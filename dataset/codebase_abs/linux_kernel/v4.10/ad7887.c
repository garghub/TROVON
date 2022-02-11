static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( * V_2 -> V_5 ) {
case ( 1 << 0 ) :
V_4 -> V_6 = & V_4 -> V_7 [ V_8 ] ;
break;
case ( 1 << 1 ) :
V_4 -> V_6 = & V_4 -> V_7 [ V_9 ] ;
F_3 ( V_4 -> V_10 , V_4 -> V_6 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_4 -> V_6 = & V_4 -> V_7 [ V_11 ] ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_10 , & V_4 -> V_7 [ V_8 ] ) ;
}
static T_1 F_5 ( int V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
V_16 = F_3 ( V_4 -> V_10 , V_4 -> V_6 ) ;
if ( V_16 )
goto V_17;
F_6 ( V_2 , V_4 -> V_18 ,
F_7 ( V_2 ) ) ;
V_17:
F_8 ( V_2 -> V_19 ) ;
return V_20 ;
}
static int F_9 ( struct V_3 * V_4 , unsigned V_21 )
{
int V_22 = F_3 ( V_4 -> V_10 , & V_4 -> V_7 [ V_21 ] ) ;
if ( V_22 )
return V_22 ;
return ( V_4 -> V_18 [ ( V_21 * 2 ) ] << 8 ) | V_4 -> V_18 [ ( V_21 * 2 ) + 1 ] ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_23 const * V_24 ,
int * V_25 ,
int * V_26 ,
long V_27 )
{
int V_22 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_27 ) {
case V_28 :
V_22 = F_11 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_9 ( V_4 , V_24 -> V_29 ) ;
F_12 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
* V_25 = V_22 >> V_24 -> V_30 . V_31 ;
* V_25 &= F_13 ( V_24 -> V_30 . V_32 - 1 , 0 ) ;
return V_33 ;
case V_34 :
if ( V_4 -> V_35 ) {
* V_25 = F_14 ( V_4 -> V_35 ) ;
if ( * V_25 < 0 )
return * V_25 ;
* V_25 /= 1000 ;
} else {
* V_25 = V_4 -> V_36 -> V_37 ;
}
* V_26 = V_24 -> V_30 . V_32 ;
return V_38 ;
}
return - V_39 ;
}
static int F_15 ( struct V_40 * V_10 )
{
struct V_41 * V_42 = V_10 -> V_43 . V_44 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 V_45 ;
int V_22 ;
V_2 = F_16 ( & V_10 -> V_43 , sizeof( * V_4 ) ) ;
if ( V_2 == NULL )
return - V_46 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_42 || ! V_42 -> V_47 ) {
V_4 -> V_35 = F_17 ( & V_10 -> V_43 , L_1 ) ;
if ( F_18 ( V_4 -> V_35 ) )
return F_19 ( V_4 -> V_35 ) ;
V_22 = F_20 ( V_4 -> V_35 ) ;
if ( V_22 )
return V_22 ;
}
V_4 -> V_36 =
& V_48 [ F_21 ( V_10 ) -> V_49 ] ;
F_22 ( V_10 , V_2 ) ;
V_4 -> V_10 = V_10 ;
V_2 -> V_43 . V_50 = & V_10 -> V_43 ;
V_2 -> V_43 . V_51 = V_10 -> V_43 . V_51 ;
V_2 -> V_52 = F_21 ( V_10 ) -> V_52 ;
V_2 -> V_53 = & V_54 ;
V_2 -> V_55 = V_56 ;
V_45 = V_57 ;
if ( ! V_42 || ! V_42 -> V_47 )
V_45 |= V_58 ;
if ( V_42 && V_42 -> V_59 )
V_45 |= V_60 ;
V_4 -> V_61 [ 0 ] = V_62 | V_45 ;
V_4 -> V_63 [ 0 ] . V_64 = & V_4 -> V_18 [ 0 ] ;
V_4 -> V_63 [ 0 ] . V_65 = & V_4 -> V_61 [ 0 ] ;
V_4 -> V_63 [ 0 ] . V_66 = 2 ;
F_23 ( & V_4 -> V_7 [ V_8 ] ) ;
F_24 ( & V_4 -> V_63 [ 0 ] , & V_4 -> V_7 [ V_8 ] ) ;
if ( V_42 && V_42 -> V_59 ) {
V_4 -> V_61 [ 2 ] = V_67 | V_45 ;
V_4 -> V_63 [ 1 ] . V_64 = & V_4 -> V_18 [ 0 ] ;
V_4 -> V_63 [ 1 ] . V_65 = & V_4 -> V_61 [ 2 ] ;
V_4 -> V_63 [ 1 ] . V_66 = 2 ;
V_4 -> V_63 [ 2 ] . V_64 = & V_4 -> V_18 [ 2 ] ;
V_4 -> V_63 [ 2 ] . V_65 = & V_4 -> V_61 [ 0 ] ;
V_4 -> V_63 [ 2 ] . V_66 = 2 ;
F_23 ( & V_4 -> V_7 [ V_11 ] ) ;
F_24 ( & V_4 -> V_63 [ 1 ] , & V_4 -> V_7 [ V_11 ] ) ;
F_24 ( & V_4 -> V_63 [ 2 ] , & V_4 -> V_7 [ V_11 ] ) ;
V_4 -> V_63 [ 3 ] . V_64 = & V_4 -> V_18 [ 2 ] ;
V_4 -> V_63 [ 3 ] . V_65 = & V_4 -> V_61 [ 2 ] ;
V_4 -> V_63 [ 3 ] . V_66 = 2 ;
F_23 ( & V_4 -> V_7 [ V_9 ] ) ;
F_24 ( & V_4 -> V_63 [ 3 ] , & V_4 -> V_7 [ V_9 ] ) ;
V_2 -> V_68 = V_4 -> V_36 -> V_69 ;
V_2 -> V_70 = 3 ;
} else {
V_2 -> V_68 = & V_4 -> V_36 -> V_69 [ 1 ] ;
V_2 -> V_70 = 2 ;
}
V_22 = F_25 ( V_2 , & V_71 ,
& F_5 , & V_72 ) ;
if ( V_22 )
goto V_73;
V_22 = F_26 ( V_2 ) ;
if ( V_22 )
goto V_74;
return 0 ;
V_74:
F_27 ( V_2 ) ;
V_73:
if ( V_4 -> V_35 )
F_28 ( V_4 -> V_35 ) ;
return V_22 ;
}
static int F_29 ( struct V_40 * V_10 )
{
struct V_1 * V_2 = F_30 ( V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( V_4 -> V_35 )
F_28 ( V_4 -> V_35 ) ;
return 0 ;
}
