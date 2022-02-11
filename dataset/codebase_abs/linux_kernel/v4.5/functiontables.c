static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 ,
void * V_6 ,
void * V_7 )
{
int V_8 = 0 ;
T_1 * V_9 ;
for ( V_9 = V_4 -> V_10 ; NULL != * V_9 ; V_9 ++ ) {
int V_11 = (* V_9)( V_2 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_11 == V_12 )
break;
if ( V_11 ) {
if ( 0 == V_8 )
V_8 = V_11 ;
if ( V_4 -> V_13 )
break;
}
}
return V_8 ;
}
int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 , void * V_6 )
{
int V_8 = 0 ;
void * V_7 = NULL ;
if ( V_2 == NULL || V_4 == NULL || V_4 -> V_10 == NULL ) {
F_3 ( V_14 L_1 ) ;
return 0 ;
}
if ( 0 != V_4 -> V_15 ) {
V_7 = F_4 ( V_4 -> V_15 , V_16 ) ;
if ( V_7 == NULL ) {
F_3 ( V_14 L_2 ) ;
return - V_17 ;
}
}
V_8 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
if ( NULL != V_7 )
F_5 ( V_7 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 )
{
T_2 V_20 = 0 ;
const struct V_21 * V_22 ;
T_2 V_23 ;
T_1 * V_24 ;
T_1 * V_25 ;
if ( V_2 == NULL || V_19 == NULL || V_4 == NULL ) {
F_3 ( V_14 L_1 ) ;
return - V_26 ;
}
for ( V_22 = V_19 -> V_27 ;
NULL != V_22 -> V_28 ; V_22 ++ ) {
if ( ( NULL == V_22 -> V_29 ) ||
( V_22 -> V_29 ( V_2 ) ) )
V_20 ++ ;
}
V_23 = ( V_20 + 1 ) * sizeof( T_1 ) ;
V_24 = F_4 ( V_23 , V_16 ) ;
if ( NULL == V_24 )
return - V_17 ;
V_25 = V_24 ;
for ( V_22 = V_19 -> V_27 ;
NULL != V_22 -> V_28 ; V_22 ++ ) {
if ( ( V_25 - V_24 ) > V_20 ) {
F_3 ( V_14 L_3 ) ;
F_5 ( V_24 ) ;
return - V_26 ;
}
if ( ( NULL == V_22 -> V_29 ) ||
( V_22 -> V_29 ( V_2 ) ) ) {
* ( V_25 ++ ) = V_22 -> V_28 ;
}
}
if ( ( V_25 - V_24 ) > V_20 ) {
F_3 ( V_14 L_3 ) ;
F_5 ( V_24 ) ;
return - V_26 ;
}
* V_25 = NULL ;
V_4 -> V_10 = V_24 ;
V_4 -> V_13 = ( 0 != ( V_19 -> V_30 & V_31 ) ) ;
V_4 -> V_15 = V_19 -> V_15 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 == NULL || V_4 == NULL ) {
F_3 ( V_14 L_4 ) ;
return - V_26 ;
}
if ( NULL == V_4 -> V_10 )
return 0 ;
F_5 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
V_4 -> V_15 = 0 ;
V_4 -> V_13 = false ;
return 0 ;
}
