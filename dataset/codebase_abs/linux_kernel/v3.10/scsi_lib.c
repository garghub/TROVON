static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_4 ;
}
int F_2 ( struct V_5 * V_3 )
{
V_3 -> V_6 = F_1 ;
return F_3 ( V_3 ) ;
}
void F_4 ( struct V_5 * V_3 )
{
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
F_7 ( V_8 ) ;
V_8 -> V_11 = NULL ;
F_8 ( V_10 ) ;
}
static void F_9 ( struct V_9 * V_10 , int V_12 , int V_13 )
{
struct V_14 * V_15 = V_10 -> V_1 -> V_15 ;
struct V_16 * V_1 = V_10 -> V_1 ;
struct V_17 * V_18 = V_17 ( V_1 ) ;
struct V_19 * V_20 = V_1 -> V_19 ;
unsigned long V_21 ;
F_10 ( 1 ,
F_11 ( L_1 , V_10 ) ) ;
switch ( V_12 ) {
case V_22 :
V_15 -> V_23 = V_15 -> V_24 ;
break;
case V_25 :
case V_26 :
V_1 -> V_27 = V_1 -> V_28 ;
break;
case V_29 :
V_18 -> V_30 = V_18 -> V_31 ;
break;
}
if ( V_13 )
F_12 ( V_1 ) ;
F_13 ( V_20 -> V_32 , V_21 ) ;
F_14 ( V_20 , V_10 -> V_7 ) ;
F_15 ( V_20 , & V_1 -> V_33 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
}
void F_17 ( struct V_9 * V_10 , int V_12 )
{
F_9 ( V_10 , V_12 , 1 ) ;
}
int F_18 ( struct V_16 * V_34 , const unsigned char * V_10 ,
int V_35 , void * V_36 , unsigned V_37 ,
unsigned char * V_38 , int V_39 , int V_40 , int V_21 ,
int * V_41 )
{
struct V_7 * V_8 ;
int V_42 = ( V_35 == V_43 ) ;
int V_44 = V_45 << 24 ;
V_8 = F_19 ( V_34 -> V_19 , V_42 , V_46 ) ;
if ( ! V_8 )
return V_44 ;
if ( V_37 && F_20 ( V_34 -> V_19 , V_8 ,
V_36 , V_37 , V_46 ) )
goto V_47;
V_8 -> V_48 = F_21 ( V_10 [ 0 ] ) ;
memcpy ( V_8 -> V_10 , V_10 , V_8 -> V_48 ) ;
V_8 -> V_38 = V_38 ;
V_8 -> V_49 = 0 ;
V_8 -> V_40 = V_40 ;
V_8 -> V_39 = V_39 ;
V_8 -> V_50 = V_51 ;
V_8 -> V_52 |= V_21 | V_53 | V_54 ;
F_22 ( V_8 -> V_20 , NULL , V_8 , 1 ) ;
if ( F_23 ( V_8 -> V_55 > 0 && V_8 -> V_55 <= V_37 ) )
memset ( V_36 + ( V_37 - V_8 -> V_55 ) , 0 , V_8 -> V_55 ) ;
if ( V_41 )
* V_41 = V_8 -> V_55 ;
V_44 = V_8 -> V_56 ;
V_47:
F_24 ( V_8 ) ;
return V_44 ;
}
int F_25 ( struct V_16 * V_34 , const unsigned char * V_10 ,
int V_35 , void * V_36 , unsigned V_37 ,
struct V_57 * V_58 , int V_39 , int V_40 ,
int * V_41 , int V_21 )
{
char * V_38 = NULL ;
int V_59 ;
if ( V_58 ) {
V_38 = F_26 ( V_60 , V_61 ) ;
if ( ! V_38 )
return V_45 << 24 ;
}
V_59 = F_18 ( V_34 , V_10 , V_35 , V_36 , V_37 ,
V_38 , V_39 , V_40 , V_21 , V_41 ) ;
if ( V_58 )
F_27 ( V_38 , V_60 , V_58 ) ;
F_28 ( V_38 ) ;
return V_59 ;
}
static void F_29 ( struct V_9 * V_10 )
{
V_10 -> V_62 = 0 ;
F_30 ( V_10 , 0 ) ;
memset ( V_10 -> V_63 , 0 , V_60 ) ;
if ( V_10 -> V_48 == 0 )
V_10 -> V_48 = F_31 ( V_10 -> V_64 ) ;
}
void F_12 ( struct V_16 * V_34 )
{
struct V_14 * V_65 = V_34 -> V_15 ;
struct V_17 * V_18 = V_17 ( V_34 ) ;
unsigned long V_21 ;
F_13 ( V_65 -> V_66 , V_21 ) ;
V_65 -> V_67 -- ;
V_18 -> V_68 -- ;
if ( F_23 ( F_32 ( V_65 ) &&
( V_65 -> V_69 || V_65 -> V_70 ) ) )
F_33 ( V_65 ) ;
F_34 ( V_65 -> V_66 ) ;
F_35 ( V_34 -> V_19 -> V_32 ) ;
V_34 -> V_71 -- ;
F_16 ( V_34 -> V_19 -> V_32 , V_21 ) ;
}
static void F_36 ( struct V_16 * V_72 )
{
struct V_14 * V_65 = V_72 -> V_15 ;
struct V_16 * V_34 , * V_73 ;
struct V_17 * V_18 = V_17 ( V_72 ) ;
unsigned long V_21 ;
F_13 ( V_65 -> V_66 , V_21 ) ;
V_18 -> V_74 = NULL ;
F_16 ( V_65 -> V_66 , V_21 ) ;
F_37 ( V_72 -> V_19 ) ;
F_13 ( V_65 -> V_66 , V_21 ) ;
if ( V_18 -> V_74 )
goto V_47;
F_38 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_34 == V_72 )
continue;
if ( F_39 ( V_34 ) )
continue;
F_16 ( V_65 -> V_66 , V_21 ) ;
F_37 ( V_34 -> V_19 ) ;
F_13 ( V_65 -> V_66 , V_21 ) ;
F_40 ( V_34 ) ;
}
V_47:
F_16 ( V_65 -> V_66 , V_21 ) ;
}
static inline int F_41 ( struct V_16 * V_34 )
{
if ( V_34 -> V_71 >= V_34 -> V_75 || V_34 -> V_27 )
return 1 ;
return 0 ;
}
static inline int F_42 ( struct V_17 * V_18 )
{
return ( ( V_18 -> V_76 > 0 &&
V_18 -> V_68 >= V_18 -> V_76 ) ||
V_18 -> V_30 ) ;
}
static inline int F_43 ( struct V_14 * V_65 )
{
if ( ( V_65 -> V_76 > 0 && V_65 -> V_67 >= V_65 -> V_76 ) ||
V_65 -> V_23 || V_65 -> V_77 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_19 * V_20 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
struct V_14 * V_65 ;
F_45 ( V_79 ) ;
unsigned long V_21 ;
V_65 = V_34 -> V_15 ;
if ( V_17 ( V_34 ) -> V_80 )
F_36 ( V_34 ) ;
F_13 ( V_65 -> V_66 , V_21 ) ;
F_46 ( & V_65 -> V_79 , & V_79 ) ;
while ( ! F_47 ( & V_79 ) ) {
if ( F_43 ( V_65 ) )
break;
V_34 = F_48 ( V_79 . V_81 ,
struct V_16 , V_82 ) ;
F_49 ( & V_34 -> V_82 ) ;
if ( F_42 ( V_17 ( V_34 ) ) ) {
F_50 ( & V_34 -> V_82 ,
& V_65 -> V_79 ) ;
continue;
}
F_34 ( V_65 -> V_66 ) ;
F_35 ( V_34 -> V_19 -> V_32 ) ;
F_51 ( V_34 -> V_19 ) ;
F_34 ( V_34 -> V_19 -> V_32 ) ;
F_35 ( V_65 -> V_66 ) ;
}
F_52 ( & V_79 , & V_65 -> V_79 ) ;
F_16 ( V_65 -> V_66 , V_21 ) ;
F_37 ( V_20 ) ;
}
void F_53 ( struct V_83 * V_84 )
{
struct V_16 * V_34 ;
struct V_19 * V_20 ;
V_34 = F_54 ( V_84 , struct V_16 , V_33 ) ;
V_20 = V_34 -> V_19 ;
F_44 ( V_20 ) ;
}
static void F_55 ( struct V_19 * V_20 , struct V_9 * V_10 )
{
struct V_16 * V_34 = V_10 -> V_1 ;
struct V_7 * V_8 = V_10 -> V_7 ;
unsigned long V_21 ;
F_56 ( & V_34 -> V_85 ) ;
F_13 ( V_20 -> V_32 , V_21 ) ;
F_6 ( V_8 ) ;
F_14 ( V_20 , V_8 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
F_44 ( V_20 ) ;
F_57 ( & V_34 -> V_85 ) ;
}
void F_58 ( struct V_9 * V_10 )
{
struct V_16 * V_34 = V_10 -> V_1 ;
struct V_19 * V_20 = V_34 -> V_19 ;
F_56 ( & V_34 -> V_85 ) ;
F_8 ( V_10 ) ;
F_44 ( V_20 ) ;
F_57 ( & V_34 -> V_85 ) ;
}
void F_59 ( struct V_14 * V_65 )
{
struct V_16 * V_34 ;
F_60 (sdev, shost)
F_44 ( V_34 -> V_19 ) ;
}
static struct V_9 * F_61 ( struct V_9 * V_10 , int error ,
int V_86 , int V_87 )
{
struct V_19 * V_20 = V_10 -> V_1 -> V_19 ;
struct V_7 * V_8 = V_10 -> V_7 ;
if ( F_62 ( V_8 , error , V_86 ) ) {
if ( error && F_63 ( V_10 ) )
F_64 ( V_8 , error ) ;
else {
if ( V_87 ) {
F_65 ( V_10 ) ;
F_55 ( V_20 , V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
}
F_66 ( V_10 , 0 ) ;
F_58 ( V_10 ) ;
return NULL ;
}
static inline unsigned int F_67 ( unsigned short V_88 )
{
unsigned int V_89 ;
F_68 ( V_88 > V_90 ) ;
if ( V_88 <= 8 )
V_89 = 0 ;
else
V_89 = F_69 ( V_88 ) - 3 ;
return V_89 ;
}
static void F_70 ( struct V_91 * V_92 , unsigned int V_88 )
{
struct V_93 * V_94 ;
V_94 = V_95 + F_67 ( V_88 ) ;
F_71 ( V_92 , V_94 -> V_96 ) ;
}
static struct V_91 * F_72 ( unsigned int V_88 , T_1 V_97 )
{
struct V_93 * V_94 ;
V_94 = V_95 + F_67 ( V_88 ) ;
return F_73 ( V_94 -> V_96 , V_97 ) ;
}
static int F_74 ( struct V_98 * V_99 , int V_88 ,
T_1 V_97 )
{
int V_44 ;
F_68 ( ! V_88 ) ;
V_44 = F_75 ( & V_99 -> V_100 , V_88 , V_90 ,
V_97 , F_72 ) ;
if ( F_23 ( V_44 ) )
F_76 ( & V_99 -> V_100 , V_90 ,
F_70 ) ;
return V_44 ;
}
static void F_77 ( struct V_98 * V_99 )
{
F_76 ( & V_99 -> V_100 , V_90 , F_70 ) ;
}
static void F_66 ( struct V_9 * V_10 , int V_101 )
{
if ( V_10 -> V_99 . V_100 . V_88 )
F_77 ( & V_10 -> V_99 ) ;
memset ( & V_10 -> V_99 , 0 , sizeof( V_10 -> V_99 ) ) ;
if ( V_101 && F_78 ( V_10 ) ) {
struct V_98 * V_102 =
V_10 -> V_7 -> V_103 -> V_11 ;
F_77 ( V_102 ) ;
F_79 ( V_104 , V_102 ) ;
V_10 -> V_7 -> V_103 -> V_11 = NULL ;
}
if ( F_80 ( V_10 ) )
F_77 ( V_10 -> V_105 ) ;
}
void F_65 ( struct V_9 * V_10 )
{
F_66 ( V_10 , 1 ) ;
}
static int F_81 ( struct V_9 * V_10 , int V_59 )
{
int error = 0 ;
switch( F_82 ( V_59 ) ) {
case V_106 :
error = - V_107 ;
break;
case V_108 :
F_83 ( V_10 , V_109 ) ;
error = - V_110 ;
break;
case V_111 :
F_83 ( V_10 , V_109 ) ;
error = - V_112 ;
break;
default:
error = - V_113 ;
break;
}
return error ;
}
void F_84 ( struct V_9 * V_10 , unsigned int V_114 )
{
int V_59 = V_10 -> V_59 ;
struct V_19 * V_20 = V_10 -> V_1 -> V_19 ;
struct V_7 * V_8 = V_10 -> V_7 ;
int error = 0 ;
struct V_57 V_58 ;
int V_115 = 0 ;
int V_116 = 0 ;
enum { V_117 , V_118 , V_119 ,
V_120 } V_121 ;
char * V_122 = NULL ;
if ( V_59 ) {
V_115 = F_85 ( V_10 , & V_58 ) ;
if ( V_115 )
V_116 = F_86 ( & V_58 ) ;
}
if ( V_8 -> V_50 == V_51 ) {
if ( V_59 ) {
if ( V_115 && V_8 -> V_38 ) {
int V_123 = 8 + V_10 -> V_63 [ 7 ] ;
if ( V_123 > V_60 )
V_123 = V_60 ;
memcpy ( V_8 -> V_38 , V_10 -> V_63 , V_123 ) ;
V_8 -> V_49 = V_123 ;
}
if ( ! V_116 )
error = F_81 ( V_10 , V_59 ) ;
}
V_8 -> V_56 = V_10 -> V_59 ;
V_8 -> V_55 = F_87 ( V_10 ) ;
if ( F_78 ( V_10 ) ) {
V_8 -> V_103 -> V_55 = F_88 ( V_10 ) -> V_41 ;
F_65 ( V_10 ) ;
F_64 ( V_8 , 0 ) ;
F_58 ( V_10 ) ;
return;
}
}
F_68 ( F_89 ( V_8 ) ) ;
F_90 ( 1 , F_11 ( L_2
L_3 ,
F_91 ( V_8 ) , V_114 ) ) ;
if ( V_115 && ( V_58 . V_124 == V_125 ) ) {
if ( ( V_58 . V_126 == 0x0 ) && ( V_58 . V_127 == 0x1d ) )
;
else if ( ! ( V_8 -> V_52 & V_53 ) )
F_92 ( L_4 , V_10 ) ;
V_59 = 0 ;
error = 0 ;
}
if ( F_61 ( V_10 , error , V_114 , V_59 == 0 ) == NULL )
return;
error = F_81 ( V_10 , V_59 ) ;
if ( F_82 ( V_59 ) == V_128 ) {
V_121 = V_119 ;
} else if ( V_115 && ! V_116 ) {
switch ( V_58 . V_124 ) {
case V_129 :
if ( V_10 -> V_1 -> V_130 ) {
V_10 -> V_1 -> V_131 = 1 ;
V_122 = L_5 ;
V_121 = V_117 ;
} else {
V_121 = V_119 ;
}
break;
case V_132 :
if ( ( V_10 -> V_1 -> V_133 &&
V_58 . V_126 == 0x20 && V_58 . V_127 == 0x00 ) &&
( V_10 -> V_64 [ 0 ] == V_134 ||
V_10 -> V_64 [ 0 ] == V_135 ) ) {
V_10 -> V_1 -> V_133 = 0 ;
V_121 = V_118 ;
} else if ( V_58 . V_126 == 0x10 ) {
V_122 = L_6 ;
V_121 = V_117 ;
error = - V_136 ;
} else if ( V_58 . V_126 == 0x20 || V_58 . V_126 == 0x24 ) {
switch ( V_10 -> V_64 [ 0 ] ) {
case V_137 :
V_122 = L_7 ;
break;
case V_138 :
case V_139 :
if ( V_10 -> V_64 [ 1 ] & 0x8 )
V_122 = L_7 ;
else
V_122 =
L_8 ;
break;
default:
V_122 = L_9 ;
break;
}
V_121 = V_117 ;
error = - V_110 ;
} else
V_121 = V_117 ;
break;
case V_140 :
V_121 = V_117 ;
if ( V_58 . V_126 == 0x10 ) {
V_122 = L_10 ;
error = - V_136 ;
}
break;
case V_141 :
if ( V_58 . V_126 == 0x04 ) {
switch ( V_58 . V_127 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_121 = V_120 ;
break;
default:
V_122 = L_11 ;
V_121 = V_117 ;
break;
}
} else {
V_122 = L_11 ;
V_121 = V_117 ;
}
break;
case V_142 :
V_121 = V_117 ;
break;
default:
V_122 = L_12 ;
V_121 = V_117 ;
break;
}
} else {
V_122 = L_13 ;
V_121 = V_117 ;
}
switch ( V_121 ) {
case V_117 :
F_65 ( V_10 ) ;
if ( ! ( V_8 -> V_52 & V_53 ) ) {
if ( V_122 )
F_93 ( V_143 , V_10 , L_14 ,
V_122 ) ;
F_94 ( V_10 ) ;
if ( F_95 ( V_59 ) & V_144 )
F_92 ( L_4 , V_10 ) ;
F_96 ( V_10 ) ;
}
if ( F_97 ( V_8 , error ) )
F_55 ( V_20 , V_10 ) ;
else
F_58 ( V_10 ) ;
break;
case V_118 :
F_65 ( V_10 ) ;
F_55 ( V_20 , V_10 ) ;
break;
case V_119 :
F_9 ( V_10 , V_26 , 0 ) ;
break;
case V_120 :
F_9 ( V_10 , V_25 , 0 ) ;
break;
}
}
static int F_98 ( struct V_7 * V_8 , struct V_98 * V_99 ,
T_1 V_97 )
{
int V_145 ;
if ( F_23 ( F_74 ( V_99 , V_8 -> V_146 ,
V_97 ) ) ) {
return V_147 ;
}
V_8 -> V_36 = NULL ;
V_145 = F_99 ( V_8 -> V_20 , V_8 , V_99 -> V_100 . V_92 ) ;
F_68 ( V_145 > V_99 -> V_100 . V_88 ) ;
V_99 -> V_100 . V_88 = V_145 ;
V_99 -> V_148 = F_100 ( V_8 ) ;
return V_149 ;
}
int F_101 ( struct V_9 * V_10 , T_1 V_97 )
{
struct V_7 * V_150 = V_10 -> V_7 ;
int error = F_98 ( V_150 , & V_10 -> V_99 , V_97 ) ;
if ( error )
goto V_151;
if ( F_89 ( V_150 ) ) {
struct V_98 * V_102 = F_102 (
V_104 , V_152 ) ;
if ( ! V_102 ) {
error = V_147 ;
goto V_151;
}
V_150 -> V_103 -> V_11 = V_102 ;
error = F_98 ( V_150 -> V_103 , V_102 , V_152 ) ;
if ( error )
goto V_151;
}
if ( F_103 ( V_150 ) ) {
struct V_98 * V_105 = V_10 -> V_105 ;
int V_153 , V_145 ;
F_68 ( V_105 == NULL ) ;
V_153 = F_104 ( V_150 -> V_20 , V_150 -> V_154 ) ;
if ( F_74 ( V_105 , V_153 , V_97 ) ) {
error = V_147 ;
goto V_151;
}
V_145 = F_105 ( V_150 -> V_20 , V_150 -> V_154 ,
V_105 -> V_100 . V_92 ) ;
F_68 ( F_23 ( V_145 > V_153 ) ) ;
F_68 ( F_23 ( V_145 > F_106 ( V_150 -> V_20 ) ) ) ;
V_10 -> V_105 = V_105 ;
V_10 -> V_105 -> V_100 . V_88 = V_145 ;
}
return V_149 ;
V_151:
F_65 ( V_10 ) ;
V_10 -> V_7 -> V_11 = NULL ;
F_8 ( V_10 ) ;
return error ;
}
static struct V_9 * F_107 ( struct V_16 * V_34 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_8 -> V_11 ) {
V_10 = F_108 ( V_34 , V_152 ) ;
if ( F_23 ( ! V_10 ) )
return NULL ;
V_8 -> V_11 = V_10 ;
} else {
V_10 = V_8 -> V_11 ;
}
V_10 -> V_155 = V_8 -> V_155 ;
V_10 -> V_7 = V_8 ;
V_10 -> V_64 = V_8 -> V_10 ;
V_10 -> V_156 = V_157 ;
return V_10 ;
}
int F_109 ( struct V_16 * V_34 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_44 = F_110 ( V_34 , V_8 ) ;
if ( V_44 != V_149 )
return V_44 ;
V_10 = F_107 ( V_34 , V_8 ) ;
if ( F_23 ( ! V_10 ) )
return V_147 ;
if ( V_8 -> V_154 ) {
int V_44 ;
F_68 ( ! V_8 -> V_146 ) ;
V_44 = F_101 ( V_10 , V_152 ) ;
if ( F_23 ( V_44 ) )
return V_44 ;
} else {
F_68 ( F_100 ( V_8 ) ) ;
memset ( & V_10 -> V_99 , 0 , sizeof( V_10 -> V_99 ) ) ;
V_8 -> V_36 = NULL ;
}
V_10 -> V_48 = V_8 -> V_48 ;
if ( ! F_100 ( V_8 ) )
V_10 -> V_158 = V_159 ;
else if ( F_111 ( V_8 ) == V_160 )
V_10 -> V_158 = V_43 ;
else
V_10 -> V_158 = V_161 ;
V_10 -> V_162 = F_100 ( V_8 ) ;
V_10 -> V_163 = V_8 -> V_40 ;
return V_149 ;
}
int F_112 ( struct V_16 * V_34 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_44 = F_110 ( V_34 , V_8 ) ;
if ( V_44 != V_149 )
return V_44 ;
if ( F_23 ( V_34 -> V_164 && V_34 -> V_164 -> V_165
&& V_34 -> V_164 -> V_165 -> V_166 ) ) {
V_44 = V_34 -> V_164 -> V_165 -> V_166 ( V_34 , V_8 ) ;
if ( V_44 != V_149 )
return V_44 ;
}
F_68 ( ! V_8 -> V_146 ) ;
V_10 = F_107 ( V_34 , V_8 ) ;
if ( F_23 ( ! V_10 ) )
return V_147 ;
memset ( V_10 -> V_64 , 0 , V_167 ) ;
return F_101 ( V_10 , V_152 ) ;
}
int F_110 ( struct V_16 * V_34 , struct V_7 * V_8 )
{
int V_44 = V_149 ;
if ( F_23 ( V_34 -> V_168 != V_169 ) ) {
switch ( V_34 -> V_168 ) {
case V_170 :
case V_171 :
F_113 ( V_172 , V_34 ,
L_15 ) ;
V_44 = V_173 ;
break;
case V_174 :
F_113 ( V_172 , V_34 ,
L_16 ) ;
V_44 = V_173 ;
break;
case V_175 :
case V_176 :
case V_177 :
if ( ! ( V_8 -> V_52 & V_54 ) )
V_44 = V_147 ;
break;
default:
if ( ! ( V_8 -> V_52 & V_54 ) )
V_44 = V_173 ;
break;
}
}
return V_44 ;
}
int F_114 ( struct V_19 * V_20 , struct V_7 * V_8 , int V_44 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
switch ( V_44 ) {
case V_173 :
V_8 -> V_56 = V_178 << 16 ;
if ( V_8 -> V_11 ) {
struct V_9 * V_10 = V_8 -> V_11 ;
F_65 ( V_10 ) ;
F_8 ( V_10 ) ;
V_8 -> V_11 = NULL ;
}
break;
case V_147 :
if ( V_34 -> V_71 == 0 )
F_115 ( V_20 , V_179 ) ;
break;
default:
V_8 -> V_52 |= V_180 ;
}
return V_44 ;
}
int F_116 ( struct V_19 * V_20 , struct V_7 * V_8 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
int V_44 = V_173 ;
if ( V_8 -> V_50 == V_51 )
V_44 = F_109 ( V_34 , V_8 ) ;
return F_114 ( V_20 , V_8 , V_44 ) ;
}
static inline int F_117 ( struct V_19 * V_20 ,
struct V_16 * V_34 )
{
if ( V_34 -> V_71 == 0 && V_34 -> V_27 ) {
if ( -- V_34 -> V_27 == 0 ) {
F_10 ( 3 ,
F_113 ( V_143 , V_34 ,
L_17 ) ) ;
} else {
F_115 ( V_20 , V_179 ) ;
return 0 ;
}
}
if ( F_41 ( V_34 ) )
return 0 ;
return 1 ;
}
static inline int F_118 ( struct V_14 * V_65 ,
struct V_16 * V_34 )
{
struct V_17 * V_18 = V_17 ( V_34 ) ;
if ( V_18 -> V_80 ) {
if ( V_18 -> V_74 &&
V_18 -> V_74 != V_34 )
return 0 ;
V_18 -> V_74 = V_34 ;
}
if ( V_18 -> V_68 == 0 && V_18 -> V_30 ) {
if ( -- V_18 -> V_30 == 0 ) {
F_10 ( 3 , F_119 ( V_143 , V_18 ,
L_18 ) ) ;
} else
return 0 ;
}
if ( F_42 ( V_18 ) ) {
F_50 ( & V_34 -> V_82 , & V_65 -> V_79 ) ;
return 0 ;
}
return 1 ;
}
static inline int F_120 ( struct V_19 * V_20 ,
struct V_14 * V_65 ,
struct V_16 * V_34 )
{
if ( F_32 ( V_65 ) )
return 0 ;
if ( V_65 -> V_67 == 0 && V_65 -> V_23 ) {
if ( -- V_65 -> V_23 == 0 ) {
F_10 ( 3 ,
F_11 ( L_19 ,
V_65 -> V_181 ) ) ;
} else {
return 0 ;
}
}
if ( F_43 ( V_65 ) ) {
if ( F_47 ( & V_34 -> V_82 ) )
F_121 ( & V_34 -> V_82 , & V_65 -> V_79 ) ;
return 0 ;
}
if ( ! F_47 ( & V_34 -> V_82 ) )
F_49 ( & V_34 -> V_82 ) ;
return 1 ;
}
static int F_122 ( struct V_19 * V_20 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
struct V_14 * V_65 ;
if ( F_123 ( V_20 ) )
return 0 ;
V_65 = V_34 -> V_15 ;
if ( F_32 ( V_65 ) || F_41 ( V_34 ) )
return 1 ;
return 0 ;
}
static void F_124 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_16 * V_34 ;
struct V_17 * V_18 ;
struct V_14 * V_65 ;
F_125 ( V_8 ) ;
F_93 ( V_143 , V_10 , L_20 ) ;
V_34 = V_10 -> V_1 ;
V_18 = V_17 ( V_34 ) ;
V_65 = V_34 -> V_15 ;
F_29 ( V_10 ) ;
V_10 -> V_59 = V_178 << 16 ;
F_126 ( & V_10 -> V_1 -> V_182 ) ;
V_34 -> V_71 ++ ;
F_34 ( V_34 -> V_19 -> V_32 ) ;
F_35 ( V_65 -> V_66 ) ;
V_65 -> V_67 ++ ;
V_18 -> V_68 ++ ;
F_34 ( V_65 -> V_66 ) ;
F_35 ( V_34 -> V_19 -> V_32 ) ;
F_127 ( V_8 ) ;
}
static void F_128 ( struct V_7 * V_150 )
{
struct V_9 * V_10 = V_150 -> V_11 ;
unsigned long V_183 = ( V_10 -> V_163 + 1 ) * V_150 -> V_39 ;
int V_184 ;
F_129 ( & V_10 -> V_185 ) ;
F_126 ( & V_10 -> V_1 -> V_186 ) ;
if ( V_10 -> V_59 )
F_126 ( & V_10 -> V_1 -> V_187 ) ;
V_184 = F_130 ( V_10 ) ;
if ( V_184 != V_188 &&
F_131 ( V_10 -> V_189 + V_183 , V_190 ) ) {
F_113 ( V_172 , V_10 -> V_1 ,
L_21 ,
V_183 / V_191 ) ;
V_184 = V_188 ;
}
F_132 ( V_10 , V_184 ) ;
switch ( V_184 ) {
case V_188 :
F_133 ( V_10 ) ;
break;
case V_192 :
F_17 ( V_10 , V_26 ) ;
break;
case V_193 :
F_17 ( V_10 , V_25 ) ;
break;
default:
if ( ! F_134 ( V_10 , 0 ) )
F_133 ( V_10 ) ;
}
}
static void F_135 ( struct V_19 * V_20 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
struct V_14 * V_65 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
if( ! F_56 ( & V_34 -> V_85 ) )
return;
V_65 = V_34 -> V_15 ;
for (; ; ) {
int V_194 ;
V_8 = F_136 ( V_20 ) ;
if ( ! V_8 || ! F_117 ( V_20 , V_34 ) )
break;
if ( F_23 ( ! F_137 ( V_34 ) ) ) {
F_113 ( V_172 , V_34 ,
L_15 ) ;
F_124 ( V_8 , V_20 ) ;
continue;
}
if ( ! ( F_138 ( V_20 ) && ! F_139 ( V_20 , V_8 ) ) )
F_125 ( V_8 ) ;
V_34 -> V_71 ++ ;
F_34 ( V_20 -> V_32 ) ;
V_10 = V_8 -> V_11 ;
if ( F_23 ( V_10 == NULL ) ) {
F_11 ( V_195 L_22
L_23
L_24 ,
V_196 ) ;
F_140 ( V_8 , L_25 ) ;
F_141 () ;
}
F_35 ( V_65 -> V_66 ) ;
if ( F_138 ( V_20 ) && ! F_142 ( V_8 ) ) {
if ( F_47 ( & V_34 -> V_82 ) )
F_121 ( & V_34 -> V_82 ,
& V_65 -> V_79 ) ;
goto V_197;
}
if ( ! F_118 ( V_65 , V_34 ) )
goto V_197;
if ( ! F_120 ( V_20 , V_65 , V_34 ) )
goto V_197;
V_17 ( V_34 ) -> V_68 ++ ;
V_65 -> V_67 ++ ;
F_143 ( V_65 -> V_66 ) ;
F_29 ( V_10 ) ;
V_194 = F_144 ( V_10 ) ;
F_145 ( V_20 -> V_32 ) ;
if ( V_194 )
goto V_198;
}
goto V_47;
V_197:
F_143 ( V_65 -> V_66 ) ;
F_145 ( V_20 -> V_32 ) ;
F_14 ( V_20 , V_8 ) ;
V_34 -> V_71 -- ;
V_198:
if ( V_34 -> V_71 == 0 )
F_115 ( V_20 , V_179 ) ;
V_47:
F_143 ( V_20 -> V_32 ) ;
F_57 ( & V_34 -> V_85 ) ;
F_145 ( V_20 -> V_32 ) ;
}
T_2 F_146 ( struct V_14 * V_65 )
{
struct V_1 * V_199 ;
T_2 V_200 = 0xffffffff ;
if ( V_65 -> V_201 )
return V_202 ;
if ( ! V_203 )
return V_204 ;
V_199 = F_147 ( V_65 ) ;
if ( V_199 && V_199 -> V_205 )
V_200 = * V_199 -> V_205 ;
return V_200 ;
}
struct V_19 * F_148 ( struct V_14 * V_65 ,
T_3 * V_206 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_65 -> V_207 ;
V_20 = F_149 ( V_206 , NULL ) ;
if ( ! V_20 )
return NULL ;
F_150 ( V_20 , F_151 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_152 ( V_65 ) ) {
V_65 -> V_208 =
F_153 ( V_65 -> V_208 ,
( unsigned short ) V_209 ) ;
F_68 ( V_65 -> V_208 < V_65 -> V_210 ) ;
F_154 ( V_20 , V_65 -> V_208 ) ;
}
F_155 ( V_20 , V_65 -> V_211 ) ;
F_156 ( V_20 , F_146 ( V_65 ) ) ;
F_157 ( V_20 , V_65 -> V_212 ) ;
F_158 ( V_2 , V_65 -> V_212 ) ;
F_159 ( V_20 , F_160 ( V_2 ) ) ;
if ( ! V_65 -> V_213 )
V_20 -> V_214 . V_215 = 0 ;
F_161 ( V_20 , 0x03 ) ;
return V_20 ;
}
struct V_19 * F_162 ( struct V_16 * V_34 )
{
struct V_19 * V_20 ;
V_20 = F_148 ( V_34 -> V_15 , F_135 ) ;
if ( ! V_20 )
return NULL ;
F_163 ( V_20 , F_116 ) ;
F_164 ( V_20 , F_128 ) ;
F_165 ( V_20 , V_216 ) ;
F_166 ( V_20 , F_122 ) ;
return V_20 ;
}
void F_167 ( struct V_14 * V_65 )
{
V_65 -> V_77 = 1 ;
}
void F_168 ( struct V_14 * V_65 )
{
V_65 -> V_77 = 0 ;
F_59 ( V_65 ) ;
}
int T_4 F_169 ( void )
{
int V_217 ;
V_104 = F_170 ( L_26 ,
sizeof( struct V_98 ) ,
0 , 0 , NULL ) ;
if ( ! V_104 ) {
F_11 ( V_172 L_27 ) ;
return - V_218 ;
}
for ( V_217 = 0 ; V_217 < V_219 ; V_217 ++ ) {
struct V_93 * V_94 = V_95 + V_217 ;
int V_220 = V_94 -> V_220 * sizeof( struct V_91 ) ;
V_94 -> V_221 = F_170 ( V_94 -> V_222 , V_220 , 0 ,
V_223 , NULL ) ;
if ( ! V_94 -> V_221 ) {
F_11 ( V_172 L_28 ,
V_94 -> V_222 ) ;
goto V_224;
}
V_94 -> V_96 = F_171 ( V_225 ,
V_94 -> V_221 ) ;
if ( ! V_94 -> V_96 ) {
F_11 ( V_172 L_29 ,
V_94 -> V_222 ) ;
goto V_224;
}
}
return 0 ;
V_224:
for ( V_217 = 0 ; V_217 < V_219 ; V_217 ++ ) {
struct V_93 * V_94 = V_95 + V_217 ;
if ( V_94 -> V_96 )
F_172 ( V_94 -> V_96 ) ;
if ( V_94 -> V_221 )
F_173 ( V_94 -> V_221 ) ;
}
F_173 ( V_104 ) ;
return - V_218 ;
}
void F_174 ( void )
{
int V_217 ;
F_173 ( V_104 ) ;
for ( V_217 = 0 ; V_217 < V_219 ; V_217 ++ ) {
struct V_93 * V_94 = V_95 + V_217 ;
F_172 ( V_94 -> V_96 ) ;
F_173 ( V_94 -> V_221 ) ;
}
}
int
F_175 ( struct V_16 * V_34 , int V_226 , int V_227 , int V_228 ,
unsigned char * V_36 , int V_123 , int V_39 , int V_40 ,
struct V_229 * V_230 , struct V_57 * V_58 )
{
unsigned char V_10 [ 10 ] ;
unsigned char * V_231 ;
int V_44 ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_10 [ 1 ] = ( V_226 ? 0x10 : 0 ) | ( V_227 ? 0x01 : 0 ) ;
if ( V_34 -> V_232 ) {
if ( V_123 > 65535 )
return - V_233 ;
V_231 = F_176 ( 8 + V_123 , V_234 ) ;
if ( ! V_231 )
return - V_218 ;
memcpy ( V_231 + 8 , V_36 , V_123 ) ;
V_123 += 8 ;
V_231 [ 0 ] = 0 ;
V_231 [ 1 ] = 0 ;
V_231 [ 2 ] = V_230 -> V_235 ;
V_231 [ 3 ] = V_230 -> V_236 ;
V_231 [ 4 ] = V_230 -> V_237 ? 0x01 : 0 ;
V_231 [ 5 ] = 0 ;
V_231 [ 6 ] = V_230 -> V_238 >> 8 ;
V_231 [ 7 ] = V_230 -> V_238 ;
V_10 [ 0 ] = V_239 ;
V_10 [ 7 ] = V_123 >> 8 ;
V_10 [ 8 ] = V_123 ;
} else {
if ( V_123 > 255 || V_230 -> V_238 > 255 ||
V_230 -> V_237 )
return - V_233 ;
V_231 = F_176 ( 4 + V_123 , V_234 ) ;
if ( ! V_231 )
return - V_218 ;
memcpy ( V_231 + 4 , V_36 , V_123 ) ;
V_123 += 4 ;
V_231 [ 0 ] = 0 ;
V_231 [ 1 ] = V_230 -> V_235 ;
V_231 [ 2 ] = V_230 -> V_236 ;
V_231 [ 3 ] = V_230 -> V_238 ;
V_10 [ 0 ] = V_240 ;
V_10 [ 4 ] = V_123 ;
}
V_44 = F_177 ( V_34 , V_10 , V_43 , V_231 , V_123 ,
V_58 , V_39 , V_40 , NULL ) ;
F_28 ( V_231 ) ;
return V_44 ;
}
int
F_178 ( struct V_16 * V_34 , int V_241 , int V_228 ,
unsigned char * V_36 , int V_123 , int V_39 , int V_40 ,
struct V_229 * V_230 , struct V_57 * V_58 )
{
unsigned char V_10 [ 12 ] ;
int V_232 ;
int V_242 ;
int V_59 ;
struct V_57 V_243 ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
memset ( & V_10 [ 0 ] , 0 , 12 ) ;
V_10 [ 1 ] = V_241 & 0x18 ;
V_10 [ 2 ] = V_228 ;
if ( ! V_58 )
V_58 = & V_243 ;
V_244:
V_232 = V_34 -> V_232 ;
if ( V_232 ) {
if ( V_123 < 8 )
V_123 = 8 ;
V_10 [ 0 ] = V_245 ;
V_10 [ 8 ] = V_123 ;
V_242 = 8 ;
} else {
if ( V_123 < 4 )
V_123 = 4 ;
V_10 [ 0 ] = V_246 ;
V_10 [ 4 ] = V_123 ;
V_242 = 4 ;
}
memset ( V_36 , 0 , V_123 ) ;
V_59 = F_177 ( V_34 , V_10 , V_161 , V_36 , V_123 ,
V_58 , V_39 , V_40 , NULL ) ;
if ( V_232 && ! F_179 ( V_59 ) &&
( F_95 ( V_59 ) & V_144 ) ) {
if ( F_180 ( V_58 ) ) {
if ( ( V_58 -> V_124 == V_132 ) &&
( V_58 -> V_126 == 0x20 ) && ( V_58 -> V_127 == 0 ) ) {
V_34 -> V_232 = 0 ;
goto V_244;
}
}
}
if( F_179 ( V_59 ) ) {
if ( F_23 ( V_36 [ 0 ] == 0x86 && V_36 [ 1 ] == 0x0b &&
( V_228 == 6 || V_228 == 8 ) ) ) {
V_242 = 0 ;
V_230 -> V_148 = 13 ;
V_230 -> V_235 = 0 ;
V_230 -> V_236 = 0 ;
V_230 -> V_237 = 0 ;
V_230 -> V_238 = 0 ;
} else if( V_232 ) {
V_230 -> V_148 = V_36 [ 0 ] * 256 + V_36 [ 1 ] + 2 ;
V_230 -> V_235 = V_36 [ 2 ] ;
V_230 -> V_236 = V_36 [ 3 ] ;
V_230 -> V_237 = V_36 [ 4 ] & 0x01 ;
V_230 -> V_238 = V_36 [ 6 ] * 256
+ V_36 [ 7 ] ;
} else {
V_230 -> V_148 = V_36 [ 0 ] + 1 ;
V_230 -> V_235 = V_36 [ 1 ] ;
V_230 -> V_236 = V_36 [ 2 ] ;
V_230 -> V_238 = V_36 [ 3 ] ;
}
V_230 -> V_242 = V_242 ;
}
return V_59 ;
}
int
F_181 ( struct V_16 * V_34 , int V_39 , int V_40 ,
struct V_57 * V_247 )
{
char V_10 [] = {
V_248 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_57 * V_58 ;
int V_59 ;
if ( ! V_247 )
V_58 = F_26 ( sizeof( * V_58 ) , V_234 ) ;
else
V_58 = V_247 ;
do {
V_59 = F_177 ( V_34 , V_10 , V_159 , NULL , 0 , V_58 ,
V_39 , V_40 , NULL ) ;
if ( V_34 -> V_130 && F_180 ( V_58 ) &&
V_58 -> V_124 == V_129 )
V_34 -> V_131 = 1 ;
} while ( F_180 ( V_58 ) &&
V_58 -> V_124 == V_129 && -- V_40 );
if ( ! V_247 )
F_28 ( V_58 ) ;
return V_59 ;
}
int
F_182 ( struct V_16 * V_34 , enum V_249 V_250 )
{
enum V_249 V_251 = V_34 -> V_168 ;
if ( V_250 == V_251 )
return 0 ;
switch ( V_250 ) {
case V_252 :
switch ( V_251 ) {
case V_177 :
break;
default:
goto V_253;
}
break;
case V_169 :
switch ( V_251 ) {
case V_252 :
case V_170 :
case V_171 :
case V_175 :
case V_176 :
break;
default:
goto V_253;
}
break;
case V_175 :
switch ( V_251 ) {
case V_169 :
case V_170 :
case V_171 :
break;
default:
goto V_253;
}
break;
case V_170 :
case V_171 :
switch ( V_251 ) {
case V_252 :
case V_169 :
case V_175 :
case V_176 :
break;
default:
goto V_253;
}
break;
case V_176 :
switch ( V_251 ) {
case V_169 :
case V_177 :
break;
default:
goto V_253;
}
break;
case V_177 :
switch ( V_251 ) {
case V_252 :
break;
default:
goto V_253;
}
break;
case V_254 :
switch ( V_251 ) {
case V_252 :
case V_169 :
case V_175 :
case V_170 :
case V_171 :
case V_176 :
break;
default:
goto V_253;
}
break;
case V_174 :
switch ( V_251 ) {
case V_252 :
case V_169 :
case V_170 :
case V_171 :
case V_254 :
break;
default:
goto V_253;
}
break;
}
V_34 -> V_168 = V_250 ;
return 0 ;
V_253:
F_183 ( 1 ,
F_113 ( V_172 , V_34 ,
L_30 ,
F_184 ( V_251 ) ,
F_184 ( V_250 ) )
) ;
return - V_233 ;
}
static void F_185 ( struct V_16 * V_34 , struct V_255 * V_256 )
{
int V_257 = 0 ;
char * V_258 [ 3 ] ;
switch ( V_256 -> V_259 ) {
case V_260 :
V_258 [ V_257 ++ ] = L_31 ;
break;
default:
break;
}
V_258 [ V_257 ++ ] = NULL ;
F_186 ( & V_34 -> V_85 . V_261 , V_262 , V_258 ) ;
}
void F_187 ( struct V_83 * V_84 )
{
struct V_16 * V_34 ;
F_45 ( V_263 ) ;
V_34 = F_54 ( V_84 , struct V_16 , V_264 ) ;
while ( 1 ) {
struct V_255 * V_256 ;
struct V_265 * V_266 , * V_73 ;
unsigned long V_21 ;
F_13 ( & V_34 -> V_267 , V_21 ) ;
F_46 ( & V_34 -> V_263 , & V_263 ) ;
F_16 ( & V_34 -> V_267 , V_21 ) ;
if ( F_47 ( & V_263 ) )
break;
F_188 (this, tmp, &event_list) {
V_256 = F_48 ( V_266 , struct V_255 , V_268 ) ;
F_189 ( & V_256 -> V_268 ) ;
F_185 ( V_34 , V_256 ) ;
F_28 ( V_256 ) ;
}
}
}
void F_190 ( struct V_16 * V_34 , struct V_255 * V_256 )
{
unsigned long V_21 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_13 ( & V_34 -> V_267 , V_21 ) ;
F_121 ( & V_256 -> V_268 , & V_34 -> V_263 ) ;
F_191 ( & V_34 -> V_264 ) ;
F_16 ( & V_34 -> V_267 , V_21 ) ;
}
struct V_255 * F_192 ( enum V_269 V_259 ,
T_1 V_270 )
{
struct V_255 * V_256 = F_26 ( sizeof( struct V_255 ) , V_270 ) ;
if ( ! V_256 )
return NULL ;
V_256 -> V_259 = V_259 ;
F_129 ( & V_256 -> V_268 ) ;
switch ( V_259 ) {
case V_260 :
default:
break;
}
return V_256 ;
}
void F_193 ( struct V_16 * V_34 ,
enum V_269 V_259 , T_1 V_270 )
{
struct V_255 * V_256 = F_192 ( V_259 , V_270 ) ;
if ( ! V_256 ) {
F_113 ( V_172 , V_34 , L_32 ,
V_259 ) ;
return;
}
F_190 ( V_34 , V_256 ) ;
}
int
F_194 ( struct V_16 * V_34 )
{
int V_271 = F_182 ( V_34 , V_175 ) ;
if ( V_271 )
return V_271 ;
F_44 ( V_34 -> V_19 ) ;
while ( V_34 -> V_71 ) {
F_195 ( 200 ) ;
F_44 ( V_34 -> V_19 ) ;
}
return 0 ;
}
void F_196 ( struct V_16 * V_34 )
{
if ( V_34 -> V_168 != V_175 ||
F_182 ( V_34 , V_169 ) )
return;
F_44 ( V_34 -> V_19 ) ;
}
static void
F_197 ( struct V_16 * V_34 , void * V_230 )
{
F_194 ( V_34 ) ;
}
void
F_198 ( struct V_17 * V_18 )
{
F_199 ( V_18 , NULL , F_197 ) ;
}
static void
F_200 ( struct V_16 * V_34 , void * V_230 )
{
F_196 ( V_34 ) ;
}
void
F_201 ( struct V_17 * V_18 )
{
F_199 ( V_18 , NULL , F_200 ) ;
}
int
F_202 ( struct V_16 * V_34 )
{
struct V_19 * V_20 = V_34 -> V_19 ;
unsigned long V_21 ;
int V_271 = 0 ;
V_271 = F_182 ( V_34 , V_176 ) ;
if ( V_271 ) {
V_271 = F_182 ( V_34 , V_177 ) ;
if ( V_271 )
return V_271 ;
}
F_13 ( V_20 -> V_32 , V_21 ) ;
F_203 ( V_20 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
return 0 ;
}
int
F_204 ( struct V_16 * V_34 ,
enum V_249 V_272 )
{
struct V_19 * V_20 = V_34 -> V_19 ;
unsigned long V_21 ;
if ( ( V_34 -> V_168 == V_176 ) ||
( V_34 -> V_168 == V_171 ) )
V_34 -> V_168 = V_272 ;
else if ( V_34 -> V_168 == V_177 ) {
if ( V_272 == V_171 ||
V_272 == V_170 )
V_34 -> V_168 = V_272 ;
else
V_34 -> V_168 = V_252 ;
} else if ( V_34 -> V_168 != V_254 &&
V_34 -> V_168 != V_170 )
return - V_233 ;
F_13 ( V_20 -> V_32 , V_21 ) ;
F_205 ( V_20 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
return 0 ;
}
static void
F_206 ( struct V_16 * V_34 , void * V_230 )
{
F_202 ( V_34 ) ;
}
static int
F_207 ( struct V_1 * V_2 , void * V_230 )
{
if ( F_208 ( V_2 ) )
F_199 ( F_209 ( V_2 ) , NULL ,
F_206 ) ;
return 0 ;
}
void
F_210 ( struct V_1 * V_2 )
{
if ( F_208 ( V_2 ) )
F_199 ( F_209 ( V_2 ) , NULL ,
F_206 ) ;
else
F_211 ( V_2 , NULL , F_207 ) ;
}
static void
F_212 ( struct V_16 * V_34 , void * V_230 )
{
F_204 ( V_34 , * (enum V_249 * ) V_230 ) ;
}
static int
F_213 ( struct V_1 * V_2 , void * V_230 )
{
if ( F_208 ( V_2 ) )
F_199 ( F_209 ( V_2 ) , V_230 ,
F_212 ) ;
return 0 ;
}
void
F_214 ( struct V_1 * V_2 , enum V_249 V_272 )
{
if ( F_208 ( V_2 ) )
F_199 ( F_209 ( V_2 ) , & V_272 ,
F_212 ) ;
else
F_211 ( V_2 , & V_272 , F_213 ) ;
}
void * F_215 ( struct V_91 * V_92 , int V_273 ,
T_5 * V_274 , T_5 * V_123 )
{
int V_217 ;
T_5 V_275 = 0 , V_276 = 0 ;
struct V_91 * V_277 ;
struct V_278 * V_278 ;
F_216 ( ! F_217 () ) ;
F_218 (sgl, sg, sg_count, i) {
V_276 = V_275 ;
V_275 += V_277 -> V_148 ;
if ( V_275 > * V_274 )
break;
}
if ( F_23 ( V_217 == V_273 ) ) {
F_11 ( V_172 L_33
L_34 ,
V_196 , V_275 , * V_274 , V_273 ) ;
F_216 ( 1 ) ;
return NULL ;
}
* V_274 = * V_274 - V_276 + V_277 -> V_274 ;
V_278 = F_219 ( F_220 ( V_277 ) , ( * V_274 >> V_279 ) ) ;
* V_274 &= ~ V_280 ;
V_275 = V_281 - * V_274 ;
if ( * V_123 > V_275 )
* V_123 = V_275 ;
return F_221 ( V_278 ) ;
}
void F_222 ( void * V_282 )
{
F_223 ( V_282 ) ;
}
void F_224 ( struct V_16 * V_34 )
{
F_126 ( & V_34 -> V_283 ) ;
}
void F_225 ( struct V_16 * V_34 )
{
if ( F_226 ( F_227 ( & V_34 -> V_283 ) <= 0 ) )
return;
F_228 ( & V_34 -> V_283 ) ;
}
