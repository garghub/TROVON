static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 = 0 ;
if ( V_2 -> V_5 )
F_2 ( V_2 -> V_5 , V_4 ) ;
V_3 = F_3 ( V_2 -> V_3 ) ;
V_3 |= F_4 ( V_2 -> V_6 ) ;
F_5 ( V_3 , V_2 -> V_3 ) ;
if ( V_2 -> V_5 )
F_6 ( V_2 -> V_5 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 = 0 ;
if ( V_2 -> V_5 )
F_2 ( V_2 -> V_5 , V_4 ) ;
V_3 = F_3 ( V_2 -> V_3 ) ;
V_3 &= ~ F_4 ( V_2 -> V_6 ) ;
F_5 ( V_3 , V_2 -> V_3 ) ;
if ( V_2 -> V_5 )
F_6 ( V_2 -> V_5 , V_4 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
if ( V_2 -> V_4 & V_9 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
if ( V_2 -> V_4 & V_9 )
F_1 ( V_2 ) ;
else
F_7 ( V_2 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
T_1 V_3 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
V_3 = F_3 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 & V_9 )
V_3 ^= F_4 ( V_2 -> V_6 ) ;
V_3 &= F_4 ( V_2 -> V_6 ) ;
return V_3 ? 1 : 0 ;
}
struct V_10 * F_12 ( struct V_11 * V_12 , const char * V_13 ,
const char * V_14 , unsigned long V_4 ,
void T_2 * V_3 , T_3 V_6 ,
T_3 V_15 , T_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_10 * V_10 ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_2 ) {
F_14 ( L_1 , V_17 ) ;
return NULL ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_15 ;
V_2 -> V_5 = V_5 ;
if ( V_14 ) {
V_2 -> V_18 [ 0 ] = F_15 ( V_14 , V_16 ) ;
if ( ! V_2 -> V_18 [ 0 ] )
goto V_19;
}
V_10 = F_16 ( V_12 , V_13 ,
& V_20 , & V_2 -> V_8 ,
V_2 -> V_18 ,
( V_14 ? 1 : 0 ) ,
V_4 ) ;
if ( V_10 )
return V_10 ;
V_19:
F_17 ( V_2 -> V_18 [ 0 ] ) ;
F_17 ( V_2 ) ;
return NULL ;
}
