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
F_1 ( V_2 , V_4 ,
V_36 ,
V_37 ) ;
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
static enum V_29 F_19 ( struct V_44 * V_45 )
{
struct V_46 * V_46 ;
enum V_29 V_8 ;
if ( V_47 != V_45 -> V_48 )
return V_30 ;
V_46 = F_20 ( V_45 ) ;
switch ( V_46 -> V_49 ) {
case V_50 :
case V_51 : {
struct V_52 * V_53 = & V_45 -> V_54 . V_55 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_56 = 0x27 ;
V_53 -> V_23 &= ~ 0x80 ;
V_53 -> V_23 &= 0xF0 ;
if ( V_46 -> V_49 == V_50 )
V_53 -> V_57 |= V_58 ;
else
V_53 -> V_57 &= ~ V_58 ;
break;
}
default:
return V_30 ;
}
V_8 = F_21 ( V_45 ) ;
return V_8 ;
}
static struct V_44 * F_22 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_2 V_28 , struct V_46 * V_46 )
{
enum V_29 V_8 = V_30 ;
struct V_44 * V_45 = NULL ;
struct V_59 * V_13 ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_8 , V_14 , V_46 ) ;
V_13 = V_21 -> V_60 ;
V_45 = F_23 ( V_2 , V_46 , V_28 ) ;
if ( ! V_45 )
return NULL ;
V_8 = F_24 ( V_2 , V_21 , V_28 ,
V_45 ) ;
if ( V_8 != V_43 ) {
F_25 ( & V_2 -> V_12 -> V_13 ,
L_9
L_10 ,
V_14 ,
V_8 ) ;
return NULL ;
}
if ( V_13 -> V_61 == V_62 ) {
V_46 -> V_63 = V_64 ;
V_8 = F_26 ( V_45 ) ;
if ( V_8 != V_43 )
return NULL ;
}
if ( V_13 -> V_61 == V_65 || ( V_13 -> V_66 & V_67 ) ) {
V_46 -> V_63 = V_68 ;
V_8 = F_19 ( V_45 ) ;
if ( V_8 != V_43 )
return NULL ;
}
return V_45 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_46 * V_69 , unsigned long V_70 )
{
F_28 ( V_71 ) ;
enum V_72 V_8 = V_73 ;
struct V_44 * V_45 ;
int V_74 = V_75 ;
unsigned long V_23 ;
unsigned long V_76 ;
T_2 V_28 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_28 = F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( V_28 == V_35 )
return V_74 ;
if ( ! V_21 ||
( ! F_6 ( V_22 , & V_21 -> V_23 ) &&
! F_6 ( V_24 , & V_21 -> V_23 ) ) ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_11 ,
V_14 ,
V_21 , V_21 ? V_21 -> V_23 : 0 ) ;
goto V_77;
} else
F_3 ( & V_2 -> V_12 -> V_13 ,
L_12 ,
V_14 , V_21 ) ;
V_69 -> V_78 = & V_71 ;
V_45 = F_22 ( V_2 , V_21 , V_28 , V_69 ) ;
if ( ! V_45 )
goto V_77;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_8 = F_29 ( V_2 , V_21 , V_45 ) ;
if ( V_8 != V_79 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_13 ,
V_14 ,
V_8 ,
V_45 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
goto V_77;
}
if ( V_69 -> V_80 != NULL )
V_69 -> V_80 ( V_81 , V_69 , V_69 -> V_82 ) ;
F_30 ( V_45 , V_83 ) ;
F_31 ( & V_45 -> V_84 , & V_21 -> V_85 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
V_76 = F_32 ( & V_71 ,
F_33 ( V_70 ) ) ;
if ( V_76 == 0 ) {
F_11 ( & V_2 -> V_31 , V_23 ) ;
if ( V_69 -> V_80 != NULL )
V_69 -> V_80 ( V_86 , V_69 , V_69 -> V_82 ) ;
F_34 ( V_2 ,
V_21 ,
V_45 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_35 ( V_69 -> V_78 ) ;
}
F_36 ( V_69 ) ;
if ( V_69 -> V_8 == V_43 )
V_74 = V_87 ;
else if ( V_69 -> V_8 == V_88 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_14
L_15 ,
V_14 ) ;
V_74 = V_87 ;
}
F_3 ( & V_2 -> V_12 -> V_13 ,
L_16 ,
V_14 ,
V_45 ) ;
return V_74 ;
V_77:
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_16 ( V_2 , F_17 ( V_28 ) ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
return V_74 ;
}
static void F_37 ( struct V_46 * V_69 ,
enum V_89 V_90 ,
void (* F_38)( enum V_91 ,
struct V_46 * ,
void * ) ,
void * V_82 )
{
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> V_49 = V_90 ;
V_69 -> V_80 = F_38 ;
V_69 -> V_82 = V_82 ;
}
static void F_39 ( struct V_46 * V_69 ,
enum V_89 V_90 ,
void (* F_38)( enum V_91 ,
struct V_46 * ,
void * ) ,
struct V_44 * V_92 )
{
F_37 ( V_69 , V_90 , F_38 , V_92 ) ;
V_69 -> V_93 = V_92 -> V_93 ;
}
static enum V_94 F_40 (
struct V_44 * V_44 ,
struct V_1 * V_1 ,
struct V_20 * V_95 ,
struct V_71 * V_96 )
{
enum V_94 V_97 = V_98 ;
if ( V_44 && ! F_41 ( & V_44 -> V_84 ) ) {
V_97 = F_42 (
V_44 , V_96 ) ;
}
return V_97 ;
}
static void F_43 (
struct V_1 * V_1 ,
struct V_20 * V_95 ,
struct V_44 * V_44 ,
struct V_3 * V_4 )
{
unsigned long V_23 ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_17 ,
V_14 , V_95 , V_44 , V_4 ) ;
if ( V_4 != NULL ) {
F_11 ( & V_4 -> V_38 , V_23 ) ;
V_4 -> V_15 = NULL ;
V_4 -> V_39 &= ~ V_99 ;
F_44 ( V_4 ) ;
if ( ! ( V_4 -> V_39 & V_40 ) ) {
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_4 -> V_16 ( V_4 ) ;
} else
F_14 ( & V_4 -> V_38 , V_23 ) ;
}
if ( V_44 != NULL ) {
F_11 ( & V_1 -> V_31 , V_23 ) ;
F_45 ( & V_44 -> V_84 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_44 * V_44 )
{
enum V_29 V_8 = V_43 ;
bool V_100 = false ;
bool V_101 = false ;
enum V_94 V_102 ;
unsigned long V_23 ;
unsigned long V_103 = 1 ;
struct V_71 * V_104 ;
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_18 ,
V_14 , V_21 , V_44 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_104 = V_44 -> V_104 ;
V_4 = ( V_44 -> V_48 == V_105 )
? F_47 ( V_44 )
: NULL ;
F_48 ( V_106 , & V_44 -> V_23 ) ;
if ( ! F_6 ( V_107 , & V_44 -> V_23 ) ) {
V_100 = true ;
V_101 = true ;
V_8 = F_34 ( V_2 ,
V_21 ,
V_44 ) ;
}
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( V_8 != V_43 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_19
L_20 ,
V_14 , V_8 ) ;
V_44 -> V_104 = NULL ;
} else {
if ( V_100 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_21 ,
V_14 , V_44 , V_104 ) ;
#define F_49 500
V_103
= F_32 (
V_104 ,
F_33 ( F_49 ) ) ;
if ( ! V_103 ) {
F_11 ( & V_2 -> V_31 ,
V_23 ) ;
if ( ! F_6 ( V_107 , & V_44 -> V_23 ) ) {
V_44 -> V_8 = V_108 ;
V_44 -> V_104
= NULL ;
if ( V_44 -> V_48 == V_105 ) {
V_44 -> V_109 . V_110
= NULL ;
}
} else
V_103 = 1 ;
F_14 ( & V_2 -> V_31 ,
V_23 ) ;
if ( ! V_103 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_22
L_23 ,
V_14 , V_104 ,
V_44 ) ;
V_44 = NULL ;
}
}
if ( V_103 )
F_3 ( & V_2 -> V_12 -> V_13 ,
L_24 ,
V_14 , V_44 , V_104 ) ;
}
if ( V_103 ) {
V_44 -> V_104 = NULL ;
F_11 ( & V_44 -> V_111 , V_23 ) ;
V_102 = V_44 -> V_8 ;
if ( ( V_44 -> V_48 == V_105 )
&& ( ( V_102 == V_112 )
|| ( V_102 == V_113 )
|| ( V_102 == V_114 )
|| ( V_102 == V_115 )
|| ( V_102 == V_108 )
)
) {
V_101 = true ;
}
F_14 ( & V_44 -> V_111 , V_23 ) ;
}
if ( V_101 )
F_43 (
V_2 , V_21 , V_44 , V_4 ) ;
}
}
void F_50 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_71 V_116 ;
enum V_94 V_97 ;
unsigned long V_23 ;
F_51 ( V_117 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_52 ( & V_21 -> V_85 , & V_117 ) ;
while ( ! F_41 ( & V_117 ) ) {
struct V_44 * V_45 = F_53 ( V_117 . V_118 , F_54 ( * V_45 ) , V_84 ) ;
V_97 = F_55 ( V_45 ,
& V_116 ,
V_114 ) ;
switch ( V_97 ) {
case V_83 :
case V_115 :
case V_113 :
break;
default:
F_56 ( & V_45 -> V_84 , & V_21 -> V_85 ) ;
V_45 = NULL ;
break;
}
if ( ! V_45 )
continue;
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_57 ( & V_116 ) ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_25 ,
V_14 , V_21 , V_45 ,
V_45 -> V_48 == V_105 ? F_47 ( V_45 ) : NULL ,
V_97 ) ;
F_46 ( V_2 , V_21 , V_45 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
}
F_14 ( & V_2 -> V_31 , V_23 ) ;
}
static int F_58 (
struct V_1 * V_1 ,
struct V_20 * V_95 ,
T_3 * V_119 )
{
struct V_46 V_69 ;
int V_74 = V_75 ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_26 ,
V_14 , V_1 , V_95 ) ;
F_37 ( & V_69 , V_120 , NULL , NULL ) ;
#define F_59 2000
V_74 = F_27 ( V_1 , V_95 , & V_69 , F_59 ) ;
if ( V_74 == V_87 )
F_3 ( & V_1 -> V_12 -> V_13 ,
L_27 ,
V_14 , V_95 ) ;
else
F_3 ( & V_1 -> V_12 -> V_13 ,
L_28 ,
V_14 , V_95 , V_74 ) ;
return V_74 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_20 * V_21 , T_3 * V_119 )
{
int V_74 = V_75 ;
struct V_46 V_69 ;
#define F_61 25000
F_37 ( & V_69 , V_50 , NULL , NULL ) ;
V_74 = F_27 ( V_2 , V_21 , & V_69 , F_61 ) ;
if ( V_74 != V_87 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_29 ,
V_14 , V_21 , V_74 ) ;
}
return V_74 ;
}
int F_62 ( struct V_59 * V_59 , T_3 * V_119 )
{
struct V_1 * V_1 = F_9 ( V_59 ) ;
struct V_20 * V_95 ;
unsigned long V_23 ;
int V_74 ;
F_11 ( & V_1 -> V_31 , V_23 ) ;
V_95 = F_12 ( V_59 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_30 ,
V_14 , V_59 , V_1 , V_95 ) ;
if ( V_95 )
F_48 ( V_121 , & V_95 -> V_23 ) ;
if ( ! V_95 ||
F_63 ( V_1 , V_95 ) ) {
F_3 ( & V_1 -> V_12 -> V_13 ,
L_31
L_32 ,
V_14 , V_95 , V_59 ) ;
V_74 = V_75 ;
goto V_122;
}
if ( F_64 ( V_59 -> V_66 ) ) {
V_74 = F_60 ( V_1 , V_95 , V_119 ) ;
} else
V_74 = F_58 ( V_1 , V_95 , V_119 ) ;
if ( V_74 == V_87 )
F_50 ( V_1 ,
V_95 ) ;
V_122:
F_18 ( V_95 ) ;
return V_74 ;
}
int F_65 ( struct V_123 * V_124 )
{
return V_75 ;
}
int F_66 ( struct V_125 * V_126 )
{
return V_75 ;
}
static void F_67 (
enum V_91 V_127 ,
struct V_46 * V_69 ,
void * V_82 )
{
struct V_44 * V_92 ;
V_92 = (struct V_44 * ) V_82 ;
F_3 ( & V_92 -> V_1 -> V_12 -> V_13 ,
L_33 ,
V_14 , V_69 , V_92 ) ;
switch ( V_127 ) {
case V_81 :
if ( ( V_92 -> V_8 != V_112 )
&& ( V_92 -> V_8 != V_115 ) )
F_3 ( & V_92 -> V_1 -> V_12 -> V_13 ,
L_34 ,
V_14 , V_92 -> V_8 , V_69 , V_92 ) ;
break;
case V_86 :
F_30 ( V_92 , V_113 ) ;
break;
default:
F_3 ( & V_92 -> V_1 -> V_12 -> V_13 ,
L_35 ,
V_14 , V_127 , V_69 , V_92 ) ;
break;
}
}
int F_68 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_9 ( V_4 -> V_13 ) ;
F_28 ( V_96 ) ;
struct V_44 * V_92 = NULL ;
enum V_94 V_97 ;
struct V_20 * V_95 = NULL ;
struct V_46 V_69 ;
int V_74 = V_75 ;
unsigned long V_23 ;
bool V_128 = false ;
F_11 ( & V_1 -> V_31 , V_23 ) ;
F_69 ( & V_4 -> V_38 ) ;
V_92 = V_4 -> V_15 ;
if ( ! ( V_4 -> V_39 & V_129 ) &&
( V_4 -> V_39 & V_42 ) &&
V_92 )
V_95 = F_12 ( V_4 -> V_13 ) ;
F_70 ( & V_4 -> V_38 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_36 , V_14 , V_4 ) ;
if ( ! V_95 || ! V_92 )
goto V_122;
F_48 ( V_121 , & V_95 -> V_23 ) ;
if ( F_64 ( V_4 -> V_130 ) ) {
F_3 ( & V_1 -> V_12 -> V_13 ,
L_37
L_38
L_39 , V_4 ) ;
goto V_122;
}
F_3 ( & V_1 -> V_12 -> V_13 ,
L_40 , V_14 , V_92 ) ;
V_128 = F_63 ( V_1 , V_95 ) ;
F_11 ( & V_4 -> V_38 , V_23 ) ;
V_128 = V_128 || ( V_4 -> V_39 & V_99 ) ;
if ( ( V_92 == NULL ) || V_128 ) {
if ( V_128 ) {
V_4 -> V_39 &= ~ V_129 ;
V_4 -> V_39 |= V_99 ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_74 = V_75 ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_41
L_42
L_43
L_44 ,
V_14 , V_4 , V_95 ) ;
} else {
F_44 ( V_4 ) ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_74 = V_87 ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_45 ,
V_14 , V_4 ) ;
}
goto V_122;
} else {
F_14 ( & V_4 -> V_38 , V_23 ) ;
}
F_11 ( & V_1 -> V_31 , V_23 ) ;
V_97 = F_40 (
V_92 , V_1 , V_95 ,
& V_96 ) ;
if ( ( V_97 != V_83 ) &&
( V_97 != V_115 ) &&
( V_97 != V_113 ) ) {
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_46 ,
V_14 ,
V_95 , V_92 ) ;
V_74 = V_87 ;
goto V_122;
}
if ( V_4 -> V_130 == V_131 ||
F_6 ( V_106 , & V_92 -> V_23 ) ) {
F_14 ( & V_1 -> V_31 , V_23 ) ;
F_3 ( & V_1 -> V_12 -> V_13 ,
L_47
L_48 ,
V_14 , ( V_4 -> V_130 == V_131 ) ,
F_6 ( V_106 , & V_92 -> V_23 ) ) ;
F_71 ( V_4 ) ;
V_74 = V_87 ;
} else {
F_39 ( & V_69 , V_132 ,
F_67 ,
V_92 ) ;
F_14 ( & V_1 -> V_31 , V_23 ) ;
#define F_72 500
V_74 = F_27 ( V_1 , V_95 , & V_69 ,
F_72 ) ;
if ( V_74 != V_87 )
F_3 ( & V_1 -> V_12 -> V_13 ,
L_49 ,
V_14 ) ;
}
if ( V_74 == V_87 ) {
F_48 ( V_106 , & V_92 -> V_23 ) ;
F_46 ( V_1 , V_95 , V_92 ) ;
}
V_92 -> V_104 = NULL ;
V_122:
F_18 ( V_95 ) ;
return V_74 ;
}
int F_73 (
struct V_59 * V_133 ,
T_3 * V_119 )
{
return V_75 ;
}
int F_74 (
struct V_59 * V_133 ,
T_3 * V_119 )
{
return V_75 ;
}
int F_75 (
struct V_59 * V_133 ,
T_3 * V_119 )
{
return V_75 ;
}
int F_76 (
struct V_3 * V_4 )
{
if ( V_4 -> V_39 & V_99 )
return V_75 ;
else
return V_134 ;
}
void
F_77 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
enum V_72 V_135 )
{
struct V_46 * V_69 = F_20 ( V_45 ) ;
struct V_71 * V_136 ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_50 ,
V_14 , V_45 , V_135 ) ;
F_30 ( V_45 , V_115 ) ;
V_69 -> V_8 = V_135 ;
F_48 ( V_106 , & V_45 -> V_23 ) ;
if ( V_69 -> V_63 == V_64 ) {
memcpy ( & V_69 -> V_137 . V_138 ,
& V_45 -> V_139 . V_140 ,
V_141 ) ;
} else if ( V_69 -> V_63 == V_68 ) {
memcpy ( & V_69 -> V_137 . V_142 ,
& V_45 -> V_54 . V_140 ,
sizeof( struct V_143 ) ) ;
}
V_136 = V_69 -> V_78 ;
F_78 ( V_2 , V_45 -> V_144 , V_45 ) ;
F_48 ( V_107 , & V_45 -> V_23 ) ;
F_30 ( V_45 , V_98 ) ;
F_45 ( & V_45 -> V_84 ) ;
V_78 ( V_136 ) ;
}
static void F_79 ( unsigned long V_145 )
{
struct V_3 * V_4 = ( void * ) V_145 ;
unsigned long V_23 ;
F_11 ( & V_4 -> V_38 , V_23 ) ;
if ( ! ( V_4 -> V_39 & V_129 ) )
V_4 -> V_39 |= V_40 ;
F_14 ( & V_4 -> V_38 , V_23 ) ;
V_78 ( & V_4 -> V_71 ) ;
}
static void F_80 ( struct V_3 * V_4 )
{
if ( ! F_81 ( & V_4 -> V_146 ) )
return;
V_78 ( & V_4 -> V_71 ) ;
}
static struct V_3 * F_82 ( void )
{
struct V_3 * V_4 = F_83 ( sizeof( * V_4 ) , V_147 ) ;
if ( V_4 ) {
F_84 ( & V_4 -> V_117 ) ;
F_85 ( & V_4 -> V_38 ) ;
V_4 -> V_39 = V_148 ;
F_86 ( & V_4 -> V_146 ) ;
F_57 ( & V_4 -> V_71 ) ;
}
return V_4 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 ) {
F_88 ( ! F_41 ( & V_4 -> V_117 ) ) ;
F_89 ( V_4 ) ;
}
}
static int F_90 ( struct V_1 * V_2 ,
struct V_59 * V_13 , void * V_149 ,
int V_150 , void * V_137 , int V_151 )
{
int V_152 , V_153 ;
struct V_3 * V_4 = NULL ;
for ( V_153 = 0 ; V_153 < 3 ; V_153 ++ ) {
V_4 = F_82 () ;
if ( ! V_4 )
return - V_154 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_130 = V_13 -> V_66 ;
F_91 ( & V_4 -> V_155 . V_156 , V_149 , V_150 ) ;
F_91 ( & V_4 -> V_155 . V_157 , V_137 , V_151 ) ;
V_4 -> V_16 = F_80 ;
V_4 -> V_146 . V_158 = ( unsigned long ) V_4 ;
V_4 -> V_146 . V_159 = F_79 ;
V_4 -> V_146 . V_160 = V_161 + 10 * V_162 ;
F_92 ( & V_4 -> V_146 ) ;
V_152 = F_8 ( V_4 , 1 , V_147 ) ;
if ( V_152 ) {
F_81 ( & V_4 -> V_146 ) ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_51 ,
V_14 , V_152 ) ;
goto V_163;
}
F_35 ( & V_4 -> V_71 ) ;
V_152 = - V_164 ;
if ( ( V_4 -> V_39 & V_40 ) ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_52 ,
V_14 ) ;
F_68 ( V_4 ) ;
if ( ! ( V_4 -> V_39 & V_129 ) ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_53 ,
V_14 ) ;
goto V_163;
}
}
if ( V_4 -> V_165 . V_137 == V_36 &&
V_4 -> V_165 . V_166 == V_167 ) {
V_152 = 0 ;
break;
}
if ( V_4 -> V_165 . V_137 == V_36 &&
V_4 -> V_165 . V_166 == V_168 ) {
V_152 = V_4 -> V_165 . V_169 ;
break;
}
if ( V_4 -> V_165 . V_137 == V_36 &&
V_4 -> V_165 . V_166 == V_170 ) {
V_152 = - V_171 ;
break;
} else {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_54
L_55 , V_14 ,
F_93 ( V_13 -> V_172 ) ,
V_4 -> V_165 . V_137 ,
V_4 -> V_165 . V_166 ) ;
F_87 ( V_2 , V_4 ) ;
V_4 = NULL ;
}
}
V_163:
F_88 ( V_153 == 3 && V_4 != NULL ) ;
F_87 ( V_2 , V_4 ) ;
return V_152 ;
}
int F_94 ( struct V_1 * V_2 ,
struct V_59 * V_13 ,
int V_173 , int * V_174 )
{
struct V_157 * V_175 ;
T_3 * V_176 ;
int V_152 ;
V_175 = F_83 ( V_177 , V_147 ) ;
if ( ! V_175 )
return - V_154 ;
V_176 = F_83 ( V_178 , V_147 ) ;
if ( V_176 ) {
V_176 [ 0 ] = V_179 ;
V_176 [ 1 ] = V_180 ;
V_176 [ 9 ] = V_173 ;
} else {
F_89 ( V_175 ) ;
return - V_154 ;
}
V_152 = F_90 ( V_2 , V_13 , V_176 , V_178 ,
V_175 , V_177 ) ;
if ( ! V_152 ) {
if ( V_175 -> V_181 != V_182 )
V_152 = V_175 -> V_181 ;
else
* V_174 = V_175 -> V_183 . V_184 ;
}
F_89 ( V_176 ) ;
F_89 ( V_175 ) ;
return V_152 ;
}
static void F_95 ( struct V_20 * V_21 , int V_185 )
{
struct V_59 * V_13 = V_21 -> V_60 ;
struct V_186 * V_187 = V_21 -> V_186 ;
struct V_1 * V_2 = V_187 -> V_1 ;
int V_152 , V_188 = 0 , V_189 ;
#define F_96 25000
unsigned long V_190 = F_33 ( F_96 ) ;
unsigned long V_191 = V_161 + V_190 ;
enum {
V_192 ,
V_193 ,
V_194
} V_195 = V_192 ;
while ( F_97 ( V_191 ) && V_195 != V_194 ) {
int V_196 = F_98 ( & V_187 -> V_196 ) ;
++ V_188 ;
V_190 = F_99 ( V_2 -> V_197 ,
V_196 != F_98 ( & V_187 -> V_196 ) ||
! F_6 ( V_198 , & V_187 -> V_23 ) ,
V_190 ) ;
if ( ! F_6 ( V_198 , & V_187 -> V_23 ) )
break;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_56
L_57 ,
V_14 , V_187 , V_188 , V_195 ,
V_190 , F_6 ( V_199 , & V_187 -> V_23 ) ) ;
V_152 = F_94 ( V_2 , V_13 , V_185 ,
& V_189 ) ;
V_190 = V_191 - V_161 ;
if ( V_152 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_58
L_59 ,
V_14 , V_188 , V_195 , V_152 , V_190 ) ;
break;
}
F_3 ( & V_2 -> V_12 -> V_13 ,
L_56
L_60
L_61 ,
V_14 , V_187 , V_188 , V_195 ,
V_190 , F_6 ( V_199 , & V_187 -> V_23 ) ,
V_189 ) ;
switch ( V_195 ) {
case V_192 :
if ( ! V_189 )
V_195 = V_193 ;
break;
case V_193 :
if ( V_189 )
V_195 = V_194 ;
break;
case V_194 :
break;
}
}
F_3 ( & V_2 -> V_12 -> V_13 , L_62 , V_14 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_200 * V_201 = F_101 ( V_21 -> V_60 ) ;
struct V_186 * V_187 = V_21 -> V_186 ;
enum V_29 V_8 ;
unsigned long V_23 ;
int V_202 ;
F_3 ( & V_2 -> V_12 -> V_13 , L_63 , V_14 , V_21 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_8 = F_102 ( V_21 ) ;
if ( V_8 != V_43 ) {
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_3 ( & V_2 -> V_12 -> V_13 ,
L_64 ,
V_14 , V_21 , V_8 ) ;
return V_75 ;
}
F_14 ( & V_2 -> V_31 , V_23 ) ;
F_103 ( V_2 , V_21 ) ;
if ( ! F_104 ( V_201 ) )
F_48 ( V_198 , & V_187 -> V_23 ) ;
V_202 = F_105 ( V_201 , true ) ;
F_106 ( V_2 , V_21 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_8 = F_107 ( V_21 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( ! F_104 ( V_201 ) ) {
F_95 ( V_21 , V_201 -> V_203 ) ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
F_108 ( V_2 , V_21 -> V_186 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
}
if ( V_8 != V_43 ) {
F_3 ( & V_2 -> V_12 -> V_13 ,
L_65
L_66 , V_14 , V_21 , V_8 ) ;
}
F_3 ( & V_2 -> V_12 -> V_13 , L_67 , V_14 , V_21 ) ;
return V_202 ;
}
int F_109 ( struct V_59 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_20 * V_21 ;
unsigned long V_23 ;
int V_74 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_21 = F_12 ( V_13 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( ! V_21 || ! F_6 ( V_121 , & V_21 -> V_23 ) ) {
V_74 = V_87 ;
goto V_122;
}
V_74 = F_100 ( V_2 , V_21 ) ;
V_122:
F_18 ( V_21 ) ;
return V_74 ;
}
int F_110 ( struct V_204 * V_55 )
{
struct V_59 * V_13 = F_111 ( V_55 -> V_205 ) ;
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_20 * V_21 ;
unsigned long V_23 ;
int V_74 ;
F_11 ( & V_2 -> V_31 , V_23 ) ;
V_21 = F_12 ( V_13 ) ;
F_14 ( & V_2 -> V_31 , V_23 ) ;
if ( ! V_21 ) {
V_74 = V_87 ;
goto V_122;
}
V_74 = F_100 ( V_2 , V_21 ) ;
V_122:
F_18 ( V_21 ) ;
return V_74 ;
}
