static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_5 == V_6 ) {
F_2 ( & V_7 . V_8 ,
V_9 , 1 ) ;
F_2 ( & V_7 . V_8 ,
V_10 , 1 ) ;
F_3 ( V_4 , L_1 ) ;
} else {
F_2 ( & V_7 . V_8 ,
V_9 , 0 ) ;
F_2 ( & V_7 . V_8 ,
V_10 , 0 ) ;
F_4 ( V_4 , L_1 ) ;
}
if ( V_11 == V_12 )
F_3 ( V_4 , L_2 ) ;
else
F_4 ( V_4 , L_2 ) ;
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_7 ( & V_2 -> V_18 ) ;
F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_13 * V_14 )
{
F_2 ( & V_7 . V_8 ,
V_9 , 1 ) ;
F_2 ( & V_7 . V_8 ,
V_10 , 1 ) ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_19 * V_20 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_21 * V_22 = V_16 -> V_22 ;
struct V_21 * V_23 = V_16 -> V_23 ;
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
V_32 -> V_33 . integer . V_33 [ 0 ] = V_5 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_30 ) ;
if ( V_5 == V_32 -> V_33 . integer . V_33 [ 0 ] )
return 0 ;
V_5 = V_32 -> V_33 . integer . V_33 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> V_33 . integer . V_33 [ 0 ] = V_11 ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_30 ) ;
if ( V_11 == V_32 -> V_33 . integer . V_33 [ 0 ] )
return 0 ;
V_11 = V_32 -> V_33 . integer . V_33 [ 0 ] ;
F_1 ( V_2 ) ;
return 1 ;
}
static int F_18 ( struct V_34 * V_35 ,
struct V_29 * V_36 , int V_37 )
{
if ( F_19 ( V_37 ) )
F_2 ( & V_7 . V_8 ,
V_38 , 0 ) ;
else
F_2 ( & V_7 . V_8 ,
V_38 , 1 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
F_21 ( V_4 , L_3 ) ;
F_21 ( V_4 , L_4 ) ;
F_3 ( V_4 , L_5 ) ;
return 0 ;
}
static int T_1 F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_43 ;
int V_25 ;
F_23 ( & V_7 . V_8 ,
V_38 , 0 ) ;
F_23 ( & V_7 . V_8 ,
V_9 , 0 ) ;
F_23 ( & V_7 . V_8 ,
V_10 , 0 ) ;
V_42 -> V_8 = & V_40 -> V_8 ;
V_25 = F_24 ( V_42 ) ;
if ( V_25 )
F_25 ( & V_40 -> V_8 , L_6 ,
V_25 ) ;
return V_25 ;
}
static int T_2 F_26 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_27 ( V_40 ) ;
F_28 ( V_42 ) ;
return 0 ;
}
