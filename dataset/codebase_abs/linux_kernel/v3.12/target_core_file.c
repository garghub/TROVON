static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_6 ( L_2
L_3 , V_5 -> V_12 , V_13 ,
V_14 ) ;
F_6 ( L_4
L_5 ,
V_5 -> V_12 , V_7 -> V_10 , V_15 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_6 ( L_6
L_7 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static struct V_2 * F_9 ( struct V_4 * V_5 , const char * V_16 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_1 ) {
F_5 ( L_8 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
F_6 ( L_9 , V_16 ) ;
return & V_1 -> V_3 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
struct V_17 * V_17 ;
struct V_18 * V_18 = NULL ;
int V_19 , V_20 = - V_21 ;
if ( ! ( V_1 -> V_22 & V_23 ) ) {
F_5 ( L_10 ) ;
return - V_21 ;
}
V_19 = V_24 | V_25 | V_26 | V_27 ;
if ( V_1 -> V_22 & V_28 ) {
F_6 ( L_11 ) ;
V_19 &= ~ V_27 ;
}
V_17 = F_11 ( V_1 -> V_29 , V_19 , 0600 ) ;
if ( F_12 ( V_17 ) ) {
F_5 ( L_12 , V_1 -> V_29 ) ;
V_20 = F_13 ( V_17 ) ;
goto V_30;
}
V_1 -> V_31 = V_17 ;
V_18 = V_17 -> V_32 -> V_33 ;
if ( F_14 ( V_18 -> V_34 ) ) {
struct V_35 * V_36 = F_15 ( V_18 -> V_37 ) ;
unsigned long long V_38 ;
V_1 -> V_39 = F_16 ( V_18 -> V_37 ) ;
V_38 = ( F_17 ( V_17 -> V_32 -> V_33 ) -
V_1 -> V_39 ) ;
F_6 ( L_13
L_14 ,
V_38 , F_18 ( V_38 , V_1 -> V_39 ) ,
V_1 -> V_39 ) ;
if ( F_19 ( V_36 ) ) {
V_3 -> V_40 . V_41 =
V_36 -> V_42 . V_43 ;
V_3 -> V_40 . V_44 = 1 ;
V_3 -> V_40 . V_45 =
V_36 -> V_42 . V_46 >> 9 ;
V_3 -> V_40 . V_47 =
V_36 -> V_42 . V_48 ;
F_6 ( L_15
L_16 ) ;
}
V_3 -> V_40 . V_49 = 0xFFFF ;
if ( F_20 ( V_36 ) )
V_3 -> V_40 . V_50 = 1 ;
} else {
if ( ! ( V_1 -> V_22 & V_51 ) ) {
F_5 ( L_17
L_18
L_19 ) ;
goto V_30;
}
V_1 -> V_39 = V_52 ;
V_3 -> V_40 . V_41 = 0x2000 ;
V_3 -> V_40 . V_44 = 1 ;
V_3 -> V_40 . V_45 = 1 ;
V_3 -> V_40 . V_47 = 0 ;
V_3 -> V_40 . V_49 = 0x1000 ;
}
V_3 -> V_40 . V_53 = V_1 -> V_39 ;
V_3 -> V_40 . V_54 = V_15 ;
V_3 -> V_40 . V_55 = V_56 ;
if ( V_1 -> V_22 & V_28 ) {
F_6 ( L_20
L_21 ) ;
V_3 -> V_40 . V_57 = 1 ;
}
V_1 -> V_58 = V_7 -> V_59 ++ ;
V_1 -> V_60 = V_3 -> V_61 ;
F_6 ( L_22
L_23 , V_7 -> V_10 , V_1 -> V_58 ,
V_1 -> V_29 , V_1 -> V_62 ) ;
return 0 ;
V_30:
if ( V_1 -> V_31 ) {
F_21 ( V_1 -> V_31 , NULL ) ;
V_1 -> V_31 = NULL ;
}
return V_20 ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_31 ) {
F_21 ( V_1 -> V_31 , NULL ) ;
V_1 -> V_31 = NULL ;
}
F_8 ( V_1 ) ;
}
static int F_23 ( struct V_63 * V_64 , struct V_65 * V_66 ,
T_1 V_67 , int V_68 )
{
struct V_2 * V_69 = V_64 -> V_69 ;
struct V_1 * V_3 = F_1 ( V_69 ) ;
struct V_17 * V_70 = V_3 -> V_31 ;
struct V_65 * V_71 ;
struct V_72 * V_73 ;
T_2 V_74 ;
T_3 V_75 = ( V_64 -> V_76 * V_69 -> V_40 . V_77 ) ;
int V_20 = 0 , V_78 ;
V_73 = F_4 ( sizeof( struct V_72 ) * V_67 , V_8 ) ;
if ( ! V_73 ) {
F_5 ( L_24 ) ;
return - V_9 ;
}
F_24 (sgl, sg, sgl_nents, i) {
V_73 [ V_78 ] . V_79 = V_71 -> V_80 ;
V_73 [ V_78 ] . V_81 = F_25 ( F_26 ( V_71 ) ) + V_71 -> V_82 ;
}
V_74 = F_27 () ;
F_28 ( F_29 () ) ;
if ( V_68 )
V_20 = F_30 ( V_70 , & V_73 [ 0 ] , V_67 , & V_75 ) ;
else
V_20 = F_31 ( V_70 , & V_73 [ 0 ] , V_67 , & V_75 ) ;
F_28 ( V_74 ) ;
F_24 (sgl, sg, sgl_nents, i)
F_32 ( F_26 ( V_71 ) ) ;
F_8 ( V_73 ) ;
if ( V_68 ) {
if ( V_20 < 0 || V_20 != V_64 -> V_83 ) {
F_5 ( L_25 , V_84 , V_20 ) ;
return ( V_20 < 0 ? V_20 : - V_21 ) ;
}
} else {
if ( F_14 ( F_33 ( V_70 ) -> V_34 ) ) {
if ( V_20 < 0 || V_20 != V_64 -> V_83 ) {
F_5 ( L_26
L_27 , V_84 , V_20 ,
V_64 -> V_83 ) ;
return ( V_20 < 0 ? V_20 : - V_21 ) ;
}
} else {
if ( V_20 < 0 ) {
F_5 ( L_28 ,
V_84 , V_20 ) ;
return V_20 ;
}
}
}
return 1 ;
}
static T_4
F_34 ( struct V_63 * V_64 )
{
struct V_2 * V_3 = V_64 -> V_69 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_85 = ( V_64 -> V_86 [ 1 ] & 0x2 ) ;
T_3 V_87 , V_88 ;
int V_20 ;
if ( V_85 )
F_35 ( V_64 , V_89 ) ;
if ( V_64 -> V_76 == 0 && V_64 -> V_83 == 0 ) {
V_87 = 0 ;
V_88 = V_90 ;
} else {
V_87 = V_64 -> V_76 * V_3 -> V_40 . V_77 ;
if ( V_64 -> V_83 )
V_88 = V_87 + V_64 -> V_83 ;
else
V_88 = V_90 ;
}
V_20 = F_36 ( V_1 -> V_31 , V_87 , V_88 , 1 ) ;
if ( V_20 != 0 )
F_5 ( L_29 , V_20 ) ;
if ( V_85 )
return 0 ;
if ( V_20 )
F_35 ( V_64 , V_91 ) ;
else
F_35 ( V_64 , V_89 ) ;
return 0 ;
}
static unsigned char *
F_37 ( struct V_63 * V_64 , struct V_65 * V_71 ,
unsigned int V_92 )
{
struct V_2 * V_69 = V_64 -> V_69 ;
unsigned int V_77 = V_69 -> V_40 . V_77 ;
unsigned int V_78 = 0 , V_88 ;
unsigned char * V_93 , * V_94 , * V_95 ;
V_93 = F_4 ( F_38 (unsigned int, len, PAGE_SIZE) , V_8 ) ;
if ( ! V_93 ) {
F_5 ( L_30 ) ;
return NULL ;
}
V_95 = F_25 ( F_26 ( V_71 ) ) + V_71 -> V_82 ;
if ( ! V_95 ) {
F_5 ( L_31 ) ;
F_8 ( V_93 ) ;
return NULL ;
}
V_94 = V_93 ;
V_88 = F_38 (unsigned int, len, PAGE_SIZE) ;
while ( V_78 < V_88 ) {
memcpy ( V_94 , V_95 , V_77 ) ;
V_78 += V_77 ;
V_94 += V_77 ;
}
F_32 ( F_26 ( V_71 ) ) ;
return V_93 ;
}
static T_4
F_39 ( struct V_63 * V_64 )
{
struct V_2 * V_69 = V_64 -> V_69 ;
struct V_1 * V_1 = F_1 ( V_69 ) ;
struct V_17 * V_96 = V_1 -> V_31 ;
struct V_65 * V_71 ;
struct V_72 * V_73 ;
T_2 V_74 ;
T_5 V_97 = F_40 ( V_64 ) ;
T_3 V_75 = V_64 -> V_76 * V_69 -> V_40 . V_77 ;
unsigned int V_92 , V_98 , V_99 ;
int V_78 , V_100 ;
unsigned char * V_93 ;
if ( ! V_97 ) {
F_35 ( V_64 , V_89 ) ;
return 0 ;
}
V_71 = & V_64 -> V_101 [ 0 ] ;
if ( V_64 -> V_102 > 1 ||
V_71 -> V_80 != V_64 -> V_69 -> V_40 . V_77 ) {
F_5 ( L_32
L_33 , V_64 -> V_102 , V_71 -> V_80 ,
V_64 -> V_69 -> V_40 . V_77 ) ;
return V_103 ;
}
V_92 = V_98 = V_97 * V_69 -> V_40 . V_77 ;
V_99 = F_41 ( V_92 , V_104 ) ;
V_93 = F_37 ( V_64 , V_71 , V_92 ) ;
if ( ! V_93 )
return V_105 ;
V_73 = F_42 ( sizeof( struct V_72 ) * V_99 ) ;
if ( ! V_73 ) {
F_5 ( L_34 ) ;
F_8 ( V_93 ) ;
return V_105 ;
}
for ( V_78 = 0 ; V_78 < V_99 ; V_78 ++ ) {
V_73 [ V_78 ] . V_81 = V_93 ;
V_73 [ V_78 ] . V_79 = F_38 (unsigned int, len_tmp, PAGE_SIZE) ;
V_98 -= V_73 [ V_78 ] . V_79 ;
}
V_74 = F_27 () ;
F_28 ( F_29 () ) ;
V_100 = F_30 ( V_96 , & V_73 [ 0 ] , V_99 , & V_75 ) ;
F_28 ( V_74 ) ;
F_43 ( V_73 ) ;
F_8 ( V_93 ) ;
if ( V_100 < 0 || V_100 != V_92 ) {
F_5 ( L_35 , V_100 ) ;
return V_105 ;
}
F_35 ( V_64 , V_89 ) ;
return 0 ;
}
static T_4
F_44 ( struct V_63 * V_64 , void * V_106 , T_5 V_107 , T_5 V_97 )
{
struct V_17 * V_17 = V_106 ;
struct V_18 * V_18 = V_17 -> V_32 -> V_33 ;
int V_20 ;
if ( F_14 ( V_18 -> V_34 ) ) {
struct V_108 * V_109 = V_18 -> V_37 ;
V_20 = F_45 ( V_109 , V_107 ,
V_97 , V_8 , 0 ) ;
if ( V_20 < 0 ) {
F_46 ( L_36 ,
V_20 ) ;
return V_105 ;
}
} else {
struct V_2 * V_69 = V_64 -> V_69 ;
T_3 V_75 = V_107 * V_69 -> V_40 . V_77 ;
unsigned int V_92 = V_97 * V_69 -> V_40 . V_77 ;
int V_110 = V_111 | V_112 ;
if ( ! V_17 -> V_113 -> V_114 )
return V_105 ;
V_20 = V_17 -> V_113 -> V_114 ( V_17 , V_110 , V_75 , V_92 ) ;
if ( V_20 < 0 ) {
F_46 ( L_37 , V_20 ) ;
return V_105 ;
}
}
return 0 ;
}
static T_4
F_47 ( struct V_63 * V_64 )
{
struct V_2 * V_69 = V_64 -> V_69 ;
struct V_1 * V_1 = F_1 ( V_69 ) ;
struct V_17 * V_17 = V_1 -> V_31 ;
T_5 V_107 = V_64 -> V_76 ;
T_5 V_97 = F_40 ( V_64 ) ;
int V_20 ;
if ( ! V_97 ) {
F_35 ( V_64 , V_89 ) ;
return 0 ;
}
V_20 = F_44 ( V_64 , V_17 , V_107 , V_97 ) ;
if ( V_20 )
return V_20 ;
F_35 ( V_64 , V_115 ) ;
return 0 ;
}
static T_4
F_48 ( struct V_63 * V_64 )
{
struct V_17 * V_17 = F_1 ( V_64 -> V_69 ) -> V_31 ;
return F_49 ( V_64 , F_44 , V_17 ) ;
}
static T_4
F_50 ( struct V_63 * V_64 , struct V_65 * V_66 , T_1 V_67 ,
enum V_116 V_117 )
{
struct V_2 * V_3 = V_64 -> V_69 ;
int V_20 = 0 ;
if ( V_117 == V_118 ) {
V_20 = F_23 ( V_64 , V_66 , V_67 , 0 ) ;
} else {
V_20 = F_23 ( V_64 , V_66 , V_67 , 1 ) ;
if ( V_20 > 0 &&
V_3 -> V_40 . V_119 > 0 &&
( V_64 -> V_120 & V_121 ) ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_87 = V_64 -> V_76 *
V_3 -> V_40 . V_77 ;
T_3 V_88 = V_87 + V_64 -> V_83 ;
F_36 ( V_1 -> V_31 , V_87 , V_88 , 1 ) ;
}
}
if ( V_20 < 0 )
return V_105 ;
if ( V_20 )
F_35 ( V_64 , V_89 ) ;
return 0 ;
}
static T_6 F_51 ( struct V_2 * V_3 ,
const char * V_122 , T_6 V_123 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_124 , * V_125 , * V_126 , * V_127 ;
T_7 args [ V_128 ] ;
int V_20 = 0 , V_129 , V_130 ;
V_127 = F_52 ( V_122 , V_8 ) ;
if ( ! V_127 )
return - V_9 ;
V_124 = V_127 ;
while ( ( V_125 = F_53 ( & V_127 , L_38 ) ) != NULL ) {
if ( ! * V_125 )
continue;
V_130 = F_54 ( V_125 , V_131 , args ) ;
switch ( V_130 ) {
case V_132 :
if ( F_55 ( V_1 -> V_29 , & args [ 0 ] ,
V_133 ) == 0 ) {
V_20 = - V_21 ;
break;
}
F_6 ( L_39 ,
V_1 -> V_29 ) ;
V_1 -> V_22 |= V_23 ;
break;
case V_134 :
V_126 = F_56 ( & args [ 0 ] ) ;
if ( ! V_126 ) {
V_20 = - V_9 ;
break;
}
V_20 = F_57 ( V_126 , 0 , & V_1 -> V_62 ) ;
F_8 ( V_126 ) ;
if ( V_20 < 0 ) {
F_5 ( L_40
L_41 ) ;
goto V_135;
}
F_6 ( L_42
L_43 , V_1 -> V_62 ) ;
V_1 -> V_22 |= V_51 ;
break;
case V_136 :
F_58 ( args , & V_129 ) ;
if ( V_129 != 1 ) {
F_5 ( L_44 , V_129 ) ;
V_20 = - V_21 ;
goto V_135;
}
F_6 ( L_45
L_46 ) ;
V_1 -> V_22 |= V_28 ;
break;
default:
break;
}
}
V_135:
F_8 ( V_124 ) ;
return ( ! V_20 ) ? V_123 : V_20 ;
}
static T_6 F_59 ( struct V_2 * V_3 , char * V_137 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_6 V_138 = 0 ;
V_138 = sprintf ( V_137 + V_138 , L_47 , V_1 -> V_58 ) ;
V_138 += sprintf ( V_137 + V_138 , L_48 ,
V_1 -> V_29 , V_1 -> V_62 ,
( V_1 -> V_22 & V_28 ) ?
L_49 : L_50 ) ;
return V_138 ;
}
static T_5 F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_96 = V_1 -> V_31 ;
struct V_18 * V_78 = V_96 -> V_32 -> V_33 ;
unsigned long long V_38 ;
if ( F_14 ( V_78 -> V_34 ) )
V_38 = F_17 ( V_78 ) ;
else
V_38 = V_1 -> V_62 ;
return F_18 ( V_38 - V_3 -> V_40 . V_77 ,
V_3 -> V_40 . V_77 ) ;
}
static T_4
F_61 ( struct V_63 * V_64 )
{
return F_62 ( V_64 , & V_139 ) ;
}
static int T_8 F_63 ( void )
{
return F_64 ( & V_140 ) ;
}
static void T_9 F_65 ( void )
{
F_66 ( & V_140 ) ;
}
