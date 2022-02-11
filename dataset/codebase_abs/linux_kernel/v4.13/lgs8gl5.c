static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_6 ,
. V_13 = 2
} ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1 ,
V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_7 V_8 [ 2 ] = {
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_16 ,
. V_13 = 1
} ,
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = V_18 ,
. V_6 = V_17 ,
. V_13 = 1
}
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
return - V_19 ;
return V_17 [ 0 ] ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_4 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
T_1 V_20 [] = { V_3 , V_4 } ;
struct V_7 V_8 [ 3 ] = {
{
. V_9 = V_2 -> V_10 -> V_11 + 2 ,
. V_12 = 0 ,
. V_6 = V_16 ,
. V_13 = 1
} ,
{
. V_9 = V_2 -> V_10 -> V_11 + 2 ,
. V_12 = V_18 ,
. V_6 = V_17 ,
. V_13 = 1
} ,
{
. V_9 = V_2 -> V_10 -> V_11 + 2 ,
. V_12 = 0 ,
. V_6 = V_20 ,
. V_13 = 2
} ,
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 3 ) ;
return ( V_5 != 3 ) ? - 1 : 0 ;
}
static void
F_7 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_3 ( L_2 , V_15 ) ;
V_21 = F_4 ( V_2 , V_22 ) ;
F_1 ( V_2 , V_22 , V_21 & ~ V_23 ) ;
F_1 ( V_2 , V_22 , V_21 | V_23 ) ;
F_8 ( 5 ) ;
}
static void
F_9 ( struct V_1 * V_2 )
{
T_1 V_21 ;
int V_24 ;
F_3 ( L_2 , V_15 ) ;
F_6 ( V_2 , 0xc2 , 0x28 ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 , V_25 , 0x10 ) ;
F_5 ( V_2 , V_25 , 0x10 ) ;
F_1 ( V_2 , V_26 , 0x0e ) ;
F_1 ( V_2 , V_27 , 0xe5 ) ;
F_1 ( V_2 , V_28 , 0x35 ) ;
F_1 ( V_2 , V_29 , 0x30 ) ;
F_5 ( V_2 , V_30 , 0x00 ) ;
F_5 ( V_2 , V_31 , 0x01 ) ;
F_6 ( V_2 , 0xc5 , 0x00 ) ;
F_5 ( V_2 , V_32 , 0x02 ) ;
F_5 ( V_2 , V_33 , 0x01 ) ;
F_7 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < 10 ; V_24 ++ ) {
V_21 = F_4 ( V_2 , V_34 ) ;
F_3 ( L_3 , V_24 , V_21 ) ;
if ( V_21 & V_35 )
break;
F_8 ( 4 ) ;
}
if ( ! ( V_21 & V_35 ) )
return;
for ( V_24 = 0 ; V_24 < 20 ; V_24 ++ ) {
V_21 = F_4 ( V_2 , V_36 ) ;
F_3 ( L_4 , V_24 , V_21 ) ;
if ( V_21 & V_37 )
break;
F_8 ( 12 ) ;
}
if ( ! ( V_21 & V_37 ) )
return;
F_1 ( V_2 , V_38 , F_4 ( V_2 , V_39 ) ) ;
F_7 ( V_2 ) ;
}
static int
F_10 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
F_3 ( L_2 , V_15 ) ;
F_6 ( V_2 , 0xc2 , 0x28 ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 , V_25 , 0x10 ) ;
F_5 ( V_2 , V_25 , 0x10 ) ;
F_1 ( V_2 , V_26 , 0x0e ) ;
F_1 ( V_2 , V_27 , 0xe5 ) ;
F_1 ( V_2 , V_28 , 0x35 ) ;
F_1 ( V_2 , V_29 , 0x30 ) ;
return 0 ;
}
static int
F_11 ( struct V_40 * V_41 , enum V_43 * V_44 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_45 = F_4 ( V_2 , V_34 ) ;
T_1 V_12 = F_4 ( V_2 , V_36 ) ;
* V_44 = 0 ;
if ( ( V_45 & V_46 ) > 0 )
* V_44 |= V_47 ;
if ( V_45 & V_35 )
* V_44 |= V_48 ;
if ( V_12 & V_49 )
* V_44 |= V_50 ;
if ( V_12 & V_37 )
* V_44 |= V_51 ;
return 0 ;
}
static int
F_12 ( struct V_40 * V_41 , T_2 * V_52 )
{
* V_52 = 0 ;
return 0 ;
}
static int
F_13 ( struct V_40 * V_41 , T_3 * V_53 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_45 = F_4 ( V_2 , V_34 ) ;
* V_53 = ( V_45 & V_46 ) << 8 ;
return 0 ;
}
static int
F_14 ( struct V_40 * V_41 , T_3 * V_54 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_45 = F_4 ( V_2 , V_34 ) ;
* V_54 = ( V_45 & V_46 ) << 8 ;
return 0 ;
}
static int
F_15 ( struct V_40 * V_41 , T_2 * V_55 )
{
* V_55 = 0 ;
return 0 ;
}
static int
F_16 ( struct V_40 * V_41 )
{
struct V_56 * V_57 = & V_41 -> V_58 ;
struct V_1 * V_2 = V_41 -> V_42 ;
F_3 ( L_2 , V_15 ) ;
if ( V_57 -> V_59 != 8000000 )
return - V_60 ;
if ( V_41 -> V_61 . V_62 . V_63 ) {
V_41 -> V_61 . V_62 . V_63 ( V_41 ) ;
if ( V_41 -> V_61 . V_64 )
V_41 -> V_61 . V_64 ( V_41 , 0 ) ;
}
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_17 ( struct V_40 * V_41 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_65 = F_4 ( V_2 , V_66 ) ;
V_57 -> V_67 = ( V_65 & V_68 ) ? V_69 : V_70 ;
V_57 -> V_71 = V_72 ;
V_57 -> V_73 = V_74 ;
V_57 -> V_75 = V_76 ;
V_57 -> V_77 = V_78 ;
V_57 -> V_79 = V_80 ;
V_57 -> V_81 = V_82 ;
V_57 -> V_59 = 8000000 ;
return 0 ;
}
static int
F_18 ( struct V_40 * V_41 ,
struct V_83 * V_84 )
{
V_84 -> V_85 = 240 ;
V_84 -> V_86 = 0 ;
V_84 -> V_87 = 0 ;
return 0 ;
}
static void
F_19 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
F_20 ( V_2 ) ;
}
struct V_40 *
F_21 ( const struct V_88 * V_10 , struct V_89 * V_14 )
{
struct V_1 * V_2 = NULL ;
F_3 ( L_2 , V_15 ) ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_90 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
if ( F_4 ( V_2 , V_22 ) < 0 )
goto error;
memcpy ( & V_2 -> V_91 . V_61 , & V_92 ,
sizeof( struct V_93 ) ) ;
V_2 -> V_91 . V_42 = V_2 ;
return & V_2 -> V_91 ;
error:
F_20 ( V_2 ) ;
return NULL ;
}
