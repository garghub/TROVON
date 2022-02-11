inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
inline T_1 * F_2 ( T_2 V_4 )
{
T_1 * V_5 ;
V_5 = F_3 ( V_4 ) ;
return V_5 ;
}
inline T_1 * F_4 ( T_2 V_4 )
{
T_1 * V_5 ;
V_5 = F_2 ( V_4 ) ;
if ( V_5 != NULL )
memset ( V_5 , 0 , V_4 ) ;
return V_5 ;
}
inline void F_5 ( T_1 * V_5 , T_2 V_4 )
{
F_6 ( V_5 ) ;
}
void F_7 ( struct V_6 * V_7 )
{
F_8 ( & V_7 -> V_8 ) ;
F_9 ( & V_7 -> V_9 ) ;
}
T_2 F_10 ( struct V_6 * V_7 )
{
if ( F_11 ( & V_7 -> V_8 ) )
return true ;
else
return false ;
}
T_3 F_12 ( T_3 V_10 , T_3 V_11 )
{
return F_13 ( V_10 , V_11 ) ;
}
T_3 F_14 ( T_3 V_10 , T_3 V_11 )
{
F_13 ( V_10 , V_11 ) ;
return V_10 ;
}
inline bool F_15 ( struct V_12 * V_13 )
{
return ( V_13 -> V_14 == V_13 -> V_15 - 1 ) ? true : false ;
}
inline bool F_16 ( struct V_12 * V_13 )
{
return ( V_13 -> V_14 == V_13 -> V_15 ) ? true : false ;
}
bool F_17 ( struct V_12 * V_13 , void * V_16 )
{
if ( F_15 ( V_13 ) )
return V_3 ;
if ( 0 )
F_18 ( L_1 , V_17 , V_13 -> V_14 ) ;
V_13 -> V_18 [ V_13 -> V_14 ] = V_16 ;
V_13 -> V_14 = ( V_13 -> V_14 + 1 ) % V_13 -> V_19 ;
return V_2 ;
}
void * F_19 ( struct V_12 * V_13 )
{
void * V_16 ;
if ( F_16 ( V_13 ) )
return NULL ;
if ( 0 )
F_18 ( L_1 , V_17 , V_13 -> V_15 ) ;
V_16 = V_13 -> V_18 [ V_13 -> V_15 ] ;
V_13 -> V_15 = ( V_13 -> V_15 + 1 ) % V_13 -> V_19 ;
return V_16 ;
}
struct V_12 * F_20 ( T_2 V_19 )
{
struct V_12 * V_13 ;
V_13 = F_21 ( sizeof( * V_13 ) + sizeof( void * ) * V_19 , V_20 ) ;
if ( V_13 ) {
V_13 -> V_14 = 0 ;
V_13 -> V_15 = 0 ;
V_13 -> V_19 = V_19 ;
}
return V_13 ;
}
void F_22 ( struct V_12 * V_13 )
{
F_23 ( V_13 ) ;
}
