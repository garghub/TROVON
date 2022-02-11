static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
static const struct V_10 V_11 = { 0x6D , 1 , 0x80 , 0x80 } ;
if ( ! F_3 ( V_7 , & V_11 ) )
return - V_12 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
int V_15 = 0 ;
int V_16 = V_14 -> V_17 - V_18 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_1 V_19 ;
static const
T_2 V_20 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_6 ( V_7 , V_21 , & V_19 ) ;
if ( V_14 -> V_22 == V_23 )
V_15 |= V_24 ;
if ( F_7 ( V_14 ) )
V_15 |= V_25 ;
if ( V_16 > 1 )
V_15 |= V_26 ;
V_19 &= 0xCCEE ;
V_19 &= ~ ( 0x07 << ( 4 * V_14 -> V_27 ) ) ;
V_19 |= V_15 << ( 4 * V_14 -> V_27 ) ;
V_19 |= ( V_20 [ V_16 ] [ 0 ] << 12 ) | ( V_20 [ V_16 ] [ 1 ] << 8 ) ;
F_8 ( V_7 , V_21 , V_19 ) ;
V_5 -> V_28 = V_14 ;
}
static unsigned int F_9 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
struct V_13 * V_14 = V_30 -> V_9 ;
if ( V_14 -> V_17 && V_14 != V_5 -> V_28 )
F_5 ( V_5 , V_14 ) ;
return F_10 ( V_30 ) ;
}
static int F_11 ( struct V_6 * V_9 , const struct V_31 * V_32 )
{
static int V_33 ;
struct V_34 * V_8 ;
struct V_4 * V_5 ;
void T_3 * V_35 , * V_36 ;
T_1 V_19 ;
int V_37 , V_38 , V_39 ;
if ( ! V_33 ++ )
F_12 ( V_40 , & V_9 -> V_9 , L_1 V_41 L_2 ) ;
V_8 = F_13 ( & V_9 -> V_9 , 1 ) ;
if ( ! V_8 )
return - V_42 ;
V_5 = V_8 -> V_43 [ 0 ] ;
F_6 ( V_9 , V_21 , & V_19 ) ;
if ( ! ( V_19 & V_44 ) )
return - V_45 ;
if ( ! ( V_19 & V_46 ) ) {
V_37 = 0x1F0 ;
V_38 = 0x3F6 ;
V_39 = 14 ;
} else {
V_37 = 0x170 ;
V_38 = 0x376 ;
V_39 = 15 ;
}
V_35 = F_14 ( & V_9 -> V_9 , V_37 , 8 ) ;
V_36 = F_14 ( & V_9 -> V_9 , V_38 , 1 ) ;
if ( ! V_35 || ! V_36 )
return - V_42 ;
F_15 ( V_5 , L_3 , V_37 , V_38 ) ;
V_5 -> V_47 = & V_48 ;
V_5 -> V_49 = V_50 ;
V_5 -> V_51 |= V_52 ;
V_5 -> V_53 . V_35 = V_35 ;
V_5 -> V_53 . V_36 = V_36 ;
V_5 -> V_53 . V_54 = V_36 ;
F_16 ( & V_5 -> V_53 ) ;
return F_17 ( V_8 , V_39 , V_55 , V_56 ,
& V_57 ) ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_58 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_58 ) ;
}
