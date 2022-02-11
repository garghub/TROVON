int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 * V_6 , bool V_7 )
{
struct V_8 * V_9 , * V_10 = NULL ;
struct V_8 * V_11 ;
T_1 V_12 ;
int V_13 = 0 ;
if ( ! V_7 ) {
if ( ! F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ) {
V_13 = - V_14 ;
} else {
V_2 -> V_15 [ V_3 ] . V_16 ++ ;
}
goto V_17;
}
V_12 = * V_6 ;
F_3 (sect, &target->ovly_list, list_elem) {
if ( V_12 <= V_9 -> V_12 ) {
if ( ( V_12 + V_4 > V_9 -> V_12 ) || ( V_10 &&
( V_10 -> V_12 +
V_10 -> V_4 >
V_12 ) ) ) {
V_13 = - V_18 ;
}
break;
}
V_10 = V_9 ;
}
if ( ! V_13 ) {
V_11 = F_4 ( sizeof( struct V_8 ) , V_19 ) ;
if ( V_11 == NULL ) {
V_13 = - V_14 ;
} else {
V_11 -> V_12 = V_12 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_20 = V_3 ;
if ( F_5 ( & V_9 -> V_21 , & V_2 -> V_22 ) )
F_6 ( & V_11 -> V_21 ,
& V_2 -> V_22 ) ;
else
F_6 ( & V_11 -> V_21 ,
& V_9 -> V_21 ) ;
}
}
V_17:
return V_13 ;
}
int F_7 ( struct V_1 * * V_23 ,
struct V_24 V_15 [] , T_1 V_25 )
{
struct V_26 * V_27 ;
struct V_24 * V_28 , * V_29 ;
struct V_1 * V_2 ;
T_2 V_30 ;
int V_13 = 0 ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_19 ) ;
if ( V_2 == NULL )
V_13 = - V_14 ;
if ( V_13 )
goto V_31;
V_2 -> V_25 = V_25 ;
if ( ! ( V_25 > 0 ) )
goto V_31;
V_2 -> V_32 = F_4 ( V_25 * sizeof( struct V_26 * ) ,
V_19 ) ;
if ( V_2 -> V_32 == NULL ) {
V_13 = - V_14 ;
} else {
for ( V_30 = 0 ; V_30 < ( T_2 ) V_25 ; V_30 ++ ) {
V_2 -> V_32 [ V_30 ] =
F_4 ( sizeof( struct V_26 ) , V_19 ) ;
if ( V_2 -> V_32 [ V_30 ] == NULL ) {
V_13 = - V_14 ;
break;
}
}
V_2 -> V_15 = F_4 ( V_25 * sizeof( struct V_24 ) ,
V_19 ) ;
if ( V_2 -> V_15 == NULL ) {
V_13 = - V_14 ;
} else {
V_28 = V_2 -> V_15 ;
for ( V_30 = 0 , V_29 = V_15 ; V_25 > 0 ;
V_25 -- , V_30 ++ ) {
* V_28 = * V_29 ;
V_27 = V_2 -> V_32 [ V_30 ] ;
V_27 -> V_12 = V_29 -> V_33 ;
V_27 -> V_4 = V_29 -> V_34 ;
V_27 -> V_35 = NULL ;
V_29 ++ ;
V_28 ++ ;
}
}
}
V_31:
if ( ! V_13 )
F_8 ( & V_2 -> V_22 ) ;
if ( ! V_13 ) {
* V_23 = V_2 ;
} else {
* V_23 = NULL ;
if ( V_2 )
F_9 ( V_2 ) ;
}
return V_13 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_29 ;
struct V_26 * V_27 ;
struct V_26 * V_35 ;
T_1 V_30 ;
F_10 ( V_2 -> V_15 ) ;
F_11 (sect, tmp, &target->ovly_list, list_elem) {
F_12 ( & V_9 -> V_21 ) ;
F_10 ( V_9 ) ;
}
if ( V_2 -> V_32 != NULL ) {
for ( V_30 = 0 ; V_30 < V_2 -> V_25 ; V_30 ++ ) {
V_27 = V_35 = V_2 -> V_32 [ V_30 ] ;
while ( V_35 ) {
V_27 = V_35 ;
V_35 = V_27 -> V_35 ;
F_10 ( V_27 ) ;
}
}
F_10 ( V_2 -> V_32 ) ;
}
F_10 ( V_2 ) ;
}
bool F_13 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_36 , T_1 V_4 ,
bool V_37 )
{
struct V_8 * V_9 , * V_29 ;
bool V_38 = false ;
if ( ! V_37 ) {
V_38 = F_14 ( V_2 , V_3 , V_36 , V_4 ) ;
if ( V_38 )
V_2 -> V_15 [ V_3 ] . V_16 -- ;
} else {
F_11 (sect, tmp, &target->ovly_list,
list_elem) {
if ( V_36 == V_9 -> V_12 ) {
F_12 ( & V_9 -> V_21 ) ;
F_10 ( V_9 ) ;
return true ;
}
}
}
return V_38 ;
}
bool F_15 ( struct V_1 * V_2 , enum V_39 V_3 ,
struct V_40 * V_41 )
{
struct V_26 * V_42 ;
bool V_38 = false ;
T_1 V_43 = 0 ;
T_1 V_44 = 0 ;
T_1 V_45 = 0 ;
if ( ( T_1 ) V_3 < V_2 -> V_25 ) {
V_42 = V_2 -> V_32 [ V_3 ] ;
while ( V_42 != NULL ) {
V_43 = F_16 ( V_43 , V_42 -> V_4 ) ;
V_44 += V_42 -> V_4 ;
V_45 ++ ;
V_42 = V_42 -> V_35 ;
}
V_41 -> V_4 = V_2 -> V_15 [ V_3 ] . V_34 ;
V_41 -> V_46 = V_45 ;
V_41 -> V_44 = V_44 ;
V_41 -> V_47 = V_43 ;
V_41 -> V_48 =
V_2 -> V_15 [ V_3 ] . V_16 ;
V_38 = true ;
}
return V_38 ;
}
static bool F_2 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 * V_6 )
{
struct V_26 * V_42 ;
struct V_26 * V_49 = NULL ;
struct V_26 * V_35 ;
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_12 ;
V_51 = ( V_5 == 0 ) ? 1 : V_5 ;
V_49 = NULL ;
V_42 = V_2 -> V_32 [ V_3 ] ;
do {
V_52 = V_42 -> V_4 ;
V_35 = V_42 -> V_35 ;
V_12 = V_42 -> V_12 ;
( V_50 = ( T_1 ) V_12 % V_51 ) ;
if ( V_50 != 0 )
V_50 = V_51 - V_50 ;
V_53 = V_4 + V_50 ;
if ( V_52 >= V_53 ) {
if ( V_52 == V_53 && V_49 != NULL ) {
V_49 -> V_35 = V_35 ;
F_10 ( V_42 ) ;
} else {
V_42 -> V_4 = V_52 - V_53 ;
V_42 -> V_12 += V_53 ;
}
if ( V_50 )
F_14 ( V_2 , V_3 , V_12 , V_50 ) ;
* V_6 = V_12 + V_50 ;
return true ;
}
V_49 = V_42 ;
V_42 = V_35 ;
} while ( V_42 != NULL );
return false ;
}
static bool F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 ,
T_1 V_4 )
{
struct V_26 * V_42 ;
struct V_26 * V_54 ;
struct V_26 * V_55 ;
bool V_38 = true ;
V_55 = F_4 ( sizeof( struct V_26 ) , V_19 ) ;
if ( V_55 == NULL ) {
V_38 = false ;
} else {
V_42 = V_2 -> V_32 [ V_3 ] ;
if ( V_12 >= V_42 -> V_12 ) {
while ( V_42 -> V_35 != NULL && V_12 > V_42 -> V_35 -> V_12 )
V_42 = V_42 -> V_35 ;
V_54 = V_42 -> V_35 ;
V_42 -> V_35 = V_55 ;
V_55 -> V_35 = V_54 ;
V_55 -> V_12 = V_12 ;
V_55 -> V_4 = V_4 ;
} else {
* V_55 = * V_42 ;
V_42 -> V_35 = V_55 ;
V_42 -> V_12 = V_12 ;
V_42 -> V_4 = V_4 ;
V_54 = V_55 -> V_35 ;
}
if ( V_54 != NULL && ( V_55 -> V_12 + V_55 -> V_4 ) ==
V_54 -> V_12 ) {
V_42 -> V_35 = V_55 -> V_35 ;
V_54 -> V_4 = V_4 + V_54 -> V_4 ;
V_54 -> V_12 = V_12 ;
F_10 ( V_55 ) ;
V_55 = V_54 ;
}
if ( ( V_42 -> V_12 + V_42 -> V_4 ) == V_55 -> V_12 ) {
V_42 -> V_35 = V_55 -> V_35 ;
V_42 -> V_4 = V_42 -> V_4 + V_55 -> V_4 ;
F_10 ( V_55 ) ;
}
}
return V_38 ;
}
