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
static T_1 F_49 ( struct V_9 * V_10 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_33 = & V_12 -> V_41 ;
T_1 V_4 = 0 ;
int V_36 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
V_36 = 0x80 >> V_47 ;
if ( V_33 -> V_37 & V_36 )
V_4 += sprintf ( V_45 + V_4 , L_4 , V_33 -> V_39 [ V_47 ] . V_40 ) ;
else
V_4 += sprintf ( V_45 + V_4 , L_5 ) ;
}
V_4 += sprintf ( V_45 + V_4 , L_6 ) ;
return V_4 ;
}
static T_1 F_50 ( struct V_9 * V_10 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_34 * V_34 = & V_12 -> V_42 . V_34 ;
return sprintf ( V_45 , L_7 ,
V_34 -> V_38 , V_34 -> V_48 , V_34 -> V_49 ) ;
}
int F_51 ( struct V_11 * V_12 )
{
int V_4 ;
V_12 -> V_10 . V_50 = & V_51 [ 0 ] -> V_9 ;
V_12 -> V_10 . V_52 = & V_19 ;
V_12 -> V_10 . V_53 = V_54 ;
if ( V_12 -> V_46 == V_55 )
V_12 -> V_10 . type = & V_56 ;
F_52 ( & V_12 -> V_10 , 1 ) ;
F_45 ( V_12 ) ;
V_4 = F_32 ( V_12 ) ;
if ( V_4 ) {
F_53 ( 0 , L_8 ,
V_12 -> V_3 . V_7 , V_12 -> V_3 . V_5 , V_4 ) ;
return V_4 ;
}
if ( ! V_12 -> V_57 ) {
F_52 ( & V_12 -> V_10 , 0 ) ;
F_54 ( & V_12 -> V_10 . V_58 , V_59 ) ;
}
return V_4 ;
}
static int F_55 ( struct V_1 V_3 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_26 ( V_3 ) ;
if ( F_56 ( V_12 ) )
return F_57 ( V_12 ) ;
V_4 = F_51 ( V_12 ) ;
if ( V_4 )
F_11 ( & V_12 -> V_10 ) ;
return V_4 ;
}
static int
F_58 ( struct V_9 * V_10 , void * V_2 )
{
struct V_11 * V_12 ;
struct V_1 * V_3 = V_2 ;
V_12 = F_5 ( V_10 ) ;
return F_59 ( & V_12 -> V_3 , V_3 ) ;
}
struct V_11 *
F_10 ( struct V_1 V_3 )
{
struct V_9 * V_10 ;
V_10 = F_60 ( & V_19 , NULL ,
& V_3 , F_58 ) ;
return V_10 ? F_5 ( V_10 ) : NULL ;
}
int F_61 ( struct V_42 * V_42 )
{
if ( ( V_42 -> V_34 . V_46 == V_55 ) && ! V_42 -> V_34 . V_60 )
return 0 ;
if ( ( V_42 -> V_34 . V_46 == V_61 ) && ! V_42 -> V_34 . V_62 )
return 0 ;
return 1 ;
}
static int F_62 ( struct V_1 V_3 , int V_63 )
{
struct V_42 V_42 ;
if ( ! V_63 ) {
return - V_64 ;
}
if ( F_63 ( V_3 , & V_42 ) ) {
return - V_65 ;
}
if ( ! F_61 ( & V_42 ) ) {
return 0 ;
}
F_53 ( 4 , L_9 , V_3 . V_7 ,
V_3 . V_5 ) ;
return F_55 ( V_3 ) ;
}
static int F_64 ( struct V_11 * V_12 , int V_63 )
{
int V_4 = 0 ;
if ( V_12 -> V_57 ) {
if ( V_12 -> V_57 -> V_66 )
V_4 = V_12 -> V_57 -> V_66 ( V_12 , V_63 ) ;
else
F_65 ( & V_12 -> V_10 ,
L_10
L_11 ) ;
}
if ( V_4 != 0 && V_4 != - V_64 ) {
F_53 ( 2 , L_12 ,
V_12 -> V_3 . V_7 , V_12 -> V_3 . V_5 , V_4 ) ;
}
return V_4 ;
}
static void F_66 ( struct V_1 V_3 , int V_63 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_10 ( V_3 ) ;
if ( V_12 ) {
V_4 = F_64 ( V_12 , V_63 ) ;
F_11 ( & V_12 -> V_10 ) ;
} else
V_4 = F_62 ( V_3 , V_63 ) ;
if ( V_4 == - V_64 )
F_67 ( V_3 ) ;
}
void F_68 ( struct V_11 * V_12 , enum V_67 V_68 )
{
F_53 ( 4 , L_13 ,
V_12 -> V_3 . V_7 , V_12 -> V_3 . V_5 , V_68 ) ;
if ( V_12 -> V_68 >= V_68 )
return;
if ( ! F_69 ( & V_12 -> V_10 ) )
return;
V_12 -> V_68 = V_68 ;
if ( ! F_70 ( V_69 , & V_12 -> V_29 ) ) {
F_11 ( & V_12 -> V_10 ) ;
}
}
static void V_30 ( struct V_70 * V_71 )
{
struct V_11 * V_12 ;
enum V_67 V_68 ;
int V_4 ;
V_12 = F_71 ( V_71 , struct V_11 , V_29 ) ;
F_72 ( V_12 -> V_21 ) ;
V_68 = V_12 -> V_68 ;
F_53 ( 4 , L_14 , V_12 -> V_3 . V_7 ,
V_12 -> V_3 . V_5 , V_68 ) ;
V_12 -> V_68 = V_72 ;
F_73 ( V_12 -> V_21 ) ;
switch ( V_68 ) {
case V_72 :
break;
case V_73 :
V_4 = F_64 ( V_12 , 1 ) ;
if ( V_4 == - V_64 ) {
F_72 ( V_12 -> V_21 ) ;
F_68 ( V_12 , V_68 ) ;
F_73 ( V_12 -> V_21 ) ;
}
break;
case V_74 :
F_37 ( V_12 ) ;
break;
}
F_11 ( & V_12 -> V_10 ) ;
}
static int T_2 F_74 ( void )
{
F_21 ( & V_75 ) ;
F_75 ( & V_76 , 0 ) ;
F_76 ( & V_77 ) ;
V_78 = F_16 () ;
if ( ! V_78 ) {
F_53 ( 0 , L_15 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_77 ( struct V_11 * V_12 , void * V_2 )
{
int V_79 ;
int V_15 ;
F_72 ( & V_75 ) ;
V_79 = F_8 ( V_78 , V_12 -> V_3 ) ;
F_6 ( V_78 , V_12 -> V_3 ) ;
F_73 ( & V_75 ) ;
if ( V_79 ) {
V_15 = F_64 ( V_12 , 1 ) ;
if ( V_15 == - V_64 )
F_67 ( V_12 -> V_3 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 V_3 , void * V_2 )
{
int V_79 ;
int V_15 = 0 ;
F_72 ( & V_75 ) ;
V_79 = F_8 ( V_78 , V_3 ) ;
F_6 ( V_78 , V_3 ) ;
F_73 ( & V_75 ) ;
if ( V_79 ) {
V_15 = F_62 ( V_3 , 1 ) ;
switch ( V_15 ) {
case - V_64 :
F_67 ( V_3 ) ;
V_15 = 0 ;
break;
case - V_65 :
case - V_23 :
case - V_80 :
F_72 ( & V_75 ) ;
F_79 ( V_78 , V_3 ) ;
F_73 ( & V_75 ) ;
break;
default:
V_15 = 0 ;
}
F_80 () ;
}
return V_15 ;
}
static void F_81 ( struct V_70 * V_81 )
{
unsigned long V_82 ;
F_82 ( 4 , L_16 ) ;
F_12 ( F_77 , F_78 ,
NULL ) ;
F_83 ( & V_75 , V_82 ) ;
if ( F_84 ( V_78 ) ) {
F_75 ( & V_76 , 0 ) ;
F_85 ( & V_77 ) ;
}
F_86 ( & V_75 , V_82 ) ;
}
void F_67 ( struct V_1 V_3 )
{
unsigned long V_82 ;
F_83 ( & V_75 , V_82 ) ;
F_87 ( V_78 , V_3 ) ;
F_75 ( & V_76 , 1 ) ;
F_88 ( V_69 , & V_83 , 0 ) ;
F_86 ( & V_75 , V_82 ) ;
}
void F_89 ( void )
{
unsigned long V_82 ;
F_83 ( & V_75 , V_82 ) ;
F_17 ( V_78 ) ;
F_75 ( & V_76 , 1 ) ;
F_88 ( V_69 , & V_83 , 0 ) ;
F_86 ( & V_75 , V_82 ) ;
}
static int F_90 ( struct V_9 * V_10 , void * V_2 )
{
struct V_84 * V_16 = V_2 ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_6 ( V_16 , V_12 -> V_3 ) ;
return 0 ;
}
void F_91 ( unsigned long V_85 )
{
unsigned long V_82 ;
struct V_84 * V_86 ;
V_86 = F_16 () ;
if ( ! V_86 ) {
F_89 () ;
return;
}
F_17 ( V_86 ) ;
F_15 ( & V_19 , NULL , V_86 , F_90 ) ;
F_83 ( & V_75 , V_82 ) ;
F_92 ( V_78 , V_86 ) ;
F_75 ( & V_76 , 1 ) ;
F_88 ( V_69 , & V_83 , V_85 ) ;
F_86 ( & V_75 , V_82 ) ;
F_18 ( V_86 ) ;
}
void F_93 ( void )
{
F_94 ( V_69 ) ;
}
void F_95 ( void )
{
F_91 ( 1 * V_87 ) ;
}
static void F_96 ( struct V_88 * V_89 , struct V_88 * V_90 , int V_91 )
{
struct V_1 V_92 ;
struct V_11 * V_12 ;
if ( V_91 ) {
F_89 () ;
return;
}
F_97 ( 2 , L_17
L_18 ,
V_89 -> V_93 , V_89 -> V_94 , V_89 -> V_95 , V_89 -> V_96 , V_89 -> V_97 ,
V_89 -> V_98 , V_89 -> V_99 ) ;
if ( V_90 )
F_97 ( 2 , L_19
L_18 ,
V_90 -> V_93 , V_90 -> V_94 , V_90 -> V_95 , V_90 -> V_96 ,
V_90 -> V_97 , V_90 -> V_98 , V_90 -> V_99 ) ;
F_3 ( & V_92 ) ;
V_92 . V_5 = V_89 -> V_99 ;
if ( V_90 )
V_92 . V_7 = ( V_90 -> V_99 >> 4 ) & 3 ;
if ( V_89 -> V_98 == V_100 ) {
V_12 = F_10 ( V_92 ) ;
if ( V_12 ) {
F_45 ( V_12 ) ;
F_11 ( & V_12 -> V_10 ) ;
}
}
F_66 ( V_92 , 0 ) ;
}
static void T_2
F_98 ( struct V_101 * V_102 , T_3 V_103 )
{
struct V_104 V_105 ;
if ( V_106 . V_107 ) {
V_102 -> V_108 . V_109 . V_110 . V_111 = 0x80 ;
V_102 -> V_108 . V_109 . V_110 . V_112 =
( V_102 -> V_112 < 0 ) ? 0 : V_102 -> V_112 ;
} else {
V_102 -> V_108 . V_109 . V_113 = F_99 () ;
}
F_100 ( & V_105 ) ;
V_102 -> V_108 . V_105 = V_105 . V_114 ;
V_102 -> V_108 . V_115 = V_105 . V_116 ;
V_102 -> V_108 . V_103 = V_103 ;
}
static void F_101 ( struct V_9 * V_10 )
{
struct V_101 * V_102 = F_102 ( V_10 ) ;
F_103 ( & V_102 -> V_117 ) ;
F_25 ( V_102 ) ;
}
static T_1 F_104 ( struct V_9 * V_10 , struct V_43 * V_118 ,
char * V_45 )
{
struct V_101 * V_102 = F_102 ( V_10 ) ;
if ( V_102 -> V_112 < 0 )
return - V_119 ;
return sprintf ( V_45 , L_20 , V_102 -> V_112 ) ;
}
static T_1 F_105 ( struct V_9 * V_10 , struct V_43 * V_118 ,
char * V_45 )
{
struct V_101 * V_102 = F_102 ( V_10 ) ;
int V_4 ;
F_33 ( & V_102 -> V_117 ) ;
V_4 = sprintf ( V_45 , L_20 , V_102 -> V_120 ) ;
F_36 ( & V_102 -> V_117 ) ;
return V_4 ;
}
static T_1 F_106 ( struct V_9 * V_10 , struct V_43 * V_118 ,
const char * V_45 , T_4 V_121 )
{
struct V_101 * V_102 = F_102 ( V_10 ) ;
unsigned long V_122 ;
int V_4 ;
V_4 = F_107 ( V_45 , 16 , & V_122 ) ;
if ( V_4 )
return V_4 ;
F_33 ( & V_102 -> V_117 ) ;
switch ( V_122 ) {
case 0 :
V_4 = V_102 -> V_120 ? F_108 ( V_102 , 0 ) : 0 ;
break;
case 1 :
V_4 = V_102 -> V_120 ? 0 : F_108 ( V_102 , 1 ) ;
break;
default:
V_4 = - V_119 ;
}
F_36 ( & V_102 -> V_117 ) ;
return V_4 < 0 ? V_4 : V_121 ;
}
static T_5 F_109 ( struct V_123 * V_58 , struct V_124 * V_44 ,
int V_125 )
{
return V_126 . V_127 ? V_44 -> V_128 : 0 ;
}
static int T_2 F_110 ( int V_129 )
{
struct V_101 * V_102 ;
int V_4 ;
V_102 = F_27 ( sizeof( * V_102 ) , V_22 ) ;
if ( ! V_102 )
return - V_23 ;
V_51 [ V_129 ] = V_102 ;
F_34 ( & V_102 -> V_9 , L_21 , V_129 ) ;
V_102 -> V_9 . V_53 = V_130 ;
V_102 -> V_9 . V_31 = F_101 ;
F_22 ( & V_102 -> V_117 ) ;
V_102 -> V_112 = F_111 ( V_129 ) ;
F_98 ( V_102 , ( T_3 ) ( F_112 () >> 32 ) ) ;
V_4 = F_113 ( & V_102 -> V_9 ) ;
if ( V_4 ) {
F_11 ( & V_102 -> V_9 ) ;
goto V_131;
}
V_102 -> V_132 = F_27 ( sizeof( * V_102 -> V_132 ) ,
V_22 ) ;
if ( ! V_102 -> V_132 ) {
F_39 ( & V_102 -> V_9 ) ;
V_4 = - V_23 ;
goto V_131;
}
V_102 -> V_132 -> V_10 . V_50 = & V_102 -> V_9 ;
V_102 -> V_132 -> V_10 . V_31 = F_23 ;
F_22 ( & V_102 -> V_132 -> V_24 ) ;
V_4 = F_19 ( V_102 -> V_132 ) ;
if ( V_4 ) {
F_25 ( V_102 -> V_132 ) ;
F_39 ( & V_102 -> V_9 ) ;
goto V_131;
}
F_34 ( & V_102 -> V_132 -> V_10 , L_22 ) ;
V_4 = F_113 ( & V_102 -> V_132 -> V_10 ) ;
if ( V_4 ) {
F_11 ( & V_102 -> V_132 -> V_10 ) ;
F_39 ( & V_102 -> V_9 ) ;
goto V_131;
}
return V_4 ;
V_131:
V_51 [ V_129 ] = NULL ;
return V_4 ;
}
static int F_114 ( struct V_133 * V_134 ,
unsigned long V_135 ,
void * V_136 )
{
struct V_101 * V_102 ;
int V_4 ;
V_4 = V_137 ;
F_115 (css) {
F_33 ( & V_102 -> V_117 ) ;
if ( V_102 -> V_120 )
if ( F_108 ( V_102 , 0 ) )
V_4 = V_138 ;
F_36 ( & V_102 -> V_117 ) ;
}
return V_4 ;
}
static int F_116 ( struct V_133 * V_134 , unsigned long V_135 ,
void * V_136 )
{
struct V_101 * V_102 ;
int V_4 ;
switch ( V_135 ) {
case V_139 :
case V_140 :
V_4 = V_137 ;
F_115 (css) {
F_33 ( & V_102 -> V_117 ) ;
if ( ! V_102 -> V_120 ) {
F_36 ( & V_102 -> V_117 ) ;
continue;
}
V_4 = F_117 ( V_102 , 0 ) ;
V_4 = F_118 ( V_4 ) ;
F_36 ( & V_102 -> V_117 ) ;
}
break;
case V_141 :
case V_142 :
V_4 = V_137 ;
F_115 (css) {
F_33 ( & V_102 -> V_117 ) ;
if ( ! V_102 -> V_120 ) {
F_36 ( & V_102 -> V_117 ) ;
continue;
}
V_4 = F_117 ( V_102 , 1 ) ;
V_4 = F_118 ( V_4 ) ;
F_36 ( & V_102 -> V_117 ) ;
}
F_95 () ;
break;
default:
V_4 = V_137 ;
}
return V_4 ;
}
static int T_2 F_119 ( void )
{
int V_4 , V_35 ;
V_4 = F_120 () ;
if ( V_4 )
return V_4 ;
F_121 () ;
V_4 = F_122 ( V_143 ) ;
if ( V_4 )
V_8 = 0 ;
else
V_8 = V_144 ;
V_4 = F_74 () ;
if ( V_4 )
goto V_20;
V_4 = F_123 ( V_145 , F_96 ) ;
if ( V_4 )
goto V_20;
if ( ( V_4 = F_124 ( & V_19 ) ) )
goto V_20;
for ( V_35 = 0 ; V_35 <= V_146 ; V_35 ++ ) {
V_4 = F_110 ( V_35 ) ;
if ( V_4 )
goto V_147;
}
V_4 = F_125 ( & V_148 ) ;
if ( V_4 )
goto V_147;
V_4 = F_126 ( & V_149 ) ;
if ( V_4 ) {
F_127 ( & V_148 ) ;
goto V_147;
}
V_150 = 1 ;
F_128 ( V_151 ) ;
return 0 ;
V_147:
while ( V_35 -- > 0 ) {
struct V_101 * V_102 = V_51 [ V_35 ] ;
F_39 ( & V_102 -> V_132 -> V_10 ) ;
F_39 ( & V_102 -> V_9 ) ;
}
F_129 ( & V_19 ) ;
V_20:
F_130 ( V_145 ) ;
F_18 ( V_78 ) ;
F_131 () ;
F_132 ( L_23
L_24 , V_4 ) ;
return V_4 ;
}
static void T_2 F_133 ( void )
{
struct V_101 * V_102 ;
F_115 (css) {
F_39 ( & V_102 -> V_132 -> V_10 ) ;
F_39 ( & V_102 -> V_9 ) ;
}
F_129 ( & V_19 ) ;
F_130 ( V_145 ) ;
F_18 ( V_78 ) ;
F_131 () ;
F_134 ( V_151 ) ;
}
static int T_2 F_135 ( void )
{
int V_4 ;
V_4 = F_119 () ;
if ( V_4 )
return V_4 ;
V_69 = F_136 ( L_25 ) ;
if ( ! V_69 ) {
V_4 = - V_23 ;
goto V_152;
}
V_4 = F_137 () ;
if ( V_4 )
goto V_153;
return V_4 ;
V_153:
F_138 ( V_69 ) ;
V_152:
F_133 () ;
return V_4 ;
}
static int F_139 ( struct V_154 * V_155 , void * V_81 )
{
struct V_156 * V_157 = F_140 ( V_155 ) ;
if ( V_157 -> V_158 )
return V_157 -> V_158 () ;
return 0 ;
}
int F_141 ( void )
{
int V_4 ;
V_4 = F_142 ( V_77 ,
F_143 ( & V_76 ) == 0 ) ;
if ( V_4 )
return - V_159 ;
F_94 ( V_69 ) ;
return F_144 ( & V_19 , NULL , NULL , F_139 ) ;
}
static int T_2 F_145 ( void )
{
F_146 () ;
F_89 () ;
F_141 () ;
return 0 ;
}
void F_147 ( void )
{
struct V_160 * V_47 ;
struct V_161 V_39 ;
F_122 ( V_143 ) ;
F_148 (&chpid) {
V_47 = F_149 ( V_39 ) ;
if ( V_47 )
F_150 ( V_47 ) ;
}
F_151 () ;
}
static T_1 F_152 ( struct V_162 * V_162 , const char T_6 * V_45 ,
T_4 V_121 , T_7 * V_163 )
{
int V_4 ;
F_153 () ;
V_4 = F_141 () ;
return V_4 ? V_4 : V_121 ;
}
static int T_2 F_154 ( void )
{
struct V_164 * V_165 ;
V_165 = F_155 ( L_26 , V_166 , NULL ,
& V_167 ) ;
if ( ! V_165 )
return - V_23 ;
return 0 ;
}
int F_156 ( struct V_11 * V_12 )
{
return V_12 == F_102 ( V_12 -> V_10 . V_50 ) -> V_132 ;
}
static int F_157 ( struct V_9 * V_10 , struct V_154 * V_155 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_156 * V_57 = F_140 ( V_155 ) ;
struct V_168 * V_40 ;
for ( V_40 = V_57 -> V_169 ; V_40 -> V_170 ; V_40 ++ ) {
if ( V_12 -> V_46 == V_40 -> type )
return 1 ;
}
return 0 ;
}
static int F_158 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_5 ( V_10 ) ;
V_12 -> V_57 = F_140 ( V_10 -> V_57 ) ;
V_4 = V_12 -> V_57 -> V_171 ? V_12 -> V_57 -> V_171 ( V_12 ) : 0 ;
if ( V_4 )
V_12 -> V_57 = NULL ;
return V_4 ;
}
static int F_159 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_4 ;
V_12 = F_5 ( V_10 ) ;
V_4 = V_12 -> V_57 -> remove ? V_12 -> V_57 -> remove ( V_12 ) : 0 ;
V_12 -> V_57 = NULL ;
return V_4 ;
}
static void F_160 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_57 && V_12 -> V_57 -> V_172 )
V_12 -> V_57 -> V_172 ( V_12 ) ;
}
static int F_161 ( struct V_9 * V_10 , struct V_173 * V_174 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_4 ;
V_4 = F_162 ( V_174 , L_27 , V_12 -> V_46 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_162 ( V_174 , L_28 , V_12 -> V_46 ) ;
return V_4 ;
}
static int F_163 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_156 * V_155 ;
if ( F_164 ( & V_12 -> V_24 ) )
return - V_64 ;
if ( ! V_12 -> V_10 . V_57 )
return 0 ;
V_155 = F_140 ( V_12 -> V_10 . V_57 ) ;
return V_155 -> V_175 ? V_155 -> V_175 ( V_12 ) : 0 ;
}
static void F_165 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_156 * V_155 ;
if ( ! V_12 -> V_10 . V_57 )
return;
V_155 = F_140 ( V_12 -> V_10 . V_57 ) ;
if ( V_155 -> V_176 )
V_155 -> V_176 ( V_12 ) ;
}
static int F_166 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_156 * V_155 ;
if ( ! V_12 -> V_10 . V_57 )
return 0 ;
V_155 = F_140 ( V_12 -> V_10 . V_57 ) ;
return V_155 -> V_177 ? V_155 -> V_177 ( V_12 ) : 0 ;
}
static int F_167 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_156 * V_155 ;
if ( ! V_12 -> V_10 . V_57 )
return 0 ;
V_155 = F_140 ( V_12 -> V_10 . V_57 ) ;
return V_155 -> V_178 ? V_155 -> V_178 ( V_12 ) : 0 ;
}
static int F_168 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_156 * V_155 ;
F_45 ( V_12 ) ;
if ( ! V_12 -> V_10 . V_57 )
return 0 ;
V_155 = F_140 ( V_12 -> V_10 . V_57 ) ;
return V_155 -> V_179 ? V_155 -> V_179 ( V_12 ) : 0 ;
}
int F_169 ( struct V_156 * V_180 )
{
V_180 -> V_155 . V_52 = & V_19 ;
return F_170 ( & V_180 -> V_155 ) ;
}
void F_171 ( struct V_156 * V_180 )
{
F_172 ( & V_180 -> V_155 ) ;
}
