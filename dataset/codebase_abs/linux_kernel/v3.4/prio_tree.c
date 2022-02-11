static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_6 )
{
if ( V_2 -> V_7 ) {
struct V_8 * V_9 = F_2 (
V_4 , struct V_8 , V_10 . V_3 ) ;
* V_5 = F_3 ( V_9 ) ;
* V_6 = F_4 ( V_9 ) ;
}
else {
* V_5 = V_4 -> V_11 ;
* V_6 = V_4 -> V_12 ;
}
}
void T_1 F_5 ( void )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_6 ( V_14 ) - 1 ; V_13 ++ )
V_14 [ V_13 ] = ( 1UL << ( V_13 + 1 ) ) - 1 ;
V_14 [ F_6 ( V_14 ) - 1 ] = ~ 0UL ;
}
static inline unsigned long F_7 ( unsigned int V_15 )
{
return V_14 [ V_15 - 1 ] ;
}
static void F_8 ( struct V_3 * V_16 ,
struct V_3 * V_17 , bool V_18 )
{
if ( V_18 )
V_16 -> V_18 = V_17 ;
else
V_16 -> V_19 = V_17 ;
V_17 -> V_16 = V_16 ;
}
static struct V_3 * F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_20 )
{
struct V_3 * V_21 ;
if ( V_20 > F_7 ( V_2 -> V_22 ) )
V_2 -> V_22 ++ ;
V_21 = V_4 ;
F_10 ( V_4 ) ;
while ( V_20 > F_7 ( V_2 -> V_22 ) ) {
struct V_3 * V_23 = V_2 -> V_3 ;
V_2 -> V_22 ++ ;
if ( F_11 ( V_2 ) )
continue;
F_12 ( V_2 , V_2 -> V_3 ) ;
F_10 ( V_23 ) ;
F_8 ( V_21 , V_23 , true ) ;
V_21 = V_23 ;
}
if ( ! F_11 ( V_2 ) )
F_8 ( V_21 , V_2 -> V_3 , true ) ;
V_2 -> V_3 = V_4 ;
return V_4 ;
}
struct V_3 * F_13 ( struct V_1 * V_2 ,
struct V_3 * V_24 , struct V_3 * V_4 )
{
F_10 ( V_4 ) ;
if ( V_1 ( V_24 ) ) {
F_14 ( V_2 -> V_3 != V_24 ) ;
V_2 -> V_3 = V_4 ;
} else
F_8 ( V_24 -> V_16 , V_4 , V_24 -> V_16 -> V_18 == V_24 ) ;
if ( ! F_15 ( V_24 ) )
F_8 ( V_4 , V_24 -> V_18 , true ) ;
if ( ! F_16 ( V_24 ) )
F_8 ( V_4 , V_24 -> V_19 , false ) ;
return V_24 ;
}
struct V_3 * F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_25 , * V_26 = V_4 ;
unsigned long V_27 , V_28 ;
unsigned long V_29 , V_30 , V_31 , V_32 ;
int V_33 = 0 ;
F_1 ( V_2 , V_4 , & V_27 , & V_28 ) ;
if ( F_11 ( V_2 ) ||
V_28 > F_7 ( V_2 -> V_22 ) )
return F_9 ( V_2 , V_4 , V_28 ) ;
V_25 = V_2 -> V_3 ;
V_32 = 1UL << ( V_2 -> V_22 - 1 ) ;
while ( V_32 ) {
F_1 ( V_2 , V_25 , & V_29 , & V_30 ) ;
if ( V_29 == V_27 && V_30 == V_28 )
return V_25 ;
if ( V_30 < V_28 ||
( V_30 == V_28 && V_29 > V_27 ) ) {
struct V_3 * V_23 = V_4 ;
V_4 = F_13 ( V_2 , V_25 , V_4 ) ;
V_25 = V_23 ;
V_31 = V_29 ;
V_29 = V_27 ;
V_27 = V_31 ;
V_31 = V_30 ;
V_30 = V_28 ;
V_28 = V_31 ;
}
if ( V_33 )
V_31 = V_28 - V_27 ;
else
V_31 = V_27 ;
if ( V_31 & V_32 ) {
if ( F_16 ( V_25 ) ) {
F_10 ( V_4 ) ;
F_8 ( V_25 , V_4 , false ) ;
return V_26 ;
} else
V_25 = V_25 -> V_19 ;
} else {
if ( F_15 ( V_25 ) ) {
F_10 ( V_4 ) ;
F_8 ( V_25 , V_4 , true ) ;
return V_26 ;
} else
V_25 = V_25 -> V_18 ;
}
V_32 >>= 1 ;
if ( ! V_32 ) {
V_32 = 1UL << ( V_34 - 1 ) ;
V_33 = 1 ;
}
}
F_18 () ;
return NULL ;
}
void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_25 ;
unsigned long V_29 , V_35 , V_36 ;
V_25 = V_4 ;
while ( ! F_15 ( V_25 ) || ! F_16 ( V_25 ) ) {
if ( ! F_15 ( V_25 ) )
F_1 ( V_2 , V_25 -> V_18 , & V_29 , & V_36 ) ;
else {
V_25 = V_25 -> V_19 ;
continue;
}
if ( ! F_16 ( V_25 ) )
F_1 ( V_2 , V_25 -> V_19 , & V_29 , & V_35 ) ;
else {
V_25 = V_25 -> V_18 ;
continue;
}
if ( V_36 >= V_35 )
V_25 = V_25 -> V_18 ;
else
V_25 = V_25 -> V_19 ;
}
if ( V_1 ( V_25 ) ) {
F_14 ( V_2 -> V_3 != V_25 ) ;
F_19 ( V_2 , V_2 -> V_7 ) ;
return;
}
if ( V_25 -> V_16 -> V_19 == V_25 )
V_25 -> V_16 -> V_19 = V_25 -> V_16 ;
else
V_25 -> V_16 -> V_18 = V_25 -> V_16 ;
while ( V_25 != V_4 )
V_25 = F_13 ( V_2 , V_25 -> V_16 , V_25 ) ;
}
static void F_20 ( struct V_37 * V_38 )
{
V_38 -> V_32 >>= 1 ;
if ( V_38 -> V_32 ) {
if ( V_38 -> V_39 )
V_38 -> V_39 ++ ;
return;
}
if ( V_38 -> V_39 ) {
F_14 ( ! F_15 ( V_38 -> V_25 ) ) ;
F_14 ( ! F_16 ( V_38 -> V_25 ) ) ;
V_38 -> V_39 ++ ;
V_38 -> V_32 = V_40 ;
} else {
V_38 -> V_39 = 1 ;
V_38 -> V_32 = 1UL << ( V_34 - 1 ) ;
}
}
static void F_21 ( struct V_37 * V_38 )
{
if ( V_38 -> V_32 == V_40 )
V_38 -> V_32 = 1UL ;
else if ( V_38 -> V_39 == 1 )
V_38 -> V_32 = 1UL ;
else
V_38 -> V_32 <<= 1 ;
if ( V_38 -> V_39 )
V_38 -> V_39 -- ;
if ( ! V_38 -> V_39 && ( V_38 -> V_41 & V_38 -> V_32 ) )
V_38 -> V_41 ^= V_38 -> V_32 ;
}
static struct V_3 * F_22 ( struct V_37 * V_38 ,
unsigned long * V_29 , unsigned long * V_30 )
{
if ( F_15 ( V_38 -> V_25 ) )
return NULL ;
F_1 ( V_38 -> V_2 , V_38 -> V_25 -> V_18 , V_29 , V_30 ) ;
if ( V_38 -> V_29 <= * V_30 ) {
V_38 -> V_25 = V_38 -> V_25 -> V_18 ;
F_20 ( V_38 ) ;
return V_38 -> V_25 ;
}
return NULL ;
}
static struct V_3 * F_23 ( struct V_37 * V_38 ,
unsigned long * V_29 , unsigned long * V_30 )
{
unsigned long V_41 ;
if ( F_16 ( V_38 -> V_25 ) )
return NULL ;
if ( V_38 -> V_39 )
V_41 = V_38 -> V_41 ;
else
V_41 = V_38 -> V_41 | V_38 -> V_32 ;
if ( V_38 -> V_30 < V_41 )
return NULL ;
F_1 ( V_38 -> V_2 , V_38 -> V_25 -> V_19 , V_29 , V_30 ) ;
if ( V_38 -> V_29 <= * V_30 ) {
V_38 -> V_25 = V_38 -> V_25 -> V_19 ;
F_20 ( V_38 ) ;
return V_38 -> V_25 ;
}
return NULL ;
}
static struct V_3 * F_24 ( struct V_37 * V_38 )
{
V_38 -> V_25 = V_38 -> V_25 -> V_16 ;
F_21 ( V_38 ) ;
return V_38 -> V_25 ;
}
static inline int F_25 ( struct V_37 * V_38 ,
unsigned long V_29 , unsigned long V_30 )
{
return V_38 -> V_30 >= V_29 && V_38 -> V_29 <= V_30 ;
}
static struct V_3 * F_26 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
unsigned long V_29 , V_30 ;
F_27 ( V_38 ) ;
V_2 = V_38 -> V_2 ;
if ( F_11 ( V_2 ) )
return NULL ;
F_1 ( V_2 , V_2 -> V_3 , & V_29 , & V_30 ) ;
if ( V_38 -> V_29 > V_30 )
return NULL ;
V_38 -> V_32 = 1UL << ( V_2 -> V_22 - 1 ) ;
V_38 -> V_25 = V_2 -> V_3 ;
while ( 1 ) {
if ( F_25 ( V_38 , V_29 , V_30 ) )
return V_38 -> V_25 ;
if ( F_22 ( V_38 , & V_29 , & V_30 ) )
continue;
if ( F_23 ( V_38 , & V_29 , & V_30 ) )
continue;
break;
}
return NULL ;
}
struct V_3 * F_28 ( struct V_37 * V_38 )
{
unsigned long V_29 , V_30 ;
if ( V_38 -> V_25 == NULL )
return F_26 ( V_38 ) ;
V_42:
while ( F_22 ( V_38 , & V_29 , & V_30 ) )
if ( F_25 ( V_38 , V_29 , V_30 ) )
return V_38 -> V_25 ;
while ( ! F_23 ( V_38 , & V_29 , & V_30 ) ) {
while ( ! V_1 ( V_38 -> V_25 ) &&
V_38 -> V_25 -> V_16 -> V_19 == V_38 -> V_25 )
F_24 ( V_38 ) ;
if ( V_1 ( V_38 -> V_25 ) )
return NULL ;
F_24 ( V_38 ) ;
}
if ( F_25 ( V_38 , V_29 , V_30 ) )
return V_38 -> V_25 ;
goto V_42;
}
