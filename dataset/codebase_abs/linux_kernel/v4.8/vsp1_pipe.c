const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_5 = & V_4 [ V_3 ] ;
if ( V_5 -> V_2 == V_2 )
return V_5 ;
}
return NULL ;
}
void F_3 ( struct V_6 * V_7 )
{
unsigned int V_3 ;
if ( V_7 -> V_8 ) {
struct V_9 * V_8 = F_4 ( & V_7 -> V_8 -> V_10 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 -> V_11 ) ; ++ V_3 )
V_8 -> V_11 [ V_3 ] . V_12 = NULL ;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_11 ) ; ++ V_3 ) {
if ( V_7 -> V_11 [ V_3 ] ) {
V_7 -> V_11 [ V_3 ] -> V_7 = NULL ;
V_7 -> V_11 [ V_3 ] = NULL ;
}
}
if ( V_7 -> V_13 ) {
V_7 -> V_13 -> V_7 = NULL ;
V_7 -> V_13 = NULL ;
}
F_5 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = V_16 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = 0 ;
V_7 -> V_8 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_20 = NULL ;
}
void F_6 ( struct V_6 * V_7 )
{
F_7 ( & V_7 -> V_21 ) ;
F_8 ( & V_7 -> V_22 ) ;
F_9 ( & V_7 -> V_23 ) ;
F_10 ( & V_7 -> V_24 ) ;
F_5 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = V_16 ;
}
void F_11 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = V_7 -> V_13 -> V_27 . V_26 ;
if ( V_7 -> V_15 == V_16 ) {
F_12 ( V_26 , F_13 ( V_7 -> V_13 -> V_27 . V_28 ) ,
V_29 ) ;
V_7 -> V_15 = V_30 ;
}
V_7 -> V_17 = 0 ;
}
bool F_14 ( struct V_6 * V_7 )
{
unsigned long V_31 ;
bool V_32 ;
F_15 ( & V_7 -> V_22 , V_31 ) ;
V_32 = V_7 -> V_15 == V_16 ;
F_16 ( & V_7 -> V_22 , V_31 ) ;
return V_32 ;
}
int F_17 ( struct V_6 * V_7 )
{
struct V_33 * V_27 ;
unsigned long V_31 ;
int V_34 ;
if ( V_7 -> V_19 ) {
V_34 = F_18 ( V_7 -> V_13 -> V_27 . V_26 ,
V_7 -> V_13 -> V_27 . V_28 ) ;
if ( V_34 == 0 ) {
F_15 ( & V_7 -> V_22 , V_31 ) ;
V_7 -> V_15 = V_16 ;
F_16 ( & V_7 -> V_22 , V_31 ) ;
}
} else {
F_15 ( & V_7 -> V_22 , V_31 ) ;
if ( V_7 -> V_15 == V_30 )
V_7 -> V_15 = V_35 ;
F_16 ( & V_7 -> V_22 , V_31 ) ;
V_34 = F_19 ( V_7 -> V_23 , F_14 ( V_7 ) ,
F_20 ( 500 ) ) ;
V_34 = V_34 == 0 ? - V_36 : 0 ;
}
F_21 (entity, &pipe->entities, list_pipe) {
if ( V_27 -> V_37 && V_27 -> V_37 -> V_38 )
F_12 ( V_27 -> V_26 , V_27 -> V_37 -> V_38 ,
V_39 ) ;
}
F_22 ( & V_7 -> V_13 -> V_27 . V_10 , V_40 , V_41 , 0 ) ;
return V_34 ;
}
bool F_23 ( struct V_6 * V_7 )
{
unsigned int V_42 ;
V_42 = ( ( 1 << V_7 -> V_18 ) - 1 ) << 1 ;
if ( ! V_7 -> V_19 )
V_42 |= 1 << 0 ;
return V_7 -> V_17 == V_42 ;
}
void F_24 ( struct V_6 * V_7 )
{
if ( V_7 == NULL )
return;
F_25 ( V_7 -> V_13 -> V_43 ) ;
if ( V_7 -> V_44 )
V_7 -> V_44 ( V_7 ) ;
V_7 -> V_45 ++ ;
}
void F_26 ( struct V_6 * V_7 ,
struct V_46 * V_47 , unsigned int V_48 )
{
if ( ! V_7 -> V_20 )
return;
if ( V_7 -> V_49 -> type == V_50 )
V_48 = 255 ;
F_27 ( V_7 -> V_20 , V_47 , V_48 ) ;
}
void F_28 ( struct V_25 * V_26 )
{
unsigned long V_31 ;
unsigned int V_3 ;
int V_34 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_5 -> V_51 ; ++ V_3 ) {
struct V_52 * V_53 = V_26 -> V_53 [ V_3 ] ;
struct V_6 * V_7 ;
if ( V_53 == NULL )
continue;
V_7 = V_53 -> V_7 ;
if ( V_7 == NULL )
continue;
F_15 ( & V_7 -> V_22 , V_31 ) ;
if ( V_7 -> V_15 == V_30 )
V_7 -> V_15 = V_35 ;
F_16 ( & V_7 -> V_22 , V_31 ) ;
}
for ( V_3 = 0 ; V_3 < V_26 -> V_5 -> V_51 ; ++ V_3 ) {
struct V_52 * V_53 = V_26 -> V_53 [ V_3 ] ;
struct V_6 * V_7 ;
if ( V_53 == NULL )
continue;
V_7 = V_53 -> V_7 ;
if ( V_7 == NULL )
continue;
V_34 = F_19 ( V_7 -> V_23 , F_14 ( V_7 ) ,
F_20 ( 500 ) ) ;
if ( V_34 == 0 )
F_29 ( V_26 -> V_54 , L_1 ,
V_53 -> V_27 . V_28 ) ;
}
}
void F_30 ( struct V_25 * V_26 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_5 -> V_51 ; ++ V_3 ) {
struct V_52 * V_53 = V_26 -> V_53 [ V_3 ] ;
struct V_6 * V_7 ;
if ( V_53 == NULL )
continue;
V_7 = V_53 -> V_7 ;
if ( V_7 == NULL )
continue;
if ( F_23 ( V_7 ) )
F_11 ( V_7 ) ;
}
}
