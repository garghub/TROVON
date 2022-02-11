static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 + 1 ;
}
static int F_2 ( unsigned long * V_5 , unsigned long V_6 )
{
unsigned long V_7 , V_8 ;
V_8 = * V_5 ;
do {
V_7 = V_8 ;
if ( V_7 & V_6 )
return - V_9 ;
F_3 () ;
} while ( ( V_8 = F_4 ( V_5 , V_7 , V_7 | V_6 ) ) != V_7 );
return 0 ;
}
static int F_5 ( unsigned long * V_5 , unsigned long V_10 )
{
unsigned long V_7 , V_8 ;
V_8 = * V_5 ;
do {
V_7 = V_8 ;
if ( ( V_7 & V_10 ) != V_10 )
return - V_9 ;
F_3 () ;
} while ( ( V_8 = F_4 ( V_5 , V_7 , V_7 & ~ V_10 ) ) != V_7 );
return 0 ;
}
static int F_6 ( unsigned long * V_11 , int V_12 , int V_13 )
{
unsigned long * V_14 = V_11 + F_7 ( V_12 ) ;
const int V_15 = V_12 + V_13 ;
int V_16 = V_17 - ( V_12 % V_17 ) ;
unsigned long V_6 = F_8 ( V_12 ) ;
while ( V_13 - V_16 >= 0 ) {
if ( F_2 ( V_14 , V_6 ) )
return V_13 ;
V_13 -= V_16 ;
V_16 = V_17 ;
V_6 = ~ 0UL ;
V_14 ++ ;
}
if ( V_13 ) {
V_6 &= F_9 ( V_15 ) ;
if ( F_2 ( V_14 , V_6 ) )
return V_13 ;
}
return 0 ;
}
static int F_10 ( unsigned long * V_11 , int V_12 , int V_13 )
{
unsigned long * V_14 = V_11 + F_7 ( V_12 ) ;
const int V_15 = V_12 + V_13 ;
int V_18 = V_17 - ( V_12 % V_17 ) ;
unsigned long V_10 = F_8 ( V_12 ) ;
while ( V_13 - V_18 >= 0 ) {
if ( F_5 ( V_14 , V_10 ) )
return V_13 ;
V_13 -= V_18 ;
V_18 = V_17 ;
V_10 = ~ 0UL ;
V_14 ++ ;
}
if ( V_13 ) {
V_10 &= F_9 ( V_15 ) ;
if ( F_5 ( V_14 , V_10 ) )
return V_13 ;
}
return 0 ;
}
struct V_19 * F_11 ( int V_20 , int V_21 )
{
struct V_19 * V_22 ;
V_22 = F_12 ( sizeof( struct V_19 ) , V_23 , V_21 ) ;
if ( V_22 != NULL ) {
F_13 ( & V_22 -> V_24 ) ;
F_14 ( & V_22 -> V_25 ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_26 = V_27 ;
V_22 -> V_28 = NULL ;
V_22 -> V_29 = NULL ;
}
return V_22 ;
}
int F_15 ( struct V_19 * V_22 , unsigned long V_30 , T_2 V_31 ,
T_1 V_15 , int V_21 )
{
struct V_1 * V_2 ;
int V_32 = V_15 >> V_22 -> V_20 ;
int V_33 = sizeof( struct V_1 ) +
F_16 ( V_32 ) * sizeof( long ) ;
V_2 = F_17 ( V_33 , V_23 , V_21 ) ;
if ( F_18 ( V_2 == NULL ) )
return - V_34 ;
V_2 -> V_35 = V_31 ;
V_2 -> V_4 = V_30 ;
V_2 -> V_3 = V_30 + V_15 - 1 ;
F_19 ( & V_2 -> V_36 , V_15 ) ;
F_20 ( & V_22 -> V_24 ) ;
F_21 ( & V_2 -> V_37 , & V_22 -> V_25 ) ;
F_22 ( & V_22 -> V_24 ) ;
return 0 ;
}
T_2 F_23 ( struct V_19 * V_22 , unsigned long V_5 )
{
struct V_1 * V_2 ;
T_2 V_38 = - 1 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk) {
if ( V_5 >= V_2 -> V_4 && V_5 <= V_2 -> V_3 ) {
V_38 = V_2 -> V_35 + ( V_5 - V_2 -> V_4 ) ;
break;
}
}
F_26 () ;
return V_38 ;
}
void F_27 ( struct V_19 * V_22 )
{
struct V_39 * V_40 , * V_41 ;
struct V_1 * V_2 ;
int V_42 = V_22 -> V_20 ;
int V_43 , V_44 ;
F_28 (_chunk, _next_chunk, &pool->chunks) {
V_2 = F_29 ( V_40 , struct V_1 , V_37 ) ;
F_30 ( & V_2 -> V_37 ) ;
V_44 = F_1 ( V_2 ) >> V_42 ;
V_43 = F_31 ( V_2 -> V_45 , V_44 , 0 ) ;
F_32 ( V_43 < V_44 ) ;
F_33 ( V_2 ) ;
}
F_34 ( V_22 -> V_29 ) ;
F_33 ( V_22 ) ;
}
unsigned long F_35 ( struct V_19 * V_22 , T_1 V_15 )
{
return F_36 ( V_22 , V_15 , V_22 -> V_26 , V_22 -> V_28 ) ;
}
unsigned long F_36 ( struct V_19 * V_22 , T_1 V_15 ,
T_3 V_26 , void * V_28 )
{
struct V_1 * V_2 ;
unsigned long V_5 = 0 ;
int V_42 = V_22 -> V_20 ;
int V_32 , V_46 = 0 , V_44 , V_47 ;
#ifndef F_37
F_32 ( F_38 () ) ;
#endif
if ( V_15 == 0 )
return 0 ;
V_32 = ( V_15 + ( 1UL << V_42 ) - 1 ) >> V_42 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk) {
if ( V_15 > F_39 ( & V_2 -> V_36 ) )
continue;
V_44 = F_1 ( V_2 ) >> V_42 ;
V_48:
V_46 = V_26 ( V_2 -> V_45 , V_44 , V_46 ,
V_32 , V_28 , V_22 ) ;
if ( V_46 >= V_44 )
continue;
V_47 = F_6 ( V_2 -> V_45 , V_46 , V_32 ) ;
if ( V_47 ) {
V_47 = F_10 ( V_2 -> V_45 , V_46 ,
V_32 - V_47 ) ;
F_32 ( V_47 ) ;
goto V_48;
}
V_5 = V_2 -> V_4 + ( ( unsigned long ) V_46 << V_42 ) ;
V_15 = V_32 << V_42 ;
F_40 ( V_15 , & V_2 -> V_36 ) ;
break;
}
F_26 () ;
return V_5 ;
}
void * F_41 ( struct V_19 * V_22 , T_1 V_15 , T_4 * V_49 )
{
unsigned long V_50 ;
if ( ! V_22 )
return NULL ;
V_50 = F_35 ( V_22 , V_15 ) ;
if ( ! V_50 )
return NULL ;
if ( V_49 )
* V_49 = F_23 ( V_22 , V_50 ) ;
return ( void * ) V_50 ;
}
void F_42 ( struct V_19 * V_22 , unsigned long V_5 , T_1 V_15 )
{
struct V_1 * V_2 ;
int V_42 = V_22 -> V_20 ;
int V_46 , V_32 , V_47 ;
#ifndef F_37
F_32 ( F_38 () ) ;
#endif
V_32 = ( V_15 + ( 1UL << V_42 ) - 1 ) >> V_42 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk) {
if ( V_5 >= V_2 -> V_4 && V_5 <= V_2 -> V_3 ) {
F_32 ( V_5 + V_15 - 1 > V_2 -> V_3 ) ;
V_46 = ( V_5 - V_2 -> V_4 ) >> V_42 ;
V_47 = F_10 ( V_2 -> V_45 , V_46 , V_32 ) ;
F_32 ( V_47 ) ;
V_15 = V_32 << V_42 ;
F_43 ( V_15 , & V_2 -> V_36 ) ;
F_26 () ;
return;
}
}
F_26 () ;
F_44 () ;
}
void F_45 ( struct V_19 * V_22 ,
void (* F_46)( struct V_19 * V_22 , struct V_1 * V_2 , void * V_28 ) ,
void * V_28 )
{
struct V_1 * V_2 ;
F_24 () ;
F_25 (chunk, &(pool)->chunks, next_chunk)
F_46 ( V_22 , V_2 , V_28 ) ;
F_26 () ;
}
bool F_47 ( struct V_19 * V_22 , unsigned long V_12 ,
T_1 V_15 )
{
bool V_51 = false ;
unsigned long V_52 = V_12 + V_15 - 1 ;
struct V_1 * V_2 ;
F_24 () ;
F_25 (chunk, &(pool)->chunks, next_chunk) {
if ( V_12 >= V_2 -> V_4 && V_12 <= V_2 -> V_3 ) {
if ( V_52 <= V_2 -> V_3 ) {
V_51 = true ;
break;
}
}
}
F_26 () ;
return V_51 ;
}
T_1 F_48 ( struct V_19 * V_22 )
{
struct V_1 * V_2 ;
T_1 V_36 = 0 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk)
V_36 += F_39 ( & V_2 -> V_36 ) ;
F_26 () ;
return V_36 ;
}
T_1 F_49 ( struct V_19 * V_22 )
{
struct V_1 * V_2 ;
T_1 V_15 = 0 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk)
V_15 += F_1 ( V_2 ) ;
F_26 () ;
return V_15 ;
}
void F_50 ( struct V_19 * V_22 , T_3 V_26 , void * V_28 )
{
F_24 () ;
V_22 -> V_26 = V_26 ;
if ( ! V_22 -> V_26 )
V_22 -> V_26 = V_27 ;
V_22 -> V_28 = V_28 ;
F_26 () ;
}
unsigned long V_27 ( unsigned long * V_11 , unsigned long V_15 ,
unsigned long V_12 , unsigned int V_13 , void * V_28 ,
struct V_19 * V_22 )
{
return F_51 ( V_11 , V_15 , V_12 , V_13 , 0 ) ;
}
unsigned long F_52 ( unsigned long * V_11 , unsigned long V_15 ,
unsigned long V_12 , unsigned int V_13 , void * V_28 ,
struct V_19 * V_22 )
{
struct V_53 * V_54 ;
unsigned long V_55 ;
int V_42 ;
V_54 = V_28 ;
V_42 = V_22 -> V_20 ;
V_55 = ( ( V_54 -> V_56 + ( 1UL << V_42 ) - 1 ) >> V_42 ) - 1 ;
return F_51 ( V_11 , V_15 , V_12 , V_13 , V_55 ) ;
}
unsigned long F_53 ( unsigned long * V_11 , unsigned long V_15 ,
unsigned long V_12 , unsigned int V_13 , void * V_28 ,
struct V_19 * V_22 )
{
struct V_57 * V_58 ;
int V_42 ;
unsigned long V_59 ;
unsigned long V_46 ;
V_58 = V_28 ;
V_42 = V_22 -> V_20 ;
V_59 = V_58 -> V_60 >> V_42 ;
if ( F_54 ( V_58 -> V_60 & ( ( 1UL << V_42 ) - 1 ) ) )
return V_15 ;
V_46 = F_51 ( V_11 , V_15 ,
V_12 + V_59 , V_13 , 0 ) ;
if ( V_46 != V_59 )
V_46 = V_15 ;
return V_46 ;
}
unsigned long F_55 ( unsigned long * V_11 ,
unsigned long V_15 , unsigned long V_12 ,
unsigned int V_13 , void * V_28 , struct V_19 * V_22 )
{
unsigned long V_55 = F_56 ( V_13 ) - 1 ;
return F_51 ( V_11 , V_15 , V_12 , V_13 , V_55 ) ;
}
unsigned long F_57 ( unsigned long * V_11 , unsigned long V_15 ,
unsigned long V_12 , unsigned int V_13 , void * V_28 ,
struct V_19 * V_22 )
{
unsigned long V_46 = V_15 ;
unsigned long V_61 = V_15 + 1 ;
unsigned long V_62 ;
V_62 = F_51 ( V_11 , V_15 , V_12 , V_13 , 0 ) ;
while ( V_62 < V_15 ) {
int V_63 = F_31 ( V_11 , V_15 , V_62 + V_13 ) ;
if ( ( V_63 - V_62 ) < V_61 ) {
V_61 = V_63 - V_62 ;
V_46 = V_62 ;
if ( V_61 == V_13 )
return V_46 ;
}
V_62 = F_51 ( V_11 , V_15 ,
V_63 + 1 , V_13 , 0 ) ;
}
return V_46 ;
}
static void F_58 ( struct V_64 * V_65 , void * V_66 )
{
F_27 ( * (struct V_19 * * ) V_66 ) ;
}
static int F_59 ( struct V_64 * V_65 , void * V_66 , void * V_28 )
{
struct V_19 * * V_14 = V_66 ;
if ( ! V_28 && ! ( * V_14 ) -> V_29 )
return 1 ;
if ( ! V_28 || ! ( * V_14 ) -> V_29 )
return 0 ;
return ! strcmp ( ( * V_14 ) -> V_29 , V_28 ) ;
}
struct V_19 * F_60 ( struct V_64 * V_65 , const char * V_29 )
{
struct V_19 * * V_14 ;
V_14 = F_61 ( V_65 , F_58 , F_59 ,
( void * ) V_29 ) ;
if ( ! V_14 )
return NULL ;
return * V_14 ;
}
struct V_19 * F_62 ( struct V_64 * V_65 , int V_20 ,
int V_21 , const char * V_29 )
{
struct V_19 * * V_67 , * V_22 ;
const char * V_68 = NULL ;
if ( F_60 ( V_65 , V_29 ) )
return F_63 ( - V_69 ) ;
if ( V_29 ) {
V_68 = F_64 ( V_29 , V_23 ) ;
if ( ! V_68 )
return F_63 ( - V_34 ) ;
}
V_67 = F_65 ( F_58 , sizeof( * V_67 ) , V_23 ) ;
if ( ! V_67 )
goto V_70;
V_22 = F_11 ( V_20 , V_21 ) ;
if ( ! V_22 )
goto V_71;
* V_67 = V_22 ;
V_22 -> V_29 = V_68 ;
F_66 ( V_65 , V_67 ) ;
return V_22 ;
V_71:
F_67 ( V_67 ) ;
V_70:
F_34 ( V_68 ) ;
return F_63 ( - V_34 ) ;
}
struct V_19 * F_68 ( struct V_72 * V_73 ,
const char * V_74 , int V_62 )
{
struct V_75 * V_76 ;
struct V_72 * V_77 , * V_78 ;
const char * V_29 = NULL ;
struct V_19 * V_22 = NULL ;
V_77 = F_69 ( V_73 , V_74 , V_62 ) ;
if ( ! V_77 )
return NULL ;
V_76 = F_70 ( V_77 ) ;
if ( ! V_76 ) {
V_78 = F_71 ( V_77 ) ;
V_76 = F_70 ( V_78 ) ;
F_72 ( V_78 ) ;
F_73 ( V_77 , L_1 , & V_29 ) ;
if ( ! V_29 )
V_29 = V_77 -> V_29 ;
}
if ( V_76 )
V_22 = F_60 ( & V_76 -> V_65 , V_29 ) ;
F_72 ( V_77 ) ;
return V_22 ;
}
