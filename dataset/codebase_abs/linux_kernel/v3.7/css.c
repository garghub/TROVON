int
F_1 ( int (* F_2)( struct V_1 , void * ) , void * V_2 )
{
struct V_1 V_3 ;
int V_4 ;
F_3 ( & V_3 ) ;
V_4 = - V_5 ;
do {
do {
V_4 = F_2 ( V_3 , V_2 ) ;
if ( V_4 )
break;
} while ( V_3 . V_6 ++ < V_7 );
V_3 . V_6 = 0 ;
} while ( V_3 . V_8 ++ < V_9 );
return V_4 ;
}
static int F_4 ( struct V_10 * V_11 , void * V_2 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_14 * V_15 = V_2 ;
int V_16 = 0 ;
F_6 ( V_15 -> V_17 , V_13 -> V_3 ) ;
if ( V_15 -> V_18 )
V_16 = V_15 -> V_18 ( V_13 , V_15 -> V_2 ) ;
return V_16 ;
}
static int F_7 ( struct V_1 V_3 , void * V_2 )
{
struct V_14 * V_15 = V_2 ;
int V_16 = 0 ;
if ( F_8 ( V_15 -> V_17 , V_3 ) )
V_16 = V_15 -> V_19 ( V_3 , V_15 -> V_2 ) ;
return V_16 ;
}
static int F_9 ( struct V_1 V_3 , void * V_2 )
{
struct V_14 * V_15 = V_2 ;
struct V_12 * V_13 ;
int V_16 = 0 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
if ( V_15 -> V_18 )
V_16 = V_15 -> V_18 ( V_13 , V_15 -> V_2 ) ;
F_11 ( & V_13 -> V_11 ) ;
} else {
if ( V_15 -> V_19 )
V_16 = V_15 -> V_19 ( V_3 , V_15 -> V_2 ) ;
}
return V_16 ;
}
int F_12 ( int (* F_13)( struct V_12 * , void * ) ,
int (* F_14)( struct V_1 ,
void * ) , void * V_2 )
{
struct V_14 V_15 ;
int V_16 ;
V_15 . V_2 = V_2 ;
V_15 . V_18 = F_13 ;
V_15 . V_19 = F_14 ;
V_15 . V_17 = F_15 () ;
if ( ! V_15 . V_17 )
return F_1 ( F_9 , & V_15 ) ;
F_16 ( V_15 . V_17 ) ;
V_16 = F_17 ( & V_20 , NULL , & V_15 , F_4 ) ;
if ( V_16 )
goto V_21;
if ( F_14 )
V_16 = F_1 ( F_7 , & V_15 ) ;
V_21:
F_18 ( V_15 . V_17 ) ;
return V_16 ;
}
static struct V_12 *
F_19 ( struct V_1 V_3 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_20 ( sizeof ( * V_13 ) , V_22 | V_23 ) ;
if ( V_13 == NULL )
return F_21 ( - V_24 ) ;
V_4 = F_22 ( V_13 , V_3 ) ;
if ( V_4 < 0 ) {
F_23 ( V_13 ) ;
return F_21 ( V_4 ) ;
}
F_24 ( & V_13 -> V_25 , V_26 ) ;
return V_13 ;
}
static void
F_25 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( ! F_26 ( V_13 -> V_3 ) ) {
V_13 -> V_27 . V_28 = 0 ;
F_27 ( V_13 ) ;
F_23 ( V_13 -> V_29 ) ;
F_23 ( V_13 ) ;
}
}
static int F_28 ( struct V_12 * V_13 )
{
int V_4 ;
F_29 ( & V_13 -> V_30 ) ;
F_30 ( & V_13 -> V_11 , L_1 , V_13 -> V_3 . V_8 ,
V_13 -> V_3 . V_6 ) ;
V_4 = F_31 ( & V_13 -> V_11 ) ;
F_32 ( & V_13 -> V_30 ) ;
return V_4 ;
}
void F_33 ( struct V_12 * V_13 )
{
F_29 ( & V_13 -> V_30 ) ;
if ( F_34 ( & V_13 -> V_11 ) )
F_35 ( & V_13 -> V_11 ) ;
F_32 ( & V_13 -> V_30 ) ;
}
static void F_36 ( struct V_31 * V_32 , struct V_33 * V_33 )
{
int V_34 ;
int V_35 ;
memset ( V_32 , 0 , sizeof( struct V_31 ) ) ;
V_32 -> V_36 = V_33 -> V_37 ;
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ ) {
V_35 = 0x80 >> V_34 ;
if ( V_33 -> V_37 & V_35 ) {
F_37 ( & V_32 -> V_38 [ V_34 ] ) ;
V_32 -> V_38 [ V_34 ] . V_39 = V_33 -> V_38 [ V_34 ] ;
}
}
}
static void F_38 ( struct V_31 * V_32 )
{
int V_34 ;
int V_35 ;
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ ) {
V_35 = 0x80 >> V_34 ;
if ( V_32 -> V_36 & V_35 )
if ( ! F_39 ( V_32 -> V_38 [ V_34 ] ) )
F_40 ( V_32 -> V_38 [ V_34 ] ) ;
}
}
void F_41 ( struct V_12 * V_13 )
{
int V_4 ;
if ( F_26 ( V_13 -> V_3 ) ) {
F_36 ( & V_13 -> V_40 , & V_13 -> V_41 . V_33 ) ;
} else {
V_4 = F_42 ( V_13 -> V_3 , & V_13 -> V_40 ) ;
if ( V_4 )
F_36 ( & V_13 -> V_40 , & V_13 -> V_41 . V_33 ) ;
F_38 ( & V_13 -> V_40 ) ;
}
}
static T_1 F_43 ( struct V_10 * V_11 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return sprintf ( V_44 , L_2 , V_13 -> V_45 ) ;
}
static T_1 F_44 ( struct V_10 * V_11 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return sprintf ( V_44 , L_3 , V_13 -> V_45 ) ;
}
static int F_45 ( struct V_12 * V_13 )
{
int V_4 ;
V_13 -> V_11 . V_46 = & V_47 [ 0 ] -> V_10 ;
V_13 -> V_11 . V_48 = & V_20 ;
V_13 -> V_11 . V_49 = & F_25 ;
V_13 -> V_11 . V_50 = V_51 ;
F_46 ( & V_13 -> V_11 , 1 ) ;
F_41 ( V_13 ) ;
V_4 = F_28 ( V_13 ) ;
if ( V_4 ) {
F_47 ( 0 , L_4 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_4 ) ;
return V_4 ;
}
if ( ! V_13 -> V_52 ) {
F_46 ( & V_13 -> V_11 , 0 ) ;
F_48 ( & V_13 -> V_11 . V_53 , V_54 ) ;
}
return V_4 ;
}
int F_49 ( struct V_1 V_3 )
{
int V_4 ;
struct V_12 * V_13 ;
if ( F_26 ( V_3 ) )
V_13 = F_50 () ;
else {
V_13 = F_19 ( V_3 ) ;
if ( F_51 ( V_13 ) )
return F_52 ( V_13 ) ;
}
V_4 = F_45 ( V_13 ) ;
if ( V_4 ) {
if ( ! F_26 ( V_3 ) )
F_11 ( & V_13 -> V_11 ) ;
}
return V_4 ;
}
static int
F_53 ( struct V_10 * V_11 , void * V_2 )
{
struct V_12 * V_13 ;
struct V_1 * V_3 = V_2 ;
V_13 = F_5 ( V_11 ) ;
return F_54 ( & V_13 -> V_3 , V_3 ) ;
}
struct V_12 *
F_10 ( struct V_1 V_3 )
{
struct V_10 * V_11 ;
V_11 = F_55 ( & V_20 , NULL ,
& V_3 , F_53 ) ;
return V_11 ? F_5 ( V_11 ) : NULL ;
}
int F_56 ( struct V_41 * V_41 )
{
if ( ( V_41 -> V_33 . V_45 == V_55 ) && ! V_41 -> V_33 . V_56 )
return 0 ;
if ( ( V_41 -> V_33 . V_45 == V_57 ) && ! V_41 -> V_33 . V_58 )
return 0 ;
return 1 ;
}
static int F_57 ( struct V_1 V_3 , int V_59 )
{
struct V_41 V_41 ;
if ( ! V_59 ) {
return - V_60 ;
}
if ( F_58 ( V_3 , & V_41 ) ) {
return - V_61 ;
}
if ( ! F_56 ( & V_41 ) ) {
return 0 ;
}
F_47 ( 4 , L_5 , V_3 . V_8 ,
V_3 . V_6 ) ;
return F_49 ( V_3 ) ;
}
static int F_59 ( struct V_12 * V_13 , int V_59 )
{
int V_4 = 0 ;
if ( V_13 -> V_52 ) {
if ( V_13 -> V_52 -> V_62 )
V_4 = V_13 -> V_52 -> V_62 ( V_13 , V_59 ) ;
else
F_60 ( & V_13 -> V_11 ,
L_6
L_7 ) ;
}
if ( V_4 != 0 && V_4 != - V_60 ) {
F_47 ( 2 , L_8 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_4 ) ;
}
return V_4 ;
}
static void F_61 ( struct V_1 V_3 , int V_59 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
V_4 = F_59 ( V_13 , V_59 ) ;
F_11 ( & V_13 -> V_11 ) ;
} else
V_4 = F_57 ( V_3 , V_59 ) ;
if ( V_4 == - V_60 )
F_62 ( V_3 ) ;
}
void F_63 ( struct V_12 * V_13 , enum V_63 V_64 )
{
F_47 ( 4 , L_9 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_64 ) ;
if ( V_13 -> V_64 >= V_64 )
return;
if ( ! F_64 ( & V_13 -> V_11 ) )
return;
V_13 -> V_64 = V_64 ;
if ( ! F_65 ( V_65 , & V_13 -> V_25 ) ) {
F_11 ( & V_13 -> V_11 ) ;
}
}
static void V_26 ( struct V_66 * V_67 )
{
struct V_12 * V_13 ;
enum V_63 V_64 ;
int V_4 ;
V_13 = F_66 ( V_67 , struct V_12 , V_25 ) ;
F_67 ( V_13 -> V_29 ) ;
V_64 = V_13 -> V_64 ;
F_47 ( 4 , L_10 , V_13 -> V_3 . V_8 ,
V_13 -> V_3 . V_6 , V_64 ) ;
V_13 -> V_64 = V_68 ;
F_68 ( V_13 -> V_29 ) ;
switch ( V_64 ) {
case V_68 :
break;
case V_69 :
V_4 = F_59 ( V_13 , 1 ) ;
if ( V_4 == - V_60 ) {
F_67 ( V_13 -> V_29 ) ;
F_63 ( V_13 , V_64 ) ;
F_68 ( V_13 -> V_29 ) ;
}
break;
case V_70 :
F_33 ( V_13 ) ;
break;
}
F_11 ( & V_13 -> V_11 ) ;
}
static int T_2 F_69 ( void )
{
F_70 ( & V_71 ) ;
F_71 ( & V_72 , 0 ) ;
F_72 ( & V_73 ) ;
V_74 = F_15 () ;
if ( ! V_74 ) {
F_47 ( 0 , L_11 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_73 ( struct V_12 * V_13 , void * V_2 )
{
int V_75 ;
int V_16 ;
F_67 ( & V_71 ) ;
V_75 = F_8 ( V_74 , V_13 -> V_3 ) ;
F_6 ( V_74 , V_13 -> V_3 ) ;
F_68 ( & V_71 ) ;
if ( V_75 ) {
V_16 = F_59 ( V_13 , 1 ) ;
if ( V_16 == - V_60 )
F_62 ( V_13 -> V_3 ) ;
}
return 0 ;
}
static int F_74 ( struct V_1 V_3 , void * V_2 )
{
int V_75 ;
int V_16 = 0 ;
F_67 ( & V_71 ) ;
V_75 = F_8 ( V_74 , V_3 ) ;
F_6 ( V_74 , V_3 ) ;
F_68 ( & V_71 ) ;
if ( V_75 ) {
V_16 = F_57 ( V_3 , 1 ) ;
switch ( V_16 ) {
case - V_60 :
F_62 ( V_3 ) ;
V_16 = 0 ;
break;
case - V_61 :
case - V_24 :
case - V_76 :
F_75 ( V_74 , V_3 ) ;
break;
default:
V_16 = 0 ;
}
}
return V_16 ;
}
static void F_76 ( struct V_66 * V_77 )
{
unsigned long V_78 ;
F_77 ( 4 , L_12 ) ;
F_12 ( F_73 , F_74 ,
NULL ) ;
F_78 ( & V_71 , V_78 ) ;
if ( F_79 ( V_74 ) ) {
F_71 ( & V_72 , 0 ) ;
F_80 ( & V_73 ) ;
}
F_81 ( & V_71 , V_78 ) ;
}
void F_62 ( struct V_1 V_3 )
{
unsigned long V_78 ;
F_78 ( & V_71 , V_78 ) ;
F_82 ( V_74 , V_3 ) ;
F_71 ( & V_72 , 1 ) ;
F_65 ( V_65 , & V_79 ) ;
F_81 ( & V_71 , V_78 ) ;
}
void F_83 ( void )
{
unsigned long V_78 ;
F_78 ( & V_71 , V_78 ) ;
F_16 ( V_74 ) ;
F_71 ( & V_72 , 1 ) ;
F_65 ( V_65 , & V_79 ) ;
F_81 ( & V_71 , V_78 ) ;
}
static int F_84 ( struct V_10 * V_11 , void * V_2 )
{
struct V_80 * V_17 = V_2 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_17 , V_13 -> V_3 ) ;
return 0 ;
}
static void F_85 ( void )
{
unsigned long V_78 ;
struct V_80 * V_81 ;
V_81 = F_15 () ;
if ( ! V_81 ) {
F_83 () ;
return;
}
F_16 ( V_81 ) ;
F_17 ( & V_20 , NULL , V_81 , F_84 ) ;
F_78 ( & V_71 , V_78 ) ;
F_86 ( V_74 , V_81 ) ;
F_71 ( & V_72 , 1 ) ;
F_65 ( V_65 , & V_79 ) ;
F_81 ( & V_71 , V_78 ) ;
F_18 ( V_81 ) ;
}
void F_87 ( void )
{
F_88 ( V_65 ) ;
}
void F_89 ( void )
{
F_85 () ;
}
static void F_90 ( struct V_82 * V_83 , struct V_82 * V_84 , int V_85 )
{
struct V_1 V_86 ;
struct V_12 * V_13 ;
if ( V_85 ) {
F_83 () ;
return;
}
F_91 ( 2 , L_13
L_14 ,
V_83 -> V_87 , V_83 -> V_88 , V_83 -> V_89 , V_83 -> V_90 , V_83 -> V_91 ,
V_83 -> V_92 , V_83 -> V_93 ) ;
if ( V_84 )
F_91 ( 2 , L_15
L_14 ,
V_84 -> V_87 , V_84 -> V_88 , V_84 -> V_89 , V_84 -> V_90 ,
V_84 -> V_91 , V_84 -> V_92 , V_84 -> V_93 ) ;
F_3 ( & V_86 ) ;
V_86 . V_6 = V_83 -> V_93 ;
if ( V_84 )
V_86 . V_8 = ( V_84 -> V_93 >> 4 ) & 3 ;
if ( V_83 -> V_92 == V_94 ) {
V_13 = F_10 ( V_86 ) ;
if ( V_13 ) {
F_41 ( V_13 ) ;
F_11 ( & V_13 -> V_11 ) ;
}
}
F_61 ( V_86 , 0 ) ;
}
static void T_2
F_92 ( struct V_95 * V_96 , T_3 V_97 )
{
struct V_98 V_99 ;
if ( V_100 . V_101 ) {
V_96 -> V_102 . V_103 . V_104 . V_105 = 0x80 ;
V_96 -> V_102 . V_103 . V_104 . V_106 = V_96 -> V_106 ;
} else {
#ifdef F_93
V_96 -> V_102 . V_103 . V_107 = F_94 () ;
#else
V_96 -> V_102 . V_103 . V_107 = 0 ;
#endif
}
F_95 ( & V_99 ) ;
V_96 -> V_102 . V_99 = V_99 . V_108 ;
V_96 -> V_102 . V_109 = V_99 . V_110 ;
V_96 -> V_102 . V_97 = V_97 ;
}
static void
F_96 ( struct V_10 * V_11 )
{
struct V_95 * V_96 ;
V_96 = F_97 ( V_11 ) ;
F_98 ( & V_96 -> V_111 ) ;
if ( V_96 -> V_112 ) {
F_25 ( & V_96 -> V_112 -> V_11 ) ;
V_96 -> V_112 = NULL ;
}
F_23 ( V_96 ) ;
}
static T_1
F_99 ( struct V_10 * V_11 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_95 * V_96 = F_97 ( V_11 ) ;
int V_4 ;
if ( ! V_96 )
return 0 ;
F_29 ( & V_96 -> V_111 ) ;
V_4 = sprintf ( V_44 , L_16 , V_96 -> V_113 ) ;
F_32 ( & V_96 -> V_111 ) ;
return V_4 ;
}
static T_1
F_100 ( struct V_10 * V_11 , struct V_42 * V_43 ,
const char * V_44 , T_4 V_114 )
{
struct V_95 * V_96 = F_97 ( V_11 ) ;
int V_4 ;
unsigned long V_115 ;
V_4 = F_101 ( V_44 , 16 , & V_115 ) ;
if ( V_4 )
return V_4 ;
F_29 ( & V_96 -> V_111 ) ;
switch ( V_115 ) {
case 0 :
V_4 = V_96 -> V_113 ? F_102 ( V_96 , 0 ) : 0 ;
break;
case 1 :
V_4 = V_96 -> V_113 ? 0 : F_102 ( V_96 , 1 ) ;
break;
default:
V_4 = - V_116 ;
}
F_32 ( & V_96 -> V_111 ) ;
return V_4 < 0 ? V_4 : V_114 ;
}
static int T_2 F_103 ( int V_117 )
{
T_3 V_97 ;
int V_4 ;
struct V_95 * V_96 ;
V_96 = V_47 [ V_117 ] ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
V_96 -> V_112 =
F_104 ( sizeof( * V_96 -> V_112 ) , V_22 ) ;
if ( ! V_96 -> V_112 )
return - V_24 ;
V_96 -> V_112 -> V_11 . V_46 = & V_96 -> V_10 ;
V_96 -> V_112 -> V_11 . V_49 = F_25 ;
F_30 ( & V_96 -> V_112 -> V_11 , L_17 ) ;
F_105 ( & V_96 -> V_112 -> V_30 ) ;
V_4 = F_106 ( V_96 -> V_112 ) ;
if ( V_4 ) {
F_23 ( V_96 -> V_112 ) ;
return V_4 ;
}
F_105 ( & V_96 -> V_111 ) ;
V_96 -> V_118 = 1 ;
V_96 -> V_106 = V_117 ;
F_30 ( & V_96 -> V_10 , L_18 , V_117 ) ;
V_96 -> V_10 . V_49 = F_96 ;
V_97 = ( T_3 ) ( F_107 () >> 32 ) ;
F_92 ( V_96 , V_97 ) ;
return 0 ;
}
static int F_108 ( struct V_119 * V_120 ,
unsigned long V_121 ,
void * V_122 )
{
int V_4 , V_34 ;
V_4 = V_123 ;
for ( V_34 = 0 ; V_34 <= V_124 ; V_34 ++ ) {
struct V_95 * V_96 ;
V_96 = V_47 [ V_34 ] ;
F_29 ( & V_96 -> V_111 ) ;
if ( V_96 -> V_113 )
if ( F_102 ( V_96 , 0 ) )
V_4 = V_125 ;
F_32 ( & V_96 -> V_111 ) ;
}
return V_4 ;
}
static int F_109 ( struct V_119 * V_120 , unsigned long V_121 ,
void * V_122 )
{
int V_4 , V_34 ;
switch ( V_121 ) {
case V_126 :
case V_127 :
V_4 = V_123 ;
for ( V_34 = 0 ; V_34 <= V_124 ; V_34 ++ ) {
struct V_95 * V_96 ;
V_96 = V_47 [ V_34 ] ;
F_29 ( & V_96 -> V_111 ) ;
if ( ! V_96 -> V_113 ) {
F_32 ( & V_96 -> V_111 ) ;
continue;
}
V_4 = F_110 ( V_96 , 0 ) ;
V_4 = F_111 ( V_4 ) ;
F_32 ( & V_96 -> V_111 ) ;
}
break;
case V_128 :
case V_129 :
V_4 = V_123 ;
for ( V_34 = 0 ; V_34 <= V_124 ; V_34 ++ ) {
struct V_95 * V_96 ;
V_96 = V_47 [ V_34 ] ;
F_29 ( & V_96 -> V_111 ) ;
if ( ! V_96 -> V_113 ) {
F_32 ( & V_96 -> V_111 ) ;
continue;
}
V_4 = F_110 ( V_96 , 1 ) ;
V_4 = F_111 ( V_4 ) ;
F_32 ( & V_96 -> V_111 ) ;
}
F_89 () ;
break;
default:
V_4 = V_123 ;
}
return V_4 ;
}
static int T_2 F_112 ( void )
{
int V_4 , V_34 ;
V_4 = F_113 () ;
if ( V_4 )
return V_4 ;
F_114 () ;
V_4 = F_115 ( V_130 ) ;
if ( V_4 )
V_9 = 0 ;
else
V_9 = V_131 ;
V_4 = F_69 () ;
if ( V_4 )
goto V_21;
V_4 = F_116 ( V_132 , F_90 ) ;
if ( V_4 )
goto V_21;
if ( ( V_4 = F_117 ( & V_20 ) ) )
goto V_21;
for ( V_34 = 0 ; V_34 <= V_124 ; V_34 ++ ) {
struct V_95 * V_96 ;
V_96 = F_20 ( sizeof( struct V_95 ) , V_22 ) ;
if ( ! V_96 ) {
V_4 = - V_24 ;
goto V_133;
}
V_47 [ V_34 ] = V_96 ;
V_4 = F_103 ( V_34 ) ;
if ( V_4 ) {
F_23 ( V_47 [ V_34 ] ) ;
goto V_133;
}
V_4 = F_31 ( & V_96 -> V_10 ) ;
if ( V_4 ) {
F_11 ( & V_96 -> V_10 ) ;
goto V_133;
}
if ( V_134 . V_135 ) {
V_4 = F_118 ( & V_96 -> V_10 ,
& V_136 ) ;
if ( V_4 )
goto V_137;
}
V_4 = F_31 ( & V_96 -> V_112 -> V_11 ) ;
if ( V_4 ) {
F_11 ( & V_96 -> V_112 -> V_11 ) ;
goto V_138;
}
}
V_4 = F_119 ( & V_139 ) ;
if ( V_4 )
goto V_133;
V_4 = F_120 ( & V_140 ) ;
if ( V_4 ) {
F_121 ( & V_139 ) ;
goto V_133;
}
V_141 = 1 ;
F_122 ( V_142 ) ;
return 0 ;
V_138:
if ( V_134 . V_135 )
F_123 ( & V_47 [ V_34 ] -> V_10 ,
& V_136 ) ;
V_137:
F_35 ( & V_47 [ V_34 ] -> V_10 ) ;
V_133:
while ( V_34 > 0 ) {
struct V_95 * V_96 ;
V_34 -- ;
V_96 = V_47 [ V_34 ] ;
F_35 ( & V_96 -> V_112 -> V_11 ) ;
V_96 -> V_112 = NULL ;
if ( V_134 . V_135 )
F_123 ( & V_96 -> V_10 ,
& V_136 ) ;
F_35 ( & V_96 -> V_10 ) ;
}
F_124 ( & V_20 ) ;
V_21:
F_125 ( V_132 ) ;
F_18 ( V_74 ) ;
F_126 () ;
F_127 ( L_19
L_20 , V_4 ) ;
return V_4 ;
}
static void T_2 F_128 ( void )
{
struct V_95 * V_96 ;
int V_34 ;
for ( V_34 = 0 ; V_34 <= V_124 ; V_34 ++ ) {
V_96 = V_47 [ V_34 ] ;
F_35 ( & V_96 -> V_112 -> V_11 ) ;
V_96 -> V_112 = NULL ;
if ( V_134 . V_135 )
F_123 ( & V_96 -> V_10 , & V_136 ) ;
F_35 ( & V_96 -> V_10 ) ;
}
F_124 ( & V_20 ) ;
F_125 ( V_132 ) ;
F_18 ( V_74 ) ;
F_126 () ;
F_129 ( V_142 ) ;
}
static int T_2 F_130 ( void )
{
int V_4 ;
V_4 = F_112 () ;
if ( V_4 )
return V_4 ;
V_65 = F_131 ( L_21 ) ;
if ( ! V_65 ) {
V_4 = - V_24 ;
goto V_143;
}
V_4 = F_132 () ;
if ( V_4 )
goto V_144;
return V_4 ;
V_144:
F_133 ( V_65 ) ;
V_143:
F_128 () ;
return V_4 ;
}
static int F_134 ( struct V_145 * V_146 , void * V_77 )
{
struct V_147 * V_148 = F_135 ( V_146 ) ;
if ( V_148 -> V_149 )
return V_148 -> V_149 () ;
return 0 ;
}
int F_136 ( void )
{
int V_4 ;
V_4 = F_137 ( V_73 ,
F_138 ( & V_72 ) == 0 ) ;
if ( V_4 )
return - V_150 ;
F_88 ( V_65 ) ;
return F_139 ( & V_20 , NULL , NULL , F_134 ) ;
}
static int T_2 F_140 ( void )
{
F_83 () ;
F_136 () ;
return 0 ;
}
void F_141 ( void )
{
struct V_151 * V_152 ;
struct V_153 V_38 ;
F_115 ( V_130 ) ;
F_142 (&chpid) {
V_152 = F_143 ( V_38 ) ;
if ( ! V_152 )
continue;
F_144 ( V_38 , & V_152 -> V_154 ) ;
}
}
static T_1 F_145 ( struct V_155 * V_155 , const char T_5 * V_44 ,
T_4 V_114 , T_6 * V_156 )
{
int V_4 ;
F_146 () ;
V_4 = F_136 () ;
return V_4 ? V_4 : V_114 ;
}
static int T_2 F_147 ( void )
{
struct V_157 * V_158 ;
V_158 = F_148 ( L_22 , V_159 , NULL ,
& V_160 ) ;
if ( ! V_158 )
return - V_24 ;
return 0 ;
}
int F_149 ( struct V_12 * V_13 )
{
return V_13 == F_97 ( V_13 -> V_11 . V_46 ) -> V_112 ;
}
static int F_150 ( struct V_10 * V_11 , struct V_145 * V_146 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_147 * V_52 = F_135 ( V_146 ) ;
struct V_161 * V_39 ;
for ( V_39 = V_52 -> V_162 ; V_39 -> V_163 ; V_39 ++ ) {
if ( V_13 -> V_45 == V_39 -> type )
return 1 ;
}
return 0 ;
}
static int F_151 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_5 ( V_11 ) ;
V_13 -> V_52 = F_135 ( V_11 -> V_52 ) ;
V_4 = V_13 -> V_52 -> V_164 ? V_13 -> V_52 -> V_164 ( V_13 ) : 0 ;
if ( V_4 )
V_13 -> V_52 = NULL ;
return V_4 ;
}
static int F_152 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_5 ( V_11 ) ;
V_4 = V_13 -> V_52 -> remove ? V_13 -> V_52 -> remove ( V_13 ) : 0 ;
V_13 -> V_52 = NULL ;
return V_4 ;
}
static void F_153 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_52 && V_13 -> V_52 -> V_165 )
V_13 -> V_52 -> V_165 ( V_13 ) ;
}
static int F_154 ( struct V_10 * V_11 , struct V_166 * V_167 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_4 ;
V_4 = F_155 ( V_167 , L_23 , V_13 -> V_45 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_155 ( V_167 , L_24 , V_13 -> V_45 ) ;
return V_4 ;
}
static int F_156 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_147 * V_146 ;
if ( F_157 ( & V_13 -> V_30 ) )
return - V_60 ;
if ( ! V_13 -> V_11 . V_52 )
return 0 ;
V_146 = F_135 ( V_13 -> V_11 . V_52 ) ;
return V_146 -> V_168 ? V_146 -> V_168 ( V_13 ) : 0 ;
}
static void F_158 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_147 * V_146 ;
if ( ! V_13 -> V_11 . V_52 )
return;
V_146 = F_135 ( V_13 -> V_11 . V_52 ) ;
if ( V_146 -> V_169 )
V_146 -> V_169 ( V_13 ) ;
}
static int F_159 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_147 * V_146 ;
if ( ! V_13 -> V_11 . V_52 )
return 0 ;
V_146 = F_135 ( V_13 -> V_11 . V_52 ) ;
return V_146 -> V_170 ? V_146 -> V_170 ( V_13 ) : 0 ;
}
static int F_160 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_147 * V_146 ;
if ( ! V_13 -> V_11 . V_52 )
return 0 ;
V_146 = F_135 ( V_13 -> V_11 . V_52 ) ;
return V_146 -> V_171 ? V_146 -> V_171 ( V_13 ) : 0 ;
}
static int F_161 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_147 * V_146 ;
F_41 ( V_13 ) ;
if ( ! V_13 -> V_11 . V_52 )
return 0 ;
V_146 = F_135 ( V_13 -> V_11 . V_52 ) ;
return V_146 -> V_172 ? V_146 -> V_172 ( V_13 ) : 0 ;
}
int F_162 ( struct V_147 * V_173 )
{
V_173 -> V_146 . V_48 = & V_20 ;
return F_163 ( & V_173 -> V_146 ) ;
}
void F_164 ( struct V_147 * V_173 )
{
F_165 ( & V_173 -> V_146 ) ;
}
