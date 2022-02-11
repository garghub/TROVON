void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
bool F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
bool V_8 = false ;
if ( ! F_6 ( & V_2 -> V_4 ) ) {
struct F_5 * V_9 ;
F_7 ( & V_2 -> V_3 ) ;
F_8 (w, &notif_wait->notif_waits, list) {
int V_10 ;
bool V_11 = false ;
if ( V_9 -> V_8 || V_9 -> V_12 )
continue;
for ( V_10 = 0 ; V_10 < V_9 -> V_13 ; V_10 ++ ) {
T_1 V_14 = F_9 ( V_7 -> V_15 . V_16 ,
V_7 -> V_15 . V_17 ) ;
if ( V_9 -> V_18 [ V_10 ] == V_14 ||
( ! F_10 ( V_9 -> V_18 [ V_10 ] ) &&
F_11 ( V_9 -> V_18 [ V_10 ] ) == V_14 ) ) {
V_11 = true ;
break;
}
}
if ( ! V_11 )
continue;
if ( ! V_9 -> V_19 || V_9 -> V_19 ( V_2 , V_7 , V_9 -> V_20 ) ) {
V_9 -> V_8 = true ;
V_8 = true ;
}
}
F_12 ( & V_2 -> V_3 ) ;
}
return V_8 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct F_5 * V_21 ;
F_7 ( & V_2 -> V_3 ) ;
F_8 (wait_entry, &notif_wait->notif_waits, list)
V_21 -> V_12 = true ;
F_12 ( & V_2 -> V_3 ) ;
F_14 ( & V_2 -> V_5 ) ;
}
void
F_15 ( struct V_1 * V_2 ,
struct F_5 * V_21 ,
const T_1 * V_18 , int V_13 ,
bool (* V_19)( struct V_1 * V_2 ,
struct V_6 * V_7 , void * V_22 ) ,
void * V_20 )
{
if ( F_16 ( V_13 > V_23 ) )
V_13 = V_23 ;
V_21 -> V_19 = V_19 ;
V_21 -> V_20 = V_20 ;
V_21 -> V_13 = V_13 ;
memcpy ( V_21 -> V_18 , V_18 , V_13 * sizeof( T_1 ) ) ;
V_21 -> V_8 = false ;
V_21 -> V_12 = false ;
F_17 ( & V_2 -> V_3 ) ;
F_18 ( & V_21 -> V_24 , & V_2 -> V_4 ) ;
F_19 ( & V_2 -> V_3 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct F_5 * V_21 )
{
F_17 ( & V_2 -> V_3 ) ;
F_21 ( & V_21 -> V_24 ) ;
F_19 ( & V_2 -> V_3 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct F_5 * V_21 ,
unsigned long V_25 )
{
int V_26 ;
V_26 = F_23 ( V_2 -> V_5 ,
V_21 -> V_8 || V_21 -> V_12 ,
V_25 ) ;
F_20 ( V_2 , V_21 ) ;
if ( V_21 -> V_12 )
return - V_27 ;
if ( V_26 <= 0 )
return - V_28 ;
return 0 ;
}
