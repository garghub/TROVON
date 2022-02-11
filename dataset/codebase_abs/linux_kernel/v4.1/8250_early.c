unsigned int __weak T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
return F_2 ( V_2 -> V_6 + V_3 ) ;
case V_7 :
return F_3 ( V_2 -> V_6 + ( V_3 << 2 ) ) ;
case V_8 :
return F_4 ( V_2 -> V_6 + ( V_3 << 2 ) ) ;
case V_9 :
return F_5 ( V_2 -> V_10 + V_3 ) ;
default:
return 0 ;
}
}
void __weak T_1 F_6 ( struct V_1 * V_2 , int V_3 , int V_11 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
F_7 ( V_11 , V_2 -> V_6 + V_3 ) ;
break;
case V_7 :
F_8 ( V_11 , V_2 -> V_6 + ( V_3 << 2 ) ) ;
break;
case V_8 :
F_9 ( V_11 , V_2 -> V_6 + ( V_3 << 2 ) ) ;
break;
case V_9 :
F_10 ( V_11 , V_2 -> V_10 + V_3 ) ;
break;
}
}
static void T_1 F_11 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
for (; ; ) {
V_12 = F_1 ( V_2 , V_13 ) ;
if ( ( V_12 & V_14 ) == V_14 )
return;
F_12 () ;
}
}
static void T_1 F_13 ( struct V_1 * V_2 , int V_15 )
{
F_11 ( V_2 ) ;
F_6 ( V_2 , V_16 , V_15 ) ;
}
static void T_1 F_14 ( struct V_17 * V_17 ,
const char * V_18 , unsigned int V_19 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_1 * V_2 = & V_21 -> V_2 ;
unsigned int V_23 ;
V_23 = F_1 ( V_2 , V_24 ) ;
if ( V_23 )
F_6 ( V_2 , V_24 , V_23 & V_25 ) ;
F_15 ( V_2 , V_18 , V_19 , F_13 ) ;
F_11 ( V_2 ) ;
if ( V_23 )
F_6 ( V_2 , V_24 , V_23 ) ;
}
static void T_1 F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = & V_21 -> V_2 ;
unsigned int V_26 ;
unsigned char V_15 ;
unsigned int V_23 ;
F_6 ( V_2 , V_27 , 0x3 ) ;
V_23 = F_1 ( V_2 , V_24 ) ;
F_6 ( V_2 , V_24 , V_23 & V_25 ) ;
F_6 ( V_2 , V_28 , 0 ) ;
F_6 ( V_2 , V_29 , 0x3 ) ;
V_26 = F_17 ( V_2 -> V_30 , 16 * V_21 -> V_31 ) ;
V_15 = F_1 ( V_2 , V_27 ) ;
F_6 ( V_2 , V_27 , V_15 | V_32 ) ;
F_6 ( V_2 , V_33 , V_26 & 0xff ) ;
F_6 ( V_2 , V_34 , ( V_26 >> 8 ) & 0xff ) ;
F_6 ( V_2 , V_27 , V_15 & ~ V_32 ) ;
}
static int T_1 F_18 ( struct V_20 * V_21 ,
const char * V_35 )
{
if ( ! ( V_21 -> V_2 . V_6 || V_21 -> V_2 . V_10 ) )
return - V_36 ;
if ( ! V_21 -> V_31 ) {
struct V_1 * V_2 = & V_21 -> V_2 ;
unsigned int V_23 ;
V_23 = F_1 ( V_2 , V_24 ) ;
F_6 ( V_2 , V_24 , V_23 & V_25 ) ;
} else
F_16 ( V_21 ) ;
V_21 -> V_37 -> V_38 = F_14 ;
return 0 ;
}
