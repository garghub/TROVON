static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] = 0 ;
V_2 -> V_3 [ 1 ] = 0 ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = & V_2 -> V_5 ;
V_2 -> V_7 = false ;
V_2 -> V_8 = false ;
V_2 -> V_9 = 0 ;
F_3 ( & V_2 -> V_10 , V_11 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , const char * V_12 ,
struct V_13 * V_14 )
{
F_5 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_6 ( & V_2 -> V_15 , V_12 , V_14 , 0 ) ;
return F_1 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_3 [ 0 ] || V_2 -> V_3 [ 1 ] ) ;
F_10 ( & V_2 -> V_10 ) ;
F_9 ( V_2 -> V_7 ) ;
F_9 ( V_2 -> V_8 ) ;
F_9 ( V_2 -> V_5 ) ;
F_9 ( & V_2 -> V_5 != V_2 -> V_6 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_16 )
{
int V_17 = V_2 -> V_3 [ V_16 ] - 1 ;
F_12 ( V_2 -> V_3 [ V_16 ] , V_17 ) ;
if ( ! V_17 && F_13 ( V_2 -> V_8 ) )
F_14 ( & V_2 -> V_4 ) ;
}
void V_11 ( struct V_18 * V_19 )
{
int V_16 ;
struct V_20 * V_21 ;
struct V_20 * V_22 ;
struct V_1 * V_2 ;
V_2 = F_15 ( V_19 , struct V_1 , V_10 ) ;
if ( V_2 -> V_7 || ! F_13 ( V_2 -> V_5 ) )
return;
F_12 ( V_2 -> V_7 , true ) ;
F_16 () ;
V_21 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = & V_2 -> V_5 ;
F_17 () ;
V_16 = V_2 -> V_9 ;
F_12 ( V_2 -> V_9 , ! V_2 -> V_9 ) ;
F_12 ( V_2 -> V_8 , true ) ;
F_18 ( V_2 -> V_4 , ! F_13 ( V_2 -> V_3 [ V_16 ] ) ) ;
F_12 ( V_2 -> V_8 , false ) ;
while ( V_21 ) {
V_22 = V_21 ;
V_21 = V_21 -> V_23 ;
F_19 () ;
V_22 -> V_24 ( V_22 ) ;
F_20 () ;
}
F_12 ( V_2 -> V_7 , false ) ;
if ( F_13 ( V_2 -> V_5 ) )
F_21 ( & V_2 -> V_10 ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_20 * V_22 ,
T_1 V_24 )
{
unsigned long V_25 ;
V_22 -> V_24 = V_24 ;
V_22 -> V_23 = NULL ;
F_23 ( V_25 ) ;
* V_2 -> V_6 = V_22 ;
V_2 -> V_6 = & V_22 -> V_23 ;
F_24 ( V_25 ) ;
if ( ! F_13 ( V_2 -> V_7 ) )
F_21 ( & V_2 -> V_10 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_26 V_27 ;
F_26 ( & V_27 . V_28 ) ;
F_27 ( & V_27 . V_29 ) ;
F_22 ( V_2 , & V_27 . V_28 , V_30 ) ;
F_28 ( & V_27 . V_29 ) ;
F_29 ( & V_27 . V_28 ) ;
}
