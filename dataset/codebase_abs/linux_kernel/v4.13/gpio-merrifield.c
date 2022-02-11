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
return ! ( F_4 ( V_18 ) & F_5 ( V_3 % 32 ) ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_21 = F_1 ( V_2 , V_3 , V_22 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_20 )
V_11 = F_4 ( V_21 ) & ~ F_5 ( V_3 % 32 ) ;
else
V_11 = F_4 ( V_21 ) | F_5 ( V_3 % 32 ) ;
F_8 ( V_11 , V_21 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_23 )
{
T_3 V_20 ;
if ( F_15 ( V_23 ) != V_24 )
return - V_25 ;
V_20 = F_16 ( V_23 ) ;
return F_13 ( V_2 , V_3 , V_20 ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_5 * V_6 = F_18 ( V_27 ) ;
T_3 V_28 = F_19 ( V_27 ) ;
void T_1 * V_29 = F_1 ( & V_6 -> V_2 , V_28 , V_30 ) ;
unsigned long V_14 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_28 % 32 ) , V_29 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_20 ( struct V_26 * V_27 , bool V_31 )
{
struct V_5 * V_6 = F_18 ( V_27 ) ;
T_3 V_28 = F_19 ( V_27 ) ;
void T_1 * V_32 = F_1 ( & V_6 -> V_2 , V_28 , V_33 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_31 )
V_11 = F_4 ( V_32 ) | F_5 ( V_28 % 32 ) ;
else
V_11 = F_4 ( V_32 ) & ~ F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_32 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_21 ( struct V_26 * V_27 )
{
F_20 ( V_27 , false ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
F_20 ( V_27 , true ) ;
}
static int F_23 ( struct V_26 * V_27 , unsigned int type )
{
struct V_1 * V_34 = F_18 ( V_27 ) ;
struct V_5 * V_6 = F_2 ( V_34 ) ;
T_3 V_28 = F_19 ( V_27 ) ;
void T_1 * V_35 = F_1 ( & V_6 -> V_2 , V_28 , V_36 ) ;
void T_1 * V_37 = F_1 ( & V_6 -> V_2 , V_28 , V_38 ) ;
void T_1 * V_39 = F_1 ( & V_6 -> V_2 , V_28 , V_40 ) ;
void T_1 * V_41 = F_1 ( & V_6 -> V_2 , V_28 , V_42 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( type & V_43 )
V_11 = F_4 ( V_35 ) | F_5 ( V_28 % 32 ) ;
else
V_11 = F_4 ( V_35 ) & ~ F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_35 ) ;
if ( type & V_44 )
V_11 = F_4 ( V_37 ) | F_5 ( V_28 % 32 ) ;
else
V_11 = F_4 ( V_37 ) & ~ F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_37 ) ;
if ( type & V_45 )
V_11 = F_4 ( V_41 ) | F_5 ( V_28 % 32 ) ;
else
V_11 = F_4 ( V_41 ) & ~ F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_41 ) ;
if ( type & V_46 ) {
V_11 = F_4 ( V_39 ) | F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_39 ) ;
F_24 ( V_27 , V_47 ) ;
} else if ( type & V_48 ) {
V_11 = F_4 ( V_39 ) & ~ F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_39 ) ;
F_24 ( V_27 , V_49 ) ;
}
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_25 ( struct V_26 * V_27 , unsigned int V_50 )
{
struct V_1 * V_34 = F_18 ( V_27 ) ;
struct V_5 * V_6 = F_2 ( V_34 ) ;
T_3 V_28 = F_19 ( V_27 ) ;
void T_1 * V_51 = F_1 ( & V_6 -> V_2 , V_28 , V_52 ) ;
void T_1 * V_53 = F_1 ( & V_6 -> V_2 , V_28 , V_54 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_28 % 32 ) , V_53 ) ;
if ( V_50 )
V_11 = F_4 ( V_51 ) | F_5 ( V_28 % 32 ) ;
else
V_11 = F_4 ( V_51 ) & ~ F_5 ( V_28 % 32 ) ;
F_8 ( V_11 , V_51 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
F_26 ( V_6 -> V_55 , L_1 , V_50 ? L_2 : L_3 , V_28 ) ;
return 0 ;
}
static void F_27 ( struct V_56 * V_57 )
{
struct V_1 * V_34 = F_28 ( V_57 ) ;
struct V_5 * V_6 = F_2 ( V_34 ) ;
struct V_58 * V_59 = F_29 ( V_57 ) ;
unsigned long V_60 , V_28 ;
F_30 ( V_59 , V_57 ) ;
for ( V_60 = 0 ; V_60 < V_6 -> V_2 . V_61 ; V_60 += 32 ) {
void T_1 * V_29 = F_1 ( & V_6 -> V_2 , V_60 , V_30 ) ;
void T_1 * V_32 = F_1 ( & V_6 -> V_2 , V_60 , V_33 ) ;
unsigned long V_62 , V_63 ;
V_62 = F_4 ( V_29 ) ;
V_63 = F_4 ( V_32 ) ;
V_62 &= V_63 ;
F_31 (gpio, &pending, 32 ) {
unsigned int V_64 ;
V_64 = F_32 ( V_34 -> V_65 , V_60 + V_28 ) ;
F_33 ( V_64 ) ;
}
}
F_34 ( V_59 , V_57 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
void T_1 * V_7 ;
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_2 . V_61 ; V_60 += 32 ) {
V_7 = F_1 ( & V_6 -> V_2 , V_60 , V_36 ) ;
F_8 ( 0 , V_7 ) ;
V_7 = F_1 ( & V_6 -> V_2 , V_60 , V_38 ) ;
F_8 ( 0 , V_7 ) ;
}
}
static int F_36 ( struct V_66 * V_67 , const struct V_68 * V_69 )
{
const struct V_70 * V_71 ;
struct V_5 * V_6 ;
T_3 V_72 , V_73 ;
void T_1 * V_60 ;
unsigned int V_74 ;
int V_75 ;
V_75 = F_37 ( V_67 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_38 ( V_67 , F_5 ( 1 ) | F_5 ( 0 ) , F_39 ( V_67 ) ) ;
if ( V_75 ) {
F_40 ( & V_67 -> V_55 , L_4 ) ;
return V_75 ;
}
V_60 = F_41 ( V_67 ) [ 1 ] ;
V_73 = F_4 ( V_60 ) ;
V_72 = F_4 ( sizeof( T_3 ) + V_60 ) ;
F_42 ( V_67 , F_5 ( 1 ) ) ;
V_6 = F_43 ( & V_67 -> V_55 , sizeof( * V_6 ) , V_76 ) ;
if ( ! V_6 ) {
F_40 ( & V_67 -> V_55 , L_5 ) ;
return - V_77 ;
}
V_6 -> V_55 = & V_67 -> V_55 ;
V_6 -> V_8 = F_41 ( V_67 ) [ 0 ] ;
V_6 -> V_2 . V_78 = F_44 ( & V_67 -> V_55 ) ;
V_6 -> V_2 . V_79 = & V_67 -> V_55 ;
V_6 -> V_2 . V_80 = V_81 ;
V_6 -> V_2 . free = V_82 ;
V_6 -> V_2 . V_83 = F_10 ;
V_6 -> V_2 . V_84 = F_11 ;
V_6 -> V_2 . V_85 = F_3 ;
V_6 -> V_2 . V_86 = F_6 ;
V_6 -> V_2 . V_87 = F_12 ;
V_6 -> V_2 . V_88 = F_14 ;
V_6 -> V_2 . V_60 = V_72 ;
V_6 -> V_2 . V_61 = V_89 ;
V_6 -> V_2 . V_90 = false ;
F_45 ( & V_6 -> V_15 ) ;
F_46 ( V_67 , V_6 ) ;
V_75 = F_47 ( & V_67 -> V_55 , & V_6 -> V_2 , V_6 ) ;
if ( V_75 ) {
F_40 ( & V_67 -> V_55 , L_6 , V_75 ) ;
return V_75 ;
}
for ( V_74 = 0 ; V_74 < F_48 ( V_91 ) ; V_74 ++ ) {
V_71 = & V_91 [ V_74 ] ;
V_75 = F_49 ( & V_6 -> V_2 ,
L_7 ,
V_71 -> V_72 ,
V_71 -> V_92 ,
V_71 -> V_93 ) ;
if ( V_75 ) {
F_40 ( & V_67 -> V_55 , L_8 ) ;
return V_75 ;
}
}
V_75 = F_50 ( & V_6 -> V_2 , & V_94 , V_73 ,
V_95 , V_96 ) ;
if ( V_75 ) {
F_40 ( & V_67 -> V_55 , L_9 ) ;
return V_75 ;
}
F_35 ( V_6 ) ;
F_51 ( & V_6 -> V_2 , & V_94 , V_67 -> V_64 ,
F_27 ) ;
return 0 ;
}
