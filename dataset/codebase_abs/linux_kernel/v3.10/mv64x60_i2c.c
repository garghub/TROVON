static int F_1 ( int V_1 )
{
int V_2 ;
int V_3 ;
for ( V_2 = 0 ; V_2 < 1000 ; V_2 ++ ) {
F_2 ( 10 ) ;
V_3 = F_3 ( ( V_4 * ) ( V_5 + V_6 ) )
& 0xff ;
if ( V_3 == V_1 )
return V_3 ;
}
return - V_3 ;
}
static int F_4 ( int V_7 , int V_3 )
{
F_5 ( ( V_4 * ) ( V_5 + V_8 ) , V_7 & 0xff ) ;
return F_1 ( V_3 ) ;
}
static int F_6 ( int V_7 , int V_3 )
{
F_5 ( ( V_4 * ) ( V_5 + V_8 ) , V_7 & 0xff ) ;
if ( F_1 ( V_3 ) < 0 )
return - 1 ;
return F_3 ( ( V_4 * ) ( V_5 + V_9 ) ) & 0xff ;
}
static int F_7 ( int V_10 , int V_7 , int V_3 )
{
F_5 ( ( V_4 * ) ( V_5 + V_9 ) , V_10 & 0xff ) ;
F_5 ( ( V_4 * ) ( V_5 + V_8 ) , V_7 & 0xff ) ;
return F_1 ( V_3 ) ;
}
int F_8 ( V_4 V_11 , T_1 * V_12 , V_4 V_13 , V_4 V_14 ,
V_4 V_15 )
{
int V_2 ;
int V_10 ;
int V_7 ;
int V_3 ;
if ( V_5 == NULL )
return - 1 ;
F_5 ( ( V_4 * ) ( V_5 + V_16 ) , 0 ) ;
F_5 ( ( V_4 * ) ( V_5 + V_17 ) , 0 ) ;
F_5 ( ( V_4 * ) ( V_5 + V_18 ) , 0 ) ;
F_5 ( ( V_4 * ) ( V_5 + V_19 ) , ( 4 << 3 ) | 0x4 ) ;
if ( F_4 ( V_20 ,
V_21 ) < 0 )
return - 1 ;
V_7 = V_22 | V_20 ;
V_3 = V_23 ;
if ( F_4 ( V_7 , V_3 ) < 0 )
return - 1 ;
V_10 = V_11 & ~ 0x1 ;
V_7 = V_20 ;
V_3 = V_24 ;
if ( F_7 ( V_10 , V_7 , V_3 ) < 0 )
return - 1 ;
V_7 = V_20 ;
V_3 = V_25 ;
if ( V_14 > 1 ) {
if ( F_7 ( V_13 >> 8 , V_7 , V_3 ) < 0 )
return - 1 ;
}
if ( F_7 ( V_13 , V_7 , V_3 ) < 0 )
return - 1 ;
V_7 = V_22 | V_20 ;
V_3 = V_26 ;
if ( F_4 ( V_7 , V_3 ) < 0 )
return - 1 ;
V_10 = V_11 | 0x1 ;
V_7 = V_20 ;
V_3 = V_27 ;
if ( F_7 ( V_10 , V_7 , V_3 ) < 0 )
return - 1 ;
V_7 = V_28 | V_20 ;
V_3 = V_29 ;
for ( V_2 = 1 ; V_2 < V_15 ; V_2 ++ ) {
V_10 = F_6 ( V_7 , V_3 ) ;
if ( V_10 < 0 ) {
printf ( L_1 , V_2 ) ;
return - 1 ;
}
* V_12 ++ = V_10 ;
}
V_7 = V_20 ;
V_3 = V_30 ;
V_10 = F_6 ( V_7 , V_3 ) ;
if ( V_10 < 0 )
return - 1 ;
* V_12 ++ = V_10 ;
V_7 = V_31 | V_20 ;
V_3 = V_21 ;
if ( F_4 ( V_7 , V_3 ) < 0 )
return - 1 ;
return V_15 ;
}
int F_9 ( void )
{
V_4 V_32 ;
void * V_33 ;
V_33 = F_10 ( NULL , L_2 ) ;
if ( V_33 == NULL )
goto V_34;
if ( F_11 ( V_33 , L_3 , & V_32 , sizeof( V_32 ) ) != sizeof( V_32 ) )
goto V_34;
V_5 = ( T_1 * ) V_32 ;
return 0 ;
V_34:
return - 1 ;
}
void F_12 ( void )
{
V_5 = NULL ;
}
