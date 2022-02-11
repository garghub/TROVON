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
unsigned long V_15 ;
void T_2 * V_16 ;
T_1 V_17 ;
int V_18 ;
F_6 ( V_12 & ( V_13 - 1 ) ) ;
if ( ! V_2 -> V_19 )
return V_20 ;
V_16 = V_2 -> V_21 ;
F_7 ( & V_2 -> V_22 , V_15 ) ;
V_17 = F_2 ( V_16 + ( V_12 & ~ 3 ) ) ;
switch ( V_13 ) {
case 1 :
V_18 = ( ( V_12 & 3 ) * 8 ) ;
V_17 &= ~ ( 0xff << V_18 ) ;
V_17 |= ( ( V_14 & 0xff ) << V_18 ) ;
break;
case 2 :
V_18 = ( ( V_12 & 2 ) * 8 ) ;
V_17 &= ~ ( 0xffff << V_18 ) ;
V_17 |= ( ( V_14 & 0xffff ) << V_18 ) ;
break;
case 4 :
V_17 = V_14 ;
break;
default:
F_8 ( & V_2 -> V_22 , V_15 ) ;
return V_23 ;
}
F_9 ( V_17 , V_16 + ( V_12 & ~ 3 ) ) ;
F_2 ( V_16 + ( V_12 & ~ 3 ) ) ;
F_8 ( & V_2 -> V_22 , V_15 ) ;
return V_24 ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_25 , int V_12 ,
int V_13 , T_3 * V_14 )
{
struct V_1 * V_2 ;
unsigned long V_15 ;
void T_2 * V_16 ;
T_1 V_17 ;
V_2 = F_3 ( V_8 ) ;
if ( ! V_2 -> V_19 )
return V_20 ;
if ( V_25 )
return V_20 ;
V_16 = V_2 -> V_26 ;
F_7 ( & V_2 -> V_22 , V_15 ) ;
V_17 = F_2 ( V_16 + ( V_12 & ~ 3 ) ) ;
switch ( V_13 ) {
case 1 :
if ( V_12 & 1 )
V_17 >>= 8 ;
if ( V_12 & 2 )
V_17 >>= 16 ;
V_17 &= 0xff ;
break;
case 2 :
if ( V_12 & 2 )
V_17 >>= 16 ;
V_17 &= 0xffff ;
break;
case 4 :
break;
default:
F_8 ( & V_2 -> V_22 , V_15 ) ;
return V_23 ;
}
F_8 ( & V_2 -> V_22 , V_15 ) ;
if ( V_12 == V_27 && V_13 == 4 &&
V_2 -> V_28 ) {
* V_14 = V_2 -> V_29 ;
} else {
* V_14 = V_17 ;
}
return V_24 ;
}
static int F_11 ( struct V_7 * V_8 , unsigned int V_25 , int V_12 ,
int V_13 , T_3 V_14 )
{
struct V_1 * V_2 ;
unsigned long V_15 ;
void T_2 * V_16 ;
T_1 V_17 ;
int V_18 ;
V_2 = F_3 ( V_8 ) ;
if ( ! V_2 -> V_19 )
return V_20 ;
if ( V_25 )
return V_20 ;
if ( F_12 () && V_12 == V_27 && V_13 == 4 ) {
if ( V_14 != 0xffffffff ) {
V_2 -> V_28 = true ;
V_2 -> V_29 = V_14 ;
V_14 = V_30 ;
} else {
V_2 -> V_28 = false ;
}
}
V_16 = V_2 -> V_26 ;
F_7 ( & V_2 -> V_22 , V_15 ) ;
V_17 = F_2 ( V_16 + ( V_12 & ~ 3 ) ) ;
switch ( V_13 ) {
case 1 :
V_18 = ( ( V_12 & 3 ) * 8 ) ;
V_17 &= ~ ( 0xff << V_18 ) ;
V_17 |= ( ( V_14 & 0xff ) << V_18 ) ;
break;
case 2 :
V_18 = ( ( V_12 & 2 ) * 8 ) ;
V_17 &= ~ ( 0xffff << V_18 ) ;
V_17 |= ( ( V_14 & 0xffff ) << V_18 ) ;
break;
case 4 :
V_17 = V_14 ;
break;
default:
F_8 ( & V_2 -> V_22 , V_15 ) ;
return V_23 ;
}
F_9 ( V_17 , V_16 + ( V_12 & ~ 3 ) ) ;
F_2 ( V_16 + ( V_12 & ~ 3 ) ) ;
F_8 ( & V_2 -> V_22 , V_15 ) ;
return V_24 ;
}
static void F_13 ( unsigned int V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 ;
void T_2 * V_16 ;
T_1 V_34 ;
V_2 = F_14 ( V_31 ) ;
V_16 = V_2 -> V_4 ;
V_34 = F_2 ( V_16 + V_35 ) &
F_2 ( V_16 + V_36 ) ;
if ( V_34 & V_37 )
F_15 ( V_2 -> V_38 + 0 ) ;
else
F_16 () ;
}
static void F_17 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
void T_2 * V_16 ;
int V_41 ;
T_1 V_42 ;
V_2 = F_18 ( V_40 ) ;
V_16 = V_2 -> V_4 ;
V_41 = V_2 -> V_38 - V_40 -> V_31 ;
switch ( V_41 ) {
case 0 :
V_42 = F_2 ( V_16 + V_36 ) ;
F_9 ( V_42 | V_37 ,
V_16 + V_36 ) ;
F_2 ( V_16 + V_36 ) ;
}
}
static void F_19 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
void T_2 * V_16 ;
int V_41 ;
T_1 V_42 ;
V_2 = F_18 ( V_40 ) ;
V_16 = V_2 -> V_4 ;
V_41 = V_2 -> V_38 - V_40 -> V_31 ;
switch ( V_41 ) {
case 0 :
V_42 = F_2 ( V_16 + V_36 ) ;
F_9 ( V_42 & ~ V_37 ,
V_16 + V_36 ) ;
F_2 ( V_16 + V_36 ) ;
V_42 = F_2 ( V_16 + V_35 ) ;
F_9 ( V_42 | V_37 ,
V_16 + V_35 ) ;
F_2 ( V_16 + V_35 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
int V_43 )
{
void T_2 * V_16 ;
int V_44 ;
V_16 = V_2 -> V_4 ;
F_9 ( 0 , V_16 + V_36 ) ;
F_9 ( 0 , V_16 + V_35 ) ;
V_2 -> V_38 = V_45 + ( V_43 * V_46 ) ;
for ( V_44 = V_2 -> V_38 ;
V_44 < V_2 -> V_38 + V_46 ; V_44 ++ ) {
F_21 ( V_44 , & V_47 ,
V_48 ) ;
F_22 ( V_44 , V_2 ) ;
}
F_23 ( V_2 -> V_31 , V_2 ) ;
F_24 ( V_2 -> V_31 , F_13 ) ;
}
static int F_25 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_43 ;
V_43 = V_50 -> V_43 ;
if ( V_43 == - 1 )
V_43 = 0 ;
V_2 = F_26 ( & V_50 -> V_53 , sizeof( struct V_1 ) ,
V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_52 = F_27 ( V_50 , V_56 , L_1 ) ;
if ( ! V_52 )
return - V_57 ;
V_2 -> V_4 = F_28 ( & V_50 -> V_53 , V_52 ) ;
if ( F_29 ( V_2 -> V_4 ) )
return F_30 ( V_2 -> V_4 ) ;
V_52 = F_27 ( V_50 , V_56 , L_2 ) ;
if ( ! V_52 )
return - V_57 ;
V_2 -> V_26 = F_28 ( & V_50 -> V_53 , V_52 ) ;
if ( F_29 ( V_2 -> V_26 ) )
return F_30 ( V_2 -> V_26 ) ;
V_52 = F_27 ( V_50 , V_56 , L_3 ) ;
if ( ! V_52 )
return - V_57 ;
V_2 -> V_21 = F_28 ( & V_50 -> V_53 , V_52 ) ;
if ( F_29 ( V_2 -> V_21 ) )
return F_30 ( V_2 -> V_21 ) ;
V_2 -> V_31 = F_31 ( V_50 , 0 ) ;
if ( V_2 -> V_31 < 0 )
return - V_57 ;
F_32 ( & V_2 -> V_22 ) ;
V_52 = F_27 ( V_50 , V_58 , L_4 ) ;
if ( ! V_52 )
return - V_57 ;
V_2 -> V_59 . V_60 = V_52 ;
V_2 -> V_59 . V_61 = L_5 ;
V_2 -> V_59 . V_62 = V_52 -> V_62 ;
V_2 -> V_59 . V_63 = V_52 -> V_63 ;
V_2 -> V_59 . V_15 = V_58 ;
V_52 = F_27 ( V_50 , V_56 , L_6 ) ;
if ( ! V_52 )
return - V_57 ;
V_2 -> V_64 . V_60 = V_52 ;
V_2 -> V_64 . V_61 = L_7 ;
V_2 -> V_64 . V_62 = V_52 -> V_62 ;
V_2 -> V_64 . V_63 = V_52 -> V_63 ;
V_2 -> V_64 . V_15 = V_56 ;
V_2 -> V_9 . V_65 = & V_66 ;
V_2 -> V_9 . V_67 = & V_2 -> V_59 ;
V_2 -> V_9 . V_68 = & V_2 -> V_64 ;
V_2 -> V_19 = F_1 ( V_2 ) ;
if ( ! V_2 -> V_19 )
F_33 ( & V_50 -> V_53 , L_8 ) ;
F_20 ( V_2 , V_43 ) ;
F_5 ( V_2 , V_69 , 4 , V_70 ) ;
F_34 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_71 ) ;
}
