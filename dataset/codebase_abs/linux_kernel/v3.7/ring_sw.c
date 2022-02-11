static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( ( V_4 == 0 ) || ( V_3 == 0 ) )
return - V_5 ;
F_2 ( & V_2 -> V_6 , V_3 , V_4 ) ;
V_2 -> V_7 = F_3 ( V_4 * V_2 -> V_6 . V_3 , V_8 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = NULL ;
V_2 -> V_11 = NULL ;
return V_2 -> V_7 ? 0 : - V_12 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char * V_7 )
{
int V_13 = 0 ;
unsigned char * V_14 , * V_15 ;
if ( F_7 ( V_2 -> V_10 == NULL ) ) {
V_2 -> V_10 = V_2 -> V_7 ;
V_2 -> V_11 = V_2 -> V_7 - V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 / 2 ;
}
memcpy ( V_2 -> V_10 , V_7 , V_2 -> V_6 . V_3 ) ;
F_8 () ;
F_8 () ;
V_14 = V_2 -> V_10 + V_2 -> V_6 . V_3 ;
if ( V_14 == V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 )
V_14 = V_2 -> V_7 ;
V_2 -> V_10 = V_14 ;
if ( V_2 -> V_9 == NULL )
V_2 -> V_9 = V_2 -> V_7 ;
else if ( V_2 -> V_10 == V_2 -> V_9 ) {
V_15 = V_2 -> V_9 ;
V_14 = V_15 + V_2 -> V_6 . V_3 ;
if ( V_14
== V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 ) {
V_14 = V_2 -> V_7 ;
}
if ( V_15 == V_2 -> V_9 )
V_2 -> V_9 = V_14 ;
}
V_2 -> V_11 += V_2 -> V_6 . V_3 ;
if ( V_2 -> V_11 == V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 )
V_2 -> V_11 = V_2 -> V_7 ;
if ( V_2 -> V_11 == V_2 -> V_9 ) {
V_2 -> V_6 . V_16 = true ;
F_9 ( & V_2 -> V_6 . V_17 ) ;
}
return V_13 ;
}
static int F_10 ( struct V_18 * V_19 ,
T_1 V_20 , char T_2 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
T_3 * V_21 , * V_22 , * V_23 , * V_24 ;
T_3 * V_7 ;
int V_13 , V_25 , V_26 , V_27 ;
T_1 V_28 , V_29 ;
if ( V_20 % V_2 -> V_6 . V_3 ) {
V_13 = - V_5 ;
F_12 ( V_30 L_1
L_2 ,
V_20 , V_2 -> V_6 . V_3 ) ;
goto V_31;
}
V_29 = V_2 -> V_6 . V_3 * V_2 -> V_6 . V_4 ;
V_26 = F_13 ( T_1 , V_29 , V_20 ) ;
V_7 = F_3 ( V_26 , V_32 ) ;
if ( V_7 == NULL ) {
V_13 = - V_12 ;
goto V_31;
}
V_21 = V_2 -> V_9 ;
if ( F_7 ( V_21 == NULL ) ) {
V_13 = 0 ;
goto V_33;
}
V_22 = V_2 -> V_10 ;
while ( ( V_21 != V_2 -> V_9 )
|| ( V_22 != V_2 -> V_10 ) ) {
V_21 = V_2 -> V_9 ;
V_22 = V_2 -> V_10 ;
}
if ( V_22 == V_21 ) {
V_13 = 0 ;
goto V_33;
}
if ( V_22 >= V_21 )
V_28 = V_22 - V_21 ;
else
V_28 = V_29 - ( V_21 - V_22 ) ;
if ( V_28 < V_26 )
V_26 = V_28 ;
if ( V_21 + V_26 >= V_2 -> V_7 + V_29 ) {
V_25 = V_2 -> V_7 + V_29 - V_21 ;
memcpy ( V_7 , V_21 , V_25 ) ;
memcpy ( V_7 + V_25 , V_2 -> V_7 , V_26 - V_25 ) ;
V_24 = V_2 -> V_7 + V_26 - V_25 ;
} else {
memcpy ( V_7 , V_21 , V_26 ) ;
V_24 = V_21 + V_26 ;
}
V_23 = V_2 -> V_9 ;
if ( V_21 <= V_23 )
V_27 = V_23 - V_21 ;
else
V_27 = V_29 - ( V_21 - V_23 ) ;
if ( V_26 - V_27 < 0 ) {
V_13 = 0 ;
goto V_33;
}
while ( V_2 -> V_9 != V_24 )
V_2 -> V_9 = V_24 ;
V_13 = V_26 - V_27 ;
if ( F_14 ( V_6 , V_7 + V_27 , V_13 ) ) {
V_13 = - V_34 ;
goto V_33;
}
if ( V_26 >= V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 / 2 )
V_2 -> V_6 . V_16 = 0 ;
V_33:
F_5 ( V_7 ) ;
V_31:
return V_13 ;
}
static int F_15 ( struct V_18 * V_19 ,
T_3 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
return F_6 ( V_2 , V_7 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
int V_13 = 0 ;
struct V_1 * V_2 = F_11 ( V_19 ) ;
V_19 -> V_16 = false ;
if ( ! V_2 -> V_35 )
goto V_31;
F_4 ( V_2 ) ;
V_13 = F_1 ( V_2 , V_2 -> V_6 . V_3 ,
V_2 -> V_6 . V_4 ) ;
V_31:
return V_13 ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
return V_2 -> V_6 . V_3 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
V_2 -> V_35 = true ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , T_1 V_36 )
{
if ( V_19 -> V_3 != V_36 ) {
V_19 -> V_3 = V_36 ;
F_18 ( V_19 ) ;
}
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
return V_19 -> V_4 ;
}
static int F_21 ( struct V_18 * V_19 , int V_4 )
{
if ( V_19 -> V_4 != V_4 ) {
V_19 -> V_4 = V_4 ;
F_18 ( V_19 ) ;
}
return 0 ;
}
struct V_18 * F_22 ( struct V_37 * V_38 )
{
struct V_18 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_23 ( sizeof *V_2 , V_32 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_35 = true ;
V_6 = & V_2 -> V_6 ;
F_24 ( V_6 ) ;
V_6 -> V_39 = & V_40 ;
V_6 -> V_41 = & V_42 ;
return V_6 ;
}
void F_25 ( struct V_18 * V_19 )
{
F_5 ( F_11 ( V_19 ) ) ;
}
