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
( V_9 -> V_10 & V_12 ) )
return false ;
if ( V_3 . V_13 == V_14 &&
! ( V_9 -> V_10 & V_15 ) )
return false ;
return ! V_8 || V_9 -> V_16 > V_8 -> V_16 ;
}
void F_7 ( struct V_6 * V_17 )
{
struct V_6 * V_18 = V_3 . V_19 ;
if ( ! F_6 ( V_18 , V_17 ) )
return;
if ( ! F_8 ( V_17 -> V_20 ) )
return;
F_9 ( V_18 , V_17 ) ;
if ( V_18 )
V_18 -> V_21 = V_22 ;
V_3 . V_19 = V_17 ;
if ( ! F_10 ( V_5 ) )
F_4 ( V_17 ) ;
if ( V_17 -> V_10 & V_15 )
F_11 () ;
}
int F_12 ( struct V_6 * V_17 )
{
return ( V_17 && V_3 . V_19 == V_17 ) ;
}
static void F_13 ( const struct V_4 * V_23 )
{
F_14 ( L_1 ) ;
}
static void F_15 ( struct V_6 * V_17 )
{
if ( ! V_17 -> V_24 )
V_17 -> V_24 = V_25 ;
if ( ! V_17 -> V_24 ) {
F_16 ( L_2 ,
V_17 -> V_26 ) ;
V_17 -> V_24 = F_13 ;
}
}
int F_17 ( struct V_6 * V_17 , int V_1 )
{
struct V_6 * V_7 = V_3 . V_19 ;
unsigned long V_27 ;
int V_28 ;
F_18 ( & V_29 , V_27 ) ;
if ( ! F_19 ( V_17 ) ) {
V_17 -> V_21 = V_30 ;
F_15 ( V_17 ) ;
F_20 ( V_1 , V_5 ) ;
if ( V_3 . V_13 == V_31 )
F_4 ( V_7 ) ;
else
F_21 ( V_7 ) ;
V_28 = 1 ;
} else {
if ( ! ( V_17 -> V_10 & V_12 ) )
F_22 ( V_1 , V_5 ) ;
else
F_15 ( V_17 ) ;
if ( ! F_23 ( V_1 , V_32 ) )
F_22 ( V_1 , V_5 ) ;
switch ( V_3 . V_13 ) {
case V_14 :
F_1 ( V_1 ) ;
V_28 = 0 ;
break;
case V_31 :
if ( F_10 ( V_5 ) && V_7 )
F_24 ( V_7 ) ;
V_28 = F_23 ( V_1 , V_5 ) ;
break;
default:
V_28 = 0 ;
break;
}
}
F_25 ( & V_29 , V_27 ) ;
return V_28 ;
}
int F_26 ( void )
{
struct V_2 * V_33 = F_27 ( & V_34 ) ;
struct V_6 * V_35 = V_33 -> V_19 ;
if ( ! V_35 )
return - V_36 ;
if ( ! V_35 -> V_21 )
return - V_37 ;
V_35 -> V_21 ( V_35 ) ;
return 0 ;
}
static void F_28 ( struct V_4 * V_23 )
{
int V_1 = F_29 () ;
struct V_2 * V_33 ;
if ( F_23 ( V_1 , V_23 ) ) {
F_22 ( V_1 , V_23 ) ;
V_33 = & F_30 ( V_34 , V_1 ) ;
V_33 -> V_19 -> V_21 ( V_33 -> V_19 ) ;
}
if ( ! F_10 ( V_23 ) ) {
V_33 = & F_30 ( V_34 , F_31 ( V_23 ) ) ;
V_33 -> V_19 -> V_24 ( V_23 ) ;
}
}
static void F_32 ( void )
{
F_33 ( & V_29 ) ;
F_34 ( V_38 , V_39 , V_5 ) ;
F_28 ( V_38 ) ;
F_35 ( & V_29 ) ;
}
static void F_36 ( struct V_6 * V_17 )
{
T_1 V_40 ;
F_32 () ;
if ( V_17 -> V_13 == V_41 )
return;
for ( V_40 = V_17 -> V_42 ; ; ) {
V_40 = F_37 ( V_40 , V_43 ) ;
if ( ! F_38 ( V_17 , V_40 , false ) )
return;
F_32 () ;
}
}
static void F_39 ( unsigned long * V_44 )
{
struct V_6 * V_7 , * V_17 ;
struct V_2 * V_33 ;
unsigned long V_27 ;
int V_1 , V_45 ;
F_18 ( & V_29 , V_27 ) ;
V_1 = F_29 () ;
V_33 = & F_30 ( V_34 , V_1 ) ;
V_17 = V_33 -> V_19 ;
V_7 = V_3 . V_19 ;
if ( ! V_17 || ! ( V_17 -> V_10 & V_12 ) )
goto V_46;
if ( ! F_19 ( V_17 ) )
goto V_46;
V_45 = F_10 ( V_5 ) ;
switch ( * V_44 ) {
case V_47 :
case V_48 :
F_20 ( V_1 , V_32 ) ;
if ( ! F_40 ( V_1 , V_5 ) ) {
if ( V_3 . V_13 ==
V_31 )
F_24 ( V_17 ) ;
}
if ( * V_44 == V_48 )
V_49 = 1 ;
break;
case V_50 :
if ( V_49 )
break;
F_22 ( V_1 , V_32 ) ;
if ( ! F_19 ( V_17 ) )
break;
if ( F_41 ( V_1 , V_5 ) ) {
if ( V_3 . V_13 ==
V_31 )
F_5 ( V_17 , 0 ) ;
}
break;
}
if ( F_10 ( V_5 ) ) {
if ( ! V_45 )
F_24 ( V_7 ) ;
} else if ( V_45 ) {
if ( V_3 . V_13 == V_31 )
F_4 ( V_7 ) ;
else
F_21 ( V_7 ) ;
}
V_46:
F_25 ( & V_29 , V_27 ) ;
}
void F_42 ( unsigned long V_44 , int * V_51 )
{
if ( ! F_23 ( * V_51 , V_39 ) )
F_43 ( V_52 L_3
L_4 , * V_51 ) ;
else
F_39 ( & V_44 ) ;
}
void F_44 ( struct V_6 * V_17 , int V_24 )
{
if ( ! V_24 )
V_17 -> V_21 = V_30 ;
else
V_17 -> V_21 = F_36 ;
}
void F_45 ( unsigned int * V_53 )
{
struct V_6 * V_7 ;
unsigned long V_27 ;
unsigned int V_1 = * V_53 ;
F_18 ( & V_29 , V_27 ) ;
V_7 = V_3 . V_19 ;
F_22 ( V_1 , V_5 ) ;
F_22 ( V_1 , V_32 ) ;
if ( V_3 . V_13 == V_31 ) {
if ( V_7 && F_10 ( V_5 ) )
F_24 ( V_7 ) ;
}
F_25 ( & V_29 , V_27 ) ;
}
void F_46 ( void )
{
struct V_6 * V_7 ;
unsigned long V_27 ;
F_18 ( & V_29 , V_27 ) ;
V_7 = V_3 . V_19 ;
if ( V_7 )
F_24 ( V_7 ) ;
F_25 ( & V_29 , V_27 ) ;
}
int F_47 ( void )
{
struct V_6 * V_7 ;
unsigned long V_27 ;
int V_24 = 0 ;
F_18 ( & V_29 , V_27 ) ;
V_7 = V_3 . V_19 ;
if ( V_7 ) {
F_48 ( V_7 , V_54 ) ;
switch ( V_3 . V_13 ) {
case V_31 :
if ( ! F_10 ( V_5 ) )
F_4 ( V_7 ) ;
V_24 = F_23 ( F_29 () ,
V_5 ) ;
break;
case V_14 :
if ( ! F_10 ( V_5 ) )
V_24 = F_49 ( V_7 ) ;
break;
}
}
F_25 ( & V_29 , V_27 ) ;
return V_24 ;
}
struct V_4 * F_50 ( void )
{
return V_55 ;
}
int F_51 ( void )
{
return F_23 ( F_29 () , V_56 ) ;
}
static void F_52 ( struct V_6 * V_7 ,
const struct V_4 * V_4 )
{
if ( ! ( V_7 -> V_10 & V_57 ) )
return;
if ( F_53 ( V_7 -> V_4 , V_4 ) )
return;
V_7 -> V_4 = V_4 ;
F_54 ( V_7 -> V_58 , V_7 -> V_4 ) ;
}
static int F_55 ( struct V_6 * V_7 , int V_1 ,
T_1 V_59 , int V_60 )
{
int V_28 ;
if ( V_7 -> V_13 != V_61 )
F_48 ( V_7 , V_61 ) ;
V_28 = F_38 ( V_7 , V_59 , V_60 ) ;
if ( ! V_28 )
F_52 ( V_7 , F_56 ( V_1 ) ) ;
return V_28 ;
}
int F_49 ( struct V_6 * V_7 )
{
F_48 ( V_7 , V_61 ) ;
return 0 ;
}
void F_57 ( int V_1 )
{
if ( F_23 ( V_1 , V_55 ) ) {
struct V_2 * V_33 = & F_30 ( V_34 , V_1 ) ;
if ( V_33 -> V_13 == V_14 ) {
F_48 ( V_33 -> V_19 ,
V_61 ) ;
}
}
}
static void F_58 ( struct V_6 * V_17 )
{
struct V_2 * V_33 ;
T_1 V_62 , V_42 ;
int V_1 , V_63 = 0 ;
F_33 ( & V_29 ) ;
V_64:
V_17 -> V_42 . V_65 = V_66 ;
V_42 . V_65 = V_66 ;
F_59 ( V_38 ) ;
V_62 = F_60 () ;
F_61 (cpu, tick_broadcast_oneshot_mask) {
V_33 = & F_30 ( V_34 , V_1 ) ;
if ( V_33 -> V_19 -> V_42 . V_65 <= V_62 . V_65 ) {
F_20 ( V_1 , V_38 ) ;
F_20 ( V_1 , V_67 ) ;
} else if ( V_33 -> V_19 -> V_42 . V_65 < V_42 . V_65 ) {
V_42 . V_65 = V_33 -> V_19 -> V_42 . V_65 ;
V_63 = V_1 ;
}
}
F_22 ( F_29 () , V_67 ) ;
F_62 ( V_38 , V_38 , V_56 ) ;
F_59 ( V_56 ) ;
if ( F_63 ( ! F_64 ( V_38 , V_39 ) ) )
F_34 ( V_38 , V_38 , V_39 ) ;
F_28 ( V_38 ) ;
if ( V_42 . V_65 != V_66 ) {
if ( F_55 ( V_17 , V_63 , V_42 , 0 ) )
goto V_64;
}
F_35 ( & V_29 ) ;
}
void F_65 ( unsigned long V_44 )
{
struct V_6 * V_7 , * V_17 ;
struct V_2 * V_33 ;
unsigned long V_27 ;
T_1 V_62 ;
int V_1 ;
if ( V_3 . V_13 == V_31 )
return;
V_1 = F_29 () ;
V_33 = & F_30 ( V_34 , V_1 ) ;
V_17 = V_33 -> V_19 ;
if ( ! ( V_17 -> V_10 & V_12 ) )
return;
V_7 = V_3 . V_19 ;
F_18 ( & V_29 , V_27 ) ;
if ( V_44 == V_68 ) {
if ( ! F_40 ( V_1 , V_55 ) ) {
F_63 ( F_23 ( V_1 , V_67 ) ) ;
F_48 ( V_17 , V_69 ) ;
if ( ! F_23 ( V_1 , V_56 ) &&
V_17 -> V_42 . V_65 < V_7 -> V_42 . V_65 )
F_55 ( V_7 , V_1 , V_17 -> V_42 , 1 ) ;
}
} else {
if ( F_41 ( V_1 , V_55 ) ) {
F_48 ( V_17 , V_61 ) ;
if ( F_41 ( V_1 ,
V_67 ) )
goto V_46;
if ( V_17 -> V_42 . V_65 == V_66 )
goto V_46;
V_62 = F_60 () ;
if ( V_17 -> V_42 . V_65 <= V_62 . V_65 ) {
F_20 ( V_1 , V_56 ) ;
goto V_46;
}
F_66 ( V_17 -> V_42 , 1 ) ;
}
}
V_46:
F_25 ( & V_29 , V_27 ) ;
}
static void F_1 ( int V_1 )
{
F_22 ( V_1 , V_55 ) ;
}
static void F_67 ( struct V_4 * V_23 ,
T_1 V_59 )
{
struct V_2 * V_33 ;
int V_1 ;
F_61 (cpu, mask) {
V_33 = & F_30 ( V_34 , V_1 ) ;
if ( V_33 -> V_19 )
V_33 -> V_19 -> V_42 = V_59 ;
}
}
void F_21 ( struct V_6 * V_7 )
{
int V_1 = F_29 () ;
if ( V_7 -> V_21 != F_58 ) {
int V_70 = V_7 -> V_13 == V_41 ;
V_7 -> V_21 = F_58 ;
F_68 ( V_38 , V_5 ) ;
F_22 ( V_1 , V_38 ) ;
F_62 ( V_55 ,
V_55 , V_38 ) ;
if ( V_70 && ! F_10 ( V_38 ) ) {
F_48 ( V_7 , V_61 ) ;
F_67 ( V_38 ,
V_71 ) ;
F_55 ( V_7 , V_1 , V_71 , 1 ) ;
} else
V_7 -> V_42 . V_65 = V_66 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_69 ( void )
{
struct V_6 * V_7 ;
unsigned long V_27 ;
F_18 ( & V_29 , V_27 ) ;
V_3 . V_13 = V_14 ;
V_7 = V_3 . V_19 ;
if ( V_7 )
F_21 ( V_7 ) ;
F_25 ( & V_29 , V_27 ) ;
}
void F_70 ( unsigned int * V_53 )
{
unsigned long V_27 ;
unsigned int V_1 = * V_53 ;
F_18 ( & V_29 , V_27 ) ;
F_22 ( V_1 , V_55 ) ;
F_22 ( V_1 , V_67 ) ;
F_22 ( V_1 , V_56 ) ;
F_25 ( & V_29 , V_27 ) ;
}
int F_71 ( void )
{
return V_3 . V_13 == V_14 ;
}
bool F_72 ( void )
{
struct V_6 * V_7 = V_3 . V_19 ;
return V_7 ? V_7 -> V_10 & V_15 : false ;
}
void T_2 F_73 ( void )
{
F_74 ( & V_5 , V_72 ) ;
F_74 ( & V_32 , V_72 ) ;
F_74 ( & V_38 , V_72 ) ;
#ifdef F_75
F_74 ( & V_55 , V_72 ) ;
F_74 ( & V_67 , V_72 ) ;
F_74 ( & V_56 , V_72 ) ;
#endif
}
