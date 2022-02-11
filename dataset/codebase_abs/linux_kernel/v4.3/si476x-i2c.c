static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( & V_2 -> V_4 -> V_5 , L_1 ) ;
V_3 = F_3 ( V_2 ,
V_2 -> V_6 . V_7 ,
V_2 -> V_6 . V_8 ,
V_2 -> V_6 . V_9 ,
V_2 -> V_6 . V_10 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_2 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_5 ( V_2 ,
V_2 -> V_6 . V_11 ,
V_2 -> V_6 . V_12 ,
V_2 -> V_6 . V_13 ,
V_2 -> V_6 . V_14 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_3 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 ,
V_2 -> V_6 . V_15 ,
V_2 -> V_6 . V_16 ,
V_2 -> V_6 . V_17 ,
V_2 -> V_6 . V_18 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_4 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_7 ( V_2 ,
V_2 -> V_6 . V_19 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_5 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_8 ( V_2 ,
V_2 -> V_6 . V_20 ,
V_2 -> V_6 . V_21 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_6 ,
V_3 ) ;
return V_3 ;
}
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_22 ,
F_11 ( V_23 ) ) ;
}
int F_12 ( struct V_1 * V_2 , bool V_24 )
{
struct V_25 * V_4 = V_2 -> V_4 ;
int V_3 ;
if ( ! V_24 ) {
if ( F_13 ( V_2 -> V_26 ) )
F_14 ( V_2 -> V_26 , 1 ) ;
if ( V_4 -> V_27 )
F_15 ( V_4 -> V_27 ) ;
F_16 ( 100 ) ;
if ( ! V_4 -> V_27 ) {
F_17 ( & V_2 -> V_28 , 1 ) ;
F_9 ( V_2 ) ;
}
} else {
if ( V_4 -> V_27 )
F_15 ( V_4 -> V_27 ) ;
else {
F_17 ( & V_2 -> V_28 , 1 ) ;
F_9 ( V_2 ) ;
}
}
V_3 = F_18 ( V_2 ,
& V_2 -> V_29 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_7 ,
V_3 ) ;
goto V_30;
}
if ( V_4 -> V_27 )
F_17 ( & V_2 -> V_28 , 1 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_8 ,
V_3 ) ;
goto V_30;
}
if ( V_4 -> V_27 ) {
V_3 = F_19 ( V_2 -> V_31 ,
V_32 ,
V_33 |
V_34 |
V_35 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_9
L_10 , V_3 ) ;
goto V_30;
}
}
return 0 ;
V_30:
if ( V_3 == - V_36 )
F_17 ( & V_2 -> V_28 , 0 ) ;
if ( V_4 -> V_27 )
V_30 ( V_4 -> V_27 ) ;
else
F_20 ( & V_2 -> V_22 ) ;
if ( F_13 ( V_2 -> V_26 ) )
F_14 ( V_2 -> V_26 , 0 ) ;
return V_3 ;
}
int F_21 ( struct V_1 * V_2 , bool V_24 )
{
int V_3 = 0 ;
F_17 ( & V_2 -> V_28 , 0 ) ;
if ( V_24 ) {
struct V_37 args = {
. V_38 = false ,
} ;
V_3 = F_22 ( V_2 , & args ) ;
}
if ( V_2 -> V_4 -> V_27 )
V_30 ( V_2 -> V_4 -> V_27 ) ;
else
F_20 ( & V_2 -> V_22 ) ;
if ( ! V_24 ) {
if ( F_13 ( V_2 -> V_26 ) )
F_14 ( V_2 -> V_26 , 0 ) ;
}
return V_3 ;
}
int F_23 ( struct V_1 * V_2 ,
enum V_39 V_40 )
{
int V_3 = 0 ;
if ( V_2 -> V_41 == V_42 ) {
F_4 ( & V_2 -> V_4 -> V_5 ,
L_11 ) ;
return - V_43 ;
}
if ( V_40 != V_2 -> V_41 ) {
switch ( V_40 ) {
case V_44 :
V_3 = F_24 ( F_25 ( V_2 -> V_45 ) ,
V_2 -> V_45 ) ;
if ( V_3 < 0 ) {
V_2 -> V_41 = V_42 ;
break;
}
F_16 ( 100 ) ;
V_3 = F_12 ( V_2 , false ) ;
if ( V_3 < 0 )
goto V_46;
V_2 -> V_41 = V_40 ;
break;
case V_47 :
V_2 -> V_41 = V_40 ;
V_3 = F_21 ( V_2 , false ) ;
if ( V_3 < 0 )
V_2 -> V_41 = V_42 ;
V_46:
V_3 = F_26 ( F_25 ( V_2 -> V_45 ) ,
V_2 -> V_45 ) ;
if ( V_3 < 0 )
V_2 -> V_41 = V_42 ;
break;
default:
F_27 () ;
}
}
return V_3 ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_48 ) ;
V_2 -> V_49 = false ;
F_30 ( & V_2 -> V_48 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_48 ) ;
if ( ! V_2 -> V_49 ) {
V_2 -> V_49 = true ;
F_32 ( & V_2 -> V_50 ) ;
}
F_30 ( & V_2 -> V_48 ) ;
}
static void F_33 ( struct V_51 * V_52 )
{
int V_3 ;
struct V_1 * V_2 = F_34 ( V_52 , struct V_1 ,
V_50 ) ;
struct V_53 V_54 ;
F_35 ( V_2 ) ;
V_3 = F_36 ( V_2 , true , false , false , & V_54 ) ;
if ( ! V_3 ) {
int V_55 = V_54 . V_56 ;
F_2 ( & V_2 -> V_4 -> V_5 ,
L_12 , V_55 ) ;
for (; V_55 > 0 ; -- V_55 ) {
V_3 = F_36 ( V_2 , false , false ,
( V_55 == 1 ) , & V_54 ) ;
if ( V_3 < 0 )
goto V_57;
F_37 ( & V_2 -> V_58 , V_54 . V_59 ,
sizeof( V_54 . V_59 ) ) ;
F_2 ( & V_2 -> V_4 -> V_5 , L_13 ,
( int ) sizeof( V_54 . V_59 ) , V_54 . V_59 ) ;
}
F_2 ( & V_2 -> V_4 -> V_5 , L_14 ) ;
F_38 ( & V_2 -> V_60 ) ;
}
V_57:
F_39 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_4 -> V_5 , L_15 ) ;
F_17 ( & V_2 -> V_28 , 0 ) ;
F_38 ( & V_2 -> V_60 ) ;
F_17 ( & V_2 -> V_61 , 1 ) ;
F_42 ( & V_2 -> V_62 ) ;
F_17 ( & V_2 -> V_63 , 1 ) ;
F_42 ( & V_2 -> V_64 ) ;
}
int F_43 ( struct V_1 * V_2 ,
enum V_65 type ,
char * V_66 , int V_67 )
{
static int V_68 ;
int V_3 ;
if ( type == V_69 )
V_3 = F_44 ( V_2 -> V_4 , V_66 , V_67 ) ;
else
V_3 = F_45 ( V_2 -> V_4 , V_66 , V_67 ) ;
if ( V_3 < 0 ) {
if ( V_68 ++ > V_70 )
F_40 ( V_2 ) ;
} else {
V_68 = 0 ;
}
return V_3 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_71 ;
int V_3 = F_43 ( V_2 , V_72 ,
& V_71 , sizeof( V_71 ) ) ;
return ( V_3 < 0 ) ? V_3 : V_71 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_73 = F_46 ( V_2 ) ;
if ( V_73 < 0 ) {
F_4 ( & V_2 -> V_4 -> V_5 , L_16 ) ;
return;
}
if ( V_73 & V_74 ) {
F_2 ( & V_2 -> V_4 -> V_5 , L_17 ) ;
F_17 ( & V_2 -> V_61 , 1 ) ;
F_42 ( & V_2 -> V_62 ) ;
}
if ( V_73 & V_75 ) {
F_2 ( & V_2 -> V_4 -> V_5 , L_18 ) ;
F_31 ( V_2 ) ;
}
if ( V_73 & V_76 ) {
F_2 ( & V_2 -> V_4 -> V_5 , L_19 ) ;
F_17 ( & V_2 -> V_63 , 1 ) ;
F_42 ( & V_2 -> V_64 ) ;
}
}
static void F_48 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_49 ( V_52 ) ;
F_47 ( V_2 ) ;
if ( F_50 ( & V_2 -> V_28 ) )
F_9 ( V_2 ) ;
}
static T_2 F_51 ( int V_27 , void * V_5 )
{
struct V_1 * V_2 = V_5 ;
F_47 ( V_2 ) ;
return V_77 ;
}
static int F_52 ( struct V_1 * V_2 ,
int V_78 , int V_79 ,
int V_80 , int V_81 )
{
switch ( V_78 ) {
case V_82 :
switch ( V_79 ) {
case 5 :
return V_83 ;
case 8 :
return V_84 ;
case 10 :
return V_85 ;
default:
goto V_86;
}
case V_87 :
switch ( V_79 ) {
case 5 :
return V_83 ;
case 7 :
return V_84 ;
case 9 :
return V_85 ;
default:
goto V_86;
}
case V_88 :
switch ( V_79 ) {
case 3 :
return V_83 ;
case 5 :
return V_84 ;
case 7 :
return V_85 ;
default:
goto V_86;
}
case V_89 :
default:
F_27 () ;
return - 1 ;
}
V_86:
F_4 ( & V_2 -> V_4 -> V_5 ,
L_20
L_21 ,
V_79 , V_80 , V_81 ) ;
return V_83 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_90 ;
struct V_91 V_92 ;
F_35 ( V_2 ) ;
V_90 = F_23 ( V_2 , V_44 ) ;
if ( V_90 < 0 )
goto exit;
V_90 = F_54 ( V_2 , & V_92 ) ;
if ( V_90 < 0 )
goto V_93;
V_2 -> V_94 = F_52 ( V_2 , V_92 . V_78 ,
V_92 . V_95 . V_79 ,
V_92 . V_95 . V_96 [ 0 ] ,
V_92 . V_95 . V_96 [ 1 ] ) ;
V_93:
F_23 ( V_2 , V_47 ) ;
exit:
F_39 ( V_2 ) ;
return V_90 ;
}
bool F_55 ( struct V_1 * V_2 )
{
return V_2 -> V_97 == V_98 ||
V_2 -> V_97 == V_99 ;
}
bool F_56 ( struct V_1 * V_2 )
{
return V_2 -> V_97 == V_99 ;
}
bool F_57 ( struct V_1 * V_2 )
{
return F_56 ( V_2 ) &&
( V_2 -> V_100 == V_101 ||
V_2 -> V_100 == V_102 ) ;
}
bool F_58 ( struct V_1 * V_2 )
{
return F_56 ( V_2 ) &&
( V_2 -> V_100 == V_103 ||
V_2 -> V_100 == V_104 ) ;
}
bool F_59 ( struct V_1 * V_2 )
{
return F_55 ( V_2 ) &&
( V_2 -> V_29 . V_78 == V_87 ) ;
}
bool F_60 ( struct V_1 * V_2 )
{
return V_2 -> V_41 == V_44 ;
}
static int F_61 ( struct V_25 * V_4 ,
const struct V_105 * V_106 )
{
int V_90 ;
struct V_1 * V_2 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
int V_111 ;
V_2 = F_62 ( & V_4 -> V_5 , sizeof( * V_2 ) , V_112 ) ;
if ( ! V_2 ) {
F_4 ( & V_4 -> V_5 ,
L_22 ) ;
return - V_113 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_31 = F_63 ( V_2 ) ;
if ( F_64 ( V_2 -> V_31 ) ) {
V_90 = F_65 ( V_2 -> V_31 ) ;
F_4 ( & V_4 -> V_5 ,
L_23 ,
V_90 ) ;
return V_90 ;
}
F_66 ( V_4 , V_2 ) ;
F_17 ( & V_2 -> V_28 , 0 ) ;
V_2 -> V_41 = V_47 ;
V_108 = F_67 ( & V_4 -> V_5 ) ;
if ( V_108 ) {
memcpy ( & V_2 -> V_29 ,
& V_108 -> V_29 ,
sizeof( V_2 -> V_29 ) ) ;
V_2 -> V_26 = - 1 ;
if ( F_13 ( V_108 -> V_26 ) ) {
V_90 = F_68 ( V_108 -> V_26 , L_24 ) ;
if ( V_90 ) {
F_4 ( & V_4 -> V_5 ,
L_25 , V_90 ) ;
return V_90 ;
}
V_2 -> V_26 = V_108 -> V_26 ;
F_69 ( V_2 -> V_26 , 0 ) ;
}
V_2 -> V_100 = V_108 -> V_100 ;
memcpy ( & V_2 -> V_6 , & V_108 -> V_6 ,
sizeof( struct V_114 ) ) ;
} else {
F_4 ( & V_4 -> V_5 , L_26 ) ;
return - V_43 ;
}
V_2 -> V_45 [ 0 ] . V_115 = L_27 ;
V_2 -> V_45 [ 1 ] . V_115 = L_28 ;
V_2 -> V_45 [ 2 ] . V_115 = L_29 ;
V_2 -> V_45 [ 3 ] . V_115 = L_30 ;
V_90 = F_70 ( & V_4 -> V_5 ,
F_25 ( V_2 -> V_45 ) ,
V_2 -> V_45 ) ;
if ( V_90 ) {
F_4 ( & V_4 -> V_5 , L_31 ) ;
goto V_116;
}
F_71 ( & V_2 -> V_117 ) ;
F_72 ( & V_2 -> V_62 ) ;
F_72 ( & V_2 -> V_64 ) ;
V_90 = F_73 ( & V_2 -> V_58 ,
V_118 *
sizeof( struct V_119 ) ,
V_112 ) ;
if ( V_90 ) {
F_4 ( & V_4 -> V_5 , L_32 ) ;
goto V_116;
}
F_71 ( & V_2 -> V_48 ) ;
F_72 ( & V_2 -> V_60 ) ;
F_74 ( & V_2 -> V_50 , F_33 ) ;
if ( V_4 -> V_27 ) {
V_90 = F_75 ( & V_4 -> V_5 ,
V_4 -> V_27 , NULL ,
F_51 ,
V_120 |
V_121 ,
V_4 -> V_122 , V_2 ) ;
if ( V_90 < 0 ) {
F_4 ( & V_4 -> V_5 , L_33 ,
V_4 -> V_27 ) ;
goto V_123;
}
V_30 ( V_4 -> V_27 ) ;
F_2 ( & V_4 -> V_5 , L_34 ) ;
V_2 -> V_124 = 20 ;
} else {
F_76 ( & V_2 -> V_22 ,
F_48 ) ;
F_41 ( & V_4 -> V_5 ,
L_35 ) ;
V_2 -> V_124 = 5 ;
}
V_2 -> V_97 = V_106 -> V_125 ;
V_90 = F_53 ( V_2 ) ;
if ( V_90 < 0 ) {
V_90 = - V_36 ;
goto V_123;
}
V_111 = 0 ;
V_110 = & V_2 -> V_126 [ V_127 ] ;
V_110 -> V_122 = L_36 ;
V_111 ++ ;
#ifdef F_77
if ( ( V_2 -> V_97 == V_98 ||
V_2 -> V_97 == V_99 ) &&
V_2 -> V_6 . V_7 == V_128 &&
V_2 -> V_6 . V_8 == V_129 &&
V_2 -> V_6 . V_9 == V_130 &&
V_2 -> V_6 . V_10 == V_131 ) {
V_110 = & V_2 -> V_126 [ V_132 ] ;
V_110 -> V_122 = L_37 ;
V_111 ++ ;
}
#endif
V_90 = F_78 ( & V_4 -> V_5 ,
( V_4 -> V_133 -> V_134 << 8 ) + V_4 -> V_135 ,
V_2 -> V_126 , V_111 ,
NULL , 0 , NULL ) ;
if ( ! V_90 )
return 0 ;
V_123:
F_79 ( & V_2 -> V_58 ) ;
V_116:
if ( F_13 ( V_2 -> V_26 ) )
F_80 ( V_2 -> V_26 ) ;
return V_90 ;
}
static int F_81 ( struct V_25 * V_4 )
{
struct V_1 * V_2 = F_82 ( V_4 ) ;
F_40 ( V_2 ) ;
F_83 ( & V_4 -> V_5 ) ;
if ( V_4 -> V_27 )
V_30 ( V_4 -> V_27 ) ;
else
F_20 ( & V_2 -> V_22 ) ;
F_79 ( & V_2 -> V_58 ) ;
if ( F_13 ( V_2 -> V_26 ) )
F_80 ( V_2 -> V_26 ) ;
return 0 ;
}
