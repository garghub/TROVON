void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
if ( ! F_6 ( & V_2 -> V_4 ) ) {
struct V_8 * V_9 ;
F_7 ( & V_2 -> V_3 ) ;
F_8 (w, &notif_wait->notif_waits, list) {
if ( V_9 -> V_10 != V_7 -> V_11 . V_10 )
continue;
V_9 -> V_12 = true ;
if ( V_9 -> V_13 )
V_9 -> V_13 ( V_2 , V_7 , V_9 -> V_14 ) ;
}
F_9 ( & V_2 -> V_3 ) ;
F_10 ( & V_2 -> V_5 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
struct V_8 * V_16 ;
F_12 ( & V_2 -> V_3 , V_15 ) ;
F_8 (wait_entry, &notif_wait->notif_waits, list)
V_16 -> V_17 = true ;
F_13 ( & V_2 -> V_3 , V_15 ) ;
F_10 ( & V_2 -> V_5 ) ;
}
void
F_14 ( struct V_1 * V_2 ,
struct V_8 * V_16 ,
T_1 V_10 ,
void (* V_13)( struct V_1 * V_2 ,
struct V_6 * V_7 , void * V_18 ) ,
void * V_14 )
{
V_16 -> V_13 = V_13 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_10 = V_10 ;
V_16 -> V_12 = false ;
V_16 -> V_17 = false ;
F_15 ( & V_2 -> V_3 ) ;
F_16 ( & V_16 -> V_19 , & V_2 -> V_4 ) ;
F_17 ( & V_2 -> V_3 ) ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_8 * V_16 ,
unsigned long V_20 )
{
int V_21 ;
V_21 = F_19 ( V_2 -> V_5 ,
V_16 -> V_12 || V_16 -> V_17 ,
V_20 ) ;
F_15 ( & V_2 -> V_3 ) ;
F_20 ( & V_16 -> V_19 ) ;
F_17 ( & V_2 -> V_3 ) ;
if ( V_16 -> V_17 )
return - V_22 ;
if ( V_21 <= 0 )
return - V_23 ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_8 * V_16 )
{
F_15 ( & V_2 -> V_3 ) ;
F_20 ( & V_16 -> V_19 ) ;
F_17 ( & V_2 -> V_3 ) ;
}
