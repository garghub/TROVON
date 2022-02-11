static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_2 -> V_8 ) ;
V_6 -> V_9 [ 0 ] . V_10 = F_4 ( ( V_3 << 16 ) | V_4 ) ;
V_7 = F_5 ( V_6 -> V_11 , & V_6 -> V_9 [ 0 ] . V_12 [ 1 ] , 3 ) ;
F_6 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 V_14 ;
int V_7 ;
struct V_15 V_16 [] = {
{
. V_17 = & V_6 -> V_9 [ 0 ] . V_12 [ 1 ] ,
. V_18 = 3 ,
. V_19 = 1 ,
} , {
. V_20 = & V_6 -> V_9 [ 1 ] . V_12 [ 1 ] ,
. V_18 = 3 ,
} ,
} ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
F_3 ( & V_2 -> V_8 ) ;
V_6 -> V_9 [ 0 ] . V_10 = F_4 ( ( 1 << 23 ) | ( V_3 << 16 ) ) ;
V_7 = F_10 ( V_6 -> V_11 , & V_14 ) ;
if ( V_7 >= 0 )
* V_4 = F_11 ( V_6 -> V_9 [ 1 ] . V_10 ) & 0xffff ;
F_6 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_12 ( struct V_21 const * V_22 , long V_23 )
{
switch ( V_23 ) {
case 0 :
return F_13 ( V_22 -> V_24 ) ;
case V_25 :
return F_14 ( V_22 -> V_24 ) ;
case V_26 :
return F_15 ( V_22 -> V_24 ) ;
default:
break;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_21 const * V_22 , int V_4 , int V_27 , long V_23 )
{
const int V_28 = ( 1 << V_22 -> V_29 . V_30 ) ;
unsigned int V_3 ;
switch ( V_23 ) {
case V_31 :
if ( V_4 >= V_28 || V_4 < 0 )
return - V_32 ;
V_4 <<= V_22 -> V_29 . V_33 ;
break;
case V_25 :
if ( V_4 >= 128 || V_4 < - 128 )
return - V_32 ;
break;
case V_26 :
if ( V_4 >= 32 || V_4 < - 32 )
return - V_32 ;
break;
default:
return - V_32 ;
}
V_3 = F_12 ( V_22 , V_23 ) ;
return F_1 ( V_2 , V_3 , ( V_34 ) V_4 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_35 )
{
if ( V_6 -> V_36 -> V_37 )
return V_6 -> V_36 -> V_37 ;
else
return F_18 ( V_6 -> V_38 [ V_35 / 2 ] . V_39 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_21 const * V_22 , int * V_4 , int * V_27 , long V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_40 ;
unsigned int V_3 ;
int V_41 ;
int V_7 ;
switch ( V_23 ) {
case V_31 :
V_3 = F_13 ( V_22 -> V_24 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 >>= V_22 -> V_29 . V_33 ;
return V_42 ;
case V_25 :
V_3 = F_14 ( V_22 -> V_24 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = F_20 ( * V_4 , 7 ) ;
return V_42 ;
case V_26 :
V_3 = F_15 ( V_22 -> V_24 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = F_20 ( * V_4 , 5 ) ;
return V_42 ;
case V_43 :
V_41 = F_17 ( V_6 , V_22 -> V_35 ) ;
if ( V_41 < 0 )
return V_41 ;
V_40 = ( V_41 * 4 * 100 ) >> V_22 -> V_29 . V_30 ;
* V_4 = V_40 / 100000 ;
* V_27 = ( V_40 % 100000 ) * 10 ;
return V_44 ;
case V_45 :
* V_4 = - ( 1 << V_22 -> V_29 . V_30 ) / 2 ;
return V_42 ;
}
return - V_32 ;
}
static int F_21 ( struct V_46 * V_11 )
{
enum V_47 type = F_22 ( V_11 ) -> V_48 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
V_2 = F_23 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_24 ( & V_11 -> V_49 , L_1 ) ;
return - V_50 ;
}
V_6 = F_2 ( V_2 ) ;
F_25 ( V_11 , V_2 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_36 = & V_51 [ type ] ;
V_2 -> V_49 . V_52 = & V_11 -> V_49 ;
V_2 -> V_53 = F_22 ( V_11 ) -> V_53 ;
V_2 -> V_23 = & V_54 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = V_58 ;
V_2 -> V_59 = V_6 -> V_36 -> V_59 ;
if ( V_6 -> V_36 -> V_37 == 0 ) {
V_6 -> V_38 [ 0 ] . V_60 = L_2 ;
V_6 -> V_38 [ 1 ] . V_60 = L_3 ;
V_7 = F_26 ( & V_6 -> V_11 -> V_49 ,
F_27 ( V_6 -> V_38 ) , V_6 -> V_38 ) ;
if ( V_7 ) {
F_24 ( & V_11 -> V_49 , L_4 ,
V_7 ) ;
goto V_61;
}
V_7 = F_28 ( F_27 ( V_6 -> V_38 ) ,
V_6 -> V_38 ) ;
if ( V_7 ) {
F_24 ( & V_11 -> V_49 , L_5 ,
V_7 ) ;
goto V_62;
}
}
V_7 = F_29 ( V_2 ) ;
if ( V_7 ) {
F_24 ( & V_11 -> V_49 , L_6 , V_7 ) ;
goto V_63;
}
return 0 ;
V_63:
if ( V_6 -> V_36 -> V_37 == 0 )
F_30 ( F_27 ( V_6 -> V_38 ) , V_6 -> V_38 ) ;
V_62:
if ( V_6 -> V_36 -> V_37 == 0 )
F_31 ( F_27 ( V_6 -> V_38 ) , V_6 -> V_38 ) ;
V_61:
F_32 ( V_2 ) ;
return V_7 ;
}
static int F_33 ( struct V_46 * V_11 )
{
struct V_1 * V_2 = F_34 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( V_6 -> V_36 -> V_37 == 0 ) {
F_30 ( F_27 ( V_6 -> V_38 ) , V_6 -> V_38 ) ;
F_31 ( F_27 ( V_6 -> V_38 ) , V_6 -> V_38 ) ;
}
F_32 ( V_2 ) ;
return 0 ;
}
