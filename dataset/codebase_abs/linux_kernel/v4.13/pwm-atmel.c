static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 ,
unsigned long V_4 )
{
return F_4 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_3 ,
unsigned long V_4 , unsigned long V_6 )
{
F_6 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_3 ,
unsigned int V_7 , unsigned long V_4 )
{
unsigned long V_5 = V_8 + V_7 * V_9 ;
return F_4 ( V_3 -> V_5 + V_5 + V_4 ) ;
}
static inline void F_8 ( struct V_1 * V_3 ,
unsigned int V_7 , unsigned long V_4 ,
unsigned long V_6 )
{
unsigned long V_5 = V_8 + V_7 * V_9 ;
F_6 ( V_6 , V_3 -> V_5 + V_5 + V_4 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
const struct V_10 * V_11 ,
unsigned long * V_12 , T_1 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long long V_15 = V_11 -> V_16 ;
V_15 *= F_10 ( V_14 -> V_17 ) ;
F_11 ( V_15 , V_18 ) ;
for ( * V_13 = 0 ; V_15 > V_19 ; V_15 >>= 1 )
( * V_13 ) ++ ;
if ( * V_13 > V_20 ) {
F_12 ( V_3 -> V_21 , L_1 ) ;
return - V_22 ;
}
* V_12 = V_15 ;
return 0 ;
}
static void F_13 ( const struct V_10 * V_11 ,
unsigned long V_12 , unsigned long * V_23 )
{
unsigned long long V_15 = V_11 -> V_24 ;
V_15 *= V_12 ;
F_11 ( V_15 , V_11 -> V_16 ) ;
* V_23 = V_12 - V_15 ;
}
static void F_14 ( struct V_2 * V_3 , struct V_25 * V_26 ,
unsigned long V_23 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_1 V_6 ;
if ( V_14 -> V_27 -> V_28 ==
V_14 -> V_27 -> V_29 ) {
V_6 = F_7 ( V_14 , V_26 -> V_30 , V_31 ) ;
V_6 &= ~ V_32 ;
F_8 ( V_14 , V_26 -> V_30 , V_31 , V_6 ) ;
}
F_8 ( V_14 , V_26 -> V_30 ,
V_14 -> V_27 -> V_28 , V_23 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
unsigned long V_12 , unsigned long V_23 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_8 ( V_14 , V_26 -> V_30 ,
V_14 -> V_27 -> V_33 , V_23 ) ;
F_8 ( V_14 , V_26 -> V_30 ,
V_14 -> V_27 -> V_16 , V_12 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_25 * V_26 ,
bool V_34 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_35 = V_36 + 2 * V_37 ;
F_17 ( & V_14 -> V_38 ) ;
V_14 -> V_39 |= F_3 ( V_14 , V_40 ) ;
while ( ! ( V_14 -> V_39 & ( 1 << V_26 -> V_30 ) ) &&
F_18 ( V_36 , V_35 ) ) {
F_19 ( 10 , 100 ) ;
V_14 -> V_39 |= F_3 ( V_14 , V_40 ) ;
}
F_20 ( & V_14 -> V_38 ) ;
F_5 ( V_14 , V_41 , 1 << V_26 -> V_30 ) ;
V_35 = V_36 + 2 * V_37 ;
while ( ( F_3 ( V_14 , V_42 ) & ( 1 << V_26 -> V_30 ) ) &&
F_18 ( V_36 , V_35 ) )
F_19 ( 10 , 100 ) ;
if ( V_34 )
F_21 ( V_14 -> V_17 ) ;
}
static int F_22 ( struct V_2 * V_3 , struct V_25 * V_26 ,
struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_10 V_43 ;
unsigned long V_12 , V_23 ;
T_1 V_13 , V_6 ;
int V_44 ;
F_23 ( V_26 , & V_43 ) ;
if ( V_11 -> V_45 ) {
if ( V_43 . V_45 &&
V_43 . V_46 == V_11 -> V_46 &&
V_43 . V_16 == V_11 -> V_16 ) {
V_12 = F_7 ( V_14 , V_26 -> V_30 ,
V_14 -> V_27 -> V_16 ) ;
F_13 ( V_11 , V_12 , & V_23 ) ;
F_14 ( V_3 , V_26 , V_23 ) ;
return 0 ;
}
V_44 = F_9 ( V_3 , V_11 , & V_12 ,
& V_13 ) ;
if ( V_44 ) {
F_12 ( V_3 -> V_21 ,
L_2 ) ;
return V_44 ;
}
F_13 ( V_11 , V_12 , & V_23 ) ;
if ( V_43 . V_45 ) {
F_16 ( V_3 , V_26 , false ) ;
} else {
V_44 = F_24 ( V_14 -> V_17 ) ;
if ( V_44 ) {
F_12 ( V_3 -> V_21 , L_3 ) ;
return V_44 ;
}
}
V_6 = F_7 ( V_14 , V_26 -> V_30 , V_31 ) ;
V_6 = ( V_6 & ~ V_47 ) | ( V_13 & V_47 ) ;
if ( V_11 -> V_46 == V_48 )
V_6 &= ~ V_49 ;
else
V_6 |= V_49 ;
F_8 ( V_14 , V_26 -> V_30 , V_31 , V_6 ) ;
F_15 ( V_3 , V_26 , V_12 , V_23 ) ;
F_17 ( & V_14 -> V_38 ) ;
V_14 -> V_39 |= F_3 ( V_14 , V_40 ) ;
V_14 -> V_39 &= ~ ( 1 << V_26 -> V_30 ) ;
F_20 ( & V_14 -> V_38 ) ;
F_5 ( V_14 , V_50 , 1 << V_26 -> V_30 ) ;
} else if ( V_43 . V_45 ) {
F_16 ( V_3 , V_26 , true ) ;
}
return 0 ;
}
static inline const struct V_51 *
F_25 ( struct V_52 * V_53 )
{
const struct V_54 * V_55 ;
if ( V_53 -> V_21 . V_56 )
return F_26 ( & V_53 -> V_21 ) ;
V_55 = F_27 ( V_53 ) ;
return (struct V_51 * ) V_55 -> V_57 ;
}
static int F_28 ( struct V_52 * V_53 )
{
const struct V_51 * V_27 ;
struct V_1 * V_14 ;
struct V_58 * V_59 ;
int V_44 ;
V_27 = F_25 ( V_53 ) ;
if ( ! V_27 )
return - V_60 ;
V_14 = F_29 ( & V_53 -> V_21 , sizeof( * V_14 ) , V_61 ) ;
if ( ! V_14 )
return - V_62 ;
V_59 = F_30 ( V_53 , V_63 , 0 ) ;
V_14 -> V_5 = F_31 ( & V_53 -> V_21 , V_59 ) ;
if ( F_32 ( V_14 -> V_5 ) )
return F_33 ( V_14 -> V_5 ) ;
V_14 -> V_17 = F_34 ( & V_53 -> V_21 , NULL ) ;
if ( F_32 ( V_14 -> V_17 ) )
return F_33 ( V_14 -> V_17 ) ;
V_44 = F_35 ( V_14 -> V_17 ) ;
if ( V_44 ) {
F_12 ( & V_53 -> V_21 , L_4 ) ;
return V_44 ;
}
V_14 -> V_3 . V_21 = & V_53 -> V_21 ;
V_14 -> V_3 . V_64 = & V_65 ;
if ( V_53 -> V_21 . V_56 ) {
V_14 -> V_3 . V_66 = V_67 ;
V_14 -> V_3 . V_68 = 3 ;
}
V_14 -> V_3 . V_5 = - 1 ;
V_14 -> V_3 . V_69 = 4 ;
V_14 -> V_27 = V_27 ;
V_14 -> V_39 = 0 ;
F_36 ( & V_14 -> V_38 ) ;
V_44 = F_37 ( & V_14 -> V_3 ) ;
if ( V_44 < 0 ) {
F_12 ( & V_53 -> V_21 , L_5 , V_44 ) ;
goto V_70;
}
F_38 ( V_53 , V_14 ) ;
return V_44 ;
V_70:
F_39 ( V_14 -> V_17 ) ;
return V_44 ;
}
static int F_40 ( struct V_52 * V_53 )
{
struct V_1 * V_14 = F_41 ( V_53 ) ;
F_39 ( V_14 -> V_17 ) ;
F_42 ( & V_14 -> V_38 ) ;
return F_43 ( & V_14 -> V_3 ) ;
}
