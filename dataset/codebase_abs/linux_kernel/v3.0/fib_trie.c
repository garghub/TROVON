static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_3 -> V_4 , F_3 () ) ;
return (struct V_1 * ) ( V_4 & ~ V_5 ) ;
}
static inline struct V_1 * F_4 ( const struct V_2 * V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_3 -> V_4 , F_5 () ||
F_3 () ) ;
return (struct V_1 * ) ( V_4 & ~ V_5 ) ;
}
static inline void F_6 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
F_7 () ;
V_3 -> V_4 = ( unsigned long ) V_6 | F_8 ( V_3 ) ;
}
static inline struct V_2 * F_9 ( const struct V_1 * V_7 , unsigned int V_8 )
{
F_10 ( V_8 >= 1U << V_7 -> V_9 ) ;
return F_11 ( V_7 -> V_10 [ V_8 ] ) ;
}
static inline struct V_2 * F_12 ( const struct V_1 * V_7 , unsigned int V_8 )
{
F_10 ( V_8 >= 1U << V_7 -> V_9 ) ;
return F_13 ( V_7 -> V_10 [ V_8 ] ) ;
}
static inline int F_14 ( const struct V_1 * V_7 )
{
return 1 << V_7 -> V_9 ;
}
static inline T_1 F_15 ( T_1 V_11 , unsigned int V_12 )
{
return ( V_12 == 0 ) ? 0 : V_11 >> ( V_13 - V_12 ) << ( V_13 - V_12 ) ;
}
static inline T_1 F_16 ( T_1 V_14 , unsigned int V_15 , unsigned int V_9 )
{
if ( V_15 < V_13 )
return ( ( T_1 ) ( V_14 << V_15 ) ) >> ( V_13 - V_9 ) ;
else
return 0 ;
}
static inline int F_17 ( T_1 V_14 , T_1 V_16 )
{
return V_14 == V_16 ;
}
static inline int F_18 ( T_1 V_14 , int V_15 , int V_9 , T_1 V_16 )
{
if ( V_9 == 0 || V_15 >= V_13 )
return 1 ;
V_9 = V_9 > V_13 ? V_13 : V_9 ;
return ( ( V_14 ^ V_16 ) << V_15 ) >> ( V_13 - V_9 ) == 0 ;
}
static inline int F_19 ( T_1 V_14 , int V_15 , T_1 V_16 )
{
T_1 V_17 = V_14 ^ V_16 ;
int V_8 = V_15 ;
if ( ! V_17 )
return 0 ;
while ( ( V_17 << V_8 ) >> ( V_13 - 1 ) == 0 )
V_8 ++ ;
return V_8 ;
}
static inline void F_20 ( const struct V_1 * V_7 )
{
F_21 ( V_7 && V_7 -> V_18 + V_7 -> V_9 > 32 ) ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_23 ( V_20 , struct V_21 , V_23 ) ;
F_24 ( V_24 , V_22 ) ;
}
static inline void F_25 ( struct V_21 * V_22 )
{
F_26 ( & V_22 -> V_23 , F_22 ) ;
}
static void F_27 ( struct V_19 * V_20 )
{
struct V_25 * V_12 = F_23 ( V_20 , struct V_25 , V_23 ) ;
F_24 ( V_26 , V_12 ) ;
}
static inline void F_28 ( struct V_25 * V_12 )
{
F_29 ( & V_12 -> V_23 , F_27 ) ;
}
static inline void F_30 ( struct V_27 * V_25 )
{
F_31 ( V_25 , V_23 ) ;
}
static struct V_1 * F_32 ( T_2 V_28 )
{
if ( V_28 <= V_29 )
return F_33 ( V_28 , V_30 ) ;
else
return F_34 ( V_28 ) ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_1 * V_7 = F_23 ( V_32 , struct V_1 , V_33 ) ;
F_36 ( V_7 ) ;
}
static void F_37 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = F_23 ( V_20 , struct V_1 , V_23 ) ;
T_2 V_28 = sizeof( struct V_1 ) +
( sizeof( struct V_2 * ) << V_7 -> V_9 ) ;
if ( V_28 <= V_29 )
F_38 ( V_7 ) ;
else {
F_39 ( & V_7 -> V_33 , F_35 ) ;
F_40 ( & V_7 -> V_33 ) ;
}
}
static inline void F_41 ( struct V_1 * V_7 )
{
if ( F_42 ( V_7 ) )
F_28 ( (struct V_25 * ) V_7 ) ;
else
F_26 ( & V_7 -> V_23 , F_37 ) ;
}
static void F_43 ( struct V_1 * V_7 )
{
F_10 ( F_42 ( V_7 ) ) ;
V_7 -> F_41 = V_34 ;
V_34 = V_7 ;
V_35 += sizeof( struct V_1 ) +
( sizeof( struct V_2 * ) << V_7 -> V_9 ) ;
}
static void F_44 ( void )
{
struct V_1 * V_7 ;
while ( ( V_7 = V_34 ) ) {
V_34 = V_7 -> F_41 ;
V_7 -> F_41 = NULL ;
F_41 ( V_7 ) ;
}
if ( V_35 >= V_29 * V_36 ) {
V_35 = 0 ;
F_45 () ;
}
}
static struct V_25 * F_46 ( void )
{
struct V_25 * V_12 = F_47 ( V_26 , V_30 ) ;
if ( V_12 ) {
V_12 -> V_4 = V_37 ;
F_48 ( & V_12 -> V_38 ) ;
}
return V_12 ;
}
static struct V_27 * F_49 ( int V_39 )
{
struct V_27 * V_40 = F_50 ( sizeof( struct V_27 ) , V_30 ) ;
if ( V_40 ) {
V_40 -> V_39 = V_39 ;
F_51 ( & V_40 -> V_41 ) ;
}
return V_40 ;
}
static struct V_1 * F_52 ( T_1 V_42 , int V_18 , int V_9 )
{
T_2 V_43 = sizeof( struct V_1 ) + ( sizeof( struct V_2 * ) << V_9 ) ;
struct V_1 * V_7 = F_32 ( V_43 ) ;
if ( V_7 ) {
V_7 -> V_4 = V_44 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_42 = V_42 ;
V_7 -> V_45 = 0 ;
V_7 -> V_46 = 1 << V_9 ;
}
F_53 ( L_1 , V_7 , sizeof( struct V_1 ) ,
sizeof( struct V_2 ) << V_9 ) ;
return V_7 ;
}
static inline int F_54 ( const struct V_1 * V_7 , const struct V_2 * V_47 )
{
if ( V_47 == NULL || F_42 ( V_47 ) )
return 0 ;
return ( (struct V_1 * ) V_47 ) -> V_18 == V_7 -> V_18 + V_7 -> V_9 ;
}
static inline void F_55 ( struct V_48 * V_49 , struct V_1 * V_7 , int V_8 ,
struct V_2 * V_47 )
{
F_56 ( V_7 , V_8 , V_47 , - 1 ) ;
}
static void F_56 ( struct V_1 * V_7 , int V_8 , struct V_2 * V_47 ,
int V_50 )
{
struct V_2 * V_51 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
int V_52 ;
F_10 ( V_8 >= 1 << V_7 -> V_9 ) ;
if ( V_47 == NULL && V_51 != NULL )
V_7 -> V_46 ++ ;
else if ( V_47 != NULL && V_51 == NULL )
V_7 -> V_46 -- ;
if ( V_50 == - 1 )
V_50 = F_54 ( V_7 , V_51 ) ;
V_52 = F_54 ( V_7 , V_47 ) ;
if ( V_50 && ! V_52 )
V_7 -> V_45 -- ;
else if ( ! V_50 && V_52 )
V_7 -> V_45 ++ ;
if ( V_47 )
F_6 ( V_47 , V_7 ) ;
F_57 ( V_7 -> V_10 [ V_8 ] , V_47 ) ;
}
static struct V_2 * F_58 ( struct V_48 * V_49 , struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_53 ;
int V_54 ;
int V_55 ;
int V_56 ;
if ( ! V_7 )
return NULL ;
F_53 ( L_2 ,
V_7 , V_57 , V_58 ) ;
if ( V_7 -> V_46 == F_14 ( V_7 ) ) {
F_43 ( V_7 ) ;
return NULL ;
}
if ( V_7 -> V_46 == F_14 ( V_7 ) - 1 )
goto V_59;
F_20 ( V_7 ) ;
if ( ! F_1 ( (struct V_2 * ) V_7 ) ) {
V_54 = V_60 ;
V_55 = V_61 ;
} else {
V_54 = V_57 ;
V_55 = V_58 ;
}
V_56 = V_62 ;
while ( ( V_7 -> V_45 > 0 && V_56 -- &&
50 * ( V_7 -> V_45 + F_14 ( V_7 )
- V_7 -> V_46 )
>= V_54 * F_14 ( V_7 ) ) ) {
V_53 = V_7 ;
V_7 = F_59 ( V_49 , V_7 ) ;
if ( F_60 ( V_7 ) ) {
V_7 = V_53 ;
#ifdef F_61
V_49 -> V_63 . V_64 ++ ;
#endif
break;
}
}
F_20 ( V_7 ) ;
if ( V_56 != V_62 )
return (struct V_2 * ) V_7 ;
V_56 = V_62 ;
while ( V_7 -> V_9 > 1 && V_56 -- &&
100 * ( F_14 ( V_7 ) - V_7 -> V_46 ) <
V_55 * F_14 ( V_7 ) ) {
V_53 = V_7 ;
V_7 = F_62 ( V_49 , V_7 ) ;
if ( F_60 ( V_7 ) ) {
V_7 = V_53 ;
#ifdef F_61
V_49 -> V_63 . V_64 ++ ;
#endif
break;
}
}
if ( V_7 -> V_46 == F_14 ( V_7 ) - 1 ) {
V_59:
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
struct V_2 * V_47 ;
V_47 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( ! V_47 )
continue;
F_6 ( V_47 , NULL ) ;
F_43 ( V_7 ) ;
return V_47 ;
}
}
return (struct V_2 * ) V_7 ;
}
static void F_63 ( struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_65 ;
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
V_65 = (struct V_1 * ) F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( V_65 )
F_41 ( V_65 ) ;
}
F_41 ( V_7 ) ;
}
static struct V_1 * F_59 ( struct V_48 * V_49 , struct V_1 * V_7 )
{
struct V_1 * V_66 = V_7 ;
int V_67 = F_14 ( V_7 ) ;
int V_8 ;
F_53 ( L_3 ) ;
V_7 = F_52 ( V_66 -> V_42 , V_66 -> V_18 , V_66 -> V_9 + 1 ) ;
if ( ! V_7 )
return F_64 ( - V_68 ) ;
for ( V_8 = 0 ; V_8 < V_67 ; V_8 ++ ) {
struct V_1 * V_69 ;
V_69 = (struct V_1 * ) F_9 ( V_66 , V_8 ) ;
if ( V_69 &&
F_65 ( V_69 ) &&
V_69 -> V_18 == V_66 -> V_18 + V_66 -> V_9 &&
V_69 -> V_9 > 1 ) {
struct V_1 * V_70 , * V_71 ;
T_1 V_72 = ~ 0U << ( V_13 - 1 ) >> V_69 -> V_18 ;
V_70 = F_52 ( V_69 -> V_42 & ( ~ V_72 ) , V_69 -> V_18 + 1 ,
V_69 -> V_9 - 1 ) ;
if ( ! V_70 )
goto V_73;
V_71 = F_52 ( V_69 -> V_42 | V_72 , V_69 -> V_18 + 1 ,
V_69 -> V_9 - 1 ) ;
if ( ! V_71 ) {
F_41 ( V_70 ) ;
goto V_73;
}
F_55 ( V_49 , V_7 , 2 * V_8 , (struct V_2 * ) V_70 ) ;
F_55 ( V_49 , V_7 , 2 * V_8 + 1 , (struct V_2 * ) V_71 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_67 ; V_8 ++ ) {
struct V_1 * V_69 ;
struct V_2 * V_3 = F_9 ( V_66 , V_8 ) ;
struct V_1 * V_70 , * V_71 ;
int V_28 , V_74 ;
if ( V_3 == NULL )
continue;
if ( F_42 ( V_3 ) || ( (struct V_1 * ) V_3 ) -> V_18 >
V_7 -> V_18 + V_7 -> V_9 - 1 ) {
if ( F_16 ( V_3 -> V_42 ,
V_66 -> V_18 + V_66 -> V_9 ,
1 ) == 0 )
F_55 ( V_49 , V_7 , 2 * V_8 , V_3 ) ;
else
F_55 ( V_49 , V_7 , 2 * V_8 + 1 , V_3 ) ;
continue;
}
V_69 = (struct V_1 * ) V_3 ;
if ( V_69 -> V_9 == 1 ) {
F_55 ( V_49 , V_7 , 2 * V_8 , F_11 ( V_69 -> V_10 [ 0 ] ) ) ;
F_55 ( V_49 , V_7 , 2 * V_8 + 1 , F_11 ( V_69 -> V_10 [ 1 ] ) ) ;
F_43 ( V_69 ) ;
continue;
}
V_70 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 ) ;
F_55 ( V_49 , V_7 , 2 * V_8 , NULL ) ;
F_10 ( ! V_70 ) ;
V_71 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 + 1 ) ;
F_55 ( V_49 , V_7 , 2 * V_8 + 1 , NULL ) ;
F_10 ( ! V_71 ) ;
V_28 = F_14 ( V_70 ) ;
for ( V_74 = 0 ; V_74 < V_28 ; V_74 ++ ) {
F_55 ( V_49 , V_70 , V_74 , F_11 ( V_69 -> V_10 [ V_74 ] ) ) ;
F_55 ( V_49 , V_71 , V_74 , F_11 ( V_69 -> V_10 [ V_74 + V_28 ] ) ) ;
}
F_55 ( V_49 , V_7 , 2 * V_8 , F_58 ( V_49 , V_70 ) ) ;
F_55 ( V_49 , V_7 , 2 * V_8 + 1 , F_58 ( V_49 , V_71 ) ) ;
F_43 ( V_69 ) ;
}
F_43 ( V_66 ) ;
return V_7 ;
V_73:
F_63 ( V_7 ) ;
return F_64 ( - V_68 ) ;
}
static struct V_1 * F_62 ( struct V_48 * V_49 , struct V_1 * V_7 )
{
struct V_1 * V_66 = V_7 ;
struct V_2 * V_70 , * V_71 ;
int V_8 ;
int V_67 = F_14 ( V_7 ) ;
F_53 ( L_4 ) ;
V_7 = F_52 ( V_66 -> V_42 , V_66 -> V_18 , V_66 -> V_9 - 1 ) ;
if ( ! V_7 )
return F_64 ( - V_68 ) ;
for ( V_8 = 0 ; V_8 < V_67 ; V_8 += 2 ) {
V_70 = F_9 ( V_66 , V_8 ) ;
V_71 = F_9 ( V_66 , V_8 + 1 ) ;
if ( V_70 && V_71 ) {
struct V_1 * V_75 ;
V_75 = F_52 ( V_70 -> V_42 , V_7 -> V_18 + V_7 -> V_9 , 1 ) ;
if ( ! V_75 )
goto V_73;
F_55 ( V_49 , V_7 , V_8 / 2 , (struct V_2 * ) V_75 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_67 ; V_8 += 2 ) {
struct V_1 * V_76 ;
V_70 = F_9 ( V_66 , V_8 ) ;
V_71 = F_9 ( V_66 , V_8 + 1 ) ;
if ( V_70 == NULL ) {
if ( V_71 == NULL )
continue;
F_55 ( V_49 , V_7 , V_8 / 2 , V_71 ) ;
continue;
}
if ( V_71 == NULL ) {
F_55 ( V_49 , V_7 , V_8 / 2 , V_70 ) ;
continue;
}
V_76 = (struct V_1 * ) F_9 ( V_7 , V_8 / 2 ) ;
F_55 ( V_49 , V_7 , V_8 / 2 , NULL ) ;
F_55 ( V_49 , V_76 , 0 , V_70 ) ;
F_55 ( V_49 , V_76 , 1 , V_71 ) ;
F_55 ( V_49 , V_7 , V_8 / 2 , F_58 ( V_49 , V_76 ) ) ;
}
F_43 ( V_66 ) ;
return V_7 ;
V_73:
F_63 ( V_7 ) ;
return F_64 ( - V_68 ) ;
}
static struct V_27 * F_66 ( struct V_25 * V_12 , int V_39 )
{
struct V_77 * V_20 = & V_12 -> V_38 ;
struct V_78 * V_3 ;
struct V_27 * V_40 ;
F_67 (li, node, head, hlist)
if ( V_40 -> V_39 == V_39 )
return V_40 ;
return NULL ;
}
static inline struct V_79 * F_68 ( struct V_25 * V_12 , int V_39 )
{
struct V_27 * V_40 = F_66 ( V_12 , V_39 ) ;
if ( ! V_40 )
return NULL ;
return & V_40 -> V_41 ;
}
static void F_69 ( struct V_77 * V_20 , struct V_27 * V_80 )
{
struct V_27 * V_40 = NULL , * V_81 = NULL ;
struct V_78 * V_3 ;
if ( F_70 ( V_20 ) ) {
F_71 ( & V_80 -> V_82 , V_20 ) ;
} else {
F_72 (li, node, head, hlist) {
if ( V_80 -> V_39 > V_40 -> V_39 )
break;
V_81 = V_40 ;
}
if ( V_81 )
F_73 ( & V_81 -> V_82 , & V_80 -> V_82 ) ;
else
F_74 ( & V_80 -> V_82 , & V_40 -> V_82 ) ;
}
}
static struct V_25 *
F_75 ( struct V_48 * V_49 , T_3 V_42 )
{
int V_18 ;
struct V_1 * V_7 ;
struct V_2 * V_47 ;
V_18 = 0 ;
V_47 = F_13 ( V_49 -> V_48 ) ;
while ( V_47 != NULL && F_8 ( V_47 ) == V_44 ) {
V_7 = (struct V_1 * ) V_47 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_42 , V_18 , V_7 -> V_18 - V_18 , V_42 ) ) {
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_47 = F_12 ( V_7 ,
F_16 ( V_42 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
} else
break;
}
if ( V_47 != NULL && F_42 ( V_47 ) && F_17 ( V_42 , V_47 -> V_42 ) )
return (struct V_25 * ) V_47 ;
return NULL ;
}
static void F_76 ( struct V_48 * V_49 , struct V_1 * V_7 )
{
int V_50 ;
T_1 V_83 , V_42 ;
struct V_1 * V_84 ;
V_42 = V_7 -> V_42 ;
while ( V_7 != NULL && ( V_84 = F_1 ( (struct V_2 * ) V_7 ) ) != NULL ) {
V_83 = F_16 ( V_42 , V_84 -> V_18 , V_84 -> V_9 ) ;
V_50 = F_54 ( V_84 , F_9 ( V_84 , V_83 ) ) ;
V_7 = (struct V_1 * ) F_58 ( V_49 , (struct V_1 * ) V_7 ) ;
F_56 ( (struct V_1 * ) V_84 , V_83 ,
(struct V_2 * ) V_7 , V_50 ) ;
V_84 = F_1 ( (struct V_2 * ) V_7 ) ;
if ( ! V_84 )
F_57 ( V_49 -> V_48 , (struct V_2 * ) V_7 ) ;
F_44 () ;
if ( ! V_84 )
break;
V_7 = V_84 ;
}
if ( F_65 ( V_7 ) )
V_7 = (struct V_1 * ) F_58 ( V_49 , (struct V_1 * ) V_7 ) ;
F_57 ( V_49 -> V_48 , (struct V_2 * ) V_7 ) ;
F_44 () ;
}
static struct V_79 * F_77 ( struct V_48 * V_49 , T_3 V_42 , int V_39 )
{
int V_18 , V_85 ;
struct V_1 * V_84 = NULL , * V_7 = NULL ;
struct V_2 * V_47 ;
struct V_25 * V_12 ;
int V_86 ;
struct V_79 * V_87 = NULL ;
struct V_27 * V_40 ;
T_1 V_83 ;
V_18 = 0 ;
V_47 = F_11 ( V_49 -> V_48 ) ;
while ( V_47 != NULL && F_8 ( V_47 ) == V_44 ) {
V_7 = (struct V_1 * ) V_47 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_42 , V_18 , V_7 -> V_18 - V_18 , V_42 ) ) {
V_84 = V_7 ;
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_47 = F_9 ( V_7 ,
F_16 ( V_42 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
F_10 ( V_47 && F_1 ( V_47 ) != V_7 ) ;
} else
break;
}
F_10 ( V_84 && F_42 ( V_84 ) ) ;
if ( V_47 != NULL && F_42 ( V_47 ) && F_17 ( V_42 , V_47 -> V_42 ) ) {
V_12 = (struct V_25 * ) V_47 ;
V_40 = F_49 ( V_39 ) ;
if ( ! V_40 )
return NULL ;
V_87 = & V_40 -> V_41 ;
F_69 ( & V_12 -> V_38 , V_40 ) ;
goto V_88;
}
V_12 = F_46 () ;
if ( ! V_12 )
return NULL ;
V_12 -> V_42 = V_42 ;
V_40 = F_49 ( V_39 ) ;
if ( ! V_40 ) {
F_28 ( V_12 ) ;
return NULL ;
}
V_87 = & V_40 -> V_41 ;
F_69 ( & V_12 -> V_38 , V_40 ) ;
if ( V_49 -> V_48 && V_47 == NULL ) {
F_6 ( (struct V_2 * ) V_12 , V_84 ) ;
V_83 = F_16 ( V_42 , V_84 -> V_18 , V_84 -> V_9 ) ;
F_55 ( V_49 , (struct V_1 * ) V_84 , V_83 , (struct V_2 * ) V_12 ) ;
} else {
if ( V_84 )
V_18 = V_84 -> V_18 + V_84 -> V_9 ;
else
V_18 = 0 ;
if ( V_47 ) {
V_85 = F_19 ( V_42 , V_18 , V_47 -> V_42 ) ;
V_7 = F_52 ( V_47 -> V_42 , V_85 , 1 ) ;
} else {
V_85 = 0 ;
V_7 = F_52 ( V_42 , V_85 , 1 ) ;
}
if ( ! V_7 ) {
F_30 ( V_40 ) ;
F_28 ( V_12 ) ;
return NULL ;
}
F_6 ( (struct V_2 * ) V_7 , V_84 ) ;
V_86 = F_16 ( V_42 , V_85 , 1 ) ;
F_55 ( V_49 , V_7 , V_86 , (struct V_2 * ) V_12 ) ;
F_55 ( V_49 , V_7 , 1 - V_86 , V_47 ) ;
if ( V_84 ) {
V_83 = F_16 ( V_42 , V_84 -> V_18 , V_84 -> V_9 ) ;
F_55 ( V_49 , (struct V_1 * ) V_84 , V_83 ,
(struct V_2 * ) V_7 ) ;
} else {
F_57 ( V_49 -> V_48 , (struct V_2 * ) V_7 ) ;
V_84 = V_7 ;
}
}
if ( V_84 && V_84 -> V_18 + V_84 -> V_9 > 32 )
F_78 ( L_5
L_6 ,
V_84 , V_84 -> V_18 , V_84 -> V_9 , V_42 , V_39 ) ;
F_76 ( V_49 , V_84 ) ;
V_88:
return V_87 ;
}
int F_79 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_48 * V_49 = (struct V_48 * ) V_90 -> V_93 ;
struct V_21 * V_22 , * V_94 ;
struct V_79 * V_87 = NULL ;
struct V_95 * V_96 ;
int V_39 = V_92 -> V_97 ;
T_4 V_98 = V_92 -> V_99 ;
T_3 V_42 , V_100 ;
int V_101 ;
struct V_25 * V_12 ;
if ( V_39 > 32 )
return - V_102 ;
V_42 = F_80 ( V_92 -> V_103 ) ;
F_53 ( L_7 , V_90 -> V_104 , V_42 , V_39 ) ;
V_100 = F_80 ( F_81 ( V_39 ) ) ;
if ( V_42 & ~ V_100 )
return - V_102 ;
V_42 = V_42 & V_100 ;
V_96 = F_82 ( V_92 ) ;
if ( F_60 ( V_96 ) ) {
V_101 = F_83 ( V_96 ) ;
goto V_101;
}
V_12 = F_75 ( V_49 , V_42 ) ;
V_22 = NULL ;
if ( V_12 ) {
V_87 = F_68 ( V_12 , V_39 ) ;
V_22 = F_84 ( V_87 , V_98 , V_96 -> V_105 ) ;
}
if ( V_22 && V_22 -> V_106 == V_98 &&
V_22 -> V_107 -> V_105 == V_96 -> V_105 ) {
struct V_21 * V_108 , * V_109 ;
V_101 = - V_110 ;
if ( V_92 -> V_111 & V_112 )
goto V_113;
V_109 = NULL ;
V_108 = V_22 ;
V_22 = F_85 ( V_22 -> V_114 . V_115 , struct V_21 , V_114 ) ;
F_86 (fa, fa_head, fa_list) {
if ( V_22 -> V_106 != V_98 )
break;
if ( V_22 -> V_107 -> V_105 != V_96 -> V_105 )
break;
if ( V_22 -> V_116 == V_92 -> V_117 &&
V_22 -> V_107 == V_96 ) {
V_109 = V_22 ;
break;
}
}
if ( V_92 -> V_111 & V_118 ) {
struct V_95 * V_119 ;
T_4 V_120 ;
V_22 = V_108 ;
if ( V_109 ) {
if ( V_22 == V_109 )
V_101 = 0 ;
goto V_113;
}
V_101 = - V_121 ;
V_94 = F_47 ( V_24 , V_30 ) ;
if ( V_94 == NULL )
goto V_113;
V_119 = V_22 -> V_107 ;
V_94 -> V_106 = V_22 -> V_106 ;
V_94 -> V_107 = V_96 ;
V_94 -> V_116 = V_92 -> V_117 ;
V_120 = V_22 -> V_122 ;
V_94 -> V_122 = V_120 & ~ V_123 ;
F_87 ( & V_22 -> V_114 , & V_94 -> V_114 ) ;
F_25 ( V_22 ) ;
F_88 ( V_119 ) ;
if ( V_120 & V_123 )
F_89 ( V_92 -> V_124 . V_125 , - 1 ) ;
F_90 ( V_126 , F_91 ( V_42 ) , V_94 , V_39 ,
V_90 -> V_104 , & V_92 -> V_124 , V_118 ) ;
goto V_127;
}
if ( V_109 )
goto V_113;
if ( ! ( V_92 -> V_111 & V_128 ) )
V_22 = V_108 ;
}
V_101 = - V_129 ;
if ( ! ( V_92 -> V_111 & V_130 ) )
goto V_113;
V_101 = - V_121 ;
V_94 = F_47 ( V_24 , V_30 ) ;
if ( V_94 == NULL )
goto V_113;
V_94 -> V_107 = V_96 ;
V_94 -> V_106 = V_98 ;
V_94 -> V_116 = V_92 -> V_117 ;
V_94 -> V_122 = 0 ;
if ( ! V_87 ) {
V_87 = F_77 ( V_49 , V_42 , V_39 ) ;
if ( F_92 ( ! V_87 ) ) {
V_101 = - V_68 ;
goto V_131;
}
}
if ( ! V_39 )
V_90 -> V_132 ++ ;
F_93 ( & V_94 -> V_114 ,
( V_22 ? & V_22 -> V_114 : V_87 ) ) ;
F_89 ( V_92 -> V_124 . V_125 , - 1 ) ;
F_90 ( V_126 , F_91 ( V_42 ) , V_94 , V_39 , V_90 -> V_104 ,
& V_92 -> V_124 , 0 ) ;
V_127:
return 0 ;
V_131:
F_24 ( V_24 , V_94 ) ;
V_113:
F_88 ( V_96 ) ;
V_101:
return V_101 ;
}
static int F_94 ( struct V_89 * V_90 , struct V_48 * V_49 , struct V_25 * V_12 ,
T_1 V_42 , const struct V_133 * V_134 ,
struct V_135 * V_136 , int V_137 )
{
struct V_27 * V_40 ;
struct V_77 * V_138 = & V_12 -> V_38 ;
struct V_78 * V_3 ;
F_67 (li, node, hhead, hlist) {
struct V_21 * V_22 ;
int V_39 = V_40 -> V_39 ;
T_5 V_100 = F_81 ( V_39 ) ;
if ( V_12 -> V_42 != ( V_42 & F_80 ( V_100 ) ) )
continue;
F_95 (fa, &li->falh, fa_list) {
struct V_95 * V_96 = V_22 -> V_107 ;
int V_139 , V_101 ;
if ( V_22 -> V_106 && V_22 -> V_106 != V_134 -> V_140 )
continue;
if ( V_22 -> V_107 -> V_141 < V_134 -> V_142 )
continue;
F_96 ( V_22 ) ;
V_101 = V_143 [ V_22 -> V_116 ] . error ;
if ( V_101 ) {
#ifdef F_61
V_49 -> V_63 . V_144 ++ ;
#endif
return V_101 ;
}
if ( V_96 -> V_137 & V_145 )
continue;
for ( V_139 = 0 ; V_139 < V_96 -> V_146 ; V_139 ++ ) {
const struct V_147 * V_148 = & V_96 -> V_147 [ V_139 ] ;
if ( V_148 -> V_149 & V_145 )
continue;
if ( V_134 -> V_150 && V_134 -> V_150 != V_148 -> V_151 )
continue;
#ifdef F_61
V_49 -> V_63 . V_144 ++ ;
#endif
V_136 -> V_152 = V_39 ;
V_136 -> V_153 = V_139 ;
V_136 -> type = V_22 -> V_116 ;
V_136 -> V_154 = V_22 -> V_107 -> V_141 ;
V_136 -> V_96 = V_96 ;
V_136 -> V_155 = V_90 ;
V_136 -> V_87 = & V_40 -> V_41 ;
if ( ! ( V_137 & V_156 ) )
F_97 ( & V_136 -> V_96 -> V_157 ) ;
return 0 ;
}
}
#ifdef F_61
V_49 -> V_63 . V_158 ++ ;
#endif
}
return 1 ;
}
int F_98 ( struct V_89 * V_90 , const struct V_133 * V_134 ,
struct V_135 * V_136 , int V_137 )
{
struct V_48 * V_49 = (struct V_48 * ) V_90 -> V_93 ;
int V_159 ;
struct V_2 * V_47 ;
struct V_1 * V_160 ;
unsigned int V_18 , V_9 ;
T_1 V_42 = F_80 ( V_134 -> V_161 ) ;
unsigned int V_162 ;
T_1 V_83 = 0 ;
unsigned int V_163 = V_13 ;
struct V_1 * V_164 ;
T_1 V_165 ;
F_99 () ;
V_47 = F_100 ( V_49 -> V_48 ) ;
if ( ! V_47 )
goto V_166;
#ifdef F_61
V_49 -> V_63 . gets ++ ;
#endif
if ( F_42 ( V_47 ) ) {
V_159 = F_94 ( V_90 , V_49 , (struct V_25 * ) V_47 , V_42 , V_134 , V_136 , V_137 ) ;
goto V_167;
}
V_160 = (struct V_1 * ) V_47 ;
V_162 = 0 ;
while ( V_160 ) {
V_18 = V_160 -> V_18 ;
V_9 = V_160 -> V_9 ;
if ( ! V_162 )
V_83 = F_16 ( F_15 ( V_42 , V_163 ) ,
V_18 , V_9 ) ;
V_47 = F_12 ( V_160 , V_83 ) ;
if ( V_47 == NULL ) {
#ifdef F_61
V_49 -> V_63 . V_168 ++ ;
#endif
goto V_169;
}
if ( F_42 ( V_47 ) ) {
V_159 = F_94 ( V_90 , V_49 , (struct V_25 * ) V_47 , V_42 , V_134 , V_136 , V_137 ) ;
if ( V_159 > 0 )
goto V_169;
goto V_167;
}
V_164 = (struct V_1 * ) V_47 ;
if ( V_163 < V_18 + V_9 ) {
if ( F_16 ( V_164 -> V_42 , V_163 ,
V_164 -> V_18 - V_163 )
|| ! ( V_164 -> V_10 [ 0 ] ) )
goto V_169;
}
V_165 = F_15 ( V_164 -> V_42 ^ V_42 , V_164 -> V_18 ) ;
if ( V_165 ) {
int V_170 = V_13 - F_101 ( V_165 ) ;
if ( F_16 ( V_164 -> V_42 , V_170 , V_164 -> V_18 - V_170 ) != 0 )
goto V_169;
if ( V_163 >= V_164 -> V_18 )
V_163 = V_170 ;
}
V_160 = (struct V_1 * ) V_47 ;
V_162 = 0 ;
continue;
V_169:
V_162 ++ ;
while ( ( V_162 <= V_160 -> V_9 )
&& ! ( V_83 & ( 1 << ( V_162 - 1 ) ) ) )
V_162 ++ ;
if ( V_163 > V_160 -> V_18 + V_160 -> V_9 - V_162 )
V_163 = V_160 -> V_18 + V_160 -> V_9
- V_162 ;
if ( V_162 <= V_160 -> V_9 ) {
V_83 &= ~ ( 1 << ( V_162 - 1 ) ) ;
} else {
struct V_1 * V_4 = F_4 ( (struct V_2 * ) V_160 ) ;
if ( ! V_4 )
goto V_166;
V_83 = F_16 ( V_160 -> V_42 , V_4 -> V_18 , V_4 -> V_9 ) ;
V_160 = V_4 ;
V_162 = 0 ;
#ifdef F_61
V_49 -> V_63 . V_171 ++ ;
#endif
goto V_169;
}
}
V_166:
V_159 = 1 ;
V_167:
F_102 () ;
return V_159 ;
}
static void F_103 ( struct V_48 * V_49 , struct V_25 * V_12 )
{
struct V_1 * V_84 = F_1 ( (struct V_2 * ) V_12 ) ;
F_53 ( L_8 , V_12 ) ;
if ( V_84 ) {
T_1 V_83 = F_16 ( V_12 -> V_42 , V_84 -> V_18 , V_84 -> V_9 ) ;
F_55 ( V_49 , (struct V_1 * ) V_84 , V_83 , NULL ) ;
F_76 ( V_49 , V_84 ) ;
} else
F_57 ( V_49 -> V_48 , NULL ) ;
F_28 ( V_12 ) ;
}
int F_104 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_48 * V_49 = (struct V_48 * ) V_90 -> V_93 ;
T_3 V_42 , V_100 ;
int V_39 = V_92 -> V_97 ;
T_4 V_98 = V_92 -> V_99 ;
struct V_21 * V_22 , * V_172 ;
struct V_79 * V_87 ;
struct V_25 * V_12 ;
struct V_27 * V_40 ;
if ( V_39 > 32 )
return - V_102 ;
V_42 = F_80 ( V_92 -> V_103 ) ;
V_100 = F_80 ( F_81 ( V_39 ) ) ;
if ( V_42 & ~ V_100 )
return - V_102 ;
V_42 = V_42 & V_100 ;
V_12 = F_75 ( V_49 , V_42 ) ;
if ( ! V_12 )
return - V_173 ;
V_87 = F_68 ( V_12 , V_39 ) ;
V_22 = F_84 ( V_87 , V_98 , 0 ) ;
if ( ! V_22 )
return - V_173 ;
F_53 ( L_9 , V_42 , V_39 , V_98 , V_49 ) ;
V_172 = NULL ;
V_22 = F_85 ( V_22 -> V_114 . V_115 , struct V_21 , V_114 ) ;
F_86 (fa, fa_head, fa_list) {
struct V_95 * V_96 = V_22 -> V_107 ;
if ( V_22 -> V_106 != V_98 )
break;
if ( ( ! V_92 -> V_117 || V_22 -> V_116 == V_92 -> V_117 ) &&
( V_92 -> V_174 == V_175 ||
V_22 -> V_107 -> V_141 == V_92 -> V_174 ) &&
( ! V_92 -> V_176 ||
V_96 -> V_177 == V_92 -> V_176 ) &&
( ! V_92 -> V_178 ||
V_96 -> V_179 == V_92 -> V_178 ) &&
F_105 ( V_92 , V_96 ) == 0 ) {
V_172 = V_22 ;
break;
}
}
if ( ! V_172 )
return - V_173 ;
V_22 = V_172 ;
F_90 ( V_180 , F_91 ( V_42 ) , V_22 , V_39 , V_90 -> V_104 ,
& V_92 -> V_124 , 0 ) ;
V_12 = F_75 ( V_49 , V_42 ) ;
V_40 = F_66 ( V_12 , V_39 ) ;
F_106 ( & V_22 -> V_114 ) ;
if ( ! V_39 )
V_90 -> V_132 -- ;
if ( F_107 ( V_87 ) ) {
F_108 ( & V_40 -> V_82 ) ;
F_30 ( V_40 ) ;
}
if ( F_70 ( & V_12 -> V_38 ) )
F_103 ( V_49 , V_12 ) ;
if ( V_22 -> V_122 & V_123 )
F_89 ( V_92 -> V_124 . V_125 , - 1 ) ;
F_88 ( V_22 -> V_107 ) ;
F_25 ( V_22 ) ;
return 0 ;
}
static int F_109 ( struct V_79 * V_20 )
{
struct V_21 * V_22 , * V_181 ;
int V_167 = 0 ;
F_110 (fa, fa_node, head, fa_list) {
struct V_95 * V_96 = V_22 -> V_107 ;
if ( V_96 && ( V_96 -> V_137 & V_145 ) ) {
F_106 ( & V_22 -> V_114 ) ;
F_88 ( V_22 -> V_107 ) ;
F_25 ( V_22 ) ;
V_167 ++ ;
}
}
return V_167 ;
}
static int F_111 ( struct V_25 * V_12 )
{
int V_167 = 0 ;
struct V_77 * V_182 = & V_12 -> V_38 ;
struct V_78 * V_3 , * V_183 ;
struct V_27 * V_40 = NULL ;
F_112 (li, node, tmp, lih, hlist) {
V_167 += F_109 ( & V_40 -> V_41 ) ;
if ( F_107 ( & V_40 -> V_41 ) ) {
F_108 ( & V_40 -> V_82 ) ;
F_30 ( V_40 ) ;
}
}
return V_167 ;
}
static struct V_25 * F_113 ( struct V_1 * V_184 , struct V_2 * V_185 )
{
do {
T_1 V_186 ;
if ( V_185 )
V_186 = F_16 ( V_185 -> V_42 , V_184 -> V_18 , V_184 -> V_9 ) + 1 ;
else
V_186 = 0 ;
while ( V_186 < 1u << V_184 -> V_9 ) {
V_185 = F_12 ( V_184 , V_186 ++ ) ;
if ( ! V_185 )
continue;
if ( F_42 ( V_185 ) ) {
F_114 ( F_13 ( V_184 -> V_10 [ V_186 ] ) ) ;
return (struct V_25 * ) V_185 ;
}
V_184 = (struct V_1 * ) V_185 ;
V_186 = 0 ;
}
V_185 = (struct V_2 * ) V_184 ;
} while ( ( V_184 = F_4 ( V_185 ) ) != NULL );
return NULL ;
}
static struct V_25 * F_115 ( struct V_48 * V_49 )
{
struct V_1 * V_47 = (struct V_1 * ) F_13 ( V_49 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
if ( F_42 ( V_47 ) )
return (struct V_25 * ) V_47 ;
return F_113 ( V_47 , NULL ) ;
}
static struct V_25 * F_116 ( struct V_25 * V_12 )
{
struct V_2 * V_185 = (struct V_2 * ) V_12 ;
struct V_1 * V_184 = F_4 ( V_185 ) ;
if ( ! V_184 )
return NULL ;
return F_113 ( V_184 , V_185 ) ;
}
static struct V_25 * F_117 ( struct V_48 * V_49 , int V_187 )
{
struct V_25 * V_12 = F_115 ( V_49 ) ;
while ( V_12 && V_187 -- > 0 )
V_12 = F_116 ( V_12 ) ;
return V_12 ;
}
int F_118 ( struct V_89 * V_90 )
{
struct V_48 * V_49 = (struct V_48 * ) V_90 -> V_93 ;
struct V_25 * V_12 , * V_188 = NULL ;
int V_167 = 0 ;
for ( V_12 = F_115 ( V_49 ) ; V_12 ; V_12 = F_116 ( V_12 ) ) {
V_167 += F_111 ( V_12 ) ;
if ( V_188 && F_70 ( & V_188 -> V_38 ) )
F_103 ( V_49 , V_188 ) ;
V_188 = V_12 ;
}
if ( V_188 && F_70 ( & V_188 -> V_38 ) )
F_103 ( V_49 , V_188 ) ;
F_53 ( L_10 , V_167 ) ;
return V_167 ;
}
void F_119 ( struct V_89 * V_90 )
{
F_38 ( V_90 ) ;
}
static int F_120 ( T_1 V_42 , int V_39 , struct V_79 * V_189 ,
struct V_89 * V_90 ,
struct V_190 * V_191 , struct V_192 * V_193 )
{
int V_8 , V_194 ;
struct V_21 * V_22 ;
T_5 V_195 = F_91 ( V_42 ) ;
V_194 = V_193 -> args [ 5 ] ;
V_8 = 0 ;
F_95 (fa, fah, fa_list) {
if ( V_8 < V_194 ) {
V_8 ++ ;
continue;
}
if ( F_121 ( V_191 , F_122 ( V_193 -> V_191 ) . V_196 ,
V_193 -> V_197 -> V_198 ,
V_126 ,
V_90 -> V_104 ,
V_22 -> V_116 ,
V_195 ,
V_39 ,
V_22 -> V_106 ,
V_22 -> V_107 , V_199 ) < 0 ) {
V_193 -> args [ 5 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_193 -> args [ 5 ] = V_8 ;
return V_191 -> V_200 ;
}
static int F_123 ( struct V_25 * V_12 , struct V_89 * V_90 ,
struct V_190 * V_191 , struct V_192 * V_193 )
{
struct V_27 * V_40 ;
struct V_78 * V_3 ;
int V_8 , V_194 ;
V_194 = V_193 -> args [ 4 ] ;
V_8 = 0 ;
F_67 (li, node, &l->list, hlist) {
if ( V_8 < V_194 ) {
V_8 ++ ;
continue;
}
if ( V_8 > V_194 )
V_193 -> args [ 5 ] = 0 ;
if ( F_107 ( & V_40 -> V_41 ) )
continue;
if ( F_120 ( V_12 -> V_42 , V_40 -> V_39 , & V_40 -> V_41 , V_90 , V_191 , V_193 ) < 0 ) {
V_193 -> args [ 4 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_193 -> args [ 4 ] = V_8 ;
return V_191 -> V_200 ;
}
int F_124 ( struct V_89 * V_90 , struct V_190 * V_191 ,
struct V_192 * V_193 )
{
struct V_25 * V_12 ;
struct V_48 * V_49 = (struct V_48 * ) V_90 -> V_93 ;
T_1 V_42 = V_193 -> args [ 2 ] ;
int V_201 = V_193 -> args [ 3 ] ;
F_99 () ;
if ( V_201 == 0 )
V_12 = F_115 ( V_49 ) ;
else {
V_12 = F_75 ( V_49 , V_42 ) ;
if ( ! V_12 )
V_12 = F_117 ( V_49 , V_201 ) ;
}
while ( V_12 ) {
V_193 -> args [ 2 ] = V_12 -> V_42 ;
if ( F_123 ( V_12 , V_90 , V_191 , V_193 ) < 0 ) {
V_193 -> args [ 3 ] = V_201 ;
F_102 () ;
return - 1 ;
}
++ V_201 ;
V_12 = F_116 ( V_12 ) ;
memset ( & V_193 -> args [ 4 ] , 0 ,
sizeof( V_193 -> args ) - 4 * sizeof( V_193 -> args [ 0 ] ) ) ;
}
V_193 -> args [ 3 ] = V_201 ;
F_102 () ;
return V_191 -> V_200 ;
}
void T_6 F_125 ( void )
{
V_24 = F_126 ( L_11 ,
sizeof( struct V_21 ) ,
0 , V_202 , NULL ) ;
V_26 = F_126 ( L_12 ,
F_127 ( sizeof( struct V_25 ) ,
sizeof( struct V_27 ) ) ,
0 , V_202 , NULL ) ;
}
struct V_89 * F_128 ( T_3 V_203 )
{
struct V_89 * V_90 ;
struct V_48 * V_49 ;
V_90 = F_50 ( sizeof( struct V_89 ) + sizeof( struct V_48 ) ,
V_30 ) ;
if ( V_90 == NULL )
return NULL ;
V_90 -> V_104 = V_203 ;
V_90 -> V_204 = - 1 ;
V_90 -> V_132 = 0 ;
V_49 = (struct V_48 * ) V_90 -> V_93 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
return V_90 ;
}
static struct V_2 * F_129 ( struct V_205 * V_206 )
{
struct V_1 * V_7 = V_206 -> V_1 ;
unsigned int V_83 = V_206 -> V_187 ;
struct V_1 * V_184 ;
if ( ! V_7 )
return NULL ;
F_53 ( L_13 ,
V_206 -> V_1 , V_206 -> V_187 , V_206 -> V_207 ) ;
V_208:
while ( V_83 < ( 1 << V_7 -> V_9 ) ) {
struct V_2 * V_47 = F_12 ( V_7 , V_83 ) ;
if ( V_47 ) {
if ( F_42 ( V_47 ) ) {
V_206 -> V_1 = V_7 ;
V_206 -> V_187 = V_83 + 1 ;
} else {
V_206 -> V_1 = (struct V_1 * ) V_47 ;
V_206 -> V_187 = 0 ;
++ V_206 -> V_207 ;
}
return V_47 ;
}
++ V_83 ;
}
V_184 = F_4 ( (struct V_2 * ) V_7 ) ;
if ( V_184 ) {
V_83 = F_16 ( V_7 -> V_42 , V_184 -> V_18 , V_184 -> V_9 ) + 1 ;
V_7 = V_184 ;
-- V_206 -> V_207 ;
goto V_208;
}
return NULL ;
}
static struct V_2 * F_130 ( struct V_205 * V_206 ,
struct V_48 * V_49 )
{
struct V_2 * V_47 ;
if ( ! V_49 )
return NULL ;
V_47 = F_100 ( V_49 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
if ( F_65 ( V_47 ) ) {
V_206 -> V_1 = (struct V_1 * ) V_47 ;
V_206 -> V_187 = 0 ;
V_206 -> V_207 = 1 ;
} else {
V_206 -> V_1 = NULL ;
V_206 -> V_187 = 0 ;
V_206 -> V_207 = 0 ;
}
return V_47 ;
}
static void F_131 ( struct V_48 * V_49 , struct V_209 * V_210 )
{
struct V_2 * V_47 ;
struct V_205 V_206 ;
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
F_99 () ;
for ( V_47 = F_130 ( & V_206 , V_49 ) ; V_47 ; V_47 = F_129 ( & V_206 ) ) {
if ( F_42 ( V_47 ) ) {
struct V_25 * V_12 = (struct V_25 * ) V_47 ;
struct V_27 * V_40 ;
struct V_78 * V_183 ;
V_210 -> V_211 ++ ;
V_210 -> V_212 += V_206 . V_207 ;
if ( V_206 . V_207 > V_210 -> V_213 )
V_210 -> V_213 = V_206 . V_207 ;
F_67 ( V_40 , V_183 , & V_12 -> V_38 , V_82 )
++ V_210 -> V_214 ;
} else {
const struct V_1 * V_7 = ( const struct V_1 * ) V_47 ;
int V_8 ;
V_210 -> V_215 ++ ;
if ( V_7 -> V_9 < V_216 )
V_210 -> V_217 [ V_7 -> V_9 ] ++ ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 -> V_9 ) ; V_8 ++ )
if ( ! V_7 -> V_10 [ V_8 ] )
V_210 -> V_218 ++ ;
}
}
F_102 () ;
}
static void F_132 ( struct V_219 * V_220 , struct V_209 * V_221 )
{
unsigned int V_8 , F_127 , V_222 , V_223 , V_224 ;
if ( V_221 -> V_211 )
V_224 = V_221 -> V_212 * 100 / V_221 -> V_211 ;
else
V_224 = 0 ;
F_133 ( V_220 , L_14 ,
V_224 / 100 , V_224 % 100 ) ;
F_133 ( V_220 , L_15 , V_221 -> V_213 ) ;
F_133 ( V_220 , L_16 , V_221 -> V_211 ) ;
V_223 = sizeof( struct V_25 ) * V_221 -> V_211 ;
F_133 ( V_220 , L_17 , V_221 -> V_214 ) ;
V_223 += sizeof( struct V_27 ) * V_221 -> V_214 ;
F_133 ( V_220 , L_18 , V_221 -> V_215 ) ;
V_223 += sizeof( struct V_1 ) * V_221 -> V_215 ;
F_127 = V_216 ;
while ( F_127 > 0 && V_221 -> V_217 [ F_127 - 1 ] == 0 )
F_127 -- ;
V_222 = 0 ;
for ( V_8 = 1 ; V_8 <= F_127 ; V_8 ++ )
if ( V_221 -> V_217 [ V_8 ] != 0 ) {
F_133 ( V_220 , L_19 , V_8 , V_221 -> V_217 [ V_8 ] ) ;
V_222 += ( 1 << V_8 ) * V_221 -> V_217 [ V_8 ] ;
}
F_134 ( V_220 , '\n' ) ;
F_133 ( V_220 , L_20 , V_222 ) ;
V_223 += sizeof( struct V_2 * ) * V_222 ;
F_133 ( V_220 , L_21 , V_221 -> V_218 ) ;
F_133 ( V_220 , L_22 , ( V_223 + 1023 ) / 1024 ) ;
}
static void F_135 ( struct V_219 * V_220 ,
const struct V_225 * V_63 )
{
F_133 ( V_220 , L_23 ) ;
F_133 ( V_220 , L_24 , V_63 -> gets ) ;
F_133 ( V_220 , L_25 , V_63 -> V_171 ) ;
F_133 ( V_220 , L_26 ,
V_63 -> V_144 ) ;
F_133 ( V_220 , L_27 ,
V_63 -> V_158 ) ;
F_133 ( V_220 , L_28 , V_63 -> V_168 ) ;
F_133 ( V_220 , L_29 ,
V_63 -> V_64 ) ;
}
static void F_136 ( struct V_219 * V_220 , struct V_89 * V_90 )
{
if ( V_90 -> V_104 == V_226 )
F_137 ( V_220 , L_30 ) ;
else if ( V_90 -> V_104 == V_227 )
F_137 ( V_220 , L_31 ) ;
else
F_133 ( V_220 , L_32 , V_90 -> V_104 ) ;
}
static int F_138 ( struct V_219 * V_220 , void * V_228 )
{
struct V_229 * V_229 = (struct V_229 * ) V_220 -> V_230 ;
unsigned int V_231 ;
F_133 ( V_220 ,
L_33
L_34 ,
sizeof( struct V_25 ) , sizeof( struct V_1 ) ) ;
for ( V_231 = 0 ; V_231 < V_232 ; V_231 ++ ) {
struct V_77 * V_20 = & V_229 -> V_233 . V_234 [ V_231 ] ;
struct V_78 * V_3 ;
struct V_89 * V_90 ;
F_67 (tb, node, head, tb_hlist) {
struct V_48 * V_49 = (struct V_48 * ) V_90 -> V_93 ;
struct V_209 V_221 ;
if ( ! V_49 )
continue;
F_136 ( V_220 , V_90 ) ;
F_131 ( V_49 , & V_221 ) ;
F_132 ( V_220 , & V_221 ) ;
#ifdef F_61
F_135 ( V_220 , & V_49 -> V_63 ) ;
#endif
}
}
return 0 ;
}
static int F_139 ( struct V_69 * V_69 , struct V_235 * V_235 )
{
return F_140 ( V_69 , V_235 , F_138 ) ;
}
static struct V_2 * F_141 ( struct V_219 * V_220 , T_7 V_18 )
{
struct V_205 * V_206 = V_220 -> V_230 ;
struct V_229 * V_229 = F_142 ( V_220 ) ;
T_7 V_186 = 0 ;
unsigned int V_231 ;
for ( V_231 = 0 ; V_231 < V_232 ; V_231 ++ ) {
struct V_77 * V_20 = & V_229 -> V_233 . V_234 [ V_231 ] ;
struct V_78 * V_3 ;
struct V_89 * V_90 ;
F_67 (tb, node, head, tb_hlist) {
struct V_2 * V_47 ;
for ( V_47 = F_130 ( V_206 ,
(struct V_48 * ) V_90 -> V_93 ) ;
V_47 ; V_47 = F_129 ( V_206 ) )
if ( V_18 == V_186 ++ ) {
V_206 -> V_90 = V_90 ;
return V_47 ;
}
}
}
return NULL ;
}
static void * F_143 ( struct V_219 * V_220 , T_7 * V_18 )
__acquires( T_8 )
{
F_99 () ;
return F_141 ( V_220 , * V_18 ) ;
}
static void * F_144 ( struct V_219 * V_220 , void * V_228 , T_7 * V_18 )
{
struct V_205 * V_206 = V_220 -> V_230 ;
struct V_229 * V_229 = F_142 ( V_220 ) ;
struct V_89 * V_90 = V_206 -> V_90 ;
struct V_78 * V_236 ;
unsigned int V_231 ;
struct V_2 * V_47 ;
++ * V_18 ;
V_47 = F_129 ( V_206 ) ;
if ( V_47 )
return V_47 ;
V_231 = V_90 -> V_104 & ( V_232 - 1 ) ;
while ( ( V_236 = F_100 ( F_145 ( & V_90 -> V_237 ) ) ) ) {
V_90 = F_146 ( V_236 , struct V_89 , V_237 ) ;
V_47 = F_130 ( V_206 , (struct V_48 * ) V_90 -> V_93 ) ;
if ( V_47 )
goto V_167;
}
while ( ++ V_231 < V_232 ) {
struct V_77 * V_20 = & V_229 -> V_233 . V_234 [ V_231 ] ;
F_67 (tb, tb_node, head, tb_hlist) {
V_47 = F_130 ( V_206 , (struct V_48 * ) V_90 -> V_93 ) ;
if ( V_47 )
goto V_167;
}
}
return NULL ;
V_167:
V_206 -> V_90 = V_90 ;
return V_47 ;
}
static void F_147 ( struct V_219 * V_220 , void * V_228 )
__releases( T_8 )
{
F_102 () ;
}
static void F_148 ( struct V_219 * V_220 , int V_47 )
{
while ( V_47 -- > 0 )
F_137 ( V_220 , L_35 ) ;
}
static inline const char * F_149 ( char * V_238 , T_2 V_200 , enum V_239 V_210 )
{
switch ( V_210 ) {
case V_240 : return L_36 ;
case V_241 : return L_37 ;
case V_242 : return L_38 ;
case V_243 : return L_39 ;
case V_175 : return L_40 ;
default:
snprintf ( V_238 , V_200 , L_41 , V_210 ) ;
return V_238 ;
}
}
static inline const char * F_150 ( char * V_238 , T_2 V_200 , unsigned int V_49 )
{
if ( V_49 < V_244 && V_245 [ V_49 ] )
return V_245 [ V_49 ] ;
snprintf ( V_238 , V_200 , L_42 , V_49 ) ;
return V_238 ;
}
static int F_151 ( struct V_219 * V_220 , void * V_228 )
{
const struct V_205 * V_206 = V_220 -> V_230 ;
struct V_2 * V_47 = V_228 ;
if ( ! F_4 ( V_47 ) )
F_136 ( V_220 , V_206 -> V_90 ) ;
if ( F_65 ( V_47 ) ) {
struct V_1 * V_7 = (struct V_1 * ) V_47 ;
T_5 V_246 = F_91 ( F_15 ( V_7 -> V_42 , V_7 -> V_18 ) ) ;
F_148 ( V_220 , V_206 -> V_207 - 1 ) ;
F_133 ( V_220 , L_43 ,
& V_246 , V_7 -> V_18 , V_7 -> V_9 , V_7 -> V_45 ,
V_7 -> V_46 ) ;
} else {
struct V_25 * V_12 = (struct V_25 * ) V_47 ;
struct V_27 * V_40 ;
struct V_78 * V_3 ;
T_5 V_247 = F_91 ( V_12 -> V_42 ) ;
F_148 ( V_220 , V_206 -> V_207 ) ;
F_133 ( V_220 , L_44 , & V_247 ) ;
F_67 (li, node, &l->list, hlist) {
struct V_21 * V_22 ;
F_95 (fa, &li->falh, fa_list) {
char V_248 [ 32 ] , V_249 [ 32 ] ;
F_148 ( V_220 , V_206 -> V_207 + 1 ) ;
F_133 ( V_220 , L_45 , V_40 -> V_39 ,
F_149 ( V_248 , sizeof( V_248 ) ,
V_22 -> V_107 -> V_141 ) ,
F_150 ( V_249 , sizeof( V_249 ) ,
V_22 -> V_116 ) ) ;
if ( V_22 -> V_106 )
F_133 ( V_220 , L_46 , V_22 -> V_106 ) ;
F_134 ( V_220 , '\n' ) ;
}
}
}
return 0 ;
}
static int F_152 ( struct V_69 * V_69 , struct V_235 * V_235 )
{
return F_153 ( V_69 , V_235 , & V_250 ,
sizeof( struct V_205 ) ) ;
}
static struct V_25 * F_154 ( struct V_251 * V_206 , T_7 V_18 )
{
struct V_25 * V_12 = NULL ;
struct V_48 * V_49 = V_206 -> V_252 ;
if ( V_206 -> V_18 > 0 && V_18 >= V_206 -> V_18 && ( V_12 = F_75 ( V_49 , V_206 -> V_42 ) ) )
V_18 -= V_206 -> V_18 ;
else {
V_206 -> V_18 = 0 ;
V_12 = F_115 ( V_49 ) ;
}
while ( V_12 && V_18 -- > 0 ) {
V_206 -> V_18 ++ ;
V_12 = F_116 ( V_12 ) ;
}
if ( V_12 )
V_206 -> V_42 = V_18 ;
else
V_206 -> V_18 = 0 ;
return V_12 ;
}
static void * F_155 ( struct V_219 * V_220 , T_7 * V_18 )
__acquires( T_8 )
{
struct V_251 * V_206 = V_220 -> V_230 ;
struct V_89 * V_90 ;
F_99 () ;
V_90 = F_156 ( F_142 ( V_220 ) , V_227 ) ;
if ( ! V_90 )
return NULL ;
V_206 -> V_252 = (struct V_48 * ) V_90 -> V_93 ;
if ( * V_18 == 0 )
return V_253 ;
else
return F_154 ( V_206 , * V_18 - 1 ) ;
}
static void * F_157 ( struct V_219 * V_220 , void * V_228 , T_7 * V_18 )
{
struct V_251 * V_206 = V_220 -> V_230 ;
struct V_25 * V_12 = V_228 ;
++ * V_18 ;
if ( V_228 == V_253 ) {
V_206 -> V_18 = 0 ;
V_12 = F_115 ( V_206 -> V_252 ) ;
} else {
V_206 -> V_18 ++ ;
V_12 = F_116 ( V_12 ) ;
}
if ( V_12 )
V_206 -> V_42 = V_12 -> V_42 ;
else
V_206 -> V_18 = 0 ;
return V_12 ;
}
static void F_158 ( struct V_219 * V_220 , void * V_228 )
__releases( T_8 )
{
F_102 () ;
}
static unsigned int F_159 ( int type , T_5 V_100 , const struct V_95 * V_96 )
{
unsigned int V_254 = 0 ;
if ( type == V_255 || type == V_256 )
V_254 = V_257 ;
if ( V_96 && V_96 -> V_147 -> V_258 )
V_254 |= V_259 ;
if ( V_100 == F_91 ( 0xFFFFFFFF ) )
V_254 |= V_260 ;
V_254 |= V_261 ;
return V_254 ;
}
static int F_160 ( struct V_219 * V_220 , void * V_228 )
{
struct V_25 * V_12 = V_228 ;
struct V_27 * V_40 ;
struct V_78 * V_3 ;
if ( V_228 == V_253 ) {
F_133 ( V_220 , L_47 , L_48
L_49
L_50 ) ;
return 0 ;
}
F_67 (li, node, &l->list, hlist) {
struct V_21 * V_22 ;
T_5 V_100 , V_262 ;
V_100 = F_81 ( V_40 -> V_39 ) ;
V_262 = F_91 ( V_12 -> V_42 ) ;
F_95 (fa, &li->falh, fa_list) {
const struct V_95 * V_96 = V_22 -> V_107 ;
unsigned int V_254 = F_159 ( V_22 -> V_116 , V_100 , V_96 ) ;
int V_200 ;
if ( V_22 -> V_116 == V_263
|| V_22 -> V_116 == V_264 )
continue;
if ( V_96 )
F_133 ( V_220 ,
L_51
L_52 ,
V_96 -> V_265 ? V_96 -> V_265 -> V_266 : L_53 ,
V_262 ,
V_96 -> V_147 -> V_258 , V_254 , 0 , 0 ,
V_96 -> V_105 ,
V_100 ,
( V_96 -> V_267 ?
V_96 -> V_267 + 40 : 0 ) ,
V_96 -> V_268 ,
V_96 -> V_269 >> 3 , & V_200 ) ;
else
F_133 ( V_220 ,
L_54
L_52 ,
V_262 , 0 , V_254 , 0 , 0 , 0 ,
V_100 , 0 , 0 , 0 , & V_200 ) ;
F_133 ( V_220 , L_55 , 127 - V_200 , L_56 ) ;
}
}
return 0 ;
}
static int F_161 ( struct V_69 * V_69 , struct V_235 * V_235 )
{
return F_153 ( V_69 , V_235 , & V_270 ,
sizeof( struct V_251 ) ) ;
}
int T_9 F_162 ( struct V_229 * V_229 )
{
if ( ! F_163 ( V_229 , L_5 , V_271 , & V_272 ) )
goto V_273;
if ( ! F_163 ( V_229 , L_57 , V_271 ,
& V_274 ) )
goto V_275;
if ( ! F_163 ( V_229 , L_58 , V_271 , & V_276 ) )
goto V_277;
return 0 ;
V_277:
F_164 ( V_229 , L_57 ) ;
V_275:
F_164 ( V_229 , L_5 ) ;
V_273:
return - V_68 ;
}
void T_10 F_165 ( struct V_229 * V_229 )
{
F_164 ( V_229 , L_5 ) ;
F_164 ( V_229 , L_57 ) ;
F_164 ( V_229 , L_58 ) ;
}
