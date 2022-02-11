static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_7 ] . V_5 ;
struct V_8 * V_9 = F_2 ( V_5 -> V_10 , struct V_8 , V_11 ) ;
T_2 * V_12 = V_9 -> V_13 [ 0 ] -> V_12 ;
V_12 [ 0 ] = 0x40 ;
V_12 [ 1 ] = V_3 & 0xFF ;
V_12 [ 2 ] = V_3 >> 8 ;
V_12 [ 3 ] = 0x00 ;
V_12 [ 4 ] = 0x00 ;
V_12 [ 5 ] = 0x00 ;
V_12 [ 6 ] = 0x00 ;
V_12 [ 7 ] = 0x00 ;
V_12 [ 8 ] = 0x00 ;
V_12 [ 9 ] = 0x00 ;
V_12 [ 10 ] = 0x00 ;
V_12 [ 11 ] = 0x00 ;
V_12 [ 12 ] = 0x00 ;
V_12 [ 13 ] = 0x00 ;
V_12 [ 14 ] = 0x00 ;
V_12 [ 15 ] = 0x00 ;
F_3 ( V_2 , V_9 , V_14 ) ;
}
static void F_4 ( struct V_15 * V_16 ,
enum V_17 V_12 )
{
struct V_18 * V_19 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_21 = F_5 ( V_19 , struct V_1 , V_19 ) ;
struct V_22 * V_23 = F_6 ( V_21 ) ;
if ( ! V_23 ) {
F_7 ( V_21 , L_1 ) ;
return;
}
if ( V_12 == V_24 )
V_23 -> V_25 = 0 ;
else
V_23 -> V_25 = ( 1 << ( V_26 + 1 ) ) - 1 ;
F_1 ( V_21 , V_23 -> V_25 ) ;
}
static enum V_17 F_8 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_21 = F_5 ( V_19 , struct V_1 , V_19 ) ;
struct V_22 * V_23 ;
V_23 = F_6 ( V_21 ) ;
if ( ! V_23 ) {
F_7 ( V_21 , L_1 ) ;
return V_24 ;
}
return ( V_23 -> V_25 >> V_26 ) ? V_27 : V_24 ;
}
static void F_9 ( struct V_15 * V_16 ,
enum V_17 V_12 )
{
struct V_18 * V_19 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_21 = F_5 ( V_19 , struct V_1 , V_19 ) ;
struct V_22 * V_23 = F_6 ( V_21 ) ;
int V_28 , V_29 = 0 ;
if ( ! V_23 ) {
F_7 ( V_21 , L_1 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
if ( V_16 != V_23 -> V_30 [ V_28 ] )
continue;
V_29 = ( V_23 -> V_25 >> V_28 ) & 1 ;
if ( V_12 == V_24 && V_29 ) {
V_23 -> V_25 &= ~ ( 1 << V_28 ) ;
F_1 ( V_21 , V_23 -> V_25 ) ;
} else if ( V_12 != V_24 && ! V_29 ) {
V_23 -> V_25 |= 1 << V_28 ;
F_1 ( V_21 , V_23 -> V_25 ) ;
}
break;
}
}
static enum V_17 F_10 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_21 = F_5 ( V_19 , struct V_1 , V_19 ) ;
struct V_22 * V_23 ;
int V_28 , V_12 = 0 ;
V_23 = F_6 ( V_21 ) ;
if ( ! V_23 ) {
F_7 ( V_21 , L_1 ) ;
return V_24 ;
}
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ )
if ( V_16 == V_23 -> V_30 [ V_28 ] ) {
V_12 = ( V_23 -> V_25 >> V_28 ) & 1 ;
break;
}
return V_12 ? V_27 : V_24 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
int V_33 , V_28 ;
struct V_15 * V_30 ;
T_3 V_34 ;
char * V_35 ;
struct V_22 * V_23 = F_12 ( sizeof( * V_23 ) , V_36 ) ;
if ( V_23 == NULL ) {
F_7 ( V_2 , L_2 ) ;
return - V_37 ;
}
F_13 ( V_2 , V_23 ) ;
V_33 = F_14 ( V_2 ) ;
if ( V_33 ) {
F_7 ( V_2 , L_3 ) ;
goto V_38;
}
V_33 = F_15 ( V_2 , V_39 ) ;
if ( V_33 ) {
F_7 ( V_2 , L_4 ) ;
goto V_38;
}
V_23 -> V_25 = 0 ;
for ( V_28 = 0 ; V_28 < V_26 + 1 ; V_28 ++ )
V_23 -> V_30 [ V_28 ] = NULL ;
F_1 ( V_2 , 0 ) ;
V_34 = strlen ( V_2 -> V_40 ) + 16 ;
V_30 = F_12 ( sizeof( struct V_15 ) + V_34 , V_36 ) ;
if ( ! V_30 ) {
F_7 ( V_2 , L_5 ) ;
goto V_41;
}
V_35 = ( void * ) ( & V_30 [ 1 ] ) ;
snprintf ( V_35 , V_34 , L_6 , V_2 -> V_40 ) ;
V_30 -> V_35 = V_35 ;
V_30 -> V_42 = 0 ;
V_30 -> V_43 = 1 ;
V_30 -> V_44 = F_8 ;
V_30 -> V_45 = F_4 ;
V_23 -> V_30 [ V_26 ] = V_30 ;
V_33 = F_16 ( & V_2 -> V_19 , V_30 ) ;
if ( V_33 )
goto V_41;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_30 = F_12 ( sizeof( struct V_15 ) + V_34 , V_36 ) ;
if ( ! V_30 ) {
F_7 ( V_2 , L_7 , V_28 ) ;
goto V_41;
}
V_35 = ( void * ) ( & V_30 [ 1 ] ) ;
snprintf ( V_35 , V_34 , L_8 , V_2 -> V_40 , V_28 + 1 ) ;
V_30 -> V_35 = V_35 ;
V_30 -> V_42 = 0 ;
V_30 -> V_43 = 1 ;
V_30 -> V_44 = F_10 ;
V_30 -> V_45 = F_9 ;
V_23 -> V_30 [ V_28 ] = V_30 ;
V_33 = F_16 ( & V_2 -> V_19 , V_30 ) ;
if ( V_33 ) {
F_7 ( V_2 , L_9 , V_28 ) ;
V_41:
for ( V_28 = 0 ; V_28 < V_26 + 1 ; V_28 ++ ) {
V_30 = V_23 -> V_30 [ V_28 ] ;
V_23 -> V_30 [ V_28 ] = NULL ;
if ( ! V_30 )
continue;
F_17 ( V_30 ) ;
F_18 ( V_30 ) ;
}
goto V_46;
}
}
V_46:
return 0 ;
V_38:
F_18 ( V_23 ) ;
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_15 * V_30 ;
struct V_22 * V_23 = F_6 ( V_2 ) ;
if ( V_23 ) {
for ( V_28 = 0 ; V_28 < V_26 + 1 ; V_28 ++ ) {
V_30 = V_23 -> V_30 [ V_28 ] ;
V_23 -> V_30 [ V_28 ] = NULL ;
if ( ! V_30 )
continue;
F_17 ( V_30 ) ;
F_18 ( V_30 ) ;
}
}
F_20 ( V_2 ) ;
F_18 ( V_23 ) ;
return;
}
static T_4 * F_21 ( struct V_1 * V_2 , T_4 * V_47 ,
unsigned int * V_48 )
{
if ( * V_48 >= 115 && V_47 [ 11 ] == 0x02 && V_47 [ 13 ] == 0xc8
&& V_47 [ 29 ] == 0xbb && V_47 [ 40 ] == 0xc5 ) {
F_22 ( V_2 , L_10 ) ;
V_47 = V_49 ;
* V_48 = sizeof( V_49 ) ;
}
return V_47 ;
}
static int T_5 F_23 ( void )
{
return F_24 ( & V_50 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_50 ) ;
}
