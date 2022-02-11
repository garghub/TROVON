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
F_7 ( V_10 ) ;
return V_5 ;
V_9:
if ( V_6 <= V_7 )
F_8 ( V_5 ) ;
else
F_9 ( ( unsigned long ) V_5 , F_5 ( V_6 ) ) ;
V_8:
return NULL ;
}
static struct V_3 * F_6 ( struct V_3 * V_11 , T_2 V_1 ,
T_2 V_2 )
{
memset ( V_11 , 0x00 , F_1 ( V_1 , V_2 ) ) ;
V_11 -> V_1 . V_12 = ( T_2 * ) & V_11 [ 1 ] ;
V_11 -> V_1 . V_13 = V_1 ;
V_11 -> V_2 . V_12 = & V_11 -> V_1 . V_12 [ V_1 ] ;
V_11 -> V_2 . V_13 = V_2 ;
return V_11 ;
}
void F_10 ( struct V_3 * V_11 )
{
T_1 V_6 ;
V_6 = ( V_11 -> V_1 . V_13 + V_11 -> V_2 . V_13 ) * sizeof( T_2 ) ;
memset ( V_11 -> V_1 . V_12 , 0x00 , V_6 ) ;
}
void F_11 ( struct V_3 * V_11 )
{
int V_6 ;
if ( F_12 ( ! V_11 ) )
return;
V_6 = F_1 ( V_11 -> V_1 . V_13 , V_11 -> V_2 . V_13 ) ;
if ( V_6 <= V_7 )
F_8 ( V_11 ) ;
else
F_9 ( ( unsigned long ) V_11 , F_5 ( V_6 ) ) ;
F_13 ( V_10 ) ;
}
