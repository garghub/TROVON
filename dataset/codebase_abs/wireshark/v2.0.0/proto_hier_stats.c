static T_1 *
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
T_3 * V_5 ;
V_3 = F_2 ( V_1 ) ;
while ( V_3 ) {
V_4 = F_3 ( V_3 ) ;
if ( V_4 && V_4 -> V_6 == V_2 -> V_6 ) {
return V_3 ;
}
V_3 = F_4 ( V_3 ) ;
}
V_5 = F_5 ( T_3 , 1 ) ;
V_5 -> V_4 = V_2 ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0 ;
V_3 = F_6 ( V_5 ) ;
F_7 ( V_1 , V_3 ) ;
return V_3 ;
}
static void
F_8 ( T_4 * V_11 , T_1 * V_1 , T_5 * V_12 , T_6 V_13 )
{
T_7 * V_14 ;
T_3 * V_5 ;
T_4 * V_15 ;
T_1 * V_16 ;
V_14 = F_9 ( V_11 ) ;
F_10 ( V_14 ) ;
if ( V_14 -> V_4 -> V_17 != - 1 ) {
V_16 = V_1 ;
V_5 = F_11 ( V_16 ) ;
} else {
V_16 = F_1 ( V_1 , V_14 -> V_4 ) ;
V_5 = F_11 ( V_16 ) ;
V_5 -> V_7 ++ ;
V_5 -> V_9 += V_13 ;
}
V_15 = V_11 -> V_18 ;
if ( V_15 ) {
if( strlen ( F_9 ( V_15 ) -> V_4 -> V_19 ) == 0 && V_11 -> V_18 )
V_15 = V_15 -> V_18 ;
F_8 ( V_15 , V_16 , V_12 , V_13 ) ;
} else {
V_5 -> V_8 ++ ;
V_5 -> V_10 += V_13 ;
}
}
static void
F_12 ( T_8 * V_20 , T_5 * V_12 , T_6 V_13 )
{
T_4 * V_11 ;
V_11 = ( ( T_4 * ) V_20 ) -> V_21 ;
if ( ! V_11 ) {
return;
}
F_8 ( V_11 , V_12 -> V_22 , V_12 , V_13 ) ;
}
static T_9
F_13 ( T_10 * V_23 , T_11 * V_24 , T_12 * V_25 , T_5 * V_12 )
{
T_13 V_26 ;
struct V_27 V_28 ;
T_14 V_29 ;
double V_30 ;
F_14 ( & V_28 ) ;
F_15 ( & V_29 , 1500 ) ;
if ( ! F_16 ( V_23 , V_24 , & V_28 , & V_29 ) )
return FALSE ;
F_17 ( & V_26 , V_23 -> V_31 , TRUE , FALSE ) ;
F_18 ( & V_26 , FALSE ) ;
F_19 ( & V_26 , V_23 -> V_32 , & V_28 , F_20 ( V_24 , & V_29 ) , V_24 , V_25 ) ;
F_12 ( V_26 . V_33 , V_12 , V_24 -> V_13 ) ;
if ( V_24 -> V_34 . V_35 ) {
V_30 = F_21 ( & V_24 -> V_36 ) ;
if ( V_30 < V_12 -> V_37 )
V_12 -> V_37 = V_30 ;
if ( V_30 > V_12 -> V_38 )
V_12 -> V_38 = V_30 ;
}
F_22 ( & V_26 ) ;
F_23 ( & V_28 ) ;
F_24 ( & V_29 ) ;
return TRUE ;
}
T_5 *
F_25 ( T_10 * V_23 )
{
T_5 * V_12 ;
T_15 V_39 ;
T_11 * V_24 ;
T_6 V_40 , V_41 ;
T_16 * V_42 = NULL ;
T_9 V_43 ;
int V_44 ;
float V_45 ;
T_17 V_46 ;
T_18 V_47 [ 100 ] ;
int V_48 ;
int V_49 ;
if ( ! V_23 ) return NULL ;
V_12 = F_5 ( T_5 , 1 ) ;
V_12 -> V_40 = 0 ;
V_12 -> V_41 = 0 ;
V_12 -> V_22 = F_6 ( NULL ) ;
V_12 -> V_37 = 0.0 ;
V_12 -> V_38 = 0.0 ;
V_48 = 0 ;
V_49 = V_23 -> V_44 / V_50 ;
V_44 = 0 ;
V_45 = 0.0f ;
V_43 = FALSE ;
F_26 ( & V_46 ) ;
V_40 = 0 ;
V_41 = 0 ;
for ( V_39 = 1 ; V_39 <= V_23 -> V_44 ; V_39 ++ ) {
V_24 = F_27 ( V_23 -> V_51 , V_39 ) ;
if ( V_42 == NULL )
V_42 = F_28 (
V_23 -> V_52 , L_1 ,
L_2 ,
TRUE , & V_43 , & V_46 , V_45 ) ;
if ( V_44 >= V_48 ) {
F_10 ( V_23 -> V_44 > 0 ) ;
V_45 = ( V_53 ) V_44 / V_23 -> V_44 ;
if ( V_42 != NULL ) {
F_29 ( V_47 , sizeof( V_47 ) ,
L_3 , V_44 , V_23 -> V_44 ) ;
F_30 ( V_42 , V_45 , V_47 ) ;
}
V_48 += V_49 ;
}
if ( V_43 ) {
break;
}
if ( V_24 -> V_34 . V_54 ) {
if ( V_24 -> V_34 . V_35 ) {
if ( V_40 == 0 ) {
double V_30 = F_21 ( & V_24 -> V_36 ) ;
V_12 -> V_37 = V_30 ;
V_12 -> V_38 = V_30 ;
}
}
if ( ! F_13 ( V_23 , V_24 , NULL , V_12 ) ) {
V_43 = TRUE ;
break;
}
V_40 ++ ;
V_41 += V_24 -> V_13 ;
}
V_44 ++ ;
}
if ( V_42 != NULL )
F_31 ( V_42 ) ;
if ( V_43 ) {
F_32 ( V_12 ) ;
return NULL ;
}
V_12 -> V_40 = V_40 ;
V_12 -> V_41 = V_41 ;
return V_12 ;
}
static T_9
F_33 ( T_1 * V_55 , T_19 T_20 V_56 )
{
T_3 * V_5 = ( T_3 * ) V_55 -> T_20 ;
if ( V_5 ) {
F_34 ( V_5 ) ;
}
return FALSE ;
}
void
F_32 ( T_5 * V_12 )
{
if ( V_12 -> V_22 ) {
F_35 ( V_12 -> V_22 , V_57 ,
V_58 , - 1 ,
F_33 , NULL ) ;
F_36 ( V_12 -> V_22 ) ;
}
F_34 ( V_12 ) ;
}
