static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 ,
enum V_7 V_8 )
{
enum V_9 V_10 ;
V_10 = V_11 ;
V_10 = F_2 ( V_4 , V_6 , V_8 ,
V_10 ) ;
switch ( V_10 ) {
case V_11 :
F_3 ( & V_2 -> V_12 -> V_13 ,
L_1
L_2 ,
V_14 , V_4 , V_6 , V_8 ) ;
V_4 -> V_15 = NULL ;
F_4 ( V_2 , V_4 , V_4 -> V_16 ) ;
break;
case V_17 :
F_3 ( & V_2 -> V_12 -> V_13 ,
L_3
L_2 ,
V_14 , V_4 , V_6 , V_8 ) ;
break;
case V_18 :
F_3 ( & V_2 -> V_12 -> V_13 ,
L_4
L_2 ,
V_14 , V_4 , V_6 , V_8 ) ;
F_4 ( V_2 , V_4 , V_19 ) ;
break;
default:
F_3 ( & V_2 -> V_12 -> V_13 ,
L_5 ,
V_14 ) ;
V_19 ( V_4 ) ;
break;
}
}
static inline int F_5 ( struct V_20 * V_21 ,
struct V_3 * V_4 )
{
return V_21 ? F_6 ( V_22 , & V_21 -> V_23 ) ||
( F_6 ( V_24 , & V_21 -> V_23 ) &&
F_7 ( V_4 ) )
: 0 ;
}
int F_8 ( struct V_3 * V_4 , int V_25 , T_1 V_26 )
{
struct V_1 * V_2 = F_9 ( V_4 -> V_13 ) ;
struct V_20 * V_21 ;
unsigned long V_23 ;
bool V_27 ;
T_2 V_28 ;
F_3 ( & V_2 -> V_12 -> V_13 , L_6 , V_14 , V_25 ) ;
F_10 (num, task) {
enum V_29 V_8 = V_30 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_21 = F_12 ( V_4 -> V_13 ) ;
V_27 = F_5 ( V_21 , V_4 ) ;
V_28 = F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_7 ,
V_4 , V_25 , V_4 -> V_13 , V_21 , V_21 ? V_21 -> V_23 : 0 ,
V_4 -> V_32 ) ;
if ( ! V_21 ) {
F_1 ( V_2 , V_4 , V_33 ,
V_34 ) ;
} else if ( ! V_27 || V_28 == V_35 ) {
F_1 ( V_2 , V_4 , V_36 ,
V_37 ) ;
} else {
F_11 ( & V_4 -> V_38 , V_23 ) ;
if ( V_4 -> V_39 & V_40 ) {
F_14 ( & V_4 -> V_38 ,
V_23 ) ;
F_1 ( V_2 , V_4 ,
V_33 ,
V_41 ) ;
} else {
V_4 -> V_39 |= V_42 ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_8 = F_15 ( V_2 , V_21 , V_4 , V_28 ) ;
if ( V_8 != V_43 ) {
F_11 ( & V_4 -> V_38 , V_23 ) ;
V_4 -> V_39 &= ~ V_42 ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
if ( F_6 ( V_44 , & V_21 -> V_23 ) ) {
F_1 ( V_2 , V_4 ,
V_33 ,
V_34 ) ;
} else {
F_1 ( V_2 , V_4 ,
V_36 ,
V_37 ) ;
}
}
}
}
if ( V_8 != V_43 && V_28 != V_35 ) {
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_16 ( V_2 , F_17 ( V_28 ) ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
}
F_18 ( V_21 ) ;
}
return 0 ;
}
static enum V_29 F_19 ( struct V_45 * V_46 )
{
struct V_47 * V_47 ;
enum V_29 V_8 ;
if ( ! F_6 ( V_48 , & V_46 -> V_23 ) )
return V_30 ;
V_47 = F_20 ( V_46 ) ;
switch ( V_47 -> V_49 ) {
case V_50 :
case V_51 : {
struct V_52 * V_53 = & V_46 -> V_54 . V_55 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_56 = 0x27 ;
V_53 -> V_23 &= ~ 0x80 ;
V_53 -> V_23 &= 0xF0 ;
if ( V_47 -> V_49 == V_50 )
V_53 -> V_57 |= V_58 ;
else
V_53 -> V_57 &= ~ V_58 ;
break;
}
default:
return V_30 ;
}
V_8 = F_21 ( V_46 ) ;
return V_8 ;
}
static struct V_45 * F_22 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_2 V_28 , struct V_47 * V_47 )
{
enum V_29 V_8 = V_30 ;
struct V_45 * V_46 = NULL ;
struct V_59 * V_13 ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_8 , V_14 , V_47 ) ;
V_13 = V_21 -> V_60 ;
V_46 = F_23 ( V_2 , V_47 , V_28 ) ;
if ( ! V_46 )
return NULL ;
V_8 = F_24 ( V_2 , V_21 , V_28 ,
V_46 ) ;
if ( V_8 != V_43 ) {
F_25 ( & V_2 -> V_12 -> V_13 ,
L_9
L_10 ,
V_14 ,
V_8 ) ;
return NULL ;
}
if ( V_13 -> V_61 == V_62 ) {
V_47 -> V_63 = V_64 ;
V_8 = F_26 ( V_46 ) ;
if ( V_8 != V_43 )
return NULL ;
}
if ( V_13 -> V_61 == V_65 || ( V_13 -> V_66 & V_67 ) ) {
V_47 -> V_63 = V_68 ;
V_8 = F_19 ( V_46 ) ;
if ( V_8 != V_43 )
return NULL ;
}
return V_46 ;
}
static void F_27 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_69 * V_70 = NULL ;
struct V_69 * V_71 ;
V_46 -> V_8 = V_72 ;
V_71 = V_46 -> V_73 ;
V_46 -> V_73 = NULL ;
if ( F_6 ( V_48 , & V_46 -> V_23 ) ) {
struct V_47 * V_74 = F_20 ( V_46 ) ;
if ( V_74 ) {
V_70 = V_74 -> V_75 ;
V_74 -> V_75 = NULL ;
}
V_46 -> V_76 . V_77 = NULL ;
F_3 ( & V_2 -> V_12 -> V_13 , L_11 ,
V_14 , V_74 -> V_49 , V_74 -> V_78 ) ;
} else {
struct V_3 * V_4 = F_28 ( V_46 ) ;
if ( V_4 )
V_4 -> V_15 = NULL ;
V_46 -> V_76 . V_79 = NULL ;
}
F_25 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_46 -> V_78 ) ;
if ( V_71 )
V_75 ( V_71 ) ;
if ( V_70 != NULL )
V_75 ( V_70 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_47 * V_74 , unsigned long V_80 )
{
F_30 ( V_69 ) ;
enum V_81 V_8 = V_82 ;
struct V_45 * V_46 ;
int V_83 = V_84 ;
unsigned long V_23 ;
unsigned long V_85 ;
T_2 V_28 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_28 = F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( V_28 == V_35 )
return V_83 ;
if ( ! V_21 ||
( ! F_6 ( V_22 , & V_21 -> V_23 ) &&
! F_6 ( V_24 , & V_21 -> V_23 ) ) ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_13 ,
V_14 ,
V_21 , V_21 ? V_21 -> V_23 : 0 ) ;
goto V_86;
} else
F_3 ( & V_2 -> V_12 -> V_13 ,
L_14 ,
V_14 , V_21 ) ;
V_74 -> V_75 = & V_69 ;
V_74 -> V_8 = V_87 ;
V_46 = F_22 ( V_2 , V_21 , V_28 , V_74 ) ;
if ( ! V_46 )
goto V_86;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_8 = F_31 ( V_2 , V_21 , V_46 ) ;
if ( V_8 != V_88 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_15 ,
V_14 ,
V_8 ,
V_46 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
goto V_86;
}
if ( V_74 -> V_89 != NULL )
V_74 -> V_89 ( V_90 , V_74 , V_74 -> V_91 ) ;
F_32 ( V_46 , V_92 ) ;
F_33 ( & V_46 -> V_93 , & V_21 -> V_94 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
V_85 = F_34 ( & V_69 ,
F_35 ( V_80 ) ) ;
if ( V_85 == 0 ) {
F_11 ( & V_2 -> V_31 , V_23 ) ;
if ( V_74 -> V_89 != NULL )
V_74 -> V_89 ( V_95 , V_74 ,
V_74 -> V_91 ) ;
F_36 ( V_2 , V_21 , V_46 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
V_85 = F_34 (
& V_69 ,
F_35 ( V_96 ) ) ;
if ( ! V_85 ) {
F_11 ( & V_2 -> V_31 , V_23 ) ;
if ( V_74 -> V_8 == V_87 )
F_27 ( V_2 , V_46 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
}
}
F_37 ( V_2 , V_74 ) ;
if ( V_74 -> V_8 == V_43 )
V_83 = V_97 ;
else if ( V_74 -> V_8 == V_98 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_16
L_17 ,
V_14 ) ;
V_83 = V_97 ;
}
F_3 ( & V_2 -> V_12 -> V_13 ,
L_18 ,
V_14 ,
V_46 ) ;
return V_83 ;
V_86:
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_16 ( V_2 , F_17 ( V_28 ) ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
return V_83 ;
}
static void F_38 ( struct V_47 * V_74 ,
enum V_99 V_100 ,
void (* F_39)( enum V_101 ,
struct V_47 * ,
void * ) ,
void * V_91 )
{
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_49 = V_100 ;
V_74 -> V_89 = F_39 ;
V_74 -> V_91 = V_91 ;
}
static void F_40 ( struct V_47 * V_74 ,
enum V_99 V_100 ,
void (* F_39)( enum V_101 ,
struct V_47 * ,
void * ) ,
struct V_45 * V_102 )
{
F_38 ( V_74 , V_100 , F_39 , V_102 ) ;
V_74 -> V_78 = V_102 -> V_78 ;
}
static enum V_103 F_41 (
struct V_45 * V_45 ,
struct V_1 * V_1 ,
struct V_20 * V_104 ,
struct V_69 * V_105 )
{
enum V_103 V_106 = V_107 ;
if ( V_45 && ! F_42 ( & V_45 -> V_93 ) ) {
V_106 = F_43 (
V_45 , V_105 ) ;
}
return V_106 ;
}
static int F_44 ( enum V_103 V_108 )
{
switch ( V_108 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_72 :
return true ;
default:
return false ;
}
}
static void F_45 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_45 * V_45 )
{
enum V_29 V_8 = V_43 ;
bool V_113 = false ;
bool V_114 = false ;
unsigned long V_23 ;
unsigned long V_115 = 1 ;
struct V_69 * V_73 ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_19 ,
V_14 , V_21 , V_45 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_73 = V_45 -> V_73 ;
F_46 ( V_116 , & V_45 -> V_23 ) ;
if ( ! F_6 ( V_117 , & V_45 -> V_23 ) ) {
V_113 = true ;
V_114 = true ;
V_8 = F_36 ( V_2 ,
V_21 ,
V_45 ) ;
}
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( V_8 != V_43 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_20
L_21 ,
V_14 , V_8 ) ;
V_45 -> V_73 = NULL ;
} else {
if ( V_113 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_22 ,
V_14 , V_45 , V_73 ) ;
V_115
= F_34 (
V_73 ,
F_35 ( V_96 ) ) ;
if ( ! V_115 ) {
F_11 ( & V_2 -> V_31 , V_23 ) ;
if ( ! F_6 ( V_117 ,
& V_45 -> V_23 ) ) {
F_27 ( V_2 ,
V_45 ) ;
V_114 = true ;
} else
V_115 = 1 ;
F_14 ( & V_2 -> V_31 ,
V_23 ) ;
if ( ! V_115 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_23
L_24 ,
V_14 , V_73 ,
V_45 ) ;
V_45 = NULL ;
}
}
if ( V_115 )
F_3 ( & V_2 -> V_12 -> V_13 ,
L_25 ,
V_14 , V_45 , V_73 ) ;
}
if ( V_115 ) {
V_45 -> V_73 = NULL ;
F_11 ( & V_45 -> V_118 , V_23 ) ;
V_114
= F_44 (
V_45 -> V_8 ) ;
F_14 ( & V_45 -> V_118 , V_23 ) ;
}
if ( V_114 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_26 ,
V_14 , V_21 , V_45 ) ;
if ( V_45 != NULL ) {
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_47 ( V_2 , V_45 -> V_78 ) ;
F_32 ( V_45 , V_107 ) ;
F_48 ( & V_45 -> V_93 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
}
}
}
}
void F_49 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_69 V_119 ;
enum V_103 V_106 ;
unsigned long V_23 ;
F_50 ( V_120 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_51 ( & V_21 -> V_94 , & V_120 ) ;
while ( ! F_42 ( & V_120 ) ) {
struct V_45 * V_46 = F_52 ( V_120 . V_121 , F_53 ( * V_46 ) , V_93 ) ;
V_106 = F_54 ( V_46 ,
& V_119 ,
V_111 ) ;
switch ( V_106 ) {
case V_92 :
case V_112 :
case V_110 :
break;
default:
F_55 ( & V_46 -> V_93 , & V_21 -> V_94 ) ;
V_46 = NULL ;
break;
}
if ( ! V_46 )
continue;
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_56 ( & V_119 ) ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_27 ,
V_14 , V_21 , V_46 ,
( ! F_6 ( V_48 , & V_46 -> V_23 )
? F_28 ( V_46 )
: NULL ) ,
V_106 ) ;
F_45 ( V_2 , V_21 , V_46 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
}
F_14 ( & V_2 -> V_31 , V_23 ) ;
}
static int F_57 (
struct V_1 * V_1 ,
struct V_20 * V_104 ,
T_3 * V_122 )
{
struct V_47 V_74 ;
int V_83 = V_84 ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_28 ,
V_14 , V_1 , V_104 ) ;
F_38 ( & V_74 , V_123 , NULL , NULL ) ;
#define F_58 2000
V_83 = F_29 ( V_1 , V_104 , & V_74 , F_58 ) ;
if ( V_83 == V_97 )
F_3 ( & V_1 -> V_12 -> V_13 ,
L_29 ,
V_14 , V_104 ) ;
else
F_3 ( & V_1 -> V_12 -> V_13 ,
L_30 ,
V_14 , V_104 , V_83 ) ;
return V_83 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_20 * V_21 , T_3 * V_122 )
{
int V_83 = V_84 ;
struct V_47 V_74 ;
#define F_60 25000
F_38 ( & V_74 , V_50 , NULL , NULL ) ;
V_83 = F_29 ( V_2 , V_21 , & V_74 , F_60 ) ;
if ( V_83 != V_97 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_31 ,
V_14 , V_21 , V_83 ) ;
}
return V_83 ;
}
int F_61 ( struct V_59 * V_59 , T_3 * V_122 )
{
struct V_1 * V_1 = F_9 ( V_59 ) ;
struct V_20 * V_104 ;
unsigned long V_23 ;
int V_83 ;
F_11 ( & V_1 -> V_31 , V_23 ) ;
V_104 = F_12 ( V_59 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_32 ,
V_14 , V_59 , V_1 , V_104 ) ;
if ( ! V_104 ) {
F_3 ( & V_1 -> V_12 -> V_13 , L_33 , V_14 ) ;
V_83 = V_97 ;
goto V_124;
}
F_46 ( V_125 , & V_104 -> V_23 ) ;
if ( F_62 ( V_59 -> V_66 ) ) {
V_83 = F_59 ( V_1 , V_104 , V_122 ) ;
} else
V_83 = F_57 ( V_1 , V_104 , V_122 ) ;
if ( V_83 == V_97 )
F_49 ( V_1 ,
V_104 ) ;
V_124:
F_18 ( V_104 ) ;
return V_83 ;
}
int F_63 ( struct V_126 * V_127 )
{
return V_84 ;
}
int F_64 ( struct V_128 * V_129 )
{
return V_84 ;
}
static void F_65 (
enum V_101 V_130 ,
struct V_47 * V_74 ,
void * V_91 )
{
struct V_45 * V_102 ;
V_102 = (struct V_45 * ) V_91 ;
F_3 ( & V_102 -> V_1 -> V_12 -> V_13 ,
L_34 ,
V_14 , V_74 , V_102 ) ;
switch ( V_130 ) {
case V_90 :
if ( ( V_102 -> V_8 != V_109 )
&& ( V_102 -> V_8 != V_112 ) )
F_3 ( & V_102 -> V_1 -> V_12 -> V_13 ,
L_35 ,
V_14 , V_102 -> V_8 , V_74 , V_102 ) ;
break;
case V_95 :
F_32 ( V_102 , V_110 ) ;
break;
default:
F_3 ( & V_102 -> V_1 -> V_12 -> V_13 ,
L_36 ,
V_14 , V_130 , V_74 , V_102 ) ;
break;
}
}
int F_66 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_9 ( V_4 -> V_13 ) ;
F_30 ( V_105 ) ;
struct V_45 * V_102 = NULL ;
enum V_103 V_106 ;
struct V_20 * V_104 = NULL ;
struct V_47 V_74 ;
int V_83 = V_84 ;
unsigned long V_23 ;
int V_131 = 0 ;
F_11 ( & V_1 -> V_31 , V_23 ) ;
F_67 ( & V_4 -> V_38 ) ;
V_102 = V_4 -> V_15 ;
if ( ! ( V_4 -> V_39 & V_132 ) &&
( V_4 -> V_39 & V_42 ) &&
V_102 )
V_104 = F_12 ( V_4 -> V_13 ) ;
F_68 ( & V_4 -> V_38 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_37 ,
V_14 , V_104 , V_4 , V_102 ) ;
if ( V_104 )
F_46 ( V_125 , & V_104 -> V_23 ) ;
if ( ! V_104 || ! V_102 ) {
F_11 ( & V_4 -> V_38 , V_23 ) ;
V_4 -> V_39 |= V_132 ;
V_4 -> V_39 &= ~ ( V_42 |
V_133 ) ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_83 = V_97 ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_38 ,
V_14 , V_4 ) ;
goto V_124;
}
F_11 ( & V_1 -> V_31 , V_23 ) ;
V_106 = F_41 (
V_102 , V_1 , V_104 ,
& V_105 ) ;
if ( ( V_106 != V_92 ) &&
( V_106 != V_112 ) &&
( V_106 != V_110 ) ) {
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_39 ,
V_14 ,
V_104 , V_102 ) ;
V_83 = V_97 ;
goto V_124;
}
if ( V_4 -> V_134 == V_135 ||
F_62 ( V_4 -> V_134 ) ||
F_6 ( V_116 , & V_102 -> V_23 ) ) {
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_40
L_41 ,
V_14 ,
( ( V_4 -> V_134 == V_135 )
? L_42
: ( F_62 ( V_4 -> V_134 )
? L_43
: L_44 )
) ,
F_6 ( V_116 , & V_102 -> V_23 ) ) ;
if ( F_6 ( V_116 , & V_102 -> V_23 ) ) {
F_11 ( & V_4 -> V_38 , V_23 ) ;
V_4 -> V_39 |= V_132 ;
V_4 -> V_39 &= ~ ( V_42 |
V_133 ) ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_83 = V_97 ;
} else {
F_11 ( & V_4 -> V_38 , V_23 ) ;
V_4 -> V_39 &= ~ ( V_42 |
V_133 ) ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
}
V_131 = 1 ;
} else {
F_40 ( & V_74 , V_136 ,
F_65 ,
V_102 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
#define F_69 500
V_83 = F_29 ( V_1 , V_104 , & V_74 ,
F_69 ) ;
if ( V_83 == V_97 )
V_131 = 1 ;
else
F_3 ( & V_1 -> V_12 -> V_13 ,
L_45 , V_14 ) ;
}
if ( V_131 ) {
F_46 ( V_116 , & V_102 -> V_23 ) ;
F_45 ( V_1 , V_104 ,
V_102 ) ;
}
V_102 -> V_73 = NULL ;
V_124:
F_18 ( V_104 ) ;
return V_83 ;
}
int F_70 (
struct V_59 * V_137 ,
T_3 * V_122 )
{
return V_84 ;
}
int F_71 (
struct V_59 * V_137 ,
T_3 * V_122 )
{
return V_84 ;
}
int F_72 (
struct V_59 * V_137 ,
T_3 * V_122 )
{
return V_84 ;
}
int F_73 (
struct V_3 * V_4 )
{
if ( V_4 -> V_39 & V_138 )
return V_84 ;
else
return V_139 ;
}
void
F_74 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
enum V_81 V_140 )
{
struct V_47 * V_74 = F_20 ( V_46 ) ;
struct V_69 * V_141 = NULL ;
struct V_69 * V_142 = V_46 -> V_73 ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_46 ,
V_14 , V_46 , V_140 ) ;
F_32 ( V_46 , V_112 ) ;
F_46 ( V_116 , & V_46 -> V_23 ) ;
if ( V_74 ) {
V_74 -> V_8 = V_140 ;
if ( V_74 -> V_63 == V_64 ) {
memcpy ( & V_74 -> V_143 . V_144 ,
& V_46 -> V_145 . V_146 ,
V_147 ) ;
} else if ( V_74 -> V_63 == V_68 ) {
memcpy ( & V_74 -> V_143 . V_148 ,
& V_46 -> V_54 . V_146 ,
sizeof( struct V_149 ) ) ;
}
V_141 = V_74 -> V_75 ;
}
F_75 ( V_2 , V_46 -> V_150 , V_46 ) ;
F_46 ( V_117 , & V_46 -> V_23 ) ;
if ( ( V_46 -> V_8 == V_112 ) ||
! F_44 ( V_46 -> V_8 ) ) {
F_32 ( V_46 , V_107 ) ;
F_47 ( V_2 , V_46 -> V_78 ) ;
F_48 ( & V_46 -> V_93 ) ;
}
if ( V_142 )
V_75 ( V_142 ) ;
if ( V_141 )
V_75 ( V_141 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_151 * V_152 = F_77 ( V_21 -> V_60 ) ;
enum V_29 V_8 ;
unsigned long V_23 ;
int V_153 ;
F_3 ( & V_2 -> V_12 -> V_13 , L_47 , V_14 , V_21 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_8 = F_78 ( V_21 ) ;
if ( V_8 != V_43 ) {
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_48 ,
V_14 , V_21 , V_8 ) ;
return V_84 ;
}
F_14 ( & V_2 -> V_31 , V_23 ) ;
V_153 = F_79 ( V_152 , true ) ;
F_80 ( V_2 , V_21 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_8 = F_81 ( V_21 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( V_8 != V_43 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_49
L_50 , V_14 , V_21 , V_8 ) ;
}
F_3 ( & V_2 -> V_12 -> V_13 , L_51 , V_14 , V_21 ) ;
return V_153 ;
}
int F_82 ( struct V_59 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_20 * V_21 ;
unsigned long V_23 ;
int V_83 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_21 = F_12 ( V_13 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( ! V_21 || ! F_6 ( V_125 , & V_21 -> V_23 ) ) {
V_83 = V_97 ;
goto V_124;
}
V_83 = F_76 ( V_2 , V_21 ) ;
V_124:
F_18 ( V_21 ) ;
return V_83 ;
}
int F_83 ( struct V_154 * V_55 )
{
struct V_59 * V_13 = F_84 ( V_55 -> V_155 ) ;
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_20 * V_21 ;
unsigned long V_23 ;
int V_83 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_21 = F_12 ( V_13 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( ! V_21 ) {
V_83 = V_97 ;
goto V_124;
}
V_83 = F_76 ( V_2 , V_21 ) ;
V_124:
F_18 ( V_21 ) ;
return V_83 ;
}
