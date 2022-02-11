static void
F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_4 V_5 ;
T_1 V_6 ;
F_2 ( V_7 ) ;
if ( ! V_2 ) {
F_3 ( ( V_8 , L_1 ) ) ;
V_9 ;
}
V_5 . V_10 = V_11 ;
V_6 = F_4 ( V_2 , & V_5 , TRUE ) ;
if ( F_5 ( V_6 ) ) {
if ( V_3 ) {
F_3 ( ( V_8 , L_2 ,
V_3 ) ) ;
}
F_3 ( ( V_8 , L_3 ,
( char * ) V_5 . V_12 , V_2 ) ) ;
F_6 ( V_5 . V_12 ) ;
}
V_9 ;
}
void
F_7 ( T_1 V_6 ,
struct V_13 * V_14 ,
union V_15 * V_16 )
{
union V_15 * V_17 ;
struct V_18 * V_19 ;
struct V_13 * V_20 ;
struct V_1 * V_21 = NULL ;
union V_22 * V_23 ;
F_2 ( V_24 ) ;
if ( ( V_6 & V_25 ) == V_26 ) {
V_9 ;
}
if ( V_14 -> V_27 ) {
F_8 ( ( V_8 ,
L_4 ) ) ;
V_9 ;
}
V_19 = V_14 -> V_19 ;
if ( ! V_19 ) {
V_9 ;
}
F_8 ( ( V_8 ,
L_5 ,
F_9 ( V_6 ) ) ) ;
F_1 ( V_14 -> V_28 , NULL ) ;
F_3 ( ( V_8 ,
L_6 ) ) ;
V_20 = V_19 -> V_29 ;
while ( V_20 ) {
V_23 = V_20 -> V_23 ;
if ( V_23 ) {
F_10 ( (struct V_1 * )
V_23 -> V_30 . V_2 ,
V_23 , V_14 ) ;
}
F_8 ( ( V_8 ,
L_7 ,
F_11 ( V_20 ->
V_28 ) ) ) ;
if ( V_20 == V_14 ) {
if ( V_16 ) {
V_17 = V_16 -> V_31 . V_17 ;
V_16 -> V_31 . V_17 = NULL ;
#ifdef F_12
F_13 ( L_8 ) ;
F_14 ( V_20 , V_16 ,
V_32 ) ;
#endif
V_16 -> V_31 . V_17 = V_17 ;
}
} else {
F_3 ( ( V_8 ,
L_9 ) ) ;
F_1 ( V_21 , NULL ) ;
}
V_21 = V_20 -> V_28 ;
V_20 = V_20 -> V_17 ;
F_3 ( ( V_8 , L_10 ) ) ;
}
V_9 ;
}
void
F_7 ( T_1 V_6 ,
struct V_13 * V_14 ,
union V_15 * V_16 )
{
return;
}
