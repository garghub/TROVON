static int
F_1 ( T_1 * V_1 )
{
T_2 * * * V_2 = NULL ;
T_2 * * V_3 ;
int V_4 = V_1 -> V_5 ;
F_2 ( ( V_1 -> V_5 & V_6 ) == 0 ) ;
if ( V_4 == 0 ) {
F_3 ( V_1 -> V_7 , V_1 ) ;
if ( V_1 -> V_7 == NULL )
return - V_8 ;
goto V_9;
}
V_4 -= V_10 ;
if ( V_4 < V_10 * V_10 ) {
F_3 ( V_3 , V_1 ) ;
if ( V_3 == NULL )
return - V_8 ;
if ( V_4 == 0 ) {
F_3 ( V_1 -> V_11 , V_1 ) ;
if ( V_1 -> V_11 == NULL ) {
F_4 ( V_3 ) ;
return - V_8 ;
}
}
V_1 -> V_11 [ V_4 >> V_12 ] = V_3 ;
goto V_9;
}
V_4 -= V_10 * V_10 ;
#if ( V_12 * 3 < 32 )
if ( V_4 >= V_10 * V_10 * V_10 ) {
return - V_8 ;
}
#endif
F_3 ( V_3 , V_1 ) ;
if ( V_3 == NULL )
return - V_8 ;
if ( ( ( V_4 >> V_12 ) & V_6 ) == 0 ) {
F_3 ( V_2 , V_1 ) ;
if ( V_2 == NULL ) {
F_4 ( V_3 ) ;
return - V_8 ;
}
}
if ( V_4 == 0 ) {
F_3 ( V_1 -> V_13 , V_1 ) ;
if ( V_1 -> V_13 == NULL ) {
F_4 ( V_3 ) ;
F_4 ( V_2 ) ;
return - V_8 ;
}
}
if ( V_2 != NULL ) {
F_2 ( V_1 -> V_13 [ V_4 >> ( 2 * V_12 ) ] == NULL ) ;
V_1 -> V_13 [ V_4 >> ( 2 * V_12 ) ] = V_2 ;
} else {
V_2 = V_1 -> V_13 [ V_4 >> ( 2 * V_12 ) ] ;
F_2 ( V_2 != NULL ) ;
}
V_2 [ ( V_4 >> V_12 ) & V_6 ] = V_3 ;
V_9:
V_1 -> V_5 += V_10 ;
return 0 ;
}
T_1 *
F_5 ( T_3 * V_14 , unsigned int V_15 ,
unsigned V_16 , void * V_17 , struct V_18 * V_19 ,
int V_20 )
{
T_1 * V_1 ;
F_2 ( V_14 != NULL ) ;
F_2 ( V_14 -> V_21 != NULL ) ;
F_2 ( V_19 != NULL ) ;
F_2 ( V_20 == V_22 ||
( V_20 >= 0 && V_20 < V_19 -> V_23 ) ) ;
F_6 ( V_1 , V_19 , V_20 , sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_24 = V_14 ;
V_1 -> V_25 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_26 = V_17 ;
V_1 -> V_27 = V_15 & ( ~ V_28 ) ;
V_1 -> V_29 = V_19 ;
V_1 -> V_30 = V_20 ;
while ( V_1 -> V_5 < V_16 ) {
if ( F_1 ( V_1 ) != 0 ) {
F_7 ( V_1 ) ;
return NULL ;
}
}
V_1 -> V_27 |= V_15 & V_28 ;
return V_1 ;
}
void
F_7 ( T_1 * V_1 )
{
int V_31 ;
int V_32 ;
int V_33 ;
F_2 ( V_1 != NULL ) ;
V_33 = V_1 -> V_5 ;
if ( V_33 > 0 ) {
F_4 ( V_1 -> V_7 ) ;
V_33 -= V_10 ;
}
if ( V_33 > 0 ) {
for ( V_31 = 0 ; V_31 < V_10 && V_33 > 0 ; V_31 ++ ) {
F_4 ( V_1 -> V_11 [ V_31 ] ) ;
V_33 -= V_10 ;
}
F_4 ( V_1 -> V_11 ) ;
}
if ( V_33 > 0 ) {
for ( V_31 = 0 ; V_31 < V_10 && V_33 > 0 ; V_31 ++ ) {
for ( V_32 = 0 ; V_32 < V_10 && V_33 > 0 ; V_32 ++ ) {
F_4 ( V_1 -> V_13 [ V_31 ] [ V_32 ] ) ;
V_33 -= V_10 ;
}
F_4 ( V_1 -> V_13 [ V_31 ] ) ;
}
F_4 ( V_1 -> V_13 ) ;
}
F_8 ( V_1 , sizeof( * V_1 ) ) ;
}
static T_2 * *
F_9 ( T_1 * V_1 , unsigned int V_34 )
{
if ( V_34 < V_10 )
return & ( V_1 -> V_7 [ V_34 ] ) ;
V_34 -= V_10 ;
if ( V_34 < V_10 * V_10 )
return & ( V_1 -> V_11 [ V_34 >> V_12 ] [ V_34 & V_6 ] ) ;
V_34 -= V_10 * V_10 ;
return & ( V_1 -> V_13 [ V_34 >> ( 2 * V_12 ) ]\
[ ( V_34 >> V_12 ) & V_6 ]\
[ V_34 & V_6 ] ) ;
}
T_2 *
F_10 ( T_1 * V_1 , unsigned int V_34 )
{
if ( V_34 >= V_1 -> V_25 )
return NULL ;
return * F_9 ( V_1 , V_34 ) ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_35 )
{
unsigned int V_36 = V_35 -> V_37 ;
T_2 * * V_38 ;
unsigned int V_39 ;
T_2 * * V_40 ;
int V_41 = 0 ;
V_38 = F_9 ( V_1 , V_36 ) ;
F_2 ( * V_38 == V_35 ) ;
while ( V_36 > 0 ) {
V_39 = ( V_36 - 1 ) >> 1 ;
V_40 = F_9 ( V_1 , V_39 ) ;
F_2 ( ( * V_40 ) -> V_37 == V_39 ) ;
if ( V_1 -> V_24 -> V_21 ( * V_40 , V_35 ) )
break;
( * V_40 ) -> V_37 = V_36 ;
* V_38 = * V_40 ;
V_38 = V_40 ;
V_36 = V_39 ;
V_41 = 1 ;
}
V_35 -> V_37 = V_36 ;
* V_38 = V_35 ;
return V_41 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_35 )
{
unsigned int V_33 = V_1 -> V_25 ;
unsigned int V_42 ;
T_2 * * V_43 ;
T_2 * V_44 ;
unsigned int V_45 ;
T_2 * * V_46 ;
T_2 * V_47 ;
unsigned int V_36 ;
T_2 * * V_38 ;
int V_41 = 0 ;
V_36 = V_35 -> V_37 ;
V_38 = F_9 ( V_1 , V_36 ) ;
F_2 ( * V_38 == V_35 ) ;
while ( V_36 < V_33 ) {
V_42 = ( V_36 << 1 ) + 1 ;
if ( V_42 >= V_33 )
break;
V_43 = F_9 ( V_1 , V_42 ) ;
V_44 = * V_43 ;
V_45 = V_42 + 1 ;
if ( V_45 < V_33 ) {
V_46 = F_9 ( V_1 , V_45 ) ;
V_47 = * V_46 ;
if ( V_1 -> V_24 -> V_21 ( V_47 , V_44 ) ) {
V_42 = V_45 ;
V_43 = V_46 ;
V_44 = V_47 ;
}
}
F_2 ( V_44 -> V_37 == V_42 ) ;
if ( V_1 -> V_24 -> V_21 ( V_35 , V_44 ) )
break;
V_44 -> V_37 = V_36 ;
* V_38 = V_44 ;
V_38 = V_43 ;
V_36 = V_42 ;
V_41 = 1 ;
}
V_35 -> V_37 = V_36 ;
* V_38 = V_35 ;
return V_41 ;
}
int
F_13 ( T_1 * V_1 , T_2 * V_35 )
{
T_2 * * V_48 ;
unsigned int V_49 = V_1 -> V_25 ;
int V_50 ;
if ( V_49 == V_1 -> V_5 ) {
V_50 = F_1 ( V_1 ) ;
if ( V_50 != 0 )
return V_50 ;
}
if ( V_1 -> V_24 -> V_51 ) {
V_50 = V_1 -> V_24 -> V_51 ( V_1 , V_35 ) ;
if ( V_50 != 0 )
return V_50 ;
}
V_35 -> V_37 = V_49 ;
V_48 = F_9 ( V_1 , V_49 ) ;
V_1 -> V_25 ++ ;
* V_48 = V_35 ;
F_11 ( V_1 , V_35 ) ;
return 0 ;
}
void
F_14 ( T_1 * V_1 , T_2 * V_35 )
{
unsigned int V_33 = V_1 -> V_25 ;
unsigned int V_36 = V_35 -> V_37 ;
T_2 * * V_38 ;
T_2 * V_52 ;
F_2 ( V_36 != V_53 ) ;
F_2 ( V_36 < V_33 ) ;
V_38 = F_9 ( V_1 , V_36 ) ;
F_2 ( * V_38 == V_35 ) ;
V_33 -- ;
V_52 = * F_9 ( V_1 , V_33 ) ;
V_1 -> V_25 = V_33 ;
if ( V_52 == V_35 )
return;
V_52 -> V_37 = V_36 ;
* V_38 = V_52 ;
if ( ! F_11 ( V_1 , * V_38 ) )
F_12 ( V_1 , * V_38 ) ;
V_35 -> V_37 = V_53 ;
if ( V_1 -> V_24 -> V_54 )
V_1 -> V_24 -> V_54 ( V_1 , V_35 ) ;
}
