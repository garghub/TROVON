static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
int V_10 ;
if ( V_4 -> V_11 != V_8 -> V_11 )
return 0 ;
switch ( V_6 ) {
case V_12 :
V_10 = F_2 ( V_8 , V_13 ,
32768 , V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_8 , V_15 ,
0 , 0 , 0 ) ;
if ( V_10 < 0 ) {
F_4 ( L_1 ) ;
return V_10 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
int V_10 ;
if ( V_4 -> V_11 != V_8 -> V_11 )
return 0 ;
switch ( V_6 ) {
case V_16 :
if ( V_2 -> V_4 . V_17 == V_12 ) {
V_10 = F_3 ( V_8 , 0 ,
V_15 ,
32768 , 48000 * 256 ) ;
if ( V_10 < 0 ) {
F_4 ( L_2 ) ;
return V_10 ;
}
V_10 = F_2 ( V_8 ,
V_18 ,
48000 * 256 ,
V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
}
break;
default:
break;
}
V_2 -> V_4 . V_17 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_9 = V_20 -> V_24 ;
struct V_7 * V_25 = V_9 -> V_25 ;
struct V_7 * V_8 = V_9 -> V_8 ;
int V_10 ;
V_10 = F_7 ( V_8 , V_26
| V_27
| V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_25 , V_26
| V_27
| V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_8 ( struct V_29 * V_30 ,
struct V_29 * V_31 )
{
if ( V_32 && ( strcmp ( V_30 -> V_33 , L_3 ) == 0 ) )
return 1 ;
if ( ! V_32 && ( strcmp ( V_30 -> V_33 , L_4 ) == 0 ) )
return 1 ;
return 0 ;
}
static void F_9 ( struct V_34 * V_35 ,
int V_36 )
{
V_32 = ! V_36 ;
F_10 ( V_37 , V_32 ) ;
F_11 ( & V_35 -> V_4 ) ;
}
static int F_12 ( struct V_23 * V_9 )
{
struct V_7 * V_38 = V_9 -> V_8 ;
struct V_34 * V_35 = V_9 -> V_35 ;
int V_10 ;
V_10 = F_2 ( V_38 , V_13 , 32768 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_13 ( V_37 , L_5 ) ;
if ( V_10 != 0 )
F_4 ( L_6 , V_10 ) ;
F_10 ( V_37 , V_32 ) ;
V_10 = F_14 ( V_35 , L_7 ,
V_39 | V_40 |
V_41 ,
& V_42 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_15 ( & V_42 ,
F_16 ( V_43 ) ,
V_43 ) ;
if ( V_10 )
return V_10 ;
F_17 ( V_35 , & V_42 , F_9 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_4 , L_8 ) ;
F_19 ( & V_2 -> V_4 , L_9 ) ;
F_19 ( & V_2 -> V_4 , L_10 ) ;
F_19 ( & V_2 -> V_4 , L_11 ) ;
F_19 ( & V_2 -> V_4 , L_12 ) ;
F_19 ( & V_2 -> V_4 , L_13 ) ;
F_19 ( & V_2 -> V_4 , L_14 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 , L_15 ) ;
return F_22 ( V_4 -> V_35 , V_44 , 0 ,
48000 * 256 , 0 ) ;
}
static T_1 int F_23 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = & V_47 ;
int V_10 ;
V_2 -> V_11 = & V_46 -> V_11 ;
V_10 = F_24 ( V_2 ) ;
if ( V_10 ) {
F_25 ( & V_46 -> V_11 , L_16 ,
V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int T_2 F_26 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_27 ( V_46 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_48 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_48 ) ;
}
