static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ;
void T_2 * V_5 = F_3 ( V_1 , V_3 , V_2 ) ;
T_1 V_6 = F_4 ( V_5 ) ;
return ! ! ( V_6 & ( 1 << V_4 ) ) ;
}
static inline void F_5 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ;
void T_2 * V_5 = F_3 ( V_1 , V_3 , V_2 ) ;
T_1 V_6 = F_4 ( V_5 ) ;
F_6 ( V_6 | ( 1 << V_4 ) , V_5 ) ;
}
static inline void F_7 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ;
void T_2 * V_5 = F_3 ( V_1 , V_3 , V_2 ) ;
T_1 V_6 = F_4 ( V_5 ) ;
F_6 ( V_6 & ~ ( 1 << V_4 ) , V_5 ) ;
}
static int F_8 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
unsigned long V_10 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_13 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return - V_14 ;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_5 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_17 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , unsigned V_4 ,
int V_18 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
unsigned long V_10 ;
unsigned V_19 = V_4 , V_20 = V_4 , V_21 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & ( V_13 | V_22 ) ) ) {
V_21 = V_9 -> V_11 ( V_4 ) ;
if ( V_21 == - 1 )
return - V_14 ;
if ( V_9 -> V_12 & V_13 )
V_19 = V_21 ;
if ( V_9 -> V_12 & V_22 )
V_20 = V_21 ;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
if ( V_18 )
F_5 ( V_9 -> V_1 , V_20 ,
V_9 -> V_16 . V_23 ) ;
else
F_7 ( V_9 -> V_1 , V_20 ,
V_9 -> V_16 . V_23 ) ;
F_7 ( V_9 -> V_1 , V_19 , V_9 -> V_16 . V_17 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
if ( V_4 >= V_8 -> V_24 )
return - V_14 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_25 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return - V_14 ;
}
return F_1 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_26 ) ;
}
static void F_14 ( struct V_7 * V_8 , unsigned V_4 , int V_18 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
if ( V_4 >= V_8 -> V_24 )
return;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_22 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return;
}
if ( V_18 )
F_5 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_23 ) ;
else
F_7 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_23 ) ;
}
static int F_15 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
int V_27 = V_8 -> V_1 + V_4 ;
unsigned long V_10 ;
int V_28 = 0 ;
if ( V_4 >= V_8 -> V_24 )
return - V_14 ;
V_28 = F_16 ( V_27 ) ;
if ( V_28 )
return V_28 ;
if ( ! F_17 ( V_9 -> V_29 ) ) {
V_28 = F_18 ( V_9 -> V_29 ) ;
if ( V_28 )
goto V_30;
}
if ( V_9 -> V_16 . V_31 == - 1 )
return 0 ;
V_28 = F_8 ( V_8 , V_4 ) ;
if ( V_28 )
goto V_32;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_33 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 ) {
V_28 = - V_14 ;
goto V_32;
}
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_5 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_31 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
return 0 ;
V_32:
if ( ! F_17 ( V_9 -> V_29 ) )
F_19 ( V_9 -> V_29 ) ;
V_30:
F_20 ( V_27 ) ;
return V_28 ;
}
static void F_21 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
int V_27 = V_8 -> V_1 + V_4 ;
unsigned long V_10 ;
if ( V_4 >= V_8 -> V_24 )
return;
if ( V_9 -> V_16 . V_31 == - 1 )
goto V_34;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_33 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_7 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_31 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
V_34:
if ( ! F_17 ( V_9 -> V_29 ) )
F_19 ( V_9 -> V_29 ) ;
F_20 ( V_27 ) ;
}
static void F_22 ( struct V_35 * V_36 )
{
struct V_7 * V_37 = F_23 ( V_36 ) ;
struct V_9 * V_9 = F_9 ( V_37 , struct V_9 , V_8 ) ;
int V_4 = V_36 -> V_38 ;
unsigned long V_10 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_39 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_5 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_40 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
}
static void F_24 ( struct V_35 * V_36 )
{
struct V_7 * V_37 = F_23 ( V_36 ) ;
struct V_9 * V_9 = F_9 ( V_37 , struct V_9 , V_8 ) ;
int V_4 = V_36 -> V_38 ;
unsigned long V_10 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_39 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_7 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_40 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
}
static int F_25 ( struct V_35 * V_36 , unsigned V_41 )
{
struct V_7 * V_37 = F_23 ( V_36 ) ;
struct V_9 * V_9 = F_9 ( V_37 , struct V_9 , V_8 ) ;
int V_4 = V_36 -> V_38 ;
void T_2 * V_5 ;
unsigned int V_42 = 0 , V_6 ;
if ( V_4 >= V_9 -> V_8 . V_24 )
return - V_14 ;
if ( V_9 -> V_16 . V_43 == - 1 )
V_42 = V_44 ;
else
V_42 = V_45 | V_46 ;
if ( ! ( V_41 & V_42 ) )
return - V_14 ;
if ( V_9 -> V_16 . V_43 == - 1 )
return 0 ;
V_5 = F_3 ( V_9 -> V_1 , V_9 -> V_16 . V_43 , V_4 ) ;
V_6 = F_4 ( V_5 ) ;
V_4 = F_2 ( V_4 ) ;
if ( V_41 & V_45 )
F_6 ( V_6 | ( 1 << V_4 ) , V_5 ) ;
else
F_6 ( V_6 & ~ ( 1 << V_4 ) , V_5 ) ;
return 0 ;
}
static void F_26 ( struct V_47 * V_48 )
{
struct V_7 * V_37 = F_27 ( V_48 ) ;
struct V_9 * V_9 = F_9 ( V_37 , struct V_9 , V_8 ) ;
struct V_49 * V_50 = F_28 ( V_48 ) ;
int V_51 , V_52 , V_2 , V_4 , V_53 = 0 ;
unsigned long V_54 ;
V_52 = V_9 -> V_8 . V_24 ;
V_51 = F_29 ( V_52 , V_55 ) ;
F_30 ( V_50 , V_48 ) ;
for (; V_53 < V_51 ; V_53 ++ ) {
V_54 = F_4 ( V_9 -> V_1 + V_9 -> V_16 . V_56 +
V_53 * sizeof( int * ) ) ;
if ( ! V_54 )
continue;
F_6 ( ~ V_54 , V_9 -> V_1 + V_9 -> V_16 . V_56 +
V_53 * sizeof( int * ) ) ;
V_52 = V_52 - V_53 * V_55 ;
if ( V_52 < V_55 )
V_54 &= ( 1 << V_52 ) - 1 ;
F_31 (offset, &pending, MAX_GPIO_PER_REG) {
if ( V_9 -> V_57 && ( V_9 -> V_12 & V_58 ) ) {
V_2 = V_9 -> V_57 ( V_4 ) ;
if ( V_2 == - 1 )
continue;
} else
V_2 = V_4 ;
V_2 = V_53 * V_55 + V_2 ;
F_32 (
F_33 ( V_37 -> V_59 , V_2 ) ) ;
}
}
F_34 ( V_50 , V_48 ) ;
}
static int F_35 ( int V_2 )
{
int V_4 = V_2 ;
if ( V_2 <= 27 )
V_4 += 4 ;
else if ( V_2 <= 33 )
V_4 = - 1 ;
else if ( V_2 <= 97 )
V_4 -= 2 ;
else if ( V_2 <= 101 )
V_4 = 101 - V_2 ;
else
V_4 = - 1 ;
return V_4 ;
}
static int F_36 ( int V_4 )
{
if ( V_4 <= 3 )
return 101 - V_4 ;
else if ( V_4 <= 31 )
return V_4 - 4 ;
else
return V_4 + 2 ;
}
static int F_37 ( struct V_60 * V_61 , struct V_9 * V_9 )
{
struct V_62 * V_63 = V_61 -> V_64 . V_65 ;
int V_28 = - V_14 ;
T_1 V_6 ;
if ( F_38 ( L_1 ) ) {
V_9 -> V_11 = F_35 ;
V_9 -> V_57 = F_36 ;
V_9 -> V_12 = V_22 | V_13 | V_39 |
V_25 | V_58 ;
}
if ( ! F_39 ( V_63 , L_2 , & V_6 ) ) {
V_9 -> V_8 . V_24 = V_6 ;
} else {
F_40 ( & V_61 -> V_64 , L_3 ) ;
goto V_66;
}
if ( ! F_39 ( V_63 , L_4 , & V_6 ) )
V_9 -> V_16 . V_31 = V_6 ;
else
V_9 -> V_16 . V_31 = - 1 ;
if ( ! F_39 ( V_63 , L_5 , & V_6 ) ) {
V_9 -> V_16 . V_23 = V_6 ;
} else {
F_40 ( & V_61 -> V_64 , L_6 ) ;
goto V_66;
}
if ( ! F_39 ( V_63 , L_7 , & V_6 ) ) {
V_9 -> V_16 . V_17 = V_6 ;
} else {
F_40 ( & V_61 -> V_64 , L_8 ) ;
goto V_66;
}
if ( ! F_39 ( V_63 , L_9 , & V_6 ) ) {
V_9 -> V_16 . V_40 = V_6 ;
} else {
F_40 ( & V_61 -> V_64 , L_10 ) ;
goto V_66;
}
if ( ! F_39 ( V_63 , L_11 , & V_6 ) ) {
V_9 -> V_16 . V_26 = V_6 ;
} else {
F_40 ( & V_61 -> V_64 , L_12 ) ;
goto V_66;
}
if ( ! F_39 ( V_63 , L_13 , & V_6 ) ) {
V_9 -> V_16 . V_56 = V_6 ;
} else {
F_40 ( & V_61 -> V_64 , L_14 ) ;
goto V_66;
}
if ( ! F_39 ( V_63 , L_15 , & V_6 ) )
V_9 -> V_16 . V_43 = V_6 ;
else
V_9 -> V_16 . V_43 = - 1 ;
return 0 ;
V_66:
return V_28 ;
}
static int F_41 ( struct V_60 * V_61 )
{
struct V_9 * V_9 ;
struct V_67 * V_68 ;
int V_28 , V_69 ;
V_9 = F_42 ( & V_61 -> V_64 , sizeof( * V_9 ) , V_70 ) ;
if ( ! V_9 ) {
F_40 ( & V_61 -> V_64 , L_16 ) ;
return - V_71 ;
}
V_68 = F_43 ( V_61 , V_72 , 0 ) ;
V_9 -> V_1 = F_44 ( & V_61 -> V_64 , V_68 ) ;
if ( F_17 ( V_9 -> V_1 ) )
return F_45 ( V_9 -> V_1 ) ;
V_28 = F_37 ( V_61 , V_9 ) ;
if ( V_28 ) {
F_40 ( & V_61 -> V_64 , L_17 ) ;
return V_28 ;
}
V_9 -> V_29 = F_46 ( & V_61 -> V_64 , NULL ) ;
if ( F_17 ( V_9 -> V_29 ) )
F_47 ( & V_61 -> V_64 , L_18 ) ;
#ifdef F_48
V_9 -> V_73 = F_42 ( & V_61 -> V_64 ,
sizeof( * V_9 -> V_73 ) *
F_29 ( V_9 -> V_8 . V_24 , V_55 ) ,
V_70 ) ;
if ( ! V_9 -> V_73 ) {
F_40 ( & V_61 -> V_64 , L_19 ) ;
return - V_71 ;
}
#endif
F_49 ( V_61 , V_9 ) ;
F_50 ( & V_9 -> V_15 ) ;
V_9 -> V_8 . V_1 = - 1 ;
V_9 -> V_8 . V_74 = F_15 ;
V_9 -> V_8 . free = F_21 ;
V_9 -> V_8 . V_75 = F_8 ;
V_9 -> V_8 . V_76 = F_12 ;
V_9 -> V_8 . V_77 = F_13 ;
V_9 -> V_8 . V_78 = F_14 ;
V_9 -> V_8 . V_79 = F_51 ( & V_61 -> V_64 ) ;
V_9 -> V_8 . V_64 = & V_61 -> V_64 ;
V_9 -> V_8 . V_80 = V_81 ;
V_9 -> V_8 . V_65 = V_61 -> V_64 . V_65 ;
if ( ! F_17 ( V_9 -> V_29 ) ) {
V_28 = F_52 ( V_9 -> V_29 ) ;
if ( V_28 ) {
F_40 ( & V_61 -> V_64 , L_20 ) ;
return V_28 ;
}
}
V_28 = F_53 ( & V_9 -> V_8 ) ;
if ( V_28 ) {
F_40 ( & V_61 -> V_64 , L_21 ) ;
goto V_82;
}
V_69 = F_54 ( V_61 , 0 ) ;
if ( V_69 < 0 ) {
F_55 ( & V_61 -> V_64 , L_22 ) ;
return 0 ;
}
V_28 = F_56 ( & V_9 -> V_8 ,
& V_83 ,
0 ,
V_84 ,
V_85 ) ;
if ( V_28 ) {
F_40 ( & V_61 -> V_64 , L_23 ) ;
goto V_86;
}
F_57 ( & V_9 -> V_8 ,
& V_83 ,
V_69 ,
F_26 ) ;
F_55 ( & V_61 -> V_64 , L_24 ) ;
return 0 ;
V_86:
F_55 ( & V_61 -> V_64 , L_25 ) ;
F_58 ( & V_9 -> V_8 ) ;
V_82:
if ( ! F_17 ( V_9 -> V_29 ) )
F_59 ( V_9 -> V_29 ) ;
return V_28 ;
}
static int F_60 ( struct V_87 * V_64 )
{
struct V_9 * V_9 = F_61 ( V_64 ) ;
int V_53 , V_88 = F_29 ( V_9 -> V_8 . V_24 , V_55 ) ;
void T_2 * V_89 ;
for ( V_53 = 0 ; V_53 < V_88 ; V_53 ++ ) {
V_89 = V_9 -> V_1 + V_53 * sizeof( int * ) ;
if ( V_9 -> V_16 . V_31 != - 1 )
V_9 -> V_73 [ V_53 ] . V_31 =
F_4 ( V_9 -> V_16 . V_31 + V_89 ) ;
if ( V_9 -> V_16 . V_43 != - 1 )
V_9 -> V_73 [ V_53 ] . V_43 =
F_4 ( V_9 -> V_16 . V_43 + V_89 ) ;
V_9 -> V_73 [ V_53 ] . V_23 = F_4 ( V_9 -> V_16 . V_23 +
V_89 ) ;
V_9 -> V_73 [ V_53 ] . V_17 = F_4 ( V_9 -> V_16 . V_17 +
V_89 ) ;
V_9 -> V_73 [ V_53 ] . V_40 = F_4 ( V_9 -> V_16 . V_40 + V_89 ) ;
}
return 0 ;
}
static int F_62 ( struct V_87 * V_64 )
{
struct V_9 * V_9 = F_61 ( V_64 ) ;
int V_53 , V_88 = F_29 ( V_9 -> V_8 . V_24 , V_55 ) ;
void T_2 * V_89 ;
T_1 V_90 , V_21 ;
for ( V_53 = 0 ; V_53 < V_88 ; V_53 ++ ) {
V_89 = V_9 -> V_1 + V_53 * sizeof( int * ) ;
if ( V_53 == V_88 - 1 ) {
V_90 = ( 1 << ( V_9 -> V_8 . V_24 - V_53 *
V_55 ) ) - 1 ;
if ( V_9 -> V_16 . V_31 != - 1 )
F_63 ( V_31 , V_89 , V_90 , V_21 ) ;
if ( V_9 -> V_16 . V_43 != - 1 )
F_63 ( V_43 , V_89 , V_90 , V_21 ) ;
F_63 ( V_23 , V_89 , V_90 , V_21 ) ;
F_63 ( V_17 , V_89 , V_90 , V_21 ) ;
F_63 ( V_40 , V_89 , V_90 , V_21 ) ;
}
F_6 ( V_9 -> V_73 [ V_53 ] . V_23 , V_9 -> V_16 . V_23 +
V_89 ) ;
F_6 ( V_9 -> V_73 [ V_53 ] . V_17 , V_9 -> V_16 . V_17 +
V_89 ) ;
if ( V_9 -> V_16 . V_43 != - 1 )
F_6 ( V_9 -> V_73 [ V_53 ] . V_43 ,
V_9 -> V_16 . V_43 + V_89 ) ;
F_6 ( V_9 -> V_73 [ V_53 ] . V_40 , V_9 -> V_16 . V_40 + V_89 ) ;
if ( V_9 -> V_16 . V_31 != - 1 )
F_6 ( V_9 -> V_73 [ V_53 ] . V_31 ,
V_9 -> V_16 . V_31 + V_89 ) ;
}
return 0 ;
}
static int T_3 F_64 ( void )
{
return F_65 ( & V_91 ) ;
}
