static inline void F_1 ( const T_1 V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_3 . V_4 + V_1 ) ;
}
static inline T_2 F_3 ( const T_1 V_1 )
{
return F_4 ( V_3 . V_4 + V_1 ) ;
}
static T_2 F_5 ( enum V_5 V_6 , enum V_7 V_8 )
{
const struct V_9 V_10 = V_11 [ V_6 ] . V_12 [ V_8 ] ;
return F_6 ( V_10 . V_13 , V_10 . V_14 , V_10 . V_15 ) ;
}
static void F_7 ( enum V_5 V_6 ,
enum V_7 V_8 , int V_2 ) {
const struct V_9 V_10 = V_11 [ V_6 ] . V_12 [ V_8 ] ;
const bool V_16 = V_10 . V_13 == V_17 || V_10 . V_13 == V_18 ;
unsigned long V_19 ;
if ( V_16 )
F_8 ( & V_3 . V_20 , V_19 ) ;
F_9 ( V_10 . V_13 , V_2 , V_10 . V_14 , V_10 . V_15 ) ;
if ( V_16 )
F_10 ( & V_3 . V_20 , V_19 ) ;
}
static void F_11 ( void )
{
int V_21 , V_22 ;
F_12 ( L_1 ) ;
F_13 ( V_23 ) ;
F_13 ( V_24 ) ;
F_13 ( V_25 ) ;
F_13 ( V_26 ) ;
if ( F_14 ( V_27 ) ||
F_14 ( V_28 ) )
F_13 ( V_29 ) ;
if ( F_14 ( V_30 ) ) {
F_13 ( V_31 ) ;
F_13 ( V_32 ) ;
}
if ( F_14 ( V_33 ) ) {
F_13 ( V_34 ) ;
F_13 ( V_35 ) ;
}
for ( V_21 = 0 ; V_21 < F_15 () ; V_21 ++ ) {
F_13 ( F_16 ( V_21 ) ) ;
F_13 ( F_17 ( V_21 ) ) ;
F_13 ( F_18 ( V_21 ) ) ;
if ( V_21 == V_36 )
continue;
F_13 ( F_19 ( V_21 ) ) ;
F_13 ( F_20 ( V_21 ) ) ;
F_13 ( F_21 ( V_21 ) ) ;
F_13 ( F_22 ( V_21 ) ) ;
F_13 ( F_23 ( V_21 ) ) ;
F_13 ( F_24 ( V_21 ) ) ;
F_13 ( F_25 ( V_21 ) ) ;
if ( F_14 ( V_37 ) ) {
F_13 ( F_26 ( V_21 ) ) ;
F_13 ( F_27 ( V_21 ) ) ;
F_13 ( F_28 ( V_21 ) ) ;
}
}
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ ) {
F_13 ( F_30 ( V_21 ) ) ;
F_13 ( F_31 ( V_21 ) ) ;
F_13 ( F_32 ( V_21 ) ) ;
F_13 ( F_33 ( V_21 ) ) ;
F_13 ( F_34 ( V_21 ) ) ;
F_13 ( F_35 ( V_21 ) ) ;
F_13 ( F_36 ( V_21 ) ) ;
F_13 ( F_37 ( V_21 ) ) ;
if ( F_14 ( V_38 ) )
F_13 ( F_38 ( V_21 ) ) ;
if ( V_21 == V_39 ) {
F_13 ( F_39 ( V_21 ) ) ;
F_13 ( F_40 ( V_21 ) ) ;
continue;
}
F_13 ( F_41 ( V_21 ) ) ;
F_13 ( F_42 ( V_21 ) ) ;
F_13 ( F_43 ( V_21 ) ) ;
F_13 ( F_44 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_45 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_46 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_13 ( F_47 ( V_21 , V_22 ) ) ;
if ( F_14 ( V_40 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_48 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_41 ) ) {
F_13 ( F_49 ( V_21 ) ) ;
F_13 ( F_50 ( V_21 ) ) ;
F_13 ( F_51 ( V_21 ) ) ;
F_13 ( F_52 ( V_21 ) ) ;
F_13 ( F_53 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_54 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_55 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_56 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_42 ) )
F_13 ( F_57 ( V_21 ) ) ;
}
if ( F_14 ( V_43 ) )
F_13 ( V_44 ) ;
V_3 . V_45 = true ;
F_12 ( L_2 ) ;
}
static void F_58 ( void )
{
int V_21 , V_22 ;
F_12 ( L_3 ) ;
if ( ! V_3 . V_45 )
return;
F_59 ( V_25 ) ;
F_59 ( V_26 ) ;
if ( F_14 ( V_27 ) ||
F_14 ( V_28 ) )
F_59 ( V_29 ) ;
if ( F_14 ( V_30 ) )
F_59 ( V_32 ) ;
if ( F_14 ( V_33 ) )
F_59 ( V_35 ) ;
for ( V_21 = 0 ; V_21 < F_15 () ; V_21 ++ ) {
F_59 ( F_16 ( V_21 ) ) ;
F_59 ( F_17 ( V_21 ) ) ;
F_59 ( F_18 ( V_21 ) ) ;
if ( V_21 == V_36 )
continue;
F_59 ( F_19 ( V_21 ) ) ;
F_59 ( F_20 ( V_21 ) ) ;
F_59 ( F_21 ( V_21 ) ) ;
F_59 ( F_22 ( V_21 ) ) ;
F_59 ( F_23 ( V_21 ) ) ;
F_59 ( F_24 ( V_21 ) ) ;
F_59 ( F_25 ( V_21 ) ) ;
if ( F_14 ( V_37 ) ) {
F_59 ( F_26 ( V_21 ) ) ;
F_59 ( F_27 ( V_21 ) ) ;
F_59 ( F_28 ( V_21 ) ) ;
}
}
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ ) {
F_59 ( F_30 ( V_21 ) ) ;
F_59 ( F_31 ( V_21 ) ) ;
F_59 ( F_32 ( V_21 ) ) ;
F_59 ( F_33 ( V_21 ) ) ;
F_59 ( F_34 ( V_21 ) ) ;
F_59 ( F_35 ( V_21 ) ) ;
F_59 ( F_36 ( V_21 ) ) ;
F_59 ( F_37 ( V_21 ) ) ;
if ( F_14 ( V_38 ) )
F_59 ( F_38 ( V_21 ) ) ;
if ( V_21 == V_39 ) {
F_59 ( F_39 ( V_21 ) ) ;
F_59 ( F_40 ( V_21 ) ) ;
continue;
}
F_59 ( F_41 ( V_21 ) ) ;
F_59 ( F_42 ( V_21 ) ) ;
F_59 ( F_43 ( V_21 ) ) ;
F_59 ( F_44 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_45 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_46 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_59 ( F_47 ( V_21 , V_22 ) ) ;
if ( F_14 ( V_40 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_48 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_41 ) ) {
F_59 ( F_49 ( V_21 ) ) ;
F_59 ( F_50 ( V_21 ) ) ;
F_59 ( F_51 ( V_21 ) ) ;
F_59 ( F_52 ( V_21 ) ) ;
F_59 ( F_53 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_54 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_55 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_56 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_42 ) )
F_59 ( F_57 ( V_21 ) ) ;
}
if ( F_14 ( V_43 ) )
F_59 ( V_44 ) ;
F_59 ( V_24 ) ;
if ( F_14 ( V_30 ) )
F_59 ( V_31 ) ;
if ( F_14 ( V_33 ) )
F_59 ( V_34 ) ;
F_60 ( V_46 ) ;
F_59 ( V_23 ) ;
F_12 ( L_4 ) ;
}
int F_61 ( void )
{
int V_47 ;
F_12 ( L_5 ) ;
V_47 = F_62 ( & V_3 . V_48 -> V_49 ) ;
F_63 ( V_47 < 0 ) ;
return V_47 < 0 ? V_47 : 0 ;
}
void F_64 ( void )
{
int V_47 ;
F_12 ( L_6 ) ;
V_47 = F_65 ( & V_3 . V_48 -> V_49 ) ;
F_63 ( V_47 < 0 && V_47 != - V_50 ) ;
}
T_2 F_66 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_51 ;
}
T_2 F_67 ( enum V_5 V_6 )
{
if ( V_6 == V_36 && V_3 . V_52 -> V_53 )
return 0 ;
return V_11 [ V_6 ] . V_54 ;
}
T_2 F_68 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_55 ;
}
T_2 F_69 ( void )
{
return V_56 ;
}
bool F_70 ( enum V_5 V_6 )
{
return F_5 ( V_6 , V_57 ) == 1 ;
}
void F_71 ( enum V_5 V_6 )
{
F_63 ( ! F_72 ( V_6 ) ) ;
F_63 ( F_70 ( V_6 ) ) ;
F_12 ( L_7 , V_11 [ V_6 ] . V_58 ) ;
F_7 ( V_6 , V_57 , 1 ) ;
}
bool F_73 ( void )
{
return F_6 ( V_59 , 6 , 6 ) == 1 ;
}
void F_74 ( void )
{
enum V_60 V_61 = V_62 ;
bool V_63 , V_64 ;
V_63 = F_6 ( F_75 ( V_61 ) , 0 , 0 ) == 1 ;
if ( ! V_63 )
return;
V_64 = F_6 ( V_59 , 6 , 6 ) == 1 ;
if ( V_64 ) {
F_76 ( L_8 ) ;
return;
}
F_9 ( V_59 , 1 , 6 , 6 ) ;
}
static void F_77 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_1 ( F_78 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_79 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_1 ( F_80 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_81 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_1 ( F_82 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_83 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_84 ( V_61 == V_39 ) ;
F_1 ( F_85 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_86 ( enum V_60 V_61 , int V_13 ,
T_2 V_65 )
{
F_84 ( V_61 == V_39 ) ;
F_1 ( F_87 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_88 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_84 ( V_61 == V_39 ) ;
F_1 ( F_89 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_90 ( enum V_60 V_61 , int V_66 ,
int V_67 , int V_68 ,
enum V_69 V_70 )
{
const struct V_71 * V_72 , * V_73 ;
int V_21 ;
V_72 = F_91 ( V_66 , true ) ;
V_73 = F_91 ( V_67 , V_68 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
T_2 V_74 , V_75 ;
V_74 = F_92 ( V_72 [ V_21 ] . V_76 , 7 , 0 )
| F_92 ( V_72 [ V_21 ] . V_77 , 15 , 8 )
| F_92 ( V_72 [ V_21 ] . V_78 , 23 , 16 )
| F_92 ( V_72 [ V_21 ] . V_79 , 31 , 24 ) ;
V_75 = F_92 ( V_72 [ V_21 ] . V_80 , 7 , 0 )
| F_92 ( V_73 [ V_21 ] . V_77 , 15 , 8 )
| F_92 ( V_73 [ V_21 ] . V_78 , 23 , 16 )
| F_92 ( V_73 [ V_21 ] . V_79 , 31 , 24 ) ;
if ( V_70 == V_81 ) {
F_77 ( V_61 , V_21 , V_74 ) ;
F_79 ( V_61 , V_21 , V_75 ) ;
} else {
F_83 ( V_61 , V_21 , V_74 ) ;
F_86 ( V_61 , V_21 , V_75 ) ;
}
}
if ( V_68 ) {
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
T_2 V_82 ;
V_82 = F_92 ( V_73 [ V_21 ] . V_76 , 7 , 0 )
| F_92 ( V_73 [ V_21 ] . V_80 , 15 , 8 ) ;
if ( V_70 == V_81 )
F_81 ( V_61 , V_21 , V_82 ) ;
else
F_88 ( V_61 , V_21 , V_82 ) ;
}
}
}
static void F_93 ( enum V_60 V_61 ,
const struct V_83 * V_84 )
{
#define F_94 ( T_3 , T_4 ) (FLD_VAL(x, 26, 16) | FLD_VAL(y, 10, 0))
F_1 ( F_95 ( V_61 , 0 ) , F_94 ( V_84 -> V_85 , V_84 -> V_86 ) ) ;
F_1 ( F_95 ( V_61 , 1 ) , F_94 ( V_84 -> V_87 , V_84 -> V_88 ) ) ;
F_1 ( F_95 ( V_61 , 2 ) , F_94 ( V_84 -> V_89 , V_84 -> V_90 ) ) ;
F_1 ( F_95 ( V_61 , 3 ) , F_94 ( V_84 -> V_91 , V_84 -> V_92 ) ) ;
F_1 ( F_95 ( V_61 , 4 ) , F_94 ( 0 , V_84 -> V_93 ) ) ;
F_9 ( F_75 ( V_61 ) , V_84 -> V_94 , 11 , 11 ) ;
#undef F_94
}
static void F_96 ( void )
{
int V_21 ;
int V_95 = F_29 () ;
const struct V_83 V_96 = {
298 , 409 , 0 , 298 , - 208 , - 100 , 298 , 0 , 517 , 0 ,
} ;
const struct V_83 V_97 = {
66 , 129 , 25 , 112 , - 94 , - 18 , - 38 , - 74 , 112 , 0 ,
} ;
for ( V_21 = 1 ; V_21 < V_95 ; V_21 ++ )
F_93 ( V_21 , & V_96 ) ;
if ( V_3 . V_52 -> V_98 )
F_93 ( V_62 , & V_97 ) ;
}
static void F_97 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_98 ( V_61 ) , V_99 ) ;
}
static void F_99 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_100 ( V_61 ) , V_99 ) ;
}
static void F_101 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_102 ( V_61 ) , V_99 ) ;
}
static void F_103 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_104 ( V_61 ) , V_99 ) ;
}
static void F_105 ( enum V_60 V_61 ,
enum V_100 V_101 , int T_3 , int T_4 )
{
T_2 V_2 ;
if ( ( V_101 & V_102 ) == 0 )
return;
V_2 = F_92 ( T_4 , 26 , 16 ) | F_92 ( T_3 , 10 , 0 ) ;
F_1 ( F_106 ( V_61 ) , V_2 ) ;
}
static void F_107 ( enum V_60 V_61 , int V_103 ,
int V_104 )
{
T_2 V_2 = F_92 ( V_104 - 1 , 26 , 16 ) | F_92 ( V_103 - 1 , 10 , 0 ) ;
if ( V_61 == V_39 || V_61 == V_62 )
F_1 ( F_108 ( V_61 ) , V_2 ) ;
else
F_1 ( F_109 ( V_61 ) , V_2 ) ;
}
static void F_110 ( enum V_60 V_61 , int V_103 ,
int V_104 )
{
T_2 V_2 ;
F_84 ( V_61 == V_39 ) ;
V_2 = F_92 ( V_104 - 1 , 26 , 16 ) | F_92 ( V_103 - 1 , 10 , 0 ) ;
if ( V_61 == V_62 )
F_1 ( F_109 ( V_61 ) , V_2 ) ;
else
F_1 ( F_108 ( V_61 ) , V_2 ) ;
}
static void F_111 ( enum V_60 V_61 ,
enum V_100 V_101 , T_5 V_105 )
{
if ( ( V_101 & V_106 ) == 0 )
return;
F_9 ( F_75 ( V_61 ) , V_105 , 27 , 26 ) ;
}
static void F_112 ( void )
{
int V_21 ;
if ( ! F_14 ( V_28 ) )
return;
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ )
F_9 ( F_75 ( V_21 ) , 1 , 25 , 25 ) ;
}
static void F_113 ( enum V_60 V_61 ,
enum V_100 V_101 , bool V_63 )
{
if ( ( V_101 & V_107 ) == 0 )
return;
F_9 ( F_75 ( V_61 ) , V_63 ? 1 : 0 , 28 , 28 ) ;
}
static void F_114 ( enum V_60 V_61 ,
enum V_100 V_101 , T_5 V_108 )
{
static const unsigned V_109 [] = { 0 , 8 , 16 , 24 , } ;
int V_110 ;
if ( ( V_101 & V_111 ) == 0 )
return;
V_110 = V_109 [ V_61 ] ;
F_9 ( V_112 , V_108 , V_110 + 7 , V_110 ) ;
}
static void F_115 ( enum V_60 V_61 , T_6 V_113 )
{
F_1 ( F_116 ( V_61 ) , V_113 ) ;
}
static void F_117 ( enum V_60 V_61 , T_6 V_113 )
{
F_1 ( F_118 ( V_61 ) , V_113 ) ;
}
static void F_119 ( enum V_60 V_61 ,
enum V_114 V_115 )
{
T_2 V_116 = 0 ;
if ( V_61 != V_39 ) {
switch ( V_115 ) {
case V_117 :
V_116 = 0x0 ; break;
case V_118 :
V_116 = 0x1 ; break;
case V_119 :
V_116 = 0x2 ; break;
case V_120 :
V_116 = 0x4 ; break;
case V_121 :
V_116 = 0x5 ; break;
case V_122 :
V_116 = 0x6 ; break;
case V_123 :
V_116 = 0x7 ; break;
case V_124 :
V_116 = 0x8 ; break;
case V_125 :
V_116 = 0x9 ; break;
case V_126 :
V_116 = 0xa ; break;
case V_127 :
V_116 = 0xb ; break;
case V_128 :
V_116 = 0xc ; break;
case V_129 :
V_116 = 0xd ; break;
case V_130 :
V_116 = 0xe ; break;
case V_131 :
V_116 = 0xf ; break;
default:
F_120 () ; return;
}
} else {
switch ( V_115 ) {
case V_132 :
V_116 = 0x0 ; break;
case V_133 :
V_116 = 0x1 ; break;
case V_134 :
V_116 = 0x2 ; break;
case V_135 :
V_116 = 0x3 ; break;
case V_120 :
V_116 = 0x4 ; break;
case V_121 :
V_116 = 0x5 ; break;
case V_122 :
V_116 = 0x6 ; break;
case V_123 :
V_116 = 0x7 ; break;
case V_124 :
V_116 = 0x8 ; break;
case V_125 :
V_116 = 0x9 ; break;
case V_118 :
V_116 = 0xa ; break;
case V_119 :
V_116 = 0xb ; break;
case V_128 :
V_116 = 0xc ; break;
case V_129 :
V_116 = 0xd ; break;
case V_130 :
V_116 = 0xe ; break;
case V_131 :
V_116 = 0xf ; break;
default:
F_120 () ; return;
}
}
F_9 ( F_75 ( V_61 ) , V_116 , 4 , 1 ) ;
}
static void F_121 ( enum V_60 V_61 ,
enum V_136 V_137 )
{
if ( F_14 ( V_138 ) == 0 )
return;
if ( V_137 == V_139 )
F_9 ( F_75 ( V_61 ) , 1 , 29 , 29 ) ;
else
F_9 ( F_75 ( V_61 ) , 0 , 29 , 29 ) ;
}
void F_122 ( enum V_60 V_61 , enum V_5 V_6 )
{
int V_110 ;
T_2 V_2 ;
int V_140 = 0 , V_141 = 0 ;
switch ( V_61 ) {
case V_39 :
V_110 = 8 ;
break;
case V_142 :
case V_143 :
case V_144 :
V_110 = 16 ;
break;
default:
F_120 () ;
return;
}
V_2 = F_3 ( F_75 ( V_61 ) ) ;
if ( F_14 ( V_30 ) ) {
switch ( V_6 ) {
case V_145 :
V_140 = 0 ;
V_141 = 0 ;
break;
case V_36 :
V_140 = 1 ;
V_141 = 0 ;
break;
case V_146 :
V_140 = 0 ;
V_141 = 1 ;
break;
case V_147 :
if ( F_14 ( V_33 ) ) {
V_140 = 0 ;
V_141 = 2 ;
} else {
F_120 () ;
return;
}
break;
case V_148 :
V_140 = 0 ;
V_141 = 3 ;
break;
default:
F_120 () ;
return;
}
V_2 = F_123 ( V_2 , V_140 , V_110 , V_110 ) ;
V_2 = F_123 ( V_2 , V_141 , 31 , 30 ) ;
} else {
V_2 = F_123 ( V_2 , V_6 , V_110 , V_110 ) ;
}
F_1 ( F_75 ( V_61 ) , V_2 ) ;
}
static enum V_5 F_124 ( enum V_60 V_61 )
{
int V_110 ;
T_2 V_2 ;
switch ( V_61 ) {
case V_39 :
V_110 = 8 ;
break;
case V_142 :
case V_143 :
case V_144 :
V_110 = 16 ;
break;
default:
F_120 () ;
return 0 ;
}
V_2 = F_3 ( F_75 ( V_61 ) ) ;
if ( F_125 ( V_2 , V_110 , V_110 ) == 1 )
return V_36 ;
if ( ! F_14 ( V_30 ) )
return V_145 ;
switch ( F_125 ( V_2 , 31 , 30 ) ) {
case 0 :
default:
return V_145 ;
case 1 :
return V_146 ;
case 2 :
return V_147 ;
case 3 :
return V_148 ;
}
}
void F_126 ( enum V_149 V_6 )
{
enum V_60 V_61 = V_62 ;
F_9 ( F_75 ( V_61 ) , V_6 , 18 , 16 ) ;
}
static void F_127 ( enum V_60 V_61 ,
enum V_150 V_151 )
{
static const unsigned V_109 [] = { 6 , 14 , 14 , 14 , 14 , } ;
int V_110 ;
V_110 = V_109 [ V_61 ] ;
F_9 ( F_75 ( V_61 ) , V_151 , V_110 + 1 , V_110 ) ;
}
static void F_128 ( void )
{
int V_21 ;
const int V_151 = V_152 ;
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 )
F_127 ( V_21 , V_151 ) ;
if ( V_3 . V_52 -> V_98 )
F_127 ( V_62 , V_151 ) ;
}
static T_2 F_129 ( enum V_60 V_61 )
{
unsigned V_153 = F_130 () ;
return V_153 * 8 ;
}
void F_131 ( bool V_63 )
{
if ( V_63 ) {
F_132 ( L_9 ) ;
return;
}
F_9 ( V_18 , V_63 , 9 , 9 ) ;
}
static void F_133 ( enum V_5 V_6 , bool V_63 )
{
if ( V_6 == V_36 )
return;
F_7 ( V_6 , V_154 , V_63 ) ;
}
static void F_134 ( enum V_5 V_6 ,
const struct V_155 * V_156 )
{
T_2 V_157 , V_158 , V_159 ;
if ( ! F_135 ( V_6 ) )
return;
V_157 = F_92 ( V_156 -> V_160 , 31 , 22 ) | F_92 ( V_156 -> V_161 , 20 , 11 ) |
F_92 ( V_156 -> V_162 , 9 , 0 ) ;
V_158 = F_92 ( V_156 -> V_163 , 31 , 22 ) | F_92 ( V_156 -> V_164 , 20 , 11 ) |
F_92 ( V_156 -> V_165 , 9 , 0 ) ;
V_159 = F_92 ( V_156 -> V_166 , 31 , 22 ) | F_92 ( V_156 -> V_167 , 20 , 11 ) |
F_92 ( V_156 -> V_168 , 9 , 0 ) ;
F_1 ( F_136 ( V_6 ) , V_157 ) ;
F_1 ( F_137 ( V_6 ) , V_158 ) ;
F_1 ( F_138 ( V_6 ) , V_159 ) ;
}
static void F_139 ( enum V_60 V_61 , bool V_63 )
{
T_2 V_2 ;
F_84 ( V_61 == V_39 ) ;
V_2 = F_3 ( F_75 ( V_61 ) ) ;
V_2 = F_123 ( V_2 , V_63 , 9 , 9 ) ;
F_1 ( F_75 ( V_61 ) , V_2 ) ;
}
static void F_140 ( enum V_60 V_61 ,
enum V_100 V_101 , bool V_63 )
{
static const unsigned V_109 [] = { 5 , 10 , 10 , 10 } ;
int V_110 ;
if ( ( V_101 & V_169 ) == 0 )
return;
V_110 = V_109 [ V_61 ] ;
F_9 ( F_75 ( V_61 ) , V_63 , V_110 , V_110 ) ;
}
static void F_141 ( enum V_5 V_6 , T_1 V_103 ,
T_1 V_104 )
{
T_2 V_2 ;
V_2 = F_92 ( V_104 - 1 , V_3 . V_52 -> V_170 , 16 ) |
F_92 ( V_103 - 1 , V_3 . V_52 -> V_171 , 0 ) ;
F_1 ( F_142 ( V_6 ) , V_2 ) ;
}
static void F_143 ( void )
{
T_2 V_172 ;
int V_173 ;
T_5 V_174 , V_175 ;
T_2 V_153 ;
int V_21 ;
V_153 = F_144 () ;
F_145 ( V_176 , & V_174 , & V_175 ) ;
for ( V_173 = 0 ; V_173 < V_3 . V_52 -> V_177 ; ++ V_173 ) {
V_172 = F_6 ( F_146 ( V_173 ) , V_174 , V_175 ) ;
V_172 *= V_153 ;
V_3 . V_178 [ V_173 ] = V_172 ;
V_3 . V_179 [ V_173 ] = V_173 ;
}
if ( V_3 . V_52 -> V_180 ) {
T_2 V_82 ;
V_82 = F_3 ( V_181 ) ;
V_82 = F_123 ( V_82 , 4 , 2 , 0 ) ;
V_82 = F_123 ( V_82 , 4 , 5 , 3 ) ;
V_82 = F_123 ( V_82 , 0 , 26 , 24 ) ;
V_82 = F_123 ( V_82 , 0 , 29 , 27 ) ;
F_1 ( V_181 , V_82 ) ;
V_3 . V_179 [ V_39 ] = V_62 ;
V_3 . V_179 [ V_62 ] = V_39 ;
}
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 ) {
T_2 V_15 , V_14 ;
const bool V_182 = false ;
const bool V_183 = false ;
F_147 ( V_21 , & V_15 , & V_14 ,
V_182 , V_183 ) ;
F_148 ( V_21 , V_15 , V_14 ) ;
}
if ( V_3 . V_52 -> V_98 ) {
T_2 V_15 , V_14 ;
const bool V_182 = false ;
const bool V_183 = false ;
F_147 ( V_62 , & V_15 , & V_14 ,
V_182 , V_183 ) ;
F_148 ( V_62 , V_15 , V_14 ) ;
}
}
static T_2 F_149 ( enum V_60 V_61 )
{
int V_173 ;
T_2 V_172 = 0 ;
for ( V_173 = 0 ; V_173 < V_3 . V_52 -> V_177 ; ++ V_173 ) {
if ( V_3 . V_179 [ V_173 ] == V_61 )
V_172 += V_3 . V_178 [ V_173 ] ;
}
return V_172 ;
}
void F_148 ( enum V_60 V_61 , T_2 V_15 , T_2 V_14 )
{
T_5 V_184 , V_185 , V_186 , V_187 ;
T_2 V_153 ;
V_153 = F_144 () ;
F_63 ( V_15 % V_153 != 0 ) ;
F_63 ( V_14 % V_153 != 0 ) ;
V_15 /= V_153 ;
V_14 /= V_153 ;
F_145 ( V_188 , & V_184 , & V_185 ) ;
F_145 ( V_189 , & V_186 , & V_187 ) ;
F_12 ( L_10 ,
V_61 ,
F_6 ( F_150 ( V_61 ) ,
V_186 , V_187 ) * V_153 ,
F_6 ( F_150 ( V_61 ) ,
V_184 , V_185 ) * V_153 ,
V_15 * V_153 , V_14 * V_153 ) ;
F_1 ( F_150 ( V_61 ) ,
F_92 ( V_14 , V_184 , V_185 ) |
F_92 ( V_15 , V_186 , V_187 ) ) ;
if ( F_14 ( V_38 ) && V_3 . V_52 -> V_190 &&
V_61 != V_62 )
F_1 ( F_151 ( V_61 ) , F_152 ( V_14 , 0xfffu ) ) ;
}
void F_153 ( bool V_63 )
{
if ( ! F_14 ( V_191 ) ) {
F_63 ( V_63 ) ;
return;
}
F_12 ( L_11 , V_63 ? L_12 : L_13 ) ;
F_9 ( V_18 , V_63 ? 1 : 0 , 14 , 14 ) ;
}
void F_147 ( enum V_60 V_61 ,
T_2 * V_192 , T_2 * V_193 , bool V_182 ,
bool V_183 )
{
unsigned V_194 = F_144 () ;
unsigned V_195 , V_196 , V_151 ;
int V_21 ;
V_151 = F_129 ( V_61 ) ;
V_195 = F_149 ( V_61 ) ;
if ( V_182 ) {
V_196 = 0 ;
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 )
V_196 += F_149 ( V_21 ) ;
} else {
V_196 = V_195 ;
}
if ( V_183 && F_14 ( V_197 ) ) {
* V_192 = V_195 - V_151 * 2 ;
* V_193 = V_196 - V_151 ;
} else if ( V_61 == V_62 ) {
* V_192 = 0 ;
* V_193 = V_151 ;
} else {
* V_192 = V_195 - V_151 ;
* V_193 = V_196 - V_194 ;
}
}
static void F_154 ( enum V_60 V_61 , bool V_63 )
{
int V_198 ;
if ( V_61 == V_39 )
V_198 = 14 ;
else
V_198 = 23 ;
F_9 ( F_75 ( V_61 ) , V_63 , V_198 , V_198 ) ;
}
static void F_155 ( enum V_60 V_61 ,
int V_15 , int V_14 )
{
F_1 ( F_156 ( V_61 ) ,
F_92 ( V_14 , 31 , 16 ) | F_92 ( V_15 , 15 , 0 ) ) ;
}
static void F_157 ( void )
{
int V_21 ;
F_1 ( V_199 ,
( 1 << 0 ) |
( 0 << 2 ) ) ;
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 ) {
T_2 V_172 = F_149 ( V_21 ) ;
T_2 V_153 = F_144 () ;
T_2 V_15 , V_14 ;
F_154 ( V_21 , true ) ;
V_15 = V_172 * 4 / 8 / V_153 ;
V_14 = V_172 * 5 / 8 / V_153 ;
F_155 ( V_21 , V_15 , V_14 ) ;
}
if ( V_3 . V_52 -> V_98 ) {
T_2 V_172 = F_149 ( V_62 ) ;
T_2 V_153 = F_144 () ;
T_2 V_15 , V_14 ;
F_154 ( V_62 , true ) ;
V_15 = V_172 * 4 / 8 / V_153 ;
V_14 = V_172 * 5 / 8 / V_153 ;
F_155 ( V_62 , V_15 , V_14 ) ;
}
}
static void F_158 ( enum V_60 V_61 ,
int V_200 , int V_201 ,
enum V_69 V_70 )
{
T_2 V_2 ;
if ( V_70 == V_81 ) {
T_5 V_202 , V_203 , V_204 , V_205 ;
F_145 ( V_206 ,
& V_202 , & V_203 ) ;
F_145 ( V_207 ,
& V_204 , & V_205 ) ;
V_2 = F_92 ( V_201 , V_204 , V_205 ) |
F_92 ( V_200 , V_202 , V_203 ) ;
F_1 ( F_159 ( V_61 ) , V_2 ) ;
} else {
V_2 = F_92 ( V_201 , 28 , 16 ) | F_92 ( V_200 , 12 , 0 ) ;
F_1 ( F_160 ( V_61 ) , V_2 ) ;
}
}
static void F_161 ( enum V_60 V_61 , int V_208 , int V_209 )
{
T_2 V_2 ;
T_5 V_210 , V_211 , V_212 , V_213 ;
F_145 ( V_214 , & V_210 , & V_211 ) ;
F_145 ( V_215 , & V_212 , & V_213 ) ;
V_2 = F_92 ( V_209 , V_212 , V_213 ) |
F_92 ( V_208 , V_210 , V_211 ) ;
F_1 ( F_162 ( V_61 ) , V_2 ) ;
}
static void F_163 ( enum V_60 V_61 , int V_208 , int V_209 )
{
T_2 V_2 ;
T_5 V_210 , V_211 , V_212 , V_213 ;
F_145 ( V_214 , & V_210 , & V_211 ) ;
F_145 ( V_215 , & V_212 , & V_213 ) ;
V_2 = F_92 ( V_209 , V_212 , V_213 ) |
F_92 ( V_208 , V_210 , V_211 ) ;
F_1 ( F_164 ( V_61 ) , V_2 ) ;
}
static void F_165 ( enum V_60 V_61 , int V_208 ,
int V_209 )
{
T_2 V_2 ;
V_2 = F_92 ( V_209 , 26 , 16 ) | F_92 ( V_208 , 10 , 0 ) ;
F_1 ( F_166 ( V_61 ) , V_2 ) ;
}
static void F_167 ( enum V_60 V_61 , int V_208 ,
int V_209 )
{
T_2 V_2 ;
V_2 = F_92 ( V_209 , 26 , 16 ) | F_92 ( V_208 , 10 , 0 ) ;
F_1 ( F_168 ( V_61 ) , V_2 ) ;
}
static void F_169 ( enum V_60 V_61 ,
T_1 V_216 , T_1 V_217 ,
T_1 V_218 , T_1 V_219 ,
bool V_68 , T_5 V_220 ,
enum V_69 V_70 )
{
int V_66 , V_67 ;
V_66 = 1024 * V_216 / V_218 ;
V_67 = 1024 * V_217 / V_219 ;
F_90 ( V_61 , V_66 , V_67 , V_68 ,
V_70 ) ;
F_158 ( V_61 , V_66 , V_67 , V_70 ) ;
}
static void F_170 ( enum V_60 V_61 ,
T_1 V_216 , T_1 V_217 , T_1 V_218 , T_1 V_219 ,
bool V_221 , enum V_114 V_115 , T_5 V_220 )
{
int V_222 , V_223 ;
int V_224 , V_225 ;
int V_226 , V_227 ;
int V_1 ;
struct V_228 {
T_7 V_229 , V_230 ;
T_7 V_231 , V_232 ;
T_7 V_233 , V_234 ;
T_7 V_235 , V_236 ;
};
const struct V_228 * V_237 ;
const struct V_228 * V_238 ;
static const struct V_228 V_239 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ 1 , 2 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ - 1 , 2 , - 1 , 2 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_228 V_240 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 3 , 4 , - 1 , 4 } ,
{ - 1 , 4 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 4 , - 3 , 4 } ,
{ - 3 , 4 , - 3 , 4 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_228 V_241 [ 4 ] = {
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , - 1 , 1 , 0 , 1 } ,
} ;
switch ( V_220 ) {
case V_242 :
V_1 = 0 ;
break;
case V_243 :
V_1 = 1 ;
break;
case V_244 :
V_1 = 2 ;
break;
case V_245 :
V_1 = 3 ;
break;
default:
F_120 () ;
return;
}
switch ( V_115 ) {
case V_117 :
if ( V_221 )
V_237 = V_240 ;
else
V_237 = V_239 ;
break;
case V_126 :
case V_127 :
V_237 = V_241 ;
break;
default:
F_120 () ;
return;
}
V_238 = & V_237 [ V_1 ] ;
V_226 = 1024 * V_216 / V_218 ;
V_227 = 1024 * V_217 / V_219 ;
V_222 = ( V_238 -> V_229 * V_226 / V_238 -> V_230 ) % 1024 ;
V_223 = ( V_238 -> V_231 * V_226 / V_238 -> V_232 ) % 1024 ;
V_224 = ( V_238 -> V_233 * V_227 / V_238 -> V_234 ) % 1024 ;
V_225 = ( V_238 -> V_235 * V_227 / V_238 -> V_236 ) % 1024 ;
F_165 ( V_61 , V_222 , V_224 ) ;
F_167 ( V_61 , V_223 , V_225 ) ;
}
static void F_171 ( enum V_60 V_61 ,
T_1 V_216 , T_1 V_217 ,
T_1 V_218 , T_1 V_219 ,
bool V_221 , bool V_68 ,
bool V_246 , enum V_114 V_115 ,
T_5 V_220 )
{
int V_247 = 0 ;
int V_248 = 0 ;
T_2 V_249 ;
F_169 ( V_61 , V_216 , V_217 ,
V_218 , V_219 , V_68 ,
V_220 , V_81 ) ;
V_249 = F_3 ( F_75 ( V_61 ) ) ;
V_249 &= ~ ( ( 0x3 << 5 ) | ( 0x1 << 21 ) ) ;
V_249 |= ( V_216 != V_218 ) ? ( 1 << 5 ) : 0 ;
V_249 |= ( V_217 != V_219 ) ? ( 1 << 6 ) : 0 ;
V_249 |= V_68 ? ( 1 << 21 ) : 0 ;
if ( F_14 ( V_250 ) ) {
V_249 &= ~ ( 0x3 << 7 ) ;
V_249 |= ( V_216 <= V_218 ) ? 0 : ( 1 << 7 ) ;
V_249 |= ( V_217 <= V_219 ) ? 0 : ( 1 << 8 ) ;
}
if ( F_14 ( V_251 ) ) {
V_249 &= ~ ( 0x1 << 22 ) ;
V_249 |= V_68 ? ( 1 << 22 ) : 0 ;
}
F_1 ( F_75 ( V_61 ) , V_249 ) ;
if ( V_221 && ! V_246 ) {
V_248 = 0 ;
V_247 = ( ( 1024 * V_217 / V_219 ) / 2 ) & 0x3ff ;
if ( V_247 >= 1024 / 2 ) {
V_248 = 1024 / 2 ;
V_247 -= V_248 ;
}
}
F_161 ( V_61 , 0 , V_247 ) ;
F_163 ( V_61 , 0 , V_248 ) ;
}
static void F_172 ( enum V_60 V_61 ,
T_1 V_216 , T_1 V_217 ,
T_1 V_218 , T_1 V_219 ,
bool V_221 , bool V_68 ,
bool V_246 , enum V_114 V_115 ,
T_5 V_220 )
{
int V_252 = V_218 != V_216 ;
int V_253 = V_219 != V_217 ;
bool V_254 = V_61 != V_62 ? true : false ;
if ( ! F_14 ( V_41 ) )
return;
if ( ( V_115 != V_126 &&
V_115 != V_127 &&
V_115 != V_117 ) ) {
if ( V_61 != V_62 )
F_9 ( F_173 ( V_61 ) , 0 , 8 , 8 ) ;
return;
}
F_170 ( V_61 , V_216 , V_217 , V_218 ,
V_219 , V_221 , V_115 , V_220 ) ;
switch ( V_115 ) {
case V_117 :
if ( V_254 ) {
V_217 >>= 1 ;
V_216 >>= 1 ;
} else {
V_217 <<= 1 ;
V_216 <<= 1 ;
}
break;
case V_126 :
case V_127 :
if ( V_220 == V_242 ||
V_220 == V_244 ) {
if ( V_254 )
V_216 >>= 1 ;
else
V_216 <<= 1 ;
}
if ( V_220 != V_242 )
V_252 = V_253 = true ;
break;
default:
F_120 () ;
return;
}
if ( V_218 != V_216 )
V_252 = true ;
if ( V_219 != V_217 )
V_253 = true ;
F_169 ( V_61 , V_216 , V_217 ,
V_218 , V_219 , V_68 ,
V_220 , V_255 ) ;
if ( V_61 != V_62 )
F_9 ( F_173 ( V_61 ) ,
( V_252 || V_253 ) ? 1 : 0 , 8 , 8 ) ;
F_9 ( F_75 ( V_61 ) , V_252 ? 1 : 0 , 5 , 5 ) ;
F_9 ( F_75 ( V_61 ) , V_253 ? 1 : 0 , 6 , 6 ) ;
}
static void F_174 ( enum V_60 V_61 ,
T_1 V_216 , T_1 V_217 ,
T_1 V_218 , T_1 V_219 ,
bool V_221 , bool V_68 ,
bool V_246 , enum V_114 V_115 ,
T_5 V_220 )
{
F_84 ( V_61 == V_39 ) ;
F_171 ( V_61 ,
V_216 , V_217 ,
V_218 , V_219 ,
V_221 , V_68 ,
V_246 , V_115 ,
V_220 ) ;
F_172 ( V_61 ,
V_216 , V_217 ,
V_218 , V_219 ,
V_221 , V_68 ,
V_246 , V_115 ,
V_220 ) ;
}
static void F_175 ( enum V_60 V_61 , T_5 V_220 ,
enum V_136 V_137 ,
bool V_256 , enum V_114 V_115 )
{
bool V_257 = false ;
int V_258 = 0 ;
if ( V_115 == V_126 ||
V_115 == V_127 ) {
if ( V_256 ) {
switch ( V_220 ) {
case V_242 :
V_258 = 2 ;
break;
case V_243 :
V_258 = 1 ;
break;
case V_244 :
V_258 = 0 ;
break;
case V_245 :
V_258 = 3 ;
break;
}
} else {
switch ( V_220 ) {
case V_242 :
V_258 = 0 ;
break;
case V_243 :
V_258 = 1 ;
break;
case V_244 :
V_258 = 2 ;
break;
case V_245 :
V_258 = 3 ;
break;
}
}
if ( V_220 == V_243 || V_220 == V_245 )
V_257 = true ;
else
V_257 = false ;
}
if ( V_115 == V_117 &&
V_137 != V_139 )
V_258 = 1 ;
F_9 ( F_75 ( V_61 ) , V_258 , 13 , 12 ) ;
if ( F_14 ( V_259 ) )
F_9 ( F_75 ( V_61 ) ,
V_257 ? 1 : 0 , 18 , 18 ) ;
if ( V_115 == V_117 ) {
bool V_260 = ( V_137 == V_139 ) &&
( V_220 == V_242 ||
V_220 == V_244 ) ;
F_9 ( F_75 ( V_61 ) , V_260 , 22 , 22 ) ;
}
}
static int F_176 ( enum V_114 V_115 )
{
switch ( V_115 ) {
case V_132 :
return 1 ;
case V_133 :
return 2 ;
case V_134 :
return 4 ;
case V_135 :
case V_117 :
return 8 ;
case V_120 :
case V_122 :
case V_121 :
case V_126 :
case V_127 :
case V_119 :
case V_118 :
case V_123 :
case V_131 :
return 16 ;
case V_125 :
return 24 ;
case V_124 :
case V_128 :
case V_129 :
case V_130 :
return 32 ;
default:
F_120 () ;
return 0 ;
}
}
static T_6 F_177 ( int V_261 , T_5 V_262 )
{
if ( V_261 == 1 )
return 1 ;
else if ( V_261 > 1 )
return 1 + ( V_261 - 1 ) * V_262 ;
else if ( V_261 < 0 )
return 1 - ( - V_261 + 1 ) * V_262 ;
else
F_120 () ;
return 0 ;
}
static void F_178 ( T_5 V_220 , bool V_263 ,
T_1 V_264 ,
T_1 V_103 , T_1 V_104 ,
enum V_114 V_115 , bool V_246 ,
unsigned int V_265 ,
unsigned * V_266 , unsigned * V_267 ,
T_6 * V_268 , T_6 * V_269 , int V_270 , int V_271 )
{
T_5 V_262 ;
switch ( V_115 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_120 () ;
return;
case V_126 :
case V_127 :
V_262 = 4 ;
break;
default:
V_262 = F_176 ( V_115 ) / 8 ;
break;
}
F_12 ( L_14 , V_220 , V_264 ,
V_103 , V_104 ) ;
switch ( V_220 + V_263 * 4 ) {
case V_242 :
case V_244 :
if ( V_115 == V_126 ||
V_115 == V_127 )
V_103 = V_103 >> 1 ;
case V_243 :
case V_245 :
* V_267 = 0 ;
if ( V_265 )
* V_266 = V_265 * V_264 * V_262 ;
else
* V_266 = 0 ;
* V_268 = F_177 ( 1 +
( V_271 * V_264 - V_270 * V_103 ) +
( V_246 ? V_264 : 0 ) , V_262 ) ;
* V_269 = F_177 ( V_270 , V_262 ) ;
break;
case V_242 + 4 :
case V_244 + 4 :
if ( V_115 == V_126 ||
V_115 == V_127 )
V_103 = V_103 >> 1 ;
case V_243 + 4 :
case V_245 + 4 :
* V_267 = 0 ;
if ( V_265 )
* V_266 = V_265 * V_264 * V_262 ;
else
* V_266 = 0 ;
* V_268 = F_177 ( 1 -
( V_271 * V_264 + V_270 * V_103 ) -
( V_246 ? V_264 : 0 ) , V_262 ) ;
* V_269 = F_177 ( V_270 , V_262 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_179 ( T_5 V_220 , bool V_263 ,
T_1 V_264 ,
T_1 V_103 , T_1 V_104 ,
enum V_114 V_115 , bool V_246 ,
unsigned int V_265 ,
unsigned * V_266 , unsigned * V_267 ,
T_6 * V_268 , T_6 * V_269 , int V_270 , int V_271 )
{
T_5 V_262 ;
T_1 V_272 , V_273 ;
switch ( V_115 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_120 () ;
return;
default:
V_262 = F_176 ( V_115 ) / 8 ;
break;
}
F_12 ( L_14 , V_220 , V_264 ,
V_103 , V_104 ) ;
if ( V_220 == V_242 || V_220 == V_244 ) {
V_272 = V_103 ;
V_273 = V_104 ;
} else {
V_272 = V_104 ;
V_273 = V_103 ;
}
switch ( V_220 + V_263 * 4 ) {
case V_242 :
* V_267 = 0 ;
if ( V_265 )
* V_266 = * V_267 + V_265 * V_264 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( 1 +
( V_271 * V_264 - V_272 * V_270 ) +
( V_246 ? V_264 : 0 ) , V_262 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_269 = F_177 ( V_270 , 2 * V_262 ) ;
else
* V_269 = F_177 ( V_270 , V_262 ) ;
break;
case V_243 :
* V_267 = V_264 * ( V_273 - 1 ) * V_262 ;
if ( V_265 )
* V_266 = * V_267 + V_265 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( V_264 * ( V_273 * V_270 - 1 ) +
V_271 + ( V_246 ? 1 : 0 ) , V_262 ) ;
* V_269 = F_177 ( - V_270 * V_264 , V_262 ) ;
break;
case V_244 :
* V_267 = ( V_264 * ( V_273 - 1 ) + V_272 - 1 ) * V_262 ;
if ( V_265 )
* V_266 = * V_267 - V_265 * V_264 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( - 1 -
( V_271 * V_264 - V_272 * V_270 ) -
( V_246 ? V_264 : 0 ) , V_262 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_269 = F_177 ( - V_270 , 2 * V_262 ) ;
else
* V_269 = F_177 ( - V_270 , V_262 ) ;
break;
case V_245 :
* V_267 = ( V_272 - 1 ) * V_262 ;
if ( V_265 )
* V_266 = * V_267 - V_265 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( - V_264 * ( V_273 * V_270 - 1 ) -
V_271 - ( V_246 ? 1 : 0 ) , V_262 ) ;
* V_269 = F_177 ( V_270 * V_264 , V_262 ) ;
break;
case V_242 + 4 :
* V_267 = ( V_272 - 1 ) * V_262 ;
if ( V_265 )
* V_266 = * V_267 + V_265 * V_264 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( V_271 * V_264 * 2 - 1 +
( V_246 ? V_264 : 0 ) ,
V_262 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_269 = F_177 ( - V_270 , 2 * V_262 ) ;
else
* V_269 = F_177 ( - V_270 , V_262 ) ;
break;
case V_243 + 4 :
* V_267 = 0 ;
if ( V_265 )
* V_266 = * V_267 + V_265 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( - V_264 * ( V_273 * V_270 - 1 ) +
V_271 + ( V_246 ? 1 : 0 ) ,
V_262 ) ;
* V_269 = F_177 ( V_270 * V_264 , V_262 ) ;
break;
case V_244 + 4 :
* V_267 = V_264 * ( V_273 - 1 ) * V_262 ;
if ( V_265 )
* V_266 = * V_267 - V_265 * V_264 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( 1 - V_271 * V_264 * 2 -
( V_246 ? V_264 : 0 ) ,
V_262 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_269 = F_177 ( V_270 , 2 * V_262 ) ;
else
* V_269 = F_177 ( V_270 , V_262 ) ;
break;
case V_245 + 4 :
* V_267 = ( V_264 * ( V_273 - 1 ) + V_272 - 1 ) * V_262 ;
if ( V_265 )
* V_266 = * V_267 - V_265 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( V_264 * ( V_273 * V_270 - 1 ) -
V_271 - ( V_246 ? 1 : 0 ) ,
V_262 ) ;
* V_269 = F_177 ( - V_270 * V_264 , V_262 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_180 ( T_1 V_264 , T_1 V_103 ,
enum V_114 V_115 , bool V_246 ,
unsigned int V_265 , unsigned * V_266 , unsigned * V_267 ,
T_6 * V_268 , T_6 * V_269 , int V_270 , int V_271 )
{
T_5 V_262 ;
switch ( V_115 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_120 () ;
return;
default:
V_262 = F_176 ( V_115 ) / 8 ;
break;
}
F_12 ( L_15 , V_264 , V_103 ) ;
* V_267 = 0 ;
if ( V_265 )
* V_266 = * V_267 + V_265 * V_264 * V_262 ;
else
* V_266 = * V_267 ;
* V_268 = F_177 ( 1 + ( V_271 * V_264 - V_103 * V_270 ) +
( V_246 ? V_264 : 0 ) , V_262 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_269 = F_177 ( V_270 , 2 * V_262 ) ;
else
* V_269 = F_177 ( V_270 , V_262 ) ;
}
static int F_181 ( unsigned long V_274 , unsigned long V_275 ,
const struct V_276 * V_277 , T_1 V_278 ,
T_1 V_103 , T_1 V_104 , T_1 V_218 , T_1 V_219 ,
bool V_68 )
{
const int V_279 = F_182 ( V_104 , V_219 ) ;
unsigned long V_280 ;
static const T_5 V_281 [ 3 ] = { 8 , 10 , 20 } ;
T_8 V_2 , V_282 ;
int V_21 ;
V_280 = V_277 -> V_283 + V_277 -> V_284 + V_277 -> V_285 + V_277 -> V_286 - V_218 ;
V_21 = 0 ;
if ( V_219 < V_104 )
V_21 ++ ;
if ( V_218 < V_103 )
V_21 ++ ;
V_282 = F_183 ( ( T_8 ) ( V_277 -> V_286 + V_277 -> V_285 + V_277 -> V_284 ) * V_275 , V_274 ) ;
F_12 ( L_16 , V_282 , V_281 [ V_21 ] ) ;
if ( V_282 <= V_281 [ V_21 ] )
return - V_287 ;
if ( ! V_68 )
return 0 ;
V_2 = F_183 ( ( T_8 ) ( V_280 - V_278 ) * V_275 , V_274 ) ;
F_12 ( L_17 ,
V_2 , F_184 ( 0 , V_279 - 2 ) * V_103 ) ;
if ( V_2 < F_184 ( 0 , V_279 - 2 ) * V_103 )
return - V_287 ;
V_2 = F_183 ( ( T_8 ) V_280 * V_275 , V_274 ) ;
F_12 ( L_18 ,
V_2 , F_184 ( 0 , V_279 - 1 ) * V_103 ) ;
if ( V_2 < F_184 ( 0 , V_279 - 1 ) * V_103 )
return - V_287 ;
return 0 ;
}
static unsigned long F_185 ( unsigned long V_274 ,
const struct V_276 * V_288 , T_1 V_103 ,
T_1 V_104 , T_1 V_218 , T_1 V_219 ,
enum V_114 V_115 )
{
T_2 V_289 = 0 ;
T_8 V_290 ;
if ( V_104 <= V_219 && V_103 <= V_218 )
return ( unsigned long ) V_274 ;
if ( V_104 > V_219 ) {
unsigned int V_291 = V_288 -> V_283 ;
V_290 = ( T_8 ) V_274 * V_104 * V_218 ;
F_186 ( V_290 , 2 * V_219 * V_291 ) ;
V_289 = V_290 ;
if ( V_104 > 2 * V_219 ) {
if ( V_291 == V_218 )
return 0 ;
V_290 = ( T_8 ) V_274 * ( V_104 - 2 * V_219 ) * V_218 ;
F_186 ( V_290 , 2 * V_219 * ( V_291 - V_218 ) ) ;
V_289 = F_187 ( T_2 , V_289 , V_290 ) ;
}
}
if ( V_103 > V_218 ) {
V_290 = ( T_8 ) V_274 * V_103 ;
F_186 ( V_290 , V_218 ) ;
V_289 = F_187 ( T_2 , V_289 , V_290 ) ;
if ( V_115 == V_124 )
V_289 <<= 1 ;
}
return V_289 ;
}
static unsigned long F_188 ( unsigned long V_274 , T_1 V_103 ,
T_1 V_104 , T_1 V_218 , T_1 V_219 , bool V_292 )
{
if ( V_104 > V_219 && V_103 > V_218 )
return V_274 * 4 ;
else
return V_274 * 2 ;
}
static unsigned long F_189 ( unsigned long V_274 , T_1 V_103 ,
T_1 V_104 , T_1 V_218 , T_1 V_219 , bool V_292 )
{
unsigned int V_293 , V_294 ;
if ( V_103 > 3 * V_218 )
V_293 = 4 ;
else if ( V_103 > 2 * V_218 )
V_293 = 3 ;
else if ( V_103 > V_218 )
V_293 = 2 ;
else
V_293 = 1 ;
if ( V_104 > V_219 )
V_294 = 2 ;
else
V_294 = 1 ;
return V_274 * V_294 * V_293 ;
}
static unsigned long F_190 ( unsigned long V_274 , T_1 V_103 ,
T_1 V_104 , T_1 V_218 , T_1 V_219 , bool V_292 )
{
if ( V_292 )
return 1 ;
if ( V_103 > V_218 )
return F_182 ( V_274 , V_218 ) * V_103 ;
else
return V_274 ;
}
static int F_191 ( unsigned long V_274 , unsigned long V_275 ,
const struct V_276 * V_288 ,
T_1 V_103 , T_1 V_104 , T_1 V_218 , T_1 V_219 ,
enum V_114 V_115 , bool * V_68 ,
int * V_270 , int * V_271 , int * V_295 , int * V_296 ,
T_1 V_278 , unsigned long * V_289 , bool V_292 )
{
int error ;
T_1 V_297 , V_298 ;
int V_299 = F_152 ( * V_295 , * V_296 ) ;
const int V_300 =
F_192 ( V_301 ) ;
* V_68 = false ;
do {
V_298 = V_104 / * V_296 ;
V_297 = V_103 / * V_295 ;
* V_289 = V_3 . V_52 -> V_302 ( V_274 , V_297 ,
V_298 , V_218 , V_219 , V_292 ) ;
error = ( V_297 > V_300 || ! * V_289 ||
* V_289 > F_193 () ) ;
if ( error ) {
if ( * V_295 == * V_296 ) {
* V_295 = V_299 ;
++ * V_296 ;
} else {
F_194 ( * V_295 , * V_296 ) ;
if ( * V_295 < * V_296 )
++ * V_295 ;
}
}
} while ( * V_295 <= * V_270 && * V_296 <= * V_271 && error );
if ( error ) {
F_76 ( L_19 ) ;
return - V_287 ;
}
if ( V_297 > V_300 ) {
F_76 ( L_20 ) ;
return - V_287 ;
}
return 0 ;
}
static int F_195 ( unsigned long V_274 , unsigned long V_275 ,
const struct V_276 * V_288 ,
T_1 V_103 , T_1 V_104 , T_1 V_218 , T_1 V_219 ,
enum V_114 V_115 , bool * V_68 ,
int * V_270 , int * V_271 , int * V_295 , int * V_296 ,
T_1 V_278 , unsigned long * V_289 , bool V_292 )
{
int error ;
T_1 V_297 , V_298 ;
const int V_300 =
F_192 ( V_301 ) ;
do {
V_298 = V_104 / * V_296 ;
V_297 = V_103 / * V_295 ;
* V_68 = V_298 > V_219 ;
if ( V_297 > V_300 )
if ( V_298 > V_219 &&
V_298 < V_219 * 2 )
* V_68 = false ;
V_303:
if ( * V_68 )
* V_289 = F_185 ( V_274 , V_288 ,
V_297 , V_298 , V_218 ,
V_219 , V_115 ) ;
else
* V_289 = V_3 . V_52 -> V_302 ( V_274 , V_297 ,
V_298 , V_218 , V_219 ,
V_292 ) ;
error = F_181 ( V_274 , V_275 , V_288 ,
V_278 , V_297 , V_298 , V_218 ,
V_219 , * V_68 ) ;
if ( error && * V_68 ) {
* V_68 = false ;
goto V_303;
}
error = ( error || V_297 > V_300 * 2 ||
( V_297 > V_300 && * V_68 ) ||
! * V_289 || * V_289 > F_193 () ) ;
if ( ! error ) {
if ( V_297 / 4 > V_218 )
error = 1 ;
if ( * V_68 ) {
if ( V_298 / 4 > V_219 )
error = 1 ;
} else {
if ( V_298 / 2 > V_219 )
error = 1 ;
}
}
if ( error )
++ * V_296 ;
} while ( * V_295 <= * V_270 && * V_296 <= * V_271 && error );
if ( error ) {
F_76 ( L_19 ) ;
return - V_287 ;
}
if ( F_181 ( V_274 , V_275 , V_288 , V_278 , V_297 ,
V_298 , V_218 , V_219 , * V_68 ) ) {
F_76 ( L_21 ) ;
return - V_287 ;
}
if ( V_297 > ( V_300 * 2 ) ) {
F_76 ( L_22 ) ;
F_76 ( L_23 ) ;
return - V_287 ;
}
if ( V_297 > V_300 && * V_68 ) {
F_76 ( L_24 ) ;
return - V_287 ;
}
return 0 ;
}
static int F_196 ( unsigned long V_274 , unsigned long V_275 ,
const struct V_276 * V_288 ,
T_1 V_103 , T_1 V_104 , T_1 V_218 , T_1 V_219 ,
enum V_114 V_115 , bool * V_68 ,
int * V_270 , int * V_271 , int * V_295 , int * V_296 ,
T_1 V_278 , unsigned long * V_289 , bool V_292 )
{
T_1 V_297 , V_304 ;
int V_305 = * V_295 ;
T_1 V_298 = V_104 / * V_296 ;
const int V_300 =
F_192 ( V_301 ) ;
const int V_306 = F_192 ( V_307 ) ;
if ( V_292 ) {
V_304 = V_218 * V_306 ;
} else {
V_304 = F_193 () /
F_182 ( V_274 , V_218 ) ;
}
* V_295 = F_182 ( V_103 , V_304 ) ;
* V_295 = * V_295 > V_305 ? * V_295 : V_305 ;
if ( * V_295 > * V_270 )
return - V_287 ;
do {
V_297 = V_103 / * V_295 ;
} while ( * V_295 <= * V_270 &&
V_297 > V_300 && ++ * V_295 );
if ( V_297 > V_300 ) {
F_76 ( L_25 ) ;
return - V_287 ;
}
* V_289 = V_3 . V_52 -> V_302 ( V_274 , V_297 , V_298 ,
V_218 , V_219 , V_292 ) ;
return 0 ;
}
static int F_197 ( unsigned long V_274 , unsigned long V_275 ,
enum V_100 V_101 ,
const struct V_276 * V_288 ,
T_1 V_103 , T_1 V_104 , T_1 V_218 , T_1 V_219 ,
enum V_114 V_115 , bool * V_68 ,
int * V_270 , int * V_271 , T_1 V_278 ,
enum V_136 V_137 , bool V_292 )
{
const int V_306 = F_192 ( V_307 ) ;
const int V_308 = 16 ;
unsigned long V_289 = 0 ;
int V_295 , V_296 , V_309 ;
if ( V_103 == V_218 && V_104 == V_219 )
return 0 ;
if ( ! V_292 && ( V_274 == 0 || V_288 -> V_310 == 0 ) ) {
F_76 ( L_26 ) ;
return - V_287 ;
}
if ( ( V_101 & V_311 ) == 0 )
return - V_287 ;
if ( V_292 ) {
* V_270 = * V_271 = 1 ;
} else {
* V_270 = V_308 ;
* V_271 = ( V_137 == V_139 &&
F_14 ( V_138 ) ) ?
2 : V_308 ;
}
if ( V_115 == V_132 ||
V_115 == V_133 ||
V_115 == V_134 ||
V_115 == V_135 ) {
* V_270 = 1 ;
* V_271 = 1 ;
* V_68 = false ;
return 0 ;
}
V_295 = F_182 ( F_182 ( V_103 , V_218 ) , V_306 ) ;
V_296 = F_182 ( F_182 ( V_104 , V_219 ) , V_306 ) ;
if ( V_295 > * V_270 || V_218 > V_103 * 8 )
return - V_287 ;
if ( V_296 > * V_271 || V_219 > V_104 * 8 )
return - V_287 ;
V_309 = V_3 . V_52 -> V_312 ( V_274 , V_275 , V_288 , V_103 , V_104 ,
V_218 , V_219 , V_115 , V_68 ,
V_270 , V_271 , & V_295 , & V_296 , V_278 , & V_289 ,
V_292 ) ;
if ( V_309 )
return V_309 ;
F_12 ( L_27 ,
V_103 , V_104 ,
V_218 , V_219 ,
V_218 / V_103 , F_198 ( V_218 , V_103 ) ,
V_219 / V_104 , F_198 ( V_219 , V_104 ) ,
V_295 , V_296 ,
V_103 / V_295 , V_104 / V_296 ,
V_218 / ( V_103 / V_295 ) , F_198 ( V_218 , V_103 / V_295 ) ,
V_219 / ( V_104 / V_296 ) , F_198 ( V_219 , V_104 / V_296 ) ,
* V_68 ? 5 : 3 ,
V_289 , F_193 () ) ;
if ( ! V_289 || V_289 > F_193 () ) {
F_76 ( L_28
L_29
L_30 ,
V_289 , F_193 () ) ;
return - V_287 ;
}
* V_270 = V_295 ;
* V_271 = V_296 ;
return 0 ;
}
int F_199 ( enum V_60 V_61 , enum V_5 V_6 ,
const struct V_313 * V_314 ,
const struct V_276 * V_315 ,
int * V_270 , int * V_271 )
{
enum V_100 V_101 = F_200 ( V_61 ) ;
bool V_68 = true ;
bool V_246 = false ;
T_1 V_298 = V_314 -> V_104 ;
T_1 V_297 = V_314 -> V_103 ;
bool V_221 = V_315 -> V_316 ;
T_1 V_218 , V_219 ;
int V_278 = V_314 -> V_278 ;
unsigned long V_274 = F_201 ( V_6 ) ;
unsigned long V_275 = F_202 ( V_6 ) ;
V_218 = V_314 -> V_218 == 0 ? V_314 -> V_103 : V_314 -> V_218 ;
V_219 = V_314 -> V_219 == 0 ? V_314 -> V_104 : V_314 -> V_219 ;
if ( V_221 && V_314 -> V_104 == V_219 )
V_246 = true ;
if ( V_221 ) {
if ( V_246 )
V_298 /= 2 ;
V_219 /= 2 ;
F_12 ( L_31 ,
V_298 , V_219 ) ;
}
if ( ! F_203 ( V_61 , V_314 -> V_115 ) )
return - V_287 ;
return F_197 ( V_274 , V_275 , V_101 , V_315 , V_297 ,
V_298 , V_218 , V_219 , V_314 -> V_115 ,
& V_68 , V_270 , V_271 , V_278 ,
V_314 -> V_137 , false ) ;
}
static int F_204 ( enum V_60 V_61 ,
enum V_100 V_101 , T_2 V_99 , T_2 V_317 ,
T_1 V_264 , int V_278 , int V_318 , T_1 V_103 , T_1 V_104 ,
T_1 V_218 , T_1 V_219 , enum V_114 V_115 ,
T_5 V_220 , bool V_263 , T_5 V_105 , T_5 V_319 ,
T_5 V_108 , enum V_136 V_137 ,
bool V_320 , const struct V_276 * V_288 ,
bool V_292 )
{
bool V_68 = true ;
bool V_246 = false ;
int V_47 , V_321 = 0 ;
unsigned V_266 , V_267 ;
T_6 V_268 ;
T_6 V_269 ;
T_1 V_322 , V_323 ;
unsigned int V_265 = 0 ;
T_1 V_298 = V_104 ;
T_1 V_297 = V_103 ;
int V_270 = 1 , V_271 = 1 ;
bool V_221 = V_288 -> V_316 ;
unsigned long V_274 = F_205 ( V_61 ) ;
unsigned long V_275 = F_206 ( V_61 ) ;
if ( V_99 == 0 && V_137 != V_139 )
return - V_287 ;
switch ( V_115 ) {
case V_126 :
case V_127 :
case V_117 :
if ( V_297 & 1 ) {
F_76 ( L_32 ,
V_297 ) ;
return - V_287 ;
}
break;
default:
break;
}
V_218 = V_218 == 0 ? V_103 : V_218 ;
V_219 = V_219 == 0 ? V_104 : V_219 ;
if ( V_221 && V_104 == V_219 )
V_246 = true ;
if ( V_221 ) {
if ( V_246 )
V_298 /= 2 ;
V_318 /= 2 ;
V_219 /= 2 ;
F_12 ( L_33
L_34 , V_298 , V_318 ,
V_219 ) ;
}
if ( ! F_203 ( V_61 , V_115 ) )
return - V_287 ;
V_47 = F_197 ( V_274 , V_275 , V_101 , V_288 , V_297 ,
V_298 , V_218 , V_219 , V_115 ,
& V_68 , & V_270 , & V_271 , V_278 ,
V_137 , V_292 ) ;
if ( V_47 )
return V_47 ;
V_297 = V_297 / V_270 ;
V_298 = V_298 / V_271 ;
if ( V_270 > 1 || V_271 > 1 )
F_12 ( L_35 ,
V_270 , V_271 , V_297 , V_298 ) ;
switch ( V_115 ) {
case V_126 :
case V_127 :
case V_117 :
if ( V_297 & 1 ) {
F_12 ( L_36 ) ;
F_12 ( L_37 ,
V_297 , V_297 & ~ 1 ) ;
V_297 &= ~ 1 ;
}
break;
default:
break;
}
if ( V_115 == V_126 ||
V_115 == V_127 ||
V_115 == V_117 )
V_321 = 1 ;
if ( V_221 && ! V_246 ) {
if ( ! V_298 || V_298 == V_219 )
V_265 = 0 ;
else
V_265 = V_298 / V_219 / 2 ;
}
if ( V_246 )
V_265 = 1 ;
V_266 = 0 ;
V_267 = 0 ;
V_268 = 0 ;
V_269 = 0 ;
if ( V_61 == V_62 ) {
V_322 = V_218 ;
V_323 = V_219 ;
} else {
V_322 = V_297 ;
V_323 = V_104 ;
}
if ( V_137 == V_139 )
F_180 ( V_264 , V_322 ,
V_115 , V_246 , V_265 ,
& V_266 , & V_267 , & V_268 , & V_269 ,
V_270 , V_271 ) ;
else if ( V_137 == V_324 )
F_179 ( V_220 , V_263 , V_264 ,
V_322 , V_323 ,
V_115 , V_246 , V_265 ,
& V_266 , & V_267 , & V_268 , & V_269 ,
V_270 , V_271 ) ;
else
F_178 ( V_220 , V_263 ,
V_264 , V_322 , V_323 ,
V_115 , V_246 , V_265 ,
& V_266 , & V_267 , & V_268 , & V_269 ,
V_270 , V_271 ) ;
F_12 ( L_38 ,
V_266 , V_267 , V_268 , V_269 ) ;
F_119 ( V_61 , V_115 ) ;
F_121 ( V_61 , V_137 ) ;
F_97 ( V_61 , V_99 + V_266 ) ;
F_99 ( V_61 , V_99 + V_267 ) ;
if ( V_117 == V_115 ) {
F_101 ( V_61 , V_317 + V_266 ) ;
F_103 ( V_61 , V_317 + V_267 ) ;
}
if ( V_3 . V_52 -> V_325 )
V_268 += V_269 - 1 ;
F_117 ( V_61 , V_268 ) ;
F_115 ( V_61 , V_269 ) ;
F_12 ( L_39 , V_278 , V_318 , V_297 ,
V_298 , V_218 , V_219 ) ;
F_105 ( V_61 , V_101 , V_278 , V_318 ) ;
F_107 ( V_61 , V_297 , V_298 ) ;
if ( V_101 & V_311 ) {
F_174 ( V_61 , V_297 , V_298 , V_218 ,
V_219 , V_221 , V_68 , V_246 ,
V_115 , V_220 ) ;
F_110 ( V_61 , V_218 , V_219 ) ;
F_139 ( V_61 , V_321 ) ;
}
F_175 ( V_61 , V_220 , V_137 , V_263 ,
V_115 ) ;
F_111 ( V_61 , V_101 , V_105 ) ;
F_113 ( V_61 , V_101 , V_319 ) ;
F_114 ( V_61 , V_101 , V_108 ) ;
F_140 ( V_61 , V_101 , V_320 ) ;
return 0 ;
}
int F_207 ( enum V_60 V_61 , const struct V_313 * V_314 ,
bool V_320 , const struct V_276 * V_288 ,
bool V_292 )
{
int V_47 ;
enum V_100 V_101 = F_200 ( V_61 ) ;
enum V_5 V_6 ;
V_6 = F_124 ( V_61 ) ;
F_12 ( L_40
L_41 ,
V_61 , & V_314 -> V_99 , & V_314 -> V_317 , V_314 -> V_264 , V_314 -> V_278 ,
V_314 -> V_318 , V_314 -> V_103 , V_314 -> V_104 , V_314 -> V_218 , V_314 -> V_219 ,
V_314 -> V_115 , V_314 -> V_220 , V_314 -> V_263 , V_6 , V_320 ) ;
V_47 = F_204 ( V_61 , V_101 , V_314 -> V_99 , V_314 -> V_317 ,
V_314 -> V_264 , V_314 -> V_278 , V_314 -> V_318 , V_314 -> V_103 , V_314 -> V_104 ,
V_314 -> V_218 , V_314 -> V_219 , V_314 -> V_115 , V_314 -> V_220 ,
V_314 -> V_263 , V_314 -> V_105 , V_314 -> V_319 , V_314 -> V_108 ,
V_314 -> V_137 , V_320 , V_288 , V_292 ) ;
return V_47 ;
}
int F_208 ( const struct V_326 * V_327 ,
bool V_292 , const struct V_276 * V_288 )
{
int V_47 ;
T_2 V_249 ;
enum V_60 V_61 = V_62 ;
const int V_278 = 0 , V_318 = 0 ;
const T_5 V_105 = 0 , V_108 = 0 ;
const bool V_320 = false ;
bool V_328 ;
int V_297 = V_288 -> V_283 ;
int V_298 = V_288 -> V_329 ;
enum V_100 V_101 =
V_311 | V_107 ;
F_12 ( L_42
L_43 , V_327 -> V_99 , V_327 -> V_317 , V_297 ,
V_298 , V_327 -> V_103 , V_327 -> V_104 , V_327 -> V_115 , V_327 -> V_220 ,
V_327 -> V_263 ) ;
V_47 = F_204 ( V_61 , V_101 , V_327 -> V_99 , V_327 -> V_317 ,
V_327 -> V_330 , V_278 , V_318 , V_297 , V_298 , V_327 -> V_103 ,
V_327 -> V_104 , V_327 -> V_115 , V_327 -> V_220 , V_327 -> V_263 , V_105 ,
V_327 -> V_319 , V_108 , V_327 -> V_137 ,
V_320 , V_288 , V_292 ) ;
switch ( V_327 -> V_115 ) {
case V_122 :
case V_125 :
case V_121 :
case V_119 :
case V_120 :
case V_123 :
case V_131 :
case V_118 :
V_328 = true ;
break;
default:
V_328 = false ;
break;
}
V_249 = F_3 ( F_75 ( V_61 ) ) ;
V_249 = F_123 ( V_249 , V_328 , 10 , 10 ) ;
V_249 = F_123 ( V_249 , V_292 , 19 , 19 ) ;
if ( V_292 )
V_249 = F_123 ( V_249 , 1 , 26 , 24 ) ;
else
V_249 = F_123 ( V_249 , 0 , 26 , 24 ) ;
F_1 ( F_75 ( V_61 ) , V_249 ) ;
if ( V_292 ) {
F_9 ( F_173 ( V_61 ) , 0 , 7 , 0 ) ;
} else {
int V_331 ;
V_331 = F_152 ( V_288 -> V_332 + V_288 -> V_333 +
V_288 -> V_334 , 255 ) ;
F_9 ( F_173 ( V_61 ) , V_331 , 7 , 0 ) ;
}
return V_47 ;
}
int F_209 ( enum V_60 V_61 , bool V_63 )
{
F_12 ( L_44 , V_61 , V_63 ) ;
F_9 ( F_75 ( V_61 ) , V_63 ? 1 : 0 , 0 , 0 ) ;
return 0 ;
}
bool F_210 ( enum V_60 V_61 )
{
return F_6 ( F_75 ( V_61 ) , 0 , 0 ) ;
}
void F_211 ( enum V_5 V_6 , bool V_63 )
{
F_7 ( V_6 , V_335 , V_63 ) ;
F_5 ( V_6 , V_335 ) ;
}
bool F_72 ( enum V_5 V_6 )
{
return ! ! F_5 ( V_6 , V_335 ) ;
}
void F_212 ( bool V_63 )
{
F_209 ( V_62 , V_63 ) ;
}
bool F_213 ( void )
{
return F_210 ( V_62 ) ;
}
static void F_214 ( bool V_336 )
{
if ( ! F_14 ( V_337 ) )
return;
F_9 ( V_17 , V_336 ? 1 : 0 , 29 , 29 ) ;
}
void F_215 ( bool V_63 )
{
if ( ! F_14 ( V_338 ) )
return;
F_9 ( V_17 , V_63 ? 1 : 0 , 28 , 28 ) ;
}
void F_216 ( bool V_63 )
{
if ( ! F_14 ( V_339 ) )
return;
F_9 ( V_17 , V_63 ? 1 : 0 , 27 , 27 ) ;
}
static void F_217 ( enum V_5 V_6 , bool V_63 )
{
F_7 ( V_6 , V_340 , V_63 ) ;
}
static void F_218 ( enum V_5 V_6 )
{
F_7 ( V_6 , V_341 , 1 ) ;
}
static void F_219 ( enum V_342 V_343 )
{
F_9 ( V_18 , V_343 , 2 , 1 ) ;
}
static void F_220 ( enum V_5 V_6 , T_2 V_344 )
{
F_1 ( F_221 ( V_6 ) , V_344 ) ;
}
static void F_222 ( enum V_5 V_345 ,
enum V_346 type ,
T_2 V_347 )
{
F_7 ( V_345 , V_348 , type ) ;
F_1 ( F_223 ( V_345 ) , V_347 ) ;
}
static void F_224 ( enum V_5 V_345 , bool V_63 )
{
F_7 ( V_345 , V_349 , V_63 ) ;
}
static void F_225 ( enum V_5 V_345 ,
bool V_63 )
{
if ( ! F_14 ( V_27 ) )
return;
if ( V_345 == V_145 )
F_9 ( V_18 , V_63 , 18 , 18 ) ;
else if ( V_345 == V_36 )
F_9 ( V_18 , V_63 , 19 , 19 ) ;
}
void F_226 ( enum V_5 V_6 ,
const struct V_350 * V_351 )
{
F_220 ( V_6 , V_351 -> V_352 ) ;
F_222 ( V_6 , V_351 -> V_353 , V_351 -> V_347 ) ;
F_224 ( V_6 , V_351 -> V_354 ) ;
F_225 ( V_6 ,
V_351 -> V_355 ) ;
if ( F_14 ( V_37 ) ) {
F_133 ( V_6 , V_351 -> V_356 ) ;
F_134 ( V_6 , & V_351 -> V_357 ) ;
}
}
static void F_227 ( enum V_5 V_6 , T_5 V_358 )
{
int V_359 ;
switch ( V_358 ) {
case 12 :
V_359 = 0 ;
break;
case 16 :
V_359 = 1 ;
break;
case 18 :
V_359 = 2 ;
break;
case 24 :
V_359 = 3 ;
break;
default:
F_120 () ;
return;
}
F_7 ( V_6 , V_360 , V_359 ) ;
}
static void F_228 ( enum V_361 V_343 )
{
T_2 V_249 ;
int V_362 , V_363 ;
switch ( V_343 ) {
case V_364 :
V_362 = 0 ;
V_363 = 0 ;
break;
case V_365 :
V_362 = 1 ;
V_363 = 0 ;
break;
case V_366 :
V_362 = 1 ;
V_363 = 1 ;
break;
default:
F_120 () ;
return;
}
V_249 = F_3 ( V_17 ) ;
V_249 = F_123 ( V_249 , V_362 , 15 , 15 ) ;
V_249 = F_123 ( V_249 , V_363 , 16 , 16 ) ;
F_1 ( V_17 , V_249 ) ;
}
static void F_229 ( enum V_5 V_6 , bool V_63 )
{
F_7 ( V_6 , V_367 , V_63 ) ;
}
void F_230 ( enum V_5 V_6 ,
const struct V_368 * V_369 )
{
F_228 ( V_369 -> V_370 ) ;
F_229 ( V_6 , V_369 -> V_371 ) ;
F_217 ( V_6 , V_369 -> V_372 ) ;
F_231 ( V_6 , & V_369 -> V_373 ) ;
F_227 ( V_6 , V_369 -> V_374 ) ;
F_214 ( V_369 -> V_375 ) ;
F_218 ( V_6 ) ;
}
static bool F_232 ( T_1 V_103 , T_1 V_104 )
{
return V_103 <= V_3 . V_52 -> V_376 &&
V_104 <= V_3 . V_52 -> V_377 ;
}
static bool F_233 ( int V_285 , int V_284 , int V_286 ,
int V_333 , int V_332 , int V_334 )
{
if ( V_285 < 1 || V_285 > V_3 . V_52 -> V_378 ||
V_284 < 1 || V_284 > V_3 . V_52 -> V_379 ||
V_286 < 1 || V_286 > V_3 . V_52 -> V_379 ||
V_333 < 1 || V_333 > V_3 . V_52 -> V_378 ||
V_332 < 0 || V_332 > V_3 . V_52 -> V_380 ||
V_334 < 0 || V_334 > V_3 . V_52 -> V_380 )
return false ;
return true ;
}
static bool F_234 ( enum V_5 V_6 ,
unsigned long V_274 )
{
if ( F_135 ( V_6 ) )
return V_274 <= V_3 . V_52 -> V_381 ? true : false ;
else
return V_274 <= V_3 . V_52 -> V_382 ? true : false ;
}
bool F_235 ( enum V_5 V_6 ,
const struct V_276 * V_315 )
{
if ( ! F_232 ( V_315 -> V_283 , V_315 -> V_329 ) )
return false ;
if ( ! F_234 ( V_6 , V_315 -> V_310 ) )
return false ;
if ( F_135 ( V_6 ) ) {
if ( V_315 -> V_316 )
return false ;
if ( ! F_233 ( V_315 -> V_285 , V_315 -> V_284 ,
V_315 -> V_286 , V_315 -> V_333 , V_315 -> V_332 ,
V_315 -> V_334 ) )
return false ;
}
return true ;
}
static void F_236 ( enum V_5 V_6 , int V_285 ,
int V_284 , int V_286 , int V_333 , int V_332 , int V_334 ,
enum V_383 V_384 ,
enum V_383 V_385 ,
enum V_386 V_387 ,
enum V_383 V_388 ,
enum V_386 V_389 )
{
T_2 V_390 , V_391 , V_249 ;
bool V_392 , V_393 , V_394 , V_395 , V_396 , V_397 ;
V_390 = F_92 ( V_285 - 1 , V_3 . V_52 -> V_398 , 0 ) |
F_92 ( V_284 - 1 , V_3 . V_52 -> V_399 , 8 ) |
F_92 ( V_286 - 1 , V_3 . V_52 -> V_400 , 20 ) ;
V_391 = F_92 ( V_333 - 1 , V_3 . V_52 -> V_398 , 0 ) |
F_92 ( V_332 , V_3 . V_52 -> V_399 , 8 ) |
F_92 ( V_334 , V_3 . V_52 -> V_400 , 20 ) ;
F_1 ( F_237 ( V_6 ) , V_390 ) ;
F_1 ( F_238 ( V_6 ) , V_391 ) ;
switch ( V_384 ) {
case V_401 :
V_395 = true ;
break;
case V_402 :
V_395 = false ;
break;
default:
F_120 () ;
}
switch ( V_385 ) {
case V_401 :
V_396 = true ;
break;
case V_402 :
V_396 = false ;
break;
default:
F_120 () ;
}
switch ( V_388 ) {
case V_401 :
V_397 = true ;
break;
case V_402 :
V_397 = false ;
break;
default:
F_120 () ;
}
switch ( V_387 ) {
case V_403 :
V_394 = false ;
break;
case V_404 :
V_394 = true ;
break;
default:
F_120 () ;
}
V_392 = true ;
switch ( V_389 ) {
case V_404 :
V_393 = false ;
break;
case V_403 :
V_393 = true ;
break;
default:
F_120 () ;
}
V_249 = F_92 ( V_392 , 17 , 17 ) |
F_92 ( V_393 , 16 , 16 ) |
F_92 ( V_397 , 15 , 15 ) |
F_92 ( V_394 , 14 , 14 ) |
F_92 ( V_396 , 13 , 13 ) |
F_92 ( V_395 , 12 , 12 ) ;
if ( V_3 . V_52 -> V_405 )
V_249 |= ( 1 << 18 ) ;
F_1 ( F_239 ( V_6 ) , V_249 ) ;
if ( V_3 . V_406 ) {
const int V_109 [] = {
[ V_145 ] = 0 ,
[ V_146 ] = 1 ,
[ V_147 ] = 2 ,
} ;
T_2 V_407 , V_2 ;
V_407 = ( 1 << 0 ) | ( 1 << 3 ) | ( 1 << 6 ) ;
V_2 = ( V_393 << 0 ) | ( V_394 << 3 ) | ( V_392 << 6 ) ;
V_407 <<= 16 + V_109 [ V_6 ] ;
V_2 <<= 16 + V_109 [ V_6 ] ;
F_240 ( V_3 . V_406 , V_3 . V_408 ,
V_407 , V_2 ) ;
}
}
void F_241 ( enum V_5 V_6 ,
const struct V_276 * V_315 )
{
unsigned V_409 , V_410 ;
unsigned long V_411 , V_412 ;
struct V_276 V_277 = * V_315 ;
F_12 ( L_45 , V_6 , V_277 . V_283 , V_277 . V_329 ) ;
if ( ! F_235 ( V_6 , & V_277 ) ) {
F_120 () ;
return;
}
if ( F_135 ( V_6 ) ) {
F_236 ( V_6 , V_277 . V_285 , V_277 . V_284 , V_277 . V_286 , V_277 . V_333 ,
V_277 . V_332 , V_277 . V_334 , V_277 . V_384 , V_277 . V_385 ,
V_277 . V_387 , V_277 . V_388 , V_277 . V_389 ) ;
V_409 = V_277 . V_283 + V_277 . V_284 + V_277 . V_285 + V_277 . V_286 ;
V_410 = V_277 . V_329 + V_277 . V_332 + V_277 . V_333 + V_277 . V_334 ;
V_411 = V_315 -> V_310 / V_409 ;
V_412 = V_315 -> V_310 / V_409 / V_410 ;
F_12 ( L_46 , V_315 -> V_310 ) ;
F_12 ( L_47 ,
V_277 . V_285 , V_277 . V_284 , V_277 . V_286 , V_277 . V_333 , V_277 . V_332 , V_277 . V_334 ) ;
F_12 ( L_48 ,
V_277 . V_384 , V_277 . V_385 , V_277 . V_387 ,
V_277 . V_388 , V_277 . V_389 ) ;
F_12 ( L_49 , V_411 , V_412 ) ;
} else {
if ( V_277 . V_316 )
V_277 . V_329 /= 2 ;
}
F_141 ( V_6 , V_277 . V_283 , V_277 . V_329 ) ;
}
static void F_242 ( enum V_5 V_6 , T_1 V_413 ,
T_1 V_414 )
{
F_84 ( V_413 < 1 ) ;
F_84 ( V_414 < 1 ) ;
F_1 ( F_243 ( V_6 ) ,
F_92 ( V_413 , 23 , 16 ) | F_92 ( V_414 , 7 , 0 ) ) ;
if ( ! F_14 ( V_43 ) &&
V_6 == V_145 )
V_3 . V_415 = F_244 () / V_413 ;
}
static void F_245 ( enum V_5 V_6 , int * V_413 ,
int * V_414 )
{
T_2 V_249 ;
V_249 = F_3 ( F_243 ( V_6 ) ) ;
* V_413 = F_125 ( V_249 , 23 , 16 ) ;
* V_414 = F_125 ( V_249 , 7 , 0 ) ;
}
static unsigned long F_244 ( void )
{
struct V_416 * V_417 ;
unsigned long V_47 = 0 ;
switch ( F_246 () ) {
case V_418 :
V_47 = F_247 () ;
break;
case V_419 :
V_417 = F_248 ( L_50 ) ;
if ( ! V_417 )
V_417 = F_248 ( L_51 ) ;
V_47 = V_417 -> V_420 . V_421 [ 0 ] ;
break;
case V_422 :
V_417 = F_248 ( L_52 ) ;
if ( ! V_417 )
V_417 = F_248 ( L_53 ) ;
V_47 = V_417 -> V_420 . V_421 [ 0 ] ;
break;
default:
F_120 () ;
return 0 ;
}
return V_47 ;
}
static unsigned long F_202 ( enum V_5 V_6 )
{
struct V_416 * V_417 ;
int V_423 ;
unsigned long V_47 ;
T_2 V_249 ;
if ( F_135 ( V_6 ) ) {
V_249 = F_3 ( F_243 ( V_6 ) ) ;
V_423 = F_125 ( V_249 , 23 , 16 ) ;
switch ( F_249 ( V_6 ) ) {
case V_418 :
V_47 = F_247 () ;
break;
case V_419 :
V_417 = F_248 ( L_50 ) ;
if ( ! V_417 )
V_417 = F_248 ( L_51 ) ;
V_47 = V_417 -> V_420 . V_421 [ 0 ] ;
break;
case V_422 :
V_417 = F_248 ( L_52 ) ;
if ( ! V_417 )
V_417 = F_248 ( L_53 ) ;
V_47 = V_417 -> V_420 . V_421 [ 0 ] ;
break;
default:
F_120 () ;
return 0 ;
}
return V_47 / V_423 ;
} else {
return F_244 () ;
}
}
static unsigned long F_201 ( enum V_5 V_6 )
{
unsigned long V_47 ;
if ( F_135 ( V_6 ) ) {
int V_424 ;
T_2 V_249 ;
V_249 = F_3 ( F_243 ( V_6 ) ) ;
V_424 = F_125 ( V_249 , 7 , 0 ) ;
V_47 = F_202 ( V_6 ) ;
return V_47 / V_424 ;
} else {
return V_3 . V_425 ;
}
}
void F_250 ( unsigned long V_274 )
{
V_3 . V_425 = V_274 ;
}
static unsigned long F_193 ( void )
{
return V_3 . V_415 ;
}
static unsigned long F_205 ( enum V_60 V_61 )
{
enum V_5 V_6 ;
if ( V_61 == V_62 )
return 0 ;
V_6 = F_124 ( V_61 ) ;
return F_201 ( V_6 ) ;
}
static unsigned long F_206 ( enum V_60 V_61 )
{
enum V_5 V_6 ;
if ( V_61 == V_62 )
return 0 ;
V_6 = F_124 ( V_61 ) ;
return F_202 ( V_6 ) ;
}
static void F_251 ( struct V_426 * V_427 , enum V_5 V_6 )
{
int V_423 , V_424 ;
enum V_428 V_429 ;
F_252 ( V_427 , L_54 , V_11 [ V_6 ] . V_58 ) ;
V_429 = F_249 ( V_6 ) ;
F_252 ( V_427 , L_55 , V_11 [ V_6 ] . V_58 ,
F_253 ( V_429 ) ,
F_254 ( V_429 ) ) ;
F_245 ( V_6 , & V_423 , & V_424 ) ;
F_252 ( V_427 , L_56 ,
F_202 ( V_6 ) , V_423 ) ;
F_252 ( V_427 , L_57 ,
F_201 ( V_6 ) , V_424 ) ;
}
void F_255 ( struct V_426 * V_427 )
{
int V_423 ;
T_2 V_249 ;
enum V_428 V_430 = F_246 () ;
if ( F_61 () )
return;
F_252 ( V_427 , L_58 ) ;
F_252 ( V_427 , L_59 ,
F_253 ( V_430 ) ,
F_254 ( V_430 ) ) ;
F_252 ( V_427 , L_60 , F_244 () ) ;
if ( F_14 ( V_43 ) ) {
F_252 ( V_427 , L_61 ) ;
V_249 = F_3 ( V_431 ) ;
V_423 = F_125 ( V_249 , 23 , 16 ) ;
F_252 ( V_427 , L_56 ,
( F_244 () / V_423 ) , V_423 ) ;
}
F_251 ( V_427 , V_145 ) ;
if ( F_14 ( V_30 ) )
F_251 ( V_427 , V_146 ) ;
if ( F_14 ( V_33 ) )
F_251 ( V_427 , V_147 ) ;
F_64 () ;
}
static void F_256 ( struct V_426 * V_427 )
{
int V_21 , V_22 ;
const char * V_432 [] = {
[ V_145 ] = L_62 ,
[ V_36 ] = L_63 ,
[ V_146 ] = L_64 ,
[ V_147 ] = L_65 ,
} ;
const char * V_433 [] = {
[ V_39 ] = L_66 ,
[ V_142 ] = L_67 ,
[ V_143 ] = L_68 ,
[ V_144 ] = L_69 ,
[ V_62 ] = L_70 ,
} ;
const char * * V_434 ;
#define F_257 ( V_47 ) seq_printf(s, "%-50s %08x\n", #r, dispc_read_reg(r))
if ( F_61 () )
return;
F_257 ( V_435 ) ;
F_257 ( V_436 ) ;
F_257 ( V_437 ) ;
F_257 ( V_438 ) ;
F_257 ( V_439 ) ;
F_257 ( V_17 ) ;
F_257 ( V_18 ) ;
F_257 ( V_440 ) ;
F_257 ( V_441 ) ;
F_257 ( V_442 ) ;
if ( F_14 ( V_27 ) ||
F_14 ( V_28 ) )
F_257 ( V_112 ) ;
if ( F_14 ( V_30 ) ) {
F_257 ( V_59 ) ;
F_257 ( V_443 ) ;
}
if ( F_14 ( V_33 ) ) {
F_257 ( V_444 ) ;
F_257 ( V_445 ) ;
}
if ( F_14 ( V_446 ) )
F_257 ( V_199 ) ;
#undef F_257
#define F_258 ( V_21 , V_58 ) name(i)
#define F_257 ( V_21 , V_47 ) seq_printf(s, "%s(%s)%*s %08x\n", #r, p_names[i], \
(int)(48 - strlen(#r) - strlen(p_names[i])), " ", \
dispc_read_reg(DISPC_REG(i, r)))
V_434 = V_432 ;
for ( V_21 = 0 ; V_21 < F_15 () ; V_21 ++ ) {
F_257 ( V_21 , F_221 ) ;
F_257 ( V_21 , F_223 ) ;
F_257 ( V_21 , F_142 ) ;
if ( V_21 == V_36 )
continue;
F_257 ( V_21 , F_237 ) ;
F_257 ( V_21 , F_238 ) ;
F_257 ( V_21 , F_239 ) ;
F_257 ( V_21 , F_243 ) ;
F_257 ( V_21 , V_447 ) ;
F_257 ( V_21 , V_448 ) ;
F_257 ( V_21 , V_449 ) ;
if ( F_14 ( V_37 ) ) {
F_257 ( V_21 , F_136 ) ;
F_257 ( V_21 , F_137 ) ;
F_257 ( V_21 , F_138 ) ;
}
}
V_434 = V_433 ;
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ ) {
F_257 ( V_21 , F_98 ) ;
F_257 ( V_21 , F_100 ) ;
F_257 ( V_21 , F_106 ) ;
F_257 ( V_21 , F_108 ) ;
F_257 ( V_21 , F_75 ) ;
F_257 ( V_21 , F_150 ) ;
F_257 ( V_21 , F_146 ) ;
F_257 ( V_21 , F_118 ) ;
F_257 ( V_21 , F_116 ) ;
if ( F_14 ( V_38 ) )
F_257 ( V_21 , F_151 ) ;
if ( F_14 ( V_446 ) )
F_257 ( V_21 , F_156 ) ;
if ( V_21 == V_39 ) {
F_257 ( V_21 , V_450 ) ;
F_257 ( V_21 , V_451 ) ;
continue;
}
F_257 ( V_21 , F_159 ) ;
F_257 ( V_21 , F_109 ) ;
F_257 ( V_21 , F_162 ) ;
F_257 ( V_21 , F_164 ) ;
if ( F_14 ( V_41 ) ) {
F_257 ( V_21 , F_102 ) ;
F_257 ( V_21 , F_104 ) ;
F_257 ( V_21 , F_160 ) ;
F_257 ( V_21 , F_166 ) ;
F_257 ( V_21 , F_168 ) ;
}
if ( F_14 ( V_42 ) )
F_257 ( V_21 , F_173 ) ;
}
if ( V_3 . V_52 -> V_98 ) {
V_21 = V_62 ;
F_257 ( V_21 , F_98 ) ;
F_257 ( V_21 , F_100 ) ;
F_257 ( V_21 , F_108 ) ;
F_257 ( V_21 , F_75 ) ;
F_257 ( V_21 , F_150 ) ;
F_257 ( V_21 , F_146 ) ;
F_257 ( V_21 , F_118 ) ;
F_257 ( V_21 , F_116 ) ;
if ( F_14 ( V_446 ) )
F_257 ( V_21 , F_156 ) ;
F_257 ( V_21 , F_159 ) ;
F_257 ( V_21 , F_109 ) ;
F_257 ( V_21 , F_162 ) ;
F_257 ( V_21 , F_164 ) ;
if ( F_14 ( V_41 ) ) {
F_257 ( V_21 , F_102 ) ;
F_257 ( V_21 , F_104 ) ;
F_257 ( V_21 , F_160 ) ;
F_257 ( V_21 , F_166 ) ;
F_257 ( V_21 , F_168 ) ;
}
if ( F_14 ( V_42 ) )
F_257 ( V_21 , F_173 ) ;
}
#undef F_258
#undef F_257
#define F_258 ( V_61 , V_58 , V_21 ) name(plane, i)
#define F_257 ( V_61 , V_58 , V_21 ) \
seq_printf(s, "%s_%d(%s)%*s %08x\n", #name, i, p_names[plane], \
(int)(46 - strlen(#name) - strlen(p_names[plane])), " ", \
dispc_read_reg(DISPC_REG(plane, name, i)))
for ( V_21 = 1 ; V_21 < F_29 () ; V_21 ++ ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_257 ( V_21 , F_78 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_257 ( V_21 , F_80 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_257 ( V_21 , F_95 , V_22 ) ;
if ( F_14 ( V_40 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_257 ( V_21 , F_82 , V_22 ) ;
}
if ( F_14 ( V_41 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_257 ( V_21 , F_85 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_257 ( V_21 , F_87 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_257 ( V_21 , F_89 , V_22 ) ;
}
}
F_64 () ;
#undef F_258
#undef F_257
}
int F_259 ( unsigned long F_244 ,
struct V_452 * V_420 )
{
if ( V_420 -> V_413 > 255 || V_420 -> V_413 == 0 )
return - V_287 ;
if ( V_420 -> V_414 < 1 || V_420 -> V_414 > 255 )
return - V_287 ;
V_420 -> V_453 = F_244 / V_420 -> V_413 ;
V_420 -> V_454 = V_420 -> V_453 / V_420 -> V_414 ;
return 0 ;
}
bool F_260 ( unsigned long V_3 ,
unsigned long V_455 , unsigned long V_456 ,
T_9 V_457 , void * V_458 )
{
int V_459 , V_460 , V_461 ;
int V_462 , V_463 , V_464 ;
unsigned long V_454 , V_453 ;
unsigned long V_465 ;
unsigned long V_466 , V_467 ;
unsigned V_468 ;
unsigned long V_469 ;
#ifdef F_261
V_468 = F_261 ;
#else
V_468 = 0 ;
#endif
V_466 = F_262 ( V_470 ) ;
V_467 = F_192 ( V_470 ) ;
V_465 = F_192 ( V_471 ) ;
V_455 = V_455 ? V_455 : 1 ;
V_456 = V_456 ? V_456 : V_472 ;
V_460 = F_184 ( F_182 ( V_3 , V_465 ) , 1ul ) ;
V_461 = F_152 ( V_3 / V_455 , 255ul ) ;
for ( V_459 = V_460 ; V_459 <= V_461 ; ++ V_459 ) {
V_453 = V_3 / V_459 ;
V_463 = F_184 ( F_182 ( V_453 , V_456 ) , V_466 ) ;
V_464 = F_152 ( V_453 / V_455 , V_467 ) ;
for ( V_462 = V_463 ; V_462 <= V_464 ; ++ V_462 ) {
V_454 = V_453 / V_462 ;
if ( F_14 ( V_43 ) )
V_469 = F_193 () ;
else
V_469 = V_453 ;
if ( V_469 < V_454 * V_468 )
continue;
if ( V_457 ( V_459 , V_462 , V_453 , V_454 , V_458 ) )
return true ;
}
}
return false ;
}
void F_231 ( enum V_5 V_6 ,
const struct V_452 * V_420 )
{
F_12 ( L_71 , V_420 -> V_453 , V_420 -> V_413 ) ;
F_12 ( L_72 , V_420 -> V_454 , V_420 -> V_414 ) ;
F_242 ( V_6 , V_420 -> V_413 , V_420 -> V_414 ) ;
}
int F_263 ( enum V_5 V_6 ,
struct V_452 * V_420 )
{
unsigned long V_469 ;
V_469 = F_244 () ;
V_420 -> V_413 = F_6 ( F_243 ( V_6 ) , 23 , 16 ) ;
V_420 -> V_414 = F_6 ( F_243 ( V_6 ) , 7 , 0 ) ;
V_420 -> V_453 = V_469 / V_420 -> V_413 ;
V_420 -> V_454 = V_420 -> V_453 / V_420 -> V_414 ;
return 0 ;
}
T_2 F_264 ( void )
{
return F_3 ( V_438 ) ;
}
void F_60 ( T_2 V_407 )
{
F_1 ( V_438 , V_407 ) ;
}
T_2 F_265 ( void )
{
return F_3 ( V_439 ) ;
}
void F_266 ( T_2 V_407 )
{
T_2 V_473 = F_3 ( V_439 ) ;
F_60 ( ( V_407 ^ V_473 ) & V_407 ) ;
F_1 ( V_439 , V_407 ) ;
}
void F_267 ( void )
{
F_9 ( V_436 , 2 , 4 , 3 ) ;
}
void F_268 ( void )
{
F_9 ( V_436 , 1 , 4 , 3 ) ;
}
static void F_269 ( void )
{
T_2 V_249 ;
if ( F_14 ( V_43 ) ) {
V_249 = F_3 ( V_431 ) ;
V_249 = F_123 ( V_249 , 1 , 0 , 0 ) ;
V_249 = F_123 ( V_249 , 1 , 23 , 16 ) ;
F_1 ( V_431 , V_249 ) ;
V_3 . V_415 = F_244 () ;
}
if ( F_14 ( V_474 ) )
F_9 ( V_18 , 1 , 9 , 9 ) ;
F_96 () ;
F_219 ( V_475 ) ;
F_143 () ;
F_128 () ;
F_112 () ;
if ( V_3 . V_52 -> V_476 )
F_9 ( V_477 , 1 , 0 , 0 ) ;
if ( F_14 ( V_446 ) )
F_157 () ;
}
static int F_270 ( struct V_478 * V_48 )
{
const struct V_479 * V_480 ;
struct V_479 * V_481 ;
V_481 = F_271 ( & V_48 -> V_49 , sizeof( * V_481 ) , V_482 ) ;
if ( ! V_481 ) {
F_272 ( & V_48 -> V_49 , L_73 ) ;
return - V_483 ;
}
switch ( F_273 () ) {
case V_484 :
V_480 = & V_485 ;
break;
case V_486 :
V_480 = & V_487 ;
break;
case V_488 :
case V_489 :
case V_490 :
case V_491 :
V_480 = & V_492 ;
break;
case V_493 :
case V_494 :
case V_495 :
V_480 = & V_496 ;
break;
case V_497 :
case V_498 :
V_480 = & V_499 ;
break;
default:
return - V_500 ;
}
memcpy ( V_481 , V_480 , sizeof( * V_481 ) ) ;
V_3 . V_52 = V_481 ;
return 0 ;
}
static T_10 F_274 ( int V_501 , void * V_502 )
{
if ( ! V_3 . V_503 )
return V_504 ;
return V_3 . V_505 ( V_501 , V_3 . V_506 ) ;
}
int F_275 ( T_11 V_507 , void * V_508 )
{
int V_47 ;
if ( V_3 . V_505 != NULL )
return - V_509 ;
V_3 . V_505 = V_507 ;
V_3 . V_506 = V_508 ;
F_276 () ;
V_47 = F_277 ( & V_3 . V_48 -> V_49 , V_3 . V_501 , F_274 ,
V_510 , L_74 , & V_3 ) ;
if ( V_47 ) {
V_3 . V_505 = NULL ;
V_3 . V_506 = NULL ;
}
return V_47 ;
}
void F_278 ( void * V_508 )
{
F_279 ( & V_3 . V_48 -> V_49 , V_3 . V_501 , & V_3 ) ;
V_3 . V_505 = NULL ;
V_3 . V_506 = NULL ;
}
static int F_280 ( struct V_511 * V_49 , struct V_511 * V_512 , void * V_458 )
{
struct V_478 * V_48 = F_281 ( V_49 ) ;
T_2 V_513 ;
int V_47 = 0 ;
struct V_514 * V_515 ;
struct V_516 * V_517 = V_48 -> V_49 . V_518 ;
V_3 . V_48 = V_48 ;
F_282 ( & V_3 . V_20 ) ;
V_47 = F_270 ( V_3 . V_48 ) ;
if ( V_47 )
return V_47 ;
V_515 = F_283 ( V_3 . V_48 , V_519 , 0 ) ;
if ( ! V_515 ) {
F_76 ( L_75 ) ;
return - V_287 ;
}
V_3 . V_4 = F_284 ( & V_48 -> V_49 , V_515 -> V_174 ,
F_285 ( V_515 ) ) ;
if ( ! V_3 . V_4 ) {
F_76 ( L_76 ) ;
return - V_483 ;
}
V_3 . V_501 = F_286 ( V_3 . V_48 , 0 ) ;
if ( V_3 . V_501 < 0 ) {
F_76 ( L_77 ) ;
return - V_500 ;
}
if ( V_517 && F_287 ( V_517 , L_78 ) ) {
V_3 . V_406 = F_288 ( V_517 , L_78 ) ;
if ( F_289 ( V_3 . V_406 ) ) {
F_272 ( & V_48 -> V_49 , L_79 ) ;
return F_290 ( V_3 . V_406 ) ;
}
if ( F_291 ( V_517 , L_78 , 1 ,
& V_3 . V_408 ) ) {
F_272 ( & V_48 -> V_49 , L_80 ) ;
return - V_287 ;
}
}
F_292 ( & V_48 -> V_49 ) ;
V_47 = F_61 () ;
if ( V_47 )
goto V_520;
F_269 () ;
V_513 = F_3 ( V_435 ) ;
F_293 ( & V_48 -> V_49 , L_81 ,
F_125 ( V_513 , 7 , 4 ) , F_125 ( V_513 , 3 , 0 ) ) ;
F_64 () ;
F_294 () ;
F_295 ( L_82 , F_256 ) ;
return 0 ;
V_520:
F_296 ( & V_48 -> V_49 ) ;
return V_47 ;
}
static void F_297 ( struct V_511 * V_49 , struct V_511 * V_512 ,
void * V_458 )
{
F_296 ( V_49 ) ;
F_298 () ;
}
static int F_299 ( struct V_478 * V_48 )
{
return F_300 ( & V_48 -> V_49 , & V_521 ) ;
}
static int F_301 ( struct V_478 * V_48 )
{
F_302 ( & V_48 -> V_49 , & V_521 ) ;
return 0 ;
}
static int F_303 ( struct V_511 * V_49 )
{
V_3 . V_503 = false ;
F_276 () ;
F_304 ( V_3 . V_501 ) ;
F_11 () ;
return 0 ;
}
static int F_305 ( struct V_511 * V_49 )
{
if ( F_6 ( V_18 , 2 , 1 ) != V_475 ) {
F_269 () ;
F_58 () ;
}
V_3 . V_503 = true ;
F_276 () ;
return 0 ;
}
int T_12 F_306 ( void )
{
return F_307 ( & V_522 ) ;
}
void F_308 ( void )
{
F_309 ( & V_522 ) ;
}
