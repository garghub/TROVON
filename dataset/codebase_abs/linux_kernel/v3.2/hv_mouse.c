static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
F_3 ( V_3 , V_4 ) ;
F_4 ( & V_4 -> V_6 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_3 )
{
F_6 ( V_3 -> V_7 ) ;
F_6 ( V_3 -> V_8 ) ;
F_3 ( V_3 -> V_3 , NULL ) ;
F_6 ( V_3 ) ;
}
static void F_7 ( struct V_1 * V_9 ,
struct V_10 * V_11 )
{
int V_12 = 0 ;
struct V_13 * V_14 ;
struct V_15 V_16 ;
V_9 -> V_17 = 0 ;
memcpy ( & V_9 -> V_18 , & V_11 -> V_18 ,
sizeof( struct V_19 ) ) ;
V_14 = & V_11 -> V_13 ;
F_8 ( V_14 -> V_20 == 0 ) ;
V_9 -> V_7 = F_2 ( V_14 -> V_20 , V_21 ) ;
if ( ! V_9 -> V_7 )
goto V_22;
memcpy ( V_9 -> V_7 , V_14 , V_14 -> V_20 ) ;
V_9 -> V_23 = V_14 -> V_14 [ 0 ] . V_24 ;
if ( V_9 -> V_23 == 0 )
goto V_22;
V_9 -> V_8 = F_2 ( V_9 -> V_23 ,
V_21 ) ;
if ( ! V_9 -> V_8 )
goto V_22;
memcpy ( V_9 -> V_8 ,
( ( unsigned char * ) V_14 ) + V_14 -> V_20 ,
V_14 -> V_14 [ 0 ] . V_24 ) ;
memset ( & V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 . type = V_25 ;
V_16 . V_26 = sizeof( struct V_27 ) ;
V_16 . V_16 . V_28 . type = V_29 ;
V_16 . V_16 . V_28 . V_26 = 1 ;
V_16 . V_16 . V_30 = 0 ;
V_12 = F_9 ( V_9 -> V_3 -> V_31 ,
& V_16 ,
sizeof( struct V_32 ) - sizeof( unsigned char ) +
sizeof( struct V_27 ) ,
( unsigned long ) & V_16 ,
V_33 ,
V_34 ) ;
if ( V_12 != 0 )
goto V_22;
F_10 ( & V_9 -> V_6 ) ;
return;
V_22:
F_6 ( V_9 -> V_7 ) ;
V_9 -> V_7 = NULL ;
F_6 ( V_9 -> V_8 ) ;
V_9 -> V_8 = NULL ;
V_9 -> V_17 = - 1 ;
F_10 ( & V_9 -> V_6 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_32 * V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_4 = F_12 ( V_3 ) ;
struct V_40 * V_41 ;
V_37 = (struct V_32 * ) ( ( unsigned long ) V_36 +
( V_36 -> V_42 << 3 ) ) ;
if ( V_37 -> type != V_25 )
return;
V_39 = (struct V_38 * ) & V_37 -> V_43 [ 0 ] ;
switch ( V_39 -> V_28 . type ) {
case V_44 :
memcpy ( & V_4 -> V_45 , V_37 ,
V_37 -> V_26 + sizeof( struct V_32 ) -
sizeof( unsigned char ) ) ;
F_10 ( & V_4 -> V_6 ) ;
break;
case V_46 :
F_8 ( V_37 -> V_26 < sizeof( struct V_19 ) ) ;
F_7 ( V_4 ,
(struct V_10 * ) & V_37 -> V_43 [ 0 ] ) ;
break;
case V_47 :
V_41 =
(struct V_40 * ) & V_37 -> V_43 [ 0 ] ;
if ( ! V_4 -> V_48 )
break;
F_13 ( V_4 -> V_49 ,
V_50 , V_41 -> V_51 ,
V_41 -> V_28 . V_26 , 1 ) ;
break;
default:
F_14 ( L_1 ,
V_39 -> V_28 . type , V_39 -> V_28 . V_26 ) ;
break;
}
}
static void F_15 ( void * V_52 )
{
const int V_53 = 0x100 ;
int V_12 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_52 ;
T_1 V_54 ;
T_2 V_55 ;
unsigned char V_36 [ 0x100 ] ;
struct V_35 * V_14 ;
unsigned char * V_51 = V_36 ;
int V_56 = V_53 ;
do {
V_12 = F_16 ( V_3 -> V_31 , V_51 ,
V_56 , & V_54 , & V_55 ) ;
if ( V_12 == 0 ) {
if ( V_54 > 0 ) {
V_14 = (struct V_35 * ) V_51 ;
switch ( V_14 -> type ) {
case V_57 :
break;
case V_33 :
F_11 (
V_3 , V_14 ) ;
break;
default:
F_14 ( L_2 ,
V_14 -> type ,
V_55 ,
V_54 ) ;
break;
}
if ( V_56 > V_53 ) {
F_6 ( V_51 ) ;
V_51 = V_36 ;
V_56 = V_53 ;
}
} else {
if ( V_56 > V_53 ) {
F_6 ( V_51 ) ;
V_51 = V_36 ;
V_56 = V_53 ;
}
break;
}
} else if ( V_12 == - V_58 ) {
V_56 = V_54 ;
V_51 = F_2 ( V_54 , V_21 ) ;
if ( V_51 == NULL ) {
V_51 = V_36 ;
V_56 = V_53 ;
break;
}
}
} while ( 1 );
return;
}
static int F_17 ( struct V_2 * V_3 )
{
int V_12 = 0 ;
int V_59 ;
struct V_1 * V_4 = F_12 ( V_3 ) ;
struct V_15 * V_60 ;
struct V_15 * V_61 ;
V_60 = & V_4 -> V_62 ;
memset ( V_60 , 0 , sizeof( struct V_15 ) ) ;
V_60 -> type = V_25 ;
V_60 -> V_26 = sizeof( struct V_63 ) ;
V_60 -> V_60 . V_28 . type = V_64 ;
V_60 -> V_60 . V_28 . V_26 = sizeof( unsigned int ) ;
V_60 -> V_60 . V_65 . V_66 = V_67 ;
V_12 = F_9 ( V_3 -> V_31 , V_60 ,
sizeof( struct V_32 ) -
sizeof( unsigned char ) +
sizeof( struct V_63 ) ,
( unsigned long ) V_60 ,
V_33 ,
V_34 ) ;
if ( V_12 != 0 )
goto V_22;
V_59 = F_18 ( & V_4 -> V_6 , 5 * V_68 ) ;
if ( V_59 == 0 ) {
V_12 = - V_69 ;
goto V_22;
}
V_61 = & V_4 -> V_45 ;
if ( ! V_61 -> V_61 . V_70 ) {
F_14 ( L_3 ,
V_67 ) ;
V_12 = - V_71 ;
goto V_22;
}
V_59 = F_18 ( & V_4 -> V_6 , 5 * V_68 ) ;
if ( V_59 == 0 ) {
V_12 = - V_69 ;
goto V_22;
}
if ( V_4 -> V_17 )
V_12 = - V_72 ;
V_22:
return V_12 ;
}
static int F_19 ( struct V_49 * V_73 )
{
return 0 ;
}
static void F_20 ( struct V_49 * V_73 )
{
}
static void F_21 ( struct V_2 * V_74 , void * V_36 , T_1 V_75 )
{
struct V_49 * V_76 ;
struct V_1 * V_9 = F_12 ( V_74 ) ;
V_76 = F_22 () ;
if ( F_23 ( V_76 ) )
return;
V_76 -> V_77 = & V_78 ;
V_76 -> V_79 = & V_80 ;
if ( F_24 ( V_76 , V_36 , V_75 ) )
return;
V_76 -> V_81 = V_82 ;
V_76 -> V_83 = V_9 -> V_18 . V_83 ;
V_76 -> V_84 = V_9 -> V_18 . V_84 ;
V_76 -> V_66 = V_9 -> V_18 . V_66 ;
sprintf ( V_76 -> V_85 , L_4 , L_5 ) ;
if ( ! F_25 ( V_76 , 0 ) ) {
V_76 -> V_86 |= V_87 ;
V_9 -> V_88 = 1 ;
}
V_9 -> V_49 = V_76 ;
}
static int F_26 ( struct V_2 * V_3 )
{
int V_12 = 0 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_72 ;
V_4 -> V_48 = false ;
V_12 = F_27 ( V_3 -> V_31 ,
V_89 ,
V_90 ,
NULL ,
0 ,
F_15 ,
V_3
) ;
if ( V_12 != 0 ) {
F_5 ( V_4 ) ;
return V_12 ;
}
V_12 = F_17 ( V_3 ) ;
if ( V_12 != 0 ) {
F_28 ( V_3 -> V_31 ) ;
F_5 ( V_4 ) ;
return V_12 ;
}
if ( V_4 -> V_8 [ 14 ] == 0x25 )
V_4 -> V_8 [ 14 ] = 0x29 ;
F_21 ( V_3 , V_4 -> V_8 ,
V_4 -> V_23 ) ;
V_4 -> V_48 = true ;
return V_12 ;
}
static int F_29 ( struct V_2 * V_74 ,
const struct V_91 * V_92 )
{
return F_26 ( V_74 ) ;
}
static int F_30 ( struct V_2 * V_74 )
{
struct V_1 * V_4 = F_12 ( V_74 ) ;
F_28 ( V_74 -> V_31 ) ;
if ( V_4 -> V_88 ) {
F_31 ( V_4 -> V_49 ) ;
V_4 -> V_88 = 0 ;
F_32 ( V_4 -> V_49 ) ;
}
F_5 ( V_4 ) ;
return 0 ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_93 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_93 ) ;
}
