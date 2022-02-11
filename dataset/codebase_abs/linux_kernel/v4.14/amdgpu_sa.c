int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 , T_1 V_6 , T_1 V_7 )
{
int V_8 , V_9 ;
F_2 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = NULL ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_12 = & V_4 -> V_13 ;
F_3 ( & V_4 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 )
F_3 ( & V_4 -> V_15 [ V_8 ] ) ;
V_9 = F_4 ( V_2 , V_5 , V_6 , true , V_7 ,
0 , NULL , NULL , 0 , & V_4 -> V_11 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_1 , V_9 ) ;
return V_9 ;
}
return V_9 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 , * V_19 ;
if ( ! F_7 ( & V_4 -> V_13 ) ) {
V_4 -> V_12 = & V_4 -> V_13 ,
F_8 ( V_4 ) ;
if ( ! F_7 ( & V_4 -> V_13 ) ) {
F_5 ( V_2 -> V_16 , L_2 ) ;
}
}
F_9 (sa_bo, tmp, &sa_manager->olist, olist) {
F_10 ( V_18 ) ;
}
F_11 ( & V_4 -> V_11 ) ;
V_4 -> V_5 = 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 ;
if ( V_4 -> V_11 == NULL ) {
F_5 ( V_2 -> V_16 , L_3 ) ;
return - V_20 ;
}
V_9 = F_13 ( V_4 -> V_11 , false ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_14 ( V_4 -> V_11 , V_4 -> V_7 , & V_4 -> V_21 ) ;
if ( V_9 ) {
F_15 ( V_4 -> V_11 ) ;
F_5 ( V_2 -> V_16 , L_5 , V_9 ) ;
return V_9 ;
}
V_9 = F_16 ( V_4 -> V_11 , & V_4 -> V_22 ) ;
memset ( V_4 -> V_22 , 0 , V_4 -> V_5 ) ;
F_15 ( V_4 -> V_11 ) ;
return V_9 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 ;
if ( V_4 -> V_11 == NULL ) {
F_5 ( V_2 -> V_16 , L_3 ) ;
return - V_20 ;
}
V_9 = F_13 ( V_4 -> V_11 , true ) ;
if ( ! V_9 ) {
F_18 ( V_4 -> V_11 ) ;
F_19 ( V_4 -> V_11 ) ;
F_15 ( V_4 -> V_11 ) ;
}
return V_9 ;
}
static void F_10 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_23 ;
if ( V_4 -> V_12 == & V_18 -> V_13 ) {
V_4 -> V_12 = V_18 -> V_13 . V_24 ;
}
F_20 ( & V_18 -> V_13 ) ;
F_20 ( & V_18 -> V_15 ) ;
F_21 ( V_18 -> V_25 ) ;
F_22 ( V_18 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_17 * V_18 , * V_19 ;
if ( V_4 -> V_12 -> V_26 == & V_4 -> V_13 )
return;
V_18 = F_23 ( V_4 -> V_12 -> V_26 , struct V_17 , V_13 ) ;
F_24 (sa_bo, tmp, &sa_manager->olist, olist) {
if ( V_18 -> V_25 == NULL ||
! F_25 ( V_18 -> V_25 ) ) {
return;
}
F_10 ( V_18 ) ;
}
}
static inline unsigned F_26 ( struct V_3 * V_4 )
{
struct V_27 * V_12 = V_4 -> V_12 ;
if ( V_12 != & V_4 -> V_13 ) {
return F_23 ( V_12 , struct V_17 , V_13 ) -> V_28 ;
}
return 0 ;
}
static inline unsigned F_27 ( struct V_3 * V_4 )
{
struct V_27 * V_12 = V_4 -> V_12 ;
if ( V_12 -> V_26 != & V_4 -> V_13 ) {
return F_23 ( V_12 -> V_26 , struct V_17 , V_13 ) -> V_29 ;
}
return V_4 -> V_5 ;
}
static bool F_28 ( struct V_3 * V_4 ,
struct V_17 * V_18 ,
unsigned V_5 , unsigned V_6 )
{
unsigned V_29 , V_28 , V_30 ;
V_29 = F_26 ( V_4 ) ;
V_28 = F_27 ( V_4 ) ;
V_30 = ( V_6 - ( V_29 % V_6 ) ) % V_6 ;
if ( ( V_28 - V_29 ) >= ( V_5 + V_30 ) ) {
V_29 += V_30 ;
V_18 -> V_23 = V_4 ;
V_18 -> V_29 = V_29 ;
V_18 -> V_28 = V_29 + V_5 ;
F_29 ( & V_18 -> V_13 , V_4 -> V_12 ) ;
F_3 ( & V_18 -> V_15 ) ;
V_4 -> V_12 = & V_18 -> V_13 ;
return true ;
}
return false ;
}
static bool F_30 ( struct V_3 * V_4 ,
unsigned V_5 , unsigned V_6 )
{
unsigned V_29 , V_28 , V_30 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 )
if ( ! F_7 ( & V_4 -> V_15 [ V_8 ] ) )
return true ;
V_29 = F_26 ( V_4 ) ;
V_28 = F_27 ( V_4 ) ;
V_30 = ( V_6 - ( V_29 % V_6 ) ) % V_6 ;
if ( ( V_28 - V_29 ) >= ( V_5 + V_30 ) ) {
return true ;
}
return false ;
}
static bool F_31 ( struct V_3 * V_4 ,
struct V_31 * * V_32 ,
unsigned * V_33 )
{
struct V_17 * V_34 = NULL ;
unsigned V_8 , V_29 , V_35 , V_19 ;
if ( V_4 -> V_12 -> V_26 == & V_4 -> V_13 ) {
V_4 -> V_12 = & V_4 -> V_13 ;
return true ;
}
V_29 = F_26 ( V_4 ) ;
V_35 = V_4 -> V_5 * 2 ;
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
struct V_17 * V_18 ;
if ( F_7 ( & V_4 -> V_15 [ V_8 ] ) )
continue;
V_18 = F_32 ( & V_4 -> V_15 [ V_8 ] ,
struct V_17 , V_15 ) ;
if ( ! F_25 ( V_18 -> V_25 ) ) {
V_32 [ V_8 ] = V_18 -> V_25 ;
continue;
}
if ( V_33 [ V_8 ] > 2 ) {
continue;
}
V_19 = V_18 -> V_29 ;
if ( V_19 < V_29 ) {
V_19 += V_4 -> V_5 ;
}
V_19 -= V_29 ;
if ( V_19 < V_35 ) {
V_35 = V_19 ;
V_34 = V_18 ;
}
}
if ( V_34 ) {
T_2 V_36 = V_34 -> V_25 -> V_37 ;
V_36 %= V_14 ;
++ V_33 [ V_36 ] ;
V_4 -> V_12 = V_34 -> V_13 . V_24 ;
F_10 ( V_34 ) ;
return true ;
}
return false ;
}
int F_33 ( struct V_3 * V_4 ,
struct V_17 * * V_18 ,
unsigned V_5 , unsigned V_6 )
{
struct V_31 * V_32 [ V_14 ] ;
unsigned V_33 [ V_14 ] ;
unsigned V_38 ;
int V_8 , V_9 ;
signed long V_39 ;
if ( F_34 ( V_6 > V_4 -> V_6 ) )
return - V_20 ;
if ( F_34 ( V_5 > V_4 -> V_5 ) )
return - V_20 ;
* V_18 = F_35 ( sizeof( struct V_17 ) , V_40 ) ;
if ( ! ( * V_18 ) )
return - V_41 ;
( * V_18 ) -> V_23 = V_4 ;
( * V_18 ) -> V_25 = NULL ;
F_3 ( & ( * V_18 ) -> V_13 ) ;
F_3 ( & ( * V_18 ) -> V_15 ) ;
F_36 ( & V_4 -> V_10 . V_42 ) ;
do {
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
V_32 [ V_8 ] = NULL ;
V_33 [ V_8 ] = 0 ;
}
do {
F_8 ( V_4 ) ;
if ( F_28 ( V_4 , * V_18 ,
V_5 , V_6 ) ) {
F_37 ( & V_4 -> V_10 . V_42 ) ;
return 0 ;
}
} while ( F_31 ( V_4 , V_32 , V_33 ) );
for ( V_8 = 0 , V_38 = 0 ; V_8 < V_14 ; ++ V_8 )
if ( V_32 [ V_8 ] )
V_32 [ V_38 ++ ] = F_38 ( V_32 [ V_8 ] ) ;
if ( V_38 ) {
F_37 ( & V_4 -> V_10 . V_42 ) ;
V_39 = F_39 ( V_32 , V_38 , false ,
V_43 ,
NULL ) ;
for ( V_8 = 0 ; V_8 < V_38 ; ++ V_8 )
F_21 ( V_32 [ V_8 ] ) ;
V_9 = ( V_39 > 0 ) ? 0 : V_39 ;
F_36 ( & V_4 -> V_10 . V_42 ) ;
} else {
V_9 = F_40 (
V_4 -> V_10 ,
F_30 ( V_4 , V_5 , V_6 )
) ;
}
} while ( ! V_9 );
F_37 ( & V_4 -> V_10 . V_42 ) ;
F_22 ( * V_18 ) ;
* V_18 = NULL ;
return V_9 ;
}
void F_41 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
struct V_31 * V_25 )
{
struct V_3 * V_4 ;
if ( V_18 == NULL || * V_18 == NULL ) {
return;
}
V_4 = ( * V_18 ) -> V_23 ;
F_36 ( & V_4 -> V_10 . V_42 ) ;
if ( V_25 && ! F_25 ( V_25 ) ) {
T_2 V_36 ;
( * V_18 ) -> V_25 = F_38 ( V_25 ) ;
V_36 = V_25 -> V_37 % V_14 ;
F_42 ( & ( * V_18 ) -> V_15 , & V_4 -> V_15 [ V_36 ] ) ;
} else {
F_10 ( * V_18 ) ;
}
F_43 ( & V_4 -> V_10 ) ;
F_37 ( & V_4 -> V_10 . V_42 ) ;
* V_18 = NULL ;
}
void F_44 ( struct V_3 * V_4 ,
struct V_44 * V_45 )
{
struct V_17 * V_8 ;
F_36 ( & V_4 -> V_10 . V_42 ) ;
F_45 (i, &sa_manager->olist, olist) {
T_3 V_29 = V_8 -> V_29 + V_4 -> V_21 ;
T_3 V_28 = V_8 -> V_28 + V_4 -> V_21 ;
if ( & V_8 -> V_13 == V_4 -> V_12 ) {
F_46 ( V_45 , L_6 ) ;
} else {
F_46 ( V_45 , L_7 ) ;
}
F_46 ( V_45 , L_8 ,
V_29 , V_28 , V_28 - V_29 ) ;
if ( V_8 -> V_25 )
F_46 ( V_45 , L_9 ,
V_8 -> V_25 -> V_46 , V_8 -> V_25 -> V_37 ) ;
F_46 ( V_45 , L_10 ) ;
}
F_37 ( & V_4 -> V_10 . V_42 ) ;
}
