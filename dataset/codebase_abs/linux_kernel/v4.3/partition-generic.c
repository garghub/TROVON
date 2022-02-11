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
static void F_30 ( struct V_35 * V_36 )
{
struct V_15 * V_37 = F_31 ( V_36 , struct V_15 , V_35 ) ;
V_37 -> V_17 = 0 ;
V_37 -> V_38 = 0 ;
F_32 ( V_37 , 0 ) ;
F_33 ( F_34 ( V_37 ) ) ;
}
void F_35 ( struct V_39 * V_40 )
{
struct V_15 * V_37 = F_31 ( V_40 , struct V_15 , V_40 ) ;
F_36 ( & V_37 -> V_35 , F_30 ) ;
}
void F_37 ( struct V_1 * V_41 , int V_3 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_15 * V_37 ;
if ( V_3 >= V_43 -> V_45 )
return;
V_37 = V_43 -> V_37 [ V_3 ] ;
if ( ! V_37 )
return;
F_38 ( V_43 -> V_37 [ V_3 ] , NULL ) ;
F_38 ( V_43 -> V_46 , NULL ) ;
F_39 ( V_37 -> V_47 ) ;
F_40 ( F_34 ( V_37 ) ) ;
F_41 ( V_37 ) ;
}
static T_2 F_42 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
return 0 ;
}
struct V_15 * F_43 ( struct V_1 * V_41 , int V_3 ,
T_4 V_48 , T_4 V_45 , int V_49 ,
struct V_50 * V_51 )
{
struct V_15 * V_16 ;
T_1 V_34 = F_44 ( 0 , 0 ) ;
struct V_12 * V_52 = F_45 ( V_41 ) ;
struct V_12 * V_53 ;
struct V_42 * V_43 ;
const char * V_54 ;
int V_55 ;
V_55 = F_46 ( V_41 , V_3 ) ;
if ( V_55 )
return F_47 ( V_55 ) ;
V_43 = V_41 -> V_44 ;
if ( V_43 -> V_37 [ V_3 ] )
return F_47 ( - V_56 ) ;
V_16 = F_48 ( sizeof( * V_16 ) , V_57 ) ;
if ( ! V_16 )
return F_47 ( - V_56 ) ;
if ( ! F_49 ( V_16 ) ) {
V_55 = - V_58 ;
goto V_59;
}
F_50 ( & V_16 -> V_60 ) ;
V_53 = F_34 ( V_16 ) ;
V_16 -> V_17 = V_48 ;
V_16 -> V_19 =
F_51 ( & V_41 -> V_61 -> V_62 , V_48 ) ;
V_16 -> V_20 =
F_52 ( & V_41 -> V_61 -> V_62 , V_48 ) ;
V_16 -> V_38 = V_45 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_18 = F_53 ( V_41 ) ;
if ( V_51 ) {
struct V_50 * V_63 = F_54 ( V_41 ) ;
if ( ! V_63 )
goto V_64;
memcpy ( V_63 , V_51 , sizeof( * V_51 ) ) ;
V_16 -> V_51 = V_63 ;
}
V_54 = F_55 ( V_52 ) ;
if ( isdigit ( V_54 [ strlen ( V_54 ) - 1 ] ) )
F_56 ( V_53 , L_2 , V_54 , V_3 ) ;
else
F_56 ( V_53 , L_3 , V_54 , V_3 ) ;
F_57 ( V_53 ) ;
V_53 -> V_65 = & V_66 ;
V_53 -> type = & V_67 ;
V_53 -> V_68 = V_52 ;
V_55 = F_58 ( V_16 , & V_34 ) ;
if ( V_55 )
goto V_69;
V_53 -> V_34 = V_34 ;
F_59 ( V_53 , 1 ) ;
V_55 = F_60 ( V_53 ) ;
if ( V_55 )
goto V_70;
V_55 = - V_58 ;
V_16 -> V_47 = F_61 ( L_13 , & V_53 -> V_71 ) ;
if ( ! V_16 -> V_47 )
goto V_72;
F_59 ( V_53 , 0 ) ;
if ( V_49 & V_73 ) {
V_55 = F_62 ( V_53 , & V_74 ) ;
if ( V_55 )
goto V_72;
}
F_38 ( V_43 -> V_37 [ V_3 ] , V_16 ) ;
if ( ! F_63 ( V_52 ) )
F_64 ( & V_53 -> V_71 , V_75 ) ;
if ( ! F_65 ( V_16 ) )
return V_16 ;
V_69:
F_66 ( V_16 ) ;
V_64:
F_67 ( V_16 ) ;
V_59:
F_29 ( V_16 ) ;
return F_47 ( V_55 ) ;
V_72:
F_39 ( V_16 -> V_47 ) ;
F_40 ( V_53 ) ;
V_70:
F_33 ( V_53 ) ;
F_27 ( V_34 ) ;
return F_47 ( V_55 ) ;
}
static bool F_68 ( struct V_1 * V_41 )
{
const struct V_76 * V_77 = V_41 -> V_78 ;
if ( V_77 -> V_79 &&
! ( V_41 -> V_49 & V_80 ) ) {
F_69 ( V_81 L_14 ) ;
V_77 -> V_79 ( V_41 ) ;
V_41 -> V_49 |= V_80 ;
return true ;
} else {
F_69 ( V_81 L_15 ) ;
return false ;
}
}
static int F_70 ( struct V_1 * V_41 , struct V_6 * V_7 )
{
struct V_82 V_83 ;
struct V_15 * V_37 ;
int V_84 ;
if ( V_7 -> V_85 )
return - V_56 ;
V_84 = F_71 ( V_41 , 0 ) ;
if ( V_84 )
return V_84 ;
F_72 ( & V_83 , V_41 , V_86 ) ;
while ( ( V_37 = F_73 ( & V_83 ) ) )
F_37 ( V_41 , V_37 -> V_3 ) ;
F_74 ( & V_83 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_41 , struct V_6 * V_7 )
{
struct V_87 * V_88 = NULL ;
struct V_15 * V_37 ;
int V_16 , V_89 , V_84 ;
V_90:
if ( V_88 && ! F_76 ( V_88 ) ) {
F_77 ( V_88 ) ;
V_88 = NULL ;
}
V_84 = F_70 ( V_41 , V_7 ) ;
if ( V_84 )
return V_84 ;
if ( V_41 -> V_78 -> V_91 )
V_41 -> V_78 -> V_91 ( V_41 ) ;
F_78 ( V_41 , V_7 ) ;
V_7 -> V_92 = 0 ;
if ( ! F_79 ( V_41 ) || ! ( V_88 = F_80 ( V_41 , V_7 ) ) )
return 0 ;
if ( F_76 ( V_88 ) ) {
if ( F_81 ( V_88 ) == - V_93 ) {
F_69 ( V_94 L_16 ,
V_41 -> F_1 ) ;
if ( F_68 ( V_41 ) )
goto V_90;
}
return - V_95 ;
}
if ( V_88 -> V_96 ) {
F_69 ( V_94
L_17 ,
V_41 -> F_1 ) ;
if ( F_68 ( V_41 ) )
goto V_90;
}
F_64 ( & F_45 ( V_41 ) -> V_71 , V_97 ) ;
for ( V_16 = 1 , V_89 = 0 ; V_16 < V_88 -> V_98 ; V_16 ++ )
if ( V_88 -> V_99 [ V_16 ] . V_100 )
V_89 = V_16 ;
F_46 ( V_41 , V_89 ) ;
for ( V_16 = 1 ; V_16 < V_88 -> V_98 ; V_16 ++ ) {
T_4 V_100 , V_101 ;
struct V_50 * V_51 = NULL ;
V_100 = V_88 -> V_99 [ V_16 ] . V_100 ;
if ( ! V_100 )
continue;
V_101 = V_88 -> V_99 [ V_16 ] . V_101 ;
if ( V_101 >= F_79 ( V_41 ) ) {
F_69 ( V_94
L_18 ,
V_41 -> F_1 , V_16 , ( unsigned long long ) V_101 ) ;
if ( F_68 ( V_41 ) )
goto V_90;
continue;
}
if ( V_101 + V_100 > F_79 ( V_41 ) ) {
F_69 ( V_94
L_19 ,
V_41 -> F_1 , V_16 , ( unsigned long long ) V_100 ) ;
if ( F_68 ( V_41 ) ) {
goto V_90;
} else {
V_100 = F_79 ( V_41 ) - V_101 ;
}
}
if ( V_88 -> V_99 [ V_16 ] . V_102 )
V_51 = & V_88 -> V_99 [ V_16 ] . V_51 ;
V_37 = F_43 ( V_41 , V_16 , V_101 , V_100 ,
V_88 -> V_99 [ V_16 ] . V_49 ,
& V_88 -> V_99 [ V_16 ] . V_51 ) ;
if ( F_76 ( V_37 ) ) {
F_69 ( V_103 L_20 ,
V_41 -> F_1 , V_16 , - F_81 ( V_37 ) ) ;
continue;
}
#ifdef F_82
if ( V_88 -> V_99 [ V_16 ] . V_49 & V_104 )
F_83 ( F_34 ( V_37 ) -> V_34 ) ;
#endif
}
F_77 ( V_88 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_41 , struct V_6 * V_7 )
{
int V_84 ;
if ( ! V_7 -> V_92 )
return 0 ;
V_84 = F_70 ( V_41 , V_7 ) ;
if ( V_84 )
return V_84 ;
F_85 ( V_41 , 0 ) ;
F_78 ( V_41 , V_7 ) ;
V_7 -> V_92 = 0 ;
F_64 ( & F_45 ( V_41 ) -> V_71 , V_97 ) ;
return 0 ;
}
unsigned char * F_86 ( struct V_6 * V_7 , T_4 V_105 , T_5 * V_16 )
{
struct V_106 * V_107 = V_7 -> V_108 -> V_109 ;
struct V_110 * V_110 ;
V_110 = F_87 ( V_107 , ( V_111 ) ( V_105 >> ( V_112 - 9 ) ) ,
NULL ) ;
if ( ! F_76 ( V_110 ) ) {
if ( F_88 ( V_110 ) )
goto V_113;
V_16 -> V_114 = V_110 ;
return ( unsigned char * ) F_89 ( V_110 ) + ( ( V_105 & ( ( 1 << ( V_112 - 9 ) ) - 1 ) ) << 9 ) ;
V_113:
F_90 ( V_110 ) ;
}
V_16 -> V_114 = NULL ;
return NULL ;
}
