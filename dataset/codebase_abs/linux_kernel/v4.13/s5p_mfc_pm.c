int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_4 = & V_2 -> V_4 ;
V_5 = V_2 ;
V_4 -> V_6 = V_2 -> V_7 -> V_6 ;
V_4 -> V_8 = V_2 -> V_7 -> V_8 ;
V_4 -> V_9 = & V_2 -> V_10 -> V_2 ;
V_4 -> V_11 = NULL ;
for ( V_3 = 0 ; V_3 < V_4 -> V_6 ; V_3 ++ ) {
V_4 -> V_12 [ V_3 ] = F_2 ( V_4 -> V_9 , V_4 -> V_8 [ V_3 ] ) ;
if ( F_3 ( V_4 -> V_12 [ V_3 ] ) ) {
F_4 ( L_1 ,
V_4 -> V_8 [ V_3 ] ) ;
return F_5 ( V_4 -> V_12 [ V_3 ] ) ;
}
}
if ( V_2 -> V_7 -> V_13 )
V_4 -> V_11 = V_4 -> V_12 [ 0 ] ;
F_6 ( V_4 -> V_9 ) ;
F_7 ( & V_14 , 0 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_4 -> V_9 ) ;
}
int F_10 ( void )
{
F_11 ( & V_14 ) ;
F_12 ( 3 , L_2 , F_13 ( & V_14 ) ) ;
return F_14 ( V_4 -> V_11 ) ;
}
void F_15 ( void )
{
F_16 ( & V_14 ) ;
F_12 ( 3 , L_3 , F_13 ( & V_14 ) ) ;
F_17 ( V_4 -> V_11 ) ;
}
int F_18 ( void )
{
int V_3 , V_15 = 0 ;
V_15 = F_19 ( V_4 -> V_9 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_6 ; V_3 ++ ) {
V_15 = F_20 ( V_4 -> V_12 [ V_3 ] ) ;
if ( V_15 < 0 ) {
F_4 ( L_4 ,
V_4 -> V_8 [ V_3 ] ) ;
V_3 ++ ;
goto V_16;
}
}
F_17 ( V_4 -> V_11 ) ;
return 0 ;
V_16:
while ( -- V_3 > 0 )
F_21 ( V_4 -> V_12 [ V_3 ] ) ;
F_22 ( V_4 -> V_9 ) ;
return V_15 ;
}
int F_23 ( void )
{
int V_3 ;
F_14 ( V_4 -> V_11 ) ;
for ( V_3 = 0 ; V_3 < V_4 -> V_6 ; V_3 ++ )
F_21 ( V_4 -> V_12 [ V_3 ] ) ;
return F_24 ( V_4 -> V_9 ) ;
}
