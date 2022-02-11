static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 ,
unsigned int V_4 , int V_5 ,
T_1 * V_6 )
{
T_1 V_7 = V_3 -> V_8 ;
T_1 V_9 , type ;
T_1 V_10 ;
void * V_11 ;
int V_12 = F_2 ( V_4 ) ;
int V_13 = F_3 ( V_4 ) ;
int V_14 = V_5 & ~ 3 ;
if ( V_7 == 0 ) {
#ifdef F_4
if ( ( V_15 == V_12 ) && ( V_14 < V_16 ) ) {
switch ( V_1 ) {
case V_17 :
* V_6 = F_5 ( V_13 , V_14 ) ;
break;
case V_18 :
F_6 ( V_13 , V_14 , * V_6 ) ;
break;
}
return 0 ;
}
#endif
if ( V_12 > V_19 )
return - 1 ;
V_9 = ( 1 << ( V_12 + V_20 ) ) | ( V_13 << 8 ) | V_14 ;
type = 0 ;
} else {
V_9 = ( V_7 << 16 ) | ( V_12 << 11 ) | ( V_13 << 8 ) | V_14 ;
type = 0x10000 ;
}
V_21 |= V_22 | \
V_23 ;
V_24 = ( V_9 >> 16 ) | type ;
V_10 = V_24 ;
F_7 () ;
V_11 = F_8 ( V_9 & 0xffff ) ;
if ( V_1 == V_18 )
F_9 ( F_10 ( * V_6 ) , V_11 ) ;
else
* V_6 = F_11 ( F_12 ( V_11 ) ) ;
if ( V_21 & ( V_22 |
V_23 ) ) {
V_21 |= ( V_22 |
V_23 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_25 , T_1 * V_26 )
{
T_1 V_6 = 0 ;
if ( ( V_25 == 2 ) && ( V_5 & 1 ) )
return V_27 ;
else if ( ( V_25 == 4 ) && ( V_5 & 3 ) )
return V_27 ;
if ( F_1 ( V_17 , V_3 , V_4 , V_5 ,
& V_6 ) )
return - 1 ;
if ( V_25 == 1 )
* V_26 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_25 == 2 )
* V_26 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_26 = V_6 ;
return V_28 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_25 , T_1 V_26 )
{
T_1 V_6 = 0 ;
if ( ( V_25 == 2 ) && ( V_5 & 1 ) )
return V_27 ;
else if ( ( V_25 == 4 ) && ( V_5 & 3 ) )
return V_27 ;
if ( V_25 == 4 )
V_6 = V_26 ;
else {
if ( F_1 ( V_17 , V_3 , V_4 ,
V_5 , & V_6 ) )
return - 1 ;
if ( V_25 == 1 )
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_26 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_25 == 2 )
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_26 << ( ( V_5 & 3 ) << 3 ) ) ;
}
if ( F_1 ( V_18 , V_3 , V_4 , V_5 ,
& V_6 ) )
return - 1 ;
return V_28 ;
}
void F_15 ( T_1 V_29 , T_1 * V_30 , T_1 * V_31 )
{
struct V_2 V_3 = {
. V_8 = V_32
} ;
T_1 V_4 = F_16 ( V_15 , 0 ) ;
unsigned long V_33 ;
F_17 ( & V_34 , V_33 ) ;
F_14 ( & V_3 , V_4 , V_35 , 4 , V_29 ) ;
F_13 ( & V_3 , V_4 , V_36 , 4 , V_31 ) ;
F_13 ( & V_3 , V_4 , V_37 , 4 , V_30 ) ;
F_18 ( & V_34 , V_33 ) ;
}
void F_19 ( T_1 V_29 , T_1 V_30 , T_1 V_31 )
{
struct V_2 V_3 = {
. V_8 = V_32
} ;
T_1 V_4 = F_16 ( V_15 , 0 ) ;
unsigned long V_33 ;
F_17 ( & V_34 , V_33 ) ;
F_14 ( & V_3 , V_4 , V_35 , 4 , V_29 ) ;
F_14 ( & V_3 , V_4 , V_36 , 4 , V_31 ) ;
F_14 ( & V_3 , V_4 , V_37 , 4 , V_30 ) ;
F_18 ( & V_34 , V_33 ) ;
}
