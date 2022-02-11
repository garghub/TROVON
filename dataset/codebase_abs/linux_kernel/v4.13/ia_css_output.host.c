void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = V_4 -> V_7 ;
}
void
V_3 (
struct V_8 * V_2 ,
const struct V_9 * V_4 ,
unsigned V_5 )
{
unsigned V_10 = V_11 ;
( void ) V_5 ;
F_2 ( & V_2 -> V_12 , V_4 -> V_13 ) ;
V_2 -> V_14 = V_10 / V_2 -> V_12 . V_15 ;
V_2 -> V_16 = V_4 -> V_13 -> V_17 . V_16 ;
V_2 -> V_18 = V_4 -> V_13 != NULL ;
F_3 ( & V_2 -> V_13 , V_4 -> V_13 ) ;
assert ( V_10 % V_2 -> V_12 . V_15 == 0 ) ;
}
void
F_4 (
struct V_8 * V_2 ,
const struct V_19 * V_4 ,
unsigned V_5 )
{
V_3 (
V_2 , ( const struct V_9 * ) V_4 , V_5 ) ;
}
void
F_5 (
struct V_8 * V_2 ,
const struct V_20 * V_4 ,
unsigned V_5 )
{
V_3 (
V_2 , ( const struct V_9 * ) V_4 , V_5 ) ;
}
void
F_6 (
const struct V_21 * V_22 ,
const struct V_23 * V_13 )
{
if ( NULL != V_13 ) {
struct V_9 V_24 =
V_25 ;
V_24 . V_13 = V_13 ;
F_7 ( V_22 , & V_24 ) ;
}
}
void
F_8 (
const struct V_21 * V_22 ,
const struct V_23 * V_13 )
{
if ( NULL != V_13 ) {
struct V_19 V_24 =
V_26 ;
V_24 . V_13 = V_13 ;
F_9 ( V_22 , & V_24 ) ;
}
}
void
F_10 (
const struct V_21 * V_22 ,
const struct V_23 * V_13 )
{
if ( NULL != V_13 ) {
struct V_20 V_24 =
V_27 ;
V_24 . V_13 = V_13 ;
F_11 ( V_22 , & V_24 ) ;
}
}
void
F_12 (
const struct V_1 * V_28 ,
unsigned V_29 )
{
if ( ! V_28 ) return;
F_13 ( V_29 , L_1 ) ;
F_13 ( V_29 , L_2 ,
L_3 , V_28 -> V_6 ) ;
F_13 ( V_29 , L_4 ) ;
F_13 ( V_29 , L_2 ,
L_3 , V_28 -> V_7 ) ;
}
void
F_14 (
const struct V_3 * V_24 ,
unsigned V_29 )
{
F_13 ( V_29 ,
L_5 ,
V_24 -> V_6 ) ;
F_13 ( V_29 ,
L_6 ,
V_24 -> V_7 ) ;
}
