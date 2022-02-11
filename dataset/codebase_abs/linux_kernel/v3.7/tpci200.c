static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 == NULL )
return NULL ;
V_4 = F_2 ( V_3 -> V_5 -> V_6 ) ;
if ( V_4 == NULL ) {
F_3 ( & V_3 -> V_3 , L_1 ) ;
return NULL ;
}
if ( V_3 -> V_7 >= V_8 ) {
F_3 ( & V_3 -> V_3 ,
L_2 ,
V_3 -> V_9 , V_3 -> V_7 , V_8 - 1 ) ;
return NULL ;
}
return V_4 ;
}
static void F_4 ( struct V_1 * V_4 ,
T_1 T_2 * V_10 , T_3 V_11 )
{
unsigned long V_12 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_6 ( F_7 ( V_10 ) & ( ~ V_11 ) , V_10 ) ;
F_8 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_4 ,
T_1 T_2 * V_10 , T_3 V_11 )
{
unsigned long V_12 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_6 ( F_7 ( V_10 ) | V_11 , V_10 ) ;
F_8 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
int V_14 ;
F_11 ( V_4 -> V_15 -> V_16 -> V_17 , ( void * ) V_4 ) ;
F_12 ( V_4 -> V_15 -> V_16 , V_4 -> V_15 -> V_18 ) ;
F_12 ( V_4 -> V_15 -> V_16 , V_4 -> V_15 -> V_19 ) ;
F_12 ( V_4 -> V_15 -> V_16 , V_4 -> V_15 -> V_20 ) ;
F_12 ( V_4 -> V_15 -> V_16 , V_4 -> V_15 -> V_21 ) ;
F_13 ( V_4 -> V_15 -> V_16 , V_22 ) ;
F_13 ( V_4 -> V_15 -> V_16 , V_23 ) ;
F_13 ( V_4 -> V_15 -> V_16 , V_24 ) ;
F_13 ( V_4 -> V_15 -> V_16 , V_25 ) ;
F_14 ( V_4 -> V_15 -> V_16 ) ;
F_15 ( V_4 -> V_15 -> V_16 ) ;
for ( V_14 = 0 ; V_14 < V_8 ; V_14 ++ ) {
V_4 -> V_26 [ V_14 ] . V_27 . V_28 = NULL ;
V_4 -> V_26 [ V_14 ] . V_27 . V_29 = 0 ;
V_4 -> V_26 [ V_14 ] . V_30 . V_28 = NULL ;
V_4 -> V_26 [ V_14 ] . V_30 . V_29 = 0 ;
V_4 -> V_26 [ V_14 ] . V_31 . V_28 = NULL ;
V_4 -> V_26 [ V_14 ] . V_31 . V_29 = 0 ;
V_4 -> V_26 [ V_14 ] . V_32 . V_28 = NULL ;
V_4 -> V_26 [ V_14 ] . V_32 . V_29 = 0 ;
}
}
static void F_16 ( struct V_1 * V_4 ,
int V_33 )
{
F_9 ( V_4 ,
& V_4 -> V_15 -> V_18 -> V_34 [ V_33 ] ,
V_35 | V_36 ) ;
}
static void F_17 ( struct V_1 * V_4 ,
int V_33 )
{
F_4 ( V_4 ,
& V_4 -> V_15 -> V_18 -> V_34 [ V_33 ] ,
V_35 | V_36 ) ;
}
static T_4 F_18 ( struct V_37 * V_37 )
{
T_4 V_38 ;
if ( ! V_37 )
return - V_39 ;
V_38 = V_37 -> V_40 ( V_37 -> V_41 ) ;
return V_38 ;
}
static T_4 F_19 ( int V_17 , void * V_42 )
{
struct V_1 * V_4 = (struct V_1 * ) V_42 ;
struct V_37 * V_37 ;
T_4 V_38 ;
T_3 V_43 ;
int V_14 ;
V_43 = F_7 ( & V_4 -> V_15 -> V_18 -> V_44 ) ;
if ( ! ( V_43 & V_45 ) )
return V_46 ;
F_20 () ;
for ( V_14 = 0 ; V_14 < V_8 ; V_14 ++ ) {
if ( ! ( V_43 & ( ( V_47 | V_48 ) << ( 2 * V_14 ) ) ) )
continue;
V_37 = F_21 ( V_4 -> V_26 [ V_14 ] . V_17 ) ;
V_38 = F_18 ( V_37 ) ;
if ( V_38 == - V_39 ) {
F_3 ( & V_4 -> V_15 -> V_16 -> V_3 ,
L_3 ,
V_4 -> V_49 , V_14 ) ;
F_17 ( V_4 , V_14 ) ;
}
}
F_22 () ;
return V_50 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_37 * V_37 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_51 ;
if ( F_24 ( & V_4 -> V_52 ) )
return - V_53 ;
if ( V_4 -> V_26 [ V_3 -> V_7 ] . V_17 == NULL ) {
F_25 ( & V_4 -> V_52 ) ;
return - V_51 ;
}
F_17 ( V_4 , V_3 -> V_7 ) ;
V_37 = V_4 -> V_26 [ V_3 -> V_7 ] . V_17 ;
F_26 ( V_4 -> V_26 [ V_3 -> V_7 ] . V_17 , NULL ) ;
F_27 () ;
F_28 ( V_37 ) ;
F_25 ( & V_4 -> V_52 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
T_4 (* V_40)( void * ) , void * V_41 )
{
int V_54 = 0 ;
struct V_37 * V_37 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_51 ;
if ( F_24 ( & V_4 -> V_52 ) )
return - V_53 ;
if ( V_4 -> V_26 [ V_3 -> V_7 ] . V_17 != NULL ) {
F_30 ( & V_3 -> V_3 ,
L_4 , V_3 -> V_9 ,
V_3 -> V_7 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_37 = F_31 ( sizeof( struct V_37 ) , V_56 ) ;
if ( V_37 == NULL ) {
F_30 ( & V_3 -> V_3 ,
L_5 ,
V_3 -> V_9 , V_3 -> V_7 ) ;
V_54 = - V_57 ;
goto V_55;
}
V_37 -> V_40 = V_40 ;
V_37 -> V_41 = V_41 ;
V_37 -> V_58 = V_3 ;
F_32 ( V_4 -> V_26 [ V_3 -> V_7 ] . V_17 , V_37 ) ;
F_16 ( V_4 , V_3 -> V_7 ) ;
V_55:
F_25 ( & V_4 -> V_52 ) ;
return V_54 ;
}
static int F_33 ( struct V_1 * V_4 )
{
int V_14 ;
int V_54 ;
unsigned long V_59 ;
unsigned long V_60 ;
unsigned short V_61 ;
if ( F_34 ( V_4 -> V_15 -> V_16 ) < 0 )
return - V_39 ;
V_54 = F_35 ( V_4 -> V_15 -> V_16 , V_22 ,
L_6 ) ;
if ( V_54 ) {
F_30 ( & V_4 -> V_15 -> V_16 -> V_3 ,
L_7 ,
V_4 -> V_15 -> V_16 -> V_5 -> V_49 ,
V_4 -> V_15 -> V_16 -> V_62 ) ;
goto V_63;
}
V_54 = F_35 ( V_4 -> V_15 -> V_16 ,
V_23 ,
L_8 ) ;
if ( V_54 ) {
F_30 ( & V_4 -> V_15 -> V_16 -> V_3 ,
L_9 ,
V_4 -> V_15 -> V_16 -> V_5 -> V_49 ,
V_4 -> V_15 -> V_16 -> V_62 ) ;
goto V_64;
}
V_54 = F_35 ( V_4 -> V_15 -> V_16 , V_24 ,
L_10 ) ;
if ( V_54 ) {
F_30 ( & V_4 -> V_15 -> V_16 -> V_3 ,
L_11 ,
V_4 -> V_15 -> V_16 -> V_5 -> V_49 ,
V_4 -> V_15 -> V_16 -> V_62 ) ;
goto V_65;
}
V_4 -> V_15 -> V_18 =
F_36 ( F_37 ( V_4 -> V_15 -> V_16 ,
V_22 ) ,
V_66 ) ;
V_4 -> V_15 -> V_19 =
F_36 ( F_37 ( V_4 -> V_15 -> V_16 ,
V_23 ) ,
V_67 ) ;
V_4 -> V_15 -> V_20 =
F_36 ( F_37 ( V_4 -> V_15 -> V_16 ,
V_24 ) ,
V_68 ) ;
F_38 ( & V_4 -> V_13 ) ;
V_59 = F_37 ( V_4 -> V_15 -> V_16 ,
V_23 ) ;
V_60 = F_37 ( V_4 -> V_15 -> V_16 ,
V_24 ) ;
V_61 = 0 ;
for ( V_14 = 0 ; V_14 < V_8 ; V_14 ++ ) {
V_4 -> V_26 [ V_14 ] . V_27 . V_28 =
( void T_2 * ) V_59 +
V_69 + V_70 * V_14 ;
V_4 -> V_26 [ V_14 ] . V_27 . V_29 = V_71 ;
V_4 -> V_26 [ V_14 ] . V_30 . V_28 =
( void T_2 * ) V_59 +
V_72 + V_73 * V_14 ;
V_4 -> V_26 [ V_14 ] . V_30 . V_29 = V_74 ;
V_4 -> V_26 [ V_14 ] . V_31 . V_28 =
( void T_2 * ) V_59 +
V_75 + V_76 * V_14 ;
V_4 -> V_26 [ V_14 ] . V_31 . V_29 = V_77 ;
V_4 -> V_26 [ V_14 ] . V_32 . V_28 =
( void T_2 * ) V_60 + V_78 * V_14 ;
V_4 -> V_26 [ V_14 ] . V_32 . V_29 = V_68 ;
F_39 ( V_61 , & V_4 -> V_15 -> V_18 -> V_34 [ V_14 ] ) ;
}
V_54 = F_40 ( V_4 -> V_15 -> V_16 -> V_17 ,
F_19 , V_79 ,
V_80 , ( void * ) V_4 ) ;
if ( V_54 ) {
F_30 ( & V_4 -> V_15 -> V_16 -> V_3 ,
L_12 ,
V_4 -> V_15 -> V_16 -> V_5 -> V_49 ,
V_4 -> V_15 -> V_16 -> V_62 ) ;
goto V_65;
}
return 0 ;
V_65:
F_13 ( V_4 -> V_15 -> V_16 , V_23 ) ;
V_64:
F_13 ( V_4 -> V_15 -> V_16 , V_22 ) ;
V_63:
F_14 ( V_4 -> V_15 -> V_16 ) ;
return V_54 ;
}
static int F_41 ( struct V_2 * V_3 , int V_81 )
{
struct V_82 * V_83 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_51 ;
if ( F_24 ( & V_4 -> V_52 ) )
return - V_53 ;
switch ( V_81 ) {
case V_84 :
if ( V_3 -> V_85 . V_28 == NULL ) {
F_3 ( & V_3 -> V_3 ,
L_13 ,
V_3 -> V_9 , V_3 -> V_7 ) ;
goto V_55;
}
V_83 = & V_3 -> V_85 ;
break;
case V_86 :
if ( V_3 -> V_87 . V_28 == NULL ) {
F_3 ( & V_3 -> V_3 ,
L_14 ,
V_3 -> V_9 , V_3 -> V_7 ) ;
goto V_55;
}
V_83 = & V_3 -> V_87 ;
break;
case V_88 :
if ( V_3 -> V_89 . V_28 == NULL ) {
F_3 ( & V_3 -> V_3 ,
L_15 ,
V_3 -> V_9 , V_3 -> V_7 ) ;
goto V_55;
}
V_83 = & V_3 -> V_89 ;
break;
case V_90 :
if ( V_3 -> V_91 . V_28 == NULL ) {
F_3 ( & V_3 -> V_3 ,
L_16 ,
V_3 -> V_9 , V_3 -> V_7 ) ;
goto V_55;
}
V_83 = & V_3 -> V_91 ;
break;
default:
F_30 ( & V_3 -> V_3 ,
L_17 ,
V_3 -> V_9 , V_3 -> V_7 , V_81 ) ;
F_25 ( & V_4 -> V_52 ) ;
return - V_51 ;
}
F_42 ( V_83 -> V_28 ) ;
V_83 -> V_28 = NULL ;
V_83 -> V_29 = 0 ;
V_55:
F_25 ( & V_4 -> V_52 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 ,
unsigned int V_92 , int V_81 )
{
int V_54 = 0 ;
unsigned int V_93 ;
void T_2 * V_94 ;
struct V_82 * V_83 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_51 ;
if ( F_24 ( & V_4 -> V_52 ) )
return - V_53 ;
switch ( V_81 ) {
case V_84 :
if ( V_3 -> V_85 . V_28 != NULL ) {
F_30 ( & V_3 -> V_3 ,
L_18 ,
V_4 -> V_49 , V_3 -> V_7 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_83 = & V_3 -> V_85 ;
V_94 = V_4 -> V_26 [ V_3 -> V_7 ] . V_27 . V_28 ;
V_93 = V_4 -> V_26 [ V_3 -> V_7 ] . V_27 . V_29 ;
break;
case V_86 :
if ( V_3 -> V_87 . V_28 != NULL ) {
F_30 ( & V_3 -> V_3 ,
L_19 ,
V_4 -> V_49 , V_3 -> V_7 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_83 = & V_3 -> V_87 ;
V_94 = V_4 -> V_26 [ V_3 -> V_7 ] . V_30 . V_28 ;
V_93 = V_4 -> V_26 [ V_3 -> V_7 ] . V_30 . V_29 ;
break;
case V_88 :
if ( V_3 -> V_89 . V_28 != NULL ) {
F_30 ( & V_3 -> V_3 ,
L_20 ,
V_4 -> V_49 , V_3 -> V_7 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_83 = & V_3 -> V_89 ;
V_94 = V_4 -> V_26 [ V_3 -> V_7 ] . V_31 . V_28 ;
V_93 = V_4 -> V_26 [ V_3 -> V_7 ] . V_31 . V_29 ;
break;
case V_90 :
if ( V_3 -> V_91 . V_28 != NULL ) {
F_30 ( & V_3 -> V_3 ,
L_21 ,
V_4 -> V_49 , V_3 -> V_7 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_83 = & V_3 -> V_91 ;
if ( V_92 > V_4 -> V_26 [ V_3 -> V_7 ] . V_32 . V_29 ) {
F_30 ( & V_3 -> V_3 ,
L_22 ,
V_3 -> V_9 , V_3 -> V_7 , V_92 ,
V_4 -> V_26 [ V_3 -> V_7 ] . V_32 . V_29 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_94 = V_4 -> V_26 [ V_3 -> V_7 ] . V_32 . V_28 ;
V_93 = V_92 ;
break;
default:
F_30 ( & V_3 -> V_3 , L_23 ,
V_4 -> V_49 , V_3 -> V_7 , V_81 ) ;
V_54 = - V_51 ;
goto V_55;
}
V_83 -> V_29 = V_93 ;
V_83 -> V_28 =
F_36 ( ( unsigned long ) V_94 , V_93 ) ;
V_55:
F_25 ( & V_4 -> V_52 ) ;
return V_54 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
if ( ! V_4 )
return - V_39 ;
V_10 = & V_4 -> V_15 -> V_18 -> V_34 [ V_3 -> V_7 ] ;
return ( F_7 ( V_10 ) & V_95 ) ? 32 : 8 ;
}
static int F_45 ( struct V_2 * V_3 , int V_96 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
if ( ! V_4 )
return - V_39 ;
V_10 = & V_4 -> V_15 -> V_18 -> V_34 [ V_3 -> V_7 ] ;
switch ( V_96 ) {
case 8 :
F_4 ( V_4 , V_10 , V_95 ) ;
break;
case 32 :
F_9 ( V_4 , V_10 , V_95 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
T_3 V_11 ;
if ( ! V_4 )
return - V_39 ;
V_10 = & V_4 -> V_15 -> V_18 -> V_44 ;
V_11 = V_97 [ V_3 -> V_7 ] ;
return ( F_7 ( V_10 ) & V_11 ) ? 1 : 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
T_3 V_11 ;
if ( ! V_4 )
return - V_39 ;
V_10 = & V_4 -> V_15 -> V_18 -> V_44 ;
V_11 = V_98 [ V_3 -> V_7 ] ;
return ( F_7 ( V_10 ) & V_11 ) ? 1 : 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
T_3 V_11 ;
if ( ! V_4 )
return - V_39 ;
V_10 = & V_4 -> V_15 -> V_18 -> V_44 ;
V_11 = V_98 [ V_3 -> V_7 ] ;
F_6 ( V_11 , V_10 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_4 )
{
F_10 ( V_4 ) ;
F_28 ( V_4 -> V_26 ) ;
}
static int F_50 ( struct V_1 * V_4 )
{
int V_54 ;
V_4 -> V_26 = F_31 (
V_8 * sizeof( struct V_99 ) , V_56 ) ;
if ( V_4 -> V_26 == NULL )
return - V_57 ;
V_54 = F_33 ( V_4 ) ;
if ( V_54 ) {
F_28 ( V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
return V_54 ;
}
F_51 ( & V_4 -> V_52 ) ;
return 0 ;
}
static int F_52 ( struct V_100 * V_16 ,
const struct V_101 * V_102 )
{
int V_38 , V_14 ;
struct V_1 * V_4 ;
T_5 V_103 ;
V_4 = F_31 ( sizeof( struct V_1 ) , V_56 ) ;
if ( ! V_4 )
return - V_57 ;
V_4 -> V_15 = F_31 ( sizeof( struct V_104 ) , V_56 ) ;
if ( ! V_4 -> V_15 ) {
V_38 = - V_57 ;
goto V_105;
}
F_53 ( V_16 ) ;
V_38 = F_35 ( V_16 , V_25 ,
V_80 L_24 ) ;
if ( V_38 ) {
F_30 ( & V_16 -> V_3 , L_25 ) ;
V_38 = - V_106 ;
goto V_107;
}
V_4 -> V_15 -> V_21 = F_36 (
F_37 ( V_16 , V_25 ) ,
F_54 ( V_16 , V_25 ) ) ;
if ( ! V_4 -> V_15 -> V_21 ) {
F_30 ( & V_16 -> V_3 , L_26 ) ;
V_38 = - V_108 ;
goto V_109;
}
V_103 = F_55 ( V_4 -> V_15 -> V_21 + V_110 ) ;
V_103 |= 1 << V_111 ;
F_56 ( V_103 , V_4 -> V_15 -> V_21 + V_110 ) ;
V_103 = F_55 ( V_4 -> V_15 -> V_21 + V_112 ) ;
V_103 |= 1 << V_111 ;
F_56 ( V_103 , V_4 -> V_15 -> V_21 + V_112 ) ;
V_4 -> V_15 -> V_16 = V_16 ;
V_4 -> V_15 -> V_113 = (struct V_101 * ) V_102 ;
V_38 = F_50 ( V_4 ) ;
if ( V_38 ) {
F_30 ( & V_16 -> V_3 , L_27 ) ;
V_38 = - V_39 ;
goto V_114;
}
V_4 -> V_15 -> V_115 = F_57 ( & V_16 -> V_3 ,
V_8 ,
& V_116 ) ;
if ( ! V_4 -> V_15 -> V_115 ) {
F_30 ( & V_16 -> V_3 ,
L_28 ) ;
V_38 = - V_108 ;
goto V_117;
}
V_4 -> V_49 = V_4 -> V_15 -> V_115 -> V_9 ;
F_58 ( & V_16 -> V_3 , V_4 ) ;
for ( V_14 = 0 ; V_14 < V_8 ; V_14 ++ )
F_59 ( V_4 -> V_15 -> V_115 , V_14 ) ;
return 0 ;
V_117:
F_49 ( V_4 ) ;
V_114:
F_42 ( V_4 -> V_15 -> V_21 ) ;
V_109:
F_13 ( V_16 , V_25 ) ;
V_107:
F_15 ( V_16 ) ;
F_28 ( V_4 -> V_15 ) ;
V_105:
F_28 ( V_4 ) ;
return V_38 ;
}
static void F_60 ( struct V_1 * V_4 )
{
F_61 ( V_4 -> V_15 -> V_115 ) ;
F_49 ( V_4 ) ;
F_28 ( V_4 -> V_15 ) ;
F_28 ( V_4 ) ;
}
static void T_6 F_62 ( struct V_100 * V_3 )
{
struct V_1 * V_4 = F_63 ( V_3 ) ;
F_60 ( V_4 ) ;
}
static int T_7 F_64 ( void )
{
return F_65 ( & V_118 ) ;
}
static void T_8 F_66 ( void )
{
F_67 ( & V_118 ) ;
}
