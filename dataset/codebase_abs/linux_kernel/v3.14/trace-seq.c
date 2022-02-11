void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = malloc ( V_2 -> V_5 ) ;
if ( V_2 -> V_7 != NULL )
V_2 -> V_8 = V_9 ;
else
V_2 -> V_8 = V_10 ;
}
void F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_3 ( V_2 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_5 ( V_2 ) ;
free ( V_2 -> V_7 ) ;
V_2 -> V_7 = V_11 ;
}
static void F_6 ( struct V_1 * V_2 )
{
char * V_12 ;
V_12 = realloc ( V_2 -> V_7 , V_2 -> V_5 + V_6 ) ;
if ( F_7 ( ! V_12 , L_1 ) ) {
V_2 -> V_8 = V_10 ;
return;
}
V_2 -> V_7 = V_12 ;
V_2 -> V_5 += V_6 ;
}
int
F_8 ( struct V_1 * V_2 , const char * V_13 , ... )
{
T_1 V_14 ;
int V_3 ;
int V_15 ;
V_16:
F_9 ( V_2 ) ;
V_3 = ( V_2 -> V_5 - 1 ) - V_2 -> V_3 ;
va_start ( V_14 , V_13 ) ;
V_15 = vsnprintf ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_13 , V_14 ) ;
va_end ( V_14 ) ;
if ( V_15 >= V_3 ) {
F_6 ( V_2 ) ;
goto V_16;
}
V_2 -> V_3 += V_15 ;
return 1 ;
}
int
F_10 ( struct V_1 * V_2 , const char * V_13 , T_1 args )
{
int V_3 ;
int V_15 ;
V_16:
F_9 ( V_2 ) ;
V_3 = ( V_2 -> V_5 - 1 ) - V_2 -> V_3 ;
V_15 = vsnprintf ( V_2 -> V_7 + V_2 -> V_3 , V_3 , V_13 , args ) ;
if ( V_15 >= V_3 ) {
F_6 ( V_2 ) ;
goto V_16;
}
V_2 -> V_3 += V_15 ;
return V_3 ;
}
int F_11 ( struct V_1 * V_2 , const char * V_17 )
{
int V_3 ;
F_9 ( V_2 ) ;
V_3 = strlen ( V_17 ) ;
while ( V_3 > ( ( V_2 -> V_5 - 1 ) - V_2 -> V_3 ) )
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
memcpy ( V_2 -> V_7 + V_2 -> V_3 , V_17 , V_3 ) ;
V_2 -> V_3 += V_3 ;
return V_3 ;
}
int F_12 ( struct V_1 * V_2 , unsigned char V_18 )
{
F_9 ( V_2 ) ;
while ( V_2 -> V_3 >= ( V_2 -> V_5 - 1 ) )
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_7 [ V_2 -> V_3 ++ ] = V_18 ;
return 1 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
V_2 -> V_7 [ V_2 -> V_3 ] = 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
return printf ( L_2 , V_2 -> V_3 , V_2 -> V_7 ) ;
case V_19 :
puts ( L_3 ) ;
break;
case V_10 :
puts ( L_1 ) ;
break;
}
return - 1 ;
}
