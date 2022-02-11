static void F_1 ( struct V_1 * V_2 )
{
if ( V_3 == V_4 ) {
F_2 ( & V_5 . V_6 ,
V_7 , 1 ) ;
F_2 ( & V_5 . V_6 ,
V_8 , 1 ) ;
F_3 ( V_2 , L_1 ) ;
} else {
F_2 ( & V_5 . V_6 ,
V_7 , 0 ) ;
F_2 ( & V_5 . V_6 ,
V_8 , 0 ) ;
F_4 ( V_2 , L_1 ) ;
}
if ( V_9 == V_10 )
F_3 ( V_2 , L_2 ) ;
else
F_4 ( V_2 , L_2 ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
F_7 ( & V_17 -> V_18 ) ;
F_1 ( & V_17 -> V_2 ) ;
F_8 ( & V_17 -> V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_11 * V_12 )
{
F_2 ( & V_5 . V_6 ,
V_7 , 1 ) ;
F_2 ( & V_5 . V_6 ,
V_8 , 1 ) ;
}
static int F_10 ( struct V_11 * V_12 ,
struct V_19 * V_20 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_21 * V_22 = V_14 -> V_22 ;
struct V_21 * V_23 = V_14 -> V_23 ;
unsigned int V_24 = 0 ;
int V_25 = 0 ;
switch ( F_11 ( V_20 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_24 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_24 = 11289600 ;
break;
}
V_25 = F_12 ( V_22 , V_26 , V_24 ,
V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_12 ( V_23 , V_28 , 0 ,
V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> V_33 . integer . V_33 [ 0 ] = V_3 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_34 * V_35 = F_15 ( V_30 ) ;
if ( V_3 == V_32 -> V_33 . integer . V_33 [ 0 ] )
return 0 ;
V_3 = V_32 -> V_33 . integer . V_33 [ 0 ] ;
F_1 ( & V_35 -> V_2 ) ;
return 1 ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> V_33 . integer . V_33 [ 0 ] = V_9 ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_34 * V_35 = F_15 ( V_30 ) ;
if ( V_9 == V_32 -> V_33 . integer . V_33 [ 0 ] )
return 0 ;
V_9 = V_32 -> V_33 . integer . V_33 [ 0 ] ;
F_1 ( & V_35 -> V_2 ) ;
return 1 ;
}
static int F_18 ( struct V_36 * V_37 ,
struct V_29 * V_38 , int V_39 )
{
if ( F_19 ( V_39 ) )
F_2 ( & V_5 . V_6 ,
V_40 , 0 ) ;
else
F_2 ( & V_5 . V_6 ,
V_40 , 1 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_1 * V_2 = & V_17 -> V_2 ;
F_21 ( V_2 , L_3 ) ;
F_21 ( V_2 , L_4 ) ;
F_3 ( V_2 , L_5 ) ;
return 0 ;
}
static int T_1 F_22 ( struct V_41 * V_42 )
{
struct V_34 * V_35 = & V_43 ;
int V_25 ;
F_23 ( & V_5 . V_6 ,
V_40 , 0 ) ;
F_23 ( & V_5 . V_6 ,
V_7 , 0 ) ;
F_23 ( & V_5 . V_6 ,
V_8 , 0 ) ;
V_35 -> V_6 = & V_42 -> V_6 ;
V_25 = F_24 ( V_35 ) ;
if ( V_25 )
F_25 ( & V_42 -> V_6 , L_6 ,
V_25 ) ;
return V_25 ;
}
static int T_2 F_26 ( struct V_41 * V_42 )
{
struct V_34 * V_35 = F_27 ( V_42 ) ;
F_28 ( V_35 ) ;
return 0 ;
}
