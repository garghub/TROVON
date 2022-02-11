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
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
F_3 ( & V_4 -> V_15 [ V_8 ] ) ;
}
V_9 = F_4 ( V_2 , V_5 , V_6 , true , V_7 ,
0 , NULL , NULL , & V_4 -> V_11 ) ;
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
V_9 = F_13 ( V_4 -> V_11 , false ) ;
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
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
if ( ! F_7 ( & V_4 -> V_15 [ V_8 ] ) ) {
return true ;
}
}
V_29 = F_26 ( V_4 ) ;
V_28 = F_27 ( V_4 ) ;
V_30 = ( V_6 - ( V_29 % V_6 ) ) % V_6 ;
if ( ( V_28 - V_29 ) >= ( V_5 + V_30 ) ) {
return true ;
}
return false ;
}
static bool F_31 ( struct V_3 * V_4 ,
struct V_25 * * V_31 ,
unsigned * V_32 )
{
struct V_17 * V_33 = NULL ;
unsigned V_8 , V_29 , V_34 , V_19 ;
if ( V_4 -> V_12 -> V_26 == & V_4 -> V_13 ) {
V_4 -> V_12 = & V_4 -> V_13 ;
return true ;
}
V_29 = F_26 ( V_4 ) ;
V_34 = V_4 -> V_5 * 2 ;
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
struct V_17 * V_18 ;
if ( F_7 ( & V_4 -> V_15 [ V_8 ] ) ) {
continue;
}
V_18 = F_32 ( & V_4 -> V_15 [ V_8 ] ,
struct V_17 , V_15 ) ;
if ( ! F_25 ( V_18 -> V_25 ) ) {
V_31 [ V_8 ] = V_18 -> V_25 ;
continue;
}
if ( V_32 [ V_8 ] > 2 ) {
continue;
}
V_19 = V_18 -> V_29 ;
if ( V_19 < V_29 ) {
V_19 += V_4 -> V_5 ;
}
V_19 -= V_29 ;
if ( V_19 < V_34 ) {
V_34 = V_19 ;
V_33 = V_18 ;
}
}
if ( V_33 ) {
T_2 V_35 = F_33 ( V_33 -> V_25 ) -> V_35 ;
++ V_32 [ V_35 ] ;
V_4 -> V_12 = V_33 -> V_13 . V_24 ;
F_10 ( V_33 ) ;
return true ;
}
return false ;
}
int F_34 ( struct V_3 * V_4 ,
struct V_17 * * V_18 ,
unsigned V_5 , unsigned V_6 )
{
struct V_25 * V_31 [ V_14 ] ;
unsigned V_32 [ V_14 ] ;
unsigned V_36 ;
int V_8 , V_9 ;
signed long V_37 ;
F_35 ( V_6 > V_4 -> V_6 ) ;
F_35 ( V_5 > V_4 -> V_5 ) ;
* V_18 = F_36 ( sizeof( struct V_17 ) , V_38 ) ;
if ( ( * V_18 ) == NULL ) {
return - V_39 ;
}
( * V_18 ) -> V_23 = V_4 ;
( * V_18 ) -> V_25 = NULL ;
F_3 ( & ( * V_18 ) -> V_13 ) ;
F_3 ( & ( * V_18 ) -> V_15 ) ;
F_37 ( & V_4 -> V_10 . V_40 ) ;
do {
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
V_31 [ V_8 ] = NULL ;
V_32 [ V_8 ] = 0 ;
}
do {
F_8 ( V_4 ) ;
if ( F_28 ( V_4 , * V_18 ,
V_5 , V_6 ) ) {
F_38 ( & V_4 -> V_10 . V_40 ) ;
return 0 ;
}
} while ( F_31 ( V_4 , V_31 , V_32 ) );
for ( V_8 = 0 , V_36 = 0 ; V_8 < V_14 ; ++ V_8 )
if ( V_31 [ V_8 ] )
V_31 [ V_36 ++ ] = F_39 ( V_31 [ V_8 ] ) ;
if ( V_36 ) {
F_38 ( & V_4 -> V_10 . V_40 ) ;
V_37 = F_40 ( V_31 , V_36 , false ,
V_41 ) ;
for ( V_8 = 0 ; V_8 < V_36 ; ++ V_8 )
F_21 ( V_31 [ V_8 ] ) ;
V_9 = ( V_37 > 0 ) ? 0 : V_37 ;
F_37 ( & V_4 -> V_10 . V_40 ) ;
} else {
V_9 = F_41 (
V_4 -> V_10 ,
F_30 ( V_4 , V_5 , V_6 )
) ;
}
} while ( ! V_9 );
F_38 ( & V_4 -> V_10 . V_40 ) ;
F_22 ( * V_18 ) ;
* V_18 = NULL ;
return V_9 ;
}
void F_42 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
struct V_25 * V_25 )
{
struct V_3 * V_4 ;
if ( V_18 == NULL || * V_18 == NULL ) {
return;
}
V_4 = ( * V_18 ) -> V_23 ;
F_37 ( & V_4 -> V_10 . V_40 ) ;
if ( V_25 && ! F_25 ( V_25 ) ) {
T_2 V_35 ;
( * V_18 ) -> V_25 = F_39 ( V_25 ) ;
V_35 = F_33 ( V_25 ) -> V_35 ;
F_43 ( & ( * V_18 ) -> V_15 , & V_4 -> V_15 [ V_35 ] ) ;
} else {
F_10 ( * V_18 ) ;
}
F_44 ( & V_4 -> V_10 ) ;
F_38 ( & V_4 -> V_10 . V_40 ) ;
* V_18 = NULL ;
}
static void F_45 ( struct V_25 * V_25 , struct V_42 * V_43 )
{
struct V_44 * V_45 = F_46 ( V_25 ) ;
struct V_46 * V_47 = F_47 ( V_25 ) ;
if ( V_45 )
F_48 ( V_43 , L_6 ,
V_45 -> V_48 , V_45 -> V_49 -> V_35 ) ;
if ( V_47 ) {
struct V_50 * V_49 ;
V_49 = F_49 ( V_47 -> V_51 , struct V_50 , V_51 ) ;
F_48 ( V_43 , L_7 ,
V_47 -> V_52 . V_53 , V_49 -> V_35 ) ;
}
}
void F_50 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_17 * V_8 ;
F_37 ( & V_4 -> V_10 . V_40 ) ;
F_51 (i, &sa_manager->olist, olist) {
T_3 V_29 = V_8 -> V_29 + V_4 -> V_21 ;
T_3 V_28 = V_8 -> V_28 + V_4 -> V_21 ;
if ( & V_8 -> V_13 == V_4 -> V_12 ) {
F_48 ( V_43 , L_8 ) ;
} else {
F_48 ( V_43 , L_9 ) ;
}
F_48 ( V_43 , L_10 ,
V_29 , V_28 , V_28 - V_29 ) ;
if ( V_8 -> V_25 )
F_45 ( V_8 -> V_25 , V_43 ) ;
F_48 ( V_43 , L_11 ) ;
}
F_38 ( & V_4 -> V_10 . V_40 ) ;
}
