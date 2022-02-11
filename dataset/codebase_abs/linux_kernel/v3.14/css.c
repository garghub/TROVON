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
if ( V_15 -> V_17 )
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
if ( F_13 && ! F_14 ) {
V_15 . V_17 = NULL ;
return F_15 ( & V_20 , NULL , & V_15 ,
F_4 ) ;
}
V_15 . V_17 = F_16 () ;
if ( ! V_15 . V_17 )
return F_1 ( F_9 , & V_15 ) ;
F_17 ( V_15 . V_17 ) ;
V_16 = F_15 ( & V_20 , NULL , & V_15 , F_4 ) ;
if ( V_16 )
goto V_21;
if ( F_14 )
V_16 = F_1 ( F_7 , & V_15 ) ;
V_21:
F_18 ( V_15 . V_17 ) ;
return V_16 ;
}
static int F_19 ( struct V_12 * V_13 )
{
V_13 -> V_22 = F_20 ( sizeof( * V_13 -> V_22 ) , V_23 ) ;
if ( ! V_13 -> V_22 )
return - V_24 ;
F_21 ( V_13 -> V_22 ) ;
F_22 ( & V_13 -> V_25 ) ;
return 0 ;
}
static void F_23 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_26 . V_27 = 0 ;
F_24 ( V_13 ) ;
F_25 ( V_13 -> V_22 ) ;
F_25 ( V_13 ) ;
}
struct V_12 * F_26 ( struct V_1 V_3 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_27 ( sizeof( * V_13 ) , V_23 | V_28 ) ;
if ( ! V_13 )
return F_28 ( - V_24 ) ;
V_4 = F_29 ( V_13 , V_3 ) ;
if ( V_4 < 0 )
goto V_29;
V_4 = F_19 ( V_13 ) ;
if ( V_4 )
goto V_29;
F_30 ( & V_13 -> V_30 , V_31 ) ;
V_13 -> V_11 . V_32 = & F_23 ;
F_31 ( & V_13 -> V_11 ) ;
return V_13 ;
V_29:
F_25 ( V_13 ) ;
return F_28 ( V_4 ) ;
}
static int F_32 ( struct V_12 * V_13 )
{
int V_4 ;
F_33 ( & V_13 -> V_25 ) ;
F_34 ( & V_13 -> V_11 , L_1 , V_13 -> V_3 . V_8 ,
V_13 -> V_3 . V_6 ) ;
V_4 = F_35 ( & V_13 -> V_11 ) ;
F_36 ( & V_13 -> V_25 ) ;
return V_4 ;
}
void F_37 ( struct V_12 * V_13 )
{
F_33 ( & V_13 -> V_25 ) ;
if ( F_38 ( & V_13 -> V_11 ) )
F_39 ( & V_13 -> V_11 ) ;
F_36 ( & V_13 -> V_25 ) ;
}
static void F_40 ( struct V_33 * V_34 , struct V_35 * V_35 )
{
int V_36 ;
int V_37 ;
memset ( V_34 , 0 , sizeof( struct V_33 ) ) ;
V_34 -> V_38 = V_35 -> V_39 ;
for ( V_36 = 0 ; V_36 < 8 ; V_36 ++ ) {
V_37 = 0x80 >> V_36 ;
if ( V_35 -> V_39 & V_37 ) {
F_41 ( & V_34 -> V_40 [ V_36 ] ) ;
V_34 -> V_40 [ V_36 ] . V_41 = V_35 -> V_40 [ V_36 ] ;
}
}
}
static void F_42 ( struct V_33 * V_34 )
{
int V_36 ;
int V_37 ;
for ( V_36 = 0 ; V_36 < 8 ; V_36 ++ ) {
V_37 = 0x80 >> V_36 ;
if ( V_34 -> V_38 & V_37 )
if ( ! F_43 ( V_34 -> V_40 [ V_36 ] ) )
F_44 ( V_34 -> V_40 [ V_36 ] ) ;
}
}
void F_45 ( struct V_12 * V_13 )
{
int V_4 ;
V_4 = F_46 ( V_13 -> V_3 , & V_13 -> V_42 ) ;
if ( V_4 )
F_40 ( & V_13 -> V_42 , & V_13 -> V_43 . V_35 ) ;
F_42 ( & V_13 -> V_42 ) ;
}
static T_1 F_47 ( struct V_10 * V_11 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return sprintf ( V_46 , L_2 , V_13 -> V_47 ) ;
}
static T_1 F_48 ( struct V_10 * V_11 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return sprintf ( V_46 , L_3 , V_13 -> V_47 ) ;
}
int F_49 ( struct V_12 * V_13 )
{
int V_4 ;
V_13 -> V_11 . V_48 = & V_49 [ 0 ] -> V_10 ;
V_13 -> V_11 . V_50 = & V_20 ;
V_13 -> V_11 . V_51 = V_52 ;
F_50 ( & V_13 -> V_11 , 1 ) ;
F_45 ( V_13 ) ;
V_4 = F_32 ( V_13 ) ;
if ( V_4 ) {
F_51 ( 0 , L_4 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_4 ) ;
return V_4 ;
}
if ( ! V_13 -> V_53 ) {
F_50 ( & V_13 -> V_11 , 0 ) ;
F_52 ( & V_13 -> V_11 . V_54 , V_55 ) ;
}
return V_4 ;
}
static int F_53 ( struct V_1 V_3 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_26 ( V_3 ) ;
if ( F_54 ( V_13 ) )
return F_55 ( V_13 ) ;
V_4 = F_49 ( V_13 ) ;
if ( V_4 )
F_11 ( & V_13 -> V_11 ) ;
return V_4 ;
}
static int
F_56 ( struct V_10 * V_11 , void * V_2 )
{
struct V_12 * V_13 ;
struct V_1 * V_3 = V_2 ;
V_13 = F_5 ( V_11 ) ;
return F_57 ( & V_13 -> V_3 , V_3 ) ;
}
struct V_12 *
F_10 ( struct V_1 V_3 )
{
struct V_10 * V_11 ;
V_11 = F_58 ( & V_20 , NULL ,
& V_3 , F_56 ) ;
return V_11 ? F_5 ( V_11 ) : NULL ;
}
int F_59 ( struct V_43 * V_43 )
{
if ( ( V_43 -> V_35 . V_47 == V_56 ) && ! V_43 -> V_35 . V_57 )
return 0 ;
if ( ( V_43 -> V_35 . V_47 == V_58 ) && ! V_43 -> V_35 . V_59 )
return 0 ;
return 1 ;
}
static int F_60 ( struct V_1 V_3 , int V_60 )
{
struct V_43 V_43 ;
if ( ! V_60 ) {
return - V_61 ;
}
if ( F_61 ( V_3 , & V_43 ) ) {
return - V_62 ;
}
if ( ! F_59 ( & V_43 ) ) {
return 0 ;
}
F_51 ( 4 , L_5 , V_3 . V_8 ,
V_3 . V_6 ) ;
return F_53 ( V_3 ) ;
}
static int F_62 ( struct V_12 * V_13 , int V_60 )
{
int V_4 = 0 ;
if ( V_13 -> V_53 ) {
if ( V_13 -> V_53 -> V_63 )
V_4 = V_13 -> V_53 -> V_63 ( V_13 , V_60 ) ;
else
F_63 ( & V_13 -> V_11 ,
L_6
L_7 ) ;
}
if ( V_4 != 0 && V_4 != - V_61 ) {
F_51 ( 2 , L_8 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_4 ) ;
}
return V_4 ;
}
static void F_64 ( struct V_1 V_3 , int V_60 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
V_4 = F_62 ( V_13 , V_60 ) ;
F_11 ( & V_13 -> V_11 ) ;
} else
V_4 = F_60 ( V_3 , V_60 ) ;
if ( V_4 == - V_61 )
F_65 ( V_3 ) ;
}
void F_66 ( struct V_12 * V_13 , enum V_64 V_65 )
{
F_51 ( 4 , L_9 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_65 ) ;
if ( V_13 -> V_65 >= V_65 )
return;
if ( ! F_67 ( & V_13 -> V_11 ) )
return;
V_13 -> V_65 = V_65 ;
if ( ! F_68 ( V_66 , & V_13 -> V_30 ) ) {
F_11 ( & V_13 -> V_11 ) ;
}
}
static void V_31 ( struct V_67 * V_68 )
{
struct V_12 * V_13 ;
enum V_64 V_65 ;
int V_4 ;
V_13 = F_69 ( V_68 , struct V_12 , V_30 ) ;
F_70 ( V_13 -> V_22 ) ;
V_65 = V_13 -> V_65 ;
F_51 ( 4 , L_10 , V_13 -> V_3 . V_8 ,
V_13 -> V_3 . V_6 , V_65 ) ;
V_13 -> V_65 = V_69 ;
F_71 ( V_13 -> V_22 ) ;
switch ( V_65 ) {
case V_69 :
break;
case V_70 :
V_4 = F_62 ( V_13 , 1 ) ;
if ( V_4 == - V_61 ) {
F_70 ( V_13 -> V_22 ) ;
F_66 ( V_13 , V_65 ) ;
F_71 ( V_13 -> V_22 ) ;
}
break;
case V_71 :
F_37 ( V_13 ) ;
break;
}
F_11 ( & V_13 -> V_11 ) ;
}
static int T_2 F_72 ( void )
{
F_21 ( & V_72 ) ;
F_73 ( & V_73 , 0 ) ;
F_74 ( & V_74 ) ;
V_75 = F_16 () ;
if ( ! V_75 ) {
F_51 ( 0 , L_11 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_75 ( struct V_12 * V_13 , void * V_2 )
{
int V_76 ;
int V_16 ;
F_70 ( & V_72 ) ;
V_76 = F_8 ( V_75 , V_13 -> V_3 ) ;
F_6 ( V_75 , V_13 -> V_3 ) ;
F_71 ( & V_72 ) ;
if ( V_76 ) {
V_16 = F_62 ( V_13 , 1 ) ;
if ( V_16 == - V_61 )
F_65 ( V_13 -> V_3 ) ;
}
return 0 ;
}
static int F_76 ( struct V_1 V_3 , void * V_2 )
{
int V_76 ;
int V_16 = 0 ;
F_70 ( & V_72 ) ;
V_76 = F_8 ( V_75 , V_3 ) ;
F_6 ( V_75 , V_3 ) ;
F_71 ( & V_72 ) ;
if ( V_76 ) {
V_16 = F_60 ( V_3 , 1 ) ;
switch ( V_16 ) {
case - V_61 :
F_65 ( V_3 ) ;
V_16 = 0 ;
break;
case - V_62 :
case - V_24 :
case - V_77 :
F_70 ( & V_72 ) ;
F_77 ( V_75 , V_3 ) ;
F_71 ( & V_72 ) ;
break;
default:
V_16 = 0 ;
}
F_78 () ;
}
return V_16 ;
}
static void F_79 ( struct V_67 * V_78 )
{
unsigned long V_79 ;
F_80 ( 4 , L_12 ) ;
F_12 ( F_75 , F_76 ,
NULL ) ;
F_81 ( & V_72 , V_79 ) ;
if ( F_82 ( V_75 ) ) {
F_73 ( & V_73 , 0 ) ;
F_83 ( & V_74 ) ;
}
F_84 ( & V_72 , V_79 ) ;
}
void F_65 ( struct V_1 V_3 )
{
unsigned long V_79 ;
F_81 ( & V_72 , V_79 ) ;
F_85 ( V_75 , V_3 ) ;
F_73 ( & V_73 , 1 ) ;
F_86 ( V_66 , & V_80 , 0 ) ;
F_84 ( & V_72 , V_79 ) ;
}
void F_87 ( void )
{
unsigned long V_79 ;
F_81 ( & V_72 , V_79 ) ;
F_17 ( V_75 ) ;
F_73 ( & V_73 , 1 ) ;
F_86 ( V_66 , & V_80 , 0 ) ;
F_84 ( & V_72 , V_79 ) ;
}
static int F_88 ( struct V_10 * V_11 , void * V_2 )
{
struct V_81 * V_17 = V_2 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_17 , V_13 -> V_3 ) ;
return 0 ;
}
void F_89 ( unsigned long V_82 )
{
unsigned long V_79 ;
struct V_81 * V_83 ;
V_83 = F_16 () ;
if ( ! V_83 ) {
F_87 () ;
return;
}
F_17 ( V_83 ) ;
F_15 ( & V_20 , NULL , V_83 , F_88 ) ;
F_81 ( & V_72 , V_79 ) ;
F_90 ( V_75 , V_83 ) ;
F_73 ( & V_73 , 1 ) ;
F_86 ( V_66 , & V_80 , V_82 ) ;
F_84 ( & V_72 , V_79 ) ;
F_18 ( V_83 ) ;
}
void F_91 ( void )
{
F_92 ( V_66 ) ;
}
void F_93 ( void )
{
F_89 ( 1 * V_84 ) ;
}
static void F_94 ( struct V_85 * V_86 , struct V_85 * V_87 , int V_88 )
{
struct V_1 V_89 ;
struct V_12 * V_13 ;
if ( V_88 ) {
F_87 () ;
return;
}
F_95 ( 2 , L_13
L_14 ,
V_86 -> V_90 , V_86 -> V_91 , V_86 -> V_92 , V_86 -> V_93 , V_86 -> V_94 ,
V_86 -> V_95 , V_86 -> V_96 ) ;
if ( V_87 )
F_95 ( 2 , L_15
L_14 ,
V_87 -> V_90 , V_87 -> V_91 , V_87 -> V_92 , V_87 -> V_93 ,
V_87 -> V_94 , V_87 -> V_95 , V_87 -> V_96 ) ;
F_3 ( & V_89 ) ;
V_89 . V_6 = V_86 -> V_96 ;
if ( V_87 )
V_89 . V_8 = ( V_87 -> V_96 >> 4 ) & 3 ;
if ( V_86 -> V_95 == V_97 ) {
V_13 = F_10 ( V_89 ) ;
if ( V_13 ) {
F_45 ( V_13 ) ;
F_11 ( & V_13 -> V_11 ) ;
}
}
F_64 ( V_89 , 0 ) ;
}
static void T_2
F_96 ( struct V_98 * V_99 , T_3 V_100 )
{
struct V_101 V_102 ;
if ( V_103 . V_104 ) {
V_99 -> V_105 . V_106 . V_107 . V_108 = 0x80 ;
V_99 -> V_105 . V_106 . V_107 . V_109 = V_99 -> V_109 ;
} else {
#ifdef F_97
V_99 -> V_105 . V_106 . V_110 = F_98 () ;
#else
V_99 -> V_105 . V_106 . V_110 = 0 ;
#endif
}
F_99 ( & V_102 ) ;
V_99 -> V_105 . V_102 = V_102 . V_111 ;
V_99 -> V_105 . V_112 = V_102 . V_113 ;
V_99 -> V_105 . V_100 = V_100 ;
}
static void
F_100 ( struct V_10 * V_11 )
{
struct V_98 * V_99 ;
V_99 = F_101 ( V_11 ) ;
F_102 ( & V_99 -> V_114 ) ;
if ( V_99 -> V_115 ) {
F_23 ( & V_99 -> V_115 -> V_11 ) ;
V_99 -> V_115 = NULL ;
}
F_25 ( V_99 ) ;
}
static T_1
F_103 ( struct V_10 * V_11 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_98 * V_99 = F_101 ( V_11 ) ;
int V_4 ;
if ( ! V_99 )
return 0 ;
F_33 ( & V_99 -> V_114 ) ;
V_4 = sprintf ( V_46 , L_16 , V_99 -> V_116 ) ;
F_36 ( & V_99 -> V_114 ) ;
return V_4 ;
}
static T_1
F_104 ( struct V_10 * V_11 , struct V_44 * V_45 ,
const char * V_46 , T_4 V_117 )
{
struct V_98 * V_99 = F_101 ( V_11 ) ;
int V_4 ;
unsigned long V_118 ;
V_4 = F_105 ( V_46 , 16 , & V_118 ) ;
if ( V_4 )
return V_4 ;
F_33 ( & V_99 -> V_114 ) ;
switch ( V_118 ) {
case 0 :
V_4 = V_99 -> V_116 ? F_106 ( V_99 , 0 ) : 0 ;
break;
case 1 :
V_4 = V_99 -> V_116 ? 0 : F_106 ( V_99 , 1 ) ;
break;
default:
V_4 = - V_119 ;
}
F_36 ( & V_99 -> V_114 ) ;
return V_4 < 0 ? V_4 : V_117 ;
}
static int T_2 F_107 ( int V_120 )
{
T_3 V_100 ;
int V_4 ;
struct V_98 * V_99 ;
V_99 = V_49 [ V_120 ] ;
memset ( V_99 , 0 , sizeof( struct V_98 ) ) ;
V_99 -> V_115 =
F_27 ( sizeof( * V_99 -> V_115 ) , V_23 ) ;
if ( ! V_99 -> V_115 )
return - V_24 ;
V_99 -> V_115 -> V_11 . V_48 = & V_99 -> V_10 ;
V_99 -> V_115 -> V_11 . V_32 = F_23 ;
F_34 ( & V_99 -> V_115 -> V_11 , L_17 ) ;
F_22 ( & V_99 -> V_115 -> V_25 ) ;
V_4 = F_19 ( V_99 -> V_115 ) ;
if ( V_4 ) {
F_25 ( V_99 -> V_115 ) ;
return V_4 ;
}
F_22 ( & V_99 -> V_114 ) ;
V_99 -> V_121 = 1 ;
V_99 -> V_109 = V_120 ;
F_34 ( & V_99 -> V_10 , L_18 , V_120 ) ;
V_99 -> V_10 . V_32 = F_100 ;
V_100 = ( T_3 ) ( F_108 () >> 32 ) ;
F_96 ( V_99 , V_100 ) ;
return 0 ;
}
static int F_109 ( struct V_122 * V_123 ,
unsigned long V_124 ,
void * V_125 )
{
int V_4 , V_36 ;
V_4 = V_126 ;
for ( V_36 = 0 ; V_36 <= V_127 ; V_36 ++ ) {
struct V_98 * V_99 ;
V_99 = V_49 [ V_36 ] ;
F_33 ( & V_99 -> V_114 ) ;
if ( V_99 -> V_116 )
if ( F_106 ( V_99 , 0 ) )
V_4 = V_128 ;
F_36 ( & V_99 -> V_114 ) ;
}
return V_4 ;
}
static int F_110 ( struct V_122 * V_123 , unsigned long V_124 ,
void * V_125 )
{
int V_4 , V_36 ;
switch ( V_124 ) {
case V_129 :
case V_130 :
V_4 = V_126 ;
for ( V_36 = 0 ; V_36 <= V_127 ; V_36 ++ ) {
struct V_98 * V_99 ;
V_99 = V_49 [ V_36 ] ;
F_33 ( & V_99 -> V_114 ) ;
if ( ! V_99 -> V_116 ) {
F_36 ( & V_99 -> V_114 ) ;
continue;
}
V_4 = F_111 ( V_99 , 0 ) ;
V_4 = F_112 ( V_4 ) ;
F_36 ( & V_99 -> V_114 ) ;
}
break;
case V_131 :
case V_132 :
V_4 = V_126 ;
for ( V_36 = 0 ; V_36 <= V_127 ; V_36 ++ ) {
struct V_98 * V_99 ;
V_99 = V_49 [ V_36 ] ;
F_33 ( & V_99 -> V_114 ) ;
if ( ! V_99 -> V_116 ) {
F_36 ( & V_99 -> V_114 ) ;
continue;
}
V_4 = F_111 ( V_99 , 1 ) ;
V_4 = F_112 ( V_4 ) ;
F_36 ( & V_99 -> V_114 ) ;
}
F_93 () ;
break;
default:
V_4 = V_126 ;
}
return V_4 ;
}
static int T_2 F_113 ( void )
{
int V_4 , V_36 ;
V_4 = F_114 () ;
if ( V_4 )
return V_4 ;
F_115 () ;
V_4 = F_116 ( V_133 ) ;
if ( V_4 )
V_9 = 0 ;
else
V_9 = V_134 ;
V_4 = F_72 () ;
if ( V_4 )
goto V_21;
V_4 = F_117 ( V_135 , F_94 ) ;
if ( V_4 )
goto V_21;
if ( ( V_4 = F_118 ( & V_20 ) ) )
goto V_21;
for ( V_36 = 0 ; V_36 <= V_127 ; V_36 ++ ) {
struct V_98 * V_99 ;
V_99 = F_20 ( sizeof( struct V_98 ) , V_23 ) ;
if ( ! V_99 ) {
V_4 = - V_24 ;
goto V_136;
}
V_49 [ V_36 ] = V_99 ;
V_4 = F_107 ( V_36 ) ;
if ( V_4 ) {
F_25 ( V_49 [ V_36 ] ) ;
goto V_136;
}
V_4 = F_119 ( & V_99 -> V_10 ) ;
if ( V_4 ) {
F_11 ( & V_99 -> V_10 ) ;
goto V_136;
}
if ( V_137 . V_138 ) {
V_4 = F_120 ( & V_99 -> V_10 ,
& V_139 ) ;
if ( V_4 )
goto V_140;
}
V_4 = F_119 ( & V_99 -> V_115 -> V_11 ) ;
if ( V_4 ) {
F_11 ( & V_99 -> V_115 -> V_11 ) ;
goto V_141;
}
}
V_4 = F_121 ( & V_142 ) ;
if ( V_4 )
goto V_136;
V_4 = F_122 ( & V_143 ) ;
if ( V_4 ) {
F_123 ( & V_142 ) ;
goto V_136;
}
V_144 = 1 ;
F_124 ( V_145 ) ;
return 0 ;
V_141:
if ( V_137 . V_138 )
F_125 ( & V_49 [ V_36 ] -> V_10 ,
& V_139 ) ;
V_140:
F_39 ( & V_49 [ V_36 ] -> V_10 ) ;
V_136:
while ( V_36 > 0 ) {
struct V_98 * V_99 ;
V_36 -- ;
V_99 = V_49 [ V_36 ] ;
F_39 ( & V_99 -> V_115 -> V_11 ) ;
V_99 -> V_115 = NULL ;
if ( V_137 . V_138 )
F_125 ( & V_99 -> V_10 ,
& V_139 ) ;
F_39 ( & V_99 -> V_10 ) ;
}
F_126 ( & V_20 ) ;
V_21:
F_127 ( V_135 ) ;
F_18 ( V_75 ) ;
F_128 () ;
F_129 ( L_19
L_20 , V_4 ) ;
return V_4 ;
}
static void T_2 F_130 ( void )
{
struct V_98 * V_99 ;
int V_36 ;
for ( V_36 = 0 ; V_36 <= V_127 ; V_36 ++ ) {
V_99 = V_49 [ V_36 ] ;
F_39 ( & V_99 -> V_115 -> V_11 ) ;
V_99 -> V_115 = NULL ;
if ( V_137 . V_138 )
F_125 ( & V_99 -> V_10 , & V_139 ) ;
F_39 ( & V_99 -> V_10 ) ;
}
F_126 ( & V_20 ) ;
F_127 ( V_135 ) ;
F_18 ( V_75 ) ;
F_128 () ;
F_131 ( V_145 ) ;
}
static int T_2 F_132 ( void )
{
int V_4 ;
V_4 = F_113 () ;
if ( V_4 )
return V_4 ;
V_66 = F_133 ( L_21 ) ;
if ( ! V_66 ) {
V_4 = - V_24 ;
goto V_146;
}
V_4 = F_134 () ;
if ( V_4 )
goto V_147;
return V_4 ;
V_147:
F_135 ( V_66 ) ;
V_146:
F_130 () ;
return V_4 ;
}
static int F_136 ( struct V_148 * V_149 , void * V_78 )
{
struct V_150 * V_151 = F_137 ( V_149 ) ;
if ( V_151 -> V_152 )
return V_151 -> V_152 () ;
return 0 ;
}
int F_138 ( void )
{
int V_4 ;
V_4 = F_139 ( V_74 ,
F_140 ( & V_73 ) == 0 ) ;
if ( V_4 )
return - V_153 ;
F_92 ( V_66 ) ;
return F_141 ( & V_20 , NULL , NULL , F_136 ) ;
}
static int T_2 F_142 ( void )
{
F_143 () ;
F_87 () ;
F_138 () ;
return 0 ;
}
void F_144 ( void )
{
struct V_154 * V_155 ;
struct V_156 V_40 ;
F_116 ( V_133 ) ;
F_145 (&chpid) {
V_155 = F_146 ( V_40 ) ;
if ( V_155 )
F_147 ( V_155 ) ;
}
}
static T_1 F_148 ( struct V_157 * V_157 , const char T_5 * V_46 ,
T_4 V_117 , T_6 * V_158 )
{
int V_4 ;
F_149 () ;
V_4 = F_138 () ;
return V_4 ? V_4 : V_117 ;
}
static int T_2 F_150 ( void )
{
struct V_159 * V_160 ;
V_160 = F_151 ( L_22 , V_161 , NULL ,
& V_162 ) ;
if ( ! V_160 )
return - V_24 ;
return 0 ;
}
int F_152 ( struct V_12 * V_13 )
{
return V_13 == F_101 ( V_13 -> V_11 . V_48 ) -> V_115 ;
}
static int F_153 ( struct V_10 * V_11 , struct V_148 * V_149 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_150 * V_53 = F_137 ( V_149 ) ;
struct V_163 * V_41 ;
for ( V_41 = V_53 -> V_164 ; V_41 -> V_165 ; V_41 ++ ) {
if ( V_13 -> V_47 == V_41 -> type )
return 1 ;
}
return 0 ;
}
static int F_154 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_5 ( V_11 ) ;
V_13 -> V_53 = F_137 ( V_11 -> V_53 ) ;
V_4 = V_13 -> V_53 -> V_166 ? V_13 -> V_53 -> V_166 ( V_13 ) : 0 ;
if ( V_4 )
V_13 -> V_53 = NULL ;
return V_4 ;
}
static int F_155 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_5 ( V_11 ) ;
V_4 = V_13 -> V_53 -> remove ? V_13 -> V_53 -> remove ( V_13 ) : 0 ;
V_13 -> V_53 = NULL ;
return V_4 ;
}
static void F_156 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_53 && V_13 -> V_53 -> V_167 )
V_13 -> V_53 -> V_167 ( V_13 ) ;
}
static int F_157 ( struct V_10 * V_11 , struct V_168 * V_169 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_4 ;
V_4 = F_158 ( V_169 , L_23 , V_13 -> V_47 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_158 ( V_169 , L_24 , V_13 -> V_47 ) ;
return V_4 ;
}
static int F_159 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_150 * V_149 ;
if ( F_160 ( & V_13 -> V_25 ) )
return - V_61 ;
if ( ! V_13 -> V_11 . V_53 )
return 0 ;
V_149 = F_137 ( V_13 -> V_11 . V_53 ) ;
return V_149 -> V_170 ? V_149 -> V_170 ( V_13 ) : 0 ;
}
static void F_161 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_150 * V_149 ;
if ( ! V_13 -> V_11 . V_53 )
return;
V_149 = F_137 ( V_13 -> V_11 . V_53 ) ;
if ( V_149 -> V_171 )
V_149 -> V_171 ( V_13 ) ;
}
static int F_162 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_150 * V_149 ;
if ( ! V_13 -> V_11 . V_53 )
return 0 ;
V_149 = F_137 ( V_13 -> V_11 . V_53 ) ;
return V_149 -> V_172 ? V_149 -> V_172 ( V_13 ) : 0 ;
}
static int F_163 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_150 * V_149 ;
if ( ! V_13 -> V_11 . V_53 )
return 0 ;
V_149 = F_137 ( V_13 -> V_11 . V_53 ) ;
return V_149 -> V_173 ? V_149 -> V_173 ( V_13 ) : 0 ;
}
static int F_164 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_150 * V_149 ;
F_45 ( V_13 ) ;
if ( ! V_13 -> V_11 . V_53 )
return 0 ;
V_149 = F_137 ( V_13 -> V_11 . V_53 ) ;
return V_149 -> V_174 ? V_149 -> V_174 ( V_13 ) : 0 ;
}
int F_165 ( struct V_150 * V_175 )
{
V_175 -> V_149 . V_50 = & V_20 ;
return F_166 ( & V_175 -> V_149 ) ;
}
void F_167 ( struct V_150 * V_175 )
{
F_168 ( & V_175 -> V_149 ) ;
}
