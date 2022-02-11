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
F_4 ( V_2 -> V_21 , true ) ;
F_5 ( & V_20 -> V_22 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , int V_23 )
{
struct V_7 * V_6 = V_2 -> V_6 ;
struct V_24 * V_25 = V_6 -> V_24 ;
unsigned long V_26 ;
F_7 ( 1 , F_8 ( V_27 , V_2 ,
L_1 , V_2 ) ) ;
F_1 ( V_2 , V_3 ) ;
if ( V_23 )
F_9 ( V_6 ) ;
V_2 -> V_28 = 0 ;
if ( V_25 -> V_29 ) {
F_3 ( V_2 ) ;
return;
}
F_10 ( V_25 -> V_30 , V_26 ) ;
F_11 ( V_25 , V_2 -> V_21 ) ;
F_12 ( & V_6 -> V_31 ) ;
F_13 ( V_25 -> V_30 , V_26 ) ;
}
void F_14 ( struct V_1 * V_2 , int V_3 )
{
F_6 ( V_2 , V_3 , 1 ) ;
}
static int F_15 ( struct V_7 * V_20 , const unsigned char * V_2 ,
int V_32 , void * V_33 , unsigned V_34 ,
unsigned char * V_35 , int V_36 , int V_37 , T_1 V_26 ,
T_2 V_38 , int * V_39 )
{
struct V_21 * V_40 ;
int V_41 = ( V_32 == V_42 ) ;
int V_43 = V_44 << 24 ;
V_40 = F_16 ( V_20 -> V_24 , V_41 , V_45 ) ;
if ( F_17 ( V_40 ) )
return V_43 ;
F_18 ( V_40 ) ;
if ( V_34 && F_19 ( V_20 -> V_24 , V_40 ,
V_33 , V_34 , V_45 ) )
goto V_46;
V_40 -> V_47 = F_20 ( V_2 [ 0 ] ) ;
memcpy ( V_40 -> V_2 , V_2 , V_40 -> V_47 ) ;
V_40 -> V_35 = V_35 ;
V_40 -> V_48 = 0 ;
V_40 -> V_37 = V_37 ;
V_40 -> V_36 = V_36 ;
V_40 -> V_49 |= V_26 ;
V_40 -> V_38 |= V_38 | V_50 | V_51 ;
F_21 ( V_40 -> V_25 , NULL , V_40 , 1 ) ;
if ( F_22 ( V_40 -> V_52 > 0 && V_40 -> V_52 <= V_34 ) )
memset ( V_33 + ( V_34 - V_40 -> V_52 ) , 0 , V_40 -> V_52 ) ;
if ( V_39 )
* V_39 = V_40 -> V_52 ;
V_43 = V_40 -> V_53 ;
V_46:
F_23 ( V_40 ) ;
return V_43 ;
}
int F_24 ( struct V_7 * V_20 , const unsigned char * V_2 ,
int V_32 , void * V_33 , unsigned V_34 ,
unsigned char * V_35 , int V_36 , int V_37 , T_1 V_26 ,
int * V_39 )
{
return F_15 ( V_20 , V_2 , V_32 , V_33 , V_34 , V_35 ,
V_36 , V_37 , V_26 , 0 , V_39 ) ;
}
int F_25 ( struct V_7 * V_20 , const unsigned char * V_2 ,
int V_32 , void * V_33 , unsigned V_34 ,
struct V_54 * V_55 , int V_36 , int V_37 ,
int * V_39 , T_1 V_26 , T_2 V_38 )
{
char * V_35 = NULL ;
int V_28 ;
if ( V_55 ) {
V_35 = F_26 ( V_56 , V_57 ) ;
if ( ! V_35 )
return V_44 << 24 ;
}
V_28 = F_15 ( V_20 , V_2 , V_32 , V_33 , V_34 ,
V_35 , V_36 , V_37 , V_26 , V_38 , V_39 ) ;
if ( V_55 )
F_27 ( V_35 , V_56 , V_55 ) ;
F_28 ( V_35 ) ;
return V_28 ;
}
static void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_58 = 0 ;
F_30 ( V_2 , 0 ) ;
memset ( V_2 -> V_59 , 0 , V_56 ) ;
if ( V_2 -> V_47 == 0 )
V_2 -> V_47 = F_31 ( V_2 -> V_60 ) ;
}
void F_9 ( struct V_7 * V_20 )
{
struct V_4 * V_61 = V_20 -> V_5 ;
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned long V_26 ;
F_32 ( & V_61 -> V_62 ) ;
if ( V_9 -> V_63 > 0 )
F_32 ( & V_9 -> V_64 ) ;
if ( F_22 ( F_33 ( V_61 ) &&
( V_61 -> V_65 || V_61 -> V_66 ) ) ) {
F_10 ( V_61 -> V_67 , V_26 ) ;
F_34 ( V_61 ) ;
F_13 ( V_61 -> V_67 , V_26 ) ;
}
F_32 ( & V_20 -> V_68 ) ;
}
static void F_35 ( struct V_24 * V_25 )
{
if ( V_25 -> V_29 )
F_36 ( V_25 ) ;
else
F_37 ( V_25 ) ;
}
static void F_38 ( struct V_7 * V_69 )
{
struct V_4 * V_61 = V_69 -> V_5 ;
struct V_7 * V_20 , * V_70 ;
struct V_8 * V_9 = V_8 ( V_69 ) ;
unsigned long V_26 ;
F_10 ( V_61 -> V_67 , V_26 ) ;
V_9 -> V_71 = NULL ;
F_13 ( V_61 -> V_67 , V_26 ) ;
F_35 ( V_69 -> V_24 ) ;
F_10 ( V_61 -> V_67 , V_26 ) ;
if ( V_9 -> V_71 )
goto V_46;
F_39 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_20 == V_69 )
continue;
if ( F_40 ( V_20 ) )
continue;
F_13 ( V_61 -> V_67 , V_26 ) ;
F_35 ( V_20 -> V_24 ) ;
F_10 ( V_61 -> V_67 , V_26 ) ;
F_41 ( V_20 ) ;
}
V_46:
F_13 ( V_61 -> V_67 , V_26 ) ;
}
static inline bool F_42 ( struct V_7 * V_20 )
{
if ( F_43 ( & V_20 -> V_68 ) >= V_20 -> V_72 )
return true ;
if ( F_43 ( & V_20 -> V_15 ) > 0 )
return true ;
return false ;
}
static inline bool F_44 ( struct V_8 * V_9 )
{
if ( V_9 -> V_63 > 0 ) {
if ( F_43 ( & V_9 -> V_64 ) >= V_9 -> V_63 )
return true ;
if ( F_43 ( & V_9 -> V_18 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_45 ( struct V_4 * V_61 )
{
if ( V_61 -> V_63 > 0 &&
F_43 ( & V_61 -> V_62 ) >= V_61 -> V_63 )
return true ;
if ( F_43 ( & V_61 -> V_11 ) > 0 )
return true ;
if ( V_61 -> V_73 )
return true ;
return false ;
}
static void F_46 ( struct V_4 * V_61 )
{
F_47 ( V_74 ) ;
struct V_7 * V_20 ;
unsigned long V_26 ;
F_10 ( V_61 -> V_67 , V_26 ) ;
F_48 ( & V_61 -> V_74 , & V_74 ) ;
while ( ! F_49 ( & V_74 ) ) {
struct V_24 * V_75 ;
if ( F_45 ( V_61 ) )
break;
V_20 = F_50 ( V_74 . V_76 ,
struct V_7 , V_77 ) ;
F_51 ( & V_20 -> V_77 ) ;
if ( F_44 ( V_8 ( V_20 ) ) ) {
F_52 ( & V_20 -> V_77 ,
& V_61 -> V_74 ) ;
continue;
}
V_75 = V_20 -> V_24 ;
if ( ! F_53 ( V_75 ) )
continue;
F_13 ( V_61 -> V_67 , V_26 ) ;
F_35 ( V_75 ) ;
F_54 ( V_75 ) ;
F_10 ( V_61 -> V_67 , V_26 ) ;
}
F_55 ( & V_74 , & V_61 -> V_74 ) ;
F_13 ( V_61 -> V_67 , V_26 ) ;
}
static void F_56 ( struct V_24 * V_25 )
{
struct V_7 * V_20 = V_25 -> V_78 ;
if ( V_8 ( V_20 ) -> V_79 )
F_38 ( V_20 ) ;
if ( ! F_49 ( & V_20 -> V_5 -> V_74 ) )
F_46 ( V_20 -> V_5 ) ;
if ( V_25 -> V_29 )
F_57 ( V_25 , false ) ;
else
F_37 ( V_25 ) ;
}
void F_58 ( struct V_80 * V_81 )
{
struct V_7 * V_20 ;
struct V_24 * V_25 ;
V_20 = F_59 ( V_81 , struct V_7 , V_31 ) ;
V_25 = V_20 -> V_24 ;
F_56 ( V_25 ) ;
}
static void F_60 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_40 = V_2 -> V_21 ;
unsigned long V_26 ;
F_10 ( V_25 -> V_30 , V_26 ) ;
F_61 ( V_40 ) ;
V_40 -> V_82 = NULL ;
F_62 ( V_2 ) ;
F_11 ( V_25 , V_40 ) ;
F_13 ( V_25 -> V_30 , V_26 ) ;
F_56 ( V_25 ) ;
F_5 ( & V_20 -> V_22 ) ;
}
void F_63 ( struct V_4 * V_61 )
{
struct V_7 * V_20 ;
F_64 (sdev, shost)
F_56 ( V_20 -> V_24 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 -> V_83 == V_84 ) {
struct V_85 * V_86 = F_66 ( V_2 ) ;
if ( V_86 -> V_87 )
V_86 -> V_87 ( V_2 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_88 * V_89 ;
if ( V_2 -> V_89 . V_90 . V_91 )
F_68 ( & V_2 -> V_89 . V_90 , true ) ;
if ( V_2 -> V_21 -> V_92 ) {
V_89 = V_2 -> V_21 -> V_92 -> V_82 ;
if ( V_89 )
F_68 ( & V_89 -> V_90 , true ) ;
}
if ( F_69 ( V_2 ) )
F_68 ( & V_2 -> V_93 -> V_90 , true ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_4 * V_61 = V_20 -> V_5 ;
unsigned long V_26 ;
F_67 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_61 -> V_94 ) {
F_71 ( F_49 ( & V_2 -> V_95 ) ) ;
F_10 ( & V_20 -> V_96 , V_26 ) ;
F_51 ( & V_2 -> V_95 ) ;
F_13 ( & V_20 -> V_96 , V_26 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 . V_90 . V_91 )
F_68 ( & V_2 -> V_89 . V_90 , false ) ;
memset ( & V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
if ( F_69 ( V_2 ) )
F_68 ( & V_2 -> V_93 -> V_90 , false ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_88 * V_97 = V_2 -> V_21 -> V_92 -> V_82 ;
F_68 ( & V_97 -> V_90 , false ) ;
F_74 ( V_98 , V_97 ) ;
V_2 -> V_21 -> V_92 -> V_82 = NULL ;
}
static bool F_75 ( struct V_21 * V_40 , int error ,
unsigned int V_99 , unsigned int V_100 )
{
struct V_1 * V_2 = V_40 -> V_82 ;
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_24 * V_25 = V_20 -> V_24 ;
if ( F_76 ( V_40 , error , V_99 ) )
return true ;
if ( F_22 ( V_100 ) &&
F_76 ( V_40 -> V_92 , error , V_100 ) )
return true ;
if ( F_77 ( V_25 ) )
F_78 ( V_40 -> V_101 ) ;
if ( V_40 -> V_102 ) {
F_70 ( V_2 ) ;
F_79 ( V_40 , error ) ;
if ( V_8 ( V_20 ) -> V_79 ||
! F_49 ( & V_20 -> V_5 -> V_74 ) )
F_12 ( & V_20 -> V_31 ) ;
else
F_57 ( V_25 , true ) ;
} else {
unsigned long V_26 ;
if ( V_100 )
F_73 ( V_2 ) ;
F_10 ( V_25 -> V_30 , V_26 ) ;
F_80 ( V_40 , error ) ;
F_13 ( V_25 -> V_30 , V_26 ) ;
F_72 ( V_2 ) ;
F_62 ( V_2 ) ;
F_56 ( V_25 ) ;
}
F_5 ( & V_20 -> V_22 ) ;
return false ;
}
static int F_81 ( struct V_1 * V_2 , int V_28 )
{
int error = 0 ;
switch( F_82 ( V_28 ) ) {
case V_103 :
error = - V_104 ;
break;
case V_105 :
F_83 ( V_2 , V_106 ) ;
error = - V_107 ;
break;
case V_108 :
F_83 ( V_2 , V_106 ) ;
error = - V_109 ;
break;
case V_110 :
F_83 ( V_2 , V_106 ) ;
error = - V_111 ;
break;
case V_112 :
F_83 ( V_2 , V_106 ) ;
error = - V_113 ;
break;
default:
error = - V_114 ;
break;
}
return error ;
}
void F_84 ( struct V_1 * V_2 , unsigned int V_115 )
{
int V_28 = V_2 -> V_28 ;
struct V_24 * V_25 = V_2 -> V_6 -> V_24 ;
struct V_21 * V_40 = V_2 -> V_21 ;
int error = 0 ;
struct V_54 V_55 ;
bool V_116 = false ;
int V_117 = 0 , V_118 = 0 ;
enum { V_119 , V_120 , V_121 ,
V_122 } V_123 ;
unsigned long V_124 = ( V_2 -> V_125 + 1 ) * V_40 -> V_36 ;
if ( V_28 ) {
V_116 = F_85 ( V_2 , & V_55 ) ;
if ( V_116 )
V_117 = F_86 ( & V_55 ) ;
}
if ( V_40 -> V_83 == V_126 ) {
if ( V_28 ) {
if ( V_116 && V_40 -> V_35 ) {
int V_127 = 8 + V_2 -> V_59 [ 7 ] ;
if ( V_127 > V_56 )
V_127 = V_56 ;
memcpy ( V_40 -> V_35 , V_2 -> V_59 , V_127 ) ;
V_40 -> V_48 = V_127 ;
}
if ( ! V_117 )
error = F_81 ( V_2 , V_28 ) ;
}
V_40 -> V_53 = V_2 -> V_28 ;
V_40 -> V_52 = F_87 ( V_2 ) ;
if ( F_88 ( V_2 ) ) {
V_40 -> V_92 -> V_52 = F_89 ( V_2 ) -> V_39 ;
if ( F_75 ( V_40 , 0 , F_90 ( V_40 ) ,
F_90 ( V_40 -> V_92 ) ) )
F_91 () ;
return;
}
} else if ( F_90 ( V_40 ) == 0 && V_28 && ! V_117 ) {
error = F_81 ( V_2 , V_28 ) ;
}
F_71 ( F_92 ( V_40 ) ) ;
F_93 ( 1 , F_8 ( V_27 , V_2 ,
L_2 ,
F_94 ( V_40 ) , V_115 ) ) ;
if ( V_116 && ( V_55 . V_128 == V_129 ) ) {
if ( ( V_55 . V_130 == 0x0 ) && ( V_55 . V_131 == 0x1d ) )
;
else if ( ! ( V_40 -> V_38 & V_50 ) )
F_95 ( V_2 ) ;
V_28 = 0 ;
error = 0 ;
}
if ( ! ( F_90 ( V_40 ) == 0 && error ) &&
! F_75 ( V_40 , error , V_115 , 0 ) )
return;
if ( error && F_96 ( V_2 ) ) {
if ( F_75 ( V_40 , error , F_90 ( V_40 ) , 0 ) )
F_91 () ;
return;
}
if ( V_28 == 0 )
goto V_132;
error = F_81 ( V_2 , V_28 ) ;
if ( F_82 ( V_28 ) == V_133 ) {
V_123 = V_121 ;
} else if ( V_116 && ! V_117 ) {
switch ( V_55 . V_128 ) {
case V_134 :
if ( V_2 -> V_6 -> V_135 ) {
V_2 -> V_6 -> V_136 = 1 ;
V_123 = V_119 ;
} else {
V_123 = V_121 ;
}
break;
case V_137 :
if ( ( V_2 -> V_6 -> V_138 &&
V_55 . V_130 == 0x20 && V_55 . V_131 == 0x00 ) &&
( V_2 -> V_60 [ 0 ] == V_139 ||
V_2 -> V_60 [ 0 ] == V_140 ) ) {
V_2 -> V_6 -> V_138 = 0 ;
V_123 = V_120 ;
} else if ( V_55 . V_130 == 0x10 ) {
V_123 = V_119 ;
error = - V_141 ;
} else if ( V_55 . V_130 == 0x20 || V_55 . V_130 == 0x24 ) {
V_123 = V_119 ;
error = - V_107 ;
} else
V_123 = V_119 ;
break;
case V_142 :
V_123 = V_119 ;
if ( V_55 . V_130 == 0x10 )
error = - V_141 ;
break;
case V_143 :
if ( V_55 . V_130 == 0x04 ) {
switch ( V_55 . V_131 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_123 = V_122 ;
break;
default:
V_123 = V_119 ;
break;
}
} else
V_123 = V_119 ;
break;
case V_144 :
V_123 = V_119 ;
break;
default:
V_123 = V_119 ;
break;
}
} else
V_123 = V_119 ;
if ( V_123 != V_119 &&
F_97 ( V_2 -> V_145 + V_124 , V_146 ) )
V_123 = V_119 ;
switch ( V_123 ) {
case V_119 :
if ( ! ( V_40 -> V_38 & V_50 ) ) {
static F_98 ( V_147 ,
V_148 ,
V_149 ) ;
if ( F_22 ( V_150 ) )
V_118 = F_99 ( V_151 ,
V_152 ) ;
if ( ! V_118 && F_100 ( & V_147 ) ) {
F_101 ( V_2 , NULL , V_153 ) ;
if ( F_102 ( V_28 ) & V_154 )
F_95 ( V_2 ) ;
F_103 ( V_2 ) ;
}
}
if ( ! F_75 ( V_40 , error , F_104 ( V_40 ) , 0 ) )
return;
case V_120 :
V_132:
if ( V_25 -> V_29 ) {
V_2 -> V_21 -> V_38 &= ~ V_155 ;
F_70 ( V_2 ) ;
F_3 ( V_2 ) ;
} else {
F_72 ( V_2 ) ;
F_60 ( V_25 , V_2 ) ;
}
break;
case V_121 :
F_6 ( V_2 , V_14 , 0 ) ;
break;
case V_122 :
F_6 ( V_2 , V_13 , 0 ) ;
break;
}
}
static int F_105 ( struct V_21 * V_40 , struct V_88 * V_89 )
{
int V_156 ;
if ( F_22 ( F_106 ( & V_89 -> V_90 ,
F_107 ( V_40 ) , V_89 -> V_90 . V_157 ) ) )
return V_158 ;
V_156 = F_108 ( V_40 -> V_25 , V_40 , V_89 -> V_90 . V_157 ) ;
F_71 ( V_156 > V_89 -> V_90 . V_91 ) ;
V_89 -> V_90 . V_91 = V_156 ;
V_89 -> V_159 = F_109 ( V_40 ) ;
return V_160 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_7 * V_20 = V_2 -> V_6 ;
struct V_21 * V_161 = V_2 -> V_21 ;
bool V_162 = ( V_161 -> V_102 != NULL ) ;
int error ;
if ( F_111 ( ! F_107 ( V_161 ) ) )
return - V_163 ;
error = F_105 ( V_161 , & V_2 -> V_89 ) ;
if ( error )
goto V_164;
if ( F_92 ( V_161 ) ) {
if ( ! V_161 -> V_25 -> V_29 ) {
struct V_88 * V_97 =
F_112 ( V_98 , V_165 ) ;
if ( ! V_97 ) {
error = V_158 ;
goto V_164;
}
V_161 -> V_92 -> V_82 = V_97 ;
}
error = F_105 ( V_161 -> V_92 , V_161 -> V_92 -> V_82 ) ;
if ( error )
goto V_164;
}
if ( F_113 ( V_161 ) ) {
struct V_88 * V_93 = V_2 -> V_93 ;
int V_166 , V_156 ;
if ( V_93 == NULL ) {
F_111 ( 1 ) ;
error = V_167 ;
goto V_164;
}
V_166 = F_114 ( V_161 -> V_25 , V_161 -> V_168 ) ;
if ( F_106 ( & V_93 -> V_90 , V_166 ,
V_93 -> V_90 . V_157 ) ) {
error = V_158 ;
goto V_164;
}
V_156 = F_115 ( V_161 -> V_25 , V_161 -> V_168 ,
V_93 -> V_90 . V_157 ) ;
F_71 ( F_22 ( V_156 > V_166 ) ) ;
F_71 ( F_22 ( V_156 > F_116 ( V_161 -> V_25 ) ) ) ;
V_2 -> V_93 = V_93 ;
V_2 -> V_93 -> V_90 . V_91 = V_156 ;
}
return V_160 ;
V_164:
if ( V_162 ) {
F_67 ( V_2 ) ;
} else {
F_72 ( V_2 ) ;
V_2 -> V_21 -> V_82 = NULL ;
F_62 ( V_2 ) ;
F_5 ( & V_20 -> V_22 ) ;
}
return error ;
}
static struct V_1 * F_117 ( struct V_7 * V_20 ,
struct V_21 * V_40 )
{
struct V_1 * V_2 ;
if ( ! V_40 -> V_82 ) {
if ( ! F_118 ( & V_20 -> V_22 ) )
return NULL ;
V_2 = F_119 ( V_20 , V_165 ) ;
if ( F_22 ( ! V_2 ) ) {
F_5 ( & V_20 -> V_22 ) ;
return NULL ;
}
V_40 -> V_82 = V_2 ;
} else {
V_2 = V_40 -> V_82 ;
}
V_2 -> V_169 = V_40 -> V_169 ;
V_2 -> V_21 = V_40 ;
V_2 -> V_60 = V_40 -> V_2 ;
V_2 -> V_170 = V_171 ;
return V_2 ;
}
static int F_120 ( struct V_7 * V_20 , struct V_21 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_82 ;
if ( V_40 -> V_168 ) {
int V_43 = F_110 ( V_2 ) ;
if ( F_22 ( V_43 ) )
return V_43 ;
} else {
F_71 ( F_90 ( V_40 ) ) ;
memset ( & V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
}
V_2 -> V_47 = V_40 -> V_47 ;
V_2 -> V_172 = F_90 ( V_40 ) ;
V_2 -> V_125 = V_40 -> V_37 ;
return V_160 ;
}
static int F_121 ( struct V_7 * V_20 , struct V_21 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_82 ;
if ( F_22 ( V_20 -> V_173 && V_20 -> V_173 -> V_174 ) ) {
int V_43 = V_20 -> V_173 -> V_174 ( V_20 , V_40 ) ;
if ( V_43 != V_160 )
return V_43 ;
}
memset ( V_2 -> V_60 , 0 , V_175 ) ;
return F_66 ( V_2 ) -> F_122 ( V_2 ) ;
}
static int F_123 ( struct V_7 * V_20 , struct V_21 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_82 ;
if ( ! F_90 ( V_40 ) )
V_2 -> V_176 = V_177 ;
else if ( F_124 ( V_40 ) == V_178 )
V_2 -> V_176 = V_42 ;
else
V_2 -> V_176 = V_179 ;
switch ( V_40 -> V_83 ) {
case V_84 :
return F_121 ( V_20 , V_40 ) ;
case V_126 :
return F_120 ( V_20 , V_40 ) ;
default:
return V_167 ;
}
}
static int
F_125 ( struct V_7 * V_20 , struct V_21 * V_40 )
{
int V_43 = V_160 ;
if ( F_22 ( V_20 -> V_180 != V_181 ) ) {
switch ( V_20 -> V_180 ) {
case V_182 :
case V_183 :
F_126 ( V_184 , V_20 ,
L_3 ) ;
V_43 = V_167 ;
break;
case V_185 :
F_126 ( V_184 , V_20 ,
L_4 ) ;
V_43 = V_167 ;
break;
case V_186 :
case V_187 :
V_43 = V_158 ;
break;
case V_188 :
if ( ! ( V_40 -> V_38 & V_51 ) )
V_43 = V_158 ;
break;
default:
if ( ! ( V_40 -> V_38 & V_51 ) )
V_43 = V_167 ;
break;
}
}
return V_43 ;
}
static int
F_127 ( struct V_24 * V_25 , struct V_21 * V_40 , int V_43 )
{
struct V_7 * V_20 = V_25 -> V_78 ;
switch ( V_43 ) {
case V_167 :
case V_189 :
V_40 -> V_53 = V_190 << 16 ;
if ( V_40 -> V_82 ) {
struct V_1 * V_2 = V_40 -> V_82 ;
F_72 ( V_2 ) ;
F_62 ( V_2 ) ;
F_5 ( & V_20 -> V_22 ) ;
V_40 -> V_82 = NULL ;
}
break;
case V_158 :
if ( F_43 ( & V_20 -> V_68 ) == 0 )
F_128 ( V_25 , V_191 ) ;
break;
default:
V_40 -> V_38 |= V_155 ;
}
return V_43 ;
}
static int F_129 ( struct V_24 * V_25 , struct V_21 * V_40 )
{
struct V_7 * V_20 = V_25 -> V_78 ;
struct V_1 * V_2 ;
int V_43 ;
V_43 = F_125 ( V_20 , V_40 ) ;
if ( V_43 != V_160 )
goto V_46;
V_2 = F_117 ( V_20 , V_40 ) ;
if ( F_22 ( ! V_2 ) ) {
V_43 = V_158 ;
goto V_46;
}
V_43 = F_123 ( V_20 , V_40 ) ;
V_46:
return F_127 ( V_25 , V_40 , V_43 ) ;
}
static void F_130 ( struct V_24 * V_25 , struct V_21 * V_40 )
{
F_65 ( V_40 -> V_82 ) ;
}
static inline int F_131 ( struct V_24 * V_25 ,
struct V_7 * V_20 )
{
unsigned int V_192 ;
V_192 = F_132 ( & V_20 -> V_68 ) - 1 ;
if ( F_43 ( & V_20 -> V_15 ) ) {
if ( V_192 )
goto V_193;
if ( F_133 ( & V_20 -> V_15 ) > 0 ) {
if ( ! V_25 -> V_29 )
F_128 ( V_25 , V_191 ) ;
goto V_193;
}
F_7 ( 3 , F_126 ( V_27 , V_20 ,
L_5 ) ) ;
}
if ( V_192 >= V_20 -> V_72 )
goto V_193;
return 1 ;
V_193:
F_32 ( & V_20 -> V_68 ) ;
return 0 ;
}
static inline int F_134 ( struct V_4 * V_61 ,
struct V_7 * V_20 )
{
struct V_8 * V_9 = V_8 ( V_20 ) ;
unsigned int V_192 ;
if ( V_9 -> V_79 ) {
F_135 ( V_61 -> V_67 ) ;
if ( V_9 -> V_71 &&
V_9 -> V_71 != V_20 ) {
F_136 ( V_61 -> V_67 ) ;
return 0 ;
}
V_9 -> V_71 = V_20 ;
F_136 ( V_61 -> V_67 ) ;
}
if ( V_9 -> V_63 <= 0 )
return 1 ;
V_192 = F_132 ( & V_9 -> V_64 ) - 1 ;
if ( F_43 ( & V_9 -> V_18 ) > 0 ) {
if ( V_192 )
goto V_194;
if ( F_133 ( & V_9 -> V_18 ) > 0 )
goto V_193;
F_7 ( 3 , F_137 ( V_27 , V_9 ,
L_6 ) ) ;
}
if ( V_192 >= V_9 -> V_63 )
goto V_194;
return 1 ;
V_194:
F_135 ( V_61 -> V_67 ) ;
F_52 ( & V_20 -> V_77 , & V_61 -> V_74 ) ;
F_136 ( V_61 -> V_67 ) ;
V_193:
if ( V_9 -> V_63 > 0 )
F_32 ( & V_9 -> V_64 ) ;
return 0 ;
}
static inline int F_138 ( struct V_24 * V_25 ,
struct V_4 * V_61 ,
struct V_7 * V_20 )
{
unsigned int V_192 ;
if ( F_33 ( V_61 ) )
return 0 ;
V_192 = F_132 ( & V_61 -> V_62 ) - 1 ;
if ( F_43 ( & V_61 -> V_11 ) > 0 ) {
if ( V_192 )
goto V_194;
if ( F_133 ( & V_61 -> V_11 ) > 0 )
goto V_193;
F_7 ( 3 ,
F_139 ( V_27 , V_61 ,
L_7 ) ) ;
}
if ( V_61 -> V_63 > 0 && V_192 >= V_61 -> V_63 )
goto V_194;
if ( V_61 -> V_73 )
goto V_194;
if ( ! F_49 ( & V_20 -> V_77 ) ) {
F_135 ( V_61 -> V_67 ) ;
if ( ! F_49 ( & V_20 -> V_77 ) )
F_51 ( & V_20 -> V_77 ) ;
F_136 ( V_61 -> V_67 ) ;
}
return 1 ;
V_194:
F_135 ( V_61 -> V_67 ) ;
if ( F_49 ( & V_20 -> V_77 ) )
F_140 ( & V_20 -> V_77 , & V_61 -> V_74 ) ;
F_136 ( V_61 -> V_67 ) ;
V_193:
F_32 ( & V_61 -> V_62 ) ;
return 0 ;
}
static int F_141 ( struct V_24 * V_25 )
{
struct V_7 * V_20 = V_25 -> V_78 ;
struct V_4 * V_61 ;
if ( F_142 ( V_25 ) )
return 0 ;
V_61 = V_20 -> V_5 ;
if ( F_33 ( V_61 ) || F_42 ( V_20 ) )
return 1 ;
return 0 ;
}
static void F_143 ( struct V_21 * V_40 , struct V_24 * V_25 )
{
struct V_1 * V_2 = V_40 -> V_82 ;
struct V_7 * V_20 ;
struct V_8 * V_9 ;
struct V_4 * V_61 ;
F_144 ( V_40 ) ;
F_8 ( V_27 , V_2 , L_8 ) ;
V_20 = V_2 -> V_6 ;
V_9 = V_8 ( V_20 ) ;
V_61 = V_20 -> V_5 ;
F_29 ( V_2 ) ;
V_2 -> V_28 = V_190 << 16 ;
F_145 ( & V_2 -> V_6 -> V_195 ) ;
F_145 ( & V_20 -> V_68 ) ;
F_145 ( & V_61 -> V_62 ) ;
if ( V_9 -> V_63 > 0 )
F_145 ( & V_9 -> V_64 ) ;
F_146 ( V_40 ) ;
}
static void F_147 ( struct V_21 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_82 ;
unsigned long V_124 = ( V_2 -> V_125 + 1 ) * V_161 -> V_36 ;
int V_196 ;
F_148 ( & V_2 -> V_197 ) ;
F_145 ( & V_2 -> V_6 -> V_198 ) ;
if ( V_2 -> V_28 )
F_145 ( & V_2 -> V_6 -> V_199 ) ;
V_196 = F_149 ( V_2 ) ;
if ( V_196 != V_200 &&
F_97 ( V_2 -> V_145 + V_124 , V_146 ) ) {
F_126 ( V_184 , V_2 -> V_6 ,
L_9 ,
V_124 / V_201 ) ;
V_196 = V_200 ;
}
F_150 ( V_2 , V_196 ) ;
switch ( V_196 ) {
case V_200 :
F_151 ( V_2 ) ;
break;
case V_202 :
F_14 ( V_2 , V_14 ) ;
break;
case V_203 :
F_14 ( V_2 , V_13 ) ;
break;
default:
if ( ! F_152 ( V_2 , 0 ) )
F_151 ( V_2 ) ;
}
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_5 ;
int V_204 = 0 ;
F_145 ( & V_2 -> V_6 -> V_195 ) ;
if ( F_22 ( V_2 -> V_6 -> V_180 == V_185 ) ) {
V_2 -> V_28 = V_190 << 16 ;
goto V_205;
}
if ( F_22 ( F_154 ( V_2 -> V_6 ) ) ) {
F_7 ( 3 , F_8 ( V_27 , V_2 ,
L_10 ) ) ;
return V_13 ;
}
if ( V_2 -> V_6 -> V_206 )
V_2 -> V_60 [ 1 ] = ( V_2 -> V_60 [ 1 ] & 0x1f ) |
( V_2 -> V_6 -> V_207 << 5 & 0xe0 ) ;
F_155 ( V_2 ) ;
if ( V_2 -> V_47 > V_2 -> V_6 -> V_5 -> V_208 ) {
F_7 ( 3 , F_8 ( V_27 , V_2 ,
L_11
L_12 ,
V_2 -> V_47 , V_2 -> V_6 -> V_5 -> V_208 ) ) ;
V_2 -> V_28 = ( V_209 << 16 ) ;
goto V_205;
}
if ( F_22 ( V_5 -> V_210 == V_211 ) ) {
V_2 -> V_28 = ( V_190 << 16 ) ;
goto V_205;
}
F_156 ( V_2 ) ;
V_204 = V_5 -> V_212 -> V_213 ( V_5 , V_2 ) ;
if ( V_204 ) {
F_157 ( V_2 , V_204 ) ;
if ( V_204 != V_13 &&
V_204 != V_17 )
V_204 = V_10 ;
F_7 ( 3 , F_8 ( V_27 , V_2 ,
L_13 ) ) ;
}
return V_204 ;
V_205:
V_2 -> V_214 ( V_2 ) ;
return 0 ;
}
static void V_214 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_146 ( V_2 -> V_21 ) ;
}
static void F_159 ( struct V_24 * V_25 )
__releases( V_25 -> V_30 )
__acquires( V_25 -> V_30 )
{
struct V_7 * V_20 = V_25 -> V_78 ;
struct V_4 * V_61 ;
struct V_1 * V_2 ;
struct V_21 * V_40 ;
V_61 = V_20 -> V_5 ;
for (; ; ) {
int V_204 ;
V_40 = F_160 ( V_25 ) ;
if ( ! V_40 )
break;
if ( F_22 ( ! F_161 ( V_20 ) ) ) {
F_126 ( V_184 , V_20 ,
L_3 ) ;
F_143 ( V_40 , V_25 ) ;
continue;
}
if ( ! F_131 ( V_25 , V_20 ) )
break;
if ( ! ( F_162 ( V_25 ) && ! F_163 ( V_25 , V_40 ) ) )
F_144 ( V_40 ) ;
F_136 ( V_25 -> V_30 ) ;
V_2 = V_40 -> V_82 ;
if ( F_22 ( V_2 == NULL ) ) {
F_164 ( V_215 L_14
L_15
L_16 ,
V_216 ) ;
F_165 ( V_40 , L_17 ) ;
F_91 () ;
}
if ( F_162 ( V_25 ) && ! ( V_40 -> V_38 & V_217 ) ) {
F_135 ( V_61 -> V_67 ) ;
if ( F_49 ( & V_20 -> V_77 ) )
F_140 ( & V_20 -> V_77 ,
& V_61 -> V_74 ) ;
F_136 ( V_61 -> V_67 ) ;
goto V_218;
}
if ( ! F_134 ( V_61 , V_20 ) )
goto V_218;
if ( ! F_138 ( V_25 , V_61 , V_20 ) )
goto V_219;
if ( V_20 -> V_220 )
V_2 -> V_26 |= V_221 ;
else
V_2 -> V_26 &= ~ V_221 ;
F_29 ( V_2 ) ;
V_2 -> V_214 = V_214 ;
V_204 = F_153 ( V_2 ) ;
if ( V_204 ) {
F_14 ( V_2 , V_204 ) ;
F_135 ( V_25 -> V_30 ) ;
goto V_222;
}
F_135 ( V_25 -> V_30 ) ;
}
return;
V_219:
if ( V_8 ( V_20 ) -> V_63 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_64 ) ;
V_218:
F_135 ( V_25 -> V_30 ) ;
F_11 ( V_25 , V_40 ) ;
F_32 ( & V_20 -> V_68 ) ;
V_222:
if ( ! F_43 ( & V_20 -> V_68 ) && ! F_154 ( V_20 ) )
F_128 ( V_25 , V_191 ) ;
}
static inline int F_166 ( int V_43 )
{
switch ( V_43 ) {
case V_160 :
return V_223 ;
case V_158 :
return V_224 ;
default:
return V_225 ;
}
}
static int F_167 ( struct V_21 * V_40 )
{
struct V_1 * V_2 = F_168 ( V_40 ) ;
struct V_7 * V_20 = V_40 -> V_25 -> V_78 ;
struct V_4 * V_61 = V_20 -> V_5 ;
unsigned char * V_226 = V_2 -> V_59 ;
struct V_227 * V_228 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_40 -> V_82 = V_2 ;
V_2 -> V_21 = V_40 ;
V_2 -> V_6 = V_20 ;
V_2 -> V_59 = V_226 ;
V_2 -> V_169 = V_40 -> V_169 ;
V_2 -> V_60 = V_40 -> V_2 ;
V_2 -> V_170 = V_171 ;
F_148 ( & V_2 -> V_95 ) ;
F_169 ( & V_2 -> V_229 , V_230 ) ;
V_2 -> V_145 = V_146 ;
if ( V_61 -> V_94 ) {
F_135 ( & V_20 -> V_96 ) ;
F_140 ( & V_2 -> V_95 , & V_20 -> V_231 ) ;
F_136 ( & V_20 -> V_96 ) ;
}
V_228 = ( void * ) V_2 + sizeof( struct V_1 ) + V_61 -> V_212 -> V_232 ;
V_2 -> V_89 . V_90 . V_157 = V_228 ;
if ( F_170 ( V_61 ) ) {
V_2 -> V_93 = ( void * ) V_228 +
F_171 (unsigned int,
shost->sg_tablesize, SG_CHUNK_SIZE) *
sizeof( struct V_227 ) ;
memset ( V_2 -> V_93 , 0 , sizeof( struct V_88 ) ) ;
V_2 -> V_93 -> V_90 . V_157 =
(struct V_227 * ) ( V_2 -> V_93 + 1 ) ;
}
if ( F_92 ( V_40 ) ) {
struct V_21 * V_92 = V_40 -> V_92 ;
struct V_88 * V_97 = F_168 ( V_92 ) ;
memset ( V_97 , 0 , sizeof( struct V_88 ) ) ;
V_97 -> V_90 . V_157 =
(struct V_227 * ) ( V_97 + 1 ) ;
V_92 -> V_82 = V_97 ;
}
F_172 ( V_40 ) ;
return F_123 ( V_20 , V_40 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_174 ( V_2 -> V_21 , V_2 -> V_21 -> V_53 ) ;
}
static int F_175 ( struct V_233 * V_234 ,
const struct V_235 * V_236 )
{
struct V_21 * V_40 = V_236 -> V_161 ;
struct V_24 * V_25 = V_40 -> V_25 ;
struct V_7 * V_20 = V_25 -> V_78 ;
struct V_4 * V_61 = V_20 -> V_5 ;
struct V_1 * V_2 = F_168 ( V_40 ) ;
int V_43 ;
int V_3 ;
V_43 = F_166 ( F_125 ( V_20 , V_40 ) ) ;
if ( V_43 != V_223 )
goto V_46;
V_43 = V_224 ;
if ( ! F_118 ( & V_20 -> V_22 ) )
goto V_46;
if ( ! F_131 ( V_25 , V_20 ) )
goto V_237;
if ( ! F_134 ( V_61 , V_20 ) )
goto V_238;
if ( ! F_138 ( V_25 , V_61 , V_20 ) )
goto V_239;
if ( ! ( V_40 -> V_38 & V_155 ) ) {
V_43 = F_166 ( F_167 ( V_40 ) ) ;
if ( V_43 != V_223 )
goto V_240;
V_40 -> V_38 |= V_155 ;
} else {
F_172 ( V_40 ) ;
}
if ( V_20 -> V_220 )
V_2 -> V_26 |= V_221 ;
else
V_2 -> V_26 &= ~ V_221 ;
F_29 ( V_2 ) ;
V_2 -> V_214 = F_173 ;
V_3 = F_153 ( V_2 ) ;
if ( V_3 ) {
F_1 ( V_2 , V_3 ) ;
V_43 = V_224 ;
goto V_240;
}
return V_223 ;
V_240:
F_32 ( & V_61 -> V_62 ) ;
V_239:
if ( V_8 ( V_20 ) -> V_63 > 0 )
F_32 ( & V_8 ( V_20 ) -> V_64 ) ;
V_238:
F_32 ( & V_20 -> V_68 ) ;
V_237:
F_5 ( & V_20 -> V_22 ) ;
V_46:
switch ( V_43 ) {
case V_224 :
if ( F_43 ( & V_20 -> V_68 ) == 0 &&
! F_154 ( V_20 ) )
F_176 ( V_234 , V_191 ) ;
break;
case V_225 :
if ( V_40 -> V_38 & V_155 )
F_70 ( V_2 ) ;
break;
default:
break;
}
return V_43 ;
}
static enum V_241 F_177 ( struct V_21 * V_40 ,
bool V_242 )
{
if ( V_242 )
return V_243 ;
return F_178 ( V_40 ) ;
}
static int F_179 ( void * V_244 , struct V_21 * V_161 ,
unsigned int V_245 , unsigned int V_246 ,
unsigned int V_247 )
{
struct V_1 * V_2 = F_168 ( V_161 ) ;
V_2 -> V_59 = F_180 ( V_56 , V_248 ,
V_247 ) ;
if ( ! V_2 -> V_59 )
return - V_249 ;
return 0 ;
}
static void F_181 ( void * V_244 , struct V_21 * V_161 ,
unsigned int V_245 , unsigned int V_246 )
{
struct V_1 * V_2 = F_168 ( V_161 ) ;
F_28 ( V_2 -> V_59 ) ;
}
static int F_182 ( struct V_250 * V_251 )
{
struct V_4 * V_61 = F_59 ( V_251 , struct V_4 , V_252 ) ;
if ( V_61 -> V_212 -> V_253 )
return V_61 -> V_212 -> V_253 ( V_61 ) ;
return F_183 ( V_251 ) ;
}
static T_1 F_184 ( struct V_4 * V_61 )
{
struct V_6 * V_254 ;
T_1 V_255 = 0xffffffff ;
if ( V_61 -> V_256 )
return V_257 ;
if ( ! V_258 )
return V_259 ;
V_254 = F_185 ( V_61 ) ;
if ( V_254 && V_254 -> V_260 )
V_255 = ( T_1 ) F_186 ( V_254 ) << V_261 ;
return V_255 ;
}
static void F_187 ( struct V_4 * V_61 , struct V_24 * V_25 )
{
struct V_6 * V_262 = V_61 -> V_263 ;
F_188 ( V_25 , F_171 (unsigned short, shost->sg_tablesize,
SG_MAX_SEGMENTS) ) ;
if ( F_189 ( V_61 ) ) {
V_61 -> V_264 =
F_190 ( V_61 -> V_264 ,
( unsigned short ) V_265 ) ;
F_71 ( V_61 -> V_264 < V_61 -> V_266 ) ;
F_191 ( V_25 , V_61 -> V_264 ) ;
}
F_192 ( V_25 , V_61 -> V_267 ) ;
F_193 ( V_25 , F_184 ( V_61 ) ) ;
F_194 ( V_25 , V_61 -> V_268 ) ;
F_195 ( V_262 , V_61 -> V_268 ) ;
F_196 ( V_25 , F_197 ( V_262 ) ) ;
if ( ! V_61 -> V_269 )
V_25 -> V_270 . V_271 = 0 ;
F_198 ( V_25 , 0x03 ) ;
}
struct V_24 * F_199 ( struct V_4 * V_61 ,
T_3 * V_272 )
{
struct V_24 * V_25 ;
V_25 = F_200 ( V_272 , NULL ) ;
if ( ! V_25 )
return NULL ;
F_187 ( V_61 , V_25 ) ;
return V_25 ;
}
struct V_24 * F_201 ( struct V_7 * V_20 )
{
struct V_24 * V_25 ;
V_25 = F_199 ( V_20 -> V_5 , F_159 ) ;
if ( ! V_25 )
return NULL ;
F_202 ( V_25 , F_129 ) ;
F_203 ( V_25 , F_130 ) ;
F_204 ( V_25 , F_147 ) ;
F_205 ( V_25 , F_178 ) ;
F_206 ( V_25 , F_141 ) ;
return V_25 ;
}
struct V_24 * F_207 ( struct V_7 * V_20 )
{
V_20 -> V_24 = F_208 ( & V_20 -> V_5 -> V_252 ) ;
if ( F_17 ( V_20 -> V_24 ) )
return NULL ;
V_20 -> V_24 -> V_78 = V_20 ;
F_187 ( V_20 -> V_5 , V_20 -> V_24 ) ;
return V_20 -> V_24 ;
}
int F_209 ( struct V_4 * V_61 )
{
unsigned int V_232 , V_273 , V_274 ;
V_274 = V_61 -> V_266 ;
if ( V_274 > V_275 )
V_274 = V_275 ;
V_273 = V_274 * sizeof( struct V_227 ) ;
V_232 = sizeof( struct V_1 ) + V_61 -> V_212 -> V_232 + V_273 ;
if ( F_170 ( V_61 ) )
V_232 += sizeof( struct V_88 ) + V_273 ;
memset ( & V_61 -> V_252 , 0 , sizeof( V_61 -> V_252 ) ) ;
V_61 -> V_252 . V_276 = & V_277 ;
V_61 -> V_252 . V_278 = V_61 -> V_278 ? : 1 ;
V_61 -> V_252 . V_72 = V_61 -> V_63 ;
V_61 -> V_252 . V_232 = V_232 ;
V_61 -> V_252 . V_247 = V_279 ;
V_61 -> V_252 . V_26 = V_280 | V_281 ;
V_61 -> V_252 . V_26 |=
F_210 ( V_61 -> V_212 -> V_282 ) ;
V_61 -> V_252 . V_283 = V_61 ;
return F_211 ( & V_61 -> V_252 ) ;
}
void F_212 ( struct V_4 * V_61 )
{
F_213 ( & V_61 -> V_252 ) ;
}
void F_214 ( struct V_4 * V_61 )
{
V_61 -> V_73 = 1 ;
}
void F_215 ( struct V_4 * V_61 )
{
V_61 -> V_73 = 0 ;
F_63 ( V_61 ) ;
}
int T_4 F_216 ( void )
{
V_98 = F_217 ( L_18 ,
sizeof( struct V_88 ) ,
0 , 0 , NULL ) ;
if ( ! V_98 ) {
F_164 ( V_184 L_19 ) ;
return - V_249 ;
}
return 0 ;
}
void F_218 ( void )
{
F_219 ( V_98 ) ;
}
int
F_220 ( struct V_7 * V_20 , int V_284 , int V_285 , int V_286 ,
unsigned char * V_33 , int V_127 , int V_36 , int V_37 ,
struct V_287 * V_244 , struct V_54 * V_55 )
{
unsigned char V_2 [ 10 ] ;
unsigned char * V_288 ;
int V_43 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
V_2 [ 1 ] = ( V_284 ? 0x10 : 0 ) | ( V_285 ? 0x01 : 0 ) ;
if ( V_20 -> V_289 ) {
if ( V_127 > 65535 )
return - V_163 ;
V_288 = F_221 ( 8 + V_127 , V_248 ) ;
if ( ! V_288 )
return - V_249 ;
memcpy ( V_288 + 8 , V_33 , V_127 ) ;
V_127 += 8 ;
V_288 [ 0 ] = 0 ;
V_288 [ 1 ] = 0 ;
V_288 [ 2 ] = V_244 -> V_290 ;
V_288 [ 3 ] = V_244 -> V_291 ;
V_288 [ 4 ] = V_244 -> V_292 ? 0x01 : 0 ;
V_288 [ 5 ] = 0 ;
V_288 [ 6 ] = V_244 -> V_293 >> 8 ;
V_288 [ 7 ] = V_244 -> V_293 ;
V_2 [ 0 ] = V_294 ;
V_2 [ 7 ] = V_127 >> 8 ;
V_2 [ 8 ] = V_127 ;
} else {
if ( V_127 > 255 || V_244 -> V_293 > 255 ||
V_244 -> V_292 )
return - V_163 ;
V_288 = F_221 ( 4 + V_127 , V_248 ) ;
if ( ! V_288 )
return - V_249 ;
memcpy ( V_288 + 4 , V_33 , V_127 ) ;
V_127 += 4 ;
V_288 [ 0 ] = 0 ;
V_288 [ 1 ] = V_244 -> V_290 ;
V_288 [ 2 ] = V_244 -> V_291 ;
V_288 [ 3 ] = V_244 -> V_293 ;
V_2 [ 0 ] = V_295 ;
V_2 [ 4 ] = V_127 ;
}
V_43 = F_222 ( V_20 , V_2 , V_42 , V_288 , V_127 ,
V_55 , V_36 , V_37 , NULL ) ;
F_28 ( V_288 ) ;
return V_43 ;
}
int
F_223 ( struct V_7 * V_20 , int V_296 , int V_286 ,
unsigned char * V_33 , int V_127 , int V_36 , int V_37 ,
struct V_287 * V_244 , struct V_54 * V_55 )
{
unsigned char V_2 [ 12 ] ;
int V_289 ;
int V_297 ;
int V_28 , V_298 = V_37 ;
struct V_54 V_299 ;
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
memset ( & V_2 [ 0 ] , 0 , 12 ) ;
V_2 [ 1 ] = V_296 & 0x18 ;
V_2 [ 2 ] = V_286 ;
if ( ! V_55 )
V_55 = & V_299 ;
V_300:
V_289 = V_20 -> V_289 ;
if ( V_289 ) {
if ( V_127 < 8 )
V_127 = 8 ;
V_2 [ 0 ] = V_301 ;
V_2 [ 8 ] = V_127 ;
V_297 = 8 ;
} else {
if ( V_127 < 4 )
V_127 = 4 ;
V_2 [ 0 ] = V_302 ;
V_2 [ 4 ] = V_127 ;
V_297 = 4 ;
}
memset ( V_33 , 0 , V_127 ) ;
V_28 = F_222 ( V_20 , V_2 , V_179 , V_33 , V_127 ,
V_55 , V_36 , V_37 , NULL ) ;
if ( V_289 && ! F_224 ( V_28 ) &&
( F_102 ( V_28 ) & V_154 ) ) {
if ( F_225 ( V_55 ) ) {
if ( ( V_55 -> V_128 == V_137 ) &&
( V_55 -> V_130 == 0x20 ) && ( V_55 -> V_131 == 0 ) ) {
V_20 -> V_289 = 0 ;
goto V_300;
}
}
}
if( F_224 ( V_28 ) ) {
if ( F_22 ( V_33 [ 0 ] == 0x86 && V_33 [ 1 ] == 0x0b &&
( V_286 == 6 || V_286 == 8 ) ) ) {
V_297 = 0 ;
V_244 -> V_159 = 13 ;
V_244 -> V_290 = 0 ;
V_244 -> V_291 = 0 ;
V_244 -> V_292 = 0 ;
V_244 -> V_293 = 0 ;
} else if( V_289 ) {
V_244 -> V_159 = V_33 [ 0 ] * 256 + V_33 [ 1 ] + 2 ;
V_244 -> V_290 = V_33 [ 2 ] ;
V_244 -> V_291 = V_33 [ 3 ] ;
V_244 -> V_292 = V_33 [ 4 ] & 0x01 ;
V_244 -> V_293 = V_33 [ 6 ] * 256
+ V_33 [ 7 ] ;
} else {
V_244 -> V_159 = V_33 [ 0 ] + 1 ;
V_244 -> V_290 = V_33 [ 1 ] ;
V_244 -> V_291 = V_33 [ 2 ] ;
V_244 -> V_293 = V_33 [ 3 ] ;
}
V_244 -> V_297 = V_297 ;
} else if ( ( F_226 ( V_28 ) == V_303 ) &&
F_225 ( V_55 ) &&
V_55 -> V_128 == V_134 && V_298 ) {
V_298 -- ;
goto V_300;
}
return V_28 ;
}
int
F_227 ( struct V_7 * V_20 , int V_36 , int V_37 ,
struct V_54 * V_304 )
{
char V_2 [] = {
V_305 , 0 , 0 , 0 , 0 , 0 ,
} ;
struct V_54 * V_55 ;
int V_28 ;
if ( ! V_304 )
V_55 = F_26 ( sizeof( * V_55 ) , V_248 ) ;
else
V_55 = V_304 ;
do {
V_28 = F_222 ( V_20 , V_2 , V_177 , NULL , 0 , V_55 ,
V_36 , V_37 , NULL ) ;
if ( V_20 -> V_135 && F_225 ( V_55 ) &&
V_55 -> V_128 == V_134 )
V_20 -> V_136 = 1 ;
} while ( F_225 ( V_55 ) &&
V_55 -> V_128 == V_134 && -- V_37 );
if ( ! V_304 )
F_28 ( V_55 ) ;
return V_28 ;
}
int
F_228 ( struct V_7 * V_20 , enum V_306 V_307 )
{
enum V_306 V_308 = V_20 -> V_180 ;
if ( V_307 == V_308 )
return 0 ;
switch ( V_307 ) {
case V_309 :
switch ( V_308 ) {
case V_187 :
break;
default:
goto V_310;
}
break;
case V_181 :
switch ( V_308 ) {
case V_309 :
case V_182 :
case V_183 :
case V_188 :
case V_186 :
break;
default:
goto V_310;
}
break;
case V_188 :
switch ( V_308 ) {
case V_181 :
case V_182 :
case V_183 :
break;
default:
goto V_310;
}
break;
case V_182 :
case V_183 :
switch ( V_308 ) {
case V_309 :
case V_181 :
case V_188 :
case V_186 :
break;
default:
goto V_310;
}
break;
case V_186 :
switch ( V_308 ) {
case V_181 :
case V_187 :
break;
default:
goto V_310;
}
break;
case V_187 :
switch ( V_308 ) {
case V_309 :
break;
default:
goto V_310;
}
break;
case V_311 :
switch ( V_308 ) {
case V_309 :
case V_181 :
case V_188 :
case V_182 :
case V_183 :
case V_186 :
break;
default:
goto V_310;
}
break;
case V_185 :
switch ( V_308 ) {
case V_309 :
case V_181 :
case V_182 :
case V_183 :
case V_311 :
case V_187 :
break;
default:
goto V_310;
}
break;
}
V_20 -> V_180 = V_307 ;
return 0 ;
V_310:
F_229 ( 1 ,
F_126 ( V_184 , V_20 ,
L_20 ,
F_230 ( V_308 ) ,
F_230 ( V_307 ) )
) ;
return - V_163 ;
}
static void F_231 ( struct V_7 * V_20 , struct V_312 * V_313 )
{
int V_314 = 0 ;
char * V_315 [ 3 ] ;
switch ( V_313 -> V_316 ) {
case V_317 :
V_315 [ V_314 ++ ] = L_21 ;
break;
case V_318 :
F_232 ( & V_20 -> V_22 ) ;
V_315 [ V_314 ++ ] = L_22 ;
break;
case V_319 :
V_315 [ V_314 ++ ] = L_23 ;
break;
case V_320 :
V_315 [ V_314 ++ ] = L_24 ;
break;
case V_321 :
V_315 [ V_314 ++ ] = L_25 ;
break;
case V_322 :
V_315 [ V_314 ++ ] = L_26 ;
break;
case V_323 :
V_315 [ V_314 ++ ] = L_27 ;
break;
default:
break;
}
V_315 [ V_314 ++ ] = NULL ;
F_233 ( & V_20 -> V_22 . V_324 , V_325 , V_315 ) ;
}
void F_234 ( struct V_80 * V_81 )
{
struct V_7 * V_20 ;
enum V_326 V_316 ;
F_47 ( V_327 ) ;
V_20 = F_59 ( V_81 , struct V_7 , V_328 ) ;
for ( V_316 = V_329 ; V_316 <= V_330 ; V_316 ++ )
if ( F_235 ( V_316 , V_20 -> V_331 ) )
F_236 ( V_20 , V_316 , V_248 ) ;
while ( 1 ) {
struct V_312 * V_313 ;
struct V_332 * V_333 , * V_70 ;
unsigned long V_26 ;
F_10 ( & V_20 -> V_96 , V_26 ) ;
F_48 ( & V_20 -> V_327 , & V_327 ) ;
F_13 ( & V_20 -> V_96 , V_26 ) ;
if ( F_49 ( & V_327 ) )
break;
F_237 (this, tmp, &event_list) {
V_313 = F_50 ( V_333 , struct V_312 , V_334 ) ;
F_238 ( & V_313 -> V_334 ) ;
F_231 ( V_20 , V_313 ) ;
F_28 ( V_313 ) ;
}
}
}
void F_239 ( struct V_7 * V_20 , struct V_312 * V_313 )
{
unsigned long V_26 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_10 ( & V_20 -> V_96 , V_26 ) ;
F_140 ( & V_313 -> V_334 , & V_20 -> V_327 ) ;
F_240 ( & V_20 -> V_328 ) ;
F_13 ( & V_20 -> V_96 , V_26 ) ;
}
struct V_312 * F_241 ( enum V_326 V_316 ,
T_5 V_335 )
{
struct V_312 * V_313 = F_26 ( sizeof( struct V_312 ) , V_335 ) ;
if ( ! V_313 )
return NULL ;
V_313 -> V_316 = V_316 ;
F_148 ( & V_313 -> V_334 ) ;
switch ( V_316 ) {
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
default:
break;
}
return V_313 ;
}
void F_236 ( struct V_7 * V_20 ,
enum V_326 V_316 , T_5 V_335 )
{
struct V_312 * V_313 = F_241 ( V_316 , V_335 ) ;
if ( ! V_313 ) {
F_126 ( V_184 , V_20 , L_28 ,
V_316 ) ;
return;
}
F_239 ( V_20 , V_313 ) ;
}
static int F_242 ( struct V_7 * V_20 )
{
struct V_24 * V_25 = V_20 -> V_24 ;
int V_336 ;
F_111 ( V_20 -> V_5 -> V_337 ) ;
F_135 ( V_25 -> V_30 ) ;
V_336 = V_25 -> V_336 ;
F_136 ( V_25 -> V_30 ) ;
return V_336 ;
}
static void F_243 ( struct V_7 * V_20 )
{
F_111 ( V_20 -> V_5 -> V_337 ) ;
while ( F_242 ( V_20 ) )
F_244 ( 20 ) ;
}
int
F_245 ( struct V_7 * V_20 )
{
int V_338 = F_228 ( V_20 , V_188 ) ;
if ( V_338 )
return V_338 ;
F_56 ( V_20 -> V_24 ) ;
while ( F_43 ( & V_20 -> V_68 ) ) {
F_246 ( 200 ) ;
F_56 ( V_20 -> V_24 ) ;
}
return 0 ;
}
void F_247 ( struct V_7 * V_20 )
{
if ( V_20 -> V_180 != V_188 ||
F_228 ( V_20 , V_181 ) )
return;
F_56 ( V_20 -> V_24 ) ;
}
static void
F_248 ( struct V_7 * V_20 , void * V_244 )
{
F_245 ( V_20 ) ;
}
void
F_249 ( struct V_8 * V_9 )
{
F_250 ( V_9 , NULL , F_248 ) ;
}
static void
F_251 ( struct V_7 * V_20 , void * V_244 )
{
F_247 ( V_20 ) ;
}
void
F_252 ( struct V_8 * V_9 )
{
F_250 ( V_9 , NULL , F_251 ) ;
}
int
F_253 ( struct V_7 * V_20 )
{
struct V_24 * V_25 = V_20 -> V_24 ;
unsigned long V_26 ;
int V_338 = 0 ;
V_338 = F_228 ( V_20 , V_186 ) ;
if ( V_338 ) {
V_338 = F_228 ( V_20 , V_187 ) ;
if ( V_338 )
return V_338 ;
}
if ( V_25 -> V_29 ) {
F_254 ( V_25 ) ;
} else {
F_10 ( V_25 -> V_30 , V_26 ) ;
F_255 ( V_25 ) ;
F_13 ( V_25 -> V_30 , V_26 ) ;
F_243 ( V_20 ) ;
}
return 0 ;
}
int
F_256 ( struct V_7 * V_20 ,
enum V_306 V_339 )
{
struct V_24 * V_25 = V_20 -> V_24 ;
unsigned long V_26 ;
if ( ( V_20 -> V_180 == V_186 ) ||
( V_20 -> V_180 == V_183 ) )
V_20 -> V_180 = V_339 ;
else if ( V_20 -> V_180 == V_187 ) {
if ( V_339 == V_183 ||
V_339 == V_182 )
V_20 -> V_180 = V_339 ;
else
V_20 -> V_180 = V_309 ;
} else if ( V_20 -> V_180 != V_311 &&
V_20 -> V_180 != V_182 )
return - V_163 ;
if ( V_25 -> V_29 ) {
F_57 ( V_25 , false ) ;
} else {
F_10 ( V_25 -> V_30 , V_26 ) ;
F_257 ( V_25 ) ;
F_13 ( V_25 -> V_30 , V_26 ) ;
}
return 0 ;
}
static void
F_258 ( struct V_7 * V_20 , void * V_244 )
{
F_253 ( V_20 ) ;
}
static int
F_259 ( struct V_6 * V_262 , void * V_244 )
{
if ( F_260 ( V_262 ) )
F_250 ( F_261 ( V_262 ) , NULL ,
F_258 ) ;
return 0 ;
}
void
F_262 ( struct V_6 * V_262 )
{
if ( F_260 ( V_262 ) )
F_250 ( F_261 ( V_262 ) , NULL ,
F_258 ) ;
else
F_263 ( V_262 , NULL , F_259 ) ;
}
static void
F_264 ( struct V_7 * V_20 , void * V_244 )
{
F_256 ( V_20 , * (enum V_306 * ) V_244 ) ;
}
static int
F_265 ( struct V_6 * V_262 , void * V_244 )
{
if ( F_260 ( V_262 ) )
F_250 ( F_261 ( V_262 ) , V_244 ,
F_264 ) ;
return 0 ;
}
void
F_266 ( struct V_6 * V_262 , enum V_306 V_339 )
{
if ( F_260 ( V_262 ) )
F_250 ( F_261 ( V_262 ) , & V_339 ,
F_264 ) ;
else
F_263 ( V_262 , & V_339 , F_265 ) ;
}
void * F_267 ( struct V_227 * V_157 , int V_340 ,
T_6 * V_341 , T_6 * V_127 )
{
int V_342 ;
T_6 V_343 = 0 , V_344 = 0 ;
struct V_227 * V_228 ;
struct V_345 * V_345 ;
F_268 ( ! F_269 () ) ;
F_270 (sgl, sg, sg_count, i) {
V_344 = V_343 ;
V_343 += V_228 -> V_159 ;
if ( V_343 > * V_341 )
break;
}
if ( F_22 ( V_342 == V_340 ) ) {
F_164 ( V_184 L_29
L_30 ,
V_216 , V_343 , * V_341 , V_340 ) ;
F_268 ( 1 ) ;
return NULL ;
}
* V_341 = * V_341 - V_344 + V_228 -> V_341 ;
V_345 = F_271 ( F_272 ( V_228 ) , ( * V_341 >> V_261 ) ) ;
* V_341 &= ~ V_346 ;
V_343 = V_347 - * V_341 ;
if ( * V_127 > V_343 )
* V_127 = V_343 ;
return F_273 ( V_345 ) ;
}
void F_274 ( void * V_348 )
{
F_275 ( V_348 ) ;
}
void F_276 ( struct V_7 * V_20 )
{
F_145 ( & V_20 -> V_349 ) ;
}
void F_277 ( struct V_7 * V_20 )
{
if ( F_111 ( F_43 ( & V_20 -> V_349 ) <= 0 ) )
return;
F_32 ( & V_20 -> V_349 ) ;
}
int F_278 ( struct V_7 * V_20 , char * V_350 , T_6 V_351 )
{
T_7 V_352 = 0xff ;
T_7 V_353 = 0 ;
unsigned char * V_354 , * V_355 ;
unsigned char T_8 * V_356 ;
int V_357 = - V_163 ;
F_279 () ;
V_356 = F_280 ( V_20 -> V_356 ) ;
if ( ! V_356 ) {
F_281 () ;
return - V_358 ;
}
if ( V_351 < 21 ) {
F_281 () ;
return - V_163 ;
}
memset ( V_350 , 0 , V_351 ) ;
V_354 = V_356 + 4 ;
while ( V_354 < V_356 + V_20 -> V_359 ) {
if ( ( V_354 [ 1 ] & 0x30 ) != 0x00 )
goto V_360;
switch ( V_354 [ 1 ] & 0xf ) {
case 0x1 :
if ( V_353 > V_354 [ 3 ] )
break;
if ( V_352 > 0x01 && V_352 != 0xff )
break;
V_353 = V_354 [ 3 ] ;
if ( V_353 + 4 > V_351 )
V_353 = V_351 - 4 ;
V_355 = V_354 + 4 ;
V_352 = V_354 [ 1 ] & 0xf ;
V_357 = snprintf ( V_350 , V_351 , L_31 ,
V_353 , V_355 ) ;
break;
case 0x2 :
if ( V_353 > V_354 [ 3 ] )
break;
if ( V_352 == 0x3 &&
V_353 == V_354 [ 3 ] )
break;
V_353 = V_354 [ 3 ] ;
V_355 = V_354 + 4 ;
V_352 = V_354 [ 1 ] & 0xf ;
switch ( V_353 ) {
case 8 :
V_357 = snprintf ( V_350 , V_351 ,
L_32 ,
V_355 ) ;
break;
case 12 :
V_357 = snprintf ( V_350 , V_351 ,
L_33 ,
V_355 ) ;
break;
case 16 :
V_357 = snprintf ( V_350 , V_351 ,
L_34 ,
V_355 ) ;
break;
default:
V_353 = 0 ;
break;
}
break;
case 0x3 :
if ( V_353 > V_354 [ 3 ] )
break;
V_353 = V_354 [ 3 ] ;
V_355 = V_354 + 4 ;
V_352 = V_354 [ 1 ] & 0xf ;
switch ( V_353 ) {
case 8 :
V_357 = snprintf ( V_350 , V_351 ,
L_35 ,
V_355 ) ;
break;
case 16 :
V_357 = snprintf ( V_350 , V_351 ,
L_36 ,
V_355 ) ;
break;
default:
V_353 = 0 ;
break;
}
break;
case 0x8 :
if ( V_353 + 4 > V_354 [ 3 ] )
break;
if ( V_353 && V_354 [ 3 ] > V_351 )
break;
V_353 = V_357 = V_354 [ 3 ] ;
V_355 = V_354 + 4 ;
V_352 = V_354 [ 1 ] & 0xf ;
if ( V_353 >= V_351 )
V_353 = V_351 - 1 ;
memcpy ( V_350 , V_355 , V_353 ) ;
if ( V_353 != V_357 )
V_353 = 6 ;
break;
default:
break;
}
V_360:
V_354 += V_354 [ 3 ] + 4 ;
}
F_281 () ;
return V_357 ;
}
int F_282 ( struct V_7 * V_20 , int * V_361 )
{
unsigned char * V_354 ;
unsigned char T_8 * V_356 ;
int V_362 = - V_363 , V_364 = - 1 ;
F_279 () ;
V_356 = F_280 ( V_20 -> V_356 ) ;
if ( ! V_356 ) {
F_281 () ;
return - V_358 ;
}
V_354 = V_20 -> V_356 + 4 ;
while ( V_354 < V_20 -> V_356 + V_20 -> V_359 ) {
switch ( V_354 [ 1 ] & 0xf ) {
case 0x4 :
V_364 = F_283 ( & V_354 [ 6 ] ) ;
break;
case 0x5 :
V_362 = F_283 ( & V_354 [ 6 ] ) ;
break;
default:
break;
}
V_354 += V_354 [ 3 ] + 4 ;
}
F_281 () ;
if ( V_362 >= 0 && V_361 && V_364 != - 1 )
* V_361 = V_364 ;
return V_362 ;
}
