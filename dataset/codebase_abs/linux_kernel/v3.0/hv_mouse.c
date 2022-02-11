static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
F_3 ( & V_4 -> V_6 , 0 , 2 ) ;
V_4 -> V_3 = V_3 ;
V_3 -> V_7 = V_4 ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_3 )
{
F_5 ( F_6 ( & V_3 -> V_6 ) == 0 ) ;
F_7 ( V_3 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_7 ;
if ( V_4 && F_6 ( & V_4 -> V_6 ) > 1 )
F_9 ( & V_4 -> V_6 ) ;
else
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_7 ;
if ( V_4 && F_6 ( & V_4 -> V_6 ) )
F_9 ( & V_4 -> V_6 ) ;
else
V_4 = NULL ;
return V_4 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_7 ;
F_12 ( & V_4 -> V_6 ) ;
}
static struct V_1 * F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_7 ;
while ( F_3 ( & V_4 -> V_6 , 2 , 1 ) != 2 )
F_14 ( 100 ) ;
return V_4 ;
}
static struct V_1 * F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_3 -> V_7 ;
while ( F_3 ( & V_4 -> V_6 , 1 , 0 ) != 1 )
F_14 ( 100 ) ;
V_3 -> V_7 = NULL ;
return V_4 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_4 ;
void * V_10 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_17 ( L_1 ) ;
return;
}
V_10 = ( void * ) ( unsigned long ) V_9 -> V_11 ;
if ( V_10 == & V_4 -> V_12 ) {
}
F_11 ( V_3 ) ;
}
static void F_18 ( struct V_1 * V_13 ,
struct V_14 * V_15 )
{
int V_16 = 0 ;
struct V_17 * V_18 ;
struct V_19 V_20 ;
V_13 -> V_21 = 0 ;
memcpy ( & V_13 -> V_22 , & V_15 -> V_22 ,
sizeof( struct V_23 ) ) ;
V_18 = & V_15 -> V_17 ;
F_5 ( V_18 -> V_24 > 0 ) ;
V_13 -> V_25 = F_2 ( V_18 -> V_24 , V_5 ) ;
if ( ! V_13 -> V_25 ) {
F_17 ( L_2 , V_18 -> V_24 ) ;
goto V_26;
}
memcpy ( V_13 -> V_25 , V_18 , V_18 -> V_24 ) ;
V_13 -> V_27 = V_18 -> V_18 [ 0 ] . V_28 ;
V_13 -> V_29 = F_2 ( V_13 -> V_27 ,
V_5 ) ;
if ( ! V_13 -> V_29 ) {
F_17 ( L_3 ,
V_13 -> V_27 ) ;
goto V_26;
}
memcpy ( V_13 -> V_29 ,
( ( unsigned char * ) V_18 ) + V_18 -> V_24 ,
V_18 -> V_18 [ 0 ] . V_28 ) ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . type = V_30 ;
V_20 . V_31 = sizeof( struct V_32 ) ;
V_20 . V_20 . V_33 . type = V_34 ;
V_20 . V_20 . V_33 . V_31 = 1 ;
V_20 . V_20 . V_35 = 0 ;
V_16 = F_19 ( V_13 -> V_3 -> V_36 ,
& V_20 ,
sizeof( struct V_37 ) - sizeof( unsigned char ) +
sizeof( struct V_32 ) ,
( unsigned long ) & V_20 ,
V_38 ,
V_39 ) ;
if ( V_16 != 0 ) {
F_17 ( L_4 ,
V_16 ) ;
goto V_26;
}
V_13 -> V_40 = 1 ;
F_20 ( & V_13 -> V_41 ) ;
return;
V_26:
F_7 ( V_13 -> V_25 ) ;
V_13 -> V_25 = NULL ;
F_7 ( V_13 -> V_29 ) ;
V_13 -> V_29 = NULL ;
V_13 -> V_21 = - 1 ;
V_13 -> V_40 = 1 ;
F_20 ( & V_13 -> V_41 ) ;
}
static void F_21 ( struct V_1 * V_13 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 ;
if ( ! V_13 -> V_46 ) {
F_22 ( L_5 ) ;
return;
}
V_45 = F_23 ( V_13 -> V_3 -> V_3 . V_47 ) ;
F_24 ( V_13 -> V_3 ,
V_43 -> V_48 ,
V_43 -> V_33 . V_31 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_37 * V_49 ;
struct V_50 * V_51 ;
struct V_1 * V_4 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_17 ( L_1 ) ;
return;
}
V_49 = (struct V_37 * ) ( ( unsigned long ) V_9 +
( V_9 -> V_52 << 3 ) ) ;
if ( V_49 -> type != V_30 ) {
F_17 ( L_6 ,
V_49 -> type , V_49 -> V_31 ) ;
F_11 ( V_3 ) ;
return ;
}
V_51 = (struct V_50 * ) & V_49 -> V_53 [ 0 ] ;
switch ( V_51 -> V_33 . type ) {
case V_54 :
memcpy ( & V_4 -> V_55 , V_49 ,
V_49 -> V_31 + sizeof( struct V_37 ) -
sizeof( unsigned char ) ) ;
V_4 -> V_56 = 1 ;
F_20 ( & V_4 -> V_57 ) ;
break;
case V_58 :
F_5 ( V_49 -> V_31 >= sizeof( struct V_23 ) ) ;
F_18 ( V_4 ,
(struct V_14 * ) & V_49 -> V_53 [ 0 ] ) ;
break;
case V_59 :
F_21 ( V_4 ,
(struct V_42 * ) & V_49 -> V_53 [ 0 ] ) ;
break;
default:
F_17 ( L_7 ,
V_51 -> V_33 . type , V_51 -> V_33 . V_31 ) ;
break;
}
F_11 ( V_3 ) ;
}
static void F_26 ( void * V_60 )
{
const int V_61 = 0x100 ;
int V_16 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_60 ;
struct V_1 * V_4 ;
T_1 V_62 ;
T_2 V_63 ;
unsigned char V_9 [ 0x100 ] ;
struct V_8 * V_18 ;
unsigned char * V_48 = V_9 ;
int V_64 = V_61 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_17 ( L_1 ) ;
return;
}
do {
V_16 = F_27 ( V_3 -> V_36 , V_48 ,
V_64 , & V_62 , & V_63 ) ;
if ( V_16 == 0 ) {
if ( V_62 > 0 ) {
V_18 = (struct V_8 * ) V_48 ;
switch ( V_18 -> type ) {
case V_65 :
F_16 (
V_3 , V_18 ) ;
break;
case V_38 :
F_25 (
V_3 , V_18 ) ;
break;
default:
F_17 ( L_8 ,
V_18 -> type ,
V_63 ,
V_62 ) ;
break;
}
if ( V_64 > V_61 ) {
F_7 ( V_48 ) ;
V_48 = V_9 ;
V_64 = V_61 ;
}
} else {
if ( V_64 > V_61 ) {
F_7 ( V_48 ) ;
V_48 = V_9 ;
V_64 = V_61 ;
}
break;
}
} else if ( V_16 == - 2 ) {
V_64 = V_62 ;
V_48 = F_2 ( V_62 , V_5 ) ;
if ( V_48 == NULL ) {
V_48 = V_9 ;
V_64 = V_61 ;
F_17 ( L_9 ,
V_62 ) ;
break;
}
}
} while ( 1 );
F_11 ( V_3 ) ;
return;
}
static int F_28 ( struct V_2 * V_3 )
{
int V_16 = 0 ;
struct V_1 * V_4 ;
struct V_19 * V_10 ;
struct V_19 * V_66 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 ) {
F_17 ( L_1 ) ;
return - 1 ;
}
F_29 ( & V_4 -> V_57 ) ;
F_29 ( & V_4 -> V_41 ) ;
V_10 = & V_4 -> V_12 ;
memset ( V_10 , 0 , sizeof( struct V_19 ) ) ;
V_10 -> type = V_30 ;
V_10 -> V_31 = sizeof( struct V_67 ) ;
V_10 -> V_10 . V_33 . type = V_68 ;
V_10 -> V_10 . V_33 . V_31 = sizeof( unsigned long ) ;
V_10 -> V_10 . V_69 . V_70 = V_71 ;
F_22 ( L_10 ) ;
V_16 = F_19 ( V_3 -> V_36 , V_10 ,
sizeof( struct V_37 ) -
sizeof( unsigned char ) +
sizeof( struct V_67 ) ,
( unsigned long ) V_10 ,
V_38 ,
V_39 ) ;
if ( V_16 != 0 ) {
F_17 ( L_11 ) ;
goto V_26;
}
V_4 -> V_56 = 0 ;
F_30 ( V_4 -> V_57 ,
V_4 -> V_56 , F_31 ( 1000 ) ) ;
if ( V_4 -> V_56 == 0 ) {
V_16 = - V_72 ;
goto V_26;
}
V_66 = & V_4 -> V_55 ;
if ( ! V_66 -> V_66 . V_73 ) {
F_17 ( L_12 ,
V_71 ) ;
V_16 = - 1 ;
goto V_26;
}
V_4 -> V_40 = 0 ;
F_30 ( V_4 -> V_41 ,
V_4 -> V_40 , F_31 ( 1000 ) ) ;
if ( V_4 -> V_40 == 0 ) {
V_16 = - V_72 ;
goto V_26;
}
if ( ! V_4 -> V_21 )
F_22 ( L_13 ) ;
else
V_16 = - 1 ;
V_26:
F_11 ( V_3 ) ;
return V_16 ;
}
static int F_32 ( struct V_2 * V_3 ,
void * V_74 )
{
int V_16 = 0 ;
struct V_1 * V_4 ;
struct V_44 * V_45 ;
struct V_23 V_75 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_16 = - 1 ;
goto V_26;
}
V_4 -> V_46 = false ;
V_16 = F_33 ( V_3 -> V_36 ,
V_76 ,
V_77 ,
NULL ,
0 ,
F_26 ,
V_3
) ;
if ( V_16 != 0 ) {
F_17 ( L_14 , V_16 ) ;
F_4 ( V_4 ) ;
return - 1 ;
}
F_22 ( L_15 , V_16 ) ;
V_16 = F_28 ( V_3 ) ;
if ( V_16 != 0 ) {
F_17 ( L_16 , V_16 ) ;
F_34 ( V_3 -> V_36 ) ;
F_4 ( V_4 ) ;
return V_16 ;
}
V_45 = F_23 ( V_4 -> V_3 -> V_3 . V_47 ) ;
V_75 . V_78 = V_4 -> V_22 . V_78 ;
V_75 . V_79 = V_4 -> V_22 . V_79 ;
V_75 . V_70 = V_4 -> V_22 . V_70 ;
strcpy ( V_75 . V_80 , L_17 ) ;
F_35 ( V_3 , & V_75 ) ;
if ( V_4 -> V_29 [ 14 ] == 0x25 )
V_4 -> V_29 [ 14 ] = 0x29 ;
F_36 ( V_3 , V_4 -> V_29 ,
V_4 -> V_27 ) ;
V_4 -> V_46 = true ;
V_26:
return V_16 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_16 = 0 ;
F_22 ( L_18 ,
V_3 -> V_7 ) ;
V_4 = F_13 ( V_3 ) ;
while ( V_4 -> V_81 ) {
F_22 ( L_19 ,
V_4 -> V_81 ) ;
F_14 ( 100 ) ;
}
F_22 ( L_20 , V_3 -> V_7 ) ;
V_4 = F_15 ( V_3 ) ;
F_22 ( L_21 , V_4 ) ;
F_34 ( V_3 -> V_36 ) ;
F_4 ( V_4 ) ;
return V_16 ;
}
static void F_35 ( struct V_2 * V_82 , struct V_23 * V_83 )
{
struct V_84 * V_85 =
F_38 ( & V_82 -> V_3 ) ;
memcpy ( & V_85 -> V_15 , V_83 ,
sizeof( struct V_23 ) ) ;
F_39 ( V_86 , L_22 , V_87 ) ;
}
static void F_24 ( struct V_2 * V_82 , void * V_9 , T_1 V_88 )
{
int V_16 = 0 ;
struct V_84 * V_89 =
F_38 ( & V_82 -> V_3 ) ;
V_16 = F_40 ( V_89 -> V_90 ,
V_91 , V_9 , V_88 , 1 ) ;
F_41 ( V_86 , L_23 , V_16 ) ;
}
static int F_42 ( struct V_90 * V_92 )
{
return 0 ;
}
static void F_43 ( struct V_90 * V_92 )
{
}
static int F_44 ( struct V_2 * V_82 )
{
int V_16 = 0 ;
struct V_84 * V_89 ;
V_89 = F_45 ( sizeof( struct V_84 ) ,
V_5 ) ;
F_46 ( & V_82 -> V_3 , V_89 ) ;
V_16 = F_32 ( V_82 , NULL ) ;
if ( V_16 != 0 ) {
F_47 ( V_86 , L_24 ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_82 )
{
int V_16 = 0 ;
struct V_84 * V_89 ;
V_89 = F_45 ( sizeof( struct V_84 ) ,
V_5 ) ;
F_46 ( & V_82 -> V_3 , V_89 ) ;
if ( V_89 -> V_93 ) {
F_49 ( V_89 -> V_90 ) ;
V_89 -> V_93 = 0 ;
}
V_16 = F_37 ( V_82 ) ;
if ( V_16 != 0 ) {
F_47 ( V_86 ,
L_25 , V_16 ) ;
}
F_7 ( V_89 ) ;
return V_16 ;
}
static void F_36 ( struct V_2 * V_82 , void * V_9 , T_1 V_88 )
{
struct V_84 * V_85 =
F_38 ( & V_82 -> V_3 ) ;
struct V_90 * V_94 ;
V_94 = F_45 ( sizeof( struct V_90 ) , V_5 ) ;
if ( F_50 ( V_94 , V_9 , V_88 ) ) {
F_39 ( V_86 , L_26 ) ;
return;
}
if ( V_94 ) {
F_39 ( V_86 , L_27 ) ;
V_94 -> V_95 -> V_96 = F_42 ;
V_94 -> V_95 -> V_97 = F_43 ;
V_94 -> V_98 = V_99 ;
V_94 -> V_78 = V_85 -> V_15 . V_78 ;
V_94 -> V_79 = V_85 -> V_15 . V_79 ;
V_94 -> V_70 = V_85 -> V_15 . V_70 ;
V_94 -> V_82 = V_82 -> V_3 ;
sprintf ( V_94 -> V_80 , L_22 ,
V_85 -> V_15 . V_80 ) ;
if ( ! F_51 ( V_94 , 0 ) ) {
V_94 -> V_100 |= V_101 ;
V_85 -> V_93 = 1 ;
F_39 ( V_86 ,
L_28 ) ;
}
if ( ! V_94 -> V_100 ) {
F_47 ( V_86 ,
L_29
L_30 ) ;
}
V_85 -> V_90 = V_94 ;
}
F_7 ( V_94 ) ;
}
static void F_52 ( void )
{
F_53 ( & V_102 . V_47 ) ;
}
static int T_3 F_54 ( void )
{
struct V_44 * V_103 = & V_102 ;
F_39 ( V_86 , L_31 ) ;
memcpy ( & V_103 -> V_104 , & V_105 ,
sizeof( struct V_106 ) ) ;
V_103 -> V_47 . V_80 = V_107 ;
V_103 -> V_80 = V_107 ;
F_55 ( & V_103 -> V_47 ) ;
return 0 ;
}
static void T_4 F_56 ( void )
{
F_52 () ;
}
