static int
F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 ;
V_8 -> V_9 = F_2 ( sizeof( struct V_7 ) - 4 + 2 ) ;
V_8 -> V_10 = V_11 ;
V_8 -> V_12 = 0 ;
F_3 ( 0 , V_8 ) ;
F_4 ( & V_2 -> V_13 ) ;
V_6 = F_5 ( V_8 , V_2 , & V_5 -> V_14 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_13 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 , V_8 , F_8 ( V_8 -> V_9 ) ) ;
F_6 ( & V_2 -> V_13 ) ;
F_9 ( 1 , L_1 ,
V_8 -> V_15 , V_6 ) ;
return V_6 ;
}
static bool
F_10 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
return V_17 -> V_19 == V_18 -> V_19 ;
}
static unsigned int
F_11 ( char * V_3 )
{
T_1 * V_20 = ( T_1 * ) V_3 ;
return F_12 ( V_20 -> V_21 ) ;
}
static unsigned int
F_13 ( char * V_3 )
{
T_1 * V_20 = ( T_1 * ) V_3 ;
return ( F_12 ( V_20 -> V_22 ) << 16 ) +
F_12 ( V_20 -> V_23 ) ;
}
static struct V_4 *
F_14 ( struct V_1 * V_2 , char * V_24 )
{
struct V_7 * V_3 = (struct V_7 * ) V_24 ;
struct V_4 * V_5 ;
F_15 ( & V_25 ) ;
F_16 (mid, &server->pending_mid_q, qhead) {
if ( V_5 -> V_5 == V_3 -> V_15 &&
V_5 -> V_26 == V_27 &&
F_12 ( V_5 -> V_28 ) == V_3 -> V_10 ) {
F_17 ( & V_25 ) ;
return V_5 ;
}
}
F_17 ( & V_25 ) ;
return NULL ;
}
static void
F_18 ( struct V_1 * V_2 , const unsigned int V_29 )
{
F_15 ( & V_2 -> V_30 ) ;
V_2 -> V_31 += V_29 ;
V_2 -> V_32 -- ;
F_17 ( & V_2 -> V_30 ) ;
F_19 ( & V_2 -> V_33 ) ;
}
static void
F_20 ( struct V_1 * V_2 , const int V_34 )
{
F_15 ( & V_2 -> V_30 ) ;
V_2 -> V_31 = V_34 ;
V_2 -> V_35 = V_34 > 1 ? V_36 : false ;
F_17 ( & V_2 -> V_30 ) ;
}
static int *
F_21 ( struct V_1 * V_2 )
{
return & V_2 -> V_31 ;
}
static T_2
F_22 ( struct V_1 * V_2 )
{
T_2 V_5 = 0 ;
T_3 V_37 , V_38 ;
bool V_39 ;
F_15 ( & V_25 ) ;
V_38 = ( T_3 ) ( ( V_2 -> V_40 ) & 0xffff ) ;
V_37 = V_38 ;
V_38 ++ ;
while ( V_38 != V_37 ) {
struct V_4 * V_41 ;
unsigned int V_42 ;
V_39 = false ;
if ( V_38 == 0 )
V_38 ++ ;
V_42 = 0 ;
F_16 (mid_entry, &server->pending_mid_q, qhead) {
++ V_42 ;
if ( V_41 -> V_5 == V_38 &&
V_41 -> V_26 == V_27 ) {
V_39 = true ;
break;
}
}
if ( V_42 > 32768 )
V_2 -> V_43 = V_44 ;
if ( ! V_39 ) {
V_5 = ( T_2 ) V_38 ;
V_2 -> V_40 = V_5 ;
break;
}
V_38 ++ ;
}
F_17 ( & V_25 ) ;
return V_5 ;
}
