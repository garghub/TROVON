static inline struct V_1 *
F_1 ( bool V_2 )
{
return V_2 ? V_3 : V_4 ;
}
static void F_2 ( bool V_2 ,
unsigned char * V_5 )
{
F_3 ( F_1 ( V_2 ) ,
V_5 ) ;
}
static unsigned char * F_4 ( bool V_2 ,
T_1 V_6 , int V_7 )
{
return F_5 ( F_1 ( V_2 ) ,
V_6 , V_7 ) ;
}
int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_10 ;
int V_11 = 0 ;
V_10 = F_1 ( V_9 -> V_2 ) ;
if ( V_10 )
return 0 ;
F_7 ( & V_12 ) ;
if ( V_9 -> V_2 ) {
V_3 =
F_8 ( L_1 ,
V_13 , 0 ,
V_14 | V_15 , NULL ) ;
if ( ! V_3 )
V_11 = - V_16 ;
} else {
V_4 =
F_8 ( L_2 ,
V_13 , 0 , V_14 , NULL ) ;
if ( ! V_4 )
V_11 = - V_16 ;
}
F_9 ( & V_12 ) ;
return V_11 ;
}
static void
F_10 ( struct V_17 * V_18 , int V_19 )
{
struct V_8 * V_20 = V_18 -> V_21 -> V_20 ;
struct V_22 * V_21 = V_18 -> V_21 ;
struct V_23 * V_24 = V_23 ( V_21 ) ;
switch ( V_19 ) {
case V_25 :
F_11 ( & V_20 -> V_26 , V_20 -> V_27 ) ;
break;
case V_28 :
case V_29 :
F_11 ( & V_21 -> V_30 ,
V_21 -> V_31 ) ;
break;
case V_32 :
F_11 ( & V_24 -> V_33 ,
V_24 -> V_34 ) ;
break;
}
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
if ( V_18 -> V_36 -> V_37 & V_38 ) {
V_18 -> V_36 -> V_37 &= ~ V_38 ;
F_13 ( V_18 ) ;
} else {
F_14 ( true ) ;
}
F_15 ( V_18 -> V_36 , true ) ;
F_16 ( & V_35 -> V_39 ) ;
}
static void F_17 ( struct V_17 * V_18 , int V_19 , int V_40 )
{
struct V_22 * V_21 = V_18 -> V_21 ;
struct V_41 * V_42 = V_21 -> V_41 ;
unsigned long V_43 ;
F_18 ( 1 , F_19 ( V_44 , V_18 ,
L_3 , V_18 ) ) ;
F_10 ( V_18 , V_19 ) ;
if ( V_40 )
F_20 ( V_21 ) ;
V_18 -> V_45 = 0 ;
if ( V_42 -> V_46 ) {
F_12 ( V_18 ) ;
return;
}
F_21 ( V_42 -> V_47 , V_43 ) ;
F_22 ( V_42 , V_18 -> V_36 ) ;
F_23 ( & V_21 -> V_48 ) ;
F_24 ( V_42 -> V_47 , V_43 ) ;
}
void F_25 ( struct V_17 * V_18 , int V_19 )
{
F_17 ( V_18 , V_19 , 1 ) ;
}
int F_26 ( struct V_22 * V_35 , const unsigned char * V_18 ,
int V_49 , void * V_50 , unsigned V_51 ,
unsigned char * V_52 , struct V_53 * V_54 ,
int V_55 , int V_56 , T_2 V_43 , T_3 V_37 ,
int * V_57 )
{
struct V_36 * V_58 ;
struct V_59 * V_60 ;
int V_11 = V_61 << 24 ;
V_58 = F_27 ( V_35 -> V_41 ,
V_49 == V_62 ?
V_63 : V_64 , V_65 ) ;
if ( F_28 ( V_58 ) )
return V_11 ;
V_60 = F_29 ( V_58 ) ;
if ( V_51 && F_30 ( V_35 -> V_41 , V_58 ,
V_50 , V_51 , V_65 ) )
goto V_66;
V_60 -> V_67 = F_31 ( V_18 [ 0 ] ) ;
memcpy ( V_60 -> V_18 , V_18 , V_60 -> V_67 ) ;
V_60 -> V_56 = V_56 ;
V_58 -> V_55 = V_55 ;
V_58 -> V_68 |= V_43 ;
V_58 -> V_37 |= V_37 | V_69 | V_70 ;
F_32 ( V_58 -> V_42 , NULL , V_58 , 1 ) ;
if ( F_33 ( V_60 -> V_71 > 0 && V_60 -> V_71 <= V_51 ) )
memset ( V_50 + ( V_51 - V_60 -> V_71 ) , 0 , V_60 -> V_71 ) ;
if ( V_57 )
* V_57 = V_60 -> V_71 ;
if ( V_52 && V_60 -> V_72 )
memcpy ( V_52 , V_60 -> V_52 , V_13 ) ;
if ( V_54 )
F_34 ( V_60 -> V_52 , V_60 -> V_72 , V_54 ) ;
V_11 = V_60 -> V_45 ;
V_66:
F_35 ( V_58 ) ;
return V_11 ;
}
static void F_36 ( struct V_17 * V_18 )
{
V_18 -> V_73 = 0 ;
F_37 ( V_18 , 0 ) ;
memset ( V_18 -> V_5 , 0 , V_13 ) ;
if ( V_18 -> V_67 == 0 )
V_18 -> V_67 = F_38 ( V_18 -> V_74 ) ;
}
void F_20 ( struct V_22 * V_35 )
{
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned long V_43 ;
F_39 ( & V_9 -> V_75 ) ;
if ( V_24 -> V_76 > 0 )
F_39 ( & V_24 -> V_77 ) ;
if ( F_33 ( F_40 ( V_9 ) &&
( V_9 -> V_78 || V_9 -> V_79 ) ) ) {
F_21 ( V_9 -> V_80 , V_43 ) ;
F_41 ( V_9 ) ;
F_24 ( V_9 -> V_80 , V_43 ) ;
}
F_39 ( & V_35 -> V_81 ) ;
}
static void F_42 ( struct V_41 * V_42 )
{
if ( V_42 -> V_46 )
F_43 ( V_42 ) ;
else
F_44 ( V_42 ) ;
}
static void F_45 ( struct V_22 * V_82 )
{
struct V_8 * V_9 = V_82 -> V_20 ;
struct V_22 * V_35 , * V_83 ;
struct V_23 * V_24 = V_23 ( V_82 ) ;
unsigned long V_43 ;
F_21 ( V_9 -> V_80 , V_43 ) ;
V_24 -> V_84 = NULL ;
F_24 ( V_9 -> V_80 , V_43 ) ;
F_42 ( V_82 -> V_41 ) ;
F_21 ( V_9 -> V_80 , V_43 ) ;
if ( V_24 -> V_84 )
goto V_66;
F_46 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_35 == V_82 )
continue;
if ( F_47 ( V_35 ) )
continue;
F_24 ( V_9 -> V_80 , V_43 ) ;
F_42 ( V_35 -> V_41 ) ;
F_21 ( V_9 -> V_80 , V_43 ) ;
F_48 ( V_35 ) ;
}
V_66:
F_24 ( V_9 -> V_80 , V_43 ) ;
}
static inline bool F_49 ( struct V_22 * V_35 )
{
if ( F_50 ( & V_35 -> V_81 ) >= V_35 -> V_85 )
return true ;
if ( F_50 ( & V_35 -> V_30 ) > 0 )
return true ;
return false ;
}
static inline bool F_51 ( struct V_23 * V_24 )
{
if ( V_24 -> V_76 > 0 ) {
if ( F_50 ( & V_24 -> V_77 ) >= V_24 -> V_76 )
return true ;
if ( F_50 ( & V_24 -> V_33 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_52 ( struct V_8 * V_9 )
{
if ( V_9 -> V_76 > 0 &&
F_50 ( & V_9 -> V_75 ) >= V_9 -> V_76 )
return true ;
if ( F_50 ( & V_9 -> V_26 ) > 0 )
return true ;
if ( V_9 -> V_86 )
return true ;
return false ;
}
static void F_53 ( struct V_8 * V_9 )
{
F_54 ( V_87 ) ;
struct V_22 * V_35 ;
unsigned long V_43 ;
F_21 ( V_9 -> V_80 , V_43 ) ;
F_55 ( & V_9 -> V_87 , & V_87 ) ;
while ( ! F_56 ( & V_87 ) ) {
struct V_41 * V_88 ;
if ( F_52 ( V_9 ) )
break;
V_35 = F_57 ( V_87 . V_89 ,
struct V_22 , V_90 ) ;
F_58 ( & V_35 -> V_90 ) ;
if ( F_51 ( V_23 ( V_35 ) ) ) {
F_59 ( & V_35 -> V_90 ,
& V_9 -> V_87 ) ;
continue;
}
V_88 = V_35 -> V_41 ;
if ( ! F_60 ( V_88 ) )
continue;
F_24 ( V_9 -> V_80 , V_43 ) ;
F_42 ( V_88 ) ;
F_61 ( V_88 ) ;
F_21 ( V_9 -> V_80 , V_43 ) ;
}
F_62 ( & V_87 , & V_9 -> V_87 ) ;
F_24 ( V_9 -> V_80 , V_43 ) ;
}
static void F_63 ( struct V_41 * V_42 )
{
struct V_22 * V_35 = V_42 -> V_91 ;
if ( V_23 ( V_35 ) -> V_92 )
F_45 ( V_35 ) ;
if ( ! F_56 ( & V_35 -> V_20 -> V_87 ) )
F_53 ( V_35 -> V_20 ) ;
if ( V_42 -> V_46 )
F_64 ( V_42 , false ) ;
else
F_44 ( V_42 ) ;
}
void F_65 ( struct V_93 * V_94 )
{
struct V_22 * V_35 ;
struct V_41 * V_42 ;
V_35 = F_66 ( V_94 , struct V_22 , V_48 ) ;
V_42 = V_35 -> V_41 ;
F_63 ( V_42 ) ;
}
static void F_67 ( struct V_41 * V_42 , struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_58 = V_18 -> V_36 ;
unsigned long V_43 ;
F_21 ( V_42 -> V_47 , V_43 ) ;
F_68 ( V_58 ) ;
V_58 -> V_95 = NULL ;
F_69 ( V_18 ) ;
F_22 ( V_42 , V_58 ) ;
F_24 ( V_42 -> V_47 , V_43 ) ;
F_63 ( V_42 ) ;
F_16 ( & V_35 -> V_39 ) ;
}
void F_70 ( struct V_8 * V_9 )
{
struct V_22 * V_35 ;
F_71 (sdev, shost)
F_63 ( V_35 -> V_41 ) ;
}
static void F_72 ( struct V_17 * V_18 )
{
if ( ! F_73 ( V_18 -> V_36 ) ) {
struct V_96 * V_97 = F_74 ( V_18 ) ;
if ( V_97 -> V_98 )
V_97 -> V_98 ( V_18 ) ;
}
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_99 * V_100 ;
if ( V_18 -> V_100 . V_101 . V_102 )
F_76 ( & V_18 -> V_100 . V_101 , true ) ;
if ( V_18 -> V_36 -> V_103 ) {
V_100 = V_18 -> V_36 -> V_103 -> V_95 ;
if ( V_100 )
F_76 ( & V_100 -> V_101 , true ) ;
}
if ( F_77 ( V_18 ) )
F_76 ( & V_18 -> V_104 -> V_101 , true ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
F_75 ( V_18 ) ;
F_72 ( V_18 ) ;
F_78 ( V_18 ) ;
}
static void F_79 ( struct V_17 * V_18 )
{
if ( V_18 -> V_100 . V_101 . V_102 )
F_76 ( & V_18 -> V_100 . V_101 , false ) ;
memset ( & V_18 -> V_100 , 0 , sizeof( V_18 -> V_100 ) ) ;
if ( F_77 ( V_18 ) )
F_76 ( & V_18 -> V_104 -> V_101 , false ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
struct V_99 * V_105 = V_18 -> V_36 -> V_103 -> V_95 ;
F_76 ( & V_105 -> V_101 , false ) ;
F_3 ( V_106 , V_105 ) ;
V_18 -> V_36 -> V_103 -> V_95 = NULL ;
}
static bool F_81 ( struct V_36 * V_58 , T_4 error ,
unsigned int V_107 , unsigned int V_108 )
{
struct V_17 * V_18 = F_82 ( V_58 ) ;
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_41 * V_42 = V_35 -> V_41 ;
if ( F_83 ( V_58 , error , V_107 ) )
return true ;
if ( F_33 ( V_108 ) &&
F_83 ( V_58 -> V_103 , error , V_108 ) )
return true ;
if ( F_84 ( V_42 ) )
F_85 ( V_58 -> V_109 ) ;
if ( ! F_86 ( V_58 ) ) {
F_14 ( ! ( V_18 -> V_43 & V_110 ) ) ;
V_18 -> V_43 &= ~ V_110 ;
}
if ( V_58 -> V_111 ) {
F_13 ( V_18 ) ;
F_87 ( V_58 , error ) ;
if ( V_23 ( V_35 ) -> V_92 ||
! F_56 ( & V_35 -> V_20 -> V_87 ) )
F_23 ( & V_35 -> V_48 ) ;
else
F_64 ( V_42 , true ) ;
} else {
unsigned long V_43 ;
if ( V_108 )
F_80 ( V_18 ) ;
F_79 ( V_18 ) ;
F_69 ( V_18 ) ;
F_21 ( V_42 -> V_47 , V_43 ) ;
F_88 ( V_58 , error ) ;
F_24 ( V_42 -> V_47 , V_43 ) ;
F_63 ( V_42 ) ;
}
F_16 ( & V_35 -> V_39 ) ;
return false ;
}
static T_4 F_89 ( struct V_17 * V_18 ,
int V_45 )
{
switch ( F_90 ( V_45 ) ) {
case V_112 :
return V_113 ;
case V_114 :
F_91 ( V_18 , V_115 ) ;
return V_116 ;
case V_117 :
return V_118 ;
case V_119 :
F_91 ( V_18 , V_115 ) ;
return V_120 ;
case V_121 :
F_91 ( V_18 , V_115 ) ;
return V_122 ;
default:
return V_123 ;
}
}
void F_92 ( struct V_17 * V_18 , unsigned int V_124 )
{
int V_45 = V_18 -> V_45 ;
struct V_41 * V_42 = V_18 -> V_21 -> V_41 ;
struct V_36 * V_58 = V_18 -> V_36 ;
T_4 error = V_125 ;
struct V_53 V_54 ;
bool V_126 = false ;
int V_127 = 0 , V_128 = 0 ;
enum { V_129 , V_130 , V_131 ,
V_132 } V_133 ;
unsigned long V_134 = ( V_18 -> V_135 + 1 ) * V_58 -> V_55 ;
if ( V_45 ) {
V_126 = F_93 ( V_18 , & V_54 ) ;
if ( V_126 )
V_127 = F_94 ( & V_54 ) ;
}
if ( F_73 ( V_58 ) ) {
if ( V_45 ) {
if ( V_126 ) {
F_29 ( V_58 ) -> V_72 =
F_95 ( 8 + V_18 -> V_5 [ 7 ] ,
V_13 ) ;
}
if ( ! V_127 )
error = F_89 ( V_18 , V_45 ) ;
}
F_29 ( V_58 ) -> V_45 = V_18 -> V_45 ;
F_29 ( V_58 ) -> V_71 = F_96 ( V_18 ) ;
if ( F_97 ( V_18 ) ) {
F_29 ( V_58 -> V_103 ) -> V_71 = F_98 ( V_18 ) -> V_57 ;
if ( F_81 ( V_58 , V_125 , F_99 ( V_58 ) ,
F_99 ( V_58 -> V_103 ) ) )
F_100 () ;
return;
}
} else if ( F_99 ( V_58 ) == 0 && V_45 && ! V_127 ) {
error = F_89 ( V_18 , V_45 ) ;
}
F_101 ( F_102 ( V_58 ) ) ;
F_103 ( 1 , F_19 ( V_44 , V_18 ,
L_4 ,
F_104 ( V_58 ) , V_124 ) ) ;
if ( V_126 && ( V_54 . V_136 == V_137 ) ) {
if ( ( V_54 . V_138 == 0x0 ) && ( V_54 . V_139 == 0x1d ) )
;
else if ( ! ( V_58 -> V_37 & V_69 ) )
F_105 ( V_18 ) ;
V_45 = 0 ;
error = V_125 ;
}
if ( ! ( F_99 ( V_58 ) == 0 && error ) &&
! F_81 ( V_58 , error , V_124 , 0 ) )
return;
if ( error && F_106 ( V_18 ) ) {
if ( F_81 ( V_58 , error , F_99 ( V_58 ) , 0 ) )
F_100 () ;
return;
}
if ( V_45 == 0 )
goto V_140;
error = F_89 ( V_18 , V_45 ) ;
if ( F_90 ( V_45 ) == V_141 ) {
V_133 = V_131 ;
} else if ( V_126 && ! V_127 ) {
switch ( V_54 . V_136 ) {
case V_142 :
if ( V_18 -> V_21 -> V_143 ) {
V_18 -> V_21 -> V_144 = 1 ;
V_133 = V_129 ;
} else {
V_133 = V_131 ;
}
break;
case V_145 :
if ( ( V_18 -> V_21 -> V_146 &&
V_54 . V_138 == 0x20 && V_54 . V_139 == 0x00 ) &&
( V_18 -> V_74 [ 0 ] == V_147 ||
V_18 -> V_74 [ 0 ] == V_148 ) ) {
V_18 -> V_21 -> V_146 = 0 ;
V_133 = V_130 ;
} else if ( V_54 . V_138 == 0x10 ) {
V_133 = V_129 ;
error = V_149 ;
} else if ( V_54 . V_138 == 0x20 || V_54 . V_138 == 0x24 ) {
V_133 = V_129 ;
error = V_116 ;
} else
V_133 = V_129 ;
break;
case V_150 :
V_133 = V_129 ;
if ( V_54 . V_138 == 0x10 )
error = V_149 ;
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
V_133 = V_132 ;
break;
default:
V_133 = V_129 ;
break;
}
} else
V_133 = V_129 ;
break;
case V_152 :
V_133 = V_129 ;
break;
default:
V_133 = V_129 ;
break;
}
} else
V_133 = V_129 ;
if ( V_133 != V_129 &&
F_107 ( V_18 -> V_153 + V_134 , V_154 ) )
V_133 = V_129 ;
switch ( V_133 ) {
case V_129 :
if ( ! ( V_58 -> V_37 & V_69 ) ) {
static F_108 ( V_155 ,
V_156 ,
V_157 ) ;
if ( F_33 ( V_158 ) )
V_128 = F_109 ( V_159 ,
V_160 ) ;
if ( ! V_128 && F_110 ( & V_155 ) ) {
F_111 ( V_18 , NULL , V_161 ) ;
if ( F_112 ( V_45 ) & V_162 )
F_105 ( V_18 ) ;
F_113 ( V_18 ) ;
}
}
if ( ! F_81 ( V_58 , error , F_114 ( V_58 ) , 0 ) )
return;
case V_130 :
V_140:
if ( V_42 -> V_46 ) {
F_12 ( V_18 ) ;
} else {
F_79 ( V_18 ) ;
F_67 ( V_42 , V_18 ) ;
}
break;
case V_131 :
F_17 ( V_18 , V_29 , 0 ) ;
break;
case V_132 :
F_17 ( V_18 , V_28 , 0 ) ;
break;
}
}
static int F_115 ( struct V_36 * V_58 , struct V_99 * V_100 )
{
int V_163 ;
if ( F_33 ( F_116 ( & V_100 -> V_101 ,
F_117 ( V_58 ) , V_100 -> V_101 . V_164 ) ) )
return V_165 ;
V_163 = F_118 ( V_58 -> V_42 , V_58 , V_100 -> V_101 . V_164 ) ;
F_101 ( V_163 > V_100 -> V_101 . V_102 ) ;
V_100 -> V_101 . V_102 = V_163 ;
V_100 -> V_166 = F_119 ( V_58 ) ;
return V_167 ;
}
int F_120 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_60 = V_18 -> V_36 ;
bool V_168 = ( V_60 -> V_111 != NULL ) ;
int error = V_169 ;
if ( F_14 ( ! F_117 ( V_60 ) ) )
goto V_170;
error = F_115 ( V_60 , & V_18 -> V_100 ) ;
if ( error )
goto V_170;
if ( F_102 ( V_60 ) ) {
if ( ! V_60 -> V_42 -> V_46 ) {
struct V_99 * V_105 =
F_121 ( V_106 , V_171 ) ;
if ( ! V_105 ) {
error = V_165 ;
goto V_170;
}
V_60 -> V_103 -> V_95 = V_105 ;
}
error = F_115 ( V_60 -> V_103 , V_60 -> V_103 -> V_95 ) ;
if ( error )
goto V_170;
}
if ( F_122 ( V_60 ) ) {
struct V_99 * V_104 = V_18 -> V_104 ;
int V_172 , V_163 ;
if ( V_104 == NULL ) {
F_14 ( 1 ) ;
error = V_169 ;
goto V_170;
}
V_172 = F_123 ( V_60 -> V_42 , V_60 -> V_173 ) ;
if ( F_116 ( & V_104 -> V_101 , V_172 ,
V_104 -> V_101 . V_164 ) ) {
error = V_165 ;
goto V_170;
}
V_163 = F_124 ( V_60 -> V_42 , V_60 -> V_173 ,
V_104 -> V_101 . V_164 ) ;
F_101 ( F_33 ( V_163 > V_172 ) ) ;
F_101 ( F_33 ( V_163 > F_125 ( V_60 -> V_42 ) ) ) ;
V_18 -> V_104 = V_104 ;
V_18 -> V_104 -> V_101 . V_102 = V_163 ;
}
return V_167 ;
V_170:
if ( V_168 ) {
F_75 ( V_18 ) ;
} else {
F_79 ( V_18 ) ;
V_18 -> V_36 -> V_95 = NULL ;
F_69 ( V_18 ) ;
F_16 ( & V_35 -> V_39 ) ;
}
return error ;
}
void F_126 ( struct V_36 * V_60 )
{
struct V_17 * V_18 = F_82 ( V_60 ) ;
F_127 ( & V_18 -> V_58 ) ;
V_18 -> V_153 = V_154 ;
V_18 -> V_56 = 0 ;
}
void F_128 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_8 * V_9 = V_35 -> V_20 ;
unsigned long V_43 ;
if ( V_9 -> V_174 ) {
F_21 ( & V_35 -> V_175 , V_43 ) ;
F_129 ( & V_18 -> V_176 , & V_35 -> V_177 ) ;
F_24 ( & V_35 -> V_175 , V_43 ) ;
}
}
void F_78 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_8 * V_9 = V_35 -> V_20 ;
unsigned long V_43 ;
if ( V_9 -> V_174 ) {
F_21 ( & V_35 -> V_175 , V_43 ) ;
F_101 ( F_56 ( & V_18 -> V_176 ) ) ;
F_58 ( & V_18 -> V_176 ) ;
F_24 ( & V_35 -> V_175 , V_43 ) ;
}
}
void F_130 ( struct V_22 * V_178 , struct V_17 * V_18 )
{
void * V_179 = V_18 -> V_5 ;
void * V_180 = V_18 -> V_104 ;
struct V_36 * V_60 = F_131 ( V_18 ) ;
unsigned int V_43 = V_18 -> V_43 & V_181 ;
unsigned long V_153 ;
int V_56 ;
if ( ! F_86 ( V_60 ) && ! ( V_43 & V_110 ) ) {
V_43 |= V_110 ;
F_126 ( V_60 ) ;
}
V_153 = V_18 -> V_153 ;
V_56 = V_18 -> V_56 ;
memset ( ( char * ) V_18 + sizeof( V_18 -> V_58 ) , 0 ,
sizeof( * V_18 ) - sizeof( V_18 -> V_58 ) + V_178 -> V_20 -> V_182 -> V_183 ) ;
V_18 -> V_21 = V_178 ;
V_18 -> V_5 = V_179 ;
V_18 -> V_104 = V_180 ;
V_18 -> V_43 = V_43 ;
F_132 ( & V_18 -> V_184 , V_185 ) ;
V_18 -> V_153 = V_153 ;
V_18 -> V_56 = V_56 ;
F_128 ( V_18 ) ;
}
static int F_133 ( struct V_22 * V_35 , struct V_36 * V_58 )
{
struct V_17 * V_18 = F_82 ( V_58 ) ;
if ( V_58 -> V_173 ) {
int V_11 = F_120 ( V_18 ) ;
if ( F_33 ( V_11 ) )
return V_11 ;
} else {
F_101 ( F_99 ( V_58 ) ) ;
memset ( & V_18 -> V_100 , 0 , sizeof( V_18 -> V_100 ) ) ;
}
V_18 -> V_67 = F_29 ( V_58 ) -> V_67 ;
V_18 -> V_74 = F_29 ( V_58 ) -> V_18 ;
V_18 -> V_186 = F_99 ( V_58 ) ;
V_18 -> V_135 = F_29 ( V_58 ) -> V_56 ;
return V_167 ;
}
static int F_134 ( struct V_22 * V_35 , struct V_36 * V_58 )
{
struct V_17 * V_18 = F_82 ( V_58 ) ;
if ( F_33 ( V_35 -> V_187 && V_35 -> V_187 -> V_188 ) ) {
int V_11 = V_35 -> V_187 -> V_188 ( V_35 , V_58 ) ;
if ( V_11 != V_167 )
return V_11 ;
}
V_18 -> V_74 = F_29 ( V_58 ) -> V_18 = F_29 ( V_58 ) -> V_189 ;
memset ( V_18 -> V_74 , 0 , V_190 ) ;
return F_74 ( V_18 ) -> F_135 ( V_18 ) ;
}
static int F_136 ( struct V_22 * V_35 , struct V_36 * V_58 )
{
struct V_17 * V_18 = F_82 ( V_58 ) ;
if ( ! F_99 ( V_58 ) )
V_18 -> V_191 = V_192 ;
else if ( F_137 ( V_58 ) == V_193 )
V_18 -> V_191 = V_62 ;
else
V_18 -> V_191 = V_194 ;
if ( F_86 ( V_58 ) )
return F_133 ( V_35 , V_58 ) ;
else
return F_134 ( V_35 , V_58 ) ;
}
static int
F_138 ( struct V_22 * V_35 , struct V_36 * V_58 )
{
int V_11 = V_167 ;
if ( F_33 ( V_35 -> V_195 != V_196 ) ) {
switch ( V_35 -> V_195 ) {
case V_197 :
case V_198 :
F_139 ( V_199 , V_35 ,
L_5 ) ;
V_11 = V_169 ;
break;
case V_200 :
F_139 ( V_199 , V_35 ,
L_6 ) ;
V_11 = V_169 ;
break;
case V_201 :
case V_202 :
V_11 = V_165 ;
break;
case V_203 :
if ( ! ( V_58 -> V_37 & V_70 ) )
V_11 = V_165 ;
break;
default:
if ( ! ( V_58 -> V_37 & V_70 ) )
V_11 = V_169 ;
break;
}
}
return V_11 ;
}
static int
F_140 ( struct V_41 * V_42 , struct V_36 * V_58 , int V_11 )
{
struct V_22 * V_35 = V_42 -> V_91 ;
switch ( V_11 ) {
case V_169 :
case V_204 :
F_29 ( V_58 ) -> V_45 = V_205 << 16 ;
if ( V_58 -> V_95 ) {
struct V_17 * V_18 = V_58 -> V_95 ;
F_79 ( V_18 ) ;
F_69 ( V_18 ) ;
F_16 ( & V_35 -> V_39 ) ;
V_58 -> V_95 = NULL ;
}
break;
case V_165 :
if ( F_50 ( & V_35 -> V_81 ) == 0 )
F_141 ( V_42 , V_206 ) ;
break;
default:
V_58 -> V_37 |= V_38 ;
}
return V_11 ;
}
static int F_142 ( struct V_41 * V_42 , struct V_36 * V_58 )
{
struct V_22 * V_35 = V_42 -> V_91 ;
struct V_17 * V_18 = F_82 ( V_58 ) ;
int V_11 ;
V_11 = F_138 ( V_35 , V_58 ) ;
if ( V_11 != V_167 )
goto V_66;
if ( ! V_58 -> V_95 ) {
if ( F_33 ( ! F_143 ( & V_35 -> V_39 ) ) ) {
V_11 = V_165 ;
goto V_66;
}
F_130 ( V_35 , V_18 ) ;
V_58 -> V_95 = V_18 ;
}
V_18 -> V_207 = V_58 -> V_207 ;
V_18 -> V_36 = V_58 ;
V_18 -> V_208 = V_209 ;
V_11 = F_136 ( V_35 , V_58 ) ;
V_66:
return F_140 ( V_42 , V_58 , V_11 ) ;
}
static void F_144 ( struct V_41 * V_42 , struct V_36 * V_58 )
{
F_72 ( F_82 ( V_58 ) ) ;
}
static inline int F_145 ( struct V_41 * V_42 ,
struct V_22 * V_35 )
{
unsigned int V_210 ;
V_210 = F_146 ( & V_35 -> V_81 ) - 1 ;
if ( F_50 ( & V_35 -> V_30 ) ) {
if ( V_210 )
goto V_211;
if ( F_147 ( & V_35 -> V_30 ) > 0 ) {
if ( ! V_42 -> V_46 )
F_141 ( V_42 , V_206 ) ;
goto V_211;
}
F_18 ( 3 , F_139 ( V_44 , V_35 ,
L_7 ) ) ;
}
if ( V_210 >= V_35 -> V_85 )
goto V_211;
return 1 ;
V_211:
F_39 ( & V_35 -> V_81 ) ;
return 0 ;
}
static inline int F_148 ( struct V_8 * V_9 ,
struct V_22 * V_35 )
{
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned int V_210 ;
if ( V_24 -> V_92 ) {
F_149 ( V_9 -> V_80 ) ;
if ( V_24 -> V_84 &&
V_24 -> V_84 != V_35 ) {
F_150 ( V_9 -> V_80 ) ;
return 0 ;
}
V_24 -> V_84 = V_35 ;
F_150 ( V_9 -> V_80 ) ;
}
if ( V_24 -> V_76 <= 0 )
return 1 ;
V_210 = F_146 ( & V_24 -> V_77 ) - 1 ;
if ( F_50 ( & V_24 -> V_33 ) > 0 ) {
if ( V_210 )
goto V_212;
if ( F_147 ( & V_24 -> V_33 ) > 0 )
goto V_211;
F_18 ( 3 , F_151 ( V_44 , V_24 ,
L_8 ) ) ;
}
if ( V_210 >= V_24 -> V_76 )
goto V_212;
return 1 ;
V_212:
F_149 ( V_9 -> V_80 ) ;
F_59 ( & V_35 -> V_90 , & V_9 -> V_87 ) ;
F_150 ( V_9 -> V_80 ) ;
V_211:
if ( V_24 -> V_76 > 0 )
F_39 ( & V_24 -> V_77 ) ;
return 0 ;
}
static inline int F_152 ( struct V_41 * V_42 ,
struct V_8 * V_9 ,
struct V_22 * V_35 )
{
unsigned int V_210 ;
if ( F_40 ( V_9 ) )
return 0 ;
V_210 = F_146 ( & V_9 -> V_75 ) - 1 ;
if ( F_50 ( & V_9 -> V_26 ) > 0 ) {
if ( V_210 )
goto V_212;
if ( F_147 ( & V_9 -> V_26 ) > 0 )
goto V_211;
F_18 ( 3 ,
F_153 ( V_44 , V_9 ,
L_9 ) ) ;
}
if ( V_9 -> V_76 > 0 && V_210 >= V_9 -> V_76 )
goto V_212;
if ( V_9 -> V_86 )
goto V_212;
if ( ! F_56 ( & V_35 -> V_90 ) ) {
F_149 ( V_9 -> V_80 ) ;
if ( ! F_56 ( & V_35 -> V_90 ) )
F_58 ( & V_35 -> V_90 ) ;
F_150 ( V_9 -> V_80 ) ;
}
return 1 ;
V_212:
F_149 ( V_9 -> V_80 ) ;
if ( F_56 ( & V_35 -> V_90 ) )
F_129 ( & V_35 -> V_90 , & V_9 -> V_87 ) ;
F_150 ( V_9 -> V_80 ) ;
V_211:
F_39 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_154 ( struct V_41 * V_42 )
{
struct V_22 * V_35 = V_42 -> V_91 ;
struct V_8 * V_9 ;
if ( F_155 ( V_42 ) )
return 0 ;
V_9 = V_35 -> V_20 ;
if ( F_40 ( V_9 ) || F_49 ( V_35 ) )
return 1 ;
return 0 ;
}
static void F_156 ( struct V_36 * V_58 , struct V_41 * V_42 )
{
struct V_17 * V_18 = F_82 ( V_58 ) ;
struct V_22 * V_35 ;
struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_157 ( V_58 ) ;
F_19 ( V_44 , V_18 , L_10 ) ;
V_35 = V_18 -> V_21 ;
V_24 = V_23 ( V_35 ) ;
V_9 = V_35 -> V_20 ;
F_36 ( V_18 ) ;
V_18 -> V_45 = V_205 << 16 ;
F_158 ( & V_18 -> V_21 -> V_213 ) ;
F_158 ( & V_35 -> V_81 ) ;
F_158 ( & V_9 -> V_75 ) ;
if ( V_24 -> V_76 > 0 )
F_158 ( & V_24 -> V_77 ) ;
F_159 ( V_58 ) ;
}
static void F_160 ( struct V_36 * V_60 )
{
struct V_17 * V_18 = F_82 ( V_60 ) ;
unsigned long V_134 = ( V_18 -> V_135 + 1 ) * V_60 -> V_55 ;
int V_214 ;
F_161 ( & V_18 -> V_215 ) ;
F_158 ( & V_18 -> V_21 -> V_216 ) ;
if ( V_18 -> V_45 )
F_158 ( & V_18 -> V_21 -> V_217 ) ;
V_214 = F_162 ( V_18 ) ;
if ( V_214 != V_218 &&
F_107 ( V_18 -> V_153 + V_134 , V_154 ) ) {
F_139 ( V_199 , V_18 -> V_21 ,
L_11 ,
V_134 / V_219 ) ;
V_214 = V_218 ;
}
F_163 ( V_18 , V_214 ) ;
switch ( V_214 ) {
case V_218 :
F_164 ( V_18 ) ;
break;
case V_220 :
F_25 ( V_18 , V_29 ) ;
break;
case V_221 :
F_25 ( V_18 , V_28 ) ;
break;
default:
F_165 ( V_18 ) ;
break;
}
}
static int F_166 ( struct V_17 * V_18 )
{
struct V_8 * V_20 = V_18 -> V_21 -> V_20 ;
int V_222 = 0 ;
F_158 ( & V_18 -> V_21 -> V_213 ) ;
if ( F_33 ( V_18 -> V_21 -> V_195 == V_200 ) ) {
V_18 -> V_45 = V_205 << 16 ;
goto V_223;
}
if ( F_33 ( F_167 ( V_18 -> V_21 ) ) ) {
F_18 ( 3 , F_19 ( V_44 , V_18 ,
L_12 ) ) ;
return V_28 ;
}
if ( V_18 -> V_21 -> V_224 )
V_18 -> V_74 [ 1 ] = ( V_18 -> V_74 [ 1 ] & 0x1f ) |
( V_18 -> V_21 -> V_225 << 5 & 0xe0 ) ;
F_168 ( V_18 ) ;
if ( V_18 -> V_67 > V_18 -> V_21 -> V_20 -> V_226 ) {
F_18 ( 3 , F_19 ( V_44 , V_18 ,
L_13
L_14 ,
V_18 -> V_67 , V_18 -> V_21 -> V_20 -> V_226 ) ) ;
V_18 -> V_45 = ( V_227 << 16 ) ;
goto V_223;
}
if ( F_33 ( V_20 -> V_228 == V_229 ) ) {
V_18 -> V_45 = ( V_205 << 16 ) ;
goto V_223;
}
F_169 ( V_18 ) ;
V_222 = V_20 -> V_182 -> V_230 ( V_20 , V_18 ) ;
if ( V_222 ) {
F_170 ( V_18 , V_222 ) ;
if ( V_222 != V_28 &&
V_222 != V_32 )
V_222 = V_25 ;
F_18 ( 3 , F_19 ( V_44 , V_18 ,
L_15 ) ) ;
}
return V_222 ;
V_223:
V_18 -> V_231 ( V_18 ) ;
return 0 ;
}
static void V_231 ( struct V_17 * V_18 )
{
F_171 ( V_18 ) ;
F_159 ( V_18 -> V_36 ) ;
}
static void F_172 ( struct V_41 * V_42 )
__releases( V_42 -> V_47 )
__acquires( V_42 -> V_47 )
{
struct V_22 * V_35 = V_42 -> V_91 ;
struct V_8 * V_9 ;
struct V_17 * V_18 ;
struct V_36 * V_58 ;
V_9 = V_35 -> V_20 ;
for (; ; ) {
int V_222 ;
V_58 = F_173 ( V_42 ) ;
if ( ! V_58 )
break;
if ( F_33 ( ! F_174 ( V_35 ) ) ) {
F_139 ( V_199 , V_35 ,
L_5 ) ;
F_156 ( V_58 , V_42 ) ;
continue;
}
if ( ! F_145 ( V_42 , V_35 ) )
break;
if ( ! ( F_175 ( V_42 ) && ! F_176 ( V_42 , V_58 ) ) )
F_157 ( V_58 ) ;
F_150 ( V_42 -> V_47 ) ;
V_18 = F_82 ( V_58 ) ;
if ( V_18 != V_58 -> V_95 ) {
F_177 ( V_232 L_16
L_17
L_18 ,
V_233 ) ;
F_178 ( V_58 , L_19 ) ;
F_100 () ;
}
if ( F_175 ( V_42 ) && ! ( V_58 -> V_37 & V_234 ) ) {
F_149 ( V_9 -> V_80 ) ;
if ( F_56 ( & V_35 -> V_90 ) )
F_129 ( & V_35 -> V_90 ,
& V_9 -> V_87 ) ;
F_150 ( V_9 -> V_80 ) ;
goto V_235;
}
if ( ! F_148 ( V_9 , V_35 ) )
goto V_235;
if ( ! F_152 ( V_42 , V_9 , V_35 ) )
goto V_236;
if ( V_35 -> V_237 )
V_18 -> V_43 |= V_238 ;
else
V_18 -> V_43 &= ~ V_238 ;
F_36 ( V_18 ) ;
V_18 -> V_231 = V_231 ;
V_222 = F_166 ( V_18 ) ;
if ( V_222 ) {
F_25 ( V_18 , V_222 ) ;
F_149 ( V_42 -> V_47 ) ;
goto V_239;
}
F_149 ( V_42 -> V_47 ) ;
}
return;
V_236:
if ( V_23 ( V_35 ) -> V_76 > 0 )
F_39 ( & V_23 ( V_35 ) -> V_77 ) ;
V_235:
F_149 ( V_42 -> V_47 ) ;
F_22 ( V_42 , V_58 ) ;
F_39 ( & V_35 -> V_81 ) ;
V_239:
if ( ! F_50 ( & V_35 -> V_81 ) && ! F_167 ( V_35 ) )
F_141 ( V_42 , V_206 ) ;
}
static inline T_4 F_179 ( int V_11 )
{
switch ( V_11 ) {
case V_167 :
return V_125 ;
case V_165 :
return V_240 ;
default:
return V_123 ;
}
}
static unsigned int F_180 ( struct V_8 * V_9 )
{
return F_181 (unsigned int, shost->sg_tablesize, SG_CHUNK_SIZE) *
sizeof( struct V_241 ) ;
}
static int F_182 ( struct V_36 * V_58 )
{
struct V_17 * V_18 = F_82 ( V_58 ) ;
struct V_22 * V_35 = V_58 -> V_42 -> V_91 ;
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_241 * V_242 ;
F_130 ( V_35 , V_18 ) ;
V_58 -> V_95 = V_18 ;
V_18 -> V_36 = V_58 ;
V_18 -> V_207 = V_58 -> V_207 ;
V_18 -> V_208 = V_209 ;
V_242 = ( void * ) V_18 + sizeof( struct V_17 ) + V_9 -> V_182 -> V_183 ;
V_18 -> V_100 . V_101 . V_164 = V_242 ;
if ( F_183 ( V_9 ) ) {
memset ( V_18 -> V_104 , 0 , sizeof( struct V_99 ) ) ;
V_18 -> V_104 -> V_101 . V_164 =
(struct V_241 * ) ( V_18 -> V_104 + 1 ) ;
}
if ( F_102 ( V_58 ) ) {
struct V_36 * V_103 = V_58 -> V_103 ;
struct V_99 * V_105 = F_82 ( V_103 ) ;
memset ( V_105 , 0 , sizeof( struct V_99 ) ) ;
V_105 -> V_101 . V_164 =
(struct V_241 * ) ( V_105 + 1 ) ;
V_103 -> V_95 = V_105 ;
}
F_184 ( V_58 ) ;
return F_136 ( V_35 , V_58 ) ;
}
static void F_185 ( struct V_17 * V_18 )
{
F_171 ( V_18 ) ;
F_186 ( V_18 -> V_36 ) ;
}
static T_4 F_187 ( struct V_243 * V_244 ,
const struct V_245 * V_246 )
{
struct V_36 * V_58 = V_246 -> V_60 ;
struct V_41 * V_42 = V_58 -> V_42 ;
struct V_22 * V_35 = V_42 -> V_91 ;
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_17 * V_18 = F_82 ( V_58 ) ;
T_4 V_11 ;
int V_19 ;
V_11 = F_179 ( F_138 ( V_35 , V_58 ) ) ;
if ( V_11 != V_125 )
goto V_66;
V_11 = V_240 ;
if ( ! F_143 ( & V_35 -> V_39 ) )
goto V_66;
if ( ! F_145 ( V_42 , V_35 ) )
goto V_247;
if ( ! F_148 ( V_9 , V_35 ) )
goto V_248;
if ( ! F_152 ( V_42 , V_9 , V_35 ) )
goto V_249;
if ( ! ( V_58 -> V_37 & V_38 ) ) {
V_11 = F_179 ( F_182 ( V_58 ) ) ;
if ( V_11 != V_125 )
goto V_250;
V_58 -> V_37 |= V_38 ;
} else {
F_184 ( V_58 ) ;
}
if ( V_35 -> V_237 )
V_18 -> V_43 |= V_238 ;
else
V_18 -> V_43 &= ~ V_238 ;
F_36 ( V_18 ) ;
V_18 -> V_231 = F_185 ;
V_19 = F_166 ( V_18 ) ;
if ( V_19 ) {
F_10 ( V_18 , V_19 ) ;
V_11 = V_240 ;
goto V_250;
}
return V_125 ;
V_250:
F_39 ( & V_9 -> V_75 ) ;
V_249:
if ( V_23 ( V_35 ) -> V_76 > 0 )
F_39 ( & V_23 ( V_35 ) -> V_77 ) ;
V_248:
F_39 ( & V_35 -> V_81 ) ;
V_247:
F_16 ( & V_35 -> V_39 ) ;
V_66:
switch ( V_11 ) {
case V_125 :
break;
case V_240 :
if ( F_50 ( & V_35 -> V_81 ) == 0 &&
! F_167 ( V_35 ) )
F_188 ( V_244 , V_206 ) ;
break;
default:
if ( V_58 -> V_37 & V_38 )
F_13 ( V_18 ) ;
break;
}
return V_11 ;
}
static enum V_251 F_189 ( struct V_36 * V_58 ,
bool V_252 )
{
if ( V_252 )
return V_253 ;
return F_190 ( V_58 ) ;
}
static int F_191 ( struct V_254 * V_255 , struct V_36 * V_60 ,
unsigned int V_256 , unsigned int V_7 )
{
struct V_8 * V_9 = V_255 -> V_257 ;
const bool V_2 = V_9 -> V_2 ;
struct V_17 * V_18 = F_82 ( V_60 ) ;
struct V_241 * V_242 ;
if ( V_2 )
V_18 -> V_43 |= V_258 ;
V_18 -> V_5 = F_4 ( V_2 ,
V_259 , V_7 ) ;
if ( ! V_18 -> V_5 )
return - V_16 ;
V_18 -> V_58 . V_52 = V_18 -> V_5 ;
if ( F_183 ( V_9 ) ) {
V_242 = ( void * ) V_18 + sizeof( struct V_17 ) +
V_9 -> V_182 -> V_183 ;
V_18 -> V_104 = ( void * ) V_242 + F_180 ( V_9 ) ;
}
return 0 ;
}
static void F_192 ( struct V_254 * V_255 , struct V_36 * V_60 ,
unsigned int V_256 )
{
struct V_17 * V_18 = F_82 ( V_60 ) ;
F_2 ( V_18 -> V_43 & V_258 ,
V_18 -> V_5 ) ;
}
static int F_193 ( struct V_254 * V_255 )
{
struct V_8 * V_9 = F_66 ( V_255 , struct V_8 , V_260 ) ;
if ( V_9 -> V_182 -> V_261 )
return V_9 -> V_182 -> V_261 ( V_9 ) ;
return F_194 ( V_255 ) ;
}
static T_2 F_195 ( struct V_8 * V_9 )
{
struct V_21 * V_262 ;
T_2 V_263 = 0xffffffff ;
if ( V_9 -> V_2 )
return V_264 ;
if ( ! V_265 )
return V_266 ;
V_262 = F_196 ( V_9 ) ;
if ( V_262 && V_262 -> V_267 )
V_263 = ( T_2 ) F_197 ( V_262 ) << V_268 ;
return V_263 ;
}
void F_198 ( struct V_8 * V_9 , struct V_41 * V_42 )
{
struct V_21 * V_178 = V_9 -> V_269 ;
F_199 ( V_270 , V_42 ) ;
F_200 ( V_42 , F_181 (unsigned short, shost->sg_tablesize,
SG_MAX_SEGMENTS) ) ;
if ( F_201 ( V_9 ) ) {
V_9 -> V_271 =
F_202 ( V_9 -> V_271 ,
( unsigned short ) V_272 ) ;
F_101 ( V_9 -> V_271 < V_9 -> V_273 ) ;
F_203 ( V_42 , V_9 -> V_271 ) ;
}
F_204 ( V_42 , V_9 -> V_274 ) ;
F_205 ( V_42 , F_195 ( V_9 ) ) ;
F_206 ( V_42 , V_9 -> V_275 ) ;
F_207 ( V_178 , V_9 -> V_275 ) ;
F_208 ( V_42 , F_209 ( V_178 ) ) ;
if ( ! V_9 -> V_276 )
V_42 -> V_277 . V_278 = 0 ;
F_210 ( V_42 , 0x03 ) ;
}
static int F_211 ( struct V_41 * V_42 , struct V_36 * V_60 ,
T_1 V_279 )
{
struct V_8 * V_9 = V_42 -> V_280 ;
const bool V_2 = V_9 -> V_2 ;
struct V_17 * V_18 = F_82 ( V_60 ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
if ( V_2 )
V_18 -> V_43 |= V_258 ;
V_18 -> V_5 = F_4 ( V_2 , V_279 ,
V_281 ) ;
if ( ! V_18 -> V_5 )
goto V_282;
V_18 -> V_58 . V_52 = V_18 -> V_5 ;
if ( F_183 ( V_9 ) >= V_283 ) {
V_18 -> V_104 = F_121 ( V_106 , V_279 ) ;
if ( ! V_18 -> V_104 )
goto V_284;
}
return 0 ;
V_284:
F_2 ( V_2 , V_18 -> V_5 ) ;
V_282:
return - V_16 ;
}
static void F_212 ( struct V_41 * V_42 , struct V_36 * V_60 )
{
struct V_17 * V_18 = F_82 ( V_60 ) ;
if ( V_18 -> V_104 )
F_3 ( V_106 , V_18 -> V_104 ) ;
F_2 ( V_18 -> V_43 & V_258 ,
V_18 -> V_5 ) ;
}
struct V_41 * F_213 ( struct V_22 * V_35 )
{
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_41 * V_42 ;
V_42 = F_214 ( V_259 , V_281 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_183 = sizeof( struct V_17 ) + V_9 -> V_182 -> V_183 ;
V_42 -> V_280 = V_9 ;
V_42 -> V_285 = F_172 ;
V_42 -> V_286 = F_211 ;
V_42 -> V_287 = F_212 ;
V_42 -> V_288 = F_126 ;
if ( F_215 ( V_42 ) < 0 ) {
F_216 ( V_42 ) ;
return NULL ;
}
F_198 ( V_9 , V_42 ) ;
F_217 ( V_42 , F_142 ) ;
F_218 ( V_42 , F_144 ) ;
F_219 ( V_42 , F_160 ) ;
F_220 ( V_42 , F_190 ) ;
F_221 ( V_42 , F_154 ) ;
return V_42 ;
}
struct V_41 * F_222 ( struct V_22 * V_35 )
{
V_35 -> V_41 = F_223 ( & V_35 -> V_20 -> V_260 ) ;
if ( F_28 ( V_35 -> V_41 ) )
return NULL ;
V_35 -> V_41 -> V_91 = V_35 ;
F_198 ( V_35 -> V_20 , V_35 -> V_41 ) ;
return V_35 -> V_41 ;
}
int F_224 ( struct V_8 * V_9 )
{
unsigned int V_183 , V_289 ;
V_289 = F_180 ( V_9 ) ;
V_183 = sizeof( struct V_17 ) + V_9 -> V_182 -> V_183 + V_289 ;
if ( F_183 ( V_9 ) )
V_183 += sizeof( struct V_99 ) + V_289 ;
memset ( & V_9 -> V_260 , 0 , sizeof( V_9 -> V_260 ) ) ;
V_9 -> V_260 . V_290 = & V_291 ;
V_9 -> V_260 . V_292 = V_9 -> V_292 ? : 1 ;
V_9 -> V_260 . V_85 = V_9 -> V_76 ;
V_9 -> V_260 . V_183 = V_183 ;
V_9 -> V_260 . V_7 = V_281 ;
V_9 -> V_260 . V_43 = V_293 | V_294 ;
V_9 -> V_260 . V_43 |=
F_225 ( V_9 -> V_182 -> V_295 ) ;
V_9 -> V_260 . V_257 = V_9 ;
return F_226 ( & V_9 -> V_260 ) ;
}
void F_227 ( struct V_8 * V_9 )
{
F_228 ( & V_9 -> V_260 ) ;
}
struct V_22 * F_229 ( struct V_41 * V_42 )
{
struct V_22 * V_35 = NULL ;
if ( V_42 -> V_46 ) {
if ( V_42 -> V_46 == & V_291 )
V_35 = V_42 -> V_91 ;
} else if ( V_42 -> V_285 == F_172 )
V_35 = V_42 -> V_91 ;
if ( ! V_35 || ! F_143 ( & V_35 -> V_39 ) )
V_35 = NULL ;
return V_35 ;
}
void F_230 ( struct V_8 * V_9 )
{
V_9 -> V_86 = 1 ;
}
void F_231 ( struct V_8 * V_9 )
{
V_9 -> V_86 = 0 ;
F_70 ( V_9 ) ;
}
int T_5 F_232 ( void )
{
V_106 = F_8 ( L_20 ,
sizeof( struct V_99 ) ,
0 , 0 , NULL ) ;
if ( ! V_106 ) {
F_177 ( V_199 L_21 ) ;
return - V_16 ;
}
return 0 ;
}
void F_233 ( void )
{
F_234 ( V_4 ) ;
F_234 ( V_3 ) ;
F_234 ( V_106 ) ;
}
int
F_235 ( struct V_22 * V_35 , int V_296 , int V_297 , int V_298 ,
unsigned char * V_50 , int V_299 , int V_55 , int V_56 ,
struct V_300 * V_301 , struct V_53 * V_54 )
{
unsigned char V_18 [ 10 ] ;
unsigned char * V_302 ;
int V_11 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 1 ] = ( V_296 ? 0x10 : 0 ) | ( V_297 ? 0x01 : 0 ) ;
if ( V_35 -> V_303 ) {
if ( V_299 > 65535 )
return - V_304 ;
V_302 = F_236 ( 8 + V_299 , V_259 ) ;
if ( ! V_302 )
return - V_16 ;
memcpy ( V_302 + 8 , V_50 , V_299 ) ;
V_299 += 8 ;
V_302 [ 0 ] = 0 ;
V_302 [ 1 ] = 0 ;
V_302 [ 2 ] = V_301 -> V_305 ;
V_302 [ 3 ] = V_301 -> V_306 ;
V_302 [ 4 ] = V_301 -> V_307 ? 0x01 : 0 ;
V_302 [ 5 ] = 0 ;
V_302 [ 6 ] = V_301 -> V_308 >> 8 ;
V_302 [ 7 ] = V_301 -> V_308 ;
V_18 [ 0 ] = V_309 ;
V_18 [ 7 ] = V_299 >> 8 ;
V_18 [ 8 ] = V_299 ;
} else {
if ( V_299 > 255 || V_301 -> V_308 > 255 ||
V_301 -> V_307 )
return - V_304 ;
V_302 = F_236 ( 4 + V_299 , V_259 ) ;
if ( ! V_302 )
return - V_16 ;
memcpy ( V_302 + 4 , V_50 , V_299 ) ;
V_299 += 4 ;
V_302 [ 0 ] = 0 ;
V_302 [ 1 ] = V_301 -> V_305 ;
V_302 [ 2 ] = V_301 -> V_306 ;
V_302 [ 3 ] = V_301 -> V_308 ;
V_18 [ 0 ] = V_310 ;
V_18 [ 4 ] = V_299 ;
}
V_11 = F_237 ( V_35 , V_18 , V_62 , V_302 , V_299 ,
V_54 , V_55 , V_56 , NULL ) ;
F_238 ( V_302 ) ;
return V_11 ;
}
int
F_239 ( struct V_22 * V_35 , int V_311 , int V_298 ,
unsigned char * V_50 , int V_299 , int V_55 , int V_56 ,
struct V_300 * V_301 , struct V_53 * V_54 )
{
unsigned char V_18 [ 12 ] ;
int V_303 ;
int V_312 ;
int V_45 , V_313 = V_56 ;
struct V_53 V_314 ;
memset ( V_301 , 0 , sizeof( * V_301 ) ) ;
memset ( & V_18 [ 0 ] , 0 , 12 ) ;
V_18 [ 1 ] = V_311 & 0x18 ;
V_18 [ 2 ] = V_298 ;
if ( ! V_54 )
V_54 = & V_314 ;
V_315:
V_303 = V_35 -> V_303 ;
if ( V_303 ) {
if ( V_299 < 8 )
V_299 = 8 ;
V_18 [ 0 ] = V_316 ;
V_18 [ 8 ] = V_299 ;
V_312 = 8 ;
} else {
if ( V_299 < 4 )
V_299 = 4 ;
V_18 [ 0 ] = V_317 ;
V_18 [ 4 ] = V_299 ;
V_312 = 4 ;
}
memset ( V_50 , 0 , V_299 ) ;
V_45 = F_237 ( V_35 , V_18 , V_194 , V_50 , V_299 ,
V_54 , V_55 , V_56 , NULL ) ;
if ( V_303 && ! F_240 ( V_45 ) &&
( F_112 ( V_45 ) & V_162 ) ) {
if ( F_241 ( V_54 ) ) {
if ( ( V_54 -> V_136 == V_145 ) &&
( V_54 -> V_138 == 0x20 ) && ( V_54 -> V_139 == 0 ) ) {
V_35 -> V_303 = 0 ;
goto V_315;
}
}
}
if( F_240 ( V_45 ) ) {
if ( F_33 ( V_50 [ 0 ] == 0x86 && V_50 [ 1 ] == 0x0b &&
( V_298 == 6 || V_298 == 8 ) ) ) {
V_312 = 0 ;
V_301 -> V_166 = 13 ;
V_301 -> V_305 = 0 ;
V_301 -> V_306 = 0 ;
V_301 -> V_307 = 0 ;
V_301 -> V_308 = 0 ;
} else if( V_303 ) {
V_301 -> V_166 = V_50 [ 0 ] * 256 + V_50 [ 1 ] + 2 ;
V_301 -> V_305 = V_50 [ 2 ] ;
V_301 -> V_306 = V_50 [ 3 ] ;
V_301 -> V_307 = V_50 [ 4 ] & 0x01 ;
V_301 -> V_308 = V_50 [ 6 ] * 256
+ V_50 [ 7 ] ;
} else {
V_301 -> V_166 = V_50 [ 0 ] + 1 ;
V_301 -> V_305 = V_50 [ 1 ] ;
V_301 -> V_306 = V_50 [ 2 ] ;
V_301 -> V_308 = V_50 [ 3 ] ;
}
V_301 -> V_312 = V_312 ;
} else if ( ( F_242 ( V_45 ) == V_318 ) &&
F_241 ( V_54 ) &&
V_54 -> V_136 == V_142 && V_313 ) {
V_313 -- ;
goto V_315;
}
return V_45 ;
}
int
F_243 ( struct V_22 * V_35 , int V_55 , int V_56 ,
struct V_53 * V_54 )
{
char V_18 [] = {
V_319 , 0 , 0 , 0 , 0 , 0 ,
} ;
int V_45 ;
do {
V_45 = F_237 ( V_35 , V_18 , V_192 , NULL , 0 , V_54 ,
V_55 , V_56 , NULL ) ;
if ( V_35 -> V_143 && F_241 ( V_54 ) &&
V_54 -> V_136 == V_142 )
V_35 -> V_144 = 1 ;
} while ( F_241 ( V_54 ) &&
V_54 -> V_136 == V_142 && -- V_56 );
return V_45 ;
}
int
F_244 ( struct V_22 * V_35 , enum V_320 V_321 )
{
enum V_320 V_322 = V_35 -> V_195 ;
if ( V_321 == V_322 )
return 0 ;
switch ( V_321 ) {
case V_323 :
switch ( V_322 ) {
case V_202 :
break;
default:
goto V_324;
}
break;
case V_196 :
switch ( V_322 ) {
case V_323 :
case V_197 :
case V_198 :
case V_203 :
case V_201 :
break;
default:
goto V_324;
}
break;
case V_203 :
switch ( V_322 ) {
case V_196 :
case V_197 :
case V_198 :
break;
default:
goto V_324;
}
break;
case V_197 :
case V_198 :
switch ( V_322 ) {
case V_323 :
case V_196 :
case V_203 :
case V_201 :
break;
default:
goto V_324;
}
break;
case V_201 :
switch ( V_322 ) {
case V_196 :
case V_202 :
break;
default:
goto V_324;
}
break;
case V_202 :
switch ( V_322 ) {
case V_323 :
break;
default:
goto V_324;
}
break;
case V_325 :
switch ( V_322 ) {
case V_323 :
case V_196 :
case V_203 :
case V_197 :
case V_198 :
break;
default:
goto V_324;
}
break;
case V_200 :
switch ( V_322 ) {
case V_323 :
case V_196 :
case V_197 :
case V_198 :
case V_325 :
case V_201 :
case V_202 :
break;
default:
goto V_324;
}
break;
}
V_35 -> V_195 = V_321 ;
return 0 ;
V_324:
F_245 ( 1 ,
F_139 ( V_199 , V_35 ,
L_22 ,
F_246 ( V_322 ) ,
F_246 ( V_321 ) )
) ;
return - V_304 ;
}
static void F_247 ( struct V_22 * V_35 , struct V_326 * V_327 )
{
int V_328 = 0 ;
char * V_329 [ 3 ] ;
switch ( V_327 -> V_330 ) {
case V_331 :
V_329 [ V_328 ++ ] = L_23 ;
break;
case V_332 :
F_248 ( & V_35 -> V_39 ) ;
V_329 [ V_328 ++ ] = L_24 ;
break;
case V_333 :
V_329 [ V_328 ++ ] = L_25 ;
break;
case V_334 :
V_329 [ V_328 ++ ] = L_26 ;
break;
case V_335 :
V_329 [ V_328 ++ ] = L_27 ;
break;
case V_336 :
V_329 [ V_328 ++ ] = L_28 ;
break;
case V_337 :
V_329 [ V_328 ++ ] = L_29 ;
break;
default:
break;
}
V_329 [ V_328 ++ ] = NULL ;
F_249 ( & V_35 -> V_39 . V_338 , V_339 , V_329 ) ;
}
void F_250 ( struct V_93 * V_94 )
{
struct V_22 * V_35 ;
enum V_340 V_330 ;
F_54 ( V_341 ) ;
V_35 = F_66 ( V_94 , struct V_22 , V_342 ) ;
for ( V_330 = V_343 ; V_330 <= V_344 ; V_330 ++ )
if ( F_251 ( V_330 , V_35 -> V_345 ) )
F_252 ( V_35 , V_330 , V_259 ) ;
while ( 1 ) {
struct V_326 * V_327 ;
struct V_346 * V_347 , * V_83 ;
unsigned long V_43 ;
F_21 ( & V_35 -> V_175 , V_43 ) ;
F_55 ( & V_35 -> V_341 , & V_341 ) ;
F_24 ( & V_35 -> V_175 , V_43 ) ;
if ( F_56 ( & V_341 ) )
break;
F_253 (this, tmp, &event_list) {
V_327 = F_57 ( V_347 , struct V_326 , V_348 ) ;
F_254 ( & V_327 -> V_348 ) ;
F_247 ( V_35 , V_327 ) ;
F_238 ( V_327 ) ;
}
}
}
void F_255 ( struct V_22 * V_35 , struct V_326 * V_327 )
{
unsigned long V_43 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_21 ( & V_35 -> V_175 , V_43 ) ;
F_129 ( & V_327 -> V_348 , & V_35 -> V_341 ) ;
F_256 ( & V_35 -> V_342 ) ;
F_24 ( & V_35 -> V_175 , V_43 ) ;
}
struct V_326 * F_257 ( enum V_340 V_330 ,
T_1 V_349 )
{
struct V_326 * V_327 = F_258 ( sizeof( struct V_326 ) , V_349 ) ;
if ( ! V_327 )
return NULL ;
V_327 -> V_330 = V_330 ;
F_161 ( & V_327 -> V_348 ) ;
switch ( V_330 ) {
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
default:
break;
}
return V_327 ;
}
void F_252 ( struct V_22 * V_35 ,
enum V_340 V_330 , T_1 V_349 )
{
struct V_326 * V_327 = F_257 ( V_330 , V_349 ) ;
if ( ! V_327 ) {
F_139 ( V_199 , V_35 , L_30 ,
V_330 ) ;
return;
}
F_255 ( V_35 , V_327 ) ;
}
static int F_259 ( struct V_22 * V_35 )
{
struct V_41 * V_42 = V_35 -> V_41 ;
int V_350 ;
F_14 ( V_35 -> V_20 -> V_351 ) ;
F_149 ( V_42 -> V_47 ) ;
V_350 = V_42 -> V_350 ;
F_150 ( V_42 -> V_47 ) ;
return V_350 ;
}
static void F_260 ( struct V_22 * V_35 )
{
F_14 ( V_35 -> V_20 -> V_351 ) ;
while ( F_259 ( V_35 ) )
F_261 ( 20 ) ;
}
int
F_262 ( struct V_22 * V_35 )
{
int V_352 ;
F_7 ( & V_35 -> V_353 ) ;
V_352 = F_244 ( V_35 , V_203 ) ;
F_9 ( & V_35 -> V_353 ) ;
if ( V_352 )
return V_352 ;
F_63 ( V_35 -> V_41 ) ;
while ( F_50 ( & V_35 -> V_81 ) ) {
F_263 ( 200 ) ;
F_63 ( V_35 -> V_41 ) ;
}
return 0 ;
}
void F_264 ( struct V_22 * V_35 )
{
F_7 ( & V_35 -> V_353 ) ;
if ( V_35 -> V_195 == V_203 &&
F_244 ( V_35 , V_196 ) == 0 )
F_63 ( V_35 -> V_41 ) ;
F_9 ( & V_35 -> V_353 ) ;
}
static void
F_265 ( struct V_22 * V_35 , void * V_301 )
{
F_262 ( V_35 ) ;
}
void
F_266 ( struct V_23 * V_24 )
{
F_267 ( V_24 , NULL , F_265 ) ;
}
static void
F_268 ( struct V_22 * V_35 , void * V_301 )
{
F_264 ( V_35 ) ;
}
void
F_269 ( struct V_23 * V_24 )
{
F_267 ( V_24 , NULL , F_268 ) ;
}
int F_270 ( struct V_22 * V_35 )
{
struct V_41 * V_42 = V_35 -> V_41 ;
unsigned long V_43 ;
int V_352 = 0 ;
V_352 = F_244 ( V_35 , V_201 ) ;
if ( V_352 ) {
V_352 = F_244 ( V_35 , V_202 ) ;
if ( V_352 )
return V_352 ;
}
if ( V_42 -> V_46 ) {
F_271 ( V_42 ) ;
} else {
F_21 ( V_42 -> V_47 , V_43 ) ;
F_272 ( V_42 ) ;
F_24 ( V_42 -> V_47 , V_43 ) ;
}
return 0 ;
}
static int F_273 ( struct V_22 * V_35 )
{
struct V_41 * V_42 = V_35 -> V_41 ;
int V_352 ;
F_7 ( & V_35 -> V_353 ) ;
V_352 = F_270 ( V_35 ) ;
if ( V_352 == 0 ) {
if ( V_42 -> V_46 )
F_274 ( V_42 ) ;
else
F_260 ( V_35 ) ;
}
F_9 ( & V_35 -> V_353 ) ;
return V_352 ;
}
void F_275 ( struct V_22 * V_35 )
{
struct V_41 * V_42 = V_35 -> V_41 ;
unsigned long V_43 ;
if ( V_42 -> V_46 ) {
F_276 ( V_42 ) ;
} else {
F_21 ( V_42 -> V_47 , V_43 ) ;
F_277 ( V_42 ) ;
F_24 ( V_42 -> V_47 , V_43 ) ;
}
}
int F_278 ( struct V_22 * V_35 ,
enum V_320 V_354 )
{
switch ( V_35 -> V_195 ) {
case V_201 :
case V_198 :
V_35 -> V_195 = V_354 ;
break;
case V_202 :
if ( V_354 == V_198 ||
V_354 == V_197 )
V_35 -> V_195 = V_354 ;
else
V_35 -> V_195 = V_323 ;
break;
case V_325 :
case V_197 :
break;
default:
return - V_304 ;
}
F_275 ( V_35 ) ;
return 0 ;
}
static int F_279 ( struct V_22 * V_35 ,
enum V_320 V_354 )
{
int V_11 ;
F_7 ( & V_35 -> V_353 ) ;
V_11 = F_278 ( V_35 , V_354 ) ;
F_9 ( & V_35 -> V_353 ) ;
return V_11 ;
}
static void
F_280 ( struct V_22 * V_35 , void * V_301 )
{
F_273 ( V_35 ) ;
}
static int
F_281 ( struct V_21 * V_178 , void * V_301 )
{
if ( F_282 ( V_178 ) )
F_267 ( F_283 ( V_178 ) , NULL ,
F_280 ) ;
return 0 ;
}
void
F_284 ( struct V_21 * V_178 )
{
if ( F_282 ( V_178 ) )
F_267 ( F_283 ( V_178 ) , NULL ,
F_280 ) ;
else
F_285 ( V_178 , NULL , F_281 ) ;
}
static void
F_286 ( struct V_22 * V_35 , void * V_301 )
{
F_279 ( V_35 , * (enum V_320 * ) V_301 ) ;
}
static int
F_287 ( struct V_21 * V_178 , void * V_301 )
{
if ( F_282 ( V_178 ) )
F_267 ( F_283 ( V_178 ) , V_301 ,
F_286 ) ;
return 0 ;
}
void
F_288 ( struct V_21 * V_178 , enum V_320 V_354 )
{
if ( F_282 ( V_178 ) )
F_267 ( F_283 ( V_178 ) , & V_354 ,
F_286 ) ;
else
F_285 ( V_178 , & V_354 , F_287 ) ;
}
void * F_289 ( struct V_241 * V_164 , int V_355 ,
T_6 * V_356 , T_6 * V_299 )
{
int V_357 ;
T_6 V_358 = 0 , V_359 = 0 ;
struct V_241 * V_242 ;
struct V_360 * V_360 ;
F_290 ( ! F_291 () ) ;
F_292 (sgl, sg, sg_count, i) {
V_359 = V_358 ;
V_358 += V_242 -> V_166 ;
if ( V_358 > * V_356 )
break;
}
if ( F_33 ( V_357 == V_355 ) ) {
F_177 ( V_199 L_31
L_32 ,
V_233 , V_358 , * V_356 , V_355 ) ;
F_290 ( 1 ) ;
return NULL ;
}
* V_356 = * V_356 - V_359 + V_242 -> V_356 ;
V_360 = F_293 ( F_294 ( V_242 ) , ( * V_356 >> V_268 ) ) ;
* V_356 &= ~ V_361 ;
V_358 = V_362 - * V_356 ;
if ( * V_299 > V_358 )
* V_299 = V_358 ;
return F_295 ( V_360 ) ;
}
void F_296 ( void * V_363 )
{
F_297 ( V_363 ) ;
}
void F_298 ( struct V_22 * V_35 )
{
F_158 ( & V_35 -> V_364 ) ;
}
void F_299 ( struct V_22 * V_35 )
{
if ( F_14 ( F_50 ( & V_35 -> V_364 ) <= 0 ) )
return;
F_39 ( & V_35 -> V_364 ) ;
}
int F_300 ( struct V_22 * V_35 , char * V_365 , T_6 V_366 )
{
T_7 V_367 = 0xff ;
T_7 V_368 = 0 ;
const unsigned char * V_369 , * V_370 ;
const struct V_371 * V_372 ;
int V_373 = - V_304 ;
F_301 () ;
V_372 = F_302 ( V_35 -> V_372 ) ;
if ( ! V_372 ) {
F_303 () ;
return - V_374 ;
}
if ( V_366 < 21 ) {
F_303 () ;
return - V_304 ;
}
memset ( V_365 , 0 , V_366 ) ;
V_369 = V_372 -> V_301 + 4 ;
while ( V_369 < V_372 -> V_301 + V_372 -> V_299 ) {
if ( ( V_369 [ 1 ] & 0x30 ) != 0x00 )
goto V_375;
switch ( V_369 [ 1 ] & 0xf ) {
case 0x1 :
if ( V_368 > V_369 [ 3 ] )
break;
if ( V_367 > 0x01 && V_367 != 0xff )
break;
V_368 = V_369 [ 3 ] ;
if ( V_368 + 4 > V_366 )
V_368 = V_366 - 4 ;
V_370 = V_369 + 4 ;
V_367 = V_369 [ 1 ] & 0xf ;
V_373 = snprintf ( V_365 , V_366 , L_33 ,
V_368 , V_370 ) ;
break;
case 0x2 :
if ( V_368 > V_369 [ 3 ] )
break;
if ( V_367 == 0x3 &&
V_368 == V_369 [ 3 ] )
break;
V_368 = V_369 [ 3 ] ;
V_370 = V_369 + 4 ;
V_367 = V_369 [ 1 ] & 0xf ;
switch ( V_368 ) {
case 8 :
V_373 = snprintf ( V_365 , V_366 ,
L_34 ,
V_370 ) ;
break;
case 12 :
V_373 = snprintf ( V_365 , V_366 ,
L_35 ,
V_370 ) ;
break;
case 16 :
V_373 = snprintf ( V_365 , V_366 ,
L_36 ,
V_370 ) ;
break;
default:
V_368 = 0 ;
break;
}
break;
case 0x3 :
if ( V_368 > V_369 [ 3 ] )
break;
V_368 = V_369 [ 3 ] ;
V_370 = V_369 + 4 ;
V_367 = V_369 [ 1 ] & 0xf ;
switch ( V_368 ) {
case 8 :
V_373 = snprintf ( V_365 , V_366 ,
L_37 ,
V_370 ) ;
break;
case 16 :
V_373 = snprintf ( V_365 , V_366 ,
L_38 ,
V_370 ) ;
break;
default:
V_368 = 0 ;
break;
}
break;
case 0x8 :
if ( V_368 + 4 > V_369 [ 3 ] )
break;
if ( V_368 && V_369 [ 3 ] > V_366 )
break;
V_368 = V_373 = V_369 [ 3 ] ;
V_370 = V_369 + 4 ;
V_367 = V_369 [ 1 ] & 0xf ;
if ( V_368 >= V_366 )
V_368 = V_366 - 1 ;
memcpy ( V_365 , V_370 , V_368 ) ;
if ( V_368 != V_373 )
V_368 = 6 ;
break;
default:
break;
}
V_375:
V_369 += V_369 [ 3 ] + 4 ;
}
F_303 () ;
return V_373 ;
}
int F_304 ( struct V_22 * V_35 , int * V_376 )
{
const unsigned char * V_369 ;
const struct V_371 * V_372 ;
int V_377 = - V_378 , V_379 = - 1 ;
F_301 () ;
V_372 = F_302 ( V_35 -> V_372 ) ;
if ( ! V_372 ) {
F_303 () ;
return - V_374 ;
}
V_369 = V_372 -> V_301 + 4 ;
while ( V_369 < V_372 -> V_301 + V_372 -> V_299 ) {
switch ( V_369 [ 1 ] & 0xf ) {
case 0x4 :
V_379 = F_305 ( & V_369 [ 6 ] ) ;
break;
case 0x5 :
V_377 = F_305 ( & V_369 [ 6 ] ) ;
break;
default:
break;
}
V_369 += V_369 [ 3 ] + 4 ;
}
F_303 () ;
if ( V_377 >= 0 && V_376 && V_379 != - 1 )
* V_376 = V_379 ;
return V_377 ;
}
