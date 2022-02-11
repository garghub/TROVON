static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 = NULL ;
V_2 -> V_5 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_8 )
{
if ( F_4 ( F_1 ( V_2 ) ) )
V_2 -> V_3 = V_7 ;
else
V_2 -> V_4 -> V_9 = V_7 ;
V_2 -> V_4 = V_7 ;
V_7 -> V_9 = NULL ;
V_2 -> V_5 += V_8 ;
}
static void F_5 ( struct V_1 * V_10 , struct V_1 * V_11 )
{
if ( F_4 ( F_1 ( V_10 ) ) )
return;
if ( F_1 ( V_11 ) ) {
* V_11 = * V_10 ;
F_2 ( V_10 ) ;
return;
}
V_11 -> V_4 -> V_9 = V_10 -> V_3 ;
V_11 -> V_4 = V_10 -> V_4 ;
V_11 -> V_5 += V_10 -> V_5 ;
F_2 ( V_10 ) ;
}
static void F_6 ( struct V_1 * V_10 , struct V_6 * V_12 ,
struct V_1 * V_11 , T_1 V_8 )
{
if ( F_4 ( V_12 == V_10 -> V_4 ) ) {
F_5 ( V_10 , V_11 ) ;
return;
}
if ( F_1 ( V_11 ) )
V_11 -> V_3 = V_10 -> V_3 ;
else
V_11 -> V_4 -> V_9 = V_10 -> V_3 ;
V_11 -> V_4 = V_12 ;
V_10 -> V_3 = V_12 -> V_9 ;
V_12 -> V_9 = NULL ;
V_10 -> V_5 -= V_8 ;
V_11 -> V_5 += V_8 ;
}
static struct V_13 * F_7 ( struct V_6 * V_7 )
{
return F_8 ( V_7 ) -> V_14 ;
}
static void * F_9 ( struct V_6 * V_7 , struct V_13 * V_15 )
{
struct V_16 * V_17 =
F_10 ( V_7 , struct V_16 ,
V_18 ) ;
return ( ( void * ) V_17 ) - V_15 -> V_19 . V_20 ;
}
static void F_11 ( struct V_6 * V_7 , struct V_13 * V_15 )
{
void * V_21 = F_9 ( V_7 , V_15 ) ;
unsigned long V_22 ;
if ( F_12 ( V_23 ) )
F_13 ( V_22 ) ;
F_14 ( V_15 , V_21 , V_24 ) ;
if ( F_12 ( V_23 ) )
F_15 ( V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_13 * V_15 )
{
struct V_6 * V_7 ;
if ( F_4 ( F_1 ( V_2 ) ) )
return;
V_7 = V_2 -> V_3 ;
while ( V_7 ) {
struct V_13 * V_25 =
V_15 ? V_15 : F_7 ( V_7 ) ;
struct V_6 * V_9 = V_7 -> V_9 ;
F_11 ( V_7 , V_25 ) ;
V_7 = V_9 ;
}
F_2 ( V_2 ) ;
}
void F_17 ( struct V_16 * V_26 , struct V_13 * V_15 )
{
unsigned long V_22 ;
struct V_1 * V_2 ;
struct V_1 V_27 = V_28 ;
F_13 ( V_22 ) ;
V_2 = F_18 ( & V_29 ) ;
F_3 ( V_2 , & V_26 -> V_18 , V_15 -> V_8 ) ;
if ( F_4 ( V_2 -> V_5 > V_30 ) )
F_5 ( V_2 , & V_27 ) ;
F_15 ( V_22 ) ;
if ( F_4 ( ! F_1 ( & V_27 ) ) ) {
F_19 ( & V_31 , V_22 ) ;
F_5 ( & V_27 , & V_32 ) ;
F_20 ( & V_31 , V_22 ) ;
}
}
void F_21 ( void )
{
T_1 V_33 , V_34 ;
unsigned long V_22 ;
struct V_1 V_35 = V_28 ;
T_1 V_36 = 0 ;
struct V_6 * V_12 ;
if ( F_22 ( F_23 ( V_32 . V_5 ) <=
F_23 ( V_37 ) ) )
return;
F_19 ( & V_31 , V_22 ) ;
V_33 = ( F_23 ( V_38 ) << V_39 ) /
V_40 ;
V_34 = V_30 * F_24 () ;
V_33 = ( V_33 < V_34 ) ?
0 : V_33 - V_34 ;
F_25 ( V_37 , V_33 ) ;
V_12 = V_32 . V_3 ;
while ( V_12 ) {
struct V_13 * V_15 = F_7 ( V_12 ) ;
V_36 += V_15 -> V_8 ;
if ( ! V_12 -> V_9 || V_36 >
V_32 . V_5 - V_41 )
break;
V_12 = V_12 -> V_9 ;
}
F_6 ( & V_32 , V_12 , & V_35 , V_36 ) ;
F_20 ( & V_31 , V_22 ) ;
F_16 ( & V_35 , NULL ) ;
}
static void F_26 ( struct V_1 * V_10 ,
struct V_1 * V_11 ,
struct V_13 * V_15 )
{
struct V_6 * V_42 ;
if ( F_4 ( F_1 ( V_10 ) ) )
return;
V_42 = V_10 -> V_3 ;
F_2 ( V_10 ) ;
while ( V_42 ) {
struct V_6 * V_9 = V_42 -> V_9 ;
struct V_13 * V_25 = F_7 ( V_42 ) ;
if ( V_25 == V_15 )
F_3 ( V_11 , V_42 , V_25 -> V_8 ) ;
else
F_3 ( V_10 , V_42 , V_25 -> V_8 ) ;
V_42 = V_9 ;
}
}
static void F_27 ( void * V_43 )
{
struct V_13 * V_15 = V_43 ;
struct V_1 V_35 = V_28 ;
struct V_1 * V_2 ;
V_2 = F_18 ( & V_29 ) ;
F_26 ( V_2 , & V_35 , V_15 ) ;
F_16 ( & V_35 , V_15 ) ;
}
void F_28 ( struct V_13 * V_15 )
{
unsigned long V_22 ;
struct V_1 V_35 = V_28 ;
F_29 ( F_27 , V_15 , 1 ) ;
F_19 ( & V_31 , V_22 ) ;
F_26 ( & V_32 , & V_35 , V_15 ) ;
F_20 ( & V_31 , V_22 ) ;
F_16 ( & V_35 , V_15 ) ;
}
