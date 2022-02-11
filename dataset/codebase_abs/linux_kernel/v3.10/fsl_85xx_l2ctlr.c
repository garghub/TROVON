static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
unsigned int V_4 ;
if ( ! V_5 || ( F_2 ( V_5 , 0 , & V_4 ) < 0 ) )
return - V_6 ;
if ( ! V_7 || ( F_3 ( V_7 , 0 , & V_3 ) < 0 ) )
return - V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_5 = V_4 ;
return 0 ;
}
static int T_1 F_4 ( char * V_8 )
{
if ( ! V_8 )
return 0 ;
V_5 = V_8 ;
return 1 ;
}
static int T_1 F_5 ( char * V_8 )
{
if ( ! V_8 )
return 0 ;
V_7 = V_8 ;
return 1 ;
}
static int F_6 ( struct V_9 * V_10 )
{
long V_11 ;
unsigned int V_12 ;
unsigned char V_13 ;
const unsigned int * V_14 ;
unsigned int V_15 ;
struct V_1 V_2 ;
if ( ! V_10 -> V_10 . V_16 ) {
F_7 ( & V_10 -> V_10 , L_1 ) ;
return - V_6 ;
}
V_14 = F_8 ( V_10 -> V_10 . V_16 , L_2 , NULL ) ;
if ( ! V_14 ) {
F_7 ( & V_10 -> V_10 , L_3 ) ;
return - V_6 ;
}
V_15 = * V_14 ;
if ( F_1 ( & V_2 ) ) {
F_7 ( & V_10 -> V_10 ,
L_4 ) ;
return - V_6 ;
}
V_12 = V_15 % V_2 . V_5 ;
V_13 = V_17 * V_2 . V_5 / V_15 ;
if ( V_12 || ( V_13 & ( V_13 - 1 ) ) ) {
F_7 ( & V_10 -> V_10 , L_5 ) ;
return - V_6 ;
}
V_18 = F_9 ( V_10 -> V_10 . V_16 , 0 ) ;
if ( ! V_18 ) {
F_7 ( & V_10 -> V_10 , L_6 ) ;
return - V_6 ;
}
F_10 ( & V_18 -> V_19 ,
F_11 ( V_2 . V_7 ) & V_20 ) ;
#ifdef F_12
F_10 ( & V_18 -> V_21 ,
F_13 ( V_2 . V_7 ) & V_22 ) ;
#endif
F_14 ( & V_18 -> V_23 , V_24 , V_25 ) ;
switch ( V_13 ) {
case V_26 :
F_15 ( & V_18 -> V_23 ,
V_24 | V_25 | V_27 ) ;
break;
case V_28 :
F_15 ( & V_18 -> V_23 ,
V_24 | V_25 | V_29 ) ;
break;
case V_30 :
F_15 ( & V_18 -> V_23 ,
V_24 | V_25 | V_31 ) ;
break;
case V_17 :
default:
F_15 ( & V_18 -> V_23 ,
V_24 | V_25 | V_32 ) ;
break;
}
F_16 () ;
V_11 = F_17 ( V_10 , V_2 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_10 -> V_10 , L_7 ) ;
F_18 ( V_18 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
F_20 ( ! V_18 ) ;
F_18 ( V_18 ) ;
F_21 ( V_10 ) ;
F_22 ( & V_10 -> V_10 , L_8 ) ;
return 0 ;
}
static T_1 int F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
