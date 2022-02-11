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
char * V_13 ;
if ( F_4 ( & V_7 -> V_14 ) ) {
F_5 ( V_11 , V_15 , L_1 ) ;
* V_9 = NULL ;
return;
}
* V_9 = F_6 ( V_7 -> V_14 . V_16 ,
struct V_8 , V_17 . V_18 ) ;
V_13 = F_7 ( & ( * V_9 ) -> V_17 ) ;
return;
}
static inline void F_8 ( struct V_10 * V_11 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_5 ( V_11 , V_19 , L_2 , V_9 , V_9 -> V_17 . V_3 ) ;
V_9 -> V_17 . V_20 = V_21 ;
V_9 -> V_17 . V_22 ++ ;
F_9 ( & V_9 -> V_17 . V_23 ) ;
F_10 ( & V_9 -> V_17 . V_18 ) ;
F_11 ( & V_9 -> V_17 . V_24 ) ;
}
static int F_12 ( T_1 * V_25 , unsigned long V_26 ,
struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
T_1 * V_29 = V_25 , * V_30 = V_25 + V_26 , V_31 ;
unsigned long V_32 = 0 ;
int V_33 = 0 ;
unsigned int V_34 , V_35 , V_36 , V_37 , V_38 , V_39 , line , V_40 = 0 ;
struct V_8 * V_41 = NULL ;
char * V_42 = NULL ;
unsigned int V_43 ;
if ( ! V_11 -> V_44 ) {
F_2 ( V_7 , & V_41 ) ;
if ( ! V_41 )
return V_33 ;
V_42 = F_7 ( & V_41 -> V_17 ) ;
if ( ! V_42 )
return 0 ;
}
for ( V_29 = V_25 ; V_29 < V_30 ; ) {
if ( ! V_11 -> V_45 . V_34 ) {
if ( V_11 -> V_45 . V_46 > 0 ) {
V_32 = V_11 -> V_45 . V_47 ;
if ( 4 - V_11 -> V_45 . V_46 > 0 ) {
memcpy ( ( T_1 * ) & V_32 +
V_11 -> V_45 . V_46 ,
V_29 ,
4 - V_11 -> V_45 . V_46 ) ;
V_29 += 4 - V_11 -> V_45 . V_46 ;
}
V_11 -> V_45 . V_46 = 0 ;
} else {
if ( V_29 + 3 >= V_30 ) {
V_11 -> V_45 . V_46 = V_30 - V_29 ;
memcpy ( & V_11 -> V_45 . V_47 , V_29 ,
V_11 -> V_45 . V_46 ) ;
return V_33 ;
}
for (; V_29 < V_30 - 3 ; V_29 ++ ) {
if ( * ( V_29 + 3 ) == 0x47 )
break;
}
V_32 = * ( unsigned long * ) V_29 ;
V_29 += 4 ;
}
V_31 = ( V_32 >> 24 ) & 0xff ;
V_37 = ( ( V_32 & 0x7e ) << 1 ) ;
if ( V_37 > 0 )
V_37 -= 4 ;
V_39 = ( V_32 >> 7 ) & 0xf ;
V_38 = ( V_32 >> 11 ) & 0x1 ;
line = ( V_32 >> 12 ) & 0x1ff ;
V_34 = ( V_32 >> 21 ) & 0x7 ;
if ( V_37 > V_48 )
V_37 = V_48 ;
V_36 = V_48 ;
switch ( V_34 ) {
case V_49 :
if ( ! V_11 -> V_44 ) {
if ( ( V_11 -> V_45 . V_50 != V_38 ) &&
( V_38 == 1 ) ) {
F_8 ( V_11 , V_7 , V_41 ) ;
F_5 ( V_11 , V_19 ,
L_3 ) ;
F_2 ( V_7 , & V_41 ) ;
if ( ! V_41 )
return V_33 ;
V_42 = F_7 ( & V_41 -> V_17 ) ;
if ( ! V_42 )
return V_33 ;
memset ( V_42 , 0 , V_41 -> V_17 . V_37 ) ;
}
V_43 = V_41 -> V_17 . V_51 << 1 ;
V_40 = ( ( line << 1 ) - V_38 - 1 ) *
V_43 + V_39 * V_48 ;
if ( V_40 + V_37 > V_41 -> V_17 . V_37 )
V_34 = V_52 ;
V_11 -> V_45 . V_50 = V_38 ;
}
break;
case V_53 :
break;
case V_54 :
case V_55 :
V_37 = V_36 ;
break;
}
} else {
V_34 = V_11 -> V_45 . V_34 ;
V_37 = V_11 -> V_45 . V_37 ;
V_40 = V_11 -> V_45 . V_40 ;
V_36 = V_11 -> V_45 . V_36 ;
V_38 = V_11 -> V_45 . V_38 ;
}
V_35 = ( V_30 - V_29 > V_37 ) ? V_37 : V_30 - V_29 ;
if ( V_35 ) {
switch ( V_34 ) {
case V_49 :
if ( V_41 )
memcpy ( & V_42 [ V_40 ] , V_29 , V_35 ) ;
break;
case V_54 : {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_35 ; V_3 += 2 )
F_13 ( ( V_56 * ) ( V_29 + V_3 ) ) ;
F_14 ( V_11 , V_57 , V_29 , V_35 ) ;
break;
}
case V_53 :
break;
case V_55 : {
T_2 V_58 ;
V_58 = * ( T_2 * ) V_29 ;
F_5 ( V_11 , V_19 , L_4 ,
V_38 , V_58 ) ;
break;
}
}
}
if ( V_29 + V_36 > V_30 ) {
V_11 -> V_45 . V_40 = V_40 + V_35 ;
V_11 -> V_45 . V_37 = V_37 - V_35 ;
V_11 -> V_45 . V_34 = V_34 ;
V_11 -> V_45 . V_38 = V_38 ;
V_11 -> V_45 . V_36 = V_36 - ( V_30 - V_29 ) ;
V_29 += V_30 - V_29 ;
} else {
V_11 -> V_45 . V_34 = 0 ;
V_29 += V_36 ;
}
}
return 0 ;
}
static int F_15 ( T_1 * V_29 , unsigned long V_26 ,
struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
unsigned int V_40 = V_11 -> V_45 . V_40 , V_35 ;
int V_33 = 1 ;
struct V_8 * V_9 ;
char * V_13 = NULL ;
F_2 ( V_7 , & V_9 ) ;
if ( V_9 )
V_13 = F_7 ( & V_9 -> V_17 ) ;
if ( ! V_13 )
return 0 ;
while ( V_26 > 0 ) {
V_35 = F_16 ( V_26 , V_9 -> V_17 . V_37 - V_40 ) ;
memcpy ( & V_13 [ V_40 ] , V_29 , V_35 ) ;
V_40 += V_35 ;
V_29 += V_35 ;
V_26 -= V_35 ;
if ( V_40 >= V_9 -> V_17 . V_37 ) {
V_40 = 0 ;
F_8 ( V_11 , V_7 , V_9 ) ;
F_5 ( V_11 , V_19 , L_3 ) ;
F_2 ( V_7 , & V_9 ) ;
if ( ! V_9 )
break;
V_13 = F_7 ( & ( V_9 -> V_17 ) ) ;
if ( ! V_13 )
return V_33 ;
V_40 = 0 ;
}
}
V_11 -> V_45 . V_40 = V_40 ;
return V_33 ;
}
static inline void F_17 ( struct V_10 * V_11 ,
int V_59 , int V_60 )
{
char * V_61 = L_5 ;
switch ( V_60 ) {
case - V_62 :
V_61 = L_6 ;
break;
case - V_63 :
V_61 = L_7 ;
break;
case - V_64 :
V_61 = L_8 ;
break;
case - V_65 :
V_61 = L_9 ;
break;
case - V_66 :
V_61 = L_10 ;
break;
case - V_67 :
V_61 = L_11 ;
break;
case - V_68 :
V_61 = L_12 ;
break;
case - V_69 :
V_61 = L_13 ;
break;
}
if ( V_59 < 0 ) {
F_5 ( V_11 , V_15 , L_14 ,
V_60 , V_61 ) ;
} else {
F_5 ( V_11 , V_15 , L_15 ,
V_59 , V_60 , V_61 ) ;
}
}
static inline int F_18 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
int V_3 , V_26 = 0 , V_33 = 1 , V_60 ;
char * V_70 ;
if ( V_27 -> V_60 < 0 ) {
F_17 ( V_11 , - 1 , V_27 -> V_60 ) ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_71 ; V_3 ++ ) {
V_60 = V_27 -> V_72 [ V_3 ] . V_60 ;
if ( V_60 < 0 ) {
F_17 ( V_11 , V_3 , V_60 ) ;
continue;
}
V_26 = V_27 -> V_72 [ V_3 ] . V_73 ;
if ( V_26 > 0 ) {
V_70 = V_27 -> V_74 + V_27 -> V_72 [ V_3 ] . V_75 ;
if ( ! V_27 -> V_72 [ V_3 ] . V_60 ) {
if ( ( V_11 -> V_76 ) == V_77 ) {
V_33 = F_15 ( V_70 , V_26 , V_27 ) ;
if ( V_33 <= 0 )
return V_33 ;
} else {
F_12 ( V_70 , V_26 , V_27 ) ;
}
}
}
}
return V_33 ;
}
static void F_19 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
struct V_10 * V_11 = F_3 ( V_7 , struct V_10 , V_12 ) ;
int V_3 ;
switch ( V_27 -> V_60 ) {
case 0 :
case - V_78 :
break;
case - V_63 :
case - V_62 :
case - V_79 :
return;
default:
F_20 ( L_16 , V_27 -> V_60 ) ;
break;
}
F_21 ( & V_11 -> V_80 ) ;
F_18 ( V_27 ) ;
F_22 ( & V_11 -> V_80 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_71 ; V_3 ++ ) {
V_27 -> V_72 [ V_3 ] . V_60 = 0 ;
V_27 -> V_72 [ V_3 ] . V_73 = 0 ;
}
V_27 -> V_60 = F_23 ( V_27 , V_81 ) ;
if ( V_27 -> V_60 )
F_20 ( L_17 ,
V_27 -> V_60 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_27 * V_27 ;
int V_3 ;
V_11 -> V_45 . V_9 = NULL ;
for ( V_3 = 0 ; V_3 < V_11 -> V_45 . V_82 ; V_3 ++ ) {
V_27 = V_11 -> V_45 . V_27 [ V_3 ] ;
if ( V_27 ) {
F_25 ( V_27 ) ;
F_26 ( V_27 ) ;
if ( V_11 -> V_45 . V_74 [ V_3 ] ) {
F_27 ( V_11 -> V_83 ,
V_27 -> V_84 ,
V_11 -> V_45 . V_74 [ V_3 ] ,
V_27 -> V_85 ) ;
}
F_28 ( V_27 ) ;
V_11 -> V_45 . V_27 [ V_3 ] = NULL ;
}
V_11 -> V_45 . V_74 [ V_3 ] = NULL ;
}
F_29 ( V_11 -> V_45 . V_27 ) ;
F_29 ( V_11 -> V_45 . V_74 ) ;
V_11 -> V_45 . V_27 = NULL ;
V_11 -> V_45 . V_74 = NULL ;
V_11 -> V_45 . V_82 = 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_12 ;
int V_3 , V_86 , V_87 , V_88 , V_37 , V_89 , V_82 = 8 ;
struct V_27 * V_27 ;
F_24 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 -> V_83 ,
V_11 -> V_90 . V_91 ,
V_11 -> V_90 . V_92 ) ;
F_33 ( V_11 ) ;
V_88 = F_34 ( V_11 -> V_83 ,
V_11 -> V_90 . V_30 -> V_93 . V_94 &
V_95 ) ;
V_37 = F_35 ( V_11 -> V_83 , V_88 , F_36 ( V_88 ) ) ;
if ( V_37 > V_11 -> V_90 . V_96 )
V_37 = V_11 -> V_90 . V_96 ;
V_11 -> V_45 . V_97 = V_37 ;
V_89 = V_98 ;
V_87 = V_89 * V_37 ;
V_11 -> V_45 . V_82 = V_82 ;
V_11 -> V_45 . V_27 = F_37 ( sizeof( void * ) * V_82 , V_99 ) ;
if ( ! V_11 -> V_45 . V_27 ) {
F_20 ( L_18 ) ;
return - V_100 ;
}
V_11 -> V_45 . V_74 = F_37 ( sizeof( void * ) * V_82 ,
V_99 ) ;
if ( ! V_11 -> V_45 . V_74 ) {
F_20 ( L_19 ) ;
F_29 ( V_11 -> V_45 . V_27 ) ;
return - V_100 ;
}
F_5 ( V_11 , V_15 , L_20
L_21 ,
V_89 , V_82 , V_87 ,
V_11 -> V_90 . V_96 , V_37 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_45 . V_82 ; V_3 ++ ) {
V_27 = F_38 ( V_89 , V_99 ) ;
if ( ! V_27 ) {
F_20 ( L_22 , V_3 ) ;
F_24 ( V_11 ) ;
F_28 ( V_27 ) ;
return - V_100 ;
}
V_11 -> V_45 . V_27 [ V_3 ] = V_27 ;
V_11 -> V_45 . V_74 [ V_3 ] = F_39 ( V_11 -> V_83 ,
V_87 , V_99 , & V_27 -> V_85 ) ;
if ( ! V_11 -> V_45 . V_74 [ V_3 ] ) {
F_20 ( L_23
L_24 ,
V_87 , V_3 ,
F_40 () ? L_25 : L_26 ) ;
F_24 ( V_11 ) ;
return - V_100 ;
}
memset ( V_11 -> V_45 . V_74 [ V_3 ] , 0 , V_87 ) ;
F_41 ( V_27 , V_11 -> V_83 , V_88 ,
V_11 -> V_45 . V_74 [ V_3 ] , V_87 ,
F_19 , V_7 ) ;
V_27 -> V_101 = V_11 -> V_90 . V_30 -> V_93 . V_102 ;
V_27 -> V_71 = V_89 ;
V_27 -> V_103 = V_104 | V_105 ;
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
V_27 -> V_72 [ V_86 ] . V_75 = V_37 * V_86 ;
V_27 -> V_72 [ V_86 ] . V_106 = V_37 ;
}
}
return 0 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_12 ;
int V_3 ;
V_7 -> V_107 = 0 ;
V_7 -> V_108 = V_109 ;
F_43 ( & V_7 -> V_110 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_45 . V_82 ; V_3 ++ ) {
int V_33 = F_23 ( V_11 -> V_45 . V_27 [ V_3 ] , V_81 ) ;
if ( V_33 ) {
F_20 ( L_27 , V_3 ,
V_33 ) ;
F_24 ( V_11 ) ;
return V_33 ;
}
}
return 0 ;
}
static int
F_44 ( struct V_111 * V_112 , unsigned int * V_113 , unsigned int * V_37 )
{
struct V_114 * V_115 = V_112 -> V_116 ;
* V_37 = V_115 -> V_117 -> V_118 * V_115 -> V_51 * V_115 -> V_119 >> 3 ;
if ( 0 == * V_113 )
* V_113 = V_120 ;
if ( * V_113 < V_121 )
* V_113 = V_121 ;
while ( * V_37 * * V_113 > V_122 * 1024 * 1024 )
( * V_113 ) -- ;
return 0 ;
}
static void F_45 ( struct V_111 * V_112 , struct V_8 * V_9 )
{
struct V_114 * V_115 = V_112 -> V_116 ;
struct V_10 * V_11 = V_115 -> V_11 ;
unsigned long V_123 ;
if ( F_40 () )
F_46 () ;
F_47 ( & V_11 -> V_80 , V_123 ) ;
if ( V_11 -> V_45 . V_9 == V_9 )
V_11 -> V_45 . V_9 = NULL ;
F_48 ( & V_11 -> V_80 , V_123 ) ;
F_49 ( & V_9 -> V_17 ) ;
V_9 -> V_17 . V_20 = V_124 ;
}
static int
F_50 ( struct V_111 * V_112 , struct V_125 * V_17 ,
enum V_126 V_38 )
{
struct V_114 * V_115 = V_112 -> V_116 ;
struct V_8 * V_9 = F_3 ( V_17 , struct V_8 , V_17 ) ;
struct V_10 * V_11 = V_115 -> V_11 ;
int V_33 = 0 ;
F_51 ( NULL == V_115 -> V_117 ) ;
V_9 -> V_17 . V_37 = V_115 -> V_117 -> V_118 * V_115 -> V_51 * V_115 -> V_119 >> 3 ;
if ( 0 != V_9 -> V_17 . V_127 && V_9 -> V_17 . V_128 < V_9 -> V_17 . V_37 )
return - V_129 ;
if ( V_9 -> V_117 != V_115 -> V_117 ||
V_9 -> V_17 . V_51 != V_115 -> V_51 ||
V_9 -> V_17 . V_119 != V_115 -> V_119 ||
V_9 -> V_17 . V_38 != V_38 ) {
V_9 -> V_117 = V_115 -> V_117 ;
V_9 -> V_17 . V_51 = V_115 -> V_51 ;
V_9 -> V_17 . V_119 = V_115 -> V_119 ;
V_9 -> V_17 . V_38 = V_38 ;
V_9 -> V_17 . V_20 = V_124 ;
}
if ( V_124 == V_9 -> V_17 . V_20 ) {
V_33 = F_52 ( V_112 , & V_9 -> V_17 , NULL ) ;
if ( V_33 != 0 )
goto V_130;
}
if ( ! V_11 -> V_45 . V_82 ) {
V_33 = F_30 ( V_11 ) ;
if ( V_33 < 0 )
goto V_130;
V_33 = F_42 ( V_11 ) ;
if ( V_33 < 0 )
goto V_130;
}
V_9 -> V_17 . V_20 = V_131 ;
return 0 ;
V_130:
F_45 ( V_112 , V_9 ) ;
return V_33 ;
}
static void
F_53 ( struct V_111 * V_112 , struct V_125 * V_17 )
{
struct V_8 * V_9 = F_3 ( V_17 , struct V_8 , V_17 ) ;
struct V_114 * V_115 = V_112 -> V_116 ;
struct V_10 * V_11 = V_115 -> V_11 ;
struct V_6 * V_12 = & V_11 -> V_12 ;
V_9 -> V_17 . V_20 = V_132 ;
F_54 ( & V_9 -> V_17 . V_18 , & V_12 -> V_14 ) ;
}
static void F_55 ( struct V_111 * V_112 , struct V_125 * V_17 )
{
struct V_8 * V_9 = F_3 ( V_17 , struct V_8 , V_17 ) ;
F_45 ( V_112 , V_9 ) ;
}
static bool F_56 ( struct V_10 * V_11 , struct V_114 * V_115 )
{
if ( V_11 -> V_133 == V_115 && V_11 -> F_56 )
return true ;
return false ;
}
static bool F_57 ( struct V_10 * V_11 , struct V_114 * V_115 )
{
if ( V_11 -> V_133 == V_115 )
return true ;
return false ;
}
static bool F_58 ( struct V_10 * V_11 , struct V_114 * V_115 ,
bool F_56 )
{
if ( V_11 -> V_133 == V_115 && V_11 -> F_56 == F_56 )
return true ;
if ( V_11 -> V_133 )
return false ;
V_11 -> V_133 = V_115 ;
V_11 -> F_56 = F_56 ;
F_5 ( V_11 , V_134 , L_28 ) ;
return true ;
}
static void F_59 ( struct V_10 * V_11 , struct V_114 * V_115 )
{
if ( V_11 -> V_133 != V_115 )
return;
V_11 -> V_133 = NULL ;
F_5 ( V_11 , V_134 , L_29 ) ;
}
static int F_60 ( struct V_135 * V_135 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_10 * V_11 = ( (struct V_114 * ) V_136 ) -> V_11 ;
F_61 ( V_138 -> V_139 , L_30 , sizeof( V_138 -> V_139 ) ) ;
F_61 ( V_138 -> V_140 , L_31 , sizeof( V_138 -> V_140 ) ) ;
V_138 -> V_141 = V_142 ;
V_138 -> V_143 = V_144 |
V_145 |
V_146 |
V_147 ;
if ( V_11 -> V_148 != V_149 )
V_138 -> V_143 |= V_150 ;
return 0 ;
}
static int F_62 ( struct V_135 * V_135 , void * V_136 ,
struct V_151 * V_152 )
{
if ( F_63 ( V_152 -> V_153 >= F_64 ( V_154 ) ) )
return - V_129 ;
F_61 ( V_152 -> V_155 , V_154 [ V_152 -> V_153 ] . V_156 , sizeof( V_152 -> V_155 ) ) ;
V_152 -> V_157 = V_154 [ V_152 -> V_153 ] . V_76 ;
return 0 ;
}
static int F_65 ( struct V_135 * V_135 , void * V_136 ,
struct V_158 * V_152 )
{
struct V_114 * V_115 = V_136 ;
V_152 -> V_117 . V_159 . V_51 = V_115 -> V_51 ;
V_152 -> V_117 . V_159 . V_119 = V_115 -> V_119 ;
V_152 -> V_117 . V_159 . V_38 = V_115 -> V_160 . V_38 ;
V_152 -> V_117 . V_159 . V_157 = V_115 -> V_117 -> V_76 ;
V_152 -> V_117 . V_159 . V_161 =
( V_152 -> V_117 . V_159 . V_51 * V_115 -> V_117 -> V_118 ) >> 3 ;
V_152 -> V_117 . V_159 . V_162 =
V_152 -> V_117 . V_159 . V_119 * V_152 -> V_117 . V_159 . V_161 ;
return 0 ;
}
static struct V_163 * F_66 ( unsigned int V_76 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_64 ( V_154 ) ; V_3 ++ )
if ( V_154 [ V_3 ] . V_76 == V_76 )
return V_154 + V_3 ;
return NULL ;
}
static int F_67 ( struct V_135 * V_135 , void * V_136 ,
struct V_158 * V_152 )
{
struct V_10 * V_11 = ( (struct V_114 * ) V_136 ) -> V_11 ;
struct V_163 * V_117 ;
enum V_126 V_38 ;
V_117 = F_66 ( V_152 -> V_117 . V_159 . V_157 ) ;
if ( NULL == V_117 ) {
F_5 ( V_11 , V_164 , L_32
L_33 , V_152 -> V_117 . V_159 . V_157 ) ;
return - V_129 ;
}
V_38 = V_152 -> V_117 . V_159 . V_38 ;
if ( V_38 == V_165 )
V_38 = V_166 ;
else if ( V_167 != V_38 ) {
F_5 ( V_11 , V_164 , L_34 ) ;
return - V_129 ;
}
F_68 ( V_11 ) ;
V_152 -> V_117 . V_159 . V_51 = V_11 -> V_51 ;
V_152 -> V_117 . V_159 . V_119 = V_11 -> V_119 ;
V_152 -> V_117 . V_159 . V_51 &= ~ 0x01 ;
V_152 -> V_117 . V_159 . V_38 = V_38 ;
V_152 -> V_117 . V_159 . V_161 =
( V_152 -> V_117 . V_159 . V_51 * V_117 -> V_118 ) >> 3 ;
V_152 -> V_117 . V_159 . V_162 =
V_152 -> V_117 . V_159 . V_119 * V_152 -> V_117 . V_159 . V_161 ;
return 0 ;
}
static int F_69 ( struct V_135 * V_135 , void * V_136 ,
struct V_158 * V_152 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
int V_168 = F_67 ( V_135 , V_115 , V_152 ) ;
if ( V_168 < 0 )
return V_168 ;
V_115 -> V_117 = F_66 ( V_152 -> V_117 . V_159 . V_157 ) ;
V_115 -> V_51 = V_152 -> V_117 . V_159 . V_51 ;
V_115 -> V_119 = V_152 -> V_117 . V_159 . V_119 ;
V_115 -> V_160 . V_38 = V_152 -> V_117 . V_159 . V_38 ;
V_115 -> type = V_152 -> type ;
V_11 -> V_76 = V_152 -> V_117 . V_159 . V_157 ;
F_70 ( V_11 ) ;
return 0 ;
}
static int F_71 ( struct V_135 * V_135 , void * V_136 ,
struct V_169 * V_70 )
{
struct V_114 * V_115 = V_136 ;
return F_72 ( & V_115 -> V_160 , V_70 ) ;
}
static int F_73 ( struct V_135 * V_135 , void * V_136 ,
struct V_170 * V_70 )
{
struct V_114 * V_115 = V_136 ;
return F_74 ( & V_115 -> V_160 , V_70 ) ;
}
static int F_75 ( struct V_135 * V_135 , void * V_136 , struct V_170 * V_70 )
{
struct V_114 * V_115 = V_136 ;
return F_76 ( & V_115 -> V_160 , V_70 ) ;
}
static int F_77 ( struct V_135 * V_135 , void * V_136 , struct V_170 * V_70 )
{
struct V_114 * V_115 = V_136 ;
return F_78 ( & V_115 -> V_160 , V_70 ,
V_135 -> V_171 & V_172 ) ;
}
static int F_79 ( struct V_135 * V_135 , void * V_136 , enum V_173 V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( V_115 -> type != V_174 )
return - V_129 ;
if ( V_3 != V_115 -> type )
return - V_129 ;
if ( ! F_58 ( V_11 , V_115 , false ) )
return - V_175 ;
return F_80 ( & V_115 -> V_160 ) ;
}
static int F_81 ( struct V_135 * V_135 , void * V_136 , enum V_173 V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( V_115 -> type != V_174 )
return - V_129 ;
if ( V_3 != V_115 -> type )
return - V_129 ;
F_82 ( & V_115 -> V_160 ) ;
F_59 ( V_11 , V_115 ) ;
return 0 ;
}
static int F_83 ( struct V_135 * V_135 , void * V_136 , T_3 * V_176 )
{
int V_33 = 0 ;
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
V_11 -> V_176 = * V_176 ;
V_33 = F_84 ( V_11 ) ;
V_115 -> V_51 = V_11 -> V_51 ;
V_115 -> V_119 = V_11 -> V_119 ;
if ( V_33 < 0 )
return V_33 ;
F_85 ( & V_11 -> V_177 , 0 , V_178 , V_179 , V_11 -> V_176 ) ;
return 0 ;
}
static int F_86 ( struct V_135 * V_135 , void * V_136 ,
struct V_180 * V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
unsigned int V_181 ;
V_181 = V_3 -> V_153 ;
if ( V_181 >= 3 )
return - V_129 ;
if ( ! V_11 -> V_182 [ V_181 ] . type )
return - V_129 ;
V_3 -> V_153 = V_181 ;
if ( V_11 -> V_182 [ V_181 ] . type == V_183 )
V_3 -> type = V_184 ;
else
V_3 -> type = V_185 ;
strcpy ( V_3 -> V_156 , V_186 [ V_11 -> V_182 [ V_181 ] . type ] ) ;
V_3 -> V_187 = V_188 ;
return 0 ;
}
static int F_87 ( struct V_135 * V_135 , void * V_136 , unsigned int * V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
* V_3 = V_11 -> V_189 ;
return 0 ;
}
static int F_88 ( struct V_135 * V_135 , void * V_136 , unsigned int V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
int V_33 = 0 ;
if ( V_3 >= 3 )
return - V_129 ;
if ( ! V_11 -> V_182 [ V_3 ] . type )
return - V_129 ;
V_11 -> V_189 = V_3 ;
V_33 = F_83 ( V_135 , V_136 , & V_11 -> V_190 -> V_191 ) ;
return V_33 ;
}
static int F_89 ( struct V_135 * V_135 , void * V_136 ,
struct V_1 * V_192 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_64 ( V_5 ) ; V_3 ++ )
if ( V_192 -> V_2 && V_192 -> V_2 == V_5 [ V_3 ] . V_2 ) {
memcpy ( V_192 , & ( V_5 [ V_3 ] ) ,
sizeof( * V_192 ) ) ;
return 0 ;
}
return - V_129 ;
}
static int F_90 ( struct V_135 * V_135 , void * V_136 ,
struct V_193 * V_194 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
int V_195 ;
switch ( V_194 -> V_2 ) {
case V_196 :
V_195 = F_91 ( V_11 , V_197 , 0 ) ;
break;
case V_198 :
V_195 = F_91 ( V_11 , V_199 , 0 ) ;
return 0 ;
case V_200 :
V_195 = F_91 ( V_11 , V_201 , 0 ) ;
return 0 ;
case V_202 :
V_195 = F_91 ( V_11 , V_203 , 0 ) ;
return 0 ;
case V_204 :
V_195 = V_11 -> V_205 ;
return 0 ;
case V_206 :
V_195 = V_11 -> V_207 ;
return 0 ;
default:
return - V_129 ;
}
if ( V_195 < 0 )
return V_195 ;
V_194 -> V_208 = V_195 ;
return 0 ;
}
static int F_92 ( struct V_135 * V_135 , void * V_136 ,
struct V_193 * V_194 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
T_1 V_195 = V_194 -> V_208 ;
switch ( V_194 -> V_2 ) {
case V_196 :
F_93 ( V_11 , V_197 , V_195 ) ;
return 0 ;
case V_198 :
F_93 ( V_11 , V_199 , V_195 ) ;
return 0 ;
case V_200 :
F_93 ( V_11 , V_201 , V_195 ) ;
return 0 ;
case V_202 :
F_93 ( V_11 , V_203 , V_195 ) ;
return 0 ;
case V_204 :
V_11 -> V_205 = V_195 ;
F_94 ( V_11 , V_195 ) ;
return 0 ;
case V_206 :
V_11 -> V_207 = V_195 ;
F_95 ( V_11 , V_195 ) ;
return 0 ;
}
return - V_129 ;
}
static int F_96 ( struct V_135 * V_135 , void * V_136 ,
struct V_209 * V_210 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( F_63 ( V_211 == V_11 -> V_148 ) )
return - V_129 ;
if ( 0 != V_210 -> V_153 )
return - V_129 ;
strcpy ( V_210 -> V_156 , L_35 ) ;
V_210 -> type = V_212 ;
V_210 -> V_213 = V_214 ;
V_210 -> V_215 = 0xffffffffUL ;
V_210 -> V_216 = V_217 ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_219 , V_210 ) ;
V_210 -> V_220 = V_11 -> V_221 ;
return 0 ;
}
static int F_97 ( struct V_135 * V_135 , void * V_136 ,
struct V_209 * V_210 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( V_211 == V_11 -> V_148 )
return - V_129 ;
if ( 0 != V_210 -> V_153 )
return - V_129 ;
V_11 -> V_221 = V_210 -> V_220 ;
F_5 ( V_11 , 3 , L_36 , V_210 -> V_220 ) ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_222 , V_210 ) ;
return 0 ;
}
static int F_98 ( struct V_135 * V_135 , void * V_136 ,
struct V_223 * V_152 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( F_63 ( V_211 == V_11 -> V_148 ) )
return - V_129 ;
V_152 -> type = V_115 -> V_44 ? V_224 : V_212 ;
V_152 -> V_225 = V_11 -> V_226 ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_227 , V_152 ) ;
return 0 ;
}
static int F_99 ( struct V_135 * V_135 , void * V_136 ,
struct V_223 * V_152 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( F_63 ( V_211 == V_11 -> V_148 ) )
return - V_129 ;
if ( F_63 ( V_152 -> V_218 != 0 ) )
return - V_129 ;
if ( 0 == V_115 -> V_44 && V_212 != V_152 -> type )
return - V_129 ;
if ( 1 == V_115 -> V_44 && V_224 != V_152 -> type )
return - V_129 ;
V_11 -> V_226 = V_152 -> V_225 ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_228 , V_152 ) ;
return 0 ;
}
static int F_100 ( struct V_135 * V_135 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
struct V_10 * V_11 = V_115 -> V_11 ;
strcpy ( V_138 -> V_139 , L_30 ) ;
F_61 ( V_138 -> V_140 , V_11 -> V_156 , sizeof( V_11 -> V_156 ) ) ;
sprintf ( V_138 -> V_230 , L_37 ,
F_101 ( V_11 -> V_83 -> V_231 . V_232 ) ,
F_101 ( V_11 -> V_83 -> V_231 . V_233 ) ) ;
V_138 -> V_141 = V_11 -> V_234 ;
V_138 -> V_143 = V_150 |
V_146 |
V_235 |
V_147 |
V_145 ;
return 0 ;
}
static int F_102 ( struct V_135 * V_135 , void * V_136 ,
struct V_209 * V_210 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( 0 != V_210 -> V_153 )
return - V_129 ;
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
strcpy ( V_210 -> V_156 , L_38 ) ;
V_210 -> type = V_224 ;
V_210 -> V_216 = V_217 ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_219 , V_210 ) ;
return 0 ;
}
static int F_103 ( struct V_135 * V_135 , void * V_136 ,
struct V_209 * V_210 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( 0 != V_210 -> V_153 )
return - V_129 ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_222 , V_210 ) ;
return 0 ;
}
static int F_104 ( struct V_135 * V_135 , void * V_136 ,
struct V_180 * V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( V_3 -> V_153 != 0 )
return - V_129 ;
if ( ! V_11 -> V_236 . type )
return - V_129 ;
strcpy ( V_3 -> V_156 , L_38 ) ;
V_3 -> type = V_184 ;
return 0 ;
}
static int F_105 ( struct V_135 * V_237 , void * V_136 , unsigned int * V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( V_11 -> V_189 != 5 )
return - V_129 ;
* V_3 = V_11 -> V_189 - 5 ;
return 0 ;
}
static int F_106 ( struct V_135 * V_135 , void * V_136 ,
struct V_238 * V_239 )
{
memset ( V_239 , 0 , sizeof( * V_239 ) ) ;
strcpy ( V_239 -> V_156 , L_38 ) ;
return 0 ;
}
static int F_107 ( struct V_135 * V_135 , void * V_136 ,
struct V_238 * V_239 )
{
return 0 ;
}
static int F_108 ( struct V_135 * V_237 , void * V_136 , unsigned int V_3 )
{
struct V_114 * V_115 = V_136 ;
struct V_10 * V_11 = V_115 -> V_11 ;
if ( V_3 )
return - V_129 ;
if ( ! V_11 -> V_236 . type )
return - V_129 ;
V_11 -> V_189 = V_3 + 5 ;
return 0 ;
}
static int F_109 ( struct V_135 * V_135 , void * V_115 , T_3 * V_176 )
{
return 0 ;
}
static int F_110 ( struct V_135 * V_135 , void * V_136 ,
struct V_1 * V_31 )
{
const struct V_1 * V_194 ;
if ( V_31 -> V_2 < V_240 ||
V_31 -> V_2 >= V_241 )
return - V_129 ;
if ( V_31 -> V_2 == V_204 ) {
V_194 = F_1 ( V_31 -> V_2 ) ;
* V_31 = * V_194 ;
} else
* V_31 = V_242 ;
return 0 ;
}
static int F_111 ( struct V_135 * V_135 )
{
struct V_243 * V_244 = F_112 ( V_135 ) ;
struct V_10 * V_11 = F_113 ( V_135 ) ;
struct V_114 * V_115 ;
enum V_173 type = V_174 ;
int V_3 , V_33 ;
int V_44 = 0 ;
F_5 ( V_11 , V_245 , L_39 ,
F_114 ( V_244 ) ) ;
switch ( V_244 -> V_246 ) {
case V_247 :
type = V_174 ;
break;
case V_248 :
type = V_249 ;
break;
case V_250 :
V_44 = 1 ;
break;
}
V_11 -> V_251 ++ ;
F_5 ( V_11 , V_245 , L_40 ,
F_114 ( V_244 ) , V_252 [ type ] ,
V_11 -> V_251 ) ;
V_115 = F_115 ( sizeof( * V_115 ) , V_99 ) ;
if ( NULL == V_115 ) {
V_11 -> V_251 -- ;
return - V_100 ;
}
V_135 -> V_229 = V_115 ;
V_115 -> V_11 = V_11 ;
V_115 -> V_44 = V_44 ;
V_11 -> V_44 = V_44 ;
V_115 -> type = type ;
V_11 -> V_76 = V_154 [ 0 ] . V_76 ;
V_115 -> V_117 = F_66 ( V_11 -> V_76 ) ;
F_68 ( V_11 ) ;
V_115 -> V_51 = V_11 -> V_51 ;
V_115 -> V_119 = V_11 -> V_119 ;
F_5 ( V_11 , V_245 , L_41
L_42 ,
( unsigned long ) V_115 , ( unsigned long ) V_11 ,
( unsigned long ) & V_11 -> V_12 ) ;
F_5 ( V_11 , V_245 , L_43
L_44 , F_4 ( & V_11 -> V_12 . V_253 ) ) ;
F_5 ( V_11 , V_245 , L_43
L_45 , F_4 ( & V_11 -> V_12 . V_14 ) ) ;
V_33 = F_84 ( V_11 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_11 -> V_254 != V_255 ) {
for ( V_3 = 0 ; V_3 < F_64 ( V_5 ) ; V_3 ++ )
V_256 [ V_3 ] = V_5 [ V_3 ] . V_257 ;
V_11 -> V_254 = V_255 ;
}
if ( ! V_115 -> V_44 ) {
F_116 ( & V_115 -> V_160 , & V_258 ,
NULL , & V_11 -> V_80 ,
V_115 -> type ,
V_167 ,
sizeof( struct V_8 ) , V_115 , & V_11 -> V_259 ) ;
} else {
F_5 ( V_11 , V_245 , L_46 ) ;
V_11 -> V_189 = 5 ;
F_117 ( V_11 ) ;
F_85 ( & V_11 -> V_177 , 0 , V_218 , V_260 ) ;
F_30 ( V_11 ) ;
F_42 ( V_11 ) ;
}
return 0 ;
}
static T_4
F_118 ( struct V_135 * V_135 , char T_5 * V_25 , T_6 V_113 , T_7 * V_40 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
if ( V_115 -> type == V_174 ) {
if ( ! F_58 ( V_115 -> V_11 , V_115 , true ) )
return - V_175 ;
return F_119 ( & V_115 -> V_160 , V_25 , V_113 , V_40 , 0 ,
V_135 -> V_171 & V_172 ) ;
}
return 0 ;
}
static unsigned int
F_120 ( struct V_135 * V_135 , struct V_261 * V_262 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
struct V_8 * V_9 ;
if ( V_174 != V_115 -> type )
return V_263 ;
if ( ! ! F_57 ( V_115 -> V_11 , V_115 ) )
return V_263 ;
if ( ! F_56 ( V_115 -> V_11 , V_115 ) ) {
if ( F_4 ( & V_115 -> V_160 . V_264 ) )
return V_263 ;
V_9 = F_6 ( V_115 -> V_160 . V_264 . V_16 , struct V_8 , V_17 . V_264 ) ;
} else {
return F_121 ( V_135 , & V_115 -> V_160 , V_262 ) ;
}
F_122 ( V_135 , & V_9 -> V_17 . V_24 , V_262 ) ;
if ( V_9 -> V_17 . V_20 == V_21 ||
V_9 -> V_17 . V_20 == V_265 )
return V_266 | V_267 ;
return 0 ;
}
static int F_123 ( struct V_135 * V_135 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
struct V_10 * V_11 = V_115 -> V_11 ;
struct V_243 * V_244 = F_112 ( V_135 ) ;
F_5 ( V_11 , V_245 , L_47 ,
F_114 ( V_244 ) , V_11 -> V_251 ) ;
V_11 -> V_251 -- ;
F_59 ( V_11 , V_115 ) ;
if ( ! V_11 -> V_251 ) {
int V_268 ;
F_24 ( V_11 ) ;
if ( ! V_115 -> V_44 )
F_124 ( & V_115 -> V_160 ) ;
V_268 = F_125 ( V_11 ) ;
if ( V_268 < 0 )
F_126 ( & V_244 -> V_11 , L_48 , V_268 ) ;
}
F_29 ( V_115 ) ;
return 0 ;
}
static int F_127 ( struct V_135 * V_135 , struct V_269 * V_270 )
{
struct V_114 * V_115 = V_135 -> V_229 ;
return F_128 ( & V_115 -> V_160 , V_270 ) ;
}
static struct V_243 * F_129 ( struct V_10 * V_11 ,
const struct V_243
* V_271 , const char * V_272 )
{
struct V_243 * V_190 ;
V_190 = F_130 () ;
if ( NULL == V_190 )
return NULL ;
* V_190 = * V_271 ;
V_190 -> V_177 = & V_11 -> V_177 ;
V_190 -> V_273 = V_274 ;
V_190 -> V_275 = V_276 ;
V_190 -> V_259 = & V_11 -> V_259 ;
snprintf ( V_190 -> V_156 , sizeof( V_190 -> V_156 ) , L_49 , V_11 -> V_156 , V_272 ) ;
F_131 ( V_190 , V_11 ) ;
return V_190 ;
}
int F_132 ( struct V_10 * V_11 )
{
int V_168 = - 1 ;
V_11 -> V_190 = F_129 ( V_11 , & V_277 , L_50 ) ;
if ( ! V_11 -> V_190 ) {
F_133 ( V_278 L_51 ,
V_11 -> V_156 ) ;
return - V_100 ;
}
F_134 ( & V_11 -> V_12 . V_14 ) ;
F_134 ( & V_11 -> V_12 . V_253 ) ;
V_168 = F_135 ( V_11 -> V_190 , V_247 , V_279 ) ;
if ( V_168 < 0 ) {
F_133 ( V_278 L_51 ,
V_11 -> V_156 ) ;
return V_168 ;
}
F_133 ( V_278 L_52 ,
V_11 -> V_156 , F_114 ( V_11 -> V_190 ) ) ;
if ( V_11 -> V_280 . V_281 ) {
V_11 -> V_282 = F_129 ( V_11 , & V_283 ,
L_53 ) ;
if ( ! V_11 -> V_282 ) {
F_133 ( V_278 L_54 ,
V_11 -> V_156 ) ;
return V_168 ;
}
V_168 = F_135 ( V_11 -> V_282 , V_250 ,
V_284 ) ;
if ( V_168 < 0 ) {
F_133 ( V_278 L_54 ,
V_11 -> V_156 ) ;
return V_168 ;
}
F_133 ( V_278 L_52 ,
V_11 -> V_156 , F_114 ( V_11 -> V_282 ) ) ;
}
F_133 ( V_278 L_55 , V_168 ) ;
return V_168 ;
}
int F_136 ( struct V_10 * V_11 )
{
F_137 ( V_11 -> V_190 ) ;
if ( V_11 -> V_282 ) {
if ( F_138 ( V_11 -> V_282 ) )
F_137 ( V_11 -> V_282 ) ;
else
V_274 ( V_11 -> V_282 ) ;
V_11 -> V_282 = NULL ;
}
return 0 ;
}
int F_139 ( void )
{
return 0 ;
}
