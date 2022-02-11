static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 &= 0xffffdfff ;
F_3 ( V_3 , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 |= 0x00002000 ;
F_3 ( V_3 , V_2 -> V_4 ) ;
}
static void F_5 ( void )
{
F_6 ( V_5 , V_6 ) ;
F_6 ( V_5 , V_6 ) ;
F_6 ( V_7 , V_6 ) ;
F_6 ( V_8 , V_9 ) ;
}
static void F_7 ( void )
{
F_6 ( V_10 , V_6 ) ;
}
static void F_8 ( unsigned int V_11 )
{
unsigned int V_12 ;
F_5 () ;
F_6 ( V_13 , V_6 ) ;
V_12 = F_9 ( V_9 ) ;
V_12 &= 0xF7 ;
F_6 ( V_12 , V_9 ) ;
F_6 ( V_14 , V_6 ) ;
F_6 ( ( V_11 & 255 ) , V_9 ) ;
F_6 ( V_15 , V_6 ) ;
V_12 = F_9 ( V_9 ) ;
V_12 &= 0x3f ;
F_6 ( V_12 , V_9 ) ;
F_6 ( V_16 , V_6 ) ;
V_12 = F_9 ( V_9 ) ;
V_12 |= 0x01 ;
F_6 ( V_12 , V_9 ) ;
F_7 () ;
}
static void F_10 ( void )
{
unsigned int V_12 ;
F_5 () ;
F_6 ( V_16 , V_6 ) ;
V_12 = F_9 ( V_9 ) ;
V_12 &= 0xFE ;
F_6 ( V_12 , V_9 ) ;
F_7 () ;
}
static void F_11 ( unsigned int V_11 )
{
F_5 () ;
F_6 ( V_14 , V_6 ) ;
F_6 ( ( V_11 & 255 ) , V_9 ) ;
F_7 () ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 &= 0xffffdffe ;
F_3 ( V_3 , V_2 -> V_4 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 |= 0x00002001 ;
F_3 ( V_3 , V_2 -> V_4 ) ;
}
void F_14 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
switch ( V_17 ) {
case V_18 :
F_1 ( V_2 ) ;
break;
case V_19 :
F_8 ( V_11 ) ;
break;
case V_20 :
F_12 ( V_2 ) ;
break;
}
}
void F_15 ( struct V_1 * V_2 )
{
switch ( V_17 ) {
case V_18 :
F_4 ( V_2 ) ;
break;
case V_19 :
F_10 () ;
break;
case V_20 :
F_13 ( V_2 ) ;
break;
}
}
void F_16 ( struct V_1 * V_2 , unsigned int V_11 )
{
if ( V_17 == V_19 )
F_11 ( V_11 ) ;
}
void F_17 ( unsigned int V_11 )
{
if ( V_17 == V_19 )
F_11 ( V_11 ) ;
}
int F_18 ( void )
{
switch ( V_17 ) {
case V_18 :
return 0 ;
default:
return 1 ;
}
}
static int T_1 F_19 ( void )
{
F_20 ( L_1 , V_17 ) ;
return 0 ;
}
static void T_2 F_21 ( void )
{
F_20 ( L_2 ) ;
}
