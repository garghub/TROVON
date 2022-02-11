void F_1 ( int V_1 , void * V_2 )
{
F_2 ( F_3 ( V_2 ) , V_3 +
F_4 ( V_1 ) ) ;
}
int F_5 ( unsigned int V_4 ,
unsigned int V_5 ,
T_1 V_6 )
{
void T_2 * V_7 ;
T_3 V_8 = & V_9 - & V_10 ;
F_6 ( V_11 , V_12 ) ;
F_7 ( V_4 , V_5 ,
V_13 , V_14 ) ;
V_7 = F_8 ( V_13 , V_14 ) ;
if ( ! V_7 ) {
F_9 ( L_1 ) ;
return - V_15 ;
}
memcpy ( V_7 , & V_10 , V_8 ) ;
F_10 ( ( unsigned long ) V_6 ,
V_7 + V_8 - 4 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int T_4 F_12 ( void )
{
struct V_16 * V_17 ;
struct V_18 V_19 ;
int V_20 = 0 ;
V_17 = F_13 ( NULL , V_21 ) ;
if ( ! V_17 )
return 0 ;
F_14 ( L_2 ) ;
if ( F_15 ( V_17 , 0 , & V_19 ) ) {
F_9 ( L_3 ) ;
V_20 = - V_22 ;
goto V_23;
}
if ( F_16 ( V_17 , L_4 ) ) {
F_17 ( V_24 L_5 ) ;
V_19 . V_25 = V_19 . V_25 - V_26 ;
V_19 . V_27 = V_19 . V_25 + V_28 - 1 ;
}
if ( ! F_18 ( V_19 . V_25 , F_19 ( & V_19 ) ,
V_17 -> V_29 ) ) {
F_9 ( L_6 ) ;
V_20 = - V_30 ;
goto V_23;
}
V_31 = V_19 . V_25 ;
V_3 = F_8 ( V_19 . V_25 , F_19 ( & V_19 ) ) ;
if ( ! V_3 ) {
F_9 ( L_7 ) ;
F_20 ( V_19 . V_25 , F_19 ( & V_19 ) ) ;
V_20 = - V_15 ;
goto V_23;
}
V_23:
F_21 ( V_17 ) ;
return V_20 ;
}
static void F_22 ( void )
{
T_3 V_32 ;
if ( V_3 == NULL )
return;
V_32 = F_23 ( V_3 + V_33 ) ;
V_32 |= V_34 ;
F_2 ( V_32 , V_3 + V_33 ) ;
}
static int F_24 ( unsigned long V_35 )
{
unsigned int V_1 = F_25 ( F_26 () ) ;
T_3 V_32 ;
if ( V_3 == NULL )
return - V_36 ;
V_32 = F_23 ( V_3 + F_27 ( V_1 ) ) ;
V_32 |= V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ;
F_2 ( V_32 , V_3 + F_27 ( V_1 ) ) ;
V_32 = F_23 ( V_3 + F_28 ( V_1 ) ) ;
if ( V_35 & V_43 )
V_32 |= V_44 ;
V_32 |= V_45 ;
F_2 ( V_32 , V_3 + F_28 ( V_1 ) ) ;
if ( V_35 & V_46 ) {
V_32 = F_23 ( V_3 + F_29 ( V_1 ) ) ;
V_32 |= V_47 ;
F_2 ( V_32 , V_3 + F_29 ( V_1 ) ) ;
}
return 0 ;
}
int F_30 ( unsigned long V_48 )
{
unsigned long V_35 = V_46 ;
int V_20 ;
if ( V_48 )
V_35 |= V_43 ;
V_20 = F_24 ( V_35 ) ;
if ( V_20 )
return V_20 ;
F_31 ( V_49 ) ;
F_32 () ;
F_33 () ;
F_34 () ;
F_35 () ;
F_36 () ;
asm volatile(
"mrc p15, 0, r0, c1, c0, 0 \n\t"
"tst r0, #(1 << 2) \n\t"
"orreq r0, r0, #(1 << 2) \n\t"
"mcreq p15, 0, r0, c1, c0, 0 \n\t"
"isb "
: : : "r0");
F_37 ( L_8 ) ;
return 0 ;
}
static int F_38 ( unsigned long V_48 )
{
return F_39 ( V_48 , F_30 ) ;
}
int F_40 ( unsigned long V_48 )
{
unsigned long V_35 = 0 ;
if ( V_48 )
V_35 |= V_43 ;
F_24 ( V_35 ) ;
F_31 ( V_50 ) ;
F_41 ( F_42 () , V_51 ) ;
F_43 () ;
return 1 ;
}
static int F_44 ( unsigned long V_48 )
{
return F_39 ( false , F_40 ) ;
}
void F_45 ( void )
{
unsigned int V_1 = F_25 ( F_26 () ) ;
T_3 V_32 ;
if ( V_3 == NULL )
return;
V_32 = F_23 ( V_3 + F_28 ( V_1 ) ) ;
V_32 &= ~ V_44 ;
F_2 ( V_32 , V_3 + F_28 ( V_1 ) ) ;
V_32 = F_23 ( V_3 + F_27 ( V_1 ) ) ;
V_32 &= ~ ( V_38 | V_39 ) ;
V_32 &= ~ V_37 ;
V_32 &= ~ V_40 ;
V_32 &= ~ ( V_41 | V_42 ) ;
F_2 ( V_32 , V_3 + F_27 ( V_1 ) ) ;
}
static int F_46 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
if ( V_54 == V_56 ) {
unsigned int V_1 = F_25 ( F_26 () ) ;
F_1 ( V_1 , V_57 ) ;
} else if ( V_54 == V_58 ) {
F_45 () ;
}
return V_59 ;
}
static T_4 int F_47 ( void )
{
struct V_16 * V_17 ;
T_1 V_60 ;
V_17 = F_48 ( NULL , NULL , L_9 ) ;
if ( ! V_17 )
return - V_61 ;
F_21 ( V_17 ) ;
V_60 = V_31 + F_4 ( 0 ) ;
F_5 ( V_62 ,
V_63 ,
V_60 ) ;
V_57 = V_64 ;
V_65 . V_66 . V_67 = F_38 ;
V_65 . V_68 = L_10 ;
return 0 ;
}
static T_4 int F_49 ( void )
{
struct V_16 * V_17 ;
void T_2 * V_69 ;
T_3 V_32 ;
V_17 = F_48 ( NULL , NULL ,
L_11 ) ;
if ( ! V_17 )
return - V_61 ;
F_21 ( V_17 ) ;
V_17 = F_48 ( NULL , NULL ,
L_12 ) ;
if ( ! V_17 )
return - V_61 ;
V_69 = F_50 ( V_17 , 0 ) ;
F_51 ( ! V_69 ) ;
F_21 ( V_17 ) ;
V_32 = F_23 ( V_69 + V_70 ) ;
V_32 |= V_71 ;
V_32 |= V_72 ;
F_2 ( V_32 , V_69 + V_70 ) ;
F_11 ( V_69 ) ;
V_32 = F_23 ( V_3 + V_73 ) ;
V_32 &= ~ V_74 ;
V_32 |= V_75 ;
V_32 |= V_76 ;
F_2 ( V_32 , V_3 + V_73 ) ;
V_57 = V_77 ;
V_65 . V_66 . V_67 = F_44 ;
V_65 . V_68 = L_13 ;
return 0 ;
}
static T_4 int F_52 ( void )
{
struct V_16 * V_17 ;
V_17 = F_48 ( NULL , NULL , L_9 ) ;
if ( ! V_17 )
return - V_61 ;
F_21 ( V_17 ) ;
V_57 = V_64 ;
V_65 . V_66 . V_67 = F_38 ;
V_65 . V_68 = L_14 ;
return 0 ;
}
static int T_4 F_53 ( void )
{
struct V_16 * V_17 ;
int V_20 ;
V_17 = F_13 ( NULL , V_21 ) ;
if ( ! V_17 )
return 0 ;
F_21 ( V_17 ) ;
if ( F_54 ( L_15 ) )
V_20 = F_52 () ;
else if ( F_54 ( L_16 ) )
V_20 = F_47 () ;
else if ( F_54 ( L_17 ) )
V_20 = F_49 () ;
else
return 0 ;
if ( V_20 )
return V_20 ;
F_22 () ;
F_55 ( & V_65 ) ;
F_56 ( & V_78 ) ;
return 0 ;
}
static void F_57 ( void * V_79 )
{
T_3 V_32 ;
T_3 V_80 = F_26 () ;
unsigned long V_35 ;
F_58 ( V_35 ) ;
V_32 = F_23 ( V_3 + F_27 ( V_80 ) ) ;
V_32 |= V_37 |
V_41 |
V_42 ;
F_2 ( V_32 , V_3 + F_27 ( V_80 ) ) ;
V_32 = F_23 ( V_3 + F_28 ( V_80 ) ) ;
V_32 |= V_81 ;
F_2 ( V_32 , V_3 + F_28 ( V_80 ) ) ;
F_34 () ;
V_32 = F_23 ( V_3 + F_27 ( V_80 ) ) ;
V_32 &= ~ V_37 ;
F_2 ( V_32 , V_3 + F_27 ( V_80 ) ) ;
F_59 ( V_35 ) ;
}
int F_60 ( int V_80 )
{
unsigned long V_82 ;
int V_83 = F_25 ( V_80 ) ;
T_3 V_32 ;
V_32 = F_23 ( V_3 + F_61 ( V_83 ) ) ;
V_32 &= ~ V_84 ;
F_2 ( V_32 , V_3 + F_61 ( V_83 ) ) ;
V_32 = F_23 ( V_3 + F_61 ( V_83 ) ) ;
V_32 |= V_85 ;
F_2 ( V_32 , V_3 + F_61 ( V_83 ) ) ;
F_62 ( V_80 , F_57 ,
NULL , false ) ;
V_82 = V_86 + V_87 ;
while ( F_63 ( V_86 , V_82 ) ) {
V_32 = F_23 ( V_3 + F_61 ( V_83 ) ) ;
if ( V_32 & V_84 )
break;
F_64 ( 10 ) ;
}
if ( F_65 ( V_86 , V_82 ) )
return - V_88 ;
V_32 = F_23 ( V_3 + F_61 ( V_83 ) ) ;
V_32 &= ~ V_85 ;
F_2 ( V_32 , V_3 + F_61 ( V_83 ) ) ;
return 0 ;
}
static int T_4 F_66 ( void )
{
struct V_16 * V_17 ;
struct V_18 V_19 ;
int V_20 , V_80 ;
if ( ! F_54 ( L_15 ) )
return 0 ;
V_17 = F_48 ( NULL , NULL , L_18 ) ;
if ( ! V_17 )
return 0 ;
V_20 = F_15 ( V_17 , 1 , & V_19 ) ;
if ( V_20 ) {
F_17 ( V_24 L_19 ) ;
F_21 ( V_17 ) ;
return 0 ;
}
F_21 ( V_17 ) ;
F_67 (cpu) {
struct V_89 * V_90 ;
struct V_91 * V_91 ;
int V_20 ;
V_90 = F_68 ( V_80 ) ;
if ( ! V_90 ) {
F_9 ( L_20 , V_80 ) ;
continue;
}
V_91 = F_69 ( V_90 , 0 ) ;
if ( F_70 ( V_91 ) ) {
F_9 ( L_21 , V_80 ) ;
return F_71 ( V_91 ) ;
}
V_20 = F_72 ( V_90 , F_73 ( V_91 ) , 0 ) ;
if ( V_20 ) {
F_74 ( V_91 ) ;
return V_20 ;
}
V_20 = F_72 ( V_90 , F_73 ( V_91 ) / 2 , 0 ) ;
if ( V_20 ) {
F_74 ( V_91 ) ;
return V_20 ;
}
}
F_75 ( NULL , L_22 , - 1 ,
& V_92 , sizeof( V_92 ) ) ;
return 0 ;
}
