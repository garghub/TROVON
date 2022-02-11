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
if ( ( V_5 -> V_2 = F_3 ( V_16 , & V_14 ,
& V_5 -> V_17 -> V_18 , & V_9 -> V_10 ) ) == NULL )
return - V_19 ;
V_5 -> V_2 -> V_10 . V_20 = F_1 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_7 ;
V_9 -> V_12 = 0x61 ;
F_3 ( V_21 , V_5 -> V_2 , 0x61 , & V_5 -> V_17 -> V_18 ,
V_22 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_7 ;
V_9 -> V_12 = 0x60 ;
F_3 ( V_21 , V_5 -> V_2 , 0x60 , & V_5 -> V_17 -> V_18 ,
V_23 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
T_1 V_24 [ 2 ] = { 0 , 0 } , V_25 [ 1 ] ;
int V_26 = 0 ;
struct V_27 V_28 [ 2 ] = {
{ . V_29 = 0 , . V_30 = V_24 , . V_31 = 2 } ,
{ . V_29 = V_32 , . V_30 = V_25 , . V_31 = 1 } ,
} ;
struct V_8 * V_9 = V_5 -> V_7 ;
V_28 [ 0 ] . V_33 = V_28 [ 1 ] . V_33 = V_9 -> V_12 = 0x60 ;
if ( V_5 -> V_2 -> V_10 . V_20 )
V_5 -> V_2 -> V_10 . V_20 ( V_5 -> V_2 , 1 ) ;
if ( F_7 ( & V_5 -> V_17 -> V_18 , V_28 , 2 ) != 2 ) {
F_8 ( L_1 ) ;
V_26 = - V_34 ;
}
if ( V_5 -> V_2 -> V_10 . V_20 )
V_5 -> V_2 -> V_10 . V_20 ( V_5 -> V_2 , 0 ) ;
if ( V_25 [ 0 ] == 0xfe ) {
F_9 ( L_2 ) ;
V_26 = F_4 ( V_5 ) ;
} else {
F_9 ( L_3 ) ;
V_26 = F_5 ( V_5 ) ;
}
return V_26 ;
}
static int F_10 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
if ( 0 == F_11 ( V_36 , & V_39 ,
V_40 , NULL , V_41 ) ||
0 == F_11 ( V_36 , & V_42 ,
V_40 , NULL , V_41 ) ||
0 == F_11 ( V_36 , & V_43 ,
V_40 , NULL , V_41 ) ||
0 == F_11 ( V_36 , & V_44 ,
V_40 , NULL , V_41 ) )
return 0 ;
return - V_45 ;
}
static int T_2 F_12 ( void )
{
int V_46 ;
if ( ( V_46 = F_13 ( & V_47 ) ) ) {
F_8 ( L_4 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_47 ) ;
}
