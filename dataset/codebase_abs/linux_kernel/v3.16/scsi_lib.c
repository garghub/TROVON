static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
struct V_8 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = V_9 ( V_7 ) ;
struct V_11 * V_12 = V_7 -> V_11 ;
unsigned long V_13 ;
F_2 ( 1 ,
F_3 ( L_1 , V_2 ) ) ;
switch ( V_3 ) {
case V_14 :
V_6 -> V_15 = V_6 -> V_16 ;
break;
case V_17 :
case V_18 :
V_7 -> V_19 = V_7 -> V_20 ;
break;
case V_21 :
V_10 -> V_22 = V_10 -> V_23 ;
break;
}
if ( V_4 )
F_4 ( V_7 ) ;
V_2 -> V_24 = 0 ;
F_5 ( V_12 -> V_25 , V_13 ) ;
F_6 ( V_12 , V_2 -> V_26 ) ;
F_7 ( & V_7 -> V_27 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
}
void F_9 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , 1 ) ;
}
int F_10 ( struct V_8 * V_28 , const unsigned char * V_2 ,
int V_29 , void * V_30 , unsigned V_31 ,
unsigned char * V_32 , int V_33 , int V_34 , T_1 V_13 ,
int * V_35 )
{
struct V_26 * V_36 ;
int V_37 = ( V_29 == V_38 ) ;
int V_39 = V_40 << 24 ;
V_36 = F_11 ( V_28 -> V_11 , V_37 , V_41 ) ;
if ( ! V_36 )
return V_39 ;
F_12 ( V_36 ) ;
if ( V_31 && F_13 ( V_28 -> V_11 , V_36 ,
V_30 , V_31 , V_41 ) )
goto V_42;
V_36 -> V_43 = F_14 ( V_2 [ 0 ] ) ;
memcpy ( V_36 -> V_2 , V_2 , V_36 -> V_43 ) ;
V_36 -> V_32 = V_32 ;
V_36 -> V_44 = 0 ;
V_36 -> V_34 = V_34 ;
V_36 -> V_33 = V_33 ;
V_36 -> V_45 |= V_13 | V_46 | V_47 ;
F_15 ( V_36 -> V_12 , NULL , V_36 , 1 ) ;
if ( F_16 ( V_36 -> V_48 > 0 && V_36 -> V_48 <= V_31 ) )
memset ( V_30 + ( V_31 - V_36 -> V_48 ) , 0 , V_36 -> V_48 ) ;
if ( V_35 )
* V_35 = V_36 -> V_48 ;
V_39 = V_36 -> V_49 ;
V_42:
F_17 ( V_36 ) ;
return V_39 ;
}
int F_18 ( struct V_8 * V_28 , const unsigned char * V_2 ,
int V_29 , void * V_30 , unsigned V_31 ,
struct V_50 * V_51 , int V_33 , int V_34 ,
int * V_35 , T_1 V_13 )
{
char * V_32 = NULL ;
int V_24 ;
if ( V_51 ) {
V_32 = F_19 ( V_52 , V_53 ) ;
if ( ! V_32 )
return V_40 << 24 ;
}
V_24 = F_10 ( V_28 , V_2 , V_29 , V_30 , V_31 ,
V_32 , V_33 , V_34 , V_13 , V_35 ) ;
if ( V_51 )
F_20 ( V_32 , V_52 , V_51 ) ;
F_21 ( V_32 ) ;
return V_24 ;
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_54 = 0 ;
F_23 ( V_2 , 0 ) ;
memset ( V_2 -> V_55 , 0 , V_52 ) ;
if ( V_2 -> V_43 == 0 )
V_2 -> V_43 = F_24 ( V_2 -> V_56 ) ;
}
void F_4 ( struct V_8 * V_28 )
{
struct V_5 * V_57 = V_28 -> V_6 ;
struct V_9 * V_10 = V_9 ( V_28 ) ;
unsigned long V_13 ;
F_5 ( V_57 -> V_58 , V_13 ) ;
V_57 -> V_59 -- ;
V_10 -> V_60 -- ;
if ( F_16 ( F_25 ( V_57 ) &&
( V_57 -> V_61 || V_57 -> V_62 ) ) )
F_26 ( V_57 ) ;
F_27 ( V_57 -> V_58 ) ;
F_28 ( V_28 -> V_11 -> V_25 ) ;
V_28 -> V_63 -- ;
F_8 ( V_28 -> V_11 -> V_25 , V_13 ) ;
}
static void F_29 ( struct V_8 * V_64 )
{
struct V_5 * V_57 = V_64 -> V_6 ;
struct V_8 * V_28 , * V_65 ;
struct V_9 * V_10 = V_9 ( V_64 ) ;
unsigned long V_13 ;
F_5 ( V_57 -> V_58 , V_13 ) ;
V_10 -> V_66 = NULL ;
F_8 ( V_57 -> V_58 , V_13 ) ;
F_30 ( V_64 -> V_11 ) ;
F_5 ( V_57 -> V_58 , V_13 ) ;
if ( V_10 -> V_66 )
goto V_42;
F_31 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_28 == V_64 )
continue;
if ( F_32 ( V_28 ) )
continue;
F_8 ( V_57 -> V_58 , V_13 ) ;
F_30 ( V_28 -> V_11 ) ;
F_5 ( V_57 -> V_58 , V_13 ) ;
F_33 ( V_28 ) ;
}
V_42:
F_8 ( V_57 -> V_58 , V_13 ) ;
}
static inline int F_34 ( struct V_8 * V_28 )
{
if ( V_28 -> V_63 >= V_28 -> V_67 || V_28 -> V_19 )
return 1 ;
return 0 ;
}
static inline int F_35 ( struct V_9 * V_10 )
{
return ( ( V_10 -> V_68 > 0 &&
V_10 -> V_60 >= V_10 -> V_68 ) ||
V_10 -> V_22 ) ;
}
static inline int F_36 ( struct V_5 * V_57 )
{
if ( ( V_57 -> V_68 > 0 && V_57 -> V_59 >= V_57 -> V_68 ) ||
V_57 -> V_15 || V_57 -> V_69 )
return 1 ;
return 0 ;
}
static void F_37 ( struct V_5 * V_57 )
{
F_38 ( V_70 ) ;
struct V_8 * V_28 ;
unsigned long V_13 ;
F_5 ( V_57 -> V_58 , V_13 ) ;
F_39 ( & V_57 -> V_70 , & V_70 ) ;
while ( ! F_40 ( & V_70 ) ) {
struct V_11 * V_71 ;
if ( F_36 ( V_57 ) )
break;
V_28 = F_41 ( V_70 . V_72 ,
struct V_8 , V_73 ) ;
F_42 ( & V_28 -> V_73 ) ;
if ( F_35 ( V_9 ( V_28 ) ) ) {
F_43 ( & V_28 -> V_73 ,
& V_57 -> V_70 ) ;
continue;
}
V_71 = V_28 -> V_11 ;
if ( ! F_44 ( V_71 ) )
continue;
F_8 ( V_57 -> V_58 , V_13 ) ;
F_30 ( V_71 ) ;
F_45 ( V_71 ) ;
F_5 ( V_57 -> V_58 , V_13 ) ;
}
F_46 ( & V_70 , & V_57 -> V_70 ) ;
F_8 ( V_57 -> V_58 , V_13 ) ;
}
static void F_47 ( struct V_11 * V_12 )
{
struct V_8 * V_28 = V_12 -> V_74 ;
if ( V_9 ( V_28 ) -> V_75 )
F_29 ( V_28 ) ;
if ( ! F_40 ( & V_28 -> V_6 -> V_70 ) )
F_37 ( V_28 -> V_6 ) ;
F_30 ( V_12 ) ;
}
void F_48 ( struct V_76 * V_77 )
{
struct V_8 * V_28 ;
struct V_11 * V_12 ;
V_28 = F_49 ( V_77 , struct V_8 , V_27 ) ;
V_12 = V_28 -> V_11 ;
F_47 ( V_12 ) ;
}
static void F_50 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_8 * V_28 = V_2 -> V_7 ;
struct V_26 * V_36 = V_2 -> V_26 ;
unsigned long V_13 ;
F_5 ( V_12 -> V_25 , V_13 ) ;
F_51 ( V_36 ) ;
V_36 -> V_78 = NULL ;
F_52 ( V_2 ) ;
F_6 ( V_12 , V_36 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
F_47 ( V_12 ) ;
F_53 ( & V_28 -> V_79 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_28 = V_2 -> V_7 ;
struct V_11 * V_12 = V_28 -> V_11 ;
F_52 ( V_2 ) ;
F_47 ( V_12 ) ;
F_53 ( & V_28 -> V_79 ) ;
}
void F_55 ( struct V_5 * V_57 )
{
struct V_8 * V_28 ;
F_56 (sdev, shost)
F_47 ( V_28 -> V_11 ) ;
}
static inline unsigned int F_57 ( unsigned short V_80 )
{
unsigned int V_81 ;
F_58 ( V_80 > V_82 ) ;
if ( V_80 <= 8 )
V_81 = 0 ;
else
V_81 = F_59 ( V_80 ) - 3 ;
return V_81 ;
}
static void F_60 ( struct V_83 * V_84 , unsigned int V_80 )
{
struct V_85 * V_86 ;
V_86 = V_87 + F_57 ( V_80 ) ;
F_61 ( V_84 , V_86 -> V_88 ) ;
}
static struct V_83 * F_62 ( unsigned int V_80 , T_2 V_89 )
{
struct V_85 * V_86 ;
V_86 = V_87 + F_57 ( V_80 ) ;
return F_63 ( V_86 -> V_88 , V_89 ) ;
}
static int F_64 ( struct V_90 * V_91 , int V_80 ,
T_2 V_89 )
{
int V_39 ;
F_58 ( ! V_80 ) ;
V_39 = F_65 ( & V_91 -> V_92 , V_80 , V_82 ,
V_89 , F_62 ) ;
if ( F_16 ( V_39 ) )
F_66 ( & V_91 -> V_92 , V_82 ,
F_60 ) ;
return V_39 ;
}
static void F_67 ( struct V_90 * V_91 )
{
F_66 ( & V_91 -> V_92 , V_82 , F_60 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 . V_92 . V_80 )
F_67 ( & V_2 -> V_91 ) ;
memset ( & V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
if ( F_69 ( V_2 ) )
F_67 ( V_2 -> V_93 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_90 * V_94 = V_2 -> V_26 -> V_95 -> V_78 ;
F_67 ( V_94 ) ;
F_71 ( V_96 , V_94 ) ;
V_2 -> V_26 -> V_95 -> V_78 = NULL ;
}
static int F_72 ( struct V_1 * V_2 , int V_24 )
{
int error = 0 ;
switch( F_73 ( V_24 ) ) {
case V_97 :
error = - V_98 ;
break;
case V_99 :
F_74 ( V_2 , V_100 ) ;
error = - V_101 ;
break;
case V_102 :
F_74 ( V_2 , V_100 ) ;
error = - V_103 ;
break;
case V_104 :
F_74 ( V_2 , V_100 ) ;
error = - V_105 ;
break;
case V_106 :
F_74 ( V_2 , V_100 ) ;
error = - V_107 ;
break;
default:
error = - V_108 ;
break;
}
return error ;
}
void F_75 ( struct V_1 * V_2 , unsigned int V_109 )
{
int V_24 = V_2 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_7 -> V_11 ;
struct V_26 * V_36 = V_2 -> V_26 ;
int error = 0 ;
struct V_50 V_51 ;
int V_110 = 0 ;
int V_111 = 0 ;
enum { V_112 , V_113 , V_114 ,
V_115 } V_116 ;
char * V_117 = NULL ;
unsigned long V_118 = ( V_2 -> V_119 + 1 ) * V_36 -> V_33 ;
if ( V_24 ) {
V_110 = F_76 ( V_2 , & V_51 ) ;
if ( V_110 )
V_111 = F_77 ( & V_51 ) ;
}
if ( V_36 -> V_120 == V_121 ) {
if ( V_24 ) {
if ( V_110 && V_36 -> V_32 ) {
int V_122 = 8 + V_2 -> V_55 [ 7 ] ;
if ( V_122 > V_52 )
V_122 = V_52 ;
memcpy ( V_36 -> V_32 , V_2 -> V_55 , V_122 ) ;
V_36 -> V_44 = V_122 ;
}
if ( ! V_111 )
error = F_72 ( V_2 , V_24 ) ;
}
V_36 -> V_49 = V_2 -> V_24 ;
V_36 -> V_48 = F_78 ( V_2 ) ;
if ( F_79 ( V_2 ) ) {
V_36 -> V_95 -> V_48 = F_80 ( V_2 ) -> V_35 ;
F_68 ( V_2 ) ;
F_70 ( V_2 ) ;
F_81 ( V_36 , 0 ) ;
F_54 ( V_2 ) ;
return;
}
} else if ( F_82 ( V_36 ) == 0 && V_24 && ! V_111 ) {
error = F_72 ( V_2 , V_24 ) ;
}
F_58 ( F_83 ( V_36 ) ) ;
F_84 ( 1 , F_3 ( L_2
L_3 ,
F_85 ( V_36 ) , V_109 ) ) ;
if ( V_110 && ( V_51 . V_123 == V_124 ) ) {
if ( ( V_51 . V_125 == 0x0 ) && ( V_51 . V_126 == 0x1d ) )
;
else if ( ! ( V_36 -> V_45 & V_46 ) )
F_86 ( L_4 , V_2 ) ;
V_24 = 0 ;
error = 0 ;
}
if ( ! F_87 ( V_36 , error , V_109 ) )
goto V_127;
if ( error && F_88 ( V_2 ) ) {
F_81 ( V_36 , error ) ;
goto V_127;
}
if ( V_24 == 0 )
goto V_128;
error = F_72 ( V_2 , V_24 ) ;
if ( F_73 ( V_24 ) == V_129 ) {
V_116 = V_114 ;
} else if ( V_110 && ! V_111 ) {
switch ( V_51 . V_123 ) {
case V_130 :
if ( V_2 -> V_7 -> V_131 ) {
V_2 -> V_7 -> V_132 = 1 ;
V_117 = L_5 ;
V_116 = V_112 ;
} else {
V_116 = V_114 ;
}
break;
case V_133 :
if ( ( V_2 -> V_7 -> V_134 &&
V_51 . V_125 == 0x20 && V_51 . V_126 == 0x00 ) &&
( V_2 -> V_56 [ 0 ] == V_135 ||
V_2 -> V_56 [ 0 ] == V_136 ) ) {
V_2 -> V_7 -> V_134 = 0 ;
V_116 = V_113 ;
} else if ( V_51 . V_125 == 0x10 ) {
V_117 = L_6 ;
V_116 = V_112 ;
error = - V_137 ;
} else if ( V_51 . V_125 == 0x20 || V_51 . V_125 == 0x24 ) {
switch ( V_2 -> V_56 [ 0 ] ) {
case V_138 :
V_117 = L_7 ;
break;
case V_139 :
case V_140 :
if ( V_2 -> V_56 [ 1 ] & 0x8 )
V_117 = L_7 ;
else
V_117 =
L_8 ;
break;
default:
V_117 = L_9 ;
break;
}
V_116 = V_112 ;
error = - V_101 ;
} else
V_116 = V_112 ;
break;
case V_141 :
V_116 = V_112 ;
if ( V_51 . V_125 == 0x10 ) {
V_117 = L_10 ;
error = - V_137 ;
}
break;
case V_142 :
if ( V_51 . V_125 == 0x04 ) {
switch ( V_51 . V_126 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_116 = V_115 ;
break;
default:
V_117 = L_11 ;
V_116 = V_112 ;
break;
}
} else {
V_117 = L_11 ;
V_116 = V_112 ;
}
break;
case V_143 :
V_116 = V_112 ;
break;
default:
V_117 = L_12 ;
V_116 = V_112 ;
break;
}
} else {
V_117 = L_13 ;
V_116 = V_112 ;
}
if ( V_116 != V_112 &&
F_89 ( V_2 -> V_144 + V_118 , V_145 ) ) {
V_116 = V_112 ;
V_117 = L_14 ;
}
switch ( V_116 ) {
case V_112 :
if ( ! ( V_36 -> V_45 & V_46 ) ) {
if ( V_117 )
F_90 ( V_146 , V_2 , L_15 ,
V_117 ) ;
F_91 ( V_2 ) ;
if ( F_92 ( V_24 ) & V_147 )
F_86 ( L_4 , V_2 ) ;
F_93 ( V_2 ) ;
}
if ( ! F_94 ( V_36 , error ) )
goto V_127;
case V_113 :
V_128:
F_68 ( V_2 ) ;
F_50 ( V_12 , V_2 ) ;
break;
case V_114 :
F_1 ( V_2 , V_18 , 0 ) ;
break;
case V_115 :
F_1 ( V_2 , V_17 , 0 ) ;
break;
}
return;
V_127:
F_68 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_95 ( struct V_26 * V_36 , struct V_90 * V_91 ,
T_2 V_89 )
{
int V_148 ;
if ( F_16 ( F_64 ( V_91 , V_36 -> V_149 ,
V_89 ) ) ) {
return V_150 ;
}
V_148 = F_96 ( V_36 -> V_12 , V_36 , V_91 -> V_92 . V_84 ) ;
F_58 ( V_148 > V_91 -> V_92 . V_80 ) ;
V_91 -> V_92 . V_80 = V_148 ;
V_91 -> V_151 = F_82 ( V_36 ) ;
return V_152 ;
}
int F_97 ( struct V_1 * V_2 , T_2 V_89 )
{
struct V_8 * V_28 = V_2 -> V_7 ;
struct V_26 * V_153 = V_2 -> V_26 ;
int error = F_95 ( V_153 , & V_2 -> V_91 , V_89 ) ;
if ( error )
goto V_154;
if ( F_83 ( V_153 ) ) {
struct V_90 * V_94 = F_98 (
V_96 , V_155 ) ;
if ( ! V_94 ) {
error = V_150 ;
goto V_154;
}
V_153 -> V_95 -> V_78 = V_94 ;
error = F_95 ( V_153 -> V_95 , V_94 , V_155 ) ;
if ( error )
goto V_154;
}
if ( F_99 ( V_153 ) ) {
struct V_90 * V_93 = V_2 -> V_93 ;
int V_156 , V_148 ;
F_58 ( V_93 == NULL ) ;
V_156 = F_100 ( V_153 -> V_12 , V_153 -> V_157 ) ;
if ( F_64 ( V_93 , V_156 , V_89 ) ) {
error = V_150 ;
goto V_154;
}
V_148 = F_101 ( V_153 -> V_12 , V_153 -> V_157 ,
V_93 -> V_92 . V_84 ) ;
F_58 ( F_16 ( V_148 > V_156 ) ) ;
F_58 ( F_16 ( V_148 > F_102 ( V_153 -> V_12 ) ) ) ;
V_2 -> V_93 = V_93 ;
V_2 -> V_93 -> V_92 . V_80 = V_148 ;
}
return V_152 ;
V_154:
F_68 ( V_2 ) ;
V_2 -> V_26 -> V_78 = NULL ;
F_52 ( V_2 ) ;
F_53 ( & V_28 -> V_79 ) ;
return error ;
}
static struct V_1 * F_103 ( struct V_8 * V_28 ,
struct V_26 * V_36 )
{
struct V_1 * V_2 ;
if ( ! V_36 -> V_78 ) {
if ( ! F_104 ( & V_28 -> V_79 ) )
return NULL ;
V_2 = F_105 ( V_28 , V_155 ) ;
if ( F_16 ( ! V_2 ) ) {
F_53 ( & V_28 -> V_79 ) ;
return NULL ;
}
V_36 -> V_78 = V_2 ;
} else {
V_2 = V_36 -> V_78 ;
}
V_2 -> V_158 = V_36 -> V_158 ;
V_2 -> V_26 = V_36 ;
V_2 -> V_56 = V_36 -> V_2 ;
V_2 -> V_159 = V_160 ;
return V_2 ;
}
int F_106 ( struct V_8 * V_28 , struct V_26 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_78 ;
if ( V_36 -> V_157 ) {
int V_39 ;
F_58 ( ! V_36 -> V_149 ) ;
V_39 = F_97 ( V_2 , V_155 ) ;
if ( F_16 ( V_39 ) )
return V_39 ;
} else {
F_58 ( F_82 ( V_36 ) ) ;
memset ( & V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
}
V_2 -> V_43 = V_36 -> V_43 ;
if ( ! F_82 ( V_36 ) )
V_2 -> V_161 = V_162 ;
else if ( F_107 ( V_36 ) == V_163 )
V_2 -> V_161 = V_38 ;
else
V_2 -> V_161 = V_164 ;
V_2 -> V_165 = F_82 ( V_36 ) ;
V_2 -> V_119 = V_36 -> V_34 ;
return V_152 ;
}
int F_108 ( struct V_8 * V_28 , struct V_26 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_78 ;
if ( F_16 ( V_28 -> V_166 && V_28 -> V_166 -> V_167
&& V_28 -> V_166 -> V_167 -> V_168 ) ) {
int V_39 = V_28 -> V_166 -> V_167 -> V_168 ( V_28 , V_36 ) ;
if ( V_39 != V_152 )
return V_39 ;
}
F_58 ( ! V_36 -> V_149 ) ;
memset ( V_2 -> V_56 , 0 , V_169 ) ;
return F_97 ( V_2 , V_155 ) ;
}
static int
F_109 ( struct V_8 * V_28 , struct V_26 * V_36 )
{
int V_39 = V_152 ;
if ( F_16 ( V_28 -> V_170 != V_171 ) ) {
switch ( V_28 -> V_170 ) {
case V_172 :
case V_173 :
F_110 ( V_174 , V_28 ,
L_16 ) ;
V_39 = V_175 ;
break;
case V_176 :
F_110 ( V_174 , V_28 ,
L_17 ) ;
V_39 = V_175 ;
break;
case V_177 :
case V_178 :
case V_179 :
if ( ! ( V_36 -> V_45 & V_47 ) )
V_39 = V_150 ;
break;
default:
if ( ! ( V_36 -> V_45 & V_47 ) )
V_39 = V_175 ;
break;
}
}
return V_39 ;
}
static int
F_111 ( struct V_11 * V_12 , struct V_26 * V_36 , int V_39 )
{
struct V_8 * V_28 = V_12 -> V_74 ;
switch ( V_39 ) {
case V_175 :
V_36 -> V_49 = V_180 << 16 ;
if ( V_36 -> V_78 ) {
struct V_1 * V_2 = V_36 -> V_78 ;
F_68 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( & V_28 -> V_79 ) ;
V_36 -> V_78 = NULL ;
}
break;
case V_150 :
if ( V_28 -> V_63 == 0 )
F_112 ( V_12 , V_181 ) ;
break;
default:
V_36 -> V_45 |= V_182 ;
}
return V_39 ;
}
static int F_113 ( struct V_11 * V_12 , struct V_26 * V_36 )
{
struct V_8 * V_28 = V_12 -> V_74 ;
struct V_1 * V_2 ;
int V_39 ;
V_39 = F_109 ( V_28 , V_36 ) ;
if ( V_39 != V_152 )
goto V_42;
V_2 = F_103 ( V_28 , V_36 ) ;
if ( F_16 ( ! V_2 ) ) {
V_39 = V_150 ;
goto V_42;
}
if ( V_36 -> V_120 == V_183 )
V_39 = F_114 ( V_2 ) -> F_115 ( V_2 ) ;
else if ( V_36 -> V_120 == V_121 )
V_39 = F_106 ( V_28 , V_36 ) ;
else
V_39 = V_175 ;
V_42:
return F_111 ( V_12 , V_36 , V_39 ) ;
}
static void F_116 ( struct V_11 * V_12 , struct V_26 * V_36 )
{
if ( V_36 -> V_120 == V_183 ) {
struct V_1 * V_2 = V_36 -> V_78 ;
struct V_184 * V_185 = F_114 ( V_2 ) ;
if ( V_185 -> V_186 )
V_185 -> V_186 ( V_2 ) ;
}
}
static inline int F_117 ( struct V_11 * V_12 ,
struct V_8 * V_28 )
{
if ( V_28 -> V_63 == 0 && V_28 -> V_19 ) {
if ( -- V_28 -> V_19 == 0 ) {
F_2 ( 3 ,
F_110 ( V_146 , V_28 ,
L_18 ) ) ;
} else {
F_112 ( V_12 , V_181 ) ;
return 0 ;
}
}
if ( F_34 ( V_28 ) )
return 0 ;
return 1 ;
}
static inline int F_118 ( struct V_5 * V_57 ,
struct V_8 * V_28 )
{
struct V_9 * V_10 = V_9 ( V_28 ) ;
if ( V_10 -> V_75 ) {
if ( V_10 -> V_66 &&
V_10 -> V_66 != V_28 )
return 0 ;
V_10 -> V_66 = V_28 ;
}
if ( V_10 -> V_60 == 0 && V_10 -> V_22 ) {
if ( -- V_10 -> V_22 == 0 ) {
F_2 ( 3 , F_119 ( V_146 , V_10 ,
L_19 ) ) ;
} else
return 0 ;
}
if ( F_35 ( V_10 ) ) {
F_43 ( & V_28 -> V_73 , & V_57 -> V_70 ) ;
return 0 ;
}
return 1 ;
}
static inline int F_120 ( struct V_11 * V_12 ,
struct V_5 * V_57 ,
struct V_8 * V_28 )
{
if ( F_25 ( V_57 ) )
return 0 ;
if ( V_57 -> V_59 == 0 && V_57 -> V_15 ) {
if ( -- V_57 -> V_15 == 0 ) {
F_2 ( 3 ,
F_3 ( L_20 ,
V_57 -> V_187 ) ) ;
} else {
return 0 ;
}
}
if ( F_36 ( V_57 ) ) {
if ( F_40 ( & V_28 -> V_73 ) )
F_121 ( & V_28 -> V_73 , & V_57 -> V_70 ) ;
return 0 ;
}
if ( ! F_40 ( & V_28 -> V_73 ) )
F_42 ( & V_28 -> V_73 ) ;
return 1 ;
}
static int F_122 ( struct V_11 * V_12 )
{
struct V_8 * V_28 = V_12 -> V_74 ;
struct V_5 * V_57 ;
if ( F_123 ( V_12 ) )
return 0 ;
V_57 = V_28 -> V_6 ;
if ( F_25 ( V_57 ) || F_34 ( V_28 ) )
return 1 ;
return 0 ;
}
static void F_124 ( struct V_26 * V_36 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_36 -> V_78 ;
struct V_8 * V_28 ;
struct V_9 * V_10 ;
struct V_5 * V_57 ;
F_125 ( V_36 ) ;
F_90 ( V_146 , V_2 , L_21 ) ;
V_28 = V_2 -> V_7 ;
V_10 = V_9 ( V_28 ) ;
V_57 = V_28 -> V_6 ;
F_22 ( V_2 ) ;
V_2 -> V_24 = V_180 << 16 ;
F_126 ( & V_2 -> V_7 -> V_188 ) ;
V_28 -> V_63 ++ ;
F_27 ( V_28 -> V_11 -> V_25 ) ;
F_28 ( V_57 -> V_58 ) ;
V_57 -> V_59 ++ ;
V_10 -> V_60 ++ ;
F_27 ( V_57 -> V_58 ) ;
F_28 ( V_28 -> V_11 -> V_25 ) ;
F_127 ( V_36 ) ;
}
static void F_128 ( struct V_26 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_78 ;
unsigned long V_118 = ( V_2 -> V_119 + 1 ) * V_153 -> V_33 ;
int V_189 ;
F_129 ( & V_2 -> V_190 ) ;
F_126 ( & V_2 -> V_7 -> V_191 ) ;
if ( V_2 -> V_24 )
F_126 ( & V_2 -> V_7 -> V_192 ) ;
V_189 = F_130 ( V_2 ) ;
if ( V_189 != V_193 &&
F_89 ( V_2 -> V_144 + V_118 , V_145 ) ) {
F_110 ( V_174 , V_2 -> V_7 ,
L_22 ,
V_118 / V_194 ) ;
V_189 = V_193 ;
}
F_131 ( V_2 , V_189 ) ;
switch ( V_189 ) {
case V_193 :
F_132 ( V_2 ) ;
break;
case V_195 :
F_9 ( V_2 , V_18 ) ;
break;
case V_196 :
F_9 ( V_2 , V_17 ) ;
break;
default:
if ( ! F_133 ( V_2 , 0 ) )
F_132 ( V_2 ) ;
}
}
static void F_134 ( struct V_11 * V_12 )
__releases( V_12 -> V_25 )
__acquires( V_12 -> V_25 )
{
struct V_8 * V_28 = V_12 -> V_74 ;
struct V_5 * V_57 ;
struct V_1 * V_2 ;
struct V_26 * V_36 ;
V_57 = V_28 -> V_6 ;
for (; ; ) {
int V_197 ;
V_36 = F_135 ( V_12 ) ;
if ( ! V_36 || ! F_117 ( V_12 , V_28 ) )
break;
if ( F_16 ( ! F_136 ( V_28 ) ) ) {
F_110 ( V_174 , V_28 ,
L_16 ) ;
F_124 ( V_36 , V_12 ) ;
continue;
}
if ( ! ( F_137 ( V_12 ) && ! F_138 ( V_12 , V_36 ) ) )
F_125 ( V_36 ) ;
V_28 -> V_63 ++ ;
F_27 ( V_12 -> V_25 ) ;
V_2 = V_36 -> V_78 ;
if ( F_16 ( V_2 == NULL ) ) {
F_3 ( V_198 L_23
L_24
L_25 ,
V_199 ) ;
F_139 ( V_36 , L_26 ) ;
F_140 () ;
}
F_28 ( V_57 -> V_58 ) ;
if ( F_137 ( V_12 ) && ! F_141 ( V_36 ) ) {
if ( F_40 ( & V_28 -> V_73 ) )
F_121 ( & V_28 -> V_73 ,
& V_57 -> V_70 ) ;
goto V_200;
}
if ( ! F_118 ( V_57 , V_28 ) )
goto V_200;
if ( ! F_120 ( V_12 , V_57 , V_28 ) )
goto V_200;
V_9 ( V_28 ) -> V_60 ++ ;
V_57 -> V_59 ++ ;
F_142 ( V_57 -> V_58 ) ;
F_22 ( V_2 ) ;
V_197 = F_143 ( V_2 ) ;
F_144 ( V_12 -> V_25 ) ;
if ( V_197 )
goto V_201;
}
return;
V_200:
F_142 ( V_57 -> V_58 ) ;
F_144 ( V_12 -> V_25 ) ;
F_6 ( V_12 , V_36 ) ;
V_28 -> V_63 -- ;
V_201:
if ( V_28 -> V_63 == 0 )
F_112 ( V_12 , V_181 ) ;
}
T_1 F_145 ( struct V_5 * V_57 )
{
struct V_7 * V_202 ;
T_1 V_203 = 0xffffffff ;
if ( V_57 -> V_204 )
return V_205 ;
if ( ! V_206 )
return V_207 ;
V_202 = F_146 ( V_57 ) ;
if ( V_202 && V_202 -> V_208 )
V_203 = ( T_1 ) F_147 ( V_202 ) << V_209 ;
return V_203 ;
}
struct V_11 * F_148 ( struct V_5 * V_57 ,
T_3 * V_210 )
{
struct V_11 * V_12 ;
struct V_7 * V_211 = V_57 -> V_212 ;
V_12 = F_149 ( V_210 , NULL ) ;
if ( ! V_12 )
return NULL ;
F_150 ( V_12 , F_151 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_152 ( V_57 ) ) {
V_57 -> V_213 =
F_153 ( V_57 -> V_213 ,
( unsigned short ) V_214 ) ;
F_58 ( V_57 -> V_213 < V_57 -> V_215 ) ;
F_154 ( V_12 , V_57 -> V_213 ) ;
}
F_155 ( V_12 , V_57 -> V_216 ) ;
F_156 ( V_12 , F_145 ( V_57 ) ) ;
F_157 ( V_12 , V_57 -> V_217 ) ;
F_158 ( V_211 , V_57 -> V_217 ) ;
F_159 ( V_12 , F_160 ( V_211 ) ) ;
if ( ! V_57 -> V_218 )
V_12 -> V_219 . V_220 = 0 ;
F_161 ( V_12 , 0x03 ) ;
return V_12 ;
}
struct V_11 * F_162 ( struct V_8 * V_28 )
{
struct V_11 * V_12 ;
V_12 = F_148 ( V_28 -> V_6 , F_134 ) ;
if ( ! V_12 )
return NULL ;
F_163 ( V_12 , F_113 ) ;
F_164 ( V_12 , F_116 ) ;
F_165 ( V_12 , F_128 ) ;
F_166 ( V_12 , V_221 ) ;
F_167 ( V_12 , F_122 ) ;
return V_12 ;
}
void F_168 ( struct V_5 * V_57 )
{
V_57 -> V_69 = 1 ;
}
void F_169 ( struct V_5 * V_57 )
{
V_57 -> V_69 = 0 ;
F_55 ( V_57 ) ;
}
int T_4 F_170 ( void )
{
int V_222 ;
V_96 = F_171 ( L_27 ,
sizeof( struct V_90 ) ,
0 , 0 , NULL ) ;
if ( ! V_96 ) {
F_3 ( V_174 L_28 ) ;
return - V_223 ;
}
for ( V_222 = 0 ; V_222 < V_224 ; V_222 ++ ) {
struct V_85 * V_86 = V_87 + V_222 ;
int V_225 = V_86 -> V_225 * sizeof( struct V_83 ) ;
V_86 -> V_226 = F_171 ( V_86 -> V_227 , V_225 , 0 ,
V_228 , NULL ) ;
if ( ! V_86 -> V_226 ) {
F_3 ( V_174 L_29 ,
V_86 -> V_227 ) ;
goto V_229;
}
V_86 -> V_88 = F_172 ( V_230 ,
V_86 -> V_226 ) ;
if ( ! V_86 -> V_88 ) {
F_3 ( V_174 L_30 ,
V_86 -> V_227 ) ;
goto V_229;
}
}
return 0 ;
V_229:
for ( V_222 = 0 ; V_222 < V_224 ; V_222 ++ ) {
struct V_85 * V_86 = V_87 + V_222 ;
if ( V_86 -> V_88 )
F_173 ( V_86 -> V_88 ) ;
if ( V_86 -> V_226 )
F_174 ( V_86 -> V_226 ) ;
}
F_174 ( V_96 ) ;
return - V_223 ;
}
void F_175 ( void )
{
int V_222 ;
F_174 ( V_96 ) ;
for ( V_222 = 0 ; V_222 < V_224 ; V_222 ++ ) {
struct V_85 * V_86 = V_87 + V_222 ;
F_173 ( V_86 -> V_88 ) ;
F_174 ( V_86 -> V_226 ) ;
}
}
int
F_176 ( struct V_8 * V_28 , int V_231 , int V_232 , int V_233 ,
unsigned char * V_30 , int V_122 , int V_33 , int V_34 ,
struct V_234 * V_235 , struct V_50 * V_51 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_236 ;
int V_39 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_231 ? 0x10 : 0 ) | ( V_232 ? 0x01 : 0 ) ;
if ( V_28 -> V_237 ) {
if ( V_122 > 65535 )
return - V_238 ;
V_236 = F_177 ( 8 + V_122 , V_239 ) ;
if ( ! V_236 )
return - V_223 ;
memcpy ( V_236 + 8 , V_30 , V_122 ) ;
V_122 += 8 ;
V_236 [ 0 ] = 0 ;
V_236 [ 1 ] = 0 ;
V_236 [ 2 ] = V_235 -> V_240 ;
V_236 [ 3 ] = V_235 -> V_241 ;
V_236 [ 4 ] = V_235 -> V_242 ? 0x01 : 0 ;
V_236 [ 5 ] = 0 ;
V_236 [ 6 ] = V_235 -> V_243 >> 8 ;
V_236 [ 7 ] = V_235 -> V_243 ;
V_2 [ 0 ] = V_244 ;
V_2 [ 7 ] = V_122 >> 8 ;
V_2 [ 8 ] = V_122 ;
} else {
if ( V_122 > 255 || V_235 -> V_243 > 255 ||
V_235 -> V_242 )
return - V_238 ;
V_236 = F_177 ( 4 + V_122 , V_239 ) ;
if ( ! V_236 )
return - V_223 ;
memcpy ( V_236 + 4 , V_30 , V_122 ) ;
V_122 += 4 ;
V_236 [ 0 ] = 0 ;
V_236 [ 1 ] = V_235 -> V_240 ;
V_236 [ 2 ] = V_235 -> V_241 ;
V_236 [ 3 ] = V_235 -> V_243 ;
V_2 [ 0 ] = V_245 ;
V_2 [ 4 ] = V_122 ;
}
V_39 = F_178 ( V_28 , V_2 , V_38 , V_236 , V_122 ,
V_51 , V_33 , V_34 , NULL ) ;
F_21 ( V_236 ) ;
return V_39 ;
}
int
F_179 ( struct V_8 * V_28 , int V_246 , int V_233 ,
unsigned char * V_30 , int V_122 , int V_33 , int V_34 ,
struct V_234 * V_235 , struct V_50 * V_51 )
{
unsigned char V_2 [ 12 ] ;
int V_237 ;
int V_247 ;
int V_24 ;
struct V_50 V_248 ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_246 & 0x18 ;
V_2 [ 2 ] = V_233 ;
if ( ! V_51 )
V_51 = & V_248 ;
V_249:
V_237 = V_28 -> V_237 ;
if ( V_237 ) {
if ( V_122 < 8 )
V_122 = 8 ;
V_2 [ 0 ] = V_250 ;
V_2 [ 8 ] = V_122 ;
V_247 = 8 ;
} else {
if ( V_122 < 4 )
V_122 = 4 ;
V_2 [ 0 ] = V_251 ;
V_2 [ 4 ] = V_122 ;
V_247 = 4 ;
}
memset ( V_30 , 0 , V_122 ) ;
V_24 = F_178 ( V_28 , V_2 , V_164 , V_30 , V_122 ,
V_51 , V_33 , V_34 , NULL ) ;
if ( V_237 && ! F_180 ( V_24 ) &&
( F_92 ( V_24 ) & V_147 ) ) {
if ( F_181 ( V_51 ) ) {
if ( ( V_51 -> V_123 == V_133 ) &&
( V_51 -> V_125 == 0x20 ) && ( V_51 -> V_126 == 0 ) ) {
V_28 -> V_237 = 0 ;
goto V_249;
}
}
}
if( F_180 ( V_24 ) ) {
if ( F_16 ( V_30 [ 0 ] == 0x86 && V_30 [ 1 ] == 0x0b &&
( V_233 == 6 || V_233 == 8 ) ) ) {
V_247 = 0 ;
V_235 -> V_151 = 13 ;
V_235 -> V_240 = 0 ;
V_235 -> V_241 = 0 ;
V_235 -> V_242 = 0 ;
V_235 -> V_243 = 0 ;
} else if( V_237 ) {
V_235 -> V_151 = V_30 [ 0 ] * 256 + V_30 [ 1 ] + 2 ;
V_235 -> V_240 = V_30 [ 2 ] ;
V_235 -> V_241 = V_30 [ 3 ] ;
V_235 -> V_242 = V_30 [ 4 ] & 0x01 ;
V_235 -> V_243 = V_30 [ 6 ] * 256
+ V_30 [ 7 ] ;
} else {
V_235 -> V_151 = V_30 [ 0 ] + 1 ;
V_235 -> V_240 = V_30 [ 1 ] ;
V_235 -> V_241 = V_30 [ 2 ] ;
V_235 -> V_243 = V_30 [ 3 ] ;
}
V_235 -> V_247 = V_247 ;
}
return V_24 ;
}
int
F_182 ( struct V_8 * V_28 , int V_33 , int V_34 ,
struct V_50 * V_252 )
{
char V_2 [] = {
V_253 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_50 * V_51 ;
int V_24 ;
if ( ! V_252 )
V_51 = F_19 ( sizeof( * V_51 ) , V_239 ) ;
else
V_51 = V_252 ;
do {
V_24 = F_178 ( V_28 , V_2 , V_162 , NULL , 0 , V_51 ,
V_33 , V_34 , NULL ) ;
if ( V_28 -> V_131 && F_181 ( V_51 ) &&
V_51 -> V_123 == V_130 )
V_28 -> V_132 = 1 ;
} while ( F_181 ( V_51 ) &&
V_51 -> V_123 == V_130 && -- V_34 );
if ( ! V_252 )
F_21 ( V_51 ) ;
return V_24 ;
}
int
F_183 ( struct V_8 * V_28 , enum V_254 V_255 )
{
enum V_254 V_256 = V_28 -> V_170 ;
if ( V_255 == V_256 )
return 0 ;
switch ( V_255 ) {
case V_257 :
switch ( V_256 ) {
case V_179 :
break;
default:
goto V_258;
}
break;
case V_171 :
switch ( V_256 ) {
case V_257 :
case V_172 :
case V_173 :
case V_177 :
case V_178 :
break;
default:
goto V_258;
}
break;
case V_177 :
switch ( V_256 ) {
case V_171 :
case V_172 :
case V_173 :
break;
default:
goto V_258;
}
break;
case V_172 :
case V_173 :
switch ( V_256 ) {
case V_257 :
case V_171 :
case V_177 :
case V_178 :
break;
default:
goto V_258;
}
break;
case V_178 :
switch ( V_256 ) {
case V_171 :
case V_179 :
break;
default:
goto V_258;
}
break;
case V_179 :
switch ( V_256 ) {
case V_257 :
break;
default:
goto V_258;
}
break;
case V_259 :
switch ( V_256 ) {
case V_257 :
case V_171 :
case V_177 :
case V_172 :
case V_173 :
case V_178 :
break;
default:
goto V_258;
}
break;
case V_176 :
switch ( V_256 ) {
case V_257 :
case V_171 :
case V_172 :
case V_173 :
case V_259 :
case V_179 :
break;
default:
goto V_258;
}
break;
}
V_28 -> V_170 = V_255 ;
return 0 ;
V_258:
F_184 ( 1 ,
F_110 ( V_174 , V_28 ,
L_31 ,
F_185 ( V_256 ) ,
F_185 ( V_255 ) )
) ;
return - V_238 ;
}
static void F_186 ( struct V_8 * V_28 , struct V_260 * V_261 )
{
int V_262 = 0 ;
char * V_263 [ 3 ] ;
switch ( V_261 -> V_264 ) {
case V_265 :
V_263 [ V_262 ++ ] = L_32 ;
break;
case V_266 :
V_263 [ V_262 ++ ] = L_33 ;
break;
case V_267 :
V_263 [ V_262 ++ ] = L_34 ;
break;
case V_268 :
V_263 [ V_262 ++ ] = L_35 ;
break;
case V_269 :
V_263 [ V_262 ++ ] = L_36 ;
break;
case V_270 :
V_263 [ V_262 ++ ] = L_37 ;
break;
default:
break;
}
V_263 [ V_262 ++ ] = NULL ;
F_187 ( & V_28 -> V_79 . V_271 , V_272 , V_263 ) ;
}
void F_188 ( struct V_76 * V_77 )
{
struct V_8 * V_28 ;
enum V_273 V_264 ;
F_38 ( V_274 ) ;
V_28 = F_49 ( V_77 , struct V_8 , V_275 ) ;
for ( V_264 = V_276 ; V_264 <= V_277 ; V_264 ++ )
if ( F_189 ( V_264 , V_28 -> V_278 ) )
F_190 ( V_28 , V_264 , V_239 ) ;
while ( 1 ) {
struct V_260 * V_261 ;
struct V_279 * V_280 , * V_65 ;
unsigned long V_13 ;
F_5 ( & V_28 -> V_281 , V_13 ) ;
F_39 ( & V_28 -> V_274 , & V_274 ) ;
F_8 ( & V_28 -> V_281 , V_13 ) ;
if ( F_40 ( & V_274 ) )
break;
F_191 (this, tmp, &event_list) {
V_261 = F_41 ( V_280 , struct V_260 , V_282 ) ;
F_192 ( & V_261 -> V_282 ) ;
F_186 ( V_28 , V_261 ) ;
F_21 ( V_261 ) ;
}
}
}
void F_193 ( struct V_8 * V_28 , struct V_260 * V_261 )
{
unsigned long V_13 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_5 ( & V_28 -> V_281 , V_13 ) ;
F_121 ( & V_261 -> V_282 , & V_28 -> V_274 ) ;
F_194 ( & V_28 -> V_275 ) ;
F_8 ( & V_28 -> V_281 , V_13 ) ;
}
struct V_260 * F_195 ( enum V_273 V_264 ,
T_2 V_283 )
{
struct V_260 * V_261 = F_19 ( sizeof( struct V_260 ) , V_283 ) ;
if ( ! V_261 )
return NULL ;
V_261 -> V_264 = V_264 ;
F_129 ( & V_261 -> V_282 ) ;
switch ( V_264 ) {
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
default:
break;
}
return V_261 ;
}
void F_190 ( struct V_8 * V_28 ,
enum V_273 V_264 , T_2 V_283 )
{
struct V_260 * V_261 = F_195 ( V_264 , V_283 ) ;
if ( ! V_261 ) {
F_110 ( V_174 , V_28 , L_38 ,
V_264 ) ;
return;
}
F_193 ( V_28 , V_261 ) ;
}
int
F_196 ( struct V_8 * V_28 )
{
int V_284 = F_183 ( V_28 , V_177 ) ;
if ( V_284 )
return V_284 ;
F_47 ( V_28 -> V_11 ) ;
while ( V_28 -> V_63 ) {
F_197 ( 200 ) ;
F_47 ( V_28 -> V_11 ) ;
}
return 0 ;
}
void F_198 ( struct V_8 * V_28 )
{
if ( V_28 -> V_170 != V_177 ||
F_183 ( V_28 , V_171 ) )
return;
F_47 ( V_28 -> V_11 ) ;
}
static void
F_199 ( struct V_8 * V_28 , void * V_235 )
{
F_196 ( V_28 ) ;
}
void
F_200 ( struct V_9 * V_10 )
{
F_201 ( V_10 , NULL , F_199 ) ;
}
static void
F_202 ( struct V_8 * V_28 , void * V_235 )
{
F_198 ( V_28 ) ;
}
void
F_203 ( struct V_9 * V_10 )
{
F_201 ( V_10 , NULL , F_202 ) ;
}
int
F_204 ( struct V_8 * V_28 )
{
struct V_11 * V_12 = V_28 -> V_11 ;
unsigned long V_13 ;
int V_284 = 0 ;
V_284 = F_183 ( V_28 , V_178 ) ;
if ( V_284 ) {
V_284 = F_183 ( V_28 , V_179 ) ;
if ( V_284 )
return V_284 ;
}
F_5 ( V_12 -> V_25 , V_13 ) ;
F_205 ( V_12 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
return 0 ;
}
int
F_206 ( struct V_8 * V_28 ,
enum V_254 V_285 )
{
struct V_11 * V_12 = V_28 -> V_11 ;
unsigned long V_13 ;
if ( ( V_28 -> V_170 == V_178 ) ||
( V_28 -> V_170 == V_173 ) )
V_28 -> V_170 = V_285 ;
else if ( V_28 -> V_170 == V_179 ) {
if ( V_285 == V_173 ||
V_285 == V_172 )
V_28 -> V_170 = V_285 ;
else
V_28 -> V_170 = V_257 ;
} else if ( V_28 -> V_170 != V_259 &&
V_28 -> V_170 != V_172 )
return - V_238 ;
F_5 ( V_12 -> V_25 , V_13 ) ;
F_207 ( V_12 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
return 0 ;
}
static void
F_208 ( struct V_8 * V_28 , void * V_235 )
{
F_204 ( V_28 ) ;
}
static int
F_209 ( struct V_7 * V_211 , void * V_235 )
{
if ( F_210 ( V_211 ) )
F_201 ( F_211 ( V_211 ) , NULL ,
F_208 ) ;
return 0 ;
}
void
F_212 ( struct V_7 * V_211 )
{
if ( F_210 ( V_211 ) )
F_201 ( F_211 ( V_211 ) , NULL ,
F_208 ) ;
else
F_213 ( V_211 , NULL , F_209 ) ;
}
static void
F_214 ( struct V_8 * V_28 , void * V_235 )
{
F_206 ( V_28 , * (enum V_254 * ) V_235 ) ;
}
static int
F_215 ( struct V_7 * V_211 , void * V_235 )
{
if ( F_210 ( V_211 ) )
F_201 ( F_211 ( V_211 ) , V_235 ,
F_214 ) ;
return 0 ;
}
void
F_216 ( struct V_7 * V_211 , enum V_254 V_285 )
{
if ( F_210 ( V_211 ) )
F_201 ( F_211 ( V_211 ) , & V_285 ,
F_214 ) ;
else
F_213 ( V_211 , & V_285 , F_215 ) ;
}
void * F_217 ( struct V_83 * V_84 , int V_286 ,
T_5 * V_287 , T_5 * V_122 )
{
int V_222 ;
T_5 V_288 = 0 , V_289 = 0 ;
struct V_83 * V_290 ;
struct V_291 * V_291 ;
F_218 ( ! F_219 () ) ;
F_220 (sgl, sg, sg_count, i) {
V_289 = V_288 ;
V_288 += V_290 -> V_151 ;
if ( V_288 > * V_287 )
break;
}
if ( F_16 ( V_222 == V_286 ) ) {
F_3 ( V_174 L_39
L_40 ,
V_199 , V_288 , * V_287 , V_286 ) ;
F_218 ( 1 ) ;
return NULL ;
}
* V_287 = * V_287 - V_289 + V_290 -> V_287 ;
V_291 = F_221 ( F_222 ( V_290 ) , ( * V_287 >> V_209 ) ) ;
* V_287 &= ~ V_292 ;
V_288 = V_293 - * V_287 ;
if ( * V_122 > V_288 )
* V_122 = V_288 ;
return F_223 ( V_291 ) ;
}
void F_224 ( void * V_294 )
{
F_225 ( V_294 ) ;
}
void F_226 ( struct V_8 * V_28 )
{
F_126 ( & V_28 -> V_295 ) ;
}
void F_227 ( struct V_8 * V_28 )
{
if ( F_228 ( F_229 ( & V_28 -> V_295 ) <= 0 ) )
return;
F_230 ( & V_28 -> V_295 ) ;
}
