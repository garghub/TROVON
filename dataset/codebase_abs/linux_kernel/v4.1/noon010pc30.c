static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_1 * V_8 ,
struct V_9 * V_10 , unsigned int V_11 )
{
T_1 V_12 = V_11 >> 8 & 0xFF ;
int V_13 = 0 ;
if ( V_8 -> V_14 != V_12 && ( V_11 & 0xFF ) != 0x03 ) {
V_13 = F_5 ( V_10 , V_15 , V_12 ) ;
if ( ! V_13 )
V_8 -> V_14 = V_12 ;
}
return V_13 ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_16 )
{
struct V_9 * V_10 = F_7 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = F_4 ( V_8 , V_10 , V_16 ) ;
if ( V_13 )
return V_13 ;
return F_8 ( V_10 , V_16 & 0xFF ) ;
}
static int F_9 ( struct V_2 * V_3 , T_1 V_16 , T_1 V_17 )
{
struct V_9 * V_10 = F_7 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = F_4 ( V_8 , V_10 , V_16 ) ;
if ( V_13 )
return V_13 ;
return F_5 ( V_10 , V_16 & 0xFF , V_17 ) ;
}
static inline int F_10 ( struct V_2 * V_3 ,
const struct V_18 * V_19 )
{
while ( V_19 -> V_20 != V_21 ) {
int V_13 = F_9 ( V_3 , V_19 -> V_20 , V_19 -> V_17 ) ;
if ( V_13 )
return V_13 ;
V_19 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , bool V_22 , bool V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_11 = V_23 ? 0xF1 : 0xF0 ;
int V_13 = 0 ;
if ( V_22 ) {
V_13 = F_9 ( V_3 , V_24 , V_11 | 0x02 ) ;
F_12 ( 20 ) ;
}
if ( ! V_13 ) {
V_13 = F_9 ( V_3 , V_24 , V_11 ) ;
if ( V_22 && ! V_13 )
V_8 -> V_14 = - 1 ;
}
return V_13 ;
}
static int F_13 ( struct V_2 * V_3 , int V_25 )
{
int V_13 ;
V_13 = F_9 ( V_3 , F_14 ( 1 ) , V_25 ? 0x2E : 0x2F ) ;
if ( ! V_13 )
V_13 = F_9 ( V_3 , F_14 ( 0 ) , V_25 ? 0xFB : 0x7B ) ;
return V_13 ;
}
static int F_15 ( struct V_2 * V_3 , int V_26 , int V_27 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_11 , V_13 ;
V_11 = F_6 ( V_3 , F_16 ( 1 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= 0x7C ;
if ( V_26 )
V_11 |= 0x01 ;
if ( V_27 )
V_11 |= 0x02 ;
V_13 = F_9 ( V_3 , F_16 ( 1 ) , V_11 | 0x80 ) ;
if ( ! V_13 ) {
V_8 -> V_26 = V_26 ;
V_8 -> V_27 = V_27 ;
}
return V_13 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = F_9 ( V_3 , F_16 ( 0 ) ,
V_8 -> V_28 -> V_29 ) ;
if ( V_13 )
return V_13 ;
return F_9 ( V_3 , F_18 ( 0 ) ,
V_8 -> V_30 -> V_31 ) ;
}
static int F_19 ( struct V_32 * V_33 ,
const struct V_34 * * V_35 )
{
unsigned int V_36 = ~ 0 ;
int V_37 = F_20 ( V_38 ) ;
const struct V_34 * V_39 = & V_38 [ 0 ] ,
* V_40 = NULL ;
while ( V_37 -- ) {
int V_41 = abs ( V_39 -> V_42 - V_33 -> V_42 )
+ abs ( V_39 -> V_43 - V_33 -> V_43 ) ;
if ( V_41 < V_36 ) {
V_36 = V_41 ;
V_40 = V_39 ;
}
V_39 ++ ;
}
if ( V_40 ) {
V_33 -> V_42 = V_40 -> V_42 ;
V_33 -> V_43 = V_40 -> V_43 ;
if ( V_35 )
* V_35 = V_40 ;
return 0 ;
}
return - V_44 ;
}
static int F_21 ( struct V_1 * V_8 )
{
int V_13 ;
if ( V_8 -> V_45 ) {
F_22 ( & V_8 -> V_3 , L_1 , V_46 ) ;
return 0 ;
}
if ( F_23 ( V_8 -> V_47 ) )
F_24 ( V_8 -> V_47 , 0 ) ;
if ( F_23 ( V_8 -> V_48 ) )
F_24 ( V_8 -> V_48 , 0 ) ;
V_13 = F_25 ( V_49 , V_8 -> V_50 ) ;
if ( V_13 )
return V_13 ;
if ( F_23 ( V_8 -> V_48 ) ) {
F_26 ( 50 ) ;
F_24 ( V_8 -> V_48 , 1 ) ;
}
if ( F_23 ( V_8 -> V_47 ) ) {
F_12 ( 1000 ) ;
F_24 ( V_8 -> V_47 , 1 ) ;
}
if ( F_23 ( V_8 -> V_48 ) ) {
F_12 ( 1000 ) ;
F_24 ( V_8 -> V_48 , 0 ) ;
F_26 ( 100 ) ;
F_24 ( V_8 -> V_48 , 1 ) ;
F_26 ( 20 ) ;
}
V_8 -> V_45 = 1 ;
F_27 ( 1 , V_51 , & V_8 -> V_3 , L_2 , V_46 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_8 )
{
int V_13 ;
if ( ! V_8 -> V_45 ) {
F_22 ( & V_8 -> V_3 , L_3 , V_46 ) ;
return 0 ;
}
V_13 = F_29 ( V_49 , V_8 -> V_50 ) ;
if ( V_13 )
return V_13 ;
if ( F_23 ( V_8 -> V_47 ) )
F_24 ( V_8 -> V_47 , 0 ) ;
if ( F_23 ( V_8 -> V_48 ) )
F_24 ( V_8 -> V_48 , 0 ) ;
V_8 -> V_45 = 0 ;
F_27 ( 1 , V_51 , & V_8 -> V_3 , L_4 , V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = 0 ;
F_27 ( 1 , V_51 , V_3 , L_5 ,
V_46 , V_5 -> V_52 , V_5 -> V_17 ) ;
F_31 ( & V_8 -> V_53 ) ;
if ( ! V_8 -> V_45 )
goto V_54;
switch ( V_5 -> V_52 ) {
case V_55 :
V_13 = F_13 ( V_3 , V_5 -> V_17 ) ;
break;
case V_56 :
V_13 = F_9 ( V_3 , V_57 , V_5 -> V_17 ) ;
break;
case V_58 :
V_13 = F_9 ( V_3 , V_59 , V_5 -> V_17 ) ;
break;
default:
V_13 = - V_44 ;
}
V_54:
F_32 ( & V_8 -> V_53 ) ;
return V_13 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_62 * V_63 )
{
if ( V_63 -> V_64 >= F_20 ( V_65 ) )
return - V_44 ;
V_63 -> V_63 = V_65 [ V_63 -> V_64 ] . V_63 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_66 * V_67 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_32 * V_33 ;
if ( V_67 -> V_68 == V_69 ) {
if ( V_61 ) {
V_33 = F_35 ( V_3 , V_61 , 0 ) ;
V_67 -> V_70 = * V_33 ;
}
return 0 ;
}
V_33 = & V_67 -> V_70 ;
F_31 ( & V_8 -> V_53 ) ;
V_33 -> V_42 = V_8 -> V_28 -> V_42 ;
V_33 -> V_43 = V_8 -> V_28 -> V_43 ;
V_33 -> V_63 = V_8 -> V_30 -> V_63 ;
V_33 -> V_71 = V_8 -> V_30 -> V_71 ;
V_33 -> V_72 = V_73 ;
F_32 ( & V_8 -> V_53 ) ;
return 0 ;
}
static const struct V_74 * F_36 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
int V_37 = F_20 ( V_65 ) ;
while ( -- V_37 )
if ( V_33 -> V_63 == V_65 [ V_37 ] . V_63 )
break;
V_33 -> V_63 = V_65 [ V_37 ] . V_63 ;
return & V_65 [ V_37 ] ;
}
static int F_37 ( struct V_2 * V_3 , struct V_60 * V_61 ,
struct V_66 * V_67 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_34 * V_35 = NULL ;
const struct V_74 * V_75 ;
struct V_32 * V_33 ;
int V_13 = 0 ;
V_75 = F_36 ( V_3 , & V_67 -> V_70 ) ;
F_19 ( & V_67 -> V_70 , & V_35 ) ;
V_67 -> V_70 . V_71 = V_76 ;
V_67 -> V_70 . V_72 = V_73 ;
if ( V_67 -> V_68 == V_69 ) {
if ( V_61 ) {
V_33 = F_35 ( V_3 , V_61 , 0 ) ;
* V_33 = V_67 -> V_70 ;
}
return 0 ;
}
F_31 ( & V_8 -> V_53 ) ;
if ( ! V_8 -> V_77 ) {
V_8 -> V_78 = 1 ;
V_8 -> V_30 = V_75 ;
V_8 -> V_28 = V_35 ;
} else {
V_13 = - V_79 ;
}
F_32 ( & V_8 -> V_53 ) ;
return V_13 ;
}
static int F_38 ( struct V_2 * V_3 )
{
int V_13 = F_10 ( V_3 , V_80 ) ;
if ( ! V_13 )
V_13 = F_17 ( V_3 ) ;
if ( ! V_13 )
V_13 = F_15 ( V_3 , 1 , 0 ) ;
return V_13 ;
}
static int F_39 ( struct V_2 * V_3 , int V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 ;
F_31 ( & V_8 -> V_53 ) ;
if ( V_25 ) {
V_13 = F_21 ( V_8 ) ;
if ( ! V_13 )
V_13 = F_38 ( V_3 ) ;
} else {
F_11 ( V_3 , false , true ) ;
V_13 = F_28 ( V_8 ) ;
}
F_32 ( & V_8 -> V_53 ) ;
if ( ! V_13 && V_25 )
V_13 = F_40 ( & V_8 -> V_7 ) ;
return V_13 ;
}
static int F_41 ( struct V_2 * V_3 , int V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_13 = 0 ;
F_31 ( & V_8 -> V_53 ) ;
if ( ! V_8 -> V_77 != ! V_25 ) {
V_13 = F_11 ( V_3 , false , ! V_25 ) ;
if ( ! V_13 )
V_8 -> V_77 = V_25 ;
}
if ( ! V_13 && V_25 && V_8 -> V_78 ) {
V_13 = F_17 ( V_3 ) ;
if ( ! V_13 )
V_8 -> V_78 = 0 ;
}
F_32 ( & V_8 -> V_53 ) ;
return V_13 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_43 ( & V_8 -> V_7 , V_3 -> V_81 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , struct V_82 * V_83 )
{
struct V_32 * V_33 = F_35 ( V_3 , V_83 -> V_84 , 0 ) ;
V_33 -> V_42 = V_38 [ 0 ] . V_42 ;
V_33 -> V_43 = V_38 [ 0 ] . V_43 ;
V_33 -> V_63 = V_65 [ 0 ] . V_63 ;
V_33 -> V_71 = V_76 ;
V_33 -> V_72 = V_73 ;
return 0 ;
}
static int F_45 ( struct V_9 * V_10 , struct V_1 * V_8 )
{
int V_13 ;
V_13 = F_21 ( V_8 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_8 ( V_10 , V_85 ) ;
if ( V_13 < 0 )
F_46 ( & V_10 -> V_86 , L_6 , V_13 ) ;
F_28 ( V_8 ) ;
return V_13 == V_87 ? 0 : - V_88 ;
}
static int F_47 ( struct V_9 * V_10 ,
const struct V_89 * V_52 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
const struct V_90 * V_91
= V_10 -> V_86 . V_92 ;
int V_13 ;
int V_37 ;
if ( ! V_91 ) {
F_46 ( & V_10 -> V_86 , L_7 ) ;
return - V_93 ;
}
V_8 = F_48 ( & V_10 -> V_86 , sizeof( * V_8 ) , V_94 ) ;
if ( ! V_8 )
return - V_95 ;
F_49 ( & V_8 -> V_53 ) ;
V_3 = & V_8 -> V_3 ;
F_50 ( V_3 , V_10 , & V_96 ) ;
F_51 ( V_3 -> V_81 , V_97 , sizeof( V_3 -> V_81 ) ) ;
V_3 -> V_98 = & V_99 ;
V_3 -> V_100 |= V_101 ;
F_52 ( & V_8 -> V_7 , 3 ) ;
F_53 ( & V_8 -> V_7 , & V_102 ,
V_55 , 0 , 1 , 1 , 1 ) ;
F_53 ( & V_8 -> V_7 , & V_102 ,
V_58 , 0 , 127 , 1 , 64 ) ;
F_53 ( & V_8 -> V_7 , & V_102 ,
V_56 , 0 , 127 , 1 , 64 ) ;
V_3 -> V_103 = & V_8 -> V_7 ;
V_13 = V_8 -> V_7 . error ;
if ( V_13 )
goto V_104;
V_8 -> V_14 = - 1 ;
V_8 -> V_48 = - V_44 ;
V_8 -> V_47 = - V_44 ;
V_8 -> V_30 = & V_65 [ 0 ] ;
V_8 -> V_28 = & V_38 [ 0 ] ;
if ( F_23 ( V_91 -> V_48 ) ) {
V_13 = F_54 ( & V_10 -> V_86 , V_91 -> V_48 ,
V_105 ,
L_8 ) ;
if ( V_13 ) {
F_46 ( & V_10 -> V_86 , L_9 , V_13 ) ;
goto V_104;
}
V_8 -> V_48 = V_91 -> V_48 ;
F_55 ( V_8 -> V_48 , 0 ) ;
}
if ( F_23 ( V_91 -> V_47 ) ) {
V_13 = F_54 ( & V_10 -> V_86 , V_91 -> V_47 ,
V_105 ,
L_10 ) ;
if ( V_13 ) {
F_46 ( & V_10 -> V_86 , L_9 , V_13 ) ;
goto V_104;
}
V_8 -> V_47 = V_91 -> V_47 ;
F_55 ( V_8 -> V_47 , 0 ) ;
}
for ( V_37 = 0 ; V_37 < V_49 ; V_37 ++ )
V_8 -> V_50 [ V_37 ] . V_50 = V_106 [ V_37 ] ;
V_13 = F_56 ( & V_10 -> V_86 , V_49 ,
V_8 -> V_50 ) ;
if ( V_13 )
goto V_104;
V_8 -> V_84 . V_100 = V_107 ;
V_3 -> V_108 . type = V_109 ;
V_13 = F_57 ( & V_3 -> V_108 , 1 , & V_8 -> V_84 , 0 ) ;
if ( V_13 < 0 )
goto V_104;
V_13 = F_45 ( V_10 , V_8 ) ;
if ( ! V_13 )
return 0 ;
V_104:
F_58 ( & V_8 -> V_7 ) ;
F_59 ( V_3 ) ;
return V_13 ;
}
static int F_60 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_61 ( V_10 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_59 ( V_3 ) ;
F_58 ( & V_8 -> V_7 ) ;
F_62 ( & V_3 -> V_108 ) ;
return 0 ;
}
