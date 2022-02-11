static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_3 & V_7 )
V_2 -> V_8 = true ;
else
V_2 -> V_8 = false ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_9 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_3 & V_9 )
V_2 -> V_10 = true ;
else
V_2 -> V_10 = false ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , bool V_11 ,
T_1 V_12 )
{
#ifdef F_5
int V_4 ;
if ( V_12 & V_7 ) {
V_2 -> V_13 = V_11 ;
V_2 -> V_14 = ! V_11 ;
}
if ( V_12 & V_9 ) {
V_2 -> V_15 = V_11 ;
V_2 -> V_16 = ! V_11 ;
}
if ( V_11 ) {
V_4 = F_6 ( & V_2 -> V_17 -> V_18 ) ;
} else {
F_7 ( & V_2 -> V_17 -> V_18 ) ;
V_4 = F_8 ( & V_2 -> V_17 -> V_18 ) ;
}
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 ,
L_1 ,
V_11 , V_4 ) ;
if ( V_11 )
F_10 ( & V_2 -> V_17 -> V_18 ) ;
return V_4 ;
}
if ( V_11 ) {
if ( V_2 -> V_13 ) {
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_13 = false ;
}
if ( V_2 -> V_15 ) {
V_4 = F_3 ( V_2 , V_20 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_15 = false ;
}
}
#endif
return 0 ;
}
static inline bool F_11 ( struct V_1 * V_2 )
{
int V_4 ;
int V_21 ;
V_4 = F_12 ( V_2 -> V_5 , V_22 , & V_21 ) ;
if ( V_4 < 0 )
return false ;
if ( V_21 &
( V_23 |
V_24 ) )
return true ;
else
return false ;
}
static T_2 F_13 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_2 -> V_29 = F_15 ( V_28 ) ;
return V_30 ;
}
static T_2 F_16 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( F_11 ( V_2 ) ) {
F_17 ( V_2 -> V_31 ) ;
return V_32 ;
}
return V_33 ;
}
static T_2 F_18 ( int V_25 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_27 * V_28 = V_36 -> V_28 ;
if ( ! F_19 ( V_28 ) )
V_36 -> V_37 = F_15 ( V_28 ) ;
return V_30 ;
}
static T_2 F_20 ( int V_25 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_27 * V_28 = V_36 -> V_28 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_38 ;
T_1 V_39 [ 16 ] ;
if ( F_19 ( V_28 ) && V_2 -> V_29 ) {
V_36 -> V_37 = V_2 -> V_29 ;
V_2 -> V_29 = 0 ;
}
if ( ! V_36 -> V_37 )
V_36 -> V_37 = F_15 ( V_28 ) ;
V_38 = F_21 ( V_2 -> V_5 , V_40 ,
& V_39 ,
( 3 * 2 ) + 1 ) ;
if ( ! V_38 )
F_22 ( V_28 ,
V_39 , V_36 -> V_37 ) ;
else
F_9 ( & V_2 -> V_17 -> V_18 ,
L_2 ) ;
V_36 -> V_37 = 0 ;
F_23 ( V_28 -> V_41 ) ;
return V_32 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_2 ( V_2 -> V_5 , V_42 ,
V_43 ,
V_44 ) ;
if ( V_38 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_3 ) ;
return - V_45 ;
}
V_38 = F_25 ( V_2 -> V_5 , V_22 ,
V_46 |
V_47 |
V_48
) ;
if ( V_38 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_4 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_5 , V_22 ,
V_47 |
V_49
) ;
}
static int F_27 ( struct V_50 * V_51 ,
bool V_52 )
{
struct V_27 * V_28 = F_28 ( V_51 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_38 ;
if ( V_52 )
V_38 = F_24 ( V_2 ) ;
else
V_38 = F_26 ( V_2 ) ;
if ( V_38 )
F_9 ( & V_2 -> V_17 -> V_18 , L_5 ) ;
return V_38 ;
}
static int F_29 ( struct V_27 * V_28 )
{
int V_38 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_30 ( & V_2 -> V_53 ) ;
V_38 = F_4 ( V_2 , true ,
( V_9 | V_7 ) ) ;
F_31 ( & V_2 -> V_53 ) ;
if ( V_38 )
F_9 ( & V_2 -> V_17 -> V_18 , L_6 ) ;
return V_38 ;
}
static int F_32 ( struct V_27 * V_28 )
{
int V_38 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_30 ( & V_2 -> V_53 ) ;
V_38 = F_4 ( V_2 , false ,
( V_9 | V_7 ) ) ;
F_31 ( & V_2 -> V_53 ) ;
if ( V_38 )
F_9 ( & V_2 -> V_17 -> V_18 , L_7 ) ;
return V_38 ;
}
static int F_33 ( struct V_1 * V_2 , int V_54 ,
int * V_55 , int * V_56 )
{
int V_4 , V_21 , V_57 ;
V_4 = F_12 ( V_2 -> V_5 , V_58 [ V_54 ] . V_21 , & V_21 ) ;
if ( V_4 < 0 )
return V_4 ;
V_57 = ( V_58 [ V_54 ] . V_59 & V_21 ) >> V_58 [ V_54 ] . V_60 ;
* V_55 = V_58 [ V_54 ] . V_61 [ V_57 ] . V_62 ;
* V_56 = V_58 [ V_54 ] . V_61 [ V_57 ] . V_63 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_54 ,
int V_55 , int V_56 )
{
int V_64 , V_57 = - V_65 ;
for ( V_64 = 0 ; V_64 < V_58 [ V_54 ] . V_66 ; V_64 ++ )
if ( V_55 == V_58 [ V_54 ] . V_61 [ V_64 ] . V_62 &&
V_56 == V_58 [ V_54 ] . V_61 [ V_64 ] . V_63 ) {
V_57 = V_64 ;
break;
}
if ( V_57 < 0 )
return V_57 ;
return F_2 ( V_2 -> V_5 , V_58 [ V_54 ] . V_21 ,
V_58 [ V_54 ] . V_59 ,
V_57 << V_58 [ V_54 ] . V_60 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
enum V_67 V_68 ,
int * V_55 , int * V_56 )
{
int V_21 , V_4 ;
V_4 = F_12 ( V_2 -> V_5 , V_6 , & V_21 ) ;
if ( V_4 < 0 )
return V_4 ;
V_21 &= V_69 ;
if ( V_21 >= F_36 ( V_70 ) )
return - V_65 ;
switch ( V_68 ) {
case V_71 :
* V_55 = V_70 [ V_21 ] . V_72 ;
* V_56 = V_70 [ V_21 ] . V_73 ;
return 0 ;
case V_74 :
* V_55 = V_70 [ V_21 ] . V_75 ;
* V_56 = V_70 [ V_21 ] . V_76 ;
return 0 ;
default:
return - V_65 ;
}
}
static int F_37 ( struct V_1 * V_2 ,
enum V_67 V_68 ,
int V_55 , int V_56 )
{
int V_64 ;
switch ( V_55 ) {
case 0 :
V_64 = 0 ;
break;
case 2 :
if ( V_56 != 500000 )
return - V_65 ;
V_64 = 11 ;
break;
case 10 :
V_64 = 6 ;
break;
default:
return - V_65 ;
}
return F_2 ( V_2 -> V_5 ,
V_6 ,
V_69 ,
V_64 ) ;
}
static int F_38 ( struct V_1 * V_2 , int * V_77 )
{
int V_4 ;
T_3 V_39 ;
V_4 = F_21 ( V_2 -> V_5 ,
V_78 , & V_39 , sizeof( V_39 ) ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_8 ) ;
return V_4 ;
}
* V_77 = F_39 ( V_39 ) ;
return V_4 ;
}
static int F_40 ( struct V_1 * V_2 , int V_77 )
{
int V_4 ;
T_3 V_39 ;
V_39 = F_41 ( V_77 & 0x3ff ) ;
V_4 = F_42 ( V_2 -> V_5 ,
V_78 , & V_39 , sizeof( V_39 ) ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_9 ) ;
return V_4 ;
}
return V_4 ;
}
static int F_43 ( struct V_27 * V_28 ,
struct V_79 const * V_54 , int * V_55 ,
int * V_56 , long V_59 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_4 ;
int V_80 ;
T_1 V_12 ;
T_3 V_81 ;
switch ( V_59 ) {
case V_82 :
if ( V_54 -> type != V_71 && V_54 -> type != V_74 )
return - V_65 ;
V_80 = F_44 ( V_28 ) ;
if ( V_80 )
return - V_45 ;
V_12 = V_83 [ V_54 -> V_84 ] . V_12 ;
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_4 ( V_2 , true , V_12 ) ;
if ( V_4 < 0 )
goto V_85;
V_4 = F_21 ( V_2 -> V_5 ,
V_83 [ V_54 -> V_84 ] . V_84 ,
& V_81 , sizeof( V_81 ) ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 , false , V_12 ) ;
goto V_85;
}
V_4 = F_4 ( V_2 , false , V_12 ) ;
V_85:
F_31 ( & V_2 -> V_53 ) ;
F_45 ( V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_55 = F_39 ( V_81 ) ;
return V_86 ;
case V_87 :
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_33 ( V_2 , V_54 -> V_84 , V_55 , V_56 ) ;
F_31 ( & V_2 -> V_53 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_88 ;
case V_89 :
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_35 ( V_2 , V_54 -> type , V_55 , V_56 ) ;
F_31 ( & V_2 -> V_53 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_88 ;
case V_90 :
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_38 ( V_2 , V_55 ) ;
F_31 ( & V_2 -> V_53 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_86 ;
default:
return - V_65 ;
}
}
static int F_46 ( struct V_27 * V_28 ,
struct V_79 const * V_54 , int V_55 ,
int V_56 , long V_59 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_4 ;
switch ( V_59 ) {
case V_87 :
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_34 ( V_2 , V_54 -> V_84 , V_55 , V_56 ) ;
F_31 ( & V_2 -> V_53 ) ;
return V_4 ;
case V_89 :
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_37 ( V_2 , V_54 -> type ,
V_55 , V_56 ) ;
F_31 ( & V_2 -> V_53 ) ;
return V_4 ;
case V_90 :
F_30 ( & V_2 -> V_53 ) ;
V_4 = F_40 ( V_2 , V_55 ) ;
F_31 ( & V_2 -> V_53 ) ;
return V_4 ;
default:
return - V_65 ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
int V_4 ;
int V_91 ;
V_4 = F_12 ( V_2 -> V_5 , V_92 , & V_91 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_10 ) ;
return V_4 ;
}
if ( V_91 != V_93 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_11 ,
V_91 , V_93 ) ;
return - V_94 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_69 ,
V_95 ) ;
if ( V_4 ) {
F_48 ( L_12 , V_4 ) ;
return V_4 ;
}
#ifndef F_5
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_3 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
return V_4 ;
#endif
V_2 -> V_29 = 0 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_4 ;
int V_96 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 |
V_9 ,
V_97 |
V_98 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_8 = false ;
V_2 -> V_10 = false ;
V_4 = F_12 ( V_2 -> V_5 , V_22 , & V_96 ) ;
if ( V_4 ) {
F_9 ( & V_2 -> V_17 -> V_18 , L_13 ) ;
return V_4 ;
}
return 0 ;
}
static bool F_50 ( struct V_99 * V_18 , unsigned int V_21 )
{
switch ( V_21 ) {
case V_6 :
case V_100 :
case V_42 :
return false ;
default:
return true ;
}
}
static int F_51 ( struct V_101 * V_17 ,
const struct V_102 * V_91 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_5 * V_5 ;
int V_4 ;
V_28 = F_52 ( & V_17 -> V_18 , sizeof( * V_2 ) ) ;
if ( ! V_28 )
return - V_103 ;
V_5 = F_53 ( V_17 , & V_104 ) ;
if ( F_54 ( V_5 ) ) {
F_9 ( & V_17 -> V_18 , L_14 ) ;
return F_55 ( V_5 ) ;
}
V_2 = F_14 ( V_28 ) ;
F_56 ( V_17 , V_28 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_5 = V_5 ;
F_57 ( & V_2 -> V_53 ) ;
V_28 -> V_18 . V_105 = & V_17 -> V_18 ;
V_28 -> V_106 = & V_107 ;
V_28 -> V_108 = V_109 ;
V_28 -> V_110 = V_111 ;
V_28 -> V_112 = F_36 ( V_111 ) ;
V_28 -> V_113 = V_114 ;
V_4 = F_47 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_17 -> V_18 , L_15 ) ;
return V_4 ;
}
V_4 = F_58 ( & V_17 -> V_18 ) ;
if ( V_4 < 0 )
goto V_115;
F_59 ( & V_17 -> V_18 ) ;
F_60 ( & V_17 -> V_18 , V_116 ) ;
F_61 ( & V_17 -> V_18 ) ;
if ( V_17 -> V_25 ) {
V_2 -> V_31 = F_62 (
V_28 -> V_18 . V_105 ,
L_16 , V_28 -> V_108 , V_28 -> V_91 ) ;
if ( ! V_2 -> V_31 ) {
V_4 = - V_103 ;
goto V_117;
}
V_2 -> V_31 -> V_18 . V_105 = V_28 -> V_18 . V_105 ;
V_2 -> V_31 -> V_118 = & V_119 ;
V_28 -> V_120 = V_121 ;
F_63 ( V_2 -> V_31 , V_28 ) ;
V_4 = F_64 ( & V_17 -> V_18 , V_17 -> V_25 ,
F_13 , F_16 ,
V_122 | V_123 ,
V_124 , V_28 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_17 -> V_18 , L_17 ,
V_17 -> V_25 ) ;
goto V_117;
}
V_4 = F_65 ( V_28 -> V_18 . V_105 ,
V_2 -> V_31 ) ;
if ( V_4 ) {
F_9 ( & V_17 -> V_18 , L_18 ) ;
goto V_117;
}
V_4 = F_66 ( V_28 -> V_18 . V_105 ,
V_28 ,
F_18 ,
F_20 ,
& V_125 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_17 -> V_18 , L_19 ) ;
goto V_117;
}
}
V_4 = F_67 ( V_28 ) ;
if ( V_4 )
goto V_117;
return 0 ;
V_117:
F_68 ( & V_17 -> V_18 ) ;
F_69 ( & V_17 -> V_18 ) ;
F_10 ( & V_17 -> V_18 ) ;
V_115:
F_49 ( V_2 ) ;
return V_4 ;
}
static int F_70 ( struct V_101 * V_17 )
{
struct V_27 * V_28 = F_71 ( V_17 ) ;
F_72 ( V_28 ) ;
F_68 ( & V_17 -> V_18 ) ;
F_69 ( & V_17 -> V_18 ) ;
F_10 ( & V_17 -> V_18 ) ;
F_49 ( F_14 ( V_28 ) ) ;
return 0 ;
}
static int F_73 ( struct V_99 * V_18 )
{
struct V_27 * V_28 = F_71 ( F_74 ( V_18 ) ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_4 ;
F_30 ( & V_2 -> V_53 ) ;
if ( ! V_2 -> V_14 )
V_2 -> V_13 = V_2 -> V_8 ;
if ( ! V_2 -> V_16 )
V_2 -> V_15 = V_2 -> V_10 ;
V_4 = F_49 ( V_2 ) ;
F_75 ( V_2 -> V_5 ) ;
F_31 ( & V_2 -> V_53 ) ;
return V_4 ;
}
static int F_76 ( struct V_99 * V_18 )
{
struct V_27 * V_28 = F_71 ( F_74 ( V_18 ) ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_4 ;
F_77 ( V_2 -> V_5 ) ;
if ( V_2 -> V_13 ) {
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_13 = false ;
}
if ( V_2 -> V_15 ) {
V_4 = F_3 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_15 = false ;
}
F_78 ( 100 ) ;
return 0 ;
}
