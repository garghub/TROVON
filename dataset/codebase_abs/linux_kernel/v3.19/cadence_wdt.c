static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_1 ( V_2 , V_9 ,
V_10 & ( ~ V_11 ) ) ;
F_6 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_1 ( V_2 , V_12 ,
V_13 ) ;
F_6 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned int V_14 = 0 ;
unsigned short V_15 ;
unsigned long V_16 = F_9 ( V_2 -> V_17 ) ;
V_15 = ( V_7 -> V_18 * ( V_16 / V_2 -> V_19 ) ) /
V_20 + 1 ;
if ( V_15 > V_21 )
V_15 = V_21 ;
F_5 ( & V_2 -> V_8 ) ;
F_1 ( V_2 , V_9 ,
V_10 ) ;
V_15 = ( V_15 << 2 ) & V_22 ;
V_14 = V_15 | V_23 | V_2 -> V_24 ;
F_1 ( V_2 , V_25 , V_14 ) ;
V_14 = V_11 | V_26 |
V_10 ;
if ( V_2 -> V_27 ) {
V_14 |= V_28 ;
V_14 &= ~ V_29 ;
} else {
V_14 &= ~ V_28 ;
V_14 |= V_29 ;
}
F_1 ( V_2 , V_9 , V_14 ) ;
F_1 ( V_2 , V_12 ,
V_13 ) ;
F_6 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
unsigned int V_30 )
{
V_7 -> V_18 = V_30 ;
return F_8 ( V_7 ) ;
}
static T_2 F_11 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
F_12 ( & V_34 -> V_35 ,
L_1 ) ;
return V_36 ;
}
static int F_13 ( struct V_37 * V_38 , unsigned long V_39 ,
void * V_40 )
{
struct V_1 * V_2 = F_14 ( V_38 , struct V_1 ,
V_41 ) ;
if ( V_39 == V_42 || V_39 == V_43 )
F_3 ( & V_2 -> V_44 ) ;
return V_45 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_46 * V_47 ;
int V_48 , V_31 ;
unsigned long V_16 ;
struct V_1 * V_2 ;
struct V_6 * V_44 ;
V_2 = F_16 ( & V_34 -> V_35 , sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_44 = & V_2 -> V_44 ;
V_44 -> V_51 = & V_52 ;
V_44 -> V_53 = & V_54 ;
V_44 -> V_18 = V_55 ;
V_44 -> V_56 = V_57 ;
V_44 -> V_58 = V_59 ;
V_47 = F_17 ( V_34 , V_60 , 0 ) ;
V_2 -> V_5 = F_18 ( & V_34 -> V_35 , V_47 ) ;
if ( F_19 ( V_2 -> V_5 ) )
return F_20 ( V_2 -> V_5 ) ;
V_2 -> V_27 = F_21 ( V_34 -> V_35 . V_61 , L_2 ) ;
V_31 = F_22 ( V_34 , 0 ) ;
if ( ! V_2 -> V_27 && V_31 >= 0 ) {
V_48 = F_23 ( & V_34 -> V_35 , V_31 , F_11 , 0 ,
V_34 -> V_62 , V_34 ) ;
if ( V_48 ) {
F_24 ( & V_34 -> V_35 ,
L_3 ,
V_48 ) ;
return V_48 ;
}
}
V_44 -> V_63 = & V_34 -> V_35 ;
V_48 = F_25 ( V_44 , V_64 , & V_34 -> V_35 ) ;
if ( V_48 ) {
F_24 ( & V_34 -> V_35 , L_4 ) ;
return V_48 ;
}
F_26 ( V_44 , V_65 ) ;
F_27 ( V_44 , V_2 ) ;
V_2 -> V_17 = F_28 ( & V_34 -> V_35 , NULL ) ;
if ( F_19 ( V_2 -> V_17 ) ) {
F_24 ( & V_34 -> V_35 , L_5 ) ;
V_48 = F_20 ( V_2 -> V_17 ) ;
return V_48 ;
}
V_48 = F_29 ( V_2 -> V_17 ) ;
if ( V_48 ) {
F_24 ( & V_34 -> V_35 , L_6 ) ;
return V_48 ;
}
V_16 = F_9 ( V_2 -> V_17 ) ;
if ( V_16 <= V_66 ) {
V_2 -> V_19 = V_67 ;
V_2 -> V_24 = V_68 ;
} else {
V_2 -> V_19 = V_69 ;
V_2 -> V_24 = V_70 ;
}
F_30 ( & V_2 -> V_8 ) ;
V_2 -> V_41 . V_71 = & F_13 ;
V_48 = F_31 ( & V_2 -> V_41 ) ;
if ( V_48 != 0 ) {
F_24 ( & V_34 -> V_35 , L_7 ,
V_48 ) ;
goto V_72;
}
V_48 = F_32 ( V_44 ) ;
if ( V_48 ) {
F_24 ( & V_34 -> V_35 , L_8 ) ;
goto V_72;
}
F_33 ( V_34 , V_2 ) ;
F_34 ( & V_34 -> V_35 , L_9 ,
V_2 -> V_5 , V_44 -> V_18 ,
V_65 ? L_10 : L_11 ) ;
return 0 ;
V_72:
F_35 ( V_2 -> V_17 ) ;
return V_48 ;
}
static int F_36 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_37 ( V_34 ) ;
F_3 ( & V_2 -> V_44 ) ;
F_38 ( & V_2 -> V_44 ) ;
F_39 ( & V_2 -> V_41 ) ;
F_35 ( V_2 -> V_17 ) ;
return 0 ;
}
static void F_40 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_37 ( V_34 ) ;
F_3 ( & V_2 -> V_44 ) ;
F_35 ( V_2 -> V_17 ) ;
}
static int T_3 F_41 ( struct V_73 * V_35 )
{
struct V_33 * V_34 = F_14 ( V_35 ,
struct V_33 , V_35 ) ;
struct V_1 * V_2 = F_37 ( V_34 ) ;
F_3 ( & V_2 -> V_44 ) ;
F_35 ( V_2 -> V_17 ) ;
return 0 ;
}
static int T_3 F_42 ( struct V_73 * V_35 )
{
int V_48 ;
struct V_33 * V_34 = F_14 ( V_35 ,
struct V_33 , V_35 ) ;
struct V_1 * V_2 = F_37 ( V_34 ) ;
V_48 = F_29 ( V_2 -> V_17 ) ;
if ( V_48 ) {
F_24 ( V_35 , L_6 ) ;
return V_48 ;
}
F_8 ( & V_2 -> V_44 ) ;
return 0 ;
}
