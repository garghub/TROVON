static unsigned int T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_4 ;
switch ( V_2 -> V_5 ) {
case V_6 :
return F_2 ( V_2 -> V_7 + V_3 ) ;
case V_8 :
return F_3 ( V_2 -> V_7 + V_3 ) ;
case V_9 :
return F_4 ( V_2 -> V_7 + V_3 ) ;
case V_10 :
return F_5 ( V_2 -> V_7 + V_3 ) ;
case V_11 :
return F_6 ( V_2 -> V_12 + V_3 ) ;
default:
return 0 ;
}
}
static void T_1 F_7 ( struct V_1 * V_2 , int V_3 , int V_13 )
{
V_3 <<= V_2 -> V_4 ;
switch ( V_2 -> V_5 ) {
case V_6 :
F_8 ( V_13 , V_2 -> V_7 + V_3 ) ;
break;
case V_8 :
F_9 ( V_13 , V_2 -> V_7 + V_3 ) ;
break;
case V_9 :
F_10 ( V_13 , V_2 -> V_7 + V_3 ) ;
break;
case V_10 :
F_11 ( V_13 , V_2 -> V_7 + V_3 ) ;
break;
case V_11 :
F_12 ( V_13 , V_2 -> V_12 + V_3 ) ;
break;
}
}
static void T_1 F_13 ( struct V_1 * V_2 , int V_14 )
{
unsigned int V_15 ;
F_7 ( V_2 , V_16 , V_14 ) ;
for (; ; ) {
V_15 = F_1 ( V_2 , V_17 ) ;
if ( ( V_15 & V_18 ) == V_18 )
break;
F_14 () ;
}
}
static void T_1 F_15 ( struct V_19 * V_19 ,
const char * V_20 , unsigned int V_21 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 ;
F_16 ( V_2 , V_20 , V_21 , F_13 ) ;
}
static void T_1 F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_2 ;
unsigned int V_25 ;
unsigned char V_14 ;
unsigned int V_26 ;
F_7 ( V_2 , V_27 , 0x3 ) ;
V_26 = F_1 ( V_2 , V_28 ) ;
F_7 ( V_2 , V_28 , V_26 & V_29 ) ;
F_7 ( V_2 , V_30 , 0 ) ;
F_7 ( V_2 , V_31 , 0x3 ) ;
V_25 = F_18 ( V_2 -> V_32 , 16 * V_23 -> V_33 ) ;
V_14 = F_1 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_27 , V_14 | V_34 ) ;
F_7 ( V_2 , V_35 , V_25 & 0xff ) ;
F_7 ( V_2 , V_36 , ( V_25 >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_27 , V_14 & ~ V_34 ) ;
}
int T_1 F_19 ( struct V_22 * V_23 ,
const char * V_37 )
{
if ( ! ( V_23 -> V_2 . V_7 || V_23 -> V_2 . V_12 ) )
return - V_38 ;
if ( ! V_23 -> V_33 ) {
struct V_1 * V_2 = & V_23 -> V_2 ;
unsigned int V_26 ;
V_26 = F_1 ( V_2 , V_28 ) ;
F_7 ( V_2 , V_28 , V_26 & V_29 ) ;
} else
F_17 ( V_23 ) ;
V_23 -> V_39 -> V_40 = F_15 ;
return 0 ;
}
static int T_1 F_20 ( struct V_22 * V_23 ,
const char * V_37 )
{
struct V_1 * V_2 = & V_23 -> V_2 ;
if ( ! ( V_23 -> V_2 . V_7 || V_23 -> V_2 . V_12 ) )
return - V_38 ;
V_2 -> V_4 = 2 ;
V_23 -> V_39 -> V_40 = F_15 ;
return 0 ;
}
