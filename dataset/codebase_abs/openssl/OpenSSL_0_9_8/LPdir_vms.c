const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
int V_3 ;
char * V_4 , * V_5 ;
T_2 V_6 ;
unsigned long V_7 = 0 ;
#ifdef F_2
V_7 |= V_8 ;
#endif
if ( V_1 == NULL || V_2 == NULL )
{
V_9 = V_10 ;
return 0 ;
}
V_9 = 0 ;
if ( * V_1 == NULL )
{
T_2 V_11 = strlen ( V_2 ) ;
char * V_12 = NULL ;
if ( V_2 [ V_11 - 1 ] != ']'
&& V_2 [ V_11 - 1 ] != '>'
&& V_2 [ V_11 - 1 ] != ':' )
{
V_9 = V_10 ;
return 0 ;
}
V_11 += 4 ;
if ( V_11 >
#ifdef F_2
F_2
#else
255
#endif
)
{
V_9 = V_13 ;
return 0 ;
}
* V_1 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( * V_1 == NULL )
{
V_9 = V_14 ;
return 0 ;
}
memset ( * V_1 , '\0' , sizeof( T_1 ) ) ;
strcpy ( ( * V_1 ) -> V_12 , V_2 ) ;
strcat ( ( * V_1 ) -> V_12 , L_1 ) ;
( * V_1 ) -> V_15 . V_16 = V_11 ;
( * V_1 ) -> V_15 . V_17 = V_18 ;
( * V_1 ) -> V_15 . V_19 = V_20 ;
( * V_1 ) -> V_15 . V_21 = ( * V_1 ) -> V_12 ;
( * V_1 ) -> V_22 . V_16 = 0 ;
( * V_1 ) -> V_22 . V_17 = V_18 ;
( * V_1 ) -> V_22 . V_19 = V_23 ;
( * V_1 ) -> V_22 . V_21 = 0 ;
}
( * V_1 ) -> V_22 . V_16 = 0 ;
( * V_1 ) -> V_22 . V_17 = V_18 ;
( * V_1 ) -> V_22 . V_19 = V_23 ;
( * V_1 ) -> V_22 . V_21 = 0 ;
V_3 = F_3 ( & ( * V_1 ) -> V_15 , & ( * V_1 ) -> V_22 ,
& ( * V_1 ) -> V_24 , 0 , 0 , 0 , & V_7 ) ;
if ( V_3 == V_25 )
{
V_9 = 0 ;
V_26 = V_3 ;
return NULL ;
}
if( ! F_4 ( V_3 ) )
{
V_9 = V_27 ;
V_26 = V_3 ;
return NULL ;
}
V_6 = ( * V_1 ) -> V_22 . V_16 ;
V_4 = ( * V_1 ) -> V_22 . V_21 ;
V_5 = V_4 ;
for (; * V_4 ; V_4 ++ )
{
if ( * V_4 == '^' && V_4 [ 1 ] != '\0' )
{
V_4 ++ ;
}
else if ( * V_4 == ':' || * V_4 == '>' || * V_4 == ']' )
{
V_6 -= V_4 + 1 - V_5 ;
V_5 = V_4 + 1 ;
}
else if ( * V_4 == ';' )
{
V_6 = V_4 - V_5 ;
break;
}
}
strncpy ( ( * V_1 ) -> V_28 , V_5 , V_6 ) ;
( * V_1 ) -> V_28 [ V_6 ] = '\0' ;
F_5 ( & ( * V_1 ) -> V_22 ) ;
return ( * V_1 ) -> V_28 ;
}
int F_6 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL )
{
int V_3 = F_7 ( & ( * V_1 ) -> V_24 ) ;
free ( * V_1 ) ;
if( ! F_4 ( V_3 ) )
{
V_9 = V_27 ;
V_26 = V_3 ;
return 0 ;
}
return 1 ;
}
V_9 = V_10 ;
return 0 ;
}
