static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 [ V_6 + 1 ] ;
struct V_7 * V_8 ;
const struct V_3 * V_9 ;
int V_10 , V_11 , V_12 ;
if ( ! F_2 ( V_2 -> V_13 ,
V_14 |
V_15 ) )
return - V_16 ;
V_12 = F_3 ( V_2 , V_17 ,
V_5 ) ;
if ( V_12 < 0 ) {
F_4 ( & V_2 -> V_18 , L_1 ) ;
return V_12 ;
}
V_5 [ V_12 ] = '\0' ;
F_5 ( & V_2 -> V_18 , L_2 , V_5 ) ;
for ( V_9 = V_19 ; V_9 -> V_20 [ 0 ] ; V_9 ++ ) {
if ( ! strncasecmp ( V_9 -> V_20 , V_5 , strlen ( V_9 -> V_20 ) ) )
break;
}
if ( ! V_9 -> V_20 [ 0 ] ) {
F_4 ( & V_2 -> V_18 , L_3 ) ;
return - V_16 ;
}
if ( V_4 -> V_21 != V_22 && V_4 -> V_21 != V_9 -> V_21 )
F_6 ( & V_2 -> V_18 ,
L_4 ,
V_4 -> V_20 , V_9 -> V_20 ) ;
V_8 = F_7 ( sizeof( struct V_7 ) , V_23 ) ;
if ( ! V_8 )
return - V_24 ;
V_12 = F_3 ( V_2 , V_25 ,
V_5 ) ;
if ( V_12 < 0 ) {
F_4 ( & V_2 -> V_18 , L_5 ) ;
goto V_26;
}
V_8 -> V_27 = 0 ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
if ( ! V_5 [ V_10 ] )
break;
V_8 -> V_27 ++ ;
}
if ( ! V_8 -> V_27 ) {
F_4 ( & V_2 -> V_18 , L_6 ) ;
V_12 = - V_16 ;
goto V_26;
}
F_5 ( & V_2 -> V_18 , L_7 , V_8 -> V_27 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_27 ; V_10 ++ ) {
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_12 = F_8 ( V_2 , V_28 , V_10 ) ;
if ( V_12 < 0 )
continue;
V_12 = F_8 ( V_2 , V_29 ,
0xff ) ;
if ( V_12 < 0 )
continue;
break;
}
if ( V_12 < 0 ) {
F_4 ( & V_2 -> V_18 ,
L_8 ) ;
goto V_26;
}
}
if ( V_8 -> V_27 > 1 )
F_8 ( V_2 , V_28 , 0 ) ;
V_8 -> V_30 [ 0 ] = V_31 | V_32 |
V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 | V_40 |
V_41 | V_42 ;
for ( V_10 = 1 ; V_10 < V_8 -> V_27 ; V_10 ++ )
V_8 -> V_30 [ V_10 ] = V_35 | V_36 |
V_37 | V_38 |
V_39 |
V_41 | V_42 ;
if ( V_9 -> V_21 == V_43 )
V_8 -> V_30 [ 0 ] |= V_44 | V_45 ;
V_12 = F_9 ( V_2 , V_9 , V_8 ) ;
if ( V_12 < 0 )
goto V_26;
return 0 ;
V_26:
F_10 ( V_8 ) ;
return V_12 ;
}
static int F_11 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 ;
V_8 = F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_10 ( V_8 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_46 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_46 ) ;
}
