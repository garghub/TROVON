unsigned long long
F_1 ( unsigned long long T_1 * V_1 ,
unsigned long long V_2 )
{
unsigned long long V_3 ;
unsigned long long V_4 ;
V_4 = F_2 ( V_1 ) ;
do {
V_3 = V_4 ;
V_4 = F_3 ( ( V_5 unsigned long long * ) V_1 ,
V_3 , V_3 | V_2 , sizeof( * ( V_1 ) ) ) ;
} while ( V_3 != V_4 );
return V_4 ;
}
unsigned long long
F_4 ( unsigned long long T_1 * V_1 ,
unsigned long long V_2 )
{
unsigned long long V_3 ;
unsigned long long V_4 ;
V_4 = F_2 ( V_1 ) ;
do {
V_3 = V_4 ;
V_4 = F_3 ( ( V_5 unsigned long long * ) V_1 ,
V_3 , V_3 & V_2 , sizeof( * ( V_1 ) ) ) ;
} while ( V_3 != V_4 );
return V_4 ;
}
static T_2
F_5 ( struct V_6 * V_7 ,
unsigned int V_8 ,
void * V_9 ,
T_3 * V_10 ,
unsigned char V_11 ,
T_4 V_12 , T_2 * V_13 )
{
unsigned long V_14 ;
unsigned char V_15 ;
unsigned int V_16 = 0 ;
unsigned int V_17 = 0 ;
T_2 V_18 = 0 ;
F_6 ( V_10 , V_14 ) ;
V_16 = 1 ;
if ( ! F_7 ( V_7 -> V_19 , V_13 , NULL ) )
goto V_20;
V_17 = 1 ;
V_15 = F_8 ( V_7 -> V_19 , V_8 ) ;
if ( ! F_9 ( V_7 -> V_19 , V_8 , V_9 ) )
goto V_20;
F_10 ( V_7 -> V_19 , V_13 , NULL ) ;
V_17 = 0 ;
F_11 ( V_10 , V_14 ) ;
V_16 = 0 ;
V_7 -> V_21 ++ ;
V_18 = 1 ;
V_20:
if ( V_17 ) {
F_10 ( V_7 -> V_19 , V_13 ,
NULL ) ;
V_17 = 0 ;
}
if ( V_16 ) {
F_11 ( ( T_3 * ) V_10 , V_14 ) ;
V_16 = 0 ;
}
return V_18 ;
}
int
F_12 ( struct V_6 * V_7 ,
struct V_22 * V_23 ,
unsigned int V_8 ,
void * V_24 ,
unsigned char V_11 ,
T_4 V_12 ,
char V_25 , T_2 * V_13 )
{
while ( ! F_5 ( V_7 , V_8 , V_23 ,
( T_3 * ) V_24 ,
V_11 ,
V_12 , V_13 ) ) {
if ( V_25 != V_26 ) {
F_13 ( L_1 ) ;
return 0 ;
}
F_13 ( L_2 ) ;
F_14 ( V_27 ) ;
F_15 ( F_16 ( 10 ) ) ;
}
return 1 ;
}
int
F_17 ( struct V_6 * V_7 ,
void * V_23 , unsigned int V_8 )
{
if ( ! F_18 ( V_7 -> V_19 , V_8 , V_23 ) )
return 0 ;
V_7 -> V_28 ++ ;
return 1 ;
}
