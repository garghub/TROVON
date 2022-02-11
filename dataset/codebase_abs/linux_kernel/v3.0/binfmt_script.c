static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const char * V_5 , * V_6 ;
char * V_7 ;
struct V_8 * V_8 ;
char V_9 [ V_10 ] ;
int V_11 ;
if ( ( V_2 -> V_12 [ 0 ] != '#' ) || ( V_2 -> V_12 [ 1 ] != '!' ) ||
( V_2 -> V_13 > V_14 ) )
return - V_15 ;
V_2 -> V_13 ++ ;
F_2 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_12 [ V_10 - 1 ] = '\0' ;
if ( ( V_7 = strchr ( V_2 -> V_12 , '\n' ) ) == NULL )
V_7 = V_2 -> V_12 + V_10 - 1 ;
* V_7 = '\0' ;
while ( V_7 > V_2 -> V_12 ) {
V_7 -- ;
if ( ( * V_7 == ' ' ) || ( * V_7 == '\t' ) )
* V_7 = '\0' ;
else
break;
}
for ( V_7 = V_2 -> V_12 + 2 ; ( * V_7 == ' ' ) || ( * V_7 == '\t' ) ; V_7 ++ ) ;
if ( * V_7 == '\0' )
return - V_15 ;
V_6 = V_7 ;
V_5 = NULL ;
for ( ; * V_7 && ( * V_7 != ' ' ) && ( * V_7 != '\t' ) ; V_7 ++ )
;
while ( ( * V_7 == ' ' ) || ( * V_7 == '\t' ) )
* V_7 ++ = '\0' ;
if ( * V_7 )
V_5 = V_7 ;
strcpy ( V_9 , V_6 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( 1 , & V_2 -> V_9 , V_2 ) ;
if ( V_11 < 0 ) return V_11 ;
V_2 -> V_16 ++ ;
if ( V_5 ) {
V_11 = F_5 ( 1 , & V_5 , V_2 ) ;
if ( V_11 < 0 ) return V_11 ;
V_2 -> V_16 ++ ;
}
V_11 = F_5 ( 1 , & V_6 , V_2 ) ;
if ( V_11 ) return V_11 ;
V_2 -> V_16 ++ ;
V_2 -> V_9 = V_9 ;
V_8 = F_6 ( V_9 ) ;
if ( F_7 ( V_8 ) )
return F_8 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_11 = F_9 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_10 ( V_2 , V_4 ) ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_17 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_17 ) ;
}
