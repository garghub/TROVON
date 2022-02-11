static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_6 &&
V_2 -> V_7 == V_8 ) {
struct V_9 V_10 [] = {
F_2 ( L_1 ) ,
F_3 ( L_2 , 0xf ) ,
F_2 ( L_3 ) ,
F_2 ( L_4 ) ,
F_2 ( L_5 ) ,
F_2 ( L_6 ) ,
F_2 ( L_7 ) ,
F_2 ( L_8 ) ,
F_2 ( L_9 ) ,
F_2 ( L_10 ) ,
F_3 ( L_11 , 1 ) ,
F_2 ( L_12 ) ,
F_2 ( L_13 ) ,
F_2 ( L_14 ) ,
{ } ,
} ;
return F_4 ( V_4 , V_10 ) ;
}
if ( V_2 -> V_5 == V_11 ) {
int V_12 ;
struct V_9 V_10 [] = {
F_5 ( L_15 , L_16 ) ,
{ }
} ;
V_12 = F_4 ( V_4 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_7 == V_13 ) {
struct V_14 * V_15 ;
F_6 ( F_7 ( & V_2 -> V_16 ) ,
V_17 ) ;
V_15 = F_8 ( & V_2 -> V_16 , L_17 , V_18 ) ;
if ( F_9 ( V_15 ) )
return F_10 ( V_15 ) ;
F_11 ( V_15 , 1 ) ;
F_12 ( V_15 ) ;
V_15 = F_8 ( & V_2 -> V_16 , L_18 , V_18 ) ;
if ( F_9 ( V_15 ) )
return F_10 ( V_15 ) ;
if ( V_15 ) {
F_11 ( V_15 , 1 ) ;
F_12 ( V_15 ) ;
F_13 ( 10000 , 11000 ) ;
}
}
}
if ( V_2 -> V_5 == V_19 &&
( V_2 -> V_7 == V_20 ||
V_2 -> V_7 == V_21 ||
V_2 -> V_7 == V_22 ) ) {
struct V_9 V_10 [] = {
F_2 ( L_19 ) ,
F_2 ( L_1 ) ,
F_2 ( L_20 ) ,
{ } ,
} ;
return F_4 ( V_4 , V_10 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 V_27 [ 2 ] ;
struct V_3 * V_4 ;
int V_12 ;
struct V_7 * V_16 = & V_23 -> V_16 ;
V_12 = F_15 ( V_23 ) ;
if ( V_12 ) {
F_16 ( V_16 , L_21 ) ;
return - V_28 ;
}
F_17 ( V_23 ) ;
V_4 = F_18 ( L_22 , V_29 ) ;
if ( ! V_4 ) {
F_16 ( V_16 , L_23 ) ;
return - V_30 ;
}
memset ( V_27 , 0x00 , sizeof( struct V_26 ) * F_19 ( V_27 ) ) ;
V_27 [ 0 ] . V_31 = F_20 ( V_23 , 0 ) ;
V_27 [ 0 ] . V_32 = F_21 ( V_23 , 0 ) ;
V_27 [ 0 ] . V_33 = L_24 ;
V_27 [ 0 ] . V_34 = V_35 ;
V_27 [ 1 ] . V_31 = V_23 -> V_36 ;
V_27 [ 1 ] . V_33 = L_24 ;
V_27 [ 1 ] . V_34 = V_37 ;
V_12 = F_22 ( V_4 , V_27 , F_19 ( V_27 ) ) ;
if ( V_12 ) {
F_16 ( V_16 , L_25 ) ;
return V_12 ;
}
V_4 -> V_16 . V_38 = V_16 ;
F_23 ( & V_4 -> V_16 , F_7 ( V_16 ) ) ;
V_12 = F_1 ( V_23 , V_4 ) ;
if ( V_12 )
goto V_39;
V_12 = F_24 ( V_4 ) ;
if ( V_12 ) {
F_16 ( V_16 , L_26 ) ;
goto V_39;
}
F_25 ( V_16 , true ) ;
F_26 ( V_16 , true ) ;
F_27 ( V_23 , V_4 ) ;
F_28 ( V_16 ) ;
return 0 ;
V_39:
F_29 ( V_4 ) ;
return V_12 ;
}
static void F_30 ( struct V_1 * V_23 )
{
F_25 ( & V_23 -> V_16 , false ) ;
F_31 ( & V_23 -> V_16 ) ;
F_32 ( F_7 ( & V_23 -> V_16 ) ) ;
F_33 ( F_34 ( V_23 ) ) ;
}
static int F_35 ( struct V_7 * V_16 )
{
if ( F_36 ( V_16 ) )
return 0 ;
return - V_40 ;
}
static int F_37 ( struct V_7 * V_16 )
{
struct V_3 * V_4 = F_38 ( V_16 ) ;
return F_31 ( & V_4 -> V_16 ) ;
}
static int F_39 ( struct V_7 * V_16 )
{
return 0 ;
}
