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
V_1 = F_7 ( V_8 -> V_13 ) ;
V_10 = F_8 ( V_1 -> V_14 ) ;
V_11 = F_9 ( V_10 , V_9 ) ;
V_11 = F_10 ( V_11 , 2 ) ;
if ( V_11 > 30 )
return - V_15 ;
if ( V_11 < 4 )
V_11 = 4 ;
V_12 = 0x10 + V_11 / 2 ;
V_2 = F_3 ( F_1 ( V_1 , V_16 ) ) ;
V_2 = ( ( V_2 & ~ V_17 ) | V_12 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_16 ) ) ;
return 0 ;
}
static void
F_11 ( struct V_7 * V_8 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_13 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_16 ) ) ;
V_2 &= ~ V_18 ;
if ( V_8 -> V_19 & V_20 )
V_2 |= V_21 ;
if ( V_8 -> V_19 & V_22 )
V_2 |= V_23 ;
F_4 ( V_2 , F_1 ( V_1 , V_16 ) ) ;
}
static int
F_12 ( struct V_7 * V_8 , struct V_24 * V_25 )
{
struct V_1 * V_1 ;
unsigned int V_9 = V_8 -> V_26 ;
unsigned int V_27 = V_8 -> V_27 ;
int V_28 ;
V_1 = F_7 ( V_8 -> V_13 ) ;
if ( ( V_25 != NULL ) && V_25 -> V_29 )
V_9 = V_25 -> V_29 ;
if ( ( V_25 != NULL ) && V_25 -> V_27 )
V_27 = V_25 -> V_27 ;
F_11 ( V_8 ) ;
V_28 = F_6 ( V_8 , V_9 ) ;
if ( V_28 )
return V_28 ;
if ( V_27 == 16 )
F_2 ( V_1 , V_16 ,
V_30 ) ;
else
F_5 ( V_1 , V_16 ,
V_30 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_1 , int V_31 )
{
if ( V_31 )
F_2 ( V_1 , V_32 , 0x1 ) ;
else
F_5 ( V_1 , V_32 , 0x1 ) ;
}
static inline int F_14 ( struct V_1 * V_1 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_35 ) ) )
return 1 ;
else
F_15 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_16 ( struct V_7 * V_8 ,
const T_3 * * V_36 , T_3 * * V_37 )
{
void T_1 * V_38 , * V_39 , * V_40 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_13 ) ;
V_38 = F_1 ( V_1 , V_41 ) ;
V_39 = F_1 ( V_1 , V_42 ) ;
V_40 = F_1 ( V_1 , V_35 ) ;
F_4 ( 0x0 , V_40 ) ;
if ( V_36 && * V_36 )
F_4 ( * ( * V_36 ) ++ , V_38 ) ;
else
F_4 ( 0 , V_38 ) ;
if ( F_14 ( V_1 ) < 0 ) {
F_17 ( & V_8 -> V_43 , L_1 ) ;
return - 1 ;
}
if ( V_37 && * V_37 )
* ( * V_37 ) ++ = F_3 ( V_39 ) ;
return 1 ;
}
static inline int
F_18 ( struct V_7 * V_8 ,
const T_4 * * V_36 , T_4 * * V_37 )
{
void T_1 * V_38 , * V_39 , * V_40 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_13 ) ;
V_38 = F_1 ( V_1 , V_41 ) ;
V_39 = F_1 ( V_1 , V_42 ) ;
V_40 = F_1 ( V_1 , V_35 ) ;
F_4 ( 0x0 , V_40 ) ;
if ( V_36 && * V_36 )
F_4 ( F_19 ( F_20 ( ( * V_36 ) ++ ) ) , V_38 ) ;
else
F_4 ( 0 , V_38 ) ;
if ( F_14 ( V_1 ) < 0 ) {
F_17 ( & V_8 -> V_43 , L_1 ) ;
return - 1 ;
}
if ( V_37 && * V_37 )
F_21 ( F_22 ( F_3 ( V_39 ) ) , ( * V_37 ) ++ ) ;
return 1 ;
}
static unsigned int
F_23 ( struct V_7 * V_8 , struct V_24 * V_44 )
{
unsigned int V_45 ;
int V_46 ;
V_46 = V_8 -> V_27 ;
V_45 = V_44 -> V_47 ;
if ( V_46 == 8 ) {
const T_3 * V_48 = V_44 -> V_36 ;
T_3 * V_49 = V_44 -> V_37 ;
do {
if ( F_16 ( V_8 , & V_48 , & V_49 ) < 0 )
goto V_50;
V_45 -- ;
} while ( V_45 );
} else if ( V_46 == 16 ) {
const T_4 * V_48 = V_44 -> V_36 ;
T_4 * V_49 = V_44 -> V_37 ;
do {
if ( F_18 ( V_8 , & V_48 , & V_49 ) < 0 )
goto V_50;
V_45 -= 2 ;
} while ( V_45 );
}
V_50:
return V_44 -> V_47 - V_45 ;
}
static int F_24 ( struct V_51 * V_13 ,
struct V_52 * V_53 )
{
struct V_1 * V_1 = F_7 ( V_13 ) ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_24 * V_25 = NULL ;
int V_54 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
V_55 = F_12 ( V_8 , NULL ) ;
if ( V_55 < 0 )
goto V_57;
F_25 (t, &m->transfers, transfer_list) {
if ( V_54 || V_25 -> V_29 || V_25 -> V_27 ) {
V_54 = 1 ;
V_55 = F_12 ( V_8 , V_25 ) ;
if ( V_55 < 0 )
break;
if ( ! V_25 -> V_29 && ! V_25 -> V_27 )
V_54 = 0 ;
}
if ( ! V_56 ) {
F_13 ( V_1 , 1 ) ;
V_56 = 1 ;
}
if ( V_25 -> V_47 )
V_53 -> V_58 += F_23 ( V_8 , V_25 ) ;
if ( V_25 -> V_59 )
F_15 ( V_25 -> V_59 ) ;
if ( V_25 -> V_60 ) {
F_13 ( V_1 , 0 ) ;
V_56 = 0 ;
}
}
V_57:
if ( V_56 )
F_13 ( V_1 , 0 ) ;
V_53 -> V_55 = V_55 ;
F_26 ( V_13 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
F_13 ( V_1 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_51 * V_13 ;
struct V_1 * V_8 ;
struct V_63 * V_64 ;
unsigned long V_10 ;
int V_55 = 0 ;
const T_2 * V_65 ;
int V_66 ;
V_13 = F_29 ( & V_62 -> V_43 , sizeof( * V_8 ) ) ;
if ( V_13 == NULL ) {
F_30 ( & V_62 -> V_43 , L_2 ) ;
return - V_67 ;
}
if ( V_62 -> V_68 != - 1 )
V_13 -> V_69 = V_62 -> V_68 ;
if ( V_62 -> V_43 . V_70 ) {
V_65 = F_31 ( V_62 -> V_43 . V_70 , L_3 ,
& V_66 ) ;
if ( V_65 && V_66 == sizeof( * V_65 ) )
V_13 -> V_69 = * V_65 ;
}
V_13 -> V_71 = V_22 | V_20 ;
V_13 -> V_72 = F_24 ;
V_13 -> V_73 = V_74 ;
V_13 -> V_75 = F_32 ( 8 ) | F_32 ( 16 ) ;
F_33 ( V_62 , V_13 ) ;
V_8 = F_7 ( V_13 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_14 = F_34 ( & V_62 -> V_43 , NULL ) ;
if ( F_35 ( V_8 -> V_14 ) ) {
V_55 = F_36 ( V_8 -> V_14 ) ;
goto V_50;
}
F_37 ( V_8 -> V_14 ) ;
F_38 ( V_8 -> V_14 ) ;
V_10 = F_8 ( V_8 -> V_14 ) ;
V_13 -> V_26 = F_9 ( V_10 , 4 ) ;
V_13 -> V_76 = F_9 ( V_10 , 30 ) ;
V_64 = F_39 ( V_62 , V_77 , 0 ) ;
V_8 -> V_3 = F_40 ( & V_62 -> V_43 , V_64 ) ;
if ( F_35 ( V_8 -> V_3 ) ) {
V_55 = F_36 ( V_8 -> V_3 ) ;
goto V_78;
}
if ( F_27 ( V_8 ) < 0 )
goto V_78;
V_13 -> V_43 . V_70 = V_62 -> V_43 . V_70 ;
V_55 = F_41 ( & V_62 -> V_43 , V_13 ) ;
if ( V_55 < 0 )
goto V_78;
return V_55 ;
V_78:
F_42 ( V_8 -> V_14 ) ;
V_50:
F_43 ( V_13 ) ;
return V_55 ;
}
static int F_44 ( struct V_61 * V_62 )
{
struct V_51 * V_13 ;
struct V_1 * V_8 ;
V_13 = F_45 ( V_62 ) ;
V_8 = F_7 ( V_13 ) ;
F_42 ( V_8 -> V_14 ) ;
return 0 ;
}
