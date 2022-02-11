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
bool V_13 , struct V_1 * * V_14 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
struct V_1 * V_11 = F_2 ( V_12 ) , * V_15 , * V_16 ;
if ( V_13 )
* V_14 = V_12 ;
while ( true ) {
if ( F_9 ( ! V_11 ) ) {
F_5 ( V_12 , NULL , V_4 ) ;
break;
}
if( F_10 ( V_11 ) )
break;
V_15 = F_2 ( V_11 ) ;
V_16 = V_15 -> V_17 ;
if ( V_11 != V_16 ) {
if ( V_16 && F_11 ( V_16 ) ) {
F_5 ( V_16 , V_15 , V_4 ) ;
F_5 ( V_11 , V_15 , V_4 ) ;
V_12 = V_15 ;
V_11 = F_4 ( V_12 ) ;
F_5 ( V_12 , V_11 , V_18 ) ;
continue;
}
V_16 = V_11 -> V_17 ;
if ( V_12 == V_16 ) {
V_16 = V_12 -> V_19 ;
F_12 ( V_11 -> V_17 , V_16 ) ;
F_12 ( V_12 -> V_19 , V_11 ) ;
if ( V_16 )
F_5 ( V_16 , V_11 ,
V_4 ) ;
F_5 ( V_11 , V_12 , V_18 ) ;
F_8 ( V_11 , V_12 ) ;
V_11 = V_12 ;
V_16 = V_12 -> V_17 ;
}
F_12 ( V_15 -> V_19 , V_16 ) ;
F_12 ( V_11 -> V_17 , V_15 ) ;
if ( V_16 )
F_5 ( V_16 , V_15 , V_4 ) ;
F_3 ( V_15 , V_11 , V_9 , V_18 ) ;
F_8 ( V_15 , V_11 ) ;
break;
} else {
V_16 = V_15 -> V_19 ;
if ( V_16 && F_11 ( V_16 ) ) {
F_5 ( V_16 , V_15 , V_4 ) ;
F_5 ( V_11 , V_15 , V_4 ) ;
V_12 = V_15 ;
V_11 = F_4 ( V_12 ) ;
F_5 ( V_12 , V_11 , V_18 ) ;
continue;
}
V_16 = V_11 -> V_19 ;
if ( V_12 == V_16 ) {
V_16 = V_12 -> V_17 ;
F_12 ( V_11 -> V_19 , V_16 ) ;
F_12 ( V_12 -> V_17 , V_11 ) ;
if ( V_16 )
F_5 ( V_16 , V_11 ,
V_4 ) ;
F_5 ( V_11 , V_12 , V_18 ) ;
F_8 ( V_11 , V_12 ) ;
V_11 = V_12 ;
V_16 = V_12 -> V_19 ;
}
F_12 ( V_15 -> V_17 , V_16 ) ;
F_12 ( V_11 -> V_19 , V_15 ) ;
if ( V_16 )
F_5 ( V_16 , V_15 , V_4 ) ;
F_3 ( V_15 , V_11 , V_9 , V_18 ) ;
F_8 ( V_15 , V_11 ) ;
break;
}
}
}
static T_1 void
F_13 ( struct V_1 * V_11 , struct V_8 * V_9 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
struct V_1 * V_12 = NULL , * V_20 , * V_21 , * V_22 ;
while ( true ) {
V_20 = V_11 -> V_17 ;
if ( V_12 != V_20 ) {
if ( F_11 ( V_20 ) ) {
V_21 = V_20 -> V_19 ;
F_12 ( V_11 -> V_17 , V_21 ) ;
F_12 ( V_20 -> V_19 , V_11 ) ;
F_5 ( V_21 , V_11 , V_4 ) ;
F_3 ( V_11 , V_20 , V_9 ,
V_18 ) ;
F_8 ( V_11 , V_20 ) ;
V_20 = V_21 ;
}
V_21 = V_20 -> V_17 ;
if ( ! V_21 || F_10 ( V_21 ) ) {
V_22 = V_20 -> V_19 ;
if ( ! V_22 || F_10 ( V_22 ) ) {
F_5 ( V_20 , V_11 ,
V_18 ) ;
if ( F_11 ( V_11 ) )
F_1 ( V_11 ) ;
else {
V_12 = V_11 ;
V_11 = F_4 ( V_12 ) ;
if ( V_11 )
continue;
}
break;
}
V_21 = V_22 -> V_17 ;
F_12 ( V_20 -> V_19 , V_21 ) ;
F_12 ( V_22 -> V_17 , V_20 ) ;
F_12 ( V_11 -> V_17 , V_22 ) ;
if ( V_21 )
F_5 ( V_21 , V_20 ,
V_4 ) ;
F_8 ( V_20 , V_22 ) ;
V_21 = V_20 ;
V_20 = V_22 ;
}
V_22 = V_20 -> V_19 ;
F_12 ( V_11 -> V_17 , V_22 ) ;
F_12 ( V_20 -> V_19 , V_11 ) ;
F_5 ( V_21 , V_20 , V_4 ) ;
if ( V_22 )
F_14 ( V_22 , V_11 ) ;
F_3 ( V_11 , V_20 , V_9 ,
V_4 ) ;
F_8 ( V_11 , V_20 ) ;
break;
} else {
V_20 = V_11 -> V_19 ;
if ( F_11 ( V_20 ) ) {
V_21 = V_20 -> V_17 ;
F_12 ( V_11 -> V_19 , V_21 ) ;
F_12 ( V_20 -> V_17 , V_11 ) ;
F_5 ( V_21 , V_11 , V_4 ) ;
F_3 ( V_11 , V_20 , V_9 ,
V_18 ) ;
F_8 ( V_11 , V_20 ) ;
V_20 = V_21 ;
}
V_21 = V_20 -> V_19 ;
if ( ! V_21 || F_10 ( V_21 ) ) {
V_22 = V_20 -> V_17 ;
if ( ! V_22 || F_10 ( V_22 ) ) {
F_5 ( V_20 , V_11 ,
V_18 ) ;
if ( F_11 ( V_11 ) )
F_1 ( V_11 ) ;
else {
V_12 = V_11 ;
V_11 = F_4 ( V_12 ) ;
if ( V_11 )
continue;
}
break;
}
V_21 = V_22 -> V_19 ;
F_12 ( V_20 -> V_17 , V_21 ) ;
F_12 ( V_22 -> V_19 , V_20 ) ;
F_12 ( V_11 -> V_19 , V_22 ) ;
if ( V_21 )
F_5 ( V_21 , V_20 ,
V_4 ) ;
F_8 ( V_20 , V_22 ) ;
V_21 = V_20 ;
V_20 = V_22 ;
}
V_22 = V_20 -> V_17 ;
F_12 ( V_11 -> V_19 , V_22 ) ;
F_12 ( V_20 -> V_17 , V_11 ) ;
F_5 ( V_21 , V_20 , V_4 ) ;
if ( V_22 )
F_14 ( V_22 , V_11 ) ;
F_3 ( V_11 , V_20 , V_9 ,
V_4 ) ;
F_8 ( V_11 , V_20 ) ;
break;
}
}
}
void F_15 ( struct V_1 * V_11 , struct V_8 * V_9 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
F_13 ( V_11 , V_9 , F_8 ) ;
}
static inline void F_16 ( struct V_1 * V_12 , struct V_1 * V_23 ) {}
static inline void F_17 ( struct V_1 * V_6 , struct V_1 * V_7 ) {}
static inline void F_18 ( struct V_1 * V_6 , struct V_1 * V_7 ) {}
void F_19 ( struct V_1 * V_12 , struct V_8 * V_9 )
{
F_7 ( V_12 , V_9 , false , NULL , F_18 ) ;
}
void F_20 ( struct V_1 * V_12 , struct V_8 * V_9 )
{
struct V_1 * V_24 ;
V_24 = F_21 ( V_12 , V_9 ,
NULL , & V_25 ) ;
if ( V_24 )
F_13 ( V_24 , V_9 , F_18 ) ;
}
void F_22 ( struct V_1 * V_12 ,
struct V_26 * V_9 , bool V_14 )
{
F_7 ( V_12 , & V_9 -> V_8 , V_14 ,
& V_9 -> V_27 , F_18 ) ;
}
void F_23 ( struct V_1 * V_12 , struct V_26 * V_9 )
{
struct V_1 * V_24 ;
V_24 = F_21 ( V_12 , & V_9 -> V_8 ,
& V_9 -> V_27 , & V_25 ) ;
if ( V_24 )
F_13 ( V_24 , & V_9 -> V_8 , F_18 ) ;
}
void F_24 ( struct V_1 * V_12 , struct V_8 * V_9 ,
bool V_13 , struct V_1 * * V_14 ,
void (* F_8)( struct V_1 * V_6 , struct V_1 * V_7 ) )
{
F_7 ( V_12 , V_9 , V_13 , V_14 , F_8 ) ;
}
struct V_1 * F_25 ( const struct V_8 * V_9 )
{
struct V_1 * V_28 ;
V_28 = V_9 -> V_1 ;
if ( ! V_28 )
return NULL ;
while ( V_28 -> V_19 )
V_28 = V_28 -> V_19 ;
return V_28 ;
}
struct V_1 * F_26 ( const struct V_8 * V_9 )
{
struct V_1 * V_28 ;
V_28 = V_9 -> V_1 ;
if ( ! V_28 )
return NULL ;
while ( V_28 -> V_17 )
V_28 = V_28 -> V_17 ;
return V_28 ;
}
struct V_1 * F_27 ( const struct V_1 * V_12 )
{
struct V_1 * V_11 ;
if ( F_28 ( V_12 ) )
return NULL ;
if ( V_12 -> V_17 ) {
V_12 = V_12 -> V_17 ;
while ( V_12 -> V_19 )
V_12 = V_12 -> V_19 ;
return (struct V_1 * ) V_12 ;
}
while ( ( V_11 = F_4 ( V_12 ) ) && V_12 == V_11 -> V_17 )
V_12 = V_11 ;
return V_11 ;
}
struct V_1 * F_29 ( const struct V_1 * V_12 )
{
struct V_1 * V_11 ;
if ( F_28 ( V_12 ) )
return NULL ;
if ( V_12 -> V_19 ) {
V_12 = V_12 -> V_19 ;
while ( V_12 -> V_17 )
V_12 = V_12 -> V_17 ;
return (struct V_1 * ) V_12 ;
}
while ( ( V_11 = F_4 ( V_12 ) ) && V_12 == V_11 -> V_19 )
V_12 = V_11 ;
return V_11 ;
}
void F_30 ( struct V_1 * V_29 , struct V_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 = F_4 ( V_29 ) ;
* V_7 = * V_29 ;
if ( V_29 -> V_19 )
F_14 ( V_29 -> V_19 , V_7 ) ;
if ( V_29 -> V_17 )
F_14 ( V_29 -> V_17 , V_7 ) ;
F_6 ( V_29 , V_7 , V_11 , V_9 ) ;
}
void F_31 ( struct V_1 * V_29 , struct V_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_11 = F_4 ( V_29 ) ;
* V_7 = * V_29 ;
if ( V_29 -> V_19 )
F_14 ( V_29 -> V_19 , V_7 ) ;
if ( V_29 -> V_17 )
F_14 ( V_29 -> V_17 , V_7 ) ;
F_32 ( V_29 , V_7 , V_11 , V_9 ) ;
}
static struct V_1 * F_33 ( const struct V_1 * V_12 )
{
for (; ; ) {
if ( V_12 -> V_19 )
V_12 = V_12 -> V_19 ;
else if ( V_12 -> V_17 )
V_12 = V_12 -> V_17 ;
else
return (struct V_1 * ) V_12 ;
}
}
struct V_1 * F_34 ( const struct V_1 * V_12 )
{
const struct V_1 * V_11 ;
if ( ! V_12 )
return NULL ;
V_11 = F_4 ( V_12 ) ;
if ( V_11 && V_12 == V_11 -> V_19 && V_11 -> V_17 ) {
return F_33 ( V_11 -> V_17 ) ;
} else
return (struct V_1 * ) V_11 ;
}
struct V_1 * F_35 ( const struct V_8 * V_9 )
{
if ( ! V_9 -> V_1 )
return NULL ;
return F_33 ( V_9 -> V_1 ) ;
}
