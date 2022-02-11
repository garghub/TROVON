static void F_1 ( struct V_1 * V_2 )
{
( void ) F_2 ( V_2 -> V_3 -> V_4 , V_5 ) ;
}
static void F_3 ( void * V_6 , const T_1 V_7 ,
unsigned long V_8 )
{
F_4 ( V_6 , V_7 , V_8 ) ;
F_1 ( F_5 ( V_7 ) ) ;
}
static inline unsigned long F_6 ( struct V_9 * V_3 ,
unsigned long V_10 )
{
return V_10 - ( ( unsigned long ) ( V_3 -> V_11 ) - V_12 ) ;
}
static T_2 F_7 ( struct V_9 * V_3 ,
unsigned long V_10 , int V_13 )
{
unsigned int V_14 ;
unsigned int V_15 , V_16 ;
unsigned long V_17 ;
T_2 V_18 , V_19 ;
F_8 ( ( ( V_10 & 0x3ul ) + V_13 ) > 4 ) ;
V_17 = F_6 ( V_3 , V_10 ) ;
V_16 = V_17 & 0x3ul ;
V_14 = ( ( 1 << V_13 ) - 1 ) << V_16 ;
V_15 = V_20 | ( V_14 << V_21 ) ;
F_9 ( V_3 -> V_4 , V_22 , ( V_17 & ~ 0x3ul ) ) ;
F_9 ( V_3 -> V_4 , V_23 , V_15 ) ;
V_18 = F_2 ( V_3 -> V_4 , V_24 ) ;
V_19 = ( V_18 >> ( V_16 * 8 ) ) & ( 0xFFFFFFFF >> ( ( 4 - V_13 ) * 8 ) ) ;
F_10 ( L_1
L_2 , V_10 , V_17 , V_13 , V_14 ,
V_15 , V_18 , V_19 ) ;
return V_19 ;
}
static void F_11 ( struct V_9 * V_3 ,
unsigned long V_10 , int V_13 , T_2 V_25 )
{
unsigned int V_14 ;
unsigned int V_15 , V_16 ;
unsigned long V_17 ;
T_2 V_18 ;
F_8 ( ( ( V_10 & 0x3ul ) + V_13 ) > 4 ) ;
V_17 = F_6 ( V_3 , V_10 ) ;
V_16 = V_17 & 0x3ul ;
V_14 = ( ( 1 << V_13 ) - 1 ) << V_16 ;
V_15 = V_26 | ( V_14 << V_21 ) ;
V_18 = ( V_25 & ( 0xFFFFFFFF >> ( 4 - V_13 ) * 8 ) ) << ( V_16 * 8 ) ;
F_9 ( V_3 -> V_4 , V_22 , ( V_17 & ~ 0x3ul ) ) ;
F_9 ( V_3 -> V_4 , V_23 , V_15 ) ;
F_9 ( V_3 -> V_4 , V_27 , V_18 ) ;
F_10 ( L_3
L_4 , V_10 , V_17 , V_13 , V_25 ,
V_14 , V_15 , V_18 ) ;
}
static T_3 F_12 ( struct V_9 * V_3 , unsigned long V_10 )
{
return ( T_3 ) F_7 ( V_3 , V_10 , 1 ) ;
}
static T_4 F_13 ( struct V_9 * V_3 , unsigned long V_10 )
{
T_2 V_18 ;
if ( ( V_10 & 0x3ul ) < 3 )
V_18 = F_7 ( V_3 , V_10 , 2 ) ;
else {
T_2 V_28 = F_7 ( V_3 , V_10 , 1 ) ;
T_2 V_29 = F_7 ( V_3 , V_10 + 1 , 1 ) ;
V_18 = V_28 | ( V_29 << 8 ) ;
}
return ( T_4 ) V_18 ;
}
static T_2 F_14 ( struct V_9 * V_3 , unsigned long V_10 )
{
unsigned int V_30 = V_10 & 0x3ul ;
T_2 V_18 ;
if ( V_30 == 0 )
V_18 = F_7 ( V_3 , V_10 , 4 ) ;
else {
T_2 V_28 = F_7 ( V_3 , V_10 , 4 - V_30 ) ;
T_2 V_29 = F_7 ( V_3 , V_10 + 1 , V_30 ) ;
V_18 = V_28 | ( V_29 << ( V_30 * 8 ) ) ;
}
return V_18 ;
}
static void F_15 ( struct V_9 * V_3 ,
T_3 V_25 , unsigned long V_10 )
{
F_11 ( V_3 , V_10 , 1 , ( T_2 ) V_25 ) ;
}
static void F_16 ( struct V_9 * V_3 ,
T_4 V_25 , unsigned long V_10 )
{
if ( ( V_10 & 0x3ul ) < 3 )
F_11 ( V_3 , V_10 , 2 , ( T_2 ) V_25 ) ;
else {
T_2 V_28 = V_25 & 0x000000FF ;
T_2 V_29 = ( V_25 & 0x0000FF00 ) >> 8 ;
F_11 ( V_3 , V_10 , 1 , V_28 ) ;
F_11 ( V_3 , V_10 + 1 , 1 , V_29 ) ;
}
}
static void F_17 ( struct V_9 * V_3 ,
T_2 V_25 , unsigned long V_10 )
{
unsigned int V_30 = V_10 & 0x3ul ;
if ( V_30 == 0 )
F_11 ( V_3 , V_10 , 4 , V_25 ) ;
else {
T_2 V_28 = V_25 & ( 0xFFFFFFFFul >> ( V_30 * 8 ) ) ;
T_2 V_29 = V_25 >> ( ( 4 - V_30 ) * 8 ) ;
F_11 ( V_3 , V_10 , 4 - V_30 , V_28 ) ;
F_11 ( V_3 , V_10 + 1 , V_30 , V_29 ) ;
}
}
static int T_5 F_18 ( struct V_1 * V_2 , void * V_18 )
{
T_6 V_31 ;
void * V_32 ;
V_32 = F_19 ( V_33 , V_34 ) ;
if ( ! V_32 ) {
F_20 ( L_5 ) ;
return - 1 ;
}
V_31 = F_21 ( V_2 -> V_3 -> V_35 , V_32 ,
V_33 , V_36 ) ;
if ( F_22 ( V_2 -> V_3 -> V_35 , V_31 ) ) {
F_20 ( L_6 ) ;
F_23 ( V_32 ) ;
return - 1 ;
}
F_9 ( V_2 -> V_3 -> V_4 , V_37 , V_31 ) ;
return 0 ;
}
static T_7 F_24 ( unsigned int T_8 * V_38 ,
T_9 V_39 , T_9 V_40 , T_9 V_41 ,
T_9 V_42 , T_9 V_13 )
{
T_7 V_19 ;
T_7 V_17 , V_15 ;
V_17 = F_25 ( V_39 , V_40 , V_41 , V_42 ) ;
V_15 = F_26 ( V_43 , V_42 , V_13 ) ;
F_9 ( V_38 , V_22 , V_17 ) ;
F_9 ( V_38 , V_23 , V_15 ) ;
V_19 = ( F_2 ( V_38 , V_24 )
>> ( ( V_42 & ( 4 - V_13 ) ) * 8 ) ) & ( ( 0x1 << ( V_13 * 8 ) ) - 1 ) ;
return V_19 ;
}
static void F_27 ( unsigned int T_8 * V_38 , T_9 V_39 ,
T_9 V_40 , T_9 V_41 , T_9 V_42 , T_9 V_13 ,
T_7 V_18 )
{
T_7 V_17 , V_15 ;
V_17 = F_25 ( V_39 , V_40 , V_41 , V_42 ) ;
V_15 = F_26 ( V_44 , V_42 , V_13 ) ;
F_9 ( V_38 , V_22 , V_17 ) ;
F_9 ( V_38 , V_23 , V_15 ) ;
F_9 ( V_38 , V_27 ,
( V_18 & ( ( 0x1 << ( V_13 * 8 ) ) - 1 ) ) << ( ( V_42 & ( 4 - V_13 ) ) * 8 ) ) ;
}
static T_7 F_28 ( unsigned int T_8 * V_38 ,
T_7 V_45 , T_7 V_13 )
{
F_9 ( V_38 , V_46 , F_29 ( V_47 , V_45 , V_13 ) ) ;
return ( F_2 ( V_38 , V_48 )
>> ( ( V_45 & ( 4 - V_13 ) ) * 8 ) ) & ( ( 0x1 << ( V_13 * 8 ) ) - 1 ) ;
}
static void F_30 ( unsigned int T_8 * V_38 , T_7 V_45 ,
T_7 V_13 , T_7 V_25 )
{
T_7 V_18 ;
V_18 = ( V_25 & ( ( 0x1 << ( V_13 * 8 ) ) - 1 ) ) << ( ( V_45 & ( 4 - V_13 ) ) * 8 ) ;
F_9 ( V_38 , V_46 , F_29 ( V_49 , V_45 , V_13 ) ) ;
F_9 ( V_38 , V_50 , V_18 ) ;
}
static int F_31 ( struct V_51 * V_2 , unsigned int V_52 ,
int V_45 , int V_13 , unsigned int * V_25 )
{
struct V_9 * V_3 = F_32 ( V_2 ) ;
if ( V_2 -> V_53 == V_3 -> V_54 && F_33 ( V_52 ) != 1 ) {
* V_25 = ~ 0 ;
return V_55 ;
}
if ( V_2 -> V_53 == 0 && F_33 ( V_52 ) == 0 )
* V_25 = F_28 ( V_3 -> V_4 , V_45 , V_13 ) ;
else
* V_25 = F_24 ( V_3 -> V_4 , V_2 -> V_53 ,
F_33 ( V_52 ) , F_34 ( V_52 ) , V_45 , V_13 ) ;
return V_56 ;
}
static int F_35 ( struct V_51 * V_2 , unsigned int V_52 ,
int V_45 , int V_13 , unsigned int V_25 )
{
struct V_9 * V_3 = F_32 ( V_2 ) ;
if ( V_2 -> V_53 == V_3 -> V_54 && F_33 ( V_52 ) != 1 )
return V_55 ;
if ( V_2 -> V_53 == 0 && F_33 ( V_52 ) == 0 )
F_30 ( V_3 -> V_4 , V_45 , V_13 , V_25 ) ;
else
F_27 ( V_3 -> V_4 , V_2 -> V_53 ,
F_33 ( V_52 ) , F_34 ( V_52 ) , V_45 , V_13 , V_25 ) ;
return V_56 ;
}
static void F_36 ( unsigned int T_8 * V_38 )
{
F_9 ( V_38 , V_57 , 0xffffffff ) ;
F_9 ( V_38 , V_58 , 0xffffffff ) ;
F_9 ( V_38 , V_59 , 0xffffffff ) ;
}
static void F_37 ( unsigned int T_8 * V_38 )
{
F_9 ( V_38 , V_60 , 0x0000e7f1 ) ;
F_9 ( V_38 , V_61 , 0x03ff01ff ) ;
F_9 ( V_38 , V_62 , 0x0001010f ) ;
F_9 ( V_38 , V_63 , 0x00000001 ) ;
}
static void F_38 ( unsigned int T_8 * V_38 )
{
T_7 V_64 = 0 ;
T_7 V_65 , V_66 , V_67 , V_68 , V_69 ;
T_7 V_70 , V_71 ;
V_65 = F_2 ( V_38 , V_59 ) ;
V_66 = F_2 ( V_38 , V_57 ) ;
V_67 = F_2 ( V_38 , V_58 ) ;
V_68 = F_2 ( V_38 , V_72 ) ;
V_69 = F_2 ( V_38 , V_73 ) ;
if ( V_65 || V_66 || V_67 || V_68 || V_69 )
V_64 = 1 ;
F_39 ( L_7 ) ;
F_39 ( L_8 , V_65 ) ;
F_39 ( L_9 , V_66 ) ;
F_39 ( L_10 , V_67 ) ;
F_39 ( L_11 , V_68 ) ;
F_39 ( L_12 , V_69 ) ;
if ( V_65 & 0x00004000 ) {
T_7 V_74 , V_8 ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
V_8 = 1 << V_74 ;
if ( V_67 & V_8 ) {
V_70 = F_2 ( V_38 , F_40 ( V_74 ) ) ;
V_71 = F_2 ( V_38 , F_41 ( V_74 ) ) ;
F_39 ( L_13 , V_74 , V_71 ) ;
F_39 ( L_14 , V_74 , V_70 ) ;
}
}
}
if ( V_64 )
F_36 ( V_38 ) ;
}
static T_10 F_42 ( int V_75 , void * V_76 )
{
struct V_9 * V_3 = V_76 ;
F_10 ( L_15 , V_75 ) ;
F_8 ( V_3 -> V_4 == NULL ) ;
F_38 ( V_3 -> V_4 ) ;
return V_77 ;
}
static T_5 int F_43 ( struct V_78 * V_79 ,
struct V_9 * V_3 )
{
struct V_80 V_81 ;
struct V_82 V_83 ;
int V_84 ;
if ( F_44 ( V_79 , 0 , & V_81 ) ) {
F_20 ( L_16 ) ;
return 1 ;
}
V_3 -> V_4 = F_45 ( V_81 . V_85 , F_46 ( & V_81 ) ) ;
if ( ! V_3 -> V_4 ) {
F_20 ( L_17 ) ;
return 1 ;
}
V_3 -> V_86 = NULL ;
V_3 -> V_87 = & V_88 ;
if ( F_47 ( V_79 , 1 , & V_83 ) ) {
F_20 ( L_18 ) ;
goto error;
}
V_84 = F_48 ( V_83 . V_89 , V_83 . V_90 ,
V_83 . V_13 ) ;
if ( F_49 ( V_84 , F_42 ,
V_91 , L_19 , ( void * ) V_3 ) ) {
F_20 ( L_20 ) ;
goto error;
}
F_36 ( V_3 -> V_4 ) ;
F_37 ( V_3 -> V_4 ) ;
return 0 ;
error:
V_3 -> V_86 = NULL ;
if ( V_3 -> V_4 )
F_50 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
return 1 ;
}
