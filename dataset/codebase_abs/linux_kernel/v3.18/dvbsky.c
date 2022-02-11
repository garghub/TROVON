static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 , T_1 * V_5 , T_2 V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_10 ) ;
if ( V_4 != 0 )
memcpy ( V_9 -> V_11 , V_3 , V_4 ) ;
V_7 = F_4 ( V_2 , V_9 -> V_11 , V_4 ,
V_9 -> V_12 , V_6 ) ;
if ( ! V_7 && ( V_6 != 0 ) )
memcpy ( V_5 , V_9 -> V_12 , V_6 ) ;
F_5 ( & V_2 -> V_10 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_7 ;
T_1 V_14 [ 3 ] = { 0x37 , 0 , 0 } ;
T_1 V_15 [ 3 ] = { 0x36 , 3 , 0 } ;
F_3 ( & V_9 -> V_16 ) ;
V_7 = F_1 ( V_2 , V_14 , 3 , NULL , 0 ) ;
if ( ! V_7 && V_13 ) {
F_7 ( 20 ) ;
V_7 = F_1 ( V_2 , V_15 , 3 , NULL , 0 ) ;
}
F_5 ( & V_9 -> V_16 ) ;
return V_7 ;
}
static int F_8 ( struct V_17 * V_18 , int V_13 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
return F_6 ( V_2 , ( V_13 == 0 ) ? 0 : 1 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 )
{
int V_7 ;
T_1 V_11 [ 3 ] , V_12 [ 2 ] ;
V_11 [ 0 ] = 0x0e ;
V_11 [ 1 ] = V_19 ;
V_11 [ 2 ] = V_20 ;
V_7 = F_1 ( V_2 , V_11 , 3 , V_12 , 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 ,
V_23 , V_24 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_25 * V_26 , struct V_27 V_28 [] ,
int V_29 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
int V_7 = 0 ;
T_1 V_12 [ 64 ] , V_11 [ 64 ] ;
if ( F_14 ( & V_2 -> V_30 ) < 0 )
return - V_31 ;
if ( V_29 > 2 ) {
F_11 ( & V_2 -> V_21 -> V_22 ,
L_2 , V_29 ) ;
V_7 = - V_32 ;
goto V_33;
}
if ( V_29 == 1 ) {
if ( V_28 [ 0 ] . V_34 > 60 ) {
F_11 ( & V_2 -> V_21 -> V_22 ,
L_3 ,
V_28 [ 0 ] . V_34 ) ;
V_7 = - V_32 ;
goto V_33;
}
if ( V_28 [ 0 ] . V_35 & V_36 ) {
V_11 [ 0 ] = 0x09 ;
V_11 [ 1 ] = 0 ;
V_11 [ 2 ] = V_28 [ 0 ] . V_34 ;
V_11 [ 3 ] = V_28 [ 0 ] . V_37 ;
V_7 = F_1 ( V_2 , V_11 , 4 ,
V_12 , V_28 [ 0 ] . V_34 + 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 ,
V_23 , V_24 , V_7 ) ;
if ( ! V_7 )
memcpy ( V_28 [ 0 ] . V_38 , & V_12 [ 1 ] , V_28 [ 0 ] . V_34 ) ;
} else {
V_11 [ 0 ] = 0x08 ;
V_11 [ 1 ] = V_28 [ 0 ] . V_37 ;
V_11 [ 2 ] = V_28 [ 0 ] . V_34 ;
memcpy ( & V_11 [ 3 ] , V_28 [ 0 ] . V_38 , V_28 [ 0 ] . V_34 ) ;
V_7 = F_1 ( V_2 , V_11 ,
V_28 [ 0 ] . V_34 + 3 , V_12 , 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 ,
V_23 , V_24 , V_7 ) ;
}
} else {
if ( ( V_28 [ 0 ] . V_34 > 60 ) || ( V_28 [ 1 ] . V_34 > 60 ) ) {
F_11 ( & V_2 -> V_21 -> V_22 ,
L_4 ,
V_28 [ 0 ] . V_34 , V_28 [ 1 ] . V_34 ) ;
V_7 = - V_32 ;
goto V_33;
}
V_11 [ 0 ] = 0x09 ;
V_11 [ 1 ] = V_28 [ 0 ] . V_34 ;
V_11 [ 2 ] = V_28 [ 1 ] . V_34 ;
V_11 [ 3 ] = V_28 [ 0 ] . V_37 ;
memcpy ( & V_11 [ 4 ] , V_28 [ 0 ] . V_38 , V_28 [ 0 ] . V_34 ) ;
V_7 = F_1 ( V_2 , V_11 ,
V_28 [ 0 ] . V_34 + 4 , V_12 , V_28 [ 1 ] . V_34 + 1 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 ,
V_23 , V_24 , V_7 ) ;
if ( ! V_7 )
memcpy ( V_28 [ 1 ] . V_38 , & V_12 [ 1 ] , V_28 [ 1 ] . V_34 ) ;
}
V_33:
F_5 ( & V_2 -> V_30 ) ;
return ( V_7 ) ? V_7 : V_29 ;
}
static T_3 F_15 ( struct V_25 * V_39 )
{
return V_40 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_41 = 0xffff , V_42 ;
T_1 V_43 , V_44 ;
T_1 V_11 [ 2 ] , V_12 [ 2 ] , V_45 ;
int V_7 ;
V_11 [ 0 ] = 0x10 ;
V_7 = F_1 ( V_2 , V_11 , 1 , V_12 , 2 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_21 -> V_22 , L_1 ,
V_23 , V_24 , V_7 ) ;
if ( V_7 == 0 )
V_41 = ( V_12 [ 0 ] << 8 ) | V_12 [ 1 ] ;
if ( V_41 != 0xffff ) {
F_17 ( & V_2 -> V_21 -> V_22 , L_5 , V_41 ) ;
V_43 = V_41 & 0x3F ;
V_44 = ( V_41 & 0x7C0 ) >> 6 ;
V_45 = ( V_41 & 0x800 ) ? 1 : 0 ;
V_42 = V_44 << 8 | V_43 ;
F_18 ( V_2 -> V_46 , V_47 , V_42 , V_45 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
V_49 -> V_50 = V_51 ;
V_49 -> V_52 = F_16 ;
V_49 -> V_53 = 300 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
T_4 V_54 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
if ( V_54 == V_55 )
V_20 = 0 ;
else
V_20 = 1 ;
F_10 ( V_2 , 0x80 , V_20 ) ;
return V_9 -> V_56 ( V_18 , V_54 ) ;
}
static int F_21 ( struct V_57 * V_26 , T_1 V_58 [ 6 ] )
{
struct V_1 * V_2 = F_22 ( V_26 ) ;
T_1 V_11 [] = { 0x1e , 0x00 } ;
T_1 V_12 [ 6 ] = { 0 } ;
struct V_27 V_28 [] = {
{
. V_37 = 0x51 ,
. V_35 = 0 ,
. V_38 = V_11 ,
. V_34 = 2 ,
} , {
. V_37 = 0x51 ,
. V_35 = V_36 ,
. V_38 = V_12 ,
. V_34 = 6 ,
}
} ;
if ( F_23 ( & V_2 -> V_59 , V_28 , 2 ) == 2 )
memcpy ( V_58 , V_12 , 6 ) ;
F_24 ( & V_2 -> V_21 -> V_22 , L_6 , V_58 ) ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 , T_5 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = V_9 -> V_61 ( V_18 , V_60 ) ;
if ( ( * V_60 & V_62 ) && ( ! V_9 -> V_63 ) )
F_6 ( V_2 , 1 ) ;
V_9 -> V_63 = ( * V_60 & V_62 ) ? 1 : 0 ;
return V_7 ;
}
static int F_26 ( struct V_57 * V_26 )
{
struct V_8 * V_9 = F_27 ( V_26 ) ;
struct V_1 * V_2 = F_22 ( V_26 ) ;
int V_7 = 0 ;
struct V_25 * V_25 ;
struct V_64 * V_65 ;
struct V_66 V_67 ;
struct V_68 V_68 = {
. clock = 27000000 ,
} ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_26 -> V_18 [ 0 ] = F_28 ( V_69 ,
& V_70 ,
& V_2 -> V_59 ,
& V_25 ) ;
if ( ! V_26 -> V_18 [ 0 ] ) {
F_11 ( & V_2 -> V_21 -> V_22 , L_7 ) ;
V_7 = - V_71 ;
goto V_72;
}
V_68 . V_18 = V_26 -> V_18 [ 0 ] ;
F_29 ( V_67 . type , L_8 , V_73 ) ;
V_67 . V_37 = 0x60 ;
V_67 . V_74 = & V_68 ;
F_30 ( L_8 ) ;
V_65 = F_31 ( V_25 , & V_67 ) ;
if ( V_65 == NULL || V_65 -> V_22 . V_75 == NULL ) {
F_32 ( V_26 -> V_18 [ 0 ] ) ;
V_7 = - V_71 ;
goto V_72;
}
if ( ! F_33 ( V_65 -> V_22 . V_75 -> V_76 ) ) {
F_34 ( V_65 ) ;
F_32 ( V_26 -> V_18 [ 0 ] ) ;
V_7 = - V_71 ;
goto V_72;
}
V_26 -> V_18 [ 0 ] -> V_77 . V_78 =
V_26 -> V_18 [ 0 ] -> V_77 . V_79 . V_80 ;
V_9 -> V_61 = V_26 -> V_18 [ 0 ] -> V_77 . V_81 ;
V_26 -> V_18 [ 0 ] -> V_77 . V_81 = F_25 ;
V_9 -> V_56 = V_26 -> V_18 [ 0 ] -> V_77 . V_82 ;
V_26 -> V_18 [ 0 ] -> V_77 . V_82 = F_20 ;
V_9 -> V_83 = V_65 ;
V_72:
return V_7 ;
}
static int F_35 ( struct V_1 * V_2 , const char * * V_84 )
{
F_10 ( V_2 , 0x04 , 1 ) ;
F_7 ( 20 ) ;
F_10 ( V_2 , 0x83 , 0 ) ;
F_10 ( V_2 , 0xc0 , 1 ) ;
F_7 ( 100 ) ;
F_10 ( V_2 , 0x83 , 1 ) ;
F_10 ( V_2 , 0xc0 , 0 ) ;
F_7 ( 50 ) ;
return V_85 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_37 ( & V_9 -> V_16 ) ;
V_9 -> V_63 = 0 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_64 * V_65 ;
V_65 = V_9 -> V_83 ;
if ( V_65 ) {
F_39 ( V_65 -> V_22 . V_75 -> V_76 ) ;
F_34 ( V_65 ) ;
}
}
