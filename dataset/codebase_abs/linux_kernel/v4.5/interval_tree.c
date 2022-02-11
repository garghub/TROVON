static inline int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 != NULL ) ;
return V_2 == V_2 -> V_3 -> V_4 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 != NULL ) ;
return V_2 == V_2 -> V_3 -> V_5 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_6 == V_7 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_6 == V_8 ;
}
static inline int F_6 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
int V_12 ;
if ( V_10 -> V_13 == V_11 -> V_13 ) {
if ( V_10 -> V_14 < V_11 -> V_14 )
V_12 = - 1 ;
else if ( V_10 -> V_14 > V_11 -> V_14 )
V_12 = 1 ;
else
V_12 = 0 ;
} else {
if ( V_10 -> V_13 < V_11 -> V_13 )
V_12 = - 1 ;
else
V_12 = 1 ;
}
return V_12 ;
}
static inline int F_7 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
return ( V_10 -> V_13 == V_11 -> V_13 ) && ( V_10 -> V_14 == V_11 -> V_14 ) ;
}
static inline T_1 F_8 ( T_1 V_15 , T_1 V_16 )
{
return V_15 > V_16 ? V_15 : V_16 ;
}
static struct V_1 * F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
while ( V_2 -> V_4 )
V_2 = V_2 -> V_4 ;
return V_2 ;
}
static struct V_1 * F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_5 )
return F_9 ( V_2 -> V_5 ) ;
while ( V_2 -> V_3 && F_3 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_1 * V_17 )
{
T_1 V_18 , V_19 ;
V_17 -> V_20 = V_2 -> V_20 ;
V_18 = V_2 -> V_4 ? V_2 -> V_4 -> V_20 : 0 ;
V_19 = V_2 -> V_5 ? V_2 -> V_5 -> V_20 : 0 ;
V_2 -> V_20 = F_8 ( F_12 ( V_2 ) ,
F_8 ( V_18 , V_19 ) ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_22 = V_2 -> V_5 ;
struct V_1 * V_23 = V_2 -> V_3 ;
V_2 -> V_5 = V_22 -> V_4 ;
if ( V_2 -> V_5 )
V_22 -> V_4 -> V_3 = V_2 ;
V_22 -> V_4 = V_2 ;
V_22 -> V_3 = V_23 ;
if ( V_23 ) {
if ( F_1 ( V_2 ) )
V_23 -> V_4 = V_22 ;
else
V_23 -> V_5 = V_22 ;
} else {
* V_21 = V_22 ;
}
V_2 -> V_3 = V_22 ;
F_11 ( V_2 , V_22 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_24 = V_2 -> V_4 ;
struct V_1 * V_23 = V_2 -> V_3 ;
V_2 -> V_4 = V_24 -> V_5 ;
if ( V_2 -> V_4 )
V_24 -> V_5 -> V_3 = V_2 ;
V_24 -> V_5 = V_2 ;
V_24 -> V_3 = V_23 ;
if ( V_23 ) {
if ( F_3 ( V_2 ) )
V_23 -> V_5 = V_24 ;
else
V_23 -> V_4 = V_24 ;
} else {
* V_21 = V_24 ;
}
V_2 -> V_3 = V_24 ;
F_11 ( V_2 , V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_23 , * V_25 ;
while ( ( V_23 = V_2 -> V_3 ) && F_4 ( V_23 ) ) {
V_25 = V_23 -> V_3 ;
if ( F_1 ( V_23 ) ) {
struct V_1 * V_26 ;
V_26 = V_25 -> V_5 ;
if ( V_26 && F_4 ( V_26 ) ) {
V_26 -> V_6 = V_8 ;
V_23 -> V_6 = V_8 ;
V_25 -> V_6 = V_7 ;
V_2 = V_25 ;
continue;
}
if ( V_23 -> V_5 == V_2 ) {
F_13 ( V_23 , V_21 ) ;
F_16 ( V_2 , V_23 ) ;
}
V_23 -> V_6 = V_8 ;
V_25 -> V_6 = V_7 ;
F_14 ( V_25 , V_21 ) ;
} else {
struct V_1 * V_26 ;
V_26 = V_25 -> V_4 ;
if ( V_26 && F_4 ( V_26 ) ) {
V_26 -> V_6 = V_8 ;
V_23 -> V_6 = V_8 ;
V_25 -> V_6 = V_7 ;
V_2 = V_25 ;
continue;
}
if ( F_1 ( V_2 ) ) {
F_14 ( V_23 , V_21 ) ;
F_16 ( V_2 , V_23 ) ;
}
V_23 -> V_6 = V_8 ;
V_25 -> V_6 = V_7 ;
F_13 ( V_25 , V_21 ) ;
}
}
( * V_21 ) -> V_6 = V_8 ;
}
struct V_1 * F_17 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * * V_27 , * V_23 = NULL ;
F_2 ( ! F_18 ( V_2 ) ) ;
V_27 = V_21 ;
while ( * V_27 ) {
V_23 = * V_27 ;
if ( F_7 ( & V_23 -> V_28 , & V_2 -> V_28 ) )
return V_23 ;
if ( V_23 -> V_20 < F_12 ( V_2 ) )
V_23 -> V_20 = F_12 ( V_2 ) ;
if ( F_6 ( & V_2 -> V_28 , & V_23 -> V_28 ) < 0 )
V_27 = & V_23 -> V_4 ;
else
V_27 = & V_23 -> V_5 ;
}
V_2 -> V_3 = V_23 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
* V_27 = V_2 ;
F_15 ( V_2 , V_21 ) ;
V_2 -> V_29 = 1 ;
return NULL ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return ! V_2 || F_5 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_1 * V_23 ,
struct V_1 * * V_21 )
{
struct V_1 * V_30 ;
while ( F_19 ( V_2 ) && V_2 != * V_21 ) {
if ( V_23 -> V_4 == V_2 ) {
V_30 = V_23 -> V_5 ;
if ( F_4 ( V_30 ) ) {
V_30 -> V_6 = V_8 ;
V_23 -> V_6 = V_7 ;
F_13 ( V_23 , V_21 ) ;
V_30 = V_23 -> V_5 ;
}
if ( F_19 ( V_30 -> V_4 ) &&
F_19 ( V_30 -> V_5 ) ) {
V_30 -> V_6 = V_7 ;
V_2 = V_23 ;
V_23 = V_2 -> V_3 ;
} else {
if ( F_19 ( V_30 -> V_5 ) ) {
struct V_1 * V_31 ;
V_31 = V_30 -> V_4 ;
if ( V_31 )
V_31 -> V_6 = V_8 ;
V_30 -> V_6 = V_7 ;
F_14 ( V_30 , V_21 ) ;
V_30 = V_23 -> V_5 ;
}
V_30 -> V_6 = V_23 -> V_6 ;
V_23 -> V_6 = V_8 ;
if ( V_30 -> V_5 )
V_30 -> V_5 -> V_6 = V_8 ;
F_13 ( V_23 , V_21 ) ;
V_2 = * V_21 ;
break;
}
} else {
V_30 = V_23 -> V_4 ;
if ( F_4 ( V_30 ) ) {
V_30 -> V_6 = V_8 ;
V_23 -> V_6 = V_7 ;
F_14 ( V_23 , V_21 ) ;
V_30 = V_23 -> V_4 ;
}
if ( F_19 ( V_30 -> V_4 ) &&
F_19 ( V_30 -> V_5 ) ) {
V_30 -> V_6 = V_7 ;
V_2 = V_23 ;
V_23 = V_2 -> V_3 ;
} else {
if ( F_19 ( V_30 -> V_4 ) ) {
struct V_1 * V_32 ;
V_32 = V_30 -> V_5 ;
if ( V_32 )
V_32 -> V_6 = V_8 ;
V_30 -> V_6 = V_7 ;
F_13 ( V_30 , V_21 ) ;
V_30 = V_23 -> V_4 ;
}
V_30 -> V_6 = V_23 -> V_6 ;
V_23 -> V_6 = V_8 ;
if ( V_30 -> V_4 )
V_30 -> V_4 -> V_6 = V_8 ;
F_14 ( V_23 , V_21 ) ;
V_2 = * V_21 ;
break;
}
}
}
if ( V_2 )
V_2 -> V_6 = V_8 ;
}
static void F_21 ( struct V_1 * V_2 ,
T_1 V_33 )
{
T_1 V_18 , V_19 ;
while ( V_2 ) {
V_18 = V_2 -> V_4 ? V_2 -> V_4 -> V_20 : 0 ;
V_19 = V_2 -> V_5 ? V_2 -> V_5 -> V_20 : 0 ;
V_2 -> V_20 = F_8 ( F_12 ( V_2 ) ,
F_8 ( V_18 , V_19 ) ) ;
if ( V_2 -> V_20 >= V_33 )
break;
V_2 = V_2 -> V_3 ;
}
}
void F_22 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_34 , * V_23 ;
int V_35 ;
F_2 ( F_18 ( V_2 ) ) ;
V_2 -> V_29 = 0 ;
if ( ! V_2 -> V_4 ) {
V_34 = V_2 -> V_5 ;
} else if ( ! V_2 -> V_5 ) {
V_34 = V_2 -> V_4 ;
} else {
struct V_1 * V_36 = V_2 ;
V_2 = F_10 ( V_2 ) ;
V_34 = V_2 -> V_5 ;
V_23 = V_2 -> V_3 ;
V_35 = V_2 -> V_6 ;
if ( V_34 )
V_34 -> V_3 = V_23 ;
if ( V_23 == V_36 )
V_23 -> V_5 = V_34 ;
else
V_23 -> V_4 = V_34 ;
V_2 -> V_6 = V_36 -> V_6 ;
V_2 -> V_5 = V_36 -> V_5 ;
V_2 -> V_4 = V_36 -> V_4 ;
V_2 -> V_3 = V_36 -> V_3 ;
if ( V_36 -> V_3 ) {
if ( F_1 ( V_36 ) )
V_36 -> V_3 -> V_4 = V_2 ;
else
V_36 -> V_3 -> V_5 = V_2 ;
} else {
* V_21 = V_2 ;
}
V_36 -> V_4 -> V_3 = V_2 ;
if ( V_36 -> V_5 )
V_36 -> V_5 -> V_3 = V_2 ;
F_21 ( V_34 ? : V_23 , V_2 -> V_20 ) ;
F_21 ( V_2 , V_36 -> V_20 ) ;
if ( V_23 == V_36 )
V_23 = V_2 ;
goto V_35;
}
V_23 = V_2 -> V_3 ;
V_35 = V_2 -> V_6 ;
if ( V_34 )
V_34 -> V_3 = V_23 ;
if ( V_23 ) {
if ( F_1 ( V_2 ) )
V_23 -> V_4 = V_34 ;
else
V_23 -> V_5 = V_34 ;
} else {
* V_21 = V_34 ;
}
F_21 ( V_34 ? : V_23 , V_2 -> V_20 ) ;
V_35:
if ( V_35 == V_8 )
F_20 ( V_34 , V_23 , V_21 ) ;
}
