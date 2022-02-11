static int F_1 ( char * V_1 ,
T_1 * * V_2 , unsigned V_3 )
{
T_1 * V_4 ;
V_4 = V_5 ;
while( V_4 -> V_6 )
{
if( ( V_3 == strlen ( V_4 -> V_6 ) ) && ! strncmp ( V_4 -> V_6 , V_1 ,
V_3 ) )
{
* V_2 = V_4 ;
return 0 ;
}
V_4 ++ ;
}
return 1 ;
}
static int F_2 ( unsigned V_7 ,
T_1 * * V_2 )
{
T_1 * V_4 ;
V_4 = V_5 ;
while( V_4 -> V_6 )
{
if( V_4 -> V_8 == V_7 )
{
* V_2 = V_4 ;
return 0 ;
}
V_4 ++ ;
}
return 1 ;
}
int F_3 ( T_2 * V_9 , const char * V_10 )
{
return F_4 ( V_10 , & V_9 -> V_11 ) ;
}
int F_5 ( T_3 * V_12 , const char * V_10 )
{
return F_4 ( V_10 , & V_12 -> V_11 ) ;
}
int F_6 ( T_3 * V_12 , unsigned char * V_4 , int * V_3 , int V_13 )
{
int V_14 = 0 ;
int V_15 ;
F_7 ( T_1 ) * V_16 = 0 ;
T_1 * V_17 ;
V_16 = F_8 ( V_12 ) ;
V_14 = F_9 ( V_16 ) ;
if( V_4 )
{
if( V_14 == 0 )
{
F_10 ( V_18 , V_19 ) ;
return 1 ;
}
if( ( 2 + V_14 * 2 + 1 ) > V_13 )
{
F_10 ( V_18 , V_20 ) ;
return 1 ;
}
F_11 ( V_14 * 2 , V_4 ) ;
for( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
{
V_17 = F_12 ( V_16 , V_15 ) ;
F_11 ( V_17 -> V_8 , V_4 ) ;
}
* V_4 ++ = 0 ;
}
* V_3 = 2 + V_14 * 2 + 1 ;
return 0 ;
}
int F_13 ( T_3 * V_12 , unsigned char * V_21 , int V_3 , int * V_22 )
{
T_1 * V_23 , * V_24 ;
F_7 ( T_1 ) * V_16 = 0 , * V_25 ;
int V_14 ;
int V_26 ;
int V_15 , V_27 ;
int V_8 ;
int V_28 ;
if( V_3 < 3 )
{
F_10 ( V_29 , V_30 ) ;
* V_22 = V_31 ;
return 1 ;
}
F_14 ( V_21 , V_14 ) ;
V_3 -= 2 ;
if( V_14 % 2 )
{
F_10 ( V_29 , V_30 ) ;
* V_22 = V_31 ;
return 1 ;
}
if( V_3 < ( V_14 + 1 ) )
{
F_10 ( V_29 , V_30 ) ;
* V_22 = V_31 ;
return 1 ;
}
V_16 = F_15 () ;
while( V_14 )
{
F_14 ( V_21 , V_8 ) ;
V_14 -= 2 ;
V_3 -= 2 ;
if( ! F_2 ( V_8 , & V_23 ) )
{
F_16 ( V_16 , V_23 ) ;
}
else
{
;
}
}
V_26 = * V_21 ;
V_21 ++ ; V_3 -- ;
if ( V_26 != V_3 )
{
F_10 ( V_29 , V_32 ) ;
* V_22 = V_31 ;
return 1 ;
}
V_25 = F_8 ( V_12 ) ;
for( V_15 = 0 ; V_15 < F_9 ( V_25 ) ; V_15 ++ )
{
V_24 = F_12 ( V_25 , V_15 ) ;
for( V_27 = 0 ; V_27 < F_9 ( V_16 ) ; V_27 ++ )
{
V_23 = F_12 ( V_16 , V_27 ) ;
if( V_23 -> V_8 == V_24 -> V_8 )
{
V_12 -> V_33 = V_24 ;
* V_22 = 0 ;
V_28 = 0 ;
goto V_34;
}
}
}
V_28 = 0 ;
V_34:
if( V_16 ) F_17 ( V_16 ) ;
return V_28 ;
}
int F_18 ( T_3 * V_12 , unsigned char * V_4 , int * V_3 , int V_13 )
{
if( V_4 )
{
if( V_13 < 5 )
{
F_10 ( V_35 , V_20 ) ;
return 1 ;
}
if( V_12 -> V_33 == 0 )
{
F_10 ( V_35 , V_36 ) ;
return 1 ;
}
F_11 ( 2 , V_4 ) ;
F_11 ( V_12 -> V_33 -> V_8 , V_4 ) ;
* V_4 ++ = 0 ;
}
* V_3 = 5 ;
return 0 ;
}
int F_19 ( T_3 * V_12 , unsigned char * V_21 , int V_3 , int * V_22 )
{
unsigned V_8 ;
int V_15 ;
int V_14 ;
F_7 ( T_1 ) * V_16 ;
T_1 * V_17 ;
if( V_3 != 5 )
{
F_10 ( V_37 , V_30 ) ;
* V_22 = V_31 ;
return 1 ;
}
F_14 ( V_21 , V_14 ) ;
if( V_14 != 2 )
{
F_10 ( V_37 , V_30 ) ;
* V_22 = V_31 ;
return 1 ;
}
F_14 ( V_21 , V_8 ) ;
if ( * V_21 )
{
F_10 ( V_37 , V_32 ) ;
* V_22 = V_38 ;
return 1 ;
}
V_16 = F_8 ( V_12 ) ;
if ( V_16 == NULL )
{
F_10 ( V_37 , V_39 ) ;
* V_22 = V_31 ;
return 1 ;
}
for( V_15 = 0 ; V_15 < F_9 ( V_16 ) ; V_15 ++ )
{
V_17 = F_12 ( V_16 , V_15 ) ;
if( V_17 -> V_8 == V_8 )
{
V_12 -> V_33 = V_17 ;
* V_22 = 0 ;
return 0 ;
}
}
F_10 ( V_37 , V_30 ) ;
* V_22 = V_31 ;
return 1 ;
}
