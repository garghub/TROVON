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
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
struct V_1 * V_3 ;
struct V_11 * V_12 ;
const struct V_13 * V_14 ;
struct V_13 V_15 ;
if ( ! F_8 ( V_2 ) )
return;
V_14 = F_9 ( V_2 , & V_15 , V_10 ) ;
if ( ! V_14 )
return;
V_3 = F_10 ( sizeof( struct V_11 ) + sizeof( struct V_13 ) +
V_16 , V_17 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_16 ) ;
V_12 = F_12 ( V_3 , V_2 , V_18 ,
V_19 ) ;
F_13 ( V_3 , V_2 , V_14 ) ;
V_12 -> V_20 = V_19 ;
V_12 -> V_21 = F_14 ( V_3 -> V_22 ) ;
F_15 ( V_12 ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_2 -> V_23 ) , V_3 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_10 ,
T_1 V_24 )
{
struct V_1 * V_3 ;
struct V_11 * V_12 ;
struct V_25 * V_26 ;
unsigned int V_22 ;
void * V_27 ;
T_2 V_28 ;
if ( ! F_8 ( V_2 ) )
return;
if ( F_19 ( V_2 ) -> V_29 & F_14 ( V_30 ) )
return;
V_22 = F_20 (unsigned int, 536 , oldskb->len) ;
if ( ! F_21 ( V_2 , V_22 ) )
return;
if ( F_22 ( V_2 , V_10 , F_23 ( V_2 ) , 0 ) )
return;
V_3 = F_10 ( sizeof( struct V_11 ) + sizeof( struct V_25 ) +
V_16 + V_22 , V_17 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_16 ) ;
V_12 = F_12 ( V_3 , V_2 , V_31 ,
V_19 ) ;
F_24 ( V_3 ) ;
V_26 = (struct V_25 * ) F_25 ( V_3 , sizeof( struct V_25 ) ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> type = V_32 ;
V_26 -> V_24 = V_24 ;
V_27 = F_25 ( V_3 , V_22 ) ;
memcpy ( V_27 , F_26 ( V_2 ) , V_22 ) ;
V_28 = F_27 ( ( void * ) V_26 , V_22 + sizeof( struct V_25 ) , 0 ) ;
V_26 -> V_33 = F_28 ( V_28 ) ;
V_12 -> V_21 = F_14 ( V_3 -> V_22 ) ;
F_15 ( V_12 ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_2 -> V_23 ) , V_3 ) ;
}
static void F_29 ( struct V_34 * V_34 ,
struct V_1 * V_2 , int V_10 )
{
struct V_1 * V_3 ;
const struct V_13 * V_14 ;
struct V_13 V_15 ;
unsigned int V_35 ;
struct V_36 * V_37 ;
if ( ! F_30 ( V_2 ) )
return;
V_14 = F_31 ( V_2 , & V_15 , & V_35 , V_10 ) ;
if ( ! V_14 )
return;
V_3 = F_10 ( sizeof( struct V_36 ) + sizeof( struct V_13 ) +
V_16 , V_17 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_16 ) ;
V_37 = F_32 ( V_3 , V_2 , V_18 ,
V_34 -> V_38 . V_39 -> V_40 ) ;
F_33 ( V_3 , V_2 , V_14 , V_35 ) ;
V_37 -> V_41 = F_14 ( V_3 -> V_22 - sizeof( struct V_36 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_2 -> V_23 ) , V_3 ) ;
}
static void F_34 ( struct V_34 * V_34 ,
struct V_1 * V_2 , int V_10 ,
T_1 V_24 )
{
struct V_1 * V_3 ;
struct V_36 * V_37 ;
struct V_42 * V_43 ;
unsigned int V_22 ;
void * V_27 ;
if ( ! F_30 ( V_2 ) )
return;
V_22 = F_20 (unsigned int, 1220 , oldskb->len) ;
if ( ! F_21 ( V_2 , V_22 ) )
return;
V_3 = F_10 ( sizeof( struct V_11 ) + sizeof( struct V_42 ) +
V_16 + V_22 , V_17 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_16 ) ;
V_37 = F_32 ( V_3 , V_2 , V_44 ,
V_34 -> V_38 . V_39 -> V_40 ) ;
F_24 ( V_3 ) ;
V_43 = (struct V_42 * ) F_25 ( V_3 , sizeof( struct V_42 ) ) ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_45 = V_46 ;
V_43 -> V_47 = V_24 ;
V_27 = F_25 ( V_3 , V_22 ) ;
memcpy ( V_27 , F_26 ( V_2 ) , V_22 ) ;
V_37 -> V_41 = F_14 ( V_3 -> V_22 - sizeof( struct V_36 ) ) ;
V_43 -> V_48 =
F_35 ( & V_37 -> V_49 , & V_37 -> V_50 ,
V_3 -> V_22 - sizeof( struct V_36 ) ,
V_44 ,
F_27 ( V_43 ,
V_3 -> V_22 - sizeof( struct V_36 ) ,
0 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_2 -> V_23 ) , V_3 ) ;
}
static void F_36 ( const struct V_51 * V_52 ,
struct V_53 V_54 [ V_55 + 1 ] ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 = F_37 ( V_52 ) ;
struct V_34 * V_34 = F_38 ( ( V_57 -> V_60 != NULL ) ? V_57 -> V_60 : V_57 -> V_61 ) ;
const unsigned char * V_62 = F_5 ( V_57 -> V_63 ) -> V_8 ;
if ( F_39 ( V_62 ) ||
F_40 ( V_62 ) )
goto V_61;
switch ( F_5 ( V_57 -> V_63 ) -> V_9 ) {
case F_14 ( V_64 ) :
switch ( V_59 -> type ) {
case V_65 :
F_18 ( V_57 -> V_63 ,
V_57 -> V_66 -> V_67 ,
V_59 -> V_68 ) ;
break;
case V_69 :
F_7 ( V_57 -> V_63 ,
V_57 -> V_66 -> V_67 ) ;
break;
case V_70 :
F_18 ( V_57 -> V_63 ,
V_57 -> V_66 -> V_67 ,
F_41 ( V_59 -> V_68 ) ) ;
break;
}
break;
case F_14 ( V_71 ) :
switch ( V_59 -> type ) {
case V_65 :
F_34 ( V_34 , V_57 -> V_63 ,
V_57 -> V_66 -> V_67 ,
V_59 -> V_68 ) ;
break;
case V_69 :
F_29 ( V_34 , V_57 -> V_63 ,
V_57 -> V_66 -> V_67 ) ;
break;
case V_70 :
F_34 ( V_34 , V_57 -> V_63 ,
V_57 -> V_66 -> V_67 ,
F_42 ( V_59 -> V_68 ) ) ;
break;
}
break;
default:
break;
}
V_61:
V_54 [ V_72 ] . V_73 = V_74 ;
}
static int F_43 ( const struct V_75 * V_76 ,
const struct V_51 * V_52 ,
const struct V_53 * * V_54 )
{
return F_44 ( V_76 -> V_77 , ( 1 << V_78 ) |
( 1 << V_79 ) ) ;
}
static int F_45 ( const struct V_75 * V_76 ,
const struct V_51 * V_52 ,
const struct V_80 * const V_81 [] )
{
struct V_58 * V_59 = F_37 ( V_52 ) ;
int V_68 , V_82 ;
V_82 = F_43 ( V_76 , V_52 , NULL ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_81 [ V_83 ] == NULL )
return - V_84 ;
V_59 -> type = F_46 ( F_47 ( V_81 [ V_83 ] ) ) ;
switch ( V_59 -> type ) {
case V_65 :
case V_70 :
if ( V_81 [ V_85 ] == NULL )
return - V_84 ;
V_68 = F_48 ( V_81 [ V_85 ] ) ;
if ( V_59 -> type == V_70 &&
V_68 > V_86 )
return - V_84 ;
V_59 -> V_68 = V_68 ;
break;
case V_69 :
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_63 ,
const struct V_51 * V_52 )
{
const struct V_58 * V_59 = F_37 ( V_52 ) ;
if ( F_50 ( V_63 , V_83 , F_51 ( V_59 -> type ) ) )
goto V_87;
switch ( V_59 -> type ) {
case V_65 :
case V_70 :
if ( F_52 ( V_63 , V_85 , V_59 -> V_68 ) )
goto V_87;
break;
}
return 0 ;
V_87:
return - 1 ;
}
static int T_3 F_53 ( void )
{
return F_54 ( & V_88 ) ;
}
static void T_4 F_55 ( void )
{
F_56 ( & V_88 ) ;
}
