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
case 0 :
if ( V_4 >= V_28 || V_4 < 0 )
return - V_31 ;
V_4 <<= V_22 -> V_29 . V_32 ;
break;
case V_25 :
if ( V_4 >= 128 || V_4 < - 128 )
return - V_31 ;
break;
case V_26 :
if ( V_4 >= 32 || V_4 < - 32 )
return - V_31 ;
break;
default:
return - V_31 ;
}
V_3 = F_12 ( V_22 , V_23 ) ;
return F_1 ( V_2 , V_3 , ( V_33 ) V_4 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_34 )
{
if ( V_6 -> V_35 -> V_36 )
return V_6 -> V_35 -> V_36 ;
else
return F_18 ( V_6 -> V_37 [ V_34 / 2 ] . V_38 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_21 const * V_22 , int * V_4 , int * V_27 , long V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_39 ;
unsigned int V_3 ;
int V_40 ;
int V_7 ;
switch ( V_23 ) {
case 0 :
V_3 = F_13 ( V_22 -> V_24 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 >>= V_22 -> V_29 . V_32 ;
return V_41 ;
case V_25 :
V_3 = F_14 ( V_22 -> V_24 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = F_20 ( * V_4 , 7 ) ;
return V_41 ;
case V_26 :
V_3 = F_15 ( V_22 -> V_24 ) ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = F_20 ( * V_4 , 5 ) ;
return V_41 ;
case V_42 :
V_40 = F_17 ( V_6 , V_22 -> V_34 ) ;
if ( V_40 < 0 )
return V_40 ;
V_39 = ( V_40 * 4 * 100 ) >> V_22 -> V_29 . V_30 ;
* V_4 = V_39 / 100000 ;
* V_27 = ( V_39 % 100000 ) * 10 ;
return V_43 ;
case V_44 :
* V_4 = - ( 1 << V_22 -> V_29 . V_30 ) / 2 ;
return V_41 ;
}
return - V_31 ;
}
static int T_1 F_21 ( struct V_45 * V_11 )
{
enum V_46 type = F_22 ( V_11 ) -> V_47 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
V_2 = F_23 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_24 ( & V_11 -> V_48 , L_1 ) ;
return - V_49 ;
}
V_6 = F_2 ( V_2 ) ;
F_25 ( V_11 , V_2 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_35 = & V_50 [ type ] ;
V_2 -> V_48 . V_51 = & V_11 -> V_48 ;
V_2 -> V_52 = F_22 ( V_11 ) -> V_52 ;
V_2 -> V_23 = & V_53 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = V_6 -> V_35 -> V_58 ;
if ( V_6 -> V_35 -> V_36 == 0 ) {
V_6 -> V_37 [ 0 ] . V_59 = L_2 ;
V_6 -> V_37 [ 1 ] . V_59 = L_3 ;
V_7 = F_26 ( & V_6 -> V_11 -> V_48 ,
F_27 ( V_6 -> V_37 ) , V_6 -> V_37 ) ;
if ( V_7 ) {
F_24 ( & V_11 -> V_48 , L_4 ,
V_7 ) ;
goto V_60;
}
V_7 = F_28 ( F_27 ( V_6 -> V_37 ) ,
V_6 -> V_37 ) ;
if ( V_7 ) {
F_24 ( & V_11 -> V_48 , L_5 ,
V_7 ) ;
goto V_61;
}
}
V_7 = F_29 ( V_2 ) ;
if ( V_7 ) {
F_24 ( & V_11 -> V_48 , L_6 , V_7 ) ;
goto V_62;
}
return 0 ;
V_62:
if ( V_6 -> V_35 -> V_36 == 0 )
F_30 ( F_27 ( V_6 -> V_37 ) , V_6 -> V_37 ) ;
V_61:
if ( V_6 -> V_35 -> V_36 == 0 )
F_31 ( F_27 ( V_6 -> V_37 ) , V_6 -> V_37 ) ;
V_60:
F_32 ( V_2 ) ;
return V_7 ;
}
static int T_2 F_33 ( struct V_45 * V_11 )
{
struct V_1 * V_2 = F_34 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( V_6 -> V_35 -> V_36 == 0 ) {
F_30 ( F_27 ( V_6 -> V_37 ) , V_6 -> V_37 ) ;
F_31 ( F_27 ( V_6 -> V_37 ) , V_6 -> V_37 ) ;
}
F_32 ( V_2 ) ;
return 0 ;
}
static int T_3 F_36 ( void )
{
return F_37 ( & V_63 ) ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_63 ) ;
}
