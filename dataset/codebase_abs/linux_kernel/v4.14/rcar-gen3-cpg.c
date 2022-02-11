static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
T_1 V_4 = F_3 ( clock -> V_5 ) ;
V_4 &= ~ ( V_6 ) ;
V_4 |= clock -> V_7 [ clock -> V_8 ] . V_4 & V_6 ;
F_4 ( V_4 , clock -> V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
F_4 ( F_3 ( clock -> V_5 ) | V_6 , clock -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
return ! ( F_3 ( clock -> V_5 ) & V_6 ) ;
}
static unsigned long F_7 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
return F_8 ( V_9 ,
clock -> V_7 [ clock -> V_8 ] . div ) ;
}
static unsigned int F_9 ( struct V_3 * clock ,
unsigned long V_10 ,
unsigned long V_9 )
{
unsigned int div ;
if ( ! V_10 )
V_10 = 1 ;
div = F_8 ( V_9 , V_10 ) ;
return F_10 (unsigned int, div, clock->div_min, clock->div_max) ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_9 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = F_9 ( clock , V_10 , * V_9 ) ;
return F_8 ( * V_9 , div ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_9 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = F_9 ( clock , V_10 , V_9 ) ;
T_1 V_4 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < clock -> V_12 ; V_11 ++ )
if ( div == clock -> V_7 [ V_11 ] . div )
break;
if ( V_11 >= clock -> V_12 )
return - V_13 ;
clock -> V_8 = V_11 ;
V_4 = F_3 ( clock -> V_5 ) ;
V_4 &= ~ ( V_6 | V_14 ) ;
V_4 |= clock -> V_7 [ V_11 ] . V_4 & ( V_6 | V_14 ) ;
F_4 ( V_4 , clock -> V_5 ) ;
return 0 ;
}
static struct V_15 * T_2 F_13 ( const struct V_16 * V_17 ,
void T_3 * V_18 ,
const char * V_19 )
{
struct V_20 V_21 ;
struct V_3 * clock ;
struct V_15 * V_15 ;
unsigned int V_11 ;
T_1 V_22 ;
clock = F_14 ( sizeof( * clock ) , V_23 ) ;
if ( ! clock )
return F_15 ( - V_24 ) ;
V_21 . V_25 = V_17 -> V_25 ;
V_21 . V_26 = & V_27 ;
V_21 . V_28 = V_29 | V_30 ;
V_21 . V_31 = & V_19 ;
V_21 . V_32 = 1 ;
clock -> V_5 = V_18 + V_17 -> V_33 ;
clock -> V_2 . V_21 = & V_21 ;
clock -> V_7 = V_34 ;
clock -> V_12 = F_16 ( V_34 ) ;
V_22 = F_3 ( clock -> V_5 ) & V_14 ;
for ( V_11 = 0 ; V_11 < clock -> V_12 ; V_11 ++ )
if ( V_22 == ( clock -> V_7 [ V_11 ] . V_4 & V_14 ) )
break;
if ( F_17 ( V_11 >= clock -> V_12 ) ) {
F_18 ( clock ) ;
return F_15 ( - V_13 ) ;
}
clock -> V_8 = V_11 ;
clock -> V_35 = clock -> V_7 [ 0 ] . div ;
clock -> V_36 = clock -> V_35 ;
for ( V_11 = 1 ; V_11 < clock -> V_12 ; V_11 ++ ) {
clock -> V_35 = F_19 ( clock -> V_35 , clock -> V_7 [ V_11 ] . div ) ;
clock -> V_36 = F_20 ( clock -> V_36 , clock -> V_7 [ V_11 ] . div ) ;
}
V_15 = F_21 ( NULL , & clock -> V_2 ) ;
if ( F_22 ( V_15 ) )
F_18 ( clock ) ;
return V_15 ;
}
struct V_15 * T_2 F_23 ( struct V_37 * V_38 ,
const struct V_16 * V_17 , const struct V_39 * V_40 ,
struct V_15 * * V_41 , void T_3 * V_18 )
{
const struct V_15 * V_42 ;
unsigned int V_43 = 1 ;
unsigned int div = 1 ;
T_1 V_44 ;
V_42 = V_41 [ V_17 -> V_42 & 0xffff ] ;
if ( F_22 ( V_42 ) )
return F_24 ( V_42 ) ;
switch ( V_17 -> type ) {
case V_45 :
div = V_46 -> V_47 ;
break;
case V_48 :
V_44 = F_3 ( V_18 + V_49 ) ;
V_43 = ( ( ( V_44 >> 24 ) & 0x7f ) + 1 ) * 2 ;
if ( V_50 & V_51 )
V_43 *= 2 ;
break;
case V_52 :
V_43 = V_46 -> V_53 ;
div = V_46 -> V_54 ;
break;
case V_55 :
V_44 = F_3 ( V_18 + V_56 ) ;
V_43 = ( ( ( V_44 >> 24 ) & 0x7f ) + 1 ) * 2 ;
if ( V_50 & V_51 )
V_43 *= 2 ;
break;
case V_57 :
V_43 = V_46 -> V_58 ;
div = V_46 -> V_59 ;
break;
case V_60 :
V_44 = F_3 ( V_18 + V_61 ) ;
V_43 = ( ( ( V_44 >> 24 ) & 0x7f ) + 1 ) * 2 ;
if ( V_50 & V_51 )
V_43 *= 2 ;
break;
case V_62 :
return F_13 ( V_17 , V_18 , F_25 ( V_42 ) ) ;
case V_63 :
if ( V_50 & V_64 ) {
V_44 = F_3 ( V_18 + V_65 ) & 0x3f ;
if ( F_26 ( V_41 [ V_66 ] ) ) {
V_42 = V_41 [ V_66 ] ;
V_44 |= F_27 ( 15 ) ;
}
F_4 ( V_44 , V_18 + V_65 ) ;
break;
}
if ( V_67 & F_27 ( 28 ) )
V_42 = V_41 [ V_66 ] ;
break;
case V_68 :
if ( V_67 & F_27 ( 12 ) ) {
div = V_17 -> div & 0xffff ;
} else {
V_42 = V_41 [ V_17 -> V_42 >> 16 ] ;
if ( F_22 ( V_42 ) )
return F_24 ( V_42 ) ;
div = V_17 -> div >> 16 ;
}
V_43 = 1 ;
break;
default:
return F_15 ( - V_13 ) ;
}
return F_28 ( NULL , V_17 -> V_25 ,
F_25 ( V_42 ) , 0 , V_43 , div ) ;
}
int T_2 F_29 ( const struct V_69 * V_70 ,
unsigned int V_71 , T_1 V_72 )
{
const struct V_73 * V_74 ;
V_46 = V_70 ;
V_66 = V_71 ;
V_67 = V_72 ;
V_74 = F_30 ( V_75 ) ;
if ( V_74 )
V_50 = ( V_76 ) V_74 -> V_77 ;
F_31 ( L_1 , V_78 , V_72 , V_50 ) ;
return 0 ;
}
