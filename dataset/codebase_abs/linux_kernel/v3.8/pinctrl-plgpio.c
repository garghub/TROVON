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
static int F_22 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_9 * V_9 = F_9 ( V_8 , struct V_9 , V_8 ) ;
if ( F_23 ( V_9 -> V_35 ) )
return - V_14 ;
return F_24 ( V_9 -> V_36 , V_4 ) ;
}
static void F_25 ( struct V_37 * V_38 )
{
struct V_9 * V_9 = F_26 ( V_38 ) ;
int V_4 = V_38 -> V_39 - V_9 -> V_35 ;
unsigned long V_10 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_40 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_5 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_41 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
}
static void F_27 ( struct V_37 * V_38 )
{
struct V_9 * V_9 = F_26 ( V_38 ) ;
int V_4 = V_38 -> V_39 - V_9 -> V_35 ;
unsigned long V_10 ;
if ( V_9 -> V_11 && ( V_9 -> V_12 & V_40 ) ) {
V_4 = V_9 -> V_11 ( V_4 ) ;
if ( V_4 == - 1 )
return;
}
F_10 ( & V_9 -> V_15 , V_10 ) ;
F_7 ( V_9 -> V_1 , V_4 , V_9 -> V_16 . V_41 ) ;
F_11 ( & V_9 -> V_15 , V_10 ) ;
}
static int F_28 ( struct V_37 * V_38 , unsigned V_42 )
{
struct V_9 * V_9 = F_26 ( V_38 ) ;
int V_4 = V_38 -> V_39 - V_9 -> V_35 ;
void T_2 * V_5 ;
unsigned int V_43 = 0 , V_6 ;
if ( V_4 >= V_9 -> V_8 . V_24 )
return - V_14 ;
if ( V_9 -> V_16 . V_44 == - 1 )
V_43 = V_45 ;
else
V_43 = V_46 | V_47 ;
if ( ! ( V_42 & V_43 ) )
return - V_14 ;
if ( V_9 -> V_16 . V_44 == - 1 )
return 0 ;
V_5 = F_3 ( V_9 -> V_1 , V_9 -> V_16 . V_44 , V_4 ) ;
V_6 = F_4 ( V_5 ) ;
V_4 = F_2 ( V_4 ) ;
if ( V_42 & V_46 )
F_6 ( V_6 | ( 1 << V_4 ) , V_5 ) ;
else
F_6 ( V_6 & ~ ( 1 << V_4 ) , V_5 ) ;
return 0 ;
}
static void F_29 ( unsigned V_39 , struct V_48 * V_49 )
{
struct V_9 * V_9 = F_30 ( V_39 ) ;
struct V_50 * V_51 = F_31 ( V_49 ) ;
int V_52 , V_53 , V_2 , V_4 , V_54 = 0 ;
unsigned long V_55 ;
V_53 = V_9 -> V_8 . V_24 ;
V_52 = F_32 ( V_53 , V_56 ) ;
F_33 ( V_51 , V_49 ) ;
for (; V_54 < V_52 ; V_54 ++ ) {
V_55 = F_4 ( V_9 -> V_1 + V_9 -> V_16 . V_57 +
V_54 * sizeof( int * ) ) ;
if ( ! V_55 )
continue;
F_6 ( ~ V_55 , V_9 -> V_1 + V_9 -> V_16 . V_57 +
V_54 * sizeof( int * ) ) ;
V_53 = V_53 - V_54 * V_56 ;
if ( V_53 < V_56 )
V_55 &= ( 1 << V_53 ) - 1 ;
F_34 (offset, &pending, MAX_GPIO_PER_REG) {
if ( V_9 -> V_58 && ( V_9 -> V_12 & V_59 ) ) {
V_2 = V_9 -> V_58 ( V_4 ) ;
if ( V_2 == - 1 )
continue;
} else
V_2 = V_4 ;
V_2 = V_54 * V_56 + V_2 ;
F_35 ( F_22 ( & V_9 -> V_8 , V_2 ) ) ;
}
}
F_36 ( V_51 , V_49 ) ;
}
static int F_37 ( int V_2 )
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
int F_38 ( int V_4 )
{
if ( V_4 <= 3 )
return 101 - V_4 ;
else if ( V_4 <= 31 )
return V_4 - 4 ;
else
return V_4 + 2 ;
}
static int F_39 ( struct V_60 * V_61 , struct V_9 * V_9 )
{
struct V_62 * V_63 = V_61 -> V_64 . V_65 ;
int V_28 = - V_14 ;
T_1 V_6 ;
if ( F_40 ( L_1 ) ) {
V_9 -> V_11 = F_37 ;
V_9 -> V_58 = F_38 ;
V_9 -> V_12 = V_22 | V_13 | V_40 |
V_25 | V_59 ;
}
if ( ! F_41 ( V_63 , L_2 , & V_6 ) ) {
V_9 -> V_8 . V_24 = V_6 ;
} else {
F_42 ( & V_61 -> V_64 , L_3 ) ;
goto V_66;
}
if ( ! F_41 ( V_63 , L_4 , & V_6 ) )
V_9 -> V_16 . V_31 = V_6 ;
else
V_9 -> V_16 . V_31 = - 1 ;
if ( ! F_41 ( V_63 , L_5 , & V_6 ) ) {
V_9 -> V_16 . V_23 = V_6 ;
} else {
F_42 ( & V_61 -> V_64 , L_6 ) ;
goto V_66;
}
if ( ! F_41 ( V_63 , L_7 , & V_6 ) ) {
V_9 -> V_16 . V_17 = V_6 ;
} else {
F_42 ( & V_61 -> V_64 , L_8 ) ;
goto V_66;
}
if ( ! F_41 ( V_63 , L_9 , & V_6 ) ) {
V_9 -> V_16 . V_41 = V_6 ;
} else {
F_42 ( & V_61 -> V_64 , L_10 ) ;
goto V_66;
}
if ( ! F_41 ( V_63 , L_11 , & V_6 ) ) {
V_9 -> V_16 . V_26 = V_6 ;
} else {
F_42 ( & V_61 -> V_64 , L_12 ) ;
goto V_66;
}
if ( ! F_41 ( V_63 , L_13 , & V_6 ) ) {
V_9 -> V_16 . V_57 = V_6 ;
} else {
F_42 ( & V_61 -> V_64 , L_14 ) ;
goto V_66;
}
if ( ! F_41 ( V_63 , L_15 , & V_6 ) )
V_9 -> V_16 . V_44 = V_6 ;
else
V_9 -> V_16 . V_44 = - 1 ;
return 0 ;
V_66:
return V_28 ;
}
static int F_43 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_64 . V_65 ;
struct V_9 * V_9 ;
struct V_67 * V_68 ;
int V_28 , V_39 , V_54 ;
V_68 = F_44 ( V_61 , V_69 , 0 ) ;
if ( ! V_68 ) {
F_42 ( & V_61 -> V_64 , L_16 ) ;
return - V_70 ;
}
V_9 = F_45 ( & V_61 -> V_64 , sizeof( * V_9 ) , V_71 ) ;
if ( ! V_9 ) {
F_42 ( & V_61 -> V_64 , L_17 ) ;
return - V_72 ;
}
V_9 -> V_1 = F_46 ( & V_61 -> V_64 , V_68 ) ;
if ( ! V_9 -> V_1 ) {
F_42 ( & V_61 -> V_64 , L_18 ) ;
return - V_72 ;
}
V_28 = F_39 ( V_61 , V_9 ) ;
if ( V_28 ) {
F_42 ( & V_61 -> V_64 , L_19 ) ;
return V_28 ;
}
V_9 -> V_29 = F_47 ( & V_61 -> V_64 , NULL ) ;
if ( F_17 ( V_9 -> V_29 ) )
F_48 ( & V_61 -> V_64 , L_20 ) ;
#ifdef F_49
V_9 -> V_73 = F_45 ( & V_61 -> V_64 ,
sizeof( * V_9 -> V_73 ) *
F_32 ( V_9 -> V_8 . V_24 , V_56 ) ,
V_71 ) ;
if ( ! V_9 -> V_73 ) {
F_42 ( & V_61 -> V_64 , L_21 ) ;
return - V_72 ;
}
#endif
F_50 ( V_61 , V_9 ) ;
F_51 ( & V_9 -> V_15 ) ;
V_9 -> V_35 = - 1 ;
V_9 -> V_8 . V_1 = - 1 ;
V_9 -> V_8 . V_74 = F_15 ;
V_9 -> V_8 . free = F_21 ;
V_9 -> V_8 . V_75 = F_8 ;
V_9 -> V_8 . V_76 = F_12 ;
V_9 -> V_8 . V_77 = F_13 ;
V_9 -> V_8 . V_78 = F_14 ;
V_9 -> V_8 . V_79 = F_22 ;
V_9 -> V_8 . V_80 = F_52 ( & V_61 -> V_64 ) ;
V_9 -> V_8 . V_64 = & V_61 -> V_64 ;
V_9 -> V_8 . V_81 = V_82 ;
if ( ! F_17 ( V_9 -> V_29 ) ) {
V_28 = F_53 ( V_9 -> V_29 ) ;
if ( V_28 ) {
F_42 ( & V_61 -> V_64 , L_22 ) ;
return V_28 ;
}
}
V_28 = F_54 ( & V_9 -> V_8 ) ;
if ( V_28 ) {
F_42 ( & V_61 -> V_64 , L_23 ) ;
goto V_83;
}
V_39 = F_55 ( V_61 , 0 ) ;
if ( V_39 < 0 ) {
F_56 ( & V_61 -> V_64 , L_24 ) ;
return 0 ;
}
V_9 -> V_35 = F_57 ( - 1 , 0 , V_9 -> V_8 . V_24 , 0 ) ;
if ( F_23 ( V_9 -> V_35 ) ) {
F_48 ( & V_61 -> V_64 , L_25 ) ;
return 0 ;
}
V_9 -> V_36 = F_58 ( V_63 , V_9 -> V_8 . V_24 ,
V_9 -> V_35 , 0 , & V_84 , NULL ) ;
if ( F_59 ( ! V_9 -> V_36 ) ) {
F_42 ( & V_61 -> V_64 , L_26 ) ;
F_60 ( V_9 -> V_35 , V_9 -> V_8 . V_24 ) ;
V_28 = - V_85 ;
goto V_86;
}
F_61 ( V_39 , F_29 ) ;
for ( V_54 = 0 ; V_54 < V_9 -> V_8 . V_24 ; V_54 ++ ) {
F_62 ( V_54 + V_9 -> V_35 , & V_87 ,
V_88 ) ;
F_63 ( V_54 + V_9 -> V_35 , V_89 ) ;
F_64 ( V_54 + V_9 -> V_35 , V_9 ) ;
}
F_65 ( V_39 , V_9 ) ;
F_56 ( & V_61 -> V_64 , L_27 ) ;
return 0 ;
V_86:
F_56 ( & V_61 -> V_64 , L_28 ) ;
if ( F_66 ( & V_9 -> V_8 ) )
F_42 ( & V_61 -> V_64 , L_29 ) ;
V_83:
if ( ! F_17 ( V_9 -> V_29 ) )
F_67 ( V_9 -> V_29 ) ;
return V_28 ;
}
static int F_68 ( struct V_90 * V_64 )
{
struct V_9 * V_9 = F_69 ( V_64 ) ;
int V_54 , V_91 = F_32 ( V_9 -> V_8 . V_24 , V_56 ) ;
void T_2 * V_92 ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
V_92 = V_9 -> V_1 + V_54 * sizeof( int * ) ;
if ( V_9 -> V_16 . V_31 != - 1 )
V_9 -> V_73 [ V_54 ] . V_31 =
F_4 ( V_9 -> V_16 . V_31 + V_92 ) ;
if ( V_9 -> V_16 . V_44 != - 1 )
V_9 -> V_73 [ V_54 ] . V_44 =
F_4 ( V_9 -> V_16 . V_44 + V_92 ) ;
V_9 -> V_73 [ V_54 ] . V_23 = F_4 ( V_9 -> V_16 . V_23 +
V_92 ) ;
V_9 -> V_73 [ V_54 ] . V_17 = F_4 ( V_9 -> V_16 . V_17 +
V_92 ) ;
V_9 -> V_73 [ V_54 ] . V_41 = F_4 ( V_9 -> V_16 . V_41 + V_92 ) ;
}
return 0 ;
}
static int F_70 ( struct V_90 * V_64 )
{
struct V_9 * V_9 = F_69 ( V_64 ) ;
int V_54 , V_91 = F_32 ( V_9 -> V_8 . V_24 , V_56 ) ;
void T_2 * V_92 ;
T_1 V_93 , V_21 ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
V_92 = V_9 -> V_1 + V_54 * sizeof( int * ) ;
if ( V_54 == V_91 - 1 ) {
V_93 = ( 1 << ( V_9 -> V_8 . V_24 - V_54 *
V_56 ) ) - 1 ;
if ( V_9 -> V_16 . V_31 != - 1 )
F_71 ( V_31 , V_92 , V_93 , V_21 ) ;
if ( V_9 -> V_16 . V_44 != - 1 )
F_71 ( V_44 , V_92 , V_93 , V_21 ) ;
F_71 ( V_23 , V_92 , V_93 , V_21 ) ;
F_71 ( V_17 , V_92 , V_93 , V_21 ) ;
F_71 ( V_41 , V_92 , V_93 , V_21 ) ;
}
F_6 ( V_9 -> V_73 [ V_54 ] . V_23 , V_9 -> V_16 . V_23 +
V_92 ) ;
F_6 ( V_9 -> V_73 [ V_54 ] . V_17 , V_9 -> V_16 . V_17 +
V_92 ) ;
if ( V_9 -> V_16 . V_44 != - 1 )
F_6 ( V_9 -> V_73 [ V_54 ] . V_44 ,
V_9 -> V_16 . V_44 + V_92 ) ;
F_6 ( V_9 -> V_73 [ V_54 ] . V_41 , V_9 -> V_16 . V_41 + V_92 ) ;
if ( V_9 -> V_16 . V_31 != - 1 )
F_6 ( V_9 -> V_73 [ V_54 ] . V_31 ,
V_9 -> V_16 . V_31 + V_92 ) ;
}
return 0 ;
}
static int T_3 F_72 ( void )
{
return F_73 ( & V_94 ) ;
}
