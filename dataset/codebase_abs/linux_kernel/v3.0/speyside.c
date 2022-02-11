static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 [ 0 ] . V_6 ;
int V_8 ;
switch ( V_4 ) {
case V_9 :
V_8 = F_2 ( V_6 , V_10 ,
32768 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_6 , V_12 ,
0 , 0 , 0 ) ;
if ( V_8 < 0 ) {
F_4 ( L_1 ) ;
return V_8 ;
}
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_7 = V_14 -> V_18 ;
struct V_5 * V_19 = V_7 -> V_19 ;
struct V_5 * V_6 = V_7 -> V_6 ;
int V_8 ;
V_8 = F_6 ( V_6 , V_20
| V_21
| V_22 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_19 , V_20
| V_21
| V_22 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_6 , 0 , V_12 ,
32768 , 256 * 48000 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_6 , V_23 ,
256 * 48000 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 ,
struct V_24 * V_26 )
{
if ( V_27 && ( strcmp ( V_25 -> V_28 , L_2 ) == 0 ) )
return 1 ;
if ( ! V_27 && ( strcmp ( V_25 -> V_28 , L_3 ) == 0 ) )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_29 * V_30 ,
int V_31 )
{
V_27 = ! V_31 ;
F_9 ( V_32 , V_27 ) ;
F_10 ( & V_30 -> V_33 ) ;
}
static int F_11 ( struct V_17 * V_7 )
{
struct V_5 * V_34 = V_7 -> V_6 ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_8 ;
V_8 = F_2 ( V_34 , V_10 , 32768 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_32 , L_4 ) ;
if ( V_8 != 0 )
F_4 ( L_5 , V_8 ) ;
F_9 ( V_32 , V_27 ) ;
V_8 = F_13 ( V_30 , L_6 ,
V_35 | V_36 ,
& V_37 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_14 ( & V_37 ,
F_15 ( V_38 ) ,
V_38 ) ;
if ( V_8 )
return V_8 ;
F_16 ( V_30 , & V_37 , F_8 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_33 , L_7 ) ;
F_18 ( & V_2 -> V_33 , L_8 ) ;
F_18 ( & V_2 -> V_33 , L_9 ) ;
F_18 ( & V_2 -> V_33 , L_10 ) ;
F_18 ( & V_2 -> V_33 , L_11 ) ;
F_18 ( & V_2 -> V_33 , L_12 ) ;
F_18 ( & V_2 -> V_33 , L_13 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_33 )
{
F_20 ( V_33 , L_14 ) ;
return F_21 ( V_33 -> V_30 , V_40 ,
48000 * 256 , 0 ) ;
}
static T_1 int F_22 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_43 ;
int V_8 ;
V_2 -> V_44 = & V_42 -> V_44 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 ) {
F_24 ( & V_42 -> V_44 , L_15 ,
V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_45 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_45 ) ;
}
