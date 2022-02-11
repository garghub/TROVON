static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_4 ;
}
static inline struct V_1 * F_2 ( struct V_1 * V_5 )
{
return (struct V_1 * ) V_5 -> V_3 ;
}
static inline void
F_3 ( struct V_1 * V_6 , struct V_1 * V_7 ,
struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_11 = F_4 ( V_6 ) ;
V_7 -> V_3 = V_6 -> V_3 ;
F_5 ( V_6 , V_7 , V_10 ) ;
F_6 ( V_6 , V_7 , V_11 , V_9 ) ;
}
static T_1 void
F_7 ( struct V_1 * V_12 , struct V_8 * V_9 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
struct V_1 * V_11 = F_2 ( V_12 ) , * V_13 , * V_14 ;
while ( true ) {
if ( ! V_11 ) {
F_5 ( V_12 , NULL , V_4 ) ;
break;
} else if ( F_9 ( V_11 ) )
break;
V_13 = F_2 ( V_11 ) ;
V_14 = V_13 -> V_15 ;
if ( V_11 != V_14 ) {
if ( V_14 && F_10 ( V_14 ) ) {
F_5 ( V_14 , V_13 , V_4 ) ;
F_5 ( V_11 , V_13 , V_4 ) ;
V_12 = V_13 ;
V_11 = F_4 ( V_12 ) ;
F_5 ( V_12 , V_11 , V_16 ) ;
continue;
}
V_14 = V_11 -> V_15 ;
if ( V_12 == V_14 ) {
V_11 -> V_15 = V_14 = V_12 -> V_17 ;
V_12 -> V_17 = V_11 ;
if ( V_14 )
F_5 ( V_14 , V_11 ,
V_4 ) ;
F_5 ( V_11 , V_12 , V_16 ) ;
F_8 ( V_11 , V_12 ) ;
V_11 = V_12 ;
V_14 = V_12 -> V_15 ;
}
V_13 -> V_17 = V_14 ;
V_11 -> V_15 = V_13 ;
if ( V_14 )
F_5 ( V_14 , V_13 , V_4 ) ;
F_3 ( V_13 , V_11 , V_9 , V_16 ) ;
F_8 ( V_13 , V_11 ) ;
break;
} else {
V_14 = V_13 -> V_17 ;
if ( V_14 && F_10 ( V_14 ) ) {
F_5 ( V_14 , V_13 , V_4 ) ;
F_5 ( V_11 , V_13 , V_4 ) ;
V_12 = V_13 ;
V_11 = F_4 ( V_12 ) ;
F_5 ( V_12 , V_11 , V_16 ) ;
continue;
}
V_14 = V_11 -> V_17 ;
if ( V_12 == V_14 ) {
V_11 -> V_17 = V_14 = V_12 -> V_15 ;
V_12 -> V_15 = V_11 ;
if ( V_14 )
F_5 ( V_14 , V_11 ,
V_4 ) ;
F_5 ( V_11 , V_12 , V_16 ) ;
F_8 ( V_11 , V_12 ) ;
V_11 = V_12 ;
V_14 = V_12 -> V_17 ;
}
V_13 -> V_15 = V_14 ;
V_11 -> V_17 = V_13 ;
if ( V_14 )
F_5 ( V_14 , V_13 , V_4 ) ;
F_3 ( V_13 , V_11 , V_9 , V_16 ) ;
F_8 ( V_13 , V_11 ) ;
break;
}
}
}
static T_1 void
F_11 ( struct V_1 * V_11 , struct V_8 * V_9 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
struct V_1 * V_12 = NULL , * V_18 , * V_19 , * V_20 ;
while ( true ) {
V_18 = V_11 -> V_15 ;
if ( V_12 != V_18 ) {
if ( F_10 ( V_18 ) ) {
V_11 -> V_15 = V_19 = V_18 -> V_17 ;
V_18 -> V_17 = V_11 ;
F_5 ( V_19 , V_11 , V_4 ) ;
F_3 ( V_11 , V_18 , V_9 ,
V_16 ) ;
F_8 ( V_11 , V_18 ) ;
V_18 = V_19 ;
}
V_19 = V_18 -> V_15 ;
if ( ! V_19 || F_9 ( V_19 ) ) {
V_20 = V_18 -> V_17 ;
if ( ! V_20 || F_9 ( V_20 ) ) {
F_5 ( V_18 , V_11 ,
V_16 ) ;
if ( F_10 ( V_11 ) )
F_1 ( V_11 ) ;
else {
V_12 = V_11 ;
V_11 = F_4 ( V_12 ) ;
if ( V_11 )
continue;
}
break;
}
V_18 -> V_17 = V_19 = V_20 -> V_15 ;
V_20 -> V_15 = V_18 ;
V_11 -> V_15 = V_20 ;
if ( V_19 )
F_5 ( V_19 , V_18 ,
V_4 ) ;
F_8 ( V_18 , V_20 ) ;
V_19 = V_18 ;
V_18 = V_20 ;
}
V_11 -> V_15 = V_20 = V_18 -> V_17 ;
V_18 -> V_17 = V_11 ;
F_5 ( V_19 , V_18 , V_4 ) ;
if ( V_20 )
F_12 ( V_20 , V_11 ) ;
F_3 ( V_11 , V_18 , V_9 ,
V_4 ) ;
F_8 ( V_11 , V_18 ) ;
break;
} else {
V_18 = V_11 -> V_17 ;
if ( F_10 ( V_18 ) ) {
V_11 -> V_17 = V_19 = V_18 -> V_15 ;
V_18 -> V_15 = V_11 ;
F_5 ( V_19 , V_11 , V_4 ) ;
F_3 ( V_11 , V_18 , V_9 ,
V_16 ) ;
F_8 ( V_11 , V_18 ) ;
V_18 = V_19 ;
}
V_19 = V_18 -> V_17 ;
if ( ! V_19 || F_9 ( V_19 ) ) {
V_20 = V_18 -> V_15 ;
if ( ! V_20 || F_9 ( V_20 ) ) {
F_5 ( V_18 , V_11 ,
V_16 ) ;
if ( F_10 ( V_11 ) )
F_1 ( V_11 ) ;
else {
V_12 = V_11 ;
V_11 = F_4 ( V_12 ) ;
if ( V_11 )
continue;
}
break;
}
V_18 -> V_15 = V_19 = V_20 -> V_17 ;
V_20 -> V_17 = V_18 ;
V_11 -> V_17 = V_20 ;
if ( V_19 )
F_5 ( V_19 , V_18 ,
V_4 ) ;
F_8 ( V_18 , V_20 ) ;
V_19 = V_18 ;
V_18 = V_20 ;
}
V_11 -> V_17 = V_20 = V_18 -> V_15 ;
V_18 -> V_15 = V_11 ;
F_5 ( V_19 , V_18 , V_4 ) ;
if ( V_20 )
F_12 ( V_20 , V_11 ) ;
F_3 ( V_11 , V_18 , V_9 ,
V_4 ) ;
F_8 ( V_11 , V_18 ) ;
break;
}
}
}
void F_13 ( struct V_1 * V_11 , struct V_8 * V_9 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
F_11 ( V_11 , V_9 , F_8 ) ;
}
static inline void F_14 ( struct V_1 * V_12 , struct V_1 * V_21 ) {}
static inline void F_15 ( struct V_1 * V_6 , struct V_1 * V_7 ) {}
static inline void F_16 ( struct V_1 * V_6 , struct V_1 * V_7 ) {}
void F_17 ( struct V_1 * V_12 , struct V_8 * V_9 )
{
F_7 ( V_12 , V_9 , F_16 ) ;
}
void F_18 ( struct V_1 * V_12 , struct V_8 * V_9 )
{
struct V_1 * V_22 ;
V_22 = F_19 ( V_12 , V_9 , & V_23 ) ;
if ( V_22 )
F_11 ( V_22 , V_9 , F_16 ) ;
}
void F_20 ( struct V_1 * V_12 , struct V_8 * V_9 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
F_7 ( V_12 , V_9 , F_8 ) ;
}
struct V_1 * F_21 ( const struct V_8 * V_9 )
{
struct V_1 * V_24 ;
V_24 = V_9 -> V_1 ;
if ( ! V_24 )
return NULL ;
while ( V_24 -> V_17 )
V_24 = V_24 -> V_17 ;
return V_24 ;
}
struct V_1 * F_22 ( const struct V_8 * V_9 )
{
struct V_1 * V_24 ;
V_24 = V_9 -> V_1 ;
if ( ! V_24 )
return NULL ;
while ( V_24 -> V_15 )
V_24 = V_24 -> V_15 ;
return V_24 ;
}
struct V_1 * F_23 ( const struct V_1 * V_12 )
{
struct V_1 * V_11 ;
if ( F_24 ( V_12 ) )
return NULL ;
if ( V_12 -> V_15 ) {
V_12 = V_12 -> V_15 ;
while ( V_12 -> V_17 )
V_12 = V_12 -> V_17 ;
return (struct V_1 * ) V_12 ;
}
while ( ( V_11 = F_4 ( V_12 ) ) && V_12 == V_11 -> V_15 )
V_12 = V_11 ;
return V_11 ;
}
struct V_1 * F_25 ( const struct V_1 * V_12 )
{
struct V_1 * V_11 ;
if ( F_24 ( V_12 ) )
return NULL ;
if ( V_12 -> V_17 ) {
V_12 = V_12 -> V_17 ;
while ( V_12 -> V_15 )
V_12 = V_12 -> V_15 ;
return (struct V_1 * ) V_12 ;
}
while ( ( V_11 = F_4 ( V_12 ) ) && V_12 == V_11 -> V_17 )
V_12 = V_11 ;
return V_11 ;
}
void F_26 ( struct V_1 * V_25 , struct V_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 = F_4 ( V_25 ) ;
F_6 ( V_25 , V_7 , V_11 , V_9 ) ;
if ( V_25 -> V_17 )
F_12 ( V_25 -> V_17 , V_7 ) ;
if ( V_25 -> V_15 )
F_12 ( V_25 -> V_15 , V_7 ) ;
* V_7 = * V_25 ;
}
