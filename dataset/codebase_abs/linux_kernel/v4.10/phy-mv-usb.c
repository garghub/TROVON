static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_7 ) ;
if ( V_5 -> V_8 -> V_9 == NULL )
return - V_10 ;
return V_5 -> V_8 -> V_9 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_2 -> V_12 = V_12 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
V_2 -> V_14 = V_14 ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
unsigned long V_15 )
{
F_6 ( & V_5 -> V_16 -> V_17 , L_1 ) ;
if ( ! V_5 -> V_18 )
return;
F_7 ( V_5 -> V_18 , & V_5 -> V_19 , V_15 ) ;
}
static void F_8 ( unsigned long V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_20 ;
V_5 -> V_21 . V_22 = 1 ;
F_9 ( & V_5 -> V_16 -> V_17 , L_2 ) ;
if ( F_10 ( & V_5 -> V_23 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_23 ) ;
}
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_24 )
{
struct V_25 * V_26 ;
if ( V_24 >= V_27 )
return - V_28 ;
V_26 = & V_5 -> V_21 . V_26 [ V_24 ] ;
if ( F_13 ( V_26 ) )
F_14 ( V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_24 ,
unsigned long V_29 ,
void (* F_16) ( unsigned long ) )
{
struct V_25 * V_26 ;
if ( V_24 >= V_27 )
return - V_28 ;
V_26 = & V_5 -> V_21 . V_26 [ V_24 ] ;
if ( F_13 ( V_26 ) ) {
F_17 ( & V_5 -> V_16 -> V_17 , L_3 , V_24 ) ;
return - V_30 ;
}
F_18 ( V_26 ) ;
V_26 -> V_20 = ( unsigned long ) V_5 ;
V_26 -> V_31 = F_16 ;
V_26 -> V_32 = V_33 + V_29 ;
F_19 ( V_26 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
unsigned int V_34 ;
T_1 V_35 ;
V_35 = F_21 ( & V_5 -> V_36 -> V_37 ) ;
V_35 &= ~ V_38 ;
F_22 ( V_35 , & V_5 -> V_36 -> V_37 ) ;
F_22 ( V_39 , & V_5 -> V_36 -> V_37 ) ;
V_34 = 500 ;
while ( F_21 ( & V_5 -> V_36 -> V_37 ) & V_39 ) {
if ( V_34 == 0 ) {
F_17 ( & V_5 -> V_16 -> V_17 ,
L_4 ) ;
return - V_40 ;
}
V_34 -- ;
F_23 ( 20 ) ;
}
F_22 ( 0x0 , & V_5 -> V_36 -> V_41 ) ;
V_35 = F_21 ( & V_5 -> V_36 -> V_42 ) ;
F_22 ( V_35 , & V_5 -> V_36 -> V_42 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
T_1 V_43 ;
V_5 -> V_44 = V_45
| V_46 ;
V_5 -> V_47 = V_48
| V_49 ;
if ( V_5 -> V_8 -> V_50 == NULL ) {
V_5 -> V_44 |= V_51
| V_52 ;
V_5 -> V_47 |= V_53
| V_54 ;
}
if ( V_5 -> V_8 -> V_24 == NULL ) {
V_5 -> V_44 |= V_55 ;
V_5 -> V_47 |= V_56 ;
}
V_43 = F_21 ( & V_5 -> V_36 -> V_43 ) ;
V_43 |= V_5 -> V_44 ;
F_22 ( V_43 , & V_5 -> V_36 -> V_43 ) ;
}
static void F_25 ( struct V_4 * V_5 , int V_3 )
{
#ifdef F_26
struct V_1 * V_2 = V_5 -> V_7 . V_2 ;
struct V_57 * V_58 ;
if ( ! V_2 -> V_12 )
return;
F_9 ( & V_5 -> V_16 -> V_17 , L_5 , V_3 ? L_6 : L_7 ) ;
V_58 = F_27 ( V_2 -> V_12 ) ;
if ( V_3 ) {
F_28 ( V_58 , V_58 -> V_59 , V_60 ) ;
F_29 ( V_58 -> V_61 . V_62 ) ;
} else {
F_30 ( V_58 ) ;
}
#endif
}
static void F_31 ( struct V_4 * V_5 , int V_3 )
{
struct V_1 * V_2 = V_5 -> V_7 . V_2 ;
if ( ! V_2 -> V_14 )
return;
F_9 ( V_5 -> V_7 . V_17 , L_8 , V_3 ? L_9 : L_10 ) ;
if ( V_3 )
F_32 ( V_2 -> V_14 ) ;
else
F_33 ( V_2 -> V_14 ) ;
}
static void F_34 ( struct V_4 * V_5 )
{
F_35 ( V_5 -> V_63 ) ;
}
static void F_36 ( struct V_4 * V_5 )
{
F_37 ( V_5 -> V_63 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
int V_64 = 0 ;
if ( V_5 -> V_65 )
return 0 ;
F_6 ( & V_5 -> V_16 -> V_17 , L_11 ) ;
F_34 ( V_5 ) ;
if ( V_5 -> V_8 -> V_66 ) {
V_64 = V_5 -> V_8 -> V_66 ( V_5 -> V_67 ) ;
if ( V_64 ) {
F_17 ( & V_5 -> V_16 -> V_17 ,
L_12 , V_64 ) ;
F_36 ( V_5 ) ;
return V_64 ;
}
}
V_5 -> V_65 = 1 ;
return 0 ;
}
static int F_39 ( struct V_4 * V_5 )
{
if ( V_5 -> V_68 )
return F_38 ( V_5 ) ;
return 0 ;
}
static void F_40 ( struct V_4 * V_5 )
{
if ( V_5 -> V_65 ) {
F_6 ( & V_5 -> V_16 -> V_17 , L_13 ) ;
if ( V_5 -> V_8 -> V_69 )
V_5 -> V_8 -> V_69 ( V_5 -> V_67 ) ;
F_36 ( V_5 ) ;
V_5 -> V_65 = 0 ;
}
}
static void F_41 ( struct V_4 * V_5 )
{
if ( V_5 -> V_68 )
F_40 ( V_5 ) ;
}
static void F_42 ( struct V_4 * V_5 )
{
struct V_70 * V_21 = & V_5 -> V_21 ;
T_1 V_43 ;
V_43 = F_21 ( & V_5 -> V_36 -> V_43 ) ;
if ( V_5 -> V_8 -> V_50 ) {
if ( V_5 -> V_8 -> V_50 -> V_71 () == V_72 ) {
V_21 -> V_73 = 1 ;
V_21 -> V_74 = 0 ;
} else {
V_21 -> V_73 = 0 ;
V_21 -> V_74 = 1 ;
}
} else {
V_21 -> V_73 = ! ! ( V_43 & V_75 ) ;
V_21 -> V_74 = ! ! ( V_43 & V_76 ) ;
}
if ( V_5 -> V_8 -> V_24 )
V_21 -> V_24 = ! ! V_5 -> V_8 -> V_24 -> V_71 () ;
else
V_21 -> V_24 = ! ! ( V_43 & V_77 ) ;
if ( V_5 -> V_8 -> V_78 && ! V_21 -> V_24 )
V_21 -> V_79 = 1 ;
V_21 -> V_80 = ! ! ( V_43 & V_81 ) ;
V_21 -> V_82 = ! ! ( V_43 & V_83 ) ;
F_6 ( & V_5 -> V_16 -> V_17 , L_14 , V_84 ) ;
F_6 ( & V_5 -> V_16 -> V_17 , L_15 , V_21 -> V_24 ) ;
F_6 ( & V_5 -> V_16 -> V_17 , L_16 , V_21 -> V_73 ) ;
F_6 ( & V_5 -> V_16 -> V_17 , L_17 , V_21 -> V_74 ) ;
F_6 ( & V_5 -> V_16 -> V_17 , L_18 , V_21 -> V_82 ) ;
F_6 ( & V_5 -> V_16 -> V_17 , L_19 , V_21 -> V_80 ) ;
}
static void F_43 ( struct V_4 * V_5 )
{
struct V_70 * V_21 = & V_5 -> V_21 ;
int V_85 = V_5 -> V_7 . V_2 -> V_86 ;
switch ( V_85 ) {
case V_87 :
V_5 -> V_7 . V_2 -> V_86 = V_88 ;
case V_88 :
if ( V_21 -> V_24 == 0 )
V_5 -> V_7 . V_2 -> V_86 = V_89 ;
else if ( V_21 -> V_73 )
V_5 -> V_7 . V_2 -> V_86 = V_90 ;
break;
case V_90 :
if ( ! V_21 -> V_73 || V_21 -> V_24 == 0 )
V_5 -> V_7 . V_2 -> V_86 = V_88 ;
break;
case V_89 :
if ( V_21 -> V_24 )
V_5 -> V_7 . V_2 -> V_86 = V_88 ;
else if ( ! ( V_21 -> V_91 ) &&
( V_21 -> V_79 || V_21 -> V_92 ) )
V_5 -> V_7 . V_2 -> V_86 = V_93 ;
break;
case V_93 :
if ( V_21 -> V_82 )
V_5 -> V_7 . V_2 -> V_86 = V_94 ;
break;
case V_94 :
if ( V_21 -> V_24 || V_21 -> V_91
|| V_21 -> V_22 ) {
F_12 ( V_5 , V_95 ) ;
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_7 . V_2 -> V_86 = V_96 ;
V_21 -> V_79 = 0 ;
} else if ( ! V_21 -> V_82 ) {
F_12 ( V_5 , V_95 ) ;
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_7 . V_2 -> V_86 = V_97 ;
} else if ( V_21 -> V_98 ) {
F_12 ( V_5 , V_95 ) ;
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_7 . V_2 -> V_86 = V_99 ;
}
break;
case V_99 :
if ( V_21 -> V_24 || ! V_21 -> V_98
|| V_21 -> V_91 )
V_5 -> V_7 . V_2 -> V_86 = V_94 ;
else if ( ! V_21 -> V_82 )
V_5 -> V_7 . V_2 -> V_86 = V_97 ;
break;
case V_96 :
if ( V_21 -> V_24
|| ( ! V_21 -> V_98 && V_21 -> V_80 )
|| V_21 -> V_79 )
V_5 -> V_7 . V_2 -> V_86 = V_89 ;
break;
case V_97 :
if ( V_21 -> V_24 || V_21 -> V_100
|| V_21 -> V_91 ) {
V_21 -> V_100 = 0 ;
V_5 -> V_7 . V_2 -> V_86 = V_96 ;
}
break;
default:
break;
}
}
static void F_44 ( struct V_101 * V_19 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_85 ;
V_5 = F_2 ( F_45 ( V_19 ) , struct V_4 , V_19 ) ;
V_102:
V_7 = & V_5 -> V_7 ;
V_2 = V_5 -> V_7 . V_2 ;
V_85 = V_2 -> V_86 ;
if ( ! V_5 -> V_65 )
return;
F_42 ( V_5 ) ;
F_43 ( V_5 ) ;
if ( V_85 != V_5 -> V_7 . V_2 -> V_86 ) {
F_9 ( & V_5 -> V_16 -> V_17 , L_20 ,
V_103 [ V_85 ] ,
V_103 [ V_5 -> V_7 . V_2 -> V_86 ] ) ;
switch ( V_5 -> V_7 . V_2 -> V_86 ) {
case V_88 :
V_2 -> V_104 = 0 ;
if ( V_85 == V_90 )
F_31 ( V_5 , 0 ) ;
F_20 ( V_5 ) ;
F_41 ( V_5 ) ;
F_46 ( & V_5 -> V_7 , V_105 ) ;
break;
case V_90 :
F_39 ( V_5 ) ;
F_31 ( V_5 , 1 ) ;
F_46 ( & V_5 -> V_7 , V_106 ) ;
break;
case V_89 :
V_2 -> V_104 = 1 ;
F_39 ( V_5 ) ;
if ( V_85 == V_96 )
F_25 ( V_5 , 0 ) ;
F_20 ( V_5 ) ;
break;
case V_93 :
F_1 ( V_2 , 1 ) ;
break;
case V_94 :
if ( V_85 != V_99 )
F_25 ( V_5 , 1 ) ;
F_15 ( V_5 , V_95 ,
V_107 ,
F_8 ) ;
V_5 -> V_21 . V_98 = 1 ;
break;
case V_99 :
break;
case V_96 :
V_5 -> V_21 . V_98 = 0 ;
F_1 ( V_2 , 0 ) ;
break;
case V_97 :
break;
default:
break;
}
goto V_102;
}
}
static T_2 F_47 ( int V_59 , void * V_17 )
{
struct V_4 * V_5 = V_17 ;
T_1 V_43 ;
V_43 = F_21 ( & V_5 -> V_36 -> V_43 ) ;
F_22 ( V_43 , & V_5 -> V_36 -> V_43 ) ;
if ( V_5 -> V_8 -> V_50 )
if ( ( V_43 & V_77 ) &&
! ( V_43 & V_56 ) )
return V_108 ;
if ( ( V_43 & V_5 -> V_47 ) == 0 )
return V_108 ;
F_5 ( V_5 , 0 ) ;
return V_109 ;
}
static T_2 F_48 ( int V_59 , void * V_17 )
{
struct V_4 * V_5 = V_17 ;
if ( ! V_5 -> V_65 ) {
F_39 ( V_5 ) ;
F_24 ( V_5 ) ;
}
F_5 ( V_5 , 0 ) ;
return V_109 ;
}
static T_3
F_49 ( struct V_110 * V_17 , struct V_111 * V_112 , char * V_113 )
{
struct V_4 * V_5 = F_50 ( V_17 ) ;
return F_51 ( V_113 , V_114 , L_21 ,
V_5 -> V_21 . V_79 ) ;
}
static T_3
F_52 ( struct V_110 * V_17 , struct V_111 * V_112 ,
const char * V_113 , T_4 V_115 )
{
struct V_4 * V_5 = F_50 ( V_17 ) ;
if ( V_115 > 2 )
return - 1 ;
if ( V_5 -> V_7 . V_2 -> V_86 != V_88
&& V_5 -> V_7 . V_2 -> V_86 != V_89 )
return - 1 ;
F_39 ( V_5 ) ;
F_24 ( V_5 ) ;
if ( V_113 [ 0 ] == '1' ) {
V_5 -> V_21 . V_79 = 1 ;
V_5 -> V_21 . V_91 = 0 ;
F_6 ( & V_5 -> V_16 -> V_17 ,
L_22 ) ;
if ( F_10 ( & V_5 -> V_23 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_23 ) ;
}
}
return V_115 ;
}
static T_3
F_53 ( struct V_110 * V_17 , struct V_111 * V_112 ,
const char * V_113 , T_4 V_115 )
{
struct V_4 * V_5 = F_50 ( V_17 ) ;
if ( ! V_5 -> V_7 . V_2 -> V_104 )
return - 1 ;
if ( V_115 > 2 )
return - 1 ;
if ( V_113 [ 0 ] == '1' ) {
V_5 -> V_21 . V_100 = 1 ;
F_6 ( & V_5 -> V_16 -> V_17 ,
L_23 ) ;
}
if ( F_10 ( & V_5 -> V_23 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_23 ) ;
}
return V_115 ;
}
static T_3
F_54 ( struct V_110 * V_17 , struct V_111 * V_112 ,
char * V_113 )
{
struct V_4 * V_5 = F_50 ( V_17 ) ;
return F_51 ( V_113 , V_114 , L_21 ,
V_5 -> V_21 . V_91 ) ;
}
static T_3
F_55 ( struct V_110 * V_17 , struct V_111 * V_112 ,
const char * V_113 , T_4 V_115 )
{
struct V_4 * V_5 = F_50 ( V_17 ) ;
if ( ! V_5 -> V_7 . V_2 -> V_104 )
return - 1 ;
if ( V_115 > 2 )
return - 1 ;
if ( V_113 [ 0 ] == '0' ) {
V_5 -> V_21 . V_91 = 0 ;
F_6 ( & V_5 -> V_16 -> V_17 ,
L_24 ) ;
} else if ( V_113 [ 0 ] == '1' ) {
V_5 -> V_21 . V_91 = 1 ;
V_5 -> V_21 . V_79 = 0 ;
F_6 ( & V_5 -> V_16 -> V_17 ,
L_25 ) ;
F_6 ( & V_5 -> V_16 -> V_17 ,
L_26 ) ;
}
if ( F_10 ( & V_5 -> V_23 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_23 ) ;
}
return V_115 ;
}
static int F_56 ( struct V_116 * V_16 )
{
struct V_4 * V_5 = F_57 ( V_16 ) ;
F_58 ( & V_5 -> V_16 -> V_17 . V_117 , & V_118 ) ;
if ( V_5 -> V_18 ) {
F_59 ( V_5 -> V_18 ) ;
F_60 ( V_5 -> V_18 ) ;
}
F_41 ( V_5 ) ;
F_61 ( & V_5 -> V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_116 * V_16 )
{
struct V_119 * V_8 = F_63 ( & V_16 -> V_17 ) ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_120 * V_121 ;
int V_64 = 0 , V_122 ;
if ( V_8 == NULL ) {
F_17 ( & V_16 -> V_17 , L_27 ) ;
return - V_10 ;
}
V_5 = F_64 ( & V_16 -> V_17 , sizeof( * V_5 ) , V_123 ) ;
if ( ! V_5 )
return - V_124 ;
V_2 = F_64 ( & V_16 -> V_17 , sizeof( * V_2 ) , V_123 ) ;
if ( ! V_2 )
return - V_124 ;
F_65 ( V_16 , V_5 ) ;
V_5 -> V_16 = V_16 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_63 = F_66 ( & V_16 -> V_17 , NULL ) ;
if ( F_67 ( V_5 -> V_63 ) )
return F_68 ( V_5 -> V_63 ) ;
V_5 -> V_18 = F_69 ( L_28 ) ;
if ( ! V_5 -> V_18 ) {
F_6 ( & V_16 -> V_17 , L_29 ) ;
return - V_124 ;
}
F_70 ( & V_5 -> V_19 , F_44 ) ;
V_5 -> V_16 = V_16 ;
V_5 -> V_7 . V_17 = & V_16 -> V_17 ;
V_5 -> V_7 . V_2 = V_2 ;
V_5 -> V_7 . V_125 = V_126 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_6 = & V_5 -> V_7 ;
V_2 -> V_127 = F_3 ;
V_2 -> V_128 = F_4 ;
V_2 -> V_9 = F_1 ;
for ( V_122 = 0 ; V_122 < V_27 ; V_122 ++ )
F_18 ( & V_5 -> V_21 . V_26 [ V_122 ] ) ;
V_121 = F_71 ( V_5 -> V_16 ,
V_129 , L_30 ) ;
if ( V_121 == NULL ) {
F_17 ( & V_16 -> V_17 , L_31 ) ;
V_64 = - V_10 ;
goto V_130;
}
V_5 -> V_67 = F_72 ( & V_16 -> V_17 , V_121 -> V_131 , F_73 ( V_121 ) ) ;
if ( V_5 -> V_67 == NULL ) {
F_17 ( & V_16 -> V_17 , L_32 ) ;
V_64 = - V_132 ;
goto V_130;
}
V_121 = F_71 ( V_5 -> V_16 ,
V_129 , L_33 ) ;
if ( V_121 == NULL ) {
F_17 ( & V_16 -> V_17 , L_34 ) ;
V_64 = - V_10 ;
goto V_130;
}
V_5 -> V_133 = F_72 ( & V_16 -> V_17 , V_121 -> V_131 , F_73 ( V_121 ) ) ;
if ( V_5 -> V_133 == NULL ) {
F_17 ( & V_16 -> V_17 , L_35 ) ;
V_64 = - V_132 ;
goto V_130;
}
V_64 = F_38 ( V_5 ) ;
if ( V_64 ) {
F_17 ( & V_16 -> V_17 , L_36 , V_64 ) ;
goto V_130;
}
V_5 -> V_36 =
(struct V_134 V_135 * ) ( ( unsigned long ) V_5 -> V_133
+ ( F_21 ( V_5 -> V_133 ) & V_136 ) ) ;
if ( V_8 -> V_24 ) {
V_64 = F_74 ( & V_16 -> V_17 , V_8 -> V_24 -> V_59 ,
NULL , F_48 ,
V_137 , L_37 , V_5 ) ;
if ( V_64 ) {
F_9 ( & V_16 -> V_17 ,
L_38 ) ;
V_8 -> V_24 = NULL ;
}
}
if ( V_8 -> V_50 ) {
V_5 -> V_68 = 1 ;
V_64 = F_74 ( & V_16 -> V_17 , V_8 -> V_50 -> V_59 ,
NULL , F_48 ,
V_137 , L_39 , V_5 ) ;
if ( V_64 ) {
F_9 ( & V_16 -> V_17 ,
L_40
L_41 ) ;
V_5 -> V_68 = 0 ;
V_8 -> V_50 = NULL ;
}
}
if ( V_8 -> V_138 )
V_5 -> V_68 = 0 ;
F_20 ( V_5 ) ;
F_24 ( V_5 ) ;
V_121 = F_75 ( V_5 -> V_16 , V_139 , 0 ) ;
if ( V_121 == NULL ) {
F_17 ( & V_16 -> V_17 , L_42 ) ;
V_64 = - V_10 ;
goto V_140;
}
V_5 -> V_59 = V_121 -> V_131 ;
if ( F_76 ( & V_16 -> V_17 , V_5 -> V_59 , F_47 , V_60 ,
V_126 , V_5 ) ) {
F_17 ( & V_16 -> V_17 , L_43 ,
V_5 -> V_59 ) ;
V_5 -> V_59 = 0 ;
V_64 = - V_10 ;
goto V_140;
}
V_64 = F_77 ( & V_5 -> V_7 , V_141 ) ;
if ( V_64 < 0 ) {
F_17 ( & V_16 -> V_17 , L_44 ,
V_64 ) ;
goto V_140;
}
V_64 = F_78 ( & V_16 -> V_17 . V_117 , & V_118 ) ;
if ( V_64 < 0 ) {
F_6 ( & V_16 -> V_17 ,
L_45 , V_64 ) ;
goto V_142;
}
F_79 ( & V_5 -> V_23 ) ;
if ( F_10 ( & V_5 -> V_23 ) ) {
F_5 ( V_5 , 2 * V_143 ) ;
F_11 ( & V_5 -> V_23 ) ;
}
F_9 ( & V_16 -> V_17 ,
L_46 ,
V_5 -> V_68 ? L_47 : L_48 ) ;
return 0 ;
V_142:
F_61 ( & V_5 -> V_7 ) ;
V_140:
F_40 ( V_5 ) ;
V_130:
F_59 ( V_5 -> V_18 ) ;
F_60 ( V_5 -> V_18 ) ;
return V_64 ;
}
static int F_80 ( struct V_116 * V_16 , T_5 V_86 )
{
struct V_4 * V_5 = F_57 ( V_16 ) ;
if ( V_5 -> V_7 . V_2 -> V_86 != V_88 ) {
F_9 ( & V_16 -> V_17 ,
L_49 ,
V_5 -> V_7 . V_2 -> V_86 ) ;
return - V_144 ;
}
if ( ! V_5 -> V_68 )
F_40 ( V_5 ) ;
return 0 ;
}
static int F_81 ( struct V_116 * V_16 )
{
struct V_4 * V_5 = F_57 ( V_16 ) ;
T_1 V_43 ;
if ( ! V_5 -> V_68 ) {
F_38 ( V_5 ) ;
V_43 = F_21 ( & V_5 -> V_36 -> V_43 ) ;
V_43 |= V_5 -> V_44 ;
F_22 ( V_43 , & V_5 -> V_36 -> V_43 ) ;
if ( F_10 ( & V_5 -> V_23 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_23 ) ;
}
}
return 0 ;
}
