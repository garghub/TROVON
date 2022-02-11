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
static int F_12 ( struct V_1 * V_2 , unsigned int V_3 )
{
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_19 ) ;
return ( F_4 ( V_18 ) & F_5 ( V_3 % 32 ) ) ? V_20 : V_21 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_23 = F_1 ( V_2 , V_3 , V_24 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_22 )
V_11 = F_4 ( V_23 ) & ~ F_5 ( V_3 % 32 ) ;
else
V_11 = F_4 ( V_23 ) | F_5 ( V_3 % 32 ) ;
F_8 ( V_11 , V_23 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static void F_14 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
T_3 V_27 = F_16 ( V_26 ) ;
void T_1 * V_28 = F_1 ( & V_6 -> V_2 , V_27 , V_29 ) ;
unsigned long V_14 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_27 % 32 ) , V_28 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_17 ( struct V_25 * V_26 , bool V_30 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
T_3 V_27 = F_16 ( V_26 ) ;
void T_1 * V_31 = F_1 ( & V_6 -> V_2 , V_27 , V_32 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_30 )
V_11 = F_4 ( V_31 ) | F_5 ( V_27 % 32 ) ;
else
V_11 = F_4 ( V_31 ) & ~ F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_31 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_18 ( struct V_25 * V_26 )
{
F_17 ( V_26 , false ) ;
}
static void F_19 ( struct V_25 * V_26 )
{
F_17 ( V_26 , true ) ;
}
static int F_20 ( struct V_25 * V_26 , unsigned int type )
{
struct V_1 * V_33 = F_15 ( V_26 ) ;
struct V_5 * V_6 = F_2 ( V_33 ) ;
T_3 V_27 = F_16 ( V_26 ) ;
void T_1 * V_34 = F_1 ( & V_6 -> V_2 , V_27 , V_35 ) ;
void T_1 * V_36 = F_1 ( & V_6 -> V_2 , V_27 , V_37 ) ;
void T_1 * V_38 = F_1 ( & V_6 -> V_2 , V_27 , V_39 ) ;
void T_1 * V_40 = F_1 ( & V_6 -> V_2 , V_27 , V_41 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( type & V_42 )
V_11 = F_4 ( V_34 ) | F_5 ( V_27 % 32 ) ;
else
V_11 = F_4 ( V_34 ) & ~ F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_34 ) ;
if ( type & V_43 )
V_11 = F_4 ( V_36 ) | F_5 ( V_27 % 32 ) ;
else
V_11 = F_4 ( V_36 ) & ~ F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_36 ) ;
if ( type & V_44 )
V_11 = F_4 ( V_40 ) | F_5 ( V_27 % 32 ) ;
else
V_11 = F_4 ( V_40 ) & ~ F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_40 ) ;
if ( type & V_45 ) {
V_11 = F_4 ( V_38 ) | F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_38 ) ;
F_21 ( V_26 , V_46 ) ;
} else if ( type & V_47 ) {
V_11 = F_4 ( V_38 ) & ~ F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_38 ) ;
F_21 ( V_26 , V_48 ) ;
}
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 , unsigned int V_49 )
{
struct V_1 * V_33 = F_15 ( V_26 ) ;
struct V_5 * V_6 = F_2 ( V_33 ) ;
T_3 V_27 = F_16 ( V_26 ) ;
void T_1 * V_50 = F_1 ( & V_6 -> V_2 , V_27 , V_51 ) ;
void T_1 * V_52 = F_1 ( & V_6 -> V_2 , V_27 , V_53 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_27 % 32 ) , V_52 ) ;
if ( V_49 )
V_11 = F_4 ( V_50 ) | F_5 ( V_27 % 32 ) ;
else
V_11 = F_4 ( V_50 ) & ~ F_5 ( V_27 % 32 ) ;
F_8 ( V_11 , V_50 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
F_23 ( V_6 -> V_54 , L_1 , V_49 ? L_2 : L_3 , V_27 ) ;
return 0 ;
}
static void F_24 ( struct V_55 * V_56 )
{
struct V_1 * V_33 = F_25 ( V_56 ) ;
struct V_5 * V_6 = F_2 ( V_33 ) ;
struct V_57 * V_58 = F_26 ( V_56 ) ;
unsigned long V_59 , V_27 ;
F_27 ( V_58 , V_56 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_2 . V_60 ; V_59 += 32 ) {
void T_1 * V_28 = F_1 ( & V_6 -> V_2 , V_59 , V_29 ) ;
void T_1 * V_31 = F_1 ( & V_6 -> V_2 , V_59 , V_32 ) ;
unsigned long V_61 , V_62 ;
V_61 = F_4 ( V_28 ) ;
V_62 = F_4 ( V_31 ) ;
V_61 &= V_62 ;
F_28 (gpio, &pending, 32 ) {
unsigned int V_63 ;
V_63 = F_29 ( V_33 -> V_64 , V_59 + V_27 ) ;
F_30 ( V_63 ) ;
}
}
F_31 ( V_58 , V_56 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
void T_1 * V_7 ;
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_6 -> V_2 . V_60 ; V_59 += 32 ) {
V_7 = F_1 ( & V_6 -> V_2 , V_59 , V_35 ) ;
F_8 ( 0 , V_7 ) ;
V_7 = F_1 ( & V_6 -> V_2 , V_59 , V_37 ) ;
F_8 ( 0 , V_7 ) ;
}
}
static int F_33 ( struct V_65 * V_66 , const struct V_67 * V_68 )
{
const struct V_69 * V_70 ;
struct V_5 * V_6 ;
T_3 V_71 , V_72 ;
void T_1 * V_59 ;
unsigned int V_73 ;
int V_74 ;
V_74 = F_34 ( V_66 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_35 ( V_66 , F_5 ( 1 ) | F_5 ( 0 ) , F_36 ( V_66 ) ) ;
if ( V_74 ) {
F_37 ( & V_66 -> V_54 , L_4 ) ;
return V_74 ;
}
V_59 = F_38 ( V_66 ) [ 1 ] ;
V_72 = F_4 ( V_59 ) ;
V_71 = F_4 ( sizeof( T_3 ) + V_59 ) ;
F_39 ( V_66 , F_5 ( 1 ) ) ;
V_6 = F_40 ( & V_66 -> V_54 , sizeof( * V_6 ) , V_75 ) ;
if ( ! V_6 ) {
F_37 ( & V_66 -> V_54 , L_5 ) ;
return - V_76 ;
}
V_6 -> V_54 = & V_66 -> V_54 ;
V_6 -> V_8 = F_38 ( V_66 ) [ 0 ] ;
V_6 -> V_2 . V_77 = F_41 ( & V_66 -> V_54 ) ;
V_6 -> V_2 . V_78 = & V_66 -> V_54 ;
V_6 -> V_2 . V_79 = V_80 ;
V_6 -> V_2 . free = V_81 ;
V_6 -> V_2 . V_82 = F_10 ;
V_6 -> V_2 . V_83 = F_11 ;
V_6 -> V_2 . V_84 = F_3 ;
V_6 -> V_2 . V_85 = F_6 ;
V_6 -> V_2 . V_86 = F_12 ;
V_6 -> V_2 . V_87 = F_13 ;
V_6 -> V_2 . V_59 = V_71 ;
V_6 -> V_2 . V_60 = V_88 ;
V_6 -> V_2 . V_89 = false ;
F_42 ( & V_6 -> V_15 ) ;
F_43 ( V_66 , V_6 ) ;
V_74 = F_44 ( & V_66 -> V_54 , & V_6 -> V_2 , V_6 ) ;
if ( V_74 ) {
F_37 ( & V_66 -> V_54 , L_6 , V_74 ) ;
return V_74 ;
}
for ( V_73 = 0 ; V_73 < F_45 ( V_90 ) ; V_73 ++ ) {
V_70 = & V_90 [ V_73 ] ;
V_74 = F_46 ( & V_6 -> V_2 ,
L_7 ,
V_70 -> V_71 ,
V_70 -> V_91 ,
V_70 -> V_92 ) ;
if ( V_74 ) {
F_37 ( & V_66 -> V_54 , L_8 ) ;
return V_74 ;
}
}
V_74 = F_47 ( & V_6 -> V_2 , & V_93 , V_72 ,
V_94 , V_95 ) ;
if ( V_74 ) {
F_37 ( & V_66 -> V_54 , L_9 ) ;
return V_74 ;
}
F_32 ( V_6 ) ;
F_48 ( & V_6 -> V_2 , & V_93 , V_66 -> V_63 ,
F_24 ) ;
return 0 ;
}
