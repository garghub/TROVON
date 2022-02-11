void F_1 ( int V_1 , struct V_2 * V_3 )
{
while ( -- V_1 >= 0 ) {
F_2 ( V_3 [ V_1 ] . V_4 ) ;
V_3 [ V_1 ] . V_4 = NULL ;
}
}
int T_1 F_3 ( struct V_5 * V_6 , int V_1 ,
struct V_2 * V_3 )
{
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_1 ; V_8 ++ )
V_3 [ V_8 ] . V_4 = NULL ;
for ( V_8 = 0 ; V_8 < V_1 ; V_8 ++ ) {
V_3 [ V_8 ] . V_4 = F_4 ( V_6 , V_3 [ V_8 ] . V_9 ) ;
if ( F_5 ( V_3 [ V_8 ] . V_4 ) ) {
V_7 = F_6 ( V_3 [ V_8 ] . V_4 ) ;
F_7 ( V_6 , L_1 ,
V_3 [ V_8 ] . V_9 , V_7 ) ;
V_3 [ V_8 ] . V_4 = NULL ;
goto V_10;
}
}
return 0 ;
V_10:
F_1 ( V_8 , V_3 ) ;
return V_7 ;
}
void F_8 ( int V_1 , const struct V_2 * V_3 )
{
while ( -- V_1 >= 0 )
F_9 ( V_3 [ V_1 ] . V_4 ) ;
}
int T_1 F_10 ( int V_1 ,
const struct V_2 * V_3 )
{
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_1 ; V_8 ++ ) {
V_7 = F_11 ( V_3 [ V_8 ] . V_4 ) ;
if ( V_7 ) {
F_12 ( L_2 ,
V_3 [ V_8 ] . V_9 , V_7 ) ;
goto V_10;
}
}
return 0 ;
V_10:
F_8 ( V_8 , V_3 ) ;
return V_7 ;
}
void F_13 ( int V_1 , const struct V_2 * V_3 )
{
while ( -- V_1 >= 0 )
F_14 ( V_3 [ V_1 ] . V_4 ) ;
}
int T_1 F_15 ( int V_1 , const struct V_2 * V_3 )
{
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_1 ; V_8 ++ ) {
V_7 = F_16 ( V_3 [ V_8 ] . V_4 ) ;
if ( V_7 ) {
F_12 ( L_3 ,
V_3 [ V_8 ] . V_9 , V_7 ) ;
goto V_10;
}
}
return 0 ;
V_10:
F_13 ( V_8 , V_3 ) ;
return V_7 ;
}
