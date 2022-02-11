int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , int V_6 )
{
unsigned int V_7 ;
unsigned int V_8 ;
if ( V_4 < 0 ) {
V_4 = F_2 ( V_9 ) ;
if ( V_3 >= 4 ) {
while ( ( 4U << V_4 ) > V_3 )
V_4 -- ;
}
}
V_7 = 1U << V_4 ;
if ( V_7 > V_9 )
return - V_10 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_11 = F_3 ( V_2 -> V_3 , V_7 ) ;
if ( V_3 == 0 ) {
V_2 -> V_12 = NULL ;
return 0 ;
}
V_2 -> V_12 = F_4 ( V_2 -> V_11 * sizeof( * V_2 -> V_12 ) , V_5 , V_6 ) ;
if ( ! V_2 -> V_12 )
return - V_13 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
V_2 -> V_12 [ V_8 ] . V_3 = F_5 ( V_3 , V_7 ) ;
V_3 -= V_2 -> V_12 [ V_8 ] . V_3 ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_7 = 1U << V_2 -> V_4 ;
unsigned int V_8 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_11 = F_3 ( V_2 -> V_3 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
V_2 -> V_12 [ V_8 ] . V_3 = F_5 ( V_3 , V_7 ) ;
V_3 -= V_2 -> V_12 [ V_8 ] . V_3 ;
}
}
static int F_7 ( struct V_14 * V_15 , unsigned int V_16 ,
bool V_17 )
{
unsigned int V_18 = V_16 ;
int V_19 ;
while ( 1 ) {
V_19 = F_8 ( & V_15 -> V_15 , V_15 -> V_3 , V_16 ) ;
if ( F_9 ( V_19 >= V_15 -> V_3 ) ) {
if ( V_18 && V_16 && V_17 ) {
V_16 = V_18 = 0 ;
continue;
}
return - 1 ;
}
if ( ! F_10 ( V_19 , & V_15 -> V_15 ) )
break;
V_16 = V_19 + 1 ;
if ( V_16 >= V_15 -> V_3 - 1 )
V_16 = 0 ;
}
return V_19 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_20 , bool V_21 )
{
unsigned int V_8 , V_22 ;
int V_19 = - 1 ;
V_22 = F_12 ( V_2 , V_20 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
V_19 = F_7 ( & V_2 -> V_12 [ V_22 ] ,
F_13 ( V_2 , V_20 ) ,
! V_21 ) ;
if ( V_19 != - 1 ) {
V_19 += V_22 << V_2 -> V_4 ;
break;
}
V_22 ++ ;
V_20 = V_22 << V_2 -> V_4 ;
if ( V_22 >= V_2 -> V_11 ) {
V_22 = 0 ;
V_20 = 0 ;
}
}
return V_19 ;
}
bool F_14 ( const struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] . V_15 )
return true ;
}
return false ;
}
bool F_15 ( const struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
const struct V_14 * V_15 = & V_2 -> V_12 [ V_8 ] ;
unsigned long V_23 ;
V_23 = F_16 ( & V_15 -> V_15 , V_15 -> V_3 ) ;
if ( V_23 < V_15 -> V_3 )
return true ;
}
return false ;
}
unsigned int F_17 ( const struct V_1 * V_2 )
{
unsigned int V_8 , V_24 = 0 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
const struct V_14 * V_15 = & V_2 -> V_12 [ V_8 ] ;
V_24 += F_18 ( & V_15 -> V_15 , V_15 -> V_3 ) ;
}
return V_24 ;
}
static unsigned int F_19 ( unsigned int V_3 )
{
unsigned int V_25 ;
V_25 = V_26 ;
if ( V_25 > V_3 / V_27 )
V_25 = F_20 ( 1U , V_3 / V_27 ) ;
return V_25 ;
}
int F_21 ( struct V_28 * V_29 , unsigned int V_3 ,
int V_4 , bool V_21 , T_1 V_5 , int V_6 )
{
int V_23 ;
int V_8 ;
V_23 = F_1 ( & V_29 -> V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_23 )
return V_23 ;
V_29 -> V_20 = F_22 (unsigned int, flags) ;
if ( ! V_29 -> V_20 ) {
F_23 ( & V_29 -> V_2 ) ;
return - V_13 ;
}
if ( V_3 && ! V_21 ) {
F_24 ( V_8 )
* F_25 ( V_29 -> V_20 , V_8 ) = F_26 () % V_3 ;
}
V_29 -> V_25 = F_19 ( V_3 ) ;
F_27 ( & V_29 -> V_30 , 0 ) ;
V_29 -> V_31 = F_4 ( V_27 * sizeof( * V_29 -> V_31 ) , V_5 , V_6 ) ;
if ( ! V_29 -> V_31 ) {
F_28 ( V_29 -> V_20 ) ;
F_23 ( & V_29 -> V_2 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ ) {
F_29 ( & V_29 -> V_31 [ V_8 ] . V_32 ) ;
F_27 ( & V_29 -> V_31 [ V_8 ] . V_33 , V_29 -> V_25 ) ;
}
V_29 -> V_21 = V_21 ;
return 0 ;
}
void F_30 ( struct V_28 * V_29 , unsigned int V_3 )
{
V_29 -> V_25 = F_19 ( V_3 ) ;
F_6 ( & V_29 -> V_2 , V_3 ) ;
}
int F_31 ( struct V_28 * V_29 )
{
unsigned int V_16 , V_3 ;
int V_19 ;
V_16 = F_32 ( * V_29 -> V_20 ) ;
V_3 = F_33 ( V_29 -> V_2 . V_3 ) ;
if ( F_9 ( V_16 >= V_3 ) ) {
V_16 = V_3 ? F_26 () % V_3 : 0 ;
F_34 ( * V_29 -> V_20 , V_16 ) ;
}
V_19 = F_11 ( & V_29 -> V_2 , V_16 , V_29 -> V_21 ) ;
if ( V_19 == - 1 ) {
F_34 ( * V_29 -> V_20 , 0 ) ;
} else if ( V_19 == V_16 || F_9 ( V_29 -> V_21 ) ) {
V_16 = V_19 + 1 ;
if ( V_16 >= V_3 - 1 )
V_16 = 0 ;
F_34 ( * V_29 -> V_20 , V_16 ) ;
}
return V_19 ;
}
static struct V_34 * F_35 ( struct V_28 * V_29 )
{
int V_8 , V_30 ;
V_30 = F_36 ( & V_29 -> V_30 ) ;
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ ) {
struct V_34 * V_31 = & V_29 -> V_31 [ V_30 ] ;
if ( F_37 ( & V_31 -> V_32 ) ) {
int V_35 = F_36 ( & V_29 -> V_30 ) ;
if ( V_30 != V_35 )
F_38 ( & V_29 -> V_30 , V_35 , V_30 ) ;
return V_31 ;
}
V_30 = F_39 ( V_30 ) ;
}
return NULL ;
}
static void F_40 ( struct V_28 * V_29 )
{
struct V_34 * V_31 ;
int V_33 ;
F_41 () ;
V_31 = F_35 ( V_29 ) ;
if ( ! V_31 )
return;
V_33 = F_42 ( & V_31 -> V_33 ) ;
if ( F_9 ( V_33 < 0 ) )
V_33 = F_43 ( & V_31 -> V_33 ) ;
if ( V_33 == 0 ) {
F_44 ( V_29 -> V_25 , & V_31 -> V_33 ) ;
F_45 ( & V_29 -> V_30 ) ;
F_46 ( & V_31 -> V_32 ) ;
}
}
void F_47 ( struct V_28 * V_29 , unsigned int V_19 ,
unsigned int V_36 )
{
F_48 ( & V_29 -> V_2 , V_19 ) ;
F_40 ( V_29 ) ;
if ( F_49 ( ! V_29 -> V_21 && V_19 < V_29 -> V_2 . V_3 ) )
* F_25 ( V_29 -> V_20 , V_36 ) = V_19 ;
}
void F_50 ( struct V_28 * V_29 )
{
int V_8 , V_30 ;
F_41 () ;
V_30 = F_36 ( & V_29 -> V_30 ) ;
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ ) {
struct V_34 * V_31 = & V_29 -> V_31 [ V_30 ] ;
if ( F_37 ( & V_31 -> V_32 ) )
F_46 ( & V_31 -> V_32 ) ;
V_30 = F_39 ( V_30 ) ;
}
}
