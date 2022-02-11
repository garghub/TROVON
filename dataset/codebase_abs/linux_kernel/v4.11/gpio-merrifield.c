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
static int F_14 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_25 )
{
T_3 V_22 ;
if ( F_15 ( V_25 ) != V_26 )
return - V_27 ;
V_22 = F_16 ( V_25 ) ;
return F_13 ( V_2 , V_3 , V_22 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
struct V_5 * V_6 = F_18 ( V_29 ) ;
T_3 V_30 = F_19 ( V_29 ) ;
void T_1 * V_31 = F_1 ( & V_6 -> V_2 , V_30 , V_32 ) ;
unsigned long V_14 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_30 % 32 ) , V_31 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_20 ( struct V_28 * V_29 , bool V_33 )
{
struct V_5 * V_6 = F_18 ( V_29 ) ;
T_3 V_30 = F_19 ( V_29 ) ;
void T_1 * V_34 = F_1 ( & V_6 -> V_2 , V_30 , V_35 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( V_33 )
V_11 = F_4 ( V_34 ) | F_5 ( V_30 % 32 ) ;
else
V_11 = F_4 ( V_34 ) & ~ F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_34 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
F_20 ( V_29 , false ) ;
}
static void F_22 ( struct V_28 * V_29 )
{
F_20 ( V_29 , true ) ;
}
static int F_23 ( struct V_28 * V_29 , unsigned int type )
{
struct V_1 * V_36 = F_18 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_36 ) ;
T_3 V_30 = F_19 ( V_29 ) ;
void T_1 * V_37 = F_1 ( & V_6 -> V_2 , V_30 , V_38 ) ;
void T_1 * V_39 = F_1 ( & V_6 -> V_2 , V_30 , V_40 ) ;
void T_1 * V_41 = F_1 ( & V_6 -> V_2 , V_30 , V_42 ) ;
void T_1 * V_43 = F_1 ( & V_6 -> V_2 , V_30 , V_44 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
if ( type & V_45 )
V_11 = F_4 ( V_37 ) | F_5 ( V_30 % 32 ) ;
else
V_11 = F_4 ( V_37 ) & ~ F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_37 ) ;
if ( type & V_46 )
V_11 = F_4 ( V_39 ) | F_5 ( V_30 % 32 ) ;
else
V_11 = F_4 ( V_39 ) & ~ F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_39 ) ;
if ( type & V_47 )
V_11 = F_4 ( V_43 ) | F_5 ( V_30 % 32 ) ;
else
V_11 = F_4 ( V_43 ) & ~ F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_43 ) ;
if ( type & V_48 ) {
V_11 = F_4 ( V_41 ) | F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_41 ) ;
F_24 ( V_29 , V_49 ) ;
} else if ( type & V_50 ) {
V_11 = F_4 ( V_41 ) & ~ F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_41 ) ;
F_24 ( V_29 , V_51 ) ;
}
F_9 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 , unsigned int V_52 )
{
struct V_1 * V_36 = F_18 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_36 ) ;
T_3 V_30 = F_19 ( V_29 ) ;
void T_1 * V_53 = F_1 ( & V_6 -> V_2 , V_30 , V_54 ) ;
void T_1 * V_55 = F_1 ( & V_6 -> V_2 , V_30 , V_56 ) ;
unsigned long V_14 ;
T_3 V_11 ;
F_7 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( F_5 ( V_30 % 32 ) , V_55 ) ;
if ( V_52 )
V_11 = F_4 ( V_53 ) | F_5 ( V_30 % 32 ) ;
else
V_11 = F_4 ( V_53 ) & ~ F_5 ( V_30 % 32 ) ;
F_8 ( V_11 , V_53 ) ;
F_9 ( & V_6 -> V_15 , V_14 ) ;
F_26 ( V_6 -> V_57 , L_1 , V_52 ? L_2 : L_3 , V_30 ) ;
return 0 ;
}
static void F_27 ( struct V_58 * V_59 )
{
struct V_1 * V_36 = F_28 ( V_59 ) ;
struct V_5 * V_6 = F_2 ( V_36 ) ;
struct V_60 * V_61 = F_29 ( V_59 ) ;
unsigned long V_62 , V_30 ;
F_30 ( V_61 , V_59 ) ;
for ( V_62 = 0 ; V_62 < V_6 -> V_2 . V_63 ; V_62 += 32 ) {
void T_1 * V_31 = F_1 ( & V_6 -> V_2 , V_62 , V_32 ) ;
void T_1 * V_34 = F_1 ( & V_6 -> V_2 , V_62 , V_35 ) ;
unsigned long V_64 , V_65 ;
V_64 = F_4 ( V_31 ) ;
V_65 = F_4 ( V_34 ) ;
V_64 &= V_65 ;
F_31 (gpio, &pending, 32 ) {
unsigned int V_66 ;
V_66 = F_32 ( V_36 -> V_67 , V_62 + V_30 ) ;
F_33 ( V_66 ) ;
}
}
F_34 ( V_61 , V_59 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
void T_1 * V_7 ;
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_6 -> V_2 . V_63 ; V_62 += 32 ) {
V_7 = F_1 ( & V_6 -> V_2 , V_62 , V_38 ) ;
F_8 ( 0 , V_7 ) ;
V_7 = F_1 ( & V_6 -> V_2 , V_62 , V_40 ) ;
F_8 ( 0 , V_7 ) ;
}
}
static int F_36 ( struct V_68 * V_69 , const struct V_70 * V_71 )
{
const struct V_72 * V_73 ;
struct V_5 * V_6 ;
T_3 V_74 , V_75 ;
void T_1 * V_62 ;
unsigned int V_76 ;
int V_77 ;
V_77 = F_37 ( V_69 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_38 ( V_69 , F_5 ( 1 ) | F_5 ( 0 ) , F_39 ( V_69 ) ) ;
if ( V_77 ) {
F_40 ( & V_69 -> V_57 , L_4 ) ;
return V_77 ;
}
V_62 = F_41 ( V_69 ) [ 1 ] ;
V_75 = F_4 ( V_62 ) ;
V_74 = F_4 ( sizeof( T_3 ) + V_62 ) ;
F_42 ( V_69 , F_5 ( 1 ) ) ;
V_6 = F_43 ( & V_69 -> V_57 , sizeof( * V_6 ) , V_78 ) ;
if ( ! V_6 ) {
F_40 ( & V_69 -> V_57 , L_5 ) ;
return - V_79 ;
}
V_6 -> V_57 = & V_69 -> V_57 ;
V_6 -> V_8 = F_41 ( V_69 ) [ 0 ] ;
V_6 -> V_2 . V_80 = F_44 ( & V_69 -> V_57 ) ;
V_6 -> V_2 . V_81 = & V_69 -> V_57 ;
V_6 -> V_2 . V_82 = V_83 ;
V_6 -> V_2 . free = V_84 ;
V_6 -> V_2 . V_85 = F_10 ;
V_6 -> V_2 . V_86 = F_11 ;
V_6 -> V_2 . V_87 = F_3 ;
V_6 -> V_2 . V_88 = F_6 ;
V_6 -> V_2 . V_89 = F_12 ;
V_6 -> V_2 . V_90 = F_14 ;
V_6 -> V_2 . V_62 = V_74 ;
V_6 -> V_2 . V_63 = V_91 ;
V_6 -> V_2 . V_92 = false ;
F_45 ( & V_6 -> V_15 ) ;
F_46 ( V_69 , V_6 ) ;
V_77 = F_47 ( & V_69 -> V_57 , & V_6 -> V_2 , V_6 ) ;
if ( V_77 ) {
F_40 ( & V_69 -> V_57 , L_6 , V_77 ) ;
return V_77 ;
}
for ( V_76 = 0 ; V_76 < F_48 ( V_93 ) ; V_76 ++ ) {
V_73 = & V_93 [ V_76 ] ;
V_77 = F_49 ( & V_6 -> V_2 ,
L_7 ,
V_73 -> V_74 ,
V_73 -> V_94 ,
V_73 -> V_95 ) ;
if ( V_77 ) {
F_40 ( & V_69 -> V_57 , L_8 ) ;
return V_77 ;
}
}
V_77 = F_50 ( & V_6 -> V_2 , & V_96 , V_75 ,
V_97 , V_98 ) ;
if ( V_77 ) {
F_40 ( & V_69 -> V_57 , L_9 ) ;
return V_77 ;
}
F_35 ( V_6 ) ;
F_51 ( & V_6 -> V_2 , & V_96 , V_69 -> V_66 ,
F_27 ) ;
return 0 ;
}
