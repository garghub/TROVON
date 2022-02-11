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
F_7 () ) ;
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
F_11 ( & V_2 -> V_29 ) ;
if ( F_12 ( V_2 ) )
V_22 = - V_30 ;
else
V_22 = F_9 ( V_4 , V_24 -> V_31 ) ;
F_13 ( & V_2 -> V_29 ) ;
if ( V_22 < 0 )
return V_22 ;
* V_25 = V_22 >> V_24 -> V_32 . V_33 ;
* V_25 &= F_14 ( V_24 -> V_32 . V_34 ) ;
return V_35 ;
case V_36 :
if ( V_4 -> V_37 ) {
* V_25 = F_15 ( V_4 -> V_37 ) ;
if ( * V_25 < 0 )
return * V_25 ;
* V_25 /= 1000 ;
} else {
* V_25 = V_4 -> V_38 -> V_39 ;
}
* V_26 = V_24 -> V_32 . V_34 ;
return V_40 ;
}
return - V_41 ;
}
static int F_16 ( struct V_42 * V_10 )
{
struct V_43 * V_44 = V_10 -> V_45 . V_46 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 V_47 ;
int V_22 ;
V_2 = F_17 ( & V_10 -> V_45 , sizeof( * V_4 ) ) ;
if ( V_2 == NULL )
return - V_48 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_44 || ! V_44 -> V_49 ) {
V_4 -> V_37 = F_18 ( & V_10 -> V_45 , L_1 ) ;
if ( F_19 ( V_4 -> V_37 ) )
return F_20 ( V_4 -> V_37 ) ;
V_22 = F_21 ( V_4 -> V_37 ) ;
if ( V_22 )
return V_22 ;
}
V_4 -> V_38 =
& V_50 [ F_22 ( V_10 ) -> V_51 ] ;
F_23 ( V_10 , V_2 ) ;
V_4 -> V_10 = V_10 ;
V_2 -> V_45 . V_52 = & V_10 -> V_45 ;
V_2 -> V_53 = F_22 ( V_10 ) -> V_53 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_56 = V_57 ;
V_47 = V_58 ;
if ( ! V_44 || ! V_44 -> V_49 )
V_47 |= V_59 ;
if ( V_44 && V_44 -> V_60 )
V_47 |= V_61 ;
V_4 -> V_62 [ 0 ] = V_63 | V_47 ;
V_4 -> V_64 [ 0 ] . V_65 = & V_4 -> V_18 [ 0 ] ;
V_4 -> V_64 [ 0 ] . V_66 = & V_4 -> V_62 [ 0 ] ;
V_4 -> V_64 [ 0 ] . V_67 = 2 ;
F_24 ( & V_4 -> V_7 [ V_8 ] ) ;
F_25 ( & V_4 -> V_64 [ 0 ] , & V_4 -> V_7 [ V_8 ] ) ;
if ( V_44 && V_44 -> V_60 ) {
V_4 -> V_62 [ 2 ] = V_68 | V_47 ;
V_4 -> V_64 [ 1 ] . V_65 = & V_4 -> V_18 [ 0 ] ;
V_4 -> V_64 [ 1 ] . V_66 = & V_4 -> V_62 [ 2 ] ;
V_4 -> V_64 [ 1 ] . V_67 = 2 ;
V_4 -> V_64 [ 2 ] . V_65 = & V_4 -> V_18 [ 2 ] ;
V_4 -> V_64 [ 2 ] . V_66 = & V_4 -> V_62 [ 0 ] ;
V_4 -> V_64 [ 2 ] . V_67 = 2 ;
F_24 ( & V_4 -> V_7 [ V_11 ] ) ;
F_25 ( & V_4 -> V_64 [ 1 ] , & V_4 -> V_7 [ V_11 ] ) ;
F_25 ( & V_4 -> V_64 [ 2 ] , & V_4 -> V_7 [ V_11 ] ) ;
V_4 -> V_64 [ 3 ] . V_65 = & V_4 -> V_18 [ 2 ] ;
V_4 -> V_64 [ 3 ] . V_66 = & V_4 -> V_62 [ 2 ] ;
V_4 -> V_64 [ 3 ] . V_67 = 2 ;
F_24 ( & V_4 -> V_7 [ V_9 ] ) ;
F_25 ( & V_4 -> V_64 [ 3 ] , & V_4 -> V_7 [ V_9 ] ) ;
V_2 -> V_69 = V_4 -> V_38 -> V_70 ;
V_2 -> V_71 = 3 ;
} else {
V_2 -> V_69 = & V_4 -> V_38 -> V_70 [ 1 ] ;
V_2 -> V_71 = 2 ;
}
V_22 = F_26 ( V_2 , & V_72 ,
& F_5 , & V_73 ) ;
if ( V_22 )
goto V_74;
V_22 = F_27 ( V_2 ) ;
if ( V_22 )
goto V_75;
return 0 ;
V_75:
F_28 ( V_2 ) ;
V_74:
if ( V_4 -> V_37 )
F_29 ( V_4 -> V_37 ) ;
return V_22 ;
}
static int F_30 ( struct V_42 * V_10 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_32 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_4 -> V_37 )
F_29 ( V_4 -> V_37 ) ;
return 0 ;
}
