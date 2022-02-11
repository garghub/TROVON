static inline int F_1 ( void )
{
int V_1 = F_2 ( NULL , 0 , 0 , 0 ) ;
return V_1 == - V_2 ? V_1 : ( ( ( unsigned int ) V_1 ) >> 28 ) ;
}
static void F_3 ( char * V_3 , char * V_4 , int V_5 )
{
memcpy ( V_3 , V_4 , V_5 ) ;
F_4 ( V_3 , V_5 ) ;
}
static void F_5 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = V_9 ;
if ( F_2 ( V_8 , 1 , 1 , 1 ) == - V_2 )
return;
F_3 ( V_6 -> V_10 , V_8 -> V_10 ,
sizeof( V_8 -> V_10 ) ) ;
F_3 ( V_6 -> type , V_8 -> type , sizeof( V_8 -> type ) ) ;
F_3 ( V_6 -> V_11 , V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
F_3 ( V_6 -> V_12 , V_8 -> V_12 , sizeof( V_8 -> V_12 ) ) ;
F_3 ( V_6 -> V_13 , V_8 -> V_13 , sizeof( V_8 -> V_13 ) ) ;
}
static void F_6 ( struct V_6 * V_6 )
{
struct V_14 * V_8 = V_9 ;
if ( F_2 ( V_8 , 2 , 2 , 2 ) == - V_2 )
return;
F_3 ( V_6 -> V_15 , V_8 -> V_15 , sizeof( V_8 -> V_15 ) ) ;
memcpy ( & V_6 -> V_16 , & V_8 -> V_16 ,
sizeof( V_6 -> V_16 ) ) ;
}
static void F_7 ( struct V_6 * V_6 )
{
struct V_17 * V_8 = V_9 ;
int V_18 ;
if ( F_2 ( V_8 , 3 , 2 , 2 ) == - V_2 )
return;
for ( V_18 = 0 ; V_18 < F_8 ( V_19 , V_8 -> V_20 , V_21 ) ; V_18 ++ ) {
F_3 ( V_6 -> V_22 [ V_18 ] . V_15 , V_8 -> V_22 [ V_18 ] . V_15 ,
sizeof( V_8 -> V_22 [ V_18 ] . V_15 ) ) ;
F_3 ( V_6 -> V_22 [ V_18 ] . V_23 , V_8 -> V_22 [ V_18 ] . V_23 ,
sizeof( V_8 -> V_22 [ V_18 ] . V_23 ) ) ;
}
V_6 -> V_24 = V_8 -> V_20 ;
}
static void F_9 ( struct V_6 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_10 ( V_6 -> V_25 , F_11 ( V_6 -> V_25 ) ) ;
V_6 -> V_26 = F_1 () ;
if ( V_6 -> V_26 == - V_2 )
return;
if ( V_6 -> V_26 >= 1 )
F_5 ( V_6 ) ;
if ( V_6 -> V_26 >= 2 )
F_6 ( V_6 ) ;
if ( V_6 -> V_26 >= 3 )
F_7 ( V_6 ) ;
}
void F_12 ( void )
{
static F_13 ( V_27 ) ;
unsigned long V_28 ;
if ( ! F_14 ( & V_27 , V_28 ) )
return;
F_9 ( & V_29 ) ;
if ( memcmp ( & V_30 , & V_29 , sizeof( V_29 ) ) != 0 ) {
F_15 ( V_31 , 1 , & V_29 , sizeof( V_29 ) ) ;
V_30 = V_29 ;
}
F_16 ( & V_27 , V_28 ) ;
}
static void F_17 ( unsigned long V_32 )
{
F_12 () ;
F_18 () ;
}
static void F_18 ( void )
{
F_19 ( & V_33 , V_34 + V_35 * V_36 ) ;
}
static int T_1 F_20 ( void )
{
V_9 = ( void * ) F_21 ( V_37 , 0 ) ;
if ( ! V_9 )
return - V_38 ;
V_31 = F_22 ( L_1 , 1 , 1 , sizeof( struct V_6 ) ) ;
if ( ! V_31 ) {
F_23 ( ( unsigned long ) V_9 ) ;
return - V_38 ;
}
F_24 ( V_31 , & V_39 ) ;
F_9 ( & V_30 ) ;
F_15 ( V_31 , 1 , & V_30 , sizeof( V_30 ) ) ;
F_18 () ;
return 0 ;
}
