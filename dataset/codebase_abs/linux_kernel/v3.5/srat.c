static T_1 int F_1 ( int V_1 )
{
return F_2 ( V_1 ) ;
}
static T_1 void F_3 ( void )
{
F_4 ( V_2 L_1 ) ;
V_3 = - 1 ;
}
static T_1 inline int F_5 ( void )
{
return V_3 < 0 ;
}
void T_1 F_6 ( struct V_4 * V_5 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ )
F_7 ( F_8 ( V_6 ) , F_8 ( V_7 ) ,
V_5 -> V_9 [ V_5 -> V_8 * V_6 + V_7 ] ) ;
}
void T_1
F_9 ( struct V_10 * V_11 )
{
int V_1 , V_12 ;
int V_13 ;
if ( F_5 () )
return;
if ( V_11 -> V_14 . V_15 < sizeof( struct V_10 ) ) {
F_3 () ;
return;
}
if ( ( V_11 -> V_16 & V_17 ) == 0 )
return;
V_1 = V_11 -> V_18 ;
V_13 = V_11 -> V_13 ;
if ( ! V_19 -> V_20 ( V_13 ) ) {
F_4 ( V_21 L_2 ,
V_1 , V_13 ) ;
return;
}
V_12 = F_1 ( V_1 ) ;
if ( V_12 < 0 ) {
F_4 ( V_2 L_3 , V_1 ) ;
F_3 () ;
return;
}
if ( V_13 >= V_22 ) {
F_4 ( V_21 L_4 , V_1 , V_13 , V_12 ) ;
return;
}
F_10 ( V_13 , V_12 ) ;
F_11 ( V_12 , V_23 ) ;
V_3 = 1 ;
F_4 ( V_21 L_5 ,
V_1 , V_13 , V_12 ) ;
}
void T_1
F_12 ( struct V_24 * V_11 )
{
int V_1 , V_12 ;
int V_13 ;
if ( F_5 () )
return;
if ( V_11 -> V_14 . V_15 != sizeof( struct V_24 ) ) {
F_3 () ;
return;
}
if ( ( V_11 -> V_16 & V_17 ) == 0 )
return;
V_1 = V_11 -> V_25 ;
if ( V_26 >= 2 )
V_1 |= * ( ( unsigned int * ) V_11 -> V_27 ) << 8 ;
V_12 = F_1 ( V_1 ) ;
if ( V_12 < 0 ) {
F_4 ( V_2 L_3 , V_1 ) ;
F_3 () ;
return;
}
if ( F_13 () >= V_28 )
V_13 = ( V_11 -> V_13 << 8 ) | V_11 -> V_29 ;
else
V_13 = V_11 -> V_13 ;
if ( V_13 >= V_22 ) {
F_4 ( V_21 L_6 , V_1 , V_13 , V_12 ) ;
return;
}
F_10 ( V_13 , V_12 ) ;
F_11 ( V_12 , V_23 ) ;
V_3 = 1 ;
F_4 ( V_21 L_7 ,
V_1 , V_13 , V_12 ) ;
}
static inline int F_14 ( void ) { return 1 ; }
static inline int F_14 ( void ) { return 0 ; }
void T_1
F_15 ( struct V_30 * V_31 )
{
T_2 V_32 , V_33 ;
int V_12 , V_1 ;
if ( F_5 () )
return;
if ( V_31 -> V_14 . V_15 != sizeof( struct V_30 ) ) {
F_3 () ;
return;
}
if ( ( V_31 -> V_16 & V_34 ) == 0 )
return;
if ( ( V_31 -> V_16 & V_35 ) && ! F_14 () )
return;
V_32 = V_31 -> V_36 ;
V_33 = V_32 + V_31 -> V_15 ;
V_1 = V_31 -> V_18 ;
if ( V_26 <= 1 )
V_1 &= 0xff ;
V_12 = F_1 ( V_1 ) ;
if ( V_12 < 0 ) {
F_4 ( V_2 L_8 ) ;
F_3 () ;
return;
}
if ( F_16 ( V_12 , V_32 , V_33 ) < 0 ) {
F_3 () ;
return;
}
F_11 ( V_12 , V_23 ) ;
F_4 ( V_21 L_9 ,
V_12 , V_1 ,
( unsigned long long ) V_32 , ( unsigned long long ) V_33 - 1 ) ;
}
void T_1 F_17 ( void ) {}
int T_1 F_18 ( void )
{
int V_37 ;
V_37 = F_19 () ;
if ( V_37 < 0 )
return V_37 ;
return F_5 () ? - V_38 : 0 ;
}
