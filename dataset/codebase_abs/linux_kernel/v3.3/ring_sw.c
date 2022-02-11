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
unsigned char * V_7 , T_1 V_13 )
{
int V_14 = 0 ;
unsigned char * V_15 , * V_16 ;
if ( F_7 ( V_2 -> V_10 == NULL ) ) {
V_2 -> V_10 = V_2 -> V_7 ;
V_2 -> V_11 = V_2 -> V_7 - V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 / 2 ;
}
memcpy ( V_2 -> V_10 , V_7 , V_2 -> V_6 . V_3 ) ;
F_8 () ;
F_8 () ;
V_15 = V_2 -> V_10 + V_2 -> V_6 . V_3 ;
if ( V_15 == V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 )
V_15 = V_2 -> V_7 ;
V_2 -> V_10 = V_15 ;
if ( V_2 -> V_9 == NULL )
V_2 -> V_9 = V_2 -> V_7 ;
else if ( V_2 -> V_10 == V_2 -> V_9 ) {
V_16 = V_2 -> V_9 ;
V_15 = V_16 + V_2 -> V_6 . V_3 ;
if ( V_15
== V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 ) {
V_15 = V_2 -> V_7 ;
}
if ( V_16 == V_2 -> V_9 )
V_2 -> V_9 = V_15 ;
}
V_2 -> V_11 += V_2 -> V_6 . V_3 ;
if ( V_2 -> V_11 == V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 )
V_2 -> V_11 = V_2 -> V_7 ;
if ( V_2 -> V_11 == V_2 -> V_9 ) {
V_2 -> V_6 . V_17 = true ;
F_9 ( & V_2 -> V_6 . V_18 ) ;
}
return V_14 ;
}
static int F_10 ( struct V_19 * V_20 ,
T_2 V_21 , char T_3 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
T_4 * V_22 , * V_23 , * V_24 , * V_25 ;
T_4 * V_7 ;
int V_14 , V_26 , V_27 , V_28 ;
T_2 V_29 , V_30 ;
if ( V_21 % V_2 -> V_6 . V_3 ) {
V_14 = - V_5 ;
F_12 ( V_31 L_1
L_2 ,
V_21 , V_2 -> V_6 . V_3 ) ;
goto V_32;
}
V_30 = V_2 -> V_6 . V_3 * V_2 -> V_6 . V_4 ;
V_27 = F_13 ( T_2 , V_30 , V_21 ) ;
V_7 = F_3 ( V_27 , V_33 ) ;
if ( V_7 == NULL ) {
V_14 = - V_12 ;
goto V_32;
}
V_22 = V_2 -> V_9 ;
if ( F_7 ( V_22 == NULL ) ) {
V_14 = 0 ;
goto V_34;
}
V_23 = V_2 -> V_10 ;
while ( ( V_22 != V_2 -> V_9 )
|| ( V_23 != V_2 -> V_10 ) ) {
V_22 = V_2 -> V_9 ;
V_23 = V_2 -> V_10 ;
}
if ( V_23 == V_22 ) {
V_14 = 0 ;
goto V_34;
}
if ( V_23 >= V_22 )
V_29 = V_23 - V_22 ;
else
V_29 = V_30 - ( V_22 - V_23 ) ;
if ( V_29 < V_27 )
V_27 = V_29 ;
if ( V_22 + V_27 >= V_2 -> V_7 + V_30 ) {
V_26 = V_2 -> V_7 + V_30 - V_22 ;
memcpy ( V_7 , V_22 , V_26 ) ;
memcpy ( V_7 + V_26 , V_2 -> V_7 , V_27 - V_26 ) ;
V_25 = V_2 -> V_7 + V_27 - V_26 ;
} else {
memcpy ( V_7 , V_22 , V_27 ) ;
V_25 = V_22 + V_27 ;
}
V_24 = V_2 -> V_9 ;
if ( V_22 <= V_24 )
V_28 = V_24 - V_22 ;
else
V_28 = V_30 - ( V_22 - V_24 ) ;
if ( V_27 - V_28 < 0 ) {
V_14 = 0 ;
goto V_34;
}
while ( V_2 -> V_9 != V_25 )
V_2 -> V_9 = V_25 ;
V_14 = V_27 - V_28 ;
if ( F_14 ( V_6 , V_7 + V_28 , V_14 ) ) {
V_14 = - V_35 ;
goto V_34;
}
if ( V_27 >= V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 / 2 )
V_2 -> V_6 . V_17 = 0 ;
V_34:
F_5 ( V_7 ) ;
V_32:
return V_14 ;
}
static int F_15 ( struct V_19 * V_20 ,
T_4 * V_7 ,
T_1 V_13 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
return F_6 ( V_2 , V_7 , V_13 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
int V_14 = 0 ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
V_20 -> V_17 = false ;
if ( ! V_2 -> V_36 )
goto V_32;
F_4 ( V_2 ) ;
V_14 = F_1 ( V_2 , V_2 -> V_6 . V_3 ,
V_2 -> V_6 . V_4 ) ;
V_32:
return V_14 ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
return V_2 -> V_6 . V_3 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
V_2 -> V_36 = true ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , T_2 V_37 )
{
if ( V_20 -> V_3 != V_37 ) {
V_20 -> V_3 = V_37 ;
F_18 ( V_20 ) ;
}
return 0 ;
}
static int F_20 ( struct V_19 * V_20 )
{
return V_20 -> V_4 ;
}
static int F_21 ( struct V_19 * V_20 , int V_4 )
{
if ( V_20 -> V_4 != V_4 ) {
V_20 -> V_4 = V_4 ;
F_18 ( V_20 ) ;
}
return 0 ;
}
struct V_19 * F_22 ( struct V_38 * V_39 )
{
struct V_19 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_23 ( sizeof *V_2 , V_33 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_36 = true ;
V_6 = & V_2 -> V_6 ;
F_24 ( V_6 ) ;
V_6 -> V_40 = & V_41 ;
return V_6 ;
}
void F_25 ( struct V_19 * V_20 )
{
F_5 ( F_11 ( V_20 ) ) ;
}
