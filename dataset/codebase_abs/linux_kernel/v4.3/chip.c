int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
if ( ! V_3 )
V_3 = & V_8 ;
V_6 -> V_9 . V_3 = V_3 ;
F_3 ( V_6 , V_4 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_5 ( unsigned int V_1 , unsigned int type )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , V_10 ) ;
int V_11 = 0 ;
if ( ! V_6 )
return - V_7 ;
type &= V_12 ;
V_11 = F_7 ( V_6 , type ) ;
F_8 ( V_6 , V_4 ) ;
return V_11 ;
}
int F_9 ( unsigned int V_1 , void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_14 . V_15 = V_13 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_10 ( unsigned int V_16 , unsigned int V_17 ,
struct V_18 * V_19 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_16 + V_17 , & V_4 , V_10 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_14 . V_18 = V_19 ;
if ( V_19 && ! V_17 )
V_19 -> V_1 = V_16 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_11 ( unsigned int V_1 , struct V_18 * V_19 )
{
return F_10 ( V_1 , 0 , V_19 ) ;
}
int F_12 ( unsigned int V_1 , void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_20 = V_13 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
struct V_9 * F_13 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_14 ( V_1 ) ;
return V_6 ? & V_6 -> V_9 : NULL ;
}
static void F_15 ( struct V_5 * V_6 )
{
F_16 ( & V_6 -> V_9 , V_21 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_9 , V_21 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
F_16 ( & V_6 -> V_9 , V_22 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_9 , V_22 ) ;
}
int F_21 ( struct V_5 * V_6 , bool V_23 )
{
int V_11 = 0 ;
F_15 ( V_6 ) ;
V_6 -> V_24 = 0 ;
F_22 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_9 . V_3 -> F_21 ) {
V_11 = V_6 -> V_9 . V_3 -> F_21 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
} else {
F_23 ( V_6 ) ;
}
if ( V_23 )
F_24 ( V_6 ) ;
return V_11 ;
}
void F_25 ( struct V_5 * V_6 )
{
F_17 ( V_6 ) ;
V_6 -> V_24 = 1 ;
if ( V_6 -> V_9 . V_3 -> F_25 )
V_6 -> V_9 . V_3 -> F_25 ( & V_6 -> V_9 ) ;
else if ( V_6 -> V_9 . V_3 -> V_25 )
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_26 ( & V_6 -> V_9 ) ;
F_20 ( V_6 ) ;
}
void F_23 ( struct V_5 * V_6 )
{
F_15 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> F_23 )
V_6 -> V_9 . V_3 -> F_23 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_27 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
void V_25 ( struct V_5 * V_6 )
{
F_17 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> V_25 ) {
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
F_20 ( V_6 ) ;
}
}
void F_27 ( struct V_5 * V_6 , unsigned int V_28 )
{
if ( V_6 -> V_9 . V_3 -> F_23 )
V_6 -> V_9 . V_3 -> F_23 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_27 ( & V_6 -> V_9 ) ;
F_28 ( V_28 , V_6 -> V_29 ) ;
}
void F_29 ( struct V_5 * V_6 , unsigned int V_28 )
{
if ( V_6 -> V_9 . V_3 -> V_25 )
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_30 ( V_28 , V_6 -> V_29 ) ;
}
static inline void F_31 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_30 )
V_6 -> V_9 . V_3 -> V_30 ( & V_6 -> V_9 ) ;
else {
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_9 . V_3 -> V_31 )
V_6 -> V_9 . V_3 -> V_31 ( & V_6 -> V_9 ) ;
}
F_20 ( V_6 ) ;
}
void F_32 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_26 ) {
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_20 ( V_6 ) ;
}
}
void F_33 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_27 ) {
V_6 -> V_9 . V_3 -> V_27 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_34 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_9 . V_3 ;
if ( V_3 -> V_4 & V_32 )
V_3 -> V_33 ( & V_6 -> V_9 ) ;
if ( V_3 -> V_27 ) {
V_3 -> V_27 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_35 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_14 ( V_1 ) ;
struct V_34 * V_35 ;
T_1 V_36 ;
F_36 () ;
F_37 ( & V_6 -> V_37 ) ;
V_6 -> V_38 &= ~ ( V_39 | V_40 ) ;
F_38 ( V_6 ) ;
V_35 = V_6 -> V_35 ;
if ( F_39 ( ! V_35 || F_40 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_38 |= V_41 ;
goto V_42;
}
F_18 ( & V_6 -> V_9 , V_43 ) ;
F_41 ( & V_6 -> V_37 ) ;
V_36 = V_35 -> V_44 ( V_35 -> V_1 , V_35 -> V_45 ) ;
if ( ! V_46 )
F_42 ( V_6 , V_36 ) ;
F_37 ( & V_6 -> V_37 ) ;
F_16 ( & V_6 -> V_9 , V_43 ) ;
V_42:
F_41 ( & V_6 -> V_37 ) ;
}
static bool F_43 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_38 & V_47 ) )
return false ;
return F_44 ( V_6 ) ;
}
static bool F_45 ( struct V_5 * V_6 )
{
unsigned int V_48 = V_43 | V_49 ;
if ( ! F_46 ( & V_6 -> V_9 , V_48 ) )
return true ;
if ( F_47 ( V_6 ) )
return false ;
return F_43 ( V_6 ) ;
}
void F_48 ( struct V_5 * V_6 )
{
F_49 ( & V_6 -> V_37 ) ;
if ( ! F_45 ( V_6 ) )
goto V_42;
V_6 -> V_38 &= ~ ( V_39 | V_40 ) ;
F_38 ( V_6 ) ;
if ( F_39 ( ! V_6 -> V_35 || F_40 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_38 |= V_41 ;
goto V_42;
}
F_50 ( V_6 ) ;
V_42:
F_51 ( & V_6 -> V_37 ) ;
}
static void F_52 ( struct V_5 * V_6 )
{
if ( ! F_40 ( & V_6 -> V_9 ) &&
F_53 ( & V_6 -> V_9 ) && ! V_6 -> V_50 )
F_33 ( V_6 ) ;
}
void F_54 ( struct V_5 * V_6 )
{
F_49 ( & V_6 -> V_37 ) ;
F_31 ( V_6 ) ;
if ( ! F_45 ( V_6 ) )
goto V_42;
V_6 -> V_38 &= ~ ( V_39 | V_40 ) ;
F_38 ( V_6 ) ;
if ( F_39 ( ! V_6 -> V_35 || F_40 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_38 |= V_41 ;
goto V_42;
}
F_50 ( V_6 ) ;
F_52 ( V_6 ) ;
V_42:
F_51 ( & V_6 -> V_37 ) ;
}
static inline void F_55 ( struct V_5 * V_6 )
{
if ( V_6 -> F_55 )
V_6 -> F_55 ( & V_6 -> V_9 ) ;
}
static inline void F_55 ( struct V_5 * V_6 ) { }
static void F_56 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
if ( ! ( V_6 -> V_38 & V_51 ) ) {
V_3 -> V_33 ( & V_6 -> V_9 ) ;
return;
}
if ( ! F_40 ( & V_6 -> V_9 ) &&
F_53 ( & V_6 -> V_9 ) && ! V_6 -> V_50 ) {
V_3 -> V_33 ( & V_6 -> V_9 ) ;
F_33 ( V_6 ) ;
} else if ( ! ( V_3 -> V_4 & V_32 ) ) {
V_3 -> V_33 ( & V_6 -> V_9 ) ;
}
}
void F_57 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_9 . V_3 ;
F_49 ( & V_6 -> V_37 ) ;
if ( ! F_45 ( V_6 ) )
goto V_52;
V_6 -> V_38 &= ~ ( V_39 | V_40 ) ;
F_38 ( V_6 ) ;
if ( F_39 ( ! V_6 -> V_35 || F_40 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_38 |= V_41 ;
F_32 ( V_6 ) ;
goto V_52;
}
if ( V_6 -> V_38 & V_51 )
F_32 ( V_6 ) ;
F_55 ( V_6 ) ;
F_50 ( V_6 ) ;
F_56 ( V_6 , V_3 ) ;
F_51 ( & V_6 -> V_37 ) ;
return;
V_52:
if ( ! ( V_3 -> V_4 & V_53 ) )
V_3 -> V_33 ( & V_6 -> V_9 ) ;
F_51 ( & V_6 -> V_37 ) ;
}
void F_58 ( struct V_5 * V_6 )
{
F_49 ( & V_6 -> V_37 ) ;
V_6 -> V_38 &= ~ ( V_39 | V_40 ) ;
if ( ! F_45 ( V_6 ) ) {
V_6 -> V_38 |= V_41 ;
F_31 ( V_6 ) ;
goto V_42;
}
if ( F_40 ( & V_6 -> V_9 ) || ! V_6 -> V_35 ) {
V_6 -> V_38 |= V_41 ;
F_31 ( V_6 ) ;
goto V_42;
}
F_38 ( V_6 ) ;
V_6 -> V_9 . V_3 -> V_31 ( & V_6 -> V_9 ) ;
do {
if ( F_39 ( ! V_6 -> V_35 ) ) {
F_32 ( V_6 ) ;
goto V_42;
}
if ( F_39 ( V_6 -> V_38 & V_41 ) ) {
if ( ! F_40 ( & V_6 -> V_9 ) &&
F_53 ( & V_6 -> V_9 ) )
F_33 ( V_6 ) ;
}
F_50 ( V_6 ) ;
} while ( ( V_6 -> V_38 & V_41 ) &&
! F_40 ( & V_6 -> V_9 ) );
V_42:
F_51 ( & V_6 -> V_37 ) ;
}
void F_59 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_60 ( V_6 ) ;
F_49 ( & V_6 -> V_37 ) ;
V_6 -> V_38 &= ~ ( V_39 | V_40 ) ;
if ( ! F_45 ( V_6 ) ) {
V_6 -> V_38 |= V_41 ;
goto V_54;
}
if ( F_40 ( & V_6 -> V_9 ) || ! V_6 -> V_35 ) {
V_6 -> V_38 |= V_41 ;
goto V_54;
}
F_38 ( V_6 ) ;
do {
if ( F_39 ( ! V_6 -> V_35 ) )
goto V_54;
F_50 ( V_6 ) ;
} while ( ( V_6 -> V_38 & V_41 ) &&
! F_40 ( & V_6 -> V_9 ) );
V_54:
V_3 -> V_33 ( & V_6 -> V_9 ) ;
F_51 ( & V_6 -> V_37 ) ;
}
void F_61 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_60 ( V_6 ) ;
F_38 ( V_6 ) ;
if ( V_3 -> V_31 )
V_3 -> V_31 ( & V_6 -> V_9 ) ;
F_62 ( V_6 , V_6 -> V_35 ) ;
if ( V_3 -> V_33 )
V_3 -> V_33 ( & V_6 -> V_9 ) ;
}
void F_63 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_60 ( V_6 ) ;
struct V_34 * V_35 = V_6 -> V_35 ;
void * V_45 = F_64 ( V_35 -> V_55 ) ;
unsigned int V_1 = F_65 ( V_6 ) ;
T_1 V_56 ;
F_38 ( V_6 ) ;
if ( V_3 -> V_31 )
V_3 -> V_31 ( & V_6 -> V_9 ) ;
F_66 ( V_1 , V_35 ) ;
V_56 = V_35 -> V_57 ( V_1 , V_45 ) ;
F_67 ( V_1 , V_35 , V_56 ) ;
if ( V_3 -> V_33 )
V_3 -> V_33 ( & V_6 -> V_9 ) ;
}
void
F_68 ( struct V_5 * V_6 , T_2 V_58 ,
int V_59 , const char * V_60 )
{
if ( ! V_58 ) {
V_58 = V_61 ;
} else {
struct V_9 * V_9 = & V_6 -> V_9 ;
#ifdef F_69
while ( V_9 ) {
if ( V_9 -> V_3 != & V_8 )
break;
if ( F_70 ( V_59 ) )
return;
V_9 = V_9 -> V_62 ;
}
#endif
if ( F_70 ( ! V_9 || V_9 -> V_3 == & V_8 ) )
return;
}
if ( V_58 == V_61 ) {
if ( V_6 -> V_9 . V_3 != & V_8 )
F_31 ( V_6 ) ;
F_17 ( V_6 ) ;
V_6 -> V_24 = 1 ;
}
V_6 -> V_63 = V_58 ;
V_6 -> V_60 = V_60 ;
if ( V_58 != V_61 && V_59 ) {
F_71 ( V_6 ) ;
F_72 ( V_6 ) ;
F_73 ( V_6 ) ;
F_21 ( V_6 , true ) ;
}
}
void
F_74 ( unsigned int V_1 , T_2 V_58 , int V_59 ,
const char * V_60 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_68 ( V_6 , V_58 , V_59 , V_60 ) ;
F_8 ( V_6 , V_4 ) ;
}
void
F_75 ( unsigned int V_1 , T_2 V_58 ,
void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_68 ( V_6 , V_58 , 1 , NULL ) ;
V_6 -> V_14 . V_15 = V_13 ;
F_8 ( V_6 , V_4 ) ;
}
void
F_76 ( unsigned int V_1 , struct V_2 * V_3 ,
T_2 V_58 , const char * V_60 )
{
F_1 ( V_1 , V_3 ) ;
F_74 ( V_1 , V_58 , 0 , V_60 ) ;
}
void F_77 ( unsigned int V_1 , unsigned long V_64 , unsigned long V_65 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_78 ( V_6 , V_64 , V_65 ) ;
F_16 ( & V_6 -> V_9 , V_66 | V_67 |
V_68 | V_69 | V_70 ) ;
if ( F_79 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_66 ) ;
if ( F_80 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_67 ) ;
if ( F_81 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_70 ) ;
if ( F_82 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_69 ) ;
F_18 ( & V_6 -> V_9 , F_83 ( V_6 ) ) ;
F_3 ( V_6 , V_4 ) ;
}
void F_84 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_85 (irq) {
V_6 = F_14 ( V_1 ) ;
if ( ! V_6 )
continue;
F_86 ( & V_6 -> V_37 , V_4 ) ;
V_3 = F_87 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_84 &&
( ! ( V_3 -> V_4 & V_71 ) ||
! F_40 ( & V_6 -> V_9 ) ) )
V_3 -> F_84 ( & V_6 -> V_9 ) ;
F_88 ( & V_6 -> V_37 , V_4 ) ;
}
}
void F_89 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_85 (irq) {
V_6 = F_14 ( V_1 ) ;
if ( ! V_6 )
continue;
F_86 ( & V_6 -> V_37 , V_4 ) ;
V_3 = F_87 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_89 &&
( ! ( V_3 -> V_4 & V_71 ) ||
! F_40 ( & V_6 -> V_9 ) ) )
V_3 -> F_89 ( & V_6 -> V_9 ) ;
F_88 ( & V_6 -> V_37 , V_4 ) ;
}
}
void F_90 ( struct V_9 * V_13 )
{
V_13 = V_13 -> V_62 ;
if ( V_13 -> V_3 -> F_23 )
V_13 -> V_3 -> F_23 ( V_13 ) ;
else
V_13 -> V_3 -> V_27 ( V_13 ) ;
}
void F_91 ( struct V_9 * V_13 )
{
V_13 = V_13 -> V_62 ;
if ( V_13 -> V_3 -> V_25 )
V_13 -> V_3 -> V_25 ( V_13 ) ;
else
V_13 -> V_3 -> V_26 ( V_13 ) ;
}
void F_92 ( struct V_9 * V_13 )
{
V_13 = V_13 -> V_62 ;
V_13 -> V_3 -> V_31 ( V_13 ) ;
}
void F_93 ( struct V_9 * V_13 )
{
V_13 = V_13 -> V_62 ;
V_13 -> V_3 -> V_26 ( V_13 ) ;
}
void F_94 ( struct V_9 * V_13 )
{
V_13 = V_13 -> V_62 ;
V_13 -> V_3 -> V_27 ( V_13 ) ;
}
void F_95 ( struct V_9 * V_13 )
{
V_13 = V_13 -> V_62 ;
V_13 -> V_3 -> V_33 ( V_13 ) ;
}
int F_96 ( struct V_9 * V_13 ,
const struct V_72 * V_73 , bool V_74 )
{
V_13 = V_13 -> V_62 ;
if ( V_13 -> V_3 -> V_75 )
return V_13 -> V_3 -> V_75 ( V_13 , V_73 , V_74 ) ;
return - V_76 ;
}
int F_97 ( struct V_9 * V_13 , unsigned int type )
{
V_13 = V_13 -> V_62 ;
if ( V_13 -> V_3 -> V_77 )
return V_13 -> V_3 -> V_77 ( V_13 , type ) ;
return - V_76 ;
}
int F_98 ( struct V_9 * V_13 )
{
for ( V_13 = V_13 -> V_62 ; V_13 ; V_13 = V_13 -> V_62 )
if ( V_13 -> V_3 && V_13 -> V_3 -> V_78 )
return V_13 -> V_3 -> V_78 ( V_13 ) ;
return 0 ;
}
int F_99 ( struct V_9 * V_13 , void * V_79 )
{
V_13 = V_13 -> V_62 ;
if ( V_13 -> V_3 -> V_80 )
return V_13 -> V_3 -> V_80 ( V_13 , V_79 ) ;
return - V_76 ;
}
int F_100 ( struct V_9 * V_13 , unsigned int V_81 )
{
V_13 = V_13 -> V_62 ;
if ( V_13 -> V_3 -> V_82 )
return V_13 -> V_3 -> V_82 ( V_13 , V_81 ) ;
return - V_76 ;
}
int F_101 ( struct V_9 * V_13 , struct V_83 * V_84 )
{
struct V_9 * V_85 = NULL ;
#ifdef F_69
for (; V_13 ; V_13 = V_13 -> V_62 )
#endif
if ( V_13 -> V_3 && V_13 -> V_3 -> V_86 )
V_85 = V_13 ;
if ( ! V_85 )
return - V_76 ;
V_85 -> V_3 -> V_86 ( V_85 , V_84 ) ;
return 0 ;
}
