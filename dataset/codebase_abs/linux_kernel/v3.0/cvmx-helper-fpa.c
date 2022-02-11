static int F_1 ( int V_1 , T_1 V_2 ,
T_1 V_3 , const char * V_4 )
{
T_1 V_5 ;
void * V_6 ;
T_1 V_7 = V_8 ;
while ( V_7 < V_2 )
V_7 = V_7 << 1 ;
if ( V_3 == 0 )
return 0 ;
V_5 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_5 ) {
F_4 ( L_1
L_2 ,
V_1 , V_4 , ( unsigned long long ) V_5 ) ;
return 0 ;
}
V_6 = F_5 ( V_2 * V_3 , V_7 ) ;
if ( V_6 == NULL ) {
F_4 ( L_3 ,
V_1 , V_4 ) ;
return - 1 ;
}
F_6 ( V_1 , V_4 , V_6 , V_2 , V_3 ) ;
return 0 ;
}
static int F_7 ( int V_9 , int V_10 ,
int V_11 , int V_12 ,
int V_13 , int V_14 ,
int V_15 , int V_16 ,
int V_17 , int V_18 ,
int V_19 , int V_20 ,
int V_21 , int V_22 ,
int V_23 )
{
int V_24 ;
F_8 () ;
if ( ( V_11 > 0 ) && ( V_11 <= 64 ) )
F_4
( L_4
L_5 , V_11 ) ;
if ( V_9 >= 0 ) {
V_24 =
F_1 ( V_9 , V_10 ,
V_11 ,
L_6 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_12 >= 0 ) {
V_24 =
F_1 ( V_12 , V_13 ,
V_14 ,
L_7 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_15 >= 0 ) {
V_24 =
F_1 ( V_15 , V_16 ,
V_17 ,
L_8 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_18 >= 0 ) {
V_24 =
F_1 ( V_18 , V_19 ,
V_20 ,
L_9 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_21 >= 0 ) {
V_24 =
F_1 ( V_21 , V_22 ,
V_23 ,
L_10 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_9 ( int V_25 , int V_26 ,
int V_17 , int V_20 ,
int V_23 )
{
#ifndef F_10
#define F_10 -1
#define F_11 0
#endif
#ifndef F_12
#define F_12 -1
#define F_13 0
#endif
#ifndef F_14
#define F_14 -1
#define F_15 0
#endif
#ifndef F_16
#define F_16 -1
#define F_17 0
#endif
#ifndef F_18
#define F_18 -1
#define F_19 0
#endif
return F_7 ( F_10 ,
F_11 ,
V_25 , F_12 ,
F_13 ,
V_26 ,
F_14 ,
F_15 ,
V_17 , F_16 ,
F_17 ,
V_20 , F_18 ,
F_19 ,
V_23 ) ;
}
