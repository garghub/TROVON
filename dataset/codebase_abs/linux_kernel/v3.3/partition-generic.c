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
return sprintf ( V_4 , L_6 , ( unsigned long long ) V_16 -> V_18 ) ;
}
static T_2 F_11 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_5 , V_16 -> V_19 ? 1 : 0 ) ;
}
static T_2 F_12 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_6 , ( unsigned long long ) V_16 -> V_20 ) ;
}
static T_2 F_13 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_7 , V_16 -> V_21 ) ;
}
T_2 F_14 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
int V_22 ;
V_22 = F_15 () ;
F_16 ( V_22 , V_16 ) ;
F_17 () ;
return sprintf ( V_4 ,
L_8
L_8
L_9
L_10 ,
F_18 ( V_16 , V_23 [ V_24 ] ) ,
F_18 ( V_16 , V_25 [ V_24 ] ) ,
( unsigned long long ) F_18 ( V_16 , V_26 [ V_24 ] ) ,
F_19 ( F_18 ( V_16 , V_27 [ V_24 ] ) ) ,
F_18 ( V_16 , V_23 [ V_28 ] ) ,
F_18 ( V_16 , V_25 [ V_28 ] ) ,
( unsigned long long ) F_18 ( V_16 , V_26 [ V_28 ] ) ,
F_19 ( F_18 ( V_16 , V_27 [ V_28 ] ) ) ,
F_20 ( V_16 ) ,
F_19 ( F_18 ( V_16 , V_29 ) ) ,
F_19 ( F_18 ( V_16 , V_30 ) ) ) ;
}
T_2 F_21 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_11 , F_22 ( & V_16 -> V_31 [ 0 ] ) ,
F_22 ( & V_16 -> V_31 [ 1 ] ) ) ;
}
T_2 F_23 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_5 , V_16 -> V_32 ) ;
}
T_2 F_24 ( struct V_12 * V_10 ,
struct V_13 * V_14 ,
const char * V_4 , T_3 V_33 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
int V_34 ;
if ( V_33 > 0 && sscanf ( V_4 , L_12 , & V_34 ) > 0 )
V_16 -> V_32 = ( V_34 == 0 ) ? 0 : 1 ;
return V_33 ;
}
static void F_25 ( struct V_12 * V_10 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
F_26 ( V_16 ) ;
F_27 ( V_16 ) ;
F_28 ( V_16 ) ;
}
static void F_29 ( struct V_35 * V_36 )
{
struct V_15 * V_37 = F_30 ( V_36 , struct V_15 , V_35 ) ;
V_37 -> V_17 = 0 ;
V_37 -> V_18 = 0 ;
F_31 ( V_37 , 0 ) ;
F_32 ( F_33 ( V_37 ) ) ;
}
void F_34 ( struct V_15 * V_37 )
{
F_35 ( & V_37 -> V_35 , F_29 ) ;
}
void F_36 ( struct V_1 * V_38 , int V_3 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_15 * V_37 ;
if ( V_3 >= V_40 -> V_42 )
return;
V_37 = V_40 -> V_37 [ V_3 ] ;
if ( ! V_37 )
return;
F_37 ( F_38 ( V_37 ) ) ;
F_39 ( V_40 -> V_37 [ V_3 ] , NULL ) ;
F_39 ( V_40 -> V_43 , NULL ) ;
F_40 ( V_37 -> V_44 ) ;
F_41 ( F_33 ( V_37 ) ) ;
F_42 ( V_37 ) ;
}
static T_2 F_43 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
return 0 ;
}
struct V_15 * F_44 ( struct V_1 * V_38 , int V_3 ,
T_4 V_45 , T_4 V_42 , int V_46 ,
struct V_47 * V_48 )
{
struct V_15 * V_16 ;
T_1 V_49 = F_45 ( 0 , 0 ) ;
struct V_12 * V_50 = F_46 ( V_38 ) ;
struct V_12 * V_51 ;
struct V_39 * V_40 ;
const char * V_52 ;
int V_53 ;
V_53 = F_47 ( V_38 , V_3 ) ;
if ( V_53 )
return F_48 ( V_53 ) ;
V_40 = V_38 -> V_41 ;
if ( V_40 -> V_37 [ V_3 ] )
return F_48 ( - V_54 ) ;
V_16 = F_49 ( sizeof( * V_16 ) , V_55 ) ;
if ( ! V_16 )
return F_48 ( - V_54 ) ;
if ( ! F_50 ( V_16 ) ) {
V_53 = - V_56 ;
goto V_57;
}
V_51 = F_33 ( V_16 ) ;
V_16 -> V_17 = V_45 ;
V_16 -> V_20 =
F_51 ( & V_38 -> V_58 -> V_59 , V_45 ) ;
V_16 -> V_21 =
F_52 ( & V_38 -> V_58 -> V_59 , V_45 ) ;
V_16 -> V_18 = V_42 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_19 = F_53 ( V_38 ) ;
if ( V_48 ) {
struct V_47 * V_60 = F_54 ( V_38 ) ;
if ( ! V_60 )
goto V_61;
memcpy ( V_60 , V_48 , sizeof( * V_48 ) ) ;
V_16 -> V_48 = V_60 ;
}
V_52 = F_55 ( V_50 ) ;
if ( isdigit ( V_52 [ strlen ( V_52 ) - 1 ] ) )
F_56 ( V_51 , L_2 , V_52 , V_3 ) ;
else
F_56 ( V_51 , L_3 , V_52 , V_3 ) ;
F_57 ( V_51 ) ;
V_51 -> V_62 = & V_63 ;
V_51 -> type = & V_64 ;
V_51 -> V_65 = V_50 ;
V_53 = F_58 ( V_16 , & V_49 ) ;
if ( V_53 )
goto V_66;
V_51 -> V_49 = V_49 ;
F_59 ( V_51 , 1 ) ;
V_53 = F_60 ( V_51 ) ;
if ( V_53 )
goto V_67;
V_53 = - V_56 ;
V_16 -> V_44 = F_61 ( L_13 , & V_51 -> V_68 ) ;
if ( ! V_16 -> V_44 )
goto V_69;
F_59 ( V_51 , 0 ) ;
if ( V_46 & V_70 ) {
V_53 = F_62 ( V_51 , & V_71 ) ;
if ( V_53 )
goto V_69;
}
F_39 ( V_40 -> V_37 [ V_3 ] , V_16 ) ;
if ( ! F_63 ( V_50 ) )
F_64 ( & V_51 -> V_68 , V_72 ) ;
F_65 ( V_16 ) ;
return V_16 ;
V_66:
F_27 ( V_16 ) ;
V_61:
F_26 ( V_16 ) ;
V_57:
F_28 ( V_16 ) ;
return F_48 ( V_53 ) ;
V_69:
F_40 ( V_16 -> V_44 ) ;
F_41 ( V_51 ) ;
V_67:
F_32 ( V_51 ) ;
F_37 ( V_49 ) ;
return F_48 ( V_53 ) ;
}
static bool F_66 ( struct V_1 * V_38 )
{
const struct V_73 * V_74 = V_38 -> V_75 ;
if ( V_74 -> V_76 &&
! ( V_38 -> V_46 & V_77 ) ) {
F_67 ( V_78 L_14 ) ;
V_74 -> V_76 ( V_38 ) ;
V_38 -> V_46 |= V_77 ;
return true ;
} else {
F_67 ( V_78 L_15 ) ;
return false ;
}
}
static int F_68 ( struct V_1 * V_38 , struct V_6 * V_7 )
{
struct V_79 V_80 ;
struct V_15 * V_37 ;
int V_81 ;
if ( V_7 -> V_82 )
return - V_54 ;
V_81 = F_69 ( V_38 , 0 ) ;
if ( V_81 )
return V_81 ;
F_70 ( & V_80 , V_38 , V_83 ) ;
while ( ( V_37 = F_71 ( & V_80 ) ) )
F_36 ( V_38 , V_37 -> V_3 ) ;
F_72 ( & V_80 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_38 , struct V_6 * V_7 )
{
struct V_84 * V_85 = NULL ;
struct V_15 * V_37 ;
int V_16 , V_86 , V_81 ;
V_87:
if ( V_85 && ! F_74 ( V_85 ) ) {
F_28 ( V_85 ) ;
V_85 = NULL ;
}
V_81 = F_68 ( V_38 , V_7 ) ;
if ( V_81 )
return V_81 ;
if ( V_38 -> V_75 -> V_88 )
V_38 -> V_75 -> V_88 ( V_38 ) ;
F_75 ( V_38 , V_7 ) ;
V_7 -> V_89 = 0 ;
if ( ! F_76 ( V_38 ) || ! ( V_85 = F_77 ( V_38 , V_7 ) ) )
return 0 ;
if ( F_74 ( V_85 ) ) {
if ( F_78 ( V_85 ) == - V_90 ) {
F_67 ( V_91 L_16 ,
V_38 -> F_1 ) ;
if ( F_66 ( V_38 ) )
goto V_87;
}
return - V_92 ;
}
if ( V_85 -> V_93 ) {
F_67 ( V_91
L_17 ,
V_38 -> F_1 ) ;
if ( F_66 ( V_38 ) )
goto V_87;
}
F_64 ( & F_46 ( V_38 ) -> V_68 , V_94 ) ;
for ( V_16 = 1 , V_86 = 0 ; V_16 < V_85 -> V_95 ; V_16 ++ )
if ( V_85 -> V_96 [ V_16 ] . V_97 )
V_86 = V_16 ;
F_47 ( V_38 , V_86 ) ;
for ( V_16 = 1 ; V_16 < V_85 -> V_95 ; V_16 ++ ) {
T_4 V_97 , V_98 ;
struct V_47 * V_48 = NULL ;
V_97 = V_85 -> V_96 [ V_16 ] . V_97 ;
if ( ! V_97 )
continue;
V_98 = V_85 -> V_96 [ V_16 ] . V_98 ;
if ( V_98 >= F_76 ( V_38 ) ) {
F_67 ( V_91
L_18 ,
V_38 -> F_1 , V_16 , ( unsigned long long ) V_98 ) ;
if ( F_66 ( V_38 ) )
goto V_87;
continue;
}
if ( V_98 + V_97 > F_76 ( V_38 ) ) {
F_67 ( V_91
L_19 ,
V_38 -> F_1 , V_16 , ( unsigned long long ) V_97 ) ;
if ( F_66 ( V_38 ) ) {
goto V_87;
} else {
V_97 = F_76 ( V_38 ) - V_98 ;
}
}
if ( V_85 -> V_96 [ V_16 ] . V_99 )
V_48 = & V_85 -> V_96 [ V_16 ] . V_48 ;
V_37 = F_44 ( V_38 , V_16 , V_98 , V_97 ,
V_85 -> V_96 [ V_16 ] . V_46 ,
& V_85 -> V_96 [ V_16 ] . V_48 ) ;
if ( F_74 ( V_37 ) ) {
F_67 ( V_100 L_20 ,
V_38 -> F_1 , V_16 , - F_78 ( V_37 ) ) ;
continue;
}
#ifdef F_79
if ( V_85 -> V_96 [ V_16 ] . V_46 & V_101 )
F_80 ( F_33 ( V_37 ) -> V_49 ) ;
#endif
}
F_28 ( V_85 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_38 , struct V_6 * V_7 )
{
int V_81 ;
if ( ! V_7 -> V_89 )
return 0 ;
V_81 = F_68 ( V_38 , V_7 ) ;
if ( V_81 )
return V_81 ;
F_82 ( V_38 , 0 ) ;
F_75 ( V_38 , V_7 ) ;
V_7 -> V_89 = 0 ;
F_64 ( & F_46 ( V_38 ) -> V_68 , V_94 ) ;
return 0 ;
}
unsigned char * F_83 ( struct V_6 * V_7 , T_4 V_102 , T_5 * V_16 )
{
struct V_103 * V_104 = V_7 -> V_105 -> V_106 ;
struct V_107 * V_107 ;
V_107 = F_84 ( V_104 , ( V_108 ) ( V_102 >> ( V_109 - 9 ) ) ,
NULL ) ;
if ( ! F_74 ( V_107 ) ) {
if ( F_85 ( V_107 ) )
goto V_110;
V_16 -> V_111 = V_107 ;
return ( unsigned char * ) F_86 ( V_107 ) + ( ( V_102 & ( ( 1 << ( V_109 - 9 ) ) - 1 ) ) << 9 ) ;
V_110:
F_87 ( V_107 ) ;
}
V_16 -> V_111 = NULL ;
return NULL ;
}
