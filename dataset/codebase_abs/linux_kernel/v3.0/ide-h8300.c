static void F_1 ( unsigned long V_1 , void * V_2 , T_1 V_3 )
{
unsigned short * V_4 = ( unsigned short * ) V_2 ;
for (; V_3 > 0 ; V_3 -- , V_4 ++ )
* ( volatile V_5 * ) V_1 = F_2 ( * V_4 ) ;
}
static void F_3 ( unsigned long V_1 , void * V_2 , T_1 V_3 )
{
unsigned short * V_4 = ( unsigned short * ) V_2 ;
for (; V_3 > 0 ; V_3 -- , V_4 ++ )
* V_4 = F_2 ( * ( volatile V_5 * ) V_1 ) ;
}
static void F_4 ( T_2 * V_6 , struct V_7 * V_8 ,
void * V_2 , unsigned int V_3 )
{
F_3 ( V_6 -> V_9 -> V_10 . V_11 , V_2 , ( V_3 + 1 ) / 2 ) ;
}
static void F_5 ( T_2 * V_6 , struct V_7 * V_8 ,
void * V_2 , unsigned int V_3 )
{
F_1 ( V_6 -> V_9 -> V_10 . V_11 , V_2 , ( V_3 + 1 ) / 2 ) ;
}
static inline void F_6 ( struct V_12 * V_13 )
{
int V_14 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
for ( V_14 = 0 ; V_14 <= 7 ; V_14 ++ )
V_13 -> V_15 [ V_14 ] = V_16 + V_17 * V_14 ;
V_13 -> V_10 . V_18 = V_19 ;
V_13 -> V_20 = V_21 + V_22 ;
}
static int T_3 F_7 ( void )
{
struct V_12 V_13 , * V_23 [] = { & V_13 } ;
F_8 (KERN_INFO DRV_NAME L_1 ) ;
if ( ! F_9 ( V_16 , V_17 * 8 , L_2 ) )
goto V_24;
if ( ! F_9 ( V_19 , V_17 , L_2 ) ) {
F_10 ( V_16 , V_17 * 8 ) ;
goto V_24;
}
F_6 ( & V_13 ) ;
return F_11 ( & V_25 , V_23 , 1 , NULL ) ;
V_24:
F_8 ( V_26 L_3 ) ;
return - V_27 ;
}
