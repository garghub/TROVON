void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
unsigned V_6 = V_7 ;
( void ) V_5 ;
V_2 -> V_8 = V_4 -> V_8 ;
V_2 -> V_9 = V_4 -> V_10 != NULL ;
if ( V_4 -> V_10 ) {
F_2 ( & V_2 -> V_10 , V_4 -> V_10 ) ;
F_3 ( & V_2 -> V_11 . V_12 , V_4 -> V_10 ) ;
V_2 -> V_11 . V_13 = V_6 / V_2 -> V_11 . V_12 . V_14 ;
assert ( V_6 % V_2 -> V_11 . V_12 . V_14 == 0 ) ;
}
}
enum V_15
F_4 (
const struct V_16 * V_17 ,
const struct V_16 * V_18 ,
unsigned int * V_19 )
{
unsigned int V_20 = 0 ;
unsigned int V_21 ;
if ( ( V_17 == NULL ) | ( V_18 == NULL ) )
return V_22 ;
V_21 = V_17 -> V_23 . V_24 ;
if ( V_21 == 0 )
return V_22 ;
while ( V_21 >= V_18 -> V_23 . V_24 ) {
V_20 ++ ;
V_21 /= 2 ;
}
if ( ( V_20 > 0 ) && ( V_21 < F_5 () ) )
V_20 -- ;
if ( ( V_17 -> V_23 . V_24 >> V_20 ) >= 2 * F_5 () )
return V_22 ;
* V_19 = V_20 ;
return V_25 ;
}
static enum V_15
F_6 (
const struct V_26 * V_10 ,
const struct V_16 * V_17 ,
const struct V_16 * V_18 ,
unsigned int * V_19 ,
struct V_3 * V_27 )
{
enum V_15 V_28 ;
unsigned V_29 = 0 ;
if ( V_18 ) {
V_28 = F_4 ( V_17 , V_18 , & V_29 ) ;
if ( V_28 != V_25 )
return V_28 ;
}
V_29 = F_7 ( V_29 , V_10 -> V_30 . V_31 ) ;
* V_19 = V_29 ;
V_27 -> V_8 = V_29 ;
return V_25 ;
}
static void
F_8 (
struct V_3 * V_27 ,
const struct V_16 * V_18 )
{
V_27 -> V_10 = V_18 ;
}
enum V_15
F_9 (
const struct V_32 * V_33 ,
const struct V_16 * V_17 ,
struct V_16 * V_18 ,
unsigned int * V_19 )
{
enum V_15 V_28 ;
struct V_3 V_27 ;
const struct V_26 * V_10 = & V_33 -> V_10 -> V_34 ;
V_28 = F_6 ( V_10 , V_17 , V_18 , V_19 , & V_27 ) ;
F_8 ( & V_27 , V_18 ) ;
if ( V_33 ) {
if ( V_18 )
V_18 -> V_35 = V_10 -> V_11 . V_36 ;
F_10 ( V_33 , & V_27 ) ;
}
return V_25 ;
}
