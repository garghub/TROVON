static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 1 ] . V_8 ;
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
struct V_7 * V_8 = V_2 -> V_9 [ 1 ] . V_8 ;
int V_10 ;
if ( V_4 -> V_11 != V_8 -> V_11 )
return 0 ;
switch ( V_6 ) {
case V_16 :
if ( V_2 -> V_4 . V_17 == V_12 ) {
V_10 = F_3 ( V_8 , 0 ,
V_15 ,
32768 , V_18 ) ;
if ( V_10 < 0 ) {
F_4 ( L_2 ) ;
return V_10 ;
}
V_10 = F_2 ( V_8 ,
V_19 ,
V_18 ,
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
static int F_6 ( struct V_20 * V_21 ,
struct V_20 * V_22 )
{
if ( V_23 && ( strcmp ( V_21 -> V_24 , L_3 ) == 0 ) )
return 1 ;
if ( ! V_23 && ( strcmp ( V_21 -> V_24 , L_4 ) == 0 ) )
return 1 ;
return 0 ;
}
static void F_7 ( struct V_25 * V_26 ,
int V_27 )
{
V_23 = ! V_27 ;
F_8 ( V_28 , V_23 ) ;
F_9 ( F_10 ( V_26 ) ) ;
}
static int F_11 ( struct V_29 * V_9 )
{
struct V_7 * V_30 = V_9 -> V_8 ;
int V_10 ;
V_10 = F_2 ( V_30 , 0 , V_18 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_12 ( struct V_29 * V_9 )
{
struct V_7 * V_30 = V_9 -> V_8 ;
struct V_25 * V_26 = V_9 -> V_26 ;
int V_10 ;
V_10 = F_2 ( V_30 , V_13 , 32768 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_13 ( V_28 , L_5 ) ;
if ( V_10 != 0 )
F_4 ( L_6 , V_10 ) ;
F_8 ( V_28 , V_23 ) ;
V_10 = F_14 ( V_9 -> V_2 , L_7 , V_31 |
V_32 | V_33 ,
& V_34 , V_35 ,
F_15 ( V_35 ) ) ;
if ( V_10 )
return V_10 ;
F_16 ( V_26 , & V_34 , F_7 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_4 , L_8 ) ;
F_18 ( & V_2 -> V_4 , L_9 ) ;
F_18 ( & V_2 -> V_4 , L_10 ) ;
F_18 ( & V_2 -> V_4 , L_11 ) ;
F_18 ( & V_2 -> V_4 , L_12 ) ;
F_18 ( & V_2 -> V_4 , L_13 ) ;
F_18 ( & V_2 -> V_4 , L_14 ) ;
return 0 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_25 * V_26 = F_20 ( V_37 ) ;
return F_21 ( V_26 , V_38 , 0 ,
V_18 , 0 ) ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = & V_41 ;
int V_10 ;
V_2 -> V_11 = & V_40 -> V_11 ;
V_10 = F_23 ( & V_40 -> V_11 , V_2 ) ;
if ( V_10 )
F_24 ( & V_40 -> V_11 , L_15 ,
V_10 ) ;
return V_10 ;
}
