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
int F_6 ( struct V_6 * V_8 )
{
struct V_6 * V_9 = V_3 . V_10 ;
if ( ( V_8 -> V_11 & V_12 ) ||
( V_3 . V_10 &&
V_3 . V_10 -> V_13 >= V_8 -> V_13 ) ||
( V_8 -> V_11 & V_14 ) )
return 0 ;
F_7 ( V_3 . V_10 , V_8 ) ;
if ( V_9 )
V_9 -> V_15 = V_16 ;
V_3 . V_10 = V_8 ;
if ( ! F_8 ( V_5 ) )
F_4 ( V_8 ) ;
if ( V_8 -> V_11 & V_17 )
F_9 () ;
return 1 ;
}
int F_10 ( struct V_6 * V_8 )
{
return ( V_8 && V_3 . V_10 == V_8 ) ;
}
static void F_11 ( const struct V_4 * V_18 )
{
F_12 ( L_1 ) ;
}
static void F_13 ( struct V_6 * V_8 )
{
if ( ! V_8 -> V_19 )
V_8 -> V_19 = V_20 ;
if ( ! V_8 -> V_19 ) {
F_14 ( L_2 ,
V_8 -> V_21 ) ;
V_8 -> V_19 = F_11 ;
}
}
int F_15 ( struct V_6 * V_8 , int V_1 )
{
unsigned long V_22 ;
int V_23 = 0 ;
F_16 ( & V_24 , V_22 ) ;
if ( ! F_17 ( V_8 ) ) {
V_8 -> V_15 = V_25 ;
F_13 ( V_8 ) ;
F_18 ( V_1 , V_5 ) ;
F_4 ( V_3 . V_10 ) ;
V_23 = 1 ;
} else {
if ( ! ( V_8 -> V_11 & V_14 ) ) {
int V_1 = F_19 () ;
F_20 ( V_1 , V_5 ) ;
F_1 ( V_1 ) ;
} else {
F_13 ( V_8 ) ;
}
}
F_21 ( & V_24 , V_22 ) ;
return V_23 ;
}
int F_22 ( void )
{
struct V_2 * V_26 = F_23 ( & V_27 ) ;
struct V_6 * V_28 = V_26 -> V_10 ;
if ( ! V_28 )
return - V_29 ;
if ( ! V_28 -> V_15 )
return - V_30 ;
V_28 -> V_15 ( V_28 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_18 )
{
int V_1 = F_19 () ;
struct V_2 * V_26 ;
if ( F_25 ( V_1 , V_18 ) ) {
F_20 ( V_1 , V_18 ) ;
V_26 = & F_26 ( V_27 , V_1 ) ;
V_26 -> V_10 -> V_15 ( V_26 -> V_10 ) ;
}
if ( ! F_8 ( V_18 ) ) {
V_26 = & F_26 ( V_27 , F_27 ( V_18 ) ) ;
V_26 -> V_10 -> V_19 ( V_18 ) ;
}
}
static void F_28 ( void )
{
F_29 ( & V_24 ) ;
F_30 ( V_31 , V_32 , V_5 ) ;
F_24 ( V_31 ) ;
F_31 ( & V_24 ) ;
}
static void F_32 ( struct V_6 * V_8 )
{
T_1 V_33 ;
F_28 () ;
if ( V_8 -> V_34 == V_35 )
return;
for ( V_33 = V_8 -> V_36 ; ; ) {
V_33 = F_33 ( V_33 , V_37 ) ;
if ( ! F_34 ( V_8 , V_33 , false ) )
return;
F_28 () ;
}
}
static void F_35 ( unsigned long * V_38 )
{
struct V_6 * V_7 , * V_8 ;
struct V_2 * V_26 ;
unsigned long V_22 ;
int V_1 , V_39 ;
F_16 ( & V_24 , V_22 ) ;
V_1 = F_19 () ;
V_26 = & F_26 ( V_27 , V_1 ) ;
V_8 = V_26 -> V_10 ;
V_7 = V_3 . V_10 ;
if ( ! V_8 || ! ( V_8 -> V_11 & V_14 ) )
goto V_40;
if ( ! F_17 ( V_8 ) )
goto V_40;
V_39 = F_8 ( V_5 ) ;
switch ( * V_38 ) {
case V_41 :
case V_42 :
if ( ! F_36 ( V_1 , V_5 ) ) {
if ( V_3 . V_34 ==
V_43 )
F_37 ( V_8 ) ;
}
if ( * V_38 == V_42 )
V_44 = 1 ;
break;
case V_45 :
if ( ! V_44 &&
F_38 ( V_1 , V_5 ) ) {
if ( V_3 . V_34 ==
V_43 )
F_5 ( V_8 , 0 ) ;
}
break;
}
if ( F_8 ( V_5 ) ) {
if ( ! V_39 )
F_37 ( V_7 ) ;
} else if ( V_39 ) {
if ( V_3 . V_34 == V_43 )
F_4 ( V_7 ) ;
else
F_39 ( V_7 ) ;
}
V_40:
F_21 ( & V_24 , V_22 ) ;
}
void F_40 ( unsigned long V_38 , int * V_46 )
{
if ( ! F_25 ( * V_46 , V_32 ) )
F_41 ( V_47 L_3
L_4 , * V_46 ) ;
else
F_35 ( & V_38 ) ;
}
void F_42 ( struct V_6 * V_8 , int V_19 )
{
if ( ! V_19 )
V_8 -> V_15 = V_25 ;
else
V_8 -> V_15 = F_32 ;
}
void F_43 ( unsigned int * V_48 )
{
struct V_6 * V_7 ;
unsigned long V_22 ;
unsigned int V_1 = * V_48 ;
F_16 ( & V_24 , V_22 ) ;
V_7 = V_3 . V_10 ;
F_20 ( V_1 , V_5 ) ;
if ( V_3 . V_34 == V_43 ) {
if ( V_7 && F_8 ( V_5 ) )
F_37 ( V_7 ) ;
}
F_21 ( & V_24 , V_22 ) ;
}
void F_44 ( void )
{
struct V_6 * V_7 ;
unsigned long V_22 ;
F_16 ( & V_24 , V_22 ) ;
V_7 = V_3 . V_10 ;
if ( V_7 )
F_37 ( V_7 ) ;
F_21 ( & V_24 , V_22 ) ;
}
int F_45 ( void )
{
struct V_6 * V_7 ;
unsigned long V_22 ;
int V_19 = 0 ;
F_16 ( & V_24 , V_22 ) ;
V_7 = V_3 . V_10 ;
if ( V_7 ) {
F_46 ( V_7 , V_49 ) ;
switch ( V_3 . V_34 ) {
case V_43 :
if ( ! F_8 ( V_5 ) )
F_4 ( V_7 ) ;
V_19 = F_25 ( F_19 () ,
V_5 ) ;
break;
case V_50 :
if ( ! F_8 ( V_5 ) )
V_19 = F_47 ( V_7 ) ;
break;
}
}
F_21 ( & V_24 , V_22 ) ;
return V_19 ;
}
struct V_4 * F_48 ( void )
{
return V_51 ;
}
int F_49 ( void )
{
return F_25 ( F_19 () , V_52 ) ;
}
static void F_50 ( struct V_6 * V_7 ,
const struct V_4 * V_4 )
{
if ( ! ( V_7 -> V_11 & V_53 ) )
return;
if ( F_51 ( V_7 -> V_4 , V_4 ) )
return;
V_7 -> V_4 = V_4 ;
F_52 ( V_7 -> V_54 , V_7 -> V_4 ) ;
}
static int F_53 ( struct V_6 * V_7 , int V_1 ,
T_1 V_55 , int V_56 )
{
int V_23 ;
if ( V_7 -> V_34 != V_57 )
F_46 ( V_7 , V_57 ) ;
V_23 = F_34 ( V_7 , V_55 , V_56 ) ;
if ( ! V_23 )
F_50 ( V_7 , F_54 ( V_1 ) ) ;
return V_23 ;
}
int F_47 ( struct V_6 * V_7 )
{
F_46 ( V_7 , V_57 ) ;
return 0 ;
}
void F_55 ( int V_1 )
{
if ( F_25 ( V_1 , V_51 ) ) {
struct V_2 * V_26 = & F_26 ( V_27 , V_1 ) ;
F_46 ( V_26 -> V_10 , V_57 ) ;
}
}
static void F_56 ( struct V_6 * V_8 )
{
struct V_2 * V_26 ;
T_1 V_58 , V_36 ;
int V_1 , V_59 = 0 ;
F_29 ( & V_24 ) ;
V_60:
V_8 -> V_36 . V_61 = V_62 ;
V_36 . V_61 = V_62 ;
F_57 ( V_31 ) ;
V_58 = F_58 () ;
F_59 (cpu, tick_broadcast_oneshot_mask) {
V_26 = & F_26 ( V_27 , V_1 ) ;
if ( V_26 -> V_10 -> V_36 . V_61 <= V_58 . V_61 ) {
F_18 ( V_1 , V_31 ) ;
F_18 ( V_1 , V_63 ) ;
} else if ( V_26 -> V_10 -> V_36 . V_61 < V_36 . V_61 ) {
V_36 . V_61 = V_26 -> V_10 -> V_36 . V_61 ;
V_59 = V_1 ;
}
}
F_20 ( F_19 () , V_63 ) ;
F_60 ( V_31 , V_31 , V_52 ) ;
F_57 ( V_52 ) ;
F_24 ( V_31 ) ;
if ( V_36 . V_61 != V_62 ) {
if ( F_53 ( V_8 , V_59 , V_36 , 0 ) )
goto V_60;
}
F_31 ( & V_24 ) ;
}
void F_61 ( unsigned long V_38 )
{
struct V_6 * V_7 , * V_8 ;
struct V_2 * V_26 ;
unsigned long V_22 ;
T_1 V_58 ;
int V_1 ;
if ( V_3 . V_34 == V_43 )
return;
V_1 = F_19 () ;
V_26 = & F_26 ( V_27 , V_1 ) ;
V_8 = V_26 -> V_10 ;
if ( ! ( V_8 -> V_11 & V_14 ) )
return;
V_7 = V_3 . V_10 ;
F_16 ( & V_24 , V_22 ) ;
if ( V_38 == V_64 ) {
if ( ! F_36 ( V_1 , V_51 ) ) {
F_62 ( F_25 ( V_1 , V_63 ) ) ;
F_46 ( V_8 , V_65 ) ;
if ( ! F_25 ( V_1 , V_52 ) &&
V_8 -> V_36 . V_61 < V_7 -> V_36 . V_61 )
F_53 ( V_7 , V_1 , V_8 -> V_36 , 1 ) ;
}
} else {
if ( F_38 ( V_1 , V_51 ) ) {
F_46 ( V_8 , V_57 ) ;
if ( F_38 ( V_1 ,
V_63 ) )
goto V_40;
if ( V_8 -> V_36 . V_61 == V_62 )
goto V_40;
V_58 = F_58 () ;
if ( V_8 -> V_36 . V_61 <= V_58 . V_61 ) {
F_18 ( V_1 , V_52 ) ;
goto V_40;
}
F_63 ( V_8 -> V_36 , 1 ) ;
}
}
V_40:
F_21 ( & V_24 , V_22 ) ;
}
static void F_1 ( int V_1 )
{
F_20 ( V_1 , V_51 ) ;
}
static void F_64 ( struct V_4 * V_18 ,
T_1 V_55 )
{
struct V_2 * V_26 ;
int V_1 ;
F_59 (cpu, mask) {
V_26 = & F_26 ( V_27 , V_1 ) ;
if ( V_26 -> V_10 )
V_26 -> V_10 -> V_36 = V_55 ;
}
}
void F_39 ( struct V_6 * V_7 )
{
int V_1 = F_19 () ;
if ( V_7 -> V_15 != F_56 ) {
int V_66 = V_7 -> V_34 == V_35 ;
V_7 -> V_15 = F_56 ;
F_65 ( V_31 , V_5 ) ;
F_20 ( V_1 , V_31 ) ;
F_60 ( V_51 ,
V_51 , V_31 ) ;
if ( V_66 && ! F_8 ( V_31 ) ) {
F_46 ( V_7 , V_57 ) ;
F_64 ( V_31 ,
V_67 ) ;
F_53 ( V_7 , V_1 , V_67 , 1 ) ;
} else
V_7 -> V_36 . V_61 = V_62 ;
} else {
F_1 ( V_1 ) ;
}
}
void F_66 ( void )
{
struct V_6 * V_7 ;
unsigned long V_22 ;
F_16 ( & V_24 , V_22 ) ;
V_3 . V_34 = V_50 ;
V_7 = V_3 . V_10 ;
if ( V_7 )
F_39 ( V_7 ) ;
F_21 ( & V_24 , V_22 ) ;
}
void F_67 ( unsigned int * V_48 )
{
unsigned long V_22 ;
unsigned int V_1 = * V_48 ;
F_16 ( & V_24 , V_22 ) ;
F_20 ( V_1 , V_51 ) ;
F_21 ( & V_24 , V_22 ) ;
}
int F_68 ( void )
{
return V_3 . V_34 == V_50 ;
}
bool F_69 ( void )
{
struct V_6 * V_7 = V_3 . V_10 ;
return V_7 ? V_7 -> V_11 & V_17 : false ;
}
void T_2 F_70 ( void )
{
F_71 ( & V_5 , V_68 ) ;
F_71 ( & V_31 , V_68 ) ;
#ifdef F_72
F_71 ( & V_51 , V_68 ) ;
F_71 ( & V_63 , V_68 ) ;
F_71 ( & V_52 , V_68 ) ;
#endif
}
