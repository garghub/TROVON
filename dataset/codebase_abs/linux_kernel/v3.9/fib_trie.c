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
F_26 ( & V_12 -> V_23 , F_27 ) ;
}
static inline void F_29 ( struct V_27 * V_25 )
{
F_30 ( V_25 , V_23 ) ;
}
static struct V_1 * F_31 ( T_2 V_28 )
{
if ( V_28 <= V_29 )
return F_32 ( V_28 , V_30 ) ;
else
return F_33 ( V_28 ) ;
}
static void F_34 ( struct V_31 * V_32 )
{
struct V_1 * V_7 = F_23 ( V_32 , struct V_1 , V_33 ) ;
F_35 ( V_7 ) ;
}
static void F_36 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = F_23 ( V_20 , struct V_1 , V_23 ) ;
T_2 V_28 = sizeof( struct V_1 ) +
( sizeof( struct V_2 * ) << V_7 -> V_9 ) ;
if ( V_28 <= V_29 )
F_37 ( V_7 ) ;
else {
F_38 ( & V_7 -> V_33 , F_34 ) ;
F_39 ( & V_7 -> V_33 ) ;
}
}
static inline void F_40 ( struct V_1 * V_7 )
{
if ( F_41 ( V_7 ) )
F_28 ( (struct V_25 * ) V_7 ) ;
else
F_26 ( & V_7 -> V_23 , F_36 ) ;
}
static void F_42 ( struct V_1 * V_7 )
{
F_10 ( F_41 ( V_7 ) ) ;
V_7 -> F_40 = V_34 ;
V_34 = V_7 ;
V_35 += sizeof( struct V_1 ) +
( sizeof( struct V_2 * ) << V_7 -> V_9 ) ;
}
static void F_43 ( void )
{
struct V_1 * V_7 ;
while ( ( V_7 = V_34 ) ) {
V_34 = V_7 -> F_40 ;
V_7 -> F_40 = NULL ;
F_40 ( V_7 ) ;
}
if ( V_35 >= V_29 * V_36 ) {
V_35 = 0 ;
F_44 () ;
}
}
static struct V_25 * F_45 ( void )
{
struct V_25 * V_12 = F_46 ( V_26 , V_30 ) ;
if ( V_12 ) {
V_12 -> V_4 = V_37 ;
F_47 ( & V_12 -> V_38 ) ;
}
return V_12 ;
}
static struct V_27 * F_48 ( int V_39 )
{
struct V_27 * V_40 = F_49 ( sizeof( struct V_27 ) , V_30 ) ;
if ( V_40 ) {
V_40 -> V_39 = V_39 ;
V_40 -> V_41 = F_50 ( F_51 ( V_39 ) ) ;
F_52 ( & V_40 -> V_42 ) ;
}
return V_40 ;
}
static struct V_1 * F_53 ( T_1 V_43 , int V_18 , int V_9 )
{
T_2 V_44 = sizeof( struct V_1 ) + ( sizeof( struct V_2 * ) << V_9 ) ;
struct V_1 * V_7 = F_31 ( V_44 ) ;
if ( V_7 ) {
V_7 -> V_4 = V_45 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_43 = V_43 ;
V_7 -> V_46 = 0 ;
V_7 -> V_47 = 1 << V_9 ;
}
F_54 ( L_1 , V_7 , sizeof( struct V_1 ) ,
sizeof( struct V_2 * ) << V_9 ) ;
return V_7 ;
}
static inline int F_55 ( const struct V_1 * V_7 , const struct V_2 * V_48 )
{
if ( V_48 == NULL || F_41 ( V_48 ) )
return 0 ;
return ( (struct V_1 * ) V_48 ) -> V_18 == V_7 -> V_18 + V_7 -> V_9 ;
}
static inline void F_56 ( struct V_1 * V_7 , int V_8 ,
struct V_2 * V_48 )
{
F_57 ( V_7 , V_8 , V_48 , - 1 ) ;
}
static void F_57 ( struct V_1 * V_7 , int V_8 , struct V_2 * V_48 ,
int V_49 )
{
struct V_2 * V_50 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
int V_51 ;
F_10 ( V_8 >= 1 << V_7 -> V_9 ) ;
if ( V_48 == NULL && V_50 != NULL )
V_7 -> V_47 ++ ;
else if ( V_48 != NULL && V_50 == NULL )
V_7 -> V_47 -- ;
if ( V_49 == - 1 )
V_49 = F_55 ( V_7 , V_50 ) ;
V_51 = F_55 ( V_7 , V_48 ) ;
if ( V_49 && ! V_51 )
V_7 -> V_46 -- ;
else if ( ! V_49 && V_51 )
V_7 -> V_46 ++ ;
if ( V_48 )
F_6 ( V_48 , V_7 ) ;
F_58 ( V_7 -> V_10 [ V_8 ] , V_48 ) ;
}
static struct V_2 * F_59 ( struct V_52 * V_53 , struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_54 ;
int V_55 ;
int V_56 ;
int V_57 ;
if ( ! V_7 )
return NULL ;
F_54 ( L_2 ,
V_7 , V_58 , V_59 ) ;
if ( V_7 -> V_47 == F_14 ( V_7 ) ) {
F_42 ( V_7 ) ;
return NULL ;
}
if ( V_7 -> V_47 == F_14 ( V_7 ) - 1 )
goto V_60;
F_20 ( V_7 ) ;
if ( ! F_1 ( (struct V_2 * ) V_7 ) ) {
V_55 = V_61 ;
V_56 = V_62 ;
} else {
V_55 = V_58 ;
V_56 = V_59 ;
}
V_57 = V_63 ;
while ( ( V_7 -> V_46 > 0 && V_57 -- &&
50 * ( V_7 -> V_46 + F_14 ( V_7 )
- V_7 -> V_47 )
>= V_55 * F_14 ( V_7 ) ) ) {
V_54 = V_7 ;
V_7 = F_60 ( V_53 , V_7 ) ;
if ( F_61 ( V_7 ) ) {
V_7 = V_54 ;
#ifdef F_62
V_53 -> V_64 . V_65 ++ ;
#endif
break;
}
}
F_20 ( V_7 ) ;
if ( V_57 != V_63 )
return (struct V_2 * ) V_7 ;
V_57 = V_63 ;
while ( V_7 -> V_9 > 1 && V_57 -- &&
100 * ( F_14 ( V_7 ) - V_7 -> V_47 ) <
V_56 * F_14 ( V_7 ) ) {
V_54 = V_7 ;
V_7 = F_63 ( V_53 , V_7 ) ;
if ( F_61 ( V_7 ) ) {
V_7 = V_54 ;
#ifdef F_62
V_53 -> V_64 . V_65 ++ ;
#endif
break;
}
}
if ( V_7 -> V_47 == F_14 ( V_7 ) - 1 ) {
V_60:
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
struct V_2 * V_48 ;
V_48 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( ! V_48 )
continue;
F_6 ( V_48 , NULL ) ;
F_42 ( V_7 ) ;
return V_48 ;
}
}
return (struct V_2 * ) V_7 ;
}
static void F_64 ( struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_66 ;
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
V_66 = (struct V_1 * ) F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( V_66 )
F_40 ( V_66 ) ;
}
F_40 ( V_7 ) ;
}
static struct V_1 * F_60 ( struct V_52 * V_53 , struct V_1 * V_7 )
{
struct V_1 * V_67 = V_7 ;
int V_68 = F_14 ( V_7 ) ;
int V_8 ;
F_54 ( L_3 ) ;
V_7 = F_53 ( V_67 -> V_43 , V_67 -> V_18 , V_67 -> V_9 + 1 ) ;
if ( ! V_7 )
return F_65 ( - V_69 ) ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
struct V_1 * V_70 ;
V_70 = (struct V_1 * ) F_9 ( V_67 , V_8 ) ;
if ( V_70 &&
F_66 ( V_70 ) &&
V_70 -> V_18 == V_67 -> V_18 + V_67 -> V_9 &&
V_70 -> V_9 > 1 ) {
struct V_1 * V_71 , * V_72 ;
T_1 V_73 = ~ 0U << ( V_13 - 1 ) >> V_70 -> V_18 ;
V_71 = F_53 ( V_70 -> V_43 & ( ~ V_73 ) , V_70 -> V_18 + 1 ,
V_70 -> V_9 - 1 ) ;
if ( ! V_71 )
goto V_74;
V_72 = F_53 ( V_70 -> V_43 | V_73 , V_70 -> V_18 + 1 ,
V_70 -> V_9 - 1 ) ;
if ( ! V_72 ) {
F_40 ( V_71 ) ;
goto V_74;
}
F_56 ( V_7 , 2 * V_8 , (struct V_2 * ) V_71 ) ;
F_56 ( V_7 , 2 * V_8 + 1 , (struct V_2 * ) V_72 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
struct V_1 * V_70 ;
struct V_2 * V_3 = F_9 ( V_67 , V_8 ) ;
struct V_1 * V_71 , * V_72 ;
int V_28 , V_75 ;
if ( V_3 == NULL )
continue;
if ( F_41 ( V_3 ) || ( (struct V_1 * ) V_3 ) -> V_18 >
V_7 -> V_18 + V_7 -> V_9 - 1 ) {
if ( F_16 ( V_3 -> V_43 ,
V_67 -> V_18 + V_67 -> V_9 ,
1 ) == 0 )
F_56 ( V_7 , 2 * V_8 , V_3 ) ;
else
F_56 ( V_7 , 2 * V_8 + 1 , V_3 ) ;
continue;
}
V_70 = (struct V_1 * ) V_3 ;
if ( V_70 -> V_9 == 1 ) {
F_56 ( V_7 , 2 * V_8 , F_11 ( V_70 -> V_10 [ 0 ] ) ) ;
F_56 ( V_7 , 2 * V_8 + 1 , F_11 ( V_70 -> V_10 [ 1 ] ) ) ;
F_42 ( V_70 ) ;
continue;
}
V_71 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 ) ;
F_56 ( V_7 , 2 * V_8 , NULL ) ;
F_10 ( ! V_71 ) ;
V_72 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 + 1 ) ;
F_56 ( V_7 , 2 * V_8 + 1 , NULL ) ;
F_10 ( ! V_72 ) ;
V_28 = F_14 ( V_71 ) ;
for ( V_75 = 0 ; V_75 < V_28 ; V_75 ++ ) {
F_56 ( V_71 , V_75 , F_11 ( V_70 -> V_10 [ V_75 ] ) ) ;
F_56 ( V_72 , V_75 , F_11 ( V_70 -> V_10 [ V_75 + V_28 ] ) ) ;
}
F_56 ( V_7 , 2 * V_8 , F_59 ( V_53 , V_71 ) ) ;
F_56 ( V_7 , 2 * V_8 + 1 , F_59 ( V_53 , V_72 ) ) ;
F_42 ( V_70 ) ;
}
F_42 ( V_67 ) ;
return V_7 ;
V_74:
F_64 ( V_7 ) ;
return F_65 ( - V_69 ) ;
}
static struct V_1 * F_63 ( struct V_52 * V_53 , struct V_1 * V_7 )
{
struct V_1 * V_67 = V_7 ;
struct V_2 * V_71 , * V_72 ;
int V_8 ;
int V_68 = F_14 ( V_7 ) ;
F_54 ( L_4 ) ;
V_7 = F_53 ( V_67 -> V_43 , V_67 -> V_18 , V_67 -> V_9 - 1 ) ;
if ( ! V_7 )
return F_65 ( - V_69 ) ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 += 2 ) {
V_71 = F_9 ( V_67 , V_8 ) ;
V_72 = F_9 ( V_67 , V_8 + 1 ) ;
if ( V_71 && V_72 ) {
struct V_1 * V_76 ;
V_76 = F_53 ( V_71 -> V_43 , V_7 -> V_18 + V_7 -> V_9 , 1 ) ;
if ( ! V_76 )
goto V_74;
F_56 ( V_7 , V_8 / 2 , (struct V_2 * ) V_76 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_68 ; V_8 += 2 ) {
struct V_1 * V_77 ;
V_71 = F_9 ( V_67 , V_8 ) ;
V_72 = F_9 ( V_67 , V_8 + 1 ) ;
if ( V_71 == NULL ) {
if ( V_72 == NULL )
continue;
F_56 ( V_7 , V_8 / 2 , V_72 ) ;
continue;
}
if ( V_72 == NULL ) {
F_56 ( V_7 , V_8 / 2 , V_71 ) ;
continue;
}
V_77 = (struct V_1 * ) F_9 ( V_7 , V_8 / 2 ) ;
F_56 ( V_7 , V_8 / 2 , NULL ) ;
F_56 ( V_77 , 0 , V_71 ) ;
F_56 ( V_77 , 1 , V_72 ) ;
F_56 ( V_7 , V_8 / 2 , F_59 ( V_53 , V_77 ) ) ;
}
F_42 ( V_67 ) ;
return V_7 ;
V_74:
F_64 ( V_7 ) ;
return F_65 ( - V_69 ) ;
}
static struct V_27 * F_67 ( struct V_25 * V_12 , int V_39 )
{
struct V_78 * V_20 = & V_12 -> V_38 ;
struct V_27 * V_40 ;
F_68 (li, head, hlist)
if ( V_40 -> V_39 == V_39 )
return V_40 ;
return NULL ;
}
static inline struct V_79 * F_69 ( struct V_25 * V_12 , int V_39 )
{
struct V_27 * V_40 = F_67 ( V_12 , V_39 ) ;
if ( ! V_40 )
return NULL ;
return & V_40 -> V_42 ;
}
static void F_70 ( struct V_78 * V_20 , struct V_27 * V_80 )
{
struct V_27 * V_40 = NULL , * V_81 = NULL ;
if ( F_71 ( V_20 ) ) {
F_72 ( & V_80 -> V_82 , V_20 ) ;
} else {
F_73 (li, head, hlist) {
if ( V_80 -> V_39 > V_40 -> V_39 )
break;
V_81 = V_40 ;
}
if ( V_81 )
F_74 ( & V_81 -> V_82 , & V_80 -> V_82 ) ;
else
F_75 ( & V_80 -> V_82 , & V_40 -> V_82 ) ;
}
}
static struct V_25 *
F_76 ( struct V_52 * V_53 , T_3 V_43 )
{
int V_18 ;
struct V_1 * V_7 ;
struct V_2 * V_48 ;
V_18 = 0 ;
V_48 = F_13 ( V_53 -> V_52 ) ;
while ( V_48 != NULL && F_8 ( V_48 ) == V_45 ) {
V_7 = (struct V_1 * ) V_48 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_43 , V_18 , V_7 -> V_18 - V_18 , V_43 ) ) {
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_48 = F_12 ( V_7 ,
F_16 ( V_43 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
} else
break;
}
if ( V_48 != NULL && F_41 ( V_48 ) && F_17 ( V_43 , V_48 -> V_43 ) )
return (struct V_25 * ) V_48 ;
return NULL ;
}
static void F_77 ( struct V_52 * V_53 , struct V_1 * V_7 )
{
int V_49 ;
T_1 V_83 , V_43 ;
struct V_1 * V_84 ;
V_43 = V_7 -> V_43 ;
while ( V_7 != NULL && ( V_84 = F_1 ( (struct V_2 * ) V_7 ) ) != NULL ) {
V_83 = F_16 ( V_43 , V_84 -> V_18 , V_84 -> V_9 ) ;
V_49 = F_55 ( V_84 , F_9 ( V_84 , V_83 ) ) ;
V_7 = (struct V_1 * ) F_59 ( V_53 , V_7 ) ;
F_57 ( V_84 , V_83 ,
(struct V_2 * ) V_7 , V_49 ) ;
V_84 = F_1 ( (struct V_2 * ) V_7 ) ;
if ( ! V_84 )
F_58 ( V_53 -> V_52 , (struct V_2 * ) V_7 ) ;
F_43 () ;
if ( ! V_84 )
break;
V_7 = V_84 ;
}
if ( F_66 ( V_7 ) )
V_7 = (struct V_1 * ) F_59 ( V_53 , V_7 ) ;
F_58 ( V_53 -> V_52 , (struct V_2 * ) V_7 ) ;
F_43 () ;
}
static struct V_79 * F_78 ( struct V_52 * V_53 , T_3 V_43 , int V_39 )
{
int V_18 , V_85 ;
struct V_1 * V_84 = NULL , * V_7 = NULL ;
struct V_2 * V_48 ;
struct V_25 * V_12 ;
int V_86 ;
struct V_79 * V_87 = NULL ;
struct V_27 * V_40 ;
T_1 V_83 ;
V_18 = 0 ;
V_48 = F_11 ( V_53 -> V_52 ) ;
while ( V_48 != NULL && F_8 ( V_48 ) == V_45 ) {
V_7 = (struct V_1 * ) V_48 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_43 , V_18 , V_7 -> V_18 - V_18 , V_43 ) ) {
V_84 = V_7 ;
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_48 = F_9 ( V_7 ,
F_16 ( V_43 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
F_10 ( V_48 && F_1 ( V_48 ) != V_7 ) ;
} else
break;
}
F_10 ( V_84 && F_41 ( V_84 ) ) ;
if ( V_48 != NULL && F_41 ( V_48 ) && F_17 ( V_43 , V_48 -> V_43 ) ) {
V_12 = (struct V_25 * ) V_48 ;
V_40 = F_48 ( V_39 ) ;
if ( ! V_40 )
return NULL ;
V_87 = & V_40 -> V_42 ;
F_70 ( & V_12 -> V_38 , V_40 ) ;
goto V_88;
}
V_12 = F_45 () ;
if ( ! V_12 )
return NULL ;
V_12 -> V_43 = V_43 ;
V_40 = F_48 ( V_39 ) ;
if ( ! V_40 ) {
F_28 ( V_12 ) ;
return NULL ;
}
V_87 = & V_40 -> V_42 ;
F_70 ( & V_12 -> V_38 , V_40 ) ;
if ( V_53 -> V_52 && V_48 == NULL ) {
F_6 ( (struct V_2 * ) V_12 , V_84 ) ;
V_83 = F_16 ( V_43 , V_84 -> V_18 , V_84 -> V_9 ) ;
F_56 ( V_84 , V_83 , (struct V_2 * ) V_12 ) ;
} else {
if ( V_84 )
V_18 = V_84 -> V_18 + V_84 -> V_9 ;
else
V_18 = 0 ;
if ( V_48 ) {
V_85 = F_19 ( V_43 , V_18 , V_48 -> V_43 ) ;
V_7 = F_53 ( V_48 -> V_43 , V_85 , 1 ) ;
} else {
V_85 = 0 ;
V_7 = F_53 ( V_43 , V_85 , 1 ) ;
}
if ( ! V_7 ) {
F_29 ( V_40 ) ;
F_28 ( V_12 ) ;
return NULL ;
}
F_6 ( (struct V_2 * ) V_7 , V_84 ) ;
V_86 = F_16 ( V_43 , V_85 , 1 ) ;
F_56 ( V_7 , V_86 , (struct V_2 * ) V_12 ) ;
F_56 ( V_7 , 1 - V_86 , V_48 ) ;
if ( V_84 ) {
V_83 = F_16 ( V_43 , V_84 -> V_18 , V_84 -> V_9 ) ;
F_56 ( V_84 , V_83 , (struct V_2 * ) V_7 ) ;
} else {
F_58 ( V_53 -> V_52 , (struct V_2 * ) V_7 ) ;
V_84 = V_7 ;
}
}
if ( V_84 && V_84 -> V_18 + V_84 -> V_9 > 32 )
F_79 ( L_5 ,
V_84 , V_84 -> V_18 , V_84 -> V_9 , V_43 , V_39 ) ;
F_77 ( V_53 , V_84 ) ;
V_88:
return V_87 ;
}
int F_80 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_52 * V_53 = (struct V_52 * ) V_90 -> V_93 ;
struct V_21 * V_22 , * V_94 ;
struct V_79 * V_87 = NULL ;
struct V_95 * V_96 ;
int V_39 = V_92 -> V_97 ;
T_4 V_98 = V_92 -> V_99 ;
T_3 V_43 , V_100 ;
int V_101 ;
struct V_25 * V_12 ;
if ( V_39 > 32 )
return - V_102 ;
V_43 = F_50 ( V_92 -> V_103 ) ;
F_54 ( L_6 , V_90 -> V_104 , V_43 , V_39 ) ;
V_100 = F_50 ( F_51 ( V_39 ) ) ;
if ( V_43 & ~ V_100 )
return - V_102 ;
V_43 = V_43 & V_100 ;
V_96 = F_81 ( V_92 ) ;
if ( F_61 ( V_96 ) ) {
V_101 = F_82 ( V_96 ) ;
goto V_101;
}
V_12 = F_76 ( V_53 , V_43 ) ;
V_22 = NULL ;
if ( V_12 ) {
V_87 = F_69 ( V_12 , V_39 ) ;
V_22 = F_83 ( V_87 , V_98 , V_96 -> V_105 ) ;
}
if ( V_22 && V_22 -> V_106 == V_98 &&
V_22 -> V_107 -> V_105 == V_96 -> V_105 ) {
struct V_21 * V_108 , * V_109 ;
V_101 = - V_110 ;
if ( V_92 -> V_111 & V_112 )
goto V_113;
V_109 = NULL ;
V_108 = V_22 ;
V_22 = F_84 ( V_22 -> V_114 . V_115 , struct V_21 , V_114 ) ;
F_85 (fa, fa_head, fa_list) {
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
V_94 = F_46 ( V_24 , V_30 ) ;
if ( V_94 == NULL )
goto V_113;
V_119 = V_22 -> V_107 ;
V_94 -> V_106 = V_22 -> V_106 ;
V_94 -> V_107 = V_96 ;
V_94 -> V_116 = V_92 -> V_117 ;
V_120 = V_22 -> V_122 ;
V_94 -> V_122 = V_120 & ~ V_123 ;
F_86 ( & V_22 -> V_114 , & V_94 -> V_114 ) ;
F_25 ( V_22 ) ;
F_87 ( V_119 ) ;
if ( V_120 & V_123 )
F_88 ( V_92 -> V_124 . V_125 ) ;
F_89 ( V_126 , F_90 ( V_43 ) , V_94 , V_39 ,
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
V_94 = F_46 ( V_24 , V_30 ) ;
if ( V_94 == NULL )
goto V_113;
V_94 -> V_107 = V_96 ;
V_94 -> V_106 = V_98 ;
V_94 -> V_116 = V_92 -> V_117 ;
V_94 -> V_122 = 0 ;
if ( ! V_87 ) {
V_87 = F_78 ( V_53 , V_43 , V_39 ) ;
if ( F_91 ( ! V_87 ) ) {
V_101 = - V_69 ;
goto V_131;
}
}
if ( ! V_39 )
V_90 -> V_132 ++ ;
F_92 ( & V_94 -> V_114 ,
( V_22 ? & V_22 -> V_114 : V_87 ) ) ;
F_88 ( V_92 -> V_124 . V_125 ) ;
F_89 ( V_126 , F_90 ( V_43 ) , V_94 , V_39 , V_90 -> V_104 ,
& V_92 -> V_124 , 0 ) ;
V_127:
return 0 ;
V_131:
F_24 ( V_24 , V_94 ) ;
V_113:
F_87 ( V_96 ) ;
V_101:
return V_101 ;
}
static int F_93 ( struct V_89 * V_90 , struct V_52 * V_53 , struct V_25 * V_12 ,
T_1 V_43 , const struct V_133 * V_134 ,
struct V_135 * V_136 , int V_137 )
{
struct V_27 * V_40 ;
struct V_78 * V_138 = & V_12 -> V_38 ;
F_68 (li, hhead, hlist) {
struct V_21 * V_22 ;
if ( V_12 -> V_43 != ( V_43 & V_40 -> V_41 ) )
continue;
F_94 (fa, &li->falh, fa_list) {
struct V_95 * V_96 = V_22 -> V_107 ;
int V_139 , V_101 ;
if ( V_22 -> V_106 && V_22 -> V_106 != V_134 -> V_140 )
continue;
if ( V_96 -> V_141 )
continue;
if ( V_22 -> V_107 -> V_142 < V_134 -> V_143 )
continue;
F_95 ( V_22 ) ;
V_101 = V_144 [ V_22 -> V_116 ] . error ;
if ( V_101 ) {
#ifdef F_62
V_53 -> V_64 . V_145 ++ ;
#endif
return V_101 ;
}
if ( V_96 -> V_137 & V_146 )
continue;
for ( V_139 = 0 ; V_139 < V_96 -> V_147 ; V_139 ++ ) {
const struct V_148 * V_149 = & V_96 -> V_148 [ V_139 ] ;
if ( V_149 -> V_150 & V_146 )
continue;
if ( V_134 -> V_151 && V_134 -> V_151 != V_149 -> V_152 )
continue;
#ifdef F_62
V_53 -> V_64 . V_145 ++ ;
#endif
V_136 -> V_153 = V_40 -> V_39 ;
V_136 -> V_154 = V_139 ;
V_136 -> type = V_22 -> V_116 ;
V_136 -> V_155 = V_22 -> V_107 -> V_142 ;
V_136 -> V_96 = V_96 ;
V_136 -> V_156 = V_90 ;
V_136 -> V_87 = & V_40 -> V_42 ;
if ( ! ( V_137 & V_157 ) )
F_96 ( & V_96 -> V_158 ) ;
return 0 ;
}
}
#ifdef F_62
V_53 -> V_64 . V_159 ++ ;
#endif
}
return 1 ;
}
int F_97 ( struct V_89 * V_90 , const struct V_133 * V_134 ,
struct V_135 * V_136 , int V_137 )
{
struct V_52 * V_53 = (struct V_52 * ) V_90 -> V_93 ;
int V_160 ;
struct V_2 * V_48 ;
struct V_1 * V_161 ;
unsigned int V_18 , V_9 ;
T_1 V_43 = F_50 ( V_134 -> V_162 ) ;
unsigned int V_163 ;
T_1 V_83 = 0 ;
unsigned int V_164 = V_13 ;
struct V_1 * V_165 ;
T_1 V_166 ;
F_98 () ;
V_48 = F_99 ( V_53 -> V_52 ) ;
if ( ! V_48 )
goto V_167;
#ifdef F_62
V_53 -> V_64 . gets ++ ;
#endif
if ( F_41 ( V_48 ) ) {
V_160 = F_93 ( V_90 , V_53 , (struct V_25 * ) V_48 , V_43 , V_134 , V_136 , V_137 ) ;
goto V_168;
}
V_161 = (struct V_1 * ) V_48 ;
V_163 = 0 ;
while ( V_161 ) {
V_18 = V_161 -> V_18 ;
V_9 = V_161 -> V_9 ;
if ( ! V_163 )
V_83 = F_16 ( F_15 ( V_43 , V_164 ) ,
V_18 , V_9 ) ;
V_48 = F_12 ( V_161 , V_83 ) ;
if ( V_48 == NULL ) {
#ifdef F_62
V_53 -> V_64 . V_169 ++ ;
#endif
goto V_170;
}
if ( F_41 ( V_48 ) ) {
V_160 = F_93 ( V_90 , V_53 , (struct V_25 * ) V_48 , V_43 , V_134 , V_136 , V_137 ) ;
if ( V_160 > 0 )
goto V_170;
goto V_168;
}
V_165 = (struct V_1 * ) V_48 ;
if ( V_164 < V_18 + V_9 ) {
if ( F_16 ( V_165 -> V_43 , V_164 ,
V_165 -> V_18 - V_164 )
|| ! ( V_165 -> V_10 [ 0 ] ) )
goto V_170;
}
V_166 = F_15 ( V_165 -> V_43 ^ V_43 , V_165 -> V_18 ) ;
if ( V_166 ) {
int V_171 = V_13 - F_100 ( V_166 ) - 1 ;
if ( F_16 ( V_165 -> V_43 , V_171 , V_165 -> V_18 - V_171 ) != 0 )
goto V_170;
if ( V_164 >= V_165 -> V_18 )
V_164 = V_171 ;
}
V_161 = (struct V_1 * ) V_48 ;
V_163 = 0 ;
continue;
V_170:
V_163 ++ ;
while ( ( V_163 <= V_161 -> V_9 )
&& ! ( V_83 & ( 1 << ( V_163 - 1 ) ) ) )
V_163 ++ ;
if ( V_164 > V_161 -> V_18 + V_161 -> V_9 - V_163 )
V_164 = V_161 -> V_18 + V_161 -> V_9
- V_163 ;
if ( V_163 <= V_161 -> V_9 ) {
V_83 &= ~ ( 1 << ( V_163 - 1 ) ) ;
} else {
struct V_1 * V_4 = F_4 ( (struct V_2 * ) V_161 ) ;
if ( ! V_4 )
goto V_167;
V_83 = F_16 ( V_161 -> V_43 , V_4 -> V_18 , V_4 -> V_9 ) ;
V_161 = V_4 ;
V_163 = 0 ;
#ifdef F_62
V_53 -> V_64 . V_172 ++ ;
#endif
goto V_170;
}
}
V_167:
V_160 = 1 ;
V_168:
F_101 () ;
return V_160 ;
}
static void F_102 ( struct V_52 * V_53 , struct V_25 * V_12 )
{
struct V_1 * V_84 = F_1 ( (struct V_2 * ) V_12 ) ;
F_54 ( L_7 , V_12 ) ;
if ( V_84 ) {
T_1 V_83 = F_16 ( V_12 -> V_43 , V_84 -> V_18 , V_84 -> V_9 ) ;
F_56 ( V_84 , V_83 , NULL ) ;
F_77 ( V_53 , V_84 ) ;
} else
F_103 ( V_53 -> V_52 , NULL ) ;
F_28 ( V_12 ) ;
}
int F_104 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_52 * V_53 = (struct V_52 * ) V_90 -> V_93 ;
T_3 V_43 , V_100 ;
int V_39 = V_92 -> V_97 ;
T_4 V_98 = V_92 -> V_99 ;
struct V_21 * V_22 , * V_173 ;
struct V_79 * V_87 ;
struct V_25 * V_12 ;
struct V_27 * V_40 ;
if ( V_39 > 32 )
return - V_102 ;
V_43 = F_50 ( V_92 -> V_103 ) ;
V_100 = F_50 ( F_51 ( V_39 ) ) ;
if ( V_43 & ~ V_100 )
return - V_102 ;
V_43 = V_43 & V_100 ;
V_12 = F_76 ( V_53 , V_43 ) ;
if ( ! V_12 )
return - V_174 ;
V_40 = F_67 ( V_12 , V_39 ) ;
if ( ! V_40 )
return - V_174 ;
V_87 = & V_40 -> V_42 ;
V_22 = F_83 ( V_87 , V_98 , 0 ) ;
if ( ! V_22 )
return - V_174 ;
F_54 ( L_8 , V_43 , V_39 , V_98 , V_53 ) ;
V_173 = NULL ;
V_22 = F_84 ( V_22 -> V_114 . V_115 , struct V_21 , V_114 ) ;
F_85 (fa, fa_head, fa_list) {
struct V_95 * V_96 = V_22 -> V_107 ;
if ( V_22 -> V_106 != V_98 )
break;
if ( ( ! V_92 -> V_117 || V_22 -> V_116 == V_92 -> V_117 ) &&
( V_92 -> V_175 == V_176 ||
V_22 -> V_107 -> V_142 == V_92 -> V_175 ) &&
( ! V_92 -> V_177 ||
V_96 -> V_178 == V_92 -> V_177 ) &&
( ! V_92 -> V_179 ||
V_96 -> V_180 == V_92 -> V_179 ) &&
F_105 ( V_92 , V_96 ) == 0 ) {
V_173 = V_22 ;
break;
}
}
if ( ! V_173 )
return - V_174 ;
V_22 = V_173 ;
F_89 ( V_181 , F_90 ( V_43 ) , V_22 , V_39 , V_90 -> V_104 ,
& V_92 -> V_124 , 0 ) ;
F_106 ( & V_22 -> V_114 ) ;
if ( ! V_39 )
V_90 -> V_132 -- ;
if ( F_107 ( V_87 ) ) {
F_108 ( & V_40 -> V_82 ) ;
F_29 ( V_40 ) ;
}
if ( F_71 ( & V_12 -> V_38 ) )
F_102 ( V_53 , V_12 ) ;
if ( V_22 -> V_122 & V_123 )
F_88 ( V_92 -> V_124 . V_125 ) ;
F_87 ( V_22 -> V_107 ) ;
F_25 ( V_22 ) ;
return 0 ;
}
static int F_109 ( struct V_79 * V_20 )
{
struct V_21 * V_22 , * V_182 ;
int V_168 = 0 ;
F_110 (fa, fa_node, head, fa_list) {
struct V_95 * V_96 = V_22 -> V_107 ;
if ( V_96 && ( V_96 -> V_137 & V_146 ) ) {
F_106 ( & V_22 -> V_114 ) ;
F_87 ( V_22 -> V_107 ) ;
F_25 ( V_22 ) ;
V_168 ++ ;
}
}
return V_168 ;
}
static int F_111 ( struct V_25 * V_12 )
{
int V_168 = 0 ;
struct V_78 * V_183 = & V_12 -> V_38 ;
struct V_184 * V_185 ;
struct V_27 * V_40 = NULL ;
F_112 (li, tmp, lih, hlist) {
V_168 += F_109 ( & V_40 -> V_42 ) ;
if ( F_107 ( & V_40 -> V_42 ) ) {
F_108 ( & V_40 -> V_82 ) ;
F_29 ( V_40 ) ;
}
}
return V_168 ;
}
static struct V_25 * F_113 ( struct V_1 * V_186 , struct V_2 * V_187 )
{
do {
T_1 V_188 ;
if ( V_187 )
V_188 = F_16 ( V_187 -> V_43 , V_186 -> V_18 , V_186 -> V_9 ) + 1 ;
else
V_188 = 0 ;
while ( V_188 < 1u << V_186 -> V_9 ) {
V_187 = F_12 ( V_186 , V_188 ++ ) ;
if ( ! V_187 )
continue;
if ( F_41 ( V_187 ) ) {
F_114 ( F_13 ( V_186 -> V_10 [ V_188 ] ) ) ;
return (struct V_25 * ) V_187 ;
}
V_186 = (struct V_1 * ) V_187 ;
V_188 = 0 ;
}
V_187 = (struct V_2 * ) V_186 ;
} while ( ( V_186 = F_4 ( V_187 ) ) != NULL );
return NULL ;
}
static struct V_25 * F_115 ( struct V_52 * V_53 )
{
struct V_1 * V_48 = (struct V_1 * ) F_13 ( V_53 -> V_52 ) ;
if ( ! V_48 )
return NULL ;
if ( F_41 ( V_48 ) )
return (struct V_25 * ) V_48 ;
return F_113 ( V_48 , NULL ) ;
}
static struct V_25 * F_116 ( struct V_25 * V_12 )
{
struct V_2 * V_187 = (struct V_2 * ) V_12 ;
struct V_1 * V_186 = F_4 ( V_187 ) ;
if ( ! V_186 )
return NULL ;
return F_113 ( V_186 , V_187 ) ;
}
static struct V_25 * F_117 ( struct V_52 * V_53 , int V_189 )
{
struct V_25 * V_12 = F_115 ( V_53 ) ;
while ( V_12 && V_189 -- > 0 )
V_12 = F_116 ( V_12 ) ;
return V_12 ;
}
int F_118 ( struct V_89 * V_90 )
{
struct V_52 * V_53 = (struct V_52 * ) V_90 -> V_93 ;
struct V_25 * V_12 , * V_190 = NULL ;
int V_168 = 0 ;
for ( V_12 = F_115 ( V_53 ) ; V_12 ; V_12 = F_116 ( V_12 ) ) {
V_168 += F_111 ( V_12 ) ;
if ( V_190 && F_71 ( & V_190 -> V_38 ) )
F_102 ( V_53 , V_190 ) ;
V_190 = V_12 ;
}
if ( V_190 && F_71 ( & V_190 -> V_38 ) )
F_102 ( V_53 , V_190 ) ;
F_54 ( L_9 , V_168 ) ;
return V_168 ;
}
void F_119 ( struct V_89 * V_90 )
{
F_37 ( V_90 ) ;
}
static int F_120 ( T_1 V_43 , int V_39 , struct V_79 * V_191 ,
struct V_89 * V_90 ,
struct V_192 * V_193 , struct V_194 * V_195 )
{
int V_8 , V_196 ;
struct V_21 * V_22 ;
T_5 V_197 = F_90 ( V_43 ) ;
V_196 = V_195 -> args [ 5 ] ;
V_8 = 0 ;
F_94 (fa, fah, fa_list) {
if ( V_8 < V_196 ) {
V_8 ++ ;
continue;
}
if ( F_121 ( V_193 , F_122 ( V_195 -> V_193 ) . V_198 ,
V_195 -> V_199 -> V_200 ,
V_126 ,
V_90 -> V_104 ,
V_22 -> V_116 ,
V_197 ,
V_39 ,
V_22 -> V_106 ,
V_22 -> V_107 , V_201 ) < 0 ) {
V_195 -> args [ 5 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_195 -> args [ 5 ] = V_8 ;
return V_193 -> V_202 ;
}
static int F_123 ( struct V_25 * V_12 , struct V_89 * V_90 ,
struct V_192 * V_193 , struct V_194 * V_195 )
{
struct V_27 * V_40 ;
int V_8 , V_196 ;
V_196 = V_195 -> args [ 4 ] ;
V_8 = 0 ;
F_68 (li, &l->list, hlist) {
if ( V_8 < V_196 ) {
V_8 ++ ;
continue;
}
if ( V_8 > V_196 )
V_195 -> args [ 5 ] = 0 ;
if ( F_107 ( & V_40 -> V_42 ) )
continue;
if ( F_120 ( V_12 -> V_43 , V_40 -> V_39 , & V_40 -> V_42 , V_90 , V_193 , V_195 ) < 0 ) {
V_195 -> args [ 4 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_195 -> args [ 4 ] = V_8 ;
return V_193 -> V_202 ;
}
int F_124 ( struct V_89 * V_90 , struct V_192 * V_193 ,
struct V_194 * V_195 )
{
struct V_25 * V_12 ;
struct V_52 * V_53 = (struct V_52 * ) V_90 -> V_93 ;
T_1 V_43 = V_195 -> args [ 2 ] ;
int V_203 = V_195 -> args [ 3 ] ;
F_98 () ;
if ( V_203 == 0 )
V_12 = F_115 ( V_53 ) ;
else {
V_12 = F_76 ( V_53 , V_43 ) ;
if ( ! V_12 )
V_12 = F_117 ( V_53 , V_203 ) ;
}
while ( V_12 ) {
V_195 -> args [ 2 ] = V_12 -> V_43 ;
if ( F_123 ( V_12 , V_90 , V_193 , V_195 ) < 0 ) {
V_195 -> args [ 3 ] = V_203 ;
F_101 () ;
return - 1 ;
}
++ V_203 ;
V_12 = F_116 ( V_12 ) ;
memset ( & V_195 -> args [ 4 ] , 0 ,
sizeof( V_195 -> args ) - 4 * sizeof( V_195 -> args [ 0 ] ) ) ;
}
V_195 -> args [ 3 ] = V_203 ;
F_101 () ;
return V_193 -> V_202 ;
}
void T_6 F_125 ( void )
{
V_24 = F_126 ( L_10 ,
sizeof( struct V_21 ) ,
0 , V_204 , NULL ) ;
V_26 = F_126 ( L_11 ,
F_127 ( sizeof( struct V_25 ) ,
sizeof( struct V_27 ) ) ,
0 , V_204 , NULL ) ;
}
struct V_89 * F_128 ( T_3 V_205 )
{
struct V_89 * V_90 ;
struct V_52 * V_53 ;
V_90 = F_49 ( sizeof( struct V_89 ) + sizeof( struct V_52 ) ,
V_30 ) ;
if ( V_90 == NULL )
return NULL ;
V_90 -> V_104 = V_205 ;
V_90 -> V_206 = - 1 ;
V_90 -> V_132 = 0 ;
V_53 = (struct V_52 * ) V_90 -> V_93 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
return V_90 ;
}
static struct V_2 * F_129 ( struct V_207 * V_208 )
{
struct V_1 * V_7 = V_208 -> V_1 ;
unsigned int V_83 = V_208 -> V_189 ;
struct V_1 * V_186 ;
if ( ! V_7 )
return NULL ;
F_54 ( L_12 ,
V_208 -> V_1 , V_208 -> V_189 , V_208 -> V_209 ) ;
V_210:
while ( V_83 < ( 1 << V_7 -> V_9 ) ) {
struct V_2 * V_48 = F_12 ( V_7 , V_83 ) ;
if ( V_48 ) {
if ( F_41 ( V_48 ) ) {
V_208 -> V_1 = V_7 ;
V_208 -> V_189 = V_83 + 1 ;
} else {
V_208 -> V_1 = (struct V_1 * ) V_48 ;
V_208 -> V_189 = 0 ;
++ V_208 -> V_209 ;
}
return V_48 ;
}
++ V_83 ;
}
V_186 = F_4 ( (struct V_2 * ) V_7 ) ;
if ( V_186 ) {
V_83 = F_16 ( V_7 -> V_43 , V_186 -> V_18 , V_186 -> V_9 ) + 1 ;
V_7 = V_186 ;
-- V_208 -> V_209 ;
goto V_210;
}
return NULL ;
}
static struct V_2 * F_130 ( struct V_207 * V_208 ,
struct V_52 * V_53 )
{
struct V_2 * V_48 ;
if ( ! V_53 )
return NULL ;
V_48 = F_99 ( V_53 -> V_52 ) ;
if ( ! V_48 )
return NULL ;
if ( F_66 ( V_48 ) ) {
V_208 -> V_1 = (struct V_1 * ) V_48 ;
V_208 -> V_189 = 0 ;
V_208 -> V_209 = 1 ;
} else {
V_208 -> V_1 = NULL ;
V_208 -> V_189 = 0 ;
V_208 -> V_209 = 0 ;
}
return V_48 ;
}
static void F_131 ( struct V_52 * V_53 , struct V_211 * V_212 )
{
struct V_2 * V_48 ;
struct V_207 V_208 ;
memset ( V_212 , 0 , sizeof( * V_212 ) ) ;
F_98 () ;
for ( V_48 = F_130 ( & V_208 , V_53 ) ; V_48 ; V_48 = F_129 ( & V_208 ) ) {
if ( F_41 ( V_48 ) ) {
struct V_25 * V_12 = (struct V_25 * ) V_48 ;
struct V_27 * V_40 ;
V_212 -> V_213 ++ ;
V_212 -> V_214 += V_208 . V_209 ;
if ( V_208 . V_209 > V_212 -> V_215 )
V_212 -> V_215 = V_208 . V_209 ;
F_68 ( V_40 , & V_12 -> V_38 , V_82 )
++ V_212 -> V_216 ;
} else {
const struct V_1 * V_7 = ( const struct V_1 * ) V_48 ;
int V_8 ;
V_212 -> V_217 ++ ;
if ( V_7 -> V_9 < V_218 )
V_212 -> V_219 [ V_7 -> V_9 ] ++ ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 -> V_9 ) ; V_8 ++ )
if ( ! V_7 -> V_10 [ V_8 ] )
V_212 -> V_220 ++ ;
}
}
F_101 () ;
}
static void F_132 ( struct V_221 * V_222 , struct V_211 * V_223 )
{
unsigned int V_8 , F_127 , V_224 , V_225 , V_226 ;
if ( V_223 -> V_213 )
V_226 = V_223 -> V_214 * 100 / V_223 -> V_213 ;
else
V_226 = 0 ;
F_133 ( V_222 , L_13 ,
V_226 / 100 , V_226 % 100 ) ;
F_133 ( V_222 , L_14 , V_223 -> V_215 ) ;
F_133 ( V_222 , L_15 , V_223 -> V_213 ) ;
V_225 = sizeof( struct V_25 ) * V_223 -> V_213 ;
F_133 ( V_222 , L_16 , V_223 -> V_216 ) ;
V_225 += sizeof( struct V_27 ) * V_223 -> V_216 ;
F_133 ( V_222 , L_17 , V_223 -> V_217 ) ;
V_225 += sizeof( struct V_1 ) * V_223 -> V_217 ;
F_127 = V_218 ;
while ( F_127 > 0 && V_223 -> V_219 [ F_127 - 1 ] == 0 )
F_127 -- ;
V_224 = 0 ;
for ( V_8 = 1 ; V_8 <= F_127 ; V_8 ++ )
if ( V_223 -> V_219 [ V_8 ] != 0 ) {
F_133 ( V_222 , L_18 , V_8 , V_223 -> V_219 [ V_8 ] ) ;
V_224 += ( 1 << V_8 ) * V_223 -> V_219 [ V_8 ] ;
}
F_134 ( V_222 , '\n' ) ;
F_133 ( V_222 , L_19 , V_224 ) ;
V_225 += sizeof( struct V_2 * ) * V_224 ;
F_133 ( V_222 , L_20 , V_223 -> V_220 ) ;
F_133 ( V_222 , L_21 , ( V_225 + 1023 ) / 1024 ) ;
}
static void F_135 ( struct V_221 * V_222 ,
const struct V_227 * V_64 )
{
F_133 ( V_222 , L_22 ) ;
F_133 ( V_222 , L_23 , V_64 -> gets ) ;
F_133 ( V_222 , L_24 , V_64 -> V_172 ) ;
F_133 ( V_222 , L_25 ,
V_64 -> V_145 ) ;
F_133 ( V_222 , L_26 ,
V_64 -> V_159 ) ;
F_133 ( V_222 , L_27 , V_64 -> V_169 ) ;
F_133 ( V_222 , L_28 ,
V_64 -> V_65 ) ;
}
static void F_136 ( struct V_221 * V_222 , struct V_89 * V_90 )
{
if ( V_90 -> V_104 == V_228 )
F_137 ( V_222 , L_29 ) ;
else if ( V_90 -> V_104 == V_229 )
F_137 ( V_222 , L_30 ) ;
else
F_133 ( V_222 , L_31 , V_90 -> V_104 ) ;
}
static int F_138 ( struct V_221 * V_222 , void * V_230 )
{
struct V_231 * V_231 = (struct V_231 * ) V_222 -> V_232 ;
unsigned int V_233 ;
F_133 ( V_222 ,
L_32
L_33 ,
sizeof( struct V_25 ) , sizeof( struct V_1 ) ) ;
for ( V_233 = 0 ; V_233 < V_234 ; V_233 ++ ) {
struct V_78 * V_20 = & V_231 -> V_235 . V_236 [ V_233 ] ;
struct V_89 * V_90 ;
F_68 (tb, head, tb_hlist) {
struct V_52 * V_53 = (struct V_52 * ) V_90 -> V_93 ;
struct V_211 V_223 ;
if ( ! V_53 )
continue;
F_136 ( V_222 , V_90 ) ;
F_131 ( V_53 , & V_223 ) ;
F_132 ( V_222 , & V_223 ) ;
#ifdef F_62
F_135 ( V_222 , & V_53 -> V_64 ) ;
#endif
}
}
return 0 ;
}
static int F_139 ( struct V_70 * V_70 , struct V_237 * V_237 )
{
return F_140 ( V_70 , V_237 , F_138 ) ;
}
static struct V_2 * F_141 ( struct V_221 * V_222 , T_7 V_18 )
{
struct V_207 * V_208 = V_222 -> V_232 ;
struct V_231 * V_231 = F_142 ( V_222 ) ;
T_7 V_188 = 0 ;
unsigned int V_233 ;
for ( V_233 = 0 ; V_233 < V_234 ; V_233 ++ ) {
struct V_78 * V_20 = & V_231 -> V_235 . V_236 [ V_233 ] ;
struct V_89 * V_90 ;
F_68 (tb, head, tb_hlist) {
struct V_2 * V_48 ;
for ( V_48 = F_130 ( V_208 ,
(struct V_52 * ) V_90 -> V_93 ) ;
V_48 ; V_48 = F_129 ( V_208 ) )
if ( V_18 == V_188 ++ ) {
V_208 -> V_90 = V_90 ;
return V_48 ;
}
}
}
return NULL ;
}
static void * F_143 ( struct V_221 * V_222 , T_7 * V_18 )
__acquires( T_8 )
{
F_98 () ;
return F_141 ( V_222 , * V_18 ) ;
}
static void * F_144 ( struct V_221 * V_222 , void * V_230 , T_7 * V_18 )
{
struct V_207 * V_208 = V_222 -> V_232 ;
struct V_231 * V_231 = F_142 ( V_222 ) ;
struct V_89 * V_90 = V_208 -> V_90 ;
struct V_184 * V_238 ;
unsigned int V_233 ;
struct V_2 * V_48 ;
++ * V_18 ;
V_48 = F_129 ( V_208 ) ;
if ( V_48 )
return V_48 ;
V_233 = V_90 -> V_104 & ( V_234 - 1 ) ;
while ( ( V_238 = F_99 ( F_145 ( & V_90 -> V_239 ) ) ) ) {
V_90 = F_146 ( V_238 , struct V_89 , V_239 ) ;
V_48 = F_130 ( V_208 , (struct V_52 * ) V_90 -> V_93 ) ;
if ( V_48 )
goto V_168;
}
while ( ++ V_233 < V_234 ) {
struct V_78 * V_20 = & V_231 -> V_235 . V_236 [ V_233 ] ;
F_68 (tb, head, tb_hlist) {
V_48 = F_130 ( V_208 , (struct V_52 * ) V_90 -> V_93 ) ;
if ( V_48 )
goto V_168;
}
}
return NULL ;
V_168:
V_208 -> V_90 = V_90 ;
return V_48 ;
}
static void F_147 ( struct V_221 * V_222 , void * V_230 )
__releases( T_8 )
{
F_101 () ;
}
static void F_148 ( struct V_221 * V_222 , int V_48 )
{
while ( V_48 -- > 0 )
F_137 ( V_222 , L_34 ) ;
}
static inline const char * F_149 ( char * V_240 , T_2 V_202 , enum V_241 V_212 )
{
switch ( V_212 ) {
case V_242 : return L_35 ;
case V_243 : return L_36 ;
case V_244 : return L_37 ;
case V_245 : return L_38 ;
case V_176 : return L_39 ;
default:
snprintf ( V_240 , V_202 , L_40 , V_212 ) ;
return V_240 ;
}
}
static inline const char * F_150 ( char * V_240 , T_2 V_202 , unsigned int V_53 )
{
if ( V_53 < V_246 && V_247 [ V_53 ] )
return V_247 [ V_53 ] ;
snprintf ( V_240 , V_202 , L_41 , V_53 ) ;
return V_240 ;
}
static int F_151 ( struct V_221 * V_222 , void * V_230 )
{
const struct V_207 * V_208 = V_222 -> V_232 ;
struct V_2 * V_48 = V_230 ;
if ( ! F_4 ( V_48 ) )
F_136 ( V_222 , V_208 -> V_90 ) ;
if ( F_66 ( V_48 ) ) {
struct V_1 * V_7 = (struct V_1 * ) V_48 ;
T_5 V_248 = F_90 ( F_15 ( V_7 -> V_43 , V_7 -> V_18 ) ) ;
F_148 ( V_222 , V_208 -> V_209 - 1 ) ;
F_133 ( V_222 , L_42 ,
& V_248 , V_7 -> V_18 , V_7 -> V_9 , V_7 -> V_46 ,
V_7 -> V_47 ) ;
} else {
struct V_25 * V_12 = (struct V_25 * ) V_48 ;
struct V_27 * V_40 ;
T_5 V_249 = F_90 ( V_12 -> V_43 ) ;
F_148 ( V_222 , V_208 -> V_209 ) ;
F_133 ( V_222 , L_43 , & V_249 ) ;
F_68 (li, &l->list, hlist) {
struct V_21 * V_22 ;
F_94 (fa, &li->falh, fa_list) {
char V_250 [ 32 ] , V_251 [ 32 ] ;
F_148 ( V_222 , V_208 -> V_209 + 1 ) ;
F_133 ( V_222 , L_44 , V_40 -> V_39 ,
F_149 ( V_250 , sizeof( V_250 ) ,
V_22 -> V_107 -> V_142 ) ,
F_150 ( V_251 , sizeof( V_251 ) ,
V_22 -> V_116 ) ) ;
if ( V_22 -> V_106 )
F_133 ( V_222 , L_45 , V_22 -> V_106 ) ;
F_134 ( V_222 , '\n' ) ;
}
}
}
return 0 ;
}
static int F_152 ( struct V_70 * V_70 , struct V_237 * V_237 )
{
return F_153 ( V_70 , V_237 , & V_252 ,
sizeof( struct V_207 ) ) ;
}
static struct V_25 * F_154 ( struct V_253 * V_208 , T_7 V_18 )
{
struct V_25 * V_12 = NULL ;
struct V_52 * V_53 = V_208 -> V_254 ;
if ( V_208 -> V_18 > 0 && V_18 >= V_208 -> V_18 && ( V_12 = F_76 ( V_53 , V_208 -> V_43 ) ) )
V_18 -= V_208 -> V_18 ;
else {
V_208 -> V_18 = 0 ;
V_12 = F_115 ( V_53 ) ;
}
while ( V_12 && V_18 -- > 0 ) {
V_208 -> V_18 ++ ;
V_12 = F_116 ( V_12 ) ;
}
if ( V_12 )
V_208 -> V_43 = V_18 ;
else
V_208 -> V_18 = 0 ;
return V_12 ;
}
static void * F_155 ( struct V_221 * V_222 , T_7 * V_18 )
__acquires( T_8 )
{
struct V_253 * V_208 = V_222 -> V_232 ;
struct V_89 * V_90 ;
F_98 () ;
V_90 = F_156 ( F_142 ( V_222 ) , V_229 ) ;
if ( ! V_90 )
return NULL ;
V_208 -> V_254 = (struct V_52 * ) V_90 -> V_93 ;
if ( * V_18 == 0 )
return V_255 ;
else
return F_154 ( V_208 , * V_18 - 1 ) ;
}
static void * F_157 ( struct V_221 * V_222 , void * V_230 , T_7 * V_18 )
{
struct V_253 * V_208 = V_222 -> V_232 ;
struct V_25 * V_12 = V_230 ;
++ * V_18 ;
if ( V_230 == V_255 ) {
V_208 -> V_18 = 0 ;
V_12 = F_115 ( V_208 -> V_254 ) ;
} else {
V_208 -> V_18 ++ ;
V_12 = F_116 ( V_12 ) ;
}
if ( V_12 )
V_208 -> V_43 = V_12 -> V_43 ;
else
V_208 -> V_18 = 0 ;
return V_12 ;
}
static void F_158 ( struct V_221 * V_222 , void * V_230 )
__releases( T_8 )
{
F_101 () ;
}
static unsigned int F_159 ( int type , T_5 V_100 , const struct V_95 * V_96 )
{
unsigned int V_256 = 0 ;
if ( type == V_257 || type == V_258 )
V_256 = V_259 ;
if ( V_96 && V_96 -> V_148 -> V_260 )
V_256 |= V_261 ;
if ( V_100 == F_90 ( 0xFFFFFFFF ) )
V_256 |= V_262 ;
V_256 |= V_263 ;
return V_256 ;
}
static int F_160 ( struct V_221 * V_222 , void * V_230 )
{
struct V_25 * V_12 = V_230 ;
struct V_27 * V_40 ;
if ( V_230 == V_255 ) {
F_133 ( V_222 , L_46 , L_47
L_48
L_49 ) ;
return 0 ;
}
F_68 (li, &l->list, hlist) {
struct V_21 * V_22 ;
T_5 V_100 , V_264 ;
V_100 = F_51 ( V_40 -> V_39 ) ;
V_264 = F_90 ( V_12 -> V_43 ) ;
F_94 (fa, &li->falh, fa_list) {
const struct V_95 * V_96 = V_22 -> V_107 ;
unsigned int V_256 = F_159 ( V_22 -> V_116 , V_100 , V_96 ) ;
int V_202 ;
if ( V_22 -> V_116 == V_265
|| V_22 -> V_116 == V_266 )
continue;
if ( V_96 )
F_133 ( V_222 ,
L_50
L_51 ,
V_96 -> V_267 ? V_96 -> V_267 -> V_268 : L_52 ,
V_264 ,
V_96 -> V_148 -> V_260 , V_256 , 0 , 0 ,
V_96 -> V_105 ,
V_100 ,
( V_96 -> V_269 ?
V_96 -> V_269 + 40 : 0 ) ,
V_96 -> V_270 ,
V_96 -> V_271 >> 3 , & V_202 ) ;
else
F_133 ( V_222 ,
L_53
L_51 ,
V_264 , 0 , V_256 , 0 , 0 , 0 ,
V_100 , 0 , 0 , 0 , & V_202 ) ;
F_133 ( V_222 , L_54 , 127 - V_202 , L_55 ) ;
}
}
return 0 ;
}
static int F_161 ( struct V_70 * V_70 , struct V_237 * V_237 )
{
return F_153 ( V_70 , V_237 , & V_272 ,
sizeof( struct V_253 ) ) ;
}
int T_9 F_162 ( struct V_231 * V_231 )
{
if ( ! F_163 ( L_56 , V_273 , V_231 -> V_274 , & V_275 ) )
goto V_276;
if ( ! F_163 ( L_57 , V_273 , V_231 -> V_274 ,
& V_277 ) )
goto V_278;
if ( ! F_163 ( L_58 , V_273 , V_231 -> V_274 , & V_279 ) )
goto V_280;
return 0 ;
V_280:
F_164 ( L_57 , V_231 -> V_274 ) ;
V_278:
F_164 ( L_56 , V_231 -> V_274 ) ;
V_276:
return - V_69 ;
}
void T_10 F_165 ( struct V_231 * V_231 )
{
F_164 ( L_56 , V_231 -> V_274 ) ;
F_164 ( L_57 , V_231 -> V_274 ) ;
F_164 ( L_58 , V_231 -> V_274 ) ;
}
