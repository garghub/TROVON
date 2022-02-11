int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 , V_10 ;
F_2 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = NULL ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_13 = & V_4 -> V_14 ;
F_3 ( & V_4 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_15 ; ++ V_9 ) {
F_3 ( & V_4 -> V_16 [ V_9 ] ) ;
}
V_10 = F_4 ( V_2 , V_5 , V_6 , true ,
V_7 , V_8 , NULL , & V_4 -> V_12 ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_17 , L_1 , V_10 ) ;
return V_10 ;
}
return V_10 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 , * V_20 ;
if ( ! F_7 ( & V_4 -> V_14 ) ) {
V_4 -> V_13 = & V_4 -> V_14 ,
F_8 ( V_4 ) ;
if ( ! F_7 ( & V_4 -> V_14 ) ) {
F_5 ( V_2 -> V_17 , L_2 ) ;
}
}
F_9 (sa_bo, tmp, &sa_manager->olist, olist) {
F_10 ( V_19 ) ;
}
F_11 ( & V_4 -> V_12 ) ;
V_4 -> V_5 = 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_10 ;
if ( V_4 -> V_12 == NULL ) {
F_5 ( V_2 -> V_17 , L_3 ) ;
return - V_21 ;
}
V_10 = F_13 ( V_4 -> V_12 , false ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_17 , L_4 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_4 -> V_12 , V_4 -> V_7 , & V_4 -> V_22 ) ;
if ( V_10 ) {
F_15 ( V_4 -> V_12 ) ;
F_5 ( V_2 -> V_17 , L_5 , V_10 ) ;
return V_10 ;
}
V_10 = F_16 ( V_4 -> V_12 , & V_4 -> V_23 ) ;
F_15 ( V_4 -> V_12 ) ;
return V_10 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_10 ;
if ( V_4 -> V_12 == NULL ) {
F_5 ( V_2 -> V_17 , L_3 ) ;
return - V_21 ;
}
V_10 = F_13 ( V_4 -> V_12 , false ) ;
if ( ! V_10 ) {
F_18 ( V_4 -> V_12 ) ;
F_19 ( V_4 -> V_12 ) ;
F_15 ( V_4 -> V_12 ) ;
}
return V_10 ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_24 ;
if ( V_4 -> V_13 == & V_19 -> V_14 ) {
V_4 -> V_13 = V_19 -> V_14 . V_25 ;
}
F_20 ( & V_19 -> V_14 ) ;
F_20 ( & V_19 -> V_16 ) ;
F_21 ( & V_19 -> V_26 ) ;
F_22 ( V_19 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_18 * V_19 , * V_20 ;
if ( V_4 -> V_13 -> V_27 == & V_4 -> V_14 )
return;
V_19 = F_23 ( V_4 -> V_13 -> V_27 , struct V_18 , V_14 ) ;
F_24 (sa_bo, tmp, &sa_manager->olist, olist) {
if ( V_19 -> V_26 == NULL || ! F_25 ( V_19 -> V_26 ) ) {
return;
}
F_10 ( V_19 ) ;
}
}
static inline unsigned F_26 ( struct V_3 * V_4 )
{
struct V_28 * V_13 = V_4 -> V_13 ;
if ( V_13 != & V_4 -> V_14 ) {
return F_23 ( V_13 , struct V_18 , V_14 ) -> V_29 ;
}
return 0 ;
}
static inline unsigned F_27 ( struct V_3 * V_4 )
{
struct V_28 * V_13 = V_4 -> V_13 ;
if ( V_13 -> V_27 != & V_4 -> V_14 ) {
return F_23 ( V_13 -> V_27 , struct V_18 , V_14 ) -> V_30 ;
}
return V_4 -> V_5 ;
}
static bool F_28 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
unsigned V_5 , unsigned V_6 )
{
unsigned V_30 , V_29 , V_31 ;
V_30 = F_26 ( V_4 ) ;
V_29 = F_27 ( V_4 ) ;
V_31 = ( V_6 - ( V_30 % V_6 ) ) % V_6 ;
if ( ( V_29 - V_30 ) >= ( V_5 + V_31 ) ) {
V_30 += V_31 ;
V_19 -> V_24 = V_4 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_29 = V_30 + V_5 ;
F_29 ( & V_19 -> V_14 , V_4 -> V_13 ) ;
F_3 ( & V_19 -> V_16 ) ;
V_4 -> V_13 = & V_19 -> V_14 ;
return true ;
}
return false ;
}
static bool F_30 ( struct V_3 * V_4 ,
unsigned V_5 , unsigned V_6 )
{
unsigned V_30 , V_29 , V_31 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_15 ; ++ V_9 ) {
if ( ! F_7 ( & V_4 -> V_16 [ V_9 ] ) ) {
return true ;
}
}
V_30 = F_26 ( V_4 ) ;
V_29 = F_27 ( V_4 ) ;
V_31 = ( V_6 - ( V_30 % V_6 ) ) % V_6 ;
if ( ( V_29 - V_30 ) >= ( V_5 + V_31 ) ) {
return true ;
}
return false ;
}
static bool F_31 ( struct V_3 * V_4 ,
struct V_32 * * V_33 ,
unsigned * V_34 )
{
struct V_18 * V_35 = NULL ;
unsigned V_9 , V_30 , V_36 , V_20 ;
if ( V_4 -> V_13 -> V_27 == & V_4 -> V_14 ) {
V_4 -> V_13 = & V_4 -> V_14 ;
return true ;
}
V_30 = F_26 ( V_4 ) ;
V_36 = V_4 -> V_5 * 2 ;
for ( V_9 = 0 ; V_9 < V_15 ; ++ V_9 ) {
struct V_18 * V_19 ;
if ( F_7 ( & V_4 -> V_16 [ V_9 ] ) ) {
continue;
}
V_19 = F_32 ( & V_4 -> V_16 [ V_9 ] ,
struct V_18 , V_16 ) ;
if ( ! F_25 ( V_19 -> V_26 ) ) {
V_33 [ V_9 ] = V_19 -> V_26 ;
continue;
}
if ( V_34 [ V_9 ] > 2 ) {
continue;
}
V_20 = V_19 -> V_30 ;
if ( V_20 < V_30 ) {
V_20 += V_4 -> V_5 ;
}
V_20 -= V_30 ;
if ( V_20 < V_36 ) {
V_36 = V_20 ;
V_35 = V_19 ;
}
}
if ( V_35 ) {
++ V_34 [ V_35 -> V_26 -> V_37 ] ;
V_4 -> V_13 = V_35 -> V_14 . V_25 ;
F_10 ( V_35 ) ;
return true ;
}
return false ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * * V_19 ,
unsigned V_5 , unsigned V_6 )
{
struct V_32 * V_33 [ V_15 ] ;
unsigned V_34 [ V_15 ] ;
int V_9 , V_10 ;
F_34 ( V_6 > V_4 -> V_6 ) ;
F_34 ( V_5 > V_4 -> V_5 ) ;
* V_19 = F_35 ( sizeof( struct V_18 ) , V_38 ) ;
if ( ( * V_19 ) == NULL ) {
return - V_39 ;
}
( * V_19 ) -> V_24 = V_4 ;
( * V_19 ) -> V_26 = NULL ;
F_3 ( & ( * V_19 ) -> V_14 ) ;
F_3 ( & ( * V_19 ) -> V_16 ) ;
F_36 ( & V_4 -> V_11 . V_40 ) ;
do {
for ( V_9 = 0 ; V_9 < V_15 ; ++ V_9 ) {
V_33 [ V_9 ] = NULL ;
V_34 [ V_9 ] = 0 ;
}
do {
F_8 ( V_4 ) ;
if ( F_28 ( V_4 , * V_19 ,
V_5 , V_6 ) ) {
F_37 ( & V_4 -> V_11 . V_40 ) ;
return 0 ;
}
} while ( F_31 ( V_4 , V_33 , V_34 ) );
F_37 ( & V_4 -> V_11 . V_40 ) ;
V_10 = F_38 ( V_2 , V_33 , false ) ;
F_36 ( & V_4 -> V_11 . V_40 ) ;
if ( V_10 == - V_41 ) {
V_10 = F_39 (
V_4 -> V_11 ,
F_30 ( V_4 , V_5 , V_6 )
) ;
}
} while ( ! V_10 );
F_37 ( & V_4 -> V_11 . V_40 ) ;
F_22 ( * V_19 ) ;
* V_19 = NULL ;
return V_10 ;
}
void F_40 ( struct V_1 * V_2 , struct V_18 * * V_19 ,
struct V_32 * V_26 )
{
struct V_3 * V_4 ;
if ( V_19 == NULL || * V_19 == NULL ) {
return;
}
V_4 = ( * V_19 ) -> V_24 ;
F_36 ( & V_4 -> V_11 . V_40 ) ;
if ( V_26 && ! F_25 ( V_26 ) ) {
( * V_19 ) -> V_26 = F_41 ( V_26 ) ;
F_42 ( & ( * V_19 ) -> V_16 ,
& V_4 -> V_16 [ V_26 -> V_37 ] ) ;
} else {
F_10 ( * V_19 ) ;
}
F_43 ( & V_4 -> V_11 ) ;
F_37 ( & V_4 -> V_11 . V_40 ) ;
* V_19 = NULL ;
}
void F_44 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_18 * V_9 ;
F_36 ( & V_4 -> V_11 . V_40 ) ;
F_45 (i, &sa_manager->olist, olist) {
T_2 V_30 = V_9 -> V_30 + V_4 -> V_22 ;
T_2 V_29 = V_9 -> V_29 + V_4 -> V_22 ;
if ( & V_9 -> V_14 == V_4 -> V_13 ) {
F_46 ( V_43 , L_6 ) ;
} else {
F_46 ( V_43 , L_7 ) ;
}
F_46 ( V_43 , L_8 ,
V_30 , V_29 , V_29 - V_30 ) ;
if ( V_9 -> V_26 ) {
F_46 ( V_43 , L_9 ,
V_9 -> V_26 -> V_44 , V_9 -> V_26 -> V_37 ) ;
}
F_46 ( V_43 , L_10 ) ;
}
F_37 ( & V_4 -> V_11 . V_40 ) ;
}
