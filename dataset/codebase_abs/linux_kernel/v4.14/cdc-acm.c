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
static void F_17 ( struct V_1 * V_1 )
{
int V_26 ;
F_18 ( V_1 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ )
F_18 ( V_1 -> V_29 [ V_26 ] . V_30 ) ;
for ( V_26 = 0 ; V_26 < V_1 -> V_31 ; V_26 ++ )
F_18 ( V_1 -> V_32 [ V_26 ] ) ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_26 , V_33 ;
struct V_34 * V_29 ;
V_33 = 0 ;
V_26 = 0 ;
for (; ; ) {
V_29 = & V_1 -> V_29 [ V_33 ] ;
if ( ! V_29 -> V_35 ) {
V_29 -> V_35 = 1 ;
return V_33 ;
}
V_33 = ( V_33 + 1 ) % V_28 ;
if ( ++ V_26 >= V_28 )
return - 1 ;
}
}
static int F_20 ( struct V_1 * V_1 )
{
int V_26 , V_36 ;
unsigned long V_37 ;
V_36 = V_28 ;
F_21 ( & V_1 -> V_38 , V_37 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ )
V_36 -= V_1 -> V_29 [ V_26 ] . V_35 ;
F_22 ( & V_1 -> V_38 , V_37 ) ;
return V_36 ;
}
static void F_23 ( struct V_1 * V_1 , struct V_34 * V_29 )
{
V_29 -> V_35 = 0 ;
V_1 -> V_39 -- ;
F_24 ( V_1 -> V_15 ) ;
}
static int F_25 ( struct V_1 * V_1 , struct V_34 * V_29 )
{
int V_40 ;
V_1 -> V_39 ++ ;
V_29 -> V_30 -> V_41 = V_29 -> V_12 ;
V_29 -> V_30 -> V_42 = V_29 -> V_43 ;
V_29 -> V_30 -> V_44 = V_29 -> V_13 ;
V_29 -> V_30 -> V_16 = V_1 -> V_16 ;
V_40 = F_26 ( V_29 -> V_30 , V_45 ) ;
if ( V_40 < 0 ) {
F_27 ( & V_1 -> V_46 -> V_16 ,
L_2 ,
V_21 , V_40 ) ;
F_23 ( V_1 , V_29 ) ;
}
return V_40 ;
}
static T_1 F_28
( struct V_47 * V_16 , struct V_48 * V_49 , char * V_12 )
{
struct V_50 * V_51 = F_29 ( V_16 ) ;
struct V_1 * V_1 = F_30 ( V_51 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_52 ) ;
}
static T_1 F_31
( struct V_47 * V_16 , struct V_48 * V_49 , char * V_12 )
{
struct V_50 * V_51 = F_29 ( V_16 ) ;
struct V_1 * V_1 = F_30 ( V_51 ) ;
memcpy ( V_12 , V_1 -> V_53 , V_1 -> V_54 ) ;
return V_1 -> V_54 ;
}
static T_1 F_32
( struct V_47 * V_16 , struct V_48 * V_49 , char * V_12 )
{
struct V_50 * V_51 = F_29 ( V_16 ) ;
struct V_1 * V_1 = F_30 ( V_51 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_55 ) ;
}
static void F_33 ( struct V_1 * V_1 , unsigned char * V_12 )
{
int V_56 ;
int V_57 ;
struct V_58 * V_59 = (struct V_58 * ) V_12 ;
unsigned char * V_46 = V_12 + sizeof( struct V_58 ) ;
switch ( V_59 -> V_60 ) {
case V_61 :
F_14 ( & V_1 -> V_15 -> V_16 ,
L_4 , V_21 , V_59 -> V_62 ) ;
break;
case V_63 :
if ( F_34 ( V_59 -> V_64 ) != 2 ) {
F_14 ( & V_1 -> V_15 -> V_16 ,
L_5 , V_21 ) ;
break;
}
V_56 = F_35 ( V_46 ) ;
F_14 ( & V_1 -> V_15 -> V_16 ,
L_6 , V_21 , V_56 ) ;
if ( ! V_1 -> V_65 && ( V_1 -> V_66 & ~ V_56 & V_67 ) ) {
F_14 ( & V_1 -> V_15 -> V_16 ,
L_7 , V_21 ) ;
F_36 ( & V_1 -> V_7 , false ) ;
}
V_57 = V_1 -> V_66 ^ V_56 ;
F_37 ( & V_1 -> V_68 ) ;
V_1 -> V_66 = V_56 ;
V_1 -> V_69 = V_1 -> V_70 ;
if ( V_57 & V_71 )
V_1 -> V_70 . V_72 ++ ;
if ( V_57 & V_73 )
V_1 -> V_70 . V_74 ++ ;
if ( V_57 & V_75 )
V_1 -> V_70 . V_76 ++ ;
if ( V_57 & V_67 )
V_1 -> V_70 . V_77 ++ ;
if ( V_57 & V_78 )
V_1 -> V_70 . V_79 ++ ;
if ( V_57 & V_80 )
V_1 -> V_70 . V_81 ++ ;
if ( V_57 & V_82 )
V_1 -> V_70 . V_83 ++ ;
F_38 ( & V_1 -> V_68 ) ;
if ( V_57 )
F_39 ( & V_1 -> V_84 ) ;
break;
default:
F_14 ( & V_1 -> V_15 -> V_16 ,
L_8 ,
V_21 ,
V_59 -> V_60 , V_59 -> V_85 , V_59 -> V_64 ) ;
}
}
static void F_40 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = V_30 -> V_86 ;
struct V_58 * V_59 = V_30 -> V_41 ;
unsigned int V_87 = V_30 -> V_88 ;
unsigned int V_89 , V_90 , V_91 ;
int V_14 ;
int V_92 = V_30 -> V_92 ;
switch ( V_92 ) {
case 0 :
break;
case - V_93 :
case - V_94 :
case - V_95 :
V_1 -> V_96 = 0 ;
F_14 ( & V_1 -> V_15 -> V_16 ,
L_9 ,
V_21 , V_92 ) ;
return;
default:
F_14 ( & V_1 -> V_15 -> V_16 ,
L_10 ,
V_21 , V_92 ) ;
goto exit;
}
F_41 ( V_1 -> V_16 ) ;
if ( V_1 -> V_96 )
V_59 = (struct V_58 * ) V_1 -> V_97 ;
V_89 = sizeof( struct V_58 ) +
F_34 ( V_59 -> V_64 ) ;
if ( V_87 < V_89 ) {
if ( V_1 -> V_98 < V_89 ) {
if ( V_1 -> V_98 ) {
F_42 ( V_1 -> V_97 ) ;
V_1 -> V_98 = 0 ;
}
V_91 = F_43 ( V_89 ) ;
V_1 -> V_97 =
F_44 ( V_91 , V_45 ) ;
if ( ! V_1 -> V_97 )
goto exit;
V_1 -> V_98 = V_91 ;
}
V_90 = F_45 ( V_87 ,
V_89 - V_1 -> V_96 ) ;
memcpy ( & V_1 -> V_97 [ V_1 -> V_96 ] ,
V_30 -> V_41 , V_90 ) ;
V_1 -> V_96 += V_90 ;
V_87 = V_1 -> V_96 ;
}
if ( V_87 >= V_89 ) {
F_33 ( V_1 , ( unsigned char * ) V_59 ) ;
V_1 -> V_96 = 0 ;
}
exit:
V_14 = F_26 ( V_30 , V_45 ) ;
if ( V_14 && V_14 != - V_99 )
F_27 ( & V_1 -> V_15 -> V_16 ,
L_11 , V_21 , V_14 ) ;
}
static int F_46 ( struct V_1 * V_1 , int V_100 , T_2 V_101 )
{
int V_102 ;
if ( ! F_47 ( V_100 , & V_1 -> V_103 ) )
return 0 ;
V_102 = F_26 ( V_1 -> V_32 [ V_100 ] , V_101 ) ;
if ( V_102 ) {
if ( V_102 != - V_99 ) {
F_27 ( & V_1 -> V_46 -> V_16 ,
L_12 ,
V_100 , V_102 ) ;
}
F_48 ( V_100 , & V_1 -> V_103 ) ;
return V_102 ;
} else {
F_49 ( & V_1 -> V_46 -> V_16 , L_13 , V_100 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_1 , T_2 V_101 )
{
int V_102 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1 -> V_31 ; ++ V_26 ) {
V_102 = F_46 ( V_1 , V_26 , V_101 ) ;
if ( V_102 )
return V_102 ;
}
return 0 ;
}
static void F_51 ( struct V_1 * V_1 , struct V_30 * V_30 )
{
if ( ! V_30 -> V_88 )
return;
F_52 ( & V_1 -> V_7 , V_30 -> V_41 ,
V_30 -> V_88 ) ;
F_53 ( & V_1 -> V_7 ) ;
}
static void F_54 ( struct V_30 * V_30 )
{
struct V_104 * V_105 = V_30 -> V_86 ;
struct V_1 * V_1 = V_105 -> V_106 ;
unsigned long V_37 ;
int V_92 = V_30 -> V_92 ;
F_49 ( & V_1 -> V_46 -> V_16 , L_14 ,
V_105 -> V_100 , V_30 -> V_88 , V_92 ) ;
F_48 ( V_105 -> V_100 , & V_1 -> V_103 ) ;
if ( ! V_1 -> V_16 ) {
F_14 ( & V_1 -> V_46 -> V_16 , L_15 , V_21 ) ;
return;
}
switch ( V_92 ) {
case 0 :
F_41 ( V_1 -> V_16 ) ;
F_51 ( V_1 , V_30 ) ;
break;
case - V_107 :
F_48 ( V_108 , & V_1 -> V_37 ) ;
F_55 ( & V_1 -> V_109 ) ;
return;
case - V_94 :
case - V_93 :
case - V_95 :
F_14 ( & V_1 -> V_46 -> V_16 ,
L_9 ,
V_21 , V_92 ) ;
return;
default:
F_14 ( & V_1 -> V_46 -> V_16 ,
L_10 ,
V_21 , V_92 ) ;
break;
}
F_56 () ;
F_21 ( & V_1 -> V_68 , V_37 ) ;
V_1 -> V_110 = V_1 -> V_111 ;
if ( ! V_1 -> V_110 ) {
F_22 ( & V_1 -> V_68 , V_37 ) ;
F_46 ( V_1 , V_105 -> V_100 , V_45 ) ;
} else {
F_22 ( & V_1 -> V_68 , V_37 ) ;
}
}
static void F_57 ( struct V_30 * V_30 )
{
struct V_34 * V_29 = V_30 -> V_86 ;
struct V_1 * V_1 = V_29 -> V_106 ;
unsigned long V_37 ;
int V_92 = V_30 -> V_92 ;
if ( V_92 || ( V_30 -> V_88 != V_30 -> V_44 ) )
F_49 ( & V_1 -> V_46 -> V_16 , L_16 ,
V_30 -> V_88 ,
V_30 -> V_44 ,
V_92 ) ;
F_21 ( & V_1 -> V_38 , V_37 ) ;
F_23 ( V_1 , V_29 ) ;
F_22 ( & V_1 -> V_38 , V_37 ) ;
F_48 ( V_112 , & V_1 -> V_37 ) ;
F_55 ( & V_1 -> V_109 ) ;
}
static void F_58 ( struct V_113 * V_109 )
{
int V_26 ;
struct V_1 * V_1 = F_59 ( V_109 , struct V_1 , V_109 ) ;
if ( F_60 ( V_108 , & V_1 -> V_37 ) ) {
if ( ! ( F_11 ( V_1 -> V_46 ) ) ) {
for ( V_26 = 0 ; V_26 < V_1 -> V_31 ; V_26 ++ )
F_18 ( V_1 -> V_32 [ V_26 ] ) ;
F_61 ( V_1 -> V_16 , V_1 -> V_114 ) ;
F_50 ( V_1 , V_9 ) ;
F_15 ( V_1 -> V_46 ) ;
}
F_62 ( V_108 , & V_1 -> V_37 ) ;
}
if ( F_60 ( V_112 , & V_1 -> V_37 ) ) {
F_63 ( & V_1 -> V_7 ) ;
F_62 ( V_112 , & V_1 -> V_37 ) ;
}
}
static int F_64 ( struct V_115 * V_116 , struct V_117 * V_118 )
{
struct V_1 * V_1 ;
int V_14 ;
V_1 = F_1 ( V_118 -> V_100 ) ;
if ( ! V_1 )
return - V_119 ;
V_14 = F_65 ( V_116 , V_118 ) ;
if ( V_14 )
goto V_120;
V_118 -> V_121 = V_1 ;
return 0 ;
V_120:
F_66 ( & V_1 -> V_7 ) ;
return V_14 ;
}
static int F_67 ( struct V_117 * V_118 , struct V_122 * V_123 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
return F_68 ( & V_1 -> V_7 , V_118 , V_123 ) ;
}
static void F_69 ( struct V_124 * V_7 , int raise )
{
struct V_1 * V_1 = F_59 ( V_7 , struct V_1 , V_7 ) ;
int V_125 ;
int V_102 ;
if ( raise )
V_125 = V_126 | V_127 ;
else
V_125 = 0 ;
V_1 -> V_128 = V_125 ;
V_102 = F_16 ( V_1 , V_125 ) ;
if ( V_102 && ( V_1 -> V_52 & V_129 ) )
F_27 ( & V_1 -> V_15 -> V_16 , L_17 ) ;
}
static int F_70 ( struct V_124 * V_7 , struct V_117 * V_118 )
{
struct V_1 * V_1 = F_59 ( V_7 , struct V_1 , V_7 ) ;
int V_14 = - V_119 ;
int V_26 ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
goto V_6;
V_14 = F_11 ( V_1 -> V_15 ) ;
if ( V_14 )
goto V_130;
F_48 ( V_131 , & V_118 -> V_37 ) ;
V_1 -> V_15 -> V_132 = 1 ;
V_1 -> V_27 -> V_16 = V_1 -> V_16 ;
V_14 = F_26 ( V_1 -> V_27 , V_9 ) ;
if ( V_14 ) {
F_27 ( & V_1 -> V_15 -> V_16 ,
L_18 , V_21 ) ;
goto V_133;
}
F_71 ( V_118 , NULL ) ;
F_72 ( & V_1 -> V_68 ) ;
V_1 -> V_110 = 0 ;
V_1 -> V_111 = 0 ;
F_73 ( & V_1 -> V_68 ) ;
V_14 = F_50 ( V_1 , V_9 ) ;
if ( V_14 )
goto V_134;
F_15 ( V_1 -> V_15 ) ;
F_4 ( & V_1 -> V_5 ) ;
return 0 ;
V_134:
for ( V_26 = 0 ; V_26 < V_1 -> V_31 ; V_26 ++ )
F_18 ( V_1 -> V_32 [ V_26 ] ) ;
F_18 ( V_1 -> V_27 ) ;
V_133:
F_15 ( V_1 -> V_15 ) ;
V_130:
V_6:
F_4 ( & V_1 -> V_5 ) ;
return F_74 ( V_14 ) ;
}
static void F_75 ( struct V_124 * V_7 )
{
struct V_1 * V_1 = F_59 ( V_7 , struct V_1 , V_7 ) ;
F_8 ( V_1 ) ;
F_76 ( V_1 -> V_15 ) ;
F_42 ( V_1 -> V_53 ) ;
F_42 ( V_1 ) ;
}
static void F_77 ( struct V_124 * V_7 )
{
struct V_1 * V_1 = F_59 ( V_7 , struct V_1 , V_7 ) ;
struct V_30 * V_30 ;
struct V_34 * V_29 ;
F_72 ( & V_1 -> V_38 ) ;
F_73 ( & V_1 -> V_38 ) ;
F_78 ( V_1 -> V_15 ) ;
V_1 -> V_15 -> V_132 = 0 ;
F_15 ( V_1 -> V_15 ) ;
for (; ; ) {
V_30 = F_79 ( & V_1 -> V_135 ) ;
if ( ! V_30 )
break;
V_29 = V_30 -> V_86 ;
V_29 -> V_35 = 0 ;
F_24 ( V_1 -> V_15 ) ;
}
F_17 ( V_1 ) ;
}
static void F_80 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
F_66 ( & V_1 -> V_7 ) ;
}
static void F_81 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
F_82 ( & V_1 -> V_7 ) ;
}
static void F_83 ( struct V_117 * V_118 , struct V_122 * V_123 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
F_84 ( & V_1 -> V_7 , V_118 , V_123 ) ;
}
static int F_85 ( struct V_117 * V_118 ,
const unsigned char * V_12 , int V_136 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
int V_137 ;
unsigned long V_37 ;
int V_33 ;
struct V_34 * V_29 ;
if ( ! V_136 )
return 0 ;
F_49 ( & V_1 -> V_46 -> V_16 , L_19 , V_136 ) ;
F_21 ( & V_1 -> V_38 , V_37 ) ;
V_33 = F_19 ( V_1 ) ;
if ( V_33 < 0 ) {
F_22 ( & V_1 -> V_38 , V_37 ) ;
return 0 ;
}
V_29 = & V_1 -> V_29 [ V_33 ] ;
if ( ! V_1 -> V_16 ) {
V_29 -> V_35 = 0 ;
F_22 ( & V_1 -> V_38 , V_37 ) ;
return - V_119 ;
}
V_136 = ( V_136 > V_1 -> V_138 ) ? V_1 -> V_138 : V_136 ;
F_49 ( & V_1 -> V_46 -> V_16 , L_20 , V_136 ) ;
memcpy ( V_29 -> V_12 , V_12 , V_136 ) ;
V_29 -> V_13 = V_136 ;
V_137 = F_86 ( V_1 -> V_15 ) ;
if ( V_137 ) {
V_29 -> V_35 = 0 ;
F_22 ( & V_1 -> V_38 , V_37 ) ;
return V_137 ;
}
if ( V_1 -> V_139 ) {
if ( V_1 -> V_140 ) {
F_87 ( V_1 -> V_140 -> V_30 , & V_1 -> V_135 ) ;
V_1 -> V_140 = NULL ;
}
F_87 ( V_29 -> V_30 , & V_1 -> V_135 ) ;
F_22 ( & V_1 -> V_38 , V_37 ) ;
return V_136 ;
} else {
if ( V_1 -> V_140 ) {
F_25 ( V_1 , V_1 -> V_140 ) ;
V_1 -> V_140 = NULL ;
}
}
V_137 = F_25 ( V_1 , V_29 ) ;
F_22 ( & V_1 -> V_38 , V_37 ) ;
if ( V_137 < 0 )
return V_137 ;
return V_136 ;
}
static void F_88 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
struct V_34 * V_141 = V_1 -> V_140 ;
int V_142 ;
unsigned long V_37 ;
if ( ! V_141 )
return;
V_1 -> V_140 = NULL ;
V_142 = F_86 ( V_1 -> V_15 ) ;
F_21 ( & V_1 -> V_38 , V_37 ) ;
if ( V_142 < 0 ) {
V_141 -> V_35 = 0 ;
V_1 -> V_140 = V_141 ;
goto V_143;
}
if ( V_1 -> V_139 )
F_87 ( V_141 -> V_30 , & V_1 -> V_135 ) ;
else
F_25 ( V_1 , V_141 ) ;
V_143:
F_22 ( & V_1 -> V_38 , V_37 ) ;
return;
}
static int F_89 ( struct V_117 * V_118 , unsigned char V_144 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
struct V_34 * V_141 ;
int V_33 ;
unsigned long V_37 ;
V_145:
V_141 = V_1 -> V_140 ;
if ( ! V_141 ) {
F_21 ( & V_1 -> V_38 , V_37 ) ;
V_33 = F_19 ( V_1 ) ;
if ( V_33 >= 0 ) {
V_141 = & V_1 -> V_29 [ V_33 ] ;
V_1 -> V_140 = V_141 ;
}
F_22 ( & V_1 -> V_38 , V_37 ) ;
if ( ! V_141 )
return 0 ;
}
if ( V_141 -> V_13 == V_1 -> V_138 ) {
F_88 ( V_118 ) ;
goto V_145;
}
V_141 -> V_12 [ V_141 -> V_13 ++ ] = V_144 ;
return 1 ;
}
static int F_90 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
return F_20 ( V_1 ) ? V_1 -> V_138 : 0 ;
}
static int F_91 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
if ( V_1 -> V_6 )
return 0 ;
return ( V_28 - F_20 ( V_1 ) ) * V_1 -> V_138 ;
}
static void F_92 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
F_72 ( & V_1 -> V_68 ) ;
V_1 -> V_111 = 1 ;
F_73 ( & V_1 -> V_68 ) ;
}
static void F_93 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
unsigned int V_146 ;
F_72 ( & V_1 -> V_68 ) ;
V_146 = V_1 -> V_110 ;
V_1 -> V_110 = 0 ;
V_1 -> V_111 = 0 ;
F_73 ( & V_1 -> V_68 ) ;
if ( V_146 )
F_50 ( V_1 , V_9 ) ;
}
static int F_94 ( struct V_117 * V_118 , int V_147 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
int V_14 ;
V_14 = F_95 ( V_1 , V_147 ? 0xffff : 0 ) ;
if ( V_14 < 0 )
F_14 ( & V_1 -> V_15 -> V_16 ,
L_21 , V_21 ) ;
return V_14 ;
}
static int F_96 ( struct V_117 * V_118 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
return ( V_1 -> V_128 & V_126 ? V_148 : 0 ) |
( V_1 -> V_128 & V_127 ? V_149 : 0 ) |
( V_1 -> V_66 & V_71 ? V_150 : 0 ) |
( V_1 -> V_66 & V_75 ? V_151 : 0 ) |
( V_1 -> V_66 & V_67 ? V_152 : 0 ) |
V_153 ;
}
static int F_97 ( struct V_117 * V_118 ,
unsigned int V_154 , unsigned int V_155 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
unsigned int V_56 ;
V_56 = V_1 -> V_128 ;
V_154 = ( V_154 & V_148 ? V_126 : 0 ) |
( V_154 & V_149 ? V_127 : 0 ) ;
V_155 = ( V_155 & V_148 ? V_126 : 0 ) |
( V_155 & V_149 ? V_127 : 0 ) ;
V_56 = ( V_56 & ~ V_155 ) | V_154 ;
if ( V_1 -> V_128 == V_56 )
return 0 ;
return F_16 ( V_1 , V_1 -> V_128 = V_56 ) ;
}
static int F_98 ( struct V_1 * V_1 , struct V_156 T_3 * V_157 )
{
struct V_156 V_158 ;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_158 . V_159 = V_1 -> V_138 ;
V_158 . V_160 = F_99 ( V_1 -> line . V_161 ) ;
V_158 . V_162 = V_1 -> V_7 . V_162 / 10 ;
V_158 . V_163 = V_1 -> V_7 . V_163 == V_164 ?
V_164 :
V_1 -> V_7 . V_163 / 10 ;
if ( F_100 ( V_157 , & V_158 , sizeof( V_158 ) ) )
return - V_165 ;
else
return 0 ;
}
static int F_101 ( struct V_1 * V_1 ,
struct V_156 T_3 * V_166 )
{
struct V_156 V_167 ;
unsigned int V_163 , V_162 ;
int V_14 = 0 ;
if ( F_102 ( & V_167 , V_166 , sizeof( V_167 ) ) )
return - V_165 ;
V_162 = V_167 . V_162 * 10 ;
V_163 = V_167 . V_163 == V_164 ?
V_164 : V_167 . V_163 * 10 ;
F_2 ( & V_1 -> V_7 . V_5 ) ;
if ( ! F_103 ( V_168 ) ) {
if ( ( V_162 != V_1 -> V_7 . V_162 ) ||
( V_163 != V_1 -> V_7 . V_163 ) )
V_14 = - V_99 ;
else
V_14 = - V_24 ;
} else {
V_1 -> V_7 . V_162 = V_162 ;
V_1 -> V_7 . V_163 = V_163 ;
}
F_4 ( & V_1 -> V_7 . V_5 ) ;
return V_14 ;
}
static int F_104 ( struct V_1 * V_1 , unsigned long V_169 )
{
int V_170 = 0 ;
F_105 ( V_171 , V_172 ) ;
struct V_173 V_174 , V_175 ;
do {
F_72 ( & V_1 -> V_68 ) ;
V_174 = V_1 -> V_69 ;
V_175 = V_1 -> V_70 ;
V_1 -> V_69 = V_175 ;
F_73 ( & V_1 -> V_68 ) ;
if ( ( V_169 & V_150 ) &&
V_174 . V_72 != V_175 . V_72 )
break;
if ( ( V_169 & V_152 ) &&
V_174 . V_77 != V_175 . V_77 )
break;
if ( ( V_169 & V_151 ) &&
V_174 . V_76 != V_175 . V_76 )
break;
F_106 ( & V_1 -> V_84 , & V_171 ) ;
F_107 ( V_176 ) ;
F_108 () ;
F_109 ( & V_1 -> V_84 , & V_171 ) ;
if ( V_1 -> V_6 ) {
if ( V_169 & V_152 )
break;
else
V_170 = - V_119 ;
} else {
if ( F_110 ( V_172 ) )
V_170 = - V_177 ;
}
} while ( ! V_170 );
return V_170 ;
}
static int F_111 ( struct V_117 * V_118 ,
struct V_178 * V_179 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
V_179 -> V_72 = V_1 -> V_70 . V_72 ;
V_179 -> V_76 = V_1 -> V_70 . V_76 ;
V_179 -> V_77 = V_1 -> V_70 . V_77 ;
V_179 -> V_79 = V_1 -> V_70 . V_79 ;
V_179 -> V_83 = V_1 -> V_70 . V_83 ;
V_179 -> V_81 = V_1 -> V_70 . V_81 ;
V_179 -> V_74 = V_1 -> V_70 . V_74 ;
return 0 ;
}
static int F_112 ( struct V_117 * V_118 ,
unsigned int V_180 , unsigned long V_169 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
int V_170 = - V_181 ;
switch ( V_180 ) {
case V_182 :
V_170 = F_98 ( V_1 , (struct V_156 T_3 * ) V_169 ) ;
break;
case V_183 :
V_170 = F_101 ( V_1 , (struct V_156 T_3 * ) V_169 ) ;
break;
case V_184 :
V_170 = F_11 ( V_1 -> V_15 ) ;
if ( V_170 < 0 ) {
V_170 = - V_185 ;
break;
}
V_170 = F_104 ( V_1 , V_169 ) ;
F_15 ( V_1 -> V_15 ) ;
break;
}
return V_170 ;
}
static void F_71 ( struct V_117 * V_118 ,
struct V_186 * V_187 )
{
struct V_1 * V_1 = V_118 -> V_121 ;
struct V_186 * V_188 = & V_118 -> V_188 ;
struct V_189 V_190 ;
int V_56 = V_1 -> V_128 ;
V_190 . V_161 = F_113 ( F_114 ( V_118 ) ) ;
V_190 . V_191 = V_188 -> V_192 & V_193 ? 2 : 0 ;
V_190 . V_194 = V_188 -> V_192 & V_195 ?
( V_188 -> V_192 & V_196 ? 1 : 2 ) +
( V_188 -> V_192 & V_197 ? 2 : 0 ) : 0 ;
switch ( V_188 -> V_192 & V_198 ) {
case V_199 :
V_190 . V_200 = 5 ;
break;
case V_201 :
V_190 . V_200 = 6 ;
break;
case V_202 :
V_190 . V_200 = 7 ;
break;
case V_203 :
default:
V_190 . V_200 = 8 ;
break;
}
V_1 -> V_65 = ( ( V_188 -> V_192 & V_204 ) != 0 ) ;
if ( F_115 ( V_118 ) == V_205 ) {
V_190 . V_161 = V_1 -> line . V_161 ;
V_56 &= ~ V_126 ;
} else if ( V_187 && ( V_187 -> V_192 & V_206 ) == V_205 ) {
V_56 |= V_126 ;
}
if ( V_56 != V_1 -> V_128 )
F_16 ( V_1 , V_1 -> V_128 = V_56 ) ;
if ( memcmp ( & V_1 -> line , & V_190 , sizeof V_190 ) ) {
memcpy ( & V_1 -> line , & V_190 , sizeof V_190 ) ;
F_14 ( & V_1 -> V_15 -> V_16 , L_22 ,
V_21 ,
F_99 ( V_190 . V_161 ) ,
V_190 . V_191 , V_190 . V_194 ,
V_190 . V_200 ) ;
F_116 ( V_1 , & V_1 -> line ) ;
}
}
static void F_117 ( struct V_1 * V_1 )
{
int V_26 ;
struct V_34 * V_29 ;
for ( V_29 = & V_1 -> V_29 [ 0 ] , V_26 = 0 ; V_26 < V_28 ; V_26 ++ , V_29 ++ )
F_118 ( V_1 -> V_16 , V_1 -> V_138 , V_29 -> V_12 , V_29 -> V_43 ) ;
}
static void F_119 ( struct V_1 * V_1 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1 -> V_31 ; V_26 ++ )
F_118 ( V_1 -> V_16 , V_1 -> V_207 ,
V_1 -> V_208 [ V_26 ] . V_209 , V_1 -> V_208 [ V_26 ] . V_210 ) ;
}
static int F_120 ( struct V_1 * V_1 )
{
int V_26 ;
struct V_34 * V_29 ;
for ( V_29 = & V_1 -> V_29 [ 0 ] , V_26 = 0 ; V_26 < V_28 ; V_26 ++ , V_29 ++ ) {
V_29 -> V_12 = F_121 ( V_1 -> V_16 , V_1 -> V_138 , V_9 ,
& V_29 -> V_43 ) ;
if ( ! V_29 -> V_12 ) {
while ( V_26 != 0 ) {
-- V_26 ;
-- V_29 ;
F_118 ( V_1 -> V_16 , V_1 -> V_138 ,
V_29 -> V_12 , V_29 -> V_43 ) ;
}
return - V_211 ;
}
}
return 0 ;
}
static int F_122 ( struct V_50 * V_51 ,
const struct V_212 * V_213 )
{
struct V_214 * V_215 = NULL ;
struct V_216 * V_217 = NULL ;
unsigned char * V_218 = V_51 -> V_18 -> V_219 ;
int V_220 = V_51 -> V_18 -> V_221 ;
struct V_50 * V_222 ;
struct V_50 * V_223 ;
struct V_224 * V_225 = NULL ;
struct V_224 * V_226 = NULL ;
struct V_224 * V_227 = NULL ;
struct V_228 * V_229 = F_123 ( V_51 ) ;
struct V_230 V_231 ;
struct V_1 * V_1 ;
int V_2 ;
int V_232 , V_207 ;
T_4 * V_12 ;
int V_233 = - 1 ;
int V_234 = - 1 ;
unsigned long V_22 ;
int V_235 ;
int V_26 ;
int V_236 = 0 ;
struct V_47 * V_237 ;
int V_170 = - V_211 ;
int V_102 ;
V_22 = ( unsigned long ) V_213 -> V_238 ;
if ( V_22 == V_239 )
return - V_119 ;
memset ( & V_231 , 0x00 , sizeof( struct V_230 ) ) ;
V_235 = ( V_22 == V_240 ) ? 1 : V_241 ;
if ( V_22 == V_242 ) {
V_223 = F_124 ( V_229 , 1 ) ;
V_222 = F_124 ( V_229 , 0 ) ;
if ( ! V_223 || ! V_222 )
return - V_119 ;
goto V_243;
}
if ( ! V_218 ) {
F_27 ( & V_51 -> V_16 , L_23 ) ;
return - V_244 ;
}
if ( ! V_51 -> V_245 )
return - V_244 ;
if ( ! V_220 ) {
if ( V_51 -> V_245 -> V_246 &&
V_51 -> V_245 -> V_246 -> V_221 &&
V_51 -> V_245 -> V_246 -> V_219 ) {
F_14 ( & V_51 -> V_16 ,
L_24 ) ;
V_220 = V_51 -> V_245 -> V_246 -> V_221 ;
V_218 = V_51 -> V_245 -> V_246 -> V_219 ;
} else {
F_27 ( & V_51 -> V_16 ,
L_25 ) ;
return - V_244 ;
}
}
F_125 ( & V_231 , V_51 , V_218 , V_220 ) ;
V_215 = V_231 . V_214 ;
V_217 = V_231 . V_216 ;
if ( V_217 )
V_233 = V_217 -> V_247 ;
if ( ! V_215 ) {
if ( V_233 > 0 ) {
F_14 ( & V_51 -> V_16 , L_26 ) ;
if ( V_22 & V_248 ) {
V_223 = F_124 ( V_229 , 0 ) ;
} else {
V_234 = V_233 ;
V_223 = F_124 ( V_229 , V_234 ) ;
}
V_222 = V_51 ;
} else {
if ( V_51 -> V_245 -> V_19 . V_249 != 3 ) {
F_14 ( & V_51 -> V_16 , L_27 ) ;
return - V_119 ;
} else {
F_126 ( & V_51 -> V_16 , L_28 ) ;
V_236 = 1 ;
V_222 = V_223 = V_51 ;
goto V_250;
}
}
} else {
V_234 = V_215 -> V_251 ;
V_222 = F_124 ( V_229 , V_215 -> V_252 ) ;
V_223 = F_124 ( V_229 , V_234 ) ;
}
if ( ! V_222 || ! V_223 ) {
F_14 ( & V_51 -> V_16 , L_29 ) ;
return - V_119 ;
}
if ( ! V_223 -> V_245 || ! V_222 -> V_245 )
return - V_119 ;
if ( V_234 != V_233 )
F_14 ( & V_51 -> V_16 , L_30 ) ;
if ( V_222 == V_223 ) {
F_126 ( & V_51 -> V_16 , L_31 ) ;
V_236 = 1 ;
V_22 |= V_253 ;
if ( V_223 -> V_245 -> V_19 . V_249 != 3 ) {
F_27 ( & V_51 -> V_16 , L_32 ) ;
return - V_244 ;
}
V_250:
V_102 = F_127 ( V_223 -> V_245 ,
& V_226 , & V_227 , & V_225 , NULL ) ;
if ( V_102 )
return V_102 ;
goto V_254;
}
V_243:
if ( V_223 -> V_245 -> V_19 . V_255
!= V_256 ) {
if ( V_222 -> V_245 -> V_19 . V_255
== V_256 ) {
F_14 ( & V_51 -> V_16 ,
L_33 ) ;
F_128 ( V_222 , V_223 ) ;
} else {
return - V_244 ;
}
}
if ( ! V_236 && V_51 != V_222 )
return - V_119 ;
if ( ! V_236 && F_129 ( V_223 ) ) {
F_14 ( & V_51 -> V_16 , L_34 ) ;
return - V_257 ;
}
if ( V_223 -> V_245 -> V_19 . V_249 < 2 ||
V_222 -> V_245 -> V_19 . V_249 == 0 )
return - V_244 ;
V_225 = & V_222 -> V_245 -> V_246 [ 0 ] . V_19 ;
V_226 = & V_223 -> V_245 -> V_246 [ 0 ] . V_19 ;
V_227 = & V_223 -> V_245 -> V_246 [ 1 ] . V_19 ;
if ( ! F_130 ( V_226 ) ) {
F_14 ( & V_51 -> V_16 ,
L_35 ) ;
F_128 ( V_226 , V_227 ) ;
}
V_254:
F_14 ( & V_51 -> V_16 , L_36 ) ;
V_1 = F_131 ( sizeof( struct V_1 ) , V_9 ) ;
if ( V_1 == NULL )
goto V_258;
V_2 = F_6 ( V_1 ) ;
if ( V_2 < 0 )
goto V_259;
V_232 = F_132 ( V_225 ) ;
V_207 = F_132 ( V_226 ) *
( V_22 == V_240 ? 1 : 2 ) ;
V_1 -> V_236 = V_236 ;
V_1 -> V_138 = F_132 ( V_227 ) * 20 ;
V_1 -> V_15 = V_222 ;
V_1 -> V_46 = V_223 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_16 = V_229 ;
if ( V_231 . V_260 )
V_1 -> V_52 = V_231 . V_260 -> V_261 ;
if ( V_22 & V_253 )
V_1 -> V_52 &= ~ V_129 ;
V_1 -> V_232 = V_232 ;
V_1 -> V_207 = V_207 ;
V_1 -> V_31 = V_235 ;
F_133 ( & V_1 -> V_109 , F_58 ) ;
F_134 ( & V_1 -> V_84 ) ;
F_135 ( & V_1 -> V_38 ) ;
F_135 ( & V_1 -> V_68 ) ;
F_136 ( & V_1 -> V_5 ) ;
if ( F_137 ( V_226 ) ) {
V_1 -> V_262 = V_226 -> V_262 ;
V_1 -> V_114 = F_138 ( V_229 , V_226 -> V_263 ) ;
} else {
V_1 -> V_114 = F_139 ( V_229 , V_226 -> V_263 ) ;
}
if ( F_137 ( V_227 ) )
V_1 -> V_143 = F_140 ( V_229 , V_227 -> V_263 ) ;
else
V_1 -> V_143 = F_141 ( V_229 , V_227 -> V_263 ) ;
F_142 ( & V_1 -> V_7 ) ;
V_1 -> V_7 . V_264 = & V_265 ;
F_143 ( & V_1 -> V_135 ) ;
V_1 -> V_22 = V_22 ;
V_12 = F_121 ( V_229 , V_232 , V_9 , & V_1 -> V_266 ) ;
if ( ! V_12 )
goto V_267;
V_1 -> V_268 = V_12 ;
if ( F_120 ( V_1 ) < 0 )
goto V_269;
V_1 -> V_27 = F_144 ( 0 , V_9 ) ;
if ( ! V_1 -> V_27 )
goto V_270;
for ( V_26 = 0 ; V_26 < V_235 ; V_26 ++ ) {
struct V_104 * V_105 = & ( V_1 -> V_208 [ V_26 ] ) ;
struct V_30 * V_30 ;
V_105 -> V_209 = F_121 ( V_1 -> V_16 , V_207 , V_9 ,
& V_105 -> V_210 ) ;
if ( ! V_105 -> V_209 )
goto V_271;
V_105 -> V_100 = V_26 ;
V_105 -> V_106 = V_1 ;
V_30 = F_144 ( 0 , V_9 ) ;
if ( ! V_30 )
goto V_271;
V_30 -> V_272 |= V_273 ;
V_30 -> V_42 = V_105 -> V_210 ;
if ( F_137 ( V_226 ) )
F_145 ( V_30 , V_1 -> V_16 , V_1 -> V_114 , V_105 -> V_209 ,
V_1 -> V_207 ,
F_54 , V_105 ,
V_1 -> V_262 ) ;
else
F_146 ( V_30 , V_1 -> V_16 , V_1 -> V_114 , V_105 -> V_209 ,
V_1 -> V_207 ,
F_54 , V_105 ) ;
V_1 -> V_32 [ V_26 ] = V_30 ;
F_147 ( V_26 , & V_1 -> V_103 ) ;
}
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
struct V_34 * V_274 = & ( V_1 -> V_29 [ V_26 ] ) ;
V_274 -> V_30 = F_144 ( 0 , V_9 ) ;
if ( V_274 -> V_30 == NULL )
goto V_275;
if ( F_137 ( V_227 ) )
F_145 ( V_274 -> V_30 , V_229 , V_1 -> V_143 ,
NULL , V_1 -> V_138 , F_57 , V_274 , V_227 -> V_262 ) ;
else
F_146 ( V_274 -> V_30 , V_229 , V_1 -> V_143 ,
NULL , V_1 -> V_138 , F_57 , V_274 ) ;
V_274 -> V_30 -> V_272 |= V_273 ;
if ( V_22 & V_276 )
V_274 -> V_30 -> V_272 |= V_277 ;
V_274 -> V_106 = V_1 ;
}
F_148 ( V_51 , V_1 ) ;
V_26 = F_149 ( & V_51 -> V_16 , & V_278 ) ;
if ( V_26 < 0 )
goto V_275;
if ( V_231 . V_279 ) {
struct V_279 * V_280 =
V_231 . V_279 ;
V_1 -> V_53 = F_44 ( V_280 -> V_281 - 4 , V_9 ) ;
if ( ! V_1 -> V_53 )
goto V_282;
V_1 -> V_54 = V_280 -> V_281 - 4 ;
memcpy ( V_1 -> V_53 , ( T_4 * ) & V_280 -> V_283 ,
V_280 -> V_281 - 4 ) ;
V_1 -> V_55 = V_280 -> V_284 ;
V_26 = F_149 ( & V_51 -> V_16 , & V_285 ) ;
if ( V_26 < 0 ) {
F_42 ( V_1 -> V_53 ) ;
V_1 -> V_53 = NULL ;
V_1 -> V_54 = 0 ;
goto V_282;
}
V_26 = F_149 ( & V_51 -> V_16 ,
& V_286 ) ;
if ( V_26 < 0 ) {
F_150 ( & V_51 -> V_16 , & V_285 ) ;
F_42 ( V_1 -> V_53 ) ;
V_1 -> V_53 = NULL ;
V_1 -> V_54 = 0 ;
goto V_282;
}
}
V_282:
F_145 ( V_1 -> V_27 , V_229 ,
F_138 ( V_229 , V_225 -> V_263 ) ,
V_1 -> V_268 , V_232 , F_40 , V_1 ,
V_225 -> V_262 ? V_225 -> V_262 : 16 ) ;
V_1 -> V_27 -> V_272 |= V_273 ;
V_1 -> V_27 -> V_42 = V_1 -> V_266 ;
V_1 -> V_97 = NULL ;
V_1 -> V_96 = 0 ;
V_1 -> V_98 = 0 ;
F_151 ( & V_51 -> V_16 , L_37 , V_2 ) ;
V_1 -> line . V_161 = F_113 ( 9600 ) ;
V_1 -> line . V_200 = 8 ;
F_116 ( V_1 , & V_1 -> line ) ;
F_152 ( & V_287 , V_223 , V_1 ) ;
F_148 ( V_223 , V_1 ) ;
F_153 ( V_222 ) ;
V_237 = F_154 ( & V_1 -> V_7 , V_288 , V_2 ,
& V_222 -> V_16 ) ;
if ( F_155 ( V_237 ) ) {
V_170 = F_156 ( V_237 ) ;
goto V_289;
}
if ( V_22 & V_290 ) {
F_61 ( V_229 , V_1 -> V_114 ) ;
F_61 ( V_229 , V_1 -> V_143 ) ;
}
return 0 ;
V_289:
if ( V_1 -> V_53 ) {
F_150 ( & V_1 -> V_15 -> V_16 ,
& V_285 ) ;
F_150 ( & V_1 -> V_15 -> V_16 ,
& V_286 ) ;
F_42 ( V_1 -> V_53 ) ;
}
F_150 ( & V_1 -> V_15 -> V_16 , & V_278 ) ;
V_275:
F_148 ( V_51 , NULL ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ )
F_157 ( V_1 -> V_29 [ V_26 ] . V_30 ) ;
V_271:
for ( V_26 = 0 ; V_26 < V_235 ; V_26 ++ )
F_157 ( V_1 -> V_32 [ V_26 ] ) ;
F_119 ( V_1 ) ;
F_157 ( V_1 -> V_27 ) ;
V_270:
F_117 ( V_1 ) ;
V_269:
F_118 ( V_229 , V_232 , V_1 -> V_268 , V_1 -> V_266 ) ;
V_267:
F_8 ( V_1 ) ;
V_259:
F_42 ( V_1 ) ;
V_258:
return V_170 ;
}
static void F_158 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_30 ( V_51 ) ;
struct V_117 * V_118 ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = true ;
if ( V_1 -> V_53 ) {
F_150 ( & V_1 -> V_15 -> V_16 ,
& V_285 ) ;
F_150 ( & V_1 -> V_15 -> V_16 ,
& V_286 ) ;
}
F_39 ( & V_1 -> V_84 ) ;
F_150 ( & V_1 -> V_15 -> V_16 , & V_278 ) ;
F_148 ( V_1 -> V_15 , NULL ) ;
F_148 ( V_1 -> V_46 , NULL ) ;
F_4 ( & V_1 -> V_5 ) ;
V_118 = F_159 ( & V_1 -> V_7 ) ;
if ( V_118 ) {
F_160 ( V_118 ) ;
F_161 ( V_118 ) ;
}
F_17 ( V_1 ) ;
F_162 ( & V_1 -> V_109 ) ;
F_163 ( V_288 , V_1 -> V_2 ) ;
F_117 ( V_1 ) ;
F_118 ( V_1 -> V_16 , V_1 -> V_232 , V_1 -> V_268 , V_1 -> V_266 ) ;
F_119 ( V_1 ) ;
F_42 ( V_1 -> V_97 ) ;
if ( ! V_1 -> V_236 )
F_164 ( & V_287 , V_51 == V_1 -> V_15 ?
V_1 -> V_46 : V_1 -> V_15 ) ;
F_66 ( & V_1 -> V_7 ) ;
}
static int F_165 ( struct V_50 * V_51 , T_5 V_291 )
{
struct V_1 * V_1 = F_30 ( V_51 ) ;
int V_292 ;
F_72 ( & V_1 -> V_38 ) ;
if ( F_166 ( V_291 ) ) {
if ( V_1 -> V_39 ) {
F_73 ( & V_1 -> V_38 ) ;
return - V_257 ;
}
}
V_292 = V_1 -> V_139 ++ ;
F_73 ( & V_1 -> V_38 ) ;
if ( V_292 )
return 0 ;
F_17 ( V_1 ) ;
F_162 ( & V_1 -> V_109 ) ;
return 0 ;
}
static int F_167 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_30 ( V_51 ) ;
struct V_30 * V_30 ;
int V_170 = 0 ;
F_72 ( & V_1 -> V_38 ) ;
if ( -- V_1 -> V_139 )
goto V_143;
if ( F_168 ( & V_1 -> V_7 ) ) {
V_170 = F_26 ( V_1 -> V_27 , V_45 ) ;
for (; ; ) {
V_30 = F_79 ( & V_1 -> V_135 ) ;
if ( ! V_30 )
break;
F_25 ( V_1 , V_30 -> V_86 ) ;
}
if ( V_170 < 0 )
goto V_143;
V_170 = F_50 ( V_1 , V_45 ) ;
}
V_143:
F_73 ( & V_1 -> V_38 ) ;
return V_170 ;
}
static int F_169 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_30 ( V_51 ) ;
if ( F_168 ( & V_1 -> V_7 ) )
F_36 ( & V_1 -> V_7 , false ) ;
return F_167 ( V_51 ) ;
}
static int F_170 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_30 ( V_51 ) ;
F_62 ( V_108 , & V_1 -> V_37 ) ;
return 0 ;
}
static int T_6 F_171 ( void )
{
int V_14 ;
V_288 = F_172 ( V_8 ) ;
if ( ! V_288 )
return - V_211 ;
V_288 -> V_293 = L_38 ,
V_288 -> V_294 = L_39 ,
V_288 -> V_295 = V_296 ,
V_288 -> V_297 = 0 ,
V_288 -> type = V_298 ,
V_288 -> V_299 = V_300 ,
V_288 -> V_37 = V_301 | V_302 ;
V_288 -> V_303 = V_304 ;
V_288 -> V_303 . V_192 = V_305 | V_203 | V_306 |
V_307 | V_204 ;
F_173 ( V_288 , & V_308 ) ;
V_14 = F_174 ( V_288 ) ;
if ( V_14 ) {
F_175 ( V_288 ) ;
return V_14 ;
}
V_14 = F_176 ( & V_287 ) ;
if ( V_14 ) {
F_177 ( V_288 ) ;
F_175 ( V_288 ) ;
return V_14 ;
}
F_178 (KERN_INFO KBUILD_MODNAME L_40 DRIVER_DESC L_41 ) ;
return 0 ;
}
static void T_7 F_179 ( void )
{
F_180 ( & V_287 ) ;
F_177 ( V_288 ) ;
F_175 ( V_288 ) ;
F_181 ( & V_4 ) ;
}
