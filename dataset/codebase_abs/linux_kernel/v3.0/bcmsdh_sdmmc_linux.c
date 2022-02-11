static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = 0 ;
static struct V_1 V_6 ;
F_2 ( ( L_1 , V_7 ) ) ;
F_2 ( ( L_2 , V_2 -> V_8 ) ) ;
F_2 ( ( L_3 , V_2 -> V_9 ) ) ;
F_2 ( ( L_4 , V_2 -> V_10 ) ) ;
F_2 ( ( L_5 , V_2 -> V_11 ) ) ;
if ( V_2 -> V_11 == 1 ) {
V_6 . V_11 = 0 ;
V_6 . V_12 = V_2 -> V_12 ;
V_13 -> V_2 [ 0 ] = & V_6 ;
if ( V_2 -> V_10 == 0x4 ) {
V_13 -> V_2 [ 2 ] = NULL ;
F_2 ( ( L_6 ) ) ;
V_5 = F_3 ( & V_14 ) ;
}
}
V_13 -> V_2 [ V_2 -> V_11 ] = V_2 ;
if ( V_2 -> V_11 == 2 ) {
F_4 ( V_2 ) ;
F_2 ( ( L_7 ) ) ;
V_5 = F_3 ( & V_14 ) ;
}
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( ( L_1 , V_7 ) ) ;
F_6 ( ( L_2 , V_2 -> V_8 ) ) ;
F_6 ( ( L_3 , V_2 -> V_9 ) ) ;
F_6 ( ( L_4 , V_2 -> V_10 ) ) ;
F_6 ( ( L_5 , V_2 -> V_11 ) ) ;
if ( V_2 -> V_11 == 2 ) {
F_2 ( ( L_8 ) ) ;
F_7 ( & V_14 ) ;
}
}
int F_8 ( T_1 * V_15 )
{
struct V_16 * V_17 ;
V_17 = F_9 ( sizeof( struct V_16 ) , V_18 ) ;
V_15 -> V_16 = ( void * ) V_17 ;
if ( V_17 == NULL )
return - V_19 ;
V_17 -> V_15 = V_15 ;
F_10 ( & V_17 -> V_20 ) ;
return 0 ;
}
void F_11 ( T_1 * V_15 )
{
struct V_16 * V_17 ;
ASSERT ( V_15 && V_15 -> V_16 ) ;
V_17 = (struct V_16 * ) V_15 -> V_16 ;
F_12 ( V_17 ) ;
}
T_2 F_13 ( T_1 * V_15 , bool V_21 )
{
unsigned long V_22 ;
struct V_16 * V_17 ;
F_2 ( ( L_9 , V_7 , V_21 ? L_10 : L_11 ) ) ;
V_17 = (struct V_16 * ) V_15 -> V_16 ;
ASSERT ( V_17 ) ;
#if ! F_14 ( V_23 )
if ( V_21 && ! ( V_15 -> V_24 && V_15 -> V_25 ) ) {
F_15 ( ( L_12 ,
V_7 ) ) ;
return V_26 ;
}
#endif
F_16 ( & V_17 -> V_20 , V_22 ) ;
V_15 -> V_27 = V_21 ;
if ( V_21 )
F_17 ( V_15 ) ;
else
F_18 ( V_15 ) ;
F_19 ( & V_17 -> V_20 , V_22 ) ;
return V_28 ;
}
int F_20 ( void )
{
int error = 0 ;
F_2 ( ( L_1 , V_7 ) ) ;
V_13 = F_21 ( sizeof( V_29 ) , V_30 ) ;
if ( ! V_13 )
return - V_19 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
error = F_22 ( & V_31 ) ;
return error ;
}
void F_23 ( void )
{
F_2 ( ( L_13 , V_7 ) ) ;
F_24 ( & V_31 ) ;
F_12 ( V_13 ) ;
}
