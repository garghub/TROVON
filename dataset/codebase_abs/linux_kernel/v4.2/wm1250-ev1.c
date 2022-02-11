static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_8 ;
if ( V_6 )
V_8 = V_6 -> V_9 [ V_10 ] . V_11 ;
else
V_8 = - 1 ;
switch ( V_4 ) {
case V_12 :
break;
case V_13 :
break;
case V_14 :
if ( V_8 >= 0 )
F_3 ( V_8 , 1 ) ;
break;
case V_15 :
if ( V_8 >= 0 )
F_3 ( V_8 , 0 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_5 * V_6 = F_5 ( V_21 -> V_2 ) ;
switch ( F_6 ( V_19 ) ) {
case 8000 :
F_7 ( V_6 -> V_9 [ V_22 ] . V_11 ,
1 ) ;
F_7 ( V_6 -> V_9 [ V_23 ] . V_11 ,
1 ) ;
break;
case 16000 :
F_7 ( V_6 -> V_9 [ V_22 ] . V_11 ,
0 ) ;
F_7 ( V_6 -> V_9 [ V_23 ] . V_11 ,
1 ) ;
break;
case 32000 :
F_7 ( V_6 -> V_9 [ V_22 ] . V_11 ,
1 ) ;
F_7 ( V_6 -> V_9 [ V_23 ] . V_11 ,
0 ) ;
break;
case 64000 :
F_7 ( V_6 -> V_9 [ V_22 ] . V_11 ,
0 ) ;
F_7 ( V_6 -> V_9 [ V_23 ] . V_11 ,
0 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static int F_8 ( struct V_25 * V_26 )
{
struct F_8 * V_27 = F_9 ( & V_26 -> V_7 ) ;
struct V_5 * V_6 ;
int V_28 , V_29 ;
if ( ! V_27 )
return 0 ;
V_6 = F_10 ( & V_26 -> V_7 , sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 ) {
V_29 = - V_31 ;
goto V_32;
}
for ( V_28 = 0 ; V_28 < F_11 ( V_6 -> V_9 ) ; V_28 ++ ) {
V_6 -> V_9 [ V_28 ] . V_11 = V_27 -> V_9 [ V_28 ] ;
V_6 -> V_9 [ V_28 ] . V_33 = V_34 [ V_28 ] ;
V_6 -> V_9 [ V_28 ] . V_35 = V_36 ;
}
V_6 -> V_9 [ V_22 ] . V_35 = V_37 ;
V_6 -> V_9 [ V_23 ] . V_35 = V_37 ;
V_29 = F_12 ( V_6 -> V_9 , F_11 ( V_6 -> V_9 ) ) ;
if ( V_29 != 0 ) {
F_13 ( & V_26 -> V_7 , L_1 , V_29 ) ;
goto V_32;
}
F_14 ( & V_26 -> V_7 , V_6 ) ;
return V_29 ;
V_32:
return V_29 ;
}
static void F_15 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_2 ( & V_26 -> V_7 ) ;
if ( V_6 )
F_16 ( V_6 -> V_9 , F_11 ( V_6 -> V_9 ) ) ;
}
static int F_17 ( struct V_25 * V_26 ,
const struct V_38 * V_39 )
{
int V_40 , V_41 , V_42 , V_29 ;
F_14 ( & V_26 -> V_7 , NULL ) ;
V_41 = F_18 ( V_26 , 0 ) ;
if ( V_41 < 0 ) {
F_13 ( & V_26 -> V_7 , L_2 , V_41 ) ;
return V_41 ;
}
V_40 = ( V_41 & 0xfe ) >> 2 ;
V_42 = V_41 & 0x3 ;
if ( V_40 != 1 ) {
F_13 ( & V_26 -> V_7 , L_3 , V_40 ) ;
return - V_43 ;
}
F_19 ( & V_26 -> V_7 , L_4 , V_42 + 1 ) ;
V_29 = F_8 ( V_26 ) ;
if ( V_29 != 0 )
return V_29 ;
V_29 = F_20 ( & V_26 -> V_7 , & V_44 ,
& V_45 , 1 ) ;
if ( V_29 != 0 ) {
F_13 ( & V_26 -> V_7 , L_5 , V_29 ) ;
F_15 ( V_26 ) ;
return V_29 ;
}
return 0 ;
}
static int F_21 ( struct V_25 * V_26 )
{
F_22 ( & V_26 -> V_7 ) ;
F_15 ( V_26 ) ;
return 0 ;
}
