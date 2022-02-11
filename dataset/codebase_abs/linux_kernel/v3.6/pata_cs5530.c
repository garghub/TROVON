static void T_1 * F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = ( unsigned long ) V_2 -> V_4 . V_5 ;
return ( void T_1 * ) ( ( V_3 & ~ 0x0F ) + 0x20 + 0x10 * V_2 -> V_6 ) ;
}
static void F_2 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
static const unsigned int V_9 [ 2 ] [ 5 ] = {
{ 0x00009172 , 0x00012171 , 0x00020080 , 0x00032010 , 0x00040010 } ,
{ 0xd1329172 , 0x71212171 , 0x30200080 , 0x20102010 , 0x00100010 }
} ;
void T_1 * V_10 = F_1 ( V_2 ) ;
T_2 V_11 ;
int V_12 ;
V_11 = F_3 ( V_10 + 0x04 ) ;
V_12 = ( V_11 & 0x80000000UL ) ? 1 : 0 ;
if ( V_8 -> V_13 )
V_10 += 0x08 ;
F_4 ( V_9 [ V_12 ] [ V_8 -> V_14 - V_15 ] , V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
void T_1 * V_10 = F_1 ( V_2 ) ;
T_2 V_11 , V_16 = 0 ;
T_3 V_17 ;
V_11 = F_3 ( V_10 + 0x04 ) ;
switch( V_8 -> V_18 ) {
case V_19 :
V_16 = 0x00921250 ; break;
case V_20 :
V_16 = 0x00911140 ; break;
case V_21 :
V_16 = 0x00911030 ; break;
case V_22 :
V_16 = 0x00077771 ; break;
case V_23 :
V_16 = 0x00012121 ; break;
case V_24 :
V_16 = 0x00002020 ; break;
default:
F_6 () ;
}
V_16 |= ( V_11 & 0x80000000UL ) ;
if ( V_8 -> V_13 == 0 )
F_4 ( V_16 , V_10 + 0x04 ) ;
else {
if ( V_16 & 0x00100000 )
V_11 |= 0x00100000 ;
else
V_11 &= ~ 0x00100000 ;
F_4 ( V_11 , V_10 + 0x04 ) ;
F_4 ( V_16 , V_10 + 0x0C ) ;
}
V_17 = F_7 ( V_2 -> V_4 . V_5 + V_25 ) ;
V_17 |= ( 1 << ( 5 + V_8 -> V_13 ) ) ;
F_8 ( V_17 , V_2 -> V_4 . V_5 + V_25 ) ;
V_2 -> V_26 = V_8 ;
}
static unsigned int F_9 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_7 * V_8 = V_28 -> V_29 ;
struct V_7 * V_30 = V_2 -> V_26 ;
if ( F_10 ( V_8 ) && V_8 != V_30 && V_30 != NULL ) {
if ( ( F_11 ( V_8 ) && ! F_11 ( V_30 ) ) ||
( F_11 ( V_30 ) && ! F_11 ( V_8 ) ) )
F_5 ( V_2 , V_8 ) ;
}
return F_12 ( V_28 ) ;
}
static int F_13 ( void )
{
if ( F_14 ( V_31 ) ) {
F_15 ( V_32 L_1 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( void )
{
struct V_33 * V_34 = NULL , * V_35 = NULL , * V_29 = NULL ;
while ( ( V_29 = F_17 ( V_36 , V_37 , V_29 ) ) != NULL ) {
switch ( V_29 -> V_38 ) {
case V_39 :
V_34 = F_18 ( V_29 ) ;
break;
case V_40 :
V_35 = F_18 ( V_29 ) ;
break;
}
}
if ( ! V_34 ) {
F_15 (KERN_ERR DRV_NAME L_2 ) ;
goto V_41;
}
if ( ! V_35 ) {
F_15 (KERN_ERR DRV_NAME L_3 ) ;
goto V_41;
}
F_19 ( V_35 ) ;
F_20 ( V_35 ) ;
F_21 ( V_35 , V_42 , 0x04 ) ;
F_22 ( V_35 , 0xd0 , 0x5006 ) ;
F_21 ( V_34 , 0x40 , 0x1e ) ;
F_21 ( V_34 , 0x41 , 0x14 ) ;
F_21 ( V_34 , 0x42 , 0x00 ) ;
F_21 ( V_34 , 0x43 , 0xc1 ) ;
F_23 ( V_34 ) ;
F_23 ( V_35 ) ;
return 0 ;
V_41:
if ( V_34 )
F_23 ( V_34 ) ;
if ( V_35 )
F_23 ( V_35 ) ;
return - V_43 ;
}
static int F_24 ( struct V_33 * V_44 , const struct V_45 * V_46 )
{
static const struct V_47 V_48 = {
. V_49 = V_50 ,
. V_51 = V_52 ,
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = & V_58
} ;
static const struct V_47 V_59 = {
. V_49 = V_50 ,
. V_51 = V_52 ,
. V_57 = & V_58
} ;
const struct V_47 * V_60 [] = { & V_48 , NULL } ;
int V_61 ;
V_61 = F_25 ( V_44 ) ;
if ( V_61 )
return V_61 ;
if ( F_16 () )
return - V_43 ;
if ( F_13 () )
V_60 [ 1 ] = & V_59 ;
return F_26 ( V_44 , V_60 , & V_62 , NULL , 0 ) ;
}
static int F_27 ( struct V_33 * V_44 )
{
struct V_63 * V_64 = F_28 ( & V_44 -> V_29 ) ;
int V_61 ;
V_61 = F_29 ( V_44 ) ;
if ( V_61 )
return V_61 ;
if ( F_16 () )
return - V_65 ;
F_30 ( V_64 ) ;
return 0 ;
}
