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
int V_7 ;
struct V_13 V_14 [] = {
{
. V_15 = & V_6 -> V_9 [ 0 ] . V_12 [ 1 ] ,
. V_16 = 3 ,
. V_17 = 1 ,
} , {
. V_18 = & V_6 -> V_9 [ 1 ] . V_12 [ 1 ] ,
. V_16 = 3 ,
} ,
} ;
F_3 ( & V_2 -> V_8 ) ;
V_6 -> V_9 [ 0 ] . V_10 = F_4 ( ( 1 << 23 ) | ( V_3 << 16 ) ) ;
V_7 = F_8 ( V_6 -> V_11 , V_14 , F_9 ( V_14 ) ) ;
if ( V_7 >= 0 )
* V_4 = F_10 ( V_6 -> V_9 [ 1 ] . V_10 ) & 0xffff ;
F_6 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_11 ( struct V_19 const * V_20 , long V_21 )
{
switch ( V_21 ) {
case 0 :
return F_12 ( V_20 -> V_22 ) ;
case V_23 :
return F_13 ( V_20 -> V_22 ) ;
case V_24 :
return F_14 ( V_20 -> V_22 ) ;
default:
break;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_19 const * V_20 , int V_4 , int V_25 , long V_21 )
{
const int V_26 = ( 1 << V_20 -> V_27 . V_28 ) ;
unsigned int V_3 ;
switch ( V_21 ) {
case V_29 :
if ( V_4 >= V_26 || V_4 < 0 )
return - V_30 ;
V_4 <<= V_20 -> V_27 . V_31 ;
break;
case V_23 :
if ( V_4 >= 128 || V_4 < - 128 )
return - V_30 ;
break;
case V_24 :
if ( V_4 >= 32 || V_4 < - 32 )
return - V_30 ;
break;
default:
return - V_30 ;
}
V_3 = F_11 ( V_20 , V_21 ) ;
return F_1 ( V_2 , V_3 , ( V_32 ) V_4 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_33 )
{
if ( V_6 -> V_34 -> V_35 )
return V_6 -> V_34 -> V_35 ;
else
return F_17 ( V_6 -> V_36 [ V_33 / 2 ] . V_37 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_19 const * V_20 , int * V_4 , int * V_25 , long V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_38 ;
unsigned int V_3 ;
int V_39 ;
int V_7 ;
switch ( V_21 ) {
case V_29 :
V_3 = F_12 ( V_20 -> V_22 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 >>= V_20 -> V_27 . V_31 ;
return V_40 ;
case V_23 :
V_3 = F_13 ( V_20 -> V_22 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = F_19 ( * V_4 , 7 ) ;
return V_40 ;
case V_24 :
V_3 = F_14 ( V_20 -> V_22 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = F_19 ( * V_4 , 5 ) ;
return V_40 ;
case V_41 :
V_39 = F_16 ( V_6 , V_20 -> V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
V_38 = ( V_39 * 4 * 100 ) >> V_20 -> V_27 . V_28 ;
* V_4 = V_38 / 100000 ;
* V_25 = ( V_38 % 100000 ) * 10 ;
return V_42 ;
case V_43 :
* V_4 = - ( 1 << V_20 -> V_27 . V_28 ) / 2 ;
return V_40 ;
}
return - V_30 ;
}
static int F_20 ( struct V_44 * V_11 )
{
enum V_45 type = F_21 ( V_11 ) -> V_46 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
V_2 = F_22 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_23 ( & V_11 -> V_47 , L_1 ) ;
return - V_48 ;
}
V_6 = F_2 ( V_2 ) ;
F_24 ( V_11 , V_2 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_34 = & V_49 [ type ] ;
V_2 -> V_47 . V_50 = & V_11 -> V_47 ;
V_2 -> V_51 = F_21 ( V_11 ) -> V_51 ;
V_2 -> V_21 = & V_52 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = V_6 -> V_34 -> V_57 ;
if ( V_6 -> V_34 -> V_35 == 0 ) {
V_6 -> V_36 [ 0 ] . V_58 = L_2 ;
V_6 -> V_36 [ 1 ] . V_58 = L_3 ;
V_7 = F_25 ( & V_6 -> V_11 -> V_47 ,
F_9 ( V_6 -> V_36 ) , V_6 -> V_36 ) ;
if ( V_7 ) {
F_23 ( & V_11 -> V_47 , L_4 ,
V_7 ) ;
goto V_59;
}
V_7 = F_26 ( F_9 ( V_6 -> V_36 ) ,
V_6 -> V_36 ) ;
if ( V_7 ) {
F_23 ( & V_11 -> V_47 , L_5 ,
V_7 ) ;
goto V_60;
}
}
V_7 = F_27 ( V_2 ) ;
if ( V_7 ) {
F_23 ( & V_11 -> V_47 , L_6 , V_7 ) ;
goto V_61;
}
return 0 ;
V_61:
if ( V_6 -> V_34 -> V_35 == 0 )
F_28 ( F_9 ( V_6 -> V_36 ) , V_6 -> V_36 ) ;
V_60:
if ( V_6 -> V_34 -> V_35 == 0 )
F_29 ( F_9 ( V_6 -> V_36 ) , V_6 -> V_36 ) ;
V_59:
F_30 ( V_2 ) ;
return V_7 ;
}
static int F_31 ( struct V_44 * V_11 )
{
struct V_1 * V_2 = F_32 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( V_6 -> V_34 -> V_35 == 0 ) {
F_28 ( F_9 ( V_6 -> V_36 ) , V_6 -> V_36 ) ;
F_29 ( F_9 ( V_6 -> V_36 ) , V_6 -> V_36 ) ;
}
F_30 ( V_2 ) ;
return 0 ;
}
