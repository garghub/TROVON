static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_4 ,
struct V_5 * V_6 , unsigned int V_7 )
{
int V_8 = 0 ;
T_1 V_9 = V_7 >> 8 & 0xFF ;
if ( V_4 -> V_10 != V_9 && ( V_7 & 0xFF ) != 0x03 ) {
V_8 = F_4 ( V_6 , V_11 , V_9 ) ;
if ( ! V_8 )
V_4 -> V_10 = V_9 ;
}
return V_8 ;
}
static int F_5 ( struct V_2 * V_3 , T_1 V_12 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = F_3 ( V_4 , V_6 , V_12 ) ;
if ( ! V_8 )
V_8 = F_7 ( V_6 , V_12 & 0xFF ) ;
return V_8 ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_12 , T_1 V_13 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = F_3 ( V_4 , V_6 , V_12 ) ;
if ( ! V_8 )
V_8 = F_4 (
V_6 , V_12 & 0xFF , V_13 ) ;
return V_8 ;
}
static inline int F_9 ( struct V_2 * V_3 ,
const struct V_14 * V_15 )
{
while ( V_15 -> V_16 != V_17 ) {
int V_8 = F_8 ( V_3 , V_15 -> V_16 , V_15 -> V_13 ) ;
if ( V_8 )
return V_8 ;
V_15 ++ ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
bool V_18 , bool V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_7 = V_19 ? 0xF1 : 0xF0 ;
int V_8 = 0 ;
if ( V_18 )
V_8 = F_8 ( V_3 , V_20 , V_7 | 0x02 ) ;
if ( ! V_8 ) {
V_8 = F_8 ( V_3 , V_20 , V_7 ) ;
if ( ! V_8 ) {
V_4 -> V_19 = V_19 ;
if ( V_18 )
V_4 -> V_10 = - 1 ;
}
}
return V_8 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_7 = F_5 ( V_3 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= 0x7C ;
if ( V_4 -> V_22 )
V_7 |= 0x01 ;
if ( V_4 -> V_23 )
V_7 |= 0x02 ;
return F_8 ( V_3 , V_21 , V_7 | 0x80 ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_4 -> V_24 )
return - V_25 ;
V_8 = F_8 ( V_3 , V_26 ,
V_4 -> V_24 -> V_27 ) ;
if ( ! V_8 && V_4 -> V_28 )
V_8 = F_8 ( V_3 , F_13 ( 0 ) ,
V_4 -> V_28 -> V_29 ) ;
if ( ! V_8 )
V_8 = F_11 ( V_3 ) ;
return V_8 ;
}
static int F_14 ( struct V_30 * V_31 )
{
unsigned int V_32 = ~ 0 ;
int V_33 = F_15 ( V_34 ) ;
const struct V_35 * V_36 = & V_34 [ 0 ] ,
* V_37 = NULL ;
while ( V_33 -- ) {
int V_38 = abs ( V_36 -> V_39 - V_31 -> V_39 )
+ abs ( V_36 -> V_40 - V_31 -> V_40 ) ;
if ( V_38 < V_32 ) {
V_32 = V_38 ;
V_37 = V_36 ;
}
V_36 ++ ;
}
if ( V_37 ) {
V_31 -> V_39 = V_37 -> V_39 ;
V_31 -> V_40 = V_37 -> V_40 ;
return 0 ;
}
return - V_25 ;
}
static int F_16 ( struct V_41 * V_42 )
{
struct V_1 * V_4 =
F_2 ( V_42 -> V_43 , struct V_1 , V_44 ) ;
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_8 = 0 ;
F_17 ( 1 , V_45 , V_3 , L_1 ,
V_46 , V_42 -> V_47 , V_42 -> V_13 ) ;
switch ( V_42 -> V_47 ) {
case V_48 :
if ( V_42 -> V_49 ) {
V_8 = F_8 ( V_3 , V_50 ,
V_42 -> V_13 ? 0x2E : 0x2F ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_51 ,
V_42 -> V_13 ? 0xFB : 0x7B ) ;
}
if ( ! V_8 && V_4 -> V_52 -> V_49 )
V_8 = F_8 ( V_3 , V_53 , V_4 -> V_52 -> V_13 ) ;
if ( ! V_8 && V_4 -> V_54 -> V_49 )
V_8 = F_8 ( V_3 , V_55 , V_4 -> V_54 -> V_13 ) ;
return V_8 ;
case V_56 :
if ( V_42 -> V_49 )
V_8 = F_8 ( V_3 , V_57 ,
V_42 -> V_13 == V_58 ? 0xDC : 0x0C ) ;
if ( V_4 -> exp -> V_49 ) {
unsigned long V_59 = V_4 -> exp -> V_13 ;
V_59 = V_59 * V_4 -> V_60 -> V_61 / ( 8 * 1000 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_62 ,
V_59 >> 16 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_63 ,
V_59 >> 8 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_64 ,
V_59 & 0xFF ) ;
}
return V_8 ;
default:
return - V_25 ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_65 * V_66 ,
struct V_67 * V_68 )
{
if ( ! V_68 || V_68 -> V_69 ||
V_68 -> V_70 >= F_15 ( V_71 ) )
return - V_25 ;
V_68 -> V_68 = V_71 [ V_68 -> V_70 ] . V_68 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_65 * V_66 ,
struct V_72 * V_73 )
{
struct V_30 * V_31 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_73 || V_73 -> V_69 )
return - V_25 ;
V_31 = & V_73 -> V_73 ;
if ( ! V_4 -> V_24 || ! V_4 -> V_28 ) {
V_8 = F_12 ( V_3 ) ;
if ( V_8 )
return V_8 ;
}
V_31 -> V_39 = V_4 -> V_24 -> V_39 ;
V_31 -> V_40 = V_4 -> V_24 -> V_40 ;
V_31 -> V_68 = V_4 -> V_28 -> V_68 ;
V_31 -> V_74 = V_4 -> V_28 -> V_74 ;
V_31 -> V_75 = V_76 ;
return 0 ;
}
static const struct V_77 * F_20 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
int V_33 = F_15 ( V_71 ) ;
F_14 ( V_31 ) ;
while ( V_33 -- )
if ( V_31 -> V_68 == V_71 [ V_33 ] . V_68 )
break;
V_31 -> V_68 = V_71 [ V_33 ] . V_68 ;
return & V_71 [ V_33 ] ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_65 * V_66 ,
struct V_72 * V_73 )
{
struct V_1 * V_4 = V_3 ? F_1 ( V_3 ) : NULL ;
const struct V_77 * V_78 ;
struct V_30 * V_31 ;
if ( ! V_3 || ! V_73 )
return - V_25 ;
V_31 = & V_73 -> V_73 ;
if ( V_73 -> V_69 )
return - V_25 ;
V_78 = F_20 ( V_3 , V_31 ) ;
if ( V_73 -> V_79 == V_80 ) {
V_66 -> F_20 = * V_31 ;
return 0 ;
}
V_4 -> V_28 = V_78 ;
return F_12 ( V_3 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
unsigned long V_81 , V_82 ;
V_8 = F_9 ( V_3 , V_83 ) ;
if ( ! V_8 ) {
V_4 -> V_28 = & V_71 [ 0 ] ;
V_4 -> V_24 = & V_34 [ 0 ] ;
V_8 = F_12 ( V_3 ) ;
}
if ( ! V_8 )
V_8 = F_10 ( V_3 , false , false ) ;
if ( ! V_8 && ! V_4 -> V_60 )
return V_8 ;
V_81 = V_84 * V_4 -> V_60 -> V_61 / ( 8 * 1000 ) ;
V_82 = V_85 * V_4 -> V_60 -> V_61 / ( 8 * 1000 ) ;
F_17 ( 1 , V_45 , V_3 , L_2 , V_46 ,
V_81 , V_82 ) ;
V_8 = F_8 ( V_3 , V_86 , V_81 >> 8 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_87 , V_81 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_88 , V_82 >> 16 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_89 , V_82 >> 8 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_90 , V_82 & 0xFF ) ;
return V_8 ;
}
static int F_23 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_92 * V_60 = V_4 -> V_60 ;
int V_8 ;
if ( V_60 == NULL ) {
F_24 ( 1 , L_3 ) ;
return - V_25 ;
}
if ( ! V_91 )
F_10 ( V_3 , false , true ) ;
if ( V_60 -> V_93 ) {
V_8 = V_60 -> V_93 ( & V_6 -> V_94 , V_91 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_91 ) {
V_8 = F_22 ( V_3 ) ;
} else {
V_8 = 0 ;
V_4 -> V_24 = NULL ;
V_4 -> V_28 = NULL ;
}
return V_8 ;
}
static int F_25 ( struct V_5 * V_6 )
{
const struct V_92 * V_60
= V_6 -> V_94 . V_95 ;
int V_8 ;
if ( V_60 -> V_93 ) {
V_8 = V_60 -> V_93 ( & V_6 -> V_94 , 1 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_7 ( V_6 , V_96 ) ;
if ( V_60 -> V_93 )
V_60 -> V_93 ( & V_6 -> V_94 , 0 ) ;
if ( V_8 < 0 ) {
F_26 ( & V_6 -> V_94 , L_4 , V_46 ) ;
return V_8 ;
}
return V_8 == V_97 ? 0 : - V_98 ;
}
static int F_27 ( struct V_5 * V_6 ,
const struct V_99 * V_47 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_100 * V_44 ;
const struct V_92 * V_60
= V_6 -> V_94 . V_95 ;
int V_8 ;
if ( ! V_60 ) {
F_26 ( & V_6 -> V_94 , L_5 ) ;
return - V_101 ;
}
V_8 = F_25 ( V_6 ) ;
if ( V_8 )
return V_8 ;
V_4 = F_28 ( & V_6 -> V_94 , sizeof( * V_4 ) , V_102 ) ;
if ( ! V_4 )
return - V_103 ;
V_3 = & V_4 -> V_3 ;
strcpy ( V_3 -> V_104 , V_105 ) ;
V_4 -> V_60 = V_6 -> V_94 . V_95 ;
F_29 ( V_3 , V_6 , & V_106 ) ;
V_44 = & V_4 -> V_44 ;
F_30 ( V_44 , 6 ) ;
V_4 -> V_107 = F_31 ( V_44 , & V_108 ,
V_48 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_54 = F_31 ( V_44 , & V_108 ,
V_109 , 0 , 127 , 1 , 64 ) ;
V_4 -> V_52 = F_31 ( V_44 , & V_108 ,
V_110 , 0 , 127 , 1 , 64 ) ;
V_4 -> V_111 = F_31 ( V_44 , & V_108 ,
V_56 , 0 , 1 , 1 , 1 ) ;
V_4 -> exp = F_31 ( V_44 , & V_108 ,
V_112 , V_84 , V_85 , 1 , 30 ) ;
V_3 -> V_113 = V_44 ;
if ( V_44 -> error ) {
int V_38 = V_44 -> error ;
F_32 ( V_44 ) ;
return V_38 ;
}
F_33 ( 3 , & V_4 -> V_107 , 0 , false ) ;
F_33 ( 2 , & V_4 -> V_111 , V_114 , false ) ;
F_34 ( V_44 ) ;
V_4 -> V_10 = - 1 ;
V_4 -> V_22 = 1 ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_36 ( V_6 ) ;
F_37 ( V_3 ) ;
F_32 ( V_3 -> V_113 ) ;
return 0 ;
}
