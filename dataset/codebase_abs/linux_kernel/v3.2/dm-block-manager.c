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
static struct V_34 * F_37 ( struct V_35 * V_36 )
{
return (struct V_34 * ) V_36 ;
}
T_2 F_38 ( struct V_33 * V_31 )
{
return F_39 ( F_36 ( V_31 ) ) ;
}
void * F_40 ( struct V_33 * V_31 )
{
return F_41 ( F_36 ( V_31 ) ) ;
}
static void F_42 ( struct V_32 * V_37 )
{
struct V_38 * V_39 = F_43 ( V_37 ) ;
V_39 -> V_40 = NULL ;
F_21 ( & V_39 -> V_2 ) ;
}
static void F_44 ( struct V_32 * V_37 )
{
struct V_38 * V_39 = F_43 ( V_37 ) ;
if ( V_39 -> V_40 ) {
V_39 -> V_40 -> V_41 ( V_39 -> V_40 , (struct V_33 * ) V_37 ,
F_45 ( F_46 ( V_37 ) ) ) ;
}
}
struct V_35 * F_47 ( struct V_42 * V_43 ,
unsigned V_44 ,
unsigned V_45 ,
unsigned V_46 )
{
return (struct V_35 * )
F_48 ( V_43 , V_44 , V_46 ,
sizeof( struct V_38 ) ,
F_42 ,
F_44 ) ;
}
void F_49 ( struct V_35 * V_36 )
{
return F_50 ( F_37 ( V_36 ) ) ;
}
unsigned F_51 ( struct V_35 * V_36 )
{
return F_45 ( F_37 ( V_36 ) ) ;
}
T_2 F_52 ( struct V_35 * V_36 )
{
return F_53 ( F_37 ( V_36 ) ) ;
}
static int F_54 ( struct V_35 * V_36 ,
struct V_32 * V_37 ,
struct V_38 * V_39 ,
struct V_47 * V_48 )
{
if ( F_55 ( ! V_39 -> V_40 ) ) {
int V_28 ;
if ( ! V_48 )
return 0 ;
V_28 = V_48 -> V_49 ( V_48 , (struct V_33 * ) V_37 , F_45 ( F_37 ( V_36 ) ) ) ;
if ( F_55 ( V_28 ) )
return V_28 ;
V_39 -> V_40 = V_48 ;
} else {
if ( F_55 ( V_39 -> V_40 != V_48 ) ) {
F_10 ( L_5 ,
V_39 -> V_40 -> V_50 , V_48 ? V_48 -> V_50 : L_6 ,
( unsigned long long )
F_39 ( V_37 ) ) ;
return - V_18 ;
}
}
return 0 ;
}
int F_56 ( struct V_35 * V_36 , T_2 V_31 ,
struct V_47 * V_48 ,
struct V_33 * * V_51 )
{
struct V_38 * V_39 ;
void * V_52 ;
int V_28 ;
V_52 = F_57 ( F_37 ( V_36 ) , V_31 , (struct V_32 * * ) V_51 ) ;
if ( F_55 ( F_58 ( V_52 ) ) )
return F_59 ( V_52 ) ;
V_39 = F_43 ( F_36 ( * V_51 ) ) ;
V_28 = F_26 ( & V_39 -> V_2 ) ;
if ( F_55 ( V_28 ) ) {
F_60 ( F_36 ( * V_51 ) ) ;
F_35 ( V_31 , V_28 ) ;
return V_28 ;
}
V_39 -> V_53 = 0 ;
V_28 = F_54 ( V_36 , F_36 ( * V_51 ) , V_39 , V_48 ) ;
if ( F_55 ( V_28 ) ) {
F_31 ( & V_39 -> V_2 ) ;
F_60 ( F_36 ( * V_51 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_61 ( struct V_35 * V_36 ,
T_2 V_31 , struct V_47 * V_48 ,
struct V_33 * * V_51 )
{
struct V_38 * V_39 ;
void * V_52 ;
int V_28 ;
V_52 = F_57 ( F_37 ( V_36 ) , V_31 , (struct V_32 * * ) V_51 ) ;
if ( F_55 ( F_58 ( V_52 ) ) )
return F_59 ( V_52 ) ;
V_39 = F_43 ( F_36 ( * V_51 ) ) ;
V_28 = F_32 ( & V_39 -> V_2 ) ;
if ( V_28 ) {
F_60 ( F_36 ( * V_51 ) ) ;
F_35 ( V_31 , V_28 ) ;
return V_28 ;
}
V_39 -> V_53 = 1 ;
V_28 = F_54 ( V_36 , F_36 ( * V_51 ) , V_39 , V_48 ) ;
if ( F_55 ( V_28 ) ) {
F_34 ( & V_39 -> V_2 ) ;
F_60 ( F_36 ( * V_51 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_62 ( struct V_35 * V_36 ,
T_2 V_31 , struct V_47 * V_48 ,
struct V_33 * * V_51 )
{
struct V_38 * V_39 ;
void * V_52 ;
int V_28 ;
V_52 = F_63 ( F_37 ( V_36 ) , V_31 , (struct V_32 * * ) V_51 ) ;
if ( F_55 ( F_58 ( V_52 ) ) )
return F_59 ( V_52 ) ;
if ( F_55 ( ! V_52 ) )
return - V_30 ;
V_39 = F_43 ( F_36 ( * V_51 ) ) ;
V_28 = F_30 ( & V_39 -> V_2 ) ;
if ( V_28 < 0 ) {
F_60 ( F_36 ( * V_51 ) ) ;
F_35 ( V_31 , V_28 ) ;
return V_28 ;
}
V_39 -> V_53 = 0 ;
V_28 = F_54 ( V_36 , F_36 ( * V_51 ) , V_39 , V_48 ) ;
if ( F_55 ( V_28 ) ) {
F_31 ( & V_39 -> V_2 ) ;
F_60 ( F_36 ( * V_51 ) ) ;
return V_28 ;
}
return 0 ;
}
int F_64 ( struct V_35 * V_36 ,
T_2 V_31 , struct V_47 * V_48 ,
struct V_33 * * V_51 )
{
int V_28 ;
struct V_38 * V_39 ;
void * V_52 ;
V_52 = F_65 ( F_37 ( V_36 ) , V_31 , (struct V_32 * * ) V_51 ) ;
if ( F_55 ( F_58 ( V_52 ) ) )
return F_59 ( V_52 ) ;
memset ( V_52 , 0 , F_51 ( V_36 ) ) ;
V_39 = F_43 ( F_36 ( * V_51 ) ) ;
V_28 = F_32 ( & V_39 -> V_2 ) ;
if ( V_28 ) {
F_60 ( F_36 ( * V_51 ) ) ;
return V_28 ;
}
V_39 -> V_53 = 1 ;
V_39 -> V_40 = V_48 ;
return 0 ;
}
int F_66 ( struct V_33 * V_31 )
{
struct V_38 * V_39 ;
V_39 = F_43 ( F_36 ( V_31 ) ) ;
if ( V_39 -> V_53 ) {
F_67 ( F_36 ( V_31 ) ) ;
F_34 ( & V_39 -> V_2 ) ;
} else
F_31 ( & V_39 -> V_2 ) ;
F_60 ( F_36 ( V_31 ) ) ;
return 0 ;
}
int F_68 ( struct V_33 * V_31 , T_2 V_54 )
{
struct V_38 * V_39 ;
V_39 = F_43 ( F_36 ( V_31 ) ) ;
if ( V_39 -> V_53 ) {
F_67 ( F_36 ( V_31 ) ) ;
F_34 ( & V_39 -> V_2 ) ;
} else
F_31 ( & V_39 -> V_2 ) ;
F_69 ( F_36 ( V_31 ) , V_54 ) ;
return 0 ;
}
int F_70 ( struct V_35 * V_36 ,
struct V_33 * V_55 )
{
int V_28 ;
V_28 = F_71 ( F_37 ( V_36 ) ) ;
if ( F_55 ( V_28 ) )
return V_28 ;
V_28 = F_72 ( F_37 ( V_36 ) ) ;
if ( F_55 ( V_28 ) )
return V_28 ;
F_66 ( V_55 ) ;
V_28 = F_71 ( F_37 ( V_36 ) ) ;
if ( F_55 ( V_28 ) )
return V_28 ;
V_28 = F_72 ( F_37 ( V_36 ) ) ;
if ( F_55 ( V_28 ) )
return V_28 ;
return 0 ;
}
T_3 F_73 ( const void * V_56 , T_4 V_57 , T_3 V_58 )
{
return F_74 ( ~ ( T_3 ) 0 , V_56 , V_57 ) ^ V_58 ;
}
