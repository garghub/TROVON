int F_1 ( int V_1 )
{
switch ( V_1 ) {
case 0 :
return 0 ;
case - 1 :
return - V_2 ;
case - 2 :
return - V_3 ;
default:
return - V_4 ;
}
}
struct V_5 * F_2 ( void )
{
F_3 ( & V_6 ) ;
F_4 () ;
return V_7 ;
}
void F_4 ( void )
{
memset ( V_7 , 0 , sizeof( struct V_5 ) ) ;
}
void F_5 ( void )
{
F_6 ( & V_6 ) ;
}
void F_7 ( int V_8 , int V_9 )
{
struct V_10 V_11 ;
V_11 . V_12 = V_13 ;
V_11 . V_14 = V_15 ;
V_11 . V_16 = V_17 ;
V_11 . V_18 = F_8 ( V_7 ) ;
V_11 . V_19 = 0x42534931 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_9 = V_9 ;
F_9 ( & V_11 ) ;
}
struct V_20 * F_10 ( int V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_24 [ V_22 ] . V_25 == V_21 )
return & V_24 [ V_22 ] ;
}
return NULL ;
}
static void T_1 F_11 ( const struct V_26 * V_27 )
{
int V_28 = ( V_27 -> V_29 - 11 ) / sizeof( struct V_20 ) - 1 ;
struct V_20 * V_30 ;
struct V_31 * V_32 =
F_12 ( V_27 , struct V_31 , V_33 ) ;
if ( V_27 -> V_29 < 17 )
return;
V_15 = V_32 -> V_34 ;
V_17 = V_32 -> V_35 ;
V_30 = F_13 ( V_24 , ( V_23 + V_28 ) *
sizeof( struct V_20 ) ,
V_36 ) ;
if ( ! V_30 )
return;
V_24 = V_30 ;
memcpy ( V_24 + V_23 , V_32 -> V_28 ,
sizeof( struct V_20 ) * V_28 ) ;
V_23 += V_28 ;
}
static void T_1 F_14 ( const struct V_26 * V_27 , void * V_37 )
{
switch ( V_27 -> type ) {
case 0xd4 :
case 0xd5 :
case 0xd6 :
break;
case 0xda :
F_11 ( V_27 ) ;
break;
}
}
static int T_1 F_15 ( void )
{
int V_38 ;
F_16 ( F_14 , NULL ) ;
if ( ! V_24 ) {
F_17 ( L_1 ) ;
return - V_39 ;
}
V_7 = ( void * ) F_18 ( V_36 | V_40 ) ;
if ( ! V_7 ) {
V_38 = - V_41 ;
goto V_42;
}
return 0 ;
V_42:
F_19 ( V_24 ) ;
return V_38 ;
}
static void T_2 F_20 ( void )
{
F_19 ( V_24 ) ;
F_21 ( ( unsigned long ) V_7 ) ;
}
