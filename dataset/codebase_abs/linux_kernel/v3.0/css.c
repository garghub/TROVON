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
static void V_26 ( struct V_31 * V_32 )
{
struct V_12 * V_13 ;
enum V_33 V_34 ;
V_13 = F_36 ( V_32 , struct V_12 , V_25 ) ;
F_37 ( V_13 -> V_29 ) ;
V_34 = V_13 -> V_34 ;
F_38 ( 4 , L_2 , V_13 -> V_3 . V_8 ,
V_13 -> V_3 . V_6 , V_34 ) ;
V_13 -> V_34 = V_35 ;
F_39 ( V_13 -> V_29 ) ;
if ( V_34 == V_36 )
F_33 ( V_13 ) ;
F_11 ( & V_13 -> V_11 ) ;
}
void F_40 ( struct V_12 * V_13 , enum V_33 V_34 )
{
F_38 ( 4 , L_3 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_34 ) ;
if ( V_13 -> V_34 >= V_34 )
return;
if ( ! F_41 ( & V_13 -> V_11 ) )
return;
V_13 -> V_34 = V_34 ;
if ( ! F_42 ( V_37 , & V_13 -> V_25 ) ) {
F_11 ( & V_13 -> V_11 ) ;
}
}
static void F_43 ( struct V_38 * V_39 , struct V_40 * V_40 )
{
int V_41 ;
int V_42 ;
memset ( V_39 , 0 , sizeof( struct V_38 ) ) ;
V_39 -> V_43 = V_40 -> V_44 ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
V_42 = 0x80 >> V_41 ;
if ( V_40 -> V_44 & V_42 ) {
F_44 ( & V_39 -> V_45 [ V_41 ] ) ;
V_39 -> V_45 [ V_41 ] . V_46 = V_40 -> V_45 [ V_41 ] ;
}
}
}
static void F_45 ( struct V_38 * V_39 )
{
int V_41 ;
int V_42 ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
V_42 = 0x80 >> V_41 ;
if ( V_39 -> V_43 & V_42 )
if ( ! F_46 ( V_39 -> V_45 [ V_41 ] ) )
F_47 ( V_39 -> V_45 [ V_41 ] ) ;
}
}
void F_48 ( struct V_12 * V_13 )
{
int V_4 ;
if ( F_26 ( V_13 -> V_3 ) ) {
F_43 ( & V_13 -> V_47 , & V_13 -> V_48 . V_40 ) ;
} else {
V_4 = F_49 ( V_13 -> V_3 , & V_13 -> V_47 ) ;
if ( V_4 )
F_43 ( & V_13 -> V_47 , & V_13 -> V_48 . V_40 ) ;
F_45 ( & V_13 -> V_47 ) ;
}
}
static T_1 F_50 ( struct V_10 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return sprintf ( V_51 , L_4 , V_13 -> V_52 ) ;
}
static T_1 F_51 ( struct V_10 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
return sprintf ( V_51 , L_5 , V_13 -> V_52 ) ;
}
static int F_52 ( struct V_12 * V_13 )
{
int V_4 ;
V_13 -> V_11 . V_53 = & V_54 [ 0 ] -> V_10 ;
V_13 -> V_11 . V_55 = & V_20 ;
V_13 -> V_11 . V_56 = & F_25 ;
V_13 -> V_11 . V_57 = V_58 ;
F_53 ( & V_13 -> V_11 , 1 ) ;
F_48 ( V_13 ) ;
V_4 = F_28 ( V_13 ) ;
if ( V_4 ) {
F_38 ( 0 , L_6 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_4 ) ;
return V_4 ;
}
if ( ! V_13 -> V_59 ) {
F_53 ( & V_13 -> V_11 , 0 ) ;
F_54 ( & V_13 -> V_11 . V_60 , V_61 ) ;
}
return V_4 ;
}
int F_55 ( struct V_1 V_3 )
{
int V_4 ;
struct V_12 * V_13 ;
if ( F_26 ( V_3 ) )
V_13 = F_56 () ;
else {
V_13 = F_19 ( V_3 ) ;
if ( F_57 ( V_13 ) )
return F_58 ( V_13 ) ;
}
V_4 = F_52 ( V_13 ) ;
if ( V_4 ) {
if ( ! F_26 ( V_3 ) )
F_11 ( & V_13 -> V_11 ) ;
}
return V_4 ;
}
static int
F_59 ( struct V_10 * V_11 , void * V_2 )
{
struct V_12 * V_13 ;
struct V_1 * V_3 = V_2 ;
V_13 = F_5 ( V_11 ) ;
return F_60 ( & V_13 -> V_3 , V_3 ) ;
}
struct V_12 *
F_10 ( struct V_1 V_3 )
{
struct V_10 * V_11 ;
V_11 = F_61 ( & V_20 , NULL ,
& V_3 , F_59 ) ;
return V_11 ? F_5 ( V_11 ) : NULL ;
}
int F_62 ( struct V_48 * V_48 )
{
if ( ( V_48 -> V_40 . V_52 == V_62 ) && ! V_48 -> V_40 . V_63 )
return 0 ;
if ( ( V_48 -> V_40 . V_52 == V_64 ) && ! V_48 -> V_40 . V_65 )
return 0 ;
return 1 ;
}
static int F_63 ( struct V_1 V_3 , int V_66 )
{
struct V_48 V_48 ;
if ( ! V_66 ) {
return - V_67 ;
}
if ( F_64 ( V_3 , & V_48 ) || ! F_62 ( & V_48 ) ) {
return 0 ;
}
F_38 ( 4 , L_7 , V_3 . V_8 ,
V_3 . V_6 ) ;
return F_55 ( V_3 ) ;
}
static int F_65 ( struct V_12 * V_13 , int V_66 )
{
int V_4 = 0 ;
if ( V_13 -> V_59 ) {
if ( V_13 -> V_59 -> V_68 )
V_4 = V_13 -> V_59 -> V_68 ( V_13 , V_66 ) ;
else
F_66 ( & V_13 -> V_11 ,
L_8
L_9 ) ;
}
if ( V_4 != 0 && V_4 != - V_67 ) {
F_38 ( 2 , L_10 ,
V_13 -> V_3 . V_8 , V_13 -> V_3 . V_6 , V_4 ) ;
}
return V_4 ;
}
static void F_67 ( struct V_1 V_3 , int V_66 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_10 ( V_3 ) ;
if ( V_13 ) {
V_4 = F_65 ( V_13 , V_66 ) ;
F_11 ( & V_13 -> V_11 ) ;
} else
V_4 = F_63 ( V_3 , V_66 ) ;
if ( V_4 == - V_67 )
F_68 ( V_3 ) ;
}
static int T_2 F_69 ( void )
{
F_70 ( & V_69 ) ;
F_71 ( & V_70 , 0 ) ;
F_72 ( & V_71 ) ;
V_72 = F_15 () ;
if ( ! V_72 ) {
F_38 ( 0 , L_11 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_73 ( struct V_12 * V_13 , void * V_2 )
{
int V_73 ;
int V_16 ;
F_37 ( & V_69 ) ;
V_73 = F_8 ( V_72 , V_13 -> V_3 ) ;
F_6 ( V_72 , V_13 -> V_3 ) ;
F_39 ( & V_69 ) ;
if ( V_73 ) {
V_16 = F_65 ( V_13 , 1 ) ;
if ( V_16 == - V_67 )
F_68 ( V_13 -> V_3 ) ;
}
return 0 ;
}
static int F_74 ( struct V_1 V_3 , void * V_2 )
{
int V_73 ;
int V_16 = 0 ;
F_37 ( & V_69 ) ;
V_73 = F_8 ( V_72 , V_3 ) ;
F_6 ( V_72 , V_3 ) ;
F_39 ( & V_69 ) ;
if ( V_73 ) {
V_16 = F_63 ( V_3 , 1 ) ;
switch ( V_16 ) {
case - V_67 :
F_68 ( V_3 ) ;
V_16 = 0 ;
break;
case - V_74 :
case - V_24 :
case - V_75 :
break;
default:
V_16 = 0 ;
}
}
return V_16 ;
}
static void F_75 ( struct V_31 * V_76 )
{
unsigned long V_77 ;
F_76 ( 4 , L_12 ) ;
F_12 ( F_73 , F_74 ,
NULL ) ;
F_77 ( & V_69 , V_77 ) ;
if ( F_78 ( V_72 ) ) {
F_71 ( & V_70 , 0 ) ;
F_79 ( & V_71 ) ;
}
F_80 ( & V_69 , V_77 ) ;
}
void F_68 ( struct V_1 V_3 )
{
unsigned long V_77 ;
F_77 ( & V_69 , V_77 ) ;
F_81 ( V_72 , V_3 ) ;
F_71 ( & V_70 , 1 ) ;
F_42 ( V_37 , & V_78 ) ;
F_80 ( & V_69 , V_77 ) ;
}
void F_82 ( void )
{
unsigned long V_77 ;
F_77 ( & V_69 , V_77 ) ;
F_16 ( V_72 ) ;
F_71 ( & V_70 , 1 ) ;
F_42 ( V_37 , & V_78 ) ;
F_80 ( & V_69 , V_77 ) ;
}
static int F_83 ( struct V_10 * V_11 , void * V_2 )
{
struct V_79 * V_17 = V_2 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_6 ( V_17 , V_13 -> V_3 ) ;
return 0 ;
}
static void F_84 ( void )
{
unsigned long V_77 ;
struct V_79 * V_80 ;
V_80 = F_15 () ;
if ( ! V_80 ) {
F_82 () ;
return;
}
F_16 ( V_80 ) ;
F_17 ( & V_20 , NULL , V_80 , F_83 ) ;
F_77 ( & V_69 , V_77 ) ;
F_85 ( V_72 , V_80 ) ;
F_71 ( & V_70 , 1 ) ;
F_42 ( V_37 , & V_78 ) ;
F_80 ( & V_69 , V_77 ) ;
F_18 ( V_80 ) ;
}
void F_86 ( void )
{
F_87 ( V_37 ) ;
}
void F_88 ( void )
{
F_84 () ;
}
static void F_89 ( struct V_81 * V_82 , struct V_81 * V_83 , int V_84 )
{
struct V_1 V_85 ;
struct V_12 * V_13 ;
if ( V_84 ) {
F_82 () ;
return;
}
F_90 ( 2 , L_13
L_14 ,
V_82 -> V_86 , V_82 -> V_87 , V_82 -> V_88 , V_82 -> V_89 , V_82 -> V_90 ,
V_82 -> V_91 , V_82 -> V_92 ) ;
if ( V_83 )
F_90 ( 2 , L_15
L_14 ,
V_83 -> V_86 , V_83 -> V_87 , V_83 -> V_88 , V_83 -> V_89 ,
V_83 -> V_90 , V_83 -> V_91 , V_83 -> V_92 ) ;
F_3 ( & V_85 ) ;
V_85 . V_6 = V_82 -> V_92 ;
if ( V_83 )
V_85 . V_8 = ( V_83 -> V_92 >> 4 ) & 3 ;
if ( V_82 -> V_91 == V_93 ) {
V_13 = F_10 ( V_85 ) ;
if ( V_13 ) {
F_48 ( V_13 ) ;
F_11 ( & V_13 -> V_11 ) ;
}
}
F_67 ( V_85 , 0 ) ;
}
static void T_2
F_91 ( struct V_94 * V_95 , T_3 V_96 )
{
struct V_97 V_98 ;
if ( V_99 . V_100 ) {
V_95 -> V_101 . V_102 . V_103 . V_104 = 0x80 ;
V_95 -> V_101 . V_102 . V_103 . V_105 = V_95 -> V_105 ;
} else {
#ifdef F_92
V_95 -> V_101 . V_102 . V_106 = F_93 () ;
#else
V_95 -> V_101 . V_102 . V_106 = 0 ;
#endif
}
F_94 ( & V_98 ) ;
V_95 -> V_101 . V_98 = V_98 . V_107 ;
V_95 -> V_101 . V_108 = V_98 . V_109 ;
V_95 -> V_101 . V_96 = V_96 ;
}
static void
F_95 ( struct V_10 * V_11 )
{
struct V_94 * V_95 ;
V_95 = F_96 ( V_11 ) ;
F_97 ( & V_95 -> V_110 ) ;
if ( V_95 -> V_111 ) {
F_25 ( & V_95 -> V_111 -> V_11 ) ;
V_95 -> V_111 = NULL ;
}
F_23 ( V_95 ) ;
}
static T_1
F_98 ( struct V_10 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_94 * V_95 = F_96 ( V_11 ) ;
int V_4 ;
if ( ! V_95 )
return 0 ;
F_29 ( & V_95 -> V_110 ) ;
V_4 = sprintf ( V_51 , L_16 , V_95 -> V_112 ) ;
F_32 ( & V_95 -> V_110 ) ;
return V_4 ;
}
static T_1
F_99 ( struct V_10 * V_11 , struct V_49 * V_50 ,
const char * V_51 , T_4 V_113 )
{
struct V_94 * V_95 = F_96 ( V_11 ) ;
int V_4 ;
unsigned long V_114 ;
V_4 = F_100 ( V_51 , 16 , & V_114 ) ;
if ( V_4 )
return V_4 ;
F_29 ( & V_95 -> V_110 ) ;
switch ( V_114 ) {
case 0 :
V_4 = V_95 -> V_112 ? F_101 ( V_95 , 0 ) : 0 ;
break;
case 1 :
V_4 = V_95 -> V_112 ? 0 : F_101 ( V_95 , 1 ) ;
break;
default:
V_4 = - V_115 ;
}
F_32 ( & V_95 -> V_110 ) ;
return V_4 < 0 ? V_4 : V_113 ;
}
static int T_2 F_102 ( int V_116 )
{
T_3 V_96 ;
int V_4 ;
struct V_94 * V_95 ;
V_95 = V_54 [ V_116 ] ;
memset ( V_95 , 0 , sizeof( struct V_94 ) ) ;
V_95 -> V_111 =
F_103 ( sizeof( * V_95 -> V_111 ) , V_22 ) ;
if ( ! V_95 -> V_111 )
return - V_24 ;
V_95 -> V_111 -> V_11 . V_53 = & V_95 -> V_10 ;
V_95 -> V_111 -> V_11 . V_56 = F_25 ;
F_30 ( & V_95 -> V_111 -> V_11 , L_17 ) ;
F_104 ( & V_95 -> V_111 -> V_30 ) ;
V_4 = F_105 ( V_95 -> V_111 ) ;
if ( V_4 ) {
F_23 ( V_95 -> V_111 ) ;
return V_4 ;
}
F_104 ( & V_95 -> V_110 ) ;
V_95 -> V_117 = 1 ;
V_95 -> V_105 = V_116 ;
F_30 ( & V_95 -> V_10 , L_18 , V_116 ) ;
V_95 -> V_10 . V_56 = F_95 ;
V_96 = ( T_3 ) ( F_106 () >> 32 ) ;
F_91 ( V_95 , V_96 ) ;
return 0 ;
}
static int F_107 ( struct V_118 * V_119 ,
unsigned long V_120 ,
void * V_121 )
{
int V_4 , V_41 ;
V_4 = V_122 ;
for ( V_41 = 0 ; V_41 <= V_123 ; V_41 ++ ) {
struct V_94 * V_95 ;
V_95 = V_54 [ V_41 ] ;
F_29 ( & V_95 -> V_110 ) ;
if ( V_95 -> V_112 )
if ( F_101 ( V_95 , 0 ) )
V_4 = V_124 ;
F_32 ( & V_95 -> V_110 ) ;
}
return V_4 ;
}
static int F_108 ( struct V_118 * V_119 , unsigned long V_120 ,
void * V_121 )
{
int V_4 , V_41 ;
switch ( V_120 ) {
case V_125 :
case V_126 :
V_4 = V_122 ;
for ( V_41 = 0 ; V_41 <= V_123 ; V_41 ++ ) {
struct V_94 * V_95 ;
V_95 = V_54 [ V_41 ] ;
F_29 ( & V_95 -> V_110 ) ;
if ( ! V_95 -> V_112 ) {
F_32 ( & V_95 -> V_110 ) ;
continue;
}
if ( F_109 ( V_95 , 0 ) )
V_4 = V_124 ;
F_32 ( & V_95 -> V_110 ) ;
}
break;
case V_127 :
case V_128 :
V_4 = V_122 ;
for ( V_41 = 0 ; V_41 <= V_123 ; V_41 ++ ) {
struct V_94 * V_95 ;
V_95 = V_54 [ V_41 ] ;
F_29 ( & V_95 -> V_110 ) ;
if ( ! V_95 -> V_112 ) {
F_32 ( & V_95 -> V_110 ) ;
continue;
}
if ( F_109 ( V_95 , 1 ) )
V_4 = V_124 ;
F_32 ( & V_95 -> V_110 ) ;
}
F_88 () ;
break;
default:
V_4 = V_122 ;
}
return V_4 ;
}
static int T_2 F_110 ( void )
{
int V_4 , V_41 ;
V_4 = F_111 () ;
if ( V_4 )
return V_4 ;
F_112 () ;
V_4 = F_113 ( V_129 ) ;
if ( V_4 )
V_9 = 0 ;
else
V_9 = V_130 ;
V_4 = F_69 () ;
if ( V_4 )
goto V_21;
V_4 = F_114 ( V_131 , F_89 ) ;
if ( V_4 )
goto V_21;
if ( ( V_4 = F_115 ( & V_20 ) ) )
goto V_21;
for ( V_41 = 0 ; V_41 <= V_123 ; V_41 ++ ) {
struct V_94 * V_95 ;
V_95 = F_20 ( sizeof( struct V_94 ) , V_22 ) ;
if ( ! V_95 ) {
V_4 = - V_24 ;
goto V_132;
}
V_54 [ V_41 ] = V_95 ;
V_4 = F_102 ( V_41 ) ;
if ( V_4 ) {
F_23 ( V_54 [ V_41 ] ) ;
goto V_132;
}
V_4 = F_31 ( & V_95 -> V_10 ) ;
if ( V_4 ) {
F_11 ( & V_95 -> V_10 ) ;
goto V_132;
}
if ( V_133 . V_134 ) {
V_4 = F_116 ( & V_95 -> V_10 ,
& V_135 ) ;
if ( V_4 )
goto V_136;
}
V_4 = F_31 ( & V_95 -> V_111 -> V_11 ) ;
if ( V_4 ) {
F_11 ( & V_95 -> V_111 -> V_11 ) ;
goto V_137;
}
}
V_4 = F_117 ( & V_138 ) ;
if ( V_4 )
goto V_132;
V_4 = F_118 ( & V_139 ) ;
if ( V_4 ) {
F_119 ( & V_138 ) ;
goto V_132;
}
V_140 = 1 ;
F_120 ( V_141 ) ;
return 0 ;
V_137:
if ( V_133 . V_134 )
F_121 ( & V_54 [ V_41 ] -> V_10 ,
& V_135 ) ;
V_136:
F_35 ( & V_54 [ V_41 ] -> V_10 ) ;
V_132:
while ( V_41 > 0 ) {
struct V_94 * V_95 ;
V_41 -- ;
V_95 = V_54 [ V_41 ] ;
F_35 ( & V_95 -> V_111 -> V_11 ) ;
V_95 -> V_111 = NULL ;
if ( V_133 . V_134 )
F_121 ( & V_95 -> V_10 ,
& V_135 ) ;
F_35 ( & V_95 -> V_10 ) ;
}
F_122 ( & V_20 ) ;
V_21:
F_123 ( V_131 ) ;
F_18 ( V_72 ) ;
F_124 () ;
F_125 ( L_19
L_20 , V_4 ) ;
return V_4 ;
}
static void T_2 F_126 ( void )
{
struct V_94 * V_95 ;
int V_41 ;
for ( V_41 = 0 ; V_41 <= V_123 ; V_41 ++ ) {
V_95 = V_54 [ V_41 ] ;
F_35 ( & V_95 -> V_111 -> V_11 ) ;
V_95 -> V_111 = NULL ;
if ( V_133 . V_134 )
F_121 ( & V_95 -> V_10 , & V_135 ) ;
F_35 ( & V_95 -> V_10 ) ;
}
F_122 ( & V_20 ) ;
F_123 ( V_131 ) ;
F_18 ( V_72 ) ;
F_124 () ;
F_127 ( V_141 ) ;
}
static int T_2 F_128 ( void )
{
int V_4 ;
V_4 = F_110 () ;
if ( V_4 )
return V_4 ;
V_37 = F_129 ( L_21 ) ;
if ( ! V_37 ) {
V_4 = - V_24 ;
goto V_142;
}
V_4 = F_130 () ;
if ( V_4 )
goto V_143;
return V_4 ;
V_143:
F_131 ( V_37 ) ;
V_142:
F_126 () ;
return V_4 ;
}
static int F_132 ( struct V_144 * V_145 , void * V_76 )
{
struct V_146 * V_147 = F_133 ( V_145 ) ;
if ( V_147 -> V_148 )
return V_147 -> V_148 () ;
return 0 ;
}
int F_134 ( void )
{
int V_4 ;
V_4 = F_135 ( V_71 ,
F_136 ( & V_70 ) == 0 ) ;
if ( V_4 )
return - V_149 ;
F_87 ( V_37 ) ;
return F_137 ( & V_20 , NULL , NULL , F_132 ) ;
}
static int T_2 F_138 ( void )
{
F_82 () ;
F_134 () ;
return 0 ;
}
void F_139 ( void )
{
struct V_150 * V_151 ;
struct V_152 V_45 ;
F_113 ( V_129 ) ;
F_140 (&chpid) {
V_151 = F_141 ( V_45 ) ;
if ( ! V_151 )
continue;
F_142 ( V_45 , & V_151 -> V_153 ) ;
}
}
static T_1 F_143 ( struct V_154 * V_154 , const char T_5 * V_51 ,
T_4 V_113 , T_6 * V_155 )
{
int V_4 ;
F_144 () ;
V_4 = F_134 () ;
return V_4 ? V_4 : V_113 ;
}
static int T_2 F_145 ( void )
{
struct V_156 * V_157 ;
V_157 = F_146 ( L_22 , V_158 , NULL ,
& V_159 ) ;
if ( ! V_157 )
return - V_24 ;
return 0 ;
}
int F_147 ( struct V_12 * V_13 )
{
return V_13 == F_96 ( V_13 -> V_11 . V_53 ) -> V_111 ;
}
static int F_148 ( struct V_10 * V_11 , struct V_144 * V_145 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_146 * V_59 = F_133 ( V_145 ) ;
struct V_160 * V_46 ;
for ( V_46 = V_59 -> V_161 ; V_46 -> V_162 ; V_46 ++ ) {
if ( V_13 -> V_52 == V_46 -> type )
return 1 ;
}
return 0 ;
}
static int F_149 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_5 ( V_11 ) ;
V_13 -> V_59 = F_133 ( V_11 -> V_59 ) ;
V_4 = V_13 -> V_59 -> V_163 ? V_13 -> V_59 -> V_163 ( V_13 ) : 0 ;
if ( V_4 )
V_13 -> V_59 = NULL ;
return V_4 ;
}
static int F_150 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_4 ;
V_13 = F_5 ( V_11 ) ;
V_4 = V_13 -> V_59 -> remove ? V_13 -> V_59 -> remove ( V_13 ) : 0 ;
V_13 -> V_59 = NULL ;
return V_4 ;
}
static void F_151 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_59 && V_13 -> V_59 -> V_164 )
V_13 -> V_59 -> V_164 ( V_13 ) ;
}
static int F_152 ( struct V_10 * V_11 , struct V_165 * V_166 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_4 ;
V_4 = F_153 ( V_166 , L_23 , V_13 -> V_52 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_153 ( V_166 , L_24 , V_13 -> V_52 ) ;
return V_4 ;
}
static int F_154 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_146 * V_145 ;
if ( F_155 ( & V_13 -> V_30 ) )
return - V_67 ;
if ( ! V_13 -> V_11 . V_59 )
return 0 ;
V_145 = F_133 ( V_13 -> V_11 . V_59 ) ;
return V_145 -> V_167 ? V_145 -> V_167 ( V_13 ) : 0 ;
}
static void F_156 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_146 * V_145 ;
if ( ! V_13 -> V_11 . V_59 )
return;
V_145 = F_133 ( V_13 -> V_11 . V_59 ) ;
if ( V_145 -> V_168 )
V_145 -> V_168 ( V_13 ) ;
}
static int F_157 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_146 * V_145 ;
if ( ! V_13 -> V_11 . V_59 )
return 0 ;
V_145 = F_133 ( V_13 -> V_11 . V_59 ) ;
return V_145 -> V_169 ? V_145 -> V_169 ( V_13 ) : 0 ;
}
static int F_158 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_146 * V_145 ;
if ( ! V_13 -> V_11 . V_59 )
return 0 ;
V_145 = F_133 ( V_13 -> V_11 . V_59 ) ;
return V_145 -> V_170 ? V_145 -> V_170 ( V_13 ) : 0 ;
}
static int F_159 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_146 * V_145 ;
F_48 ( V_13 ) ;
if ( ! V_13 -> V_11 . V_59 )
return 0 ;
V_145 = F_133 ( V_13 -> V_11 . V_59 ) ;
return V_145 -> V_171 ? V_145 -> V_171 ( V_13 ) : 0 ;
}
int F_160 ( struct V_146 * V_172 )
{
V_172 -> V_145 . V_55 = & V_20 ;
return F_161 ( & V_172 -> V_145 ) ;
}
void F_162 ( struct V_146 * V_172 )
{
F_163 ( & V_172 -> V_145 ) ;
}
