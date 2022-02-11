int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
if ( V_6 == V_7 ) {
F_3 ( L_1 ,
V_7 ) ;
F_4 ( & V_5 ) ;
return - V_8 ;
}
F_5 (itr, &virtio_crypto_table) {
struct V_1 * V_9 =
F_6 ( V_4 , struct V_1 , V_10 ) ;
if ( V_9 == V_2 ) {
F_4 ( & V_5 ) ;
return - V_11 ;
}
}
F_7 ( & V_2 -> V_12 , 0 ) ;
F_8 ( & V_2 -> V_10 , & V_13 ) ;
V_2 -> V_14 = V_6 ++ ;
F_4 ( & V_5 ) ;
return 0 ;
}
struct V_3 * F_9 ( void )
{
return & V_13 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_2 ( & V_5 ) ;
F_11 ( & V_2 -> V_10 ) ;
V_6 -- ;
F_4 ( & V_5 ) ;
}
struct V_1 * F_12 ( void )
{
struct V_1 * V_15 = NULL ;
F_2 ( & V_5 ) ;
if ( ! F_13 ( & V_13 ) )
V_15 = F_14 ( & V_13 ,
struct V_1 ,
V_10 ) ;
F_4 ( & V_5 ) ;
return V_15 ;
}
int F_15 ( struct V_1 * V_2 )
{
return F_16 ( & V_2 -> V_12 ) != 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
if ( F_18 ( 1 , & V_2 -> V_12 ) == 1 )
if ( ! F_19 ( V_2 -> V_16 ) )
return - V_8 ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
if ( F_21 ( 1 , & V_2 -> V_12 ) == 0 )
F_22 ( V_2 -> V_16 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
return ( V_2 -> V_17 & V_18 ) ;
}
struct V_1 * F_24 ( int V_19 )
{
struct V_1 * V_2 = NULL , * V_20 ;
unsigned long V_21 = ~ 0 ;
unsigned long V_22 ;
F_2 ( & V_5 ) ;
F_25 (tmp_dev, virtcrypto_devmgr_get_head(), list) {
if ( ( V_19 == F_26 ( & V_20 -> V_23 -> V_15 ) ||
F_26 ( & V_20 -> V_23 -> V_15 ) < 0 ) &&
F_23 ( V_20 ) ) {
V_22 = F_16 ( & V_20 -> V_12 ) ;
if ( V_21 > V_22 ) {
V_2 = V_20 ;
V_21 = V_22 ;
}
}
}
if ( ! V_2 ) {
F_3 ( L_2 ,
V_19 ) ;
F_25 (tmp_dev,
virtcrypto_devmgr_get_head(), list) {
if ( F_23 ( V_20 ) ) {
V_2 = V_20 ;
break;
}
}
}
F_4 ( & V_5 ) ;
if ( ! V_2 )
return NULL ;
F_17 ( V_2 ) ;
return V_2 ;
}
int F_27 ( struct V_1 * V_24 )
{
if ( F_28 () ) {
F_29 ( L_3 ) ;
return - V_8 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_24 )
{
F_31 () ;
}
