static int F_1 ( unsigned int V_1 , bool V_2 )
{
T_1 V_3 , V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 , V_6 , & V_3 , & V_4 ) ;
if ( V_5 ) {
F_3 ( L_1 , V_7 ) ;
return V_5 ;
}
V_2 ? ( V_3 |= F_4 ( 18 ) ) : ( V_3 &= ~ F_4 ( 18 ) ) ;
V_5 = F_5 ( V_1 , V_6 , V_3 , V_4 ) ;
if ( V_5 )
F_3 ( L_2 , V_7 ) ;
return V_5 ;
}
static int F_6 ( void * V_8 , T_2 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
* V_9 = V_11 -> V_12 ;
return 0 ;
}
static int F_7 ( void * V_8 , T_2 V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
V_11 -> V_12 = ( V_13 ) V_9 ;
return 0 ;
}
static int F_8 ( void * V_8 , T_2 V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
if ( V_9 >= V_14 || ! F_9 ( V_9 ) ) {
F_3 ( L_3 , V_7 , V_9 ) ;
return - V_15 ;
}
V_11 -> V_16 = V_9 ;
return 0 ;
}
static void F_10 ( void * V_17 )
{
asm volatile("int $18");
}
static void F_11 ( void )
{
T_2 V_18 = 0 ;
unsigned int V_1 = V_19 . V_16 ;
V_13 V_20 = V_19 . V_21 ;
if ( ! ( V_19 . V_12 & V_22 ) ) {
F_12 ( NULL , 0 , & V_19 ) ;
return;
}
F_13 () ;
if ( ! F_9 ( V_1 ) )
goto V_5;
V_18 = V_23 | V_24 ;
if ( ! ( V_19 . V_25 & V_26 ) )
V_18 |= V_27 ;
F_1 ( V_1 , true ) ;
F_5 ( V_1 , V_28 ,
( T_1 ) V_18 , ( T_1 ) ( V_18 >> 32 ) ) ;
F_5 ( V_1 , F_14 ( V_20 ) ,
( T_1 ) V_19 . V_25 , ( T_1 ) ( V_19 . V_25 >> 32 ) ) ;
F_5 ( V_1 , F_15 ( V_20 ) ,
( T_1 ) V_19 . V_29 , ( T_1 ) ( V_19 . V_29 >> 32 ) ) ;
F_5 ( V_1 , F_16 ( V_20 ) ,
( T_1 ) V_19 . V_30 , ( T_1 ) ( V_19 . V_30 >> 32 ) ) ;
F_1 ( V_1 , false ) ;
F_17 ( V_1 , F_10 , NULL , 0 ) ;
V_5:
F_18 () ;
}
static int F_19 ( void * V_8 , T_2 V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
if ( V_9 > 5 ) {
if ( V_31 . V_32 != 0x15 || V_9 > 6 ) {
F_3 ( L_4 , V_9 ) ;
return - V_15 ;
}
}
V_11 -> V_21 = V_9 ;
F_11 () ;
return 0 ;
}
static int F_20 ( void * V_8 , T_2 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
* V_9 = V_11 -> V_21 ;
return 0 ;
}
static int T_3 F_21 ( void )
{
int V_33 ;
V_34 = F_22 ( L_5 , NULL ) ;
if ( ! V_34 )
return - V_15 ;
for ( V_33 = 0 ; V_33 < F_23 ( V_35 ) ; V_33 ++ ) {
V_35 [ V_33 ] . V_36 = F_24 ( V_35 [ V_33 ] . V_37 ,
V_38 | V_39 ,
V_34 ,
& V_19 ,
V_35 [ V_33 ] . V_40 ) ;
if ( ! V_35 [ V_33 ] . V_36 )
goto V_41;
}
return 0 ;
V_41:
while ( -- V_33 >= 0 )
F_25 ( V_35 [ V_33 ] . V_36 ) ;
F_25 ( V_34 ) ;
V_34 = NULL ;
return - V_42 ;
}
static void T_4 F_26 ( void )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < F_23 ( V_35 ) ; V_33 ++ )
F_25 ( V_35 [ V_33 ] . V_36 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_25 ( V_34 ) ;
V_34 = NULL ;
}
