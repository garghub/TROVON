static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = ( ~ V_3 & V_2 -> V_6 ) | V_4 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 ,
V_9 , V_5 ) ;
if ( ! V_7 )
V_2 -> V_6 = V_5 ;
return V_7 ;
}
static int F_3 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
int V_12 = V_13 [ V_10 ] . V_12 ;
int V_7 = - V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_4 ( V_16 [ V_10 ] ) ; V_15 ++ ) {
if ( V_11 && V_11 == V_16 [ V_10 ] [ V_15 ] ) {
V_7 = F_1 ( V_2 ,
V_13 [ V_10 ] . V_3 << V_12 ,
V_15 << V_12 ) ;
if ( ! V_7 )
V_2 -> V_17 [ V_10 ] = V_11 ;
break;
}
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_18 const * V_10 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
int V_20 = V_2 -> V_17 [ V_10 -> V_21 ] ;
int V_7 ;
T_1 V_4 ;
V_7 = F_6 ( V_8 , V_10 -> V_21 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_8 -> V_22 , L_1 ) ;
return V_7 ;
}
F_8 ( V_20 , V_20 + 1000 ) ;
V_7 = F_9 ( V_2 -> V_8 , ( char * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_7 < 0 ) {
F_7 ( & V_8 -> V_22 , L_2 ) ;
return V_7 ;
}
return F_10 ( V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_6 & V_23 ) ;
}
static int F_12 ( struct V_24 * V_25 ,
struct V_18 const * V_10 , int * V_4 ,
int * V_11 , long V_3 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
switch ( V_3 ) {
case V_26 : {
int V_7 ;
F_14 ( & V_2 -> V_27 ) ;
if ( V_10 -> type == V_28 ) {
* V_4 = F_11 ( V_2 ) ;
V_7 = V_29 ;
} else {
V_7 = F_5 ( V_2 , V_10 ) ;
if ( V_7 >= 0 ) {
* V_4 = V_7 ;
V_7 = V_29 ;
}
}
F_15 ( & V_2 -> V_27 ) ;
return V_7 ;
}
case V_30 :
* V_4 = 0 ;
* V_11 = V_2 -> V_17 [ V_10 -> V_21 ] ;
return V_31 ;
case V_32 :
if ( V_10 -> type == V_33 ) {
* V_4 = 165000 ;
* V_11 = 65536 ;
return V_34 ;
} else {
* V_4 = 100 ;
* V_11 = 65536 ;
return V_34 ;
}
break;
case V_35 :
* V_4 = - 15887 ;
* V_11 = 515151 ;
return V_31 ;
default:
return - V_14 ;
}
}
static int F_16 ( struct V_24 * V_25 ,
struct V_18 const * V_10 ,
int V_4 , int V_11 , long V_3 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_7 = - V_14 ;
switch ( V_3 ) {
case V_30 :
if ( V_4 != 0 )
return - V_14 ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_3 ( V_2 , V_10 -> V_21 , V_11 ) ;
F_15 ( & V_2 -> V_27 ) ;
return V_7 ;
case V_26 :
if ( V_10 -> type != V_28 || V_11 != 0 )
return - V_14 ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_1 ( V_2 , V_23 ,
V_4 ? V_23 : 0 ) ;
F_15 ( & V_2 -> V_27 ) ;
return V_7 ;
default:
return - V_14 ;
}
}
static int F_17 ( struct V_19 * V_8 ,
const struct V_36 * V_37 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
if ( ! F_18 ( V_8 -> V_38 , V_39 |
V_40 | V_41 ) )
return - V_42 ;
V_25 = F_19 ( & V_8 -> V_22 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_43 ;
V_2 = F_13 ( V_25 ) ;
F_20 ( V_8 , V_25 ) ;
V_2 -> V_8 = V_8 ;
F_21 ( & V_2 -> V_27 ) ;
V_25 -> V_22 . V_44 = & V_8 -> V_22 ;
V_25 -> V_45 = F_22 ( & V_8 -> V_22 ) ;
V_25 -> V_46 = V_47 ;
V_25 -> V_48 = & V_49 ;
V_25 -> V_50 = V_51 ;
V_25 -> V_52 = F_4 ( V_51 ) ;
F_3 ( V_2 , 0 , V_16 [ 0 ] [ 0 ] ) ;
F_3 ( V_2 , 1 , V_16 [ 1 ] [ 0 ] ) ;
return F_23 ( & V_8 -> V_22 , V_25 ) ;
}
