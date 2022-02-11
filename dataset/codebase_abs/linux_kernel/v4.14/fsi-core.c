int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 ,
T_2 V_5 )
{
if ( V_3 > V_2 -> V_5 || V_5 > V_2 -> V_5 || V_3 > V_2 -> V_5 - V_5 )
return - V_6 ;
return F_2 ( V_2 -> V_7 , V_2 -> V_3 + V_3 , V_4 , V_5 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , const void * V_4 ,
T_2 V_5 )
{
if ( V_3 > V_2 -> V_5 || V_5 > V_2 -> V_5 || V_3 > V_2 -> V_5 - V_5 )
return - V_6 ;
return F_4 ( V_2 -> V_7 , V_2 -> V_3 + V_3 , V_4 , V_5 ) ;
}
int F_5 ( struct V_1 * V_2 , void * V_4 )
{
T_1 V_3 = V_8 + ( ( V_2 -> V_9 - 2 ) * sizeof( T_1 ) ) ;
return F_2 ( V_2 -> V_7 , V_3 , V_4 , sizeof( T_1 ) ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_10 = F_7 ( V_11 ) ;
F_8 ( V_10 ) ;
}
static struct V_1 * F_9 ( struct V_12 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 . V_14 = & V_7 -> V_2 ;
V_2 -> V_2 . V_15 = & V_16 ;
V_2 -> V_2 . V_17 = F_6 ;
return V_2 ;
}
static int F_11 ( struct V_12 * V_7 , T_1 * V_18 ,
T_3 * V_19 )
{
T_1 V_3 = * V_18 ;
T_3 V_20 = * V_19 ;
if ( V_3 > V_7 -> V_5 )
return - V_6 ;
if ( V_3 > 0x1fffff ) {
if ( V_7 -> V_20 != 0 )
return - V_6 ;
V_20 = ( V_3 >> 21 ) & 0x3 ;
V_3 &= 0x1fffff ;
}
* V_18 = V_3 ;
* V_19 = V_20 ;
return 0 ;
}
int F_12 ( struct V_12 * V_7 )
{
struct V_21 * V_22 = V_7 -> V_22 ;
T_1 V_23 , V_24 ;
int V_25 , V_26 ;
T_3 V_20 ;
V_26 = V_7 -> V_26 ;
V_20 = V_7 -> V_20 ;
V_25 = F_13 ( V_22 , V_26 , V_20 , V_27 + V_28 ,
& V_23 , sizeof( V_23 ) ) ;
if ( V_25 )
return V_25 ;
V_25 = F_13 ( V_22 , V_26 , V_20 , V_27 + V_29 ,
& V_24 , sizeof( V_24 ) ) ;
if ( V_25 )
return V_25 ;
F_14 ( & V_7 -> V_2 , L_1 ,
F_15 ( V_24 ) , F_15 ( V_23 ) ) ;
return F_16 ( V_22 , V_26 , V_20 , V_27 + V_28 ,
& V_23 , sizeof( V_23 ) ) ;
}
int F_17 ( struct V_12 * V_7 , bool V_30 , T_1 V_3 ,
T_2 V_5 )
{
struct V_21 * V_22 = V_7 -> V_22 ;
int V_25 , V_26 ;
T_1 V_31 ;
T_3 V_20 ;
if ( V_32 )
return - 1 ;
V_26 = V_7 -> V_26 ;
V_20 = V_7 -> V_20 ;
F_18 ( & V_7 -> V_2 , L_2 ,
V_30 ? L_3 : L_4 , V_3 , V_5 ) ;
V_25 = F_12 ( V_7 ) ;
if ( ! V_25 )
return 0 ;
if ( V_22 -> V_33 ) {
V_25 = V_22 -> V_33 ( V_22 , V_26 , V_20 ) ;
if ( ! V_25 ) {
V_25 = F_13 ( V_22 , V_26 , V_20 , 0 ,
& V_31 , sizeof( V_31 ) ) ;
if ( ! V_25 )
V_25 = F_12 ( V_7 ) ;
if ( ! V_25 )
return 0 ;
}
}
V_25 = F_19 ( V_22 , V_26 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_20 ( V_22 , V_26 , V_20 ) ;
if ( V_25 )
return V_25 ;
return F_12 ( V_7 ) ;
}
int F_2 ( struct V_12 * V_7 , T_1 V_3 ,
void * V_4 , T_2 V_5 )
{
T_3 V_20 = V_7 -> V_20 ;
int V_25 , V_34 , V_35 ;
V_25 = F_11 ( V_7 , & V_3 , & V_20 ) ;
if ( V_25 )
return V_25 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_25 = F_13 ( V_7 -> V_22 , V_7 -> V_26 ,
V_20 , V_3 , V_4 , V_5 ) ;
if ( ! V_25 )
break;
V_34 = F_17 ( V_7 , false , V_3 , V_5 ) ;
if ( V_34 )
break;
}
return V_25 ;
}
int F_4 ( struct V_12 * V_7 , T_1 V_3 ,
const void * V_4 , T_2 V_5 )
{
T_3 V_20 = V_7 -> V_20 ;
int V_25 , V_34 , V_35 ;
V_25 = F_11 ( V_7 , & V_3 , & V_20 ) ;
if ( V_25 )
return V_25 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_25 = F_16 ( V_7 -> V_22 , V_7 -> V_26 ,
V_20 , V_3 , V_4 , V_5 ) ;
if ( ! V_25 )
break;
V_34 = F_17 ( V_7 , true , V_3 , V_5 ) ;
if ( V_34 )
break;
}
return V_25 ;
}
extern int F_21 ( struct V_12 * V_7 ,
T_1 V_3 , T_1 V_5 )
{
if ( V_3 + V_5 < V_3 )
return - V_6 ;
if ( V_3 + V_5 > V_7 -> V_5 )
return - V_6 ;
return 0 ;
}
extern void F_22 ( struct V_12 * V_7 ,
T_1 V_3 , T_1 V_5 )
{
}
static int F_23 ( struct V_12 * V_7 )
{
T_1 V_37 ;
T_1 V_38 ;
int V_25 , V_35 ;
V_37 = V_39 * 3 ;
for ( V_35 = 2 ; V_35 < V_39 / sizeof( T_1 ) ; V_35 ++ ) {
T_3 V_40 , V_41 , type , V_42 ;
struct V_1 * V_2 ;
V_25 = F_2 ( V_7 , ( V_35 + 1 ) * sizeof( V_38 ) ,
& V_38 , sizeof( V_38 ) ) ;
if ( V_25 ) {
F_24 ( & V_7 -> V_2 ,
L_5 ) ;
return - 1 ;
}
V_38 = F_15 ( V_38 ) ;
V_42 = F_25 ( 0 , V_38 , 32 ) ;
if ( V_42 ) {
F_24 ( & V_7 -> V_2 ,
L_6 ,
V_35 ) ;
return - 1 ;
}
V_40 = ( V_38 & V_43 )
>> V_44 ;
V_41 = ( V_38 & V_45 )
>> V_46 ;
type = ( V_38 & V_47 )
>> V_48 ;
if ( type != 0 && V_40 != 0 ) {
V_2 = F_9 ( V_7 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_50 = type ;
V_2 -> V_41 = V_41 ;
V_2 -> V_9 = V_35 ;
V_2 -> V_3 = V_37 ;
V_2 -> V_5 = V_40 * V_39 ;
F_18 ( & V_7 -> V_2 ,
L_7 ,
V_2 -> V_9 , V_2 -> V_50 , V_41 ,
V_2 -> V_3 , V_2 -> V_5 ) ;
F_26 ( & V_2 -> V_2 , L_8 ,
V_7 -> V_22 -> V_51 , V_7 -> V_26 ,
V_7 -> V_20 , V_35 - 2 ) ;
V_25 = F_27 ( & V_2 -> V_2 ) ;
if ( V_25 ) {
F_24 ( & V_7 -> V_2 , L_9 , V_25 ) ;
F_28 ( & V_2 -> V_2 ) ;
}
}
V_37 += V_40 * V_39 ;
if ( ! ( V_38 & V_52 ) )
break;
}
return 0 ;
}
static T_4 F_29 ( struct V_53 * V_53 ,
struct V_54 * V_55 , struct V_56 * V_57 , char * V_58 ,
T_5 V_59 , T_2 V_60 )
{
struct V_12 * V_7 = F_30 ( F_31 ( V_55 ) ) ;
T_2 V_61 , V_62 ;
int V_25 ;
if ( V_59 < 0 )
return - V_6 ;
if ( V_59 > 0xffffffff || V_60 > 0xffffffff || V_59 + V_60 > 0xffffffff )
return - V_6 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 += V_62 ) {
V_62 = F_32 ( T_2 , V_60 , 4 ) ;
V_62 -= V_59 & 0x3 ;
V_25 = F_2 ( V_7 , V_59 , V_58 + V_61 , V_62 ) ;
if ( V_25 )
return V_25 ;
V_59 += V_62 ;
}
return V_60 ;
}
static T_4 F_33 ( struct V_53 * V_53 ,
struct V_54 * V_55 , struct V_56 * V_57 ,
char * V_58 , T_5 V_59 , T_2 V_60 )
{
struct V_12 * V_7 = F_30 ( F_31 ( V_55 ) ) ;
T_2 V_61 , V_63 ;
int V_25 ;
if ( V_59 < 0 )
return - V_6 ;
if ( V_59 > 0xffffffff || V_60 > 0xffffffff || V_59 + V_60 > 0xffffffff )
return - V_6 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 += V_63 ) {
V_63 = F_32 ( T_2 , V_60 , 4 ) ;
V_63 -= V_59 & 0x3 ;
V_25 = F_4 ( V_7 , V_59 , V_58 + V_61 , V_63 ) ;
if ( V_25 )
return V_25 ;
V_59 += V_63 ;
}
return V_60 ;
}
static T_4 F_34 ( struct V_53 * V_53 ,
struct V_54 * V_55 , struct V_56 * V_57 ,
char * V_58 , T_5 V_59 , T_2 V_60 )
{
struct V_12 * V_7 = F_30 ( F_31 ( V_55 ) ) ;
struct V_21 * V_22 = V_7 -> V_22 ;
if ( ! V_22 -> V_33 )
return - V_64 ;
V_22 -> V_33 ( V_22 , V_7 -> V_26 , V_7 -> V_20 ) ;
return V_60 ;
}
static inline T_1 F_35 ( int V_65 )
{
return ( V_65 & V_66 ) << V_67 ;
}
static inline T_1 F_36 ( int V_65 )
{
return ( V_65 & V_68 ) << V_69 ;
}
static inline T_1 F_37 ( int V_65 )
{
return ( V_65 & V_70 ) << V_71 ;
}
static inline T_1 F_38 ( int V_65 )
{
return ( V_65 & V_72 ) << V_73 ;
}
static T_1 F_39 ( int V_20 )
{
return V_74 | V_75
| F_38 ( V_20 )
| F_35 ( 0xf ) | F_36 ( 0xf )
| F_37 ( 0x8 ) ;
}
static int F_20 ( struct V_21 * V_22 , int V_26 , int V_20 )
{
T_1 V_76 ;
V_76 = F_39 ( V_20 ) ;
V_76 = F_40 ( V_76 ) ;
return F_16 ( V_22 , V_26 , V_20 , V_27 + V_77 ,
& V_76 , sizeof( V_76 ) ) ;
}
static void F_41 ( struct V_10 * V_2 )
{
struct V_12 * V_7 = F_30 ( V_2 ) ;
F_8 ( V_7 ) ;
}
static int F_42 ( struct V_21 * V_22 , int V_26 , T_3 V_20 )
{
T_1 V_78 , V_79 ;
struct V_12 * V_7 ;
T_3 V_42 ;
int V_25 ;
if ( V_20 != 0 )
return - V_6 ;
V_25 = F_13 ( V_22 , V_26 , V_20 , 0 , & V_78 , sizeof( V_78 ) ) ;
if ( V_25 ) {
F_18 ( & V_22 -> V_2 , L_10 ,
V_26 , V_20 , V_25 ) ;
return - V_64 ;
}
V_78 = F_15 ( V_78 ) ;
V_42 = F_25 ( 0 , V_78 , 32 ) ;
if ( V_42 ) {
F_24 ( & V_22 -> V_2 , L_11 ,
V_26 , V_20 ) ;
return - V_80 ;
}
F_14 ( & V_22 -> V_2 , L_12 ,
V_78 , V_22 -> V_51 , V_26 , V_20 ) ;
V_25 = F_20 ( V_22 , V_26 , V_20 ) ;
if ( V_25 ) {
F_24 ( & V_22 -> V_2 ,
L_13 ,
V_26 , V_20 , V_25 ) ;
return - V_64 ;
}
if ( V_22 -> V_81 & V_82 ) {
V_79 = F_40 ( V_83 ) ;
V_25 = F_16 ( V_22 , V_26 , V_20 ,
V_27 + V_84 ,
& V_79 , sizeof( V_79 ) ) ;
if ( V_25 )
F_24 ( & V_22 -> V_2 ,
L_14 ,
V_26 , V_20 , V_25 ) ;
}
V_7 = F_10 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
return - V_49 ;
V_7 -> V_22 = V_22 ;
V_7 -> V_2 . V_14 = & V_22 -> V_2 ;
V_7 -> V_2 . V_17 = F_41 ;
V_7 -> V_26 = V_26 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_5 = V_85 ;
F_26 ( & V_7 -> V_2 , L_15 , V_26 , V_20 ) ;
V_25 = F_27 ( & V_7 -> V_2 ) ;
if ( V_25 < 0 ) {
F_24 ( & V_22 -> V_2 , L_16 ,
V_25 ) ;
F_28 ( & V_7 -> V_2 ) ;
return V_25 ;
}
V_25 = F_43 ( & V_7 -> V_2 , & V_86 ) ;
if ( V_25 )
F_24 ( & V_7 -> V_2 , L_17 , V_25 ) ;
V_25 = F_43 ( & V_7 -> V_2 , & V_87 ) ;
if ( V_25 )
F_24 ( & V_7 -> V_2 , L_18 , V_25 ) ;
V_25 = F_23 ( V_7 ) ;
if ( V_25 )
F_18 ( & V_22 -> V_2 , L_19 ,
V_25 ) ;
return V_25 ;
}
static int F_44 ( T_1 V_3 , T_2 V_5 )
{
if ( V_5 != 1 && V_5 != 2 && V_5 != 4 )
return - V_6 ;
if ( ( V_3 & 0x3 ) != ( V_5 & 0x3 ) )
return - V_6 ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 , int V_26 ,
T_3 V_88 , T_1 V_3 , void * V_4 , T_2 V_5 )
{
int V_25 ;
F_45 ( V_22 , V_26 , V_88 , V_3 , V_5 ) ;
V_25 = F_44 ( V_3 , V_5 ) ;
if ( ! V_25 )
V_25 = V_22 -> V_89 ( V_22 , V_26 , V_88 , V_3 , V_4 , V_5 ) ;
F_46 ( V_22 , V_26 , V_88 , V_3 , V_5 ,
false , V_4 , V_25 ) ;
return V_25 ;
}
static int F_16 ( struct V_21 * V_22 , int V_26 ,
T_3 V_88 , T_1 V_3 , const void * V_4 , T_2 V_5 )
{
int V_25 ;
F_47 ( V_22 , V_26 , V_88 , V_3 , V_5 , V_4 ) ;
V_25 = F_44 ( V_3 , V_5 ) ;
if ( ! V_25 )
V_25 = V_22 -> V_30 ( V_22 , V_26 , V_88 , V_3 , V_4 , V_5 ) ;
F_46 ( V_22 , V_26 , V_88 , V_3 , V_5 ,
true , V_4 , V_25 ) ;
return V_25 ;
}
static int F_48 ( struct V_21 * V_22 , int V_26 )
{
if ( V_22 -> V_90 )
return V_22 -> V_90 ( V_22 , V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 , int V_26 )
{
F_49 ( V_22 , V_26 ) ;
if ( V_22 -> V_91 )
return V_22 -> V_91 ( V_22 , V_26 ) ;
return 0 ;
}
static int F_50 ( struct V_21 * V_22 )
{
int V_26 , V_25 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_92 ; V_26 ++ ) {
V_25 = F_48 ( V_22 , V_26 ) ;
if ( V_25 ) {
F_18 ( & V_22 -> V_2 ,
L_20 , V_26 , V_25 ) ;
continue;
}
V_25 = F_19 ( V_22 , V_26 ) ;
if ( V_25 ) {
F_18 ( & V_22 -> V_2 ,
L_21 , V_26 , V_25 ) ;
continue;
}
F_42 ( V_22 , V_26 , 0 ) ;
}
return 0 ;
}
static int F_51 ( struct V_10 * V_2 , void * V_93 )
{
F_52 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_10 * V_2 , void * V_93 )
{
F_54 ( V_2 , NULL , F_51 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_21 * V_22 )
{
F_54 ( & V_22 -> V_2 , NULL , F_53 ) ;
}
static T_4 F_56 ( struct V_10 * V_2 ,
struct V_94 * V_57 , const char * V_58 , T_2 V_60 )
{
struct V_21 * V_22 = F_57 ( V_2 ) ;
int V_25 ;
F_55 ( V_22 ) ;
V_25 = F_50 ( V_22 ) ;
if ( V_25 < 0 )
return V_25 ;
return V_60 ;
}
static T_4 F_58 ( struct V_10 * V_2 ,
struct V_94 * V_57 , const char * V_58 , T_2 V_60 )
{
struct V_21 * V_22 = F_57 ( V_2 ) ;
F_19 ( V_22 , 0 ) ;
return V_60 ;
}
int F_59 ( struct V_21 * V_22 )
{
int V_25 ;
if ( ! V_22 )
return - V_6 ;
V_22 -> V_51 = F_60 ( & V_95 , 0 , V_96 , V_13 ) ;
F_26 ( & V_22 -> V_2 , L_22 , V_22 -> V_51 ) ;
V_25 = F_27 ( & V_22 -> V_2 ) ;
if ( V_25 ) {
F_61 ( & V_95 , V_22 -> V_51 ) ;
return V_25 ;
}
V_25 = F_62 ( & V_22 -> V_2 , & V_97 ) ;
if ( V_25 ) {
F_52 ( & V_22 -> V_2 ) ;
F_61 ( & V_95 , V_22 -> V_51 ) ;
return V_25 ;
}
V_25 = F_62 ( & V_22 -> V_2 , & V_98 ) ;
if ( V_25 ) {
F_52 ( & V_22 -> V_2 ) ;
F_61 ( & V_95 , V_22 -> V_51 ) ;
return V_25 ;
}
F_50 ( V_22 ) ;
return 0 ;
}
void F_63 ( struct V_21 * V_22 )
{
if ( V_22 -> V_51 >= 0 ) {
F_61 ( & V_95 , V_22 -> V_51 ) ;
V_22 -> V_51 = - 1 ;
}
F_55 ( V_22 ) ;
F_52 ( & V_22 -> V_2 ) ;
}
static int F_64 ( struct V_10 * V_2 , struct V_99 * V_100 )
{
struct V_1 * V_101 = F_7 ( V_2 ) ;
struct V_102 * V_103 = F_65 ( V_100 ) ;
const struct V_104 * V_20 ;
if ( ! V_103 -> V_105 )
return 0 ;
for ( V_20 = V_103 -> V_105 ; V_20 -> V_50 ; V_20 ++ ) {
if ( V_20 -> V_50 != V_101 -> V_50 )
continue;
if ( V_20 -> V_41 == V_106 ||
V_20 -> V_41 == V_101 -> V_41 )
return 1 ;
}
return 0 ;
}
int F_66 ( struct V_102 * V_103 )
{
if ( ! V_103 )
return - V_6 ;
if ( ! V_103 -> V_105 )
return - V_6 ;
return F_67 ( & V_103 -> V_100 ) ;
}
void F_68 ( struct V_102 * V_103 )
{
F_69 ( & V_103 -> V_100 ) ;
}
static int T_6 F_70 ( void )
{
return F_71 ( & V_16 ) ;
}
static void F_72 ( void )
{
F_73 ( & V_16 ) ;
}
