void F_1 ( const char * V_1 , const struct V_2 * V_3 ,
const char * V_4 , ... )
{
T_1 args ;
struct V_5 V_6 ;
va_start ( args , V_4 ) ;
V_6 . V_7 = V_4 ;
V_6 . V_8 = & args ;
if ( V_3 -> V_9 )
F_2 ( L_1 ,
V_1 , V_10 , V_3 -> V_11 -> V_12 , & V_6 ) ;
else
F_2 ( L_2 ,
V_1 , V_10 , F_3 ( & V_3 -> V_13 -> V_14 -> V_11 ) ,
V_3 -> V_15 , & V_6 ) ;
va_end ( args ) ;
}
void F_4 ( struct V_16 * V_11 ,
T_2 V_17 )
{
struct V_2 * V_3 = F_5 ( V_11 ) ;
if ( V_17 & V_18 )
V_3 -> V_19 |= F_6 ( V_20 ) ;
else
V_3 -> V_19 &= F_6 ( ~ V_20 ) ;
V_3 -> V_21 &= ~ ( V_22 |
V_23 ) ;
if ( F_7 ( V_3 -> V_13 -> V_11 ) &&
! ( V_17 & V_18 ) && ! V_3 -> V_24 )
V_3 -> V_21 |= V_22 ;
if ( F_7 ( V_3 -> V_13 -> V_11 ) || V_3 -> V_24 )
V_3 -> V_21 |= V_23 ;
F_8 ( & V_3 -> V_13 -> V_25 ) ;
if ( ( V_3 -> V_13 -> V_11 -> V_26 . V_27 &
V_28 ) &&
V_3 -> V_29 . V_30 && V_3 -> V_29 . V_30 -> V_31 ) {
int V_32 ;
int V_33 = 0 ;
int V_34 = ! ! ( V_17 & V_18 ) ;
for ( V_32 = 0 ; V_32 < V_3 -> V_35 ; V_32 ++ ) {
int V_36 ;
V_36 = F_9 ( V_3 ,
& V_3 -> V_29 . V_37 [ V_32 ] ,
V_34 ) ;
if ( ! V_33 )
V_33 = V_36 ;
}
if ( V_33 )
F_10 ( V_3 -> V_13 , L_3 ) ;
}
F_11 ( & V_3 -> V_13 -> V_25 ) ;
}
static void F_12 ( struct V_38 * V_13 )
{
struct V_39 * V_40 = & V_13 -> V_41 ;
int V_32 ;
V_40 -> V_42 = V_42 ;
V_40 -> V_43 = F_13 () ?
V_44 :
F_14 ( int , F_15 () , V_45 ) ;
if ( V_40 -> V_42 && ! ( V_13 -> V_11 -> V_26 . V_21
& V_46 ) ) {
F_10 ( V_13 , L_4 ) ;
V_40 -> V_42 = 0 ;
}
for ( V_32 = 1 ; V_32 <= V_47 ; V_32 ++ ) {
V_40 -> V_48 [ V_32 ] . V_49 = 1 ;
V_40 -> V_48 [ V_32 ] . V_50 = V_51 ;
V_40 -> V_48 [ V_32 ] . V_52 = 1 ;
V_40 -> V_48 [ V_32 ] . V_53 = V_54 ;
V_40 -> V_48 [ V_32 ] . V_55 = V_56 ;
V_40 -> V_48 [ V_32 ] . V_57 = V_58 ;
V_40 -> V_48 [ V_32 ] . V_59 = V_60 ;
V_40 -> V_48 [ V_32 ] . V_43 = V_40 -> V_43 ;
V_40 -> V_48 [ V_32 ] . V_61 [ V_62 ] = V_40 -> V_43 *
V_40 -> V_48 [ V_32 ] . V_59 ;
V_40 -> V_48 [ V_32 ] . V_63 = 0 ;
V_40 -> V_48 [ V_32 ] . V_64 = V_64 ;
}
}
static void * F_16 ( struct V_65 * V_11 , void * V_66 , T_3 V_15 )
{
struct V_38 * V_67 = V_66 ;
return V_67 -> V_68 [ V_15 ] ;
}
static void F_17 ( struct V_65 * V_11 , void * V_69 ,
enum V_70 V_71 , unsigned long V_15 )
{
struct V_38 * V_13 = (struct V_38 * ) V_69 ;
struct V_2 * V_3 ;
switch ( V_71 ) {
case V_72 :
case V_73 :
if ( ! V_13 -> V_68 [ V_15 ] )
return;
V_3 = F_5 ( V_13 -> V_68 [ V_15 ] ) ;
V_3 -> V_74 = V_71 ;
F_18 ( V_13 -> V_75 , & V_3 -> V_76 ) ;
break;
case V_77 :
F_19 ( V_13 , L_5 ) ;
break;
case V_78 :
case V_79 :
break;
default:
if ( V_15 < 1 || V_15 > V_11 -> V_26 . V_80 ||
! V_13 -> V_68 [ V_15 ] )
return;
F_10 ( V_13 , L_6 , V_71 ,
( int ) V_15 ) ;
}
}
static void F_20 ( struct V_65 * V_11 , void * V_69 )
{
struct V_38 * V_13 = V_69 ;
int V_32 ;
F_8 ( & V_13 -> V_25 ) ;
V_13 -> V_81 = false ;
F_11 ( & V_13 -> V_25 ) ;
F_21 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_13 -> V_68 [ V_32 ] )
F_22 ( V_13 -> V_68 [ V_32 ] ) ;
F_23 ( V_13 -> V_75 ) ;
F_24 ( V_13 -> V_75 ) ;
( void ) F_25 ( V_11 , & V_13 -> V_82 ) ;
F_26 ( V_13 -> V_83 ) ;
F_27 ( V_11 , & V_13 -> V_84 ) ;
F_28 ( V_11 , V_13 -> V_85 ) ;
if ( V_13 -> V_86 . V_87 )
F_29 ( & V_13 -> V_86 ) ;
F_30 ( V_13 ) ;
}
static void F_31 ( struct V_65 * V_11 , void * V_66 )
{
int V_32 ;
struct V_38 * V_13 = V_66 ;
F_21 (i, dev, MLX4_PORT_TYPE_ETH) {
F_32 ( V_13 , L_7 , V_32 ) ;
if ( F_33 ( V_13 , V_32 , & V_13 -> V_41 . V_48 [ V_32 ] ) )
V_13 -> V_68 [ V_32 ] = NULL ;
}
V_13 -> V_86 . V_87 = V_88 ;
if ( F_34 ( & V_13 -> V_86 ) ) {
V_13 -> V_86 . V_87 = NULL ;
F_19 ( V_13 , L_8 ) ;
}
}
static void * F_35 ( struct V_65 * V_11 )
{
struct V_38 * V_13 ;
int V_32 ;
F_36 ( V_89 L_9 , V_90 ) ;
V_13 = F_37 ( sizeof( * V_13 ) , V_91 ) ;
if ( ! V_13 )
goto V_92;
if ( F_38 ( V_11 , & V_13 -> V_85 ) )
goto V_93;
if ( F_39 ( V_11 , & V_13 -> V_84 ) )
goto V_94;
V_13 -> V_83 = F_40 ( ( V_95 ) V_13 -> V_84 . V_96 << V_97 ,
V_98 ) ;
if ( ! V_13 -> V_83 )
goto V_99;
F_41 ( & V_13 -> V_100 ) ;
V_13 -> V_11 = V_11 ;
V_13 -> V_101 = & V_11 -> V_102 -> V_14 -> V_11 ;
V_13 -> V_14 = V_11 -> V_102 -> V_14 ;
V_13 -> V_81 = false ;
V_13 -> V_103 = ! ! ( V_11 -> V_26 . V_21 & ( 1 << 15 ) ) ;
if ( ! V_13 -> V_103 )
F_10 ( V_13 , L_10 ) ;
if ( F_42 ( V_13 -> V_11 , V_13 -> V_85 , 0 , ~ 0ull ,
V_104 | V_105 ,
0 , 0 , & V_13 -> V_82 ) ) {
F_19 ( V_13 , L_11 ) ;
goto V_106;
}
if ( F_43 ( V_13 -> V_11 , & V_13 -> V_82 ) ) {
F_19 ( V_13 , L_12 ) ;
goto V_107;
}
F_12 ( V_13 ) ;
V_13 -> V_108 = 0 ;
F_21 (i, dev, MLX4_PORT_TYPE_ETH)
V_13 -> V_108 ++ ;
F_44 ( V_13 ) ;
V_13 -> V_75 = F_45 ( L_13 ) ;
if ( ! V_13 -> V_75 )
goto V_107;
F_46 ( & V_13 -> V_25 ) ;
V_13 -> V_81 = true ;
return V_13 ;
V_107:
( void ) F_25 ( V_11 , & V_13 -> V_82 ) ;
V_106:
if ( V_13 -> V_83 )
F_26 ( V_13 -> V_83 ) ;
V_99:
F_27 ( V_11 , & V_13 -> V_84 ) ;
V_94:
F_28 ( V_11 , V_13 -> V_85 ) ;
V_93:
F_30 ( V_13 ) ;
V_92:
return NULL ;
}
static void F_47 ( void )
{
if ( V_54 > V_109 ) {
F_48 ( L_14 ,
V_54 , V_109 ) ;
V_54 = 0 ;
}
if ( V_51 > V_110 ) {
F_48 ( L_15 ,
V_51 , V_110 ) ;
V_51 = 0 ;
}
if ( V_64 < V_111 || V_64 > V_112 ) {
F_48 ( L_16 ,
V_64 , V_111 , V_112 , V_112 ) ;
V_64 = V_112 ;
}
}
static int T_4 F_49 ( void )
{
F_47 () ;
F_50 () ;
return F_51 ( & V_113 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_113 ) ;
}
