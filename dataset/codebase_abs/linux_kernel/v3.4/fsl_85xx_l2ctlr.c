static long F_1 ( void )
{
unsigned long V_1 ;
if ( ! V_2 || ( F_2 ( V_2 , 0 , & V_1 ) < 0 ) )
return - V_3 ;
return V_1 ;
}
static long F_3 ( void )
{
unsigned long V_1 ;
if ( ! V_4 || ( F_2 ( V_4 , 0 , & V_1 ) < 0 ) )
return - V_3 ;
return V_1 ;
}
static int T_1 F_4 ( char * V_5 )
{
if ( ! V_5 )
return 0 ;
V_2 = V_5 ;
return 1 ;
}
static int T_1 F_5 ( char * V_5 )
{
if ( ! V_5 )
return 0 ;
V_4 = V_5 ;
return 1 ;
}
static int T_2 F_6 ( struct V_6 * V_7 )
{
long V_8 ;
unsigned int V_9 ;
unsigned char V_10 ;
const unsigned int * V_11 ;
unsigned int V_12 ;
struct V_13 V_14 ;
if ( ! V_7 -> V_7 . V_15 ) {
F_7 ( & V_7 -> V_7 , L_1 ) ;
return - V_3 ;
}
V_11 = F_8 ( V_7 -> V_7 . V_15 , L_2 , NULL ) ;
if ( ! V_11 ) {
F_7 ( & V_7 -> V_7 , L_3 ) ;
return - V_3 ;
}
V_12 = * V_11 ;
V_14 . V_2 = F_1 () ;
if ( ( int ) V_14 . V_2 <= 0 ) {
F_7 ( & V_7 -> V_7 ,
L_4 ) ;
return - V_3 ;
}
V_14 . V_4 = F_3 () ;
if ( ( V_16 ) V_14 . V_4 <= 0 ) {
F_7 ( & V_7 -> V_7 ,
L_5 ) ;
return - V_3 ;
}
V_9 = V_12 % V_14 . V_2 ;
V_10 = V_17 * V_14 . V_2 / V_12 ;
if ( V_9 || ( V_10 & ( V_10 - 1 ) ) ) {
F_7 ( & V_7 -> V_7 , L_6 ) ;
return - V_3 ;
}
V_18 = F_9 ( V_7 -> V_7 . V_15 , 0 ) ;
if ( ! V_18 ) {
F_7 ( & V_7 -> V_7 , L_7 ) ;
return - V_3 ;
}
F_10 ( & V_18 -> V_19 ,
V_14 . V_4 & V_20 ) ;
#ifdef F_11
F_10 ( & V_18 -> V_21 ,
( V_14 . V_4 >> 32 ) & V_22 ) ;
#endif
F_12 ( & V_18 -> V_23 , V_24 , V_25 ) ;
switch ( V_10 ) {
case V_26 :
F_13 ( & V_18 -> V_23 ,
V_24 | V_25 | V_27 ) ;
break;
case V_28 :
F_13 ( & V_18 -> V_23 ,
V_24 | V_25 | V_29 ) ;
break;
case V_30 :
F_13 ( & V_18 -> V_23 ,
V_24 | V_25 | V_31 ) ;
break;
case V_17 :
default:
F_13 ( & V_18 -> V_23 ,
V_24 | V_25 | V_32 ) ;
break;
}
F_14 () ;
V_8 = F_15 ( V_7 , V_14 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_7 -> V_7 , L_8 ) ;
F_16 ( V_18 ) ;
return - V_3 ;
}
return 0 ;
}
static int T_3 F_17 ( struct V_6 * V_7 )
{
F_18 ( ! V_18 ) ;
F_16 ( V_18 ) ;
F_19 ( V_7 ) ;
F_20 ( & V_7 -> V_7 , L_9 ) ;
return 0 ;
}
static T_1 int F_21 ( void )
{
return F_22 ( & V_33 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_33 ) ;
}
