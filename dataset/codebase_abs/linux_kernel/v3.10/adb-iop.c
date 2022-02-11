static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = 1 ;
V_5 = V_2 -> V_6 ;
if ( V_2 -> V_7 ) (* V_2 -> V_7 )( V_2 ) ;
V_8 = V_3 ;
}
static void F_2 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
unsigned long V_11 ;
F_3 ( V_11 ) ;
V_2 = V_5 ;
if ( ( V_8 == V_12 ) && V_2 && V_2 -> V_13 ) {
V_8 = V_14 ;
}
F_4 ( V_11 ) ;
}
static void F_5 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 -> V_17 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
#ifdef F_6
int V_18 ;
#endif
F_3 ( V_11 ) ;
V_2 = V_5 ;
#ifdef F_6
F_7 ( L_1 , V_2 ,
( V_19 ) V_16 -> V_20 + 2 , ( V_19 ) V_16 -> V_11 , ( V_19 ) V_16 -> V_21 ) ;
for ( V_18 = 0 ; V_18 < V_16 -> V_20 ; V_18 ++ )
F_7 ( L_2 , ( V_19 ) V_16 -> V_22 [ V_18 ] ) ;
F_7 ( L_3 ) ;
#endif
if ( V_16 -> V_11 & V_23 ) {
V_10 -> V_24 [ 0 ] = V_23 | V_25 ;
V_10 -> V_24 [ 1 ] = 0 ;
V_10 -> V_24 [ 2 ] = 0 ;
if ( V_2 && ( V_8 != V_26 ) ) {
F_1 ( V_2 , V_26 ) ;
}
} else {
if ( ( V_8 == V_14 ) &&
( V_16 -> V_11 & V_27 ) ) {
V_2 -> V_28 = V_16 -> V_20 + 1 ;
memcpy ( V_2 -> V_24 , & V_16 -> V_21 , V_2 -> V_28 ) ;
} else {
F_8 ( & V_16 -> V_21 , V_16 -> V_20 + 1 ,
V_16 -> V_11 & V_25 ) ;
}
memcpy ( V_10 -> V_24 , V_10 -> V_17 , V_29 ) ;
}
F_9 ( V_10 ) ;
F_4 ( V_11 ) ;
}
static void F_10 ( void )
{
unsigned long V_11 ;
struct V_1 * V_2 ;
struct V_15 V_16 ;
#ifdef F_6
int V_18 ;
#endif
V_2 = V_5 ;
if ( ! V_2 ) return;
F_3 ( V_11 ) ;
#ifdef F_6
F_7 ( L_4 , V_2 , V_2 -> V_30 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_30 ; V_18 ++ )
F_7 ( L_2 , ( V_19 ) V_2 -> V_22 [ V_18 ] ) ;
F_7 ( L_3 ) ;
#endif
V_16 . V_11 = V_27 ;
V_16 . V_20 = V_2 -> V_30 - 2 ;
memcpy ( & V_16 . V_21 , V_2 -> V_22 + 1 , V_2 -> V_30 - 1 ) ;
V_2 -> V_31 = 1 ;
V_8 = V_12 ;
F_4 ( V_11 ) ;
F_11 ( V_32 , V_33 , V_2 ,
sizeof( V_16 ) , ( V_34 * ) & V_16 , F_2 ) ;
}
int F_12 ( void )
{
if ( ! V_35 ) return - V_36 ;
return 0 ;
}
int F_13 ( void )
{
F_7 ( L_5 ) ;
F_14 ( V_32 , V_33 , F_5 , L_6 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , int V_37 )
{
int V_38 ;
V_38 = F_16 ( V_2 ) ;
if ( V_38 ) return V_38 ;
if ( V_37 ) {
while ( ! V_2 -> V_4 ) F_17 () ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
if ( ( V_2 -> V_30 < 2 ) || ( V_2 -> V_22 [ 0 ] != V_39 ) ) {
V_2 -> V_4 = 1 ;
return - V_40 ;
}
F_3 ( V_11 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_31 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_28 = 0 ;
if ( V_5 != 0 ) {
V_41 -> V_6 = V_2 ;
V_41 = V_2 ;
} else {
V_5 = V_2 ;
V_41 = V_2 ;
}
F_4 ( V_11 ) ;
if ( V_8 == V_26 ) F_10 () ;
return 0 ;
}
int F_18 ( int V_42 )
{
return 0 ;
}
void F_17 ( void )
{
if ( V_8 == V_26 ) F_10 () ;
F_19 ( 0 , ( void * ) V_32 ) ;
}
int F_20 ( void )
{
struct V_1 V_2 = {
. V_13 = 0 ,
. V_30 = 2 ,
. V_22 = { V_39 , 0 } ,
} ;
F_16 ( & V_2 ) ;
while ( ! V_2 . V_4 ) {
F_17 () ;
F_21 () ;
}
return 0 ;
}
