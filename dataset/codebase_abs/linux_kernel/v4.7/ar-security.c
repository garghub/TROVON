int T_1 F_1 ( void )
{
int V_1 , V_2 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_3 ) ; V_1 ++ ) {
if ( V_3 [ V_1 ] ) {
V_2 = V_3 [ V_1 ] -> F_3 () ;
if ( V_2 < 0 )
goto V_4;
}
}
return 0 ;
V_4:
for ( V_1 -- ; V_1 >= 0 ; V_1 -- )
if ( V_3 [ V_1 ] )
V_3 [ V_1 ] -> exit () ;
return V_2 ;
}
void F_4 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_3 ) ; V_1 ++ )
if ( V_3 [ V_1 ] )
V_3 [ V_1 ] -> exit () ;
}
static const struct V_5 * F_5 ( T_2 V_6 )
{
if ( V_6 >= F_2 ( V_3 ) )
return NULL ;
return V_3 [ V_6 ] ;
}
int F_6 ( struct V_7 * V_8 )
{
const struct V_5 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_12 = V_8 -> V_12 ;
int V_2 ;
F_7 ( L_1 , V_8 -> V_13 , F_8 ( V_12 ) ) ;
if ( ! V_12 )
return 0 ;
V_2 = F_9 ( V_12 ) ;
if ( V_2 < 0 )
return V_2 ;
V_11 = V_12 -> V_14 . V_15 [ 0 ] ;
if ( ! V_11 )
return - V_16 ;
V_9 = F_5 ( V_11 -> V_6 ) ;
if ( ! V_9 )
return - V_16 ;
V_8 -> V_17 = V_9 ;
V_2 = V_8 -> V_17 -> V_18 ( V_8 ) ;
if ( V_2 < 0 ) {
V_8 -> V_17 = & V_19 ;
return V_2 ;
}
F_10 ( L_2 ) ;
return 0 ;
}
int F_11 ( struct V_7 * V_8 )
{
const struct V_5 * V_9 ;
struct V_20 * V_21 = V_8 -> V_22 -> V_21 ;
struct V_23 * V_24 ;
struct V_12 * V_12 ;
T_3 V_25 ;
char V_26 [ 5 + 1 + 3 + 1 ] ;
F_7 ( L_3 ) ;
sprintf ( V_26 , L_4 , V_8 -> V_27 , V_8 -> V_28 ) ;
V_9 = F_5 ( V_8 -> V_28 ) ;
if ( ! V_9 ) {
F_10 ( L_5 ) ;
return - V_29 ;
}
F_12 ( & V_21 -> V_30 ) ;
F_13 (rx, &local->services, listen_link) {
if ( V_24 -> V_31 . V_32 == V_8 -> V_27 )
goto V_33;
}
F_14 ( & V_21 -> V_30 ) ;
F_10 ( L_6 ) ;
return - V_34 ;
V_33:
if ( ! V_24 -> V_35 ) {
F_14 ( & V_21 -> V_30 ) ;
F_10 ( L_7 ) ;
return - V_29 ;
}
V_25 = F_15 ( F_16 ( V_24 -> V_35 , 1UL ) ,
& V_36 , V_26 ) ;
if ( F_17 ( V_25 ) ) {
F_14 ( & V_21 -> V_30 ) ;
F_10 ( L_8 , F_18 ( V_25 ) ) ;
return F_18 ( V_25 ) ;
}
V_12 = F_19 ( V_25 ) ;
F_14 ( & V_21 -> V_30 ) ;
V_8 -> V_37 = V_12 ;
V_8 -> V_17 = V_9 ;
F_10 ( L_2 ) ;
return 0 ;
}
