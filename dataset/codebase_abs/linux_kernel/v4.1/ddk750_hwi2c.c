int F_1 (
unsigned char V_1
)
{
unsigned int V_2 ;
V_2 = F_2 ( V_3 ) ;
V_2 = F_3 ( V_2 , V_3 , 30 , V_4 ) |
F_3 ( 0 , V_3 , 31 , V_4 ) ;
F_4 ( V_3 , V_2 ) ;
F_5 ( 1 ) ;
V_2 = F_2 ( V_5 ) ;
if ( V_1 == 0 )
V_2 = F_3 ( V_2 , V_5 , V_6 , V_7 ) ;
else
V_2 = F_3 ( V_2 , V_5 , V_6 , V_8 ) ;
V_2 = F_3 ( V_2 , V_5 , V_9 , V_10 ) ;
F_4 ( V_5 , V_2 ) ;
return 0 ;
}
void F_6 ( void )
{
unsigned int V_2 ;
V_2 = F_2 ( V_5 ) ;
V_2 = F_3 ( V_2 , V_5 , V_9 , V_11 ) ;
F_4 ( V_5 , V_2 ) ;
F_5 ( 0 ) ;
V_2 = F_2 ( V_3 ) ;
V_2 = F_3 ( V_2 , V_3 , 30 , V_12 ) ;
V_2 = F_3 ( V_2 , V_3 , 31 , V_12 ) ;
F_4 ( V_3 , V_2 ) ;
}
static long F_7 ( void )
{
unsigned int V_13 ;
V_13 = V_14 ;
while ( ( F_8 ( F_2 ( V_15 ) , V_15 , V_16 ) != V_17 ) &&
( V_13 != 0 ) )
V_13 -- ;
if ( V_13 == 0 )
return ( - 1 ) ;
return 0 ;
}
static unsigned int F_9 (
unsigned char V_18 ,
unsigned int V_19 ,
unsigned char * V_20
)
{
unsigned char V_21 , V_22 ;
unsigned int V_23 = 0 ;
F_4 ( V_24 , V_18 & ~ 0x01 ) ;
do
{
F_4 ( V_25 , 0 ) ;
if ( V_19 < V_26 )
V_21 = V_19 - 1 ;
else
V_21 = V_26 - 1 ;
F_4 ( V_27 , V_21 ) ;
for ( V_22 = 0 ; V_22 <= V_21 ; V_22 ++ )
F_4 ( V_28 + V_22 , * V_20 ++ ) ;
F_4 ( V_5 , F_3 ( F_2 ( V_5 ) , V_5 , V_29 , V_30 ) ) ;
if ( F_7 () != 0 )
break;
V_19 -= ( V_21 + 1 ) ;
V_23 += ( V_21 + 1 ) ;
} while ( V_19 > 0 );
return V_23 ;
}
static unsigned int F_10 (
unsigned char V_18 ,
unsigned int V_19 ,
unsigned char * V_20
)
{
unsigned char V_21 , V_22 ;
unsigned int V_23 = 0 ;
F_4 ( V_24 , V_18 | 0x01 ) ;
do
{
F_4 ( V_25 , 0 ) ;
if ( V_19 <= V_26 )
V_21 = V_19 - 1 ;
else
V_21 = V_26 - 1 ;
F_4 ( V_27 , V_21 ) ;
F_4 ( V_5 , F_3 ( F_2 ( V_5 ) , V_5 , V_29 , V_30 ) ) ;
if ( F_7 () != 0 )
break;
for ( V_22 = 0 ; V_22 <= V_21 ; V_22 ++ )
* V_20 ++ = F_2 ( V_28 + V_22 ) ;
V_19 -= ( V_21 + 1 ) ;
V_23 += ( V_21 + 1 ) ;
} while ( V_19 > 0 );
return V_23 ;
}
unsigned char F_11 (
unsigned char V_18 ,
unsigned char V_31
)
{
unsigned char V_2 = ( 0xFF ) ;
if ( F_9 ( V_18 , 1 , & V_31 ) == 1 )
F_10 ( V_18 , 1 , & V_2 ) ;
return V_2 ;
}
int F_12 (
unsigned char V_18 ,
unsigned char V_31 ,
unsigned char V_32
)
{
unsigned char V_2 [ 2 ] ;
V_2 [ 0 ] = V_31 ;
V_2 [ 1 ] = V_32 ;
if ( F_9 ( V_18 , 2 , V_2 ) == 2 )
return 0 ;
return ( - 1 ) ;
}
