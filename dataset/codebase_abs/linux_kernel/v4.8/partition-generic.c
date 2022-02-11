char * F_1 ( struct V_1 * V_2 , int V_3 , char * V_4 )
{
if ( ! V_3 )
snprintf ( V_4 , V_5 , L_1 , V_2 -> F_1 ) ;
else if ( isdigit ( V_2 -> F_1 [ strlen ( V_2 -> F_1 ) - 1 ] ) )
snprintf ( V_4 , V_5 , L_2 , V_2 -> F_1 , V_3 ) ;
else
snprintf ( V_4 , V_5 , L_3 , V_2 -> F_1 , V_3 ) ;
return V_4 ;
}
const char * F_2 ( struct V_6 * V_7 , char * V_4 )
{
return F_1 ( V_7 -> V_8 , V_7 -> V_9 -> V_3 , V_4 ) ;
}
const char * F_3 ( T_1 V_10 , char * V_11 )
{
F_4 ( V_11 , V_5 , L_4 ,
F_5 ( V_10 ) , F_6 ( V_10 ) ) ;
return V_11 ;
}
static T_2 F_7 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_5 , V_16 -> V_3 ) ;
}
static T_2 F_9 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_6 , ( unsigned long long ) V_16 -> V_17 ) ;
}
T_2 F_10 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_6 , ( unsigned long long ) F_11 ( V_16 ) ) ;
}
static T_2 F_12 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_5 , V_16 -> V_18 ? 1 : 0 ) ;
}
static T_2 F_13 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_6 , ( unsigned long long ) V_16 -> V_19 ) ;
}
static T_2 F_14 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_7 , V_16 -> V_20 ) ;
}
T_2 F_15 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
int V_21 ;
V_21 = F_16 () ;
F_17 ( V_21 , V_16 ) ;
F_18 () ;
return sprintf ( V_4 ,
L_8
L_8
L_9
L_10 ,
F_19 ( V_16 , V_22 [ V_23 ] ) ,
F_19 ( V_16 , V_24 [ V_23 ] ) ,
( unsigned long long ) F_19 ( V_16 , V_25 [ V_23 ] ) ,
F_20 ( F_19 ( V_16 , V_26 [ V_23 ] ) ) ,
F_19 ( V_16 , V_22 [ V_27 ] ) ,
F_19 ( V_16 , V_24 [ V_27 ] ) ,
( unsigned long long ) F_19 ( V_16 , V_25 [ V_27 ] ) ,
F_20 ( F_19 ( V_16 , V_26 [ V_27 ] ) ) ,
F_21 ( V_16 ) ,
F_20 ( F_19 ( V_16 , V_28 ) ) ,
F_20 ( F_19 ( V_16 , V_29 ) ) ) ;
}
T_2 F_22 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_11 , F_23 ( & V_16 -> V_30 [ 0 ] ) ,
F_23 ( & V_16 -> V_30 [ 1 ] ) ) ;
}
T_2 F_24 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_5 , V_16 -> V_31 ) ;
}
T_2 F_25 ( struct V_12 * V_10 ,
struct V_13 * V_14 ,
const char * V_4 , T_3 V_32 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
int V_33 ;
if ( V_32 > 0 && sscanf ( V_4 , L_12 , & V_33 ) > 0 )
V_16 -> V_31 = ( V_33 == 0 ) ? 0 : 1 ;
return V_32 ;
}
static void F_26 ( struct V_12 * V_10 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
F_27 ( V_10 -> V_34 ) ;
F_28 ( V_16 ) ;
F_29 ( V_16 ) ;
}
static int F_30 ( struct V_12 * V_10 , struct V_35 * V_36 )
{
struct V_15 * V_37 = F_8 ( V_10 ) ;
F_31 ( V_36 , L_13 , V_37 -> V_3 ) ;
if ( V_37 -> V_38 && V_37 -> V_38 -> V_39 [ 0 ] )
F_31 ( V_36 , L_14 , V_37 -> V_38 -> V_39 ) ;
return 0 ;
}
static void F_32 ( struct V_40 * V_41 )
{
struct V_15 * V_37 = F_33 ( V_41 , struct V_15 , V_40 ) ;
V_37 -> V_17 = 0 ;
V_37 -> V_42 = 0 ;
F_34 ( V_37 , 0 ) ;
F_35 ( F_36 ( V_37 ) ) ;
}
void F_37 ( struct V_43 * V_44 )
{
struct V_15 * V_37 = F_33 ( V_44 , struct V_15 , V_44 ) ;
F_38 ( & V_37 -> V_40 , F_32 ) ;
}
void F_39 ( struct V_1 * V_45 , int V_3 )
{
struct V_46 * V_47 = V_45 -> V_48 ;
struct V_15 * V_37 ;
if ( V_3 >= V_47 -> V_49 )
return;
V_37 = V_47 -> V_37 [ V_3 ] ;
if ( ! V_37 )
return;
F_40 ( V_47 -> V_37 [ V_3 ] , NULL ) ;
F_40 ( V_47 -> V_50 , NULL ) ;
F_41 ( V_37 -> V_51 ) ;
F_42 ( F_36 ( V_37 ) ) ;
F_43 ( V_37 ) ;
}
static T_2 F_44 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
return 0 ;
}
struct V_15 * F_45 ( struct V_1 * V_45 , int V_3 ,
T_4 V_52 , T_4 V_49 , int V_53 ,
struct V_54 * V_38 )
{
struct V_15 * V_16 ;
T_1 V_34 = F_46 ( 0 , 0 ) ;
struct V_12 * V_55 = F_47 ( V_45 ) ;
struct V_12 * V_56 ;
struct V_46 * V_47 ;
const char * V_57 ;
int V_58 ;
V_58 = F_48 ( V_45 , V_3 ) ;
if ( V_58 )
return F_49 ( V_58 ) ;
V_47 = V_45 -> V_48 ;
if ( V_47 -> V_37 [ V_3 ] )
return F_49 ( - V_59 ) ;
V_16 = F_50 ( sizeof( * V_16 ) , V_60 ) ;
if ( ! V_16 )
return F_49 ( - V_59 ) ;
if ( ! F_51 ( V_16 ) ) {
V_58 = - V_61 ;
goto V_62;
}
F_52 ( & V_16 -> V_63 ) ;
V_56 = F_36 ( V_16 ) ;
V_16 -> V_17 = V_52 ;
V_16 -> V_19 =
F_53 ( & V_45 -> V_64 -> V_65 , V_52 ) ;
V_16 -> V_20 =
F_54 ( & V_45 -> V_64 -> V_65 , V_52 ) ;
V_16 -> V_42 = V_49 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_18 = F_55 ( V_45 ) ;
if ( V_38 ) {
struct V_54 * V_66 = F_56 ( V_45 ) ;
if ( ! V_66 )
goto V_67;
memcpy ( V_66 , V_38 , sizeof( * V_38 ) ) ;
V_16 -> V_38 = V_66 ;
}
V_57 = F_57 ( V_55 ) ;
if ( isdigit ( V_57 [ strlen ( V_57 ) - 1 ] ) )
F_58 ( V_56 , L_2 , V_57 , V_3 ) ;
else
F_58 ( V_56 , L_3 , V_57 , V_3 ) ;
F_59 ( V_56 ) ;
V_56 -> V_68 = & V_69 ;
V_56 -> type = & V_70 ;
V_56 -> V_71 = V_55 ;
V_58 = F_60 ( V_16 , & V_34 ) ;
if ( V_58 )
goto V_72;
V_56 -> V_34 = V_34 ;
F_61 ( V_56 , 1 ) ;
V_58 = F_62 ( V_56 ) ;
if ( V_58 )
goto V_73;
V_58 = - V_61 ;
V_16 -> V_51 = F_63 ( L_15 , & V_56 -> V_74 ) ;
if ( ! V_16 -> V_51 )
goto V_75;
F_61 ( V_56 , 0 ) ;
if ( V_53 & V_76 ) {
V_58 = F_64 ( V_56 , & V_77 ) ;
if ( V_58 )
goto V_75;
}
V_58 = F_65 ( V_16 ) ;
if ( V_58 ) {
if ( V_53 & V_76 )
goto V_78;
goto V_75;
}
F_40 ( V_47 -> V_37 [ V_3 ] , V_16 ) ;
if ( ! F_66 ( V_55 ) )
F_67 ( & V_56 -> V_74 , V_79 ) ;
return V_16 ;
V_72:
F_68 ( V_16 ) ;
V_67:
F_69 ( V_16 ) ;
V_62:
F_29 ( V_16 ) ;
return F_49 ( V_58 ) ;
V_78:
F_70 ( V_56 , & V_77 ) ;
V_75:
F_41 ( V_16 -> V_51 ) ;
F_42 ( V_56 ) ;
V_73:
F_35 ( V_56 ) ;
F_27 ( V_34 ) ;
return F_49 ( V_58 ) ;
}
static bool F_71 ( struct V_1 * V_45 )
{
const struct V_80 * V_81 = V_45 -> V_82 ;
if ( V_81 -> V_83 &&
! ( V_45 -> V_53 & V_84 ) ) {
F_72 ( V_85 L_16 ) ;
V_81 -> V_83 ( V_45 ) ;
V_45 -> V_53 |= V_84 ;
return true ;
} else {
F_72 ( V_85 L_17 ) ;
return false ;
}
}
static int F_73 ( struct V_1 * V_45 , struct V_6 * V_7 )
{
struct V_86 V_87 ;
struct V_15 * V_37 ;
int V_88 ;
if ( V_7 -> V_89 || V_7 -> V_90 )
return - V_59 ;
V_88 = F_74 ( V_45 , 0 ) ;
if ( V_88 )
return V_88 ;
F_75 ( & V_87 , V_45 , V_91 ) ;
while ( ( V_37 = F_76 ( & V_87 ) ) )
F_39 ( V_45 , V_37 -> V_3 ) ;
F_77 ( & V_87 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_45 , struct V_6 * V_7 )
{
struct V_92 * V_93 = NULL ;
struct V_15 * V_37 ;
int V_16 , V_94 , V_88 ;
V_95:
if ( V_93 && ! F_79 ( V_93 ) ) {
F_80 ( V_93 ) ;
V_93 = NULL ;
}
V_88 = F_73 ( V_45 , V_7 ) ;
if ( V_88 )
return V_88 ;
if ( V_45 -> V_82 -> V_96 )
V_45 -> V_82 -> V_96 ( V_45 ) ;
F_81 ( V_45 ) ;
F_82 ( V_45 , V_7 ) ;
V_7 -> V_97 = 0 ;
if ( ! F_83 ( V_45 ) || ! ( V_93 = F_84 ( V_45 , V_7 ) ) )
return 0 ;
if ( F_79 ( V_93 ) ) {
if ( F_85 ( V_93 ) == - V_98 ) {
F_72 ( V_99 L_18 ,
V_45 -> F_1 ) ;
if ( F_71 ( V_45 ) )
goto V_95;
}
return - V_100 ;
}
if ( V_93 -> V_101 ) {
F_72 ( V_99
L_19 ,
V_45 -> F_1 ) ;
if ( F_71 ( V_45 ) )
goto V_95;
}
F_67 ( & F_47 ( V_45 ) -> V_74 , V_102 ) ;
for ( V_16 = 1 , V_94 = 0 ; V_16 < V_93 -> V_103 ; V_16 ++ )
if ( V_93 -> V_104 [ V_16 ] . V_105 )
V_94 = V_16 ;
F_48 ( V_45 , V_94 ) ;
for ( V_16 = 1 ; V_16 < V_93 -> V_103 ; V_16 ++ ) {
T_4 V_105 , V_106 ;
V_105 = V_93 -> V_104 [ V_16 ] . V_105 ;
if ( ! V_105 )
continue;
V_106 = V_93 -> V_104 [ V_16 ] . V_106 ;
if ( V_106 >= F_83 ( V_45 ) ) {
F_72 ( V_99
L_20 ,
V_45 -> F_1 , V_16 , ( unsigned long long ) V_106 ) ;
if ( F_71 ( V_45 ) )
goto V_95;
continue;
}
if ( V_106 + V_105 > F_83 ( V_45 ) ) {
F_72 ( V_99
L_21 ,
V_45 -> F_1 , V_16 , ( unsigned long long ) V_105 ) ;
if ( F_71 ( V_45 ) ) {
goto V_95;
} else {
V_105 = F_83 ( V_45 ) - V_106 ;
}
}
V_37 = F_45 ( V_45 , V_16 , V_106 , V_105 ,
V_93 -> V_104 [ V_16 ] . V_53 ,
& V_93 -> V_104 [ V_16 ] . V_38 ) ;
if ( F_79 ( V_37 ) ) {
F_72 ( V_107 L_22 ,
V_45 -> F_1 , V_16 , - F_85 ( V_37 ) ) ;
continue;
}
#ifdef F_86
if ( V_93 -> V_104 [ V_16 ] . V_53 & V_108 )
F_87 ( F_36 ( V_37 ) -> V_34 ) ;
#endif
}
F_80 ( V_93 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_45 , struct V_6 * V_7 )
{
int V_88 ;
if ( ! V_7 -> V_97 )
return 0 ;
V_88 = F_73 ( V_45 , V_7 ) ;
if ( V_88 )
return V_88 ;
F_89 ( V_45 , 0 ) ;
F_82 ( V_45 , V_7 ) ;
V_7 -> V_97 = 0 ;
F_67 ( & F_47 ( V_45 ) -> V_74 , V_102 ) ;
return 0 ;
}
static struct V_109 * F_90 ( struct V_6 * V_7 , T_4 V_110 )
{
struct V_111 * V_112 = V_7 -> V_113 -> V_114 ;
return F_91 ( V_112 , ( V_115 ) ( V_110 >> ( V_116 - 9 ) ) ,
NULL ) ;
}
unsigned char * F_92 ( struct V_6 * V_7 , T_4 V_110 , T_5 * V_16 )
{
struct V_109 * V_109 ;
if ( F_93 ( V_7 -> V_113 ) )
V_109 = F_94 ( V_7 , V_110 ) ;
else
V_109 = F_90 ( V_7 , V_110 ) ;
if ( ! F_79 ( V_109 ) ) {
if ( F_95 ( V_109 ) )
goto V_117;
V_16 -> V_118 = V_109 ;
return ( unsigned char * ) F_96 ( V_109 ) + ( ( V_110 & ( ( 1 << ( V_116 - 9 ) ) - 1 ) ) << 9 ) ;
V_117:
F_97 ( V_109 ) ;
}
V_16 -> V_118 = NULL ;
return NULL ;
}
