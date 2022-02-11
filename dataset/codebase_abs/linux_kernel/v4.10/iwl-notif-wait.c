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
T_1 V_15 = F_9 ( V_7 -> V_16 . V_17 ,
V_7 -> V_16 . V_18 ) ;
if ( V_10 -> V_19 [ V_11 ] == V_15 ||
( ! F_10 ( V_10 -> V_19 [ V_11 ] ) &&
F_11 ( V_10 -> V_19 [ V_11 ] ) == V_15 ) ) {
V_12 = true ;
break;
}
}
if ( ! V_12 )
continue;
if ( ! V_10 -> V_20 || V_10 -> V_20 ( V_2 , V_7 , V_10 -> V_21 ) ) {
V_10 -> V_8 = true ;
V_8 = true ;
}
}
F_12 ( & V_2 -> V_3 ) ;
}
if ( V_8 )
F_13 ( & V_2 -> V_5 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_22 ;
F_7 ( & V_2 -> V_3 ) ;
F_8 (wait_entry, &notif_wait->notif_waits, list)
V_22 -> V_13 = true ;
F_12 ( & V_2 -> V_3 ) ;
F_13 ( & V_2 -> V_5 ) ;
}
void
F_15 ( struct V_1 * V_2 ,
struct V_9 * V_22 ,
const T_1 * V_19 , int V_14 ,
bool (* V_20)( struct V_1 * V_2 ,
struct V_6 * V_7 , void * V_23 ) ,
void * V_21 )
{
if ( F_16 ( V_14 > V_24 ) )
V_14 = V_24 ;
V_22 -> V_20 = V_20 ;
V_22 -> V_21 = V_21 ;
V_22 -> V_14 = V_14 ;
memcpy ( V_22 -> V_19 , V_19 , V_14 * sizeof( T_1 ) ) ;
V_22 -> V_8 = false ;
V_22 -> V_13 = false ;
F_17 ( & V_2 -> V_3 ) ;
F_18 ( & V_22 -> V_25 , & V_2 -> V_4 ) ;
F_19 ( & V_2 -> V_3 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_9 * V_22 ,
unsigned long V_26 )
{
int V_27 ;
V_27 = F_21 ( V_2 -> V_5 ,
V_22 -> V_8 || V_22 -> V_13 ,
V_26 ) ;
F_17 ( & V_2 -> V_3 ) ;
F_22 ( & V_22 -> V_25 ) ;
F_19 ( & V_2 -> V_3 ) ;
if ( V_22 -> V_13 )
return - V_28 ;
if ( V_27 <= 0 )
return - V_29 ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_9 * V_22 )
{
F_17 ( & V_2 -> V_3 ) ;
F_22 ( & V_22 -> V_25 ) ;
F_19 ( & V_2 -> V_3 ) ;
}
