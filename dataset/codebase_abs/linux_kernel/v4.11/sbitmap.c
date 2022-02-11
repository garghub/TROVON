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
void F_19 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_20 ( V_26 , L_1 , V_2 -> V_3 ) ;
F_20 ( V_26 , L_2 , F_17 ( V_2 ) ) ;
F_20 ( V_26 , L_3 , 1U << V_2 -> V_4 ) ;
F_20 ( V_26 , L_4 , V_2 -> V_11 ) ;
}
static inline void F_21 ( struct V_25 * V_26 , unsigned int V_27 , T_2 V_28 )
{
if ( ( V_27 & 0xf ) == 0 ) {
if ( V_27 != 0 )
F_22 ( V_26 , '\n' ) ;
F_20 ( V_26 , L_5 , V_27 ) ;
}
if ( ( V_27 & 0x1 ) == 0 )
F_22 ( V_26 , ' ' ) ;
F_20 ( V_26 , L_6 , V_28 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
T_2 V_28 = 0 ;
unsigned int V_29 = 0 ;
unsigned int V_27 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
unsigned long V_15 = F_24 ( V_2 -> V_12 [ V_8 ] . V_15 ) ;
unsigned int V_30 = F_24 ( V_2 -> V_12 [ V_8 ] . V_3 ) ;
while ( V_30 > 0 ) {
unsigned int V_31 = F_5 ( 8 - V_29 , V_30 ) ;
V_28 |= ( V_15 & ( F_25 ( V_31 ) - 1 ) ) << V_29 ;
V_29 += V_31 ;
if ( V_29 == 8 ) {
F_21 ( V_26 , V_27 , V_28 ) ;
V_28 = 0 ;
V_29 = 0 ;
V_27 ++ ;
}
V_15 >>= V_31 ;
V_30 -= V_31 ;
}
}
if ( V_29 ) {
F_21 ( V_26 , V_27 , V_28 ) ;
V_27 ++ ;
}
if ( V_27 )
F_22 ( V_26 , '\n' ) ;
}
static unsigned int F_26 ( unsigned int V_3 )
{
unsigned int V_32 ;
V_32 = V_33 ;
if ( V_32 > V_3 / V_34 )
V_32 = F_27 ( 1U , V_3 / V_34 ) ;
return V_32 ;
}
int F_28 ( struct V_35 * V_36 , unsigned int V_3 ,
int V_4 , bool V_21 , T_1 V_5 , int V_6 )
{
int V_23 ;
int V_8 ;
V_23 = F_1 ( & V_36 -> V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_23 )
return V_23 ;
V_36 -> V_20 = F_29 (unsigned int, flags) ;
if ( ! V_36 -> V_20 ) {
F_30 ( & V_36 -> V_2 ) ;
return - V_13 ;
}
if ( V_3 && ! V_21 ) {
F_31 ( V_8 )
* F_32 ( V_36 -> V_20 , V_8 ) = F_33 () % V_3 ;
}
V_36 -> V_32 = F_26 ( V_3 ) ;
F_34 ( & V_36 -> V_37 , 0 ) ;
V_36 -> V_38 = F_4 ( V_34 * sizeof( * V_36 -> V_38 ) , V_5 , V_6 ) ;
if ( ! V_36 -> V_38 ) {
F_35 ( V_36 -> V_20 ) ;
F_30 ( & V_36 -> V_2 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
F_36 ( & V_36 -> V_38 [ V_8 ] . V_39 ) ;
F_34 ( & V_36 -> V_38 [ V_8 ] . V_40 , V_36 -> V_32 ) ;
}
V_36 -> V_21 = V_21 ;
return 0 ;
}
void F_37 ( struct V_35 * V_36 , unsigned int V_3 )
{
unsigned int V_32 = F_26 ( V_3 ) ;
int V_8 ;
if ( V_36 -> V_32 != V_32 ) {
F_38 ( V_36 -> V_32 , V_32 ) ;
F_39 () ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
F_34 ( & V_36 -> V_38 [ V_8 ] . V_40 , 1 ) ;
}
F_6 ( & V_36 -> V_2 , V_3 ) ;
}
int F_40 ( struct V_35 * V_36 )
{
unsigned int V_16 , V_3 ;
int V_19 ;
V_16 = F_41 ( * V_36 -> V_20 ) ;
V_3 = F_24 ( V_36 -> V_2 . V_3 ) ;
if ( F_9 ( V_16 >= V_3 ) ) {
V_16 = V_3 ? F_33 () % V_3 : 0 ;
F_42 ( * V_36 -> V_20 , V_16 ) ;
}
V_19 = F_11 ( & V_36 -> V_2 , V_16 , V_36 -> V_21 ) ;
if ( V_19 == - 1 ) {
F_42 ( * V_36 -> V_20 , 0 ) ;
} else if ( V_19 == V_16 || F_9 ( V_36 -> V_21 ) ) {
V_16 = V_19 + 1 ;
if ( V_16 >= V_3 - 1 )
V_16 = 0 ;
F_42 ( * V_36 -> V_20 , V_16 ) ;
}
return V_19 ;
}
static struct V_41 * F_43 ( struct V_35 * V_36 )
{
int V_8 , V_37 ;
V_37 = F_44 ( & V_36 -> V_37 ) ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
struct V_41 * V_38 = & V_36 -> V_38 [ V_37 ] ;
if ( F_45 ( & V_38 -> V_39 ) ) {
int V_42 = F_44 ( & V_36 -> V_37 ) ;
if ( V_37 != V_42 )
F_46 ( & V_36 -> V_37 , V_42 , V_37 ) ;
return V_38 ;
}
V_37 = F_47 ( V_37 ) ;
}
return NULL ;
}
static void F_48 ( struct V_35 * V_36 )
{
struct V_41 * V_38 ;
unsigned int V_32 ;
int V_40 ;
F_49 () ;
V_38 = F_43 ( V_36 ) ;
if ( ! V_38 )
return;
V_40 = F_50 ( & V_38 -> V_40 ) ;
if ( V_40 <= 0 ) {
V_32 = F_24 ( V_36 -> V_32 ) ;
F_39 () ;
F_46 ( & V_38 -> V_40 , V_40 , V_40 + V_32 ) ;
F_51 ( & V_36 -> V_37 ) ;
F_52 ( & V_38 -> V_39 ) ;
}
}
void F_53 ( struct V_35 * V_36 , unsigned int V_19 ,
unsigned int V_43 )
{
F_54 ( & V_36 -> V_2 , V_19 ) ;
F_48 ( V_36 ) ;
if ( F_55 ( ! V_36 -> V_21 && V_19 < V_36 -> V_2 . V_3 ) )
* F_32 ( V_36 -> V_20 , V_43 ) = V_19 ;
}
void F_56 ( struct V_35 * V_36 )
{
int V_8 , V_37 ;
F_57 () ;
V_37 = F_44 ( & V_36 -> V_37 ) ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
struct V_41 * V_38 = & V_36 -> V_38 [ V_37 ] ;
if ( F_45 ( & V_38 -> V_39 ) )
F_52 ( & V_38 -> V_39 ) ;
V_37 = F_47 ( V_37 ) ;
}
}
void F_58 ( struct V_35 * V_36 , struct V_25 * V_26 )
{
bool V_44 ;
int V_8 ;
F_19 ( & V_36 -> V_2 , V_26 ) ;
F_59 ( V_26 , L_7 ) ;
V_44 = true ;
F_31 (i) {
if ( ! V_44 )
F_59 ( V_26 , L_8 ) ;
V_44 = false ;
F_20 ( V_26 , L_9 , * F_32 ( V_36 -> V_20 , V_8 ) ) ;
}
F_59 ( V_26 , L_10 ) ;
F_20 ( V_26 , L_11 , V_36 -> V_32 ) ;
F_20 ( V_26 , L_12 , F_44 ( & V_36 -> V_37 ) ) ;
F_59 ( V_26 , L_13 ) ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
struct V_41 * V_38 = & V_36 -> V_38 [ V_8 ] ;
F_20 ( V_26 , L_14 ,
F_44 ( & V_38 -> V_40 ) ,
F_45 ( & V_38 -> V_39 ) ? L_15 : L_16 ) ;
}
F_59 ( V_26 , L_10 ) ;
F_20 ( V_26 , L_17 , V_36 -> V_21 ) ;
}
