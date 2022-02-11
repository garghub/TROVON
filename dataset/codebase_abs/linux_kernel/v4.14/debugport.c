static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = { 0 } ;
T_2 V_4 = { 0 } ;
T_3 V_5 = { 0 } ;
T_4 V_6 = { 0 } ;
T_5 V_7 = { 0 } ;
if ( ! V_2 || V_2 -> V_8 )
return;
V_2 -> V_8 = 1 ;
if ( V_2 -> V_9 == 1 )
F_2 ( V_10 ) ;
else if ( V_2 -> V_9 == 2 )
F_2 ( V_11 ) ;
else if ( V_2 -> V_9 == 3 )
F_2 ( V_12 ) ;
#if V_13 == 5
else if ( V_2 -> V_9 == 4 )
F_2 ( V_14 ) ;
#endif
V_3 . V_15 = V_5 . V_15 = V_16 ;
V_4 . V_17 = V_5 . V_18 = V_19 ;
V_6 . div = V_7 . div = 29493000 / V_2 -> V_20 / 8 ;
V_3 . V_17 = V_5 . V_17 = 1 ;
if ( V_2 -> V_21 == 'O' ) {
V_3 . V_22 = V_23 ;
V_3 . V_24 = V_25 ;
V_5 . V_22 = V_23 ;
V_5 . V_24 = V_25 ;
} else if ( V_2 -> V_21 == 'E' ) {
V_3 . V_22 = V_23 ;
V_3 . V_24 = V_26 ;
V_5 . V_22 = V_23 ;
V_5 . V_24 = V_25 ;
}
if ( V_2 -> V_27 == 7 ) {
V_3 . V_28 = V_29 ;
V_5 . V_28 = V_29 ;
}
F_3 ( V_30 , V_2 -> V_31 , V_32 , V_6 ) ;
F_3 ( V_30 , V_2 -> V_31 , V_33 , V_7 ) ;
F_3 ( V_30 , V_2 -> V_31 , V_34 , V_4 ) ;
F_3 ( V_30 , V_2 -> V_31 , V_35 , V_3 ) ;
F_3 ( V_30 , V_2 -> V_31 , V_36 , V_5 ) ;
}
int F_4 ( void )
{
T_6 V_37 ;
T_7 V_38 = { 0 } ;
do {
V_37 = F_5 ( V_30 , V_39 -> V_31 , V_40 ) ;
} while ( ! V_37 . V_41 );
V_38 . V_41 = 1 ;
F_3 ( V_30 , V_39 -> V_31 , V_42 , V_38 ) ;
return V_37 . V_43 ;
}
void F_6 ( int V_44 )
{
T_8 V_37 ;
do {
V_37 = F_5 ( V_30 , V_39 -> V_31 , V_45 ) ;
} while ( ! V_37 . V_46 );
F_7 ( V_30 , V_39 -> V_31 , V_47 , V_44 ) ;
}
static void T_9 F_8 ( int V_48 )
{
T_8 V_37 ;
do
V_37 = F_5 ( V_30 , V_49 -> V_31 , V_45 ) ;
while ( ! V_37 . V_46 );
F_7 ( V_30 , V_49 -> V_31 , V_47 , V_48 ) ;
}
static void T_9
F_9 ( struct V_50 * V_51 , const char * V_52 , unsigned V_53 )
{
extern void V_54 ( void ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
if ( V_52 [ V_55 ] == '\n' )
F_8 ( '\r' ) ;
F_8 ( V_52 [ V_55 ] ) ;
V_54 () ;
}
}
int T_9 F_10 ( void )
{
F_1 ( V_49 ) ;
F_11 ( & V_56 ) ;
#ifdef F_12
F_1 ( V_39 ) ;
#endif
return 0 ;
}
