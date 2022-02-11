static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( F_2 ( V_4 , V_5 ) ) {
F_3 ( L_1 ) ;
F_4 () ;
F_3 ( L_2 ) ;
}
return V_6 ;
}
static inline void F_5 ( struct V_3 * V_4 )
{
F_6 ( V_4 , V_7 , V_8 | V_9 ) ;
}
static void F_7 ( unsigned long V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
if ( F_8 ( V_11 , V_4 -> V_12 ) ||
! F_9 ( & V_4 -> V_13 ) ) {
F_5 ( V_4 ) ;
F_10 ( & V_4 -> V_14 , V_11 + V_4 -> V_15 ) ;
} else {
F_3 ( L_3 ) ;
}
}
static int F_11 ( struct V_16 * V_13 )
{
struct V_3 * V_4 = F_12 ( V_13 ) ;
V_4 -> V_12 = V_11 + V_13 -> V_17 * V_18 ;
return 0 ;
}
static int F_13 ( struct V_16 * V_13 )
{
return 0 ;
}
static int F_14 ( struct V_16 * V_13 , unsigned int V_19 )
{
V_13 -> V_17 = V_19 ;
return F_11 ( V_13 ) ;
}
static int F_15 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
T_2 V_22 ;
T_2 V_23 ;
T_2 V_24 ;
int V_25 ;
T_2 V_26 = V_4 -> V_27 ;
unsigned long V_28 = 1 ;
unsigned long V_29 ;
struct V_30 * V_31 = & V_21 -> V_31 ;
V_22 = F_2 ( V_4 , V_32 ) ;
if ( ( V_22 & V_26 ) != ( V_4 -> V_33 & V_26 ) ) {
if ( V_22 == V_34 ) {
F_6 ( V_4 , V_32 , V_4 -> V_33 ) ;
V_22 = F_2 ( V_4 , V_32 ) ;
}
}
if ( V_22 & V_35 ) {
if ( V_4 -> V_33 & V_35 )
return 0 ;
F_16 ( V_31 , L_4 ) ;
return - V_36 ;
}
V_24 = V_22 & V_37 ;
V_23 = ( V_22 & V_38 ) >> 16 ;
if ( V_23 < V_24 )
V_28 = F_17 ( V_24 - V_23 ) ;
V_29 = F_18 ( V_24 ) ;
if ( ! V_29 ) {
F_16 ( V_31 ,
L_5 ) ;
return - V_36 ;
}
if ( ( V_29 / 4 ) >= V_28 )
V_4 -> V_15 = V_29 / 4 ;
else if ( ( V_29 / 2 ) >= V_28 )
V_4 -> V_15 = V_29 / 2 ;
else
V_4 -> V_15 = V_28 ;
if ( V_29 < V_28 + 4 )
F_19 ( V_31 ,
L_6 ) ;
if ( ( V_22 & V_39 ) && V_4 -> V_1 ) {
V_25 = F_20 ( V_4 -> V_1 , F_1 ,
V_40 | V_41 |
V_42 ,
V_21 -> V_43 , V_4 ) ;
if ( V_25 )
return V_25 ;
}
if ( ( V_22 & V_4 -> V_27 ) != ( V_4 -> V_33 & V_4 -> V_27 ) )
F_19 ( V_31 ,
L_7 ,
V_22 & V_4 -> V_27 , V_4 -> V_33 & V_4 -> V_27 ) ;
F_21 ( & V_4 -> V_14 , F_7 , ( unsigned long ) V_4 ) ;
F_10 ( & V_4 -> V_14 , V_11 + V_28 ) ;
if ( F_22 ( & V_4 -> V_13 , 0 , V_31 ) )
F_22 ( & V_4 -> V_13 , V_15 , V_31 ) ;
F_23 ( & V_4 -> V_13 , V_4 -> V_44 ) ;
V_25 = F_24 ( & V_4 -> V_13 ) ;
if ( V_25 )
goto V_45;
V_4 -> V_12 = V_11 + V_4 -> V_13 . V_17 * V_18 ;
return 0 ;
V_45:
F_25 ( & V_4 -> V_14 ) ;
return V_25 ;
}
static int F_26 ( struct V_46 * V_47 , struct V_3 * V_4 )
{
T_2 V_48 = 0 ;
T_2 V_49 = V_50 ;
const char * V_22 ;
V_4 -> V_1 = F_27 ( V_47 , 0 ) ;
if ( ! V_4 -> V_1 )
F_19 ( V_4 -> V_13 . V_51 , L_8 ) ;
if ( ! F_28 ( V_47 , L_9 , 0 ,
& V_49 ) ) {
if ( ! V_49 || V_49 > V_50 )
V_49 = V_50 ;
if ( ! F_28 ( V_47 , L_10 ,
0 , & V_48 ) ) {
if ( V_48 >= V_49 )
V_48 = V_49 - 1 ;
}
}
V_48 = F_29 ( V_48 ) ;
V_49 = F_29 ( V_49 ) ;
V_4 -> V_27 = 0x3FFFFFFF ;
V_4 -> V_33 = 0 ;
if ( ! F_30 ( V_47 , L_11 , & V_22 ) &&
! strcmp ( V_22 , L_12 ) ) {
V_4 -> V_33 |= V_39 ;
V_4 -> V_27 &= ~ V_52 ;
} else {
V_4 -> V_33 |= V_53 ;
}
if ( ! F_30 ( V_47 , L_13 , & V_22 ) &&
! strcmp ( V_22 , L_14 ) )
V_4 -> V_33 |= V_52 ;
if ( F_31 ( V_47 , L_15 ) ) {
V_4 -> V_33 |= V_35 ;
V_4 -> V_27 &= V_35 ;
}
if ( F_31 ( V_47 , L_16 ) )
V_4 -> V_33 |= V_54 ;
if ( F_31 ( V_47 , L_17 ) )
V_4 -> V_33 |= V_55 ;
V_4 -> V_33 |= V_49 | ( ( V_49 - V_48 ) << 16 ) ;
return 0 ;
}
static inline int F_26 ( struct V_46 * V_47 , struct V_3 * V_4 )
{
return 0 ;
}
static int T_3 F_32 ( struct V_20 * V_21 )
{
struct V_56 * V_57 ;
int V_25 ;
struct V_3 * V_4 ;
V_4 = F_33 ( & V_21 -> V_31 , sizeof( * V_4 ) , V_58 ) ;
if ( ! V_4 )
return - V_59 ;
V_4 -> V_33 = ( V_60 * 256 ) | V_53 | V_38 |
V_55 | V_54 ;
V_4 -> V_27 = 0x3FFFFFFF ;
V_4 -> V_44 = V_44 ;
V_4 -> V_13 . V_51 = & V_21 -> V_31 ;
V_4 -> V_13 . V_61 = & V_62 ;
V_4 -> V_13 . V_63 = & V_64 ;
V_4 -> V_13 . V_17 = V_65 ;
V_4 -> V_13 . V_66 = 1 ;
V_4 -> V_13 . V_67 = 0xFFFF ;
V_57 = F_34 ( V_21 , V_68 , 0 ) ;
V_4 -> V_69 = F_35 ( & V_21 -> V_31 , V_57 ) ;
if ( F_36 ( V_4 -> V_69 ) )
return F_37 ( V_4 -> V_69 ) ;
if ( V_21 -> V_31 . V_70 ) {
V_25 = F_26 ( V_21 -> V_31 . V_70 , V_4 ) ;
if ( V_25 )
return V_25 ;
}
V_25 = F_15 ( V_21 , V_4 ) ;
if ( V_25 )
return V_25 ;
F_38 ( V_21 , V_4 ) ;
F_39 ( L_18 ,
V_4 -> V_13 . V_17 , V_4 -> V_44 ) ;
return 0 ;
}
static int T_4 F_40 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_41 ( V_21 ) ;
F_42 ( & V_4 -> V_13 ) ;
F_43 ( L_19 ) ;
F_25 ( & V_4 -> V_14 ) ;
return 0 ;
}
