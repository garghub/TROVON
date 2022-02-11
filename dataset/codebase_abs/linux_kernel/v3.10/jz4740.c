static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_7 = F_2 ( V_6 -> V_8 ) ;
T_1 V_9 ;
switch ( F_3 ( V_4 ) ) {
case 8000 :
V_9 = 0 ;
break;
case 11025 :
V_9 = 1 ;
break;
case 12000 :
V_9 = 2 ;
break;
case 16000 :
V_9 = 3 ;
break;
case 22050 :
V_9 = 4 ;
break;
case 24000 :
V_9 = 5 ;
break;
case 32000 :
V_9 = 6 ;
break;
case 44100 :
V_9 = 7 ;
break;
case 48000 :
V_9 = 8 ;
break;
default:
return - V_10 ;
}
V_9 <<= V_11 ;
F_4 ( V_7 -> V_12 , V_13 ,
V_14 , V_9 ) ;
return 0 ;
}
static void F_5 ( struct V_12 * V_12 )
{
F_4 ( V_12 , V_15 ,
V_16 , V_16 ) ;
F_6 ( 2 ) ;
F_4 ( V_12 , V_15 ,
V_17 | V_16 , 0 ) ;
F_7 ( V_12 ) ;
}
static int F_8 ( struct V_18 * V_8 ,
enum V_19 V_20 )
{
struct V_7 * V_7 = F_2 ( V_8 ) ;
struct V_12 * V_12 = V_7 -> V_12 ;
unsigned int V_21 ;
unsigned int V_22 ;
switch ( V_20 ) {
case V_23 :
break;
case V_24 :
V_21 = V_25 |
V_26 |
V_27 ;
V_22 = 0 ;
F_4 ( V_12 , V_15 , V_21 , V_22 ) ;
break;
case V_28 :
if ( V_8 -> V_29 . V_30 == V_31 )
F_5 ( V_12 ) ;
V_21 = V_25 |
V_26 |
V_27 ;
V_22 = V_25 |
V_26 |
V_27 ;
F_4 ( V_12 , V_15 , V_21 , V_22 ) ;
break;
case V_31 :
V_21 = V_17 ;
V_22 = V_17 ;
F_4 ( V_12 , V_15 , V_21 , V_22 ) ;
F_9 ( V_12 ) ;
break;
default:
break;
}
V_8 -> V_29 . V_30 = V_20 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_8 )
{
struct V_7 * V_7 = F_2 ( V_8 ) ;
F_4 ( V_7 -> V_12 , V_15 ,
V_32 , V_32 ) ;
F_8 ( V_8 , V_28 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_8 )
{
F_8 ( V_8 , V_31 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_8 )
{
return F_8 ( V_8 , V_31 ) ;
}
static int F_13 ( struct V_18 * V_8 )
{
return F_8 ( V_8 , V_28 ) ;
}
static int F_14 ( struct V_33 * V_34 )
{
int V_35 ;
struct V_7 * V_7 ;
struct V_36 * V_37 ;
void T_2 * V_38 ;
V_7 = F_15 ( & V_34 -> V_39 , sizeof( * V_7 ) ,
V_40 ) ;
if ( ! V_7 )
return - V_41 ;
V_37 = F_16 ( V_34 , V_42 , 0 ) ;
V_38 = F_17 ( & V_34 -> V_39 , V_37 ) ;
if ( F_18 ( V_38 ) )
return F_19 ( V_38 ) ;
V_7 -> V_12 = F_20 ( & V_34 -> V_39 , V_38 ,
& V_43 ) ;
if ( F_18 ( V_7 -> V_12 ) )
return F_19 ( V_7 -> V_12 ) ;
F_21 ( V_34 , V_7 ) ;
V_35 = F_22 ( & V_34 -> V_39 ,
& V_44 , & V_45 , 1 ) ;
if ( V_35 )
F_23 ( & V_34 -> V_39 , L_1 ) ;
return V_35 ;
}
static int F_24 ( struct V_33 * V_34 )
{
F_25 ( & V_34 -> V_39 ) ;
F_21 ( V_34 , NULL ) ;
return 0 ;
}
