void F_1 ( struct V_1 * V_2 , int V_3 , ... )
{
T_1 args ;
int V_4 , V_5 ;
int V_6 = 0 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_7 ;
if ( F_2 ( V_2 -> V_8 & V_9 ) ) {
va_start ( args , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
* ( ( ( V_10 * ) V_7 ) + V_4 ) = ( V_10 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_3 ( V_9 , V_2 ,
V_2 -> V_11 -> V_12 , V_10 , V_7 , V_3 , L_1 , V_13 ) ;
}
if ( V_3 <= 0 )
return;
if ( V_2 -> V_14 && ( V_2 -> V_14 -> V_15 == 8 ) ) {
V_6 = ( V_3 % 4 ) ? 4 - ( V_3 % 4 ) : 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
* V_7 ++ = 0x000 ;
}
va_start ( args , V_3 ) ;
* V_7 ++ = ( V_10 ) va_arg (args, unsigned int) ;
V_4 = V_3 - 1 ;
while ( V_4 -- ) {
* V_7 = ( V_10 ) va_arg (args, unsigned int) ;
* V_7 ++ |= 0x100 ;
}
va_end ( args ) ;
V_5 = V_2 -> V_16 . V_17 ( V_2 , V_2 -> V_7 , ( V_3 + V_6 ) * sizeof( T_2 ) ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_11 -> V_12 ,
L_2 , V_5 ) ;
return;
}
}
int F_5 ( struct V_1 * V_2 , T_3 V_18 , T_3 V_3 )
{
T_2 * V_19 ;
T_2 * V_20 = ( T_2 * ) V_2 -> V_21 . V_7 ;
T_3 V_22 ;
T_3 V_23 ;
T_3 V_24 ;
int V_4 ;
int V_5 = 0 ;
T_3 V_25 = 0 ;
F_6 ( V_26 , V_2 , L_3 ,
V_13 , V_18 , V_3 ) ;
V_22 = V_3 / 2 ;
V_19 = ( T_2 * ) ( V_2 -> V_11 -> V_27 + V_18 ) ;
if ( V_2 -> V_28 . V_29 != - 1 )
F_7 ( V_2 -> V_28 . V_29 , 1 ) ;
if ( ! V_2 -> V_21 . V_7 )
return V_2 -> V_16 . V_17 ( V_2 , V_19 , V_3 ) ;
V_24 = V_2 -> V_21 . V_3 / 2 ;
if ( V_2 -> V_30 ) {
V_20 = ( T_2 * ) ( V_2 -> V_21 . V_7 + 1 ) ;
V_24 -= 2 ;
* ( V_10 * ) ( V_2 -> V_21 . V_7 ) = V_2 -> V_30 | 0x2 ;
V_25 = 1 ;
}
while ( V_22 ) {
V_23 = V_22 > V_24 ? V_24 : V_22 ;
F_8 ( V_2 -> V_11 -> V_12 , L_4 ,
V_23 , V_22 - V_23 ) ;
for ( V_4 = 0 ; V_4 < V_23 ; V_4 ++ )
V_20 [ V_4 ] = F_9 ( V_19 [ V_4 ] ) ;
V_19 = V_19 + V_23 ;
V_5 = V_2 -> V_16 . V_17 ( V_2 , V_2 -> V_21 . V_7 ,
V_25 + V_23 * 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_22 -= V_23 ;
}
return V_5 ;
}
int F_10 ( struct V_1 * V_2 , T_3 V_18 , T_3 V_3 )
{
V_10 T_4 * V_31 ;
T_2 * V_20 = V_2 -> V_21 . V_7 ;
T_3 V_22 ;
T_3 V_23 ;
T_3 V_24 ;
int V_4 ;
int V_5 = 0 ;
F_6 ( V_26 , V_2 , L_3 ,
V_13 , V_18 , V_3 ) ;
if ( ! V_2 -> V_21 . V_7 ) {
F_4 ( V_2 -> V_11 -> V_12 , L_5 , V_13 ) ;
return - 1 ;
}
V_22 = V_3 ;
V_31 = V_2 -> V_11 -> V_27 + V_18 ;
V_24 = V_2 -> V_21 . V_3 / 2 ;
while ( V_22 ) {
V_23 = V_22 > V_24 ? V_24 : V_22 ;
F_8 ( V_2 -> V_11 -> V_12 , L_4 ,
V_23 , V_22 - V_23 ) ;
#ifdef F_11
for ( V_4 = 0 ; V_4 < V_23 ; V_4 += 2 ) {
V_20 [ V_4 ] = 0x0100 | F_12 ( V_31 + V_4 + 1 ) ;
V_20 [ V_4 + 1 ] = 0x0100 | F_12 ( V_31 + V_4 ) ;
}
#else
for ( V_4 = 0 ; V_4 < V_23 ; V_4 ++ )
V_20 [ V_4 ] = 0x0100 | F_12 ( V_31 + V_4 ) ;
#endif
V_31 = V_31 + V_23 ;
V_5 = V_2 -> V_16 . V_17 ( V_2 , V_2 -> V_21 . V_7 , V_23 * 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_22 -= V_23 ;
}
return V_5 ;
}
int F_13 ( struct V_1 * V_2 , T_3 V_18 , T_3 V_3 )
{
F_4 ( V_2 -> V_11 -> V_12 , L_6 , V_13 ) ;
return - 1 ;
}
int F_14 ( struct V_1 * V_2 , T_3 V_18 , T_3 V_3 )
{
T_2 * V_19 ;
F_6 ( V_26 , V_2 , L_3 ,
V_13 , V_18 , V_3 ) ;
V_19 = ( T_2 * ) ( V_2 -> V_11 -> V_27 + V_18 ) ;
if ( V_2 -> V_28 . V_29 != - 1 )
F_7 ( V_2 -> V_28 . V_29 , 1 ) ;
return V_2 -> V_16 . V_17 ( V_2 , V_19 , V_3 ) ;
}
