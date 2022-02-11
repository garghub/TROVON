int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 ) ;
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
struct V_5 * V_6 = F_6 ( V_1 , & V_4 ) ;
int V_10 = 0 ;
if ( ! V_6 )
return - V_7 ;
type &= V_11 ;
if ( type != V_12 )
V_10 = F_7 ( V_6 , V_1 , type ) ;
F_8 ( V_6 , V_4 ) ;
return V_10 ;
}
int F_9 ( unsigned int V_1 , void * V_13 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_14 = V_13 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_10 ( unsigned int V_1 , struct V_15 * V_16 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 ) ;
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
struct V_5 * V_6 = F_2 ( V_1 , & V_4 ) ;
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
int F_20 ( struct V_5 * V_6 )
{
F_14 ( V_6 ) ;
V_6 -> V_20 = 0 ;
if ( V_6 -> V_9 . V_3 -> F_20 ) {
int V_10 = V_6 -> V_9 . V_3 -> F_20 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
return V_10 ;
}
F_21 ( V_6 ) ;
return 0 ;
}
void F_22 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
V_6 -> V_20 = 1 ;
if ( V_6 -> V_9 . V_3 -> F_22 )
V_6 -> V_9 . V_3 -> F_22 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_9 . V_3 -> V_21 )
V_6 -> V_9 . V_3 -> V_21 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
void F_21 ( struct V_5 * V_6 )
{
F_14 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> F_21 )
V_6 -> V_9 . V_3 -> F_21 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
}
void V_21 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
if ( V_6 -> V_9 . V_3 -> V_21 ) {
V_6 -> V_9 . V_3 -> V_21 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
static inline void F_23 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_24 )
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
else {
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_9 . V_3 -> V_25 )
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
}
F_19 ( V_6 ) ;
}
void F_24 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_22 ) {
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_25 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_23 ) {
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
}
}
void F_26 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_13 ( V_1 ) ;
struct V_26 * V_27 ;
T_1 V_28 ;
F_27 () ;
F_28 ( & V_6 -> V_29 ) ;
F_29 ( V_1 , V_6 ) ;
V_27 = V_6 -> V_27 ;
if ( F_30 ( ! V_27 || F_31 ( & V_6 -> V_9 ) ) )
goto V_30;
F_17 ( & V_6 -> V_9 , V_31 ) ;
F_32 ( & V_6 -> V_29 ) ;
V_28 = V_27 -> V_32 ( V_27 -> V_1 , V_27 -> V_33 ) ;
if ( ! V_34 )
F_33 ( V_1 , V_6 , V_28 ) ;
F_28 ( & V_6 -> V_29 ) ;
F_15 ( & V_6 -> V_9 , V_31 ) ;
V_30:
F_32 ( & V_6 -> V_29 ) ;
}
static bool F_34 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_35 & V_36 ) )
return false ;
return F_35 ( V_6 ) ;
}
void
F_36 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_37 ( & V_6 -> V_29 ) ;
if ( F_30 ( F_38 ( & V_6 -> V_9 ) ) )
if ( ! F_34 ( V_6 ) )
goto V_30;
V_6 -> V_35 &= ~ ( V_37 | V_38 ) ;
F_29 ( V_1 , V_6 ) ;
if ( F_30 ( ! V_6 -> V_27 || F_31 ( & V_6 -> V_9 ) ) )
goto V_30;
F_39 ( V_6 ) ;
V_30:
F_40 ( & V_6 -> V_29 ) ;
}
void
F_41 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_37 ( & V_6 -> V_29 ) ;
F_23 ( V_6 ) ;
if ( F_30 ( F_38 ( & V_6 -> V_9 ) ) )
if ( ! F_34 ( V_6 ) )
goto V_30;
V_6 -> V_35 &= ~ ( V_37 | V_38 ) ;
F_29 ( V_1 , V_6 ) ;
if ( F_30 ( ! V_6 -> V_27 || F_31 ( & V_6 -> V_9 ) ) )
goto V_30;
F_39 ( V_6 ) ;
if ( ! F_31 ( & V_6 -> V_9 ) && ! ( V_6 -> V_35 & V_39 ) )
F_25 ( V_6 ) ;
V_30:
F_40 ( & V_6 -> V_29 ) ;
}
static inline void F_42 ( struct V_5 * V_6 )
{
if ( V_6 -> F_42 )
V_6 -> F_42 ( & V_6 -> V_9 ) ;
}
static inline void F_42 ( struct V_5 * V_6 ) { }
void
F_43 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_37 ( & V_6 -> V_29 ) ;
if ( F_30 ( F_38 ( & V_6 -> V_9 ) ) )
if ( ! F_34 ( V_6 ) )
goto V_40;
V_6 -> V_35 &= ~ ( V_37 | V_38 ) ;
F_29 ( V_1 , V_6 ) ;
if ( F_30 ( ! V_6 -> V_27 || F_31 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_35 |= V_41 ;
F_24 ( V_6 ) ;
goto V_40;
}
if ( V_6 -> V_35 & V_39 )
F_24 ( V_6 ) ;
F_42 ( V_6 ) ;
F_39 ( V_6 ) ;
V_42:
V_6 -> V_9 . V_3 -> V_43 ( & V_6 -> V_9 ) ;
V_30:
F_40 ( & V_6 -> V_29 ) ;
return;
V_40:
if ( ! ( V_6 -> V_9 . V_3 -> V_4 & V_44 ) )
goto V_42;
goto V_30;
}
void
F_44 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_37 ( & V_6 -> V_29 ) ;
V_6 -> V_35 &= ~ ( V_37 | V_38 ) ;
if ( F_30 ( F_31 ( & V_6 -> V_9 ) ||
F_38 ( & V_6 -> V_9 ) || ! V_6 -> V_27 ) ) {
if ( ! F_34 ( V_6 ) ) {
V_6 -> V_35 |= V_41 ;
F_23 ( V_6 ) ;
goto V_30;
}
}
F_29 ( V_1 , V_6 ) ;
V_6 -> V_9 . V_3 -> V_25 ( & V_6 -> V_9 ) ;
do {
if ( F_30 ( ! V_6 -> V_27 ) ) {
F_24 ( V_6 ) ;
goto V_30;
}
if ( F_30 ( V_6 -> V_35 & V_41 ) ) {
if ( ! F_31 ( & V_6 -> V_9 ) &&
F_45 ( & V_6 -> V_9 ) )
F_25 ( V_6 ) ;
}
F_39 ( V_6 ) ;
} while ( ( V_6 -> V_35 & V_41 ) &&
! F_31 ( & V_6 -> V_9 ) );
V_30:
F_40 ( & V_6 -> V_29 ) ;
}
void F_46 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_47 ( V_6 ) ;
F_37 ( & V_6 -> V_29 ) ;
V_6 -> V_35 &= ~ ( V_37 | V_38 ) ;
if ( F_30 ( F_31 ( & V_6 -> V_9 ) ||
F_38 ( & V_6 -> V_9 ) || ! V_6 -> V_27 ) ) {
if ( ! F_34 ( V_6 ) ) {
V_6 -> V_35 |= V_41 ;
goto V_42;
}
}
F_29 ( V_1 , V_6 ) ;
do {
if ( F_30 ( ! V_6 -> V_27 ) )
goto V_42;
F_39 ( V_6 ) ;
} while ( ( V_6 -> V_35 & V_41 ) &&
! F_31 ( & V_6 -> V_9 ) );
V_42:
V_3 -> V_43 ( & V_6 -> V_9 ) ;
F_40 ( & V_6 -> V_29 ) ;
}
void
F_48 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_47 ( V_6 ) ;
F_29 ( V_1 , V_6 ) ;
if ( V_3 -> V_25 )
V_3 -> V_25 ( & V_6 -> V_9 ) ;
F_49 ( V_6 , V_6 -> V_27 ) ;
if ( V_3 -> V_43 )
V_3 -> V_43 ( & V_6 -> V_9 ) ;
}
void
F_50 ( unsigned int V_1 , T_2 V_45 , int V_46 ,
const char * V_47 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 ) ;
if ( ! V_6 )
return;
if ( ! V_45 ) {
V_45 = V_48 ;
} else {
if ( F_51 ( V_6 -> V_9 . V_3 == & V_8 ) )
goto V_40;
}
if ( V_45 == V_48 ) {
if ( V_6 -> V_9 . V_3 != & V_8 )
F_23 ( V_6 ) ;
F_16 ( V_6 ) ;
V_6 -> V_20 = 1 ;
}
V_6 -> V_49 = V_45 ;
V_6 -> V_47 = V_47 ;
if ( V_45 != V_48 && V_46 ) {
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_20 ( V_6 ) ;
}
V_40:
F_8 ( V_6 , V_4 ) ;
}
void
F_55 ( unsigned int V_1 , struct V_2 * V_3 ,
T_2 V_45 , const char * V_47 )
{
F_1 ( V_1 , V_3 ) ;
F_50 ( V_1 , V_45 , 0 , V_47 ) ;
}
void F_56 ( unsigned int V_1 , unsigned long V_50 , unsigned long V_51 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 ) ;
if ( ! V_6 )
return;
F_57 ( V_6 , V_50 , V_51 ) ;
F_15 ( & V_6 -> V_9 , V_52 | V_53 |
V_54 | V_55 | V_56 ) ;
if ( F_58 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_52 ) ;
if ( F_59 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_53 ) ;
if ( F_60 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_56 ) ;
if ( F_61 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_55 ) ;
F_17 ( & V_6 -> V_9 , F_62 ( V_6 ) ) ;
F_3 ( V_6 , V_4 ) ;
}
void F_63 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_64 (irq) {
V_6 = F_13 ( V_1 ) ;
if ( ! V_6 )
continue;
F_65 ( & V_6 -> V_29 , V_4 ) ;
V_3 = F_66 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_63 &&
( ! ( V_3 -> V_4 & V_57 ) ||
! F_31 ( & V_6 -> V_9 ) ) )
V_3 -> F_63 ( & V_6 -> V_9 ) ;
F_67 ( & V_6 -> V_29 , V_4 ) ;
}
}
void F_68 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_64 (irq) {
V_6 = F_13 ( V_1 ) ;
if ( ! V_6 )
continue;
F_65 ( & V_6 -> V_29 , V_4 ) ;
V_3 = F_66 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_68 &&
( ! ( V_3 -> V_4 & V_57 ) ||
! F_31 ( & V_6 -> V_9 ) ) )
V_3 -> F_68 ( & V_6 -> V_9 ) ;
F_67 ( & V_6 -> V_29 , V_4 ) ;
}
}
