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
static struct V_3 * F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_16 )
{
struct V_3 * V_17 = NULL , * V_18 , * V_12 = NULL ;
if ( V_16 > F_7 ( V_2 -> V_19 ) )
V_2 -> V_19 ++ ;
while ( V_16 > F_7 ( V_2 -> V_19 ) ) {
V_2 -> V_19 ++ ;
if ( F_9 ( V_2 ) )
continue;
if ( V_17 == NULL ) {
V_17 = V_2 -> V_3 ;
F_10 ( V_2 , V_2 -> V_3 ) ;
F_11 ( V_17 ) ;
V_12 = V_17 ;
} else {
V_18 = V_12 ;
V_12 = V_2 -> V_3 ;
F_10 ( V_2 , V_2 -> V_3 ) ;
F_11 ( V_12 ) ;
V_18 -> V_20 = V_12 ;
V_12 -> V_21 = V_18 ;
}
}
F_11 ( V_4 ) ;
if ( V_17 ) {
V_4 -> V_20 = V_17 ;
V_17 -> V_21 = V_4 ;
} else
V_12 = V_4 ;
if ( ! F_9 ( V_2 ) ) {
V_12 -> V_20 = V_2 -> V_3 ;
V_12 -> V_20 -> V_21 = V_12 ;
}
V_2 -> V_3 = V_4 ;
return V_4 ;
}
struct V_3 * F_12 ( struct V_1 * V_2 ,
struct V_3 * V_22 , struct V_3 * V_4 )
{
F_11 ( V_4 ) ;
if ( V_1 ( V_22 ) ) {
F_13 ( V_2 -> V_3 != V_22 ) ;
V_4 -> V_21 = V_4 ;
V_2 -> V_3 = V_4 ;
} else {
V_4 -> V_21 = V_22 -> V_21 ;
if ( V_22 -> V_21 -> V_20 == V_22 )
V_22 -> V_21 -> V_20 = V_4 ;
else
V_22 -> V_21 -> V_23 = V_4 ;
}
if ( ! F_14 ( V_22 ) ) {
V_4 -> V_20 = V_22 -> V_20 ;
V_22 -> V_20 -> V_21 = V_4 ;
}
if ( ! F_15 ( V_22 ) ) {
V_4 -> V_23 = V_22 -> V_23 ;
V_22 -> V_23 -> V_21 = V_4 ;
}
return V_22 ;
}
struct V_3 * F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_24 , * V_25 = V_4 ;
unsigned long V_26 , V_27 ;
unsigned long V_28 , V_29 , V_30 , V_31 ;
int V_32 = 0 ;
F_1 ( V_2 , V_4 , & V_26 , & V_27 ) ;
if ( F_9 ( V_2 ) ||
V_27 > F_7 ( V_2 -> V_19 ) )
return F_8 ( V_2 , V_4 , V_27 ) ;
V_24 = V_2 -> V_3 ;
V_31 = 1UL << ( V_2 -> V_19 - 1 ) ;
while ( V_31 ) {
F_1 ( V_2 , V_24 , & V_28 , & V_29 ) ;
if ( V_28 == V_26 && V_29 == V_27 )
return V_24 ;
if ( V_29 < V_27 ||
( V_29 == V_27 && V_28 > V_26 ) ) {
struct V_3 * V_33 = V_4 ;
V_4 = F_12 ( V_2 , V_24 , V_4 ) ;
V_24 = V_33 ;
V_30 = V_28 ;
V_28 = V_26 ;
V_26 = V_30 ;
V_30 = V_29 ;
V_29 = V_27 ;
V_27 = V_30 ;
}
if ( V_32 )
V_30 = V_27 - V_26 ;
else
V_30 = V_26 ;
if ( V_30 & V_31 ) {
if ( F_15 ( V_24 ) ) {
F_11 ( V_4 ) ;
V_24 -> V_23 = V_4 ;
V_4 -> V_21 = V_24 ;
return V_25 ;
} else
V_24 = V_24 -> V_23 ;
} else {
if ( F_14 ( V_24 ) ) {
F_11 ( V_4 ) ;
V_24 -> V_20 = V_4 ;
V_4 -> V_21 = V_24 ;
return V_25 ;
} else
V_24 = V_24 -> V_20 ;
}
V_31 >>= 1 ;
if ( ! V_31 ) {
V_31 = 1UL << ( V_34 - 1 ) ;
V_32 = 1 ;
}
}
F_17 () ;
return NULL ;
}
void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_24 ;
unsigned long V_28 , V_35 , V_36 ;
V_24 = V_4 ;
while ( ! F_14 ( V_24 ) || ! F_15 ( V_24 ) ) {
if ( ! F_14 ( V_24 ) )
F_1 ( V_2 , V_24 -> V_20 , & V_28 , & V_36 ) ;
else {
V_24 = V_24 -> V_23 ;
continue;
}
if ( ! F_15 ( V_24 ) )
F_1 ( V_2 , V_24 -> V_23 , & V_28 , & V_35 ) ;
else {
V_24 = V_24 -> V_20 ;
continue;
}
if ( V_36 >= V_35 )
V_24 = V_24 -> V_20 ;
else
V_24 = V_24 -> V_23 ;
}
if ( V_1 ( V_24 ) ) {
F_13 ( V_2 -> V_3 != V_24 ) ;
F_18 ( V_2 , V_2 -> V_7 ) ;
return;
}
if ( V_24 -> V_21 -> V_23 == V_24 )
V_24 -> V_21 -> V_23 = V_24 -> V_21 ;
else
V_24 -> V_21 -> V_20 = V_24 -> V_21 ;
while ( V_24 != V_4 )
V_24 = F_12 ( V_2 , V_24 -> V_21 , V_24 ) ;
}
static struct V_3 * F_19 ( struct V_37 * V_38 ,
unsigned long * V_28 , unsigned long * V_29 )
{
if ( F_14 ( V_38 -> V_24 ) )
return NULL ;
F_1 ( V_38 -> V_2 , V_38 -> V_24 -> V_20 , V_28 , V_29 ) ;
if ( V_38 -> V_28 <= * V_29 ) {
V_38 -> V_24 = V_38 -> V_24 -> V_20 ;
V_38 -> V_31 >>= 1 ;
if ( V_38 -> V_31 ) {
if ( V_38 -> V_39 )
V_38 -> V_39 ++ ;
} else {
if ( V_38 -> V_39 ) {
F_13 ( ! F_14 ( V_38 -> V_24 ) ) ;
F_13 ( ! F_15 ( V_38 -> V_24 ) ) ;
V_38 -> V_39 ++ ;
V_38 -> V_31 = V_40 ;
} else {
V_38 -> V_39 = 1 ;
V_38 -> V_31 = 1UL << ( V_34 - 1 ) ;
}
}
return V_38 -> V_24 ;
}
return NULL ;
}
static struct V_3 * F_20 ( struct V_37 * V_38 ,
unsigned long * V_28 , unsigned long * V_29 )
{
unsigned long V_41 ;
if ( F_15 ( V_38 -> V_24 ) )
return NULL ;
if ( V_38 -> V_39 )
V_41 = V_38 -> V_41 ;
else
V_41 = V_38 -> V_41 | V_38 -> V_31 ;
if ( V_38 -> V_29 < V_41 )
return NULL ;
F_1 ( V_38 -> V_2 , V_38 -> V_24 -> V_23 , V_28 , V_29 ) ;
if ( V_38 -> V_28 <= * V_29 ) {
V_38 -> V_24 = V_38 -> V_24 -> V_23 ;
V_38 -> V_31 >>= 1 ;
V_38 -> V_41 = V_41 ;
if ( V_38 -> V_31 ) {
if ( V_38 -> V_39 )
V_38 -> V_39 ++ ;
} else {
if ( V_38 -> V_39 ) {
F_13 ( ! F_14 ( V_38 -> V_24 ) ) ;
F_13 ( ! F_15 ( V_38 -> V_24 ) ) ;
V_38 -> V_39 ++ ;
V_38 -> V_31 = V_40 ;
} else {
V_38 -> V_39 = 1 ;
V_38 -> V_31 = 1UL << ( V_34 - 1 ) ;
}
}
return V_38 -> V_24 ;
}
return NULL ;
}
static struct V_3 * F_21 ( struct V_37 * V_38 )
{
V_38 -> V_24 = V_38 -> V_24 -> V_21 ;
if ( V_38 -> V_31 == V_40 )
V_38 -> V_31 = 1UL ;
else if ( V_38 -> V_39 == 1 )
V_38 -> V_31 = 1UL ;
else
V_38 -> V_31 <<= 1 ;
if ( V_38 -> V_39 )
V_38 -> V_39 -- ;
if ( ! V_38 -> V_39 && ( V_38 -> V_41 & V_38 -> V_31 ) )
V_38 -> V_41 ^= V_38 -> V_31 ;
return V_38 -> V_24 ;
}
static inline int F_22 ( struct V_37 * V_38 ,
unsigned long V_28 , unsigned long V_29 )
{
return V_38 -> V_29 >= V_28 && V_38 -> V_28 <= V_29 ;
}
static struct V_3 * F_23 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
unsigned long V_28 , V_29 ;
F_24 ( V_38 ) ;
V_2 = V_38 -> V_2 ;
if ( F_9 ( V_2 ) )
return NULL ;
F_1 ( V_2 , V_2 -> V_3 , & V_28 , & V_29 ) ;
if ( V_38 -> V_28 > V_29 )
return NULL ;
V_38 -> V_31 = 1UL << ( V_2 -> V_19 - 1 ) ;
V_38 -> V_24 = V_2 -> V_3 ;
while ( 1 ) {
if ( F_22 ( V_38 , V_28 , V_29 ) )
return V_38 -> V_24 ;
if ( F_19 ( V_38 , & V_28 , & V_29 ) )
continue;
if ( F_20 ( V_38 , & V_28 , & V_29 ) )
continue;
break;
}
return NULL ;
}
struct V_3 * F_25 ( struct V_37 * V_38 )
{
unsigned long V_28 , V_29 ;
if ( V_38 -> V_24 == NULL )
return F_23 ( V_38 ) ;
V_42:
while ( F_19 ( V_38 , & V_28 , & V_29 ) )
if ( F_22 ( V_38 , V_28 , V_29 ) )
return V_38 -> V_24 ;
while ( ! F_20 ( V_38 , & V_28 , & V_29 ) ) {
while ( ! V_1 ( V_38 -> V_24 ) &&
V_38 -> V_24 -> V_21 -> V_23 == V_38 -> V_24 )
F_21 ( V_38 ) ;
if ( V_1 ( V_38 -> V_24 ) )
return NULL ;
F_21 ( V_38 ) ;
}
if ( F_22 ( V_38 , V_28 , V_29 ) )
return V_38 -> V_24 ;
goto V_42;
}
