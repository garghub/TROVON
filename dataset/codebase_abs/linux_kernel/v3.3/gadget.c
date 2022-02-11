void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
if ( V_2 -> V_6 . V_7 == 0 ) {
return;
}
if ( V_2 -> V_6 . V_8 ) {
int V_9 ;
V_9 = F_2 ( V_4 -> V_10 , V_2 -> V_6 . V_11 ,
V_2 -> V_6 . V_8 ,
V_2 -> V_12 ? V_13
: V_14 ) ;
if ( V_9 < 0 ) {
F_3 ( V_4 -> V_10 , L_1 ) ;
return;
}
V_2 -> V_6 . V_15 = V_9 ;
return;
}
if ( V_2 -> V_6 . V_16 == V_17 ) {
V_2 -> V_6 . V_16 = F_4 ( V_4 -> V_10 , V_2 -> V_6 . V_18 ,
V_2 -> V_6 . V_7 , V_2 -> V_12
? V_13 : V_14 ) ;
V_2 -> V_9 = true ;
}
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
if ( V_2 -> V_6 . V_7 == 0 ) {
V_2 -> V_6 . V_16 = V_17 ;
return;
}
if ( V_2 -> V_6 . V_15 ) {
V_2 -> V_6 . V_16 = V_17 ;
F_6 ( V_4 -> V_10 , V_2 -> V_6 . V_11 ,
V_2 -> V_6 . V_15 ,
V_2 -> V_12 ? V_13
: V_14 ) ;
V_2 -> V_6 . V_15 = 0 ;
return;
}
if ( V_2 -> V_9 ) {
F_7 ( V_4 -> V_10 , V_2 -> V_6 . V_16 ,
V_2 -> V_6 . V_7 , V_2 -> V_12
? V_13 : V_14 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_6 . V_16 = V_17 ;
}
}
void F_8 ( struct V_19 * V_5 , struct V_1 * V_2 ,
int V_20 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
if ( V_2 -> V_21 ) {
if ( V_2 -> V_6 . V_15 )
V_5 -> V_22 += V_2 -> V_6 . V_15 ;
else
V_5 -> V_22 ++ ;
if ( ( ( V_5 -> V_22 & V_23 ) == V_24 - 1 ) &&
F_9 ( V_5 -> V_25 ) )
V_5 -> V_22 ++ ;
}
F_10 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = NULL ;
if ( V_2 -> V_6 . V_20 == - V_28 )
V_2 -> V_6 . V_20 = V_20 ;
F_5 ( V_2 ) ;
F_11 ( V_4 -> V_10 , L_2 ,
V_2 , V_5 -> V_29 , V_2 -> V_6 . V_30 ,
V_2 -> V_6 . V_7 , V_20 ) ;
F_12 ( & V_4 -> V_31 ) ;
V_2 -> V_6 . V_32 ( & V_2 -> V_5 -> V_33 , & V_2 -> V_6 ) ;
F_13 ( & V_4 -> V_31 ) ;
}
static const char * F_14 ( T_1 V_34 )
{
switch ( V_34 ) {
case V_35 :
return L_3 ;
case V_36 :
return L_4 ;
case V_37 :
return L_5 ;
case V_38 :
return L_6 ;
case V_39 :
return L_7 ;
case V_40 :
return L_8 ;
case V_41 :
return L_9 ;
case V_42 :
return L_10 ;
case V_43 :
return L_11 ;
default:
return L_12 ;
}
}
int F_15 ( struct V_3 * V_4 , unsigned V_44 ,
unsigned V_34 , struct V_45 * V_46 )
{
struct V_19 * V_5 = V_4 -> V_47 [ V_44 ] ;
T_2 V_48 = 500 ;
T_2 V_49 ;
F_16 ( V_4 -> V_10 , L_13 ,
V_5 -> V_29 ,
F_14 ( V_34 ) , V_46 -> V_50 ,
V_46 -> V_51 , V_46 -> V_52 ) ;
F_17 ( V_4 -> V_53 , F_18 ( V_44 ) , V_46 -> V_50 ) ;
F_17 ( V_4 -> V_53 , F_19 ( V_44 ) , V_46 -> V_51 ) ;
F_17 ( V_4 -> V_53 , F_20 ( V_44 ) , V_46 -> V_52 ) ;
F_17 ( V_4 -> V_53 , F_21 ( V_44 ) , V_34 | V_54 ) ;
do {
V_49 = F_22 ( V_4 -> V_53 , F_21 ( V_44 ) ) ;
if ( ! ( V_49 & V_54 ) ) {
F_16 ( V_4 -> V_10 , L_14 ,
F_23 ( V_49 ) ) ;
return 0 ;
}
V_48 -- ;
if ( ! V_48 )
return - V_55 ;
F_24 ( 1 ) ;
} while ( 1 );
}
static T_3 F_25 ( struct V_19 * V_5 ,
struct V_56 * V_27 )
{
T_2 V_57 = ( char * ) V_27 - ( char * ) V_5 -> V_58 ;
return V_5 -> V_59 + V_57 ;
}
static int F_26 ( struct V_19 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
if ( V_5 -> V_58 )
return 0 ;
if ( V_5 -> V_60 == 0 || V_5 -> V_60 == 1 )
return 0 ;
V_5 -> V_58 = F_27 ( V_4 -> V_10 ,
sizeof( struct V_61 ) * V_24 ,
& V_5 -> V_59 , V_62 ) ;
if ( ! V_5 -> V_58 ) {
F_3 ( V_5 -> V_4 -> V_10 , L_15 ,
V_5 -> V_29 ) ;
return - V_63 ;
}
return 0 ;
}
static void F_28 ( struct V_19 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
F_29 ( V_4 -> V_10 , sizeof( struct V_61 ) * V_24 ,
V_5 -> V_58 , V_5 -> V_59 ) ;
V_5 -> V_58 = NULL ;
V_5 -> V_59 = 0 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_19 * V_5 )
{
struct V_45 V_46 ;
T_2 V_34 ;
memset ( & V_46 , 0x00 , sizeof( V_46 ) ) ;
if ( V_5 -> V_60 != 1 ) {
V_34 = V_35 ;
if ( V_5 -> V_60 > 1 ) {
if ( V_4 -> V_64 )
return 0 ;
V_4 -> V_64 = true ;
V_34 |= F_31 ( 2 ) ;
}
return F_15 ( V_4 , 0 , V_34 , & V_46 ) ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_19 * V_5 ,
const struct V_65 * V_25 ,
const struct V_66 * V_67 )
{
struct V_45 V_46 ;
memset ( & V_46 , 0x00 , sizeof( V_46 ) ) ;
V_46 . V_50 = F_33 ( F_34 ( V_25 ) )
| F_35 ( F_36 ( V_25 ) )
| F_37 ( V_5 -> V_33 . V_68 ) ;
V_46 . V_51 = V_69
| V_70 ;
if ( F_38 ( V_67 ) && F_39 ( V_25 ) ) {
V_46 . V_51 |= V_71
| V_72 ;
V_5 -> V_73 = true ;
}
if ( F_9 ( V_25 ) )
V_46 . V_51 |= V_74 ;
V_46 . V_51 |= F_40 ( V_5 -> V_60 ) ;
if ( V_5 -> V_12 )
V_46 . V_50 |= F_41 ( V_5 -> V_60 >> 1 ) ;
if ( V_25 -> V_75 ) {
V_46 . V_51 |= F_42 ( V_25 -> V_75 - 1 ) ;
V_5 -> V_76 = 1 << ( V_25 -> V_75 - 1 ) ;
}
return F_15 ( V_4 , V_5 -> V_60 ,
V_43 , & V_46 ) ;
}
static int F_43 ( struct V_3 * V_4 , struct V_19 * V_5 )
{
struct V_45 V_46 ;
memset ( & V_46 , 0x00 , sizeof( V_46 ) ) ;
V_46 . V_50 = F_44 ( 1 ) ;
return F_15 ( V_4 , V_5 -> V_60 ,
V_42 , & V_46 ) ;
}
static int F_45 ( struct V_19 * V_5 ,
const struct V_65 * V_25 ,
const struct V_66 * V_67 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
T_2 V_49 ;
int V_77 = - V_63 ;
if ( ! ( V_5 -> V_78 & V_79 ) ) {
V_77 = F_30 ( V_4 , V_5 ) ;
if ( V_77 )
return V_77 ;
}
V_77 = F_32 ( V_4 , V_5 , V_25 , V_67 ) ;
if ( V_77 )
return V_77 ;
if ( ! ( V_5 -> V_78 & V_79 ) ) {
struct V_56 * V_80 ;
struct V_56 * V_81 ;
struct V_61 V_82 ;
V_77 = F_43 ( V_4 , V_5 ) ;
if ( V_77 )
return V_77 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_67 = V_67 ;
V_5 -> type = F_34 ( V_25 ) ;
V_5 -> V_78 |= V_79 ;
V_49 = F_22 ( V_4 -> V_53 , V_83 ) ;
V_49 |= F_46 ( V_5 -> V_60 ) ;
F_17 ( V_4 -> V_53 , V_83 , V_49 ) ;
if ( ! F_9 ( V_25 ) )
return 0 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_80 = & V_5 -> V_58 [ 0 ] ;
V_82 . V_84 = F_25 ( V_5 , V_80 ) ;
V_82 . V_85 = V_86 ;
V_82 . V_87 = true ;
V_81 = & V_5 -> V_58 [ V_24 - 1 ] ;
F_47 ( & V_82 , V_81 ) ;
}
return 0 ;
}
static void F_48 ( struct V_3 * V_4 , struct V_19 * V_5 )
{
struct V_1 * V_2 ;
if ( ! F_49 ( & V_5 -> V_88 ) )
F_50 ( V_4 , V_5 -> V_60 ) ;
while ( ! F_49 ( & V_5 -> V_89 ) ) {
V_2 = F_51 ( & V_5 -> V_89 ) ;
F_8 ( V_5 , V_2 , - V_90 ) ;
}
}
static int F_52 ( struct V_19 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
T_2 V_49 ;
F_48 ( V_4 , V_5 ) ;
V_49 = F_22 ( V_4 -> V_53 , V_83 ) ;
V_49 &= ~ F_46 ( V_5 -> V_60 ) ;
F_17 ( V_4 -> V_53 , V_83 , V_49 ) ;
V_5 -> V_73 = false ;
V_5 -> V_25 = NULL ;
V_5 -> V_67 = NULL ;
V_5 -> type = 0 ;
V_5 -> V_78 = 0 ;
return 0 ;
}
static int F_53 ( struct V_91 * V_44 ,
const struct V_65 * V_25 )
{
return - V_92 ;
}
static int F_54 ( struct V_91 * V_44 )
{
return - V_92 ;
}
static int F_55 ( struct V_91 * V_44 ,
const struct V_65 * V_25 )
{
struct V_19 * V_5 ;
struct V_3 * V_4 ;
unsigned long V_78 ;
int V_77 ;
if ( ! V_44 || ! V_25 || V_25 -> V_93 != V_94 ) {
F_56 ( L_16 ) ;
return - V_92 ;
}
if ( ! V_25 -> V_95 ) {
F_56 ( L_17 ) ;
return - V_92 ;
}
V_5 = F_57 ( V_44 ) ;
V_4 = V_5 -> V_4 ;
switch ( F_34 ( V_25 ) ) {
case V_96 :
strncat ( V_5 -> V_29 , L_18 , sizeof( V_5 -> V_29 ) ) ;
break;
case V_97 :
strncat ( V_5 -> V_29 , L_19 , sizeof( V_5 -> V_29 ) ) ;
break;
case V_98 :
strncat ( V_5 -> V_29 , L_20 , sizeof( V_5 -> V_29 ) ) ;
break;
case V_99 :
strncat ( V_5 -> V_29 , L_21 , sizeof( V_5 -> V_29 ) ) ;
break;
default:
F_3 ( V_4 -> V_10 , L_22 ) ;
}
if ( V_5 -> V_78 & V_79 ) {
F_58 ( V_4 -> V_10 , true , L_23 ,
V_5 -> V_29 ) ;
return 0 ;
}
F_16 ( V_4 -> V_10 , L_24 , V_5 -> V_29 ) ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
V_77 = F_45 ( V_5 , V_25 , V_44 -> V_67 ) ;
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
static int F_61 ( struct V_91 * V_44 )
{
struct V_19 * V_5 ;
struct V_3 * V_4 ;
unsigned long V_78 ;
int V_77 ;
if ( ! V_44 ) {
F_56 ( L_16 ) ;
return - V_92 ;
}
V_5 = F_57 ( V_44 ) ;
V_4 = V_5 -> V_4 ;
if ( ! ( V_5 -> V_78 & V_79 ) ) {
F_58 ( V_4 -> V_10 , true , L_25 ,
V_5 -> V_29 ) ;
return 0 ;
}
snprintf ( V_5 -> V_29 , sizeof( V_5 -> V_29 ) , L_26 ,
V_5 -> V_60 >> 1 ,
( V_5 -> V_60 & 1 ) ? L_27 : L_28 ) ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
V_77 = F_52 ( V_5 ) ;
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
static struct V_100 * F_62 ( struct V_91 * V_44 ,
T_4 V_101 )
{
struct V_1 * V_2 ;
struct V_19 * V_5 = F_57 ( V_44 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
V_2 = F_63 ( sizeof( * V_2 ) , V_101 ) ;
if ( ! V_2 ) {
F_3 ( V_4 -> V_10 , L_29 ) ;
return NULL ;
}
V_2 -> V_102 = V_5 -> V_60 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 . V_16 = V_17 ;
return & V_2 -> V_6 ;
}
static void F_64 ( struct V_91 * V_44 ,
struct V_100 * V_6 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
F_66 ( V_2 ) ;
}
static void F_67 ( struct V_19 * V_5 ,
struct V_1 * V_2 , T_3 V_16 ,
unsigned V_7 , unsigned V_103 , unsigned V_104 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_56 * V_105 ;
struct V_61 V_27 ;
unsigned int V_106 ;
F_16 ( V_4 -> V_10 , L_30 ,
V_5 -> V_29 , V_2 , ( unsigned long long ) V_16 ,
V_7 , V_103 ? L_31 : L_32 ,
V_104 ? L_33 : L_32 ) ;
V_105 = & V_5 -> V_58 [ V_5 -> V_107 & V_23 ] ;
V_106 = V_5 -> V_107 ;
V_5 -> V_107 ++ ;
if ( ( ( V_106 & V_23 ) == V_24 - 1 ) &&
F_9 ( V_5 -> V_25 ) )
return;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
if ( ! V_2 -> V_27 ) {
F_68 ( V_2 ) ;
V_2 -> V_27 = V_105 ;
V_2 -> V_108 = F_25 ( V_5 , V_105 ) ;
}
if ( F_9 ( V_5 -> V_25 ) ) {
V_27 . V_109 = true ;
V_27 . V_110 = true ;
} else {
V_27 . V_111 = V_104 ;
V_27 . V_112 = V_103 ;
}
if ( F_39 ( V_5 -> V_25 ) && V_5 -> V_73 )
V_27 . V_113 = V_2 -> V_6 . V_114 ;
switch ( F_34 ( V_5 -> V_25 ) ) {
case V_96 :
V_27 . V_85 = V_115 ;
break;
case V_97 :
V_27 . V_85 = V_116 ;
if ( ! ( V_106 % ( V_24 / 4 ) ) )
V_27 . V_117 = V_103 ;
break;
case V_98 :
case V_99 :
V_27 . V_85 = V_118 ;
break;
default:
F_69 () ;
}
V_27 . V_7 = V_7 ;
V_27 . V_84 = V_16 ;
V_27 . V_87 = true ;
F_47 ( & V_27 , V_105 ) ;
}
static void F_70 ( struct V_19 * V_5 , bool V_119 )
{
struct V_1 * V_2 , * V_120 ;
T_2 V_121 ;
unsigned int V_122 = 0 ;
F_71 ( V_24 ) ;
V_121 = ( V_5 -> V_22 - V_5 -> V_107 ) & V_23 ;
if ( ! V_121 ) {
if ( ! V_119 )
return;
V_121 = V_24 ;
if ( F_9 ( V_5 -> V_25 ) ) {
V_5 -> V_22 = 1 ;
V_5 -> V_107 = 1 ;
} else {
V_5 -> V_22 = 0 ;
V_5 -> V_107 = 0 ;
}
}
if ( ( V_121 <= 1 ) && F_9 ( V_5 -> V_25 ) )
return;
F_72 (req, n, &dep->request_list, list) {
unsigned V_7 ;
T_3 V_16 ;
if ( V_2 -> V_6 . V_15 > 0 ) {
struct V_100 * V_6 = & V_2 -> V_6 ;
struct V_123 * V_11 = V_6 -> V_11 ;
struct V_123 * V_124 ;
int V_125 ;
F_73 (sg, s, request->num_mapped_sgs, i) {
unsigned V_104 = true ;
V_7 = F_74 ( V_124 ) ;
V_16 = F_75 ( V_124 ) ;
if ( V_125 == ( V_6 -> V_15 - 1 )
|| F_76 ( V_124 ) ) {
V_122 = true ;
V_104 = false ;
}
V_121 -- ;
if ( ! V_121 )
V_122 = true ;
if ( V_122 )
V_104 = false ;
F_67 ( V_5 , V_2 , V_16 , V_7 ,
V_122 , V_104 ) ;
if ( V_122 )
break;
}
} else {
V_16 = V_2 -> V_6 . V_16 ;
V_7 = V_2 -> V_6 . V_7 ;
V_121 -- ;
if ( ! V_121 )
V_122 = 1 ;
if ( F_77 ( & V_2 -> V_26 , & V_5 -> V_89 ) )
V_122 = 1 ;
F_67 ( V_5 , V_2 , V_16 , V_7 ,
V_122 , false ) ;
if ( V_122 )
break;
}
}
}
static int F_78 ( struct V_19 * V_5 , T_5 V_126 ,
int V_127 )
{
struct V_45 V_46 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = V_5 -> V_4 ;
int V_77 ;
T_2 V_34 ;
if ( V_127 && ( V_5 -> V_78 & V_128 ) ) {
F_16 ( V_4 -> V_10 , L_34 , V_5 -> V_29 ) ;
return - V_129 ;
}
V_5 -> V_78 &= ~ V_130 ;
if ( V_127 ) {
if ( F_49 ( & V_5 -> V_88 ) )
F_70 ( V_5 , V_127 ) ;
V_2 = F_51 ( & V_5 -> V_88 ) ;
} else {
F_70 ( V_5 , V_127 ) ;
V_2 = F_51 ( & V_5 -> V_88 ) ;
}
if ( ! V_2 ) {
V_5 -> V_78 |= V_130 ;
return 0 ;
}
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_50 = F_79 ( V_2 -> V_108 ) ;
V_46 . V_51 = F_80 ( V_2 -> V_108 ) ;
if ( V_127 )
V_34 = V_38 ;
else
V_34 = V_37 ;
V_34 |= F_31 ( V_126 ) ;
V_77 = F_15 ( V_4 , V_5 -> V_60 , V_34 , & V_46 ) ;
if ( V_77 < 0 ) {
F_11 ( V_4 -> V_10 , L_35 ) ;
F_5 ( V_2 ) ;
F_10 ( & V_2 -> V_26 ) ;
return V_77 ;
}
V_5 -> V_78 |= V_128 ;
V_5 -> V_131 = F_81 ( V_4 ,
V_5 -> V_60 ) ;
F_82 ( ! V_5 -> V_131 ) ;
return 0 ;
}
static int F_83 ( struct V_19 * V_5 , struct V_1 * V_2 )
{
V_2 -> V_6 . V_30 = 0 ;
V_2 -> V_6 . V_20 = - V_28 ;
V_2 -> V_12 = V_5 -> V_12 ;
V_2 -> V_102 = V_5 -> V_60 ;
F_1 ( V_2 ) ;
F_84 ( & V_2 -> V_26 , & V_5 -> V_89 ) ;
if ( V_5 -> V_78 & V_130 ) {
int V_77 ;
int V_132 ;
V_132 = 1 ;
if ( F_9 ( V_5 -> V_33 . V_25 ) &&
V_5 -> V_78 & V_128 )
V_132 = 0 ;
V_77 = F_78 ( V_5 , 0 , V_132 ) ;
if ( V_77 && V_77 != - V_129 ) {
struct V_3 * V_4 = V_5 -> V_4 ;
F_11 ( V_4 -> V_10 , L_36 ,
V_5 -> V_29 ) ;
}
} ;
return 0 ;
}
static int F_85 ( struct V_91 * V_44 , struct V_100 * V_6 ,
T_4 V_101 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_19 * V_5 = F_57 ( V_44 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_78 ;
int V_77 ;
if ( ! V_5 -> V_25 ) {
F_11 ( V_4 -> V_10 , L_37 ,
V_6 , V_44 -> V_29 ) ;
return - V_90 ;
}
F_16 ( V_4 -> V_10 , L_38 ,
V_6 , V_44 -> V_29 , V_6 -> V_7 ) ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
V_77 = F_83 ( V_5 , V_2 ) ;
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
static int F_86 ( struct V_91 * V_44 ,
struct V_100 * V_6 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_1 * V_133 = NULL ;
struct V_19 * V_5 = F_57 ( V_44 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_78 ;
int V_77 = 0 ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
F_87 (r, &dep->request_list, list) {
if ( V_133 == V_2 )
break;
}
if ( V_133 != V_2 ) {
F_87 (r, &dep->req_queued, list) {
if ( V_133 == V_2 )
break;
}
if ( V_133 == V_2 ) {
F_50 ( V_4 , V_5 -> V_60 ) ;
goto V_134;
}
F_3 ( V_4 -> V_10 , L_39 ,
V_6 , V_44 -> V_29 ) ;
V_77 = - V_92 ;
goto V_134;
}
F_8 ( V_5 , V_2 , - V_135 ) ;
V_134:
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
int F_88 ( struct V_19 * V_5 , int V_136 )
{
struct V_45 V_46 ;
struct V_3 * V_4 = V_5 -> V_4 ;
int V_77 ;
memset ( & V_46 , 0x00 , sizeof( V_46 ) ) ;
if ( V_136 ) {
if ( V_5 -> V_60 == 0 || V_5 -> V_60 == 1 ) {
V_4 -> V_137 = V_138 ;
}
V_77 = F_15 ( V_4 , V_5 -> V_60 ,
V_40 , & V_46 ) ;
if ( V_77 )
F_3 ( V_4 -> V_10 , L_40 ,
V_136 ? L_41 : L_42 ,
V_5 -> V_29 ) ;
else
V_5 -> V_78 |= V_139 ;
} else {
if ( V_5 -> V_78 & V_140 )
return 0 ;
V_77 = F_15 ( V_4 , V_5 -> V_60 ,
V_39 , & V_46 ) ;
if ( V_77 )
F_3 ( V_4 -> V_10 , L_40 ,
V_136 ? L_41 : L_42 ,
V_5 -> V_29 ) ;
else
V_5 -> V_78 &= ~ V_139 ;
}
return V_77 ;
}
static int F_89 ( struct V_91 * V_44 , int V_136 )
{
struct V_19 * V_5 = F_57 ( V_44 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_78 ;
int V_77 ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
if ( F_9 ( V_5 -> V_25 ) ) {
F_3 ( V_4 -> V_10 , L_43 , V_5 -> V_29 ) ;
V_77 = - V_92 ;
goto V_141;
}
V_77 = F_88 ( V_5 , V_136 ) ;
V_141:
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
static int F_90 ( struct V_91 * V_44 )
{
struct V_19 * V_5 = F_57 ( V_44 ) ;
V_5 -> V_78 |= V_140 ;
return F_89 ( V_44 , 1 ) ;
}
static int F_91 ( struct V_142 * V_143 )
{
struct V_3 * V_4 = F_92 ( V_143 ) ;
T_2 V_49 ;
V_49 = F_22 ( V_4 -> V_53 , V_144 ) ;
return F_93 ( V_49 ) ;
}
static int F_94 ( struct V_142 * V_143 )
{
struct V_3 * V_4 = F_92 ( V_143 ) ;
unsigned long V_48 ;
unsigned long V_78 ;
T_2 V_49 ;
int V_77 = 0 ;
T_1 V_145 ;
T_1 V_146 ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
V_49 = F_22 ( V_4 -> V_53 , V_144 ) ;
V_146 = V_49 & V_147 ;
if ( V_146 == V_148 ) {
F_11 ( V_4 -> V_10 , L_44 ) ;
V_77 = - V_92 ;
goto V_141;
}
V_145 = F_95 ( V_49 ) ;
switch ( V_145 ) {
case V_149 :
case V_150 :
break;
default:
F_11 ( V_4 -> V_10 , L_45 ,
V_145 ) ;
V_77 = - V_92 ;
goto V_141;
}
V_49 = F_22 ( V_4 -> V_53 , V_151 ) ;
V_49 |= V_152 ;
F_17 ( V_4 -> V_53 , V_151 , V_49 ) ;
F_96 ( 2000 , 2500 ) ;
V_49 &= ~ V_153 ;
F_17 ( V_4 -> V_53 , V_151 , V_49 ) ;
V_48 = V_154 + F_97 ( 100 ) ;
while ( ! ( F_98 ( V_154 , V_48 ) ) ) {
V_49 = F_22 ( V_4 -> V_53 , V_144 ) ;
if ( F_95 ( V_49 ) == V_155 )
break;
}
if ( F_95 ( V_49 ) != V_155 ) {
F_3 ( V_4 -> V_10 , L_46 ) ;
V_77 = - V_92 ;
}
V_141:
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
static int F_99 ( struct V_142 * V_143 ,
int V_156 )
{
struct V_3 * V_4 = F_92 ( V_143 ) ;
V_4 -> V_156 = ! ! V_156 ;
return 0 ;
}
static void F_100 ( struct V_3 * V_4 , int V_157 )
{
T_2 V_49 ;
T_2 V_48 = 500 ;
V_49 = F_22 ( V_4 -> V_53 , V_151 ) ;
if ( V_157 )
V_49 |= V_158 ;
else
V_49 &= ~ V_158 ;
F_17 ( V_4 -> V_53 , V_151 , V_49 ) ;
do {
V_49 = F_22 ( V_4 -> V_53 , V_144 ) ;
if ( V_157 ) {
if ( ! ( V_49 & V_159 ) )
break;
} else {
if ( V_49 & V_159 )
break;
}
V_48 -- ;
if ( ! V_48 )
break;
F_24 ( 1 ) ;
} while ( 1 );
F_16 ( V_4 -> V_10 , L_47 ,
V_4 -> V_160
? V_4 -> V_160 -> V_161 : L_48 ,
V_157 ? L_49 : L_50 ) ;
}
static int F_101 ( struct V_142 * V_143 , int V_157 )
{
struct V_3 * V_4 = F_92 ( V_143 ) ;
unsigned long V_78 ;
V_157 = ! ! V_157 ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
F_100 ( V_4 , V_157 ) ;
F_60 ( & V_4 -> V_31 , V_78 ) ;
return 0 ;
}
static int F_102 ( struct V_142 * V_143 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = F_92 ( V_143 ) ;
struct V_19 * V_5 ;
unsigned long V_78 ;
int V_77 = 0 ;
T_2 V_49 ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
if ( V_4 -> V_160 ) {
F_3 ( V_4 -> V_10 , L_51 ,
V_4 -> V_164 . V_29 ,
V_4 -> V_160 -> V_163 . V_29 ) ;
V_77 = - V_129 ;
goto V_165;
}
V_4 -> V_160 = V_163 ;
V_4 -> V_164 . V_10 . V_163 = & V_163 -> V_163 ;
V_49 = F_22 ( V_4 -> V_53 , V_166 ) ;
V_49 &= ~ ( V_167 ) ;
V_49 |= V_4 -> V_168 ;
F_17 ( V_4 -> V_53 , V_166 , V_49 ) ;
V_4 -> V_64 = false ;
V_169 . V_95 = F_103 ( 512 ) ;
V_5 = V_4 -> V_47 [ 0 ] ;
V_77 = F_45 ( V_5 , & V_169 , NULL ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_52 , V_5 -> V_29 ) ;
goto V_165;
}
V_5 = V_4 -> V_47 [ 1 ] ;
V_77 = F_45 ( V_5 , & V_169 , NULL ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_52 , V_5 -> V_29 ) ;
goto V_170;
}
V_4 -> V_137 = V_138 ;
F_104 ( V_4 ) ;
F_60 ( & V_4 -> V_31 , V_78 ) ;
return 0 ;
V_170:
F_52 ( V_4 -> V_47 [ 0 ] ) ;
V_165:
F_60 ( & V_4 -> V_31 , V_78 ) ;
return V_77 ;
}
static int F_105 ( struct V_142 * V_143 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = F_92 ( V_143 ) ;
unsigned long V_78 ;
F_59 ( & V_4 -> V_31 , V_78 ) ;
F_52 ( V_4 -> V_47 [ 0 ] ) ;
F_52 ( V_4 -> V_47 [ 1 ] ) ;
V_4 -> V_160 = NULL ;
V_4 -> V_164 . V_10 . V_163 = NULL ;
F_60 ( & V_4 -> V_31 , V_78 ) ;
return 0 ;
}
static int T_6 F_106 ( struct V_3 * V_4 )
{
struct V_19 * V_5 ;
T_1 V_102 ;
F_107 ( & V_4 -> V_164 . V_171 ) ;
for ( V_102 = 0 ; V_102 < V_172 ; V_102 ++ ) {
V_5 = F_63 ( sizeof( * V_5 ) , V_62 ) ;
if ( ! V_5 ) {
F_3 ( V_4 -> V_10 , L_53 ,
V_102 ) ;
return - V_63 ;
}
V_5 -> V_4 = V_4 ;
V_5 -> V_60 = V_102 ;
V_4 -> V_47 [ V_102 ] = V_5 ;
snprintf ( V_5 -> V_29 , sizeof( V_5 -> V_29 ) , L_26 , V_102 >> 1 ,
( V_102 & 1 ) ? L_27 : L_28 ) ;
V_5 -> V_33 . V_29 = V_5 -> V_29 ;
V_5 -> V_12 = ( V_102 & 1 ) ;
if ( V_102 == 0 || V_102 == 1 ) {
V_5 -> V_33 . V_173 = 512 ;
V_5 -> V_33 . V_174 = & V_175 ;
if ( ! V_102 )
V_4 -> V_164 . V_176 = & V_5 -> V_33 ;
} else {
int V_77 ;
V_5 -> V_33 . V_173 = 1024 ;
V_5 -> V_33 . V_177 = 15 ;
V_5 -> V_33 . V_174 = & V_178 ;
F_84 ( & V_5 -> V_33 . V_171 ,
& V_4 -> V_164 . V_171 ) ;
V_77 = F_26 ( V_5 ) ;
if ( V_77 )
return V_77 ;
}
F_107 ( & V_5 -> V_89 ) ;
F_107 ( & V_5 -> V_88 ) ;
}
return 0 ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_19 * V_5 ;
T_1 V_102 ;
for ( V_102 = 0 ; V_102 < V_172 ; V_102 ++ ) {
V_5 = V_4 -> V_47 [ V_102 ] ;
F_28 ( V_5 ) ;
if ( V_102 != 0 && V_102 != 1 )
F_10 ( & V_5 -> V_33 . V_171 ) ;
F_66 ( V_5 ) ;
}
}
static void F_109 ( struct V_179 * V_10 )
{
F_11 ( V_10 , L_54 , V_180 ) ;
}
static int F_110 ( struct V_3 * V_4 , struct V_19 * V_5 ,
const struct V_181 * V_182 , int V_20 )
{
struct V_1 * V_2 ;
struct V_61 V_27 ;
unsigned int V_183 ;
unsigned int V_184 = 0 ;
do {
V_2 = F_51 ( & V_5 -> V_88 ) ;
if ( ! V_2 ) {
F_82 ( 1 ) ;
return 1 ;
}
F_111 ( V_2 -> V_27 , & V_27 ) ;
if ( V_27 . V_87 && V_20 != - V_90 )
F_3 ( V_4 -> V_10 , L_55 ,
V_5 -> V_29 , V_2 -> V_27 ) ;
V_183 = V_27 . V_7 ;
if ( V_5 -> V_12 ) {
if ( V_183 ) {
F_3 ( V_4 -> V_10 , L_56 ,
V_5 -> V_29 ) ;
V_20 = - V_135 ;
}
} else {
if ( V_183 && ( V_182 -> V_20 & V_185 ) )
V_184 = 1 ;
}
V_2 -> V_6 . V_30 += V_2 -> V_6 . V_7 - V_183 ;
F_8 ( V_5 , V_2 , V_20 ) ;
if ( V_184 )
break;
if ( ( V_182 -> V_20 & V_186 ) && V_27 . V_112 )
break;
if ( ( V_182 -> V_20 & V_187 ) && V_27 . V_117 )
break;
} while ( 1 );
if ( ( V_182 -> V_20 & V_187 ) && V_27 . V_117 )
return 0 ;
return 1 ;
}
static void F_112 ( struct V_3 * V_4 ,
struct V_19 * V_5 , const struct V_181 * V_182 ,
int V_127 )
{
unsigned V_20 = 0 ;
int V_188 ;
if ( V_182 -> V_20 & V_189 )
V_20 = - V_135 ;
V_188 = F_110 ( V_4 , V_5 , V_182 , V_20 ) ;
if ( V_188 ) {
V_5 -> V_78 &= ~ V_128 ;
V_5 -> V_131 = 0 ;
}
if ( V_4 -> V_190 < V_191 ) {
T_2 V_49 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_172 ; V_125 ++ ) {
struct V_19 * V_5 = V_4 -> V_47 [ V_125 ] ;
if ( ! ( V_5 -> V_78 & V_79 ) )
continue;
if ( ! F_49 ( & V_5 -> V_88 ) )
return;
}
V_49 = F_22 ( V_4 -> V_53 , V_151 ) ;
V_49 |= V_4 -> V_192 ;
F_17 ( V_4 -> V_53 , V_151 , V_49 ) ;
V_4 -> V_192 = 0 ;
}
}
static void F_113 ( struct V_3 * V_4 ,
struct V_19 * V_5 , const struct V_181 * V_182 )
{
T_2 V_193 ;
if ( F_49 ( & V_5 -> V_89 ) ) {
F_16 ( V_4 -> V_10 , L_57 ,
V_5 -> V_29 ) ;
return;
}
if ( V_182 -> V_194 ) {
T_2 V_195 ;
V_195 = ~ ( V_5 -> V_76 - 1 ) ;
V_193 = V_182 -> V_194 & V_195 ;
V_193 += V_5 -> V_76 * 4 ;
} else {
V_193 = 0 ;
}
F_78 ( V_5 , V_193 , 1 ) ;
}
static void F_114 ( struct V_19 * V_5 ,
const struct V_181 * V_182 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_181 V_196 = * V_182 ;
V_196 . V_20 = V_186 ;
F_110 ( V_4 , V_5 , & V_196 , - V_90 ) ;
V_5 -> V_78 &= ~ V_128 ;
}
static void F_115 ( struct V_19 * V_5 ,
const struct V_181 * V_182 )
{
T_2 V_197 = V_182 -> V_194 ;
T_2 V_198 = ( V_197 >> 8 ) & ( ( 1 << 5 ) - 1 ) ;
switch ( V_198 ) {
case V_36 :
F_114 ( V_5 , V_182 ) ;
break;
case V_38 :
V_5 -> V_131 = V_197 & 0x7f ;
break;
default:
F_116 ( V_199 L_58 ,
V_180 , V_198 ) ;
break;
} ;
}
static void F_117 ( struct V_3 * V_4 ,
const struct V_181 * V_182 )
{
struct V_19 * V_5 ;
T_1 V_102 = V_182 -> V_200 ;
V_5 = V_4 -> V_47 [ V_102 ] ;
F_16 ( V_4 -> V_10 , L_59 , V_5 -> V_29 ,
F_118 ( V_182 -> V_201 ) ) ;
if ( V_102 == 0 || V_102 == 1 ) {
F_119 ( V_4 , V_182 ) ;
return;
}
switch ( V_182 -> V_201 ) {
case V_202 :
if ( F_9 ( V_5 -> V_25 ) ) {
F_11 ( V_4 -> V_10 , L_60 ,
V_5 -> V_29 ) ;
return;
}
F_112 ( V_4 , V_5 , V_182 , 1 ) ;
break;
case V_203 :
if ( ! F_9 ( V_5 -> V_25 ) ) {
F_11 ( V_4 -> V_10 , L_61 ,
V_5 -> V_29 ) ;
return;
}
F_112 ( V_4 , V_5 , V_182 , 0 ) ;
break;
case V_204 :
if ( F_9 ( V_5 -> V_25 ) ) {
F_113 ( V_4 , V_5 , V_182 ) ;
} else {
int V_77 ;
F_16 ( V_4 -> V_10 , L_62 ,
V_5 -> V_29 , V_182 -> V_20
? L_63
: L_64 ) ;
V_77 = F_78 ( V_5 , 0 , 1 ) ;
if ( ! V_77 || V_77 == - V_129 )
return;
F_11 ( V_4 -> V_10 , L_36 ,
V_5 -> V_29 ) ;
}
break;
case V_205 :
if ( ! F_39 ( V_5 -> V_25 ) ) {
F_3 ( V_4 -> V_10 , L_65 ,
V_5 -> V_29 ) ;
return;
}
switch ( V_182 -> V_20 ) {
case V_206 :
F_16 ( V_4 -> V_10 , L_66 ,
V_182 -> V_194 ) ;
break;
case V_207 :
default:
F_11 ( V_4 -> V_10 , L_67 ) ;
}
break;
case V_208 :
F_11 ( V_4 -> V_10 , L_68 , V_5 -> V_29 ) ;
break;
case V_209 :
F_115 ( V_5 , V_182 ) ;
break;
}
}
static void F_120 ( struct V_3 * V_4 )
{
if ( V_4 -> V_160 && V_4 -> V_160 -> V_210 ) {
F_12 ( & V_4 -> V_31 ) ;
V_4 -> V_160 -> V_210 ( & V_4 -> V_164 ) ;
F_13 ( & V_4 -> V_31 ) ;
}
}
static void F_50 ( struct V_3 * V_4 , T_2 V_102 )
{
struct V_19 * V_5 ;
struct V_45 V_46 ;
T_2 V_34 ;
int V_77 ;
V_5 = V_4 -> V_47 [ V_102 ] ;
F_121 ( ! V_5 -> V_131 ) ;
if ( V_5 -> V_131 ) {
V_34 = V_36 ;
V_34 |= V_211 | V_212 ;
V_34 |= F_31 ( V_5 -> V_131 ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_77 = F_15 ( V_4 , V_5 -> V_60 , V_34 , & V_46 ) ;
F_82 ( V_77 ) ;
V_5 -> V_131 = 0 ;
}
}
static void F_122 ( struct V_3 * V_4 )
{
T_2 V_102 ;
for ( V_102 = 2 ; V_102 < V_172 ; V_102 ++ ) {
struct V_19 * V_5 ;
V_5 = V_4 -> V_47 [ V_102 ] ;
if ( ! ( V_5 -> V_78 & V_79 ) )
continue;
F_48 ( V_4 , V_5 ) ;
}
}
static void F_123 ( struct V_3 * V_4 )
{
T_2 V_102 ;
for ( V_102 = 1 ; V_102 < V_172 ; V_102 ++ ) {
struct V_19 * V_5 ;
struct V_45 V_46 ;
int V_77 ;
V_5 = V_4 -> V_47 [ V_102 ] ;
if ( ! ( V_5 -> V_78 & V_139 ) )
continue;
V_5 -> V_78 &= ~ V_139 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_77 = F_15 ( V_4 , V_5 -> V_60 ,
V_39 , & V_46 ) ;
F_82 ( V_77 ) ;
}
}
static void F_124 ( struct V_3 * V_4 )
{
F_16 ( V_4 -> V_10 , L_54 , V_180 ) ;
#if 0
XXX
U1/U2 is powersave optimization. Skip it for now. Anyway we need to
enable it before we can disable it.
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
#endif
F_122 ( V_4 ) ;
F_120 ( V_4 ) ;
V_4 -> V_64 = false ;
V_4 -> V_164 . V_146 = V_213 ;
V_4 -> V_214 = false ;
}
static void F_125 ( struct V_3 * V_4 , int V_215 )
{
T_2 V_49 ;
V_49 = F_22 ( V_4 -> V_53 , F_126 ( 0 ) ) ;
if ( V_215 )
V_49 &= ~ V_216 ;
else
V_49 |= V_216 ;
F_17 ( V_4 -> V_53 , F_126 ( 0 ) , V_49 ) ;
}
static void F_127 ( struct V_3 * V_4 , int V_215 )
{
T_2 V_49 ;
V_49 = F_22 ( V_4 -> V_53 , F_128 ( 0 ) ) ;
if ( V_215 )
V_49 &= ~ V_217 ;
else
V_49 |= V_217 ;
F_17 ( V_4 -> V_53 , F_128 ( 0 ) , V_49 ) ;
}
static void F_129 ( struct V_3 * V_4 )
{
T_2 V_49 ;
F_16 ( V_4 -> V_10 , L_54 , V_180 ) ;
if ( V_4 -> V_190 < V_218 ) {
if ( V_4 -> V_214 )
F_124 ( V_4 ) ;
}
V_4 -> V_219 = V_220 ;
F_127 ( V_4 , true ) ;
F_125 ( V_4 , true ) ;
if ( V_4 -> V_164 . V_146 != V_213 )
F_120 ( V_4 ) ;
V_49 = F_22 ( V_4 -> V_53 , V_151 ) ;
V_49 &= ~ V_221 ;
F_17 ( V_4 -> V_53 , V_151 , V_49 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
V_4 -> V_64 = false ;
V_49 = F_22 ( V_4 -> V_53 , V_166 ) ;
V_49 &= ~ ( V_222 ) ;
F_17 ( V_4 -> V_53 , V_166 , V_49 ) ;
}
static void F_130 ( struct V_3 * V_4 , T_2 V_146 )
{
T_2 V_49 ;
T_2 V_223 = V_224 ;
if ( V_146 != V_148 )
return;
if ( ! V_223 )
return;
V_49 = F_22 ( V_4 -> V_53 , V_225 ) ;
V_49 |= F_131 ( V_223 ) ;
F_17 ( V_4 -> V_53 , V_225 , V_49 ) ;
}
static void F_132 ( struct V_3 * V_4 , T_1 V_146 )
{
switch ( V_146 ) {
case V_226 :
F_127 ( V_4 , false ) ;
break;
case V_227 :
case V_228 :
case V_229 :
F_125 ( V_4 , false ) ;
break;
}
}
static void F_133 ( struct V_3 * V_4 )
{
struct V_45 V_46 ;
struct V_19 * V_5 ;
int V_77 ;
T_2 V_49 ;
T_1 V_146 ;
F_16 ( V_4 -> V_10 , L_54 , V_180 ) ;
memset ( & V_46 , 0x00 , sizeof( V_46 ) ) ;
V_49 = F_22 ( V_4 -> V_53 , V_144 ) ;
V_146 = V_49 & V_147 ;
V_4 -> V_146 = V_146 ;
F_130 ( V_4 , V_146 ) ;
switch ( V_146 ) {
case V_230 :
if ( V_4 -> V_190 < V_231 )
F_129 ( V_4 ) ;
V_169 . V_95 = F_103 ( 512 ) ;
V_4 -> V_164 . V_176 -> V_173 = 512 ;
V_4 -> V_164 . V_146 = V_226 ;
break;
case V_232 :
V_169 . V_95 = F_103 ( 64 ) ;
V_4 -> V_164 . V_176 -> V_173 = 64 ;
V_4 -> V_164 . V_146 = V_227 ;
break;
case V_233 :
case V_234 :
V_169 . V_95 = F_103 ( 64 ) ;
V_4 -> V_164 . V_176 -> V_173 = 64 ;
V_4 -> V_164 . V_146 = V_228 ;
break;
case V_235 :
V_169 . V_95 = F_103 ( 8 ) ;
V_4 -> V_164 . V_176 -> V_173 = 8 ;
V_4 -> V_164 . V_146 = V_229 ;
break;
}
F_132 ( V_4 , V_4 -> V_164 . V_146 ) ;
V_5 = V_4 -> V_47 [ 0 ] ;
V_77 = F_45 ( V_5 , & V_169 , NULL ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_52 , V_5 -> V_29 ) ;
return;
}
V_5 = V_4 -> V_47 [ 1 ] ;
V_77 = F_45 ( V_5 , & V_169 , NULL ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_52 , V_5 -> V_29 ) ;
return;
}
}
static void F_134 ( struct V_3 * V_4 )
{
F_16 ( V_4 -> V_10 , L_54 , V_180 ) ;
V_4 -> V_160 -> V_236 ( & V_4 -> V_164 ) ;
}
static void F_135 ( struct V_3 * V_4 ,
unsigned int V_237 )
{
enum V_238 V_239 = V_237 & V_240 ;
if ( V_4 -> V_190 < V_191 ) {
if ( V_239 == V_155 ) {
T_2 V_192 ;
T_2 V_49 ;
switch ( V_4 -> V_145 ) {
case V_241 :
case V_242 :
V_49 = F_22 ( V_4 -> V_53 , V_151 ) ;
V_192 = V_49 & ( V_243
| V_244
| V_245
| V_246 ) ;
if ( ! V_4 -> V_192 )
V_4 -> V_192 = V_49 & V_192 ;
V_49 &= ~ V_192 ;
F_17 ( V_4 -> V_53 , V_151 , V_49 ) ;
break;
default:
break;
}
}
}
V_4 -> V_145 = V_239 ;
F_16 ( V_4 -> V_10 , L_69 , V_180 , V_4 -> V_145 ) ;
}
static void F_136 ( struct V_3 * V_4 ,
const struct V_247 * V_182 )
{
switch ( V_182 -> type ) {
case V_248 :
F_124 ( V_4 ) ;
break;
case V_249 :
F_129 ( V_4 ) ;
break;
case V_250 :
F_133 ( V_4 ) ;
break;
case V_251 :
F_134 ( V_4 ) ;
break;
case V_252 :
F_135 ( V_4 , V_182 -> V_253 ) ;
break;
case V_254 :
F_16 ( V_4 -> V_10 , L_70 ) ;
break;
case V_255 :
F_16 ( V_4 -> V_10 , L_71 ) ;
break;
case V_256 :
F_16 ( V_4 -> V_10 , L_72 ) ;
break;
case V_257 :
F_16 ( V_4 -> V_10 , L_73 ) ;
break;
case V_258 :
F_16 ( V_4 -> V_10 , L_74 ) ;
break;
default:
F_11 ( V_4 -> V_10 , L_75 , V_182 -> type ) ;
}
}
static void F_137 ( struct V_3 * V_4 ,
const union V_259 * V_182 )
{
if ( V_182 -> type . V_260 == 0 ) {
return F_117 ( V_4 , & V_182 -> V_261 ) ;
}
switch ( V_182 -> type . type ) {
case V_262 :
F_136 ( V_4 , & V_182 -> V_263 ) ;
break;
default:
F_3 ( V_4 -> V_10 , L_76 , V_182 -> V_264 ) ;
}
}
static T_7 F_138 ( struct V_3 * V_4 , T_2 V_18 )
{
struct V_265 * V_266 ;
int V_267 ;
T_2 V_183 ;
V_183 = F_22 ( V_4 -> V_53 , F_139 ( V_18 ) ) ;
V_183 &= V_268 ;
if ( ! V_183 )
return V_269 ;
V_266 = V_4 -> V_270 [ V_18 ] ;
V_267 = V_183 ;
while ( V_267 > 0 ) {
union V_259 V_182 ;
memcpy ( & V_182 . V_264 , ( V_266 -> V_18 + V_266 -> V_271 ) , sizeof( V_182 . V_264 ) ) ;
F_137 ( V_4 , & V_182 ) ;
V_266 -> V_271 = ( V_266 -> V_271 + 4 ) % V_272 ;
V_267 -= 4 ;
F_17 ( V_4 -> V_53 , F_139 ( V_18 ) , 4 ) ;
}
return V_273 ;
}
static T_7 F_140 ( int V_274 , void * V_275 )
{
struct V_3 * V_4 = V_275 ;
int V_125 ;
T_7 V_77 = V_269 ;
F_13 ( & V_4 -> V_31 ) ;
for ( V_125 = 0 ; V_125 < V_4 -> V_276 ; V_125 ++ ) {
T_7 V_20 ;
V_20 = F_138 ( V_4 , V_125 ) ;
if ( V_20 == V_273 )
V_77 = V_20 ;
}
F_12 ( & V_4 -> V_31 ) ;
return V_77 ;
}
int T_6 F_141 ( struct V_3 * V_4 )
{
T_2 V_49 ;
int V_77 ;
int V_274 ;
V_4 -> V_277 = F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_277 ) ,
& V_4 -> V_278 , V_62 ) ;
if ( ! V_4 -> V_277 ) {
F_3 ( V_4 -> V_10 , L_77 ) ;
V_77 = - V_63 ;
goto V_165;
}
V_4 -> V_279 = F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_279 ) ,
& V_4 -> V_280 , V_62 ) ;
if ( ! V_4 -> V_279 ) {
F_3 ( V_4 -> V_10 , L_78 ) ;
V_77 = - V_63 ;
goto V_170;
}
V_4 -> V_281 = F_27 ( V_4 -> V_10 ,
sizeof( * V_4 -> V_281 ) * 2 ,
& V_4 -> V_282 , V_62 ) ;
if ( ! V_4 -> V_281 ) {
F_3 ( V_4 -> V_10 , L_79 ) ;
V_77 = - V_63 ;
goto V_283;
}
V_4 -> V_284 = F_27 ( V_4 -> V_10 ,
512 , & V_4 -> V_285 , V_62 ) ;
if ( ! V_4 -> V_284 ) {
F_3 ( V_4 -> V_10 , L_80 ) ;
V_77 = - V_63 ;
goto V_286;
}
F_142 ( & V_4 -> V_164 . V_10 , L_81 ) ;
V_4 -> V_164 . V_174 = & V_287 ;
V_4 -> V_164 . V_288 = V_226 ;
V_4 -> V_164 . V_146 = V_213 ;
V_4 -> V_164 . V_10 . V_289 = V_4 -> V_10 ;
V_4 -> V_164 . V_290 = true ;
F_143 ( & V_4 -> V_164 . V_10 , V_4 -> V_10 -> V_291 ) ;
V_4 -> V_164 . V_10 . V_292 = V_4 -> V_10 -> V_292 ;
V_4 -> V_164 . V_10 . V_293 = V_4 -> V_10 -> V_293 ;
V_4 -> V_164 . V_10 . V_294 = F_109 ;
V_4 -> V_164 . V_29 = L_82 ;
V_77 = F_106 ( V_4 ) ;
if ( V_77 )
goto V_295;
V_274 = F_144 ( F_145 ( V_4 -> V_10 ) , 0 ) ;
V_77 = F_146 ( V_274 , F_140 , V_296 ,
L_83 , V_4 ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_84 ,
V_274 , V_77 ) ;
goto V_297;
}
V_49 = ( V_298 |
V_299 |
V_300 |
V_301 |
V_302 |
V_303 |
V_304 |
V_305 |
V_306 ) ;
F_17 ( V_4 -> V_53 , V_307 , V_49 ) ;
V_77 = F_147 ( & V_4 -> V_164 . V_10 ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_85 ) ;
F_148 ( & V_4 -> V_164 . V_10 ) ;
goto V_308;
}
V_77 = F_149 ( V_4 -> V_10 , & V_4 -> V_164 ) ;
if ( V_77 ) {
F_3 ( V_4 -> V_10 , L_86 ) ;
goto V_309;
}
return 0 ;
V_309:
F_150 ( & V_4 -> V_164 . V_10 ) ;
V_308:
F_17 ( V_4 -> V_53 , V_307 , 0x00 ) ;
F_151 ( V_274 , V_4 ) ;
V_297:
F_108 ( V_4 ) ;
V_295:
F_29 ( V_4 -> V_10 , 512 , V_4 -> V_284 ,
V_4 -> V_285 ) ;
V_286:
F_29 ( V_4 -> V_10 , sizeof( * V_4 -> V_281 ) * 2 ,
V_4 -> V_281 , V_4 -> V_282 ) ;
V_283:
F_29 ( V_4 -> V_10 , sizeof( * V_4 -> V_279 ) ,
V_4 -> V_279 , V_4 -> V_280 ) ;
V_170:
F_29 ( V_4 -> V_10 , sizeof( * V_4 -> V_277 ) ,
V_4 -> V_277 , V_4 -> V_278 ) ;
V_165:
return V_77 ;
}
void F_152 ( struct V_3 * V_4 )
{
int V_274 ;
F_153 ( & V_4 -> V_164 ) ;
V_274 = F_144 ( F_145 ( V_4 -> V_10 ) , 0 ) ;
F_17 ( V_4 -> V_53 , V_307 , 0x00 ) ;
F_151 ( V_274 , V_4 ) ;
F_108 ( V_4 ) ;
F_29 ( V_4 -> V_10 , 512 , V_4 -> V_284 ,
V_4 -> V_285 ) ;
F_29 ( V_4 -> V_10 , sizeof( * V_4 -> V_281 ) * 2 ,
V_4 -> V_281 , V_4 -> V_282 ) ;
F_29 ( V_4 -> V_10 , sizeof( * V_4 -> V_279 ) ,
V_4 -> V_279 , V_4 -> V_280 ) ;
F_29 ( V_4 -> V_10 , sizeof( * V_4 -> V_277 ) ,
V_4 -> V_277 , V_4 -> V_278 ) ;
F_150 ( & V_4 -> V_164 . V_10 ) ;
}
