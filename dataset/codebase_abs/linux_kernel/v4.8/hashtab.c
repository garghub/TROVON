static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void T_2 * V_4 )
{
* ( void T_2 * * ) ( V_2 -> V_5 + V_3 ) = V_4 ;
}
static inline void T_2 * F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
return * ( void T_2 * * ) ( V_2 -> V_5 + V_3 ) ;
}
static struct V_1 * F_3 ( struct V_6 * V_7 , int V_8 )
{
return (struct V_1 * ) ( V_7 -> V_9 + V_8 * V_7 -> V_10 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
int V_8 ;
if ( V_7 -> V_11 . V_12 != V_13 )
goto V_14;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 . V_15 ; V_8 ++ ) {
void T_2 * V_4 ;
V_4 = F_2 ( F_3 ( V_7 , V_8 ) ,
V_7 -> V_11 . V_3 ) ;
F_5 ( V_4 ) ;
}
V_14:
F_6 ( V_7 -> V_9 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
int V_16 = - V_17 , V_8 ;
V_7 -> V_9 = F_8 ( V_7 -> V_10 * V_7 -> V_11 . V_15 ) ;
if ( ! V_7 -> V_9 )
return - V_17 ;
if ( V_7 -> V_11 . V_12 != V_13 )
goto V_18;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 . V_15 ; V_8 ++ ) {
T_1 V_19 = F_9 ( V_7 -> V_11 . V_20 , 8 ) ;
void T_2 * V_4 ;
V_4 = F_10 ( V_19 , 8 , V_21 | V_22 ) ;
if ( ! V_4 )
goto V_14;
F_1 ( F_3 ( V_7 , V_8 ) , V_7 -> V_11 . V_3 ,
V_4 ) ;
}
V_18:
V_16 = F_11 ( & V_7 -> V_23 ) ;
if ( V_16 )
goto V_14;
F_12 ( & V_7 -> V_23 , V_7 -> V_9 , V_7 -> V_10 ,
V_7 -> V_11 . V_15 ) ;
return 0 ;
V_14:
F_4 ( V_7 ) ;
return V_16 ;
}
static int F_13 ( struct V_6 * V_7 )
{
void T_2 * V_4 ;
int V_24 ;
V_4 = F_10 ( V_7 -> V_10 , 8 , V_21 | V_22 ) ;
if ( ! V_4 )
return - V_17 ;
F_14 (cpu) {
( (struct V_1 * ) F_15 ( V_4 , V_24 ) ) -> V_25 =
V_26 ;
}
V_7 -> V_27 = V_4 ;
return 0 ;
}
static struct V_28 * F_16 ( union V_29 * V_30 )
{
bool V_31 = V_30 -> V_12 == V_13 ;
struct V_6 * V_7 ;
int V_16 , V_8 ;
T_3 V_32 ;
if ( V_30 -> V_33 & ~ V_34 )
return F_17 ( - V_35 ) ;
V_7 = F_18 ( sizeof( * V_7 ) , V_21 ) ;
if ( ! V_7 )
return F_17 ( - V_17 ) ;
V_7 -> V_11 . V_12 = V_30 -> V_12 ;
V_7 -> V_11 . V_3 = V_30 -> V_3 ;
V_7 -> V_11 . V_20 = V_30 -> V_20 ;
V_7 -> V_11 . V_15 = V_30 -> V_15 ;
V_7 -> V_11 . V_33 = V_30 -> V_33 ;
V_16 = - V_35 ;
if ( V_7 -> V_11 . V_15 == 0 || V_7 -> V_11 . V_3 == 0 ||
V_7 -> V_11 . V_20 == 0 )
goto V_36;
V_7 -> V_37 = F_19 ( V_7 -> V_11 . V_15 ) ;
V_16 = - V_38 ;
if ( V_7 -> V_11 . V_3 > V_39 )
goto V_36;
if ( V_7 -> V_11 . V_20 >= ( 1 << ( V_40 - 1 ) ) -
V_39 - sizeof( struct V_1 ) )
goto V_36;
if ( V_31 && F_9 ( V_7 -> V_11 . V_20 , 8 ) > V_41 )
goto V_36;
V_7 -> V_10 = sizeof( struct V_1 ) +
F_9 ( V_7 -> V_11 . V_3 , 8 ) ;
if ( V_31 )
V_7 -> V_10 += sizeof( void * ) ;
else
V_7 -> V_10 += F_9 ( V_7 -> V_11 . V_20 , 8 ) ;
if ( V_7 -> V_37 == 0 ||
V_7 -> V_37 > V_42 / sizeof( struct V_43 ) )
goto V_36;
V_32 = ( T_3 ) V_7 -> V_37 * sizeof( struct V_43 ) +
( T_3 ) V_7 -> V_10 * V_7 -> V_11 . V_15 ;
if ( V_31 )
V_32 += ( T_3 ) F_9 ( V_7 -> V_11 . V_20 , 8 ) *
F_20 () * V_7 -> V_11 . V_15 ;
else
V_32 += ( T_3 ) V_7 -> V_10 * F_20 () ;
if ( V_32 >= V_42 - V_44 )
goto V_36;
V_7 -> V_11 . V_45 = F_9 ( V_32 , V_44 ) >> V_46 ;
V_16 = F_21 ( V_7 -> V_11 . V_45 ) ;
if ( V_16 )
goto V_36;
V_16 = - V_17 ;
V_7 -> V_47 = F_22 ( V_7 -> V_37 , sizeof( struct V_43 ) ,
V_21 | V_22 ) ;
if ( ! V_7 -> V_47 ) {
V_7 -> V_47 = F_23 ( V_7 -> V_37 * sizeof( struct V_43 ) ) ;
if ( ! V_7 -> V_47 )
goto V_36;
}
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
F_24 ( & V_7 -> V_47 [ V_8 ] . V_48 ) ;
F_25 ( & V_7 -> V_47 [ V_8 ] . V_49 ) ;
}
if ( ! V_31 ) {
V_16 = F_13 ( V_7 ) ;
if ( V_16 )
goto V_50;
}
if ( ! ( V_30 -> V_33 & V_34 ) ) {
V_16 = F_7 ( V_7 ) ;
if ( V_16 )
goto V_51;
}
return & V_7 -> V_11 ;
V_51:
F_5 ( V_7 -> V_27 ) ;
V_50:
F_26 ( V_7 -> V_47 ) ;
V_36:
F_27 ( V_7 ) ;
return F_17 ( V_16 ) ;
}
static inline T_1 F_28 ( const void * V_5 , T_1 V_52 )
{
return F_29 ( V_5 , V_52 , 0 ) ;
}
static inline struct V_43 * F_30 ( struct V_6 * V_7 , T_1 V_53 )
{
return & V_7 -> V_47 [ V_53 & ( V_7 -> V_37 - 1 ) ] ;
}
static inline struct V_54 * F_31 ( struct V_6 * V_7 , T_1 V_53 )
{
return & F_30 ( V_7 , V_53 ) -> V_48 ;
}
static struct V_1 * F_32 ( struct V_54 * V_48 , T_1 V_53 ,
void * V_5 , T_1 V_3 )
{
struct V_1 * V_2 ;
F_33 (l, head, hash_node)
if ( V_2 -> V_53 == V_53 && ! memcmp ( & V_2 -> V_5 , V_5 , V_3 ) )
return V_2 ;
return NULL ;
}
static void * F_34 ( struct V_28 * V_11 , void * V_5 )
{
struct V_6 * V_7 = F_35 ( V_11 , struct V_6 , V_11 ) ;
struct V_54 * V_48 ;
struct V_1 * V_2 ;
T_1 V_53 , V_3 ;
F_36 ( ! F_37 () ) ;
V_3 = V_11 -> V_3 ;
V_53 = F_28 ( V_5 , V_3 ) ;
V_48 = F_31 ( V_7 , V_53 ) ;
V_2 = F_32 ( V_48 , V_53 , V_5 , V_3 ) ;
return V_2 ;
}
static void * F_38 ( struct V_28 * V_11 , void * V_5 )
{
struct V_1 * V_2 = F_34 ( V_11 , V_5 ) ;
if ( V_2 )
return V_2 -> V_5 + F_9 ( V_11 -> V_3 , 8 ) ;
return NULL ;
}
static int F_39 ( struct V_28 * V_11 , void * V_5 , void * V_55 )
{
struct V_6 * V_7 = F_35 ( V_11 , struct V_6 , V_11 ) ;
struct V_54 * V_48 ;
struct V_1 * V_2 , * V_56 ;
T_1 V_53 , V_3 ;
int V_8 ;
F_36 ( ! F_37 () ) ;
V_3 = V_11 -> V_3 ;
V_53 = F_28 ( V_5 , V_3 ) ;
V_48 = F_31 ( V_7 , V_53 ) ;
V_2 = F_32 ( V_48 , V_53 , V_5 , V_3 ) ;
if ( ! V_2 ) {
V_8 = 0 ;
goto V_57;
}
V_56 = F_40 ( F_41 ( F_42 ( & V_2 -> V_58 ) ) ,
struct V_1 , V_58 ) ;
if ( V_56 ) {
memcpy ( V_55 , V_56 -> V_5 , V_3 ) ;
return 0 ;
}
V_8 = V_53 & ( V_7 -> V_37 - 1 ) ;
V_8 ++ ;
V_57:
for (; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_48 = F_31 ( V_7 , V_8 ) ;
V_56 = F_40 ( F_41 ( F_43 ( V_48 ) ) ,
struct V_1 , V_58 ) ;
if ( V_56 ) {
memcpy ( V_55 , V_56 -> V_5 , V_3 ) ;
return 0 ;
}
}
return - V_59 ;
}
static void F_44 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( V_7 -> V_11 . V_12 == V_13 )
F_5 ( F_2 ( V_2 , V_7 -> V_11 . V_3 ) ) ;
F_27 ( V_2 ) ;
}
static void F_45 ( struct V_60 * V_48 )
{
struct V_1 * V_2 = F_35 ( V_48 , struct V_1 , V_61 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_46 () ;
F_47 ( V_62 ) ;
F_44 ( V_7 , V_2 ) ;
F_48 ( V_62 ) ;
F_49 () ;
}
static void F_50 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( V_2 -> V_25 == V_63 ) {
V_2 -> V_25 = V_26 ;
return;
}
if ( ! ( V_7 -> V_11 . V_33 & V_34 ) ) {
F_51 ( & V_7 -> V_23 , & V_2 -> V_64 ) ;
} else {
F_52 ( & V_7 -> V_65 ) ;
V_2 -> V_7 = V_7 ;
F_53 ( & V_2 -> V_61 , F_45 ) ;
}
}
static struct V_1 * F_54 ( struct V_6 * V_7 , void * V_5 ,
void * V_66 , T_1 V_3 , T_1 V_53 ,
bool V_31 , bool V_67 ,
bool V_68 )
{
T_1 V_19 = V_7 -> V_11 . V_20 ;
bool V_69 = ! ( V_7 -> V_11 . V_33 & V_34 ) ;
struct V_1 * V_70 ;
void T_2 * V_4 ;
int V_16 = 0 ;
if ( V_69 ) {
V_70 = (struct V_1 * ) F_55 ( & V_7 -> V_23 ) ;
if ( ! V_70 )
V_16 = - V_38 ;
} else {
if ( F_56 ( & V_7 -> V_65 ) > V_7 -> V_11 . V_15 ) {
F_52 ( & V_7 -> V_65 ) ;
V_16 = - V_38 ;
} else {
V_70 = F_57 ( V_7 -> V_10 ,
V_71 | V_22 ) ;
if ( ! V_70 )
return F_17 ( - V_17 ) ;
}
}
if ( V_16 ) {
if ( ! V_68 )
return F_17 ( V_16 ) ;
V_70 = F_58 ( V_7 -> V_27 ) ;
if ( V_70 -> V_25 != V_26 )
return F_17 ( - V_38 ) ;
V_70 -> V_25 = V_63 ;
} else {
V_70 -> V_25 = V_72 ;
}
memcpy ( V_70 -> V_5 , V_5 , V_3 ) ;
if ( V_31 ) {
V_19 = F_9 ( V_19 , 8 ) ;
if ( V_69 ) {
V_4 = F_2 ( V_70 , V_3 ) ;
} else {
V_4 = F_10 ( V_19 , 8 ,
V_71 | V_22 ) ;
if ( ! V_4 ) {
F_27 ( V_70 ) ;
return F_17 ( - V_17 ) ;
}
}
if ( ! V_67 ) {
memcpy ( F_58 ( V_4 ) , V_66 , V_7 -> V_11 . V_20 ) ;
} else {
int V_73 = 0 , V_24 ;
F_14 (cpu) {
F_59 ( F_15 ( V_4 , V_24 ) ,
V_66 + V_73 , V_19 ) ;
V_73 += V_19 ;
}
}
if ( ! V_69 )
F_1 ( V_70 , V_3 , V_4 ) ;
} else {
memcpy ( V_70 -> V_5 + F_9 ( V_3 , 8 ) , V_66 , V_19 ) ;
}
V_70 -> V_53 = V_53 ;
return V_70 ;
}
static int F_60 ( struct V_6 * V_7 , struct V_1 * V_74 ,
T_3 V_33 )
{
if ( V_74 && V_33 == V_75 )
return - V_76 ;
if ( ! V_74 && V_33 == V_77 )
return - V_59 ;
return 0 ;
}
static int F_61 ( struct V_28 * V_11 , void * V_5 , void * V_66 ,
T_3 V_33 )
{
struct V_6 * V_7 = F_35 ( V_11 , struct V_6 , V_11 ) ;
struct V_1 * V_70 = NULL , * V_74 ;
struct V_54 * V_48 ;
unsigned long V_78 ;
struct V_43 * V_79 ;
T_1 V_3 , V_53 ;
int V_80 ;
if ( F_62 ( V_33 > V_77 ) )
return - V_35 ;
F_36 ( ! F_37 () ) ;
V_3 = V_11 -> V_3 ;
V_53 = F_28 ( V_5 , V_3 ) ;
V_79 = F_30 ( V_7 , V_53 ) ;
V_48 = & V_79 -> V_48 ;
F_63 ( & V_79 -> V_49 , V_78 ) ;
V_74 = F_32 ( V_48 , V_53 , V_5 , V_3 ) ;
V_80 = F_60 ( V_7 , V_74 , V_33 ) ;
if ( V_80 )
goto V_16;
V_70 = F_54 ( V_7 , V_5 , V_66 , V_3 , V_53 , false , false ,
! ! V_74 ) ;
if ( F_64 ( V_70 ) ) {
V_80 = F_65 ( V_70 ) ;
goto V_16;
}
F_66 ( & V_70 -> V_58 , V_48 ) ;
if ( V_74 ) {
F_67 ( & V_74 -> V_58 ) ;
F_50 ( V_7 , V_74 ) ;
}
V_80 = 0 ;
V_16:
F_68 ( & V_79 -> V_49 , V_78 ) ;
return V_80 ;
}
static int F_69 ( struct V_28 * V_11 , void * V_5 ,
void * V_66 , T_3 V_33 ,
bool V_67 )
{
struct V_6 * V_7 = F_35 ( V_11 , struct V_6 , V_11 ) ;
struct V_1 * V_70 = NULL , * V_74 ;
struct V_54 * V_48 ;
unsigned long V_78 ;
struct V_43 * V_79 ;
T_1 V_3 , V_53 ;
int V_80 ;
if ( F_62 ( V_33 > V_77 ) )
return - V_35 ;
F_36 ( ! F_37 () ) ;
V_3 = V_11 -> V_3 ;
V_53 = F_28 ( V_5 , V_3 ) ;
V_79 = F_30 ( V_7 , V_53 ) ;
V_48 = & V_79 -> V_48 ;
F_63 ( & V_79 -> V_49 , V_78 ) ;
V_74 = F_32 ( V_48 , V_53 , V_5 , V_3 ) ;
V_80 = F_60 ( V_7 , V_74 , V_33 ) ;
if ( V_80 )
goto V_16;
if ( V_74 ) {
void T_2 * V_4 = F_2 ( V_74 , V_3 ) ;
T_1 V_19 = V_7 -> V_11 . V_20 ;
if ( ! V_67 ) {
memcpy ( F_58 ( V_4 ) , V_66 , V_19 ) ;
} else {
int V_73 = 0 , V_24 ;
V_19 = F_9 ( V_19 , 8 ) ;
F_14 (cpu) {
F_59 ( F_15 ( V_4 , V_24 ) ,
V_66 + V_73 , V_19 ) ;
V_73 += V_19 ;
}
}
} else {
V_70 = F_54 ( V_7 , V_5 , V_66 , V_3 ,
V_53 , true , V_67 , false ) ;
if ( F_64 ( V_70 ) ) {
V_80 = F_65 ( V_70 ) ;
goto V_16;
}
F_66 ( & V_70 -> V_58 , V_48 ) ;
}
V_80 = 0 ;
V_16:
F_68 ( & V_79 -> V_49 , V_78 ) ;
return V_80 ;
}
static int F_70 ( struct V_28 * V_11 , void * V_5 ,
void * V_66 , T_3 V_33 )
{
return F_69 ( V_11 , V_5 , V_66 , V_33 , false ) ;
}
static int F_71 ( struct V_28 * V_11 , void * V_5 )
{
struct V_6 * V_7 = F_35 ( V_11 , struct V_6 , V_11 ) ;
struct V_54 * V_48 ;
struct V_43 * V_79 ;
struct V_1 * V_2 ;
unsigned long V_78 ;
T_1 V_53 , V_3 ;
int V_80 = - V_59 ;
F_36 ( ! F_37 () ) ;
V_3 = V_11 -> V_3 ;
V_53 = F_28 ( V_5 , V_3 ) ;
V_79 = F_30 ( V_7 , V_53 ) ;
V_48 = & V_79 -> V_48 ;
F_63 ( & V_79 -> V_49 , V_78 ) ;
V_2 = F_32 ( V_48 , V_53 , V_5 , V_3 ) ;
if ( V_2 ) {
F_67 ( & V_2 -> V_58 ) ;
F_50 ( V_7 , V_2 ) ;
V_80 = 0 ;
}
F_68 ( & V_79 -> V_49 , V_78 ) ;
return V_80 ;
}
static void F_72 ( struct V_6 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
struct V_54 * V_48 = F_31 ( V_7 , V_8 ) ;
struct V_81 * V_82 ;
struct V_1 * V_2 ;
F_73 (l, n, head, hash_node) {
F_67 ( & V_2 -> V_58 ) ;
F_44 ( V_7 , V_2 ) ;
}
}
}
static void F_74 ( struct V_28 * V_11 )
{
struct V_6 * V_7 = F_35 ( V_11 , struct V_6 , V_11 ) ;
F_75 () ;
F_76 () ;
if ( V_7 -> V_11 . V_33 & V_34 ) {
F_72 ( V_7 ) ;
} else {
F_4 ( V_7 ) ;
F_77 ( & V_7 -> V_23 ) ;
}
F_5 ( V_7 -> V_27 ) ;
F_26 ( V_7 -> V_47 ) ;
F_27 ( V_7 ) ;
}
static void * F_78 ( struct V_28 * V_11 , void * V_5 )
{
struct V_1 * V_2 = F_34 ( V_11 , V_5 ) ;
if ( V_2 )
return F_58 ( F_2 ( V_2 , V_11 -> V_3 ) ) ;
else
return NULL ;
}
int F_79 ( struct V_28 * V_11 , void * V_5 , void * V_66 )
{
struct V_1 * V_2 ;
void T_2 * V_4 ;
int V_80 = - V_59 ;
int V_24 , V_73 = 0 ;
T_1 V_19 ;
V_19 = F_9 ( V_11 -> V_20 , 8 ) ;
F_80 () ;
V_2 = F_34 ( V_11 , V_5 ) ;
if ( ! V_2 )
goto V_83;
V_4 = F_2 ( V_2 , V_11 -> V_3 ) ;
F_14 (cpu) {
F_59 ( V_66 + V_73 ,
F_15 ( V_4 , V_24 ) , V_19 ) ;
V_73 += V_19 ;
}
V_80 = 0 ;
V_83:
F_81 () ;
return V_80 ;
}
int F_82 ( struct V_28 * V_11 , void * V_5 , void * V_66 ,
T_3 V_33 )
{
int V_80 ;
F_80 () ;
V_80 = F_69 ( V_11 , V_5 , V_66 , V_33 , true ) ;
F_81 () ;
return V_80 ;
}
static int T_4 F_83 ( void )
{
F_84 ( & V_84 ) ;
F_84 ( & V_85 ) ;
return 0 ;
}
