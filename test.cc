
void LRUReplacer::Unpin(frame_id_t frame_id) {
  std::lock_guard<std::mutex> guard(m_lock);
  // key already exists, just update the queue
  if(auto mapIter = m_lruMap.find(frame_id);mapIter!=m_lruMap.end()){
    m_lruList.splice(m_lruList.begin(),m_lruList,mapIter->second);
  }else{
    m_lruList.push_front(frame_id);
    m_lruMap[frame_id] = m_lruList.begin();

————————————————
版权声明：本文为CSDN博主「wwxy261」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/wwxy1995/article/details/113360396