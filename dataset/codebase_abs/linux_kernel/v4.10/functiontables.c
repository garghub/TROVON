static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 ,
void * V_6 ,
void * V_7 )
{
int V_8 = 0 ;
T_1 * V_9 ;
if ( V_4 -> V_10 == NULL ) {
F_2 ( L_1 ) ;
return 0 ;
}
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
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 , void * V_6 )
{
int V_8 ;
void * V_7 ;
if ( V_2 == NULL || V_4 == NULL ) {
F_4 ( V_14 L_2 ) ;
return - V_15 ;
}
if ( 0 != V_4 -> V_16 ) {
V_7 = F_5 ( V_4 -> V_16 , V_17 ) ;
if ( V_7 == NULL ) {
F_4 ( V_14 L_3 ) ;
return - V_18 ;
}
} else {
V_7 = NULL ;
}
V_8 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
F_6 ( V_7 ) ;
return V_8 ;
}
int F_7 ( struct V_1 * V_2 ,
const struct V_19 * V_20 ,
struct V_3 * V_4 )
{
T_2 V_21 = 0 ;
const struct V_22 * V_23 ;
T_2 V_24 ;
T_1 * V_25 ;
T_1 * V_26 ;
if ( V_2 == NULL || V_20 == NULL || V_4 == NULL ) {
F_4 ( V_14 L_2 ) ;
return - V_15 ;
}
for ( V_23 = V_20 -> V_27 ;
NULL != V_23 -> V_28 ; V_23 ++ ) {
if ( ( NULL == V_23 -> V_29 ) ||
( V_23 -> V_29 ( V_2 ) ) )
V_21 ++ ;
}
V_24 = ( V_21 + 1 ) * sizeof( T_1 ) ;
V_25 = F_5 ( V_24 , V_17 ) ;
if ( NULL == V_25 )
return - V_18 ;
V_26 = V_25 ;
for ( V_23 = V_20 -> V_27 ;
NULL != V_23 -> V_28 ; V_23 ++ ) {
if ( ( V_26 - V_25 ) > V_21 ) {
F_4 ( V_14 L_4 ) ;
F_6 ( V_25 ) ;
return - V_15 ;
}
if ( ( NULL == V_23 -> V_29 ) ||
( V_23 -> V_29 ( V_2 ) ) ) {
* ( V_26 ++ ) = V_23 -> V_28 ;
}
}
if ( ( V_26 - V_25 ) > V_21 ) {
F_4 ( V_14 L_4 ) ;
F_6 ( V_25 ) ;
return - V_15 ;
}
* V_26 = NULL ;
V_4 -> V_10 = V_25 ;
V_4 -> V_13 = ( 0 != ( V_20 -> V_30 & V_31 ) ) ;
V_4 -> V_16 = V_20 -> V_16 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 == NULL || V_4 == NULL ) {
F_4 ( V_14 L_5 ) ;
return - V_15 ;
}
if ( NULL == V_4 -> V_10 )
return 0 ;
F_6 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
V_4 -> V_16 = 0 ;
V_4 -> V_13 = false ;
return 0 ;
}
