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
if ( type != V_13 )
V_11 = F_7 ( V_6 , V_1 , type ) ;
F_8 ( V_6 , V_4 ) ;
return V_11 ;
}
int F_9 ( unsigned int V_1 , void * V_14 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_15 = V_14 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_10 ( unsigned int V_1 , struct V_16 * V_17 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , V_10 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_16 = V_17 ;
if ( V_17 )
V_17 -> V_1 = V_1 ;
F_3 ( V_6 , V_4 ) ;
return 0 ;
}
int F_11 ( unsigned int V_1 , void * V_14 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_9 . V_18 = V_14 ;
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
F_15 ( & V_6 -> V_9 , V_19 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
F_17 ( & V_6 -> V_9 , V_19 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_9 , V_20 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
F_17 ( & V_6 -> V_9 , V_20 ) ;
}
int F_20 ( struct V_5 * V_6 )
{
F_14 ( V_6 ) ;
V_6 -> V_21 = 0 ;
if ( V_6 -> V_9 . V_3 -> F_20 ) {
int V_11 = V_6 -> V_9 . V_3 -> F_20 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
return V_11 ;
}
F_21 ( V_6 ) ;
return 0 ;
}
void F_22 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
V_6 -> V_21 = 1 ;
if ( V_6 -> V_9 . V_3 -> F_22 )
V_6 -> V_9 . V_3 -> F_22 ( & V_6 -> V_9 ) ;
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
void F_23 ( struct V_5 * V_6 , unsigned int V_25 )
{
if ( V_6 -> V_9 . V_3 -> F_21 )
V_6 -> V_9 . V_3 -> F_21 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
F_24 ( V_25 , V_6 -> V_26 ) ;
}
void F_25 ( struct V_5 * V_6 , unsigned int V_25 )
{
if ( V_6 -> V_9 . V_3 -> V_22 )
V_6 -> V_9 . V_3 -> V_22 ( & V_6 -> V_9 ) ;
else
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_26 ( V_25 , V_6 -> V_26 ) ;
}
static inline void F_27 ( struct V_5 * V_6 )
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
void F_28 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_23 ) {
V_6 -> V_9 . V_3 -> V_23 ( & V_6 -> V_9 ) ;
F_19 ( V_6 ) ;
}
}
void F_29 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 . V_3 -> V_24 ) {
V_6 -> V_9 . V_3 -> V_24 ( & V_6 -> V_9 ) ;
F_18 ( V_6 ) ;
}
}
void F_30 ( unsigned int V_1 )
{
struct V_5 * V_6 = F_13 ( V_1 ) ;
struct V_29 * V_30 ;
T_1 V_31 ;
F_31 () ;
F_32 ( & V_6 -> V_32 ) ;
F_33 ( V_1 , V_6 ) ;
V_30 = V_6 -> V_30 ;
if ( F_34 ( ! V_30 || F_35 ( & V_6 -> V_9 ) ) )
goto V_33;
F_17 ( & V_6 -> V_9 , V_34 ) ;
F_36 ( & V_6 -> V_32 ) ;
V_31 = V_30 -> V_35 ( V_30 -> V_1 , V_30 -> V_36 ) ;
if ( ! V_37 )
F_37 ( V_1 , V_6 , V_31 ) ;
F_32 ( & V_6 -> V_32 ) ;
F_15 ( & V_6 -> V_9 , V_34 ) ;
V_33:
F_36 ( & V_6 -> V_32 ) ;
}
static bool F_38 ( struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_38 & V_39 ) )
return false ;
return F_39 ( V_6 ) ;
}
void
F_40 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_41 ( & V_6 -> V_32 ) ;
if ( F_34 ( F_42 ( & V_6 -> V_9 ) ) )
if ( ! F_38 ( V_6 ) )
goto V_33;
V_6 -> V_38 &= ~ ( V_40 | V_41 ) ;
F_33 ( V_1 , V_6 ) ;
if ( F_34 ( ! V_6 -> V_30 || F_35 ( & V_6 -> V_9 ) ) )
goto V_33;
F_43 ( V_6 ) ;
V_33:
F_44 ( & V_6 -> V_32 ) ;
}
void
F_45 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_41 ( & V_6 -> V_32 ) ;
F_27 ( V_6 ) ;
if ( F_34 ( F_42 ( & V_6 -> V_9 ) ) )
if ( ! F_38 ( V_6 ) )
goto V_33;
V_6 -> V_38 &= ~ ( V_40 | V_41 ) ;
F_33 ( V_1 , V_6 ) ;
if ( F_34 ( ! V_6 -> V_30 || F_35 ( & V_6 -> V_9 ) ) )
goto V_33;
F_43 ( V_6 ) ;
if ( ! F_35 ( & V_6 -> V_9 ) && ! ( V_6 -> V_38 & V_42 ) )
F_29 ( V_6 ) ;
V_33:
F_44 ( & V_6 -> V_32 ) ;
}
static inline void F_46 ( struct V_5 * V_6 )
{
if ( V_6 -> F_46 )
V_6 -> F_46 ( & V_6 -> V_9 ) ;
}
static inline void F_46 ( struct V_5 * V_6 ) { }
void
F_47 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_41 ( & V_6 -> V_32 ) ;
if ( F_34 ( F_42 ( & V_6 -> V_9 ) ) )
if ( ! F_38 ( V_6 ) )
goto V_43;
V_6 -> V_38 &= ~ ( V_40 | V_41 ) ;
F_33 ( V_1 , V_6 ) ;
if ( F_34 ( ! V_6 -> V_30 || F_35 ( & V_6 -> V_9 ) ) ) {
V_6 -> V_38 |= V_44 ;
F_28 ( V_6 ) ;
goto V_43;
}
if ( V_6 -> V_38 & V_42 )
F_28 ( V_6 ) ;
F_46 ( V_6 ) ;
F_43 ( V_6 ) ;
V_45:
V_6 -> V_9 . V_3 -> V_46 ( & V_6 -> V_9 ) ;
V_33:
F_44 ( & V_6 -> V_32 ) ;
return;
V_43:
if ( ! ( V_6 -> V_9 . V_3 -> V_4 & V_47 ) )
goto V_45;
goto V_33;
}
void
F_48 ( unsigned int V_1 , struct V_5 * V_6 )
{
F_41 ( & V_6 -> V_32 ) ;
V_6 -> V_38 &= ~ ( V_40 | V_41 ) ;
if ( F_34 ( F_35 ( & V_6 -> V_9 ) ||
F_42 ( & V_6 -> V_9 ) || ! V_6 -> V_30 ) ) {
if ( ! F_38 ( V_6 ) ) {
V_6 -> V_38 |= V_44 ;
F_27 ( V_6 ) ;
goto V_33;
}
}
F_33 ( V_1 , V_6 ) ;
V_6 -> V_9 . V_3 -> V_28 ( & V_6 -> V_9 ) ;
do {
if ( F_34 ( ! V_6 -> V_30 ) ) {
F_28 ( V_6 ) ;
goto V_33;
}
if ( F_34 ( V_6 -> V_38 & V_44 ) ) {
if ( ! F_35 ( & V_6 -> V_9 ) &&
F_49 ( & V_6 -> V_9 ) )
F_29 ( V_6 ) ;
}
F_43 ( V_6 ) ;
} while ( ( V_6 -> V_38 & V_44 ) &&
! F_35 ( & V_6 -> V_9 ) );
V_33:
F_44 ( & V_6 -> V_32 ) ;
}
void F_50 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_51 ( V_6 ) ;
F_41 ( & V_6 -> V_32 ) ;
V_6 -> V_38 &= ~ ( V_40 | V_41 ) ;
if ( F_34 ( F_35 ( & V_6 -> V_9 ) ||
F_42 ( & V_6 -> V_9 ) || ! V_6 -> V_30 ) ) {
if ( ! F_38 ( V_6 ) ) {
V_6 -> V_38 |= V_44 ;
goto V_45;
}
}
F_33 ( V_1 , V_6 ) ;
do {
if ( F_34 ( ! V_6 -> V_30 ) )
goto V_45;
F_43 ( V_6 ) ;
} while ( ( V_6 -> V_38 & V_44 ) &&
! F_35 ( & V_6 -> V_9 ) );
V_45:
V_3 -> V_46 ( & V_6 -> V_9 ) ;
F_44 ( & V_6 -> V_32 ) ;
}
void
F_52 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_51 ( V_6 ) ;
F_33 ( V_1 , V_6 ) ;
if ( V_3 -> V_28 )
V_3 -> V_28 ( & V_6 -> V_9 ) ;
F_53 ( V_6 , V_6 -> V_30 ) ;
if ( V_3 -> V_46 )
V_3 -> V_46 ( & V_6 -> V_9 ) ;
}
void F_54 ( unsigned int V_1 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_51 ( V_6 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
void * V_36 = F_55 ( V_30 -> V_48 ) ;
T_1 V_49 ;
F_33 ( V_1 , V_6 ) ;
if ( V_3 -> V_28 )
V_3 -> V_28 ( & V_6 -> V_9 ) ;
F_56 ( V_1 , V_30 ) ;
V_49 = V_30 -> V_50 ( V_1 , V_36 ) ;
F_57 ( V_1 , V_30 , V_49 ) ;
if ( V_3 -> V_46 )
V_3 -> V_46 ( & V_6 -> V_9 ) ;
}
void
F_58 ( unsigned int V_1 , T_2 V_51 , int V_52 ,
const char * V_53 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_6 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
if ( ! V_51 ) {
V_51 = V_54 ;
} else {
if ( F_59 ( V_6 -> V_9 . V_3 == & V_8 ) )
goto V_43;
}
if ( V_51 == V_54 ) {
if ( V_6 -> V_9 . V_3 != & V_8 )
F_27 ( V_6 ) ;
F_16 ( V_6 ) ;
V_6 -> V_21 = 1 ;
}
V_6 -> V_55 = V_51 ;
V_6 -> V_53 = V_53 ;
if ( V_51 != V_54 && V_52 ) {
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
F_62 ( V_6 ) ;
F_20 ( V_6 ) ;
}
V_43:
F_8 ( V_6 , V_4 ) ;
}
void
F_63 ( unsigned int V_1 , struct V_2 * V_3 ,
T_2 V_51 , const char * V_53 )
{
F_1 ( V_1 , V_3 ) ;
F_58 ( V_1 , V_51 , 0 , V_53 ) ;
}
void F_64 ( unsigned int V_1 , unsigned long V_56 , unsigned long V_57 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_1 , & V_4 , 0 ) ;
if ( ! V_6 )
return;
F_65 ( V_6 , V_56 , V_57 ) ;
F_15 ( & V_6 -> V_9 , V_58 | V_59 |
V_60 | V_61 | V_62 ) ;
if ( F_66 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_58 ) ;
if ( F_67 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_59 ) ;
if ( F_68 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_62 ) ;
if ( F_69 ( V_6 ) )
F_17 ( & V_6 -> V_9 , V_61 ) ;
F_17 ( & V_6 -> V_9 , F_70 ( V_6 ) ) ;
F_3 ( V_6 , V_4 ) ;
}
void F_71 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_72 (irq) {
V_6 = F_13 ( V_1 ) ;
if ( ! V_6 )
continue;
F_73 ( & V_6 -> V_32 , V_4 ) ;
V_3 = F_74 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_71 &&
( ! ( V_3 -> V_4 & V_63 ) ||
! F_35 ( & V_6 -> V_9 ) ) )
V_3 -> F_71 ( & V_6 -> V_9 ) ;
F_75 ( & V_6 -> V_32 , V_4 ) ;
}
}
void F_76 ( void )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
unsigned int V_1 ;
F_72 (irq) {
V_6 = F_13 ( V_1 ) ;
if ( ! V_6 )
continue;
F_73 ( & V_6 -> V_32 , V_4 ) ;
V_3 = F_74 ( & V_6 -> V_9 ) ;
if ( V_3 && V_3 -> F_76 &&
( ! ( V_3 -> V_4 & V_63 ) ||
! F_35 ( & V_6 -> V_9 ) ) )
V_3 -> F_76 ( & V_6 -> V_9 ) ;
F_75 ( & V_6 -> V_32 , V_4 ) ;
}
}
