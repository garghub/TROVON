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
static int F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
T_1 V_12 ;
if ( ! F_8 ( V_2 , sizeof( struct V_10 ) ) )
return 0 ;
V_11 = F_9 ( V_2 ) ;
if ( V_11 -> V_13 < 5 || V_11 -> V_14 != 4 )
return 0 ;
V_12 = F_10 ( V_11 -> V_15 ) ;
if ( V_2 -> V_12 < V_12 )
return 0 ;
else if ( V_12 < ( V_11 -> V_13 * 4 ) )
return 0 ;
if ( ! F_8 ( V_2 , V_11 -> V_13 * 4 ) )
return 0 ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_3 ;
struct V_10 * V_17 ;
const struct V_18 * V_19 ;
struct V_18 V_20 ;
if ( ! F_7 ( V_2 ) )
return;
V_19 = F_12 ( V_2 , & V_20 , V_16 ) ;
if ( ! V_19 )
return;
V_3 = F_13 ( sizeof( struct V_10 ) + sizeof( struct V_18 ) +
V_21 , V_22 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_21 ) ;
V_17 = F_15 ( V_3 , V_2 , V_23 ,
V_24 ) ;
F_16 ( V_3 , V_2 , V_19 ) ;
V_17 -> V_25 = V_24 ;
V_17 -> V_15 = F_17 ( V_3 -> V_12 ) ;
F_18 ( V_17 ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_2 -> V_26 ) , V_3 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_16 ,
T_2 V_27 )
{
struct V_1 * V_3 ;
struct V_10 * V_17 ;
struct V_28 * V_29 ;
unsigned int V_12 ;
void * V_30 ;
T_3 V_31 ;
if ( ! F_7 ( V_2 ) )
return;
if ( F_9 ( V_2 ) -> V_32 & F_17 ( V_33 ) )
return;
V_12 = F_22 (unsigned int, 536 , oldskb->len) ;
if ( ! F_8 ( V_2 , V_12 ) )
return;
if ( F_23 ( V_2 , V_16 , F_24 ( V_2 ) , 0 ) )
return;
V_3 = F_13 ( sizeof( struct V_10 ) + sizeof( struct V_28 ) +
V_21 + V_12 , V_22 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_21 ) ;
V_17 = F_15 ( V_3 , V_2 , V_34 ,
V_24 ) ;
F_25 ( V_3 ) ;
V_29 = (struct V_28 * ) F_26 ( V_3 , sizeof( struct V_28 ) ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> type = V_35 ;
V_29 -> V_27 = V_27 ;
V_30 = F_26 ( V_3 , V_12 ) ;
memcpy ( V_30 , F_27 ( V_2 ) , V_12 ) ;
V_31 = F_28 ( ( void * ) V_29 , V_12 + sizeof( struct V_28 ) , 0 ) ;
V_29 -> V_36 = F_29 ( V_31 ) ;
V_17 -> V_15 = F_17 ( V_3 -> V_12 ) ;
F_18 ( V_17 ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_2 -> V_26 ) , V_3 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
T_1 V_39 ;
if ( ! F_8 ( V_2 , sizeof( struct V_37 ) ) )
return 0 ;
V_38 = F_31 ( V_2 ) ;
if ( V_38 -> V_14 != 6 )
return 0 ;
V_39 = F_10 ( V_38 -> V_40 ) ;
if ( V_39 + sizeof( struct V_37 ) > V_2 -> V_12 )
return 0 ;
return 1 ;
}
static void F_32 ( struct V_41 * V_41 ,
struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_3 ;
const struct V_18 * V_19 ;
struct V_18 V_20 ;
unsigned int V_42 ;
struct V_37 * V_43 ;
if ( ! F_30 ( V_2 ) )
return;
V_19 = F_33 ( V_2 , & V_20 , & V_42 , V_16 ) ;
if ( ! V_19 )
return;
V_3 = F_13 ( sizeof( struct V_37 ) + sizeof( struct V_18 ) +
V_21 , V_22 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_21 ) ;
V_43 = F_34 ( V_3 , V_2 , V_23 ,
V_41 -> V_44 . V_45 -> V_46 ) ;
F_35 ( V_3 , V_2 , V_19 , V_42 ) ;
V_43 -> V_40 = F_17 ( V_3 -> V_12 - sizeof( struct V_37 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_2 -> V_26 ) , V_3 ) ;
}
static void F_36 ( struct V_41 * V_41 ,
struct V_1 * V_2 , int V_16 ,
T_2 V_27 )
{
struct V_1 * V_3 ;
struct V_37 * V_43 ;
struct V_47 * V_48 ;
unsigned int V_12 ;
void * V_30 ;
if ( ! F_30 ( V_2 ) )
return;
V_12 = F_22 (unsigned int, 1220 , oldskb->len) ;
if ( ! F_8 ( V_2 , V_12 ) )
return;
V_3 = F_13 ( sizeof( struct V_10 ) + sizeof( struct V_47 ) +
V_21 + V_12 , V_22 ) ;
if ( ! V_3 )
return;
F_14 ( V_3 , V_21 ) ;
V_43 = F_34 ( V_3 , V_2 , V_49 ,
V_41 -> V_44 . V_45 -> V_46 ) ;
F_25 ( V_3 ) ;
V_48 = (struct V_47 * ) F_26 ( V_3 , sizeof( struct V_47 ) ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_50 = V_51 ;
V_48 -> V_52 = V_27 ;
V_30 = F_26 ( V_3 , V_12 ) ;
memcpy ( V_30 , F_27 ( V_2 ) , V_12 ) ;
V_43 -> V_40 = F_17 ( V_3 -> V_12 - sizeof( struct V_37 ) ) ;
V_48 -> V_53 =
F_37 ( & V_43 -> V_54 , & V_43 -> V_55 ,
V_3 -> V_12 - sizeof( struct V_37 ) ,
V_49 ,
F_28 ( V_48 ,
V_3 -> V_12 - sizeof( struct V_37 ) ,
0 ) ) ;
F_1 ( V_2 , V_3 ) ;
F_19 ( F_20 ( V_2 -> V_26 ) , V_3 ) ;
}
static void F_38 ( const struct V_56 * V_57 ,
struct V_58 V_59 [ V_60 + 1 ] ,
const struct V_61 * V_62 )
{
struct V_63 * V_64 = F_39 ( V_57 ) ;
struct V_41 * V_41 = F_40 ( ( V_62 -> V_65 != NULL ) ? V_62 -> V_65 : V_62 -> V_66 ) ;
const unsigned char * V_67 = F_5 ( V_62 -> V_68 ) -> V_8 ;
if ( F_41 ( V_67 ) ||
F_42 ( V_67 ) )
goto V_66;
switch ( F_5 ( V_62 -> V_68 ) -> V_9 ) {
case F_17 ( V_69 ) :
switch ( V_64 -> type ) {
case V_70 :
F_21 ( V_62 -> V_68 ,
V_62 -> V_71 -> V_72 ,
V_64 -> V_73 ) ;
break;
case V_74 :
F_11 ( V_62 -> V_68 ,
V_62 -> V_71 -> V_72 ) ;
break;
case V_75 :
F_21 ( V_62 -> V_68 ,
V_62 -> V_71 -> V_72 ,
F_43 ( V_64 -> V_73 ) ) ;
break;
}
break;
case F_17 ( V_76 ) :
switch ( V_64 -> type ) {
case V_70 :
F_36 ( V_41 , V_62 -> V_68 ,
V_62 -> V_71 -> V_72 ,
V_64 -> V_73 ) ;
break;
case V_74 :
F_32 ( V_41 , V_62 -> V_68 ,
V_62 -> V_71 -> V_72 ) ;
break;
case V_75 :
F_36 ( V_41 , V_62 -> V_68 ,
V_62 -> V_71 -> V_72 ,
F_44 ( V_64 -> V_73 ) ) ;
break;
}
break;
default:
break;
}
V_66:
V_59 [ V_77 ] . V_78 = V_79 ;
}
static int F_45 ( const struct V_80 * V_81 )
{
struct V_82 * V_83 ;
if ( V_81 -> V_84 & V_85 ) {
V_83 = V_82 ( V_81 ) ;
switch ( V_83 -> V_71 [ 0 ] . V_72 ) {
case V_86 :
case V_87 :
break;
default:
return - V_88 ;
}
}
return 0 ;
}
static int F_46 ( const struct V_89 * V_90 ,
const struct V_56 * V_57 ,
const struct V_91 * const V_92 [] )
{
struct V_63 * V_64 = F_39 ( V_57 ) ;
int V_73 , V_93 ;
V_93 = F_45 ( V_90 -> V_81 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_92 [ V_94 ] == NULL )
return - V_95 ;
V_64 -> type = F_47 ( F_48 ( V_92 [ V_94 ] ) ) ;
switch ( V_64 -> type ) {
case V_70 :
case V_75 :
if ( V_92 [ V_96 ] == NULL )
return - V_95 ;
V_73 = F_49 ( V_92 [ V_96 ] ) ;
if ( V_64 -> type == V_75 &&
V_73 > V_97 )
return - V_95 ;
V_64 -> V_73 = V_73 ;
break;
case V_74 :
break;
default:
return - V_95 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_68 ,
const struct V_56 * V_57 )
{
const struct V_63 * V_64 = F_39 ( V_57 ) ;
if ( F_51 ( V_68 , V_94 , F_52 ( V_64 -> type ) ) )
goto V_98;
switch ( V_64 -> type ) {
case V_70 :
case V_75 :
if ( F_53 ( V_68 , V_96 , V_64 -> V_73 ) )
goto V_98;
break;
}
return 0 ;
V_98:
return - 1 ;
}
static int F_54 ( const struct V_89 * V_90 ,
const struct V_56 * V_57 ,
const struct V_58 * * V_59 )
{
return F_45 ( V_90 -> V_81 ) ;
}
static int T_4 F_55 ( void )
{
return F_56 ( & V_99 ) ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_99 ) ;
}
