int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_2 = & V_3 ;
return F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( V_5 ) ;
V_5 -> V_8 = NULL ;
F_7 ( V_7 ) ;
}
static void F_8 ( struct V_6 * V_7 , int V_9 , int V_10 )
{
struct V_11 * V_12 = V_7 -> V_13 -> V_12 ;
struct V_14 * V_13 = V_7 -> V_13 ;
struct V_15 * V_16 = V_15 ( V_13 ) ;
struct V_17 * V_18 = V_13 -> V_17 ;
unsigned long V_19 ;
F_9 ( 1 ,
F_10 ( L_1 , V_7 ) ) ;
switch ( V_9 ) {
case V_20 :
V_12 -> V_21 = V_12 -> V_22 ;
break;
case V_23 :
case V_24 :
V_13 -> V_25 = V_13 -> V_26 ;
break;
case V_27 :
V_16 -> V_28 = V_16 -> V_29 ;
break;
}
if ( V_10 )
F_11 ( V_13 ) ;
F_12 ( V_18 -> V_30 , V_19 ) ;
F_13 ( V_18 , V_7 -> V_4 ) ;
F_14 ( V_18 , & V_13 -> V_31 ) ;
F_15 ( V_18 -> V_30 , V_19 ) ;
}
void F_16 ( struct V_6 * V_7 , int V_9 )
{
F_8 ( V_7 , V_9 , 1 ) ;
}
int F_17 ( struct V_14 * V_32 , const unsigned char * V_7 ,
int V_33 , void * V_34 , unsigned V_35 ,
unsigned char * V_36 , int V_37 , int V_38 , int V_19 ,
int * V_39 )
{
struct V_4 * V_5 ;
int V_40 = ( V_33 == V_41 ) ;
int V_42 = V_43 << 24 ;
V_5 = F_18 ( V_32 -> V_17 , V_40 , V_44 ) ;
if ( ! V_5 )
return V_42 ;
if ( V_35 && F_19 ( V_32 -> V_17 , V_5 ,
V_34 , V_35 , V_44 ) )
goto V_45;
V_5 -> V_46 = F_20 ( V_7 [ 0 ] ) ;
memcpy ( V_5 -> V_7 , V_7 , V_5 -> V_46 ) ;
V_5 -> V_36 = V_36 ;
V_5 -> V_47 = 0 ;
V_5 -> V_38 = V_38 ;
V_5 -> V_37 = V_37 ;
V_5 -> V_48 = V_49 ;
V_5 -> V_50 |= V_19 | V_51 | V_52 ;
F_21 ( V_5 -> V_18 , NULL , V_5 , 1 ) ;
if ( F_22 ( V_5 -> V_53 > 0 && V_5 -> V_53 <= V_35 ) )
memset ( V_34 + ( V_35 - V_5 -> V_53 ) , 0 , V_5 -> V_53 ) ;
if ( V_39 )
* V_39 = V_5 -> V_53 ;
V_42 = V_5 -> V_54 ;
V_45:
F_23 ( V_5 ) ;
return V_42 ;
}
int F_24 ( struct V_14 * V_32 , const unsigned char * V_7 ,
int V_33 , void * V_34 , unsigned V_35 ,
struct V_55 * V_56 , int V_37 , int V_38 ,
int * V_39 )
{
char * V_36 = NULL ;
int V_57 ;
if ( V_56 ) {
V_36 = F_25 ( V_58 , V_59 ) ;
if ( ! V_36 )
return V_43 << 24 ;
}
V_57 = F_17 ( V_32 , V_7 , V_33 , V_34 , V_35 ,
V_36 , V_37 , V_38 , 0 , V_39 ) ;
if ( V_56 )
F_26 ( V_36 , V_58 , V_56 ) ;
F_27 ( V_36 ) ;
return V_57 ;
}
static void F_28 ( struct V_6 * V_7 )
{
V_7 -> V_60 = 0 ;
F_29 ( V_7 , 0 ) ;
memset ( V_7 -> V_61 , 0 , V_58 ) ;
if ( V_7 -> V_46 == 0 )
V_7 -> V_46 = F_30 ( V_7 -> V_62 ) ;
}
void F_11 ( struct V_14 * V_32 )
{
struct V_11 * V_63 = V_32 -> V_12 ;
struct V_15 * V_16 = V_15 ( V_32 ) ;
unsigned long V_19 ;
F_12 ( V_63 -> V_64 , V_19 ) ;
V_63 -> V_65 -- ;
V_16 -> V_66 -- ;
if ( F_22 ( F_31 ( V_63 ) &&
( V_63 -> V_67 || V_63 -> V_68 ) ) )
F_32 ( V_63 ) ;
F_33 ( V_63 -> V_64 ) ;
F_34 ( V_32 -> V_17 -> V_30 ) ;
V_32 -> V_69 -- ;
F_15 ( V_32 -> V_17 -> V_30 , V_19 ) ;
}
static void F_35 ( struct V_14 * V_70 )
{
struct V_11 * V_63 = V_70 -> V_12 ;
struct V_14 * V_32 , * V_71 ;
struct V_15 * V_16 = V_15 ( V_70 ) ;
unsigned long V_19 ;
F_12 ( V_63 -> V_64 , V_19 ) ;
V_16 -> V_72 = NULL ;
F_15 ( V_63 -> V_64 , V_19 ) ;
F_36 ( V_70 -> V_17 ) ;
F_12 ( V_63 -> V_64 , V_19 ) ;
if ( V_16 -> V_72 )
goto V_45;
F_37 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_32 == V_70 )
continue;
if ( F_38 ( V_32 ) )
continue;
F_15 ( V_63 -> V_64 , V_19 ) ;
F_36 ( V_32 -> V_17 ) ;
F_12 ( V_63 -> V_64 , V_19 ) ;
F_39 ( V_32 ) ;
}
V_45:
F_15 ( V_63 -> V_64 , V_19 ) ;
}
static inline int F_40 ( struct V_14 * V_32 )
{
if ( V_32 -> V_69 >= V_32 -> V_73 || V_32 -> V_25 )
return 1 ;
return 0 ;
}
static inline int F_41 ( struct V_15 * V_16 )
{
return ( ( V_16 -> V_74 > 0 &&
V_16 -> V_66 >= V_16 -> V_74 ) ||
V_16 -> V_28 ) ;
}
static inline int F_42 ( struct V_11 * V_63 )
{
if ( ( V_63 -> V_74 > 0 && V_63 -> V_65 >= V_63 -> V_74 ) ||
V_63 -> V_21 || V_63 -> V_75 )
return 1 ;
return 0 ;
}
static void F_43 ( struct V_17 * V_18 )
{
struct V_14 * V_32 = V_18 -> V_76 ;
struct V_11 * V_63 ;
F_44 ( V_77 ) ;
unsigned long V_19 ;
V_63 = V_32 -> V_12 ;
if ( V_15 ( V_32 ) -> V_78 )
F_35 ( V_32 ) ;
F_12 ( V_63 -> V_64 , V_19 ) ;
F_45 ( & V_63 -> V_77 , & V_77 ) ;
while ( ! F_46 ( & V_77 ) ) {
if ( F_42 ( V_63 ) )
break;
V_32 = F_47 ( V_77 . V_79 ,
struct V_14 , V_80 ) ;
F_48 ( & V_32 -> V_80 ) ;
if ( F_41 ( V_15 ( V_32 ) ) ) {
F_49 ( & V_32 -> V_80 ,
& V_63 -> V_77 ) ;
continue;
}
F_33 ( V_63 -> V_64 ) ;
F_34 ( V_32 -> V_17 -> V_30 ) ;
F_50 ( V_32 -> V_17 ) ;
F_33 ( V_32 -> V_17 -> V_30 ) ;
F_34 ( V_63 -> V_64 ) ;
}
F_51 ( & V_77 , & V_63 -> V_77 ) ;
F_15 ( V_63 -> V_64 , V_19 ) ;
F_36 ( V_18 ) ;
}
void F_52 ( struct V_81 * V_82 )
{
struct V_14 * V_32 ;
struct V_17 * V_18 ;
V_32 = F_53 ( V_82 , struct V_14 , V_31 ) ;
V_18 = V_32 -> V_17 ;
F_43 ( V_18 ) ;
}
static void F_54 ( struct V_17 * V_18 , struct V_6 * V_7 )
{
struct V_14 * V_32 = V_7 -> V_13 ;
struct V_4 * V_5 = V_7 -> V_4 ;
unsigned long V_19 ;
F_55 ( & V_32 -> V_83 ) ;
F_12 ( V_18 -> V_30 , V_19 ) ;
F_5 ( V_5 ) ;
F_13 ( V_18 , V_5 ) ;
F_15 ( V_18 -> V_30 , V_19 ) ;
F_43 ( V_18 ) ;
F_56 ( & V_32 -> V_83 ) ;
}
void F_57 ( struct V_6 * V_7 )
{
struct V_14 * V_32 = V_7 -> V_13 ;
struct V_17 * V_18 = V_32 -> V_17 ;
F_55 ( & V_32 -> V_83 ) ;
F_7 ( V_7 ) ;
F_43 ( V_18 ) ;
F_56 ( & V_32 -> V_83 ) ;
}
void F_58 ( struct V_11 * V_63 )
{
struct V_14 * V_32 ;
F_59 (sdev, shost)
F_43 ( V_32 -> V_17 ) ;
}
static struct V_6 * F_60 ( struct V_6 * V_7 , int error ,
int V_84 , int V_85 )
{
struct V_17 * V_18 = V_7 -> V_13 -> V_17 ;
struct V_4 * V_5 = V_7 -> V_4 ;
if ( F_61 ( V_5 , error , V_84 ) ) {
if ( error && F_62 ( V_7 ) )
F_63 ( V_5 , error ) ;
else {
if ( V_85 ) {
F_64 ( V_7 ) ;
F_54 ( V_18 , V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
}
F_65 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
return NULL ;
}
static inline unsigned int F_66 ( unsigned short V_86 )
{
unsigned int V_87 ;
F_67 ( V_86 > V_88 ) ;
if ( V_86 <= 8 )
V_87 = 0 ;
else
V_87 = F_68 ( V_86 ) - 3 ;
return V_87 ;
}
static void F_69 ( struct V_89 * V_90 , unsigned int V_86 )
{
struct V_91 * V_92 ;
V_92 = V_93 + F_66 ( V_86 ) ;
F_70 ( V_90 , V_92 -> V_94 ) ;
}
static struct V_89 * F_71 ( unsigned int V_86 , T_1 V_95 )
{
struct V_91 * V_92 ;
V_92 = V_93 + F_66 ( V_86 ) ;
return F_72 ( V_92 -> V_94 , V_95 ) ;
}
static int F_73 ( struct V_96 * V_97 , int V_86 ,
T_1 V_95 )
{
int V_42 ;
F_67 ( ! V_86 ) ;
V_42 = F_74 ( & V_97 -> V_98 , V_86 , V_88 ,
V_95 , F_71 ) ;
if ( F_22 ( V_42 ) )
F_75 ( & V_97 -> V_98 , V_88 ,
F_69 ) ;
return V_42 ;
}
static void F_76 ( struct V_96 * V_97 )
{
F_75 ( & V_97 -> V_98 , V_88 , F_69 ) ;
}
static void F_65 ( struct V_6 * V_7 , int V_99 )
{
if ( V_7 -> V_97 . V_98 . V_86 )
F_76 ( & V_7 -> V_97 ) ;
memset ( & V_7 -> V_97 , 0 , sizeof( V_7 -> V_97 ) ) ;
if ( V_99 && F_77 ( V_7 ) ) {
struct V_96 * V_100 =
V_7 -> V_4 -> V_101 -> V_8 ;
F_76 ( V_100 ) ;
F_78 ( V_102 , V_100 ) ;
V_7 -> V_4 -> V_101 -> V_8 = NULL ;
}
if ( F_79 ( V_7 ) )
F_76 ( V_7 -> V_103 ) ;
}
void F_64 ( struct V_6 * V_7 )
{
F_65 ( V_7 , 1 ) ;
}
static int F_80 ( struct V_6 * V_7 , int V_57 )
{
int error = 0 ;
switch( F_81 ( V_57 ) ) {
case V_104 :
error = - V_105 ;
break;
case V_106 :
F_82 ( V_7 , V_107 ) ;
error = - V_108 ;
break;
case V_109 :
F_82 ( V_7 , V_107 ) ;
error = - V_110 ;
break;
default:
error = - V_111 ;
break;
}
return error ;
}
void F_83 ( struct V_6 * V_7 , unsigned int V_112 )
{
int V_57 = V_7 -> V_57 ;
struct V_17 * V_18 = V_7 -> V_13 -> V_17 ;
struct V_4 * V_5 = V_7 -> V_4 ;
int error = 0 ;
struct V_55 V_56 ;
int V_113 = 0 ;
int V_114 = 0 ;
enum { V_115 , V_116 , V_117 ,
V_118 } V_119 ;
char * V_120 = NULL ;
if ( V_57 ) {
V_113 = F_84 ( V_7 , & V_56 ) ;
if ( V_113 )
V_114 = F_85 ( & V_56 ) ;
}
if ( V_5 -> V_48 == V_49 ) {
if ( V_57 ) {
if ( V_113 && V_5 -> V_36 ) {
int V_121 = 8 + V_7 -> V_61 [ 7 ] ;
if ( V_121 > V_58 )
V_121 = V_58 ;
memcpy ( V_5 -> V_36 , V_7 -> V_61 , V_121 ) ;
V_5 -> V_47 = V_121 ;
}
if ( ! V_114 )
error = F_80 ( V_7 , V_57 ) ;
}
V_5 -> V_54 = V_7 -> V_57 ;
V_5 -> V_53 = F_86 ( V_7 ) ;
if ( F_77 ( V_7 ) ) {
V_5 -> V_101 -> V_53 = F_87 ( V_7 ) -> V_39 ;
F_64 ( V_7 ) ;
F_63 ( V_5 , 0 ) ;
F_57 ( V_7 ) ;
return;
}
}
F_67 ( F_88 ( V_5 ) ) ;
F_89 ( 1 , F_10 ( L_2
L_3 ,
F_90 ( V_5 ) , V_112 ) ) ;
if ( V_113 && ( V_56 . V_122 == V_123 ) ) {
if ( ( V_56 . V_124 == 0x0 ) && ( V_56 . V_125 == 0x1d ) )
;
else if ( ! ( V_5 -> V_50 & V_51 ) )
F_91 ( L_4 , V_7 ) ;
V_57 = 0 ;
error = 0 ;
}
if ( F_60 ( V_7 , error , V_112 , V_57 == 0 ) == NULL )
return;
error = F_80 ( V_7 , V_57 ) ;
if ( F_81 ( V_57 ) == V_126 ) {
V_119 = V_117 ;
} else if ( V_113 && ! V_114 ) {
switch ( V_56 . V_122 ) {
case V_127 :
if ( V_7 -> V_13 -> V_128 ) {
V_7 -> V_13 -> V_129 = 1 ;
V_120 = L_5 ;
V_119 = V_115 ;
} else {
V_119 = V_117 ;
}
break;
case V_130 :
if ( ( V_7 -> V_13 -> V_131 &&
V_56 . V_124 == 0x20 && V_56 . V_125 == 0x00 ) &&
( V_7 -> V_62 [ 0 ] == V_132 ||
V_7 -> V_62 [ 0 ] == V_133 ) ) {
V_7 -> V_13 -> V_131 = 0 ;
V_119 = V_116 ;
} else if ( V_56 . V_124 == 0x10 ) {
V_120 = L_6 ;
V_119 = V_115 ;
error = - V_134 ;
} else if ( V_56 . V_124 == 0x20 || V_56 . V_124 == 0x24 ) {
switch ( V_7 -> V_62 [ 0 ] ) {
case V_135 :
V_120 = L_7 ;
break;
case V_136 :
case V_137 :
if ( V_7 -> V_62 [ 1 ] & 0x8 )
V_120 = L_7 ;
else
V_120 =
L_8 ;
break;
default:
V_120 = L_9 ;
break;
}
V_119 = V_115 ;
error = - V_108 ;
} else
V_119 = V_115 ;
break;
case V_138 :
V_119 = V_115 ;
if ( V_56 . V_124 == 0x10 ) {
V_120 = L_10 ;
error = - V_134 ;
}
break;
case V_139 :
if ( V_56 . V_124 == 0x04 ) {
switch ( V_56 . V_125 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_119 = V_118 ;
break;
default:
V_120 = L_11 ;
V_119 = V_115 ;
break;
}
} else {
V_120 = L_11 ;
V_119 = V_115 ;
}
break;
case V_140 :
V_119 = V_115 ;
break;
default:
V_120 = L_12 ;
V_119 = V_115 ;
break;
}
} else {
V_120 = L_13 ;
V_119 = V_115 ;
}
switch ( V_119 ) {
case V_115 :
F_64 ( V_7 ) ;
if ( ! ( V_5 -> V_50 & V_51 ) ) {
if ( V_120 )
F_92 ( V_141 , V_7 , L_14 ,
V_120 ) ;
F_93 ( V_7 ) ;
if ( F_94 ( V_57 ) & V_142 )
F_91 ( L_4 , V_7 ) ;
F_95 ( V_7 ) ;
}
if ( F_96 ( V_5 , error ) )
F_54 ( V_18 , V_7 ) ;
else
F_57 ( V_7 ) ;
break;
case V_116 :
F_64 ( V_7 ) ;
F_54 ( V_18 , V_7 ) ;
break;
case V_117 :
F_8 ( V_7 , V_24 , 0 ) ;
break;
case V_118 :
F_8 ( V_7 , V_23 , 0 ) ;
break;
}
}
static int F_97 ( struct V_4 * V_5 , struct V_96 * V_97 ,
T_1 V_95 )
{
int V_143 ;
if ( F_22 ( F_73 ( V_97 , V_5 -> V_144 ,
V_95 ) ) ) {
return V_145 ;
}
V_5 -> V_34 = NULL ;
V_143 = F_98 ( V_5 -> V_18 , V_5 , V_97 -> V_98 . V_90 ) ;
F_67 ( V_143 > V_97 -> V_98 . V_86 ) ;
V_97 -> V_98 . V_86 = V_143 ;
V_97 -> V_146 = F_99 ( V_5 ) ;
return V_147 ;
}
int F_100 ( struct V_6 * V_7 , T_1 V_95 )
{
struct V_4 * V_148 = V_7 -> V_4 ;
int error = F_97 ( V_148 , & V_7 -> V_97 , V_95 ) ;
if ( error )
goto V_149;
if ( F_88 ( V_148 ) ) {
struct V_96 * V_100 = F_101 (
V_102 , V_150 ) ;
if ( ! V_100 ) {
error = V_145 ;
goto V_149;
}
V_148 -> V_101 -> V_8 = V_100 ;
error = F_97 ( V_148 -> V_101 , V_100 , V_150 ) ;
if ( error )
goto V_149;
}
if ( F_102 ( V_148 ) ) {
struct V_96 * V_103 = V_7 -> V_103 ;
int V_151 , V_143 ;
F_67 ( V_103 == NULL ) ;
V_151 = F_103 ( V_148 -> V_18 , V_148 -> V_152 ) ;
if ( F_73 ( V_103 , V_151 , V_95 ) ) {
error = V_145 ;
goto V_149;
}
V_143 = F_104 ( V_148 -> V_18 , V_148 -> V_152 ,
V_103 -> V_98 . V_90 ) ;
F_67 ( F_22 ( V_143 > V_151 ) ) ;
F_67 ( F_22 ( V_143 > F_105 ( V_148 -> V_18 ) ) ) ;
V_7 -> V_103 = V_103 ;
V_7 -> V_103 -> V_98 . V_86 = V_143 ;
}
return V_147 ;
V_149:
F_64 ( V_7 ) ;
V_7 -> V_4 -> V_8 = NULL ;
F_7 ( V_7 ) ;
return error ;
}
static struct V_6 * F_106 ( struct V_14 * V_32 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
if ( ! V_5 -> V_8 ) {
V_7 = F_107 ( V_32 , V_150 ) ;
if ( F_22 ( ! V_7 ) )
return NULL ;
V_5 -> V_8 = V_7 ;
} else {
V_7 = V_5 -> V_8 ;
}
V_7 -> V_153 = V_5 -> V_153 ;
V_7 -> V_4 = V_5 ;
V_7 -> V_62 = V_5 -> V_7 ;
V_7 -> V_154 = V_155 ;
return V_7 ;
}
int F_108 ( struct V_14 * V_32 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_42 = F_109 ( V_32 , V_5 ) ;
if ( V_42 != V_147 )
return V_42 ;
V_7 = F_106 ( V_32 , V_5 ) ;
if ( F_22 ( ! V_7 ) )
return V_145 ;
if ( V_5 -> V_152 ) {
int V_42 ;
F_67 ( ! V_5 -> V_144 ) ;
V_42 = F_100 ( V_7 , V_150 ) ;
if ( F_22 ( V_42 ) )
return V_42 ;
} else {
F_67 ( F_99 ( V_5 ) ) ;
memset ( & V_7 -> V_97 , 0 , sizeof( V_7 -> V_97 ) ) ;
V_5 -> V_34 = NULL ;
}
V_7 -> V_46 = V_5 -> V_46 ;
if ( ! F_99 ( V_5 ) )
V_7 -> V_156 = V_157 ;
else if ( F_110 ( V_5 ) == V_158 )
V_7 -> V_156 = V_41 ;
else
V_7 -> V_156 = V_159 ;
V_7 -> V_160 = F_99 ( V_5 ) ;
V_7 -> V_161 = V_5 -> V_38 ;
return V_147 ;
}
int F_111 ( struct V_14 * V_32 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_42 = F_109 ( V_32 , V_5 ) ;
if ( V_42 != V_147 )
return V_42 ;
if ( F_22 ( V_32 -> V_162 && V_32 -> V_162 -> V_163
&& V_32 -> V_162 -> V_163 -> V_164 ) ) {
V_42 = V_32 -> V_162 -> V_163 -> V_164 ( V_32 , V_5 ) ;
if ( V_42 != V_147 )
return V_42 ;
}
F_67 ( ! V_5 -> V_144 ) ;
V_7 = F_106 ( V_32 , V_5 ) ;
if ( F_22 ( ! V_7 ) )
return V_145 ;
memset ( V_7 -> V_62 , 0 , V_165 ) ;
return F_100 ( V_7 , V_150 ) ;
}
int F_109 ( struct V_14 * V_32 , struct V_4 * V_5 )
{
int V_42 = V_147 ;
if ( F_22 ( V_32 -> V_166 != V_167 ) ) {
switch ( V_32 -> V_166 ) {
case V_168 :
case V_169 :
F_112 ( V_170 , V_32 ,
L_15 ) ;
V_42 = V_171 ;
break;
case V_172 :
F_112 ( V_170 , V_32 ,
L_16 ) ;
V_42 = V_171 ;
break;
case V_173 :
case V_174 :
case V_175 :
if ( ! ( V_5 -> V_50 & V_52 ) )
V_42 = V_145 ;
break;
default:
if ( ! ( V_5 -> V_50 & V_52 ) )
V_42 = V_171 ;
break;
}
}
return V_42 ;
}
int F_113 ( struct V_17 * V_18 , struct V_4 * V_5 , int V_42 )
{
struct V_14 * V_32 = V_18 -> V_76 ;
switch ( V_42 ) {
case V_171 :
V_5 -> V_54 = V_176 << 16 ;
if ( V_5 -> V_8 ) {
struct V_6 * V_7 = V_5 -> V_8 ;
F_64 ( V_7 ) ;
F_7 ( V_7 ) ;
V_5 -> V_8 = NULL ;
}
break;
case V_145 :
if ( V_32 -> V_69 == 0 )
F_114 ( V_18 , V_177 ) ;
break;
default:
V_5 -> V_50 |= V_178 ;
}
return V_42 ;
}
int F_115 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_14 * V_32 = V_18 -> V_76 ;
int V_42 = V_171 ;
if ( V_5 -> V_48 == V_49 )
V_42 = F_108 ( V_32 , V_5 ) ;
return F_113 ( V_18 , V_5 , V_42 ) ;
}
static inline int F_116 ( struct V_17 * V_18 ,
struct V_14 * V_32 )
{
if ( V_32 -> V_69 == 0 && V_32 -> V_25 ) {
if ( -- V_32 -> V_25 == 0 ) {
F_9 ( 3 ,
F_112 ( V_141 , V_32 ,
L_17 ) ) ;
} else {
F_114 ( V_18 , V_177 ) ;
return 0 ;
}
}
if ( F_40 ( V_32 ) )
return 0 ;
return 1 ;
}
static inline int F_117 ( struct V_11 * V_63 ,
struct V_14 * V_32 )
{
struct V_15 * V_16 = V_15 ( V_32 ) ;
if ( V_16 -> V_78 ) {
if ( V_16 -> V_72 &&
V_16 -> V_72 != V_32 )
return 0 ;
V_16 -> V_72 = V_32 ;
}
if ( V_16 -> V_66 == 0 && V_16 -> V_28 ) {
if ( -- V_16 -> V_28 == 0 ) {
F_9 ( 3 , F_118 ( V_141 , V_16 ,
L_18 ) ) ;
} else
return 0 ;
}
if ( F_41 ( V_16 ) ) {
F_49 ( & V_32 -> V_80 , & V_63 -> V_77 ) ;
return 0 ;
}
return 1 ;
}
static inline int F_119 ( struct V_17 * V_18 ,
struct V_11 * V_63 ,
struct V_14 * V_32 )
{
if ( F_31 ( V_63 ) )
return 0 ;
if ( V_63 -> V_65 == 0 && V_63 -> V_21 ) {
if ( -- V_63 -> V_21 == 0 ) {
F_9 ( 3 ,
F_10 ( L_19 ,
V_63 -> V_179 ) ) ;
} else {
return 0 ;
}
}
if ( F_42 ( V_63 ) ) {
if ( F_46 ( & V_32 -> V_80 ) )
F_120 ( & V_32 -> V_80 , & V_63 -> V_77 ) ;
return 0 ;
}
if ( ! F_46 ( & V_32 -> V_80 ) )
F_48 ( & V_32 -> V_80 ) ;
return 1 ;
}
static int F_121 ( struct V_17 * V_18 )
{
struct V_14 * V_32 = V_18 -> V_76 ;
struct V_11 * V_63 ;
if ( F_122 ( V_18 ) )
return 0 ;
V_63 = V_32 -> V_12 ;
if ( F_31 ( V_63 ) || F_40 ( V_32 ) )
return 1 ;
return 0 ;
}
static void F_123 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_14 * V_32 ;
struct V_15 * V_16 ;
struct V_11 * V_63 ;
F_124 ( V_5 ) ;
F_92 ( V_141 , V_7 , L_20 ) ;
V_32 = V_7 -> V_13 ;
V_16 = V_15 ( V_32 ) ;
V_63 = V_32 -> V_12 ;
F_28 ( V_7 ) ;
V_7 -> V_57 = V_176 << 16 ;
F_125 ( & V_7 -> V_13 -> V_180 ) ;
V_32 -> V_69 ++ ;
F_33 ( V_32 -> V_17 -> V_30 ) ;
F_34 ( V_63 -> V_64 ) ;
V_63 -> V_65 ++ ;
V_16 -> V_66 ++ ;
F_33 ( V_63 -> V_64 ) ;
F_34 ( V_32 -> V_17 -> V_30 ) ;
F_126 ( V_5 ) ;
}
static void F_127 ( struct V_4 * V_148 )
{
struct V_6 * V_7 = V_148 -> V_8 ;
unsigned long V_181 = ( V_7 -> V_161 + 1 ) * V_148 -> V_37 ;
int V_182 ;
F_128 ( & V_7 -> V_183 ) ;
F_125 ( & V_7 -> V_13 -> V_184 ) ;
if ( V_7 -> V_57 )
F_125 ( & V_7 -> V_13 -> V_185 ) ;
V_182 = F_129 ( V_7 ) ;
if ( V_182 != V_186 &&
F_130 ( V_7 -> V_187 + V_181 , V_188 ) ) {
F_112 ( V_170 , V_7 -> V_13 ,
L_21 ,
V_181 / V_189 ) ;
V_182 = V_186 ;
}
F_131 ( V_7 , V_182 ) ;
switch ( V_182 ) {
case V_186 :
F_132 ( V_7 ) ;
break;
case V_190 :
F_16 ( V_7 , V_24 ) ;
break;
case V_191 :
F_16 ( V_7 , V_23 ) ;
break;
default:
if ( ! F_133 ( V_7 , 0 ) )
F_132 ( V_7 ) ;
}
}
static void F_134 ( struct V_17 * V_18 )
{
struct V_14 * V_32 = V_18 -> V_76 ;
struct V_11 * V_63 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
if( ! F_55 ( & V_32 -> V_83 ) )
return;
V_63 = V_32 -> V_12 ;
for (; ; ) {
int V_192 ;
V_5 = F_135 ( V_18 ) ;
if ( ! V_5 || ! F_116 ( V_18 , V_32 ) )
break;
if ( F_22 ( ! F_136 ( V_32 ) ) ) {
F_112 ( V_170 , V_32 ,
L_15 ) ;
F_123 ( V_5 , V_18 ) ;
continue;
}
if ( ! ( F_137 ( V_18 ) && ! F_138 ( V_18 , V_5 ) ) )
F_124 ( V_5 ) ;
V_32 -> V_69 ++ ;
F_33 ( V_18 -> V_30 ) ;
V_7 = V_5 -> V_8 ;
if ( F_22 ( V_7 == NULL ) ) {
F_10 ( V_193 L_22
L_23
L_24 ,
V_194 ) ;
F_139 ( V_5 , L_25 ) ;
F_140 () ;
}
F_34 ( V_63 -> V_64 ) ;
if ( F_137 ( V_18 ) && ! F_141 ( V_5 ) ) {
if ( F_46 ( & V_32 -> V_80 ) )
F_120 ( & V_32 -> V_80 ,
& V_63 -> V_77 ) ;
goto V_195;
}
if ( ! F_117 ( V_63 , V_32 ) )
goto V_195;
if ( ! F_119 ( V_18 , V_63 , V_32 ) )
goto V_195;
V_15 ( V_32 ) -> V_66 ++ ;
V_63 -> V_65 ++ ;
F_142 ( V_63 -> V_64 ) ;
F_28 ( V_7 ) ;
V_192 = F_143 ( V_7 ) ;
F_144 ( V_18 -> V_30 ) ;
if ( V_192 )
goto V_196;
}
goto V_45;
V_195:
F_142 ( V_63 -> V_64 ) ;
F_144 ( V_18 -> V_30 ) ;
F_13 ( V_18 , V_5 ) ;
V_32 -> V_69 -- ;
V_196:
if ( V_32 -> V_69 == 0 )
F_114 ( V_18 , V_177 ) ;
V_45:
F_142 ( V_18 -> V_30 ) ;
F_56 ( & V_32 -> V_83 ) ;
F_144 ( V_18 -> V_30 ) ;
}
T_2 F_145 ( struct V_11 * V_63 )
{
struct V_13 * V_197 ;
T_2 V_198 = 0xffffffff ;
if ( V_63 -> V_199 )
return V_200 ;
if ( ! V_201 )
return V_202 ;
V_197 = F_146 ( V_63 ) ;
if ( V_197 && V_197 -> V_203 )
V_198 = * V_197 -> V_203 ;
return V_198 ;
}
struct V_17 * F_147 ( struct V_11 * V_63 ,
T_3 * V_204 )
{
struct V_17 * V_18 ;
struct V_13 * V_205 = V_63 -> V_206 ;
V_18 = F_148 ( V_204 , NULL ) ;
if ( ! V_18 )
return NULL ;
F_149 ( V_18 , F_150 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_151 ( V_63 ) ) {
V_63 -> V_207 =
F_152 ( V_63 -> V_207 ,
( unsigned short ) V_208 ) ;
F_67 ( V_63 -> V_207 < V_63 -> V_209 ) ;
F_153 ( V_18 , V_63 -> V_207 ) ;
}
F_154 ( V_18 , V_63 -> V_210 ) ;
F_155 ( V_18 , F_145 ( V_63 ) ) ;
F_156 ( V_18 , V_63 -> V_211 ) ;
F_157 ( V_205 , V_63 -> V_211 ) ;
F_158 ( V_18 , F_159 ( V_205 ) ) ;
if ( ! V_63 -> V_212 )
V_18 -> V_213 . V_214 = 0 ;
F_160 ( V_18 , 0x03 ) ;
return V_18 ;
}
struct V_17 * F_161 ( struct V_14 * V_32 )
{
struct V_17 * V_18 ;
V_18 = F_147 ( V_32 -> V_12 , F_134 ) ;
if ( ! V_18 )
return NULL ;
F_162 ( V_18 , F_115 ) ;
F_163 ( V_18 , F_127 ) ;
F_164 ( V_18 , V_215 ) ;
F_165 ( V_18 , F_121 ) ;
return V_18 ;
}
void F_166 ( struct V_11 * V_63 )
{
V_63 -> V_75 = 1 ;
}
void F_167 ( struct V_11 * V_63 )
{
V_63 -> V_75 = 0 ;
F_58 ( V_63 ) ;
}
int T_4 F_168 ( void )
{
int V_216 ;
V_102 = F_169 ( L_26 ,
sizeof( struct V_96 ) ,
0 , 0 , NULL ) ;
if ( ! V_102 ) {
F_10 ( V_170 L_27 ) ;
return - V_217 ;
}
for ( V_216 = 0 ; V_216 < V_218 ; V_216 ++ ) {
struct V_91 * V_92 = V_93 + V_216 ;
int V_219 = V_92 -> V_219 * sizeof( struct V_89 ) ;
V_92 -> V_220 = F_169 ( V_92 -> V_221 , V_219 , 0 ,
V_222 , NULL ) ;
if ( ! V_92 -> V_220 ) {
F_10 ( V_170 L_28 ,
V_92 -> V_221 ) ;
goto V_223;
}
V_92 -> V_94 = F_170 ( V_224 ,
V_92 -> V_220 ) ;
if ( ! V_92 -> V_94 ) {
F_10 ( V_170 L_29 ,
V_92 -> V_221 ) ;
goto V_223;
}
}
return 0 ;
V_223:
for ( V_216 = 0 ; V_216 < V_218 ; V_216 ++ ) {
struct V_91 * V_92 = V_93 + V_216 ;
if ( V_92 -> V_94 )
F_171 ( V_92 -> V_94 ) ;
if ( V_92 -> V_220 )
F_172 ( V_92 -> V_220 ) ;
}
F_172 ( V_102 ) ;
return - V_217 ;
}
void F_173 ( void )
{
int V_216 ;
F_172 ( V_102 ) ;
for ( V_216 = 0 ; V_216 < V_218 ; V_216 ++ ) {
struct V_91 * V_92 = V_93 + V_216 ;
F_171 ( V_92 -> V_94 ) ;
F_172 ( V_92 -> V_220 ) ;
}
}
int
F_174 ( struct V_14 * V_32 , int V_225 , int V_226 , int V_227 ,
unsigned char * V_34 , int V_121 , int V_37 , int V_38 ,
struct V_228 * V_229 , struct V_55 * V_56 )
{
unsigned char V_7 [ 10 ] ;
unsigned char * V_230 ;
int V_42 ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_7 [ 1 ] = ( V_225 ? 0x10 : 0 ) | ( V_226 ? 0x01 : 0 ) ;
if ( V_32 -> V_231 ) {
if ( V_121 > 65535 )
return - V_232 ;
V_230 = F_175 ( 8 + V_121 , V_233 ) ;
if ( ! V_230 )
return - V_217 ;
memcpy ( V_230 + 8 , V_34 , V_121 ) ;
V_121 += 8 ;
V_230 [ 0 ] = 0 ;
V_230 [ 1 ] = 0 ;
V_230 [ 2 ] = V_229 -> V_234 ;
V_230 [ 3 ] = V_229 -> V_235 ;
V_230 [ 4 ] = V_229 -> V_236 ? 0x01 : 0 ;
V_230 [ 5 ] = 0 ;
V_230 [ 6 ] = V_229 -> V_237 >> 8 ;
V_230 [ 7 ] = V_229 -> V_237 ;
V_7 [ 0 ] = V_238 ;
V_7 [ 7 ] = V_121 >> 8 ;
V_7 [ 8 ] = V_121 ;
} else {
if ( V_121 > 255 || V_229 -> V_237 > 255 ||
V_229 -> V_236 )
return - V_232 ;
V_230 = F_175 ( 4 + V_121 , V_233 ) ;
if ( ! V_230 )
return - V_217 ;
memcpy ( V_230 + 4 , V_34 , V_121 ) ;
V_121 += 4 ;
V_230 [ 0 ] = 0 ;
V_230 [ 1 ] = V_229 -> V_234 ;
V_230 [ 2 ] = V_229 -> V_235 ;
V_230 [ 3 ] = V_229 -> V_237 ;
V_7 [ 0 ] = V_239 ;
V_7 [ 4 ] = V_121 ;
}
V_42 = F_24 ( V_32 , V_7 , V_41 , V_230 , V_121 ,
V_56 , V_37 , V_38 , NULL ) ;
F_27 ( V_230 ) ;
return V_42 ;
}
int
F_176 ( struct V_14 * V_32 , int V_240 , int V_227 ,
unsigned char * V_34 , int V_121 , int V_37 , int V_38 ,
struct V_228 * V_229 , struct V_55 * V_56 )
{
unsigned char V_7 [ 12 ] ;
int V_231 ;
int V_241 ;
int V_57 ;
struct V_55 V_242 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
memset ( & V_7 [ 0 ] , 0 , 12 ) ;
V_7 [ 1 ] = V_240 & 0x18 ;
V_7 [ 2 ] = V_227 ;
if ( ! V_56 )
V_56 = & V_242 ;
V_243:
V_231 = V_32 -> V_231 ;
if ( V_231 ) {
if ( V_121 < 8 )
V_121 = 8 ;
V_7 [ 0 ] = V_244 ;
V_7 [ 8 ] = V_121 ;
V_241 = 8 ;
} else {
if ( V_121 < 4 )
V_121 = 4 ;
V_7 [ 0 ] = V_245 ;
V_7 [ 4 ] = V_121 ;
V_241 = 4 ;
}
memset ( V_34 , 0 , V_121 ) ;
V_57 = F_24 ( V_32 , V_7 , V_159 , V_34 , V_121 ,
V_56 , V_37 , V_38 , NULL ) ;
if ( V_231 && ! F_177 ( V_57 ) &&
( F_94 ( V_57 ) & V_142 ) ) {
if ( F_178 ( V_56 ) ) {
if ( ( V_56 -> V_122 == V_130 ) &&
( V_56 -> V_124 == 0x20 ) && ( V_56 -> V_125 == 0 ) ) {
V_32 -> V_231 = 0 ;
goto V_243;
}
}
}
if( F_177 ( V_57 ) ) {
if ( F_22 ( V_34 [ 0 ] == 0x86 && V_34 [ 1 ] == 0x0b &&
( V_227 == 6 || V_227 == 8 ) ) ) {
V_241 = 0 ;
V_229 -> V_146 = 13 ;
V_229 -> V_234 = 0 ;
V_229 -> V_235 = 0 ;
V_229 -> V_236 = 0 ;
V_229 -> V_237 = 0 ;
} else if( V_231 ) {
V_229 -> V_146 = V_34 [ 0 ] * 256 + V_34 [ 1 ] + 2 ;
V_229 -> V_234 = V_34 [ 2 ] ;
V_229 -> V_235 = V_34 [ 3 ] ;
V_229 -> V_236 = V_34 [ 4 ] & 0x01 ;
V_229 -> V_237 = V_34 [ 6 ] * 256
+ V_34 [ 7 ] ;
} else {
V_229 -> V_146 = V_34 [ 0 ] + 1 ;
V_229 -> V_234 = V_34 [ 1 ] ;
V_229 -> V_235 = V_34 [ 2 ] ;
V_229 -> V_237 = V_34 [ 3 ] ;
}
V_229 -> V_241 = V_241 ;
}
return V_57 ;
}
int
F_179 ( struct V_14 * V_32 , int V_37 , int V_38 ,
struct V_55 * V_246 )
{
char V_7 [] = {
V_247 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_55 * V_56 ;
int V_57 ;
if ( ! V_246 )
V_56 = F_25 ( sizeof( * V_56 ) , V_233 ) ;
else
V_56 = V_246 ;
do {
V_57 = F_24 ( V_32 , V_7 , V_157 , NULL , 0 , V_56 ,
V_37 , V_38 , NULL ) ;
if ( V_32 -> V_128 && F_178 ( V_56 ) &&
V_56 -> V_122 == V_127 )
V_32 -> V_129 = 1 ;
} while ( F_178 ( V_56 ) &&
V_56 -> V_122 == V_127 && -- V_38 );
if ( ! V_246 )
F_27 ( V_56 ) ;
return V_57 ;
}
int
F_180 ( struct V_14 * V_32 , enum V_248 V_249 )
{
enum V_248 V_250 = V_32 -> V_166 ;
if ( V_249 == V_250 )
return 0 ;
switch ( V_249 ) {
case V_251 :
switch ( V_250 ) {
case V_175 :
break;
default:
goto V_252;
}
break;
case V_167 :
switch ( V_250 ) {
case V_251 :
case V_168 :
case V_169 :
case V_173 :
case V_174 :
break;
default:
goto V_252;
}
break;
case V_173 :
switch ( V_250 ) {
case V_167 :
case V_168 :
case V_169 :
break;
default:
goto V_252;
}
break;
case V_168 :
case V_169 :
switch ( V_250 ) {
case V_251 :
case V_167 :
case V_173 :
case V_174 :
break;
default:
goto V_252;
}
break;
case V_174 :
switch ( V_250 ) {
case V_167 :
case V_175 :
break;
default:
goto V_252;
}
break;
case V_175 :
switch ( V_250 ) {
case V_251 :
break;
default:
goto V_252;
}
break;
case V_253 :
switch ( V_250 ) {
case V_251 :
case V_167 :
case V_173 :
case V_168 :
case V_169 :
case V_174 :
break;
default:
goto V_252;
}
break;
case V_172 :
switch ( V_250 ) {
case V_251 :
case V_167 :
case V_168 :
case V_169 :
case V_253 :
break;
default:
goto V_252;
}
break;
}
V_32 -> V_166 = V_249 ;
return 0 ;
V_252:
F_181 ( 1 ,
F_112 ( V_170 , V_32 ,
L_30 ,
F_182 ( V_250 ) ,
F_182 ( V_249 ) )
) ;
return - V_232 ;
}
static void F_183 ( struct V_14 * V_32 , struct V_254 * V_255 )
{
int V_256 = 0 ;
char * V_257 [ 3 ] ;
switch ( V_255 -> V_258 ) {
case V_259 :
V_257 [ V_256 ++ ] = L_31 ;
break;
default:
break;
}
V_257 [ V_256 ++ ] = NULL ;
F_184 ( & V_32 -> V_83 . V_260 , V_261 , V_257 ) ;
}
void F_185 ( struct V_81 * V_82 )
{
struct V_14 * V_32 ;
F_44 ( V_262 ) ;
V_32 = F_53 ( V_82 , struct V_14 , V_263 ) ;
while ( 1 ) {
struct V_254 * V_255 ;
struct V_264 * V_265 , * V_71 ;
unsigned long V_19 ;
F_12 ( & V_32 -> V_266 , V_19 ) ;
F_45 ( & V_32 -> V_262 , & V_262 ) ;
F_15 ( & V_32 -> V_266 , V_19 ) ;
if ( F_46 ( & V_262 ) )
break;
F_186 (this, tmp, &event_list) {
V_255 = F_47 ( V_265 , struct V_254 , V_267 ) ;
F_187 ( & V_255 -> V_267 ) ;
F_183 ( V_32 , V_255 ) ;
F_27 ( V_255 ) ;
}
}
}
void F_188 ( struct V_14 * V_32 , struct V_254 * V_255 )
{
unsigned long V_19 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_12 ( & V_32 -> V_266 , V_19 ) ;
F_120 ( & V_255 -> V_267 , & V_32 -> V_262 ) ;
F_189 ( & V_32 -> V_263 ) ;
F_15 ( & V_32 -> V_266 , V_19 ) ;
}
struct V_254 * F_190 ( enum V_268 V_258 ,
T_1 V_269 )
{
struct V_254 * V_255 = F_25 ( sizeof( struct V_254 ) , V_269 ) ;
if ( ! V_255 )
return NULL ;
V_255 -> V_258 = V_258 ;
F_128 ( & V_255 -> V_267 ) ;
switch ( V_258 ) {
case V_259 :
default:
break;
}
return V_255 ;
}
void F_191 ( struct V_14 * V_32 ,
enum V_268 V_258 , T_1 V_269 )
{
struct V_254 * V_255 = F_190 ( V_258 , V_269 ) ;
if ( ! V_255 ) {
F_112 ( V_170 , V_32 , L_32 ,
V_258 ) ;
return;
}
F_188 ( V_32 , V_255 ) ;
}
int
F_192 ( struct V_14 * V_32 )
{
int V_270 = F_180 ( V_32 , V_173 ) ;
if ( V_270 )
return V_270 ;
F_43 ( V_32 -> V_17 ) ;
while ( V_32 -> V_69 ) {
F_193 ( 200 ) ;
F_43 ( V_32 -> V_17 ) ;
}
return 0 ;
}
void F_194 ( struct V_14 * V_32 )
{
if ( V_32 -> V_166 != V_173 ||
F_180 ( V_32 , V_167 ) )
return;
F_43 ( V_32 -> V_17 ) ;
}
static void
F_195 ( struct V_14 * V_32 , void * V_229 )
{
F_192 ( V_32 ) ;
}
void
F_196 ( struct V_15 * V_16 )
{
F_197 ( V_16 , NULL , F_195 ) ;
}
static void
F_198 ( struct V_14 * V_32 , void * V_229 )
{
F_194 ( V_32 ) ;
}
void
F_199 ( struct V_15 * V_16 )
{
F_197 ( V_16 , NULL , F_198 ) ;
}
int
F_200 ( struct V_14 * V_32 )
{
struct V_17 * V_18 = V_32 -> V_17 ;
unsigned long V_19 ;
int V_270 = 0 ;
V_270 = F_180 ( V_32 , V_174 ) ;
if ( V_270 ) {
V_270 = F_180 ( V_32 , V_175 ) ;
if ( V_270 )
return V_270 ;
}
F_12 ( V_18 -> V_30 , V_19 ) ;
F_201 ( V_18 ) ;
F_15 ( V_18 -> V_30 , V_19 ) ;
return 0 ;
}
int
F_202 ( struct V_14 * V_32 ,
enum V_248 V_271 )
{
struct V_17 * V_18 = V_32 -> V_17 ;
unsigned long V_19 ;
if ( ( V_32 -> V_166 == V_174 ) ||
( V_32 -> V_166 == V_169 ) )
V_32 -> V_166 = V_271 ;
else if ( V_32 -> V_166 == V_175 ) {
if ( V_271 == V_169 ||
V_271 == V_168 )
V_32 -> V_166 = V_271 ;
else
V_32 -> V_166 = V_251 ;
} else if ( V_32 -> V_166 != V_253 &&
V_32 -> V_166 != V_168 )
return - V_232 ;
F_12 ( V_18 -> V_30 , V_19 ) ;
F_203 ( V_18 ) ;
F_15 ( V_18 -> V_30 , V_19 ) ;
return 0 ;
}
static void
F_204 ( struct V_14 * V_32 , void * V_229 )
{
F_200 ( V_32 ) ;
}
static int
F_205 ( struct V_13 * V_205 , void * V_229 )
{
if ( F_206 ( V_205 ) )
F_197 ( F_207 ( V_205 ) , NULL ,
F_204 ) ;
return 0 ;
}
void
F_208 ( struct V_13 * V_205 )
{
if ( F_206 ( V_205 ) )
F_197 ( F_207 ( V_205 ) , NULL ,
F_204 ) ;
else
F_209 ( V_205 , NULL , F_205 ) ;
}
static void
F_210 ( struct V_14 * V_32 , void * V_229 )
{
F_202 ( V_32 , * (enum V_248 * ) V_229 ) ;
}
static int
F_211 ( struct V_13 * V_205 , void * V_229 )
{
if ( F_206 ( V_205 ) )
F_197 ( F_207 ( V_205 ) , V_229 ,
F_210 ) ;
return 0 ;
}
void
F_212 ( struct V_13 * V_205 , enum V_248 V_271 )
{
if ( F_206 ( V_205 ) )
F_197 ( F_207 ( V_205 ) , & V_271 ,
F_210 ) ;
else
F_209 ( V_205 , & V_271 , F_211 ) ;
}
void * F_213 ( struct V_89 * V_90 , int V_272 ,
T_5 * V_273 , T_5 * V_121 )
{
int V_216 ;
T_5 V_274 = 0 , V_275 = 0 ;
struct V_89 * V_276 ;
struct V_277 * V_277 ;
F_214 ( ! F_215 () ) ;
F_216 (sgl, sg, sg_count, i) {
V_275 = V_274 ;
V_274 += V_276 -> V_146 ;
if ( V_274 > * V_273 )
break;
}
if ( F_22 ( V_216 == V_272 ) ) {
F_10 ( V_170 L_33
L_34 ,
V_194 , V_274 , * V_273 , V_272 ) ;
F_214 ( 1 ) ;
return NULL ;
}
* V_273 = * V_273 - V_275 + V_276 -> V_273 ;
V_277 = F_217 ( F_218 ( V_276 ) , ( * V_273 >> V_278 ) ) ;
* V_273 &= ~ V_279 ;
V_274 = V_280 - * V_273 ;
if ( * V_121 > V_274 )
* V_121 = V_274 ;
return F_219 ( V_277 ) ;
}
void F_220 ( void * V_281 )
{
F_221 ( V_281 ) ;
}
