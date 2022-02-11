static inline void F_1 ( int V_1 ) { }
static inline void F_2 ( struct V_2 * V_3 ) { }
struct V_4 * F_3 ( void )
{
return & V_5 ;
}
struct V_6 * F_4 ( void )
{
return V_7 ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( V_3 )
F_6 ( V_3 , 1 ) ;
}
static bool F_7 ( struct V_2 * V_8 ,
struct V_2 * V_9 )
{
if ( ( V_9 -> V_10 & V_11 ) ||
( V_9 -> V_10 & V_12 ) ||
( V_9 -> V_10 & V_13 ) )
return false ;
if ( V_5 . V_14 == V_15 &&
! ( V_9 -> V_10 & V_16 ) )
return false ;
return ! V_8 || V_9 -> V_17 > V_8 -> V_17 ;
}
void F_8 ( struct V_2 * V_18 )
{
struct V_2 * V_19 = V_5 . V_20 ;
if ( ! F_7 ( V_19 , V_18 ) )
return;
if ( ! F_9 ( V_18 -> V_21 ) )
return;
F_10 ( V_19 , V_18 ) ;
if ( V_19 )
V_19 -> V_22 = V_23 ;
V_5 . V_20 = V_18 ;
if ( ! F_11 ( V_7 ) )
F_5 ( V_18 ) ;
if ( V_18 -> V_10 & V_16 )
F_12 () ;
}
int F_13 ( struct V_2 * V_18 )
{
return ( V_18 && V_5 . V_20 == V_18 ) ;
}
int F_14 ( struct V_2 * V_18 , T_1 V_24 )
{
int V_25 = - V_26 ;
if ( F_13 ( V_18 ) ) {
F_15 ( & V_27 ) ;
V_25 = F_16 ( V_18 , V_24 ) ;
F_17 ( & V_27 ) ;
}
return V_25 ;
}
static void F_18 ( const struct V_6 * V_28 )
{
F_19 ( L_1 ) ;
}
static void F_20 ( struct V_2 * V_18 )
{
if ( ! V_18 -> V_29 )
V_18 -> V_29 = V_30 ;
if ( ! V_18 -> V_29 ) {
F_21 ( L_2 ,
V_18 -> V_31 ) ;
V_18 -> V_29 = F_18 ;
}
}
int F_22 ( struct V_2 * V_18 , int V_1 )
{
struct V_2 * V_3 = V_5 . V_20 ;
unsigned long V_32 ;
int V_25 ;
F_23 ( & V_27 , V_32 ) ;
if ( ! F_24 ( V_18 ) ) {
V_18 -> V_22 = V_33 ;
F_20 ( V_18 ) ;
F_25 ( V_1 , V_7 ) ;
if ( V_5 . V_14 == V_34 )
F_5 ( V_3 ) ;
else
F_26 ( V_3 ) ;
V_25 = 1 ;
} else {
if ( ! ( V_18 -> V_10 & V_13 ) )
F_27 ( V_1 , V_7 ) ;
else
F_20 ( V_18 ) ;
if ( ! F_28 ( V_1 , V_35 ) )
F_27 ( V_1 , V_7 ) ;
switch ( V_5 . V_14 ) {
case V_15 :
F_1 ( V_1 ) ;
V_25 = 0 ;
break;
case V_34 :
if ( F_11 ( V_7 ) && V_3 )
F_29 ( V_3 ) ;
V_25 = F_28 ( V_1 , V_7 ) ;
break;
default:
V_25 = 0 ;
break;
}
}
F_30 ( & V_27 , V_32 ) ;
return V_25 ;
}
int F_31 ( void )
{
struct V_4 * V_36 = F_32 ( & V_37 ) ;
struct V_2 * V_38 = V_36 -> V_20 ;
if ( ! V_38 )
return - V_26 ;
if ( ! V_38 -> V_22 )
return - V_39 ;
V_38 -> V_22 ( V_38 ) ;
return 0 ;
}
static void F_33 ( struct V_6 * V_28 )
{
int V_1 = F_34 () ;
struct V_4 * V_36 ;
if ( F_28 ( V_1 , V_28 ) ) {
F_27 ( V_1 , V_28 ) ;
V_36 = & F_35 ( V_37 , V_1 ) ;
V_36 -> V_20 -> V_22 ( V_36 -> V_20 ) ;
}
if ( ! F_11 ( V_28 ) ) {
V_36 = & F_35 ( V_37 , F_36 ( V_28 ) ) ;
V_36 -> V_20 -> V_29 ( V_28 ) ;
}
}
static void F_37 ( void )
{
F_38 ( V_40 , V_41 , V_7 ) ;
F_33 ( V_40 ) ;
}
static void F_39 ( struct V_2 * V_18 )
{
T_2 V_42 ;
F_15 ( & V_27 ) ;
F_37 () ;
if ( V_18 -> V_43 == V_44 )
goto V_45;
for ( V_42 = V_18 -> V_46 ; ; ) {
V_42 = F_40 ( V_42 , V_47 ) ;
if ( ! F_41 ( V_18 , V_42 , false ) )
goto V_45;
F_37 () ;
}
V_45:
F_17 ( & V_27 ) ;
}
void F_42 ( enum V_48 V_14 )
{
struct V_2 * V_3 , * V_18 ;
struct V_4 * V_36 ;
int V_1 , V_49 ;
V_36 = F_32 ( & V_37 ) ;
V_18 = V_36 -> V_20 ;
if ( ! V_18 || ! ( V_18 -> V_10 & V_13 ) )
return;
if ( ! F_24 ( V_18 ) )
return;
F_15 ( & V_27 ) ;
V_1 = F_34 () ;
V_3 = V_5 . V_20 ;
V_49 = F_11 ( V_7 ) ;
switch ( V_14 ) {
case V_50 :
V_51 = 1 ;
case V_52 :
F_25 ( V_1 , V_35 ) ;
if ( ! F_43 ( V_1 , V_7 ) ) {
if ( V_5 . V_14 ==
V_34 )
F_29 ( V_18 ) ;
}
break;
case V_53 :
if ( V_51 )
break;
F_27 ( V_1 , V_35 ) ;
if ( ! F_24 ( V_18 ) )
break;
if ( F_44 ( V_1 , V_7 ) ) {
if ( V_5 . V_14 ==
V_34 )
F_6 ( V_18 , 0 ) ;
}
break;
}
if ( F_11 ( V_7 ) ) {
if ( ! V_49 )
F_29 ( V_3 ) ;
} else if ( V_49 ) {
if ( V_5 . V_14 == V_34 )
F_5 ( V_3 ) ;
else
F_26 ( V_3 ) ;
}
F_17 ( & V_27 ) ;
}
void F_45 ( struct V_2 * V_18 , int V_29 )
{
if ( ! V_29 )
V_18 -> V_22 = V_33 ;
else
V_18 -> V_22 = F_39 ;
}
void F_46 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
F_27 ( V_1 , V_7 ) ;
F_27 ( V_1 , V_35 ) ;
if ( V_5 . V_14 == V_34 ) {
if ( V_3 && F_11 ( V_7 ) )
F_29 ( V_3 ) ;
}
F_30 ( & V_27 , V_32 ) ;
}
void F_47 ( void )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
if ( V_3 )
F_29 ( V_3 ) ;
F_30 ( & V_27 , V_32 ) ;
}
bool F_48 ( void )
{
if ( V_5 . V_14 == V_15 )
return false ;
else
return F_28 ( F_34 () , V_7 ) ;
}
void F_49 ( void )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
if ( V_3 ) {
F_50 ( V_3 ) ;
switch ( V_5 . V_14 ) {
case V_34 :
if ( ! F_11 ( V_7 ) )
F_5 ( V_3 ) ;
break;
case V_15 :
if ( ! F_11 ( V_7 ) )
F_2 ( V_3 ) ;
break;
}
}
F_30 ( & V_27 , V_32 ) ;
}
struct V_6 * F_51 ( void )
{
return V_54 ;
}
int F_52 ( void )
{
return F_28 ( F_34 () , V_55 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
const struct V_6 * V_6 )
{
if ( ! ( V_3 -> V_10 & V_56 ) )
return;
if ( F_54 ( V_3 -> V_6 , V_6 ) )
return;
V_3 -> V_6 = V_6 ;
F_55 ( V_3 -> V_57 , V_3 -> V_6 ) ;
}
static int F_56 ( struct V_2 * V_3 , int V_1 ,
T_2 V_58 , int V_59 )
{
int V_25 ;
if ( V_3 -> V_43 != V_60 )
F_57 ( V_3 , V_60 ) ;
V_25 = F_41 ( V_3 , V_58 , V_59 ) ;
if ( ! V_25 )
F_53 ( V_3 , F_58 ( V_1 ) ) ;
return V_25 ;
}
static void F_2 ( struct V_2 * V_3 )
{
F_57 ( V_3 , V_60 ) ;
}
void F_59 ( void )
{
if ( F_28 ( F_34 () , V_54 ) ) {
struct V_4 * V_36 = F_32 ( & V_37 ) ;
if ( V_36 -> V_14 == V_15 ) {
F_57 ( V_36 -> V_20 ,
V_60 ) ;
}
}
}
static void F_60 ( struct V_2 * V_18 )
{
struct V_4 * V_36 ;
T_2 V_61 , V_46 ;
int V_1 , V_62 = 0 ;
F_15 ( & V_27 ) ;
V_63:
V_18 -> V_46 . V_64 = V_65 ;
V_46 . V_64 = V_65 ;
F_61 ( V_40 ) ;
V_61 = F_62 () ;
F_63 (cpu, tick_broadcast_oneshot_mask) {
V_36 = & F_35 ( V_37 , V_1 ) ;
if ( V_36 -> V_20 -> V_46 . V_64 <= V_61 . V_64 ) {
F_25 ( V_1 , V_40 ) ;
F_25 ( V_1 , V_66 ) ;
} else if ( V_36 -> V_20 -> V_46 . V_64 < V_46 . V_64 ) {
V_46 . V_64 = V_36 -> V_20 -> V_46 . V_64 ;
V_62 = V_1 ;
}
}
F_27 ( F_34 () , V_66 ) ;
F_64 ( V_40 , V_40 , V_55 ) ;
F_61 ( V_55 ) ;
if ( F_65 ( ! F_66 ( V_40 , V_41 ) ) )
F_38 ( V_40 , V_40 , V_41 ) ;
F_33 ( V_40 ) ;
if ( V_46 . V_64 != V_65 ) {
if ( F_56 ( V_18 , V_62 , V_46 , 0 ) )
goto V_63;
}
F_17 ( & V_27 ) ;
}
static int F_67 ( struct V_2 * V_3 , int V_1 )
{
if ( ! ( V_3 -> V_10 & V_67 ) )
return 0 ;
if ( V_3 -> V_46 . V_64 == V_65 )
return 0 ;
return V_3 -> V_68 == V_1 ? - V_69 : 0 ;
}
static void F_68 ( struct V_2 * V_3 ,
struct V_2 * V_18 )
{
if ( V_3 -> V_10 & V_67 ) {
if ( F_67 ( V_3 , F_34 () ) )
return;
if ( V_18 -> V_46 . V_64 < V_3 -> V_46 . V_64 )
return;
}
F_57 ( V_18 , V_70 ) ;
}
int F_69 ( enum V_71 V_43 )
{
struct V_2 * V_3 , * V_18 ;
struct V_4 * V_36 ;
int V_1 , V_25 = 0 ;
T_2 V_61 ;
if ( V_5 . V_14 == V_34 )
return 0 ;
V_36 = F_32 ( & V_37 ) ;
V_18 = V_36 -> V_20 ;
if ( ! ( V_18 -> V_10 & V_13 ) )
return 0 ;
F_15 ( & V_27 ) ;
V_3 = V_5 . V_20 ;
V_1 = F_34 () ;
if ( V_43 == V_72 ) {
if ( ! F_43 ( V_1 , V_54 ) ) {
F_65 ( F_28 ( V_1 , V_66 ) ) ;
F_68 ( V_3 , V_18 ) ;
if ( ! F_28 ( V_1 , V_55 ) &&
V_18 -> V_46 . V_64 < V_3 -> V_46 . V_64 )
F_56 ( V_3 , V_1 , V_18 -> V_46 , 1 ) ;
}
V_25 = F_67 ( V_3 , V_1 ) ;
if ( V_25 )
F_27 ( V_1 , V_54 ) ;
} else {
if ( F_44 ( V_1 , V_54 ) ) {
F_57 ( V_18 , V_60 ) ;
if ( F_44 ( V_1 ,
V_66 ) )
goto V_73;
if ( V_18 -> V_46 . V_64 == V_65 )
goto V_73;
V_61 = F_62 () ;
if ( V_18 -> V_46 . V_64 <= V_61 . V_64 ) {
F_25 ( V_1 , V_55 ) ;
goto V_73;
}
F_70 ( V_18 -> V_46 , 1 ) ;
}
}
V_73:
F_17 ( & V_27 ) ;
return V_25 ;
}
static void F_1 ( int V_1 )
{
F_27 ( V_1 , V_54 ) ;
F_27 ( V_1 , V_66 ) ;
}
static void F_71 ( struct V_6 * V_28 ,
T_2 V_58 )
{
struct V_4 * V_36 ;
int V_1 ;
F_63 (cpu, mask) {
V_36 = & F_35 ( V_37 , V_1 ) ;
if ( V_36 -> V_20 )
V_36 -> V_20 -> V_46 = V_58 ;
}
}
void F_26 ( struct V_2 * V_3 )
{
int V_1 = F_34 () ;
if ( V_3 -> V_22 != F_60 ) {
int V_74 = V_3 -> V_43 == V_44 ;
V_3 -> V_22 = F_60 ;
F_72 ( V_40 , V_7 ) ;
F_27 ( V_1 , V_40 ) ;
F_64 ( V_54 ,
V_54 , V_40 ) ;
if ( V_74 && ! F_11 ( V_40 ) ) {
F_57 ( V_3 , V_60 ) ;
F_71 ( V_40 ,
V_75 ) ;
F_56 ( V_3 , V_1 , V_75 , 1 ) ;
} else
V_3 -> V_46 . V_64 = V_65 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_73 ( void )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_5 . V_14 = V_15 ;
V_3 = V_5 . V_20 ;
if ( V_3 )
F_26 ( V_3 ) ;
F_30 ( & V_27 , V_32 ) ;
}
void F_74 ( int V_76 )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
if ( V_3 && F_67 ( V_3 , V_76 ) ) {
F_41 ( V_3 , V_3 -> V_46 , 1 ) ;
}
F_30 ( & V_27 , V_32 ) ;
}
void F_75 ( unsigned int V_1 )
{
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
F_27 ( V_1 , V_54 ) ;
F_27 ( V_1 , V_66 ) ;
F_27 ( V_1 , V_55 ) ;
F_30 ( & V_27 , V_32 ) ;
}
int F_76 ( void )
{
return V_5 . V_14 == V_15 ;
}
bool F_77 ( void )
{
struct V_2 * V_3 = V_5 . V_20 ;
return V_3 ? V_3 -> V_10 & V_16 : false ;
}
void T_3 F_78 ( void )
{
F_79 ( & V_7 , V_77 ) ;
F_79 ( & V_35 , V_77 ) ;
F_79 ( & V_40 , V_77 ) ;
#ifdef F_80
F_79 ( & V_54 , V_77 ) ;
F_79 ( & V_66 , V_77 ) ;
F_79 ( & V_55 , V_77 ) ;
#endif
}
