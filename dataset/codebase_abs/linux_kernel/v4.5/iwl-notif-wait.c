void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
bool V_8 = false ;
if ( ! F_6 ( & V_2 -> V_4 ) ) {
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_3 ) ;
F_8 (w, &notif_wait->notif_waits, list) {
int V_11 ;
bool V_12 = false ;
if ( V_10 -> V_8 || V_10 -> V_13 )
continue;
for ( V_11 = 0 ; V_11 < V_10 -> V_14 ; V_11 ++ ) {
if ( V_10 -> V_15 [ V_11 ] ==
F_9 ( V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 ) ) {
V_12 = true ;
break;
}
}
if ( ! V_12 )
continue;
if ( ! V_10 -> V_19 || V_10 -> V_19 ( V_2 , V_7 , V_10 -> V_20 ) ) {
V_10 -> V_8 = true ;
V_8 = true ;
}
}
F_10 ( & V_2 -> V_3 ) ;
}
if ( V_8 )
F_11 ( & V_2 -> V_5 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_21 ;
F_7 ( & V_2 -> V_3 ) ;
F_8 (wait_entry, &notif_wait->notif_waits, list)
V_21 -> V_13 = true ;
F_10 ( & V_2 -> V_3 ) ;
F_11 ( & V_2 -> V_5 ) ;
}
void
F_13 ( struct V_1 * V_2 ,
struct V_9 * V_21 ,
const T_1 * V_15 , int V_14 ,
bool (* V_19)( struct V_1 * V_2 ,
struct V_6 * V_7 , void * V_22 ) ,
void * V_20 )
{
if ( F_14 ( V_14 > V_23 ) )
V_14 = V_23 ;
V_21 -> V_19 = V_19 ;
V_21 -> V_20 = V_20 ;
V_21 -> V_14 = V_14 ;
memcpy ( V_21 -> V_15 , V_15 , V_14 * sizeof( T_1 ) ) ;
V_21 -> V_8 = false ;
V_21 -> V_13 = false ;
F_15 ( & V_2 -> V_3 ) ;
F_16 ( & V_21 -> V_24 , & V_2 -> V_4 ) ;
F_17 ( & V_2 -> V_3 ) ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_9 * V_21 ,
unsigned long V_25 )
{
int V_26 ;
V_26 = F_19 ( V_2 -> V_5 ,
V_21 -> V_8 || V_21 -> V_13 ,
V_25 ) ;
F_15 ( & V_2 -> V_3 ) ;
F_20 ( & V_21 -> V_24 ) ;
F_17 ( & V_2 -> V_3 ) ;
if ( V_21 -> V_13 )
return - V_27 ;
if ( V_26 <= 0 )
return - V_28 ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_9 * V_21 )
{
F_15 ( & V_2 -> V_3 ) ;
F_20 ( & V_21 -> V_24 ) ;
F_17 ( & V_2 -> V_3 ) ;
}
