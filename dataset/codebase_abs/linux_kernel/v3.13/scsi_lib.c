static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_3 * V_4 , int V_6 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 -> V_9 ;
struct V_11 * V_10 = V_4 -> V_10 ;
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = V_10 -> V_14 ;
unsigned long V_16 ;
F_5 ( 1 ,
F_6 ( L_1 , V_4 ) ) ;
switch ( V_6 ) {
case V_17 :
V_9 -> V_18 = V_9 -> V_19 ;
break;
case V_20 :
case V_21 :
V_10 -> V_22 = V_10 -> V_23 ;
break;
case V_24 :
V_13 -> V_25 = V_13 -> V_26 ;
break;
}
if ( V_7 )
F_7 ( V_10 ) ;
F_8 ( V_15 -> V_27 , V_16 ) ;
F_9 ( V_15 , V_4 -> V_1 ) ;
F_10 ( V_15 , & V_10 -> V_28 ) ;
F_11 ( V_15 -> V_27 , V_16 ) ;
}
void F_12 ( struct V_3 * V_4 , int V_6 )
{
F_4 ( V_4 , V_6 , 1 ) ;
}
int F_13 ( struct V_11 * V_29 , const unsigned char * V_4 ,
int V_30 , void * V_31 , unsigned V_32 ,
unsigned char * V_33 , int V_34 , int V_35 , int V_16 ,
int * V_36 )
{
struct V_1 * V_2 ;
int V_37 = ( V_30 == V_38 ) ;
int V_39 = V_40 << 24 ;
V_2 = F_14 ( V_29 -> V_14 , V_37 , V_41 ) ;
if ( ! V_2 )
return V_39 ;
if ( V_32 && F_15 ( V_29 -> V_14 , V_2 ,
V_31 , V_32 , V_41 ) )
goto V_42;
V_2 -> V_43 = F_16 ( V_4 [ 0 ] ) ;
memcpy ( V_2 -> V_4 , V_4 , V_2 -> V_43 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_44 = 0 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 |= V_16 | V_48 | V_49 ;
F_17 ( V_2 -> V_15 , NULL , V_2 , 1 ) ;
if ( F_18 ( V_2 -> V_50 > 0 && V_2 -> V_50 <= V_32 ) )
memset ( V_31 + ( V_32 - V_2 -> V_50 ) , 0 , V_2 -> V_50 ) ;
if ( V_36 )
* V_36 = V_2 -> V_50 ;
V_39 = V_2 -> V_51 ;
V_42:
F_19 ( V_2 ) ;
return V_39 ;
}
int F_20 ( struct V_11 * V_29 , const unsigned char * V_4 ,
int V_30 , void * V_31 , unsigned V_32 ,
struct V_52 * V_53 , int V_34 , int V_35 ,
int * V_36 , int V_16 )
{
char * V_33 = NULL ;
int V_54 ;
if ( V_53 ) {
V_33 = F_21 ( V_55 , V_56 ) ;
if ( ! V_33 )
return V_40 << 24 ;
}
V_54 = F_13 ( V_29 , V_4 , V_30 , V_31 , V_32 ,
V_33 , V_34 , V_35 , V_16 , V_36 ) ;
if ( V_53 )
F_22 ( V_33 , V_55 , V_53 ) ;
F_23 ( V_33 ) ;
return V_54 ;
}
static void F_24 ( struct V_3 * V_4 )
{
V_4 -> V_57 = 0 ;
F_25 ( V_4 , 0 ) ;
memset ( V_4 -> V_58 , 0 , V_55 ) ;
if ( V_4 -> V_43 == 0 )
V_4 -> V_43 = F_26 ( V_4 -> V_59 ) ;
}
void F_7 ( struct V_11 * V_29 )
{
struct V_8 * V_60 = V_29 -> V_9 ;
struct V_12 * V_13 = V_12 ( V_29 ) ;
unsigned long V_16 ;
F_8 ( V_60 -> V_61 , V_16 ) ;
V_60 -> V_62 -- ;
V_13 -> V_63 -- ;
if ( F_18 ( F_27 ( V_60 ) &&
( V_60 -> V_64 || V_60 -> V_65 ) ) )
F_28 ( V_60 ) ;
F_29 ( V_60 -> V_61 ) ;
F_30 ( V_29 -> V_14 -> V_27 ) ;
V_29 -> V_66 -- ;
F_11 ( V_29 -> V_14 -> V_27 , V_16 ) ;
}
static void F_31 ( struct V_11 * V_67 )
{
struct V_8 * V_60 = V_67 -> V_9 ;
struct V_11 * V_29 , * V_68 ;
struct V_12 * V_13 = V_12 ( V_67 ) ;
unsigned long V_16 ;
F_8 ( V_60 -> V_61 , V_16 ) ;
V_13 -> V_69 = NULL ;
F_11 ( V_60 -> V_61 , V_16 ) ;
F_32 ( V_67 -> V_14 ) ;
F_8 ( V_60 -> V_61 , V_16 ) ;
if ( V_13 -> V_69 )
goto V_42;
F_33 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_29 == V_67 )
continue;
if ( F_34 ( V_29 ) )
continue;
F_11 ( V_60 -> V_61 , V_16 ) ;
F_32 ( V_29 -> V_14 ) ;
F_8 ( V_60 -> V_61 , V_16 ) ;
F_35 ( V_29 ) ;
}
V_42:
F_11 ( V_60 -> V_61 , V_16 ) ;
}
static inline int F_36 ( struct V_11 * V_29 )
{
if ( V_29 -> V_66 >= V_29 -> V_70 || V_29 -> V_22 )
return 1 ;
return 0 ;
}
static inline int F_37 ( struct V_12 * V_13 )
{
return ( ( V_13 -> V_71 > 0 &&
V_13 -> V_63 >= V_13 -> V_71 ) ||
V_13 -> V_25 ) ;
}
static inline int F_38 ( struct V_8 * V_60 )
{
if ( ( V_60 -> V_71 > 0 && V_60 -> V_62 >= V_60 -> V_71 ) ||
V_60 -> V_18 || V_60 -> V_72 )
return 1 ;
return 0 ;
}
static void F_39 ( struct V_14 * V_15 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
struct V_8 * V_60 ;
F_40 ( V_74 ) ;
unsigned long V_16 ;
V_60 = V_29 -> V_9 ;
if ( V_12 ( V_29 ) -> V_75 )
F_31 ( V_29 ) ;
F_8 ( V_60 -> V_61 , V_16 ) ;
F_41 ( & V_60 -> V_74 , & V_74 ) ;
while ( ! F_42 ( & V_74 ) ) {
struct V_14 * V_76 ;
if ( F_38 ( V_60 ) )
break;
V_29 = F_43 ( V_74 . V_77 ,
struct V_11 , V_78 ) ;
F_44 ( & V_29 -> V_78 ) ;
if ( F_37 ( V_12 ( V_29 ) ) ) {
F_45 ( & V_29 -> V_78 ,
& V_60 -> V_74 ) ;
continue;
}
V_76 = V_29 -> V_14 ;
if ( ! F_46 ( V_76 ) )
continue;
F_11 ( V_60 -> V_61 , V_16 ) ;
F_32 ( V_76 ) ;
F_47 ( V_76 ) ;
F_8 ( V_60 -> V_61 , V_16 ) ;
}
F_48 ( & V_74 , & V_60 -> V_74 ) ;
F_11 ( V_60 -> V_61 , V_16 ) ;
F_32 ( V_15 ) ;
}
void F_49 ( struct V_79 * V_80 )
{
struct V_11 * V_29 ;
struct V_14 * V_15 ;
V_29 = F_50 ( V_80 , struct V_11 , V_28 ) ;
V_15 = V_29 -> V_14 ;
F_39 ( V_15 ) ;
}
static void F_51 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_11 * V_29 = V_4 -> V_10 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_16 ;
F_52 ( & V_29 -> V_81 ) ;
F_8 ( V_15 -> V_27 , V_16 ) ;
F_1 ( V_2 ) ;
F_9 ( V_15 , V_2 ) ;
F_11 ( V_15 -> V_27 , V_16 ) ;
F_39 ( V_15 ) ;
F_53 ( & V_29 -> V_81 ) ;
}
void F_54 ( struct V_3 * V_4 )
{
struct V_11 * V_29 = V_4 -> V_10 ;
struct V_14 * V_15 = V_29 -> V_14 ;
F_52 ( & V_29 -> V_81 ) ;
F_3 ( V_4 ) ;
F_39 ( V_15 ) ;
F_53 ( & V_29 -> V_81 ) ;
}
void F_55 ( struct V_8 * V_60 )
{
struct V_11 * V_29 ;
F_56 (sdev, shost)
F_39 ( V_29 -> V_14 ) ;
}
static struct V_3 * F_57 ( struct V_3 * V_4 , int error ,
int V_82 , int V_83 )
{
struct V_14 * V_15 = V_4 -> V_10 -> V_14 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( F_58 ( V_2 , error , V_82 ) ) {
if ( error && F_59 ( V_4 ) )
F_60 ( V_2 , error ) ;
else {
if ( V_83 ) {
F_61 ( V_4 ) ;
F_51 ( V_15 , V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
}
F_62 ( V_4 , 0 ) ;
F_54 ( V_4 ) ;
return NULL ;
}
static inline unsigned int F_63 ( unsigned short V_84 )
{
unsigned int V_85 ;
F_64 ( V_84 > V_86 ) ;
if ( V_84 <= 8 )
V_85 = 0 ;
else
V_85 = F_65 ( V_84 ) - 3 ;
return V_85 ;
}
static void F_66 ( struct V_87 * V_88 , unsigned int V_84 )
{
struct V_89 * V_90 ;
V_90 = V_91 + F_63 ( V_84 ) ;
F_67 ( V_88 , V_90 -> V_92 ) ;
}
static struct V_87 * F_68 ( unsigned int V_84 , T_1 V_93 )
{
struct V_89 * V_90 ;
V_90 = V_91 + F_63 ( V_84 ) ;
return F_69 ( V_90 -> V_92 , V_93 ) ;
}
static int F_70 ( struct V_94 * V_95 , int V_84 ,
T_1 V_93 )
{
int V_39 ;
F_64 ( ! V_84 ) ;
V_39 = F_71 ( & V_95 -> V_96 , V_84 , V_86 ,
V_93 , F_68 ) ;
if ( F_18 ( V_39 ) )
F_72 ( & V_95 -> V_96 , V_86 ,
F_66 ) ;
return V_39 ;
}
static void F_73 ( struct V_94 * V_95 )
{
F_72 ( & V_95 -> V_96 , V_86 , F_66 ) ;
}
static void F_62 ( struct V_3 * V_4 , int V_97 )
{
if ( V_4 -> V_95 . V_96 . V_84 )
F_73 ( & V_4 -> V_95 ) ;
memset ( & V_4 -> V_95 , 0 , sizeof( V_4 -> V_95 ) ) ;
if ( V_97 && F_74 ( V_4 ) ) {
struct V_94 * V_98 =
V_4 -> V_1 -> V_99 -> V_5 ;
F_73 ( V_98 ) ;
F_75 ( V_100 , V_98 ) ;
V_4 -> V_1 -> V_99 -> V_5 = NULL ;
}
if ( F_76 ( V_4 ) )
F_73 ( V_4 -> V_101 ) ;
}
void F_61 ( struct V_3 * V_4 )
{
F_62 ( V_4 , 1 ) ;
}
static int F_77 ( struct V_3 * V_4 , int V_54 )
{
int error = 0 ;
switch( F_78 ( V_54 ) ) {
case V_102 :
error = - V_103 ;
break;
case V_104 :
F_79 ( V_4 , V_105 ) ;
error = - V_106 ;
break;
case V_107 :
F_79 ( V_4 , V_105 ) ;
error = - V_108 ;
break;
case V_109 :
F_79 ( V_4 , V_105 ) ;
error = - V_110 ;
break;
case V_111 :
F_79 ( V_4 , V_105 ) ;
error = - V_112 ;
break;
default:
error = - V_113 ;
break;
}
return error ;
}
void F_80 ( struct V_3 * V_4 , unsigned int V_114 )
{
int V_54 = V_4 -> V_54 ;
struct V_14 * V_15 = V_4 -> V_10 -> V_14 ;
struct V_1 * V_2 = V_4 -> V_1 ;
int error = 0 ;
struct V_52 V_53 ;
int V_115 = 0 ;
int V_116 = 0 ;
enum { V_117 , V_118 , V_119 ,
V_120 } V_121 ;
char * V_122 = NULL ;
if ( V_54 ) {
V_115 = F_81 ( V_4 , & V_53 ) ;
if ( V_115 )
V_116 = F_82 ( & V_53 ) ;
}
if ( V_2 -> V_45 == V_46 ) {
if ( V_54 ) {
if ( V_115 && V_2 -> V_33 ) {
int V_123 = 8 + V_4 -> V_58 [ 7 ] ;
if ( V_123 > V_55 )
V_123 = V_55 ;
memcpy ( V_2 -> V_33 , V_4 -> V_58 , V_123 ) ;
V_2 -> V_44 = V_123 ;
}
if ( ! V_116 )
error = F_77 ( V_4 , V_54 ) ;
}
V_2 -> V_51 = V_4 -> V_54 ;
V_2 -> V_50 = F_83 ( V_4 ) ;
if ( F_74 ( V_4 ) ) {
V_2 -> V_99 -> V_50 = F_84 ( V_4 ) -> V_36 ;
F_61 ( V_4 ) ;
F_60 ( V_2 , 0 ) ;
F_54 ( V_4 ) ;
return;
}
}
F_64 ( F_85 ( V_2 ) ) ;
F_86 ( 1 , F_6 ( L_2
L_3 ,
F_87 ( V_2 ) , V_114 ) ) ;
if ( V_115 && ( V_53 . V_124 == V_125 ) ) {
if ( ( V_53 . V_126 == 0x0 ) && ( V_53 . V_127 == 0x1d ) )
;
else if ( ! ( V_2 -> V_47 & V_48 ) )
F_88 ( L_4 , V_4 ) ;
V_54 = 0 ;
error = 0 ;
}
if ( F_57 ( V_4 , error , V_114 , V_54 == 0 ) == NULL )
return;
error = F_77 ( V_4 , V_54 ) ;
if ( F_78 ( V_54 ) == V_128 ) {
V_121 = V_119 ;
} else if ( V_115 && ! V_116 ) {
switch ( V_53 . V_124 ) {
case V_129 :
if ( V_4 -> V_10 -> V_130 ) {
V_4 -> V_10 -> V_131 = 1 ;
V_122 = L_5 ;
V_121 = V_117 ;
} else {
V_121 = V_119 ;
}
break;
case V_132 :
if ( ( V_4 -> V_10 -> V_133 &&
V_53 . V_126 == 0x20 && V_53 . V_127 == 0x00 ) &&
( V_4 -> V_59 [ 0 ] == V_134 ||
V_4 -> V_59 [ 0 ] == V_135 ) ) {
V_4 -> V_10 -> V_133 = 0 ;
V_121 = V_118 ;
} else if ( V_53 . V_126 == 0x10 ) {
V_122 = L_6 ;
V_121 = V_117 ;
error = - V_136 ;
} else if ( V_53 . V_126 == 0x20 || V_53 . V_126 == 0x24 ) {
switch ( V_4 -> V_59 [ 0 ] ) {
case V_137 :
V_122 = L_7 ;
break;
case V_138 :
case V_139 :
if ( V_4 -> V_59 [ 1 ] & 0x8 )
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
error = - V_106 ;
} else
V_121 = V_117 ;
break;
case V_140 :
V_121 = V_117 ;
if ( V_53 . V_126 == 0x10 ) {
V_122 = L_10 ;
error = - V_136 ;
}
break;
case V_141 :
if ( V_53 . V_126 == 0x04 ) {
switch ( V_53 . V_127 ) {
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
F_61 ( V_4 ) ;
if ( ! ( V_2 -> V_47 & V_48 ) ) {
if ( V_122 )
F_89 ( V_143 , V_4 , L_14 ,
V_122 ) ;
F_90 ( V_4 ) ;
if ( F_91 ( V_54 ) & V_144 )
F_88 ( L_4 , V_4 ) ;
F_92 ( V_4 ) ;
}
if ( F_93 ( V_2 , error ) )
F_51 ( V_15 , V_4 ) ;
else
F_54 ( V_4 ) ;
break;
case V_118 :
F_61 ( V_4 ) ;
F_51 ( V_15 , V_4 ) ;
break;
case V_119 :
F_4 ( V_4 , V_21 , 0 ) ;
break;
case V_120 :
F_4 ( V_4 , V_20 , 0 ) ;
break;
}
}
static int F_94 ( struct V_1 * V_2 , struct V_94 * V_95 ,
T_1 V_93 )
{
int V_145 ;
if ( F_18 ( F_70 ( V_95 , V_2 -> V_146 ,
V_93 ) ) ) {
return V_147 ;
}
V_2 -> V_31 = NULL ;
V_145 = F_95 ( V_2 -> V_15 , V_2 , V_95 -> V_96 . V_88 ) ;
F_64 ( V_145 > V_95 -> V_96 . V_84 ) ;
V_95 -> V_96 . V_84 = V_145 ;
V_95 -> V_148 = F_96 ( V_2 ) ;
return V_149 ;
}
int F_97 ( struct V_3 * V_4 , T_1 V_93 )
{
struct V_1 * V_150 = V_4 -> V_1 ;
int error = F_94 ( V_150 , & V_4 -> V_95 , V_93 ) ;
if ( error )
goto V_151;
if ( F_85 ( V_150 ) ) {
struct V_94 * V_98 = F_98 (
V_100 , V_152 ) ;
if ( ! V_98 ) {
error = V_147 ;
goto V_151;
}
V_150 -> V_99 -> V_5 = V_98 ;
error = F_94 ( V_150 -> V_99 , V_98 , V_152 ) ;
if ( error )
goto V_151;
}
if ( F_99 ( V_150 ) ) {
struct V_94 * V_101 = V_4 -> V_101 ;
int V_153 , V_145 ;
F_64 ( V_101 == NULL ) ;
V_153 = F_100 ( V_150 -> V_15 , V_150 -> V_154 ) ;
if ( F_70 ( V_101 , V_153 , V_93 ) ) {
error = V_147 ;
goto V_151;
}
V_145 = F_101 ( V_150 -> V_15 , V_150 -> V_154 ,
V_101 -> V_96 . V_88 ) ;
F_64 ( F_18 ( V_145 > V_153 ) ) ;
F_64 ( F_18 ( V_145 > F_102 ( V_150 -> V_15 ) ) ) ;
V_4 -> V_101 = V_101 ;
V_4 -> V_101 -> V_96 . V_84 = V_145 ;
}
return V_149 ;
V_151:
F_61 ( V_4 ) ;
V_4 -> V_1 -> V_5 = NULL ;
F_3 ( V_4 ) ;
return error ;
}
static struct V_3 * F_103 ( struct V_11 * V_29 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_5 ) {
V_4 = F_104 ( V_29 , V_152 ) ;
if ( F_18 ( ! V_4 ) )
return NULL ;
V_2 -> V_5 = V_4 ;
} else {
V_4 = V_2 -> V_5 ;
}
V_4 -> V_155 = V_2 -> V_155 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_59 = V_2 -> V_4 ;
V_4 -> V_156 = V_157 ;
return V_4 ;
}
int F_105 ( struct V_11 * V_29 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_39 = F_106 ( V_29 , V_2 ) ;
if ( V_39 != V_149 )
return V_39 ;
V_4 = F_103 ( V_29 , V_2 ) ;
if ( F_18 ( ! V_4 ) )
return V_147 ;
if ( V_2 -> V_154 ) {
int V_39 ;
F_64 ( ! V_2 -> V_146 ) ;
V_39 = F_97 ( V_4 , V_152 ) ;
if ( F_18 ( V_39 ) )
return V_39 ;
} else {
F_64 ( F_96 ( V_2 ) ) ;
memset ( & V_4 -> V_95 , 0 , sizeof( V_4 -> V_95 ) ) ;
V_2 -> V_31 = NULL ;
}
V_4 -> V_43 = V_2 -> V_43 ;
if ( ! F_96 ( V_2 ) )
V_4 -> V_158 = V_159 ;
else if ( F_107 ( V_2 ) == V_160 )
V_4 -> V_158 = V_38 ;
else
V_4 -> V_158 = V_161 ;
V_4 -> V_162 = F_96 ( V_2 ) ;
V_4 -> V_163 = V_2 -> V_35 ;
return V_149 ;
}
int F_108 ( struct V_11 * V_29 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_39 = F_106 ( V_29 , V_2 ) ;
if ( V_39 != V_149 )
return V_39 ;
if ( F_18 ( V_29 -> V_164 && V_29 -> V_164 -> V_165
&& V_29 -> V_164 -> V_165 -> V_166 ) ) {
V_39 = V_29 -> V_164 -> V_165 -> V_166 ( V_29 , V_2 ) ;
if ( V_39 != V_149 )
return V_39 ;
}
F_64 ( ! V_2 -> V_146 ) ;
V_4 = F_103 ( V_29 , V_2 ) ;
if ( F_18 ( ! V_4 ) )
return V_147 ;
memset ( V_4 -> V_59 , 0 , V_167 ) ;
return F_97 ( V_4 , V_152 ) ;
}
int F_106 ( struct V_11 * V_29 , struct V_1 * V_2 )
{
int V_39 = V_149 ;
if ( F_18 ( V_29 -> V_168 != V_169 ) ) {
switch ( V_29 -> V_168 ) {
case V_170 :
case V_171 :
F_109 ( V_172 , V_29 ,
L_15 ) ;
V_39 = V_173 ;
break;
case V_174 :
F_109 ( V_172 , V_29 ,
L_16 ) ;
V_39 = V_173 ;
break;
case V_175 :
case V_176 :
case V_177 :
if ( ! ( V_2 -> V_47 & V_49 ) )
V_39 = V_147 ;
break;
default:
if ( ! ( V_2 -> V_47 & V_49 ) )
V_39 = V_173 ;
break;
}
}
return V_39 ;
}
int F_110 ( struct V_14 * V_15 , struct V_1 * V_2 , int V_39 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
switch ( V_39 ) {
case V_173 :
V_2 -> V_51 = V_178 << 16 ;
if ( V_2 -> V_5 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
F_61 ( V_4 ) ;
F_3 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
break;
case V_147 :
if ( V_29 -> V_66 == 0 )
F_111 ( V_15 , V_179 ) ;
break;
default:
V_2 -> V_47 |= V_180 ;
}
return V_39 ;
}
int F_112 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
int V_39 = V_173 ;
if ( V_2 -> V_45 == V_46 )
V_39 = F_105 ( V_29 , V_2 ) ;
return F_110 ( V_15 , V_2 , V_39 ) ;
}
static inline int F_113 ( struct V_14 * V_15 ,
struct V_11 * V_29 )
{
if ( V_29 -> V_66 == 0 && V_29 -> V_22 ) {
if ( -- V_29 -> V_22 == 0 ) {
F_5 ( 3 ,
F_109 ( V_143 , V_29 ,
L_17 ) ) ;
} else {
F_111 ( V_15 , V_179 ) ;
return 0 ;
}
}
if ( F_36 ( V_29 ) )
return 0 ;
return 1 ;
}
static inline int F_114 ( struct V_8 * V_60 ,
struct V_11 * V_29 )
{
struct V_12 * V_13 = V_12 ( V_29 ) ;
if ( V_13 -> V_75 ) {
if ( V_13 -> V_69 &&
V_13 -> V_69 != V_29 )
return 0 ;
V_13 -> V_69 = V_29 ;
}
if ( V_13 -> V_63 == 0 && V_13 -> V_25 ) {
if ( -- V_13 -> V_25 == 0 ) {
F_5 ( 3 , F_115 ( V_143 , V_13 ,
L_18 ) ) ;
} else
return 0 ;
}
if ( F_37 ( V_13 ) ) {
F_45 ( & V_29 -> V_78 , & V_60 -> V_74 ) ;
return 0 ;
}
return 1 ;
}
static inline int F_116 ( struct V_14 * V_15 ,
struct V_8 * V_60 ,
struct V_11 * V_29 )
{
if ( F_27 ( V_60 ) )
return 0 ;
if ( V_60 -> V_62 == 0 && V_60 -> V_18 ) {
if ( -- V_60 -> V_18 == 0 ) {
F_5 ( 3 ,
F_6 ( L_19 ,
V_60 -> V_181 ) ) ;
} else {
return 0 ;
}
}
if ( F_38 ( V_60 ) ) {
if ( F_42 ( & V_29 -> V_78 ) )
F_117 ( & V_29 -> V_78 , & V_60 -> V_74 ) ;
return 0 ;
}
if ( ! F_42 ( & V_29 -> V_78 ) )
F_44 ( & V_29 -> V_78 ) ;
return 1 ;
}
static int F_118 ( struct V_14 * V_15 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
struct V_8 * V_60 ;
if ( F_119 ( V_15 ) )
return 0 ;
V_60 = V_29 -> V_9 ;
if ( F_27 ( V_60 ) || F_36 ( V_29 ) )
return 1 ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_29 ;
struct V_12 * V_13 ;
struct V_8 * V_60 ;
F_121 ( V_2 ) ;
F_89 ( V_143 , V_4 , L_20 ) ;
V_29 = V_4 -> V_10 ;
V_13 = V_12 ( V_29 ) ;
V_60 = V_29 -> V_9 ;
F_24 ( V_4 ) ;
V_4 -> V_54 = V_178 << 16 ;
F_122 ( & V_4 -> V_10 -> V_182 ) ;
V_29 -> V_66 ++ ;
F_29 ( V_29 -> V_14 -> V_27 ) ;
F_30 ( V_60 -> V_61 ) ;
V_60 -> V_62 ++ ;
V_13 -> V_63 ++ ;
F_29 ( V_60 -> V_61 ) ;
F_30 ( V_29 -> V_14 -> V_27 ) ;
F_123 ( V_2 ) ;
}
static void F_124 ( struct V_1 * V_150 )
{
struct V_3 * V_4 = V_150 -> V_5 ;
unsigned long V_183 = ( V_4 -> V_163 + 1 ) * V_150 -> V_34 ;
int V_184 ;
F_125 ( & V_4 -> V_185 ) ;
F_122 ( & V_4 -> V_10 -> V_186 ) ;
if ( V_4 -> V_54 )
F_122 ( & V_4 -> V_10 -> V_187 ) ;
V_184 = F_126 ( V_4 ) ;
if ( V_184 != V_188 &&
F_127 ( V_4 -> V_189 + V_183 , V_190 ) ) {
F_109 ( V_172 , V_4 -> V_10 ,
L_21 ,
V_183 / V_191 ) ;
V_184 = V_188 ;
}
F_128 ( V_4 , V_184 ) ;
switch ( V_184 ) {
case V_188 :
F_129 ( V_4 ) ;
break;
case V_192 :
F_12 ( V_4 , V_21 ) ;
break;
case V_193 :
F_12 ( V_4 , V_20 ) ;
break;
default:
if ( ! F_130 ( V_4 , 0 ) )
F_129 ( V_4 ) ;
}
}
static void F_131 ( struct V_14 * V_15 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
struct V_8 * V_60 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
if( ! F_52 ( & V_29 -> V_81 ) )
return;
V_60 = V_29 -> V_9 ;
for (; ; ) {
int V_194 ;
V_2 = F_132 ( V_15 ) ;
if ( ! V_2 || ! F_113 ( V_15 , V_29 ) )
break;
if ( F_18 ( ! F_133 ( V_29 ) ) ) {
F_109 ( V_172 , V_29 ,
L_15 ) ;
F_120 ( V_2 , V_15 ) ;
continue;
}
if ( ! ( F_134 ( V_15 ) && ! F_135 ( V_15 , V_2 ) ) )
F_121 ( V_2 ) ;
V_29 -> V_66 ++ ;
F_29 ( V_15 -> V_27 ) ;
V_4 = V_2 -> V_5 ;
if ( F_18 ( V_4 == NULL ) ) {
F_6 ( V_195 L_22
L_23
L_24 ,
V_196 ) ;
F_136 ( V_2 , L_25 ) ;
F_137 () ;
}
F_30 ( V_60 -> V_61 ) ;
if ( F_134 ( V_15 ) && ! F_138 ( V_2 ) ) {
if ( F_42 ( & V_29 -> V_78 ) )
F_117 ( & V_29 -> V_78 ,
& V_60 -> V_74 ) ;
goto V_197;
}
if ( ! F_114 ( V_60 , V_29 ) )
goto V_197;
if ( ! F_116 ( V_15 , V_60 , V_29 ) )
goto V_197;
V_12 ( V_29 ) -> V_63 ++ ;
V_60 -> V_62 ++ ;
F_139 ( V_60 -> V_61 ) ;
F_24 ( V_4 ) ;
V_194 = F_140 ( V_4 ) ;
F_141 ( V_15 -> V_27 ) ;
if ( V_194 )
goto V_198;
}
goto V_42;
V_197:
F_139 ( V_60 -> V_61 ) ;
F_141 ( V_15 -> V_27 ) ;
F_9 ( V_15 , V_2 ) ;
V_29 -> V_66 -- ;
V_198:
if ( V_29 -> V_66 == 0 )
F_111 ( V_15 , V_179 ) ;
V_42:
F_139 ( V_15 -> V_27 ) ;
F_53 ( & V_29 -> V_81 ) ;
F_141 ( V_15 -> V_27 ) ;
}
T_2 F_142 ( struct V_8 * V_60 )
{
struct V_10 * V_199 ;
T_2 V_200 = 0xffffffff ;
if ( V_60 -> V_201 )
return V_202 ;
if ( ! V_203 )
return V_204 ;
V_199 = F_143 ( V_60 ) ;
if ( V_199 && V_199 -> V_205 )
V_200 = F_144 ( V_199 ) << V_206 ;
return V_200 ;
}
struct V_14 * F_145 ( struct V_8 * V_60 ,
T_3 * V_207 )
{
struct V_14 * V_15 ;
struct V_10 * V_208 = V_60 -> V_209 ;
V_15 = F_146 ( V_207 , NULL ) ;
if ( ! V_15 )
return NULL ;
F_147 ( V_15 , F_148 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_149 ( V_60 ) ) {
V_60 -> V_210 =
F_150 ( V_60 -> V_210 ,
( unsigned short ) V_211 ) ;
F_64 ( V_60 -> V_210 < V_60 -> V_212 ) ;
F_151 ( V_15 , V_60 -> V_210 ) ;
}
F_152 ( V_15 , V_60 -> V_213 ) ;
F_153 ( V_15 , F_142 ( V_60 ) ) ;
F_154 ( V_15 , V_60 -> V_214 ) ;
F_155 ( V_208 , V_60 -> V_214 ) ;
F_156 ( V_15 , F_157 ( V_208 ) ) ;
if ( ! V_60 -> V_215 )
V_15 -> V_216 . V_217 = 0 ;
F_158 ( V_15 , 0x03 ) ;
return V_15 ;
}
struct V_14 * F_159 ( struct V_11 * V_29 )
{
struct V_14 * V_15 ;
V_15 = F_145 ( V_29 -> V_9 , F_131 ) ;
if ( ! V_15 )
return NULL ;
F_160 ( V_15 , F_112 ) ;
F_161 ( V_15 , F_124 ) ;
F_162 ( V_15 , V_218 ) ;
F_163 ( V_15 , F_118 ) ;
return V_15 ;
}
void F_164 ( struct V_8 * V_60 )
{
V_60 -> V_72 = 1 ;
}
void F_165 ( struct V_8 * V_60 )
{
V_60 -> V_72 = 0 ;
F_55 ( V_60 ) ;
}
int T_4 F_166 ( void )
{
int V_219 ;
V_100 = F_167 ( L_26 ,
sizeof( struct V_94 ) ,
0 , 0 , NULL ) ;
if ( ! V_100 ) {
F_6 ( V_172 L_27 ) ;
return - V_220 ;
}
for ( V_219 = 0 ; V_219 < V_221 ; V_219 ++ ) {
struct V_89 * V_90 = V_91 + V_219 ;
int V_222 = V_90 -> V_222 * sizeof( struct V_87 ) ;
V_90 -> V_223 = F_167 ( V_90 -> V_224 , V_222 , 0 ,
V_225 , NULL ) ;
if ( ! V_90 -> V_223 ) {
F_6 ( V_172 L_28 ,
V_90 -> V_224 ) ;
goto V_226;
}
V_90 -> V_92 = F_168 ( V_227 ,
V_90 -> V_223 ) ;
if ( ! V_90 -> V_92 ) {
F_6 ( V_172 L_29 ,
V_90 -> V_224 ) ;
goto V_226;
}
}
return 0 ;
V_226:
for ( V_219 = 0 ; V_219 < V_221 ; V_219 ++ ) {
struct V_89 * V_90 = V_91 + V_219 ;
if ( V_90 -> V_92 )
F_169 ( V_90 -> V_92 ) ;
if ( V_90 -> V_223 )
F_170 ( V_90 -> V_223 ) ;
}
F_170 ( V_100 ) ;
return - V_220 ;
}
void F_171 ( void )
{
int V_219 ;
F_170 ( V_100 ) ;
for ( V_219 = 0 ; V_219 < V_221 ; V_219 ++ ) {
struct V_89 * V_90 = V_91 + V_219 ;
F_169 ( V_90 -> V_92 ) ;
F_170 ( V_90 -> V_223 ) ;
}
}
int
F_172 ( struct V_11 * V_29 , int V_228 , int V_229 , int V_230 ,
unsigned char * V_31 , int V_123 , int V_34 , int V_35 ,
struct V_231 * V_232 , struct V_52 * V_53 )
{
unsigned char V_4 [ 10 ] ;
unsigned char * V_233 ;
int V_39 ;
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
V_4 [ 1 ] = ( V_228 ? 0x10 : 0 ) | ( V_229 ? 0x01 : 0 ) ;
if ( V_29 -> V_234 ) {
if ( V_123 > 65535 )
return - V_235 ;
V_233 = F_173 ( 8 + V_123 , V_236 ) ;
if ( ! V_233 )
return - V_220 ;
memcpy ( V_233 + 8 , V_31 , V_123 ) ;
V_123 += 8 ;
V_233 [ 0 ] = 0 ;
V_233 [ 1 ] = 0 ;
V_233 [ 2 ] = V_232 -> V_237 ;
V_233 [ 3 ] = V_232 -> V_238 ;
V_233 [ 4 ] = V_232 -> V_239 ? 0x01 : 0 ;
V_233 [ 5 ] = 0 ;
V_233 [ 6 ] = V_232 -> V_240 >> 8 ;
V_233 [ 7 ] = V_232 -> V_240 ;
V_4 [ 0 ] = V_241 ;
V_4 [ 7 ] = V_123 >> 8 ;
V_4 [ 8 ] = V_123 ;
} else {
if ( V_123 > 255 || V_232 -> V_240 > 255 ||
V_232 -> V_239 )
return - V_235 ;
V_233 = F_173 ( 4 + V_123 , V_236 ) ;
if ( ! V_233 )
return - V_220 ;
memcpy ( V_233 + 4 , V_31 , V_123 ) ;
V_123 += 4 ;
V_233 [ 0 ] = 0 ;
V_233 [ 1 ] = V_232 -> V_237 ;
V_233 [ 2 ] = V_232 -> V_238 ;
V_233 [ 3 ] = V_232 -> V_240 ;
V_4 [ 0 ] = V_242 ;
V_4 [ 4 ] = V_123 ;
}
V_39 = F_174 ( V_29 , V_4 , V_38 , V_233 , V_123 ,
V_53 , V_34 , V_35 , NULL ) ;
F_23 ( V_233 ) ;
return V_39 ;
}
int
F_175 ( struct V_11 * V_29 , int V_243 , int V_230 ,
unsigned char * V_31 , int V_123 , int V_34 , int V_35 ,
struct V_231 * V_232 , struct V_52 * V_53 )
{
unsigned char V_4 [ 12 ] ;
int V_234 ;
int V_244 ;
int V_54 ;
struct V_52 V_245 ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
memset ( & V_4 [ 0 ] , 0 , 12 ) ;
V_4 [ 1 ] = V_243 & 0x18 ;
V_4 [ 2 ] = V_230 ;
if ( ! V_53 )
V_53 = & V_245 ;
V_246:
V_234 = V_29 -> V_234 ;
if ( V_234 ) {
if ( V_123 < 8 )
V_123 = 8 ;
V_4 [ 0 ] = V_247 ;
V_4 [ 8 ] = V_123 ;
V_244 = 8 ;
} else {
if ( V_123 < 4 )
V_123 = 4 ;
V_4 [ 0 ] = V_248 ;
V_4 [ 4 ] = V_123 ;
V_244 = 4 ;
}
memset ( V_31 , 0 , V_123 ) ;
V_54 = F_174 ( V_29 , V_4 , V_161 , V_31 , V_123 ,
V_53 , V_34 , V_35 , NULL ) ;
if ( V_234 && ! F_176 ( V_54 ) &&
( F_91 ( V_54 ) & V_144 ) ) {
if ( F_177 ( V_53 ) ) {
if ( ( V_53 -> V_124 == V_132 ) &&
( V_53 -> V_126 == 0x20 ) && ( V_53 -> V_127 == 0 ) ) {
V_29 -> V_234 = 0 ;
goto V_246;
}
}
}
if( F_176 ( V_54 ) ) {
if ( F_18 ( V_31 [ 0 ] == 0x86 && V_31 [ 1 ] == 0x0b &&
( V_230 == 6 || V_230 == 8 ) ) ) {
V_244 = 0 ;
V_232 -> V_148 = 13 ;
V_232 -> V_237 = 0 ;
V_232 -> V_238 = 0 ;
V_232 -> V_239 = 0 ;
V_232 -> V_240 = 0 ;
} else if( V_234 ) {
V_232 -> V_148 = V_31 [ 0 ] * 256 + V_31 [ 1 ] + 2 ;
V_232 -> V_237 = V_31 [ 2 ] ;
V_232 -> V_238 = V_31 [ 3 ] ;
V_232 -> V_239 = V_31 [ 4 ] & 0x01 ;
V_232 -> V_240 = V_31 [ 6 ] * 256
+ V_31 [ 7 ] ;
} else {
V_232 -> V_148 = V_31 [ 0 ] + 1 ;
V_232 -> V_237 = V_31 [ 1 ] ;
V_232 -> V_238 = V_31 [ 2 ] ;
V_232 -> V_240 = V_31 [ 3 ] ;
}
V_232 -> V_244 = V_244 ;
}
return V_54 ;
}
int
F_178 ( struct V_11 * V_29 , int V_34 , int V_35 ,
struct V_52 * V_249 )
{
char V_4 [] = {
V_250 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_52 * V_53 ;
int V_54 ;
if ( ! V_249 )
V_53 = F_21 ( sizeof( * V_53 ) , V_236 ) ;
else
V_53 = V_249 ;
do {
V_54 = F_174 ( V_29 , V_4 , V_159 , NULL , 0 , V_53 ,
V_34 , V_35 , NULL ) ;
if ( V_29 -> V_130 && F_177 ( V_53 ) &&
V_53 -> V_124 == V_129 )
V_29 -> V_131 = 1 ;
} while ( F_177 ( V_53 ) &&
V_53 -> V_124 == V_129 && -- V_35 );
if ( ! V_249 )
F_23 ( V_53 ) ;
return V_54 ;
}
int
F_179 ( struct V_11 * V_29 , enum V_251 V_252 )
{
enum V_251 V_253 = V_29 -> V_168 ;
if ( V_252 == V_253 )
return 0 ;
switch ( V_252 ) {
case V_254 :
switch ( V_253 ) {
case V_177 :
break;
default:
goto V_255;
}
break;
case V_169 :
switch ( V_253 ) {
case V_254 :
case V_170 :
case V_171 :
case V_175 :
case V_176 :
break;
default:
goto V_255;
}
break;
case V_175 :
switch ( V_253 ) {
case V_169 :
case V_170 :
case V_171 :
break;
default:
goto V_255;
}
break;
case V_170 :
case V_171 :
switch ( V_253 ) {
case V_254 :
case V_169 :
case V_175 :
case V_176 :
break;
default:
goto V_255;
}
break;
case V_176 :
switch ( V_253 ) {
case V_169 :
case V_177 :
break;
default:
goto V_255;
}
break;
case V_177 :
switch ( V_253 ) {
case V_254 :
break;
default:
goto V_255;
}
break;
case V_256 :
switch ( V_253 ) {
case V_254 :
case V_169 :
case V_175 :
case V_170 :
case V_171 :
case V_176 :
break;
default:
goto V_255;
}
break;
case V_174 :
switch ( V_253 ) {
case V_254 :
case V_169 :
case V_170 :
case V_171 :
case V_256 :
case V_177 :
break;
default:
goto V_255;
}
break;
}
V_29 -> V_168 = V_252 ;
return 0 ;
V_255:
F_180 ( 1 ,
F_109 ( V_172 , V_29 ,
L_30 ,
F_181 ( V_253 ) ,
F_181 ( V_252 ) )
) ;
return - V_235 ;
}
static void F_182 ( struct V_11 * V_29 , struct V_257 * V_258 )
{
int V_259 = 0 ;
char * V_260 [ 3 ] ;
switch ( V_258 -> V_261 ) {
case V_262 :
V_260 [ V_259 ++ ] = L_31 ;
break;
case V_263 :
V_260 [ V_259 ++ ] = L_32 ;
break;
case V_264 :
V_260 [ V_259 ++ ] = L_33 ;
break;
case V_265 :
V_260 [ V_259 ++ ] = L_34 ;
break;
case V_266 :
V_260 [ V_259 ++ ] = L_35 ;
break;
case V_267 :
V_260 [ V_259 ++ ] = L_36 ;
break;
default:
break;
}
V_260 [ V_259 ++ ] = NULL ;
F_183 ( & V_29 -> V_81 . V_268 , V_269 , V_260 ) ;
}
void F_184 ( struct V_79 * V_80 )
{
struct V_11 * V_29 ;
enum V_270 V_261 ;
F_40 ( V_271 ) ;
V_29 = F_50 ( V_80 , struct V_11 , V_272 ) ;
for ( V_261 = V_273 ; V_261 <= V_274 ; V_261 ++ )
if ( F_185 ( V_261 , V_29 -> V_275 ) )
F_186 ( V_29 , V_261 , V_236 ) ;
while ( 1 ) {
struct V_257 * V_258 ;
struct V_276 * V_277 , * V_68 ;
unsigned long V_16 ;
F_8 ( & V_29 -> V_278 , V_16 ) ;
F_41 ( & V_29 -> V_271 , & V_271 ) ;
F_11 ( & V_29 -> V_278 , V_16 ) ;
if ( F_42 ( & V_271 ) )
break;
F_187 (this, tmp, &event_list) {
V_258 = F_43 ( V_277 , struct V_257 , V_279 ) ;
F_188 ( & V_258 -> V_279 ) ;
F_182 ( V_29 , V_258 ) ;
F_23 ( V_258 ) ;
}
}
}
void F_189 ( struct V_11 * V_29 , struct V_257 * V_258 )
{
unsigned long V_16 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_8 ( & V_29 -> V_278 , V_16 ) ;
F_117 ( & V_258 -> V_279 , & V_29 -> V_271 ) ;
F_190 ( & V_29 -> V_272 ) ;
F_11 ( & V_29 -> V_278 , V_16 ) ;
}
struct V_257 * F_191 ( enum V_270 V_261 ,
T_1 V_280 )
{
struct V_257 * V_258 = F_21 ( sizeof( struct V_257 ) , V_280 ) ;
if ( ! V_258 )
return NULL ;
V_258 -> V_261 = V_261 ;
F_125 ( & V_258 -> V_279 ) ;
switch ( V_261 ) {
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
default:
break;
}
return V_258 ;
}
void F_186 ( struct V_11 * V_29 ,
enum V_270 V_261 , T_1 V_280 )
{
struct V_257 * V_258 = F_191 ( V_261 , V_280 ) ;
if ( ! V_258 ) {
F_109 ( V_172 , V_29 , L_37 ,
V_261 ) ;
return;
}
F_189 ( V_29 , V_258 ) ;
}
int
F_192 ( struct V_11 * V_29 )
{
int V_281 = F_179 ( V_29 , V_175 ) ;
if ( V_281 )
return V_281 ;
F_39 ( V_29 -> V_14 ) ;
while ( V_29 -> V_66 ) {
F_193 ( 200 ) ;
F_39 ( V_29 -> V_14 ) ;
}
return 0 ;
}
void F_194 ( struct V_11 * V_29 )
{
if ( V_29 -> V_168 != V_175 ||
F_179 ( V_29 , V_169 ) )
return;
F_39 ( V_29 -> V_14 ) ;
}
static void
F_195 ( struct V_11 * V_29 , void * V_232 )
{
F_192 ( V_29 ) ;
}
void
F_196 ( struct V_12 * V_13 )
{
F_197 ( V_13 , NULL , F_195 ) ;
}
static void
F_198 ( struct V_11 * V_29 , void * V_232 )
{
F_194 ( V_29 ) ;
}
void
F_199 ( struct V_12 * V_13 )
{
F_197 ( V_13 , NULL , F_198 ) ;
}
int
F_200 ( struct V_11 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_14 ;
unsigned long V_16 ;
int V_281 = 0 ;
V_281 = F_179 ( V_29 , V_176 ) ;
if ( V_281 ) {
V_281 = F_179 ( V_29 , V_177 ) ;
if ( V_281 )
return V_281 ;
}
F_8 ( V_15 -> V_27 , V_16 ) ;
F_201 ( V_15 ) ;
F_11 ( V_15 -> V_27 , V_16 ) ;
return 0 ;
}
int
F_202 ( struct V_11 * V_29 ,
enum V_251 V_282 )
{
struct V_14 * V_15 = V_29 -> V_14 ;
unsigned long V_16 ;
if ( ( V_29 -> V_168 == V_176 ) ||
( V_29 -> V_168 == V_171 ) )
V_29 -> V_168 = V_282 ;
else if ( V_29 -> V_168 == V_177 ) {
if ( V_282 == V_171 ||
V_282 == V_170 )
V_29 -> V_168 = V_282 ;
else
V_29 -> V_168 = V_254 ;
} else if ( V_29 -> V_168 != V_256 &&
V_29 -> V_168 != V_170 )
return - V_235 ;
F_8 ( V_15 -> V_27 , V_16 ) ;
F_203 ( V_15 ) ;
F_11 ( V_15 -> V_27 , V_16 ) ;
return 0 ;
}
static void
F_204 ( struct V_11 * V_29 , void * V_232 )
{
F_200 ( V_29 ) ;
}
static int
F_205 ( struct V_10 * V_208 , void * V_232 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , NULL ,
F_204 ) ;
return 0 ;
}
void
F_208 ( struct V_10 * V_208 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , NULL ,
F_204 ) ;
else
F_209 ( V_208 , NULL , F_205 ) ;
}
static void
F_210 ( struct V_11 * V_29 , void * V_232 )
{
F_202 ( V_29 , * (enum V_251 * ) V_232 ) ;
}
static int
F_211 ( struct V_10 * V_208 , void * V_232 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , V_232 ,
F_210 ) ;
return 0 ;
}
void
F_212 ( struct V_10 * V_208 , enum V_251 V_282 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , & V_282 ,
F_210 ) ;
else
F_209 ( V_208 , & V_282 , F_211 ) ;
}
void * F_213 ( struct V_87 * V_88 , int V_283 ,
T_5 * V_284 , T_5 * V_123 )
{
int V_219 ;
T_5 V_285 = 0 , V_286 = 0 ;
struct V_87 * V_287 ;
struct V_288 * V_288 ;
F_214 ( ! F_215 () ) ;
F_216 (sgl, sg, sg_count, i) {
V_286 = V_285 ;
V_285 += V_287 -> V_148 ;
if ( V_285 > * V_284 )
break;
}
if ( F_18 ( V_219 == V_283 ) ) {
F_6 ( V_172 L_38
L_39 ,
V_196 , V_285 , * V_284 , V_283 ) ;
F_214 ( 1 ) ;
return NULL ;
}
* V_284 = * V_284 - V_286 + V_287 -> V_284 ;
V_288 = F_217 ( F_218 ( V_287 ) , ( * V_284 >> V_206 ) ) ;
* V_284 &= ~ V_289 ;
V_285 = V_290 - * V_284 ;
if ( * V_123 > V_285 )
* V_123 = V_285 ;
return F_219 ( V_288 ) ;
}
void F_220 ( void * V_291 )
{
F_221 ( V_291 ) ;
}
void F_222 ( struct V_11 * V_29 )
{
F_122 ( & V_29 -> V_292 ) ;
}
void F_223 ( struct V_11 * V_29 )
{
if ( F_224 ( F_225 ( & V_29 -> V_292 ) <= 0 ) )
return;
F_226 ( & V_29 -> V_292 ) ;
}
