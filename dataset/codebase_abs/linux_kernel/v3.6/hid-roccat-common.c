static inline T_1 F_1 ( T_2 V_1 )
{
return 0x300 | V_1 ;
}
int F_2 ( struct V_2 * V_3 , T_3 V_1 ,
void * V_4 , T_3 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_3 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_4 ( V_3 , F_5 ( V_3 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
F_1 ( V_1 ) ,
0 , V_6 , V_5 , V_14 ) ;
memcpy ( V_4 , V_6 , V_5 ) ;
F_6 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
int F_7 ( struct V_2 * V_3 , T_3 V_1 ,
void const * V_4 , T_3 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_8 ( V_4 , V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_4 ( V_3 , F_9 ( V_3 , 0 ) ,
V_16 ,
V_11 | V_12 | V_17 ,
F_1 ( V_1 ) ,
0 , V_6 , V_5 , V_14 ) ;
F_6 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
int V_18 ;
struct V_19 V_20 ;
do {
F_11 ( 50 ) ;
V_18 = F_2 ( V_3 ,
V_21 ,
& V_20 , sizeof( struct V_19 ) ) ;
if ( V_18 )
return V_18 ;
switch ( V_20 . V_22 ) {
case V_23 :
return 0 ;
case V_24 :
F_11 ( 500 ) ;
continue;
case V_25 :
case V_26 :
return - V_27 ;
default:
F_12 ( & V_3 -> V_28 ,
L_1
L_2 ,
V_20 . V_22 ) ;
return - V_27 ;
}
} while ( 1 );
}
int F_13 ( struct V_2 * V_3 ,
T_3 V_29 , void const * V_6 , T_3 V_5 )
{
int V_18 ;
V_18 = F_7 ( V_3 , V_29 , V_6 , V_5 ) ;
if ( V_18 )
return V_18 ;
F_11 ( 100 ) ;
return F_10 ( V_3 ) ;
}
