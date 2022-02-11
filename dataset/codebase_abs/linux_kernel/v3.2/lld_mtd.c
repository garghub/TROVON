T_1 F_1 ( void )
{
if ( V_1 == - 1 ) {
F_2 ( V_2 L_1 ) ;
return V_3 ;
}
V_4 = F_3 ( NULL , V_1 ) ;
if ( ! V_4 ) {
F_2 ( V_2 L_2 , V_1 ) ;
return V_3 ;
}
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
return V_7 ;
}
int F_5 ( void )
{
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( ! V_4 )
return V_7 ;
F_6 ( V_4 ) ;
V_4 = NULL ;
return V_7 ;
}
T_1 F_7 ( void )
{
T_2 V_8 ;
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( ! V_4 )
return V_3 ;
V_9 . V_10 = 0 ;
V_9 . V_11 = 8 ;
V_9 . V_12 = V_13 ;
V_8 = V_4 -> V_14 ;
F_8 ( V_8 , V_4 -> V_15 ) ;
V_9 . V_16 = V_8 ;
V_9 . V_17 = V_9 . V_16 - 1 ;
V_9 . V_18 = V_4 -> V_15 / V_4 -> V_19 ;
V_9 . V_20 = V_4 -> V_19 + V_4 -> V_21 ;
V_9 . V_22 = V_4 -> V_19 ;
V_9 . V_23 = V_4 -> V_21 ;
V_9 . V_24 = V_9 . V_20 * V_9 . V_18 ;
V_9 . V_25 = V_9 . V_22 * V_9 . V_18 ;
V_9 . V_26 = ( V_27 ) ( V_9 . V_17 -
V_9 . V_12
+ 1 ) ;
V_9 . V_28 = 0 ;
V_9 . V_29 =
( V_30 ) F_9 ( V_9 . V_18 ) ;
V_9 . V_31 =
( V_30 ) F_9 ( V_9 . V_22 ) ;
V_9 . V_32 =
( V_30 ) F_9 ( V_9 . V_25 ) ;
#if V_33
V_34 = 4 ;
V_35 [ 0 ] = 1 ;
V_35 [ 1 ] = 1 ;
V_35 [ 2 ] = 1 ;
V_35 [ 3 ] = 1 ;
#endif
return V_7 ;
}
T_1 F_10 ( void )
{
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
return V_7 ;
}
void F_11 ( struct V_36 * V_37 )
{
F_12 ( ( void * ) V_37 -> V_38 ) ;
}
T_1 F_13 ( V_27 V_39 )
{
struct V_36 V_40 ;
F_14 ( V_41 ) ;
int V_42 ;
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( V_39 >= V_9 . V_16 ) {
F_2 ( V_2 L_4
L_5 , V_39 ) ;
return V_3 ;
}
F_4 ( V_43 , L_6 ,
( int ) V_39 ) ;
V_40 . V_44 = V_4 ;
V_40 . V_45 = F_11 ;
V_40 . V_46 = V_39 * V_4 -> V_15 ;
V_40 . V_47 = V_4 -> V_15 ;
V_40 . V_38 = ( unsigned long ) & V_41 ;
V_42 = V_4 -> V_40 ( V_4 , & V_40 ) ;
if ( ! V_42 ) {
F_15 ( & V_41 ) ;
if ( V_40 . V_48 != V_49 )
V_42 = - V_50 ;
}
if ( V_42 ) {
F_2 ( V_51 L_4
L_7 ,
V_40 . V_46 , V_40 . V_47 ) ;
return V_3 ;
}
return V_7 ;
}
T_1 F_16 ( V_30 * V_52 , V_27 V_53 ,
T_1 V_54 , T_1 V_55 )
{
T_3 V_56 ;
int V_42 = 0 ;
if ( V_53 >= V_9 . V_16 )
return V_3 ;
if ( V_54 + V_55 > V_9 . V_18 )
return V_3 ;
F_4 ( V_43 , L_8
L_9 ,
( unsigned int ) V_53 ,
( unsigned int ) V_54 , ( unsigned int ) V_55 ) ;
while ( V_55 ) {
V_42 = V_4 -> V_57 ( V_4 ,
( V_53 * V_4 -> V_15 ) + ( V_54 * V_4 -> V_19 ) ,
V_9 . V_22 , & V_56 , V_52 ) ;
if ( V_42 ) {
F_2 ( V_2 L_10 , V_6 , V_42 ) ;
return V_3 ;
}
V_52 += V_9 . V_22 ;
V_54 ++ ;
V_55 -- ;
}
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
return V_7 ;
}
T_1 F_17 ( V_30 * V_58 , V_27 V_53 ,
T_1 V_54 , T_1 V_55 )
{
T_3 V_56 ;
int V_42 = 0 ;
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( V_53 >= V_9 . V_16 )
return V_3 ;
if ( V_54 + V_55 > V_9 . V_18 )
return V_3 ;
F_4 ( V_43 , L_11
L_9 ,
( unsigned int ) V_53 ,
( unsigned int ) V_54 , ( unsigned int ) V_55 ) ;
while ( V_55 ) {
V_42 = V_4 -> V_59 ( V_4 ,
( V_53 * V_4 -> V_15 ) + ( V_54 * V_4 -> V_19 ) ,
V_9 . V_22 , & V_56 , V_58 ) ;
if ( V_42 ) {
F_2 ( V_2 L_10 , V_6 , V_42 ) ;
return V_3 ;
}
V_58 += V_9 . V_22 ;
V_54 ++ ;
V_55 -- ;
}
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
return V_7 ;
}
T_1 F_18 ( V_30 * V_58 , V_27 V_53 ,
T_1 V_54 , T_1 V_55 )
{
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( V_53 >= V_9 . V_16 ) {
F_2 ( V_2 L_12
L_13 ) ;
return V_3 ;
}
if ( V_54 + V_55 > V_9 . V_18 ) {
F_2 ( V_2 L_12
L_14 ,
V_54 , V_55 , V_53 ) ;
return V_3 ;
}
F_4 ( V_43 , L_15
L_16 ,
( unsigned int ) V_55 ,
( unsigned int ) V_53 , ( unsigned int ) V_54 ) ;
while ( V_55 ) {
struct V_60 V_61 ;
int V_42 ;
V_61 . V_62 = V_63 ;
V_61 . V_64 = V_58 ;
V_61 . V_47 = V_9 . V_22 ;
V_61 . V_65 = V_58 + V_9 . V_22 + V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_42 = V_4 -> V_70 ( V_4 ,
( V_53 * V_4 -> V_15 ) + ( V_54 * V_4 -> V_19 ) ,
& V_61 ) ;
if ( V_42 ) {
F_2 ( V_2 L_10 , V_6 , V_42 ) ;
return V_3 ;
}
V_58 += V_9 . V_20 ;
V_54 ++ ;
V_55 -- ;
}
return V_7 ;
}
T_1 F_19 ( V_30 * V_52 , V_27 V_53 ,
T_1 V_54 , T_1 V_71 )
{
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( V_53 >= V_9 . V_16 ) {
F_2 ( V_2 L_17
L_13 ) ;
return V_3 ;
}
if ( V_54 + V_71 > V_9 . V_18 ) {
F_2 ( V_2 L_17
L_14 ,
V_54 , V_71 , V_53 ) ;
F_20 ( 1 ) ;
return V_3 ;
}
F_4 ( V_43 , L_18
L_16 ,
( unsigned int ) V_71 ,
( unsigned int ) V_53 , ( unsigned int ) V_54 ) ;
while ( V_71 ) {
struct V_60 V_61 ;
int V_42 ;
V_61 . V_62 = V_63 ;
V_61 . V_64 = V_52 ;
V_61 . V_47 = V_9 . V_22 ;
V_61 . V_65 = V_52 + V_9 . V_22 + V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_42 = V_4 -> V_72 ( V_4 ,
( V_53 * V_4 -> V_15 ) + ( V_54 * V_4 -> V_19 ) ,
& V_61 ) ;
if ( V_42 ) {
F_2 ( V_2 L_10 , V_6 , V_42 ) ;
return V_3 ;
}
V_52 += V_9 . V_20 ;
V_54 ++ ;
V_71 -- ;
}
return V_7 ;
}
T_1 F_21 ( V_30 * V_52 , V_27 V_53 ,
T_1 V_54 , T_1 V_55 )
{
F_20 ( 1 ) ;
return V_3 ;
}
T_1 F_22 ( V_30 * V_58 , V_27 V_53 ,
T_1 V_54 , T_1 V_55 )
{
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
if ( V_53 >= V_9 . V_16 ) {
F_2 ( V_2 L_19
L_13 ) ;
return V_3 ;
}
if ( V_54 + V_55 > V_9 . V_18 ) {
F_2 ( V_2 L_19
L_20 ) ;
return V_3 ;
}
F_4 ( V_43 , L_21
L_22 ,
( unsigned int ) V_53 , ( unsigned int ) V_54 , V_55 ) ;
while ( V_55 ) {
struct V_60 V_61 ;
int V_42 ;
V_61 . V_62 = V_63 ;
V_61 . V_64 = NULL ;
V_61 . V_47 = 0 ;
V_61 . V_65 = V_58 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_42 = V_4 -> V_70 ( V_4 ,
( V_53 * V_4 -> V_15 ) + ( V_54 * V_4 -> V_19 ) ,
& V_61 ) ;
if ( V_42 ) {
F_2 ( V_2 L_10 , V_6 , V_42 ) ;
return V_3 ;
}
V_58 += V_9 . V_20 ;
V_54 ++ ;
V_55 -- ;
}
return V_7 ;
}
void F_23 ( T_1 V_73 )
{
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
}
T_1 F_24 ( V_27 V_74 )
{
return 0 ;
}
T_1 F_25 ( void )
{
T_1 V_75 ;
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
for ( V_75 = 0 ; V_75 < V_76 + V_77 ; V_75 ++ ) {
V_78 [ V_75 ] . V_79 = 0 ;
V_78 [ V_75 ] . V_80 = 0 ;
V_78 [ V_75 ] . V_81 = 0 ;
V_78 [ V_75 ] . V_53 = 0 ;
V_78 [ V_75 ] . V_54 = 0 ;
V_78 [ V_75 ] . V_55 = 0 ;
V_78 [ V_75 ] . V_82 = 0 ;
V_78 [ V_75 ] . V_83 = 0 ;
V_78 [ V_75 ] . V_84 = 0 ;
V_78 [ V_75 ] . V_85 [ 0 ] = 0 ;
V_78 [ V_75 ] . V_85 [ 1 ] = 0 ;
V_78 [ V_75 ] . V_85 [ 2 ] = 0 ;
V_78 [ V_75 ] . V_85 [ 3 ] = 0 ;
V_78 [ V_75 ] . V_85 [ 4 ] = 0 ;
V_78 [ V_75 ] . V_86 = 3 ;
}
return V_7 ;
}
static void F_26 ( int V_87 , void * V_88 )
{
}
T_1 F_27 ( T_1 V_89 )
{
T_1 V_75 , V_90 ;
V_30 V_79 ;
V_30 * V_91 ;
V_27 V_74 ;
T_1 V_92 ;
T_1 V_93 ;
T_1 V_94 = V_7 ;
F_4 ( V_5 , L_3 ,
__FILE__ , __LINE__ , V_6 ) ;
F_4 ( V_5 , L_23
L_24 , V_89 ) ;
for ( V_75 = 0 ; V_75 < V_34 ; V_75 ++ ) {
V_78 [ V_75 ] . V_79 = V_95 ;
V_78 [ V_75 ] . V_80 = 0xFF ;
V_78 [ V_75 ] . V_53 =
( V_9 . V_16 / V_34 ) * V_75 ;
for ( V_90 = 0 ; V_90 <= V_77 ; V_90 ++ )
V_78 [ V_75 ] . V_85 [ V_90 ] = 0 ;
}
F_28 ( V_89 ) ;
#ifdef F_29
F_30 ( V_89 ) ;
#endif
#if V_96
}
