void F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 )
F_2 ( V_1 -> V_2 ) ;
if ( V_1 -> V_3 )
F_3 ( V_1 -> V_3 ) ;
F_3 ( V_1 ) ;
}
int F_4 ( T_1 * V_1 , T_2 * V_4 )
{
static const char V_5 [] =
L_1
L_2 ;
if ( F_5 ( V_1 -> V_2 , V_5 , F_6 ( V_4 , NULL ) ) <= 0 )
return 0 ;
if ( F_7 ( V_1 -> V_2 , V_4 ) <= 0 )
return 0 ;
V_1 -> V_6 = V_7 ;
V_1 -> V_8 = F_8 ( V_1 -> V_2 , NULL ) ;
return 1 ;
}
int F_9 ( T_1 * V_1 ,
const char * V_9 , const char * V_10 )
{
if ( ! V_9 )
return 0 ;
if ( F_10 ( V_1 -> V_2 , V_9 ) <= 0 )
return 0 ;
if ( V_10 )
{
if ( F_11 ( V_1 -> V_2 , L_3 , 2 ) != 2 )
return 0 ;
if ( F_10 ( V_1 -> V_2 , V_10 ) <= 0 )
return 0 ;
}
if ( F_11 ( V_1 -> V_2 , L_4 , 2 ) != 2 )
return 0 ;
return 1 ;
}
T_1 * F_12 ( T_3 * V_11 , char * V_12 , T_2 * V_4 ,
int V_13 )
{
static const char V_14 [] = L_5 ;
T_1 * V_1 ;
V_1 = F_13 ( sizeof( T_1 ) ) ;
V_1 -> V_6 = V_15 ;
V_1 -> V_2 = F_14 ( F_15 () ) ;
V_1 -> V_11 = V_11 ;
V_1 -> V_8 = 0 ;
if ( V_13 > 0 )
V_1 -> V_16 = V_13 ;
else
V_1 -> V_16 = V_17 ;
V_1 -> V_3 = F_13 ( V_1 -> V_16 ) ;
if ( ! V_1 -> V_3 )
return 0 ;
if ( ! V_12 )
V_12 = L_6 ;
if ( F_5 ( V_1 -> V_2 , V_14 , V_12 ) <= 0 )
return 0 ;
if ( V_4 && ! F_4 ( V_1 , V_4 ) )
return 0 ;
return V_1 ;
}
static int F_16 ( char * line )
{
int V_18 ;
char * V_19 , * V_20 , * V_21 ;
for( V_19 = line ; * V_19 && ! isspace ( ( unsigned char ) * V_19 ) ; V_19 ++ )
continue;
if( ! * V_19 )
{
F_17 ( V_22 ,
V_23 ) ;
return 0 ;
}
while( * V_19 && isspace ( ( unsigned char ) * V_19 ) )
V_19 ++ ;
if( ! * V_19 )
{
F_17 ( V_22 ,
V_23 ) ;
return 0 ;
}
for( V_20 = V_19 ; * V_20 && ! isspace ( ( unsigned char ) * V_20 ) ; V_20 ++ )
continue;
if( ! * V_20 )
{
F_17 ( V_22 ,
V_23 ) ;
return 0 ;
}
* V_20 ++ = 0 ;
V_18 = strtoul ( V_19 , & V_21 , 10 ) ;
if( * V_21 )
return 0 ;
while( * V_20 && isspace ( ( unsigned char ) * V_20 ) )
V_20 ++ ;
if( * V_20 )
{
for( V_21 = V_20 + strlen ( V_20 ) - 1 ; isspace ( ( unsigned char ) * V_21 ) ; V_21 -- )
* V_21 = 0 ;
}
if( V_18 != 200 )
{
F_17 ( V_22 , V_24 ) ;
if( ! * V_20 )
F_18 ( 2 , L_7 , V_19 ) ;
else
F_18 ( 4 , L_7 , V_19 , L_8 , V_20 ) ;
return 0 ;
}
return 1 ;
}
int F_19 ( T_4 * * V_25 , T_1 * V_1 )
{
int V_26 , V_27 ;
const unsigned char * V_19 ;
V_28:
if ( ! ( V_1 -> V_6 & V_29 ) )
{
V_27 = F_20 ( V_1 -> V_11 , V_1 -> V_3 , V_1 -> V_16 ) ;
if ( V_27 <= 0 )
{
if ( F_21 ( V_1 -> V_11 ) )
return - 1 ;
return 0 ;
}
if ( F_11 ( V_1 -> V_2 , V_1 -> V_3 , V_27 ) != V_27 )
return 0 ;
}
switch( V_1 -> V_6 )
{
case V_7 :
V_27 = F_8 ( V_1 -> V_2 , & V_19 ) ;
V_26 = F_11 ( V_1 -> V_11 ,
V_19 + ( V_27 - V_1 -> V_8 ) , V_1 -> V_8 ) ;
if ( V_26 <= 0 )
{
if ( F_21 ( V_1 -> V_11 ) )
return - 1 ;
V_1 -> V_6 = V_15 ;
return 0 ;
}
V_1 -> V_8 -= V_26 ;
if ( V_1 -> V_8 > 0 )
goto V_28;
V_1 -> V_6 = V_30 ;
( void ) F_22 ( V_1 -> V_2 ) ;
case V_30 :
V_26 = F_23 ( V_1 -> V_11 ) ;
if ( V_26 > 0 )
{
V_1 -> V_6 = V_31 ;
goto V_28;
}
if ( F_21 ( V_1 -> V_11 ) )
return - 1 ;
V_1 -> V_6 = V_15 ;
return 0 ;
case V_15 :
return 0 ;
case V_31 :
case V_32 :
V_33:
V_27 = F_8 ( V_1 -> V_2 , & V_19 ) ;
if ( ( V_27 <= 0 ) || ! memchr ( V_19 , '\n' , V_27 ) )
{
if ( V_27 >= V_1 -> V_16 )
{
V_1 -> V_6 = V_15 ;
return 0 ;
}
goto V_28;
}
V_27 = F_24 ( V_1 -> V_2 , ( char * ) V_1 -> V_3 , V_1 -> V_16 ) ;
if ( V_27 <= 0 )
{
if ( F_21 ( V_1 -> V_2 ) )
goto V_28;
V_1 -> V_6 = V_15 ;
return 0 ;
}
if ( V_27 == V_1 -> V_16 )
{
V_1 -> V_6 = V_15 ;
return 0 ;
}
if ( V_1 -> V_6 == V_31 )
{
if ( F_16 ( ( char * ) V_1 -> V_3 ) )
{
V_1 -> V_6 = V_32 ;
goto V_33;
}
else
{
V_1 -> V_6 = V_15 ;
return 0 ;
}
}
else
{
for ( V_19 = V_1 -> V_3 ; * V_19 ; V_19 ++ )
{
if ( ( * V_19 != '\r' ) && ( * V_19 != '\n' ) )
break;
}
if ( * V_19 )
goto V_33;
V_1 -> V_6 = V_34 ;
}
case V_34 :
V_27 = F_8 ( V_1 -> V_2 , & V_19 ) ;
if ( V_27 < 6 )
goto V_28;
if ( * V_19 ++ != ( V_35 | V_36 ) )
{
V_1 -> V_6 = V_15 ;
return 0 ;
}
if ( * V_19 & 0x80 )
{
V_27 = * V_19 & 0x7F ;
if ( ! V_27 || ( V_27 > 4 ) )
{
V_1 -> V_6 = V_15 ;
return 0 ;
}
V_19 ++ ;
V_1 -> V_8 = 0 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
{
V_1 -> V_8 <<= 8 ;
V_1 -> V_8 |= * V_19 ++ ;
}
if ( V_1 -> V_8 > V_37 )
{
V_1 -> V_6 = V_15 ;
return 0 ;
}
V_1 -> V_8 += V_27 + 2 ;
}
else
V_1 -> V_8 = * V_19 + 2 ;
V_1 -> V_6 = V_38 ;
case V_38 :
V_27 = F_8 ( V_1 -> V_2 , & V_19 ) ;
if ( V_27 < ( int ) V_1 -> V_8 )
goto V_28;
* V_25 = F_25 ( NULL , & V_19 , V_1 -> V_8 ) ;
if ( * V_25 )
{
V_1 -> V_6 = V_39 ;
return 1 ;
}
V_1 -> V_6 = V_15 ;
return 0 ;
break;
case V_39 :
return 1 ;
}
return 0 ;
}
T_4 * F_26 ( T_3 * V_40 , char * V_12 , T_2 * V_4 )
{
T_4 * V_41 = NULL ;
T_1 * V_42 ;
int V_43 ;
V_42 = F_12 ( V_40 , V_12 , V_4 , - 1 ) ;
do
{
V_43 = F_19 ( & V_41 , V_42 ) ;
} while ( ( V_43 == - 1 ) && F_21 ( V_40 ) );
F_1 ( V_42 ) ;
if ( V_43 )
return V_41 ;
return NULL ;
}
