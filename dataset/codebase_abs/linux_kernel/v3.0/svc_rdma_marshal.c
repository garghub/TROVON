static T_1 * F_1 ( T_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
while ( V_4 -> V_5 != V_6 ) {
T_2 V_7 ;
if ( ( ( unsigned long ) V_4 + sizeof( struct V_3 ) ) >
( unsigned long ) V_2 ) {
F_2 ( L_1 , V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_5 = F_3 ( V_4 -> V_5 ) ;
V_4 -> V_8 = F_3 ( V_4 -> V_8 ) ;
V_4 -> V_9 . V_10 = F_3 ( V_4 -> V_9 . V_10 ) ;
V_4 -> V_9 . V_11 = F_3 ( V_4 -> V_9 . V_11 ) ;
V_1 = ( T_1 * ) & V_4 -> V_9 . V_12 ;
F_4 ( V_1 , & V_7 ) ;
F_5 ( V_7 , ( T_2 * ) V_1 ) ;
V_4 ++ ;
}
return ( T_1 * ) & V_4 -> V_8 ;
}
void F_6 ( struct V_3 * V_4 ,
int * V_13 , int * V_14 )
{
* V_14 = 0 ;
* V_13 = 0 ;
for (; V_4 -> V_5 != 0 ; V_4 ++ ) {
* V_14 = * V_14 + V_4 -> V_9 . V_11 ;
* V_13 = * V_13 + 1 ;
}
}
static T_1 * F_7 ( T_1 * V_1 , T_1 * V_2 )
{
int V_15 ;
struct V_16 * V_17 =
(struct V_16 * ) V_1 ;
if ( V_17 -> V_18 == V_6 )
return ( T_1 * ) & V_17 -> V_19 ;
if ( ( unsigned long ) V_17 + sizeof( struct V_16 ) >
( unsigned long ) V_2 ) {
F_2 ( L_2 , V_17 , V_2 ) ;
return NULL ;
}
V_17 -> V_18 = F_3 ( V_17 -> V_18 ) ;
V_17 -> V_19 = F_3 ( V_17 -> V_19 ) ;
if ( ( ( unsigned long ) & V_17 -> V_20 [ 0 ] +
( sizeof( struct V_21 ) * V_17 -> V_19 ) ) >
( unsigned long ) V_2 ) {
F_2 ( L_3 ,
V_17 , V_17 -> V_19 , V_2 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_17 -> V_19 ; V_15 ++ ) {
T_2 V_7 ;
V_17 -> V_20 [ V_15 ] . V_22 . V_10 =
F_3 ( V_17 -> V_20 [ V_15 ] . V_22 . V_10 ) ;
V_17 -> V_20 [ V_15 ] . V_22 . V_11 =
F_3 ( V_17 -> V_20 [ V_15 ] . V_22 . V_11 ) ;
V_1 = ( T_1 * ) & V_17 -> V_20 [ V_15 ] . V_22 . V_12 ;
F_4 ( V_1 , & V_7 ) ;
F_5 ( V_7 , ( T_2 * ) V_1 ) ;
}
return ( T_1 * ) & V_17 -> V_20 [ V_15 ] . V_22 . V_11 ;
}
static T_1 * F_8 ( T_1 * V_1 , T_1 * V_2 )
{
int V_15 ;
struct V_16 * V_17 =
(struct V_16 * ) V_1 ;
if ( V_17 -> V_18 == V_6 )
return ( T_1 * ) & V_17 -> V_19 ;
if ( ( unsigned long ) V_17 + sizeof( struct V_16 ) >
( unsigned long ) V_2 ) {
F_2 ( L_2 , V_17 , V_2 ) ;
return NULL ;
}
V_17 -> V_18 = F_3 ( V_17 -> V_18 ) ;
V_17 -> V_19 = F_3 ( V_17 -> V_19 ) ;
if ( ( ( unsigned long ) & V_17 -> V_20 [ 0 ] +
( sizeof( struct V_21 ) * V_17 -> V_19 ) ) >
( unsigned long ) V_2 ) {
F_2 ( L_3 ,
V_17 , V_17 -> V_19 , V_2 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_17 -> V_19 ; V_15 ++ ) {
T_2 V_7 ;
V_17 -> V_20 [ V_15 ] . V_22 . V_10 =
F_3 ( V_17 -> V_20 [ V_15 ] . V_22 . V_10 ) ;
V_17 -> V_20 [ V_15 ] . V_22 . V_11 =
F_3 ( V_17 -> V_20 [ V_15 ] . V_22 . V_11 ) ;
V_1 = ( T_1 * ) & V_17 -> V_20 [ V_15 ] . V_22 . V_12 ;
F_4 ( V_1 , & V_7 ) ;
F_5 ( V_7 , ( T_2 * ) V_1 ) ;
}
return ( T_1 * ) & V_17 -> V_20 [ V_15 ] ;
}
int F_9 ( struct V_23 * * V_24 ,
struct V_25 * V_26 )
{
struct V_23 * V_27 = NULL ;
T_1 * V_1 ;
T_1 * V_2 ;
T_1 V_28 ;
V_27 = (struct V_23 * ) V_26 -> V_29 . V_30 [ 0 ] . V_31 ;
if ( V_26 -> V_29 . V_32 <= V_33 ) {
F_2 ( L_4 ,
V_26 -> V_29 . V_32 ) ;
return - V_34 ;
}
V_27 -> V_35 = F_3 ( V_27 -> V_35 ) ;
V_27 -> V_36 = F_3 ( V_27 -> V_36 ) ;
V_27 -> V_37 = F_3 ( V_27 -> V_37 ) ;
V_27 -> V_38 = F_3 ( V_27 -> V_38 ) ;
if ( V_27 -> V_36 != V_39 )
return - V_40 ;
if ( V_27 -> V_38 == V_41 ) {
int V_42 ;
V_27 -> V_43 . V_44 . V_45 =
F_3 ( V_27 -> V_43 . V_44 . V_45 ) ;
V_27 -> V_43 . V_44 . V_46 =
F_3 ( V_27 -> V_43 . V_44 . V_46 ) ;
V_1 = & V_27 -> V_43 . V_44 . V_47 [ 4 ] ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_42 = ( T_1 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_27 ) ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_42 ;
if ( V_42 > V_26 -> V_29 . V_32 )
return - V_34 ;
return V_42 ;
}
V_1 = & V_27 -> V_43 . V_49 [ 0 ] ;
V_2 = ( T_1 * ) ( ( unsigned long ) V_27 + V_26 -> V_29 . V_32 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_34 ;
V_1 = F_7 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_34 ;
V_1 = F_8 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_34 ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_28 = ( unsigned long ) V_1 - ( unsigned long ) V_27 ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_28 ;
* V_24 = V_27 ;
return V_28 ;
}
int F_10 ( struct V_25 * V_26 )
{
struct V_23 * V_27 = NULL ;
struct V_3 * V_4 ;
struct V_16 * V_17 ;
T_1 * V_1 ;
T_1 V_42 ;
F_2 ( L_5 ,
V_26 ) ;
V_27 = (struct V_23 * ) V_26 -> V_29 . V_30 [ 0 ] . V_31 ;
if ( V_27 -> V_38 == V_41 ) {
V_1 = & V_27 -> V_43 . V_44 . V_47 [ 4 ] ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_42 = ( T_1 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_27 ) ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_42 ;
return V_42 ;
}
V_1 = & V_27 -> V_43 . V_49 [ 0 ] ;
for ( V_4 = (struct V_3 * ) V_1 ;
V_4 -> V_5 != V_6 ; V_4 ++ ) ;
V_1 = ( T_1 * ) & V_4 -> V_8 ;
V_17 = (struct V_16 * ) V_1 ;
if ( V_17 -> V_18 == V_6 )
V_1 = ( T_1 * ) & V_17 -> V_19 ;
else
V_1 = ( T_1 * ) & V_17 -> V_20 [ V_17 -> V_19 ] . V_22 . V_11 ;
V_17 = (struct V_16 * ) V_1 ;
if ( V_17 -> V_18 == V_6 )
V_1 = ( T_1 * ) & V_17 -> V_19 ;
else
V_1 = ( T_1 * ) & V_17 -> V_20 [ V_17 -> V_19 ] ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_42 = ( unsigned long ) V_1 - ( unsigned long ) V_27 ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_42 ;
return V_42 ;
}
int F_11 ( struct V_50 * V_51 ,
struct V_23 * V_27 ,
enum V_52 V_53 , T_1 * V_1 )
{
T_1 * V_54 = V_1 ;
* V_1 ++ = F_12 ( V_27 -> V_35 ) ;
* V_1 ++ = F_12 ( V_27 -> V_36 ) ;
* V_1 ++ = F_12 ( V_51 -> V_55 ) ;
* V_1 ++ = F_12 ( V_56 ) ;
* V_1 ++ = F_12 ( V_53 ) ;
if ( V_53 == V_57 ) {
* V_1 ++ = F_12 ( V_39 ) ;
* V_1 ++ = F_12 ( V_39 ) ;
}
return ( int ) ( ( unsigned long ) V_1 - ( unsigned long ) V_54 ) ;
}
int F_13 ( struct V_23 * V_27 )
{
struct V_16 * V_58 ;
V_58 = (struct V_16 * )
& V_27 -> V_43 . V_49 [ 1 ] ;
if ( V_58 -> V_18 )
V_58 = (struct V_16 * )
& V_58 -> V_20 [ F_3 ( V_58 -> V_19 ) ] .
V_22 . V_11 ;
else
V_58 = (struct V_16 * )
& V_58 -> V_19 ;
if ( V_58 -> V_18 )
V_58 = (struct V_16 * )
& V_58 -> V_20 [ F_3 ( V_58 -> V_19 ) ] ;
else
V_58 = (struct V_16 * )
& V_58 -> V_19 ;
return ( unsigned long ) V_58 - ( unsigned long ) V_27 ;
}
void F_14 ( struct V_23 * V_27 , int V_59 )
{
struct V_16 * V_17 ;
V_27 -> V_43 . V_49 [ 0 ] = V_6 ;
V_17 = (struct V_16 * )
& V_27 -> V_43 . V_49 [ 1 ] ;
V_17 -> V_18 = V_60 ;
V_17 -> V_19 = F_12 ( V_59 ) ;
V_17 -> V_20 [ V_59 ] . V_22 . V_10 = V_6 ;
V_17 -> V_20 [ V_59 ] . V_22 . V_11 = V_6 ;
}
void F_15 ( struct V_16 * V_17 ,
int V_59 )
{
V_17 -> V_18 = V_60 ;
V_17 -> V_19 = F_12 ( V_59 ) ;
}
void F_16 ( struct V_16 * V_17 ,
int V_61 ,
T_1 V_10 , T_2 V_12 ,
T_1 V_62 )
{
struct V_63 * V_64 = & V_17 -> V_20 [ V_61 ] . V_22 ;
V_64 -> V_10 = F_12 ( V_10 ) ;
V_64 -> V_11 = F_12 ( V_62 ) ;
F_17 ( ( T_1 * ) & V_64 -> V_12 , V_12 ) ;
}
void F_18 ( struct V_50 * V_51 ,
struct V_23 * V_65 ,
struct V_23 * V_66 ,
enum V_67 V_68 )
{
V_66 -> V_35 = F_12 ( V_65 -> V_35 ) ;
V_66 -> V_36 = F_12 ( V_65 -> V_36 ) ;
V_66 -> V_37 = F_12 ( V_51 -> V_55 ) ;
V_66 -> V_38 = F_12 ( V_68 ) ;
V_66 -> V_43 . V_49 [ 0 ] = V_6 ;
V_66 -> V_43 . V_49 [ 1 ] = V_6 ;
V_66 -> V_43 . V_49 [ 2 ] = V_6 ;
}
