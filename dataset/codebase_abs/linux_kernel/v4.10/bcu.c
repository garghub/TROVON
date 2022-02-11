unsigned long F_1 ( void )
{
return V_1 ;
}
unsigned long F_2 ( void )
{
return V_2 ;
}
static inline T_1 F_3 ( void )
{
switch ( F_4 () ) {
case V_3 :
case V_4 : return F_5 ( V_5 ) ;
case V_6 :
case V_7 :
case V_8 : return F_5 ( V_9 ) ;
default:
F_6 ( V_10 L_1 ) ;
break;
}
return 0 ;
}
static inline unsigned long F_7 ( T_1 V_11 )
{
unsigned long V_12 = 0 ;
switch ( F_4 () ) {
case V_3 :
case V_4 :
V_12 = 18432000 * 64 ;
V_12 /= F_8 ( V_11 ) ;
break;
case V_6 :
V_12 = 18432000 * 98 ;
V_12 /= F_8 ( V_11 ) ;
break;
case V_7 :
V_12 = 18432000 * 108 ;
V_12 /= F_8 ( V_11 ) ;
break;
case V_8 :
switch ( F_9 ( V_11 ) ) {
case 0 :
V_12 = 133000000 ;
break;
case 1 :
V_12 = 149000000 ;
break;
case 2 :
V_12 = 165900000 ;
break;
case 3 :
V_12 = 199100000 ;
break;
case 4 :
V_12 = 265900000 ;
break;
default:
F_6 ( V_10 L_2 ) ;
break;
}
break;
default:
F_6 ( V_10 L_1 ) ;
break;
}
F_6 ( V_10 L_3 , V_12 ) ;
return V_12 ;
}
static inline unsigned long F_10 ( T_1 V_11 , unsigned long V_12 )
{
unsigned long V_13 = 0 ;
switch ( F_4 () ) {
case V_3 :
break;
case V_4 :
V_13 = V_12 ;
if ( F_11 ( V_11 ) == 9 )
V_13 = V_12 * 6 ;
else if ( F_11 ( V_11 ) == 10 )
V_13 = V_12 * 4 ;
V_13 /= F_11 ( V_11 ) ;
F_6 ( V_10 L_4 , V_13 ) ;
break;
case V_6 :
if( F_12 ( V_11 ) == 7 )
V_13 = V_12 / 1 ;
else if( F_12 ( V_11 ) == 1 )
V_13 = V_12 / 2 ;
else
V_13 = V_12 / F_12 ( V_11 ) ;
F_6 ( V_10 L_4 , V_13 ) ;
break;
case V_7 :
case V_8 :
V_13 = V_12 / F_12 ( V_11 ) ;
F_6 ( V_10 L_4 , V_13 ) ;
break;
default:
F_6 ( V_10 L_1 ) ;
break;
}
return V_13 ;
}
static inline unsigned long F_13 ( T_1 V_11 , unsigned long V_12 ,
unsigned long V_13 )
{
unsigned long V_14 = 0 ;
switch ( F_4 () ) {
case V_3 :
if ( ! ( V_11 & V_15 ) )
V_14 = V_12 / 2 ;
else if ( ! ( V_11 & V_16 ) )
V_14 = V_12 / 3 ;
else if ( ! ( V_11 & V_17 ) )
V_14 = V_12 / 4 ;
break;
case V_4 :
V_14 = V_12 / F_14 ( V_11 ) ;
break;
case V_6 :
case V_7 :
case V_8 :
V_14 = V_13 / F_15 ( V_11 ) ;
break;
default:
F_6 ( V_10 L_1 ) ;
break;
}
F_6 ( V_10 L_5 , V_14 ) ;
return V_14 ;
}
void F_16 ( void )
{
unsigned long V_12 ;
T_1 V_11 ;
V_11 = F_3 () ;
V_12 = F_7 ( V_11 ) ;
V_1 = F_10 ( V_11 , V_12 ) ;
V_2 = F_13 ( V_11 , V_12 , V_1 ) ;
}
