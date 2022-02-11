static int F_1 ( unsigned long V_1 ,
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
F_3 ( ( unsigned long ) V_3 , 2 ) ;
F_4 ( & V_12 , V_4 ) ;
if ( V_12 . V_13 . V_16 != 0 ) {
F_5 ( L_1 ,
V_12 . V_13 . V_16 ) ;
} else {
V_7 = V_12 . V_17 . V_18 ;
V_8 = V_12 . V_19 . V_20 ;
V_6 = V_12 . V_21 . V_22 ;
V_5 =
V_7 + V_8 ;
if ( ( V_7 + V_8 ) ) {
V_23 =
F_2 ( V_5 , V_6 ) ;
if ( V_23 ) {
F_3 ( ( unsigned long ) V_23 & V_24 ,
( V_6 + V_11 - 1 ) >> V_25 ) ;
V_9 = 0 ;
}
}
F_6 ( L_2 , V_7 ) ;
F_6 ( L_3 , V_8 ) ;
F_6 ( L_4 , V_6 ) ;
F_6 ( L_5 , & V_23 ) ;
}
F_7 ( V_3 ) ;
return V_9 ;
}
static int F_8 ( const char T_1 * V_26 , int V_27 )
{
char V_28 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ )
V_28 += V_26 [ V_29 ] ;
return ( ( V_28 == 0 ) && ( V_27 > 0 ) ) ;
}
static int F_9 ( const char T_1 * V_30 )
{
struct V_31 * V_32 ;
int V_33 ;
unsigned long V_1 , V_2 ;
V_32 = (struct V_31 * ) V_30 ;
if ( V_32 -> V_34 == V_35 ) {
V_33 = V_32 -> V_33 * V_36 ;
if ( F_8 ( V_30 , V_33 ) ) {
V_1 = V_32 -> V_37 & ~ ( V_11 - 1 ) ;
V_2 = V_32 -> V_37 - V_1 ;
return F_1 ( V_1 , V_2 ) ;
}
}
return - V_10 ;
}
static int F_10 ( void )
{
char T_1 * V_30 , * V_38 ;
int V_39 = - 1 ;
V_30 = F_2 ( V_40 , V_41 ) ;
if ( V_30 == NULL )
return - V_42 ;
for ( V_38 = V_30 ; V_38 < V_30 + V_41 ; V_38 += 16 ) {
V_39 = F_9 ( V_38 ) ;
if ( ! V_39 )
break;
}
F_7 ( V_30 ) ;
return V_39 ;
}
static void F_11 ( const struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 ;
unsigned long V_5 ;
if ( V_44 -> type == V_48 ) {
V_47 = (struct V_46 * ) V_44 ;
if ( V_47 -> V_34 == V_15 ) {
V_5 =
V_47 -> V_49 +
V_47 -> V_50 ;
V_23 = F_2 ( V_5 ,
V_47 -> V_51 ) ;
F_3 ( ( unsigned long ) V_23 & V_24 ,
V_47 -> V_51 >> V_25 ) ;
}
}
}
static int F_10 ( void )
{
V_23 = NULL ;
F_12 ( F_11 , NULL ) ;
return ( ( V_23 != NULL ) ? 0 : - V_10 ) ;
}
static void F_13 ( void )
{
V_52 = F_14 ( V_53 ) ;
F_15 ( V_52 , V_54 ) ;
F_16 ( 0x85 , V_55 ) ;
}
static void F_17 ( void )
{
unsigned long V_56 ;
V_56 = F_18 ( V_55 ) ;
V_56 &= 0xFE ;
F_16 ( V_56 , V_55 ) ;
}
static void F_19 ( void )
{
F_15 ( V_52 , V_54 ) ;
}
static int F_20 ( int V_57 )
{
if ( V_57 < 1 || V_57 > V_58 ) {
F_5 ( L_6 ,
V_57 ) ;
return - V_59 ;
}
V_53 = V_57 ;
F_6 ( L_7 , V_57 ) ;
V_52 = F_14 ( V_53 ) ;
return 0 ;
}
static int F_21 ( void )
{
return F_22 ( F_23 ( V_54 ) ) ;
}
static int F_24 ( unsigned int V_60 , struct V_61 * V_62 )
{
unsigned long V_63 ;
static int V_64 ;
if ( ! V_65 )
return V_66 ;
F_25 ( & V_67 , V_63 ) ;
if ( ! V_64 && ! V_68 && ! V_69 )
F_4 ( & V_12 , V_23 ) ;
V_64 = 1 ;
F_26 ( & V_67 , V_63 ) ;
if ( V_70 )
F_17 () ;
if ( ! V_68 && ! V_69 ) {
if ( V_12 . V_13 . V_16 == 0 ) {
F_27 ( V_62 , L_8 ) ;
return V_71 ;
}
}
F_27 ( V_62 , L_9
L_10
L_11
L_12
L_13
L_14
L_15 ) ;
return V_71 ;
}
static int F_28 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
if ( F_29 ( 0 , & V_74 ) )
return - V_75 ;
F_13 () ;
F_19 () ;
return F_30 ( V_72 , V_73 ) ;
}
static int F_31 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
if ( V_76 == 42 ) {
F_17 () ;
} else {
F_32 ( L_16 ) ;
F_19 () ;
}
V_76 = 0 ;
F_33 ( 0 , & V_74 ) ;
return 0 ;
}
static T_2 F_34 ( struct V_73 * V_73 , const char T_3 * V_56 ,
T_4 V_27 , T_5 * V_77 )
{
if ( V_27 ) {
if ( ! V_78 ) {
T_4 V_29 ;
V_76 = 0 ;
for ( V_29 = 0 ; V_29 != V_27 ; V_29 ++ ) {
char V_79 ;
if ( F_35 ( V_79 , V_56 + V_29 ) )
return - V_80 ;
if ( V_79 == 'V' )
V_76 = 42 ;
}
}
F_19 () ;
}
return V_27 ;
}
static long F_36 ( struct V_73 * V_73 , unsigned int V_81 ,
unsigned long V_82 )
{
void T_3 * V_83 = ( void T_3 * ) V_82 ;
int T_3 * V_30 = V_83 ;
int V_57 , V_84 ;
int V_85 = - V_86 ;
switch ( V_81 ) {
case V_87 :
V_85 = 0 ;
if ( F_37 ( V_83 , & V_88 , sizeof( V_88 ) ) )
V_85 = - V_80 ;
break;
case V_89 :
case V_90 :
V_85 = F_38 ( 0 , V_30 ) ;
break;
case V_91 :
F_19 () ;
V_85 = 0 ;
break;
case V_92 :
V_85 = F_35 ( V_84 , V_30 ) ;
if ( V_85 )
break;
if ( V_84 & V_93 )
F_17 () ;
if ( V_84 & V_94 ) {
F_13 () ;
F_19 () ;
}
break;
case V_95 :
V_85 = F_35 ( V_57 , V_30 ) ;
if ( V_85 )
break;
V_85 = F_20 ( V_57 ) ;
if ( V_85 )
break;
F_19 () ;
case V_96 :
V_85 = F_38 ( V_53 , V_30 ) ;
break;
case V_97 :
V_85 = F_38 ( F_21 () , V_30 ) ;
break;
}
return V_85 ;
}
static void F_39 ( struct V_98 * V_99 )
{
V_65 = 1 ;
}
static void F_39 ( struct V_98 * V_99 )
{
F_40 ( & V_99 -> V_99 , L_17
L_18 ) ;
}
static void F_41 ( const struct V_43 * V_44 , void * V_45 )
{
struct V_100 * V_101 ;
if ( V_44 -> type == V_102 ) {
V_101 = (struct V_100 * ) V_44 ;
if ( V_101 -> V_103 & 0x01 )
V_68 = 1 ;
if ( V_101 -> V_103 & 0x408 )
V_69 = 1 ;
}
}
static int F_42 ( struct V_98 * V_99 )
{
int V_9 ;
F_12 ( F_41 , NULL ) ;
if ( ! V_68 && ! V_69 ) {
V_9 = F_10 () ;
if ( V_9 < 0 ) {
F_40 ( & V_99 -> V_99 ,
L_19 ,
V_104 ) ;
return V_9 ;
}
V_12 . V_13 . V_105 = 0x0D ;
V_12 . V_13 . V_16 = 0x02 ;
}
V_9 = F_43 ( V_106 , F_24 , 0 , L_20 ) ;
if ( V_9 )
goto error;
V_9 = F_43 ( V_107 , F_24 , 0 , L_20 ) ;
if ( V_9 )
goto V_108;
V_9 = F_43 ( V_109 , F_24 , 0 , L_20 ) ;
if ( V_9 )
goto V_110;
F_44 ( & V_99 -> V_99 ,
L_21
L_22 ,
( V_70 == 0 ) ? L_23 : L_24 ) ;
return 0 ;
V_110:
F_45 ( V_107 , L_20 ) ;
V_108:
F_45 ( V_106 , L_20 ) ;
error:
F_40 ( & V_99 -> V_99 ,
L_25 ,
V_9 ) ;
if ( V_23 )
F_7 ( V_23 ) ;
return V_9 ;
}
static void F_46 ( void )
{
F_45 ( V_106 , L_20 ) ;
F_45 ( V_107 , L_20 ) ;
F_45 ( V_109 , L_20 ) ;
if ( V_23 )
F_7 ( V_23 ) ;
}
static void F_39 ( struct V_98 * V_99 )
{
}
static int F_42 ( struct V_98 * V_99 )
{
return 0 ;
}
static void F_46 ( void )
{
}
static int F_47 ( struct V_98 * V_99 ,
const struct V_111 * V_112 )
{
int V_9 ;
F_39 ( V_99 ) ;
if ( V_99 -> V_113 != V_114 &&
V_99 -> V_113 != V_115 ) {
F_40 ( & V_99 -> V_99 ,
L_26 ) ;
return - V_10 ;
}
if ( V_99 -> V_113 == V_114 &&
V_99 -> V_116 == 0x1979 )
return - V_10 ;
if ( F_48 ( V_99 ) ) {
F_40 ( & V_99 -> V_99 ,
L_27 ,
V_112 -> V_117 , V_112 -> V_118 ) ;
return - V_10 ;
}
V_119 = F_49 ( V_99 , 1 , 0x80 ) ;
if ( ! V_119 ) {
F_40 ( & V_99 -> V_99 ,
L_28 ) ;
V_9 = - V_42 ;
goto V_120;
}
V_54 = V_119 + 0x70 ;
V_55 = V_119 + 0x72 ;
F_17 () ;
if ( F_20 ( V_53 ) )
F_20 ( V_121 ) ;
V_9 = F_42 ( V_99 ) ;
if ( V_9 != 0 )
goto V_122;
V_9 = F_50 ( & V_123 ) ;
if ( V_9 < 0 ) {
F_40 ( & V_99 -> V_99 ,
L_29 ,
V_124 , V_9 ) ;
goto V_125;
}
F_44 ( & V_99 -> V_99 , L_30
L_31 ,
V_126 , V_53 , V_78 ) ;
return 0 ;
V_125:
F_46 () ;
V_122:
F_51 ( V_99 , V_119 ) ;
V_120:
F_52 ( V_99 ) ;
return V_9 ;
}
static void F_53 ( struct V_98 * V_99 )
{
if ( ! V_78 )
F_17 () ;
F_54 ( & V_123 ) ;
F_46 () ;
F_51 ( V_99 , V_119 ) ;
F_52 ( V_99 ) ;
}
