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
struct V_21 * V_22 = F_16 ( V_16 ) -> V_23 ;
unsigned int V_24 [ 2 ] ;
int V_25 ;
V_25 = F_17 () ;
F_18 ( V_22 , V_25 , V_16 ) ;
F_19 () ;
F_20 ( V_22 , V_16 , V_24 ) ;
return sprintf ( V_4 ,
L_8
L_8
L_9
L_10 ,
F_21 ( V_16 , V_26 [ V_27 ] ) ,
F_21 ( V_16 , V_28 [ V_27 ] ) ,
( unsigned long long ) F_21 ( V_16 , V_29 [ V_27 ] ) ,
F_22 ( F_21 ( V_16 , V_30 [ V_27 ] ) ) ,
F_21 ( V_16 , V_26 [ V_31 ] ) ,
F_21 ( V_16 , V_28 [ V_31 ] ) ,
( unsigned long long ) F_21 ( V_16 , V_29 [ V_31 ] ) ,
F_22 ( F_21 ( V_16 , V_30 [ V_31 ] ) ) ,
V_24 [ 0 ] ,
F_22 ( F_21 ( V_16 , V_32 ) ) ,
F_22 ( F_21 ( V_16 , V_33 ) ) ) ;
}
T_2 F_23 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_11 , F_24 ( & V_16 -> V_34 [ 0 ] ) ,
F_24 ( & V_16 -> V_34 [ 1 ] ) ) ;
}
T_2 F_25 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
return sprintf ( V_4 , L_5 , V_16 -> V_35 ) ;
}
T_2 F_26 ( struct V_12 * V_10 ,
struct V_13 * V_14 ,
const char * V_4 , T_3 V_36 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
int V_37 ;
if ( V_36 > 0 && sscanf ( V_4 , L_12 , & V_37 ) > 0 )
V_16 -> V_35 = ( V_37 == 0 ) ? 0 : 1 ;
return V_36 ;
}
static void F_27 ( struct V_12 * V_10 )
{
struct V_15 * V_16 = F_8 ( V_10 ) ;
F_28 ( V_10 -> V_38 ) ;
F_29 ( V_16 ) ;
F_30 ( V_16 ) ;
}
static int F_31 ( struct V_12 * V_10 , struct V_39 * V_40 )
{
struct V_15 * V_41 = F_8 ( V_10 ) ;
F_32 ( V_40 , L_13 , V_41 -> V_3 ) ;
if ( V_41 -> V_42 && V_41 -> V_42 -> V_43 [ 0 ] )
F_32 ( V_40 , L_14 , V_41 -> V_42 -> V_43 ) ;
return 0 ;
}
static void F_33 ( struct V_44 * V_45 )
{
struct V_15 * V_41 = F_34 ( V_45 , struct V_15 , V_44 ) ;
V_41 -> V_17 = 0 ;
V_41 -> V_46 = 0 ;
F_35 ( V_41 , 0 ) ;
F_36 ( F_37 ( V_41 ) ) ;
}
void F_38 ( struct V_47 * V_48 )
{
struct V_15 * V_41 = F_34 ( V_48 , struct V_15 , V_48 ) ;
F_39 ( & V_41 -> V_44 , F_33 ) ;
}
void F_40 ( struct V_1 * V_49 , int V_3 )
{
struct V_50 * V_51 =
F_41 ( V_49 -> V_52 , 1 ) ;
struct V_15 * V_41 ;
if ( V_3 >= V_51 -> V_53 )
return;
V_41 = F_41 ( V_51 -> V_41 [ V_3 ] , 1 ) ;
if ( ! V_41 )
return;
F_42 ( V_51 -> V_41 [ V_3 ] , NULL ) ;
F_42 ( V_51 -> V_54 , NULL ) ;
F_43 ( V_41 -> V_55 ) ;
F_44 ( F_37 ( V_41 ) ) ;
F_45 ( V_41 ) ;
}
static T_2 F_46 ( struct V_12 * V_10 ,
struct V_13 * V_14 , char * V_4 )
{
return 0 ;
}
struct V_15 * F_47 ( struct V_1 * V_49 , int V_3 ,
T_4 V_56 , T_4 V_53 , int V_57 ,
struct V_58 * V_42 )
{
struct V_15 * V_16 ;
T_1 V_38 = F_48 ( 0 , 0 ) ;
struct V_12 * V_59 = F_49 ( V_49 ) ;
struct V_12 * V_60 ;
struct V_50 * V_51 ;
const char * V_61 ;
int V_62 ;
V_62 = F_50 ( V_49 , V_3 ) ;
if ( V_62 )
return F_51 ( V_62 ) ;
V_51 = F_41 ( V_49 -> V_52 , 1 ) ;
if ( V_51 -> V_41 [ V_3 ] )
return F_51 ( - V_63 ) ;
V_16 = F_52 ( sizeof( * V_16 ) , V_64 ) ;
if ( ! V_16 )
return F_51 ( - V_63 ) ;
if ( ! F_53 ( V_16 ) ) {
V_62 = - V_65 ;
goto V_66;
}
F_54 ( & V_16 -> V_67 ) ;
V_60 = F_37 ( V_16 ) ;
V_16 -> V_17 = V_56 ;
V_16 -> V_19 =
F_55 ( & V_49 -> V_23 -> V_68 , V_56 ) ;
V_16 -> V_20 =
F_56 ( & V_49 -> V_23 -> V_68 , V_56 ) ;
V_16 -> V_46 = V_53 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_18 = F_57 ( V_49 ) ;
if ( V_42 ) {
struct V_58 * V_69 = F_58 ( V_49 ) ;
if ( ! V_69 ) {
V_62 = - V_65 ;
goto V_70;
}
memcpy ( V_69 , V_42 , sizeof( * V_42 ) ) ;
V_16 -> V_42 = V_69 ;
}
V_61 = F_59 ( V_59 ) ;
if ( isdigit ( V_61 [ strlen ( V_61 ) - 1 ] ) )
F_60 ( V_60 , L_2 , V_61 , V_3 ) ;
else
F_60 ( V_60 , L_3 , V_61 , V_3 ) ;
F_61 ( V_60 ) ;
V_60 -> V_71 = & V_72 ;
V_60 -> type = & V_73 ;
V_60 -> V_74 = V_59 ;
V_62 = F_62 ( V_16 , & V_38 ) ;
if ( V_62 )
goto V_75;
V_60 -> V_38 = V_38 ;
F_63 ( V_60 , 1 ) ;
V_62 = F_64 ( V_60 ) ;
if ( V_62 )
goto V_76;
V_62 = - V_65 ;
V_16 -> V_55 = F_65 ( L_15 , & V_60 -> V_77 ) ;
if ( ! V_16 -> V_55 )
goto V_78;
F_63 ( V_60 , 0 ) ;
if ( V_57 & V_79 ) {
V_62 = F_66 ( V_60 , & V_80 ) ;
if ( V_62 )
goto V_78;
}
V_62 = F_67 ( V_16 ) ;
if ( V_62 ) {
if ( V_57 & V_79 )
goto V_81;
goto V_78;
}
F_42 ( V_51 -> V_41 [ V_3 ] , V_16 ) ;
if ( ! F_68 ( V_59 ) )
F_69 ( & V_60 -> V_77 , V_82 ) ;
return V_16 ;
V_75:
F_70 ( V_16 ) ;
V_70:
F_71 ( V_16 ) ;
V_66:
F_30 ( V_16 ) ;
return F_51 ( V_62 ) ;
V_81:
F_72 ( V_60 , & V_80 ) ;
V_78:
F_43 ( V_16 -> V_55 ) ;
F_44 ( V_60 ) ;
V_76:
F_36 ( V_60 ) ;
return F_51 ( V_62 ) ;
}
static bool F_73 ( struct V_1 * V_49 )
{
const struct V_83 * V_84 = V_49 -> V_85 ;
if ( V_84 -> V_86 &&
! ( V_49 -> V_57 & V_87 ) ) {
F_74 ( V_88 L_16 ) ;
V_84 -> V_86 ( V_49 ) ;
V_49 -> V_57 |= V_87 ;
return true ;
} else {
F_74 ( V_88 L_17 ) ;
return false ;
}
}
static int F_75 ( struct V_1 * V_49 , struct V_6 * V_7 )
{
struct V_89 V_90 ;
struct V_15 * V_41 ;
int V_91 ;
if ( V_7 -> V_92 || V_7 -> V_93 )
return - V_63 ;
V_91 = F_76 ( V_49 , 0 ) ;
if ( V_91 )
return V_91 ;
F_77 ( & V_90 , V_49 , V_94 ) ;
while ( ( V_41 = F_78 ( & V_90 ) ) )
F_40 ( V_49 , V_41 -> V_3 ) ;
F_79 ( & V_90 ) ;
return 0 ;
}
static bool F_80 ( struct V_1 * V_49 ,
struct V_6 * V_7 ,
T_4 V_95 , T_4 V_96 )
{
unsigned int V_97 = F_81 ( V_7 ) ;
if ( ! V_97 )
return true ;
if ( F_82 ( ! F_83 ( V_97 ) ) ) {
T_5 V_98 ;
F_84 ( V_95 , V_97 , & V_98 ) ;
if ( V_98 )
return false ;
if ( ( V_95 + V_96 ) < F_85 ( V_49 ) ) {
F_84 ( V_96 , V_97 , & V_98 ) ;
if ( V_98 )
return false ;
}
} else {
if ( V_95 & ( V_97 - 1 ) )
return false ;
if ( ( V_95 + V_96 ) < F_85 ( V_49 ) &&
( V_96 & ( V_97 - 1 ) ) )
return false ;
}
return true ;
}
int F_86 ( struct V_1 * V_49 , struct V_6 * V_7 )
{
struct V_99 * V_100 = NULL ;
struct V_15 * V_41 ;
int V_16 , V_101 , V_91 ;
V_102:
if ( V_100 && ! F_87 ( V_100 ) ) {
F_88 ( V_100 ) ;
V_100 = NULL ;
}
V_91 = F_75 ( V_49 , V_7 ) ;
if ( V_91 )
return V_91 ;
if ( V_49 -> V_85 -> V_103 )
V_49 -> V_85 -> V_103 ( V_49 ) ;
F_89 ( V_49 , V_7 ) ;
V_7 -> V_104 = 0 ;
if ( ! F_85 ( V_49 ) || ! ( V_100 = F_90 ( V_49 , V_7 ) ) )
return 0 ;
if ( F_87 ( V_100 ) ) {
if ( F_91 ( V_100 ) == - V_105 ) {
F_74 ( V_106 L_18 ,
V_49 -> F_1 ) ;
if ( F_73 ( V_49 ) )
goto V_102;
}
return - V_107 ;
}
if ( V_100 -> V_108 ) {
F_74 ( V_106
L_19 ,
V_49 -> F_1 ) ;
if ( F_73 ( V_49 ) )
goto V_102;
}
F_69 ( & F_49 ( V_49 ) -> V_77 , V_109 ) ;
for ( V_16 = 1 , V_101 = 0 ; V_16 < V_100 -> V_110 ; V_16 ++ )
if ( V_100 -> V_111 [ V_16 ] . V_96 )
V_101 = V_16 ;
F_50 ( V_49 , V_101 ) ;
for ( V_16 = 1 ; V_16 < V_100 -> V_110 ; V_16 ++ ) {
T_4 V_96 , V_95 ;
V_96 = V_100 -> V_111 [ V_16 ] . V_96 ;
if ( ! V_96 )
continue;
V_95 = V_100 -> V_111 [ V_16 ] . V_95 ;
if ( V_95 >= F_85 ( V_49 ) ) {
F_74 ( V_106
L_20 ,
V_49 -> F_1 , V_16 , ( unsigned long long ) V_95 ) ;
if ( F_73 ( V_49 ) )
goto V_102;
continue;
}
if ( V_95 + V_96 > F_85 ( V_49 ) ) {
F_74 ( V_106
L_21 ,
V_49 -> F_1 , V_16 , ( unsigned long long ) V_96 ) ;
if ( F_73 ( V_49 ) ) {
goto V_102;
} else {
V_96 = F_85 ( V_49 ) - V_95 ;
}
}
if ( F_92 ( V_7 ) &&
! F_80 ( V_49 , V_7 , V_95 , V_96 ) ) {
F_74 ( V_106
L_22 ,
V_49 -> F_1 , V_16 , ( unsigned long long ) V_95 ,
( unsigned long long ) V_96 ) ;
continue;
}
V_41 = F_47 ( V_49 , V_16 , V_95 , V_96 ,
V_100 -> V_111 [ V_16 ] . V_57 ,
& V_100 -> V_111 [ V_16 ] . V_42 ) ;
if ( F_87 ( V_41 ) ) {
F_74 ( V_112 L_23 ,
V_49 -> F_1 , V_16 , - F_91 ( V_41 ) ) ;
continue;
}
#ifdef F_93
if ( V_100 -> V_111 [ V_16 ] . V_57 & V_113 )
F_94 ( F_37 ( V_41 ) -> V_38 ) ;
#endif
}
F_88 ( V_100 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_49 , struct V_6 * V_7 )
{
int V_91 ;
if ( ! V_7 -> V_104 )
return 0 ;
V_91 = F_75 ( V_49 , V_7 ) ;
if ( V_91 )
return V_91 ;
F_96 ( V_49 , 0 ) ;
F_89 ( V_49 , V_7 ) ;
V_7 -> V_104 = 0 ;
F_69 ( & F_49 ( V_49 ) -> V_77 , V_109 ) ;
return 0 ;
}
unsigned char * F_97 ( struct V_6 * V_7 , T_4 V_114 , T_6 * V_16 )
{
struct V_115 * V_116 = V_7 -> V_117 -> V_118 ;
struct V_119 * V_119 ;
V_119 = F_98 ( V_116 , ( V_120 ) ( V_114 >> ( V_121 - 9 ) ) , NULL ) ;
if ( ! F_87 ( V_119 ) ) {
if ( F_99 ( V_119 ) )
goto V_122;
V_16 -> V_123 = V_119 ;
return ( unsigned char * ) F_100 ( V_119 ) + ( ( V_114 & ( ( 1 << ( V_121 - 9 ) ) - 1 ) ) << 9 ) ;
V_122:
F_101 ( V_119 ) ;
}
V_16 -> V_123 = NULL ;
return NULL ;
}
