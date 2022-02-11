static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 , * V_4 ;
char * V_5 ;
struct V_6 * V_6 ;
int V_7 ;
if ( ( V_2 -> V_8 [ 0 ] != '#' ) || ( V_2 -> V_8 [ 1 ] != '!' ) )
return - V_9 ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
F_2 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_8 [ V_13 - 1 ] = '\0' ;
if ( ( V_5 = strchr ( V_2 -> V_8 , '\n' ) ) == NULL )
V_5 = V_2 -> V_8 + V_13 - 1 ;
* V_5 = '\0' ;
while ( V_5 > V_2 -> V_8 ) {
V_5 -- ;
if ( ( * V_5 == ' ' ) || ( * V_5 == '\t' ) )
* V_5 = '\0' ;
else
break;
}
for ( V_5 = V_2 -> V_8 + 2 ; ( * V_5 == ' ' ) || ( * V_5 == '\t' ) ; V_5 ++ ) ;
if ( * V_5 == '\0' )
return - V_9 ;
V_4 = V_5 ;
V_3 = NULL ;
for ( ; * V_5 && ( * V_5 != ' ' ) && ( * V_5 != '\t' ) ; V_5 ++ )
;
while ( ( * V_5 == ' ' ) || ( * V_5 == '\t' ) )
* V_5 ++ = '\0' ;
if ( * V_5 )
V_3 = V_5 ;
V_7 = F_4 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( 1 , & V_2 -> V_14 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_15 ++ ;
if ( V_3 ) {
V_7 = F_5 ( 1 , & V_3 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_15 ++ ;
}
V_7 = F_5 ( 1 , & V_4 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_15 ++ ;
V_7 = F_6 ( V_4 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = F_7 ( V_4 ) ;
if ( F_8 ( V_6 ) )
return F_9 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_7 = F_10 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_11 ( V_2 ) ;
}
static int T_1 F_12 ( void )
{
F_13 ( & V_16 ) ;
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_16 ) ;
}
