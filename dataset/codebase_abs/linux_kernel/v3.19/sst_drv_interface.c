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
F_7 ( V_2 -> V_8 , L_3 , V_32 ) ;
if ( V_32 == true )
return F_13 ( V_8 ) ;
else
return F_14 ( V_2 ) ;
}
static int F_15 ( struct V_31 * V_8 ,
struct V_9 * V_10 )
{
int V_13 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( ! V_10 )
return - V_26 ;
V_13 = F_10 ( V_2 , V_10 ) ;
if ( V_13 > 0 )
V_2 -> V_33 ++ ;
else
F_5 ( V_2 -> V_8 , L_4 , V_13 ) ;
return V_13 ;
}
static int F_16 ( struct V_31 * V_8 ,
struct V_9 * V_34 , struct V_35 * V_36 )
{
int V_3 , V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_13 = F_13 ( V_2 -> V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_3 = F_10 ( V_2 , V_34 ) ;
if ( V_3 > 0 ) {
F_7 ( V_8 , L_5 , V_3 ) ;
V_5 = & V_2 -> V_7 [ V_3 ] ;
V_5 -> V_37 = V_36 -> V_37 ;
V_5 -> V_38 = V_36 -> V_39 ;
V_5 -> V_40 = V_36 -> V_40 ;
V_5 -> V_41 = V_36 -> V_41 ;
} else {
F_5 ( V_8 , L_6 , V_3 ) ;
V_3 = - V_26 ;
F_14 ( V_2 ) ;
}
return V_3 ;
}
static int F_17 ( struct V_31 * V_8 , unsigned int V_3 )
{
int V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 ) {
F_5 ( V_8 , L_7 , V_3 ) ;
return - V_26 ;
}
if ( V_5 -> V_42 == V_43 ) {
F_7 ( V_8 , L_8 ) ;
V_5 -> V_42 = V_44 ;
V_13 = 0 ;
goto V_45;
}
V_13 = F_3 ( V_2 , V_3 ) ;
V_45:
V_5 -> V_38 = NULL ;
V_5 -> V_37 = NULL ;
if ( V_13 )
F_5 ( V_8 , L_9 , V_13 ) ;
F_7 ( V_8 , L_10 ) ;
return V_13 ;
}
static int F_18 ( struct V_31 * V_8 , unsigned int V_3 ,
unsigned long V_46 )
{
struct V_4 * V_5 ;
struct V_47 V_48 = { 0 ,} ;
int V_49 ;
void T_1 * V_50 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_51 += V_46 ;
F_7 ( V_8 , L_11 , V_5 -> V_51 , V_46 ) ;
F_19 ( & V_48 ,
( ( void * ) ( V_2 -> V_52 + V_2 -> V_53 )
+ ( V_3 * sizeof( V_48 ) ) ) ,
sizeof( V_48 ) ) ;
V_48 . V_54 = V_5 -> V_51 ;
F_7 ( V_8 , L_12 ,
V_48 . V_54 , V_46 ) ;
V_50 = ( ( void * ) ( V_2 -> V_52 + V_2 -> V_53 ) ) +
( V_3 * sizeof( V_48 ) ) ;
V_49 = F_20 ( struct V_47 , V_54 ) ;
F_21 ( V_50 , V_49 , V_48 . V_54 ) ;
return 0 ;
}
static int F_22 ( struct V_31 * V_8 ,
unsigned int V_3 , struct V_55 * V_56 )
{
int V_13 = 0 ;
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_7 ( V_8 , L_13 , V_3 ) ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
F_7 ( V_8 , L_14 , V_29 -> V_57 ) ;
V_13 = F_23 ( V_2 , V_29 -> V_58 , V_59 ,
V_60 , V_29 -> V_57 ,
sizeof( * V_56 ) , V_56 , NULL ,
true , true , true , false ) ;
return V_13 ;
}
static int F_24 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_25 ( V_2 , V_3 ) ;
}
static int F_26 ( struct V_31 * V_8 ,
unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_27 ( V_2 , V_3 ) ;
}
static int F_28 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_61 = V_29 -> V_42 ;
V_29 -> V_42 = V_62 ;
return F_29 ( V_2 , V_3 ) ;
}
static int F_30 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_31 ( V_2 , V_3 ) ;
}
static int F_32 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_33 ( V_2 , V_3 , false ) ;
}
static int F_34 ( struct V_31 * V_8 ,
unsigned int V_3 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
return F_33 ( V_2 , V_3 , true ) ;
}
static int F_35 ( struct V_31 * V_8 , unsigned int V_3 ,
struct V_63 * V_53 )
{
struct V_47 V_48 = { 0 ,} ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_19 ( & V_48 ,
( ( void * ) ( V_2 -> V_52 + V_2 -> V_53 )
+ ( V_3 * sizeof( V_48 ) ) ) ,
sizeof( V_48 ) ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
F_7 ( V_8 , L_15 , V_48 . V_64 ) ;
V_53 -> V_65 = V_48 . V_64 ;
V_53 -> V_66 = V_48 . V_67 ;
V_53 -> V_68 = F_36 ( V_48 . V_69 ,
( V_70 ) ( ( V_5 -> V_71 ) * F_37 ( 24 ) ) ) ;
V_53 -> V_72 = V_48 . V_73 ;
F_7 ( V_8 , L_16 , V_53 -> V_68 ) ;
F_7 ( V_8 , L_17 ,
V_3 , V_53 -> V_65 , V_53 -> V_66 ) ;
F_7 ( V_8 , L_18 , V_53 -> V_68 ) ;
return 0 ;
}
static int F_38 ( struct V_74 * V_75 )
{
V_75 -> V_76 = V_77 ;
V_75 -> V_78 = V_79 ;
V_75 -> V_80 = V_81 ;
V_75 -> V_82 = V_83 ;
V_75 -> V_84 = V_85 ;
V_75 -> V_86 [ 0 ] = V_87 ;
V_75 -> V_86 [ 1 ] = V_88 ;
return 0 ;
}
static int F_39 ( struct V_89 * V_16 )
{
if ( V_16 -> V_16 == V_87 )
* V_16 = V_90 ;
else if ( V_16 -> V_16 == V_88 )
* V_16 = V_91 ;
else
return - V_26 ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
F_7 ( V_2 -> V_8 , L_19 ,
V_3 ) ;
V_5 = & V_2 -> V_7 [ V_3 ] ;
if ( V_5 -> V_37 )
V_5 -> V_37 ( V_5 -> V_38 ) ;
}
static int F_41 ( struct V_31 * V_8 , unsigned int V_3 )
{
struct V_4 * V_5 ;
int V_13 = 0 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 ) {
F_5 ( V_2 -> V_8 , L_7 , V_3 ) ;
return - V_26 ;
}
if ( V_5 -> V_42 == V_43 ) {
F_7 ( V_2 -> V_8 , L_8 ) ;
V_13 = 0 ;
goto V_45;
}
V_13 = F_1 ( V_2 , V_3 ) ;
V_45:
V_5 -> V_92 = NULL ;
V_5 -> V_42 = V_44 ;
V_5 -> V_93 = NULL ;
V_2 -> V_33 -- ;
if ( V_13 )
F_5 ( V_2 -> V_8 , L_9 , V_13 ) ;
F_7 ( V_2 -> V_8 , L_20 ) ;
return 0 ;
}
static inline int F_42 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
struct V_96 * V_97 ,
struct V_47 * V_48 )
{
T_2 V_98 , V_99 ;
T_2 V_100 ;
T_3 V_101 , V_102 ;
F_7 ( V_2 -> V_8 , L_21 ,
V_48 -> V_64 ) ;
F_7 ( V_2 -> V_8 , L_22 ,
V_48 -> V_69 ) ;
if ( V_97 -> V_5 == V_103 )
V_98 = ( T_2 ) ( V_48 -> V_64 -
V_48 -> V_69 ) ;
else
V_98 = ( T_2 ) ( V_48 -> V_69 -
V_48 -> V_64 ) ;
V_99 = F_43 ( V_97 -> V_104 , V_98 ) ;
V_100 = F_44 ( V_97 ) ;
F_45 ( V_48 -> V_64 , V_100 , & V_101 ) ;
V_102 = F_46 ( V_97 -> V_104 , V_101 ) ;
F_7 ( V_2 -> V_8 , L_23 , V_98 ) ;
V_95 -> V_105 = V_102 / V_97 -> V_104 -> V_106 ;
V_95 -> V_107 = V_99 / V_97 -> V_104 -> V_106 ;
F_7 ( V_2 -> V_8 , L_24 ,
V_95 -> V_105 , V_95 -> V_107 ) ;
return 0 ;
}
static int F_47 ( struct V_31 * V_8 , struct V_94 * V_95 )
{
struct V_4 * V_5 ;
struct V_96 * V_97 ;
struct V_47 V_48 ;
unsigned int V_3 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_3 = V_95 -> V_3 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
if ( ! V_5 -> V_92 )
return - V_26 ;
V_97 = V_5 -> V_92 ;
F_19 ( & V_48 ,
( ( void * ) ( V_2 -> V_52 + V_2 -> V_53 )
+ ( V_3 * sizeof( V_48 ) ) ) ,
sizeof( V_48 ) ) ;
return F_42 ( V_2 , V_95 , V_97 , & V_48 ) ;
}
static int F_48 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_108 != V_109 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_61 = V_29 -> V_42 ;
V_29 -> V_42 = V_62 ;
F_29 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_49 ( struct V_31 * V_8 , int V_3 )
{
struct V_4 * V_29 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( V_2 -> V_108 != V_109 )
return 0 ;
V_29 = F_2 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_26 ;
V_29 -> V_61 = V_44 ;
V_29 -> V_42 = V_110 ;
return F_31 ( V_2 , V_3 ) ;
}
static int F_50 ( struct V_31 * V_8 , struct V_94 * V_29 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
V_3 = V_29 -> V_3 ;
if ( V_2 -> V_108 != V_109 )
return 0 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( ! V_5 )
return - V_26 ;
F_7 ( V_2 -> V_8 , L_25 ) ;
V_5 -> V_92 = V_29 -> V_111 ;
V_5 -> V_93 = V_29 -> V_93 ;
V_5 -> V_21 = V_29 -> V_21 ;
V_5 -> V_61 = V_5 -> V_42 ;
V_5 -> V_42 = V_110 ;
F_7 ( V_2 -> V_8 ,
L_26 ,
V_5 -> V_92 , V_5 -> V_93 ,
V_5 -> V_21 , V_5 -> V_42 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_8 ,
struct V_112 * V_46 )
{
int V_113 = 0 ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
if ( NULL == V_46 )
return - V_26 ;
V_113 = F_13 ( V_2 -> V_8 ) ;
if ( V_113 < 0 )
return V_113 ;
V_113 = F_52 ( V_2 , V_46 ) ;
F_14 ( V_2 ) ;
return V_113 ;
}
int F_53 ( struct V_31 * V_8 )
{
int V_113 ;
V_114 . V_8 = V_8 ;
V_113 = F_54 ( & V_114 ) ;
if ( V_113 )
F_5 ( V_8 , L_27 ) ;
return V_113 ;
}
int F_55 ( struct V_31 * V_8 )
{
return F_56 ( & V_114 ) ;
}
