static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_5 -> V_6 -> V_7 == NULL )
return - V_8 ;
return V_5 -> V_6 -> V_7 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
V_2 -> V_10 = V_10 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_2 -> V_12 = V_12 ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
unsigned long V_13 )
{
F_6 ( & V_5 -> V_14 -> V_15 , L_1 ) ;
if ( ! V_5 -> V_16 )
return;
F_7 ( V_5 -> V_16 , & V_5 -> V_17 , V_13 ) ;
}
static void F_8 ( unsigned long V_18 )
{
struct V_4 * V_5 = (struct V_4 * ) V_18 ;
V_5 -> V_19 . V_20 = 1 ;
F_9 ( & V_5 -> V_14 -> V_15 , L_2 ) ;
if ( F_10 ( & V_5 -> V_21 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_21 ) ;
}
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_22 )
{
struct V_23 * V_24 ;
if ( V_22 >= V_25 )
return - V_26 ;
V_24 = & V_5 -> V_19 . V_24 [ V_22 ] ;
if ( F_13 ( V_24 ) )
F_14 ( V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_22 ,
unsigned long V_27 ,
void (* F_16) ( unsigned long ) )
{
struct V_23 * V_24 ;
if ( V_22 >= V_25 )
return - V_26 ;
V_24 = & V_5 -> V_19 . V_24 [ V_22 ] ;
if ( F_13 ( V_24 ) ) {
F_17 ( & V_5 -> V_14 -> V_15 , L_3 , V_22 ) ;
return - V_28 ;
}
F_18 ( V_24 ) ;
V_24 -> V_18 = ( unsigned long ) V_5 ;
V_24 -> V_29 = F_16 ;
V_24 -> V_30 = V_31 + V_27 ;
F_19 ( V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
unsigned int V_32 ;
T_1 V_33 ;
V_33 = F_21 ( & V_5 -> V_34 -> V_35 ) ;
V_33 &= ~ V_36 ;
F_22 ( V_33 , & V_5 -> V_34 -> V_35 ) ;
F_22 ( V_37 , & V_5 -> V_34 -> V_35 ) ;
V_32 = 500 ;
while ( F_21 ( & V_5 -> V_34 -> V_35 ) & V_37 ) {
if ( V_32 == 0 ) {
F_17 ( & V_5 -> V_14 -> V_15 ,
L_4 ) ;
return - V_38 ;
}
V_32 -- ;
F_23 ( 20 ) ;
}
F_22 ( 0x0 , & V_5 -> V_34 -> V_39 ) ;
V_33 = F_21 ( & V_5 -> V_34 -> V_40 ) ;
F_22 ( V_33 , & V_5 -> V_34 -> V_40 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
T_1 V_41 ;
V_5 -> V_42 = V_43
| V_44 ;
V_5 -> V_45 = V_46
| V_47 ;
if ( V_5 -> V_6 -> V_48 == NULL ) {
V_5 -> V_42 |= V_49
| V_50 ;
V_5 -> V_45 |= V_51
| V_52 ;
}
if ( V_5 -> V_6 -> V_22 == NULL ) {
V_5 -> V_42 |= V_53 ;
V_5 -> V_45 |= V_54 ;
}
V_41 = F_21 ( & V_5 -> V_34 -> V_41 ) ;
V_41 |= V_5 -> V_42 ;
F_22 ( V_41 , & V_5 -> V_34 -> V_41 ) ;
}
static void F_25 ( struct V_4 * V_5 , int V_3 )
{
#ifdef F_26
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_55 * V_56 ;
if ( ! V_2 -> V_10 )
return;
F_9 ( & V_5 -> V_14 -> V_15 , L_5 , V_3 ? L_6 : L_7 ) ;
V_56 = F_27 ( V_2 -> V_10 ) ;
if ( V_3 )
F_28 ( V_56 , V_56 -> V_57 , V_58 ) ;
else
F_29 ( V_56 ) ;
#endif
}
static void F_30 ( struct V_4 * V_5 , int V_3 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
if ( ! V_2 -> V_12 )
return;
F_9 ( V_2 -> V_15 , L_8 , V_3 ? L_9 : L_10 ) ;
if ( V_3 )
F_31 ( V_2 -> V_12 ) ;
else
F_32 ( V_2 -> V_12 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_5 -> V_60 ; V_59 ++ )
F_34 ( V_5 -> V_61 [ V_59 ] ) ;
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_5 -> V_60 ; V_59 ++ )
F_36 ( V_5 -> V_61 [ V_59 ] ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
int V_62 = 0 ;
if ( V_5 -> V_63 )
return 0 ;
F_6 ( & V_5 -> V_14 -> V_15 , L_11 ) ;
F_33 ( V_5 ) ;
if ( V_5 -> V_6 -> V_64 ) {
V_62 = V_5 -> V_6 -> V_64 ( V_5 -> V_65 ) ;
if ( V_62 ) {
F_17 ( & V_5 -> V_14 -> V_15 ,
L_12 , V_62 ) ;
F_35 ( V_5 ) ;
return V_62 ;
}
}
V_5 -> V_63 = 1 ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 )
{
if ( V_5 -> V_66 )
return F_37 ( V_5 ) ;
return 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
if ( V_5 -> V_63 ) {
F_6 ( & V_5 -> V_14 -> V_15 , L_13 ) ;
if ( V_5 -> V_6 -> V_67 )
V_5 -> V_6 -> V_67 ( V_5 -> V_65 ) ;
F_35 ( V_5 ) ;
V_5 -> V_63 = 0 ;
}
}
static void F_40 ( struct V_4 * V_5 )
{
if ( V_5 -> V_66 )
F_39 ( V_5 ) ;
}
static void F_41 ( struct V_4 * V_5 )
{
struct V_68 * V_19 = & V_5 -> V_19 ;
T_1 V_41 ;
V_41 = F_21 ( & V_5 -> V_34 -> V_41 ) ;
if ( V_5 -> V_6 -> V_48 ) {
if ( V_5 -> V_6 -> V_48 -> V_69 () == V_70 ) {
V_19 -> V_71 = 1 ;
V_19 -> V_72 = 0 ;
} else {
V_19 -> V_71 = 0 ;
V_19 -> V_72 = 1 ;
}
} else {
V_19 -> V_71 = ! ! ( V_41 & V_73 ) ;
V_19 -> V_72 = ! ! ( V_41 & V_74 ) ;
}
if ( V_5 -> V_6 -> V_22 )
V_19 -> V_22 = ! ! V_5 -> V_6 -> V_22 -> V_69 () ;
else
V_19 -> V_22 = ! ! ( V_41 & V_75 ) ;
if ( V_5 -> V_6 -> V_76 && ! V_19 -> V_22 )
V_19 -> V_77 = 1 ;
V_19 -> V_78 = ! ! ( V_41 & V_79 ) ;
V_19 -> V_80 = ! ! ( V_41 & V_81 ) ;
F_6 ( & V_5 -> V_14 -> V_15 , L_14 , V_82 ) ;
F_6 ( & V_5 -> V_14 -> V_15 , L_15 , V_19 -> V_22 ) ;
F_6 ( & V_5 -> V_14 -> V_15 , L_16 , V_19 -> V_71 ) ;
F_6 ( & V_5 -> V_14 -> V_15 , L_17 , V_19 -> V_72 ) ;
F_6 ( & V_5 -> V_14 -> V_15 , L_18 , V_19 -> V_80 ) ;
F_6 ( & V_5 -> V_14 -> V_15 , L_19 , V_19 -> V_78 ) ;
}
static void F_42 ( struct V_4 * V_5 )
{
struct V_68 * V_19 = & V_5 -> V_19 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_83 = V_2 -> V_84 ;
switch ( V_83 ) {
case V_85 :
V_2 -> V_84 = V_86 ;
case V_86 :
if ( V_19 -> V_22 == 0 )
V_2 -> V_84 = V_87 ;
else if ( V_19 -> V_71 )
V_2 -> V_84 = V_88 ;
break;
case V_88 :
if ( ! V_19 -> V_71 || V_19 -> V_22 == 0 )
V_2 -> V_84 = V_86 ;
break;
case V_87 :
if ( V_19 -> V_22 )
V_2 -> V_84 = V_86 ;
else if ( ! ( V_19 -> V_89 ) &&
( V_19 -> V_77 || V_19 -> V_90 ) )
V_2 -> V_84 = V_91 ;
break;
case V_91 :
if ( V_19 -> V_80 )
V_2 -> V_84 = V_92 ;
break;
case V_92 :
if ( V_19 -> V_22 || V_19 -> V_89
|| V_19 -> V_20 ) {
F_12 ( V_5 , V_93 ) ;
V_5 -> V_19 . V_20 = 0 ;
V_2 -> V_84 = V_94 ;
V_19 -> V_77 = 0 ;
} else if ( ! V_19 -> V_80 ) {
F_12 ( V_5 , V_93 ) ;
V_5 -> V_19 . V_20 = 0 ;
V_2 -> V_84 = V_95 ;
} else if ( V_19 -> V_96 ) {
F_12 ( V_5 , V_93 ) ;
V_5 -> V_19 . V_20 = 0 ;
V_2 -> V_84 = V_97 ;
}
break;
case V_97 :
if ( V_19 -> V_22 || ! V_19 -> V_96
|| V_19 -> V_89 )
V_2 -> V_84 = V_92 ;
else if ( ! V_19 -> V_80 )
V_2 -> V_84 = V_95 ;
break;
case V_94 :
if ( V_19 -> V_22
|| ( ! V_19 -> V_96 && V_19 -> V_78 )
|| V_19 -> V_77 )
V_2 -> V_84 = V_87 ;
break;
case V_95 :
if ( V_19 -> V_22 || V_19 -> V_98
|| V_19 -> V_89 ) {
V_19 -> V_98 = 0 ;
V_2 -> V_84 = V_94 ;
}
break;
default:
break;
}
}
static void F_43 ( struct V_99 * V_17 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_83 ;
V_5 = F_2 ( (struct V_100 * ) V_17 , struct V_4 , V_17 ) ;
V_101:
V_2 = & V_5 -> V_2 ;
V_83 = V_2 -> V_84 ;
if ( ! V_5 -> V_63 )
return;
F_41 ( V_5 ) ;
F_42 ( V_5 ) ;
if ( V_83 != V_2 -> V_84 ) {
F_9 ( & V_5 -> V_14 -> V_15 , L_20 ,
V_102 [ V_83 ] ,
V_102 [ V_2 -> V_84 ] ) ;
switch ( V_2 -> V_84 ) {
case V_86 :
V_5 -> V_2 . V_103 = 0 ;
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
V_5 -> V_2 . V_103 = 1 ;
F_38 ( V_5 ) ;
if ( V_83 == V_94 )
F_25 ( V_5 , 0 ) ;
F_20 ( V_5 ) ;
break;
case V_91 :
F_1 ( & V_5 -> V_2 , 1 ) ;
break;
case V_92 :
if ( V_83 != V_97 )
F_25 ( V_5 , 1 ) ;
F_15 ( V_5 , V_93 ,
V_104 ,
F_8 ) ;
V_5 -> V_19 . V_96 = 1 ;
break;
case V_97 :
break;
case V_94 :
V_5 -> V_19 . V_96 = 0 ;
F_1 ( & V_5 -> V_2 , 0 ) ;
break;
case V_95 :
break;
default:
break;
}
goto V_101;
}
}
static T_2 F_44 ( int V_57 , void * V_15 )
{
struct V_4 * V_5 = V_15 ;
T_1 V_41 ;
V_41 = F_21 ( & V_5 -> V_34 -> V_41 ) ;
F_22 ( V_41 , & V_5 -> V_34 -> V_41 ) ;
if ( V_5 -> V_6 -> V_48 )
if ( ( V_41 & V_75 ) &&
! ( V_41 & V_54 ) )
return V_105 ;
if ( ( V_41 & V_5 -> V_45 ) == 0 )
return V_105 ;
F_5 ( V_5 , 0 ) ;
return V_106 ;
}
static T_2 F_45 ( int V_57 , void * V_15 )
{
struct V_4 * V_5 = V_15 ;
if ( ! V_5 -> V_63 ) {
F_38 ( V_5 ) ;
F_24 ( V_5 ) ;
}
F_5 ( V_5 , 0 ) ;
return V_106 ;
}
static T_3
F_46 ( struct V_107 * V_15 , struct V_108 * V_109 , char * V_110 )
{
struct V_4 * V_5 = F_47 ( V_15 ) ;
return F_48 ( V_110 , V_111 , L_21 ,
V_5 -> V_19 . V_77 ) ;
}
static T_3
F_49 ( struct V_107 * V_15 , struct V_108 * V_109 ,
const char * V_110 , T_4 V_112 )
{
struct V_4 * V_5 = F_47 ( V_15 ) ;
if ( V_112 > 2 )
return - 1 ;
if ( V_5 -> V_2 . V_84 != V_86
&& V_5 -> V_2 . V_84 != V_87 )
return - 1 ;
F_38 ( V_5 ) ;
F_24 ( V_5 ) ;
if ( V_110 [ 0 ] == '1' ) {
V_5 -> V_19 . V_77 = 1 ;
V_5 -> V_19 . V_89 = 0 ;
F_6 ( & V_5 -> V_14 -> V_15 ,
L_22 ) ;
if ( F_10 ( & V_5 -> V_21 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_21 ) ;
}
}
return V_112 ;
}
static T_3
F_50 ( struct V_107 * V_15 , struct V_108 * V_109 ,
const char * V_110 , T_4 V_112 )
{
struct V_4 * V_5 = F_47 ( V_15 ) ;
if ( ! V_5 -> V_2 . V_103 )
return - 1 ;
if ( V_112 > 2 )
return - 1 ;
if ( V_110 [ 0 ] == '1' ) {
V_5 -> V_19 . V_98 = 1 ;
F_6 ( & V_5 -> V_14 -> V_15 ,
L_23 ) ;
}
if ( F_10 ( & V_5 -> V_21 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_21 ) ;
}
return V_112 ;
}
static T_3
F_51 ( struct V_107 * V_15 , struct V_108 * V_109 ,
char * V_110 )
{
struct V_4 * V_5 = F_47 ( V_15 ) ;
return F_48 ( V_110 , V_111 , L_21 ,
V_5 -> V_19 . V_89 ) ;
}
static T_3
F_52 ( struct V_107 * V_15 , struct V_108 * V_109 ,
const char * V_110 , T_4 V_112 )
{
struct V_4 * V_5 = F_47 ( V_15 ) ;
if ( ! V_5 -> V_2 . V_103 )
return - 1 ;
if ( V_112 > 2 )
return - 1 ;
if ( V_110 [ 0 ] == '0' ) {
V_5 -> V_19 . V_89 = 0 ;
F_6 ( & V_5 -> V_14 -> V_15 ,
L_24 ) ;
} else if ( V_110 [ 0 ] == '1' ) {
V_5 -> V_19 . V_89 = 1 ;
V_5 -> V_19 . V_77 = 0 ;
F_6 ( & V_5 -> V_14 -> V_15 ,
L_25 ) ;
F_6 ( & V_5 -> V_14 -> V_15 ,
L_26 ) ;
}
if ( F_10 ( & V_5 -> V_21 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_21 ) ;
}
return V_112 ;
}
int F_53 ( struct V_113 * V_14 )
{
struct V_4 * V_5 = F_54 ( V_14 ) ;
int V_114 ;
F_55 ( & V_5 -> V_14 -> V_15 . V_115 , & V_116 ) ;
if ( V_5 -> V_57 )
F_56 ( V_5 -> V_57 , V_5 ) ;
if ( V_5 -> V_6 -> V_48 )
F_56 ( V_5 -> V_6 -> V_48 -> V_57 , V_5 ) ;
if ( V_5 -> V_6 -> V_22 )
F_56 ( V_5 -> V_6 -> V_22 -> V_57 , V_5 ) ;
if ( V_5 -> V_16 ) {
F_57 ( V_5 -> V_16 ) ;
F_58 ( V_5 -> V_16 ) ;
}
F_40 ( V_5 ) ;
if ( V_5 -> V_117 )
F_59 ( V_5 -> V_117 ) ;
if ( V_5 -> V_65 )
F_59 ( V_5 -> V_65 ) ;
for ( V_114 = 0 ; V_114 <= V_5 -> V_60 ; V_114 ++ )
F_60 ( V_5 -> V_61 [ V_114 ] ) ;
F_61 ( NULL ) ;
F_62 ( V_14 , NULL ) ;
F_63 ( V_5 ) ;
return 0 ;
}
static int F_64 ( struct V_113 * V_14 )
{
struct V_118 * V_6 = V_14 -> V_15 . V_119 ;
struct V_4 * V_5 ;
struct V_120 * V_121 ;
int V_62 = 0 , V_114 , V_59 ;
T_4 V_122 ;
if ( V_6 == NULL ) {
F_17 ( & V_14 -> V_15 , L_27 ) ;
return - V_8 ;
}
V_122 = sizeof( * V_5 ) + sizeof( struct V_61 * ) * V_6 -> V_60 ;
V_5 = F_65 ( V_122 , V_123 ) ;
if ( ! V_5 ) {
F_17 ( & V_14 -> V_15 , L_28 ) ;
return - V_124 ;
}
F_62 ( V_14 , V_5 ) ;
V_5 -> V_14 = V_14 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_60 = V_6 -> V_60 ;
for ( V_114 = 0 ; V_114 < V_5 -> V_60 ; V_114 ++ ) {
V_5 -> V_61 [ V_114 ] = F_66 ( & V_14 -> V_15 , V_6 -> V_125 [ V_114 ] ) ;
if ( F_67 ( V_5 -> V_61 [ V_114 ] ) ) {
V_62 = F_68 ( V_5 -> V_61 [ V_114 ] ) ;
goto V_126;
}
}
V_5 -> V_16 = F_69 ( L_29 ) ;
if ( ! V_5 -> V_16 ) {
F_6 ( & V_14 -> V_15 , L_30 ) ;
V_62 = - V_124 ;
goto V_126;
}
F_70 ( & V_5 -> V_17 , F_43 ) ;
V_5 -> V_14 = V_14 ;
V_5 -> V_2 . V_15 = & V_14 -> V_15 ;
V_5 -> V_2 . V_127 = V_128 ;
V_5 -> V_2 . V_129 = F_3 ;
V_5 -> V_2 . V_130 = F_4 ;
V_5 -> V_2 . V_7 = F_1 ;
V_5 -> V_2 . V_84 = V_85 ;
for ( V_59 = 0 ; V_59 < V_25 ; V_59 ++ )
F_18 ( & V_5 -> V_19 . V_24 [ V_59 ] ) ;
V_121 = F_71 ( V_5 -> V_14 ,
V_131 , L_31 ) ;
if ( V_121 == NULL ) {
F_17 ( & V_14 -> V_15 , L_32 ) ;
V_62 = - V_8 ;
goto V_132;
}
V_5 -> V_65 = F_72 ( V_121 -> V_133 , F_73 ( V_121 ) ) ;
if ( V_5 -> V_65 == NULL ) {
F_17 ( & V_14 -> V_15 , L_33 ) ;
V_62 = - V_134 ;
goto V_132;
}
V_121 = F_71 ( V_5 -> V_14 ,
V_131 , L_34 ) ;
if ( V_121 == NULL ) {
F_17 ( & V_14 -> V_15 , L_35 ) ;
V_62 = - V_8 ;
goto V_135;
}
V_5 -> V_117 = F_72 ( V_121 -> V_133 , F_73 ( V_121 ) ) ;
if ( V_5 -> V_117 == NULL ) {
F_17 ( & V_14 -> V_15 , L_36 ) ;
V_62 = - V_134 ;
goto V_135;
}
V_62 = F_37 ( V_5 ) ;
if ( V_62 ) {
F_17 ( & V_14 -> V_15 , L_37 , V_62 ) ;
goto V_136;
}
V_5 -> V_34 =
(struct V_137 V_138 * ) ( ( unsigned long ) V_5 -> V_117
+ ( F_21 ( V_5 -> V_117 ) & V_139 ) ) ;
if ( V_6 -> V_22 ) {
V_62 = F_74 ( V_6 -> V_22 -> V_57 , NULL ,
F_45 ,
V_140 , L_38 , V_5 ) ;
if ( V_62 ) {
F_9 ( & V_14 -> V_15 ,
L_39 ) ;
V_6 -> V_22 = NULL ;
}
}
if ( V_6 -> V_48 ) {
V_5 -> V_66 = 1 ;
V_62 = F_74 ( V_6 -> V_48 -> V_57 , NULL ,
F_45 ,
V_140 , L_40 , V_5 ) ;
if ( V_62 ) {
F_9 ( & V_14 -> V_15 ,
L_41
L_42 ) ;
V_5 -> V_66 = 0 ;
V_6 -> V_48 = NULL ;
}
}
if ( V_6 -> V_141 )
V_5 -> V_66 = 0 ;
F_20 ( V_5 ) ;
F_24 ( V_5 ) ;
V_121 = F_75 ( V_5 -> V_14 , V_142 , 0 ) ;
if ( V_121 == NULL ) {
F_17 ( & V_14 -> V_15 , L_43 ) ;
V_62 = - V_8 ;
goto V_143;
}
V_5 -> V_57 = V_121 -> V_133 ;
if ( F_76 ( V_5 -> V_57 , F_44 , V_58 ,
V_128 , V_5 ) ) {
F_17 ( & V_14 -> V_15 , L_44 ,
V_5 -> V_57 ) ;
V_5 -> V_57 = 0 ;
V_62 = - V_8 ;
goto V_143;
}
V_62 = F_61 ( & V_5 -> V_2 ) ;
if ( V_62 < 0 ) {
F_17 ( & V_14 -> V_15 , L_45 ,
V_62 ) ;
goto V_144;
}
V_62 = F_77 ( & V_14 -> V_15 . V_115 , & V_116 ) ;
if ( V_62 < 0 ) {
F_6 ( & V_14 -> V_15 ,
L_46 , V_62 ) ;
goto V_145;
}
F_78 ( & V_5 -> V_21 ) ;
if ( F_10 ( & V_5 -> V_21 ) ) {
F_5 ( V_5 , 2 * V_146 ) ;
F_11 ( & V_5 -> V_21 ) ;
}
F_9 ( & V_14 -> V_15 ,
L_47 ,
V_5 -> V_66 ? L_48 : L_49 ) ;
return 0 ;
V_145:
F_61 ( NULL ) ;
V_144:
F_56 ( V_5 -> V_57 , V_5 ) ;
V_143:
if ( V_6 -> V_48 )
F_56 ( V_6 -> V_48 -> V_57 , V_5 ) ;
if ( V_6 -> V_22 )
F_56 ( V_6 -> V_22 -> V_57 , V_5 ) ;
F_39 ( V_5 ) ;
V_136:
F_59 ( V_5 -> V_117 ) ;
V_135:
F_59 ( V_5 -> V_65 ) ;
V_132:
F_57 ( V_5 -> V_16 ) ;
F_58 ( V_5 -> V_16 ) ;
V_126:
for ( V_114 -- ; V_114 >= 0 ; V_114 -- )
F_60 ( V_5 -> V_61 [ V_114 ] ) ;
F_62 ( V_14 , NULL ) ;
F_63 ( V_5 ) ;
return V_62 ;
}
static int F_79 ( struct V_113 * V_14 , T_5 V_84 )
{
struct V_4 * V_5 = F_54 ( V_14 ) ;
if ( V_5 -> V_2 . V_84 != V_86 ) {
F_9 ( & V_14 -> V_15 ,
L_50 ,
V_5 -> V_2 . V_84 ) ;
return - V_147 ;
}
if ( ! V_5 -> V_66 )
F_39 ( V_5 ) ;
return 0 ;
}
static int F_80 ( struct V_113 * V_14 )
{
struct V_4 * V_5 = F_54 ( V_14 ) ;
T_1 V_41 ;
if ( ! V_5 -> V_66 ) {
F_37 ( V_5 ) ;
V_41 = F_21 ( & V_5 -> V_34 -> V_41 ) ;
V_41 |= V_5 -> V_42 ;
F_22 ( V_41 , & V_5 -> V_34 -> V_41 ) ;
if ( F_10 ( & V_5 -> V_21 ) ) {
F_5 ( V_5 , 0 ) ;
F_11 ( & V_5 -> V_21 ) ;
}
}
return 0 ;
}
static int T_6 F_81 ( void )
{
return F_82 ( & V_148 ) ;
}
static void T_7 F_83 ( void )
{
F_84 ( & V_148 ) ;
}
