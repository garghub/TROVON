static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
return V_4 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_6 ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_8 |= V_4 ;
if ( V_2 -> V_9 )
F_7 ( & V_2 -> V_10 ) ;
else if ( ! V_2 -> V_11 )
F_3 ( V_2 , V_12 , V_2 -> V_8 ) ;
F_8 ( & V_2 -> V_7 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_13 ) ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_14 ) ;
if ( V_3 & V_15 ) {
V_2 -> V_9 = true ;
F_11 ( & V_2 -> V_10 , & V_13 ,
V_16 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_13 () ;
F_14 ( & V_2 -> V_7 ) ;
F_15 ( & V_2 -> V_10 , & V_13 ) ;
V_3 = F_1 ( V_2 , V_14 ) ;
F_16 ( ( V_3 & V_15 ) && ! ( V_3 & V_17 ) ) ;
V_2 -> V_9 = false ;
}
V_2 -> V_11 = true ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_4 )
{
F_14 ( & V_2 -> V_7 ) ;
F_9 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_4 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_11 = false ;
F_3 ( V_2 , V_12 , V_2 -> V_8 ) ;
F_8 ( & V_2 -> V_7 , V_6 ) ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_6 ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_8 &= ~ V_4 ;
F_3 ( V_2 , V_12 , V_2 -> V_8 ) ;
F_8 ( & V_2 -> V_7 , V_6 ) ;
}
static void F_20 ( struct V_1 * V_18 )
{
unsigned int V_19 ;
V_19 = V_20 | V_21 |
V_22 | V_23 ;
F_3 ( V_18 , V_24 , V_19 ) ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_1 * V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_30 ;
struct V_31 * V_32 = V_26 -> V_33 . V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
const T_2 * V_39 ;
T_1 V_4 ;
int V_40 , V_41 ;
int V_42 ;
int V_43 = 0 , V_44 = 0 , V_45 ;
int V_46 = 0 ;
if ( ! V_26 -> V_33 . V_34 ) {
F_22 ( & V_26 -> V_33 , L_1 ) ;
return - V_47 ;
}
V_32 = F_23 ( V_26 -> V_33 . V_34 , L_2 ) ;
F_24 ( V_32 , L_3 , & V_43 ) ;
F_24 ( V_32 , L_4 , & V_46 ) ;
V_32 = F_23 ( V_26 -> V_33 . V_34 , L_5 ) ;
F_25 (node, L_6 , prop, cur, val) {
V_44 ++ ;
if ( V_4 > 7 ) {
F_22 ( & V_26 -> V_33 , L_7 ,
V_4 ) ;
return - V_47 ;
}
}
V_45 = V_43 + V_44 ;
if ( V_45 > 8 ) {
F_22 ( & V_26 -> V_33 , L_8 ) ;
return - V_47 ;
}
if ( V_45 == 0 ) {
F_22 ( & V_26 -> V_33 , L_9 ) ;
return - V_47 ;
}
if ( V_46 * 2 + 2 + V_44 > 16 ) {
F_22 ( & V_26 -> V_33 , L_10 ) ;
return - V_47 ;
}
V_27 = F_26 ( & V_26 -> V_33 ,
sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_27 ) {
F_22 ( & V_26 -> V_33 , L_11 ) ;
return - V_49 ;
}
V_27 -> V_33 = & V_26 -> V_33 ;
V_40 = F_27 ( V_26 , 0 ) ;
if ( V_40 < 0 ) {
F_22 ( & V_26 -> V_33 , L_12 ) ;
goto V_50;
} else
V_27 -> V_51 = V_40 ;
V_29 = F_28 ( V_26 , V_52 , 0 ) ;
V_27 -> V_53 = F_29 ( & V_26 -> V_33 , V_29 ) ;
if ( F_30 ( V_27 -> V_53 ) )
return F_31 ( V_27 -> V_53 ) ;
V_27 -> V_5 = F_32 ( & V_26 -> V_33 ,
V_27 -> V_53 , & V_54 ) ;
if ( F_30 ( V_27 -> V_5 ) ) {
F_22 ( & V_26 -> V_33 , L_13 ) ;
V_40 = F_31 ( V_27 -> V_5 ) ;
goto V_50;
}
F_33 ( & V_27 -> V_7 ) ;
F_34 ( & V_27 -> V_10 ) ;
F_35 ( & V_26 -> V_33 ) ;
F_36 ( & V_26 -> V_33 ) ;
V_30 = F_37 ( & V_26 -> V_33 , L_14 ) ;
if ( F_30 ( V_30 ) ) {
F_22 ( & V_26 -> V_33 , L_15 ) ;
V_40 = F_31 ( V_30 ) ;
goto V_55;
}
V_42 = F_38 ( V_30 ) ;
F_39 ( V_30 ) ;
V_27 -> V_56 = V_42 / V_57 ;
V_27 -> V_56 -- ;
F_3 ( V_27 , V_58 , V_27 -> V_56 ) ;
V_41 = V_59 | V_60 ;
F_3 ( V_27 , V_61 , V_41 ) ;
if ( V_43 > 0 ) {
V_27 -> V_43 = V_43 ;
if ( V_43 == 5 )
V_41 |= V_62 | V_63 ;
else
V_41 |= V_64 | V_63 ;
F_20 ( V_27 ) ;
}
V_41 |= V_65 ;
F_3 ( V_27 , V_61 , V_41 ) ;
V_27 -> V_66 = 0 ;
V_27 -> V_67 = - 1 ;
V_27 -> V_68 = - 1 ;
if ( V_43 > 0 ) {
V_27 -> V_67 = V_27 -> V_66 ;
V_36 = & V_27 -> V_69 [ V_27 -> V_66 ++ ] ;
V_36 -> V_70 = L_16 ;
V_36 -> V_71 = L_17 ;
V_36 -> V_72 = & V_27 ;
V_36 -> V_73 = sizeof( V_27 ) ;
}
if ( V_44 > 0 ) {
V_27 -> V_68 = V_27 -> V_66 ;
V_36 = & V_27 -> V_69 [ V_27 -> V_66 ++ ] ;
V_36 -> V_70 = L_18 ;
V_36 -> V_71 = L_19 ;
V_36 -> V_72 = & V_27 ;
V_36 -> V_73 = sizeof( V_27 ) ;
}
V_40 = F_40 ( & V_26 -> V_33 , V_26 -> V_74 , V_27 -> V_69 ,
V_27 -> V_66 , NULL , 0 , NULL ) ;
if ( V_40 < 0 )
goto V_55;
F_41 ( & V_26 -> V_33 , true ) ;
F_42 ( V_26 , V_27 ) ;
return 0 ;
V_55:
F_43 ( & V_26 -> V_33 ) ;
F_44 ( & V_26 -> V_33 ) ;
V_50:
return V_40 ;
}
static int F_45 ( struct V_25 * V_26 )
{
struct V_1 * V_27 = F_46 ( V_26 ) ;
F_3 ( V_27 , V_12 , 0x00 ) ;
F_43 ( & V_26 -> V_33 ) ;
F_44 ( & V_26 -> V_33 ) ;
F_47 ( V_27 -> V_33 ) ;
return 0 ;
}
static int F_48 ( struct V_75 * V_33 )
{
struct V_1 * V_76 = F_49 ( V_33 ) ;
F_3 ( V_76 , V_12 , 0x00 ) ;
F_43 ( V_33 ) ;
return 0 ;
}
static int F_50 ( struct V_75 * V_33 )
{
struct V_1 * V_76 = F_49 ( V_33 ) ;
T_1 V_41 ;
F_36 ( V_33 ) ;
V_41 = V_59 | V_60 ;
F_3 ( V_76 , V_61 , V_41 ) ;
if ( V_76 -> V_67 != - 1 ) {
if ( V_76 -> V_43 == 5 )
V_41 |= V_62 | V_63 ;
else
V_41 |= V_64 | V_63 ;
F_20 ( V_76 ) ;
}
V_41 |= V_65 ;
F_3 ( V_76 , V_61 , V_41 ) ;
F_3 ( V_76 , V_58 , V_76 -> V_56 ) ;
return 0 ;
}
