static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned long V_3 , unsigned int V_4 )
{
register unsigned long T_1 V_5 ( L_1 ) = V_1 ;
register unsigned long T_2 V_5 ( L_2 ) = V_2 ;
register unsigned long T_3 V_5 ( L_3 ) = V_3 ;
register unsigned long T_4 V_5 ( L_4 ) = V_4 ;
int V_6 ;
V_6 = - V_7 ;
asm volatile(
" diag %1, %3, 0x288\n"
"0: la %0, 0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (err) : "d"(__func), "d"(__timeout),
"d"(__action), "d"(__len) : "1", "cc");
return V_6 ;
}
static int F_2 ( unsigned int V_1 , unsigned int V_2 ,
char * V_8 , T_5 V_4 )
{
F_3 ( V_9 ) ;
return F_1 ( V_1 , V_2 , F_4 ( V_8 ) , V_4 ) ;
}
static int F_5 ( unsigned int V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
F_3 ( V_9 ) ;
return F_1 ( V_1 , V_2 , V_3 , 0 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
char * V_12 ;
T_5 V_4 ;
int V_13 ;
unsigned int V_1 ;
if ( F_7 ( V_14 , & V_15 ) )
return - V_16 ;
V_13 = - V_17 ;
if ( V_18 ) {
V_12 = F_8 ( V_19 , V_20 ) ;
if ( ! V_12 ) {
F_9 ( V_14 , & V_15 ) ;
return - V_21 ;
}
V_4 = F_10 ( V_12 , V_22 , V_19 ) ;
F_11 ( V_12 , V_19 ) ;
F_12 ( V_12 , V_19 ) ;
V_1 = V_23 ? ( V_24 | V_25 )
: V_24 ;
V_13 = F_2 ( V_1 , V_11 -> V_2 , V_12 , V_4 ) ;
F_13 ( V_13 != 0 ) ;
F_14 ( V_12 ) ;
} else {
V_13 = F_5 ( V_24 ,
V_11 -> V_2 , V_26 ) ;
}
if ( V_13 ) {
F_15 ( L_5 ) ;
F_9 ( V_14 , & V_15 ) ;
return V_13 ;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
int V_13 ;
F_3 ( V_9 ) ;
V_13 = F_1 ( V_27 , 0 , 0 , 0 ) ;
F_9 ( V_14 , & V_15 ) ;
return V_13 ;
}
static int F_17 ( struct V_10 * V_11 )
{
char * V_12 ;
T_5 V_4 ;
int V_13 ;
unsigned int V_1 ;
V_13 = - V_17 ;
if ( V_18 ) {
V_12 = F_8 ( V_19 , V_20 ) ;
if ( ! V_12 )
return - V_21 ;
V_4 = F_10 ( V_12 , V_22 , V_19 ) ;
F_11 ( V_12 , V_19 ) ;
F_12 ( V_12 , V_19 ) ;
V_1 = V_23 ? ( V_24 | V_25 )
: V_24 ;
V_13 = F_2 ( V_1 , V_11 -> V_2 , V_12 , V_4 ) ;
F_13 ( V_13 != 0 ) ;
F_14 ( V_12 ) ;
} else {
V_13 = F_5 ( V_28 , V_11 -> V_2 , 0 ) ;
}
if ( V_13 )
F_15 ( L_6 ) ;
return V_13 ;
}
static int F_18 ( struct V_10 * V_11 , unsigned int V_29 )
{
V_11 -> V_2 = V_29 ;
return F_17 ( V_11 ) ;
}
static int F_19 ( void )
{
if ( F_7 ( V_14 , & V_15 ) ) {
F_15 ( L_7 ) ;
return F_20 ( - V_16 ) ;
}
return V_30 ;
}
static int F_21 ( void )
{
F_9 ( V_14 , & V_15 ) ;
return V_30 ;
}
static int F_22 ( struct V_31 * V_32 , unsigned long V_33 ,
void * V_34 )
{
switch ( V_33 ) {
case V_35 :
case V_36 :
return F_21 () ;
case V_37 :
case V_38 :
return F_19 () ;
default:
return V_30 ;
}
}
static int T_6 F_23 ( void )
{
int V_13 ;
char V_39 [] = {
194 , 197 , 199 , 201 , 213
} ;
F_24 ( & V_40 , V_41 ) ;
if ( V_18 ) {
if ( F_2 ( V_24 , 15 ,
V_39 , sizeof( V_39 ) ) != 0 ) {
F_15 ( L_8 ) ;
return - V_7 ;
}
} else {
if ( F_5 ( V_24 , 30 , V_26 ) ) {
F_15 ( L_8 ) ;
return - V_7 ;
}
}
if ( F_5 ( V_27 , 0 , 0 ) ) {
F_15 ( L_9 ) ;
return - V_7 ;
}
V_13 = F_25 ( & V_42 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_26 ( & V_40 ) ;
if ( V_13 )
F_27 ( & V_42 ) ;
return V_13 ;
}
static void T_7 F_28 ( void )
{
F_29 ( & V_40 ) ;
F_27 ( & V_42 ) ;
}
