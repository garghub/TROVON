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
if ( ! V_39 )
return V_42 ;
F_18 ( V_39 ) ;
if ( V_34 && F_19 ( V_20 -> V_21 , V_39 ,
V_33 , V_34 , V_44 ) )
goto V_45;
V_39 -> V_46 = F_20 ( V_2 [ 0 ] ) ;
memcpy ( V_39 -> V_2 , V_2 , V_39 -> V_46 ) ;
V_39 -> V_35 = V_35 ;
V_39 -> V_47 = 0 ;
V_39 -> V_37 = V_37 ;
V_39 -> V_36 = V_36 ;
V_39 -> V_48 |= V_26 | V_49 | V_50 ;
F_21 ( V_39 -> V_22 , NULL , V_39 , 1 ) ;
if ( F_22 ( V_39 -> V_51 > 0 && V_39 -> V_51 <= V_34 ) )
memset ( V_33 + ( V_34 - V_39 -> V_51 ) , 0 , V_39 -> V_51 ) ;
if ( V_38 )
* V_38 = V_39 -> V_51 ;
V_42 = V_39 -> V_52 ;
V_45:
F_23 ( V_39 ) ;
return V_42 ;
}
int F_24 ( struct V_7 * V_20 , const unsigned char * V_2 ,
int V_32 , void * V_33 , unsigned V_34 ,
struct V_53 * V_54 , int V_36 , int V_37 ,
int * V_38 , T_1 V_26 )
{
char * V_35 = NULL ;
int V_28 ;
if ( V_54 ) {
V_35 = F_25 ( V_55 , V_56 ) ;
if ( ! V_35 )
return V_43 << 24 ;
}
V_28 = F_16 ( V_20 , V_2 , V_32 , V_33 , V_34 ,
V_35 , V_36 , V_37 , V_26 , V_38 ) ;
if ( V_54 )
F_26 ( V_35 , V_55 , V_54 ) ;
F_27 ( V_35 ) ;
return V_28 ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_57 = 0 ;
F_29 ( V_2 , 0 ) ;
memset ( V_2 -> V_58 , 0 , V_55 ) ;
if ( V_2 -> V_46 == 0 )
V_2 -> V_46 = F_30 ( V_2 -> V_59 ) ;
}
void F_10 ( struct V_7 * V_20 )
{
struct V_4 * V_60 = V_20 -> V_5 ;
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned long V_26 ;
F_31 ( & V_60 -> V_61 ) ;
if ( V_9 -> V_62 > 0 )
F_31 ( & V_9 -> V_63 ) ;
if ( F_22 ( F_32 ( V_60 ) &&
( V_60 -> V_64 || V_60 -> V_65 ) ) ) {
F_11 ( V_60 -> V_66 , V_26 ) ;
F_33 ( V_60 ) ;
F_14 ( V_60 -> V_66 , V_26 ) ;
}
F_31 ( & V_20 -> V_67 ) ;
}
static void F_34 ( struct V_21 * V_22 )
{
if ( V_22 -> V_29 )
F_35 ( V_22 ) ;
else
F_36 ( V_22 ) ;
}
static void F_37 ( struct V_7 * V_68 )
{
struct V_4 * V_60 = V_68 -> V_5 ;
struct V_7 * V_20 , * V_69 ;
struct V_8 * V_9 = V_8 ( V_68 ) ;
unsigned long V_26 ;
F_11 ( V_60 -> V_66 , V_26 ) ;
V_9 -> V_70 = NULL ;
F_14 ( V_60 -> V_66 , V_26 ) ;
F_34 ( V_68 -> V_21 ) ;
F_11 ( V_60 -> V_66 , V_26 ) ;
if ( V_9 -> V_70 )
goto V_45;
F_38 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_20 == V_68 )
continue;
if ( F_39 ( V_20 ) )
continue;
F_14 ( V_60 -> V_66 , V_26 ) ;
F_34 ( V_20 -> V_21 ) ;
F_11 ( V_60 -> V_66 , V_26 ) ;
F_40 ( V_20 ) ;
}
V_45:
F_14 ( V_60 -> V_66 , V_26 ) ;
}
static inline bool F_41 ( struct V_7 * V_20 )
{
if ( F_42 ( & V_20 -> V_67 ) >= V_20 -> V_71 )
return true ;
if ( F_42 ( & V_20 -> V_15 ) > 0 )
return true ;
return false ;
}
static inline bool F_43 ( struct V_8 * V_9 )
{
if ( V_9 -> V_62 > 0 ) {
if ( F_42 ( & V_9 -> V_63 ) >= V_9 -> V_62 )
return true ;
if ( F_42 ( & V_9 -> V_18 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_44 ( struct V_4 * V_60 )
{
if ( V_60 -> V_62 > 0 &&
F_42 ( & V_60 -> V_61 ) >= V_60 -> V_62 )
return true ;
if ( F_42 ( & V_60 -> V_11 ) > 0 )
return true ;
if ( V_60 -> V_72 )
return true ;
return false ;
}
static void F_45 ( struct V_4 * V_60 )
{
F_46 ( V_73 ) ;
struct V_7 * V_20 ;
unsigned long V_26 ;
F_11 ( V_60 -> V_66 , V_26 ) ;
F_47 ( & V_60 -> V_73 , & V_73 ) ;
while ( ! F_48 ( & V_73 ) ) {
struct V_21 * V_74 ;
if ( F_44 ( V_60 ) )
break;
V_20 = F_49 ( V_73 . V_75 ,
struct V_7 , V_76 ) ;
F_50 ( & V_20 -> V_76 ) ;
if ( F_43 ( V_8 ( V_20 ) ) ) {
F_51 ( & V_20 -> V_76 ,
& V_60 -> V_73 ) ;
continue;
}
V_74 = V_20 -> V_21 ;
if ( ! F_52 ( V_74 ) )
continue;
F_14 ( V_60 -> V_66 , V_26 ) ;
F_34 ( V_74 ) ;
F_53 ( V_74 ) ;
F_11 ( V_60 -> V_66 , V_26 ) ;
}
F_54 ( & V_73 , & V_60 -> V_73 ) ;
F_14 ( V_60 -> V_66 , V_26 ) ;
}
static void F_55 ( struct V_21 * V_22 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
if ( V_8 ( V_20 ) -> V_78 )
F_37 ( V_20 ) ;
if ( ! F_48 ( & V_20 -> V_5 -> V_73 ) )
F_45 ( V_20 -> V_5 ) ;
if ( V_22 -> V_29 )
F_56 ( V_22 , false ) ;
else
F_36 ( V_22 ) ;
}
void F_57 ( struct V_79 * V_80 )
{
struct V_7 * V_20 ;
struct V_21 * V_22 ;
V_20 = F_58 ( V_80 , struct V_7 , V_31 ) ;
V_22 = V_20 -> V_21 ;
F_55 ( V_22 ) ;
}
static void F_59 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_23 * V_39 = V_2 -> V_23 ;
unsigned long V_26 ;
F_11 ( V_22 -> V_30 , V_26 ) ;
F_60 ( V_39 ) ;
V_39 -> V_81 = NULL ;
F_61 ( V_2 ) ;
F_12 ( V_22 , V_39 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
F_55 ( V_22 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_20 -> V_21 ;
F_61 ( V_2 ) ;
F_55 ( V_22 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
void F_63 ( struct V_4 * V_60 )
{
struct V_7 * V_20 ;
F_64 (sdev, shost)
F_55 ( V_20 -> V_21 ) ;
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
static int F_74 ( struct V_92 * V_93 , int V_82 ,
T_2 V_91 , bool V_94 )
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
V_96 , V_91 , F_70 ) ;
if ( F_22 ( V_42 ) )
F_72 ( V_93 , V_94 ) ;
return V_42 ;
}
static void F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_97 == V_98 ) {
struct V_99 * V_100 = F_78 ( V_2 ) ;
if ( V_100 -> V_101 )
V_100 -> V_101 ( V_2 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 . V_95 . V_82 )
F_72 ( & V_2 -> V_93 , true ) ;
if ( V_2 -> V_23 -> V_102 && V_2 -> V_23 -> V_102 -> V_81 )
F_72 ( V_2 -> V_23 -> V_102 -> V_81 , true ) ;
if ( F_80 ( V_2 ) )
F_72 ( V_2 -> V_103 , true ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
unsigned long V_26 ;
F_66 ( F_48 ( & V_2 -> V_104 ) ) ;
F_79 ( V_2 ) ;
F_77 ( V_2 ) ;
F_11 ( & V_20 -> V_105 , V_26 ) ;
F_50 ( & V_2 -> V_104 ) ;
F_14 ( & V_20 -> V_105 , V_26 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 . V_95 . V_82 )
F_72 ( & V_2 -> V_93 , false ) ;
memset ( & V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
if ( F_80 ( V_2 ) )
F_72 ( V_2 -> V_103 , false ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_92 * V_106 = V_2 -> V_23 -> V_102 -> V_81 ;
F_72 ( V_106 , false ) ;
F_84 ( V_107 , V_106 ) ;
V_2 -> V_23 -> V_102 -> V_81 = NULL ;
}
static bool F_85 ( struct V_23 * V_39 , int error ,
unsigned int V_108 , unsigned int V_109 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_20 -> V_21 ;
if ( F_86 ( V_39 , error , V_108 ) )
return true ;
if ( F_22 ( V_109 ) &&
F_86 ( V_39 -> V_102 , error , V_109 ) )
return true ;
if ( F_87 ( V_22 ) )
F_88 ( V_39 -> V_110 ) ;
if ( V_39 -> V_111 ) {
F_81 ( V_2 ) ;
F_89 ( V_39 , error ) ;
if ( V_8 ( V_20 ) -> V_78 ||
! F_48 ( & V_20 -> V_5 -> V_73 ) )
F_13 ( & V_20 -> V_31 ) ;
else
F_56 ( V_22 , true ) ;
F_6 ( & V_20 -> V_24 ) ;
} else {
unsigned long V_26 ;
if ( V_109 )
F_83 ( V_2 ) ;
F_11 ( V_22 -> V_30 , V_26 ) ;
F_90 ( V_39 , error ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
F_82 ( V_2 ) ;
F_62 ( V_2 ) ;
}
return false ;
}
static int F_91 ( struct V_1 * V_2 , int V_28 )
{
int error = 0 ;
switch( F_92 ( V_28 ) ) {
case V_112 :
error = - V_113 ;
break;
case V_114 :
F_93 ( V_2 , V_115 ) ;
error = - V_116 ;
break;
case V_117 :
F_93 ( V_2 , V_115 ) ;
error = - V_118 ;
break;
case V_119 :
F_93 ( V_2 , V_115 ) ;
error = - V_120 ;
break;
case V_121 :
F_93 ( V_2 , V_115 ) ;
error = - V_122 ;
break;
default:
error = - V_123 ;
break;
}
return error ;
}
void F_94 ( struct V_1 * V_2 , unsigned int V_124 )
{
int V_28 = V_2 -> V_28 ;
struct V_21 * V_22 = V_2 -> V_6 -> V_21 ;
struct V_23 * V_39 = V_2 -> V_23 ;
int error = 0 ;
struct V_53 V_54 ;
int V_125 = 0 ;
int V_126 = 0 ;
enum { V_127 , V_128 , V_129 ,
V_130 } V_131 ;
unsigned long V_132 = ( V_2 -> V_133 + 1 ) * V_39 -> V_36 ;
if ( V_28 ) {
V_125 = F_95 ( V_2 , & V_54 ) ;
if ( V_125 )
V_126 = F_96 ( & V_54 ) ;
}
if ( V_39 -> V_97 == V_134 ) {
if ( V_28 ) {
if ( V_125 && V_39 -> V_35 ) {
int V_135 = 8 + V_2 -> V_58 [ 7 ] ;
if ( V_135 > V_55 )
V_135 = V_55 ;
memcpy ( V_39 -> V_35 , V_2 -> V_58 , V_135 ) ;
V_39 -> V_47 = V_135 ;
}
if ( ! V_126 )
error = F_91 ( V_2 , V_28 ) ;
}
V_39 -> V_52 = V_2 -> V_28 ;
V_39 -> V_51 = F_97 ( V_2 ) ;
if ( F_98 ( V_2 ) ) {
V_39 -> V_102 -> V_51 = F_99 ( V_2 ) -> V_38 ;
if ( F_85 ( V_39 , 0 , F_100 ( V_39 ) ,
F_100 ( V_39 -> V_102 ) ) )
F_101 () ;
return;
}
} else if ( F_100 ( V_39 ) == 0 && V_28 && ! V_126 ) {
error = F_91 ( V_2 , V_28 ) ;
}
F_66 ( F_102 ( V_39 ) ) ;
F_103 ( 1 , F_9 ( V_27 , V_2 ,
L_2 ,
F_104 ( V_39 ) , V_124 ) ) ;
if ( V_125 && ( V_54 . V_136 == V_137 ) ) {
if ( ( V_54 . V_138 == 0x0 ) && ( V_54 . V_139 == 0x1d ) )
;
else if ( ! ( V_39 -> V_48 & V_49 ) )
F_105 ( L_3 , V_2 ) ;
V_28 = 0 ;
error = 0 ;
}
if ( ! F_85 ( V_39 , error , V_124 , 0 ) )
return;
if ( error && F_106 ( V_2 ) ) {
if ( F_85 ( V_39 , error , F_100 ( V_39 ) , 0 ) )
F_101 () ;
return;
}
if ( V_28 == 0 )
goto V_140;
error = F_91 ( V_2 , V_28 ) ;
if ( F_92 ( V_28 ) == V_141 ) {
V_131 = V_129 ;
} else if ( V_125 && ! V_126 ) {
switch ( V_54 . V_136 ) {
case V_142 :
if ( V_2 -> V_6 -> V_143 ) {
V_2 -> V_6 -> V_144 = 1 ;
V_131 = V_127 ;
} else {
V_131 = V_129 ;
}
break;
case V_145 :
if ( ( V_2 -> V_6 -> V_146 &&
V_54 . V_138 == 0x20 && V_54 . V_139 == 0x00 ) &&
( V_2 -> V_59 [ 0 ] == V_147 ||
V_2 -> V_59 [ 0 ] == V_148 ) ) {
V_2 -> V_6 -> V_146 = 0 ;
V_131 = V_128 ;
} else if ( V_54 . V_138 == 0x10 ) {
V_131 = V_127 ;
error = - V_149 ;
} else if ( V_54 . V_138 == 0x20 || V_54 . V_138 == 0x24 ) {
V_131 = V_127 ;
error = - V_116 ;
} else
V_131 = V_127 ;
break;
case V_150 :
V_131 = V_127 ;
if ( V_54 . V_138 == 0x10 )
error = - V_149 ;
break;
case V_151 :
if ( V_54 . V_138 == 0x04 ) {
switch ( V_54 . V_139 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_131 = V_130 ;
break;
default:
V_131 = V_127 ;
break;
}
} else
V_131 = V_127 ;
break;
case V_152 :
V_131 = V_127 ;
break;
default:
V_131 = V_127 ;
break;
}
} else
V_131 = V_127 ;
if ( V_131 != V_127 &&
F_107 ( V_2 -> V_153 + V_132 , V_154 ) )
V_131 = V_127 ;
switch ( V_131 ) {
case V_127 :
if ( ! ( V_39 -> V_48 & V_49 ) ) {
F_108 ( V_2 ) ;
if ( F_109 ( V_28 ) & V_155 )
F_105 ( L_3 , V_2 ) ;
F_110 ( V_2 ) ;
}
if ( ! F_85 ( V_39 , error , F_111 ( V_39 ) , 0 ) )
return;
case V_128 :
V_140:
if ( V_22 -> V_29 ) {
V_2 -> V_23 -> V_48 &= ~ V_156 ;
F_81 ( V_2 ) ;
F_3 ( V_2 ) ;
} else {
F_82 ( V_2 ) ;
F_59 ( V_22 , V_2 ) ;
}
break;
case V_129 :
F_7 ( V_2 , V_14 , 0 ) ;
break;
case V_130 :
F_7 ( V_2 , V_13 , 0 ) ;
break;
}
}
static int F_112 ( struct V_23 * V_39 , struct V_92 * V_93 ,
T_2 V_91 )
{
int V_157 ;
if ( F_22 ( F_74 ( V_93 , V_39 -> V_158 ,
V_91 , V_39 -> V_111 != NULL ) ) )
return V_159 ;
V_157 = F_113 ( V_39 -> V_22 , V_39 , V_93 -> V_95 . V_86 ) ;
F_66 ( V_157 > V_93 -> V_95 . V_82 ) ;
V_93 -> V_95 . V_82 = V_157 ;
V_93 -> V_160 = F_100 ( V_39 ) ;
return V_161 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_91 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_23 * V_162 = V_2 -> V_23 ;
bool V_163 = ( V_162 -> V_111 != NULL ) ;
int error ;
F_66 ( ! V_162 -> V_158 ) ;
error = F_112 ( V_162 , & V_2 -> V_93 , V_91 ) ;
if ( error )
goto V_164;
if ( F_102 ( V_162 ) ) {
if ( ! V_162 -> V_22 -> V_29 ) {
struct V_92 * V_106 =
F_115 ( V_107 , V_165 ) ;
if ( ! V_106 ) {
error = V_159 ;
goto V_164;
}
V_162 -> V_102 -> V_81 = V_106 ;
}
error = F_112 ( V_162 -> V_102 , V_162 -> V_102 -> V_81 ,
V_165 ) ;
if ( error )
goto V_164;
}
if ( F_116 ( V_162 ) ) {
struct V_92 * V_103 = V_2 -> V_103 ;
int V_166 , V_157 ;
F_66 ( V_103 == NULL ) ;
V_166 = F_117 ( V_162 -> V_22 , V_162 -> V_167 ) ;
if ( F_74 ( V_103 , V_166 , V_91 , V_163 ) ) {
error = V_159 ;
goto V_164;
}
V_157 = F_118 ( V_162 -> V_22 , V_162 -> V_167 ,
V_103 -> V_95 . V_86 ) ;
F_66 ( F_22 ( V_157 > V_166 ) ) ;
F_66 ( F_22 ( V_157 > F_119 ( V_162 -> V_22 ) ) ) ;
V_2 -> V_103 = V_103 ;
V_2 -> V_103 -> V_95 . V_82 = V_157 ;
}
return V_161 ;
V_164:
if ( V_163 ) {
F_79 ( V_2 ) ;
} else {
F_82 ( V_2 ) ;
V_2 -> V_23 -> V_81 = NULL ;
F_61 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
return error ;
}
static struct V_1 * F_120 ( struct V_7 * V_20 ,
struct V_23 * V_39 )
{
struct V_1 * V_2 ;
if ( ! V_39 -> V_81 ) {
if ( ! F_121 ( & V_20 -> V_24 ) )
return NULL ;
V_2 = F_122 ( V_20 , V_165 ) ;
if ( F_22 ( ! V_2 ) ) {
F_6 ( & V_20 -> V_24 ) ;
return NULL ;
}
V_39 -> V_81 = V_2 ;
} else {
V_2 = V_39 -> V_81 ;
}
V_2 -> V_168 = V_39 -> V_168 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_169 = V_170 ;
return V_2 ;
}
static int F_123 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( V_39 -> V_167 ) {
int V_42 = F_114 ( V_2 , V_165 ) ;
if ( F_22 ( V_42 ) )
return V_42 ;
} else {
F_66 ( F_100 ( V_39 ) ) ;
memset ( & V_2 -> V_93 , 0 , sizeof( V_2 -> V_93 ) ) ;
}
V_2 -> V_46 = V_39 -> V_46 ;
V_2 -> V_171 = F_100 ( V_39 ) ;
V_2 -> V_133 = V_39 -> V_37 ;
return V_161 ;
}
static int F_124 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( F_22 ( V_20 -> V_172 && V_20 -> V_172 -> V_173
&& V_20 -> V_172 -> V_173 -> V_174 ) ) {
int V_42 = V_20 -> V_172 -> V_173 -> V_174 ( V_20 , V_39 ) ;
if ( V_42 != V_161 )
return V_42 ;
}
memset ( V_2 -> V_59 , 0 , V_175 ) ;
return F_78 ( V_2 ) -> F_125 ( V_2 ) ;
}
static int F_126 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( ! F_100 ( V_39 ) )
V_2 -> V_176 = V_177 ;
else if ( F_127 ( V_39 ) == V_178 )
V_2 -> V_176 = V_41 ;
else
V_2 -> V_176 = V_179 ;
switch ( V_39 -> V_97 ) {
case V_98 :
return F_124 ( V_20 , V_39 ) ;
case V_134 :
return F_123 ( V_20 , V_39 ) ;
default:
return V_180 ;
}
}
static int
F_128 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
int V_42 = V_161 ;
if ( F_22 ( V_20 -> V_181 != V_182 ) ) {
switch ( V_20 -> V_181 ) {
case V_183 :
case V_184 :
F_129 ( V_185 , V_20 ,
L_4 ) ;
V_42 = V_180 ;
break;
case V_186 :
F_129 ( V_185 , V_20 ,
L_5 ) ;
V_42 = V_180 ;
break;
case V_187 :
case V_188 :
case V_189 :
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_159 ;
break;
default:
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_180 ;
break;
}
}
return V_42 ;
}
static int
F_130 ( struct V_21 * V_22 , struct V_23 * V_39 , int V_42 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
switch ( V_42 ) {
case V_180 :
V_39 -> V_52 = V_190 << 16 ;
if ( V_39 -> V_81 ) {
struct V_1 * V_2 = V_39 -> V_81 ;
F_82 ( V_2 ) ;
F_61 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
V_39 -> V_81 = NULL ;
}
break;
case V_159 :
if ( F_42 ( & V_20 -> V_67 ) == 0 )
F_131 ( V_22 , V_191 ) ;
break;
default:
V_39 -> V_48 |= V_156 ;
}
return V_42 ;
}
static int F_132 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_1 * V_2 ;
int V_42 ;
V_42 = F_128 ( V_20 , V_39 ) ;
if ( V_42 != V_161 )
goto V_45;
V_2 = F_120 ( V_20 , V_39 ) ;
if ( F_22 ( ! V_2 ) ) {
V_42 = V_159 ;
goto V_45;
}
V_42 = F_126 ( V_20 , V_39 ) ;
V_45:
return F_130 ( V_22 , V_39 , V_42 ) ;
}
static void F_133 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
F_77 ( V_39 -> V_81 ) ;
}
static inline int F_134 ( struct V_21 * V_22 ,
struct V_7 * V_20 )
{
unsigned int V_192 ;
V_192 = F_135 ( & V_20 -> V_67 ) - 1 ;
if ( F_42 ( & V_20 -> V_15 ) ) {
if ( V_192 )
goto V_193;
if ( F_136 ( & V_20 -> V_15 ) > 0 ) {
if ( ! V_22 -> V_29 )
F_131 ( V_22 , V_191 ) ;
goto V_193;
}
F_8 ( 3 , F_129 ( V_27 , V_20 ,
L_6 ) ) ;
}
if ( V_192 >= V_20 -> V_71 )
goto V_193;
return 1 ;
V_193:
F_31 ( & V_20 -> V_67 ) ;
return 0 ;
}
static inline int F_137 ( struct V_4 * V_60 ,
struct V_7 * V_20 )
{
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned int V_192 ;
if ( V_9 -> V_78 ) {
F_138 ( V_60 -> V_66 ) ;
if ( V_9 -> V_70 &&
V_9 -> V_70 != V_20 ) {
F_139 ( V_60 -> V_66 ) ;
return 0 ;
}
V_9 -> V_70 = V_20 ;
F_139 ( V_60 -> V_66 ) ;
}
if ( V_9 -> V_62 <= 0 )
return 1 ;
V_192 = F_135 ( & V_9 -> V_63 ) - 1 ;
if ( F_42 ( & V_9 -> V_18 ) > 0 ) {
if ( V_192 )
goto V_194;
if ( F_136 ( & V_9 -> V_18 ) > 0 )
goto V_193;
F_8 ( 3 , F_140 ( V_27 , V_9 ,
L_7 ) ) ;
}
if ( V_192 >= V_9 -> V_62 )
goto V_194;
return 1 ;
V_194:
F_138 ( V_60 -> V_66 ) ;
F_51 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_139 ( V_60 -> V_66 ) ;
V_193:
if ( V_9 -> V_62 > 0 )
F_31 ( & V_9 -> V_63 ) ;
return 0 ;
}
static inline int F_141 ( struct V_21 * V_22 ,
struct V_4 * V_60 ,
struct V_7 * V_20 )
{
unsigned int V_192 ;
if ( F_32 ( V_60 ) )
return 0 ;
V_192 = F_135 ( & V_60 -> V_61 ) - 1 ;
if ( F_42 ( & V_60 -> V_11 ) > 0 ) {
if ( V_192 )
goto V_194;
if ( F_136 ( & V_60 -> V_11 ) > 0 )
goto V_193;
F_8 ( 3 ,
F_142 ( V_27 , V_60 ,
L_8 ) ) ;
}
if ( V_60 -> V_62 > 0 && V_192 >= V_60 -> V_62 )
goto V_194;
if ( V_60 -> V_72 )
goto V_194;
if ( ! F_48 ( & V_20 -> V_76 ) ) {
F_138 ( V_60 -> V_66 ) ;
if ( ! F_48 ( & V_20 -> V_76 ) )
F_50 ( & V_20 -> V_76 ) ;
F_139 ( V_60 -> V_66 ) ;
}
return 1 ;
V_194:
F_138 ( V_60 -> V_66 ) ;
if ( F_48 ( & V_20 -> V_76 ) )
F_143 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_139 ( V_60 -> V_66 ) ;
V_193:
F_31 ( & V_60 -> V_61 ) ;
return 0 ;
}
static int F_144 ( struct V_21 * V_22 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
if ( F_145 ( V_22 ) )
return 0 ;
V_60 = V_20 -> V_5 ;
if ( F_32 ( V_60 ) || F_41 ( V_20 ) )
return 1 ;
return 0 ;
}
static void F_146 ( struct V_23 * V_39 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 ;
struct V_8 * V_9 ;
struct V_4 * V_60 ;
F_147 ( V_39 ) ;
F_9 ( V_27 , V_2 , L_9 ) ;
V_20 = V_2 -> V_6 ;
V_9 = V_8 ( V_20 ) ;
V_60 = V_20 -> V_5 ;
F_28 ( V_2 ) ;
V_2 -> V_28 = V_190 << 16 ;
F_148 ( & V_2 -> V_6 -> V_195 ) ;
F_148 ( & V_20 -> V_67 ) ;
F_148 ( & V_60 -> V_61 ) ;
if ( V_9 -> V_62 > 0 )
F_148 ( & V_9 -> V_63 ) ;
F_149 ( V_39 ) ;
}
static void F_150 ( struct V_23 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_81 ;
unsigned long V_132 = ( V_2 -> V_133 + 1 ) * V_162 -> V_36 ;
int V_196 ;
F_151 ( & V_2 -> V_197 ) ;
F_148 ( & V_2 -> V_6 -> V_198 ) ;
if ( V_2 -> V_28 )
F_148 ( & V_2 -> V_6 -> V_199 ) ;
V_196 = F_152 ( V_2 ) ;
if ( V_196 != V_200 &&
F_107 ( V_2 -> V_153 + V_132 , V_154 ) ) {
F_129 ( V_185 , V_2 -> V_6 ,
L_10 ,
V_132 / V_201 ) ;
V_196 = V_200 ;
}
F_153 ( V_2 , V_196 ) ;
switch ( V_196 ) {
case V_200 :
F_154 ( V_2 ) ;
break;
case V_202 :
F_15 ( V_2 , V_14 ) ;
break;
case V_203 :
F_15 ( V_2 , V_13 ) ;
break;
default:
if ( ! F_155 ( V_2 , 0 ) )
F_154 ( V_2 ) ;
}
}
static void F_156 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_149 ( V_2 -> V_23 ) ;
}
static void F_158 ( struct V_21 * V_22 )
__releases( V_22 -> V_30 )
__acquires( V_22 -> V_30 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
struct V_1 * V_2 ;
struct V_23 * V_39 ;
V_60 = V_20 -> V_5 ;
for (; ; ) {
int V_204 ;
V_39 = F_159 ( V_22 ) ;
if ( ! V_39 )
break;
if ( F_22 ( ! F_160 ( V_20 ) ) ) {
F_129 ( V_185 , V_20 ,
L_4 ) ;
F_146 ( V_39 , V_22 ) ;
continue;
}
if ( ! F_134 ( V_22 , V_20 ) )
break;
if ( ! ( F_161 ( V_22 ) && ! F_162 ( V_22 , V_39 ) ) )
F_147 ( V_39 ) ;
F_139 ( V_22 -> V_30 ) ;
V_2 = V_39 -> V_81 ;
if ( F_22 ( V_2 == NULL ) ) {
F_163 ( V_205 L_11
L_12
L_13 ,
V_206 ) ;
F_164 ( V_39 , L_14 ) ;
F_101 () ;
}
if ( F_161 ( V_22 ) && ! F_165 ( V_39 ) ) {
F_138 ( V_60 -> V_66 ) ;
if ( F_48 ( & V_20 -> V_76 ) )
F_143 ( & V_20 -> V_76 ,
& V_60 -> V_73 ) ;
F_139 ( V_60 -> V_66 ) ;
goto V_207;
}
if ( ! F_137 ( V_60 , V_20 ) )
goto V_207;
if ( ! F_141 ( V_22 , V_60 , V_20 ) )
goto V_208;
F_28 ( V_2 ) ;
V_2 -> F_156 = F_156 ;
V_204 = F_166 ( V_2 ) ;
if ( V_204 ) {
F_15 ( V_2 , V_204 ) ;
F_138 ( V_22 -> V_30 ) ;
goto V_209;
}
F_138 ( V_22 -> V_30 ) ;
}
return;
V_208:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_31 ( & V_8 ( V_20 ) -> V_63 ) ;
V_207:
F_138 ( V_22 -> V_30 ) ;
F_12 ( V_22 , V_39 ) ;
F_31 ( & V_20 -> V_67 ) ;
V_209:
if ( ! F_42 ( & V_20 -> V_67 ) && ! F_167 ( V_20 ) )
F_131 ( V_22 , V_191 ) ;
}
static inline int F_168 ( int V_42 )
{
switch ( V_42 ) {
case V_161 :
return 0 ;
case V_159 :
return V_210 ;
default:
return V_211 ;
}
}
static int F_169 ( struct V_23 * V_39 )
{
struct V_1 * V_2 = F_170 ( V_39 ) ;
struct V_7 * V_20 = V_39 -> V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned char * V_212 = V_2 -> V_58 ;
struct V_85 * V_213 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_39 -> V_81 = V_2 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_6 = V_20 ;
V_2 -> V_58 = V_212 ;
V_2 -> V_168 = V_39 -> V_168 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_169 = V_170 ;
F_151 ( & V_2 -> V_104 ) ;
F_171 ( & V_2 -> V_214 , V_215 ) ;
V_2 -> V_153 = V_154 ;
F_138 ( & V_20 -> V_105 ) ;
F_143 ( & V_2 -> V_104 , & V_20 -> V_216 ) ;
F_139 ( & V_20 -> V_105 ) ;
V_213 = ( void * ) V_2 + sizeof( struct V_1 ) + V_60 -> V_217 -> V_218 ;
V_2 -> V_93 . V_95 . V_86 = V_213 ;
if ( F_172 ( V_60 ) ) {
V_2 -> V_103 = ( void * ) V_213 +
V_60 -> V_219 * sizeof( struct V_85 ) ;
memset ( V_2 -> V_103 , 0 , sizeof( struct V_92 ) ) ;
V_2 -> V_103 -> V_95 . V_86 =
(struct V_85 * ) ( V_2 -> V_103 + 1 ) ;
}
if ( F_102 ( V_39 ) ) {
struct V_23 * V_102 = V_39 -> V_102 ;
struct V_92 * V_106 = F_170 ( V_102 ) ;
memset ( V_106 , 0 , sizeof( struct V_92 ) ) ;
V_106 -> V_95 . V_86 =
(struct V_85 * ) ( V_106 + 1 ) ;
V_102 -> V_81 = V_106 ;
}
return F_126 ( V_20 , V_39 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_174 ( V_2 -> V_23 ) ;
}
static int F_175 ( struct V_220 * V_221 , struct V_23 * V_39 )
{
struct V_21 * V_22 = V_39 -> V_22 ;
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
struct V_1 * V_2 = F_170 ( V_39 ) ;
int V_42 ;
int V_3 ;
V_42 = F_168 ( F_128 ( V_20 , V_39 ) ) ;
if ( V_42 )
goto V_45;
V_42 = V_210 ;
if ( ! F_121 ( & V_20 -> V_24 ) )
goto V_45;
if ( ! F_134 ( V_22 , V_20 ) )
goto V_222;
if ( ! F_137 ( V_60 , V_20 ) )
goto V_223;
if ( ! F_141 ( V_22 , V_60 , V_20 ) )
goto V_224;
if ( ! ( V_39 -> V_48 & V_156 ) ) {
V_42 = F_168 ( F_169 ( V_39 ) ) ;
if ( V_42 )
goto V_225;
V_39 -> V_48 |= V_156 ;
}
F_28 ( V_2 ) ;
V_2 -> F_156 = F_173 ;
V_3 = F_166 ( V_2 ) ;
if ( V_3 ) {
F_1 ( V_2 , V_3 ) ;
V_42 = V_210 ;
goto V_225;
}
return V_226 ;
V_225:
F_31 ( & V_60 -> V_61 ) ;
V_224:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_31 ( & V_8 ( V_20 ) -> V_63 ) ;
V_223:
F_31 ( & V_20 -> V_67 ) ;
V_222:
F_6 ( & V_20 -> V_24 ) ;
V_45:
switch ( V_42 ) {
case V_210 :
F_176 ( V_221 ) ;
if ( F_42 ( & V_20 -> V_67 ) == 0 &&
! F_167 ( V_20 ) )
F_177 ( V_221 , V_191 ) ;
break;
case V_211 :
if ( V_39 -> V_48 & V_156 )
F_81 ( V_2 ) ;
break;
default:
break;
}
return V_42 ;
}
static int F_178 ( void * V_227 , struct V_23 * V_162 ,
unsigned int V_228 , unsigned int V_229 ,
unsigned int V_230 )
{
struct V_1 * V_2 = F_170 ( V_162 ) ;
V_2 -> V_58 = F_179 ( V_55 , V_231 ,
V_230 ) ;
if ( ! V_2 -> V_58 )
return - V_232 ;
return 0 ;
}
static void F_180 ( void * V_227 , struct V_23 * V_162 ,
unsigned int V_228 , unsigned int V_229 )
{
struct V_1 * V_2 = F_170 ( V_162 ) ;
F_27 ( V_2 -> V_58 ) ;
}
static T_1 F_181 ( struct V_4 * V_60 )
{
struct V_6 * V_233 ;
T_1 V_234 = 0xffffffff ;
if ( V_60 -> V_235 )
return V_236 ;
if ( ! V_237 )
return V_238 ;
V_233 = F_182 ( V_60 ) ;
if ( V_233 && V_233 -> V_239 )
V_234 = ( T_1 ) F_183 ( V_233 ) << V_240 ;
return V_234 ;
}
static void F_184 ( struct V_4 * V_60 , struct V_21 * V_22 )
{
struct V_6 * V_241 = V_60 -> V_242 ;
F_185 ( V_22 , F_186 (unsigned short, shost->sg_tablesize,
SCSI_MAX_SG_CHAIN_SEGMENTS) ) ;
if ( F_187 ( V_60 ) ) {
V_60 -> V_243 =
F_188 ( V_60 -> V_243 ,
( unsigned short ) V_244 ) ;
F_66 ( V_60 -> V_243 < V_60 -> V_219 ) ;
F_189 ( V_22 , V_60 -> V_243 ) ;
}
F_190 ( V_22 , V_60 -> V_245 ) ;
F_191 ( V_22 , F_181 ( V_60 ) ) ;
F_192 ( V_22 , V_60 -> V_246 ) ;
F_193 ( V_241 , V_60 -> V_246 ) ;
F_194 ( V_22 , F_195 ( V_241 ) ) ;
if ( ! V_60 -> V_247 )
V_22 -> V_248 . V_249 = 0 ;
F_196 ( V_22 , 0x03 ) ;
}
struct V_21 * F_197 ( struct V_4 * V_60 ,
T_3 * V_250 )
{
struct V_21 * V_22 ;
V_22 = F_198 ( V_250 , NULL ) ;
if ( ! V_22 )
return NULL ;
F_184 ( V_60 , V_22 ) ;
return V_22 ;
}
struct V_21 * F_199 ( struct V_7 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_197 ( V_20 -> V_5 , F_158 ) ;
if ( ! V_22 )
return NULL ;
F_200 ( V_22 , F_132 ) ;
F_201 ( V_22 , F_133 ) ;
F_202 ( V_22 , F_150 ) ;
F_203 ( V_22 , V_251 ) ;
F_204 ( V_22 , F_144 ) ;
return V_22 ;
}
struct V_21 * F_205 ( struct V_7 * V_20 )
{
V_20 -> V_21 = F_206 ( & V_20 -> V_5 -> V_252 ) ;
if ( F_207 ( V_20 -> V_21 ) )
return NULL ;
V_20 -> V_21 -> V_77 = V_20 ;
F_184 ( V_20 -> V_5 , V_20 -> V_21 ) ;
return V_20 -> V_21 ;
}
int F_208 ( struct V_4 * V_60 )
{
unsigned int V_218 , V_253 , V_254 ;
V_254 = V_60 -> V_219 ;
if ( V_254 > V_84 )
V_254 = V_84 ;
V_253 = V_254 * sizeof( struct V_85 ) ;
V_218 = sizeof( struct V_1 ) + V_60 -> V_217 -> V_218 + V_253 ;
if ( F_172 ( V_60 ) )
V_218 += sizeof( struct V_92 ) + V_253 ;
memset ( & V_60 -> V_252 , 0 , sizeof( V_60 -> V_252 ) ) ;
V_60 -> V_252 . V_255 = & V_256 ;
V_60 -> V_252 . V_257 = 1 ;
V_60 -> V_252 . V_71 = V_60 -> V_62 ;
V_60 -> V_252 . V_218 = V_218 ;
V_60 -> V_252 . V_230 = V_258 ;
V_60 -> V_252 . V_26 = V_259 | V_260 ;
V_60 -> V_252 . V_261 = V_60 ;
return F_209 ( & V_60 -> V_252 ) ;
}
void F_210 ( struct V_4 * V_60 )
{
F_211 ( & V_60 -> V_252 ) ;
}
void F_212 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 1 ;
}
void F_213 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 0 ;
F_63 ( V_60 ) ;
}
int T_4 F_214 ( void )
{
int V_262 ;
V_107 = F_215 ( L_15 ,
sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_107 ) {
F_163 ( V_185 L_16 ) ;
return - V_232 ;
}
for ( V_262 = 0 ; V_262 < V_263 ; V_262 ++ ) {
struct V_87 * V_88 = V_89 + V_262 ;
int V_264 = V_88 -> V_264 * sizeof( struct V_85 ) ;
V_88 -> V_265 = F_215 ( V_88 -> V_266 , V_264 , 0 ,
V_267 , NULL ) ;
if ( ! V_88 -> V_265 ) {
F_163 ( V_185 L_17 ,
V_88 -> V_266 ) ;
goto V_268;
}
V_88 -> V_90 = F_216 ( V_269 ,
V_88 -> V_265 ) ;
if ( ! V_88 -> V_90 ) {
F_163 ( V_185 L_18 ,
V_88 -> V_266 ) ;
goto V_268;
}
}
return 0 ;
V_268:
for ( V_262 = 0 ; V_262 < V_263 ; V_262 ++ ) {
struct V_87 * V_88 = V_89 + V_262 ;
if ( V_88 -> V_90 )
F_217 ( V_88 -> V_90 ) ;
if ( V_88 -> V_265 )
F_218 ( V_88 -> V_265 ) ;
}
F_218 ( V_107 ) ;
return - V_232 ;
}
void F_219 ( void )
{
int V_262 ;
F_218 ( V_107 ) ;
for ( V_262 = 0 ; V_262 < V_263 ; V_262 ++ ) {
struct V_87 * V_88 = V_89 + V_262 ;
F_217 ( V_88 -> V_90 ) ;
F_218 ( V_88 -> V_265 ) ;
}
}
int
F_220 ( struct V_7 * V_20 , int V_270 , int V_271 , int V_272 ,
unsigned char * V_33 , int V_135 , int V_36 , int V_37 ,
struct V_273 * V_227 , struct V_53 * V_54 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_274 ;
int V_42 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_270 ? 0x10 : 0 ) | ( V_271 ? 0x01 : 0 ) ;
if ( V_20 -> V_275 ) {
if ( V_135 > 65535 )
return - V_276 ;
V_274 = F_221 ( 8 + V_135 , V_231 ) ;
if ( ! V_274 )
return - V_232 ;
memcpy ( V_274 + 8 , V_33 , V_135 ) ;
V_135 += 8 ;
V_274 [ 0 ] = 0 ;
V_274 [ 1 ] = 0 ;
V_274 [ 2 ] = V_227 -> V_277 ;
V_274 [ 3 ] = V_227 -> V_278 ;
V_274 [ 4 ] = V_227 -> V_279 ? 0x01 : 0 ;
V_274 [ 5 ] = 0 ;
V_274 [ 6 ] = V_227 -> V_280 >> 8 ;
V_274 [ 7 ] = V_227 -> V_280 ;
V_2 [ 0 ] = V_281 ;
V_2 [ 7 ] = V_135 >> 8 ;
V_2 [ 8 ] = V_135 ;
} else {
if ( V_135 > 255 || V_227 -> V_280 > 255 ||
V_227 -> V_279 )
return - V_276 ;
V_274 = F_221 ( 4 + V_135 , V_231 ) ;
if ( ! V_274 )
return - V_232 ;
memcpy ( V_274 + 4 , V_33 , V_135 ) ;
V_135 += 4 ;
V_274 [ 0 ] = 0 ;
V_274 [ 1 ] = V_227 -> V_277 ;
V_274 [ 2 ] = V_227 -> V_278 ;
V_274 [ 3 ] = V_227 -> V_280 ;
V_2 [ 0 ] = V_282 ;
V_2 [ 4 ] = V_135 ;
}
V_42 = F_222 ( V_20 , V_2 , V_41 , V_274 , V_135 ,
V_54 , V_36 , V_37 , NULL ) ;
F_27 ( V_274 ) ;
return V_42 ;
}
int
F_223 ( struct V_7 * V_20 , int V_283 , int V_272 ,
unsigned char * V_33 , int V_135 , int V_36 , int V_37 ,
struct V_273 * V_227 , struct V_53 * V_54 )
{
unsigned char V_2 [ 12 ] ;
int V_275 ;
int V_284 ;
int V_28 ;
struct V_53 V_285 ;
memset ( V_227 , 0 , sizeof( * V_227 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_283 & 0x18 ;
V_2 [ 2 ] = V_272 ;
if ( ! V_54 )
V_54 = & V_285 ;
V_286:
V_275 = V_20 -> V_275 ;
if ( V_275 ) {
if ( V_135 < 8 )
V_135 = 8 ;
V_2 [ 0 ] = V_287 ;
V_2 [ 8 ] = V_135 ;
V_284 = 8 ;
} else {
if ( V_135 < 4 )
V_135 = 4 ;
V_2 [ 0 ] = V_288 ;
V_2 [ 4 ] = V_135 ;
V_284 = 4 ;
}
memset ( V_33 , 0 , V_135 ) ;
V_28 = F_222 ( V_20 , V_2 , V_179 , V_33 , V_135 ,
V_54 , V_36 , V_37 , NULL ) ;
if ( V_275 && ! F_224 ( V_28 ) &&
( F_109 ( V_28 ) & V_155 ) ) {
if ( F_225 ( V_54 ) ) {
if ( ( V_54 -> V_136 == V_145 ) &&
( V_54 -> V_138 == 0x20 ) && ( V_54 -> V_139 == 0 ) ) {
V_20 -> V_275 = 0 ;
goto V_286;
}
}
}
if( F_224 ( V_28 ) ) {
if ( F_22 ( V_33 [ 0 ] == 0x86 && V_33 [ 1 ] == 0x0b &&
( V_272 == 6 || V_272 == 8 ) ) ) {
V_284 = 0 ;
V_227 -> V_160 = 13 ;
V_227 -> V_277 = 0 ;
V_227 -> V_278 = 0 ;
V_227 -> V_279 = 0 ;
V_227 -> V_280 = 0 ;
} else if( V_275 ) {
V_227 -> V_160 = V_33 [ 0 ] * 256 + V_33 [ 1 ] + 2 ;
V_227 -> V_277 = V_33 [ 2 ] ;
V_227 -> V_278 = V_33 [ 3 ] ;
V_227 -> V_279 = V_33 [ 4 ] & 0x01 ;
V_227 -> V_280 = V_33 [ 6 ] * 256
+ V_33 [ 7 ] ;
} else {
V_227 -> V_160 = V_33 [ 0 ] + 1 ;
V_227 -> V_277 = V_33 [ 1 ] ;
V_227 -> V_278 = V_33 [ 2 ] ;
V_227 -> V_280 = V_33 [ 3 ] ;
}
V_227 -> V_284 = V_284 ;
}
return V_28 ;
}
int
F_226 ( struct V_7 * V_20 , int V_36 , int V_37 ,
struct V_53 * V_289 )
{
char V_2 [] = {
V_290 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_53 * V_54 ;
int V_28 ;
if ( ! V_289 )
V_54 = F_25 ( sizeof( * V_54 ) , V_231 ) ;
else
V_54 = V_289 ;
do {
V_28 = F_222 ( V_20 , V_2 , V_177 , NULL , 0 , V_54 ,
V_36 , V_37 , NULL ) ;
if ( V_20 -> V_143 && F_225 ( V_54 ) &&
V_54 -> V_136 == V_142 )
V_20 -> V_144 = 1 ;
} while ( F_225 ( V_54 ) &&
V_54 -> V_136 == V_142 && -- V_37 );
if ( ! V_289 )
F_27 ( V_54 ) ;
return V_28 ;
}
int
F_227 ( struct V_7 * V_20 , enum V_291 V_292 )
{
enum V_291 V_293 = V_20 -> V_181 ;
if ( V_292 == V_293 )
return 0 ;
switch ( V_292 ) {
case V_294 :
switch ( V_293 ) {
case V_189 :
break;
default:
goto V_295;
}
break;
case V_182 :
switch ( V_293 ) {
case V_294 :
case V_183 :
case V_184 :
case V_187 :
case V_188 :
break;
default:
goto V_295;
}
break;
case V_187 :
switch ( V_293 ) {
case V_182 :
case V_183 :
case V_184 :
break;
default:
goto V_295;
}
break;
case V_183 :
case V_184 :
switch ( V_293 ) {
case V_294 :
case V_182 :
case V_187 :
case V_188 :
break;
default:
goto V_295;
}
break;
case V_188 :
switch ( V_293 ) {
case V_182 :
case V_189 :
break;
default:
goto V_295;
}
break;
case V_189 :
switch ( V_293 ) {
case V_294 :
break;
default:
goto V_295;
}
break;
case V_296 :
switch ( V_293 ) {
case V_294 :
case V_182 :
case V_187 :
case V_183 :
case V_184 :
case V_188 :
break;
default:
goto V_295;
}
break;
case V_186 :
switch ( V_293 ) {
case V_294 :
case V_182 :
case V_183 :
case V_184 :
case V_296 :
case V_189 :
break;
default:
goto V_295;
}
break;
}
V_20 -> V_181 = V_292 ;
return 0 ;
V_295:
F_228 ( 1 ,
F_129 ( V_185 , V_20 ,
L_19 ,
F_229 ( V_293 ) ,
F_229 ( V_292 ) )
) ;
return - V_276 ;
}
static void F_230 ( struct V_7 * V_20 , struct V_297 * V_298 )
{
int V_299 = 0 ;
char * V_300 [ 3 ] ;
switch ( V_298 -> V_301 ) {
case V_302 :
V_300 [ V_299 ++ ] = L_20 ;
break;
case V_303 :
V_300 [ V_299 ++ ] = L_21 ;
break;
case V_304 :
V_300 [ V_299 ++ ] = L_22 ;
break;
case V_305 :
V_300 [ V_299 ++ ] = L_23 ;
break;
case V_306 :
V_300 [ V_299 ++ ] = L_24 ;
break;
case V_307 :
V_300 [ V_299 ++ ] = L_25 ;
break;
default:
break;
}
V_300 [ V_299 ++ ] = NULL ;
F_231 ( & V_20 -> V_24 . V_308 , V_309 , V_300 ) ;
}
void F_232 ( struct V_79 * V_80 )
{
struct V_7 * V_20 ;
enum V_310 V_301 ;
F_46 ( V_311 ) ;
V_20 = F_58 ( V_80 , struct V_7 , V_312 ) ;
for ( V_301 = V_313 ; V_301 <= V_314 ; V_301 ++ )
if ( F_233 ( V_301 , V_20 -> V_315 ) )
F_234 ( V_20 , V_301 , V_231 ) ;
while ( 1 ) {
struct V_297 * V_298 ;
struct V_316 * V_317 , * V_69 ;
unsigned long V_26 ;
F_11 ( & V_20 -> V_105 , V_26 ) ;
F_47 ( & V_20 -> V_311 , & V_311 ) ;
F_14 ( & V_20 -> V_105 , V_26 ) ;
if ( F_48 ( & V_311 ) )
break;
F_235 (this, tmp, &event_list) {
V_298 = F_49 ( V_317 , struct V_297 , V_318 ) ;
F_236 ( & V_298 -> V_318 ) ;
F_230 ( V_20 , V_298 ) ;
F_27 ( V_298 ) ;
}
}
}
void F_237 ( struct V_7 * V_20 , struct V_297 * V_298 )
{
unsigned long V_26 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_11 ( & V_20 -> V_105 , V_26 ) ;
F_143 ( & V_298 -> V_318 , & V_20 -> V_311 ) ;
F_238 ( & V_20 -> V_312 ) ;
F_14 ( & V_20 -> V_105 , V_26 ) ;
}
struct V_297 * F_239 ( enum V_310 V_301 ,
T_2 V_319 )
{
struct V_297 * V_298 = F_25 ( sizeof( struct V_297 ) , V_319 ) ;
if ( ! V_298 )
return NULL ;
V_298 -> V_301 = V_301 ;
F_151 ( & V_298 -> V_318 ) ;
switch ( V_301 ) {
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
case V_307 :
default:
break;
}
return V_298 ;
}
void F_234 ( struct V_7 * V_20 ,
enum V_310 V_301 , T_2 V_319 )
{
struct V_297 * V_298 = F_239 ( V_301 , V_319 ) ;
if ( ! V_298 ) {
F_129 ( V_185 , V_20 , L_26 ,
V_301 ) ;
return;
}
F_237 ( V_20 , V_298 ) ;
}
int
F_240 ( struct V_7 * V_20 )
{
int V_320 = F_227 ( V_20 , V_187 ) ;
if ( V_320 )
return V_320 ;
F_55 ( V_20 -> V_21 ) ;
while ( F_42 ( & V_20 -> V_67 ) ) {
F_241 ( 200 ) ;
F_55 ( V_20 -> V_21 ) ;
}
return 0 ;
}
void F_242 ( struct V_7 * V_20 )
{
if ( V_20 -> V_181 != V_187 ||
F_227 ( V_20 , V_182 ) )
return;
F_55 ( V_20 -> V_21 ) ;
}
static void
F_243 ( struct V_7 * V_20 , void * V_227 )
{
F_240 ( V_20 ) ;
}
void
F_244 ( struct V_8 * V_9 )
{
F_245 ( V_9 , NULL , F_243 ) ;
}
static void
F_246 ( struct V_7 * V_20 , void * V_227 )
{
F_242 ( V_20 ) ;
}
void
F_247 ( struct V_8 * V_9 )
{
F_245 ( V_9 , NULL , F_246 ) ;
}
int
F_248 ( struct V_7 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
int V_320 = 0 ;
V_320 = F_227 ( V_20 , V_188 ) ;
if ( V_320 ) {
V_320 = F_227 ( V_20 , V_189 ) ;
if ( V_320 )
return V_320 ;
}
if ( V_22 -> V_29 ) {
F_249 ( V_22 ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_250 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
int
F_251 ( struct V_7 * V_20 ,
enum V_291 V_321 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
if ( ( V_20 -> V_181 == V_188 ) ||
( V_20 -> V_181 == V_184 ) )
V_20 -> V_181 = V_321 ;
else if ( V_20 -> V_181 == V_189 ) {
if ( V_321 == V_184 ||
V_321 == V_183 )
V_20 -> V_181 = V_321 ;
else
V_20 -> V_181 = V_294 ;
} else if ( V_20 -> V_181 != V_296 &&
V_20 -> V_181 != V_183 )
return - V_276 ;
if ( V_22 -> V_29 ) {
F_56 ( V_22 , false ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_252 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
static void
F_253 ( struct V_7 * V_20 , void * V_227 )
{
F_248 ( V_20 ) ;
}
static int
F_254 ( struct V_6 * V_241 , void * V_227 )
{
if ( F_255 ( V_241 ) )
F_245 ( F_256 ( V_241 ) , NULL ,
F_253 ) ;
return 0 ;
}
void
F_257 ( struct V_6 * V_241 )
{
if ( F_255 ( V_241 ) )
F_245 ( F_256 ( V_241 ) , NULL ,
F_253 ) ;
else
F_258 ( V_241 , NULL , F_254 ) ;
}
static void
F_259 ( struct V_7 * V_20 , void * V_227 )
{
F_251 ( V_20 , * (enum V_291 * ) V_227 ) ;
}
static int
F_260 ( struct V_6 * V_241 , void * V_227 )
{
if ( F_255 ( V_241 ) )
F_245 ( F_256 ( V_241 ) , V_227 ,
F_259 ) ;
return 0 ;
}
void
F_261 ( struct V_6 * V_241 , enum V_291 V_321 )
{
if ( F_255 ( V_241 ) )
F_245 ( F_256 ( V_241 ) , & V_321 ,
F_259 ) ;
else
F_258 ( V_241 , & V_321 , F_260 ) ;
}
void * F_262 ( struct V_85 * V_86 , int V_322 ,
T_5 * V_323 , T_5 * V_135 )
{
int V_262 ;
T_5 V_324 = 0 , V_325 = 0 ;
struct V_85 * V_213 ;
struct V_326 * V_326 ;
F_263 ( ! F_264 () ) ;
F_265 (sgl, sg, sg_count, i) {
V_325 = V_324 ;
V_324 += V_213 -> V_160 ;
if ( V_324 > * V_323 )
break;
}
if ( F_22 ( V_262 == V_322 ) ) {
F_163 ( V_185 L_27
L_28 ,
V_206 , V_324 , * V_323 , V_322 ) ;
F_263 ( 1 ) ;
return NULL ;
}
* V_323 = * V_323 - V_325 + V_213 -> V_323 ;
V_326 = F_266 ( F_267 ( V_213 ) , ( * V_323 >> V_240 ) ) ;
* V_323 &= ~ V_327 ;
V_324 = V_328 - * V_323 ;
if ( * V_135 > V_324 )
* V_135 = V_324 ;
return F_268 ( V_326 ) ;
}
void F_269 ( void * V_329 )
{
F_270 ( V_329 ) ;
}
void F_271 ( struct V_7 * V_20 )
{
F_148 ( & V_20 -> V_330 ) ;
}
void F_272 ( struct V_7 * V_20 )
{
if ( F_273 ( F_42 ( & V_20 -> V_330 ) <= 0 ) )
return;
F_31 ( & V_20 -> V_330 ) ;
}
