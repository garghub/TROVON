int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_2 -> V_9 & V_3 ) {
F_2 ( ( L_1 , V_3 , V_7 -> V_9 ) ) ;
return 1 ;
}
if ( V_7 -> V_9 & V_3 ) {
F_2 ( ( L_2 , V_7 -> V_9 , V_3 ) ) ;
return 0 ;
}
V_2 -> V_9 |= V_3 ;
V_7 -> V_9 |= V_3 ;
F_2 ( ( L_3 , V_3 , V_7 -> V_9 ) ) ;
return 1 ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_4 ( ( V_2 -> V_9 & V_10 ) != V_10 ) ;
V_2 -> V_9 &= ~ V_10 ;
V_7 -> V_9 &= ~ V_10 ;
F_2 ( ( L_4 , V_10 , V_7 -> V_9 ) ) ;
}
void F_5 ( struct V_4 * V_5 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( & V_14 -> V_17 ) ;
F_7 ( ( L_5 , V_5 , V_14 ) ) ;
F_4 ( F_8 () ) ;
F_9 ( V_12 , & V_14 -> V_17 , 0 , 0 ) ;
F_10 ( V_12 -> V_5 , V_16 ) ;
F_11 ( V_16 ) ;
V_14 -> V_17 . V_18 = V_19 ;
}
int F_12 ( struct V_4 * V_5 ,
struct V_20 * V_12 ,
struct V_13 * V_14 )
{
F_13 ( & V_5 -> V_21 ) ;
F_7 ( ( L_6 , V_5 , V_12 , V_14 ) ) ;
F_4 ( ! V_12 ) ;
if ( NULL == V_12 -> V_22 ) {
V_12 -> V_22 = V_14 ;
F_2 ( ( L_7 , V_14 ) ) ;
V_14 -> V_23 ( V_5 , V_14 , NULL ) ;
} else {
F_14 ( & V_14 -> V_17 . V_24 , & V_12 -> V_24 ) ;
V_14 -> V_17 . V_18 = V_25 ;
F_2 ( ( L_8 , V_14 ) ) ;
}
return 0 ;
}
void F_15 ( struct V_4 * V_5 ,
struct V_20 * V_12 ,
int V_18 )
{
F_13 ( & V_5 -> V_21 ) ;
F_7 ( ( L_9 , V_5 , V_12 , V_18 ) ) ;
F_7 ( ( L_10 , V_12 -> V_22 ) ) ;
F_4 ( ! V_12 -> V_22 ) ;
if ( NULL == V_12 -> V_22 ) {
F_2 ( ( L_11 ) ) ;
return;
}
V_12 -> V_22 -> V_17 . V_18 = V_18 ;
F_16 ( & V_12 -> V_22 -> V_17 . V_26 ) ;
F_17 ( & V_12 -> V_22 -> V_17 . V_27 ) ;
V_12 -> V_22 = NULL ;
}
void F_18 ( struct V_4 * V_5 ,
struct V_20 * V_12 , int V_28 )
{
struct V_13 * V_14 , * V_29 = NULL ;
F_4 ( ! V_12 ) ;
F_19 ( ( L_12 , V_5 , V_12 , V_28 ) ) ;
F_13 ( & V_5 -> V_21 ) ;
if ( ! F_20 ( & V_12 -> V_24 ) ) {
V_14 = F_21 ( V_12 -> V_24 . V_29 , struct V_13 , V_17 . V_24 ) ;
F_22 ( & V_14 -> V_17 . V_24 ) ;
if ( ! F_20 ( & V_12 -> V_24 ) )
V_29 = F_21 ( V_12 -> V_24 . V_29 , struct V_13 , V_17 . V_24 ) ;
V_12 -> V_22 = V_14 ;
F_19 ( ( L_13 , V_14 , V_12 -> V_24 . V_30 , V_12 -> V_24 . V_29 ) ) ;
V_14 -> V_23 ( V_5 , V_14 , V_29 ) ;
} else {
F_19 ( ( L_14 ) ) ;
if( 0 != V_28 ) {
F_23 ( V_5 , V_31 , V_32 ) ;
} else {
F_23 ( V_5 , V_33 , 0 ) ;
F_23 ( V_5 , V_34 , ( V_35 | V_36 ) ) ;
F_23 ( V_5 , V_37 , V_5 -> V_38 . V_39 ) ;
F_23 ( V_5 , V_31 , ( V_40 | V_41 ) ) ;
}
F_24 ( & V_12 -> V_42 ) ;
}
}
void F_25 ( unsigned long V_43 )
{
struct V_20 * V_12 = (struct V_20 * ) V_43 ;
struct V_4 * V_5 = V_12 -> V_5 ;
unsigned long V_44 ;
F_7 ( ( L_15 , V_5 , V_12 ) ) ;
F_26 ( & V_5 -> V_21 , V_44 ) ;
if ( V_12 -> V_22 ) {
F_2 ( ( L_16 , V_12 -> V_22 ) ) ;
F_15 ( V_5 , V_12 , V_45 ) ;
}
F_27 ( & V_5 -> V_21 , V_44 ) ;
}
static int F_28 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_4 * V_5 = F_30 ( V_46 ) ;
struct V_1 * V_2 = NULL ;
int V_49 = 0 ;
enum V_50 type ;
F_7 ( ( L_17 , V_46 , F_31 ( V_48 ) ) ) ;
if ( F_32 ( & V_51 ) )
return - V_52 ;
F_2 ( ( L_18 , V_5 ) ) ;
type = V_48 -> V_53 == V_54
? V_55
: V_56 ;
if( NULL == V_5 -> V_57 ) {
F_33 ( ( L_19 ) ) ;
V_49 = - V_58 ;
goto V_59;
}
V_2 = F_34 ( sizeof( * V_2 ) , V_60 ) ;
if ( NULL == V_2 ) {
F_33 ( ( L_20 ) ) ;
V_49 = - V_61 ;
goto V_59;
}
V_46 -> V_62 = V_2 ;
V_2 -> V_5 = V_5 ;
V_2 -> type = type ;
if( V_2 -> type == V_56 ) {
F_33 ( ( L_21 ) ) ;
if ( V_5 -> V_63 -> V_64 & V_65 )
V_49 = V_66 . V_67 ( V_5 , V_46 ) ;
if ( V_5 -> V_63 -> V_68 . V_67 )
V_5 -> V_63 -> V_68 . V_67 ( V_46 ) ;
} else {
F_33 ( ( L_22 ) ) ;
V_49 = V_69 . V_67 ( V_5 , V_46 ) ;
}
if ( 0 != V_49 ) {
goto V_59;
}
if( 0 == F_35 ( V_5 -> V_57 -> V_70 ) ) {
V_49 = - V_71 ;
goto V_59;
}
V_49 = 0 ;
V_59:
if ( V_2 && V_49 != 0 ) {
F_36 ( V_2 ) ;
V_46 -> V_62 = NULL ;
}
F_37 ( & V_51 ) ;
return V_49 ;
}
static int F_38 ( struct V_46 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_62 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_7 ( ( L_23 , V_46 ) ) ;
if ( F_32 ( & V_51 ) )
return - V_52 ;
if( V_2 -> type == V_56 ) {
if ( V_5 -> V_63 -> V_64 & V_65 )
V_66 . V_72 ( V_5 , V_46 ) ;
if ( V_5 -> V_63 -> V_68 . V_72 )
V_5 -> V_63 -> V_68 . V_72 ( V_46 ) ;
} else {
V_69 . V_72 ( V_5 , V_46 ) ;
}
F_39 ( V_5 -> V_57 -> V_70 ) ;
V_46 -> V_62 = NULL ;
F_36 ( V_2 ) ;
F_37 ( & V_51 ) ;
return 0 ;
}
static int F_40 ( struct V_46 * V_46 , struct V_73 * V_74 )
{
struct V_1 * V_2 = V_46 -> V_62 ;
struct V_11 * V_12 ;
switch ( V_2 -> type ) {
case V_55 : {
F_7 ( ( L_24 , V_46 , V_74 ) ) ;
V_12 = & V_2 -> V_75 ;
break;
}
case V_56 : {
F_7 ( ( L_25 , V_46 , V_74 ) ) ;
V_12 = & V_2 -> V_76 ;
break;
}
default:
F_41 () ;
return 0 ;
}
return F_42 ( V_12 , V_74 ) ;
}
static unsigned int F_43 ( struct V_46 * V_46 , struct V_77 * V_78 )
{
struct V_1 * V_2 = V_46 -> V_62 ;
struct V_79 * V_14 = NULL ;
struct V_11 * V_12 ;
F_7 ( ( L_26 , V_46 , V_78 ) ) ;
if ( V_56 == V_2 -> type ) {
if( 0 == V_2 -> V_76 . V_80 )
return F_44 ( V_46 , & V_2 -> V_76 , V_78 ) ;
V_12 = & V_2 -> V_76 ;
} else {
F_2 ( ( L_27 ) ) ;
V_12 = & V_2 -> V_75 ;
}
if ( ! F_20 ( & V_12 -> V_81 ) )
V_14 = F_21 ( V_12 -> V_81 . V_29 , struct V_79 , V_81 ) ;
if ( ! V_14 ) {
F_2 ( ( L_28 ) ) ;
return V_82 ;
}
F_45 ( V_46 , & V_14 -> V_27 , V_78 ) ;
if ( V_14 -> V_18 == V_83 || V_14 -> V_18 == V_45 ) {
F_2 ( ( L_29 ) ) ;
return V_84 | V_85 ;
}
F_2 ( ( L_30 , V_14 -> V_18 ) ) ;
return 0 ;
}
static T_1 F_46 ( struct V_46 * V_46 , char T_2 * V_43 , T_3 V_86 , T_4 * V_87 )
{
struct V_1 * V_2 = V_46 -> V_62 ;
switch ( V_2 -> type ) {
case V_55 : {
return V_69 . V_88 ( V_46 , V_43 , V_86 , V_87 ) ;
}
case V_56 : {
if ( V_2 -> V_5 -> V_63 -> V_64 & V_65 )
return V_66 . V_88 ( V_46 , V_43 , V_86 , V_87 ) ;
else
return - V_71 ;
}
break;
default:
F_41 () ;
return 0 ;
}
}
static T_1 F_47 ( struct V_46 * V_46 , const char T_2 * V_43 , T_3 V_86 , T_4 * V_87 )
{
struct V_1 * V_2 = V_46 -> V_62 ;
switch ( V_2 -> type ) {
case V_55 :
return - V_71 ;
case V_56 :
if ( V_2 -> V_5 -> V_63 -> V_68 . V_89 )
return V_2 -> V_5 -> V_63 -> V_68 . V_89 ( V_46 , V_43 , V_86 , V_87 ) ;
else
return - V_71 ;
default:
F_41 () ;
return - V_71 ;
}
}
static void F_48 ( struct V_4 * V_5 , unsigned long V_90 )
{
T_5 V_91 = V_90 ;
F_19 ( ( L_31 , V_5 , ( T_5 ) V_90 ) ) ;
if ( 0 != ( V_91 & ( V_92 ) ) ) {
F_19 ( ( L_32 , V_91 ) ) ;
V_69 . V_93 ( V_5 , V_91 ) ;
}
if ( 0 != ( V_91 & ( V_41 ) ) ) {
T_5 V_94 = F_49 ( V_5 , V_34 ) ;
if( 0 != ( V_94 & V_95 ) ) {
F_19 ( ( L_33 , V_91 ) ) ;
F_17 ( & V_5 -> V_8 -> V_96 ) ;
F_23 ( V_5 , V_34 , V_97 ) ;
return;
}
F_19 ( ( L_34 , V_91 ) ) ;
V_66 . V_93 ( V_5 , V_91 ) ;
}
}
int F_50 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_6 * V_7 ;
int V_100 ;
V_100 = F_51 ( & V_5 -> V_101 -> V_5 , & V_5 -> V_102 ) ;
if ( V_100 )
return V_100 ;
V_7 = F_34 ( sizeof( struct V_6 ) , V_60 ) ;
if ( V_7 == NULL ) {
F_52 ( ( L_35 ) ) ;
return - V_61 ;
}
V_99 -> V_103 = V_104 ;
V_99 -> V_105 = & V_104 ;
F_7 ( ( L_36 , V_5 ) ) ;
F_23 ( V_5 , V_106 , 0x80400040 ) ;
F_23 ( V_5 , V_31 , ( V_107 | V_108 ) ) ;
V_5 -> V_63 = V_99 ;
V_7 -> V_109 . V_110 = F_53 ( V_5 -> V_101 , V_111 , & V_7 -> V_109 . V_39 ) ;
if( NULL == V_7 -> V_109 . V_110 ) {
F_52 ( ( L_35 ) ) ;
F_36 ( V_7 ) ;
return - 1 ;
}
memset ( V_7 -> V_109 . V_110 , 0x0 , V_111 ) ;
V_69 . V_112 ( V_5 , V_7 ) ;
if ( V_5 -> V_63 -> V_64 & V_65 )
V_66 . V_112 ( V_5 , V_7 ) ;
V_5 -> V_8 = V_7 ;
V_5 -> F_48 = & F_48 ;
return 0 ;
}
int F_54 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_7 ( ( L_36 , V_5 ) ) ;
F_55 ( & V_5 -> V_102 ) ;
F_56 ( V_5 -> V_101 , V_111 , V_7 -> V_109 . V_110 , V_7 -> V_109 . V_39 ) ;
F_36 ( V_7 ) ;
V_5 -> V_8 = NULL ;
V_5 -> F_48 = NULL ;
return 0 ;
}
int F_57 ( struct V_47 * * V_113 , struct V_4 * V_5 ,
char * V_114 , int type )
{
struct V_47 * V_115 ;
int V_100 ;
int V_116 ;
F_7 ( ( L_37 , V_5 , V_114 , type ) ) ;
V_115 = F_58 () ;
if ( V_115 == NULL )
return - V_61 ;
V_115 -> V_117 = & V_118 ;
V_115 -> V_119 = & V_5 -> V_63 -> V_103 ;
V_115 -> V_72 = V_120 ;
V_115 -> V_121 = & V_5 -> V_122 ;
V_115 -> V_123 = 0 ;
for ( V_116 = 0 ; V_116 < V_5 -> V_63 -> V_124 ; V_116 ++ )
V_115 -> V_123 |= V_5 -> V_63 -> V_125 [ V_116 ] . V_126 ;
F_59 ( V_115 -> V_114 , V_114 , sizeof( V_115 -> V_114 ) ) ;
F_60 ( V_115 , V_5 ) ;
V_100 = F_61 ( V_115 , type , - 1 ) ;
if ( V_100 < 0 ) {
F_52 ( ( L_38 ) ) ;
V_120 ( V_115 ) ;
return V_100 ;
}
F_62 ( ( L_39 ,
V_5 -> V_114 , F_31 ( V_115 ) ) ) ;
* V_113 = V_115 ;
return 0 ;
}
int F_63 ( struct V_47 * * V_113 , struct V_4 * V_5 )
{
F_7 ( ( L_36 , V_5 ) ) ;
F_64 ( * V_113 ) ;
* V_113 = NULL ;
return 0 ;
}
static int T_6 F_65 ( void )
{
return 0 ;
}
static void T_7 F_66 ( void )
{
}
