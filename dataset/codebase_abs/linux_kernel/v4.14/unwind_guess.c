unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( F_2 ( V_2 ) )
return 0 ;
V_3 = F_3 ( * V_2 -> V_4 ) ;
return F_4 ( V_2 -> V_5 , & V_2 -> V_6 ,
V_3 , V_2 -> V_4 ) ;
}
unsigned long * F_5 ( struct V_1 * V_2 )
{
return NULL ;
}
bool F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_7 ;
if ( F_2 ( V_2 ) )
return false ;
do {
for ( V_2 -> V_4 ++ ; V_2 -> V_4 < V_8 -> V_9 ; V_2 -> V_4 ++ ) {
unsigned long V_3 = F_3 ( * V_2 -> V_4 ) ;
if ( F_7 ( V_3 ) )
return true ;
}
V_2 -> V_4 = F_8 ( V_8 -> V_10 , sizeof( long ) ) ;
} while ( ! F_9 ( V_2 -> V_4 , V_2 -> V_5 , V_8 ,
& V_2 -> V_11 ) );
return false ;
}
void F_10 ( struct V_1 * V_2 , struct V_12 * V_5 ,
struct V_13 * V_14 , unsigned long * V_15 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = F_8 ( V_15 , sizeof( long ) ) ;
F_9 ( V_15 , V_2 -> V_5 , & V_2 -> V_7 ,
& V_2 -> V_11 ) ;
if ( ! F_2 ( V_2 ) &&
( ! F_11 ( & V_2 -> V_7 , V_15 , sizeof( long ) ) ||
! F_7 ( * V_15 ) ) )
F_6 ( V_2 ) ;
}
