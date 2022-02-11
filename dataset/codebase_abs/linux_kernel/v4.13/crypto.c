static void F_1 ( const void * V_1 , T_1 V_2 )
{
F_2 ( V_3 , L_1 , V_4 , 16 , 1 ,
V_1 , V_2 , 0 ) ;
}
static void F_3 ( void * V_5 , const void * V_6 , const void * V_7 ,
T_1 V_8 )
{
T_2 * V_9 = V_5 ;
const T_2 * V_10 = V_6 , * V_11 = V_7 ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ )
V_9 [ V_12 ] = V_10 [ V_12 ] ^ V_11 [ V_12 ] ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
void * V_19 ,
const struct V_20 * V_21 ,
const struct V_22 * V_23 , const void * V_24 ,
T_1 V_25 )
{
int V_26 = 0 ;
F_5 ( V_27 , V_14 ) ;
struct V_28 V_29 [ 4 ] , V_30 ;
void * V_31 ;
T_1 V_32 ;
T_2 V_33 [ F_6 ( V_14 ) ] ;
T_1 V_34 ;
F_7 ( sizeof( * V_23 ) != sizeof( V_18 -> V_35 ) - sizeof( V_18 -> V_35 . V_36 ) ) ;
F_7 ( sizeof( V_18 -> V_37 ) != sizeof( struct V_38 ) ) ;
F_7 ( sizeof( V_18 -> V_35 ) != sizeof( struct V_38 ) ) ;
F_7 ( sizeof( V_18 -> V_39 ) != sizeof( struct V_38 ) ) ;
V_26 = - V_40 ;
V_34 = V_25 % sizeof( struct V_38 ) ;
if ( V_34 )
V_34 = sizeof( struct V_38 ) - V_34 ;
V_32 = V_25 + sizeof( V_18 -> V_37 ) + sizeof( V_18 -> V_35 ) +
V_34 ;
V_31 = F_8 ( V_32 , V_41 ) ;
if ( ! V_31 )
goto V_42;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
V_18 -> V_37 . V_43 = 0x59 ;
V_18 -> V_37 . V_44 = * V_21 ;
V_18 -> V_37 . V_45 = F_9 ( 0 ) ;
V_18 -> V_35 . V_36 = F_9 ( V_25 + 14 ) ;
memcpy ( & V_18 -> V_35 . V_46 , V_23 , sizeof( * V_23 ) ) ;
F_10 ( V_29 , F_11 ( V_29 ) ) ;
F_12 ( & V_29 [ 0 ] , & V_18 -> V_37 , sizeof( V_18 -> V_37 ) ) ;
F_12 ( & V_29 [ 1 ] , & V_18 -> V_35 , sizeof( V_18 -> V_35 ) ) ;
F_12 ( & V_29 [ 2 ] , V_24 , V_25 ) ;
F_13 ( & V_29 [ 3 ] , F_14 ( 0 ) , V_34 , 0 ) ;
F_15 ( & V_30 , V_31 , V_32 ) ;
F_16 ( V_27 , V_14 ) ;
F_17 ( V_27 , 0 , NULL , NULL ) ;
F_18 ( V_27 , V_29 , & V_30 , V_32 , V_33 ) ;
V_26 = F_19 ( V_27 ) ;
F_20 ( V_27 ) ;
if ( V_26 < 0 ) {
F_21 ( V_3 L_2 ,
V_26 ) ;
goto V_47;
}
V_18 -> V_39 . V_43 = 0x01 ;
V_18 -> V_39 . V_44 = * V_21 ;
V_18 -> V_39 . V_48 = 0 ;
F_22 ( V_16 , ( void * ) & V_18 -> V_39 ,
( void * ) & V_18 -> V_39 ) ;
F_3 ( V_19 , & V_18 -> V_39 , V_33 , 8 ) ;
V_26 = 8 ;
V_47:
F_23 ( V_31 ) ;
V_42:
return V_26 ;
}
T_3 F_24 ( void * V_49 , T_1 V_50 ,
const T_2 V_51 [ 16 ] , const struct V_20 * V_52 ,
const struct V_22 * V_23 ,
const void * V_24 , T_1 V_25 , T_1 V_2 )
{
T_3 V_26 , V_53 = 0 , V_54 ;
struct V_20 V_21 = * V_52 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
T_4 V_55 = 0 ;
T_5 V_56 ;
V_14 = F_25 ( L_3 , 0 , V_57 ) ;
if ( F_26 ( V_14 ) ) {
V_26 = F_27 ( V_14 ) ;
F_21 ( V_3 L_4 , ( int ) V_26 ) ;
goto V_58;
}
V_26 = F_28 ( V_14 , V_51 , 16 ) ;
if ( V_26 < 0 ) {
F_21 ( V_3 L_5 , ( int ) V_26 ) ;
goto V_59;
}
V_16 = F_29 ( L_6 , 0 , V_57 ) ;
if ( F_26 ( V_16 ) ) {
V_26 = F_27 ( V_16 ) ;
F_21 ( V_3 L_7 , ( int ) V_26 ) ;
goto V_60;
}
V_26 = F_30 ( V_16 , V_51 , 16 ) ;
if ( V_26 < 0 ) {
F_21 ( V_3 L_8 , ( int ) V_26 ) ;
goto V_61;
}
V_18 = F_31 ( sizeof( * V_18 ) , V_41 ) ;
if ( ! V_18 ) {
V_26 = - V_40 ;
goto V_62;
}
for ( V_54 = 0 ; V_54 < ( V_2 + 63 ) / 64 ; V_54 ++ ) {
V_56 = F_32 ( V_55 ++ ) ;
memcpy ( & V_21 . V_55 , & V_56 , sizeof( V_21 . V_55 ) ) ;
V_26 = F_4 ( V_14 , V_16 , V_18 , V_49 + V_53 ,
& V_21 , V_23 , V_24 , V_25 ) ;
if ( V_26 < 0 )
goto V_63;
V_53 += V_26 ;
}
V_26 = V_53 ;
F_23 ( V_18 ) ;
V_62:
V_63:
V_61:
F_33 ( V_16 ) ;
V_60:
V_59:
F_34 ( V_14 ) ;
V_58:
return V_26 ;
}
static int F_35 ( void )
{
int V_26 ;
T_2 V_19 [ 8 ] ;
struct V_64 V_65 = {
. V_66 = 2 ,
. V_67 = 00 ,
. V_68 = { 0x76 , 0x98 , 0x01 } ,
. V_69 = 00 ,
. V_70 = { 0x30 , 0x31 , 0x32 , 0x33 , 0x34 , 0x35 ,
0x36 , 0x37 , 0x38 , 0x39 , 0x3a , 0x3b ,
0x3c , 0x3d , 0x3e , 0x3f } ,
. V_71 = { 0x20 , 0x21 , 0x22 , 0x23 , 0x24 , 0x25 ,
0x26 , 0x27 , 0x28 , 0x29 , 0x2a , 0x2b ,
0x2c , 0x2d , 0x2e , 0x2f } ,
. V_72 = { 0x75 , 0x6a , 0x97 , 0x51 , 0x0c , 0x8c ,
0x14 , 0x7b } ,
} ;
T_1 V_73 ;
V_26 = F_36 ( V_19 , V_74 , & V_75 , & V_65 ) ;
if ( V_26 < 0 )
F_21 ( V_3 L_9 , V_26 ) ;
else if ( memcmp ( V_65 . V_72 , V_19 , sizeof( V_19 ) ) ) {
F_21 ( V_3 L_10
L_11 ) ;
V_73 = sizeof( V_65 ) - sizeof( V_65 . V_72 ) ;
F_21 ( V_3 L_12 , V_73 ) ;
F_1 ( & V_65 , V_73 ) ;
F_21 ( V_3 L_13 ,
sizeof( V_75 ) ) ;
F_1 ( & V_75 , sizeof( V_75 ) ) ;
F_21 ( V_3 L_14 ) ;
F_1 ( V_19 , sizeof( V_19 ) ) ;
F_21 ( V_3 L_15 ) ;
F_1 ( V_65 . V_72 , sizeof( V_65 . V_72 ) ) ;
V_26 = - V_76 ;
} else
V_26 = 0 ;
return V_26 ;
}
static int F_37 ( void )
{
int V_26 = 0 ;
struct V_77 V_78 ;
struct V_79 V_80 = {
. V_81 = {
0x10 , 0x11 , 0x12 , 0x13 , 0x14 , 0x15 , 0x16 , 0x17 ,
0x18 , 0x19 , 0x1a , 0x1b , 0x1c , 0x1d , 0x1e , 0x1f
} ,
. V_82 = {
0x20 , 0x21 , 0x22 , 0x23 , 0x24 , 0x25 , 0x26 , 0x27 ,
0x28 , 0x29 , 0x2a , 0x2b , 0x2c , 0x2d , 0x2e , 0x2f
}
} ;
V_26 = F_38 ( & V_78 , V_83 , & V_84 ,
& V_80 ) ;
if ( V_26 < 0 )
F_21 ( V_3 L_16
L_17 , V_26 ) ;
if ( memcmp ( & V_85 , & V_78 , sizeof( V_78 ) ) ) {
F_21 ( V_3 L_16
L_18
L_19 ) ;
F_21 ( V_3 L_20 ) ;
F_1 ( V_83 , sizeof( V_83 ) ) ;
F_21 ( V_3 L_21 ) ;
F_1 ( & V_84 , sizeof( V_84 ) ) ;
F_21 ( V_3 L_22 ) ;
F_1 ( & V_80 , sizeof( V_80 ) ) ;
F_21 ( V_3 L_23 ) ;
F_1 ( & V_78 . V_86 , sizeof( V_78 . V_86 ) ) ;
F_21 ( V_3 L_24 ) ;
F_1 ( & V_78 . V_87 , sizeof( V_78 . V_87 ) ) ;
V_26 = - V_76 ;
} else
V_26 = 0 ;
return V_26 ;
}
int F_39 ( void )
{
int V_26 ;
if ( V_88 ) {
V_26 = F_37 () ;
if ( V_26 < 0 )
return V_26 ;
return F_35 () ;
}
return 0 ;
}
void F_40 ( void )
{
}
