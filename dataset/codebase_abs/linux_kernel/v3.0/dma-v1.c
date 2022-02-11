static void F_1 ( unsigned V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static unsigned F_3 ( unsigned V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
if ( F_6 () )
return V_5 -> V_6 ;
else
return 0 ;
}
static inline int F_7 ( int V_7 , struct V_8 * V_9 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
unsigned long V_11 ;
if ( ! V_5 -> V_12 ) {
F_8 ( V_13 L_1 ,
V_14 , V_7 ) ;
return 0 ;
}
V_11 = F_9 ( V_5 -> V_15 , V_9 -> V_16 ) ;
if ( V_5 -> V_15 != V_17 )
V_5 -> V_15 -= V_11 ;
if ( ( V_5 -> V_18 & V_19 ) == V_20 )
F_1 ( V_9 -> V_21 , F_10 ( V_7 ) ) ;
else
F_1 ( V_9 -> V_21 , F_11 ( V_7 ) ) ;
F_1 ( V_11 , F_12 ( V_7 ) ) ;
F_13 ( L_2
L_3 , V_7 ,
F_3 ( F_10 ( V_7 ) ) ,
F_3 ( F_11 ( V_7 ) ) ,
F_3 ( F_12 ( V_7 ) ) ) ;
return V_11 ;
}
int
F_14 ( int V_7 , T_1 V_21 ,
unsigned int V_22 , unsigned int V_23 ,
unsigned int V_24 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
V_5 -> V_9 = NULL ;
V_5 -> V_18 = V_24 ;
if ( ! V_21 ) {
F_8 ( V_25 L_4 ,
V_7 ) ;
return - V_26 ;
}
if ( ! V_22 ) {
F_8 ( V_25 L_5 ,
V_7 ) ;
return - V_26 ;
}
if ( ( V_24 & V_19 ) == V_20 ) {
F_13 ( L_6
L_7 ,
V_7 , V_14 , ( unsigned int ) V_21 ,
V_22 , V_23 ) ;
F_1 ( V_23 , F_11 ( V_7 ) ) ;
F_1 ( V_21 , F_10 ( V_7 ) ) ;
F_1 ( V_5 -> V_27 , F_15 ( V_7 ) ) ;
} else if ( ( V_24 & V_19 ) == V_28 ) {
F_13 ( L_6
L_8 ,
V_7 , V_14 , ( unsigned int ) V_21 ,
V_22 , V_23 ) ;
F_1 ( V_21 , F_11 ( V_7 ) ) ;
F_1 ( V_23 , F_10 ( V_7 ) ) ;
F_1 ( V_5 -> V_29 ,
F_15 ( V_7 ) ) ;
} else {
F_8 ( V_25 L_9 ,
V_7 ) ;
return - V_26 ;
}
F_1 ( V_22 , F_12 ( V_7 ) ) ;
return 0 ;
}
int
F_16 ( int V_7 ,
struct V_8 * V_9 , unsigned int V_30 ,
unsigned int V_22 , unsigned int V_23 ,
unsigned int V_24 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
if ( V_5 -> V_31 )
return - V_32 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_18 = V_24 ;
V_5 -> V_15 = V_22 ;
if ( ! V_9 || ! V_30 ) {
F_8 ( V_25 L_10 ,
V_7 ) ;
return - V_26 ;
}
if ( ! V_9 -> V_16 ) {
F_8 ( V_25 L_11 ,
V_7 ) ;
return - V_26 ;
}
if ( ( V_24 & V_19 ) == V_20 ) {
F_13 ( L_12
L_7 ,
V_7 , V_14 , V_9 , V_30 , V_22 , V_23 ) ;
F_1 ( V_23 , F_11 ( V_7 ) ) ;
F_1 ( V_5 -> V_27 , F_15 ( V_7 ) ) ;
} else if ( ( V_24 & V_19 ) == V_28 ) {
F_13 ( L_12
L_8 ,
V_7 , V_14 , V_9 , V_30 , V_22 , V_23 ) ;
F_1 ( V_23 , F_10 ( V_7 ) ) ;
F_1 ( V_5 -> V_29 , F_15 ( V_7 ) ) ;
} else {
F_8 ( V_25 L_13 ,
V_7 ) ;
return - V_26 ;
}
F_7 ( V_7 , V_9 ) ;
return 0 ;
}
int
F_17 ( int V_7 , unsigned int V_33 ,
unsigned int V_34 , unsigned int V_35 , int V_6 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
T_2 V_36 = 0 ;
V_5 -> V_6 = 0 ;
if ( V_6 ) {
V_5 -> V_6 = 1 ;
if ( ! F_5 ( V_5 ) )
return - V_26 ;
}
if ( V_35 )
V_36 = V_37 ;
V_5 -> V_27 = V_33 | ( V_34 << 2 ) | V_36 ;
V_5 -> V_29 = V_34 | ( V_33 << 2 ) | V_36 ;
F_1 ( V_35 , F_18 ( V_7 ) ) ;
return 0 ;
}
void F_19 ( int V_7 , unsigned int V_38 )
{
F_1 ( V_38 , F_20 ( V_7 ) ) ;
}
int
F_21 ( int V_7 ,
void (* F_22) ( int , void * ) ,
void (* F_23) ( int , void * , int ) ,
void * V_39 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
unsigned long V_40 ;
if ( ! V_5 -> V_12 ) {
F_8 ( V_13 L_1 ,
V_14 , V_7 ) ;
return - V_41 ;
}
F_24 ( V_40 ) ;
F_1 ( 1 << V_7 , V_42 ) ;
V_5 -> F_22 = F_22 ;
V_5 -> F_23 = F_23 ;
V_5 -> V_39 = V_39 ;
F_25 ( V_40 ) ;
return 0 ;
}
int
F_26 ( int V_7 ,
void (* F_27) ( int , void * , struct V_8 * ) )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
unsigned long V_40 ;
if ( ! V_5 -> V_12 ) {
F_8 ( V_13 L_1 ,
V_14 , V_7 ) ;
return - V_41 ;
}
F_24 ( V_40 ) ;
V_5 -> F_27 = F_27 ;
F_25 ( V_40 ) ;
return 0 ;
}
void F_28 ( int V_7 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
unsigned long V_40 ;
F_13 ( L_14 , V_7 ) ;
if ( ! V_5 -> V_12 ) {
F_8 ( V_13 L_1 ,
V_14 , V_7 ) ;
return;
}
if ( V_5 -> V_31 )
return;
F_24 ( V_40 ) ;
F_1 ( 1 << V_7 , V_42 ) ;
F_1 ( F_3 ( V_43 ) & ~ ( 1 << V_7 ) , V_43 ) ;
F_1 ( F_3 ( F_15 ( V_7 ) ) | V_44 |
V_45 , F_15 ( V_7 ) ) ;
#ifdef F_29
if ( ( F_30 () || F_6 () ) &&
V_5 -> V_9 && F_5 ( V_5 ) ) {
V_5 -> V_9 = F_31 ( V_5 -> V_9 ) ;
if ( V_5 -> V_9 ) {
T_2 V_46 ;
F_7 ( V_7 , V_5 -> V_9 ) ;
V_46 = F_3 ( F_15 ( V_7 ) ) ;
F_1 ( V_46 | V_47 | V_45 ,
F_15 ( V_7 ) ) ;
}
}
#endif
V_5 -> V_31 = 1 ;
F_25 ( V_40 ) ;
}
void F_32 ( int V_7 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
unsigned long V_40 ;
F_13 ( L_15 , V_7 ) ;
if ( F_5 ( V_5 ) )
F_33 ( & V_5 -> V_48 ) ;
F_24 ( V_40 ) ;
F_1 ( F_3 ( V_43 ) | ( 1 << V_7 ) , V_43 ) ;
F_1 ( F_3 ( F_15 ( V_7 ) ) & ~ V_44 ,
F_15 ( V_7 ) ) ;
F_1 ( 1 << V_7 , V_42 ) ;
V_5 -> V_31 = 0 ;
F_25 ( V_40 ) ;
}
static void F_34 ( unsigned long V_49 )
{
struct V_4 * V_5 = & V_10 [ V_49 ] ;
F_1 ( 0 , F_15 ( V_49 ) ) ;
V_5 -> V_31 = 0 ;
V_5 -> V_9 = NULL ;
if ( V_5 -> F_23 )
V_5 -> F_23 ( V_49 , V_5 -> V_39 , V_50 ) ;
}
static T_3 F_35 ( int V_51 , void * V_52 )
{
int V_53 , V_54 ;
struct V_4 * V_5 ;
unsigned int V_55 ;
int V_56 ;
V_54 = F_3 ( V_42 ) ;
V_55 = F_3 ( V_57 ) |
F_3 ( V_58 ) |
F_3 ( V_59 ) |
F_3 ( V_60 ) ;
if ( ! V_55 )
return V_61 ;
F_1 ( V_54 & V_55 , V_42 ) ;
for ( V_53 = 0 ; V_53 < V_62 ; V_53 ++ ) {
if ( ! ( V_55 & ( 1 << V_53 ) ) )
continue;
V_5 = & V_10 [ V_53 ] ;
V_56 = 0 ;
if ( F_3 ( V_57 ) & ( 1 << V_53 ) ) {
F_1 ( 1 << V_53 , V_57 ) ;
V_56 |= V_63 ;
}
if ( F_3 ( V_58 ) & ( 1 << V_53 ) ) {
F_1 ( 1 << V_53 , V_58 ) ;
V_56 |= V_64 ;
}
if ( F_3 ( V_59 ) & ( 1 << V_53 ) ) {
F_1 ( 1 << V_53 , V_59 ) ;
V_56 |= V_65 ;
}
if ( F_3 ( V_60 ) & ( 1 << V_53 ) ) {
F_1 ( 1 << V_53 , V_60 ) ;
V_56 |= V_66 ;
}
if ( V_5 -> V_12 && V_5 -> F_23 ) {
V_5 -> F_23 ( V_53 , V_5 -> V_39 , V_56 ) ;
continue;
}
V_10 [ V_53 ] . V_9 = NULL ;
F_8 ( V_67
L_16 ,
V_53 , V_5 -> V_12 ,
V_56 & V_63 ? L_17 : L_18 ,
V_56 & V_64 ? L_19 : L_18 ,
V_56 & V_65 ? L_20 : L_18 ,
V_56 & V_66 ? L_21 : L_18 ) ;
}
return V_61 ;
}
static void F_36 ( int V_49 )
{
struct V_4 * V_5 = & V_10 [ V_49 ] ;
if ( ! V_5 -> V_12 ) {
F_8 ( V_67
L_22 , V_49 ) ;
return;
}
if ( V_5 -> V_9 ) {
T_2 V_46 ;
struct V_8 * V_68 = V_5 -> V_9 ;
V_5 -> V_9 = F_31 ( V_5 -> V_9 ) ;
if ( V_5 -> V_9 ) {
F_7 ( V_49 , V_5 -> V_9 ) ;
V_46 = F_3 ( F_15 ( V_49 ) ) ;
if ( F_5 ( V_5 ) ) {
F_37 ( & V_5 -> V_48 ,
V_69 + F_38 ( 500 ) ) ;
V_46 |= V_44 | V_47 | V_45 ;
F_1 ( V_46 , F_15 ( V_49 ) ) ;
} else {
F_1 ( V_46 & ~ V_44 , F_15 ( V_49 ) ) ;
V_46 |= V_44 ;
}
F_1 ( V_46 , F_15 ( V_49 ) ) ;
if ( V_5 -> F_27 )
V_5 -> F_27 ( V_49 , V_5 -> V_39 ,
V_68 ) ;
return;
}
if ( F_5 ( V_5 ) ) {
F_33 ( & V_5 -> V_48 ) ;
return;
}
}
F_1 ( 0 , F_15 ( V_49 ) ) ;
V_5 -> V_31 = 0 ;
if ( V_5 -> F_22 )
V_5 -> F_22 ( V_49 , V_5 -> V_39 ) ;
}
static T_3 F_39 ( int V_51 , void * V_52 )
{
int V_53 , V_54 ;
#ifdef F_29
if ( F_30 () || F_6 () )
F_35 ( V_51 , V_52 ) ;
#endif
V_54 = F_3 ( V_42 ) ;
F_13 ( L_23 ,
V_54 ) ;
F_1 ( V_54 , V_42 ) ;
for ( V_53 = 0 ; V_53 < V_62 ; V_53 ++ ) {
if ( V_54 & ( 1 << V_53 ) )
F_36 ( V_53 ) ;
}
return V_61 ;
}
int F_40 ( int V_7 , const char * V_12 )
{
struct V_4 * V_5 = & V_10 [ V_7 ] ;
unsigned long V_40 ;
int V_70 = 0 ;
if ( ! V_12 )
return - V_26 ;
if ( V_7 >= V_62 ) {
F_8 ( V_13 L_24 ,
V_14 , V_7 ) ;
return - V_26 ;
}
F_24 ( V_40 ) ;
if ( V_5 -> V_12 ) {
F_25 ( V_40 ) ;
return - V_32 ;
}
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_12 = V_12 ;
F_25 ( V_40 ) ;
#ifdef F_29
if ( F_30 () || F_6 () ) {
V_70 = F_41 ( V_71 + V_7 ,
F_39 , 0 , L_25 , NULL ) ;
if ( V_70 ) {
V_5 -> V_12 = NULL ;
F_42 ( L_26 ,
V_71 + V_7 , V_7 ) ;
return V_70 ;
}
F_43 ( & V_5 -> V_48 ) ;
V_5 -> V_48 . V_72 = & F_34 ;
V_5 -> V_48 . V_39 = V_7 ;
}
#endif
return V_70 ;
}
void F_44 ( int V_7 )
{
unsigned long V_40 ;
struct V_4 * V_5 = & V_10 [ V_7 ] ;
if ( ! V_5 -> V_12 ) {
F_8 ( V_13
L_27 ,
V_14 , V_7 ) ;
return;
}
F_24 ( V_40 ) ;
F_32 ( V_7 ) ;
V_5 -> V_12 = NULL ;
#ifdef F_29
if ( F_30 () || F_6 () )
F_45 ( V_71 + V_7 , NULL ) ;
#endif
F_25 ( V_40 ) ;
}
int F_46 ( const char * V_12 , enum V_73 V_74 )
{
int V_53 ;
int V_75 ;
switch ( V_74 ) {
case ( V_76 ) :
V_75 = 8 ;
break;
case ( V_77 ) :
V_75 = 4 ;
break;
case ( V_78 ) :
default:
V_75 = 0 ;
break;
}
for ( V_53 = V_75 ; V_53 < V_62 ; V_53 ++ )
if ( ! F_40 ( V_53 , V_12 ) )
return V_53 ;
for ( V_53 = V_75 - 1 ; V_53 >= 0 ; V_53 -- )
if ( ! F_40 ( V_53 , V_12 ) )
return V_53 ;
F_8 ( V_25 L_28 , V_14 ) ;
return - V_41 ;
}
static int T_4 F_47 ( void )
{
int V_70 = 0 ;
int V_53 ;
#ifdef F_48
if ( F_49 () )
V_3 = F_50 ( V_79 ) ;
else
#endif
#ifdef F_51
if ( F_30 () )
V_3 = F_52 ( V_80 ) ;
else
#endif
#ifdef F_53
if ( F_6 () )
V_3 = F_54 ( V_81 ) ;
else
#endif
return 0 ;
V_82 = F_55 ( NULL , L_29 ) ;
if ( F_56 ( V_82 ) )
return F_57 ( V_82 ) ;
F_58 ( V_82 ) ;
F_1 ( V_83 , V_84 ) ;
#ifdef F_48
if ( F_49 () ) {
V_70 = F_41 ( V_85 , F_39 , 0 , L_25 , NULL ) ;
if ( V_70 ) {
F_42 ( L_30 ) ;
return V_70 ;
}
V_70 = F_41 ( V_86 , F_35 , 0 , L_25 , NULL ) ;
if ( V_70 ) {
F_42 ( L_31 ) ;
F_45 ( V_85 , NULL ) ;
return V_70 ;
}
}
#endif
F_1 ( V_87 , V_84 ) ;
F_1 ( ( 1 << V_62 ) - 1 , V_42 ) ;
F_1 ( ( 1 << V_62 ) - 1 , V_43 ) ;
for ( V_53 = 0 ; V_53 < V_62 ; V_53 ++ ) {
V_10 [ V_53 ] . V_9 = NULL ;
V_10 [ V_53 ] . V_88 = V_53 ;
}
return V_70 ;
}
