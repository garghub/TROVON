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
F_5 ( V_2 , V_21 , 0 ) ;
F_13 ( V_2 , V_17 , V_18 , F_11 ) ;
F_9 ( V_2 ) ;
F_5 ( V_2 , V_21 , V_20 ) ;
}
static unsigned int T_1 F_14 ( struct V_1 * V_2 )
{
unsigned char V_22 , V_23 , V_24 ;
unsigned int V_25 ;
V_22 = F_1 ( V_2 , V_26 ) ;
F_5 ( V_2 , V_26 , V_22 | V_27 ) ;
V_23 = F_1 ( V_2 , V_28 ) ;
V_24 = F_1 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_26 , V_22 ) ;
V_25 = ( V_24 << 8 ) | V_23 ;
return ( V_2 -> V_30 / 16 ) / V_25 ;
}
static void T_1 F_15 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = & V_32 -> V_2 ;
unsigned int V_33 ;
unsigned char V_14 ;
F_5 ( V_2 , V_26 , 0x3 ) ;
F_5 ( V_2 , V_21 , 0 ) ;
F_5 ( V_2 , V_34 , 0 ) ;
F_5 ( V_2 , V_35 , 0x3 ) ;
V_33 = F_16 ( V_2 -> V_30 , 16 * V_32 -> V_36 ) ;
V_14 = F_1 ( V_2 , V_26 ) ;
F_5 ( V_2 , V_26 , V_14 | V_27 ) ;
F_5 ( V_2 , V_28 , V_33 & 0xff ) ;
F_5 ( V_2 , V_29 , ( V_33 >> 8 ) & 0xff ) ;
F_5 ( V_2 , V_26 , V_14 & ~ V_27 ) ;
}
static int T_1 F_17 ( struct V_31 * V_32 ,
const char * V_37 )
{
if ( ! ( V_32 -> V_2 . V_6 || V_32 -> V_2 . V_9 ) )
return 0 ;
if ( ! V_32 -> V_36 ) {
V_32 -> V_36 = F_14 ( & V_32 -> V_2 ) ;
snprintf ( V_32 -> V_37 , sizeof( V_32 -> V_37 ) , L_1 ,
V_32 -> V_36 ) ;
}
F_15 ( V_32 ) ;
V_19 = V_32 ;
V_32 -> V_38 -> V_39 = F_12 ;
return 0 ;
}
int T_1 F_18 ( char * V_40 )
{
char V_41 [] = L_2 ;
if ( V_40 && V_40 [ 4 ] == ',' )
V_41 [ 4 ] = '\0' ;
return F_19 ( V_40 , V_41 , F_17 ) ;
}
int F_20 ( void )
{
struct V_31 * V_32 = V_19 ;
struct V_1 * V_2 = V_32 ? & V_32 -> V_2 : NULL ;
int line ;
int V_42 ;
if ( ! V_2 || ( ! V_2 -> V_6 && ! V_2 -> V_9 ) )
return - V_43 ;
line = F_21 ( V_2 ) ;
if ( line < 0 )
return - V_43 ;
V_42 = F_22 ( L_3 , 8250 ,
L_4 , line , V_32 -> V_37 ) ;
if ( V_42 < 0 )
V_42 = F_22 ( L_3 , 0 ,
L_4 , line , V_32 -> V_37 ) ;
return V_42 ;
}
