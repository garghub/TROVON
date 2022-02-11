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
static struct V_12 *
F_7 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_12 * V_13 ;
int V_14 , V_15 , V_16 ;
V_13 = F_8 ( sizeof( struct V_12 ) , V_17 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_18 = ( char * ) F_9 ( V_17 ) ;
if ( ! V_13 -> V_18 ) {
F_10 ( V_13 ) ;
return NULL ;
}
V_13 -> V_18 [ 0 ] = '\0' ;
V_13 -> V_7 = V_7 ;
F_1 ( V_2 , 0 , V_13 -> V_19 ) ;
snprintf ( V_13 -> V_18 , V_20 , L_5 , V_13 -> V_19 ) ;
if ( isdigit ( V_13 -> V_19 [ strlen ( V_13 -> V_19 ) - 1 ] ) )
sprintf ( V_13 -> V_19 , L_6 ) ;
V_13 -> V_21 = F_11 ( V_2 ) ;
V_14 = V_15 = V_16 = 0 ;
while ( ! V_15 && V_22 [ V_14 ] ) {
memset ( & V_13 -> V_23 , 0 , sizeof( V_13 -> V_23 ) ) ;
V_15 = V_22 [ V_14 ++ ] ( V_13 ) ;
if ( V_15 < 0 ) {
V_16 = V_15 ;
V_15 = 0 ;
}
}
if ( V_15 > 0 ) {
F_12 ( V_24 L_1 , V_13 -> V_18 ) ;
F_13 ( ( unsigned long ) V_13 -> V_18 ) ;
return V_13 ;
}
if ( V_13 -> V_25 )
V_16 = - V_26 ;
if ( V_16 )
V_15 = V_16 ;
if ( ! V_15 )
F_14 ( V_13 -> V_18 , L_7 , V_20 ) ;
else if ( V_27 )
F_14 ( V_13 -> V_18 , L_8 , V_20 ) ;
F_12 ( V_24 L_1 , V_13 -> V_18 ) ;
F_13 ( ( unsigned long ) V_13 -> V_18 ) ;
F_10 ( V_13 ) ;
return F_15 ( V_15 ) ;
}
static T_2 F_16 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_9 , V_32 -> V_3 ) ;
}
static T_2 F_18 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_10 , ( unsigned long long ) V_32 -> V_33 ) ;
}
T_2 F_19 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_10 , ( unsigned long long ) V_32 -> V_34 ) ;
}
T_2 F_20 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_9 , V_32 -> V_35 ? 1 : 0 ) ;
}
T_2 F_21 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_10 , ( unsigned long long ) V_32 -> V_36 ) ;
}
T_2 F_22 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_11 , V_32 -> V_37 ) ;
}
T_2 F_23 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
int V_38 ;
V_38 = F_24 () ;
F_25 ( V_38 , V_32 ) ;
F_26 () ;
return sprintf ( V_4 ,
L_12
L_12
L_13
L_14 ,
F_27 ( V_32 , V_39 [ V_40 ] ) ,
F_27 ( V_32 , V_41 [ V_40 ] ) ,
( unsigned long long ) F_27 ( V_32 , V_42 [ V_40 ] ) ,
F_28 ( F_27 ( V_32 , V_43 [ V_40 ] ) ) ,
F_27 ( V_32 , V_39 [ V_44 ] ) ,
F_27 ( V_32 , V_41 [ V_44 ] ) ,
( unsigned long long ) F_27 ( V_32 , V_42 [ V_44 ] ) ,
F_28 ( F_27 ( V_32 , V_43 [ V_44 ] ) ) ,
F_29 ( V_32 ) ,
F_28 ( F_27 ( V_32 , V_45 ) ) ,
F_28 ( F_27 ( V_32 , V_46 ) ) ) ;
}
T_2 F_30 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_15 , F_31 ( & V_32 -> V_47 [ 0 ] ) ,
F_31 ( & V_32 -> V_47 [ 1 ] ) ) ;
}
T_2 F_32 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
return sprintf ( V_4 , L_9 , V_32 -> V_48 ) ;
}
T_2 F_33 ( struct V_28 * V_10 ,
struct V_29 * V_30 ,
const char * V_4 , T_3 V_49 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
int V_14 ;
if ( V_49 > 0 && sscanf ( V_4 , L_16 , & V_14 ) > 0 )
V_32 -> V_48 = ( V_14 == 0 ) ? 0 : 1 ;
return V_49 ;
}
static void F_34 ( struct V_28 * V_10 )
{
struct V_31 * V_32 = F_17 ( V_10 ) ;
F_35 ( V_32 ) ;
F_36 ( V_32 ) ;
F_10 ( V_32 ) ;
}
static void F_37 ( struct V_50 * V_51 )
{
struct V_31 * V_52 = F_38 ( V_51 , struct V_31 , V_50 ) ;
V_52 -> V_33 = 0 ;
V_52 -> V_34 = 0 ;
F_39 ( V_52 , 0 ) ;
F_40 ( F_41 ( V_52 ) ) ;
}
void F_42 ( struct V_31 * V_52 )
{
F_43 ( & V_52 -> V_50 , F_37 ) ;
}
void F_44 ( struct V_1 * V_53 , int V_3 )
{
struct V_54 * V_55 = V_53 -> V_56 ;
struct V_31 * V_52 ;
if ( V_3 >= V_55 -> V_57 )
return;
V_52 = V_55 -> V_52 [ V_3 ] ;
if ( ! V_52 )
return;
F_45 ( F_46 ( V_52 ) ) ;
F_47 ( V_55 -> V_52 [ V_3 ] , NULL ) ;
F_47 ( V_55 -> V_58 , NULL ) ;
F_48 ( V_52 -> V_59 ) ;
F_49 ( F_41 ( V_52 ) ) ;
F_50 ( V_52 ) ;
}
static T_2 F_51 ( struct V_28 * V_10 ,
struct V_29 * V_30 , char * V_4 )
{
return 0 ;
}
struct V_31 * F_52 ( struct V_1 * V_53 , int V_3 ,
T_4 V_60 , T_4 V_57 , int V_61 ,
struct V_62 * V_63 )
{
struct V_31 * V_32 ;
T_1 V_64 = F_53 ( 0 , 0 ) ;
struct V_28 * V_65 = F_54 ( V_53 ) ;
struct V_28 * V_66 ;
struct V_54 * V_55 ;
const char * V_67 ;
int V_16 ;
V_16 = F_55 ( V_53 , V_3 ) ;
if ( V_16 )
return F_15 ( V_16 ) ;
V_55 = V_53 -> V_56 ;
if ( V_55 -> V_52 [ V_3 ] )
return F_15 ( - V_68 ) ;
V_32 = F_8 ( sizeof( * V_32 ) , V_17 ) ;
if ( ! V_32 )
return F_15 ( - V_68 ) ;
if ( ! F_56 ( V_32 ) ) {
V_16 = - V_69 ;
goto V_70;
}
V_66 = F_41 ( V_32 ) ;
V_32 -> V_33 = V_60 ;
V_32 -> V_36 =
F_57 ( & V_53 -> V_71 -> V_72 , V_60 ) ;
V_32 -> V_37 =
F_58 ( & V_53 -> V_71 -> V_72 , V_60 ) ;
V_32 -> V_34 = V_57 ;
V_32 -> V_3 = V_3 ;
V_32 -> V_35 = F_59 ( V_53 ) ;
if ( V_63 ) {
struct V_62 * V_73 = F_60 ( V_53 ) ;
if ( ! V_73 )
goto V_74;
memcpy ( V_73 , V_63 , sizeof( * V_63 ) ) ;
V_32 -> V_63 = V_73 ;
}
V_67 = F_61 ( V_65 ) ;
if ( isdigit ( V_67 [ strlen ( V_67 ) - 1 ] ) )
F_62 ( V_66 , L_2 , V_67 , V_3 ) ;
else
F_62 ( V_66 , L_3 , V_67 , V_3 ) ;
F_63 ( V_66 ) ;
V_66 -> V_75 = & V_76 ;
V_66 -> type = & V_77 ;
V_66 -> V_78 = V_65 ;
V_16 = F_64 ( V_32 , & V_64 ) ;
if ( V_16 )
goto V_79;
V_66 -> V_64 = V_64 ;
F_65 ( V_66 , 1 ) ;
V_16 = F_66 ( V_66 ) ;
if ( V_16 )
goto V_80;
V_16 = - V_69 ;
V_32 -> V_59 = F_67 ( L_17 , & V_66 -> V_81 ) ;
if ( ! V_32 -> V_59 )
goto V_82;
F_65 ( V_66 , 0 ) ;
if ( V_61 & V_83 ) {
V_16 = F_68 ( V_66 , & V_84 ) ;
if ( V_16 )
goto V_82;
}
F_47 ( V_55 -> V_52 [ V_3 ] , V_32 ) ;
if ( ! F_69 ( V_65 ) )
F_70 ( & V_66 -> V_81 , V_85 ) ;
F_71 ( V_32 ) ;
return V_32 ;
V_79:
F_36 ( V_32 ) ;
V_74:
F_35 ( V_32 ) ;
V_70:
F_10 ( V_32 ) ;
return F_15 ( V_16 ) ;
V_82:
F_48 ( V_32 -> V_59 ) ;
F_49 ( V_66 ) ;
V_80:
F_40 ( V_66 ) ;
F_45 ( V_64 ) ;
return F_15 ( V_16 ) ;
}
static bool F_72 ( struct V_1 * V_53 )
{
const struct V_86 * V_87 = V_53 -> V_88 ;
if ( V_87 -> V_89 &&
! ( V_53 -> V_61 & V_90 ) ) {
F_12 ( V_91 L_18 ) ;
V_87 -> V_89 ( V_53 ) ;
V_53 -> V_61 |= V_90 ;
return true ;
} else {
F_12 ( V_91 L_19 ) ;
return false ;
}
}
int F_73 ( struct V_1 * V_53 , struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
struct V_92 V_93 ;
struct V_31 * V_52 ;
int V_32 , V_94 , V_15 ;
V_95:
if ( V_13 && ! F_74 ( V_13 ) ) {
F_10 ( V_13 ) ;
V_13 = NULL ;
}
if ( V_7 -> V_96 )
return - V_68 ;
V_15 = F_75 ( V_53 , 0 ) ;
if ( V_15 )
return V_15 ;
F_76 ( & V_93 , V_53 , V_97 ) ;
while ( ( V_52 = F_77 ( & V_93 ) ) )
F_44 ( V_53 , V_52 -> V_3 ) ;
F_78 ( & V_93 ) ;
if ( V_53 -> V_88 -> V_98 )
V_53 -> V_88 -> V_98 ( V_53 ) ;
F_79 ( V_53 , V_7 ) ;
V_7 -> V_99 = 0 ;
if ( ! F_80 ( V_53 ) || ! ( V_13 = F_7 ( V_53 , V_7 ) ) )
return 0 ;
if ( F_74 ( V_13 ) ) {
if ( F_81 ( V_13 ) == - V_26 ) {
F_12 ( V_100 L_20 ,
V_53 -> F_1 ) ;
if ( F_72 ( V_53 ) )
goto V_95;
}
return - V_101 ;
}
if ( V_13 -> V_25 ) {
F_12 ( V_100
L_21 ,
V_53 -> F_1 ) ;
if ( F_72 ( V_53 ) )
goto V_95;
}
F_70 ( & F_54 ( V_53 ) -> V_81 , V_102 ) ;
for ( V_32 = 1 , V_94 = 0 ; V_32 < V_13 -> V_21 ; V_32 ++ )
if ( V_13 -> V_23 [ V_32 ] . V_103 )
V_94 = V_32 ;
F_55 ( V_53 , V_94 ) ;
for ( V_32 = 1 ; V_32 < V_13 -> V_21 ; V_32 ++ ) {
T_4 V_103 , V_104 ;
struct V_62 * V_63 = NULL ;
V_103 = V_13 -> V_23 [ V_32 ] . V_103 ;
if ( ! V_103 )
continue;
V_104 = V_13 -> V_23 [ V_32 ] . V_104 ;
if ( V_104 >= F_80 ( V_53 ) ) {
F_12 ( V_100
L_22 ,
V_53 -> F_1 , V_32 , ( unsigned long long ) V_104 ) ;
if ( F_72 ( V_53 ) )
goto V_95;
continue;
}
if ( V_104 + V_103 > F_80 ( V_53 ) ) {
F_12 ( V_100
L_23 ,
V_53 -> F_1 , V_32 , ( unsigned long long ) V_103 ) ;
if ( F_72 ( V_53 ) ) {
goto V_95;
} else {
V_103 = F_80 ( V_53 ) - V_104 ;
}
}
if ( V_13 -> V_23 [ V_32 ] . V_105 )
V_63 = & V_13 -> V_23 [ V_32 ] . V_63 ;
V_52 = F_52 ( V_53 , V_32 , V_104 , V_103 ,
V_13 -> V_23 [ V_32 ] . V_61 ,
& V_13 -> V_23 [ V_32 ] . V_63 ) ;
if ( F_74 ( V_52 ) ) {
F_12 ( V_106 L_24 ,
V_53 -> F_1 , V_32 , - F_81 ( V_52 ) ) ;
continue;
}
#ifdef F_82
if ( V_13 -> V_23 [ V_32 ] . V_61 & V_107 )
F_83 ( F_41 ( V_52 ) -> V_64 ) ;
#endif
}
F_10 ( V_13 ) ;
return 0 ;
}
unsigned char * F_84 ( struct V_6 * V_7 , T_4 V_108 , T_5 * V_32 )
{
struct V_109 * V_110 = V_7 -> V_111 -> V_112 ;
struct V_113 * V_113 ;
V_113 = F_85 ( V_110 , ( V_114 ) ( V_108 >> ( V_115 - 9 ) ) ,
NULL ) ;
if ( ! F_74 ( V_113 ) ) {
if ( F_86 ( V_113 ) )
goto V_116;
V_32 -> V_117 = V_113 ;
return ( unsigned char * ) F_87 ( V_113 ) + ( ( V_108 & ( ( 1 << ( V_115 - 9 ) ) - 1 ) ) << 9 ) ;
V_116:
F_88 ( V_113 ) ;
}
V_32 -> V_117 = NULL ;
return NULL ;
}
