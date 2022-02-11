static inline int F_1 ( void )
{
if ( ! F_2 ( V_1 , 2 , V_2 ) )
return - V_3 ;
F_3 ( 0x87 , V_1 ) ;
F_3 ( 0x01 , V_1 ) ;
F_3 ( 0x55 , V_1 ) ;
F_3 ( 0x55 , V_1 ) ;
return 0 ;
}
static inline void F_4 ( void )
{
F_3 ( 0x02 , V_1 ) ;
F_3 ( 0x02 , V_4 ) ;
F_5 ( V_1 , 2 ) ;
}
static inline void F_6 ( int V_5 )
{
F_3 ( V_6 , V_1 ) ;
F_3 ( V_5 , V_4 ) ;
}
static inline int F_7 ( int V_7 )
{
F_3 ( V_7 , V_1 ) ;
return F_8 ( V_4 ) ;
}
static inline void F_9 ( int V_8 , int V_7 )
{
F_3 ( V_7 , V_1 ) ;
F_3 ( V_8 , V_4 ) ;
}
static inline int F_10 ( int V_7 )
{
int V_8 ;
F_3 ( V_7 ++ , V_1 ) ;
V_8 = F_8 ( V_4 ) << 8 ;
F_3 ( V_7 , V_1 ) ;
V_8 |= F_8 ( V_4 ) ;
return V_8 ;
}
static inline void F_11 ( int V_8 , int V_7 )
{
F_3 ( V_7 ++ , V_1 ) ;
F_3 ( V_8 >> 8 , V_4 ) ;
F_3 ( V_7 , V_1 ) ;
F_3 ( V_8 , V_4 ) ;
}
static void F_12 ( unsigned int V_9 )
{
unsigned char V_10 = V_11 ;
if ( V_12 )
V_10 = 0 ;
if ( V_9 <= V_13 )
V_10 |= V_14 ;
else
V_9 /= 60 ;
if ( V_15 != V_16 )
V_10 |= V_17 ;
F_9 ( V_10 , V_18 ) ;
F_9 ( V_9 , V_19 ) ;
if ( V_13 > 255 )
F_9 ( V_9 >> 8 , V_20 ) ;
}
static int F_13 ( unsigned int V_9 )
{
int V_21 ;
V_21 = F_1 () ;
if ( V_21 )
return V_21 ;
F_6 ( V_22 ) ;
F_12 ( V_9 ) ;
F_4 () ;
return 0 ;
}
static int F_14 ( int V_9 )
{
V_9 += 59 ;
V_9 -= V_9 % 60 ;
return V_9 ;
}
static int F_15 ( struct V_23 * V_24 )
{
return F_13 ( V_24 -> V_25 ) ;
}
static int F_16 ( struct V_23 * V_24 )
{
return F_13 ( 0 ) ;
}
static int F_17 ( struct V_23 * V_24 , unsigned int V_9 )
{
int V_21 = 0 ;
if ( V_9 > V_13 )
V_9 = F_14 ( V_9 ) ;
V_24 -> V_25 = V_9 ;
if ( F_18 ( V_24 ) )
V_21 = F_13 ( V_9 ) ;
return V_21 ;
}
static int T_1 F_19 ( void )
{
T_2 V_26 ;
int V_27 ;
V_27 = F_1 () ;
if ( V_27 )
return V_27 ;
V_15 = F_10 ( V_28 ) ;
V_26 = F_7 ( V_29 ) & 0x0f ;
F_4 () ;
switch ( V_15 ) {
case V_30 :
V_13 = 255 ;
break;
case V_31 :
V_13 = ( V_26 < 8 ) ? 255 : 65535 ;
break;
case V_32 :
case V_33 :
V_13 = 65535 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_16 :
case V_44 :
case V_45 :
V_13 = 65535 ;
break;
case V_46 :
F_20 ( L_1 ,
V_15 , V_26 ) ;
return - V_47 ;
case V_48 :
F_20 ( L_2 ) ;
return - V_47 ;
default:
F_20 ( L_3 ,
V_15 , V_26 ) ;
return - V_47 ;
}
V_27 = F_1 () ;
if ( V_27 )
return V_27 ;
F_6 ( V_22 ) ;
F_9 ( V_14 , V_18 ) ;
F_9 ( 0x00 , V_49 ) ;
F_4 () ;
if ( V_25 < 1 || V_25 > V_13 * 60 ) {
V_25 = V_50 ;
F_21 ( L_4 ,
V_50 ) ;
}
if ( V_25 > V_13 )
V_25 = F_14 ( V_25 ) ;
V_51 . V_25 = V_25 ;
V_51 . V_52 = V_13 * 60 ;
F_22 ( & V_51 ) ;
V_27 = F_23 ( & V_51 ) ;
if ( V_27 ) {
F_20 ( L_5 , V_27 ) ;
return V_27 ;
}
F_24 ( L_6 ,
V_15 , V_26 , V_25 , V_53 , V_12 ) ;
return 0 ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_51 ) ;
}
