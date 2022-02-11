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
static inline int F_8 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
return ( V_10 -> V_13 <= V_11 -> V_14 ) && ( V_11 -> V_13 <= V_10 -> V_14 ) ;
}
static inline int F_9 ( struct V_1 * V_15 ,
struct V_1 * V_16 )
{
return F_6 ( & V_15 -> V_17 , & V_16 -> V_17 ) ;
}
static inline int F_10 ( struct V_1 * V_15 ,
struct V_1 * V_16 )
{
return F_7 ( & V_15 -> V_17 , & V_16 -> V_17 ) ;
}
static inline T_1 F_11 ( T_1 V_18 , T_1 V_19 )
{
return V_18 > V_19 ? V_18 : V_19 ;
}
static inline T_1 F_12 ( T_1 V_18 , T_1 V_19 )
{
return V_18 < V_19 ? V_18 : V_19 ;
}
static struct V_1 * F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
while ( V_2 -> V_4 )
V_2 = V_2 -> V_4 ;
return V_2 ;
}
static struct V_1 * F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
while ( V_2 -> V_5 )
V_2 = V_2 -> V_5 ;
return V_2 ;
}
static struct V_1 * F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_5 )
return F_13 ( V_2 -> V_5 ) ;
while ( V_2 -> V_3 && F_3 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
static struct V_1 * F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_4 )
return F_14 ( V_2 -> V_4 ) ;
while ( V_2 -> V_3 && F_1 ( V_2 ) )
V_2 = V_2 -> V_3 ;
return V_2 -> V_3 ;
}
enum V_20 F_17 ( struct V_1 * V_21 ,
T_2 V_22 ,
void * V_23 )
{
struct V_1 * V_2 ;
enum V_20 V_12 = V_24 ;
F_18 (node, root) {
V_12 = V_22 ( V_2 , V_23 ) ;
if ( V_12 == V_25 )
break;
}
return V_12 ;
}
enum V_20 F_19 ( struct V_1 * V_21 ,
T_2 V_22 ,
void * V_23 )
{
struct V_1 * V_2 ;
enum V_20 V_12 = V_24 ;
F_20 (node, root) {
V_12 = V_22 ( V_2 , V_23 ) ;
if ( V_12 == V_25 )
break;
}
return V_12 ;
}
struct V_1 * F_21 ( struct V_1 * V_21 ,
struct V_9 * V_26 )
{
struct V_1 * V_27 = V_21 ;
int V_12 ;
while ( V_27 ) {
V_12 = F_6 ( V_26 , & V_27 -> V_17 ) ;
if ( V_12 == 0 )
break;
else if ( V_12 < 0 )
V_27 = V_27 -> V_4 ;
else
V_27 = V_27 -> V_5 ;
}
return V_27 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_1 * V_28 )
{
T_1 V_29 , V_30 ;
V_28 -> V_31 = V_2 -> V_31 ;
V_29 = V_2 -> V_4 ? V_2 -> V_4 -> V_31 : 0 ;
V_30 = V_2 -> V_5 ? V_2 -> V_5 -> V_31 : 0 ;
V_2 -> V_31 = F_11 ( F_23 ( V_2 ) ,
F_11 ( V_29 , V_30 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_32 = V_2 -> V_5 ;
struct V_1 * V_33 = V_2 -> V_3 ;
V_2 -> V_5 = V_32 -> V_4 ;
if ( V_2 -> V_5 )
V_32 -> V_4 -> V_3 = V_2 ;
V_32 -> V_4 = V_2 ;
V_32 -> V_3 = V_33 ;
if ( V_33 ) {
if ( F_1 ( V_2 ) )
V_33 -> V_4 = V_32 ;
else
V_33 -> V_5 = V_32 ;
} else {
* V_21 = V_32 ;
}
V_2 -> V_3 = V_32 ;
F_22 ( V_2 , V_32 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_34 = V_2 -> V_4 ;
struct V_1 * V_33 = V_2 -> V_3 ;
V_2 -> V_4 = V_34 -> V_5 ;
if ( V_2 -> V_4 )
V_34 -> V_5 -> V_3 = V_2 ;
V_34 -> V_5 = V_2 ;
V_34 -> V_3 = V_33 ;
if ( V_33 ) {
if ( F_3 ( V_2 ) )
V_33 -> V_5 = V_34 ;
else
V_33 -> V_4 = V_34 ;
} else {
* V_21 = V_34 ;
}
V_2 -> V_3 = V_34 ;
F_22 ( V_2 , V_34 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_33 , * V_35 ;
while ( ( V_33 = V_2 -> V_3 ) && F_4 ( V_33 ) ) {
V_35 = V_33 -> V_3 ;
if ( F_1 ( V_33 ) ) {
struct V_1 * V_36 ;
V_36 = V_35 -> V_5 ;
if ( V_36 && F_4 ( V_36 ) ) {
V_36 -> V_6 = V_8 ;
V_33 -> V_6 = V_8 ;
V_35 -> V_6 = V_7 ;
V_2 = V_35 ;
continue;
}
if ( V_33 -> V_5 == V_2 ) {
F_24 ( V_33 , V_21 ) ;
F_27 ( V_2 , V_33 ) ;
}
V_33 -> V_6 = V_8 ;
V_35 -> V_6 = V_7 ;
F_25 ( V_35 , V_21 ) ;
} else {
struct V_1 * V_36 ;
V_36 = V_35 -> V_4 ;
if ( V_36 && F_4 ( V_36 ) ) {
V_36 -> V_6 = V_8 ;
V_33 -> V_6 = V_8 ;
V_35 -> V_6 = V_7 ;
V_2 = V_35 ;
continue;
}
if ( F_1 ( V_2 ) ) {
F_25 ( V_33 , V_21 ) ;
F_27 ( V_2 , V_33 ) ;
}
V_33 -> V_6 = V_8 ;
V_35 -> V_6 = V_7 ;
F_24 ( V_35 , V_21 ) ;
}
}
( * V_21 ) -> V_6 = V_8 ;
}
struct V_1 * F_28 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * * V_37 , * V_33 = NULL ;
F_2 ( ! F_29 ( V_2 ) ) ;
V_37 = V_21 ;
while ( * V_37 ) {
V_33 = * V_37 ;
if ( F_10 ( V_33 , V_2 ) )
return V_33 ;
if ( V_33 -> V_31 < F_23 ( V_2 ) )
V_33 -> V_31 = F_23 ( V_2 ) ;
if ( F_9 ( V_2 , V_33 ) < 0 )
V_37 = & V_33 -> V_4 ;
else
V_37 = & V_33 -> V_5 ;
}
V_2 -> V_3 = V_33 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = V_2 -> V_5 = NULL ;
* V_37 = V_2 ;
F_26 ( V_2 , V_21 ) ;
V_2 -> V_38 = 1 ;
return NULL ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
return ! V_2 || F_5 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_1 * V_33 ,
struct V_1 * * V_21 )
{
struct V_1 * V_39 ;
while ( F_30 ( V_2 ) && V_2 != * V_21 ) {
if ( V_33 -> V_4 == V_2 ) {
V_39 = V_33 -> V_5 ;
if ( F_4 ( V_39 ) ) {
V_39 -> V_6 = V_8 ;
V_33 -> V_6 = V_7 ;
F_24 ( V_33 , V_21 ) ;
V_39 = V_33 -> V_5 ;
}
if ( F_30 ( V_39 -> V_4 ) &&
F_30 ( V_39 -> V_5 ) ) {
V_39 -> V_6 = V_7 ;
V_2 = V_33 ;
V_33 = V_2 -> V_3 ;
} else {
if ( F_30 ( V_39 -> V_5 ) ) {
struct V_1 * V_40 ;
V_40 = V_39 -> V_4 ;
if ( V_40 )
V_40 -> V_6 = V_8 ;
V_39 -> V_6 = V_7 ;
F_25 ( V_39 , V_21 ) ;
V_39 = V_33 -> V_5 ;
}
V_39 -> V_6 = V_33 -> V_6 ;
V_33 -> V_6 = V_8 ;
if ( V_39 -> V_5 )
V_39 -> V_5 -> V_6 = V_8 ;
F_24 ( V_33 , V_21 ) ;
V_2 = * V_21 ;
break;
}
} else {
V_39 = V_33 -> V_4 ;
if ( F_4 ( V_39 ) ) {
V_39 -> V_6 = V_8 ;
V_33 -> V_6 = V_7 ;
F_25 ( V_33 , V_21 ) ;
V_39 = V_33 -> V_4 ;
}
if ( F_30 ( V_39 -> V_4 ) &&
F_30 ( V_39 -> V_5 ) ) {
V_39 -> V_6 = V_7 ;
V_2 = V_33 ;
V_33 = V_2 -> V_3 ;
} else {
if ( F_30 ( V_39 -> V_4 ) ) {
struct V_1 * V_41 ;
V_41 = V_39 -> V_5 ;
if ( V_41 )
V_41 -> V_6 = V_8 ;
V_39 -> V_6 = V_7 ;
F_24 ( V_39 , V_21 ) ;
V_39 = V_33 -> V_4 ;
}
V_39 -> V_6 = V_33 -> V_6 ;
V_33 -> V_6 = V_8 ;
if ( V_39 -> V_4 )
V_39 -> V_4 -> V_6 = V_8 ;
F_25 ( V_33 , V_21 ) ;
V_2 = * V_21 ;
break;
}
}
}
if ( V_2 )
V_2 -> V_6 = V_8 ;
}
static void F_32 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_1 V_29 , V_30 ;
while ( V_2 ) {
V_29 = V_2 -> V_4 ? V_2 -> V_4 -> V_31 : 0 ;
V_30 = V_2 -> V_5 ? V_2 -> V_5 -> V_31 : 0 ;
V_2 -> V_31 = F_11 ( F_23 ( V_2 ) ,
F_11 ( V_29 , V_30 ) ) ;
if ( V_2 -> V_31 >= V_42 )
break;
V_2 = V_2 -> V_3 ;
}
}
void F_33 ( struct V_1 * V_2 ,
struct V_1 * * V_21 )
{
struct V_1 * V_43 , * V_33 ;
int V_44 ;
F_2 ( F_29 ( V_2 ) ) ;
V_2 -> V_38 = 0 ;
if ( ! V_2 -> V_4 ) {
V_43 = V_2 -> V_5 ;
} else if ( ! V_2 -> V_5 ) {
V_43 = V_2 -> V_4 ;
} else {
struct V_1 * V_45 = V_2 ;
V_2 = F_15 ( V_2 ) ;
V_43 = V_2 -> V_5 ;
V_33 = V_2 -> V_3 ;
V_44 = V_2 -> V_6 ;
if ( V_43 )
V_43 -> V_3 = V_33 ;
if ( V_33 == V_45 )
V_33 -> V_5 = V_43 ;
else
V_33 -> V_4 = V_43 ;
V_2 -> V_6 = V_45 -> V_6 ;
V_2 -> V_5 = V_45 -> V_5 ;
V_2 -> V_4 = V_45 -> V_4 ;
V_2 -> V_3 = V_45 -> V_3 ;
if ( V_45 -> V_3 ) {
if ( F_1 ( V_45 ) )
V_45 -> V_3 -> V_4 = V_2 ;
else
V_45 -> V_3 -> V_5 = V_2 ;
} else {
* V_21 = V_2 ;
}
V_45 -> V_4 -> V_3 = V_2 ;
if ( V_45 -> V_5 )
V_45 -> V_5 -> V_3 = V_2 ;
F_32 ( V_43 ? : V_33 , V_2 -> V_31 ) ;
F_32 ( V_2 , V_45 -> V_31 ) ;
if ( V_33 == V_45 )
V_33 = V_2 ;
goto V_44;
}
V_33 = V_2 -> V_3 ;
V_44 = V_2 -> V_6 ;
if ( V_43 )
V_43 -> V_3 = V_33 ;
if ( V_33 ) {
if ( F_1 ( V_2 ) )
V_33 -> V_4 = V_43 ;
else
V_33 -> V_5 = V_43 ;
} else {
* V_21 = V_43 ;
}
F_32 ( V_43 ? : V_33 , V_2 -> V_31 ) ;
V_44:
if ( V_44 == V_8 )
F_31 ( V_43 , V_33 , V_21 ) ;
}
static inline int F_34 ( struct V_1 * V_2 ,
struct V_9 * V_46 )
{
return ( V_46 -> V_13 <= V_2 -> V_31 &&
V_46 -> V_14 >= F_35 ( V_2 ) ) ;
}
enum V_20 F_36 ( struct V_1 * V_2 ,
struct V_9 * V_46 ,
T_2 V_22 ,
void * V_23 )
{
struct V_1 * V_33 ;
enum V_20 V_12 = V_24 ;
F_2 ( V_46 != NULL ) ;
F_2 ( V_22 != NULL ) ;
while ( V_2 ) {
if ( V_46 -> V_14 < F_35 ( V_2 ) ) {
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_4 ;
continue;
}
} else if ( F_34 ( V_2 , V_46 ) ) {
if ( F_8 ( V_46 , & V_2 -> V_17 ) ) {
V_12 = V_22 ( V_2 , V_23 ) ;
if ( V_12 == V_25 )
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
V_33 = V_2 -> V_3 ;
while ( V_33 ) {
if ( F_1 ( V_2 ) &&
V_33 -> V_5 ) {
V_2 = V_33 -> V_5 ;
break;
}
V_2 = V_33 ;
V_33 = V_33 -> V_3 ;
}
if ( V_33 == NULL || ! F_34 ( V_33 , V_46 ) )
break;
}
return V_12 ;
}
static enum V_20 F_37 ( struct V_1 * V_47 ,
void * args )
{
* ( int * ) args = 1 ;
return V_25 ;
}
int F_38 ( struct V_1 * V_21 ,
struct V_9 * V_46 )
{
int V_48 = 0 ;
( void ) F_36 ( V_21 , V_46 , F_37 , & V_48 ) ;
return V_48 ;
}
static inline T_1 F_39 ( struct V_1 * V_21 , T_1 V_49 )
{
if ( V_21 == NULL )
return 0 ;
return V_49 ;
}
static inline T_1 F_40 ( struct V_1 * V_2 , T_1 V_50 )
{
T_1 V_51 = ~ 0 ;
while ( V_2 != NULL ) {
if ( V_2 -> V_31 < V_50 )
break;
if ( F_35 ( V_2 ) > V_50 ) {
V_51 = F_35 ( V_2 ) - 1 ;
V_2 = V_2 -> V_4 ;
} else {
V_2 = V_2 -> V_5 ;
}
}
return V_51 ;
}
void F_41 ( struct V_1 * V_21 ,
struct V_9 * V_46 ,
struct V_9 * V_52 )
{
F_2 ( F_38 ( V_21 , V_46 ) == 0 ) ;
if ( ! V_52 || V_52 -> V_13 < V_46 -> V_13 )
V_46 -> V_13 = F_39 ( V_21 , V_46 -> V_13 ) ;
if ( ! V_52 || V_52 -> V_14 > V_46 -> V_14 )
V_46 -> V_14 = F_40 ( V_21 , V_46 -> V_14 ) ;
F_2 ( F_38 ( V_21 , V_46 ) == 0 ) ;
}
