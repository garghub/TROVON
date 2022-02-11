static struct V_1 * F_1 ( const T_1 V_2 ,
const T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 = NULL ;
F_2 (q, &dquirks_list, node) {
if ( V_5 -> V_7 . V_2 == V_2 &&
V_5 -> V_7 . V_3 == V_3 ) {
V_6 = & V_5 -> V_7 ;
break;
}
}
if ( V_6 != NULL )
F_3 ( L_1 ,
V_6 -> V_8 , V_6 -> V_2 ,
V_6 -> V_3 ) ;
return V_6 ;
}
static int F_4 ( const T_1 V_2 , const T_1 V_3 ,
const T_2 V_8 )
{
struct V_4 * V_9 , * V_5 ;
int V_10 = 0 ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return - V_11 ;
}
V_9 = F_5 ( sizeof( struct V_4 ) , V_12 ) ;
if ( ! V_9 ) {
F_3 ( L_3 ) ;
return - V_13 ;
}
V_9 -> V_7 . V_2 = V_2 ;
V_9 -> V_7 . V_3 = V_3 ;
V_9 -> V_7 . V_8 = V_8 ;
F_6 ( & V_14 ) ;
F_2 (q, &dquirks_list, node) {
if ( V_5 -> V_7 . V_2 == V_2 &&
V_5 -> V_7 . V_3 == V_3 ) {
F_7 ( & V_5 -> V_15 , & V_9 -> V_15 ) ;
F_8 ( V_5 ) ;
V_10 = 1 ;
break;
}
}
if ( ! V_10 )
F_9 ( & V_9 -> V_15 , & V_16 ) ;
F_10 ( & V_14 ) ;
return 0 ;
}
static void F_11 ( void )
{
struct V_4 * V_5 , * V_17 ;
F_6 ( & V_14 ) ;
F_12 (q, temp, &dquirks_list, node) {
F_13 ( & V_5 -> V_15 ) ;
F_8 ( V_5 ) ;
}
F_10 ( & V_14 ) ;
}
int F_14 ( char * * V_18 )
{
T_1 V_2 , V_3 ;
T_2 V_8 ;
int V_19 = 0 , V_20 ;
for (; V_19 < V_21 && V_18 [ V_19 ] ; V_19 ++ ) {
V_20 = sscanf ( V_18 [ V_19 ] , L_4 ,
& V_2 , & V_3 , & V_8 ) ;
if ( V_20 != 3 ||
F_4 ( V_2 , V_3 , V_8 ) != 0 ) {
F_15 ( V_22
L_5 ,
V_18 [ V_19 ] ) ;
}
}
return 0 ;
}
void F_16 ( void )
{
F_11 () ;
}
static const struct V_1 * F_17 ( const T_1 V_2 ,
const T_1 V_3 )
{
const struct V_1 * V_6 = NULL ;
int V_19 = 0 ;
for (; V_1 [ V_19 ] . V_2 ; V_19 ++ )
if ( V_1 [ V_19 ] . V_2 == V_2 &&
V_1 [ V_19 ] . V_3 == V_3 )
V_6 = & V_1 [ V_19 ] ;
if ( V_6 != NULL )
F_3 ( L_6 ,
V_6 -> V_8 , V_6 -> V_2 ,
V_6 -> V_3 ) ;
return V_6 ;
}
T_2 F_18 ( const T_1 V_2 , const T_1 V_3 )
{
T_2 V_8 = 0 ;
const struct V_1 * V_6 = NULL ;
if ( V_2 == V_23 &&
V_3 >= V_24 &&
V_3 <= V_25 )
return V_26 ;
F_19 ( & V_14 ) ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( ! V_6 )
V_6 = F_17 ( V_2 , V_3 ) ;
if ( V_6 )
V_8 = V_6 -> V_8 ;
F_20 ( & V_14 ) ;
return V_8 ;
}
