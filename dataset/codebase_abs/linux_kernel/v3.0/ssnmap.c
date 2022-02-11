static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
return sizeof( struct V_3 ) + ( V_1 + V_2 ) * sizeof( T_2 ) ;
}
struct V_3 * F_2 ( T_2 V_1 , T_2 V_2 ,
T_3 V_4 )
{
struct V_3 * V_5 ;
int V_6 ;
V_6 = F_1 ( V_1 , V_2 ) ;
if ( V_6 <= V_7 )
V_5 = F_3 ( V_6 , V_4 ) ;
else
V_5 = (struct V_3 * )
F_4 ( V_4 , F_5 ( V_6 ) ) ;
if ( ! V_5 )
goto V_8;
if ( ! F_6 ( V_5 , V_1 , V_2 ) )
goto V_9;
V_5 -> V_10 = 1 ;
F_7 ( V_11 ) ;
return V_5 ;
V_9:
if ( V_6 <= V_7 )
F_8 ( V_5 ) ;
else
F_9 ( ( unsigned long ) V_5 , F_5 ( V_6 ) ) ;
V_8:
return NULL ;
}
static struct V_3 * F_6 ( struct V_3 * V_12 , T_2 V_1 ,
T_2 V_2 )
{
memset ( V_12 , 0x00 , F_1 ( V_1 , V_2 ) ) ;
V_12 -> V_1 . V_13 = ( T_2 * ) & V_12 [ 1 ] ;
V_12 -> V_1 . V_14 = V_1 ;
V_12 -> V_2 . V_13 = & V_12 -> V_1 . V_13 [ V_1 ] ;
V_12 -> V_2 . V_14 = V_2 ;
return V_12 ;
}
void F_10 ( struct V_3 * V_12 )
{
T_1 V_6 ;
V_6 = ( V_12 -> V_1 . V_14 + V_12 -> V_2 . V_14 ) * sizeof( T_2 ) ;
memset ( V_12 -> V_1 . V_13 , 0x00 , V_6 ) ;
}
void F_11 ( struct V_3 * V_12 )
{
if ( V_12 && V_12 -> V_10 ) {
int V_6 ;
V_6 = F_1 ( V_12 -> V_1 . V_14 , V_12 -> V_2 . V_14 ) ;
if ( V_6 <= V_7 )
F_8 ( V_12 ) ;
else
F_9 ( ( unsigned long ) V_12 , F_5 ( V_6 ) ) ;
F_12 ( V_11 ) ;
}
}
