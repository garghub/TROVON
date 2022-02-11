static inline void T_1 * F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
return V_1 -> V_3 + V_2 ;
}
static inline void
F_2 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_4 )
{
void T_1 * V_5 = F_1 ( V_1 , V_2 ) ;
T_2 V_6 ;
V_6 = F_3 ( V_5 ) ;
V_6 |= V_4 ;
F_4 ( V_6 , V_5 ) ;
}
static inline void
F_5 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_4 )
{
void T_1 * V_5 = F_1 ( V_1 , V_2 ) ;
T_2 V_6 ;
V_6 = F_3 ( V_5 ) ;
V_6 &= ~ V_4 ;
F_4 ( V_6 , V_5 ) ;
}
static int F_6 ( struct V_7 * V_8 , unsigned int V_9 )
{
T_2 V_10 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_2 ;
struct V_1 * V_1 ;
const struct V_13 * V_14 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_14 = V_1 -> V_14 ;
V_10 = F_8 ( V_1 -> V_16 ) ;
if ( V_14 -> V_17 == V_18 ) {
unsigned int V_16 , V_19 , V_20 , V_21 , V_22 ;
unsigned int V_23 , V_24 , V_25 ;
V_25 = V_9 ;
V_23 = 0 ;
V_24 = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
V_21 = 0x1 << V_20 ;
V_19 = V_10 / V_21 ;
V_19 = F_9 ( V_19 , V_9 ) ;
if ( ( V_19 == 0 ) || ( V_19 > 15 ) )
continue;
V_16 = V_10 / ( V_19 * V_21 ) ;
V_22 = V_9 - V_16 ;
if ( V_22 < V_25 ) {
V_23 = V_19 ;
V_24 = V_20 ;
V_25 = V_22 ;
}
}
if ( ( V_24 == 0 ) && ( V_23 == 0 ) )
return - V_26 ;
V_12 = ( ( V_24 & 0x6 ) << 5 ) |
( ( V_24 & 0x1 ) << 4 ) | V_23 ;
} else {
V_11 = F_9 ( V_10 , V_9 ) ;
V_11 = F_10 ( V_11 , 2 ) ;
if ( V_11 > 30 )
return - V_26 ;
if ( V_11 < 4 )
V_11 = 4 ;
V_12 = 0x10 + V_11 / 2 ;
}
V_2 = F_3 ( F_1 ( V_1 , V_27 ) ) ;
V_2 = ( ( V_2 & ~ V_14 -> V_28 ) | V_12 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_27 ) ) ;
return 0 ;
}
static void
F_11 ( struct V_7 * V_8 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_27 ) ) ;
V_2 &= ~ V_29 ;
if ( V_8 -> V_30 & V_31 )
V_2 |= V_32 ;
if ( V_8 -> V_30 & V_33 )
V_2 |= V_34 ;
F_4 ( V_2 , F_1 ( V_1 , V_27 ) ) ;
}
static int
F_12 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_1 * V_1 ;
unsigned int V_9 = V_8 -> V_37 ;
unsigned int V_38 = V_8 -> V_38 ;
int V_39 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
if ( ( V_36 != NULL ) && V_36 -> V_40 )
V_9 = V_36 -> V_40 ;
if ( ( V_36 != NULL ) && V_36 -> V_38 )
V_38 = V_36 -> V_38 ;
F_11 ( V_8 ) ;
V_39 = F_6 ( V_8 , V_9 ) ;
if ( V_39 )
return V_39 ;
if ( V_38 == 16 )
F_2 ( V_1 , V_27 ,
V_41 ) ;
else
F_5 ( V_1 , V_27 ,
V_41 ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 , bool V_42 )
{
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
F_5 ( V_1 , V_43 , V_44 ) ;
F_2 ( V_1 , V_43 ,
F_14 ( V_8 -> V_45 ) ) ;
if ( ! V_42 )
F_2 ( V_1 , V_43 , 0x1 ) ;
else
F_5 ( V_1 , V_43 , 0x1 ) ;
}
static inline int F_15 ( struct V_1 * V_1 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_48 ) ) )
return 1 ;
F_16 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_17 ( struct V_7 * V_8 ,
const T_3 * * V_49 , T_3 * * V_50 )
{
void T_1 * V_51 , * V_52 , * V_53 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_51 = F_1 ( V_1 , V_54 ) ;
V_52 = F_1 ( V_1 , V_55 ) ;
V_53 = F_1 ( V_1 , V_48 ) ;
F_4 ( 0x0 , V_53 ) ;
if ( V_49 && * V_49 )
F_4 ( * ( * V_49 ) ++ , V_51 ) ;
else
F_4 ( 0 , V_51 ) ;
if ( F_15 ( V_1 ) < 0 ) {
F_18 ( & V_8 -> V_56 , L_1 ) ;
return - 1 ;
}
if ( V_50 && * V_50 )
* ( * V_50 ) ++ = F_3 ( V_52 ) ;
return 1 ;
}
static inline int
F_19 ( struct V_7 * V_8 ,
const T_4 * * V_49 , T_4 * * V_50 )
{
void T_1 * V_51 , * V_52 , * V_53 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_51 = F_1 ( V_1 , V_54 ) ;
V_52 = F_1 ( V_1 , V_55 ) ;
V_53 = F_1 ( V_1 , V_48 ) ;
F_4 ( 0x0 , V_53 ) ;
if ( V_49 && * V_49 )
F_4 ( F_20 ( F_21 ( ( * V_49 ) ++ ) ) , V_51 ) ;
else
F_4 ( 0 , V_51 ) ;
if ( F_15 ( V_1 ) < 0 ) {
F_18 ( & V_8 -> V_56 , L_1 ) ;
return - 1 ;
}
if ( V_50 && * V_50 )
F_22 ( F_23 ( F_3 ( V_52 ) ) , ( * V_50 ) ++ ) ;
return 1 ;
}
static unsigned int
F_24 ( struct V_7 * V_8 , struct V_35 * V_57 )
{
unsigned int V_58 ;
int V_59 ;
V_59 = V_8 -> V_38 ;
V_58 = V_57 -> V_60 ;
if ( V_59 == 8 ) {
const T_3 * V_61 = V_57 -> V_49 ;
T_3 * V_62 = V_57 -> V_50 ;
do {
if ( F_17 ( V_8 , & V_61 , & V_62 ) < 0 )
goto V_63;
V_58 -- ;
} while ( V_58 );
} else if ( V_59 == 16 ) {
const T_4 * V_61 = V_57 -> V_49 ;
T_4 * V_62 = V_57 -> V_50 ;
do {
if ( F_19 ( V_8 , & V_61 , & V_62 ) < 0 )
goto V_63;
V_58 -= 2 ;
} while ( V_58 );
}
V_63:
return V_57 -> V_60 - V_58 ;
}
static int F_25 ( struct V_64 * V_15 ,
struct V_7 * V_8 ,
struct V_35 * V_36 )
{
int V_65 = 0 ;
V_65 = F_12 ( V_8 , V_36 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( V_36 -> V_60 )
F_24 ( V_8 , V_36 ) ;
return V_65 ;
}
static int F_26 ( struct V_7 * V_8 )
{
return F_12 ( V_8 , NULL ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_43 , 0x1 ) ;
return 0 ;
}
static int F_28 ( struct V_66 * V_67 )
{
const struct V_68 * V_69 ;
const struct V_13 * V_14 ;
struct V_64 * V_15 ;
struct V_1 * V_8 ;
struct V_70 * V_71 ;
unsigned long V_10 ;
int V_65 = 0 ;
V_15 = F_29 ( & V_67 -> V_56 , sizeof( * V_8 ) ) ;
if ( V_15 == NULL ) {
F_30 ( & V_67 -> V_56 , L_2 ) ;
return - V_72 ;
}
if ( V_67 -> V_73 != - 1 )
V_15 -> V_74 = V_67 -> V_73 ;
if ( V_67 -> V_56 . V_75 ) {
T_2 V_76 ;
if ( ! F_31 ( V_67 -> V_56 . V_75 , L_3 ,
& V_76 ) )
V_15 -> V_74 = V_76 ;
}
V_15 -> V_77 = V_33 | V_31 ;
V_15 -> V_78 = F_13 ;
V_15 -> V_79 = F_25 ;
V_15 -> V_80 = V_81 ;
V_15 -> V_82 = F_26 ;
V_15 -> V_83 = F_32 ( 8 ) | F_32 ( 16 ) ;
V_15 -> V_84 = true ;
F_33 ( V_67 , V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_8 -> V_15 = V_15 ;
V_69 = F_34 ( V_85 , & V_67 -> V_56 ) ;
V_14 = ( V_69 ) ? V_69 -> V_86 : & V_87 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_16 = F_35 ( & V_67 -> V_56 , NULL ) ;
if ( F_36 ( V_8 -> V_16 ) ) {
V_65 = F_37 ( V_8 -> V_16 ) ;
goto V_63;
}
V_65 = F_38 ( V_8 -> V_16 ) ;
if ( V_65 )
goto V_63;
V_10 = F_8 ( V_8 -> V_16 ) ;
if ( F_39 ( V_67 -> V_56 . V_75 ,
L_4 ) )
V_15 -> V_37 = F_40 ( V_14 -> V_88 ,
F_9 ( V_10 , V_14 -> V_89 ) ) ;
else if ( V_14 -> V_89 )
V_15 -> V_37 =
F_9 ( V_10 , V_14 -> V_89 ) ;
else
V_15 -> V_37 = V_14 -> V_88 ;
V_15 -> V_90 = F_9 ( V_10 , V_14 -> V_91 ) ;
V_71 = F_41 ( V_67 , V_92 , 0 ) ;
V_8 -> V_3 = F_42 ( & V_67 -> V_56 , V_71 ) ;
if ( F_36 ( V_8 -> V_3 ) ) {
V_65 = F_37 ( V_8 -> V_3 ) ;
goto V_93;
}
F_43 ( & V_67 -> V_56 ) ;
F_44 ( & V_67 -> V_56 ) ;
F_45 ( & V_67 -> V_56 , V_94 ) ;
F_46 ( & V_67 -> V_56 ) ;
V_65 = F_27 ( V_8 ) ;
if ( V_65 < 0 )
goto V_95;
F_47 ( & V_67 -> V_56 ) ;
F_48 ( & V_67 -> V_56 ) ;
V_15 -> V_56 . V_75 = V_67 -> V_56 . V_75 ;
V_65 = F_49 ( V_15 ) ;
if ( V_65 < 0 )
goto V_95;
return V_65 ;
V_95:
F_50 ( & V_67 -> V_56 ) ;
V_93:
F_51 ( V_8 -> V_16 ) ;
V_63:
F_52 ( V_15 ) ;
return V_65 ;
}
static int F_53 ( struct V_66 * V_67 )
{
struct V_64 * V_15 = F_54 ( V_67 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_55 ( & V_67 -> V_56 ) ;
F_51 ( V_8 -> V_16 ) ;
F_56 ( V_15 ) ;
F_50 ( & V_67 -> V_56 ) ;
return 0 ;
}
static int F_57 ( struct V_96 * V_56 )
{
struct V_64 * V_15 = F_58 ( V_56 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_51 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_59 ( struct V_96 * V_56 )
{
struct V_64 * V_15 = F_58 ( V_56 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
return F_38 ( V_8 -> V_16 ) ;
}
