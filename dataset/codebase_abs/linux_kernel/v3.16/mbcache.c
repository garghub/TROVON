static inline void
F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_3 ,
F_4 ( V_2 ) ) ) ;
}
static inline void
F_5 ( struct V_1 * V_2 )
{
F_6 ( F_3 ( V_3 ,
F_4 ( V_2 ) ) ) ;
}
static inline int
F_7 ( struct V_1 * V_2 )
{
return ! F_8 ( & V_2 -> V_4 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) )
F_10 ( & V_2 -> V_4 ) ;
}
static inline int
F_11 ( struct V_1 * V_2 )
{
return ! F_8 ( & V_2 -> V_5 . V_6 ) ;
}
static inline void
F_12 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
F_10 ( & V_2 -> V_5 . V_6 ) ;
}
static inline void
F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_7 ) ;
F_9 ( V_2 ) ;
F_14 ( V_2 -> V_8 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
F_16 ( ! ( V_2 -> V_13 || V_2 -> V_14 || F_17 ( & V_2 -> V_15 ) ) ) ;
F_18 ( V_11 -> V_16 , V_2 ) ;
F_19 ( & V_11 -> V_17 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_14 )
F_21 ( & V_18 ) ;
if ( V_2 -> V_13 >= V_19 )
V_2 -> V_13 -= V_19 ;
V_2 -> V_13 -- ;
if ( ! ( V_2 -> V_13 || V_2 -> V_14 || F_17 ( & V_2 -> V_15 ) ) ) {
if ( ! F_7 ( V_2 ) ) {
F_5 ( V_2 ) ;
goto V_20;
}
F_2 ( & V_21 ) ;
if ( F_22 ( & V_2 -> V_22 ) )
F_23 ( & V_2 -> V_22 , & V_23 ) ;
F_6 ( & V_21 ) ;
}
F_5 ( V_2 ) ;
return;
V_20:
F_16 ( F_22 ( & V_2 -> V_22 ) ) ;
F_15 ( V_2 , V_24 ) ;
}
static unsigned long
F_24 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
F_25 ( V_29 ) ;
struct V_1 * V_30 , * V_31 ;
int V_32 = V_28 -> V_32 ;
T_1 V_9 = V_28 -> V_9 ;
unsigned long V_33 = 0 ;
F_26 ( L_1 , V_32 ) ;
F_2 ( & V_21 ) ;
while ( ( V_32 -- > 0 ) && ! F_22 ( & V_23 ) ) {
struct V_1 * V_2 =
F_27 ( V_23 . V_34 ,
struct V_1 , V_22 ) ;
F_28 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_13 || V_2 -> V_14 || F_17 ( & V_2 -> V_15 ) )
continue;
F_6 ( & V_21 ) ;
F_29 ( V_2 -> V_8 ) ;
F_29 ( V_2 -> V_7 ) ;
if ( V_2 -> V_13 || V_2 -> V_14 || F_17 ( & V_2 -> V_15 ) ||
! F_22 ( & V_2 -> V_22 ) ) {
F_14 ( V_2 -> V_7 ) ;
F_14 ( V_2 -> V_8 ) ;
F_2 ( & V_21 ) ;
continue;
}
F_13 ( V_2 ) ;
F_23 ( & V_2 -> V_22 , & V_29 ) ;
F_2 ( & V_21 ) ;
}
F_6 ( & V_21 ) ;
F_30 (entry, tmp, &free_list, e_lru_list) {
F_15 ( V_30 , V_9 ) ;
V_33 ++ ;
}
return V_33 ;
}
static unsigned long
F_31 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
struct V_10 * V_11 ;
unsigned long V_35 = 0 ;
F_2 ( & V_21 ) ;
F_32 (cache, &mb_cache_list, c_cache_list) {
F_26 ( L_2 , V_11 -> V_36 ,
F_17 ( & V_11 -> V_17 ) ) ;
V_35 += F_17 ( & V_11 -> V_17 ) ;
}
F_6 ( & V_21 ) ;
return F_33 ( V_35 ) ;
}
struct V_10 *
F_34 ( const char * V_37 , int V_38 )
{
int V_39 , V_40 = 1 << V_38 ;
struct V_10 * V_11 = NULL ;
if ( ! V_3 ) {
V_3 = F_35 ( sizeof( struct V_41 ) ,
V_24 ) ;
if ( ! V_3 )
return NULL ;
F_36 ( V_3 ) ;
}
V_11 = F_35 ( sizeof( struct V_10 ) , V_24 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_36 = V_37 ;
F_37 ( & V_11 -> V_17 , 0 ) ;
V_11 -> V_42 = V_38 ;
V_11 -> V_43 = F_35 ( V_40 *
sizeof( struct V_44 ) , V_24 ) ;
if ( ! V_11 -> V_43 )
goto V_45;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_38 ( & V_11 -> V_43 [ V_39 ] ) ;
V_11 -> V_46 = F_35 ( V_40 *
sizeof( struct V_44 ) , V_24 ) ;
if ( ! V_11 -> V_46 )
goto V_45;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_38 ( & V_11 -> V_46 [ V_39 ] ) ;
if ( ! V_47 ) {
V_47 = F_39 ( V_37 ,
sizeof( struct V_1 ) , 0 ,
V_48 | V_49 , NULL ) ;
if ( ! V_47 )
goto V_50;
}
V_11 -> V_16 = V_47 ;
V_11 -> V_51 = V_40 << 4 ;
F_2 ( & V_21 ) ;
F_40 ( & V_11 -> V_52 , & V_53 ) ;
F_6 ( & V_21 ) ;
return V_11 ;
V_50:
F_41 ( V_11 -> V_46 ) ;
V_45:
F_41 ( V_11 -> V_43 ) ;
F_41 ( V_11 ) ;
return NULL ;
}
void
F_42 ( struct V_54 * V_55 )
{
F_25 ( V_29 ) ;
struct V_56 * V_57 ;
struct V_1 * V_2 , * V_31 ;
V_57 = & V_23 ;
F_2 ( & V_21 ) ;
while ( ! F_43 ( V_57 , & V_23 ) ) {
V_57 = V_57 -> V_34 ;
V_2 = F_27 ( V_57 , struct V_1 , V_22 ) ;
if ( V_2 -> V_58 == V_55 ) {
F_28 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) )
continue;
F_6 ( & V_21 ) ;
F_29 ( V_2 -> V_8 ) ;
F_29 ( V_2 -> V_7 ) ;
if ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) ||
! F_22 ( & V_2 -> V_22 ) ) {
F_14 ( V_2 -> V_7 ) ;
F_14 ( V_2 -> V_8 ) ;
V_57 = & V_23 ;
F_2 ( & V_21 ) ;
continue;
}
F_13 ( V_2 ) ;
F_16 ( ! ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) ) ) ;
F_23 ( & V_2 -> V_22 , & V_29 ) ;
V_57 = & V_23 ;
F_2 ( & V_21 ) ;
}
}
F_6 ( & V_21 ) ;
F_30 (ce, tmp, &free_list, e_lru_list) {
F_15 ( V_2 , V_24 ) ;
}
}
void
F_44 ( struct V_10 * V_11 )
{
F_25 ( V_29 ) ;
struct V_1 * V_2 , * V_31 ;
F_2 ( & V_21 ) ;
F_30 (ce, tmp, &mb_cache_lru_list, e_lru_list) {
if ( V_2 -> V_12 == V_11 )
F_45 ( & V_2 -> V_22 , & V_29 ) ;
}
F_46 ( & V_11 -> V_52 ) ;
F_6 ( & V_21 ) ;
F_30 (ce, tmp, &free_list, e_lru_list) {
F_28 ( & V_2 -> V_22 ) ;
F_29 ( V_2 -> V_8 ) ;
F_29 ( V_2 -> V_7 ) ;
F_16 ( ! ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) ) ) ;
F_13 ( V_2 ) ;
F_15 ( V_2 , V_24 ) ;
}
if ( F_17 ( & V_11 -> V_17 ) > 0 ) {
F_47 ( L_3 ,
V_11 -> V_36 ,
F_17 ( & V_11 -> V_17 ) ) ;
}
if ( F_22 ( & V_53 ) ) {
F_48 ( V_47 ) ;
V_47 = NULL ;
}
F_41 ( V_11 -> V_46 ) ;
F_41 ( V_11 -> V_43 ) ;
F_41 ( V_11 ) ;
}
struct V_1 *
F_49 ( struct V_10 * V_11 , T_1 V_59 )
{
struct V_1 * V_2 ;
if ( F_17 ( & V_11 -> V_17 ) >= V_11 -> V_51 ) {
struct V_56 * V_57 ;
V_57 = & V_23 ;
F_2 ( & V_21 ) ;
while ( ! F_43 ( V_57 , & V_23 ) ) {
V_57 = V_57 -> V_34 ;
V_2 = F_27 ( V_57 , struct V_1 , V_22 ) ;
if ( V_2 -> V_12 == V_11 ) {
F_28 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) )
continue;
F_6 ( & V_21 ) ;
F_29 ( V_2 -> V_8 ) ;
F_29 ( V_2 -> V_7 ) ;
if ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) ||
! F_22 ( & V_2 -> V_22 ) ) {
F_14 ( V_2 -> V_7 ) ;
F_14 ( V_2 -> V_8 ) ;
V_57 = & V_23 ;
F_2 ( & V_21 ) ;
continue;
}
F_16 ( F_22 ( & V_2 -> V_22 ) ) ;
F_16 ( ! ( V_2 -> V_13 || V_2 -> V_14 ||
F_17 ( & V_2 -> V_15 ) ) ) ;
F_13 ( V_2 ) ;
goto V_60;
}
}
F_6 ( & V_21 ) ;
}
V_2 = F_50 ( V_11 -> V_16 , V_59 ) ;
if ( ! V_2 )
return NULL ;
F_51 ( & V_11 -> V_17 ) ;
F_52 ( & V_2 -> V_22 ) ;
F_53 ( & V_2 -> V_4 ) ;
F_53 ( & V_2 -> V_5 . V_6 ) ;
V_2 -> V_12 = V_11 ;
V_2 -> V_14 = 0 ;
F_37 ( & V_2 -> V_15 , 0 ) ;
V_60:
V_2 -> V_8 = & V_11 -> V_43 [ 0 ] ;
V_2 -> V_7 = & V_11 -> V_46 [ 0 ] ;
V_2 -> V_13 = 1 + V_19 ;
return V_2 ;
}
int
F_54 ( struct V_1 * V_2 , struct V_54 * V_55 ,
T_2 V_61 , unsigned int V_62 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_63 ;
struct V_64 * V_57 ;
struct V_44 * V_65 ;
struct V_44 * V_66 ;
struct V_1 * V_67 ;
F_16 ( V_2 ) ;
V_63 = F_55 ( ( unsigned long ) V_55 + ( V_61 & 0xffffffff ) ,
V_11 -> V_42 ) ;
V_65 = & V_11 -> V_43 [ V_63 ] ;
F_29 ( V_65 ) ;
F_56 (lce, l, block_hash_p, e_block_list) {
if ( V_67 -> V_58 == V_55 && V_67 -> V_68 == V_61 ) {
F_14 ( V_65 ) ;
return - V_69 ;
}
}
F_16 ( ! F_7 ( V_2 ) ) ;
F_9 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_58 = V_55 ;
V_2 -> V_68 = V_61 ;
V_2 -> V_8 = V_65 ;
V_2 -> V_5 . V_70 = V_62 ;
F_57 ( & V_2 -> V_4 , V_65 ) ;
F_14 ( V_65 ) ;
V_63 = F_55 ( V_62 , V_11 -> V_42 ) ;
V_66 = & V_11 -> V_46 [ V_63 ] ;
F_29 ( V_66 ) ;
V_2 -> V_7 = V_66 ;
F_57 ( & V_2 -> V_5 . V_6 , V_66 ) ;
F_14 ( V_66 ) ;
return 0 ;
}
void
F_58 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
void
F_59 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_16 ( F_22 ( & V_2 -> V_22 ) ) ;
F_29 ( V_2 -> V_7 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_7 ) ;
F_29 ( V_2 -> V_8 ) ;
F_9 ( V_2 ) ;
F_14 ( V_2 -> V_8 ) ;
F_20 ( V_2 ) ;
}
struct V_1 *
F_60 ( struct V_10 * V_11 , struct V_54 * V_55 ,
T_2 V_61 )
{
unsigned int V_63 ;
struct V_64 * V_57 ;
struct V_1 * V_2 ;
struct V_44 * V_65 ;
V_63 = F_55 ( ( unsigned long ) V_55 + ( V_61 & 0xffffffff ) ,
V_11 -> V_42 ) ;
V_65 = & V_11 -> V_43 [ V_63 ] ;
F_29 ( V_65 ) ;
F_56 (ce, l, block_hash_p, e_block_list) {
F_16 ( V_2 -> V_8 == V_65 ) ;
if ( V_2 -> V_58 == V_55 && V_2 -> V_68 == V_61 ) {
F_51 ( & V_2 -> V_15 ) ;
F_14 ( V_65 ) ;
F_1 ( V_2 ) ;
F_19 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_13 > 0 ) {
F_61 ( V_71 ) ;
while ( V_2 -> V_13 > 0 ) {
V_2 -> V_14 ++ ;
F_62 ( & V_18 , & V_71 ,
V_72 ) ;
F_5 ( V_2 ) ;
F_63 () ;
F_1 ( V_2 ) ;
V_2 -> V_14 -- ;
}
F_64 ( & V_18 , & V_71 ) ;
}
V_2 -> V_13 += 1 + V_19 ;
F_5 ( V_2 ) ;
if ( ! F_22 ( & V_2 -> V_22 ) ) {
F_2 ( & V_21 ) ;
F_28 ( & V_2 -> V_22 ) ;
F_6 ( & V_21 ) ;
}
if ( ! F_7 ( V_2 ) ) {
F_20 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
}
F_14 ( V_65 ) ;
return NULL ;
}
static struct V_1 *
F_65 ( struct V_64 * V_57 , struct V_44 * V_73 ,
struct V_54 * V_55 , unsigned int V_62 )
{
while ( V_57 != NULL ) {
struct V_1 * V_2 =
F_66 ( V_57 , struct V_1 ,
V_5 . V_6 ) ;
F_16 ( V_2 -> V_7 == V_73 ) ;
if ( V_2 -> V_58 == V_55 && V_2 -> V_5 . V_70 == V_62 ) {
F_51 ( & V_2 -> V_15 ) ;
F_14 ( V_73 ) ;
F_1 ( V_2 ) ;
F_19 ( & V_2 -> V_15 ) ;
V_2 -> V_13 ++ ;
if ( V_2 -> V_13 >= V_19 ) {
F_61 ( V_71 ) ;
while ( V_2 -> V_13 >= V_19 ) {
V_2 -> V_14 ++ ;
F_62 ( & V_18 , & V_71 ,
V_72 ) ;
F_5 ( V_2 ) ;
F_63 () ;
F_1 ( V_2 ) ;
V_2 -> V_14 -- ;
}
F_64 ( & V_18 , & V_71 ) ;
}
F_5 ( V_2 ) ;
if ( ! F_22 ( & V_2 -> V_22 ) ) {
F_2 ( & V_21 ) ;
F_28 ( & V_2 -> V_22 ) ;
F_6 ( & V_21 ) ;
}
if ( ! F_7 ( V_2 ) ) {
F_20 ( V_2 ) ;
return F_67 ( - V_74 ) ;
}
return V_2 ;
}
V_57 = V_57 -> V_34 ;
}
F_14 ( V_73 ) ;
return NULL ;
}
struct V_1 *
F_68 ( struct V_10 * V_11 , struct V_54 * V_55 ,
unsigned int V_62 )
{
unsigned int V_63 = F_55 ( V_62 , V_11 -> V_42 ) ;
struct V_64 * V_57 ;
struct V_1 * V_2 = NULL ;
struct V_44 * V_66 ;
V_66 = & V_11 -> V_46 [ V_63 ] ;
F_29 ( V_66 ) ;
if ( ! F_69 ( V_66 ) ) {
V_57 = F_70 ( V_66 ) ;
V_2 = F_65 ( V_57 , V_66 , V_55 , V_62 ) ;
} else
F_14 ( V_66 ) ;
return V_2 ;
}
struct V_1 *
F_71 ( struct V_1 * V_75 ,
struct V_54 * V_55 , unsigned int V_62 )
{
struct V_10 * V_11 = V_75 -> V_12 ;
unsigned int V_63 = F_55 ( V_62 , V_11 -> V_42 ) ;
struct V_64 * V_57 ;
struct V_1 * V_2 ;
struct V_44 * V_66 ;
V_66 = & V_11 -> V_46 [ V_63 ] ;
F_16 ( V_75 -> V_7 == V_66 ) ;
F_29 ( V_66 ) ;
F_16 ( ! F_69 ( V_66 ) ) ;
V_57 = V_75 -> V_5 . V_6 . V_34 ;
V_2 = F_65 ( V_57 , V_66 , V_55 , V_62 ) ;
F_20 ( V_75 ) ;
return V_2 ;
}
static int T_3 F_72 ( void )
{
F_73 ( & V_76 ) ;
return 0 ;
}
static void T_4 F_74 ( void )
{
F_75 ( & V_76 ) ;
}
