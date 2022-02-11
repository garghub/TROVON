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
void F_63 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_20 -> V_21 ;
F_62 ( V_2 ) ;
F_56 ( V_22 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
void F_64 ( struct V_4 * V_60 )
{
struct V_7 * V_20 ;
F_65 (sdev, shost)
F_56 ( V_20 -> V_21 ) ;
}
static inline unsigned int F_66 ( unsigned short V_82 )
{
unsigned int V_83 ;
F_67 ( V_82 > V_84 ) ;
if ( V_82 <= 8 )
V_83 = 0 ;
else
V_83 = F_68 ( V_82 ) - 3 ;
return V_83 ;
}
static void F_69 ( struct V_85 * V_86 , unsigned int V_82 )
{
struct V_87 * V_88 ;
V_88 = V_89 + F_66 ( V_82 ) ;
F_70 ( V_86 , V_88 -> V_90 ) ;
}
static struct V_85 * F_71 ( unsigned int V_82 , T_2 V_91 )
{
struct V_87 * V_88 ;
V_88 = V_89 + F_66 ( V_82 ) ;
return F_72 ( V_88 -> V_90 , V_91 ) ;
}
static void F_73 ( struct V_92 * V_93 , bool V_94 )
{
if ( V_94 && V_93 -> V_95 . V_82 <= V_84 )
return;
F_74 ( & V_93 -> V_95 , V_84 , V_94 , F_69 ) ;
}
static int F_75 ( struct V_92 * V_93 , int V_82 ,
T_2 V_91 , bool V_94 )
{
struct V_85 * V_96 = NULL ;
int V_42 ;
F_67 ( ! V_82 ) ;
if ( V_94 ) {
if ( V_82 <= V_84 ) {
V_93 -> V_95 . V_82 = V_82 ;
F_76 ( V_93 -> V_95 . V_86 , V_93 -> V_95 . V_82 ) ;
return 0 ;
}
V_96 = V_93 -> V_95 . V_86 ;
}
V_42 = F_77 ( & V_93 -> V_95 , V_82 , V_84 ,
V_96 , V_91 , F_71 ) ;
if ( F_23 ( V_42 ) )
F_73 ( V_93 , V_94 ) ;
return V_42 ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_97 == V_98 ) {
struct V_99 * V_100 = F_79 ( V_2 ) ;
if ( V_100 -> V_101 )
V_100 -> V_101 ( V_2 ) ;
}
}
static void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 . V_95 . V_82 )
F_73 ( & V_2 -> V_93 , true ) ;
if ( V_2 -> V_23 -> V_102 && V_2 -> V_23 -> V_102 -> V_81 )
F_73 ( V_2 -> V_23 -> V_102 -> V_81 , true ) ;
if ( F_81 ( V_2 ) )
F_73 ( V_2 -> V_103 , true ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned long V_26 ;
F_80 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_60 -> V_104 ) {
F_67 ( F_49 ( & V_2 -> V_105 ) ) ;
F_11 ( & V_20 -> V_106 , V_26 ) ;
F_51 ( & V_2 -> V_105 ) ;
F_14 ( & V_20 -> V_106 , V_26 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 . V_95 . V_82 )
F_73 ( & V_2 -> V_93 , false ) ;
memset ( & V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
if ( F_81 ( V_2 ) )
F_73 ( V_2 -> V_103 , false ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_92 * V_107 = V_2 -> V_23 -> V_102 -> V_81 ;
F_73 ( V_107 , false ) ;
F_85 ( V_108 , V_107 ) ;
V_2 -> V_23 -> V_102 -> V_81 = NULL ;
}
static bool F_86 ( struct V_23 * V_39 , int error ,
unsigned int V_109 , unsigned int V_110 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_20 -> V_21 ;
if ( F_87 ( V_39 , error , V_109 ) )
return true ;
if ( F_23 ( V_110 ) &&
F_87 ( V_39 -> V_102 , error , V_110 ) )
return true ;
if ( F_88 ( V_22 ) )
F_89 ( V_39 -> V_111 ) ;
if ( V_39 -> V_112 ) {
F_82 ( V_2 ) ;
F_90 ( V_39 , error ) ;
if ( V_8 ( V_20 ) -> V_78 ||
! F_49 ( & V_20 -> V_5 -> V_73 ) )
F_13 ( & V_20 -> V_31 ) ;
else
F_57 ( V_22 , true ) ;
F_6 ( & V_20 -> V_24 ) ;
} else {
unsigned long V_26 ;
if ( V_110 )
F_84 ( V_2 ) ;
F_11 ( V_22 -> V_30 , V_26 ) ;
F_91 ( V_39 , error ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
F_83 ( V_2 ) ;
F_63 ( V_2 ) ;
}
return false ;
}
static int F_92 ( struct V_1 * V_2 , int V_28 )
{
int error = 0 ;
switch( F_93 ( V_28 ) ) {
case V_113 :
error = - V_114 ;
break;
case V_115 :
F_94 ( V_2 , V_116 ) ;
error = - V_117 ;
break;
case V_118 :
F_94 ( V_2 , V_116 ) ;
error = - V_119 ;
break;
case V_120 :
F_94 ( V_2 , V_116 ) ;
error = - V_121 ;
break;
case V_122 :
F_94 ( V_2 , V_116 ) ;
error = - V_123 ;
break;
default:
error = - V_124 ;
break;
}
return error ;
}
void F_95 ( struct V_1 * V_2 , unsigned int V_125 )
{
int V_28 = V_2 -> V_28 ;
struct V_21 * V_22 = V_2 -> V_6 -> V_21 ;
struct V_23 * V_39 = V_2 -> V_23 ;
int error = 0 ;
struct V_53 V_54 ;
int V_126 = 0 ;
int V_127 = 0 ;
enum { V_128 , V_129 , V_130 ,
V_131 } V_132 ;
unsigned long V_133 = ( V_2 -> V_134 + 1 ) * V_39 -> V_36 ;
if ( V_28 ) {
V_126 = F_96 ( V_2 , & V_54 ) ;
if ( V_126 )
V_127 = F_97 ( & V_54 ) ;
}
if ( V_39 -> V_97 == V_135 ) {
if ( V_28 ) {
if ( V_126 && V_39 -> V_35 ) {
int V_136 = 8 + V_2 -> V_58 [ 7 ] ;
if ( V_136 > V_55 )
V_136 = V_55 ;
memcpy ( V_39 -> V_35 , V_2 -> V_58 , V_136 ) ;
V_39 -> V_47 = V_136 ;
}
if ( ! V_127 )
error = F_92 ( V_2 , V_28 ) ;
}
V_39 -> V_52 = V_2 -> V_28 ;
V_39 -> V_51 = F_98 ( V_2 ) ;
if ( F_99 ( V_2 ) ) {
V_39 -> V_102 -> V_51 = F_100 ( V_2 ) -> V_38 ;
if ( F_86 ( V_39 , 0 , F_101 ( V_39 ) ,
F_101 ( V_39 -> V_102 ) ) )
F_102 () ;
return;
}
} else if ( F_101 ( V_39 ) == 0 && V_28 && ! V_127 ) {
error = F_92 ( V_2 , V_28 ) ;
}
F_67 ( F_103 ( V_39 ) ) ;
F_104 ( 1 , F_9 ( V_27 , V_2 ,
L_2 ,
F_105 ( V_39 ) , V_125 ) ) ;
if ( V_126 && ( V_54 . V_137 == V_138 ) ) {
if ( ( V_54 . V_139 == 0x0 ) && ( V_54 . V_140 == 0x1d ) )
;
else if ( ! ( V_39 -> V_48 & V_49 ) )
F_106 ( L_3 , V_2 ) ;
V_28 = 0 ;
error = 0 ;
}
if ( ! F_86 ( V_39 , error , V_125 , 0 ) )
return;
if ( error && F_107 ( V_2 ) ) {
if ( F_86 ( V_39 , error , F_101 ( V_39 ) , 0 ) )
F_102 () ;
return;
}
if ( V_28 == 0 )
goto V_141;
error = F_92 ( V_2 , V_28 ) ;
if ( F_93 ( V_28 ) == V_142 ) {
V_132 = V_130 ;
} else if ( V_126 && ! V_127 ) {
switch ( V_54 . V_137 ) {
case V_143 :
if ( V_2 -> V_6 -> V_144 ) {
V_2 -> V_6 -> V_145 = 1 ;
V_132 = V_128 ;
} else {
V_132 = V_130 ;
}
break;
case V_146 :
if ( ( V_2 -> V_6 -> V_147 &&
V_54 . V_139 == 0x20 && V_54 . V_140 == 0x00 ) &&
( V_2 -> V_59 [ 0 ] == V_148 ||
V_2 -> V_59 [ 0 ] == V_149 ) ) {
V_2 -> V_6 -> V_147 = 0 ;
V_132 = V_129 ;
} else if ( V_54 . V_139 == 0x10 ) {
V_132 = V_128 ;
error = - V_150 ;
} else if ( V_54 . V_139 == 0x20 || V_54 . V_139 == 0x24 ) {
V_132 = V_128 ;
error = - V_117 ;
} else
V_132 = V_128 ;
break;
case V_151 :
V_132 = V_128 ;
if ( V_54 . V_139 == 0x10 )
error = - V_150 ;
break;
case V_152 :
if ( V_54 . V_139 == 0x04 ) {
switch ( V_54 . V_140 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_132 = V_131 ;
break;
default:
V_132 = V_128 ;
break;
}
} else
V_132 = V_128 ;
break;
case V_153 :
V_132 = V_128 ;
break;
default:
V_132 = V_128 ;
break;
}
} else
V_132 = V_128 ;
if ( V_132 != V_128 &&
F_108 ( V_2 -> V_154 + V_133 , V_155 ) )
V_132 = V_128 ;
switch ( V_132 ) {
case V_128 :
if ( ! ( V_39 -> V_48 & V_49 ) ) {
F_109 ( V_2 ) ;
if ( F_110 ( V_28 ) & V_156 )
F_106 ( L_3 , V_2 ) ;
F_111 ( V_2 ) ;
}
if ( ! F_86 ( V_39 , error , F_112 ( V_39 ) , 0 ) )
return;
case V_129 :
V_141:
if ( V_22 -> V_29 ) {
V_2 -> V_23 -> V_48 &= ~ V_157 ;
F_82 ( V_2 ) ;
F_3 ( V_2 ) ;
} else {
F_83 ( V_2 ) ;
F_60 ( V_22 , V_2 ) ;
}
break;
case V_130 :
F_7 ( V_2 , V_14 , 0 ) ;
break;
case V_131 :
F_7 ( V_2 , V_13 , 0 ) ;
break;
}
}
static int F_113 ( struct V_23 * V_39 , struct V_92 * V_93 ,
T_2 V_91 )
{
int V_158 ;
if ( F_23 ( F_75 ( V_93 , V_39 -> V_159 ,
V_91 , V_39 -> V_112 != NULL ) ) )
return V_160 ;
V_158 = F_114 ( V_39 -> V_22 , V_39 , V_93 -> V_95 . V_86 ) ;
F_67 ( V_158 > V_93 -> V_95 . V_82 ) ;
V_93 -> V_95 . V_82 = V_158 ;
V_93 -> V_161 = F_101 ( V_39 ) ;
return V_162 ;
}
int F_115 ( struct V_1 * V_2 , T_2 V_91 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_23 * V_163 = V_2 -> V_23 ;
bool V_164 = ( V_163 -> V_112 != NULL ) ;
int error ;
F_67 ( ! V_163 -> V_159 ) ;
error = F_113 ( V_163 , & V_2 -> V_93 , V_91 ) ;
if ( error )
goto V_165;
if ( F_103 ( V_163 ) ) {
if ( ! V_163 -> V_22 -> V_29 ) {
struct V_92 * V_107 =
F_116 ( V_108 , V_166 ) ;
if ( ! V_107 ) {
error = V_160 ;
goto V_165;
}
V_163 -> V_102 -> V_81 = V_107 ;
}
error = F_113 ( V_163 -> V_102 , V_163 -> V_102 -> V_81 ,
V_166 ) ;
if ( error )
goto V_165;
}
if ( F_117 ( V_163 ) ) {
struct V_92 * V_103 = V_2 -> V_103 ;
int V_167 , V_158 ;
F_67 ( V_103 == NULL ) ;
V_167 = F_118 ( V_163 -> V_22 , V_163 -> V_168 ) ;
if ( F_75 ( V_103 , V_167 , V_91 , V_164 ) ) {
error = V_160 ;
goto V_165;
}
V_158 = F_119 ( V_163 -> V_22 , V_163 -> V_168 ,
V_103 -> V_95 . V_86 ) ;
F_67 ( F_23 ( V_158 > V_167 ) ) ;
F_67 ( F_23 ( V_158 > F_120 ( V_163 -> V_22 ) ) ) ;
V_2 -> V_103 = V_103 ;
V_2 -> V_103 -> V_95 . V_82 = V_158 ;
}
return V_162 ;
V_165:
if ( V_164 ) {
F_80 ( V_2 ) ;
} else {
F_83 ( V_2 ) ;
V_2 -> V_23 -> V_81 = NULL ;
F_62 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
return error ;
}
static struct V_1 * F_121 ( struct V_7 * V_20 ,
struct V_23 * V_39 )
{
struct V_1 * V_2 ;
if ( ! V_39 -> V_81 ) {
if ( ! F_122 ( & V_20 -> V_24 ) )
return NULL ;
V_2 = F_123 ( V_20 , V_166 ) ;
if ( F_23 ( ! V_2 ) ) {
F_6 ( & V_20 -> V_24 ) ;
return NULL ;
}
V_39 -> V_81 = V_2 ;
} else {
V_2 = V_39 -> V_81 ;
}
V_2 -> V_169 = V_39 -> V_169 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_170 = V_171 ;
return V_2 ;
}
static int F_124 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( V_39 -> V_168 ) {
int V_42 = F_115 ( V_2 , V_166 ) ;
if ( F_23 ( V_42 ) )
return V_42 ;
} else {
F_67 ( F_101 ( V_39 ) ) ;
memset ( & V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
}
V_2 -> V_46 = V_39 -> V_46 ;
V_2 -> V_172 = F_101 ( V_39 ) ;
V_2 -> V_134 = V_39 -> V_37 ;
return V_162 ;
}
static int F_125 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( F_23 ( V_20 -> V_173 && V_20 -> V_173 -> V_174
&& V_20 -> V_173 -> V_174 -> V_175 ) ) {
int V_42 = V_20 -> V_173 -> V_174 -> V_175 ( V_20 , V_39 ) ;
if ( V_42 != V_162 )
return V_42 ;
}
memset ( V_2 -> V_59 , 0 , V_176 ) ;
return F_79 ( V_2 ) -> F_126 ( V_2 ) ;
}
static int F_127 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( ! F_101 ( V_39 ) )
V_2 -> V_177 = V_178 ;
else if ( F_128 ( V_39 ) == V_179 )
V_2 -> V_177 = V_41 ;
else
V_2 -> V_177 = V_180 ;
switch ( V_39 -> V_97 ) {
case V_98 :
return F_125 ( V_20 , V_39 ) ;
case V_135 :
return F_124 ( V_20 , V_39 ) ;
default:
return V_181 ;
}
}
static int
F_129 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
int V_42 = V_162 ;
if ( F_23 ( V_20 -> V_182 != V_183 ) ) {
switch ( V_20 -> V_182 ) {
case V_184 :
case V_185 :
F_130 ( V_186 , V_20 ,
L_4 ) ;
V_42 = V_181 ;
break;
case V_187 :
F_130 ( V_186 , V_20 ,
L_5 ) ;
V_42 = V_181 ;
break;
case V_188 :
case V_189 :
case V_190 :
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_160 ;
break;
default:
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_181 ;
break;
}
}
return V_42 ;
}
static int
F_131 ( struct V_21 * V_22 , struct V_23 * V_39 , int V_42 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
switch ( V_42 ) {
case V_181 :
V_39 -> V_52 = V_191 << 16 ;
if ( V_39 -> V_81 ) {
struct V_1 * V_2 = V_39 -> V_81 ;
F_83 ( V_2 ) ;
F_62 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
V_39 -> V_81 = NULL ;
}
break;
case V_160 :
if ( F_43 ( & V_20 -> V_67 ) == 0 )
F_132 ( V_22 , V_192 ) ;
break;
default:
V_39 -> V_48 |= V_157 ;
}
return V_42 ;
}
static int F_133 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_1 * V_2 ;
int V_42 ;
V_42 = F_129 ( V_20 , V_39 ) ;
if ( V_42 != V_162 )
goto V_45;
V_2 = F_121 ( V_20 , V_39 ) ;
if ( F_23 ( ! V_2 ) ) {
V_42 = V_160 ;
goto V_45;
}
V_42 = F_127 ( V_20 , V_39 ) ;
V_45:
return F_131 ( V_22 , V_39 , V_42 ) ;
}
static void F_134 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
F_78 ( V_39 -> V_81 ) ;
}
static inline int F_135 ( struct V_21 * V_22 ,
struct V_7 * V_20 )
{
unsigned int V_193 ;
V_193 = F_136 ( & V_20 -> V_67 ) - 1 ;
if ( F_43 ( & V_20 -> V_15 ) ) {
if ( V_193 )
goto V_194;
if ( F_137 ( & V_20 -> V_15 ) > 0 ) {
if ( ! V_22 -> V_29 )
F_132 ( V_22 , V_192 ) ;
goto V_194;
}
F_8 ( 3 , F_130 ( V_27 , V_20 ,
L_6 ) ) ;
}
if ( V_193 >= V_20 -> V_71 )
goto V_194;
return 1 ;
V_194:
F_32 ( & V_20 -> V_67 ) ;
return 0 ;
}
static inline int F_138 ( struct V_4 * V_60 ,
struct V_7 * V_20 )
{
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned int V_193 ;
if ( V_9 -> V_78 ) {
F_139 ( V_60 -> V_66 ) ;
if ( V_9 -> V_70 &&
V_9 -> V_70 != V_20 ) {
F_140 ( V_60 -> V_66 ) ;
return 0 ;
}
V_9 -> V_70 = V_20 ;
F_140 ( V_60 -> V_66 ) ;
}
if ( V_9 -> V_62 <= 0 )
return 1 ;
V_193 = F_136 ( & V_9 -> V_63 ) - 1 ;
if ( F_43 ( & V_9 -> V_18 ) > 0 ) {
if ( V_193 )
goto V_195;
if ( F_137 ( & V_9 -> V_18 ) > 0 )
goto V_194;
F_8 ( 3 , F_141 ( V_27 , V_9 ,
L_7 ) ) ;
}
if ( V_193 >= V_9 -> V_62 )
goto V_195;
return 1 ;
V_195:
F_139 ( V_60 -> V_66 ) ;
F_52 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_140 ( V_60 -> V_66 ) ;
V_194:
if ( V_9 -> V_62 > 0 )
F_32 ( & V_9 -> V_63 ) ;
return 0 ;
}
static inline int F_142 ( struct V_21 * V_22 ,
struct V_4 * V_60 ,
struct V_7 * V_20 )
{
unsigned int V_193 ;
if ( F_33 ( V_60 ) )
return 0 ;
V_193 = F_136 ( & V_60 -> V_61 ) - 1 ;
if ( F_43 ( & V_60 -> V_11 ) > 0 ) {
if ( V_193 )
goto V_195;
if ( F_137 ( & V_60 -> V_11 ) > 0 )
goto V_194;
F_8 ( 3 ,
F_143 ( V_27 , V_60 ,
L_8 ) ) ;
}
if ( V_60 -> V_62 > 0 && V_193 >= V_60 -> V_62 )
goto V_195;
if ( V_60 -> V_72 )
goto V_195;
if ( ! F_49 ( & V_20 -> V_76 ) ) {
F_139 ( V_60 -> V_66 ) ;
if ( ! F_49 ( & V_20 -> V_76 ) )
F_51 ( & V_20 -> V_76 ) ;
F_140 ( V_60 -> V_66 ) ;
}
return 1 ;
V_195:
F_139 ( V_60 -> V_66 ) ;
if ( F_49 ( & V_20 -> V_76 ) )
F_144 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_140 ( V_60 -> V_66 ) ;
V_194:
F_32 ( & V_60 -> V_61 ) ;
return 0 ;
}
static int F_145 ( struct V_21 * V_22 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
if ( F_146 ( V_22 ) )
return 0 ;
V_60 = V_20 -> V_5 ;
if ( F_33 ( V_60 ) || F_42 ( V_20 ) )
return 1 ;
return 0 ;
}
static void F_147 ( struct V_23 * V_39 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 ;
struct V_8 * V_9 ;
struct V_4 * V_60 ;
F_148 ( V_39 ) ;
F_9 ( V_27 , V_2 , L_9 ) ;
V_20 = V_2 -> V_6 ;
V_9 = V_8 ( V_20 ) ;
V_60 = V_20 -> V_5 ;
F_29 ( V_2 ) ;
V_2 -> V_28 = V_191 << 16 ;
F_149 ( & V_2 -> V_6 -> V_196 ) ;
F_149 ( & V_20 -> V_67 ) ;
F_149 ( & V_60 -> V_61 ) ;
if ( V_9 -> V_62 > 0 )
F_149 ( & V_9 -> V_63 ) ;
F_150 ( V_39 ) ;
}
static void F_151 ( struct V_23 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_81 ;
unsigned long V_133 = ( V_2 -> V_134 + 1 ) * V_163 -> V_36 ;
int V_197 ;
F_152 ( & V_2 -> V_198 ) ;
F_149 ( & V_2 -> V_6 -> V_199 ) ;
if ( V_2 -> V_28 )
F_149 ( & V_2 -> V_6 -> V_200 ) ;
V_197 = F_153 ( V_2 ) ;
if ( V_197 != V_201 &&
F_108 ( V_2 -> V_154 + V_133 , V_155 ) ) {
F_130 ( V_186 , V_2 -> V_6 ,
L_10 ,
V_133 / V_202 ) ;
V_197 = V_201 ;
}
F_154 ( V_2 , V_197 ) ;
switch ( V_197 ) {
case V_201 :
F_155 ( V_2 ) ;
break;
case V_203 :
F_15 ( V_2 , V_14 ) ;
break;
case V_204 :
F_15 ( V_2 , V_13 ) ;
break;
default:
if ( ! F_156 ( V_2 , 0 ) )
F_155 ( V_2 ) ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_150 ( V_2 -> V_23 ) ;
}
static void F_159 ( struct V_21 * V_22 )
__releases( V_22 -> V_30 )
__acquires( V_22 -> V_30 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
struct V_1 * V_2 ;
struct V_23 * V_39 ;
V_60 = V_20 -> V_5 ;
for (; ; ) {
int V_205 ;
V_39 = F_160 ( V_22 ) ;
if ( ! V_39 )
break;
if ( F_23 ( ! F_161 ( V_20 ) ) ) {
F_130 ( V_186 , V_20 ,
L_4 ) ;
F_147 ( V_39 , V_22 ) ;
continue;
}
if ( ! F_135 ( V_22 , V_20 ) )
break;
if ( ! ( F_162 ( V_22 ) && ! F_163 ( V_22 , V_39 ) ) )
F_148 ( V_39 ) ;
F_140 ( V_22 -> V_30 ) ;
V_2 = V_39 -> V_81 ;
if ( F_23 ( V_2 == NULL ) ) {
F_164 ( V_206 L_11
L_12
L_13 ,
V_207 ) ;
F_165 ( V_39 , L_14 ) ;
F_102 () ;
}
if ( F_162 ( V_22 ) && ! F_166 ( V_39 ) ) {
F_139 ( V_60 -> V_66 ) ;
if ( F_49 ( & V_20 -> V_76 ) )
F_144 ( & V_20 -> V_76 ,
& V_60 -> V_73 ) ;
F_140 ( V_60 -> V_66 ) ;
goto V_208;
}
if ( ! F_138 ( V_60 , V_20 ) )
goto V_208;
if ( ! F_142 ( V_22 , V_60 , V_20 ) )
goto V_209;
F_29 ( V_2 ) ;
V_2 -> F_157 = F_157 ;
V_205 = F_167 ( V_2 ) ;
if ( V_205 ) {
F_15 ( V_2 , V_205 ) ;
F_139 ( V_22 -> V_30 ) ;
goto V_210;
}
F_139 ( V_22 -> V_30 ) ;
}
return;
V_209:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_63 ) ;
V_208:
F_139 ( V_22 -> V_30 ) ;
F_12 ( V_22 , V_39 ) ;
F_32 ( & V_20 -> V_67 ) ;
V_210:
if ( ! F_43 ( & V_20 -> V_67 ) && ! F_168 ( V_20 ) )
F_132 ( V_22 , V_192 ) ;
}
static inline int F_169 ( int V_42 )
{
switch ( V_42 ) {
case V_162 :
return 0 ;
case V_160 :
return V_211 ;
default:
return V_212 ;
}
}
static int F_170 ( struct V_23 * V_39 )
{
struct V_1 * V_2 = F_171 ( V_39 ) ;
struct V_7 * V_20 = V_39 -> V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned char * V_213 = V_2 -> V_58 ;
struct V_85 * V_214 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_39 -> V_81 = V_2 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_6 = V_20 ;
V_2 -> V_58 = V_213 ;
V_2 -> V_169 = V_39 -> V_169 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_170 = V_171 ;
F_152 ( & V_2 -> V_105 ) ;
F_172 ( & V_2 -> V_215 , V_216 ) ;
V_2 -> V_154 = V_155 ;
if ( V_60 -> V_104 ) {
F_139 ( & V_20 -> V_106 ) ;
F_144 ( & V_2 -> V_105 , & V_20 -> V_217 ) ;
F_140 ( & V_20 -> V_106 ) ;
}
V_214 = ( void * ) V_2 + sizeof( struct V_1 ) + V_60 -> V_218 -> V_219 ;
V_2 -> V_93 . V_95 . V_86 = V_214 ;
if ( F_173 ( V_60 ) ) {
V_2 -> V_103 = ( void * ) V_214 +
V_60 -> V_220 * sizeof( struct V_85 ) ;
memset ( V_2 -> V_103 , 0 , sizeof( struct V_92 ) ) ;
V_2 -> V_103 -> V_95 . V_86 =
(struct V_85 * ) ( V_2 -> V_103 + 1 ) ;
}
if ( F_103 ( V_39 ) ) {
struct V_23 * V_102 = V_39 -> V_102 ;
struct V_92 * V_107 = F_171 ( V_102 ) ;
memset ( V_107 , 0 , sizeof( struct V_92 ) ) ;
V_107 -> V_95 . V_86 =
(struct V_85 * ) ( V_107 + 1 ) ;
V_102 -> V_81 = V_107 ;
}
F_174 ( V_39 ) ;
return F_127 ( V_20 , V_39 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_176 ( V_2 -> V_23 ) ;
}
static int F_177 ( struct V_221 * V_222 , struct V_23 * V_39 ,
bool V_223 )
{
struct V_21 * V_22 = V_39 -> V_22 ;
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
struct V_1 * V_2 = F_171 ( V_39 ) ;
int V_42 ;
int V_3 ;
V_42 = F_169 ( F_129 ( V_20 , V_39 ) ) ;
if ( V_42 )
goto V_45;
V_42 = V_211 ;
if ( ! F_122 ( & V_20 -> V_24 ) )
goto V_45;
if ( ! F_135 ( V_22 , V_20 ) )
goto V_224;
if ( ! F_138 ( V_60 , V_20 ) )
goto V_225;
if ( ! F_142 ( V_22 , V_60 , V_20 ) )
goto V_226;
if ( ! ( V_39 -> V_48 & V_157 ) ) {
V_42 = F_169 ( F_170 ( V_39 ) ) ;
if ( V_42 )
goto V_227;
V_39 -> V_48 |= V_157 ;
} else {
F_174 ( V_39 ) ;
}
if ( F_162 ( V_22 ) )
V_39 -> V_48 |= V_228 ;
else
V_39 -> V_48 &= ~ V_228 ;
F_29 ( V_2 ) ;
V_2 -> F_157 = F_175 ;
V_3 = F_167 ( V_2 ) ;
if ( V_3 ) {
F_1 ( V_2 , V_3 ) ;
V_42 = V_211 ;
goto V_227;
}
return V_229 ;
V_227:
F_32 ( & V_60 -> V_61 ) ;
V_226:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_63 ) ;
V_225:
F_32 ( & V_20 -> V_67 ) ;
V_224:
F_6 ( & V_20 -> V_24 ) ;
V_45:
switch ( V_42 ) {
case V_211 :
F_178 ( V_222 ) ;
if ( F_43 ( & V_20 -> V_67 ) == 0 &&
! F_168 ( V_20 ) )
F_179 ( V_222 , V_192 ) ;
break;
case V_212 :
if ( V_39 -> V_48 & V_157 )
F_82 ( V_2 ) ;
break;
default:
break;
}
return V_42 ;
}
static enum V_230 F_180 ( struct V_23 * V_39 ,
bool V_231 )
{
if ( V_231 )
return V_232 ;
return F_181 ( V_39 ) ;
}
static int F_182 ( void * V_233 , struct V_23 * V_163 ,
unsigned int V_234 , unsigned int V_235 ,
unsigned int V_236 )
{
struct V_1 * V_2 = F_171 ( V_163 ) ;
V_2 -> V_58 = F_183 ( V_55 , V_237 ,
V_236 ) ;
if ( ! V_2 -> V_58 )
return - V_238 ;
return 0 ;
}
static void F_184 ( void * V_233 , struct V_23 * V_163 ,
unsigned int V_234 , unsigned int V_235 )
{
struct V_1 * V_2 = F_171 ( V_163 ) ;
F_28 ( V_2 -> V_58 ) ;
}
static T_1 F_185 ( struct V_4 * V_60 )
{
struct V_6 * V_239 ;
T_1 V_240 = 0xffffffff ;
if ( V_60 -> V_241 )
return V_242 ;
if ( ! V_243 )
return V_244 ;
V_239 = F_186 ( V_60 ) ;
if ( V_239 && V_239 -> V_245 )
V_240 = ( T_1 ) F_187 ( V_239 ) << V_246 ;
return V_240 ;
}
static void F_188 ( struct V_4 * V_60 , struct V_21 * V_22 )
{
struct V_6 * V_247 = V_60 -> V_248 ;
F_189 ( V_22 , F_190 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_191 ( V_60 ) ) {
V_60 -> V_249 =
F_192 ( V_60 -> V_249 ,
( unsigned short ) V_250 ) ;
F_67 ( V_60 -> V_249 < V_60 -> V_220 ) ;
F_193 ( V_22 , V_60 -> V_249 ) ;
}
F_194 ( V_22 , V_60 -> V_251 ) ;
F_195 ( V_22 , F_185 ( V_60 ) ) ;
F_196 ( V_22 , V_60 -> V_252 ) ;
F_197 ( V_247 , V_60 -> V_252 ) ;
F_198 ( V_22 , F_199 ( V_247 ) ) ;
if ( ! V_60 -> V_253 )
V_22 -> V_254 . V_255 = 0 ;
F_200 ( V_22 , 0x03 ) ;
}
struct V_21 * F_201 ( struct V_4 * V_60 ,
T_3 * V_256 )
{
struct V_21 * V_22 ;
V_22 = F_202 ( V_256 , NULL ) ;
if ( ! V_22 )
return NULL ;
F_188 ( V_60 , V_22 ) ;
return V_22 ;
}
struct V_21 * F_203 ( struct V_7 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_201 ( V_20 -> V_5 , F_159 ) ;
if ( ! V_22 )
return NULL ;
F_204 ( V_22 , F_133 ) ;
F_205 ( V_22 , F_134 ) ;
F_206 ( V_22 , F_151 ) ;
F_207 ( V_22 , F_181 ) ;
F_208 ( V_22 , F_145 ) ;
return V_22 ;
}
struct V_21 * F_209 ( struct V_7 * V_20 )
{
V_20 -> V_21 = F_210 ( & V_20 -> V_5 -> V_257 ) ;
if ( F_18 ( V_20 -> V_21 ) )
return NULL ;
V_20 -> V_21 -> V_77 = V_20 ;
F_188 ( V_20 -> V_5 , V_20 -> V_21 ) ;
return V_20 -> V_21 ;
}
int F_211 ( struct V_4 * V_60 )
{
unsigned int V_219 , V_258 , V_259 ;
V_259 = V_60 -> V_220 ;
if ( V_259 > V_84 )
V_259 = V_84 ;
V_258 = V_259 * sizeof( struct V_85 ) ;
V_219 = sizeof( struct V_1 ) + V_60 -> V_218 -> V_219 + V_258 ;
if ( F_173 ( V_60 ) )
V_219 += sizeof( struct V_92 ) + V_258 ;
memset ( & V_60 -> V_257 , 0 , sizeof( V_60 -> V_257 ) ) ;
V_60 -> V_257 . V_260 = & V_261 ;
V_60 -> V_257 . V_262 = 1 ;
V_60 -> V_257 . V_71 = V_60 -> V_62 ;
V_60 -> V_257 . V_219 = V_219 ;
V_60 -> V_257 . V_236 = V_263 ;
V_60 -> V_257 . V_26 = V_264 | V_265 ;
V_60 -> V_257 . V_266 = V_60 ;
return F_212 ( & V_60 -> V_257 ) ;
}
void F_213 ( struct V_4 * V_60 )
{
F_214 ( & V_60 -> V_257 ) ;
}
void F_215 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 1 ;
}
void F_216 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 0 ;
F_64 ( V_60 ) ;
}
int T_4 F_217 ( void )
{
int V_267 ;
V_108 = F_218 ( L_15 ,
sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_108 ) {
F_164 ( V_186 L_16 ) ;
return - V_238 ;
}
for ( V_267 = 0 ; V_267 < V_268 ; V_267 ++ ) {
struct V_87 * V_88 = V_89 + V_267 ;
int V_269 = V_88 -> V_269 * sizeof( struct V_85 ) ;
V_88 -> V_270 = F_218 ( V_88 -> V_271 , V_269 , 0 ,
V_272 , NULL ) ;
if ( ! V_88 -> V_270 ) {
F_164 ( V_186 L_17 ,
V_88 -> V_271 ) ;
goto V_273;
}
V_88 -> V_90 = F_219 ( V_274 ,
V_88 -> V_270 ) ;
if ( ! V_88 -> V_90 ) {
F_164 ( V_186 L_18 ,
V_88 -> V_271 ) ;
goto V_273;
}
}
return 0 ;
V_273:
for ( V_267 = 0 ; V_267 < V_268 ; V_267 ++ ) {
struct V_87 * V_88 = V_89 + V_267 ;
if ( V_88 -> V_90 )
F_220 ( V_88 -> V_90 ) ;
if ( V_88 -> V_270 )
F_221 ( V_88 -> V_270 ) ;
}
F_221 ( V_108 ) ;
return - V_238 ;
}
void F_222 ( void )
{
int V_267 ;
F_221 ( V_108 ) ;
for ( V_267 = 0 ; V_267 < V_268 ; V_267 ++ ) {
struct V_87 * V_88 = V_89 + V_267 ;
F_220 ( V_88 -> V_90 ) ;
F_221 ( V_88 -> V_270 ) ;
}
}
int
F_223 ( struct V_7 * V_20 , int V_275 , int V_276 , int V_277 ,
unsigned char * V_33 , int V_136 , int V_36 , int V_37 ,
struct V_278 * V_233 , struct V_53 * V_54 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_279 ;
int V_42 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_275 ? 0x10 : 0 ) | ( V_276 ? 0x01 : 0 ) ;
if ( V_20 -> V_280 ) {
if ( V_136 > 65535 )
return - V_281 ;
V_279 = F_224 ( 8 + V_136 , V_237 ) ;
if ( ! V_279 )
return - V_238 ;
memcpy ( V_279 + 8 , V_33 , V_136 ) ;
V_136 += 8 ;
V_279 [ 0 ] = 0 ;
V_279 [ 1 ] = 0 ;
V_279 [ 2 ] = V_233 -> V_282 ;
V_279 [ 3 ] = V_233 -> V_283 ;
V_279 [ 4 ] = V_233 -> V_284 ? 0x01 : 0 ;
V_279 [ 5 ] = 0 ;
V_279 [ 6 ] = V_233 -> V_285 >> 8 ;
V_279 [ 7 ] = V_233 -> V_285 ;
V_2 [ 0 ] = V_286 ;
V_2 [ 7 ] = V_136 >> 8 ;
V_2 [ 8 ] = V_136 ;
} else {
if ( V_136 > 255 || V_233 -> V_285 > 255 ||
V_233 -> V_284 )
return - V_281 ;
V_279 = F_224 ( 4 + V_136 , V_237 ) ;
if ( ! V_279 )
return - V_238 ;
memcpy ( V_279 + 4 , V_33 , V_136 ) ;
V_136 += 4 ;
V_279 [ 0 ] = 0 ;
V_279 [ 1 ] = V_233 -> V_282 ;
V_279 [ 2 ] = V_233 -> V_283 ;
V_279 [ 3 ] = V_233 -> V_285 ;
V_2 [ 0 ] = V_287 ;
V_2 [ 4 ] = V_136 ;
}
V_42 = F_225 ( V_20 , V_2 , V_41 , V_279 , V_136 ,
V_54 , V_36 , V_37 , NULL ) ;
F_28 ( V_279 ) ;
return V_42 ;
}
int
F_226 ( struct V_7 * V_20 , int V_288 , int V_277 ,
unsigned char * V_33 , int V_136 , int V_36 , int V_37 ,
struct V_278 * V_233 , struct V_53 * V_54 )
{
unsigned char V_2 [ 12 ] ;
int V_280 ;
int V_289 ;
int V_28 ;
struct V_53 V_290 ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_288 & 0x18 ;
V_2 [ 2 ] = V_277 ;
if ( ! V_54 )
V_54 = & V_290 ;
V_291:
V_280 = V_20 -> V_280 ;
if ( V_280 ) {
if ( V_136 < 8 )
V_136 = 8 ;
V_2 [ 0 ] = V_292 ;
V_2 [ 8 ] = V_136 ;
V_289 = 8 ;
} else {
if ( V_136 < 4 )
V_136 = 4 ;
V_2 [ 0 ] = V_293 ;
V_2 [ 4 ] = V_136 ;
V_289 = 4 ;
}
memset ( V_33 , 0 , V_136 ) ;
V_28 = F_225 ( V_20 , V_2 , V_180 , V_33 , V_136 ,
V_54 , V_36 , V_37 , NULL ) ;
if ( V_280 && ! F_227 ( V_28 ) &&
( F_110 ( V_28 ) & V_156 ) ) {
if ( F_228 ( V_54 ) ) {
if ( ( V_54 -> V_137 == V_146 ) &&
( V_54 -> V_139 == 0x20 ) && ( V_54 -> V_140 == 0 ) ) {
V_20 -> V_280 = 0 ;
goto V_291;
}
}
}
if( F_227 ( V_28 ) ) {
if ( F_23 ( V_33 [ 0 ] == 0x86 && V_33 [ 1 ] == 0x0b &&
( V_277 == 6 || V_277 == 8 ) ) ) {
V_289 = 0 ;
V_233 -> V_161 = 13 ;
V_233 -> V_282 = 0 ;
V_233 -> V_283 = 0 ;
V_233 -> V_284 = 0 ;
V_233 -> V_285 = 0 ;
} else if( V_280 ) {
V_233 -> V_161 = V_33 [ 0 ] * 256 + V_33 [ 1 ] + 2 ;
V_233 -> V_282 = V_33 [ 2 ] ;
V_233 -> V_283 = V_33 [ 3 ] ;
V_233 -> V_284 = V_33 [ 4 ] & 0x01 ;
V_233 -> V_285 = V_33 [ 6 ] * 256
+ V_33 [ 7 ] ;
} else {
V_233 -> V_161 = V_33 [ 0 ] + 1 ;
V_233 -> V_282 = V_33 [ 1 ] ;
V_233 -> V_283 = V_33 [ 2 ] ;
V_233 -> V_285 = V_33 [ 3 ] ;
}
V_233 -> V_289 = V_289 ;
}
return V_28 ;
}
int
F_229 ( struct V_7 * V_20 , int V_36 , int V_37 ,
struct V_53 * V_294 )
{
char V_2 [] = {
V_295 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_53 * V_54 ;
int V_28 ;
if ( ! V_294 )
V_54 = F_26 ( sizeof( * V_54 ) , V_237 ) ;
else
V_54 = V_294 ;
do {
V_28 = F_225 ( V_20 , V_2 , V_178 , NULL , 0 , V_54 ,
V_36 , V_37 , NULL ) ;
if ( V_20 -> V_144 && F_228 ( V_54 ) &&
V_54 -> V_137 == V_143 )
V_20 -> V_145 = 1 ;
} while ( F_228 ( V_54 ) &&
V_54 -> V_137 == V_143 && -- V_37 );
if ( ! V_294 )
F_28 ( V_54 ) ;
return V_28 ;
}
int
F_230 ( struct V_7 * V_20 , enum V_296 V_297 )
{
enum V_296 V_298 = V_20 -> V_182 ;
if ( V_297 == V_298 )
return 0 ;
switch ( V_297 ) {
case V_299 :
switch ( V_298 ) {
case V_190 :
break;
default:
goto V_300;
}
break;
case V_183 :
switch ( V_298 ) {
case V_299 :
case V_184 :
case V_185 :
case V_188 :
case V_189 :
break;
default:
goto V_300;
}
break;
case V_188 :
switch ( V_298 ) {
case V_183 :
case V_184 :
case V_185 :
break;
default:
goto V_300;
}
break;
case V_184 :
case V_185 :
switch ( V_298 ) {
case V_299 :
case V_183 :
case V_188 :
case V_189 :
break;
default:
goto V_300;
}
break;
case V_189 :
switch ( V_298 ) {
case V_183 :
case V_190 :
break;
default:
goto V_300;
}
break;
case V_190 :
switch ( V_298 ) {
case V_299 :
break;
default:
goto V_300;
}
break;
case V_301 :
switch ( V_298 ) {
case V_299 :
case V_183 :
case V_188 :
case V_184 :
case V_185 :
case V_189 :
break;
default:
goto V_300;
}
break;
case V_187 :
switch ( V_298 ) {
case V_299 :
case V_183 :
case V_184 :
case V_185 :
case V_301 :
case V_190 :
break;
default:
goto V_300;
}
break;
}
V_20 -> V_182 = V_297 ;
return 0 ;
V_300:
F_231 ( 1 ,
F_130 ( V_186 , V_20 ,
L_19 ,
F_232 ( V_298 ) ,
F_232 ( V_297 ) )
) ;
return - V_281 ;
}
static void F_233 ( struct V_7 * V_20 , struct V_302 * V_303 )
{
int V_304 = 0 ;
char * V_305 [ 3 ] ;
switch ( V_303 -> V_306 ) {
case V_307 :
V_305 [ V_304 ++ ] = L_20 ;
break;
case V_308 :
V_305 [ V_304 ++ ] = L_21 ;
break;
case V_309 :
V_305 [ V_304 ++ ] = L_22 ;
break;
case V_310 :
V_305 [ V_304 ++ ] = L_23 ;
break;
case V_311 :
V_305 [ V_304 ++ ] = L_24 ;
break;
case V_312 :
V_305 [ V_304 ++ ] = L_25 ;
break;
default:
break;
}
V_305 [ V_304 ++ ] = NULL ;
F_234 ( & V_20 -> V_24 . V_313 , V_314 , V_305 ) ;
}
void F_235 ( struct V_79 * V_80 )
{
struct V_7 * V_20 ;
enum V_315 V_306 ;
F_47 ( V_316 ) ;
V_20 = F_59 ( V_80 , struct V_7 , V_317 ) ;
for ( V_306 = V_318 ; V_306 <= V_319 ; V_306 ++ )
if ( F_236 ( V_306 , V_20 -> V_320 ) )
F_237 ( V_20 , V_306 , V_237 ) ;
while ( 1 ) {
struct V_302 * V_303 ;
struct V_321 * V_322 , * V_69 ;
unsigned long V_26 ;
F_11 ( & V_20 -> V_106 , V_26 ) ;
F_48 ( & V_20 -> V_316 , & V_316 ) ;
F_14 ( & V_20 -> V_106 , V_26 ) ;
if ( F_49 ( & V_316 ) )
break;
F_238 (this, tmp, &event_list) {
V_303 = F_50 ( V_322 , struct V_302 , V_323 ) ;
F_239 ( & V_303 -> V_323 ) ;
F_233 ( V_20 , V_303 ) ;
F_28 ( V_303 ) ;
}
}
}
void F_240 ( struct V_7 * V_20 , struct V_302 * V_303 )
{
unsigned long V_26 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_11 ( & V_20 -> V_106 , V_26 ) ;
F_144 ( & V_303 -> V_323 , & V_20 -> V_316 ) ;
F_241 ( & V_20 -> V_317 ) ;
F_14 ( & V_20 -> V_106 , V_26 ) ;
}
struct V_302 * F_242 ( enum V_315 V_306 ,
T_2 V_324 )
{
struct V_302 * V_303 = F_26 ( sizeof( struct V_302 ) , V_324 ) ;
if ( ! V_303 )
return NULL ;
V_303 -> V_306 = V_306 ;
F_152 ( & V_303 -> V_323 ) ;
switch ( V_306 ) {
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
default:
break;
}
return V_303 ;
}
void F_237 ( struct V_7 * V_20 ,
enum V_315 V_306 , T_2 V_324 )
{
struct V_302 * V_303 = F_242 ( V_306 , V_324 ) ;
if ( ! V_303 ) {
F_130 ( V_186 , V_20 , L_26 ,
V_306 ) ;
return;
}
F_240 ( V_20 , V_303 ) ;
}
int
F_243 ( struct V_7 * V_20 )
{
int V_325 = F_230 ( V_20 , V_188 ) ;
if ( V_325 )
return V_325 ;
F_56 ( V_20 -> V_21 ) ;
while ( F_43 ( & V_20 -> V_67 ) ) {
F_244 ( 200 ) ;
F_56 ( V_20 -> V_21 ) ;
}
return 0 ;
}
void F_245 ( struct V_7 * V_20 )
{
if ( V_20 -> V_182 != V_188 ||
F_230 ( V_20 , V_183 ) )
return;
F_56 ( V_20 -> V_21 ) ;
}
static void
F_246 ( struct V_7 * V_20 , void * V_233 )
{
F_243 ( V_20 ) ;
}
void
F_247 ( struct V_8 * V_9 )
{
F_248 ( V_9 , NULL , F_246 ) ;
}
static void
F_249 ( struct V_7 * V_20 , void * V_233 )
{
F_245 ( V_20 ) ;
}
void
F_250 ( struct V_8 * V_9 )
{
F_248 ( V_9 , NULL , F_249 ) ;
}
int
F_251 ( struct V_7 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
int V_325 = 0 ;
V_325 = F_230 ( V_20 , V_189 ) ;
if ( V_325 ) {
V_325 = F_230 ( V_20 , V_190 ) ;
if ( V_325 )
return V_325 ;
}
if ( V_22 -> V_29 ) {
F_252 ( V_22 ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_253 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
int
F_254 ( struct V_7 * V_20 ,
enum V_296 V_326 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
if ( ( V_20 -> V_182 == V_189 ) ||
( V_20 -> V_182 == V_185 ) )
V_20 -> V_182 = V_326 ;
else if ( V_20 -> V_182 == V_190 ) {
if ( V_326 == V_185 ||
V_326 == V_184 )
V_20 -> V_182 = V_326 ;
else
V_20 -> V_182 = V_299 ;
} else if ( V_20 -> V_182 != V_301 &&
V_20 -> V_182 != V_184 )
return - V_281 ;
if ( V_22 -> V_29 ) {
F_57 ( V_22 , false ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_255 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
static void
F_256 ( struct V_7 * V_20 , void * V_233 )
{
F_251 ( V_20 ) ;
}
static int
F_257 ( struct V_6 * V_247 , void * V_233 )
{
if ( F_258 ( V_247 ) )
F_248 ( F_259 ( V_247 ) , NULL ,
F_256 ) ;
return 0 ;
}
void
F_260 ( struct V_6 * V_247 )
{
if ( F_258 ( V_247 ) )
F_248 ( F_259 ( V_247 ) , NULL ,
F_256 ) ;
else
F_261 ( V_247 , NULL , F_257 ) ;
}
static void
F_262 ( struct V_7 * V_20 , void * V_233 )
{
F_254 ( V_20 , * (enum V_296 * ) V_233 ) ;
}
static int
F_263 ( struct V_6 * V_247 , void * V_233 )
{
if ( F_258 ( V_247 ) )
F_248 ( F_259 ( V_247 ) , V_233 ,
F_262 ) ;
return 0 ;
}
void
F_264 ( struct V_6 * V_247 , enum V_296 V_326 )
{
if ( F_258 ( V_247 ) )
F_248 ( F_259 ( V_247 ) , & V_326 ,
F_262 ) ;
else
F_261 ( V_247 , & V_326 , F_263 ) ;
}
void * F_265 ( struct V_85 * V_86 , int V_327 ,
T_5 * V_328 , T_5 * V_136 )
{
int V_267 ;
T_5 V_329 = 0 , V_330 = 0 ;
struct V_85 * V_214 ;
struct V_331 * V_331 ;
F_266 ( ! F_267 () ) ;
F_268 (sgl, sg, sg_count, i) {
V_330 = V_329 ;
V_329 += V_214 -> V_161 ;
if ( V_329 > * V_328 )
break;
}
if ( F_23 ( V_267 == V_327 ) ) {
F_164 ( V_186 L_27
L_28 ,
V_207 , V_329 , * V_328 , V_327 ) ;
F_266 ( 1 ) ;
return NULL ;
}
* V_328 = * V_328 - V_330 + V_214 -> V_328 ;
V_331 = F_269 ( F_270 ( V_214 ) , ( * V_328 >> V_246 ) ) ;
* V_328 &= ~ V_332 ;
V_329 = V_333 - * V_328 ;
if ( * V_136 > V_329 )
* V_136 = V_329 ;
return F_271 ( V_331 ) ;
}
void F_272 ( void * V_334 )
{
F_273 ( V_334 ) ;
}
void F_274 ( struct V_7 * V_20 )
{
F_149 ( & V_20 -> V_335 ) ;
}
void F_275 ( struct V_7 * V_20 )
{
if ( F_276 ( F_43 ( & V_20 -> V_335 ) <= 0 ) )
return;
F_32 ( & V_20 -> V_335 ) ;
}
