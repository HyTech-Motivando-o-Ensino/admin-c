void insertCourse(char *name, char *timeCourseAmount, char *type, char *operation_test);
char *insertClass(char *courseId, char *period, char *link);
char *insertProfessor(char *slack, char *name, char *email, char *whatsapp, char *favoriteContact, char *professorId);
char *insertProfCourse(int courseId, char *professor_id);
char *insertProfSubject(int subjectId, char *professor_id);
char *insertSubject(char *name, char *period);
char *insertClassroomCode(char *subjectId, char *classId, char *classroomId);