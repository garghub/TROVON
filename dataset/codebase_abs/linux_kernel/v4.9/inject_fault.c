static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 ;
unsigned long V_6 = * F_2 ( V_2 ) ;
bool V_7 = ( V_6 & V_8 ) ;
T_1 V_9 = ( V_7 ) ? 4 : 0 ;
T_1 V_10 = F_3 ( V_2 , V_11 ) ;
V_5 = V_3 | V_12 ;
if ( V_10 & ( 1 << 30 ) )
V_5 |= V_8 ;
if ( V_10 & ( 1 << 25 ) )
V_5 |= V_13 ;
* F_2 ( V_2 ) = V_5 ;
* F_4 ( V_2 ) = V_6 ;
* F_5 ( V_2 , 14 ) = * F_6 ( V_2 ) + V_9 ;
if ( V_10 & ( 1 << 13 ) )
V_4 += 0xffff0000 ;
else
V_4 += F_3 ( V_2 , V_14 ) ;
* F_6 ( V_2 ) = V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_15 , 4 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_16 ,
unsigned long V_17 )
{
T_1 V_4 ;
T_1 * V_18 , * V_19 ;
bool V_20 ;
if ( V_16 ) {
V_4 = 12 ;
V_18 = & F_3 ( V_2 , V_21 ) ;
V_19 = & F_3 ( V_2 , V_22 ) ;
} else {
V_4 = 16 ;
V_18 = & F_3 ( V_2 , V_23 ) ;
V_19 = & F_3 ( V_2 , V_24 ) ;
}
F_1 ( V_2 , V_25 | V_26 , V_4 ) ;
* V_18 = V_17 ;
V_20 = ( F_3 ( V_2 , V_27 ) >> 31 ) ;
if ( V_20 )
* V_19 = 1 << 9 | 0x34 ;
else
* V_19 = 0x14 ;
}
static T_2 F_9 ( struct V_1 * V_2 , enum V_28 type )
{
T_2 V_29 ;
switch ( * F_2 ( V_2 ) & ( V_30 | V_31 ) ) {
case V_32 :
V_29 = V_33 ;
break;
case V_34 :
V_29 = V_35 ;
break;
case V_36 :
V_29 = V_37 ;
break;
default:
V_29 = V_38 ;
}
return F_10 ( V_2 , V_39 ) + V_29 + type ;
}
static void F_11 ( struct V_1 * V_2 , bool V_40 , unsigned long V_17 )
{
unsigned long V_5 = * F_2 ( V_2 ) ;
bool V_41 = F_12 ( V_2 ) ;
T_1 V_42 = 0 ;
* F_13 ( V_2 ) = * F_6 ( V_2 ) ;
* F_6 ( V_2 ) = F_9 ( V_2 , V_43 ) ;
* F_2 ( V_2 ) = V_44 ;
* F_4 ( V_2 ) = V_5 ;
F_10 ( V_2 , V_45 ) = V_17 ;
if ( F_14 ( V_2 ) )
V_42 |= V_46 ;
if ( V_41 || ( V_5 & V_30 ) == V_36 )
V_42 |= ( V_47 << V_48 ) ;
else
V_42 |= ( V_49 << V_48 ) ;
if ( ! V_40 )
V_42 |= V_50 << V_48 ;
F_10 ( V_2 , V_51 ) = V_42 | V_52 ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned long V_5 = * F_2 ( V_2 ) ;
T_1 V_42 = ( V_53 << V_48 ) ;
* F_13 ( V_2 ) = * F_6 ( V_2 ) ;
* F_6 ( V_2 ) = F_9 ( V_2 , V_43 ) ;
* F_2 ( V_2 ) = V_44 ;
* F_4 ( V_2 ) = V_5 ;
if ( F_14 ( V_2 ) )
V_42 |= V_46 ;
F_10 ( V_2 , V_51 ) = V_42 ;
}
void F_16 ( struct V_1 * V_2 , unsigned long V_17 )
{
if ( ! ( V_2 -> V_54 . V_55 & V_56 ) )
F_8 ( V_2 , false , V_17 ) ;
else
F_11 ( V_2 , false , V_17 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned long V_17 )
{
if ( ! ( V_2 -> V_54 . V_55 & V_56 ) )
F_8 ( V_2 , true , V_17 ) ;
else
F_11 ( V_2 , true , V_17 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_54 . V_55 & V_56 ) )
F_7 ( V_2 ) ;
else
F_15 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 , F_21 ( V_2 ) | V_57 ) ;
}
