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
static int F_6 ( struct V_1 * V_1 , int V_7 )
{
if ( V_7 == 16 ) {
F_2 ( V_1 , V_8 ,
V_9 ) ;
} else if ( V_7 == 8 ) {
F_5 ( V_1 , V_8 ,
V_9 ) ;
} else {
F_7 ( L_1
L_2 , V_7 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_13 )
{
T_2 V_14 ;
T_2 V_15 ;
T_2 V_16 ;
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_14 = V_1 -> V_18 -> V_19 ;
V_15 = F_10 ( V_14 , V_13 ) ;
V_15 = F_11 ( V_15 , 2 ) ;
if ( V_15 > 30 )
return - V_10 ;
if ( V_15 < 4 )
V_15 = 4 ;
V_16 = 0x10 + V_15 / 2 ;
V_2 = F_3 ( F_1 ( V_1 , V_8 ) ) ;
V_2 = ( ( V_2 & ~ V_20 ) | V_16 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_8 ) ) ;
return 0 ;
}
static int
F_12 ( struct V_11 * V_12 , struct V_21 * V_22 )
{
struct V_1 * V_1 ;
unsigned int V_13 = V_12 -> V_23 ;
unsigned int V_24 = V_12 -> V_24 ;
int V_25 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_22 != NULL ) && V_22 -> V_26 )
V_13 = V_22 -> V_26 ;
if ( ( V_22 != NULL ) && V_22 -> V_24 )
V_24 = V_22 -> V_24 ;
V_25 = F_8 ( V_12 , V_13 ) ;
if ( V_25 )
return V_25 ;
return F_6 ( V_1 , V_24 ) ;
}
static void F_13 ( struct V_1 * V_1 , int V_27 )
{
if ( V_27 )
F_2 ( V_1 , V_28 , 0x1 ) ;
else
F_5 ( V_1 , V_28 , 0x1 ) ;
}
static inline int F_14 ( struct V_1 * V_1 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_31 ) ) )
return 1 ;
else
F_15 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_16 ( struct V_11 * V_12 ,
const T_3 * * V_32 , T_3 * * V_33 )
{
void T_1 * V_34 , * V_35 , * V_36 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_34 = F_1 ( V_1 , V_37 ) ;
V_35 = F_1 ( V_1 , V_38 ) ;
V_36 = F_1 ( V_1 , V_31 ) ;
F_4 ( 0x0 , V_36 ) ;
if ( V_32 && * V_32 )
F_4 ( * ( * V_32 ) ++ , V_34 ) ;
else
F_4 ( 0 , V_34 ) ;
if ( F_14 ( V_1 ) < 0 ) {
F_17 ( & V_12 -> V_39 , L_3 ) ;
return - 1 ;
}
if ( V_33 && * V_33 )
* ( * V_33 ) ++ = F_3 ( V_35 ) ;
return 1 ;
}
static inline int
F_18 ( struct V_11 * V_12 ,
const T_4 * * V_32 , T_4 * * V_33 )
{
void T_1 * V_34 , * V_35 , * V_36 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_34 = F_1 ( V_1 , V_37 ) ;
V_35 = F_1 ( V_1 , V_38 ) ;
V_36 = F_1 ( V_1 , V_31 ) ;
F_4 ( 0x0 , V_36 ) ;
if ( V_32 && * V_32 )
F_4 ( F_19 ( F_20 ( ( * V_32 ) ++ ) ) , V_34 ) ;
else
F_4 ( 0 , V_34 ) ;
if ( F_14 ( V_1 ) < 0 ) {
F_17 ( & V_12 -> V_39 , L_3 ) ;
return - 1 ;
}
if ( V_33 && * V_33 )
F_21 ( F_22 ( F_3 ( V_35 ) ) , ( * V_33 ) ++ ) ;
return 1 ;
}
static unsigned int
F_23 ( struct V_11 * V_12 , struct V_21 * V_40 )
{
struct V_1 * V_1 ;
unsigned int V_41 ;
int V_42 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_42 = V_12 -> V_24 ;
V_41 = V_40 -> V_43 ;
if ( V_42 == 8 ) {
const T_3 * V_44 = V_40 -> V_32 ;
T_3 * V_45 = V_40 -> V_33 ;
do {
if ( F_16 ( V_12 , & V_44 , & V_45 ) < 0 )
goto V_46;
V_41 -- ;
} while ( V_41 );
} else if ( V_42 == 16 ) {
const T_4 * V_44 = V_40 -> V_32 ;
T_4 * V_45 = V_40 -> V_33 ;
do {
if ( F_18 ( V_12 , & V_44 , & V_45 ) < 0 )
goto V_46;
V_41 -= 2 ;
} while ( V_41 );
}
V_46:
return V_40 -> V_43 - V_41 ;
}
static void F_24 ( struct V_47 * V_48 )
{
struct V_1 * V_1 =
F_25 ( V_48 , struct V_1 , V_48 ) ;
F_26 ( & V_1 -> V_49 ) ;
while ( ! F_27 ( & V_1 -> V_50 ) ) {
struct V_51 * V_52 ;
struct V_11 * V_12 ;
struct V_21 * V_22 = NULL ;
int V_53 = 0 ;
int V_54 = 0 ;
int V_55 = 0 ;
V_52 = F_25 ( V_1 -> V_50 . V_56 , struct V_51 ,
V_57 ) ;
F_28 ( & V_52 -> V_57 ) ;
F_29 ( & V_1 -> V_49 ) ;
V_12 = V_52 -> V_12 ;
V_54 = F_12 ( V_12 , NULL ) ;
if ( V_54 < 0 )
goto V_58;
F_30 (t, &m->transfers, transfer_list) {
if ( V_53 || V_22 -> V_26 || V_22 -> V_24 ) {
V_53 = 1 ;
V_54 = F_12 ( V_12 , V_22 ) ;
if ( V_54 < 0 )
break;
if ( ! V_22 -> V_26 && ! V_22 -> V_24 )
V_53 = 0 ;
}
if ( ! V_55 ) {
F_13 ( V_1 , 1 ) ;
V_55 = 1 ;
}
if ( V_22 -> V_43 )
V_52 -> V_59 +=
F_23 ( V_12 , V_22 ) ;
if ( V_22 -> V_60 )
F_15 ( V_22 -> V_60 ) ;
if ( V_22 -> V_61 ) {
F_13 ( V_1 , 0 ) ;
V_55 = 0 ;
}
}
V_58:
if ( V_55 )
F_13 ( V_1 , 0 ) ;
V_52 -> V_54 = V_54 ;
V_52 -> V_62 ( V_52 -> V_63 ) ;
F_26 ( & V_1 -> V_49 ) ;
}
F_29 ( & V_1 -> V_49 ) ;
}
static int T_5 F_31 ( struct V_1 * V_1 )
{
F_13 ( V_1 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
if ( V_1 -> V_18 -> V_64 )
F_2 ( V_1 , V_8 ,
( 1 << 14 ) ) ;
if ( ( V_12 -> V_23 == 0 )
|| ( V_12 -> V_23 > V_1 -> V_65 ) )
V_12 -> V_23 = V_1 -> V_65 ;
if ( V_12 -> V_23 < V_1 -> V_66 ) {
F_17 ( & V_12 -> V_39 , L_4 ,
V_12 -> V_23 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_33 ( struct V_11 * V_12 , struct V_51 * V_52 )
{
struct V_1 * V_1 ;
struct V_21 * V_22 = NULL ;
unsigned long V_67 ;
V_52 -> V_59 = 0 ;
V_52 -> V_54 = 0 ;
if ( F_27 ( & V_52 -> V_68 ) || ! V_52 -> V_62 )
return - V_10 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
F_30 (t, &m->transfers, transfer_list) {
unsigned int V_24 = V_12 -> V_24 ;
if ( V_22 -> V_32 == NULL && V_22 -> V_33 == NULL && V_22 -> V_43 ) {
F_17 ( & V_12 -> V_39 ,
L_5
L_6 ) ;
goto V_69;
}
if ( V_22 -> V_24 )
V_24 = V_22 -> V_24 ;
if ( ( V_24 != 8 ) && ( V_24 != 16 ) ) {
F_17 ( & V_12 -> V_39 ,
L_5
L_7 ,
V_24 ) ;
goto V_69;
}
if ( ( V_22 -> V_24 == 16 ) && ( V_22 -> V_43 & 1 ) ) {
F_17 ( & V_12 -> V_39 ,
L_5
L_8 ,
V_22 -> V_43 ) ;
goto V_69;
}
if ( V_22 -> V_26 && V_22 -> V_26 < V_1 -> V_66 ) {
F_17 ( & V_12 -> V_39 ,
L_5
L_9
L_10 ,
V_1 -> V_66 , V_22 -> V_26 ) ;
goto V_69;
}
}
F_34 ( & V_1 -> V_49 , V_67 ) ;
F_35 ( & V_52 -> V_57 , & V_1 -> V_50 ) ;
F_36 ( V_70 , & V_1 -> V_48 ) ;
F_37 ( & V_1 -> V_49 , V_67 ) ;
return 0 ;
V_69:
V_52 -> V_54 = - V_10 ;
if ( V_52 -> V_62 )
V_52 -> V_62 ( V_52 -> V_63 ) ;
return - V_10 ;
}
static int T_5 F_38 ( struct V_71 * V_72 )
{
struct V_73 * V_17 ;
struct V_1 * V_12 ;
struct V_74 * V_75 ;
struct V_76 * V_18 ;
int V_54 = 0 ;
V_18 = V_72 -> V_39 . V_77 ;
V_17 = F_39 ( & V_72 -> V_39 , sizeof *V_12 ) ;
if ( V_17 == NULL ) {
F_40 ( & V_72 -> V_39 , L_11 ) ;
return - V_78 ;
}
if ( V_72 -> V_79 != - 1 )
V_17 -> V_80 = V_72 -> V_79 ;
V_17 -> V_81 = 0 ;
V_17 -> V_82 = F_32 ;
V_17 -> V_83 = F_33 ;
V_17 -> V_84 = V_85 ;
F_41 ( & V_72 -> V_39 , V_17 ) ;
V_12 = F_9 ( V_17 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_65 = F_10 ( V_18 -> V_19 , 4 ) ;
V_12 -> V_66 = F_10 ( V_18 -> V_19 , 30 ) ;
V_75 = F_42 ( V_72 , V_86 , 0 ) ;
if ( V_75 == NULL ) {
V_54 = - V_87 ;
goto V_46;
}
if ( ! F_43 ( V_75 -> V_88 , ( V_75 -> V_89 - V_75 -> V_88 ) + 1 ,
F_44 ( & V_72 -> V_39 ) ) ) {
V_54 = - V_90 ;
goto V_46;
}
V_12 -> V_3 = F_45 ( V_75 -> V_88 , V_91 ) ;
F_46 ( & V_12 -> V_48 , F_24 ) ;
F_47 ( & V_12 -> V_49 ) ;
F_48 ( & V_12 -> V_50 ) ;
if ( F_31 ( V_12 ) < 0 )
goto V_92;
V_54 = F_49 ( V_17 ) ;
if ( V_54 < 0 )
goto V_92;
return V_54 ;
V_92:
F_50 ( V_75 -> V_88 , ( V_75 -> V_89 - V_75 -> V_88 ) + 1 ) ;
V_46:
F_51 ( V_17 ) ;
return V_54 ;
}
static int T_6 F_52 ( struct V_71 * V_72 )
{
struct V_73 * V_17 ;
struct V_1 * V_12 ;
struct V_74 * V_75 ;
V_17 = F_53 ( & V_72 -> V_39 ) ;
V_12 = F_9 ( V_17 ) ;
F_54 ( & V_12 -> V_48 ) ;
V_75 = F_42 ( V_72 , V_86 , 0 ) ;
F_50 ( V_75 -> V_88 , ( V_75 -> V_89 - V_75 -> V_88 ) + 1 ) ;
F_55 ( V_17 ) ;
return 0 ;
}
static int T_5 F_56 ( void )
{
V_70 = F_57 (
V_93 . V_94 . V_95 ) ;
if ( V_70 == NULL )
return - V_78 ;
return F_58 ( & V_93 , F_38 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( V_70 ) ;
F_61 ( & V_93 ) ;
F_62 ( V_70 ) ;
}
