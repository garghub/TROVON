static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 ;
struct V_2 * V_5 ;
if ( strcasecmp ( V_3 -> type , L_1 ) ) {
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
if ( V_7 [ V_4 ] . V_8 == V_3 ||
V_7 [ V_4 ] . V_9 == V_3 )
return & V_7 [ V_4 ] ;
return NULL ;
}
if ( V_3 -> V_10 )
return V_3 -> V_10 ;
V_5 = V_3 ;
do {
V_5 = V_5 -> V_11 ;
F_2 ( ! V_5 ) ;
} while ( strcasecmp ( V_5 -> type , L_2 ) &&
strcasecmp ( V_5 -> type , L_3 ) );
V_3 -> V_10 = F_1 ( V_5 ) ;
return V_3 -> V_10 ;
}
struct V_12 T_1 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( V_13 == NULL )
return NULL ;
return V_13 -> V_14 ;
}
struct V_12 T_1 * F_4 ( int V_15 )
{
struct V_1 * V_13 = V_16 [ V_15 ] . V_17 ;
if ( V_13 == NULL )
return NULL ;
return V_13 -> V_14 ;
}
struct V_18 * F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( V_13 == NULL )
return NULL ;
return & V_13 -> V_19 ;
}
struct V_18 * F_6 ( int V_15 )
{
struct V_1 * V_13 = V_16 [ V_15 ] . V_17 ;
if ( V_13 == NULL )
return NULL ;
return & V_13 -> V_19 ;
}
struct V_20 T_1 * F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( V_13 == NULL )
return NULL ;
return V_13 -> V_21 ;
}
struct V_20 T_1 * F_8 ( int V_15 )
{
struct V_1 * V_13 = V_16 [ V_15 ] . V_17 ;
if ( V_13 == NULL )
return NULL ;
return V_13 -> V_21 ;
}
struct V_22 T_1 * F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( V_13 == NULL )
return NULL ;
return V_13 -> V_23 ;
}
struct V_22 T_1 * F_10 ( int V_15 )
{
struct V_1 * V_13 = V_16 [ V_15 ] . V_17 ;
if ( V_13 == NULL )
return NULL ;
return V_13 -> V_23 ;
}
T_2 F_11 ( int V_15 )
{
return V_16 [ V_15 ] . V_24 ;
}
T_2 F_12 ( int V_15 )
{
return V_16 [ V_15 ] . V_25 ;
}
T_2 F_13 ( int V_26 )
{
return F_14 ( & V_27 [ V_26 ] ) ;
}
static struct V_2 * F_15 ( int V_28 )
{
struct V_2 * V_3 ;
F_16 (np, L_3 ) {
int V_29 , V_4 ;
const T_3 * V_30 ;
V_30 = F_17 ( V_3 , L_4 , & V_29 ) ;
if ( F_18 ( ! V_30 ) )
return V_3 ;
for ( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
if ( F_19 ( V_30 [ V_4 ] ) == F_20 ( V_28 , NULL ) )
return V_3 ;
}
return NULL ;
}
static void T_4 F_21 ( struct V_1 * V_13 )
{
if( V_13 -> V_9 ) {
struct V_2 * V_31 , * V_3 ;
V_31 = V_13 -> V_9 ;
F_16 (np, L_5 )
if ( F_22 ( V_3 ) == V_31 )
V_13 -> V_14 = F_23 ( V_3 , 0 ) ;
F_16 (np, L_6 )
if ( F_22 ( V_3 ) == V_31 )
V_13 -> V_21 = F_23 ( V_3 , 2 ) ;
F_16 (np, L_7 )
if ( F_22 ( V_3 ) == V_31 )
V_13 -> V_23 = F_23 ( V_3 , 0 ) ;
} else {
struct V_2 * V_15 ;
const struct V_32 {
unsigned long V_33 ;
unsigned int V_29 ;
} V_34 ( ( V_35 ) ) * V_36 ;
V_15 = V_13 -> V_8 ;
V_36 = F_17 ( V_15 , L_5 , NULL ) ;
if ( V_36 != NULL )
V_13 -> V_14 = F_24 ( V_36 -> V_33 , V_36 -> V_29 ) ;
V_36 = F_17 ( V_15 , L_8 , NULL ) ;
if ( V_36 != NULL )
V_13 -> V_21 = F_24 ( V_36 -> V_33 , V_36 -> V_29 ) ;
V_36 = F_17 ( V_15 , L_7 , NULL ) ;
if ( V_36 != NULL )
V_13 -> V_23 = F_24 ( V_36 -> V_33 , V_36 -> V_29 ) ;
}
}
void T_4 F_25 ( void )
{
int V_4 ;
unsigned int V_24 ;
struct V_2 * V_15 ;
F_26 (i) {
V_16 [ V_4 ] . V_8 = F_20 ( V_4 , & V_24 ) ;
V_16 [ V_4 ] . V_9 = F_15 ( V_4 ) ;
V_16 [ V_4 ] . V_24 = V_24 ;
}
F_16 (cpu, L_2 ) {
struct V_1 * V_13 ;
unsigned int V_25 ;
V_25 = V_6 ++ ;
V_13 = & V_7 [ V_25 ] ;
if ( V_6 > V_37 ) {
F_27 ( V_38 L_9
L_10 ) ;
V_6 -- ;
F_28 ( V_15 ) ;
return;
}
V_13 -> V_8 = V_15 ;
F_26 (i) {
struct V_16 * V_39 = & V_16 [ V_4 ] ;
if ( V_39 -> V_8 == V_15 ) {
V_39 -> V_17 = V_13 ;
V_39 -> V_25 = V_25 ;
V_13 -> V_9 = V_39 -> V_9 ;
F_29 ( V_4 , & V_27 [ V_25 ] ) ;
if( V_39 -> V_24 == 0 )
F_29 ( V_4 , & V_40 ) ;
}
}
F_21 ( V_13 ) ;
}
}
