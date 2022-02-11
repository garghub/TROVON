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
V_40 -> V_41 = F_51 ( F_52 ( V_39 ) ) ;
F_53 ( & V_40 -> V_42 ) ;
}
return V_40 ;
}
static struct V_1 * F_54 ( T_1 V_43 , int V_18 , int V_9 )
{
T_2 V_44 = sizeof( struct V_1 ) + ( sizeof( struct V_2 * ) << V_9 ) ;
struct V_1 * V_7 = F_32 ( V_44 ) ;
if ( V_7 ) {
V_7 -> V_4 = V_45 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_43 = V_43 ;
V_7 -> V_46 = 0 ;
V_7 -> V_47 = 1 << V_9 ;
}
F_55 ( L_1 , V_7 , sizeof( struct V_1 ) ,
sizeof( struct V_2 ) << V_9 ) ;
return V_7 ;
}
static inline int F_56 ( const struct V_1 * V_7 , const struct V_2 * V_48 )
{
if ( V_48 == NULL || F_42 ( V_48 ) )
return 0 ;
return ( (struct V_1 * ) V_48 ) -> V_18 == V_7 -> V_18 + V_7 -> V_9 ;
}
static inline void F_57 ( struct V_49 * V_50 , struct V_1 * V_7 , int V_8 ,
struct V_2 * V_48 )
{
F_58 ( V_7 , V_8 , V_48 , - 1 ) ;
}
static void F_58 ( struct V_1 * V_7 , int V_8 , struct V_2 * V_48 ,
int V_51 )
{
struct V_2 * V_52 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
int V_53 ;
F_10 ( V_8 >= 1 << V_7 -> V_9 ) ;
if ( V_48 == NULL && V_52 != NULL )
V_7 -> V_47 ++ ;
else if ( V_48 != NULL && V_52 == NULL )
V_7 -> V_47 -- ;
if ( V_51 == - 1 )
V_51 = F_56 ( V_7 , V_52 ) ;
V_53 = F_56 ( V_7 , V_48 ) ;
if ( V_51 && ! V_53 )
V_7 -> V_46 -- ;
else if ( ! V_51 && V_53 )
V_7 -> V_46 ++ ;
if ( V_48 )
F_6 ( V_48 , V_7 ) ;
F_59 ( V_7 -> V_10 [ V_8 ] , V_48 ) ;
}
static struct V_2 * F_60 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_54 ;
int V_55 ;
int V_56 ;
int V_57 ;
if ( ! V_7 )
return NULL ;
F_55 ( L_2 ,
V_7 , V_58 , V_59 ) ;
if ( V_7 -> V_47 == F_14 ( V_7 ) ) {
F_43 ( V_7 ) ;
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
V_7 = F_61 ( V_50 , V_7 ) ;
if ( F_62 ( V_7 ) ) {
V_7 = V_54 ;
#ifdef F_63
V_50 -> V_64 . V_65 ++ ;
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
V_7 = F_64 ( V_50 , V_7 ) ;
if ( F_62 ( V_7 ) ) {
V_7 = V_54 ;
#ifdef F_63
V_50 -> V_64 . V_65 ++ ;
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
F_43 ( V_7 ) ;
return V_48 ;
}
}
return (struct V_2 * ) V_7 ;
}
static void F_65 ( struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_66 ;
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
V_66 = (struct V_1 * ) F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( V_66 )
F_41 ( V_66 ) ;
}
F_41 ( V_7 ) ;
}
static struct V_1 * F_61 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
struct V_1 * V_67 = V_7 ;
int V_68 = F_14 ( V_7 ) ;
int V_8 ;
F_55 ( L_3 ) ;
V_7 = F_54 ( V_67 -> V_43 , V_67 -> V_18 , V_67 -> V_9 + 1 ) ;
if ( ! V_7 )
return F_66 ( - V_69 ) ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
struct V_1 * V_70 ;
V_70 = (struct V_1 * ) F_9 ( V_67 , V_8 ) ;
if ( V_70 &&
F_67 ( V_70 ) &&
V_70 -> V_18 == V_67 -> V_18 + V_67 -> V_9 &&
V_70 -> V_9 > 1 ) {
struct V_1 * V_71 , * V_72 ;
T_1 V_73 = ~ 0U << ( V_13 - 1 ) >> V_70 -> V_18 ;
V_71 = F_54 ( V_70 -> V_43 & ( ~ V_73 ) , V_70 -> V_18 + 1 ,
V_70 -> V_9 - 1 ) ;
if ( ! V_71 )
goto V_74;
V_72 = F_54 ( V_70 -> V_43 | V_73 , V_70 -> V_18 + 1 ,
V_70 -> V_9 - 1 ) ;
if ( ! V_72 ) {
F_41 ( V_71 ) ;
goto V_74;
}
F_57 ( V_50 , V_7 , 2 * V_8 , (struct V_2 * ) V_71 ) ;
F_57 ( V_50 , V_7 , 2 * V_8 + 1 , (struct V_2 * ) V_72 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
struct V_1 * V_70 ;
struct V_2 * V_3 = F_9 ( V_67 , V_8 ) ;
struct V_1 * V_71 , * V_72 ;
int V_28 , V_75 ;
if ( V_3 == NULL )
continue;
if ( F_42 ( V_3 ) || ( (struct V_1 * ) V_3 ) -> V_18 >
V_7 -> V_18 + V_7 -> V_9 - 1 ) {
if ( F_16 ( V_3 -> V_43 ,
V_67 -> V_18 + V_67 -> V_9 ,
1 ) == 0 )
F_57 ( V_50 , V_7 , 2 * V_8 , V_3 ) ;
else
F_57 ( V_50 , V_7 , 2 * V_8 + 1 , V_3 ) ;
continue;
}
V_70 = (struct V_1 * ) V_3 ;
if ( V_70 -> V_9 == 1 ) {
F_57 ( V_50 , V_7 , 2 * V_8 , F_11 ( V_70 -> V_10 [ 0 ] ) ) ;
F_57 ( V_50 , V_7 , 2 * V_8 + 1 , F_11 ( V_70 -> V_10 [ 1 ] ) ) ;
F_43 ( V_70 ) ;
continue;
}
V_71 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 ) ;
F_57 ( V_50 , V_7 , 2 * V_8 , NULL ) ;
F_10 ( ! V_71 ) ;
V_72 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 + 1 ) ;
F_57 ( V_50 , V_7 , 2 * V_8 + 1 , NULL ) ;
F_10 ( ! V_72 ) ;
V_28 = F_14 ( V_71 ) ;
for ( V_75 = 0 ; V_75 < V_28 ; V_75 ++ ) {
F_57 ( V_50 , V_71 , V_75 , F_11 ( V_70 -> V_10 [ V_75 ] ) ) ;
F_57 ( V_50 , V_72 , V_75 , F_11 ( V_70 -> V_10 [ V_75 + V_28 ] ) ) ;
}
F_57 ( V_50 , V_7 , 2 * V_8 , F_60 ( V_50 , V_71 ) ) ;
F_57 ( V_50 , V_7 , 2 * V_8 + 1 , F_60 ( V_50 , V_72 ) ) ;
F_43 ( V_70 ) ;
}
F_43 ( V_67 ) ;
return V_7 ;
V_74:
F_65 ( V_7 ) ;
return F_66 ( - V_69 ) ;
}
static struct V_1 * F_64 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
struct V_1 * V_67 = V_7 ;
struct V_2 * V_71 , * V_72 ;
int V_8 ;
int V_68 = F_14 ( V_7 ) ;
F_55 ( L_4 ) ;
V_7 = F_54 ( V_67 -> V_43 , V_67 -> V_18 , V_67 -> V_9 - 1 ) ;
if ( ! V_7 )
return F_66 ( - V_69 ) ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 += 2 ) {
V_71 = F_9 ( V_67 , V_8 ) ;
V_72 = F_9 ( V_67 , V_8 + 1 ) ;
if ( V_71 && V_72 ) {
struct V_1 * V_76 ;
V_76 = F_54 ( V_71 -> V_43 , V_7 -> V_18 + V_7 -> V_9 , 1 ) ;
if ( ! V_76 )
goto V_74;
F_57 ( V_50 , V_7 , V_8 / 2 , (struct V_2 * ) V_76 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_68 ; V_8 += 2 ) {
struct V_1 * V_77 ;
V_71 = F_9 ( V_67 , V_8 ) ;
V_72 = F_9 ( V_67 , V_8 + 1 ) ;
if ( V_71 == NULL ) {
if ( V_72 == NULL )
continue;
F_57 ( V_50 , V_7 , V_8 / 2 , V_72 ) ;
continue;
}
if ( V_72 == NULL ) {
F_57 ( V_50 , V_7 , V_8 / 2 , V_71 ) ;
continue;
}
V_77 = (struct V_1 * ) F_9 ( V_7 , V_8 / 2 ) ;
F_57 ( V_50 , V_7 , V_8 / 2 , NULL ) ;
F_57 ( V_50 , V_77 , 0 , V_71 ) ;
F_57 ( V_50 , V_77 , 1 , V_72 ) ;
F_57 ( V_50 , V_7 , V_8 / 2 , F_60 ( V_50 , V_77 ) ) ;
}
F_43 ( V_67 ) ;
return V_7 ;
V_74:
F_65 ( V_7 ) ;
return F_66 ( - V_69 ) ;
}
static struct V_27 * F_68 ( struct V_25 * V_12 , int V_39 )
{
struct V_78 * V_20 = & V_12 -> V_38 ;
struct V_79 * V_3 ;
struct V_27 * V_40 ;
F_69 (li, node, head, hlist)
if ( V_40 -> V_39 == V_39 )
return V_40 ;
return NULL ;
}
static inline struct V_80 * F_70 ( struct V_25 * V_12 , int V_39 )
{
struct V_27 * V_40 = F_68 ( V_12 , V_39 ) ;
if ( ! V_40 )
return NULL ;
return & V_40 -> V_42 ;
}
static void F_71 ( struct V_78 * V_20 , struct V_27 * V_81 )
{
struct V_27 * V_40 = NULL , * V_82 = NULL ;
struct V_79 * V_3 ;
if ( F_72 ( V_20 ) ) {
F_73 ( & V_81 -> V_83 , V_20 ) ;
} else {
F_74 (li, node, head, hlist) {
if ( V_81 -> V_39 > V_40 -> V_39 )
break;
V_82 = V_40 ;
}
if ( V_82 )
F_75 ( & V_82 -> V_83 , & V_81 -> V_83 ) ;
else
F_76 ( & V_81 -> V_83 , & V_40 -> V_83 ) ;
}
}
static struct V_25 *
F_77 ( struct V_49 * V_50 , T_3 V_43 )
{
int V_18 ;
struct V_1 * V_7 ;
struct V_2 * V_48 ;
V_18 = 0 ;
V_48 = F_13 ( V_50 -> V_49 ) ;
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
if ( V_48 != NULL && F_42 ( V_48 ) && F_17 ( V_43 , V_48 -> V_43 ) )
return (struct V_25 * ) V_48 ;
return NULL ;
}
static void F_78 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
int V_51 ;
T_1 V_84 , V_43 ;
struct V_1 * V_85 ;
V_43 = V_7 -> V_43 ;
while ( V_7 != NULL && ( V_85 = F_1 ( (struct V_2 * ) V_7 ) ) != NULL ) {
V_84 = F_16 ( V_43 , V_85 -> V_18 , V_85 -> V_9 ) ;
V_51 = F_56 ( V_85 , F_9 ( V_85 , V_84 ) ) ;
V_7 = (struct V_1 * ) F_60 ( V_50 , (struct V_1 * ) V_7 ) ;
F_58 ( (struct V_1 * ) V_85 , V_84 ,
(struct V_2 * ) V_7 , V_51 ) ;
V_85 = F_1 ( (struct V_2 * ) V_7 ) ;
if ( ! V_85 )
F_59 ( V_50 -> V_49 , (struct V_2 * ) V_7 ) ;
F_44 () ;
if ( ! V_85 )
break;
V_7 = V_85 ;
}
if ( F_67 ( V_7 ) )
V_7 = (struct V_1 * ) F_60 ( V_50 , (struct V_1 * ) V_7 ) ;
F_59 ( V_50 -> V_49 , (struct V_2 * ) V_7 ) ;
F_44 () ;
}
static struct V_80 * F_79 ( struct V_49 * V_50 , T_3 V_43 , int V_39 )
{
int V_18 , V_86 ;
struct V_1 * V_85 = NULL , * V_7 = NULL ;
struct V_2 * V_48 ;
struct V_25 * V_12 ;
int V_87 ;
struct V_80 * V_88 = NULL ;
struct V_27 * V_40 ;
T_1 V_84 ;
V_18 = 0 ;
V_48 = F_11 ( V_50 -> V_49 ) ;
while ( V_48 != NULL && F_8 ( V_48 ) == V_45 ) {
V_7 = (struct V_1 * ) V_48 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_43 , V_18 , V_7 -> V_18 - V_18 , V_43 ) ) {
V_85 = V_7 ;
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_48 = F_9 ( V_7 ,
F_16 ( V_43 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
F_10 ( V_48 && F_1 ( V_48 ) != V_7 ) ;
} else
break;
}
F_10 ( V_85 && F_42 ( V_85 ) ) ;
if ( V_48 != NULL && F_42 ( V_48 ) && F_17 ( V_43 , V_48 -> V_43 ) ) {
V_12 = (struct V_25 * ) V_48 ;
V_40 = F_49 ( V_39 ) ;
if ( ! V_40 )
return NULL ;
V_88 = & V_40 -> V_42 ;
F_71 ( & V_12 -> V_38 , V_40 ) ;
goto V_89;
}
V_12 = F_46 () ;
if ( ! V_12 )
return NULL ;
V_12 -> V_43 = V_43 ;
V_40 = F_49 ( V_39 ) ;
if ( ! V_40 ) {
F_28 ( V_12 ) ;
return NULL ;
}
V_88 = & V_40 -> V_42 ;
F_71 ( & V_12 -> V_38 , V_40 ) ;
if ( V_50 -> V_49 && V_48 == NULL ) {
F_6 ( (struct V_2 * ) V_12 , V_85 ) ;
V_84 = F_16 ( V_43 , V_85 -> V_18 , V_85 -> V_9 ) ;
F_57 ( V_50 , (struct V_1 * ) V_85 , V_84 , (struct V_2 * ) V_12 ) ;
} else {
if ( V_85 )
V_18 = V_85 -> V_18 + V_85 -> V_9 ;
else
V_18 = 0 ;
if ( V_48 ) {
V_86 = F_19 ( V_43 , V_18 , V_48 -> V_43 ) ;
V_7 = F_54 ( V_48 -> V_43 , V_86 , 1 ) ;
} else {
V_86 = 0 ;
V_7 = F_54 ( V_43 , V_86 , 1 ) ;
}
if ( ! V_7 ) {
F_30 ( V_40 ) ;
F_28 ( V_12 ) ;
return NULL ;
}
F_6 ( (struct V_2 * ) V_7 , V_85 ) ;
V_87 = F_16 ( V_43 , V_86 , 1 ) ;
F_57 ( V_50 , V_7 , V_87 , (struct V_2 * ) V_12 ) ;
F_57 ( V_50 , V_7 , 1 - V_87 , V_48 ) ;
if ( V_85 ) {
V_84 = F_16 ( V_43 , V_85 -> V_18 , V_85 -> V_9 ) ;
F_57 ( V_50 , (struct V_1 * ) V_85 , V_84 ,
(struct V_2 * ) V_7 ) ;
} else {
F_59 ( V_50 -> V_49 , (struct V_2 * ) V_7 ) ;
V_85 = V_7 ;
}
}
if ( V_85 && V_85 -> V_18 + V_85 -> V_9 > 32 )
F_80 ( L_5
L_6 ,
V_85 , V_85 -> V_18 , V_85 -> V_9 , V_43 , V_39 ) ;
F_78 ( V_50 , V_85 ) ;
V_89:
return V_88 ;
}
int F_81 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
struct V_49 * V_50 = (struct V_49 * ) V_91 -> V_94 ;
struct V_21 * V_22 , * V_95 ;
struct V_80 * V_88 = NULL ;
struct V_96 * V_97 ;
int V_39 = V_93 -> V_98 ;
T_4 V_99 = V_93 -> V_100 ;
T_3 V_43 , V_101 ;
int V_102 ;
struct V_25 * V_12 ;
if ( V_39 > 32 )
return - V_103 ;
V_43 = F_51 ( V_93 -> V_104 ) ;
F_55 ( L_7 , V_91 -> V_105 , V_43 , V_39 ) ;
V_101 = F_51 ( F_52 ( V_39 ) ) ;
if ( V_43 & ~ V_101 )
return - V_103 ;
V_43 = V_43 & V_101 ;
V_97 = F_82 ( V_93 ) ;
if ( F_62 ( V_97 ) ) {
V_102 = F_83 ( V_97 ) ;
goto V_102;
}
V_12 = F_77 ( V_50 , V_43 ) ;
V_22 = NULL ;
if ( V_12 ) {
V_88 = F_70 ( V_12 , V_39 ) ;
V_22 = F_84 ( V_88 , V_99 , V_97 -> V_106 ) ;
}
if ( V_22 && V_22 -> V_107 == V_99 &&
V_22 -> V_108 -> V_106 == V_97 -> V_106 ) {
struct V_21 * V_109 , * V_110 ;
V_102 = - V_111 ;
if ( V_93 -> V_112 & V_113 )
goto V_114;
V_110 = NULL ;
V_109 = V_22 ;
V_22 = F_85 ( V_22 -> V_115 . V_116 , struct V_21 , V_115 ) ;
F_86 (fa, fa_head, fa_list) {
if ( V_22 -> V_107 != V_99 )
break;
if ( V_22 -> V_108 -> V_106 != V_97 -> V_106 )
break;
if ( V_22 -> V_117 == V_93 -> V_118 &&
V_22 -> V_108 == V_97 ) {
V_110 = V_22 ;
break;
}
}
if ( V_93 -> V_112 & V_119 ) {
struct V_96 * V_120 ;
T_4 V_121 ;
V_22 = V_109 ;
if ( V_110 ) {
if ( V_22 == V_110 )
V_102 = 0 ;
goto V_114;
}
V_102 = - V_122 ;
V_95 = F_47 ( V_24 , V_30 ) ;
if ( V_95 == NULL )
goto V_114;
V_120 = V_22 -> V_108 ;
V_95 -> V_107 = V_22 -> V_107 ;
V_95 -> V_108 = V_97 ;
V_95 -> V_117 = V_93 -> V_118 ;
V_121 = V_22 -> V_123 ;
V_95 -> V_123 = V_121 & ~ V_124 ;
F_87 ( & V_22 -> V_115 , & V_95 -> V_115 ) ;
F_25 ( V_22 ) ;
F_88 ( V_120 ) ;
if ( V_121 & V_124 )
F_89 ( V_93 -> V_125 . V_126 , - 1 ) ;
F_90 ( V_127 , F_91 ( V_43 ) , V_95 , V_39 ,
V_91 -> V_105 , & V_93 -> V_125 , V_119 ) ;
goto V_128;
}
if ( V_110 )
goto V_114;
if ( ! ( V_93 -> V_112 & V_129 ) )
V_22 = V_109 ;
}
V_102 = - V_130 ;
if ( ! ( V_93 -> V_112 & V_131 ) )
goto V_114;
V_102 = - V_122 ;
V_95 = F_47 ( V_24 , V_30 ) ;
if ( V_95 == NULL )
goto V_114;
V_95 -> V_108 = V_97 ;
V_95 -> V_107 = V_99 ;
V_95 -> V_117 = V_93 -> V_118 ;
V_95 -> V_123 = 0 ;
if ( ! V_88 ) {
V_88 = F_79 ( V_50 , V_43 , V_39 ) ;
if ( F_92 ( ! V_88 ) ) {
V_102 = - V_69 ;
goto V_132;
}
}
if ( ! V_39 )
V_91 -> V_133 ++ ;
F_93 ( & V_95 -> V_115 ,
( V_22 ? & V_22 -> V_115 : V_88 ) ) ;
F_89 ( V_93 -> V_125 . V_126 , - 1 ) ;
F_90 ( V_127 , F_91 ( V_43 ) , V_95 , V_39 , V_91 -> V_105 ,
& V_93 -> V_125 , 0 ) ;
V_128:
return 0 ;
V_132:
F_24 ( V_24 , V_95 ) ;
V_114:
F_88 ( V_97 ) ;
V_102:
return V_102 ;
}
static int F_94 ( struct V_90 * V_91 , struct V_49 * V_50 , struct V_25 * V_12 ,
T_1 V_43 , const struct V_134 * V_135 ,
struct V_136 * V_137 , int V_138 )
{
struct V_27 * V_40 ;
struct V_78 * V_139 = & V_12 -> V_38 ;
struct V_79 * V_3 ;
F_69 (li, node, hhead, hlist) {
struct V_21 * V_22 ;
if ( V_12 -> V_43 != ( V_43 & V_40 -> V_41 ) )
continue;
F_95 (fa, &li->falh, fa_list) {
struct V_96 * V_97 = V_22 -> V_108 ;
int V_140 , V_102 ;
if ( V_22 -> V_107 && V_22 -> V_107 != V_135 -> V_141 )
continue;
if ( V_22 -> V_108 -> V_142 < V_135 -> V_143 )
continue;
F_96 ( V_22 ) ;
V_102 = V_144 [ V_22 -> V_117 ] . error ;
if ( V_102 ) {
#ifdef F_63
V_50 -> V_64 . V_145 ++ ;
#endif
return V_102 ;
}
if ( V_97 -> V_138 & V_146 )
continue;
for ( V_140 = 0 ; V_140 < V_97 -> V_147 ; V_140 ++ ) {
const struct V_148 * V_149 = & V_97 -> V_148 [ V_140 ] ;
if ( V_149 -> V_150 & V_146 )
continue;
if ( V_135 -> V_151 && V_135 -> V_151 != V_149 -> V_152 )
continue;
#ifdef F_63
V_50 -> V_64 . V_145 ++ ;
#endif
V_137 -> V_153 = V_40 -> V_39 ;
V_137 -> V_154 = V_140 ;
V_137 -> type = V_22 -> V_117 ;
V_137 -> V_155 = V_22 -> V_108 -> V_142 ;
V_137 -> V_97 = V_97 ;
V_137 -> V_156 = V_91 ;
V_137 -> V_88 = & V_40 -> V_42 ;
if ( ! ( V_138 & V_157 ) )
F_97 ( & V_97 -> V_158 ) ;
return 0 ;
}
}
#ifdef F_63
V_50 -> V_64 . V_159 ++ ;
#endif
}
return 1 ;
}
int F_98 ( struct V_90 * V_91 , const struct V_134 * V_135 ,
struct V_136 * V_137 , int V_138 )
{
struct V_49 * V_50 = (struct V_49 * ) V_91 -> V_94 ;
int V_160 ;
struct V_2 * V_48 ;
struct V_1 * V_161 ;
unsigned int V_18 , V_9 ;
T_1 V_43 = F_51 ( V_135 -> V_162 ) ;
unsigned int V_163 ;
T_1 V_84 = 0 ;
unsigned int V_164 = V_13 ;
struct V_1 * V_165 ;
T_1 V_166 ;
F_99 () ;
V_48 = F_100 ( V_50 -> V_49 ) ;
if ( ! V_48 )
goto V_167;
#ifdef F_63
V_50 -> V_64 . gets ++ ;
#endif
if ( F_42 ( V_48 ) ) {
V_160 = F_94 ( V_91 , V_50 , (struct V_25 * ) V_48 , V_43 , V_135 , V_137 , V_138 ) ;
goto V_168;
}
V_161 = (struct V_1 * ) V_48 ;
V_163 = 0 ;
while ( V_161 ) {
V_18 = V_161 -> V_18 ;
V_9 = V_161 -> V_9 ;
if ( ! V_163 )
V_84 = F_16 ( F_15 ( V_43 , V_164 ) ,
V_18 , V_9 ) ;
V_48 = F_12 ( V_161 , V_84 ) ;
if ( V_48 == NULL ) {
#ifdef F_63
V_50 -> V_64 . V_169 ++ ;
#endif
goto V_170;
}
if ( F_42 ( V_48 ) ) {
V_160 = F_94 ( V_91 , V_50 , (struct V_25 * ) V_48 , V_43 , V_135 , V_137 , V_138 ) ;
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
int V_171 = V_13 - F_101 ( V_166 ) ;
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
&& ! ( V_84 & ( 1 << ( V_163 - 1 ) ) ) )
V_163 ++ ;
if ( V_164 > V_161 -> V_18 + V_161 -> V_9 - V_163 )
V_164 = V_161 -> V_18 + V_161 -> V_9
- V_163 ;
if ( V_163 <= V_161 -> V_9 ) {
V_84 &= ~ ( 1 << ( V_163 - 1 ) ) ;
} else {
struct V_1 * V_4 = F_4 ( (struct V_2 * ) V_161 ) ;
if ( ! V_4 )
goto V_167;
V_84 = F_16 ( V_161 -> V_43 , V_4 -> V_18 , V_4 -> V_9 ) ;
V_161 = V_4 ;
V_163 = 0 ;
#ifdef F_63
V_50 -> V_64 . V_172 ++ ;
#endif
goto V_170;
}
}
V_167:
V_160 = 1 ;
V_168:
F_102 () ;
return V_160 ;
}
static void F_103 ( struct V_49 * V_50 , struct V_25 * V_12 )
{
struct V_1 * V_85 = F_1 ( (struct V_2 * ) V_12 ) ;
F_55 ( L_8 , V_12 ) ;
if ( V_85 ) {
T_1 V_84 = F_16 ( V_12 -> V_43 , V_85 -> V_18 , V_85 -> V_9 ) ;
F_57 ( V_50 , (struct V_1 * ) V_85 , V_84 , NULL ) ;
F_78 ( V_50 , V_85 ) ;
} else
F_104 ( V_50 -> V_49 , NULL ) ;
F_28 ( V_12 ) ;
}
int F_105 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
struct V_49 * V_50 = (struct V_49 * ) V_91 -> V_94 ;
T_3 V_43 , V_101 ;
int V_39 = V_93 -> V_98 ;
T_4 V_99 = V_93 -> V_100 ;
struct V_21 * V_22 , * V_173 ;
struct V_80 * V_88 ;
struct V_25 * V_12 ;
struct V_27 * V_40 ;
if ( V_39 > 32 )
return - V_103 ;
V_43 = F_51 ( V_93 -> V_104 ) ;
V_101 = F_51 ( F_52 ( V_39 ) ) ;
if ( V_43 & ~ V_101 )
return - V_103 ;
V_43 = V_43 & V_101 ;
V_12 = F_77 ( V_50 , V_43 ) ;
if ( ! V_12 )
return - V_174 ;
V_88 = F_70 ( V_12 , V_39 ) ;
V_22 = F_84 ( V_88 , V_99 , 0 ) ;
if ( ! V_22 )
return - V_174 ;
F_55 ( L_9 , V_43 , V_39 , V_99 , V_50 ) ;
V_173 = NULL ;
V_22 = F_85 ( V_22 -> V_115 . V_116 , struct V_21 , V_115 ) ;
F_86 (fa, fa_head, fa_list) {
struct V_96 * V_97 = V_22 -> V_108 ;
if ( V_22 -> V_107 != V_99 )
break;
if ( ( ! V_93 -> V_118 || V_22 -> V_117 == V_93 -> V_118 ) &&
( V_93 -> V_175 == V_176 ||
V_22 -> V_108 -> V_142 == V_93 -> V_175 ) &&
( ! V_93 -> V_177 ||
V_97 -> V_178 == V_93 -> V_177 ) &&
( ! V_93 -> V_179 ||
V_97 -> V_180 == V_93 -> V_179 ) &&
F_106 ( V_93 , V_97 ) == 0 ) {
V_173 = V_22 ;
break;
}
}
if ( ! V_173 )
return - V_174 ;
V_22 = V_173 ;
F_90 ( V_181 , F_91 ( V_43 ) , V_22 , V_39 , V_91 -> V_105 ,
& V_93 -> V_125 , 0 ) ;
V_12 = F_77 ( V_50 , V_43 ) ;
V_40 = F_68 ( V_12 , V_39 ) ;
F_107 ( & V_22 -> V_115 ) ;
if ( ! V_39 )
V_91 -> V_133 -- ;
if ( F_108 ( V_88 ) ) {
F_109 ( & V_40 -> V_83 ) ;
F_30 ( V_40 ) ;
}
if ( F_72 ( & V_12 -> V_38 ) )
F_103 ( V_50 , V_12 ) ;
if ( V_22 -> V_123 & V_124 )
F_89 ( V_93 -> V_125 . V_126 , - 1 ) ;
F_88 ( V_22 -> V_108 ) ;
F_25 ( V_22 ) ;
return 0 ;
}
static int F_110 ( struct V_80 * V_20 )
{
struct V_21 * V_22 , * V_182 ;
int V_168 = 0 ;
F_111 (fa, fa_node, head, fa_list) {
struct V_96 * V_97 = V_22 -> V_108 ;
if ( V_97 && ( V_97 -> V_138 & V_146 ) ) {
F_107 ( & V_22 -> V_115 ) ;
F_88 ( V_22 -> V_108 ) ;
F_25 ( V_22 ) ;
V_168 ++ ;
}
}
return V_168 ;
}
static int F_112 ( struct V_25 * V_12 )
{
int V_168 = 0 ;
struct V_78 * V_183 = & V_12 -> V_38 ;
struct V_79 * V_3 , * V_184 ;
struct V_27 * V_40 = NULL ;
F_113 (li, node, tmp, lih, hlist) {
V_168 += F_110 ( & V_40 -> V_42 ) ;
if ( F_108 ( & V_40 -> V_42 ) ) {
F_109 ( & V_40 -> V_83 ) ;
F_30 ( V_40 ) ;
}
}
return V_168 ;
}
static struct V_25 * F_114 ( struct V_1 * V_185 , struct V_2 * V_186 )
{
do {
T_1 V_187 ;
if ( V_186 )
V_187 = F_16 ( V_186 -> V_43 , V_185 -> V_18 , V_185 -> V_9 ) + 1 ;
else
V_187 = 0 ;
while ( V_187 < 1u << V_185 -> V_9 ) {
V_186 = F_12 ( V_185 , V_187 ++ ) ;
if ( ! V_186 )
continue;
if ( F_42 ( V_186 ) ) {
F_115 ( F_13 ( V_185 -> V_10 [ V_187 ] ) ) ;
return (struct V_25 * ) V_186 ;
}
V_185 = (struct V_1 * ) V_186 ;
V_187 = 0 ;
}
V_186 = (struct V_2 * ) V_185 ;
} while ( ( V_185 = F_4 ( V_186 ) ) != NULL );
return NULL ;
}
static struct V_25 * F_116 ( struct V_49 * V_50 )
{
struct V_1 * V_48 = (struct V_1 * ) F_13 ( V_50 -> V_49 ) ;
if ( ! V_48 )
return NULL ;
if ( F_42 ( V_48 ) )
return (struct V_25 * ) V_48 ;
return F_114 ( V_48 , NULL ) ;
}
static struct V_25 * F_117 ( struct V_25 * V_12 )
{
struct V_2 * V_186 = (struct V_2 * ) V_12 ;
struct V_1 * V_185 = F_4 ( V_186 ) ;
if ( ! V_185 )
return NULL ;
return F_114 ( V_185 , V_186 ) ;
}
static struct V_25 * F_118 ( struct V_49 * V_50 , int V_188 )
{
struct V_25 * V_12 = F_116 ( V_50 ) ;
while ( V_12 && V_188 -- > 0 )
V_12 = F_117 ( V_12 ) ;
return V_12 ;
}
int F_119 ( struct V_90 * V_91 )
{
struct V_49 * V_50 = (struct V_49 * ) V_91 -> V_94 ;
struct V_25 * V_12 , * V_189 = NULL ;
int V_168 = 0 ;
for ( V_12 = F_116 ( V_50 ) ; V_12 ; V_12 = F_117 ( V_12 ) ) {
V_168 += F_112 ( V_12 ) ;
if ( V_189 && F_72 ( & V_189 -> V_38 ) )
F_103 ( V_50 , V_189 ) ;
V_189 = V_12 ;
}
if ( V_189 && F_72 ( & V_189 -> V_38 ) )
F_103 ( V_50 , V_189 ) ;
F_55 ( L_10 , V_168 ) ;
return V_168 ;
}
void F_120 ( struct V_90 * V_91 )
{
F_38 ( V_91 ) ;
}
static int F_121 ( T_1 V_43 , int V_39 , struct V_80 * V_190 ,
struct V_90 * V_91 ,
struct V_191 * V_192 , struct V_193 * V_194 )
{
int V_8 , V_195 ;
struct V_21 * V_22 ;
T_5 V_196 = F_91 ( V_43 ) ;
V_195 = V_194 -> args [ 5 ] ;
V_8 = 0 ;
F_95 (fa, fah, fa_list) {
if ( V_8 < V_195 ) {
V_8 ++ ;
continue;
}
if ( F_122 ( V_192 , F_123 ( V_194 -> V_192 ) . V_197 ,
V_194 -> V_198 -> V_199 ,
V_127 ,
V_91 -> V_105 ,
V_22 -> V_117 ,
V_196 ,
V_39 ,
V_22 -> V_107 ,
V_22 -> V_108 , V_200 ) < 0 ) {
V_194 -> args [ 5 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_194 -> args [ 5 ] = V_8 ;
return V_192 -> V_201 ;
}
static int F_124 ( struct V_25 * V_12 , struct V_90 * V_91 ,
struct V_191 * V_192 , struct V_193 * V_194 )
{
struct V_27 * V_40 ;
struct V_79 * V_3 ;
int V_8 , V_195 ;
V_195 = V_194 -> args [ 4 ] ;
V_8 = 0 ;
F_69 (li, node, &l->list, hlist) {
if ( V_8 < V_195 ) {
V_8 ++ ;
continue;
}
if ( V_8 > V_195 )
V_194 -> args [ 5 ] = 0 ;
if ( F_108 ( & V_40 -> V_42 ) )
continue;
if ( F_121 ( V_12 -> V_43 , V_40 -> V_39 , & V_40 -> V_42 , V_91 , V_192 , V_194 ) < 0 ) {
V_194 -> args [ 4 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_194 -> args [ 4 ] = V_8 ;
return V_192 -> V_201 ;
}
int F_125 ( struct V_90 * V_91 , struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_25 * V_12 ;
struct V_49 * V_50 = (struct V_49 * ) V_91 -> V_94 ;
T_1 V_43 = V_194 -> args [ 2 ] ;
int V_202 = V_194 -> args [ 3 ] ;
F_99 () ;
if ( V_202 == 0 )
V_12 = F_116 ( V_50 ) ;
else {
V_12 = F_77 ( V_50 , V_43 ) ;
if ( ! V_12 )
V_12 = F_118 ( V_50 , V_202 ) ;
}
while ( V_12 ) {
V_194 -> args [ 2 ] = V_12 -> V_43 ;
if ( F_124 ( V_12 , V_91 , V_192 , V_194 ) < 0 ) {
V_194 -> args [ 3 ] = V_202 ;
F_102 () ;
return - 1 ;
}
++ V_202 ;
V_12 = F_117 ( V_12 ) ;
memset ( & V_194 -> args [ 4 ] , 0 ,
sizeof( V_194 -> args ) - 4 * sizeof( V_194 -> args [ 0 ] ) ) ;
}
V_194 -> args [ 3 ] = V_202 ;
F_102 () ;
return V_192 -> V_201 ;
}
void T_6 F_126 ( void )
{
V_24 = F_127 ( L_11 ,
sizeof( struct V_21 ) ,
0 , V_203 , NULL ) ;
V_26 = F_127 ( L_12 ,
F_128 ( sizeof( struct V_25 ) ,
sizeof( struct V_27 ) ) ,
0 , V_203 , NULL ) ;
}
struct V_90 * F_129 ( T_3 V_204 )
{
struct V_90 * V_91 ;
struct V_49 * V_50 ;
V_91 = F_50 ( sizeof( struct V_90 ) + sizeof( struct V_49 ) ,
V_30 ) ;
if ( V_91 == NULL )
return NULL ;
V_91 -> V_105 = V_204 ;
V_91 -> V_205 = - 1 ;
V_91 -> V_133 = 0 ;
V_50 = (struct V_49 * ) V_91 -> V_94 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
return V_91 ;
}
static struct V_2 * F_130 ( struct V_206 * V_207 )
{
struct V_1 * V_7 = V_207 -> V_1 ;
unsigned int V_84 = V_207 -> V_188 ;
struct V_1 * V_185 ;
if ( ! V_7 )
return NULL ;
F_55 ( L_13 ,
V_207 -> V_1 , V_207 -> V_188 , V_207 -> V_208 ) ;
V_209:
while ( V_84 < ( 1 << V_7 -> V_9 ) ) {
struct V_2 * V_48 = F_12 ( V_7 , V_84 ) ;
if ( V_48 ) {
if ( F_42 ( V_48 ) ) {
V_207 -> V_1 = V_7 ;
V_207 -> V_188 = V_84 + 1 ;
} else {
V_207 -> V_1 = (struct V_1 * ) V_48 ;
V_207 -> V_188 = 0 ;
++ V_207 -> V_208 ;
}
return V_48 ;
}
++ V_84 ;
}
V_185 = F_4 ( (struct V_2 * ) V_7 ) ;
if ( V_185 ) {
V_84 = F_16 ( V_7 -> V_43 , V_185 -> V_18 , V_185 -> V_9 ) + 1 ;
V_7 = V_185 ;
-- V_207 -> V_208 ;
goto V_209;
}
return NULL ;
}
static struct V_2 * F_131 ( struct V_206 * V_207 ,
struct V_49 * V_50 )
{
struct V_2 * V_48 ;
if ( ! V_50 )
return NULL ;
V_48 = F_100 ( V_50 -> V_49 ) ;
if ( ! V_48 )
return NULL ;
if ( F_67 ( V_48 ) ) {
V_207 -> V_1 = (struct V_1 * ) V_48 ;
V_207 -> V_188 = 0 ;
V_207 -> V_208 = 1 ;
} else {
V_207 -> V_1 = NULL ;
V_207 -> V_188 = 0 ;
V_207 -> V_208 = 0 ;
}
return V_48 ;
}
static void F_132 ( struct V_49 * V_50 , struct V_210 * V_211 )
{
struct V_2 * V_48 ;
struct V_206 V_207 ;
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
F_99 () ;
for ( V_48 = F_131 ( & V_207 , V_50 ) ; V_48 ; V_48 = F_130 ( & V_207 ) ) {
if ( F_42 ( V_48 ) ) {
struct V_25 * V_12 = (struct V_25 * ) V_48 ;
struct V_27 * V_40 ;
struct V_79 * V_184 ;
V_211 -> V_212 ++ ;
V_211 -> V_213 += V_207 . V_208 ;
if ( V_207 . V_208 > V_211 -> V_214 )
V_211 -> V_214 = V_207 . V_208 ;
F_69 ( V_40 , V_184 , & V_12 -> V_38 , V_83 )
++ V_211 -> V_215 ;
} else {
const struct V_1 * V_7 = ( const struct V_1 * ) V_48 ;
int V_8 ;
V_211 -> V_216 ++ ;
if ( V_7 -> V_9 < V_217 )
V_211 -> V_218 [ V_7 -> V_9 ] ++ ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 -> V_9 ) ; V_8 ++ )
if ( ! V_7 -> V_10 [ V_8 ] )
V_211 -> V_219 ++ ;
}
}
F_102 () ;
}
static void F_133 ( struct V_220 * V_221 , struct V_210 * V_222 )
{
unsigned int V_8 , F_128 , V_223 , V_224 , V_225 ;
if ( V_222 -> V_212 )
V_225 = V_222 -> V_213 * 100 / V_222 -> V_212 ;
else
V_225 = 0 ;
F_134 ( V_221 , L_14 ,
V_225 / 100 , V_225 % 100 ) ;
F_134 ( V_221 , L_15 , V_222 -> V_214 ) ;
F_134 ( V_221 , L_16 , V_222 -> V_212 ) ;
V_224 = sizeof( struct V_25 ) * V_222 -> V_212 ;
F_134 ( V_221 , L_17 , V_222 -> V_215 ) ;
V_224 += sizeof( struct V_27 ) * V_222 -> V_215 ;
F_134 ( V_221 , L_18 , V_222 -> V_216 ) ;
V_224 += sizeof( struct V_1 ) * V_222 -> V_216 ;
F_128 = V_217 ;
while ( F_128 > 0 && V_222 -> V_218 [ F_128 - 1 ] == 0 )
F_128 -- ;
V_223 = 0 ;
for ( V_8 = 1 ; V_8 <= F_128 ; V_8 ++ )
if ( V_222 -> V_218 [ V_8 ] != 0 ) {
F_134 ( V_221 , L_19 , V_8 , V_222 -> V_218 [ V_8 ] ) ;
V_223 += ( 1 << V_8 ) * V_222 -> V_218 [ V_8 ] ;
}
F_135 ( V_221 , '\n' ) ;
F_134 ( V_221 , L_20 , V_223 ) ;
V_224 += sizeof( struct V_2 * ) * V_223 ;
F_134 ( V_221 , L_21 , V_222 -> V_219 ) ;
F_134 ( V_221 , L_22 , ( V_224 + 1023 ) / 1024 ) ;
}
static void F_136 ( struct V_220 * V_221 ,
const struct V_226 * V_64 )
{
F_134 ( V_221 , L_23 ) ;
F_134 ( V_221 , L_24 , V_64 -> gets ) ;
F_134 ( V_221 , L_25 , V_64 -> V_172 ) ;
F_134 ( V_221 , L_26 ,
V_64 -> V_145 ) ;
F_134 ( V_221 , L_27 ,
V_64 -> V_159 ) ;
F_134 ( V_221 , L_28 , V_64 -> V_169 ) ;
F_134 ( V_221 , L_29 ,
V_64 -> V_65 ) ;
}
static void F_137 ( struct V_220 * V_221 , struct V_90 * V_91 )
{
if ( V_91 -> V_105 == V_227 )
F_138 ( V_221 , L_30 ) ;
else if ( V_91 -> V_105 == V_228 )
F_138 ( V_221 , L_31 ) ;
else
F_134 ( V_221 , L_32 , V_91 -> V_105 ) ;
}
static int F_139 ( struct V_220 * V_221 , void * V_229 )
{
struct V_230 * V_230 = (struct V_230 * ) V_221 -> V_231 ;
unsigned int V_232 ;
F_134 ( V_221 ,
L_33
L_34 ,
sizeof( struct V_25 ) , sizeof( struct V_1 ) ) ;
for ( V_232 = 0 ; V_232 < V_233 ; V_232 ++ ) {
struct V_78 * V_20 = & V_230 -> V_234 . V_235 [ V_232 ] ;
struct V_79 * V_3 ;
struct V_90 * V_91 ;
F_69 (tb, node, head, tb_hlist) {
struct V_49 * V_50 = (struct V_49 * ) V_91 -> V_94 ;
struct V_210 V_222 ;
if ( ! V_50 )
continue;
F_137 ( V_221 , V_91 ) ;
F_132 ( V_50 , & V_222 ) ;
F_133 ( V_221 , & V_222 ) ;
#ifdef F_63
F_136 ( V_221 , & V_50 -> V_64 ) ;
#endif
}
}
return 0 ;
}
static int F_140 ( struct V_70 * V_70 , struct V_236 * V_236 )
{
return F_141 ( V_70 , V_236 , F_139 ) ;
}
static struct V_2 * F_142 ( struct V_220 * V_221 , T_7 V_18 )
{
struct V_206 * V_207 = V_221 -> V_231 ;
struct V_230 * V_230 = F_143 ( V_221 ) ;
T_7 V_187 = 0 ;
unsigned int V_232 ;
for ( V_232 = 0 ; V_232 < V_233 ; V_232 ++ ) {
struct V_78 * V_20 = & V_230 -> V_234 . V_235 [ V_232 ] ;
struct V_79 * V_3 ;
struct V_90 * V_91 ;
F_69 (tb, node, head, tb_hlist) {
struct V_2 * V_48 ;
for ( V_48 = F_131 ( V_207 ,
(struct V_49 * ) V_91 -> V_94 ) ;
V_48 ; V_48 = F_130 ( V_207 ) )
if ( V_18 == V_187 ++ ) {
V_207 -> V_91 = V_91 ;
return V_48 ;
}
}
}
return NULL ;
}
static void * F_144 ( struct V_220 * V_221 , T_7 * V_18 )
__acquires( T_8 )
{
F_99 () ;
return F_142 ( V_221 , * V_18 ) ;
}
static void * F_145 ( struct V_220 * V_221 , void * V_229 , T_7 * V_18 )
{
struct V_206 * V_207 = V_221 -> V_231 ;
struct V_230 * V_230 = F_143 ( V_221 ) ;
struct V_90 * V_91 = V_207 -> V_91 ;
struct V_79 * V_237 ;
unsigned int V_232 ;
struct V_2 * V_48 ;
++ * V_18 ;
V_48 = F_130 ( V_207 ) ;
if ( V_48 )
return V_48 ;
V_232 = V_91 -> V_105 & ( V_233 - 1 ) ;
while ( ( V_237 = F_100 ( F_146 ( & V_91 -> V_238 ) ) ) ) {
V_91 = F_147 ( V_237 , struct V_90 , V_238 ) ;
V_48 = F_131 ( V_207 , (struct V_49 * ) V_91 -> V_94 ) ;
if ( V_48 )
goto V_168;
}
while ( ++ V_232 < V_233 ) {
struct V_78 * V_20 = & V_230 -> V_234 . V_235 [ V_232 ] ;
F_69 (tb, tb_node, head, tb_hlist) {
V_48 = F_131 ( V_207 , (struct V_49 * ) V_91 -> V_94 ) ;
if ( V_48 )
goto V_168;
}
}
return NULL ;
V_168:
V_207 -> V_91 = V_91 ;
return V_48 ;
}
static void F_148 ( struct V_220 * V_221 , void * V_229 )
__releases( T_8 )
{
F_102 () ;
}
static void F_149 ( struct V_220 * V_221 , int V_48 )
{
while ( V_48 -- > 0 )
F_138 ( V_221 , L_35 ) ;
}
static inline const char * F_150 ( char * V_239 , T_2 V_201 , enum V_240 V_211 )
{
switch ( V_211 ) {
case V_241 : return L_36 ;
case V_242 : return L_37 ;
case V_243 : return L_38 ;
case V_244 : return L_39 ;
case V_176 : return L_40 ;
default:
snprintf ( V_239 , V_201 , L_41 , V_211 ) ;
return V_239 ;
}
}
static inline const char * F_151 ( char * V_239 , T_2 V_201 , unsigned int V_50 )
{
if ( V_50 < V_245 && V_246 [ V_50 ] )
return V_246 [ V_50 ] ;
snprintf ( V_239 , V_201 , L_42 , V_50 ) ;
return V_239 ;
}
static int F_152 ( struct V_220 * V_221 , void * V_229 )
{
const struct V_206 * V_207 = V_221 -> V_231 ;
struct V_2 * V_48 = V_229 ;
if ( ! F_4 ( V_48 ) )
F_137 ( V_221 , V_207 -> V_91 ) ;
if ( F_67 ( V_48 ) ) {
struct V_1 * V_7 = (struct V_1 * ) V_48 ;
T_5 V_247 = F_91 ( F_15 ( V_7 -> V_43 , V_7 -> V_18 ) ) ;
F_149 ( V_221 , V_207 -> V_208 - 1 ) ;
F_134 ( V_221 , L_43 ,
& V_247 , V_7 -> V_18 , V_7 -> V_9 , V_7 -> V_46 ,
V_7 -> V_47 ) ;
} else {
struct V_25 * V_12 = (struct V_25 * ) V_48 ;
struct V_27 * V_40 ;
struct V_79 * V_3 ;
T_5 V_248 = F_91 ( V_12 -> V_43 ) ;
F_149 ( V_221 , V_207 -> V_208 ) ;
F_134 ( V_221 , L_44 , & V_248 ) ;
F_69 (li, node, &l->list, hlist) {
struct V_21 * V_22 ;
F_95 (fa, &li->falh, fa_list) {
char V_249 [ 32 ] , V_250 [ 32 ] ;
F_149 ( V_221 , V_207 -> V_208 + 1 ) ;
F_134 ( V_221 , L_45 , V_40 -> V_39 ,
F_150 ( V_249 , sizeof( V_249 ) ,
V_22 -> V_108 -> V_142 ) ,
F_151 ( V_250 , sizeof( V_250 ) ,
V_22 -> V_117 ) ) ;
if ( V_22 -> V_107 )
F_134 ( V_221 , L_46 , V_22 -> V_107 ) ;
F_135 ( V_221 , '\n' ) ;
}
}
}
return 0 ;
}
static int F_153 ( struct V_70 * V_70 , struct V_236 * V_236 )
{
return F_154 ( V_70 , V_236 , & V_251 ,
sizeof( struct V_206 ) ) ;
}
static struct V_25 * F_155 ( struct V_252 * V_207 , T_7 V_18 )
{
struct V_25 * V_12 = NULL ;
struct V_49 * V_50 = V_207 -> V_253 ;
if ( V_207 -> V_18 > 0 && V_18 >= V_207 -> V_18 && ( V_12 = F_77 ( V_50 , V_207 -> V_43 ) ) )
V_18 -= V_207 -> V_18 ;
else {
V_207 -> V_18 = 0 ;
V_12 = F_116 ( V_50 ) ;
}
while ( V_12 && V_18 -- > 0 ) {
V_207 -> V_18 ++ ;
V_12 = F_117 ( V_12 ) ;
}
if ( V_12 )
V_207 -> V_43 = V_18 ;
else
V_207 -> V_18 = 0 ;
return V_12 ;
}
static void * F_156 ( struct V_220 * V_221 , T_7 * V_18 )
__acquires( T_8 )
{
struct V_252 * V_207 = V_221 -> V_231 ;
struct V_90 * V_91 ;
F_99 () ;
V_91 = F_157 ( F_143 ( V_221 ) , V_228 ) ;
if ( ! V_91 )
return NULL ;
V_207 -> V_253 = (struct V_49 * ) V_91 -> V_94 ;
if ( * V_18 == 0 )
return V_254 ;
else
return F_155 ( V_207 , * V_18 - 1 ) ;
}
static void * F_158 ( struct V_220 * V_221 , void * V_229 , T_7 * V_18 )
{
struct V_252 * V_207 = V_221 -> V_231 ;
struct V_25 * V_12 = V_229 ;
++ * V_18 ;
if ( V_229 == V_254 ) {
V_207 -> V_18 = 0 ;
V_12 = F_116 ( V_207 -> V_253 ) ;
} else {
V_207 -> V_18 ++ ;
V_12 = F_117 ( V_12 ) ;
}
if ( V_12 )
V_207 -> V_43 = V_12 -> V_43 ;
else
V_207 -> V_18 = 0 ;
return V_12 ;
}
static void F_159 ( struct V_220 * V_221 , void * V_229 )
__releases( T_8 )
{
F_102 () ;
}
static unsigned int F_160 ( int type , T_5 V_101 , const struct V_96 * V_97 )
{
unsigned int V_255 = 0 ;
if ( type == V_256 || type == V_257 )
V_255 = V_258 ;
if ( V_97 && V_97 -> V_148 -> V_259 )
V_255 |= V_260 ;
if ( V_101 == F_91 ( 0xFFFFFFFF ) )
V_255 |= V_261 ;
V_255 |= V_262 ;
return V_255 ;
}
static int F_161 ( struct V_220 * V_221 , void * V_229 )
{
struct V_25 * V_12 = V_229 ;
struct V_27 * V_40 ;
struct V_79 * V_3 ;
if ( V_229 == V_254 ) {
F_134 ( V_221 , L_47 , L_48
L_49
L_50 ) ;
return 0 ;
}
F_69 (li, node, &l->list, hlist) {
struct V_21 * V_22 ;
T_5 V_101 , V_263 ;
V_101 = F_52 ( V_40 -> V_39 ) ;
V_263 = F_91 ( V_12 -> V_43 ) ;
F_95 (fa, &li->falh, fa_list) {
const struct V_96 * V_97 = V_22 -> V_108 ;
unsigned int V_255 = F_160 ( V_22 -> V_117 , V_101 , V_97 ) ;
int V_201 ;
if ( V_22 -> V_117 == V_264
|| V_22 -> V_117 == V_265 )
continue;
if ( V_97 )
F_134 ( V_221 ,
L_51
L_52 ,
V_97 -> V_266 ? V_97 -> V_266 -> V_267 : L_53 ,
V_263 ,
V_97 -> V_148 -> V_259 , V_255 , 0 , 0 ,
V_97 -> V_106 ,
V_101 ,
( V_97 -> V_268 ?
V_97 -> V_268 + 40 : 0 ) ,
V_97 -> V_269 ,
V_97 -> V_270 >> 3 , & V_201 ) ;
else
F_134 ( V_221 ,
L_54
L_52 ,
V_263 , 0 , V_255 , 0 , 0 , 0 ,
V_101 , 0 , 0 , 0 , & V_201 ) ;
F_134 ( V_221 , L_55 , 127 - V_201 , L_56 ) ;
}
}
return 0 ;
}
static int F_162 ( struct V_70 * V_70 , struct V_236 * V_236 )
{
return F_154 ( V_70 , V_236 , & V_271 ,
sizeof( struct V_252 ) ) ;
}
int T_9 F_163 ( struct V_230 * V_230 )
{
if ( ! F_164 ( V_230 , L_5 , V_272 , & V_273 ) )
goto V_274;
if ( ! F_164 ( V_230 , L_57 , V_272 ,
& V_275 ) )
goto V_276;
if ( ! F_164 ( V_230 , L_58 , V_272 , & V_277 ) )
goto V_278;
return 0 ;
V_278:
F_165 ( V_230 , L_57 ) ;
V_276:
F_165 ( V_230 , L_5 ) ;
V_274:
return - V_69 ;
}
void T_10 F_166 ( struct V_230 * V_230 )
{
F_165 ( V_230 , L_5 ) ;
F_165 ( V_230 , L_57 ) ;
F_165 ( V_230 , L_58 ) ;
}
