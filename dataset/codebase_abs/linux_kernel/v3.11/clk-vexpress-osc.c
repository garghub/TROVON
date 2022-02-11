static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
F_3 ( V_5 -> V_7 , 0 , & V_6 ) ;
return V_6 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_5 ( V_5 -> V_8 && V_6 < V_5 -> V_8 ) )
V_6 = V_5 -> V_8 ;
if ( F_5 ( V_5 -> V_9 && V_6 > V_5 -> V_9 ) )
V_6 = V_5 -> V_9 ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_7 ( V_5 -> V_7 , 0 , V_6 ) ;
}
struct V_10 * T_2 F_8 ( struct V_11 * V_12 )
{
struct V_13 V_14 ;
struct V_4 * V_5 = F_9 ( sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_7 = F_10 ( V_12 ) ;
if ( ! V_5 -> V_7 ) {
F_11 ( V_5 ) ;
return NULL ;
}
V_14 . V_16 = F_12 ( V_12 ) ;
V_14 . V_17 = & V_18 ;
V_14 . V_19 = V_20 ;
V_14 . V_21 = 0 ;
V_5 -> V_2 . V_14 = & V_14 ;
return F_13 ( NULL , & V_5 -> V_2 ) ;
}
void T_2 F_14 ( struct V_22 * V_23 )
{
struct V_13 V_14 ;
struct V_4 * V_5 ;
struct V_10 * V_10 ;
T_1 V_24 [ 2 ] ;
V_5 = F_9 ( sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 )
goto error;
V_5 -> V_7 = F_15 ( V_23 ) ;
if ( ! V_5 -> V_7 ) {
F_16 ( L_1 ,
V_23 -> V_25 ) ;
goto error;
}
if ( F_17 ( V_23 , L_2 , V_24 ,
F_18 ( V_24 ) ) == 0 ) {
V_5 -> V_8 = V_24 [ 0 ] ;
V_5 -> V_9 = V_24 [ 1 ] ;
}
F_19 ( V_23 , L_3 , & V_14 . V_16 ) ;
if ( ! V_14 . V_16 )
V_14 . V_16 = V_23 -> V_25 ;
V_14 . V_17 = & V_18 ;
V_14 . V_19 = V_20 ;
V_14 . V_21 = 0 ;
V_5 -> V_2 . V_14 = & V_14 ;
V_10 = F_13 ( NULL , & V_5 -> V_2 ) ;
if ( F_20 ( V_10 ) ) {
F_16 ( L_4 , V_14 . V_16 ) ;
goto error;
}
F_21 ( V_23 , V_26 , V_10 ) ;
F_22 ( L_5 , V_14 . V_16 ) ;
return;
error:
if ( V_5 -> V_7 )
F_23 ( V_5 -> V_7 ) ;
F_11 ( V_5 ) ;
}
