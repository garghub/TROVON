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
V_2 -> V_8 = V_4 ;
if ( V_2 -> V_9 )
F_7 ( & V_2 -> V_10 ) ;
else if ( ! V_2 -> V_11 )
F_3 ( V_2 , V_12 , V_4 ) ;
F_8 ( & V_2 -> V_7 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_13 ) ;
T_1 V_3 ;
F_3 ( V_2 , V_12 , 0 ) ;
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
F_16 ( V_3 & V_15 ) ;
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
static void F_20 ( struct V_1 * V_17 )
{
unsigned int V_18 ;
V_18 = V_19 | V_20 |
V_21 | V_22 ;
F_3 ( V_17 , V_23 , V_18 ) ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_29 ;
struct V_30 * V_31 = V_25 -> V_32 . V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
const T_2 * V_38 ;
T_1 V_4 ;
int V_39 , V_40 ;
int V_41 ;
int V_42 = 0 , V_43 = 0 , V_44 ;
int V_45 = 0 ;
if ( ! V_25 -> V_32 . V_33 ) {
F_22 ( & V_25 -> V_32 , L_1 ) ;
return - V_46 ;
}
V_31 = F_23 ( V_25 -> V_32 . V_33 , L_2 ) ;
F_24 ( V_31 , L_3 , & V_42 ) ;
F_24 ( V_31 , L_4 , & V_45 ) ;
V_31 = F_23 ( V_25 -> V_32 . V_33 , L_5 ) ;
F_25 (node, L_6 , prop, cur, val) {
V_43 ++ ;
if ( V_4 > 7 ) {
F_22 ( & V_25 -> V_32 , L_7 ,
V_4 ) ;
return - V_46 ;
}
}
V_44 = V_42 + V_43 ;
if ( V_44 > 8 ) {
F_22 ( & V_25 -> V_32 , L_8 ) ;
return - V_46 ;
}
if ( V_44 == 0 ) {
F_22 ( & V_25 -> V_32 , L_9 ) ;
return - V_46 ;
}
if ( V_45 * 2 + 2 + V_43 > 16 ) {
F_22 ( & V_25 -> V_32 , L_10 ) ;
return - V_46 ;
}
V_28 = F_26 ( V_25 , V_47 , 0 ) ;
if ( ! V_28 ) {
F_22 ( & V_25 -> V_32 , L_11 ) ;
return - V_46 ;
}
V_26 = F_27 ( & V_25 -> V_32 ,
sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_26 ) {
F_22 ( & V_25 -> V_32 , L_12 ) ;
return - V_49 ;
}
V_26 -> V_32 = & V_25 -> V_32 ;
V_39 = F_28 ( V_25 , 0 ) ;
if ( V_39 < 0 ) {
F_22 ( & V_25 -> V_32 , L_13 ) ;
goto V_50;
} else
V_26 -> V_51 = V_39 ;
V_28 = F_29 ( & V_25 -> V_32 ,
V_28 -> V_52 , F_30 ( V_28 ) , V_25 -> V_53 ) ;
if ( ! V_28 ) {
F_22 ( & V_25 -> V_32 , L_14 ) ;
return - V_54 ;
}
V_26 -> V_55 = F_31 ( & V_25 -> V_32 ,
V_28 -> V_52 , F_30 ( V_28 ) ) ;
if ( ! V_26 -> V_55 ) {
F_22 ( & V_25 -> V_32 , L_15 ) ;
return - V_49 ;
}
V_26 -> V_5 = F_32 ( & V_25 -> V_32 ,
V_26 -> V_55 , & V_56 ) ;
if ( F_33 ( V_26 -> V_5 ) ) {
F_22 ( & V_25 -> V_32 , L_16 ) ;
V_39 = F_34 ( V_26 -> V_5 ) ;
goto V_50;
}
F_35 ( & V_26 -> V_7 ) ;
F_36 ( & V_26 -> V_10 ) ;
F_37 ( & V_25 -> V_32 ) ;
F_38 ( & V_25 -> V_32 ) ;
V_29 = F_39 ( & V_25 -> V_32 , L_17 ) ;
if ( F_33 ( V_29 ) ) {
F_22 ( & V_25 -> V_32 , L_18 ) ;
V_39 = F_34 ( V_29 ) ;
goto V_57;
}
V_41 = F_40 ( V_29 ) ;
F_41 ( V_29 ) ;
V_26 -> V_58 = V_41 / V_59 ;
V_26 -> V_58 -- ;
F_3 ( V_26 , V_60 , V_26 -> V_58 ) ;
V_40 = V_61 |
V_62 ;
if ( V_42 > 0 )
V_40 |= V_63 | V_64 ;
F_3 ( V_26 , V_65 , V_40 ) ;
if ( V_42 > 0 )
F_20 ( V_26 ) ;
V_40 = F_1 ( V_26 , V_65 ) ;
V_40 |= V_66 ;
F_3 ( V_26 , V_65 , V_40 ) ;
V_26 -> V_67 = 0 ;
V_26 -> V_68 = - 1 ;
V_26 -> V_69 = - 1 ;
if ( V_42 > 0 ) {
V_26 -> V_68 = V_26 -> V_67 ;
V_35 = & V_26 -> V_70 [ V_26 -> V_67 ++ ] ;
V_35 -> V_53 = L_19 ;
V_35 -> V_71 = L_20 ;
V_35 -> V_72 = & V_26 ;
V_35 -> V_73 = sizeof( V_26 ) ;
}
if ( V_43 > 0 ) {
V_26 -> V_69 = V_26 -> V_67 ;
V_35 = & V_26 -> V_70 [ V_26 -> V_67 ++ ] ;
V_35 -> V_53 = L_21 ;
V_35 -> V_71 = L_22 ;
V_35 -> V_72 = & V_26 ;
V_35 -> V_73 = sizeof( V_26 ) ;
}
V_39 = F_42 ( & V_25 -> V_32 , V_25 -> V_74 , V_26 -> V_70 ,
V_26 -> V_67 , NULL , 0 , NULL ) ;
if ( V_39 < 0 )
goto V_57;
F_43 ( & V_25 -> V_32 , true ) ;
F_44 ( V_25 , V_26 ) ;
return 0 ;
V_57:
F_45 ( & V_25 -> V_32 ) ;
F_46 ( & V_25 -> V_32 ) ;
V_50:
return V_39 ;
}
static int F_47 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_48 ( V_25 ) ;
F_3 ( V_26 , V_12 , 0x00 ) ;
F_45 ( & V_25 -> V_32 ) ;
F_46 ( & V_25 -> V_32 ) ;
F_49 ( V_26 -> V_32 ) ;
return 0 ;
}
static int F_50 ( struct V_75 * V_32 )
{
struct V_1 * V_76 = F_51 ( V_32 ) ;
F_3 ( V_76 , V_12 , 0x00 ) ;
F_45 ( V_32 ) ;
return 0 ;
}
static int F_52 ( struct V_75 * V_32 )
{
struct V_1 * V_76 = F_51 ( V_32 ) ;
unsigned int V_77 , V_40 ;
F_38 ( V_32 ) ;
V_40 = V_61 | V_62 ;
if ( V_76 -> V_68 != - 1 )
V_40 |= V_64 | V_63 ;
F_3 ( V_76 , V_65 , V_40 ) ;
if ( V_76 -> V_68 != - 1 )
F_20 ( V_76 ) ;
V_77 = F_1 ( V_76 , V_65 ) ;
F_3 ( V_76 , V_65 ,
( V_77 | V_66 ) ) ;
F_3 ( V_76 , V_60 , V_76 -> V_58 ) ;
return 0 ;
}
