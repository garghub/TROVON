static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned long V_6 ,
unsigned long V_7 )
{
int V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 )
V_2 -> V_9 = V_8 ;
if ( ! V_2 -> V_9 )
V_2 -> V_9 = V_2 -> V_10 ;
if ( F_5 ( V_2 ) &&
V_6 == V_2 -> V_4 &&
V_7 == V_2 -> V_5 )
return;
F_1 ( V_2 ) ;
V_2 -> V_4 = V_6 ;
V_2 -> V_5 = V_7 ;
if ( ! V_6 )
return;
if ( ! V_7 ) {
F_6 ( V_2 , V_2 -> V_9 ) ;
return;
}
F_7 ( & V_2 -> V_3 , V_11 + 1 ) ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned long * V_6 ,
unsigned long * V_7 )
{
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_12 &&
! V_2 -> V_12 ( V_2 , V_6 , V_7 ) )
return;
if ( ! * V_6 && ! * V_7 )
* V_6 = * V_7 = 500 ;
F_3 ( V_2 , * V_6 , * V_7 ) ;
}
void F_9 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
F_1 ( V_2 ) ;
V_2 -> V_15 ( V_2 , V_14 ) ;
}
