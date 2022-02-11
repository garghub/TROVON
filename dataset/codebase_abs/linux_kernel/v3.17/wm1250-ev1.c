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
V_2 -> V_16 . V_17 = V_4 ;
return 0 ;
}
static int F_4 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_5 ( V_23 -> V_2 ) ;
switch ( F_6 ( V_21 ) ) {
case 8000 :
F_7 ( V_6 -> V_9 [ V_24 ] . V_11 ,
1 ) ;
F_7 ( V_6 -> V_9 [ V_25 ] . V_11 ,
1 ) ;
break;
case 16000 :
F_7 ( V_6 -> V_9 [ V_24 ] . V_11 ,
0 ) ;
F_7 ( V_6 -> V_9 [ V_25 ] . V_11 ,
1 ) ;
break;
case 32000 :
F_7 ( V_6 -> V_9 [ V_24 ] . V_11 ,
1 ) ;
F_7 ( V_6 -> V_9 [ V_25 ] . V_11 ,
0 ) ;
break;
case 64000 :
F_7 ( V_6 -> V_9 [ V_24 ] . V_11 ,
0 ) ;
F_7 ( V_6 -> V_9 [ V_25 ] . V_11 ,
0 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_8 ( struct V_27 * V_28 )
{
struct F_8 * V_29 = F_9 ( & V_28 -> V_7 ) ;
struct V_5 * V_6 ;
int V_30 , V_31 ;
if ( ! V_29 )
return 0 ;
V_6 = F_10 ( & V_28 -> V_7 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 ) {
V_31 = - V_33 ;
goto V_34;
}
for ( V_30 = 0 ; V_30 < F_11 ( V_6 -> V_9 ) ; V_30 ++ ) {
V_6 -> V_9 [ V_30 ] . V_11 = V_29 -> V_9 [ V_30 ] ;
V_6 -> V_9 [ V_30 ] . V_35 = V_36 [ V_30 ] ;
V_6 -> V_9 [ V_30 ] . V_37 = V_38 ;
}
V_6 -> V_9 [ V_24 ] . V_37 = V_39 ;
V_6 -> V_9 [ V_25 ] . V_37 = V_39 ;
V_31 = F_12 ( V_6 -> V_9 , F_11 ( V_6 -> V_9 ) ) ;
if ( V_31 != 0 ) {
F_13 ( & V_28 -> V_7 , L_1 , V_31 ) ;
goto V_34;
}
F_14 ( & V_28 -> V_7 , V_6 ) ;
return V_31 ;
V_34:
return V_31 ;
}
static void F_15 ( struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( & V_28 -> V_7 ) ;
if ( V_6 )
F_16 ( V_6 -> V_9 , F_11 ( V_6 -> V_9 ) ) ;
}
static int F_17 ( struct V_27 * V_28 ,
const struct V_40 * V_41 )
{
int V_42 , V_43 , V_44 , V_31 ;
F_14 ( & V_28 -> V_7 , NULL ) ;
V_43 = F_18 ( V_28 , 0 ) ;
if ( V_43 < 0 ) {
F_13 ( & V_28 -> V_7 , L_2 , V_43 ) ;
return V_43 ;
}
V_42 = ( V_43 & 0xfe ) >> 2 ;
V_44 = V_43 & 0x3 ;
if ( V_42 != 1 ) {
F_13 ( & V_28 -> V_7 , L_3 , V_42 ) ;
return - V_45 ;
}
F_19 ( & V_28 -> V_7 , L_4 , V_44 + 1 ) ;
V_31 = F_8 ( V_28 ) ;
if ( V_31 != 0 )
return V_31 ;
V_31 = F_20 ( & V_28 -> V_7 , & V_46 ,
& V_47 , 1 ) ;
if ( V_31 != 0 ) {
F_13 ( & V_28 -> V_7 , L_5 , V_31 ) ;
F_15 ( V_28 ) ;
return V_31 ;
}
return 0 ;
}
static int F_21 ( struct V_27 * V_28 )
{
F_22 ( & V_28 -> V_7 ) ;
F_15 ( V_28 ) ;
return 0 ;
}
