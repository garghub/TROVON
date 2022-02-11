static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
if ( ! V_8 -> V_9 ) {
F_3 ( V_6 -> V_10 ,
L_1 ) ;
return - V_11 ;
}
F_4 ( V_2 -> V_12 , 0 ,
V_13 ,
& V_8 -> V_14 ) ;
F_5 ( V_8 -> V_15 , 1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_5 ( V_8 -> V_15 , 0 ) ;
}
static int F_7 ( struct V_3 * V_16 ,
int V_17 , unsigned int V_18 , int V_19 )
{
struct V_5 * V_6 = V_16 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
unsigned int V_20 ;
int V_21 , V_22 = 0 ;
V_8 -> V_9 = V_18 ;
V_8 -> V_14 . V_23 = 0 ;
for ( V_21 = 0 ; V_21 < F_8 ( V_24 ) ; V_21 ++ ) {
V_20 = V_18 / V_24 [ V_21 ] . V_25 ;
switch ( V_20 ) {
case 8000 :
case 32000 :
case 44100 :
case 48000 :
case 88200 :
case 96000 :
case 176400 :
case 192000 :
F_9 ( V_6 -> V_10 , L_2 ,
V_20 ) ;
V_8 -> V_26 [ V_22 ++ ] = V_20 ;
V_8 -> V_14 . V_23 ++ ;
break;
default:
F_9 ( V_6 -> V_10 , L_3 ,
V_20 ) ;
}
}
if ( V_8 -> V_14 . V_23 == 0 )
return - V_11 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_16 , unsigned int V_27 )
{
V_27 &= ( V_28 | V_29 |
V_30 ) ;
if ( V_27 != ( V_31 | V_32 |
V_33 ) ) {
F_3 ( V_16 -> V_10 , L_4 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , int V_15 , int V_34 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_6 ) ;
if ( V_8 -> V_15 )
F_5 ( V_8 -> V_15 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
V_8 -> V_14 . V_35 = & V_8 -> V_26 [ 0 ] ;
V_8 -> V_14 . V_23 =
F_8 ( V_8 -> V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 )
{
struct V_7 * V_8 ;
int V_38 ;
V_8 = F_14 ( & V_37 -> V_10 , sizeof( struct V_7 ) ,
V_39 ) ;
if ( V_8 == NULL )
return - V_40 ;
F_15 ( V_37 , V_8 ) ;
V_8 -> V_15 = F_16 ( & V_37 -> V_10 , L_5 , V_41 ) ;
if ( F_17 ( V_8 -> V_15 ) ) {
V_38 = F_18 ( V_8 -> V_15 ) ;
F_3 ( & V_37 -> V_10 , L_6 , V_38 ) ;
return V_38 ;
}
V_38 = F_19 ( & V_37 -> V_10 ,
& V_42 , & V_43 , 1 ) ;
if ( V_38 < 0 )
F_3 ( & V_37 -> V_10 , L_7 , V_38 ) ;
return V_38 ;
}
static int F_20 ( struct V_36 * V_37 )
{
F_21 ( & V_37 -> V_10 ) ;
return 0 ;
}
