unsigned int __weak T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
return F_2 ( V_2 -> V_6 + V_3 ) ;
case V_7 :
return F_3 ( V_2 -> V_6 + ( V_3 << 2 ) ) ;
case V_8 :
return F_4 ( V_2 -> V_9 + V_3 ) ;
default:
return 0 ;
}
}
void __weak T_1 F_5 ( struct V_1 * V_2 , int V_3 , int V_10 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
F_6 ( V_10 , V_2 -> V_6 + V_3 ) ;
break;
case V_7 :
F_7 ( V_10 , V_2 -> V_6 + ( V_3 << 2 ) ) ;
break;
case V_8 :
F_8 ( V_10 , V_2 -> V_9 + V_3 ) ;
break;
}
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for (; ; ) {
V_11 = F_1 ( V_2 , V_12 ) ;
if ( ( V_11 & V_13 ) == V_13 )
return;
F_10 () ;
}
}
static void T_1 F_11 ( struct V_1 * V_2 , int V_14 )
{
F_9 ( V_2 ) ;
F_5 ( V_2 , V_15 , V_14 ) ;
}
static void T_1 F_12 ( struct V_16 * V_16 ,
const char * V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = & V_19 -> V_2 ;
unsigned int V_20 ;
V_20 = F_1 ( V_2 , V_21 ) ;
if ( V_20 )
F_5 ( V_2 , V_21 , V_20 & V_22 ) ;
F_13 ( V_2 , V_17 , V_18 , F_11 ) ;
F_9 ( V_2 ) ;
if ( V_20 )
F_5 ( V_2 , V_21 , V_20 ) ;
}
static unsigned int T_1 F_14 ( struct V_1 * V_2 )
{
unsigned char V_23 , V_24 , V_25 ;
unsigned int V_26 ;
V_23 = F_1 ( V_2 , V_27 ) ;
F_5 ( V_2 , V_27 , V_23 | V_28 ) ;
V_24 = F_1 ( V_2 , V_29 ) ;
V_25 = F_1 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_27 , V_23 ) ;
V_26 = ( V_25 << 8 ) | V_24 ;
return ( V_2 -> V_31 / 16 ) / V_26 ;
}
static void T_1 F_15 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = & V_33 -> V_2 ;
unsigned int V_34 ;
unsigned char V_14 ;
unsigned int V_20 ;
F_5 ( V_2 , V_27 , 0x3 ) ;
V_20 = F_1 ( V_2 , V_21 ) ;
F_5 ( V_2 , V_21 , V_20 & V_22 ) ;
F_5 ( V_2 , V_35 , 0 ) ;
F_5 ( V_2 , V_36 , 0x3 ) ;
V_34 = F_16 ( V_2 -> V_31 , 16 * V_33 -> V_37 ) ;
V_14 = F_1 ( V_2 , V_27 ) ;
F_5 ( V_2 , V_27 , V_14 | V_28 ) ;
F_5 ( V_2 , V_29 , V_34 & 0xff ) ;
F_5 ( V_2 , V_30 , ( V_34 >> 8 ) & 0xff ) ;
F_5 ( V_2 , V_27 , V_14 & ~ V_28 ) ;
}
static int T_1 F_17 ( struct V_32 * V_33 ,
const char * V_38 )
{
if ( ! ( V_33 -> V_2 . V_6 || V_33 -> V_2 . V_9 ) )
return 0 ;
if ( ! V_33 -> V_37 ) {
V_33 -> V_37 = F_14 ( & V_33 -> V_2 ) ;
snprintf ( V_33 -> V_38 , sizeof( V_33 -> V_38 ) , L_1 ,
V_33 -> V_37 ) ;
}
F_15 ( V_33 ) ;
V_19 = V_33 ;
V_33 -> V_39 -> V_40 = F_12 ;
return 0 ;
}
int T_1 F_18 ( char * V_41 )
{
char V_42 [] = L_2 ;
if ( V_41 && V_41 [ 4 ] == ',' )
V_42 [ 4 ] = '\0' ;
return F_19 ( V_41 , V_42 , F_17 ) ;
}
int F_20 ( void )
{
struct V_32 * V_33 = V_19 ;
struct V_1 * V_2 = V_33 ? & V_33 -> V_2 : NULL ;
int line ;
int V_43 ;
if ( ! V_2 || ( ! V_2 -> V_6 && ! V_2 -> V_9 ) )
return - V_44 ;
line = F_21 ( V_2 ) ;
if ( line < 0 )
return - V_44 ;
V_43 = F_22 ( L_3 , 8250 ,
L_4 , line , V_33 -> V_38 ) ;
if ( V_43 < 0 )
V_43 = F_22 ( L_3 , 0 ,
L_4 , line , V_33 -> V_38 ) ;
return V_43 ;
}
