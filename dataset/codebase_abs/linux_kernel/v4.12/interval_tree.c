static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 == V_2 -> V_3 -> V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 == V_2 -> V_3 -> V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_6 == V_7 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_6 == V_8 ;
}
static inline int F_5 ( struct V_9 * V_10 ,
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
static inline int F_6 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
return ( V_10 -> V_13 == V_11 -> V_13 ) && ( V_10 -> V_14 == V_11 -> V_14 ) ;
}
static inline int F_7 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
return ( V_10 -> V_13 <= V_11 -> V_14 ) && ( V_11 -> V_13 <= V_10 -> V_14 ) ;
}
static inline int F_8 ( struct V_1 * V_15 , struct V_1 * V_16 )
{
return F_6 ( & V_15 -> V_17 , & V_16 -> V_17 ) ;
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
while ( V_2 -> V_3 && F_2 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_1 * V_18 )
{
T_1 V_19 , V_20 ;
V_18 -> V_21 = V_2 -> V_21 ;
V_19 = V_2 -> V_4 ? V_2 -> V_4 -> V_21 : 0 ;
V_20 = V_2 -> V_5 ? V_2 -> V_5 -> V_21 : 0 ;
V_2 -> V_21 = F_12 ( F_13 ( V_2 ) ,
F_12 ( V_19 , V_20 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_23 = V_2 -> V_5 ;
struct V_1 * V_24 = V_2 -> V_3 ;
V_2 -> V_5 = V_23 -> V_4 ;
if ( V_2 -> V_5 )
V_23 -> V_4 -> V_3 = V_2 ;
V_23 -> V_4 = V_2 ;
V_23 -> V_3 = V_24 ;
if ( V_24 ) {
if ( F_1 ( V_2 ) )
V_24 -> V_4 = V_23 ;
else
V_24 -> V_5 = V_23 ;
} else {
* V_22 = V_23 ;
}
V_2 -> V_3 = V_23 ;
F_11 ( V_2 , V_23 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_25 = V_2 -> V_4 ;
struct V_1 * V_24 = V_2 -> V_3 ;
V_2 -> V_4 = V_25 -> V_5 ;
if ( V_2 -> V_4 )
V_25 -> V_5 -> V_3 = V_2 ;
V_25 -> V_5 = V_2 ;
V_25 -> V_3 = V_24 ;
if ( V_24 ) {
if ( F_2 ( V_2 ) )
V_24 -> V_5 = V_25 ;
else
V_24 -> V_4 = V_25 ;
} else {
* V_22 = V_25 ;
}
V_2 -> V_3 = V_25 ;
F_11 ( V_2 , V_25 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_24 , * V_26 ;
while ( ( V_24 = V_2 -> V_3 ) && F_3 ( V_24 ) ) {
V_26 = V_24 -> V_3 ;
if ( F_1 ( V_24 ) ) {
struct V_1 * V_27 ;
V_27 = V_26 -> V_5 ;
if ( V_27 && F_3 ( V_27 ) ) {
V_27 -> V_6 = V_8 ;
V_24 -> V_6 = V_8 ;
V_26 -> V_6 = V_7 ;
V_2 = V_26 ;
continue;
}
if ( V_24 -> V_5 == V_2 ) {
F_14 ( V_24 , V_22 ) ;
F_17 ( V_2 , V_24 ) ;
}
V_24 -> V_6 = V_8 ;
V_26 -> V_6 = V_7 ;
F_15 ( V_26 , V_22 ) ;
} else {
struct V_1 * V_27 ;
V_27 = V_26 -> V_4 ;
if ( V_27 && F_3 ( V_27 ) ) {
V_27 -> V_6 = V_8 ;
V_24 -> V_6 = V_8 ;
V_26 -> V_6 = V_7 ;
V_2 = V_26 ;
continue;
}
if ( F_1 ( V_2 ) ) {
F_15 ( V_24 , V_22 ) ;
F_17 ( V_2 , V_24 ) ;
}
V_24 -> V_6 = V_8 ;
V_26 -> V_6 = V_7 ;
F_14 ( V_26 , V_22 ) ;
}
}
( * V_22 ) -> V_6 = V_8 ;
}
struct V_1 * F_18 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * * V_28 , * V_24 = NULL ;
F_19 ( ! F_20 ( V_2 ) ) ;
V_28 = V_22 ;
while ( * V_28 ) {
V_24 = * V_28 ;
if ( F_8 ( V_24 , V_2 ) )
return V_24 ;
if ( V_24 -> V_21 < F_13 ( V_2 ) )
V_24 -> V_21 = F_13 ( V_2 ) ;
if ( F_5 ( & V_2 -> V_17 , & V_24 -> V_17 ) < 0 )
V_28 = & V_24 -> V_4 ;
else
V_28 = & V_24 -> V_5 ;
}
V_2 -> V_3 = V_24 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
* V_28 = V_2 ;
F_16 ( V_2 , V_22 ) ;
V_2 -> V_29 = 1 ;
return NULL ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ! V_2 || F_4 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_1 * V_24 ,
struct V_1 * * V_22 )
{
struct V_1 * V_30 ;
while ( F_21 ( V_2 ) && V_2 != * V_22 ) {
if ( V_24 -> V_4 == V_2 ) {
V_30 = V_24 -> V_5 ;
if ( F_3 ( V_30 ) ) {
V_30 -> V_6 = V_8 ;
V_24 -> V_6 = V_7 ;
F_14 ( V_24 , V_22 ) ;
V_30 = V_24 -> V_5 ;
}
if ( F_21 ( V_30 -> V_4 ) &&
F_21 ( V_30 -> V_5 ) ) {
V_30 -> V_6 = V_7 ;
V_2 = V_24 ;
V_24 = V_2 -> V_3 ;
} else {
if ( F_21 ( V_30 -> V_5 ) ) {
struct V_1 * V_31 ;
V_31 = V_30 -> V_4 ;
if ( V_31 )
V_31 -> V_6 = V_8 ;
V_30 -> V_6 = V_7 ;
F_15 ( V_30 , V_22 ) ;
V_30 = V_24 -> V_5 ;
}
V_30 -> V_6 = V_24 -> V_6 ;
V_24 -> V_6 = V_8 ;
if ( V_30 -> V_5 )
V_30 -> V_5 -> V_6 = V_8 ;
F_14 ( V_24 , V_22 ) ;
V_2 = * V_22 ;
break;
}
} else {
V_30 = V_24 -> V_4 ;
if ( F_3 ( V_30 ) ) {
V_30 -> V_6 = V_8 ;
V_24 -> V_6 = V_7 ;
F_15 ( V_24 , V_22 ) ;
V_30 = V_24 -> V_4 ;
}
if ( F_21 ( V_30 -> V_4 ) &&
F_21 ( V_30 -> V_5 ) ) {
V_30 -> V_6 = V_7 ;
V_2 = V_24 ;
V_24 = V_2 -> V_3 ;
} else {
if ( F_21 ( V_30 -> V_4 ) ) {
struct V_1 * V_32 ;
V_32 = V_30 -> V_5 ;
if ( V_32 )
V_32 -> V_6 = V_8 ;
V_30 -> V_6 = V_7 ;
F_14 ( V_30 , V_22 ) ;
V_30 = V_24 -> V_4 ;
}
V_30 -> V_6 = V_24 -> V_6 ;
V_24 -> V_6 = V_8 ;
if ( V_30 -> V_4 )
V_30 -> V_4 -> V_6 = V_8 ;
F_15 ( V_24 , V_22 ) ;
V_2 = * V_22 ;
break;
}
}
}
if ( V_2 )
V_2 -> V_6 = V_8 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_33 )
{
T_1 V_19 , V_20 ;
while ( V_2 ) {
V_19 = V_2 -> V_4 ? V_2 -> V_4 -> V_21 : 0 ;
V_20 = V_2 -> V_5 ? V_2 -> V_5 -> V_21 : 0 ;
V_2 -> V_21 = F_12 ( F_13 ( V_2 ) ,
F_12 ( V_19 , V_20 ) ) ;
if ( V_2 -> V_21 >= V_33 )
break;
V_2 = V_2 -> V_3 ;
}
}
void F_24 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_34 , * V_24 ;
int V_35 ;
F_19 ( F_20 ( V_2 ) ) ;
V_2 -> V_29 = 0 ;
if ( ! V_2 -> V_4 ) {
V_34 = V_2 -> V_5 ;
} else if ( ! V_2 -> V_5 ) {
V_34 = V_2 -> V_4 ;
} else {
struct V_1 * V_36 = V_2 ;
V_2 = F_10 ( V_2 ) ;
V_34 = V_2 -> V_5 ;
V_24 = V_2 -> V_3 ;
V_35 = V_2 -> V_6 ;
if ( V_34 )
V_34 -> V_3 = V_24 ;
if ( V_24 == V_36 )
V_24 -> V_5 = V_34 ;
else
V_24 -> V_4 = V_34 ;
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
* V_22 = V_2 ;
}
V_36 -> V_4 -> V_3 = V_2 ;
if ( V_36 -> V_5 )
V_36 -> V_5 -> V_3 = V_2 ;
F_23 ( V_34 ? : V_24 , V_2 -> V_21 ) ;
F_23 ( V_2 , V_36 -> V_21 ) ;
if ( V_24 == V_36 )
V_24 = V_2 ;
goto V_35;
}
V_24 = V_2 -> V_3 ;
V_35 = V_2 -> V_6 ;
if ( V_34 )
V_34 -> V_3 = V_24 ;
if ( V_24 ) {
if ( F_1 ( V_2 ) )
V_24 -> V_4 = V_34 ;
else
V_24 -> V_5 = V_34 ;
} else {
* V_22 = V_34 ;
}
F_23 ( V_34 ? : V_24 , V_2 -> V_21 ) ;
V_35:
if ( V_35 == V_8 )
F_22 ( V_34 , V_24 , V_22 ) ;
}
static inline int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_37 )
{
return ( V_37 -> V_13 <= V_2 -> V_21 &&
V_37 -> V_14 >= F_26 ( V_2 ) ) ;
}
enum V_38 F_27 ( struct V_1 * V_2 ,
struct V_9 * V_37 ,
T_2 V_39 ,
void * V_40 )
{
enum V_38 V_12 = V_41 ;
struct V_1 * V_24 ;
F_19 ( V_37 ) ;
F_19 ( V_39 ) ;
while ( V_2 ) {
if ( V_37 -> V_14 < F_26 ( V_2 ) ) {
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_4 ;
continue;
}
} else if ( F_25 ( V_2 , V_37 ) ) {
if ( F_7 ( V_37 , & V_2 -> V_17 ) ) {
V_12 = V_39 ( V_2 , V_40 ) ;
if ( V_12 == V_42 )
break;
}
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_4 ;
continue;
}
if ( V_2 -> V_5 ) {
V_2 = V_2 -> V_5 ;
continue;
}
}
V_24 = V_2 -> V_3 ;
while ( V_24 ) {
if ( F_1 ( V_2 ) &&
V_24 -> V_5 ) {
V_2 = V_24 -> V_5 ;
break;
}
V_2 = V_24 ;
V_24 = V_24 -> V_3 ;
}
if ( ! V_24 || ! F_25 ( V_24 , V_37 ) )
break;
}
return V_12 ;
}
