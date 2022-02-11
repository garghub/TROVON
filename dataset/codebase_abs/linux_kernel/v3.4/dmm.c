int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
int V_6 = 0 ;
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 ) {
V_7 = V_3 ;
V_8 = F_3 ( V_4 , V_9 ) / V_9 ;
V_10 = F_4 ( V_8 *
sizeof( struct V_11 ) , V_12 |
V_13 | V_14 , V_15 ) ;
if ( V_10 == NULL )
V_6 = - V_16 ;
else {
V_17 = 0 ;
V_18 = V_8 * V_9 ;
V_10 [ 0 ] . V_19 = V_8 ;
}
}
if ( V_6 )
F_5 ( L_1 , V_20 , V_6 ) ;
return V_6 ;
}
int F_6 ( struct V_1 * * V_21 ,
struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_1 * V_5 = NULL ;
int V_6 = 0 ;
* V_21 = NULL ;
V_5 = F_7 ( sizeof( struct V_1 ) , V_12 ) ;
if ( V_5 != NULL ) {
F_8 ( & V_5 -> V_26 ) ;
* V_21 = V_5 ;
} else {
V_6 = - V_16 ;
}
return V_6 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
int V_6 = 0 ;
if ( V_2 ) {
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 )
F_10 ( V_5 ) ;
} else
V_6 = - V_27 ;
return V_6 ;
}
int F_2 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 )
F_11 ( V_10 ) ;
else
V_6 = - V_27 ;
return V_6 ;
}
int F_12 ( void * V_28 , struct V_1 * * V_21 )
{
int V_6 = 0 ;
struct V_22 * V_23 ;
if ( V_28 != NULL )
V_6 = F_13 ( V_28 , & V_23 ) ;
else
V_23 = F_14 () ;
if ( ! V_6 )
V_6 = F_15 ( V_23 , V_21 ) ;
return V_6 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_29 ;
int V_6 = 0 ;
F_17 ( & V_5 -> V_26 ) ;
V_29 = (struct V_11 * ) F_18 ( V_3 ) ;
if ( V_29 != NULL ) {
V_29 -> V_30 = true ;
V_29 -> V_31 = ( V_4 / V_9 ) ;
} else
V_6 = - V_32 ;
F_19 ( & V_5 -> V_26 ) ;
F_20 ( V_33 , L_2
L_3 , V_20 , V_2 , V_3 , V_4 , V_6 , V_29 ) ;
return V_6 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_4 ,
T_1 * V_34 )
{
int V_6 = 0 ;
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_35 ;
T_1 V_36 = 0 ;
T_1 V_37 = 0 ;
F_17 ( & V_5 -> V_26 ) ;
V_35 = F_22 ( V_4 ) ;
if ( V_35 != NULL ) {
V_36 = F_23 ( V_35 ) ;
V_37 = V_4 / V_9 ;
if ( V_37 < V_35 -> V_19 ) {
V_35 [ V_37 ] . V_30 = false ;
V_35 [ V_37 ] . V_38 = false ;
V_35 [ V_37 ] . V_19 =
V_35 -> V_19 - V_37 ;
V_35 [ V_37 ] . V_31 = 0 ;
}
V_35 -> V_30 = false ;
V_35 -> V_38 = true ;
V_35 -> V_19 = V_37 ;
V_35 -> V_31 = 0 ;
* V_34 = V_36 ;
} else
V_6 = - V_16 ;
F_19 ( & V_5 -> V_26 ) ;
F_20 ( V_33 , L_4
L_5 , V_20 , V_2 , V_4 ,
V_34 , V_6 , V_36 , V_37 ) ;
return V_6 ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_39 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_29 ;
int V_6 = 0 ;
F_17 ( & V_5 -> V_26 ) ;
V_29 = F_25 ( V_3 ) ;
if ( V_29 == NULL )
V_6 = - V_32 ;
if ( ! V_6 ) {
* V_39 = V_29 -> V_31 * V_9 ;
V_29 -> V_30 = false ;
V_29 -> V_31 = 0 ;
}
F_19 ( & V_5 -> V_26 ) ;
F_20 ( V_33 , L_6
L_7 , V_20 , V_2 , V_3 , V_39 , V_6 , V_29 ) ;
return V_6 ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_29 ;
T_1 V_40 ;
int V_6 = 0 ;
T_1 V_41 ;
F_17 ( & V_5 -> V_26 ) ;
V_29 = F_25 ( V_36 ) ;
if ( V_29 == NULL )
V_6 = - V_32 ;
if ( ! V_6 ) {
V_40 = 0 ;
while ( V_40 < V_29 -> V_19 ) {
if ( V_29 [ V_40 ] . V_30 ) {
V_41 = V_29 [ V_40 ] . V_31 ;
V_29 [ V_40 ] . V_30 = false ;
V_29 [ V_40 ] . V_31 = 0 ;
V_40 += V_41 ;
} else
V_40 ++ ;
}
V_29 -> V_38 = false ;
}
F_19 ( & V_5 -> V_26 ) ;
F_20 ( V_33 , L_8 ,
V_20 , V_2 , V_36 , V_6 , V_29 ) ;
return V_6 ;
}
static struct V_11 * F_18 ( T_1 V_3 )
{
struct V_11 * V_42 = NULL ;
T_1 V_40 = 0 ;
if ( V_10 != NULL ) {
V_40 = F_27 ( V_3 ) ;
if ( V_40 < V_8 )
V_42 = V_10 + V_40 ;
}
F_20 ( V_33 , L_9 ,
V_20 , V_42 , V_17 , V_18 ) ;
return V_42 ;
}
static struct V_11 * F_22 ( T_1 V_43 )
{
struct V_11 * V_42 = NULL ;
T_1 V_40 = 0 ;
T_1 V_19 = 0 ;
T_1 V_44 = 0 ;
if ( V_10 == NULL )
return V_42 ;
if ( V_43 > V_18 ) {
while ( V_40 < V_8 ) {
V_19 = V_10 [ V_40 ] . V_19 ;
V_44 = V_40 + V_19 ;
if ( V_10 [ V_40 ] . V_38 == false ) {
if ( V_44 < V_8 &&
V_10 [ V_44 ] . V_38
== false ) {
V_10 [ V_40 ] . V_19 +=
V_10
[ V_44 ] . V_19 ;
continue;
}
V_19 *= V_9 ;
if ( V_19 > V_18 ) {
V_17 = V_40 ;
V_18 = V_19 ;
}
}
V_40 = V_44 ;
}
}
if ( V_43 <= V_18 ) {
V_42 = V_10 + V_17 ;
V_17 += ( V_43 / V_9 ) ;
V_18 -= V_43 ;
}
return V_42 ;
}
static struct V_11 * F_25 ( T_1 V_45 )
{
T_1 V_40 = 0 ;
struct V_11 * V_42 = NULL ;
if ( V_10 == NULL )
return V_42 ;
V_40 = F_27 ( V_45 ) ;
if ( V_40 < V_8 && ( V_10 [ V_40 ] . V_30 ||
V_10 [ V_40 ] . V_38 ) )
V_42 = V_10 + V_40 ;
return V_42 ;
}
T_1 F_28 ( struct V_1 * V_2 )
{
struct V_11 * V_46 = NULL ;
T_1 V_40 ;
T_1 V_47 = 0 ;
T_1 V_48 = 0 ;
F_17 ( & V_2 -> V_26 ) ;
if ( V_10 != NULL ) {
for ( V_40 = 0 ; V_40 < V_8 ; V_40 +=
V_10 [ V_40 ] . V_19 ) {
V_46 = V_10 + V_40 ;
if ( V_46 -> V_38 ) {
} else {
V_47 += ( V_46 -> V_19 * V_9 ) ;
if ( V_46 -> V_19 > V_48 )
V_48 = V_46 -> V_19 ;
}
}
}
F_19 ( & V_2 -> V_26 ) ;
F_29 ( V_49 L_10 ,
V_47 / ( 1024 * 1024 ) ) ;
F_29 ( V_49 L_11 ,
( ( ( V_8 * V_9 ) - V_47 ) ) / ( 1024 * 1024 ) ) ;
F_29 ( V_49 L_12 ,
( V_48 * V_9 / ( 1024 * 1024 ) ) ) ;
return 0 ;
}
