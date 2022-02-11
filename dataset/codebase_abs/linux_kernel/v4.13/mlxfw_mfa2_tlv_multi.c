const struct V_1 *
F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( sizeof( struct V_4 ) ) ;
return F_3 ( V_3 , ( void * ) V_5 + V_6 ) ;
}
const struct V_1 *
F_4 ( const struct V_2 * V_3 ,
const struct V_1 * V_7 )
{
const struct V_4 * V_5 ;
T_2 V_8 ;
void * V_9 ;
V_8 = F_5 ( V_7 ) ;
if ( V_7 -> type == V_10 ) {
V_5 = F_6 ( V_3 , V_7 ) ;
V_8 = F_2 ( V_8 + F_7 ( V_5 -> V_11 ) ) ;
}
V_9 = ( void * ) V_7 + V_8 ;
return F_3 ( V_3 , V_9 ) ;
}
const struct V_1 *
F_8 ( const struct V_2 * V_3 ,
const struct V_1 * V_12 , T_2 V_13 )
{
const struct V_1 * V_7 ;
T_2 V_14 ;
F_9 (mfa2_file, tlv, idx, from_tlv, count)
if ( ! V_7 )
return NULL ;
return V_7 ;
}
const struct V_1 *
F_10 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 ,
enum V_15 type , T_2 V_16 )
{
const struct V_1 * V_7 ;
T_2 V_17 = 0 ;
T_2 V_14 ;
F_11 (mfa2_file, tlv, idx, multi) {
if ( ! V_7 ) {
F_12 ( L_1 ) ;
return NULL ;
}
if ( V_7 -> type == type )
if ( V_17 ++ == V_16 )
return V_7 ;
}
return NULL ;
}
int F_13 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 ,
enum V_15 type ,
T_2 * V_18 )
{
const struct V_1 * V_7 ;
T_2 V_13 = 0 ;
T_2 V_14 ;
F_11 (mfa2_file, tlv, idx, multi) {
if ( ! V_7 ) {
F_12 ( L_1 ) ;
return - V_19 ;
}
if ( V_7 -> type == type )
V_13 ++ ;
}
* V_18 = V_13 ;
return 0 ;
}
