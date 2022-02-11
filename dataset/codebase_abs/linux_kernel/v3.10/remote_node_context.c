const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = V_4 ;
return V_3 [ V_2 ] ;
}
bool F_2 (
struct V_5 * V_6 )
{
T_1 V_7 = V_6 -> V_8 . V_9 ;
if ( V_7 == V_10 ) {
return true ;
}
return false ;
}
bool F_3 ( struct V_5 * V_6 )
{
T_1 V_7 = V_6 -> V_8 . V_9 ;
if ( V_7 == V_11 )
return true ;
return false ;
}
static union V_12 * F_4 ( struct V_13 * V_14 , T_2 V_15 )
{
if ( V_15 < V_14 -> V_16 &&
V_14 -> V_17 [ V_15 ] )
return & V_14 -> V_18 [ V_15 ] ;
return NULL ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_6 ( V_6 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
int V_24 = V_6 -> V_25 ;
union V_12 * V_26 ;
struct V_13 * V_14 ;
T_3 V_27 ;
V_14 = V_20 -> V_28 -> V_29 ;
V_26 = F_4 ( V_14 , V_24 ) ;
memset ( V_26 , 0 , sizeof( union V_12 )
* F_7 ( V_20 ) ) ;
V_26 -> V_30 . V_25 = V_24 ;
V_26 -> V_30 . V_31 = V_20 -> V_32 ;
V_26 -> V_30 . V_33 = V_20 -> V_28 -> V_34 ;
V_27 = F_8 ( F_9 ( V_22 -> V_27 ) ) ;
V_26 -> V_30 . V_35 = F_10 ( V_27 ) ;
V_26 -> V_30 . V_36 = F_11 ( V_27 ) ;
V_26 -> V_30 . V_37 = true ;
V_26 -> V_30 . V_38 = false ;
V_26 -> V_30 . V_39 = false ;
V_26 -> V_30 . V_40 = true ;
V_26 -> V_30 . V_41 = 0 ;
V_26 -> V_30 . V_42 = 0 ;
if ( F_12 ( V_22 ) ) {
V_26 -> V_30 . V_43 =
V_14 -> V_44 . V_45 ;
V_26 -> V_30 . V_46 =
V_14 -> V_44 . V_47 ;
} else {
V_26 -> V_30 . V_43 =
V_14 -> V_44 . V_48 ;
V_26 -> V_30 . V_46 =
V_14 -> V_44 . V_49 ;
}
V_26 -> V_30 . V_50 = 0 ;
V_26 -> V_30 . V_51 = V_20 -> V_52 ;
V_26 -> V_30 . V_53 = 0 ;
V_26 -> V_30 . V_54 = 0 ;
V_26 -> V_30 . V_55 = 0 ;
}
static void F_13 (
struct V_5 * V_6 ,
T_4 V_56 ,
void * V_57 ,
enum V_58 V_59 )
{
if ( V_6 -> V_60 != V_61 ) {
V_6 -> V_60 = V_59 ;
if ( V_56 != NULL ) {
V_6 -> V_62 = V_56 ;
V_6 -> V_63 = V_57 ;
}
}
}
static void F_14 (
struct V_5 * V_6 ,
T_4 V_56 ,
void * V_57 )
{
struct V_13 * V_14 = F_15 ( F_6 ( V_6 ) ) ;
V_6 -> V_60 = V_61 ;
V_6 -> V_62 = V_56 ;
V_6 -> V_63 = V_57 ;
F_16 ( & V_14 -> V_64 ) ;
}
static void F_17 (
struct V_5 * V_26 )
{
if ( V_26 -> V_62 != NULL ) {
(* V_26 -> V_62 )( V_26 -> V_63 ) ;
V_26 -> V_62 = NULL ;
V_26 -> V_63 = NULL ;
}
}
static void F_18 ( struct V_5 * V_26 )
{
switch ( V_26 -> V_60 ) {
case V_65 :
case V_66 :
V_26 -> V_60 = V_65 ;
case V_61 :
F_19 ( V_26 , V_26 -> V_62 ,
V_26 -> V_63 ) ;
break;
default:
V_26 -> V_60 = V_67 ;
break;
}
}
static void F_20 ( struct V_5 * V_6 )
{
union V_12 * V_68 ;
struct V_19 * V_20 = F_6 ( V_6 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_13 * V_14 = V_20 -> V_28 -> V_29 ;
V_68 = F_4 ( V_14 , V_6 -> V_25 ) ;
V_68 -> V_30 . V_39 = true ;
if ( F_12 ( V_22 ) && V_22 -> V_69 ) {
F_21 ( V_20 , V_70 ) ;
} else {
F_21 ( V_20 , V_71 ) ;
if ( ! V_22 -> V_69 )
F_22 ( V_20 -> V_28 ,
V_6 -> V_25 ) ;
}
}
static void F_23 ( struct V_5 * V_6 )
{
union V_12 * V_68 ;
struct V_19 * V_20 = F_6 ( V_6 ) ;
struct V_13 * V_14 = V_20 -> V_28 -> V_29 ;
V_68 = F_4 ( V_14 , V_6 -> V_25 ) ;
V_68 -> V_30 . V_39 = false ;
F_21 ( F_6 ( V_6 ) ,
V_72 ) ;
}
static void F_24 ( struct V_73 * V_8 )
{
struct V_5 * V_26 = F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
struct V_19 * V_20 = F_6 ( V_26 ) ;
struct V_13 * V_14 = V_20 -> V_28 -> V_29 ;
if ( V_8 -> V_74 == V_75 ) {
V_26 -> V_60 = V_67 ;
F_17 ( V_26 ) ;
F_27 () ;
F_16 ( & V_14 -> V_64 ) ;
}
}
static void F_28 ( struct V_73 * V_8 )
{
struct V_5 * V_6 = F_25 ( V_8 , F_26 ( * V_6 ) , V_8 ) ;
F_20 ( V_6 ) ;
}
static void F_29 ( struct V_73 * V_8 )
{
struct V_5 * V_26 = F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
F_30 ( F_6 ( V_26 ) ) ;
F_23 ( V_26 ) ;
}
static void F_31 ( struct V_73 * V_8 )
{
struct V_5 * V_26 = F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_20 = F_6 ( V_26 ) ;
V_22 = V_20 -> V_23 ;
if ( F_12 ( V_22 ) && ! V_22 -> V_69 )
F_22 ( V_20 -> V_28 , V_26 -> V_25 ) ;
F_21 ( V_20 , V_76 ) ;
}
static void F_32 ( struct V_73 * V_8 )
{
struct V_5 * V_26 = F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
enum V_58 V_77 ;
int V_78 = 1 ;
V_77 = V_26 -> V_60 ;
V_26 -> V_60 = V_67 ;
if ( ( V_77 == V_79 ) ||
( V_77 == V_66 ) ) {
F_33 (
V_26 , V_26 -> V_80 ,
V_81 ) ;
if ( V_77 == V_66 )
V_78 = 0 ;
}
if ( V_78 )
F_17 ( V_26 ) ;
}
static void F_34 ( struct V_73 * V_8 )
{
struct V_5 * V_26 = F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
F_18 ( V_26 ) ;
}
static void F_35 ( struct V_73 * V_8 )
{
struct V_5 * V_26 = F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
struct V_19 * V_20 = F_6 ( V_26 ) ;
struct V_13 * V_14 = V_20 -> V_28 -> V_29 ;
T_1 V_82 = V_26 -> V_83 + 1 ;
if ( V_82 == 0 )
V_26 -> V_83 = 1 ;
else
V_26 -> V_83 = V_82 ;
F_27 () ;
F_36 ( V_20 ) ;
F_16 ( & V_14 -> V_64 ) ;
F_18 ( V_26 ) ;
}
static void F_37 (
struct V_73 * V_8 )
{
struct V_5 * V_26
= F_25 ( V_8 , F_26 ( * V_26 ) , V_8 ) ;
struct V_19 * V_20 = F_6 ( V_26 ) ;
if ( F_12 ( V_20 -> V_23 ) )
F_38 ( V_20 , 0 ) ;
}
void F_39 ( struct V_5 * V_26 ,
T_2 V_25 )
{
memset ( V_26 , 0 , sizeof( struct V_5 ) ) ;
V_26 -> V_25 = V_25 ;
V_26 -> V_60 = V_67 ;
F_40 ( & V_26 -> V_8 , V_84 , V_85 ) ;
}
enum V_86 F_41 ( struct V_5 * V_6 ,
T_1 V_87 )
{
enum V_1 V_2 ;
T_1 V_88 ;
V_2 = V_6 -> V_8 . V_9 ;
switch ( V_2 ) {
case V_89 :
switch ( F_42 ( V_87 ) ) {
case V_90 :
F_43 ( & V_6 -> V_8 , V_10 ) ;
break;
default:
goto V_91;
}
break;
case V_75 :
if ( F_42 ( V_87 ) == V_92 ) {
if ( V_6 -> V_60 == V_61 )
V_88 = V_85 ;
else
V_88 = V_89 ;
F_43 ( & V_6 -> V_8 , V_88 ) ;
} else {
switch ( F_44 ( V_87 ) ) {
case V_93 :
case V_94 :
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_1
L_2
L_3 , V_95 , V_6 ) ;
break;
default:
goto V_91;
}
}
break;
case V_96 :
if ( F_42 ( V_87 ) == V_97 ) {
F_43 ( & V_6 -> V_8 , V_10 ) ;
} else {
switch ( F_44 ( V_87 ) ) {
case V_93 :
case V_94 :
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_1
L_4 ,
V_95 , V_6 ) ;
break;
default:
goto V_91;
}
}
break;
case V_10 :
switch ( F_44 ( V_87 ) ) {
case V_98 :
F_43 ( & V_6 -> V_8 , V_99 ) ;
V_6 -> V_100 = F_44 ( V_87 ) ;
break;
case V_101 :
F_43 ( & V_6 -> V_8 , V_11 ) ;
V_6 -> V_100 = F_44 ( V_87 ) ;
break;
default:
goto V_91;
}
break;
case V_102 :
switch ( F_44 ( V_87 ) ) {
case V_98 :
V_88 = V_99 ;
break;
case V_101 :
V_88 = V_11 ;
break;
default:
goto V_91;
}
if ( V_6 -> V_100 == F_44 ( V_87 ) )
F_43 ( & V_6 -> V_8 , V_88 ) ;
break;
default:
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_5 , V_95 ,
F_1 ( V_2 ) ) ;
return V_103 ;
}
return V_104 ;
V_91:
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_6 , V_95 , V_87 ,
F_1 ( V_2 ) ) ;
return V_105 ;
}
enum V_86 F_47 ( struct V_5 * V_6 ,
T_4 V_106 ,
void * V_107 )
{
enum V_1 V_2 ;
V_2 = V_6 -> V_8 . V_9 ;
switch ( V_2 ) {
case V_75 :
F_14 ( V_6 , V_106 , V_107 ) ;
return V_104 ;
case V_89 :
case V_96 :
case V_10 :
case V_99 :
case V_11 :
F_14 ( V_6 , V_106 , V_107 ) ;
F_43 ( & V_6 -> V_8 , V_75 ) ;
return V_104 ;
case V_102 :
F_14 ( V_6 , V_106 , V_107 ) ;
return V_104 ;
case V_85 :
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_5 , V_95 ,
F_1 ( V_2 ) ) ;
return V_104 ;
default:
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_7 , V_95 ,
F_1 ( V_2 ) ) ;
return V_103 ;
}
}
enum V_86 F_33 (
struct V_5 * V_6 ,
enum V_108 V_80 ,
T_1 V_100 )
{
enum V_1 V_2
= V_6 -> V_8 . V_9 ;
struct V_19 * V_20 = F_6 ( V_6 ) ;
enum V_86 V_109 = V_103 ;
enum V_58 V_59 =
V_67 ;
F_48 ( F_46 ( V_20 ) ,
L_8
L_9 ,
V_95 , F_1 ( V_2 ) , V_6 -> V_100 ,
V_6 -> V_60 , V_80 ,
V_100 ) ;
if ( ( V_80 == V_110 ) ||
( V_6 -> V_60 == V_61 ) )
V_59 = V_6 -> V_60 ;
switch ( V_2 ) {
case V_10 :
break;
case V_75 :
if ( V_6 -> V_60 == V_61 ) {
F_45 ( F_46 ( V_20 ) ,
L_10 ,
V_95 , V_6 ) ;
return V_103 ;
}
case V_96 :
case V_89 :
if ( V_6 -> V_60 != V_61 )
V_6 -> V_60 = V_79 ;
V_6 -> V_100 = V_100 ;
V_6 -> V_80 = V_80 ;
return V_104 ;
case V_99 :
if ( V_100 == V_98 )
V_109 = V_104 ;
break;
case V_11 :
if ( V_100 == V_101 )
V_109 = V_104 ;
break;
case V_102 :
if ( ( V_6 -> V_100 == V_101 )
|| ( V_100 == V_6 -> V_100 ) )
return V_104 ;
break;
default:
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_7 , V_95 ,
F_1 ( V_2 ) ) ;
return V_103 ;
}
V_6 -> V_60 = V_59 ;
V_6 -> V_100 = V_100 ;
V_6 -> V_80 = V_80 ;
if ( V_109 == V_104 ) {
struct V_13 * V_14 = V_20 -> V_28 -> V_29 ;
F_49 ( & V_14 -> V_64 ) ;
return V_104 ;
}
if ( ( V_80 == V_111 ) ||
( V_80 == V_112 ) ) {
if ( V_80 == V_112 )
F_38 ( V_20 , 0x00000001 ) ;
F_21 (
V_20 , V_113 ) ;
}
if ( V_2 != V_102 )
F_43 ( & V_6 -> V_8 , V_102 ) ;
return V_104 ;
}
enum V_86 F_19 ( struct V_5 * V_6 ,
T_4 V_106 ,
void * V_107 )
{
enum V_1 V_2 ;
struct V_19 * V_20 = F_6 ( V_6 ) ;
V_2 = V_6 -> V_8 . V_9 ;
F_48 ( F_46 ( V_20 ) ,
L_11
L_12 ,
V_95 , F_1 ( V_2 ) , V_106 , V_107 ,
V_6 -> V_60 ,
F_50 ( V_114 , & V_20 -> V_115 )
? L_13 : L_14 ) ;
switch ( V_2 ) {
case V_85 :
if ( V_6 -> V_25 == V_116 )
return V_103 ;
F_13 ( V_6 , V_106 , V_107 ,
V_65 ) ;
if ( ! F_50 ( V_114 , & V_20 -> V_115 ) ) {
F_5 ( V_6 ) ;
F_43 ( & V_6 -> V_8 , V_89 ) ;
}
return V_104 ;
case V_89 :
case V_75 :
case V_96 :
switch ( V_6 -> V_60 ) {
case V_79 :
case V_66 :
F_13 (
V_6 , V_106 , V_107 ,
V_66 ) ;
break;
default:
F_13 (
V_6 , V_106 , V_107 ,
V_65 ) ;
break;
}
return V_104 ;
case V_99 :
case V_11 :
{
struct V_21 * V_22 = V_20 -> V_23 ;
F_13 (
V_6 , V_106 , V_107 , V_65 ) ;
if ( ! F_50 ( V_114 , & V_20 -> V_115 ) ) {
if ( ( F_12 ( V_22 ) && V_22 -> V_69 ) ||
( V_6 -> V_60 == V_61 ) )
F_43 ( & V_6 -> V_8 ,
V_75 ) ;
else
F_43 ( & V_6 -> V_8 ,
V_96 ) ;
}
}
return V_104 ;
case V_102 :
F_13 (
V_6 , V_106 , V_107 , V_66 ) ;
return V_104 ;
default:
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_7 , V_95 ,
F_1 ( V_2 ) ) ;
return V_103 ;
}
}
enum V_86 F_51 ( struct V_5 * V_6 ,
struct V_117 * V_118 )
{
enum V_1 V_2 ;
V_2 = V_6 -> V_8 . V_9 ;
switch ( V_2 ) {
case V_10 :
return V_104 ;
case V_99 :
case V_11 :
case V_102 :
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_7 , V_95 ,
F_1 ( V_2 ) ) ;
return V_119 ;
default:
F_48 ( F_46 ( F_6 ( V_6 ) ) ,
L_7 , V_95 ,
F_1 ( V_2 ) ) ;
return V_103 ;
}
}
enum V_86 F_52 (
struct V_5 * V_6 ,
struct V_117 * V_118 ,
T_4 V_106 ,
void * V_107 )
{
enum V_86 V_109 = F_19 ( V_6 ,
V_106 , V_107 ) ;
if ( V_109 != V_104 )
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_15 , V_95 , V_109 ) ;
return V_109 ;
}
int F_53 (
struct V_5 * V_6 )
{
enum V_1 V_2 ;
V_2 = V_6 -> V_8 . V_9 ;
switch ( V_2 ) {
case V_75 :
case V_11 :
return 1 ;
case V_89 :
case V_96 :
case V_10 :
case V_99 :
case V_102 :
case V_85 :
return 0 ;
default:
F_45 ( F_46 ( F_6 ( V_6 ) ) ,
L_16 , V_95 , V_2 ) ;
return 0 ;
}
}
