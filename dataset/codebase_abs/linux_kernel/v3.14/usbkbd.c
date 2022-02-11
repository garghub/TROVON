static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 ;
switch ( V_1 -> V_6 ) {
case 0 :
break;
case - V_7 :
case - V_8 :
case - V_9 :
return;
default:
goto V_10;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
F_2 ( V_3 -> V_11 , V_12 [ V_5 + 224 ] , ( V_3 -> V_13 [ 0 ] >> V_5 ) & 1 ) ;
for ( V_5 = 2 ; V_5 < 8 ; V_5 ++ ) {
if ( V_3 -> V_14 [ V_5 ] > 3 && F_3 ( V_3 -> V_13 + 2 , V_3 -> V_14 [ V_5 ] , 6 ) == V_3 -> V_13 + 8 ) {
if ( V_12 [ V_3 -> V_14 [ V_5 ] ] )
F_2 ( V_3 -> V_11 , V_12 [ V_3 -> V_14 [ V_5 ] ] , 0 ) ;
else
F_4 ( V_1 -> V_11 ,
L_1 ,
V_3 -> V_14 [ V_5 ] ) ;
}
if ( V_3 -> V_13 [ V_5 ] > 3 && F_3 ( V_3 -> V_14 + 2 , V_3 -> V_13 [ V_5 ] , 6 ) == V_3 -> V_14 + 8 ) {
if ( V_12 [ V_3 -> V_13 [ V_5 ] ] )
F_2 ( V_3 -> V_11 , V_12 [ V_3 -> V_13 [ V_5 ] ] , 1 ) ;
else
F_4 ( V_1 -> V_11 ,
L_2 ,
V_3 -> V_13 [ V_5 ] ) ;
}
}
F_5 ( V_3 -> V_11 ) ;
memcpy ( V_3 -> V_14 , V_3 -> V_13 , 8 ) ;
V_10:
V_5 = F_6 ( V_1 , V_15 ) ;
if ( V_5 )
F_7 ( V_1 -> V_11 , L_3 ,
V_3 -> V_16 -> V_17 -> V_18 ,
V_3 -> V_16 -> V_19 , V_5 ) ;
}
static int F_8 ( struct V_20 * V_11 , unsigned int type ,
unsigned int V_21 , int V_22 )
{
unsigned long V_23 ;
struct V_2 * V_3 = F_9 ( V_11 ) ;
if ( type != V_24 )
return - 1 ;
F_10 ( & V_3 -> V_25 , V_23 ) ;
V_3 -> V_26 = ( ! ! F_11 ( V_27 , V_11 -> V_28 ) << 3 ) | ( ! ! F_11 ( V_29 , V_11 -> V_28 ) << 3 ) |
( ! ! F_11 ( V_30 , V_11 -> V_28 ) << 2 ) | ( ! ! F_11 ( V_31 , V_11 -> V_28 ) << 1 ) |
( ! ! F_11 ( V_32 , V_11 -> V_28 ) ) ;
if ( V_3 -> V_33 ) {
F_12 ( & V_3 -> V_25 , V_23 ) ;
return 0 ;
}
if ( * ( V_3 -> V_34 ) == V_3 -> V_26 ) {
F_12 ( & V_3 -> V_25 , V_23 ) ;
return 0 ;
}
* ( V_3 -> V_34 ) = V_3 -> V_26 ;
V_3 -> V_28 -> V_11 = V_3 -> V_16 ;
if ( F_6 ( V_3 -> V_28 , V_15 ) )
F_13 ( L_4 ) ;
else
V_3 -> V_33 = true ;
F_12 ( & V_3 -> V_25 , V_23 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
unsigned long V_23 ;
struct V_2 * V_3 = V_1 -> V_4 ;
if ( V_1 -> V_6 )
F_15 ( V_1 -> V_11 , L_5 ,
V_1 -> V_6 ) ;
F_10 ( & V_3 -> V_25 , V_23 ) ;
if ( * ( V_3 -> V_34 ) == V_3 -> V_26 ) {
V_3 -> V_33 = false ;
F_12 ( & V_3 -> V_25 , V_23 ) ;
return;
}
* ( V_3 -> V_34 ) = V_3 -> V_26 ;
V_3 -> V_28 -> V_11 = V_3 -> V_16 ;
if ( F_6 ( V_3 -> V_28 , V_15 ) ) {
F_7 ( V_1 -> V_11 , L_4 ) ;
V_3 -> V_33 = false ;
}
F_12 ( & V_3 -> V_25 , V_23 ) ;
}
static int F_16 ( struct V_20 * V_11 )
{
struct V_2 * V_3 = F_9 ( V_11 ) ;
V_3 -> V_35 -> V_11 = V_3 -> V_16 ;
if ( F_6 ( V_3 -> V_35 , V_36 ) )
return - V_37 ;
return 0 ;
}
static void F_17 ( struct V_20 * V_11 )
{
struct V_2 * V_3 = F_9 ( V_11 ) ;
F_18 ( V_3 -> V_35 ) ;
}
static int F_19 ( struct V_38 * V_11 , struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_35 = F_20 ( 0 , V_36 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_28 = F_20 ( 0 , V_36 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_13 = F_21 ( V_11 , 8 , V_15 , & V_3 -> V_39 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_40 = F_22 ( sizeof( struct V_41 ) , V_36 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_34 = F_21 ( V_11 , 1 , V_15 , & V_3 -> V_42 ) ) )
return - 1 ;
return 0 ;
}
static void F_23 ( struct V_38 * V_11 , struct V_2 * V_3 )
{
F_24 ( V_3 -> V_35 ) ;
F_24 ( V_3 -> V_28 ) ;
F_25 ( V_11 , 8 , V_3 -> V_13 , V_3 -> V_39 ) ;
F_26 ( V_3 -> V_40 ) ;
F_25 ( V_11 , 1 , V_3 -> V_34 , V_3 -> V_42 ) ;
}
static int F_27 ( struct V_43 * V_44 ,
const struct V_45 * V_46 )
{
struct V_38 * V_11 = F_28 ( V_44 ) ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_2 * V_3 ;
struct V_20 * V_20 ;
int V_5 , V_51 , V_52 ;
int error = - V_53 ;
V_48 = V_44 -> V_54 ;
if ( V_48 -> V_55 . V_56 != 1 )
return - V_57 ;
V_50 = & V_48 -> V_50 [ 0 ] . V_55 ;
if ( ! F_29 ( V_50 ) )
return - V_57 ;
V_51 = F_30 ( V_11 , V_50 -> V_58 ) ;
V_52 = F_31 ( V_11 , V_51 , F_32 ( V_51 ) ) ;
V_3 = F_33 ( sizeof( struct V_2 ) , V_36 ) ;
V_20 = F_34 () ;
if ( ! V_3 || ! V_20 )
goto V_59;
if ( F_19 ( V_11 , V_3 ) )
goto V_60;
V_3 -> V_16 = V_11 ;
V_3 -> V_11 = V_20 ;
F_35 ( & V_3 -> V_25 ) ;
if ( V_11 -> V_61 )
F_36 ( V_3 -> V_62 , V_11 -> V_61 , sizeof( V_3 -> V_62 ) ) ;
if ( V_11 -> V_63 ) {
if ( V_11 -> V_61 )
F_37 ( V_3 -> V_62 , L_6 , sizeof( V_3 -> V_62 ) ) ;
F_37 ( V_3 -> V_62 , V_11 -> V_63 , sizeof( V_3 -> V_62 ) ) ;
}
if ( ! strlen ( V_3 -> V_62 ) )
snprintf ( V_3 -> V_62 , sizeof( V_3 -> V_62 ) ,
L_7 ,
F_38 ( V_11 -> V_64 . V_65 ) ,
F_38 ( V_11 -> V_64 . V_66 ) ) ;
F_39 ( V_11 , V_3 -> V_67 , sizeof( V_3 -> V_67 ) ) ;
F_37 ( V_3 -> V_67 , L_8 , sizeof( V_3 -> V_67 ) ) ;
V_20 -> V_62 = V_3 -> V_62 ;
V_20 -> V_67 = V_3 -> V_67 ;
F_40 ( V_11 , & V_20 -> V_46 ) ;
V_20 -> V_11 . V_68 = & V_44 -> V_11 ;
F_41 ( V_20 , V_3 ) ;
V_20 -> V_69 [ 0 ] = F_42 ( V_70 ) | F_42 ( V_24 ) |
F_42 ( V_71 ) ;
V_20 -> V_72 [ 0 ] = F_42 ( V_32 ) | F_42 ( V_31 ) |
F_42 ( V_30 ) | F_42 ( V_29 ) |
F_42 ( V_27 ) ;
for ( V_5 = 0 ; V_5 < 255 ; V_5 ++ )
F_43 ( V_12 [ V_5 ] , V_20 -> V_73 ) ;
F_44 ( 0 , V_20 -> V_73 ) ;
V_20 -> V_74 = F_8 ;
V_20 -> V_75 = F_16 ;
V_20 -> V_76 = F_17 ;
F_45 ( V_3 -> V_35 , V_11 , V_51 ,
V_3 -> V_13 , ( V_52 > 8 ? 8 : V_52 ) ,
F_1 , V_3 , V_50 -> V_77 ) ;
V_3 -> V_35 -> V_78 = V_3 -> V_39 ;
V_3 -> V_35 -> V_79 |= V_80 ;
V_3 -> V_40 -> V_81 = V_82 | V_83 ;
V_3 -> V_40 -> V_84 = 0x09 ;
V_3 -> V_40 -> V_85 = F_46 ( 0x200 ) ;
V_3 -> V_40 -> V_86 = F_46 ( V_48 -> V_55 . V_87 ) ;
V_3 -> V_40 -> V_88 = F_46 ( 1 ) ;
F_47 ( V_3 -> V_28 , V_11 , F_48 ( V_11 , 0 ) ,
( void * ) V_3 -> V_40 , V_3 -> V_34 , 1 ,
F_14 , V_3 ) ;
V_3 -> V_28 -> V_78 = V_3 -> V_42 ;
V_3 -> V_28 -> V_79 |= V_80 ;
error = F_49 ( V_3 -> V_11 ) ;
if ( error )
goto V_60;
F_50 ( V_44 , V_3 ) ;
F_51 ( & V_11 -> V_11 , 1 ) ;
return 0 ;
V_60:
F_23 ( V_11 , V_3 ) ;
V_59:
F_52 ( V_20 ) ;
F_26 ( V_3 ) ;
return error ;
}
static void F_53 ( struct V_43 * V_89 )
{
struct V_2 * V_3 = F_54 ( V_89 ) ;
F_50 ( V_89 , NULL ) ;
if ( V_3 ) {
F_18 ( V_3 -> V_35 ) ;
F_55 ( V_3 -> V_11 ) ;
F_18 ( V_3 -> V_28 ) ;
F_23 ( F_28 ( V_89 ) , V_3 ) ;
F_26 ( V_3 ) ;
}
}
