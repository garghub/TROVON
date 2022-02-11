static int F_1 ( unsigned int V_1 , unsigned int V_2 , int V_3 )
{
if ( ( V_2 > 255 ) || ( V_3 > 255 ) )
return V_4 ;
if ( V_1 == 0 && V_2 >= F_2 ( 8 , 0 ) )
return V_5 ;
* ( volatile V_6 * ) V_7 =
( ( V_1 & 0xff ) << 16 ) |
( ( V_2 & 0xff ) << 8 ) |
( V_3 & 0xfc ) ;
return V_8 ;
}
static int F_3 ( struct V_9 * V_10 , unsigned int V_2 , int V_3 ,
int V_11 , V_6 * V_12 )
{
int V_13 ;
if ( ( V_13 = F_1 ( V_10 -> V_14 , V_2 , V_3 ) ) )
return V_13 ;
switch ( V_11 ) {
case 1 :
* V_12 = F_4 ( V_15 + ( V_3 & 3 ) ) ;
break;
case 2 :
* V_12 = F_5 ( V_15 + ( V_3 & 2 ) ) ;
break;
case 4 :
* V_12 = F_6 ( V_15 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_9 * V_10 , unsigned int V_2 , int V_3 ,
int V_11 , V_6 V_12 )
{
int V_13 ;
if ( ( V_13 = F_1 ( V_10 -> V_14 , V_2 , V_3 ) ) )
return V_13 ;
switch ( V_11 ) {
case 1 :
F_8 ( V_12 , V_15 + ( V_3 & 3 ) ) ;
break;
case 2 :
F_9 ( V_12 , V_15 + ( V_3 & 2 ) ) ;
break;
case 4 :
F_10 ( V_12 , V_15 ) ;
break;
}
return 0 ;
}
static int F_11 ( unsigned int V_1 , unsigned int V_2 , int V_3 )
{
if ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_1 > 255 ) )
return V_4 ;
F_10 ( ( 1 << 31 ) | ( ( V_1 & 0xff ) << 16 ) | ( ( V_2 & 0xff ) << 8 ) | ( V_3 & 0xfc ) , 0xcf8 ) ;
return V_8 ;
}
static int F_12 ( struct V_9 * V_10 , unsigned int V_2 , int V_3 ,
int V_11 , V_6 * V_12 )
{
int V_13 ;
if ( V_10 -> V_14 == 0 ) {
F_11 ( 0 , 0 , 0x68 ) ;
F_10 ( F_6 ( 0xcfc ) | 0xc0000000 , 0xcfc ) ;
if ( ( V_13 = F_11 ( 0 , V_2 , 0 ) ) )
return V_13 ;
F_10 ( 0xffffffff , 0xcfc ) ;
F_11 ( 0 , 0 , 0x68 ) ;
if ( F_6 ( 0xcfc ) & 0x100000 )
return V_5 ;
}
if ( ( V_13 = F_11 ( V_10 -> V_14 , V_2 , V_3 ) ) )
return V_13 ;
switch ( V_11 ) {
case 1 :
* V_12 = F_4 ( V_15 + ( V_3 & 3 ) ) ;
break;
case 2 :
* V_12 = F_5 ( V_15 + ( V_3 & 2 ) ) ;
break;
case 4 :
* V_12 = F_6 ( V_15 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , unsigned int V_2 , int V_3 ,
int V_11 , V_6 V_12 )
{
int V_13 ;
if ( ( V_13 = F_11 ( V_10 -> V_14 , V_2 , V_3 ) ) )
return V_13 ;
switch ( V_11 ) {
case 1 :
F_8 ( V_12 , V_15 + ( V_3 & 3 ) ) ;
break;
case 2 :
F_9 ( V_12 , V_15 + ( V_3 & 2 ) ) ;
break;
case 4 :
F_10 ( V_12 , V_15 ) ;
break;
}
return 0 ;
}
