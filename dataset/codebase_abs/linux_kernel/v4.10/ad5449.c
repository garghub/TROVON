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
struct V_11 V_12 [] = {
{
. V_13 = & V_6 -> V_9 [ 0 ] ,
. V_14 = 2 ,
. V_15 = 1 ,
} , {
. V_13 = & V_6 -> V_9 [ 1 ] ,
. V_16 = & V_6 -> V_9 [ 1 ] ,
. V_14 = 2 ,
} ,
} ;
F_3 ( & V_2 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = F_4 ( V_3 << 12 ) ;
V_6 -> V_9 [ 1 ] = F_4 ( V_17 ) ;
V_7 = F_8 ( V_6 -> V_10 , V_12 , F_9 ( V_12 ) ) ;
if ( V_7 < 0 )
goto V_18;
* V_4 = F_10 ( V_6 -> V_9 [ 1 ] ) ;
V_18:
F_6 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_19 const * V_20 , int * V_4 , int * V_21 , long V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_23 * V_24 ;
int V_25 ;
int V_7 ;
switch ( V_22 ) {
case V_26 :
if ( V_6 -> V_27 ) {
V_7 = F_7 ( V_2 ,
F_12 ( V_20 -> V_28 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
* V_4 &= 0xfff ;
} else {
* V_4 = V_6 -> V_29 [ V_20 -> V_28 ] ;
}
return V_30 ;
case V_31 :
V_24 = & V_6 -> V_32 [ V_20 -> V_33 ] ;
V_25 = F_13 ( V_24 -> V_34 ) ;
if ( V_25 < 0 )
return V_25 ;
* V_4 = V_25 / 1000 ;
* V_21 = V_20 -> V_35 . V_36 ;
return V_37 ;
default:
break;
}
return - V_38 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_19 const * V_20 , int V_4 , int V_21 , long V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_22 ) {
case V_26 :
if ( V_4 < 0 || V_4 >= ( 1 << V_20 -> V_35 . V_36 ) )
return - V_38 ;
V_7 = F_1 ( V_2 ,
F_15 ( V_20 -> V_28 ) ,
V_4 << V_20 -> V_35 . V_39 ) ;
if ( V_7 == 0 )
V_6 -> V_29 [ V_20 -> V_28 ] = V_4 ;
break;
default:
V_7 = - V_38 ;
}
return V_7 ;
}
static const char * F_16 ( struct V_5 * V_6 , int V_40 )
{
if ( V_6 -> V_41 -> V_42 == 1 )
return L_1 ;
if ( V_40 == 0 )
return L_2 ;
else
return L_3 ;
}
static int F_17 ( struct V_43 * V_10 )
{
struct V_44 * V_45 = V_10 -> V_46 . V_47 ;
const struct V_48 * V_49 = F_18 ( V_10 ) ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned int V_50 ;
int V_7 ;
V_2 = F_19 ( & V_10 -> V_46 , sizeof( * V_6 ) ) ;
if ( V_2 == NULL )
return - V_51 ;
V_6 = F_2 ( V_2 ) ;
F_20 ( V_10 , V_2 ) ;
V_6 -> V_41 = & V_52 [ V_49 -> V_53 ] ;
V_6 -> V_10 = V_10 ;
for ( V_50 = 0 ; V_50 < V_6 -> V_41 -> V_42 ; ++ V_50 )
V_6 -> V_32 [ V_50 ] . V_54 = F_16 ( V_6 , V_50 ) ;
V_7 = F_21 ( & V_10 -> V_46 , V_6 -> V_41 -> V_42 ,
V_6 -> V_32 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_22 ( V_6 -> V_41 -> V_42 , V_6 -> V_32 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_46 . V_55 = & V_10 -> V_46 ;
V_2 -> V_56 = V_49 -> V_56 ;
V_2 -> V_22 = & V_57 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = V_6 -> V_41 -> V_60 ;
V_2 -> V_42 = V_6 -> V_41 -> V_42 ;
if ( V_6 -> V_41 -> V_61 ) {
unsigned int V_62 = 0x00 ;
if ( V_45 ) {
if ( V_45 -> V_63 )
V_62 |= V_64 ;
V_62 |= V_45 -> V_65 << V_66 ;
V_6 -> V_27 = V_45 -> V_65 != V_67 ;
} else {
V_6 -> V_27 = true ;
}
F_1 ( V_2 , V_68 , V_62 ) ;
}
V_7 = F_23 ( V_2 ) ;
if ( V_7 )
goto V_69;
return 0 ;
V_69:
F_24 ( V_6 -> V_41 -> V_42 , V_6 -> V_32 ) ;
return V_7 ;
}
static int F_25 ( struct V_43 * V_10 )
{
struct V_1 * V_2 = F_26 ( V_10 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_27 ( V_2 ) ;
F_24 ( V_6 -> V_41 -> V_42 , V_6 -> V_32 ) ;
return 0 ;
}
