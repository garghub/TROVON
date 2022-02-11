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
F_7 ( & V_2 -> V_8 ) ;
V_2 -> V_7 |= V_4 ;
F_8 ( & V_2 -> V_8 ) ;
F_5 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_4 )
{
F_7 ( & V_2 -> V_8 ) ;
V_2 -> V_7 &= ~ V_4 ;
F_8 ( & V_2 -> V_8 ) ;
F_5 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_9 )
{
unsigned int V_10 ;
V_10 = V_11 | V_12 |
V_13 | V_14 ;
F_3 ( V_9 , V_15 , V_10 ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_21 ;
struct V_22 * V_23 = V_17 -> V_24 . V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
const T_2 * V_30 ;
T_1 V_4 ;
int V_31 , V_32 ;
int V_33 , V_34 ;
int V_35 = 0 , V_36 = 0 , V_37 ;
int V_38 = 0 ;
if ( ! V_17 -> V_24 . V_25 ) {
F_12 ( & V_17 -> V_24 , L_1 ) ;
return - V_39 ;
}
V_23 = F_13 ( V_17 -> V_24 . V_25 , L_2 ) ;
F_14 ( V_23 , L_3 , & V_35 ) ;
F_14 ( V_23 , L_4 , & V_38 ) ;
V_23 = F_13 ( V_17 -> V_24 . V_25 , L_5 ) ;
F_15 (node, L_6 , prop, cur, val) {
V_36 ++ ;
if ( V_4 > 7 ) {
F_12 ( & V_17 -> V_24 , L_7 ,
V_4 ) ;
return - V_39 ;
}
}
V_37 = V_35 + V_36 ;
if ( V_37 > 8 ) {
F_12 ( & V_17 -> V_24 , L_8 ) ;
return - V_39 ;
}
if ( V_37 == 0 ) {
F_12 ( & V_17 -> V_24 , L_9 ) ;
return - V_39 ;
}
if ( V_38 * 2 + 2 + V_36 > 16 ) {
F_12 ( & V_17 -> V_24 , L_10 ) ;
return - V_39 ;
}
V_20 = F_16 ( V_17 , V_40 , 0 ) ;
if ( ! V_20 ) {
F_12 ( & V_17 -> V_24 , L_11 ) ;
return - V_39 ;
}
V_18 = F_17 ( & V_17 -> V_24 ,
sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_18 ) {
F_12 ( & V_17 -> V_24 , L_12 ) ;
return - V_42 ;
}
V_18 -> V_24 = & V_17 -> V_24 ;
V_31 = F_18 ( V_17 , 0 ) ;
if ( V_31 < 0 ) {
F_12 ( & V_17 -> V_24 , L_13 ) ;
goto V_43;
} else
V_18 -> V_44 = V_31 ;
V_20 = F_19 ( & V_17 -> V_24 ,
V_20 -> V_45 , F_20 ( V_20 ) , V_17 -> V_46 ) ;
if ( ! V_20 ) {
F_12 ( & V_17 -> V_24 , L_14 ) ;
return - V_47 ;
}
V_18 -> V_48 = F_21 ( & V_17 -> V_24 ,
V_20 -> V_45 , F_20 ( V_20 ) ) ;
if ( ! V_18 -> V_48 ) {
F_12 ( & V_17 -> V_24 , L_15 ) ;
return - V_42 ;
}
V_18 -> V_5 = F_22 ( & V_17 -> V_24 ,
V_18 -> V_48 , & V_49 ) ;
if ( F_23 ( V_18 -> V_5 ) ) {
F_12 ( & V_17 -> V_24 , L_16 ) ;
V_31 = F_24 ( V_18 -> V_5 ) ;
goto V_43;
}
F_25 ( & V_18 -> V_8 ) ;
F_26 ( & V_17 -> V_24 ) ;
F_27 ( & V_17 -> V_24 ) ;
V_21 = F_28 ( & V_17 -> V_24 , L_17 ) ;
if ( F_23 ( V_21 ) ) {
F_12 ( & V_17 -> V_24 , L_18 ) ;
V_31 = F_24 ( V_21 ) ;
goto V_50;
}
V_34 = F_29 ( V_21 ) ;
F_30 ( V_21 ) ;
V_33 = V_34 / V_51 ;
if ( V_33 < V_52 ) {
F_12 ( & V_17 -> V_24 , L_19 ) ;
V_31 = - V_39 ;
goto V_50;
}
V_33 = V_33 - 1 ;
F_3 ( V_18 , V_53 , V_33 ) ;
V_32 = V_54 |
V_55 |
V_56 |
V_57 ;
F_3 ( V_18 , V_58 , V_32 ) ;
F_10 ( V_18 ) ;
V_32 = F_1 ( V_18 , V_58 ) ;
V_32 |= V_59 ;
F_3 ( V_18 , V_58 , V_32 ) ;
V_18 -> V_60 = 0 ;
V_18 -> V_61 = - 1 ;
V_18 -> V_62 = - 1 ;
if ( V_35 > 0 ) {
V_18 -> V_61 = V_18 -> V_60 ;
V_27 = & V_18 -> V_63 [ V_18 -> V_60 ++ ] ;
V_27 -> V_46 = L_20 ;
V_27 -> V_64 = L_21 ;
V_27 -> V_65 = & V_18 ;
V_27 -> V_66 = sizeof( V_18 ) ;
}
if ( V_36 > 0 ) {
V_18 -> V_62 = V_18 -> V_60 ;
V_27 = & V_18 -> V_63 [ V_18 -> V_60 ++ ] ;
V_27 -> V_46 = L_22 ;
V_27 -> V_64 = L_23 ;
V_27 -> V_65 = & V_18 ;
V_27 -> V_66 = sizeof( V_18 ) ;
}
V_31 = F_31 ( & V_17 -> V_24 , V_17 -> V_67 , V_18 -> V_63 ,
V_18 -> V_60 , NULL , 0 , NULL ) ;
if ( V_31 < 0 )
goto V_50;
F_32 ( & V_17 -> V_24 , true ) ;
F_33 ( V_17 , V_18 ) ;
return 0 ;
V_50:
F_34 ( & V_17 -> V_24 ) ;
F_35 ( & V_17 -> V_24 ) ;
V_43:
return V_31 ;
}
static int F_36 ( struct V_16 * V_17 )
{
struct V_1 * V_18 = F_37 ( V_17 ) ;
F_3 ( V_18 , V_6 , 0x00 ) ;
F_34 ( & V_17 -> V_24 ) ;
F_35 ( & V_17 -> V_24 ) ;
F_38 ( V_18 -> V_24 ) ;
return 0 ;
}
static int F_39 ( struct V_68 * V_24 )
{
struct V_1 * V_69 = F_40 ( V_24 ) ;
F_3 ( V_69 , V_6 , 0x00 ) ;
F_34 ( V_24 ) ;
return 0 ;
}
static int F_41 ( struct V_68 * V_24 )
{
struct V_1 * V_69 = F_40 ( V_24 ) ;
unsigned int V_70 , V_32 ;
F_27 ( V_24 ) ;
V_32 = V_54 | V_55 |
V_56 | V_57 ;
F_3 ( V_69 , V_58 , V_32 ) ;
F_10 ( V_69 ) ;
F_5 ( V_69 ) ;
V_70 = F_1 ( V_69 , V_58 ) ;
F_3 ( V_69 , V_58 ,
( V_70 | V_59 ) ) ;
return 0 ;
}
