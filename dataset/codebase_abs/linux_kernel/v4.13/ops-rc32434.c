static inline int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 , unsigned int V_4 ,
unsigned char V_5 , T_1 * V_6 )
{
unsigned int V_7 = F_2 ( V_4 ) ;
T_2 V_8 = F_3 ( V_4 ) ;
F_4 ( V_3 -> V_9 , V_7 , V_8 , V_5 ) ;
F_5 () ;
if ( V_1 == V_10 )
V_11 -> V_12 = * V_6 ;
else
* V_6 = V_11 -> V_12 ;
F_5 () ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , T_2 * V_13 )
{
T_1 V_6 ;
int V_14 ;
V_14 = F_1 ( V_15 , V_3 , V_4 , V_5 , & V_6 ) ;
* V_13 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
return V_14 ;
}
static int F_7 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , T_3 * V_13 )
{
T_1 V_6 ;
int V_14 ;
V_14 = F_1 ( V_15 , V_3 , V_4 , V_5 , & V_6 ) ;
* V_13 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
return V_14 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , T_1 * V_13 )
{
int V_14 ;
int V_16 = 1 ;
if ( V_3 -> V_9 == 0 && F_2 ( V_4 ) > 21 )
return 0 ;
V_17:
V_14 = F_1 ( V_15 , V_3 , V_4 , V_5 , V_13 ) ;
if ( V_5 == V_18 ) {
if ( V_14 == 0xffffffff || V_14 == 0x00000000 ||
V_14 == 0x0000ffff || V_14 == 0xffff0000 ) {
if ( V_16 > 4 )
return 0 ;
V_16 *= 2 ;
F_9 ( V_16 ) ;
goto V_17;
}
}
return V_14 ;
}
static int
F_10 ( struct V_2 * V_3 , unsigned int V_4 , int V_5 ,
T_2 V_13 )
{
T_1 V_6 = 0 ;
if ( F_1 ( V_15 , V_3 , V_4 , V_5 , & V_6 ) )
return - 1 ;
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_13 << ( ( V_5 & 3 ) << 3 ) ) ;
if ( F_1 ( V_10 , V_3 , V_4 , V_5 , & V_6 ) )
return - 1 ;
return V_19 ;
}
static int
F_11 ( struct V_2 * V_3 , unsigned int V_4 , int V_5 ,
T_3 V_13 )
{
T_1 V_6 = 0 ;
if ( F_1 ( V_15 , V_3 , V_4 , V_5 , & V_6 ) )
return - 1 ;
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_13 << ( ( V_5 & 3 ) << 3 ) ) ;
if ( F_1 ( V_10 , V_3 , V_4 , V_5 , & V_6 ) )
return - 1 ;
return V_19 ;
}
static int
F_12 ( struct V_2 * V_3 , unsigned int V_4 , int V_5 ,
T_1 V_13 )
{
if ( F_1 ( V_10 , V_3 , V_4 , V_5 , & V_13 ) )
return - 1 ;
return V_19 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 * V_13 )
{
switch ( V_20 ) {
case 1 :
return F_6 ( V_3 , V_4 , V_5 , ( T_2 * ) V_13 ) ;
case 2 :
return F_7 ( V_3 , V_4 , V_5 , ( T_3 * ) V_13 ) ;
default:
return F_8 ( V_3 , V_4 , V_5 , V_13 ) ;
}
}
static int F_14 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 V_13 )
{
switch ( V_20 ) {
case 1 :
return F_10 ( V_3 , V_4 , V_5 , ( T_2 ) V_13 ) ;
case 2 :
return F_11 ( V_3 , V_4 , V_5 , ( T_3 ) V_13 ) ;
default:
return F_12 ( V_3 , V_4 , V_5 , V_13 ) ;
}
}
