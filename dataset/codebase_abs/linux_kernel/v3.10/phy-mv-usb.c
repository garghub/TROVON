static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_6 ) ;
if ( V_5 -> V_7 -> V_8 == NULL )
return - V_9 ;
return V_5 -> V_7 -> V_8 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_2 -> V_11 = V_11 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
V_2 -> V_13 = V_13 ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
unsigned long V_14 )
{
F_6 ( & V_5 -> V_15 -> V_16 , L_1 ) ;
if ( ! V_5 -> V_17 )
return;
F_7 ( V_5 -> V_17 , & V_5 -> V_18 , V_14 ) ;
}
static void F_8 ( unsigned long V_19 )
{
struct V_4 * V_5 = (struct V_4 * ) V_19 ;
V_5 -> V_20 . V_21 = 1 ;
F_9 ( & V_5 -> V_15 -> V_16 , L_2 ) ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_23 )
{
struct V_24 * V_25 ;
if ( V_23 >= V_26 )
return - V_27 ;
V_25 = & V_5 -> V_20 . V_25 [ V_23 ] ;
if ( F_13 ( V_25 ) )
F_14 ( V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_23 ,
unsigned long V_28 ,
void (* F_16) ( unsigned long ) )
{
struct V_24 * V_25 ;
if ( V_23 >= V_26 )
return - V_27 ;
V_25 = & V_5 -> V_20 . V_25 [ V_23 ] ;
if ( F_13 ( V_25 ) ) {
F_17 ( & V_5 -> V_15 -> V_16 , L_3 , V_23 ) ;
return - V_29 ;
}
F_18 ( V_25 ) ;
V_25 -> V_19 = ( unsigned long ) V_5 ;
V_25 -> V_30 = F_16 ;
V_25 -> V_31 = V_32 + V_28 ;
F_19 ( V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
unsigned int V_33 ;
T_1 V_34 ;
V_34 = F_21 ( & V_5 -> V_35 -> V_36 ) ;
V_34 &= ~ V_37 ;
F_22 ( V_34 , & V_5 -> V_35 -> V_36 ) ;
F_22 ( V_38 , & V_5 -> V_35 -> V_36 ) ;
V_33 = 500 ;
while ( F_21 ( & V_5 -> V_35 -> V_36 ) & V_38 ) {
if ( V_33 == 0 ) {
F_17 ( & V_5 -> V_15 -> V_16 ,
L_4 ) ;
return - V_39 ;
}
V_33 -- ;
F_23 ( 20 ) ;
}
F_22 ( 0x0 , & V_5 -> V_35 -> V_40 ) ;
V_34 = F_21 ( & V_5 -> V_35 -> V_41 ) ;
F_22 ( V_34 , & V_5 -> V_35 -> V_41 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
T_1 V_42 ;
V_5 -> V_43 = V_44
| V_45 ;
V_5 -> V_46 = V_47
| V_48 ;
if ( V_5 -> V_7 -> V_49 == NULL ) {
V_5 -> V_43 |= V_50
| V_51 ;
V_5 -> V_46 |= V_52
| V_53 ;
}
if ( V_5 -> V_7 -> V_23 == NULL ) {
V_5 -> V_43 |= V_54 ;
V_5 -> V_46 |= V_55 ;
}
V_42 = F_21 ( & V_5 -> V_35 -> V_42 ) ;
V_42 |= V_5 -> V_43 ;
F_22 ( V_42 , & V_5 -> V_35 -> V_42 ) ;
}
static void F_25 ( struct V_4 * V_5 , int V_3 )
{
#ifdef F_26
struct V_1 * V_2 = V_5 -> V_6 . V_2 ;
struct V_56 * V_57 ;
if ( ! V_2 -> V_11 )
return;
F_9 ( & V_5 -> V_15 -> V_16 , L_5 , V_3 ? L_6 : L_7 ) ;
V_57 = F_27 ( V_2 -> V_11 ) ;
if ( V_3 )
F_28 ( V_57 , V_57 -> V_58 , V_59 ) ;
else
F_29 ( V_57 ) ;
#endif
}
static void F_30 ( struct V_4 * V_5 , int V_3 )
{
struct V_1 * V_2 = V_5 -> V_6 . V_2 ;
if ( ! V_2 -> V_13 )
return;
F_9 ( V_5 -> V_6 . V_16 , L_8 , V_3 ? L_9 : L_10 ) ;
if ( V_3 )
F_31 ( V_2 -> V_13 ) ;
else
F_32 ( V_2 -> V_13 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
F_34 ( V_5 -> V_60 ) ;
}
static void F_35 ( struct V_4 * V_5 )
{
F_36 ( V_5 -> V_60 ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
int V_61 = 0 ;
if ( V_5 -> V_62 )
return 0 ;
F_6 ( & V_5 -> V_15 -> V_16 , L_11 ) ;
F_33 ( V_5 ) ;
if ( V_5 -> V_7 -> V_63 ) {
V_61 = V_5 -> V_7 -> V_63 ( V_5 -> V_64 ) ;
if ( V_61 ) {
F_17 ( & V_5 -> V_15 -> V_16 ,
L_12 , V_61 ) ;
F_35 ( V_5 ) ;
return V_61 ;
}
}
V_5 -> V_62 = 1 ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 )
{
if ( V_5 -> V_65 )
return F_37 ( V_5 ) ;
return 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
if ( V_5 -> V_62 ) {
F_6 ( & V_5 -> V_15 -> V_16 , L_13 ) ;
if ( V_5 -> V_7 -> V_66 )
V_5 -> V_7 -> V_66 ( V_5 -> V_64 ) ;
F_35 ( V_5 ) ;
V_5 -> V_62 = 0 ;
}
}
static void F_40 ( struct V_4 * V_5 )
{
if ( V_5 -> V_65 )
F_39 ( V_5 ) ;
}
static void F_41 ( struct V_4 * V_5 )
{
struct V_67 * V_20 = & V_5 -> V_20 ;
T_1 V_42 ;
V_42 = F_21 ( & V_5 -> V_35 -> V_42 ) ;
if ( V_5 -> V_7 -> V_49 ) {
if ( V_5 -> V_7 -> V_49 -> V_68 () == V_69 ) {
V_20 -> V_70 = 1 ;
V_20 -> V_71 = 0 ;
} else {
V_20 -> V_70 = 0 ;
V_20 -> V_71 = 1 ;
}
} else {
V_20 -> V_70 = ! ! ( V_42 & V_72 ) ;
V_20 -> V_71 = ! ! ( V_42 & V_73 ) ;
}
if ( V_5 -> V_7 -> V_23 )
V_20 -> V_23 = ! ! V_5 -> V_7 -> V_23 -> V_68 () ;
else
V_20 -> V_23 = ! ! ( V_42 & V_74 ) ;
if ( V_5 -> V_7 -> V_75 && ! V_20 -> V_23 )
V_20 -> V_76 = 1 ;
V_20 -> V_77 = ! ! ( V_42 & V_78 ) ;
V_20 -> V_79 = ! ! ( V_42 & V_80 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_14 , V_81 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_15 , V_20 -> V_23 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_16 , V_20 -> V_70 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_17 , V_20 -> V_71 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_18 , V_20 -> V_79 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_19 , V_20 -> V_77 ) ;
}
static void F_42 ( struct V_4 * V_5 )
{
struct V_67 * V_20 = & V_5 -> V_20 ;
struct V_82 * V_6 = & V_5 -> V_6 ;
int V_83 = V_6 -> V_84 ;
switch ( V_83 ) {
case V_85 :
V_6 -> V_84 = V_86 ;
case V_86 :
if ( V_20 -> V_23 == 0 )
V_6 -> V_84 = V_87 ;
else if ( V_20 -> V_70 )
V_6 -> V_84 = V_88 ;
break;
case V_88 :
if ( ! V_20 -> V_70 || V_20 -> V_23 == 0 )
V_6 -> V_84 = V_86 ;
break;
case V_87 :
if ( V_20 -> V_23 )
V_6 -> V_84 = V_86 ;
else if ( ! ( V_20 -> V_89 ) &&
( V_20 -> V_76 || V_20 -> V_90 ) )
V_6 -> V_84 = V_91 ;
break;
case V_91 :
if ( V_20 -> V_79 )
V_6 -> V_84 = V_92 ;
break;
case V_92 :
if ( V_20 -> V_23 || V_20 -> V_89
|| V_20 -> V_21 ) {
F_12 ( V_5 , V_93 ) ;
V_5 -> V_20 . V_21 = 0 ;
V_6 -> V_84 = V_94 ;
V_20 -> V_76 = 0 ;
} else if ( ! V_20 -> V_79 ) {
F_12 ( V_5 , V_93 ) ;
V_5 -> V_20 . V_21 = 0 ;
V_6 -> V_84 = V_95 ;
} else if ( V_20 -> V_96 ) {
F_12 ( V_5 , V_93 ) ;
V_5 -> V_20 . V_21 = 0 ;
V_6 -> V_84 = V_97 ;
}
break;
case V_97 :
if ( V_20 -> V_23 || ! V_20 -> V_96
|| V_20 -> V_89 )
V_6 -> V_84 = V_92 ;
else if ( ! V_20 -> V_79 )
V_6 -> V_84 = V_95 ;
break;
case V_94 :
if ( V_20 -> V_23
|| ( ! V_20 -> V_96 && V_20 -> V_77 )
|| V_20 -> V_76 )
V_6 -> V_84 = V_87 ;
break;
case V_95 :
if ( V_20 -> V_23 || V_20 -> V_98
|| V_20 -> V_89 ) {
V_20 -> V_98 = 0 ;
V_6 -> V_84 = V_94 ;
}
break;
default:
break;
}
}
static void F_43 ( struct V_99 * V_18 )
{
struct V_4 * V_5 ;
struct V_82 * V_6 ;
struct V_1 * V_2 ;
int V_83 ;
V_5 = F_2 ( F_44 ( V_18 ) , struct V_4 , V_18 ) ;
V_100:
V_6 = & V_5 -> V_6 ;
V_2 = V_6 -> V_2 ;
V_83 = V_6 -> V_84 ;
if ( ! V_5 -> V_62 )
return;
F_41 ( V_5 ) ;
F_42 ( V_5 ) ;
if ( V_83 != V_6 -> V_84 ) {
F_9 ( & V_5 -> V_15 -> V_16 , L_20 ,
V_101 [ V_83 ] ,
V_101 [ V_6 -> V_84 ] ) ;
switch ( V_6 -> V_84 ) {
case V_86 :
V_2 -> V_102 = 0 ;
if ( V_83 == V_88 )
F_30 ( V_5 , 0 ) ;
F_20 ( V_5 ) ;
F_40 ( V_5 ) ;
break;
case V_88 :
F_38 ( V_5 ) ;
F_30 ( V_5 , 1 ) ;
break;
case V_87 :
V_2 -> V_102 = 1 ;
F_38 ( V_5 ) ;
if ( V_83 == V_94 )
F_25 ( V_5 , 0 ) ;
F_20 ( V_5 ) ;
break;
case V_91 :
F_1 ( V_2 , 1 ) ;
break;
case V_92 :
if ( V_83 != V_97 )
F_25 ( V_5 , 1 ) ;
F_15 ( V_5 , V_93 ,
V_103 ,
F_8 ) ;
V_5 -> V_20 . V_96 = 1 ;
break;
case V_97 :
break;
case V_94 :
V_5 -> V_20 . V_96 = 0 ;
F_1 ( V_2 , 0 ) ;
break;
case V_95 :
break;
default:
break;
}
goto V_100;
}
}
static T_2 F_45 ( int V_58 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
T_1 V_42 ;
V_42 = F_21 ( & V_5 -> V_35 -> V_42 ) ;
F_22 ( V_42 , & V_5 -> V_35 -> V_42 ) ;
if ( V_5 -> V_7 -> V_49 )
if ( ( V_42 & V_74 ) &&
! ( V_42 & V_55 ) )
return V_104 ;
if ( ( V_42 & V_5 -> V_46 ) == 0 )
return V_104 ;
F_5 ( V_5 , 0 ) ;
return V_105 ;
}
static T_2 F_46 ( int V_58 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
if ( ! V_5 -> V_62 ) {
F_38 ( V_5 ) ;
F_24 ( V_5 ) ;
}
F_5 ( V_5 , 0 ) ;
return V_105 ;
}
static T_3
F_47 ( struct V_106 * V_16 , struct V_107 * V_108 , char * V_109 )
{
struct V_4 * V_5 = F_48 ( V_16 ) ;
return F_49 ( V_109 , V_110 , L_21 ,
V_5 -> V_20 . V_76 ) ;
}
static T_3
F_50 ( struct V_106 * V_16 , struct V_107 * V_108 ,
const char * V_109 , T_4 V_111 )
{
struct V_4 * V_5 = F_48 ( V_16 ) ;
if ( V_111 > 2 )
return - 1 ;
if ( V_5 -> V_6 . V_84 != V_86
&& V_5 -> V_6 . V_84 != V_87 )
return - 1 ;
F_38 ( V_5 ) ;
F_24 ( V_5 ) ;
if ( V_109 [ 0 ] == '1' ) {
V_5 -> V_20 . V_76 = 1 ;
V_5 -> V_20 . V_89 = 0 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_22 ) ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
}
return V_111 ;
}
static T_3
F_51 ( struct V_106 * V_16 , struct V_107 * V_108 ,
const char * V_109 , T_4 V_111 )
{
struct V_4 * V_5 = F_48 ( V_16 ) ;
if ( ! V_5 -> V_6 . V_2 -> V_102 )
return - 1 ;
if ( V_111 > 2 )
return - 1 ;
if ( V_109 [ 0 ] == '1' ) {
V_5 -> V_20 . V_98 = 1 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_23 ) ;
}
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
return V_111 ;
}
static T_3
F_52 ( struct V_106 * V_16 , struct V_107 * V_108 ,
char * V_109 )
{
struct V_4 * V_5 = F_48 ( V_16 ) ;
return F_49 ( V_109 , V_110 , L_21 ,
V_5 -> V_20 . V_89 ) ;
}
static T_3
F_53 ( struct V_106 * V_16 , struct V_107 * V_108 ,
const char * V_109 , T_4 V_111 )
{
struct V_4 * V_5 = F_48 ( V_16 ) ;
if ( ! V_5 -> V_6 . V_2 -> V_102 )
return - 1 ;
if ( V_111 > 2 )
return - 1 ;
if ( V_109 [ 0 ] == '0' ) {
V_5 -> V_20 . V_89 = 0 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_24 ) ;
} else if ( V_109 [ 0 ] == '1' ) {
V_5 -> V_20 . V_89 = 1 ;
V_5 -> V_20 . V_76 = 0 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_25 ) ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_26 ) ;
}
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
return V_111 ;
}
int F_54 ( struct V_112 * V_15 )
{
struct V_4 * V_5 = F_55 ( V_15 ) ;
F_56 ( & V_5 -> V_15 -> V_16 . V_113 , & V_114 ) ;
if ( V_5 -> V_17 ) {
F_57 ( V_5 -> V_17 ) ;
F_58 ( V_5 -> V_17 ) ;
}
F_40 ( V_5 ) ;
F_59 ( & V_5 -> V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_112 * V_15 )
{
struct V_115 * V_7 = V_15 -> V_16 . V_116 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_117 * V_118 ;
int V_61 = 0 , V_119 ;
if ( V_7 == NULL ) {
F_17 ( & V_15 -> V_16 , L_27 ) ;
return - V_9 ;
}
V_5 = F_61 ( & V_15 -> V_16 , sizeof( * V_5 ) , V_120 ) ;
if ( ! V_5 ) {
F_17 ( & V_15 -> V_16 , L_28 ) ;
return - V_121 ;
}
V_2 = F_61 ( & V_15 -> V_16 , sizeof( * V_2 ) , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
F_62 ( V_15 , V_5 ) ;
V_5 -> V_15 = V_15 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_60 = F_63 ( & V_15 -> V_16 , NULL ) ;
if ( F_64 ( V_5 -> V_60 ) )
return F_65 ( V_5 -> V_60 ) ;
V_5 -> V_17 = F_66 ( L_29 ) ;
if ( ! V_5 -> V_17 ) {
F_6 ( & V_15 -> V_16 , L_30 ) ;
return - V_121 ;
}
F_67 ( & V_5 -> V_18 , F_43 ) ;
V_5 -> V_15 = V_15 ;
V_5 -> V_6 . V_16 = & V_15 -> V_16 ;
V_5 -> V_6 . V_2 = V_2 ;
V_5 -> V_6 . V_122 = V_123 ;
V_5 -> V_6 . V_84 = V_85 ;
V_2 -> V_6 = & V_5 -> V_6 ;
V_2 -> V_124 = F_3 ;
V_2 -> V_125 = F_4 ;
V_2 -> V_8 = F_1 ;
for ( V_119 = 0 ; V_119 < V_26 ; V_119 ++ )
F_18 ( & V_5 -> V_20 . V_25 [ V_119 ] ) ;
V_118 = F_68 ( V_5 -> V_15 ,
V_126 , L_31 ) ;
if ( V_118 == NULL ) {
F_17 ( & V_15 -> V_16 , L_32 ) ;
V_61 = - V_9 ;
goto V_127;
}
V_5 -> V_64 = F_69 ( & V_15 -> V_16 , V_118 -> V_128 , F_70 ( V_118 ) ) ;
if ( V_5 -> V_64 == NULL ) {
F_17 ( & V_15 -> V_16 , L_33 ) ;
V_61 = - V_129 ;
goto V_127;
}
V_118 = F_68 ( V_5 -> V_15 ,
V_126 , L_34 ) ;
if ( V_118 == NULL ) {
F_17 ( & V_15 -> V_16 , L_35 ) ;
V_61 = - V_9 ;
goto V_127;
}
V_5 -> V_130 = F_69 ( & V_15 -> V_16 , V_118 -> V_128 , F_70 ( V_118 ) ) ;
if ( V_5 -> V_130 == NULL ) {
F_17 ( & V_15 -> V_16 , L_36 ) ;
V_61 = - V_129 ;
goto V_127;
}
V_61 = F_37 ( V_5 ) ;
if ( V_61 ) {
F_17 ( & V_15 -> V_16 , L_37 , V_61 ) ;
goto V_127;
}
V_5 -> V_35 =
(struct V_131 V_132 * ) ( ( unsigned long ) V_5 -> V_130
+ ( F_21 ( V_5 -> V_130 ) & V_133 ) ) ;
if ( V_7 -> V_23 ) {
V_61 = F_71 ( & V_15 -> V_16 , V_7 -> V_23 -> V_58 ,
NULL , F_46 ,
V_134 , L_38 , V_5 ) ;
if ( V_61 ) {
F_9 ( & V_15 -> V_16 ,
L_39 ) ;
V_7 -> V_23 = NULL ;
}
}
if ( V_7 -> V_49 ) {
V_5 -> V_65 = 1 ;
V_61 = F_71 ( & V_15 -> V_16 , V_7 -> V_49 -> V_58 ,
NULL , F_46 ,
V_134 , L_40 , V_5 ) ;
if ( V_61 ) {
F_9 ( & V_15 -> V_16 ,
L_41
L_42 ) ;
V_5 -> V_65 = 0 ;
V_7 -> V_49 = NULL ;
}
}
if ( V_7 -> V_135 )
V_5 -> V_65 = 0 ;
F_20 ( V_5 ) ;
F_24 ( V_5 ) ;
V_118 = F_72 ( V_5 -> V_15 , V_136 , 0 ) ;
if ( V_118 == NULL ) {
F_17 ( & V_15 -> V_16 , L_43 ) ;
V_61 = - V_9 ;
goto V_137;
}
V_5 -> V_58 = V_118 -> V_128 ;
if ( F_73 ( & V_15 -> V_16 , V_5 -> V_58 , F_45 , V_59 ,
V_123 , V_5 ) ) {
F_17 ( & V_15 -> V_16 , L_44 ,
V_5 -> V_58 ) ;
V_5 -> V_58 = 0 ;
V_61 = - V_9 ;
goto V_137;
}
V_61 = F_74 ( & V_5 -> V_6 , V_138 ) ;
if ( V_61 < 0 ) {
F_17 ( & V_15 -> V_16 , L_45 ,
V_61 ) ;
goto V_137;
}
V_61 = F_75 ( & V_15 -> V_16 . V_113 , & V_114 ) ;
if ( V_61 < 0 ) {
F_6 ( & V_15 -> V_16 ,
L_46 , V_61 ) ;
goto V_139;
}
F_76 ( & V_5 -> V_22 ) ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 2 * V_140 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
F_9 ( & V_15 -> V_16 ,
L_47 ,
V_5 -> V_65 ? L_48 : L_49 ) ;
return 0 ;
V_139:
F_59 ( & V_5 -> V_6 ) ;
V_137:
F_39 ( V_5 ) ;
V_127:
F_57 ( V_5 -> V_17 ) ;
F_58 ( V_5 -> V_17 ) ;
return V_61 ;
}
static int F_77 ( struct V_112 * V_15 , T_5 V_84 )
{
struct V_4 * V_5 = F_55 ( V_15 ) ;
if ( V_5 -> V_6 . V_84 != V_86 ) {
F_9 ( & V_15 -> V_16 ,
L_50 ,
V_5 -> V_6 . V_84 ) ;
return - V_141 ;
}
if ( ! V_5 -> V_65 )
F_39 ( V_5 ) ;
return 0 ;
}
static int F_78 ( struct V_112 * V_15 )
{
struct V_4 * V_5 = F_55 ( V_15 ) ;
T_1 V_42 ;
if ( ! V_5 -> V_65 ) {
F_37 ( V_5 ) ;
V_42 = F_21 ( & V_5 -> V_35 -> V_42 ) ;
V_42 |= V_5 -> V_43 ;
F_22 ( V_42 , & V_5 -> V_35 -> V_42 ) ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
}
return 0 ;
}
