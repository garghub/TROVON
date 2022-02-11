void F_1 ( const char * V_1 )
{
T_1 V_2 ;
T_2 V_3 ;
short int V_4 , V_5 ;
V_2 = F_2 ( & V_4 , & V_5 ) ;
if ( ! V_2 ) {
return;
}
if ( F_3 ( V_2 , V_6 ) == V_7 ) {
F_4 ( NULL , L_1 ,
L_2 , V_8 | V_9 ) ;
return;
}
F_5 ( & V_3 , L_3 ) ;
F_6 ( V_2 , & V_3 ) ;
F_7 ( V_2 ) ;
F_8 ( V_1 , V_2 , V_4 , V_5 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static T_1 F_2 ( short * V_4 , short * V_5 )
{
T_3 V_10 ;
T_4 V_11 ;
memset ( & V_10 , 0 , sizeof( T_3 ) ) ;
V_10 . V_12 = sizeof( T_3 ) ;
V_10 . V_13 =
V_14 |
V_15 |
V_16 |
V_17 ;
if ( F_12 ( & V_10 ) ) {
V_11 = ( T_4 ) F_13 ( V_10 . V_18 ) ;
if ( V_11 == NULL ) {
if ( V_10 . V_18 )
F_14 ( V_10 . V_18 ) ;
if ( V_10 . V_19 )
F_14 ( V_10 . V_19 ) ;
return NULL ;
}
if ( V_11 -> V_20 == V_21 ) {
* V_4 = V_11 -> V_22 ;
* V_5 = V_11 -> V_23 ;
}
else {
* V_4 = V_11 -> V_23 ;
* V_5 = V_11 -> V_22 ;
}
F_15 ( V_10 . V_18 ) ;
if ( V_10 . V_18 )
F_14 ( V_10 . V_18 ) ;
if ( V_10 . V_19 )
F_14 ( V_10 . V_19 ) ;
}
return V_10 . V_2 ;
}
static BOOL T_5 V_6 ( T_1 V_2 , int Error )
{
T_6 V_24 ;
while ( F_16 ( & V_24 , NULL , 0 , 0 , V_25 ) ) {
F_17 ( & V_24 ) ;
F_18 ( & V_24 ) ;
}
return TRUE ;
}
static void F_5 ( T_2 * V_3 , char * V_26 )
{
memset ( V_3 , 0 , sizeof( T_2 ) ) ;
V_3 -> V_27 = sizeof( T_2 ) ;
V_3 -> V_28 = V_26 ;
}
static void F_8 ( const char * V_1 , T_1 V_29 , int V_4 , int V_5 )
{
#define F_19 1024
#define F_20 5
#define F_21 5
T_7 * V_30 ;
int V_31 = 0 , V_32 = F_21 , V_33 = 0 ;
char V_34 [ F_19 ] ;
char V_35 ;
T_8 V_36 ;
int V_37 , V_38 ;
F_22 ( V_29 , V_39 ) ;
F_23 ( V_29 , & V_36 ) ;
V_37 = F_24 ( V_4 / ( V_36 . V_40 + 1 ) , F_19 ) ;
V_38 = V_5 / ( V_36 . V_41 + 1 ) ;
F_22 ( V_29 , V_42 ) ;
F_23 ( V_29 , & V_36 ) ;
V_30 = F_25 ( V_1 , L_4 ) ;
if ( ! V_30 ) {
F_4 ( NULL , L_5 ,
L_2 , V_8 | V_9 ) ;
return;
}
while ( fread ( & V_35 , 1 , 1 , V_30 ) != 0 ) {
if ( V_35 == 0x0c ) {
V_34 [ V_31 ] = 0 ;
F_26 ( V_29 , F_20 , V_32 , V_34 , ( int ) strlen ( V_34 ) ) ;
V_31 = 0 ;
F_9 ( V_29 ) ;
F_7 ( V_29 ) ;
V_32 = F_21 ;
V_33 = 0 ;
continue;
}
if ( V_35 == 0x0a ) {
V_34 [ V_31 ] = 0 ;
F_26 ( V_29 , F_20 , V_32 , V_34 , ( int ) strlen ( V_34 ) ) ;
V_32 += V_36 . V_41 ;
V_31 = 0 ;
if ( ++ V_33 == V_38 ) {
F_9 ( V_29 ) ;
F_7 ( V_29 ) ;
V_32 = F_21 ;
V_33 = 0 ;
}
continue;
}
if ( V_31 == ( V_37 - 1 ) ) {
V_34 [ V_31 ] = 0 ;
F_26 ( V_29 , F_20 , V_32 , V_34 , ( int ) strlen ( V_34 ) ) ;
V_32 += V_36 . V_41 ;
V_31 = 0 ;
if ( ++ V_33 == V_38 ) {
F_9 ( V_29 ) ;
F_7 ( V_29 ) ;
V_32 = F_21 ;
V_33 = 0 ;
}
}
V_34 [ V_31 ++ ] = V_35 ;
}
if ( V_31 > 0 ) {
V_34 [ V_31 ] = 0 ;
F_26 ( V_29 , 0 , V_32 , V_34 , ( int ) strlen ( V_34 ) ) ;
}
fclose ( V_30 ) ;
}
