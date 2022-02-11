static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = & V_7 -> V_10 ;
V_9 -> V_11 = F_3 ( F_4 ( V_4 ) ) ;
V_9 -> V_12 = F_5 ( F_6 ( & V_9 -> V_13 ,
V_5 - sizeof( V_14 ) ,
V_15 ) ) ;
F_7 ( F_8 ( V_2 , V_4 , 4096 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = & V_7 -> V_10 ;
T_1 V_16 ;
V_14 V_17 ;
T_2 V_13 ;
if ( F_4 ( V_4 ) != F_9 ( V_9 -> V_11 ) ) {
F_10 ( L_1 ,
F_9 ( V_9 -> V_11 ) , F_4 ( V_4 ) ) ;
return - V_18 ;
}
V_17 = F_5 ( F_6 ( & V_9 -> V_13 ,
V_5 - sizeof( V_14 ) ,
V_15 ) ) ;
if ( V_17 != V_9 -> V_12 ) {
F_10 ( L_2 ,
F_11 ( V_17 ) , F_11 ( V_9 -> V_12 ) ) ;
return - V_19 ;
}
V_16 = F_11 ( V_9 -> V_16 ) ;
if ( sizeof( struct V_8 ) +
( sizeof( V_20 ) + V_16 ) * F_11 ( V_9 -> V_21 ) > V_5 ) {
F_10 ( L_3 ) ;
return - V_19 ;
}
if ( F_11 ( V_9 -> V_22 ) > F_11 ( V_9 -> V_21 ) ) {
F_10 ( L_4 ) ;
return - V_19 ;
}
V_13 = F_11 ( V_9 -> V_13 ) ;
if ( ! ( V_13 & V_23 ) && ! ( V_13 & V_24 ) ) {
F_10 ( L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_25 * V_26 , T_3 V_4 ,
struct V_3 * * V_27 )
{
return F_13 ( V_26 -> V_28 , V_4 , & V_29 , V_27 ) ;
}
static int F_14 ( struct V_25 * V_26 , T_3 V_30 ,
struct V_31 * V_32 ,
struct V_3 * * V_27 )
{
int V_33 , V_34 ;
V_33 = F_15 ( V_26 -> V_28 , V_30 , & V_29 ,
V_27 , & V_34 ) ;
if ( ! V_33 && V_34 )
F_16 ( V_26 -> V_28 , F_2 ( * V_27 ) , V_32 ) ;
return V_33 ;
}
int F_17 ( struct V_25 * V_26 , struct V_3 * * V_27 )
{
return F_18 ( V_26 -> V_28 , & V_29 , V_27 ) ;
}
int F_19 ( struct V_25 * V_26 , struct V_3 * V_4 )
{
return F_20 ( V_26 -> V_28 , V_4 ) ;
}
void F_21 ( struct V_35 * V_36 , struct V_25 * V_26 )
{
V_36 -> V_26 = V_26 ;
V_36 -> V_37 = 0 ;
V_36 -> V_38 [ 0 ] = NULL ;
V_36 -> V_38 [ 1 ] = NULL ;
}
int F_22 ( struct V_35 * V_36 )
{
int V_33 = 0 , V_39 ;
for ( V_39 = 0 ; V_39 < V_36 -> V_37 ; V_39 ++ ) {
int V_40 = F_19 ( V_36 -> V_26 , V_36 -> V_38 [ V_39 ] ) ;
if ( V_40 < 0 )
V_33 = V_40 ;
}
return V_33 ;
}
int F_23 ( struct V_35 * V_36 , T_3 V_41 )
{
int V_33 ;
if ( V_36 -> V_37 == 2 ) {
V_33 = F_19 ( V_36 -> V_26 , V_36 -> V_38 [ 0 ] ) ;
if ( V_33 < 0 )
return V_33 ;
V_36 -> V_38 [ 0 ] = V_36 -> V_38 [ 1 ] ;
V_36 -> V_37 -- ;
}
V_33 = F_12 ( V_36 -> V_26 , V_41 , V_36 -> V_38 + V_36 -> V_37 ) ;
if ( ! V_33 )
V_36 -> V_37 ++ ;
return V_33 ;
}
struct V_6 * F_24 ( struct V_35 * V_36 )
{
struct V_3 * V_42 ;
F_7 ( ! V_36 -> V_37 ) ;
V_42 = V_36 -> V_38 [ V_36 -> V_37 - 1 ] ;
return F_2 ( V_42 ) ;
}
void F_25 ( struct V_43 * V_36 , struct V_25 * V_26 )
{
V_36 -> V_26 = V_26 ;
V_36 -> V_37 = 0 ;
}
int F_26 ( struct V_43 * V_36 )
{
int V_33 = 0 , V_39 ;
for ( V_39 = 0 ; V_39 < V_36 -> V_37 ; V_39 ++ ) {
int V_40 = F_19 ( V_36 -> V_26 , V_36 -> V_38 [ V_39 ] ) ;
if ( V_40 < 0 )
V_33 = V_40 ;
}
return V_33 ;
}
int F_27 ( struct V_43 * V_36 , T_3 V_4 ,
struct V_31 * V_32 )
{
int V_33 ;
if ( V_36 -> V_37 == 2 ) {
V_33 = F_19 ( V_36 -> V_26 , V_36 -> V_38 [ 0 ] ) ;
if ( V_33 < 0 )
return V_33 ;
V_36 -> V_38 [ 0 ] = V_36 -> V_38 [ 1 ] ;
V_36 -> V_37 -- ;
}
V_33 = F_14 ( V_36 -> V_26 , V_4 , V_32 , V_36 -> V_38 + V_36 -> V_37 ) ;
if ( ! V_33 ) {
if ( ! V_36 -> V_37 )
V_36 -> V_44 = F_4 ( V_36 -> V_38 [ 0 ] ) ;
V_36 -> V_37 ++ ;
}
return V_33 ;
}
struct V_3 * F_28 ( struct V_43 * V_36 )
{
F_7 ( ! V_36 -> V_37 ) ;
return V_36 -> V_38 [ V_36 -> V_37 - 1 ] ;
}
struct V_3 * F_29 ( struct V_43 * V_36 )
{
F_7 ( V_36 -> V_37 != 2 ) ;
return V_36 -> V_37 == 2 ? V_36 -> V_38 [ 0 ] : NULL ;
}
int F_30 ( struct V_43 * V_36 )
{
return V_36 -> V_37 >= 2 ;
}
int F_31 ( struct V_43 * V_36 )
{
return V_36 -> V_44 ;
}
