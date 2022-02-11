static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_2 == V_2 )
return V_5 + V_3 ;
return NULL ;
}
static inline void F_2 ( struct V_6 * V_7 ,
struct V_8 * * V_9 )
{
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
if ( F_4 ( & V_7 -> V_13 ) ) {
F_5 ( V_11 , V_14 , L_1 ) ;
* V_9 = NULL ;
return;
}
* V_9 = F_6 ( V_7 -> V_13 . V_15 ,
struct V_8 , V_16 . V_17 ) ;
}
static inline void F_7 ( struct V_10 * V_11 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_5 ( V_11 , V_18 , L_2 , V_9 , V_9 -> V_16 . V_3 ) ;
V_9 -> V_16 . V_19 = V_20 ;
V_9 -> V_16 . V_21 ++ ;
F_8 ( & V_9 -> V_16 . V_22 ) ;
F_9 ( & V_9 -> V_16 . V_17 ) ;
F_10 ( & V_9 -> V_16 . V_23 ) ;
}
static int F_11 ( T_1 * V_24 , unsigned long V_25 ,
struct V_26 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
T_1 * V_28 = V_24 , * V_29 = V_24 + V_25 ;
unsigned long V_30 = 0 ;
int V_31 = 0 ;
unsigned int V_32 , V_33 , V_34 , V_35 , V_36 , V_37 , line , V_38 = 0 ;
struct V_8 * V_39 = NULL ;
char * V_40 = NULL ;
unsigned int V_41 ;
if ( ! V_11 -> V_42 ) {
F_2 ( V_7 , & V_39 ) ;
if ( ! V_39 )
return V_31 ;
V_40 = F_12 ( & V_39 -> V_16 ) ;
if ( ! V_40 )
return 0 ;
}
for ( V_28 = V_24 ; V_28 < V_29 ; ) {
if ( ! V_11 -> V_43 . V_32 ) {
if ( V_11 -> V_43 . V_44 > 0 ) {
V_30 = V_11 -> V_43 . V_45 ;
if ( 4 - V_11 -> V_43 . V_44 > 0 ) {
memcpy ( ( T_1 * ) & V_30 +
V_11 -> V_43 . V_44 ,
V_28 ,
4 - V_11 -> V_43 . V_44 ) ;
V_28 += 4 - V_11 -> V_43 . V_44 ;
}
V_11 -> V_43 . V_44 = 0 ;
} else {
if ( V_28 + 3 >= V_29 ) {
V_11 -> V_43 . V_44 = V_29 - V_28 ;
memcpy ( & V_11 -> V_43 . V_45 , V_28 ,
V_11 -> V_43 . V_44 ) ;
return V_31 ;
}
for (; V_28 < V_29 - 3 ; V_28 ++ ) {
if ( * ( V_28 + 3 ) == 0x47 )
break;
}
V_30 = * ( unsigned long * ) V_28 ;
V_28 += 4 ;
}
V_35 = ( ( V_30 & 0x7e ) << 1 ) ;
if ( V_35 > 0 )
V_35 -= 4 ;
V_37 = ( V_30 >> 7 ) & 0xf ;
V_36 = ( V_30 >> 11 ) & 0x1 ;
line = ( V_30 >> 12 ) & 0x1ff ;
V_32 = ( V_30 >> 21 ) & 0x7 ;
if ( V_35 > V_46 )
V_35 = V_46 ;
V_34 = V_46 ;
switch ( V_32 ) {
case V_47 :
if ( ! V_11 -> V_42 ) {
if ( ( V_11 -> V_43 . V_48 != V_36 ) &&
( V_36 == 1 ) ) {
F_7 ( V_11 , V_7 , V_39 ) ;
F_5 ( V_11 , V_18 ,
L_3 ) ;
F_2 ( V_7 , & V_39 ) ;
if ( ! V_39 )
return V_31 ;
V_40 = F_12 ( & V_39 -> V_16 ) ;
if ( ! V_40 )
return V_31 ;
memset ( V_40 , 0 , V_39 -> V_16 . V_35 ) ;
}
V_41 = V_39 -> V_16 . V_49 << 1 ;
V_38 = ( ( line << 1 ) - V_36 - 1 ) *
V_41 + V_37 * V_46 ;
if ( V_38 + V_35 > V_39 -> V_16 . V_35 )
V_32 = V_50 ;
V_11 -> V_43 . V_48 = V_36 ;
}
break;
case V_51 :
break;
case V_52 :
case V_53 :
V_35 = V_34 ;
break;
}
} else {
V_32 = V_11 -> V_43 . V_32 ;
V_35 = V_11 -> V_43 . V_35 ;
V_38 = V_11 -> V_43 . V_38 ;
V_34 = V_11 -> V_43 . V_34 ;
V_36 = V_11 -> V_43 . V_36 ;
}
V_33 = ( V_29 - V_28 > V_35 ) ? V_35 : V_29 - V_28 ;
if ( V_33 ) {
switch ( V_32 ) {
case V_47 :
if ( V_39 )
memcpy ( & V_40 [ V_38 ] , V_28 , V_33 ) ;
break;
case V_52 : {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 += 2 )
F_13 ( ( V_54 * ) ( V_28 + V_3 ) ) ;
F_14 ( V_11 , V_55 , V_28 , V_33 ) ;
break;
}
case V_51 :
break;
case V_53 : {
T_2 V_56 ;
V_56 = * ( T_2 * ) V_28 ;
F_5 ( V_11 , V_18 , L_4 ,
V_36 , V_56 ) ;
break;
}
}
}
if ( V_28 + V_34 > V_29 ) {
V_11 -> V_43 . V_38 = V_38 + V_33 ;
V_11 -> V_43 . V_35 = V_35 - V_33 ;
V_11 -> V_43 . V_32 = V_32 ;
V_11 -> V_43 . V_36 = V_36 ;
V_11 -> V_43 . V_34 = V_34 - ( V_29 - V_28 ) ;
V_28 += V_29 - V_28 ;
} else {
V_11 -> V_43 . V_32 = 0 ;
V_28 += V_34 ;
}
}
return 0 ;
}
static int F_15 ( T_1 * V_28 , unsigned long V_25 ,
struct V_26 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
unsigned int V_38 = V_11 -> V_43 . V_38 , V_33 ;
int V_31 = 1 ;
struct V_8 * V_9 ;
char * V_57 = NULL ;
F_2 ( V_7 , & V_9 ) ;
if ( V_9 )
V_57 = F_12 ( & V_9 -> V_16 ) ;
if ( ! V_57 )
return 0 ;
while ( V_25 > 0 ) {
V_33 = F_16 ( V_25 , V_9 -> V_16 . V_35 - V_38 ) ;
memcpy ( & V_57 [ V_38 ] , V_28 , V_33 ) ;
V_38 += V_33 ;
V_28 += V_33 ;
V_25 -= V_33 ;
if ( V_38 >= V_9 -> V_16 . V_35 ) {
V_38 = 0 ;
F_7 ( V_11 , V_7 , V_9 ) ;
F_5 ( V_11 , V_18 , L_3 ) ;
F_2 ( V_7 , & V_9 ) ;
if ( ! V_9 )
break;
V_57 = F_12 ( & ( V_9 -> V_16 ) ) ;
if ( ! V_57 )
return V_31 ;
V_38 = 0 ;
}
}
V_11 -> V_43 . V_38 = V_38 ;
return V_31 ;
}
static inline void F_17 ( struct V_10 * V_11 ,
int V_58 , int V_59 )
{
char * V_60 = L_5 ;
switch ( V_59 ) {
case - V_61 :
V_60 = L_6 ;
break;
case - V_62 :
V_60 = L_7 ;
break;
case - V_63 :
V_60 = L_8 ;
break;
case - V_64 :
V_60 = L_9 ;
break;
case - V_65 :
V_60 = L_10 ;
break;
case - V_66 :
V_60 = L_11 ;
break;
case - V_67 :
V_60 = L_12 ;
break;
case - V_68 :
V_60 = L_13 ;
break;
}
if ( V_58 < 0 ) {
F_5 ( V_11 , V_14 , L_14 ,
V_59 , V_60 ) ;
} else {
F_5 ( V_11 , V_14 , L_15 ,
V_58 , V_59 , V_60 ) ;
}
}
static inline int F_18 ( struct V_26 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
int V_3 , V_25 = 0 , V_31 = 1 , V_59 ;
char * V_69 ;
if ( V_26 -> V_59 < 0 ) {
F_17 ( V_11 , - 1 , V_26 -> V_59 ) ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_26 -> V_70 ; V_3 ++ ) {
V_59 = V_26 -> V_71 [ V_3 ] . V_59 ;
if ( V_59 < 0 ) {
F_17 ( V_11 , V_3 , V_59 ) ;
continue;
}
V_25 = V_26 -> V_71 [ V_3 ] . V_72 ;
if ( V_25 > 0 ) {
V_69 = V_26 -> V_73 + V_26 -> V_71 [ V_3 ] . V_74 ;
if ( ! V_26 -> V_71 [ V_3 ] . V_59 ) {
if ( ( V_11 -> V_75 ) == V_76 ) {
V_31 = F_15 ( V_69 , V_25 , V_26 ) ;
if ( V_31 <= 0 )
return V_31 ;
} else {
F_11 ( V_69 , V_25 , V_26 ) ;
}
}
}
}
return V_31 ;
}
static void F_19 ( struct V_26 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
int V_3 ;
switch ( V_26 -> V_59 ) {
case 0 :
case - V_77 :
break;
case - V_62 :
case - V_61 :
case - V_78 :
return;
default:
F_20 ( L_16 , V_26 -> V_59 ) ;
break;
}
F_21 ( & V_11 -> V_79 ) ;
F_18 ( V_26 ) ;
F_22 ( & V_11 -> V_79 ) ;
for ( V_3 = 0 ; V_3 < V_26 -> V_70 ; V_3 ++ ) {
V_26 -> V_71 [ V_3 ] . V_59 = 0 ;
V_26 -> V_71 [ V_3 ] . V_72 = 0 ;
}
V_26 -> V_59 = F_23 ( V_26 , V_80 ) ;
if ( V_26 -> V_59 )
F_20 ( L_17 ,
V_26 -> V_59 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_26 * V_26 ;
int V_3 ;
V_11 -> V_43 . V_9 = NULL ;
for ( V_3 = 0 ; V_3 < V_11 -> V_43 . V_81 ; V_3 ++ ) {
V_26 = V_11 -> V_43 . V_26 [ V_3 ] ;
if ( V_26 ) {
F_25 ( V_26 ) ;
F_26 ( V_26 ) ;
if ( V_11 -> V_43 . V_73 [ V_3 ] ) {
F_27 ( V_11 -> V_82 ,
V_26 -> V_83 ,
V_11 -> V_43 . V_73 [ V_3 ] ,
V_26 -> V_84 ) ;
}
F_28 ( V_26 ) ;
V_11 -> V_43 . V_26 [ V_3 ] = NULL ;
}
V_11 -> V_43 . V_73 [ V_3 ] = NULL ;
}
F_29 ( V_11 -> V_43 . V_26 ) ;
F_29 ( V_11 -> V_43 . V_73 ) ;
V_11 -> V_43 . V_26 = NULL ;
V_11 -> V_43 . V_73 = NULL ;
V_11 -> V_43 . V_81 = 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_12 ;
int V_3 , V_85 , V_86 , V_87 , V_35 , V_88 , V_81 = 8 ;
struct V_26 * V_26 ;
F_24 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 -> V_82 ,
V_11 -> V_89 . V_90 ,
V_11 -> V_89 . V_91 ) ;
F_33 ( V_11 ) ;
V_87 = F_34 ( V_11 -> V_82 ,
V_11 -> V_89 . V_29 -> V_92 . V_93 &
V_94 ) ;
V_35 = F_35 ( V_11 -> V_82 , V_87 , F_36 ( V_87 ) ) ;
if ( V_35 > V_11 -> V_89 . V_95 )
V_35 = V_11 -> V_89 . V_95 ;
V_11 -> V_43 . V_96 = V_35 ;
V_88 = V_97 ;
V_86 = V_88 * V_35 ;
V_11 -> V_43 . V_81 = V_81 ;
V_11 -> V_43 . V_26 = F_37 ( sizeof( void * ) * V_81 , V_98 ) ;
if ( ! V_11 -> V_43 . V_26 ) {
F_20 ( L_18 ) ;
return - V_99 ;
}
V_11 -> V_43 . V_73 = F_37 ( sizeof( void * ) * V_81 ,
V_98 ) ;
if ( ! V_11 -> V_43 . V_73 ) {
F_20 ( L_19 ) ;
F_29 ( V_11 -> V_43 . V_26 ) ;
return - V_99 ;
}
F_5 ( V_11 , V_14 , L_20
L_21 ,
V_88 , V_81 , V_86 ,
V_11 -> V_89 . V_95 , V_35 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_43 . V_81 ; V_3 ++ ) {
V_26 = F_38 ( V_88 , V_98 ) ;
if ( ! V_26 ) {
F_20 ( L_22 , V_3 ) ;
F_24 ( V_11 ) ;
F_28 ( V_26 ) ;
return - V_99 ;
}
V_11 -> V_43 . V_26 [ V_3 ] = V_26 ;
V_11 -> V_43 . V_73 [ V_3 ] = F_39 ( V_11 -> V_82 ,
V_86 , V_98 , & V_26 -> V_84 ) ;
if ( ! V_11 -> V_43 . V_73 [ V_3 ] ) {
F_20 ( L_23
L_24 ,
V_86 , V_3 ,
F_40 () ? L_25 : L_26 ) ;
F_24 ( V_11 ) ;
return - V_99 ;
}
memset ( V_11 -> V_43 . V_73 [ V_3 ] , 0 , V_86 ) ;
F_41 ( V_26 , V_11 -> V_82 , V_87 ,
V_11 -> V_43 . V_73 [ V_3 ] , V_86 ,
F_19 , V_7 ) ;
V_26 -> V_100 = V_11 -> V_89 . V_29 -> V_92 . V_101 ;
V_26 -> V_70 = V_88 ;
V_26 -> V_102 = V_103 | V_104 ;
for ( V_85 = 0 ; V_85 < V_88 ; V_85 ++ ) {
V_26 -> V_71 [ V_85 ] . V_74 = V_35 * V_85 ;
V_26 -> V_71 [ V_85 ] . V_105 = V_35 ;
}
}
return 0 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_12 ;
int V_3 ;
V_7 -> V_106 = 0 ;
V_7 -> V_107 = V_108 ;
F_43 ( & V_7 -> V_109 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_43 . V_81 ; V_3 ++ ) {
int V_31 = F_23 ( V_11 -> V_43 . V_26 [ V_3 ] , V_80 ) ;
if ( V_31 ) {
F_20 ( L_27 , V_3 ,
V_31 ) ;
F_24 ( V_11 ) ;
return V_31 ;
}
}
return 0 ;
}
static int
F_44 ( struct V_110 * V_111 , unsigned int * V_112 , unsigned int * V_35 )
{
struct V_113 * V_114 = V_111 -> V_115 ;
* V_35 = V_114 -> V_116 -> V_117 * V_114 -> V_49 * V_114 -> V_118 >> 3 ;
if ( 0 == * V_112 )
* V_112 = V_119 ;
if ( * V_112 < V_120 )
* V_112 = V_120 ;
while ( * V_35 * * V_112 > V_121 * 1024 * 1024 )
( * V_112 ) -- ;
return 0 ;
}
static void F_45 ( struct V_110 * V_111 , struct V_8 * V_9 )
{
struct V_113 * V_114 = V_111 -> V_115 ;
struct V_10 * V_11 = V_114 -> V_11 ;
unsigned long V_122 ;
if ( F_40 () )
F_46 () ;
F_47 ( & V_11 -> V_79 , V_122 ) ;
if ( V_11 -> V_43 . V_9 == V_9 )
V_11 -> V_43 . V_9 = NULL ;
F_48 ( & V_11 -> V_79 , V_122 ) ;
F_49 ( & V_9 -> V_16 ) ;
V_9 -> V_16 . V_19 = V_123 ;
}
static int
F_50 ( struct V_110 * V_111 , struct V_124 * V_16 ,
enum V_125 V_36 )
{
struct V_113 * V_114 = V_111 -> V_115 ;
struct V_8 * V_9 = F_3 ( V_16 , struct V_8 , V_16 ) ;
struct V_10 * V_11 = V_114 -> V_11 ;
int V_31 = 0 ;
F_51 ( NULL == V_114 -> V_116 ) ;
V_9 -> V_16 . V_35 = V_114 -> V_116 -> V_117 * V_114 -> V_49 * V_114 -> V_118 >> 3 ;
if ( 0 != V_9 -> V_16 . V_126 && V_9 -> V_16 . V_127 < V_9 -> V_16 . V_35 )
return - V_128 ;
if ( V_9 -> V_116 != V_114 -> V_116 ||
V_9 -> V_16 . V_49 != V_114 -> V_49 ||
V_9 -> V_16 . V_118 != V_114 -> V_118 ||
V_9 -> V_16 . V_36 != V_36 ) {
V_9 -> V_116 = V_114 -> V_116 ;
V_9 -> V_16 . V_49 = V_114 -> V_49 ;
V_9 -> V_16 . V_118 = V_114 -> V_118 ;
V_9 -> V_16 . V_36 = V_36 ;
V_9 -> V_16 . V_19 = V_123 ;
}
if ( V_123 == V_9 -> V_16 . V_19 ) {
V_31 = F_52 ( V_111 , & V_9 -> V_16 , NULL ) ;
if ( V_31 != 0 )
goto V_129;
}
if ( ! V_11 -> V_43 . V_81 ) {
V_31 = F_30 ( V_11 ) ;
if ( V_31 < 0 )
goto V_129;
V_31 = F_42 ( V_11 ) ;
if ( V_31 < 0 )
goto V_129;
}
V_9 -> V_16 . V_19 = V_130 ;
return 0 ;
V_129:
F_45 ( V_111 , V_9 ) ;
return V_31 ;
}
static void
F_53 ( struct V_110 * V_111 , struct V_124 * V_16 )
{
struct V_8 * V_9 = F_3 ( V_16 , struct V_8 , V_16 ) ;
struct V_113 * V_114 = V_111 -> V_115 ;
struct V_10 * V_11 = V_114 -> V_11 ;
struct V_6 * V_12 = & V_11 -> V_12 ;
V_9 -> V_16 . V_19 = V_131 ;
F_54 ( & V_9 -> V_16 . V_17 , & V_12 -> V_13 ) ;
}
static void F_55 ( struct V_110 * V_111 , struct V_124 * V_16 )
{
struct V_8 * V_9 = F_3 ( V_16 , struct V_8 , V_16 ) ;
F_45 ( V_111 , V_9 ) ;
}
static bool F_56 ( struct V_10 * V_11 , struct V_113 * V_114 )
{
if ( V_11 -> V_132 == V_114 && V_11 -> F_56 )
return true ;
return false ;
}
static bool F_57 ( struct V_10 * V_11 , struct V_113 * V_114 )
{
if ( V_11 -> V_132 == V_114 )
return true ;
return false ;
}
static bool F_58 ( struct V_10 * V_11 , struct V_113 * V_114 ,
bool F_56 )
{
if ( V_11 -> V_132 == V_114 && V_11 -> F_56 == F_56 )
return true ;
if ( V_11 -> V_132 )
return false ;
V_11 -> V_132 = V_114 ;
V_11 -> F_56 = F_56 ;
F_5 ( V_11 , V_133 , L_28 ) ;
return true ;
}
static void F_59 ( struct V_10 * V_11 , struct V_113 * V_114 )
{
if ( V_11 -> V_132 != V_114 )
return;
V_11 -> V_132 = NULL ;
F_5 ( V_11 , V_133 , L_29 ) ;
}
static int F_60 ( struct V_134 * V_134 , void * V_135 ,
struct V_136 * V_137 )
{
struct V_10 * V_11 = ( (struct V_113 * ) V_135 ) -> V_11 ;
F_61 ( V_137 -> V_138 , L_30 , sizeof( V_137 -> V_138 ) ) ;
F_61 ( V_137 -> V_139 , L_31 , sizeof( V_137 -> V_139 ) ) ;
V_137 -> V_140 = V_141 |
V_142 |
V_143 |
V_144 ;
if ( V_11 -> V_145 != V_146 )
V_137 -> V_140 |= V_147 ;
return 0 ;
}
static int F_62 ( struct V_134 * V_134 , void * V_135 ,
struct V_148 * V_149 )
{
if ( F_63 ( V_149 -> V_150 >= F_64 ( V_151 ) ) )
return - V_128 ;
F_61 ( V_149 -> V_152 , V_151 [ V_149 -> V_150 ] . V_153 , sizeof( V_149 -> V_152 ) ) ;
V_149 -> V_154 = V_151 [ V_149 -> V_150 ] . V_75 ;
return 0 ;
}
static int F_65 ( struct V_134 * V_134 , void * V_135 ,
struct V_155 * V_149 )
{
struct V_113 * V_114 = V_135 ;
V_149 -> V_116 . V_156 . V_49 = V_114 -> V_49 ;
V_149 -> V_116 . V_156 . V_118 = V_114 -> V_118 ;
V_149 -> V_116 . V_156 . V_36 = V_114 -> V_157 . V_36 ;
V_149 -> V_116 . V_156 . V_154 = V_114 -> V_116 -> V_75 ;
V_149 -> V_116 . V_156 . V_158 =
( V_149 -> V_116 . V_156 . V_49 * V_114 -> V_116 -> V_117 ) >> 3 ;
V_149 -> V_116 . V_156 . V_159 =
V_149 -> V_116 . V_156 . V_118 * V_149 -> V_116 . V_156 . V_158 ;
return 0 ;
}
static struct V_160 * F_66 ( unsigned int V_75 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_64 ( V_151 ) ; V_3 ++ )
if ( V_151 [ V_3 ] . V_75 == V_75 )
return V_151 + V_3 ;
return NULL ;
}
static int F_67 ( struct V_134 * V_134 , void * V_135 ,
struct V_155 * V_149 )
{
struct V_10 * V_11 = ( (struct V_113 * ) V_135 ) -> V_11 ;
struct V_160 * V_116 ;
enum V_125 V_36 ;
V_116 = F_66 ( V_149 -> V_116 . V_156 . V_154 ) ;
if ( NULL == V_116 ) {
F_5 ( V_11 , V_161 , L_32
L_33 , V_149 -> V_116 . V_156 . V_154 ) ;
return - V_128 ;
}
V_36 = V_149 -> V_116 . V_156 . V_36 ;
if ( V_36 == V_162 )
V_36 = V_163 ;
else if ( V_164 != V_36 ) {
F_5 ( V_11 , V_161 , L_34 ) ;
return - V_128 ;
}
F_68 ( V_11 ) ;
V_149 -> V_116 . V_156 . V_49 = V_11 -> V_49 ;
V_149 -> V_116 . V_156 . V_118 = V_11 -> V_118 ;
V_149 -> V_116 . V_156 . V_49 &= ~ 0x01 ;
V_149 -> V_116 . V_156 . V_36 = V_36 ;
V_149 -> V_116 . V_156 . V_158 =
( V_149 -> V_116 . V_156 . V_49 * V_116 -> V_117 ) >> 3 ;
V_149 -> V_116 . V_156 . V_159 =
V_149 -> V_116 . V_156 . V_118 * V_149 -> V_116 . V_156 . V_158 ;
return 0 ;
}
static int F_69 ( struct V_134 * V_134 , void * V_135 ,
struct V_155 * V_149 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
int V_165 = F_67 ( V_134 , V_114 , V_149 ) ;
if ( V_165 < 0 )
return V_165 ;
V_114 -> V_116 = F_66 ( V_149 -> V_116 . V_156 . V_154 ) ;
V_114 -> V_49 = V_149 -> V_116 . V_156 . V_49 ;
V_114 -> V_118 = V_149 -> V_116 . V_156 . V_118 ;
V_114 -> V_157 . V_36 = V_149 -> V_116 . V_156 . V_36 ;
V_114 -> type = V_149 -> type ;
V_11 -> V_75 = V_149 -> V_116 . V_156 . V_154 ;
F_70 ( V_11 ) ;
return 0 ;
}
static int F_71 ( struct V_134 * V_134 , void * V_135 ,
struct V_166 * V_69 )
{
struct V_113 * V_114 = V_135 ;
return F_72 ( & V_114 -> V_157 , V_69 ) ;
}
static int F_73 ( struct V_134 * V_134 , void * V_135 ,
struct V_167 * V_69 )
{
struct V_113 * V_114 = V_135 ;
return F_74 ( & V_114 -> V_157 , V_69 ) ;
}
static int F_75 ( struct V_134 * V_134 , void * V_135 , struct V_167 * V_69 )
{
struct V_113 * V_114 = V_135 ;
return F_76 ( & V_114 -> V_157 , V_69 ) ;
}
static int F_77 ( struct V_134 * V_134 , void * V_135 , struct V_167 * V_69 )
{
struct V_113 * V_114 = V_135 ;
return F_78 ( & V_114 -> V_157 , V_69 ,
V_134 -> V_168 & V_169 ) ;
}
static int F_79 ( struct V_134 * V_134 , void * V_135 , enum V_170 V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_114 -> type != V_171 )
return - V_128 ;
if ( V_3 != V_114 -> type )
return - V_128 ;
if ( ! F_58 ( V_11 , V_114 , false ) )
return - V_172 ;
return F_80 ( & V_114 -> V_157 ) ;
}
static int F_81 ( struct V_134 * V_134 , void * V_135 , enum V_170 V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_114 -> type != V_171 )
return - V_128 ;
if ( V_3 != V_114 -> type )
return - V_128 ;
F_82 ( & V_114 -> V_157 ) ;
F_59 ( V_11 , V_114 ) ;
return 0 ;
}
static int F_83 ( struct V_134 * V_134 , void * V_135 , T_3 * V_173 )
{
int V_31 = 0 ;
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
V_11 -> V_173 = * V_173 ;
V_31 = F_84 ( V_11 ) ;
V_114 -> V_49 = V_11 -> V_49 ;
V_114 -> V_118 = V_11 -> V_118 ;
if ( V_31 < 0 )
return V_31 ;
F_85 ( & V_11 -> V_174 , 0 , V_175 , V_176 , V_11 -> V_173 ) ;
return 0 ;
}
static int F_86 ( struct V_134 * V_134 , void * V_135 ,
struct V_177 * V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
unsigned int V_178 ;
V_178 = V_3 -> V_150 ;
if ( V_178 >= 3 )
return - V_128 ;
if ( ! V_11 -> V_179 [ V_178 ] . type )
return - V_128 ;
V_3 -> V_150 = V_178 ;
if ( V_11 -> V_179 [ V_178 ] . type == V_180 )
V_3 -> type = V_181 ;
else
V_3 -> type = V_182 ;
strcpy ( V_3 -> V_153 , V_183 [ V_11 -> V_179 [ V_178 ] . type ] ) ;
V_3 -> V_184 = V_185 ;
return 0 ;
}
static int F_87 ( struct V_134 * V_134 , void * V_135 , unsigned int * V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
* V_3 = V_11 -> V_186 ;
return 0 ;
}
static int F_88 ( struct V_134 * V_134 , void * V_135 , unsigned int V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
int V_31 = 0 ;
if ( V_3 >= 3 )
return - V_128 ;
if ( ! V_11 -> V_179 [ V_3 ] . type )
return - V_128 ;
V_11 -> V_186 = V_3 ;
V_31 = F_83 ( V_134 , V_135 , & V_11 -> V_187 -> V_188 ) ;
return V_31 ;
}
static int F_89 ( struct V_134 * V_134 , void * V_135 ,
struct V_1 * V_189 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_64 ( V_5 ) ; V_3 ++ )
if ( V_189 -> V_2 && V_189 -> V_2 == V_5 [ V_3 ] . V_2 ) {
memcpy ( V_189 , & ( V_5 [ V_3 ] ) ,
sizeof( * V_189 ) ) ;
return 0 ;
}
return - V_128 ;
}
static int F_90 ( struct V_134 * V_134 , void * V_135 ,
struct V_190 * V_191 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
int V_192 ;
switch ( V_191 -> V_2 ) {
case V_193 :
V_192 = F_91 ( V_11 , V_194 , 0 ) ;
break;
case V_195 :
V_192 = F_91 ( V_11 , V_196 , 0 ) ;
return 0 ;
case V_197 :
V_192 = F_91 ( V_11 , V_198 , 0 ) ;
return 0 ;
case V_199 :
V_192 = F_91 ( V_11 , V_200 , 0 ) ;
return 0 ;
case V_201 :
V_192 = V_11 -> V_202 ;
return 0 ;
case V_203 :
V_192 = V_11 -> V_204 ;
return 0 ;
default:
return - V_128 ;
}
if ( V_192 < 0 )
return V_192 ;
V_191 -> V_205 = V_192 ;
return 0 ;
}
static int F_92 ( struct V_134 * V_134 , void * V_135 ,
struct V_190 * V_191 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
T_1 V_192 = V_191 -> V_205 ;
switch ( V_191 -> V_2 ) {
case V_193 :
F_93 ( V_11 , V_194 , V_192 ) ;
return 0 ;
case V_195 :
F_93 ( V_11 , V_196 , V_192 ) ;
return 0 ;
case V_197 :
F_93 ( V_11 , V_198 , V_192 ) ;
return 0 ;
case V_199 :
F_93 ( V_11 , V_200 , V_192 ) ;
return 0 ;
case V_201 :
V_11 -> V_202 = V_192 ;
F_94 ( V_11 , V_192 ) ;
return 0 ;
case V_203 :
V_11 -> V_204 = V_192 ;
F_95 ( V_11 , V_192 ) ;
return 0 ;
}
return - V_128 ;
}
static int F_96 ( struct V_134 * V_134 , void * V_135 ,
struct V_206 * V_207 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( F_63 ( V_208 == V_11 -> V_145 ) )
return - V_128 ;
if ( 0 != V_207 -> V_150 )
return - V_128 ;
strcpy ( V_207 -> V_153 , L_35 ) ;
V_207 -> type = V_209 ;
V_207 -> V_210 = V_211 ;
V_207 -> V_212 = 0xffffffffUL ;
V_207 -> V_213 = V_214 ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_216 , V_207 ) ;
V_207 -> V_217 = V_11 -> V_218 ;
return 0 ;
}
static int F_97 ( struct V_134 * V_134 , void * V_135 ,
struct V_206 * V_207 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_208 == V_11 -> V_145 )
return - V_128 ;
if ( 0 != V_207 -> V_150 )
return - V_128 ;
V_11 -> V_218 = V_207 -> V_217 ;
F_5 ( V_11 , 3 , L_36 , V_207 -> V_217 ) ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_219 , V_207 ) ;
return 0 ;
}
static int F_98 ( struct V_134 * V_134 , void * V_135 ,
struct V_220 * V_149 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( F_63 ( V_208 == V_11 -> V_145 ) )
return - V_128 ;
V_149 -> type = V_114 -> V_42 ? V_221 : V_209 ;
V_149 -> V_222 = V_11 -> V_223 ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_224 , V_149 ) ;
return 0 ;
}
static int F_99 ( struct V_134 * V_134 , void * V_135 ,
struct V_220 * V_149 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( F_63 ( V_208 == V_11 -> V_145 ) )
return - V_128 ;
if ( F_63 ( V_149 -> V_215 != 0 ) )
return - V_128 ;
if ( 0 == V_114 -> V_42 && V_209 != V_149 -> type )
return - V_128 ;
if ( 1 == V_114 -> V_42 && V_221 != V_149 -> type )
return - V_128 ;
V_11 -> V_223 = V_149 -> V_222 ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_225 , V_149 ) ;
return 0 ;
}
static int F_100 ( struct V_134 * V_134 , void * V_135 ,
struct V_136 * V_137 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
strcpy ( V_137 -> V_138 , L_30 ) ;
F_61 ( V_137 -> V_139 , V_11 -> V_153 , sizeof( V_11 -> V_153 ) ) ;
sprintf ( V_137 -> V_227 , L_37 ,
F_101 ( V_11 -> V_82 -> V_228 . V_229 ) ,
F_101 ( V_11 -> V_82 -> V_228 . V_230 ) ) ;
V_137 -> V_231 = V_11 -> V_232 ;
V_137 -> V_140 = V_147 |
V_143 |
V_233 |
V_144 |
V_142 ;
return 0 ;
}
static int F_102 ( struct V_134 * V_134 , void * V_135 ,
struct V_206 * V_207 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( 0 != V_207 -> V_150 )
return - V_128 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
strcpy ( V_207 -> V_153 , L_38 ) ;
V_207 -> type = V_221 ;
V_207 -> V_213 = V_214 ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_216 , V_207 ) ;
return 0 ;
}
static int F_103 ( struct V_134 * V_134 , void * V_135 ,
struct V_206 * V_207 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( 0 != V_207 -> V_150 )
return - V_128 ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_219 , V_207 ) ;
return 0 ;
}
static int F_104 ( struct V_134 * V_134 , void * V_135 ,
struct V_177 * V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_3 -> V_150 != 0 )
return - V_128 ;
if ( ! V_11 -> V_234 . type )
return - V_128 ;
strcpy ( V_3 -> V_153 , L_38 ) ;
V_3 -> type = V_181 ;
return 0 ;
}
static int F_105 ( struct V_134 * V_235 , void * V_135 , unsigned int * V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_11 -> V_186 != 5 )
return - V_128 ;
* V_3 = V_11 -> V_186 - 5 ;
return 0 ;
}
static int F_106 ( struct V_134 * V_134 , void * V_135 ,
struct V_236 * V_237 )
{
memset ( V_237 , 0 , sizeof( * V_237 ) ) ;
strcpy ( V_237 -> V_153 , L_38 ) ;
return 0 ;
}
static int F_107 ( struct V_134 * V_134 , void * V_135 ,
const struct V_236 * V_237 )
{
return 0 ;
}
static int F_108 ( struct V_134 * V_235 , void * V_135 , unsigned int V_3 )
{
struct V_113 * V_114 = V_135 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_3 )
return - V_128 ;
if ( ! V_11 -> V_234 . type )
return - V_128 ;
V_11 -> V_186 = V_3 + 5 ;
return 0 ;
}
static int F_109 ( struct V_134 * V_134 , void * V_114 , T_3 * V_173 )
{
return 0 ;
}
static int F_110 ( struct V_134 * V_134 , void * V_135 ,
struct V_1 * V_238 )
{
const struct V_1 * V_191 ;
if ( V_238 -> V_2 < V_239 ||
V_238 -> V_2 >= V_240 )
return - V_128 ;
if ( V_238 -> V_2 == V_201 ) {
V_191 = F_1 ( V_238 -> V_2 ) ;
* V_238 = * V_191 ;
} else
* V_238 = V_241 ;
return 0 ;
}
static int F_111 ( struct V_134 * V_134 )
{
struct V_242 * V_243 = F_112 ( V_134 ) ;
struct V_10 * V_11 = F_113 ( V_134 ) ;
struct V_113 * V_114 ;
enum V_170 type = V_171 ;
int V_3 , V_31 ;
int V_42 = 0 ;
F_5 ( V_11 , V_244 , L_39 ,
F_114 ( V_243 ) ) ;
switch ( V_243 -> V_245 ) {
case V_246 :
type = V_171 ;
break;
case V_247 :
type = V_248 ;
break;
case V_249 :
V_42 = 1 ;
break;
}
V_11 -> V_250 ++ ;
F_5 ( V_11 , V_244 , L_40 ,
F_114 ( V_243 ) , V_251 [ type ] ,
V_11 -> V_250 ) ;
V_114 = F_115 ( sizeof( * V_114 ) , V_98 ) ;
if ( NULL == V_114 ) {
V_11 -> V_250 -- ;
return - V_99 ;
}
V_134 -> V_226 = V_114 ;
V_114 -> V_11 = V_11 ;
V_114 -> V_42 = V_42 ;
V_11 -> V_42 = V_42 ;
V_114 -> type = type ;
V_11 -> V_75 = V_151 [ 0 ] . V_75 ;
V_114 -> V_116 = F_66 ( V_11 -> V_75 ) ;
F_68 ( V_11 ) ;
V_114 -> V_49 = V_11 -> V_49 ;
V_114 -> V_118 = V_11 -> V_118 ;
F_5 ( V_11 , V_244 , L_41
L_42 ,
( unsigned long ) V_114 , ( unsigned long ) V_11 ,
( unsigned long ) & V_11 -> V_12 ) ;
F_5 ( V_11 , V_244 , L_43
L_44 , F_4 ( & V_11 -> V_12 . V_252 ) ) ;
F_5 ( V_11 , V_244 , L_43
L_45 , F_4 ( & V_11 -> V_12 . V_13 ) ) ;
V_31 = F_84 ( V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_11 -> V_253 != V_254 ) {
for ( V_3 = 0 ; V_3 < F_64 ( V_5 ) ; V_3 ++ )
V_255 [ V_3 ] = V_5 [ V_3 ] . V_256 ;
V_11 -> V_253 = V_254 ;
}
if ( ! V_114 -> V_42 ) {
F_116 ( & V_114 -> V_157 , & V_257 ,
NULL , & V_11 -> V_79 ,
V_114 -> type ,
V_164 ,
sizeof( struct V_8 ) , V_114 , & V_11 -> V_258 ) ;
} else {
F_5 ( V_11 , V_244 , L_46 ) ;
V_11 -> V_186 = 5 ;
F_117 ( V_11 ) ;
F_85 ( & V_11 -> V_174 , 0 , V_215 , V_259 ) ;
F_30 ( V_11 ) ;
F_42 ( V_11 ) ;
}
return 0 ;
}
static int F_118 ( struct V_134 * V_134 )
{
struct V_242 * V_243 = F_112 ( V_134 ) ;
int V_260 ;
F_119 ( V_243 -> V_258 ) ;
V_260 = F_111 ( V_134 ) ;
F_120 ( V_243 -> V_258 ) ;
return V_260 ;
}
static T_4
F_121 ( struct V_134 * V_134 , char T_5 * V_24 , T_6 V_112 , T_7 * V_38 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
if ( V_114 -> type == V_171 ) {
int V_260 ;
if ( ! F_58 ( V_114 -> V_11 , V_114 , true ) )
return - V_172 ;
if ( F_122 ( & V_11 -> V_258 ) )
return - V_261 ;
V_260 = F_123 ( & V_114 -> V_157 , V_24 , V_112 , V_38 , 0 ,
V_134 -> V_168 & V_169 ) ;
F_120 ( & V_11 -> V_258 ) ;
return V_260 ;
}
return 0 ;
}
static unsigned int
F_124 ( struct V_134 * V_134 , struct V_262 * V_263 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_8 * V_9 ;
if ( V_171 != V_114 -> type )
return V_264 ;
if ( ! ! F_57 ( V_114 -> V_11 , V_114 ) )
return V_264 ;
if ( ! F_56 ( V_114 -> V_11 , V_114 ) ) {
if ( F_4 ( & V_114 -> V_157 . V_265 ) )
return V_264 ;
V_9 = F_6 ( V_114 -> V_157 . V_265 . V_15 , struct V_8 , V_16 . V_265 ) ;
} else {
return F_125 ( V_134 , & V_114 -> V_157 , V_263 ) ;
}
F_126 ( V_134 , & V_9 -> V_16 . V_23 , V_263 ) ;
if ( V_9 -> V_16 . V_19 == V_20 ||
V_9 -> V_16 . V_19 == V_266 )
return V_267 | V_268 ;
return 0 ;
}
static unsigned int F_127 ( struct V_134 * V_134 , struct V_262 * V_263 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
unsigned int V_260 ;
F_119 ( & V_11 -> V_258 ) ;
V_260 = F_124 ( V_134 , V_263 ) ;
F_120 ( & V_11 -> V_258 ) ;
return V_260 ;
}
static int F_128 ( struct V_134 * V_134 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
struct V_242 * V_243 = F_112 ( V_134 ) ;
F_5 ( V_11 , V_244 , L_47 ,
F_114 ( V_243 ) , V_11 -> V_250 ) ;
F_119 ( & V_11 -> V_258 ) ;
V_11 -> V_250 -- ;
F_59 ( V_11 , V_114 ) ;
if ( ! V_11 -> V_250 ) {
F_24 ( V_11 ) ;
F_31 ( V_11 ) ;
F_129 ( V_11 -> V_82 ) ;
if ( V_11 -> V_269 . V_29 )
F_32 ( V_11 -> V_82 ,
V_11 -> V_89 . V_90 , 2 ) ;
else
F_32 ( V_11 -> V_82 ,
V_11 -> V_89 . V_90 , 0 ) ;
F_33 ( V_11 ) ;
if ( ! V_114 -> V_42 )
F_130 ( & V_114 -> V_157 ) ;
}
F_29 ( V_114 ) ;
F_120 ( & V_11 -> V_258 ) ;
return 0 ;
}
static int F_131 ( struct V_134 * V_134 , struct V_270 * V_271 )
{
struct V_113 * V_114 = V_134 -> V_226 ;
struct V_10 * V_11 = V_114 -> V_11 ;
int V_260 ;
if ( F_122 ( & V_11 -> V_258 ) )
return - V_261 ;
V_260 = F_132 ( & V_114 -> V_157 , V_271 ) ;
F_120 ( & V_11 -> V_258 ) ;
return V_260 ;
}
static struct V_242 * F_133 ( struct V_10 * V_11 ,
const struct V_242
* V_272 , const char * V_273 )
{
struct V_242 * V_187 ;
V_187 = F_134 () ;
if ( NULL == V_187 )
return NULL ;
* V_187 = * V_272 ;
V_187 -> V_174 = & V_11 -> V_174 ;
V_187 -> V_274 = V_275 ;
V_187 -> V_276 = V_277 ;
V_187 -> V_258 = & V_11 -> V_258 ;
snprintf ( V_187 -> V_153 , sizeof( V_187 -> V_153 ) , L_48 , V_11 -> V_153 , V_273 ) ;
F_135 ( V_187 , V_11 ) ;
return V_187 ;
}
int F_136 ( struct V_10 * V_11 )
{
int V_165 = - 1 ;
V_11 -> V_187 = F_133 ( V_11 , & V_278 , L_49 ) ;
if ( ! V_11 -> V_187 ) {
F_137 ( V_279 L_50 ,
V_11 -> V_153 ) ;
return - V_99 ;
}
F_138 ( & V_11 -> V_12 . V_13 ) ;
F_138 ( & V_11 -> V_12 . V_252 ) ;
V_165 = F_139 ( V_11 -> V_187 , V_246 , V_280 ) ;
if ( V_165 < 0 ) {
F_137 ( V_279 L_50 ,
V_11 -> V_153 ) ;
return V_165 ;
}
F_137 ( V_279 L_51 ,
V_11 -> V_153 , F_114 ( V_11 -> V_187 ) ) ;
if ( V_11 -> V_281 . V_282 ) {
V_11 -> V_283 = F_133 ( V_11 , & V_284 ,
L_52 ) ;
if ( ! V_11 -> V_283 ) {
F_137 ( V_279 L_53 ,
V_11 -> V_153 ) ;
V_165 = - V_285 ;
return V_165 ;
}
V_165 = F_139 ( V_11 -> V_283 , V_249 ,
V_286 ) ;
if ( V_165 < 0 ) {
F_137 ( V_279 L_53 ,
V_11 -> V_153 ) ;
return V_165 ;
}
F_137 ( V_279 L_51 ,
V_11 -> V_153 , F_114 ( V_11 -> V_283 ) ) ;
}
F_137 ( V_279 L_54 , V_165 ) ;
return V_165 ;
}
int F_140 ( struct V_10 * V_11 )
{
F_141 ( V_11 -> V_187 ) ;
if ( V_11 -> V_283 ) {
if ( F_142 ( V_11 -> V_283 ) )
F_141 ( V_11 -> V_283 ) ;
else
V_275 ( V_11 -> V_283 ) ;
V_11 -> V_283 = NULL ;
}
return 0 ;
}
int F_143 ( void )
{
return 0 ;
}
