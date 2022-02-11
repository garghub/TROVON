int
F_1 ( int (* F_2)( struct V_1 , void * ) , void * V_2 )
{
struct V_1 V_3 ;
int V_4 ;
F_3 ( & V_3 ) ;
do {
do {
V_4 = F_2 ( V_3 , V_2 ) ;
if ( V_4 )
break;
} while ( V_3 . V_5 ++ < V_6 );
V_3 . V_5 = 0 ;
} while ( V_3 . V_7 ++ < V_8 );
return V_4 ;
}
static int F_4 ( struct V_9 * V_10 , void * V_2 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_13 * V_14 = V_2 ;
int V_15 = 0 ;
if ( V_14 -> V_16 )
F_6 ( V_14 -> V_16 , V_12 -> V_3 ) ;
if ( V_14 -> V_17 )
V_15 = V_14 -> V_17 ( V_12 , V_14 -> V_2 ) ;
return V_15 ;
}
static int F_7 ( struct V_1 V_3 , void * V_2 )
{
struct V_13 * V_14 = V_2 ;
int V_15 = 0 ;
if ( F_8 ( V_14 -> V_16 , V_3 ) )
V_15 = V_14 -> V_18 ( V_3 , V_14 -> V_2 ) ;
return V_15 ;
}
static int F_9 ( struct V_1 V_3 , void * V_2 )
{
struct V_13 * V_14 = V_2 ;
struct V_11 * V_12 ;
int V_15 = 0 ;
V_12 = F_10 ( V_3 ) ;
if ( V_12 ) {
if ( V_14 -> V_17 )
V_15 = V_14 -> V_17 ( V_12 , V_14 -> V_2 ) ;
F_11 ( & V_12 -> V_10 ) ;
} else {
if ( V_14 -> V_18 )
V_15 = V_14 -> V_18 ( V_3 , V_14 -> V_2 ) ;
}
return V_15 ;
}
int F_12 ( int (* F_13)( struct V_11 * , void * ) ,
int (* F_14)( struct V_1 ,
void * ) , void * V_2 )
{
struct V_13 V_14 ;
int V_15 ;
V_14 . V_2 = V_2 ;
V_14 . V_17 = F_13 ;
V_14 . V_18 = F_14 ;
if ( F_13 && ! F_14 ) {
V_14 . V_16 = NULL ;
return F_15 ( & V_19 , NULL , & V_14 ,
F_4 ) ;
}
V_14 . V_16 = F_16 () ;
if ( ! V_14 . V_16 )
return F_1 ( F_9 , & V_14 ) ;
F_17 ( V_14 . V_16 ) ;
V_15 = F_15 ( & V_19 , NULL , & V_14 , F_4 ) ;
if ( V_15 )
goto V_20;
if ( F_14 )
V_15 = F_1 ( F_7 , & V_14 ) ;
V_20:
F_18 ( V_14 . V_16 ) ;
return V_15 ;
}
static int F_19 ( struct V_11 * V_12 )
{
V_12 -> V_21 = F_20 ( sizeof( * V_12 -> V_21 ) , V_22 ) ;
if ( ! V_12 -> V_21 )
return - V_23 ;
F_21 ( V_12 -> V_21 ) ;
F_22 ( & V_12 -> V_24 ) ;
return 0 ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
V_12 -> V_25 . V_26 = 0 ;
F_24 ( V_12 ) ;
F_25 ( V_12 -> V_21 ) ;
F_25 ( V_12 ) ;
}
struct V_11 * F_26 ( struct V_1 V_3 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_22 | V_27 ) ;
if ( ! V_12 )
return F_28 ( - V_23 ) ;
V_4 = F_29 ( V_12 , V_3 ) ;
if ( V_4 < 0 )
goto V_28;
V_4 = F_19 ( V_12 ) ;
if ( V_4 )
goto V_28;
F_30 ( & V_12 -> V_29 , V_30 ) ;
V_12 -> V_10 . V_31 = & F_23 ;
F_31 ( & V_12 -> V_10 ) ;
return V_12 ;
V_28:
F_25 ( V_12 ) ;
return F_28 ( V_4 ) ;
}
static int F_32 ( struct V_11 * V_12 )
{
int V_4 ;
F_33 ( & V_12 -> V_24 ) ;
F_34 ( & V_12 -> V_10 , L_1 , V_12 -> V_3 . V_7 ,
V_12 -> V_3 . V_5 ) ;
V_4 = F_35 ( & V_12 -> V_10 ) ;
F_36 ( & V_12 -> V_24 ) ;
return V_4 ;
}
void F_37 ( struct V_11 * V_12 )
{
F_33 ( & V_12 -> V_24 ) ;
if ( F_38 ( & V_12 -> V_10 ) )
F_39 ( & V_12 -> V_10 ) ;
F_36 ( & V_12 -> V_24 ) ;
}
static void F_40 ( struct V_32 * V_33 , struct V_34 * V_34 )
{
int V_35 ;
int V_36 ;
memset ( V_33 , 0 , sizeof( struct V_32 ) ) ;
V_33 -> V_37 = V_34 -> V_38 ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_36 = 0x80 >> V_35 ;
if ( V_34 -> V_38 & V_36 ) {
F_41 ( & V_33 -> V_39 [ V_35 ] ) ;
V_33 -> V_39 [ V_35 ] . V_40 = V_34 -> V_39 [ V_35 ] ;
}
}
}
static void F_42 ( struct V_32 * V_33 )
{
int V_35 ;
int V_36 ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_36 = 0x80 >> V_35 ;
if ( V_33 -> V_37 & V_36 )
if ( ! F_43 ( V_33 -> V_39 [ V_35 ] ) )
F_44 ( V_33 -> V_39 [ V_35 ] ) ;
}
}
void F_45 ( struct V_11 * V_12 )
{
int V_4 ;
V_4 = F_46 ( V_12 -> V_3 , & V_12 -> V_41 ) ;
if ( V_4 )
F_40 ( & V_12 -> V_41 , & V_12 -> V_42 . V_34 ) ;
F_42 ( & V_12 -> V_41 ) ;
}
static T_1 F_47 ( struct V_9 * V_10 , struct V_43 * V_44 ,
char * V_45 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return sprintf ( V_45 , L_2 , V_12 -> V_46 ) ;
}
static T_1 F_48 ( struct V_9 * V_10 , struct V_43 * V_44 ,
char * V_45 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return sprintf ( V_45 , L_3 , V_12 -> V_46 ) ;
}
int F_49 ( struct V_11 * V_12 )
{
int V_4 ;
V_12 -> V_10 . V_47 = & V_48 [ 0 ] -> V_9 ;
V_12 -> V_10 . V_49 = & V_19 ;
V_12 -> V_10 . V_50 = V_51 ;
F_50 ( & V_12 -> V_10 , 1 ) ;
F_45 ( V_12 ) ;
V_4 = F_32 ( V_12 ) ;
if ( V_4 ) {
F_51 ( 0 , L_4 ,
V_12 -> V_3 . V_7 , V_12 -> V_3 . V_5 , V_4 ) ;
return V_4 ;
}
if ( ! V_12 -> V_52 ) {
F_50 ( & V_12 -> V_10 , 0 ) ;
F_52 ( & V_12 -> V_10 . V_53 , V_54 ) ;
}
return V_4 ;
}
static int F_53 ( struct V_1 V_3 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_26 ( V_3 ) ;
if ( F_54 ( V_12 ) )
return F_55 ( V_12 ) ;
V_4 = F_49 ( V_12 ) ;
if ( V_4 )
F_11 ( & V_12 -> V_10 ) ;
return V_4 ;
}
static int
F_56 ( struct V_9 * V_10 , void * V_2 )
{
struct V_11 * V_12 ;
struct V_1 * V_3 = V_2 ;
V_12 = F_5 ( V_10 ) ;
return F_57 ( & V_12 -> V_3 , V_3 ) ;
}
struct V_11 *
F_10 ( struct V_1 V_3 )
{
struct V_9 * V_10 ;
V_10 = F_58 ( & V_19 , NULL ,
& V_3 , F_56 ) ;
return V_10 ? F_5 ( V_10 ) : NULL ;
}
int F_59 ( struct V_42 * V_42 )
{
if ( ( V_42 -> V_34 . V_46 == V_55 ) && ! V_42 -> V_34 . V_56 )
return 0 ;
if ( ( V_42 -> V_34 . V_46 == V_57 ) && ! V_42 -> V_34 . V_58 )
return 0 ;
return 1 ;
}
static int F_60 ( struct V_1 V_3 , int V_59 )
{
struct V_42 V_42 ;
if ( ! V_59 ) {
return - V_60 ;
}
if ( F_61 ( V_3 , & V_42 ) ) {
return - V_61 ;
}
if ( ! F_59 ( & V_42 ) ) {
return 0 ;
}
F_51 ( 4 , L_5 , V_3 . V_7 ,
V_3 . V_5 ) ;
return F_53 ( V_3 ) ;
}
static int F_62 ( struct V_11 * V_12 , int V_59 )
{
int V_4 = 0 ;
if ( V_12 -> V_52 ) {
if ( V_12 -> V_52 -> V_62 )
V_4 = V_12 -> V_52 -> V_62 ( V_12 , V_59 ) ;
else
F_63 ( & V_12 -> V_10 ,
L_6
L_7 ) ;
}
if ( V_4 != 0 && V_4 != - V_60 ) {
F_51 ( 2 , L_8 ,
V_12 -> V_3 . V_7 , V_12 -> V_3 . V_5 , V_4 ) ;
}
return V_4 ;
}
static void F_64 ( struct V_1 V_3 , int V_59 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_10 ( V_3 ) ;
if ( V_12 ) {
V_4 = F_62 ( V_12 , V_59 ) ;
F_11 ( & V_12 -> V_10 ) ;
} else
V_4 = F_60 ( V_3 , V_59 ) ;
if ( V_4 == - V_60 )
F_65 ( V_3 ) ;
}
void F_66 ( struct V_11 * V_12 , enum V_63 V_64 )
{
F_51 ( 4 , L_9 ,
V_12 -> V_3 . V_7 , V_12 -> V_3 . V_5 , V_64 ) ;
if ( V_12 -> V_64 >= V_64 )
return;
if ( ! F_67 ( & V_12 -> V_10 ) )
return;
V_12 -> V_64 = V_64 ;
if ( ! F_68 ( V_65 , & V_12 -> V_29 ) ) {
F_11 ( & V_12 -> V_10 ) ;
}
}
static void V_30 ( struct V_66 * V_67 )
{
struct V_11 * V_12 ;
enum V_63 V_64 ;
int V_4 ;
V_12 = F_69 ( V_67 , struct V_11 , V_29 ) ;
F_70 ( V_12 -> V_21 ) ;
V_64 = V_12 -> V_64 ;
F_51 ( 4 , L_10 , V_12 -> V_3 . V_7 ,
V_12 -> V_3 . V_5 , V_64 ) ;
V_12 -> V_64 = V_68 ;
F_71 ( V_12 -> V_21 ) ;
switch ( V_64 ) {
case V_68 :
break;
case V_69 :
V_4 = F_62 ( V_12 , 1 ) ;
if ( V_4 == - V_60 ) {
F_70 ( V_12 -> V_21 ) ;
F_66 ( V_12 , V_64 ) ;
F_71 ( V_12 -> V_21 ) ;
}
break;
case V_70 :
F_37 ( V_12 ) ;
break;
}
F_11 ( & V_12 -> V_10 ) ;
}
static int T_2 F_72 ( void )
{
F_21 ( & V_71 ) ;
F_73 ( & V_72 , 0 ) ;
F_74 ( & V_73 ) ;
V_74 = F_16 () ;
if ( ! V_74 ) {
F_51 ( 0 , L_11 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_75 ( struct V_11 * V_12 , void * V_2 )
{
int V_75 ;
int V_15 ;
F_70 ( & V_71 ) ;
V_75 = F_8 ( V_74 , V_12 -> V_3 ) ;
F_6 ( V_74 , V_12 -> V_3 ) ;
F_71 ( & V_71 ) ;
if ( V_75 ) {
V_15 = F_62 ( V_12 , 1 ) ;
if ( V_15 == - V_60 )
F_65 ( V_12 -> V_3 ) ;
}
return 0 ;
}
static int F_76 ( struct V_1 V_3 , void * V_2 )
{
int V_75 ;
int V_15 = 0 ;
F_70 ( & V_71 ) ;
V_75 = F_8 ( V_74 , V_3 ) ;
F_6 ( V_74 , V_3 ) ;
F_71 ( & V_71 ) ;
if ( V_75 ) {
V_15 = F_60 ( V_3 , 1 ) ;
switch ( V_15 ) {
case - V_60 :
F_65 ( V_3 ) ;
V_15 = 0 ;
break;
case - V_61 :
case - V_23 :
case - V_76 :
F_70 ( & V_71 ) ;
F_77 ( V_74 , V_3 ) ;
F_71 ( & V_71 ) ;
break;
default:
V_15 = 0 ;
}
F_78 () ;
}
return V_15 ;
}
static void F_79 ( struct V_66 * V_77 )
{
unsigned long V_78 ;
F_80 ( 4 , L_12 ) ;
F_12 ( F_75 , F_76 ,
NULL ) ;
F_81 ( & V_71 , V_78 ) ;
if ( F_82 ( V_74 ) ) {
F_73 ( & V_72 , 0 ) ;
F_83 ( & V_73 ) ;
}
F_84 ( & V_71 , V_78 ) ;
}
void F_65 ( struct V_1 V_3 )
{
unsigned long V_78 ;
F_81 ( & V_71 , V_78 ) ;
F_85 ( V_74 , V_3 ) ;
F_73 ( & V_72 , 1 ) ;
F_86 ( V_65 , & V_79 , 0 ) ;
F_84 ( & V_71 , V_78 ) ;
}
void F_87 ( void )
{
unsigned long V_78 ;
F_81 ( & V_71 , V_78 ) ;
F_17 ( V_74 ) ;
F_73 ( & V_72 , 1 ) ;
F_86 ( V_65 , & V_79 , 0 ) ;
F_84 ( & V_71 , V_78 ) ;
}
static int F_88 ( struct V_9 * V_10 , void * V_2 )
{
struct V_80 * V_16 = V_2 ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_6 ( V_16 , V_12 -> V_3 ) ;
return 0 ;
}
void F_89 ( unsigned long V_81 )
{
unsigned long V_78 ;
struct V_80 * V_82 ;
V_82 = F_16 () ;
if ( ! V_82 ) {
F_87 () ;
return;
}
F_17 ( V_82 ) ;
F_15 ( & V_19 , NULL , V_82 , F_88 ) ;
F_81 ( & V_71 , V_78 ) ;
F_90 ( V_74 , V_82 ) ;
F_73 ( & V_72 , 1 ) ;
F_86 ( V_65 , & V_79 , V_81 ) ;
F_84 ( & V_71 , V_78 ) ;
F_18 ( V_82 ) ;
}
void F_91 ( void )
{
F_92 ( V_65 ) ;
}
void F_93 ( void )
{
F_89 ( 1 * V_83 ) ;
}
static void F_94 ( struct V_84 * V_85 , struct V_84 * V_86 , int V_87 )
{
struct V_1 V_88 ;
struct V_11 * V_12 ;
if ( V_87 ) {
F_87 () ;
return;
}
F_95 ( 2 , L_13
L_14 ,
V_85 -> V_89 , V_85 -> V_90 , V_85 -> V_91 , V_85 -> V_92 , V_85 -> V_93 ,
V_85 -> V_94 , V_85 -> V_95 ) ;
if ( V_86 )
F_95 ( 2 , L_15
L_14 ,
V_86 -> V_89 , V_86 -> V_90 , V_86 -> V_91 , V_86 -> V_92 ,
V_86 -> V_93 , V_86 -> V_94 , V_86 -> V_95 ) ;
F_3 ( & V_88 ) ;
V_88 . V_5 = V_85 -> V_95 ;
if ( V_86 )
V_88 . V_7 = ( V_86 -> V_95 >> 4 ) & 3 ;
if ( V_85 -> V_94 == V_96 ) {
V_12 = F_10 ( V_88 ) ;
if ( V_12 ) {
F_45 ( V_12 ) ;
F_11 ( & V_12 -> V_10 ) ;
}
}
F_64 ( V_88 , 0 ) ;
}
static void T_2
F_96 ( struct V_97 * V_98 , T_3 V_99 )
{
struct V_100 V_101 ;
if ( V_102 . V_103 ) {
V_98 -> V_104 . V_105 . V_106 . V_107 = 0x80 ;
V_98 -> V_104 . V_105 . V_106 . V_108 = V_98 -> V_108 ;
} else {
V_98 -> V_104 . V_105 . V_109 = F_97 () ;
}
F_98 ( & V_101 ) ;
V_98 -> V_104 . V_101 = V_101 . V_110 ;
V_98 -> V_104 . V_111 = V_101 . V_112 ;
V_98 -> V_104 . V_99 = V_99 ;
}
static void
F_99 ( struct V_9 * V_10 )
{
struct V_97 * V_98 ;
V_98 = F_100 ( V_10 ) ;
F_101 ( & V_98 -> V_113 ) ;
if ( V_98 -> V_114 ) {
F_23 ( & V_98 -> V_114 -> V_10 ) ;
V_98 -> V_114 = NULL ;
}
F_25 ( V_98 ) ;
}
static T_1
F_102 ( struct V_9 * V_10 , struct V_43 * V_44 ,
char * V_45 )
{
struct V_97 * V_98 = F_100 ( V_10 ) ;
int V_4 ;
if ( ! V_98 )
return 0 ;
F_33 ( & V_98 -> V_113 ) ;
V_4 = sprintf ( V_45 , L_16 , V_98 -> V_115 ) ;
F_36 ( & V_98 -> V_113 ) ;
return V_4 ;
}
static T_1
F_103 ( struct V_9 * V_10 , struct V_43 * V_44 ,
const char * V_45 , T_4 V_116 )
{
struct V_97 * V_98 = F_100 ( V_10 ) ;
int V_4 ;
unsigned long V_117 ;
V_4 = F_104 ( V_45 , 16 , & V_117 ) ;
if ( V_4 )
return V_4 ;
F_33 ( & V_98 -> V_113 ) ;
switch ( V_117 ) {
case 0 :
V_4 = V_98 -> V_115 ? F_105 ( V_98 , 0 ) : 0 ;
break;
case 1 :
V_4 = V_98 -> V_115 ? 0 : F_105 ( V_98 , 1 ) ;
break;
default:
V_4 = - V_118 ;
}
F_36 ( & V_98 -> V_113 ) ;
return V_4 < 0 ? V_4 : V_116 ;
}
static int T_2 F_106 ( int V_119 )
{
T_3 V_99 ;
int V_4 ;
struct V_97 * V_98 ;
V_98 = V_48 [ V_119 ] ;
memset ( V_98 , 0 , sizeof( struct V_97 ) ) ;
V_98 -> V_114 =
F_27 ( sizeof( * V_98 -> V_114 ) , V_22 ) ;
if ( ! V_98 -> V_114 )
return - V_23 ;
V_98 -> V_114 -> V_10 . V_47 = & V_98 -> V_9 ;
V_98 -> V_114 -> V_10 . V_31 = F_23 ;
F_34 ( & V_98 -> V_114 -> V_10 , L_17 ) ;
F_22 ( & V_98 -> V_114 -> V_24 ) ;
V_4 = F_19 ( V_98 -> V_114 ) ;
if ( V_4 ) {
F_25 ( V_98 -> V_114 ) ;
return V_4 ;
}
F_22 ( & V_98 -> V_113 ) ;
V_98 -> V_120 = 1 ;
V_98 -> V_108 = V_119 ;
F_34 ( & V_98 -> V_9 , L_18 , V_119 ) ;
V_98 -> V_9 . V_31 = F_99 ;
V_99 = ( T_3 ) ( F_107 () >> 32 ) ;
F_96 ( V_98 , V_99 ) ;
return 0 ;
}
static int F_108 ( struct V_121 * V_122 ,
unsigned long V_123 ,
void * V_124 )
{
int V_4 , V_35 ;
V_4 = V_125 ;
for ( V_35 = 0 ; V_35 <= V_126 ; V_35 ++ ) {
struct V_97 * V_98 ;
V_98 = V_48 [ V_35 ] ;
F_33 ( & V_98 -> V_113 ) ;
if ( V_98 -> V_115 )
if ( F_105 ( V_98 , 0 ) )
V_4 = V_127 ;
F_36 ( & V_98 -> V_113 ) ;
}
return V_4 ;
}
static int F_109 ( struct V_121 * V_122 , unsigned long V_123 ,
void * V_124 )
{
int V_4 , V_35 ;
switch ( V_123 ) {
case V_128 :
case V_129 :
V_4 = V_125 ;
for ( V_35 = 0 ; V_35 <= V_126 ; V_35 ++ ) {
struct V_97 * V_98 ;
V_98 = V_48 [ V_35 ] ;
F_33 ( & V_98 -> V_113 ) ;
if ( ! V_98 -> V_115 ) {
F_36 ( & V_98 -> V_113 ) ;
continue;
}
V_4 = F_110 ( V_98 , 0 ) ;
V_4 = F_111 ( V_4 ) ;
F_36 ( & V_98 -> V_113 ) ;
}
break;
case V_130 :
case V_131 :
V_4 = V_125 ;
for ( V_35 = 0 ; V_35 <= V_126 ; V_35 ++ ) {
struct V_97 * V_98 ;
V_98 = V_48 [ V_35 ] ;
F_33 ( & V_98 -> V_113 ) ;
if ( ! V_98 -> V_115 ) {
F_36 ( & V_98 -> V_113 ) ;
continue;
}
V_4 = F_110 ( V_98 , 1 ) ;
V_4 = F_111 ( V_4 ) ;
F_36 ( & V_98 -> V_113 ) ;
}
F_93 () ;
break;
default:
V_4 = V_125 ;
}
return V_4 ;
}
static int T_2 F_112 ( void )
{
int V_4 , V_35 ;
V_4 = F_113 () ;
if ( V_4 )
return V_4 ;
F_114 () ;
V_4 = F_115 ( V_132 ) ;
if ( V_4 )
V_8 = 0 ;
else
V_8 = V_133 ;
V_4 = F_72 () ;
if ( V_4 )
goto V_20;
V_4 = F_116 ( V_134 , F_94 ) ;
if ( V_4 )
goto V_20;
if ( ( V_4 = F_117 ( & V_19 ) ) )
goto V_20;
for ( V_35 = 0 ; V_35 <= V_126 ; V_35 ++ ) {
struct V_97 * V_98 ;
V_98 = F_20 ( sizeof( struct V_97 ) , V_22 ) ;
if ( ! V_98 ) {
V_4 = - V_23 ;
goto V_135;
}
V_48 [ V_35 ] = V_98 ;
V_4 = F_106 ( V_35 ) ;
if ( V_4 ) {
F_25 ( V_48 [ V_35 ] ) ;
goto V_135;
}
V_4 = F_118 ( & V_98 -> V_9 ) ;
if ( V_4 ) {
F_11 ( & V_98 -> V_9 ) ;
goto V_135;
}
if ( V_136 . V_137 ) {
V_4 = F_119 ( & V_98 -> V_9 ,
& V_138 ) ;
if ( V_4 )
goto V_139;
}
V_4 = F_118 ( & V_98 -> V_114 -> V_10 ) ;
if ( V_4 ) {
F_11 ( & V_98 -> V_114 -> V_10 ) ;
goto V_140;
}
}
V_4 = F_120 ( & V_141 ) ;
if ( V_4 )
goto V_135;
V_4 = F_121 ( & V_142 ) ;
if ( V_4 ) {
F_122 ( & V_141 ) ;
goto V_135;
}
V_143 = 1 ;
F_123 ( V_144 ) ;
return 0 ;
V_140:
if ( V_136 . V_137 )
F_124 ( & V_48 [ V_35 ] -> V_9 ,
& V_138 ) ;
V_139:
F_39 ( & V_48 [ V_35 ] -> V_9 ) ;
V_135:
while ( V_35 > 0 ) {
struct V_97 * V_98 ;
V_35 -- ;
V_98 = V_48 [ V_35 ] ;
F_39 ( & V_98 -> V_114 -> V_10 ) ;
V_98 -> V_114 = NULL ;
if ( V_136 . V_137 )
F_124 ( & V_98 -> V_9 ,
& V_138 ) ;
F_39 ( & V_98 -> V_9 ) ;
}
F_125 ( & V_19 ) ;
V_20:
F_126 ( V_134 ) ;
F_18 ( V_74 ) ;
F_127 () ;
F_128 ( L_19
L_20 , V_4 ) ;
return V_4 ;
}
static void T_2 F_129 ( void )
{
struct V_97 * V_98 ;
int V_35 ;
for ( V_35 = 0 ; V_35 <= V_126 ; V_35 ++ ) {
V_98 = V_48 [ V_35 ] ;
F_39 ( & V_98 -> V_114 -> V_10 ) ;
V_98 -> V_114 = NULL ;
if ( V_136 . V_137 )
F_124 ( & V_98 -> V_9 , & V_138 ) ;
F_39 ( & V_98 -> V_9 ) ;
}
F_125 ( & V_19 ) ;
F_126 ( V_134 ) ;
F_18 ( V_74 ) ;
F_127 () ;
F_130 ( V_144 ) ;
}
static int T_2 F_131 ( void )
{
int V_4 ;
V_4 = F_112 () ;
if ( V_4 )
return V_4 ;
V_65 = F_132 ( L_21 ) ;
if ( ! V_65 ) {
V_4 = - V_23 ;
goto V_145;
}
V_4 = F_133 () ;
if ( V_4 )
goto V_146;
return V_4 ;
V_146:
F_134 ( V_65 ) ;
V_145:
F_129 () ;
return V_4 ;
}
static int F_135 ( struct V_147 * V_148 , void * V_77 )
{
struct V_149 * V_150 = F_136 ( V_148 ) ;
if ( V_150 -> V_151 )
return V_150 -> V_151 () ;
return 0 ;
}
int F_137 ( void )
{
int V_4 ;
V_4 = F_138 ( V_73 ,
F_139 ( & V_72 ) == 0 ) ;
if ( V_4 )
return - V_152 ;
F_92 ( V_65 ) ;
return F_140 ( & V_19 , NULL , NULL , F_135 ) ;
}
static int T_2 F_141 ( void )
{
F_142 () ;
F_87 () ;
F_137 () ;
return 0 ;
}
void F_143 ( void )
{
struct V_153 * V_154 ;
struct V_155 V_39 ;
F_115 ( V_132 ) ;
F_144 (&chpid) {
V_154 = F_145 ( V_39 ) ;
if ( V_154 )
F_146 ( V_154 ) ;
}
F_147 () ;
}
static T_1 F_148 ( struct V_156 * V_156 , const char T_5 * V_45 ,
T_4 V_116 , T_6 * V_157 )
{
int V_4 ;
F_149 () ;
V_4 = F_137 () ;
return V_4 ? V_4 : V_116 ;
}
static int T_2 F_150 ( void )
{
struct V_158 * V_159 ;
V_159 = F_151 ( L_22 , V_160 , NULL ,
& V_161 ) ;
if ( ! V_159 )
return - V_23 ;
return 0 ;
}
int F_152 ( struct V_11 * V_12 )
{
return V_12 == F_100 ( V_12 -> V_10 . V_47 ) -> V_114 ;
}
static int F_153 ( struct V_9 * V_10 , struct V_147 * V_148 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_149 * V_52 = F_136 ( V_148 ) ;
struct V_162 * V_40 ;
for ( V_40 = V_52 -> V_163 ; V_40 -> V_164 ; V_40 ++ ) {
if ( V_12 -> V_46 == V_40 -> type )
return 1 ;
}
return 0 ;
}
static int F_154 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_5 ( V_10 ) ;
V_12 -> V_52 = F_136 ( V_10 -> V_52 ) ;
V_4 = V_12 -> V_52 -> V_165 ? V_12 -> V_52 -> V_165 ( V_12 ) : 0 ;
if ( V_4 )
V_12 -> V_52 = NULL ;
return V_4 ;
}
static int F_155 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_5 ( V_10 ) ;
V_4 = V_12 -> V_52 -> remove ? V_12 -> V_52 -> remove ( V_12 ) : 0 ;
V_12 -> V_52 = NULL ;
return V_4 ;
}
static void F_156 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_52 && V_12 -> V_52 -> V_166 )
V_12 -> V_52 -> V_166 ( V_12 ) ;
}
static int F_157 ( struct V_9 * V_10 , struct V_167 * V_168 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_4 ;
V_4 = F_158 ( V_168 , L_23 , V_12 -> V_46 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_158 ( V_168 , L_24 , V_12 -> V_46 ) ;
return V_4 ;
}
static int F_159 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_149 * V_148 ;
if ( F_160 ( & V_12 -> V_24 ) )
return - V_60 ;
if ( ! V_12 -> V_10 . V_52 )
return 0 ;
V_148 = F_136 ( V_12 -> V_10 . V_52 ) ;
return V_148 -> V_169 ? V_148 -> V_169 ( V_12 ) : 0 ;
}
static void F_161 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_149 * V_148 ;
if ( ! V_12 -> V_10 . V_52 )
return;
V_148 = F_136 ( V_12 -> V_10 . V_52 ) ;
if ( V_148 -> V_170 )
V_148 -> V_170 ( V_12 ) ;
}
static int F_162 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_149 * V_148 ;
if ( ! V_12 -> V_10 . V_52 )
return 0 ;
V_148 = F_136 ( V_12 -> V_10 . V_52 ) ;
return V_148 -> V_171 ? V_148 -> V_171 ( V_12 ) : 0 ;
}
static int F_163 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_149 * V_148 ;
if ( ! V_12 -> V_10 . V_52 )
return 0 ;
V_148 = F_136 ( V_12 -> V_10 . V_52 ) ;
return V_148 -> V_172 ? V_148 -> V_172 ( V_12 ) : 0 ;
}
static int F_164 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_149 * V_148 ;
F_45 ( V_12 ) ;
if ( ! V_12 -> V_10 . V_52 )
return 0 ;
V_148 = F_136 ( V_12 -> V_10 . V_52 ) ;
return V_148 -> V_173 ? V_148 -> V_173 ( V_12 ) : 0 ;
}
int F_165 ( struct V_149 * V_174 )
{
V_174 -> V_148 . V_49 = & V_19 ;
return F_166 ( & V_174 -> V_148 ) ;
}
void F_167 ( struct V_149 * V_174 )
{
F_168 ( & V_174 -> V_148 ) ;
}
