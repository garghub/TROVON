static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_6 = 1000 ;
do {
V_5 = F_1 ( V_2 , V_7 ) ;
} while ( ! ( V_5 & V_8 ) && -- V_6 );
return V_6 ? 0 : - V_9 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_10 , V_6 = 1000 ;
V_10 = F_3 ( V_2 ) ;
if ( V_10 != 0 )
return V_10 ;
F_5 ( V_11 , V_2 -> V_4 + V_12 ) ;
do {
V_5 = F_2 ( V_2 -> V_4 + V_12 ) ;
} while ( ! ( V_5 & V_13 ) && -- V_6 );
return V_6 ? 0 : - V_9 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_14 )
{
int V_10 = 0 ;
if ( V_2 -> type >= V_15 )
V_10 = F_4 ( V_2 ) ;
if ( V_10 == 0 )
V_10 = F_3 ( V_2 ) ;
if ( V_10 == 0 )
F_5 ( V_14 , V_2 -> V_4 + V_3 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_16 ,
bool V_17 )
{
int V_10 ;
unsigned long V_18 ;
T_1 V_5 ;
F_8 ( & V_2 -> V_19 , V_18 ) ;
V_5 = F_1 ( V_2 , V_7 ) ;
V_5 |= V_20 | V_21 ;
if ( V_17 )
V_5 |= V_16 ;
else
V_5 &= ~ V_16 ;
V_10 = F_6 ( V_2 , V_7 , V_5 ) ;
F_9 ( & V_2 -> V_19 , V_18 ) ;
return V_10 ;
}
static int F_10 ( struct V_22 * V_23 , struct V_24 * time )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
T_1 V_25 , V_26 ;
int V_6 = 5 ;
V_25 = F_1 ( V_2 , V_27 ) ;
V_26 = F_1 ( V_2 , V_27 ) ;
while ( V_25 != V_26 && -- V_6 ) {
V_25 = V_26 ;
V_26 = F_1 ( V_2 , V_27 ) ;
}
if ( V_6 == 0 )
return - V_9 ;
F_12 ( V_25 , time ) ;
return F_13 ( time ) ;
}
static int F_14 ( struct V_22 * V_23 , unsigned long V_25 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
return F_6 ( V_2 , V_27 , V_25 ) ;
}
static int F_15 ( struct V_22 * V_23 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
T_1 V_25 ;
T_1 V_5 ;
V_25 = F_1 ( V_2 , V_30 ) ;
V_5 = F_1 ( V_2 , V_7 ) ;
V_29 -> V_31 = ! ! ( V_5 & V_32 ) ;
V_29 -> V_33 = ! ! ( V_5 & V_21 ) ;
F_12 ( V_25 , & V_29 -> time ) ;
return F_13 ( & V_29 -> time ) ;
}
static int F_16 ( struct V_22 * V_23 , struct V_28 * V_29 )
{
int V_10 ;
struct V_1 * V_2 = F_11 ( V_23 ) ;
unsigned long V_25 ;
F_17 ( & V_29 -> time , & V_25 ) ;
V_10 = F_6 ( V_2 , V_30 , V_25 ) ;
if ( ! V_10 )
V_10 = F_7 ( V_2 ,
V_32 | V_34 , V_29 -> V_31 ) ;
return V_10 ;
}
static int F_18 ( struct V_22 * V_23 , unsigned int V_35 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
return F_7 ( V_2 , V_34 , V_35 ) ;
}
static T_3 F_19 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
T_1 V_5 ;
unsigned long V_38 = 0 ;
V_5 = F_1 ( V_2 , V_7 ) ;
if ( V_5 & V_20 )
V_38 |= ( V_39 | V_40 ) ;
if ( V_5 & V_21 )
V_38 |= ( V_41 | V_40 ) ;
F_20 ( V_2 -> V_2 , 1 , V_38 ) ;
F_7 ( V_2 , V_20 | V_21 , false ) ;
return V_42 ;
}
static void F_21 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
F_6 ( V_2 , V_43 , 1 ) ;
}
static void F_22 ( void )
{
struct V_1 * V_2 = F_11 ( V_44 ) ;
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
F_23 ( V_2 -> V_48 ) ;
V_45 = F_24 ( V_2 -> V_48 ) ;
V_46 =
( V_2 -> V_49 * V_45 ) / 1000 ;
if ( V_46 < V_50 )
V_46 &= V_50 ;
else
V_46 = V_50 ;
F_6 ( V_2 ,
V_51 , V_46 ) ;
V_47 = ( V_2 -> V_52 * V_45 ) / 1000 ;
if ( V_47 < V_53 )
V_47 &= V_53 ;
else
V_47 = V_53 ;
F_6 ( V_2 ,
V_54 , V_47 ) ;
F_21 ( V_44 ) ;
F_25 () ;
}
static int F_26 ( struct V_55 * V_56 )
{
int V_10 ;
struct V_1 * V_2 ;
T_1 V_57 ;
struct V_58 * V_59 ;
const struct V_60 * V_61 = F_27 ( V_56 ) ;
const struct V_62 * V_63 = F_28 (
V_64 , & V_56 -> V_23 ) ;
struct V_65 * V_66 = V_56 -> V_23 . V_67 ;
V_2 = F_29 ( & V_56 -> V_23 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
if ( V_63 )
V_2 -> type = (enum V_70 ) V_63 -> V_37 ;
else
V_2 -> type = V_61 -> V_71 ;
V_2 -> V_36 = F_30 ( V_56 , 0 ) ;
if ( V_2 -> V_36 < 0 ) {
F_31 ( & V_56 -> V_23 , L_1 ) ;
return - V_72 ;
}
V_59 = F_32 ( V_56 , V_73 , 0 ) ;
V_2 -> V_4 = F_33 ( & V_56 -> V_23 , V_59 ) ;
if ( F_34 ( V_2 -> V_4 ) )
return F_35 ( V_2 -> V_4 ) ;
V_2 -> V_48 = F_36 ( & V_56 -> V_23 , L_2 ) ;
if ( F_34 ( V_2 -> V_48 ) ) {
F_31 ( & V_56 -> V_23 , L_3 ) ;
return F_35 ( V_2 -> V_48 ) ;
}
F_37 ( & V_2 -> V_19 ) ;
F_38 ( V_56 , V_2 ) ;
F_39 ( & V_56 -> V_23 , 1 ) ;
V_2 -> V_2 = F_40 ( & V_56 -> V_23 , V_56 -> V_74 ,
& V_75 , V_76 ) ;
if ( F_34 ( V_2 -> V_2 ) ) {
V_10 = F_35 ( V_2 -> V_2 ) ;
F_31 ( & V_56 -> V_23 , L_4 , V_10 ) ;
return V_10 ;
}
V_10 = F_41 ( & V_56 -> V_23 , V_2 -> V_36 , F_19 , 0 ,
V_56 -> V_74 , V_2 ) ;
if ( V_10 ) {
F_31 ( & V_56 -> V_23 , L_5 , V_10 ) ;
return V_10 ;
}
V_57 = F_1 ( V_2 , V_77 ) ;
if ( V_57 != 0x12345678 ) {
V_10 = F_6 ( V_2 , V_77 , 0x12345678 ) ;
V_10 = F_6 ( V_2 , V_27 , 0 ) ;
if ( V_10 ) {
F_31 ( & V_56 -> V_23 , L_6 ) ;
return V_10 ;
}
}
if ( V_66 && F_42 ( V_66 ) ) {
if ( ! V_78 ) {
V_2 -> V_52 = 60 ;
F_43 ( V_66 , L_7 ,
& V_2 -> V_52 ) ;
V_2 -> V_49 = 100 ;
F_43 ( V_66 ,
L_8 ,
& V_2 -> V_49 ) ;
V_44 = & V_56 -> V_23 ;
V_78 = F_22 ;
} else {
F_44 ( & V_56 -> V_23 ,
L_9 ) ;
}
}
return 0 ;
}
static int F_45 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
if ( F_46 ( V_23 ) )
F_47 ( V_2 -> V_36 ) ;
return 0 ;
}
static int F_48 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
if ( F_46 ( V_23 ) )
F_49 ( V_2 -> V_36 ) ;
return 0 ;
}
