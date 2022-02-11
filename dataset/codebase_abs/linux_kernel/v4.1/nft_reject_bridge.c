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
static void F_7 ( struct V_1 * V_2 ,
const struct V_10 * V_11 ,
int V_12 )
{
struct V_1 * V_3 ;
struct V_13 * V_14 ;
const struct V_15 * V_16 ;
struct V_15 V_17 ;
if ( ! F_8 ( V_2 ) )
return;
V_16 = F_9 ( V_2 , & V_17 , V_12 ) ;
if ( ! V_16 )
return;
V_3 = F_10 ( sizeof( struct V_13 ) + sizeof( struct V_15 ) +
V_18 , V_19 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_18 ) ;
V_14 = F_12 ( V_3 , V_2 , V_20 ,
V_21 ) ;
F_13 ( V_3 , V_2 , V_16 ) ;
V_14 -> V_22 = V_21 ;
V_14 -> V_23 = F_14 ( V_3 -> V_24 ) ;
F_15 ( V_14 ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_11 ) , V_3 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
const struct V_10 * V_11 ,
int V_12 , T_1 V_25 )
{
struct V_1 * V_3 ;
struct V_13 * V_14 ;
struct V_26 * V_27 ;
unsigned int V_24 ;
void * V_28 ;
T_2 V_29 ;
T_1 V_30 ;
if ( V_2 -> V_31 || ! F_8 ( V_2 ) )
return;
if ( F_19 ( V_2 ) -> V_32 & F_14 ( V_33 ) )
return;
V_24 = F_20 (unsigned int, 536 , oldskb->len) ;
if ( ! F_21 ( V_2 , V_24 ) )
return;
if ( F_22 ( V_2 , F_23 ( F_19 ( V_2 ) -> V_23 ) ) )
return;
if ( F_19 ( V_2 ) -> V_34 == V_20 ||
F_19 ( V_2 ) -> V_34 == V_35 )
V_30 = F_19 ( V_2 ) -> V_34 ;
else
V_30 = 0 ;
if ( ! F_24 ( V_2 ) &&
F_25 ( V_2 , V_12 , F_26 ( V_2 ) , V_30 ) )
return;
V_3 = F_10 ( sizeof( struct V_13 ) + sizeof( struct V_26 ) +
V_18 + V_24 , V_19 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_18 ) ;
V_14 = F_12 ( V_3 , V_2 , V_36 ,
V_21 ) ;
F_27 ( V_3 ) ;
V_27 = (struct V_26 * ) F_28 ( V_3 , sizeof( struct V_26 ) ) ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> type = V_37 ;
V_27 -> V_25 = V_25 ;
V_28 = F_28 ( V_3 , V_24 ) ;
memcpy ( V_28 , F_29 ( V_2 ) , V_24 ) ;
V_29 = F_30 ( ( void * ) V_27 , V_24 + sizeof( struct V_26 ) , 0 ) ;
V_27 -> V_38 = F_31 ( V_29 ) ;
V_14 -> V_23 = F_14 ( V_3 -> V_24 ) ;
F_15 ( V_14 ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_11 ) , V_3 ) ;
}
static void F_32 ( struct V_39 * V_39 ,
struct V_1 * V_2 ,
const struct V_10 * V_11 ,
int V_12 )
{
struct V_1 * V_3 ;
const struct V_15 * V_16 ;
struct V_15 V_17 ;
unsigned int V_40 ;
struct V_41 * V_42 ;
if ( ! F_33 ( V_2 ) )
return;
V_16 = F_34 ( V_2 , & V_17 , & V_40 , V_12 ) ;
if ( ! V_16 )
return;
V_3 = F_10 ( sizeof( struct V_41 ) + sizeof( struct V_15 ) +
V_18 , V_19 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_18 ) ;
V_42 = F_35 ( V_3 , V_2 , V_20 ,
V_39 -> V_43 . V_44 -> V_45 ) ;
F_36 ( V_3 , V_2 , V_16 , V_40 ) ;
V_42 -> V_46 = F_14 ( V_3 -> V_24 - sizeof( struct V_41 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_11 ) , V_3 ) ;
}
static bool F_37 ( struct V_1 * V_47 , int V_12 )
{
const struct V_41 * V_48 = F_38 ( V_47 ) ;
int V_49 ;
T_3 V_50 ;
T_1 V_30 = V_48 -> V_51 ;
if ( V_47 -> V_31 )
return false ;
if ( F_24 ( V_47 ) )
return true ;
if ( V_48 -> V_46 &&
F_22 ( V_47 , F_23 ( V_48 -> V_46 ) + sizeof( * V_48 ) ) )
return false ;
V_49 = F_39 ( V_47 , ( ( T_1 * ) ( V_48 + 1 ) - V_47 -> V_52 ) , & V_30 , & V_50 ) ;
if ( V_49 < 0 || V_49 >= V_47 -> V_24 || ( V_50 & F_14 ( ~ 0x7 ) ) != 0 )
return false ;
return F_40 ( V_47 , V_12 , V_49 , V_30 ) == 0 ;
}
static void F_41 ( struct V_39 * V_39 ,
struct V_1 * V_2 ,
const struct V_10 * V_11 ,
int V_12 , T_1 V_25 )
{
struct V_1 * V_3 ;
struct V_41 * V_42 ;
struct V_53 * V_54 ;
unsigned int V_24 ;
void * V_28 ;
if ( ! F_33 ( V_2 ) )
return;
V_24 = F_20 (unsigned int, 1220 , oldskb->len) ;
if ( ! F_21 ( V_2 , V_24 ) )
return;
if ( ! F_37 ( V_2 , V_12 ) )
return;
V_3 = F_10 ( sizeof( struct V_13 ) + sizeof( struct V_53 ) +
V_18 + V_24 , V_19 ) ;
if ( ! V_3 )
return;
F_11 ( V_3 , V_18 ) ;
V_42 = F_35 ( V_3 , V_2 , V_55 ,
V_39 -> V_43 . V_44 -> V_45 ) ;
F_27 ( V_3 ) ;
V_54 = (struct V_53 * ) F_28 ( V_3 , sizeof( struct V_53 ) ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_56 = V_57 ;
V_54 -> V_58 = V_25 ;
V_28 = F_28 ( V_3 , V_24 ) ;
memcpy ( V_28 , F_29 ( V_2 ) , V_24 ) ;
V_42 -> V_46 = F_14 ( V_3 -> V_24 - sizeof( struct V_41 ) ) ;
V_54 -> V_59 =
F_42 ( & V_42 -> V_60 , & V_42 -> V_61 ,
V_3 -> V_24 - sizeof( struct V_41 ) ,
V_55 ,
F_30 ( V_54 ,
V_3 -> V_24 - sizeof( struct V_41 ) ,
0 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_16 ( F_17 ( V_11 ) , V_3 ) ;
}
static void F_43 ( const struct V_62 * V_63 ,
struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 = F_44 ( V_63 ) ;
struct V_39 * V_39 = F_45 ( ( V_67 -> V_70 != NULL ) ? V_67 -> V_70 : V_67 -> V_71 ) ;
const unsigned char * V_72 = F_5 ( V_67 -> V_47 ) -> V_8 ;
if ( F_46 ( V_72 ) ||
F_47 ( V_72 ) )
goto V_71;
switch ( F_5 ( V_67 -> V_47 ) -> V_9 ) {
case F_14 ( V_73 ) :
switch ( V_69 -> type ) {
case V_74 :
F_18 ( V_67 -> V_47 , V_67 -> V_70 ,
V_67 -> V_75 -> V_76 ,
V_69 -> V_77 ) ;
break;
case V_78 :
F_7 ( V_67 -> V_47 , V_67 -> V_70 ,
V_67 -> V_75 -> V_76 ) ;
break;
case V_79 :
F_18 ( V_67 -> V_47 , V_67 -> V_70 ,
V_67 -> V_75 -> V_76 ,
F_48 ( V_69 -> V_77 ) ) ;
break;
}
break;
case F_14 ( V_80 ) :
switch ( V_69 -> type ) {
case V_74 :
F_41 ( V_39 , V_67 -> V_47 , V_67 -> V_70 ,
V_67 -> V_75 -> V_76 ,
V_69 -> V_77 ) ;
break;
case V_78 :
F_32 ( V_39 , V_67 -> V_47 , V_67 -> V_70 ,
V_67 -> V_75 -> V_76 ) ;
break;
case V_79 :
F_41 ( V_39 , V_67 -> V_47 , V_67 -> V_70 ,
V_67 -> V_75 -> V_76 ,
F_49 ( V_69 -> V_77 ) ) ;
break;
}
break;
default:
break;
}
V_71:
V_65 -> V_81 . V_25 = V_82 ;
}
static int F_50 ( const struct V_83 * V_84 ,
const struct V_62 * V_63 ,
const struct V_85 * * V_52 )
{
return F_51 ( V_84 -> V_86 , ( 1 << V_87 ) |
( 1 << V_88 ) ) ;
}
static int F_52 ( const struct V_83 * V_84 ,
const struct V_62 * V_63 ,
const struct V_89 * const V_90 [] )
{
struct V_68 * V_69 = F_44 ( V_63 ) ;
int V_77 , V_91 ;
V_91 = F_50 ( V_84 , V_63 , NULL ) ;
if ( V_91 < 0 )
return V_91 ;
if ( V_90 [ V_92 ] == NULL )
return - V_93 ;
V_69 -> type = F_53 ( F_54 ( V_90 [ V_92 ] ) ) ;
switch ( V_69 -> type ) {
case V_74 :
case V_79 :
if ( V_90 [ V_94 ] == NULL )
return - V_93 ;
V_77 = F_55 ( V_90 [ V_94 ] ) ;
if ( V_69 -> type == V_79 &&
V_77 > V_95 )
return - V_93 ;
V_69 -> V_77 = V_77 ;
break;
case V_78 :
break;
default:
return - V_93 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_47 ,
const struct V_62 * V_63 )
{
const struct V_68 * V_69 = F_44 ( V_63 ) ;
if ( F_57 ( V_47 , V_92 , F_58 ( V_69 -> type ) ) )
goto V_96;
switch ( V_69 -> type ) {
case V_74 :
case V_79 :
if ( F_59 ( V_47 , V_94 , V_69 -> V_77 ) )
goto V_96;
break;
default:
break;
}
return 0 ;
V_96:
return - 1 ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_97 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_97 ) ;
}
