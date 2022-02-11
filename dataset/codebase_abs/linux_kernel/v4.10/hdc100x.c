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
V_7 = F_15 ( V_25 ) ;
if ( V_7 ) {
F_16 ( & V_2 -> V_27 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 , V_10 ) ;
F_17 ( V_25 ) ;
if ( V_7 >= 0 ) {
* V_4 = V_7 ;
V_7 = V_29 ;
}
}
F_16 ( & V_2 -> V_27 ) ;
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
static int F_18 ( struct V_24 * V_25 ,
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
F_16 ( & V_2 -> V_27 ) ;
return V_7 ;
case V_26 :
if ( V_10 -> type != V_28 || V_11 != 0 )
return - V_14 ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_1 ( V_2 , V_23 ,
V_4 ? V_23 : 0 ) ;
F_16 ( & V_2 -> V_27 ) ;
return V_7 ;
default:
return - V_14 ;
}
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_7 ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_1 ( V_2 , V_36 ,
V_36 ) ;
F_16 ( & V_2 -> V_27 ) ;
if ( V_7 )
return V_7 ;
return F_20 ( V_25 ) ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_7 ;
V_7 = F_22 ( V_25 ) ;
if ( V_7 )
return V_7 ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_1 ( V_2 , V_36 , 0 ) ;
F_16 ( & V_2 -> V_27 ) ;
return V_7 ;
}
static T_2 F_23 ( int V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_24 * V_25 = V_40 -> V_25 ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
struct V_19 * V_8 = V_2 -> V_8 ;
int V_20 = V_2 -> V_17 [ 0 ] + V_2 -> V_17 [ 1 ] ;
int V_7 ;
T_3 V_41 [ 8 ] ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_6 ( V_8 , V_42 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_8 -> V_22 , L_3 ) ;
goto V_43;
}
F_8 ( V_20 , V_20 + 1000 ) ;
V_7 = F_9 ( V_8 , ( V_44 * ) V_41 , 4 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_8 -> V_22 , L_2 ) ;
goto V_43;
}
F_24 ( V_25 , V_41 ,
F_25 ( V_25 ) ) ;
V_43:
F_16 ( & V_2 -> V_27 ) ;
F_26 ( V_25 -> V_45 ) ;
return V_46 ;
}
static int F_27 ( struct V_19 * V_8 ,
const struct V_47 * V_48 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_7 ;
if ( ! F_28 ( V_8 -> V_49 , V_50 |
V_51 | V_52 ) )
return - V_53 ;
V_25 = F_29 ( & V_8 -> V_22 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_54 ;
V_2 = F_13 ( V_25 ) ;
F_30 ( V_8 , V_25 ) ;
V_2 -> V_8 = V_8 ;
F_31 ( & V_2 -> V_27 ) ;
V_25 -> V_22 . V_55 = & V_8 -> V_22 ;
V_25 -> V_56 = F_32 ( & V_8 -> V_22 ) ;
V_25 -> V_57 = V_58 ;
V_25 -> V_59 = & V_60 ;
V_25 -> V_61 = V_62 ;
V_25 -> V_63 = F_4 ( V_62 ) ;
V_25 -> V_64 = V_65 ;
F_3 ( V_2 , 0 , V_16 [ 0 ] [ 0 ] ) ;
F_3 ( V_2 , 1 , V_16 [ 1 ] [ 0 ] ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_7 = F_33 ( V_25 , NULL ,
F_23 ,
& V_66 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_8 -> V_22 , L_4 ) ;
return V_7 ;
}
V_7 = F_34 ( V_25 ) ;
if ( V_7 < 0 )
F_35 ( V_25 ) ;
return V_7 ;
}
static int F_36 ( struct V_19 * V_8 )
{
struct V_24 * V_25 = F_37 ( V_8 ) ;
F_38 ( V_25 ) ;
F_35 ( V_25 ) ;
return 0 ;
}
