static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
unsigned int V_6 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_4 = F_2 ( V_2 -> V_8 , V_3 , & V_6 ) ;
if ( V_4 == - V_9 )
continue;
else
break;
}
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_1 , V_4 ) ;
return V_4 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
int V_4 ;
V_4 = F_5 ( V_2 -> V_8 , V_3 , ( unsigned int ) V_6 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_12 [ 2 ] ;
int V_4 ;
V_4 = F_7 ( V_2 -> V_8 , V_3 , V_12 , 2 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_3 , V_4 ) ;
return V_4 ;
}
V_4 = F_8 ( V_12 ) ;
if ( ! ( V_4 & V_13 ) ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_4 ,
V_3 ) ;
return - V_14 ;
}
return V_4 & V_15 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_12 [ 2 ] ;
int V_4 ;
V_4 = F_7 ( V_2 -> V_8 , V_3 , V_12 , 2 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_3 , V_4 ) ;
return V_4 ;
}
return ( V_12 [ 0 ] << 4 ) | ( ( V_12 [ 1 ] >> 4 ) & 0x0f ) ;
}
static int F_10 ( const char * V_16 , int * V_17 ,
struct V_1 * V_2 )
{
int V_4 , V_6 = 0 ;
struct V_18 * V_19 ;
V_19 = F_11 ( NULL , V_16 ) ;
if ( F_12 ( V_19 ) ) {
V_4 = F_13 ( V_19 ) ;
goto exit;
}
V_4 = F_14 ( V_19 , & V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_5 , V_4 , V_6 ) ;
goto V_20;
}
F_15 ( & V_2 -> V_10 -> V_11 , L_6 , V_6 ) ;
* V_17 = V_6 ;
V_20:
F_16 ( V_19 ) ;
exit:
return V_4 ;
}
static int F_17 ( struct V_21 * V_22 , void * V_23 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
int V_17 , V_4 ;
F_18 ( V_22 , L_7 ,
V_25 ,
F_1 ( V_2 , V_25 ) ) ;
F_18 ( V_22 , L_8 ,
V_26 ,
F_1 ( V_2 , V_26 ) ) ;
F_18 ( V_22 , L_9 ,
V_27 ,
F_1 ( V_2 , V_27 ) ) ;
F_18 ( V_22 , L_10 ,
V_28 ,
F_1 ( V_2 , V_28 ) ) ;
F_18 ( V_22 , L_11 ,
V_29 ,
F_1 ( V_2 , V_29 ) ) ;
F_18 ( V_22 , L_12 ,
V_30 ,
F_1 ( V_2 , V_30 ) ) ;
F_18 ( V_22 , L_13 ,
V_31 ,
F_1 ( V_2 , V_31 ) ) ;
F_18 ( V_22 , L_14 ,
V_32 ,
F_1 ( V_2 , V_32 ) ) ;
F_18 ( V_22 , L_15 ,
V_33 ,
F_1 ( V_2 , V_33 ) ) ;
F_18 ( V_22 , L_16 ,
V_34 ,
F_9 ( V_2 , V_34 ) ) ;
F_18 ( V_22 , L_17 ,
V_35 ,
F_6 ( V_2 , V_35 ) ) ;
F_18 ( V_22 , L_18 ,
V_36 ,
F_6 ( V_2 , V_36 ) ) ;
F_18 ( V_22 , L_19 ,
V_37 ,
F_1 ( V_2 , V_37 ) ) ;
F_18 ( V_22 , L_20 ,
V_38 ,
F_1 ( V_2 , V_38 ) ) ;
F_18 ( V_22 , L_21 ,
V_39 ,
F_1 ( V_2 , V_39 ) ) ;
F_18 ( V_22 , L_22 ,
V_40 ,
F_1 ( V_2 , V_40 ) ) ;
F_18 ( V_22 , L_23 ,
V_41 ,
F_1 ( V_2 , V_41 ) ) ;
F_18 ( V_22 , L_24 ,
V_42 ,
F_1 ( V_2 , V_42 ) ) ;
F_18 ( V_22 , L_25 ,
V_43 ,
F_1 ( V_2 , V_43 ) ) ;
F_18 ( V_22 , L_26 ,
V_44 ,
F_1 ( V_2 , V_44 ) ) ;
F_18 ( V_22 , L_27 ,
V_45 ,
F_1 ( V_2 , V_45 ) ) ;
V_4 = F_10 ( L_28 , & V_17 , V_2 ) ;
if ( V_4 >= 0 )
F_18 ( V_22 , L_29 , V_17 ) ;
V_4 = F_10 ( L_30 , & V_17 , V_2 ) ;
if ( V_4 >= 0 )
F_18 ( V_22 , L_31 , V_17 ) ;
V_4 = F_10 ( L_32 , & V_17 , V_2 ) ;
if ( V_4 >= 0 )
F_18 ( V_22 , L_33 , V_17 ) ;
V_4 = F_10 ( L_34 , & V_17 , V_2 ) ;
if ( V_4 >= 0 )
F_18 ( V_22 , L_35 , V_17 ) ;
V_4 = F_10 ( L_36 , & V_17 , V_2 ) ;
if ( V_4 >= 0 )
F_18 ( V_22 , L_37 , V_17 ) ;
V_4 = F_10 ( L_38 , & V_17 , V_2 ) ;
if ( V_4 >= 0 )
F_18 ( V_22 , L_39 , V_17 ) ;
return 0 ;
}
static int F_19 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_20 ( V_47 , F_17 , V_46 -> V_48 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_49 = F_22 ( L_40 , 0666 , NULL ,
V_2 , & V_50 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_49 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
}
static inline void F_23 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
int V_51 , V_4 ;
int V_52 , V_53 ;
V_51 = F_1 ( V_2 , V_25 ) ;
if ( V_51 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_41 , V_51 ) ;
return;
}
V_4 = F_10 ( L_34 , & V_52 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_42 , V_4 ) ;
return;
}
V_4 = F_10 ( L_36 , & V_53 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_43 , V_4 ) ;
return;
}
if ( V_52 > 0 )
V_2 -> V_54 = V_55 ;
else if ( V_53 > 0 )
V_2 -> V_54 = V_56 ;
else {
if ( V_51 & V_57 )
V_2 -> V_54 = V_58 ;
else
V_2 -> V_54 = V_59 ;
}
}
static int F_26 ( struct V_1 * V_2 , int * V_60 )
{
int V_4 = 0 , V_17 ;
V_4 = F_10 ( L_38 , & V_17 , V_2 ) ;
if ( V_4 < 0 )
goto V_61;
* V_60 = F_27 ( V_17 ) ;
V_61:
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 , int * V_62 )
{
int V_4 , V_63 = 0 ;
int V_52 , V_53 ;
V_4 = F_10 ( L_34 , & V_52 , V_2 ) ;
if ( V_4 < 0 )
goto V_64;
V_4 = F_10 ( L_36 , & V_53 , V_2 ) ;
if ( V_4 < 0 )
goto V_64;
if ( V_52 > 0 )
V_63 = V_52 ;
else if ( V_53 > 0 )
V_63 = - 1 * V_53 ;
* V_62 = V_63 ;
V_64:
return V_4 ;
}
static int F_29 ( struct V_1 * V_2 , int * V_65 )
{
int V_4 ;
V_4 = F_9 ( V_2 , V_34 ) ;
if ( V_4 >= 0 )
* V_65 = F_27 ( V_4 ) ;
return V_4 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_4 , V_65 , V_66 = V_67 ;
V_4 = F_29 ( V_2 , & V_65 ) ;
if ( V_4 < 0 )
goto V_68;
if ( V_65 > V_2 -> V_69 )
V_66 = V_70 ;
else
V_66 = V_71 ;
V_68:
return V_66 ;
}
static int F_31 ( struct V_72 * V_73 ,
enum V_74 V_75 ,
union V_76 * V_6 )
{
struct V_1 * V_2 = F_32 ( V_73 ) ;
int V_4 = 0 , V_63 ;
F_33 ( & V_2 -> V_77 ) ;
switch ( V_75 ) {
case V_78 :
F_25 ( V_2 ) ;
V_6 -> V_79 = V_2 -> V_54 ;
break;
case V_80 :
V_6 -> V_79 = F_30 ( V_2 ) ;
break;
case V_81 :
V_4 = F_26 ( V_2 , & V_63 ) ;
if ( V_4 < 0 )
goto V_82;
V_6 -> V_79 = F_34 ( V_63 ) ;
break;
case V_83 :
V_4 = F_29 ( V_2 , & V_63 ) ;
if ( V_4 < 0 )
goto V_82;
V_6 -> V_79 = F_34 ( V_63 ) ;
break;
case V_84 :
V_4 = F_28 ( V_2 , & V_63 ) ;
if ( V_4 < 0 )
goto V_82;
V_6 -> V_79 = F_35 ( V_63 ) ;
break;
case V_85 :
V_4 = F_1 ( V_2 , V_26 ) ;
if ( V_4 < 0 )
goto V_82;
if ( V_4 & V_57 )
V_6 -> V_79 = 1 ;
else
V_6 -> V_79 = 0 ;
break;
case V_86 :
V_4 = F_1 ( V_2 , V_31 ) ;
if ( V_4 < 0 )
goto V_82;
if ( ! ( V_4 & V_87 ) )
F_3 ( & V_2 -> V_10 -> V_11 ,
L_44 ) ;
V_6 -> V_79 = ( V_4 & V_88 ) ;
break;
case V_89 :
V_4 = F_1 ( V_2 , V_39 ) ;
if ( V_4 < 0 )
goto V_82;
V_6 -> V_79 = ( V_4 & 0x0f ) ;
break;
case V_90 :
V_6 -> V_79 = V_91 ;
break;
case V_92 :
V_4 = F_6 ( V_2 , V_36 ) ;
if ( V_4 < 0 )
goto V_82;
V_6 -> V_79 = V_4 * V_93 ;
break;
case V_94 :
V_4 = F_6 ( V_2 , V_35 ) ;
if ( V_4 < 0 )
goto V_82;
V_6 -> V_79 = V_4 * V_93 ;
break;
case V_95 :
V_6 -> V_79 = F_34 ( V_2 -> V_69 ) ;
break;
default:
F_36 ( & V_2 -> V_77 ) ;
return - V_96 ;
}
F_36 ( & V_2 -> V_77 ) ;
return 0 ;
V_82:
F_36 ( & V_2 -> V_77 ) ;
return V_4 ;
}
static int F_37 ( struct V_72 * V_73 ,
enum V_74 V_75 ,
const union V_76 * V_6 )
{
struct V_1 * V_2 = F_32 ( V_73 ) ;
int V_4 = 0 ;
F_33 ( & V_2 -> V_77 ) ;
switch ( V_75 ) {
case V_89 :
if ( ( V_6 -> V_79 < 0 ) || ( V_6 -> V_79 > 15 ) ) {
V_4 = - V_96 ;
break;
}
V_4 = F_1 ( V_2 , V_39 ) ;
if ( V_4 < 0 )
break;
V_4 &= 0xf0 ;
V_4 |= ( V_6 -> V_79 & 0xf ) ;
V_4 = F_4 ( V_2 , V_39 , V_4 ) ;
break;
default:
V_4 = - V_96 ;
break;
}
F_36 ( & V_2 -> V_77 ) ;
return V_4 ;
}
static int F_38 ( struct V_72 * V_97 ,
enum V_74 V_98 )
{
int V_4 ;
switch ( V_98 ) {
case V_89 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
}
return V_4 ;
}
static void F_39 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_40 ( V_100 ,
struct V_1 , V_101 . V_100 ) ;
F_25 ( V_2 ) ;
F_41 ( V_2 -> V_102 ) ;
F_42 ( & V_2 -> V_101 , V_103 ) ;
}
static T_2 F_43 ( int V_104 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
if ( V_2 -> V_104 [ V_5 ] == V_104 )
break;
}
if ( V_5 >= V_105 ) {
F_44 ( & V_2 -> V_10 -> V_11 , L_45 ) ;
return V_106 ;
}
switch ( V_5 ) {
case V_107 :
F_45 ( & V_2 -> V_10 -> V_11 ,
L_46 ) ;
break;
case V_108 :
F_45 ( & V_2 -> V_10 -> V_11 ,
L_47 ) ;
break;
case V_109 :
F_45 ( & V_2 -> V_10 -> V_11 ,
L_48 ) ;
break;
case V_110 :
F_45 ( & V_2 -> V_10 -> V_11 ,
L_49 ) ;
break;
case V_111 :
F_45 ( & V_2 -> V_10 -> V_11 , L_50 ) ;
break;
case V_112 :
F_45 ( & V_2 -> V_10 -> V_11 , L_51 ) ;
break;
default:
F_44 ( & V_2 -> V_10 -> V_11 , L_52 ) ;
}
F_41 ( V_2 -> V_102 ) ;
return V_113 ;
}
static void F_46 ( struct V_72 * V_97 )
{
struct V_1 * V_2 = F_32 ( V_97 ) ;
F_41 ( V_2 -> V_102 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_4 , V_5 , V_114 ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
V_114 = F_48 ( V_2 -> V_10 , V_5 ) ;
V_2 -> V_104 [ V_5 ] = F_49 ( V_2 -> V_115 , V_114 ) ;
if ( V_2 -> V_104 [ V_5 ] < 0 ) {
F_44 ( & V_2 -> V_10 -> V_11 ,
L_53 ,
V_114 , V_2 -> V_104 [ V_5 ] ) ;
V_2 -> V_104 [ V_5 ] = - 1 ;
goto V_116;
}
V_4 = F_50 ( V_2 -> V_104 [ V_5 ] ,
NULL , F_43 ,
V_117 , V_118 , V_2 ) ;
if ( V_4 ) {
F_44 ( & V_2 -> V_10 -> V_11 ,
L_54 ,
V_114 , V_2 -> V_104 [ V_5 ] ) ;
V_2 -> V_104 [ V_5 ] = - 1 ;
goto V_116;
} else {
F_45 ( & V_2 -> V_10 -> V_11 , L_55 ,
V_114 , V_2 -> V_104 [ V_5 ] ) ;
}
}
return;
V_116:
for (; V_5 > 0 ; V_5 -- ) {
F_51 ( V_2 -> V_104 [ V_5 - 1 ] , V_2 ) ;
V_2 -> V_104 [ V_5 - 1 ] = - 1 ;
}
}
static int F_52 ( struct V_119 * V_10 )
{
int V_4 = 0 ;
struct V_1 * V_2 ;
struct V_120 * V_121 = F_53 ( V_10 -> V_11 . V_122 ) ;
struct V_123 V_124 = {} ;
V_2 = F_54 ( & V_10 -> V_11 , sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_8 = V_121 -> V_8 ;
V_2 -> V_115 = V_121 -> V_115 ;
V_2 -> V_54 = V_127 ;
F_55 ( V_10 , V_2 ) ;
F_56 ( & V_2 -> V_77 ) ;
F_57 ( & V_2 -> V_101 , F_39 ) ;
V_4 = F_1 ( V_2 , V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_128 ) ) {
F_3 ( & V_10 -> V_11 , L_56 ) ;
return - V_129 ;
}
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( ( V_4 & V_130 ) >> V_131 ) {
case V_132 :
V_2 -> V_69 = 4100 ;
break;
case V_133 :
V_2 -> V_69 = 4150 ;
break;
case V_134 :
V_2 -> V_69 = 4200 ;
break;
case V_135 :
V_2 -> V_69 = 4350 ;
break;
}
V_124 . V_136 = V_2 ;
V_2 -> V_102 = F_58 ( & V_10 -> V_11 , & V_137 , & V_124 ) ;
if ( F_59 ( V_2 -> V_102 ) ) {
V_4 = F_13 ( V_2 -> V_102 ) ;
F_3 ( & V_10 -> V_11 , L_57 , V_4 ) ;
return V_4 ;
}
F_21 ( V_2 ) ;
F_47 ( V_2 ) ;
F_42 ( & V_2 -> V_101 , V_103 ) ;
return 0 ;
}
static int F_60 ( struct V_119 * V_10 )
{
struct V_1 * V_2 = F_61 ( V_10 ) ;
int V_5 ;
F_62 ( & V_2 -> V_101 ) ;
F_63 ( V_2 -> V_102 ) ;
F_23 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ )
if ( V_2 -> V_104 [ V_5 ] >= 0 )
F_51 ( V_2 -> V_104 [ V_5 ] , V_2 ) ;
return 0 ;
}
