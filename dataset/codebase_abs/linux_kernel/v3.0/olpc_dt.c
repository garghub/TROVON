static T_1 T_2 F_1 ( T_1 V_1 )
{
const void * args [] = { ( void * ) V_1 } ;
void * V_2 [] = { & V_1 } ;
if ( ( V_3 ) V_1 == - 1 )
return 0 ;
if ( F_2 ( L_1 , args , V_2 ) || ( V_3 ) V_1 == - 1 )
return 0 ;
return V_1 ;
}
static T_1 T_2 F_3 ( T_1 V_1 )
{
const void * args [] = { ( void * ) V_1 } ;
void * V_2 [] = { & V_1 } ;
if ( ( V_3 ) V_1 == - 1 )
return 0 ;
if ( F_2 ( L_2 , args , V_2 ) || ( V_3 ) V_1 == - 1 ) {
F_4 ( L_3 , V_4 ) ;
return 0 ;
}
return V_1 ;
}
static int T_2 F_5 ( T_1 V_1 , const char * V_5 )
{
const void * args [] = { ( void * ) V_1 , V_5 } ;
int V_6 ;
void * V_2 [] = { & V_6 } ;
if ( ( V_3 ) V_1 == - 1 )
return - 1 ;
if ( F_2 ( L_4 , args , V_2 ) ) {
F_4 ( L_5 , V_4 ) ;
return - 1 ;
}
return V_6 ;
}
static int T_2 F_6 ( T_1 V_1 , const char * V_5 ,
char * V_7 , int V_8 )
{
int V_9 ;
V_9 = F_5 ( V_1 , V_5 ) ;
if ( V_9 > V_8 || V_9 < 1 ) {
return - 1 ;
} else {
const void * args [] = { ( void * ) V_1 , V_5 , V_7 , ( void * ) V_9 } ;
void * V_2 [] = { & V_9 } ;
if ( F_2 ( L_6 , args , V_2 ) ) {
F_4 ( L_7 , V_4 ) ;
return - 1 ;
}
}
return V_9 ;
}
static int T_2 F_7 ( T_1 V_1 , char * V_10 , char * V_7 )
{
const void * args [] = { ( void * ) V_1 , V_10 , V_7 } ;
int V_11 ;
void * V_2 [] = { & V_11 } ;
V_7 [ 0 ] = '\0' ;
if ( ( V_3 ) V_1 == - 1 )
return - 1 ;
if ( F_2 ( L_8 , args , V_2 ) || V_11 != 1 )
return - 1 ;
return 0 ;
}
static int T_2 F_8 ( T_1 V_1 , char * V_7 ,
const int V_12 , int * V_6 )
{
const void * args [] = { ( void * ) V_1 , V_7 , ( void * ) V_12 } ;
void * V_2 [] = { V_6 } ;
if ( ( V_3 ) V_1 == - 1 )
return - 1 ;
if ( F_2 ( L_9 , args , V_2 ) || * V_6 < 1 )
return - 1 ;
return 0 ;
}
void * T_2 F_9 ( unsigned long V_13 )
{
static T_3 * V_14 ;
static T_4 V_15 ;
void * V_2 ;
if ( V_15 < V_13 ) {
const T_4 V_16 = F_10 ( V_17 , V_13 ) ;
V_2 = F_11 ( V_16 ) ;
F_12 ( ! V_2 ) ;
V_18 += V_16 ;
memset ( V_2 , 0 , V_16 ) ;
V_15 = V_16 ;
V_14 = V_2 ;
}
V_15 -= V_13 ;
V_2 = V_14 ;
V_14 += V_13 ;
return V_2 ;
}
void T_2 F_13 ( void )
{
T_1 V_19 ;
if ( ! F_14 () )
return;
V_19 = F_1 ( 0 ) ;
if ( ! V_19 ) {
F_4 ( L_10 ) ;
return;
}
F_15 ( V_19 , & V_20 ) ;
F_16 ( L_11 ,
V_18 ) ;
}
static int T_2 F_17 ( void )
{
if ( F_18 () )
return F_19 ( NULL , V_21 , NULL ) ;
else
return 0 ;
}
