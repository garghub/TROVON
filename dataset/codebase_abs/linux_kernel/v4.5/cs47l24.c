static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_9 :
return F_3 ( & V_8 -> V_10 [ 0 ] , V_4 , V_5 , V_6 ) ;
case V_11 :
return F_3 ( & V_8 -> V_10 [ 1 ] , V_4 , V_5 , V_6 ) ;
case V_12 :
return F_4 ( & V_8 -> V_10 [ 0 ] , V_4 , V_5 ,
V_6 ) ;
case V_13 :
return F_4 ( & V_8 -> V_10 [ 1 ] , V_4 , V_5 ,
V_6 ) ;
default:
return - V_14 ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_7 * V_17 = F_2 ( V_2 ) ;
int V_18 ;
V_17 -> V_19 . V_20 -> V_16 = V_16 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
V_18 = F_10 ( & V_17 -> V_19 . V_21 [ 1 ] , V_2 ) ;
if ( V_18 )
goto V_22;
V_18 = F_10 ( & V_17 -> V_19 . V_21 [ 2 ] , V_2 ) ;
if ( V_18 )
goto V_22;
V_18 = F_11 ( V_2 ,
& V_23 [ 1 ] , 2 ) ;
if ( V_18 )
goto V_22;
F_12 ( V_16 , L_1 ) ;
return 0 ;
V_22:
F_13 ( & V_17 -> V_19 . V_21 [ 1 ] , V_2 ) ;
F_13 ( & V_17 -> V_19 . V_21 [ 2 ] , V_2 ) ;
return V_18 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_17 = F_2 ( V_2 ) ;
F_13 ( & V_17 -> V_19 . V_21 [ 1 ] , V_2 ) ;
F_13 ( & V_17 -> V_19 . V_21 [ 2 ] , V_2 ) ;
V_17 -> V_19 . V_20 -> V_16 = NULL ;
return 0 ;
}
static struct V_24 * F_15 ( struct V_25 * V_26 )
{
struct V_7 * V_17 = F_16 ( V_26 ) ;
return V_17 -> V_19 . V_20 -> V_24 ;
}
static int F_17 ( struct V_27 * V_28 )
{
struct V_20 * V_20 = F_16 ( V_28 -> V_26 . V_29 ) ;
struct V_7 * V_8 ;
int V_30 , V_18 ;
F_18 ( F_19 ( V_31 ) > V_32 ) ;
V_8 = F_20 ( & V_28 -> V_26 , sizeof( struct V_7 ) ,
V_33 ) ;
if ( ! V_8 )
return - V_34 ;
F_21 ( V_28 , V_8 ) ;
V_8 -> V_19 . V_20 = V_20 ;
V_8 -> V_19 . V_35 = 4 ;
for ( V_30 = 1 ; V_30 <= 2 ; V_30 ++ ) {
V_8 -> V_19 . V_21 [ V_30 ] . V_36 = L_2 ;
V_8 -> V_19 . V_21 [ V_30 ] . V_37 = V_30 + 1 ;
V_8 -> V_19 . V_21 [ V_30 ] . type = V_38 ;
V_8 -> V_19 . V_21 [ V_30 ] . V_26 = V_20 -> V_26 ;
V_8 -> V_19 . V_21 [ V_30 ] . V_24 = V_20 -> V_24 ;
V_8 -> V_19 . V_21 [ V_30 ] . V_39 = V_40 +
( 0x100 * V_30 ) ;
V_8 -> V_19 . V_21 [ V_30 ] . V_41 = V_42 [ V_30 - 1 ] ;
V_8 -> V_19 . V_21 [ V_30 ] . V_43 =
F_19 ( V_44 ) ;
V_18 = F_22 ( & V_8 -> V_19 . V_21 [ V_30 ] ) ;
if ( V_18 != 0 )
return V_18 ;
}
for ( V_30 = 0 ; V_30 < F_19 ( V_8 -> V_10 ) ; V_30 ++ )
V_8 -> V_10 [ V_30 ] . V_45 = 3 ;
F_23 ( V_20 , 1 , V_46 - 1 ,
V_47 , V_48 ,
& V_8 -> V_10 [ 0 ] ) ;
F_23 ( V_20 , 2 , V_49 - 1 ,
V_50 , V_51 ,
& V_8 -> V_10 [ 1 ] ) ;
F_24 ( V_20 -> V_24 , V_52 ,
V_53 , 0x11 ) ;
F_24 ( V_20 -> V_24 , V_54 ,
V_55 , 0x12 ) ;
for ( V_30 = 0 ; V_30 < F_19 ( V_31 ) ; V_30 ++ )
F_25 ( & V_8 -> V_19 , V_30 ) ;
for ( V_30 = 0 ; V_30 < F_19 ( V_56 ) ; V_30 ++ )
F_24 ( V_20 -> V_24 , V_56 [ V_30 ] ,
V_57 , V_57 ) ;
F_26 ( & V_28 -> V_26 ) ;
F_27 ( & V_28 -> V_26 ) ;
return F_28 ( & V_28 -> V_26 , & V_58 ,
V_31 , F_19 ( V_31 ) ) ;
}
static int F_29 ( struct V_27 * V_28 )
{
F_30 ( & V_28 -> V_26 ) ;
F_31 ( & V_28 -> V_26 ) ;
return 0 ;
}
