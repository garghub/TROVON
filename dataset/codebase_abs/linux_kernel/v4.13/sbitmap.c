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
static int F_7 ( unsigned long * V_14 , unsigned long V_3 ,
unsigned int V_15 , bool V_16 )
{
unsigned int V_17 = V_15 ;
int V_18 ;
while ( 1 ) {
V_18 = F_8 ( V_14 , V_3 , V_15 ) ;
if ( F_9 ( V_18 >= V_3 ) ) {
if ( V_17 && V_15 && V_16 ) {
V_15 = V_17 = 0 ;
continue;
}
return - 1 ;
}
if ( ! F_10 ( V_18 , V_14 ) )
break;
V_15 = V_18 + 1 ;
if ( V_15 >= V_3 - 1 )
V_15 = 0 ;
}
return V_18 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_19 , bool V_20 )
{
unsigned int V_8 , V_21 ;
int V_18 = - 1 ;
V_21 = F_12 ( V_2 , V_19 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
V_18 = F_7 ( & V_2 -> V_12 [ V_21 ] . V_14 ,
V_2 -> V_12 [ V_21 ] . V_3 ,
F_13 ( V_2 , V_19 ) ,
! V_20 ) ;
if ( V_18 != - 1 ) {
V_18 += V_21 << V_2 -> V_4 ;
break;
}
V_21 ++ ;
V_19 = V_21 << V_2 -> V_4 ;
if ( V_21 >= V_2 -> V_11 ) {
V_21 = 0 ;
V_19 = 0 ;
}
}
return V_18 ;
}
int F_14 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned long V_22 )
{
unsigned int V_8 , V_21 ;
int V_18 = - 1 ;
V_21 = F_12 ( V_2 , V_19 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
V_18 = F_7 ( & V_2 -> V_12 [ V_21 ] . V_14 ,
F_5 ( V_2 -> V_12 [ V_21 ] . V_3 , V_22 ) ,
F_13 ( V_2 , V_19 ) , true ) ;
if ( V_18 != - 1 ) {
V_18 += V_21 << V_2 -> V_4 ;
break;
}
V_21 ++ ;
V_19 = V_21 << V_2 -> V_4 ;
if ( V_21 >= V_2 -> V_11 ) {
V_21 = 0 ;
V_19 = 0 ;
}
}
return V_18 ;
}
bool F_15 ( const struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] . V_14 )
return true ;
}
return false ;
}
bool F_16 ( const struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
const struct V_23 * V_14 = & V_2 -> V_12 [ V_8 ] ;
unsigned long V_24 ;
V_24 = F_17 ( & V_14 -> V_14 , V_14 -> V_3 ) ;
if ( V_24 < V_14 -> V_3 )
return true ;
}
return false ;
}
unsigned int F_18 ( const struct V_1 * V_2 )
{
unsigned int V_8 , V_25 = 0 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
const struct V_23 * V_14 = & V_2 -> V_12 [ V_8 ] ;
V_25 += F_19 ( & V_14 -> V_14 , V_14 -> V_3 ) ;
}
return V_25 ;
}
void F_20 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
F_21 ( V_27 , L_1 , V_2 -> V_3 ) ;
F_21 ( V_27 , L_2 , F_18 ( V_2 ) ) ;
F_21 ( V_27 , L_3 , 1U << V_2 -> V_4 ) ;
F_21 ( V_27 , L_4 , V_2 -> V_11 ) ;
}
static inline void F_22 ( struct V_26 * V_27 , unsigned int V_28 , T_2 V_29 )
{
if ( ( V_28 & 0xf ) == 0 ) {
if ( V_28 != 0 )
F_23 ( V_27 , '\n' ) ;
F_21 ( V_27 , L_5 , V_28 ) ;
}
if ( ( V_28 & 0x1 ) == 0 )
F_23 ( V_27 , ' ' ) ;
F_21 ( V_27 , L_6 , V_29 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
T_2 V_29 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_28 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_11 ; V_8 ++ ) {
unsigned long V_14 = F_25 ( V_2 -> V_12 [ V_8 ] . V_14 ) ;
unsigned int V_31 = F_25 ( V_2 -> V_12 [ V_8 ] . V_3 ) ;
while ( V_31 > 0 ) {
unsigned int V_32 = F_5 ( 8 - V_30 , V_31 ) ;
V_29 |= ( V_14 & ( F_26 ( V_32 ) - 1 ) ) << V_30 ;
V_30 += V_32 ;
if ( V_30 == 8 ) {
F_22 ( V_27 , V_28 , V_29 ) ;
V_29 = 0 ;
V_30 = 0 ;
V_28 ++ ;
}
V_14 >>= V_32 ;
V_31 -= V_32 ;
}
}
if ( V_30 ) {
F_22 ( V_27 , V_28 , V_29 ) ;
V_28 ++ ;
}
if ( V_28 )
F_23 ( V_27 , '\n' ) ;
}
static unsigned int F_27 ( unsigned int V_3 )
{
unsigned int V_33 ;
V_33 = V_34 ;
if ( V_33 > V_3 / V_35 )
V_33 = F_28 ( 1U , V_3 / V_35 ) ;
return V_33 ;
}
int F_29 ( struct V_36 * V_37 , unsigned int V_3 ,
int V_4 , bool V_20 , T_1 V_5 , int V_6 )
{
int V_24 ;
int V_8 ;
V_24 = F_1 ( & V_37 -> V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_24 )
return V_24 ;
V_37 -> V_19 = F_30 (unsigned int, flags) ;
if ( ! V_37 -> V_19 ) {
F_31 ( & V_37 -> V_2 ) ;
return - V_13 ;
}
if ( V_3 && ! V_20 ) {
F_32 ( V_8 )
* F_33 ( V_37 -> V_19 , V_8 ) = F_34 () % V_3 ;
}
V_37 -> V_33 = F_27 ( V_3 ) ;
F_35 ( & V_37 -> V_38 , 0 ) ;
V_37 -> V_39 = F_4 ( V_35 * sizeof( * V_37 -> V_39 ) , V_5 , V_6 ) ;
if ( ! V_37 -> V_39 ) {
F_36 ( V_37 -> V_19 ) ;
F_31 ( & V_37 -> V_2 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
F_37 ( & V_37 -> V_39 [ V_8 ] . V_40 ) ;
F_35 ( & V_37 -> V_39 [ V_8 ] . V_41 , V_37 -> V_33 ) ;
}
V_37 -> V_20 = V_20 ;
return 0 ;
}
void F_38 ( struct V_36 * V_37 , unsigned int V_3 )
{
unsigned int V_33 = F_27 ( V_3 ) ;
int V_8 ;
if ( V_37 -> V_33 != V_33 ) {
F_39 ( V_37 -> V_33 , V_33 ) ;
F_40 () ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ )
F_35 ( & V_37 -> V_39 [ V_8 ] . V_41 , 1 ) ;
}
F_6 ( & V_37 -> V_2 , V_3 ) ;
}
int F_41 ( struct V_36 * V_37 )
{
unsigned int V_15 , V_3 ;
int V_18 ;
V_15 = F_42 ( * V_37 -> V_19 ) ;
V_3 = F_25 ( V_37 -> V_2 . V_3 ) ;
if ( F_9 ( V_15 >= V_3 ) ) {
V_15 = V_3 ? F_34 () % V_3 : 0 ;
F_43 ( * V_37 -> V_19 , V_15 ) ;
}
V_18 = F_11 ( & V_37 -> V_2 , V_15 , V_37 -> V_20 ) ;
if ( V_18 == - 1 ) {
F_43 ( * V_37 -> V_19 , 0 ) ;
} else if ( V_18 == V_15 || F_9 ( V_37 -> V_20 ) ) {
V_15 = V_18 + 1 ;
if ( V_15 >= V_3 - 1 )
V_15 = 0 ;
F_43 ( * V_37 -> V_19 , V_15 ) ;
}
return V_18 ;
}
int F_44 ( struct V_36 * V_37 ,
unsigned int V_22 )
{
unsigned int V_15 , V_3 ;
int V_18 ;
V_15 = F_42 ( * V_37 -> V_19 ) ;
V_3 = F_25 ( V_37 -> V_2 . V_3 ) ;
if ( F_9 ( V_15 >= V_3 ) ) {
V_15 = V_3 ? F_34 () % V_3 : 0 ;
F_43 ( * V_37 -> V_19 , V_15 ) ;
}
V_18 = F_14 ( & V_37 -> V_2 , V_15 , V_22 ) ;
if ( V_18 == - 1 ) {
F_43 ( * V_37 -> V_19 , 0 ) ;
} else if ( V_18 == V_15 || F_9 ( V_37 -> V_20 ) ) {
V_15 = V_18 + 1 ;
if ( V_15 >= V_3 - 1 )
V_15 = 0 ;
F_43 ( * V_37 -> V_19 , V_15 ) ;
}
return V_18 ;
}
static struct V_42 * F_45 ( struct V_36 * V_37 )
{
int V_8 , V_38 ;
V_38 = F_46 ( & V_37 -> V_38 ) ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
struct V_42 * V_39 = & V_37 -> V_39 [ V_38 ] ;
if ( F_47 ( & V_39 -> V_40 ) ) {
int V_43 = F_46 ( & V_37 -> V_38 ) ;
if ( V_38 != V_43 )
F_48 ( & V_37 -> V_38 , V_43 , V_38 ) ;
return V_39 ;
}
V_38 = F_49 ( V_38 ) ;
}
return NULL ;
}
static void F_50 ( struct V_36 * V_37 )
{
struct V_42 * V_39 ;
unsigned int V_33 ;
int V_41 ;
F_51 () ;
V_39 = F_45 ( V_37 ) ;
if ( ! V_39 )
return;
V_41 = F_52 ( & V_39 -> V_41 ) ;
if ( V_41 <= 0 ) {
V_33 = F_25 ( V_37 -> V_33 ) ;
F_40 () ;
F_48 ( & V_39 -> V_41 , V_41 , V_41 + V_33 ) ;
F_53 ( & V_37 -> V_38 ) ;
F_54 ( & V_39 -> V_40 ) ;
}
}
void F_55 ( struct V_36 * V_37 , unsigned int V_18 ,
unsigned int V_44 )
{
F_56 ( & V_37 -> V_2 , V_18 ) ;
F_50 ( V_37 ) ;
if ( F_57 ( ! V_37 -> V_20 && V_18 < V_37 -> V_2 . V_3 ) )
* F_33 ( V_37 -> V_19 , V_44 ) = V_18 ;
}
void F_58 ( struct V_36 * V_37 )
{
int V_8 , V_38 ;
F_59 () ;
V_38 = F_46 ( & V_37 -> V_38 ) ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
struct V_42 * V_39 = & V_37 -> V_39 [ V_38 ] ;
if ( F_47 ( & V_39 -> V_40 ) )
F_54 ( & V_39 -> V_40 ) ;
V_38 = F_49 ( V_38 ) ;
}
}
void F_60 ( struct V_36 * V_37 , struct V_26 * V_27 )
{
bool V_45 ;
int V_8 ;
F_20 ( & V_37 -> V_2 , V_27 ) ;
F_61 ( V_27 , L_7 ) ;
V_45 = true ;
F_32 (i) {
if ( ! V_45 )
F_61 ( V_27 , L_8 ) ;
V_45 = false ;
F_21 ( V_27 , L_9 , * F_33 ( V_37 -> V_19 , V_8 ) ) ;
}
F_61 ( V_27 , L_10 ) ;
F_21 ( V_27 , L_11 , V_37 -> V_33 ) ;
F_21 ( V_27 , L_12 , F_46 ( & V_37 -> V_38 ) ) ;
F_61 ( V_27 , L_13 ) ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
struct V_42 * V_39 = & V_37 -> V_39 [ V_8 ] ;
F_21 ( V_27 , L_14 ,
F_46 ( & V_39 -> V_41 ) ,
F_47 ( & V_39 -> V_40 ) ? L_15 : L_16 ) ;
}
F_61 ( V_27 , L_10 ) ;
F_21 ( V_27 , L_17 , V_37 -> V_20 ) ;
}
