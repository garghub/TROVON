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
V_2 -> V_12 = NULL ;
return V_2 -> V_7 ? 0 : - V_13 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_14 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_7 ) ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
F_10 ( & V_2 -> V_14 ) ;
V_2 -> V_17 ++ ;
F_11 ( & V_2 -> V_14 ) ;
}
static void F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
F_10 ( & V_2 -> V_14 ) ;
V_2 -> V_17 -- ;
F_11 ( & V_2 -> V_14 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned char * V_7 , T_1 V_18 )
{
int V_19 = 0 ;
unsigned char * V_20 , * V_21 ;
if ( F_14 ( V_2 -> V_10 == NULL ) ) {
V_2 -> V_10 = V_2 -> V_7 ;
V_2 -> V_12 = V_2 -> V_7 - V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 / 2 ;
}
memcpy ( V_2 -> V_10 , V_7 , V_2 -> V_6 . V_3 ) ;
F_15 () ;
V_2 -> V_11 = V_2 -> V_10 ;
F_15 () ;
V_20 = V_2 -> V_10 + V_2 -> V_6 . V_3 ;
if ( V_20 == V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 )
V_20 = V_2 -> V_7 ;
V_2 -> V_10 = V_20 ;
if ( V_2 -> V_9 == NULL )
V_2 -> V_9 = V_2 -> V_7 ;
else if ( V_2 -> V_10 == V_2 -> V_9 ) {
V_21 = V_2 -> V_9 ;
V_20 = V_21 + V_2 -> V_6 . V_3 ;
if ( V_20
== V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 ) {
V_20 = V_2 -> V_7 ;
}
if ( V_21 == V_2 -> V_9 )
V_2 -> V_9 = V_20 ;
}
V_2 -> V_12 += V_2 -> V_6 . V_3 ;
if ( V_2 -> V_12 == V_2 -> V_7 + V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 )
V_2 -> V_12 = V_2 -> V_7 ;
if ( V_2 -> V_12 == V_2 -> V_9 ) {
V_2 -> V_6 . V_22 = true ;
F_16 ( & V_2 -> V_6 . V_23 ) ;
}
return V_19 ;
}
static int F_17 ( struct V_15 * V_16 ,
T_2 V_24 , char T_3 * V_6 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_4 * V_25 , * V_26 , * V_27 , * V_28 ;
T_4 * V_7 ;
int V_19 , V_29 , V_30 , V_31 ;
if ( V_24 % V_2 -> V_6 . V_3 ) {
V_19 = - V_5 ;
F_18 ( V_32 L_1
L_2 ,
V_24 , V_2 -> V_6 . V_3 ) ;
goto V_33;
}
V_30 = F_19 ( ( T_2 ) ( V_2 -> V_6 . V_3 * V_2 -> V_6 . V_4 ) ,
V_24 ) ;
V_7 = F_3 ( V_30 , V_34 ) ;
if ( V_7 == NULL ) {
V_19 = - V_13 ;
goto V_33;
}
V_25 = V_2 -> V_9 ;
if ( F_14 ( V_25 == NULL ) ) {
V_19 = 0 ;
goto V_35;
}
V_26 = V_2 -> V_10 ;
while ( ( V_25 != V_2 -> V_9 )
|| ( V_26 != V_2 -> V_10 ) ) {
V_25 = V_2 -> V_9 ;
V_26 = V_2 -> V_10 ;
}
if ( V_26 == V_25 ) {
V_19 = 0 ;
goto V_35;
}
if ( V_26 >= V_25 + V_30 ) {
V_29 = V_30 ;
memcpy ( V_7 , V_25 , V_29 ) ;
V_28 = V_25 + V_29 ;
} else if ( V_26 > V_25 ) {
V_29 = V_26 - V_25 ;
memcpy ( V_7 , V_25 , V_29 ) ;
V_28 = V_26 ;
} else {
V_29 = V_2 -> V_7
+ V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 - V_25 ;
memcpy ( V_7 , V_25 , V_29 ) ;
if ( V_29 == V_30 )
V_28 = V_2 -> V_7 ;
else if ( V_26
> V_2 -> V_7 + V_30 - V_29 ) {
memcpy ( V_7 + V_29 , V_2 -> V_7 ,
V_30 - V_29 ) ;
V_29 = V_30 ;
V_28 = V_2 -> V_7 + ( V_30 - V_29 ) ;
} else {
memcpy ( V_7 + V_29 , V_2 -> V_7 ,
V_26 - V_2 -> V_7 ) ;
V_29 += V_26 - V_2 -> V_7 ;
V_28 = V_26 ;
}
}
V_27 = V_2 -> V_9 ;
if ( V_25 <= V_27 )
V_31 = V_27 - V_25 ;
else
V_31 = V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3
- ( V_25 - V_27 ) ;
if ( V_29 - V_31 < 0 ) {
V_19 = 0 ;
goto V_35;
}
while ( V_2 -> V_9 != V_28 )
V_2 -> V_9 = V_28 ;
V_19 = V_29 - V_31 ;
if ( F_20 ( V_6 , V_7 + V_31 , V_19 ) ) {
V_19 = - V_36 ;
goto V_35;
}
if ( V_30 >= V_2 -> V_6 . V_4 * V_2 -> V_6 . V_3 / 2 )
V_2 -> V_6 . V_22 = 0 ;
V_35:
F_7 ( V_7 ) ;
V_33:
return V_19 ;
}
static int F_21 ( struct V_15 * V_16 ,
T_4 * V_7 ,
T_1 V_18 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
return F_13 ( V_2 , V_7 , V_18 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned char * V_7 )
{
unsigned char * V_37 ;
F_8 ( & V_2 -> V_6 ) ;
V_38:
F_15 () ;
V_37 = V_2 -> V_11 ;
F_15 () ;
if ( V_37 == NULL )
return - V_39 ;
memcpy ( V_7 , V_37 , V_2 -> V_6 . V_3 ) ;
if ( F_14 ( V_2 -> V_11 != V_37 ) )
goto V_38;
F_12 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_23 ( struct V_15 * V_16 ,
unsigned char * V_7 )
{
return F_22 ( F_9 ( V_16 ) , V_7 ) ;
}
static int F_24 ( struct V_15 * V_16 )
{
int V_19 = 0 ;
struct V_1 * V_2 = F_9 ( V_16 ) ;
V_16 -> V_22 = false ;
F_10 ( & V_2 -> V_14 ) ;
if ( ! V_2 -> V_40 )
goto V_33;
if ( V_2 -> V_17 ) {
V_19 = - V_39 ;
goto V_33;
}
F_6 ( V_2 ) ;
V_19 = F_1 ( V_2 , V_2 -> V_6 . V_3 ,
V_2 -> V_6 . V_4 ) ;
V_33:
F_11 ( & V_2 -> V_14 ) ;
return V_19 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
return V_2 -> V_6 . V_3 ;
}
static int F_26 ( struct V_15 * V_16 , T_2 V_41 )
{
if ( V_16 -> V_3 != V_41 ) {
V_16 -> V_3 = V_41 ;
if ( V_16 -> V_42 -> V_43 )
V_16 -> V_42 -> V_43 ( V_16 ) ;
}
return 0 ;
}
static int F_27 ( struct V_15 * V_16 )
{
return V_16 -> V_4 ;
}
static int F_28 ( struct V_15 * V_16 , int V_4 )
{
if ( V_16 -> V_4 != V_4 ) {
V_16 -> V_4 = V_4 ;
if ( V_16 -> V_42 -> V_43 )
V_16 -> V_42 -> V_43 ( V_16 ) ;
}
return 0 ;
}
static int F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
V_2 -> V_40 = true ;
return 0 ;
}
static void F_30 ( struct V_44 * V_45 )
{
struct V_15 * V_16 = F_31 ( V_45 ) ;
F_32 ( & V_16 -> V_45 ) ;
F_7 ( F_9 ( V_16 ) ) ;
}
struct V_15 * F_33 ( struct V_46 * V_47 )
{
struct V_15 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_34 ( sizeof *V_2 , V_34 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_40 = true ;
V_6 = & V_2 -> V_6 ;
F_35 ( V_6 , V_47 ) ;
F_4 ( V_2 ) ;
V_6 -> V_45 . type = & V_48 ;
V_6 -> V_45 . V_49 = & V_47 -> V_45 ;
F_36 ( & V_6 -> V_45 , ( void * ) V_6 ) ;
return V_6 ;
}
void F_37 ( struct V_15 * V_16 )
{
if ( V_16 )
F_38 ( V_16 ) ;
}
