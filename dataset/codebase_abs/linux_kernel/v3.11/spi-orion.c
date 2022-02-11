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
static void
F_13 ( struct V_11 * V_12 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_8 ) ) ;
V_2 &= ~ V_20 ;
if ( V_12 -> V_21 & V_22 )
V_2 |= V_23 ;
if ( V_12 -> V_21 & V_24 )
V_2 |= V_25 ;
F_4 ( V_2 , F_1 ( V_1 , V_8 ) ) ;
}
static int
F_14 ( struct V_11 * V_12 , struct V_26 * V_27 )
{
struct V_1 * V_1 ;
unsigned int V_13 = V_12 -> V_28 ;
unsigned int V_29 = V_12 -> V_29 ;
int V_30 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_27 != NULL ) && V_27 -> V_31 )
V_13 = V_27 -> V_31 ;
if ( ( V_27 != NULL ) && V_27 -> V_29 )
V_29 = V_27 -> V_29 ;
F_13 ( V_12 ) ;
V_30 = F_8 ( V_12 , V_13 ) ;
if ( V_30 )
return V_30 ;
return F_6 ( V_1 , V_29 ) ;
}
static void F_15 ( struct V_1 * V_1 , int V_32 )
{
if ( V_32 )
F_2 ( V_1 , V_33 , 0x1 ) ;
else
F_5 ( V_1 , V_33 , 0x1 ) ;
}
static inline int F_16 ( struct V_1 * V_1 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_36 ) ) )
return 1 ;
else
F_17 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_18 ( struct V_11 * V_12 ,
const T_3 * * V_37 , T_3 * * V_38 )
{
void T_1 * V_39 , * V_40 , * V_41 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_39 = F_1 ( V_1 , V_42 ) ;
V_40 = F_1 ( V_1 , V_43 ) ;
V_41 = F_1 ( V_1 , V_36 ) ;
F_4 ( 0x0 , V_41 ) ;
if ( V_37 && * V_37 )
F_4 ( * ( * V_37 ) ++ , V_39 ) ;
else
F_4 ( 0 , V_39 ) ;
if ( F_16 ( V_1 ) < 0 ) {
F_19 ( & V_12 -> V_44 , L_3 ) ;
return - 1 ;
}
if ( V_38 && * V_38 )
* ( * V_38 ) ++ = F_3 ( V_40 ) ;
return 1 ;
}
static inline int
F_20 ( struct V_11 * V_12 ,
const T_4 * * V_37 , T_4 * * V_38 )
{
void T_1 * V_39 , * V_40 , * V_41 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_39 = F_1 ( V_1 , V_42 ) ;
V_40 = F_1 ( V_1 , V_43 ) ;
V_41 = F_1 ( V_1 , V_36 ) ;
F_4 ( 0x0 , V_41 ) ;
if ( V_37 && * V_37 )
F_4 ( F_21 ( F_22 ( ( * V_37 ) ++ ) ) , V_39 ) ;
else
F_4 ( 0 , V_39 ) ;
if ( F_16 ( V_1 ) < 0 ) {
F_19 ( & V_12 -> V_44 , L_3 ) ;
return - 1 ;
}
if ( V_38 && * V_38 )
F_23 ( F_24 ( F_3 ( V_40 ) ) , ( * V_38 ) ++ ) ;
return 1 ;
}
static unsigned int
F_25 ( struct V_11 * V_12 , struct V_26 * V_45 )
{
struct V_1 * V_1 ;
unsigned int V_46 ;
int V_47 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
V_47 = V_12 -> V_29 ;
V_46 = V_45 -> V_48 ;
if ( V_47 == 8 ) {
const T_3 * V_49 = V_45 -> V_37 ;
T_3 * V_50 = V_45 -> V_38 ;
do {
if ( F_18 ( V_12 , & V_49 , & V_50 ) < 0 )
goto V_51;
V_46 -- ;
} while ( V_46 );
} else if ( V_47 == 16 ) {
const T_4 * V_49 = V_45 -> V_37 ;
T_4 * V_50 = V_45 -> V_38 ;
do {
if ( F_20 ( V_12 , & V_49 , & V_50 ) < 0 )
goto V_51;
V_46 -= 2 ;
} while ( V_46 );
}
V_51:
return V_45 -> V_48 - V_46 ;
}
static int F_26 ( struct V_52 * V_17 ,
struct V_53 * V_54 )
{
struct V_1 * V_1 = F_9 ( V_17 ) ;
struct V_11 * V_12 = V_54 -> V_12 ;
struct V_26 * V_27 = NULL ;
int V_55 = 0 ;
int V_56 = 0 ;
int V_57 = 0 ;
V_56 = F_14 ( V_12 , NULL ) ;
if ( V_56 < 0 )
goto V_58;
F_27 (t, &m->transfers, transfer_list) {
if ( ( V_27 -> V_29 == 16 ) && ( V_27 -> V_48 & 1 ) ) {
F_19 ( & V_12 -> V_44 ,
L_4
L_5 ,
V_27 -> V_48 ) ;
V_56 = - V_59 ;
goto V_58;
}
if ( V_27 -> V_31 && V_27 -> V_31 < V_1 -> V_60 ) {
F_19 ( & V_12 -> V_44 ,
L_4
L_6
L_7 ,
V_1 -> V_60 , V_27 -> V_31 ) ;
V_56 = - V_59 ;
goto V_58;
}
if ( V_55 || V_27 -> V_31 || V_27 -> V_29 ) {
V_55 = 1 ;
V_56 = F_14 ( V_12 , V_27 ) ;
if ( V_56 < 0 )
break;
if ( ! V_27 -> V_31 && ! V_27 -> V_29 )
V_55 = 0 ;
}
if ( ! V_57 ) {
F_15 ( V_1 , 1 ) ;
V_57 = 1 ;
}
if ( V_27 -> V_48 )
V_54 -> V_61 += F_25 ( V_12 , V_27 ) ;
if ( V_27 -> V_62 )
F_17 ( V_27 -> V_62 ) ;
if ( V_27 -> V_63 ) {
F_15 ( V_1 , 0 ) ;
V_57 = 0 ;
}
}
V_58:
if ( V_57 )
F_15 ( V_1 , 0 ) ;
V_54 -> V_56 = V_56 ;
F_28 ( V_17 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
F_15 ( V_1 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_12 -> V_17 ) ;
if ( ( V_12 -> V_28 == 0 )
|| ( V_12 -> V_28 > V_1 -> V_64 ) )
V_12 -> V_28 = V_1 -> V_64 ;
if ( V_12 -> V_28 < V_1 -> V_60 ) {
F_19 ( & V_12 -> V_44 , L_8 ,
V_12 -> V_28 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_31 ( struct V_65 * V_66 )
{
struct V_52 * V_17 ;
struct V_1 * V_12 ;
struct V_67 * V_68 ;
unsigned long V_14 ;
int V_56 = 0 ;
const T_2 * V_69 ;
int V_7 ;
V_17 = F_32 ( & V_66 -> V_44 , sizeof *V_12 ) ;
if ( V_17 == NULL ) {
F_33 ( & V_66 -> V_44 , L_9 ) ;
return - V_70 ;
}
if ( V_66 -> V_71 != - 1 )
V_17 -> V_72 = V_66 -> V_71 ;
if ( V_66 -> V_44 . V_73 ) {
V_69 = F_34 ( V_66 -> V_44 . V_73 , L_10 ,
& V_7 ) ;
if ( V_69 && V_7 == sizeof( * V_69 ) )
V_17 -> V_72 = * V_69 ;
}
V_17 -> V_74 = V_24 | V_22 ;
V_17 -> V_75 = F_30 ;
V_17 -> V_76 = F_26 ;
V_17 -> V_77 = V_78 ;
F_35 ( V_66 , V_17 ) ;
V_12 = F_9 ( V_17 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_18 = F_36 ( & V_66 -> V_44 , NULL ) ;
if ( F_37 ( V_12 -> V_18 ) ) {
V_56 = F_38 ( V_12 -> V_18 ) ;
goto V_51;
}
F_39 ( V_12 -> V_18 ) ;
F_40 ( V_12 -> V_18 ) ;
V_14 = F_10 ( V_12 -> V_18 ) ;
V_12 -> V_64 = F_11 ( V_14 , 4 ) ;
V_12 -> V_60 = F_11 ( V_14 , 30 ) ;
V_68 = F_41 ( V_66 , V_79 , 0 ) ;
if ( V_68 == NULL ) {
V_56 = - V_80 ;
goto V_81;
}
if ( ! F_42 ( V_68 -> V_82 , F_43 ( V_68 ) ,
F_44 ( & V_66 -> V_44 ) ) ) {
V_56 = - V_83 ;
goto V_81;
}
V_12 -> V_3 = F_45 ( V_68 -> V_82 , V_84 ) ;
if ( F_29 ( V_12 ) < 0 )
goto V_85;
V_17 -> V_44 . V_73 = V_66 -> V_44 . V_73 ;
V_56 = F_46 ( V_17 ) ;
if ( V_56 < 0 )
goto V_85;
return V_56 ;
V_85:
F_47 ( V_68 -> V_82 , F_43 ( V_68 ) ) ;
V_81:
F_48 ( V_12 -> V_18 ) ;
F_49 ( V_12 -> V_18 ) ;
V_51:
F_50 ( V_17 ) ;
return V_56 ;
}
static int F_51 ( struct V_65 * V_66 )
{
struct V_52 * V_17 ;
struct V_67 * V_68 ;
struct V_1 * V_12 ;
V_17 = F_52 ( V_66 ) ;
V_12 = F_9 ( V_17 ) ;
F_48 ( V_12 -> V_18 ) ;
F_49 ( V_12 -> V_18 ) ;
V_68 = F_41 ( V_66 , V_79 , 0 ) ;
F_47 ( V_68 -> V_82 , F_43 ( V_68 ) ) ;
F_53 ( V_17 ) ;
return 0 ;
}
