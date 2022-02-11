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
static void F_7 ( struct V_10 * V_10 ,
struct V_1 * V_2 ,
const struct V_11 * V_12 ,
int V_13 )
{
struct V_1 * V_3 ;
struct V_14 * V_15 ;
const struct V_16 * V_17 ;
struct V_16 V_18 ;
if ( ! F_8 ( V_2 ) )
return;
V_17 = F_9 ( V_2 , & V_18 , V_13 ) ;
if ( ! V_17 )
return;
V_3 = F_10 ( sizeof( struct V_14 ) + sizeof( struct V_16 ) +
V_19 , V_20 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_19 ) ;
V_15 = F_12 ( V_3 , V_2 , V_21 ,
V_10 -> V_22 . V_23 ) ;
F_13 ( V_3 , V_2 , V_17 ) ;
V_15 -> V_24 = V_10 -> V_22 . V_23 ;
V_15 -> V_25 = F_14 ( V_3 -> V_26 ) ;
F_15 ( V_15 ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_12 ) , V_3 , false , true ) ;
}
static void F_18 ( struct V_10 * V_10 ,
struct V_1 * V_2 ,
const struct V_11 * V_12 ,
int V_13 , T_1 V_27 )
{
struct V_1 * V_3 ;
struct V_14 * V_15 ;
struct V_28 * V_29 ;
unsigned int V_26 ;
void * V_30 ;
T_2 V_31 ;
T_1 V_32 ;
if ( V_2 -> V_33 || ! F_8 ( V_2 ) )
return;
if ( F_19 ( V_2 ) -> V_34 & F_14 ( V_35 ) )
return;
V_26 = F_20 (unsigned int, 536 , oldskb->len) ;
if ( ! F_21 ( V_2 , V_26 ) )
return;
if ( F_22 ( V_2 , F_23 ( F_19 ( V_2 ) -> V_25 ) ) )
return;
if ( F_19 ( V_2 ) -> V_36 == V_21 ||
F_19 ( V_2 ) -> V_36 == V_37 )
V_32 = F_19 ( V_2 ) -> V_36 ;
else
V_32 = 0 ;
if ( ! F_24 ( V_2 ) &&
F_25 ( V_2 , V_13 , F_26 ( V_2 ) , V_32 ) )
return;
V_3 = F_10 ( sizeof( struct V_14 ) + sizeof( struct V_28 ) +
V_19 + V_26 , V_20 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_19 ) ;
V_15 = F_12 ( V_3 , V_2 , V_38 ,
V_10 -> V_22 . V_23 ) ;
F_27 ( V_3 ) ;
V_29 = (struct V_28 * ) F_28 ( V_3 , sizeof( struct V_28 ) ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> type = V_39 ;
V_29 -> V_27 = V_27 ;
V_30 = F_28 ( V_3 , V_26 ) ;
memcpy ( V_30 , F_29 ( V_2 ) , V_26 ) ;
V_31 = F_30 ( ( void * ) V_29 , V_26 + sizeof( struct V_28 ) , 0 ) ;
V_29 -> V_40 = F_31 ( V_31 ) ;
V_15 -> V_25 = F_14 ( V_3 -> V_26 ) ;
F_15 ( V_15 ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_12 ) , V_3 , false , true ) ;
}
static void F_32 ( struct V_10 * V_10 ,
struct V_1 * V_2 ,
const struct V_11 * V_12 ,
int V_13 )
{
struct V_1 * V_3 ;
const struct V_16 * V_17 ;
struct V_16 V_18 ;
unsigned int V_41 ;
struct V_42 * V_43 ;
if ( ! F_33 ( V_2 ) )
return;
V_17 = F_34 ( V_2 , & V_18 , & V_41 , V_13 ) ;
if ( ! V_17 )
return;
V_3 = F_10 ( sizeof( struct V_42 ) + sizeof( struct V_16 ) +
V_19 , V_20 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_19 ) ;
V_43 = F_35 ( V_3 , V_2 , V_21 ,
V_10 -> V_44 . V_45 -> V_46 ) ;
F_36 ( V_3 , V_2 , V_17 , V_41 ) ;
V_43 -> V_47 = F_14 ( V_3 -> V_26 - sizeof( struct V_42 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_12 ) , V_3 , false , true ) ;
}
static bool F_37 ( struct V_1 * V_48 , int V_13 )
{
const struct V_42 * V_49 = F_38 ( V_48 ) ;
int V_50 ;
T_3 V_51 ;
T_1 V_32 = V_49 -> V_52 ;
if ( V_48 -> V_33 )
return false ;
if ( F_24 ( V_48 ) )
return true ;
if ( V_49 -> V_47 &&
F_22 ( V_48 , F_23 ( V_49 -> V_47 ) + sizeof( * V_49 ) ) )
return false ;
V_50 = F_39 ( V_48 , ( ( T_1 * ) ( V_49 + 1 ) - V_48 -> V_53 ) , & V_32 , & V_51 ) ;
if ( V_50 < 0 || V_50 >= V_48 -> V_26 || ( V_51 & F_14 ( ~ 0x7 ) ) != 0 )
return false ;
return F_40 ( V_48 , V_13 , V_50 , V_32 ) == 0 ;
}
static void F_41 ( struct V_10 * V_10 ,
struct V_1 * V_2 ,
const struct V_11 * V_12 ,
int V_13 , T_1 V_27 )
{
struct V_1 * V_3 ;
struct V_42 * V_43 ;
struct V_54 * V_55 ;
unsigned int V_26 ;
void * V_30 ;
if ( ! F_33 ( V_2 ) )
return;
V_26 = F_20 (unsigned int, 1220 , oldskb->len) ;
if ( ! F_21 ( V_2 , V_26 ) )
return;
if ( ! F_37 ( V_2 , V_13 ) )
return;
V_3 = F_10 ( sizeof( struct V_14 ) + sizeof( struct V_54 ) +
V_19 + V_26 , V_20 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_19 ) ;
V_43 = F_35 ( V_3 , V_2 , V_56 ,
V_10 -> V_44 . V_45 -> V_46 ) ;
F_27 ( V_3 ) ;
V_55 = (struct V_54 * ) F_28 ( V_3 , sizeof( struct V_54 ) ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_55 -> V_57 = V_58 ;
V_55 -> V_59 = V_27 ;
V_30 = F_28 ( V_3 , V_26 ) ;
memcpy ( V_30 , F_29 ( V_2 ) , V_26 ) ;
V_43 -> V_47 = F_14 ( V_3 -> V_26 - sizeof( struct V_42 ) ) ;
V_55 -> V_60 =
F_42 ( & V_43 -> V_61 , & V_43 -> V_62 ,
V_3 -> V_26 - sizeof( struct V_42 ) ,
V_56 ,
F_30 ( V_55 ,
V_3 -> V_26 - sizeof( struct V_42 ) ,
0 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_12 ) , V_3 , false , true ) ;
}
static void F_43 ( const struct V_63 * V_64 ,
struct V_65 * V_66 ,
const struct V_67 * V_68 )
{
struct V_69 * V_70 = F_44 ( V_64 ) ;
const unsigned char * V_71 = F_5 ( V_68 -> V_48 ) -> V_8 ;
if ( F_45 ( V_71 ) ||
F_46 ( V_71 ) )
goto V_72;
switch ( F_5 ( V_68 -> V_48 ) -> V_9 ) {
case F_14 ( V_73 ) :
switch ( V_70 -> type ) {
case V_74 :
F_18 ( V_68 -> V_10 , V_68 -> V_48 ,
V_68 -> V_75 , V_68 -> V_13 ,
V_70 -> V_76 ) ;
break;
case V_77 :
F_7 ( V_68 -> V_10 , V_68 -> V_48 ,
V_68 -> V_75 , V_68 -> V_13 ) ;
break;
case V_78 :
F_18 ( V_68 -> V_10 , V_68 -> V_48 ,
V_68 -> V_75 , V_68 -> V_13 ,
F_47 ( V_70 -> V_76 ) ) ;
break;
}
break;
case F_14 ( V_79 ) :
switch ( V_70 -> type ) {
case V_74 :
F_41 ( V_68 -> V_10 , V_68 -> V_48 ,
V_68 -> V_75 , V_68 -> V_13 ,
V_70 -> V_76 ) ;
break;
case V_77 :
F_32 ( V_68 -> V_10 , V_68 -> V_48 ,
V_68 -> V_75 , V_68 -> V_13 ) ;
break;
case V_78 :
F_41 ( V_68 -> V_10 , V_68 -> V_48 ,
V_68 -> V_75 , V_68 -> V_13 ,
F_48 ( V_70 -> V_76 ) ) ;
break;
}
break;
default:
break;
}
V_72:
V_66 -> V_80 . V_27 = V_81 ;
}
static int F_49 ( const struct V_82 * V_83 ,
const struct V_63 * V_64 ,
const struct V_84 * * V_53 )
{
return F_50 ( V_83 -> V_85 , ( 1 << V_86 ) |
( 1 << V_87 ) ) ;
}
static int F_51 ( const struct V_82 * V_83 ,
const struct V_63 * V_64 ,
const struct V_88 * const V_89 [] )
{
struct V_69 * V_70 = F_44 ( V_64 ) ;
int V_76 , V_90 ;
V_90 = F_49 ( V_83 , V_64 , NULL ) ;
if ( V_90 < 0 )
return V_90 ;
if ( V_89 [ V_91 ] == NULL )
return - V_92 ;
V_70 -> type = F_52 ( F_53 ( V_89 [ V_91 ] ) ) ;
switch ( V_70 -> type ) {
case V_74 :
case V_78 :
if ( V_89 [ V_93 ] == NULL )
return - V_92 ;
V_76 = F_54 ( V_89 [ V_93 ] ) ;
if ( V_70 -> type == V_78 &&
V_76 > V_94 )
return - V_92 ;
V_70 -> V_76 = V_76 ;
break;
case V_77 :
break;
default:
return - V_92 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_48 ,
const struct V_63 * V_64 )
{
const struct V_69 * V_70 = F_44 ( V_64 ) ;
if ( F_56 ( V_48 , V_91 , F_57 ( V_70 -> type ) ) )
goto V_95;
switch ( V_70 -> type ) {
case V_74 :
case V_78 :
if ( F_58 ( V_48 , V_93 , V_70 -> V_76 ) )
goto V_95;
break;
default:
break;
}
return 0 ;
V_95:
return - 1 ;
}
static int T_4 F_59 ( void )
{
return F_60 ( & V_96 ) ;
}
static void T_5 F_61 ( void )
{
F_62 ( & V_96 ) ;
}
