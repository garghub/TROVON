static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
F_3 ( V_3 , V_4 ) ;
F_4 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = false ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_3 )
{
F_6 ( V_3 -> V_8 ) ;
F_6 ( V_3 -> V_9 ) ;
F_3 ( V_3 -> V_3 , NULL ) ;
F_6 ( V_3 ) ;
}
static void F_7 ( struct V_1 * V_10 ,
struct V_11 * V_12 )
{
int V_13 = 0 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
V_10 -> V_18 = - V_19 ;
V_10 -> V_20 = V_12 -> V_20 ;
V_15 = & V_12 -> V_14 ;
if ( V_15 -> V_21 == 0 )
goto V_22;
V_10 -> V_8 = F_2 ( V_15 -> V_21 , V_23 ) ;
if ( ! V_10 -> V_8 )
goto V_22;
memcpy ( V_10 -> V_8 , V_15 , V_15 -> V_21 ) ;
V_10 -> V_24 = V_15 -> V_15 [ 0 ] . V_25 ;
if ( V_10 -> V_24 == 0 ) {
V_10 -> V_18 = - V_26 ;
goto V_22;
}
V_10 -> V_9 = F_2 ( V_10 -> V_24 ,
V_23 ) ;
if ( ! V_10 -> V_9 ) {
V_10 -> V_18 = - V_19 ;
goto V_22;
}
memcpy ( V_10 -> V_9 ,
( ( unsigned char * ) V_15 ) + V_15 -> V_21 ,
V_15 -> V_15 [ 0 ] . V_25 ) ;
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 . type = V_27 ;
V_17 . V_28 = sizeof( struct V_29 ) ;
V_17 . V_17 . V_30 . type = V_31 ;
V_17 . V_17 . V_30 . V_28 = 1 ;
V_17 . V_17 . V_32 = 0 ;
V_13 = F_8 ( V_10 -> V_3 -> V_33 ,
& V_17 ,
sizeof( struct V_34 ) - sizeof( unsigned char ) +
sizeof( struct V_29 ) ,
( unsigned long ) & V_17 ,
V_35 ,
V_36 ) ;
if ( ! V_13 )
V_10 -> V_18 = 0 ;
V_22:
F_9 ( & V_10 -> V_6 ) ;
return;
}
static void F_10 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_34 * V_39 ;
struct V_40 * V_41 ;
struct V_1 * V_4 = F_11 ( V_3 ) ;
struct V_42 * V_43 ;
V_39 = (struct V_34 * ) ( ( unsigned long ) V_38 +
( V_38 -> V_44 << 3 ) ) ;
if ( V_39 -> type != V_27 )
return;
V_41 = (struct V_40 * ) V_39 -> V_45 ;
switch ( V_41 -> V_30 . type ) {
case V_46 :
if ( ( V_39 -> V_28 + sizeof( struct V_34 )
- sizeof( unsigned char ) )
> sizeof( struct V_16 ) ) {
F_12 ( 1 ) ;
break;
}
memcpy ( & V_4 -> V_47 , V_39 ,
V_39 -> V_28 + sizeof( struct V_34 ) -
sizeof( unsigned char ) ) ;
F_9 ( & V_4 -> V_6 ) ;
break;
case V_48 :
F_12 ( V_39 -> V_28 < sizeof( struct V_49 ) ) ;
F_7 ( V_4 ,
(struct V_11 * ) V_39 -> V_45 ) ;
break;
case V_50 :
V_43 =
(struct V_42 * ) V_39 -> V_45 ;
if ( ! V_4 -> V_7 )
break;
F_13 ( V_4 -> V_51 ,
V_52 , V_43 -> V_53 ,
V_43 -> V_30 . V_28 , 1 ) ;
break;
default:
F_14 ( L_1 ,
V_41 -> V_30 . type , V_41 -> V_30 . V_28 ) ;
break;
}
}
static void F_15 ( void * V_54 )
{
const int V_55 = 0x100 ;
int V_13 ;
struct V_2 * V_3 = V_54 ;
T_1 V_56 ;
T_2 V_57 ;
struct V_37 * V_15 ;
unsigned char * V_53 ;
int V_58 = V_55 ;
V_53 = F_16 ( V_58 , V_23 ) ;
if ( ! V_53 )
return;
do {
V_13 = F_17 ( V_3 -> V_33 , V_53 ,
V_58 , & V_56 , & V_57 ) ;
switch ( V_13 ) {
case 0 :
if ( V_56 <= 0 ) {
F_6 ( V_53 ) ;
return;
}
V_15 = (struct V_37 * ) V_53 ;
switch ( V_15 -> type ) {
case V_59 :
break;
case V_35 :
F_10 ( V_3 , V_15 ) ;
break;
default:
F_14 ( L_2 ,
V_15 -> type , V_57 , V_56 ) ;
break;
}
break;
case - V_60 :
F_6 ( V_53 ) ;
V_58 = V_56 ;
V_53 = F_16 ( V_56 , V_23 ) ;
if ( ! V_53 )
return;
break;
}
} while ( 1 );
}
static int F_18 ( struct V_2 * V_3 )
{
int V_13 = 0 ;
int V_61 ;
struct V_1 * V_4 = F_11 ( V_3 ) ;
struct V_16 * V_62 ;
struct V_16 * V_63 ;
V_62 = & V_4 -> V_64 ;
memset ( V_62 , 0 , sizeof( struct V_16 ) ) ;
V_62 -> type = V_27 ;
V_62 -> V_28 = sizeof( struct V_65 ) ;
V_62 -> V_62 . V_30 . type = V_66 ;
V_62 -> V_62 . V_30 . V_28 = sizeof( unsigned int ) ;
V_62 -> V_62 . V_67 . V_68 = V_69 ;
V_13 = F_8 ( V_3 -> V_33 , V_62 ,
sizeof( struct V_34 ) -
sizeof( unsigned char ) +
sizeof( struct V_65 ) ,
( unsigned long ) V_62 ,
V_35 ,
V_36 ) ;
if ( V_13 )
goto V_22;
V_61 = F_19 ( & V_4 -> V_6 , 5 * V_70 ) ;
if ( ! V_61 ) {
V_13 = - V_71 ;
goto V_22;
}
V_63 = & V_4 -> V_47 ;
if ( ! V_63 -> V_63 . V_72 ) {
F_14 ( L_3 ,
V_69 ) ;
V_13 = - V_73 ;
goto V_22;
}
V_61 = F_19 ( & V_4 -> V_6 , 5 * V_70 ) ;
if ( ! V_61 ) {
V_13 = - V_71 ;
goto V_22;
}
V_13 = V_4 -> V_18 ;
V_22:
return V_13 ;
}
static int F_20 ( struct V_51 * V_74 )
{
struct V_2 * V_75 = F_21 ( V_74 ) ;
struct V_1 * V_4 = F_11 ( V_75 ) ;
return F_22 ( V_74 , V_4 -> V_9 ,
V_4 -> V_24 ) ;
}
static int F_23 ( struct V_51 * V_74 )
{
return 0 ;
}
static int F_24 ( struct V_51 * V_74 )
{
return 0 ;
}
static void F_25 ( struct V_51 * V_74 )
{
}
static void F_26 ( struct V_51 * V_74 )
{
}
static int F_27 ( struct V_2 * V_3 ,
const struct V_76 * V_77 )
{
int V_13 ;
struct V_1 * V_4 ;
struct V_51 * V_78 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_19 ;
V_13 = F_28 ( V_3 -> V_33 ,
V_79 ,
V_80 ,
NULL ,
0 ,
F_15 ,
V_3
) ;
if ( V_13 )
goto V_81;
V_13 = F_18 ( V_3 ) ;
if ( V_13 )
goto V_82;
if ( V_4 -> V_9 [ 14 ] == 0x25 )
V_4 -> V_9 [ 14 ] = 0x29 ;
V_78 = F_29 () ;
if ( F_30 ( V_78 ) ) {
V_13 = F_31 ( V_78 ) ;
goto V_82;
}
V_78 -> V_83 = & V_84 ;
V_78 -> V_85 = & V_86 ;
V_78 -> V_87 = V_88 ;
V_78 -> V_89 = V_4 -> V_20 . V_89 ;
V_78 -> V_90 = V_4 -> V_20 . V_90 ;
V_78 -> V_68 = V_4 -> V_20 . V_68 ;
V_4 -> V_51 = V_78 ;
sprintf ( V_78 -> V_91 , L_4 , L_5 ) ;
F_32 ( V_78 , V_3 ) ;
V_13 = F_33 ( V_78 ) ;
if ( V_13 )
goto V_82;
V_13 = F_34 ( V_78 ) ;
if ( V_13 ) {
F_35 ( V_78 , L_6 ) ;
goto V_92;
}
V_13 = F_36 ( V_78 , V_93 | V_94 ) ;
if ( V_13 ) {
F_35 ( V_78 , L_7 ) ;
goto V_92;
}
V_4 -> V_95 = true ;
V_4 -> V_7 = true ;
return V_13 ;
V_92:
F_37 ( V_78 ) ;
V_82:
F_38 ( V_3 -> V_33 ) ;
V_81:
F_5 ( V_4 ) ;
return V_13 ;
}
static int F_39 ( struct V_2 * V_75 )
{
struct V_1 * V_4 = F_11 ( V_75 ) ;
F_38 ( V_75 -> V_33 ) ;
F_40 ( V_4 -> V_51 ) ;
F_37 ( V_4 -> V_51 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_96 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_96 ) ;
}
