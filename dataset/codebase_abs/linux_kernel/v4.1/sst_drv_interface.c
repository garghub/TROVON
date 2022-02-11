int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
int V_6 = 0 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 ) {
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 )
F_4 ( & V_2 -> V_7 [ V_3 ] ) ;
return V_6 ;
} else {
F_5 ( V_2 -> V_8 , L_1 , V_3 ) ;
}
return V_6 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * * V_12 )
{
int V_13 ;
V_13 = V_2 -> V_14 -> V_15 ( V_2 , V_10 ) ;
if ( V_13 > 0 )
F_7 ( V_2 -> V_8 , L_2 , V_13 ) ;
return V_13 ;
}
int F_8 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_16 ) {
case V_17 :
return V_10 -> V_18 . V_19 . V_20 . V_21 ;
case V_22 :
return V_10 -> V_18 . V_19 . V_23 . V_24 ;
case V_25 :
return 0 ;
default:
return - V_26 ;
}
}
int F_9 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_16 ) {
case V_17 :
return V_10 -> V_18 . V_19 . V_20 . V_27 ;
case V_25 :
return V_10 -> V_18 . V_19 . V_28 . V_27 ;
case V_22 :
return V_10 -> V_18 . V_19 . V_23 . V_27 ;
default:
return - V_26 ;
}
}
int F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_13 ;
struct V_4 * V_29 ;
V_13 = V_2 -> V_14 -> V_15 ( V_2 , V_10 ) ;
if ( V_13 <= 0 ) {
return - V_30 ;
}
V_29 = & V_2 -> V_7 [ V_13 ] ;
V_29 -> V_21 = F_8 ( V_10 ) ;
return V_13 ;
}
static int F_11 ( struct V_31 * V_8 , bool V_32 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
int V_6 = 0 ;
int V_33 = 0 ;
#ifdef F_13
V_33 = F_14 ( & V_8 -> V_34 . V_33 ) ;
#else
V_33 = 1 ;
#endif
if ( V_32 == true ) {
V_6 = F_15 ( V_8 ) ;
F_7 ( V_2 -> V_8 , L_3 , V_33 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_8 , L_4 , V_6 ) ;
return V_6 ;
}
if ( ( V_2 -> V_35 == V_36 ) && ( V_33 == 1 ) ) {
V_6 = F_16 ( V_2 ) ;
if ( V_6 ) {
F_5 ( V_8 , L_5 , V_6 ) ;
F_17 ( V_2 , V_36 ) ;
V_6 = F_18 ( V_2 ) ;
}
}
} else {
F_7 ( V_2 -> V_8 , L_6 , V_33 ) ;
return F_18 ( V_2 ) ;
}
return V_6 ;
}
static int F_19 ( struct V_31 * V_8 ,
struct V_9 * V_10 )
{
int V_13 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( ! V_10 )
return - V_26 ;
V_13 = F_10 ( V_2 , V_10 ) ;
if ( V_13 > 0 )
V_2 -> V_37 ++ ;
else
F_5 ( V_2 -> V_8 , L_7 , V_13 ) ;
return V_13 ;
}
static int F_20 ( struct V_31 * V_8 ,
struct V_9 * V_38 , struct V_39 * V_40 )
{
int V_3 , V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_13 = F_15 ( V_2 -> V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_3 = F_10 ( V_2 , V_38 ) ;
if ( V_3 > 0 ) {
F_7 ( V_8 , L_8 , V_3 ) ;
V_5 = & V_2 -> V_7 [ V_3 ] ;
V_5 -> V_41 = V_40 -> V_41 ;
V_5 -> V_42 = V_40 -> V_43 ;
V_5 -> V_44 = V_40 -> V_44 ;
V_5 -> V_45 = V_40 -> V_45 ;
} else {
F_5 ( V_8 , L_9 , V_3 ) ;
V_3 = - V_26 ;
F_18 ( V_2 ) ;
}
return V_3 ;
}
static int F_21 ( struct V_31 * V_8 , unsigned int V_3 )
{
int V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 ) {
F_5 ( V_8 , L_10 , V_3 ) ;
return - V_26 ;
}
if ( V_5 -> V_46 == V_47 ) {
F_7 ( V_8 , L_11 ) ;
V_5 -> V_46 = V_48 ;
V_13 = 0 ;
goto V_49;
}
V_13 = F_3 ( V_2 , V_3 ) ;
V_49:
V_5 -> V_42 = NULL ;
V_5 -> V_41 = NULL ;
if ( V_13 )
F_5 ( V_8 , L_12 , V_13 ) ;
F_7 ( V_8 , L_13 ) ;
return V_13 ;
}
static int F_22 ( struct V_31 * V_8 , unsigned int V_3 ,
unsigned long V_50 )
{
struct V_4 * V_5 ;
struct V_51 V_52 = { 0 ,} ;
int V_53 ;
void T_1 * V_54 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_55 += V_50 ;
F_7 ( V_8 , L_14 , V_5 -> V_55 , V_50 ) ;
F_23 ( & V_52 ,
( ( void * ) ( V_2 -> V_56 + V_2 -> V_57 )
+ ( V_3 * sizeof( V_52 ) ) ) ,
sizeof( V_52 ) ) ;
V_52 . V_58 = V_5 -> V_55 ;
F_7 ( V_8 , L_15 ,
V_52 . V_58 , V_50 ) ;
V_54 = ( ( void * ) ( V_2 -> V_56 + V_2 -> V_57 ) ) +
( V_3 * sizeof( V_52 ) ) ;
V_53 = F_24 ( struct V_51 , V_58 ) ;
F_25 ( V_54 , V_53 , V_52 . V_58 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_8 ,
unsigned int V_3 , struct V_59 * V_60 )
{
int V_13 = 0 ;
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_7 ( V_8 , L_16 , V_3 ) ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
F_7 ( V_8 , L_17 , V_29 -> V_61 ) ;
V_13 = F_27 ( V_2 , V_29 -> V_62 , V_63 ,
V_64 , V_29 -> V_61 ,
sizeof( * V_60 ) , V_60 , NULL ,
true , true , true , false ) ;
return V_13 ;
}
static int F_28 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_29 ( V_2 , V_3 ) ;
}
static int F_30 ( struct V_31 * V_8 ,
unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_31 ( V_2 , V_3 ) ;
}
static int F_32 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_65 = V_29 -> V_46 ;
V_29 -> V_46 = V_66 ;
return F_33 ( V_2 , V_3 ) ;
}
static int F_34 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_35 ( V_2 , V_3 ) ;
}
static int F_36 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_37 ( V_2 , V_3 , false ) ;
}
static int F_38 ( struct V_31 * V_8 ,
unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_37 ( V_2 , V_3 , true ) ;
}
static int F_39 ( struct V_31 * V_8 , unsigned int V_3 ,
struct V_67 * V_57 )
{
struct V_51 V_52 = { 0 ,} ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_23 ( & V_52 ,
( ( void * ) ( V_2 -> V_56 + V_2 -> V_57 )
+ ( V_3 * sizeof( V_52 ) ) ) ,
sizeof( V_52 ) ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
F_7 ( V_8 , L_18 , V_52 . V_68 ) ;
V_57 -> V_69 = V_52 . V_68 ;
V_57 -> V_70 = V_52 . V_71 ;
V_57 -> V_72 = F_40 ( V_52 . V_73 ,
( V_74 ) V_5 -> V_75 * F_41 ( 24 ) ) ;
V_57 -> V_76 = V_52 . V_77 ;
F_7 ( V_8 , L_19 , V_57 -> V_72 ) ;
F_7 ( V_8 , L_20 ,
V_3 , V_57 -> V_69 , V_57 -> V_70 ) ;
F_7 ( V_8 , L_21 , V_57 -> V_72 ) ;
return 0 ;
}
static int F_42 ( struct V_78 * V_79 )
{
V_79 -> V_80 = V_81 ;
V_79 -> V_82 = V_83 ;
V_79 -> V_84 = V_85 ;
V_79 -> V_86 = V_87 ;
V_79 -> V_88 = V_89 ;
V_79 -> V_90 [ 0 ] = V_91 ;
V_79 -> V_90 [ 1 ] = V_92 ;
return 0 ;
}
static int F_43 ( struct V_93 * V_16 )
{
if ( V_16 -> V_16 == V_91 )
* V_16 = V_94 ;
else if ( V_16 -> V_16 == V_92 )
* V_16 = V_95 ;
else
return - V_26 ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
F_7 ( V_2 -> V_8 , L_22 ,
V_3 ) ;
V_5 = & V_2 -> V_7 [ V_3 ] ;
if ( V_5 -> V_41 )
V_5 -> V_41 ( V_5 -> V_42 ) ;
}
static int F_45 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_4 * V_5 ;
int V_13 = 0 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 ) {
F_5 ( V_2 -> V_8 , L_10 , V_3 ) ;
return - V_26 ;
}
if ( V_5 -> V_46 == V_47 ) {
F_7 ( V_2 -> V_8 , L_11 ) ;
V_13 = 0 ;
goto V_49;
}
V_13 = F_1 ( V_2 , V_3 ) ;
V_49:
V_5 -> V_96 = NULL ;
V_5 -> V_46 = V_48 ;
V_5 -> V_97 = NULL ;
V_2 -> V_37 -- ;
if ( V_13 )
F_5 ( V_2 -> V_8 , L_12 , V_13 ) ;
F_7 ( V_2 -> V_8 , L_23 ) ;
return 0 ;
}
static inline int F_46 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_100 * V_101 ,
struct V_51 * V_52 )
{
T_2 V_102 , V_103 ;
T_2 V_104 ;
T_3 V_105 , V_106 ;
F_7 ( V_2 -> V_8 , L_24 ,
V_52 -> V_68 ) ;
F_7 ( V_2 -> V_8 , L_25 ,
V_52 -> V_73 ) ;
if ( V_101 -> V_5 == V_107 )
V_102 = ( T_2 ) ( V_52 -> V_68 -
V_52 -> V_73 ) ;
else
V_102 = ( T_2 ) ( V_52 -> V_73 -
V_52 -> V_68 ) ;
V_103 = F_47 ( V_101 -> V_108 , V_102 ) ;
V_104 = F_48 ( V_101 ) ;
F_49 ( V_52 -> V_68 , V_104 , & V_105 ) ;
V_106 = F_50 ( V_101 -> V_108 , V_105 ) ;
F_7 ( V_2 -> V_8 , L_26 , V_102 ) ;
V_99 -> V_109 = V_106 / V_101 -> V_108 -> V_110 ;
V_99 -> V_111 = V_103 / V_101 -> V_108 -> V_110 ;
F_7 ( V_2 -> V_8 , L_27 ,
V_99 -> V_109 , V_99 -> V_111 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_8 , struct V_98 * V_99 )
{
struct V_4 * V_5 ;
struct V_100 * V_101 ;
struct V_51 V_52 ;
unsigned int V_3 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_3 = V_99 -> V_3 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
if ( ! V_5 -> V_96 )
return - V_26 ;
V_101 = V_5 -> V_96 ;
F_23 ( & V_52 ,
( ( void * ) ( V_2 -> V_56 + V_2 -> V_57 )
+ ( V_3 * sizeof( V_52 ) ) ) ,
sizeof( V_52 ) ) ;
return F_46 ( V_2 , V_99 , V_101 , & V_52 ) ;
}
static int F_52 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_35 != V_112 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_65 = V_29 -> V_46 ;
V_29 -> V_46 = V_66 ;
F_33 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_35 != V_112 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_65 = V_48 ;
V_29 -> V_46 = V_113 ;
return F_35 ( V_2 , V_3 ) ;
}
static int F_54 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_35 != V_112 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
return F_29 ( V_2 , V_3 ) ;
}
static int F_55 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_35 != V_112 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
return F_31 ( V_2 , V_3 ) ;
}
static int F_56 ( struct V_31 * V_8 , struct V_98 * V_29 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_3 = V_29 -> V_3 ;
if ( V_2 -> V_35 != V_112 )
return 0 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
F_7 ( V_2 -> V_8 , L_28 ) ;
V_5 -> V_96 = V_29 -> V_114 ;
V_5 -> V_97 = V_29 -> V_97 ;
V_5 -> V_21 = V_29 -> V_21 ;
V_5 -> V_65 = V_5 -> V_46 ;
V_5 -> V_46 = V_113 ;
F_7 ( V_2 -> V_8 ,
L_29 ,
V_5 -> V_96 , V_5 -> V_97 ,
V_5 -> V_21 , V_5 -> V_46 ) ;
return 0 ;
}
static int F_57 ( struct V_31 * V_8 ,
struct V_115 * V_50 )
{
int V_116 = 0 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( NULL == V_50 )
return - V_26 ;
V_116 = F_15 ( V_2 -> V_8 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_58 ( V_2 , V_50 ) ;
F_18 ( V_2 ) ;
return V_116 ;
}
int F_59 ( struct V_31 * V_8 )
{
int V_116 ;
V_117 . V_8 = V_8 ;
V_116 = F_60 ( & V_117 ) ;
if ( V_116 )
F_5 ( V_8 , L_30 ) ;
return V_116 ;
}
int F_61 ( struct V_31 * V_8 )
{
return F_62 ( & V_117 ) ;
}
