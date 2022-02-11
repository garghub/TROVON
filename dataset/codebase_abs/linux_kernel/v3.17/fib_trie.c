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
static void F_34 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = F_23 ( V_20 , struct V_1 , V_23 ) ;
T_2 V_28 = sizeof( struct V_1 ) +
( sizeof( struct V_2 * ) << V_7 -> V_9 ) ;
if ( V_28 <= V_29 )
F_35 ( V_7 ) ;
else
F_36 ( V_7 ) ;
}
static inline void F_37 ( struct V_1 * V_7 )
{
if ( F_38 ( V_7 ) )
F_28 ( (struct V_25 * ) V_7 ) ;
else
F_26 ( & V_7 -> V_23 , F_34 ) ;
}
static void F_39 ( struct V_1 * V_7 )
{
F_10 ( F_38 ( V_7 ) ) ;
V_7 -> F_37 = V_31 ;
V_31 = V_7 ;
V_32 += sizeof( struct V_1 ) +
( sizeof( struct V_2 * ) << V_7 -> V_9 ) ;
}
static void F_40 ( void )
{
struct V_1 * V_7 ;
while ( ( V_7 = V_31 ) ) {
V_31 = V_7 -> F_37 ;
V_7 -> F_37 = NULL ;
F_37 ( V_7 ) ;
}
if ( V_32 >= V_29 * V_33 ) {
V_32 = 0 ;
F_41 () ;
}
}
static struct V_25 * F_42 ( void )
{
struct V_25 * V_12 = F_43 ( V_26 , V_30 ) ;
if ( V_12 ) {
V_12 -> V_4 = V_34 ;
F_44 ( & V_12 -> V_35 ) ;
}
return V_12 ;
}
static struct V_27 * F_45 ( int V_36 )
{
struct V_27 * V_37 = F_46 ( sizeof( struct V_27 ) , V_30 ) ;
if ( V_37 ) {
V_37 -> V_36 = V_36 ;
V_37 -> V_38 = F_47 ( F_48 ( V_36 ) ) ;
F_49 ( & V_37 -> V_39 ) ;
}
return V_37 ;
}
static struct V_1 * F_50 ( T_1 V_40 , int V_18 , int V_9 )
{
T_2 V_41 = sizeof( struct V_1 ) + ( sizeof( struct V_2 * ) << V_9 ) ;
struct V_1 * V_7 = F_31 ( V_41 ) ;
if ( V_7 ) {
V_7 -> V_4 = V_42 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_40 = V_40 ;
V_7 -> V_43 = 0 ;
V_7 -> V_44 = 1 << V_9 ;
}
F_51 ( L_1 , V_7 , sizeof( struct V_1 ) ,
sizeof( struct V_2 * ) << V_9 ) ;
return V_7 ;
}
static inline int F_52 ( const struct V_1 * V_7 , const struct V_2 * V_45 )
{
if ( V_45 == NULL || F_38 ( V_45 ) )
return 0 ;
return ( (struct V_1 * ) V_45 ) -> V_18 == V_7 -> V_18 + V_7 -> V_9 ;
}
static inline void F_53 ( struct V_1 * V_7 , int V_8 ,
struct V_2 * V_45 )
{
F_54 ( V_7 , V_8 , V_45 , - 1 ) ;
}
static void F_54 ( struct V_1 * V_7 , int V_8 , struct V_2 * V_45 ,
int V_46 )
{
struct V_2 * V_47 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
int V_48 ;
F_10 ( V_8 >= 1 << V_7 -> V_9 ) ;
if ( V_45 == NULL && V_47 != NULL )
V_7 -> V_44 ++ ;
else if ( V_45 != NULL && V_47 == NULL )
V_7 -> V_44 -- ;
if ( V_46 == - 1 )
V_46 = F_52 ( V_7 , V_47 ) ;
V_48 = F_52 ( V_7 , V_45 ) ;
if ( V_46 && ! V_48 )
V_7 -> V_43 -- ;
else if ( ! V_46 && V_48 )
V_7 -> V_43 ++ ;
if ( V_45 )
F_6 ( V_45 , V_7 ) ;
F_55 ( V_7 -> V_10 [ V_8 ] , V_45 ) ;
}
static struct V_2 * F_56 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_51 ;
int V_52 ;
int V_53 ;
int V_54 ;
if ( ! V_7 )
return NULL ;
F_51 ( L_2 ,
V_7 , V_55 , V_56 ) ;
if ( V_7 -> V_44 == F_14 ( V_7 ) ) {
F_39 ( V_7 ) ;
return NULL ;
}
if ( V_7 -> V_44 == F_14 ( V_7 ) - 1 )
goto V_57;
F_20 ( V_7 ) ;
if ( ! F_1 ( (struct V_2 * ) V_7 ) ) {
V_52 = V_58 ;
V_53 = V_59 ;
} else {
V_52 = V_55 ;
V_53 = V_56 ;
}
V_54 = V_60 ;
while ( ( V_7 -> V_43 > 0 && V_54 -- &&
50 * ( V_7 -> V_43 + F_14 ( V_7 )
- V_7 -> V_44 )
>= V_52 * F_14 ( V_7 ) ) ) {
V_51 = V_7 ;
V_7 = F_57 ( V_50 , V_7 ) ;
if ( F_58 ( V_7 ) ) {
V_7 = V_51 ;
#ifdef F_59
V_50 -> V_61 . V_62 ++ ;
#endif
break;
}
}
F_20 ( V_7 ) ;
if ( V_54 != V_60 )
return (struct V_2 * ) V_7 ;
V_54 = V_60 ;
while ( V_7 -> V_9 > 1 && V_54 -- &&
100 * ( F_14 ( V_7 ) - V_7 -> V_44 ) <
V_53 * F_14 ( V_7 ) ) {
V_51 = V_7 ;
V_7 = F_60 ( V_50 , V_7 ) ;
if ( F_58 ( V_7 ) ) {
V_7 = V_51 ;
#ifdef F_59
V_50 -> V_61 . V_62 ++ ;
#endif
break;
}
}
if ( V_7 -> V_44 == F_14 ( V_7 ) - 1 ) {
V_57:
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
struct V_2 * V_45 ;
V_45 = F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( ! V_45 )
continue;
F_6 ( V_45 , NULL ) ;
F_39 ( V_7 ) ;
return V_45 ;
}
}
return (struct V_2 * ) V_7 ;
}
static void F_61 ( struct V_1 * V_7 )
{
int V_8 ;
struct V_1 * V_63 ;
for ( V_8 = 0 ; V_8 < F_14 ( V_7 ) ; V_8 ++ ) {
V_63 = (struct V_1 * ) F_11 ( V_7 -> V_10 [ V_8 ] ) ;
if ( V_63 )
F_37 ( V_63 ) ;
}
F_37 ( V_7 ) ;
}
static struct V_1 * F_57 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
struct V_1 * V_64 = V_7 ;
int V_65 = F_14 ( V_7 ) ;
int V_8 ;
F_51 ( L_3 ) ;
V_7 = F_50 ( V_64 -> V_40 , V_64 -> V_18 , V_64 -> V_9 + 1 ) ;
if ( ! V_7 )
return F_62 ( - V_66 ) ;
for ( V_8 = 0 ; V_8 < V_65 ; V_8 ++ ) {
struct V_1 * V_67 ;
V_67 = (struct V_1 * ) F_9 ( V_64 , V_8 ) ;
if ( V_67 &&
F_63 ( V_67 ) &&
V_67 -> V_18 == V_64 -> V_18 + V_64 -> V_9 &&
V_67 -> V_9 > 1 ) {
struct V_1 * V_68 , * V_69 ;
T_1 V_70 = ~ 0U << ( V_13 - 1 ) >> V_67 -> V_18 ;
V_68 = F_50 ( V_67 -> V_40 & ( ~ V_70 ) , V_67 -> V_18 + 1 ,
V_67 -> V_9 - 1 ) ;
if ( ! V_68 )
goto V_71;
V_69 = F_50 ( V_67 -> V_40 | V_70 , V_67 -> V_18 + 1 ,
V_67 -> V_9 - 1 ) ;
if ( ! V_69 ) {
F_37 ( V_68 ) ;
goto V_71;
}
F_53 ( V_7 , 2 * V_8 , (struct V_2 * ) V_68 ) ;
F_53 ( V_7 , 2 * V_8 + 1 , (struct V_2 * ) V_69 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_65 ; V_8 ++ ) {
struct V_1 * V_67 ;
struct V_2 * V_3 = F_9 ( V_64 , V_8 ) ;
struct V_1 * V_68 , * V_69 ;
int V_28 , V_72 ;
if ( V_3 == NULL )
continue;
if ( F_38 ( V_3 ) || ( (struct V_1 * ) V_3 ) -> V_18 >
V_7 -> V_18 + V_7 -> V_9 - 1 ) {
F_53 ( V_7 ,
F_16 ( V_3 -> V_40 , V_64 -> V_18 , V_64 -> V_9 + 1 ) ,
V_3 ) ;
continue;
}
V_67 = (struct V_1 * ) V_3 ;
if ( V_67 -> V_9 == 1 ) {
F_53 ( V_7 , 2 * V_8 , F_11 ( V_67 -> V_10 [ 0 ] ) ) ;
F_53 ( V_7 , 2 * V_8 + 1 , F_11 ( V_67 -> V_10 [ 1 ] ) ) ;
F_39 ( V_67 ) ;
continue;
}
V_68 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 ) ;
F_53 ( V_7 , 2 * V_8 , NULL ) ;
F_10 ( ! V_68 ) ;
V_69 = (struct V_1 * ) F_9 ( V_7 , 2 * V_8 + 1 ) ;
F_53 ( V_7 , 2 * V_8 + 1 , NULL ) ;
F_10 ( ! V_69 ) ;
V_28 = F_14 ( V_68 ) ;
for ( V_72 = 0 ; V_72 < V_28 ; V_72 ++ ) {
F_53 ( V_68 , V_72 , F_11 ( V_67 -> V_10 [ V_72 ] ) ) ;
F_53 ( V_69 , V_72 , F_11 ( V_67 -> V_10 [ V_72 + V_28 ] ) ) ;
}
F_53 ( V_7 , 2 * V_8 , F_56 ( V_50 , V_68 ) ) ;
F_53 ( V_7 , 2 * V_8 + 1 , F_56 ( V_50 , V_69 ) ) ;
F_39 ( V_67 ) ;
}
F_39 ( V_64 ) ;
return V_7 ;
V_71:
F_61 ( V_7 ) ;
return F_62 ( - V_66 ) ;
}
static struct V_1 * F_60 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
struct V_1 * V_64 = V_7 ;
struct V_2 * V_68 , * V_69 ;
int V_8 ;
int V_65 = F_14 ( V_7 ) ;
F_51 ( L_4 ) ;
V_7 = F_50 ( V_64 -> V_40 , V_64 -> V_18 , V_64 -> V_9 - 1 ) ;
if ( ! V_7 )
return F_62 ( - V_66 ) ;
for ( V_8 = 0 ; V_8 < V_65 ; V_8 += 2 ) {
V_68 = F_9 ( V_64 , V_8 ) ;
V_69 = F_9 ( V_64 , V_8 + 1 ) ;
if ( V_68 && V_69 ) {
struct V_1 * V_73 ;
V_73 = F_50 ( V_68 -> V_40 , V_7 -> V_18 + V_7 -> V_9 , 1 ) ;
if ( ! V_73 )
goto V_71;
F_53 ( V_7 , V_8 / 2 , (struct V_2 * ) V_73 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_65 ; V_8 += 2 ) {
struct V_1 * V_74 ;
V_68 = F_9 ( V_64 , V_8 ) ;
V_69 = F_9 ( V_64 , V_8 + 1 ) ;
if ( V_68 == NULL ) {
if ( V_69 == NULL )
continue;
F_53 ( V_7 , V_8 / 2 , V_69 ) ;
continue;
}
if ( V_69 == NULL ) {
F_53 ( V_7 , V_8 / 2 , V_68 ) ;
continue;
}
V_74 = (struct V_1 * ) F_9 ( V_7 , V_8 / 2 ) ;
F_53 ( V_7 , V_8 / 2 , NULL ) ;
F_53 ( V_74 , 0 , V_68 ) ;
F_53 ( V_74 , 1 , V_69 ) ;
F_53 ( V_7 , V_8 / 2 , F_56 ( V_50 , V_74 ) ) ;
}
F_39 ( V_64 ) ;
return V_7 ;
V_71:
F_61 ( V_7 ) ;
return F_62 ( - V_66 ) ;
}
static struct V_27 * F_64 ( struct V_25 * V_12 , int V_36 )
{
struct V_75 * V_20 = & V_12 -> V_35 ;
struct V_27 * V_37 ;
F_65 (li, head, hlist)
if ( V_37 -> V_36 == V_36 )
return V_37 ;
return NULL ;
}
static inline struct V_76 * F_66 ( struct V_25 * V_12 , int V_36 )
{
struct V_27 * V_37 = F_64 ( V_12 , V_36 ) ;
if ( ! V_37 )
return NULL ;
return & V_37 -> V_39 ;
}
static void F_67 ( struct V_75 * V_20 , struct V_27 * V_77 )
{
struct V_27 * V_37 = NULL , * V_78 = NULL ;
if ( F_68 ( V_20 ) ) {
F_69 ( & V_77 -> V_79 , V_20 ) ;
} else {
F_70 (li, head, hlist) {
if ( V_77 -> V_36 > V_37 -> V_36 )
break;
V_78 = V_37 ;
}
if ( V_78 )
F_71 ( & V_77 -> V_79 , & V_78 -> V_79 ) ;
else
F_72 ( & V_77 -> V_79 , & V_37 -> V_79 ) ;
}
}
static struct V_25 *
F_73 ( struct V_49 * V_50 , T_3 V_40 )
{
int V_18 ;
struct V_1 * V_7 ;
struct V_2 * V_45 ;
V_18 = 0 ;
V_45 = F_13 ( V_50 -> V_49 ) ;
while ( V_45 != NULL && F_8 ( V_45 ) == V_42 ) {
V_7 = (struct V_1 * ) V_45 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_40 , V_18 , V_7 -> V_18 - V_18 , V_40 ) ) {
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_45 = F_12 ( V_7 ,
F_16 ( V_40 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
} else
break;
}
if ( V_45 != NULL && F_38 ( V_45 ) && F_17 ( V_40 , V_45 -> V_40 ) )
return (struct V_25 * ) V_45 ;
return NULL ;
}
static void F_74 ( struct V_49 * V_50 , struct V_1 * V_7 )
{
int V_46 ;
T_1 V_80 , V_40 ;
struct V_1 * V_81 ;
V_40 = V_7 -> V_40 ;
while ( V_7 != NULL && ( V_81 = F_1 ( (struct V_2 * ) V_7 ) ) != NULL ) {
V_80 = F_16 ( V_40 , V_81 -> V_18 , V_81 -> V_9 ) ;
V_46 = F_52 ( V_81 , F_9 ( V_81 , V_80 ) ) ;
V_7 = (struct V_1 * ) F_56 ( V_50 , V_7 ) ;
F_54 ( V_81 , V_80 ,
(struct V_2 * ) V_7 , V_46 ) ;
V_81 = F_1 ( (struct V_2 * ) V_7 ) ;
if ( ! V_81 )
F_55 ( V_50 -> V_49 , (struct V_2 * ) V_7 ) ;
F_40 () ;
if ( ! V_81 )
break;
V_7 = V_81 ;
}
if ( F_63 ( V_7 ) )
V_7 = (struct V_1 * ) F_56 ( V_50 , V_7 ) ;
F_55 ( V_50 -> V_49 , (struct V_2 * ) V_7 ) ;
F_40 () ;
}
static struct V_76 * F_75 ( struct V_49 * V_50 , T_3 V_40 , int V_36 )
{
int V_18 , V_82 ;
struct V_1 * V_81 = NULL , * V_7 = NULL ;
struct V_2 * V_45 ;
struct V_25 * V_12 ;
int V_83 ;
struct V_76 * V_84 = NULL ;
struct V_27 * V_37 ;
T_1 V_80 ;
V_18 = 0 ;
V_45 = F_11 ( V_50 -> V_49 ) ;
while ( V_45 != NULL && F_8 ( V_45 ) == V_42 ) {
V_7 = (struct V_1 * ) V_45 ;
F_20 ( V_7 ) ;
if ( F_18 ( V_7 -> V_40 , V_18 , V_7 -> V_18 - V_18 , V_40 ) ) {
V_81 = V_7 ;
V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_45 = F_9 ( V_7 ,
F_16 ( V_40 ,
V_7 -> V_18 ,
V_7 -> V_9 ) ) ;
F_10 ( V_45 && F_1 ( V_45 ) != V_7 ) ;
} else
break;
}
F_10 ( V_81 && F_38 ( V_81 ) ) ;
if ( V_45 != NULL && F_38 ( V_45 ) && F_17 ( V_40 , V_45 -> V_40 ) ) {
V_12 = (struct V_25 * ) V_45 ;
V_37 = F_45 ( V_36 ) ;
if ( ! V_37 )
return NULL ;
V_84 = & V_37 -> V_39 ;
F_67 ( & V_12 -> V_35 , V_37 ) ;
goto V_85;
}
V_12 = F_42 () ;
if ( ! V_12 )
return NULL ;
V_12 -> V_40 = V_40 ;
V_37 = F_45 ( V_36 ) ;
if ( ! V_37 ) {
F_28 ( V_12 ) ;
return NULL ;
}
V_84 = & V_37 -> V_39 ;
F_67 ( & V_12 -> V_35 , V_37 ) ;
if ( V_50 -> V_49 && V_45 == NULL ) {
F_6 ( (struct V_2 * ) V_12 , V_81 ) ;
V_80 = F_16 ( V_40 , V_81 -> V_18 , V_81 -> V_9 ) ;
F_53 ( V_81 , V_80 , (struct V_2 * ) V_12 ) ;
} else {
if ( V_45 ) {
V_18 = V_81 ? V_81 -> V_18 + V_81 -> V_9 : 0 ;
V_82 = F_19 ( V_40 , V_18 , V_45 -> V_40 ) ;
V_7 = F_50 ( V_45 -> V_40 , V_82 , 1 ) ;
} else {
V_82 = 0 ;
V_7 = F_50 ( V_40 , V_82 , 1 ) ;
}
if ( ! V_7 ) {
F_29 ( V_37 ) ;
F_28 ( V_12 ) ;
return NULL ;
}
F_6 ( (struct V_2 * ) V_7 , V_81 ) ;
V_83 = F_16 ( V_40 , V_82 , 1 ) ;
F_53 ( V_7 , V_83 , (struct V_2 * ) V_12 ) ;
F_53 ( V_7 , 1 - V_83 , V_45 ) ;
if ( V_81 ) {
V_80 = F_16 ( V_40 , V_81 -> V_18 , V_81 -> V_9 ) ;
F_53 ( V_81 , V_80 , (struct V_2 * ) V_7 ) ;
} else {
F_55 ( V_50 -> V_49 , (struct V_2 * ) V_7 ) ;
V_81 = V_7 ;
}
}
if ( V_81 && V_81 -> V_18 + V_81 -> V_9 > 32 )
F_76 ( L_5 ,
V_81 , V_81 -> V_18 , V_81 -> V_9 , V_40 , V_36 ) ;
F_74 ( V_50 , V_81 ) ;
V_85:
return V_84 ;
}
int F_77 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
struct V_49 * V_50 = (struct V_49 * ) V_87 -> V_90 ;
struct V_21 * V_22 , * V_91 ;
struct V_76 * V_84 = NULL ;
struct V_92 * V_93 ;
int V_36 = V_89 -> V_94 ;
T_4 V_95 = V_89 -> V_96 ;
T_3 V_40 , V_97 ;
int V_98 ;
struct V_25 * V_12 ;
if ( V_36 > 32 )
return - V_99 ;
V_40 = F_47 ( V_89 -> V_100 ) ;
F_51 ( L_6 , V_87 -> V_101 , V_40 , V_36 ) ;
V_97 = F_47 ( F_48 ( V_36 ) ) ;
if ( V_40 & ~ V_97 )
return - V_99 ;
V_40 = V_40 & V_97 ;
V_93 = F_78 ( V_89 ) ;
if ( F_58 ( V_93 ) ) {
V_98 = F_79 ( V_93 ) ;
goto V_98;
}
V_12 = F_73 ( V_50 , V_40 ) ;
V_22 = NULL ;
if ( V_12 ) {
V_84 = F_66 ( V_12 , V_36 ) ;
V_22 = F_80 ( V_84 , V_95 , V_93 -> V_102 ) ;
}
if ( V_22 && V_22 -> V_103 == V_95 &&
V_22 -> V_104 -> V_102 == V_93 -> V_102 ) {
struct V_21 * V_105 , * V_106 ;
V_98 = - V_107 ;
if ( V_89 -> V_108 & V_109 )
goto V_110;
V_106 = NULL ;
V_105 = V_22 ;
V_22 = F_81 ( V_22 -> V_111 . V_112 , struct V_21 , V_111 ) ;
F_82 (fa, fa_head, fa_list) {
if ( V_22 -> V_103 != V_95 )
break;
if ( V_22 -> V_104 -> V_102 != V_93 -> V_102 )
break;
if ( V_22 -> V_113 == V_89 -> V_114 &&
V_22 -> V_104 == V_93 ) {
V_106 = V_22 ;
break;
}
}
if ( V_89 -> V_108 & V_115 ) {
struct V_92 * V_116 ;
T_4 V_117 ;
V_22 = V_105 ;
if ( V_106 ) {
if ( V_22 == V_106 )
V_98 = 0 ;
goto V_110;
}
V_98 = - V_118 ;
V_91 = F_43 ( V_24 , V_30 ) ;
if ( V_91 == NULL )
goto V_110;
V_116 = V_22 -> V_104 ;
V_91 -> V_103 = V_22 -> V_103 ;
V_91 -> V_104 = V_93 ;
V_91 -> V_113 = V_89 -> V_114 ;
V_117 = V_22 -> V_119 ;
V_91 -> V_119 = V_117 & ~ V_120 ;
F_83 ( & V_22 -> V_111 , & V_91 -> V_111 ) ;
F_25 ( V_22 ) ;
F_84 ( V_116 ) ;
if ( V_117 & V_120 )
F_85 ( V_89 -> V_121 . V_122 ) ;
F_86 ( V_123 , F_87 ( V_40 ) , V_91 , V_36 ,
V_87 -> V_101 , & V_89 -> V_121 , V_115 ) ;
goto V_124;
}
if ( V_106 )
goto V_110;
if ( ! ( V_89 -> V_108 & V_125 ) )
V_22 = V_105 ;
}
V_98 = - V_126 ;
if ( ! ( V_89 -> V_108 & V_127 ) )
goto V_110;
V_98 = - V_118 ;
V_91 = F_43 ( V_24 , V_30 ) ;
if ( V_91 == NULL )
goto V_110;
V_91 -> V_104 = V_93 ;
V_91 -> V_103 = V_95 ;
V_91 -> V_113 = V_89 -> V_114 ;
V_91 -> V_119 = 0 ;
if ( ! V_84 ) {
V_84 = F_75 ( V_50 , V_40 , V_36 ) ;
if ( F_88 ( ! V_84 ) ) {
V_98 = - V_66 ;
goto V_128;
}
}
if ( ! V_36 )
V_87 -> V_129 ++ ;
F_89 ( & V_91 -> V_111 ,
( V_22 ? & V_22 -> V_111 : V_84 ) ) ;
F_85 ( V_89 -> V_121 . V_122 ) ;
F_86 ( V_123 , F_87 ( V_40 ) , V_91 , V_36 , V_87 -> V_101 ,
& V_89 -> V_121 , 0 ) ;
V_124:
return 0 ;
V_128:
F_24 ( V_24 , V_91 ) ;
V_110:
F_84 ( V_93 ) ;
V_98:
return V_98 ;
}
static int F_90 ( struct V_86 * V_87 , struct V_49 * V_50 , struct V_25 * V_12 ,
T_1 V_40 , const struct V_130 * V_131 ,
struct V_132 * V_133 , int V_134 )
{
struct V_27 * V_37 ;
struct V_75 * V_135 = & V_12 -> V_35 ;
F_65 (li, hhead, hlist) {
struct V_21 * V_22 ;
if ( V_12 -> V_40 != ( V_40 & V_37 -> V_38 ) )
continue;
F_91 (fa, &li->falh, fa_list) {
struct V_92 * V_93 = V_22 -> V_104 ;
int V_136 , V_98 ;
if ( V_22 -> V_103 && V_22 -> V_103 != V_131 -> V_137 )
continue;
if ( V_93 -> V_138 )
continue;
if ( V_22 -> V_104 -> V_139 < V_131 -> V_140 )
continue;
F_92 ( V_22 ) ;
V_98 = V_141 [ V_22 -> V_113 ] . error ;
if ( V_98 ) {
#ifdef F_59
V_50 -> V_61 . V_142 ++ ;
#endif
return V_98 ;
}
if ( V_93 -> V_134 & V_143 )
continue;
for ( V_136 = 0 ; V_136 < V_93 -> V_144 ; V_136 ++ ) {
const struct V_145 * V_146 = & V_93 -> V_145 [ V_136 ] ;
if ( V_146 -> V_147 & V_143 )
continue;
if ( V_131 -> V_148 && V_131 -> V_148 != V_146 -> V_149 )
continue;
#ifdef F_59
V_50 -> V_61 . V_142 ++ ;
#endif
V_133 -> V_150 = V_37 -> V_36 ;
V_133 -> V_151 = V_136 ;
V_133 -> type = V_22 -> V_113 ;
V_133 -> V_152 = V_22 -> V_104 -> V_139 ;
V_133 -> V_93 = V_93 ;
V_133 -> V_153 = V_87 ;
V_133 -> V_84 = & V_37 -> V_39 ;
if ( ! ( V_134 & V_154 ) )
F_93 ( & V_93 -> V_155 ) ;
return 0 ;
}
}
#ifdef F_59
V_50 -> V_61 . V_156 ++ ;
#endif
}
return 1 ;
}
int F_94 ( struct V_86 * V_87 , const struct V_130 * V_131 ,
struct V_132 * V_133 , int V_134 )
{
struct V_49 * V_50 = (struct V_49 * ) V_87 -> V_90 ;
int V_157 ;
struct V_2 * V_45 ;
struct V_1 * V_158 ;
unsigned int V_18 , V_9 ;
T_1 V_40 = F_47 ( V_131 -> V_159 ) ;
unsigned int V_160 ;
T_1 V_80 = 0 ;
unsigned int V_161 = V_13 ;
struct V_1 * V_162 ;
T_1 V_163 ;
F_95 () ;
V_45 = F_96 ( V_50 -> V_49 ) ;
if ( ! V_45 )
goto V_164;
#ifdef F_59
V_50 -> V_61 . gets ++ ;
#endif
if ( F_38 ( V_45 ) ) {
V_157 = F_90 ( V_87 , V_50 , (struct V_25 * ) V_45 , V_40 , V_131 , V_133 , V_134 ) ;
goto V_165;
}
V_158 = (struct V_1 * ) V_45 ;
V_160 = 0 ;
while ( V_158 ) {
V_18 = V_158 -> V_18 ;
V_9 = V_158 -> V_9 ;
if ( ! V_160 )
V_80 = F_16 ( F_15 ( V_40 , V_161 ) ,
V_18 , V_9 ) ;
V_45 = F_12 ( V_158 , V_80 ) ;
if ( V_45 == NULL ) {
#ifdef F_59
V_50 -> V_61 . V_166 ++ ;
#endif
goto V_167;
}
if ( F_38 ( V_45 ) ) {
V_157 = F_90 ( V_87 , V_50 , (struct V_25 * ) V_45 , V_40 , V_131 , V_133 , V_134 ) ;
if ( V_157 > 0 )
goto V_167;
goto V_165;
}
V_162 = (struct V_1 * ) V_45 ;
if ( V_161 < V_18 + V_9 ) {
if ( F_16 ( V_162 -> V_40 , V_161 ,
V_162 -> V_18 - V_161 )
|| ! ( V_162 -> V_10 [ 0 ] ) )
goto V_167;
}
V_163 = F_15 ( V_162 -> V_40 ^ V_40 , V_162 -> V_18 ) ;
if ( V_163 ) {
int V_168 = V_13 - F_97 ( V_163 ) - 1 ;
if ( F_16 ( V_162 -> V_40 , V_168 , V_162 -> V_18 - V_168 ) != 0 )
goto V_167;
if ( V_161 >= V_162 -> V_18 )
V_161 = V_168 ;
}
V_158 = (struct V_1 * ) V_45 ;
V_160 = 0 ;
continue;
V_167:
V_160 ++ ;
while ( ( V_160 <= V_158 -> V_9 )
&& ! ( V_80 & ( 1 << ( V_160 - 1 ) ) ) )
V_160 ++ ;
if ( V_161 > V_158 -> V_18 + V_158 -> V_9 - V_160 )
V_161 = V_158 -> V_18 + V_158 -> V_9
- V_160 ;
if ( V_160 <= V_158 -> V_9 ) {
V_80 &= ~ ( 1 << ( V_160 - 1 ) ) ;
} else {
struct V_1 * V_4 = F_4 ( (struct V_2 * ) V_158 ) ;
if ( ! V_4 )
goto V_164;
V_80 = F_16 ( V_158 -> V_40 , V_4 -> V_18 , V_4 -> V_9 ) ;
V_158 = V_4 ;
V_160 = 0 ;
#ifdef F_59
V_50 -> V_61 . V_169 ++ ;
#endif
goto V_167;
}
}
V_164:
V_157 = 1 ;
V_165:
F_98 () ;
return V_157 ;
}
static void F_99 ( struct V_49 * V_50 , struct V_25 * V_12 )
{
struct V_1 * V_81 = F_1 ( (struct V_2 * ) V_12 ) ;
F_51 ( L_7 , V_12 ) ;
if ( V_81 ) {
T_1 V_80 = F_16 ( V_12 -> V_40 , V_81 -> V_18 , V_81 -> V_9 ) ;
F_53 ( V_81 , V_80 , NULL ) ;
F_74 ( V_50 , V_81 ) ;
} else
F_100 ( V_50 -> V_49 , NULL ) ;
F_28 ( V_12 ) ;
}
int F_101 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
struct V_49 * V_50 = (struct V_49 * ) V_87 -> V_90 ;
T_3 V_40 , V_97 ;
int V_36 = V_89 -> V_94 ;
T_4 V_95 = V_89 -> V_96 ;
struct V_21 * V_22 , * V_170 ;
struct V_76 * V_84 ;
struct V_25 * V_12 ;
struct V_27 * V_37 ;
if ( V_36 > 32 )
return - V_99 ;
V_40 = F_47 ( V_89 -> V_100 ) ;
V_97 = F_47 ( F_48 ( V_36 ) ) ;
if ( V_40 & ~ V_97 )
return - V_99 ;
V_40 = V_40 & V_97 ;
V_12 = F_73 ( V_50 , V_40 ) ;
if ( ! V_12 )
return - V_171 ;
V_37 = F_64 ( V_12 , V_36 ) ;
if ( ! V_37 )
return - V_171 ;
V_84 = & V_37 -> V_39 ;
V_22 = F_80 ( V_84 , V_95 , 0 ) ;
if ( ! V_22 )
return - V_171 ;
F_51 ( L_8 , V_40 , V_36 , V_95 , V_50 ) ;
V_170 = NULL ;
V_22 = F_81 ( V_22 -> V_111 . V_112 , struct V_21 , V_111 ) ;
F_82 (fa, fa_head, fa_list) {
struct V_92 * V_93 = V_22 -> V_104 ;
if ( V_22 -> V_103 != V_95 )
break;
if ( ( ! V_89 -> V_114 || V_22 -> V_113 == V_89 -> V_114 ) &&
( V_89 -> V_172 == V_173 ||
V_22 -> V_104 -> V_139 == V_89 -> V_172 ) &&
( ! V_89 -> V_174 ||
V_93 -> V_175 == V_89 -> V_174 ) &&
( ! V_89 -> V_176 ||
V_93 -> V_177 == V_89 -> V_176 ) &&
F_102 ( V_89 , V_93 ) == 0 ) {
V_170 = V_22 ;
break;
}
}
if ( ! V_170 )
return - V_171 ;
V_22 = V_170 ;
F_86 ( V_178 , F_87 ( V_40 ) , V_22 , V_36 , V_87 -> V_101 ,
& V_89 -> V_121 , 0 ) ;
F_103 ( & V_22 -> V_111 ) ;
if ( ! V_36 )
V_87 -> V_129 -- ;
if ( F_104 ( V_84 ) ) {
F_105 ( & V_37 -> V_79 ) ;
F_29 ( V_37 ) ;
}
if ( F_68 ( & V_12 -> V_35 ) )
F_99 ( V_50 , V_12 ) ;
if ( V_22 -> V_119 & V_120 )
F_85 ( V_89 -> V_121 . V_122 ) ;
F_84 ( V_22 -> V_104 ) ;
F_25 ( V_22 ) ;
return 0 ;
}
static int F_106 ( struct V_76 * V_20 )
{
struct V_21 * V_22 , * V_179 ;
int V_165 = 0 ;
F_107 (fa, fa_node, head, fa_list) {
struct V_92 * V_93 = V_22 -> V_104 ;
if ( V_93 && ( V_93 -> V_134 & V_143 ) ) {
F_103 ( & V_22 -> V_111 ) ;
F_84 ( V_22 -> V_104 ) ;
F_25 ( V_22 ) ;
V_165 ++ ;
}
}
return V_165 ;
}
static int F_108 ( struct V_25 * V_12 )
{
int V_165 = 0 ;
struct V_75 * V_180 = & V_12 -> V_35 ;
struct V_181 * V_182 ;
struct V_27 * V_37 = NULL ;
F_109 (li, tmp, lih, hlist) {
V_165 += F_106 ( & V_37 -> V_39 ) ;
if ( F_104 ( & V_37 -> V_39 ) ) {
F_105 ( & V_37 -> V_79 ) ;
F_29 ( V_37 ) ;
}
}
return V_165 ;
}
static struct V_25 * F_110 ( struct V_1 * V_183 , struct V_2 * V_184 )
{
do {
T_1 V_185 ;
if ( V_184 )
V_185 = F_16 ( V_184 -> V_40 , V_183 -> V_18 , V_183 -> V_9 ) + 1 ;
else
V_185 = 0 ;
while ( V_185 < 1u << V_183 -> V_9 ) {
V_184 = F_12 ( V_183 , V_185 ++ ) ;
if ( ! V_184 )
continue;
if ( F_38 ( V_184 ) )
return (struct V_25 * ) V_184 ;
V_183 = (struct V_1 * ) V_184 ;
V_185 = 0 ;
}
V_184 = (struct V_2 * ) V_183 ;
} while ( ( V_183 = F_4 ( V_184 ) ) != NULL );
return NULL ;
}
static struct V_25 * F_111 ( struct V_49 * V_50 )
{
struct V_1 * V_45 = (struct V_1 * ) F_13 ( V_50 -> V_49 ) ;
if ( ! V_45 )
return NULL ;
if ( F_38 ( V_45 ) )
return (struct V_25 * ) V_45 ;
return F_110 ( V_45 , NULL ) ;
}
static struct V_25 * F_112 ( struct V_25 * V_12 )
{
struct V_2 * V_184 = (struct V_2 * ) V_12 ;
struct V_1 * V_183 = F_4 ( V_184 ) ;
if ( ! V_183 )
return NULL ;
return F_110 ( V_183 , V_184 ) ;
}
static struct V_25 * F_113 ( struct V_49 * V_50 , int V_186 )
{
struct V_25 * V_12 = F_111 ( V_50 ) ;
while ( V_12 && V_186 -- > 0 )
V_12 = F_112 ( V_12 ) ;
return V_12 ;
}
int F_114 ( struct V_86 * V_87 )
{
struct V_49 * V_50 = (struct V_49 * ) V_87 -> V_90 ;
struct V_25 * V_12 , * V_187 = NULL ;
int V_165 = 0 ;
for ( V_12 = F_111 ( V_50 ) ; V_12 ; V_12 = F_112 ( V_12 ) ) {
V_165 += F_108 ( V_12 ) ;
if ( V_187 && F_68 ( & V_187 -> V_35 ) )
F_99 ( V_50 , V_187 ) ;
V_187 = V_12 ;
}
if ( V_187 && F_68 ( & V_187 -> V_35 ) )
F_99 ( V_50 , V_187 ) ;
F_51 ( L_9 , V_165 ) ;
return V_165 ;
}
void F_115 ( struct V_86 * V_87 )
{
F_35 ( V_87 ) ;
}
static int F_116 ( T_1 V_40 , int V_36 , struct V_76 * V_188 ,
struct V_86 * V_87 ,
struct V_189 * V_190 , struct V_191 * V_192 )
{
int V_8 , V_193 ;
struct V_21 * V_22 ;
T_5 V_194 = F_87 ( V_40 ) ;
V_193 = V_192 -> args [ 5 ] ;
V_8 = 0 ;
F_91 (fa, fah, fa_list) {
if ( V_8 < V_193 ) {
V_8 ++ ;
continue;
}
if ( F_117 ( V_190 , F_118 ( V_192 -> V_190 ) . V_195 ,
V_192 -> V_196 -> V_197 ,
V_123 ,
V_87 -> V_101 ,
V_22 -> V_113 ,
V_194 ,
V_36 ,
V_22 -> V_103 ,
V_22 -> V_104 , V_198 ) < 0 ) {
V_192 -> args [ 5 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_192 -> args [ 5 ] = V_8 ;
return V_190 -> V_199 ;
}
static int F_119 ( struct V_25 * V_12 , struct V_86 * V_87 ,
struct V_189 * V_190 , struct V_191 * V_192 )
{
struct V_27 * V_37 ;
int V_8 , V_193 ;
V_193 = V_192 -> args [ 4 ] ;
V_8 = 0 ;
F_65 (li, &l->list, hlist) {
if ( V_8 < V_193 ) {
V_8 ++ ;
continue;
}
if ( V_8 > V_193 )
V_192 -> args [ 5 ] = 0 ;
if ( F_104 ( & V_37 -> V_39 ) )
continue;
if ( F_116 ( V_12 -> V_40 , V_37 -> V_36 , & V_37 -> V_39 , V_87 , V_190 , V_192 ) < 0 ) {
V_192 -> args [ 4 ] = V_8 ;
return - 1 ;
}
V_8 ++ ;
}
V_192 -> args [ 4 ] = V_8 ;
return V_190 -> V_199 ;
}
int F_120 ( struct V_86 * V_87 , struct V_189 * V_190 ,
struct V_191 * V_192 )
{
struct V_25 * V_12 ;
struct V_49 * V_50 = (struct V_49 * ) V_87 -> V_90 ;
T_1 V_40 = V_192 -> args [ 2 ] ;
int V_200 = V_192 -> args [ 3 ] ;
F_95 () ;
if ( V_200 == 0 )
V_12 = F_111 ( V_50 ) ;
else {
V_12 = F_73 ( V_50 , V_40 ) ;
if ( ! V_12 )
V_12 = F_113 ( V_50 , V_200 ) ;
}
while ( V_12 ) {
V_192 -> args [ 2 ] = V_12 -> V_40 ;
if ( F_119 ( V_12 , V_87 , V_190 , V_192 ) < 0 ) {
V_192 -> args [ 3 ] = V_200 ;
F_98 () ;
return - 1 ;
}
++ V_200 ;
V_12 = F_112 ( V_12 ) ;
memset ( & V_192 -> args [ 4 ] , 0 ,
sizeof( V_192 -> args ) - 4 * sizeof( V_192 -> args [ 0 ] ) ) ;
}
V_192 -> args [ 3 ] = V_200 ;
F_98 () ;
return V_190 -> V_199 ;
}
void T_6 F_121 ( void )
{
V_24 = F_122 ( L_10 ,
sizeof( struct V_21 ) ,
0 , V_201 , NULL ) ;
V_26 = F_122 ( L_11 ,
F_123 ( sizeof( struct V_25 ) ,
sizeof( struct V_27 ) ) ,
0 , V_201 , NULL ) ;
}
struct V_86 * F_124 ( T_3 V_202 )
{
struct V_86 * V_87 ;
struct V_49 * V_50 ;
V_87 = F_46 ( sizeof( struct V_86 ) + sizeof( struct V_49 ) ,
V_30 ) ;
if ( V_87 == NULL )
return NULL ;
V_87 -> V_101 = V_202 ;
V_87 -> V_203 = - 1 ;
V_87 -> V_129 = 0 ;
V_50 = (struct V_49 * ) V_87 -> V_90 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
return V_87 ;
}
static struct V_2 * F_125 ( struct V_204 * V_205 )
{
struct V_1 * V_7 = V_205 -> V_1 ;
unsigned int V_80 = V_205 -> V_186 ;
struct V_1 * V_183 ;
if ( ! V_7 )
return NULL ;
F_51 ( L_12 ,
V_205 -> V_1 , V_205 -> V_186 , V_205 -> V_206 ) ;
V_207:
while ( V_80 < ( 1 << V_7 -> V_9 ) ) {
struct V_2 * V_45 = F_12 ( V_7 , V_80 ) ;
if ( V_45 ) {
if ( F_38 ( V_45 ) ) {
V_205 -> V_1 = V_7 ;
V_205 -> V_186 = V_80 + 1 ;
} else {
V_205 -> V_1 = (struct V_1 * ) V_45 ;
V_205 -> V_186 = 0 ;
++ V_205 -> V_206 ;
}
return V_45 ;
}
++ V_80 ;
}
V_183 = F_4 ( (struct V_2 * ) V_7 ) ;
if ( V_183 ) {
V_80 = F_16 ( V_7 -> V_40 , V_183 -> V_18 , V_183 -> V_9 ) + 1 ;
V_7 = V_183 ;
-- V_205 -> V_206 ;
goto V_207;
}
return NULL ;
}
static struct V_2 * F_126 ( struct V_204 * V_205 ,
struct V_49 * V_50 )
{
struct V_2 * V_45 ;
if ( ! V_50 )
return NULL ;
V_45 = F_96 ( V_50 -> V_49 ) ;
if ( ! V_45 )
return NULL ;
if ( F_63 ( V_45 ) ) {
V_205 -> V_1 = (struct V_1 * ) V_45 ;
V_205 -> V_186 = 0 ;
V_205 -> V_206 = 1 ;
} else {
V_205 -> V_1 = NULL ;
V_205 -> V_186 = 0 ;
V_205 -> V_206 = 0 ;
}
return V_45 ;
}
static void F_127 ( struct V_49 * V_50 , struct V_208 * V_209 )
{
struct V_2 * V_45 ;
struct V_204 V_205 ;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
F_95 () ;
for ( V_45 = F_126 ( & V_205 , V_50 ) ; V_45 ; V_45 = F_125 ( & V_205 ) ) {
if ( F_38 ( V_45 ) ) {
struct V_25 * V_12 = (struct V_25 * ) V_45 ;
struct V_27 * V_37 ;
V_209 -> V_210 ++ ;
V_209 -> V_211 += V_205 . V_206 ;
if ( V_205 . V_206 > V_209 -> V_212 )
V_209 -> V_212 = V_205 . V_206 ;
F_65 ( V_37 , & V_12 -> V_35 , V_79 )
++ V_209 -> V_213 ;
} else {
const struct V_1 * V_7 = ( const struct V_1 * ) V_45 ;
int V_8 ;
V_209 -> V_214 ++ ;
if ( V_7 -> V_9 < V_215 )
V_209 -> V_216 [ V_7 -> V_9 ] ++ ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 -> V_9 ) ; V_8 ++ )
if ( ! V_7 -> V_10 [ V_8 ] )
V_209 -> V_217 ++ ;
}
}
F_98 () ;
}
static void F_128 ( struct V_218 * V_219 , struct V_208 * V_220 )
{
unsigned int V_8 , F_123 , V_221 , V_222 , V_223 ;
if ( V_220 -> V_210 )
V_223 = V_220 -> V_211 * 100 / V_220 -> V_210 ;
else
V_223 = 0 ;
F_129 ( V_219 , L_13 ,
V_223 / 100 , V_223 % 100 ) ;
F_129 ( V_219 , L_14 , V_220 -> V_212 ) ;
F_129 ( V_219 , L_15 , V_220 -> V_210 ) ;
V_222 = sizeof( struct V_25 ) * V_220 -> V_210 ;
F_129 ( V_219 , L_16 , V_220 -> V_213 ) ;
V_222 += sizeof( struct V_27 ) * V_220 -> V_213 ;
F_129 ( V_219 , L_17 , V_220 -> V_214 ) ;
V_222 += sizeof( struct V_1 ) * V_220 -> V_214 ;
F_123 = V_215 ;
while ( F_123 > 0 && V_220 -> V_216 [ F_123 - 1 ] == 0 )
F_123 -- ;
V_221 = 0 ;
for ( V_8 = 1 ; V_8 < F_123 ; V_8 ++ )
if ( V_220 -> V_216 [ V_8 ] != 0 ) {
F_129 ( V_219 , L_18 , V_8 , V_220 -> V_216 [ V_8 ] ) ;
V_221 += ( 1 << V_8 ) * V_220 -> V_216 [ V_8 ] ;
}
F_130 ( V_219 , '\n' ) ;
F_129 ( V_219 , L_19 , V_221 ) ;
V_222 += sizeof( struct V_2 * ) * V_221 ;
F_129 ( V_219 , L_20 , V_220 -> V_217 ) ;
F_129 ( V_219 , L_21 , ( V_222 + 1023 ) / 1024 ) ;
}
static void F_131 ( struct V_218 * V_219 ,
const struct V_224 * V_61 )
{
F_129 ( V_219 , L_22 ) ;
F_129 ( V_219 , L_23 , V_61 -> gets ) ;
F_129 ( V_219 , L_24 , V_61 -> V_169 ) ;
F_129 ( V_219 , L_25 ,
V_61 -> V_142 ) ;
F_129 ( V_219 , L_26 ,
V_61 -> V_156 ) ;
F_129 ( V_219 , L_27 , V_61 -> V_166 ) ;
F_129 ( V_219 , L_28 ,
V_61 -> V_62 ) ;
}
static void F_132 ( struct V_218 * V_219 , struct V_86 * V_87 )
{
if ( V_87 -> V_101 == V_225 )
F_133 ( V_219 , L_29 ) ;
else if ( V_87 -> V_101 == V_226 )
F_133 ( V_219 , L_30 ) ;
else
F_129 ( V_219 , L_31 , V_87 -> V_101 ) ;
}
static int F_134 ( struct V_218 * V_219 , void * V_227 )
{
struct V_228 * V_228 = (struct V_228 * ) V_219 -> V_229 ;
unsigned int V_230 ;
F_129 ( V_219 ,
L_32
L_33 ,
sizeof( struct V_25 ) , sizeof( struct V_1 ) ) ;
for ( V_230 = 0 ; V_230 < V_231 ; V_230 ++ ) {
struct V_75 * V_20 = & V_228 -> V_232 . V_233 [ V_230 ] ;
struct V_86 * V_87 ;
F_65 (tb, head, tb_hlist) {
struct V_49 * V_50 = (struct V_49 * ) V_87 -> V_90 ;
struct V_208 V_220 ;
if ( ! V_50 )
continue;
F_132 ( V_219 , V_87 ) ;
F_127 ( V_50 , & V_220 ) ;
F_128 ( V_219 , & V_220 ) ;
#ifdef F_59
F_131 ( V_219 , & V_50 -> V_61 ) ;
#endif
}
}
return 0 ;
}
static int F_135 ( struct V_67 * V_67 , struct V_234 * V_234 )
{
return F_136 ( V_67 , V_234 , F_134 ) ;
}
static struct V_2 * F_137 ( struct V_218 * V_219 , T_7 V_18 )
{
struct V_204 * V_205 = V_219 -> V_229 ;
struct V_228 * V_228 = F_138 ( V_219 ) ;
T_7 V_185 = 0 ;
unsigned int V_230 ;
for ( V_230 = 0 ; V_230 < V_231 ; V_230 ++ ) {
struct V_75 * V_20 = & V_228 -> V_232 . V_233 [ V_230 ] ;
struct V_86 * V_87 ;
F_65 (tb, head, tb_hlist) {
struct V_2 * V_45 ;
for ( V_45 = F_126 ( V_205 ,
(struct V_49 * ) V_87 -> V_90 ) ;
V_45 ; V_45 = F_125 ( V_205 ) )
if ( V_18 == V_185 ++ ) {
V_205 -> V_87 = V_87 ;
return V_45 ;
}
}
}
return NULL ;
}
static void * F_139 ( struct V_218 * V_219 , T_7 * V_18 )
__acquires( T_8 )
{
F_95 () ;
return F_137 ( V_219 , * V_18 ) ;
}
static void * F_140 ( struct V_218 * V_219 , void * V_227 , T_7 * V_18 )
{
struct V_204 * V_205 = V_219 -> V_229 ;
struct V_228 * V_228 = F_138 ( V_219 ) ;
struct V_86 * V_87 = V_205 -> V_87 ;
struct V_181 * V_235 ;
unsigned int V_230 ;
struct V_2 * V_45 ;
++ * V_18 ;
V_45 = F_125 ( V_205 ) ;
if ( V_45 )
return V_45 ;
V_230 = V_87 -> V_101 & ( V_231 - 1 ) ;
while ( ( V_235 = F_96 ( F_141 ( & V_87 -> V_236 ) ) ) ) {
V_87 = F_142 ( V_235 , struct V_86 , V_236 ) ;
V_45 = F_126 ( V_205 , (struct V_49 * ) V_87 -> V_90 ) ;
if ( V_45 )
goto V_165;
}
while ( ++ V_230 < V_231 ) {
struct V_75 * V_20 = & V_228 -> V_232 . V_233 [ V_230 ] ;
F_65 (tb, head, tb_hlist) {
V_45 = F_126 ( V_205 , (struct V_49 * ) V_87 -> V_90 ) ;
if ( V_45 )
goto V_165;
}
}
return NULL ;
V_165:
V_205 -> V_87 = V_87 ;
return V_45 ;
}
static void F_143 ( struct V_218 * V_219 , void * V_227 )
__releases( T_8 )
{
F_98 () ;
}
static void F_144 ( struct V_218 * V_219 , int V_45 )
{
while ( V_45 -- > 0 )
F_133 ( V_219 , L_34 ) ;
}
static inline const char * F_145 ( char * V_237 , T_2 V_199 , enum V_238 V_209 )
{
switch ( V_209 ) {
case V_239 : return L_35 ;
case V_240 : return L_36 ;
case V_241 : return L_37 ;
case V_242 : return L_38 ;
case V_173 : return L_39 ;
default:
snprintf ( V_237 , V_199 , L_40 , V_209 ) ;
return V_237 ;
}
}
static inline const char * F_146 ( char * V_237 , T_2 V_199 , unsigned int V_50 )
{
if ( V_50 < V_243 && V_244 [ V_50 ] )
return V_244 [ V_50 ] ;
snprintf ( V_237 , V_199 , L_41 , V_50 ) ;
return V_237 ;
}
static int F_147 ( struct V_218 * V_219 , void * V_227 )
{
const struct V_204 * V_205 = V_219 -> V_229 ;
struct V_2 * V_45 = V_227 ;
if ( ! F_4 ( V_45 ) )
F_132 ( V_219 , V_205 -> V_87 ) ;
if ( F_63 ( V_45 ) ) {
struct V_1 * V_7 = (struct V_1 * ) V_45 ;
T_5 V_245 = F_87 ( F_15 ( V_7 -> V_40 , V_7 -> V_18 ) ) ;
F_144 ( V_219 , V_205 -> V_206 - 1 ) ;
F_129 ( V_219 , L_42 ,
& V_245 , V_7 -> V_18 , V_7 -> V_9 , V_7 -> V_43 ,
V_7 -> V_44 ) ;
} else {
struct V_25 * V_12 = (struct V_25 * ) V_45 ;
struct V_27 * V_37 ;
T_5 V_246 = F_87 ( V_12 -> V_40 ) ;
F_144 ( V_219 , V_205 -> V_206 ) ;
F_129 ( V_219 , L_43 , & V_246 ) ;
F_65 (li, &l->list, hlist) {
struct V_21 * V_22 ;
F_91 (fa, &li->falh, fa_list) {
char V_247 [ 32 ] , V_248 [ 32 ] ;
F_144 ( V_219 , V_205 -> V_206 + 1 ) ;
F_129 ( V_219 , L_44 , V_37 -> V_36 ,
F_145 ( V_247 , sizeof( V_247 ) ,
V_22 -> V_104 -> V_139 ) ,
F_146 ( V_248 , sizeof( V_248 ) ,
V_22 -> V_113 ) ) ;
if ( V_22 -> V_103 )
F_129 ( V_219 , L_45 , V_22 -> V_103 ) ;
F_130 ( V_219 , '\n' ) ;
}
}
}
return 0 ;
}
static int F_148 ( struct V_67 * V_67 , struct V_234 * V_234 )
{
return F_149 ( V_67 , V_234 , & V_249 ,
sizeof( struct V_204 ) ) ;
}
static struct V_25 * F_150 ( struct V_250 * V_205 , T_7 V_18 )
{
struct V_25 * V_12 = NULL ;
struct V_49 * V_50 = V_205 -> V_251 ;
if ( V_205 -> V_18 > 0 && V_18 >= V_205 -> V_18 && ( V_12 = F_73 ( V_50 , V_205 -> V_40 ) ) )
V_18 -= V_205 -> V_18 ;
else {
V_205 -> V_18 = 0 ;
V_12 = F_111 ( V_50 ) ;
}
while ( V_12 && V_18 -- > 0 ) {
V_205 -> V_18 ++ ;
V_12 = F_112 ( V_12 ) ;
}
if ( V_12 )
V_205 -> V_40 = V_18 ;
else
V_205 -> V_18 = 0 ;
return V_12 ;
}
static void * F_151 ( struct V_218 * V_219 , T_7 * V_18 )
__acquires( T_8 )
{
struct V_250 * V_205 = V_219 -> V_229 ;
struct V_86 * V_87 ;
F_95 () ;
V_87 = F_152 ( F_138 ( V_219 ) , V_226 ) ;
if ( ! V_87 )
return NULL ;
V_205 -> V_251 = (struct V_49 * ) V_87 -> V_90 ;
if ( * V_18 == 0 )
return V_252 ;
else
return F_150 ( V_205 , * V_18 - 1 ) ;
}
static void * F_153 ( struct V_218 * V_219 , void * V_227 , T_7 * V_18 )
{
struct V_250 * V_205 = V_219 -> V_229 ;
struct V_25 * V_12 = V_227 ;
++ * V_18 ;
if ( V_227 == V_252 ) {
V_205 -> V_18 = 0 ;
V_12 = F_111 ( V_205 -> V_251 ) ;
} else {
V_205 -> V_18 ++ ;
V_12 = F_112 ( V_12 ) ;
}
if ( V_12 )
V_205 -> V_40 = V_12 -> V_40 ;
else
V_205 -> V_18 = 0 ;
return V_12 ;
}
static void F_154 ( struct V_218 * V_219 , void * V_227 )
__releases( T_8 )
{
F_98 () ;
}
static unsigned int F_155 ( int type , T_5 V_97 , const struct V_92 * V_93 )
{
unsigned int V_253 = 0 ;
if ( type == V_254 || type == V_255 )
V_253 = V_256 ;
if ( V_93 && V_93 -> V_145 -> V_257 )
V_253 |= V_258 ;
if ( V_97 == F_87 ( 0xFFFFFFFF ) )
V_253 |= V_259 ;
V_253 |= V_260 ;
return V_253 ;
}
static int F_156 ( struct V_218 * V_219 , void * V_227 )
{
struct V_25 * V_12 = V_227 ;
struct V_27 * V_37 ;
if ( V_227 == V_252 ) {
F_129 ( V_219 , L_46 , L_47
L_48
L_49 ) ;
return 0 ;
}
F_65 (li, &l->list, hlist) {
struct V_21 * V_22 ;
T_5 V_97 , V_261 ;
V_97 = F_48 ( V_37 -> V_36 ) ;
V_261 = F_87 ( V_12 -> V_40 ) ;
F_91 (fa, &li->falh, fa_list) {
const struct V_92 * V_93 = V_22 -> V_104 ;
unsigned int V_253 = F_155 ( V_22 -> V_113 , V_97 , V_93 ) ;
if ( V_22 -> V_113 == V_262
|| V_22 -> V_113 == V_263 )
continue;
F_157 ( V_219 , 127 ) ;
if ( V_93 )
F_129 ( V_219 ,
L_50
L_51 ,
V_93 -> V_264 ? V_93 -> V_264 -> V_265 : L_52 ,
V_261 ,
V_93 -> V_145 -> V_257 , V_253 , 0 , 0 ,
V_93 -> V_102 ,
V_97 ,
( V_93 -> V_266 ?
V_93 -> V_266 + 40 : 0 ) ,
V_93 -> V_267 ,
V_93 -> V_268 >> 3 ) ;
else
F_129 ( V_219 ,
L_53
L_51 ,
V_261 , 0 , V_253 , 0 , 0 , 0 ,
V_97 , 0 , 0 , 0 ) ;
F_158 ( V_219 , '\n' ) ;
}
}
return 0 ;
}
static int F_159 ( struct V_67 * V_67 , struct V_234 * V_234 )
{
return F_149 ( V_67 , V_234 , & V_269 ,
sizeof( struct V_250 ) ) ;
}
int T_9 F_160 ( struct V_228 * V_228 )
{
if ( ! F_161 ( L_54 , V_270 , V_228 -> V_271 , & V_272 ) )
goto V_273;
if ( ! F_161 ( L_55 , V_270 , V_228 -> V_271 ,
& V_274 ) )
goto V_275;
if ( ! F_161 ( L_56 , V_270 , V_228 -> V_271 , & V_276 ) )
goto V_277;
return 0 ;
V_277:
F_162 ( L_55 , V_228 -> V_271 ) ;
V_275:
F_162 ( L_54 , V_228 -> V_271 ) ;
V_273:
return - V_66 ;
}
void T_10 F_163 ( struct V_228 * V_228 )
{
F_162 ( L_54 , V_228 -> V_271 ) ;
F_162 ( L_55 , V_228 -> V_271 ) ;
F_162 ( L_56 , V_228 -> V_271 ) ;
}
