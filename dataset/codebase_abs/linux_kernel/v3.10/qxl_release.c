T_1
F_1 ( struct V_1 * V_2 , int type ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
int V_6 ;
T_2 V_7 = sizeof( * V_5 ) ;
int V_8 ;
V_5 = F_2 ( V_7 , V_9 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return 0 ;
}
V_5 -> type = type ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
V_5 -> V_12 = 0 ;
F_4 ( V_9 ) ;
F_5 ( & V_2 -> V_13 ) ;
V_8 = F_6 ( & V_2 -> V_14 , V_5 , 1 , 0 , V_15 ) ;
F_7 ( & V_2 -> V_13 ) ;
F_8 () ;
V_6 = V_8 ;
if ( V_8 < 0 )
goto V_16;
* V_4 = V_5 ;
F_9 ( V_2 , L_2 , V_6 ) ;
V_5 -> V_17 = V_6 ;
V_16:
return V_6 ;
}
void
F_10 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
int V_18 ;
F_9 ( V_2 , L_3 , V_5 -> V_17 ,
V_5 -> type , V_5 -> V_10 ) ;
if ( V_5 -> V_12 )
F_11 ( V_2 , V_5 -> V_12 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_10 ; ++ V_18 ) {
F_9 ( V_2 , L_4 ,
V_5 -> V_19 [ V_18 ] -> V_20 . V_21
- V_22 ) ;
F_12 ( & V_5 -> V_19 [ V_18 ] -> V_23 , V_5 -> V_17 ) ;
F_13 ( & V_5 -> V_19 [ V_18 ] ) ;
}
F_5 ( & V_2 -> V_13 ) ;
F_14 ( & V_2 -> V_14 , V_5 -> V_17 ) ;
F_7 ( & V_2 -> V_13 ) ;
F_15 ( V_5 ) ;
}
void
F_16 ( struct V_1 * V_2 , struct V_3 * V_5 ,
struct V_24 * V_25 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_10 ; V_18 ++ )
if ( V_5 -> V_19 [ V_18 ] == V_25 )
return;
if ( V_5 -> V_10 >= V_26 ) {
F_3 ( L_5 ) ;
return;
}
V_5 -> V_19 [ V_5 -> V_10 ++ ] = F_17 ( V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_24 * * V_25 )
{
int V_4 ;
V_4 = F_19 ( V_2 , V_27 , false , V_28 , NULL ,
V_25 ) ;
return V_4 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_5 , bool V_29 )
{
int V_4 ;
if ( F_21 ( & V_5 -> V_19 [ 0 ] -> V_30 ) == 1 ) {
V_4 = F_22 ( V_5 -> V_19 [ 0 ] , V_29 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
if ( F_24 ( & V_5 -> V_19 [ 0 ] -> V_30 ) )
F_25 ( V_5 -> V_19 [ 0 ] ) ;
}
int F_26 ( struct V_1 * V_2 ,
enum V_31 V_32 ,
struct V_3 * V_33 ,
struct V_3 * * V_5 )
{
int V_4 ;
if ( V_32 == V_34 && V_33 ) {
int V_8 ;
struct V_24 * V_25 ;
union V_35 * V_36 ;
V_8 = F_1 ( V_2 , V_37 , V_5 ) ;
V_25 = F_17 ( V_33 -> V_19 [ 0 ] ) ;
( * V_5 ) -> V_11 = V_33 -> V_11 + 64 ;
F_16 ( V_2 , * V_5 , V_25 ) ;
V_4 = F_20 ( V_2 , * V_5 , false ) ;
if ( V_4 ) {
F_3 ( L_6 ) ;
goto V_38;
}
V_36 = F_27 ( V_2 , * V_5 ) ;
V_36 -> V_17 = V_8 ;
F_28 ( V_2 , * V_5 , V_36 ) ;
V_38:
F_13 ( & V_25 ) ;
return V_4 ;
}
return F_29 ( V_2 , sizeof( struct V_39 ) ,
V_37 , V_5 , NULL ) ;
}
int F_29 ( struct V_1 * V_2 , unsigned long V_7 ,
int type , struct V_3 * * V_5 ,
struct V_24 * * V_40 )
{
struct V_24 * V_25 ;
int V_8 ;
int V_4 ;
union V_35 * V_36 ;
int V_41 ;
if ( type == V_42 )
V_41 = 0 ;
else if ( type == V_37 )
V_41 = 1 ;
else if ( type == V_43 )
V_41 = 2 ;
else {
F_3 ( L_7 , type ) ;
return - V_44 ;
}
V_8 = F_1 ( V_2 , type , V_5 ) ;
F_30 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_46 [ V_41 ] + 1 >= V_47 [ V_41 ] ) {
F_13 ( & V_2 -> V_48 [ V_41 ] ) ;
V_2 -> V_46 [ V_41 ] = 0 ;
V_2 -> V_48 [ V_41 ] = NULL ;
}
if ( ! V_2 -> V_48 [ V_41 ] ) {
V_4 = F_18 ( V_2 , & V_2 -> V_48 [ V_41 ] ) ;
if ( V_4 ) {
F_31 ( & V_2 -> V_45 ) ;
return V_4 ;
}
V_4 = F_22 ( V_2 -> V_48 [ V_41 ] , false ) ;
F_32 ( V_2 -> V_48 [ V_41 ] , V_28 , NULL ) ;
F_25 ( V_2 -> V_48 [ V_41 ] ) ;
}
V_25 = F_17 ( V_2 -> V_48 [ V_41 ] ) ;
( * V_5 ) -> V_11 = V_2 -> V_46 [ V_41 ] * V_49 [ V_41 ] ;
V_2 -> V_46 [ V_41 ] ++ ;
if ( V_40 )
* V_40 = V_25 ;
F_16 ( V_2 , * V_5 , V_25 ) ;
V_4 = F_20 ( V_2 , * V_5 , false ) ;
F_31 ( & V_2 -> V_45 ) ;
if ( V_4 )
goto V_38;
V_36 = F_27 ( V_2 , * V_5 ) ;
V_36 -> V_17 = V_8 ;
F_28 ( V_2 , * V_5 , V_36 ) ;
V_38:
F_13 ( & V_25 ) ;
return V_4 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
int V_18 , V_4 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_10 ; V_18 ++ ) {
if ( ! V_5 -> V_19 [ V_18 ] -> V_20 . V_50 )
V_5 -> V_19 [ V_18 ] -> V_20 . V_50 = & V_5 -> V_19 [ V_18 ] -> V_23 ;
V_4 = F_34 ( & V_5 -> V_19 [ V_18 ] -> V_23 , V_5 -> V_17 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
struct V_3 * F_35 ( struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_3 * V_5 ;
F_5 ( & V_2 -> V_13 ) ;
V_5 = F_36 ( & V_2 -> V_14 , V_17 ) ;
F_7 ( & V_2 -> V_13 ) ;
if ( ! V_5 ) {
F_3 ( L_8 ) ;
return NULL ;
}
if ( V_5 -> V_10 < 1 ) {
F_3 ( L_9 ) ;
return NULL ;
}
return V_5 ;
}
union V_35 * F_27 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
void * V_51 ;
union V_35 * V_36 ;
struct V_24 * V_25 = V_5 -> V_19 [ 0 ] ;
V_51 = F_37 ( V_2 , V_25 , V_5 -> V_11 & V_27 ) ;
V_36 = V_51 + ( V_5 -> V_11 & ~ V_27 ) ;
return V_36 ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_5 ,
union V_35 * V_36 )
{
struct V_24 * V_25 = V_5 -> V_19 [ 0 ] ;
void * V_51 ;
V_51 = ( ( void * ) V_36 ) - ( V_5 -> V_11 & ~ V_27 ) ;
F_38 ( V_2 , V_25 , V_51 ) ;
}
