void
F_1 (
struct V_1 * V_2 ,
struct V_3 * * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 = ( * V_4 ) -> V_7 ;
}
void
F_2 (
const struct V_1 * V_8 ,
unsigned V_9 )
{
if ( ! V_8 ) return;
F_3 ( V_9 , L_1 ) ;
F_3 ( V_9 , L_2 ,
L_3 , V_8 -> V_6 ) ;
}
void
F_4 (
struct V_10 * V_2 ,
const struct V_11 * V_4 ,
unsigned V_5 )
{
T_1 V_12 = V_4 -> V_13 ;
T_1 V_14 = V_4 -> V_15 ;
T_1 V_16 , V_17 , V_18 ;
( void ) V_5 ;
V_17 = V_12 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_16 = F_5 ( V_17 , ( ( T_1 ) V_20 ) ) ;
V_17 = V_17 - V_16 ;
V_2 -> V_21 [ V_18 ] = V_16 ;
}
V_2 -> V_15 = V_14 ;
}
void
F_6 (
const struct V_22 * V_23 ,
T_1 V_13 ,
T_1 V_15 )
{
const struct V_11 V_24 = {
V_13 ,
V_15 } ;
F_7 ( V_23 , & V_24 ) ;
}
void
F_8 ( const struct V_25 * V_26 ,
struct V_27 * V_28 )
{
if ( V_28 == NULL )
return;
assert ( V_26 != NULL ) ;
F_3 ( V_29 ,
L_4 , V_28 ) ;
* V_28 = V_26 -> V_30 ;
F_3 ( V_29 ,
L_5 ,
V_28 -> V_31 ) ;
}
void
F_9 ( struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
if ( V_28 == NULL )
return;
assert ( V_26 != NULL ) ;
F_3 ( V_29 ,
L_6 ,
V_28 -> V_31 ) ;
V_26 -> V_30 = * V_28 ;
V_26 -> V_32 = true ;
F_3 ( V_29 ,
L_7 ) ;
}
