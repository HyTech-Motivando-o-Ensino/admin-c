void insertCourse(char *name, char *timeCourseAmount, char *type, char *operation_test);
void insertClass(char *courseId, char *period, char *link, char *operation_test);
void insertProfessor(char *slack, char *name, char *email, char *whatsapp, char *favoriteContact,char *other, char *operation_test);
void insertProfCourse(int courseId, char *professor_id, char *operation_test);
void insertProfSubject(int subjectId, char *professor_id, char *operation_test);
void insertSubject(char *name, char *period, char *operation_test);
void insertClassroomCode(char *subjectId, char *classId, char *classroomId, char *operation_test);
void insertProfPeriods(char *professorId, int period, char *operation_test);