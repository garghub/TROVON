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
F_30 ( V_16 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_15 * V_37 = F_32 ( V_36 , struct V_15 , V_35 ) ;
V_37 -> V_17 = 0 ;
V_37 -> V_38 = 0 ;
F_33 ( V_37 , 0 ) ;
F_34 ( F_35 ( V_37 ) ) ;
}
void F_36 ( struct V_15 * V_37 )
{
F_37 ( & V_37 -> V_35 , F_31 ) ;
}
void F_38 ( struct V_1 * V_39 , int V_3 )
{
struct V_40 * V_41 = V_39 -> V_42 ;
struct V_15 * V_37 ;
if ( V_3 >= V_41 -> V_43 )
return;
V_37 = V_41 -> V_37 [ V_3 ] ;
if ( ! V_37 )
return;
F_39 ( V_41 -> V_37 [ V_3 ] , NULL ) ;
F_39 ( V_41 -> V_44 , NULL ) ;
F_40 ( V_37 -> V_45 ) ;
F_41 ( F_35 ( V_37 ) ) ;
F_42 ( V_37 ) ;
}
static T_2 F_43 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
return 0 ;
}
struct V_15 * F_44 ( struct V_1 * V_39 , int V_3 ,
T_4 V_46 , T_4 V_43 , int V_47 ,
struct V_48 * V_49 )
{
struct V_15 * V_16 ;
T_1 V_34 = F_45 ( 0 , 0 ) ;
struct V_12 * V_50 = F_46 ( V_39 ) ;
struct V_12 * V_51 ;
struct V_40 * V_41 ;
const char * V_52 ;
int V_53 ;
V_53 = F_47 ( V_39 , V_3 ) ;
if ( V_53 )
return F_48 ( V_53 ) ;
V_41 = V_39 -> V_42 ;
if ( V_41 -> V_37 [ V_3 ] )
return F_48 ( - V_54 ) ;
V_16 = F_49 ( sizeof( * V_16 ) , V_55 ) ;
if ( ! V_16 )
return F_48 ( - V_54 ) ;
if ( ! F_50 ( V_16 ) ) {
V_53 = - V_56 ;
goto V_57;
}
F_51 ( & V_16 -> V_58 ) ;
V_51 = F_35 ( V_16 ) ;
V_16 -> V_17 = V_46 ;
V_16 -> V_19 =
F_52 ( & V_39 -> V_59 -> V_60 , V_46 ) ;
V_16 -> V_20 =
F_53 ( & V_39 -> V_59 -> V_60 , V_46 ) ;
V_16 -> V_38 = V_43 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_18 = F_54 ( V_39 ) ;
if ( V_49 ) {
struct V_48 * V_61 = F_55 ( V_39 ) ;
if ( ! V_61 )
goto V_62;
memcpy ( V_61 , V_49 , sizeof( * V_49 ) ) ;
V_16 -> V_49 = V_61 ;
}
V_52 = F_56 ( V_50 ) ;
if ( isdigit ( V_52 [ strlen ( V_52 ) - 1 ] ) )
F_57 ( V_51 , L_2 , V_52 , V_3 ) ;
else
F_57 ( V_51 , L_3 , V_52 , V_3 ) ;
F_58 ( V_51 ) ;
V_51 -> V_63 = & V_64 ;
V_51 -> type = & V_65 ;
V_51 -> V_66 = V_50 ;
V_53 = F_59 ( V_16 , & V_34 ) ;
if ( V_53 )
goto V_67;
V_51 -> V_34 = V_34 ;
F_60 ( V_51 , 1 ) ;
V_53 = F_61 ( V_51 ) ;
if ( V_53 )
goto V_68;
V_53 = - V_56 ;
V_16 -> V_45 = F_62 ( L_13 , & V_51 -> V_69 ) ;
if ( ! V_16 -> V_45 )
goto V_70;
F_60 ( V_51 , 0 ) ;
if ( V_47 & V_71 ) {
V_53 = F_63 ( V_51 , & V_72 ) ;
if ( V_53 )
goto V_70;
}
F_39 ( V_41 -> V_37 [ V_3 ] , V_16 ) ;
if ( ! F_64 ( V_50 ) )
F_65 ( & V_51 -> V_69 , V_73 ) ;
F_66 ( V_16 ) ;
return V_16 ;
V_67:
F_29 ( V_16 ) ;
V_62:
F_28 ( V_16 ) ;
V_57:
F_30 ( V_16 ) ;
return F_48 ( V_53 ) ;
V_70:
F_40 ( V_16 -> V_45 ) ;
F_41 ( V_51 ) ;
V_68:
F_34 ( V_51 ) ;
F_27 ( V_34 ) ;
return F_48 ( V_53 ) ;
}
static bool F_67 ( struct V_1 * V_39 )
{
const struct V_74 * V_75 = V_39 -> V_76 ;
if ( V_75 -> V_77 &&
! ( V_39 -> V_47 & V_78 ) ) {
F_68 ( V_79 L_14 ) ;
V_75 -> V_77 ( V_39 ) ;
V_39 -> V_47 |= V_78 ;
return true ;
} else {
F_68 ( V_79 L_15 ) ;
return false ;
}
}
static int F_69 ( struct V_1 * V_39 , struct V_6 * V_7 )
{
struct V_80 V_81 ;
struct V_15 * V_37 ;
int V_82 ;
if ( V_7 -> V_83 )
return - V_54 ;
V_82 = F_70 ( V_39 , 0 ) ;
if ( V_82 )
return V_82 ;
F_71 ( & V_81 , V_39 , V_84 ) ;
while ( ( V_37 = F_72 ( & V_81 ) ) )
F_38 ( V_39 , V_37 -> V_3 ) ;
F_73 ( & V_81 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_39 , struct V_6 * V_7 )
{
struct V_85 * V_86 = NULL ;
struct V_15 * V_37 ;
int V_16 , V_87 , V_82 ;
V_88:
if ( V_86 && ! F_75 ( V_86 ) ) {
F_76 ( V_86 ) ;
V_86 = NULL ;
}
V_82 = F_69 ( V_39 , V_7 ) ;
if ( V_82 )
return V_82 ;
if ( V_39 -> V_76 -> V_89 )
V_39 -> V_76 -> V_89 ( V_39 ) ;
F_77 ( V_39 , V_7 ) ;
V_7 -> V_90 = 0 ;
if ( ! F_78 ( V_39 ) || ! ( V_86 = F_79 ( V_39 , V_7 ) ) )
return 0 ;
if ( F_75 ( V_86 ) ) {
if ( F_80 ( V_86 ) == - V_91 ) {
F_68 ( V_92 L_16 ,
V_39 -> F_1 ) ;
if ( F_67 ( V_39 ) )
goto V_88;
}
return - V_93 ;
}
if ( V_86 -> V_94 ) {
F_68 ( V_92
L_17 ,
V_39 -> F_1 ) ;
if ( F_67 ( V_39 ) )
goto V_88;
}
F_65 ( & F_46 ( V_39 ) -> V_69 , V_95 ) ;
for ( V_16 = 1 , V_87 = 0 ; V_16 < V_86 -> V_96 ; V_16 ++ )
if ( V_86 -> V_97 [ V_16 ] . V_98 )
V_87 = V_16 ;
F_47 ( V_39 , V_87 ) ;
for ( V_16 = 1 ; V_16 < V_86 -> V_96 ; V_16 ++ ) {
T_4 V_98 , V_99 ;
struct V_48 * V_49 = NULL ;
V_98 = V_86 -> V_97 [ V_16 ] . V_98 ;
if ( ! V_98 )
continue;
V_99 = V_86 -> V_97 [ V_16 ] . V_99 ;
if ( V_99 >= F_78 ( V_39 ) ) {
F_68 ( V_92
L_18 ,
V_39 -> F_1 , V_16 , ( unsigned long long ) V_99 ) ;
if ( F_67 ( V_39 ) )
goto V_88;
continue;
}
if ( V_99 + V_98 > F_78 ( V_39 ) ) {
F_68 ( V_92
L_19 ,
V_39 -> F_1 , V_16 , ( unsigned long long ) V_98 ) ;
if ( F_67 ( V_39 ) ) {
goto V_88;
} else {
V_98 = F_78 ( V_39 ) - V_99 ;
}
}
if ( V_86 -> V_97 [ V_16 ] . V_100 )
V_49 = & V_86 -> V_97 [ V_16 ] . V_49 ;
V_37 = F_44 ( V_39 , V_16 , V_99 , V_98 ,
V_86 -> V_97 [ V_16 ] . V_47 ,
& V_86 -> V_97 [ V_16 ] . V_49 ) ;
if ( F_75 ( V_37 ) ) {
F_68 ( V_101 L_20 ,
V_39 -> F_1 , V_16 , - F_80 ( V_37 ) ) ;
continue;
}
#ifdef F_81
if ( V_86 -> V_97 [ V_16 ] . V_47 & V_102 )
F_82 ( F_35 ( V_37 ) -> V_34 ) ;
#endif
}
F_76 ( V_86 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_39 , struct V_6 * V_7 )
{
int V_82 ;
if ( ! V_7 -> V_90 )
return 0 ;
V_82 = F_69 ( V_39 , V_7 ) ;
if ( V_82 )
return V_82 ;
F_84 ( V_39 , 0 ) ;
F_77 ( V_39 , V_7 ) ;
V_7 -> V_90 = 0 ;
F_65 ( & F_46 ( V_39 ) -> V_69 , V_95 ) ;
return 0 ;
}
unsigned char * F_85 ( struct V_6 * V_7 , T_4 V_103 , T_5 * V_16 )
{
struct V_104 * V_105 = V_7 -> V_106 -> V_107 ;
struct V_108 * V_108 ;
V_108 = F_86 ( V_105 , ( V_109 ) ( V_103 >> ( V_110 - 9 ) ) ,
NULL ) ;
if ( ! F_75 ( V_108 ) ) {
if ( F_87 ( V_108 ) )
goto V_111;
V_16 -> V_112 = V_108 ;
return ( unsigned char * ) F_88 ( V_108 ) + ( ( V_103 & ( ( 1 << ( V_110 - 9 ) ) - 1 ) ) << 9 ) ;
V_111:
F_89 ( V_108 ) ;
}
V_16 -> V_112 = NULL ;
return NULL ;
}
