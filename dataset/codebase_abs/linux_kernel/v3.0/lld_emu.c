int F_1 ( void )
{
T_1 V_1 ;
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 = NULL ;
T_2 V_5 = 0 ;
T_2 V_6 , V_7 ;
T_3 V_8 ;
int V_9 , V_10 = - V_11 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
V_1 = F_3 () ;
F_4 ( F_5 () ) ;
V_3 = F_6 ( L_2 , V_14 | V_15 , 0 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( V_16 L_3
L_4 ) ;
return F_9 ( V_3 ) ;
}
if ( V_3 -> V_17 . V_18 ) {
V_4 = V_3 -> V_17 . V_18 -> V_19 ;
} else {
F_8 ( V_16 L_5 ) ;
goto V_20;
}
V_5 = F_10 ( V_4 -> V_21 -> V_22 ) ;
if ( V_5 <= 0 ) {
F_8 ( V_16 L_6
L_7 , V_5 ) ;
goto V_20;
} else {
F_2 ( V_23 , L_8 ,
V_5 ) ;
}
V_7 = 0 ;
for ( V_9 = 0 ; V_9 < V_24 * V_25 ; V_9 ++ ) {
V_6 = V_7 ;
V_8 = F_11 ( V_3 ,
( char V_26 * ) V_27 [ V_9 ] ,
V_28 , & V_6 ) ;
if ( V_8 < V_28 ) {
F_8 ( V_16 L_9
L_10
L_11 , __FILE__ , __LINE__ , ( int ) V_8 ) ;
goto V_20;
}
V_7 += V_28 ;
}
V_10 = 0 ;
V_20:
F_12 ( V_3 , V_29 -> V_30 ) ;
F_4 ( V_1 ) ;
return V_10 ;
}
int F_13 ( void )
{
T_1 V_1 ;
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 = NULL ;
T_2 V_5 = 0 ;
T_2 V_6 , V_7 ;
T_3 V_31 ;
int V_9 , V_10 = - V_11 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
V_1 = F_3 () ;
F_4 ( F_5 () ) ;
V_3 = F_6 ( L_2 , V_14 | V_15 , 0 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( V_16 L_3
L_4 ) ;
return F_9 ( V_3 ) ;
}
if ( V_3 -> V_17 . V_18 ) {
V_4 = V_3 -> V_17 . V_18 -> V_19 ;
} else {
F_8 ( V_16 L_12 L_13 ) ;
goto V_20;
}
V_5 = F_10 ( V_4 -> V_21 -> V_22 ) ;
if ( V_5 <= 0 ) {
F_8 ( V_16 L_12
L_14 , V_5 ) ;
goto V_20;
} else {
F_2 ( V_23 , L_15
L_16 , V_5 ) ;
}
V_7 = 0 ;
for ( V_9 = 0 ; V_9 < V_24 * V_25 ; V_9 ++ ) {
V_6 = V_7 ;
V_31 = F_14 ( V_3 ,
( char V_26 * ) V_27 [ V_9 ] ,
V_28 , & V_6 ) ;
if ( V_31 < V_28 ) {
F_8 ( V_16 L_9
L_17
L_11 , __FILE__ , __LINE__ , ( int ) V_31 ) ;
goto V_20;
}
V_7 += V_28 ;
}
V_10 = 0 ;
V_20:
F_12 ( V_3 , V_29 -> V_30 ) ;
F_4 ( V_1 ) ;
return V_10 ;
}
T_4 F_15 ( void )
{
int V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
V_27 [ 0 ] = F_16 ( V_28 * V_24 *
V_25 * sizeof( V_32 ) ) ;
if ( ! V_27 [ 0 ] ) {
F_8 ( V_16 L_18
L_19 ) ;
return V_33 ;
}
memset ( ( char * ) ( V_27 [ 0 ] ) , 0xFF ,
V_28 * V_24 * V_25 *
sizeof( V_32 ) ) ;
for ( V_9 = 1 ; V_9 < V_24 * V_25 ; V_9 ++ )
V_27 [ V_9 ] = V_27 [ V_9 - 1 ] + V_28 ;
F_1 () ;
return V_34 ;
}
int F_17 ( void )
{
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
F_13 () ;
F_18 ( V_27 [ 0 ] ) ;
return V_34 ;
}
T_4 F_19 ( void )
{
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
V_35 . V_36 = 0 ;
V_35 . V_37 = 8 ;
V_35 . V_38 = 36 ;
V_35 . V_39 = V_24 - 1 ;
V_35 . V_40 = V_24 ;
V_35 . V_41 = V_25 ;
V_35 . V_42 = V_28 ;
V_35 . V_43 = V_44 ;
V_35 . V_45 = V_28 -
V_44 ;
V_35 . V_46 = V_35 . V_42 * V_25 ;
V_35 . V_47 = V_35 . V_43 * V_25 ;
V_35 . V_48 = ( V_49 ) ( V_35 . V_39 -
V_35 . V_38
+ 1 ) ;
V_35 . V_50 = 1 ;
V_35 . V_51 =
( V_32 ) F_20 ( V_35 . V_41 ) ;
V_35 . V_52 =
( V_32 ) F_20 ( V_35 . V_43 ) ;
V_35 . V_53 =
( V_32 ) F_20 ( V_35 . V_47 ) ;
#if V_54
V_55 = 4 ;
V_56 [ 0 ] = 1 ;
V_56 [ 1 ] = 1 ;
V_56 [ 2 ] = 1 ;
V_56 [ 3 ] = 1 ;
#endif
return V_34 ;
}
T_4 F_21 ( void )
{
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
return V_34 ;
}
T_4 F_22 ( V_49 V_57 )
{
int V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_57 >= V_35 . V_40 ) {
F_8 ( V_16 L_20
L_21 , V_57 ) ;
return V_58 ;
}
F_2 ( V_23 , L_22 ,
( int ) V_57 ) ;
for ( V_9 = V_57 * V_25 ;
V_9 < ( ( V_57 + 1 ) * V_25 ) ; V_9 ++ ) {
if ( V_27 [ V_9 ] ) {
memset ( ( V_32 * ) ( V_27 [ V_9 ] ) , 0xFF ,
V_35 . V_42 * sizeof( V_32 ) ) ;
}
}
return V_34 ;
}
T_4 F_23 ( V_32 * V_59 , V_49 V_60 ,
T_4 V_61 , T_4 V_62 )
{
int V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_60 >= V_35 . V_40 )
return V_58 ;
if ( V_61 + V_62 > V_35 . V_41 )
return V_58 ;
F_2 ( V_23 , L_23
L_24 ,
( unsigned int ) V_60 ,
( unsigned int ) V_61 , ( unsigned int ) V_62 ) ;
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
if ( NULL == V_27 [ V_60 * V_25 + V_61 ] ) {
F_8 ( V_16 L_25 ) ;
return V_58 ;
}
memcpy ( ( V_32 * ) ( V_27 [ V_60 * V_25 + V_61 ] ) ,
V_59 , V_35 . V_43 ) ;
V_59 += V_35 . V_43 ;
V_61 ++ ;
}
return V_34 ;
}
T_4 F_24 ( V_32 * V_63 , V_49 V_60 ,
T_4 V_61 , T_4 V_62 )
{
int V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_60 >= V_35 . V_40 )
return V_58 ;
if ( V_61 + V_62 > V_35 . V_41 )
return V_58 ;
F_2 ( V_23 , L_26
L_24 ,
( unsigned int ) V_60 ,
( unsigned int ) V_61 , ( unsigned int ) V_62 ) ;
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
if ( NULL == V_27 [ V_60 * V_25 + V_61 ] ) {
memset ( V_63 , 0xFF , V_35 . V_43 ) ;
} else {
memcpy ( V_63 ,
( V_32 * ) ( V_27 [ V_60 * V_25
+ V_61 ] ) ,
V_35 . V_43 ) ;
}
V_63 += V_35 . V_43 ;
V_61 ++ ;
}
return V_34 ;
}
T_4 F_25 ( V_32 * V_63 , V_49 V_60 ,
T_4 V_61 , T_4 V_62 )
{
int V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_60 >= V_35 . V_40 ) {
F_8 ( V_16 L_27
L_28 ) ;
return V_58 ;
}
if ( V_61 + V_62 > V_35 . V_41 ) {
F_8 ( V_16 L_27
L_29 ) ;
return V_58 ;
}
F_2 ( V_23 , L_30
L_31 ,
( unsigned int ) V_62 ,
( unsigned int ) V_60 , ( unsigned int ) V_61 ) ;
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
if ( NULL == V_27 [ V_60 * V_25 + V_61 ] ) {
memset ( V_63 , 0xFF , V_35 . V_42 ) ;
} else {
memcpy ( V_63 , ( V_32 * ) ( V_27 [ V_60 *
V_25
+ V_61 ] ) ,
V_35 . V_42 ) ;
}
V_63 += V_35 . V_42 ;
V_61 ++ ;
}
return V_34 ;
}
T_4 F_26 ( V_32 * V_59 , V_49 V_60 ,
T_4 V_61 , T_4 V_64 )
{
T_4 V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_60 >= V_35 . V_40 ) {
F_8 ( V_16 L_32
L_28 ) ;
return V_58 ;
}
if ( V_61 + V_64 > V_35 . V_41 ) {
F_8 ( V_16 L_32
L_29 ) ;
return V_58 ;
}
F_2 ( V_23 , L_33
L_31 ,
( unsigned int ) V_64 ,
( unsigned int ) V_60 , ( unsigned int ) V_61 ) ;
for ( V_9 = 0 ; V_9 < V_64 ; V_9 ++ ) {
if ( NULL == V_27 [ V_60 * V_25 + V_61 ] ) {
F_8 ( V_16 L_34 ) ;
return V_58 ;
}
memcpy ( ( V_32 * ) ( V_27 [ V_60 * V_25 + V_61 ] ) ,
V_59 , V_35 . V_42 ) ;
V_59 += V_35 . V_42 ;
V_61 ++ ;
}
return V_34 ;
}
T_4 F_27 ( V_32 * V_59 , V_49 V_60 ,
T_4 V_61 , T_4 V_62 )
{
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_60 >= V_35 . V_40 ) {
F_8 ( V_16 L_35
L_36 ) ;
return V_58 ;
}
if ( V_61 + V_62 > V_35 . V_41 ) {
F_8 ( V_16 L_35
L_37 ) ;
return V_58 ;
}
F_2 ( V_23 , L_38
L_39 ,
( unsigned int ) V_60 , ( unsigned int ) V_61 ) ;
if ( NULL == V_27 [ V_60 * V_25 + V_61 ] ) {
F_8 ( V_16 L_34 ) ;
return V_58 ;
}
memcpy ( ( V_32 * ) ( V_27 [ V_60 * V_25 + V_61 ] +
V_35 . V_43 ) , V_59 ,
( V_35 . V_42 - V_35 . V_43 ) ) ;
return V_34 ;
}
T_4 F_28 ( V_32 * V_59 , V_49 V_60 ,
T_4 V_61 , T_4 V_62 )
{
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
if ( V_60 >= V_35 . V_40 ) {
F_8 ( V_16 L_40
L_28 ) ;
return V_58 ;
}
if ( V_61 + V_62 > V_35 . V_41 ) {
F_8 ( V_16 L_40
L_29 ) ;
return V_58 ;
}
F_2 ( V_23 , L_41
L_39 ,
( unsigned int ) V_60 , ( unsigned int ) V_61 ) ;
if ( NULL == V_27 [ V_60 * V_25 + V_61 ] ) {
memset ( V_59 , 0xFF ,
( V_35 . V_42 - V_35 . V_43 ) ) ;
} else {
memcpy ( V_59 ,
( V_32 * ) ( V_27 [ V_60 * V_25 + V_61 ]
+ V_35 . V_43 ) ,
( V_35 . V_42 - V_35 . V_43 ) ) ;
}
return V_34 ;
}
void F_29 ( T_4 V_65 )
{
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
}
T_4 F_30 ( V_49 V_66 )
{
return 0 ;
}
T_4 F_31 ( void )
{
T_4 V_9 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
for ( V_9 = 0 ; V_9 < V_67 + V_68 ; V_9 ++ ) {
V_69 [ V_9 ] . V_70 = 0 ;
V_69 [ V_9 ] . V_71 = 0 ;
V_69 [ V_9 ] . V_72 = 0 ;
V_69 [ V_9 ] . V_60 = 0 ;
V_69 [ V_9 ] . V_61 = 0 ;
V_69 [ V_9 ] . V_62 = 0 ;
V_69 [ V_9 ] . V_73 = 0 ;
V_69 [ V_9 ] . V_74 = 0 ;
V_69 [ V_9 ] . V_75 = 0 ;
V_69 [ V_9 ] . V_76 [ 0 ] = 0 ;
V_69 [ V_9 ] . V_76 [ 1 ] = 0 ;
V_69 [ V_9 ] . V_76 [ 2 ] = 0 ;
V_69 [ V_9 ] . V_76 [ 3 ] = 0 ;
V_69 [ V_9 ] . V_76 [ 4 ] = 0 ;
V_69 [ V_9 ] . V_77 = 3 ;
}
return V_34 ;
}
static void F_32 ( int V_78 , void * V_79 )
{
}
T_4 F_33 ( T_4 V_80 )
{
T_4 V_9 , V_81 ;
V_32 V_70 ;
V_32 * V_82 ;
V_49 V_66 ;
T_4 V_83 ;
T_4 V_84 ;
T_4 V_85 = V_34 ;
F_2 ( V_12 , L_1 ,
__FILE__ , __LINE__ , V_13 ) ;
F_2 ( V_12 , L_42
L_43 , V_80 ) ;
for ( V_9 = 0 ; V_9 < V_55 ; V_9 ++ ) {
V_69 [ V_9 ] . V_70 = V_86 ;
V_69 [ V_9 ] . V_71 = 0xFF ;
V_69 [ V_9 ] . V_60 =
( V_35 . V_40 / V_55 ) * V_9 ;
for ( V_81 = 0 ; V_81 <= V_68 ; V_81 ++ )
V_69 [ V_9 ] . V_76 [ V_81 ] = 0 ;
}
F_34 ( V_80 ) ;
F_35 ( V_80 ) ;
#if V_87
}
