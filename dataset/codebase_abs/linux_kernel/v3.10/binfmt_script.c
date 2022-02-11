static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 , * V_4 ;
char * V_5 ;
struct V_6 * V_6 ;
char V_7 [ V_8 ] ;
int V_9 ;
if ( ( V_2 -> V_10 [ 0 ] != '#' ) || ( V_2 -> V_10 [ 1 ] != '!' ) )
return - V_11 ;
F_2 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_10 [ V_8 - 1 ] = '\0' ;
if ( ( V_5 = strchr ( V_2 -> V_10 , '\n' ) ) == NULL )
V_5 = V_2 -> V_10 + V_8 - 1 ;
* V_5 = '\0' ;
while ( V_5 > V_2 -> V_10 ) {
V_5 -- ;
if ( ( * V_5 == ' ' ) || ( * V_5 == '\t' ) )
* V_5 = '\0' ;
else
break;
}
for ( V_5 = V_2 -> V_10 + 2 ; ( * V_5 == ' ' ) || ( * V_5 == '\t' ) ; V_5 ++ ) ;
if ( * V_5 == '\0' )
return - V_11 ;
V_4 = V_5 ;
V_3 = NULL ;
for ( ; * V_5 && ( * V_5 != ' ' ) && ( * V_5 != '\t' ) ; V_5 ++ )
;
while ( ( * V_5 == ' ' ) || ( * V_5 == '\t' ) )
* V_5 ++ = '\0' ;
if ( * V_5 )
V_3 = V_5 ;
strcpy ( V_7 , V_4 ) ;
V_9 = F_4 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( 1 , & V_2 -> V_7 , V_2 ) ;
if ( V_9 < 0 ) return V_9 ;
V_2 -> V_12 ++ ;
if ( V_3 ) {
V_9 = F_5 ( 1 , & V_3 , V_2 ) ;
if ( V_9 < 0 ) return V_9 ;
V_2 -> V_12 ++ ;
}
V_9 = F_5 ( 1 , & V_4 , V_2 ) ;
if ( V_9 ) return V_9 ;
V_2 -> V_12 ++ ;
V_9 = F_6 ( V_7 , V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 = F_7 ( V_7 ) ;
if ( F_8 ( V_6 ) )
return F_9 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_9 = F_10 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_11 ( V_2 ) ;
}
static int T_1 F_12 ( void )
{
F_13 ( & V_13 ) ;
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_13 ) ;
}
