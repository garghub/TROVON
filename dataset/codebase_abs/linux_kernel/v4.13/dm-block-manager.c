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
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] == V_17 ) {
F_10 ( L_1 ) ;
#ifdef F_4
F_10 ( L_2 ) ;
F_11 ( V_2 -> V_11 + V_5 , 4 ) ;
F_10 ( L_3 ) ;
F_12 () ;
#endif
return - V_18 ;
}
}
return 0 ;
}
static void F_13 ( struct V_19 * V_20 )
{
for (; ; ) {
F_14 ( V_21 ) ;
if ( ! V_20 -> V_4 )
break;
F_15 () ;
}
F_14 ( V_22 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
F_17 ( & V_20 -> V_23 ) ;
V_4 = V_20 -> V_4 ;
F_18 () ;
V_20 -> V_4 = NULL ;
F_19 ( V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_24 ;
F_2 ( V_2 -> V_25 < 0 ) ;
F_21 (w, tmp, &lock->waiters, list) {
if ( V_2 -> V_25 >= V_6 )
return;
if ( V_20 -> V_26 ) {
if ( V_2 -> V_25 > 0 )
return;
V_2 -> V_25 = - 1 ;
F_3 ( V_2 , V_20 -> V_4 ) ;
F_16 ( V_20 ) ;
return;
}
V_2 -> V_25 ++ ;
F_3 ( V_2 , V_20 -> V_4 ) ;
F_16 ( V_20 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
int V_5 ;
F_23 ( & V_2 -> V_2 ) ;
V_2 -> V_25 = 0 ;
F_24 ( & V_2 -> V_27 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
V_2 -> V_7 [ V_5 ] = NULL ;
}
static int F_25 ( struct V_1 * V_2 )
{
return V_2 -> V_25 >= 0 &&
V_2 -> V_25 < V_6 &&
F_26 ( & V_2 -> V_27 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_19 V_20 ;
F_28 ( & V_2 -> V_2 ) ;
V_28 = F_9 ( V_2 ) ;
if ( V_28 ) {
F_29 ( & V_2 -> V_2 ) ;
return V_28 ;
}
if ( F_25 ( V_2 ) ) {
V_2 -> V_25 ++ ;
F_3 ( V_2 , V_17 ) ;
F_29 ( & V_2 -> V_2 ) ;
return 0 ;
}
F_5 ( V_17 ) ;
V_20 . V_4 = V_17 ;
V_20 . V_26 = 0 ;
F_30 ( & V_20 . V_23 , & V_2 -> V_27 ) ;
F_29 ( & V_2 -> V_2 ) ;
F_13 ( & V_20 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_28 ;
F_28 ( & V_2 -> V_2 ) ;
V_28 = F_9 ( V_2 ) ;
if ( V_28 )
goto V_29;
if ( F_25 ( V_2 ) ) {
V_2 -> V_25 ++ ;
F_3 ( V_2 , V_17 ) ;
V_28 = 0 ;
} else
V_28 = - V_30 ;
V_29:
F_29 ( & V_2 -> V_2 ) ;
return V_28 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_2 ) ;
F_2 ( V_2 -> V_25 <= 0 ) ;
F_7 ( V_2 , V_17 ) ;
-- V_2 -> V_25 ;
if ( ! F_26 ( & V_2 -> V_27 ) )
F_20 ( V_2 ) ;
F_29 ( & V_2 -> V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_19 V_20 ;
F_28 ( & V_2 -> V_2 ) ;
V_28 = F_9 ( V_2 ) ;
if ( V_28 ) {
F_29 ( & V_2 -> V_2 ) ;
return V_28 ;
}
if ( V_2 -> V_25 == 0 && F_26 ( & V_2 -> V_27 ) ) {
V_2 -> V_25 = - 1 ;
F_3 ( V_2 , V_17 ) ;
F_29 ( & V_2 -> V_2 ) ;
return 0 ;
}
F_5 ( V_17 ) ;
V_20 . V_4 = V_17 ;
V_20 . V_26 = 1 ;
F_34 ( & V_20 . V_23 , & V_2 -> V_27 ) ;
F_29 ( & V_2 -> V_2 ) ;
F_13 ( & V_20 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_2 ) ;
F_7 ( V_2 , V_17 ) ;
V_2 -> V_25 = 0 ;
if ( ! F_26 ( & V_2 -> V_27 ) )
F_20 ( V_2 ) ;
F_29 ( & V_2 -> V_2 ) ;
}
static void F_36 ( T_1 V_31 , int V_28 )
{
if ( V_28 == - V_18 )
F_10 ( L_4 ,
( unsigned long long ) V_31 ) ;
}
static struct V_32 * F_37 ( struct V_33 * V_31 )
{
return (struct V_32 * ) V_31 ;
}
T_1 F_38 ( struct V_33 * V_31 )
{
return F_39 ( F_37 ( V_31 ) ) ;
}
void * F_40 ( struct V_33 * V_31 )
{
return F_41 ( F_37 ( V_31 ) ) ;
}
static void F_42 ( struct V_32 * V_34 )
{
struct V_35 * V_36 = F_43 ( V_34 ) ;
V_36 -> V_37 = NULL ;
F_22 ( & V_36 -> V_2 ) ;
}
static void F_44 ( struct V_32 * V_34 )
{
struct V_35 * V_36 = F_43 ( V_34 ) ;
if ( V_36 -> V_37 ) {
V_36 -> V_37 -> V_38 ( V_36 -> V_37 , (struct V_33 * ) V_34 ,
F_45 ( F_46 ( V_34 ) ) ) ;
}
}
struct V_39 * F_47 ( struct V_40 * V_41 ,
unsigned V_42 ,
unsigned V_43 )
{
int V_28 ;
struct V_39 * V_44 ;
V_44 = F_48 ( sizeof( * V_44 ) , V_45 ) ;
if ( ! V_44 ) {
V_28 = - V_46 ;
goto V_47;
}
V_44 -> V_48 = F_49 ( V_41 , V_42 , V_43 ,
sizeof( struct V_35 ) ,
F_42 ,
F_44 ) ;
if ( F_50 ( V_44 -> V_48 ) ) {
V_28 = F_51 ( V_44 -> V_48 ) ;
F_52 ( V_44 ) ;
goto V_47;
}
V_44 -> V_49 = false ;
return V_44 ;
V_47:
return F_53 ( V_28 ) ;
}
void F_54 ( struct V_39 * V_44 )
{
F_55 ( V_44 -> V_48 ) ;
F_52 ( V_44 ) ;
}
unsigned F_56 ( struct V_39 * V_44 )
{
return F_45 ( V_44 -> V_48 ) ;
}
T_1 F_57 ( struct V_39 * V_44 )
{
return F_58 ( V_44 -> V_48 ) ;
}
static int F_59 ( struct V_39 * V_44 ,
struct V_32 * V_34 ,
struct V_35 * V_36 ,
struct V_50 * V_51 )
{
if ( F_60 ( ! V_36 -> V_37 ) ) {
int V_28 ;
if ( ! V_51 )
return 0 ;
V_28 = V_51 -> V_52 ( V_51 , (struct V_33 * ) V_34 , F_45 ( V_44 -> V_48 ) ) ;
if ( F_60 ( V_28 ) ) {
F_61 ( L_5 , V_51 -> V_53 ,
( unsigned long long ) F_39 ( V_34 ) ) ;
return V_28 ;
}
V_36 -> V_37 = V_51 ;
} else {
if ( F_60 ( V_36 -> V_37 != V_51 ) ) {
F_61 ( L_6 ,
V_36 -> V_37 -> V_53 , V_51 ? V_51 -> V_53 : L_7 ,
( unsigned long long ) F_39 ( V_34 ) ) ;
return - V_18 ;
}
}
return 0 ;
}
int F_62 ( struct V_39 * V_44 , T_1 V_31 ,
struct V_50 * V_51 ,
struct V_33 * * V_54 )
{
struct V_35 * V_36 ;
void * V_55 ;
int V_28 ;
V_55 = F_63 ( V_44 -> V_48 , V_31 , (struct V_32 * * ) V_54 ) ;
if ( F_60 ( F_50 ( V_55 ) ) )
return F_51 ( V_55 ) ;
V_36 = F_43 ( F_37 ( * V_54 ) ) ;
V_28 = F_27 ( & V_36 -> V_2 ) ;
if ( F_60 ( V_28 ) ) {
F_64 ( F_37 ( * V_54 ) ) ;
F_36 ( V_31 , V_28 ) ;
return V_28 ;
}
V_36 -> V_56 = 0 ;
V_28 = F_59 ( V_44 , F_37 ( * V_54 ) , V_36 , V_51 ) ;
if ( F_60 ( V_28 ) ) {
F_32 ( & V_36 -> V_2 ) ;
F_64 ( F_37 ( * V_54 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_65 ( struct V_39 * V_44 ,
T_1 V_31 , struct V_50 * V_51 ,
struct V_33 * * V_54 )
{
struct V_35 * V_36 ;
void * V_55 ;
int V_28 ;
if ( V_44 -> V_49 )
return - V_57 ;
V_55 = F_63 ( V_44 -> V_48 , V_31 , (struct V_32 * * ) V_54 ) ;
if ( F_60 ( F_50 ( V_55 ) ) )
return F_51 ( V_55 ) ;
V_36 = F_43 ( F_37 ( * V_54 ) ) ;
V_28 = F_33 ( & V_36 -> V_2 ) ;
if ( V_28 ) {
F_64 ( F_37 ( * V_54 ) ) ;
F_36 ( V_31 , V_28 ) ;
return V_28 ;
}
V_36 -> V_56 = 1 ;
V_28 = F_59 ( V_44 , F_37 ( * V_54 ) , V_36 , V_51 ) ;
if ( F_60 ( V_28 ) ) {
F_35 ( & V_36 -> V_2 ) ;
F_64 ( F_37 ( * V_54 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_66 ( struct V_39 * V_44 ,
T_1 V_31 , struct V_50 * V_51 ,
struct V_33 * * V_54 )
{
struct V_35 * V_36 ;
void * V_55 ;
int V_28 ;
V_55 = F_67 ( V_44 -> V_48 , V_31 , (struct V_32 * * ) V_54 ) ;
if ( F_60 ( F_50 ( V_55 ) ) )
return F_51 ( V_55 ) ;
if ( F_60 ( ! V_55 ) )
return - V_30 ;
V_36 = F_43 ( F_37 ( * V_54 ) ) ;
V_28 = F_31 ( & V_36 -> V_2 ) ;
if ( V_28 < 0 ) {
F_64 ( F_37 ( * V_54 ) ) ;
F_36 ( V_31 , V_28 ) ;
return V_28 ;
}
V_36 -> V_56 = 0 ;
V_28 = F_59 ( V_44 , F_37 ( * V_54 ) , V_36 , V_51 ) ;
if ( F_60 ( V_28 ) ) {
F_32 ( & V_36 -> V_2 ) ;
F_64 ( F_37 ( * V_54 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_68 ( struct V_39 * V_44 ,
T_1 V_31 , struct V_50 * V_51 ,
struct V_33 * * V_54 )
{
int V_28 ;
struct V_35 * V_36 ;
void * V_55 ;
if ( V_44 -> V_49 )
return - V_57 ;
V_55 = F_69 ( V_44 -> V_48 , V_31 , (struct V_32 * * ) V_54 ) ;
if ( F_60 ( F_50 ( V_55 ) ) )
return F_51 ( V_55 ) ;
memset ( V_55 , 0 , F_56 ( V_44 ) ) ;
V_36 = F_43 ( F_37 ( * V_54 ) ) ;
V_28 = F_33 ( & V_36 -> V_2 ) ;
if ( V_28 ) {
F_64 ( F_37 ( * V_54 ) ) ;
return V_28 ;
}
V_36 -> V_56 = 1 ;
V_36 -> V_37 = V_51 ;
return 0 ;
}
void F_70 ( struct V_33 * V_31 )
{
struct V_35 * V_36 ;
V_36 = F_43 ( F_37 ( V_31 ) ) ;
if ( V_36 -> V_56 ) {
F_71 ( F_37 ( V_31 ) ) ;
F_35 ( & V_36 -> V_2 ) ;
} else
F_32 ( & V_36 -> V_2 ) ;
F_64 ( F_37 ( V_31 ) ) ;
}
int F_72 ( struct V_39 * V_44 )
{
if ( V_44 -> V_49 )
return - V_57 ;
return F_73 ( V_44 -> V_48 ) ;
}
void F_74 ( struct V_39 * V_44 , T_1 V_31 )
{
F_75 ( V_44 -> V_48 , V_31 , 1 ) ;
}
bool F_76 ( struct V_39 * V_44 )
{
return V_44 -> V_49 ;
}
void F_77 ( struct V_39 * V_44 )
{
V_44 -> V_49 = true ;
}
void F_78 ( struct V_39 * V_44 )
{
V_44 -> V_49 = false ;
}
T_2 F_79 ( const void * V_58 , T_3 V_59 , T_2 V_60 )
{
return F_80 ( ~ ( T_2 ) 0 , V_58 , V_59 ) ^ V_60 ;
}
