void F_1 ( T_1 V_1 , T_1 T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
T_1 F_3 ( T_1 T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static struct V_3 * F_5 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = NULL ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( ! V_9 [ V_7 ] )
break;
}
if ( V_7 < V_8 )
V_6 = F_6 ( & V_5 -> V_10 , sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return NULL ;
V_9 [ V_7 ] = V_6 ;
V_6 -> V_12 = V_7 ;
return V_6 ;
}
struct V_3 * F_7 ( int V_13 )
{
if ( ( V_13 < V_8 ) && ( V_13 >= 0 ) )
return V_9 [ V_13 ] ;
F_8 ( L_1 , V_13 ) ;
return NULL ;
}
int F_9 ( void )
{
return F_10 ( F_11 () ) ;
}
static int F_12 ( struct V_3 * V_6 )
{
union V_14 V_15 ;
union V_16 V_17 ;
union V_18 V_19 ;
union V_20 V_21 ;
union V_22 V_23 ;
union V_24 V_25 ;
union V_26 V_27 ;
int V_28 = 0 ;
V_15 . V_29 = F_3 ( V_6 -> V_30 + V_31 ) ;
V_15 . V_32 . V_33 = 1 ;
F_1 ( V_15 . V_29 & 0xFF , ( V_6 -> V_30 + V_31 ) ) ;
F_13 ( L_2 ,
F_3 ( V_6 -> V_30 + V_31 ) ) ;
V_17 . V_29 = F_3 ( V_6 -> V_30 + V_34 ) ;
V_6 -> V_35 = V_17 . V_32 . V_35 ;
V_6 -> V_36 = V_17 . V_32 . V_36 ;
V_6 -> V_37 = V_17 . V_32 . V_37 ;
F_13 ( L_3 ,
V_6 -> V_35 , V_6 -> V_36 , V_6 -> V_37 ) ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ ) {
V_27 . V_29 = 0ull ;
V_27 . V_32 . V_39 = ( V_40 / sizeof( T_1 ) ) ;
V_27 . V_32 . V_41 = 0 ;
V_27 . V_32 . V_42 = 0 ;
F_1 ( V_27 . V_29 ,
( V_6 -> V_30 + F_14 ( V_28 ) ) ) ;
F_13 ( L_4 , V_28 ,
F_3 ( V_6 -> V_30 + F_14 ( V_28 ) ) ) ;
}
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ ) {
memset ( & V_6 -> V_43 [ V_28 ] , 0x0 , sizeof( struct V_44 ) ) ;
F_15 ( & V_6 -> V_43 [ V_28 ] . V_45 ) ;
if ( F_16 ( V_6 , V_28 ) ) {
while ( V_28 != 0 ) {
V_28 -- ;
F_17 ( V_6 , V_28 ) ;
}
return - V_46 ;
}
V_6 -> V_43 [ V_28 ] . V_47 = V_6 -> V_43 [ V_28 ] . V_48 ;
V_6 -> V_43 [ V_28 ] . V_49 = V_6 -> V_43 [ V_28 ] . V_48 ;
V_25 . V_29 = 0ull ;
V_25 . V_32 . V_50 = ( F_18 ( V_6 -> V_43 [ V_28 ] . V_48 ) >>
V_51 ) ;
F_13 ( L_5 , V_28 ,
( T_1 ) V_25 . V_32 . V_50 ) ;
F_1 ( V_25 . V_29 ,
( V_6 -> V_30 + F_19 ( V_28 ) ) ) ;
F_13 ( L_6 , V_28 ,
F_3 ( V_6 -> V_30 + F_19 ( V_28 ) ) ) ;
F_20 ( L_7 ,
V_6 -> V_43 [ V_28 ] . V_48 , V_6 -> V_43 [ V_28 ] . V_47 ,
V_6 -> V_43 [ V_28 ] . V_49 ) ;
F_20 ( L_8 , V_25 . V_32 . V_50 ) ;
}
V_19 . V_29 = 0x0ull ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ )
V_19 . V_32 . V_52 |= ( 0x1 << V_28 ) ;
F_1 ( V_19 . V_29 , ( V_6 -> V_30 + V_53 ) ) ;
F_13 ( L_9 ,
F_3 ( V_6 -> V_30 + V_53 ) ) ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ ) {
V_21 . V_29 = 0ull ;
V_21 . V_32 . V_54 = 0x3 ;
F_1 ( V_21 . V_29 ,
( V_6 -> V_30 + F_21 ( V_28 ) ) ) ;
F_13 ( L_10 , V_28 ,
F_3 ( V_6 -> V_30 + F_21 ( V_28 ) ) ) ;
}
V_23 . V_29 = 0ull ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ )
V_23 . V_32 . V_55 |= ( 0x1 << V_28 ) ;
F_1 ( V_23 . V_29 , ( V_6 -> V_30 + V_56 ) ) ;
F_13 ( L_11 , F_3 ( V_6 -> V_30 + V_56 ) ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 , const struct V_57 * V_58 )
{
struct V_59 * V_10 = & V_5 -> V_10 ;
struct V_3 * V_6 = NULL ;
int V_60 ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 )
return - V_46 ;
F_23 ( V_10 , L_12 , V_6 -> V_12 ,
V_5 -> V_61 , V_5 -> V_59 , F_24 ( V_10 ) ) ;
F_25 ( V_5 , V_6 ) ;
V_6 -> V_5 = V_5 ;
V_60 = F_26 ( V_5 ) ;
if ( V_60 ) {
F_27 ( V_10 , L_13 ) ;
goto V_62;
}
V_60 = F_28 ( V_5 , V_63 ) ;
if ( V_60 ) {
F_27 ( V_10 , L_14 , V_60 ) ;
goto V_64;
}
V_60 = F_29 ( V_5 , F_30 ( 48 ) ) ;
if ( V_60 ) {
F_27 ( V_10 , L_15 ) ;
goto V_65;
}
V_60 = F_31 ( V_5 , F_30 ( 48 ) ) ;
if ( V_60 ) {
F_27 ( V_10 , L_16 ) ;
goto V_65;
}
V_6 -> V_30 = F_32 ( V_5 , V_66 ) ;
if ( ! V_6 -> V_30 ) {
F_27 ( V_10 , L_17 ) ;
V_60 = - V_46 ;
goto V_65;
}
V_60 = F_12 ( V_6 ) ;
if ( V_60 )
goto V_65;
return 0 ;
V_65:
if ( V_6 -> V_30 )
F_33 ( V_6 -> V_30 ) ;
F_34 ( V_5 ) ;
V_64:
F_35 ( V_5 ) ;
V_62:
F_25 ( V_5 , NULL ) ;
V_9 [ V_6 -> V_12 ] = NULL ;
F_36 ( V_10 , V_6 ) ;
return V_60 ;
}
static void F_37 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_38 ( V_5 ) ;
union V_14 V_15 ;
int V_28 = 0 ;
if ( ! V_6 )
return;
if ( V_6 -> V_30 ) {
V_15 . V_29 = 0x0ull ;
V_15 . V_32 . V_67 = 1 ;
F_1 ( V_15 . V_29 , ( V_6 -> V_30 + V_31 ) ) ;
F_33 ( V_6 -> V_30 ) ;
}
F_34 ( V_5 ) ;
F_35 ( V_5 ) ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ )
F_17 ( V_6 , V_28 ) ;
F_25 ( V_5 , NULL ) ;
V_9 [ V_6 -> V_12 ] = NULL ;
}
static int F_39 ( void )
{
int V_68 ;
V_68 = F_40 ( & V_69 ) ;
if ( V_68 < 0 ) {
F_8 ( L_18 ) ;
return V_68 ;
}
V_68 = F_40 ( & V_70 ) ;
if ( V_68 < 0 ) {
F_8 ( L_19 ) ;
goto V_71;
}
V_68 = F_41 ( & V_72 ) ;
if ( V_68 < 0 ) {
F_8 ( L_20 ) ;
goto V_73;
}
V_68 = F_41 ( & V_74 ) ;
if ( V_68 < 0 ) {
F_8 ( L_21 ) ;
goto V_75;
}
return V_68 ;
V_75:
F_42 ( & V_72 ) ;
V_73:
F_43 ( & V_70 ) ;
V_71:
F_43 ( & V_69 ) ;
return V_68 ;
}
static void F_44 ( void )
{
F_43 ( & V_69 ) ;
F_43 ( & V_70 ) ;
F_42 ( & V_72 ) ;
F_42 ( & V_74 ) ;
}
static int F_45 ( struct V_76 * V_32 , void * V_77 )
{
T_1 V_1 = 0ull ;
T_1 V_78 = 0ull , V_79 = 0ull ;
T_3 V_28 = 0 ;
int V_12 = 0 ;
struct V_3 * V_6 ;
struct V_80 * V_81 ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
if ( V_9 [ V_12 ] ) {
V_6 = V_9 [ V_12 ] ;
V_81 = & V_6 -> V_82 ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ ) {
V_1 = F_3 ( ( V_6 -> V_30 +
F_46 ( V_28 ) ) ) ;
V_1 = ( V_1 >> 32 ) ;
V_1 = V_1 & 0xffffff ;
F_47 ( V_1 , & V_81 -> V_83 ) ;
}
V_78 = ( F_48 ( & V_81 -> V_84 ) /
F_48 ( & V_81 -> V_85 ) ) ;
V_79 = ( F_48 ( & V_81 -> V_84 ) /
F_48 ( & V_81 -> V_86 ) ) ;
F_49 ( V_32 , L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_12 ,
( T_1 ) F_48 ( & V_81 -> V_87 ) ,
( T_1 ) F_48 ( & V_81 -> V_85 ) ,
( T_1 ) F_48 ( & V_81 -> V_84 ) ,
( T_1 ) F_48 ( & V_81 -> V_86 ) ,
V_78 ,
V_79 ,
( T_1 ) F_48 ( & V_81 -> V_88 ) ,
( T_1 ) F_48 ( & V_81 -> V_89 ) ,
( T_1 ) F_48 ( & V_81 -> V_90 ) ,
( T_1 ) F_48 ( & V_81 -> V_91 ) ,
( T_1 ) F_48 ( & V_81 -> V_92 ) ,
( T_1 ) F_48 ( & V_81 -> V_83 ) ) ;
F_50 ( & V_81 -> V_83 , 0 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_76 * V_32 , void * V_77 )
{
int V_12 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
if ( V_9 [ V_12 ] ) {
memset ( & V_9 [ V_12 ] -> V_82 , 0 ,
sizeof( struct V_80 ) ) ;
F_49 ( V_32 , L_37 , V_12 ) ;
}
}
return 0 ;
}
static int F_52 ( struct V_76 * V_32 , void * V_77 )
{
T_1 V_1 = 0 ;
int V_93 = 0 , V_12 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
if ( V_9 [ V_12 ] ) {
F_49 ( V_32 , L_38
L_39
L_38 ,
V_12 ) ;
V_93 = 0 ;
while ( V_94 [ V_93 ] . V_95 ) {
V_1 = F_3 ( ( V_9 [ V_12 ] -> V_30 +
V_94 [ V_93 ] . V_96 ) ) ;
F_49 ( V_32 , L_40 ,
V_94 [ V_93 ] . V_95 , V_1 ) ;
V_93 ++ ;
}
}
}
return 0 ;
}
static int F_53 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_54 ( V_98 , F_45 , NULL ) ;
}
static int F_55 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_54 ( V_98 , F_51 , NULL ) ;
}
static int F_56 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_54 ( V_98 , F_52 , NULL ) ;
}
static int T_4 F_57 ( void )
{
struct V_99 * V_80 , * V_100 , * V_101 ;
if ( ! F_58 () )
return - V_102 ;
V_103 = F_59 ( L_41 , NULL ) ;
if ( ! V_103 )
return - V_46 ;
V_80 = F_60 ( L_42 , 0444 ,
V_103 ,
NULL , & V_104 ) ;
if ( ! V_80 )
goto V_105;
V_100 = F_60 ( L_43 , 0444 ,
V_103 ,
NULL , & V_106 ) ;
if ( ! V_100 )
goto V_105;
V_101 = F_60 ( L_44 , 0444 ,
V_103 ,
NULL , & V_107 ) ;
if ( ! V_101 )
goto V_105;
return 0 ;
V_105:
F_61 ( V_103 ) ;
return - V_108 ;
}
static void T_5 F_62 ( void )
{
F_61 ( V_103 ) ;
}
static int T_4 F_57 ( void )
{
return 0 ;
}
static void T_5 F_62 ( void ) { }
static int T_4 F_63 ( void )
{
int V_68 ;
F_13 ( L_45 , V_63 ) ;
V_68 = F_64 ( & V_109 ) ;
if ( V_68 < 0 ) {
F_8 ( L_46 ) ;
return V_68 ;
}
V_68 = F_39 () ;
if ( V_68 < 0 ) {
F_8 ( L_47 ) ;
goto V_110;
}
V_68 = F_57 () ;
if ( V_68 < 0 ) {
F_8 ( L_48 ) ;
goto V_111;
}
return V_68 ;
V_111:
F_44 () ;
V_110:
F_65 ( & V_109 ) ;
return V_68 ;
}
static void T_5 F_66 ( void )
{
F_62 () ;
F_44 () ;
F_65 ( & V_109 ) ;
}
