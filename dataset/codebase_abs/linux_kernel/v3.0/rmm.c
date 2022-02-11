int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 * V_6 , bool V_7 )
{
struct V_8 * V_9 , * V_10 = NULL ;
struct V_8 * V_11 ;
T_1 V_12 ;
int V_13 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_6 != NULL ) ;
F_2 ( V_4 > 0 ) ;
F_2 ( V_7 || ( V_2 -> V_14 > 0 ) ) ;
F_2 ( V_15 > 0 ) ;
if ( ! V_7 ) {
if ( ! F_3 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ) {
V_13 = - V_16 ;
} else {
V_2 -> V_17 [ V_3 ] . V_18 ++ ;
}
goto V_19;
}
V_12 = * V_6 ;
F_4 (sect, &target->ovly_list, list_elem) {
if ( V_12 <= V_9 -> V_12 ) {
if ( ( V_12 + V_4 > V_9 -> V_12 ) || ( V_10 &&
( V_10 -> V_12 +
V_10 -> V_4 >
V_12 ) ) ) {
V_13 = - V_20 ;
}
break;
}
V_10 = V_9 ;
}
if ( ! V_13 ) {
V_11 = F_5 ( sizeof( struct V_8 ) , V_21 ) ;
if ( V_11 == NULL ) {
V_13 = - V_16 ;
} else {
V_11 -> V_12 = V_12 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_22 = V_3 ;
if ( F_6 ( & V_9 -> V_23 , & V_2 -> V_24 ) )
F_7 ( & V_11 -> V_23 ,
& V_2 -> V_24 ) ;
else
F_7 ( & V_11 -> V_23 ,
& V_9 -> V_23 ) ;
}
}
V_19:
return V_13 ;
}
int F_8 ( struct V_1 * * V_25 ,
struct V_26 V_17 [] , T_1 V_14 )
{
struct V_27 * V_28 ;
struct V_26 * V_29 , * V_30 ;
struct V_1 * V_2 ;
T_2 V_31 ;
int V_13 = 0 ;
F_2 ( V_25 != NULL ) ;
F_2 ( V_14 == 0 || V_17 != NULL ) ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_21 ) ;
if ( V_2 == NULL )
V_13 = - V_16 ;
if ( V_13 )
goto V_32;
V_2 -> V_14 = V_14 ;
if ( ! ( V_14 > 0 ) )
goto V_32;
V_2 -> V_33 = F_5 ( V_14 * sizeof( struct V_27 * ) ,
V_21 ) ;
if ( V_2 -> V_33 == NULL ) {
V_13 = - V_16 ;
} else {
for ( V_31 = 0 ; V_31 < ( T_2 ) V_14 ; V_31 ++ ) {
V_2 -> V_33 [ V_31 ] =
F_5 ( sizeof( struct V_27 ) , V_21 ) ;
if ( V_2 -> V_33 [ V_31 ] == NULL ) {
V_13 = - V_16 ;
break;
}
}
V_2 -> V_17 = F_5 ( V_14 * sizeof( struct V_26 ) ,
V_21 ) ;
if ( V_2 -> V_17 == NULL ) {
V_13 = - V_16 ;
} else {
V_29 = V_2 -> V_17 ;
for ( V_31 = 0 , V_30 = V_17 ; V_14 > 0 ;
V_14 -- , V_31 ++ ) {
* V_29 = * V_30 ;
V_28 = V_2 -> V_33 [ V_31 ] ;
V_28 -> V_12 = V_30 -> V_34 ;
V_28 -> V_4 = V_30 -> V_35 ;
V_28 -> V_36 = NULL ;
V_30 ++ ;
V_29 ++ ;
}
}
}
V_32:
if ( ! V_13 )
F_9 ( & V_2 -> V_24 ) ;
if ( ! V_13 ) {
* V_25 = V_2 ;
} else {
* V_25 = NULL ;
if ( V_2 )
F_10 ( V_2 ) ;
}
F_11 ( ( ! V_13 && * V_25 )
|| ( V_13 && * V_25 == NULL ) ) ;
return V_13 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_30 ;
struct V_27 * V_28 ;
struct V_27 * V_36 ;
T_1 V_31 ;
F_2 ( V_2 ) ;
F_12 ( V_2 -> V_17 ) ;
F_13 (sect, tmp, &target->ovly_list, list_elem) {
F_14 ( & V_9 -> V_23 ) ;
F_12 ( V_9 ) ;
}
if ( V_2 -> V_33 != NULL ) {
for ( V_31 = 0 ; V_31 < V_2 -> V_14 ; V_31 ++ ) {
V_28 = V_36 = V_2 -> V_33 [ V_31 ] ;
while ( V_36 ) {
V_28 = V_36 ;
V_36 = V_28 -> V_36 ;
F_12 ( V_28 ) ;
}
}
F_12 ( V_2 -> V_33 ) ;
}
F_12 ( V_2 ) ;
}
void F_15 ( void )
{
F_2 ( V_15 > 0 ) ;
V_15 -- ;
F_11 ( V_15 >= 0 ) ;
}
bool F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_37 , T_1 V_4 ,
bool V_38 )
{
struct V_8 * V_9 , * V_30 ;
bool V_39 = false ;
F_2 ( V_2 ) ;
F_2 ( V_38 || V_3 < V_2 -> V_14 ) ;
F_2 ( V_38 || ( V_37 >= V_2 -> V_17 [ V_3 ] . V_34 &&
( V_37 + V_4 ) <= ( V_2 -> V_17 [ V_3 ] .
V_34 +
V_2 -> V_17 [ V_3 ] .
V_35 ) ) ) ;
if ( ! V_38 ) {
V_39 = F_17 ( V_2 , V_3 , V_37 , V_4 ) ;
if ( V_39 )
V_2 -> V_17 [ V_3 ] . V_18 -- ;
} else {
F_13 (sect, tmp, &target->ovly_list,
list_elem) {
if ( V_37 == V_9 -> V_12 ) {
F_18 ( V_4 == V_9 -> V_4 ) ;
F_14 ( & V_9 -> V_23 ) ;
F_12 ( V_9 ) ;
return true ;
}
}
}
return V_39 ;
}
bool F_19 ( void )
{
F_2 ( V_15 >= 0 ) ;
V_15 ++ ;
return true ;
}
bool F_20 ( struct V_1 * V_2 , enum V_40 V_3 ,
struct V_41 * V_42 )
{
struct V_27 * V_43 ;
bool V_39 = false ;
T_1 V_44 = 0 ;
T_1 V_45 = 0 ;
T_1 V_46 = 0 ;
F_2 ( V_42 != NULL ) ;
F_18 ( V_2 != NULL ) ;
if ( ( T_1 ) V_3 < V_2 -> V_14 ) {
V_43 = V_2 -> V_33 [ V_3 ] ;
while ( V_43 != NULL ) {
V_44 = F_21 ( V_44 , V_43 -> V_4 ) ;
V_45 += V_43 -> V_4 ;
V_46 ++ ;
V_43 = V_43 -> V_36 ;
}
V_42 -> V_4 = V_2 -> V_17 [ V_3 ] . V_35 ;
V_42 -> V_47 = V_46 ;
V_42 -> V_45 = V_45 ;
V_42 -> V_48 = V_44 ;
V_42 -> V_49 =
V_2 -> V_17 [ V_3 ] . V_18 ;
V_39 = true ;
}
return V_39 ;
}
static bool F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 * V_6 )
{
struct V_27 * V_43 ;
struct V_27 * V_50 = NULL ;
struct V_27 * V_36 ;
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_54 ;
T_1 V_12 ;
V_52 = ( V_5 == 0 ) ? 1 : V_5 ;
V_50 = NULL ;
V_43 = V_2 -> V_33 [ V_3 ] ;
do {
V_53 = V_43 -> V_4 ;
V_36 = V_43 -> V_36 ;
V_12 = V_43 -> V_12 ;
( V_51 = ( T_1 ) V_12 % V_52 ) ;
if ( V_51 != 0 )
V_51 = V_52 - V_51 ;
V_54 = V_4 + V_51 ;
if ( V_53 >= V_54 ) {
if ( V_53 == V_54 && V_50 != NULL ) {
V_50 -> V_36 = V_36 ;
F_12 ( V_43 ) ;
} else {
V_43 -> V_4 = V_53 - V_54 ;
V_43 -> V_12 += V_54 ;
}
if ( V_51 )
F_17 ( V_2 , V_3 , V_12 , V_51 ) ;
* V_6 = V_12 + V_51 ;
return true ;
}
V_50 = V_43 ;
V_43 = V_36 ;
} while ( V_43 != NULL );
return false ;
}
static bool F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 ,
T_1 V_4 )
{
struct V_27 * V_43 ;
struct V_27 * V_55 ;
struct V_27 * V_56 ;
bool V_39 = true ;
V_56 = F_5 ( sizeof( struct V_27 ) , V_21 ) ;
if ( V_56 == NULL ) {
V_39 = false ;
} else {
V_43 = V_2 -> V_33 [ V_3 ] ;
if ( V_12 >= V_43 -> V_12 ) {
while ( V_43 -> V_36 != NULL && V_12 > V_43 -> V_36 -> V_12 )
V_43 = V_43 -> V_36 ;
V_55 = V_43 -> V_36 ;
V_43 -> V_36 = V_56 ;
V_56 -> V_36 = V_55 ;
V_56 -> V_12 = V_12 ;
V_56 -> V_4 = V_4 ;
} else {
* V_56 = * V_43 ;
V_43 -> V_36 = V_56 ;
V_43 -> V_12 = V_12 ;
V_43 -> V_4 = V_4 ;
V_55 = V_56 -> V_36 ;
}
if ( V_55 != NULL && ( V_56 -> V_12 + V_56 -> V_4 ) ==
V_55 -> V_12 ) {
V_43 -> V_36 = V_56 -> V_36 ;
V_55 -> V_4 = V_4 + V_55 -> V_4 ;
V_55 -> V_12 = V_12 ;
F_12 ( V_56 ) ;
V_56 = V_55 ;
}
if ( ( V_43 -> V_12 + V_43 -> V_4 ) == V_56 -> V_12 ) {
V_43 -> V_36 = V_56 -> V_36 ;
V_43 -> V_4 = V_43 -> V_4 + V_56 -> V_4 ;
F_12 ( V_56 ) ;
}
}
return V_39 ;
}
