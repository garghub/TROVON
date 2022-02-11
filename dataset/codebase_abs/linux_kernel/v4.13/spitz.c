static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
if ( V_3 == V_4 )
F_3 ( V_2 , L_1 ) ;
else
F_4 ( V_2 , L_1 ) ;
switch ( V_5 ) {
case V_6 :
F_4 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_4 ) ;
F_3 ( V_2 , L_5 ) ;
F_5 ( V_7 , 1 ) ;
F_5 ( V_8 , 1 ) ;
break;
case V_9 :
F_4 ( V_2 , L_5 ) ;
F_4 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_4 ) ;
F_3 ( V_2 , L_3 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 0 ) ;
break;
case V_10 :
F_4 ( V_2 , L_5 ) ;
F_4 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 ) ;
F_3 ( V_2 , L_4 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 0 ) ;
break;
case V_11 :
F_4 ( V_2 , L_5 ) ;
F_3 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_4 ) ;
F_3 ( V_2 , L_2 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 1 ) ;
break;
case V_12 :
F_4 ( V_2 , L_5 ) ;
F_4 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_4 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 0 ) ;
break;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
F_1 ( & V_16 -> V_18 -> V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_19 * V_20 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_21 * V_22 = V_16 -> V_22 ;
struct V_21 * V_23 = V_16 -> V_23 ;
unsigned int V_24 = 0 ;
int V_25 = 0 ;
switch ( F_10 ( V_20 ) ) {
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
V_25 = F_11 ( V_22 , V_26 , V_24 ,
V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_11 ( V_23 , V_28 , 0 ,
V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_12 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> V_33 . V_34 . V_35 [ 0 ] = V_5 ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_36 * V_18 = F_14 ( V_30 ) ;
if ( V_5 == V_32 -> V_33 . V_34 . V_35 [ 0 ] )
return 0 ;
V_5 = V_32 -> V_33 . V_34 . V_35 [ 0 ] ;
F_1 ( & V_18 -> V_2 ) ;
return 1 ;
}
static int F_15 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> V_33 . V_34 . V_35 [ 0 ] = V_3 ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_36 * V_18 = F_14 ( V_30 ) ;
if ( V_3 == V_32 -> V_33 . V_34 . V_35 [ 0 ] )
return 0 ;
V_3 = V_32 -> V_33 . V_34 . V_35 [ 0 ] ;
F_1 ( & V_18 -> V_2 ) ;
return 1 ;
}
static int F_17 ( struct V_37 * V_38 ,
struct V_29 * V_39 , int V_40 )
{
F_18 ( V_41 , F_19 ( V_40 ) ) ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_36 * V_18 = & V_44 ;
int V_25 ;
if ( F_21 () )
V_41 = V_45 ;
else
V_41 = V_46 ;
V_25 = F_22 ( V_41 , L_6 ) ;
if ( V_25 )
goto V_47;
V_25 = F_23 ( V_41 , 0 ) ;
if ( V_25 )
goto V_48;
V_18 -> V_49 = & V_43 -> V_49 ;
V_25 = F_24 ( & V_43 -> V_49 , V_18 ) ;
if ( V_25 ) {
F_25 ( & V_43 -> V_49 , L_7 ,
V_25 ) ;
goto V_48;
}
return 0 ;
V_48:
F_26 ( V_41 ) ;
V_47:
return V_25 ;
}
static int F_27 ( struct V_42 * V_43 )
{
F_26 ( V_41 ) ;
return 0 ;
}
