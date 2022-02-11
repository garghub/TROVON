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
int F_10 ( unsigned int V_1 , struct V_15 * V_16 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , V_10 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_15 = V_16 ;
if ( V_16 )
V_16 -> V_1 = V_1 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_11 ( unsigned int V_1 , void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_17 = V_13 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
struct V_9 * F_12 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_13 ( V_1 ) ;
return V_6 ? & V_6 -> V_9 : NULL ;
}
static void F_14 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_9 , V_18 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
F_17 ( & V_6 -> V_9 , V_18 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_9 , V_19 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
F_17 ( & V_6 -> V_9 , V_19 ) ;
}
int F_20 ( struct V_5 * V_6 , bool V_20 )
{
int V_11 = 0 ;
F_14 ( V_6 ) ;
V_6 -> V_21 = 0 ;
if ( V_6 -> V_9 . V_3 -> F_20 ) {
V_11 = V_6 -> V_9 . V_3 -> F_20 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
} else {
F_21 ( V_6 ) ;
}
if ( V_20 )
F_22 ( V_6 , V_6 -> V_9 . V_1 ) ;
return V_11 ;
}
void F_23 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
V_6 -> V_21 = 1 ;
if ( V_6 -> V_9 . V_3 -> F_23 )
V_6 -> V_9 . V_3 -> F_23 ( & V_6 -> V_9 ) ;
else if ( V_6 -> V_9 . V_3 -> V_22 )
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
void F_21 ( struct V_5 * V_6 )
{
F_14 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> F_21 )
V_6 -> V_9 . V_3 -> F_21 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
}
void V_22 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> V_22 ) {
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_24 ( struct V_5 * V_6 , unsigned int V_25 )
{
if ( V_6 -> V_9 . V_3 -> F_21 )
V_6 -> V_9 . V_3 -> F_21 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
F_25 ( V_25 , V_6 -> V_26 ) ;
}
void F_26 ( struct V_5 * V_6 , unsigned int V_25 )
{
if ( V_6 -> V_9 . V_3 -> V_22 )
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_27 ( V_25 , V_6 -> V_26 ) ;
}
static inline void F_28 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_27 )
V_6 -> V_9 . V_3 -> V_27 ( & V_6 -> V_9 ) ;
else {
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_9 . V_3 -> V_28 )
V_6 -> V_9 . V_3 -> V_28 ( & V_6 -> V_9 ) ;
}
F_19 ( V_6 ) ;
}
void F_29 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_23 ) {
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_30 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_24 ) {
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
}
}
void F_31 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_13 ( V_1 ) ;
struct V_29 * V_30 ;
T_1 V_31 ;
F_32 () ;
F_33 ( & V_6 -> V_32 ) ;
F_34 ( V_1 , V_6 ) ;
V_30 = V_6 -> V_30 ;
if ( F_35 ( ! V_30 || F_36 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_33 |= V_34 ;
goto V_35;
}
F_17 ( & V_6 -> V_9 , V_36 ) ;
F_37 ( & V_6 -> V_32 ) ;
V_31 = V_30 -> V_37 ( V_30 -> V_1 , V_30 -> V_38 ) ;
if ( ! V_39 )
F_38 ( V_1 , V_6 , V_31 ) ;
F_33 ( & V_6 -> V_32 ) ;
F_15 ( & V_6 -> V_9 , V_36 ) ;
V_35:
F_37 ( & V_6 -> V_32 ) ;
}
static bool F_39 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_33 & V_40 ) )
return false ;
return F_40 ( V_6 ) ;
}
void
F_41 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_42 ( & V_6 -> V_32 ) ;
if ( F_35 ( F_43 ( & V_6 -> V_9 ) ) )
if ( ! F_39 ( V_6 ) )
goto V_35;
V_6 -> V_33 &= ~ ( V_41 | V_42 ) ;
F_34 ( V_1 , V_6 ) ;
if ( F_35 ( ! V_6 -> V_30 || F_36 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_33 |= V_34 ;
goto V_35;
}
F_44 ( V_6 ) ;
V_35:
F_45 ( & V_6 -> V_32 ) ;
}
static void F_46 ( struct V_5 * V_6 )
{
if ( ! F_36 ( & V_6 -> V_9 ) &&
F_47 ( & V_6 -> V_9 ) && ! V_6 -> V_43 )
F_30 ( V_6 ) ;
}
void
F_48 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_42 ( & V_6 -> V_32 ) ;
F_28 ( V_6 ) ;
if ( F_35 ( F_43 ( & V_6 -> V_9 ) ) )
if ( ! F_39 ( V_6 ) )
goto V_35;
V_6 -> V_33 &= ~ ( V_41 | V_42 ) ;
F_34 ( V_1 , V_6 ) ;
if ( F_35 ( ! V_6 -> V_30 || F_36 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_33 |= V_34 ;
goto V_35;
}
F_44 ( V_6 ) ;
F_46 ( V_6 ) ;
V_35:
F_45 ( & V_6 -> V_32 ) ;
}
static inline void F_49 ( struct V_5 * V_6 )
{
if ( V_6 -> F_49 )
V_6 -> F_49 ( & V_6 -> V_9 ) ;
}
static inline void F_49 ( struct V_5 * V_6 ) { }
void
F_50 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_42 ( & V_6 -> V_32 ) ;
if ( F_35 ( F_43 ( & V_6 -> V_9 ) ) )
if ( ! F_39 ( V_6 ) )
goto V_44;
V_6 -> V_33 &= ~ ( V_41 | V_42 ) ;
F_34 ( V_1 , V_6 ) ;
if ( F_35 ( ! V_6 -> V_30 || F_36 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_33 |= V_34 ;
F_29 ( V_6 ) ;
goto V_44;
}
if ( V_6 -> V_33 & V_45 )
F_29 ( V_6 ) ;
F_49 ( V_6 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_33 & V_45 )
F_46 ( V_6 ) ;
V_46:
V_6 -> V_9 . V_3 -> V_47 ( & V_6 -> V_9 ) ;
V_35:
F_45 ( & V_6 -> V_32 ) ;
return;
V_44:
if ( ! ( V_6 -> V_9 . V_3 -> V_4 & V_48 ) )
goto V_46;
goto V_35;
}
void
F_51 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_42 ( & V_6 -> V_32 ) ;
V_6 -> V_33 &= ~ ( V_41 | V_42 ) ;
if ( F_35 ( F_36 ( & V_6 -> V_9 ) ||
F_43 ( & V_6 -> V_9 ) || ! V_6 -> V_30 ) ) {
if ( ! F_39 ( V_6 ) ) {
V_6 -> V_33 |= V_34 ;
F_28 ( V_6 ) ;
goto V_35;
}
}
F_34 ( V_1 , V_6 ) ;
V_6 -> V_9 . V_3 -> V_28 ( & V_6 -> V_9 ) ;
do {
if ( F_35 ( ! V_6 -> V_30 ) ) {
F_29 ( V_6 ) ;
goto V_35;
}
if ( F_35 ( V_6 -> V_33 & V_34 ) ) {
if ( ! F_36 ( & V_6 -> V_9 ) &&
F_47 ( & V_6 -> V_9 ) )
F_30 ( V_6 ) ;
}
F_44 ( V_6 ) ;
} while ( ( V_6 -> V_33 & V_34 ) &&
! F_36 ( & V_6 -> V_9 ) );
V_35:
F_45 ( & V_6 -> V_32 ) ;
}
void F_52 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_53 ( V_6 ) ;
F_42 ( & V_6 -> V_32 ) ;
V_6 -> V_33 &= ~ ( V_41 | V_42 ) ;
if ( F_35 ( F_36 ( & V_6 -> V_9 ) ||
F_43 ( & V_6 -> V_9 ) || ! V_6 -> V_30 ) ) {
if ( ! F_39 ( V_6 ) ) {
V_6 -> V_33 |= V_34 ;
goto V_46;
}
}
F_34 ( V_1 , V_6 ) ;
do {
if ( F_35 ( ! V_6 -> V_30 ) )
goto V_46;
F_44 ( V_6 ) ;
} while ( ( V_6 -> V_33 & V_34 ) &&
! F_36 ( & V_6 -> V_9 ) );
V_46:
V_3 -> V_47 ( & V_6 -> V_9 ) ;
F_45 ( & V_6 -> V_32 ) ;
}
void
F_54 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_53 ( V_6 ) ;
F_34 ( V_1 , V_6 ) ;
if ( V_3 -> V_28 )
V_3 -> V_28 ( & V_6 -> V_9 ) ;
F_55 ( V_6 , V_6 -> V_30 ) ;
if ( V_3 -> V_47 )
V_3 -> V_47 ( & V_6 -> V_9 ) ;
}
void F_56 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_53 ( V_6 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
void * V_38 = F_57 ( V_30 -> V_49 ) ;
T_1 V_50 ;
F_34 ( V_1 , V_6 ) ;
if ( V_3 -> V_28 )
V_3 -> V_28 ( & V_6 -> V_9 ) ;
F_58 ( V_1 , V_30 ) ;
V_50 = V_30 -> V_51 ( V_1 , V_38 ) ;
F_59 ( V_1 , V_30 , V_50 ) ;
if ( V_3 -> V_47 )
V_3 -> V_47 ( & V_6 -> V_9 ) ;
}
void
F_60 ( unsigned int V_1 , T_2 V_52 , int V_53 ,
const char * V_54 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
if ( ! V_52 ) {
V_52 = V_55 ;
} else {
if ( F_61 ( V_6 -> V_9 . V_3 == & V_8 ) )
goto V_44;
}
if ( V_52 == V_55 ) {
if ( V_6 -> V_9 . V_3 != & V_8 )
F_28 ( V_6 ) ;
F_16 ( V_6 ) ;
V_6 -> V_21 = 1 ;
}
V_6 -> V_56 = V_52 ;
V_6 -> V_54 = V_54 ;
if ( V_52 != V_55 && V_53 ) {
F_62 ( V_6 ) ;
F_63 ( V_6 ) ;
F_64 ( V_6 ) ;
F_20 ( V_6 , true ) ;
}
V_44:
F_8 ( V_6 , V_4 ) ;
}
void
F_65 ( unsigned int V_1 , struct V_2 * V_3 ,
T_2 V_52 , const char * V_54 )
{
F_1 ( V_1 , V_3 ) ;
F_60 ( V_1 , V_52 , 0 , V_54 ) ;
}
void F_66 ( unsigned int V_1 , unsigned long V_57 , unsigned long V_58 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_67 ( V_6 , V_57 , V_58 ) ;
F_15 ( & V_6 -> V_9 , V_59 | V_60 |
V_61 | V_62 | V_63 ) ;
if ( F_68 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_59 ) ;
if ( F_69 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_60 ) ;
if ( F_70 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_63 ) ;
if ( F_71 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_62 ) ;
F_17 ( & V_6 -> V_9 , F_72 ( V_6 ) ) ;
F_3 ( V_6 , V_4 ) ;
}
void F_73 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_74 (irq) {
V_6 = F_13 ( V_1 ) ;
if ( ! V_6 )
continue;
F_75 ( & V_6 -> V_32 , V_4 ) ;
V_3 = F_76 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_73 &&
( ! ( V_3 -> V_4 & V_64 ) ||
! F_36 ( & V_6 -> V_9 ) ) )
V_3 -> F_73 ( & V_6 -> V_9 ) ;
F_77 ( & V_6 -> V_32 , V_4 ) ;
}
}
void F_78 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_74 (irq) {
V_6 = F_13 ( V_1 ) ;
if ( ! V_6 )
continue;
F_75 ( & V_6 -> V_32 , V_4 ) ;
V_3 = F_76 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_78 &&
( ! ( V_3 -> V_4 & V_64 ) ||
! F_36 ( & V_6 -> V_9 ) ) )
V_3 -> F_78 ( & V_6 -> V_9 ) ;
F_77 ( & V_6 -> V_32 , V_4 ) ;
}
}
