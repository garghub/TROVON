static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned short V_9 ;
F_2 ( V_6 , V_10 , 0x5 , 0x1 ) ;
if ( V_2 -> V_11 == V_12 )
V_9 = V_13 ;
else
V_9 = V_14 ;
return F_3 ( V_6 , V_9 , V_8 -> V_15 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned short V_9 ;
F_3 ( V_6 , V_16 , 0x2002 ) ;
F_2 ( V_6 , V_10 , 0x5 , 0x5 ) ;
V_9 = V_13 ;
return F_3 ( V_6 , V_9 , V_8 -> V_15 ) ;
}
static int F_5 ( struct V_5 * V_6 ,
enum V_17 V_18 )
{
switch ( V_18 ) {
case V_19 :
case V_20 :
case V_21 :
F_3 ( V_6 , V_22 , 0x0000 ) ;
break;
case V_23 :
F_3 ( V_6 , V_22 , 0xffff ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
return F_8 ( V_25 , true , V_26 ,
V_27 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_28 * V_28 ;
int V_29 ;
V_25 = F_10 ( V_6 , V_26 ,
V_27 ) ;
if ( F_11 ( V_25 ) )
return F_12 ( V_25 ) ;
V_28 = F_13 ( V_25 , & V_30 ) ;
if ( F_11 ( V_28 ) ) {
V_29 = F_12 ( V_28 ) ;
goto V_31;
}
F_14 ( V_6 , V_28 ) ;
F_15 ( V_6 , V_25 ) ;
return 0 ;
V_31:
F_16 ( V_25 ) ;
return V_29 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
F_18 ( V_6 ) ;
F_16 ( V_25 ) ;
return 0 ;
}
static int F_19 ( struct V_32 * V_33 )
{
return F_20 ( & V_33 -> V_34 ,
& V_35 , V_36 , F_21 ( V_36 ) ) ;
}
static int F_22 ( struct V_32 * V_33 )
{
F_23 ( & V_33 -> V_34 ) ;
return 0 ;
}
