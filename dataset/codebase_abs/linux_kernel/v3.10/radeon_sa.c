int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 , T_1 V_6 )
{
int V_7 , V_8 ;
F_2 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = NULL ;
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_11 = & V_4 -> V_12 ;
F_3 ( & V_4 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; ++ V_7 ) {
F_3 ( & V_4 -> V_14 [ V_7 ] ) ;
}
V_8 = F_4 ( V_2 , V_5 , V_15 , true ,
V_6 , NULL , & V_4 -> V_10 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_16 , L_1 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 , * V_19 ;
if ( ! F_7 ( & V_4 -> V_12 ) ) {
V_4 -> V_11 = & V_4 -> V_12 ,
F_8 ( V_4 ) ;
if ( ! F_7 ( & V_4 -> V_12 ) ) {
F_5 ( V_2 -> V_16 , L_2 ) ;
}
}
F_9 (sa_bo, tmp, &sa_manager->olist, olist) {
F_10 ( V_18 ) ;
}
F_11 ( & V_4 -> V_10 ) ;
V_4 -> V_5 = 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
if ( V_4 -> V_10 == NULL ) {
F_5 ( V_2 -> V_16 , L_3 ) ;
return - V_20 ;
}
V_8 = F_13 ( V_4 -> V_10 , false ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_16 , L_4 , V_8 ) ;
return V_8 ;
}
V_8 = F_14 ( V_4 -> V_10 , V_4 -> V_6 , & V_4 -> V_21 ) ;
if ( V_8 ) {
F_15 ( V_4 -> V_10 ) ;
F_5 ( V_2 -> V_16 , L_5 , V_8 ) ;
return V_8 ;
}
V_8 = F_16 ( V_4 -> V_10 , & V_4 -> V_22 ) ;
F_15 ( V_4 -> V_10 ) ;
return V_8 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
if ( V_4 -> V_10 == NULL ) {
F_5 ( V_2 -> V_16 , L_3 ) ;
return - V_20 ;
}
V_8 = F_13 ( V_4 -> V_10 , false ) ;
if ( ! V_8 ) {
F_18 ( V_4 -> V_10 ) ;
F_19 ( V_4 -> V_10 ) ;
F_15 ( V_4 -> V_10 ) ;
}
return V_8 ;
}
static void F_10 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_23 ;
if ( V_4 -> V_11 == & V_18 -> V_12 ) {
V_4 -> V_11 = V_18 -> V_12 . V_24 ;
}
F_20 ( & V_18 -> V_12 ) ;
F_20 ( & V_18 -> V_14 ) ;
F_21 ( & V_18 -> V_25 ) ;
F_22 ( V_18 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_17 * V_18 , * V_19 ;
if ( V_4 -> V_11 -> V_26 == & V_4 -> V_12 )
return;
V_18 = F_23 ( V_4 -> V_11 -> V_26 , struct V_17 , V_12 ) ;
F_24 (sa_bo, tmp, &sa_manager->olist, olist) {
if ( V_18 -> V_25 == NULL || ! F_25 ( V_18 -> V_25 ) ) {
return;
}
F_10 ( V_18 ) ;
}
}
static inline unsigned F_26 ( struct V_3 * V_4 )
{
struct V_27 * V_11 = V_4 -> V_11 ;
if ( V_11 != & V_4 -> V_12 ) {
return F_23 ( V_11 , struct V_17 , V_12 ) -> V_28 ;
}
return 0 ;
}
static inline unsigned F_27 ( struct V_3 * V_4 )
{
struct V_27 * V_11 = V_4 -> V_11 ;
if ( V_11 -> V_26 != & V_4 -> V_12 ) {
return F_23 ( V_11 -> V_26 , struct V_17 , V_12 ) -> V_29 ;
}
return V_4 -> V_5 ;
}
static bool F_28 ( struct V_3 * V_4 ,
struct V_17 * V_18 ,
unsigned V_5 , unsigned V_30 )
{
unsigned V_29 , V_28 , V_31 ;
V_29 = F_26 ( V_4 ) ;
V_28 = F_27 ( V_4 ) ;
V_31 = ( V_30 - ( V_29 % V_30 ) ) % V_30 ;
if ( ( V_28 - V_29 ) >= ( V_5 + V_31 ) ) {
V_29 += V_31 ;
V_18 -> V_23 = V_4 ;
V_18 -> V_29 = V_29 ;
V_18 -> V_28 = V_29 + V_5 ;
F_29 ( & V_18 -> V_12 , V_4 -> V_11 ) ;
F_3 ( & V_18 -> V_14 ) ;
V_4 -> V_11 = & V_18 -> V_12 ;
return true ;
}
return false ;
}
static bool F_30 ( struct V_3 * V_4 ,
unsigned V_5 , unsigned V_30 )
{
unsigned V_29 , V_28 , V_31 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_13 ; ++ V_7 ) {
if ( ! F_7 ( & V_4 -> V_14 [ V_7 ] ) ) {
return true ;
}
}
V_29 = F_26 ( V_4 ) ;
V_28 = F_27 ( V_4 ) ;
V_31 = ( V_30 - ( V_29 % V_30 ) ) % V_30 ;
if ( ( V_28 - V_29 ) >= ( V_5 + V_31 ) ) {
return true ;
}
return false ;
}
static bool F_31 ( struct V_3 * V_4 ,
struct V_32 * * V_33 ,
unsigned * V_34 )
{
struct V_17 * V_35 = NULL ;
unsigned V_7 , V_29 , V_36 , V_19 ;
if ( V_4 -> V_11 -> V_26 == & V_4 -> V_12 ) {
V_4 -> V_11 = & V_4 -> V_12 ;
return true ;
}
V_29 = F_26 ( V_4 ) ;
V_36 = V_4 -> V_5 * 2 ;
for ( V_7 = 0 ; V_7 < V_13 ; ++ V_7 ) {
struct V_17 * V_18 ;
if ( F_7 ( & V_4 -> V_14 [ V_7 ] ) ) {
continue;
}
V_18 = F_32 ( & V_4 -> V_14 [ V_7 ] ,
struct V_17 , V_14 ) ;
if ( ! F_25 ( V_18 -> V_25 ) ) {
V_33 [ V_7 ] = V_18 -> V_25 ;
continue;
}
if ( V_34 [ V_7 ] > 2 ) {
continue;
}
V_19 = V_18 -> V_29 ;
if ( V_19 < V_29 ) {
V_19 += V_4 -> V_5 ;
}
V_19 -= V_29 ;
if ( V_19 < V_36 ) {
V_36 = V_19 ;
V_35 = V_18 ;
}
}
if ( V_35 ) {
++ V_34 [ V_35 -> V_25 -> V_37 ] ;
V_4 -> V_11 = V_35 -> V_12 . V_24 ;
F_10 ( V_35 ) ;
return true ;
}
return false ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_17 * * V_18 ,
unsigned V_5 , unsigned V_30 , bool V_38 )
{
struct V_32 * V_33 [ V_13 ] ;
unsigned V_34 [ V_13 ] ;
int V_7 , V_8 ;
F_34 ( V_30 > V_15 ) ;
F_34 ( V_5 > V_4 -> V_5 ) ;
* V_18 = F_35 ( sizeof( struct V_17 ) , V_39 ) ;
if ( ( * V_18 ) == NULL ) {
return - V_40 ;
}
( * V_18 ) -> V_23 = V_4 ;
( * V_18 ) -> V_25 = NULL ;
F_3 ( & ( * V_18 ) -> V_12 ) ;
F_3 ( & ( * V_18 ) -> V_14 ) ;
F_36 ( & V_4 -> V_9 . V_41 ) ;
do {
for ( V_7 = 0 ; V_7 < V_13 ; ++ V_7 ) {
V_33 [ V_7 ] = NULL ;
V_34 [ V_7 ] = 0 ;
}
do {
F_8 ( V_4 ) ;
if ( F_28 ( V_4 , * V_18 ,
V_5 , V_30 ) ) {
F_37 ( & V_4 -> V_9 . V_41 ) ;
return 0 ;
}
} while ( F_31 ( V_4 , V_33 , V_34 ) );
F_37 ( & V_4 -> V_9 . V_41 ) ;
V_8 = F_38 ( V_2 , V_33 , false ) ;
F_36 ( & V_4 -> V_9 . V_41 ) ;
if ( V_8 == - V_42 && V_38 ) {
V_8 = F_39 (
V_4 -> V_9 ,
F_30 ( V_4 , V_5 , V_30 )
) ;
} else if ( V_8 == - V_42 ) {
V_8 = - V_40 ;
}
} while ( ! V_8 );
F_37 ( & V_4 -> V_9 . V_41 ) ;
F_22 ( * V_18 ) ;
* V_18 = NULL ;
return V_8 ;
}
void F_40 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
struct V_32 * V_25 )
{
struct V_3 * V_4 ;
if ( V_18 == NULL || * V_18 == NULL ) {
return;
}
V_4 = ( * V_18 ) -> V_23 ;
F_36 ( & V_4 -> V_9 . V_41 ) ;
if ( V_25 && ! F_25 ( V_25 ) ) {
( * V_18 ) -> V_25 = F_41 ( V_25 ) ;
F_42 ( & ( * V_18 ) -> V_14 ,
& V_4 -> V_14 [ V_25 -> V_37 ] ) ;
} else {
F_10 ( * V_18 ) ;
}
F_43 ( & V_4 -> V_9 ) ;
F_37 ( & V_4 -> V_9 . V_41 ) ;
* V_18 = NULL ;
}
void F_44 ( struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_17 * V_7 ;
F_36 ( & V_4 -> V_9 . V_41 ) ;
F_45 (i, &sa_manager->olist, olist) {
if ( & V_7 -> V_12 == V_4 -> V_11 ) {
F_46 ( V_44 , L_6 ) ;
} else {
F_46 ( V_44 , L_7 ) ;
}
F_46 ( V_44 , L_8 ,
V_7 -> V_29 , V_7 -> V_28 , V_7 -> V_28 - V_7 -> V_29 ) ;
if ( V_7 -> V_25 ) {
F_46 ( V_44 , L_9 ,
V_7 -> V_25 -> V_45 , V_7 -> V_25 -> V_37 ) ;
}
F_46 ( V_44 , L_10 ) ;
}
F_37 ( & V_4 -> V_9 . V_41 ) ;
}
