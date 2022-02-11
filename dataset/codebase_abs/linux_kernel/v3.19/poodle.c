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
F_1 ( & V_14 -> V_16 -> V_2 ) ;
return 0 ;
}
static void F_7 ( struct V_11 * V_12 )
{
F_2 ( & V_5 . V_6 ,
V_7 , 1 ) ;
F_2 ( & V_5 . V_6 ,
V_8 , 1 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_17 * V_18 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_19 * V_21 = V_14 -> V_21 ;
unsigned int V_22 = 0 ;
int V_23 = 0 ;
switch ( F_9 ( V_18 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_22 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_22 = 11289600 ;
break;
}
V_23 = F_10 ( V_20 , V_24 , V_22 ,
V_25 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_10 ( V_21 , V_26 , 0 ,
V_25 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . integer . V_31 [ 0 ] = V_3 ;
return 0 ;
}
static int F_12 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_32 * V_16 = F_13 ( V_28 ) ;
if ( V_3 == V_30 -> V_31 . integer . V_31 [ 0 ] )
return 0 ;
V_3 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
F_1 ( & V_16 -> V_2 ) ;
return 1 ;
}
static int F_14 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . integer . V_31 [ 0 ] = V_9 ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_32 * V_16 = F_13 ( V_28 ) ;
if ( V_9 == V_30 -> V_31 . integer . V_31 [ 0 ] )
return 0 ;
V_9 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
F_1 ( & V_16 -> V_2 ) ;
return 1 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_27 * V_35 , int V_36 )
{
if ( F_17 ( V_36 ) )
F_2 ( & V_5 . V_6 ,
V_37 , 0 ) ;
else
F_2 ( & V_5 . V_6 ,
V_37 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 )
{
struct V_38 * V_39 = V_14 -> V_39 ;
struct V_1 * V_2 = & V_39 -> V_2 ;
F_19 ( V_2 , L_3 ) ;
F_19 ( V_2 , L_4 ) ;
return 0 ;
}
static int F_20 ( struct V_40 * V_41 )
{
struct V_32 * V_16 = & V_42 ;
int V_23 ;
F_21 ( & V_5 . V_6 ,
V_37 , 0 ) ;
F_21 ( & V_5 . V_6 ,
V_7 , 0 ) ;
F_21 ( & V_5 . V_6 ,
V_8 , 0 ) ;
V_16 -> V_6 = & V_41 -> V_6 ;
V_23 = F_22 ( V_16 ) ;
if ( V_23 )
F_23 ( & V_41 -> V_6 , L_5 ,
V_23 ) ;
return V_23 ;
}
static int F_24 ( struct V_40 * V_41 )
{
struct V_32 * V_16 = F_25 ( V_41 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
