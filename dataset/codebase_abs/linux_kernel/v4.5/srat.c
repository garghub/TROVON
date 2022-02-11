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
const int V_9 = F_7 ( V_6 ) ;
if ( V_9 == V_10 )
continue;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ ) {
const int V_11 = F_7 ( V_7 ) ;
if ( V_11 == V_10 )
continue;
F_8 ( V_9 , V_11 ,
V_5 -> V_12 [ V_5 -> V_8 * V_6 + V_7 ] ) ;
}
}
}
void T_1
F_9 ( struct V_13 * V_14 )
{
int V_1 , V_15 ;
int V_16 ;
if ( F_5 () )
return;
if ( V_14 -> V_17 . V_18 < sizeof( struct V_13 ) ) {
F_3 () ;
return;
}
if ( ( V_14 -> V_19 & V_20 ) == 0 )
return;
V_1 = V_14 -> V_21 ;
V_16 = V_14 -> V_16 ;
if ( ! V_22 -> V_23 ( V_16 ) ) {
F_4 ( V_24 L_2 ,
V_1 , V_16 ) ;
return;
}
V_15 = F_1 ( V_1 ) ;
if ( V_15 < 0 ) {
F_4 ( V_2 L_3 , V_1 ) ;
F_3 () ;
return;
}
if ( V_16 >= V_25 ) {
F_4 ( V_24 L_4 , V_1 , V_16 , V_15 ) ;
return;
}
F_10 ( V_16 , V_15 ) ;
F_11 ( V_15 , V_26 ) ;
V_3 = 1 ;
F_4 ( V_24 L_5 ,
V_1 , V_16 , V_15 ) ;
}
void T_1
F_12 ( struct V_27 * V_14 )
{
int V_1 , V_15 ;
int V_16 ;
if ( F_5 () )
return;
if ( V_14 -> V_17 . V_18 != sizeof( struct V_27 ) ) {
F_3 () ;
return;
}
if ( ( V_14 -> V_19 & V_20 ) == 0 )
return;
V_1 = V_14 -> V_28 ;
if ( V_29 >= 2 )
V_1 |= * ( ( unsigned int * ) V_14 -> V_30 ) << 8 ;
V_15 = F_1 ( V_1 ) ;
if ( V_15 < 0 ) {
F_4 ( V_2 L_3 , V_1 ) ;
F_3 () ;
return;
}
if ( F_13 () >= V_31 )
V_16 = ( V_14 -> V_16 << 8 ) | V_14 -> V_32 ;
else
V_16 = V_14 -> V_16 ;
if ( V_16 >= V_25 ) {
F_4 ( V_24 L_6 , V_1 , V_16 , V_15 ) ;
return;
}
F_10 ( V_16 , V_15 ) ;
F_11 ( V_15 , V_26 ) ;
V_3 = 1 ;
F_4 ( V_24 L_7 ,
V_1 , V_16 , V_15 ) ;
}
static inline int F_14 ( void ) { return 1 ; }
static inline int F_14 ( void ) { return 0 ; }
int T_1
F_15 ( struct V_33 * V_34 )
{
T_2 V_35 , V_36 ;
T_3 V_37 ;
int V_15 , V_1 ;
if ( F_5 () )
goto V_38;
if ( V_34 -> V_17 . V_18 != sizeof( struct V_33 ) )
goto V_39;
if ( ( V_34 -> V_19 & V_40 ) == 0 )
goto V_38;
V_37 = V_34 -> V_19 & V_41 ;
if ( V_37 && ! F_14 () )
goto V_38;
V_35 = V_34 -> V_42 ;
V_36 = V_35 + V_34 -> V_18 ;
V_1 = V_34 -> V_21 ;
if ( V_29 <= 1 )
V_1 &= 0xff ;
V_15 = F_1 ( V_1 ) ;
if ( V_15 < 0 ) {
F_4 ( V_2 L_8 ) ;
goto V_39;
}
if ( F_16 ( V_15 , V_35 , V_36 ) < 0 )
goto V_39;
F_11 ( V_15 , V_26 ) ;
F_17 ( L_9 ,
V_15 , V_1 ,
( unsigned long long ) V_35 , ( unsigned long long ) V_36 - 1 ,
V_37 ? L_10 : L_11 ,
V_34 -> V_19 & V_43 ? L_12 : L_11 ) ;
if ( V_37 && F_18 ( V_35 , V_34 -> V_18 ) )
F_19 ( L_13 ,
( unsigned long long ) V_35 , ( unsigned long long ) V_36 - 1 ) ;
V_44 = F_20 ( V_44 , F_21 ( V_36 - 1 ) ) ;
return 0 ;
V_39:
F_3 () ;
V_38:
return - 1 ;
}
void T_1 F_22 ( void ) {}
int T_1 F_23 ( void )
{
int V_45 ;
V_45 = F_24 () ;
if ( V_45 < 0 )
return V_45 ;
return F_5 () ? - V_46 : 0 ;
}
