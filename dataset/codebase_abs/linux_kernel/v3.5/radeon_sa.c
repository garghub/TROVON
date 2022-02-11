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
V_16 , NULL , & V_4 -> V_10 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_17 , L_1 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 , * V_20 ;
if ( ! F_7 ( & V_4 -> V_12 ) ) {
V_4 -> V_11 = & V_4 -> V_12 ,
F_8 ( V_4 ) ;
if ( ! F_7 ( & V_4 -> V_12 ) ) {
F_5 ( V_2 -> V_17 , L_2 ) ;
}
}
F_9 (sa_bo, tmp, &sa_manager->olist, olist) {
F_10 ( V_19 ) ;
}
F_11 ( & V_4 -> V_10 ) ;
V_4 -> V_5 = 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
if ( V_4 -> V_10 == NULL ) {
F_5 ( V_2 -> V_17 , L_3 ) ;
return - V_21 ;
}
V_8 = F_13 ( V_4 -> V_10 , false ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_17 , L_4 , V_8 ) ;
return V_8 ;
}
V_8 = F_14 ( V_4 -> V_10 , V_4 -> V_6 , & V_4 -> V_22 ) ;
if ( V_8 ) {
F_15 ( V_4 -> V_10 ) ;
F_5 ( V_2 -> V_17 , L_5 , V_8 ) ;
return V_8 ;
}
V_8 = F_16 ( V_4 -> V_10 , & V_4 -> V_23 ) ;
F_15 ( V_4 -> V_10 ) ;
return V_8 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
if ( V_4 -> V_10 == NULL ) {
F_5 ( V_2 -> V_17 , L_3 ) ;
return - V_21 ;
}
V_8 = F_13 ( V_4 -> V_10 , false ) ;
if ( ! V_8 ) {
F_18 ( V_4 -> V_10 ) ;
F_19 ( V_4 -> V_10 ) ;
F_15 ( V_4 -> V_10 ) ;
}
return V_8 ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_24 ;
if ( V_4 -> V_11 == & V_19 -> V_12 ) {
V_4 -> V_11 = V_19 -> V_12 . V_25 ;
}
F_20 ( & V_19 -> V_12 ) ;
F_20 ( & V_19 -> V_14 ) ;
F_21 ( & V_19 -> V_26 ) ;
F_22 ( V_19 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_18 * V_19 , * V_20 ;
if ( V_4 -> V_11 -> V_27 == & V_4 -> V_12 )
return;
V_19 = F_23 ( V_4 -> V_11 -> V_27 , struct V_18 , V_12 ) ;
F_24 (sa_bo, tmp, &sa_manager->olist, olist) {
if ( V_19 -> V_26 == NULL || ! F_25 ( V_19 -> V_26 ) ) {
return;
}
F_10 ( V_19 ) ;
}
}
static inline unsigned F_26 ( struct V_3 * V_4 )
{
struct V_28 * V_11 = V_4 -> V_11 ;
if ( V_11 != & V_4 -> V_12 ) {
return F_23 ( V_11 , struct V_18 , V_12 ) -> V_29 ;
}
return 0 ;
}
static inline unsigned F_27 ( struct V_3 * V_4 )
{
struct V_28 * V_11 = V_4 -> V_11 ;
if ( V_11 -> V_27 != & V_4 -> V_12 ) {
return F_23 ( V_11 -> V_27 , struct V_18 , V_12 ) -> V_30 ;
}
return V_4 -> V_5 ;
}
static bool F_28 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
unsigned V_5 , unsigned V_31 )
{
unsigned V_30 , V_29 , V_32 ;
V_30 = F_26 ( V_4 ) ;
V_29 = F_27 ( V_4 ) ;
V_32 = ( V_31 - ( V_30 % V_31 ) ) % V_31 ;
if ( ( V_29 - V_30 ) >= ( V_5 + V_32 ) ) {
V_30 += V_32 ;
V_19 -> V_24 = V_4 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_29 = V_30 + V_5 ;
F_29 ( & V_19 -> V_12 , V_4 -> V_11 ) ;
F_3 ( & V_19 -> V_14 ) ;
V_4 -> V_11 = & V_19 -> V_12 ;
return true ;
}
return false ;
}
static bool F_30 ( struct V_3 * V_4 ,
struct V_33 * * V_34 ,
unsigned * V_35 )
{
struct V_18 * V_36 = NULL ;
unsigned V_7 , V_30 , V_37 , V_20 ;
if ( V_4 -> V_11 -> V_27 == & V_4 -> V_12 ) {
V_4 -> V_11 = & V_4 -> V_12 ;
return true ;
}
V_30 = F_26 ( V_4 ) ;
V_37 = V_4 -> V_5 * 2 ;
for ( V_7 = 0 ; V_7 < V_13 ; ++ V_7 ) {
struct V_18 * V_19 ;
if ( F_7 ( & V_4 -> V_14 [ V_7 ] ) ) {
continue;
}
V_19 = F_31 ( & V_4 -> V_14 [ V_7 ] ,
struct V_18 , V_14 ) ;
if ( ! F_25 ( V_19 -> V_26 ) ) {
V_34 [ V_7 ] = V_19 -> V_26 ;
continue;
}
if ( V_35 [ V_7 ] > 2 ) {
continue;
}
V_20 = V_19 -> V_30 ;
if ( V_20 < V_30 ) {
V_20 += V_4 -> V_5 ;
}
V_20 -= V_30 ;
if ( V_20 < V_37 ) {
V_37 = V_20 ;
V_36 = V_19 ;
}
}
if ( V_36 ) {
++ V_35 [ V_36 -> V_26 -> V_38 ] ;
V_4 -> V_11 = V_36 -> V_12 . V_25 ;
F_10 ( V_36 ) ;
return true ;
}
return false ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * * V_19 ,
unsigned V_5 , unsigned V_31 , bool V_39 )
{
struct V_33 * V_34 [ V_13 ] ;
unsigned V_35 [ V_13 ] ;
int V_7 , V_8 = - V_40 ;
F_33 ( V_31 > V_15 ) ;
F_33 ( V_5 > V_4 -> V_5 ) ;
* V_19 = F_34 ( sizeof( struct V_18 ) , V_41 ) ;
if ( ( * V_19 ) == NULL ) {
return - V_40 ;
}
( * V_19 ) -> V_24 = V_4 ;
( * V_19 ) -> V_26 = NULL ;
F_3 ( & ( * V_19 ) -> V_12 ) ;
F_3 ( & ( * V_19 ) -> V_14 ) ;
F_35 ( & V_4 -> V_9 ) ;
do {
for ( V_7 = 0 ; V_7 < V_13 ; ++ V_7 ) {
V_34 [ V_7 ] = NULL ;
V_35 [ V_7 ] = 0 ;
}
do {
F_8 ( V_4 ) ;
if ( F_28 ( V_4 , * V_19 ,
V_5 , V_31 ) ) {
F_36 ( & V_4 -> V_9 ) ;
return 0 ;
}
} while ( F_30 ( V_4 , V_34 , V_35 ) );
if ( V_39 ) {
F_36 ( & V_4 -> V_9 ) ;
V_8 = F_37 ( V_2 , V_34 , false ) ;
F_35 ( & V_4 -> V_9 ) ;
if ( V_8 ) {
if ( V_8 == - V_42 ) {
V_8 = - V_40 ;
}
goto V_43;
}
}
} while ( V_39 );
V_43:
F_36 ( & V_4 -> V_9 ) ;
F_22 ( * V_19 ) ;
* V_19 = NULL ;
return V_8 ;
}
void F_38 ( struct V_1 * V_2 , struct V_18 * * V_19 ,
struct V_33 * V_26 )
{
struct V_3 * V_4 ;
if ( V_19 == NULL || * V_19 == NULL ) {
return;
}
V_4 = ( * V_19 ) -> V_24 ;
F_35 ( & V_4 -> V_9 ) ;
if ( V_26 && V_26 -> V_44 && V_26 -> V_44 < V_45 ) {
( * V_19 ) -> V_26 = F_39 ( V_26 ) ;
F_40 ( & ( * V_19 ) -> V_14 ,
& V_4 -> V_14 [ V_26 -> V_38 ] ) ;
} else {
F_10 ( * V_19 ) ;
}
F_36 ( & V_4 -> V_9 ) ;
* V_19 = NULL ;
}
void F_41 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_18 * V_7 ;
F_35 ( & V_4 -> V_9 ) ;
F_42 (i, &sa_manager->olist, olist) {
if ( & V_7 -> V_12 == V_4 -> V_11 ) {
F_43 ( V_47 , L_6 ) ;
} else {
F_43 ( V_47 , L_7 ) ;
}
F_43 ( V_47 , L_8 ,
V_7 -> V_30 , V_7 -> V_29 , V_7 -> V_29 - V_7 -> V_30 ) ;
if ( V_7 -> V_26 ) {
F_43 ( V_47 , L_9 ,
V_7 -> V_26 -> V_44 , V_7 -> V_26 -> V_38 ) ;
}
F_43 ( V_47 , L_10 ) ;
}
F_36 ( & V_4 -> V_9 ) ;
}
