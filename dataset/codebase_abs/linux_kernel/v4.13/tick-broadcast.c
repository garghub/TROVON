static inline void F_1 ( struct V_1 * V_2 ) { F_2 () ; }
static inline void F_3 ( int V_3 ) { }
static inline void F_4 ( struct V_1 * V_2 ) { }
struct V_4 * F_5 ( void )
{
return & V_5 ;
}
struct V_6 * F_6 ( void )
{
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 )
F_8 ( V_2 , 1 ) ;
}
static bool F_9 ( struct V_1 * V_8 ,
struct V_1 * V_9 )
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
void F_10 ( struct V_1 * V_18 )
{
struct V_1 * V_19 = V_5 . V_20 ;
if ( ! F_9 ( V_19 , V_18 ) )
return;
if ( ! F_11 ( V_18 -> V_21 ) )
return;
F_12 ( V_19 , V_18 ) ;
if ( V_19 )
V_19 -> V_22 = V_23 ;
V_5 . V_20 = V_18 ;
if ( ! F_13 ( V_7 ) )
F_7 ( V_18 ) ;
if ( V_18 -> V_10 & V_16 )
F_14 () ;
}
int F_15 ( struct V_1 * V_18 )
{
return ( V_18 && V_5 . V_20 == V_18 ) ;
}
int F_16 ( struct V_1 * V_18 , T_1 V_24 )
{
int V_25 = - V_26 ;
if ( F_15 ( V_18 ) ) {
F_17 ( & V_27 ) ;
V_25 = F_18 ( V_18 , V_24 ) ;
F_19 ( & V_27 ) ;
}
return V_25 ;
}
static void F_20 ( const struct V_6 * V_28 )
{
F_21 ( L_1 ) ;
}
static void F_22 ( struct V_1 * V_18 )
{
if ( ! V_18 -> V_29 )
V_18 -> V_29 = V_30 ;
if ( ! V_18 -> V_29 ) {
F_23 ( L_2 ,
V_18 -> V_31 ) ;
V_18 -> V_29 = F_20 ;
}
}
int F_24 ( struct V_1 * V_18 , int V_3 )
{
struct V_1 * V_2 = V_5 . V_20 ;
unsigned long V_32 ;
int V_25 = 0 ;
F_25 ( & V_27 , V_32 ) ;
if ( ! F_26 ( V_18 ) ) {
V_18 -> V_22 = V_33 ;
F_22 ( V_18 ) ;
F_27 ( V_3 , V_7 ) ;
if ( V_5 . V_14 == V_34 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
V_25 = 1 ;
} else {
if ( ! ( V_18 -> V_10 & V_13 ) )
F_28 ( V_3 , V_7 ) ;
else
F_22 ( V_18 ) ;
if ( ! F_29 ( V_3 , V_35 ) )
F_28 ( V_3 , V_7 ) ;
switch ( V_5 . V_14 ) {
case V_15 :
F_3 ( V_3 ) ;
V_25 = 0 ;
break;
case V_34 :
if ( F_13 ( V_7 ) && V_2 )
F_30 ( V_2 ) ;
if ( V_2 && ! ( V_2 -> V_10 & V_36 ) )
V_25 = F_29 ( V_3 , V_7 ) ;
break;
default:
break;
}
}
F_31 ( & V_27 , V_32 ) ;
return V_25 ;
}
int F_32 ( void )
{
struct V_4 * V_37 = F_33 ( & V_38 ) ;
struct V_1 * V_39 = V_37 -> V_20 ;
if ( ! V_39 )
return - V_26 ;
if ( ! V_39 -> V_22 )
return - V_40 ;
V_39 -> V_22 ( V_39 ) ;
return 0 ;
}
static bool F_34 ( struct V_6 * V_28 )
{
int V_3 = F_35 () ;
struct V_4 * V_37 ;
bool V_41 = false ;
if ( F_29 ( V_3 , V_28 ) ) {
struct V_1 * V_2 = V_5 . V_20 ;
F_28 ( V_3 , V_28 ) ;
V_41 = ! ( V_2 -> V_10 & V_36 ) ;
}
if ( ! F_13 ( V_28 ) ) {
V_37 = & F_36 ( V_38 , F_37 ( V_28 ) ) ;
V_37 -> V_20 -> V_29 ( V_28 ) ;
}
return V_41 ;
}
static bool F_38 ( void )
{
F_39 ( V_42 , V_43 , V_7 ) ;
return F_34 ( V_42 ) ;
}
static void F_40 ( struct V_1 * V_18 )
{
struct V_4 * V_37 = F_33 ( & V_38 ) ;
bool V_44 ;
F_17 ( & V_27 ) ;
if ( F_41 ( V_5 . V_20 ) ) {
F_19 ( & V_27 ) ;
return;
}
V_44 = F_38 () ;
if ( F_42 ( V_18 ) ) {
T_2 V_45 = F_43 ( V_18 -> V_46 , V_47 ) ;
F_44 ( V_18 , V_45 , true ) ;
}
F_19 ( & V_27 ) ;
if ( V_44 )
V_37 -> V_20 -> V_22 ( V_37 -> V_20 ) ;
}
void F_45 ( enum V_48 V_14 )
{
struct V_1 * V_2 , * V_18 ;
struct V_4 * V_37 ;
int V_3 , V_49 ;
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
V_37 = F_33 ( & V_38 ) ;
V_18 = V_37 -> V_20 ;
if ( ! V_18 || ! ( V_18 -> V_10 & V_13 ) )
goto V_50;
if ( ! F_26 ( V_18 ) )
goto V_50;
V_3 = F_35 () ;
V_2 = V_5 . V_20 ;
V_49 = F_13 ( V_7 ) ;
switch ( V_14 ) {
case V_51 :
V_52 = 1 ;
case V_53 :
F_27 ( V_3 , V_35 ) ;
if ( ! F_46 ( V_3 , V_7 ) ) {
if ( V_2 && ! ( V_2 -> V_10 & V_36 ) &&
V_5 . V_14 == V_34 )
F_30 ( V_18 ) ;
}
break;
case V_54 :
if ( V_52 )
break;
F_28 ( V_3 , V_35 ) ;
if ( ! F_26 ( V_18 ) )
break;
if ( F_47 ( V_3 , V_7 ) ) {
if ( V_5 . V_14 ==
V_34 )
F_8 ( V_18 , 0 ) ;
}
break;
}
if ( V_2 ) {
if ( F_13 ( V_7 ) ) {
if ( ! V_49 )
F_30 ( V_2 ) ;
} else if ( V_49 ) {
if ( V_5 . V_14 == V_34 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
}
}
V_50:
F_31 ( & V_27 , V_32 ) ;
}
void F_48 ( struct V_1 * V_18 , int V_29 )
{
if ( ! V_29 )
V_18 -> V_22 = V_33 ;
else
V_18 -> V_22 = F_40 ;
}
void F_49 ( unsigned int V_3 )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
V_2 = V_5 . V_20 ;
F_28 ( V_3 , V_7 ) ;
F_28 ( V_3 , V_35 ) ;
if ( V_5 . V_14 == V_34 ) {
if ( V_2 && F_13 ( V_7 ) )
F_30 ( V_2 ) ;
}
F_31 ( & V_27 , V_32 ) ;
}
void F_50 ( void )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
V_2 = V_5 . V_20 ;
if ( V_2 )
F_30 ( V_2 ) ;
F_31 ( & V_27 , V_32 ) ;
}
bool F_51 ( void )
{
if ( V_5 . V_14 == V_15 )
return false ;
else
return F_29 ( F_35 () , V_7 ) ;
}
void F_52 ( void )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
V_2 = V_5 . V_20 ;
if ( V_2 ) {
F_53 ( V_2 ) ;
switch ( V_5 . V_14 ) {
case V_34 :
if ( ! F_13 ( V_7 ) )
F_7 ( V_2 ) ;
break;
case V_15 :
if ( ! F_13 ( V_7 ) )
F_4 ( V_2 ) ;
break;
}
}
F_31 ( & V_27 , V_32 ) ;
}
struct V_6 * F_54 ( void )
{
return V_55 ;
}
int F_55 ( void )
{
return F_29 ( F_35 () , V_56 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
const struct V_6 * V_6 )
{
if ( ! ( V_2 -> V_10 & V_57 ) )
return;
if ( F_57 ( V_2 -> V_6 , V_6 ) )
return;
V_2 -> V_6 = V_6 ;
F_58 ( V_2 -> V_58 , V_2 -> V_6 ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_3 ,
T_2 V_59 )
{
if ( ! F_42 ( V_2 ) )
F_60 ( V_2 , V_60 ) ;
F_44 ( V_2 , V_59 , 1 ) ;
F_56 ( V_2 , F_61 ( V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_60 ) ;
}
void F_62 ( void )
{
if ( F_29 ( F_35 () , V_55 ) ) {
struct V_4 * V_37 = F_33 ( & V_38 ) ;
if ( V_37 -> V_14 == V_15 ) {
F_60 ( V_37 -> V_20 ,
V_60 ) ;
}
}
}
static void F_63 ( struct V_1 * V_18 )
{
struct V_4 * V_37 ;
T_2 V_61 , V_46 ;
int V_3 , V_62 = 0 ;
bool V_44 ;
F_17 ( & V_27 ) ;
V_18 -> V_46 = V_63 ;
V_46 = V_63 ;
F_64 ( V_42 ) ;
V_61 = F_65 () ;
F_66 (cpu, tick_broadcast_oneshot_mask) {
V_37 = & F_36 ( V_38 , V_3 ) ;
if ( V_37 -> V_20 -> V_46 <= V_61 ) {
F_27 ( V_3 , V_42 ) ;
F_27 ( V_3 , V_64 ) ;
} else if ( V_37 -> V_20 -> V_46 < V_46 ) {
V_46 = V_37 -> V_20 -> V_46 ;
V_62 = V_3 ;
}
}
F_28 ( F_35 () , V_64 ) ;
F_67 ( V_42 , V_42 , V_56 ) ;
F_64 ( V_56 ) ;
if ( F_68 ( ! F_69 ( V_42 , V_43 ) ) )
F_39 ( V_42 , V_42 , V_43 ) ;
V_44 = F_34 ( V_42 ) ;
if ( V_46 != V_63 )
F_59 ( V_18 , V_62 , V_46 ) ;
F_19 ( & V_27 ) ;
if ( V_44 ) {
V_37 = F_33 ( & V_38 ) ;
V_37 -> V_20 -> V_22 ( V_37 -> V_20 ) ;
}
}
static int F_70 ( struct V_1 * V_2 , int V_3 )
{
if ( ! ( V_2 -> V_10 & V_36 ) )
return 0 ;
if ( V_2 -> V_46 == V_63 )
return 0 ;
return V_2 -> V_65 == V_3 ? - V_66 : 0 ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_1 * V_18 )
{
if ( V_2 -> V_10 & V_36 ) {
if ( F_70 ( V_2 , F_35 () ) )
return;
if ( V_18 -> V_46 < V_2 -> V_46 )
return;
}
F_60 ( V_18 , V_67 ) ;
}
int F_72 ( enum V_68 V_69 )
{
struct V_1 * V_2 , * V_18 ;
int V_3 , V_25 = 0 ;
T_2 V_61 ;
if ( ! V_5 . V_20 )
return - V_66 ;
V_18 = F_33 ( & V_38 ) -> V_20 ;
F_17 ( & V_27 ) ;
V_2 = V_5 . V_20 ;
V_3 = F_35 () ;
if ( V_69 == V_70 ) {
V_25 = F_70 ( V_2 , V_3 ) ;
if ( V_25 )
goto V_50;
if ( V_5 . V_14 == V_34 ) {
if ( V_2 -> V_10 & V_36 )
V_25 = - V_66 ;
goto V_50;
}
if ( ! F_46 ( V_3 , V_55 ) ) {
F_68 ( F_29 ( V_3 , V_64 ) ) ;
F_71 ( V_2 , V_18 ) ;
if ( F_29 ( V_3 , V_56 ) ) {
V_25 = - V_66 ;
} else if ( V_18 -> V_46 < V_2 -> V_46 ) {
F_59 ( V_2 , V_3 , V_18 -> V_46 ) ;
V_25 = F_70 ( V_2 , V_3 ) ;
if ( V_25 ) {
F_28 ( V_3 ,
V_55 ) ;
}
}
}
} else {
if ( F_47 ( V_3 , V_55 ) ) {
F_60 ( V_18 , V_60 ) ;
if ( F_47 ( V_3 ,
V_64 ) )
goto V_50;
if ( V_18 -> V_46 == V_63 )
goto V_50;
V_61 = F_65 () ;
if ( V_18 -> V_46 <= V_61 ) {
F_27 ( V_3 , V_56 ) ;
goto V_50;
}
F_73 ( V_18 -> V_46 , 1 ) ;
}
}
V_50:
F_19 ( & V_27 ) ;
return V_25 ;
}
static void F_3 ( int V_3 )
{
F_28 ( V_3 , V_55 ) ;
F_28 ( V_3 , V_64 ) ;
}
static void F_74 ( struct V_6 * V_28 ,
T_2 V_59 )
{
struct V_4 * V_37 ;
int V_3 ;
F_66 (cpu, mask) {
V_37 = & F_36 ( V_38 , V_3 ) ;
if ( V_37 -> V_20 )
V_37 -> V_20 -> V_46 = V_59 ;
}
}
static void F_1 ( struct V_1 * V_2 )
{
int V_3 = F_35 () ;
if ( ! V_2 )
return;
if ( V_2 -> V_22 != F_63 ) {
int V_71 = F_75 ( V_2 ) ;
V_2 -> V_22 = F_63 ;
F_76 ( V_42 , V_7 ) ;
F_28 ( V_3 , V_42 ) ;
F_67 ( V_55 ,
V_55 , V_42 ) ;
if ( V_71 && ! F_13 ( V_42 ) ) {
F_60 ( V_2 , V_60 ) ;
F_74 ( V_42 ,
V_72 ) ;
F_59 ( V_2 , V_3 , V_72 ) ;
} else
V_2 -> V_46 = V_63 ;
} else {
F_3 ( V_3 ) ;
}
}
void F_77 ( void )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
V_5 . V_14 = V_15 ;
V_2 = V_5 . V_20 ;
if ( V_2 )
F_1 ( V_2 ) ;
F_31 ( & V_27 , V_32 ) ;
}
void F_78 ( int V_73 )
{
struct V_1 * V_2 ;
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
V_2 = V_5 . V_20 ;
if ( V_2 && F_70 ( V_2 , V_73 ) ) {
F_44 ( V_2 , V_2 -> V_46 , 1 ) ;
}
F_31 ( & V_27 , V_32 ) ;
}
void F_79 ( unsigned int V_3 )
{
unsigned long V_32 ;
F_25 ( & V_27 , V_32 ) ;
F_28 ( V_3 , V_55 ) ;
F_28 ( V_3 , V_64 ) ;
F_28 ( V_3 , V_56 ) ;
F_31 ( & V_27 , V_32 ) ;
}
int F_80 ( void )
{
return V_5 . V_14 == V_15 ;
}
bool F_81 ( void )
{
struct V_1 * V_2 = V_5 . V_20 ;
return V_2 ? V_2 -> V_10 & V_16 : false ;
}
int F_72 ( enum V_68 V_69 )
{
struct V_1 * V_2 = V_5 . V_20 ;
if ( ! V_2 || ( V_2 -> V_10 & V_36 ) )
return - V_66 ;
return 0 ;
}
void T_3 F_82 ( void )
{
F_83 ( & V_7 , V_74 ) ;
F_83 ( & V_35 , V_74 ) ;
F_83 ( & V_42 , V_74 ) ;
#ifdef F_84
F_83 ( & V_55 , V_74 ) ;
F_83 ( & V_64 , V_74 ) ;
F_83 ( & V_56 , V_74 ) ;
#endif
}
