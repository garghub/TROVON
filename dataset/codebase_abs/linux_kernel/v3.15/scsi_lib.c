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
F_7 ( V_12 , & V_7 -> V_27 ) ;
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
if ( V_31 && F_12 ( V_28 -> V_11 , V_36 ,
V_30 , V_31 , V_41 ) )
goto V_42;
V_36 -> V_43 = F_13 ( V_2 [ 0 ] ) ;
memcpy ( V_36 -> V_2 , V_2 , V_36 -> V_43 ) ;
V_36 -> V_32 = V_32 ;
V_36 -> V_44 = 0 ;
V_36 -> V_34 = V_34 ;
V_36 -> V_33 = V_33 ;
V_36 -> V_45 = V_46 ;
V_36 -> V_47 |= V_13 | V_48 | V_49 ;
F_14 ( V_36 -> V_12 , NULL , V_36 , 1 ) ;
if ( F_15 ( V_36 -> V_50 > 0 && V_36 -> V_50 <= V_31 ) )
memset ( V_30 + ( V_31 - V_36 -> V_50 ) , 0 , V_36 -> V_50 ) ;
if ( V_35 )
* V_35 = V_36 -> V_50 ;
V_39 = V_36 -> V_51 ;
V_42:
F_16 ( V_36 ) ;
return V_39 ;
}
int F_17 ( struct V_8 * V_28 , const unsigned char * V_2 ,
int V_29 , void * V_30 , unsigned V_31 ,
struct V_52 * V_53 , int V_33 , int V_34 ,
int * V_35 , T_1 V_13 )
{
char * V_32 = NULL ;
int V_24 ;
if ( V_53 ) {
V_32 = F_18 ( V_54 , V_55 ) ;
if ( ! V_32 )
return V_40 << 24 ;
}
V_24 = F_10 ( V_28 , V_2 , V_29 , V_30 , V_31 ,
V_32 , V_33 , V_34 , V_13 , V_35 ) ;
if ( V_53 )
F_19 ( V_32 , V_54 , V_53 ) ;
F_20 ( V_32 ) ;
return V_24 ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_56 = 0 ;
F_22 ( V_2 , 0 ) ;
memset ( V_2 -> V_57 , 0 , V_54 ) ;
if ( V_2 -> V_43 == 0 )
V_2 -> V_43 = F_23 ( V_2 -> V_58 ) ;
}
void F_4 ( struct V_8 * V_28 )
{
struct V_5 * V_59 = V_28 -> V_6 ;
struct V_9 * V_10 = V_9 ( V_28 ) ;
unsigned long V_13 ;
F_5 ( V_59 -> V_60 , V_13 ) ;
V_59 -> V_61 -- ;
V_10 -> V_62 -- ;
if ( F_15 ( F_24 ( V_59 ) &&
( V_59 -> V_63 || V_59 -> V_64 ) ) )
F_25 ( V_59 ) ;
F_26 ( V_59 -> V_60 ) ;
F_27 ( V_28 -> V_11 -> V_25 ) ;
V_28 -> V_65 -- ;
F_8 ( V_28 -> V_11 -> V_25 , V_13 ) ;
}
static void F_28 ( struct V_8 * V_66 )
{
struct V_5 * V_59 = V_66 -> V_6 ;
struct V_8 * V_28 , * V_67 ;
struct V_9 * V_10 = V_9 ( V_66 ) ;
unsigned long V_13 ;
F_5 ( V_59 -> V_60 , V_13 ) ;
V_10 -> V_68 = NULL ;
F_8 ( V_59 -> V_60 , V_13 ) ;
F_29 ( V_66 -> V_11 ) ;
F_5 ( V_59 -> V_60 , V_13 ) ;
if ( V_10 -> V_68 )
goto V_42;
F_30 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_28 == V_66 )
continue;
if ( F_31 ( V_28 ) )
continue;
F_8 ( V_59 -> V_60 , V_13 ) ;
F_29 ( V_28 -> V_11 ) ;
F_5 ( V_59 -> V_60 , V_13 ) ;
F_32 ( V_28 ) ;
}
V_42:
F_8 ( V_59 -> V_60 , V_13 ) ;
}
static inline int F_33 ( struct V_8 * V_28 )
{
if ( V_28 -> V_65 >= V_28 -> V_69 || V_28 -> V_19 )
return 1 ;
return 0 ;
}
static inline int F_34 ( struct V_9 * V_10 )
{
return ( ( V_10 -> V_70 > 0 &&
V_10 -> V_62 >= V_10 -> V_70 ) ||
V_10 -> V_22 ) ;
}
static inline int F_35 ( struct V_5 * V_59 )
{
if ( ( V_59 -> V_70 > 0 && V_59 -> V_61 >= V_59 -> V_70 ) ||
V_59 -> V_15 || V_59 -> V_71 )
return 1 ;
return 0 ;
}
static void F_36 ( struct V_5 * V_59 )
{
F_37 ( V_72 ) ;
struct V_8 * V_28 ;
unsigned long V_13 ;
F_5 ( V_59 -> V_60 , V_13 ) ;
F_38 ( & V_59 -> V_72 , & V_72 ) ;
while ( ! F_39 ( & V_72 ) ) {
struct V_11 * V_73 ;
if ( F_35 ( V_59 ) )
break;
V_28 = F_40 ( V_72 . V_74 ,
struct V_8 , V_75 ) ;
F_41 ( & V_28 -> V_75 ) ;
if ( F_34 ( V_9 ( V_28 ) ) ) {
F_42 ( & V_28 -> V_75 ,
& V_59 -> V_72 ) ;
continue;
}
V_73 = V_28 -> V_11 ;
if ( ! F_43 ( V_73 ) )
continue;
F_8 ( V_59 -> V_60 , V_13 ) ;
F_29 ( V_73 ) ;
F_44 ( V_73 ) ;
F_5 ( V_59 -> V_60 , V_13 ) ;
}
F_45 ( & V_72 , & V_59 -> V_72 ) ;
F_8 ( V_59 -> V_60 , V_13 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
struct V_8 * V_28 = V_12 -> V_76 ;
if ( V_9 ( V_28 ) -> V_77 )
F_28 ( V_28 ) ;
if ( ! F_39 ( & V_28 -> V_6 -> V_72 ) )
F_36 ( V_28 -> V_6 ) ;
F_29 ( V_12 ) ;
}
void F_47 ( struct V_78 * V_79 )
{
struct V_8 * V_28 ;
struct V_11 * V_12 ;
V_28 = F_48 ( V_79 , struct V_8 , V_27 ) ;
V_12 = V_28 -> V_11 ;
F_46 ( V_12 ) ;
}
static void F_49 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_8 * V_28 = V_2 -> V_7 ;
struct V_26 * V_36 = V_2 -> V_26 ;
unsigned long V_13 ;
F_5 ( V_12 -> V_25 , V_13 ) ;
F_50 ( V_36 ) ;
V_36 -> V_80 = NULL ;
F_51 ( V_2 ) ;
F_6 ( V_12 , V_36 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
F_46 ( V_12 ) ;
F_52 ( & V_28 -> V_81 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_28 = V_2 -> V_7 ;
struct V_11 * V_12 = V_28 -> V_11 ;
F_51 ( V_2 ) ;
F_46 ( V_12 ) ;
F_52 ( & V_28 -> V_81 ) ;
}
void F_54 ( struct V_5 * V_59 )
{
struct V_8 * V_28 ;
F_55 (sdev, shost)
F_46 ( V_28 -> V_11 ) ;
}
static struct V_1 * F_56 ( struct V_1 * V_2 , int error ,
int V_82 , int V_83 )
{
struct V_11 * V_12 = V_2 -> V_7 -> V_11 ;
struct V_26 * V_36 = V_2 -> V_26 ;
if ( F_57 ( V_36 , error , V_82 ) ) {
if ( error && F_58 ( V_2 ) )
F_59 ( V_36 , error ) ;
else {
if ( V_83 ) {
F_60 ( V_2 ) ;
F_49 ( V_12 , V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
}
F_61 ( V_2 , 0 ) ;
F_53 ( V_2 ) ;
return NULL ;
}
static inline unsigned int F_62 ( unsigned short V_84 )
{
unsigned int V_85 ;
F_63 ( V_84 > V_86 ) ;
if ( V_84 <= 8 )
V_85 = 0 ;
else
V_85 = F_64 ( V_84 ) - 3 ;
return V_85 ;
}
static void F_65 ( struct V_87 * V_88 , unsigned int V_84 )
{
struct V_89 * V_90 ;
V_90 = V_91 + F_62 ( V_84 ) ;
F_66 ( V_88 , V_90 -> V_92 ) ;
}
static struct V_87 * F_67 ( unsigned int V_84 , T_2 V_93 )
{
struct V_89 * V_90 ;
V_90 = V_91 + F_62 ( V_84 ) ;
return F_68 ( V_90 -> V_92 , V_93 ) ;
}
static int F_69 ( struct V_94 * V_95 , int V_84 ,
T_2 V_93 )
{
int V_39 ;
F_63 ( ! V_84 ) ;
V_39 = F_70 ( & V_95 -> V_96 , V_84 , V_86 ,
V_93 , F_67 ) ;
if ( F_15 ( V_39 ) )
F_71 ( & V_95 -> V_96 , V_86 ,
F_65 ) ;
return V_39 ;
}
static void F_72 ( struct V_94 * V_95 )
{
F_71 ( & V_95 -> V_96 , V_86 , F_65 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_97 )
{
if ( V_2 -> V_95 . V_96 . V_84 )
F_72 ( & V_2 -> V_95 ) ;
memset ( & V_2 -> V_95 , 0 , sizeof( V_2 -> V_95 ) ) ;
if ( V_97 && F_73 ( V_2 ) ) {
struct V_94 * V_98 =
V_2 -> V_26 -> V_99 -> V_80 ;
F_72 ( V_98 ) ;
F_74 ( V_100 , V_98 ) ;
V_2 -> V_26 -> V_99 -> V_80 = NULL ;
}
if ( F_75 ( V_2 ) )
F_72 ( V_2 -> V_101 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 , 1 ) ;
}
static int F_76 ( struct V_1 * V_2 , int V_24 )
{
int error = 0 ;
switch( F_77 ( V_24 ) ) {
case V_102 :
error = - V_103 ;
break;
case V_104 :
F_78 ( V_2 , V_105 ) ;
error = - V_106 ;
break;
case V_107 :
F_78 ( V_2 , V_105 ) ;
error = - V_108 ;
break;
case V_109 :
F_78 ( V_2 , V_105 ) ;
error = - V_110 ;
break;
case V_111 :
F_78 ( V_2 , V_105 ) ;
error = - V_112 ;
break;
default:
error = - V_113 ;
break;
}
return error ;
}
void F_79 ( struct V_1 * V_2 , unsigned int V_114 )
{
int V_24 = V_2 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_7 -> V_11 ;
struct V_26 * V_36 = V_2 -> V_26 ;
int error = 0 ;
struct V_52 V_53 ;
int V_115 = 0 ;
int V_116 = 0 ;
enum { V_117 , V_118 , V_119 ,
V_120 } V_121 ;
char * V_122 = NULL ;
unsigned long V_123 = ( V_2 -> V_124 + 1 ) * V_36 -> V_33 ;
if ( V_24 ) {
V_115 = F_80 ( V_2 , & V_53 ) ;
if ( V_115 )
V_116 = F_81 ( & V_53 ) ;
}
if ( V_36 -> V_45 == V_46 ) {
if ( V_24 ) {
if ( V_115 && V_36 -> V_32 ) {
int V_125 = 8 + V_2 -> V_57 [ 7 ] ;
if ( V_125 > V_54 )
V_125 = V_54 ;
memcpy ( V_36 -> V_32 , V_2 -> V_57 , V_125 ) ;
V_36 -> V_44 = V_125 ;
}
if ( ! V_116 )
error = F_76 ( V_2 , V_24 ) ;
}
V_36 -> V_51 = V_2 -> V_24 ;
V_36 -> V_50 = F_82 ( V_2 ) ;
if ( F_73 ( V_2 ) ) {
V_36 -> V_99 -> V_50 = F_83 ( V_2 ) -> V_35 ;
F_60 ( V_2 ) ;
F_59 ( V_36 , 0 ) ;
F_53 ( V_2 ) ;
return;
}
}
F_63 ( F_84 ( V_36 ) ) ;
F_85 ( 1 , F_3 ( L_2
L_3 ,
F_86 ( V_36 ) , V_114 ) ) ;
if ( V_115 && ( V_53 . V_126 == V_127 ) ) {
if ( ( V_53 . V_128 == 0x0 ) && ( V_53 . V_129 == 0x1d ) )
;
else if ( ! ( V_36 -> V_47 & V_48 ) )
F_87 ( L_4 , V_2 ) ;
V_24 = 0 ;
error = 0 ;
}
if ( F_56 ( V_2 , error , V_114 , V_24 == 0 ) == NULL )
return;
error = F_76 ( V_2 , V_24 ) ;
if ( F_77 ( V_24 ) == V_130 ) {
V_121 = V_119 ;
} else if ( V_115 && ! V_116 ) {
switch ( V_53 . V_126 ) {
case V_131 :
if ( V_2 -> V_7 -> V_132 ) {
V_2 -> V_7 -> V_133 = 1 ;
V_122 = L_5 ;
V_121 = V_117 ;
} else {
V_121 = V_119 ;
}
break;
case V_134 :
if ( ( V_2 -> V_7 -> V_135 &&
V_53 . V_128 == 0x20 && V_53 . V_129 == 0x00 ) &&
( V_2 -> V_58 [ 0 ] == V_136 ||
V_2 -> V_58 [ 0 ] == V_137 ) ) {
V_2 -> V_7 -> V_135 = 0 ;
V_121 = V_118 ;
} else if ( V_53 . V_128 == 0x10 ) {
V_122 = L_6 ;
V_121 = V_117 ;
error = - V_138 ;
} else if ( V_53 . V_128 == 0x20 || V_53 . V_128 == 0x24 ) {
switch ( V_2 -> V_58 [ 0 ] ) {
case V_139 :
V_122 = L_7 ;
break;
case V_140 :
case V_141 :
if ( V_2 -> V_58 [ 1 ] & 0x8 )
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
case V_142 :
V_121 = V_117 ;
if ( V_53 . V_128 == 0x10 ) {
V_122 = L_10 ;
error = - V_138 ;
}
break;
case V_143 :
if ( V_53 . V_128 == 0x04 ) {
switch ( V_53 . V_129 ) {
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
case V_144 :
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
if ( V_121 != V_117 &&
F_88 ( V_2 -> V_145 + V_123 , V_146 ) ) {
V_121 = V_117 ;
V_122 = L_14 ;
}
switch ( V_121 ) {
case V_117 :
F_60 ( V_2 ) ;
if ( ! ( V_36 -> V_47 & V_48 ) ) {
if ( V_122 )
F_89 ( V_147 , V_2 , L_15 ,
V_122 ) ;
F_90 ( V_2 ) ;
if ( F_91 ( V_24 ) & V_148 )
F_87 ( L_4 , V_2 ) ;
F_92 ( V_2 ) ;
}
if ( F_93 ( V_36 , error ) )
F_49 ( V_12 , V_2 ) ;
else
F_53 ( V_2 ) ;
break;
case V_118 :
F_60 ( V_2 ) ;
F_49 ( V_12 , V_2 ) ;
break;
case V_119 :
F_1 ( V_2 , V_18 , 0 ) ;
break;
case V_120 :
F_1 ( V_2 , V_17 , 0 ) ;
break;
}
}
static int F_94 ( struct V_26 * V_36 , struct V_94 * V_95 ,
T_2 V_93 )
{
int V_149 ;
if ( F_15 ( F_69 ( V_95 , V_36 -> V_150 ,
V_93 ) ) ) {
return V_151 ;
}
V_36 -> V_30 = NULL ;
V_149 = F_95 ( V_36 -> V_12 , V_36 , V_95 -> V_96 . V_88 ) ;
F_63 ( V_149 > V_95 -> V_96 . V_84 ) ;
V_95 -> V_96 . V_84 = V_149 ;
V_95 -> V_152 = F_96 ( V_36 ) ;
return V_153 ;
}
int F_97 ( struct V_1 * V_2 , T_2 V_93 )
{
struct V_8 * V_28 = V_2 -> V_7 ;
struct V_26 * V_154 = V_2 -> V_26 ;
int error = F_94 ( V_154 , & V_2 -> V_95 , V_93 ) ;
if ( error )
goto V_155;
if ( F_84 ( V_154 ) ) {
struct V_94 * V_98 = F_98 (
V_100 , V_156 ) ;
if ( ! V_98 ) {
error = V_151 ;
goto V_155;
}
V_154 -> V_99 -> V_80 = V_98 ;
error = F_94 ( V_154 -> V_99 , V_98 , V_156 ) ;
if ( error )
goto V_155;
}
if ( F_99 ( V_154 ) ) {
struct V_94 * V_101 = V_2 -> V_101 ;
int V_157 , V_149 ;
F_63 ( V_101 == NULL ) ;
V_157 = F_100 ( V_154 -> V_12 , V_154 -> V_158 ) ;
if ( F_69 ( V_101 , V_157 , V_93 ) ) {
error = V_151 ;
goto V_155;
}
V_149 = F_101 ( V_154 -> V_12 , V_154 -> V_158 ,
V_101 -> V_96 . V_88 ) ;
F_63 ( F_15 ( V_149 > V_157 ) ) ;
F_63 ( F_15 ( V_149 > F_102 ( V_154 -> V_12 ) ) ) ;
V_2 -> V_101 = V_101 ;
V_2 -> V_101 -> V_96 . V_84 = V_149 ;
}
return V_153 ;
V_155:
F_60 ( V_2 ) ;
V_2 -> V_26 -> V_80 = NULL ;
F_51 ( V_2 ) ;
F_52 ( & V_28 -> V_81 ) ;
return error ;
}
static struct V_1 * F_103 ( struct V_8 * V_28 ,
struct V_26 * V_36 )
{
struct V_1 * V_2 ;
if ( ! V_36 -> V_80 ) {
if ( ! F_104 ( & V_28 -> V_81 ) )
return NULL ;
V_2 = F_105 ( V_28 , V_156 ) ;
if ( F_15 ( ! V_2 ) ) {
F_52 ( & V_28 -> V_81 ) ;
return NULL ;
}
V_36 -> V_80 = V_2 ;
} else {
V_2 = V_36 -> V_80 ;
}
V_2 -> V_159 = V_36 -> V_159 ;
V_2 -> V_26 = V_36 ;
V_2 -> V_58 = V_36 -> V_2 ;
V_2 -> V_160 = V_161 ;
return V_2 ;
}
int F_106 ( struct V_8 * V_28 , struct V_26 * V_36 )
{
struct V_1 * V_2 ;
int V_39 = F_107 ( V_28 , V_36 ) ;
if ( V_39 != V_153 )
return V_39 ;
V_2 = F_103 ( V_28 , V_36 ) ;
if ( F_15 ( ! V_2 ) )
return V_151 ;
if ( V_36 -> V_158 ) {
int V_39 ;
F_63 ( ! V_36 -> V_150 ) ;
V_39 = F_97 ( V_2 , V_156 ) ;
if ( F_15 ( V_39 ) )
return V_39 ;
} else {
F_63 ( F_96 ( V_36 ) ) ;
memset ( & V_2 -> V_95 , 0 , sizeof( V_2 -> V_95 ) ) ;
V_36 -> V_30 = NULL ;
}
V_2 -> V_43 = V_36 -> V_43 ;
if ( ! F_96 ( V_36 ) )
V_2 -> V_162 = V_163 ;
else if ( F_108 ( V_36 ) == V_164 )
V_2 -> V_162 = V_38 ;
else
V_2 -> V_162 = V_165 ;
V_2 -> V_166 = F_96 ( V_36 ) ;
V_2 -> V_124 = V_36 -> V_34 ;
return V_153 ;
}
int F_109 ( struct V_8 * V_28 , struct V_26 * V_36 )
{
struct V_1 * V_2 ;
int V_39 = F_107 ( V_28 , V_36 ) ;
if ( V_39 != V_153 )
return V_39 ;
if ( F_15 ( V_28 -> V_167 && V_28 -> V_167 -> V_168
&& V_28 -> V_167 -> V_168 -> V_169 ) ) {
V_39 = V_28 -> V_167 -> V_168 -> V_169 ( V_28 , V_36 ) ;
if ( V_39 != V_153 )
return V_39 ;
}
F_63 ( ! V_36 -> V_150 ) ;
V_2 = F_103 ( V_28 , V_36 ) ;
if ( F_15 ( ! V_2 ) )
return V_151 ;
memset ( V_2 -> V_58 , 0 , V_170 ) ;
return F_97 ( V_2 , V_156 ) ;
}
int F_107 ( struct V_8 * V_28 , struct V_26 * V_36 )
{
int V_39 = V_153 ;
if ( F_15 ( V_28 -> V_171 != V_172 ) ) {
switch ( V_28 -> V_171 ) {
case V_173 :
case V_174 :
F_110 ( V_175 , V_28 ,
L_16 ) ;
V_39 = V_176 ;
break;
case V_177 :
F_110 ( V_175 , V_28 ,
L_17 ) ;
V_39 = V_176 ;
break;
case V_178 :
case V_179 :
case V_180 :
if ( ! ( V_36 -> V_47 & V_49 ) )
V_39 = V_151 ;
break;
default:
if ( ! ( V_36 -> V_47 & V_49 ) )
V_39 = V_176 ;
break;
}
}
return V_39 ;
}
int F_111 ( struct V_11 * V_12 , struct V_26 * V_36 , int V_39 )
{
struct V_8 * V_28 = V_12 -> V_76 ;
switch ( V_39 ) {
case V_176 :
V_36 -> V_51 = V_181 << 16 ;
if ( V_36 -> V_80 ) {
struct V_1 * V_2 = V_36 -> V_80 ;
F_60 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( & V_28 -> V_81 ) ;
V_36 -> V_80 = NULL ;
}
break;
case V_151 :
if ( V_28 -> V_65 == 0 )
F_112 ( V_12 , V_182 ) ;
break;
default:
V_36 -> V_47 |= V_183 ;
}
return V_39 ;
}
int F_113 ( struct V_11 * V_12 , struct V_26 * V_36 )
{
struct V_8 * V_28 = V_12 -> V_76 ;
int V_39 = V_176 ;
if ( V_36 -> V_45 == V_46 )
V_39 = F_106 ( V_28 , V_36 ) ;
return F_111 ( V_12 , V_36 , V_39 ) ;
}
static inline int F_114 ( struct V_11 * V_12 ,
struct V_8 * V_28 )
{
if ( V_28 -> V_65 == 0 && V_28 -> V_19 ) {
if ( -- V_28 -> V_19 == 0 ) {
F_2 ( 3 ,
F_110 ( V_147 , V_28 ,
L_18 ) ) ;
} else {
F_112 ( V_12 , V_182 ) ;
return 0 ;
}
}
if ( F_33 ( V_28 ) )
return 0 ;
return 1 ;
}
static inline int F_115 ( struct V_5 * V_59 ,
struct V_8 * V_28 )
{
struct V_9 * V_10 = V_9 ( V_28 ) ;
if ( V_10 -> V_77 ) {
if ( V_10 -> V_68 &&
V_10 -> V_68 != V_28 )
return 0 ;
V_10 -> V_68 = V_28 ;
}
if ( V_10 -> V_62 == 0 && V_10 -> V_22 ) {
if ( -- V_10 -> V_22 == 0 ) {
F_2 ( 3 , F_116 ( V_147 , V_10 ,
L_19 ) ) ;
} else
return 0 ;
}
if ( F_34 ( V_10 ) ) {
F_42 ( & V_28 -> V_75 , & V_59 -> V_72 ) ;
return 0 ;
}
return 1 ;
}
static inline int F_117 ( struct V_11 * V_12 ,
struct V_5 * V_59 ,
struct V_8 * V_28 )
{
if ( F_24 ( V_59 ) )
return 0 ;
if ( V_59 -> V_61 == 0 && V_59 -> V_15 ) {
if ( -- V_59 -> V_15 == 0 ) {
F_2 ( 3 ,
F_3 ( L_20 ,
V_59 -> V_184 ) ) ;
} else {
return 0 ;
}
}
if ( F_35 ( V_59 ) ) {
if ( F_39 ( & V_28 -> V_75 ) )
F_118 ( & V_28 -> V_75 , & V_59 -> V_72 ) ;
return 0 ;
}
if ( ! F_39 ( & V_28 -> V_75 ) )
F_41 ( & V_28 -> V_75 ) ;
return 1 ;
}
static int F_119 ( struct V_11 * V_12 )
{
struct V_8 * V_28 = V_12 -> V_76 ;
struct V_5 * V_59 ;
if ( F_120 ( V_12 ) )
return 0 ;
V_59 = V_28 -> V_6 ;
if ( F_24 ( V_59 ) || F_33 ( V_28 ) )
return 1 ;
return 0 ;
}
static void F_121 ( struct V_26 * V_36 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_36 -> V_80 ;
struct V_8 * V_28 ;
struct V_9 * V_10 ;
struct V_5 * V_59 ;
F_122 ( V_36 ) ;
F_89 ( V_147 , V_2 , L_21 ) ;
V_28 = V_2 -> V_7 ;
V_10 = V_9 ( V_28 ) ;
V_59 = V_28 -> V_6 ;
F_21 ( V_2 ) ;
V_2 -> V_24 = V_181 << 16 ;
F_123 ( & V_2 -> V_7 -> V_185 ) ;
V_28 -> V_65 ++ ;
F_26 ( V_28 -> V_11 -> V_25 ) ;
F_27 ( V_59 -> V_60 ) ;
V_59 -> V_61 ++ ;
V_10 -> V_62 ++ ;
F_26 ( V_59 -> V_60 ) ;
F_27 ( V_28 -> V_11 -> V_25 ) ;
F_124 ( V_36 ) ;
}
static void F_125 ( struct V_26 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_80 ;
unsigned long V_123 = ( V_2 -> V_124 + 1 ) * V_154 -> V_33 ;
int V_186 ;
F_126 ( & V_2 -> V_187 ) ;
F_123 ( & V_2 -> V_7 -> V_188 ) ;
if ( V_2 -> V_24 )
F_123 ( & V_2 -> V_7 -> V_189 ) ;
V_186 = F_127 ( V_2 ) ;
if ( V_186 != V_190 &&
F_88 ( V_2 -> V_145 + V_123 , V_146 ) ) {
F_110 ( V_175 , V_2 -> V_7 ,
L_22 ,
V_123 / V_191 ) ;
V_186 = V_190 ;
}
F_128 ( V_2 , V_186 ) ;
switch ( V_186 ) {
case V_190 :
F_129 ( V_2 ) ;
break;
case V_192 :
F_9 ( V_2 , V_18 ) ;
break;
case V_193 :
F_9 ( V_2 , V_17 ) ;
break;
default:
if ( ! F_130 ( V_2 , 0 ) )
F_129 ( V_2 ) ;
}
}
static void F_131 ( struct V_11 * V_12 )
__releases( V_12 -> V_25 )
__acquires( V_12 -> V_25 )
{
struct V_8 * V_28 = V_12 -> V_76 ;
struct V_5 * V_59 ;
struct V_1 * V_2 ;
struct V_26 * V_36 ;
V_59 = V_28 -> V_6 ;
for (; ; ) {
int V_194 ;
V_36 = F_132 ( V_12 ) ;
if ( ! V_36 || ! F_114 ( V_12 , V_28 ) )
break;
if ( F_15 ( ! F_133 ( V_28 ) ) ) {
F_110 ( V_175 , V_28 ,
L_16 ) ;
F_121 ( V_36 , V_12 ) ;
continue;
}
if ( ! ( F_134 ( V_12 ) && ! F_135 ( V_12 , V_36 ) ) )
F_122 ( V_36 ) ;
V_28 -> V_65 ++ ;
F_26 ( V_12 -> V_25 ) ;
V_2 = V_36 -> V_80 ;
if ( F_15 ( V_2 == NULL ) ) {
F_3 ( V_195 L_23
L_24
L_25 ,
V_196 ) ;
F_136 ( V_36 , L_26 ) ;
F_137 () ;
}
F_27 ( V_59 -> V_60 ) ;
if ( F_134 ( V_12 ) && ! F_138 ( V_36 ) ) {
if ( F_39 ( & V_28 -> V_75 ) )
F_118 ( & V_28 -> V_75 ,
& V_59 -> V_72 ) ;
goto V_197;
}
if ( ! F_115 ( V_59 , V_28 ) )
goto V_197;
if ( ! F_117 ( V_12 , V_59 , V_28 ) )
goto V_197;
V_9 ( V_28 ) -> V_62 ++ ;
V_59 -> V_61 ++ ;
F_139 ( V_59 -> V_60 ) ;
F_21 ( V_2 ) ;
V_194 = F_140 ( V_2 ) ;
F_141 ( V_12 -> V_25 ) ;
if ( V_194 )
goto V_198;
}
return;
V_197:
F_139 ( V_59 -> V_60 ) ;
F_141 ( V_12 -> V_25 ) ;
F_6 ( V_12 , V_36 ) ;
V_28 -> V_65 -- ;
V_198:
if ( V_28 -> V_65 == 0 )
F_112 ( V_12 , V_182 ) ;
}
T_1 F_142 ( struct V_5 * V_59 )
{
struct V_7 * V_199 ;
T_1 V_200 = 0xffffffff ;
if ( V_59 -> V_201 )
return V_202 ;
if ( ! V_203 )
return V_204 ;
V_199 = F_143 ( V_59 ) ;
if ( V_199 && V_199 -> V_205 )
V_200 = ( T_1 ) F_144 ( V_199 ) << V_206 ;
return V_200 ;
}
struct V_11 * F_145 ( struct V_5 * V_59 ,
T_3 * V_207 )
{
struct V_11 * V_12 ;
struct V_7 * V_208 = V_59 -> V_209 ;
V_12 = F_146 ( V_207 , NULL ) ;
if ( ! V_12 )
return NULL ;
F_147 ( V_12 , F_148 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_149 ( V_59 ) ) {
V_59 -> V_210 =
F_150 ( V_59 -> V_210 ,
( unsigned short ) V_211 ) ;
F_63 ( V_59 -> V_210 < V_59 -> V_212 ) ;
F_151 ( V_12 , V_59 -> V_210 ) ;
}
F_152 ( V_12 , V_59 -> V_213 ) ;
F_153 ( V_12 , F_142 ( V_59 ) ) ;
F_154 ( V_12 , V_59 -> V_214 ) ;
F_155 ( V_208 , V_59 -> V_214 ) ;
F_156 ( V_12 , F_157 ( V_208 ) ) ;
if ( ! V_59 -> V_215 )
V_12 -> V_216 . V_217 = 0 ;
F_158 ( V_12 , 0x03 ) ;
return V_12 ;
}
struct V_11 * F_159 ( struct V_8 * V_28 )
{
struct V_11 * V_12 ;
V_12 = F_145 ( V_28 -> V_6 , F_131 ) ;
if ( ! V_12 )
return NULL ;
F_160 ( V_12 , F_113 ) ;
F_161 ( V_12 , F_125 ) ;
F_162 ( V_12 , V_218 ) ;
F_163 ( V_12 , F_119 ) ;
return V_12 ;
}
void F_164 ( struct V_5 * V_59 )
{
V_59 -> V_71 = 1 ;
}
void F_165 ( struct V_5 * V_59 )
{
V_59 -> V_71 = 0 ;
F_54 ( V_59 ) ;
}
int T_4 F_166 ( void )
{
int V_219 ;
V_100 = F_167 ( L_27 ,
sizeof( struct V_94 ) ,
0 , 0 , NULL ) ;
if ( ! V_100 ) {
F_3 ( V_175 L_28 ) ;
return - V_220 ;
}
for ( V_219 = 0 ; V_219 < V_221 ; V_219 ++ ) {
struct V_89 * V_90 = V_91 + V_219 ;
int V_222 = V_90 -> V_222 * sizeof( struct V_87 ) ;
V_90 -> V_223 = F_167 ( V_90 -> V_224 , V_222 , 0 ,
V_225 , NULL ) ;
if ( ! V_90 -> V_223 ) {
F_3 ( V_175 L_29 ,
V_90 -> V_224 ) ;
goto V_226;
}
V_90 -> V_92 = F_168 ( V_227 ,
V_90 -> V_223 ) ;
if ( ! V_90 -> V_92 ) {
F_3 ( V_175 L_30 ,
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
F_172 ( struct V_8 * V_28 , int V_228 , int V_229 , int V_230 ,
unsigned char * V_30 , int V_125 , int V_33 , int V_34 ,
struct V_231 * V_232 , struct V_52 * V_53 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_233 ;
int V_39 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_228 ? 0x10 : 0 ) | ( V_229 ? 0x01 : 0 ) ;
if ( V_28 -> V_234 ) {
if ( V_125 > 65535 )
return - V_235 ;
V_233 = F_173 ( 8 + V_125 , V_236 ) ;
if ( ! V_233 )
return - V_220 ;
memcpy ( V_233 + 8 , V_30 , V_125 ) ;
V_125 += 8 ;
V_233 [ 0 ] = 0 ;
V_233 [ 1 ] = 0 ;
V_233 [ 2 ] = V_232 -> V_237 ;
V_233 [ 3 ] = V_232 -> V_238 ;
V_233 [ 4 ] = V_232 -> V_239 ? 0x01 : 0 ;
V_233 [ 5 ] = 0 ;
V_233 [ 6 ] = V_232 -> V_240 >> 8 ;
V_233 [ 7 ] = V_232 -> V_240 ;
V_2 [ 0 ] = V_241 ;
V_2 [ 7 ] = V_125 >> 8 ;
V_2 [ 8 ] = V_125 ;
} else {
if ( V_125 > 255 || V_232 -> V_240 > 255 ||
V_232 -> V_239 )
return - V_235 ;
V_233 = F_173 ( 4 + V_125 , V_236 ) ;
if ( ! V_233 )
return - V_220 ;
memcpy ( V_233 + 4 , V_30 , V_125 ) ;
V_125 += 4 ;
V_233 [ 0 ] = 0 ;
V_233 [ 1 ] = V_232 -> V_237 ;
V_233 [ 2 ] = V_232 -> V_238 ;
V_233 [ 3 ] = V_232 -> V_240 ;
V_2 [ 0 ] = V_242 ;
V_2 [ 4 ] = V_125 ;
}
V_39 = F_174 ( V_28 , V_2 , V_38 , V_233 , V_125 ,
V_53 , V_33 , V_34 , NULL ) ;
F_20 ( V_233 ) ;
return V_39 ;
}
int
F_175 ( struct V_8 * V_28 , int V_243 , int V_230 ,
unsigned char * V_30 , int V_125 , int V_33 , int V_34 ,
struct V_231 * V_232 , struct V_52 * V_53 )
{
unsigned char V_2 [ 12 ] ;
int V_234 ;
int V_244 ;
int V_24 ;
struct V_52 V_245 ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_243 & 0x18 ;
V_2 [ 2 ] = V_230 ;
if ( ! V_53 )
V_53 = & V_245 ;
V_246:
V_234 = V_28 -> V_234 ;
if ( V_234 ) {
if ( V_125 < 8 )
V_125 = 8 ;
V_2 [ 0 ] = V_247 ;
V_2 [ 8 ] = V_125 ;
V_244 = 8 ;
} else {
if ( V_125 < 4 )
V_125 = 4 ;
V_2 [ 0 ] = V_248 ;
V_2 [ 4 ] = V_125 ;
V_244 = 4 ;
}
memset ( V_30 , 0 , V_125 ) ;
V_24 = F_174 ( V_28 , V_2 , V_165 , V_30 , V_125 ,
V_53 , V_33 , V_34 , NULL ) ;
if ( V_234 && ! F_176 ( V_24 ) &&
( F_91 ( V_24 ) & V_148 ) ) {
if ( F_177 ( V_53 ) ) {
if ( ( V_53 -> V_126 == V_134 ) &&
( V_53 -> V_128 == 0x20 ) && ( V_53 -> V_129 == 0 ) ) {
V_28 -> V_234 = 0 ;
goto V_246;
}
}
}
if( F_176 ( V_24 ) ) {
if ( F_15 ( V_30 [ 0 ] == 0x86 && V_30 [ 1 ] == 0x0b &&
( V_230 == 6 || V_230 == 8 ) ) ) {
V_244 = 0 ;
V_232 -> V_152 = 13 ;
V_232 -> V_237 = 0 ;
V_232 -> V_238 = 0 ;
V_232 -> V_239 = 0 ;
V_232 -> V_240 = 0 ;
} else if( V_234 ) {
V_232 -> V_152 = V_30 [ 0 ] * 256 + V_30 [ 1 ] + 2 ;
V_232 -> V_237 = V_30 [ 2 ] ;
V_232 -> V_238 = V_30 [ 3 ] ;
V_232 -> V_239 = V_30 [ 4 ] & 0x01 ;
V_232 -> V_240 = V_30 [ 6 ] * 256
+ V_30 [ 7 ] ;
} else {
V_232 -> V_152 = V_30 [ 0 ] + 1 ;
V_232 -> V_237 = V_30 [ 1 ] ;
V_232 -> V_238 = V_30 [ 2 ] ;
V_232 -> V_240 = V_30 [ 3 ] ;
}
V_232 -> V_244 = V_244 ;
}
return V_24 ;
}
int
F_178 ( struct V_8 * V_28 , int V_33 , int V_34 ,
struct V_52 * V_249 )
{
char V_2 [] = {
V_250 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_52 * V_53 ;
int V_24 ;
if ( ! V_249 )
V_53 = F_18 ( sizeof( * V_53 ) , V_236 ) ;
else
V_53 = V_249 ;
do {
V_24 = F_174 ( V_28 , V_2 , V_163 , NULL , 0 , V_53 ,
V_33 , V_34 , NULL ) ;
if ( V_28 -> V_132 && F_177 ( V_53 ) &&
V_53 -> V_126 == V_131 )
V_28 -> V_133 = 1 ;
} while ( F_177 ( V_53 ) &&
V_53 -> V_126 == V_131 && -- V_34 );
if ( ! V_249 )
F_20 ( V_53 ) ;
return V_24 ;
}
int
F_179 ( struct V_8 * V_28 , enum V_251 V_252 )
{
enum V_251 V_253 = V_28 -> V_171 ;
if ( V_252 == V_253 )
return 0 ;
switch ( V_252 ) {
case V_254 :
switch ( V_253 ) {
case V_180 :
break;
default:
goto V_255;
}
break;
case V_172 :
switch ( V_253 ) {
case V_254 :
case V_173 :
case V_174 :
case V_178 :
case V_179 :
break;
default:
goto V_255;
}
break;
case V_178 :
switch ( V_253 ) {
case V_172 :
case V_173 :
case V_174 :
break;
default:
goto V_255;
}
break;
case V_173 :
case V_174 :
switch ( V_253 ) {
case V_254 :
case V_172 :
case V_178 :
case V_179 :
break;
default:
goto V_255;
}
break;
case V_179 :
switch ( V_253 ) {
case V_172 :
case V_180 :
break;
default:
goto V_255;
}
break;
case V_180 :
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
case V_172 :
case V_178 :
case V_173 :
case V_174 :
case V_179 :
break;
default:
goto V_255;
}
break;
case V_177 :
switch ( V_253 ) {
case V_254 :
case V_172 :
case V_173 :
case V_174 :
case V_256 :
case V_180 :
break;
default:
goto V_255;
}
break;
}
V_28 -> V_171 = V_252 ;
return 0 ;
V_255:
F_180 ( 1 ,
F_110 ( V_175 , V_28 ,
L_31 ,
F_181 ( V_253 ) ,
F_181 ( V_252 ) )
) ;
return - V_235 ;
}
static void F_182 ( struct V_8 * V_28 , struct V_257 * V_258 )
{
int V_259 = 0 ;
char * V_260 [ 3 ] ;
switch ( V_258 -> V_261 ) {
case V_262 :
V_260 [ V_259 ++ ] = L_32 ;
break;
case V_263 :
V_260 [ V_259 ++ ] = L_33 ;
break;
case V_264 :
V_260 [ V_259 ++ ] = L_34 ;
break;
case V_265 :
V_260 [ V_259 ++ ] = L_35 ;
break;
case V_266 :
V_260 [ V_259 ++ ] = L_36 ;
break;
case V_267 :
V_260 [ V_259 ++ ] = L_37 ;
break;
default:
break;
}
V_260 [ V_259 ++ ] = NULL ;
F_183 ( & V_28 -> V_81 . V_268 , V_269 , V_260 ) ;
}
void F_184 ( struct V_78 * V_79 )
{
struct V_8 * V_28 ;
enum V_270 V_261 ;
F_37 ( V_271 ) ;
V_28 = F_48 ( V_79 , struct V_8 , V_272 ) ;
for ( V_261 = V_273 ; V_261 <= V_274 ; V_261 ++ )
if ( F_185 ( V_261 , V_28 -> V_275 ) )
F_186 ( V_28 , V_261 , V_236 ) ;
while ( 1 ) {
struct V_257 * V_258 ;
struct V_276 * V_277 , * V_67 ;
unsigned long V_13 ;
F_5 ( & V_28 -> V_278 , V_13 ) ;
F_38 ( & V_28 -> V_271 , & V_271 ) ;
F_8 ( & V_28 -> V_278 , V_13 ) ;
if ( F_39 ( & V_271 ) )
break;
F_187 (this, tmp, &event_list) {
V_258 = F_40 ( V_277 , struct V_257 , V_279 ) ;
F_188 ( & V_258 -> V_279 ) ;
F_182 ( V_28 , V_258 ) ;
F_20 ( V_258 ) ;
}
}
}
void F_189 ( struct V_8 * V_28 , struct V_257 * V_258 )
{
unsigned long V_13 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_5 ( & V_28 -> V_278 , V_13 ) ;
F_118 ( & V_258 -> V_279 , & V_28 -> V_271 ) ;
F_190 ( & V_28 -> V_272 ) ;
F_8 ( & V_28 -> V_278 , V_13 ) ;
}
struct V_257 * F_191 ( enum V_270 V_261 ,
T_2 V_280 )
{
struct V_257 * V_258 = F_18 ( sizeof( struct V_257 ) , V_280 ) ;
if ( ! V_258 )
return NULL ;
V_258 -> V_261 = V_261 ;
F_126 ( & V_258 -> V_279 ) ;
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
void F_186 ( struct V_8 * V_28 ,
enum V_270 V_261 , T_2 V_280 )
{
struct V_257 * V_258 = F_191 ( V_261 , V_280 ) ;
if ( ! V_258 ) {
F_110 ( V_175 , V_28 , L_38 ,
V_261 ) ;
return;
}
F_189 ( V_28 , V_258 ) ;
}
int
F_192 ( struct V_8 * V_28 )
{
int V_281 = F_179 ( V_28 , V_178 ) ;
if ( V_281 )
return V_281 ;
F_46 ( V_28 -> V_11 ) ;
while ( V_28 -> V_65 ) {
F_193 ( 200 ) ;
F_46 ( V_28 -> V_11 ) ;
}
return 0 ;
}
void F_194 ( struct V_8 * V_28 )
{
if ( V_28 -> V_171 != V_178 ||
F_179 ( V_28 , V_172 ) )
return;
F_46 ( V_28 -> V_11 ) ;
}
static void
F_195 ( struct V_8 * V_28 , void * V_232 )
{
F_192 ( V_28 ) ;
}
void
F_196 ( struct V_9 * V_10 )
{
F_197 ( V_10 , NULL , F_195 ) ;
}
static void
F_198 ( struct V_8 * V_28 , void * V_232 )
{
F_194 ( V_28 ) ;
}
void
F_199 ( struct V_9 * V_10 )
{
F_197 ( V_10 , NULL , F_198 ) ;
}
int
F_200 ( struct V_8 * V_28 )
{
struct V_11 * V_12 = V_28 -> V_11 ;
unsigned long V_13 ;
int V_281 = 0 ;
V_281 = F_179 ( V_28 , V_179 ) ;
if ( V_281 ) {
V_281 = F_179 ( V_28 , V_180 ) ;
if ( V_281 )
return V_281 ;
}
F_5 ( V_12 -> V_25 , V_13 ) ;
F_201 ( V_12 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
return 0 ;
}
int
F_202 ( struct V_8 * V_28 ,
enum V_251 V_282 )
{
struct V_11 * V_12 = V_28 -> V_11 ;
unsigned long V_13 ;
if ( ( V_28 -> V_171 == V_179 ) ||
( V_28 -> V_171 == V_174 ) )
V_28 -> V_171 = V_282 ;
else if ( V_28 -> V_171 == V_180 ) {
if ( V_282 == V_174 ||
V_282 == V_173 )
V_28 -> V_171 = V_282 ;
else
V_28 -> V_171 = V_254 ;
} else if ( V_28 -> V_171 != V_256 &&
V_28 -> V_171 != V_173 )
return - V_235 ;
F_5 ( V_12 -> V_25 , V_13 ) ;
F_203 ( V_12 ) ;
F_8 ( V_12 -> V_25 , V_13 ) ;
return 0 ;
}
static void
F_204 ( struct V_8 * V_28 , void * V_232 )
{
F_200 ( V_28 ) ;
}
static int
F_205 ( struct V_7 * V_208 , void * V_232 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , NULL ,
F_204 ) ;
return 0 ;
}
void
F_208 ( struct V_7 * V_208 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , NULL ,
F_204 ) ;
else
F_209 ( V_208 , NULL , F_205 ) ;
}
static void
F_210 ( struct V_8 * V_28 , void * V_232 )
{
F_202 ( V_28 , * (enum V_251 * ) V_232 ) ;
}
static int
F_211 ( struct V_7 * V_208 , void * V_232 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , V_232 ,
F_210 ) ;
return 0 ;
}
void
F_212 ( struct V_7 * V_208 , enum V_251 V_282 )
{
if ( F_206 ( V_208 ) )
F_197 ( F_207 ( V_208 ) , & V_282 ,
F_210 ) ;
else
F_209 ( V_208 , & V_282 , F_211 ) ;
}
void * F_213 ( struct V_87 * V_88 , int V_283 ,
T_5 * V_284 , T_5 * V_125 )
{
int V_219 ;
T_5 V_285 = 0 , V_286 = 0 ;
struct V_87 * V_287 ;
struct V_288 * V_288 ;
F_214 ( ! F_215 () ) ;
F_216 (sgl, sg, sg_count, i) {
V_286 = V_285 ;
V_285 += V_287 -> V_152 ;
if ( V_285 > * V_284 )
break;
}
if ( F_15 ( V_219 == V_283 ) ) {
F_3 ( V_175 L_39
L_40 ,
V_196 , V_285 , * V_284 , V_283 ) ;
F_214 ( 1 ) ;
return NULL ;
}
* V_284 = * V_284 - V_286 + V_287 -> V_284 ;
V_288 = F_217 ( F_218 ( V_287 ) , ( * V_284 >> V_206 ) ) ;
* V_284 &= ~ V_289 ;
V_285 = V_290 - * V_284 ;
if ( * V_125 > V_285 )
* V_125 = V_285 ;
return F_219 ( V_288 ) ;
}
void F_220 ( void * V_291 )
{
F_221 ( V_291 ) ;
}
void F_222 ( struct V_8 * V_28 )
{
F_123 ( & V_28 -> V_292 ) ;
}
void F_223 ( struct V_8 * V_28 )
{
if ( F_224 ( F_225 ( & V_28 -> V_292 ) <= 0 ) )
return;
F_226 ( & V_28 -> V_292 ) ;
}
