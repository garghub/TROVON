static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
F_2 ( L_1 ,
V_5 , V_2 -> type ) ;
switch ( V_2 -> type ) {
case V_6 :
V_3 = V_2 -> V_7 . V_8 . V_9 ;
V_4 = V_2 -> V_7 . V_8 . V_10 ;
break;
case V_11 :
V_3 = V_2 -> V_7 . V_12 . V_9 ;
V_4 = V_2 -> V_7 . V_12 . V_10 ;
break;
default:
return;
}
for (; V_3 < V_4 ; V_3 += V_13 ) {
F_3 ( V_3 >> V_14 , 0 , 0 ) ;
}
}
static void F_4 ( void )
{
unsigned long V_15 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
F_5 ( & V_18 , V_15 ) ;
while ( ! F_6 ( & V_19 ) ) {
V_17 = F_7 ( V_19 . V_20 ,
struct V_16 , V_21 ) ;
F_8 ( & V_17 -> V_21 ) ;
F_9 ( & V_18 , V_15 ) ;
V_2 = (struct V_1 * )
& V_17 -> V_22 . V_23 [ 0 ] ;
F_1 ( V_2 ) ;
F_10 ( V_17 ) ;
F_5 ( & V_18 , V_15 ) ;
}
F_9 ( & V_18 , V_15 ) ;
}
static void F_11 ( struct V_24 * V_25 )
{
F_4 () ;
}
static int F_12 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_22 )
{
unsigned long V_15 ;
struct V_16 * V_17 ;
if ( V_28 != V_29 )
return 0 ;
V_17 = F_13 ( sizeof( * V_17 ) , V_30 ) ;
if ( ! V_17 ) {
F_14 ( L_2
L_3 ) ;
return - V_31 ;
}
memcpy ( & V_17 -> V_22 , V_22 , sizeof( struct V_32 ) ) ;
F_5 ( & V_18 , V_15 ) ;
F_15 ( & V_17 -> V_21 , & V_19 ) ;
F_9 ( & V_18 , V_15 ) ;
F_16 ( & V_33 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
int V_34 ;
if ( ! V_35 ) {
V_34 = F_18 (
V_29 , & V_36 ) ;
if ( V_34 ) {
F_14 ( L_4 ,
V_5 , V_34 ) ;
return V_34 ;
}
V_35 = 1 ;
}
return 0 ;
}
