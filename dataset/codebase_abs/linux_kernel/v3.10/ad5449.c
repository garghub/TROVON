static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_2 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = F_4 ( ( V_3 << 12 ) | V_4 ) ;
V_7 = F_5 ( V_6 -> V_10 , V_6 -> V_9 , 2 ) ;
F_6 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_11 V_12 ;
struct V_13 V_14 [] = {
{
. V_15 = & V_6 -> V_9 [ 0 ] ,
. V_16 = 2 ,
. V_17 = 1 ,
} , {
. V_15 = & V_6 -> V_9 [ 1 ] ,
. V_18 = & V_6 -> V_9 [ 1 ] ,
. V_16 = 2 ,
} ,
} ;
F_8 ( & V_12 ) ;
F_9 ( & V_14 [ 0 ] , & V_12 ) ;
F_9 ( & V_14 [ 1 ] , & V_12 ) ;
F_3 ( & V_2 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = F_4 ( V_3 << 12 ) ;
V_6 -> V_9 [ 1 ] = F_4 ( V_19 ) ;
V_7 = F_10 ( V_6 -> V_10 , & V_12 ) ;
if ( V_7 < 0 )
goto V_20;
* V_4 = F_11 ( V_6 -> V_9 [ 1 ] ) ;
V_20:
F_6 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_21 const * V_22 , int * V_4 , int * V_23 , long V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_26 ;
int V_27 ;
int V_7 ;
switch ( V_24 ) {
case V_28 :
if ( V_6 -> V_29 ) {
V_7 = F_7 ( V_2 ,
F_13 ( V_22 -> V_30 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
* V_4 &= 0xfff ;
} else {
* V_4 = V_6 -> V_31 [ V_22 -> V_30 ] ;
}
return V_32 ;
case V_33 :
V_26 = & V_6 -> V_34 [ V_22 -> V_35 ] ;
V_27 = F_14 ( V_26 -> V_36 ) ;
if ( V_27 < 0 )
return V_27 ;
* V_4 = V_27 / 1000 ;
* V_23 = V_22 -> V_37 . V_38 ;
return V_39 ;
default:
break;
}
return - V_40 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_21 const * V_22 , int V_4 , int V_23 , long V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_24 ) {
case V_28 :
if ( V_4 < 0 || V_4 >= ( 1 << V_22 -> V_37 . V_38 ) )
return - V_40 ;
V_7 = F_1 ( V_2 ,
F_16 ( V_22 -> V_30 ) ,
V_4 << V_22 -> V_37 . V_41 ) ;
if ( V_7 == 0 )
V_6 -> V_31 [ V_22 -> V_30 ] = V_4 ;
break;
default:
V_7 = - V_40 ;
}
return V_7 ;
}
static const char * F_17 ( struct V_5 * V_6 , int V_42 )
{
if ( V_6 -> V_43 -> V_44 == 1 )
return L_1 ;
if ( V_42 == 0 )
return L_2 ;
else
return L_3 ;
}
static int F_18 ( struct V_45 * V_10 )
{
struct V_46 * V_47 = V_10 -> V_48 . V_49 ;
const struct V_50 * V_51 = F_19 ( V_10 ) ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned int V_52 ;
int V_7 ;
V_2 = F_20 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL )
return - V_53 ;
V_6 = F_2 ( V_2 ) ;
F_21 ( V_10 , V_2 ) ;
V_6 -> V_43 = & V_54 [ V_51 -> V_55 ] ;
V_6 -> V_10 = V_10 ;
for ( V_52 = 0 ; V_52 < V_6 -> V_43 -> V_44 ; ++ V_52 )
V_6 -> V_34 [ V_52 ] . V_56 = F_17 ( V_6 , V_52 ) ;
V_7 = F_22 ( & V_10 -> V_48 , V_6 -> V_43 -> V_44 ,
V_6 -> V_34 ) ;
if ( V_7 )
goto V_57;
V_7 = F_23 ( V_6 -> V_43 -> V_44 , V_6 -> V_34 ) ;
if ( V_7 )
goto V_58;
V_2 -> V_48 . V_59 = & V_10 -> V_48 ;
V_2 -> V_60 = V_51 -> V_60 ;
V_2 -> V_24 = & V_61 ;
V_2 -> V_62 = V_63 ;
V_2 -> V_64 = V_6 -> V_43 -> V_64 ;
V_2 -> V_44 = V_6 -> V_43 -> V_44 ;
if ( V_6 -> V_43 -> V_65 ) {
unsigned int V_66 = 0x00 ;
if ( V_47 ) {
if ( V_47 -> V_67 )
V_66 |= V_68 ;
V_66 |= V_47 -> V_69 << V_70 ;
V_6 -> V_29 = V_47 -> V_69 != V_71 ;
} else {
V_6 -> V_29 = true ;
}
F_1 ( V_2 , V_72 , V_66 ) ;
}
V_7 = F_24 ( V_2 ) ;
if ( V_7 )
goto V_73;
return 0 ;
V_73:
F_25 ( V_6 -> V_43 -> V_44 , V_6 -> V_34 ) ;
V_58:
F_26 ( V_6 -> V_43 -> V_44 , V_6 -> V_34 ) ;
V_57:
F_27 ( V_2 ) ;
return V_7 ;
}
static int F_28 ( struct V_45 * V_10 )
{
struct V_1 * V_2 = F_29 ( V_10 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_30 ( V_2 ) ;
F_25 ( V_6 -> V_43 -> V_44 , V_6 -> V_34 ) ;
F_26 ( V_6 -> V_43 -> V_44 , V_6 -> V_34 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
