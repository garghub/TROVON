static void * F_1 ( void * V_1 , unsigned long V_2 ,
unsigned V_3 )
{
struct V_4 V_5 ;
V_5 . V_2 = V_2 ;
F_2 ( & V_5 ) ;
if ( V_5 . V_2 == 0 )
return NULL ;
else
return ( void * ) ( unsigned long ) ~ V_5 . V_6 ;
}
static void F_3 ( void * V_1 , void * V_7 )
{
F_4 ( ~ ( ( unsigned long ) V_7 ) ) ;
}
static void F_5 ( void * V_1 )
{
;
}
static unsigned long F_6 ( void * V_1 , void * V_7 )
{
return ~ ( ( unsigned long ) V_7 ) ;
}
static int F_7 ( struct V_8 * V_9 , void * V_10 , struct V_11 * V_12 )
{
T_1 * V_13 = V_9 -> V_14 ;
T_2 * V_15 = V_10 ;
int V_16 ;
F_8 ( & V_9 -> V_17 ) ;
#if F_9 ( V_18 ) || F_9 ( V_19 )
{
struct V_20 V_21 ;
V_21 . V_1 = ( void * ) 0xFFFFFFFF ;
V_21 . V_22 = F_1 ;
V_21 . free = F_3 ;
V_21 . V_23 = F_5 ;
V_21 . V_6 = F_6 ;
V_16 =
F_10 ( & V_13 -> V_24 , V_25 , & V_21 ) ;
}
#else
V_16 = F_11 ( & V_13 -> V_24 , V_25 , 0 ,
V_15 -> V_2 >> V_26 ) ;
#endif
if ( V_16 ) {
F_12 ( L_1 ) ;
F_13 ( & V_9 -> V_17 ) ;
return V_16 ;
}
V_13 -> V_27 = 1 ;
V_13 -> V_28 = V_15 -> V_6 ;
F_13 ( & V_9 -> V_17 ) ;
F_14 ( L_2 , V_15 -> V_6 , V_15 -> V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 , struct V_11 * V_12 ,
void * V_10 , int V_29 )
{
T_1 * V_13 = V_9 -> V_14 ;
T_3 * V_30 = V_10 ;
int V_31 = 0 ;
struct V_32 * V_33 ;
F_8 ( & V_9 -> V_17 ) ;
if ( 0 == ( ( V_29 == 0 ) ? V_13 -> V_27 :
V_13 -> V_34 ) ) {
F_12
( L_3 ) ;
F_13 ( & V_9 -> V_17 ) ;
return - V_35 ;
}
V_30 -> V_2 = ( V_30 -> V_2 + V_36 ) >> V_26 ;
V_33 = F_16 ( & V_13 -> V_24 , V_29 , V_30 -> V_2 , 0 ,
( unsigned long ) V_12 ) ;
F_13 ( & V_9 -> V_17 ) ;
if ( V_33 ) {
V_30 -> V_6 = ( ( V_29 == 0 ) ?
V_13 -> V_28 : V_13 -> V_37 ) +
( V_33 -> V_38 ->
V_6 ( V_33 -> V_38 , V_33 -> V_39 ) << V_26 ) ;
V_30 -> free = V_33 -> V_40 . V_41 ;
V_30 -> V_2 = V_30 -> V_2 << V_26 ;
} else {
V_30 -> V_6 = 0 ;
V_30 -> V_2 = 0 ;
V_30 -> free = 0 ;
V_31 = - V_42 ;
}
F_14 ( L_4 , V_29 , V_30 -> V_2 ,
V_30 -> V_6 ) ;
return V_31 ;
}
static int F_17 ( struct V_8 * V_9 , void * V_10 , struct V_11 * V_12 )
{
T_1 * V_13 = V_9 -> V_14 ;
T_3 * V_30 = V_10 ;
int V_16 ;
F_8 ( & V_9 -> V_17 ) ;
V_16 = F_18 ( & V_13 -> V_24 , V_30 -> free ) ;
F_13 ( & V_9 -> V_17 ) ;
F_14 ( L_5 , V_30 -> free ) ;
return V_16 ;
}
static int F_19 ( struct V_8 * V_9 , void * V_10 ,
struct V_11 * V_12 )
{
return F_15 ( V_9 , V_12 , V_10 , V_25 ) ;
}
static int F_20 ( struct V_8 * V_9 , void * V_10 ,
struct V_11 * V_12 )
{
T_1 * V_13 = V_9 -> V_14 ;
T_4 * V_43 = V_10 ;
int V_16 ;
V_13 = V_9 -> V_14 ;
F_8 ( & V_9 -> V_17 ) ;
V_16 = F_11 ( & V_13 -> V_24 , V_44 , 0 ,
V_43 -> V_2 >> V_26 ) ;
if ( V_16 ) {
F_12 ( L_6 ) ;
F_13 ( & V_9 -> V_17 ) ;
return V_16 ;
}
V_13 -> V_34 = 1 ;
V_13 -> V_37 = V_43 -> V_6 ;
F_13 ( & V_9 -> V_17 ) ;
F_14 ( L_2 , V_43 -> V_6 , V_43 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 , void * V_10 ,
struct V_11 * V_12 )
{
return F_15 ( V_9 , V_12 , V_10 , V_44 ) ;
}
static T_5 * F_22 ( struct V_8 * V_9 )
{
struct V_45 * V_46 ;
T_5 * V_47 ;
F_23 (entry, &dev->maplist, head) {
V_47 = V_46 -> V_47 ;
if ( ! V_47 )
continue;
if ( V_47 -> type == V_48 )
return V_47 ;
}
return NULL ;
}
int F_24 ( struct V_8 * V_9 )
{
T_1 * V_13 = V_9 -> V_14 ;
T_6 V_49 ;
unsigned long V_50 ;
int V_51 ;
if ( V_13 -> V_52 )
return 0 ;
if ( V_13 -> V_53 == NULL ) {
V_13 -> V_53 = F_22 ( V_9 ) ;
if ( V_13 -> V_53 == NULL ) {
F_12 ( L_7 ) ;
return 0 ;
}
}
if ( V_13 -> V_54 != V_55 )
return 0 ;
V_50 = V_56 + ( V_57 * 3 ) ;
for ( V_51 = 0 ; V_51 < 4 ; ++ V_51 ) {
do {
V_49 = F_25 ( 0x85cc ) ;
} while ( ! F_26 ( V_56 , V_50 ) &&
( ( V_49 & 0x80000000 ) != 0x80000000 ) );
}
if ( F_26 ( V_56 , V_50 ) ) {
F_12 ( L_8
L_9 ) ;
V_13 -> V_52 = 1 ;
}
return 0 ;
}
void F_27 ( struct V_8 * V_9 )
{
T_1 * V_13 = V_9 -> V_14 ;
if ( ! V_13 )
return;
F_8 ( & V_9 -> V_17 ) ;
F_28 ( & V_13 -> V_24 ) ;
V_13 -> V_27 = 0 ;
V_13 -> V_34 = 0 ;
V_13 -> V_53 = NULL ;
F_13 ( & V_9 -> V_17 ) ;
}
void F_29 ( struct V_8 * V_9 ,
struct V_11 * V_12 )
{
T_1 * V_13 = V_9 -> V_14 ;
F_8 ( & V_9 -> V_17 ) ;
if ( F_30 ( & V_13 -> V_24 , ( unsigned long ) V_12 ) ) {
F_13 ( & V_9 -> V_17 ) ;
return;
}
if ( V_9 -> V_58 -> V_59 )
V_9 -> V_58 -> V_59 ( V_9 ) ;
F_31 ( & V_13 -> V_24 , ( unsigned long ) V_12 ) ;
F_13 ( & V_9 -> V_17 ) ;
return;
}
