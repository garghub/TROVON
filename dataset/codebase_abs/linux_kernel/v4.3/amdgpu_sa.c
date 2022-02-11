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
static T_2 F_20 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_28 = F_21 ( V_24 ) ;
if ( V_28 ) {
struct V_29 * V_30 ;
V_30 = F_22 ( V_28 -> V_31 , struct V_29 , V_31 ) ;
return V_30 -> V_32 ;
}
V_26 = F_23 ( V_24 ) ;
if ( V_26 )
return V_26 -> V_30 -> V_32 ;
return 0 ;
}
static void F_10 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_33 ;
if ( V_4 -> V_12 == & V_18 -> V_13 ) {
V_4 -> V_12 = V_18 -> V_13 . V_34 ;
}
F_24 ( & V_18 -> V_13 ) ;
F_24 ( & V_18 -> V_15 ) ;
F_25 ( V_18 -> V_23 ) ;
F_26 ( V_18 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_17 * V_18 , * V_19 ;
if ( V_4 -> V_12 -> V_35 == & V_4 -> V_13 )
return;
V_18 = F_27 ( V_4 -> V_12 -> V_35 , struct V_17 , V_13 ) ;
F_28 (sa_bo, tmp, &sa_manager->olist, olist) {
if ( V_18 -> V_23 == NULL ||
! F_29 ( V_18 -> V_23 ) ) {
return;
}
F_10 ( V_18 ) ;
}
}
static inline unsigned F_30 ( struct V_3 * V_4 )
{
struct V_36 * V_12 = V_4 -> V_12 ;
if ( V_12 != & V_4 -> V_13 ) {
return F_27 ( V_12 , struct V_17 , V_13 ) -> V_37 ;
}
return 0 ;
}
static inline unsigned F_31 ( struct V_3 * V_4 )
{
struct V_36 * V_12 = V_4 -> V_12 ;
if ( V_12 -> V_35 != & V_4 -> V_13 ) {
return F_27 ( V_12 -> V_35 , struct V_17 , V_13 ) -> V_38 ;
}
return V_4 -> V_5 ;
}
static bool F_32 ( struct V_3 * V_4 ,
struct V_17 * V_18 ,
unsigned V_5 , unsigned V_6 )
{
unsigned V_38 , V_37 , V_39 ;
V_38 = F_30 ( V_4 ) ;
V_37 = F_31 ( V_4 ) ;
V_39 = ( V_6 - ( V_38 % V_6 ) ) % V_6 ;
if ( ( V_37 - V_38 ) >= ( V_5 + V_39 ) ) {
V_38 += V_39 ;
V_18 -> V_33 = V_4 ;
V_18 -> V_38 = V_38 ;
V_18 -> V_37 = V_38 + V_5 ;
F_33 ( & V_18 -> V_13 , V_4 -> V_12 ) ;
F_3 ( & V_18 -> V_15 ) ;
V_4 -> V_12 = & V_18 -> V_13 ;
return true ;
}
return false ;
}
static bool F_34 ( struct V_3 * V_4 ,
unsigned V_5 , unsigned V_6 )
{
unsigned V_38 , V_37 , V_39 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
if ( ! F_7 ( & V_4 -> V_15 [ V_8 ] ) ) {
return true ;
}
}
V_38 = F_30 ( V_4 ) ;
V_37 = F_31 ( V_4 ) ;
V_39 = ( V_6 - ( V_38 % V_6 ) ) % V_6 ;
if ( ( V_37 - V_38 ) >= ( V_5 + V_39 ) ) {
return true ;
}
return false ;
}
static bool F_35 ( struct V_3 * V_4 ,
struct V_23 * * V_40 ,
unsigned * V_41 )
{
struct V_17 * V_42 = NULL ;
unsigned V_8 , V_38 , V_43 , V_19 ;
if ( V_4 -> V_12 -> V_35 == & V_4 -> V_13 ) {
V_4 -> V_12 = & V_4 -> V_13 ;
return true ;
}
V_38 = F_30 ( V_4 ) ;
V_43 = V_4 -> V_5 * 2 ;
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
struct V_17 * V_18 ;
if ( F_7 ( & V_4 -> V_15 [ V_8 ] ) ) {
continue;
}
V_18 = F_36 ( & V_4 -> V_15 [ V_8 ] ,
struct V_17 , V_15 ) ;
if ( ! F_29 ( V_18 -> V_23 ) ) {
V_40 [ V_8 ] = V_18 -> V_23 ;
continue;
}
if ( V_41 [ V_8 ] > 2 ) {
continue;
}
V_19 = V_18 -> V_38 ;
if ( V_19 < V_38 ) {
V_19 += V_4 -> V_5 ;
}
V_19 -= V_38 ;
if ( V_19 < V_43 ) {
V_43 = V_19 ;
V_42 = V_18 ;
}
}
if ( V_42 ) {
T_2 V_32 = F_20 ( V_42 -> V_23 ) ;
++ V_41 [ V_32 ] ;
V_4 -> V_12 = V_42 -> V_13 . V_34 ;
F_10 ( V_42 ) ;
return true ;
}
return false ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_17 * * V_18 ,
unsigned V_5 , unsigned V_6 )
{
struct V_23 * V_40 [ V_14 ] ;
unsigned V_41 [ V_14 ] ;
int V_8 , V_9 ;
signed long V_44 ;
F_38 ( V_6 > V_4 -> V_6 ) ;
F_38 ( V_5 > V_4 -> V_5 ) ;
* V_18 = F_39 ( sizeof( struct V_17 ) , V_45 ) ;
if ( ( * V_18 ) == NULL ) {
return - V_46 ;
}
( * V_18 ) -> V_33 = V_4 ;
( * V_18 ) -> V_23 = NULL ;
F_3 ( & ( * V_18 ) -> V_13 ) ;
F_3 ( & ( * V_18 ) -> V_15 ) ;
F_40 ( & V_4 -> V_10 . V_47 ) ;
do {
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 ) {
V_40 [ V_8 ] = NULL ;
V_41 [ V_8 ] = 0 ;
}
do {
F_8 ( V_4 ) ;
if ( F_32 ( V_4 , * V_18 ,
V_5 , V_6 ) ) {
F_41 ( & V_4 -> V_10 . V_47 ) ;
return 0 ;
}
} while ( F_35 ( V_4 , V_40 , V_41 ) );
F_41 ( & V_4 -> V_10 . V_47 ) ;
V_44 = F_42 ( V_2 , V_40 , V_14 ,
false , V_48 ) ;
V_9 = ( V_44 > 0 ) ? 0 : V_44 ;
F_40 ( & V_4 -> V_10 . V_47 ) ;
if ( V_9 == - V_49 ) {
V_9 = F_43 (
V_4 -> V_10 ,
F_34 ( V_4 , V_5 , V_6 )
) ;
}
} while ( ! V_9 );
F_41 ( & V_4 -> V_10 . V_47 ) ;
F_26 ( * V_18 ) ;
* V_18 = NULL ;
return V_9 ;
}
void F_44 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
struct V_23 * V_23 )
{
struct V_3 * V_4 ;
if ( V_18 == NULL || * V_18 == NULL ) {
return;
}
V_4 = ( * V_18 ) -> V_33 ;
F_40 ( & V_4 -> V_10 . V_47 ) ;
if ( V_23 && ! F_29 ( V_23 ) ) {
T_2 V_32 ;
( * V_18 ) -> V_23 = F_45 ( V_23 ) ;
V_32 = F_20 ( V_23 ) ;
F_46 ( & ( * V_18 ) -> V_15 , & V_4 -> V_15 [ V_32 ] ) ;
} else {
F_10 ( * V_18 ) ;
}
F_47 ( & V_4 -> V_10 ) ;
F_41 ( & V_4 -> V_10 . V_47 ) ;
* V_18 = NULL ;
}
static void F_48 ( struct V_23 * V_23 , struct V_50 * V_51 )
{
struct V_25 * V_26 = F_23 ( V_23 ) ;
struct V_27 * V_28 = F_21 ( V_23 ) ;
if ( V_26 )
F_49 ( V_51 , L_6 ,
V_26 -> V_52 , V_26 -> V_30 -> V_32 ) ;
if ( V_28 ) {
struct V_29 * V_30 ;
V_30 = F_22 ( V_28 -> V_31 , struct V_29 , V_31 ) ;
F_49 ( V_51 , L_7 ,
V_28 -> V_53 . V_54 , V_30 -> V_32 ) ;
}
}
void F_50 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_17 * V_8 ;
F_40 ( & V_4 -> V_10 . V_47 ) ;
F_51 (i, &sa_manager->olist, olist) {
T_3 V_38 = V_8 -> V_38 + V_4 -> V_21 ;
T_3 V_37 = V_8 -> V_37 + V_4 -> V_21 ;
if ( & V_8 -> V_13 == V_4 -> V_12 ) {
F_49 ( V_51 , L_8 ) ;
} else {
F_49 ( V_51 , L_9 ) ;
}
F_49 ( V_51 , L_10 ,
V_38 , V_37 , V_37 - V_38 ) ;
if ( V_8 -> V_23 )
F_48 ( V_8 -> V_23 , V_51 ) ;
F_49 ( V_51 , L_11 ) ;
}
F_41 ( & V_4 -> V_10 . V_47 ) ;
}
