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
void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 , V_2 -> V_7 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_8 ;
F_7 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_7 = F_1 ( V_2 , V_6 ) ;
V_2 -> V_7 |= V_4 ;
F_5 ( V_2 ) ;
F_8 ( & V_2 -> V_9 , V_8 ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_8 ;
F_7 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_7 = F_1 ( V_2 , V_6 ) ;
V_2 -> V_7 &= ~ V_4 ;
F_5 ( V_2 ) ;
F_8 ( & V_2 -> V_9 , V_8 ) ;
}
static void F_10 ( struct V_1 * V_10 )
{
unsigned int V_11 ;
V_11 = V_12 | V_13 |
V_14 | V_15 ;
F_3 ( V_10 , V_16 , V_11 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_23 * V_24 = V_18 -> V_25 . V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
const T_2 * V_31 ;
T_1 V_4 ;
int V_32 , V_33 ;
int V_34 ;
int V_35 = 0 , V_36 = 0 , V_37 ;
int V_38 = 0 ;
if ( ! V_18 -> V_25 . V_26 ) {
F_12 ( & V_18 -> V_25 , L_1 ) ;
return - V_39 ;
}
V_24 = F_13 ( V_18 -> V_25 . V_26 , L_2 ) ;
F_14 ( V_24 , L_3 , & V_35 ) ;
F_14 ( V_24 , L_4 , & V_38 ) ;
V_24 = F_13 ( V_18 -> V_25 . V_26 , L_5 ) ;
F_15 (node, L_6 , prop, cur, val) {
V_36 ++ ;
if ( V_4 > 7 ) {
F_12 ( & V_18 -> V_25 , L_7 ,
V_4 ) ;
return - V_39 ;
}
}
V_37 = V_35 + V_36 ;
if ( V_37 > 8 ) {
F_12 ( & V_18 -> V_25 , L_8 ) ;
return - V_39 ;
}
if ( V_37 == 0 ) {
F_12 ( & V_18 -> V_25 , L_9 ) ;
return - V_39 ;
}
if ( V_38 * 2 + 2 + V_36 > 16 ) {
F_12 ( & V_18 -> V_25 , L_10 ) ;
return - V_39 ;
}
V_21 = F_16 ( V_18 , V_40 , 0 ) ;
if ( ! V_21 ) {
F_12 ( & V_18 -> V_25 , L_11 ) ;
return - V_39 ;
}
V_19 = F_17 ( & V_18 -> V_25 ,
sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_19 ) {
F_12 ( & V_18 -> V_25 , L_12 ) ;
return - V_42 ;
}
V_19 -> V_25 = & V_18 -> V_25 ;
V_32 = F_18 ( V_18 , 0 ) ;
if ( V_32 < 0 ) {
F_12 ( & V_18 -> V_25 , L_13 ) ;
goto V_43;
} else
V_19 -> V_44 = V_32 ;
V_21 = F_19 ( & V_18 -> V_25 ,
V_21 -> V_45 , F_20 ( V_21 ) , V_18 -> V_46 ) ;
if ( ! V_21 ) {
F_12 ( & V_18 -> V_25 , L_14 ) ;
return - V_47 ;
}
V_19 -> V_48 = F_21 ( & V_18 -> V_25 ,
V_21 -> V_45 , F_20 ( V_21 ) ) ;
if ( ! V_19 -> V_48 ) {
F_12 ( & V_18 -> V_25 , L_15 ) ;
return - V_42 ;
}
V_19 -> V_5 = F_22 ( & V_18 -> V_25 ,
V_19 -> V_48 , & V_49 ) ;
if ( F_23 ( V_19 -> V_5 ) ) {
F_12 ( & V_18 -> V_25 , L_16 ) ;
V_32 = F_24 ( V_19 -> V_5 ) ;
goto V_43;
}
F_25 ( & V_19 -> V_9 ) ;
F_26 ( & V_18 -> V_25 ) ;
F_27 ( & V_18 -> V_25 ) ;
V_22 = F_28 ( & V_18 -> V_25 , L_17 ) ;
if ( F_23 ( V_22 ) ) {
F_12 ( & V_18 -> V_25 , L_18 ) ;
V_32 = F_24 ( V_22 ) ;
goto V_50;
}
V_34 = F_29 ( V_22 ) ;
F_30 ( V_22 ) ;
V_19 -> V_51 = V_34 / V_52 ;
V_19 -> V_51 -- ;
F_3 ( V_19 , V_53 , V_19 -> V_51 ) ;
V_33 = V_54 |
V_55 ;
if ( V_35 > 0 )
V_33 |= V_56 | V_57 ;
F_3 ( V_19 , V_58 , V_33 ) ;
if ( V_35 > 0 )
F_10 ( V_19 ) ;
V_33 = F_1 ( V_19 , V_58 ) ;
V_33 |= V_59 ;
F_3 ( V_19 , V_58 , V_33 ) ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = - 1 ;
V_19 -> V_62 = - 1 ;
if ( V_35 > 0 ) {
V_19 -> V_61 = V_19 -> V_60 ;
V_28 = & V_19 -> V_63 [ V_19 -> V_60 ++ ] ;
V_28 -> V_46 = L_19 ;
V_28 -> V_64 = L_20 ;
V_28 -> V_65 = & V_19 ;
V_28 -> V_66 = sizeof( V_19 ) ;
}
if ( V_36 > 0 ) {
V_19 -> V_62 = V_19 -> V_60 ;
V_28 = & V_19 -> V_63 [ V_19 -> V_60 ++ ] ;
V_28 -> V_46 = L_21 ;
V_28 -> V_64 = L_22 ;
V_28 -> V_65 = & V_19 ;
V_28 -> V_66 = sizeof( V_19 ) ;
}
V_32 = F_31 ( & V_18 -> V_25 , V_18 -> V_67 , V_19 -> V_63 ,
V_19 -> V_60 , NULL , 0 , NULL ) ;
if ( V_32 < 0 )
goto V_50;
F_32 ( & V_18 -> V_25 , true ) ;
F_33 ( V_18 , V_19 ) ;
return 0 ;
V_50:
F_34 ( & V_18 -> V_25 ) ;
F_35 ( & V_18 -> V_25 ) ;
V_43:
return V_32 ;
}
static int F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = F_37 ( V_18 ) ;
F_3 ( V_19 , V_6 , 0x00 ) ;
F_34 ( & V_18 -> V_25 ) ;
F_35 ( & V_18 -> V_25 ) ;
F_38 ( V_19 -> V_25 ) ;
return 0 ;
}
static int F_39 ( struct V_68 * V_25 )
{
struct V_1 * V_69 = F_40 ( V_25 ) ;
F_3 ( V_69 , V_6 , 0x00 ) ;
F_34 ( V_25 ) ;
return 0 ;
}
static int F_41 ( struct V_68 * V_25 )
{
struct V_1 * V_69 = F_40 ( V_25 ) ;
unsigned int V_70 , V_33 ;
F_27 ( V_25 ) ;
V_33 = V_54 | V_55 ;
if ( V_69 -> V_61 != - 1 )
V_33 |= V_57 | V_56 ;
F_3 ( V_69 , V_58 , V_33 ) ;
if ( V_69 -> V_61 != - 1 )
F_10 ( V_69 ) ;
F_5 ( V_69 ) ;
V_70 = F_1 ( V_69 , V_58 ) ;
F_3 ( V_69 , V_58 ,
( V_70 | V_59 ) ) ;
F_3 ( V_69 , V_53 , V_69 -> V_51 ) ;
return 0 ;
}
