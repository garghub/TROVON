static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 1 ] . V_13 ) ;
V_10 = V_8 -> V_10 ;
if ( V_4 -> V_14 != V_10 -> V_14 )
return 0 ;
switch ( V_6 ) {
case V_15 :
V_11 = F_3 ( V_10 , V_16 ,
32768 , V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_10 , V_18 ,
0 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_5 ( L_1 ) ;
return V_11 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 1 ] . V_13 ) ;
V_10 = V_8 -> V_10 ;
if ( V_4 -> V_14 != V_10 -> V_14 )
return 0 ;
switch ( V_6 ) {
case V_19 :
if ( V_2 -> V_4 . V_20 == V_15 ) {
V_11 = F_4 ( V_10 , 0 ,
V_18 ,
32768 , V_21 ) ;
if ( V_11 < 0 ) {
F_5 ( L_2 ) ;
return V_11 ;
}
V_11 = F_3 ( V_10 ,
V_22 ,
V_21 ,
V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
}
break;
default:
break;
}
V_2 -> V_4 . V_20 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_23 * V_24 ,
struct V_23 * V_25 )
{
if ( V_26 && ( strcmp ( V_24 -> V_13 , L_3 ) == 0 ) )
return 1 ;
if ( ! V_26 && ( strcmp ( V_24 -> V_13 , L_4 ) == 0 ) )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_27 * V_28 ,
int V_29 )
{
V_26 = ! V_29 ;
F_9 ( V_30 , V_26 ) ;
F_10 ( F_11 ( V_28 ) ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_31 = V_8 -> V_10 ;
int V_11 ;
V_11 = F_3 ( V_31 , 0 , V_21 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_9 * V_31 = V_8 -> V_10 ;
struct V_27 * V_28 = V_8 -> V_28 ;
int V_11 ;
V_11 = F_3 ( V_31 , V_16 , 32768 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_14 ( V_30 , L_5 ) ;
if ( V_11 != 0 )
F_5 ( L_6 , V_11 ) ;
F_9 ( V_30 , V_26 ) ;
V_11 = F_15 ( V_8 -> V_2 , L_7 , V_32 |
V_33 | V_34 ,
& V_35 , V_36 ,
F_16 ( V_36 ) ) ;
if ( V_11 )
return V_11 ;
F_17 ( V_28 , & V_35 , F_8 ) ;
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
static int F_20 ( struct V_37 * V_38 )
{
struct V_27 * V_28 = F_21 ( V_38 ) ;
return F_22 ( V_28 , V_39 , 0 ,
V_21 , 0 ) ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = & V_42 ;
int V_11 ;
V_2 -> V_14 = & V_41 -> V_14 ;
V_11 = F_24 ( & V_41 -> V_14 , V_2 ) ;
if ( V_11 )
F_25 ( & V_41 -> V_14 , L_15 ,
V_11 ) ;
return V_11 ;
}
