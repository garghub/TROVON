static void F_1 ( char * V_1 , char * V_2 , int V_3 )
{
memcpy ( V_1 , V_2 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = ( void * ) V_7 ;
if ( F_4 ( V_6 , 1 , 1 , 1 ) )
return;
F_1 ( V_4 -> V_8 , V_6 -> V_8 ,
sizeof( V_6 -> V_8 ) ) ;
F_1 ( V_4 -> type , V_6 -> type , sizeof( V_6 -> type ) ) ;
F_1 ( V_4 -> V_9 , V_6 -> V_9 , sizeof( V_6 -> V_9 ) ) ;
F_1 ( V_4 -> V_10 , V_6 -> V_10 , sizeof( V_6 -> V_10 ) ) ;
F_1 ( V_4 -> V_11 , V_6 -> V_11 , sizeof( V_6 -> V_11 ) ) ;
}
static void F_5 ( struct V_4 * V_4 )
{
struct V_12 * V_6 = ( void * ) V_7 ;
if ( F_4 ( V_6 , 2 , 2 , 2 ) )
return;
F_1 ( V_4 -> V_13 , V_6 -> V_13 , sizeof( V_6 -> V_13 ) ) ;
memcpy ( & V_4 -> V_14 , & V_6 -> V_14 ,
sizeof( V_4 -> V_14 ) ) ;
}
static void F_6 ( struct V_4 * V_4 )
{
struct V_15 * V_6 = ( void * ) V_7 ;
int V_16 ;
if ( F_4 ( V_6 , 3 , 2 , 2 ) )
return;
for ( V_16 = 0 ; V_16 < F_7 ( V_17 , V_6 -> V_18 , V_19 ) ; V_16 ++ ) {
F_1 ( V_4 -> V_20 [ V_16 ] . V_13 , V_6 -> V_20 [ V_16 ] . V_13 ,
sizeof( V_6 -> V_20 [ V_16 ] . V_13 ) ) ;
F_1 ( V_4 -> V_20 [ V_16 ] . V_21 , V_6 -> V_20 [ V_16 ] . V_21 ,
sizeof( V_6 -> V_20 [ V_16 ] . V_21 ) ) ;
}
V_4 -> V_22 = V_6 -> V_18 ;
}
static void F_8 ( struct V_4 * V_4 )
{
int V_23 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_9 ( V_4 -> V_24 , F_10 ( V_4 -> V_24 ) ) ;
V_23 = F_4 ( NULL , 0 , 0 , 0 ) ;
V_4 -> V_23 = V_23 ;
if ( V_23 >= 1 )
F_3 ( V_4 ) ;
if ( V_23 >= 2 )
F_5 ( V_4 ) ;
if ( V_23 >= 3 )
F_6 ( V_4 ) ;
}
void F_11 ( void )
{
static F_12 ( V_25 ) ;
unsigned long V_26 ;
if ( ! F_13 ( & V_25 , V_26 ) )
return;
F_8 ( & V_27 ) ;
if ( memcmp ( & V_28 , & V_27 , sizeof( V_27 ) ) != 0 ) {
F_14 ( V_29 , 1 , & V_27 , sizeof( V_27 ) ) ;
V_28 = V_27 ;
}
F_15 ( & V_25 , V_26 ) ;
}
static void F_16 ( unsigned long V_30 )
{
F_11 () ;
F_17 () ;
}
static void F_17 ( void )
{
F_18 ( & V_31 , V_32 + V_33 * V_34 ) ;
}
static int T_1 F_19 ( void )
{
V_29 = F_20 ( L_1 , 1 , 1 , sizeof( struct V_4 ) ) ;
if ( ! V_29 )
return - V_35 ;
F_21 ( V_29 , & V_36 ) ;
F_8 ( & V_28 ) ;
F_14 ( V_29 , 1 , & V_28 , sizeof( V_28 ) ) ;
F_17 () ;
return 0 ;
}
