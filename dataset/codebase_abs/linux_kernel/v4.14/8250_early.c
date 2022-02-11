static unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 ;
V_3 <<= V_2 -> V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
return F_2 ( V_2 -> V_8 + V_3 ) ;
case V_9 :
return F_3 ( V_2 -> V_8 + V_3 ) ;
case V_10 :
return F_4 ( V_2 -> V_8 + V_3 ) ;
case V_11 :
return F_5 ( V_2 -> V_8 + V_3 ) ;
case V_12 :
return F_6 ( V_2 -> V_13 + V_3 ) ;
case V_14 :
return V_2 -> V_15 ( V_2 , V_4 ) ;
default:
return 0 ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
int V_4 = V_3 ;
V_3 <<= V_2 -> V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
F_8 ( V_16 , V_2 -> V_8 + V_3 ) ;
break;
case V_9 :
F_9 ( V_16 , V_2 -> V_8 + V_3 ) ;
break;
case V_10 :
F_10 ( V_16 , V_2 -> V_8 + V_3 ) ;
break;
case V_11 :
F_11 ( V_16 , V_2 -> V_8 + V_3 ) ;
break;
case V_12 :
F_12 ( V_16 , V_2 -> V_13 + V_3 ) ;
break;
case V_14 :
V_2 -> V_17 ( V_2 , V_4 , V_16 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_2 , int V_18 )
{
unsigned int V_19 ;
F_7 ( V_2 , V_20 , V_18 ) ;
for (; ; ) {
V_19 = F_1 ( V_2 , V_21 ) ;
if ( ( V_19 & V_22 ) == V_22 )
break;
F_14 () ;
}
}
static void F_15 ( struct V_23 * V_23 ,
const char * V_24 , unsigned int V_25 )
{
struct V_26 * V_27 = V_23 -> V_28 ;
struct V_1 * V_2 = & V_27 -> V_2 ;
F_16 ( V_2 , V_24 , V_25 , F_13 ) ;
}
static void T_1 F_17 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = & V_27 -> V_2 ;
unsigned int V_29 ;
unsigned char V_18 ;
unsigned int V_30 ;
F_7 ( V_2 , V_31 , 0x3 ) ;
V_30 = F_1 ( V_2 , V_32 ) ;
F_7 ( V_2 , V_32 , V_30 & V_33 ) ;
F_7 ( V_2 , V_34 , 0 ) ;
F_7 ( V_2 , V_35 , 0x3 ) ;
V_29 = F_18 ( V_2 -> V_36 , 16 * V_27 -> V_37 ) ;
V_18 = F_1 ( V_2 , V_31 ) ;
F_7 ( V_2 , V_31 , V_18 | V_38 ) ;
F_7 ( V_2 , V_39 , V_29 & 0xff ) ;
F_7 ( V_2 , V_40 , ( V_29 >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_31 , V_18 & ~ V_38 ) ;
}
int T_1 F_19 ( struct V_26 * V_27 ,
const char * V_41 )
{
if ( ! ( V_27 -> V_2 . V_8 || V_27 -> V_2 . V_13 ) )
return - V_42 ;
if ( ! V_27 -> V_37 ) {
struct V_1 * V_2 = & V_27 -> V_2 ;
unsigned int V_30 ;
V_30 = F_1 ( V_2 , V_32 ) ;
F_7 ( V_2 , V_32 , V_30 & V_33 ) ;
} else
F_17 ( V_27 ) ;
V_27 -> V_43 -> V_44 = F_15 ;
return 0 ;
}
static int T_1 F_20 ( struct V_26 * V_27 ,
const char * V_41 )
{
struct V_1 * V_2 = & V_27 -> V_2 ;
if ( ! ( V_27 -> V_2 . V_8 || V_27 -> V_2 . V_13 ) )
return - V_42 ;
V_2 -> V_5 = 2 ;
V_27 -> V_43 -> V_44 = F_15 ;
return 0 ;
}
static int T_1 F_21 ( struct V_26 * V_45 , const char * V_46 )
{
V_45 -> V_2 . V_15 = V_47 ;
V_45 -> V_2 . V_17 = V_48 ;
V_45 -> V_2 . V_6 = V_14 ;
V_45 -> V_43 -> V_44 = F_15 ;
return 0 ;
}
