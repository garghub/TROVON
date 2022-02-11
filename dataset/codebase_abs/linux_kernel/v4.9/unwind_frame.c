unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned long * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( V_2 ) )
return 0 ;
V_3 = F_4 ( V_2 -> V_5 , & V_2 -> V_6 , * V_4 ,
V_4 ) ;
return F_5 ( V_3 ) ? V_3 : 0 ;
}
static bool F_6 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_8 ;
while ( ! F_7 ( V_9 , V_3 , V_7 ) )
if ( F_8 ( V_9 -> V_10 , V_2 -> V_5 , V_9 ,
& V_2 -> V_11 ) )
return false ;
return true ;
}
bool F_9 ( struct V_1 * V_2 )
{
unsigned long * V_12 ;
if ( F_3 ( V_2 ) )
return false ;
V_12 = ( unsigned long * ) * V_2 -> V_13 ;
if ( ! F_6 ( V_2 , V_12 , V_14 ) )
return false ;
V_2 -> V_13 = V_12 ;
return true ;
}
void F_10 ( struct V_1 * V_2 , struct V_15 * V_5 ,
struct V_16 * V_17 , unsigned long * V_18 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 = V_5 ;
if ( V_17 && F_11 ( V_17 ) ) {
V_2 -> V_8 . type = V_19 ;
return;
}
V_2 -> V_13 = F_12 ( V_5 , V_17 ) ;
F_8 ( V_2 -> V_13 , V_2 -> V_5 , & V_2 -> V_8 ,
& V_2 -> V_11 ) ;
F_6 ( V_2 , V_2 -> V_13 , V_14 ) ;
while ( ! F_3 ( V_2 ) &&
( ! F_7 ( & V_2 -> V_8 , V_18 , sizeof( long ) ) ||
V_2 -> V_13 < V_18 ) )
F_9 ( V_2 ) ;
}
