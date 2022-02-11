int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 , V_3 ) ;
if ( V_1 == NULL )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
if ( V_1 )
F_4 ( V_1 ) ;
}
void F_5 ( struct V_5 * V_6 )
{
V_6 -> V_7 = V_8 ;
V_6 -> V_9 = NULL ;
}
static void F_6 ( struct V_10 * V_10 )
{
struct V_5 * V_6 ;
struct V_11 * V_12 ;
F_7 ( V_13 L_1 , V_10 -> V_14 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
V_12 = F_9 ( & V_6 -> V_7 ) ;
while ( V_12 ) {
struct V_2 * V_16 ;
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
F_7 ( V_13 L_2 , V_16 -> V_17 , V_16 -> V_18 ) ;
V_12 = F_11 ( V_12 ) ;
}
F_7 ( V_13 L_3 ) ;
}
static inline T_2 F_12 ( struct V_2 * V_16 )
{
F_13 ( V_16 -> V_17 + V_16 -> V_18 < V_16 -> V_17 ) ;
return V_16 -> V_17 + V_16 -> V_18 - 1 ;
}
static struct V_2 * F_14 ( struct V_19 * V_7 ,
T_2 V_20 )
{
struct V_11 * V_12 = V_7 -> V_11 ;
struct V_2 * V_16 = NULL ;
while ( V_12 ) {
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_20 < V_16 -> V_17 )
V_12 = V_12 -> V_21 ;
else if ( V_20 > F_12 ( V_16 ) )
V_12 = V_12 -> V_22 ;
else
return V_16 ;
}
if ( V_16 && V_20 < V_16 -> V_17 )
return V_16 ;
if ( V_16 && V_20 > F_12 ( V_16 ) ) {
V_12 = F_11 ( & V_16 -> V_11 ) ;
return V_12 ? F_10 ( V_12 , struct V_2 , V_11 ) :
NULL ;
}
return NULL ;
}
T_2 F_15 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = NULL ;
struct V_2 * V_23 = NULL ;
struct V_11 * V_12 ;
T_2 V_24 = V_25 ;
F_16 ( V_10 , V_16 -> V_17 ) ;
F_17 ( & F_8 ( V_10 ) -> V_26 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
if ( V_6 -> V_9 ) {
V_23 = V_6 -> V_9 ;
if ( F_18 ( V_16 -> V_17 , V_23 -> V_17 , V_23 -> V_18 ) ) {
F_19 ( L_4 ,
V_16 -> V_17 , V_23 -> V_17 , V_23 -> V_18 ) ;
goto V_27;
}
}
V_16 -> V_18 = 0 ;
V_23 = F_14 ( & V_6 -> V_7 , V_16 -> V_17 ) ;
V_27:
if ( V_23 ) {
V_6 -> V_9 = V_23 ;
V_16 -> V_17 = V_23 -> V_17 ;
V_16 -> V_18 = V_23 -> V_18 ;
V_12 = F_11 ( & V_23 -> V_11 ) ;
if ( V_12 ) {
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
V_24 = V_23 -> V_17 ;
}
}
F_20 ( & F_8 ( V_10 ) -> V_26 ) ;
F_21 ( V_10 , V_16 , V_24 ) ;
return V_24 ;
}
static struct V_2 *
F_22 ( T_2 V_17 , T_2 V_18 )
{
struct V_2 * V_16 ;
V_16 = F_23 ( V_1 , V_28 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_17 = V_17 ;
V_16 -> V_18 = V_18 ;
return V_16 ;
}
static void F_24 ( struct V_2 * V_16 )
{
F_25 ( V_1 , V_16 ) ;
}
static struct V_2 *
F_26 ( struct V_5 * V_6 , struct V_2 * V_16 )
{
struct V_2 * V_23 ;
struct V_11 * V_12 ;
V_12 = F_27 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_16 -> V_17 == F_12 ( V_23 ) + 1 ) {
V_23 -> V_18 += V_16 -> V_18 ;
F_28 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_24 ( V_16 ) ;
V_16 = V_23 ;
}
return V_16 ;
}
static struct V_2 *
F_29 ( struct V_5 * V_6 , struct V_2 * V_16 )
{
struct V_2 * V_23 ;
struct V_11 * V_12 ;
V_12 = F_11 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_23 -> V_17 == F_12 ( V_16 ) + 1 ) {
V_16 -> V_18 += V_23 -> V_18 ;
F_28 ( V_12 , & V_6 -> V_7 ) ;
F_24 ( V_23 ) ;
}
return V_16 ;
}
static int F_30 ( struct V_5 * V_6 , T_2 V_20 ,
T_2 V_18 )
{
struct V_11 * * V_29 = & V_6 -> V_7 . V_11 ;
struct V_11 * V_30 = NULL ;
struct V_2 * V_16 ;
T_2 V_31 = V_20 + V_18 - 1 ;
F_13 ( V_31 < V_20 ) ;
V_16 = V_6 -> V_9 ;
if ( V_16 && V_20 == ( F_12 ( V_16 ) + 1 ) ) {
F_19 ( L_5 , V_16 -> V_17 , V_16 -> V_18 ) ;
V_16 -> V_18 += V_18 ;
V_16 = F_29 ( V_6 , V_16 ) ;
goto V_27;
} else if ( V_16 && V_16 -> V_17 == V_31 + 1 ) {
F_19 ( L_5 , V_16 -> V_17 , V_16 -> V_18 ) ;
V_16 -> V_17 = V_20 ;
V_16 -> V_18 += V_18 ;
V_16 = F_26 ( V_6 , V_16 ) ;
goto V_27;
} else if ( V_16 && V_16 -> V_17 <= V_20 &&
V_31 <= F_12 ( V_16 ) ) {
F_19 ( L_5 , V_16 -> V_17 , V_16 -> V_18 ) ;
goto V_27;
}
while ( * V_29 ) {
V_30 = * V_29 ;
V_16 = F_10 ( V_30 , struct V_2 , V_11 ) ;
if ( V_20 < V_16 -> V_17 ) {
if ( V_16 -> V_17 == V_31 + 1 ) {
V_16 -> V_17 = V_20 ;
V_16 -> V_18 += V_18 ;
V_16 = F_26 ( V_6 , V_16 ) ;
goto V_27;
}
V_29 = & ( * V_29 ) -> V_21 ;
} else if ( V_20 > F_12 ( V_16 ) ) {
if ( V_20 == F_12 ( V_16 ) + 1 ) {
V_16 -> V_18 += V_18 ;
V_16 = F_29 ( V_6 , V_16 ) ;
goto V_27;
}
V_29 = & ( * V_29 ) -> V_22 ;
} else {
if ( F_12 ( V_16 ) <= V_31 )
V_16 -> V_18 = V_20 - V_16 -> V_17 + V_18 ;
goto V_27;
}
}
V_16 = F_22 ( V_20 , V_18 ) ;
if ( ! V_16 )
return - V_4 ;
F_31 ( & V_16 -> V_11 , V_30 , V_29 ) ;
F_32 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
V_27:
V_6 -> V_9 = V_16 ;
return 0 ;
}
int F_33 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_18 )
{
struct V_5 * V_6 ;
int V_32 = 0 ;
F_34 ( V_10 , V_20 , V_18 ) ;
F_19 ( L_6 ,
V_20 , V_18 , V_10 -> V_14 ) ;
F_35 ( & F_8 ( V_10 ) -> V_26 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
V_32 = F_30 ( V_6 , V_20 , V_18 ) ;
F_36 ( & F_8 ( V_10 ) -> V_26 ) ;
F_6 ( V_10 ) ;
return V_32 ;
}
int F_37 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_18 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 ;
struct V_2 * V_16 ;
struct V_2 V_33 ;
T_2 V_34 , V_35 , V_31 ;
int V_32 = 0 ;
F_38 ( V_10 , V_20 , V_18 ) ;
F_19 ( L_7 ,
V_20 , V_18 , V_10 -> V_14 ) ;
V_31 = V_20 + V_18 - 1 ;
F_13 ( V_31 < V_20 ) ;
F_35 ( & F_8 ( V_10 ) -> V_26 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
V_16 = F_14 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_27;
if ( V_16 -> V_17 > V_31 )
goto V_27;
V_6 -> V_9 = NULL ;
V_33 . V_17 = V_16 -> V_17 ;
V_33 . V_18 = V_16 -> V_18 ;
V_34 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_35 = F_12 ( V_16 ) > V_31 ?
F_12 ( V_16 ) - V_31 : 0 ;
if ( V_34 > 0 )
V_16 -> V_18 = V_34 ;
if ( V_35 > 0 ) {
if ( V_34 > 0 ) {
V_32 = F_30 ( V_6 , V_31 + 1 , V_35 ) ;
if ( V_32 ) {
V_16 -> V_17 = V_33 . V_17 ;
V_16 -> V_18 = V_33 . V_18 ;
goto V_27;
}
} else {
V_16 -> V_17 = V_31 + 1 ;
V_16 -> V_18 = V_35 ;
}
goto V_27;
}
if ( V_34 > 0 ) {
V_12 = F_11 ( & V_16 -> V_11 ) ;
if ( V_12 )
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
else
V_16 = NULL ;
}
while ( V_16 && F_12 ( V_16 ) <= V_31 ) {
V_12 = F_11 ( & V_16 -> V_11 ) ;
F_28 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_24 ( V_16 ) ;
if ( ! V_12 ) {
V_16 = NULL ;
break;
}
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
if ( V_16 && V_16 -> V_17 < V_31 + 1 ) {
V_34 = F_12 ( V_16 ) - V_31 ;
V_16 -> V_17 = V_31 + 1 ;
V_16 -> V_18 = V_34 ;
}
V_27:
F_36 ( & F_8 ( V_10 ) -> V_26 ) ;
F_6 ( V_10 ) ;
return V_32 ;
}
