static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
char * V_5 ;
V_5 = F_2 ( sizeof( char ) * ( V_6 + 1 ) , V_7 ) ;
if ( ! V_5 ) {
F_3 ( V_5 ) ;
return - V_8 ;
}
snprintf ( V_5 , ( V_6 + 1 ) , L_1 , V_2 -> V_4 , 1 ) ;
V_4 -> V_9 = V_5 ;
V_4 -> V_10 = V_2 -> V_10 ;
V_4 -> V_11 = 0 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_14 ;
if ( V_15 )
return;
V_15 = 1 ;
for (; V_2 -> V_4 ; V_2 ++ ) {
V_13 = V_2 -> V_13 ;
if ( ! V_13 )
continue;
V_14 = F_5 ( V_13 ) ;
if ( V_14 )
F_6 ( L_2 ) ;
}
}
static void T_1 F_7 ( struct V_1 * V_16 ,
int V_17 )
{
struct V_18 * V_19 ;
struct V_18 * V_20 [ 1 ] ;
struct V_21 * V_22 ;
struct V_12 * V_13 ;
char V_23 [ V_24 ] ;
struct V_3 * V_25 ;
struct V_26 * V_27 ;
char * V_9 ;
int V_14 ;
V_25 = F_2 ( sizeof( * V_25 ) , V_7 ) ;
if ( ! V_25 )
return;
V_14 = F_1 ( V_16 , V_25 ) ;
if ( V_14 < 0 )
goto V_28;
V_9 = L_3 ;
V_14 = snprintf ( V_23 , V_24 ,
L_4 , V_17 ) ;
F_8 ( V_14 >= V_24 ,
L_5 , V_17 ) ;
V_19 = F_9 ( V_23 ) ;
if ( ! V_19 ) {
F_6 ( L_6 , V_23 ) ;
goto V_29;
}
V_20 [ 0 ] = V_19 ;
if ( V_19 -> V_30 != NULL ) {
V_27 = V_19 -> V_30 ;
V_25 -> V_31 = V_27 -> V_32 ;
}
V_13 = F_10 ( V_9 , V_17 - 1 ) ;
if ( ! V_13 ) {
F_6 ( L_7 , V_9 ) ;
goto V_29;
}
F_11 ( & V_13 -> V_33 , L_8 , V_13 -> V_9 , V_13 -> V_34 ) ;
V_22 = F_12 ( V_13 , V_20 , 1 ) ;
if ( F_13 ( V_22 ) ) {
F_6 ( L_9 , V_9 ) ;
goto V_35;
}
V_14 = F_14 ( V_13 , V_25 ,
sizeof( struct V_3 ) ) ;
if ( V_14 ) {
F_6 ( L_10 , V_9 ) ;
goto V_35;
}
V_16 -> V_13 = V_13 ;
V_14 = F_5 ( V_13 ) ;
if ( V_14 ) {
F_6 ( L_11 , V_9 ) ;
goto V_36;
}
goto V_28;
V_36:
F_15 ( V_22 ) ;
V_35:
F_16 ( V_13 ) ;
V_29:
F_3 ( V_25 -> V_9 ) ;
V_28:
F_3 ( V_25 ) ;
}
void T_1 F_17 ( struct V_1 * V_37 )
{
if ( V_15 )
return;
V_15 = 1 ;
if ( F_18 () ) {
V_38 = V_39 ;
V_40 = V_41 ;
} else {
V_38 = V_42 ;
V_40 = V_43 ;
}
for (; V_37 -> V_4 ; V_37 ++ )
F_7 ( V_37 , V_37 -> V_4 ) ;
}
