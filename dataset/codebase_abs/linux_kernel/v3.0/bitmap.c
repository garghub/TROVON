static unsigned long F_1 ( struct V_1 * V_2 [] , unsigned V_3 , T_1 V_4 )
{
unsigned V_5 , V_6 , V_7 = 0 ;
struct V_1 * V_8 ;
for ( V_5 = 0 ; V_5 < V_3 - 1 ; V_5 ++ ) {
if ( ! ( V_8 = V_2 [ V_5 ] ) )
return ( 0 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_9 ; V_6 ++ )
V_7 += V_10 [ V_8 -> V_11 [ V_6 ] & 0xf ]
+ V_10 [ ( V_8 -> V_11 [ V_6 ] >> 4 ) & 0xf ] ;
}
if ( V_3 == 0 || ! ( V_8 = V_2 [ V_3 - 1 ] ) )
return ( 0 ) ;
V_5 = ( ( V_4 - ( V_3 - 1 ) * V_8 -> V_9 * 8 ) / 16 ) * 2 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 += V_10 [ V_8 -> V_11 [ V_6 ] & 0xf ]
+ V_10 [ ( V_8 -> V_11 [ V_6 ] >> 4 ) & 0xf ] ;
}
V_5 = V_4 % 16 ;
if ( V_5 != 0 ) {
V_5 = * ( V_12 * ) ( & V_8 -> V_11 [ V_6 ] ) | ~ ( ( 1 << V_5 ) - 1 ) ;
V_7 += V_10 [ V_5 & 0xf ] + V_10 [ ( V_5 >> 4 ) & 0xf ] ;
V_7 += V_10 [ ( V_5 >> 8 ) & 0xf ] + V_10 [ ( V_5 >> 12 ) & 0xf ] ;
}
return ( V_7 ) ;
}
void F_2 ( struct V_13 * V_13 , unsigned long V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 = F_3 ( V_16 ) ;
struct V_1 * V_8 ;
int V_20 = V_16 -> V_21 + 3 ;
unsigned long V_22 , V_23 ;
if ( V_14 < V_19 -> V_24 || V_14 >= V_19 -> V_25 ) {
F_4 ( L_1 ) ;
return;
}
V_23 = V_14 - V_19 -> V_24 + 1 ;
V_22 = V_23 & ( ( 1 << V_20 ) - 1 ) ;
V_23 >>= V_20 ;
if ( V_23 >= V_19 -> V_26 ) {
F_4 ( L_2 ) ;
return;
}
V_8 = V_19 -> V_27 [ V_23 ] ;
F_5 ( & V_28 ) ;
if ( ! F_6 ( V_22 , V_8 -> V_11 ) )
F_4 ( L_3 ,
V_16 -> V_29 , V_14 ) ;
F_7 ( & V_28 ) ;
F_8 ( V_8 ) ;
return;
}
int F_9 ( struct V_13 * V_13 )
{
struct V_18 * V_19 = F_3 ( V_13 -> V_17 ) ;
int V_30 = 8 * V_13 -> V_17 -> V_31 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_19 -> V_26 ; V_5 ++ ) {
struct V_1 * V_8 = V_19 -> V_27 [ V_5 ] ;
int V_6 ;
F_5 ( & V_28 ) ;
V_6 = F_10 ( V_8 -> V_11 , V_30 ) ;
if ( V_6 < V_30 ) {
F_11 ( V_6 , V_8 -> V_11 ) ;
F_7 ( & V_28 ) ;
F_8 ( V_8 ) ;
V_6 += V_5 * V_30 + V_19 -> V_24 - 1 ;
if ( V_6 < V_19 -> V_24 || V_6 >= V_19 -> V_25 )
break;
return V_6 ;
}
F_7 ( & V_28 ) ;
}
return 0 ;
}
unsigned long F_12 ( struct V_18 * V_19 )
{
return ( F_1 ( V_19 -> V_27 , V_19 -> V_26 ,
V_19 -> V_25 - V_19 -> V_24 + 1 )
<< V_19 -> V_32 ) ;
}
struct V_33 *
F_13 ( struct V_15 * V_16 , T_2 V_34 , struct V_1 * * V_8 )
{
int V_14 ;
struct V_18 * V_19 = F_3 ( V_16 ) ;
struct V_33 * V_35 ;
if ( ! V_34 || V_34 > V_19 -> V_36 ) {
F_4 ( L_4 ,
V_16 -> V_29 , ( long ) V_34 ) ;
return NULL ;
}
V_34 -- ;
V_14 = 2 + V_19 -> V_37 + V_19 -> V_26 +
V_34 / V_38 ;
* V_8 = F_14 ( V_16 , V_14 ) ;
if ( ! * V_8 ) {
F_4 ( L_5 ) ;
return NULL ;
}
V_35 = ( void * ) ( * V_8 ) -> V_11 ;
return V_35 + V_34 % V_38 ;
}
struct V_39 *
F_15 ( struct V_15 * V_16 , T_2 V_34 , struct V_1 * * V_8 )
{
int V_14 ;
struct V_18 * V_19 = F_3 ( V_16 ) ;
struct V_39 * V_35 ;
int V_40 = V_16 -> V_31 / sizeof( struct V_39 ) ;
* V_8 = NULL ;
if ( ! V_34 || V_34 > V_19 -> V_36 ) {
F_4 ( L_4 ,
V_16 -> V_29 , ( long ) V_34 ) ;
return NULL ;
}
V_34 -- ;
V_14 = 2 + V_19 -> V_37 + V_19 -> V_26 +
V_34 / V_40 ;
* V_8 = F_14 ( V_16 , V_14 ) ;
if ( ! * V_8 ) {
F_4 ( L_5 ) ;
return NULL ;
}
V_35 = ( void * ) ( * V_8 ) -> V_11 ;
return V_35 + V_34 % V_40 ;
}
static void F_16 ( struct V_13 * V_13 )
{
struct V_1 * V_8 = NULL ;
if ( F_17 ( V_13 ) == V_41 ) {
struct V_33 * V_42 ;
V_42 = F_13 ( V_13 -> V_17 , V_13 -> V_43 , & V_8 ) ;
if ( V_42 ) {
V_42 -> V_44 = 0 ;
V_42 -> V_45 = 0 ;
}
} else {
struct V_39 * V_42 ;
V_42 = F_15 ( V_13 -> V_17 , V_13 -> V_43 , & V_8 ) ;
if ( V_42 ) {
V_42 -> V_44 = 0 ;
V_42 -> V_45 = 0 ;
}
}
if ( V_8 ) {
F_8 ( V_8 ) ;
F_18 ( V_8 ) ;
}
}
void F_19 ( struct V_13 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 = F_3 ( V_13 -> V_17 ) ;
struct V_1 * V_8 ;
int V_20 = V_16 -> V_21 + 3 ;
unsigned long V_34 , V_22 ;
V_34 = V_13 -> V_43 ;
if ( V_34 < 1 || V_34 > V_19 -> V_36 ) {
F_4 ( L_6 ) ;
return;
}
V_22 = V_34 & ( ( 1 << V_20 ) - 1 ) ;
V_34 >>= V_20 ;
if ( V_34 >= V_19 -> V_37 ) {
F_4 ( L_7 ) ;
return;
}
F_16 ( V_13 ) ;
V_8 = V_19 -> V_46 [ V_34 ] ;
F_5 ( & V_28 ) ;
if ( ! F_6 ( V_22 , V_8 -> V_11 ) )
F_4 ( L_8 , V_22 ) ;
F_7 ( & V_28 ) ;
F_8 ( V_8 ) ;
}
struct V_13 * F_20 ( const struct V_13 * V_47 , int V_48 , int * error )
{
struct V_15 * V_16 = V_47 -> V_17 ;
struct V_18 * V_19 = F_3 ( V_16 ) ;
struct V_13 * V_13 = F_21 ( V_16 ) ;
struct V_1 * V_8 ;
int V_30 = 8 * V_16 -> V_31 ;
unsigned long V_6 ;
int V_5 ;
if ( ! V_13 ) {
* error = - V_49 ;
return NULL ;
}
V_6 = V_30 ;
V_8 = NULL ;
* error = - V_50 ;
F_5 ( & V_28 ) ;
for ( V_5 = 0 ; V_5 < V_19 -> V_37 ; V_5 ++ ) {
V_8 = V_19 -> V_46 [ V_5 ] ;
V_6 = F_10 ( V_8 -> V_11 , V_30 ) ;
if ( V_6 < V_30 )
break;
}
if ( ! V_8 || V_6 >= V_30 ) {
F_7 ( & V_28 ) ;
F_22 ( V_13 ) ;
return NULL ;
}
if ( F_23 ( V_6 , V_8 -> V_11 ) ) {
F_7 ( & V_28 ) ;
F_4 ( L_9 ) ;
F_22 ( V_13 ) ;
return NULL ;
}
F_7 ( & V_28 ) ;
F_8 ( V_8 ) ;
V_6 += V_5 * V_30 ;
if ( ! V_6 || V_6 > V_19 -> V_36 ) {
F_22 ( V_13 ) ;
return NULL ;
}
F_24 ( V_13 , V_47 , V_48 ) ;
V_13 -> V_43 = V_6 ;
V_13 -> V_51 = V_13 -> V_52 = V_13 -> V_53 = V_54 ;
V_13 -> V_55 = 0 ;
memset ( & F_25 ( V_13 ) -> V_56 , 0 , sizeof( F_25 ( V_13 ) -> V_56 ) ) ;
F_26 ( V_13 ) ;
F_27 ( V_13 ) ;
* error = 0 ;
return V_13 ;
}
unsigned long F_28 ( struct V_18 * V_19 )
{
return F_1 ( V_19 -> V_46 , V_19 -> V_37 , V_19 -> V_36 + 1 ) ;
}
