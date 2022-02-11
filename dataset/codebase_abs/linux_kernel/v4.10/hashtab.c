static bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_5 ||
V_2 -> V_3 . V_4 == V_6 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_7 ||
V_2 -> V_3 . V_4 == V_6 ;
}
static inline void F_3 ( struct V_8 * V_9 , T_1 V_10 ,
void T_2 * V_11 )
{
* ( void T_2 * * ) ( V_9 -> V_12 + V_10 ) = V_11 ;
}
static inline void T_2 * F_4 ( struct V_8 * V_9 , T_1 V_10 )
{
return * ( void T_2 * * ) ( V_9 -> V_12 + V_10 ) ;
}
static struct V_8 * F_5 ( struct V_1 * V_2 , int V_13 )
{
return (struct V_8 * ) ( V_2 -> V_14 + V_13 * V_2 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! F_2 ( V_2 ) )
goto V_16;
for ( V_13 = 0 ; V_13 < V_2 -> V_3 . V_17 ; V_13 ++ ) {
void T_2 * V_11 ;
V_11 = F_4 ( F_5 ( V_2 , V_13 ) ,
V_2 -> V_3 . V_10 ) ;
F_7 ( V_11 ) ;
}
V_16:
F_8 ( V_2 -> V_14 ) ;
}
static struct V_8 * F_9 ( struct V_1 * V_2 , void * V_12 ,
T_1 V_18 )
{
struct V_19 * V_20 = F_10 ( & V_2 -> V_21 , V_18 ) ;
struct V_8 * V_9 ;
if ( V_20 ) {
V_9 = F_11 ( V_20 , struct V_8 , V_22 ) ;
memcpy ( V_9 -> V_12 , V_12 , V_2 -> V_3 . V_10 ) ;
return V_9 ;
}
return NULL ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_23 = - V_24 , V_13 ;
V_2 -> V_14 = F_13 ( V_2 -> V_15 *
V_2 -> V_3 . V_17 ) ;
if ( ! V_2 -> V_14 )
return - V_24 ;
if ( ! F_2 ( V_2 ) )
goto V_25;
for ( V_13 = 0 ; V_13 < V_2 -> V_3 . V_17 ; V_13 ++ ) {
T_1 V_26 = F_14 ( V_2 -> V_3 . V_27 , 8 ) ;
void T_2 * V_11 ;
V_11 = F_15 ( V_26 , 8 , V_28 | V_29 ) ;
if ( ! V_11 )
goto V_16;
F_3 ( F_5 ( V_2 , V_13 ) , V_2 -> V_3 . V_10 ,
V_11 ) ;
}
V_25:
if ( F_1 ( V_2 ) )
V_23 = F_16 ( & V_2 -> V_21 ,
V_2 -> V_3 . V_30 & V_31 ,
F_17 ( struct V_8 , V_18 ) -
F_17 ( struct V_8 , V_22 ) ,
V_32 ,
V_2 ) ;
else
V_23 = F_18 ( & V_2 -> V_33 ) ;
if ( V_23 )
goto V_16;
if ( F_1 ( V_2 ) )
F_19 ( & V_2 -> V_21 , V_2 -> V_14 ,
F_17 ( struct V_8 , V_22 ) ,
V_2 -> V_15 , V_2 -> V_3 . V_17 ) ;
else
F_20 ( & V_2 -> V_33 , V_2 -> V_14 ,
V_2 -> V_15 , V_2 -> V_3 . V_17 ) ;
return 0 ;
V_16:
F_6 ( V_2 ) ;
return V_23 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
if ( F_1 ( V_2 ) )
F_22 ( & V_2 -> V_21 ) ;
else
F_23 ( & V_2 -> V_33 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
void T_2 * V_11 ;
int V_34 ;
V_11 = F_15 ( V_2 -> V_15 , 8 , V_28 | V_29 ) ;
if ( ! V_11 )
return - V_24 ;
F_25 (cpu) {
( (struct V_8 * ) F_26 ( V_11 , V_34 ) ) -> V_35 =
V_36 ;
}
V_2 -> V_37 = V_11 ;
return 0 ;
}
static struct V_38 * F_27 ( union V_39 * V_40 )
{
bool V_41 = ( V_40 -> V_4 == V_7 ||
V_40 -> V_4 == V_6 ) ;
bool V_21 = ( V_40 -> V_4 == V_5 ||
V_40 -> V_4 == V_6 ) ;
bool V_42 = ( V_40 -> V_30 & V_31 ) ;
bool V_43 = ! ( V_40 -> V_30 & V_44 ) ;
struct V_1 * V_2 ;
int V_23 , V_13 ;
T_3 V_45 ;
if ( V_21 && ! F_28 ( V_46 ) )
return F_29 ( - V_47 ) ;
if ( V_40 -> V_30 & ~ ( V_44 | V_31 ) )
return F_29 ( - V_48 ) ;
if ( ! V_21 && V_42 )
return F_29 ( - V_48 ) ;
if ( V_21 && ! V_43 )
return F_29 ( - V_49 ) ;
V_2 = F_30 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_29 ( - V_24 ) ;
V_2 -> V_3 . V_4 = V_40 -> V_4 ;
V_2 -> V_3 . V_10 = V_40 -> V_10 ;
V_2 -> V_3 . V_27 = V_40 -> V_27 ;
V_2 -> V_3 . V_17 = V_40 -> V_17 ;
V_2 -> V_3 . V_30 = V_40 -> V_30 ;
V_23 = - V_48 ;
if ( V_2 -> V_3 . V_17 == 0 || V_2 -> V_3 . V_10 == 0 ||
V_2 -> V_3 . V_27 == 0 )
goto V_50;
if ( V_42 ) {
V_2 -> V_3 . V_17 = F_31 ( V_40 -> V_17 ,
F_32 () ) ;
if ( V_2 -> V_3 . V_17 < V_40 -> V_17 )
V_2 -> V_3 . V_17 = F_33 ( V_40 -> V_17 ,
F_32 () ) ;
}
V_2 -> V_51 = F_34 ( V_2 -> V_3 . V_17 ) ;
V_23 = - V_52 ;
if ( V_2 -> V_3 . V_10 > V_53 )
goto V_50;
if ( V_2 -> V_3 . V_27 >= V_54 -
V_53 - sizeof( struct V_8 ) )
goto V_50;
if ( V_41 && F_14 ( V_2 -> V_3 . V_27 , 8 ) > V_55 )
goto V_50;
V_2 -> V_15 = sizeof( struct V_8 ) +
F_14 ( V_2 -> V_3 . V_10 , 8 ) ;
if ( V_41 )
V_2 -> V_15 += sizeof( void * ) ;
else
V_2 -> V_15 += F_14 ( V_2 -> V_3 . V_27 , 8 ) ;
if ( V_2 -> V_51 == 0 ||
V_2 -> V_51 > V_56 / sizeof( struct V_57 ) )
goto V_50;
V_45 = ( T_3 ) V_2 -> V_51 * sizeof( struct V_57 ) +
( T_3 ) V_2 -> V_15 * V_2 -> V_3 . V_17 ;
if ( V_41 )
V_45 += ( T_3 ) F_14 ( V_2 -> V_3 . V_27 , 8 ) *
F_32 () * V_2 -> V_3 . V_17 ;
else
V_45 += ( T_3 ) V_2 -> V_15 * F_32 () ;
if ( V_45 >= V_56 - V_58 )
goto V_50;
V_2 -> V_3 . V_59 = F_14 ( V_45 , V_58 ) >> V_60 ;
V_23 = F_35 ( V_2 -> V_3 . V_59 ) ;
if ( V_23 )
goto V_50;
V_23 = - V_24 ;
V_2 -> V_61 = F_13 ( V_2 -> V_51 *
sizeof( struct V_57 ) ) ;
if ( ! V_2 -> V_61 )
goto V_50;
for ( V_13 = 0 ; V_13 < V_2 -> V_51 ; V_13 ++ ) {
F_36 ( & V_2 -> V_61 [ V_13 ] . V_62 ) ;
F_37 ( & V_2 -> V_61 [ V_13 ] . V_63 ) ;
}
if ( ! V_41 && ! V_21 ) {
V_23 = F_24 ( V_2 ) ;
if ( V_23 )
goto V_64;
}
if ( V_43 ) {
V_23 = F_12 ( V_2 ) ;
if ( V_23 )
goto V_65;
}
return & V_2 -> V_3 ;
V_65:
F_7 ( V_2 -> V_37 ) ;
V_64:
F_8 ( V_2 -> V_61 ) ;
V_50:
F_38 ( V_2 ) ;
return F_29 ( V_23 ) ;
}
static inline T_1 F_39 ( const void * V_12 , T_1 V_66 )
{
return F_40 ( V_12 , V_66 , 0 ) ;
}
static inline struct V_57 * F_41 ( struct V_1 * V_2 , T_1 V_18 )
{
return & V_2 -> V_61 [ V_18 & ( V_2 -> V_51 - 1 ) ] ;
}
static inline struct V_67 * F_42 ( struct V_1 * V_2 , T_1 V_18 )
{
return & F_41 ( V_2 , V_18 ) -> V_62 ;
}
static struct V_8 * F_43 ( struct V_67 * V_62 , T_1 V_18 ,
void * V_12 , T_1 V_10 )
{
struct V_8 * V_9 ;
F_44 (l, head, hash_node)
if ( V_9 -> V_18 == V_18 && ! memcmp ( & V_9 -> V_12 , V_12 , V_10 ) )
return V_9 ;
return NULL ;
}
static void * F_45 ( struct V_38 * V_3 , void * V_12 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_67 * V_62 ;
struct V_8 * V_9 ;
T_1 V_18 , V_10 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_62 = F_42 ( V_2 , V_18 ) ;
V_9 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
return V_9 ;
}
static void * F_48 ( struct V_38 * V_3 , void * V_12 )
{
struct V_8 * V_9 = F_45 ( V_3 , V_12 ) ;
if ( V_9 )
return V_9 -> V_12 + F_14 ( V_3 -> V_10 , 8 ) ;
return NULL ;
}
static void * F_49 ( struct V_38 * V_3 , void * V_12 )
{
struct V_8 * V_9 = F_45 ( V_3 , V_12 ) ;
if ( V_9 ) {
F_50 ( & V_9 -> V_22 ) ;
return V_9 -> V_12 + F_14 ( V_3 -> V_10 , 8 ) ;
}
return NULL ;
}
static bool V_32 ( void * V_68 , struct V_19 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
struct V_8 * V_9 , * V_69 ;
struct V_67 * V_62 ;
unsigned long V_70 ;
struct V_57 * V_71 ;
V_69 = F_11 ( V_20 , struct V_8 , V_22 ) ;
V_71 = F_41 ( V_2 , V_69 -> V_18 ) ;
V_62 = & V_71 -> V_62 ;
F_51 ( & V_71 -> V_63 , V_70 ) ;
F_44 (l, head, hash_node)
if ( V_9 == V_69 ) {
F_52 ( & V_9 -> V_72 ) ;
break;
}
F_53 ( & V_71 -> V_63 , V_70 ) ;
return V_9 == V_69 ;
}
static int F_54 ( struct V_38 * V_3 , void * V_12 , void * V_73 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_67 * V_62 ;
struct V_8 * V_9 , * V_74 ;
T_1 V_18 , V_10 ;
int V_13 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_62 = F_42 ( V_2 , V_18 ) ;
V_9 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
if ( ! V_9 ) {
V_13 = 0 ;
goto V_75;
}
V_74 = F_55 ( F_56 ( F_57 ( & V_9 -> V_72 ) ) ,
struct V_8 , V_72 ) ;
if ( V_74 ) {
memcpy ( V_73 , V_74 -> V_12 , V_10 ) ;
return 0 ;
}
V_13 = V_18 & ( V_2 -> V_51 - 1 ) ;
V_13 ++ ;
V_75:
for (; V_13 < V_2 -> V_51 ; V_13 ++ ) {
V_62 = F_42 ( V_2 , V_13 ) ;
V_74 = F_55 ( F_56 ( F_58 ( V_62 ) ) ,
struct V_8 , V_72 ) ;
if ( V_74 ) {
memcpy ( V_73 , V_74 -> V_12 , V_10 ) ;
return 0 ;
}
}
return - V_76 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( V_2 -> V_3 . V_4 == V_7 )
F_7 ( F_4 ( V_9 , V_2 -> V_3 . V_10 ) ) ;
F_38 ( V_9 ) ;
}
static void F_60 ( struct V_77 * V_62 )
{
struct V_8 * V_9 = F_11 ( V_62 , struct V_8 , V_78 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
F_61 () ;
F_62 ( V_79 ) ;
F_59 ( V_2 , V_9 ) ;
F_63 ( V_79 ) ;
F_64 () ;
}
static void F_65 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( V_9 -> V_35 == V_80 ) {
V_9 -> V_35 = V_36 ;
return;
}
if ( ! ( V_2 -> V_3 . V_30 & V_44 ) ) {
F_66 ( & V_2 -> V_33 , & V_9 -> V_81 ) ;
} else {
F_67 ( & V_2 -> V_82 ) ;
V_9 -> V_2 = V_2 ;
F_68 ( & V_9 -> V_78 , F_60 ) ;
}
}
static void F_69 ( struct V_1 * V_2 , void T_2 * V_11 ,
void * V_83 , bool V_84 )
{
if ( ! V_84 ) {
memcpy ( F_70 ( V_11 ) , V_83 , V_2 -> V_3 . V_27 ) ;
} else {
T_1 V_26 = F_14 ( V_2 -> V_3 . V_27 , 8 ) ;
int V_85 = 0 , V_34 ;
F_25 (cpu) {
F_71 ( F_26 ( V_11 , V_34 ) ,
V_83 + V_85 , V_26 ) ;
V_85 += V_26 ;
}
}
}
static struct V_8 * F_72 ( struct V_1 * V_2 , void * V_12 ,
void * V_83 , T_1 V_10 , T_1 V_18 ,
bool V_41 , bool V_84 ,
bool V_86 )
{
T_1 V_26 = V_2 -> V_3 . V_27 ;
bool V_43 = ! ( V_2 -> V_3 . V_30 & V_44 ) ;
struct V_8 * V_87 ;
void T_2 * V_11 ;
int V_23 = 0 ;
if ( V_43 ) {
V_87 = (struct V_8 * ) F_73 ( & V_2 -> V_33 ) ;
if ( ! V_87 )
V_23 = - V_52 ;
} else {
if ( F_74 ( & V_2 -> V_82 ) > V_2 -> V_3 . V_17 ) {
F_67 ( & V_2 -> V_82 ) ;
V_23 = - V_52 ;
} else {
V_87 = F_75 ( V_2 -> V_15 ,
V_88 | V_29 ) ;
if ( ! V_87 )
return F_29 ( - V_24 ) ;
}
}
if ( V_23 ) {
if ( ! V_86 )
return F_29 ( V_23 ) ;
V_87 = F_70 ( V_2 -> V_37 ) ;
if ( V_87 -> V_35 != V_36 )
return F_29 ( - V_52 ) ;
V_87 -> V_35 = V_80 ;
} else {
V_87 -> V_35 = V_89 ;
}
memcpy ( V_87 -> V_12 , V_12 , V_10 ) ;
if ( V_41 ) {
V_26 = F_14 ( V_26 , 8 ) ;
if ( V_43 ) {
V_11 = F_4 ( V_87 , V_10 ) ;
} else {
V_11 = F_15 ( V_26 , 8 ,
V_88 | V_29 ) ;
if ( ! V_11 ) {
F_38 ( V_87 ) ;
return F_29 ( - V_24 ) ;
}
}
F_69 ( V_2 , V_11 , V_83 , V_84 ) ;
if ( ! V_43 )
F_3 ( V_87 , V_10 , V_11 ) ;
} else {
memcpy ( V_87 -> V_12 + F_14 ( V_10 , 8 ) , V_83 , V_26 ) ;
}
V_87 -> V_18 = V_18 ;
return V_87 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_8 * V_90 ,
T_3 V_30 )
{
if ( V_90 && V_30 == V_91 )
return - V_92 ;
if ( ! V_90 && V_30 == V_93 )
return - V_76 ;
return 0 ;
}
static int F_77 ( struct V_38 * V_3 , void * V_12 , void * V_83 ,
T_3 V_30 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_8 * V_87 = NULL , * V_90 ;
struct V_67 * V_62 ;
unsigned long V_70 ;
struct V_57 * V_71 ;
T_1 V_10 , V_18 ;
int V_94 ;
if ( F_78 ( V_30 > V_93 ) )
return - V_48 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_71 = F_41 ( V_2 , V_18 ) ;
V_62 = & V_71 -> V_62 ;
F_51 ( & V_71 -> V_63 , V_70 ) ;
V_90 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
V_94 = F_76 ( V_2 , V_90 , V_30 ) ;
if ( V_94 )
goto V_23;
V_87 = F_72 ( V_2 , V_12 , V_83 , V_10 , V_18 , false , false ,
! ! V_90 ) ;
if ( F_79 ( V_87 ) ) {
V_94 = F_80 ( V_87 ) ;
goto V_23;
}
F_81 ( & V_87 -> V_72 , V_62 ) ;
if ( V_90 ) {
F_52 ( & V_90 -> V_72 ) ;
F_65 ( V_2 , V_90 ) ;
}
V_94 = 0 ;
V_23:
F_53 ( & V_71 -> V_63 , V_70 ) ;
return V_94 ;
}
static int F_82 ( struct V_38 * V_3 , void * V_12 , void * V_83 ,
T_3 V_30 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_8 * V_87 , * V_90 = NULL ;
struct V_67 * V_62 ;
unsigned long V_70 ;
struct V_57 * V_71 ;
T_1 V_10 , V_18 ;
int V_94 ;
if ( F_78 ( V_30 > V_93 ) )
return - V_48 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_71 = F_41 ( V_2 , V_18 ) ;
V_62 = & V_71 -> V_62 ;
V_87 = F_9 ( V_2 , V_12 , V_18 ) ;
if ( ! V_87 )
return - V_24 ;
memcpy ( V_87 -> V_12 + F_14 ( V_3 -> V_10 , 8 ) , V_83 , V_3 -> V_27 ) ;
F_51 ( & V_71 -> V_63 , V_70 ) ;
V_90 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
V_94 = F_76 ( V_2 , V_90 , V_30 ) ;
if ( V_94 )
goto V_23;
F_81 ( & V_87 -> V_72 , V_62 ) ;
if ( V_90 ) {
F_50 ( & V_87 -> V_22 ) ;
F_52 ( & V_90 -> V_72 ) ;
}
V_94 = 0 ;
V_23:
F_53 ( & V_71 -> V_63 , V_70 ) ;
if ( V_94 )
F_83 ( & V_2 -> V_21 , & V_87 -> V_22 ) ;
else if ( V_90 )
F_83 ( & V_2 -> V_21 , & V_90 -> V_22 ) ;
return V_94 ;
}
static int F_84 ( struct V_38 * V_3 , void * V_12 ,
void * V_83 , T_3 V_30 ,
bool V_84 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_8 * V_87 = NULL , * V_90 ;
struct V_67 * V_62 ;
unsigned long V_70 ;
struct V_57 * V_71 ;
T_1 V_10 , V_18 ;
int V_94 ;
if ( F_78 ( V_30 > V_93 ) )
return - V_48 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_71 = F_41 ( V_2 , V_18 ) ;
V_62 = & V_71 -> V_62 ;
F_51 ( & V_71 -> V_63 , V_70 ) ;
V_90 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
V_94 = F_76 ( V_2 , V_90 , V_30 ) ;
if ( V_94 )
goto V_23;
if ( V_90 ) {
F_69 ( V_2 , F_4 ( V_90 , V_10 ) ,
V_83 , V_84 ) ;
} else {
V_87 = F_72 ( V_2 , V_12 , V_83 , V_10 ,
V_18 , true , V_84 , false ) ;
if ( F_79 ( V_87 ) ) {
V_94 = F_80 ( V_87 ) ;
goto V_23;
}
F_81 ( & V_87 -> V_72 , V_62 ) ;
}
V_94 = 0 ;
V_23:
F_53 ( & V_71 -> V_63 , V_70 ) ;
return V_94 ;
}
static int F_85 ( struct V_38 * V_3 , void * V_12 ,
void * V_83 , T_3 V_30 ,
bool V_84 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_8 * V_87 = NULL , * V_90 ;
struct V_67 * V_62 ;
unsigned long V_70 ;
struct V_57 * V_71 ;
T_1 V_10 , V_18 ;
int V_94 ;
if ( F_78 ( V_30 > V_93 ) )
return - V_48 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_71 = F_41 ( V_2 , V_18 ) ;
V_62 = & V_71 -> V_62 ;
if ( V_30 != V_93 ) {
V_87 = F_9 ( V_2 , V_12 , V_18 ) ;
if ( ! V_87 )
return - V_24 ;
}
F_51 ( & V_71 -> V_63 , V_70 ) ;
V_90 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
V_94 = F_76 ( V_2 , V_90 , V_30 ) ;
if ( V_94 )
goto V_23;
if ( V_90 ) {
F_50 ( & V_90 -> V_22 ) ;
F_69 ( V_2 , F_4 ( V_90 , V_10 ) ,
V_83 , V_84 ) ;
} else {
F_69 ( V_2 , F_4 ( V_87 , V_10 ) ,
V_83 , V_84 ) ;
F_81 ( & V_87 -> V_72 , V_62 ) ;
V_87 = NULL ;
}
V_94 = 0 ;
V_23:
F_53 ( & V_71 -> V_63 , V_70 ) ;
if ( V_87 )
F_83 ( & V_2 -> V_21 , & V_87 -> V_22 ) ;
return V_94 ;
}
static int F_86 ( struct V_38 * V_3 , void * V_12 ,
void * V_83 , T_3 V_30 )
{
return F_84 ( V_3 , V_12 , V_83 , V_30 , false ) ;
}
static int F_87 ( struct V_38 * V_3 , void * V_12 ,
void * V_83 , T_3 V_30 )
{
return F_85 ( V_3 , V_12 , V_83 , V_30 ,
false ) ;
}
static int F_88 ( struct V_38 * V_3 , void * V_12 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_67 * V_62 ;
struct V_57 * V_71 ;
struct V_8 * V_9 ;
unsigned long V_70 ;
T_1 V_18 , V_10 ;
int V_94 = - V_76 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_71 = F_41 ( V_2 , V_18 ) ;
V_62 = & V_71 -> V_62 ;
F_51 ( & V_71 -> V_63 , V_70 ) ;
V_9 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
if ( V_9 ) {
F_52 ( & V_9 -> V_72 ) ;
F_65 ( V_2 , V_9 ) ;
V_94 = 0 ;
}
F_53 ( & V_71 -> V_63 , V_70 ) ;
return V_94 ;
}
static int F_89 ( struct V_38 * V_3 , void * V_12 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_67 * V_62 ;
struct V_57 * V_71 ;
struct V_8 * V_9 ;
unsigned long V_70 ;
T_1 V_18 , V_10 ;
int V_94 = - V_76 ;
F_46 ( ! F_47 () ) ;
V_10 = V_3 -> V_10 ;
V_18 = F_39 ( V_12 , V_10 ) ;
V_71 = F_41 ( V_2 , V_18 ) ;
V_62 = & V_71 -> V_62 ;
F_51 ( & V_71 -> V_63 , V_70 ) ;
V_9 = F_43 ( V_62 , V_18 , V_12 , V_10 ) ;
if ( V_9 ) {
F_52 ( & V_9 -> V_72 ) ;
V_94 = 0 ;
}
F_53 ( & V_71 -> V_63 , V_70 ) ;
if ( V_9 )
F_83 ( & V_2 -> V_21 , & V_9 -> V_22 ) ;
return V_94 ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_51 ; V_13 ++ ) {
struct V_67 * V_62 = F_42 ( V_2 , V_13 ) ;
struct V_95 * V_96 ;
struct V_8 * V_9 ;
F_91 (l, n, head, hash_node) {
F_52 ( & V_9 -> V_72 ) ;
if ( V_9 -> V_35 != V_80 )
F_59 ( V_2 , V_9 ) ;
}
}
}
static void F_92 ( struct V_38 * V_3 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
F_93 () ;
F_94 () ;
if ( V_2 -> V_3 . V_30 & V_44 )
F_90 ( V_2 ) ;
else
F_21 ( V_2 ) ;
F_7 ( V_2 -> V_37 ) ;
F_8 ( V_2 -> V_61 ) ;
F_38 ( V_2 ) ;
}
static void * F_95 ( struct V_38 * V_3 , void * V_12 )
{
struct V_8 * V_9 = F_45 ( V_3 , V_12 ) ;
if ( V_9 )
return F_70 ( F_4 ( V_9 , V_3 -> V_10 ) ) ;
else
return NULL ;
}
static void * F_96 ( struct V_38 * V_3 , void * V_12 )
{
struct V_8 * V_9 = F_45 ( V_3 , V_12 ) ;
if ( V_9 ) {
F_50 ( & V_9 -> V_22 ) ;
return F_70 ( F_4 ( V_9 , V_3 -> V_10 ) ) ;
}
return NULL ;
}
int F_97 ( struct V_38 * V_3 , void * V_12 , void * V_83 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
struct V_8 * V_9 ;
void T_2 * V_11 ;
int V_94 = - V_76 ;
int V_34 , V_85 = 0 ;
T_1 V_26 ;
V_26 = F_14 ( V_3 -> V_27 , 8 ) ;
F_98 () ;
V_9 = F_45 ( V_3 , V_12 ) ;
if ( ! V_9 )
goto V_97;
if ( F_1 ( V_2 ) )
F_50 ( & V_9 -> V_22 ) ;
V_11 = F_4 ( V_9 , V_3 -> V_10 ) ;
F_25 (cpu) {
F_71 ( V_83 + V_85 ,
F_26 ( V_11 , V_34 ) , V_26 ) ;
V_85 += V_26 ;
}
V_94 = 0 ;
V_97:
F_99 () ;
return V_94 ;
}
int F_100 ( struct V_38 * V_3 , void * V_12 , void * V_83 ,
T_3 V_30 )
{
struct V_1 * V_2 = F_11 ( V_3 , struct V_1 , V_3 ) ;
int V_94 ;
F_98 () ;
if ( F_1 ( V_2 ) )
V_94 = F_85 ( V_3 , V_12 , V_83 ,
V_30 , true ) ;
else
V_94 = F_84 ( V_3 , V_12 , V_83 , V_30 ,
true ) ;
F_99 () ;
return V_94 ;
}
static int T_4 F_101 ( void )
{
F_102 ( & V_98 ) ;
F_102 ( & V_99 ) ;
F_102 ( & V_100 ) ;
F_102 ( & V_101 ) ;
return 0 ;
}
