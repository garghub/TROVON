static T_1 F_1 ( struct V_1 * V_2 [] , unsigned V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
unsigned V_6 = F_2 ( V_4 , V_3 * 8 ) ;
while ( V_6 -- ) {
unsigned V_7 = V_3 / 2 ;
T_2 * V_8 = ( T_2 * ) ( * V_2 ++ ) -> V_9 ;
while ( V_7 -- )
V_5 += 16 - F_3 ( * V_8 ++ ) ;
}
return V_5 ;
}
void F_4 ( struct V_10 * V_10 , unsigned long V_11 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_13 ) ;
struct V_1 * V_17 ;
int V_18 = V_13 -> V_19 + 3 ;
unsigned long V_20 , V_21 ;
if ( V_11 < V_16 -> V_22 || V_11 >= V_16 -> V_23 ) {
F_6 ( L_1 ) ;
return;
}
V_21 = V_11 - V_16 -> V_22 + 1 ;
V_20 = V_21 & ( ( 1 << V_18 ) - 1 ) ;
V_21 >>= V_18 ;
if ( V_21 >= V_16 -> V_24 ) {
F_6 ( L_2 ) ;
return;
}
V_17 = V_16 -> V_25 [ V_21 ] ;
F_7 ( & V_26 ) ;
if ( ! F_8 ( V_20 , V_17 -> V_9 ) )
F_6 ( L_3 ,
V_13 -> V_27 , V_11 ) ;
F_9 ( & V_26 ) ;
F_10 ( V_17 ) ;
return;
}
int F_11 ( struct V_10 * V_10 )
{
struct V_15 * V_16 = F_5 ( V_10 -> V_14 ) ;
int V_28 = 8 * V_10 -> V_14 -> V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_16 -> V_24 ; V_30 ++ ) {
struct V_1 * V_17 = V_16 -> V_25 [ V_30 ] ;
int V_31 ;
F_7 ( & V_26 ) ;
V_31 = F_12 ( V_17 -> V_9 , V_28 ) ;
if ( V_31 < V_28 ) {
F_13 ( V_31 , V_17 -> V_9 ) ;
F_9 ( & V_26 ) ;
F_10 ( V_17 ) ;
V_31 += V_30 * V_28 + V_16 -> V_22 - 1 ;
if ( V_31 < V_16 -> V_22 || V_31 >= V_16 -> V_23 )
break;
return V_31 ;
}
F_9 ( & V_26 ) ;
}
return 0 ;
}
unsigned long F_14 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_5 ( V_13 ) ;
T_3 V_32 = V_16 -> V_23 - V_16 -> V_22 + 1 ;
return ( F_1 ( V_16 -> V_25 , V_13 -> V_29 , V_32 )
<< V_16 -> V_33 ) ;
}
struct V_34 *
F_15 ( struct V_12 * V_13 , T_4 V_35 , struct V_1 * * V_17 )
{
int V_11 ;
struct V_15 * V_16 = F_5 ( V_13 ) ;
struct V_34 * V_8 ;
if ( ! V_35 || V_35 > V_16 -> V_36 ) {
F_6 ( L_4 ,
V_13 -> V_27 , ( long ) V_35 ) ;
return NULL ;
}
V_35 -- ;
V_11 = 2 + V_16 -> V_37 + V_16 -> V_24 +
V_35 / V_38 ;
* V_17 = F_16 ( V_13 , V_11 ) ;
if ( ! * V_17 ) {
F_6 ( L_5 ) ;
return NULL ;
}
V_8 = ( void * ) ( * V_17 ) -> V_9 ;
return V_8 + V_35 % V_38 ;
}
struct V_39 *
F_17 ( struct V_12 * V_13 , T_4 V_35 , struct V_1 * * V_17 )
{
int V_11 ;
struct V_15 * V_16 = F_5 ( V_13 ) ;
struct V_39 * V_8 ;
int V_40 = V_13 -> V_29 / sizeof( struct V_39 ) ;
* V_17 = NULL ;
if ( ! V_35 || V_35 > V_16 -> V_36 ) {
F_6 ( L_4 ,
V_13 -> V_27 , ( long ) V_35 ) ;
return NULL ;
}
V_35 -- ;
V_11 = 2 + V_16 -> V_37 + V_16 -> V_24 +
V_35 / V_40 ;
* V_17 = F_16 ( V_13 , V_11 ) ;
if ( ! * V_17 ) {
F_6 ( L_5 ) ;
return NULL ;
}
V_8 = ( void * ) ( * V_17 ) -> V_9 ;
return V_8 + V_35 % V_40 ;
}
static void F_18 ( struct V_10 * V_10 )
{
struct V_1 * V_17 = NULL ;
if ( F_19 ( V_10 ) == V_41 ) {
struct V_34 * V_42 ;
V_42 = F_15 ( V_10 -> V_14 , V_10 -> V_43 , & V_17 ) ;
if ( V_42 ) {
V_42 -> V_44 = 0 ;
V_42 -> V_45 = 0 ;
}
} else {
struct V_39 * V_42 ;
V_42 = F_17 ( V_10 -> V_14 , V_10 -> V_43 , & V_17 ) ;
if ( V_42 ) {
V_42 -> V_44 = 0 ;
V_42 -> V_45 = 0 ;
}
}
if ( V_17 ) {
F_10 ( V_17 ) ;
F_20 ( V_17 ) ;
}
}
void F_21 ( struct V_10 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_10 -> V_14 ) ;
struct V_1 * V_17 ;
int V_18 = V_13 -> V_19 + 3 ;
unsigned long V_35 , V_20 ;
V_35 = V_10 -> V_43 ;
if ( V_35 < 1 || V_35 > V_16 -> V_36 ) {
F_6 ( L_6 ) ;
return;
}
V_20 = V_35 & ( ( 1 << V_18 ) - 1 ) ;
V_35 >>= V_18 ;
if ( V_35 >= V_16 -> V_37 ) {
F_6 ( L_7 ) ;
return;
}
F_18 ( V_10 ) ;
V_17 = V_16 -> V_46 [ V_35 ] ;
F_7 ( & V_26 ) ;
if ( ! F_8 ( V_20 , V_17 -> V_9 ) )
F_6 ( L_8 , V_20 ) ;
F_9 ( & V_26 ) ;
F_10 ( V_17 ) ;
}
struct V_10 * F_22 ( const struct V_10 * V_47 , T_5 V_48 , int * error )
{
struct V_12 * V_13 = V_47 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_13 ) ;
struct V_10 * V_10 = F_23 ( V_13 ) ;
struct V_1 * V_17 ;
int V_28 = 8 * V_13 -> V_29 ;
unsigned long V_31 ;
int V_30 ;
if ( ! V_10 ) {
* error = - V_49 ;
return NULL ;
}
V_31 = V_28 ;
V_17 = NULL ;
* error = - V_50 ;
F_7 ( & V_26 ) ;
for ( V_30 = 0 ; V_30 < V_16 -> V_37 ; V_30 ++ ) {
V_17 = V_16 -> V_46 [ V_30 ] ;
V_31 = F_12 ( V_17 -> V_9 , V_28 ) ;
if ( V_31 < V_28 )
break;
}
if ( ! V_17 || V_31 >= V_28 ) {
F_9 ( & V_26 ) ;
F_24 ( V_10 ) ;
return NULL ;
}
if ( F_25 ( V_31 , V_17 -> V_9 ) ) {
F_9 ( & V_26 ) ;
F_6 ( L_9 ) ;
F_24 ( V_10 ) ;
return NULL ;
}
F_9 ( & V_26 ) ;
F_10 ( V_17 ) ;
V_31 += V_30 * V_28 ;
if ( ! V_31 || V_31 > V_16 -> V_36 ) {
F_24 ( V_10 ) ;
return NULL ;
}
F_26 ( V_10 , V_47 , V_48 ) ;
V_10 -> V_43 = V_31 ;
V_10 -> V_51 = V_10 -> V_52 = V_10 -> V_53 = V_54 ;
V_10 -> V_55 = 0 ;
memset ( & F_27 ( V_10 ) -> V_56 , 0 , sizeof( F_27 ( V_10 ) -> V_56 ) ) ;
F_28 ( V_10 ) ;
F_29 ( V_10 ) ;
* error = 0 ;
return V_10 ;
}
unsigned long F_30 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_5 ( V_13 ) ;
T_3 V_32 = V_16 -> V_36 + 1 ;
return F_1 ( V_16 -> V_46 , V_13 -> V_29 , V_32 ) ;
}
