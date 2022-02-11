static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 ;
V_5 = (struct V_4 * ) F_2 ( V_3 , V_6 ) ;
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
void * V_34 ;
T_3 V_35 ;
T_2 V_36 ;
if ( V_2 -> V_37 || ! F_7 ( V_2 ) )
return;
if ( F_9 ( V_2 ) -> V_38 & F_17 ( V_39 ) )
return;
V_13 = F_22 (unsigned int, 536 , oldskb->len) ;
if ( ! F_8 ( V_2 , V_13 ) )
return;
if ( F_23 ( V_2 , F_10 ( F_9 ( V_2 ) -> V_16 ) ) )
return;
if ( F_9 ( V_2 ) -> V_40 == V_27 ||
F_9 ( V_2 ) -> V_40 == V_41 )
V_36 = F_9 ( V_2 ) -> V_40 ;
else
V_36 = 0 ;
if ( ! F_24 ( V_2 ) &&
F_25 ( V_2 , V_20 , F_26 ( V_2 ) , V_36 ) )
return;
V_3 = F_13 ( sizeof( struct V_11 ) + sizeof( struct V_32 ) +
V_25 + V_13 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_21 = F_15 ( V_3 , V_2 , V_42 ,
V_17 -> V_28 . V_29 ) ;
F_27 ( V_3 ) ;
V_33 = (struct V_32 * ) F_28 ( V_3 , sizeof( struct V_32 ) ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> type = V_43 ;
V_33 -> V_31 = V_31 ;
V_34 = F_28 ( V_3 , V_13 ) ;
memcpy ( V_34 , F_29 ( V_2 ) , V_13 ) ;
V_35 = F_30 ( ( void * ) V_33 , V_13 + sizeof( struct V_32 ) , 0 ) ;
V_33 -> V_44 = F_31 ( V_35 ) ;
V_21 -> V_16 = F_17 ( V_3 -> V_13 ) ;
F_18 ( V_21 ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static int F_32 ( struct V_1 * V_10 )
{
struct V_45 * V_46 ;
T_1 V_47 ;
if ( ! F_8 ( V_10 , sizeof( struct V_45 ) ) )
return 0 ;
V_46 = F_33 ( V_10 ) ;
if ( V_46 -> V_15 != 6 )
return 0 ;
V_47 = F_10 ( V_46 -> V_48 ) ;
if ( V_47 + sizeof( struct V_45 ) > V_10 -> V_13 )
return 0 ;
return 1 ;
}
static void F_34 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 )
{
struct V_1 * V_3 ;
const struct V_22 * V_23 ;
struct V_22 V_24 ;
unsigned int V_49 ;
struct V_45 * V_50 ;
if ( ! F_32 ( V_2 ) )
return;
V_23 = F_35 ( V_2 , & V_24 , & V_49 , V_20 ) ;
if ( ! V_23 )
return;
V_3 = F_13 ( sizeof( struct V_45 ) + sizeof( struct V_22 ) +
V_25 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_50 = F_36 ( V_3 , V_2 , V_27 ,
V_17 -> V_51 . V_52 -> V_53 ) ;
F_37 ( V_3 , V_2 , V_23 , V_49 ) ;
V_50 -> V_48 = F_17 ( V_3 -> V_13 - sizeof( struct V_45 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static bool F_38 ( struct V_1 * V_10 , int V_20 )
{
const struct V_45 * V_54 = F_33 ( V_10 ) ;
int V_55 ;
T_4 V_56 ;
T_2 V_36 = V_54 -> V_57 ;
if ( V_10 -> V_37 )
return false ;
if ( F_24 ( V_10 ) )
return true ;
if ( V_54 -> V_48 &&
F_23 ( V_10 , F_10 ( V_54 -> V_48 ) + sizeof( * V_54 ) ) )
return false ;
V_55 = F_39 ( V_10 , ( ( T_2 * ) ( V_54 + 1 ) - V_10 -> V_58 ) , & V_36 , & V_56 ) ;
if ( V_55 < 0 || V_55 >= V_10 -> V_13 || ( V_56 & F_17 ( ~ 0x7 ) ) != 0 )
return false ;
return F_40 ( V_10 , V_20 , V_55 , V_36 ) == 0 ;
}
static void F_41 ( struct V_17 * V_17 ,
struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 , T_2 V_31 )
{
struct V_1 * V_3 ;
struct V_45 * V_50 ;
struct V_59 * V_60 ;
unsigned int V_13 ;
void * V_34 ;
if ( ! F_32 ( V_2 ) )
return;
V_13 = F_22 (unsigned int, 1220 , oldskb->len) ;
if ( ! F_8 ( V_2 , V_13 ) )
return;
if ( ! F_38 ( V_2 , V_20 ) )
return;
V_3 = F_13 ( sizeof( struct V_11 ) + sizeof( struct V_59 ) +
V_25 + V_13 , V_26 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_25 ) ;
V_50 = F_36 ( V_3 , V_2 , V_61 ,
V_17 -> V_51 . V_52 -> V_53 ) ;
F_27 ( V_3 ) ;
V_60 = (struct V_59 * ) F_28 ( V_3 , sizeof( struct V_59 ) ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_62 = V_63 ;
V_60 -> V_64 = V_31 ;
V_34 = F_28 ( V_3 , V_13 ) ;
memcpy ( V_34 , F_29 ( V_2 ) , V_13 ) ;
V_50 -> V_48 = F_17 ( V_3 -> V_13 - sizeof( struct V_45 ) ) ;
V_60 -> V_65 =
F_42 ( & V_50 -> V_66 , & V_50 -> V_67 ,
V_3 -> V_13 - sizeof( struct V_45 ) ,
V_61 ,
F_30 ( V_60 ,
V_3 -> V_13 - sizeof( struct V_45 ) ,
0 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_19 ) , V_3 , false , true ) ;
}
static void F_43 ( const struct V_68 * V_69 ,
struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_74 * V_75 = F_44 ( V_69 ) ;
const unsigned char * V_76 = F_5 ( V_73 -> V_10 ) -> V_8 ;
if ( F_45 ( V_76 ) ||
F_46 ( V_76 ) )
goto V_77;
switch ( F_5 ( V_73 -> V_10 ) -> V_9 ) {
case F_17 ( V_78 ) :
switch ( V_75 -> type ) {
case V_79 :
F_21 ( V_73 -> V_17 , V_73 -> V_10 ,
V_73 -> V_80 , V_73 -> V_20 ,
V_75 -> V_81 ) ;
break;
case V_82 :
F_11 ( V_73 -> V_17 , V_73 -> V_10 ,
V_73 -> V_80 , V_73 -> V_20 ) ;
break;
case V_83 :
F_21 ( V_73 -> V_17 , V_73 -> V_10 ,
V_73 -> V_80 , V_73 -> V_20 ,
F_47 ( V_75 -> V_81 ) ) ;
break;
}
break;
case F_17 ( V_84 ) :
switch ( V_75 -> type ) {
case V_79 :
F_41 ( V_73 -> V_17 , V_73 -> V_10 ,
V_73 -> V_80 , V_73 -> V_20 ,
V_75 -> V_81 ) ;
break;
case V_82 :
F_34 ( V_73 -> V_17 , V_73 -> V_10 ,
V_73 -> V_80 , V_73 -> V_20 ) ;
break;
case V_83 :
F_41 ( V_73 -> V_17 , V_73 -> V_10 ,
V_73 -> V_80 , V_73 -> V_20 ,
F_48 ( V_75 -> V_81 ) ) ;
break;
}
break;
default:
break;
}
V_77:
V_71 -> V_85 . V_31 = V_86 ;
}
static int F_49 ( const struct V_87 * V_88 ,
const struct V_68 * V_69 ,
const struct V_89 * * V_58 )
{
return F_50 ( V_88 -> V_90 , ( 1 << V_91 ) |
( 1 << V_92 ) ) ;
}
static int F_51 ( const struct V_87 * V_88 ,
const struct V_68 * V_69 ,
const struct V_93 * const V_94 [] )
{
struct V_74 * V_75 = F_44 ( V_69 ) ;
int V_81 , V_95 ;
V_95 = F_49 ( V_88 , V_69 , NULL ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_94 [ V_96 ] == NULL )
return - V_97 ;
V_75 -> type = F_52 ( F_53 ( V_94 [ V_96 ] ) ) ;
switch ( V_75 -> type ) {
case V_79 :
case V_83 :
if ( V_94 [ V_98 ] == NULL )
return - V_97 ;
V_81 = F_54 ( V_94 [ V_98 ] ) ;
if ( V_75 -> type == V_83 &&
V_81 > V_99 )
return - V_97 ;
V_75 -> V_81 = V_81 ;
break;
case V_82 :
break;
default:
return - V_97 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_10 ,
const struct V_68 * V_69 )
{
const struct V_74 * V_75 = F_44 ( V_69 ) ;
if ( F_56 ( V_10 , V_96 , F_57 ( V_75 -> type ) ) )
goto V_100;
switch ( V_75 -> type ) {
case V_79 :
case V_83 :
if ( F_58 ( V_10 , V_98 , V_75 -> V_81 ) )
goto V_100;
break;
default:
break;
}
return 0 ;
V_100:
return - 1 ;
}
static int T_5 F_59 ( void )
{
return F_60 ( & V_101 ) ;
}
static void T_6 F_61 ( void )
{
F_62 ( & V_101 ) ;
}
