static inline bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
return V_3 & V_6 ;
}
static inline struct V_1 *
F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = (struct V_9 * ) V_8 -> V_11 ;
return F_4 ( V_10 , struct V_1 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_12 , int V_13 , T_1 V_14 )
{
void T_2 * V_15 ;
T_1 V_16 ;
int V_17 ;
F_6 ( V_12 & ( V_13 - 1 ) ) ;
if ( ! V_2 -> V_18 )
return V_19 ;
V_15 = V_2 -> V_20 ;
V_16 = F_2 ( V_15 + ( V_12 & ~ 3 ) ) ;
switch ( V_13 ) {
case 1 :
V_17 = ( ( V_12 & 3 ) * 8 ) ;
V_16 &= ~ ( 0xff << V_17 ) ;
V_16 |= ( ( V_14 & 0xff ) << V_17 ) ;
break;
case 2 :
V_17 = ( ( V_12 & 2 ) * 8 ) ;
V_16 &= ~ ( 0xffff << V_17 ) ;
V_16 |= ( ( V_14 & 0xffff ) << V_17 ) ;
break;
case 4 :
V_16 = V_14 ;
break;
default:
return V_21 ;
}
F_7 ( V_16 , V_15 + ( V_12 & ~ 3 ) ) ;
F_2 ( V_15 + ( V_12 & ~ 3 ) ) ;
return V_22 ;
}
static int F_8 ( struct V_7 * V_8 , unsigned int V_23 , int V_12 ,
int V_13 , T_3 * V_14 )
{
struct V_1 * V_2 ;
void T_2 * V_15 ;
T_1 V_16 ;
V_2 = F_3 ( V_8 ) ;
if ( ! V_2 -> V_18 )
return V_19 ;
if ( V_23 )
return V_19 ;
V_15 = V_2 -> V_24 ;
V_16 = F_2 ( V_15 + ( V_12 & ~ 3 ) ) ;
switch ( V_13 ) {
case 1 :
if ( V_12 & 1 )
V_16 >>= 8 ;
if ( V_12 & 2 )
V_16 >>= 16 ;
V_16 &= 0xff ;
break;
case 2 :
if ( V_12 & 2 )
V_16 >>= 16 ;
V_16 &= 0xffff ;
break;
case 4 :
break;
default:
return V_21 ;
}
if ( V_12 == V_25 && V_13 == 4 &&
V_2 -> V_26 ) {
* V_14 = V_2 -> V_27 ;
} else {
* V_14 = V_16 ;
}
return V_22 ;
}
static int F_9 ( struct V_7 * V_8 , unsigned int V_23 , int V_12 ,
int V_13 , T_3 V_14 )
{
struct V_1 * V_2 ;
void T_2 * V_15 ;
T_1 V_16 ;
int V_17 ;
V_2 = F_3 ( V_8 ) ;
if ( ! V_2 -> V_18 )
return V_19 ;
if ( V_23 )
return V_19 ;
if ( F_10 () && V_12 == V_25 && V_13 == 4 ) {
if ( V_14 != 0xffffffff ) {
V_2 -> V_26 = true ;
V_2 -> V_27 = V_14 ;
V_14 = V_28 ;
} else {
V_2 -> V_26 = false ;
}
}
V_15 = V_2 -> V_24 ;
V_16 = F_2 ( V_15 + ( V_12 & ~ 3 ) ) ;
switch ( V_13 ) {
case 1 :
V_17 = ( ( V_12 & 3 ) * 8 ) ;
V_16 &= ~ ( 0xff << V_17 ) ;
V_16 |= ( ( V_14 & 0xff ) << V_17 ) ;
break;
case 2 :
V_17 = ( ( V_12 & 2 ) * 8 ) ;
V_16 &= ~ ( 0xffff << V_17 ) ;
V_16 |= ( ( V_14 & 0xffff ) << V_17 ) ;
break;
case 4 :
V_16 = V_14 ;
break;
default:
return V_21 ;
}
F_7 ( V_16 , V_15 + ( V_12 & ~ 3 ) ) ;
F_2 ( V_15 + ( V_12 & ~ 3 ) ) ;
return V_22 ;
}
static void F_11 ( unsigned int V_29 , struct V_30 * V_31 )
{
struct V_1 * V_2 ;
void T_2 * V_15 ;
T_1 V_32 ;
V_2 = F_12 ( V_29 ) ;
V_15 = V_2 -> V_4 ;
V_32 = F_2 ( V_15 + V_33 ) &
F_2 ( V_15 + V_34 ) ;
if ( V_32 & V_35 )
F_13 ( V_2 -> V_36 + 0 ) ;
else
F_14 () ;
}
static void F_15 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
void T_2 * V_15 ;
int V_39 ;
T_1 V_40 ;
V_2 = F_16 ( V_38 ) ;
V_15 = V_2 -> V_4 ;
V_39 = V_2 -> V_36 - V_38 -> V_29 ;
switch ( V_39 ) {
case 0 :
V_40 = F_2 ( V_15 + V_34 ) ;
F_7 ( V_40 | V_35 ,
V_15 + V_34 ) ;
F_2 ( V_15 + V_34 ) ;
}
}
static void F_17 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
void T_2 * V_15 ;
int V_39 ;
T_1 V_40 ;
V_2 = F_16 ( V_38 ) ;
V_15 = V_2 -> V_4 ;
V_39 = V_2 -> V_36 - V_38 -> V_29 ;
switch ( V_39 ) {
case 0 :
V_40 = F_2 ( V_15 + V_34 ) ;
F_7 ( V_40 & ~ V_35 ,
V_15 + V_34 ) ;
F_2 ( V_15 + V_34 ) ;
V_40 = F_2 ( V_15 + V_33 ) ;
F_7 ( V_40 | V_35 ,
V_15 + V_33 ) ;
F_2 ( V_15 + V_33 ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
int V_41 )
{
void T_2 * V_15 ;
int V_42 ;
V_15 = V_2 -> V_4 ;
F_7 ( 0 , V_15 + V_34 ) ;
F_7 ( 0 , V_15 + V_33 ) ;
V_2 -> V_36 = V_43 + ( V_41 * V_44 ) ;
for ( V_42 = V_2 -> V_36 ;
V_42 < V_2 -> V_36 + V_44 ; V_42 ++ ) {
F_19 ( V_42 , & V_45 ,
V_46 ) ;
F_20 ( V_42 , V_2 ) ;
}
F_21 ( V_2 -> V_29 , V_2 ) ;
F_22 ( V_2 -> V_29 , F_11 ) ;
}
static int F_23 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 ;
int V_41 ;
V_41 = V_48 -> V_41 ;
if ( V_41 == - 1 )
V_41 = 0 ;
V_2 = F_24 ( & V_48 -> V_51 , sizeof( struct V_1 ) ,
V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_50 = F_25 ( V_48 , V_54 , L_1 ) ;
V_2 -> V_4 = F_26 ( & V_48 -> V_51 , V_50 ) ;
if ( F_27 ( V_2 -> V_4 ) )
return F_28 ( V_2 -> V_4 ) ;
V_50 = F_25 ( V_48 , V_54 , L_2 ) ;
V_2 -> V_24 = F_26 ( & V_48 -> V_51 , V_50 ) ;
if ( F_27 ( V_2 -> V_24 ) )
return F_28 ( V_2 -> V_24 ) ;
V_50 = F_25 ( V_48 , V_54 , L_3 ) ;
V_2 -> V_20 = F_26 ( & V_48 -> V_51 , V_50 ) ;
if ( F_27 ( V_2 -> V_20 ) )
return F_28 ( V_2 -> V_20 ) ;
V_2 -> V_29 = F_29 ( V_48 , 0 ) ;
if ( V_2 -> V_29 < 0 )
return - V_55 ;
V_50 = F_25 ( V_48 , V_56 , L_4 ) ;
if ( ! V_50 )
return - V_55 ;
V_2 -> V_57 . V_58 = V_50 ;
V_2 -> V_57 . V_59 = L_5 ;
V_2 -> V_57 . V_60 = V_50 -> V_60 ;
V_2 -> V_57 . V_61 = V_50 -> V_61 ;
V_2 -> V_57 . V_62 = V_56 ;
V_50 = F_25 ( V_48 , V_54 , L_6 ) ;
if ( ! V_50 )
return - V_55 ;
V_2 -> V_63 . V_58 = V_50 ;
V_2 -> V_63 . V_59 = L_7 ;
V_2 -> V_63 . V_60 = V_50 -> V_60 ;
V_2 -> V_63 . V_61 = V_50 -> V_61 ;
V_2 -> V_63 . V_62 = V_54 ;
V_2 -> V_9 . V_64 = & V_65 ;
V_2 -> V_9 . V_66 = & V_2 -> V_57 ;
V_2 -> V_9 . V_67 = & V_2 -> V_63 ;
V_2 -> V_18 = F_1 ( V_2 ) ;
if ( ! V_2 -> V_18 )
F_30 ( & V_48 -> V_51 , L_8 ) ;
F_18 ( V_2 , V_41 ) ;
F_5 ( V_2 , V_68 , 4 , V_69 ) ;
F_31 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_70 ) ;
}
