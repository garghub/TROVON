static void F_1 ( char V_1 )
{
F_2 ( V_2 , & V_1 , 1 ) ;
}
static void F_3 ( bool V_3 )
{
if ( V_3 ) {
F_4 ( V_4 , 1 ) ;
F_5 ( 100 ) ;
F_4 ( V_5 , 1 ) ;
F_4 ( V_6 , 1 ) ;
} else {
F_4 ( V_4 , 0 ) ;
F_4 ( V_5 , 0 ) ;
F_4 ( V_6 , 0 ) ;
}
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_13 ;
return F_7 ( V_13 , 0 , 0 , 0 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_13 ;
F_7 ( V_13 , 0 , 0 , 0 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_12 * V_16 = V_10 -> V_16 ;
unsigned int V_1 = 0 ;
int V_17 = 0 ;
switch ( F_10 ( V_15 ) ) {
case 44100 :
F_1 ( V_18 ) ;
V_1 = 11289600 ;
break;
case 48000 :
F_1 ( V_19 ) ;
V_1 = 12288000 ;
break;
case 88200 :
F_1 ( V_20 ) ;
V_1 = 22579200 ;
break;
case 96000 :
F_1 ( V_21 ) ;
V_1 = 24576000 ;
break;
default:
return - V_22 ;
}
V_17 = F_7 ( V_13 , 0 , V_1 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_11 ( V_16 , 0 , 0 , 0 , V_1 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_12 ( V_16 , V_23 , 4 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_7 ( V_16 , V_24 , V_1 , 1 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 )
{
F_3 ( false ) ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 )
{
F_3 ( true ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 * V_16 = V_10 -> V_16 ;
int V_17 = 0 , V_1 = 0 ;
switch ( F_10 ( V_15 ) ) {
case 44100 :
F_1 ( V_18 ) ;
V_1 = 11289600 ;
break;
case 48000 :
F_1 ( V_19 ) ;
V_1 = 12288000 ;
break;
case 88200 :
F_1 ( V_20 ) ;
V_1 = 22579200 ;
break;
case 96000 :
F_1 ( V_21 ) ;
V_1 = 24576000 ;
break;
default:
return - V_22 ;
}
V_17 = F_11 ( V_16 , 0 , 0 , 0 , V_1 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_12 ( V_16 , V_23 , 4 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_7 ( V_16 , V_24 , V_1 , 1 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_17 ;
if ( ! F_17 () &&
! F_18 () )
return 0 ;
V_2 = F_19 ( F_20 ( 0 ) ,
& V_27 ) ;
if ( ! V_2 )
return - V_28 ;
F_1 ( V_19 ) ;
V_29 = F_21 ( L_1 , 0 ) ;
if ( ! V_29 )
return - V_28 ;
if ( F_17 () )
F_22 ( V_29 ,
& V_30 ) ;
if ( F_18 () )
F_22 ( V_29 ,
& V_31 ) ;
V_17 = F_23 ( V_29 ) ;
if ( V_17 < 0 ) {
F_24 ( V_29 ) ;
return V_17 ;
}
F_3 ( true ) ;
return 0 ;
}
static void T_2 F_25 ( void )
{
F_3 ( false ) ;
F_26 ( V_29 ) ;
F_27 ( V_2 ) ;
F_28 ( V_4 ) ;
F_28 ( V_6 ) ;
F_28 ( V_5 ) ;
}
