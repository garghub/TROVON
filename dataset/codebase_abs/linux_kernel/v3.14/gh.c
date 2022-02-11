struct V_1 * F_1 ( T_1 V_2 , T_1 (* F_2)( const void * ) ,
bool (* F_3)( const void * , const void * ) ,
void (* F_4)( void * ) )
{
struct V_1 * V_3 ;
V_3 = F_5 ( sizeof( struct V_1 ) , V_4 ) ;
if ( ! V_3 )
return F_6 ( - V_5 ) ;
F_7 ( V_3 -> V_6 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> F_2 = F_2 ;
V_3 -> F_3 = F_3 ;
V_3 -> F_4 = F_4 ;
return V_3 ;
}
void F_8 ( struct V_1 * V_3 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 ;
if ( V_3 ) {
F_9 (hash_tab->hash_table, i, tmp, n, hl) {
F_10 ( & V_8 -> V_12 ) ;
if ( V_3 -> F_4 )
V_3 -> F_4 ( V_8 -> V_13 ) ;
F_11 ( V_8 ) ;
}
F_11 ( V_3 ) ;
}
}
void * F_12 ( struct V_1 * V_3 , const void * V_14 )
{
struct V_7 * V_8 ;
T_1 V_15 = V_3 -> F_2 ( V_14 ) ;
F_13 (hash_tab->hash_table, n, hl, key_hash) {
if ( V_3 -> F_3 ( V_14 , V_8 -> V_13 ) )
return V_8 -> V_13 ;
}
return F_6 ( - V_16 ) ;
}
void * F_14 ( struct V_1 * V_3 , const void * V_14 ,
const void * V_17 )
{
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( struct V_7 ) + V_3 -> V_2 ,
V_4 ) ;
if ( ! V_8 )
return F_6 ( - V_5 ) ;
F_16 ( & V_8 -> V_12 ) ;
F_17 ( V_3 -> V_6 , & V_8 -> V_12 , V_3 -> F_2 ( V_14 ) ) ;
memcpy ( V_8 -> V_13 , V_17 , V_3 -> V_2 ) ;
return V_8 -> V_13 ;
}
void F_18 ( struct V_1 * V_3 ,
void (* F_19)( void * , void * ) , void * V_18 )
{
struct V_7 * V_8 ;
T_1 V_11 ;
if ( ! V_3 )
return;
F_20 (hash_tab->hash_table, i, n, hl)
F_19 ( & V_8 -> V_13 , V_18 ) ;
}
