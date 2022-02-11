static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_8 * V_9 = V_5 -> V_7 ;
return V_9 -> V_10 . V_11 ( V_2 , V_3 , V_9 -> V_12 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_13 V_14 ;
struct V_8 * V_9 = V_5 -> V_7 ;
V_14 . V_15 = 0x8 ;
V_5 -> V_16 [ 0 ] . V_2 = F_3 ( V_17 , & V_14 ,
& V_5 -> V_18 -> V_19 , & V_9 -> V_10 ) ;
if ( ( V_5 -> V_16 [ 0 ] . V_2 ) == NULL )
return - V_20 ;
V_5 -> V_16 [ 0 ] . V_2 -> V_10 . V_21 = F_1 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_7 ;
V_9 -> V_12 = 0x61 ;
F_3 ( V_22 , V_5 -> V_16 [ 0 ] . V_2 , 0x61 , & V_5 -> V_18 -> V_19 ,
V_23 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_7 ;
V_9 -> V_12 = 0x60 ;
F_3 ( V_22 , V_5 -> V_16 [ 0 ] . V_2 , 0x60 , & V_5 -> V_18 -> V_19 ,
V_24 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
T_1 V_25 [ 2 ] = { 0 , 0 } , V_26 [ 1 ] ;
int V_27 = 0 ;
struct V_28 V_29 [ 2 ] = {
{ . V_30 = 0 , . V_31 = V_25 , . V_32 = 2 } ,
{ . V_30 = V_33 , . V_31 = V_26 , . V_32 = 1 } ,
} ;
struct V_8 * V_9 = V_5 -> V_7 ;
V_29 [ 0 ] . V_34 = V_29 [ 1 ] . V_34 = V_9 -> V_12 = 0x60 ;
if ( V_5 -> V_16 [ 0 ] . V_2 -> V_10 . V_21 )
V_5 -> V_16 [ 0 ] . V_2 -> V_10 . V_21 ( V_5 -> V_16 [ 0 ] . V_2 , 1 ) ;
if ( F_7 ( & V_5 -> V_18 -> V_19 , V_29 , 2 ) != 2 ) {
F_8 ( L_1 ) ;
V_27 = - V_35 ;
}
if ( V_5 -> V_16 [ 0 ] . V_2 -> V_10 . V_21 )
V_5 -> V_16 [ 0 ] . V_2 -> V_10 . V_21 ( V_5 -> V_16 [ 0 ] . V_2 , 0 ) ;
if ( V_26 [ 0 ] == 0xfe ) {
F_9 ( L_2 ) ;
V_27 = F_4 ( V_5 ) ;
} else {
F_9 ( L_3 ) ;
V_27 = F_5 ( V_5 ) ;
}
return V_27 ;
}
static int F_10 ( struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
if ( 0 == F_11 ( V_37 , & V_40 ,
V_41 , NULL , V_42 ) ||
0 == F_11 ( V_37 , & V_43 ,
V_41 , NULL , V_42 ) ||
0 == F_11 ( V_37 , & V_44 ,
V_41 , NULL , V_42 ) ||
0 == F_11 ( V_37 , & V_45 ,
V_41 , NULL , V_42 ) )
return 0 ;
return - V_46 ;
}
static int T_2 F_12 ( void )
{
int V_47 ;
if ( ( V_47 = F_13 ( & V_48 ) ) ) {
F_8 ( L_4 , V_47 ) ;
return V_47 ;
}
return 0 ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_48 ) ;
}
