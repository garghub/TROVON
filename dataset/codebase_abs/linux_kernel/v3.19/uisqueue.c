unsigned long long
F_1 ( unsigned long long T_1 * V_1 ,
unsigned long long V_2 )
{
unsigned long long V_3 ;
unsigned long long V_4 ;
V_4 = F_2 ( V_1 ) ;
do {
V_3 = V_4 ;
V_4 = F_3 ( ( V_5 unsigned long long * ) V_1 , V_3 , V_3 | V_2 ) ;
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
V_4 = F_3 ( ( V_5 unsigned long long * ) V_1 , V_3 , V_3 & V_2 ) ;
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
T_2 V_15 = 0 ;
F_6 ( V_10 , V_14 ) ;
if ( ! F_7 ( V_7 -> V_16 , V_13 ) )
goto V_17;
if ( F_8 ( V_7 -> V_16 , V_8 , V_9 ) ) {
V_7 -> V_18 ++ ;
V_15 = 1 ;
}
F_9 ( V_7 -> V_16 , V_13 ) ;
V_17:
F_10 ( ( T_3 * ) V_10 , V_14 ) ;
return V_15 ;
}
int
F_11 ( struct V_6 * V_7 ,
struct V_19 * V_20 ,
unsigned int V_8 ,
void * V_21 ,
unsigned char V_22 ,
T_4 V_23 ,
char V_24 , T_2 * V_25 )
{
while ( ! F_5 ( V_7 , V_8 , V_20 ,
( T_3 * ) V_21 ,
V_22 ,
V_23 , V_25 ) ) {
if ( V_24 != V_26 ) {
F_12 ( L_1 ) ;
return 0 ;
}
F_12 ( L_2 ) ;
F_13 ( V_27 ) ;
F_14 ( F_15 ( 10 ) ) ;
}
return 1 ;
}
int
F_16 ( struct V_6 * V_7 ,
void * V_20 , unsigned int V_8 )
{
if ( ! F_17 ( V_7 -> V_16 , V_8 , V_20 ) )
return 0 ;
V_7 -> V_28 ++ ;
return 1 ;
}
