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
V_2 -> V_8 |= V_4 ;
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
V_26 = F_26 ( & V_25 -> V_32 ,
sizeof( struct V_1 ) , V_47 ) ;
if ( ! V_26 ) {
F_22 ( & V_25 -> V_32 , L_11 ) ;
return - V_48 ;
}
V_26 -> V_32 = & V_25 -> V_32 ;
V_39 = F_27 ( V_25 , 0 ) ;
if ( V_39 < 0 ) {
F_22 ( & V_25 -> V_32 , L_12 ) ;
goto V_49;
} else
V_26 -> V_50 = V_39 ;
V_28 = F_28 ( V_25 , V_51 , 0 ) ;
V_26 -> V_52 = F_29 ( & V_25 -> V_32 , V_28 ) ;
if ( F_30 ( V_26 -> V_52 ) )
return F_31 ( V_26 -> V_52 ) ;
V_26 -> V_5 = F_32 ( & V_25 -> V_32 ,
V_26 -> V_52 , & V_53 ) ;
if ( F_30 ( V_26 -> V_5 ) ) {
F_22 ( & V_25 -> V_32 , L_13 ) ;
V_39 = F_31 ( V_26 -> V_5 ) ;
goto V_49;
}
F_33 ( & V_26 -> V_7 ) ;
F_34 ( & V_26 -> V_10 ) ;
F_35 ( & V_25 -> V_32 ) ;
F_36 ( & V_25 -> V_32 ) ;
V_29 = F_37 ( & V_25 -> V_32 , L_14 ) ;
if ( F_30 ( V_29 ) ) {
F_22 ( & V_25 -> V_32 , L_15 ) ;
V_39 = F_31 ( V_29 ) ;
goto V_54;
}
V_41 = F_38 ( V_29 ) ;
F_39 ( V_29 ) ;
V_26 -> V_55 = V_41 / V_56 ;
V_26 -> V_55 -- ;
F_3 ( V_26 , V_57 , V_26 -> V_55 ) ;
V_40 = V_58 | V_59 ;
F_3 ( V_26 , V_60 , V_40 ) ;
if ( V_42 > 0 ) {
V_26 -> V_42 = V_42 ;
if ( V_42 == 5 )
V_40 |= V_61 | V_62 ;
else
V_40 |= V_63 | V_62 ;
F_20 ( V_26 ) ;
}
V_40 |= V_64 ;
F_3 ( V_26 , V_60 , V_40 ) ;
V_26 -> V_65 = 0 ;
V_26 -> V_66 = - 1 ;
V_26 -> V_67 = - 1 ;
if ( V_42 > 0 ) {
V_26 -> V_66 = V_26 -> V_65 ;
V_35 = & V_26 -> V_68 [ V_26 -> V_65 ++ ] ;
V_35 -> V_69 = L_16 ;
V_35 -> V_70 = L_17 ;
V_35 -> V_71 = & V_26 ;
V_35 -> V_72 = sizeof( V_26 ) ;
}
if ( V_43 > 0 ) {
V_26 -> V_67 = V_26 -> V_65 ;
V_35 = & V_26 -> V_68 [ V_26 -> V_65 ++ ] ;
V_35 -> V_69 = L_18 ;
V_35 -> V_70 = L_19 ;
V_35 -> V_71 = & V_26 ;
V_35 -> V_72 = sizeof( V_26 ) ;
}
V_39 = F_40 ( & V_25 -> V_32 , V_25 -> V_73 , V_26 -> V_68 ,
V_26 -> V_65 , NULL , 0 , NULL ) ;
if ( V_39 < 0 )
goto V_54;
F_41 ( & V_25 -> V_32 , true ) ;
F_42 ( V_25 , V_26 ) ;
return 0 ;
V_54:
F_43 ( & V_25 -> V_32 ) ;
F_44 ( & V_25 -> V_32 ) ;
V_49:
return V_39 ;
}
static int F_45 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_46 ( V_25 ) ;
F_3 ( V_26 , V_12 , 0x00 ) ;
F_43 ( & V_25 -> V_32 ) ;
F_44 ( & V_25 -> V_32 ) ;
F_47 ( V_26 -> V_32 ) ;
return 0 ;
}
static int F_48 ( struct V_74 * V_32 )
{
struct V_1 * V_75 = F_49 ( V_32 ) ;
F_3 ( V_75 , V_12 , 0x00 ) ;
F_43 ( V_32 ) ;
return 0 ;
}
static int F_50 ( struct V_74 * V_32 )
{
struct V_1 * V_75 = F_49 ( V_32 ) ;
T_1 V_40 ;
F_36 ( V_32 ) ;
V_40 = V_58 | V_59 ;
F_3 ( V_75 , V_60 , V_40 ) ;
if ( V_75 -> V_66 != - 1 ) {
if ( V_75 -> V_42 == 5 )
V_40 |= V_61 | V_62 ;
else
V_40 |= V_63 | V_62 ;
F_20 ( V_75 ) ;
}
V_40 |= V_64 ;
F_3 ( V_75 , V_60 , V_40 ) ;
F_3 ( V_75 , V_57 , V_75 -> V_55 ) ;
return 0 ;
}
