static void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
}
static inline int F_3 ( int V_1 )
{
F_2 ( V_1 , V_3 ) ;
return F_4 ( V_4 ) ;
}
static int F_5 ( void )
{
if ( ! F_6 ( V_5 , 2 , V_6 ) )
return - V_7 ;
F_7 ( 0x87 , V_3 ) ;
F_7 ( 0x87 , V_3 ) ;
return 0 ;
}
static void F_8 ( int V_8 )
{
F_1 ( 0x07 , V_8 ) ;
}
static void F_9 ( void )
{
F_7 ( 0xAA , V_3 ) ;
F_10 ( V_5 , 2 ) ;
}
static int F_11 ( struct V_9 * V_10 , enum V_11 V_12 )
{
int V_13 ;
unsigned char V_14 ;
V_13 = F_5 () ;
if ( V_13 )
return V_13 ;
F_8 ( V_15 ) ;
V_14 = F_3 ( 0x30 ) ;
if ( ! ( V_14 & 0x01 ) )
F_1 ( 0x30 , V_14 | 0x01 ) ;
switch ( V_12 ) {
case V_16 :
case V_17 :
V_14 = F_3 ( 0x2B ) & ~ 0x10 ;
F_1 ( 0x2B , V_14 ) ;
break;
case V_18 :
V_14 = F_3 ( 0x29 ) & ~ 0x60 ;
V_14 |= 0x20 ;
F_1 ( 0x29 , V_14 ) ;
break;
case V_19 :
V_14 = F_3 ( 0x2b ) & ~ 0x04 ;
F_1 ( 0x2b , V_14 ) ;
break;
case V_20 :
V_14 = ( F_3 ( 0x2B ) & ~ 0x08 ) | 0x04 ;
F_1 ( 0x2B , V_14 ) ;
break;
case V_21 :
case V_22 :
V_14 = F_3 ( 0x2D ) & ~ 0x01 ;
F_1 ( 0x2D , V_14 ) ;
V_14 = F_3 ( V_23 ) ;
V_14 |= 0x02 ;
F_1 ( V_23 , V_14 ) ;
break;
case V_24 :
break;
case V_25 :
V_14 = F_3 ( 0x2C ) & ~ 0x80 ;
F_1 ( 0x2C , V_14 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_14 = F_3 ( V_23 ) ;
V_14 |= 0x02 ;
F_1 ( V_23 , V_14 ) ;
break;
default:
break;
}
V_14 = F_3 ( V_33 ) ;
if ( V_14 != 0 ) {
F_12 ( L_1 ,
V_10 -> V_34 ) ;
F_1 ( V_33 , V_10 -> V_34 ) ;
}
V_14 = F_3 ( V_23 ) & ~ 0x0C ;
F_1 ( V_23 , V_14 ) ;
V_14 = F_3 ( 0xF7 ) & ~ 0xD0 ;
F_1 ( 0xF7 , V_14 ) ;
F_9 () ;
return 0 ;
}
static int F_13 ( unsigned int V_34 )
{
int V_13 ;
V_13 = F_5 () ;
if ( V_13 )
return V_13 ;
F_8 ( V_15 ) ;
F_1 ( V_33 , V_34 ) ;
F_9 () ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 )
{
return F_13 ( V_10 -> V_34 ) ;
}
static int F_15 ( struct V_9 * V_10 )
{
return F_13 ( 0 ) ;
}
static int F_16 ( struct V_9 * V_10 , unsigned int V_34 )
{
V_10 -> V_34 = V_34 ;
return 0 ;
}
static unsigned int F_17 ( struct V_9 * V_10 )
{
unsigned int V_35 ;
int V_13 ;
V_13 = F_5 () ;
if ( V_13 )
return 0 ;
F_8 ( V_15 ) ;
V_35 = F_3 ( V_33 ) ;
F_9 () ;
return V_35 ;
}
static int F_18 ( struct V_36 * V_37 , unsigned long V_38 ,
void * V_39 )
{
if ( V_38 == V_40 || V_38 == V_41 )
F_13 ( 0 ) ;
return V_42 ;
}
static int F_19 ( int V_43 )
{
T_1 V_2 ;
int V_13 ;
V_33 = V_44 ;
V_23 = V_45 ;
V_13 = F_5 () ;
if ( V_13 )
return V_13 ;
F_8 ( V_15 ) ;
V_2 = F_3 ( 0x20 ) ;
switch ( V_2 ) {
case V_46 :
V_13 = V_16 ;
break;
case V_47 :
V_13 = V_17 ;
break;
case V_48 :
V_13 = V_18 ;
V_33 = V_49 ;
V_23 = V_50 ;
break;
case V_51 :
V_13 = V_19 ;
V_33 = V_49 ;
V_23 = V_50 ;
break;
case V_52 :
V_13 = V_24 ;
break;
case V_53 :
V_13 = V_20 ;
break;
case V_54 :
V_13 = V_25 ;
break;
case V_55 :
V_13 = V_26 ;
break;
case V_56 :
V_13 = V_21 ;
break;
case V_57 :
V_13 = V_22 ;
break;
case V_58 :
V_13 = V_27 ;
break;
case V_59 :
V_13 = V_28 ;
break;
case V_60 :
V_13 = V_29 ;
break;
case V_61 :
V_13 = V_30 ;
break;
case V_62 :
V_13 = V_31 ;
break;
case V_63 :
V_13 = V_32 ;
break;
case 0xff :
V_13 = - V_64 ;
break;
default:
V_13 = - V_64 ;
F_20 ( L_2 , V_2 ) ;
break;
}
F_9 () ;
return V_13 ;
}
static int T_2 F_21 ( void )
{
int V_13 ;
int V_12 ;
const char * const V_65 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
} ;
V_5 = 0x2e ;
V_12 = F_19 ( 0x2e ) ;
if ( V_12 < 0 ) {
V_5 = 0x4e ;
V_12 = F_19 ( 0x4e ) ;
if ( V_12 < 0 )
return V_12 ;
}
F_12 ( L_19 ,
V_65 [ V_12 ] ) ;
F_22 ( & V_66 , V_34 , NULL ) ;
F_23 ( & V_66 , V_67 ) ;
V_13 = F_11 ( & V_66 , V_12 ) ;
if ( V_13 ) {
F_20 ( L_20 , V_13 ) ;
return V_13 ;
}
V_13 = F_24 ( & V_68 ) ;
if ( V_13 != 0 ) {
F_20 ( L_21 , V_13 ) ;
return V_13 ;
}
V_13 = F_25 ( & V_66 ) ;
if ( V_13 )
goto V_69;
F_12 ( L_22 ,
V_66 . V_34 , V_67 ) ;
return V_13 ;
V_69:
F_26 ( & V_68 ) ;
return V_13 ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_66 ) ;
F_26 ( & V_68 ) ;
}
