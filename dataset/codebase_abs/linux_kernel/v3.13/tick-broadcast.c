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
static void F_13 ( const struct V_4 * V_24 )
{
F_14 ( L_1 ) ;
}
static void F_15 ( struct V_6 * V_18 )
{
if ( ! V_18 -> V_25 )
V_18 -> V_25 = V_26 ;
if ( ! V_18 -> V_25 ) {
F_16 ( L_2 ,
V_18 -> V_27 ) ;
V_18 -> V_25 = F_13 ;
}
}
int F_17 ( struct V_6 * V_18 , int V_1 )
{
struct V_6 * V_7 = V_3 . V_20 ;
unsigned long V_28 ;
int V_29 ;
F_18 ( & V_30 , V_28 ) ;
if ( ! F_19 ( V_18 ) ) {
V_18 -> V_22 = V_31 ;
F_15 ( V_18 ) ;
F_20 ( V_1 , V_5 ) ;
if ( V_3 . V_14 == V_32 )
F_4 ( V_7 ) ;
else
F_21 ( V_7 ) ;
V_29 = 1 ;
} else {
if ( ! ( V_18 -> V_10 & V_13 ) )
F_22 ( V_1 , V_5 ) ;
else
F_15 ( V_18 ) ;
if ( ! F_23 ( V_1 , V_33 ) )
F_22 ( V_1 , V_5 ) ;
switch ( V_3 . V_14 ) {
case V_15 :
F_1 ( V_1 ) ;
V_29 = 0 ;
break;
case V_32 :
if ( F_10 ( V_5 ) && V_7 )
F_24 ( V_7 ) ;
V_29 = F_23 ( V_1 , V_5 ) ;
break;
default:
V_29 = 0 ;
break;
}
}
F_25 ( & V_30 , V_28 ) ;
return V_29 ;
}
int F_26 ( void )
{
struct V_2 * V_34 = F_27 ( & V_35 ) ;
struct V_6 * V_36 = V_34 -> V_20 ;
if ( ! V_36 )
return - V_37 ;
if ( ! V_36 -> V_22 )
return - V_38 ;
V_36 -> V_22 ( V_36 ) ;
return 0 ;
}
static void F_28 ( struct V_4 * V_24 )
{
int V_1 = F_29 () ;
struct V_2 * V_34 ;
if ( F_23 ( V_1 , V_24 ) ) {
F_22 ( V_1 , V_24 ) ;
V_34 = & F_30 ( V_35 , V_1 ) ;
V_34 -> V_20 -> V_22 ( V_34 -> V_20 ) ;
}
if ( ! F_10 ( V_24 ) ) {
V_34 = & F_30 ( V_35 , F_31 ( V_24 ) ) ;
V_34 -> V_20 -> V_25 ( V_24 ) ;
}
}
static void F_32 ( void )
{
F_33 ( & V_30 ) ;
F_34 ( V_39 , V_40 , V_5 ) ;
F_28 ( V_39 ) ;
F_35 ( & V_30 ) ;
}
static void F_36 ( struct V_6 * V_18 )
{
T_1 V_41 ;
F_32 () ;
if ( V_18 -> V_14 == V_42 )
return;
for ( V_41 = V_18 -> V_43 ; ; ) {
V_41 = F_37 ( V_41 , V_44 ) ;
if ( ! F_38 ( V_18 , V_41 , false ) )
return;
F_32 () ;
}
}
static void F_39 ( unsigned long * V_45 )
{
struct V_6 * V_7 , * V_18 ;
struct V_2 * V_34 ;
unsigned long V_28 ;
int V_1 , V_46 ;
F_18 ( & V_30 , V_28 ) ;
V_1 = F_29 () ;
V_34 = & F_30 ( V_35 , V_1 ) ;
V_18 = V_34 -> V_20 ;
V_7 = V_3 . V_20 ;
if ( ! V_18 || ! ( V_18 -> V_10 & V_13 ) )
goto V_47;
if ( ! F_19 ( V_18 ) )
goto V_47;
V_46 = F_10 ( V_5 ) ;
switch ( * V_45 ) {
case V_48 :
case V_49 :
F_20 ( V_1 , V_33 ) ;
if ( ! F_40 ( V_1 , V_5 ) ) {
if ( V_3 . V_14 ==
V_32 )
F_24 ( V_18 ) ;
}
if ( * V_45 == V_49 )
V_50 = 1 ;
break;
case V_51 :
if ( V_50 )
break;
F_22 ( V_1 , V_33 ) ;
if ( ! F_19 ( V_18 ) )
break;
if ( F_41 ( V_1 , V_5 ) ) {
if ( V_3 . V_14 ==
V_32 )
F_5 ( V_18 , 0 ) ;
}
break;
}
if ( F_10 ( V_5 ) ) {
if ( ! V_46 )
F_24 ( V_7 ) ;
} else if ( V_46 ) {
if ( V_3 . V_14 == V_32 )
F_4 ( V_7 ) ;
else
F_21 ( V_7 ) ;
}
V_47:
F_25 ( & V_30 , V_28 ) ;
}
void F_42 ( unsigned long V_45 , int * V_52 )
{
if ( ! F_23 ( * V_52 , V_40 ) )
F_43 ( V_53 L_3
L_4 , * V_52 ) ;
else
F_39 ( & V_45 ) ;
}
void F_44 ( struct V_6 * V_18 , int V_25 )
{
if ( ! V_25 )
V_18 -> V_22 = V_31 ;
else
V_18 -> V_22 = F_36 ;
}
void F_45 ( unsigned int * V_54 )
{
struct V_6 * V_7 ;
unsigned long V_28 ;
unsigned int V_1 = * V_54 ;
F_18 ( & V_30 , V_28 ) ;
V_7 = V_3 . V_20 ;
F_22 ( V_1 , V_5 ) ;
F_22 ( V_1 , V_33 ) ;
if ( V_3 . V_14 == V_32 ) {
if ( V_7 && F_10 ( V_5 ) )
F_24 ( V_7 ) ;
}
F_25 ( & V_30 , V_28 ) ;
}
void F_46 ( void )
{
struct V_6 * V_7 ;
unsigned long V_28 ;
F_18 ( & V_30 , V_28 ) ;
V_7 = V_3 . V_20 ;
if ( V_7 )
F_24 ( V_7 ) ;
F_25 ( & V_30 , V_28 ) ;
}
int F_47 ( void )
{
struct V_6 * V_7 ;
unsigned long V_28 ;
int V_25 = 0 ;
F_18 ( & V_30 , V_28 ) ;
V_7 = V_3 . V_20 ;
if ( V_7 ) {
F_48 ( V_7 , V_55 ) ;
switch ( V_3 . V_14 ) {
case V_32 :
if ( ! F_10 ( V_5 ) )
F_4 ( V_7 ) ;
V_25 = F_23 ( F_29 () ,
V_5 ) ;
break;
case V_15 :
if ( ! F_10 ( V_5 ) )
V_25 = F_49 ( V_7 ) ;
break;
}
}
F_25 ( & V_30 , V_28 ) ;
return V_25 ;
}
struct V_4 * F_50 ( void )
{
return V_56 ;
}
int F_51 ( void )
{
return F_23 ( F_29 () , V_57 ) ;
}
static void F_52 ( struct V_6 * V_7 ,
const struct V_4 * V_4 )
{
if ( ! ( V_7 -> V_10 & V_58 ) )
return;
if ( F_53 ( V_7 -> V_4 , V_4 ) )
return;
V_7 -> V_4 = V_4 ;
F_54 ( V_7 -> V_59 , V_7 -> V_4 ) ;
}
static int F_55 ( struct V_6 * V_7 , int V_1 ,
T_1 V_60 , int V_61 )
{
int V_29 ;
if ( V_7 -> V_14 != V_62 )
F_48 ( V_7 , V_62 ) ;
V_29 = F_38 ( V_7 , V_60 , V_61 ) ;
if ( ! V_29 )
F_52 ( V_7 , F_56 ( V_1 ) ) ;
return V_29 ;
}
int F_49 ( struct V_6 * V_7 )
{
F_48 ( V_7 , V_62 ) ;
return 0 ;
}
void F_57 ( int V_1 )
{
if ( F_23 ( V_1 , V_56 ) ) {
struct V_2 * V_34 = & F_30 ( V_35 , V_1 ) ;
if ( V_34 -> V_14 == V_15 ) {
F_48 ( V_34 -> V_20 ,
V_62 ) ;
}
}
}
static void F_58 ( struct V_6 * V_18 )
{
struct V_2 * V_34 ;
T_1 V_63 , V_43 ;
int V_1 , V_64 = 0 ;
F_33 ( & V_30 ) ;
V_65:
V_18 -> V_43 . V_66 = V_67 ;
V_43 . V_66 = V_67 ;
F_59 ( V_39 ) ;
V_63 = F_60 () ;
F_61 (cpu, tick_broadcast_oneshot_mask) {
V_34 = & F_30 ( V_35 , V_1 ) ;
if ( V_34 -> V_20 -> V_43 . V_66 <= V_63 . V_66 ) {
F_20 ( V_1 , V_39 ) ;
F_20 ( V_1 , V_68 ) ;
} else if ( V_34 -> V_20 -> V_43 . V_66 < V_43 . V_66 ) {
V_43 . V_66 = V_34 -> V_20 -> V_43 . V_66 ;
V_64 = V_1 ;
}
}
F_22 ( F_29 () , V_68 ) ;
F_62 ( V_39 , V_39 , V_57 ) ;
F_59 ( V_57 ) ;
if ( F_63 ( ! F_64 ( V_39 , V_40 ) ) )
F_34 ( V_39 , V_39 , V_40 ) ;
F_28 ( V_39 ) ;
if ( V_43 . V_66 != V_67 ) {
if ( F_55 ( V_18 , V_64 , V_43 , 0 ) )
goto V_65;
}
F_35 ( & V_30 ) ;
}
void F_65 ( unsigned long V_45 )
{
struct V_6 * V_7 , * V_18 ;
struct V_2 * V_34 ;
unsigned long V_28 ;
T_1 V_63 ;
int V_1 ;
if ( V_3 . V_14 == V_32 )
return;
V_1 = F_29 () ;
V_34 = & F_30 ( V_35 , V_1 ) ;
V_18 = V_34 -> V_20 ;
if ( ! ( V_18 -> V_10 & V_13 ) )
return;
V_7 = V_3 . V_20 ;
F_18 ( & V_30 , V_28 ) ;
if ( V_45 == V_69 ) {
if ( ! F_40 ( V_1 , V_56 ) ) {
F_63 ( F_23 ( V_1 , V_68 ) ) ;
F_48 ( V_18 , V_70 ) ;
if ( ! F_23 ( V_1 , V_57 ) &&
V_18 -> V_43 . V_66 < V_7 -> V_43 . V_66 )
F_55 ( V_7 , V_1 , V_18 -> V_43 , 1 ) ;
}
} else {
if ( F_41 ( V_1 , V_56 ) ) {
F_48 ( V_18 , V_62 ) ;
if ( F_41 ( V_1 ,
V_68 ) )
goto V_47;
if ( V_18 -> V_43 . V_66 == V_67 )
goto V_47;
V_63 = F_60 () ;
if ( V_18 -> V_43 . V_66 <= V_63 . V_66 ) {
F_20 ( V_1 , V_57 ) ;
goto V_47;
}
F_66 ( V_18 -> V_43 , 1 ) ;
}
}
V_47:
F_25 ( & V_30 , V_28 ) ;
}
static void F_1 ( int V_1 )
{
F_22 ( V_1 , V_56 ) ;
}
static void F_67 ( struct V_4 * V_24 ,
T_1 V_60 )
{
struct V_2 * V_34 ;
int V_1 ;
F_61 (cpu, mask) {
V_34 = & F_30 ( V_35 , V_1 ) ;
if ( V_34 -> V_20 )
V_34 -> V_20 -> V_43 = V_60 ;
}
}
void F_21 ( struct V_6 * V_7 )
{
int V_1 = F_29 () ;
if ( V_7 -> V_22 != F_58 ) {
int V_71 = V_7 -> V_14 == V_42 ;
V_7 -> V_22 = F_58 ;
F_68 ( V_39 , V_5 ) ;
F_22 ( V_1 , V_39 ) ;
F_62 ( V_56 ,
V_56 , V_39 ) ;
if ( V_71 && ! F_10 ( V_39 ) ) {
F_48 ( V_7 , V_62 ) ;
F_67 ( V_39 ,
V_72 ) ;
F_55 ( V_7 , V_1 , V_72 , 1 ) ;
} else
V_7 -> V_43 . V_66 = V_67 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_69 ( void )
{
struct V_6 * V_7 ;
unsigned long V_28 ;
F_18 ( & V_30 , V_28 ) ;
V_3 . V_14 = V_15 ;
V_7 = V_3 . V_20 ;
if ( V_7 )
F_21 ( V_7 ) ;
F_25 ( & V_30 , V_28 ) ;
}
void F_70 ( unsigned int * V_54 )
{
unsigned long V_28 ;
unsigned int V_1 = * V_54 ;
F_18 ( & V_30 , V_28 ) ;
F_22 ( V_1 , V_56 ) ;
F_22 ( V_1 , V_68 ) ;
F_22 ( V_1 , V_57 ) ;
F_25 ( & V_30 , V_28 ) ;
}
int F_71 ( void )
{
return V_3 . V_14 == V_15 ;
}
bool F_72 ( void )
{
struct V_6 * V_7 = V_3 . V_20 ;
return V_7 ? V_7 -> V_10 & V_16 : false ;
}
void T_2 F_73 ( void )
{
F_74 ( & V_5 , V_73 ) ;
F_74 ( & V_33 , V_73 ) ;
F_74 ( & V_39 , V_73 ) ;
#ifdef F_75
F_74 ( & V_56 , V_73 ) ;
F_74 ( & V_68 , V_73 ) ;
F_74 ( & V_57 , V_73 ) ;
#endif
}
