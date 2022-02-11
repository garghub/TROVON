static inline T_1 F_1 ( struct V_1 * V_2 )
{
return ( 1ULL << V_2 -> V_3 -> V_4 . V_5 ) - 1ULL ;
}
static inline T_2 F_2 ( struct V_1 * V_2 , T_3 V_6 )
{
return ( V_6 - V_2 -> V_3 -> V_4 . V_7 ) >> V_2 -> V_3 -> V_4 . V_5 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_2 V_8 )
{
return V_2 -> V_3 -> V_4 . V_7 + ( V_8 * V_2 -> V_3 -> V_4 . V_9 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_3 V_6 )
{
return V_6 & F_1 ( V_2 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_3 V_6 )
{
return F_6 ( V_6 - F_1 ( V_2 ) ,
V_2 -> V_3 -> V_4 . V_9 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , T_3 V_6 )
{
return F_6 ( V_6 , V_2 -> V_3 -> V_4 . V_9 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 . V_10 * V_2 -> V_3 -> V_4 . V_9 ;
}
static inline T_1 F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 . V_7 + F_8 ( V_2 ) - 1ULL ;
}
static inline bool
F_10 ( struct V_1 * V_2 , T_3 V_6 )
{
return V_6 >= V_2 -> V_3 -> V_4 . V_7 && V_6 <= F_9 ( V_2 ) ;
}
static void F_11 ( int V_11 , T_4 * V_12 , T_1 V_13 ,
int V_14 , struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_3 ;
int V_17 ;
for ( V_17 = V_11 ; V_17 < V_11 + V_14 ; V_17 ++ ,
V_13 += V_16 -> V_4 . V_9 ) {
if ( ! V_16 -> V_18 [ V_17 ] . V_19 &&
( V_16 -> V_18 [ V_17 ] . V_20 != V_13 ) ) {
V_2 -> V_21 -> V_22 ( V_2 , V_13 , V_17 ) ;
V_16 -> V_18 [ V_17 ] . V_20 = V_13 ;
}
V_16 -> V_18 [ V_17 ] . V_19 += V_12 [ V_17 - V_11 ] ;
}
}
static T_3 F_12 ( struct V_1 * V_2 , T_1 V_20 ,
int V_14 , T_4 * V_12 , T_5 V_23 )
{
int V_11 ;
int V_24 = 0 ;
int V_17 ;
unsigned long V_25 ;
T_3 V_26 = 0 ;
T_3 V_13 = V_20 ;
struct V_15 * V_16 = V_2 -> V_3 ;
F_13 ( & V_16 -> V_27 , V_25 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_4 . V_10 ; V_17 ++ ) {
if ( V_16 -> V_18 [ V_17 ] . V_20 == V_13 ) {
V_24 ++ ;
V_13 += V_16 -> V_4 . V_9 ;
} else if ( V_24 )
goto V_28;
if ( V_24 == V_14 )
goto V_29;
}
for ( V_24 = 0 , V_17 = 0 ; V_17 < V_16 -> V_4 . V_10 ; V_17 ++ ) {
V_24 = ( V_16 -> V_18 [ V_17 ] . V_19 == 0 ) ? V_24 + 1 : 0 ;
if ( V_24 == V_14 )
goto V_29;
}
V_28:
F_14 ( & V_16 -> V_27 , V_25 ) ;
return V_26 ;
V_29:
V_11 = V_17 - V_14 + 1 ;
V_26 = F_3 ( V_2 , V_11 ) ;
F_11 ( V_11 , V_12 , V_20 , V_14 , V_2 ) ;
V_16 -> V_30 ++ ;
V_16 -> V_19 += ( T_4 ) V_23 ;
F_14 ( & V_16 -> V_27 , V_25 ) ;
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_20 ,
T_5 V_23 , T_4 * V_12 , T_1 * V_31 )
{
T_1 V_32 = V_20 ;
T_1 V_33 = V_20 + V_23 ;
int V_17 = 0 ;
while ( V_32 < V_33 ) {
V_12 [ V_17 ++ ] = F_16 ( F_7 ( V_2 , V_32 + 1 ) ,
V_33 ) - V_32 ;
V_32 = F_7 ( V_2 , V_32 + 1 ) ;
}
if ( V_31 )
* V_31 = F_5 ( V_2 , V_20 ) ;
return V_17 ;
}
T_3 F_17 ( struct V_1 * V_2 , T_3 V_26 )
{
struct V_15 * V_16 = V_2 -> V_3 ;
int V_11 ;
T_3 V_20 ;
if ( ! F_10 ( V_2 , V_26 ) ) {
F_18 ( V_2 -> V_34 -> V_35 ,
L_1 , V_26 ) ;
return - V_36 ;
}
V_11 = F_2 ( V_2 , V_26 ) ;
V_20 = V_16 -> V_18 [ V_11 ] . V_20 +
F_4 ( V_2 , V_26 ) ;
return V_20 ;
}
T_3 F_19 ( struct V_1 * V_2 , T_3 V_20 , T_5 V_23 )
{
T_3 V_26 = 0 ;
int V_37 ;
T_4 * V_12 ;
T_1 V_31 ;
if ( ! V_23 || V_23 > F_8 ( V_2 ) )
return V_26 ;
V_12 = F_20 ( V_2 -> V_3 -> V_4 . V_10 , sizeof( T_4 ) , V_38 ) ;
if ( ! V_12 )
return V_26 ;
V_37 = F_15 ( V_2 , V_20 , V_23 ,
V_12 , & V_31 ) ;
V_26 = F_12 ( V_2 , V_31 , V_37 , V_12 , V_23 ) ;
F_21 ( V_12 ) ;
if ( ! V_26 && V_39 == V_2 -> V_40 ) {
F_18 ( V_2 -> V_34 -> V_35 ,
L_2 ,
V_20 , V_23 ) ;
return V_26 ;
} else {
return V_26 + F_4 ( V_2 , V_20 ) ;
}
}
void F_22 ( struct V_1 * V_2 , T_3 V_26 , T_5 V_23 )
{
struct V_15 * V_16 = V_2 -> V_3 ;
T_4 * V_12 ;
int V_41 ;
int V_11 ;
int V_17 ;
unsigned long V_25 ;
if ( ! V_23 )
return;
if ( ! F_10 ( V_2 , V_26 ) ) {
F_18 ( V_2 -> V_34 -> V_35 ,
L_3 , V_26 ) ;
return;
}
V_11 = F_2 ( V_2 , V_26 ) ;
V_12 = F_20 ( V_2 -> V_3 -> V_4 . V_10 , sizeof( T_4 ) , V_38 ) ;
if ( ! V_12 )
return;
V_41 = F_15 ( V_2 , V_26 , V_23 , V_12 , NULL ) ;
F_13 ( & V_16 -> V_27 , V_25 ) ;
V_16 -> V_42 ++ ;
V_16 -> V_19 -= ( T_4 ) V_23 ;
for ( V_17 = V_11 ; V_17 < V_11 + V_41 ; V_17 ++ ) {
V_16 -> V_18 [ V_17 ] . V_19 -= V_12 [ V_17 - V_11 ] ;
if ( V_16 -> V_18 [ V_17 ] . V_19 < 0 )
F_23 ( V_2 -> V_34 -> V_35 ,
L_4 , V_17 ) ;
}
F_14 ( & V_16 -> V_27 , V_25 ) ;
F_21 ( V_12 ) ;
}
T_3 F_24 ( struct V_1 * V_2 , void * V_43 , T_5 V_23 )
{
T_3 V_26 = 0 ;
struct V_44 * V_45 = F_25 ( V_2 -> V_34 -> V_35 ,
struct V_44 , V_46 ) ;
T_3 V_20 =
F_26 ( V_45 , V_43 , V_23 , V_47 ) ;
if ( ! F_27 ( V_45 , V_20 ) ) {
V_26 = F_19 ( V_2 , V_20 , V_23 ) ;
if ( ! V_26 ) {
F_18 ( V_2 -> V_34 -> V_35 ,
L_2 ,
V_20 , V_23 ) ;
F_28 ( V_45 , V_20 ,
V_23 , V_47 ) ;
}
}
return V_26 ;
}
void
F_29 ( struct V_1 * V_2 , T_3 V_26 , T_5 V_23 )
{
struct V_44 * V_45 = F_25 ( V_2 -> V_34 -> V_35 ,
struct V_44 , V_46 ) ;
T_3 V_20 = F_17 ( V_2 , V_26 ) ;
F_22 ( V_2 , V_26 , V_23 ) ;
F_28 ( V_45 , V_20 , V_23 , V_47 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_17 , V_48 = 0 ;
T_3 V_20 ;
struct V_15 * V_16 ;
V_2 -> V_3 = F_31 ( sizeof( * V_2 -> V_3 ) , V_49 ) ;
if ( ! V_2 -> V_3 )
return - V_50 ;
V_16 = V_2 -> V_3 ;
V_2 -> V_21 -> V_51 ( V_2 ) ;
V_16 -> V_18 = F_20 ( V_16 -> V_4 . V_10 ,
sizeof( * V_16 -> V_18 ) , V_49 ) ;
if ( ! V_16 -> V_18 ) {
V_48 = - V_50 ;
goto V_52;
}
F_32 ( & V_16 -> V_27 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_4 . V_10 ; V_17 ++ ) {
V_20 = V_17 * V_16 -> V_4 . V_9 ;
V_16 -> V_18 [ V_17 ] . V_20 = V_20 ;
V_16 -> V_18 [ V_17 ] . V_19 = 0 ;
V_2 -> V_21 -> V_22 ( V_2 , V_20 , V_17 ) ;
}
V_16 -> V_19 = 0 ;
V_16 -> V_30 = 0 ;
V_16 -> V_42 = 0 ;
return 0 ;
V_52:
F_21 ( V_16 ) ;
return V_48 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_3 ;
int V_17 ;
F_34 ( V_2 -> V_34 -> V_35 ,
L_5 ,
V_2 -> V_53 , V_16 -> V_19 ,
V_16 -> V_30 , V_16 -> V_42 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_4 . V_10 ; V_17 ++ ) {
F_34 ( V_2 -> V_34 -> V_35 ,
L_6 ,
V_17 , V_16 -> V_18 [ V_17 ] . V_20 ,
V_16 -> V_18 [ V_17 ] . V_19 ) ;
if ( V_16 -> V_18 [ V_17 ] . V_19 )
F_23 ( V_2 -> V_34 -> V_35 ,
L_7 , V_17 ) ;
}
F_21 ( V_16 -> V_18 ) ;
F_21 ( V_16 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
int V_17 ;
T_3 V_20 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_3 -> V_4 . V_10 ; V_17 ++ ) {
V_20 = V_2 -> V_3 -> V_18 [ V_17 ] . V_20 ;
V_2 -> V_21 -> V_22 ( V_2 , V_20 , V_17 ) ;
}
}
