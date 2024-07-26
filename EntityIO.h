#ifndef ENTITYIO_H
#define ENTITYIO_H

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

template<typename T>
class EntityIO {
public:
    EntityIO(const std::string& filename);

    void init();

    void exit();
    
    void seekToStart();

    void seekTo(int offset);

    std::vector<T*> readNRecords(int n);

    T* readRecord();

    void appendRecord(const T& record);

    void updateRecord(int index, const T& newRecord);

    int getRecordCount();

private:
    std::fstream fileStream;
    std::string filename;
    int recordCount;

};

// Include the implementation of the template class in the header file
#include "EntityIO.tpp"

#endif // ENTITYIO_H
