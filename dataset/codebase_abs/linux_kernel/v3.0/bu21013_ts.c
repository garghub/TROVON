static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_4 = F_2
( V_2 -> V_7 , V_8 ,
V_9 , V_3 ) ;
if ( V_4 == V_9 )
return 0 ;
}
return - V_10 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_9 ] ;
unsigned int V_11 [ 2 ] , V_12 [ 2 ] ;
bool V_13 , V_14 ;
int V_15 = 0 ;
int V_5 ;
if ( V_2 == NULL )
return - V_10 ;
if ( F_1 ( V_2 , V_3 ) < 0 )
return - V_10 ;
V_13 = F_4 ( V_3 [ 0 ] & V_16 ) ;
V_14 = F_4 ( ( ( V_3 [ 1 ] & V_17 ) |
( ( V_3 [ 2 ] & V_18 ) << V_19 ) ) >> V_20 ) ;
if ( ! V_13 || ! V_14 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_21 ; V_5 ++ ) {
const T_1 * V_22 = & V_3 [ 4 * V_5 + 3 ] ;
unsigned int V_23 = V_22 [ 0 ] << V_20 | ( V_22 [ 1 ] & V_24 ) ;
unsigned int V_25 = V_22 [ 2 ] << V_20 | ( V_22 [ 3 ] & V_24 ) ;
if ( V_23 == 0 || V_25 == 0 )
continue;
V_11 [ V_15 ] = V_23 ;
V_12 [ V_15 ] = V_25 ;
V_15 ++ ;
}
if ( V_15 ) {
if ( V_15 == 2 &&
( abs ( V_11 [ 0 ] - V_11 [ 1 ] ) < V_26 ||
abs ( V_12 [ 0 ] - V_12 [ 1 ] ) < V_26 ) ) {
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_2 -> V_27 -> V_28 )
V_11 [ V_5 ] = V_2 -> V_27 -> V_29 - V_11 [ V_5 ] ;
if ( V_2 -> V_27 -> V_30 )
V_12 [ V_5 ] = V_2 -> V_27 -> V_31 - V_12 [ V_5 ] ;
F_5 ( V_2 -> V_32 ,
V_33 , V_11 [ V_5 ] ) ;
F_5 ( V_2 -> V_32 ,
V_34 , V_12 [ V_5 ] ) ;
F_6 ( V_2 -> V_32 ) ;
}
} else
F_6 ( V_2 -> V_32 ) ;
F_7 ( V_2 -> V_32 ) ;
return 0 ;
}
static T_2 F_8 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
struct V_37 * V_38 = V_2 -> V_7 ;
int V_39 ;
do {
V_39 = F_3 ( V_2 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_1 ) ;
return V_41 ;
}
V_2 -> V_42 = V_2 -> V_27 -> V_43 () ;
if ( V_2 -> V_42 == V_44 )
F_10 ( V_2 -> V_45 , V_2 -> V_46 ,
F_11 ( 2 ) ) ;
} while ( ! V_2 -> V_42 && ! V_2 -> V_46 );
return V_47 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_39 ;
struct V_37 * V_38 = V_2 -> V_7 ;
V_39 = F_13 ( V_38 , V_48 ,
V_49 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_2 ) ;
return V_39 ;
}
F_14 ( V_50 ) ;
V_39 = F_13 ( V_38 , V_51 ,
V_16 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_3 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_52 ,
V_17 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_4 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_53 ,
V_18 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_5 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_54 ,
( V_55 | V_56 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_6 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_57 ,
( V_58 | V_59 |
V_60 | V_61 |
V_62 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_7 ) ;
return V_39 ;
}
if ( V_2 -> V_27 -> V_63 )
V_39 = F_13 ( V_38 , V_64 ,
( V_65 | V_66 ) ) ;
else
V_39 = F_13 ( V_38 , V_64 ,
( V_67 | V_66 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_8 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_68 ,
( V_69 | V_70 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_9 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_71 ,
V_72 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_10 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_73 ,
( V_74 |
V_75 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_11 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_76 ,
V_77 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_12 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_78 ,
V_79 | V_80 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_13 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_81 ,
( V_82 | V_83 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_14 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_84 ,
V_85 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_15 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_86 ,
( V_87 | V_88 |
V_89 | V_90 ) ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_16 ) ;
return V_39 ;
}
V_39 = F_13 ( V_38 , V_91 ,
V_92 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_38 -> V_40 , L_17 ) ;
return V_39 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_93 )
{
V_93 -> V_46 = true ;
F_16 ( & V_93 -> V_45 ) ;
F_17 ( V_93 -> V_27 -> V_35 , V_93 ) ;
}
static int T_3 F_18 ( struct V_37 * V_7 ,
const struct V_94 * V_95 )
{
struct V_1 * V_93 ;
struct V_96 * V_32 ;
const struct V_97 * V_98 =
V_7 -> V_40 . V_99 ;
int error ;
if ( ! F_19 ( V_7 -> V_100 ,
V_101 ) ) {
F_9 ( & V_7 -> V_40 , L_18 ) ;
return - V_102 ;
}
if ( ! V_98 ) {
F_9 ( & V_7 -> V_40 , L_19 ) ;
return - V_10 ;
}
V_93 = F_20 ( sizeof( struct V_1 ) , V_103 ) ;
V_32 = F_21 () ;
if ( ! V_93 || ! V_32 ) {
F_9 ( & V_7 -> V_40 , L_20 ) ;
error = - V_104 ;
goto V_105;
}
V_93 -> V_32 = V_32 ;
V_93 -> V_27 = V_98 ;
V_93 -> V_7 = V_7 ;
V_93 -> V_106 = F_22 ( & V_7 -> V_40 , L_21 ) ;
if ( F_23 ( V_93 -> V_106 ) ) {
F_9 ( & V_7 -> V_40 , L_22 ) ;
error = F_24 ( V_93 -> V_106 ) ;
goto V_105;
}
error = F_25 ( V_93 -> V_106 ) ;
if ( error < 0 ) {
F_9 ( & V_7 -> V_40 , L_23 ) ;
goto V_107;
}
V_93 -> V_46 = false ;
F_26 ( & V_93 -> V_45 ) ;
if ( V_98 -> V_108 ) {
error = V_98 -> V_108 ( V_98 -> V_109 ) ;
if ( error < 0 ) {
F_9 ( & V_7 -> V_40 , L_24 ) ;
goto V_110;
}
}
error = F_12 ( V_93 ) ;
if ( error ) {
F_9 ( & V_7 -> V_40 , L_25 ) ;
goto V_111;
}
V_32 -> V_112 = V_113 ;
V_32 -> V_95 . V_114 = V_115 ;
V_32 -> V_40 . V_116 = & V_7 -> V_40 ;
F_27 ( V_117 , V_32 -> V_118 ) ;
F_27 ( V_119 , V_32 -> V_118 ) ;
F_27 ( V_120 , V_32 -> V_118 ) ;
F_28 ( V_32 , V_33 , 0 ,
V_98 -> V_29 , 0 , 0 ) ;
F_28 ( V_32 , V_34 , 0 ,
V_98 -> V_31 , 0 , 0 ) ;
F_29 ( V_32 , V_93 ) ;
error = F_30 ( V_98 -> V_35 , NULL , F_8 ,
V_121 | V_122 ,
V_113 , V_93 ) ;
if ( error ) {
F_9 ( & V_7 -> V_40 , L_26 , V_98 -> V_35 ) ;
goto V_111;
}
error = F_31 ( V_32 ) ;
if ( error ) {
F_9 ( & V_7 -> V_40 , L_27 ) ;
goto V_123;
}
F_32 ( & V_7 -> V_40 , V_98 -> V_124 ) ;
F_33 ( V_7 , V_93 ) ;
return 0 ;
V_123:
F_15 ( V_93 ) ;
V_111:
V_98 -> V_125 ( V_98 -> V_109 ) ;
V_110:
F_34 ( V_93 -> V_106 ) ;
V_107:
F_35 ( V_93 -> V_106 ) ;
V_105:
F_36 ( V_32 ) ;
F_37 ( V_93 ) ;
return error ;
}
static int T_4 F_38 ( struct V_37 * V_7 )
{
struct V_1 * V_93 = F_39 ( V_7 ) ;
F_15 ( V_93 ) ;
V_93 -> V_27 -> V_125 ( V_93 -> V_27 -> V_109 ) ;
F_40 ( V_93 -> V_32 ) ;
F_34 ( V_93 -> V_106 ) ;
F_35 ( V_93 -> V_106 ) ;
F_37 ( V_93 ) ;
F_32 ( & V_7 -> V_40 , false ) ;
return 0 ;
}
static int F_41 ( struct V_126 * V_40 )
{
struct V_1 * V_93 = F_42 ( V_40 ) ;
struct V_37 * V_7 = V_93 -> V_7 ;
V_93 -> V_46 = true ;
if ( F_43 ( & V_7 -> V_40 ) )
F_44 ( V_93 -> V_27 -> V_35 ) ;
else
F_45 ( V_93 -> V_27 -> V_35 ) ;
F_34 ( V_93 -> V_106 ) ;
return 0 ;
}
static int F_46 ( struct V_126 * V_40 )
{
struct V_1 * V_93 = F_42 ( V_40 ) ;
struct V_37 * V_7 = V_93 -> V_7 ;
int V_39 ;
V_39 = F_25 ( V_93 -> V_106 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_7 -> V_40 , L_28 ) ;
return V_39 ;
}
V_39 = F_12 ( V_93 ) ;
if ( V_39 < 0 ) {
F_9 ( & V_7 -> V_40 , L_29 ) ;
return V_39 ;
}
V_93 -> V_46 = false ;
if ( F_43 ( & V_7 -> V_40 ) )
F_47 ( V_93 -> V_27 -> V_35 ) ;
else
F_48 ( V_93 -> V_27 -> V_35 ) ;
return 0 ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_127 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_127 ) ;
}
