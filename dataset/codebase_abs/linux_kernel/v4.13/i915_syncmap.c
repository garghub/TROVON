void F_1 ( struct V_1 * * V_2 )
{
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_3 ( V_3 > V_5 * sizeof( ( * V_2 ) -> V_6 ) ) ;
* V_2 = NULL ;
}
static inline T_1 * F_4 ( struct V_1 * V_7 )
{
F_5 ( V_7 -> V_8 ) ;
return ( T_1 * ) ( V_7 + 1 ) ;
}
static inline struct V_1 * * F_6 ( struct V_1 * V_7 )
{
F_5 ( ! V_7 -> V_8 ) ;
return (struct V_1 * * ) ( V_7 + 1 ) ;
}
static inline unsigned int
F_7 ( const struct V_1 * V_7 , T_2 V_9 )
{
return ( V_9 >> V_7 -> V_8 ) & V_10 ;
}
static inline unsigned int
F_8 ( const struct V_1 * V_7 , T_2 V_9 )
{
F_5 ( V_7 -> V_8 ) ;
return V_9 & V_10 ;
}
static inline T_2 F_9 ( const struct V_1 * V_7 , T_2 V_9 )
{
return V_9 >> V_7 -> V_8 >> V_4 ;
}
static inline T_2 F_10 ( const struct V_1 * V_7 , T_2 V_9 )
{
F_5 ( V_7 -> V_8 ) ;
return V_9 >> V_4 ;
}
static inline bool F_11 ( T_1 V_11 , T_1 V_12 )
{
return ( V_13 ) ( V_11 - V_12 ) >= 0 ;
}
bool F_12 ( struct V_1 * * V_2 , T_2 V_9 , T_1 V_14 )
{
struct V_1 * V_7 ;
unsigned int V_15 ;
V_7 = * V_2 ;
if ( ! V_7 )
return false ;
if ( F_13 ( F_10 ( V_7 , V_9 ) == V_7 -> V_16 ) )
goto V_17;
do {
V_7 = V_7 -> V_18 ;
if ( ! V_7 )
return false ;
if ( F_9 ( V_7 , V_9 ) == V_7 -> V_16 )
break;
} while ( 1 );
do {
if ( ! V_7 -> V_8 )
break;
V_7 = F_6 ( V_7 ) [ F_7 ( V_7 , V_9 ) ] ;
if ( ! V_7 )
return false ;
if ( F_9 ( V_7 , V_9 ) != V_7 -> V_16 )
return false ;
} while ( 1 );
* V_2 = V_7 ;
V_17:
V_15 = F_8 ( V_7 , V_9 ) ;
if ( ! ( V_7 -> V_6 & F_14 ( V_15 ) ) )
return false ;
return F_11 ( F_4 ( V_7 ) [ V_15 ] , V_14 ) ;
}
static struct V_1 *
F_15 ( struct V_1 * V_18 , T_2 V_9 )
{
struct V_1 * V_7 ;
V_7 = F_16 ( sizeof( * V_7 ) + V_3 * sizeof( T_1 ) , V_19 ) ;
if ( F_17 ( ! V_7 ) )
return NULL ;
V_7 -> V_18 = V_18 ;
V_7 -> V_8 = 0 ;
V_7 -> V_6 = 0 ;
V_7 -> V_16 = F_10 ( V_7 , V_9 ) ;
return V_7 ;
}
static inline void F_18 ( struct V_1 * V_7 , T_2 V_9 , T_1 V_14 )
{
unsigned int V_15 = F_8 ( V_7 , V_9 ) ;
V_7 -> V_6 |= F_14 ( V_15 ) ;
F_4 ( V_7 ) [ V_15 ] = V_14 ;
}
static inline void F_19 ( struct V_1 * V_7 ,
unsigned int V_15 ,
struct V_1 * V_20 )
{
V_7 -> V_6 |= F_14 ( V_15 ) ;
F_6 ( V_7 ) [ V_15 ] = V_20 ;
}
static T_3 int F_20 ( struct V_1 * * V_2 , T_2 V_9 , T_1 V_14 )
{
struct V_1 * V_7 = * V_2 ;
unsigned int V_15 ;
if ( ! V_7 ) {
V_7 = F_15 ( NULL , V_9 ) ;
if ( F_17 ( ! V_7 ) )
return - V_21 ;
goto V_17;
}
F_5 ( F_10 ( V_7 , V_9 ) == V_7 -> V_16 ) ;
do {
if ( ! V_7 -> V_18 )
break;
V_7 = V_7 -> V_18 ;
if ( F_9 ( V_7 , V_9 ) == V_7 -> V_16 )
break;
} while ( 1 );
do {
struct V_1 * V_22 ;
if ( F_9 ( V_7 , V_9 ) != V_7 -> V_16 ) {
unsigned int V_23 ;
V_22 = F_21 ( sizeof( * V_22 ) + V_3 * sizeof( V_22 ) ,
V_19 ) ;
if ( F_17 ( ! V_22 ) )
return - V_21 ;
V_23 = F_22 ( F_9 ( V_7 , V_9 ) ^ V_7 -> V_16 ) ;
V_23 = F_23 ( V_23 , V_4 ) ;
V_22 -> V_8 = V_23 + V_7 -> V_8 ;
V_22 -> V_16 = F_9 ( V_22 , V_9 ) ;
if ( V_7 -> V_18 ) {
V_15 = F_7 ( V_7 -> V_18 , V_9 ) ;
F_6 ( V_7 -> V_18 ) [ V_15 ] = V_22 ;
F_5 ( ! ( V_7 -> V_18 -> V_6 & F_14 ( V_15 ) ) ) ;
}
V_22 -> V_18 = V_7 -> V_18 ;
V_15 = V_7 -> V_16 >> ( V_23 - V_4 ) & V_10 ;
F_19 ( V_22 , V_15 , V_7 ) ;
V_7 -> V_18 = V_22 ;
V_7 = V_22 ;
} else {
if ( ! V_7 -> V_8 )
break;
}
F_5 ( ! V_7 -> V_8 ) ;
V_15 = F_7 ( V_7 , V_9 ) ;
V_22 = F_6 ( V_7 ) [ V_15 ] ;
if ( ! V_22 ) {
V_22 = F_15 ( V_7 , V_9 ) ;
if ( F_17 ( ! V_22 ) )
return - V_21 ;
F_19 ( V_7 , V_15 , V_22 ) ;
V_7 = V_22 ;
break;
}
V_7 = V_22 ;
} while ( 1 );
V_17:
F_5 ( V_7 -> V_16 != F_10 ( V_7 , V_9 ) ) ;
F_18 ( V_7 , V_9 , V_14 ) ;
* V_2 = V_7 ;
return 0 ;
}
int F_24 ( struct V_1 * * V_2 , T_2 V_9 , T_1 V_14 )
{
struct V_1 * V_7 = * V_2 ;
if ( F_13 ( V_7 && F_10 ( V_7 , V_9 ) == V_7 -> V_16 ) ) {
F_18 ( V_7 , V_9 , V_14 ) ;
return 0 ;
}
return F_20 ( V_2 , V_9 , V_14 ) ;
}
static void F_25 ( struct V_1 * V_7 )
{
if ( V_7 -> V_8 ) {
unsigned int V_24 ;
while ( ( V_24 = F_26 ( V_7 -> V_6 ) ) ) {
V_7 -> V_6 &= ~ 0u << V_24 ;
F_25 ( F_6 ( V_7 ) [ V_24 - 1 ] ) ;
}
}
F_27 ( V_7 ) ;
}
void F_28 ( struct V_1 * * V_2 )
{
struct V_1 * V_7 ;
V_7 = * V_2 ;
if ( ! V_7 )
return;
while ( V_7 -> V_18 )
V_7 = V_7 -> V_18 ;
F_25 ( V_7 ) ;
* V_2 = NULL ;
}
