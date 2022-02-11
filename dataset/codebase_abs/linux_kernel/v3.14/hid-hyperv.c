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
V_10 -> V_8 = F_8 ( V_15 , V_15 -> V_21 , V_23 ) ;
if ( ! V_10 -> V_8 )
goto V_22;
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
V_13 = F_9 ( V_10 -> V_3 -> V_33 ,
& V_17 ,
sizeof( struct V_34 ) - sizeof( unsigned char ) +
sizeof( struct V_29 ) ,
( unsigned long ) & V_17 ,
V_35 ,
V_36 ) ;
if ( ! V_13 )
V_10 -> V_18 = 0 ;
V_22:
F_10 ( & V_10 -> V_6 ) ;
return;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_34 * V_39 ;
struct V_40 * V_41 ;
struct V_1 * V_4 = F_12 ( V_3 ) ;
struct V_42 * V_43 ;
T_1 V_44 ;
V_39 = (struct V_34 * ) ( ( unsigned long ) V_38 +
( V_38 -> V_45 << 3 ) ) ;
if ( V_39 -> type != V_27 )
return;
V_41 = (struct V_40 * ) V_39 -> V_46 ;
switch ( V_41 -> V_30 . type ) {
case V_47 :
if ( ( V_39 -> V_28 + sizeof( struct V_34 )
- sizeof( unsigned char ) )
> sizeof( struct V_16 ) ) {
F_13 ( 1 ) ;
break;
}
memcpy ( & V_4 -> V_48 , V_39 ,
V_39 -> V_28 + sizeof( struct V_34 ) -
sizeof( unsigned char ) ) ;
F_10 ( & V_4 -> V_6 ) ;
break;
case V_49 :
F_13 ( V_39 -> V_28 < sizeof( struct V_50 ) ) ;
F_7 ( V_4 ,
(struct V_11 * ) V_39 -> V_46 ) ;
break;
case V_51 :
V_43 =
(struct V_42 * ) V_39 -> V_46 ;
if ( ! V_4 -> V_7 )
break;
V_44 = F_14 ( V_43 -> V_30 . V_28 ,
( V_52 ) sizeof( V_4 -> V_53 ) ) ;
memcpy ( V_4 -> V_53 , V_43 -> V_54 , V_44 ) ;
F_15 ( V_4 -> V_55 , V_56 ,
V_4 -> V_53 , V_44 , 1 ) ;
break;
default:
F_16 ( L_1 ,
V_41 -> V_30 . type , V_41 -> V_30 . V_28 ) ;
break;
}
}
static void F_17 ( void * V_57 )
{
const int V_58 = 0x100 ;
int V_13 ;
struct V_2 * V_3 = V_57 ;
V_52 V_59 ;
T_2 V_60 ;
struct V_37 * V_15 ;
unsigned char * V_54 ;
int V_61 = V_58 ;
V_54 = F_18 ( V_61 , V_23 ) ;
if ( ! V_54 )
return;
do {
V_13 = F_19 ( V_3 -> V_33 , V_54 ,
V_61 , & V_59 , & V_60 ) ;
switch ( V_13 ) {
case 0 :
if ( V_59 <= 0 ) {
F_6 ( V_54 ) ;
return;
}
V_15 = (struct V_37 * ) V_54 ;
switch ( V_15 -> type ) {
case V_62 :
break;
case V_35 :
F_11 ( V_3 , V_15 ) ;
break;
default:
F_16 ( L_2 ,
V_15 -> type , V_60 , V_59 ) ;
break;
}
break;
case - V_63 :
F_6 ( V_54 ) ;
V_61 = V_59 ;
V_54 = F_18 ( V_59 , V_23 ) ;
if ( ! V_54 )
return;
break;
}
} while ( 1 );
}
static int F_20 ( struct V_2 * V_3 )
{
int V_13 = 0 ;
int V_64 ;
struct V_1 * V_4 = F_12 ( V_3 ) ;
struct V_16 * V_65 ;
struct V_16 * V_66 ;
V_65 = & V_4 -> V_67 ;
memset ( V_65 , 0 , sizeof( struct V_16 ) ) ;
V_65 -> type = V_27 ;
V_65 -> V_28 = sizeof( struct V_68 ) ;
V_65 -> V_65 . V_30 . type = V_69 ;
V_65 -> V_65 . V_30 . V_28 = sizeof( unsigned int ) ;
V_65 -> V_65 . V_70 . V_71 = V_72 ;
V_13 = F_9 ( V_3 -> V_33 , V_65 ,
sizeof( struct V_34 ) -
sizeof( unsigned char ) +
sizeof( struct V_68 ) ,
( unsigned long ) V_65 ,
V_35 ,
V_36 ) ;
if ( V_13 )
goto V_22;
V_64 = F_21 ( & V_4 -> V_6 , 5 * V_73 ) ;
if ( ! V_64 ) {
V_13 = - V_74 ;
goto V_22;
}
V_66 = & V_4 -> V_48 ;
if ( ! V_66 -> V_66 . V_75 ) {
F_16 ( L_3 ,
V_72 ) ;
V_13 = - V_76 ;
goto V_22;
}
V_64 = F_21 ( & V_4 -> V_6 , 5 * V_73 ) ;
if ( ! V_64 ) {
V_13 = - V_74 ;
goto V_22;
}
V_13 = V_4 -> V_18 ;
V_22:
return V_13 ;
}
static int F_22 ( struct V_55 * V_77 )
{
struct V_2 * V_78 = F_23 ( V_77 ) ;
struct V_1 * V_4 = F_12 ( V_78 ) ;
return F_24 ( V_77 , V_4 -> V_9 ,
V_4 -> V_24 ) ;
}
static int F_25 ( struct V_55 * V_77 )
{
return 0 ;
}
static int F_26 ( struct V_55 * V_77 )
{
return 0 ;
}
static void F_27 ( struct V_55 * V_77 )
{
}
static void F_28 ( struct V_55 * V_77 )
{
}
static int F_29 ( struct V_2 * V_3 ,
const struct V_79 * V_80 )
{
int V_13 ;
struct V_1 * V_4 ;
struct V_55 * V_81 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_19 ;
V_13 = F_30 ( V_3 -> V_33 ,
V_82 ,
V_83 ,
NULL ,
0 ,
F_17 ,
V_3
) ;
if ( V_13 )
goto V_84;
V_13 = F_20 ( V_3 ) ;
if ( V_13 )
goto V_85;
if ( V_4 -> V_9 [ 14 ] == 0x25 )
V_4 -> V_9 [ 14 ] = 0x29 ;
V_81 = F_31 () ;
if ( F_32 ( V_81 ) ) {
V_13 = F_33 ( V_81 ) ;
goto V_85;
}
V_81 -> V_86 = & V_87 ;
V_81 -> V_88 = & V_89 ;
V_81 -> V_90 = V_91 ;
V_81 -> V_92 = V_4 -> V_20 . V_92 ;
V_81 -> V_93 = V_4 -> V_20 . V_93 ;
V_81 -> V_71 = V_4 -> V_20 . V_71 ;
V_4 -> V_55 = V_81 ;
sprintf ( V_81 -> V_94 , L_4 , L_5 ) ;
F_34 ( V_81 , V_3 ) ;
V_13 = F_35 ( V_81 ) ;
if ( V_13 )
goto V_85;
V_13 = F_36 ( V_81 ) ;
if ( V_13 ) {
F_37 ( V_81 , L_6 ) ;
goto V_95;
}
V_13 = F_38 ( V_81 , V_96 | V_97 ) ;
if ( V_13 ) {
F_37 ( V_81 , L_7 ) ;
goto V_95;
}
V_4 -> V_98 = true ;
V_4 -> V_7 = true ;
return V_13 ;
V_95:
F_39 ( V_81 ) ;
V_85:
F_40 ( V_3 -> V_33 ) ;
V_84:
F_5 ( V_4 ) ;
return V_13 ;
}
static int F_41 ( struct V_2 * V_78 )
{
struct V_1 * V_4 = F_12 ( V_78 ) ;
F_40 ( V_78 -> V_33 ) ;
F_42 ( V_4 -> V_55 ) ;
F_39 ( V_4 -> V_55 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_99 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_99 ) ;
}
