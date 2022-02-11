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
int F_11 ( struct V_26 * V_27 )
{
return F_12 ( & V_28 , V_27 ) ;
}
int F_13 ( struct V_26 * V_27 )
{
return F_14 ( & V_28 , V_27 ) ;
}
void F_15 ( unsigned long V_29 , void * V_30 )
{
F_16 ( & V_28 , V_29 , V_30 ) ;
}
static void T_1 F_17 ( const struct V_31 * V_32 )
{
int V_33 = ( V_32 -> V_34 - 11 ) / sizeof( struct V_20 ) - 1 ;
struct V_20 * V_35 ;
struct V_36 * V_37 =
F_18 ( V_32 , struct V_36 , V_38 ) ;
if ( V_32 -> V_34 < 17 )
return;
V_15 = V_37 -> V_39 ;
V_17 = V_37 -> V_40 ;
V_35 = F_19 ( V_24 , ( V_23 + V_33 ) *
sizeof( struct V_20 ) ,
V_41 ) ;
if ( ! V_35 )
return;
V_24 = V_35 ;
memcpy ( V_24 + V_23 , V_37 -> V_33 ,
sizeof( struct V_20 ) * V_33 ) ;
V_23 += V_33 ;
}
static void T_1 F_20 ( const struct V_31 * V_32 , void * V_42 )
{
switch ( V_32 -> type ) {
case 0xd4 :
case 0xd5 :
case 0xd6 :
break;
case 0xda :
F_17 ( V_32 ) ;
break;
}
}
static int T_1 F_21 ( void )
{
int V_43 ;
F_22 ( F_20 , NULL ) ;
if ( ! V_24 ) {
F_23 ( L_1 ) ;
return - V_44 ;
}
V_7 = ( void * ) F_24 ( V_41 | V_45 ) ;
if ( ! V_7 ) {
V_43 = - V_46 ;
goto V_47;
}
return 0 ;
V_47:
F_25 ( V_24 ) ;
return V_43 ;
}
static void T_2 F_26 ( void )
{
F_25 ( V_24 ) ;
F_27 ( ( unsigned long ) V_7 ) ;
}
