const struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
unsigned int V_5 ;
if ( V_3 -> V_6 -> V_7 != 2 && V_4 == V_8 )
return NULL ;
for ( V_5 = 0 ; V_5 < F_2 ( V_9 ) ; ++ V_5 ) {
const struct V_1 * V_6 = & V_9 [ V_5 ] ;
if ( V_6 -> V_4 == V_4 )
return V_6 ;
}
return NULL ;
}
void F_3 ( struct V_10 * V_11 )
{
unsigned int V_5 ;
if ( V_11 -> V_12 ) {
struct V_13 * V_12 = F_4 ( & V_11 -> V_12 -> V_14 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_12 -> V_15 ) ; ++ V_5 )
V_12 -> V_15 [ V_5 ] . V_16 = NULL ;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_11 -> V_15 ) ; ++ V_5 ) {
if ( V_11 -> V_15 [ V_5 ] ) {
V_11 -> V_15 [ V_5 ] -> V_11 = NULL ;
V_11 -> V_15 [ V_5 ] = NULL ;
}
}
if ( V_11 -> V_17 ) {
V_11 -> V_17 -> V_11 = NULL ;
V_11 -> V_17 = NULL ;
}
F_5 ( & V_11 -> V_18 ) ;
V_11 -> V_19 = V_20 ;
V_11 -> V_21 = 0 ;
V_11 -> V_22 = 0 ;
V_11 -> V_12 = NULL ;
V_11 -> V_23 = NULL ;
V_11 -> V_24 = NULL ;
}
void F_6 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_25 ) ;
F_8 ( & V_11 -> V_26 ) ;
F_9 ( & V_11 -> V_27 ) ;
F_10 ( & V_11 -> V_28 ) ;
F_5 ( & V_11 -> V_18 ) ;
V_11 -> V_19 = V_20 ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_17 -> V_29 . V_3 ;
if ( V_11 -> V_19 == V_20 ) {
F_12 ( V_3 , F_13 ( V_11 -> V_17 -> V_29 . V_30 ) ,
V_31 ) ;
V_11 -> V_19 = V_32 ;
}
V_11 -> V_21 = 0 ;
}
bool F_14 ( struct V_10 * V_11 )
{
unsigned long V_33 ;
bool V_34 ;
F_15 ( & V_11 -> V_26 , V_33 ) ;
V_34 = V_11 -> V_19 == V_20 ;
F_16 ( & V_11 -> V_26 , V_33 ) ;
return V_34 ;
}
int F_17 ( struct V_10 * V_11 )
{
struct V_35 * V_29 ;
unsigned long V_33 ;
int V_36 ;
if ( V_11 -> V_23 ) {
V_36 = F_18 ( V_11 -> V_17 -> V_29 . V_3 ,
V_11 -> V_17 -> V_29 . V_30 ) ;
if ( V_36 == 0 ) {
F_15 ( & V_11 -> V_26 , V_33 ) ;
V_11 -> V_19 = V_20 ;
F_16 ( & V_11 -> V_26 , V_33 ) ;
}
} else {
F_15 ( & V_11 -> V_26 , V_33 ) ;
if ( V_11 -> V_19 == V_32 )
V_11 -> V_19 = V_37 ;
F_16 ( & V_11 -> V_26 , V_33 ) ;
V_36 = F_19 ( V_11 -> V_27 , F_14 ( V_11 ) ,
F_20 ( 500 ) ) ;
V_36 = V_36 == 0 ? - V_38 : 0 ;
}
F_21 (entity, &pipe->entities, list_pipe) {
if ( V_29 -> V_39 && V_29 -> V_39 -> V_40 )
F_12 ( V_29 -> V_3 , V_29 -> V_39 -> V_40 ,
V_41 ) ;
}
F_22 ( & V_11 -> V_17 -> V_29 . V_14 , V_42 , V_43 , 0 ) ;
return V_36 ;
}
bool F_23 ( struct V_10 * V_11 )
{
unsigned int V_44 ;
V_44 = ( ( 1 << V_11 -> V_22 ) - 1 ) << 1 ;
if ( ! V_11 -> V_23 )
V_44 |= 1 << 0 ;
return V_11 -> V_21 == V_44 ;
}
void F_24 ( struct V_10 * V_11 )
{
if ( V_11 == NULL )
return;
F_25 ( V_11 -> V_17 -> V_45 ) ;
if ( V_11 -> V_46 )
V_11 -> V_46 ( V_11 ) ;
V_11 -> V_47 ++ ;
}
void F_26 ( struct V_10 * V_11 ,
struct V_48 * V_49 , unsigned int V_50 )
{
if ( ! V_11 -> V_24 )
return;
if ( V_11 -> V_51 -> type == V_52 )
V_50 = 255 ;
F_27 ( V_11 -> V_24 , V_49 , V_50 ) ;
}
void F_28 ( struct V_2 * V_3 )
{
unsigned long V_33 ;
unsigned int V_5 ;
int V_36 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_53 ; ++ V_5 ) {
struct V_54 * V_55 = V_3 -> V_55 [ V_5 ] ;
struct V_10 * V_11 ;
if ( V_55 == NULL )
continue;
V_11 = V_55 -> V_11 ;
if ( V_11 == NULL )
continue;
F_15 ( & V_11 -> V_26 , V_33 ) ;
if ( V_11 -> V_19 == V_32 )
V_11 -> V_19 = V_37 ;
F_16 ( & V_11 -> V_26 , V_33 ) ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_53 ; ++ V_5 ) {
struct V_54 * V_55 = V_3 -> V_55 [ V_5 ] ;
struct V_10 * V_11 ;
if ( V_55 == NULL )
continue;
V_11 = V_55 -> V_11 ;
if ( V_11 == NULL )
continue;
V_36 = F_19 ( V_11 -> V_27 , F_14 ( V_11 ) ,
F_20 ( 500 ) ) ;
if ( V_36 == 0 )
F_29 ( V_3 -> V_56 , L_1 ,
V_55 -> V_29 . V_30 ) ;
}
}
void F_30 ( struct V_2 * V_3 )
{
unsigned long V_33 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_53 ; ++ V_5 ) {
struct V_54 * V_55 = V_3 -> V_55 [ V_5 ] ;
struct V_10 * V_11 ;
if ( V_55 == NULL )
continue;
V_11 = V_55 -> V_11 ;
if ( V_11 == NULL )
continue;
F_15 ( & V_11 -> V_26 , V_33 ) ;
if ( F_23 ( V_11 ) )
F_11 ( V_11 ) ;
F_16 ( & V_11 -> V_26 , V_33 ) ;
}
}
