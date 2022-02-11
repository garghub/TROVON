static unsigned int T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
return F_2 ( V_2 -> V_6 + V_3 ) ;
case V_7 :
return F_3 ( V_2 -> V_6 + ( V_3 << 1 ) ) ;
case V_8 :
return F_4 ( V_2 -> V_6 + ( V_3 << 2 ) ) ;
case V_9 :
return F_5 ( V_2 -> V_6 + ( V_3 << 2 ) ) ;
case V_10 :
return F_6 ( V_2 -> V_11 + V_3 ) ;
default:
return 0 ;
}
}
static void T_1 F_7 ( struct V_1 * V_2 , int V_3 , int V_12 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
F_8 ( V_12 , V_2 -> V_6 + V_3 ) ;
break;
case V_7 :
F_9 ( V_12 , V_2 -> V_6 + ( V_3 << 1 ) ) ;
break;
case V_8 :
F_10 ( V_12 , V_2 -> V_6 + ( V_3 << 2 ) ) ;
break;
case V_9 :
F_11 ( V_12 , V_2 -> V_6 + ( V_3 << 2 ) ) ;
break;
case V_10 :
F_12 ( V_12 , V_2 -> V_11 + V_3 ) ;
break;
}
}
static void T_1 F_13 ( struct V_1 * V_2 , int V_13 )
{
unsigned int V_14 ;
F_7 ( V_2 , V_15 , V_13 ) ;
for (; ; ) {
V_14 = F_1 ( V_2 , V_16 ) ;
if ( ( V_14 & V_17 ) == V_17 )
break;
F_14 () ;
}
}
static void T_1 F_15 ( struct V_18 * V_18 ,
const char * V_19 , unsigned int V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_1 * V_2 = & V_22 -> V_2 ;
F_16 ( V_2 , V_19 , V_20 , F_13 ) ;
}
static void T_1 F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = & V_22 -> V_2 ;
unsigned int V_24 ;
unsigned char V_13 ;
unsigned int V_25 ;
F_7 ( V_2 , V_26 , 0x3 ) ;
V_25 = F_1 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_27 , V_25 & V_28 ) ;
F_7 ( V_2 , V_29 , 0 ) ;
F_7 ( V_2 , V_30 , 0x3 ) ;
V_24 = F_18 ( V_2 -> V_31 , 16 * V_22 -> V_32 ) ;
V_13 = F_1 ( V_2 , V_26 ) ;
F_7 ( V_2 , V_26 , V_13 | V_33 ) ;
F_7 ( V_2 , V_34 , V_24 & 0xff ) ;
F_7 ( V_2 , V_35 , ( V_24 >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_26 , V_13 & ~ V_33 ) ;
}
int T_1 F_19 ( struct V_21 * V_22 ,
const char * V_36 )
{
if ( ! ( V_22 -> V_2 . V_6 || V_22 -> V_2 . V_11 ) )
return - V_37 ;
if ( ! V_22 -> V_32 ) {
struct V_1 * V_2 = & V_22 -> V_2 ;
unsigned int V_25 ;
V_25 = F_1 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_27 , V_25 & V_28 ) ;
} else
F_17 ( V_22 ) ;
V_22 -> V_38 -> V_39 = F_15 ;
return 0 ;
}
