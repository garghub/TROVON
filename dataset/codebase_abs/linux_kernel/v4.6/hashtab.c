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
static struct V_24 * F_13 ( union V_25 * V_26 )
{
bool V_27 = V_26 -> V_12 == V_13 ;
struct V_6 * V_7 ;
int V_16 , V_8 ;
T_3 V_28 ;
if ( V_26 -> V_29 & ~ V_30 )
return F_14 ( - V_31 ) ;
V_7 = F_15 ( sizeof( * V_7 ) , V_21 ) ;
if ( ! V_7 )
return F_14 ( - V_17 ) ;
V_7 -> V_11 . V_12 = V_26 -> V_12 ;
V_7 -> V_11 . V_3 = V_26 -> V_3 ;
V_7 -> V_11 . V_20 = V_26 -> V_20 ;
V_7 -> V_11 . V_15 = V_26 -> V_15 ;
V_7 -> V_11 . V_29 = V_26 -> V_29 ;
V_16 = - V_31 ;
if ( V_7 -> V_11 . V_15 == 0 || V_7 -> V_11 . V_3 == 0 ||
V_7 -> V_11 . V_20 == 0 )
goto V_32;
V_7 -> V_33 = F_16 ( V_7 -> V_11 . V_15 ) ;
V_16 = - V_34 ;
if ( V_7 -> V_11 . V_3 > V_35 )
goto V_32;
if ( V_7 -> V_11 . V_20 >= ( 1 << ( V_36 - 1 ) ) -
V_35 - sizeof( struct V_1 ) )
goto V_32;
if ( V_27 && F_9 ( V_7 -> V_11 . V_20 , 8 ) > V_37 )
goto V_32;
V_7 -> V_10 = sizeof( struct V_1 ) +
F_9 ( V_7 -> V_11 . V_3 , 8 ) ;
if ( V_27 )
V_7 -> V_10 += sizeof( void * ) ;
else
V_7 -> V_10 += F_9 ( V_7 -> V_11 . V_20 , 8 ) ;
if ( V_7 -> V_33 == 0 ||
V_7 -> V_33 > V_38 / sizeof( struct V_39 ) )
goto V_32;
V_28 = ( T_3 ) V_7 -> V_33 * sizeof( struct V_39 ) +
( T_3 ) V_7 -> V_10 * V_7 -> V_11 . V_15 ;
if ( V_27 )
V_28 += ( T_3 ) F_9 ( V_7 -> V_11 . V_20 , 8 ) *
F_17 () * V_7 -> V_11 . V_15 ;
if ( V_28 >= V_38 - V_40 )
goto V_32;
V_7 -> V_11 . V_41 = F_9 ( V_28 , V_40 ) >> V_42 ;
V_16 = F_18 ( V_7 -> V_11 . V_41 ) ;
if ( V_16 )
goto V_32;
V_16 = - V_17 ;
V_7 -> V_43 = F_19 ( V_7 -> V_33 , sizeof( struct V_39 ) ,
V_21 | V_22 ) ;
if ( ! V_7 -> V_43 ) {
V_7 -> V_43 = F_20 ( V_7 -> V_33 * sizeof( struct V_39 ) ) ;
if ( ! V_7 -> V_43 )
goto V_32;
}
for ( V_8 = 0 ; V_8 < V_7 -> V_33 ; V_8 ++ ) {
F_21 ( & V_7 -> V_43 [ V_8 ] . V_44 ) ;
F_22 ( & V_7 -> V_43 [ V_8 ] . V_45 ) ;
}
if ( ! ( V_26 -> V_29 & V_30 ) ) {
V_16 = F_7 ( V_7 ) ;
if ( V_16 )
goto V_46;
}
return & V_7 -> V_11 ;
V_46:
F_23 ( V_7 -> V_43 ) ;
V_32:
F_24 ( V_7 ) ;
return F_14 ( V_16 ) ;
}
static inline T_1 F_25 ( const void * V_5 , T_1 V_47 )
{
return F_26 ( V_5 , V_47 , 0 ) ;
}
static inline struct V_39 * F_27 ( struct V_6 * V_7 , T_1 V_48 )
{
return & V_7 -> V_43 [ V_48 & ( V_7 -> V_33 - 1 ) ] ;
}
static inline struct V_49 * F_28 ( struct V_6 * V_7 , T_1 V_48 )
{
return & F_27 ( V_7 , V_48 ) -> V_44 ;
}
static struct V_1 * F_29 ( struct V_49 * V_44 , T_1 V_48 ,
void * V_5 , T_1 V_3 )
{
struct V_1 * V_2 ;
F_30 (l, head, hash_node)
if ( V_2 -> V_48 == V_48 && ! memcmp ( & V_2 -> V_5 , V_5 , V_3 ) )
return V_2 ;
return NULL ;
}
static void * F_31 ( struct V_24 * V_11 , void * V_5 )
{
struct V_6 * V_7 = F_32 ( V_11 , struct V_6 , V_11 ) ;
struct V_49 * V_44 ;
struct V_1 * V_2 ;
T_1 V_48 , V_3 ;
F_33 ( ! F_34 () ) ;
V_3 = V_11 -> V_3 ;
V_48 = F_25 ( V_5 , V_3 ) ;
V_44 = F_28 ( V_7 , V_48 ) ;
V_2 = F_29 ( V_44 , V_48 , V_5 , V_3 ) ;
return V_2 ;
}
static void * F_35 ( struct V_24 * V_11 , void * V_5 )
{
struct V_1 * V_2 = F_31 ( V_11 , V_5 ) ;
if ( V_2 )
return V_2 -> V_5 + F_9 ( V_11 -> V_3 , 8 ) ;
return NULL ;
}
static int F_36 ( struct V_24 * V_11 , void * V_5 , void * V_50 )
{
struct V_6 * V_7 = F_32 ( V_11 , struct V_6 , V_11 ) ;
struct V_49 * V_44 ;
struct V_1 * V_2 , * V_51 ;
T_1 V_48 , V_3 ;
int V_8 ;
F_33 ( ! F_34 () ) ;
V_3 = V_11 -> V_3 ;
V_48 = F_25 ( V_5 , V_3 ) ;
V_44 = F_28 ( V_7 , V_48 ) ;
V_2 = F_29 ( V_44 , V_48 , V_5 , V_3 ) ;
if ( ! V_2 ) {
V_8 = 0 ;
goto V_52;
}
V_51 = F_37 ( F_38 ( F_39 ( & V_2 -> V_53 ) ) ,
struct V_1 , V_53 ) ;
if ( V_51 ) {
memcpy ( V_50 , V_51 -> V_5 , V_3 ) ;
return 0 ;
}
V_8 = V_48 & ( V_7 -> V_33 - 1 ) ;
V_8 ++ ;
V_52:
for (; V_8 < V_7 -> V_33 ; V_8 ++ ) {
V_44 = F_28 ( V_7 , V_8 ) ;
V_51 = F_37 ( F_38 ( F_40 ( V_44 ) ) ,
struct V_1 , V_53 ) ;
if ( V_51 ) {
memcpy ( V_50 , V_51 -> V_5 , V_3 ) ;
return 0 ;
}
}
return - V_54 ;
}
static void F_41 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( V_7 -> V_11 . V_12 == V_13 )
F_5 ( F_2 ( V_2 , V_7 -> V_11 . V_3 ) ) ;
F_24 ( V_2 ) ;
}
static void F_42 ( struct V_55 * V_44 )
{
struct V_1 * V_2 = F_32 ( V_44 , struct V_1 , V_56 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_43 () ;
F_44 ( V_57 ) ;
F_41 ( V_7 , V_2 ) ;
F_45 ( V_57 ) ;
F_46 () ;
}
static void F_47 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( ! ( V_7 -> V_11 . V_29 & V_30 ) ) {
F_48 ( & V_7 -> V_23 , & V_2 -> V_58 ) ;
} else {
F_49 ( & V_7 -> V_59 ) ;
V_2 -> V_7 = V_7 ;
F_50 ( & V_2 -> V_56 , F_42 ) ;
}
}
static struct V_1 * F_51 ( struct V_6 * V_7 , void * V_5 ,
void * V_60 , T_1 V_3 , T_1 V_48 ,
bool V_27 , bool V_61 )
{
T_1 V_19 = V_7 -> V_11 . V_20 ;
bool V_62 = ! ( V_7 -> V_11 . V_29 & V_30 ) ;
struct V_1 * V_63 ;
void T_2 * V_4 ;
if ( V_62 ) {
V_63 = (struct V_1 * ) F_52 ( & V_7 -> V_23 ) ;
if ( ! V_63 )
return F_14 ( - V_34 ) ;
} else {
if ( F_53 ( & V_7 -> V_59 ) > V_7 -> V_11 . V_15 ) {
F_49 ( & V_7 -> V_59 ) ;
return F_14 ( - V_34 ) ;
}
V_63 = F_54 ( V_7 -> V_10 , V_64 | V_22 ) ;
if ( ! V_63 )
return F_14 ( - V_17 ) ;
}
memcpy ( V_63 -> V_5 , V_5 , V_3 ) ;
if ( V_27 ) {
V_19 = F_9 ( V_19 , 8 ) ;
if ( V_62 ) {
V_4 = F_2 ( V_63 , V_3 ) ;
} else {
V_4 = F_10 ( V_19 , 8 ,
V_64 | V_22 ) ;
if ( ! V_4 ) {
F_24 ( V_63 ) ;
return F_14 ( - V_17 ) ;
}
}
if ( ! V_61 ) {
memcpy ( F_55 ( V_4 ) , V_60 , V_7 -> V_11 . V_20 ) ;
} else {
int V_65 = 0 , V_66 ;
F_56 (cpu) {
F_57 ( F_58 ( V_4 , V_66 ) ,
V_60 + V_65 , V_19 ) ;
V_65 += V_19 ;
}
}
if ( ! V_62 )
F_1 ( V_63 , V_3 , V_4 ) ;
} else {
memcpy ( V_63 -> V_5 + F_9 ( V_3 , 8 ) , V_60 , V_19 ) ;
}
V_63 -> V_48 = V_48 ;
return V_63 ;
}
static int F_59 ( struct V_6 * V_7 , struct V_1 * V_67 ,
T_3 V_29 )
{
if ( V_67 && V_29 == V_68 )
return - V_69 ;
if ( ! V_67 && V_29 == V_70 )
return - V_54 ;
return 0 ;
}
static int F_60 ( struct V_24 * V_11 , void * V_5 , void * V_60 ,
T_3 V_29 )
{
struct V_6 * V_7 = F_32 ( V_11 , struct V_6 , V_11 ) ;
struct V_1 * V_63 = NULL , * V_67 ;
struct V_49 * V_44 ;
unsigned long V_71 ;
struct V_39 * V_72 ;
T_1 V_3 , V_48 ;
int V_73 ;
if ( F_61 ( V_29 > V_70 ) )
return - V_31 ;
F_33 ( ! F_34 () ) ;
V_3 = V_11 -> V_3 ;
V_48 = F_25 ( V_5 , V_3 ) ;
V_72 = F_27 ( V_7 , V_48 ) ;
V_44 = & V_72 -> V_44 ;
F_62 ( & V_72 -> V_45 , V_71 ) ;
V_67 = F_29 ( V_44 , V_48 , V_5 , V_3 ) ;
V_73 = F_59 ( V_7 , V_67 , V_29 ) ;
if ( V_73 )
goto V_16;
V_63 = F_51 ( V_7 , V_5 , V_60 , V_3 , V_48 , false , false ) ;
if ( F_63 ( V_63 ) ) {
V_73 = F_64 ( V_63 ) ;
goto V_16;
}
F_65 ( & V_63 -> V_53 , V_44 ) ;
if ( V_67 ) {
F_66 ( & V_67 -> V_53 ) ;
F_47 ( V_7 , V_67 ) ;
}
V_73 = 0 ;
V_16:
F_67 ( & V_72 -> V_45 , V_71 ) ;
return V_73 ;
}
static int F_68 ( struct V_24 * V_11 , void * V_5 ,
void * V_60 , T_3 V_29 ,
bool V_61 )
{
struct V_6 * V_7 = F_32 ( V_11 , struct V_6 , V_11 ) ;
struct V_1 * V_63 = NULL , * V_67 ;
struct V_49 * V_44 ;
unsigned long V_71 ;
struct V_39 * V_72 ;
T_1 V_3 , V_48 ;
int V_73 ;
if ( F_61 ( V_29 > V_70 ) )
return - V_31 ;
F_33 ( ! F_34 () ) ;
V_3 = V_11 -> V_3 ;
V_48 = F_25 ( V_5 , V_3 ) ;
V_72 = F_27 ( V_7 , V_48 ) ;
V_44 = & V_72 -> V_44 ;
F_62 ( & V_72 -> V_45 , V_71 ) ;
V_67 = F_29 ( V_44 , V_48 , V_5 , V_3 ) ;
V_73 = F_59 ( V_7 , V_67 , V_29 ) ;
if ( V_73 )
goto V_16;
if ( V_67 ) {
void T_2 * V_4 = F_2 ( V_67 , V_3 ) ;
T_1 V_19 = V_7 -> V_11 . V_20 ;
if ( ! V_61 ) {
memcpy ( F_55 ( V_4 ) , V_60 , V_19 ) ;
} else {
int V_65 = 0 , V_66 ;
V_19 = F_9 ( V_19 , 8 ) ;
F_56 (cpu) {
F_57 ( F_58 ( V_4 , V_66 ) ,
V_60 + V_65 , V_19 ) ;
V_65 += V_19 ;
}
}
} else {
V_63 = F_51 ( V_7 , V_5 , V_60 , V_3 ,
V_48 , true , V_61 ) ;
if ( F_63 ( V_63 ) ) {
V_73 = F_64 ( V_63 ) ;
goto V_16;
}
F_65 ( & V_63 -> V_53 , V_44 ) ;
}
V_73 = 0 ;
V_16:
F_67 ( & V_72 -> V_45 , V_71 ) ;
return V_73 ;
}
static int F_69 ( struct V_24 * V_11 , void * V_5 ,
void * V_60 , T_3 V_29 )
{
return F_68 ( V_11 , V_5 , V_60 , V_29 , false ) ;
}
static int F_70 ( struct V_24 * V_11 , void * V_5 )
{
struct V_6 * V_7 = F_32 ( V_11 , struct V_6 , V_11 ) ;
struct V_49 * V_44 ;
struct V_39 * V_72 ;
struct V_1 * V_2 ;
unsigned long V_71 ;
T_1 V_48 , V_3 ;
int V_73 = - V_54 ;
F_33 ( ! F_34 () ) ;
V_3 = V_11 -> V_3 ;
V_48 = F_25 ( V_5 , V_3 ) ;
V_72 = F_27 ( V_7 , V_48 ) ;
V_44 = & V_72 -> V_44 ;
F_62 ( & V_72 -> V_45 , V_71 ) ;
V_2 = F_29 ( V_44 , V_48 , V_5 , V_3 ) ;
if ( V_2 ) {
F_66 ( & V_2 -> V_53 ) ;
F_47 ( V_7 , V_2 ) ;
V_73 = 0 ;
}
F_67 ( & V_72 -> V_45 , V_71 ) ;
return V_73 ;
}
static void F_71 ( struct V_6 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_33 ; V_8 ++ ) {
struct V_49 * V_44 = F_28 ( V_7 , V_8 ) ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
F_72 (l, n, head, hash_node) {
F_66 ( & V_2 -> V_53 ) ;
F_41 ( V_7 , V_2 ) ;
}
}
}
static void F_73 ( struct V_24 * V_11 )
{
struct V_6 * V_7 = F_32 ( V_11 , struct V_6 , V_11 ) ;
F_74 () ;
F_75 () ;
if ( V_7 -> V_11 . V_29 & V_30 ) {
F_71 ( V_7 ) ;
} else {
F_4 ( V_7 ) ;
F_76 ( & V_7 -> V_23 ) ;
}
F_23 ( V_7 -> V_43 ) ;
F_24 ( V_7 ) ;
}
static void * F_77 ( struct V_24 * V_11 , void * V_5 )
{
struct V_1 * V_2 = F_31 ( V_11 , V_5 ) ;
if ( V_2 )
return F_55 ( F_2 ( V_2 , V_11 -> V_3 ) ) ;
else
return NULL ;
}
int F_78 ( struct V_24 * V_11 , void * V_5 , void * V_60 )
{
struct V_1 * V_2 ;
void T_2 * V_4 ;
int V_73 = - V_54 ;
int V_66 , V_65 = 0 ;
T_1 V_19 ;
V_19 = F_9 ( V_11 -> V_20 , 8 ) ;
F_79 () ;
V_2 = F_31 ( V_11 , V_5 ) ;
if ( ! V_2 )
goto V_76;
V_4 = F_2 ( V_2 , V_11 -> V_3 ) ;
F_56 (cpu) {
F_57 ( V_60 + V_65 ,
F_58 ( V_4 , V_66 ) , V_19 ) ;
V_65 += V_19 ;
}
V_73 = 0 ;
V_76:
F_80 () ;
return V_73 ;
}
int F_81 ( struct V_24 * V_11 , void * V_5 , void * V_60 ,
T_3 V_29 )
{
int V_73 ;
F_79 () ;
V_73 = F_68 ( V_11 , V_5 , V_60 , V_29 , true ) ;
F_80 () ;
return V_73 ;
}
static int T_4 F_82 ( void )
{
F_83 ( & V_77 ) ;
F_83 ( & V_78 ) ;
return 0 ;
}
