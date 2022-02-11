static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
T_1 V_4 , V_5 ;
unsigned int V_6 ;
V_4 = F_3 ( clock -> V_7 ) ;
V_5 = V_4 & V_8 ;
for ( V_6 = 0 ; V_6 < clock -> V_9 ; V_6 ++ )
if ( V_5 == ( clock -> V_10 [ V_6 ] . V_4 & V_8 ) )
break;
if ( V_6 >= clock -> V_9 )
return - V_11 ;
V_4 &= ~ ( V_12 ) ;
V_4 |= clock -> V_10 [ V_6 ] . V_4 & V_12 ;
F_4 ( V_4 , clock -> V_7 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
F_4 ( F_3 ( clock -> V_7 ) | V_12 , clock -> V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
return ! ( F_3 ( clock -> V_7 ) & V_12 ) ;
}
static unsigned long F_7 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned long V_14 = V_13 ;
T_1 V_4 , V_5 ;
unsigned int V_6 ;
V_4 = F_3 ( clock -> V_7 ) ;
V_5 = V_4 & V_8 ;
for ( V_6 = 0 ; V_6 < clock -> V_9 ; V_6 ++ )
if ( V_5 == ( clock -> V_10 [ V_6 ] . V_4 & V_8 ) )
break;
if ( V_6 >= clock -> V_9 )
return - V_11 ;
return F_8 ( V_14 , clock -> V_10 [ V_6 ] . div ) ;
}
static unsigned int F_9 ( struct V_3 * clock ,
unsigned long V_14 ,
unsigned long V_13 )
{
unsigned int div ;
if ( ! V_14 )
V_14 = 1 ;
div = F_8 ( V_13 , V_14 ) ;
return F_10 (unsigned int, div, clock->div_min, clock->div_max) ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned long * V_13 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = F_9 ( clock , V_14 , * V_13 ) ;
return F_8 ( * V_13 , div ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned long V_13 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = F_9 ( clock , V_14 , V_13 ) ;
T_1 V_4 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < clock -> V_9 ; V_6 ++ )
if ( div == clock -> V_10 [ V_6 ] . div )
break;
if ( V_6 >= clock -> V_9 )
return - V_11 ;
V_4 = F_3 ( clock -> V_7 ) ;
V_4 &= ~ ( V_12 | V_8 ) ;
V_4 |= clock -> V_10 [ V_6 ] . V_4 & ( V_12 | V_8 ) ;
F_4 ( V_4 , clock -> V_7 ) ;
return 0 ;
}
static struct V_15 * T_2 F_13 ( const struct V_16 * V_17 ,
void T_3 * V_18 ,
const char * V_19 )
{
struct V_20 V_21 ;
struct V_3 * clock ;
struct V_15 * V_15 ;
unsigned int V_6 ;
clock = F_14 ( sizeof( * clock ) , V_22 ) ;
if ( ! clock )
return F_15 ( - V_23 ) ;
V_21 . V_24 = V_17 -> V_24 ;
V_21 . V_25 = & V_26 ;
V_21 . V_27 = V_28 | V_29 ;
V_21 . V_30 = & V_19 ;
V_21 . V_31 = 1 ;
clock -> V_7 = V_18 + V_17 -> V_32 ;
clock -> V_2 . V_21 = & V_21 ;
clock -> V_10 = V_33 ;
clock -> V_9 = F_16 ( V_33 ) ;
clock -> V_34 = clock -> V_10 [ 0 ] . div ;
clock -> V_35 = clock -> V_34 ;
for ( V_6 = 1 ; V_6 < clock -> V_9 ; V_6 ++ ) {
clock -> V_34 = F_17 ( clock -> V_34 , clock -> V_10 [ V_6 ] . div ) ;
clock -> V_35 = F_18 ( clock -> V_35 , clock -> V_10 [ V_6 ] . div ) ;
}
V_15 = F_19 ( NULL , & clock -> V_2 ) ;
if ( F_20 ( V_15 ) )
F_21 ( clock ) ;
return V_15 ;
}
struct V_15 * T_2 F_22 ( struct V_36 * V_37 ,
const struct V_16 * V_17 , const struct V_38 * V_39 ,
struct V_15 * * V_40 , void T_3 * V_18 )
{
const struct V_15 * V_41 ;
unsigned int V_42 = 1 ;
unsigned int div = 1 ;
T_1 V_43 ;
V_41 = V_40 [ V_17 -> V_41 ] ;
if ( F_20 ( V_41 ) )
return F_23 ( V_41 ) ;
switch ( V_17 -> type ) {
case V_44 :
div = V_45 -> V_46 ;
break;
case V_47 :
V_43 = F_3 ( V_18 + V_48 ) ;
V_42 = ( ( ( V_43 >> 24 ) & 0x7f ) + 1 ) * 2 ;
if ( V_49 & V_50 )
V_42 *= 2 ;
break;
case V_51 :
V_42 = V_45 -> V_52 ;
break;
case V_53 :
V_43 = F_3 ( V_18 + V_54 ) ;
V_42 = ( ( ( V_43 >> 24 ) & 0x7f ) + 1 ) * 2 ;
if ( V_49 & V_50 )
V_42 *= 2 ;
break;
case V_55 :
V_42 = V_45 -> V_56 ;
break;
case V_57 :
V_43 = F_3 ( V_18 + V_58 ) ;
V_42 = ( ( ( V_43 >> 24 ) & 0x7f ) + 1 ) * 2 ;
if ( V_49 & V_50 )
V_42 *= 2 ;
break;
case V_59 :
return F_13 ( V_17 , V_18 , F_24 ( V_41 ) ) ;
case V_60 :
if ( V_49 & V_61 ) {
V_43 = F_3 ( V_18 + V_62 ) & 0x3f ;
if ( F_25 ( V_40 [ V_63 ] ) ) {
V_41 = V_40 [ V_63 ] ;
V_43 |= F_26 ( 15 ) ;
}
F_4 ( V_43 , V_18 + V_62 ) ;
break;
}
if ( V_64 & F_26 ( 28 ) )
V_41 = V_40 [ V_63 ] ;
break;
default:
return F_15 ( - V_11 ) ;
}
return F_27 ( NULL , V_17 -> V_24 ,
F_24 ( V_41 ) , 0 , V_42 , div ) ;
}
int T_2 F_28 ( const struct V_65 * V_66 ,
unsigned int V_67 , T_1 V_68 )
{
const struct V_69 * V_70 ;
V_45 = V_66 ;
V_63 = V_67 ;
V_64 = V_68 ;
V_70 = F_29 ( V_71 ) ;
if ( V_70 )
V_49 = ( V_72 ) V_70 -> V_73 ;
F_30 ( L_1 , V_74 , V_68 , V_49 ) ;
return 0 ;
}
