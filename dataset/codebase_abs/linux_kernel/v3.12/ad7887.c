static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( * V_2 -> V_6 ) {
case ( 1 << 0 ) :
V_4 -> V_7 = & V_4 -> V_8 [ V_9 ] ;
break;
case ( 1 << 1 ) :
V_4 -> V_7 = & V_4 -> V_8 [ V_10 ] ;
F_4 ( V_4 -> V_11 , V_4 -> V_7 ) ;
break;
case ( ( 1 << 1 ) | ( 1 << 0 ) ) :
V_4 -> V_7 = & V_4 -> V_8 [ V_12 ] ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_11 , & V_4 -> V_8 [ V_9 ] ) ;
}
static T_1 F_6 ( int V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_17 ;
int V_18 ;
V_18 = F_4 ( V_4 -> V_11 , V_4 -> V_7 ) ;
if ( V_18 )
goto V_19;
V_17 = F_7 () ;
if ( V_2 -> V_20 )
memcpy ( V_4 -> V_21 + V_2 -> V_22 - sizeof( T_2 ) ,
& V_17 , sizeof( V_17 ) ) ;
F_8 ( V_2 , V_4 -> V_21 ) ;
V_19:
F_9 ( V_2 -> V_23 ) ;
return V_24 ;
}
static int F_10 ( struct V_3 * V_4 , unsigned V_25 )
{
int V_5 = F_4 ( V_4 -> V_11 , & V_4 -> V_8 [ V_25 ] ) ;
if ( V_5 )
return V_5 ;
return ( V_4 -> V_21 [ ( V_25 * 2 ) ] << 8 ) | V_4 -> V_21 [ ( V_25 * 2 ) + 1 ] ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_26 const * V_27 ,
int * V_28 ,
int * V_29 ,
long V_30 )
{
int V_5 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_30 ) {
case V_31 :
F_12 ( & V_2 -> V_32 ) ;
if ( F_13 ( V_2 ) )
V_5 = - V_33 ;
else
V_5 = F_10 ( V_4 , V_27 -> V_34 ) ;
F_14 ( & V_2 -> V_32 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_28 = V_5 >> V_27 -> V_35 . V_36 ;
* V_28 &= F_15 ( V_27 -> V_35 . V_37 ) ;
return V_38 ;
case V_39 :
if ( V_4 -> V_40 ) {
* V_28 = F_16 ( V_4 -> V_40 ) ;
if ( * V_28 < 0 )
return * V_28 ;
* V_28 /= 1000 ;
} else {
* V_28 = V_4 -> V_41 -> V_42 ;
}
* V_29 = V_27 -> V_35 . V_37 ;
return V_43 ;
}
return - V_44 ;
}
static int F_17 ( struct V_45 * V_11 )
{
struct V_46 * V_47 = V_11 -> V_48 . V_49 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_3 V_50 ;
int V_5 ;
V_2 = F_18 ( & V_11 -> V_48 , sizeof( * V_4 ) ) ;
if ( V_2 == NULL )
return - V_51 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_47 || ! V_47 -> V_52 ) {
V_4 -> V_40 = F_19 ( & V_11 -> V_48 , L_1 ) ;
if ( F_20 ( V_4 -> V_40 ) )
return F_21 ( V_4 -> V_40 ) ;
V_5 = F_22 ( V_4 -> V_40 ) ;
if ( V_5 )
return V_5 ;
}
V_4 -> V_41 =
& V_53 [ F_23 ( V_11 ) -> V_54 ] ;
F_24 ( V_11 , V_2 ) ;
V_4 -> V_11 = V_11 ;
V_2 -> V_48 . V_55 = & V_11 -> V_48 ;
V_2 -> V_56 = F_23 ( V_11 ) -> V_56 ;
V_2 -> V_57 = & V_58 ;
V_2 -> V_59 = V_60 ;
V_50 = V_61 ;
if ( ! V_47 || ! V_47 -> V_52 )
V_50 |= V_62 ;
if ( V_47 && V_47 -> V_63 )
V_50 |= V_64 ;
V_4 -> V_65 [ 0 ] = V_66 | V_50 ;
V_4 -> V_67 [ 0 ] . V_68 = & V_4 -> V_21 [ 0 ] ;
V_4 -> V_67 [ 0 ] . V_69 = & V_4 -> V_65 [ 0 ] ;
V_4 -> V_67 [ 0 ] . V_70 = 2 ;
F_25 ( & V_4 -> V_8 [ V_9 ] ) ;
F_26 ( & V_4 -> V_67 [ 0 ] , & V_4 -> V_8 [ V_9 ] ) ;
if ( V_47 && V_47 -> V_63 ) {
V_4 -> V_65 [ 2 ] = V_71 | V_50 ;
V_4 -> V_67 [ 1 ] . V_68 = & V_4 -> V_21 [ 0 ] ;
V_4 -> V_67 [ 1 ] . V_69 = & V_4 -> V_65 [ 2 ] ;
V_4 -> V_67 [ 1 ] . V_70 = 2 ;
V_4 -> V_67 [ 2 ] . V_68 = & V_4 -> V_21 [ 2 ] ;
V_4 -> V_67 [ 2 ] . V_69 = & V_4 -> V_65 [ 0 ] ;
V_4 -> V_67 [ 2 ] . V_70 = 2 ;
F_25 ( & V_4 -> V_8 [ V_12 ] ) ;
F_26 ( & V_4 -> V_67 [ 1 ] , & V_4 -> V_8 [ V_12 ] ) ;
F_26 ( & V_4 -> V_67 [ 2 ] , & V_4 -> V_8 [ V_12 ] ) ;
V_4 -> V_67 [ 3 ] . V_68 = & V_4 -> V_21 [ 2 ] ;
V_4 -> V_67 [ 3 ] . V_69 = & V_4 -> V_65 [ 2 ] ;
V_4 -> V_67 [ 3 ] . V_70 = 2 ;
F_25 ( & V_4 -> V_8 [ V_10 ] ) ;
F_26 ( & V_4 -> V_67 [ 3 ] , & V_4 -> V_8 [ V_10 ] ) ;
V_2 -> V_72 = V_4 -> V_41 -> V_73 ;
V_2 -> V_74 = 3 ;
} else {
V_2 -> V_72 = & V_4 -> V_41 -> V_73 [ 1 ] ;
V_2 -> V_74 = 2 ;
}
V_5 = F_27 ( V_2 , & V_75 ,
& F_6 , & V_76 ) ;
if ( V_5 )
goto V_77;
V_5 = F_28 ( V_2 ) ;
if ( V_5 )
goto V_78;
return 0 ;
V_78:
F_29 ( V_2 ) ;
V_77:
if ( V_4 -> V_40 )
F_30 ( V_4 -> V_40 ) ;
return V_5 ;
}
static int F_31 ( struct V_45 * V_11 )
{
struct V_1 * V_2 = F_32 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( V_4 -> V_40 )
F_30 ( V_4 -> V_40 ) ;
return 0 ;
}
