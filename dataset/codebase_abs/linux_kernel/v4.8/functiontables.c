static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 ,
void * V_6 ,
void * V_7 )
{
int V_8 = 0 ;
T_1 * V_9 ;
if ( V_4 -> V_10 == NULL ) {
F_2 ( V_11 L_1 ) ;
return 0 ;
}
for ( V_9 = V_4 -> V_10 ; NULL != * V_9 ; V_9 ++ ) {
int V_12 = (* V_9)( V_2 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_12 == V_13 )
break;
if ( V_12 ) {
if ( 0 == V_8 )
V_8 = V_12 ;
if ( V_4 -> V_14 )
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
F_2 ( V_15 L_2 ) ;
return - V_16 ;
}
if ( 0 != V_4 -> V_17 ) {
V_7 = F_4 ( V_4 -> V_17 , V_18 ) ;
if ( V_7 == NULL ) {
F_2 ( V_15 L_3 ) ;
return - V_19 ;
}
} else {
V_7 = NULL ;
}
V_8 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
F_5 ( V_7 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
struct V_3 * V_4 )
{
T_2 V_22 = 0 ;
const struct V_23 * V_24 ;
T_2 V_25 ;
T_1 * V_26 ;
T_1 * V_27 ;
if ( V_2 == NULL || V_21 == NULL || V_4 == NULL ) {
F_2 ( V_15 L_2 ) ;
return - V_16 ;
}
for ( V_24 = V_21 -> V_28 ;
NULL != V_24 -> V_29 ; V_24 ++ ) {
if ( ( NULL == V_24 -> V_30 ) ||
( V_24 -> V_30 ( V_2 ) ) )
V_22 ++ ;
}
V_25 = ( V_22 + 1 ) * sizeof( T_1 ) ;
V_26 = F_4 ( V_25 , V_18 ) ;
if ( NULL == V_26 )
return - V_19 ;
V_27 = V_26 ;
for ( V_24 = V_21 -> V_28 ;
NULL != V_24 -> V_29 ; V_24 ++ ) {
if ( ( V_27 - V_26 ) > V_22 ) {
F_2 ( V_15 L_4 ) ;
F_5 ( V_26 ) ;
return - V_16 ;
}
if ( ( NULL == V_24 -> V_30 ) ||
( V_24 -> V_30 ( V_2 ) ) ) {
* ( V_27 ++ ) = V_24 -> V_29 ;
}
}
if ( ( V_27 - V_26 ) > V_22 ) {
F_2 ( V_15 L_4 ) ;
F_5 ( V_26 ) ;
return - V_16 ;
}
* V_27 = NULL ;
V_4 -> V_10 = V_26 ;
V_4 -> V_14 = ( 0 != ( V_21 -> V_31 & V_32 ) ) ;
V_4 -> V_17 = V_21 -> V_17 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 == NULL || V_4 == NULL ) {
F_2 ( V_15 L_5 ) ;
return - V_16 ;
}
if ( NULL == V_4 -> V_10 )
return 0 ;
F_5 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
V_4 -> V_17 = 0 ;
V_4 -> V_14 = false ;
return 0 ;
}
