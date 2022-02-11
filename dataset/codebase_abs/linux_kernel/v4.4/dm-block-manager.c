static unsigned F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_2 -> V_7 [ V_5 ] == V_4 )
break;
F_2 ( V_5 == V_6 ) ;
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned V_8 = F_1 ( V_2 , NULL ) ;
#ifdef F_4
struct V_9 * V_10 ;
#endif
F_5 ( V_4 ) ;
V_2 -> V_7 [ V_8 ] = V_4 ;
#ifdef F_4
V_10 = V_2 -> V_11 + V_8 ;
V_10 -> V_12 = 0 ;
V_10 -> V_13 = V_14 ;
V_10 -> V_15 = V_2 -> V_15 [ V_8 ] ;
V_10 -> V_16 = 2 ;
F_6 ( V_10 ) ;
#endif
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned V_8 = F_1 ( V_2 , V_4 ) ;
V_2 -> V_7 [ V_8 ] = NULL ;
F_8 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned V_5 ;
#ifdef F_4
static struct V_9 V_10 ;
static T_1 V_15 ;
#endif
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] == V_17 ) {
F_10 ( L_1 ) ;
#ifdef F_4
F_10 ( L_2 ) ;
F_11 ( V_2 -> V_11 + V_5 , 4 ) ;
F_10 ( L_3 ) ;
V_10 . V_12 = 0 ;
V_10 . V_13 = V_14 ;
V_10 . V_15 = V_15 ;
V_10 . V_16 = 3 ;
F_6 ( & V_10 ) ;
F_11 ( & V_10 , 4 ) ;
#endif
return - V_18 ;
}
}
return 0 ;
}
static void F_12 ( struct V_19 * V_20 )
{
for (; ; ) {
F_13 ( V_17 , V_21 ) ;
if ( ! V_20 -> V_4 )
break;
F_14 () ;
}
F_13 ( V_17 , V_22 ) ;
}
static void F_15 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
F_16 ( & V_20 -> V_23 ) ;
V_4 = V_20 -> V_4 ;
F_17 () ;
V_20 -> V_4 = NULL ;
F_18 ( V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_24 ;
F_2 ( V_2 -> V_25 < 0 ) ;
F_20 (w, tmp, &lock->waiters, list) {
if ( V_2 -> V_25 >= V_6 )
return;
if ( V_20 -> V_26 ) {
if ( V_2 -> V_25 > 0 )
return;
V_2 -> V_25 = - 1 ;
F_3 ( V_2 , V_20 -> V_4 ) ;
F_15 ( V_20 ) ;
return;
}
V_2 -> V_25 ++ ;
F_3 ( V_2 , V_20 -> V_4 ) ;
F_15 ( V_20 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
int V_5 ;
F_22 ( & V_2 -> V_2 ) ;
V_2 -> V_25 = 0 ;
F_23 ( & V_2 -> V_27 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
V_2 -> V_7 [ V_5 ] = NULL ;
}
static int F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_25 >= 0 &&
V_2 -> V_25 < V_6 &&
F_25 ( & V_2 -> V_27 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_19 V_20 ;
F_27 ( & V_2 -> V_2 ) ;
V_28 = F_9 ( V_2 ) ;
if ( V_28 ) {
F_28 ( & V_2 -> V_2 ) ;
return V_28 ;
}
if ( F_24 ( V_2 ) ) {
V_2 -> V_25 ++ ;
F_3 ( V_2 , V_17 ) ;
F_28 ( & V_2 -> V_2 ) ;
return 0 ;
}
F_5 ( V_17 ) ;
V_20 . V_4 = V_17 ;
V_20 . V_26 = 0 ;
F_29 ( & V_20 . V_23 , & V_2 -> V_27 ) ;
F_28 ( & V_2 -> V_2 ) ;
F_12 ( & V_20 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_28 ;
F_27 ( & V_2 -> V_2 ) ;
V_28 = F_9 ( V_2 ) ;
if ( V_28 )
goto V_29;
if ( F_24 ( V_2 ) ) {
V_2 -> V_25 ++ ;
F_3 ( V_2 , V_17 ) ;
V_28 = 0 ;
} else
V_28 = - V_30 ;
V_29:
F_28 ( & V_2 -> V_2 ) ;
return V_28 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_2 ) ;
F_2 ( V_2 -> V_25 <= 0 ) ;
F_7 ( V_2 , V_17 ) ;
-- V_2 -> V_25 ;
if ( ! F_25 ( & V_2 -> V_27 ) )
F_19 ( V_2 ) ;
F_28 ( & V_2 -> V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_19 V_20 ;
F_27 ( & V_2 -> V_2 ) ;
V_28 = F_9 ( V_2 ) ;
if ( V_28 ) {
F_28 ( & V_2 -> V_2 ) ;
return V_28 ;
}
if ( V_2 -> V_25 == 0 && F_25 ( & V_2 -> V_27 ) ) {
V_2 -> V_25 = - 1 ;
F_3 ( V_2 , V_17 ) ;
F_28 ( & V_2 -> V_2 ) ;
return 0 ;
}
F_5 ( V_17 ) ;
V_20 . V_4 = V_17 ;
V_20 . V_26 = 1 ;
F_33 ( & V_20 . V_23 , & V_2 -> V_27 ) ;
F_28 ( & V_2 -> V_2 ) ;
F_12 ( & V_20 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_2 ) ;
F_7 ( V_2 , V_17 ) ;
V_2 -> V_25 = 0 ;
if ( ! F_25 ( & V_2 -> V_27 ) )
F_19 ( V_2 ) ;
F_28 ( & V_2 -> V_2 ) ;
}
static void F_35 ( T_2 V_31 , int V_28 )
{
if ( V_28 == - V_18 )
F_10 ( L_4 ,
( unsigned long long ) V_31 ) ;
}
static struct V_32 * F_36 ( struct V_33 * V_31 )
{
return (struct V_32 * ) V_31 ;
}
T_2 F_37 ( struct V_33 * V_31 )
{
return F_38 ( F_36 ( V_31 ) ) ;
}
void * F_39 ( struct V_33 * V_31 )
{
return F_40 ( F_36 ( V_31 ) ) ;
}
static void F_41 ( struct V_32 * V_34 )
{
struct V_35 * V_36 = F_42 ( V_34 ) ;
V_36 -> V_37 = NULL ;
F_21 ( & V_36 -> V_2 ) ;
}
static void F_43 ( struct V_32 * V_34 )
{
struct V_35 * V_36 = F_42 ( V_34 ) ;
if ( V_36 -> V_37 ) {
V_36 -> V_37 -> V_38 ( V_36 -> V_37 , (struct V_33 * ) V_34 ,
F_44 ( F_45 ( V_34 ) ) ) ;
}
}
struct V_39 * F_46 ( struct V_40 * V_41 ,
unsigned V_42 ,
unsigned V_43 ,
unsigned V_44 )
{
int V_28 ;
struct V_39 * V_45 ;
V_45 = F_47 ( sizeof( * V_45 ) , V_46 ) ;
if ( ! V_45 ) {
V_28 = - V_47 ;
goto V_48;
}
V_45 -> V_49 = F_48 ( V_41 , V_42 , V_44 ,
sizeof( struct V_35 ) ,
F_41 ,
F_43 ) ;
if ( F_49 ( V_45 -> V_49 ) ) {
V_28 = F_50 ( V_45 -> V_49 ) ;
F_51 ( V_45 ) ;
goto V_48;
}
V_45 -> V_50 = false ;
return V_45 ;
V_48:
return F_52 ( V_28 ) ;
}
void F_53 ( struct V_39 * V_45 )
{
F_54 ( V_45 -> V_49 ) ;
F_51 ( V_45 ) ;
}
unsigned F_55 ( struct V_39 * V_45 )
{
return F_44 ( V_45 -> V_49 ) ;
}
T_2 F_56 ( struct V_39 * V_45 )
{
return F_57 ( V_45 -> V_49 ) ;
}
static int F_58 ( struct V_39 * V_45 ,
struct V_32 * V_34 ,
struct V_35 * V_36 ,
struct V_51 * V_52 )
{
if ( F_59 ( ! V_36 -> V_37 ) ) {
int V_28 ;
if ( ! V_52 )
return 0 ;
V_28 = V_52 -> V_53 ( V_52 , (struct V_33 * ) V_34 , F_44 ( V_45 -> V_49 ) ) ;
if ( F_59 ( V_28 ) ) {
F_60 ( L_5 , V_52 -> V_54 ,
( unsigned long long ) F_38 ( V_34 ) ) ;
return V_28 ;
}
V_36 -> V_37 = V_52 ;
} else {
if ( F_59 ( V_36 -> V_37 != V_52 ) ) {
F_60 ( L_6 ,
V_36 -> V_37 -> V_54 , V_52 ? V_52 -> V_54 : L_7 ,
( unsigned long long ) F_38 ( V_34 ) ) ;
return - V_18 ;
}
}
return 0 ;
}
int F_61 ( struct V_39 * V_45 , T_2 V_31 ,
struct V_51 * V_52 ,
struct V_33 * * V_55 )
{
struct V_35 * V_36 ;
void * V_56 ;
int V_28 ;
V_56 = F_62 ( V_45 -> V_49 , V_31 , (struct V_32 * * ) V_55 ) ;
if ( F_49 ( V_56 ) )
return F_50 ( V_56 ) ;
V_36 = F_42 ( F_36 ( * V_55 ) ) ;
V_28 = F_26 ( & V_36 -> V_2 ) ;
if ( F_59 ( V_28 ) ) {
F_63 ( F_36 ( * V_55 ) ) ;
F_35 ( V_31 , V_28 ) ;
return V_28 ;
}
V_36 -> V_57 = 0 ;
V_28 = F_58 ( V_45 , F_36 ( * V_55 ) , V_36 , V_52 ) ;
if ( F_59 ( V_28 ) ) {
F_31 ( & V_36 -> V_2 ) ;
F_63 ( F_36 ( * V_55 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_64 ( struct V_39 * V_45 ,
T_2 V_31 , struct V_51 * V_52 ,
struct V_33 * * V_55 )
{
struct V_35 * V_36 ;
void * V_56 ;
int V_28 ;
if ( V_45 -> V_50 )
return - V_58 ;
V_56 = F_62 ( V_45 -> V_49 , V_31 , (struct V_32 * * ) V_55 ) ;
if ( F_49 ( V_56 ) )
return F_50 ( V_56 ) ;
V_36 = F_42 ( F_36 ( * V_55 ) ) ;
V_28 = F_32 ( & V_36 -> V_2 ) ;
if ( V_28 ) {
F_63 ( F_36 ( * V_55 ) ) ;
F_35 ( V_31 , V_28 ) ;
return V_28 ;
}
V_36 -> V_57 = 1 ;
V_28 = F_58 ( V_45 , F_36 ( * V_55 ) , V_36 , V_52 ) ;
if ( F_59 ( V_28 ) ) {
F_34 ( & V_36 -> V_2 ) ;
F_63 ( F_36 ( * V_55 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_65 ( struct V_39 * V_45 ,
T_2 V_31 , struct V_51 * V_52 ,
struct V_33 * * V_55 )
{
struct V_35 * V_36 ;
void * V_56 ;
int V_28 ;
V_56 = F_66 ( V_45 -> V_49 , V_31 , (struct V_32 * * ) V_55 ) ;
if ( F_49 ( V_56 ) )
return F_50 ( V_56 ) ;
if ( F_59 ( ! V_56 ) )
return - V_30 ;
V_36 = F_42 ( F_36 ( * V_55 ) ) ;
V_28 = F_30 ( & V_36 -> V_2 ) ;
if ( V_28 < 0 ) {
F_63 ( F_36 ( * V_55 ) ) ;
F_35 ( V_31 , V_28 ) ;
return V_28 ;
}
V_36 -> V_57 = 0 ;
V_28 = F_58 ( V_45 , F_36 ( * V_55 ) , V_36 , V_52 ) ;
if ( F_59 ( V_28 ) ) {
F_31 ( & V_36 -> V_2 ) ;
F_63 ( F_36 ( * V_55 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_67 ( struct V_39 * V_45 ,
T_2 V_31 , struct V_51 * V_52 ,
struct V_33 * * V_55 )
{
int V_28 ;
struct V_35 * V_36 ;
void * V_56 ;
if ( V_45 -> V_50 )
return - V_58 ;
V_56 = F_68 ( V_45 -> V_49 , V_31 , (struct V_32 * * ) V_55 ) ;
if ( F_49 ( V_56 ) )
return F_50 ( V_56 ) ;
memset ( V_56 , 0 , F_55 ( V_45 ) ) ;
V_36 = F_42 ( F_36 ( * V_55 ) ) ;
V_28 = F_32 ( & V_36 -> V_2 ) ;
if ( V_28 ) {
F_63 ( F_36 ( * V_55 ) ) ;
return V_28 ;
}
V_36 -> V_57 = 1 ;
V_36 -> V_37 = V_52 ;
return 0 ;
}
void F_69 ( struct V_33 * V_31 )
{
struct V_35 * V_36 ;
V_36 = F_42 ( F_36 ( V_31 ) ) ;
if ( V_36 -> V_57 ) {
F_70 ( F_36 ( V_31 ) ) ;
F_34 ( & V_36 -> V_2 ) ;
} else
F_31 ( & V_36 -> V_2 ) ;
F_63 ( F_36 ( V_31 ) ) ;
}
int F_71 ( struct V_39 * V_45 )
{
if ( V_45 -> V_50 )
return - V_58 ;
return F_72 ( V_45 -> V_49 ) ;
}
void F_73 ( struct V_39 * V_45 , T_2 V_31 )
{
F_74 ( V_45 -> V_49 , V_31 , 1 ) ;
}
bool F_75 ( struct V_39 * V_45 )
{
return V_45 -> V_50 ;
}
void F_76 ( struct V_39 * V_45 )
{
V_45 -> V_50 = true ;
}
void F_77 ( struct V_39 * V_45 )
{
V_45 -> V_50 = false ;
}
T_3 F_78 ( const void * V_59 , T_4 V_60 , T_3 V_61 )
{
return F_79 ( ~ ( T_3 ) 0 , V_59 , V_60 ) ^ V_61 ;
}
