void F_1 ( const char * V_1 )
{
T_1 V_2 ;
T_2 V_3 ;
short int V_4 , V_5 ;
T_3 V_6 = V_7 ;
V_2 = F_2 ( & V_4 , & V_5 ) ;
if ( ! V_2 ) {
return;
}
if ( F_3 ( V_2 , V_8 ) == V_9 ) {
F_4 ( NULL , L_1 ,
L_2 , V_10 | V_11 ) ;
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
T_4 V_12 ;
T_5 V_13 ;
memset ( & V_12 , 0 , sizeof( T_4 ) ) ;
V_12 . V_14 = sizeof( T_4 ) ;
V_12 . V_15 =
V_16 |
V_17 |
V_18 |
V_19 ;
if ( F_12 ( & V_12 ) ) {
V_13 = ( T_5 ) F_13 ( V_12 . V_20 ) ;
if ( V_13 -> V_21 == V_22 ) {
* V_4 = V_13 -> V_23 ;
* V_5 = V_13 -> V_24 ;
}
else {
* V_4 = V_13 -> V_24 ;
* V_5 = V_13 -> V_23 ;
}
F_14 ( V_12 . V_20 ) ;
if ( V_12 . V_20 )
F_15 ( V_12 . V_20 ) ;
if ( V_12 . V_25 )
F_15 ( V_12 . V_25 ) ;
}
return V_12 . V_2 ;
}
static BOOL T_6 V_8 ( T_1 V_2 , int Error )
{
T_7 V_26 ;
while ( F_16 ( & V_26 , NULL , 0 , 0 , V_27 ) ) {
F_17 ( & V_26 ) ;
F_18 ( & V_26 ) ;
}
return TRUE ;
}
static void F_5 ( T_2 * V_3 , char * V_28 )
{
memset ( V_3 , 0 , sizeof( T_2 ) ) ;
V_3 -> V_29 = sizeof( T_2 ) ;
V_3 -> V_30 = V_28 ;
}
static void F_8 ( const char * V_1 , T_1 V_31 , int V_4 , int V_5 )
{
#define F_19 1024
#define F_20 5
#define F_21 5
T_8 * V_32 ;
T_9 V_33 ;
int V_34 = 0 , V_35 = F_21 , V_36 = 0 ;
char V_37 [ F_19 ] ;
char V_38 ;
T_10 V_39 ;
int V_40 , V_41 ;
F_22 ( V_31 , V_42 ) ;
F_23 ( V_31 , & V_39 ) ;
V_40 = F_24 ( V_4 / ( V_39 . V_43 + 1 ) , F_19 ) ;
V_41 = V_5 / ( V_39 . V_44 + 1 ) ;
F_22 ( V_31 , V_45 ) ;
F_23 ( V_31 , & V_39 ) ;
V_32 = F_25 ( V_1 , L_4 ) ;
if ( ! V_32 ) {
F_4 ( NULL , L_5 ,
L_2 , V_10 | V_11 ) ;
return;
}
while ( ( V_33 = fread ( & V_38 , 1 , 1 , V_32 ) ) != 0 ) {
if ( V_38 == 0x0c ) {
V_37 [ V_34 ] = 0 ;
F_26 ( V_31 , F_20 , V_35 , V_37 , ( int ) strlen ( V_37 ) ) ;
V_35 += V_39 . V_44 ;
V_34 = 0 ;
F_9 ( V_31 ) ;
F_7 ( V_31 ) ;
V_35 = F_21 ;
V_36 = 0 ;
continue;
}
if ( V_38 == 0x0a ) {
V_37 [ V_34 ] = 0 ;
F_26 ( V_31 , F_20 , V_35 , V_37 , ( int ) strlen ( V_37 ) ) ;
V_35 += V_39 . V_44 ;
V_34 = 0 ;
if ( ++ V_36 == V_41 ) {
F_9 ( V_31 ) ;
F_7 ( V_31 ) ;
V_35 = F_21 ;
V_36 = 0 ;
}
continue;
}
if ( V_34 == ( V_40 - 1 ) ) {
V_37 [ V_34 ] = 0 ;
F_26 ( V_31 , F_20 , V_35 , V_37 , ( int ) strlen ( V_37 ) ) ;
V_35 += V_39 . V_44 ;
V_34 = 0 ;
if ( ++ V_36 == V_41 ) {
F_9 ( V_31 ) ;
F_7 ( V_31 ) ;
V_35 = F_21 ;
V_36 = 0 ;
}
}
V_37 [ V_34 ++ ] = V_38 ;
}
if ( V_34 > 0 ) {
V_37 [ V_34 ] = 0 ;
F_26 ( V_31 , 0 , V_35 , V_37 , ( int ) strlen ( V_37 ) ) ;
}
fclose ( V_32 ) ;
}
