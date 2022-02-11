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
while ( V_2 -> V_5 )
V_2 = V_2 -> V_5 ;
return V_2 ;
}
static struct V_1 * F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_5 )
return F_9 ( V_2 -> V_5 ) ;
while ( V_2 -> V_3 && F_2 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
static struct V_1 * F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_4 )
return F_10 ( V_2 -> V_4 ) ;
while ( V_2 -> V_3 && F_1 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
enum V_18 F_13 ( struct V_1 * V_19 ,
T_1 V_20 ,
void * V_21 )
{
enum V_18 V_12 = V_22 ;
struct V_1 * V_2 ;
for ( V_2 = F_10 ( V_19 ) ; V_2 ; V_2 = F_12 ( V_2 ) ) {
V_12 = V_20 ( V_2 , V_21 ) ;
if ( V_12 == V_23 )
break;
}
return V_12 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_1 * V_24 )
{
T_2 V_25 , V_26 ;
V_24 -> V_27 = V_2 -> V_27 ;
V_25 = V_2 -> V_4 ? V_2 -> V_4 -> V_27 : 0 ;
V_26 = V_2 -> V_5 ? V_2 -> V_5 -> V_27 : 0 ;
V_2 -> V_27 = F_15 ( F_16 ( V_2 ) ,
F_15 ( V_25 , V_26 ) ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_1 * * V_19 )
{
struct V_1 * V_28 = V_2 -> V_5 ;
struct V_1 * V_29 = V_2 -> V_3 ;
V_2 -> V_5 = V_28 -> V_4 ;
if ( V_2 -> V_5 )
V_28 -> V_4 -> V_3 = V_2 ;
V_28 -> V_4 = V_2 ;
V_28 -> V_3 = V_29 ;
if ( V_29 ) {
if ( F_1 ( V_2 ) )
V_29 -> V_4 = V_28 ;
else
V_29 -> V_5 = V_28 ;
} else {
* V_19 = V_28 ;
}
V_2 -> V_3 = V_28 ;
F_14 ( V_2 , V_28 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_1 * * V_19 )
{
struct V_1 * V_30 = V_2 -> V_4 ;
struct V_1 * V_29 = V_2 -> V_3 ;
V_2 -> V_4 = V_30 -> V_5 ;
if ( V_2 -> V_4 )
V_30 -> V_5 -> V_3 = V_2 ;
V_30 -> V_5 = V_2 ;
V_30 -> V_3 = V_29 ;
if ( V_29 ) {
if ( F_2 ( V_2 ) )
V_29 -> V_5 = V_30 ;
else
V_29 -> V_4 = V_30 ;
} else {
* V_19 = V_30 ;
}
V_2 -> V_3 = V_30 ;
F_14 ( V_2 , V_30 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_1 * * V_19 )
{
struct V_1 * V_29 , * V_31 ;
while ( ( V_29 = V_2 -> V_3 ) && F_3 ( V_29 ) ) {
V_31 = V_29 -> V_3 ;
if ( F_1 ( V_29 ) ) {
struct V_1 * V_32 ;
V_32 = V_31 -> V_5 ;
if ( V_32 && F_3 ( V_32 ) ) {
V_32 -> V_6 = V_8 ;
V_29 -> V_6 = V_8 ;
V_31 -> V_6 = V_7 ;
V_2 = V_31 ;
continue;
}
if ( V_29 -> V_5 == V_2 ) {
F_17 ( V_29 , V_19 ) ;
F_20 ( V_2 , V_29 ) ;
}
V_29 -> V_6 = V_8 ;
V_31 -> V_6 = V_7 ;
F_18 ( V_31 , V_19 ) ;
} else {
struct V_1 * V_32 ;
V_32 = V_31 -> V_4 ;
if ( V_32 && F_3 ( V_32 ) ) {
V_32 -> V_6 = V_8 ;
V_29 -> V_6 = V_8 ;
V_31 -> V_6 = V_7 ;
V_2 = V_31 ;
continue;
}
if ( F_1 ( V_2 ) ) {
F_18 ( V_29 , V_19 ) ;
F_20 ( V_2 , V_29 ) ;
}
V_29 -> V_6 = V_8 ;
V_31 -> V_6 = V_7 ;
F_17 ( V_31 , V_19 ) ;
}
}
( * V_19 ) -> V_6 = V_8 ;
}
struct V_1 * F_21 ( struct V_1 * V_2 ,
struct V_1 * * V_19 )
{
struct V_1 * * V_33 , * V_29 = NULL ;
F_22 ( ! F_23 ( V_2 ) ) ;
V_33 = V_19 ;
while ( * V_33 ) {
V_29 = * V_33 ;
if ( F_8 ( V_29 , V_2 ) )
return V_29 ;
if ( V_29 -> V_27 < F_16 ( V_2 ) )
V_29 -> V_27 = F_16 ( V_2 ) ;
if ( F_5 ( & V_2 -> V_17 , & V_29 -> V_17 ) < 0 )
V_33 = & V_29 -> V_4 ;
else
V_33 = & V_29 -> V_5 ;
}
V_2 -> V_3 = V_29 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
* V_33 = V_2 ;
F_19 ( V_2 , V_19 ) ;
V_2 -> V_34 = 1 ;
return NULL ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
return ! V_2 || F_4 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_1 * V_29 ,
struct V_1 * * V_19 )
{
struct V_1 * V_35 ;
while ( F_24 ( V_2 ) && V_2 != * V_19 ) {
if ( V_29 -> V_4 == V_2 ) {
V_35 = V_29 -> V_5 ;
if ( F_3 ( V_35 ) ) {
V_35 -> V_6 = V_8 ;
V_29 -> V_6 = V_7 ;
F_17 ( V_29 , V_19 ) ;
V_35 = V_29 -> V_5 ;
}
if ( F_24 ( V_35 -> V_4 ) &&
F_24 ( V_35 -> V_5 ) ) {
V_35 -> V_6 = V_7 ;
V_2 = V_29 ;
V_29 = V_2 -> V_3 ;
} else {
if ( F_24 ( V_35 -> V_5 ) ) {
struct V_1 * V_36 ;
V_36 = V_35 -> V_4 ;
if ( V_36 )
V_36 -> V_6 = V_8 ;
V_35 -> V_6 = V_7 ;
F_18 ( V_35 , V_19 ) ;
V_35 = V_29 -> V_5 ;
}
V_35 -> V_6 = V_29 -> V_6 ;
V_29 -> V_6 = V_8 ;
if ( V_35 -> V_5 )
V_35 -> V_5 -> V_6 = V_8 ;
F_17 ( V_29 , V_19 ) ;
V_2 = * V_19 ;
break;
}
} else {
V_35 = V_29 -> V_4 ;
if ( F_3 ( V_35 ) ) {
V_35 -> V_6 = V_8 ;
V_29 -> V_6 = V_7 ;
F_18 ( V_29 , V_19 ) ;
V_35 = V_29 -> V_4 ;
}
if ( F_24 ( V_35 -> V_4 ) &&
F_24 ( V_35 -> V_5 ) ) {
V_35 -> V_6 = V_7 ;
V_2 = V_29 ;
V_29 = V_2 -> V_3 ;
} else {
if ( F_24 ( V_35 -> V_4 ) ) {
struct V_1 * V_37 ;
V_37 = V_35 -> V_5 ;
if ( V_37 )
V_37 -> V_6 = V_8 ;
V_35 -> V_6 = V_7 ;
F_17 ( V_35 , V_19 ) ;
V_35 = V_29 -> V_4 ;
}
V_35 -> V_6 = V_29 -> V_6 ;
V_29 -> V_6 = V_8 ;
if ( V_35 -> V_4 )
V_35 -> V_4 -> V_6 = V_8 ;
F_18 ( V_29 , V_19 ) ;
V_2 = * V_19 ;
break;
}
}
}
if ( V_2 )
V_2 -> V_6 = V_8 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_2 V_38 )
{
T_2 V_25 , V_26 ;
while ( V_2 ) {
V_25 = V_2 -> V_4 ? V_2 -> V_4 -> V_27 : 0 ;
V_26 = V_2 -> V_5 ? V_2 -> V_5 -> V_27 : 0 ;
V_2 -> V_27 = F_15 ( F_16 ( V_2 ) ,
F_15 ( V_25 , V_26 ) ) ;
if ( V_2 -> V_27 >= V_38 )
break;
V_2 = V_2 -> V_3 ;
}
}
void F_27 ( struct V_1 * V_2 ,
struct V_1 * * V_19 )
{
struct V_1 * V_39 , * V_29 ;
int V_40 ;
F_22 ( F_23 ( V_2 ) ) ;
V_2 -> V_34 = 0 ;
if ( ! V_2 -> V_4 ) {
V_39 = V_2 -> V_5 ;
} else if ( ! V_2 -> V_5 ) {
V_39 = V_2 -> V_4 ;
} else {
struct V_1 * V_41 = V_2 ;
V_2 = F_11 ( V_2 ) ;
V_39 = V_2 -> V_5 ;
V_29 = V_2 -> V_3 ;
V_40 = V_2 -> V_6 ;
if ( V_39 )
V_39 -> V_3 = V_29 ;
if ( V_29 == V_41 )
V_29 -> V_5 = V_39 ;
else
V_29 -> V_4 = V_39 ;
V_2 -> V_6 = V_41 -> V_6 ;
V_2 -> V_5 = V_41 -> V_5 ;
V_2 -> V_4 = V_41 -> V_4 ;
V_2 -> V_3 = V_41 -> V_3 ;
if ( V_41 -> V_3 ) {
if ( F_1 ( V_41 ) )
V_41 -> V_3 -> V_4 = V_2 ;
else
V_41 -> V_3 -> V_5 = V_2 ;
} else {
* V_19 = V_2 ;
}
V_41 -> V_4 -> V_3 = V_2 ;
if ( V_41 -> V_5 )
V_41 -> V_5 -> V_3 = V_2 ;
F_26 ( V_39 ? : V_29 , V_2 -> V_27 ) ;
F_26 ( V_2 , V_41 -> V_27 ) ;
if ( V_29 == V_41 )
V_29 = V_2 ;
goto V_40;
}
V_29 = V_2 -> V_3 ;
V_40 = V_2 -> V_6 ;
if ( V_39 )
V_39 -> V_3 = V_29 ;
if ( V_29 ) {
if ( F_1 ( V_2 ) )
V_29 -> V_4 = V_39 ;
else
V_29 -> V_5 = V_39 ;
} else {
* V_19 = V_39 ;
}
F_26 ( V_39 ? : V_29 , V_2 -> V_27 ) ;
V_40:
if ( V_40 == V_8 )
F_25 ( V_39 , V_29 , V_19 ) ;
}
static inline int F_28 ( struct V_1 * V_2 ,
struct V_9 * V_42 )
{
return ( V_42 -> V_13 <= V_2 -> V_27 &&
V_42 -> V_14 >= F_29 ( V_2 ) ) ;
}
enum V_18 F_30 ( struct V_1 * V_2 ,
struct V_9 * V_42 ,
T_1 V_20 ,
void * V_21 )
{
enum V_18 V_12 = V_22 ;
struct V_1 * V_29 ;
F_22 ( V_42 ) ;
F_22 ( V_20 ) ;
while ( V_2 ) {
if ( V_42 -> V_14 < F_29 ( V_2 ) ) {
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_4 ;
continue;
}
} else if ( F_28 ( V_2 , V_42 ) ) {
if ( F_7 ( V_42 , & V_2 -> V_17 ) ) {
V_12 = V_20 ( V_2 , V_21 ) ;
if ( V_12 == V_23 )
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
V_29 = V_2 -> V_3 ;
while ( V_29 ) {
if ( F_1 ( V_2 ) &&
V_29 -> V_5 ) {
V_2 = V_29 -> V_5 ;
break;
}
V_2 = V_29 ;
V_29 = V_29 -> V_3 ;
}
if ( ! V_29 || ! F_28 ( V_29 , V_42 ) )
break;
}
return V_12 ;
}
