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
if ( V_32 == true ) {
V_6 = F_13 ( V_8 ) ;
V_33 = F_14 ( V_8 ) ;
F_7 ( V_2 -> V_8 , L_3 , V_33 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_8 , L_4 , V_6 ) ;
return V_6 ;
}
if ( ( V_2 -> V_34 == V_35 ) && ( V_33 == 1 ) ) {
V_6 = F_15 ( V_2 ) ;
if ( V_6 ) {
F_5 ( V_8 , L_5 , V_6 ) ;
F_16 ( V_2 , V_35 ) ;
V_6 = F_17 ( V_2 ) ;
}
}
} else {
V_33 = F_14 ( V_8 ) ;
F_7 ( V_2 -> V_8 , L_6 , V_33 ) ;
return F_17 ( V_2 ) ;
}
return V_6 ;
}
static int F_18 ( struct V_31 * V_8 ,
struct V_9 * V_10 )
{
int V_13 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( ! V_10 )
return - V_26 ;
V_13 = F_10 ( V_2 , V_10 ) ;
if ( V_13 > 0 )
V_2 -> V_36 ++ ;
else
F_5 ( V_2 -> V_8 , L_7 , V_13 ) ;
return V_13 ;
}
static int F_19 ( struct V_31 * V_8 ,
struct V_9 * V_37 , struct V_38 * V_39 )
{
int V_3 , V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_13 = F_13 ( V_2 -> V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_3 = F_10 ( V_2 , V_37 ) ;
if ( V_3 > 0 ) {
F_7 ( V_8 , L_8 , V_3 ) ;
V_5 = & V_2 -> V_7 [ V_3 ] ;
V_5 -> V_40 = V_39 -> V_40 ;
V_5 -> V_41 = V_39 -> V_42 ;
V_5 -> V_43 = V_39 -> V_43 ;
V_5 -> V_44 = V_39 -> V_44 ;
} else {
F_5 ( V_8 , L_9 , V_3 ) ;
V_3 = - V_26 ;
F_17 ( V_2 ) ;
}
return V_3 ;
}
static int F_20 ( struct V_31 * V_8 , unsigned int V_3 )
{
int V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 ) {
F_5 ( V_8 , L_10 , V_3 ) ;
return - V_26 ;
}
if ( V_5 -> V_45 == V_46 ) {
F_7 ( V_8 , L_11 ) ;
V_5 -> V_45 = V_47 ;
V_13 = 0 ;
goto V_48;
}
V_13 = F_3 ( V_2 , V_3 ) ;
V_48:
V_5 -> V_41 = NULL ;
V_5 -> V_40 = NULL ;
if ( V_13 )
F_5 ( V_8 , L_12 , V_13 ) ;
F_7 ( V_8 , L_13 ) ;
return V_13 ;
}
static int F_21 ( struct V_31 * V_8 , unsigned int V_3 ,
unsigned long V_49 )
{
struct V_4 * V_5 ;
struct V_50 V_51 = { 0 ,} ;
int V_52 ;
void T_1 * V_53 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_54 += V_49 ;
F_7 ( V_8 , L_14 , V_5 -> V_54 , V_49 ) ;
F_22 ( & V_51 ,
( ( void * ) ( V_2 -> V_55 + V_2 -> V_56 )
+ ( V_3 * sizeof( V_51 ) ) ) ,
sizeof( V_51 ) ) ;
V_51 . V_57 = V_5 -> V_54 ;
F_7 ( V_8 , L_15 ,
V_51 . V_57 , V_49 ) ;
V_53 = ( ( void * ) ( V_2 -> V_55 + V_2 -> V_56 ) ) +
( V_3 * sizeof( V_51 ) ) ;
V_52 = F_23 ( struct V_50 , V_57 ) ;
F_24 ( V_53 , V_52 , V_51 . V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_8 ,
unsigned int V_3 , struct V_58 * V_59 )
{
int V_13 = 0 ;
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_7 ( V_8 , L_16 , V_3 ) ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
F_7 ( V_8 , L_17 , V_29 -> V_60 ) ;
V_13 = F_26 ( V_2 , V_29 -> V_61 , V_62 ,
V_63 , V_29 -> V_60 ,
sizeof( * V_59 ) , V_59 , NULL ,
true , true , true , false ) ;
return V_13 ;
}
static int F_27 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_28 ( V_2 , V_3 ) ;
}
static int F_29 ( struct V_31 * V_8 ,
unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_30 ( V_2 , V_3 ) ;
}
static int F_31 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_64 = V_29 -> V_45 ;
V_29 -> V_45 = V_65 ;
return F_32 ( V_2 , V_3 ) ;
}
static int F_33 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_34 ( V_2 , V_3 ) ;
}
static int F_35 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_36 ( V_2 , V_3 , false ) ;
}
static int F_37 ( struct V_31 * V_8 ,
unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_36 ( V_2 , V_3 , true ) ;
}
static int F_38 ( struct V_31 * V_8 , unsigned int V_3 ,
struct V_66 * V_56 )
{
struct V_50 V_51 = { 0 ,} ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_22 ( & V_51 ,
( ( void * ) ( V_2 -> V_55 + V_2 -> V_56 )
+ ( V_3 * sizeof( V_51 ) ) ) ,
sizeof( V_51 ) ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
F_7 ( V_8 , L_18 , V_51 . V_67 ) ;
V_56 -> V_68 = V_51 . V_67 ;
V_56 -> V_69 = V_51 . V_70 ;
V_56 -> V_71 = F_39 ( V_51 . V_72 ,
( V_73 ) V_5 -> V_74 * F_40 ( 24 ) ) ;
V_56 -> V_75 = V_51 . V_76 ;
F_7 ( V_8 , L_19 , V_56 -> V_71 ) ;
F_7 ( V_8 , L_20 ,
V_3 , V_56 -> V_68 , V_56 -> V_69 ) ;
F_7 ( V_8 , L_21 , V_56 -> V_71 ) ;
return 0 ;
}
static int F_41 ( struct V_77 * V_78 )
{
V_78 -> V_79 = V_80 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = V_84 ;
V_78 -> V_85 = V_86 ;
V_78 -> V_87 = V_88 ;
V_78 -> V_89 [ 0 ] = V_90 ;
V_78 -> V_89 [ 1 ] = V_91 ;
return 0 ;
}
static int F_42 ( struct V_92 * V_16 )
{
if ( V_16 -> V_16 == V_90 )
* V_16 = V_93 ;
else if ( V_16 -> V_16 == V_91 )
* V_16 = V_94 ;
else
return - V_26 ;
return 0 ;
}
void F_43 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
F_7 ( V_2 -> V_8 , L_22 ,
V_3 ) ;
V_5 = & V_2 -> V_7 [ V_3 ] ;
if ( V_5 -> V_40 )
V_5 -> V_40 ( V_5 -> V_41 ) ;
}
static int F_44 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_4 * V_5 ;
int V_13 = 0 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 ) {
F_5 ( V_2 -> V_8 , L_10 , V_3 ) ;
return - V_26 ;
}
if ( V_5 -> V_45 == V_46 ) {
F_7 ( V_2 -> V_8 , L_11 ) ;
V_13 = 0 ;
goto V_48;
}
V_13 = F_1 ( V_2 , V_3 ) ;
V_48:
V_5 -> V_95 = NULL ;
V_5 -> V_45 = V_47 ;
V_5 -> V_96 = NULL ;
V_2 -> V_36 -- ;
if ( V_13 )
F_5 ( V_2 -> V_8 , L_12 , V_13 ) ;
F_7 ( V_2 -> V_8 , L_23 ) ;
return 0 ;
}
static inline int F_45 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_99 * V_100 ,
struct V_50 * V_51 )
{
T_2 V_101 , V_102 ;
T_2 V_103 ;
T_3 V_104 , V_105 ;
F_7 ( V_2 -> V_8 , L_24 ,
V_51 -> V_67 ) ;
F_7 ( V_2 -> V_8 , L_25 ,
V_51 -> V_72 ) ;
if ( V_100 -> V_5 == V_106 )
V_101 = ( T_2 ) ( V_51 -> V_67 -
V_51 -> V_72 ) ;
else
V_101 = ( T_2 ) ( V_51 -> V_72 -
V_51 -> V_67 ) ;
V_102 = F_46 ( V_100 -> V_107 , V_101 ) ;
V_103 = F_47 ( V_100 ) ;
F_48 ( V_51 -> V_67 , V_103 , & V_104 ) ;
V_105 = F_49 ( V_100 -> V_107 , V_104 ) ;
F_7 ( V_2 -> V_8 , L_26 , V_101 ) ;
V_98 -> V_108 = V_105 / V_100 -> V_107 -> V_109 ;
V_98 -> V_110 = V_102 ;
F_7 ( V_2 -> V_8 , L_27 ,
V_98 -> V_108 , V_98 -> V_110 ) ;
return 0 ;
}
static int F_50 ( struct V_31 * V_8 , struct V_97 * V_98 )
{
struct V_4 * V_5 ;
struct V_99 * V_100 ;
struct V_50 V_51 ;
unsigned int V_3 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_3 = V_98 -> V_3 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
if ( ! V_5 -> V_95 )
return - V_26 ;
V_100 = V_5 -> V_95 ;
F_22 ( & V_51 ,
( ( void * ) ( V_2 -> V_55 + V_2 -> V_56 )
+ ( V_3 * sizeof( V_51 ) ) ) ,
sizeof( V_51 ) ) ;
return F_45 ( V_2 , V_98 , V_100 , & V_51 ) ;
}
static int F_51 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_34 != V_111 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_64 = V_29 -> V_45 ;
V_29 -> V_45 = V_65 ;
F_32 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_34 != V_111 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_64 = V_47 ;
V_29 -> V_45 = V_112 ;
return F_34 ( V_2 , V_3 ) ;
}
static int F_53 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_34 != V_111 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
return F_28 ( V_2 , V_3 ) ;
}
static int F_54 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_34 != V_111 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
return F_30 ( V_2 , V_3 ) ;
}
static int F_55 ( struct V_31 * V_8 , struct V_97 * V_29 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_3 = V_29 -> V_3 ;
if ( V_2 -> V_34 != V_111 )
return 0 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
F_7 ( V_2 -> V_8 , L_28 ) ;
V_5 -> V_95 = V_29 -> V_113 ;
V_5 -> V_96 = V_29 -> V_96 ;
V_5 -> V_21 = V_29 -> V_21 ;
V_5 -> V_64 = V_5 -> V_45 ;
V_5 -> V_45 = V_112 ;
F_7 ( V_2 -> V_8 ,
L_29 ,
V_5 -> V_95 , V_5 -> V_96 ,
V_5 -> V_21 , V_5 -> V_45 ) ;
return 0 ;
}
static int F_56 ( struct V_31 * V_8 ,
struct V_114 * V_49 )
{
int V_115 = 0 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( NULL == V_49 )
return - V_26 ;
V_115 = F_13 ( V_2 -> V_8 ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = F_57 ( V_2 , V_49 ) ;
F_17 ( V_2 ) ;
return V_115 ;
}
int F_58 ( struct V_31 * V_8 )
{
int V_115 ;
V_116 . V_8 = V_8 ;
V_115 = F_59 ( & V_116 ) ;
if ( V_115 )
F_5 ( V_8 , L_30 ) ;
return V_115 ;
}
int F_60 ( struct V_31 * V_8 )
{
return F_61 ( & V_116 ) ;
}
