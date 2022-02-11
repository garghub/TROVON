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
static void F_13 ( struct V_1 * V_1 , int V_42 )
{
if ( V_42 )
F_2 ( V_1 , V_43 , 0x1 ) ;
else
F_5 ( V_1 , V_43 , 0x1 ) ;
}
static inline int F_14 ( struct V_1 * V_1 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_46 ) ) )
return 1 ;
F_15 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_16 ( struct V_7 * V_8 ,
const T_3 * * V_47 , T_3 * * V_48 )
{
void T_1 * V_49 , * V_50 , * V_51 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_49 = F_1 ( V_1 , V_52 ) ;
V_50 = F_1 ( V_1 , V_53 ) ;
V_51 = F_1 ( V_1 , V_46 ) ;
F_4 ( 0x0 , V_51 ) ;
if ( V_47 && * V_47 )
F_4 ( * ( * V_47 ) ++ , V_49 ) ;
else
F_4 ( 0 , V_49 ) ;
if ( F_14 ( V_1 ) < 0 ) {
F_17 ( & V_8 -> V_54 , L_1 ) ;
return - 1 ;
}
if ( V_48 && * V_48 )
* ( * V_48 ) ++ = F_3 ( V_50 ) ;
return 1 ;
}
static inline int
F_18 ( struct V_7 * V_8 ,
const T_4 * * V_47 , T_4 * * V_48 )
{
void T_1 * V_49 , * V_50 , * V_51 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_49 = F_1 ( V_1 , V_52 ) ;
V_50 = F_1 ( V_1 , V_53 ) ;
V_51 = F_1 ( V_1 , V_46 ) ;
F_4 ( 0x0 , V_51 ) ;
if ( V_47 && * V_47 )
F_4 ( F_19 ( F_20 ( ( * V_47 ) ++ ) ) , V_49 ) ;
else
F_4 ( 0 , V_49 ) ;
if ( F_14 ( V_1 ) < 0 ) {
F_17 ( & V_8 -> V_54 , L_1 ) ;
return - 1 ;
}
if ( V_48 && * V_48 )
F_21 ( F_22 ( F_3 ( V_50 ) ) , ( * V_48 ) ++ ) ;
return 1 ;
}
static unsigned int
F_23 ( struct V_7 * V_8 , struct V_35 * V_55 )
{
unsigned int V_56 ;
int V_57 ;
V_57 = V_8 -> V_38 ;
V_56 = V_55 -> V_58 ;
if ( V_57 == 8 ) {
const T_3 * V_59 = V_55 -> V_47 ;
T_3 * V_60 = V_55 -> V_48 ;
do {
if ( F_16 ( V_8 , & V_59 , & V_60 ) < 0 )
goto V_61;
V_56 -- ;
} while ( V_56 );
} else if ( V_57 == 16 ) {
const T_4 * V_59 = V_55 -> V_47 ;
T_4 * V_60 = V_55 -> V_48 ;
do {
if ( F_18 ( V_8 , & V_59 , & V_60 ) < 0 )
goto V_61;
V_56 -= 2 ;
} while ( V_56 );
}
V_61:
return V_55 -> V_58 - V_56 ;
}
static int F_24 ( struct V_62 * V_15 ,
struct V_63 * V_64 )
{
struct V_1 * V_1 = F_7 ( V_15 ) ;
struct V_7 * V_8 = V_64 -> V_8 ;
struct V_35 * V_36 = NULL ;
int V_65 = 0 ;
int V_66 = 0 ;
int V_67 = 0 ;
V_66 = F_12 ( V_8 , NULL ) ;
if ( V_66 < 0 )
goto V_68;
F_25 (t, &m->transfers, transfer_list) {
if ( V_65 || V_36 -> V_40 || V_36 -> V_38 ) {
V_65 = 1 ;
V_66 = F_12 ( V_8 , V_36 ) ;
if ( V_66 < 0 )
break;
if ( ! V_36 -> V_40 && ! V_36 -> V_38 )
V_65 = 0 ;
}
if ( ! V_67 ) {
F_13 ( V_1 , 1 ) ;
V_67 = 1 ;
}
if ( V_36 -> V_58 )
V_64 -> V_69 += F_23 ( V_8 , V_36 ) ;
if ( V_36 -> V_70 )
F_15 ( V_36 -> V_70 ) ;
if ( V_36 -> V_71 ) {
F_13 ( V_1 , 0 ) ;
V_67 = 0 ;
}
}
V_68:
if ( V_67 )
F_13 ( V_1 , 0 ) ;
V_64 -> V_66 = V_66 ;
F_26 ( V_15 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
F_13 ( V_1 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_72 * V_73 )
{
const struct V_74 * V_75 ;
const struct V_13 * V_14 ;
struct V_62 * V_15 ;
struct V_1 * V_8 ;
struct V_76 * V_77 ;
unsigned long V_10 ;
int V_66 = 0 ;
V_15 = F_29 ( & V_73 -> V_54 , sizeof( * V_8 ) ) ;
if ( V_15 == NULL ) {
F_30 ( & V_73 -> V_54 , L_2 ) ;
return - V_78 ;
}
if ( V_73 -> V_79 != - 1 )
V_15 -> V_80 = V_73 -> V_79 ;
if ( V_73 -> V_54 . V_81 ) {
T_2 V_82 ;
if ( ! F_31 ( V_73 -> V_54 . V_81 , L_3 ,
& V_82 ) )
V_15 -> V_80 = V_82 ;
}
V_15 -> V_83 = V_33 | V_31 ;
V_15 -> V_84 = F_24 ;
V_15 -> V_85 = V_86 ;
V_15 -> V_87 = F_32 ( 8 ) | F_32 ( 16 ) ;
V_15 -> V_88 = true ;
F_33 ( V_73 , V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_8 -> V_15 = V_15 ;
V_75 = F_34 ( V_89 , & V_73 -> V_54 ) ;
V_14 = ( V_75 ) ? V_75 -> V_90 : & V_91 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_16 = F_35 ( & V_73 -> V_54 , NULL ) ;
if ( F_36 ( V_8 -> V_16 ) ) {
V_66 = F_37 ( V_8 -> V_16 ) ;
goto V_61;
}
V_66 = F_38 ( V_8 -> V_16 ) ;
if ( V_66 )
goto V_61;
V_10 = F_8 ( V_8 -> V_16 ) ;
V_15 -> V_37 = F_9 ( V_10 , V_14 -> V_92 ) ;
V_15 -> V_93 = F_9 ( V_10 , V_14 -> V_94 ) ;
V_77 = F_39 ( V_73 , V_95 , 0 ) ;
V_8 -> V_3 = F_40 ( & V_73 -> V_54 , V_77 ) ;
if ( F_36 ( V_8 -> V_3 ) ) {
V_66 = F_37 ( V_8 -> V_3 ) ;
goto V_96;
}
F_41 ( & V_73 -> V_54 ) ;
F_42 ( & V_73 -> V_54 ) ;
F_43 ( & V_73 -> V_54 , V_97 ) ;
F_44 ( & V_73 -> V_54 ) ;
V_66 = F_27 ( V_8 ) ;
if ( V_66 < 0 )
goto V_98;
F_45 ( & V_73 -> V_54 ) ;
F_46 ( & V_73 -> V_54 ) ;
V_15 -> V_54 . V_81 = V_73 -> V_54 . V_81 ;
V_66 = F_47 ( V_15 ) ;
if ( V_66 < 0 )
goto V_98;
return V_66 ;
V_98:
F_48 ( & V_73 -> V_54 ) ;
V_96:
F_49 ( V_8 -> V_16 ) ;
V_61:
F_50 ( V_15 ) ;
return V_66 ;
}
static int F_51 ( struct V_72 * V_73 )
{
struct V_62 * V_15 = F_52 ( V_73 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_53 ( & V_73 -> V_54 ) ;
F_49 ( V_8 -> V_16 ) ;
F_54 ( V_15 ) ;
F_48 ( & V_73 -> V_54 ) ;
return 0 ;
}
static int F_55 ( struct V_99 * V_54 )
{
struct V_62 * V_15 = F_56 ( V_54 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_49 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_57 ( struct V_99 * V_54 )
{
struct V_62 * V_15 = F_56 ( V_54 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
return F_38 ( V_8 -> V_16 ) ;
}
