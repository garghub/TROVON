static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_1 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
return V_4 -> V_5 >= V_6 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_7 )
{
struct V_3 * V_4 ;
unsigned long V_8 , V_9 ;
T_1 V_5 ;
V_4 = V_7 ;
V_5 = V_4 -> V_5 ;
V_9 = V_4 -> V_10 [ V_5 ] . V_9 ;
V_8 = V_4 -> V_10 [ V_5 ] . V_8 ;
F_2 ( V_2 ,
L_2 ,
( int ) V_5 , V_9 , V_8 , F_5 ( V_8 ) ,
( V_8 & V_11 ) ? 'Y' : 'N' ,
( V_8 & V_12 ) ? 'Y' : 'N' ,
( V_8 & V_13 ) ? 'Y' : 'N' ,
V_5 < V_4 -> V_14 ? 'N' : 'Y' ) ;
return 0 ;
}
static void F_6 ( struct V_3 * V_4 , unsigned int V_15 )
{
if ( V_4 -> V_16 == 'I' ) {
V_4 -> V_17 = F_7 () ;
V_4 -> V_10 = V_18 [ V_15 ] ;
V_4 -> V_14 = V_19 ;
} else {
V_4 -> V_17 = F_8 () ;
V_4 -> V_10 = V_20 [ V_15 ] ;
V_4 -> V_14 = V_21 ;
}
}
static void * F_9 ( struct V_1 * V_2 , T_1 * V_5 )
{
struct V_3 * V_4 = V_2 -> V_22 ;
if ( ! * V_5 ) {
F_2 ( V_2 , L_3 , V_4 -> V_16 ,
( V_4 -> V_17 & V_23 ? L_4 : L_5 ) ,
V_4 -> V_17 ) ;
F_1 ( V_2 ) ;
} else if ( F_3 ( V_4 ) )
return NULL ;
F_10 () ;
return V_4 ;
}
static void * F_11 ( struct V_1 * V_2 , void * V_7 , T_1 * V_5 )
{
struct V_3 * V_4 = V_7 ;
V_4 -> V_5 = ++ ( * V_5 ) ;
if ( F_3 ( V_4 ) )
return NULL ;
else
return V_4 ;
}
static void F_12 ( struct V_1 * V_2 , void * V_7 )
{
F_13 () ;
}
static int F_14 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_26 * V_27 = F_15 ( V_25 -> V_28 . V_29 -> V_30 ) ;
char V_16 ;
unsigned int V_15 ;
int V_31 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_15 = ( unsigned int ) V_27 -> V_8 ;
V_16 = V_15 & V_32 ? 'D' : 'I' ;
V_15 &= ~ V_32 ;
if ( ! F_16 ( V_15 ) )
return - V_33 ;
V_31 = F_17 ( V_25 , & V_34 , sizeof( * V_4 ) ) ;
if ( V_31 )
return V_31 ;
V_2 = V_25 -> V_35 ;
V_4 = V_2 -> V_22 ;
V_4 -> V_5 = 0 ;
V_4 -> V_16 = V_16 ;
F_6 ( V_4 , V_15 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
struct V_26 * V_36 , * V_37 ;
char V_38 [ 10 ] ;
unsigned int V_15 ;
V_36 = F_19 ( L_6 , NULL ) ;
if ( ! V_36 )
return - V_39 ;
F_20 (cpu) {
sprintf ( V_38 , L_7 , V_15 ) ;
V_37 = F_19 ( V_38 , V_36 ) ;
if ( ! V_37 )
return - V_39 ;
F_21 ( L_8 , V_40 , V_37 , & V_41 ,
( void * ) V_15 ) ;
F_21 ( L_9 , V_40 , V_37 , & V_41 ,
( void * ) ( V_15 | V_32 ) ) ;
}
return 0 ;
}
