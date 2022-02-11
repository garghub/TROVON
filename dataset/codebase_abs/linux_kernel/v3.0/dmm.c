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
F_7 ( V_26 > 0 ) ;
F_7 ( V_21 != NULL ) ;
* V_21 = NULL ;
V_5 = F_8 ( sizeof( struct V_1 ) , V_12 ) ;
if ( V_5 != NULL ) {
F_9 ( & V_5 -> V_27 ) ;
* V_21 = V_5 ;
} else {
V_6 = - V_16 ;
}
return V_6 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
int V_6 = 0 ;
F_7 ( V_26 > 0 ) ;
if ( V_2 ) {
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 )
F_11 ( V_5 ) ;
} else
V_6 = - V_28 ;
return V_6 ;
}
int F_2 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_7 ( V_26 > 0 ) ;
if ( V_2 )
F_12 ( V_10 ) ;
else
V_6 = - V_28 ;
return V_6 ;
}
void F_13 ( void )
{
F_7 ( V_26 > 0 ) ;
V_26 -- ;
}
int F_14 ( void * V_29 , struct V_1 * * V_21 )
{
int V_6 = 0 ;
struct V_22 * V_23 ;
F_7 ( V_26 > 0 ) ;
F_7 ( V_21 != NULL ) ;
if ( V_29 != NULL )
V_6 = F_15 ( V_29 , & V_23 ) ;
else
V_23 = F_16 () ;
if ( ! V_6 )
V_6 = F_17 ( V_23 , V_21 ) ;
return V_6 ;
}
bool F_18 ( void )
{
bool V_30 = true ;
F_7 ( V_26 >= 0 ) ;
if ( V_30 )
V_26 ++ ;
F_19 ( ( V_30 && ( V_26 > 0 ) ) || ( ! V_30 && ( V_26 >= 0 ) ) ) ;
V_10 = NULL ;
V_8 = 0 ;
return V_30 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_31 ;
int V_6 = 0 ;
F_21 ( & V_5 -> V_27 ) ;
V_31 = (struct V_11 * ) F_22 ( V_3 ) ;
if ( V_31 != NULL ) {
V_31 -> V_32 = true ;
V_31 -> V_33 = ( V_4 / V_9 ) ;
} else
V_6 = - V_34 ;
F_23 ( & V_5 -> V_27 ) ;
F_24 ( V_35 , L_2
L_3 , V_20 , V_2 , V_3 , V_4 , V_6 , V_31 ) ;
return V_6 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_4 ,
T_1 * V_36 )
{
int V_6 = 0 ;
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_37 ;
T_1 V_38 = 0 ;
T_1 V_39 = 0 ;
F_21 ( & V_5 -> V_27 ) ;
V_37 = F_26 ( V_4 ) ;
if ( V_37 != NULL ) {
V_38 = F_27 ( V_37 ) ;
V_39 = V_4 / V_9 ;
if ( V_39 < V_37 -> V_19 ) {
V_37 [ V_39 ] . V_32 = false ;
V_37 [ V_39 ] . V_40 = false ;
V_37 [ V_39 ] . V_19 =
V_37 -> V_19 - V_39 ;
V_37 [ V_39 ] . V_33 = 0 ;
}
V_37 -> V_32 = false ;
V_37 -> V_40 = true ;
V_37 -> V_19 = V_39 ;
V_37 -> V_33 = 0 ;
* V_36 = V_38 ;
} else
V_6 = - V_16 ;
F_23 ( & V_5 -> V_27 ) ;
F_24 ( V_35 , L_4
L_5 , V_20 , V_2 , V_4 ,
V_36 , V_6 , V_38 , V_39 ) ;
return V_6 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_41 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_31 ;
int V_6 = 0 ;
F_21 ( & V_5 -> V_27 ) ;
V_31 = F_29 ( V_3 ) ;
if ( V_31 == NULL )
V_6 = - V_34 ;
if ( ! V_6 ) {
* V_41 = V_31 -> V_33 * V_9 ;
V_31 -> V_32 = false ;
V_31 -> V_33 = 0 ;
}
F_23 ( & V_5 -> V_27 ) ;
F_24 ( V_35 , L_6
L_7 , V_20 , V_2 , V_3 , V_41 , V_6 , V_31 ) ;
return V_6 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
struct V_11 * V_31 ;
T_1 V_42 ;
int V_6 = 0 ;
T_1 V_43 ;
F_21 ( & V_5 -> V_27 ) ;
V_31 = F_29 ( V_38 ) ;
if ( V_31 == NULL )
V_6 = - V_34 ;
if ( ! V_6 ) {
V_42 = 0 ;
while ( V_42 < V_31 -> V_19 ) {
if ( V_31 [ V_42 ] . V_32 ) {
V_43 = V_31 [ V_42 ] . V_33 ;
V_31 [ V_42 ] . V_32 = false ;
V_31 [ V_42 ] . V_33 = 0 ;
V_42 += V_43 ;
} else
V_42 ++ ;
}
V_31 -> V_40 = false ;
}
F_23 ( & V_5 -> V_27 ) ;
F_24 ( V_35 , L_8 ,
V_20 , V_2 , V_38 , V_6 , V_31 ) ;
return V_6 ;
}
static struct V_11 * F_22 ( T_1 V_3 )
{
struct V_11 * V_44 = NULL ;
T_1 V_42 = 0 ;
if ( V_10 != NULL ) {
V_42 = F_31 ( V_3 ) ;
if ( V_42 < V_8 )
V_44 = V_10 + V_42 ;
}
F_24 ( V_35 , L_9 ,
V_20 , V_44 , V_17 , V_18 ) ;
return V_44 ;
}
static struct V_11 * F_26 ( T_1 V_45 )
{
struct V_11 * V_44 = NULL ;
T_1 V_42 = 0 ;
T_1 V_19 = 0 ;
T_1 V_46 = 0 ;
if ( V_10 == NULL )
return V_44 ;
if ( V_45 > V_18 ) {
while ( V_42 < V_8 ) {
V_19 = V_10 [ V_42 ] . V_19 ;
V_46 = V_42 + V_19 ;
if ( V_10 [ V_42 ] . V_40 == false ) {
if ( V_46 < V_8 &&
V_10 [ V_46 ] . V_40
== false ) {
V_10 [ V_42 ] . V_19 +=
V_10
[ V_46 ] . V_19 ;
continue;
}
V_19 *= V_9 ;
if ( V_19 > V_18 ) {
V_17 = V_42 ;
V_18 = V_19 ;
}
}
V_42 = V_46 ;
}
}
if ( V_45 <= V_18 ) {
V_44 = V_10 + V_17 ;
V_17 += ( V_45 / V_9 ) ;
V_18 -= V_45 ;
}
return V_44 ;
}
static struct V_11 * F_29 ( T_1 V_47 )
{
T_1 V_42 = 0 ;
struct V_11 * V_44 = NULL ;
if ( V_10 == NULL )
return V_44 ;
V_42 = F_31 ( V_47 ) ;
if ( V_42 < V_8 && ( V_10 [ V_42 ] . V_32 ||
V_10 [ V_42 ] . V_40 ) )
V_44 = V_10 + V_42 ;
return V_44 ;
}
T_1 F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_48 = NULL ;
T_1 V_42 ;
T_1 V_49 = 0 ;
T_1 V_50 = 0 ;
F_21 ( & V_2 -> V_27 ) ;
if ( V_10 != NULL ) {
for ( V_42 = 0 ; V_42 < V_8 ; V_42 +=
V_10 [ V_42 ] . V_19 ) {
V_48 = V_10 + V_42 ;
if ( V_48 -> V_40 ) {
} else {
V_49 += ( V_48 -> V_19 * V_9 ) ;
if ( V_48 -> V_19 > V_50 )
V_50 = V_48 -> V_19 ;
}
}
}
F_23 ( & V_2 -> V_27 ) ;
F_33 ( V_51 L_10 ,
V_49 / ( 1024 * 1024 ) ) ;
F_33 ( V_51 L_11 ,
( ( ( V_8 * V_9 ) - V_49 ) ) / ( 1024 * 1024 ) ) ;
F_33 ( V_51 L_12 ,
( V_50 * V_9 / ( 1024 * 1024 ) ) ) ;
return 0 ;
}
