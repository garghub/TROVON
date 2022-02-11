static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
static const struct V_4 V_5 [] = {
{ 0x80 , 1 , 0x01 , 0x01 } ,
{ 0x80 , 1 , 0x02 , 0x02 }
} ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
if ( ! F_3 ( V_9 , & V_5 [ V_7 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 , struct V_14 * V_15 , int V_16 )
{
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
T_1 V_17 = 0 ;
T_1 V_18 , V_19 ;
int V_20 = V_7 -> V_12 ? 0x74 : 0x70 ;
unsigned int V_21 = ( V_15 -> V_22 != 0 ) ;
F_6 ( V_9 , V_20 , & V_19 ) ;
V_18 = V_19 ;
switch( V_16 )
{
case V_23 :
V_17 = 0x0103 ; break;
case V_24 :
V_17 = 0x0203 ; break;
case V_25 :
V_17 = 0x0808 ; break;
case V_26 :
case V_27 :
case V_28 :
V_17 = 0x0F0F ; break;
case V_29 :
V_17 = 0x0202 ; break;
case V_30 :
V_17 = 0x0204 ; break;
case V_31 :
V_17 = 0x0404 ; break;
case V_32 :
V_17 = 0x0508 ; break;
case V_33 :
V_17 = 0x0808 ; break;
default:
F_7 () ;
}
V_18 &= ~ ( 0xFFFF << ( 16 * V_21 ) ) ;
V_18 |= ( V_17 << ( 16 * V_21 ) ) ;
if ( V_18 != V_19 )
F_8 ( V_9 , V_20 , V_18 ) ;
}
static void F_9 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
F_5 ( V_7 , V_15 , V_15 -> V_34 ) ;
}
static void F_10 ( struct V_35 * V_36 )
{
F_5 ( V_36 -> V_7 , V_36 -> V_11 , V_36 -> V_11 -> V_37 ) ;
F_11 ( V_36 ) ;
}
static void F_12 ( struct V_35 * V_36 )
{
F_13 ( V_36 ) ;
F_5 ( V_36 -> V_7 , V_36 -> V_11 , V_36 -> V_11 -> V_34 ) ;
}
static int F_14 ( struct V_8 * V_11 , const struct V_38 * V_39 )
{
static const struct V_40 V_41 = {
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = & V_49
} ;
const struct V_40 * V_50 [] = { & V_41 , NULL } ;
F_15 ( & V_11 -> V_11 , V_51 ) ;
return F_16 ( V_11 , V_50 , & V_52 , NULL , 0 ) ;
}
static int F_17 ( struct V_8 * V_9 , T_2 V_53 )
{
struct V_54 * V_10 = F_18 ( & V_9 -> V_11 ) ;
int V_55 = 0 ;
V_55 = F_19 ( V_10 , V_53 ) ;
if ( V_55 )
return V_55 ;
F_20 ( V_9 ) ;
return 0 ;
}
