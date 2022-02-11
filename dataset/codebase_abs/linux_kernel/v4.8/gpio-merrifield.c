static void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_7 = V_3 / 32 ;
return V_6 -> V_8 + V_4 + V_7 * 4 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
void T_1 * V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
return ! ! ( F_4 ( V_9 ) & F_5 ( V_3 % 32 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_12 , * V_13 ;
unsigned long V_14 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_11 ) {
V_12 = F_1 ( V_2 , V_3 , V_16 ) ;
F_8 ( F_5 ( V_3 % 32 ) , V_12 ) ;
} else {
V_13 = F_1 ( V_2 , V_3 , V_17 ) ;
F_8 ( F_5 ( V_3 % 32 ) , V_13 ) ;
}
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_19 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
V_11 = F_4 ( V_18 ) ;
V_11 &= ~ F_5 ( V_3 % 32 ) ;
F_8 ( V_11 , V_18 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_19 ) ;
unsigned long V_14 ;
F_6 ( V_2 , V_3 , V_11 ) ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
V_11 = F_4 ( V_18 ) ;
V_11 |= F_5 ( V_3 % 32 ) ;
F_8 ( V_11 , V_18 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static void F_12 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_13 ( V_21 ) ;
T_3 V_22 = F_14 ( V_21 ) ;
void T_1 * V_23 = F_1 ( & V_6 -> V_2 , V_22 , V_24 ) ;
unsigned long V_14 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_22 % 32 ) , V_23 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_15 ( struct V_20 * V_21 , bool V_25 )
{
struct V_5 * V_6 = F_13 ( V_21 ) ;
T_3 V_22 = F_14 ( V_21 ) ;
void T_1 * V_26 = F_1 ( & V_6 -> V_2 , V_22 , V_27 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_25 )
V_11 = F_4 ( V_26 ) | F_5 ( V_22 % 32 ) ;
else
V_11 = F_4 ( V_26 ) & ~ F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_26 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_16 ( struct V_20 * V_21 )
{
F_15 ( V_21 , false ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
F_15 ( V_21 , true ) ;
}
static int F_18 ( struct V_20 * V_21 , unsigned int type )
{
struct V_1 * V_28 = F_13 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_28 ) ;
T_3 V_22 = F_14 ( V_21 ) ;
void T_1 * V_29 = F_1 ( & V_6 -> V_2 , V_22 , V_30 ) ;
void T_1 * V_31 = F_1 ( & V_6 -> V_2 , V_22 , V_32 ) ;
void T_1 * V_33 = F_1 ( & V_6 -> V_2 , V_22 , V_34 ) ;
void T_1 * V_35 = F_1 ( & V_6 -> V_2 , V_22 , V_36 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( type & V_37 )
V_11 = F_4 ( V_29 ) | F_5 ( V_22 % 32 ) ;
else
V_11 = F_4 ( V_29 ) & ~ F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_29 ) ;
if ( type & V_38 )
V_11 = F_4 ( V_31 ) | F_5 ( V_22 % 32 ) ;
else
V_11 = F_4 ( V_31 ) & ~ F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_31 ) ;
if ( type & V_39 )
V_11 = F_4 ( V_35 ) | F_5 ( V_22 % 32 ) ;
else
V_11 = F_4 ( V_35 ) & ~ F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_35 ) ;
if ( type & V_40 ) {
V_11 = F_4 ( V_33 ) | F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_33 ) ;
F_19 ( V_21 , V_41 ) ;
} else if ( type & V_42 ) {
V_11 = F_4 ( V_33 ) & ~ F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_33 ) ;
F_19 ( V_21 , V_43 ) ;
}
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 , unsigned int V_44 )
{
struct V_1 * V_28 = F_13 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_28 ) ;
T_3 V_22 = F_14 ( V_21 ) ;
void T_1 * V_45 = F_1 ( & V_6 -> V_2 , V_22 , V_46 ) ;
void T_1 * V_47 = F_1 ( & V_6 -> V_2 , V_22 , V_48 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_22 % 32 ) , V_47 ) ;
if ( V_44 )
V_11 = F_4 ( V_45 ) | F_5 ( V_22 % 32 ) ;
else
V_11 = F_4 ( V_45 ) & ~ F_5 ( V_22 % 32 ) ;
F_8 ( V_11 , V_45 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
F_21 ( V_6 -> V_49 , L_1 , V_44 ? L_2 : L_3 , V_22 ) ;
return 0 ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_1 * V_28 = F_23 ( V_51 ) ;
struct V_5 * V_6 = F_2 ( V_28 ) ;
struct V_52 * V_53 = F_24 ( V_51 ) ;
unsigned long V_54 , V_22 ;
F_25 ( V_53 , V_51 ) ;
for ( V_54 = 0 ; V_54 < V_6 -> V_2 . V_55 ; V_54 += 32 ) {
void T_1 * V_23 = F_1 ( & V_6 -> V_2 , V_54 , V_24 ) ;
void T_1 * V_26 = F_1 ( & V_6 -> V_2 , V_54 , V_27 ) ;
unsigned long V_56 , V_57 ;
V_56 = F_4 ( V_23 ) ;
V_57 = F_4 ( V_26 ) ;
V_56 &= V_57 ;
F_26 (gpio, &pending, 32 ) {
unsigned int V_58 ;
V_58 = F_27 ( V_28 -> V_59 , V_54 + V_22 ) ;
F_28 ( V_58 ) ;
}
}
F_29 ( V_53 , V_51 ) ;
}
static void F_30 ( struct V_5 * V_6 )
{
void T_1 * V_7 ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_6 -> V_2 . V_55 ; V_54 += 32 ) {
V_7 = F_1 ( & V_6 -> V_2 , V_54 , V_30 ) ;
F_8 ( 0 , V_7 ) ;
V_7 = F_1 ( & V_6 -> V_2 , V_54 , V_32 ) ;
F_8 ( 0 , V_7 ) ;
}
}
static int F_31 ( struct V_60 * V_61 , const struct V_62 * V_63 )
{
const struct V_64 * V_65 ;
struct V_5 * V_6 ;
T_3 V_66 , V_67 ;
void T_1 * V_54 ;
unsigned int V_68 ;
int V_69 ;
V_69 = F_32 ( V_61 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_33 ( V_61 , F_5 ( 1 ) | F_5 ( 0 ) , F_34 ( V_61 ) ) ;
if ( V_69 ) {
F_35 ( & V_61 -> V_49 , L_4 ) ;
return V_69 ;
}
V_54 = F_36 ( V_61 ) [ 1 ] ;
V_67 = F_4 ( V_54 ) ;
V_66 = F_4 ( sizeof( T_3 ) + V_54 ) ;
F_37 ( V_61 , F_5 ( 1 ) ) ;
V_6 = F_38 ( & V_61 -> V_49 , sizeof( * V_6 ) , V_70 ) ;
if ( ! V_6 ) {
F_35 ( & V_61 -> V_49 , L_5 ) ;
return - V_71 ;
}
V_6 -> V_49 = & V_61 -> V_49 ;
V_6 -> V_8 = F_36 ( V_61 ) [ 0 ] ;
V_6 -> V_2 . V_72 = F_39 ( & V_61 -> V_49 ) ;
V_6 -> V_2 . V_73 = & V_61 -> V_49 ;
V_6 -> V_2 . V_74 = V_75 ;
V_6 -> V_2 . free = V_76 ;
V_6 -> V_2 . V_77 = F_10 ;
V_6 -> V_2 . V_78 = F_11 ;
V_6 -> V_2 . V_79 = F_3 ;
V_6 -> V_2 . V_80 = F_6 ;
V_6 -> V_2 . V_54 = V_66 ;
V_6 -> V_2 . V_55 = V_81 ;
V_6 -> V_2 . V_82 = false ;
F_40 ( & V_6 -> V_15 ) ;
F_41 ( V_61 , V_6 ) ;
V_69 = F_42 ( & V_61 -> V_49 , & V_6 -> V_2 , V_6 ) ;
if ( V_69 ) {
F_35 ( & V_61 -> V_49 , L_6 , V_69 ) ;
return V_69 ;
}
for ( V_68 = 0 ; V_68 < F_43 ( V_83 ) ; V_68 ++ ) {
V_65 = & V_83 [ V_68 ] ;
V_69 = F_44 ( & V_6 -> V_2 ,
L_7 ,
V_65 -> V_66 ,
V_65 -> V_84 ,
V_65 -> V_85 ) ;
if ( V_69 ) {
F_35 ( & V_61 -> V_49 , L_8 ) ;
return V_69 ;
}
}
V_69 = F_45 ( & V_6 -> V_2 , & V_86 , V_67 ,
V_87 , V_88 ) ;
if ( V_69 ) {
F_35 ( & V_61 -> V_49 , L_9 ) ;
return V_69 ;
}
F_30 ( V_6 ) ;
F_46 ( & V_6 -> V_2 , & V_86 , V_61 -> V_58 ,
F_22 ) ;
return 0 ;
}
