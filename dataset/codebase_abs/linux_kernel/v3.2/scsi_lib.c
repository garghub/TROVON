static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_3 * V_4 , int V_6 , int V_7 )
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
F_10 ( V_15 -> V_27 , V_16 ) ;
F_11 ( V_15 , & V_10 -> V_28 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 , int V_6 )
{
return F_4 ( V_4 , V_6 , 1 ) ;
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
int * V_36 )
{
char * V_33 = NULL ;
int V_54 ;
if ( V_53 ) {
V_33 = F_21 ( V_55 , V_56 ) ;
if ( ! V_33 )
return V_40 << 24 ;
}
V_54 = F_13 ( V_29 , V_4 , V_30 , V_31 , V_32 ,
V_33 , V_34 , V_35 , 0 , V_36 ) ;
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
F_10 ( V_29 -> V_14 -> V_27 , V_16 ) ;
}
static void F_31 ( struct V_11 * V_67 )
{
struct V_8 * V_60 = V_67 -> V_9 ;
struct V_11 * V_29 , * V_68 ;
struct V_12 * V_13 = V_12 ( V_67 ) ;
unsigned long V_16 ;
F_8 ( V_60 -> V_61 , V_16 ) ;
V_13 -> V_69 = NULL ;
F_10 ( V_60 -> V_61 , V_16 ) ;
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
F_10 ( V_60 -> V_61 , V_16 ) ;
F_32 ( V_29 -> V_14 ) ;
F_8 ( V_60 -> V_61 , V_16 ) ;
F_35 ( V_29 ) ;
}
V_42:
F_10 ( V_60 -> V_61 , V_16 ) ;
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
if ( ! V_29 )
return;
V_60 = V_29 -> V_9 ;
if ( V_12 ( V_29 ) -> V_75 )
F_31 ( V_29 ) ;
F_8 ( V_60 -> V_61 , V_16 ) ;
F_41 ( & V_60 -> V_74 , & V_74 ) ;
while ( ! F_42 ( & V_74 ) ) {
if ( F_38 ( V_60 ) )
break;
V_29 = F_43 ( V_74 . V_76 ,
struct V_11 , V_77 ) ;
F_44 ( & V_29 -> V_77 ) ;
if ( F_37 ( V_12 ( V_29 ) ) ) {
F_45 ( & V_29 -> V_77 ,
& V_60 -> V_74 ) ;
continue;
}
F_29 ( V_60 -> V_61 ) ;
F_30 ( V_29 -> V_14 -> V_27 ) ;
F_46 ( V_29 -> V_14 ) ;
F_29 ( V_29 -> V_14 -> V_27 ) ;
F_30 ( V_60 -> V_61 ) ;
}
F_47 ( & V_74 , & V_60 -> V_74 ) ;
F_10 ( V_60 -> V_61 , V_16 ) ;
F_32 ( V_15 ) ;
}
void F_48 ( struct V_78 * V_79 )
{
struct V_11 * V_29 ;
struct V_14 * V_15 ;
V_29 = F_49 ( V_79 , struct V_11 , V_28 ) ;
V_15 = V_29 -> V_14 ;
F_39 ( V_15 ) ;
}
static void F_50 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_16 ;
F_8 ( V_15 -> V_27 , V_16 ) ;
F_1 ( V_2 ) ;
F_9 ( V_15 , V_2 ) ;
F_10 ( V_15 -> V_27 , V_16 ) ;
F_39 ( V_15 ) ;
}
void F_51 ( struct V_3 * V_4 )
{
struct V_11 * V_29 = V_4 -> V_10 ;
struct V_14 * V_15 = V_29 -> V_14 ;
F_52 ( & V_29 -> V_80 ) ;
F_3 ( V_4 ) ;
F_39 ( V_15 ) ;
F_53 ( & V_29 -> V_80 ) ;
}
void F_54 ( struct V_8 * V_60 )
{
struct V_11 * V_29 ;
F_55 (sdev, shost)
F_39 ( V_29 -> V_14 ) ;
}
static struct V_3 * F_56 ( struct V_3 * V_4 , int error ,
int V_81 , int V_82 )
{
struct V_14 * V_15 = V_4 -> V_10 -> V_14 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( F_57 ( V_2 , error , V_81 ) ) {
if ( error && F_58 ( V_4 ) )
F_59 ( V_2 , error ) ;
else {
if ( V_82 ) {
F_60 ( V_4 ) ;
F_50 ( V_15 , V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
}
F_61 ( V_4 , 0 ) ;
F_51 ( V_4 ) ;
return NULL ;
}
static inline unsigned int F_62 ( unsigned short V_83 )
{
unsigned int V_84 ;
F_63 ( V_83 > V_85 ) ;
if ( V_83 <= 8 )
V_84 = 0 ;
else
V_84 = F_64 ( V_83 ) - 3 ;
return V_84 ;
}
static void F_65 ( struct V_86 * V_87 , unsigned int V_83 )
{
struct V_88 * V_89 ;
V_89 = V_90 + F_62 ( V_83 ) ;
F_66 ( V_87 , V_89 -> V_91 ) ;
}
static struct V_86 * F_67 ( unsigned int V_83 , T_1 V_92 )
{
struct V_88 * V_89 ;
V_89 = V_90 + F_62 ( V_83 ) ;
return F_68 ( V_89 -> V_91 , V_92 ) ;
}
static int F_69 ( struct V_93 * V_94 , int V_83 ,
T_1 V_92 )
{
int V_39 ;
F_63 ( ! V_83 ) ;
V_39 = F_70 ( & V_94 -> V_95 , V_83 , V_85 ,
V_92 , F_67 ) ;
if ( F_18 ( V_39 ) )
F_71 ( & V_94 -> V_95 , V_85 ,
F_65 ) ;
return V_39 ;
}
static void F_72 ( struct V_93 * V_94 )
{
F_71 ( & V_94 -> V_95 , V_85 , F_65 ) ;
}
static void F_61 ( struct V_3 * V_4 , int V_96 )
{
if ( V_4 -> V_94 . V_95 . V_83 )
F_72 ( & V_4 -> V_94 ) ;
memset ( & V_4 -> V_94 , 0 , sizeof( V_4 -> V_94 ) ) ;
if ( V_96 && F_73 ( V_4 ) ) {
struct V_93 * V_97 =
V_4 -> V_1 -> V_98 -> V_5 ;
F_72 ( V_97 ) ;
F_74 ( V_99 , V_97 ) ;
V_4 -> V_1 -> V_98 -> V_5 = NULL ;
}
if ( F_75 ( V_4 ) )
F_72 ( V_4 -> V_100 ) ;
}
void F_60 ( struct V_3 * V_4 )
{
F_61 ( V_4 , 1 ) ;
}
static int F_76 ( struct V_3 * V_4 , int V_54 )
{
int error = 0 ;
switch( F_77 ( V_54 ) ) {
case V_101 :
error = - V_102 ;
break;
case V_103 :
V_4 -> V_54 |= ( V_104 << 16 ) ;
error = - V_105 ;
break;
case V_106 :
V_4 -> V_54 |= ( V_104 << 16 ) ;
error = - V_107 ;
break;
default:
error = - V_108 ;
break;
}
return error ;
}
void F_78 ( struct V_3 * V_4 , unsigned int V_109 )
{
int V_54 = V_4 -> V_54 ;
struct V_14 * V_15 = V_4 -> V_10 -> V_14 ;
struct V_1 * V_2 = V_4 -> V_1 ;
int error = 0 ;
struct V_52 V_53 ;
int V_110 = 0 ;
int V_111 = 0 ;
enum { V_112 , V_113 , V_114 ,
V_115 } V_116 ;
char * V_117 = NULL ;
if ( V_54 ) {
V_110 = F_79 ( V_4 , & V_53 ) ;
if ( V_110 )
V_111 = F_80 ( & V_53 ) ;
}
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_51 = V_54 ;
if ( V_54 ) {
if ( V_110 && V_2 -> V_33 ) {
int V_118 = 8 + V_4 -> V_58 [ 7 ] ;
if ( V_118 > V_55 )
V_118 = V_55 ;
memcpy ( V_2 -> V_33 , V_4 -> V_58 , V_118 ) ;
V_2 -> V_44 = V_118 ;
}
if ( ! V_111 )
error = F_76 ( V_4 , V_54 ) ;
}
V_2 -> V_50 = F_81 ( V_4 ) ;
if ( F_73 ( V_4 ) ) {
V_2 -> V_98 -> V_50 = F_82 ( V_4 ) -> V_36 ;
F_60 ( V_4 ) ;
F_59 ( V_2 , 0 ) ;
F_51 ( V_4 ) ;
return;
}
}
F_63 ( F_83 ( V_2 ) ) ;
F_84 ( 1 , F_6 ( L_2
L_3 ,
F_85 ( V_2 ) , V_109 ) ) ;
if ( V_110 && ( V_53 . V_119 == V_120 ) ) {
if ( ( V_53 . V_121 == 0x0 ) && ( V_53 . V_122 == 0x1d ) )
;
else if ( ! ( V_2 -> V_47 & V_48 ) )
F_86 ( L_4 , V_4 ) ;
V_54 = 0 ;
error = 0 ;
}
if ( F_56 ( V_4 , error , V_109 , V_54 == 0 ) == NULL )
return;
error = F_76 ( V_4 , V_54 ) ;
if ( F_77 ( V_54 ) == V_123 ) {
V_116 = V_114 ;
} else if ( V_110 && ! V_111 ) {
switch ( V_53 . V_119 ) {
case V_124 :
if ( V_4 -> V_10 -> V_125 ) {
V_4 -> V_10 -> V_126 = 1 ;
V_117 = L_5 ;
V_116 = V_112 ;
} else {
V_116 = V_114 ;
}
break;
case V_127 :
if ( ( V_4 -> V_10 -> V_128 &&
V_53 . V_121 == 0x20 && V_53 . V_122 == 0x00 ) &&
( V_4 -> V_59 [ 0 ] == V_129 ||
V_4 -> V_59 [ 0 ] == V_130 ) ) {
V_4 -> V_10 -> V_128 = 0 ;
V_116 = V_113 ;
} else if ( V_53 . V_121 == 0x10 ) {
V_117 = L_6 ;
V_116 = V_112 ;
error = - V_131 ;
} else if ( ( V_53 . V_121 == 0x20 || V_53 . V_121 == 0x24 ) &&
( V_4 -> V_59 [ 0 ] == V_132 ||
V_4 -> V_59 [ 0 ] == V_133 ||
V_4 -> V_59 [ 0 ] == V_134 ) ) {
V_117 = L_7 ;
V_116 = V_112 ;
} else
V_116 = V_112 ;
break;
case V_135 :
V_116 = V_112 ;
if ( V_53 . V_121 == 0x10 ) {
V_117 = L_8 ;
error = - V_131 ;
}
break;
case V_136 :
if ( V_53 . V_121 == 0x04 ) {
switch ( V_53 . V_122 ) {
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
V_117 = L_9 ;
V_116 = V_112 ;
break;
}
} else {
V_117 = L_9 ;
V_116 = V_112 ;
}
break;
case V_137 :
V_116 = V_112 ;
break;
default:
V_117 = L_10 ;
V_116 = V_112 ;
break;
}
} else {
V_117 = L_11 ;
V_116 = V_112 ;
}
switch ( V_116 ) {
case V_112 :
F_60 ( V_4 ) ;
if ( ! ( V_2 -> V_47 & V_48 ) ) {
if ( V_117 )
F_87 ( V_138 , V_4 , L_12 ,
V_117 ) ;
F_88 ( V_4 ) ;
if ( F_89 ( V_54 ) & V_139 )
F_86 ( L_4 , V_4 ) ;
F_90 ( V_4 ) ;
}
if ( F_91 ( V_2 , error ) )
F_50 ( V_15 , V_4 ) ;
else
F_51 ( V_4 ) ;
break;
case V_113 :
F_60 ( V_4 ) ;
F_50 ( V_15 , V_4 ) ;
break;
case V_114 :
F_4 ( V_4 , V_21 , 0 ) ;
break;
case V_115 :
F_4 ( V_4 , V_20 , 0 ) ;
break;
}
}
static int F_92 ( struct V_1 * V_2 , struct V_93 * V_94 ,
T_1 V_92 )
{
int V_140 ;
if ( F_18 ( F_69 ( V_94 , V_2 -> V_141 ,
V_92 ) ) ) {
return V_142 ;
}
V_2 -> V_31 = NULL ;
V_140 = F_93 ( V_2 -> V_15 , V_2 , V_94 -> V_95 . V_87 ) ;
F_63 ( V_140 > V_94 -> V_95 . V_83 ) ;
V_94 -> V_95 . V_83 = V_140 ;
V_94 -> V_143 = F_94 ( V_2 ) ;
return V_144 ;
}
int F_95 ( struct V_3 * V_4 , T_1 V_92 )
{
struct V_1 * V_145 = V_4 -> V_1 ;
int error = F_92 ( V_145 , & V_4 -> V_94 , V_92 ) ;
if ( error )
goto V_146;
if ( F_83 ( V_145 ) ) {
struct V_93 * V_97 = F_96 (
V_99 , V_147 ) ;
if ( ! V_97 ) {
error = V_142 ;
goto V_146;
}
V_145 -> V_98 -> V_5 = V_97 ;
error = F_92 ( V_145 -> V_98 , V_97 , V_147 ) ;
if ( error )
goto V_146;
}
if ( F_97 ( V_145 ) ) {
struct V_93 * V_100 = V_4 -> V_100 ;
int V_148 , V_140 ;
F_63 ( V_100 == NULL ) ;
V_148 = F_98 ( V_145 -> V_15 , V_145 -> V_149 ) ;
if ( F_69 ( V_100 , V_148 , V_92 ) ) {
error = V_142 ;
goto V_146;
}
V_140 = F_99 ( V_145 -> V_15 , V_145 -> V_149 ,
V_100 -> V_95 . V_87 ) ;
F_63 ( F_18 ( V_140 > V_148 ) ) ;
F_63 ( F_18 ( V_140 > F_100 ( V_145 -> V_15 ) ) ) ;
V_4 -> V_100 = V_100 ;
V_4 -> V_100 -> V_95 . V_83 = V_140 ;
}
return V_144 ;
V_146:
F_60 ( V_4 ) ;
V_4 -> V_1 -> V_5 = NULL ;
F_3 ( V_4 ) ;
return error ;
}
static struct V_3 * F_101 ( struct V_11 * V_29 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_5 ) {
V_4 = F_102 ( V_29 , V_147 ) ;
if ( F_18 ( ! V_4 ) )
return NULL ;
V_2 -> V_5 = V_4 ;
} else {
V_4 = V_2 -> V_5 ;
}
V_4 -> V_150 = V_2 -> V_150 ;
V_4 -> V_1 = V_2 ;
V_4 -> V_59 = V_2 -> V_4 ;
V_4 -> V_151 = V_152 ;
return V_4 ;
}
int F_103 ( struct V_11 * V_29 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_39 = F_104 ( V_29 , V_2 ) ;
if ( V_39 != V_144 )
return V_39 ;
V_4 = F_101 ( V_29 , V_2 ) ;
if ( F_18 ( ! V_4 ) )
return V_142 ;
if ( V_2 -> V_149 ) {
int V_39 ;
F_63 ( ! V_2 -> V_141 ) ;
V_39 = F_95 ( V_4 , V_147 ) ;
if ( F_18 ( V_39 ) )
return V_39 ;
} else {
F_63 ( F_94 ( V_2 ) ) ;
memset ( & V_4 -> V_94 , 0 , sizeof( V_4 -> V_94 ) ) ;
V_2 -> V_31 = NULL ;
}
V_4 -> V_43 = V_2 -> V_43 ;
if ( ! F_94 ( V_2 ) )
V_4 -> V_153 = V_154 ;
else if ( F_105 ( V_2 ) == V_155 )
V_4 -> V_153 = V_38 ;
else
V_4 -> V_153 = V_156 ;
V_4 -> V_157 = F_94 ( V_2 ) ;
V_4 -> V_158 = V_2 -> V_35 ;
return V_144 ;
}
int F_106 ( struct V_11 * V_29 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_39 = F_104 ( V_29 , V_2 ) ;
if ( V_39 != V_144 )
return V_39 ;
if ( F_18 ( V_29 -> V_159 && V_29 -> V_159 -> V_160
&& V_29 -> V_159 -> V_160 -> V_161 ) ) {
V_39 = V_29 -> V_159 -> V_160 -> V_161 ( V_29 , V_2 ) ;
if ( V_39 != V_144 )
return V_39 ;
}
F_63 ( ! V_2 -> V_141 ) ;
V_4 = F_101 ( V_29 , V_2 ) ;
if ( F_18 ( ! V_4 ) )
return V_142 ;
memset ( V_4 -> V_59 , 0 , V_162 ) ;
return F_95 ( V_4 , V_147 ) ;
}
int F_104 ( struct V_11 * V_29 , struct V_1 * V_2 )
{
int V_39 = V_144 ;
if ( F_18 ( V_29 -> V_163 != V_164 ) ) {
switch ( V_29 -> V_163 ) {
case V_165 :
F_107 ( V_166 , V_29 ,
L_13 ) ;
V_39 = V_167 ;
break;
case V_168 :
F_107 ( V_166 , V_29 ,
L_14 ) ;
V_39 = V_167 ;
break;
case V_169 :
case V_170 :
case V_171 :
if ( ! ( V_2 -> V_47 & V_49 ) )
V_39 = V_142 ;
break;
default:
if ( ! ( V_2 -> V_47 & V_49 ) )
V_39 = V_167 ;
break;
}
}
return V_39 ;
}
int F_108 ( struct V_14 * V_15 , struct V_1 * V_2 , int V_39 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
switch ( V_39 ) {
case V_167 :
V_2 -> V_51 = V_172 << 16 ;
if ( V_2 -> V_5 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
F_60 ( V_4 ) ;
F_3 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
break;
case V_142 :
if ( V_29 -> V_66 == 0 )
F_109 ( V_15 , V_173 ) ;
break;
default:
V_2 -> V_47 |= V_174 ;
}
return V_39 ;
}
int F_110 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
int V_39 = V_167 ;
if ( V_2 -> V_45 == V_46 )
V_39 = F_103 ( V_29 , V_2 ) ;
return F_108 ( V_15 , V_2 , V_39 ) ;
}
static inline int F_111 ( struct V_14 * V_15 ,
struct V_11 * V_29 )
{
if ( V_29 -> V_66 == 0 && V_29 -> V_22 ) {
if ( -- V_29 -> V_22 == 0 ) {
F_5 ( 3 ,
F_107 ( V_138 , V_29 ,
L_15 ) ) ;
} else {
F_109 ( V_15 , V_173 ) ;
return 0 ;
}
}
if ( F_36 ( V_29 ) )
return 0 ;
return 1 ;
}
static inline int F_112 ( struct V_8 * V_60 ,
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
F_5 ( 3 , F_113 ( V_138 , V_13 ,
L_16 ) ) ;
} else
return 0 ;
}
if ( F_37 ( V_13 ) ) {
if ( F_42 ( & V_29 -> V_77 ) )
F_114 ( & V_29 -> V_77 ,
& V_60 -> V_74 ) ;
return 0 ;
}
if ( ! F_42 ( & V_29 -> V_77 ) )
F_44 ( & V_29 -> V_77 ) ;
return 1 ;
}
static inline int F_115 ( struct V_14 * V_15 ,
struct V_8 * V_60 ,
struct V_11 * V_29 )
{
if ( F_27 ( V_60 ) )
return 0 ;
if ( V_60 -> V_62 == 0 && V_60 -> V_18 ) {
if ( -- V_60 -> V_18 == 0 ) {
F_5 ( 3 ,
F_6 ( L_17 ,
V_60 -> V_175 ) ) ;
} else {
return 0 ;
}
}
if ( F_38 ( V_60 ) ) {
if ( F_42 ( & V_29 -> V_77 ) )
F_114 ( & V_29 -> V_77 , & V_60 -> V_74 ) ;
return 0 ;
}
if ( ! F_42 ( & V_29 -> V_77 ) )
F_44 ( & V_29 -> V_77 ) ;
return 1 ;
}
static int F_116 ( struct V_14 * V_15 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
struct V_8 * V_60 ;
struct V_12 * V_13 ;
if ( ! V_29 )
return 0 ;
V_60 = V_29 -> V_9 ;
V_13 = V_12 ( V_29 ) ;
if ( F_27 ( V_60 ) || F_38 ( V_60 ) ||
F_37 ( V_13 ) || F_36 ( V_29 ) )
return 1 ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_29 ;
struct V_12 * V_13 ;
struct V_8 * V_60 ;
F_118 ( V_2 ) ;
F_87 ( V_138 , V_4 , L_18 ) ;
V_29 = V_4 -> V_10 ;
V_13 = V_12 ( V_29 ) ;
V_60 = V_29 -> V_9 ;
F_24 ( V_4 ) ;
V_4 -> V_54 = V_172 << 16 ;
F_119 ( & V_4 -> V_10 -> V_176 ) ;
V_29 -> V_66 ++ ;
F_29 ( V_29 -> V_14 -> V_27 ) ;
F_30 ( V_60 -> V_61 ) ;
V_60 -> V_62 ++ ;
V_13 -> V_63 ++ ;
F_29 ( V_60 -> V_61 ) ;
F_30 ( V_29 -> V_14 -> V_27 ) ;
F_120 ( V_2 ) ;
}
static void F_121 ( struct V_1 * V_145 )
{
struct V_3 * V_4 = V_145 -> V_5 ;
unsigned long V_177 = ( V_4 -> V_158 + 1 ) * V_145 -> V_34 ;
int V_178 ;
F_122 ( & V_4 -> V_179 ) ;
F_119 ( & V_4 -> V_10 -> V_180 ) ;
if ( V_4 -> V_54 )
F_119 ( & V_4 -> V_10 -> V_181 ) ;
V_178 = F_123 ( V_4 ) ;
if ( V_178 != V_182 &&
F_124 ( V_4 -> V_183 + V_177 , V_184 ) ) {
F_107 ( V_166 , V_4 -> V_10 ,
L_19 ,
V_177 / V_185 ) ;
V_178 = V_182 ;
}
F_125 ( V_4 , V_178 ) ;
switch ( V_178 ) {
case V_182 :
F_126 ( V_4 ) ;
break;
case V_186 :
F_12 ( V_4 , V_21 ) ;
break;
case V_187 :
F_12 ( V_4 , V_20 ) ;
break;
default:
if ( ! F_127 ( V_4 , 0 ) )
F_126 ( V_4 ) ;
}
}
static void F_128 ( struct V_14 * V_15 )
{
struct V_11 * V_29 = V_15 -> V_73 ;
struct V_8 * V_60 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
if ( ! V_29 ) {
while ( ( V_2 = F_129 ( V_15 ) ) != NULL )
F_117 ( V_2 , V_15 ) ;
return;
}
if( ! F_52 ( & V_29 -> V_80 ) )
return;
V_60 = V_29 -> V_9 ;
for (; ; ) {
int V_188 ;
V_2 = F_129 ( V_15 ) ;
if ( ! V_2 || ! F_111 ( V_15 , V_29 ) )
break;
if ( F_18 ( ! F_130 ( V_29 ) ) ) {
F_107 ( V_166 , V_29 ,
L_13 ) ;
F_117 ( V_2 , V_15 ) ;
continue;
}
if ( ! ( F_131 ( V_15 ) && ! F_132 ( V_15 , V_2 ) ) )
F_118 ( V_2 ) ;
V_29 -> V_66 ++ ;
F_29 ( V_15 -> V_27 ) ;
V_4 = V_2 -> V_5 ;
if ( F_18 ( V_4 == NULL ) ) {
F_6 ( V_189 L_20
L_21
L_22 ,
V_190 ) ;
F_133 ( V_2 , L_23 ) ;
F_134 () ;
}
F_30 ( V_60 -> V_61 ) ;
if ( F_131 ( V_15 ) && ! F_135 ( V_2 ) ) {
if ( F_42 ( & V_29 -> V_77 ) )
F_114 ( & V_29 -> V_77 ,
& V_60 -> V_74 ) ;
goto V_191;
}
if ( ! F_112 ( V_60 , V_29 ) )
goto V_191;
if ( ! F_115 ( V_15 , V_60 , V_29 ) )
goto V_191;
V_12 ( V_29 ) -> V_63 ++ ;
V_60 -> V_62 ++ ;
F_136 ( V_60 -> V_61 ) ;
F_24 ( V_4 ) ;
V_188 = F_137 ( V_4 ) ;
F_138 ( V_15 -> V_27 ) ;
if ( V_188 )
goto V_192;
}
goto V_42;
V_191:
F_136 ( V_60 -> V_61 ) ;
F_138 ( V_15 -> V_27 ) ;
F_9 ( V_15 , V_2 ) ;
V_29 -> V_66 -- ;
V_192:
if ( V_29 -> V_66 == 0 )
F_109 ( V_15 , V_173 ) ;
V_42:
F_136 ( V_15 -> V_27 ) ;
F_53 ( & V_29 -> V_80 ) ;
F_138 ( V_15 -> V_27 ) ;
}
T_2 F_139 ( struct V_8 * V_60 )
{
struct V_10 * V_193 ;
T_2 V_194 = 0xffffffff ;
if ( V_60 -> V_195 )
return V_196 ;
if ( ! V_197 )
return V_198 ;
V_193 = F_140 ( V_60 ) ;
if ( V_193 && V_193 -> V_199 )
V_194 = * V_193 -> V_199 ;
return V_194 ;
}
struct V_14 * F_141 ( struct V_8 * V_60 ,
T_3 * V_200 )
{
struct V_14 * V_15 ;
struct V_10 * V_201 = V_60 -> V_202 . V_203 ;
V_15 = F_142 ( V_200 , NULL ) ;
if ( ! V_15 )
return NULL ;
F_143 ( V_15 , F_144 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_145 ( V_60 ) ) {
V_60 -> V_204 =
F_146 ( V_60 -> V_204 ,
( unsigned short ) V_205 ) ;
F_63 ( V_60 -> V_204 < V_60 -> V_206 ) ;
F_147 ( V_15 , V_60 -> V_204 ) ;
}
F_148 ( V_15 , V_60 -> V_207 ) ;
F_149 ( V_15 , F_139 ( V_60 ) ) ;
F_150 ( V_15 , V_60 -> V_208 ) ;
F_151 ( V_201 , V_60 -> V_208 ) ;
F_152 ( V_15 , F_153 ( V_201 ) ) ;
if ( ! V_60 -> V_209 )
V_15 -> V_210 . V_211 = 0 ;
F_154 ( V_15 , 0x03 ) ;
return V_15 ;
}
struct V_14 * F_155 ( struct V_11 * V_29 )
{
struct V_14 * V_15 ;
V_15 = F_141 ( V_29 -> V_9 , F_128 ) ;
if ( ! V_15 )
return NULL ;
F_156 ( V_15 , F_110 ) ;
F_157 ( V_15 , F_121 ) ;
F_158 ( V_15 , V_212 ) ;
F_159 ( V_15 , F_116 ) ;
return V_15 ;
}
void F_160 ( struct V_14 * V_15 )
{
unsigned long V_16 ;
F_161 ( V_15 -> V_73 ) ;
F_8 ( V_15 -> V_27 , V_16 ) ;
V_15 -> V_200 ( V_15 ) ;
F_10 ( V_15 -> V_27 , V_16 ) ;
F_162 ( V_15 ) ;
}
void F_163 ( struct V_8 * V_60 )
{
V_60 -> V_72 = 1 ;
}
void F_164 ( struct V_8 * V_60 )
{
V_60 -> V_72 = 0 ;
F_54 ( V_60 ) ;
}
int T_4 F_165 ( void )
{
int V_213 ;
V_99 = F_166 ( L_24 ,
sizeof( struct V_93 ) ,
0 , 0 , NULL ) ;
if ( ! V_99 ) {
F_6 ( V_166 L_25 ) ;
return - V_214 ;
}
for ( V_213 = 0 ; V_213 < V_215 ; V_213 ++ ) {
struct V_88 * V_89 = V_90 + V_213 ;
int V_216 = V_89 -> V_216 * sizeof( struct V_86 ) ;
V_89 -> V_217 = F_166 ( V_89 -> V_218 , V_216 , 0 ,
V_219 , NULL ) ;
if ( ! V_89 -> V_217 ) {
F_6 ( V_166 L_26 ,
V_89 -> V_218 ) ;
goto V_220;
}
V_89 -> V_91 = F_167 ( V_221 ,
V_89 -> V_217 ) ;
if ( ! V_89 -> V_91 ) {
F_6 ( V_166 L_27 ,
V_89 -> V_218 ) ;
goto V_220;
}
}
return 0 ;
V_220:
for ( V_213 = 0 ; V_213 < V_215 ; V_213 ++ ) {
struct V_88 * V_89 = V_90 + V_213 ;
if ( V_89 -> V_91 )
F_168 ( V_89 -> V_91 ) ;
if ( V_89 -> V_217 )
F_169 ( V_89 -> V_217 ) ;
}
F_169 ( V_99 ) ;
return - V_214 ;
}
void F_170 ( void )
{
int V_213 ;
F_169 ( V_99 ) ;
for ( V_213 = 0 ; V_213 < V_215 ; V_213 ++ ) {
struct V_88 * V_89 = V_90 + V_213 ;
F_168 ( V_89 -> V_91 ) ;
F_169 ( V_89 -> V_217 ) ;
}
}
int
F_171 ( struct V_11 * V_29 , int V_222 , int V_223 , int V_224 ,
unsigned char * V_31 , int V_118 , int V_34 , int V_35 ,
struct V_225 * V_226 , struct V_52 * V_53 )
{
unsigned char V_4 [ 10 ] ;
unsigned char * V_227 ;
int V_39 ;
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
V_4 [ 1 ] = ( V_222 ? 0x10 : 0 ) | ( V_223 ? 0x01 : 0 ) ;
if ( V_29 -> V_228 ) {
if ( V_118 > 65535 )
return - V_229 ;
V_227 = F_172 ( 8 + V_118 , V_230 ) ;
if ( ! V_227 )
return - V_214 ;
memcpy ( V_227 + 8 , V_31 , V_118 ) ;
V_118 += 8 ;
V_227 [ 0 ] = 0 ;
V_227 [ 1 ] = 0 ;
V_227 [ 2 ] = V_226 -> V_231 ;
V_227 [ 3 ] = V_226 -> V_232 ;
V_227 [ 4 ] = V_226 -> V_233 ? 0x01 : 0 ;
V_227 [ 5 ] = 0 ;
V_227 [ 6 ] = V_226 -> V_234 >> 8 ;
V_227 [ 7 ] = V_226 -> V_234 ;
V_4 [ 0 ] = V_235 ;
V_4 [ 7 ] = V_118 >> 8 ;
V_4 [ 8 ] = V_118 ;
} else {
if ( V_118 > 255 || V_226 -> V_234 > 255 ||
V_226 -> V_233 )
return - V_229 ;
V_227 = F_172 ( 4 + V_118 , V_230 ) ;
if ( ! V_227 )
return - V_214 ;
memcpy ( V_227 + 4 , V_31 , V_118 ) ;
V_118 += 4 ;
V_227 [ 0 ] = 0 ;
V_227 [ 1 ] = V_226 -> V_231 ;
V_227 [ 2 ] = V_226 -> V_232 ;
V_227 [ 3 ] = V_226 -> V_234 ;
V_4 [ 0 ] = V_236 ;
V_4 [ 4 ] = V_118 ;
}
V_39 = F_20 ( V_29 , V_4 , V_38 , V_227 , V_118 ,
V_53 , V_34 , V_35 , NULL ) ;
F_23 ( V_227 ) ;
return V_39 ;
}
int
F_173 ( struct V_11 * V_29 , int V_237 , int V_224 ,
unsigned char * V_31 , int V_118 , int V_34 , int V_35 ,
struct V_225 * V_226 , struct V_52 * V_53 )
{
unsigned char V_4 [ 12 ] ;
int V_228 ;
int V_238 ;
int V_54 ;
struct V_52 V_239 ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
memset ( & V_4 [ 0 ] , 0 , 12 ) ;
V_4 [ 1 ] = V_237 & 0x18 ;
V_4 [ 2 ] = V_224 ;
if ( ! V_53 )
V_53 = & V_239 ;
V_240:
V_228 = V_29 -> V_228 ;
if ( V_228 ) {
if ( V_118 < 8 )
V_118 = 8 ;
V_4 [ 0 ] = V_241 ;
V_4 [ 8 ] = V_118 ;
V_238 = 8 ;
} else {
if ( V_118 < 4 )
V_118 = 4 ;
V_4 [ 0 ] = V_242 ;
V_4 [ 4 ] = V_118 ;
V_238 = 4 ;
}
memset ( V_31 , 0 , V_118 ) ;
V_54 = F_20 ( V_29 , V_4 , V_156 , V_31 , V_118 ,
V_53 , V_34 , V_35 , NULL ) ;
if ( V_228 && ! F_174 ( V_54 ) &&
( F_89 ( V_54 ) & V_139 ) ) {
if ( F_175 ( V_53 ) ) {
if ( ( V_53 -> V_119 == V_127 ) &&
( V_53 -> V_121 == 0x20 ) && ( V_53 -> V_122 == 0 ) ) {
V_29 -> V_228 = 0 ;
goto V_240;
}
}
}
if( F_174 ( V_54 ) ) {
if ( F_18 ( V_31 [ 0 ] == 0x86 && V_31 [ 1 ] == 0x0b &&
( V_224 == 6 || V_224 == 8 ) ) ) {
V_238 = 0 ;
V_226 -> V_143 = 13 ;
V_226 -> V_231 = 0 ;
V_226 -> V_232 = 0 ;
V_226 -> V_233 = 0 ;
V_226 -> V_234 = 0 ;
} else if( V_228 ) {
V_226 -> V_143 = V_31 [ 0 ] * 256 + V_31 [ 1 ] + 2 ;
V_226 -> V_231 = V_31 [ 2 ] ;
V_226 -> V_232 = V_31 [ 3 ] ;
V_226 -> V_233 = V_31 [ 4 ] & 0x01 ;
V_226 -> V_234 = V_31 [ 6 ] * 256
+ V_31 [ 7 ] ;
} else {
V_226 -> V_143 = V_31 [ 0 ] + 1 ;
V_226 -> V_231 = V_31 [ 1 ] ;
V_226 -> V_232 = V_31 [ 2 ] ;
V_226 -> V_234 = V_31 [ 3 ] ;
}
V_226 -> V_238 = V_238 ;
}
return V_54 ;
}
int
F_176 ( struct V_11 * V_29 , int V_34 , int V_35 ,
struct V_52 * V_243 )
{
char V_4 [] = {
V_244 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_52 * V_53 ;
int V_54 ;
if ( ! V_243 )
V_53 = F_21 ( sizeof( * V_53 ) , V_230 ) ;
else
V_53 = V_243 ;
do {
V_54 = F_20 ( V_29 , V_4 , V_154 , NULL , 0 , V_53 ,
V_34 , V_35 , NULL ) ;
if ( V_29 -> V_125 && F_175 ( V_53 ) &&
V_53 -> V_119 == V_124 )
V_29 -> V_126 = 1 ;
} while ( F_175 ( V_53 ) &&
V_53 -> V_119 == V_124 && -- V_35 );
if ( ! V_243 )
F_23 ( V_53 ) ;
return V_54 ;
}
int
F_177 ( struct V_11 * V_29 , enum V_245 V_246 )
{
enum V_245 V_247 = V_29 -> V_163 ;
if ( V_246 == V_247 )
return 0 ;
switch ( V_246 ) {
case V_248 :
switch ( V_247 ) {
case V_171 :
break;
default:
goto V_249;
}
break;
case V_164 :
switch ( V_247 ) {
case V_248 :
case V_165 :
case V_169 :
case V_170 :
break;
default:
goto V_249;
}
break;
case V_169 :
switch ( V_247 ) {
case V_164 :
case V_165 :
break;
default:
goto V_249;
}
break;
case V_165 :
switch ( V_247 ) {
case V_248 :
case V_164 :
case V_169 :
case V_170 :
break;
default:
goto V_249;
}
break;
case V_170 :
switch ( V_247 ) {
case V_164 :
case V_171 :
break;
default:
goto V_249;
}
break;
case V_171 :
switch ( V_247 ) {
case V_248 :
break;
default:
goto V_249;
}
break;
case V_250 :
switch ( V_247 ) {
case V_248 :
case V_164 :
case V_169 :
case V_165 :
case V_170 :
break;
default:
goto V_249;
}
break;
case V_168 :
switch ( V_247 ) {
case V_248 :
case V_164 :
case V_165 :
case V_250 :
break;
default:
goto V_249;
}
break;
}
V_29 -> V_163 = V_246 ;
return 0 ;
V_249:
F_178 ( 1 ,
F_107 ( V_166 , V_29 ,
L_28 ,
F_179 ( V_247 ) ,
F_179 ( V_246 ) )
) ;
return - V_229 ;
}
static void F_180 ( struct V_11 * V_29 , struct V_251 * V_252 )
{
int V_253 = 0 ;
char * V_254 [ 3 ] ;
switch ( V_252 -> V_255 ) {
case V_256 :
V_254 [ V_253 ++ ] = L_29 ;
break;
default:
break;
}
V_254 [ V_253 ++ ] = NULL ;
F_181 ( & V_29 -> V_80 . V_257 , V_258 , V_254 ) ;
}
void F_182 ( struct V_78 * V_79 )
{
struct V_11 * V_29 ;
F_40 ( V_259 ) ;
V_29 = F_49 ( V_79 , struct V_11 , V_260 ) ;
while ( 1 ) {
struct V_251 * V_252 ;
struct V_261 * V_262 , * V_68 ;
unsigned long V_16 ;
F_8 ( & V_29 -> V_263 , V_16 ) ;
F_41 ( & V_29 -> V_259 , & V_259 ) ;
F_10 ( & V_29 -> V_263 , V_16 ) ;
if ( F_42 ( & V_259 ) )
break;
F_183 (this, tmp, &event_list) {
V_252 = F_43 ( V_262 , struct V_251 , V_264 ) ;
F_184 ( & V_252 -> V_264 ) ;
F_180 ( V_29 , V_252 ) ;
F_23 ( V_252 ) ;
}
}
}
void F_185 ( struct V_11 * V_29 , struct V_251 * V_252 )
{
unsigned long V_16 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_8 ( & V_29 -> V_263 , V_16 ) ;
F_114 ( & V_252 -> V_264 , & V_29 -> V_259 ) ;
F_186 ( & V_29 -> V_260 ) ;
F_10 ( & V_29 -> V_263 , V_16 ) ;
}
struct V_251 * F_187 ( enum V_265 V_255 ,
T_1 V_266 )
{
struct V_251 * V_252 = F_21 ( sizeof( struct V_251 ) , V_266 ) ;
if ( ! V_252 )
return NULL ;
V_252 -> V_255 = V_255 ;
F_122 ( & V_252 -> V_264 ) ;
switch ( V_255 ) {
case V_256 :
default:
break;
}
return V_252 ;
}
void F_188 ( struct V_11 * V_29 ,
enum V_265 V_255 , T_1 V_266 )
{
struct V_251 * V_252 = F_187 ( V_255 , V_266 ) ;
if ( ! V_252 ) {
F_107 ( V_166 , V_29 , L_30 ,
V_255 ) ;
return;
}
F_185 ( V_29 , V_252 ) ;
}
int
F_189 ( struct V_11 * V_29 )
{
int V_267 = F_177 ( V_29 , V_169 ) ;
if ( V_267 )
return V_267 ;
F_39 ( V_29 -> V_14 ) ;
while ( V_29 -> V_66 ) {
F_190 ( 200 ) ;
F_39 ( V_29 -> V_14 ) ;
}
return 0 ;
}
void
F_191 ( struct V_11 * V_29 )
{
if( F_177 ( V_29 , V_164 ) )
return;
F_39 ( V_29 -> V_14 ) ;
}
static void
F_192 ( struct V_11 * V_29 , void * V_226 )
{
F_189 ( V_29 ) ;
}
void
F_193 ( struct V_12 * V_13 )
{
F_194 ( V_13 , NULL , F_192 ) ;
}
static void
F_195 ( struct V_11 * V_29 , void * V_226 )
{
F_191 ( V_29 ) ;
}
void
F_196 ( struct V_12 * V_13 )
{
F_194 ( V_13 , NULL , F_195 ) ;
}
int
F_197 ( struct V_11 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_14 ;
unsigned long V_16 ;
int V_267 = 0 ;
V_267 = F_177 ( V_29 , V_170 ) ;
if ( V_267 ) {
V_267 = F_177 ( V_29 , V_171 ) ;
if ( V_267 )
return V_267 ;
}
F_8 ( V_15 -> V_27 , V_16 ) ;
F_198 ( V_15 ) ;
F_10 ( V_15 -> V_27 , V_16 ) ;
return 0 ;
}
int
F_199 ( struct V_11 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_14 ;
unsigned long V_16 ;
if ( V_29 -> V_163 == V_170 )
V_29 -> V_163 = V_164 ;
else if ( V_29 -> V_163 == V_171 )
V_29 -> V_163 = V_248 ;
else if ( V_29 -> V_163 != V_250 &&
V_29 -> V_163 != V_165 )
return - V_229 ;
F_8 ( V_15 -> V_27 , V_16 ) ;
F_200 ( V_15 ) ;
F_10 ( V_15 -> V_27 , V_16 ) ;
return 0 ;
}
static void
F_201 ( struct V_11 * V_29 , void * V_226 )
{
F_197 ( V_29 ) ;
}
static int
F_202 ( struct V_10 * V_201 , void * V_226 )
{
if ( F_203 ( V_201 ) )
F_194 ( F_204 ( V_201 ) , NULL ,
F_201 ) ;
return 0 ;
}
void
F_205 ( struct V_10 * V_201 )
{
if ( F_203 ( V_201 ) )
F_194 ( F_204 ( V_201 ) , NULL ,
F_201 ) ;
else
F_206 ( V_201 , NULL , F_202 ) ;
}
static void
F_207 ( struct V_11 * V_29 , void * V_226 )
{
F_199 ( V_29 ) ;
}
static int
F_208 ( struct V_10 * V_201 , void * V_226 )
{
if ( F_203 ( V_201 ) )
F_194 ( F_204 ( V_201 ) , NULL ,
F_207 ) ;
return 0 ;
}
void
F_209 ( struct V_10 * V_201 )
{
if ( F_203 ( V_201 ) )
F_194 ( F_204 ( V_201 ) , NULL ,
F_207 ) ;
else
F_206 ( V_201 , NULL , F_208 ) ;
}
void * F_210 ( struct V_86 * V_87 , int V_268 ,
T_5 * V_269 , T_5 * V_118 )
{
int V_213 ;
T_5 V_270 = 0 , V_271 = 0 ;
struct V_86 * V_272 ;
struct V_273 * V_273 ;
F_161 ( ! F_211 () ) ;
F_212 (sgl, sg, sg_count, i) {
V_271 = V_270 ;
V_270 += V_272 -> V_143 ;
if ( V_270 > * V_269 )
break;
}
if ( F_18 ( V_213 == V_268 ) ) {
F_6 ( V_166 L_31
L_32 ,
V_190 , V_270 , * V_269 , V_268 ) ;
F_161 ( 1 ) ;
return NULL ;
}
* V_269 = * V_269 - V_271 + V_272 -> V_269 ;
V_273 = F_213 ( F_214 ( V_272 ) , ( * V_269 >> V_274 ) ) ;
* V_269 &= ~ V_275 ;
V_270 = V_276 - * V_269 ;
if ( * V_118 > V_270 )
* V_118 = V_270 ;
return F_215 ( V_273 , V_277 ) ;
}
void F_216 ( void * V_278 )
{
F_217 ( V_278 , V_277 ) ;
}
