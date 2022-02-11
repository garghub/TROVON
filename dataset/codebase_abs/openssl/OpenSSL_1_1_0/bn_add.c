int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_4 = V_2 -> V_5 , V_6 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_4 ^ V_3 -> V_5 ) {
if ( V_4 ) {
const T_1 * V_7 ;
V_7 = V_2 ;
V_2 = V_3 ;
V_3 = V_7 ;
}
if ( F_3 ( V_2 , V_3 ) < 0 ) {
if ( ! F_4 ( V_1 , V_3 , V_2 ) )
return 0 ;
V_1 -> V_5 = 1 ;
} else {
if ( ! F_4 ( V_1 , V_2 , V_3 ) )
return 0 ;
V_1 -> V_5 = 0 ;
}
return 1 ;
}
V_6 = F_5 ( V_1 , V_2 , V_3 ) ;
V_1 -> V_5 = V_4 ;
F_2 ( V_1 ) ;
return V_6 ;
}
int F_5 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 , V_9 , V_10 ;
const T_2 * V_11 , * V_12 ;
T_2 * V_13 , V_14 , V_15 , V_16 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_17 < V_3 -> V_17 ) {
const T_1 * V_7 ;
V_7 = V_2 ;
V_2 = V_3 ;
V_3 = V_7 ;
}
V_8 = V_2 -> V_17 ;
V_9 = V_3 -> V_17 ;
V_10 = V_8 - V_9 ;
if ( F_6 ( V_1 , V_8 + 1 ) == NULL )
return 0 ;
V_1 -> V_17 = V_8 ;
V_11 = V_2 -> V_18 ;
V_12 = V_3 -> V_18 ;
V_13 = V_1 -> V_18 ;
V_14 = F_7 ( V_13 , V_11 , V_12 , V_9 ) ;
V_13 += V_9 ;
V_11 += V_9 ;
while ( V_10 ) {
V_10 -- ;
V_15 = * ( V_11 ++ ) ;
V_16 = ( V_15 + V_14 ) & V_19 ;
* ( V_13 ++ ) = V_16 ;
V_14 &= ( V_16 == 0 ) ;
}
* V_13 = V_14 ;
V_1 -> V_17 += V_14 ;
V_1 -> V_5 = 0 ;
F_2 ( V_1 ) ;
return 1 ;
}
int F_4 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 , V_9 , V_10 ;
T_2 V_15 , V_16 , V_20 , * V_13 ;
const T_2 * V_11 , * V_12 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
V_8 = V_2 -> V_17 ;
V_9 = V_3 -> V_17 ;
V_10 = V_8 - V_9 ;
if ( V_10 < 0 ) {
F_8 ( V_21 , V_22 ) ;
return 0 ;
}
if ( F_6 ( V_1 , V_8 ) == NULL )
return 0 ;
V_11 = V_2 -> V_18 ;
V_12 = V_3 -> V_18 ;
V_13 = V_1 -> V_18 ;
V_20 = F_9 ( V_13 , V_11 , V_12 , V_9 ) ;
V_11 += V_9 ;
V_13 += V_9 ;
while ( V_10 ) {
V_10 -- ;
V_15 = * ( V_11 ++ ) ;
V_16 = ( V_15 - V_20 ) & V_19 ;
* ( V_13 ++ ) = V_16 ;
V_20 &= ( V_15 == 0 ) ;
}
V_1 -> V_17 = V_8 ;
V_1 -> V_5 = 0 ;
F_10 ( V_1 ) ;
return 1 ;
}
int F_11 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 ;
int V_23 = 0 , V_5 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_5 ) {
if ( V_3 -> V_5 ) {
const T_1 * V_7 ;
V_7 = V_2 ;
V_2 = V_3 ;
V_3 = V_7 ;
} else {
V_23 = 1 ;
V_5 = 1 ;
}
} else {
if ( V_3 -> V_5 ) {
V_23 = 1 ;
V_5 = 0 ;
}
}
if ( V_23 ) {
if ( ! F_5 ( V_1 , V_2 , V_3 ) )
return 0 ;
V_1 -> V_5 = V_5 ;
return 1 ;
}
V_8 = ( V_2 -> V_17 > V_3 -> V_17 ) ? V_2 -> V_17 : V_3 -> V_17 ;
if ( F_6 ( V_1 , V_8 ) == NULL )
return 0 ;
if ( F_3 ( V_2 , V_3 ) < 0 ) {
if ( ! F_4 ( V_1 , V_3 , V_2 ) )
return 0 ;
V_1 -> V_5 = 1 ;
} else {
if ( ! F_4 ( V_1 , V_2 , V_3 ) )
return 0 ;
V_1 -> V_5 = 0 ;
}
F_2 ( V_1 ) ;
return 1 ;
}
