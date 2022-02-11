static unsigned long F_1 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
int V_7 ;
if ( V_4 == V_8 || V_4 == V_9 )
V_7 = V_3 * 8 ;
else
V_7 = ( V_3 / 32 ) * 4 ;
return V_6 -> V_10 + V_4 + V_7 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_11 = F_1 ( V_2 , V_3 , V_9 ) ;
unsigned long V_12 = F_1 ( V_2 , V_3 , V_13 ) ;
F_4 ( & V_6 -> V_14 -> V_15 ) ;
if ( ! ( F_5 ( V_12 ) & F_6 ( V_3 % 32 ) ) ) {
F_7 ( & V_6 -> V_14 -> V_15 , L_1 , V_3 ) ;
return - V_16 ;
}
if ( ! ( F_5 ( V_4 ) & V_17 ) )
return - V_18 ;
F_8 ( F_5 ( V_11 ) & ~ V_19 , V_11 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_11 = F_1 ( V_2 , V_3 , V_9 ) ;
F_8 ( F_5 ( V_11 ) | V_19 , V_11 ) ;
F_10 ( & V_6 -> V_14 -> V_15 ) ;
}
static int F_11 ( struct V_20 * V_21 , unsigned type )
{
struct V_5 * V_6 = F_12 ( V_21 ) ;
T_1 V_22 = F_13 ( V_21 ) ;
unsigned long V_23 ;
T_1 V_24 ;
unsigned long V_4 = F_1 ( & V_6 -> V_2 , V_22 , V_8 ) ;
if ( V_22 >= V_6 -> V_2 . V_25 )
return - V_26 ;
F_14 ( & V_6 -> V_27 , V_23 ) ;
V_24 = F_5 ( V_4 ) ;
if ( type & V_28 )
V_24 &= ~ ( V_29 | V_30 ) ;
if ( type & V_31 )
V_24 = ( V_24 | V_30 ) & ~ V_29 ;
if ( type & V_32 )
V_24 = ( V_24 | V_29 ) & ~ V_30 ;
if ( type & V_33 )
V_24 |= V_29 | V_30 ;
F_8 ( V_24 , V_4 ) ;
F_15 ( & V_6 -> V_27 , V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
return F_5 ( V_4 ) & V_34 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_3 , int V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_23 ;
F_14 ( & V_6 -> V_27 , V_23 ) ;
if ( V_24 )
F_8 ( F_5 ( V_4 ) | V_35 , V_4 ) ;
else
F_8 ( F_5 ( V_4 ) & ~ V_35 , V_4 ) ;
F_15 ( & V_6 -> V_27 , V_23 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_23 ;
F_14 ( & V_6 -> V_27 , V_23 ) ;
F_8 ( F_5 ( V_4 ) | V_36 , V_4 ) ;
F_15 ( & V_6 -> V_27 , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_3 , int V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_23 ;
F_17 ( V_2 , V_3 , V_24 ) ;
F_14 ( & V_6 -> V_27 , V_23 ) ;
F_8 ( F_5 ( V_4 ) & ~ V_36 , V_4 ) ;
F_15 ( & V_6 -> V_27 , V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
return F_21 ( V_6 -> V_37 , V_3 ) ;
}
static void F_22 ( unsigned V_38 , struct V_39 * V_40 )
{
struct V_20 * V_41 = F_23 ( V_40 ) ;
struct V_5 * V_6 = F_24 ( V_41 ) ;
struct V_42 * V_2 = F_25 ( V_41 ) ;
T_1 V_43 , V_44 , V_45 ;
unsigned long V_4 , V_46 ;
unsigned V_47 ;
for ( V_43 = 0 ; V_43 < V_6 -> V_2 . V_25 ; V_43 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_43 , V_48 ) ;
while ( ( V_46 = F_5 ( V_4 ) ) ) {
V_44 = F_26 ( V_46 ) ;
V_45 = F_6 ( V_44 ) ;
F_8 ( V_45 , V_4 ) ;
V_47 = F_27 ( V_6 -> V_37 , V_43 + V_44 ) ;
F_28 ( V_47 ) ;
}
}
V_2 -> V_49 ( V_41 ) ;
}
static void F_29 ( struct V_20 * V_21 )
{
}
static void F_30 ( struct V_20 * V_21 )
{
}
static void F_31 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_12 ( V_21 ) ;
T_1 V_22 = F_13 ( V_21 ) ;
unsigned long V_4 = F_1 ( & V_6 -> V_2 , V_22 , V_50 ) ;
unsigned long V_23 ;
F_14 ( & V_6 -> V_27 , V_23 ) ;
F_8 ( F_5 ( V_4 ) | F_6 ( V_22 % 32 ) , V_4 ) ;
F_15 ( & V_6 -> V_27 , V_23 ) ;
}
static void F_32 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_12 ( V_21 ) ;
T_1 V_22 = F_13 ( V_21 ) ;
unsigned long V_4 = F_1 ( & V_6 -> V_2 , V_22 , V_50 ) ;
unsigned long V_23 ;
F_14 ( & V_6 -> V_27 , V_23 ) ;
F_8 ( F_5 ( V_4 ) & ~ F_6 ( V_22 % 32 ) , V_4 ) ;
F_15 ( & V_6 -> V_27 , V_23 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
unsigned long V_4 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < V_6 -> V_2 . V_25 ; V_43 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_43 , V_50 ) ;
F_8 ( 0 , V_4 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_43 , V_48 ) ;
F_8 ( 0xffffffff , V_4 ) ;
}
}
static int F_34 ( struct V_51 * V_21 , unsigned int V_47 ,
T_2 V_52 )
{
struct V_5 * V_6 = V_21 -> V_53 ;
F_35 ( V_47 , & V_54 , V_55 ,
L_2 ) ;
F_36 ( V_47 , V_6 ) ;
F_37 ( V_47 , V_56 ) ;
return 0 ;
}
static int F_38 ( struct V_57 * V_14 )
{
struct V_5 * V_6 ;
struct V_1 * V_58 ;
struct V_59 * V_60 , * V_61 ;
struct V_62 * V_15 = & V_14 -> V_15 ;
unsigned long V_63 ;
unsigned V_22 ;
int V_64 = - V_18 ;
V_6 = F_39 ( V_15 , sizeof( struct V_5 ) , V_65 ) ;
if ( ! V_6 ) {
F_7 ( V_15 , L_3 ) ;
return - V_66 ;
}
V_6 -> V_14 = V_14 ;
F_40 ( V_14 , V_6 ) ;
V_60 = F_41 ( V_14 , V_67 , 0 ) ;
V_61 = F_41 ( V_14 , V_68 , 0 ) ;
if ( ! V_60 ) {
F_7 ( V_15 , L_4 ) ;
return - V_26 ;
}
V_6 -> V_10 = V_60 -> V_69 ;
V_63 = F_42 ( V_60 ) ;
if ( ! F_43 ( V_15 , V_6 -> V_10 , V_63 , L_5 ) ) {
F_7 ( V_15 , L_6 ,
( unsigned int ) V_6 -> V_10 ) ;
return - V_16 ;
}
F_44 ( & V_6 -> V_27 ) ;
V_58 = & V_6 -> V_2 ;
V_58 -> V_70 = F_45 ( V_15 ) ;
V_58 -> V_71 = V_72 ;
V_58 -> V_73 = F_3 ;
V_58 -> free = F_9 ;
V_58 -> V_74 = F_18 ;
V_58 -> V_75 = F_19 ;
V_58 -> V_76 = F_16 ;
V_58 -> V_77 = F_17 ;
V_58 -> V_43 = - 1 ;
V_58 -> V_25 = V_78 ;
V_58 -> V_79 = 0 ;
V_58 -> V_15 = V_15 ;
if ( V_61 && V_61 -> V_69 ) {
V_22 = V_61 -> V_69 ;
V_58 -> V_80 = F_20 ;
V_6 -> V_37 = F_46 ( NULL , V_78 ,
& V_81 , V_6 ) ;
if ( ! V_6 -> V_37 )
return - V_82 ;
F_33 ( V_6 ) ;
F_47 ( V_22 , V_6 ) ;
F_48 ( V_22 , F_22 ) ;
}
V_64 = F_49 ( V_58 ) ;
if ( V_64 ) {
F_7 ( V_15 , L_7 ) ;
return V_64 ;
}
F_50 ( V_15 ) ;
return 0 ;
}
static int F_51 ( struct V_62 * V_15 )
{
return 0 ;
}
static int F_52 ( struct V_62 * V_15 )
{
return 0 ;
}
static int F_53 ( struct V_57 * V_14 )
{
struct V_5 * V_6 = F_54 ( V_14 ) ;
int V_83 ;
V_83 = F_55 ( & V_6 -> V_2 ) ;
if ( V_83 )
F_56 ( & V_14 -> V_15 , L_8 ) ;
return 0 ;
}
static int T_3 F_57 ( void )
{
return F_58 ( & V_84 ) ;
}
