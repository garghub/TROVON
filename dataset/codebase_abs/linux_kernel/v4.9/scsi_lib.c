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
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_82 == V_83 ) {
struct V_84 * V_85 = F_66 ( V_2 ) ;
if ( V_85 -> V_86 )
V_85 -> V_86 ( V_2 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_87 * V_88 ;
if ( V_2 -> V_88 . V_89 . V_90 )
F_68 ( & V_2 -> V_88 . V_89 , true ) ;
if ( V_2 -> V_23 -> V_91 ) {
V_88 = V_2 -> V_23 -> V_91 -> V_81 ;
if ( V_88 )
F_68 ( & V_88 -> V_89 , true ) ;
}
if ( F_69 ( V_2 ) )
F_68 ( & V_2 -> V_92 -> V_89 , true ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned long V_26 ;
F_67 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_60 -> V_93 ) {
F_71 ( F_49 ( & V_2 -> V_94 ) ) ;
F_11 ( & V_20 -> V_95 , V_26 ) ;
F_51 ( & V_2 -> V_94 ) ;
F_14 ( & V_20 -> V_95 , V_26 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 . V_89 . V_90 )
F_68 ( & V_2 -> V_88 . V_89 , false ) ;
memset ( & V_2 -> V_88 , 0 , sizeof( V_2 -> V_88 ) ) ;
if ( F_69 ( V_2 ) )
F_68 ( & V_2 -> V_92 -> V_89 , false ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_87 * V_96 = V_2 -> V_23 -> V_91 -> V_81 ;
F_68 ( & V_96 -> V_89 , false ) ;
F_74 ( V_97 , V_96 ) ;
V_2 -> V_23 -> V_91 -> V_81 = NULL ;
}
static bool F_75 ( struct V_23 * V_39 , int error ,
unsigned int V_98 , unsigned int V_99 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_22 = V_20 -> V_21 ;
if ( F_76 ( V_39 , error , V_98 ) )
return true ;
if ( F_23 ( V_99 ) &&
F_76 ( V_39 -> V_91 , error , V_99 ) )
return true ;
if ( F_77 ( V_22 ) )
F_78 ( V_39 -> V_100 ) ;
if ( V_39 -> V_101 ) {
F_70 ( V_2 ) ;
F_79 ( V_39 , error ) ;
if ( V_8 ( V_20 ) -> V_78 ||
! F_49 ( & V_20 -> V_5 -> V_73 ) )
F_13 ( & V_20 -> V_31 ) ;
else
F_57 ( V_22 , true ) ;
} else {
unsigned long V_26 ;
if ( V_99 )
F_73 ( V_2 ) ;
F_11 ( V_22 -> V_30 , V_26 ) ;
F_80 ( V_39 , error ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
F_72 ( V_2 ) ;
F_62 ( V_2 ) ;
F_56 ( V_22 ) ;
}
F_6 ( & V_20 -> V_24 ) ;
return false ;
}
static int F_81 ( struct V_1 * V_2 , int V_28 )
{
int error = 0 ;
switch( F_82 ( V_28 ) ) {
case V_102 :
error = - V_103 ;
break;
case V_104 :
F_83 ( V_2 , V_105 ) ;
error = - V_106 ;
break;
case V_107 :
F_83 ( V_2 , V_105 ) ;
error = - V_108 ;
break;
case V_109 :
F_83 ( V_2 , V_105 ) ;
error = - V_110 ;
break;
case V_111 :
F_83 ( V_2 , V_105 ) ;
error = - V_112 ;
break;
default:
error = - V_113 ;
break;
}
return error ;
}
void F_84 ( struct V_1 * V_2 , unsigned int V_114 )
{
int V_28 = V_2 -> V_28 ;
struct V_21 * V_22 = V_2 -> V_6 -> V_21 ;
struct V_23 * V_39 = V_2 -> V_23 ;
int error = 0 ;
struct V_53 V_54 ;
bool V_115 = false ;
int V_116 = 0 , V_117 = 0 ;
enum { V_118 , V_119 , V_120 ,
V_121 } V_122 ;
unsigned long V_123 = ( V_2 -> V_124 + 1 ) * V_39 -> V_36 ;
if ( V_28 ) {
V_115 = F_85 ( V_2 , & V_54 ) ;
if ( V_115 )
V_116 = F_86 ( & V_54 ) ;
}
if ( V_39 -> V_82 == V_125 ) {
if ( V_28 ) {
if ( V_115 && V_39 -> V_35 ) {
int V_126 = 8 + V_2 -> V_58 [ 7 ] ;
if ( V_126 > V_55 )
V_126 = V_55 ;
memcpy ( V_39 -> V_35 , V_2 -> V_58 , V_126 ) ;
V_39 -> V_47 = V_126 ;
}
if ( ! V_116 )
error = F_81 ( V_2 , V_28 ) ;
}
V_39 -> V_52 = V_2 -> V_28 ;
V_39 -> V_51 = F_87 ( V_2 ) ;
if ( F_88 ( V_2 ) ) {
V_39 -> V_91 -> V_51 = F_89 ( V_2 ) -> V_38 ;
if ( F_75 ( V_39 , 0 , F_90 ( V_39 ) ,
F_90 ( V_39 -> V_91 ) ) )
F_91 () ;
return;
}
} else if ( F_90 ( V_39 ) == 0 && V_28 && ! V_116 ) {
error = F_81 ( V_2 , V_28 ) ;
}
F_71 ( F_92 ( V_39 ) ) ;
F_93 ( 1 , F_9 ( V_27 , V_2 ,
L_2 ,
F_94 ( V_39 ) , V_114 ) ) ;
if ( V_115 && ( V_54 . V_127 == V_128 ) ) {
if ( ( V_54 . V_129 == 0x0 ) && ( V_54 . V_130 == 0x1d ) )
;
else if ( ! ( V_39 -> V_48 & V_49 ) )
F_95 ( V_2 ) ;
V_28 = 0 ;
error = 0 ;
}
if ( ! ( F_90 ( V_39 ) == 0 && error ) &&
! F_75 ( V_39 , error , V_114 , 0 ) )
return;
if ( error && F_96 ( V_2 ) ) {
if ( F_75 ( V_39 , error , F_90 ( V_39 ) , 0 ) )
F_91 () ;
return;
}
if ( V_28 == 0 )
goto V_131;
error = F_81 ( V_2 , V_28 ) ;
if ( F_82 ( V_28 ) == V_132 ) {
V_122 = V_120 ;
} else if ( V_115 && ! V_116 ) {
switch ( V_54 . V_127 ) {
case V_133 :
if ( V_2 -> V_6 -> V_134 ) {
V_2 -> V_6 -> V_135 = 1 ;
V_122 = V_118 ;
} else {
V_122 = V_120 ;
}
break;
case V_136 :
if ( ( V_2 -> V_6 -> V_137 &&
V_54 . V_129 == 0x20 && V_54 . V_130 == 0x00 ) &&
( V_2 -> V_59 [ 0 ] == V_138 ||
V_2 -> V_59 [ 0 ] == V_139 ) ) {
V_2 -> V_6 -> V_137 = 0 ;
V_122 = V_119 ;
} else if ( V_54 . V_129 == 0x10 ) {
V_122 = V_118 ;
error = - V_140 ;
} else if ( V_54 . V_129 == 0x20 || V_54 . V_129 == 0x24 ) {
V_122 = V_118 ;
error = - V_106 ;
} else
V_122 = V_118 ;
break;
case V_141 :
V_122 = V_118 ;
if ( V_54 . V_129 == 0x10 )
error = - V_140 ;
break;
case V_142 :
if ( V_54 . V_129 == 0x04 ) {
switch ( V_54 . V_130 ) {
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
V_122 = V_118 ;
break;
}
} else
V_122 = V_118 ;
break;
case V_143 :
V_122 = V_118 ;
break;
default:
V_122 = V_118 ;
break;
}
} else
V_122 = V_118 ;
if ( V_122 != V_118 &&
F_97 ( V_2 -> V_144 + V_123 , V_145 ) )
V_122 = V_118 ;
switch ( V_122 ) {
case V_118 :
if ( ! ( V_39 -> V_48 & V_49 ) ) {
static F_98 ( V_146 ,
V_147 ,
V_148 ) ;
if ( F_23 ( V_149 ) )
V_117 = F_99 ( V_150 ,
V_151 ) ;
if ( ! V_117 && F_100 ( & V_146 ) ) {
F_101 ( V_2 , NULL , V_152 ) ;
if ( F_102 ( V_28 ) & V_153 )
F_95 ( V_2 ) ;
F_103 ( V_2 ) ;
}
}
if ( ! F_75 ( V_39 , error , F_104 ( V_39 ) , 0 ) )
return;
case V_119 :
V_131:
if ( V_22 -> V_29 ) {
V_2 -> V_23 -> V_48 &= ~ V_154 ;
F_70 ( V_2 ) ;
F_3 ( V_2 ) ;
} else {
F_72 ( V_2 ) ;
F_60 ( V_22 , V_2 ) ;
}
break;
case V_120 :
F_7 ( V_2 , V_14 , 0 ) ;
break;
case V_121 :
F_7 ( V_2 , V_13 , 0 ) ;
break;
}
}
static int F_105 ( struct V_23 * V_39 , struct V_87 * V_88 )
{
int V_155 ;
if ( F_23 ( F_106 ( & V_88 -> V_89 , V_39 -> V_156 ,
V_88 -> V_89 . V_157 ) ) )
return V_158 ;
V_155 = F_107 ( V_39 -> V_22 , V_39 , V_88 -> V_89 . V_157 ) ;
F_71 ( V_155 > V_88 -> V_89 . V_90 ) ;
V_88 -> V_89 . V_90 = V_155 ;
V_88 -> V_159 = F_90 ( V_39 ) ;
return V_160 ;
}
int F_108 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_23 * V_161 = V_2 -> V_23 ;
bool V_162 = ( V_161 -> V_101 != NULL ) ;
int error ;
F_71 ( ! V_161 -> V_156 ) ;
error = F_105 ( V_161 , & V_2 -> V_88 ) ;
if ( error )
goto V_163;
if ( F_92 ( V_161 ) ) {
if ( ! V_161 -> V_22 -> V_29 ) {
struct V_87 * V_96 =
F_109 ( V_97 , V_164 ) ;
if ( ! V_96 ) {
error = V_158 ;
goto V_163;
}
V_161 -> V_91 -> V_81 = V_96 ;
}
error = F_105 ( V_161 -> V_91 , V_161 -> V_91 -> V_81 ) ;
if ( error )
goto V_163;
}
if ( F_110 ( V_161 ) ) {
struct V_87 * V_92 = V_2 -> V_92 ;
int V_165 , V_155 ;
if ( V_92 == NULL ) {
F_111 ( 1 ) ;
error = V_166 ;
goto V_163;
}
V_165 = F_112 ( V_161 -> V_22 , V_161 -> V_167 ) ;
if ( F_106 ( & V_92 -> V_89 , V_165 ,
V_92 -> V_89 . V_157 ) ) {
error = V_158 ;
goto V_163;
}
V_155 = F_113 ( V_161 -> V_22 , V_161 -> V_167 ,
V_92 -> V_89 . V_157 ) ;
F_71 ( F_23 ( V_155 > V_165 ) ) ;
F_71 ( F_23 ( V_155 > F_114 ( V_161 -> V_22 ) ) ) ;
V_2 -> V_92 = V_92 ;
V_2 -> V_92 -> V_89 . V_90 = V_155 ;
}
return V_160 ;
V_163:
if ( V_162 ) {
F_67 ( V_2 ) ;
} else {
F_72 ( V_2 ) ;
V_2 -> V_23 -> V_81 = NULL ;
F_62 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
}
return error ;
}
static struct V_1 * F_115 ( struct V_7 * V_20 ,
struct V_23 * V_39 )
{
struct V_1 * V_2 ;
if ( ! V_39 -> V_81 ) {
if ( ! F_116 ( & V_20 -> V_24 ) )
return NULL ;
V_2 = F_117 ( V_20 , V_164 ) ;
if ( F_23 ( ! V_2 ) ) {
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
static int F_118 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( V_39 -> V_167 ) {
int V_42 = F_108 ( V_2 ) ;
if ( F_23 ( V_42 ) )
return V_42 ;
} else {
F_71 ( F_90 ( V_39 ) ) ;
memset ( & V_2 -> V_88 , 0 , sizeof( V_2 -> V_88 ) ) ;
}
V_2 -> V_46 = V_39 -> V_46 ;
V_2 -> V_171 = F_90 ( V_39 ) ;
V_2 -> V_124 = V_39 -> V_37 ;
return V_160 ;
}
static int F_119 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( F_23 ( V_20 -> V_172 && V_20 -> V_172 -> V_173 ) ) {
int V_42 = V_20 -> V_172 -> V_173 ( V_20 , V_39 ) ;
if ( V_42 != V_160 )
return V_42 ;
}
memset ( V_2 -> V_59 , 0 , V_174 ) ;
return F_66 ( V_2 ) -> F_120 ( V_2 ) ;
}
static int F_121 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
if ( ! F_90 ( V_39 ) )
V_2 -> V_175 = V_176 ;
else if ( F_122 ( V_39 ) == V_177 )
V_2 -> V_175 = V_41 ;
else
V_2 -> V_175 = V_178 ;
switch ( V_39 -> V_82 ) {
case V_83 :
return F_119 ( V_20 , V_39 ) ;
case V_125 :
return F_118 ( V_20 , V_39 ) ;
default:
return V_166 ;
}
}
static int
F_123 ( struct V_7 * V_20 , struct V_23 * V_39 )
{
int V_42 = V_160 ;
if ( F_23 ( V_20 -> V_179 != V_180 ) ) {
switch ( V_20 -> V_179 ) {
case V_181 :
case V_182 :
F_124 ( V_183 , V_20 ,
L_3 ) ;
V_42 = V_166 ;
break;
case V_184 :
F_124 ( V_183 , V_20 ,
L_4 ) ;
V_42 = V_166 ;
break;
case V_185 :
case V_186 :
V_42 = V_158 ;
break;
case V_187 :
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_158 ;
break;
default:
if ( ! ( V_39 -> V_48 & V_50 ) )
V_42 = V_166 ;
break;
}
}
return V_42 ;
}
static int
F_125 ( struct V_21 * V_22 , struct V_23 * V_39 , int V_42 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
switch ( V_42 ) {
case V_166 :
case V_188 :
V_39 -> V_52 = V_189 << 16 ;
if ( V_39 -> V_81 ) {
struct V_1 * V_2 = V_39 -> V_81 ;
F_72 ( V_2 ) ;
F_62 ( V_2 ) ;
F_6 ( & V_20 -> V_24 ) ;
V_39 -> V_81 = NULL ;
}
break;
case V_158 :
if ( F_43 ( & V_20 -> V_67 ) == 0 )
F_126 ( V_22 , V_190 ) ;
break;
default:
V_39 -> V_48 |= V_154 ;
}
return V_42 ;
}
static int F_127 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_1 * V_2 ;
int V_42 ;
V_42 = F_123 ( V_20 , V_39 ) ;
if ( V_42 != V_160 )
goto V_45;
V_2 = F_115 ( V_20 , V_39 ) ;
if ( F_23 ( ! V_2 ) ) {
V_42 = V_158 ;
goto V_45;
}
V_42 = F_121 ( V_20 , V_39 ) ;
V_45:
return F_125 ( V_22 , V_39 , V_42 ) ;
}
static void F_128 ( struct V_21 * V_22 , struct V_23 * V_39 )
{
F_65 ( V_39 -> V_81 ) ;
}
static inline int F_129 ( struct V_21 * V_22 ,
struct V_7 * V_20 )
{
unsigned int V_191 ;
V_191 = F_130 ( & V_20 -> V_67 ) - 1 ;
if ( F_43 ( & V_20 -> V_15 ) ) {
if ( V_191 )
goto V_192;
if ( F_131 ( & V_20 -> V_15 ) > 0 ) {
if ( ! V_22 -> V_29 )
F_126 ( V_22 , V_190 ) ;
goto V_192;
}
F_8 ( 3 , F_124 ( V_27 , V_20 ,
L_5 ) ) ;
}
if ( V_191 >= V_20 -> V_71 )
goto V_192;
return 1 ;
V_192:
F_32 ( & V_20 -> V_67 ) ;
return 0 ;
}
static inline int F_132 ( struct V_4 * V_60 ,
struct V_7 * V_20 )
{
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned int V_191 ;
if ( V_9 -> V_78 ) {
F_133 ( V_60 -> V_66 ) ;
if ( V_9 -> V_70 &&
V_9 -> V_70 != V_20 ) {
F_134 ( V_60 -> V_66 ) ;
return 0 ;
}
V_9 -> V_70 = V_20 ;
F_134 ( V_60 -> V_66 ) ;
}
if ( V_9 -> V_62 <= 0 )
return 1 ;
V_191 = F_130 ( & V_9 -> V_63 ) - 1 ;
if ( F_43 ( & V_9 -> V_18 ) > 0 ) {
if ( V_191 )
goto V_193;
if ( F_131 ( & V_9 -> V_18 ) > 0 )
goto V_192;
F_8 ( 3 , F_135 ( V_27 , V_9 ,
L_6 ) ) ;
}
if ( V_191 >= V_9 -> V_62 )
goto V_193;
return 1 ;
V_193:
F_133 ( V_60 -> V_66 ) ;
F_52 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_134 ( V_60 -> V_66 ) ;
V_192:
if ( V_9 -> V_62 > 0 )
F_32 ( & V_9 -> V_63 ) ;
return 0 ;
}
static inline int F_136 ( struct V_21 * V_22 ,
struct V_4 * V_60 ,
struct V_7 * V_20 )
{
unsigned int V_191 ;
if ( F_33 ( V_60 ) )
return 0 ;
V_191 = F_130 ( & V_60 -> V_61 ) - 1 ;
if ( F_43 ( & V_60 -> V_11 ) > 0 ) {
if ( V_191 )
goto V_193;
if ( F_131 ( & V_60 -> V_11 ) > 0 )
goto V_192;
F_8 ( 3 ,
F_137 ( V_27 , V_60 ,
L_7 ) ) ;
}
if ( V_60 -> V_62 > 0 && V_191 >= V_60 -> V_62 )
goto V_193;
if ( V_60 -> V_72 )
goto V_193;
if ( ! F_49 ( & V_20 -> V_76 ) ) {
F_133 ( V_60 -> V_66 ) ;
if ( ! F_49 ( & V_20 -> V_76 ) )
F_51 ( & V_20 -> V_76 ) ;
F_134 ( V_60 -> V_66 ) ;
}
return 1 ;
V_193:
F_133 ( V_60 -> V_66 ) ;
if ( F_49 ( & V_20 -> V_76 ) )
F_138 ( & V_20 -> V_76 , & V_60 -> V_73 ) ;
F_134 ( V_60 -> V_66 ) ;
V_192:
F_32 ( & V_60 -> V_61 ) ;
return 0 ;
}
static int F_139 ( struct V_21 * V_22 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
if ( F_140 ( V_22 ) )
return 0 ;
V_60 = V_20 -> V_5 ;
if ( F_33 ( V_60 ) || F_42 ( V_20 ) )
return 1 ;
return 0 ;
}
static void F_141 ( struct V_23 * V_39 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_39 -> V_81 ;
struct V_7 * V_20 ;
struct V_8 * V_9 ;
struct V_4 * V_60 ;
F_142 ( V_39 ) ;
F_9 ( V_27 , V_2 , L_8 ) ;
V_20 = V_2 -> V_6 ;
V_9 = V_8 ( V_20 ) ;
V_60 = V_20 -> V_5 ;
F_29 ( V_2 ) ;
V_2 -> V_28 = V_189 << 16 ;
F_143 ( & V_2 -> V_6 -> V_194 ) ;
F_143 ( & V_20 -> V_67 ) ;
F_143 ( & V_60 -> V_61 ) ;
if ( V_9 -> V_62 > 0 )
F_143 ( & V_9 -> V_63 ) ;
F_144 ( V_39 ) ;
}
static void F_145 ( struct V_23 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_81 ;
unsigned long V_123 = ( V_2 -> V_124 + 1 ) * V_161 -> V_36 ;
int V_195 ;
F_146 ( & V_2 -> V_196 ) ;
F_143 ( & V_2 -> V_6 -> V_197 ) ;
if ( V_2 -> V_28 )
F_143 ( & V_2 -> V_6 -> V_198 ) ;
V_195 = F_147 ( V_2 ) ;
if ( V_195 != V_199 &&
F_97 ( V_2 -> V_144 + V_123 , V_145 ) ) {
F_124 ( V_183 , V_2 -> V_6 ,
L_9 ,
V_123 / V_200 ) ;
V_195 = V_199 ;
}
F_148 ( V_2 , V_195 ) ;
switch ( V_195 ) {
case V_199 :
F_149 ( V_2 ) ;
break;
case V_201 :
F_15 ( V_2 , V_14 ) ;
break;
case V_202 :
F_15 ( V_2 , V_13 ) ;
break;
default:
if ( ! F_150 ( V_2 , 0 ) )
F_149 ( V_2 ) ;
}
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_5 ;
int V_203 = 0 ;
F_143 ( & V_2 -> V_6 -> V_194 ) ;
if ( F_23 ( V_2 -> V_6 -> V_179 == V_184 ) ) {
V_2 -> V_28 = V_189 << 16 ;
goto V_204;
}
if ( F_23 ( F_152 ( V_2 -> V_6 ) ) ) {
F_8 ( 3 , F_9 ( V_27 , V_2 ,
L_10 ) ) ;
return V_13 ;
}
if ( V_2 -> V_6 -> V_205 )
V_2 -> V_59 [ 1 ] = ( V_2 -> V_59 [ 1 ] & 0x1f ) |
( V_2 -> V_6 -> V_206 << 5 & 0xe0 ) ;
F_153 ( V_2 ) ;
if ( V_2 -> V_46 > V_2 -> V_6 -> V_5 -> V_207 ) {
F_8 ( 3 , F_9 ( V_27 , V_2 ,
L_11
L_12 ,
V_2 -> V_46 , V_2 -> V_6 -> V_5 -> V_207 ) ) ;
V_2 -> V_28 = ( V_208 << 16 ) ;
goto V_204;
}
if ( F_23 ( V_5 -> V_209 == V_210 ) ) {
V_2 -> V_28 = ( V_189 << 16 ) ;
goto V_204;
}
F_154 ( V_2 ) ;
V_203 = V_5 -> V_211 -> V_212 ( V_5 , V_2 ) ;
if ( V_203 ) {
F_155 ( V_2 , V_203 ) ;
if ( V_203 != V_13 &&
V_203 != V_17 )
V_203 = V_10 ;
F_8 ( 3 , F_9 ( V_27 , V_2 ,
L_13 ) ) ;
}
return V_203 ;
V_204:
V_2 -> V_213 ( V_2 ) ;
return 0 ;
}
static void V_213 ( struct V_1 * V_2 )
{
F_156 ( V_2 ) ;
F_144 ( V_2 -> V_23 ) ;
}
static void F_157 ( struct V_21 * V_22 )
__releases( V_22 -> V_30 )
__acquires( V_22 -> V_30 )
{
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 ;
struct V_1 * V_2 ;
struct V_23 * V_39 ;
V_60 = V_20 -> V_5 ;
for (; ; ) {
int V_203 ;
V_39 = F_158 ( V_22 ) ;
if ( ! V_39 )
break;
if ( F_23 ( ! F_159 ( V_20 ) ) ) {
F_124 ( V_183 , V_20 ,
L_3 ) ;
F_141 ( V_39 , V_22 ) ;
continue;
}
if ( ! F_129 ( V_22 , V_20 ) )
break;
if ( ! ( F_160 ( V_22 ) && ! F_161 ( V_22 , V_39 ) ) )
F_142 ( V_39 ) ;
F_134 ( V_22 -> V_30 ) ;
V_2 = V_39 -> V_81 ;
if ( F_23 ( V_2 == NULL ) ) {
F_162 ( V_214 L_14
L_15
L_16 ,
V_215 ) ;
F_163 ( V_39 , L_17 ) ;
F_91 () ;
}
if ( F_160 ( V_22 ) && ! ( V_39 -> V_48 & V_216 ) ) {
F_133 ( V_60 -> V_66 ) ;
if ( F_49 ( & V_20 -> V_76 ) )
F_138 ( & V_20 -> V_76 ,
& V_60 -> V_73 ) ;
F_134 ( V_60 -> V_66 ) ;
goto V_217;
}
if ( ! F_132 ( V_60 , V_20 ) )
goto V_217;
if ( ! F_136 ( V_22 , V_60 , V_20 ) )
goto V_218;
if ( V_20 -> V_219 )
V_2 -> V_26 |= V_220 ;
else
V_2 -> V_26 &= ~ V_220 ;
F_29 ( V_2 ) ;
V_2 -> V_213 = V_213 ;
V_203 = F_151 ( V_2 ) ;
if ( V_203 ) {
F_15 ( V_2 , V_203 ) ;
F_133 ( V_22 -> V_30 ) ;
goto V_221;
}
F_133 ( V_22 -> V_30 ) ;
}
return;
V_218:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_63 ) ;
V_217:
F_133 ( V_22 -> V_30 ) ;
F_12 ( V_22 , V_39 ) ;
F_32 ( & V_20 -> V_67 ) ;
V_221:
if ( ! F_43 ( & V_20 -> V_67 ) && ! F_152 ( V_20 ) )
F_126 ( V_22 , V_190 ) ;
}
static inline int F_164 ( int V_42 )
{
switch ( V_42 ) {
case V_160 :
return 0 ;
case V_158 :
return V_222 ;
default:
return V_223 ;
}
}
static int F_165 ( struct V_23 * V_39 )
{
struct V_1 * V_2 = F_166 ( V_39 ) ;
struct V_7 * V_20 = V_39 -> V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
unsigned char * V_224 = V_2 -> V_58 ;
struct V_225 * V_226 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_39 -> V_81 = V_2 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_6 = V_20 ;
V_2 -> V_58 = V_224 ;
V_2 -> V_168 = V_39 -> V_168 ;
V_2 -> V_59 = V_39 -> V_2 ;
V_2 -> V_169 = V_170 ;
F_146 ( & V_2 -> V_94 ) ;
F_167 ( & V_2 -> V_227 , V_228 ) ;
V_2 -> V_144 = V_145 ;
if ( V_60 -> V_93 ) {
F_133 ( & V_20 -> V_95 ) ;
F_138 ( & V_2 -> V_94 , & V_20 -> V_229 ) ;
F_134 ( & V_20 -> V_95 ) ;
}
V_226 = ( void * ) V_2 + sizeof( struct V_1 ) + V_60 -> V_211 -> V_230 ;
V_2 -> V_88 . V_89 . V_157 = V_226 ;
if ( F_168 ( V_60 ) ) {
V_2 -> V_92 = ( void * ) V_226 +
F_169 (unsigned int,
shost->sg_tablesize, SG_CHUNK_SIZE) *
sizeof( struct V_225 ) ;
memset ( V_2 -> V_92 , 0 , sizeof( struct V_87 ) ) ;
V_2 -> V_92 -> V_89 . V_157 =
(struct V_225 * ) ( V_2 -> V_92 + 1 ) ;
}
if ( F_92 ( V_39 ) ) {
struct V_23 * V_91 = V_39 -> V_91 ;
struct V_87 * V_96 = F_166 ( V_91 ) ;
memset ( V_96 , 0 , sizeof( struct V_87 ) ) ;
V_96 -> V_89 . V_157 =
(struct V_225 * ) ( V_96 + 1 ) ;
V_91 -> V_81 = V_96 ;
}
F_170 ( V_39 ) ;
return F_121 ( V_20 , V_39 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
F_156 ( V_2 ) ;
F_172 ( V_2 -> V_23 , V_2 -> V_23 -> V_52 ) ;
}
static int F_173 ( struct V_231 * V_232 ,
const struct V_233 * V_234 )
{
struct V_23 * V_39 = V_234 -> V_161 ;
struct V_21 * V_22 = V_39 -> V_22 ;
struct V_7 * V_20 = V_22 -> V_77 ;
struct V_4 * V_60 = V_20 -> V_5 ;
struct V_1 * V_2 = F_166 ( V_39 ) ;
int V_42 ;
int V_3 ;
V_42 = F_164 ( F_123 ( V_20 , V_39 ) ) ;
if ( V_42 )
goto V_45;
V_42 = V_222 ;
if ( ! F_116 ( & V_20 -> V_24 ) )
goto V_45;
if ( ! F_129 ( V_22 , V_20 ) )
goto V_235;
if ( ! F_132 ( V_60 , V_20 ) )
goto V_236;
if ( ! F_136 ( V_22 , V_60 , V_20 ) )
goto V_237;
if ( ! ( V_39 -> V_48 & V_154 ) ) {
V_42 = F_164 ( F_165 ( V_39 ) ) ;
if ( V_42 )
goto V_238;
V_39 -> V_48 |= V_154 ;
} else {
F_170 ( V_39 ) ;
}
if ( V_20 -> V_219 )
V_2 -> V_26 |= V_220 ;
else
V_2 -> V_26 &= ~ V_220 ;
F_29 ( V_2 ) ;
V_2 -> V_213 = F_171 ;
V_3 = F_151 ( V_2 ) ;
if ( V_3 ) {
F_1 ( V_2 , V_3 ) ;
V_42 = V_222 ;
goto V_238;
}
return V_239 ;
V_238:
F_32 ( & V_60 -> V_61 ) ;
V_237:
if ( V_8 ( V_20 ) -> V_62 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_63 ) ;
V_236:
F_32 ( & V_20 -> V_67 ) ;
V_235:
F_6 ( & V_20 -> V_24 ) ;
V_45:
switch ( V_42 ) {
case V_222 :
F_174 ( V_232 ) ;
if ( F_43 ( & V_20 -> V_67 ) == 0 &&
! F_152 ( V_20 ) )
F_175 ( V_232 , V_190 ) ;
break;
case V_223 :
if ( V_39 -> V_48 & V_154 )
F_70 ( V_2 ) ;
break;
default:
break;
}
return V_42 ;
}
static enum V_240 F_176 ( struct V_23 * V_39 ,
bool V_241 )
{
if ( V_241 )
return V_242 ;
return F_177 ( V_39 ) ;
}
static int F_178 ( void * V_243 , struct V_23 * V_161 ,
unsigned int V_244 , unsigned int V_245 ,
unsigned int V_246 )
{
struct V_1 * V_2 = F_166 ( V_161 ) ;
V_2 -> V_58 = F_179 ( V_55 , V_247 ,
V_246 ) ;
if ( ! V_2 -> V_58 )
return - V_248 ;
return 0 ;
}
static void F_180 ( void * V_243 , struct V_23 * V_161 ,
unsigned int V_244 , unsigned int V_245 )
{
struct V_1 * V_2 = F_166 ( V_161 ) ;
F_28 ( V_2 -> V_58 ) ;
}
static T_1 F_181 ( struct V_4 * V_60 )
{
struct V_6 * V_249 ;
T_1 V_250 = 0xffffffff ;
if ( V_60 -> V_251 )
return V_252 ;
if ( ! V_253 )
return V_254 ;
V_249 = F_182 ( V_60 ) ;
if ( V_249 && V_249 -> V_255 )
V_250 = ( T_1 ) F_183 ( V_249 ) << V_256 ;
return V_250 ;
}
static void F_184 ( struct V_4 * V_60 , struct V_21 * V_22 )
{
struct V_6 * V_257 = V_60 -> V_258 ;
F_185 ( V_22 , F_169 (unsigned short, shost->sg_tablesize,
SG_MAX_SEGMENTS) ) ;
if ( F_186 ( V_60 ) ) {
V_60 -> V_259 =
F_187 ( V_60 -> V_259 ,
( unsigned short ) V_260 ) ;
F_71 ( V_60 -> V_259 < V_60 -> V_261 ) ;
F_188 ( V_22 , V_60 -> V_259 ) ;
}
F_189 ( V_22 , V_60 -> V_262 ) ;
F_190 ( V_22 , F_181 ( V_60 ) ) ;
F_191 ( V_22 , V_60 -> V_263 ) ;
F_192 ( V_257 , V_60 -> V_263 ) ;
F_193 ( V_22 , F_194 ( V_257 ) ) ;
if ( ! V_60 -> V_264 )
V_22 -> V_265 . V_266 = 0 ;
F_195 ( V_22 , 0x03 ) ;
}
struct V_21 * F_196 ( struct V_4 * V_60 ,
T_2 * V_267 )
{
struct V_21 * V_22 ;
V_22 = F_197 ( V_267 , NULL ) ;
if ( ! V_22 )
return NULL ;
F_184 ( V_60 , V_22 ) ;
return V_22 ;
}
struct V_21 * F_198 ( struct V_7 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_196 ( V_20 -> V_5 , F_157 ) ;
if ( ! V_22 )
return NULL ;
F_199 ( V_22 , F_127 ) ;
F_200 ( V_22 , F_128 ) ;
F_201 ( V_22 , F_145 ) ;
F_202 ( V_22 , F_177 ) ;
F_203 ( V_22 , F_139 ) ;
return V_22 ;
}
struct V_21 * F_204 ( struct V_7 * V_20 )
{
V_20 -> V_21 = F_205 ( & V_20 -> V_5 -> V_268 ) ;
if ( F_18 ( V_20 -> V_21 ) )
return NULL ;
V_20 -> V_21 -> V_77 = V_20 ;
F_184 ( V_20 -> V_5 , V_20 -> V_21 ) ;
return V_20 -> V_21 ;
}
int F_206 ( struct V_4 * V_60 )
{
unsigned int V_230 , V_269 , V_270 ;
V_270 = V_60 -> V_261 ;
if ( V_270 > V_271 )
V_270 = V_271 ;
V_269 = V_270 * sizeof( struct V_225 ) ;
V_230 = sizeof( struct V_1 ) + V_60 -> V_211 -> V_230 + V_269 ;
if ( F_168 ( V_60 ) )
V_230 += sizeof( struct V_87 ) + V_269 ;
memset ( & V_60 -> V_268 , 0 , sizeof( V_60 -> V_268 ) ) ;
V_60 -> V_268 . V_272 = & V_273 ;
V_60 -> V_268 . V_274 = V_60 -> V_274 ? : 1 ;
V_60 -> V_268 . V_71 = V_60 -> V_62 ;
V_60 -> V_268 . V_230 = V_230 ;
V_60 -> V_268 . V_246 = V_275 ;
V_60 -> V_268 . V_26 = V_276 | V_277 ;
V_60 -> V_268 . V_26 |=
F_207 ( V_60 -> V_211 -> V_278 ) ;
V_60 -> V_268 . V_279 = V_60 ;
return F_208 ( & V_60 -> V_268 ) ;
}
void F_209 ( struct V_4 * V_60 )
{
F_210 ( & V_60 -> V_268 ) ;
}
void F_211 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 1 ;
}
void F_212 ( struct V_4 * V_60 )
{
V_60 -> V_72 = 0 ;
F_63 ( V_60 ) ;
}
int T_3 F_213 ( void )
{
V_97 = F_214 ( L_18 ,
sizeof( struct V_87 ) ,
0 , 0 , NULL ) ;
if ( ! V_97 ) {
F_162 ( V_183 L_19 ) ;
return - V_248 ;
}
return 0 ;
}
void F_215 ( void )
{
F_216 ( V_97 ) ;
}
int
F_217 ( struct V_7 * V_20 , int V_280 , int V_281 , int V_282 ,
unsigned char * V_33 , int V_126 , int V_36 , int V_37 ,
struct V_283 * V_243 , struct V_53 * V_54 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_284 ;
int V_42 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_280 ? 0x10 : 0 ) | ( V_281 ? 0x01 : 0 ) ;
if ( V_20 -> V_285 ) {
if ( V_126 > 65535 )
return - V_286 ;
V_284 = F_218 ( 8 + V_126 , V_247 ) ;
if ( ! V_284 )
return - V_248 ;
memcpy ( V_284 + 8 , V_33 , V_126 ) ;
V_126 += 8 ;
V_284 [ 0 ] = 0 ;
V_284 [ 1 ] = 0 ;
V_284 [ 2 ] = V_243 -> V_287 ;
V_284 [ 3 ] = V_243 -> V_288 ;
V_284 [ 4 ] = V_243 -> V_289 ? 0x01 : 0 ;
V_284 [ 5 ] = 0 ;
V_284 [ 6 ] = V_243 -> V_290 >> 8 ;
V_284 [ 7 ] = V_243 -> V_290 ;
V_2 [ 0 ] = V_291 ;
V_2 [ 7 ] = V_126 >> 8 ;
V_2 [ 8 ] = V_126 ;
} else {
if ( V_126 > 255 || V_243 -> V_290 > 255 ||
V_243 -> V_289 )
return - V_286 ;
V_284 = F_218 ( 4 + V_126 , V_247 ) ;
if ( ! V_284 )
return - V_248 ;
memcpy ( V_284 + 4 , V_33 , V_126 ) ;
V_126 += 4 ;
V_284 [ 0 ] = 0 ;
V_284 [ 1 ] = V_243 -> V_287 ;
V_284 [ 2 ] = V_243 -> V_288 ;
V_284 [ 3 ] = V_243 -> V_290 ;
V_2 [ 0 ] = V_292 ;
V_2 [ 4 ] = V_126 ;
}
V_42 = F_219 ( V_20 , V_2 , V_41 , V_284 , V_126 ,
V_54 , V_36 , V_37 , NULL ) ;
F_28 ( V_284 ) ;
return V_42 ;
}
int
F_220 ( struct V_7 * V_20 , int V_293 , int V_282 ,
unsigned char * V_33 , int V_126 , int V_36 , int V_37 ,
struct V_283 * V_243 , struct V_53 * V_54 )
{
unsigned char V_2 [ 12 ] ;
int V_285 ;
int V_294 ;
int V_28 , V_295 = V_37 ;
struct V_53 V_296 ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_293 & 0x18 ;
V_2 [ 2 ] = V_282 ;
if ( ! V_54 )
V_54 = & V_296 ;
V_297:
V_285 = V_20 -> V_285 ;
if ( V_285 ) {
if ( V_126 < 8 )
V_126 = 8 ;
V_2 [ 0 ] = V_298 ;
V_2 [ 8 ] = V_126 ;
V_294 = 8 ;
} else {
if ( V_126 < 4 )
V_126 = 4 ;
V_2 [ 0 ] = V_299 ;
V_2 [ 4 ] = V_126 ;
V_294 = 4 ;
}
memset ( V_33 , 0 , V_126 ) ;
V_28 = F_219 ( V_20 , V_2 , V_178 , V_33 , V_126 ,
V_54 , V_36 , V_37 , NULL ) ;
if ( V_285 && ! F_221 ( V_28 ) &&
( F_102 ( V_28 ) & V_153 ) ) {
if ( F_222 ( V_54 ) ) {
if ( ( V_54 -> V_127 == V_136 ) &&
( V_54 -> V_129 == 0x20 ) && ( V_54 -> V_130 == 0 ) ) {
V_20 -> V_285 = 0 ;
goto V_297;
}
}
}
if( F_221 ( V_28 ) ) {
if ( F_23 ( V_33 [ 0 ] == 0x86 && V_33 [ 1 ] == 0x0b &&
( V_282 == 6 || V_282 == 8 ) ) ) {
V_294 = 0 ;
V_243 -> V_159 = 13 ;
V_243 -> V_287 = 0 ;
V_243 -> V_288 = 0 ;
V_243 -> V_289 = 0 ;
V_243 -> V_290 = 0 ;
} else if( V_285 ) {
V_243 -> V_159 = V_33 [ 0 ] * 256 + V_33 [ 1 ] + 2 ;
V_243 -> V_287 = V_33 [ 2 ] ;
V_243 -> V_288 = V_33 [ 3 ] ;
V_243 -> V_289 = V_33 [ 4 ] & 0x01 ;
V_243 -> V_290 = V_33 [ 6 ] * 256
+ V_33 [ 7 ] ;
} else {
V_243 -> V_159 = V_33 [ 0 ] + 1 ;
V_243 -> V_287 = V_33 [ 1 ] ;
V_243 -> V_288 = V_33 [ 2 ] ;
V_243 -> V_290 = V_33 [ 3 ] ;
}
V_243 -> V_294 = V_294 ;
} else if ( ( F_223 ( V_28 ) == V_300 ) &&
F_222 ( V_54 ) &&
V_54 -> V_127 == V_133 && V_295 ) {
V_295 -- ;
goto V_297;
}
return V_28 ;
}
int
F_224 ( struct V_7 * V_20 , int V_36 , int V_37 ,
struct V_53 * V_301 )
{
char V_2 [] = {
V_302 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_53 * V_54 ;
int V_28 ;
if ( ! V_301 )
V_54 = F_26 ( sizeof( * V_54 ) , V_247 ) ;
else
V_54 = V_301 ;
do {
V_28 = F_219 ( V_20 , V_2 , V_176 , NULL , 0 , V_54 ,
V_36 , V_37 , NULL ) ;
if ( V_20 -> V_134 && F_222 ( V_54 ) &&
V_54 -> V_127 == V_133 )
V_20 -> V_135 = 1 ;
} while ( F_222 ( V_54 ) &&
V_54 -> V_127 == V_133 && -- V_37 );
if ( ! V_301 )
F_28 ( V_54 ) ;
return V_28 ;
}
int
F_225 ( struct V_7 * V_20 , enum V_303 V_304 )
{
enum V_303 V_305 = V_20 -> V_179 ;
if ( V_304 == V_305 )
return 0 ;
switch ( V_304 ) {
case V_306 :
switch ( V_305 ) {
case V_186 :
break;
default:
goto V_307;
}
break;
case V_180 :
switch ( V_305 ) {
case V_306 :
case V_181 :
case V_182 :
case V_187 :
case V_185 :
break;
default:
goto V_307;
}
break;
case V_187 :
switch ( V_305 ) {
case V_180 :
case V_181 :
case V_182 :
break;
default:
goto V_307;
}
break;
case V_181 :
case V_182 :
switch ( V_305 ) {
case V_306 :
case V_180 :
case V_187 :
case V_185 :
break;
default:
goto V_307;
}
break;
case V_185 :
switch ( V_305 ) {
case V_180 :
case V_186 :
break;
default:
goto V_307;
}
break;
case V_186 :
switch ( V_305 ) {
case V_306 :
break;
default:
goto V_307;
}
break;
case V_308 :
switch ( V_305 ) {
case V_306 :
case V_180 :
case V_187 :
case V_181 :
case V_182 :
case V_185 :
break;
default:
goto V_307;
}
break;
case V_184 :
switch ( V_305 ) {
case V_306 :
case V_180 :
case V_181 :
case V_182 :
case V_308 :
case V_186 :
break;
default:
goto V_307;
}
break;
}
V_20 -> V_179 = V_304 ;
return 0 ;
V_307:
F_226 ( 1 ,
F_124 ( V_183 , V_20 ,
L_20 ,
F_227 ( V_305 ) ,
F_227 ( V_304 ) )
) ;
return - V_286 ;
}
static void F_228 ( struct V_7 * V_20 , struct V_309 * V_310 )
{
int V_311 = 0 ;
char * V_312 [ 3 ] ;
switch ( V_310 -> V_313 ) {
case V_314 :
V_312 [ V_311 ++ ] = L_21 ;
break;
case V_315 :
F_229 ( & V_20 -> V_24 ) ;
V_312 [ V_311 ++ ] = L_22 ;
break;
case V_316 :
V_312 [ V_311 ++ ] = L_23 ;
break;
case V_317 :
V_312 [ V_311 ++ ] = L_24 ;
break;
case V_318 :
V_312 [ V_311 ++ ] = L_25 ;
break;
case V_319 :
V_312 [ V_311 ++ ] = L_26 ;
break;
case V_320 :
V_312 [ V_311 ++ ] = L_27 ;
break;
default:
break;
}
V_312 [ V_311 ++ ] = NULL ;
F_230 ( & V_20 -> V_24 . V_321 , V_322 , V_312 ) ;
}
void F_231 ( struct V_79 * V_80 )
{
struct V_7 * V_20 ;
enum V_323 V_313 ;
F_47 ( V_324 ) ;
V_20 = F_59 ( V_80 , struct V_7 , V_325 ) ;
for ( V_313 = V_326 ; V_313 <= V_327 ; V_313 ++ )
if ( F_232 ( V_313 , V_20 -> V_328 ) )
F_233 ( V_20 , V_313 , V_247 ) ;
while ( 1 ) {
struct V_309 * V_310 ;
struct V_329 * V_330 , * V_69 ;
unsigned long V_26 ;
F_11 ( & V_20 -> V_95 , V_26 ) ;
F_48 ( & V_20 -> V_324 , & V_324 ) ;
F_14 ( & V_20 -> V_95 , V_26 ) ;
if ( F_49 ( & V_324 ) )
break;
F_234 (this, tmp, &event_list) {
V_310 = F_50 ( V_330 , struct V_309 , V_331 ) ;
F_235 ( & V_310 -> V_331 ) ;
F_228 ( V_20 , V_310 ) ;
F_28 ( V_310 ) ;
}
}
}
void F_236 ( struct V_7 * V_20 , struct V_309 * V_310 )
{
unsigned long V_26 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_11 ( & V_20 -> V_95 , V_26 ) ;
F_138 ( & V_310 -> V_331 , & V_20 -> V_324 ) ;
F_237 ( & V_20 -> V_325 ) ;
F_14 ( & V_20 -> V_95 , V_26 ) ;
}
struct V_309 * F_238 ( enum V_323 V_313 ,
T_4 V_332 )
{
struct V_309 * V_310 = F_26 ( sizeof( struct V_309 ) , V_332 ) ;
if ( ! V_310 )
return NULL ;
V_310 -> V_313 = V_313 ;
F_146 ( & V_310 -> V_331 ) ;
switch ( V_313 ) {
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
default:
break;
}
return V_310 ;
}
void F_233 ( struct V_7 * V_20 ,
enum V_323 V_313 , T_4 V_332 )
{
struct V_309 * V_310 = F_238 ( V_313 , V_332 ) ;
if ( ! V_310 ) {
F_124 ( V_183 , V_20 , L_28 ,
V_313 ) ;
return;
}
F_236 ( V_20 , V_310 ) ;
}
int
F_239 ( struct V_7 * V_20 )
{
int V_333 = F_225 ( V_20 , V_187 ) ;
if ( V_333 )
return V_333 ;
F_56 ( V_20 -> V_21 ) ;
while ( F_43 ( & V_20 -> V_67 ) ) {
F_240 ( 200 ) ;
F_56 ( V_20 -> V_21 ) ;
}
return 0 ;
}
void F_241 ( struct V_7 * V_20 )
{
if ( V_20 -> V_179 != V_187 ||
F_225 ( V_20 , V_180 ) )
return;
F_56 ( V_20 -> V_21 ) ;
}
static void
F_242 ( struct V_7 * V_20 , void * V_243 )
{
F_239 ( V_20 ) ;
}
void
F_243 ( struct V_8 * V_9 )
{
F_244 ( V_9 , NULL , F_242 ) ;
}
static void
F_245 ( struct V_7 * V_20 , void * V_243 )
{
F_241 ( V_20 ) ;
}
void
F_246 ( struct V_8 * V_9 )
{
F_244 ( V_9 , NULL , F_245 ) ;
}
int
F_247 ( struct V_7 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
int V_333 = 0 ;
V_333 = F_225 ( V_20 , V_185 ) ;
if ( V_333 ) {
V_333 = F_225 ( V_20 , V_186 ) ;
if ( V_333 )
return V_333 ;
}
if ( V_22 -> V_29 ) {
F_248 ( V_22 ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_249 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
int
F_250 ( struct V_7 * V_20 ,
enum V_303 V_334 )
{
struct V_21 * V_22 = V_20 -> V_21 ;
unsigned long V_26 ;
if ( ( V_20 -> V_179 == V_185 ) ||
( V_20 -> V_179 == V_182 ) )
V_20 -> V_179 = V_334 ;
else if ( V_20 -> V_179 == V_186 ) {
if ( V_334 == V_182 ||
V_334 == V_181 )
V_20 -> V_179 = V_334 ;
else
V_20 -> V_179 = V_306 ;
} else if ( V_20 -> V_179 != V_308 &&
V_20 -> V_179 != V_181 )
return - V_286 ;
if ( V_22 -> V_29 ) {
F_57 ( V_22 , false ) ;
} else {
F_11 ( V_22 -> V_30 , V_26 ) ;
F_251 ( V_22 ) ;
F_14 ( V_22 -> V_30 , V_26 ) ;
}
return 0 ;
}
static void
F_252 ( struct V_7 * V_20 , void * V_243 )
{
F_247 ( V_20 ) ;
}
static int
F_253 ( struct V_6 * V_257 , void * V_243 )
{
if ( F_254 ( V_257 ) )
F_244 ( F_255 ( V_257 ) , NULL ,
F_252 ) ;
return 0 ;
}
void
F_256 ( struct V_6 * V_257 )
{
if ( F_254 ( V_257 ) )
F_244 ( F_255 ( V_257 ) , NULL ,
F_252 ) ;
else
F_257 ( V_257 , NULL , F_253 ) ;
}
static void
F_258 ( struct V_7 * V_20 , void * V_243 )
{
F_250 ( V_20 , * (enum V_303 * ) V_243 ) ;
}
static int
F_259 ( struct V_6 * V_257 , void * V_243 )
{
if ( F_254 ( V_257 ) )
F_244 ( F_255 ( V_257 ) , V_243 ,
F_258 ) ;
return 0 ;
}
void
F_260 ( struct V_6 * V_257 , enum V_303 V_334 )
{
if ( F_254 ( V_257 ) )
F_244 ( F_255 ( V_257 ) , & V_334 ,
F_258 ) ;
else
F_257 ( V_257 , & V_334 , F_259 ) ;
}
void * F_261 ( struct V_225 * V_157 , int V_335 ,
T_5 * V_336 , T_5 * V_126 )
{
int V_337 ;
T_5 V_338 = 0 , V_339 = 0 ;
struct V_225 * V_226 ;
struct V_340 * V_340 ;
F_262 ( ! F_263 () ) ;
F_264 (sgl, sg, sg_count, i) {
V_339 = V_338 ;
V_338 += V_226 -> V_159 ;
if ( V_338 > * V_336 )
break;
}
if ( F_23 ( V_337 == V_335 ) ) {
F_162 ( V_183 L_29
L_30 ,
V_215 , V_338 , * V_336 , V_335 ) ;
F_262 ( 1 ) ;
return NULL ;
}
* V_336 = * V_336 - V_339 + V_226 -> V_336 ;
V_340 = F_265 ( F_266 ( V_226 ) , ( * V_336 >> V_256 ) ) ;
* V_336 &= ~ V_341 ;
V_338 = V_342 - * V_336 ;
if ( * V_126 > V_338 )
* V_126 = V_338 ;
return F_267 ( V_340 ) ;
}
void F_268 ( void * V_343 )
{
F_269 ( V_343 ) ;
}
void F_270 ( struct V_7 * V_20 )
{
F_143 ( & V_20 -> V_344 ) ;
}
void F_271 ( struct V_7 * V_20 )
{
if ( F_111 ( F_43 ( & V_20 -> V_344 ) <= 0 ) )
return;
F_32 ( & V_20 -> V_344 ) ;
}
int F_272 ( struct V_7 * V_20 , char * V_345 , T_5 V_346 )
{
T_6 V_347 = 0xff ;
T_6 V_348 = 0 ;
unsigned char * V_349 , * V_350 ;
unsigned char T_7 * V_351 ;
int V_352 = - V_286 ;
F_273 () ;
V_351 = F_274 ( V_20 -> V_351 ) ;
if ( ! V_351 ) {
F_275 () ;
return - V_353 ;
}
if ( V_346 < 21 ) {
F_275 () ;
return - V_286 ;
}
memset ( V_345 , 0 , V_346 ) ;
V_349 = V_351 + 4 ;
while ( V_349 < V_351 + V_20 -> V_354 ) {
if ( ( V_349 [ 1 ] & 0x30 ) != 0x00 )
goto V_355;
switch ( V_349 [ 1 ] & 0xf ) {
case 0x1 :
if ( V_348 > V_349 [ 3 ] )
break;
if ( V_347 > 0x01 && V_347 != 0xff )
break;
V_348 = V_349 [ 3 ] ;
if ( V_348 + 4 > V_346 )
V_348 = V_346 - 4 ;
V_350 = V_349 + 4 ;
V_347 = V_349 [ 1 ] & 0xf ;
V_352 = snprintf ( V_345 , V_346 , L_31 ,
V_348 , V_350 ) ;
break;
case 0x2 :
if ( V_348 > V_349 [ 3 ] )
break;
if ( V_347 == 0x3 &&
V_348 == V_349 [ 3 ] )
break;
V_348 = V_349 [ 3 ] ;
V_350 = V_349 + 4 ;
V_347 = V_349 [ 1 ] & 0xf ;
switch ( V_348 ) {
case 8 :
V_352 = snprintf ( V_345 , V_346 ,
L_32 ,
V_350 ) ;
break;
case 12 :
V_352 = snprintf ( V_345 , V_346 ,
L_33 ,
V_350 ) ;
break;
case 16 :
V_352 = snprintf ( V_345 , V_346 ,
L_34 ,
V_350 ) ;
break;
default:
V_348 = 0 ;
break;
}
break;
case 0x3 :
if ( V_348 > V_349 [ 3 ] )
break;
V_348 = V_349 [ 3 ] ;
V_350 = V_349 + 4 ;
V_347 = V_349 [ 1 ] & 0xf ;
switch ( V_348 ) {
case 8 :
V_352 = snprintf ( V_345 , V_346 ,
L_35 ,
V_350 ) ;
break;
case 16 :
V_352 = snprintf ( V_345 , V_346 ,
L_36 ,
V_350 ) ;
break;
default:
V_348 = 0 ;
break;
}
break;
case 0x8 :
if ( V_348 + 4 > V_349 [ 3 ] )
break;
if ( V_348 && V_349 [ 3 ] > V_346 )
break;
V_348 = V_352 = V_349 [ 3 ] ;
V_350 = V_349 + 4 ;
V_347 = V_349 [ 1 ] & 0xf ;
if ( V_348 >= V_346 )
V_348 = V_346 - 1 ;
memcpy ( V_345 , V_350 , V_348 ) ;
if ( V_348 != V_352 )
V_348 = 6 ;
break;
default:
break;
}
V_355:
V_349 += V_349 [ 3 ] + 4 ;
}
F_275 () ;
return V_352 ;
}
int F_276 ( struct V_7 * V_20 , int * V_356 )
{
unsigned char * V_349 ;
unsigned char T_7 * V_351 ;
int V_357 = - V_358 , V_359 = - 1 ;
F_273 () ;
V_351 = F_274 ( V_20 -> V_351 ) ;
if ( ! V_351 ) {
F_275 () ;
return - V_353 ;
}
V_349 = V_20 -> V_351 + 4 ;
while ( V_349 < V_20 -> V_351 + V_20 -> V_354 ) {
switch ( V_349 [ 1 ] & 0xf ) {
case 0x4 :
V_359 = F_277 ( & V_349 [ 6 ] ) ;
break;
case 0x5 :
V_357 = F_277 ( & V_349 [ 6 ] ) ;
break;
default:
break;
}
V_349 += V_349 [ 3 ] + 4 ;
}
F_275 () ;
if ( V_357 >= 0 && V_356 && V_359 != - 1 )
* V_356 = V_359 ;
return V_357 ;
}
