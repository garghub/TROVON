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
V_14 = F_10 ( V_1 -> V_18 ) ;
V_15 = F_11 ( V_14 , V_13 ) ;
V_15 = F_12 ( V_15 , 2 ) ;
if ( V_15 > 30 )
return - V_10 ;
if ( V_15 < 4 )
V_15 = 4 ;
V_16 = 0x10 + V_15 / 2 ;
V_2 = F_3 ( F_1 ( V_1 , V_8 ) ) ;
V_2 = ( ( V_2 & ~ V_19 ) | V_16 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_8 ) ) ;
return 0 ;
}
static int
F_13 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_1 * V_1 ;
unsigned int V_13 = V_12 -> V_22 ;
unsigned int V_23 = V_12 -> V_23 ;
int V_24 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_21 != NULL ) && V_21 -> V_25 )
V_13 = V_21 -> V_25 ;
if ( ( V_21 != NULL ) && V_21 -> V_23 )
V_23 = V_21 -> V_23 ;
V_24 = F_8 ( V_12 , V_13 ) ;
if ( V_24 )
return V_24 ;
return F_6 ( V_1 , V_23 ) ;
}
static void F_14 ( struct V_1 * V_1 , int V_26 )
{
if ( V_26 )
F_2 ( V_1 , V_27 , 0x1 ) ;
else
F_5 ( V_1 , V_27 , 0x1 ) ;
}
static inline int F_15 ( struct V_1 * V_1 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_30 ) ) )
return 1 ;
else
F_16 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_17 ( struct V_11 * V_12 ,
const T_3 * * V_31 , T_3 * * V_32 )
{
void T_1 * V_33 , * V_34 , * V_35 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_33 = F_1 ( V_1 , V_36 ) ;
V_34 = F_1 ( V_1 , V_37 ) ;
V_35 = F_1 ( V_1 , V_30 ) ;
F_4 ( 0x0 , V_35 ) ;
if ( V_31 && * V_31 )
F_4 ( * ( * V_31 ) ++ , V_33 ) ;
else
F_4 ( 0 , V_33 ) ;
if ( F_15 ( V_1 ) < 0 ) {
F_18 ( & V_12 -> V_38 , L_3 ) ;
return - 1 ;
}
if ( V_32 && * V_32 )
* ( * V_32 ) ++ = F_3 ( V_34 ) ;
return 1 ;
}
static inline int
F_19 ( struct V_11 * V_12 ,
const T_4 * * V_31 , T_4 * * V_32 )
{
void T_1 * V_33 , * V_34 , * V_35 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_33 = F_1 ( V_1 , V_36 ) ;
V_34 = F_1 ( V_1 , V_37 ) ;
V_35 = F_1 ( V_1 , V_30 ) ;
F_4 ( 0x0 , V_35 ) ;
if ( V_31 && * V_31 )
F_4 ( F_20 ( F_21 ( ( * V_31 ) ++ ) ) , V_33 ) ;
else
F_4 ( 0 , V_33 ) ;
if ( F_15 ( V_1 ) < 0 ) {
F_18 ( & V_12 -> V_38 , L_3 ) ;
return - 1 ;
}
if ( V_32 && * V_32 )
F_22 ( F_23 ( F_3 ( V_34 ) ) , ( * V_32 ) ++ ) ;
return 1 ;
}
static unsigned int
F_24 ( struct V_11 * V_12 , struct V_20 * V_39 )
{
struct V_1 * V_1 ;
unsigned int V_40 ;
int V_41 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_41 = V_12 -> V_23 ;
V_40 = V_39 -> V_42 ;
if ( V_41 == 8 ) {
const T_3 * V_43 = V_39 -> V_31 ;
T_3 * V_44 = V_39 -> V_32 ;
do {
if ( F_17 ( V_12 , & V_43 , & V_44 ) < 0 )
goto V_45;
V_40 -- ;
} while ( V_40 );
} else if ( V_41 == 16 ) {
const T_4 * V_43 = V_39 -> V_31 ;
T_4 * V_44 = V_39 -> V_32 ;
do {
if ( F_19 ( V_12 , & V_43 , & V_44 ) < 0 )
goto V_45;
V_40 -= 2 ;
} while ( V_40 );
}
V_45:
return V_39 -> V_42 - V_40 ;
}
static void F_25 ( struct V_46 * V_47 )
{
struct V_1 * V_1 =
F_26 ( V_47 , struct V_1 , V_47 ) ;
F_27 ( & V_1 -> V_48 ) ;
while ( ! F_28 ( & V_1 -> V_49 ) ) {
struct V_50 * V_51 ;
struct V_11 * V_12 ;
struct V_20 * V_21 = NULL ;
int V_52 = 0 ;
int V_53 = 0 ;
int V_54 = 0 ;
V_51 = F_26 ( V_1 -> V_49 . V_55 , struct V_50 ,
V_56 ) ;
F_29 ( & V_51 -> V_56 ) ;
F_30 ( & V_1 -> V_48 ) ;
V_12 = V_51 -> V_12 ;
V_53 = F_13 ( V_12 , NULL ) ;
if ( V_53 < 0 )
goto V_57;
F_31 (t, &m->transfers, transfer_list) {
if ( V_52 || V_21 -> V_25 || V_21 -> V_23 ) {
V_52 = 1 ;
V_53 = F_13 ( V_12 , V_21 ) ;
if ( V_53 < 0 )
break;
if ( ! V_21 -> V_25 && ! V_21 -> V_23 )
V_52 = 0 ;
}
if ( ! V_54 ) {
F_14 ( V_1 , 1 ) ;
V_54 = 1 ;
}
if ( V_21 -> V_42 )
V_51 -> V_58 +=
F_24 ( V_12 , V_21 ) ;
if ( V_21 -> V_59 )
F_16 ( V_21 -> V_59 ) ;
if ( V_21 -> V_60 ) {
F_14 ( V_1 , 0 ) ;
V_54 = 0 ;
}
}
V_57:
if ( V_54 )
F_14 ( V_1 , 0 ) ;
V_51 -> V_53 = V_53 ;
V_51 -> V_61 ( V_51 -> V_62 ) ;
F_27 ( & V_1 -> V_48 ) ;
}
F_30 ( & V_1 -> V_48 ) ;
}
static int T_5 F_32 ( struct V_1 * V_1 )
{
F_14 ( V_1 , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_12 -> V_22 == 0 )
|| ( V_12 -> V_22 > V_1 -> V_63 ) )
V_12 -> V_22 = V_1 -> V_63 ;
if ( V_12 -> V_22 < V_1 -> V_64 ) {
F_18 ( & V_12 -> V_38 , L_4 ,
V_12 -> V_22 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_34 ( struct V_11 * V_12 , struct V_50 * V_51 )
{
struct V_1 * V_1 ;
struct V_20 * V_21 = NULL ;
unsigned long V_65 ;
V_51 -> V_58 = 0 ;
V_51 -> V_53 = 0 ;
if ( F_28 ( & V_51 -> V_66 ) || ! V_51 -> V_61 )
return - V_10 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
F_31 (t, &m->transfers, transfer_list) {
unsigned int V_23 = V_12 -> V_23 ;
if ( V_21 -> V_31 == NULL && V_21 -> V_32 == NULL && V_21 -> V_42 ) {
F_18 ( & V_12 -> V_38 ,
L_5
L_6 ) ;
goto V_67;
}
if ( V_21 -> V_23 )
V_23 = V_21 -> V_23 ;
if ( ( V_23 != 8 ) && ( V_23 != 16 ) ) {
F_18 ( & V_12 -> V_38 ,
L_5
L_7 ,
V_23 ) ;
goto V_67;
}
if ( ( V_21 -> V_23 == 16 ) && ( V_21 -> V_42 & 1 ) ) {
F_18 ( & V_12 -> V_38 ,
L_5
L_8 ,
V_21 -> V_42 ) ;
goto V_67;
}
if ( V_21 -> V_25 && V_21 -> V_25 < V_1 -> V_64 ) {
F_18 ( & V_12 -> V_38 ,
L_5
L_9
L_10 ,
V_1 -> V_64 , V_21 -> V_25 ) ;
goto V_67;
}
}
F_35 ( & V_1 -> V_48 , V_65 ) ;
F_36 ( & V_51 -> V_56 , & V_1 -> V_49 ) ;
F_37 ( V_68 , & V_1 -> V_47 ) ;
F_38 ( & V_1 -> V_48 , V_65 ) ;
return 0 ;
V_67:
V_51 -> V_53 = - V_10 ;
if ( V_51 -> V_61 )
V_51 -> V_61 ( V_51 -> V_62 ) ;
return - V_10 ;
}
static int T_5 F_39 ( struct V_69 * V_70 )
{
struct V_71 * V_17 ;
struct V_1 * V_12 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
unsigned long V_14 ;
int V_53 = 0 ;
V_75 = V_70 -> V_38 . V_76 ;
V_17 = F_40 ( & V_70 -> V_38 , sizeof *V_12 ) ;
if ( V_17 == NULL ) {
F_41 ( & V_70 -> V_38 , L_11 ) ;
return - V_77 ;
}
if ( V_70 -> V_78 != - 1 )
V_17 -> V_79 = V_70 -> V_78 ;
V_17 -> V_80 = 0 ;
V_17 -> V_81 = F_33 ;
V_17 -> V_82 = F_34 ;
V_17 -> V_83 = V_84 ;
F_42 ( & V_70 -> V_38 , V_17 ) ;
V_12 = F_9 ( V_17 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_75 = V_75 ;
V_12 -> V_18 = F_43 ( & V_70 -> V_38 , NULL ) ;
if ( F_44 ( V_12 -> V_18 ) ) {
V_53 = F_45 ( V_12 -> V_18 ) ;
goto V_45;
}
F_46 ( V_12 -> V_18 ) ;
F_47 ( V_12 -> V_18 ) ;
V_14 = F_10 ( V_12 -> V_18 ) ;
V_12 -> V_63 = F_11 ( V_14 , 4 ) ;
V_12 -> V_64 = F_11 ( V_14 , 30 ) ;
V_73 = F_48 ( V_70 , V_85 , 0 ) ;
if ( V_73 == NULL ) {
V_53 = - V_86 ;
goto V_87;
}
if ( ! F_49 ( V_73 -> V_88 , F_50 ( V_73 ) ,
F_51 ( & V_70 -> V_38 ) ) ) {
V_53 = - V_89 ;
goto V_87;
}
V_12 -> V_3 = F_52 ( V_73 -> V_88 , V_90 ) ;
F_53 ( & V_12 -> V_47 , F_25 ) ;
F_54 ( & V_12 -> V_48 ) ;
F_55 ( & V_12 -> V_49 ) ;
if ( F_32 ( V_12 ) < 0 )
goto V_91;
V_53 = F_56 ( V_17 ) ;
if ( V_53 < 0 )
goto V_91;
return V_53 ;
V_91:
F_57 ( V_73 -> V_88 , F_50 ( V_73 ) ) ;
V_87:
F_58 ( V_12 -> V_18 ) ;
F_59 ( V_12 -> V_18 ) ;
V_45:
F_60 ( V_17 ) ;
return V_53 ;
}
static int T_6 F_61 ( struct V_69 * V_70 )
{
struct V_71 * V_17 ;
struct V_1 * V_12 ;
struct V_72 * V_73 ;
V_17 = F_62 ( & V_70 -> V_38 ) ;
V_12 = F_9 ( V_17 ) ;
F_63 ( & V_12 -> V_47 ) ;
F_58 ( V_12 -> V_18 ) ;
F_59 ( V_12 -> V_18 ) ;
V_73 = F_48 ( V_70 , V_85 , 0 ) ;
F_57 ( V_73 -> V_88 , F_50 ( V_73 ) ) ;
F_64 ( V_17 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
V_68 = F_66 (
V_92 . V_93 . V_94 ) ;
if ( V_68 == NULL )
return - V_77 ;
return F_67 ( & V_92 , F_39 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( V_68 ) ;
F_70 ( & V_92 ) ;
F_71 ( V_68 ) ;
}
