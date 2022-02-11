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
if ( ! V_11 )
return;
F_20 ( & V_11 -> V_78 ) ;
F_18 ( V_27 ) ;
F_21 ( & V_11 -> V_78 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_71 ; V_3 ++ ) {
V_27 -> V_72 [ V_3 ] . V_60 = 0 ;
V_27 -> V_72 [ V_3 ] . V_73 = 0 ;
}
V_27 -> V_60 = F_22 ( V_27 , V_79 ) ;
if ( V_27 -> V_60 )
F_23 ( L_16 ,
V_27 -> V_60 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_27 * V_27 ;
int V_3 ;
V_11 -> V_45 . V_9 = NULL ;
for ( V_3 = 0 ; V_3 < V_11 -> V_45 . V_80 ; V_3 ++ ) {
V_27 = V_11 -> V_45 . V_27 [ V_3 ] ;
if ( V_27 ) {
F_25 ( V_27 ) ;
F_26 ( V_27 ) ;
if ( V_11 -> V_45 . V_74 [ V_3 ] ) {
F_27 ( V_11 -> V_81 ,
V_27 -> V_82 ,
V_11 -> V_45 . V_74 [ V_3 ] ,
V_27 -> V_83 ) ;
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
V_11 -> V_45 . V_80 = 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_12 ;
int V_3 , V_84 , V_85 , V_86 , V_37 , V_87 , V_80 = 8 ;
struct V_27 * V_27 ;
F_24 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 -> V_81 ,
V_11 -> V_88 . V_89 ,
V_11 -> V_88 . V_90 ) ;
F_33 ( V_11 ) ;
V_86 = F_34 ( V_11 -> V_81 ,
V_11 -> V_88 . V_30 -> V_91 . V_92 &
V_93 ) ;
V_37 = F_35 ( V_11 -> V_81 , V_86 , F_36 ( V_86 ) ) ;
if ( V_37 > V_11 -> V_88 . V_94 )
V_37 = V_11 -> V_88 . V_94 ;
V_11 -> V_45 . V_95 = V_37 ;
V_87 = V_96 ;
V_85 = V_87 * V_37 ;
V_11 -> V_45 . V_80 = V_80 ;
V_11 -> V_45 . V_27 = F_37 ( sizeof( void * ) * V_80 , V_97 ) ;
if ( ! V_11 -> V_45 . V_27 ) {
F_23 ( L_17 ) ;
return - V_98 ;
}
V_11 -> V_45 . V_74 = F_37 ( sizeof( void * ) * V_80 ,
V_97 ) ;
if ( ! V_11 -> V_45 . V_74 ) {
F_23 ( L_18 ) ;
F_29 ( V_11 -> V_45 . V_27 ) ;
return - V_98 ;
}
F_5 ( V_11 , V_15 , L_19
L_20 ,
V_87 , V_80 , V_85 ,
V_11 -> V_88 . V_94 , V_37 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_45 . V_80 ; V_3 ++ ) {
V_27 = F_38 ( V_87 , V_97 ) ;
if ( ! V_27 ) {
F_23 ( L_21 , V_3 ) ;
F_24 ( V_11 ) ;
F_28 ( V_27 ) ;
return - V_98 ;
}
V_11 -> V_45 . V_27 [ V_3 ] = V_27 ;
V_11 -> V_45 . V_74 [ V_3 ] = F_39 ( V_11 -> V_81 ,
V_85 , V_97 , & V_27 -> V_83 ) ;
if ( ! V_11 -> V_45 . V_74 [ V_3 ] ) {
F_23 ( L_22
L_23 ,
V_85 , V_3 ,
F_40 () ? L_24 : L_25 ) ;
F_24 ( V_11 ) ;
return - V_98 ;
}
memset ( V_11 -> V_45 . V_74 [ V_3 ] , 0 , V_85 ) ;
F_41 ( V_27 , V_11 -> V_81 , V_86 ,
V_11 -> V_45 . V_74 [ V_3 ] , V_85 ,
F_19 , V_7 ) ;
V_27 -> V_99 = V_11 -> V_88 . V_30 -> V_91 . V_100 ;
V_27 -> V_71 = V_87 ;
V_27 -> V_101 = V_102 | V_103 ;
for ( V_84 = 0 ; V_84 < V_87 ; V_84 ++ ) {
V_27 -> V_72 [ V_84 ] . V_75 = V_37 * V_84 ;
V_27 -> V_72 [ V_84 ] . V_104 = V_37 ;
}
}
return 0 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_12 ;
int V_3 ;
V_7 -> V_105 = 0 ;
V_7 -> V_106 = V_107 ;
F_43 ( & V_7 -> V_108 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_45 . V_80 ; V_3 ++ ) {
int V_33 = F_22 ( V_11 -> V_45 . V_27 [ V_3 ] , V_79 ) ;
if ( V_33 ) {
F_23 ( L_26 , V_3 ,
V_33 ) ;
F_24 ( V_11 ) ;
return V_33 ;
}
}
return 0 ;
}
static int
F_44 ( struct V_109 * V_110 , unsigned int * V_111 , unsigned int * V_37 )
{
struct V_112 * V_113 = V_110 -> V_114 ;
* V_37 = V_113 -> V_115 -> V_116 * V_113 -> V_51 * V_113 -> V_117 >> 3 ;
if ( 0 == * V_111 )
* V_111 = V_118 ;
if ( * V_111 < V_119 )
* V_111 = V_119 ;
while ( * V_37 * * V_111 > V_120 * 1024 * 1024 )
( * V_111 ) -- ;
return 0 ;
}
static void F_45 ( struct V_109 * V_110 , struct V_8 * V_9 )
{
struct V_112 * V_113 = V_110 -> V_114 ;
struct V_10 * V_11 = V_113 -> V_11 ;
unsigned long V_121 ;
if ( F_40 () )
F_46 () ;
F_47 ( & V_11 -> V_78 , V_121 ) ;
if ( V_11 -> V_45 . V_9 == V_9 )
V_11 -> V_45 . V_9 = NULL ;
F_48 ( & V_11 -> V_78 , V_121 ) ;
F_49 ( & V_9 -> V_17 ) ;
V_9 -> V_17 . V_20 = V_122 ;
}
static int
F_50 ( struct V_109 * V_110 , struct V_123 * V_17 ,
enum V_124 V_38 )
{
struct V_112 * V_113 = V_110 -> V_114 ;
struct V_8 * V_9 = F_3 ( V_17 , struct V_8 , V_17 ) ;
struct V_10 * V_11 = V_113 -> V_11 ;
int V_33 = 0 , V_125 = 0 ;
F_51 ( NULL == V_113 -> V_115 ) ;
V_9 -> V_17 . V_37 = V_113 -> V_115 -> V_116 * V_113 -> V_51 * V_113 -> V_117 >> 3 ;
if ( 0 != V_9 -> V_17 . V_126 && V_9 -> V_17 . V_127 < V_9 -> V_17 . V_37 )
return - V_128 ;
if ( V_9 -> V_115 != V_113 -> V_115 ||
V_9 -> V_17 . V_51 != V_113 -> V_51 ||
V_9 -> V_17 . V_117 != V_113 -> V_117 ||
V_9 -> V_17 . V_38 != V_38 ) {
V_9 -> V_115 = V_113 -> V_115 ;
V_9 -> V_17 . V_51 = V_113 -> V_51 ;
V_9 -> V_17 . V_117 = V_113 -> V_117 ;
V_9 -> V_17 . V_38 = V_38 ;
V_9 -> V_17 . V_20 = V_122 ;
}
if ( V_122 == V_9 -> V_17 . V_20 ) {
V_33 = F_52 ( V_110 , & V_9 -> V_17 , NULL ) ;
if ( V_33 != 0 )
goto V_129;
V_125 = 1 ;
}
if ( ! V_11 -> V_45 . V_80 )
V_125 = 1 ;
if ( V_125 ) {
V_33 = F_30 ( V_11 ) ;
if ( V_33 < 0 )
goto V_129;
V_33 = F_42 ( V_11 ) ;
if ( V_33 < 0 )
goto V_129;
}
V_9 -> V_17 . V_20 = V_130 ;
return 0 ;
V_129:
F_45 ( V_110 , V_9 ) ;
return V_33 ;
}
static void
F_53 ( struct V_109 * V_110 , struct V_123 * V_17 )
{
struct V_8 * V_9 = F_3 ( V_17 , struct V_8 , V_17 ) ;
struct V_112 * V_113 = V_110 -> V_114 ;
struct V_10 * V_11 = V_113 -> V_11 ;
struct V_6 * V_12 = & V_11 -> V_12 ;
V_9 -> V_17 . V_20 = V_131 ;
F_54 ( & V_9 -> V_17 . V_18 , & V_12 -> V_14 ) ;
}
static void F_55 ( struct V_109 * V_110 , struct V_123 * V_17 )
{
struct V_8 * V_9 = F_3 ( V_17 , struct V_8 , V_17 ) ;
F_45 ( V_110 , V_9 ) ;
}
static bool F_56 ( struct V_10 * V_11 , struct V_112 * V_113 )
{
if ( V_11 -> V_132 == V_113 && V_11 -> F_56 )
return true ;
return false ;
}
static bool F_57 ( struct V_10 * V_11 , struct V_112 * V_113 )
{
if ( V_11 -> V_132 == V_113 )
return true ;
return false ;
}
static bool F_58 ( struct V_10 * V_11 , struct V_112 * V_113 ,
bool F_56 )
{
if ( V_11 -> V_132 == V_113 && V_11 -> F_56 == F_56 )
return true ;
if ( V_11 -> V_132 )
return false ;
V_11 -> V_132 = V_113 ;
V_11 -> F_56 = F_56 ;
F_5 ( V_11 , V_133 , L_27 ) ;
return true ;
}
static void F_59 ( struct V_10 * V_11 , struct V_112 * V_113 )
{
if ( V_11 -> V_132 != V_113 )
return;
V_11 -> V_132 = NULL ;
F_5 ( V_11 , V_133 , L_28 ) ;
}
static int F_60 ( struct V_134 * V_134 , void * V_135 ,
struct V_136 * V_137 )
{
struct V_10 * V_11 = ( (struct V_112 * ) V_135 ) -> V_11 ;
F_61 ( V_137 -> V_138 , L_29 , sizeof( V_137 -> V_138 ) ) ;
F_61 ( V_137 -> V_139 , L_30 , sizeof( V_137 -> V_139 ) ) ;
V_137 -> V_140 = V_141 ;
V_137 -> V_142 = V_143 |
V_144 |
V_145 |
V_146 ;
if ( V_11 -> V_147 != V_148 )
V_137 -> V_142 |= V_149 ;
return 0 ;
}
static int F_62 ( struct V_134 * V_134 , void * V_135 ,
struct V_150 * V_151 )
{
if ( F_63 ( V_151 -> V_152 >= F_64 ( V_153 ) ) )
return - V_128 ;
F_61 ( V_151 -> V_154 , V_153 [ V_151 -> V_152 ] . V_155 , sizeof( V_151 -> V_154 ) ) ;
V_151 -> V_156 = V_153 [ V_151 -> V_152 ] . V_76 ;
return 0 ;
}
static int F_65 ( struct V_134 * V_134 , void * V_135 ,
struct V_157 * V_151 )
{
struct V_112 * V_113 = V_135 ;
V_151 -> V_115 . V_158 . V_51 = V_113 -> V_51 ;
V_151 -> V_115 . V_158 . V_117 = V_113 -> V_117 ;
V_151 -> V_115 . V_158 . V_38 = V_113 -> V_159 . V_38 ;
V_151 -> V_115 . V_158 . V_156 = V_113 -> V_115 -> V_76 ;
V_151 -> V_115 . V_158 . V_160 =
( V_151 -> V_115 . V_158 . V_51 * V_113 -> V_115 -> V_116 ) >> 3 ;
V_151 -> V_115 . V_158 . V_161 =
V_151 -> V_115 . V_158 . V_117 * V_151 -> V_115 . V_158 . V_160 ;
return 0 ;
}
static struct V_162 * F_66 ( unsigned int V_76 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_64 ( V_153 ) ; V_3 ++ )
if ( V_153 [ V_3 ] . V_76 == V_76 )
return V_153 + V_3 ;
return NULL ;
}
static int F_67 ( struct V_134 * V_134 , void * V_135 ,
struct V_157 * V_151 )
{
struct V_10 * V_11 = ( (struct V_112 * ) V_135 ) -> V_11 ;
struct V_162 * V_115 ;
enum V_124 V_38 ;
V_115 = F_66 ( V_151 -> V_115 . V_158 . V_156 ) ;
if ( NULL == V_115 ) {
F_5 ( V_11 , V_163 , L_31
L_32 , V_151 -> V_115 . V_158 . V_156 ) ;
return - V_128 ;
}
V_38 = V_151 -> V_115 . V_158 . V_38 ;
if ( V_38 == V_164 )
V_38 = V_165 ;
else if ( V_166 != V_38 ) {
F_5 ( V_11 , V_163 , L_33 ) ;
return - V_128 ;
}
F_68 ( V_11 ) ;
V_151 -> V_115 . V_158 . V_51 = V_11 -> V_51 ;
V_151 -> V_115 . V_158 . V_117 = V_11 -> V_117 ;
V_151 -> V_115 . V_158 . V_51 &= ~ 0x01 ;
V_151 -> V_115 . V_158 . V_38 = V_38 ;
V_151 -> V_115 . V_158 . V_160 =
( V_151 -> V_115 . V_158 . V_51 * V_115 -> V_116 ) >> 3 ;
V_151 -> V_115 . V_158 . V_161 =
V_151 -> V_115 . V_158 . V_117 * V_151 -> V_115 . V_158 . V_160 ;
return 0 ;
}
static int F_69 ( struct V_134 * V_134 , void * V_135 ,
struct V_157 * V_151 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
int V_167 = F_67 ( V_134 , V_113 , V_151 ) ;
if ( V_167 < 0 )
return V_167 ;
V_113 -> V_115 = F_66 ( V_151 -> V_115 . V_158 . V_156 ) ;
V_113 -> V_51 = V_151 -> V_115 . V_158 . V_51 ;
V_113 -> V_117 = V_151 -> V_115 . V_158 . V_117 ;
V_113 -> V_159 . V_38 = V_151 -> V_115 . V_158 . V_38 ;
V_113 -> type = V_151 -> type ;
V_11 -> V_76 = V_151 -> V_115 . V_158 . V_156 ;
F_70 ( V_11 ) ;
return 0 ;
}
static int F_71 ( struct V_134 * V_134 , void * V_135 ,
struct V_168 * V_70 )
{
struct V_112 * V_113 = V_135 ;
return F_72 ( & V_113 -> V_159 , V_70 ) ;
}
static int F_73 ( struct V_134 * V_134 , void * V_135 ,
struct V_169 * V_70 )
{
struct V_112 * V_113 = V_135 ;
return F_74 ( & V_113 -> V_159 , V_70 ) ;
}
static int F_75 ( struct V_134 * V_134 , void * V_135 , struct V_169 * V_70 )
{
struct V_112 * V_113 = V_135 ;
return F_76 ( & V_113 -> V_159 , V_70 ) ;
}
static int F_77 ( struct V_134 * V_134 , void * V_135 , struct V_169 * V_70 )
{
struct V_112 * V_113 = V_135 ;
return F_78 ( & V_113 -> V_159 , V_70 ,
V_134 -> V_170 & V_171 ) ;
}
static int F_79 ( struct V_134 * V_134 , void * V_135 , enum V_172 V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( V_113 -> type != V_173 )
return - V_128 ;
if ( V_3 != V_113 -> type )
return - V_128 ;
if ( ! F_58 ( V_11 , V_113 , false ) )
return - V_174 ;
return F_80 ( & V_113 -> V_159 ) ;
}
static int F_81 ( struct V_134 * V_134 , void * V_135 , enum V_172 V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( V_113 -> type != V_173 )
return - V_128 ;
if ( V_3 != V_113 -> type )
return - V_128 ;
F_82 ( & V_113 -> V_159 ) ;
F_59 ( V_11 , V_113 ) ;
return 0 ;
}
static int F_83 ( struct V_134 * V_134 , void * V_135 , T_3 * V_175 )
{
int V_33 = 0 ;
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
V_11 -> V_175 = * V_175 ;
V_33 = F_84 ( V_11 ) ;
V_113 -> V_51 = V_11 -> V_51 ;
V_113 -> V_117 = V_11 -> V_117 ;
if ( V_33 < 0 )
return V_33 ;
F_85 ( & V_11 -> V_176 , 0 , V_177 , V_178 , V_11 -> V_175 ) ;
return 0 ;
}
static int F_86 ( struct V_134 * V_134 , void * V_135 ,
struct V_179 * V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
unsigned int V_180 ;
V_180 = V_3 -> V_152 ;
if ( V_180 >= 3 )
return - V_128 ;
if ( ! V_11 -> V_181 [ V_180 ] . type )
return - V_128 ;
V_3 -> V_152 = V_180 ;
if ( V_11 -> V_181 [ V_180 ] . type == V_182 )
V_3 -> type = V_183 ;
else
V_3 -> type = V_184 ;
strcpy ( V_3 -> V_155 , V_185 [ V_11 -> V_181 [ V_180 ] . type ] ) ;
V_3 -> V_186 = V_187 ;
return 0 ;
}
static int F_87 ( struct V_134 * V_134 , void * V_135 , unsigned int * V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
* V_3 = V_11 -> V_188 ;
return 0 ;
}
static int F_88 ( struct V_134 * V_134 , void * V_135 , unsigned int V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
int V_33 = 0 ;
if ( V_3 >= 3 )
return - V_128 ;
if ( ! V_11 -> V_181 [ V_3 ] . type )
return - V_128 ;
V_11 -> V_188 = V_3 ;
V_33 = F_83 ( V_134 , V_135 , & V_11 -> V_189 -> V_190 ) ;
return V_33 ;
}
static int F_89 ( struct V_134 * V_134 , void * V_135 ,
struct V_1 * V_191 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_64 ( V_5 ) ; V_3 ++ )
if ( V_191 -> V_2 && V_191 -> V_2 == V_5 [ V_3 ] . V_2 ) {
memcpy ( V_191 , & ( V_5 [ V_3 ] ) ,
sizeof( * V_191 ) ) ;
return 0 ;
}
return - V_128 ;
}
static int F_90 ( struct V_134 * V_134 , void * V_135 ,
struct V_192 * V_193 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
int V_194 ;
switch ( V_193 -> V_2 ) {
case V_195 :
V_194 = F_91 ( V_11 , V_196 , 0 ) ;
break;
case V_197 :
V_194 = F_91 ( V_11 , V_198 , 0 ) ;
return 0 ;
case V_199 :
V_194 = F_91 ( V_11 , V_200 , 0 ) ;
return 0 ;
case V_201 :
V_194 = F_91 ( V_11 , V_202 , 0 ) ;
return 0 ;
case V_203 :
V_194 = V_11 -> V_204 ;
return 0 ;
case V_205 :
V_194 = V_11 -> V_206 ;
return 0 ;
default:
return - V_128 ;
}
if ( V_194 < 0 )
return V_194 ;
V_193 -> V_207 = V_194 ;
return 0 ;
}
static int F_92 ( struct V_134 * V_134 , void * V_135 ,
struct V_192 * V_193 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
T_1 V_194 = V_193 -> V_207 ;
switch ( V_193 -> V_2 ) {
case V_195 :
F_93 ( V_11 , V_196 , V_194 ) ;
return 0 ;
case V_197 :
F_93 ( V_11 , V_198 , V_194 ) ;
return 0 ;
case V_199 :
F_93 ( V_11 , V_200 , V_194 ) ;
return 0 ;
case V_201 :
F_93 ( V_11 , V_202 , V_194 ) ;
return 0 ;
case V_203 :
V_11 -> V_204 = V_194 ;
F_94 ( V_11 , V_194 ) ;
return 0 ;
case V_205 :
V_11 -> V_206 = V_194 ;
F_95 ( V_11 , V_194 ) ;
return 0 ;
}
return - V_128 ;
}
static int F_96 ( struct V_134 * V_134 , void * V_135 ,
struct V_208 * V_209 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( F_63 ( V_210 == V_11 -> V_147 ) )
return - V_128 ;
if ( 0 != V_209 -> V_152 )
return - V_128 ;
strcpy ( V_209 -> V_155 , L_34 ) ;
V_209 -> type = V_211 ;
V_209 -> V_212 = V_213 ;
V_209 -> V_214 = 0xffffffffUL ;
V_209 -> V_215 = V_216 ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_218 , V_209 ) ;
V_209 -> V_219 = V_11 -> V_220 ;
return 0 ;
}
static int F_97 ( struct V_134 * V_134 , void * V_135 ,
struct V_208 * V_209 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( V_210 == V_11 -> V_147 )
return - V_128 ;
if ( 0 != V_209 -> V_152 )
return - V_128 ;
V_11 -> V_220 = V_209 -> V_219 ;
F_5 ( V_11 , 3 , L_35 , V_209 -> V_219 ) ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_221 , V_209 ) ;
return 0 ;
}
static int F_98 ( struct V_134 * V_134 , void * V_135 ,
struct V_222 * V_151 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( F_63 ( V_210 == V_11 -> V_147 ) )
return - V_128 ;
V_151 -> type = V_113 -> V_44 ? V_223 : V_211 ;
V_151 -> V_224 = V_11 -> V_225 ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_226 , V_151 ) ;
return 0 ;
}
static int F_99 ( struct V_134 * V_134 , void * V_135 ,
struct V_222 * V_151 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( F_63 ( V_210 == V_11 -> V_147 ) )
return - V_128 ;
if ( F_63 ( V_151 -> V_217 != 0 ) )
return - V_128 ;
if ( 0 == V_113 -> V_44 && V_211 != V_151 -> type )
return - V_128 ;
if ( 1 == V_113 -> V_44 && V_223 != V_151 -> type )
return - V_128 ;
V_11 -> V_225 = V_151 -> V_224 ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_227 , V_151 ) ;
return 0 ;
}
static int F_100 ( struct V_134 * V_134 , void * V_135 ,
struct V_136 * V_137 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
struct V_10 * V_11 = V_113 -> V_11 ;
strcpy ( V_137 -> V_138 , L_29 ) ;
F_61 ( V_137 -> V_139 , V_11 -> V_155 , sizeof( V_11 -> V_155 ) ) ;
sprintf ( V_137 -> V_229 , L_36 ,
F_101 ( V_11 -> V_81 -> V_230 . V_231 ) ,
F_101 ( V_11 -> V_81 -> V_230 . V_232 ) ) ;
V_137 -> V_140 = V_11 -> V_233 ;
V_137 -> V_142 = V_149 |
V_145 |
V_234 |
V_146 |
V_144 ;
return 0 ;
}
static int F_102 ( struct V_134 * V_134 , void * V_135 ,
struct V_208 * V_209 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( 0 != V_209 -> V_152 )
return - V_128 ;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
strcpy ( V_209 -> V_155 , L_37 ) ;
V_209 -> type = V_223 ;
V_209 -> V_215 = V_216 ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_218 , V_209 ) ;
return 0 ;
}
static int F_103 ( struct V_134 * V_134 , void * V_135 ,
struct V_208 * V_209 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( 0 != V_209 -> V_152 )
return - V_128 ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_221 , V_209 ) ;
return 0 ;
}
static int F_104 ( struct V_134 * V_134 , void * V_135 ,
struct V_179 * V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( V_3 -> V_152 != 0 )
return - V_128 ;
if ( ! V_11 -> V_235 . type )
return - V_128 ;
strcpy ( V_3 -> V_155 , L_37 ) ;
V_3 -> type = V_183 ;
return 0 ;
}
static int F_105 ( struct V_134 * V_236 , void * V_135 , unsigned int * V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( V_11 -> V_188 != 5 )
return - V_128 ;
* V_3 = V_11 -> V_188 - 5 ;
return 0 ;
}
static int F_106 ( struct V_134 * V_134 , void * V_135 ,
struct V_237 * V_238 )
{
memset ( V_238 , 0 , sizeof( * V_238 ) ) ;
strcpy ( V_238 -> V_155 , L_37 ) ;
return 0 ;
}
static int F_107 ( struct V_134 * V_134 , void * V_135 ,
struct V_237 * V_238 )
{
return 0 ;
}
static int F_108 ( struct V_134 * V_236 , void * V_135 , unsigned int V_3 )
{
struct V_112 * V_113 = V_135 ;
struct V_10 * V_11 = V_113 -> V_11 ;
if ( V_3 )
return - V_128 ;
if ( ! V_11 -> V_235 . type )
return - V_128 ;
V_11 -> V_188 = V_3 + 5 ;
return 0 ;
}
static int F_109 ( struct V_134 * V_134 , void * V_113 , T_3 * V_175 )
{
return 0 ;
}
static int F_110 ( struct V_134 * V_134 , void * V_135 ,
struct V_1 * V_31 )
{
const struct V_1 * V_193 ;
if ( V_31 -> V_2 < V_239 ||
V_31 -> V_2 >= V_240 )
return - V_128 ;
if ( V_31 -> V_2 == V_203 ) {
V_193 = F_1 ( V_31 -> V_2 ) ;
* V_31 = * V_193 ;
} else
* V_31 = V_241 ;
return 0 ;
}
static int F_111 ( struct V_134 * V_134 )
{
struct V_242 * V_243 = F_112 ( V_134 ) ;
struct V_10 * V_11 = F_113 ( V_134 ) ;
struct V_112 * V_113 ;
enum V_172 type = V_173 ;
int V_3 , V_33 ;
int V_44 = 0 ;
F_114 ( V_244 L_38 ,
F_115 ( V_243 ) ) ;
F_5 ( V_11 , V_245 , L_38 ,
F_115 ( V_243 ) ) ;
switch ( V_243 -> V_246 ) {
case V_247 :
type = V_173 ;
break;
case V_248 :
type = V_249 ;
break;
case V_250 :
V_44 = 1 ;
break;
}
V_11 -> V_251 ++ ;
F_5 ( V_11 , V_245 , L_39 ,
F_115 ( V_243 ) , V_252 [ type ] ,
V_11 -> V_251 ) ;
V_113 = F_116 ( sizeof( * V_113 ) , V_97 ) ;
if ( NULL == V_113 ) {
V_11 -> V_251 -- ;
return - V_98 ;
}
V_134 -> V_228 = V_113 ;
V_113 -> V_11 = V_11 ;
V_113 -> V_44 = V_44 ;
V_11 -> V_44 = V_44 ;
V_113 -> type = type ;
V_11 -> V_76 = V_153 [ 0 ] . V_76 ;
V_113 -> V_115 = F_66 ( V_11 -> V_76 ) ;
F_68 ( V_11 ) ;
V_113 -> V_51 = V_11 -> V_51 ;
V_113 -> V_117 = V_11 -> V_117 ;
F_5 ( V_11 , V_245 , L_40
L_41 ,
( unsigned long ) V_113 , ( unsigned long ) V_11 , ( unsigned long ) & V_11 -> V_12 ) ;
F_5 ( V_11 , V_245 , L_42
L_43 , F_4 ( & V_11 -> V_12 . V_253 ) ) ;
F_5 ( V_11 , V_245 , L_42
L_44 , F_4 ( & V_11 -> V_12 . V_14 ) ) ;
V_33 = F_84 ( V_11 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_11 -> V_254 != V_255 ) {
for ( V_3 = 0 ; V_3 < F_64 ( V_5 ) ; V_3 ++ )
V_256 [ V_3 ] = V_5 [ V_3 ] . V_257 ;
V_11 -> V_254 = V_255 ;
}
F_117 ( & V_113 -> V_159 , & V_258 ,
NULL , & V_11 -> V_78 ,
V_113 -> type ,
V_166 ,
sizeof( struct V_8 ) , V_113 , & V_11 -> V_259 ) ;
if ( V_113 -> V_44 ) {
F_5 ( V_11 , V_245 , L_45 ) ;
V_11 -> V_188 = 5 ;
F_118 ( V_11 ) ;
F_85 ( & V_11 -> V_176 , 0 , V_217 , V_260 ) ;
F_30 ( V_11 ) ;
F_42 ( V_11 ) ;
}
return 0 ;
}
static T_4
F_119 ( struct V_134 * V_134 , char T_5 * V_25 , T_6 V_111 , T_7 * V_40 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
if ( V_113 -> type == V_173 ) {
if ( ! F_58 ( V_113 -> V_11 , V_113 , true ) )
return - V_174 ;
return F_120 ( & V_113 -> V_159 , V_25 , V_111 , V_40 , 0 ,
V_134 -> V_170 & V_171 ) ;
}
return 0 ;
}
static unsigned int
F_121 ( struct V_134 * V_134 , struct V_261 * V_262 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
struct V_8 * V_9 ;
if ( V_173 != V_113 -> type )
return V_263 ;
if ( ! ! F_57 ( V_113 -> V_11 , V_113 ) )
return V_263 ;
if ( ! F_56 ( V_113 -> V_11 , V_113 ) ) {
if ( F_4 ( & V_113 -> V_159 . V_264 ) )
return V_263 ;
V_9 = F_6 ( V_113 -> V_159 . V_264 . V_16 , struct V_8 , V_17 . V_264 ) ;
} else {
return F_122 ( V_134 , & V_113 -> V_159 ,
V_262 ) ;
}
F_123 ( V_134 , & V_9 -> V_17 . V_24 , V_262 ) ;
if ( V_9 -> V_17 . V_20 == V_21 ||
V_9 -> V_17 . V_20 == V_265 )
return V_266 | V_267 ;
return 0 ;
}
static int F_124 ( struct V_134 * V_134 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
struct V_10 * V_11 = V_113 -> V_11 ;
struct V_242 * V_243 = F_112 ( V_134 ) ;
F_5 ( V_11 , V_245 , L_46 ,
F_115 ( V_243 ) , V_11 -> V_251 ) ;
V_11 -> V_251 -- ;
F_59 ( V_11 , V_113 ) ;
if ( ! V_11 -> V_251 ) {
F_24 ( V_11 ) ;
F_125 ( & V_113 -> V_159 ) ;
}
F_29 ( V_113 ) ;
return 0 ;
}
static int F_126 ( struct V_134 * V_134 , struct V_268 * V_269 )
{
struct V_112 * V_113 = V_134 -> V_228 ;
int V_167 ;
V_167 = F_127 ( & V_113 -> V_159 , V_269 ) ;
return V_167 ;
}
static struct V_242 * F_128 ( struct V_10 * V_11 ,
const struct V_242
* V_270 , const char * V_271 )
{
struct V_242 * V_189 ;
V_189 = F_129 () ;
if ( NULL == V_189 )
return NULL ;
* V_189 = * V_270 ;
V_189 -> V_176 = & V_11 -> V_176 ;
V_189 -> V_272 = V_273 ;
V_189 -> V_274 = V_275 ;
V_189 -> V_259 = & V_11 -> V_259 ;
snprintf ( V_189 -> V_155 , sizeof( V_189 -> V_155 ) , L_47 , V_11 -> V_155 , V_271 ) ;
F_130 ( V_189 , V_11 ) ;
return V_189 ;
}
int F_131 ( struct V_10 * V_11 )
{
int V_167 = - 1 ;
V_11 -> V_189 = F_128 ( V_11 , & V_276 , L_48 ) ;
if ( ! V_11 -> V_189 ) {
F_114 ( V_244 L_49 ,
V_11 -> V_155 ) ;
return - V_98 ;
}
F_132 ( & V_11 -> V_12 . V_14 ) ;
F_132 ( & V_11 -> V_12 . V_253 ) ;
V_167 = F_133 ( V_11 -> V_189 , V_247 , V_277 ) ;
if ( V_167 < 0 ) {
F_114 ( V_244 L_49 ,
V_11 -> V_155 ) ;
return V_167 ;
}
F_114 ( V_244 L_50 ,
V_11 -> V_155 , F_115 ( V_11 -> V_189 ) ) ;
if ( V_11 -> V_278 . V_279 ) {
V_11 -> V_280 = F_128 ( V_11 , & V_281 ,
L_51 ) ;
if ( ! V_11 -> V_280 ) {
F_114 ( V_244 L_52 ,
V_11 -> V_155 ) ;
return V_167 ;
}
V_167 = F_133 ( V_11 -> V_280 , V_250 ,
V_282 ) ;
if ( V_167 < 0 ) {
F_114 ( V_244 L_52 ,
V_11 -> V_155 ) ;
return V_167 ;
}
F_114 ( V_244 L_50 ,
V_11 -> V_155 , F_115 ( V_11 -> V_280 ) ) ;
}
F_114 ( V_244 L_53 , V_167 ) ;
return V_167 ;
}
int F_134 ( struct V_10 * V_11 )
{
F_135 ( V_11 -> V_189 ) ;
if ( V_11 -> V_280 ) {
if ( F_136 ( V_11 -> V_280 ) )
F_135 ( V_11 -> V_280 ) ;
else
V_273 ( V_11 -> V_280 ) ;
V_11 -> V_280 = NULL ;
}
return 0 ;
}
int F_137 ( void )
{
return 0 ;
}
