static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_1 ;
F_2 ( & V_3 ) ;
V_1 = F_3 ( & V_4 , V_2 ) ;
if ( V_1 ) {
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 ) {
F_4 ( & V_1 -> V_5 ) ;
V_1 = NULL ;
} else {
F_5 ( & V_1 -> V_7 ) ;
F_4 ( & V_1 -> V_5 ) ;
}
}
F_4 ( & V_3 ) ;
return V_1 ;
}
static int F_6 ( struct V_1 * V_1 )
{
int V_2 ;
F_2 ( & V_3 ) ;
V_2 = F_7 ( & V_4 , V_1 , 0 , V_8 , V_9 ) ;
F_4 ( & V_3 ) ;
return V_2 ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_2 ( & V_3 ) ;
F_9 ( & V_4 , V_1 -> V_2 ) ;
F_4 ( & V_3 ) ;
}
static int F_10 ( struct V_1 * V_1 , int V_10 , int V_11 ,
void * V_12 , int V_13 )
{
int V_14 ;
V_14 = F_11 ( V_1 -> V_15 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( V_1 -> V_16 , F_13 ( V_1 -> V_16 , 0 ) ,
V_10 , V_17 , V_11 ,
V_1 -> V_15 -> V_18 [ 0 ] . V_19 . V_20 ,
V_12 , V_13 , 5000 ) ;
F_14 ( & V_1 -> V_15 -> V_16 ,
L_1 ,
V_21 , V_10 , V_11 , V_13 , V_14 ) ;
F_15 ( V_1 -> V_15 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static inline int F_16 ( struct V_1 * V_1 , int V_15 )
{
if ( V_1 -> V_22 & V_23 )
return - V_24 ;
return F_10 ( V_1 , V_25 ,
V_15 , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_26 , V_27 ;
struct V_28 * V_29 ;
V_27 = 0 ;
V_26 = 0 ;
for (; ; ) {
V_29 = & V_1 -> V_29 [ V_27 ] ;
if ( ! V_29 -> V_30 ) {
V_29 -> V_30 = 1 ;
return V_27 ;
}
V_27 = ( V_27 + 1 ) % V_31 ;
if ( ++ V_26 >= V_31 )
return - 1 ;
}
}
static int F_18 ( struct V_1 * V_1 )
{
int V_26 , V_32 ;
unsigned long V_33 ;
V_32 = V_31 ;
F_19 ( & V_1 -> V_34 , V_33 ) ;
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ )
V_32 -= V_1 -> V_29 [ V_26 ] . V_30 ;
F_20 ( & V_1 -> V_34 , V_33 ) ;
return V_32 ;
}
static void F_21 ( struct V_1 * V_1 , struct V_28 * V_29 )
{
V_29 -> V_30 = 0 ;
V_1 -> V_35 -- ;
F_22 ( V_1 -> V_15 ) ;
}
static int F_23 ( struct V_1 * V_1 , struct V_28 * V_29 )
{
int V_36 ;
V_1 -> V_35 ++ ;
V_29 -> V_37 -> V_38 = V_29 -> V_12 ;
V_29 -> V_37 -> V_39 = V_29 -> V_40 ;
V_29 -> V_37 -> V_41 = V_29 -> V_13 ;
V_29 -> V_37 -> V_16 = V_1 -> V_16 ;
V_36 = F_24 ( V_29 -> V_37 , V_42 ) ;
if ( V_36 < 0 ) {
F_25 ( & V_1 -> V_43 -> V_16 ,
L_2 ,
V_21 , V_36 ) ;
F_21 ( V_1 , V_29 ) ;
}
return V_36 ;
}
static T_1 F_26
( struct V_44 * V_16 , struct V_45 * V_46 , char * V_12 )
{
struct V_47 * V_48 = F_27 ( V_16 ) ;
struct V_1 * V_1 = F_28 ( V_48 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_49 ) ;
}
static T_1 F_29
( struct V_44 * V_16 , struct V_45 * V_46 , char * V_12 )
{
struct V_47 * V_48 = F_27 ( V_16 ) ;
struct V_1 * V_1 = F_28 ( V_48 ) ;
memcpy ( V_12 , V_1 -> V_50 , V_1 -> V_51 ) ;
return V_1 -> V_51 ;
}
static T_1 F_30
( struct V_44 * V_16 , struct V_45 * V_46 , char * V_12 )
{
struct V_47 * V_48 = F_27 ( V_16 ) ;
struct V_1 * V_1 = F_28 ( V_48 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_52 ) ;
}
static void F_31 ( struct V_37 * V_37 )
{
struct V_1 * V_1 = V_37 -> V_53 ;
struct V_54 * V_55 = V_37 -> V_38 ;
unsigned char * V_43 ;
int V_56 ;
int V_57 ;
int V_14 ;
int V_58 = V_37 -> V_58 ;
switch ( V_58 ) {
case 0 :
break;
case - V_59 :
case - V_60 :
case - V_61 :
F_14 ( & V_1 -> V_15 -> V_16 ,
L_4 ,
V_21 , V_58 ) ;
return;
default:
F_14 ( & V_1 -> V_15 -> V_16 ,
L_5 ,
V_21 , V_58 ) ;
goto exit;
}
F_32 ( V_1 -> V_16 ) ;
V_43 = ( unsigned char * ) ( V_55 + 1 ) ;
switch ( V_55 -> V_62 ) {
case V_63 :
F_14 ( & V_1 -> V_15 -> V_16 , L_6 ,
V_21 , V_55 -> V_64 ) ;
break;
case V_65 :
V_56 = F_33 ( V_43 ) ;
if ( ! V_1 -> V_66 && ( V_1 -> V_67 & ~ V_56 & V_68 ) ) {
F_14 ( & V_1 -> V_15 -> V_16 , L_7 ,
V_21 ) ;
F_34 ( & V_1 -> V_7 , false ) ;
}
V_57 = V_1 -> V_67 ^ V_56 ;
F_35 ( & V_1 -> V_69 ) ;
V_1 -> V_67 = V_56 ;
V_1 -> V_70 = V_1 -> V_71 ;
if ( V_57 & V_72 )
V_1 -> V_71 . V_73 ++ ;
if ( V_57 & V_74 )
V_1 -> V_71 . V_75 ++ ;
if ( V_57 & V_76 )
V_1 -> V_71 . V_77 ++ ;
if ( V_57 & V_68 )
V_1 -> V_71 . V_78 ++ ;
if ( V_57 & V_79 )
V_1 -> V_71 . V_80 ++ ;
if ( V_57 & V_81 )
V_1 -> V_71 . V_82 ++ ;
if ( V_57 & V_83 )
V_1 -> V_71 . V_84 ++ ;
F_36 ( & V_1 -> V_69 ) ;
if ( V_57 )
F_37 ( & V_1 -> V_85 ) ;
break;
default:
F_14 ( & V_1 -> V_15 -> V_16 ,
L_8
L_9 ,
V_21 ,
V_55 -> V_62 , V_55 -> V_86 ,
V_55 -> V_87 , V_43 [ 0 ] , V_43 [ 1 ] ) ;
break;
}
exit:
V_14 = F_24 ( V_37 , V_42 ) ;
if ( V_14 && V_14 != - V_88 )
F_25 ( & V_1 -> V_15 -> V_16 , L_10 ,
V_21 , V_14 ) ;
}
static int F_38 ( struct V_1 * V_1 , int V_89 , T_2 V_90 )
{
int V_91 ;
if ( ! F_39 ( V_89 , & V_1 -> V_92 ) )
return 0 ;
F_40 ( & V_1 -> V_43 -> V_16 , L_11 , V_21 , V_89 ) ;
V_91 = F_24 ( V_1 -> V_93 [ V_89 ] , V_90 ) ;
if ( V_91 ) {
if ( V_91 != - V_88 ) {
F_25 ( & V_1 -> V_43 -> V_16 ,
L_10 ,
V_21 , V_91 ) ;
}
F_41 ( V_89 , & V_1 -> V_92 ) ;
return V_91 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , T_2 V_90 )
{
int V_91 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1 -> V_94 ; ++ V_26 ) {
V_91 = F_38 ( V_1 , V_26 , V_90 ) ;
if ( V_91 )
return V_91 ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_1 , struct V_37 * V_37 )
{
if ( ! V_37 -> V_95 )
return;
F_44 ( & V_1 -> V_7 , V_37 -> V_38 ,
V_37 -> V_95 ) ;
F_45 ( & V_1 -> V_7 ) ;
}
static void F_46 ( struct V_37 * V_37 )
{
struct V_96 * V_97 = V_37 -> V_53 ;
struct V_1 * V_1 = V_97 -> V_98 ;
unsigned long V_33 ;
int V_58 = V_37 -> V_58 ;
F_40 ( & V_1 -> V_43 -> V_16 , L_12 , V_21 ,
V_97 -> V_89 , V_37 -> V_95 ) ;
if ( ! V_1 -> V_16 ) {
F_41 ( V_97 -> V_89 , & V_1 -> V_92 ) ;
F_14 ( & V_1 -> V_43 -> V_16 , L_13 , V_21 ) ;
return;
}
if ( V_58 ) {
F_41 ( V_97 -> V_89 , & V_1 -> V_92 ) ;
F_14 ( & V_1 -> V_43 -> V_16 , L_14 ,
V_21 , V_58 ) ;
if ( ( V_58 != - V_60 ) || ( V_37 -> V_95 == 0 ) )
return;
}
F_32 ( V_1 -> V_16 ) ;
F_43 ( V_1 , V_37 ) ;
F_47 () ;
F_41 ( V_97 -> V_89 , & V_1 -> V_92 ) ;
F_19 ( & V_1 -> V_69 , V_33 ) ;
V_1 -> V_99 = V_1 -> V_100 ;
if ( ! V_1 -> V_99 ) {
F_20 ( & V_1 -> V_69 , V_33 ) ;
F_38 ( V_1 , V_97 -> V_89 , V_42 ) ;
} else {
F_20 ( & V_1 -> V_69 , V_33 ) ;
}
}
static void F_48 ( struct V_37 * V_37 )
{
struct V_28 * V_29 = V_37 -> V_53 ;
struct V_1 * V_1 = V_29 -> V_98 ;
unsigned long V_33 ;
int V_58 = V_37 -> V_58 ;
if ( V_58 || ( V_37 -> V_95 != V_37 -> V_41 ) )
F_40 ( & V_1 -> V_43 -> V_16 , L_15 ,
V_21 ,
V_37 -> V_95 ,
V_37 -> V_41 ,
V_58 ) ;
F_19 ( & V_1 -> V_34 , V_33 ) ;
F_21 ( V_1 , V_29 ) ;
F_20 ( & V_1 -> V_34 , V_33 ) ;
F_49 ( & V_1 -> V_101 ) ;
}
static void F_50 ( struct V_102 * V_101 )
{
struct V_1 * V_1 = F_51 ( V_101 , struct V_1 , V_101 ) ;
F_40 ( & V_1 -> V_43 -> V_16 , L_16 , V_21 ) ;
F_52 ( & V_1 -> V_7 ) ;
}
static int F_53 ( struct V_103 * V_104 , struct V_105 * V_106 )
{
struct V_1 * V_1 ;
int V_14 ;
F_14 ( V_106 -> V_16 , L_16 , V_21 ) ;
V_1 = F_1 ( V_106 -> V_89 ) ;
if ( ! V_1 )
return - V_107 ;
V_14 = F_54 ( V_104 , V_106 ) ;
if ( V_14 )
goto V_108;
V_106 -> V_109 = V_1 ;
return 0 ;
V_108:
F_55 ( & V_1 -> V_7 ) ;
return V_14 ;
}
static int F_56 ( struct V_105 * V_106 , struct V_110 * V_111 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
F_14 ( V_106 -> V_16 , L_16 , V_21 ) ;
return F_57 ( & V_1 -> V_7 , V_106 , V_111 ) ;
}
static void F_58 ( struct V_112 * V_7 , int raise )
{
struct V_1 * V_1 = F_51 ( V_7 , struct V_1 , V_7 ) ;
int V_113 ;
int V_91 ;
if ( raise )
V_113 = V_114 | V_115 ;
else
V_113 = 0 ;
V_1 -> V_116 = V_113 ;
V_91 = F_16 ( V_1 , V_113 ) ;
if ( V_91 && ( V_1 -> V_49 & V_117 ) )
F_25 ( & V_1 -> V_15 -> V_16 , L_17 ) ;
}
static int F_59 ( struct V_112 * V_7 , struct V_105 * V_106 )
{
struct V_1 * V_1 = F_51 ( V_7 , struct V_1 , V_7 ) ;
int V_14 = - V_107 ;
int V_26 ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
goto V_6;
V_14 = F_11 ( V_1 -> V_15 ) ;
if ( V_14 )
goto V_118;
F_41 ( V_119 , & V_106 -> V_33 ) ;
V_1 -> V_15 -> V_120 = 1 ;
V_1 -> V_121 -> V_16 = V_1 -> V_16 ;
V_14 = F_24 ( V_1 -> V_121 , V_9 ) ;
if ( V_14 ) {
F_25 ( & V_1 -> V_15 -> V_16 ,
L_18 , V_21 ) ;
goto V_122;
}
F_60 ( V_106 , NULL ) ;
F_61 ( & V_1 -> V_69 ) ;
V_1 -> V_99 = 0 ;
V_1 -> V_100 = 0 ;
F_62 ( & V_1 -> V_69 ) ;
V_14 = F_42 ( V_1 , V_9 ) ;
if ( V_14 )
goto V_123;
F_15 ( V_1 -> V_15 ) ;
F_4 ( & V_1 -> V_5 ) ;
return 0 ;
V_123:
for ( V_26 = 0 ; V_26 < V_1 -> V_94 ; V_26 ++ )
F_63 ( V_1 -> V_93 [ V_26 ] ) ;
F_63 ( V_1 -> V_121 ) ;
V_122:
F_15 ( V_1 -> V_15 ) ;
V_118:
V_6:
F_4 ( & V_1 -> V_5 ) ;
return F_64 ( V_14 ) ;
}
static void F_65 ( struct V_112 * V_7 )
{
struct V_1 * V_1 = F_51 ( V_7 , struct V_1 , V_7 ) ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_8 ( V_1 ) ;
F_66 ( V_1 -> V_15 ) ;
F_67 ( V_1 -> V_50 ) ;
F_67 ( V_1 ) ;
}
static void F_68 ( struct V_112 * V_7 )
{
struct V_1 * V_1 = F_51 ( V_7 , struct V_1 , V_7 ) ;
struct V_37 * V_37 ;
struct V_28 * V_29 ;
int V_26 ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_61 ( & V_1 -> V_34 ) ;
F_62 ( & V_1 -> V_34 ) ;
F_69 ( V_1 -> V_15 ) ;
V_1 -> V_15 -> V_120 = 0 ;
F_15 ( V_1 -> V_15 ) ;
for (; ; ) {
V_37 = F_70 ( & V_1 -> V_124 ) ;
if ( ! V_37 )
break;
V_29 = V_37 -> V_53 ;
V_29 -> V_30 = 0 ;
F_22 ( V_1 -> V_15 ) ;
}
F_63 ( V_1 -> V_121 ) ;
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ )
F_63 ( V_1 -> V_29 [ V_26 ] . V_37 ) ;
for ( V_26 = 0 ; V_26 < V_1 -> V_94 ; V_26 ++ )
F_63 ( V_1 -> V_93 [ V_26 ] ) ;
}
static void F_71 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_55 ( & V_1 -> V_7 ) ;
}
static void F_72 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_73 ( & V_1 -> V_7 ) ;
}
static void F_74 ( struct V_105 * V_106 , struct V_110 * V_111 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_75 ( & V_1 -> V_7 , V_106 , V_111 ) ;
}
static int F_76 ( struct V_105 * V_106 ,
const unsigned char * V_12 , int V_125 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
int V_126 ;
unsigned long V_33 ;
int V_27 ;
struct V_28 * V_29 ;
if ( ! V_125 )
return 0 ;
F_40 ( & V_1 -> V_43 -> V_16 , L_19 , V_21 , V_125 ) ;
F_19 ( & V_1 -> V_34 , V_33 ) ;
V_27 = F_17 ( V_1 ) ;
if ( V_27 < 0 ) {
F_20 ( & V_1 -> V_34 , V_33 ) ;
return 0 ;
}
V_29 = & V_1 -> V_29 [ V_27 ] ;
if ( ! V_1 -> V_16 ) {
V_29 -> V_30 = 0 ;
F_20 ( & V_1 -> V_34 , V_33 ) ;
return - V_107 ;
}
V_125 = ( V_125 > V_1 -> V_127 ) ? V_1 -> V_127 : V_125 ;
F_40 ( & V_1 -> V_43 -> V_16 , L_20 , V_21 , V_125 ) ;
memcpy ( V_29 -> V_12 , V_12 , V_125 ) ;
V_29 -> V_13 = V_125 ;
V_126 = F_77 ( V_1 -> V_15 ) ;
if ( V_126 ) {
V_29 -> V_30 = 0 ;
F_20 ( & V_1 -> V_34 , V_33 ) ;
return V_126 ;
}
if ( V_1 -> V_128 ) {
if ( V_1 -> V_129 ) {
F_78 ( V_1 -> V_129 -> V_37 , & V_1 -> V_124 ) ;
V_1 -> V_129 = NULL ;
}
F_78 ( V_29 -> V_37 , & V_1 -> V_124 ) ;
F_20 ( & V_1 -> V_34 , V_33 ) ;
return V_125 ;
} else {
if ( V_1 -> V_129 ) {
F_23 ( V_1 , V_1 -> V_129 ) ;
V_1 -> V_129 = NULL ;
}
}
V_126 = F_23 ( V_1 , V_29 ) ;
F_20 ( & V_1 -> V_34 , V_33 ) ;
if ( V_126 < 0 )
return V_126 ;
return V_125 ;
}
static void F_79 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
struct V_28 * V_130 = V_1 -> V_129 ;
int V_131 ;
unsigned long V_33 ;
if ( ! V_130 )
return;
V_1 -> V_129 = NULL ;
V_131 = F_77 ( V_1 -> V_15 ) ;
F_19 ( & V_1 -> V_34 , V_33 ) ;
if ( V_131 < 0 ) {
V_130 -> V_30 = 0 ;
V_1 -> V_129 = V_130 ;
goto V_132;
}
if ( V_1 -> V_128 )
F_78 ( V_130 -> V_37 , & V_1 -> V_124 ) ;
else
F_23 ( V_1 , V_130 ) ;
V_132:
F_20 ( & V_1 -> V_34 , V_33 ) ;
return;
}
static int F_80 ( struct V_105 * V_106 , unsigned char V_133 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
struct V_28 * V_130 ;
int V_27 ;
unsigned long V_33 ;
V_134:
V_130 = V_1 -> V_129 ;
if ( ! V_130 ) {
F_19 ( & V_1 -> V_34 , V_33 ) ;
V_27 = F_17 ( V_1 ) ;
if ( V_27 >= 0 ) {
V_130 = & V_1 -> V_29 [ V_27 ] ;
V_1 -> V_129 = V_130 ;
}
F_20 ( & V_1 -> V_34 , V_33 ) ;
if ( ! V_130 )
return 0 ;
}
if ( V_130 -> V_13 == V_1 -> V_127 ) {
F_79 ( V_106 ) ;
goto V_134;
}
V_130 -> V_12 [ V_130 -> V_13 ++ ] = V_133 ;
return 1 ;
}
static int F_81 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
return F_18 ( V_1 ) ? V_1 -> V_127 : 0 ;
}
static int F_82 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
if ( V_1 -> V_6 )
return 0 ;
return ( V_31 - F_18 ( V_1 ) ) * V_1 -> V_127 ;
}
static void F_83 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
F_61 ( & V_1 -> V_69 ) ;
V_1 -> V_100 = 1 ;
F_62 ( & V_1 -> V_69 ) ;
}
static void F_84 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
unsigned int V_135 ;
F_61 ( & V_1 -> V_69 ) ;
V_135 = V_1 -> V_99 ;
V_1 -> V_99 = 0 ;
V_1 -> V_100 = 0 ;
F_62 ( & V_1 -> V_69 ) ;
if ( V_135 )
F_42 ( V_1 , V_9 ) ;
}
static int F_85 ( struct V_105 * V_106 , int V_136 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
int V_14 ;
V_14 = F_86 ( V_1 , V_136 ? 0xffff : 0 ) ;
if ( V_14 < 0 )
F_14 ( & V_1 -> V_15 -> V_16 , L_21 ,
V_21 ) ;
return V_14 ;
}
static int F_87 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
return ( V_1 -> V_116 & V_114 ? V_137 : 0 ) |
( V_1 -> V_116 & V_115 ? V_138 : 0 ) |
( V_1 -> V_67 & V_72 ? V_139 : 0 ) |
( V_1 -> V_67 & V_76 ? V_140 : 0 ) |
( V_1 -> V_67 & V_68 ? V_141 : 0 ) |
V_142 ;
}
static int F_88 ( struct V_105 * V_106 ,
unsigned int V_143 , unsigned int V_144 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
unsigned int V_56 ;
V_56 = V_1 -> V_116 ;
V_143 = ( V_143 & V_137 ? V_114 : 0 ) |
( V_143 & V_138 ? V_115 : 0 ) ;
V_144 = ( V_144 & V_137 ? V_114 : 0 ) |
( V_144 & V_138 ? V_115 : 0 ) ;
V_56 = ( V_56 & ~ V_144 ) | V_143 ;
if ( V_1 -> V_116 == V_56 )
return 0 ;
return F_16 ( V_1 , V_1 -> V_116 = V_56 ) ;
}
static int F_89 ( struct V_1 * V_1 , struct V_145 T_3 * V_146 )
{
struct V_145 V_147 ;
if ( ! V_146 )
return - V_148 ;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_33 = V_149 ;
V_147 . V_150 = V_1 -> V_127 ;
V_147 . V_151 = F_90 ( V_1 -> line . V_152 ) ;
V_147 . V_153 = V_1 -> V_7 . V_153 / 10 ;
V_147 . V_154 = V_1 -> V_7 . V_154 == V_155 ?
V_155 :
V_1 -> V_7 . V_154 / 10 ;
if ( F_91 ( V_146 , & V_147 , sizeof( V_147 ) ) )
return - V_156 ;
else
return 0 ;
}
static int F_92 ( struct V_1 * V_1 ,
struct V_145 T_3 * V_157 )
{
struct V_145 V_158 ;
unsigned int V_154 , V_153 ;
int V_14 = 0 ;
if ( F_93 ( & V_158 , V_157 , sizeof( V_158 ) ) )
return - V_156 ;
V_153 = V_158 . V_153 * 10 ;
V_154 = V_158 . V_154 == V_155 ?
V_155 : V_158 . V_154 * 10 ;
F_2 ( & V_1 -> V_7 . V_5 ) ;
if ( ! F_94 ( V_159 ) ) {
if ( ( V_153 != V_1 -> V_7 . V_153 ) ||
( V_154 != V_1 -> V_7 . V_154 ) )
V_14 = - V_88 ;
else
V_14 = - V_24 ;
} else {
V_1 -> V_7 . V_153 = V_153 ;
V_1 -> V_7 . V_154 = V_154 ;
}
F_4 ( & V_1 -> V_7 . V_5 ) ;
return V_14 ;
}
static int F_95 ( struct V_1 * V_1 , unsigned long V_160 )
{
int V_161 = 0 ;
F_96 ( V_162 , V_163 ) ;
struct V_164 V_165 , V_166 ;
if ( V_160 & ( V_139 | V_140 | V_141 ) )
return - V_148 ;
do {
F_61 ( & V_1 -> V_69 ) ;
V_165 = V_1 -> V_70 ;
V_166 = V_1 -> V_71 ;
V_1 -> V_70 = V_166 ;
F_62 ( & V_1 -> V_69 ) ;
if ( ( V_160 & V_139 ) &&
V_165 . V_73 != V_166 . V_73 )
break;
if ( ( V_160 & V_141 ) &&
V_165 . V_78 != V_166 . V_78 )
break;
if ( ( V_160 & V_140 ) &&
V_165 . V_77 != V_166 . V_77 )
break;
F_97 ( & V_1 -> V_85 , & V_162 ) ;
F_98 ( V_167 ) ;
F_99 () ;
F_100 ( & V_1 -> V_85 , & V_162 ) ;
if ( V_1 -> V_6 ) {
if ( V_160 & V_141 )
break;
else
V_161 = - V_107 ;
} else {
if ( F_101 ( V_163 ) )
V_161 = - V_168 ;
}
} while ( ! V_161 );
return V_161 ;
}
static int F_102 ( struct V_1 * V_1 ,
struct V_169 T_3 * V_125 )
{
struct V_169 V_170 ;
int V_161 = 0 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_73 = V_1 -> V_71 . V_73 ;
V_170 . V_77 = V_1 -> V_71 . V_77 ;
V_170 . V_78 = V_1 -> V_71 . V_78 ;
V_170 . V_80 = V_1 -> V_71 . V_80 ;
V_170 . V_84 = V_1 -> V_71 . V_84 ;
V_170 . V_82 = V_1 -> V_71 . V_82 ;
V_170 . V_75 = V_1 -> V_71 . V_75 ;
if ( F_91 ( V_125 , & V_170 , sizeof( V_170 ) ) > 0 )
V_161 = - V_156 ;
return V_161 ;
}
static int F_103 ( struct V_105 * V_106 ,
unsigned int V_171 , unsigned long V_160 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
int V_161 = - V_172 ;
switch ( V_171 ) {
case V_173 :
V_161 = F_89 ( V_1 , (struct V_145 T_3 * ) V_160 ) ;
break;
case V_174 :
V_161 = F_92 ( V_1 , (struct V_145 T_3 * ) V_160 ) ;
break;
case V_175 :
V_161 = F_11 ( V_1 -> V_15 ) ;
if ( V_161 < 0 ) {
V_161 = - V_176 ;
break;
}
V_161 = F_95 ( V_1 , V_160 ) ;
F_15 ( V_1 -> V_15 ) ;
break;
case V_177 :
V_161 = F_102 ( V_1 , (struct V_169 T_3 * ) V_160 ) ;
break;
}
return V_161 ;
}
static void F_60 ( struct V_105 * V_106 ,
struct V_178 * V_179 )
{
struct V_1 * V_1 = V_106 -> V_109 ;
struct V_178 * V_180 = & V_106 -> V_180 ;
struct V_181 V_182 ;
int V_56 = V_1 -> V_116 ;
V_182 . V_152 = F_104 ( F_105 ( V_106 ) ) ;
V_182 . V_183 = V_180 -> V_184 & V_185 ? 2 : 0 ;
V_182 . V_186 = V_180 -> V_184 & V_187 ?
( V_180 -> V_184 & V_188 ? 1 : 2 ) +
( V_180 -> V_184 & V_189 ? 2 : 0 ) : 0 ;
switch ( V_180 -> V_184 & V_190 ) {
case V_191 :
V_182 . V_192 = 5 ;
break;
case V_193 :
V_182 . V_192 = 6 ;
break;
case V_194 :
V_182 . V_192 = 7 ;
break;
case V_195 :
default:
V_182 . V_192 = 8 ;
break;
}
V_1 -> V_66 = ( ( V_180 -> V_184 & V_196 ) != 0 ) ;
if ( F_106 ( V_106 ) == V_197 ) {
V_182 . V_152 = V_1 -> line . V_152 ;
V_56 &= ~ V_114 ;
} else if ( V_179 && ( V_179 -> V_184 & V_198 ) == V_197 ) {
V_56 |= V_114 ;
}
if ( V_56 != V_1 -> V_116 )
F_16 ( V_1 , V_1 -> V_116 = V_56 ) ;
if ( memcmp ( & V_1 -> line , & V_182 , sizeof V_182 ) ) {
memcpy ( & V_1 -> line , & V_182 , sizeof V_182 ) ;
F_14 ( & V_1 -> V_15 -> V_16 , L_22 ,
V_21 ,
F_90 ( V_182 . V_152 ) ,
V_182 . V_183 , V_182 . V_186 ,
V_182 . V_192 ) ;
F_107 ( V_1 , & V_1 -> line ) ;
}
}
static void F_108 ( struct V_1 * V_1 )
{
int V_26 ;
struct V_28 * V_29 ;
struct V_199 * V_200 = F_109 ( V_1 -> V_15 ) ;
for ( V_29 = & V_1 -> V_29 [ 0 ] , V_26 = 0 ; V_26 < V_31 ; V_26 ++ , V_29 ++ )
F_110 ( V_200 , V_1 -> V_127 , V_29 -> V_12 , V_29 -> V_40 ) ;
}
static void F_111 ( struct V_1 * V_1 )
{
struct V_199 * V_200 = F_109 ( V_1 -> V_15 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1 -> V_94 ; V_26 ++ )
F_110 ( V_200 , V_1 -> V_201 ,
V_1 -> V_202 [ V_26 ] . V_203 , V_1 -> V_202 [ V_26 ] . V_204 ) ;
}
static int F_112 ( struct V_1 * V_1 )
{
int V_26 ;
struct V_28 * V_29 ;
for ( V_29 = & V_1 -> V_29 [ 0 ] , V_26 = 0 ; V_26 < V_31 ; V_26 ++ , V_29 ++ ) {
V_29 -> V_12 = F_113 ( V_1 -> V_16 , V_1 -> V_127 , V_9 ,
& V_29 -> V_40 ) ;
if ( ! V_29 -> V_12 ) {
while ( V_26 != 0 ) {
-- V_26 ;
-- V_29 ;
F_110 ( V_1 -> V_16 , V_1 -> V_127 ,
V_29 -> V_12 , V_29 -> V_40 ) ;
}
return - V_205 ;
}
}
return 0 ;
}
static int F_114 ( struct V_47 * V_48 ,
const struct V_206 * V_207 )
{
struct V_208 * V_209 = NULL ;
struct V_210 * V_211 = NULL ;
unsigned char * V_212 = V_48 -> V_18 -> V_213 ;
int V_214 = V_48 -> V_18 -> V_215 ;
struct V_47 * V_216 ;
struct V_47 * V_217 ;
struct V_218 * V_219 = NULL ;
struct V_218 * V_220 = NULL ;
struct V_218 * V_221 = NULL ;
struct V_199 * V_200 = F_109 ( V_48 ) ;
struct V_222 V_223 ;
struct V_1 * V_1 ;
int V_2 ;
int V_224 , V_201 ;
T_4 * V_12 ;
int V_225 = - 1 ;
int V_226 = - 1 ;
unsigned long V_22 ;
int V_227 ;
int V_26 ;
int V_228 = 0 ;
struct V_44 * V_229 ;
int V_161 = - V_205 ;
V_22 = ( unsigned long ) V_207 -> V_230 ;
if ( V_22 == V_231 )
return - V_107 ;
V_227 = ( V_22 == V_232 ) ? 1 : V_233 ;
if ( V_22 == V_234 ) {
V_217 = F_115 ( V_200 , 1 ) ;
V_216 = F_115 ( V_200 , 0 ) ;
if ( ! V_217 || ! V_216 )
return - V_107 ;
goto V_235;
}
if ( ! V_212 ) {
F_25 ( & V_48 -> V_16 , L_23 ) ;
return - V_148 ;
}
if ( ! V_214 ) {
if ( V_48 -> V_236 -> V_237 &&
V_48 -> V_236 -> V_237 -> V_215 &&
V_48 -> V_236 -> V_237 -> V_213 ) {
F_14 ( & V_48 -> V_16 ,
L_24 ) ;
V_214 = V_48 -> V_236 -> V_237 -> V_215 ;
V_212 = V_48 -> V_236 -> V_237 -> V_213 ;
} else {
F_25 ( & V_48 -> V_16 ,
L_25 ) ;
return - V_148 ;
}
}
F_116 ( & V_223 , V_48 , V_212 , V_214 ) ;
V_209 = V_223 . V_208 ;
V_211 = V_223 . V_210 ;
if ( V_211 )
V_225 = V_211 -> V_238 ;
if ( ! V_209 ) {
if ( V_225 > 0 ) {
F_14 ( & V_48 -> V_16 , L_26 ) ;
if ( V_22 & V_239 ) {
V_217 = F_115 ( V_200 , 0 ) ;
} else {
V_226 = V_225 ;
V_217 = F_115 ( V_200 , V_226 ) ;
}
V_216 = V_48 ;
} else {
if ( V_48 -> V_236 -> V_19 . V_240 != 3 ) {
F_14 ( & V_48 -> V_16 , L_27 ) ;
return - V_107 ;
} else {
F_117 ( & V_48 -> V_16 , L_28 ) ;
V_228 = 1 ;
V_216 = V_217 = V_48 ;
goto V_241;
}
}
} else {
V_226 = V_209 -> V_242 ;
V_216 = F_115 ( V_200 , V_209 -> V_243 ) ;
V_217 = F_115 ( V_200 , V_226 ) ;
}
if ( ! V_216 || ! V_217 ) {
F_14 ( & V_48 -> V_16 , L_29 ) ;
return - V_107 ;
}
if ( V_226 != V_225 )
F_14 ( & V_48 -> V_16 , L_30 ) ;
if ( V_216 == V_217 ) {
F_117 ( & V_48 -> V_16 , L_31 ) ;
V_228 = 1 ;
V_22 |= V_244 ;
if ( V_217 -> V_236 -> V_19 . V_240 != 3 ) {
F_25 ( & V_48 -> V_16 , L_32 ) ;
return - V_148 ;
}
V_241:
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
struct V_218 * V_245 ;
V_245 = & V_217 -> V_236 -> V_237 [ V_26 ] . V_19 ;
if ( F_118 ( V_245 ) )
V_219 = V_245 ;
else if ( F_119 ( V_245 ) )
V_221 = V_245 ;
else if ( F_120 ( V_245 ) )
V_220 = V_245 ;
else
return - V_148 ;
}
if ( ! V_219 || ! V_220 || ! V_221 )
return - V_107 ;
else
goto V_246;
}
V_235:
if ( V_217 -> V_236 -> V_19 . V_247
!= V_248 ) {
if ( V_216 -> V_236 -> V_19 . V_247
== V_248 ) {
F_14 ( & V_48 -> V_16 ,
L_33 ) ;
F_121 ( V_216 , V_217 ) ;
} else {
return - V_148 ;
}
}
if ( ! V_228 && V_48 != V_216 )
return - V_107 ;
if ( ! V_228 && F_122 ( V_217 ) ) {
F_14 ( & V_48 -> V_16 , L_34 ) ;
return - V_249 ;
}
if ( V_217 -> V_236 -> V_19 . V_240 < 2 ||
V_216 -> V_236 -> V_19 . V_240 == 0 )
return - V_148 ;
V_219 = & V_216 -> V_236 -> V_237 [ 0 ] . V_19 ;
V_220 = & V_217 -> V_236 -> V_237 [ 0 ] . V_19 ;
V_221 = & V_217 -> V_236 -> V_237 [ 1 ] . V_19 ;
if ( ! F_123 ( V_220 ) ) {
F_14 ( & V_48 -> V_16 ,
L_35 ) ;
F_121 ( V_220 , V_221 ) ;
}
V_246:
F_14 ( & V_48 -> V_16 , L_36 ) ;
V_1 = F_124 ( sizeof( struct V_1 ) , V_9 ) ;
if ( V_1 == NULL )
goto V_250;
V_2 = F_6 ( V_1 ) ;
if ( V_2 < 0 )
goto V_251;
V_224 = F_125 ( V_219 ) ;
V_201 = F_125 ( V_220 ) *
( V_22 == V_232 ? 1 : 2 ) ;
V_1 -> V_228 = V_228 ;
V_1 -> V_127 = F_125 ( V_221 ) * 20 ;
V_1 -> V_15 = V_216 ;
V_1 -> V_43 = V_217 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_16 = V_200 ;
if ( V_223 . V_252 )
V_1 -> V_49 = V_223 . V_252 -> V_253 ;
if ( V_22 & V_244 )
V_1 -> V_49 &= ~ V_117 ;
V_1 -> V_224 = V_224 ;
V_1 -> V_201 = V_201 ;
V_1 -> V_94 = V_227 ;
F_126 ( & V_1 -> V_101 , F_50 ) ;
F_127 ( & V_1 -> V_85 ) ;
F_128 ( & V_1 -> V_34 ) ;
F_128 ( & V_1 -> V_69 ) ;
F_129 ( & V_1 -> V_5 ) ;
V_1 -> V_254 = F_130 ( V_220 ) ;
if ( V_1 -> V_254 )
V_1 -> V_255 = V_220 -> V_255 ;
F_131 ( & V_1 -> V_7 ) ;
V_1 -> V_7 . V_256 = & V_257 ;
F_132 ( & V_1 -> V_124 ) ;
V_1 -> V_22 = V_22 ;
V_12 = F_113 ( V_200 , V_224 , V_9 , & V_1 -> V_258 ) ;
if ( ! V_12 )
goto V_259;
V_1 -> V_260 = V_12 ;
if ( F_112 ( V_1 ) < 0 )
goto V_261;
V_1 -> V_121 = F_133 ( 0 , V_9 ) ;
if ( ! V_1 -> V_121 )
goto V_262;
for ( V_26 = 0 ; V_26 < V_227 ; V_26 ++ ) {
struct V_96 * V_97 = & ( V_1 -> V_202 [ V_26 ] ) ;
struct V_37 * V_37 ;
V_97 -> V_203 = F_113 ( V_1 -> V_16 , V_201 , V_9 ,
& V_97 -> V_204 ) ;
if ( ! V_97 -> V_203 )
goto V_263;
V_97 -> V_89 = V_26 ;
V_97 -> V_98 = V_1 ;
V_37 = F_133 ( 0 , V_9 ) ;
if ( ! V_37 )
goto V_263;
V_37 -> V_264 |= V_265 ;
V_37 -> V_39 = V_97 -> V_204 ;
if ( V_1 -> V_254 ) {
F_134 ( V_37 , V_1 -> V_16 ,
F_135 ( V_200 , V_220 -> V_266 ) ,
V_97 -> V_203 ,
V_1 -> V_201 ,
F_46 , V_97 ,
V_1 -> V_255 ) ;
} else {
F_136 ( V_37 , V_1 -> V_16 ,
F_137 ( V_200 , V_220 -> V_266 ) ,
V_97 -> V_203 ,
V_1 -> V_201 ,
F_46 , V_97 ) ;
}
V_1 -> V_93 [ V_26 ] = V_37 ;
F_138 ( V_26 , & V_1 -> V_92 ) ;
}
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ ) {
struct V_28 * V_267 = & ( V_1 -> V_29 [ V_26 ] ) ;
V_267 -> V_37 = F_133 ( 0 , V_9 ) ;
if ( V_267 -> V_37 == NULL )
goto V_268;
if ( F_130 ( V_221 ) )
F_134 ( V_267 -> V_37 , V_200 ,
F_139 ( V_200 , V_221 -> V_266 ) ,
NULL , V_1 -> V_127 , F_48 , V_267 , V_221 -> V_255 ) ;
else
F_136 ( V_267 -> V_37 , V_200 ,
F_140 ( V_200 , V_221 -> V_266 ) ,
NULL , V_1 -> V_127 , F_48 , V_267 ) ;
V_267 -> V_37 -> V_264 |= V_265 ;
if ( V_22 & V_269 )
V_267 -> V_37 -> V_264 |= V_270 ;
V_267 -> V_98 = V_1 ;
}
F_141 ( V_48 , V_1 ) ;
V_26 = F_142 ( & V_48 -> V_16 , & V_271 ) ;
if ( V_26 < 0 )
goto V_268;
if ( V_223 . V_272 ) {
struct V_272 * V_273 =
V_223 . V_272 ;
V_1 -> V_50 = F_143 ( V_273 -> V_274 - 4 , V_9 ) ;
if ( ! V_1 -> V_50 )
goto V_275;
V_1 -> V_51 = V_273 -> V_274 - 4 ;
memcpy ( V_1 -> V_50 , ( T_4 * ) & V_273 -> V_276 ,
V_273 -> V_274 - 4 ) ;
V_1 -> V_52 = V_273 -> V_277 ;
V_26 = F_142 ( & V_48 -> V_16 , & V_278 ) ;
if ( V_26 < 0 ) {
F_67 ( V_1 -> V_50 ) ;
V_1 -> V_50 = NULL ;
V_1 -> V_51 = 0 ;
goto V_275;
}
V_26 = F_142 ( & V_48 -> V_16 ,
& V_279 ) ;
if ( V_26 < 0 ) {
F_144 ( & V_48 -> V_16 , & V_278 ) ;
F_67 ( V_1 -> V_50 ) ;
V_1 -> V_50 = NULL ;
V_1 -> V_51 = 0 ;
goto V_275;
}
}
V_275:
F_134 ( V_1 -> V_121 , V_200 ,
F_135 ( V_200 , V_219 -> V_266 ) ,
V_1 -> V_260 , V_224 , F_31 , V_1 ,
V_219 -> V_255 ? V_219 -> V_255 : 16 ) ;
V_1 -> V_121 -> V_264 |= V_265 ;
V_1 -> V_121 -> V_39 = V_1 -> V_258 ;
F_145 ( & V_48 -> V_16 , L_37 , V_2 ) ;
V_1 -> line . V_152 = F_104 ( 9600 ) ;
V_1 -> line . V_192 = 8 ;
F_107 ( V_1 , & V_1 -> line ) ;
F_146 ( & V_280 , V_217 , V_1 ) ;
F_141 ( V_217 , V_1 ) ;
F_147 ( V_216 ) ;
V_229 = F_148 ( & V_1 -> V_7 , V_281 , V_2 ,
& V_216 -> V_16 ) ;
if ( F_149 ( V_229 ) ) {
V_161 = F_150 ( V_229 ) ;
goto V_282;
}
if ( V_22 & V_283 ) {
F_151 ( V_200 , F_137 ( V_200 , V_220 -> V_266 ) ) ;
F_151 ( V_200 , F_140 ( V_200 , V_221 -> V_266 ) ) ;
}
return 0 ;
V_282:
if ( V_1 -> V_50 ) {
F_144 ( & V_1 -> V_15 -> V_16 ,
& V_278 ) ;
F_144 ( & V_1 -> V_15 -> V_16 ,
& V_279 ) ;
F_67 ( V_1 -> V_50 ) ;
}
F_144 ( & V_1 -> V_15 -> V_16 , & V_271 ) ;
V_268:
F_141 ( V_48 , NULL ) ;
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ )
F_152 ( V_1 -> V_29 [ V_26 ] . V_37 ) ;
V_263:
for ( V_26 = 0 ; V_26 < V_227 ; V_26 ++ )
F_152 ( V_1 -> V_93 [ V_26 ] ) ;
F_111 ( V_1 ) ;
F_152 ( V_1 -> V_121 ) ;
V_262:
F_108 ( V_1 ) ;
V_261:
F_110 ( V_200 , V_224 , V_1 -> V_260 , V_1 -> V_258 ) ;
V_259:
F_8 ( V_1 ) ;
V_251:
F_67 ( V_1 ) ;
V_250:
return V_161 ;
}
static void F_153 ( struct V_1 * V_1 )
{
int V_26 ;
F_14 ( & V_1 -> V_15 -> V_16 , L_16 , V_21 ) ;
F_63 ( V_1 -> V_121 ) ;
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ )
F_63 ( V_1 -> V_29 [ V_26 ] . V_37 ) ;
for ( V_26 = 0 ; V_26 < V_1 -> V_94 ; V_26 ++ )
F_63 ( V_1 -> V_93 [ V_26 ] ) ;
F_154 ( & V_1 -> V_101 ) ;
}
static void F_155 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_28 ( V_48 ) ;
struct V_199 * V_200 = F_109 ( V_48 ) ;
struct V_105 * V_106 ;
int V_26 ;
F_14 ( & V_48 -> V_16 , L_16 , V_21 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = true ;
if ( V_1 -> V_50 ) {
F_144 ( & V_1 -> V_15 -> V_16 ,
& V_278 ) ;
F_144 ( & V_1 -> V_15 -> V_16 ,
& V_279 ) ;
}
F_37 ( & V_1 -> V_85 ) ;
F_144 ( & V_1 -> V_15 -> V_16 , & V_271 ) ;
F_141 ( V_1 -> V_15 , NULL ) ;
F_141 ( V_1 -> V_43 , NULL ) ;
F_4 ( & V_1 -> V_5 ) ;
V_106 = F_156 ( & V_1 -> V_7 ) ;
if ( V_106 ) {
F_157 ( V_106 ) ;
F_158 ( V_106 ) ;
}
F_153 ( V_1 ) ;
F_159 ( V_281 , V_1 -> V_2 ) ;
F_152 ( V_1 -> V_121 ) ;
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ )
F_152 ( V_1 -> V_29 [ V_26 ] . V_37 ) ;
for ( V_26 = 0 ; V_26 < V_1 -> V_94 ; V_26 ++ )
F_152 ( V_1 -> V_93 [ V_26 ] ) ;
F_108 ( V_1 ) ;
F_110 ( V_200 , V_1 -> V_224 , V_1 -> V_260 , V_1 -> V_258 ) ;
F_111 ( V_1 ) ;
if ( ! V_1 -> V_228 )
F_160 ( & V_280 , V_48 == V_1 -> V_15 ?
V_1 -> V_43 : V_1 -> V_15 ) ;
F_55 ( & V_1 -> V_7 ) ;
}
static int F_161 ( struct V_47 * V_48 , T_5 V_284 )
{
struct V_1 * V_1 = F_28 ( V_48 ) ;
int V_285 ;
F_61 ( & V_1 -> V_34 ) ;
if ( F_162 ( V_284 ) ) {
if ( V_1 -> V_35 ) {
F_62 ( & V_1 -> V_34 ) ;
return - V_249 ;
}
}
V_285 = V_1 -> V_128 ++ ;
F_62 ( & V_1 -> V_34 ) ;
if ( V_285 )
return 0 ;
F_153 ( V_1 ) ;
return 0 ;
}
static int F_163 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_28 ( V_48 ) ;
struct V_37 * V_37 ;
int V_161 = 0 ;
F_61 ( & V_1 -> V_34 ) ;
if ( -- V_1 -> V_128 )
goto V_132;
if ( F_164 ( & V_1 -> V_7 ) ) {
V_161 = F_24 ( V_1 -> V_121 , V_42 ) ;
for (; ; ) {
V_37 = F_70 ( & V_1 -> V_124 ) ;
if ( ! V_37 )
break;
F_23 ( V_1 , V_37 -> V_53 ) ;
}
if ( V_161 < 0 )
goto V_132;
V_161 = F_42 ( V_1 , V_42 ) ;
}
V_132:
F_62 ( & V_1 -> V_34 ) ;
return V_161 ;
}
static int F_165 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_28 ( V_48 ) ;
if ( F_164 ( & V_1 -> V_7 ) )
F_34 ( & V_1 -> V_7 , false ) ;
return F_163 ( V_48 ) ;
}
static int T_6 F_166 ( void )
{
int V_14 ;
V_281 = F_167 ( V_8 ) ;
if ( ! V_281 )
return - V_205 ;
V_281 -> V_286 = L_38 ,
V_281 -> V_287 = L_39 ,
V_281 -> V_288 = V_289 ,
V_281 -> V_290 = 0 ,
V_281 -> type = V_291 ,
V_281 -> V_292 = V_293 ,
V_281 -> V_33 = V_294 | V_295 ;
V_281 -> V_296 = V_297 ;
V_281 -> V_296 . V_184 = V_298 | V_195 | V_299 |
V_300 | V_196 ;
F_168 ( V_281 , & V_301 ) ;
V_14 = F_169 ( V_281 ) ;
if ( V_14 ) {
F_170 ( V_281 ) ;
return V_14 ;
}
V_14 = F_171 ( & V_280 ) ;
if ( V_14 ) {
F_172 ( V_281 ) ;
F_170 ( V_281 ) ;
return V_14 ;
}
F_173 (KERN_INFO KBUILD_MODNAME L_40 DRIVER_DESC L_41 ) ;
return 0 ;
}
static void T_7 F_174 ( void )
{
F_175 ( & V_280 ) ;
F_172 ( V_281 ) ;
F_170 ( V_281 ) ;
F_176 ( & V_4 ) ;
}
