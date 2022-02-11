static struct V_1 * F_1 ( struct V_2 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_1 * V_7 ;
T_1 V_8 [ 2 ] ;
if ( ! regexec ( & V_5 -> V_9 , V_3 , 2 , V_8 , 0 ) )
V_7 = & V_10 ;
else if ( ! regexec ( & V_5 -> V_11 , V_3 , 2 , V_8 , 0 ) )
V_7 = & V_12 ;
else if ( ! strcmp ( V_3 , L_1 ) )
V_7 = & V_13 ;
else
return NULL ;
F_2 ( V_2 , V_3 , V_7 ) ;
return V_7 ;
}
static int F_3 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
int V_14 ;
if ( V_2 -> V_15 )
return 0 ;
V_5 = F_4 ( sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - 1 ;
V_14 = regcomp ( & V_5 -> V_11 , L_2 , V_16 ) ;
if ( V_14 )
goto V_17;
V_14 = regcomp ( & V_5 -> V_9 , L_3 ,
V_16 ) ;
if ( V_14 )
goto V_18;
V_2 -> V_15 = true ;
V_2 -> V_6 = V_5 ;
V_2 -> V_19 = F_1 ;
V_2 -> V_20 . V_21 = '/' ;
V_2 -> V_20 . V_22 = '+' ;
return 0 ;
V_18:
regfree ( & V_5 -> V_11 ) ;
V_17:
free ( V_5 ) ;
return - 1 ;
}
