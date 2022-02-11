static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_5 ;
struct V_7 * V_6 = V_2 -> V_6 ;
struct V_8 * V_9 = V_8 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
F_2 ( & V_5 -> V_11 , V_5 -> V_12 ) ;
break;
case V_13 :
case V_14 :
F_2 ( & V_6 -> V_15 ,
V_6 -> V_16 ) ;
break;
case V_17 :
F_2 ( & V_9 -> V_18 ,
V_9 -> V_19 ) ;
break;
}
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
F_4 ( V_2 -> V_23 ) ;
F_5 ( V_22 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , int V_25 )
{
struct V_7 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = V_6 -> V_21 ;
unsigned long V_26 ;
F_8 ( 1 , F_9 ( V_27 , V_2 ,
L_1 , V_2 ) ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_25 )
F_10 ( V_6 ) ;
V_2 -> V_28 = 0 ;
if ( V_22 -> V_29 ) {
F_3 ( V_2 ) ;
return;
}
F_11 ( V_22 -> V_30 , V_26 ) ;
F_12 ( V_22 , V_2 -> V_23 ) ;
F_13 ( & V_6 -> V_31 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
void F_15 ( struct V_1 * V_2 , int V_3 )
{
F_7 ( V_2 , V_3 , 1 ) ;
}
int F_16 ( struct V_7 * V_20 , const unsigned char * V_2 ,
int V_32 , void * V_33 , unsigned V_34 ,
unsigned char * V_35 , int V_36 , int V_37 , T_1 V_26 ,
int * V_38 )
{
struct V_23 * V_39 ;
int V_40 = ( V_32 == V_41 ) ;
int V_42 = V_43 << 24 ;
V_39 = F_17 ( V_20 -> V_21 , V_40 , V_44 ) ;
if ( F_18 ( V_39 ) )
return V_42 ;
F_19 ( V_39 ) ;
if ( V_34 && F_20 ( V_20 -> V_21 , V_39 ,
V_33 , V_34 , V_44 ) )
goto V_45;
V_39 -> V_46 = F_21 ( V_2 [ 0 ] ) ;
memcpy ( V_39 -> V_2 , V_2 , V_39 -> V_46 ) ;
V_39 -> V_35 = V_35 ;
V_39 -> V_47 = 0 ;
V_39 -> V_37 = V_37 ;
V_39 -> V_36 = V_36 ;
V_39 -> V_48 |= V_26 | V_49 | V_50 ;
F_22 ( V_39 -> V_22 , NULL , V_39 , 1 ) ;
if ( F_23 ( V_39 -> V_51 > 0 && V_39 -> V_51 <= V_34 ) )
memset ( V_33 + ( V_34 - V_39 -> V_51 ) , 0 , V_39 -> V_51 ) ;
if ( V_38 )
* V_38 = V_39 -> V_51 ;
V_42 = V_39 -> V_52 ;
V_45:
F_24 ( V_39 ) ;
return V_42 ;
}
int F_25 ( struct V_7 * V_20 , const unsigned char * V_2 ,
int V_32 , void * V_33 , unsigned V_34 ,
struct V_53 * V_54 , int V_36 , int V_37 ,
int * V_38 , T_1 V_26 )
{
char * V_35 = NULL ;
int V_28 ;
if ( V_54 ) {
V_35 = F_26 ( V_55 , V_56 ) ;
if ( ! V_35 )
return V_43 << 24 ;
}
V_28 = F_16 ( V_20 , V_2 , V_32 , V_33 , V_34 ,
V_35 , V_36 , V_37 , V_26 , V_38 ) ;
if ( V_54 )
F_27 ( V_35 , V_55 , V_54 ) ;
F_28 ( V_35 ) ;
return V_28 ;
}
static void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_57 = 0 ;
F_30 ( V_2 , 0 ) ;
memset ( V_2 -> V_58 , 0 , V_55 ) ;
if ( V_2 -> V_46 == 0 )
V_2 -> V_46 = F_31 ( V_2 -> V_59 ) ;
}
void F_10 ( struct V_7 * V_20 )
{
struct V_4 * V_60 = V_20 -> V_5 ;
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned long V_26 ;
F_32 ( & V_60 -> V_61 ) ;
if ( V_9 -> V_62 > 0 )
F_32 ( & V_9 -> V_63 ) ;
if ( F_23 ( F_33 ( V_60 ) &&
( V_60 -> V_64 || V_60 -> V_65 ) ) ) {
F_11 ( V_60 -> V_66 , V_26 ) ;
F_34 ( V_60 ) ;
F_14 ( V_60 -> V_66 , V_26 ) ;
}
F_32 ( & V_20 -> V_67 ) ;
}
static void F_35 ( struct V_21 * V_22 )
{
if ( V_22 -> V_29 )
F_36 ( V_22 ) ;
else
F_37 ( V_22 ) ;
}
static void F_38 ( struct V_7 * V_68 )
{
struct V_4 * V_60 = V_68 -> V_5 ;
struct V_7 * V_20 , * V_69 ;
struct V_8 * V_9 = V_8 ( V_68 ) ;
unsigned long V_26 ;
F_11 ( V_60 -> V_66 , V_26 ) ;
V_9 -> V_70 = NULL ;
F_14 ( V_60 -> V_66 , V_26 ) ;
F_35 ( V_68 -> V_21 ) ;
F_11 ( V_60 -> V_66 , V_26 ) ;
if ( V_9 -> V_70 )
goto V_45;
F_39 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_20 == V_68 )
continue;
if ( F_40 ( V_20 ) )
continue;
F_14 ( V_60 -> V_66 , V_26 ) ;
F_35 ( V_20 -> V_21 ) ;
F_11 ( V_60 -> V_66 , V_26 ) ;
F_41 ( V_20 ) ;
}
V_45:
F_14 ( V_60 -> V_66 , V_26 ) ;
}
static inline bool F_42 ( struct V_7 * V_20 )
{
if ( F_43 ( & V_20 -> V_67 ) >= V_20 -> V_71 )
return true ;
if ( F_43 ( & V_20 -> V_15 ) > 0 )
return true ;
return false ;
}
static inline bool F_44 ( struct V_8 * V_9 )
{
if ( V_9 -> V_62 > 0 ) {
if ( F_43 ( & V_9 -> V_63 ) >= V_9 -> V_62 )
return true ;
if ( F_43 ( & V_9 -> V_18 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_45 ( struct V_4 * V_60 )
{
if ( V_60 -> V_62 > 0 &&
F_43 ( & V_60 -> V_61 ) >= V_60 -> V_62 )
return true ;
if ( F_43 ( & V_60 -> V_11 ) > 0 )
return true ;
if ( V_60 -> V_72 )
return true ;
return false ;
}
static void F_46 ( struct V_4 * V_60 )
{
F_47 ( V_73 ) ;
struct V_7 * V_20 ;
unsigned long V_26 ;
F_11 ( V_60 -> V_66 , V_26 ) ;
F_48 ( & V_60 -> V_73 , & V_73 ) ;
while ( ! F_49 ( & V_73 ) ) {
struct V_21 * V_74 ;
if ( F_45 ( V_60 ) )
break;
V_20 = F_50 ( V_73 . V_75 ,
struct V_7 , V_76 ) ;
F_51 ( & V_20 -> V_76 ) ;
if ( F_44 ( V_8 ( V_20 ) ) ) {
F_52 ( & V_20 -> V_76 ,
& V_60 -> V_73 ) ;
continue;
}
V_74 = V_20 -> V_21 ;
if ( ! F_53 ( V_74 ) )
continue;
F_14 ( V_60 -> V_66 , V_26 ) ;
F_35 ( V_74 ) ;
F_54 ( V_74 ) ;
F_11 ( V_60 -> V_66 , V_26 ) ;
}
F_55 ( & V_73 , & V_60 -> V_73 ) ;
F_14 ( V_60 -> V_66 , V_26 ) ;
}
static void F_56 ( struct V_21 * V_22 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
if ( V_8 ( V_20 ) -> V_78 )
F_38 ( V_20 ) ;
if ( ! F_49 ( & V_20 -> V_5 -> V_73 ) )
F_46 ( V_20 -> V_5 ) ;
if ( V_22 -> V_29 )
F_57 ( V_22 , false ) ;
else
F_37 ( V_22 ) ;
}
void F_58 ( struct V_79 * V_80 )
{
struct V_7 * V_20 ;
struct V_21 * V_22 ;
V_20 = F_59 ( V_80 , struct V_7 , V_31 ) ;
V_22 = V_20 -> V_21 ;
F_56 ( V_22 ) ;
}
static void F_60 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_23 * V_39 = V_2 -> V_23 ;
unsigned long V_26 ;
F_11 ( V_22 -> V_30 , V_26 ) ;
F_61 ( V_39 ) ;
V_39 -> V_81 = NULL ;
F_62 ( V_2 ) ;
F_12 ( V_22 , V_39 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
F_56 ( V_22 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
void F_63 ( struct V_4 * V_60 )
{
struct V_7 * V_20 ;
F_64 (sdev, shost)
F_56 ( V_20 -> V_21 ) ;
}
static inline unsigned int F_65 ( unsigned short V_82 )
{
unsigned int V_83 ;
F_66 ( V_82 > V_84 ) ;
if ( V_82 <= 8 )
V_83 = 0 ;
else
V_83 = F_67 ( V_82 ) - 3 ;
return V_83 ;
}
static void F_68 ( struct V_85 * V_86 , unsigned int V_82 )
{
struct V_87 * V_88 ;
V_88 = V_89 + F_65 ( V_82 ) ;
F_69 ( V_86 , V_88 -> V_90 ) ;
}
static struct V_85 * F_70 ( unsigned int V_82 , T_2 V_91 )
{
struct V_87 * V_88 ;
V_88 = V_89 + F_65 ( V_82 ) ;
return F_71 ( V_88 -> V_90 , V_91 ) ;
}
static void F_72 ( struct V_92 * V_93 , bool V_94 )
{
if ( V_94 && V_93 -> V_95 . V_82 <= V_84 )
return;
F_73 ( & V_93 -> V_95 , V_84 , V_94 , F_68 ) ;
}
static int F_74 ( struct V_92 * V_93 , int V_82 , bool V_94 )
{
struct V_85 * V_96 = NULL ;
int V_42 ;
F_66 ( ! V_82 ) ;
if ( V_94 ) {
if ( V_82 <= V_84 ) {
V_93 -> V_95 . V_82 = V_82 ;
F_75 ( V_93 -> V_95 . V_86 , V_93 -> V_95 . V_82 ) ;
return 0 ;
}
V_96 = V_93 -> V_95 . V_86 ;
}
V_42 = F_76 ( & V_93 -> V_95 , V_82 , V_84 ,
V_96 , V_97 , F_70 ) ;
if ( F_23 ( V_42 ) )
F_72 ( V_93 , V_94 ) ;
return V_42 ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_98 == V_99 ) {
struct V_100 * V_101 = F_78 ( V_2 ) ;
if ( V_101 -> V_102 )
V_101 -> V_102 ( V_2 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 . V_95 . V_82 )
F_72 ( & V_2 -> V_93 , true ) ;
if ( V_2 -> V_23 -> V_103 && V_2 -> V_23 -> V_103 -> V_81 )
F_72 ( V_2 -> V_23 -> V_103 -> V_81 , true ) ;
if ( F_80 ( V_2 ) )
F_72 ( V_2 -> V_104 , true ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned long V_26 ;
F_79 ( V_2 ) ;
F_77 ( V_2 ) ;
if ( V_60 -> V_105 ) {
F_66 ( F_49 ( & V_2 -> V_106 ) ) ;
F_11 ( & V_20 -> V_107 , V_26 ) ;
F_51 ( & V_2 -> V_106 ) ;
F_14 ( & V_20 -> V_107 , V_26 ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 . V_95 . V_82 )
F_72 ( & V_2 -> V_93 , false ) ;
memset ( & V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
if ( F_80 ( V_2 ) )
F_72 ( V_2 -> V_104 , false ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_92 * V_108 = V_2 -> V_23 -> V_103 -> V_81 ;
F_72 ( V_108 , false ) ;
F_84 ( V_109 , V_108 ) ;
V_2 -> V_23 -> V_103 -> V_81 = NULL ;
}
static bool F_85 ( struct V_23 * V_39 , int error ,
unsigned int V_110 , unsigned int V_111 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_20 -> V_21 ;
if ( F_86 ( V_39 , error , V_110 ) )
return true ;
if ( F_23 ( V_111 ) &&
F_86 ( V_39 -> V_103 , error , V_111 ) )
return true ;
if ( F_87 ( V_22 ) )
F_88 ( V_39 -> V_112 ) ;
if ( V_39 -> V_113 ) {
F_81 ( V_2 ) ;
F_89 ( V_39 , error ) ;
if ( V_8 ( V_20 ) -> V_78 ||
! F_49 ( & V_20 -> V_5 -> V_73 ) )
F_13 ( & V_20 -> V_31 ) ;
else
F_57 ( V_22 , true ) ;
} else {
unsigned long V_26 ;
if ( V_111 )
F_83 ( V_2 ) ;
F_11 ( V_22 -> V_30 , V_26 ) ;
F_90 ( V_39 , error ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
F_82 ( V_2 ) ;
F_62 ( V_2 ) ;
F_56 ( V_22 ) ;
}
F_6 ( & V_20 -> V_24 ) ;
return false ;
}
static int F_91 ( struct V_1 * V_2 , int V_28 )
{
int error = 0 ;
switch( F_92 ( V_28 ) ) {
case V_114 :
error = - V_115 ;
break;
case V_116 :
F_93 ( V_2 , V_117 ) ;
error = - V_118 ;
break;
case V_119 :
F_93 ( V_2 , V_117 ) ;
error = - V_120 ;
break;
case V_121 :
F_93 ( V_2 , V_117 ) ;
error = - V_122 ;
break;
case V_123 :
F_93 ( V_2 , V_117 ) ;
error = - V_124 ;
break;
default:
error = - V_125 ;
break;
}
return error ;
}
void F_94 ( struct V_1 * V_2 , unsigned int V_126 )
{
int V_28 = V_2 -> V_28 ;
struct V_21 * V_22 = V_2 -> V_6 -> V_21 ;
struct V_23 * V_39 = V_2 -> V_23 ;
int error = 0 ;
struct V_53 V_54 ;
bool V_127 = false ;
int V_128 = 0 , V_129 = 0 ;
enum { V_130 , V_131 , V_132 ,
V_133 } V_134 ;
unsigned long V_135 = ( V_2 -> V_136 + 1 ) * V_39 -> V_36 ;
if ( V_28 ) {
V_127 = F_95 ( V_2 , & V_54 ) ;
if ( V_127 )
V_128 = F_96 ( & V_54 ) ;
}
if ( V_39 -> V_98 == V_137 ) {
if ( V_28 ) {
if ( V_127 && V_39 -> V_35 ) {
int V_138 = 8 + V_2 -> V_58 [ 7 ] ;
if ( V_138 > V_55 )
V_138 = V_55 ;
memcpy ( V_39 -> V_35 , V_2 -> V_58 , V_138 ) ;
V_39 -> V_47 = V_138 ;
}
if ( ! V_128 )
error = F_91 ( V_2 , V_28 ) ;
}
V_39 -> V_52 = V_2 -> V_28 ;
V_39 -> V_51 = F_97 ( V_2 ) ;
if ( F_98 ( V_2 ) ) {
V_39 -> V_103 -> V_51 = F_99 ( V_2 ) -> V_38 ;
if ( F_85 ( V_39 , 0 , F_100 ( V_39 ) ,
F_100 ( V_39 -> V_103 ) ) )
F_101 () ;
return;
}
} else if ( F_100 ( V_39 ) == 0 && V_28 && ! V_128 ) {
error = F_91 ( V_2 , V_28 ) ;
}
F_66 ( F_102 ( V_39 ) ) ;
F_103 ( 1 , F_9 ( V_27 , V_2 ,
L_2 ,
F_104 ( V_39 ) , V_126 ) ) ;
if ( V_127 && ( V_54 . V_139 == V_140 ) ) {
if ( ( V_54 . V_141 == 0x0 ) && ( V_54 . V_142 == 0x1d ) )
;
else if ( ! ( V_39 -> V_48 & V_49 ) )
F_105 ( V_2 ) ;
V_28 = 0 ;
error = 0 ;
}
if ( ! F_85 ( V_39 , error , V_126 , 0 ) )
return;
if ( error && F_106 ( V_2 ) ) {
if ( F_85 ( V_39 , error , F_100 ( V_39 ) , 0 ) )
F_101 () ;
return;
}
if ( V_28 == 0 )
goto V_143;
error = F_91 ( V_2 , V_28 ) ;
if ( F_92 ( V_28 ) == V_144 ) {
V_134 = V_132 ;
} else if ( V_127 && ! V_128 ) {
switch ( V_54 . V_139 ) {
case V_145 :
if ( V_2 -> V_6 -> V_146 ) {
V_2 -> V_6 -> V_147 = 1 ;
V_134 = V_130 ;
} else {
V_134 = V_132 ;
}
break;
case V_148 :
if ( ( V_2 -> V_6 -> V_149 &&
V_54 . V_141 == 0x20 && V_54 . V_142 == 0x00 ) &&
( V_2 -> V_59 [ 0 ] == V_150 ||
V_2 -> V_59 [ 0 ] == V_151 ) ) {
V_2 -> V_6 -> V_149 = 0 ;
V_134 = V_131 ;
} else if ( V_54 . V_141 == 0x10 ) {
V_134 = V_130 ;
error = - V_152 ;
} else if ( V_54 . V_141 == 0x20 || V_54 . V_141 == 0x24 ) {
V_134 = V_130 ;
error = - V_118 ;
} else
V_134 = V_130 ;
break;
case V_153 :
V_134 = V_130 ;
if ( V_54 . V_141 == 0x10 )
error = - V_152 ;
break;
case V_154 :
if ( V_54 . V_141 == 0x04 ) {
switch ( V_54 . V_142 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_134 = V_133 ;
break;
default:
V_134 = V_130 ;
break;
}
} else
V_134 = V_130 ;
break;
case V_155 :
V_134 = V_130 ;
break;
default:
V_134 = V_130 ;
break;
}
} else
V_134 = V_130 ;
if ( V_134 != V_130 &&
F_107 ( V_2 -> V_156 + V_135 , V_157 ) )
V_134 = V_130 ;
switch ( V_134 ) {
case V_130 :
if ( ! ( V_39 -> V_48 & V_49 ) ) {
static F_108 ( V_158 ,
V_159 ,
V_160 ) ;
if ( F_23 ( V_161 ) )
V_129 = F_109 ( V_162 ,
V_163 ) ;
if ( ! V_129 && F_110 ( & V_158 ) ) {
F_111 ( V_2 , NULL , V_164 ) ;
if ( F_112 ( V_28 ) & V_165 )
F_105 ( V_2 ) ;
F_113 ( V_2 ) ;
}
}
if ( ! F_85 ( V_39 , error , F_114 ( V_39 ) , 0 ) )
return;
case V_131 :
V_143:
if ( V_22 -> V_29 ) {
V_2 -> V_23 -> V_48 &= ~ V_166 ;
F_81 ( V_2 ) ;
F_3 ( V_2 ) ;
} else {
F_82 ( V_2 ) ;
F_60 ( V_22 , V_2 ) ;
}
break;
case V_132 :
F_7 ( V_2 , V_14 , 0 ) ;
break;
case V_133 :
F_7 ( V_2 , V_13 , 0 ) ;
break;
}
}
static int F_115 ( struct V_23 * V_39 , struct V_92 * V_93 )
{
int V_167 ;
if ( F_23 ( F_74 ( V_93 , V_39 -> V_168 ,
V_39 -> V_113 != NULL ) ) )
return V_169 ;
V_167 = F_116 ( V_39 -> V_22 , V_39 , V_93 -> V_95 . V_86 ) ;
F_66 ( V_167 > V_93 -> V_95 . V_82 ) ;
V_93 -> V_95 . V_82 = V_167 ;
V_93 -> V_170 = F_100 ( V_39 ) ;
return V_171 ;
}
int F_117 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_23 * V_172 = V_2 -> V_23 ;
bool V_173 = ( V_172 -> V_113 != NULL ) ;
int error ;
F_66 ( ! V_172 -> V_168 ) ;
error = F_115 ( V_172 , & V_2 -> V_93 ) ;
if ( error )
goto V_174;
if ( F_102 ( V_172 ) ) {
if ( ! V_172 -> V_22 -> V_29 ) {
struct V_92 * V_108 =
F_118 ( V_109 , V_97 ) ;
if ( ! V_108 ) {
error = V_169 ;
goto V_174;
}
V_172 -> V_103 -> V_81 = V_108 ;
}
error = F_115 ( V_172 -> V_103 , V_172 -> V_103 -> V_81 ) ;
if ( error )
goto V_174;
}
if ( F_119 ( V_172 ) ) {
struct V_92 * V_104 = V_2 -> V_104 ;
int V_175 , V_167 ;
if ( V_104 == NULL ) {
F_120 ( 1 ) ;
error = V_176 ;
goto V_174;
}
V_175 = F_121 ( V_172 -> V_22 , V_172 -> V_177 ) ;
if ( F_74 ( V_104 , V_175 , V_173 ) ) {
error = V_169 ;
goto V_174;
}
V_167 = F_122 ( V_172 -> V_22 , V_172 -> V_177 ,
V_104 -> V_95 . V_86 ) ;
F_66 ( F_23 ( V_167 > V_175 ) ) ;
F_66 ( F_23 ( V_167 > F_123 ( V_172 -> V_22 ) ) ) ;
V_2 -> V_104 = V_104 ;
V_2 -> V_104 -> V_95 . V_82 = V_167 ;
}
return V_171 ;
V_174:
if ( V_173 ) {
F_79 ( V_2 ) ;
} else {
F_82 ( V_2 ) ;
V_2 -> V_23 -> V_81 = NULL ;
F_62 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
return error ;
}
static struct V_1 * F_124 ( struct V_7 * V_20 ,
struct V_23 * V_39 )
{
struct V_1 * V_2 ;
if ( ! V_39 -> V_81 ) {
if ( ! F_125 ( & V_20 -> V_24 ) )
return NULL ;
V_2 = F_126 ( V_20 , V_97 ) ;
if ( F_23 ( ! V_2 ) ) {
F_6 ( & V_20 -> V_24 ) ;
return NULL ;
}
V_39 -> V_81 = V_2 ;
} else {
V_2 = V_39 -> V_81 ;
}
V_2 -> V_178 = V_39 -> V_178 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_179 = V_180 ;
return V_2 ;
}
static int F_127 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( V_39 -> V_177 ) {
int V_42 = F_117 ( V_2 ) ;
if ( F_23 ( V_42 ) )
return V_42 ;
} else {
F_66 ( F_100 ( V_39 ) ) ;
memset ( & V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
}
V_2 -> V_46 = V_39 -> V_46 ;
V_2 -> V_181 = F_100 ( V_39 ) ;
V_2 -> V_136 = V_39 -> V_37 ;
return V_171 ;
}
static int F_128 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( F_23 ( V_20 -> V_182 && V_20 -> V_182 -> V_183
&& V_20 -> V_182 -> V_183 -> V_184 ) ) {
int V_42 = V_20 -> V_182 -> V_183 -> V_184 ( V_20 , V_39 ) ;
if ( V_42 != V_171 )
return V_42 ;
}
memset ( V_2 -> V_59 , 0 , V_185 ) ;
return F_78 ( V_2 ) -> F_129 ( V_2 ) ;
}
static int F_130 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( ! F_100 ( V_39 ) )
V_2 -> V_186 = V_187 ;
else if ( F_131 ( V_39 ) == V_188 )
V_2 -> V_186 = V_41 ;
else
V_2 -> V_186 = V_189 ;
switch ( V_39 -> V_98 ) {
case V_99 :
return F_128 ( V_20 , V_39 ) ;
case V_137 :
return F_127 ( V_20 , V_39 ) ;
default:
return V_176 ;
}
}
static int
F_132 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
int V_42 = V_171 ;
if ( F_23 ( V_20 -> V_190 != V_191 ) ) {
switch ( V_20 -> V_190 ) {
case V_192 :
case V_193 :
F_133 ( V_194 , V_20 ,
L_3 ) ;
V_42 = V_176 ;
break;
case V_195 :
F_133 ( V_194 , V_20 ,
L_4 ) ;
V_42 = V_176 ;
break;
case V_196 :
case V_197 :
V_42 = V_169 ;
break;
case V_198 :
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_169 ;
break;
default:
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_176 ;
break;
}
}
return V_42 ;
}
static int
F_134 ( struct V_21 * V_22 , struct V_23 * V_39 , int V_42 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
switch ( V_42 ) {
case V_176 :
V_39 -> V_52 = V_199 << 16 ;
if ( V_39 -> V_81 ) {
struct V_1 * V_2 = V_39 -> V_81 ;
F_82 ( V_2 ) ;
F_62 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
V_39 -> V_81 = NULL ;
}
break;
case V_169 :
if ( F_43 ( & V_20 -> V_67 ) == 0 )
F_135 ( V_22 , V_200 ) ;
break;
default:
V_39 -> V_48 |= V_166 ;
}
return V_42 ;
}
static int F_136 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_1 * V_2 ;
int V_42 ;
V_42 = F_132 ( V_20 , V_39 ) ;
if ( V_42 != V_171 )
goto V_45;
V_2 = F_124 ( V_20 , V_39 ) ;
if ( F_23 ( ! V_2 ) ) {
V_42 = V_169 ;
goto V_45;
}
V_42 = F_130 ( V_20 , V_39 ) ;
V_45:
return F_134 ( V_22 , V_39 , V_42 ) ;
}
static void F_137 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
F_77 ( V_39 -> V_81 ) ;
}
static inline int F_138 ( struct V_21 * V_22 ,
struct V_7 * V_20 )
{
unsigned int V_201 ;
V_201 = F_139 ( & V_20 -> V_67 ) - 1 ;
if ( F_43 ( & V_20 -> V_15 ) ) {
if ( V_201 )
goto V_202;
if ( F_140 ( & V_20 -> V_15 ) > 0 ) {
if ( ! V_22 -> V_29 )
F_135 ( V_22 , V_200 ) ;
goto V_202;
}
F_8 ( 3 , F_133 ( V_27 , V_20 ,
L_5 ) ) ;
}
if ( V_201 >= V_20 -> V_71 )
goto V_202;
return 1 ;
V_202:
F_32 ( & V_20 -> V_67 ) ;
return 0 ;
}
static inline int F_141 ( struct V_4 * V_60 ,
struct V_7 * V_20 )
{
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned int V_201 ;
if ( V_9 -> V_78 ) {
F_142 ( V_60 -> V_66 ) ;
if ( V_9 -> V_70 &&
V_9 -> V_70 != V_20 ) {
F_143 ( V_60 -> V_66 ) ;
return 0 ;
}
V_9 -> V_70 = V_20 ;
F_143 ( V_60 -> V_66 ) ;
}
if ( V_9 -> V_62 <= 0 )
return 1 ;
V_201 = F_139 ( & V_9 -> V_63 ) - 1 ;
if ( F_43 ( & V_9 -> V_18 ) > 0 ) {
if ( V_201 )
goto V_203;
if ( F_140 ( & V_9 -> V_18 ) > 0 )
goto V_202;
F_8 ( 3 , F_144 ( V_27 , V_9 ,
L_6 ) ) ;
}
if ( V_201 >= V_9 -> V_62 )
goto V_203;
return 1 ;
V_203:
F_142 ( V_60 -> V_66 ) ;
F_52 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_143 ( V_60 -> V_66 ) ;
V_202:
if ( V_9 -> V_62 > 0 )
F_32 ( & V_9 -> V_63 ) ;
return 0 ;
}
static inline int F_145 ( struct V_21 * V_22 ,
struct V_4 * V_60 ,
struct V_7 * V_20 )
{
unsigned int V_201 ;
if ( F_33 ( V_60 ) )
return 0 ;
V_201 = F_139 ( & V_60 -> V_61 ) - 1 ;
if ( F_43 ( & V_60 -> V_11 ) > 0 ) {
if ( V_201 )
goto V_203;
if ( F_140 ( & V_60 -> V_11 ) > 0 )
goto V_202;
F_8 ( 3 ,
F_146 ( V_27 , V_60 ,
L_7 ) ) ;
}
if ( V_60 -> V_62 > 0 && V_201 >= V_60 -> V_62 )
goto V_203;
if ( V_60 -> V_72 )
goto V_203;
if ( ! F_49 ( & V_20 -> V_76 ) ) {
F_142 ( V_60 -> V_66 ) ;
if ( ! F_49 ( & V_20 -> V_76 ) )
F_51 ( & V_20 -> V_76 ) ;
F_143 ( V_60 -> V_66 ) ;
}
return 1 ;
V_203:
F_142 ( V_60 -> V_66 ) ;
if ( F_49 ( & V_20 -> V_76 ) )
F_147 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_143 ( V_60 -> V_66 ) ;
V_202:
F_32 ( & V_60 -> V_61 ) ;
return 0 ;
}
static int F_148 ( struct V_21 * V_22 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
if ( F_149 ( V_22 ) )
return 0 ;
V_60 = V_20 -> V_5 ;
if ( F_33 ( V_60 ) || F_42 ( V_20 ) )
return 1 ;
return 0 ;
}
static void F_150 ( struct V_23 * V_39 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 ;
struct V_8 * V_9 ;
struct V_4 * V_60 ;
F_151 ( V_39 ) ;
F_9 ( V_27 , V_2 , L_8 ) ;
V_20 = V_2 -> V_6 ;
V_9 = V_8 ( V_20 ) ;
V_60 = V_20 -> V_5 ;
F_29 ( V_2 ) ;
V_2 -> V_28 = V_199 << 16 ;
F_152 ( & V_2 -> V_6 -> V_204 ) ;
F_152 ( & V_20 -> V_67 ) ;
F_152 ( & V_60 -> V_61 ) ;
if ( V_9 -> V_62 > 0 )
F_152 ( & V_9 -> V_63 ) ;
F_153 ( V_39 ) ;
}
static void F_154 ( struct V_23 * V_172 )
{
struct V_1 * V_2 = V_172 -> V_81 ;
unsigned long V_135 = ( V_2 -> V_136 + 1 ) * V_172 -> V_36 ;
int V_205 ;
F_155 ( & V_2 -> V_206 ) ;
F_152 ( & V_2 -> V_6 -> V_207 ) ;
if ( V_2 -> V_28 )
F_152 ( & V_2 -> V_6 -> V_208 ) ;
V_205 = F_156 ( V_2 ) ;
if ( V_205 != V_209 &&
F_107 ( V_2 -> V_156 + V_135 , V_157 ) ) {
F_133 ( V_194 , V_2 -> V_6 ,
L_9 ,
V_135 / V_210 ) ;
V_205 = V_209 ;
}
F_157 ( V_2 , V_205 ) ;
switch ( V_205 ) {
case V_209 :
F_158 ( V_2 ) ;
break;
case V_211 :
F_15 ( V_2 , V_14 ) ;
break;
case V_212 :
F_15 ( V_2 , V_13 ) ;
break;
default:
if ( ! F_159 ( V_2 , 0 ) )
F_158 ( V_2 ) ;
}
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_5 ;
int V_213 = 0 ;
F_152 ( & V_2 -> V_6 -> V_204 ) ;
if ( F_23 ( V_2 -> V_6 -> V_190 == V_195 ) ) {
V_2 -> V_28 = V_199 << 16 ;
goto V_214;
}
if ( F_23 ( F_161 ( V_2 -> V_6 ) ) ) {
F_8 ( 3 , F_9 ( V_27 , V_2 ,
L_10 ) ) ;
return V_13 ;
}
if ( V_2 -> V_6 -> V_215 )
V_2 -> V_59 [ 1 ] = ( V_2 -> V_59 [ 1 ] & 0x1f ) |
( V_2 -> V_6 -> V_216 << 5 & 0xe0 ) ;
F_162 ( V_2 ) ;
if ( V_2 -> V_46 > V_2 -> V_6 -> V_5 -> V_217 ) {
F_8 ( 3 , F_9 ( V_27 , V_2 ,
L_11
L_12 ,
V_2 -> V_46 , V_2 -> V_6 -> V_5 -> V_217 ) ) ;
V_2 -> V_28 = ( V_218 << 16 ) ;
goto V_214;
}
if ( F_23 ( V_5 -> V_219 == V_220 ) ) {
V_2 -> V_28 = ( V_199 << 16 ) ;
goto V_214;
}
F_163 ( V_2 ) ;
V_213 = V_5 -> V_221 -> V_222 ( V_5 , V_2 ) ;
if ( V_213 ) {
F_164 ( V_2 , V_213 ) ;
if ( V_213 != V_13 &&
V_213 != V_17 )
V_213 = V_10 ;
F_8 ( 3 , F_9 ( V_27 , V_2 ,
L_13 ) ) ;
}
return V_213 ;
V_214:
V_2 -> V_223 ( V_2 ) ;
return 0 ;
}
static void V_223 ( struct V_1 * V_2 )
{
F_165 ( V_2 ) ;
F_153 ( V_2 -> V_23 ) ;
}
static void F_166 ( struct V_21 * V_22 )
__releases( V_22 -> V_30 )
__acquires( V_22 -> V_30 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
struct V_1 * V_2 ;
struct V_23 * V_39 ;
V_60 = V_20 -> V_5 ;
for (; ; ) {
int V_213 ;
V_39 = F_167 ( V_22 ) ;
if ( ! V_39 )
break;
if ( F_23 ( ! F_168 ( V_20 ) ) ) {
F_133 ( V_194 , V_20 ,
L_3 ) ;
F_150 ( V_39 , V_22 ) ;
continue;
}
if ( ! F_138 ( V_22 , V_20 ) )
break;
if ( ! ( F_169 ( V_22 ) && ! F_170 ( V_22 , V_39 ) ) )
F_151 ( V_39 ) ;
F_143 ( V_22 -> V_30 ) ;
V_2 = V_39 -> V_81 ;
if ( F_23 ( V_2 == NULL ) ) {
F_171 ( V_224 L_14
L_15
L_16 ,
V_225 ) ;
F_172 ( V_39 , L_17 ) ;
F_101 () ;
}
if ( F_169 ( V_22 ) && ! ( V_39 -> V_48 & V_226 ) ) {
F_142 ( V_60 -> V_66 ) ;
if ( F_49 ( & V_20 -> V_76 ) )
F_147 ( & V_20 -> V_76 ,
& V_60 -> V_73 ) ;
F_143 ( V_60 -> V_66 ) ;
goto V_227;
}
if ( ! F_141 ( V_60 , V_20 ) )
goto V_227;
if ( ! F_145 ( V_22 , V_60 , V_20 ) )
goto V_228;
if ( V_20 -> V_229 )
V_2 -> V_26 |= V_230 ;
else
V_2 -> V_26 &= ~ V_230 ;
F_29 ( V_2 ) ;
V_2 -> V_223 = V_223 ;
V_213 = F_160 ( V_2 ) ;
if ( V_213 ) {
F_15 ( V_2 , V_213 ) ;
F_142 ( V_22 -> V_30 ) ;
goto V_231;
}
F_142 ( V_22 -> V_30 ) ;
}
return;
V_228:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_63 ) ;
V_227:
F_142 ( V_22 -> V_30 ) ;
F_12 ( V_22 , V_39 ) ;
F_32 ( & V_20 -> V_67 ) ;
V_231:
if ( ! F_43 ( & V_20 -> V_67 ) && ! F_161 ( V_20 ) )
F_135 ( V_22 , V_200 ) ;
}
static inline int F_173 ( int V_42 )
{
switch ( V_42 ) {
case V_171 :
return 0 ;
case V_169 :
return V_232 ;
default:
return V_233 ;
}
}
static int F_174 ( struct V_23 * V_39 )
{
struct V_1 * V_2 = F_175 ( V_39 ) ;
struct V_7 * V_20 = V_39 -> V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned char * V_234 = V_2 -> V_58 ;
struct V_85 * V_235 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_39 -> V_81 = V_2 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_6 = V_20 ;
V_2 -> V_58 = V_234 ;
V_2 -> V_178 = V_39 -> V_178 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_179 = V_180 ;
F_155 ( & V_2 -> V_106 ) ;
F_176 ( & V_2 -> V_236 , V_237 ) ;
V_2 -> V_156 = V_157 ;
if ( V_60 -> V_105 ) {
F_142 ( & V_20 -> V_107 ) ;
F_147 ( & V_2 -> V_106 , & V_20 -> V_238 ) ;
F_143 ( & V_20 -> V_107 ) ;
}
V_235 = ( void * ) V_2 + sizeof( struct V_1 ) + V_60 -> V_221 -> V_239 ;
V_2 -> V_93 . V_95 . V_86 = V_235 ;
if ( F_177 ( V_60 ) ) {
V_2 -> V_104 = ( void * ) V_235 +
F_178 (unsigned int,
shost->sg_tablesize, SCSI_MAX_SG_SEGMENTS) *
sizeof( struct V_85 ) ;
memset ( V_2 -> V_104 , 0 , sizeof( struct V_92 ) ) ;
V_2 -> V_104 -> V_95 . V_86 =
(struct V_85 * ) ( V_2 -> V_104 + 1 ) ;
}
if ( F_102 ( V_39 ) ) {
struct V_23 * V_103 = V_39 -> V_103 ;
struct V_92 * V_108 = F_175 ( V_103 ) ;
memset ( V_108 , 0 , sizeof( struct V_92 ) ) ;
V_108 -> V_95 . V_86 =
(struct V_85 * ) ( V_108 + 1 ) ;
V_103 -> V_81 = V_108 ;
}
F_179 ( V_39 ) ;
return F_130 ( V_20 , V_39 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_165 ( V_2 ) ;
F_181 ( V_2 -> V_23 ) ;
}
static int F_182 ( struct V_240 * V_241 ,
const struct V_242 * V_243 )
{
struct V_23 * V_39 = V_243 -> V_172 ;
struct V_21 * V_22 = V_39 -> V_22 ;
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
struct V_1 * V_2 = F_175 ( V_39 ) ;
int V_42 ;
int V_3 ;
V_42 = F_173 ( F_132 ( V_20 , V_39 ) ) ;
if ( V_42 )
goto V_45;
V_42 = V_232 ;
if ( ! F_125 ( & V_20 -> V_24 ) )
goto V_45;
if ( ! F_138 ( V_22 , V_20 ) )
goto V_244;
if ( ! F_141 ( V_60 , V_20 ) )
goto V_245;
if ( ! F_145 ( V_22 , V_60 , V_20 ) )
goto V_246;
if ( ! ( V_39 -> V_48 & V_166 ) ) {
V_42 = F_173 ( F_174 ( V_39 ) ) ;
if ( V_42 )
goto V_247;
V_39 -> V_48 |= V_166 ;
} else {
F_179 ( V_39 ) ;
}
if ( V_20 -> V_229 )
V_2 -> V_26 |= V_230 ;
else
V_2 -> V_26 &= ~ V_230 ;
F_29 ( V_2 ) ;
V_2 -> V_223 = F_180 ;
V_3 = F_160 ( V_2 ) ;
if ( V_3 ) {
F_1 ( V_2 , V_3 ) ;
V_42 = V_232 ;
goto V_247;
}
return V_248 ;
V_247:
F_32 ( & V_60 -> V_61 ) ;
V_246:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_63 ) ;
V_245:
F_32 ( & V_20 -> V_67 ) ;
V_244:
F_6 ( & V_20 -> V_24 ) ;
V_45:
switch ( V_42 ) {
case V_232 :
F_183 ( V_241 ) ;
if ( F_43 ( & V_20 -> V_67 ) == 0 &&
! F_161 ( V_20 ) )
F_184 ( V_241 , V_200 ) ;
break;
case V_233 :
if ( V_39 -> V_48 & V_166 )
F_81 ( V_2 ) ;
break;
default:
break;
}
return V_42 ;
}
static enum V_249 F_185 ( struct V_23 * V_39 ,
bool V_250 )
{
if ( V_250 )
return V_251 ;
return F_186 ( V_39 ) ;
}
static int F_187 ( void * V_252 , struct V_23 * V_172 ,
unsigned int V_253 , unsigned int V_254 ,
unsigned int V_255 )
{
struct V_1 * V_2 = F_175 ( V_172 ) ;
V_2 -> V_58 = F_188 ( V_55 , V_256 ,
V_255 ) ;
if ( ! V_2 -> V_58 )
return - V_257 ;
return 0 ;
}
static void F_189 ( void * V_252 , struct V_23 * V_172 ,
unsigned int V_253 , unsigned int V_254 )
{
struct V_1 * V_2 = F_175 ( V_172 ) ;
F_28 ( V_2 -> V_58 ) ;
}
static T_1 F_190 ( struct V_4 * V_60 )
{
struct V_6 * V_258 ;
T_1 V_259 = 0xffffffff ;
if ( V_60 -> V_260 )
return V_261 ;
if ( ! V_262 )
return V_263 ;
V_258 = F_191 ( V_60 ) ;
if ( V_258 && V_258 -> V_264 )
V_259 = ( T_1 ) F_192 ( V_258 ) << V_265 ;
return V_259 ;
}
static void F_193 ( struct V_4 * V_60 , struct V_21 * V_22 )
{
struct V_6 * V_266 = V_60 -> V_267 ;
F_194 ( V_22 , F_178 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_195 ( V_60 ) ) {
V_60 -> V_268 =
F_196 ( V_60 -> V_268 ,
( unsigned short ) V_269 ) ;
F_66 ( V_60 -> V_268 < V_60 -> V_270 ) ;
F_197 ( V_22 , V_60 -> V_268 ) ;
}
F_198 ( V_22 , V_60 -> V_271 ) ;
F_199 ( V_22 , F_190 ( V_60 ) ) ;
F_200 ( V_22 , V_60 -> V_272 ) ;
F_201 ( V_266 , V_60 -> V_272 ) ;
F_202 ( V_22 , F_203 ( V_266 ) ) ;
if ( ! V_60 -> V_273 )
V_22 -> V_274 . V_275 = 0 ;
F_204 ( V_22 , 0x03 ) ;
}
struct V_21 * F_205 ( struct V_4 * V_60 ,
T_3 * V_276 )
{
struct V_21 * V_22 ;
V_22 = F_206 ( V_276 , NULL ) ;
if ( ! V_22 )
return NULL ;
F_193 ( V_60 , V_22 ) ;
return V_22 ;
}
struct V_21 * F_207 ( struct V_7 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_205 ( V_20 -> V_5 , F_166 ) ;
if ( ! V_22 )
return NULL ;
F_208 ( V_22 , F_136 ) ;
F_209 ( V_22 , F_137 ) ;
F_210 ( V_22 , F_154 ) ;
F_211 ( V_22 , F_186 ) ;
F_212 ( V_22 , F_148 ) ;
return V_22 ;
}
struct V_21 * F_213 ( struct V_7 * V_20 )
{
V_20 -> V_21 = F_214 ( & V_20 -> V_5 -> V_277 ) ;
if ( F_18 ( V_20 -> V_21 ) )
return NULL ;
V_20 -> V_21 -> V_77 = V_20 ;
F_193 ( V_20 -> V_5 , V_20 -> V_21 ) ;
return V_20 -> V_21 ;
}
int F_215 ( struct V_4 * V_60 )
{
unsigned int V_239 , V_278 , V_279 ;
V_279 = V_60 -> V_270 ;
if ( V_279 > V_84 )
V_279 = V_84 ;
V_278 = V_279 * sizeof( struct V_85 ) ;
V_239 = sizeof( struct V_1 ) + V_60 -> V_221 -> V_239 + V_278 ;
if ( F_177 ( V_60 ) )
V_239 += sizeof( struct V_92 ) + V_278 ;
memset ( & V_60 -> V_277 , 0 , sizeof( V_60 -> V_277 ) ) ;
V_60 -> V_277 . V_280 = & V_281 ;
V_60 -> V_277 . V_282 = V_60 -> V_282 ? : 1 ;
V_60 -> V_277 . V_71 = V_60 -> V_62 ;
V_60 -> V_277 . V_239 = V_239 ;
V_60 -> V_277 . V_255 = V_283 ;
V_60 -> V_277 . V_26 = V_284 | V_285 ;
V_60 -> V_277 . V_26 |=
F_216 ( V_60 -> V_221 -> V_286 ) ;
V_60 -> V_277 . V_287 = V_60 ;
return F_217 ( & V_60 -> V_277 ) ;
}
void F_218 ( struct V_4 * V_60 )
{
F_219 ( & V_60 -> V_277 ) ;
}
void F_220 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 1 ;
}
void F_221 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 0 ;
F_63 ( V_60 ) ;
}
int T_4 F_222 ( void )
{
int V_288 ;
V_109 = F_223 ( L_18 ,
sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_109 ) {
F_171 ( V_194 L_19 ) ;
return - V_257 ;
}
for ( V_288 = 0 ; V_288 < V_289 ; V_288 ++ ) {
struct V_87 * V_88 = V_89 + V_288 ;
int V_290 = V_88 -> V_290 * sizeof( struct V_85 ) ;
V_88 -> V_291 = F_223 ( V_88 -> V_292 , V_290 , 0 ,
V_293 , NULL ) ;
if ( ! V_88 -> V_291 ) {
F_171 ( V_194 L_20 ,
V_88 -> V_292 ) ;
goto V_294;
}
V_88 -> V_90 = F_224 ( V_295 ,
V_88 -> V_291 ) ;
if ( ! V_88 -> V_90 ) {
F_171 ( V_194 L_21 ,
V_88 -> V_292 ) ;
goto V_294;
}
}
return 0 ;
V_294:
for ( V_288 = 0 ; V_288 < V_289 ; V_288 ++ ) {
struct V_87 * V_88 = V_89 + V_288 ;
if ( V_88 -> V_90 )
F_225 ( V_88 -> V_90 ) ;
if ( V_88 -> V_291 )
F_226 ( V_88 -> V_291 ) ;
}
F_226 ( V_109 ) ;
return - V_257 ;
}
void F_227 ( void )
{
int V_288 ;
F_226 ( V_109 ) ;
for ( V_288 = 0 ; V_288 < V_289 ; V_288 ++ ) {
struct V_87 * V_88 = V_89 + V_288 ;
F_225 ( V_88 -> V_90 ) ;
F_226 ( V_88 -> V_291 ) ;
}
}
int
F_228 ( struct V_7 * V_20 , int V_296 , int V_297 , int V_298 ,
unsigned char * V_33 , int V_138 , int V_36 , int V_37 ,
struct V_299 * V_252 , struct V_53 * V_54 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_300 ;
int V_42 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_296 ? 0x10 : 0 ) | ( V_297 ? 0x01 : 0 ) ;
if ( V_20 -> V_301 ) {
if ( V_138 > 65535 )
return - V_302 ;
V_300 = F_229 ( 8 + V_138 , V_256 ) ;
if ( ! V_300 )
return - V_257 ;
memcpy ( V_300 + 8 , V_33 , V_138 ) ;
V_138 += 8 ;
V_300 [ 0 ] = 0 ;
V_300 [ 1 ] = 0 ;
V_300 [ 2 ] = V_252 -> V_303 ;
V_300 [ 3 ] = V_252 -> V_304 ;
V_300 [ 4 ] = V_252 -> V_305 ? 0x01 : 0 ;
V_300 [ 5 ] = 0 ;
V_300 [ 6 ] = V_252 -> V_306 >> 8 ;
V_300 [ 7 ] = V_252 -> V_306 ;
V_2 [ 0 ] = V_307 ;
V_2 [ 7 ] = V_138 >> 8 ;
V_2 [ 8 ] = V_138 ;
} else {
if ( V_138 > 255 || V_252 -> V_306 > 255 ||
V_252 -> V_305 )
return - V_302 ;
V_300 = F_229 ( 4 + V_138 , V_256 ) ;
if ( ! V_300 )
return - V_257 ;
memcpy ( V_300 + 4 , V_33 , V_138 ) ;
V_138 += 4 ;
V_300 [ 0 ] = 0 ;
V_300 [ 1 ] = V_252 -> V_303 ;
V_300 [ 2 ] = V_252 -> V_304 ;
V_300 [ 3 ] = V_252 -> V_306 ;
V_2 [ 0 ] = V_308 ;
V_2 [ 4 ] = V_138 ;
}
V_42 = F_230 ( V_20 , V_2 , V_41 , V_300 , V_138 ,
V_54 , V_36 , V_37 , NULL ) ;
F_28 ( V_300 ) ;
return V_42 ;
}
int
F_231 ( struct V_7 * V_20 , int V_309 , int V_298 ,
unsigned char * V_33 , int V_138 , int V_36 , int V_37 ,
struct V_299 * V_252 , struct V_53 * V_54 )
{
unsigned char V_2 [ 12 ] ;
int V_301 ;
int V_310 ;
int V_28 ;
struct V_53 V_311 ;
memset ( V_252 , 0 , sizeof( * V_252 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_309 & 0x18 ;
V_2 [ 2 ] = V_298 ;
if ( ! V_54 )
V_54 = & V_311 ;
V_312:
V_301 = V_20 -> V_301 ;
if ( V_301 ) {
if ( V_138 < 8 )
V_138 = 8 ;
V_2 [ 0 ] = V_313 ;
V_2 [ 8 ] = V_138 ;
V_310 = 8 ;
} else {
if ( V_138 < 4 )
V_138 = 4 ;
V_2 [ 0 ] = V_314 ;
V_2 [ 4 ] = V_138 ;
V_310 = 4 ;
}
memset ( V_33 , 0 , V_138 ) ;
V_28 = F_230 ( V_20 , V_2 , V_189 , V_33 , V_138 ,
V_54 , V_36 , V_37 , NULL ) ;
if ( V_301 && ! F_232 ( V_28 ) &&
( F_112 ( V_28 ) & V_165 ) ) {
if ( F_233 ( V_54 ) ) {
if ( ( V_54 -> V_139 == V_148 ) &&
( V_54 -> V_141 == 0x20 ) && ( V_54 -> V_142 == 0 ) ) {
V_20 -> V_301 = 0 ;
goto V_312;
}
}
}
if( F_232 ( V_28 ) ) {
if ( F_23 ( V_33 [ 0 ] == 0x86 && V_33 [ 1 ] == 0x0b &&
( V_298 == 6 || V_298 == 8 ) ) ) {
V_310 = 0 ;
V_252 -> V_170 = 13 ;
V_252 -> V_303 = 0 ;
V_252 -> V_304 = 0 ;
V_252 -> V_305 = 0 ;
V_252 -> V_306 = 0 ;
} else if( V_301 ) {
V_252 -> V_170 = V_33 [ 0 ] * 256 + V_33 [ 1 ] + 2 ;
V_252 -> V_303 = V_33 [ 2 ] ;
V_252 -> V_304 = V_33 [ 3 ] ;
V_252 -> V_305 = V_33 [ 4 ] & 0x01 ;
V_252 -> V_306 = V_33 [ 6 ] * 256
+ V_33 [ 7 ] ;
} else {
V_252 -> V_170 = V_33 [ 0 ] + 1 ;
V_252 -> V_303 = V_33 [ 1 ] ;
V_252 -> V_304 = V_33 [ 2 ] ;
V_252 -> V_306 = V_33 [ 3 ] ;
}
V_252 -> V_310 = V_310 ;
}
return V_28 ;
}
int
F_234 ( struct V_7 * V_20 , int V_36 , int V_37 ,
struct V_53 * V_315 )
{
char V_2 [] = {
V_316 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_53 * V_54 ;
int V_28 ;
if ( ! V_315 )
V_54 = F_26 ( sizeof( * V_54 ) , V_256 ) ;
else
V_54 = V_315 ;
do {
V_28 = F_230 ( V_20 , V_2 , V_187 , NULL , 0 , V_54 ,
V_36 , V_37 , NULL ) ;
if ( V_20 -> V_146 && F_233 ( V_54 ) &&
V_54 -> V_139 == V_145 )
V_20 -> V_147 = 1 ;
} while ( F_233 ( V_54 ) &&
V_54 -> V_139 == V_145 && -- V_37 );
if ( ! V_315 )
F_28 ( V_54 ) ;
return V_28 ;
}
int
F_235 ( struct V_7 * V_20 , enum V_317 V_318 )
{
enum V_317 V_319 = V_20 -> V_190 ;
if ( V_318 == V_319 )
return 0 ;
switch ( V_318 ) {
case V_320 :
switch ( V_319 ) {
case V_197 :
break;
default:
goto V_321;
}
break;
case V_191 :
switch ( V_319 ) {
case V_320 :
case V_192 :
case V_193 :
case V_198 :
case V_196 :
break;
default:
goto V_321;
}
break;
case V_198 :
switch ( V_319 ) {
case V_191 :
case V_192 :
case V_193 :
break;
default:
goto V_321;
}
break;
case V_192 :
case V_193 :
switch ( V_319 ) {
case V_320 :
case V_191 :
case V_198 :
case V_196 :
break;
default:
goto V_321;
}
break;
case V_196 :
switch ( V_319 ) {
case V_191 :
case V_197 :
break;
default:
goto V_321;
}
break;
case V_197 :
switch ( V_319 ) {
case V_320 :
break;
default:
goto V_321;
}
break;
case V_322 :
switch ( V_319 ) {
case V_320 :
case V_191 :
case V_198 :
case V_192 :
case V_193 :
case V_196 :
break;
default:
goto V_321;
}
break;
case V_195 :
switch ( V_319 ) {
case V_320 :
case V_191 :
case V_192 :
case V_193 :
case V_322 :
case V_197 :
break;
default:
goto V_321;
}
break;
}
V_20 -> V_190 = V_318 ;
return 0 ;
V_321:
F_236 ( 1 ,
F_133 ( V_194 , V_20 ,
L_22 ,
F_237 ( V_319 ) ,
F_237 ( V_318 ) )
) ;
return - V_302 ;
}
static void F_238 ( struct V_7 * V_20 , struct V_323 * V_324 )
{
int V_325 = 0 ;
char * V_326 [ 3 ] ;
switch ( V_324 -> V_327 ) {
case V_328 :
V_326 [ V_325 ++ ] = L_23 ;
break;
case V_329 :
V_326 [ V_325 ++ ] = L_24 ;
break;
case V_330 :
V_326 [ V_325 ++ ] = L_25 ;
break;
case V_331 :
V_326 [ V_325 ++ ] = L_26 ;
break;
case V_332 :
V_326 [ V_325 ++ ] = L_27 ;
break;
case V_333 :
V_326 [ V_325 ++ ] = L_28 ;
break;
default:
break;
}
V_326 [ V_325 ++ ] = NULL ;
F_239 ( & V_20 -> V_24 . V_334 , V_335 , V_326 ) ;
}
void F_240 ( struct V_79 * V_80 )
{
struct V_7 * V_20 ;
enum V_336 V_327 ;
F_47 ( V_337 ) ;
V_20 = F_59 ( V_80 , struct V_7 , V_338 ) ;
for ( V_327 = V_339 ; V_327 <= V_340 ; V_327 ++ )
if ( F_241 ( V_327 , V_20 -> V_341 ) )
F_242 ( V_20 , V_327 , V_256 ) ;
while ( 1 ) {
struct V_323 * V_324 ;
struct V_342 * V_343 , * V_69 ;
unsigned long V_26 ;
F_11 ( & V_20 -> V_107 , V_26 ) ;
F_48 ( & V_20 -> V_337 , & V_337 ) ;
F_14 ( & V_20 -> V_107 , V_26 ) ;
if ( F_49 ( & V_337 ) )
break;
F_243 (this, tmp, &event_list) {
V_324 = F_50 ( V_343 , struct V_323 , V_344 ) ;
F_244 ( & V_324 -> V_344 ) ;
F_238 ( V_20 , V_324 ) ;
F_28 ( V_324 ) ;
}
}
}
void F_245 ( struct V_7 * V_20 , struct V_323 * V_324 )
{
unsigned long V_26 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_11 ( & V_20 -> V_107 , V_26 ) ;
F_147 ( & V_324 -> V_344 , & V_20 -> V_337 ) ;
F_246 ( & V_20 -> V_338 ) ;
F_14 ( & V_20 -> V_107 , V_26 ) ;
}
struct V_323 * F_247 ( enum V_336 V_327 ,
T_2 V_345 )
{
struct V_323 * V_324 = F_26 ( sizeof( struct V_323 ) , V_345 ) ;
if ( ! V_324 )
return NULL ;
V_324 -> V_327 = V_327 ;
F_155 ( & V_324 -> V_344 ) ;
switch ( V_327 ) {
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
default:
break;
}
return V_324 ;
}
void F_242 ( struct V_7 * V_20 ,
enum V_336 V_327 , T_2 V_345 )
{
struct V_323 * V_324 = F_247 ( V_327 , V_345 ) ;
if ( ! V_324 ) {
F_133 ( V_194 , V_20 , L_29 ,
V_327 ) ;
return;
}
F_245 ( V_20 , V_324 ) ;
}
int
F_248 ( struct V_7 * V_20 )
{
int V_346 = F_235 ( V_20 , V_198 ) ;
if ( V_346 )
return V_346 ;
F_56 ( V_20 -> V_21 ) ;
while ( F_43 ( & V_20 -> V_67 ) ) {
F_249 ( 200 ) ;
F_56 ( V_20 -> V_21 ) ;
}
return 0 ;
}
void F_250 ( struct V_7 * V_20 )
{
if ( V_20 -> V_190 != V_198 ||
F_235 ( V_20 , V_191 ) )
return;
F_56 ( V_20 -> V_21 ) ;
}
static void
F_251 ( struct V_7 * V_20 , void * V_252 )
{
F_248 ( V_20 ) ;
}
void
F_252 ( struct V_8 * V_9 )
{
F_253 ( V_9 , NULL , F_251 ) ;
}
static void
F_254 ( struct V_7 * V_20 , void * V_252 )
{
F_250 ( V_20 ) ;
}
void
F_255 ( struct V_8 * V_9 )
{
F_253 ( V_9 , NULL , F_254 ) ;
}
int
F_256 ( struct V_7 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
int V_346 = 0 ;
V_346 = F_235 ( V_20 , V_196 ) ;
if ( V_346 ) {
V_346 = F_235 ( V_20 , V_197 ) ;
if ( V_346 )
return V_346 ;
}
if ( V_22 -> V_29 ) {
F_257 ( V_22 ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_258 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
int
F_259 ( struct V_7 * V_20 ,
enum V_317 V_347 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
if ( ( V_20 -> V_190 == V_196 ) ||
( V_20 -> V_190 == V_193 ) )
V_20 -> V_190 = V_347 ;
else if ( V_20 -> V_190 == V_197 ) {
if ( V_347 == V_193 ||
V_347 == V_192 )
V_20 -> V_190 = V_347 ;
else
V_20 -> V_190 = V_320 ;
} else if ( V_20 -> V_190 != V_322 &&
V_20 -> V_190 != V_192 )
return - V_302 ;
if ( V_22 -> V_29 ) {
F_57 ( V_22 , false ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_260 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
static void
F_261 ( struct V_7 * V_20 , void * V_252 )
{
F_256 ( V_20 ) ;
}
static int
F_262 ( struct V_6 * V_266 , void * V_252 )
{
if ( F_263 ( V_266 ) )
F_253 ( F_264 ( V_266 ) , NULL ,
F_261 ) ;
return 0 ;
}
void
F_265 ( struct V_6 * V_266 )
{
if ( F_263 ( V_266 ) )
F_253 ( F_264 ( V_266 ) , NULL ,
F_261 ) ;
else
F_266 ( V_266 , NULL , F_262 ) ;
}
static void
F_267 ( struct V_7 * V_20 , void * V_252 )
{
F_259 ( V_20 , * (enum V_317 * ) V_252 ) ;
}
static int
F_268 ( struct V_6 * V_266 , void * V_252 )
{
if ( F_263 ( V_266 ) )
F_253 ( F_264 ( V_266 ) , V_252 ,
F_267 ) ;
return 0 ;
}
void
F_269 ( struct V_6 * V_266 , enum V_317 V_347 )
{
if ( F_263 ( V_266 ) )
F_253 ( F_264 ( V_266 ) , & V_347 ,
F_267 ) ;
else
F_266 ( V_266 , & V_347 , F_268 ) ;
}
void * F_270 ( struct V_85 * V_86 , int V_348 ,
T_5 * V_349 , T_5 * V_138 )
{
int V_288 ;
T_5 V_350 = 0 , V_351 = 0 ;
struct V_85 * V_235 ;
struct V_352 * V_352 ;
F_271 ( ! F_272 () ) ;
F_273 (sgl, sg, sg_count, i) {
V_351 = V_350 ;
V_350 += V_235 -> V_170 ;
if ( V_350 > * V_349 )
break;
}
if ( F_23 ( V_288 == V_348 ) ) {
F_171 ( V_194 L_30
L_31 ,
V_225 , V_350 , * V_349 , V_348 ) ;
F_271 ( 1 ) ;
return NULL ;
}
* V_349 = * V_349 - V_351 + V_235 -> V_349 ;
V_352 = F_274 ( F_275 ( V_235 ) , ( * V_349 >> V_265 ) ) ;
* V_349 &= ~ V_353 ;
V_350 = V_354 - * V_349 ;
if ( * V_138 > V_350 )
* V_138 = V_350 ;
return F_276 ( V_352 ) ;
}
void F_277 ( void * V_355 )
{
F_278 ( V_355 ) ;
}
void F_279 ( struct V_7 * V_20 )
{
F_152 ( & V_20 -> V_356 ) ;
}
void F_280 ( struct V_7 * V_20 )
{
if ( F_120 ( F_43 ( & V_20 -> V_356 ) <= 0 ) )
return;
F_32 ( & V_20 -> V_356 ) ;
}
