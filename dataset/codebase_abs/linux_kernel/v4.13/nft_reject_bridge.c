static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , V_6 ) ;
F_3 ( V_3 ) ;
F_4 ( V_5 -> V_7 , F_5 ( V_2 ) -> V_8 ) ;
F_4 ( V_5 -> V_8 , F_5 ( V_2 ) -> V_7 ) ;
V_5 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_6 ( V_3 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_10 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
if ( ! F_8 ( V_10 , sizeof( struct V_11 ) ) )
return 0 ;
V_12 = F_9 ( V_10 ) ;
if ( V_12 -> V_14 < 5 || V_12 -> V_15 != 4 )
return 0 ;
V_13 = F_10 ( V_12 -> V_16 ) ;
if ( V_10 -> V_13 < V_13 )
return 0 ;
else if ( V_13 < ( V_12 -> V_14 * 4 ) )
return 0 ;
if ( ! F_8 ( V_10 , V_12 -> V_14 * 4 ) )
return 0 ;
return 1 ;
}
static void F_11 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 )
{
struct V_1 * V_3 ;
struct V_11 * V_21 ;
const struct V_22 * V_23 ;
struct V_22 V_24 ;
if ( ! F_7 ( V_2 ) )
return;
V_23 = F_12 ( V_2 , & V_24 , V_20 ) ;
if ( ! V_23 )
return;
V_3 = F_13 ( sizeof( struct V_11 ) + sizeof( struct V_22 ) +
V_25 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_21 = F_15 ( V_3 , V_2 , V_27 ,
V_17 -> V_28 . V_29 ) ;
F_16 ( V_3 , V_2 , V_23 ) ;
V_21 -> V_30 = V_17 -> V_28 . V_29 ;
V_21 -> V_16 = F_17 ( V_3 -> V_13 ) ;
F_18 ( V_21 ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static void F_21 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 , T_2 V_31 )
{
struct V_1 * V_3 ;
struct V_11 * V_21 ;
struct V_32 * V_33 ;
unsigned int V_13 ;
T_3 V_34 ;
T_2 V_35 ;
if ( ! F_7 ( V_2 ) )
return;
if ( F_9 ( V_2 ) -> V_36 & F_17 ( V_37 ) )
return;
V_13 = F_22 (unsigned int, 536 , oldskb->len) ;
if ( ! F_8 ( V_2 , V_13 ) )
return;
if ( F_23 ( V_2 , F_10 ( F_9 ( V_2 ) -> V_16 ) ) )
return;
if ( F_9 ( V_2 ) -> V_38 == V_27 ||
F_9 ( V_2 ) -> V_38 == V_39 )
V_35 = F_9 ( V_2 ) -> V_38 ;
else
V_35 = 0 ;
if ( ! F_24 ( V_2 ) &&
F_25 ( V_2 , V_20 , F_26 ( V_2 ) , V_35 ) )
return;
V_3 = F_13 ( sizeof( struct V_11 ) + sizeof( struct V_32 ) +
V_25 + V_13 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_21 = F_15 ( V_3 , V_2 , V_40 ,
V_17 -> V_28 . V_29 ) ;
F_27 ( V_3 ) ;
V_33 = F_28 ( V_3 , sizeof( struct V_32 ) ) ;
V_33 -> type = V_41 ;
V_33 -> V_31 = V_31 ;
F_29 ( V_3 , F_30 ( V_2 ) , V_13 ) ;
V_34 = F_31 ( ( void * ) V_33 , V_13 + sizeof( struct V_32 ) , 0 ) ;
V_33 -> V_42 = F_32 ( V_34 ) ;
V_21 -> V_16 = F_17 ( V_3 -> V_13 ) ;
F_18 ( V_21 ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static int F_33 ( struct V_1 * V_10 )
{
struct V_43 * V_44 ;
T_1 V_45 ;
if ( ! F_8 ( V_10 , sizeof( struct V_43 ) ) )
return 0 ;
V_44 = F_34 ( V_10 ) ;
if ( V_44 -> V_15 != 6 )
return 0 ;
V_45 = F_10 ( V_44 -> V_46 ) ;
if ( V_45 + sizeof( struct V_43 ) > V_10 -> V_13 )
return 0 ;
return 1 ;
}
static void F_35 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 )
{
struct V_1 * V_3 ;
const struct V_22 * V_23 ;
struct V_22 V_24 ;
unsigned int V_47 ;
struct V_43 * V_48 ;
if ( ! F_33 ( V_2 ) )
return;
V_23 = F_36 ( V_2 , & V_24 , & V_47 , V_20 ) ;
if ( ! V_23 )
return;
V_3 = F_13 ( sizeof( struct V_43 ) + sizeof( struct V_22 ) +
V_25 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_48 = F_37 ( V_3 , V_2 , V_27 ,
V_17 -> V_49 . V_50 -> V_51 ) ;
F_38 ( V_3 , V_2 , V_23 , V_47 ) ;
V_48 -> V_46 = F_17 ( V_3 -> V_13 - sizeof( struct V_43 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static bool F_39 ( struct V_1 * V_10 , int V_20 )
{
const struct V_43 * V_52 = F_34 ( V_10 ) ;
int V_53 ;
T_4 V_54 ;
T_2 V_35 = V_52 -> V_55 ;
if ( F_24 ( V_10 ) )
return true ;
if ( V_52 -> V_46 &&
F_23 ( V_10 , F_10 ( V_52 -> V_46 ) + sizeof( * V_52 ) ) )
return false ;
V_53 = F_40 ( V_10 , ( ( T_2 * ) ( V_52 + 1 ) - V_10 -> V_56 ) , & V_35 , & V_54 ) ;
if ( V_53 < 0 || V_53 >= V_10 -> V_13 || ( V_54 & F_17 ( ~ 0x7 ) ) != 0 )
return false ;
return F_41 ( V_10 , V_20 , V_53 , V_35 ) == 0 ;
}
static void F_42 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 , T_2 V_31 )
{
struct V_1 * V_3 ;
struct V_43 * V_48 ;
struct V_57 * V_58 ;
unsigned int V_13 ;
if ( ! F_33 ( V_2 ) )
return;
V_13 = F_22 (unsigned int, 1220 , oldskb->len) ;
if ( ! F_8 ( V_2 , V_13 ) )
return;
if ( ! F_39 ( V_2 , V_20 ) )
return;
V_3 = F_13 ( sizeof( struct V_11 ) + sizeof( struct V_57 ) +
V_25 + V_13 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_48 = F_37 ( V_3 , V_2 , V_59 ,
V_17 -> V_49 . V_50 -> V_51 ) ;
F_27 ( V_3 ) ;
V_58 = F_28 ( V_3 , sizeof( struct V_57 ) ) ;
V_58 -> V_60 = V_61 ;
V_58 -> V_62 = V_31 ;
F_29 ( V_3 , F_30 ( V_2 ) , V_13 ) ;
V_48 -> V_46 = F_17 ( V_3 -> V_13 - sizeof( struct V_43 ) ) ;
V_58 -> V_63 =
F_43 ( & V_48 -> V_64 , & V_48 -> V_65 ,
V_3 -> V_13 - sizeof( struct V_43 ) ,
V_59 ,
F_31 ( V_58 ,
V_3 -> V_13 - sizeof( struct V_43 ) ,
0 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static void F_44 ( const struct V_66 * V_67 ,
struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_72 * V_73 = F_45 ( V_67 ) ;
const unsigned char * V_74 = F_5 ( V_71 -> V_10 ) -> V_8 ;
if ( F_46 ( V_74 ) ||
F_47 ( V_74 ) )
goto V_75;
switch ( F_5 ( V_71 -> V_10 ) -> V_9 ) {
case F_17 ( V_76 ) :
switch ( V_73 -> type ) {
case V_77 :
F_21 ( F_48 ( V_71 ) , V_71 -> V_10 ,
F_49 ( V_71 ) ,
F_50 ( V_71 ) ,
V_73 -> V_78 ) ;
break;
case V_79 :
F_11 ( F_48 ( V_71 ) , V_71 -> V_10 ,
F_49 ( V_71 ) ,
F_50 ( V_71 ) ) ;
break;
case V_80 :
F_21 ( F_48 ( V_71 ) , V_71 -> V_10 ,
F_49 ( V_71 ) ,
F_50 ( V_71 ) ,
F_51 ( V_73 -> V_78 ) ) ;
break;
}
break;
case F_17 ( V_81 ) :
switch ( V_73 -> type ) {
case V_77 :
F_42 ( F_48 ( V_71 ) , V_71 -> V_10 ,
F_49 ( V_71 ) ,
F_50 ( V_71 ) ,
V_73 -> V_78 ) ;
break;
case V_79 :
F_35 ( F_48 ( V_71 ) , V_71 -> V_10 ,
F_49 ( V_71 ) ,
F_50 ( V_71 ) ) ;
break;
case V_80 :
F_42 ( F_48 ( V_71 ) , V_71 -> V_10 ,
F_49 ( V_71 ) ,
F_50 ( V_71 ) ,
F_52 ( V_73 -> V_78 ) ) ;
break;
}
break;
default:
break;
}
V_75:
V_69 -> V_82 . V_31 = V_83 ;
}
static int F_53 ( const struct V_84 * V_85 ,
const struct V_66 * V_67 ,
const struct V_86 * * V_56 )
{
return F_54 ( V_85 -> V_87 , ( 1 << V_88 ) |
( 1 << V_89 ) ) ;
}
static int F_55 ( const struct V_84 * V_85 ,
const struct V_66 * V_67 ,
const struct V_90 * const V_91 [] )
{
struct V_72 * V_73 = F_45 ( V_67 ) ;
int V_78 ;
if ( V_91 [ V_92 ] == NULL )
return - V_93 ;
V_73 -> type = F_56 ( F_57 ( V_91 [ V_92 ] ) ) ;
switch ( V_73 -> type ) {
case V_77 :
case V_80 :
if ( V_91 [ V_94 ] == NULL )
return - V_93 ;
V_78 = F_58 ( V_91 [ V_94 ] ) ;
if ( V_73 -> type == V_80 &&
V_78 > V_95 )
return - V_93 ;
V_73 -> V_78 = V_78 ;
break;
case V_79 :
break;
default:
return - V_93 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_10 ,
const struct V_66 * V_67 )
{
const struct V_72 * V_73 = F_45 ( V_67 ) ;
if ( F_60 ( V_10 , V_92 , F_61 ( V_73 -> type ) ) )
goto V_96;
switch ( V_73 -> type ) {
case V_77 :
case V_80 :
if ( F_62 ( V_10 , V_94 , V_73 -> V_78 ) )
goto V_96;
break;
default:
break;
}
return 0 ;
V_96:
return - 1 ;
}
static int T_5 F_63 ( void )
{
return F_64 ( & V_97 ) ;
}
static void T_6 F_65 ( void )
{
F_66 ( & V_97 ) ;
}
