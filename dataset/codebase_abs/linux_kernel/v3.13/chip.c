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
void F_32 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_14 ( V_1 ) ;
struct V_31 * V_32 ;
T_1 V_33 ;
F_33 () ;
F_34 ( & V_6 -> V_34 ) ;
V_6 -> V_35 &= ~ ( V_36 | V_37 ) ;
F_35 ( V_1 , V_6 ) ;
V_32 = V_6 -> V_32 ;
if ( F_36 ( ! V_32 || F_37 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_35 |= V_38 ;
goto V_39;
}
F_18 ( & V_6 -> V_9 , V_40 ) ;
F_38 ( & V_6 -> V_34 ) ;
V_33 = V_32 -> V_41 ( V_32 -> V_1 , V_32 -> V_42 ) ;
if ( ! V_43 )
F_39 ( V_1 , V_6 , V_33 ) ;
F_34 ( & V_6 -> V_34 ) ;
F_16 ( & V_6 -> V_9 , V_40 ) ;
V_39:
F_38 ( & V_6 -> V_34 ) ;
}
static bool F_40 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_35 & V_44 ) )
return false ;
return F_41 ( V_6 ) ;
}
void
F_42 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_43 ( & V_6 -> V_34 ) ;
if ( F_36 ( F_44 ( & V_6 -> V_9 ) ) )
if ( ! F_40 ( V_6 ) )
goto V_39;
V_6 -> V_35 &= ~ ( V_36 | V_37 ) ;
F_35 ( V_1 , V_6 ) ;
if ( F_36 ( ! V_6 -> V_32 || F_37 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_35 |= V_38 ;
goto V_39;
}
F_45 ( V_6 ) ;
V_39:
F_46 ( & V_6 -> V_34 ) ;
}
static void F_47 ( struct V_5 * V_6 )
{
if ( ! F_37 ( & V_6 -> V_9 ) &&
F_48 ( & V_6 -> V_9 ) && ! V_6 -> V_45 )
F_31 ( V_6 ) ;
}
void
F_49 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_43 ( & V_6 -> V_34 ) ;
F_29 ( V_6 ) ;
if ( F_36 ( F_44 ( & V_6 -> V_9 ) ) )
if ( ! F_40 ( V_6 ) )
goto V_39;
V_6 -> V_35 &= ~ ( V_36 | V_37 ) ;
F_35 ( V_1 , V_6 ) ;
if ( F_36 ( ! V_6 -> V_32 || F_37 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_35 |= V_38 ;
goto V_39;
}
F_45 ( V_6 ) ;
F_47 ( V_6 ) ;
V_39:
F_46 ( & V_6 -> V_34 ) ;
}
static inline void F_50 ( struct V_5 * V_6 )
{
if ( V_6 -> F_50 )
V_6 -> F_50 ( & V_6 -> V_9 ) ;
}
static inline void F_50 ( struct V_5 * V_6 ) { }
void
F_51 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_43 ( & V_6 -> V_34 ) ;
if ( F_36 ( F_44 ( & V_6 -> V_9 ) ) )
if ( ! F_40 ( V_6 ) )
goto V_46;
V_6 -> V_35 &= ~ ( V_36 | V_37 ) ;
F_35 ( V_1 , V_6 ) ;
if ( F_36 ( ! V_6 -> V_32 || F_37 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_35 |= V_38 ;
F_30 ( V_6 ) ;
goto V_46;
}
if ( V_6 -> V_35 & V_47 )
F_30 ( V_6 ) ;
F_50 ( V_6 ) ;
F_45 ( V_6 ) ;
if ( V_6 -> V_35 & V_47 )
F_47 ( V_6 ) ;
V_48:
V_6 -> V_9 . V_3 -> V_49 ( & V_6 -> V_9 ) ;
V_39:
F_46 ( & V_6 -> V_34 ) ;
return;
V_46:
if ( ! ( V_6 -> V_9 . V_3 -> V_4 & V_50 ) )
goto V_48;
goto V_39;
}
void
F_52 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_43 ( & V_6 -> V_34 ) ;
V_6 -> V_35 &= ~ ( V_36 | V_37 ) ;
if ( F_36 ( F_37 ( & V_6 -> V_9 ) ||
F_44 ( & V_6 -> V_9 ) || ! V_6 -> V_32 ) ) {
if ( ! F_40 ( V_6 ) ) {
V_6 -> V_35 |= V_38 ;
F_29 ( V_6 ) ;
goto V_39;
}
}
F_35 ( V_1 , V_6 ) ;
V_6 -> V_9 . V_3 -> V_30 ( & V_6 -> V_9 ) ;
do {
if ( F_36 ( ! V_6 -> V_32 ) ) {
F_30 ( V_6 ) ;
goto V_39;
}
if ( F_36 ( V_6 -> V_35 & V_38 ) ) {
if ( ! F_37 ( & V_6 -> V_9 ) &&
F_48 ( & V_6 -> V_9 ) )
F_31 ( V_6 ) ;
}
F_45 ( V_6 ) ;
} while ( ( V_6 -> V_35 & V_38 ) &&
! F_37 ( & V_6 -> V_9 ) );
V_39:
F_46 ( & V_6 -> V_34 ) ;
}
void F_53 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_54 ( V_6 ) ;
F_43 ( & V_6 -> V_34 ) ;
V_6 -> V_35 &= ~ ( V_36 | V_37 ) ;
if ( F_36 ( F_37 ( & V_6 -> V_9 ) ||
F_44 ( & V_6 -> V_9 ) || ! V_6 -> V_32 ) ) {
if ( ! F_40 ( V_6 ) ) {
V_6 -> V_35 |= V_38 ;
goto V_48;
}
}
F_35 ( V_1 , V_6 ) ;
do {
if ( F_36 ( ! V_6 -> V_32 ) )
goto V_48;
F_45 ( V_6 ) ;
} while ( ( V_6 -> V_35 & V_38 ) &&
! F_37 ( & V_6 -> V_9 ) );
V_48:
V_3 -> V_49 ( & V_6 -> V_9 ) ;
F_46 ( & V_6 -> V_34 ) ;
}
void
F_55 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_54 ( V_6 ) ;
F_35 ( V_1 , V_6 ) ;
if ( V_3 -> V_30 )
V_3 -> V_30 ( & V_6 -> V_9 ) ;
F_56 ( V_6 , V_6 -> V_32 ) ;
if ( V_3 -> V_49 )
V_3 -> V_49 ( & V_6 -> V_9 ) ;
}
void F_57 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_54 ( V_6 ) ;
struct V_31 * V_32 = V_6 -> V_32 ;
void * V_42 = F_58 ( V_32 -> V_51 ) ;
T_1 V_52 ;
F_35 ( V_1 , V_6 ) ;
if ( V_3 -> V_30 )
V_3 -> V_30 ( & V_6 -> V_9 ) ;
F_59 ( V_1 , V_32 ) ;
V_52 = V_32 -> V_53 ( V_1 , V_42 ) ;
F_60 ( V_1 , V_32 , V_52 ) ;
if ( V_3 -> V_49 )
V_3 -> V_49 ( & V_6 -> V_9 ) ;
}
void
F_61 ( unsigned int V_1 , T_2 V_54 , int V_55 ,
const char * V_56 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
if ( ! V_54 ) {
V_54 = V_57 ;
} else {
if ( F_62 ( V_6 -> V_9 . V_3 == & V_8 ) )
goto V_46;
}
if ( V_54 == V_57 ) {
if ( V_6 -> V_9 . V_3 != & V_8 )
F_29 ( V_6 ) ;
F_17 ( V_6 ) ;
V_6 -> V_23 = 1 ;
}
V_6 -> V_58 = V_54 ;
V_6 -> V_56 = V_56 ;
if ( V_54 != V_57 && V_55 ) {
F_63 ( V_6 ) ;
F_64 ( V_6 ) ;
F_65 ( V_6 ) ;
F_21 ( V_6 , true ) ;
}
V_46:
F_8 ( V_6 , V_4 ) ;
}
void
F_66 ( unsigned int V_1 , struct V_2 * V_3 ,
T_2 V_54 , const char * V_56 )
{
F_1 ( V_1 , V_3 ) ;
F_61 ( V_1 , V_54 , 0 , V_56 ) ;
}
void F_67 ( unsigned int V_1 , unsigned long V_59 , unsigned long V_60 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_68 ( V_6 , V_59 , V_60 ) ;
F_16 ( & V_6 -> V_9 , V_61 | V_62 |
V_63 | V_64 | V_65 ) ;
if ( F_69 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_61 ) ;
if ( F_70 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_62 ) ;
if ( F_71 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_65 ) ;
if ( F_72 ( V_6 ) )
F_18 ( & V_6 -> V_9 , V_64 ) ;
F_18 ( & V_6 -> V_9 , F_73 ( V_6 ) ) ;
F_3 ( V_6 , V_4 ) ;
}
void F_74 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_75 (irq) {
V_6 = F_14 ( V_1 ) ;
if ( ! V_6 )
continue;
F_76 ( & V_6 -> V_34 , V_4 ) ;
V_3 = F_77 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_74 &&
( ! ( V_3 -> V_4 & V_66 ) ||
! F_37 ( & V_6 -> V_9 ) ) )
V_3 -> F_74 ( & V_6 -> V_9 ) ;
F_78 ( & V_6 -> V_34 , V_4 ) ;
}
}
void F_79 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_75 (irq) {
V_6 = F_14 ( V_1 ) ;
if ( ! V_6 )
continue;
F_76 ( & V_6 -> V_34 , V_4 ) ;
V_3 = F_77 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_79 &&
( ! ( V_3 -> V_4 & V_66 ) ||
! F_37 ( & V_6 -> V_9 ) ) )
V_3 -> F_79 ( & V_6 -> V_9 ) ;
F_78 ( & V_6 -> V_34 , V_4 ) ;
}
}
