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
struct V_19 * V_81 ;
if ( F_43 ( V_65 ) )
break;
V_34 = F_48 ( V_79 . V_82 ,
struct V_16 , V_83 ) ;
F_49 ( & V_34 -> V_83 ) ;
if ( F_42 ( V_17 ( V_34 ) ) ) {
F_50 ( & V_34 -> V_83 ,
& V_65 -> V_79 ) ;
continue;
}
V_81 = V_34 -> V_19 ;
if ( ! F_51 ( V_81 ) )
continue;
F_16 ( V_65 -> V_66 , V_21 ) ;
F_37 ( V_81 ) ;
F_52 ( V_81 ) ;
F_13 ( V_65 -> V_66 , V_21 ) ;
}
F_53 ( & V_79 , & V_65 -> V_79 ) ;
F_16 ( V_65 -> V_66 , V_21 ) ;
F_37 ( V_20 ) ;
}
void F_54 ( struct V_84 * V_85 )
{
struct V_16 * V_34 ;
struct V_19 * V_20 ;
V_34 = F_55 ( V_85 , struct V_16 , V_33 ) ;
V_20 = V_34 -> V_19 ;
F_44 ( V_20 ) ;
}
static void F_56 ( struct V_19 * V_20 , struct V_9 * V_10 )
{
struct V_16 * V_34 = V_10 -> V_1 ;
struct V_7 * V_8 = V_10 -> V_7 ;
unsigned long V_21 ;
F_57 ( & V_34 -> V_86 ) ;
F_13 ( V_20 -> V_32 , V_21 ) ;
F_6 ( V_8 ) ;
F_14 ( V_20 , V_8 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
F_44 ( V_20 ) ;
F_58 ( & V_34 -> V_86 ) ;
}
void F_59 ( struct V_9 * V_10 )
{
struct V_16 * V_34 = V_10 -> V_1 ;
struct V_19 * V_20 = V_34 -> V_19 ;
F_57 ( & V_34 -> V_86 ) ;
F_8 ( V_10 ) ;
F_44 ( V_20 ) ;
F_58 ( & V_34 -> V_86 ) ;
}
void F_60 ( struct V_14 * V_65 )
{
struct V_16 * V_34 ;
F_61 (sdev, shost)
F_44 ( V_34 -> V_19 ) ;
}
static struct V_9 * F_62 ( struct V_9 * V_10 , int error ,
int V_87 , int V_88 )
{
struct V_19 * V_20 = V_10 -> V_1 -> V_19 ;
struct V_7 * V_8 = V_10 -> V_7 ;
if ( F_63 ( V_8 , error , V_87 ) ) {
if ( error && F_64 ( V_10 ) )
F_65 ( V_8 , error ) ;
else {
if ( V_88 ) {
F_66 ( V_10 ) ;
F_56 ( V_20 , V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
}
F_67 ( V_10 , 0 ) ;
F_59 ( V_10 ) ;
return NULL ;
}
static inline unsigned int F_68 ( unsigned short V_89 )
{
unsigned int V_90 ;
F_69 ( V_89 > V_91 ) ;
if ( V_89 <= 8 )
V_90 = 0 ;
else
V_90 = F_70 ( V_89 ) - 3 ;
return V_90 ;
}
static void F_71 ( struct V_92 * V_93 , unsigned int V_89 )
{
struct V_94 * V_95 ;
V_95 = V_96 + F_68 ( V_89 ) ;
F_72 ( V_93 , V_95 -> V_97 ) ;
}
static struct V_92 * F_73 ( unsigned int V_89 , T_1 V_98 )
{
struct V_94 * V_95 ;
V_95 = V_96 + F_68 ( V_89 ) ;
return F_74 ( V_95 -> V_97 , V_98 ) ;
}
static int F_75 ( struct V_99 * V_100 , int V_89 ,
T_1 V_98 )
{
int V_44 ;
F_69 ( ! V_89 ) ;
V_44 = F_76 ( & V_100 -> V_101 , V_89 , V_91 ,
V_98 , F_73 ) ;
if ( F_23 ( V_44 ) )
F_77 ( & V_100 -> V_101 , V_91 ,
F_71 ) ;
return V_44 ;
}
static void F_78 ( struct V_99 * V_100 )
{
F_77 ( & V_100 -> V_101 , V_91 , F_71 ) ;
}
static void F_67 ( struct V_9 * V_10 , int V_102 )
{
if ( V_10 -> V_100 . V_101 . V_89 )
F_78 ( & V_10 -> V_100 ) ;
memset ( & V_10 -> V_100 , 0 , sizeof( V_10 -> V_100 ) ) ;
if ( V_102 && F_79 ( V_10 ) ) {
struct V_99 * V_103 =
V_10 -> V_7 -> V_104 -> V_11 ;
F_78 ( V_103 ) ;
F_80 ( V_105 , V_103 ) ;
V_10 -> V_7 -> V_104 -> V_11 = NULL ;
}
if ( F_81 ( V_10 ) )
F_78 ( V_10 -> V_106 ) ;
}
void F_66 ( struct V_9 * V_10 )
{
F_67 ( V_10 , 1 ) ;
}
static int F_82 ( struct V_9 * V_10 , int V_59 )
{
int error = 0 ;
switch( F_83 ( V_59 ) ) {
case V_107 :
error = - V_108 ;
break;
case V_109 :
F_84 ( V_10 , V_110 ) ;
error = - V_111 ;
break;
case V_112 :
F_84 ( V_10 , V_110 ) ;
error = - V_113 ;
break;
default:
error = - V_114 ;
break;
}
return error ;
}
void F_85 ( struct V_9 * V_10 , unsigned int V_115 )
{
int V_59 = V_10 -> V_59 ;
struct V_19 * V_20 = V_10 -> V_1 -> V_19 ;
struct V_7 * V_8 = V_10 -> V_7 ;
int error = 0 ;
struct V_57 V_58 ;
int V_116 = 0 ;
int V_117 = 0 ;
enum { V_118 , V_119 , V_120 ,
V_121 } V_122 ;
char * V_123 = NULL ;
if ( V_59 ) {
V_116 = F_86 ( V_10 , & V_58 ) ;
if ( V_116 )
V_117 = F_87 ( & V_58 ) ;
}
if ( V_8 -> V_50 == V_51 ) {
if ( V_59 ) {
if ( V_116 && V_8 -> V_38 ) {
int V_124 = 8 + V_10 -> V_63 [ 7 ] ;
if ( V_124 > V_60 )
V_124 = V_60 ;
memcpy ( V_8 -> V_38 , V_10 -> V_63 , V_124 ) ;
V_8 -> V_49 = V_124 ;
}
if ( ! V_117 )
error = F_82 ( V_10 , V_59 ) ;
}
V_8 -> V_56 = V_10 -> V_59 ;
V_8 -> V_55 = F_88 ( V_10 ) ;
if ( F_79 ( V_10 ) ) {
V_8 -> V_104 -> V_55 = F_89 ( V_10 ) -> V_41 ;
F_66 ( V_10 ) ;
F_65 ( V_8 , 0 ) ;
F_59 ( V_10 ) ;
return;
}
}
F_69 ( F_90 ( V_8 ) ) ;
F_91 ( 1 , F_11 ( L_2
L_3 ,
F_92 ( V_8 ) , V_115 ) ) ;
if ( V_116 && ( V_58 . V_125 == V_126 ) ) {
if ( ( V_58 . V_127 == 0x0 ) && ( V_58 . V_128 == 0x1d ) )
;
else if ( ! ( V_8 -> V_52 & V_53 ) )
F_93 ( L_4 , V_10 ) ;
V_59 = 0 ;
error = 0 ;
}
if ( F_62 ( V_10 , error , V_115 , V_59 == 0 ) == NULL )
return;
error = F_82 ( V_10 , V_59 ) ;
if ( F_83 ( V_59 ) == V_129 ) {
V_122 = V_120 ;
} else if ( V_116 && ! V_117 ) {
switch ( V_58 . V_125 ) {
case V_130 :
if ( V_10 -> V_1 -> V_131 ) {
V_10 -> V_1 -> V_132 = 1 ;
V_123 = L_5 ;
V_122 = V_118 ;
} else {
V_122 = V_120 ;
}
break;
case V_133 :
if ( ( V_10 -> V_1 -> V_134 &&
V_58 . V_127 == 0x20 && V_58 . V_128 == 0x00 ) &&
( V_10 -> V_64 [ 0 ] == V_135 ||
V_10 -> V_64 [ 0 ] == V_136 ) ) {
V_10 -> V_1 -> V_134 = 0 ;
V_122 = V_119 ;
} else if ( V_58 . V_127 == 0x10 ) {
V_123 = L_6 ;
V_122 = V_118 ;
error = - V_137 ;
} else if ( V_58 . V_127 == 0x20 || V_58 . V_127 == 0x24 ) {
switch ( V_10 -> V_64 [ 0 ] ) {
case V_138 :
V_123 = L_7 ;
break;
case V_139 :
case V_140 :
if ( V_10 -> V_64 [ 1 ] & 0x8 )
V_123 = L_7 ;
else
V_123 =
L_8 ;
break;
default:
V_123 = L_9 ;
break;
}
V_122 = V_118 ;
error = - V_111 ;
} else
V_122 = V_118 ;
break;
case V_141 :
V_122 = V_118 ;
if ( V_58 . V_127 == 0x10 ) {
V_123 = L_10 ;
error = - V_137 ;
}
break;
case V_142 :
if ( V_58 . V_127 == 0x04 ) {
switch ( V_58 . V_128 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_122 = V_121 ;
break;
default:
V_123 = L_11 ;
V_122 = V_118 ;
break;
}
} else {
V_123 = L_11 ;
V_122 = V_118 ;
}
break;
case V_143 :
V_122 = V_118 ;
break;
default:
V_123 = L_12 ;
V_122 = V_118 ;
break;
}
} else {
V_123 = L_13 ;
V_122 = V_118 ;
}
switch ( V_122 ) {
case V_118 :
F_66 ( V_10 ) ;
if ( ! ( V_8 -> V_52 & V_53 ) ) {
if ( V_123 )
F_94 ( V_144 , V_10 , L_14 ,
V_123 ) ;
F_95 ( V_10 ) ;
if ( F_96 ( V_59 ) & V_145 )
F_93 ( L_4 , V_10 ) ;
F_97 ( V_10 ) ;
}
if ( F_98 ( V_8 , error ) )
F_56 ( V_20 , V_10 ) ;
else
F_59 ( V_10 ) ;
break;
case V_119 :
F_66 ( V_10 ) ;
F_56 ( V_20 , V_10 ) ;
break;
case V_120 :
F_9 ( V_10 , V_26 , 0 ) ;
break;
case V_121 :
F_9 ( V_10 , V_25 , 0 ) ;
break;
}
}
static int F_99 ( struct V_7 * V_8 , struct V_99 * V_100 ,
T_1 V_98 )
{
int V_146 ;
if ( F_23 ( F_75 ( V_100 , V_8 -> V_147 ,
V_98 ) ) ) {
return V_148 ;
}
V_8 -> V_36 = NULL ;
V_146 = F_100 ( V_8 -> V_20 , V_8 , V_100 -> V_101 . V_93 ) ;
F_69 ( V_146 > V_100 -> V_101 . V_89 ) ;
V_100 -> V_101 . V_89 = V_146 ;
V_100 -> V_149 = F_101 ( V_8 ) ;
return V_150 ;
}
int F_102 ( struct V_9 * V_10 , T_1 V_98 )
{
struct V_7 * V_151 = V_10 -> V_7 ;
int error = F_99 ( V_151 , & V_10 -> V_100 , V_98 ) ;
if ( error )
goto V_152;
if ( F_90 ( V_151 ) ) {
struct V_99 * V_103 = F_103 (
V_105 , V_153 ) ;
if ( ! V_103 ) {
error = V_148 ;
goto V_152;
}
V_151 -> V_104 -> V_11 = V_103 ;
error = F_99 ( V_151 -> V_104 , V_103 , V_153 ) ;
if ( error )
goto V_152;
}
if ( F_104 ( V_151 ) ) {
struct V_99 * V_106 = V_10 -> V_106 ;
int V_154 , V_146 ;
F_69 ( V_106 == NULL ) ;
V_154 = F_105 ( V_151 -> V_20 , V_151 -> V_155 ) ;
if ( F_75 ( V_106 , V_154 , V_98 ) ) {
error = V_148 ;
goto V_152;
}
V_146 = F_106 ( V_151 -> V_20 , V_151 -> V_155 ,
V_106 -> V_101 . V_93 ) ;
F_69 ( F_23 ( V_146 > V_154 ) ) ;
F_69 ( F_23 ( V_146 > F_107 ( V_151 -> V_20 ) ) ) ;
V_10 -> V_106 = V_106 ;
V_10 -> V_106 -> V_101 . V_89 = V_146 ;
}
return V_150 ;
V_152:
F_66 ( V_10 ) ;
V_10 -> V_7 -> V_11 = NULL ;
F_8 ( V_10 ) ;
return error ;
}
static struct V_9 * F_108 ( struct V_16 * V_34 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_8 -> V_11 ) {
V_10 = F_109 ( V_34 , V_153 ) ;
if ( F_23 ( ! V_10 ) )
return NULL ;
V_8 -> V_11 = V_10 ;
} else {
V_10 = V_8 -> V_11 ;
}
V_10 -> V_156 = V_8 -> V_156 ;
V_10 -> V_7 = V_8 ;
V_10 -> V_64 = V_8 -> V_10 ;
V_10 -> V_157 = V_158 ;
return V_10 ;
}
int F_110 ( struct V_16 * V_34 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_44 = F_111 ( V_34 , V_8 ) ;
if ( V_44 != V_150 )
return V_44 ;
V_10 = F_108 ( V_34 , V_8 ) ;
if ( F_23 ( ! V_10 ) )
return V_148 ;
if ( V_8 -> V_155 ) {
int V_44 ;
F_69 ( ! V_8 -> V_147 ) ;
V_44 = F_102 ( V_10 , V_153 ) ;
if ( F_23 ( V_44 ) )
return V_44 ;
} else {
F_69 ( F_101 ( V_8 ) ) ;
memset ( & V_10 -> V_100 , 0 , sizeof( V_10 -> V_100 ) ) ;
V_8 -> V_36 = NULL ;
}
V_10 -> V_48 = V_8 -> V_48 ;
if ( ! F_101 ( V_8 ) )
V_10 -> V_159 = V_160 ;
else if ( F_112 ( V_8 ) == V_161 )
V_10 -> V_159 = V_43 ;
else
V_10 -> V_159 = V_162 ;
V_10 -> V_163 = F_101 ( V_8 ) ;
V_10 -> V_164 = V_8 -> V_40 ;
return V_150 ;
}
int F_113 ( struct V_16 * V_34 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_44 = F_111 ( V_34 , V_8 ) ;
if ( V_44 != V_150 )
return V_44 ;
if ( F_23 ( V_34 -> V_165 && V_34 -> V_165 -> V_166
&& V_34 -> V_165 -> V_166 -> V_167 ) ) {
V_44 = V_34 -> V_165 -> V_166 -> V_167 ( V_34 , V_8 ) ;
if ( V_44 != V_150 )
return V_44 ;
}
F_69 ( ! V_8 -> V_147 ) ;
V_10 = F_108 ( V_34 , V_8 ) ;
if ( F_23 ( ! V_10 ) )
return V_148 ;
memset ( V_10 -> V_64 , 0 , V_168 ) ;
return F_102 ( V_10 , V_153 ) ;
}
int F_111 ( struct V_16 * V_34 , struct V_7 * V_8 )
{
int V_44 = V_150 ;
if ( F_23 ( V_34 -> V_169 != V_170 ) ) {
switch ( V_34 -> V_169 ) {
case V_171 :
case V_172 :
F_114 ( V_173 , V_34 ,
L_15 ) ;
V_44 = V_174 ;
break;
case V_175 :
F_114 ( V_173 , V_34 ,
L_16 ) ;
V_44 = V_174 ;
break;
case V_176 :
case V_177 :
case V_178 :
if ( ! ( V_8 -> V_52 & V_54 ) )
V_44 = V_148 ;
break;
default:
if ( ! ( V_8 -> V_52 & V_54 ) )
V_44 = V_174 ;
break;
}
}
return V_44 ;
}
int F_115 ( struct V_19 * V_20 , struct V_7 * V_8 , int V_44 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
switch ( V_44 ) {
case V_174 :
V_8 -> V_56 = V_179 << 16 ;
if ( V_8 -> V_11 ) {
struct V_9 * V_10 = V_8 -> V_11 ;
F_66 ( V_10 ) ;
F_8 ( V_10 ) ;
V_8 -> V_11 = NULL ;
}
break;
case V_148 :
if ( V_34 -> V_71 == 0 )
F_116 ( V_20 , V_180 ) ;
break;
default:
V_8 -> V_52 |= V_181 ;
}
return V_44 ;
}
int F_117 ( struct V_19 * V_20 , struct V_7 * V_8 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
int V_44 = V_174 ;
if ( V_8 -> V_50 == V_51 )
V_44 = F_110 ( V_34 , V_8 ) ;
return F_115 ( V_20 , V_8 , V_44 ) ;
}
static inline int F_118 ( struct V_19 * V_20 ,
struct V_16 * V_34 )
{
if ( V_34 -> V_71 == 0 && V_34 -> V_27 ) {
if ( -- V_34 -> V_27 == 0 ) {
F_10 ( 3 ,
F_114 ( V_144 , V_34 ,
L_17 ) ) ;
} else {
F_116 ( V_20 , V_180 ) ;
return 0 ;
}
}
if ( F_41 ( V_34 ) )
return 0 ;
return 1 ;
}
static inline int F_119 ( struct V_14 * V_65 ,
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
F_10 ( 3 , F_120 ( V_144 , V_18 ,
L_18 ) ) ;
} else
return 0 ;
}
if ( F_42 ( V_18 ) ) {
F_50 ( & V_34 -> V_83 , & V_65 -> V_79 ) ;
return 0 ;
}
return 1 ;
}
static inline int F_121 ( struct V_19 * V_20 ,
struct V_14 * V_65 ,
struct V_16 * V_34 )
{
if ( F_32 ( V_65 ) )
return 0 ;
if ( V_65 -> V_67 == 0 && V_65 -> V_23 ) {
if ( -- V_65 -> V_23 == 0 ) {
F_10 ( 3 ,
F_11 ( L_19 ,
V_65 -> V_182 ) ) ;
} else {
return 0 ;
}
}
if ( F_43 ( V_65 ) ) {
if ( F_47 ( & V_34 -> V_83 ) )
F_122 ( & V_34 -> V_83 , & V_65 -> V_79 ) ;
return 0 ;
}
if ( ! F_47 ( & V_34 -> V_83 ) )
F_49 ( & V_34 -> V_83 ) ;
return 1 ;
}
static int F_123 ( struct V_19 * V_20 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
struct V_14 * V_65 ;
if ( F_124 ( V_20 ) )
return 0 ;
V_65 = V_34 -> V_15 ;
if ( F_32 ( V_65 ) || F_41 ( V_34 ) )
return 1 ;
return 0 ;
}
static void F_125 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_16 * V_34 ;
struct V_17 * V_18 ;
struct V_14 * V_65 ;
F_126 ( V_8 ) ;
F_94 ( V_144 , V_10 , L_20 ) ;
V_34 = V_10 -> V_1 ;
V_18 = V_17 ( V_34 ) ;
V_65 = V_34 -> V_15 ;
F_29 ( V_10 ) ;
V_10 -> V_59 = V_179 << 16 ;
F_127 ( & V_10 -> V_1 -> V_183 ) ;
V_34 -> V_71 ++ ;
F_34 ( V_34 -> V_19 -> V_32 ) ;
F_35 ( V_65 -> V_66 ) ;
V_65 -> V_67 ++ ;
V_18 -> V_68 ++ ;
F_34 ( V_65 -> V_66 ) ;
F_35 ( V_34 -> V_19 -> V_32 ) ;
F_128 ( V_8 ) ;
}
static void F_129 ( struct V_7 * V_151 )
{
struct V_9 * V_10 = V_151 -> V_11 ;
unsigned long V_184 = ( V_10 -> V_164 + 1 ) * V_151 -> V_39 ;
int V_185 ;
F_130 ( & V_10 -> V_186 ) ;
F_127 ( & V_10 -> V_1 -> V_187 ) ;
if ( V_10 -> V_59 )
F_127 ( & V_10 -> V_1 -> V_188 ) ;
V_185 = F_131 ( V_10 ) ;
if ( V_185 != V_189 &&
F_132 ( V_10 -> V_190 + V_184 , V_191 ) ) {
F_114 ( V_173 , V_10 -> V_1 ,
L_21 ,
V_184 / V_192 ) ;
V_185 = V_189 ;
}
F_133 ( V_10 , V_185 ) ;
switch ( V_185 ) {
case V_189 :
F_134 ( V_10 ) ;
break;
case V_193 :
F_17 ( V_10 , V_26 ) ;
break;
case V_194 :
F_17 ( V_10 , V_25 ) ;
break;
default:
if ( ! F_135 ( V_10 , 0 ) )
F_134 ( V_10 ) ;
}
}
static void F_136 ( struct V_19 * V_20 )
{
struct V_16 * V_34 = V_20 -> V_78 ;
struct V_14 * V_65 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
if( ! F_57 ( & V_34 -> V_86 ) )
return;
V_65 = V_34 -> V_15 ;
for (; ; ) {
int V_195 ;
V_8 = F_137 ( V_20 ) ;
if ( ! V_8 || ! F_118 ( V_20 , V_34 ) )
break;
if ( F_23 ( ! F_138 ( V_34 ) ) ) {
F_114 ( V_173 , V_34 ,
L_15 ) ;
F_125 ( V_8 , V_20 ) ;
continue;
}
if ( ! ( F_139 ( V_20 ) && ! F_140 ( V_20 , V_8 ) ) )
F_126 ( V_8 ) ;
V_34 -> V_71 ++ ;
F_34 ( V_20 -> V_32 ) ;
V_10 = V_8 -> V_11 ;
if ( F_23 ( V_10 == NULL ) ) {
F_11 ( V_196 L_22
L_23
L_24 ,
V_197 ) ;
F_141 ( V_8 , L_25 ) ;
F_142 () ;
}
F_35 ( V_65 -> V_66 ) ;
if ( F_139 ( V_20 ) && ! F_143 ( V_8 ) ) {
if ( F_47 ( & V_34 -> V_83 ) )
F_122 ( & V_34 -> V_83 ,
& V_65 -> V_79 ) ;
goto V_198;
}
if ( ! F_119 ( V_65 , V_34 ) )
goto V_198;
if ( ! F_121 ( V_20 , V_65 , V_34 ) )
goto V_198;
V_17 ( V_34 ) -> V_68 ++ ;
V_65 -> V_67 ++ ;
F_144 ( V_65 -> V_66 ) ;
F_29 ( V_10 ) ;
V_195 = F_145 ( V_10 ) ;
F_146 ( V_20 -> V_32 ) ;
if ( V_195 )
goto V_199;
}
goto V_47;
V_198:
F_144 ( V_65 -> V_66 ) ;
F_146 ( V_20 -> V_32 ) ;
F_14 ( V_20 , V_8 ) ;
V_34 -> V_71 -- ;
V_199:
if ( V_34 -> V_71 == 0 )
F_116 ( V_20 , V_180 ) ;
V_47:
F_144 ( V_20 -> V_32 ) ;
F_58 ( & V_34 -> V_86 ) ;
F_146 ( V_20 -> V_32 ) ;
}
T_2 F_147 ( struct V_14 * V_65 )
{
struct V_1 * V_200 ;
T_2 V_201 = 0xffffffff ;
if ( V_65 -> V_202 )
return V_203 ;
if ( ! V_204 )
return V_205 ;
V_200 = F_148 ( V_65 ) ;
if ( V_200 && V_200 -> V_206 )
V_201 = * V_200 -> V_206 ;
return V_201 ;
}
struct V_19 * F_149 ( struct V_14 * V_65 ,
T_3 * V_207 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_65 -> V_208 ;
V_20 = F_150 ( V_207 , NULL ) ;
if ( ! V_20 )
return NULL ;
F_151 ( V_20 , F_152 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_153 ( V_65 ) ) {
V_65 -> V_209 =
F_154 ( V_65 -> V_209 ,
( unsigned short ) V_210 ) ;
F_69 ( V_65 -> V_209 < V_65 -> V_211 ) ;
F_155 ( V_20 , V_65 -> V_209 ) ;
}
F_156 ( V_20 , V_65 -> V_212 ) ;
F_157 ( V_20 , F_147 ( V_65 ) ) ;
F_158 ( V_20 , V_65 -> V_213 ) ;
F_159 ( V_2 , V_65 -> V_213 ) ;
F_160 ( V_20 , F_161 ( V_2 ) ) ;
if ( ! V_65 -> V_214 )
V_20 -> V_215 . V_216 = 0 ;
F_162 ( V_20 , 0x03 ) ;
return V_20 ;
}
struct V_19 * F_163 ( struct V_16 * V_34 )
{
struct V_19 * V_20 ;
V_20 = F_149 ( V_34 -> V_15 , F_136 ) ;
if ( ! V_20 )
return NULL ;
F_164 ( V_20 , F_117 ) ;
F_165 ( V_20 , F_129 ) ;
F_166 ( V_20 , V_217 ) ;
F_167 ( V_20 , F_123 ) ;
return V_20 ;
}
void F_168 ( struct V_14 * V_65 )
{
V_65 -> V_77 = 1 ;
}
void F_169 ( struct V_14 * V_65 )
{
V_65 -> V_77 = 0 ;
F_60 ( V_65 ) ;
}
int T_4 F_170 ( void )
{
int V_218 ;
V_105 = F_171 ( L_26 ,
sizeof( struct V_99 ) ,
0 , 0 , NULL ) ;
if ( ! V_105 ) {
F_11 ( V_173 L_27 ) ;
return - V_219 ;
}
for ( V_218 = 0 ; V_218 < V_220 ; V_218 ++ ) {
struct V_94 * V_95 = V_96 + V_218 ;
int V_221 = V_95 -> V_221 * sizeof( struct V_92 ) ;
V_95 -> V_222 = F_171 ( V_95 -> V_223 , V_221 , 0 ,
V_224 , NULL ) ;
if ( ! V_95 -> V_222 ) {
F_11 ( V_173 L_28 ,
V_95 -> V_223 ) ;
goto V_225;
}
V_95 -> V_97 = F_172 ( V_226 ,
V_95 -> V_222 ) ;
if ( ! V_95 -> V_97 ) {
F_11 ( V_173 L_29 ,
V_95 -> V_223 ) ;
goto V_225;
}
}
return 0 ;
V_225:
for ( V_218 = 0 ; V_218 < V_220 ; V_218 ++ ) {
struct V_94 * V_95 = V_96 + V_218 ;
if ( V_95 -> V_97 )
F_173 ( V_95 -> V_97 ) ;
if ( V_95 -> V_222 )
F_174 ( V_95 -> V_222 ) ;
}
F_174 ( V_105 ) ;
return - V_219 ;
}
void F_175 ( void )
{
int V_218 ;
F_174 ( V_105 ) ;
for ( V_218 = 0 ; V_218 < V_220 ; V_218 ++ ) {
struct V_94 * V_95 = V_96 + V_218 ;
F_173 ( V_95 -> V_97 ) ;
F_174 ( V_95 -> V_222 ) ;
}
}
int
F_176 ( struct V_16 * V_34 , int V_227 , int V_228 , int V_229 ,
unsigned char * V_36 , int V_124 , int V_39 , int V_40 ,
struct V_230 * V_231 , struct V_57 * V_58 )
{
unsigned char V_10 [ 10 ] ;
unsigned char * V_232 ;
int V_44 ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_10 [ 1 ] = ( V_227 ? 0x10 : 0 ) | ( V_228 ? 0x01 : 0 ) ;
if ( V_34 -> V_233 ) {
if ( V_124 > 65535 )
return - V_234 ;
V_232 = F_177 ( 8 + V_124 , V_235 ) ;
if ( ! V_232 )
return - V_219 ;
memcpy ( V_232 + 8 , V_36 , V_124 ) ;
V_124 += 8 ;
V_232 [ 0 ] = 0 ;
V_232 [ 1 ] = 0 ;
V_232 [ 2 ] = V_231 -> V_236 ;
V_232 [ 3 ] = V_231 -> V_237 ;
V_232 [ 4 ] = V_231 -> V_238 ? 0x01 : 0 ;
V_232 [ 5 ] = 0 ;
V_232 [ 6 ] = V_231 -> V_239 >> 8 ;
V_232 [ 7 ] = V_231 -> V_239 ;
V_10 [ 0 ] = V_240 ;
V_10 [ 7 ] = V_124 >> 8 ;
V_10 [ 8 ] = V_124 ;
} else {
if ( V_124 > 255 || V_231 -> V_239 > 255 ||
V_231 -> V_238 )
return - V_234 ;
V_232 = F_177 ( 4 + V_124 , V_235 ) ;
if ( ! V_232 )
return - V_219 ;
memcpy ( V_232 + 4 , V_36 , V_124 ) ;
V_124 += 4 ;
V_232 [ 0 ] = 0 ;
V_232 [ 1 ] = V_231 -> V_236 ;
V_232 [ 2 ] = V_231 -> V_237 ;
V_232 [ 3 ] = V_231 -> V_239 ;
V_10 [ 0 ] = V_241 ;
V_10 [ 4 ] = V_124 ;
}
V_44 = F_178 ( V_34 , V_10 , V_43 , V_232 , V_124 ,
V_58 , V_39 , V_40 , NULL ) ;
F_28 ( V_232 ) ;
return V_44 ;
}
int
F_179 ( struct V_16 * V_34 , int V_242 , int V_229 ,
unsigned char * V_36 , int V_124 , int V_39 , int V_40 ,
struct V_230 * V_231 , struct V_57 * V_58 )
{
unsigned char V_10 [ 12 ] ;
int V_233 ;
int V_243 ;
int V_59 ;
struct V_57 V_244 ;
memset ( V_231 , 0 , sizeof( * V_231 ) ) ;
memset ( & V_10 [ 0 ] , 0 , 12 ) ;
V_10 [ 1 ] = V_242 & 0x18 ;
V_10 [ 2 ] = V_229 ;
if ( ! V_58 )
V_58 = & V_244 ;
V_245:
V_233 = V_34 -> V_233 ;
if ( V_233 ) {
if ( V_124 < 8 )
V_124 = 8 ;
V_10 [ 0 ] = V_246 ;
V_10 [ 8 ] = V_124 ;
V_243 = 8 ;
} else {
if ( V_124 < 4 )
V_124 = 4 ;
V_10 [ 0 ] = V_247 ;
V_10 [ 4 ] = V_124 ;
V_243 = 4 ;
}
memset ( V_36 , 0 , V_124 ) ;
V_59 = F_178 ( V_34 , V_10 , V_162 , V_36 , V_124 ,
V_58 , V_39 , V_40 , NULL ) ;
if ( V_233 && ! F_180 ( V_59 ) &&
( F_96 ( V_59 ) & V_145 ) ) {
if ( F_181 ( V_58 ) ) {
if ( ( V_58 -> V_125 == V_133 ) &&
( V_58 -> V_127 == 0x20 ) && ( V_58 -> V_128 == 0 ) ) {
V_34 -> V_233 = 0 ;
goto V_245;
}
}
}
if( F_180 ( V_59 ) ) {
if ( F_23 ( V_36 [ 0 ] == 0x86 && V_36 [ 1 ] == 0x0b &&
( V_229 == 6 || V_229 == 8 ) ) ) {
V_243 = 0 ;
V_231 -> V_149 = 13 ;
V_231 -> V_236 = 0 ;
V_231 -> V_237 = 0 ;
V_231 -> V_238 = 0 ;
V_231 -> V_239 = 0 ;
} else if( V_233 ) {
V_231 -> V_149 = V_36 [ 0 ] * 256 + V_36 [ 1 ] + 2 ;
V_231 -> V_236 = V_36 [ 2 ] ;
V_231 -> V_237 = V_36 [ 3 ] ;
V_231 -> V_238 = V_36 [ 4 ] & 0x01 ;
V_231 -> V_239 = V_36 [ 6 ] * 256
+ V_36 [ 7 ] ;
} else {
V_231 -> V_149 = V_36 [ 0 ] + 1 ;
V_231 -> V_236 = V_36 [ 1 ] ;
V_231 -> V_237 = V_36 [ 2 ] ;
V_231 -> V_239 = V_36 [ 3 ] ;
}
V_231 -> V_243 = V_243 ;
}
return V_59 ;
}
int
F_182 ( struct V_16 * V_34 , int V_39 , int V_40 ,
struct V_57 * V_248 )
{
char V_10 [] = {
V_249 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_57 * V_58 ;
int V_59 ;
if ( ! V_248 )
V_58 = F_26 ( sizeof( * V_58 ) , V_235 ) ;
else
V_58 = V_248 ;
do {
V_59 = F_178 ( V_34 , V_10 , V_160 , NULL , 0 , V_58 ,
V_39 , V_40 , NULL ) ;
if ( V_34 -> V_131 && F_181 ( V_58 ) &&
V_58 -> V_125 == V_130 )
V_34 -> V_132 = 1 ;
} while ( F_181 ( V_58 ) &&
V_58 -> V_125 == V_130 && -- V_40 );
if ( ! V_248 )
F_28 ( V_58 ) ;
return V_59 ;
}
int
F_183 ( struct V_16 * V_34 , enum V_250 V_251 )
{
enum V_250 V_252 = V_34 -> V_169 ;
if ( V_251 == V_252 )
return 0 ;
switch ( V_251 ) {
case V_253 :
switch ( V_252 ) {
case V_178 :
break;
default:
goto V_254;
}
break;
case V_170 :
switch ( V_252 ) {
case V_253 :
case V_171 :
case V_172 :
case V_176 :
case V_177 :
break;
default:
goto V_254;
}
break;
case V_176 :
switch ( V_252 ) {
case V_170 :
case V_171 :
case V_172 :
break;
default:
goto V_254;
}
break;
case V_171 :
case V_172 :
switch ( V_252 ) {
case V_253 :
case V_170 :
case V_176 :
case V_177 :
break;
default:
goto V_254;
}
break;
case V_177 :
switch ( V_252 ) {
case V_170 :
case V_178 :
break;
default:
goto V_254;
}
break;
case V_178 :
switch ( V_252 ) {
case V_253 :
break;
default:
goto V_254;
}
break;
case V_255 :
switch ( V_252 ) {
case V_253 :
case V_170 :
case V_176 :
case V_171 :
case V_172 :
case V_177 :
break;
default:
goto V_254;
}
break;
case V_175 :
switch ( V_252 ) {
case V_253 :
case V_170 :
case V_171 :
case V_172 :
case V_255 :
case V_178 :
break;
default:
goto V_254;
}
break;
}
V_34 -> V_169 = V_251 ;
return 0 ;
V_254:
F_184 ( 1 ,
F_114 ( V_173 , V_34 ,
L_30 ,
F_185 ( V_252 ) ,
F_185 ( V_251 ) )
) ;
return - V_234 ;
}
static void F_186 ( struct V_16 * V_34 , struct V_256 * V_257 )
{
int V_258 = 0 ;
char * V_259 [ 3 ] ;
switch ( V_257 -> V_260 ) {
case V_261 :
V_259 [ V_258 ++ ] = L_31 ;
break;
default:
break;
}
V_259 [ V_258 ++ ] = NULL ;
F_187 ( & V_34 -> V_86 . V_262 , V_263 , V_259 ) ;
}
void F_188 ( struct V_84 * V_85 )
{
struct V_16 * V_34 ;
F_45 ( V_264 ) ;
V_34 = F_55 ( V_85 , struct V_16 , V_265 ) ;
while ( 1 ) {
struct V_256 * V_257 ;
struct V_266 * V_267 , * V_73 ;
unsigned long V_21 ;
F_13 ( & V_34 -> V_268 , V_21 ) ;
F_46 ( & V_34 -> V_264 , & V_264 ) ;
F_16 ( & V_34 -> V_268 , V_21 ) ;
if ( F_47 ( & V_264 ) )
break;
F_189 (this, tmp, &event_list) {
V_257 = F_48 ( V_267 , struct V_256 , V_269 ) ;
F_190 ( & V_257 -> V_269 ) ;
F_186 ( V_34 , V_257 ) ;
F_28 ( V_257 ) ;
}
}
}
void F_191 ( struct V_16 * V_34 , struct V_256 * V_257 )
{
unsigned long V_21 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_13 ( & V_34 -> V_268 , V_21 ) ;
F_122 ( & V_257 -> V_269 , & V_34 -> V_264 ) ;
F_192 ( & V_34 -> V_265 ) ;
F_16 ( & V_34 -> V_268 , V_21 ) ;
}
struct V_256 * F_193 ( enum V_270 V_260 ,
T_1 V_271 )
{
struct V_256 * V_257 = F_26 ( sizeof( struct V_256 ) , V_271 ) ;
if ( ! V_257 )
return NULL ;
V_257 -> V_260 = V_260 ;
F_130 ( & V_257 -> V_269 ) ;
switch ( V_260 ) {
case V_261 :
default:
break;
}
return V_257 ;
}
void F_194 ( struct V_16 * V_34 ,
enum V_270 V_260 , T_1 V_271 )
{
struct V_256 * V_257 = F_193 ( V_260 , V_271 ) ;
if ( ! V_257 ) {
F_114 ( V_173 , V_34 , L_32 ,
V_260 ) ;
return;
}
F_191 ( V_34 , V_257 ) ;
}
int
F_195 ( struct V_16 * V_34 )
{
int V_272 = F_183 ( V_34 , V_176 ) ;
if ( V_272 )
return V_272 ;
F_44 ( V_34 -> V_19 ) ;
while ( V_34 -> V_71 ) {
F_196 ( 200 ) ;
F_44 ( V_34 -> V_19 ) ;
}
return 0 ;
}
void F_197 ( struct V_16 * V_34 )
{
if ( V_34 -> V_169 != V_176 ||
F_183 ( V_34 , V_170 ) )
return;
F_44 ( V_34 -> V_19 ) ;
}
static void
F_198 ( struct V_16 * V_34 , void * V_231 )
{
F_195 ( V_34 ) ;
}
void
F_199 ( struct V_17 * V_18 )
{
F_200 ( V_18 , NULL , F_198 ) ;
}
static void
F_201 ( struct V_16 * V_34 , void * V_231 )
{
F_197 ( V_34 ) ;
}
void
F_202 ( struct V_17 * V_18 )
{
F_200 ( V_18 , NULL , F_201 ) ;
}
int
F_203 ( struct V_16 * V_34 )
{
struct V_19 * V_20 = V_34 -> V_19 ;
unsigned long V_21 ;
int V_272 = 0 ;
V_272 = F_183 ( V_34 , V_177 ) ;
if ( V_272 ) {
V_272 = F_183 ( V_34 , V_178 ) ;
if ( V_272 )
return V_272 ;
}
F_13 ( V_20 -> V_32 , V_21 ) ;
F_204 ( V_20 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
return 0 ;
}
int
F_205 ( struct V_16 * V_34 ,
enum V_250 V_273 )
{
struct V_19 * V_20 = V_34 -> V_19 ;
unsigned long V_21 ;
if ( ( V_34 -> V_169 == V_177 ) ||
( V_34 -> V_169 == V_172 ) )
V_34 -> V_169 = V_273 ;
else if ( V_34 -> V_169 == V_178 ) {
if ( V_273 == V_172 ||
V_273 == V_171 )
V_34 -> V_169 = V_273 ;
else
V_34 -> V_169 = V_253 ;
} else if ( V_34 -> V_169 != V_255 &&
V_34 -> V_169 != V_171 )
return - V_234 ;
F_13 ( V_20 -> V_32 , V_21 ) ;
F_206 ( V_20 ) ;
F_16 ( V_20 -> V_32 , V_21 ) ;
return 0 ;
}
static void
F_207 ( struct V_16 * V_34 , void * V_231 )
{
F_203 ( V_34 ) ;
}
static int
F_208 ( struct V_1 * V_2 , void * V_231 )
{
if ( F_209 ( V_2 ) )
F_200 ( F_210 ( V_2 ) , NULL ,
F_207 ) ;
return 0 ;
}
void
F_211 ( struct V_1 * V_2 )
{
if ( F_209 ( V_2 ) )
F_200 ( F_210 ( V_2 ) , NULL ,
F_207 ) ;
else
F_212 ( V_2 , NULL , F_208 ) ;
}
static void
F_213 ( struct V_16 * V_34 , void * V_231 )
{
F_205 ( V_34 , * (enum V_250 * ) V_231 ) ;
}
static int
F_214 ( struct V_1 * V_2 , void * V_231 )
{
if ( F_209 ( V_2 ) )
F_200 ( F_210 ( V_2 ) , V_231 ,
F_213 ) ;
return 0 ;
}
void
F_215 ( struct V_1 * V_2 , enum V_250 V_273 )
{
if ( F_209 ( V_2 ) )
F_200 ( F_210 ( V_2 ) , & V_273 ,
F_213 ) ;
else
F_212 ( V_2 , & V_273 , F_214 ) ;
}
void * F_216 ( struct V_92 * V_93 , int V_274 ,
T_5 * V_275 , T_5 * V_124 )
{
int V_218 ;
T_5 V_276 = 0 , V_277 = 0 ;
struct V_92 * V_278 ;
struct V_279 * V_279 ;
F_217 ( ! F_218 () ) ;
F_219 (sgl, sg, sg_count, i) {
V_277 = V_276 ;
V_276 += V_278 -> V_149 ;
if ( V_276 > * V_275 )
break;
}
if ( F_23 ( V_218 == V_274 ) ) {
F_11 ( V_173 L_33
L_34 ,
V_197 , V_276 , * V_275 , V_274 ) ;
F_217 ( 1 ) ;
return NULL ;
}
* V_275 = * V_275 - V_277 + V_278 -> V_275 ;
V_279 = F_220 ( F_221 ( V_278 ) , ( * V_275 >> V_280 ) ) ;
* V_275 &= ~ V_281 ;
V_276 = V_282 - * V_275 ;
if ( * V_124 > V_276 )
* V_124 = V_276 ;
return F_222 ( V_279 ) ;
}
void F_223 ( void * V_283 )
{
F_224 ( V_283 ) ;
}
void F_225 ( struct V_16 * V_34 )
{
F_127 ( & V_34 -> V_284 ) ;
}
void F_226 ( struct V_16 * V_34 )
{
if ( F_227 ( F_228 ( & V_34 -> V_284 ) <= 0 ) )
return;
F_229 ( & V_34 -> V_284 ) ;
}
