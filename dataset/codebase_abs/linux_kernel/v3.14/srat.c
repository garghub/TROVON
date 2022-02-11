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
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ ) {
if ( F_7 ( V_6 ) == V_9 )
continue;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ ) {
if ( F_7 ( V_7 ) == V_9 )
continue;
F_8 ( F_7 ( V_6 ) , F_7 ( V_7 ) ,
V_5 -> V_10 [ V_5 -> V_8 * V_6 + V_7 ] ) ;
}
}
}
void T_1
F_9 ( struct V_11 * V_12 )
{
int V_1 , V_13 ;
int V_14 ;
if ( F_5 () )
return;
if ( V_12 -> V_15 . V_16 < sizeof( struct V_11 ) ) {
F_3 () ;
return;
}
if ( ( V_12 -> V_17 & V_18 ) == 0 )
return;
V_1 = V_12 -> V_19 ;
V_14 = V_12 -> V_14 ;
if ( ! V_20 -> V_21 ( V_14 ) ) {
F_4 ( V_22 L_2 ,
V_1 , V_14 ) ;
return;
}
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 ) {
F_4 ( V_2 L_3 , V_1 ) ;
F_3 () ;
return;
}
if ( V_14 >= V_23 ) {
F_4 ( V_22 L_4 , V_1 , V_14 , V_13 ) ;
return;
}
F_10 ( V_14 , V_13 ) ;
F_11 ( V_13 , V_24 ) ;
V_3 = 1 ;
F_4 ( V_22 L_5 ,
V_1 , V_14 , V_13 ) ;
}
void T_1
F_12 ( struct V_25 * V_12 )
{
int V_1 , V_13 ;
int V_14 ;
if ( F_5 () )
return;
if ( V_12 -> V_15 . V_16 != sizeof( struct V_25 ) ) {
F_3 () ;
return;
}
if ( ( V_12 -> V_17 & V_18 ) == 0 )
return;
V_1 = V_12 -> V_26 ;
if ( V_27 >= 2 )
V_1 |= * ( ( unsigned int * ) V_12 -> V_28 ) << 8 ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 ) {
F_4 ( V_2 L_3 , V_1 ) ;
F_3 () ;
return;
}
if ( F_13 () >= V_29 )
V_14 = ( V_12 -> V_14 << 8 ) | V_12 -> V_30 ;
else
V_14 = V_12 -> V_14 ;
if ( V_14 >= V_23 ) {
F_4 ( V_22 L_6 , V_1 , V_14 , V_13 ) ;
return;
}
F_10 ( V_14 , V_13 ) ;
F_11 ( V_13 , V_24 ) ;
V_3 = 1 ;
F_4 ( V_22 L_7 ,
V_1 , V_14 , V_13 ) ;
}
static inline int F_14 ( void ) { return 1 ; }
static inline int F_14 ( void ) { return 0 ; }
int T_1
F_15 ( struct V_31 * V_32 )
{
T_2 V_33 , V_34 ;
T_3 V_35 ;
int V_13 , V_1 ;
if ( F_5 () )
goto V_36;
if ( V_32 -> V_15 . V_16 != sizeof( struct V_31 ) )
goto V_37;
if ( ( V_32 -> V_17 & V_38 ) == 0 )
goto V_36;
V_35 = V_32 -> V_17 & V_39 ;
if ( V_35 && ! F_14 () )
goto V_36;
V_33 = V_32 -> V_40 ;
V_34 = V_33 + V_32 -> V_16 ;
V_1 = V_32 -> V_19 ;
if ( V_27 <= 1 )
V_1 &= 0xff ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 ) {
F_4 ( V_2 L_8 ) ;
goto V_37;
}
if ( F_16 ( V_13 , V_33 , V_34 ) < 0 )
goto V_37;
F_11 ( V_13 , V_24 ) ;
F_17 ( L_9 ,
V_13 , V_1 ,
( unsigned long long ) V_33 , ( unsigned long long ) V_34 - 1 ,
V_35 ? L_10 : L_11 ) ;
if ( V_35 && F_18 ( V_33 , V_32 -> V_16 ) )
F_19 ( L_12 ,
( unsigned long long ) V_33 , ( unsigned long long ) V_34 - 1 ) ;
return 0 ;
V_37:
F_3 () ;
V_36:
return - 1 ;
}
void T_1 F_20 ( void ) {}
int T_1 F_21 ( void )
{
int V_41 ;
V_41 = F_22 () ;
if ( V_41 < 0 )
return V_41 ;
return F_5 () ? - V_42 : 0 ;
}
