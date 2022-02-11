static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 == V_9 &&
V_6 -> V_10 == V_11 ) {
struct V_12 V_13 [] = {
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
F_2 ( L_15 ) ,
{ } ,
} ;
return F_4 ( V_4 , V_13 ) ;
}
if ( V_6 -> V_8 == V_14 ) {
int V_15 ;
struct V_12 V_13 [] = {
F_5 ( L_16 , L_17 ) ,
F_2 ( L_15 ) ,
{ }
} ;
V_15 = F_4 ( V_4 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_6 -> V_10 == V_16 ||
V_6 -> V_10 == V_17 ) {
F_6 ( V_18 , V_2 -> V_19 ) ;
V_2 -> V_20 = true ;
}
if ( V_6 -> V_10 == V_21 ) {
struct V_22 * V_23 ;
F_7 ( F_8 ( & V_6 -> V_24 ) ,
V_25 ) ;
V_23 = F_9 ( & V_6 -> V_24 , L_18 , V_26 ) ;
if ( F_10 ( V_23 ) )
return F_11 ( V_23 ) ;
F_12 ( V_23 , 1 ) ;
F_13 ( V_23 ) ;
V_23 = F_9 ( & V_6 -> V_24 , L_19 , V_26 ) ;
if ( F_10 ( V_23 ) )
return F_11 ( V_23 ) ;
if ( V_23 ) {
F_12 ( V_23 , 1 ) ;
F_13 ( V_23 ) ;
F_14 ( 10000 , 11000 ) ;
}
}
}
if ( V_6 -> V_8 == V_27 &&
( V_6 -> V_10 == V_28 ||
V_6 -> V_10 == V_29 ||
V_6 -> V_10 == V_30 ) ) {
struct V_12 V_13 [] = {
F_2 ( L_20 ) ,
F_2 ( L_1 ) ,
F_2 ( L_21 ) ,
F_2 ( L_15 ) ,
{ } ,
} ;
return F_4 ( V_4 , V_13 ) ;
}
return 0 ;
}
static int F_15 ( struct V_5 * V_7 ,
const struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_33 V_34 [ 2 ] ;
int V_15 ;
struct V_10 * V_24 = & V_7 -> V_24 ;
V_15 = F_16 ( V_7 ) ;
if ( V_15 ) {
F_17 ( V_24 , L_22 ) ;
return - V_35 ;
}
F_18 ( V_7 ) ;
V_2 = F_19 ( V_24 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_4 = F_20 ( L_23 , V_38 ) ;
if ( ! V_2 -> V_4 )
return - V_37 ;
memset ( V_34 , 0x00 , sizeof( struct V_33 ) * F_21 ( V_34 ) ) ;
V_34 [ 0 ] . V_39 = F_22 ( V_7 , 0 ) ;
V_34 [ 0 ] . V_40 = F_23 ( V_7 , 0 ) ;
V_34 [ 0 ] . V_41 = L_24 ;
V_34 [ 0 ] . V_42 = V_43 ;
V_34 [ 1 ] . V_39 = V_7 -> V_44 ;
V_34 [ 1 ] . V_41 = L_24 ;
V_34 [ 1 ] . V_42 = V_45 ;
V_15 = F_24 ( V_2 -> V_4 , V_34 , F_21 ( V_34 ) ) ;
if ( V_15 ) {
F_17 ( V_24 , L_25 ) ;
return V_15 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_4 -> V_24 . V_46 = V_24 ;
F_25 ( & V_2 -> V_4 -> V_24 , F_8 ( V_24 ) ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
goto V_47;
V_15 = F_26 ( V_2 -> V_4 ) ;
if ( V_15 ) {
F_17 ( V_24 , L_26 ) ;
goto V_47;
}
F_27 ( V_24 , true ) ;
F_28 ( V_24 , true ) ;
F_29 ( V_7 , V_2 ) ;
F_30 ( V_24 ) ;
return 0 ;
V_47:
F_31 ( V_2 -> V_4 ) ;
return V_15 ;
}
static void F_32 ( struct V_5 * V_7 )
{
struct V_1 * V_2 = F_33 ( V_7 ) ;
F_27 ( & V_7 -> V_24 , false ) ;
F_34 ( & V_7 -> V_24 ) ;
F_35 ( F_8 ( & V_7 -> V_24 ) ) ;
F_36 ( V_2 -> V_4 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_48 )
{
union V_49 * V_50 ;
union V_49 V_51 ;
union V_49 V_52 = F_38 ( 1 , & V_51 ) ;
if ( ! V_2 -> V_20 )
return 0 ;
V_51 . type = V_53 ;
V_51 . integer . V_54 = V_48 ;
V_50 = F_39 ( F_40 ( & V_2 -> V_7 -> V_24 ) , V_2 -> V_19 ,
1 , V_55 , & V_52 ) ;
if ( ! V_50 ) {
F_17 ( & V_2 -> V_7 -> V_24 , L_27 ) ;
return - V_56 ;
}
F_41 ( V_50 ) ;
return 0 ;
}
static int F_42 ( struct V_10 * V_24 )
{
struct V_1 * V_2 = F_43 ( V_24 ) ;
if ( F_44 ( V_24 ) )
return F_37 ( V_2 , V_57 ) ;
return - V_58 ;
}
static int F_45 ( struct V_10 * V_24 )
{
struct V_1 * V_2 = F_43 ( V_24 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_15 ;
V_15 = F_37 ( V_2 , V_59 ) ;
if ( V_15 )
return V_15 ;
return F_34 ( & V_4 -> V_24 ) ;
}
static int F_46 ( struct V_10 * V_24 )
{
struct V_1 * V_2 = F_43 ( V_24 ) ;
return F_37 ( V_2 , V_57 ) ;
}
static int F_47 ( struct V_10 * V_24 )
{
struct V_1 * V_2 = F_43 ( V_24 ) ;
return F_37 ( V_2 , V_59 ) ;
}
