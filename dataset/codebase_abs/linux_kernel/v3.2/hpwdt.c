static int T_1 F_1 ( unsigned long V_1 ,
unsigned long V_2 )
{
void * V_3 ;
unsigned long * V_4 ;
unsigned long V_5 ;
unsigned long V_6 ;
unsigned long V_7 = 0 ;
unsigned long V_8 = 0 ;
int V_9 = - V_10 ;
V_3 = F_2 ( V_1 , ( 2 * V_11 ) ) ;
if ( V_3 == NULL )
return - V_10 ;
V_4 = V_3 + V_2 ;
V_12 . V_13 . V_14 = V_15 ;
F_3 ( ( unsigned long ) V_4 , ( 2 * V_11 ) ) ;
F_4 ( & V_12 , V_4 ) ;
if ( V_12 . V_13 . V_16 != 0 ) {
F_5 ( V_17
L_1 ,
V_12 . V_13 . V_16 ) ;
} else {
V_7 = V_12 . V_18 . V_19 ;
V_8 = V_12 . V_20 . V_21 ;
V_6 = V_12 . V_22 . V_23 ;
V_5 =
V_7 + V_8 ;
if ( ( V_7 + V_8 ) ) {
V_24 =
F_2 ( V_5 , V_6 ) ;
if ( V_24 ) {
F_3 ( ( unsigned long ) V_24 , V_6 ) ;
V_9 = 0 ;
}
}
F_5 ( V_25 L_2 ,
V_7 ) ;
F_5 ( V_25 L_3 ,
V_8 ) ;
F_5 ( V_25 L_4 ,
V_6 ) ;
F_5 ( V_25 L_5 ,
& V_24 ) ;
}
F_6 ( V_3 ) ;
return V_9 ;
}
static int T_1 F_7 ( const char T_2 * V_26 , int V_27 )
{
char V_28 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ )
V_28 += V_26 [ V_29 ] ;
return ( ( V_28 == 0 ) && ( V_27 > 0 ) ) ;
}
static int T_1 F_8 ( const char T_2 * V_30 )
{
struct V_31 * V_32 ;
int V_33 ;
unsigned long V_1 , V_2 ;
V_32 = (struct V_31 * ) V_30 ;
if ( V_32 -> V_34 == V_35 ) {
V_33 = V_32 -> V_33 * V_36 ;
if ( F_7 ( V_30 , V_33 ) ) {
V_1 = V_32 -> V_37 & ~ ( V_11 - 1 ) ;
V_2 = V_32 -> V_37 - V_1 ;
return F_1 ( V_1 , V_2 ) ;
}
}
return - V_10 ;
}
static int T_1 F_9 ( void )
{
char T_2 * V_30 , * V_38 ;
int V_39 = - 1 ;
V_30 = F_2 ( V_40 , V_41 ) ;
if ( V_30 == NULL )
return - V_42 ;
for ( V_38 = V_30 ; V_38 < V_30 + V_41 ; V_38 += 16 ) {
V_39 = F_8 ( V_38 ) ;
if ( ! V_39 )
break;
}
F_6 ( V_30 ) ;
return V_39 ;
}
static void T_1 F_10 ( const struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 ;
unsigned long V_5 ;
if ( V_44 -> type == V_48 ) {
V_47 = (struct V_46 * ) V_44 ;
if ( V_47 -> V_34 == V_15 ) {
V_5 =
V_47 -> V_49 +
V_47 -> V_50 ;
V_24 = F_2 ( V_5 ,
V_47 -> V_51 ) ;
F_3 ( ( unsigned long ) V_24 & V_52 ,
V_47 -> V_51 >> V_53 ) ;
}
}
}
static int T_1 F_9 ( void )
{
V_24 = NULL ;
F_11 ( F_10 , NULL ) ;
return ( ( V_24 != NULL ) ? 0 : - V_10 ) ;
}
static void F_12 ( void )
{
V_54 = F_13 ( V_55 ) ;
F_14 ( V_54 , V_56 ) ;
F_14 ( 0x85 , V_57 ) ;
}
static void F_15 ( void )
{
unsigned long V_58 ;
V_58 = F_16 ( V_57 ) ;
V_58 &= 0xFE ;
F_14 ( V_58 , V_57 ) ;
}
static void F_17 ( void )
{
F_14 ( V_54 , V_56 ) ;
}
static int F_18 ( int V_59 )
{
if ( V_59 < 1 || V_59 > V_60 ) {
F_5 ( V_17
L_6 ,
V_59 ) ;
return - V_61 ;
}
V_55 = V_59 ;
F_5 ( V_25
L_7 ,
V_59 ) ;
V_54 = F_13 ( V_55 ) ;
return 0 ;
}
static int F_19 ( void )
{
return F_20 ( F_16 ( V_56 ) ) ;
}
static int F_21 ( unsigned int V_62 , struct V_63 * V_64 )
{
unsigned long V_65 ;
static int V_66 ;
if ( ! V_67 )
goto V_68;
F_22 ( & V_69 , V_65 ) ;
if ( ! V_66 && ! V_70 )
F_4 ( & V_12 , V_24 ) ;
V_66 = 1 ;
F_23 ( & V_69 , V_65 ) ;
if ( V_71 )
F_15 () ;
if ( ! V_70 ) {
if ( V_12 . V_13 . V_16 == 0 ) {
F_24 ( L_8
L_9 ) ;
}
}
F_24 ( L_10
L_11 ) ;
V_68:
return V_72 ;
}
static int F_25 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
if ( F_26 ( 0 , & V_75 ) )
return - V_76 ;
F_12 () ;
F_17 () ;
return F_27 ( V_73 , V_74 ) ;
}
static int F_28 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
if ( V_77 == 42 ) {
F_15 () ;
} else {
F_5 ( V_78
L_12 ) ;
F_17 () ;
}
V_77 = 0 ;
F_29 ( 0 , & V_75 ) ;
return 0 ;
}
static T_3 F_30 ( struct V_74 * V_74 , const char T_4 * V_58 ,
T_5 V_27 , T_6 * V_79 )
{
if ( V_27 ) {
if ( ! V_80 ) {
T_5 V_29 ;
V_77 = 0 ;
for ( V_29 = 0 ; V_29 != V_27 ; V_29 ++ ) {
char V_81 ;
if ( F_31 ( V_81 , V_58 + V_29 ) )
return - V_82 ;
if ( V_81 == 'V' )
V_77 = 42 ;
}
}
F_17 () ;
}
return V_27 ;
}
static long F_32 ( struct V_74 * V_74 , unsigned int V_83 ,
unsigned long V_84 )
{
void T_4 * V_85 = ( void T_4 * ) V_84 ;
int T_4 * V_30 = V_85 ;
int V_59 ;
int V_86 = - V_87 ;
switch ( V_83 ) {
case V_88 :
V_86 = 0 ;
if ( F_33 ( V_85 , & V_89 , sizeof( V_89 ) ) )
V_86 = - V_82 ;
break;
case V_90 :
case V_91 :
V_86 = F_34 ( 0 , V_30 ) ;
break;
case V_92 :
F_17 () ;
V_86 = 0 ;
break;
case V_93 :
V_86 = F_31 ( V_59 , V_30 ) ;
if ( V_86 )
break;
V_86 = F_18 ( V_59 ) ;
if ( V_86 )
break;
F_17 () ;
case V_94 :
V_86 = F_34 ( V_55 , V_30 ) ;
break;
case V_95 :
V_86 = F_34 ( F_19 () , V_30 ) ;
break;
}
return V_86 ;
}
static void T_1 F_35 ( struct V_96 * V_97 )
{
V_67 = 1 ;
}
static void T_1 F_35 ( struct V_96 * V_97 )
{
F_36 ( & V_97 -> V_97 , L_13
L_14 ) ;
}
static void T_1 F_37 ( const struct V_43 * V_44 , void * V_45 )
{
struct V_98 * V_99 ;
if ( V_44 -> type == V_100 ) {
V_99 = (struct V_98 * ) V_44 ;
if ( V_99 -> V_101 & 0x01 )
V_70 = 1 ;
}
}
static int T_1 F_38 ( struct V_96 * V_97 )
{
int V_9 ;
F_11 ( F_37 , NULL ) ;
if ( ! V_70 ) {
V_9 = F_9 () ;
if ( V_9 < 0 ) {
F_36 ( & V_97 -> V_97 ,
L_15 ,
V_102 ) ;
return V_9 ;
}
V_12 . V_13 . V_103 = 0x0D ;
V_12 . V_13 . V_16 = 0x02 ;
}
V_9 = F_39 ( V_104 , F_21 ,
( V_105 ) ? V_106 : 0 ,
L_16 ) ;
if ( V_9 != 0 ) {
F_36 ( & V_97 -> V_97 ,
L_17 ,
V_9 ) ;
if ( V_24 )
F_6 ( V_24 ) ;
}
F_40 ( & V_97 -> V_97 ,
L_18
L_19
L_20 ,
( V_71 == 0 ) ? L_21 : L_22 ,
( V_105 == 0 ) ? L_23 : L_24 ) ;
return 0 ;
}
static void F_41 ( void )
{
F_42 ( V_104 , L_16 ) ;
if ( V_24 )
F_6 ( V_24 ) ;
}
static void T_1 F_35 ( struct V_96 * V_97 )
{
}
static int T_1 F_38 ( struct V_96 * V_97 )
{
return 0 ;
}
static void F_41 ( void )
{
}
static int T_1 F_43 ( struct V_96 * V_97 ,
const struct V_107 * V_108 )
{
int V_9 ;
F_35 ( V_97 ) ;
if ( V_97 -> V_109 != V_110 ) {
F_36 ( & V_97 -> V_97 ,
L_25 ) ;
return - V_10 ;
}
if ( F_44 ( V_97 ) ) {
F_36 ( & V_97 -> V_97 ,
L_26 ,
V_108 -> V_111 , V_108 -> V_112 ) ;
return - V_10 ;
}
V_113 = F_45 ( V_97 , 1 , 0x80 ) ;
if ( ! V_113 ) {
F_36 ( & V_97 -> V_97 ,
L_27 ) ;
V_9 = - V_42 ;
goto V_114;
}
V_56 = V_113 + 0x70 ;
V_57 = V_113 + 0x72 ;
if ( F_18 ( V_55 ) )
F_18 ( V_115 ) ;
V_9 = F_38 ( V_97 ) ;
if ( V_9 != 0 )
goto V_116;
V_9 = F_46 ( & V_117 ) ;
if ( V_9 < 0 ) {
F_36 ( & V_97 -> V_97 ,
L_28 ,
V_118 , V_9 ) ;
goto V_119;
}
F_40 ( & V_97 -> V_97 , L_29
L_30 ,
V_120 , V_55 , V_80 ) ;
return 0 ;
V_119:
F_41 () ;
V_116:
F_47 ( V_97 , V_113 ) ;
V_114:
F_48 ( V_97 ) ;
return V_9 ;
}
static void T_7 F_49 ( struct V_96 * V_97 )
{
if ( ! V_80 )
F_15 () ;
F_50 ( & V_117 ) ;
F_41 () ;
F_47 ( V_97 , V_113 ) ;
F_48 ( V_97 ) ;
}
static void T_8 F_51 ( void )
{
F_52 ( & V_121 ) ;
}
static int T_9 F_53 ( void )
{
return F_54 ( & V_121 ) ;
}
