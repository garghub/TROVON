static inline void F_1 ( int V_1 ) { }
struct V_2 * F_2 ( void )
{
return & V_3 ;
}
struct V_4 * F_3 ( void )
{
return V_5 ;
}
static void F_4 ( struct V_6 * V_7 )
{
if ( V_7 )
F_5 ( V_7 , 1 ) ;
}
static bool F_6 ( struct V_6 * V_8 ,
struct V_6 * V_9 )
{
if ( ( V_9 -> V_10 & V_11 ) ||
( V_9 -> V_10 & V_12 ) ||
( V_9 -> V_10 & V_13 ) )
return false ;
if ( V_3 . V_14 == V_15 &&
! ( V_9 -> V_10 & V_16 ) )
return false ;
return ! V_8 || V_9 -> V_17 > V_8 -> V_17 ;
}
void F_7 ( struct V_6 * V_18 )
{
struct V_6 * V_19 = V_3 . V_20 ;
if ( ! F_6 ( V_19 , V_18 ) )
return;
if ( ! F_8 ( V_18 -> V_21 ) )
return;
F_9 ( V_19 , V_18 ) ;
if ( V_19 )
V_19 -> V_22 = V_23 ;
V_3 . V_20 = V_18 ;
if ( ! F_10 ( V_5 ) )
F_4 ( V_18 ) ;
if ( V_18 -> V_10 & V_16 )
F_11 () ;
}
int F_12 ( struct V_6 * V_18 )
{
return ( V_18 && V_3 . V_20 == V_18 ) ;
}
int F_13 ( struct V_6 * V_18 , T_1 V_24 )
{
int V_25 = - V_26 ;
if ( F_12 ( V_18 ) ) {
F_14 ( & V_27 ) ;
V_25 = F_15 ( V_18 , V_24 ) ;
F_16 ( & V_27 ) ;
}
return V_25 ;
}
static void F_17 ( const struct V_4 * V_28 )
{
F_18 ( L_1 ) ;
}
static void F_19 ( struct V_6 * V_18 )
{
if ( ! V_18 -> V_29 )
V_18 -> V_29 = V_30 ;
if ( ! V_18 -> V_29 ) {
F_20 ( L_2 ,
V_18 -> V_31 ) ;
V_18 -> V_29 = F_17 ;
}
}
int F_21 ( struct V_6 * V_18 , int V_1 )
{
struct V_6 * V_7 = V_3 . V_20 ;
unsigned long V_32 ;
int V_25 ;
F_22 ( & V_27 , V_32 ) ;
if ( ! F_23 ( V_18 ) ) {
V_18 -> V_22 = V_33 ;
F_19 ( V_18 ) ;
F_24 ( V_1 , V_5 ) ;
if ( V_3 . V_14 == V_34 )
F_4 ( V_7 ) ;
else
F_25 ( V_7 ) ;
V_25 = 1 ;
} else {
if ( ! ( V_18 -> V_10 & V_13 ) )
F_26 ( V_1 , V_5 ) ;
else
F_19 ( V_18 ) ;
if ( ! F_27 ( V_1 , V_35 ) )
F_26 ( V_1 , V_5 ) ;
switch ( V_3 . V_14 ) {
case V_15 :
F_1 ( V_1 ) ;
V_25 = 0 ;
break;
case V_34 :
if ( F_10 ( V_5 ) && V_7 )
F_28 ( V_7 ) ;
V_25 = F_27 ( V_1 , V_5 ) ;
break;
default:
V_25 = 0 ;
break;
}
}
F_29 ( & V_27 , V_32 ) ;
return V_25 ;
}
int F_30 ( void )
{
struct V_2 * V_36 = F_31 ( & V_37 ) ;
struct V_6 * V_38 = V_36 -> V_20 ;
if ( ! V_38 )
return - V_26 ;
if ( ! V_38 -> V_22 )
return - V_39 ;
V_38 -> V_22 ( V_38 ) ;
return 0 ;
}
static void F_32 ( struct V_4 * V_28 )
{
int V_1 = F_33 () ;
struct V_2 * V_36 ;
if ( F_27 ( V_1 , V_28 ) ) {
F_26 ( V_1 , V_28 ) ;
V_36 = & F_34 ( V_37 , V_1 ) ;
V_36 -> V_20 -> V_22 ( V_36 -> V_20 ) ;
}
if ( ! F_10 ( V_28 ) ) {
V_36 = & F_34 ( V_37 , F_35 ( V_28 ) ) ;
V_36 -> V_20 -> V_29 ( V_28 ) ;
}
}
static void F_36 ( void )
{
F_37 ( V_40 , V_41 , V_5 ) ;
F_32 ( V_40 ) ;
}
static void F_38 ( struct V_6 * V_18 )
{
T_2 V_42 ;
F_14 ( & V_27 ) ;
F_36 () ;
if ( V_18 -> V_14 == V_43 )
goto V_44;
for ( V_42 = V_18 -> V_45 ; ; ) {
V_42 = F_39 ( V_42 , V_46 ) ;
if ( ! F_40 ( V_18 , V_42 , false ) )
goto V_44;
F_36 () ;
}
V_44:
F_16 ( & V_27 ) ;
}
static void F_41 ( unsigned long * V_47 )
{
struct V_6 * V_7 , * V_18 ;
struct V_2 * V_36 ;
unsigned long V_32 ;
int V_1 , V_48 ;
F_22 ( & V_27 , V_32 ) ;
V_1 = F_33 () ;
V_36 = & F_34 ( V_37 , V_1 ) ;
V_18 = V_36 -> V_20 ;
V_7 = V_3 . V_20 ;
if ( ! V_18 || ! ( V_18 -> V_10 & V_13 ) )
goto V_49;
if ( ! F_23 ( V_18 ) )
goto V_49;
V_48 = F_10 ( V_5 ) ;
switch ( * V_47 ) {
case V_50 :
case V_51 :
F_24 ( V_1 , V_35 ) ;
if ( ! F_42 ( V_1 , V_5 ) ) {
if ( V_3 . V_14 ==
V_34 )
F_28 ( V_18 ) ;
}
if ( * V_47 == V_51 )
V_52 = 1 ;
break;
case V_53 :
if ( V_52 )
break;
F_26 ( V_1 , V_35 ) ;
if ( ! F_23 ( V_18 ) )
break;
if ( F_43 ( V_1 , V_5 ) ) {
if ( V_3 . V_14 ==
V_34 )
F_5 ( V_18 , 0 ) ;
}
break;
}
if ( F_10 ( V_5 ) ) {
if ( ! V_48 )
F_28 ( V_7 ) ;
} else if ( V_48 ) {
if ( V_3 . V_14 == V_34 )
F_4 ( V_7 ) ;
else
F_25 ( V_7 ) ;
}
V_49:
F_29 ( & V_27 , V_32 ) ;
}
void F_44 ( unsigned long V_47 , int * V_54 )
{
if ( ! F_27 ( * V_54 , V_41 ) )
F_45 ( V_55 L_3
L_4 , * V_54 ) ;
else
F_41 ( & V_47 ) ;
}
void F_46 ( struct V_6 * V_18 , int V_29 )
{
if ( ! V_29 )
V_18 -> V_22 = V_33 ;
else
V_18 -> V_22 = F_38 ;
}
void F_47 ( unsigned int * V_56 )
{
struct V_6 * V_7 ;
unsigned long V_32 ;
unsigned int V_1 = * V_56 ;
F_22 ( & V_27 , V_32 ) ;
V_7 = V_3 . V_20 ;
F_26 ( V_1 , V_5 ) ;
F_26 ( V_1 , V_35 ) ;
if ( V_3 . V_14 == V_34 ) {
if ( V_7 && F_10 ( V_5 ) )
F_28 ( V_7 ) ;
}
F_29 ( & V_27 , V_32 ) ;
}
void F_48 ( void )
{
struct V_6 * V_7 ;
unsigned long V_32 ;
F_22 ( & V_27 , V_32 ) ;
V_7 = V_3 . V_20 ;
if ( V_7 )
F_28 ( V_7 ) ;
F_29 ( & V_27 , V_32 ) ;
}
int F_49 ( void )
{
struct V_6 * V_7 ;
unsigned long V_32 ;
int V_29 = 0 ;
F_22 ( & V_27 , V_32 ) ;
V_7 = V_3 . V_20 ;
if ( V_7 ) {
F_50 ( V_7 , V_57 ) ;
switch ( V_3 . V_14 ) {
case V_34 :
if ( ! F_10 ( V_5 ) )
F_4 ( V_7 ) ;
V_29 = F_27 ( F_33 () ,
V_5 ) ;
break;
case V_15 :
if ( ! F_10 ( V_5 ) )
V_29 = F_51 ( V_7 ) ;
break;
}
}
F_29 ( & V_27 , V_32 ) ;
return V_29 ;
}
struct V_4 * F_52 ( void )
{
return V_58 ;
}
int F_53 ( void )
{
return F_27 ( F_33 () , V_59 ) ;
}
static void F_54 ( struct V_6 * V_7 ,
const struct V_4 * V_4 )
{
if ( ! ( V_7 -> V_10 & V_60 ) )
return;
if ( F_55 ( V_7 -> V_4 , V_4 ) )
return;
V_7 -> V_4 = V_4 ;
F_56 ( V_7 -> V_61 , V_7 -> V_4 ) ;
}
static int F_57 ( struct V_6 * V_7 , int V_1 ,
T_2 V_62 , int V_63 )
{
int V_25 ;
if ( V_7 -> V_14 != V_64 )
F_50 ( V_7 , V_64 ) ;
V_25 = F_40 ( V_7 , V_62 , V_63 ) ;
if ( ! V_25 )
F_54 ( V_7 , F_58 ( V_1 ) ) ;
return V_25 ;
}
int F_51 ( struct V_6 * V_7 )
{
F_50 ( V_7 , V_64 ) ;
return 0 ;
}
void F_59 ( void )
{
if ( F_27 ( F_33 () , V_58 ) ) {
struct V_2 * V_36 = F_31 ( & V_37 ) ;
if ( V_36 -> V_14 == V_15 ) {
F_50 ( V_36 -> V_20 ,
V_64 ) ;
}
}
}
static void F_60 ( struct V_6 * V_18 )
{
struct V_2 * V_36 ;
T_2 V_65 , V_45 ;
int V_1 , V_66 = 0 ;
F_14 ( & V_27 ) ;
V_67:
V_18 -> V_45 . V_68 = V_69 ;
V_45 . V_68 = V_69 ;
F_61 ( V_40 ) ;
V_65 = F_62 () ;
F_63 (cpu, tick_broadcast_oneshot_mask) {
V_36 = & F_34 ( V_37 , V_1 ) ;
if ( V_36 -> V_20 -> V_45 . V_68 <= V_65 . V_68 ) {
F_24 ( V_1 , V_40 ) ;
F_24 ( V_1 , V_70 ) ;
} else if ( V_36 -> V_20 -> V_45 . V_68 < V_45 . V_68 ) {
V_45 . V_68 = V_36 -> V_20 -> V_45 . V_68 ;
V_66 = V_1 ;
}
}
F_26 ( F_33 () , V_70 ) ;
F_64 ( V_40 , V_40 , V_59 ) ;
F_61 ( V_59 ) ;
if ( F_65 ( ! F_66 ( V_40 , V_41 ) ) )
F_37 ( V_40 , V_40 , V_41 ) ;
F_32 ( V_40 ) ;
if ( V_45 . V_68 != V_69 ) {
if ( F_57 ( V_18 , V_66 , V_45 , 0 ) )
goto V_67;
}
F_16 ( & V_27 ) ;
}
static int F_67 ( struct V_6 * V_7 , int V_1 )
{
if ( ! ( V_7 -> V_10 & V_71 ) )
return 0 ;
if ( V_7 -> V_45 . V_68 == V_69 )
return 0 ;
return V_7 -> V_72 == V_1 ? - V_73 : 0 ;
}
static void F_68 ( struct V_6 * V_7 ,
struct V_6 * V_18 )
{
if ( V_7 -> V_10 & V_71 ) {
if ( F_67 ( V_7 , F_33 () ) )
return;
if ( V_18 -> V_45 . V_68 < V_7 -> V_45 . V_68 )
return;
}
F_50 ( V_18 , V_74 ) ;
}
static void F_69 ( int V_75 )
{
struct V_6 * V_7 = V_3 . V_20 ;
if ( ! V_7 || ! F_67 ( V_7 , V_75 ) )
return;
F_40 ( V_7 , V_7 -> V_45 , 1 ) ;
}
int F_70 ( unsigned long V_47 )
{
struct V_6 * V_7 , * V_18 ;
struct V_2 * V_36 ;
unsigned long V_32 ;
T_2 V_65 ;
int V_1 , V_25 = 0 ;
if ( V_3 . V_14 == V_34 )
return 0 ;
V_1 = F_33 () ;
V_36 = & F_34 ( V_37 , V_1 ) ;
V_18 = V_36 -> V_20 ;
if ( ! ( V_18 -> V_10 & V_13 ) )
return 0 ;
V_7 = V_3 . V_20 ;
F_22 ( & V_27 , V_32 ) ;
if ( V_47 == V_76 ) {
if ( ! F_42 ( V_1 , V_58 ) ) {
F_65 ( F_27 ( V_1 , V_70 ) ) ;
F_68 ( V_7 , V_18 ) ;
if ( ! F_27 ( V_1 , V_59 ) &&
V_18 -> V_45 . V_68 < V_7 -> V_45 . V_68 )
F_57 ( V_7 , V_1 , V_18 -> V_45 , 1 ) ;
}
V_25 = F_67 ( V_7 , V_1 ) ;
if ( V_25 )
F_26 ( V_1 , V_58 ) ;
} else {
if ( F_43 ( V_1 , V_58 ) ) {
F_50 ( V_18 , V_64 ) ;
if ( F_43 ( V_1 ,
V_70 ) )
goto V_49;
if ( V_18 -> V_45 . V_68 == V_69 )
goto V_49;
V_65 = F_62 () ;
if ( V_18 -> V_45 . V_68 <= V_65 . V_68 ) {
F_24 ( V_1 , V_59 ) ;
goto V_49;
}
F_71 ( V_18 -> V_45 , 1 ) ;
}
}
V_49:
F_29 ( & V_27 , V_32 ) ;
return V_25 ;
}
static void F_1 ( int V_1 )
{
F_26 ( V_1 , V_58 ) ;
F_26 ( V_1 , V_70 ) ;
}
static void F_72 ( struct V_4 * V_28 ,
T_2 V_62 )
{
struct V_2 * V_36 ;
int V_1 ;
F_63 (cpu, mask) {
V_36 = & F_34 ( V_37 , V_1 ) ;
if ( V_36 -> V_20 )
V_36 -> V_20 -> V_45 = V_62 ;
}
}
void F_25 ( struct V_6 * V_7 )
{
int V_1 = F_33 () ;
if ( V_7 -> V_22 != F_60 ) {
int V_77 = V_7 -> V_14 == V_43 ;
V_7 -> V_22 = F_60 ;
F_73 ( V_40 , V_5 ) ;
F_26 ( V_1 , V_40 ) ;
F_64 ( V_58 ,
V_58 , V_40 ) ;
if ( V_77 && ! F_10 ( V_40 ) ) {
F_50 ( V_7 , V_64 ) ;
F_72 ( V_40 ,
V_78 ) ;
F_57 ( V_7 , V_1 , V_78 , 1 ) ;
} else
V_7 -> V_45 . V_68 = V_69 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_74 ( void )
{
struct V_6 * V_7 ;
unsigned long V_32 ;
F_22 ( & V_27 , V_32 ) ;
V_3 . V_14 = V_15 ;
V_7 = V_3 . V_20 ;
if ( V_7 )
F_25 ( V_7 ) ;
F_29 ( & V_27 , V_32 ) ;
}
void F_75 ( unsigned int * V_56 )
{
unsigned long V_32 ;
unsigned int V_1 = * V_56 ;
F_22 ( & V_27 , V_32 ) ;
F_26 ( V_1 , V_58 ) ;
F_26 ( V_1 , V_70 ) ;
F_26 ( V_1 , V_59 ) ;
F_69 ( V_1 ) ;
F_29 ( & V_27 , V_32 ) ;
}
int F_76 ( void )
{
return V_3 . V_14 == V_15 ;
}
bool F_77 ( void )
{
struct V_6 * V_7 = V_3 . V_20 ;
return V_7 ? V_7 -> V_10 & V_16 : false ;
}
void T_3 F_78 ( void )
{
F_79 ( & V_5 , V_79 ) ;
F_79 ( & V_35 , V_79 ) ;
F_79 ( & V_40 , V_79 ) ;
#ifdef F_80
F_79 ( & V_58 , V_79 ) ;
F_79 ( & V_70 , V_79 ) ;
F_79 ( & V_59 , V_79 ) ;
#endif
}
