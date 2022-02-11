static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 )
{
T_5 V_4 ;
struct V_5 V_5 ;
int V_6 = 0 ;
T_6 V_7 ;
int V_8 = 0 ;
static const char * V_9 [] = { L_1 , L_2 , L_3 } ;
if ( ! F_2 ( V_1 , 0 , 4 ) )
return FALSE ;
V_4 = F_3 ( V_1 , 0 ) ;
F_4 ( & V_5 , V_4 ) ;
if ( ! F_5 ( & V_5 ) )
return FALSE ;
if ( ! F_6 ( & V_5 ) )
return FALSE ;
if ( ! F_7 ( & V_5 ) )
return FALSE ;
F_8 ( V_2 -> V_10 , V_11 ,
L_4 , V_9 [ F_9 ( & V_5 ) ] ) ;
F_8 ( V_2 -> V_10 , V_12 ,
L_5 , F_10 ( & V_5 ) + 1 ) ;
if ( F_11 ( & V_5 ) && F_12 ( & V_5 ) ) {
V_6 = ( int ) ( F_13 ( & V_5 ) - sizeof V_5 ) ;
F_14 ( V_2 -> V_10 , V_12 ,
L_6 ,
F_15 ( & V_5 ) / 1000 ,
F_16 ( & V_5 ) / ( float ) 1000 ) ;
}
if ( V_3 == NULL )
return TRUE ;
F_17 ( & V_7 , V_13 , TRUE , V_2 ) ;
V_8 = F_18 ( V_1 , V_8 , & V_7 ,
V_3 , V_14 ) ;
if ( V_6 > 0 ) {
unsigned int V_15 ;
F_19 ( V_3 , V_16 , V_1 ,
V_8 / 8 , V_6 , V_17 ) ;
V_8 += V_6 * 8 ;
V_15 = F_20 ( & V_5 ) ;
if ( V_15 > 0 ) {
F_19 ( V_3 , V_18 , V_1 ,
V_8 / 8 , V_15 , V_17 ) ;
}
}
return TRUE ;
}
static void
F_21 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 )
{
T_6 V_7 ;
F_22 ( V_2 -> V_10 , V_11 , L_7 ) ;
F_23 ( V_2 -> V_10 , V_12 ) ;
if ( V_3 == NULL )
return;
F_17 ( & V_7 , V_13 , TRUE , V_2 ) ;
F_24 ( V_1 , 0 , & V_7 ,
V_3 , V_19 ) ;
}
static void
F_25 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 )
{
F_22 ( V_2 -> V_10 , V_11 , L_8 ) ;
F_23 ( V_2 -> V_10 , V_12 ) ;
F_19 ( V_3 , V_20 , V_1 ,
0 , - 1 , V_17 ) ;
}
static T_1
F_26 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_7 V_21 )
{
int V_22 ;
if ( ! F_2 ( V_1 , 0 , 3 ) )
return FALSE ;
V_22 = F_27 ( V_1 , 0 ) ;
switch ( V_22 ) {
case 0x544147 :
F_21 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
case 0x494433 :
F_25 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
default:
return F_1 ( V_1 , V_2 , V_3 ) ;
}
}
void
F_28 ( void )
{
static T_8 V_23 [] = {
#include "packet-mpeg-audio-hfarr.c"
{ & V_16 ,
{ L_9 , L_10 ,
V_24 , V_25 , NULL , 0 , NULL , V_26 } } ,
{ & V_18 ,
{ L_11 , L_12 ,
V_24 , V_25 , NULL , 0 , NULL , V_26 } } ,
{ & V_19 ,
{ L_7 , L_13 ,
V_27 , V_25 , NULL , 0 , NULL , V_26 } } ,
{ & V_20 ,
{ L_8 , L_14 ,
V_27 , V_25 , NULL , 0 , NULL , V_26 } } ,
} ;
static T_9 * V_28 [] = {
#include "packet-mpeg-audio-ettarr.c"
} ;
V_14 = F_29 (
L_15 , L_16 , L_17 ) ;
F_30 ( V_14 , V_23 , F_31 ( V_23 ) ) ;
F_32 ( V_28 , F_31 ( V_28 ) ) ;
}
void
F_33 ( void )
{
F_34 ( L_18 , F_26 , L_16 , L_19 , V_14 , V_29 ) ;
}
