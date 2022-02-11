static int F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case 0x1f0 : return 14 ;
case 0x170 : return 15 ;
case 0x1e8 : return 11 ;
default:
return 0 ;
}
}
static void F_2 ( struct V_2 * V_3 , unsigned long V_1 , int V_4 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_5 . V_6 = F_3 ( V_1 ) ;
V_3 -> V_5 . V_7 = F_4 ( V_1 + 1 ) ;
V_3 -> V_5 . V_8 = F_4 ( V_1 + 2 ) ;
V_3 -> V_5 . V_9 = F_4 ( V_1 + 3 ) ;
V_3 -> V_5 . V_10 = F_4 ( V_1 + 4 ) ;
V_3 -> V_5 . V_11 = F_4 ( V_1 + 5 ) ;
V_3 -> V_5 . V_12 = F_4 ( V_1 + 6 ) ;
V_3 -> V_5 . V_13 = F_4 ( V_1 + 7 ) ;
V_3 -> V_5 . V_14 = F_4 ( V_1 + 0x206 ) ;
V_3 -> V_4 = V_4 ;
}
static void F_5 ( T_1 * V_15 , struct V_16 * V_17 ,
void * V_18 , unsigned int V_19 )
{
unsigned long V_6 = V_15 -> V_20 -> V_5 . V_6 ;
if ( V_15 -> V_21 == V_22 && V_17 && ( V_17 -> V_23 & V_24 ) ) {
F_6 ( V_6 , V_18 , ( V_19 + 1 ) / 2 ) ;
return;
}
F_7 ( ( V_25 * ) V_6 , V_18 , ( V_19 + 1 ) / 2 ) ;
}
static void F_8 ( T_1 * V_15 , struct V_16 * V_17 ,
void * V_18 , unsigned int V_19 )
{
unsigned long V_6 = V_15 -> V_20 -> V_5 . V_6 ;
if ( V_15 -> V_21 == V_22 && V_17 && ( V_17 -> V_23 & V_24 ) ) {
F_9 ( V_6 , V_18 , ( V_19 + 1 ) / 2 ) ;
return;
}
F_10 ( ( V_25 * ) V_6 , V_18 , ( V_19 + 1 ) / 2 ) ;
}
static int T_2 F_11 ( void )
{
int V_26 ;
struct V_2 V_3 [ V_27 ] , * V_28 [] = { NULL , NULL } ;
if ( ! V_29 )
return - V_30 ;
F_12 ( V_31 L_1 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
const char * V_32 = V_33 [ V_26 ] ;
if ( ! F_13 ( V_34 [ V_26 ] , 8 , V_32 ) ) {
F_12 ( L_2 ,
V_34 [ V_26 ] , V_34 [ V_26 ] + 8 , V_32 ) ;
continue;
}
if ( ! F_13 ( V_34 [ V_26 ] + 0x206 , 1 , V_32 ) ) {
F_12 ( L_3 ,
V_34 [ V_26 ] + 0x206 , V_32 ) ;
F_14 ( V_34 [ V_26 ] , 8 ) ;
continue;
}
F_2 ( & V_3 [ V_26 ] , V_34 [ V_26 ] ,
F_1 ( V_34 [ V_26 ] ) ) ;
V_28 [ V_26 ] = & V_3 [ V_26 ] ;
}
return F_15 ( & V_35 , V_28 , V_27 , NULL ) ;
}
