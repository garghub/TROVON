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
static inline int F_8 ( struct V_1 * V_15 ,
struct V_1 * V_16 )
{
return F_6 ( & V_15 -> V_17 , & V_16 -> V_17 ) ;
}
static inline int F_9 ( struct V_1 * V_15 ,
struct V_1 * V_16 )
{
return F_7 ( & V_15 -> V_17 , & V_16 -> V_17 ) ;
}
static inline T_1 F_10 ( T_1 V_18 , T_1 V_19 )
{
return V_18 > V_19 ? V_18 : V_19 ;
}
static struct V_1 * F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
while ( V_2 -> V_4 )
V_2 = V_2 -> V_4 ;
return V_2 ;
}
static struct V_1 * F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_5 )
return F_11 ( V_2 -> V_5 ) ;
while ( V_2 -> V_3 && F_3 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_1 * V_20 )
{
T_1 V_21 , V_22 ;
V_20 -> V_23 = V_2 -> V_23 ;
V_21 = V_2 -> V_4 ? V_2 -> V_4 -> V_23 : 0 ;
V_22 = V_2 -> V_5 ? V_2 -> V_5 -> V_23 : 0 ;
V_2 -> V_23 = F_10 ( F_14 ( V_2 ) ,
F_10 ( V_21 , V_22 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_1 * * V_24 )
{
struct V_1 * V_25 = V_2 -> V_5 ;
struct V_1 * V_26 = V_2 -> V_3 ;
V_2 -> V_5 = V_25 -> V_4 ;
if ( V_2 -> V_5 )
V_25 -> V_4 -> V_3 = V_2 ;
V_25 -> V_4 = V_2 ;
V_25 -> V_3 = V_26 ;
if ( V_26 ) {
if ( F_1 ( V_2 ) )
V_26 -> V_4 = V_25 ;
else
V_26 -> V_5 = V_25 ;
} else {
* V_24 = V_25 ;
}
V_2 -> V_3 = V_25 ;
F_13 ( V_2 , V_25 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_1 * * V_24 )
{
struct V_1 * V_27 = V_2 -> V_4 ;
struct V_1 * V_26 = V_2 -> V_3 ;
V_2 -> V_4 = V_27 -> V_5 ;
if ( V_2 -> V_4 )
V_27 -> V_5 -> V_3 = V_2 ;
V_27 -> V_5 = V_2 ;
V_27 -> V_3 = V_26 ;
if ( V_26 ) {
if ( F_3 ( V_2 ) )
V_26 -> V_5 = V_27 ;
else
V_26 -> V_4 = V_27 ;
} else {
* V_24 = V_27 ;
}
V_2 -> V_3 = V_27 ;
F_13 ( V_2 , V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_1 * * V_24 )
{
struct V_1 * V_26 , * V_28 ;
while ( ( V_26 = V_2 -> V_3 ) && F_4 ( V_26 ) ) {
V_28 = V_26 -> V_3 ;
if ( F_1 ( V_26 ) ) {
struct V_1 * V_29 ;
V_29 = V_28 -> V_5 ;
if ( V_29 && F_4 ( V_29 ) ) {
V_29 -> V_6 = V_8 ;
V_26 -> V_6 = V_8 ;
V_28 -> V_6 = V_7 ;
V_2 = V_28 ;
continue;
}
if ( V_26 -> V_5 == V_2 ) {
F_15 ( V_26 , V_24 ) ;
F_18 ( V_2 , V_26 ) ;
}
V_26 -> V_6 = V_8 ;
V_28 -> V_6 = V_7 ;
F_16 ( V_28 , V_24 ) ;
} else {
struct V_1 * V_29 ;
V_29 = V_28 -> V_4 ;
if ( V_29 && F_4 ( V_29 ) ) {
V_29 -> V_6 = V_8 ;
V_26 -> V_6 = V_8 ;
V_28 -> V_6 = V_7 ;
V_2 = V_28 ;
continue;
}
if ( F_1 ( V_2 ) ) {
F_16 ( V_26 , V_24 ) ;
F_18 ( V_2 , V_26 ) ;
}
V_26 -> V_6 = V_8 ;
V_28 -> V_6 = V_7 ;
F_15 ( V_28 , V_24 ) ;
}
}
( * V_24 ) -> V_6 = V_8 ;
}
struct V_1 * F_19 ( struct V_1 * V_2 ,
struct V_1 * * V_24 )
{
struct V_1 * * V_30 , * V_26 = NULL ;
F_2 ( ! F_20 ( V_2 ) ) ;
V_30 = V_24 ;
while ( * V_30 ) {
V_26 = * V_30 ;
if ( F_9 ( V_26 , V_2 ) )
return V_26 ;
if ( V_26 -> V_23 < F_14 ( V_2 ) )
V_26 -> V_23 = F_14 ( V_2 ) ;
if ( F_8 ( V_2 , V_26 ) < 0 )
V_30 = & V_26 -> V_4 ;
else
V_30 = & V_26 -> V_5 ;
}
V_2 -> V_3 = V_26 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
* V_30 = V_2 ;
F_17 ( V_2 , V_24 ) ;
V_2 -> V_31 = 1 ;
return NULL ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ! V_2 || F_5 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_1 * V_26 ,
struct V_1 * * V_24 )
{
struct V_1 * V_32 ;
while ( F_21 ( V_2 ) && V_2 != * V_24 ) {
if ( V_26 -> V_4 == V_2 ) {
V_32 = V_26 -> V_5 ;
if ( F_4 ( V_32 ) ) {
V_32 -> V_6 = V_8 ;
V_26 -> V_6 = V_7 ;
F_15 ( V_26 , V_24 ) ;
V_32 = V_26 -> V_5 ;
}
if ( F_21 ( V_32 -> V_4 ) &&
F_21 ( V_32 -> V_5 ) ) {
V_32 -> V_6 = V_7 ;
V_2 = V_26 ;
V_26 = V_2 -> V_3 ;
} else {
if ( F_21 ( V_32 -> V_5 ) ) {
struct V_1 * V_33 ;
V_33 = V_32 -> V_4 ;
if ( V_33 )
V_33 -> V_6 = V_8 ;
V_32 -> V_6 = V_7 ;
F_16 ( V_32 , V_24 ) ;
V_32 = V_26 -> V_5 ;
}
V_32 -> V_6 = V_26 -> V_6 ;
V_26 -> V_6 = V_8 ;
if ( V_32 -> V_5 )
V_32 -> V_5 -> V_6 = V_8 ;
F_15 ( V_26 , V_24 ) ;
V_2 = * V_24 ;
break;
}
} else {
V_32 = V_26 -> V_4 ;
if ( F_4 ( V_32 ) ) {
V_32 -> V_6 = V_8 ;
V_26 -> V_6 = V_7 ;
F_16 ( V_26 , V_24 ) ;
V_32 = V_26 -> V_4 ;
}
if ( F_21 ( V_32 -> V_4 ) &&
F_21 ( V_32 -> V_5 ) ) {
V_32 -> V_6 = V_7 ;
V_2 = V_26 ;
V_26 = V_2 -> V_3 ;
} else {
if ( F_21 ( V_32 -> V_4 ) ) {
struct V_1 * V_34 ;
V_34 = V_32 -> V_5 ;
if ( V_34 )
V_34 -> V_6 = V_8 ;
V_32 -> V_6 = V_7 ;
F_15 ( V_32 , V_24 ) ;
V_32 = V_26 -> V_4 ;
}
V_32 -> V_6 = V_26 -> V_6 ;
V_26 -> V_6 = V_8 ;
if ( V_32 -> V_4 )
V_32 -> V_4 -> V_6 = V_8 ;
F_16 ( V_26 , V_24 ) ;
V_2 = * V_24 ;
break;
}
}
}
if ( V_2 )
V_2 -> V_6 = V_8 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_35 )
{
T_1 V_21 , V_22 ;
while ( V_2 ) {
V_21 = V_2 -> V_4 ? V_2 -> V_4 -> V_23 : 0 ;
V_22 = V_2 -> V_5 ? V_2 -> V_5 -> V_23 : 0 ;
V_2 -> V_23 = F_10 ( F_14 ( V_2 ) ,
F_10 ( V_21 , V_22 ) ) ;
if ( V_2 -> V_23 >= V_35 )
break;
V_2 = V_2 -> V_3 ;
}
}
void F_24 ( struct V_1 * V_2 ,
struct V_1 * * V_24 )
{
struct V_1 * V_36 , * V_26 ;
int V_37 ;
F_2 ( F_20 ( V_2 ) ) ;
V_2 -> V_31 = 0 ;
if ( ! V_2 -> V_4 ) {
V_36 = V_2 -> V_5 ;
} else if ( ! V_2 -> V_5 ) {
V_36 = V_2 -> V_4 ;
} else {
struct V_1 * V_38 = V_2 ;
V_2 = F_12 ( V_2 ) ;
V_36 = V_2 -> V_5 ;
V_26 = V_2 -> V_3 ;
V_37 = V_2 -> V_6 ;
if ( V_36 )
V_36 -> V_3 = V_26 ;
if ( V_26 == V_38 )
V_26 -> V_5 = V_36 ;
else
V_26 -> V_4 = V_36 ;
V_2 -> V_6 = V_38 -> V_6 ;
V_2 -> V_5 = V_38 -> V_5 ;
V_2 -> V_4 = V_38 -> V_4 ;
V_2 -> V_3 = V_38 -> V_3 ;
if ( V_38 -> V_3 ) {
if ( F_1 ( V_38 ) )
V_38 -> V_3 -> V_4 = V_2 ;
else
V_38 -> V_3 -> V_5 = V_2 ;
} else {
* V_24 = V_2 ;
}
V_38 -> V_4 -> V_3 = V_2 ;
if ( V_38 -> V_5 )
V_38 -> V_5 -> V_3 = V_2 ;
F_23 ( V_36 ? : V_26 , V_2 -> V_23 ) ;
F_23 ( V_2 , V_38 -> V_23 ) ;
if ( V_26 == V_38 )
V_26 = V_2 ;
goto V_37;
}
V_26 = V_2 -> V_3 ;
V_37 = V_2 -> V_6 ;
if ( V_36 )
V_36 -> V_3 = V_26 ;
if ( V_26 ) {
if ( F_1 ( V_2 ) )
V_26 -> V_4 = V_36 ;
else
V_26 -> V_5 = V_36 ;
} else {
* V_24 = V_36 ;
}
F_23 ( V_36 ? : V_26 , V_2 -> V_23 ) ;
V_37:
if ( V_37 == V_8 )
F_22 ( V_36 , V_26 , V_24 ) ;
}
