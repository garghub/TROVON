static int F_1 ( void * V_1 , const char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 ;
V_6 = F_2 ( V_5 , V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_3 ;
}
static int F_3 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 , const void * V_2 , int V_3 )
{
int V_6 ;
if ( ! F_4 ( V_8 , V_9 ) &&
V_9 < V_8 -> V_11 -> V_12 &&
! V_8 -> V_13 ) {
V_6 = F_5 ( V_8 , V_9 , V_10 ) ;
if ( V_6 < 0 )
return - 1 ;
}
if ( V_8 -> V_14 ) {
V_8 -> V_15 = 1 ;
return 0 ;
}
V_6 = V_8 -> V_16 ( V_8 -> V_17 , V_2 , V_3 ) ;
if ( V_6 == V_3 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
static unsigned int F_6 ( struct V_7 * V_8 , unsigned int V_9 )
{
int V_6 ;
unsigned int V_19 ;
if ( V_9 >= V_8 -> V_11 -> V_12 ||
F_4 ( V_8 , V_9 ) ||
V_8 -> V_13 ) {
if ( V_8 -> V_14 )
return - 1 ;
F_7 ( ! V_8 -> F_6 ) ;
return V_8 -> F_6 ( V_8 , V_9 ) ;
}
V_6 = F_8 ( V_8 , V_9 , & V_19 ) ;
if ( V_6 < 0 )
return - 1 ;
return V_19 ;
}
static int F_9 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_1 V_2 ;
V_2 = F_10 ( ( V_9 << 12 ) | ( V_10 & 0xffffff ) ) ;
return F_3 ( V_8 , V_9 , V_10 , & V_2 , 2 ) ;
}
static int F_11 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_1 V_2 ;
V_2 = F_10 ( ( V_9 << 9 ) | ( V_10 & 0x1ff ) ) ;
return F_3 ( V_8 , V_9 , V_10 , & V_2 , 2 ) ;
}
static int F_12 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 2 ] ;
V_9 &= 0xff ;
V_2 [ 0 ] = V_9 ;
V_2 [ 1 ] = V_10 & 0xff ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 2 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 3 ] ;
T_1 V_19 = F_10 ( V_10 ) ;
V_2 [ 0 ] = V_9 ;
memcpy ( & V_2 [ 1 ] , & V_19 , sizeof( V_19 ) ) ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 3 ) ;
}
static unsigned int F_14 ( struct V_7 * V_8 ,
void * V_9 , int V_20 ,
void * V_2 , int V_21 )
{
struct V_22 V_23 [ 2 ] ;
int V_6 ;
struct V_24 * V_25 = V_8 -> V_17 ;
V_23 [ 0 ] . V_26 = V_25 -> V_26 ;
V_23 [ 0 ] . V_27 = 0 ;
V_23 [ 0 ] . V_3 = V_20 ;
V_23 [ 0 ] . V_28 = V_9 ;
V_23 [ 1 ] . V_26 = V_25 -> V_26 ;
V_23 [ 1 ] . V_27 = V_29 ;
V_23 [ 1 ] . V_3 = V_21 ;
V_23 [ 1 ] . V_28 = V_2 ;
V_6 = F_15 ( V_25 -> V_30 , V_23 , 2 ) ;
if ( V_6 == 2 )
return 0 ;
else if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
static unsigned int F_16 ( struct V_7 * V_8 ,
unsigned int V_31 )
{
T_2 V_9 = V_31 ;
T_2 V_2 ;
int V_6 ;
V_6 = F_14 ( V_8 , & V_9 , 1 , & V_2 , 1 ) ;
if ( V_6 < 0 )
return 0 ;
return V_2 ;
}
static unsigned int F_17 ( struct V_7 * V_8 ,
unsigned int V_31 )
{
T_2 V_9 = V_31 ;
T_1 V_2 ;
int V_6 ;
V_6 = F_14 ( V_8 , & V_9 , 1 , & V_2 , 2 ) ;
if ( V_6 < 0 )
return 0 ;
return ( V_2 >> 8 ) | ( ( V_2 & 0xff ) << 8 ) ;
}
static unsigned int F_18 ( struct V_7 * V_8 ,
unsigned int V_31 )
{
T_1 V_9 = V_31 ;
T_2 V_2 ;
int V_6 ;
V_6 = F_14 ( V_8 , & V_9 , 2 , & V_2 , 1 ) ;
if ( V_6 < 0 )
return 0 ;
return V_2 ;
}
static unsigned int F_19 ( struct V_7 * V_8 ,
unsigned int V_31 )
{
struct V_4 * V_5 = V_8 -> V_17 ;
const T_1 V_9 = F_10 ( V_31 | 0x100 ) ;
T_2 V_2 ;
int V_6 ;
V_6 = F_20 ( V_5 , & V_9 , 2 , & V_2 , 1 ) ;
if ( V_6 < 0 )
return 0 ;
return V_2 ;
}
static int F_21 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 3 ] ;
T_1 V_32 = F_10 ( V_9 ) ;
memcpy ( V_2 , & V_32 , sizeof( V_32 ) ) ;
V_2 [ 2 ] = V_10 ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 3 ) ;
}
static unsigned int F_22 ( struct V_7 * V_8 ,
unsigned int V_31 )
{
T_1 V_9 = F_10 ( V_31 ) ;
T_1 V_2 ;
int V_6 ;
V_6 = F_14 ( V_8 , & V_9 , 2 , & V_2 , 2 ) ;
if ( V_6 < 0 )
return 0 ;
return F_23 ( V_2 ) ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_1 V_2 [ 2 ] ;
V_2 [ 0 ] = F_10 ( V_9 ) ;
V_2 [ 1 ] = F_10 ( V_10 ) ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , sizeof( V_2 ) ) ;
}
static int F_25 ( struct V_7 * V_8 , unsigned int V_9 ,
const void * V_2 , T_3 V_3 )
{
int V_6 ;
if ( ! V_8 -> V_13
&& ! F_4 ( V_8 , V_9 )
&& V_9 < V_8 -> V_11 -> V_12 )
return - V_33 ;
switch ( V_8 -> V_34 ) {
#if F_26 ( V_35 ) || ( F_26 ( V_36 ) && F_26 ( V_37 ) )
case V_38 :
V_6 = F_27 ( F_28 ( V_8 -> V_39 ) , V_2 , V_3 ) ;
break;
#endif
#if F_26 ( V_40 )
case V_41 :
V_6 = F_2 ( F_29 ( V_8 -> V_39 ) , V_2 , V_3 ) ;
break;
#endif
default:
F_30 () ;
}
if ( V_6 == V_3 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
int F_31 ( struct V_7 * V_8 ,
int V_42 , int V_43 ,
enum V_44 V_1 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_32 ( V_46 ) ; V_45 ++ )
if ( V_46 [ V_45 ] . V_42 == V_42 &&
V_46 [ V_45 ] . V_43 == V_43 )
break;
if ( V_45 == F_32 ( V_46 ) ) {
F_33 ( V_47
L_1 ,
V_42 , V_43 ) ;
return - V_33 ;
}
V_8 -> V_48 = V_46 [ V_45 ] . V_48 ;
V_8 -> V_49 = F_6 ;
V_8 -> V_50 = F_25 ;
switch ( V_1 ) {
case V_38 :
#if F_26 ( V_35 ) || ( F_26 ( V_36 ) && F_26 ( V_37 ) )
V_8 -> V_16 = ( V_51 ) F_27 ;
#endif
if ( V_46 [ V_45 ] . V_52 )
V_8 -> F_6 = V_46 [ V_45 ] . V_52 ;
V_8 -> V_17 = F_34 ( V_8 -> V_39 ,
struct V_24 ,
V_39 ) ;
break;
case V_41 :
#ifdef V_40
V_8 -> V_16 = F_1 ;
#endif
if ( V_46 [ V_45 ] . V_53 )
V_8 -> F_6 = V_46 [ V_45 ] . V_53 ;
V_8 -> V_17 = F_34 ( V_8 -> V_39 ,
struct V_4 ,
V_39 ) ;
break;
}
return 0 ;
}
