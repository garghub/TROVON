static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = 12 ;
if ( V_4 -> type == V_9 && V_4 -> V_10 == V_11 )
V_8 = 13 ;
else
V_8 = 12 ;
* V_5 = F_3 ( V_7 -> V_12 , V_4 -> V_13 , V_8 ) ;
if ( * V_5 < 0 )
return * V_5 ;
return V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( V_4 -> type == V_9 && V_4 -> V_10 == V_15 )
V_8 = 13 ;
else
V_8 = 12 ;
* V_5 = F_3 ( V_7 -> V_12 , V_4 -> V_13 , V_8 ) ;
if ( * V_5 < 0 )
return * V_5 ;
return V_14 ;
}
static int F_5 ( int V_10 , int * V_5 , int * V_16 )
{
switch ( V_10 ) {
case V_17 :
case V_18 :
* V_5 = 1 ;
* V_16 = 700000 ;
return V_19 ;
case V_20 :
case V_21 :
* V_5 = 0 ;
* V_16 = 500000 ;
return V_19 ;
case V_22 :
* V_5 = 1 ;
* V_16 = 100000 ;
return V_19 ;
case V_23 :
* V_5 = 1 ;
* V_16 = 400000 ;
return V_19 ;
default:
return - V_24 ;
}
}
static int F_6 ( int V_10 , int * V_5 , int * V_16 )
{
switch ( V_10 ) {
case V_25 :
* V_5 = 0 ;
* V_16 = 625000 ;
return V_19 ;
case V_26 :
* V_5 = 0 ;
* V_16 = 375000 ;
return V_19 ;
case V_11 :
case V_27 :
* V_5 = 0 ;
* V_16 = 500000 ;
return V_19 ;
default:
return - V_24 ;
}
}
static int F_7 ( struct V_3 const * V_4 , int * V_5 ,
int * V_16 )
{
switch ( V_4 -> type ) {
case V_28 :
return F_5 ( V_4 -> V_10 , V_5 , V_16 ) ;
case V_9 :
return F_6 ( V_4 -> V_10 , V_5 , V_16 ) ;
case V_29 :
* V_5 = 100 ;
return V_14 ;
default:
return - V_24 ;
}
}
static int F_8 ( struct V_3 const * V_4 , int * V_5 ,
int * V_16 )
{
switch ( V_4 -> type ) {
case V_28 :
if ( V_4 -> V_10 != V_30 )
return - V_24 ;
* V_5 = 1 ;
* V_16 = 100000 ;
return V_19 ;
case V_9 :
* V_5 = 0 ;
* V_16 = 500000 ;
return V_19 ;
case V_29 :
* V_5 = 100 ;
return V_14 ;
default:
return - V_24 ;
}
}
static int F_9 ( struct V_1 * V_2 , int V_10 ,
int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_31 ;
V_31 = F_10 ( V_7 -> V_12 , V_32 , V_5 ) ;
if ( V_31 < 0 )
return V_31 ;
switch ( V_10 ) {
case V_20 :
* V_5 &= V_33 ;
break;
case V_21 :
* V_5 &= V_34 ;
break;
default:
return - V_24 ;
}
* V_5 = ! ! ( * V_5 ) * 700000 ;
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 )
{
switch ( V_4 -> type ) {
case V_28 :
return F_9 ( V_2 , V_4 -> V_10 , V_5 ) ;
case V_29 :
* V_5 = - 1447 ;
return V_14 ;
default:
return - V_24 ;
}
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_16 , long V_35 )
{
switch ( V_35 ) {
case V_36 :
return F_11 ( V_2 , V_4 , V_5 ) ;
case V_37 :
return F_7 ( V_4 , V_5 , V_16 ) ;
case V_38 :
return F_1 ( V_2 , V_4 , V_5 ) ;
default:
return - V_24 ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_16 , long V_35 )
{
switch ( V_35 ) {
case V_36 :
* V_5 = - 2677 ;
return V_14 ;
case V_37 :
return F_8 ( V_4 , V_5 , V_16 ) ;
case V_38 :
return F_4 ( V_2 , V_4 , V_5 ) ;
default:
return - V_24 ;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int V_5 , int V_16 ,
long V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_39 , V_40 ;
if ( V_35 != V_36 )
return - V_24 ;
if ( V_5 != 0 && V_5 != 700000 )
return - V_24 ;
switch ( V_4 -> V_10 ) {
case V_20 :
V_39 = V_33 ;
V_40 = F_15 ( ! ! V_5 ) ;
break;
case V_21 :
V_39 = V_34 ;
V_40 = F_16 ( ! ! V_5 ) ;
break;
default:
return - V_24 ;
}
return F_17 ( V_7 -> V_12 , V_32 , V_39 ,
V_40 ) ;
}
static int F_18 ( int V_41 )
{
return F_19 ( V_41 ) ;
}
static int F_20 ( int V_41 )
{
return F_21 ( V_41 ) ;
}
static int F_22 ( struct V_42 * V_43 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_44 * V_44 ;
int V_31 ;
V_44 = F_23 ( V_43 -> V_45 . V_46 ) ;
V_2 = F_24 ( & V_43 -> V_45 , sizeof( * V_7 ) ) ;
if ( ! V_2 )
return - V_47 ;
V_7 = F_2 ( V_2 ) ;
F_25 ( V_43 , V_2 ) ;
V_7 -> V_12 = V_44 -> V_12 ;
V_2 -> V_45 . V_46 = & V_43 -> V_45 ;
V_2 -> V_45 . V_48 = V_43 -> V_45 . V_48 ;
V_2 -> V_49 = V_50 ;
V_7 -> V_51 = (struct V_52 * ) F_26 ( V_43 ) -> V_53 ;
V_2 -> V_54 = F_26 ( V_43 ) -> V_54 ;
V_2 -> V_7 = V_7 -> V_51 -> V_55 ;
V_2 -> V_56 = V_7 -> V_51 -> V_56 ;
V_2 -> V_57 = V_7 -> V_51 -> V_57 ;
F_27 ( V_7 -> V_12 , V_58 , V_7 -> V_51 -> V_59 ) ;
if ( V_7 -> V_51 -> V_60 )
F_17 ( V_7 -> V_12 , V_61 ,
V_62 , V_62 ) ;
F_17 ( V_7 -> V_12 , V_63 , V_64 ,
V_7 -> V_51 -> V_65 ( 100 ) ) ;
V_31 = F_28 ( V_2 , V_7 -> V_51 -> V_66 ) ;
if ( V_31 < 0 ) {
F_29 ( & V_43 -> V_45 , L_1 , V_31 ) ;
goto V_67;
}
V_31 = F_30 ( V_2 ) ;
if ( V_31 < 0 ) {
F_29 ( & V_43 -> V_45 , L_2 ) ;
goto V_68;
}
return 0 ;
V_68:
F_31 ( V_2 ) ;
V_67:
F_27 ( V_7 -> V_12 , V_58 , 0 ) ;
if ( V_7 -> V_51 -> V_60 )
F_27 ( V_7 -> V_12 , V_61 , 0 ) ;
return V_31 ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_33 ( V_43 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_34 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( V_7 -> V_12 , V_58 , 0 ) ;
if ( V_7 -> V_51 -> V_60 )
F_27 ( V_7 -> V_12 , V_61 , 0 ) ;
return 0 ;
}
