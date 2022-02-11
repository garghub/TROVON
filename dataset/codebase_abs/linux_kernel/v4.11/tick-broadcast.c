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
int V_25 = 0 ;
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
if ( V_3 && ! ( V_3 -> V_10 & V_36 ) )
V_25 = F_28 ( V_1 , V_7 ) ;
break;
default:
break;
}
}
F_30 ( & V_27 , V_32 ) ;
return V_25 ;
}
int F_31 ( void )
{
struct V_4 * V_37 = F_32 ( & V_38 ) ;
struct V_2 * V_39 = V_37 -> V_20 ;
if ( ! V_39 )
return - V_26 ;
if ( ! V_39 -> V_22 )
return - V_40 ;
V_39 -> V_22 ( V_39 ) ;
return 0 ;
}
static bool F_33 ( struct V_6 * V_28 )
{
int V_1 = F_34 () ;
struct V_4 * V_37 ;
bool V_41 = false ;
if ( F_28 ( V_1 , V_28 ) ) {
struct V_2 * V_3 = V_5 . V_20 ;
F_27 ( V_1 , V_28 ) ;
V_41 = ! ( V_3 -> V_10 & V_36 ) ;
}
if ( ! F_11 ( V_28 ) ) {
V_37 = & F_35 ( V_38 , F_36 ( V_28 ) ) ;
V_37 -> V_20 -> V_29 ( V_28 ) ;
}
return V_41 ;
}
static bool F_37 ( void )
{
F_38 ( V_42 , V_43 , V_7 ) ;
return F_33 ( V_42 ) ;
}
static void F_39 ( struct V_2 * V_18 )
{
struct V_4 * V_37 = F_32 ( & V_38 ) ;
bool V_44 ;
F_15 ( & V_27 ) ;
if ( F_40 ( V_5 . V_20 ) ) {
F_17 ( & V_27 ) ;
return;
}
V_44 = F_37 () ;
if ( F_41 ( V_18 ) ) {
T_2 V_45 = F_42 ( V_18 -> V_46 , V_47 ) ;
F_43 ( V_18 , V_45 , true ) ;
}
F_17 ( & V_27 ) ;
if ( V_44 )
V_37 -> V_20 -> V_22 ( V_37 -> V_20 ) ;
}
void F_44 ( enum V_48 V_14 )
{
struct V_2 * V_3 , * V_18 ;
struct V_4 * V_37 ;
int V_1 , V_49 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_37 = F_32 ( & V_38 ) ;
V_18 = V_37 -> V_20 ;
if ( ! V_18 || ! ( V_18 -> V_10 & V_13 ) )
goto V_50;
if ( ! F_24 ( V_18 ) )
goto V_50;
V_1 = F_34 () ;
V_3 = V_5 . V_20 ;
V_49 = F_11 ( V_7 ) ;
switch ( V_14 ) {
case V_51 :
V_52 = 1 ;
case V_53 :
F_25 ( V_1 , V_35 ) ;
if ( ! F_45 ( V_1 , V_7 ) ) {
if ( V_3 && ! ( V_3 -> V_10 & V_36 ) &&
V_5 . V_14 == V_34 )
F_29 ( V_18 ) ;
}
break;
case V_54 :
if ( V_52 )
break;
F_27 ( V_1 , V_35 ) ;
if ( ! F_24 ( V_18 ) )
break;
if ( F_46 ( V_1 , V_7 ) ) {
if ( V_5 . V_14 ==
V_34 )
F_6 ( V_18 , 0 ) ;
}
break;
}
if ( V_3 ) {
if ( F_11 ( V_7 ) ) {
if ( ! V_49 )
F_29 ( V_3 ) ;
} else if ( V_49 ) {
if ( V_5 . V_14 == V_34 )
F_5 ( V_3 ) ;
else
F_26 ( V_3 ) ;
}
}
V_50:
F_30 ( & V_27 , V_32 ) ;
}
void F_47 ( struct V_2 * V_18 , int V_29 )
{
if ( ! V_29 )
V_18 -> V_22 = V_33 ;
else
V_18 -> V_22 = F_39 ;
}
void F_48 ( unsigned int V_1 )
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
void F_49 ( void )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
if ( V_3 )
F_29 ( V_3 ) ;
F_30 ( & V_27 , V_32 ) ;
}
bool F_50 ( void )
{
if ( V_5 . V_14 == V_15 )
return false ;
else
return F_28 ( F_34 () , V_7 ) ;
}
void F_51 ( void )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
if ( V_3 ) {
F_52 ( V_3 ) ;
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
struct V_6 * F_53 ( void )
{
return V_55 ;
}
int F_54 ( void )
{
return F_28 ( F_34 () , V_56 ) ;
}
static void F_55 ( struct V_2 * V_3 ,
const struct V_6 * V_6 )
{
if ( ! ( V_3 -> V_10 & V_57 ) )
return;
if ( F_56 ( V_3 -> V_6 , V_6 ) )
return;
V_3 -> V_6 = V_6 ;
F_57 ( V_3 -> V_58 , V_3 -> V_6 ) ;
}
static void F_58 ( struct V_2 * V_3 , int V_1 ,
T_2 V_59 )
{
if ( ! F_41 ( V_3 ) )
F_59 ( V_3 , V_60 ) ;
F_43 ( V_3 , V_59 , 1 ) ;
F_55 ( V_3 , F_60 ( V_1 ) ) ;
}
static void F_2 ( struct V_2 * V_3 )
{
F_59 ( V_3 , V_60 ) ;
}
void F_61 ( void )
{
if ( F_28 ( F_34 () , V_55 ) ) {
struct V_4 * V_37 = F_32 ( & V_38 ) ;
if ( V_37 -> V_14 == V_15 ) {
F_59 ( V_37 -> V_20 ,
V_60 ) ;
}
}
}
static void F_62 ( struct V_2 * V_18 )
{
struct V_4 * V_37 ;
T_2 V_61 , V_46 ;
int V_1 , V_62 = 0 ;
bool V_44 ;
F_15 ( & V_27 ) ;
V_18 -> V_46 = V_63 ;
V_46 = V_63 ;
F_63 ( V_42 ) ;
V_61 = F_64 () ;
F_65 (cpu, tick_broadcast_oneshot_mask) {
V_37 = & F_35 ( V_38 , V_1 ) ;
if ( V_37 -> V_20 -> V_46 <= V_61 ) {
F_25 ( V_1 , V_42 ) ;
F_25 ( V_1 , V_64 ) ;
} else if ( V_37 -> V_20 -> V_46 < V_46 ) {
V_46 = V_37 -> V_20 -> V_46 ;
V_62 = V_1 ;
}
}
F_27 ( F_34 () , V_64 ) ;
F_66 ( V_42 , V_42 , V_56 ) ;
F_63 ( V_56 ) ;
if ( F_67 ( ! F_68 ( V_42 , V_43 ) ) )
F_38 ( V_42 , V_42 , V_43 ) ;
V_44 = F_33 ( V_42 ) ;
if ( V_46 != V_63 )
F_58 ( V_18 , V_62 , V_46 ) ;
F_17 ( & V_27 ) ;
if ( V_44 ) {
V_37 = F_32 ( & V_38 ) ;
V_37 -> V_20 -> V_22 ( V_37 -> V_20 ) ;
}
}
static int F_69 ( struct V_2 * V_3 , int V_1 )
{
if ( ! ( V_3 -> V_10 & V_36 ) )
return 0 ;
if ( V_3 -> V_46 == V_63 )
return 0 ;
return V_3 -> V_65 == V_1 ? - V_66 : 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_2 * V_18 )
{
if ( V_3 -> V_10 & V_36 ) {
if ( F_69 ( V_3 , F_34 () ) )
return;
if ( V_18 -> V_46 < V_3 -> V_46 )
return;
}
F_59 ( V_18 , V_67 ) ;
}
int F_71 ( enum V_68 V_69 )
{
struct V_2 * V_3 , * V_18 ;
int V_1 , V_25 = 0 ;
T_2 V_61 ;
if ( ! V_5 . V_20 )
return - V_66 ;
V_18 = F_32 ( & V_38 ) -> V_20 ;
F_15 ( & V_27 ) ;
V_3 = V_5 . V_20 ;
V_1 = F_34 () ;
if ( V_69 == V_70 ) {
V_25 = F_69 ( V_3 , V_1 ) ;
if ( V_25 )
goto V_50;
if ( V_5 . V_14 == V_34 ) {
if ( V_3 -> V_10 & V_36 )
V_25 = - V_66 ;
goto V_50;
}
if ( ! F_45 ( V_1 , V_55 ) ) {
F_67 ( F_28 ( V_1 , V_64 ) ) ;
F_70 ( V_3 , V_18 ) ;
if ( F_28 ( V_1 , V_56 ) ) {
V_25 = - V_66 ;
} else if ( V_18 -> V_46 < V_3 -> V_46 ) {
F_58 ( V_3 , V_1 , V_18 -> V_46 ) ;
V_25 = F_69 ( V_3 , V_1 ) ;
if ( V_25 ) {
F_27 ( V_1 ,
V_55 ) ;
}
}
}
} else {
if ( F_46 ( V_1 , V_55 ) ) {
F_59 ( V_18 , V_60 ) ;
if ( F_46 ( V_1 ,
V_64 ) )
goto V_50;
if ( V_18 -> V_46 == V_63 )
goto V_50;
V_61 = F_64 () ;
if ( V_18 -> V_46 <= V_61 ) {
F_25 ( V_1 , V_56 ) ;
goto V_50;
}
F_72 ( V_18 -> V_46 , 1 ) ;
}
}
V_50:
F_17 ( & V_27 ) ;
return V_25 ;
}
static void F_1 ( int V_1 )
{
F_27 ( V_1 , V_55 ) ;
F_27 ( V_1 , V_64 ) ;
}
static void F_73 ( struct V_6 * V_28 ,
T_2 V_59 )
{
struct V_4 * V_37 ;
int V_1 ;
F_65 (cpu, mask) {
V_37 = & F_35 ( V_38 , V_1 ) ;
if ( V_37 -> V_20 )
V_37 -> V_20 -> V_46 = V_59 ;
}
}
void F_26 ( struct V_2 * V_3 )
{
int V_1 = F_34 () ;
if ( ! V_3 )
return;
if ( V_3 -> V_22 != F_62 ) {
int V_71 = F_74 ( V_3 ) ;
V_3 -> V_22 = F_62 ;
F_75 ( V_42 , V_7 ) ;
F_27 ( V_1 , V_42 ) ;
F_66 ( V_55 ,
V_55 , V_42 ) ;
if ( V_71 && ! F_11 ( V_42 ) ) {
F_59 ( V_3 , V_60 ) ;
F_73 ( V_42 ,
V_72 ) ;
F_58 ( V_3 , V_1 , V_72 ) ;
} else
V_3 -> V_46 = V_63 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_76 ( void )
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
void F_77 ( int V_73 )
{
struct V_2 * V_3 ;
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
V_3 = V_5 . V_20 ;
if ( V_3 && F_69 ( V_3 , V_73 ) ) {
F_43 ( V_3 , V_3 -> V_46 , 1 ) ;
}
F_30 ( & V_27 , V_32 ) ;
}
void F_78 ( unsigned int V_1 )
{
unsigned long V_32 ;
F_23 ( & V_27 , V_32 ) ;
F_27 ( V_1 , V_55 ) ;
F_27 ( V_1 , V_64 ) ;
F_27 ( V_1 , V_56 ) ;
F_30 ( & V_27 , V_32 ) ;
}
int F_79 ( void )
{
return V_5 . V_14 == V_15 ;
}
bool F_80 ( void )
{
struct V_2 * V_3 = V_5 . V_20 ;
return V_3 ? V_3 -> V_10 & V_16 : false ;
}
int F_71 ( enum V_68 V_69 )
{
struct V_2 * V_3 = V_5 . V_20 ;
if ( ! V_3 || ( V_3 -> V_10 & V_36 ) )
return - V_66 ;
return 0 ;
}
void T_3 F_81 ( void )
{
F_82 ( & V_7 , V_74 ) ;
F_82 ( & V_35 , V_74 ) ;
F_82 ( & V_42 , V_74 ) ;
#ifdef F_83
F_82 ( & V_55 , V_74 ) ;
F_82 ( & V_64 , V_74 ) ;
F_82 ( & V_56 , V_74 ) ;
#endif
}
