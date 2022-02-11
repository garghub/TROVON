void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = F_2 ( V_2 -> V_5 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_4 ( V_2 ) ;
free ( V_2 -> V_7 ) ;
V_2 -> V_7 = V_8 ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_5 += V_6 ;
V_2 -> V_7 = realloc ( V_2 -> V_7 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_7 )
F_6 ( L_1 ) ;
}
int
F_7 ( struct V_1 * V_2 , const char * V_9 , ... )
{
T_1 V_10 ;
int V_3 ;
int V_11 ;
F_4 ( V_2 ) ;
V_12:
V_3 = ( V_2 -> V_5 - 1 ) - V_2 -> V_3 ;
va_start ( V_10 , V_9 ) ;
V_11 = vsnprintf ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_9 , V_10 ) ;
va_end ( V_10 ) ;
if ( V_11 >= V_3 ) {
F_5 ( V_2 ) ;
goto V_12;
}
V_2 -> V_3 += V_11 ;
return 1 ;
}
int
F_8 ( struct V_1 * V_2 , const char * V_9 , T_1 args )
{
int V_3 ;
int V_11 ;
F_4 ( V_2 ) ;
V_12:
V_3 = ( V_2 -> V_5 - 1 ) - V_2 -> V_3 ;
V_11 = vsnprintf ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_9 , args ) ;
if ( V_11 >= V_3 ) {
F_5 ( V_2 ) ;
goto V_12;
}
V_2 -> V_3 += V_11 ;
return V_3 ;
}
int F_9 ( struct V_1 * V_2 , const char * V_13 )
{
int V_3 ;
F_4 ( V_2 ) ;
V_3 = strlen ( V_13 ) ;
while ( V_3 > ( ( V_2 -> V_5 - 1 ) - V_2 -> V_3 ) )
F_5 ( V_2 ) ;
memcpy ( V_2 -> V_7 + V_2 -> V_3 , V_13 , V_3 ) ;
V_2 -> V_3 += V_3 ;
return V_3 ;
}
int F_10 ( struct V_1 * V_2 , unsigned char V_14 )
{
F_4 ( V_2 ) ;
while ( V_2 -> V_3 >= ( V_2 -> V_5 - 1 ) )
F_5 ( V_2 ) ;
V_2 -> V_7 [ V_2 -> V_3 ++ ] = V_14 ;
return 1 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
V_2 -> V_7 [ V_2 -> V_3 ] = 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return printf ( L_2 , V_2 -> V_3 , V_2 -> V_7 ) ;
}
