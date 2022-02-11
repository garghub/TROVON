static int
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 ;
struct V_7 * V_8 = ( void * ) V_2 ;
F_2 ( V_5 , 0x00d97c + V_8 -> V_9 , 0x00000001 , 0x00000001 ) ;
return F_3 ( & V_8 -> V_10 , V_3 ) ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 ;
struct V_7 * V_8 = ( void * ) V_2 ;
switch ( F_5 ( V_8 -> V_10 . V_11 ) -> V_12 ) {
case F_6 ( V_13 ) :
F_2 ( V_5 , 0x00d970 + V_8 -> V_9 , 0x0000c003 , 0x00000002 ) ;
break;
case F_6 ( V_14 ) :
default:
F_2 ( V_5 , 0x00d970 + V_8 -> V_9 , 0x0000c003 , 0x0000c001 ) ;
break;
}
F_2 ( V_5 , 0x00d97c + V_8 -> V_9 , 0x00000001 , 0x00000000 ) ;
return F_7 ( & V_8 -> V_10 ) ;
}
static int
F_8 ( struct V_1 * V_15 , struct V_1 * V_6 ,
struct V_16 * V_17 , void * V_18 , T_1 V_19 ,
struct V_1 * * V_20 )
{
struct V_7 * V_8 ;
int V_21 ;
V_21 = F_9 ( V_15 , V_6 , V_17 , V_19 , & V_8 ) ;
* V_20 = F_10 ( V_8 ) ;
if ( V_21 )
return V_21 ;
V_8 -> V_9 = V_19 * 0x50 ; ;
return 0 ;
}
