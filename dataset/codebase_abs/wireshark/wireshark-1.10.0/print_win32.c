void F_1 ( const char * V_1 )
{
T_1 V_2 ;
T_2 V_3 ;
T_3 V_4 = V_5 ;
V_2 = F_2 () ;
if( ! V_2 )
{
return;
}
if( F_3 ( V_2 , V_6 ) == V_7 )
{
F_4 ( NULL , L_1 ,
L_2 , V_8 | V_9 ) ;
return;
}
F_5 ( & V_3 , L_3 ) ;
F_6 ( V_2 , & V_3 ) ;
F_7 ( V_2 ) ;
F_8 ( V_1 , V_2 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static T_1 F_2 ( void )
{
T_4 V_10 ;
memset ( & V_10 , 0 , sizeof( T_4 ) ) ;
V_10 . V_11 = sizeof( T_4 ) ;
V_10 . V_12 =
V_13 |
V_14 |
V_15 |
V_16 ;
F_12 ( & V_10 ) ;
return V_10 . V_2 ;
}
static BOOL T_5 V_6 ( T_1 V_2 , int Error )
{
T_6 V_17 ;
while( F_13 ( & V_17 , NULL , 0 , 0 , V_18 ) )
{
F_14 ( & V_17 ) ;
F_15 ( & V_17 ) ;
}
return TRUE ;
}
static void F_5 ( T_2 * V_3 , char * V_19 )
{
memset ( V_3 , 0 , sizeof( T_2 ) ) ;
V_3 -> V_20 = sizeof( T_2 ) ;
V_3 -> V_21 = V_19 ;
}
static void F_8 ( const char * V_1 , T_1 V_22 ) {
#define F_16 1024
#define F_17 66
#define F_18 5
#define F_19 5
T_7 * V_23 ;
T_8 V_24 ;
int V_25 = 0 , V_26 = F_18 , V_27 = 0 ;
char V_28 [ F_16 ] ;
char V_29 ;
T_9 V_30 ;
F_20 ( V_22 , & V_30 ) ;
F_21 ( V_22 , V_31 ) ;
V_23 = F_22 ( V_1 , L_4 ) ;
if( ! V_23 ) {
F_4 ( NULL , L_5 ,
L_2 , V_8 | V_9 ) ;
return;
}
while ( ( V_24 = fread ( & V_29 , 1 , 1 , V_23 ) ) != 0 ) {
if ( V_29 == 0x0c ) {
V_28 [ V_25 ] = 0 ;
F_23 ( V_22 , F_19 , V_26 , V_28 , ( int ) strlen ( V_28 ) ) ;
V_26 += V_30 . V_32 ;
V_25 = 0 ;
F_9 ( V_22 ) ;
F_7 ( V_22 ) ;
V_26 = F_18 ;
V_27 = 0 ;
continue;
}
if ( V_29 == 0x0a ) {
V_28 [ V_25 ] = 0 ;
F_23 ( V_22 , F_19 , V_26 , V_28 , ( int ) strlen ( V_28 ) ) ;
V_26 += V_30 . V_32 ;
V_25 = 0 ;
if ( ++ V_27 == F_17 ) {
F_9 ( V_22 ) ;
F_7 ( V_22 ) ;
V_26 = F_18 ;
V_27 = 0 ;
}
continue;
}
if ( V_25 == ( F_16 - 1 ) ) {
V_28 [ V_25 ] = 0 ;
F_23 ( V_22 , F_19 , V_26 , V_28 , ( int ) strlen ( V_28 ) ) ;
V_26 += V_30 . V_32 ;
V_25 = 0 ;
if ( ++ V_27 == F_17 ) {
F_9 ( V_22 ) ;
F_7 ( V_22 ) ;
V_26 = F_18 ;
V_27 = 0 ;
}
continue;
}
V_28 [ V_25 ++ ] = V_29 ;
}
if ( V_25 > 0 ) {
V_28 [ V_25 ] = 0 ;
F_23 ( V_22 , 0 , V_26 , V_28 , ( int ) strlen ( V_28 ) ) ;
}
fclose ( V_23 ) ;
}
