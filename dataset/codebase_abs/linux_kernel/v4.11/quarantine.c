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
static struct V_12 * F_6 ( struct V_6 * V_7 )
{
return F_7 ( V_7 ) -> V_13 ;
}
static void * F_8 ( struct V_6 * V_7 , struct V_12 * V_14 )
{
struct V_15 * V_16 =
F_9 ( V_7 , struct V_15 ,
V_17 ) ;
return ( ( void * ) V_16 ) - V_14 -> V_18 . V_19 ;
}
static void F_10 ( struct V_6 * V_7 , struct V_12 * V_14 )
{
void * V_20 = F_8 ( V_7 , V_14 ) ;
unsigned long V_21 ;
if ( F_11 ( V_22 ) )
F_12 ( V_21 ) ;
F_13 ( V_14 , V_20 , V_23 ) ;
if ( F_11 ( V_22 ) )
F_14 ( V_21 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_12 * V_14 )
{
struct V_6 * V_7 ;
if ( F_4 ( F_1 ( V_2 ) ) )
return;
V_7 = V_2 -> V_3 ;
while ( V_7 ) {
struct V_12 * V_24 =
V_14 ? V_14 : F_6 ( V_7 ) ;
struct V_6 * V_9 = V_7 -> V_9 ;
F_10 ( V_7 , V_24 ) ;
V_7 = V_9 ;
}
F_2 ( V_2 ) ;
}
void F_16 ( struct V_15 * V_25 , struct V_12 * V_14 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
struct V_1 V_26 = V_27 ;
F_12 ( V_21 ) ;
V_2 = F_17 ( & V_28 ) ;
F_3 ( V_2 , & V_25 -> V_17 , V_14 -> V_8 ) ;
if ( F_4 ( V_2 -> V_5 > V_29 ) ) {
F_5 ( V_2 , & V_26 ) ;
F_18 ( & V_30 ) ;
F_19 ( V_31 , V_31 + V_26 . V_5 ) ;
F_5 ( & V_26 , & V_32 [ V_33 ] ) ;
if ( V_32 [ V_33 ] . V_5 >=
F_20 ( V_34 ) ) {
int V_35 ;
V_35 = V_33 + 1 ;
if ( V_35 == V_36 )
V_35 = 0 ;
if ( V_35 != V_37 )
V_33 = V_35 ;
}
F_21 ( & V_30 ) ;
}
F_14 ( V_21 ) ;
}
void F_22 ( void )
{
T_1 V_38 , V_39 , V_40 ;
unsigned long V_21 ;
int V_41 ;
struct V_1 V_42 = V_27 ;
if ( F_23 ( F_20 ( V_31 ) <=
F_20 ( V_43 ) ) )
return;
V_41 = F_24 ( & V_44 ) ;
F_25 ( & V_30 , V_21 ) ;
V_38 = ( F_20 ( V_45 ) << V_46 ) /
V_47 ;
V_40 = V_29 * F_26 () ;
V_39 = ( V_38 < V_40 ) ?
0 : V_38 - V_40 ;
F_19 ( V_43 , V_39 ) ;
F_19 ( V_34 , F_27 ( ( T_1 ) V_29 ,
2 * V_38 / V_36 ) ) ;
if ( F_23 ( V_31 > V_43 ) ) {
F_5 ( & V_32 [ V_37 ] , & V_42 ) ;
F_19 ( V_31 , V_31 - V_42 . V_5 ) ;
V_37 ++ ;
if ( V_37 == V_36 )
V_37 = 0 ;
}
F_28 ( & V_30 , V_21 ) ;
F_15 ( & V_42 , NULL ) ;
F_29 ( & V_44 , V_41 ) ;
}
static void F_30 ( struct V_1 * V_10 ,
struct V_1 * V_11 ,
struct V_12 * V_14 )
{
struct V_6 * V_48 ;
if ( F_4 ( F_1 ( V_10 ) ) )
return;
V_48 = V_10 -> V_3 ;
F_2 ( V_10 ) ;
while ( V_48 ) {
struct V_6 * V_9 = V_48 -> V_9 ;
struct V_12 * V_24 = F_6 ( V_48 ) ;
if ( V_24 == V_14 )
F_3 ( V_11 , V_48 , V_24 -> V_8 ) ;
else
F_3 ( V_10 , V_48 , V_24 -> V_8 ) ;
V_48 = V_9 ;
}
}
static void F_31 ( void * V_49 )
{
struct V_12 * V_14 = V_49 ;
struct V_1 V_42 = V_27 ;
struct V_1 * V_2 ;
V_2 = F_17 ( & V_28 ) ;
F_30 ( V_2 , & V_42 , V_14 ) ;
F_15 ( & V_42 , V_14 ) ;
}
void F_32 ( struct V_12 * V_14 )
{
unsigned long V_21 , V_50 ;
struct V_1 V_42 = V_27 ;
F_33 ( F_31 , V_14 , 1 ) ;
F_25 ( & V_30 , V_21 ) ;
for ( V_50 = 0 ; V_50 < V_36 ; V_50 ++ ) {
if ( F_1 ( & V_32 [ V_50 ] ) )
continue;
F_30 ( & V_32 [ V_50 ] , & V_42 , V_14 ) ;
F_28 ( & V_30 , V_21 ) ;
F_34 () ;
F_25 ( & V_30 , V_21 ) ;
}
F_28 ( & V_30 , V_21 ) ;
F_15 ( & V_42 , V_14 ) ;
F_35 ( & V_44 ) ;
}
