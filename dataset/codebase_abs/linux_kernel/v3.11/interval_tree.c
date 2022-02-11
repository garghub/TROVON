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
V_20 ;
if ( ! V_2 )
RETURN ( NULL ) ;
while ( V_2 -> V_4 )
V_2 = V_2 -> V_4 ;
RETURN ( V_2 ) ;
}
static struct V_1 * F_14 ( struct V_1 * V_2 )
{
V_20 ;
if ( ! V_2 )
RETURN ( NULL ) ;
while ( V_2 -> V_5 )
V_2 = V_2 -> V_5 ;
RETURN ( V_2 ) ;
}
static struct V_1 * F_15 ( struct V_1 * V_2 )
{
V_20 ;
if ( ! V_2 )
RETURN ( NULL ) ;
if ( V_2 -> V_5 )
RETURN ( F_13 ( V_2 -> V_5 ) ) ;
while ( V_2 -> V_3 && F_3 ( V_2 ) )
V_2 = V_2 -> V_3 ;
RETURN ( V_2 -> V_3 ) ;
}
static struct V_1 * F_16 ( struct V_1 * V_2 )
{
V_20 ;
if ( ! V_2 )
RETURN ( NULL ) ;
if ( V_2 -> V_4 )
RETURN ( F_14 ( V_2 -> V_4 ) ) ;
while ( V_2 -> V_3 && F_1 ( V_2 ) )
V_2 = V_2 -> V_3 ;
RETURN ( V_2 -> V_3 ) ;
}
enum V_21 F_17 ( struct V_1 * V_22 ,
T_2 V_23 ,
void * V_24 )
{
struct V_1 * V_2 ;
enum V_21 V_12 = V_25 ;
V_20 ;
F_18 (node, root) {
V_12 = V_23 ( V_2 , V_24 ) ;
if ( V_12 == V_26 )
break;
}
RETURN ( V_12 ) ;
}
enum V_21 F_19 ( struct V_1 * V_22 ,
T_2 V_23 ,
void * V_24 )
{
struct V_1 * V_2 ;
enum V_21 V_12 = V_25 ;
V_20 ;
F_20 (node, root) {
V_12 = V_23 ( V_2 , V_24 ) ;
if ( V_12 == V_26 )
break;
}
RETURN ( V_12 ) ;
}
struct V_1 * F_21 ( struct V_1 * V_22 ,
struct V_9 * V_27 )
{
struct V_1 * V_28 = V_22 ;
int V_12 ;
V_20 ;
while ( V_28 ) {
V_12 = F_6 ( V_27 , & V_28 -> V_17 ) ;
if ( V_12 == 0 )
break;
else if ( V_12 < 0 )
V_28 = V_28 -> V_4 ;
else
V_28 = V_28 -> V_5 ;
}
RETURN ( V_28 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_1 * V_29 )
{
T_1 V_30 , V_31 ;
V_29 -> V_32 = V_2 -> V_32 ;
V_30 = V_2 -> V_4 ? V_2 -> V_4 -> V_32 : 0 ;
V_31 = V_2 -> V_5 ? V_2 -> V_5 -> V_32 : 0 ;
V_2 -> V_32 = F_11 ( F_23 ( V_2 ) ,
F_11 ( V_30 , V_31 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_33 = V_2 -> V_5 ;
struct V_1 * V_34 = V_2 -> V_3 ;
V_2 -> V_5 = V_33 -> V_4 ;
if ( V_2 -> V_5 )
V_33 -> V_4 -> V_3 = V_2 ;
V_33 -> V_4 = V_2 ;
V_33 -> V_3 = V_34 ;
if ( V_34 ) {
if ( F_1 ( V_2 ) )
V_34 -> V_4 = V_33 ;
else
V_34 -> V_5 = V_33 ;
} else {
* V_22 = V_33 ;
}
V_2 -> V_3 = V_33 ;
F_22 ( V_2 , V_33 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_35 = V_2 -> V_4 ;
struct V_1 * V_34 = V_2 -> V_3 ;
V_2 -> V_4 = V_35 -> V_5 ;
if ( V_2 -> V_4 )
V_35 -> V_5 -> V_3 = V_2 ;
V_35 -> V_5 = V_2 ;
V_35 -> V_3 = V_34 ;
if ( V_34 ) {
if ( F_3 ( V_2 ) )
V_34 -> V_5 = V_35 ;
else
V_34 -> V_4 = V_35 ;
} else {
* V_22 = V_35 ;
}
V_2 -> V_3 = V_35 ;
F_22 ( V_2 , V_35 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_34 , * V_36 ;
V_20 ;
while ( ( V_34 = V_2 -> V_3 ) && F_4 ( V_34 ) ) {
V_36 = V_34 -> V_3 ;
if ( F_1 ( V_34 ) ) {
struct V_1 * V_37 ;
V_37 = V_36 -> V_5 ;
if ( V_37 && F_4 ( V_37 ) ) {
V_37 -> V_6 = V_8 ;
V_34 -> V_6 = V_8 ;
V_36 -> V_6 = V_7 ;
V_2 = V_36 ;
continue;
}
if ( V_34 -> V_5 == V_2 ) {
F_24 ( V_34 , V_22 ) ;
F_27 ( V_2 , V_34 ) ;
}
V_34 -> V_6 = V_8 ;
V_36 -> V_6 = V_7 ;
F_25 ( V_36 , V_22 ) ;
} else {
struct V_1 * V_37 ;
V_37 = V_36 -> V_4 ;
if ( V_37 && F_4 ( V_37 ) ) {
V_37 -> V_6 = V_8 ;
V_34 -> V_6 = V_8 ;
V_36 -> V_6 = V_7 ;
V_2 = V_36 ;
continue;
}
if ( F_1 ( V_2 ) ) {
F_25 ( V_34 , V_22 ) ;
F_27 ( V_2 , V_34 ) ;
}
V_34 -> V_6 = V_8 ;
V_36 -> V_6 = V_7 ;
F_24 ( V_36 , V_22 ) ;
}
}
( * V_22 ) -> V_6 = V_8 ;
EXIT ;
}
struct V_1 * F_28 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * * V_38 , * V_34 = NULL ;
V_20 ;
F_2 ( ! F_29 ( V_2 ) ) ;
V_38 = V_22 ;
while ( * V_38 ) {
V_34 = * V_38 ;
if ( F_10 ( V_34 , V_2 ) )
RETURN ( V_34 ) ;
if ( V_34 -> V_32 < F_23 ( V_2 ) )
V_34 -> V_32 = F_23 ( V_2 ) ;
if ( F_9 ( V_2 , V_34 ) < 0 )
V_38 = & V_34 -> V_4 ;
else
V_38 = & V_34 -> V_5 ;
}
V_2 -> V_3 = V_34 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = V_2 -> V_5 = NULL ;
* V_38 = V_2 ;
F_26 ( V_2 , V_22 ) ;
V_2 -> V_39 = 1 ;
RETURN ( NULL ) ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
return ! V_2 || F_5 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_1 * V_34 ,
struct V_1 * * V_22 )
{
struct V_1 * V_40 ;
V_20 ;
while ( F_30 ( V_2 ) && V_2 != * V_22 ) {
if ( V_34 -> V_4 == V_2 ) {
V_40 = V_34 -> V_5 ;
if ( F_4 ( V_40 ) ) {
V_40 -> V_6 = V_8 ;
V_34 -> V_6 = V_7 ;
F_24 ( V_34 , V_22 ) ;
V_40 = V_34 -> V_5 ;
}
if ( F_30 ( V_40 -> V_4 ) &&
F_30 ( V_40 -> V_5 ) ) {
V_40 -> V_6 = V_7 ;
V_2 = V_34 ;
V_34 = V_2 -> V_3 ;
} else {
if ( F_30 ( V_40 -> V_5 ) ) {
struct V_1 * V_41 ;
if ( ( V_41 = V_40 -> V_4 ) )
V_41 -> V_6 = V_8 ;
V_40 -> V_6 = V_7 ;
F_25 ( V_40 , V_22 ) ;
V_40 = V_34 -> V_5 ;
}
V_40 -> V_6 = V_34 -> V_6 ;
V_34 -> V_6 = V_8 ;
if ( V_40 -> V_5 )
V_40 -> V_5 -> V_6 = V_8 ;
F_24 ( V_34 , V_22 ) ;
V_2 = * V_22 ;
break;
}
} else {
V_40 = V_34 -> V_4 ;
if ( F_4 ( V_40 ) ) {
V_40 -> V_6 = V_8 ;
V_34 -> V_6 = V_7 ;
F_25 ( V_34 , V_22 ) ;
V_40 = V_34 -> V_4 ;
}
if ( F_30 ( V_40 -> V_4 ) &&
F_30 ( V_40 -> V_5 ) ) {
V_40 -> V_6 = V_7 ;
V_2 = V_34 ;
V_34 = V_2 -> V_3 ;
} else {
if ( F_30 ( V_40 -> V_4 ) ) {
struct V_1 * V_42 ;
if ( ( V_42 = V_40 -> V_5 ) )
V_42 -> V_6 = V_8 ;
V_40 -> V_6 = V_7 ;
F_24 ( V_40 , V_22 ) ;
V_40 = V_34 -> V_4 ;
}
V_40 -> V_6 = V_34 -> V_6 ;
V_34 -> V_6 = V_8 ;
if ( V_40 -> V_4 )
V_40 -> V_4 -> V_6 = V_8 ;
F_25 ( V_34 , V_22 ) ;
V_2 = * V_22 ;
break;
}
}
}
if ( V_2 )
V_2 -> V_6 = V_8 ;
EXIT ;
}
static void F_32 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_1 V_30 , V_31 ;
V_20 ;
while ( V_2 ) {
V_30 = V_2 -> V_4 ? V_2 -> V_4 -> V_32 : 0 ;
V_31 = V_2 -> V_5 ? V_2 -> V_5 -> V_32 : 0 ;
V_2 -> V_32 = F_11 ( F_23 ( V_2 ) ,
F_11 ( V_30 , V_31 ) ) ;
if ( V_2 -> V_32 >= V_43 )
break;
V_2 = V_2 -> V_3 ;
}
EXIT ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_1 * * V_22 )
{
struct V_1 * V_44 , * V_34 ;
int V_45 ;
V_20 ;
F_2 ( F_29 ( V_2 ) ) ;
V_2 -> V_39 = 0 ;
if ( ! V_2 -> V_4 ) {
V_44 = V_2 -> V_5 ;
} else if ( ! V_2 -> V_5 ) {
V_44 = V_2 -> V_4 ;
} else {
struct V_1 * V_46 = V_2 ;
V_2 = F_15 ( V_2 ) ;
V_44 = V_2 -> V_5 ;
V_34 = V_2 -> V_3 ;
V_45 = V_2 -> V_6 ;
if ( V_44 )
V_44 -> V_3 = V_34 ;
if ( V_34 == V_46 )
V_34 -> V_5 = V_44 ;
else
V_34 -> V_4 = V_44 ;
V_2 -> V_6 = V_46 -> V_6 ;
V_2 -> V_5 = V_46 -> V_5 ;
V_2 -> V_4 = V_46 -> V_4 ;
V_2 -> V_3 = V_46 -> V_3 ;
if ( V_46 -> V_3 ) {
if ( F_1 ( V_46 ) )
V_46 -> V_3 -> V_4 = V_2 ;
else
V_46 -> V_3 -> V_5 = V_2 ;
} else {
* V_22 = V_2 ;
}
V_46 -> V_4 -> V_3 = V_2 ;
if ( V_46 -> V_5 )
V_46 -> V_5 -> V_3 = V_2 ;
F_32 ( V_44 ? : V_34 , V_2 -> V_32 ) ;
F_32 ( V_2 , V_46 -> V_32 ) ;
if ( V_34 == V_46 )
V_34 = V_2 ;
goto V_45;
}
V_34 = V_2 -> V_3 ;
V_45 = V_2 -> V_6 ;
if ( V_44 )
V_44 -> V_3 = V_34 ;
if ( V_34 ) {
if ( F_1 ( V_2 ) )
V_34 -> V_4 = V_44 ;
else
V_34 -> V_5 = V_44 ;
} else {
* V_22 = V_44 ;
}
F_32 ( V_44 ? : V_34 , V_2 -> V_32 ) ;
V_45:
if ( V_45 == V_8 )
F_31 ( V_44 , V_34 , V_22 ) ;
EXIT ;
}
static inline int F_34 ( struct V_1 * V_2 ,
struct V_9 * V_47 )
{
return ( V_47 -> V_13 <= V_2 -> V_32 &&
V_47 -> V_14 >= F_35 ( V_2 ) ) ;
}
enum V_21 F_36 ( struct V_1 * V_2 ,
struct V_9 * V_47 ,
T_2 V_23 ,
void * V_24 )
{
struct V_1 * V_34 ;
enum V_21 V_12 = V_25 ;
F_2 ( V_47 != NULL ) ;
F_2 ( V_23 != NULL ) ;
while ( V_2 ) {
if ( V_47 -> V_14 < F_35 ( V_2 ) ) {
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_4 ;
continue;
}
} else if ( F_34 ( V_2 , V_47 ) ) {
if ( F_8 ( V_47 , & V_2 -> V_17 ) ) {
V_12 = V_23 ( V_2 , V_24 ) ;
if ( V_12 == V_26 )
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
V_34 = V_2 -> V_3 ;
while ( V_34 ) {
if ( F_1 ( V_2 ) &&
V_34 -> V_5 ) {
V_2 = V_34 -> V_5 ;
break;
}
V_2 = V_34 ;
V_34 = V_34 -> V_3 ;
}
if ( V_34 == NULL || ! F_34 ( V_34 , V_47 ) )
break;
}
return V_12 ;
}
static enum V_21 F_37 ( struct V_1 * V_48 ,
void * args )
{
* ( int * ) args = 1 ;
return V_26 ;
}
int F_38 ( struct V_1 * V_22 ,
struct V_9 * V_47 )
{
int V_49 = 0 ;
( void ) F_36 ( V_22 , V_47 , F_37 , & V_49 ) ;
return V_49 ;
}
static inline T_1 F_39 ( struct V_1 * V_22 , T_1 V_50 )
{
if ( V_22 == NULL )
return 0 ;
return V_50 ;
}
static inline T_1 F_40 ( struct V_1 * V_2 , T_1 V_51 )
{
T_1 V_52 = ~ 0 ;
while ( V_2 != NULL ) {
if ( V_2 -> V_32 < V_51 )
break;
if ( F_35 ( V_2 ) > V_51 ) {
V_52 = F_35 ( V_2 ) - 1 ;
V_2 = V_2 -> V_4 ;
} else {
V_2 = V_2 -> V_5 ;
}
}
return V_52 ;
}
void F_41 ( struct V_1 * V_22 ,
struct V_9 * V_47 ,
struct V_9 * V_53 )
{
F_2 ( F_38 ( V_22 , V_47 ) == 0 ) ;
if ( ! V_53 || V_53 -> V_13 < V_47 -> V_13 )
V_47 -> V_13 = F_39 ( V_22 , V_47 -> V_13 ) ;
if ( ! V_53 || V_53 -> V_14 > V_47 -> V_14 )
V_47 -> V_14 = F_40 ( V_22 , V_47 -> V_14 ) ;
F_2 ( F_38 ( V_22 , V_47 ) == 0 ) ;
}
