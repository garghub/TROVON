signed char * F_1 ( const T_1 * V_1 , int V_2 , T_2 * V_3 )
{
int V_4 ;
signed char * V_5 = NULL ;
int V_6 = 1 ;
int V_7 , V_8 , V_9 ;
T_2 V_10 = 0 , V_11 ;
if ( F_2 ( V_1 ) ) {
V_5 = F_3 ( 1 ) ;
if ( V_5 == NULL ) {
F_4 ( V_12 , V_13 ) ;
goto V_14;
}
V_5 [ 0 ] = 0 ;
* V_3 = 1 ;
return V_5 ;
}
if ( V_2 <= 0 || V_2 > 7 ) {
F_4 ( V_12 , V_15 ) ;
goto V_14;
}
V_7 = 1 << V_2 ;
V_8 = V_7 << 1 ;
V_9 = V_8 - 1 ;
if ( F_5 ( V_1 ) ) {
V_6 = - 1 ;
}
if ( V_1 -> V_16 == NULL || V_1 -> V_17 == 0 ) {
F_4 ( V_12 , V_15 ) ;
goto V_14;
}
V_10 = F_6 ( V_1 ) ;
V_5 = F_3 ( V_10 + 1 ) ;
if ( V_5 == NULL ) {
F_4 ( V_12 , V_13 ) ;
goto V_14;
}
V_4 = V_1 -> V_16 [ 0 ] & V_9 ;
V_11 = 0 ;
while ( ( V_4 != 0 ) || ( V_11 + V_2 + 1 < V_10 ) ) {
int V_18 = 0 ;
if ( V_4 & 1 ) {
if ( V_4 & V_7 ) {
V_18 = V_4 - V_8 ;
#if 1
if ( V_11 + V_2 + 1 >= V_10 ) {
V_18 = V_4 & ( V_9 >> 1 ) ;
}
#endif
} else {
V_18 = V_4 ;
}
if ( V_18 <= - V_7 || V_18 >= V_7 || ! ( V_18 & 1 ) ) {
F_4 ( V_12 , V_15 ) ;
goto V_14;
}
V_4 -= V_18 ;
if ( V_4 != 0 && V_4 != V_8
&& V_4 != V_7 ) {
F_4 ( V_12 , V_15 ) ;
goto V_14;
}
}
V_5 [ V_11 ++ ] = V_6 * V_18 ;
V_4 >>= 1 ;
V_4 += V_7 * F_7 ( V_1 , V_11 + V_2 ) ;
if ( V_4 > V_8 ) {
F_4 ( V_12 , V_15 ) ;
goto V_14;
}
}
if ( V_11 > V_10 + 1 ) {
F_4 ( V_12 , V_15 ) ;
goto V_14;
}
* V_3 = V_11 ;
return V_5 ;
V_14:
F_8 ( V_5 ) ;
return NULL ;
}
int F_9 ( const T_1 * V_19 )
{
return V_19 -> V_17 ;
}
void F_10 ( T_1 * V_19 , int V_17 )
{
V_19 -> V_17 = V_17 ;
}
int F_11 ( const T_1 * V_19 )
{
return V_19 -> V_20 ;
}
void F_12 ( T_1 * V_19 )
{
int V_21 ;
for ( V_21 = V_19 -> V_17 ; V_21 < V_19 -> V_20 ; V_21 ++ )
V_19 -> V_16 [ V_21 ] = 0 ;
}
int F_13 ( T_3 * V_22 , const T_1 * V_23 , int V_24 )
{
if ( V_23 -> V_17 > V_24 )
return 0 ;
memset ( V_22 , 0 , sizeof( * V_22 ) * V_24 ) ;
memcpy ( V_22 , V_23 -> V_16 , sizeof( * V_22 ) * V_23 -> V_17 ) ;
return 1 ;
}
T_3 * F_14 ( const T_1 * V_19 )
{
return V_19 -> V_16 ;
}
void F_15 ( T_1 * V_19 , T_3 * V_25 , int V_24 )
{
V_19 -> V_16 = V_25 ;
V_19 -> V_20 = V_19 -> V_17 = V_24 ;
V_19 -> V_26 = 0 ;
V_19 -> V_27 |= V_28 ;
F_16 ( V_19 ) ;
}
int F_17 ( T_1 * V_19 , T_3 * V_25 , int V_29 )
{
if ( F_18 ( V_19 , V_29 ) == NULL ) {
F_4 ( V_30 , V_13 ) ;
return 0 ;
}
memcpy ( V_19 -> V_16 , V_25 , sizeof( T_3 ) * V_29 ) ;
V_19 -> V_17 = V_29 ;
F_16 ( V_19 ) ;
return 1 ;
}
T_2 F_19 ( void )
{
return sizeof( T_1 ) ;
}
T_1 * F_20 ( T_1 * V_31 , int V_32 )
{
return & V_31 [ V_32 ] ;
}
