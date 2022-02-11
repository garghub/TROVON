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
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_5 -> V_61 ; V_60 ++ )
F_34 ( V_5 -> V_62 [ V_60 ] ) ;
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_5 -> V_61 ; V_60 ++ )
F_36 ( V_5 -> V_62 [ V_60 ] ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
int V_63 = 0 ;
if ( V_5 -> V_64 )
return 0 ;
F_6 ( & V_5 -> V_15 -> V_16 , L_11 ) ;
F_33 ( V_5 ) ;
if ( V_5 -> V_7 -> V_65 ) {
V_63 = V_5 -> V_7 -> V_65 ( V_5 -> V_66 ) ;
if ( V_63 ) {
F_17 ( & V_5 -> V_15 -> V_16 ,
L_12 , V_63 ) ;
F_35 ( V_5 ) ;
return V_63 ;
}
}
V_5 -> V_64 = 1 ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 )
{
if ( V_5 -> V_67 )
return F_37 ( V_5 ) ;
return 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
if ( V_5 -> V_64 ) {
F_6 ( & V_5 -> V_15 -> V_16 , L_13 ) ;
if ( V_5 -> V_7 -> V_68 )
V_5 -> V_7 -> V_68 ( V_5 -> V_66 ) ;
F_35 ( V_5 ) ;
V_5 -> V_64 = 0 ;
}
}
static void F_40 ( struct V_4 * V_5 )
{
if ( V_5 -> V_67 )
F_39 ( V_5 ) ;
}
static void F_41 ( struct V_4 * V_5 )
{
struct V_69 * V_20 = & V_5 -> V_20 ;
T_1 V_42 ;
V_42 = F_21 ( & V_5 -> V_35 -> V_42 ) ;
if ( V_5 -> V_7 -> V_49 ) {
if ( V_5 -> V_7 -> V_49 -> V_70 () == V_71 ) {
V_20 -> V_72 = 1 ;
V_20 -> V_73 = 0 ;
} else {
V_20 -> V_72 = 0 ;
V_20 -> V_73 = 1 ;
}
} else {
V_20 -> V_72 = ! ! ( V_42 & V_74 ) ;
V_20 -> V_73 = ! ! ( V_42 & V_75 ) ;
}
if ( V_5 -> V_7 -> V_23 )
V_20 -> V_23 = ! ! V_5 -> V_7 -> V_23 -> V_70 () ;
else
V_20 -> V_23 = ! ! ( V_42 & V_76 ) ;
if ( V_5 -> V_7 -> V_77 && ! V_20 -> V_23 )
V_20 -> V_78 = 1 ;
V_20 -> V_79 = ! ! ( V_42 & V_80 ) ;
V_20 -> V_81 = ! ! ( V_42 & V_82 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_14 , V_83 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_15 , V_20 -> V_23 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_16 , V_20 -> V_72 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_17 , V_20 -> V_73 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_18 , V_20 -> V_81 ) ;
F_6 ( & V_5 -> V_15 -> V_16 , L_19 , V_20 -> V_79 ) ;
}
static void F_42 ( struct V_4 * V_5 )
{
struct V_69 * V_20 = & V_5 -> V_20 ;
struct V_84 * V_6 = & V_5 -> V_6 ;
int V_85 = V_6 -> V_86 ;
switch ( V_85 ) {
case V_87 :
V_6 -> V_86 = V_88 ;
case V_88 :
if ( V_20 -> V_23 == 0 )
V_6 -> V_86 = V_89 ;
else if ( V_20 -> V_72 )
V_6 -> V_86 = V_90 ;
break;
case V_90 :
if ( ! V_20 -> V_72 || V_20 -> V_23 == 0 )
V_6 -> V_86 = V_88 ;
break;
case V_89 :
if ( V_20 -> V_23 )
V_6 -> V_86 = V_88 ;
else if ( ! ( V_20 -> V_91 ) &&
( V_20 -> V_78 || V_20 -> V_92 ) )
V_6 -> V_86 = V_93 ;
break;
case V_93 :
if ( V_20 -> V_81 )
V_6 -> V_86 = V_94 ;
break;
case V_94 :
if ( V_20 -> V_23 || V_20 -> V_91
|| V_20 -> V_21 ) {
F_12 ( V_5 , V_95 ) ;
V_5 -> V_20 . V_21 = 0 ;
V_6 -> V_86 = V_96 ;
V_20 -> V_78 = 0 ;
} else if ( ! V_20 -> V_81 ) {
F_12 ( V_5 , V_95 ) ;
V_5 -> V_20 . V_21 = 0 ;
V_6 -> V_86 = V_97 ;
} else if ( V_20 -> V_98 ) {
F_12 ( V_5 , V_95 ) ;
V_5 -> V_20 . V_21 = 0 ;
V_6 -> V_86 = V_99 ;
}
break;
case V_99 :
if ( V_20 -> V_23 || ! V_20 -> V_98
|| V_20 -> V_91 )
V_6 -> V_86 = V_94 ;
else if ( ! V_20 -> V_81 )
V_6 -> V_86 = V_97 ;
break;
case V_96 :
if ( V_20 -> V_23
|| ( ! V_20 -> V_98 && V_20 -> V_79 )
|| V_20 -> V_78 )
V_6 -> V_86 = V_89 ;
break;
case V_97 :
if ( V_20 -> V_23 || V_20 -> V_100
|| V_20 -> V_91 ) {
V_20 -> V_100 = 0 ;
V_6 -> V_86 = V_96 ;
}
break;
default:
break;
}
}
static void F_43 ( struct V_101 * V_18 )
{
struct V_4 * V_5 ;
struct V_84 * V_6 ;
struct V_1 * V_2 ;
int V_85 ;
V_5 = F_2 ( (struct V_102 * ) V_18 , struct V_4 , V_18 ) ;
V_103:
V_6 = & V_5 -> V_6 ;
V_2 = V_6 -> V_2 ;
V_85 = V_6 -> V_86 ;
if ( ! V_5 -> V_64 )
return;
F_41 ( V_5 ) ;
F_42 ( V_5 ) ;
if ( V_85 != V_6 -> V_86 ) {
F_9 ( & V_5 -> V_15 -> V_16 , L_20 ,
V_104 [ V_85 ] ,
V_104 [ V_6 -> V_86 ] ) ;
switch ( V_6 -> V_86 ) {
case V_88 :
V_2 -> V_105 = 0 ;
if ( V_85 == V_90 )
F_30 ( V_5 , 0 ) ;
F_20 ( V_5 ) ;
F_40 ( V_5 ) ;
break;
case V_90 :
F_38 ( V_5 ) ;
F_30 ( V_5 , 1 ) ;
break;
case V_89 :
V_2 -> V_105 = 1 ;
F_38 ( V_5 ) ;
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
V_106 ,
F_8 ) ;
V_5 -> V_20 . V_98 = 1 ;
break;
case V_99 :
break;
case V_96 :
V_5 -> V_20 . V_98 = 0 ;
F_1 ( V_2 , 0 ) ;
break;
case V_97 :
break;
default:
break;
}
goto V_103;
}
}
static T_2 F_44 ( int V_58 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
T_1 V_42 ;
V_42 = F_21 ( & V_5 -> V_35 -> V_42 ) ;
F_22 ( V_42 , & V_5 -> V_35 -> V_42 ) ;
if ( V_5 -> V_7 -> V_49 )
if ( ( V_42 & V_76 ) &&
! ( V_42 & V_55 ) )
return V_107 ;
if ( ( V_42 & V_5 -> V_46 ) == 0 )
return V_107 ;
F_5 ( V_5 , 0 ) ;
return V_108 ;
}
static T_2 F_45 ( int V_58 , void * V_16 )
{
struct V_4 * V_5 = V_16 ;
if ( ! V_5 -> V_64 ) {
F_38 ( V_5 ) ;
F_24 ( V_5 ) ;
}
F_5 ( V_5 , 0 ) ;
return V_108 ;
}
static T_3
F_46 ( struct V_109 * V_16 , struct V_110 * V_111 , char * V_112 )
{
struct V_4 * V_5 = F_47 ( V_16 ) ;
return F_48 ( V_112 , V_113 , L_21 ,
V_5 -> V_20 . V_78 ) ;
}
static T_3
F_49 ( struct V_109 * V_16 , struct V_110 * V_111 ,
const char * V_112 , T_4 V_114 )
{
struct V_4 * V_5 = F_47 ( V_16 ) ;
if ( V_114 > 2 )
return - 1 ;
if ( V_5 -> V_6 . V_86 != V_88
&& V_5 -> V_6 . V_86 != V_89 )
return - 1 ;
F_38 ( V_5 ) ;
F_24 ( V_5 ) ;
if ( V_112 [ 0 ] == '1' ) {
V_5 -> V_20 . V_78 = 1 ;
V_5 -> V_20 . V_91 = 0 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_22 ) ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
}
return V_114 ;
}
static T_3
F_50 ( struct V_109 * V_16 , struct V_110 * V_111 ,
const char * V_112 , T_4 V_114 )
{
struct V_4 * V_5 = F_47 ( V_16 ) ;
if ( ! V_5 -> V_6 . V_2 -> V_105 )
return - 1 ;
if ( V_114 > 2 )
return - 1 ;
if ( V_112 [ 0 ] == '1' ) {
V_5 -> V_20 . V_100 = 1 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_23 ) ;
}
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
return V_114 ;
}
static T_3
F_51 ( struct V_109 * V_16 , struct V_110 * V_111 ,
char * V_112 )
{
struct V_4 * V_5 = F_47 ( V_16 ) ;
return F_48 ( V_112 , V_113 , L_21 ,
V_5 -> V_20 . V_91 ) ;
}
static T_3
F_52 ( struct V_109 * V_16 , struct V_110 * V_111 ,
const char * V_112 , T_4 V_114 )
{
struct V_4 * V_5 = F_47 ( V_16 ) ;
if ( ! V_5 -> V_6 . V_2 -> V_105 )
return - 1 ;
if ( V_114 > 2 )
return - 1 ;
if ( V_112 [ 0 ] == '0' ) {
V_5 -> V_20 . V_91 = 0 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_24 ) ;
} else if ( V_112 [ 0 ] == '1' ) {
V_5 -> V_20 . V_91 = 1 ;
V_5 -> V_20 . V_78 = 0 ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_25 ) ;
F_6 ( & V_5 -> V_15 -> V_16 ,
L_26 ) ;
}
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
return V_114 ;
}
int F_53 ( struct V_115 * V_15 )
{
struct V_4 * V_5 = F_54 ( V_15 ) ;
int V_116 ;
F_55 ( & V_5 -> V_15 -> V_16 . V_117 , & V_118 ) ;
if ( V_5 -> V_58 )
F_56 ( V_5 -> V_58 , V_5 ) ;
if ( V_5 -> V_7 -> V_49 )
F_56 ( V_5 -> V_7 -> V_49 -> V_58 , V_5 ) ;
if ( V_5 -> V_7 -> V_23 )
F_56 ( V_5 -> V_7 -> V_23 -> V_58 , V_5 ) ;
if ( V_5 -> V_17 ) {
F_57 ( V_5 -> V_17 ) ;
F_58 ( V_5 -> V_17 ) ;
}
F_40 ( V_5 ) ;
if ( V_5 -> V_119 )
F_59 ( V_5 -> V_119 ) ;
if ( V_5 -> V_66 )
F_59 ( V_5 -> V_66 ) ;
for ( V_116 = 0 ; V_116 <= V_5 -> V_61 ; V_116 ++ )
F_60 ( V_5 -> V_62 [ V_116 ] ) ;
F_61 ( & V_5 -> V_6 ) ;
F_62 ( V_15 , NULL ) ;
F_63 ( V_5 -> V_6 . V_2 ) ;
F_63 ( V_5 ) ;
return 0 ;
}
static int F_64 ( struct V_115 * V_15 )
{
struct V_120 * V_7 = V_15 -> V_16 . V_121 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
int V_63 = 0 , V_116 , V_60 ;
T_4 V_124 ;
if ( V_7 == NULL ) {
F_17 ( & V_15 -> V_16 , L_27 ) ;
return - V_9 ;
}
V_124 = sizeof( * V_5 ) + sizeof( struct V_62 * ) * V_7 -> V_61 ;
V_5 = F_65 ( V_124 , V_125 ) ;
if ( ! V_5 ) {
F_17 ( & V_15 -> V_16 , L_28 ) ;
return - V_126 ;
}
V_2 = F_65 ( sizeof *V_2 , V_125 ) ;
if ( ! V_2 ) {
F_63 ( V_5 ) ;
return - V_126 ;
}
F_62 ( V_15 , V_5 ) ;
V_5 -> V_15 = V_15 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_61 = V_7 -> V_61 ;
for ( V_116 = 0 ; V_116 < V_5 -> V_61 ; V_116 ++ ) {
V_5 -> V_62 [ V_116 ] = F_66 ( & V_15 -> V_16 , V_7 -> V_127 [ V_116 ] ) ;
if ( F_67 ( V_5 -> V_62 [ V_116 ] ) ) {
V_63 = F_68 ( V_5 -> V_62 [ V_116 ] ) ;
goto V_128;
}
}
V_5 -> V_17 = F_69 ( L_29 ) ;
if ( ! V_5 -> V_17 ) {
F_6 ( & V_15 -> V_16 , L_30 ) ;
V_63 = - V_126 ;
goto V_128;
}
F_70 ( & V_5 -> V_18 , F_43 ) ;
V_5 -> V_15 = V_15 ;
V_5 -> V_6 . V_16 = & V_15 -> V_16 ;
V_5 -> V_6 . V_2 = V_2 ;
V_5 -> V_6 . V_129 = V_130 ;
V_5 -> V_6 . V_86 = V_87 ;
V_2 -> V_6 = & V_5 -> V_6 ;
V_2 -> V_131 = F_3 ;
V_2 -> V_132 = F_4 ;
V_2 -> V_8 = F_1 ;
for ( V_60 = 0 ; V_60 < V_26 ; V_60 ++ )
F_18 ( & V_5 -> V_20 . V_25 [ V_60 ] ) ;
V_123 = F_71 ( V_5 -> V_15 ,
V_133 , L_31 ) ;
if ( V_123 == NULL ) {
F_17 ( & V_15 -> V_16 , L_32 ) ;
V_63 = - V_9 ;
goto V_134;
}
V_5 -> V_66 = F_72 ( V_123 -> V_135 , F_73 ( V_123 ) ) ;
if ( V_5 -> V_66 == NULL ) {
F_17 ( & V_15 -> V_16 , L_33 ) ;
V_63 = - V_136 ;
goto V_134;
}
V_123 = F_71 ( V_5 -> V_15 ,
V_133 , L_34 ) ;
if ( V_123 == NULL ) {
F_17 ( & V_15 -> V_16 , L_35 ) ;
V_63 = - V_9 ;
goto V_137;
}
V_5 -> V_119 = F_72 ( V_123 -> V_135 , F_73 ( V_123 ) ) ;
if ( V_5 -> V_119 == NULL ) {
F_17 ( & V_15 -> V_16 , L_36 ) ;
V_63 = - V_136 ;
goto V_137;
}
V_63 = F_37 ( V_5 ) ;
if ( V_63 ) {
F_17 ( & V_15 -> V_16 , L_37 , V_63 ) ;
goto V_138;
}
V_5 -> V_35 =
(struct V_139 V_140 * ) ( ( unsigned long ) V_5 -> V_119
+ ( F_21 ( V_5 -> V_119 ) & V_141 ) ) ;
if ( V_7 -> V_23 ) {
V_63 = F_74 ( V_7 -> V_23 -> V_58 , NULL ,
F_45 ,
V_142 , L_38 , V_5 ) ;
if ( V_63 ) {
F_9 ( & V_15 -> V_16 ,
L_39 ) ;
V_7 -> V_23 = NULL ;
}
}
if ( V_7 -> V_49 ) {
V_5 -> V_67 = 1 ;
V_63 = F_74 ( V_7 -> V_49 -> V_58 , NULL ,
F_45 ,
V_142 , L_40 , V_5 ) ;
if ( V_63 ) {
F_9 ( & V_15 -> V_16 ,
L_41
L_42 ) ;
V_5 -> V_67 = 0 ;
V_7 -> V_49 = NULL ;
}
}
if ( V_7 -> V_143 )
V_5 -> V_67 = 0 ;
F_20 ( V_5 ) ;
F_24 ( V_5 ) ;
V_123 = F_75 ( V_5 -> V_15 , V_144 , 0 ) ;
if ( V_123 == NULL ) {
F_17 ( & V_15 -> V_16 , L_43 ) ;
V_63 = - V_9 ;
goto V_145;
}
V_5 -> V_58 = V_123 -> V_135 ;
if ( F_76 ( V_5 -> V_58 , F_44 , V_59 ,
V_130 , V_5 ) ) {
F_17 ( & V_15 -> V_16 , L_44 ,
V_5 -> V_58 ) ;
V_5 -> V_58 = 0 ;
V_63 = - V_9 ;
goto V_145;
}
V_63 = F_77 ( & V_5 -> V_6 , V_146 ) ;
if ( V_63 < 0 ) {
F_17 ( & V_15 -> V_16 , L_45 ,
V_63 ) ;
goto V_147;
}
V_63 = F_78 ( & V_15 -> V_16 . V_117 , & V_118 ) ;
if ( V_63 < 0 ) {
F_6 ( & V_15 -> V_16 ,
L_46 , V_63 ) ;
goto V_148;
}
F_79 ( & V_5 -> V_22 ) ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_5 ( V_5 , 2 * V_149 ) ;
F_11 ( & V_5 -> V_22 ) ;
}
F_9 ( & V_15 -> V_16 ,
L_47 ,
V_5 -> V_67 ? L_48 : L_49 ) ;
return 0 ;
V_148:
F_61 ( & V_5 -> V_6 ) ;
V_147:
F_56 ( V_5 -> V_58 , V_5 ) ;
V_145:
if ( V_7 -> V_49 )
F_56 ( V_7 -> V_49 -> V_58 , V_5 ) ;
if ( V_7 -> V_23 )
F_56 ( V_7 -> V_23 -> V_58 , V_5 ) ;
F_39 ( V_5 ) ;
V_138:
F_59 ( V_5 -> V_119 ) ;
V_137:
F_59 ( V_5 -> V_66 ) ;
V_134:
F_57 ( V_5 -> V_17 ) ;
F_58 ( V_5 -> V_17 ) ;
V_128:
for ( V_116 -- ; V_116 >= 0 ; V_116 -- )
F_60 ( V_5 -> V_62 [ V_116 ] ) ;
F_62 ( V_15 , NULL ) ;
F_63 ( V_2 ) ;
F_63 ( V_5 ) ;
return V_63 ;
}
static int F_80 ( struct V_115 * V_15 , T_5 V_86 )
{
struct V_4 * V_5 = F_54 ( V_15 ) ;
if ( V_5 -> V_6 . V_86 != V_88 ) {
F_9 ( & V_15 -> V_16 ,
L_50 ,
V_5 -> V_6 . V_86 ) ;
return - V_150 ;
}
if ( ! V_5 -> V_67 )
F_39 ( V_5 ) ;
return 0 ;
}
static int F_81 ( struct V_115 * V_15 )
{
struct V_4 * V_5 = F_54 ( V_15 ) ;
T_1 V_42 ;
if ( ! V_5 -> V_67 ) {
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
static int T_6 F_82 ( void )
{
return F_83 ( & V_151 ) ;
}
static void T_7 F_84 ( void )
{
F_85 ( & V_151 ) ;
}
