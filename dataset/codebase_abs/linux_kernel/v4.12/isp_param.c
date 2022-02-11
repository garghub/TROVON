void
F_1 (
struct V_1 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 ,
char * V_7 , T_1 V_8 )
{
V_2 -> V_9 [ V_4 ] [ V_6 ] . V_7 = V_7 ;
V_2 -> V_9 [ V_4 ] [ V_6 ] . V_8 = ( V_10 ) V_8 ;
}
void
F_2 (
struct V_11 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 ,
T_2 V_7 , T_1 V_8 )
{
V_2 -> V_9 [ V_4 ] [ V_6 ] . V_7 = V_7 ;
V_2 -> V_9 [ V_4 ] [ V_6 ] . V_8 = ( V_10 ) V_8 ;
}
void
F_3 (
struct V_12 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 ,
V_10 V_7 , T_1 V_8 )
{
V_2 -> V_9 [ V_4 ] [ V_6 ] . V_7 = V_7 ;
V_2 -> V_9 [ V_4 ] [ V_6 ] . V_8 = ( V_10 ) V_8 ;
}
const struct V_13 *
F_4 (
const struct V_1 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
return & V_2 -> V_9 [ V_4 ] [ V_6 ] ;
}
const struct V_14 *
F_5 (
const struct V_11 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
return & V_2 -> V_9 [ V_4 ] [ V_6 ] ;
}
const struct V_15 *
F_6 (
const struct V_12 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
return & V_2 -> V_9 [ V_4 ] [ V_6 ] ;
}
void
F_7 (
struct V_11 * V_16 ,
const struct V_1 * V_17 ,
const struct V_11 * V_18 )
{
unsigned V_4 , V_6 ;
for ( V_4 = 0 ; V_4 < V_19 ; V_4 ++ ) {
memset ( V_16 -> V_9 [ V_4 ] , 0 , sizeof( V_16 -> V_9 [ V_4 ] ) ) ;
for ( V_6 = 0 ; V_6 < V_20 ; V_6 ++ ) {
if ( ! V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 )
continue;
V_16 -> V_9 [ V_4 ] [ V_6 ] . V_8 = V_17 -> V_9 [ V_4 ] [ V_6 ] . V_8 ;
if ( V_4 != V_21 )
V_16 -> V_9 [ V_4 ] [ V_6 ] . V_7 = V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 ;
}
}
}
enum V_22
F_8 (
struct V_1 * V_17 ,
struct V_11 * V_18 ,
const struct V_12 * V_23 )
{
enum V_22 V_24 = V_25 ;
unsigned V_6 , V_4 ;
V_4 = V_21 ;
for ( V_6 = 0 ; V_6 < V_20 ; V_6 ++ ) {
for ( V_4 = 0 ; V_4 < V_19 ; V_4 ++ ) {
V_10 V_8 = 0 ;
if ( V_23 )
V_8 = V_23 -> V_9 [ V_4 ] [ V_6 ] . V_8 ;
V_17 -> V_9 [ V_4 ] [ V_6 ] . V_8 = V_8 ;
V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 = NULL ;
V_18 -> V_9 [ V_4 ] [ V_6 ] . V_8 = V_8 ;
V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 = 0x0 ;
if ( V_8 ) {
V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 = F_9 ( 1 , V_8 ) ;
if ( ! V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 ) {
V_24 = V_26 ;
goto V_27;
}
if ( V_4 != V_21 ) {
V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 = F_10 ( V_8 ) ;
if ( ! V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 ) {
V_24 = V_26 ;
goto V_27;
}
}
}
}
}
return V_24 ;
V_27:
F_11 ( V_17 , V_18 ) ;
return V_24 ;
}
void
F_11 (
struct V_1 * V_17 ,
struct V_11 * V_18 )
{
unsigned V_6 , V_4 ;
for ( V_6 = 0 ; V_6 < V_20 ; V_6 ++ ) {
for ( V_4 = 0 ; V_4 < V_19 ; V_4 ++ ) {
if ( V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 )
F_12 ( V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 ) ;
if ( V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 )
F_13 ( V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 ) ;
V_17 -> V_9 [ V_4 ] [ V_6 ] . V_7 = NULL ;
V_18 -> V_9 [ V_4 ] [ V_6 ] . V_7 = 0x0 ;
}
}
}
void
F_14 (
const char * V_28 ,
union V_29 * V_30 ,
const struct V_31 * V_32 ,
bool V_33 )
{
unsigned V_4 ;
for ( V_4 = 0 ; V_4 < V_19 ; V_4 ++ ) {
V_30 -> V_34 [ V_4 ] . V_35 = NULL ;
if ( V_33 )
V_30 -> V_34 [ V_4 ] . V_35 = ( void * ) ( V_28 + V_32 -> V_36 [ V_4 ] ) ;
}
}
enum V_22
F_15 (
struct V_11 * V_37 ,
const struct V_1 * V_38 ,
enum V_3 V_4 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ ) {
T_1 V_8 = V_38 -> V_9 [ V_4 ] [ V_6 ] . V_8 ;
T_2 V_40 = V_37 -> V_9 [ V_4 ] [ V_6 ] . V_7 ;
char * V_41 = V_38 -> V_9 [ V_4 ] [ V_6 ] . V_7 ;
if ( V_8 != V_37 -> V_9 [ V_4 ] [ V_6 ] . V_8 )
return V_42 ;
if ( ! V_8 )
continue;
F_16 ( V_40 , V_41 , V_8 ) ;
}
return V_25 ;
}
void
F_17 (
const struct V_1 * V_17 )
{
short V_43 = 0 ;
if ( V_17 -> V_9 [ V_21 ] [ V_44 ] . V_8 == 0 )
return;
* ( V_10 * ) & V_17 -> V_9 [ V_21 ] [ V_44 ] . V_7 [ V_43 ] = 0x0 ;
}
