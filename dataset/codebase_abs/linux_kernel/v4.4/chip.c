static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( 1 , L_1 , V_1 ) ;
return V_3 ;
}
int F_3 ( unsigned int V_1 , struct V_4 * V_5 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_4 ( V_1 , & V_6 , 0 ) ;
if ( ! V_8 )
return - V_9 ;
if ( ! V_5 )
V_5 = & V_10 ;
V_8 -> V_11 . V_5 = V_5 ;
F_5 ( V_8 , V_6 ) ;
F_6 ( V_1 ) ;
return 0 ;
}
int F_7 ( unsigned int V_1 , unsigned int type )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_8 ( V_1 , & V_6 , V_12 ) ;
int V_13 = 0 ;
if ( ! V_8 )
return - V_9 ;
type &= V_14 ;
V_13 = F_9 ( V_8 , type ) ;
F_10 ( V_8 , V_6 ) ;
return V_13 ;
}
int F_11 ( unsigned int V_1 , void * V_15 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_4 ( V_1 , & V_6 , 0 ) ;
if ( ! V_8 )
return - V_9 ;
V_8 -> V_16 . V_17 = V_15 ;
F_5 ( V_8 , V_6 ) ;
return 0 ;
}
int F_12 ( unsigned int V_18 , unsigned int V_19 ,
struct V_20 * V_21 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_4 ( V_18 + V_19 , & V_6 , V_12 ) ;
if ( ! V_8 )
return - V_9 ;
V_8 -> V_16 . V_20 = V_21 ;
if ( V_21 && ! V_19 )
V_21 -> V_1 = V_18 ;
F_5 ( V_8 , V_6 ) ;
return 0 ;
}
int F_13 ( unsigned int V_1 , struct V_20 * V_21 )
{
return F_12 ( V_1 , 0 , V_21 ) ;
}
int F_14 ( unsigned int V_1 , void * V_15 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_4 ( V_1 , & V_6 , 0 ) ;
if ( ! V_8 )
return - V_9 ;
V_8 -> V_11 . V_22 = V_15 ;
F_5 ( V_8 , V_6 ) ;
return 0 ;
}
struct V_11 * F_15 ( unsigned int V_1 )
{
struct V_7 * V_8 = F_16 ( V_1 ) ;
return V_8 ? & V_8 -> V_11 : NULL ;
}
static void F_17 ( struct V_7 * V_8 )
{
F_18 ( & V_8 -> V_11 , V_23 ) ;
}
static void F_19 ( struct V_7 * V_8 )
{
F_20 ( & V_8 -> V_11 , V_23 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
F_18 ( & V_8 -> V_11 , V_24 ) ;
}
static void F_22 ( struct V_7 * V_8 )
{
F_20 ( & V_8 -> V_11 , V_24 ) ;
}
int F_23 ( struct V_7 * V_8 , bool V_25 )
{
int V_13 = 0 ;
F_17 ( V_8 ) ;
V_8 -> V_26 = 0 ;
F_24 ( & V_8 -> V_11 ) ;
if ( V_8 -> V_11 . V_5 -> F_23 ) {
V_13 = V_8 -> V_11 . V_5 -> F_23 ( & V_8 -> V_11 ) ;
F_21 ( V_8 ) ;
} else {
F_25 ( V_8 ) ;
}
if ( V_25 )
F_26 ( V_8 ) ;
return V_13 ;
}
void F_27 ( struct V_7 * V_8 )
{
F_19 ( V_8 ) ;
V_8 -> V_26 = 1 ;
if ( V_8 -> V_11 . V_5 -> F_27 )
V_8 -> V_11 . V_5 -> F_27 ( & V_8 -> V_11 ) ;
else if ( V_8 -> V_11 . V_5 -> V_27 )
V_8 -> V_11 . V_5 -> V_27 ( & V_8 -> V_11 ) ;
else
V_8 -> V_11 . V_5 -> V_28 ( & V_8 -> V_11 ) ;
F_28 ( & V_8 -> V_11 ) ;
F_22 ( V_8 ) ;
}
void F_25 ( struct V_7 * V_8 )
{
F_17 ( V_8 ) ;
if ( V_8 -> V_11 . V_5 -> F_25 )
V_8 -> V_11 . V_5 -> F_25 ( & V_8 -> V_11 ) ;
else
V_8 -> V_11 . V_5 -> V_29 ( & V_8 -> V_11 ) ;
F_21 ( V_8 ) ;
}
void V_27 ( struct V_7 * V_8 )
{
F_19 ( V_8 ) ;
if ( V_8 -> V_11 . V_5 -> V_27 ) {
V_8 -> V_11 . V_5 -> V_27 ( & V_8 -> V_11 ) ;
F_22 ( V_8 ) ;
} else if ( F_29 ( V_8 ) ) {
F_30 ( V_8 ) ;
}
}
void F_31 ( struct V_7 * V_8 , unsigned int V_30 )
{
if ( V_8 -> V_11 . V_5 -> F_25 )
V_8 -> V_11 . V_5 -> F_25 ( & V_8 -> V_11 ) ;
else
V_8 -> V_11 . V_5 -> V_29 ( & V_8 -> V_11 ) ;
F_32 ( V_30 , V_8 -> V_31 ) ;
}
void F_33 ( struct V_7 * V_8 , unsigned int V_30 )
{
if ( V_8 -> V_11 . V_5 -> V_27 )
V_8 -> V_11 . V_5 -> V_27 ( & V_8 -> V_11 ) ;
else
V_8 -> V_11 . V_5 -> V_28 ( & V_8 -> V_11 ) ;
F_34 ( V_30 , V_8 -> V_31 ) ;
}
static inline void F_35 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 . V_5 -> V_32 )
V_8 -> V_11 . V_5 -> V_32 ( & V_8 -> V_11 ) ;
else {
V_8 -> V_11 . V_5 -> V_28 ( & V_8 -> V_11 ) ;
if ( V_8 -> V_11 . V_5 -> V_33 )
V_8 -> V_11 . V_5 -> V_33 ( & V_8 -> V_11 ) ;
}
F_22 ( V_8 ) ;
}
void F_30 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 . V_5 -> V_28 ) {
V_8 -> V_11 . V_5 -> V_28 ( & V_8 -> V_11 ) ;
F_22 ( V_8 ) ;
}
}
void F_36 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 . V_5 -> V_29 ) {
V_8 -> V_11 . V_5 -> V_29 ( & V_8 -> V_11 ) ;
F_21 ( V_8 ) ;
}
}
void F_37 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_11 . V_5 ;
if ( V_5 -> V_6 & V_34 )
V_5 -> V_35 ( & V_8 -> V_11 ) ;
if ( V_5 -> V_29 ) {
V_5 -> V_29 ( & V_8 -> V_11 ) ;
F_21 ( V_8 ) ;
}
}
void F_38 ( unsigned int V_1 )
{
struct V_7 * V_8 = F_16 ( V_1 ) ;
struct V_36 * V_37 ;
T_1 V_38 ;
F_39 () ;
F_40 ( & V_8 -> V_39 ) ;
V_8 -> V_40 &= ~ ( V_41 | V_42 ) ;
F_41 ( V_8 ) ;
V_37 = V_8 -> V_37 ;
if ( F_42 ( ! V_37 || F_43 ( & V_8 -> V_11 ) ) ) {
V_8 -> V_40 |= V_43 ;
goto V_44;
}
F_20 ( & V_8 -> V_11 , V_45 ) ;
F_44 ( & V_8 -> V_39 ) ;
V_38 = V_37 -> V_46 ( V_37 -> V_1 , V_37 -> V_2 ) ;
if ( ! V_47 )
F_45 ( V_8 , V_38 ) ;
F_40 ( & V_8 -> V_39 ) ;
F_18 ( & V_8 -> V_11 , V_45 ) ;
V_44:
F_44 ( & V_8 -> V_39 ) ;
}
static bool F_46 ( struct V_7 * V_8 )
{
if ( ! ( V_8 -> V_40 & V_48 ) )
return false ;
return F_47 ( V_8 ) ;
}
static bool F_48 ( struct V_7 * V_8 )
{
unsigned int V_49 = V_45 | V_50 ;
if ( ! F_49 ( & V_8 -> V_11 , V_49 ) )
return true ;
if ( F_50 ( V_8 ) )
return false ;
return F_46 ( V_8 ) ;
}
void F_51 ( struct V_7 * V_8 )
{
F_52 ( & V_8 -> V_39 ) ;
if ( ! F_48 ( V_8 ) )
goto V_44;
V_8 -> V_40 &= ~ ( V_41 | V_42 ) ;
F_41 ( V_8 ) ;
if ( F_42 ( ! V_8 -> V_37 || F_43 ( & V_8 -> V_11 ) ) ) {
V_8 -> V_40 |= V_43 ;
goto V_44;
}
F_53 ( V_8 ) ;
V_44:
F_54 ( & V_8 -> V_39 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
if ( ! F_43 ( & V_8 -> V_11 ) &&
F_56 ( & V_8 -> V_11 ) && ! V_8 -> V_51 )
F_36 ( V_8 ) ;
}
void F_57 ( struct V_7 * V_8 )
{
F_52 ( & V_8 -> V_39 ) ;
F_35 ( V_8 ) ;
if ( ! F_48 ( V_8 ) )
goto V_44;
V_8 -> V_40 &= ~ ( V_41 | V_42 ) ;
F_41 ( V_8 ) ;
if ( F_42 ( ! V_8 -> V_37 || F_43 ( & V_8 -> V_11 ) ) ) {
V_8 -> V_40 |= V_43 ;
goto V_44;
}
F_53 ( V_8 ) ;
F_55 ( V_8 ) ;
V_44:
F_54 ( & V_8 -> V_39 ) ;
}
static inline void F_58 ( struct V_7 * V_8 )
{
if ( V_8 -> F_58 )
V_8 -> F_58 ( & V_8 -> V_11 ) ;
}
static inline void F_58 ( struct V_7 * V_8 ) { }
static void F_59 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
if ( ! ( V_8 -> V_40 & V_52 ) ) {
V_5 -> V_35 ( & V_8 -> V_11 ) ;
return;
}
if ( ! F_43 ( & V_8 -> V_11 ) &&
F_56 ( & V_8 -> V_11 ) && ! V_8 -> V_51 ) {
V_5 -> V_35 ( & V_8 -> V_11 ) ;
F_36 ( V_8 ) ;
} else if ( ! ( V_5 -> V_6 & V_34 ) ) {
V_5 -> V_35 ( & V_8 -> V_11 ) ;
}
}
void F_60 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_11 . V_5 ;
F_52 ( & V_8 -> V_39 ) ;
if ( ! F_48 ( V_8 ) )
goto V_53;
V_8 -> V_40 &= ~ ( V_41 | V_42 ) ;
F_41 ( V_8 ) ;
if ( F_42 ( ! V_8 -> V_37 || F_43 ( & V_8 -> V_11 ) ) ) {
V_8 -> V_40 |= V_43 ;
F_30 ( V_8 ) ;
goto V_53;
}
if ( V_8 -> V_40 & V_52 )
F_30 ( V_8 ) ;
F_58 ( V_8 ) ;
F_53 ( V_8 ) ;
F_59 ( V_8 , V_5 ) ;
F_54 ( & V_8 -> V_39 ) ;
return;
V_53:
if ( ! ( V_5 -> V_6 & V_54 ) )
V_5 -> V_35 ( & V_8 -> V_11 ) ;
F_54 ( & V_8 -> V_39 ) ;
}
void F_61 ( struct V_7 * V_8 )
{
F_52 ( & V_8 -> V_39 ) ;
V_8 -> V_40 &= ~ ( V_41 | V_42 ) ;
if ( ! F_48 ( V_8 ) ) {
V_8 -> V_40 |= V_43 ;
F_35 ( V_8 ) ;
goto V_44;
}
if ( F_43 ( & V_8 -> V_11 ) || ! V_8 -> V_37 ) {
V_8 -> V_40 |= V_43 ;
F_35 ( V_8 ) ;
goto V_44;
}
F_41 ( V_8 ) ;
V_8 -> V_11 . V_5 -> V_33 ( & V_8 -> V_11 ) ;
do {
if ( F_42 ( ! V_8 -> V_37 ) ) {
F_30 ( V_8 ) ;
goto V_44;
}
if ( F_42 ( V_8 -> V_40 & V_43 ) ) {
if ( ! F_43 ( & V_8 -> V_11 ) &&
F_56 ( & V_8 -> V_11 ) )
F_36 ( V_8 ) ;
}
F_53 ( V_8 ) ;
} while ( ( V_8 -> V_40 & V_43 ) &&
! F_43 ( & V_8 -> V_11 ) );
V_44:
F_54 ( & V_8 -> V_39 ) ;
}
void F_62 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_63 ( V_8 ) ;
F_52 ( & V_8 -> V_39 ) ;
V_8 -> V_40 &= ~ ( V_41 | V_42 ) ;
if ( ! F_48 ( V_8 ) ) {
V_8 -> V_40 |= V_43 ;
goto V_55;
}
if ( F_43 ( & V_8 -> V_11 ) || ! V_8 -> V_37 ) {
V_8 -> V_40 |= V_43 ;
goto V_55;
}
F_41 ( V_8 ) ;
do {
if ( F_42 ( ! V_8 -> V_37 ) )
goto V_55;
F_53 ( V_8 ) ;
} while ( ( V_8 -> V_40 & V_43 ) &&
! F_43 ( & V_8 -> V_11 ) );
V_55:
V_5 -> V_35 ( & V_8 -> V_11 ) ;
F_54 ( & V_8 -> V_39 ) ;
}
void F_64 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_63 ( V_8 ) ;
F_41 ( V_8 ) ;
if ( V_5 -> V_33 )
V_5 -> V_33 ( & V_8 -> V_11 ) ;
F_65 ( V_8 ) ;
if ( V_5 -> V_35 )
V_5 -> V_35 ( & V_8 -> V_11 ) ;
}
void F_66 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_63 ( V_8 ) ;
struct V_36 * V_37 = V_8 -> V_37 ;
void * V_2 = F_67 ( V_37 -> V_56 ) ;
unsigned int V_1 = F_68 ( V_8 ) ;
T_1 V_57 ;
F_41 ( V_8 ) ;
if ( V_5 -> V_33 )
V_5 -> V_33 ( & V_8 -> V_11 ) ;
F_69 ( V_1 , V_37 ) ;
V_57 = V_37 -> V_58 ( V_1 , V_2 ) ;
F_70 ( V_1 , V_37 , V_57 ) ;
if ( V_5 -> V_35 )
V_5 -> V_35 ( & V_8 -> V_11 ) ;
}
void
F_71 ( struct V_7 * V_8 , T_2 V_59 ,
int V_60 , const char * V_61 )
{
if ( ! V_59 ) {
V_59 = V_62 ;
} else {
struct V_11 * V_11 = & V_8 -> V_11 ;
#ifdef F_72
while ( V_11 ) {
if ( V_11 -> V_5 != & V_10 )
break;
if ( F_73 ( V_60 ) )
return;
V_11 = V_11 -> V_63 ;
}
#endif
if ( F_73 ( ! V_11 || V_11 -> V_5 == & V_10 ) )
return;
}
if ( V_59 == V_62 ) {
if ( V_8 -> V_11 . V_5 != & V_10 )
F_35 ( V_8 ) ;
F_19 ( V_8 ) ;
if ( V_60 )
V_8 -> V_37 = NULL ;
V_8 -> V_26 = 1 ;
}
V_8 -> V_64 = V_59 ;
V_8 -> V_61 = V_61 ;
if ( V_59 != V_62 && V_60 ) {
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
F_76 ( V_8 ) ;
V_8 -> V_37 = & V_65 ;
F_23 ( V_8 , true ) ;
}
}
void
F_77 ( unsigned int V_1 , T_2 V_59 , int V_60 ,
const char * V_61 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_8 ( V_1 , & V_6 , 0 ) ;
if ( ! V_8 )
return;
F_71 ( V_8 , V_59 , V_60 , V_61 ) ;
F_10 ( V_8 , V_6 ) ;
}
void
F_78 ( unsigned int V_1 , T_2 V_59 ,
void * V_15 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_8 ( V_1 , & V_6 , 0 ) ;
if ( ! V_8 )
return;
F_71 ( V_8 , V_59 , 1 , NULL ) ;
V_8 -> V_16 . V_17 = V_15 ;
F_10 ( V_8 , V_6 ) ;
}
void
F_79 ( unsigned int V_1 , struct V_4 * V_5 ,
T_2 V_59 , const char * V_61 )
{
F_3 ( V_1 , V_5 ) ;
F_77 ( V_1 , V_59 , 0 , V_61 ) ;
}
void F_80 ( unsigned int V_1 , unsigned long V_66 , unsigned long V_67 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_4 ( V_1 , & V_6 , 0 ) ;
if ( ! V_8 )
return;
F_81 ( V_8 , V_66 , V_67 ) ;
F_18 ( & V_8 -> V_11 , V_68 | V_69 |
V_70 | V_71 | V_72 ) ;
if ( F_82 ( V_8 ) )
F_20 ( & V_8 -> V_11 , V_68 ) ;
if ( F_83 ( V_8 ) )
F_20 ( & V_8 -> V_11 , V_69 ) ;
if ( F_84 ( V_8 ) )
F_20 ( & V_8 -> V_11 , V_72 ) ;
if ( F_85 ( V_8 ) )
F_20 ( & V_8 -> V_11 , V_71 ) ;
F_20 ( & V_8 -> V_11 , F_86 ( V_8 ) ) ;
F_5 ( V_8 , V_6 ) ;
}
void F_87 ( void )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
unsigned long V_6 ;
unsigned int V_1 ;
F_88 (irq) {
V_8 = F_16 ( V_1 ) ;
if ( ! V_8 )
continue;
F_89 ( & V_8 -> V_39 , V_6 ) ;
V_5 = F_90 ( & V_8 -> V_11 ) ;
if ( V_5 && V_5 -> F_87 &&
( ! ( V_5 -> V_6 & V_73 ) ||
! F_43 ( & V_8 -> V_11 ) ) )
V_5 -> F_87 ( & V_8 -> V_11 ) ;
F_91 ( & V_8 -> V_39 , V_6 ) ;
}
}
void F_92 ( void )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
unsigned long V_6 ;
unsigned int V_1 ;
F_88 (irq) {
V_8 = F_16 ( V_1 ) ;
if ( ! V_8 )
continue;
F_89 ( & V_8 -> V_39 , V_6 ) ;
V_5 = F_90 ( & V_8 -> V_11 ) ;
if ( V_5 && V_5 -> F_92 &&
( ! ( V_5 -> V_6 & V_73 ) ||
! F_43 ( & V_8 -> V_11 ) ) )
V_5 -> F_92 ( & V_8 -> V_11 ) ;
F_91 ( & V_8 -> V_39 , V_6 ) ;
}
}
void F_93 ( struct V_11 * V_15 )
{
V_15 = V_15 -> V_63 ;
if ( V_15 -> V_5 -> F_25 )
V_15 -> V_5 -> F_25 ( V_15 ) ;
else
V_15 -> V_5 -> V_29 ( V_15 ) ;
}
void F_94 ( struct V_11 * V_15 )
{
V_15 = V_15 -> V_63 ;
if ( V_15 -> V_5 -> V_27 )
V_15 -> V_5 -> V_27 ( V_15 ) ;
else
V_15 -> V_5 -> V_28 ( V_15 ) ;
}
void F_95 ( struct V_11 * V_15 )
{
V_15 = V_15 -> V_63 ;
V_15 -> V_5 -> V_33 ( V_15 ) ;
}
void F_96 ( struct V_11 * V_15 )
{
V_15 = V_15 -> V_63 ;
V_15 -> V_5 -> V_28 ( V_15 ) ;
}
void F_97 ( struct V_11 * V_15 )
{
V_15 = V_15 -> V_63 ;
V_15 -> V_5 -> V_29 ( V_15 ) ;
}
void F_98 ( struct V_11 * V_15 )
{
V_15 = V_15 -> V_63 ;
V_15 -> V_5 -> V_35 ( V_15 ) ;
}
int F_99 ( struct V_11 * V_15 ,
const struct V_74 * V_75 , bool V_76 )
{
V_15 = V_15 -> V_63 ;
if ( V_15 -> V_5 -> V_77 )
return V_15 -> V_5 -> V_77 ( V_15 , V_75 , V_76 ) ;
return - V_78 ;
}
int F_100 ( struct V_11 * V_15 , unsigned int type )
{
V_15 = V_15 -> V_63 ;
if ( V_15 -> V_5 -> V_79 )
return V_15 -> V_5 -> V_79 ( V_15 , type ) ;
return - V_78 ;
}
int F_101 ( struct V_11 * V_15 )
{
for ( V_15 = V_15 -> V_63 ; V_15 ; V_15 = V_15 -> V_63 )
if ( V_15 -> V_5 && V_15 -> V_5 -> V_80 )
return V_15 -> V_5 -> V_80 ( V_15 ) ;
return 0 ;
}
int F_102 ( struct V_11 * V_15 , void * V_81 )
{
V_15 = V_15 -> V_63 ;
if ( V_15 -> V_5 -> V_82 )
return V_15 -> V_5 -> V_82 ( V_15 , V_81 ) ;
return - V_78 ;
}
int F_103 ( struct V_11 * V_15 , unsigned int V_83 )
{
V_15 = V_15 -> V_63 ;
if ( V_15 -> V_5 -> V_84 )
return V_15 -> V_5 -> V_84 ( V_15 , V_83 ) ;
return - V_78 ;
}
int F_104 ( struct V_11 * V_15 , struct V_85 * V_86 )
{
struct V_11 * V_87 = NULL ;
#ifdef F_72
for (; V_15 ; V_15 = V_15 -> V_63 )
#endif
if ( V_15 -> V_5 && V_15 -> V_5 -> V_88 )
V_87 = V_15 ;
if ( ! V_87 )
return - V_78 ;
V_87 -> V_5 -> V_88 ( V_87 , V_86 ) ;
return 0 ;
}
