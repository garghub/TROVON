static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return snprintf ( V_5 , V_11 ,
L_1 ,
( V_9 -> V_12 & V_13 ) ? L_2 : L_3 ,
( V_9 -> V_12 & V_14 ) ? L_4 :
( V_9 -> V_15 && ! ( V_9 -> V_12 & V_13 ) ) ? L_5 : L_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_16 * V_17 = V_9 -> V_18 [ 0 ] ;
if ( V_17 == NULL )
return snprintf ( V_5 , V_11 , L_7 ) ;
return snprintf ( V_5 , V_11 , L_8 , V_17 -> V_19 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_20 * V_21 [ 8 ] , * * V_22 , * * V_23 , * * V_24 ;
struct V_16 * * V_17 , * * V_25 ;
struct V_26 * V_27 , * V_28 ;
char * V_29 ;
memset ( V_21 , 0 , sizeof V_21 ) ;
V_22 = V_21 ;
V_24 = V_22 + F_5 ( V_21 ) ;
V_17 = V_9 -> V_18 ;
V_25 = V_17 + V_9 -> V_30 ;
for (; V_17 < V_25 && * V_17 ; V_17 ++ ) {
V_27 = ( * V_17 ) -> V_31 ;
V_28 = V_27 + V_32 ;
for (; V_27 < V_28 && V_27 -> V_22 ; V_27 ++ ) {
for ( V_23 = V_21 ; V_23 < V_22 ; V_23 ++ )
if ( * V_23 == V_27 -> V_22 )
break;
if ( V_23 == V_22 && V_22 != V_24 )
* V_22 ++ = V_27 -> V_22 ;
}
}
V_24 = V_22 ;
V_22 = V_21 ;
if ( * V_22 == NULL )
return snprintf ( V_5 , V_11 , L_7 ) ;
for ( V_29 = V_5 ; V_22 < V_24 ; V_22 ++ )
V_29 += snprintf ( V_29 , V_11 - ( V_29 - V_5 ) , L_9 ,
V_29 == V_5 ? L_6 : L_10 , ( * V_22 ) -> V_33 ) ;
V_29 += snprintf ( V_29 , V_11 - ( V_29 - V_5 ) , L_11 ) ;
return V_29 - V_5 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return snprintf ( V_5 , V_11 , L_12 , ( unsigned int ) V_9 -> V_34 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return snprintf ( V_5 , V_11 , L_13 , V_9 -> V_35 ) ;
}
static int F_8 ( struct V_36 * V_37 , void * V_38 )
{
struct V_8 * V_9 ;
struct V_16 * * V_17 , * * V_25 ;
struct V_26 * V_27 , * V_39 ;
unsigned long V_12 ;
char V_40 ;
V_9 = V_37 -> V_41 ;
F_9 ( V_37 , L_14 ,
V_9 -> V_42 >> V_43 ,
V_9 -> V_44 >> V_45 ) ;
F_9 ( V_37 , L_15 , F_10 ( & V_9 -> V_46 ) ) ;
F_9 ( V_37 , L_16 , V_9 -> V_47 ) ;
F_9 ( V_37 , L_17 , V_9 -> V_35 ) ;
F_9 ( V_37 , L_18 , V_9 -> V_48 ) ;
F_11 ( & V_9 -> V_49 , V_12 ) ;
V_17 = V_9 -> V_18 ;
V_25 = V_17 + V_9 -> V_30 ;
for (; V_17 < V_25 && * V_17 ; V_17 ++ ) {
V_40 = '\t' ;
F_9 ( V_37 , L_19 , ( * V_17 ) -> V_50 ) ;
F_9 ( V_37 , L_20 ,
F_12 ( & ( * V_17 ) -> V_51 ) ? NULL : ( * V_17 ) -> V_51 . V_52 ) ;
F_9 ( V_37 , L_21 , ( * V_17 ) -> V_19 , ( * V_17 ) -> V_53 ,
( * V_17 ) -> V_54 , ( * V_17 ) -> V_55 ) ;
F_9 ( V_37 , L_22 , ( * V_17 ) -> V_56 ) ;
F_9 ( V_37 , L_23 , ( * V_17 ) -> V_57 ) ;
F_9 ( V_37 , L_24 , ( * V_17 ) -> V_58 ) ;
F_9 ( V_37 , L_25 , ( * V_17 ) -> V_59 ) ;
V_27 = ( * V_17 ) -> V_31 ;
V_39 = V_27 + F_5 ( ( * V_17 ) -> V_31 ) ;
for (; V_27 -> V_22 && V_27 < V_39 ; V_27 ++ ) {
F_9 ( V_37 , L_26 , V_40 , V_27 -> V_22 -> V_33 ) ;
V_40 = ',' ;
}
F_13 ( V_37 , L_11 ) ;
}
F_14 ( & V_9 -> V_49 , V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
return F_16 ( V_61 , F_8 , V_60 -> V_62 ) ;
}
static void
F_17 ( struct V_8 * V_9 )
{
struct V_63 * V_64 ;
char * V_29 ;
if ( V_65 == NULL )
return;
V_29 = strchr ( V_9 -> V_66 -> V_67 , '/' ) ;
if ( V_29 == NULL )
V_29 = V_9 -> V_66 -> V_67 ;
else
V_29 ++ ;
F_18 ( * V_29 == '\0' ) ;
V_64 = F_19 ( V_29 , 0444 , V_65 , V_9 ,
& V_68 ) ;
if ( F_20 ( V_64 ) ) {
F_21 ( L_27 ,
V_9 -> V_66 -> V_67 ) ;
return;
}
F_18 ( V_9 -> V_69 ) ;
V_9 -> V_69 = V_64 ;
}
void
F_22 ( struct V_8 * V_9 )
{
F_23 ( V_9 -> V_69 ) ;
V_9 -> V_69 = NULL ;
}
static int
F_24 ( struct V_8 * V_9 )
{
return F_25 ( & F_26 ( V_9 -> V_66 ) -> V_70 , & V_71 ) ;
}
void
F_27 ( struct V_8 * V_9 )
{
F_28 ( & F_26 ( V_9 -> V_66 ) -> V_70 , & V_71 ) ;
}
static int
F_29 ( struct V_72 * V_73 , T_2 V_74 )
{
struct V_8 * V_9 = V_73 -> V_75 -> V_10 ;
T_3 V_12 ;
if ( ! F_30 ( V_9 ) ) {
F_31 ( L_28 ,
V_76 ) ;
F_32 ( 1 ) ;
return - V_77 ;
}
if ( ! ( V_9 -> V_12 & V_13 ) || V_9 -> V_12 & V_78 )
return - V_77 ;
F_33 ( & V_79 ) ;
F_11 ( & V_9 -> V_49 , V_12 ) ;
if ( V_9 -> V_12 & V_13 && ! ( V_9 -> V_12 & V_78 ) ) {
V_9 -> V_15 ++ ;
F_14 ( & V_9 -> V_49 , V_12 ) ;
F_34 ( & V_79 ) ;
return 0 ;
}
F_14 ( & V_9 -> V_49 , V_12 ) ;
F_34 ( & V_79 ) ;
return - V_77 ;
}
static void
F_35 ( struct V_6 * V_7 , T_2 V_74 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_12 ;
F_11 ( & V_9 -> V_49 , V_12 ) ;
if ( -- V_9 -> V_15 == 0 ) {
F_14 ( & V_9 -> V_49 , V_12 ) ;
F_36 ( V_9 -> V_80 , V_9 -> V_81 ) ;
return;
}
F_14 ( & V_9 -> V_49 , V_12 ) ;
}
static void
F_37 ( struct V_82 * V_83 )
{
struct V_8 * V_9 ;
struct V_84 * V_85 ;
V_9 = V_83 -> V_86 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_38 ( L_29 ,
V_9 -> V_80 , V_9 -> V_81 ) ;
while ( ( V_85 = F_39 ( V_83 ) ) ) {
F_40 ( V_85 ) ;
F_41 ( V_9 , V_85 , 1 ) ;
}
return;
}
F_42 ( V_9 ) ;
}
static int
F_43 ( struct V_72 * V_73 , struct V_87 * V_88 )
{
struct V_8 * V_9 = V_73 -> V_75 -> V_10 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_44 ( V_89 L_30 ) ;
return - V_77 ;
}
V_88 -> V_90 = V_9 -> V_88 . V_90 ;
V_88 -> V_91 = V_9 -> V_88 . V_91 ;
V_88 -> V_92 = V_9 -> V_88 . V_92 ;
return 0 ;
}
static int
F_45 ( struct V_72 * V_73 , T_2 V_74 , T_4 V_93 , T_3 V_94 )
{
struct V_8 * V_9 ;
if ( ! V_94 )
return - V_95 ;
V_9 = V_73 -> V_75 -> V_10 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_46 ( L_30 ) ;
return - V_77 ;
}
if ( V_93 == V_96 ) {
if ( ! F_47 ( ( void V_97 * ) V_94 , & V_9 -> V_98 ,
sizeof( V_9 -> V_98 ) ) )
return 0 ;
return - V_99 ;
}
if ( V_93 != V_100 )
F_21 ( L_31 , V_93 ) ;
return - V_101 ;
}
void
F_48 ( void * V_102 )
{
struct V_8 * V_9 = V_102 ;
struct V_6 * V_66 ;
T_5 * V_103 ;
struct V_82 * V_83 ;
enum { V_104 = 1024 , V_105 = V_104 * V_104 , V_106 = 2 * V_105 , };
T_3 V_12 ;
int V_107 = 0 ;
F_11 ( & V_9 -> V_49 , V_12 ) ;
if ( V_9 -> V_12 & V_108
&& ! ( V_9 -> V_12 & V_78 )
&& ! ( V_9 -> V_12 & V_109 ) )
V_9 -> V_12 |= V_109 ;
else
V_107 = 1 ;
F_14 ( & V_9 -> V_49 , V_12 ) ;
if ( V_107 )
return;
V_66 = F_49 ( V_110 ) ;
if ( V_66 == NULL ) {
F_46 ( L_32 ,
V_9 -> V_80 , V_9 -> V_81 ) ;
goto V_111;
}
V_103 = F_50 ( V_112 , V_113 , V_114 ,
V_115 ) ;
if ( V_103 == NULL ) {
F_44 ( V_89 L_33 ,
V_9 -> V_80 , V_9 -> V_81 ) ;
goto V_116;
}
V_83 = F_51 ( F_37 , & V_9 -> V_49 ) ;
if ( V_83 == NULL ) {
F_46 ( L_34 ,
V_9 -> V_80 , V_9 -> V_81 ) ;
goto V_117;
}
F_11 ( & V_9 -> V_49 , V_12 ) ;
F_32 ( ! ( V_9 -> V_12 & V_109 ) ) ;
F_32 ( ! ( V_9 -> V_12 & V_108 ) ) ;
F_32 ( V_9 -> V_12 & V_78 ) ;
F_32 ( V_9 -> V_66 ) ;
F_32 ( V_9 -> V_12 & V_13 ) ;
F_52 ( V_83 , 1024 ) ;
V_83 -> V_118 . V_33 = L_35 ;
V_83 -> V_118 . V_119 = V_106 / V_120 ;
V_9 -> V_121 = V_103 ;
V_9 -> V_122 = V_66 -> V_123 = V_83 ;
V_83 -> V_86 = V_9 ;
V_9 -> V_66 = V_66 ;
if ( V_124 )
F_52 ( V_83 , V_124 ) ;
V_66 -> V_125 = V_126 ;
V_66 -> V_127 = V_9 -> V_128 ;
V_66 -> V_129 = & V_130 ;
V_66 -> V_10 = V_9 ;
F_53 ( V_66 , V_9 -> V_131 ) ;
snprintf ( V_66 -> V_67 , sizeof V_66 -> V_67 , L_36 ,
V_9 -> V_80 , V_9 -> V_81 ) ;
V_9 -> V_12 &= ~ V_108 ;
V_9 -> V_12 |= V_13 ;
F_14 ( & V_9 -> V_49 , V_12 ) ;
F_54 ( V_66 ) ;
F_24 ( V_9 ) ;
F_17 ( V_9 ) ;
F_11 ( & V_9 -> V_49 , V_12 ) ;
F_32 ( ! ( V_9 -> V_12 & V_109 ) ) ;
V_9 -> V_12 &= ~ V_109 ;
F_14 ( & V_9 -> V_49 , V_12 ) ;
return;
V_117:
F_55 ( V_103 ) ;
V_116:
F_56 ( V_66 ) ;
V_111:
F_11 ( & V_9 -> V_49 , V_12 ) ;
V_9 -> V_12 &= ~ V_109 ;
F_57 ( & V_9 -> V_132 ) ;
F_14 ( & V_9 -> V_49 , V_12 ) ;
}
void
F_58 ( void )
{
F_59 ( V_65 ) ;
V_65 = NULL ;
F_60 ( V_115 ) ;
}
int T_6
F_61 ( void )
{
V_115 = F_62 ( L_37 ,
sizeof( struct V_133 ) ,
0 , 0 , NULL ) ;
if ( V_115 == NULL )
return - V_134 ;
V_65 = F_63 ( L_35 , NULL ) ;
if ( F_20 ( V_65 ) ) {
F_21 ( L_38 ) ;
V_65 = NULL ;
}
return 0 ;
}
