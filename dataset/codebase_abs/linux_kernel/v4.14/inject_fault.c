static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 ;
unsigned long V_6 = * F_2 ( V_2 ) ;
bool V_7 = ( V_6 & V_8 ) ;
T_1 V_9 = V_10 [ V_4 >> 2 ] [ V_7 ] ;
T_1 V_11 = F_3 ( V_2 , V_12 ) ;
V_5 = V_3 | V_13 ;
if ( V_11 & ( 1 << 30 ) )
V_5 |= V_8 ;
if ( V_11 & ( 1 << 25 ) )
V_5 |= V_14 ;
* F_2 ( V_2 ) = V_5 ;
* F_4 ( V_2 ) = V_6 ;
* F_5 ( V_2 , 14 ) = * F_6 ( V_2 ) + V_9 ;
if ( V_11 & ( 1 << 13 ) )
V_4 += 0xffff0000 ;
else
V_4 += F_3 ( V_2 , V_15 ) ;
* F_6 ( V_2 ) = V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_16 , 4 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_17 ,
unsigned long V_18 )
{
T_1 V_4 ;
T_1 * V_19 , * V_20 ;
bool V_21 ;
if ( V_17 ) {
V_4 = 12 ;
V_19 = & F_3 ( V_2 , V_22 ) ;
V_20 = & F_3 ( V_2 , V_23 ) ;
} else {
V_4 = 16 ;
V_19 = & F_3 ( V_2 , V_24 ) ;
V_20 = & F_3 ( V_2 , V_25 ) ;
}
F_1 ( V_2 , V_26 | V_27 , V_4 ) ;
* V_19 = V_18 ;
V_21 = ( F_3 ( V_2 , V_28 ) >> 31 ) ;
if ( V_21 )
* V_20 = 1 << 9 | 0x34 ;
else
* V_20 = 0x14 ;
}
static T_2 F_9 ( struct V_1 * V_2 , enum V_29 type )
{
T_2 V_30 ;
switch ( * F_2 ( V_2 ) & ( V_31 | V_32 ) ) {
case V_33 :
V_30 = V_34 ;
break;
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
V_30 = V_38 ;
break;
default:
V_30 = V_39 ;
}
return F_10 ( V_2 , V_40 ) + V_30 + type ;
}
static void F_11 ( struct V_1 * V_2 , bool V_41 , unsigned long V_18 )
{
unsigned long V_5 = * F_2 ( V_2 ) ;
bool V_42 = F_12 ( V_2 ) ;
T_1 V_43 = 0 ;
* F_13 ( V_2 ) = * F_6 ( V_2 ) ;
* F_6 ( V_2 ) = F_9 ( V_2 , V_44 ) ;
* F_2 ( V_2 ) = V_45 ;
* F_4 ( V_2 ) = V_5 ;
F_10 ( V_2 , V_46 ) = V_18 ;
if ( F_14 ( V_2 ) )
V_43 |= V_47 ;
if ( V_42 || ( V_5 & V_31 ) == V_37 )
V_43 |= ( V_48 << V_49 ) ;
else
V_43 |= ( V_50 << V_49 ) ;
if ( ! V_41 )
V_43 |= V_51 << V_49 ;
F_10 ( V_2 , V_52 ) = V_43 | V_53 ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned long V_5 = * F_2 ( V_2 ) ;
T_1 V_43 = ( V_54 << V_49 ) ;
* F_13 ( V_2 ) = * F_6 ( V_2 ) ;
* F_6 ( V_2 ) = F_9 ( V_2 , V_44 ) ;
* F_2 ( V_2 ) = V_45 ;
* F_4 ( V_2 ) = V_5 ;
if ( F_14 ( V_2 ) )
V_43 |= V_47 ;
F_10 ( V_2 , V_52 ) = V_43 ;
}
void F_16 ( struct V_1 * V_2 , unsigned long V_18 )
{
if ( ! ( V_2 -> V_55 . V_56 & V_57 ) )
F_8 ( V_2 , false , V_18 ) ;
else
F_11 ( V_2 , false , V_18 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned long V_18 )
{
if ( ! ( V_2 -> V_55 . V_56 & V_57 ) )
F_8 ( V_2 , true , V_18 ) ;
else
F_11 ( V_2 , true , V_18 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_55 . V_56 & V_57 ) )
F_7 ( V_2 ) ;
else
F_15 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 , F_21 ( V_2 ) | V_58 ) ;
}
