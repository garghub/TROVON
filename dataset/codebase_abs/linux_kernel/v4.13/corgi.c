static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_4 :
F_3 ( V_5 , 1 ) ;
F_3 ( V_6 , 1 ) ;
F_4 ( V_2 , L_1 ) ;
F_4 ( V_2 , L_2 ) ;
F_5 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_4 ) ;
break;
case V_7 :
F_3 ( V_5 , 0 ) ;
F_3 ( V_6 , 0 ) ;
F_5 ( V_2 , L_1 ) ;
F_4 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_4 ) ;
break;
case V_8 :
F_3 ( V_5 , 0 ) ;
F_3 ( V_6 , 0 ) ;
F_4 ( V_2 , L_1 ) ;
F_5 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_4 ) ;
break;
case V_9 :
F_3 ( V_5 , 0 ) ;
F_3 ( V_6 , 1 ) ;
F_5 ( V_2 , L_1 ) ;
F_4 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 ) ;
F_5 ( V_2 , L_4 ) ;
break;
}
if ( V_10 == V_11 )
F_5 ( V_2 , L_5 ) ;
else
F_4 ( V_2 , L_5 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
F_1 ( & V_15 -> V_17 -> V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_12 * V_13 )
{
F_3 ( V_5 , 1 ) ;
F_3 ( V_6 , 1 ) ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_20 * V_21 = V_15 -> V_21 ;
struct V_20 * V_22 = V_15 -> V_22 ;
unsigned int V_23 = 0 ;
int V_24 = 0 ;
switch ( F_11 ( V_19 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_23 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_23 = 11289600 ;
break;
}
V_24 = F_12 ( V_21 , V_25 , V_23 ,
V_26 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_12 ( V_22 , V_27 , 0 ,
V_26 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . V_33 . V_34 [ 0 ] = V_3 ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_35 * V_17 = F_15 ( V_29 ) ;
if ( V_3 == V_31 -> V_32 . V_33 . V_34 [ 0 ] )
return 0 ;
V_3 = V_31 -> V_32 . V_33 . V_34 [ 0 ] ;
F_1 ( & V_17 -> V_2 ) ;
return 1 ;
}
static int F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_31 -> V_32 . V_33 . V_34 [ 0 ] = V_10 ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_35 * V_17 = F_15 ( V_29 ) ;
if ( V_10 == V_31 -> V_32 . V_33 . V_34 [ 0 ] )
return 0 ;
V_10 = V_31 -> V_32 . V_33 . V_34 [ 0 ] ;
F_1 ( & V_17 -> V_2 ) ;
return 1 ;
}
static int F_18 ( struct V_36 * V_37 ,
struct V_28 * V_38 , int V_39 )
{
F_3 ( V_40 , F_19 ( V_39 ) ) ;
return 0 ;
}
static int F_20 ( struct V_36 * V_37 ,
struct V_28 * V_38 , int V_39 )
{
F_3 ( V_41 , F_19 ( V_39 ) ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_43 )
{
struct V_35 * V_17 = & V_44 ;
int V_24 ;
V_17 -> V_45 = & V_43 -> V_45 ;
V_24 = F_22 ( & V_43 -> V_45 , V_17 ) ;
if ( V_24 )
F_23 ( & V_43 -> V_45 , L_6 ,
V_24 ) ;
return V_24 ;
}
