static void
F_1 ( struct V_1 * V_2 , long V_3 )
{
T_1 volatile V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = V_2 -> V_6 -> V_7 ;
V_4 = V_4 & ~ V_8 ;
V_4 |= ( V_3 << V_9 ) ;
V_2 -> V_6 -> V_7 = V_4 ;
F_3 ( & V_2 -> V_5 ) ;
}
static void
F_4 ( struct V_1 * V_2 , long V_10 )
{
T_1 volatile V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = V_2 -> V_6 -> V_7 ;
V_4 = V_4 & ~ V_11 ;
V_4 |= ( V_10 << V_12 ) ;
V_2 -> V_6 -> V_7 = V_4 ;
F_3 ( & V_2 -> V_5 ) ;
}
static void
F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
struct V_15 * V_17 ;
V_14 -> V_18 = 0 ;
V_14 -> V_19 = 0 ;
V_16 = V_14 -> V_20 ;
if ( ! V_16 )
return;
do {
V_17 = V_16 -> V_21 ;
F_6 ( V_16 ) ;
V_16 = V_17 ;
} while ( V_16 != V_14 -> V_20 );
V_14 -> V_20 = NULL ;
}
static int
F_7 ( struct V_13 * V_14 , unsigned int V_22 ,
unsigned int V_19 )
{
struct V_23 * V_24 = V_14 -> V_24 ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_15 * V_16 ;
unsigned long V_27 ;
int V_28 ;
V_27 = F_8 ( V_26 -> V_29 ) ;
if ( V_14 -> V_18 == V_22 &&
V_14 -> V_19 == V_19 )
return 0 ;
F_5 ( V_14 ) ;
V_14 -> V_18 = V_22 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_20 = F_9 ( sizeof( struct V_15 ) , V_30 ) ;
if ( ! V_14 -> V_20 )
return - V_31 ;
V_16 = V_14 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ ) {
V_16 -> V_32 = ( T_1 ) ( V_27 + ( V_28 * V_22 ) ) ;
V_16 -> V_33 = ( T_1 ) ( ( ( V_28 + 1 ) * V_22 ) - 0x1 ) ;
if ( V_28 < V_19 - 1 ) {
V_16 -> V_21 = F_9 ( sizeof( struct V_15 ) , V_30 ) ;
if ( ! V_16 -> V_21 ) {
F_5 ( V_14 ) ;
return - V_31 ;
}
V_16 = V_16 -> V_21 ;
}
}
V_16 -> V_21 = V_14 -> V_20 ;
return 0 ;
}
static void
F_10 ( struct V_13 * V_14 )
{
if ( F_11 ( ! V_14 -> V_20 ) )
return;
F_12 ( V_14 -> V_34 ) ;
}
static void
F_13 ( struct V_13 * V_14 )
{
if ( F_11 ( ! V_14 -> V_20 ) )
return;
F_14 ( V_14 -> V_34 ) ;
if ( F_15 ( V_14 -> V_34 ) == 0 ) {
F_16 ( V_14 -> V_34 ) ;
F_17 ( V_14 -> V_34 , V_14 -> V_20 -> V_32 ) ;
F_18 ( V_14 -> V_34 , V_14 -> V_18 >> 1 ) ;
F_19 ( V_14 -> V_34 , V_14 -> V_20 -> V_21 -> V_32 ) ;
F_20 ( V_14 -> V_34 , V_14 -> V_18 >> 1 ) ;
} else {
F_21 ( V_14 -> V_34 ) ;
F_19 ( V_14 -> V_34 , V_14 -> V_20 -> V_32 ) ;
F_20 ( V_14 -> V_34 , V_14 -> V_18 >> 1 ) ;
F_17 ( V_14 -> V_34 , V_14 -> V_20 -> V_21 -> V_32 ) ;
F_18 ( V_14 -> V_34 , V_14 -> V_18 >> 1 ) ;
}
F_22 ( V_14 -> V_34 ) ;
F_23 ( V_14 -> V_34 ) ;
}
static T_2
F_24 ( int V_35 , void * V_36 )
{
struct V_13 * V_14 = (struct V_13 * ) V_36 ;
struct V_23 * V_24 = V_14 -> V_24 ;
F_2 ( & V_14 -> V_37 ) ;
switch ( F_25 ( V_14 -> V_34 ) ) {
case V_38 :
V_14 -> V_20 = V_14 -> V_20 -> V_21 ;
F_16 ( V_14 -> V_34 ) ;
F_17 ( V_14 -> V_34 , V_14 -> V_20 -> V_21 -> V_32 ) ;
F_18 ( V_14 -> V_34 , V_14 -> V_18 >> 1 ) ;
F_26 ( V_14 -> V_34 ) ;
break;
case V_39 :
V_14 -> V_20 = V_14 -> V_20 -> V_21 ;
F_21 ( V_14 -> V_34 ) ;
F_19 ( V_14 -> V_34 , V_14 -> V_20 -> V_21 -> V_32 ) ;
F_20 ( V_14 -> V_34 , V_14 -> V_18 >> 1 ) ;
F_27 ( V_14 -> V_34 ) ;
break;
case ( V_38 | V_39 ) :
F_28 ( V_40 L_1 , V_14 -> V_34 ) ;
F_10 ( V_14 ) ;
F_13 ( V_14 ) ;
break;
case ( ~ V_38 & ~ V_39 ) :
F_28 ( V_40 L_2 , V_14 -> V_34 ) ;
}
F_3 ( & V_14 -> V_37 ) ;
F_29 ( V_24 ) ;
return V_41 ;
}
static int
F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 -> V_43 ;
V_2 -> V_14 [ V_44 ] -> V_24 = V_24 ;
V_2 -> V_14 [ V_44 ] -> V_20 = NULL ;
V_24 -> V_43 = V_2 -> V_14 [ V_44 ] ;
V_24 -> V_26 -> V_45 = V_46 ;
return ( F_31 ( V_24 -> V_26 , 0 ,
V_47 , & V_48 ) < 0 ) ;
}
static int
F_32 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 -> V_43 ;
V_2 -> V_14 [ V_49 ] -> V_24 = V_24 ;
V_2 -> V_14 [ V_49 ] -> V_20 = NULL ;
V_24 -> V_43 = V_2 -> V_14 [ V_49 ] ;
V_24 -> V_26 -> V_45 = V_46 ;
return ( F_31 ( V_24 -> V_26 , 0 ,
V_47 , & V_48 ) < 0 ) ;
}
static int
F_33 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 -> V_43 ;
V_2 -> V_14 [ V_44 ] -> V_24 = NULL ;
return 0 ;
}
static int
F_34 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 -> V_43 ;
V_2 -> V_14 [ V_49 ] -> V_24 = NULL ;
return 0 ;
}
static int
F_35 ( struct V_23 * V_24 ,
struct V_50 * V_51 )
{
struct V_13 * V_14 = V_24 -> V_43 ;
int V_52 ;
V_52 = F_36 ( V_24 ,
F_37 ( V_51 ) ) ;
if ( V_52 < 0 )
return V_52 ;
return F_7 ( V_14 ,
F_38 ( V_51 ) ,
F_39 ( V_51 ) ) ;
}
static int
F_40 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = V_24 -> V_43 ;
F_5 ( V_14 ) ;
return F_41 ( V_24 ) ;
}
static int
F_42 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 -> V_43 ;
struct V_25 * V_26 = V_24 -> V_26 ;
if ( V_26 -> V_53 == 1 )
F_1 ( V_2 , V_54 ) ;
else
F_1 ( V_2 , V_55 | V_54 ) ;
F_43 ( V_2 -> V_56 , V_57 , V_26 -> V_58 ) ;
return 0 ;
}
static int
F_44 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 -> V_43 ;
struct V_25 * V_26 = V_24 -> V_26 ;
if ( V_26 -> V_53 == 1 )
F_4 ( V_2 , V_54 ) ;
else
F_4 ( V_2 , V_55 | V_54 ) ;
F_43 ( V_2 -> V_56 , V_59 , V_26 -> V_58 ) ;
return 0 ;
}
static int
F_45 ( struct V_23 * V_24 , int V_60 )
{
struct V_13 * V_14 = V_24 -> V_43 ;
int V_52 = 0 ;
F_2 ( & V_14 -> V_37 ) ;
switch ( V_60 ) {
case V_61 :
F_13 ( V_14 ) ;
break;
case V_62 :
F_10 ( V_14 ) ;
break;
default:
V_52 = - V_63 ;
break;
}
F_3 ( & V_14 -> V_37 ) ;
return V_52 ;
}
static T_3
F_46 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = V_24 -> V_43 ;
struct V_25 * V_26 = V_24 -> V_26 ;
long V_64 ;
F_2 ( & V_14 -> V_37 ) ;
V_64 = F_47 ( V_14 -> V_34 ) ;
F_3 ( & V_14 -> V_37 ) ;
V_64 = V_14 -> V_20 -> V_33 - V_64 ;
if ( V_64 == - 1 )
V_64 = 0 ;
return F_48 ( V_26 , V_64 ) ;
}
static int
F_49 ( struct V_1 * V_2 )
{
struct V_65 * V_42 ;
int V_52 ;
unsigned long V_66 ;
if ( ( V_52 = F_50 ( V_2 -> V_67 , L_3 , 0 , 1 , 1 , & V_42 ) ) < 0 )
return V_52 ;
F_51 ( V_42 , V_68 ,
F_52 ( V_30 ) , 128 * 1024 , 128 * 1024 ) ;
F_53 ( V_42 , V_69 ,
& V_70 ) ;
F_53 ( V_42 , V_71 ,
& V_72 ) ;
V_42 -> V_43 = V_2 ;
V_42 -> V_73 = 0 ;
strcpy ( V_42 -> V_74 , L_4 ) ;
F_54 ( & V_2 -> V_14 [ V_44 ] -> V_37 ) ;
F_54 ( & V_2 -> V_14 [ V_49 ] -> V_37 ) ;
V_66 = F_55 () ;
if ( ( V_2 -> V_14 [ V_44 ] -> V_34 = F_56 ( V_75 ,
L_5 , F_24 , 0 ,
V_2 -> V_14 [ V_44 ] ) ) < 0 ) {
F_57 ( V_66 ) ;
return - V_76 ;
}
if ( ( V_2 -> V_14 [ V_49 ] -> V_34 = F_56 ( V_77 ,
L_6 , F_24 , 0 ,
V_2 -> V_14 [ V_49 ] ) ) < 0 ) {
F_57 ( V_66 ) ;
return - V_76 ;
}
F_58 ( V_2 -> V_14 [ V_44 ] -> V_34 ,
F_59 ( V_2 -> V_14 [ V_44 ] -> V_34 ) & ~ V_78 ) ;
F_58 ( V_2 -> V_14 [ V_49 ] -> V_34 ,
F_59 ( V_2 -> V_14 [ V_49 ] -> V_34 ) & ~ V_78 ) ;
F_57 ( V_66 ) ;
V_2 -> V_42 = V_42 ;
return 0 ;
}
static unsigned short
F_60 ( struct V_79 * V_56 , unsigned short V_80 )
{
struct V_1 * V_2 = V_56 -> V_43 ;
T_1 volatile V_60 ;
T_4 volatile V_81 ;
int V_28 ;
F_2 ( & V_2 -> V_5 ) ;
for ( V_28 = 0 ; V_28 < 0x5000 ; V_28 ++ )
if ( ! ( V_2 -> V_6 -> V_82 & V_83 ) )
break;
if ( V_28 == 0x5000 )
F_28 ( V_40 L_7 ) ;
V_60 = ( T_1 ) V_80 & V_84 ;
V_60 |= V_85 ;
V_2 -> V_6 -> V_60 = V_60 ;
for ( V_28 = 0 ; V_28 < 0x5000 ; V_28 ++ )
if ( ! ( V_2 -> V_6 -> V_82 & V_83 ) )
break;
if ( V_28 == 0x5000 ) {
F_28 ( V_40 L_7 ) ;
F_3 ( & V_2 -> V_5 ) ;
return 0 ;
}
V_81 = V_2 -> V_6 -> V_60 & 0xffff ;
F_3 ( & V_2 -> V_5 ) ;
return V_81 ;
}
static void
F_61 ( struct V_79 * V_56 , unsigned short V_80 , unsigned short V_86 )
{
struct V_1 * V_2 = V_56 -> V_43 ;
T_1 V_60 ;
int V_28 ;
F_2 ( & V_2 -> V_5 ) ;
for ( V_28 = 0 ; V_28 < 0x5000 ; V_28 ++ )
if ( ! ( V_2 -> V_6 -> V_82 & V_83 ) )
break;
if ( V_28 == 0x5000 )
F_28 ( V_40 L_8 ) ;
V_60 = ( T_1 ) V_80 & V_84 ;
V_60 &= ~ V_85 ;
V_60 |= ( ( T_1 ) V_86 << V_87 ) ;
V_2 -> V_6 -> V_60 = V_60 ;
F_3 ( & V_2 -> V_5 ) ;
}
static int
F_62 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_88 * V_89 ;
struct V_90 V_56 ;
static struct V_91 V_92 = {
. V_93 = F_61 ,
. V_94 = F_60 ,
} ;
if ( ( V_2 -> V_95 = F_63 ( F_64 ( V_96 ) ,
0x100000 , L_9 ) ) == NULL ) {
F_65 ( V_40 L_10 ) ;
return - V_76 ;
}
V_2 -> V_6 = (struct V_97 * )
F_66 ( V_2 -> V_95 -> V_32 ) ;
F_54 ( & V_2 -> V_5 ) ;
F_67 ( F_68 ( V_98 ) & ~ 0x02 , V_98 ) ;
V_2 -> V_6 -> V_99 = V_100 | V_101 ;
F_69 ( 10 ) ;
V_2 -> V_6 -> V_99 = V_101 ;
F_69 ( 10 ) ;
V_2 -> V_6 -> V_7 = V_102 ;
F_69 ( 10 ) ;
V_2 -> V_6 -> V_7 = 0x0 ;
F_70 ( 5 ) ;
if ( ( V_52 = V_88 ( V_2 -> V_67 , 0 , & V_92 , V_2 , & V_89 ) ) < 0 )
return V_52 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_43 = V_2 ;
if ( ( V_52 = F_71 ( V_89 , & V_56 , & V_2 -> V_56 ) ) < 0 )
return V_52 ;
return 0 ;
}
void
F_72 ( struct V_103 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_43 ;
if ( V_2 -> V_95 ) {
V_2 -> V_6 -> V_99 = V_100 ;
V_2 -> V_6 = NULL ;
F_73 ( V_2 -> V_95 ) ;
}
if ( V_2 -> V_14 [ V_44 ] ) {
if ( V_2 -> V_14 [ V_44 ] -> V_34 >= 0 )
F_74 ( V_2 -> V_14 [ V_44 ] -> V_34 ) ;
F_6 ( V_2 -> V_14 [ V_44 ] ) ;
}
if ( V_2 -> V_14 [ V_49 ] ) {
if ( V_2 -> V_14 [ V_49 ] -> V_34 >= 0 )
F_74 ( V_2 -> V_14 [ V_49 ] -> V_34 ) ;
F_6 ( V_2 -> V_14 [ V_49 ] ) ;
}
}
static int T_5
F_75 ( void )
{
int V_52 ;
struct V_103 * V_67 ;
struct V_1 * V_2 ;
V_52 = F_76 ( - 1 , L_11 , V_104 ,
sizeof( struct V_1 ) , & V_67 ) ;
if ( V_52 < 0 )
return V_52 ;
V_67 -> V_105 = F_72 ;
V_2 = V_67 -> V_43 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_14 [ V_44 ] = F_9 ( sizeof( struct V_13 ) , V_30 ) ;
V_2 -> V_14 [ V_49 ] = F_9 ( sizeof( struct V_13 ) , V_30 ) ;
V_2 -> V_95 = NULL ;
if ( V_2 -> V_14 [ V_44 ] )
V_2 -> V_14 [ V_44 ] -> V_34 = - 1 ;
if ( V_2 -> V_14 [ V_49 ] )
V_2 -> V_14 [ V_49 ] -> V_34 = - 1 ;
if ( V_2 -> V_14 [ V_44 ] == NULL ||
V_2 -> V_14 [ V_49 ] == NULL ) {
F_77 ( V_67 ) ;
return - V_31 ;
}
if ( ( V_52 = F_62 ( V_2 ) ) < 0 ) {
F_77 ( V_67 ) ;
return V_52 ;
}
if ( ( V_52 = F_49 ( V_2 ) ) < 0 ) {
F_77 ( V_67 ) ;
return V_52 ;
}
strcpy ( V_67 -> V_106 , L_12 ) ;
strcpy ( V_67 -> V_107 , L_13 ) ;
sprintf ( V_67 -> V_108 , L_14 ) ;
if ( ( V_52 = F_78 ( V_67 ) ) < 0 ) {
F_77 ( V_67 ) ;
return V_52 ;
}
F_28 ( V_109 L_15 ) ;
V_110 = V_67 ;
return 0 ;
}
static void T_6 F_79 ( void )
{
F_77 ( V_110 ) ;
}
