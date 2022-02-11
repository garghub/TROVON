static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_2 * V_5 ;
struct V_1 * V_6 ;
F_2 (ptr, head) {
V_6 = F_3 ( V_5 , struct V_1 , V_7 ) ;
if ( V_6 -> V_4 == V_4 )
return V_6 ;
}
return NULL ;
}
static int F_4 ( struct V_1
* V_8 , int V_9 )
{
int V_10 , V_11 ;
struct V_12 * V_13 ;
V_13 = V_8 -> V_13 ;
V_11 = - 1 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
if ( V_9 == V_13 [ V_10 ] . V_15 ) {
V_11 = V_10 ;
break;
}
if ( V_11 < 0 ) {
F_5 ( V_16 L_1 ) ;
return 0 ;
}
return V_11 ;
}
static T_1 F_6 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
if ( V_8 -> V_18 & V_19 ) {
F_7 ( & V_8 -> V_20 ) ;
F_8 ( V_9 ) ;
V_8 -> V_21 = true ;
F_9 ( & V_8 -> V_20 ) ;
}
F_10 ( V_8 -> V_22 , V_8 -> V_23 ,
V_8 -> V_24 , 1 ) ;
return V_25 ;
}
static T_1 F_11 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_11 = F_4 ( V_8 , V_9 ) ;
T_2 V_15 ;
if ( V_11 >= 0 ) {
V_15 = V_8 -> V_26 [ V_11 ] . V_15 ;
F_10 ( V_8 -> V_22 , V_8 -> V_23 ,
V_15 , 1 ) ;
}
return V_25 ;
}
static void F_12 ( struct V_27 * V_28 )
{
struct V_1 * V_29 =
F_13 ( V_28 , struct V_1 ,
V_30 ) ;
F_10 ( V_29 -> V_22 , V_29 -> V_23 , V_29 -> V_24 , 0 ) ;
F_7 ( & V_29 -> V_20 ) ;
if ( V_29 -> V_21 ) {
F_14 ( V_29 -> V_31 ) ;
V_29 -> V_21 = false ;
}
F_9 ( & V_29 -> V_20 ) ;
}
static void F_15 ( struct V_22 * V_22 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_30 . V_32 != - 1 )
F_16 ( V_22 ,
& V_8 -> V_30 ) ;
F_10 ( V_8 -> V_22 , V_8 -> V_23 ,
V_8 -> V_24 , 0 ) ;
if ( V_8 -> V_23 != - 1 )
F_17 ( V_22 , V_8 -> V_23 ) ;
V_8 -> V_23 = - 1 ;
V_8 -> V_18 &= ~ ( V_33 ) ;
}
static void F_18 ( struct V_22 * V_22 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_18 & V_34 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_19 ( V_8 -> V_13 [ V_10 ] . V_15 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_20 ( V_8 -> V_13 [ V_10 ] . V_15 ,
V_8 ) ;
V_8 -> V_14 = 0 ;
F_21 ( V_8 -> V_13 ) ;
F_21 ( V_8 -> V_26 ) ;
F_22 ( V_8 -> V_29 ) ;
} else {
F_19 ( V_8 -> V_31 ) ;
F_20 ( V_8 -> V_31 , V_8 ) ;
if ( V_8 -> V_18 & V_35 )
F_23 ( V_8 -> V_29 ) ;
}
V_8 -> V_18 &= ~ ( V_36 ) ;
}
static int F_24 ( struct V_22 * V_22 ,
struct V_1 * V_8 ,
unsigned long V_18 )
{
unsigned long V_37 , V_38 ;
if ( ! F_25 ( V_22 ) )
return - V_39 ;
if ( ! V_8 -> V_18 )
return - V_40 ;
V_38 = V_18 & V_36 ;
V_37 = V_18 & V_33 ;
if ( V_38 )
F_18 ( V_22 , V_8 ) ;
if ( V_37 )
F_15 ( V_22 , V_8 ) ;
return 0 ;
}
static void F_26 ( struct V_22 * V_22 ,
struct V_1 * V_8 )
{
F_24 ( V_22 , V_8 , V_8 -> V_18 ) ;
}
static void F_27 ( struct V_22 * V_22 ,
struct V_1
* V_8 )
{
F_26 ( V_22 , V_8 ) ;
F_28 ( V_8 -> V_29 ) ;
if ( F_29 ( V_8 -> V_29 ,
& V_8 -> V_41 ) )
F_5 ( V_42 L_2 ,
V_43 , F_30 ( & V_8 -> V_29 -> V_29 ) ) ;
else
F_31 ( V_8 -> V_29 ) ;
V_8 -> V_29 -> V_44 &= ~ V_45 ;
F_32 ( V_8 -> V_29 ) ;
F_33 ( V_8 -> V_29 ) ;
F_34 ( V_8 -> V_29 ) ;
F_35 ( & V_8 -> V_7 ) ;
F_21 ( V_8 ) ;
}
void F_36 ( struct V_22 * V_22 )
{
struct V_2 * V_5 , * V_46 ;
struct V_1 * V_8 ;
F_37 (ptr, ptr2, &kvm->arch.assigned_dev_head) {
V_8 = F_3 ( V_5 ,
struct V_1 ,
V_7 ) ;
F_27 ( V_22 , V_8 ) ;
}
}
static int F_38 ( struct V_22 * V_22 ,
struct V_1 * V_29 )
{
V_29 -> V_31 = V_29 -> V_29 -> V_9 ;
if ( F_39 ( V_29 -> V_31 , NULL , F_6 ,
V_47 , V_29 -> V_48 , V_29 ) )
return - V_49 ;
return 0 ;
}
static int F_40 ( struct V_22 * V_22 ,
struct V_1 * V_29 )
{
int V_50 ;
if ( ! V_29 -> V_29 -> V_51 ) {
V_50 = F_41 ( V_29 -> V_29 ) ;
if ( V_50 )
return V_50 ;
}
V_29 -> V_31 = V_29 -> V_29 -> V_9 ;
if ( F_39 ( V_29 -> V_31 , NULL , F_6 ,
0 , V_29 -> V_48 , V_29 ) ) {
F_23 ( V_29 -> V_29 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_42 ( struct V_22 * V_22 ,
struct V_1 * V_29 )
{
int V_10 , V_50 = - V_39 ;
if ( V_29 -> V_14 == 0 )
return V_50 ;
V_50 = F_43 ( V_29 -> V_29 , V_29 -> V_13 , V_29 -> V_14 ) ;
if ( V_50 )
return V_50 ;
for ( V_10 = 0 ; V_10 < V_29 -> V_14 ; V_10 ++ ) {
V_50 = F_39 ( V_29 -> V_13 [ V_10 ] . V_15 ,
NULL , F_11 ,
0 , V_29 -> V_48 , V_29 ) ;
if ( V_50 )
goto V_52;
}
return 0 ;
V_52:
for ( V_10 -= 1 ; V_10 >= 0 ; V_10 -- )
F_20 ( V_29 -> V_13 [ V_10 ] . V_15 , V_29 ) ;
F_22 ( V_29 -> V_29 ) ;
return V_50 ;
}
static int F_44 ( struct V_22 * V_22 ,
struct V_1 * V_29 ,
struct V_53 * V_9 )
{
V_29 -> V_24 = V_9 -> V_24 ;
V_29 -> V_30 . V_32 = V_9 -> V_24 ;
return 0 ;
}
static int F_45 ( struct V_22 * V_22 ,
struct V_1 * V_29 ,
struct V_53 * V_9 )
{
V_29 -> V_24 = V_9 -> V_24 ;
V_29 -> V_30 . V_32 = - 1 ;
V_29 -> V_21 = false ;
return 0 ;
}
static int F_46 ( struct V_22 * V_22 ,
struct V_1 * V_29 ,
struct V_53 * V_9 )
{
V_29 -> V_24 = V_9 -> V_24 ;
V_29 -> V_30 . V_32 = - 1 ;
V_29 -> V_21 = false ;
return 0 ;
}
static int F_47 ( struct V_22 * V_22 ,
struct V_1 * V_29 ,
T_3 V_38 )
{
int V_50 = - V_54 ;
if ( V_29 -> V_18 & V_36 )
return V_50 ;
snprintf ( V_29 -> V_48 , sizeof( V_29 -> V_48 ) , L_3 ,
F_48 ( V_29 -> V_29 ) ) ;
switch ( V_38 ) {
case V_19 :
V_50 = F_38 ( V_22 , V_29 ) ;
break;
#ifdef F_49
case V_35 :
V_50 = F_40 ( V_22 , V_29 ) ;
break;
#endif
#ifdef F_50
case V_34 :
V_50 = F_42 ( V_22 , V_29 ) ;
break;
#endif
default:
V_50 = - V_39 ;
}
if ( ! V_50 )
V_29 -> V_18 |= V_38 ;
return V_50 ;
}
static int F_51 ( struct V_22 * V_22 ,
struct V_1 * V_29 ,
struct V_53 * V_9 ,
unsigned long V_37 )
{
int V_55 ;
int V_50 = - V_54 ;
if ( V_29 -> V_18 & V_33 )
return V_50 ;
V_55 = F_52 ( V_22 ) ;
if ( V_55 < 0 )
return V_55 ;
V_29 -> V_23 = V_55 ;
switch ( V_37 ) {
case V_56 :
V_50 = F_44 ( V_22 , V_29 , V_9 ) ;
break;
#ifdef F_49
case V_57 :
V_50 = F_45 ( V_22 , V_29 , V_9 ) ;
break;
#endif
#ifdef F_50
case V_58 :
V_50 = F_46 ( V_22 , V_29 , V_9 ) ;
break;
#endif
default:
V_50 = - V_39 ;
}
if ( ! V_50 ) {
V_29 -> V_18 |= V_37 ;
if ( V_29 -> V_30 . V_32 != - 1 )
F_53 ( V_22 , & V_29 -> V_30 ) ;
} else
F_17 ( V_22 , V_29 -> V_23 ) ;
return V_50 ;
}
static int F_54 ( struct V_22 * V_22 ,
struct V_53 * V_59 )
{
int V_50 = - V_39 ;
struct V_1 * V_6 ;
unsigned long V_38 , V_37 ;
if ( ! F_25 ( V_22 ) )
return V_50 ;
F_55 ( & V_22 -> V_60 ) ;
V_50 = - V_61 ;
V_6 = F_1 ( & V_22 -> V_62 . V_63 ,
V_59 -> V_4 ) ;
if ( ! V_6 )
goto V_64;
V_38 = ( V_59 -> V_65 & V_36 ) ;
V_37 = ( V_59 -> V_65 & V_33 ) ;
V_50 = - V_39 ;
if ( F_56 ( V_38 ) > 1 )
goto V_64;
if ( F_56 ( V_37 ) > 1 )
goto V_64;
if ( V_38 == 0 && V_37 == 0 )
goto V_64;
V_50 = 0 ;
if ( V_38 )
V_50 = F_47 ( V_22 , V_6 , V_38 ) ;
if ( V_50 )
goto V_64;
if ( V_37 )
V_50 = F_51 ( V_22 , V_6 , V_59 , V_37 ) ;
V_64:
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
}
static int F_58 ( struct V_22 * V_22 ,
struct V_53
* V_59 )
{
int V_50 = - V_61 ;
struct V_1 * V_6 ;
F_55 ( & V_22 -> V_60 ) ;
V_6 = F_1 ( & V_22 -> V_62 . V_63 ,
V_59 -> V_4 ) ;
if ( ! V_6 )
goto V_64;
V_50 = F_24 ( V_22 , V_6 , V_59 -> V_65 ) ;
V_64:
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
}
static int F_59 ( struct V_66 * V_29 )
{
#ifdef F_60
int V_10 ;
bool V_67 = false ;
for ( V_10 = V_68 ; V_10 <= V_69 ; V_10 ++ ) {
char * V_70 , * V_71 ;
struct V_72 V_72 ;
struct V_73 * V_73 ;
int V_50 ;
if ( ! F_61 ( V_29 , V_10 ) )
continue;
V_70 = F_62 ( & V_29 -> V_29 . V_74 , V_75 ) ;
if ( ! V_70 )
return - V_76 ;
V_71 = F_63 ( V_75 , L_4 , V_70 , V_10 ) ;
F_21 ( V_70 ) ;
if ( ! V_71 )
return - V_76 ;
V_50 = F_64 ( V_71 , V_77 , & V_72 ) ;
F_21 ( V_71 ) ;
if ( V_50 )
return V_50 ;
V_73 = V_72 . V_78 -> V_79 ;
V_50 = F_65 ( V_73 , V_80 | V_81 | V_82 ) ;
F_66 ( & V_72 ) ;
if ( V_50 )
return V_50 ;
V_67 = true ;
}
if ( ! V_67 )
return - V_83 ;
return 0 ;
#else
return - V_39 ;
#endif
}
static int F_67 ( struct V_22 * V_22 ,
struct V_84 * V_8 )
{
int V_50 = 0 , V_85 ;
struct V_1 * V_6 ;
struct V_66 * V_29 ;
T_4 V_86 ;
if ( ! ( V_8 -> V_65 & V_87 ) )
return - V_39 ;
F_55 ( & V_22 -> V_60 ) ;
V_85 = F_68 ( & V_22 -> V_88 ) ;
V_6 = F_1 ( & V_22 -> V_62 . V_63 ,
V_8 -> V_4 ) ;
if ( V_6 ) {
V_50 = - V_54 ;
goto V_64;
}
V_6 = F_69 ( sizeof( struct V_1 ) , V_75 ) ;
if ( V_6 == NULL ) {
F_5 ( V_42 L_5 ,
V_43 ) ;
V_50 = - V_76 ;
goto V_64;
}
V_29 = F_70 ( V_8 -> V_89 ,
V_8 -> V_90 ,
V_8 -> V_91 ) ;
if ( ! V_29 ) {
F_5 ( V_42 L_6 , V_43 ) ;
V_50 = - V_39 ;
goto V_92;
}
F_71 ( V_29 , V_93 , & V_86 ) ;
if ( ( V_86 & V_93 ) != V_94 ) {
V_50 = - V_83 ;
goto V_95;
}
V_50 = F_59 ( V_29 ) ;
if ( V_50 )
goto V_95;
if ( F_72 ( V_29 ) ) {
F_5 ( V_42 L_7 , V_43 ) ;
V_50 = - V_96 ;
goto V_95;
}
V_50 = F_73 ( V_29 , L_8 ) ;
if ( V_50 ) {
F_5 ( V_42 L_9 ,
V_43 ) ;
goto V_97;
}
F_28 ( V_29 ) ;
F_74 ( V_29 ) ;
V_6 -> V_41 = F_75 ( V_29 ) ;
if ( ! V_6 -> V_41 )
F_5 ( V_98 L_10 ,
V_43 , F_30 ( & V_29 -> V_29 ) ) ;
V_6 -> V_4 = V_8 -> V_4 ;
V_6 -> V_99 = V_8 -> V_89 ;
V_6 -> V_100 = V_8 -> V_90 ;
V_6 -> V_101 = V_8 -> V_91 ;
V_6 -> V_65 = V_8 -> V_65 ;
V_6 -> V_29 = V_29 ;
F_76 ( & V_6 -> V_20 ) ;
V_6 -> V_23 = - 1 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_30 . V_102 = F_12 ;
F_77 ( & V_6 -> V_7 , & V_22 -> V_62 . V_63 ) ;
if ( ! V_22 -> V_62 . V_103 ) {
V_50 = F_78 ( V_22 ) ;
if ( V_50 )
goto V_104;
}
V_50 = F_79 ( V_22 , V_6 ) ;
if ( V_50 )
goto V_104;
V_64:
F_80 ( & V_22 -> V_88 , V_85 ) ;
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
V_104:
if ( F_29 ( V_29 , & V_6 -> V_41 ) )
F_5 ( V_42 L_2 ,
V_43 , F_30 ( & V_29 -> V_29 ) ) ;
F_35 ( & V_6 -> V_7 ) ;
F_32 ( V_29 ) ;
V_97:
F_33 ( V_29 ) ;
V_95:
F_34 ( V_29 ) ;
V_92:
F_21 ( V_6 ) ;
F_80 ( & V_22 -> V_88 , V_85 ) ;
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
}
static int F_81 ( struct V_22 * V_22 ,
struct V_84 * V_8 )
{
int V_50 = 0 ;
struct V_1 * V_6 ;
F_55 ( & V_22 -> V_60 ) ;
V_6 = F_1 ( & V_22 -> V_62 . V_63 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
F_5 ( V_42 L_11
L_12 , V_43 ) ;
V_50 = - V_39 ;
goto V_64;
}
F_82 ( V_22 , V_6 ) ;
F_27 ( V_22 , V_6 ) ;
V_64:
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
}
static int F_83 ( struct V_22 * V_22 ,
struct V_105 * V_106 )
{
int V_50 = 0 ;
struct V_1 * V_107 ;
F_55 ( & V_22 -> V_60 ) ;
V_107 = F_1 ( & V_22 -> V_62 . V_63 ,
V_106 -> V_4 ) ;
if ( ! V_107 ) {
V_50 = - V_39 ;
goto V_108;
}
if ( V_107 -> V_14 == 0 ) {
V_107 -> V_14 = V_106 -> V_106 ;
if ( V_107 -> V_14 == 0 ||
V_107 -> V_14 > V_109 ) {
V_50 = - V_39 ;
goto V_108;
}
V_107 -> V_13 = F_69 ( sizeof( struct V_12 ) *
V_106 -> V_106 ,
V_75 ) ;
if ( ! V_107 -> V_13 ) {
V_50 = - V_76 ;
goto V_108;
}
V_107 -> V_26 =
F_69 ( sizeof( struct V_12 ) * V_106 -> V_106 ,
V_75 ) ;
if ( ! V_107 -> V_26 ) {
F_21 ( V_107 -> V_13 ) ;
V_50 = - V_76 ;
goto V_108;
}
} else
V_50 = - V_39 ;
V_108:
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
}
static int F_84 ( struct V_22 * V_22 ,
struct V_110 * V_111 )
{
int V_50 = 0 , V_10 ;
struct V_1 * V_107 ;
F_55 ( & V_22 -> V_60 ) ;
V_107 = F_1 ( & V_22 -> V_62 . V_63 ,
V_111 -> V_4 ) ;
if ( ! V_107 ) {
V_50 = - V_39 ;
goto V_112;
}
for ( V_10 = 0 ; V_10 < V_107 -> V_14 ; V_10 ++ )
if ( V_107 -> V_26 [ V_10 ] . V_15 == 0 ||
V_107 -> V_26 [ V_10 ] . V_111 == V_111 -> V_111 ) {
V_107 -> V_26 [ V_10 ] . V_111 = V_111 -> V_111 ;
V_107 -> V_26 [ V_10 ] . V_15 = V_111 -> V_32 ;
V_107 -> V_13 [ V_10 ] . V_111 = V_111 -> V_111 ;
break;
}
if ( V_10 == V_107 -> V_14 ) {
V_50 = - V_113 ;
goto V_112;
}
V_112:
F_57 ( & V_22 -> V_60 ) ;
return V_50 ;
}
long F_85 ( struct V_22 * V_22 , unsigned V_114 ,
unsigned long V_115 )
{
void T_5 * V_116 = ( void T_5 * ) V_115 ;
int V_50 ;
switch ( V_114 ) {
case V_117 : {
struct V_84 V_8 ;
V_50 = - V_118 ;
if ( F_86 ( & V_8 , V_116 , sizeof V_8 ) )
goto V_64;
V_50 = F_67 ( V_22 , & V_8 ) ;
if ( V_50 )
goto V_64;
break;
}
case V_119 : {
V_50 = - V_120 ;
break;
}
case V_121 : {
struct V_53 V_59 ;
V_50 = - V_118 ;
if ( F_86 ( & V_59 , V_116 , sizeof V_59 ) )
goto V_64;
V_50 = F_54 ( V_22 , & V_59 ) ;
if ( V_50 )
goto V_64;
break;
}
case V_122 : {
struct V_53 V_59 ;
V_50 = - V_118 ;
if ( F_86 ( & V_59 , V_116 , sizeof V_59 ) )
goto V_64;
V_50 = F_58 ( V_22 , & V_59 ) ;
if ( V_50 )
goto V_64;
break;
}
case V_123 : {
struct V_84 V_8 ;
V_50 = - V_118 ;
if ( F_86 ( & V_8 , V_116 , sizeof V_8 ) )
goto V_64;
V_50 = F_81 ( V_22 , & V_8 ) ;
if ( V_50 )
goto V_64;
break;
}
#ifdef F_87
case V_124 : {
struct V_125 V_126 ;
struct V_125 T_5 * V_127 ;
struct V_128 * V_129 ;
V_50 = - V_118 ;
if ( F_86 ( & V_126 , V_116 , sizeof( V_126 ) ) )
goto V_64;
V_50 = - V_39 ;
if ( V_126 . V_130 >= V_131 )
goto V_64;
if ( V_126 . V_65 )
goto V_64;
V_50 = - V_76 ;
V_129 = F_88 ( V_126 . V_130 * sizeof( * V_129 ) ) ;
if ( ! V_129 )
goto V_64;
V_50 = - V_118 ;
V_127 = V_116 ;
if ( F_86 ( V_129 , V_127 -> V_129 ,
V_126 . V_130 * sizeof( * V_129 ) ) )
goto V_132;
V_50 = F_89 ( V_22 , V_129 , V_126 . V_130 ,
V_126 . V_65 ) ;
V_132:
F_90 ( V_129 ) ;
break;
}
#endif
#ifdef F_50
case V_133 : {
struct V_105 V_106 ;
V_50 = - V_118 ;
if ( F_86 ( & V_106 , V_116 , sizeof V_106 ) )
goto V_64;
V_50 = F_83 ( V_22 , & V_106 ) ;
if ( V_50 )
goto V_64;
break;
}
case V_134 : {
struct V_110 V_111 ;
V_50 = - V_118 ;
if ( F_86 ( & V_111 , V_116 , sizeof V_111 ) )
goto V_64;
V_50 = F_84 ( V_22 , & V_111 ) ;
if ( V_50 )
goto V_64;
break;
}
#endif
default:
V_50 = - V_135 ;
break;
}
V_64:
return V_50 ;
}
