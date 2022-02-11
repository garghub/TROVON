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
static inline int F_11 ( struct V_2 * V_3 , int V_21 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = F_8 ( V_3 , V_22 , V_21 ? 0xDC : 0x0C ) ;
if ( ! V_8 )
V_4 -> V_23 = V_21 ;
return V_8 ;
}
static int F_12 ( struct V_2 * V_3 , int V_24 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_25 = V_24 * V_4 -> V_26 -> V_27 / ( 8 * 1000 ) ;
int V_8 = F_8 ( V_3 , V_28 , V_25 >> 16 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_29 , V_25 >> 8 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_30 , V_25 & 0xFF ) ;
if ( ! V_8 ) {
V_4 -> V_31 = V_24 ;
V_8 = F_11 ( V_3 , 0 ) ;
}
return V_8 ;
}
static int F_13 ( struct V_2 * V_3 , int V_21 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = F_8 ( V_3 , V_32 , V_21 ? 0x2E : 0x2F ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_33 , V_21 ? 0xFB : 0x7B ) ;
if ( ! V_8 )
V_4 -> V_34 = V_21 ;
return V_8 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_7 = F_5 ( V_3 , V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= 0x7C ;
if ( V_4 -> V_36 )
V_7 |= 0x01 ;
if ( V_4 -> V_37 )
V_7 |= 0x02 ;
return F_8 ( V_3 , V_35 , V_7 | 0x80 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_4 -> V_38 )
return - V_39 ;
V_8 = F_8 ( V_3 , V_40 ,
V_4 -> V_38 -> V_41 ) ;
if ( ! V_8 && V_4 -> V_42 )
V_8 = F_8 ( V_3 , F_16 ( 0 ) ,
V_4 -> V_42 -> V_43 ) ;
if ( ! V_8 )
V_8 = F_14 ( V_3 ) ;
return V_8 ;
}
static int F_17 ( struct V_44 * V_45 )
{
unsigned int V_46 = ~ 0 ;
int V_47 = F_18 ( V_48 ) ;
const struct V_49 * V_50 = & V_48 [ 0 ] ,
* V_51 = NULL ;
while ( V_47 -- ) {
int V_52 = abs ( V_50 -> V_53 - V_45 -> V_53 )
+ abs ( V_50 -> V_54 - V_45 -> V_54 ) ;
if ( V_52 < V_46 ) {
V_46 = V_52 ;
V_51 = V_50 ;
}
V_50 ++ ;
}
if ( V_51 ) {
V_45 -> V_53 = V_51 -> V_53 ;
V_45 -> V_54 = V_51 -> V_54 ;
return 0 ;
}
return - V_39 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_55 * V_56 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_57 ) ; V_47 ++ )
if ( V_56 -> V_58 == V_57 [ V_47 ] . V_58 ) {
* V_56 = V_57 [ V_47 ] ;
F_20 ( 1 , V_59 , V_3 , L_1 ,
V_60 , V_56 -> V_58 ) ;
return 0 ;
}
return - V_39 ;
}
static inline int F_21 ( struct V_2 * V_3 , int V_24 )
{
int V_8 = F_8 ( V_3 , V_61 , V_24 ) ;
if ( ! V_8 )
F_1 ( V_3 ) -> V_62 = V_24 ;
return V_8 ;
}
static inline int F_22 ( struct V_2 * V_3 , int V_24 )
{
int V_8 = F_8 ( V_3 , V_63 , V_24 ) ;
if ( ! V_8 )
F_1 ( V_3 ) -> V_64 = V_24 ;
return V_8 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_65 * V_66 )
{
int V_47 , V_8 = 0 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_57 ) ; V_47 ++ )
if ( V_66 -> V_58 == V_57 [ V_47 ] . V_58 )
break;
if ( V_47 == F_18 ( V_57 ) )
return - V_39 ;
if ( V_66 -> V_24 < V_57 [ V_47 ] . V_67 ||
V_66 -> V_24 > V_57 [ V_47 ] . V_68 )
return - V_69 ;
F_20 ( 1 , V_59 , V_3 , L_2 ,
V_60 , V_66 -> V_58 , V_66 -> V_24 ) ;
switch ( V_66 -> V_58 ) {
case V_70 :
F_13 ( V_3 , V_66 -> V_24 ) ;
break;
case V_71 :
V_8 = F_21 ( V_3 , V_66 -> V_24 ) ;
break;
case V_72 :
V_8 = F_22 ( V_3 , V_66 -> V_24 ) ;
break;
case V_73 :
F_11 ( V_3 ,
V_66 -> V_24 == V_74 ) ;
break;
case V_75 :
V_8 = F_12 ( V_3 , V_66 -> V_24 ) ;
break;
default:
return - V_39 ;
}
return V_8 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_65 * V_66 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_20 ( 1 , V_59 , V_3 , L_3 , V_60 , V_66 -> V_58 ) ;
switch ( V_66 -> V_58 ) {
case V_70 :
V_66 -> V_24 = V_4 -> V_34 ;
break;
case V_71 :
V_66 -> V_24 = V_4 -> V_62 ;
break;
case V_72 :
V_66 -> V_24 = V_4 -> V_64 ;
break;
case V_73 :
V_66 -> V_24 = V_4 -> V_23 ;
break;
case V_75 :
V_66 -> V_24 = V_4 -> V_31 ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned int V_76 ,
enum V_77 * V_78 )
{
if ( ! V_78 || V_76 >= F_18 ( V_79 ) )
return - V_39 ;
* V_78 = V_79 [ V_76 ] . V_78 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_45 )
return - V_39 ;
if ( ! V_4 -> V_38 || ! V_4 -> V_42 ) {
V_8 = F_15 ( V_3 ) ;
if ( V_8 )
return V_8 ;
}
V_45 -> V_53 = V_4 -> V_38 -> V_53 ;
V_45 -> V_54 = V_4 -> V_38 -> V_54 ;
V_45 -> V_78 = V_4 -> V_42 -> V_78 ;
V_45 -> V_80 = V_4 -> V_42 -> V_80 ;
V_45 -> V_81 = V_82 ;
return 0 ;
}
static const struct V_83 * F_27 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
int V_47 = F_18 ( V_79 ) ;
F_17 ( V_45 ) ;
while ( V_47 -- )
if ( V_45 -> V_78 == V_79 [ V_47 ] . V_78 )
break;
V_45 -> V_78 = V_79 [ V_47 ] . V_78 ;
return & V_79 [ V_47 ] ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
if ( ! V_3 || ! V_45 )
return - V_39 ;
F_27 ( V_3 , V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_45 )
return - V_39 ;
V_4 -> V_42 = F_27 ( V_3 , V_45 ) ;
return F_15 ( V_3 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
unsigned long V_84 , V_85 ;
V_8 = F_9 ( V_3 , V_86 ) ;
if ( ! V_8 ) {
V_4 -> V_42 = & V_79 [ 0 ] ;
V_4 -> V_38 = & V_48 [ 0 ] ;
V_8 = F_15 ( V_3 ) ;
}
if ( ! V_8 )
V_8 = F_10 ( V_3 , false , false ) ;
if ( ! V_8 && ! V_4 -> V_26 )
return V_8 ;
V_84 = V_87 * V_4 -> V_26 -> V_27 / ( 8 * 1000 ) ;
V_85 = V_88 * V_4 -> V_26 -> V_27 / ( 8 * 1000 ) ;
F_20 ( 1 , V_59 , V_3 , L_4 , V_60 ,
V_84 , V_85 ) ;
V_8 = F_8 ( V_3 , V_89 , V_84 >> 8 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_90 , V_84 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_91 , V_85 >> 16 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_92 , V_85 >> 8 & 0xFF ) ;
if ( ! V_8 )
V_8 = F_8 ( V_3 , V_93 , V_85 & 0xFF ) ;
return V_8 ;
}
static int F_31 ( struct V_2 * V_3 , int V_94 )
{
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , int V_21 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_95 * V_26 = V_4 -> V_26 ;
int V_8 ;
if ( V_26 == NULL ) {
F_33 ( 1 , L_5 ) ;
return - V_39 ;
}
if ( ! V_21 )
F_10 ( V_3 , false , true ) ;
if ( V_26 -> V_96 ) {
V_8 = V_26 -> V_96 ( & V_6 -> V_97 , V_21 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_21 ) {
V_8 = F_30 ( V_3 ) ;
} else {
V_8 = 0 ;
V_4 -> V_38 = NULL ;
V_4 -> V_42 = NULL ;
}
return V_8 ;
}
static int F_34 ( struct V_5 * V_6 )
{
const struct V_95 * V_26
= V_6 -> V_97 . V_98 ;
int V_8 ;
if ( V_26 -> V_96 ) {
V_8 = V_26 -> V_96 ( & V_6 -> V_97 , 1 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_7 ( V_6 , V_99 ) ;
if ( V_26 -> V_96 )
V_26 -> V_96 ( & V_6 -> V_97 , 0 ) ;
if ( V_8 < 0 ) {
F_35 ( & V_6 -> V_97 , L_6 , V_60 ) ;
return V_8 ;
}
return V_8 == V_100 ? 0 : - V_101 ;
}
static int F_36 ( struct V_5 * V_6 ,
const struct V_102 * V_58 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
const struct V_95 * V_26
= V_6 -> V_97 . V_98 ;
int V_8 ;
if ( ! V_26 ) {
F_35 ( & V_6 -> V_97 , L_7 ) ;
return - V_103 ;
}
V_8 = F_34 ( V_6 ) ;
if ( V_8 )
return V_8 ;
V_4 = F_37 ( sizeof( * V_4 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
V_3 = & V_4 -> V_3 ;
strcpy ( V_3 -> V_106 , V_107 ) ;
V_4 -> V_26 = V_6 -> V_97 . V_98 ;
F_38 ( V_3 , V_6 , & V_108 ) ;
V_4 -> V_10 = - 1 ;
V_4 -> V_36 = 1 ;
V_4 -> V_23 = 1 ;
V_4 -> V_31 = 30 ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_40 ( V_6 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_4 ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_109 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_109 ) ;
}
