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
V_11 = F_7 ( V_6 , V_1 , type ) ;
F_8 ( V_6 , V_4 ) ;
return V_11 ;
}
int F_9 ( unsigned int V_1 , void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_14 = V_13 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_10 ( unsigned int V_15 , unsigned int V_16 ,
struct V_17 * V_18 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_15 + V_16 , & V_4 , V_10 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_17 = V_18 ;
if ( V_18 && ! V_16 )
V_18 -> V_1 = V_15 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_11 ( unsigned int V_1 , struct V_17 * V_18 )
{
return F_10 ( V_1 , 0 , V_18 ) ;
}
int F_12 ( unsigned int V_1 , void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_19 = V_13 ;
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
F_16 ( & V_6 -> V_9 , V_20 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_9 , V_20 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
F_16 ( & V_6 -> V_9 , V_21 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_9 , V_21 ) ;
}
int F_21 ( struct V_5 * V_6 , bool V_22 )
{
int V_11 = 0 ;
F_15 ( V_6 ) ;
V_6 -> V_23 = 0 ;
if ( V_6 -> V_9 . V_3 -> F_21 ) {
V_11 = V_6 -> V_9 . V_3 -> F_21 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
} else {
F_22 ( V_6 ) ;
}
if ( V_22 )
F_23 ( V_6 , V_6 -> V_9 . V_1 ) ;
return V_11 ;
}
void F_24 ( struct V_5 * V_6 )
{
F_17 ( V_6 ) ;
V_6 -> V_23 = 1 ;
if ( V_6 -> V_9 . V_3 -> F_24 )
V_6 -> V_9 . V_3 -> F_24 ( & V_6 -> V_9 ) ;
else if ( V_6 -> V_9 . V_3 -> V_24 )
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
F_20 ( V_6 ) ;
}
void F_22 ( struct V_5 * V_6 )
{
F_15 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> F_22 )
V_6 -> V_9 . V_3 -> F_22 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
void V_24 ( struct V_5 * V_6 )
{
F_17 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> V_24 ) {
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
F_20 ( V_6 ) ;
}
}
void F_25 ( struct V_5 * V_6 , unsigned int V_27 )
{
if ( V_6 -> V_9 . V_3 -> F_22 )
V_6 -> V_9 . V_3 -> F_22 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_26 ( V_27 , V_6 -> V_28 ) ;
}
void F_27 ( struct V_5 * V_6 , unsigned int V_27 )
{
if ( V_6 -> V_9 . V_3 -> V_24 )
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
F_28 ( V_27 , V_6 -> V_28 ) ;
}
static inline void F_29 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_29 )
V_6 -> V_9 . V_3 -> V_29 ( & V_6 -> V_9 ) ;
else {
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_9 . V_3 -> V_30 )
V_6 -> V_9 . V_3 -> V_30 ( & V_6 -> V_9 ) ;
}
F_20 ( V_6 ) ;
}
void F_30 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_25 ) {
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
F_20 ( V_6 ) ;
}
}
void F_31 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_26 ) {
V_6 -> V_9 . V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_32 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_9 . V_3 ;
if ( V_3 -> V_4 & V_31 )
V_3 -> V_32 ( & V_6 -> V_9 ) ;
if ( V_3 -> V_26 ) {
V_3 -> V_26 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_33 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_14 ( V_1 ) ;
struct V_33 * V_34 ;
T_1 V_35 ;
F_34 () ;
F_35 ( & V_6 -> V_36 ) ;
V_6 -> V_37 &= ~ ( V_38 | V_39 ) ;
F_36 ( V_1 , V_6 ) ;
V_34 = V_6 -> V_34 ;
if ( F_37 ( ! V_34 || F_38 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_37 |= V_40 ;
goto V_41;
}
F_18 ( & V_6 -> V_9 , V_42 ) ;
F_39 ( & V_6 -> V_36 ) ;
V_35 = V_34 -> V_43 ( V_34 -> V_1 , V_34 -> V_44 ) ;
if ( ! V_45 )
F_40 ( V_1 , V_6 , V_35 ) ;
F_35 ( & V_6 -> V_36 ) ;
F_16 ( & V_6 -> V_9 , V_42 ) ;
V_41:
F_39 ( & V_6 -> V_36 ) ;
}
static bool F_41 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_37 & V_46 ) )
return false ;
return F_42 ( V_6 ) ;
}
static bool F_43 ( struct V_5 * V_6 )
{
unsigned int V_47 = V_42 | V_48 ;
if ( ! F_44 ( & V_6 -> V_9 , V_47 ) )
return true ;
if ( F_45 ( V_6 ) )
return false ;
return F_41 ( V_6 ) ;
}
void
F_46 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_36 ) ;
if ( ! F_43 ( V_6 ) )
goto V_41;
V_6 -> V_37 &= ~ ( V_38 | V_39 ) ;
F_36 ( V_1 , V_6 ) ;
if ( F_37 ( ! V_6 -> V_34 || F_38 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_37 |= V_40 ;
goto V_41;
}
F_48 ( V_6 ) ;
V_41:
F_49 ( & V_6 -> V_36 ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
if ( ! F_38 ( & V_6 -> V_9 ) &&
F_51 ( & V_6 -> V_9 ) && ! V_6 -> V_49 )
F_31 ( V_6 ) ;
}
void
F_52 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_36 ) ;
F_29 ( V_6 ) ;
if ( ! F_43 ( V_6 ) )
goto V_41;
V_6 -> V_37 &= ~ ( V_38 | V_39 ) ;
F_36 ( V_1 , V_6 ) ;
if ( F_37 ( ! V_6 -> V_34 || F_38 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_37 |= V_40 ;
goto V_41;
}
F_48 ( V_6 ) ;
F_50 ( V_6 ) ;
V_41:
F_49 ( & V_6 -> V_36 ) ;
}
static inline void F_53 ( struct V_5 * V_6 )
{
if ( V_6 -> F_53 )
V_6 -> F_53 ( & V_6 -> V_9 ) ;
}
static inline void F_53 ( struct V_5 * V_6 ) { }
static void F_54 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
if ( ! ( V_6 -> V_37 & V_50 ) ) {
V_3 -> V_32 ( & V_6 -> V_9 ) ;
return;
}
if ( ! F_38 ( & V_6 -> V_9 ) &&
F_51 ( & V_6 -> V_9 ) && ! V_6 -> V_49 ) {
V_3 -> V_32 ( & V_6 -> V_9 ) ;
F_31 ( V_6 ) ;
} else if ( ! ( V_3 -> V_4 & V_31 ) ) {
V_3 -> V_32 ( & V_6 -> V_9 ) ;
}
}
void
F_55 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_9 . V_3 ;
F_47 ( & V_6 -> V_36 ) ;
if ( ! F_43 ( V_6 ) )
goto V_51;
V_6 -> V_37 &= ~ ( V_38 | V_39 ) ;
F_36 ( V_1 , V_6 ) ;
if ( F_37 ( ! V_6 -> V_34 || F_38 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_37 |= V_40 ;
F_30 ( V_6 ) ;
goto V_51;
}
if ( V_6 -> V_37 & V_50 )
F_30 ( V_6 ) ;
F_53 ( V_6 ) ;
F_48 ( V_6 ) ;
F_54 ( V_6 , V_3 ) ;
F_49 ( & V_6 -> V_36 ) ;
return;
V_51:
if ( ! ( V_3 -> V_4 & V_52 ) )
V_3 -> V_32 ( & V_6 -> V_9 ) ;
F_49 ( & V_6 -> V_36 ) ;
}
void
F_56 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_36 ) ;
V_6 -> V_37 &= ~ ( V_38 | V_39 ) ;
if ( ! F_43 ( V_6 ) ) {
V_6 -> V_37 |= V_40 ;
F_29 ( V_6 ) ;
goto V_41;
}
if ( F_38 ( & V_6 -> V_9 ) || ! V_6 -> V_34 ) {
V_6 -> V_37 |= V_40 ;
F_29 ( V_6 ) ;
goto V_41;
}
F_36 ( V_1 , V_6 ) ;
V_6 -> V_9 . V_3 -> V_30 ( & V_6 -> V_9 ) ;
do {
if ( F_37 ( ! V_6 -> V_34 ) ) {
F_30 ( V_6 ) ;
goto V_41;
}
if ( F_37 ( V_6 -> V_37 & V_40 ) ) {
if ( ! F_38 ( & V_6 -> V_9 ) &&
F_51 ( & V_6 -> V_9 ) )
F_31 ( V_6 ) ;
}
F_48 ( V_6 ) ;
} while ( ( V_6 -> V_37 & V_40 ) &&
! F_38 ( & V_6 -> V_9 ) );
V_41:
F_49 ( & V_6 -> V_36 ) ;
}
void F_57 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_58 ( V_6 ) ;
F_47 ( & V_6 -> V_36 ) ;
V_6 -> V_37 &= ~ ( V_38 | V_39 ) ;
if ( ! F_43 ( V_6 ) ) {
V_6 -> V_37 |= V_40 ;
goto V_53;
}
if ( F_38 ( & V_6 -> V_9 ) || ! V_6 -> V_34 ) {
V_6 -> V_37 |= V_40 ;
goto V_53;
}
F_36 ( V_1 , V_6 ) ;
do {
if ( F_37 ( ! V_6 -> V_34 ) )
goto V_53;
F_48 ( V_6 ) ;
} while ( ( V_6 -> V_37 & V_40 ) &&
! F_38 ( & V_6 -> V_9 ) );
V_53:
V_3 -> V_32 ( & V_6 -> V_9 ) ;
F_49 ( & V_6 -> V_36 ) ;
}
void
F_59 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_58 ( V_6 ) ;
F_36 ( V_1 , V_6 ) ;
if ( V_3 -> V_30 )
V_3 -> V_30 ( & V_6 -> V_9 ) ;
F_60 ( V_6 , V_6 -> V_34 ) ;
if ( V_3 -> V_32 )
V_3 -> V_32 ( & V_6 -> V_9 ) ;
}
void F_61 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_58 ( V_6 ) ;
struct V_33 * V_34 = V_6 -> V_34 ;
void * V_44 = F_62 ( V_34 -> V_54 ) ;
T_1 V_55 ;
F_36 ( V_1 , V_6 ) ;
if ( V_3 -> V_30 )
V_3 -> V_30 ( & V_6 -> V_9 ) ;
F_63 ( V_1 , V_34 ) ;
V_55 = V_34 -> V_56 ( V_1 , V_44 ) ;
F_64 ( V_1 , V_34 , V_55 ) ;
if ( V_3 -> V_32 )
V_3 -> V_32 ( & V_6 -> V_9 ) ;
}
void
F_65 ( unsigned int V_1 , T_2 V_57 , int V_58 ,
const char * V_59 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
if ( ! V_57 ) {
V_57 = V_60 ;
} else {
if ( F_66 ( V_6 -> V_9 . V_3 == & V_8 ) )
goto V_51;
}
if ( V_57 == V_60 ) {
if ( V_6 -> V_9 . V_3 != & V_8 )
F_29 ( V_6 ) ;
F_17 ( V_6 ) ;
V_6 -> V_23 = 1 ;
}
V_6 -> V_61 = V_57 ;
V_6 -> V_59 = V_59 ;
if ( V_57 != V_60 && V_58 ) {
F_67 ( V_6 ) ;
F_68 ( V_6 ) ;
F_69 ( V_6 ) ;
F_21 ( V_6 , true ) ;
}
V_51:
F_8 ( V_6 , V_4 ) ;
}
void
F_70 ( unsigned int V_1 , struct V_2 * V_3 ,
T_2 V_57 , const char * V_59 )
{
F_1 ( V_1 , V_3 ) ;
F_65 ( V_1 , V_57 , 0 , V_59 ) ;
}
void F_71 ( unsigned int V_1 , unsigned long V_62 , unsigned long V_63 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_72 ( V_6 , V_62 , V_63 ) ;
F_16 ( & V_6 -> V_9 , V_64 | V_65 |
V_66 | V_67 | V_68 ) ;
if ( F_73 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_64 ) ;
if ( F_74 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_65 ) ;
if ( F_75 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_68 ) ;
if ( F_76 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_67 ) ;
F_18 ( & V_6 -> V_9 , F_77 ( V_6 ) ) ;
F_3 ( V_6 , V_4 ) ;
}
void F_78 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_79 (irq) {
V_6 = F_14 ( V_1 ) ;
if ( ! V_6 )
continue;
F_80 ( & V_6 -> V_36 , V_4 ) ;
V_3 = F_81 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_78 &&
( ! ( V_3 -> V_4 & V_69 ) ||
! F_38 ( & V_6 -> V_9 ) ) )
V_3 -> F_78 ( & V_6 -> V_9 ) ;
F_82 ( & V_6 -> V_36 , V_4 ) ;
}
}
void F_83 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_79 (irq) {
V_6 = F_14 ( V_1 ) ;
if ( ! V_6 )
continue;
F_80 ( & V_6 -> V_36 , V_4 ) ;
V_3 = F_81 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_83 &&
( ! ( V_3 -> V_4 & V_69 ) ||
! F_38 ( & V_6 -> V_9 ) ) )
V_3 -> F_83 ( & V_6 -> V_9 ) ;
F_82 ( & V_6 -> V_36 , V_4 ) ;
}
}
