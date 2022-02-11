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
return F_1 ( V_1 , V_2 , F_3 ( V_8 ) , V_4 ) ;
}
static int F_4 ( unsigned int V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , 0 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
char * V_11 ;
T_5 V_4 ;
int V_12 ;
unsigned int V_1 ;
V_12 = - V_13 ;
if ( V_14 ) {
V_11 = F_6 ( V_15 , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
V_4 = F_7 ( V_11 , V_18 , V_15 ) ;
F_8 ( V_11 , V_15 ) ;
F_9 ( V_11 , V_15 ) ;
V_1 = V_19 ? ( V_20 | V_21 )
: V_20 ;
V_12 = F_2 ( V_1 , V_10 -> V_2 , V_11 , V_4 ) ;
F_10 ( V_12 != 0 ) ;
F_11 ( V_11 ) ;
} else {
V_12 = F_4 ( V_20 ,
V_10 -> V_2 , V_22 ) ;
}
if ( V_12 ) {
F_12 ( L_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
int V_12 ;
V_12 = F_1 ( V_23 , 0 , 0 , 0 ) ;
return V_12 ;
}
static int F_14 ( struct V_9 * V_10 )
{
char * V_11 ;
T_5 V_4 ;
int V_12 ;
unsigned int V_1 ;
V_12 = - V_13 ;
if ( V_14 ) {
V_11 = F_6 ( V_15 , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
V_4 = F_7 ( V_11 , V_18 , V_15 ) ;
F_8 ( V_11 , V_15 ) ;
F_9 ( V_11 , V_15 ) ;
V_1 = V_19 ? ( V_20 | V_21 )
: V_20 ;
V_12 = F_2 ( V_1 , V_10 -> V_2 , V_11 , V_4 ) ;
F_10 ( V_12 != 0 ) ;
F_11 ( V_11 ) ;
} else {
V_12 = F_4 ( V_24 , V_10 -> V_2 , 0 ) ;
}
if ( V_12 )
F_12 ( L_6 ) ;
return V_12 ;
}
static int F_15 ( struct V_9 * V_10 , unsigned int V_25 )
{
V_10 -> V_2 = V_25 ;
return F_14 ( V_10 ) ;
}
static int F_16 ( void )
{
if ( F_17 ( V_26 , & V_27 . V_28 ) ) {
F_12 ( L_7 ) ;
return F_18 ( - V_29 ) ;
}
if ( F_19 ( V_30 , & V_27 . V_28 ) ) {
F_20 ( V_26 , & V_27 . V_28 ) ;
F_12 ( L_7 ) ;
return F_18 ( - V_29 ) ;
}
return V_31 ;
}
static int F_21 ( void )
{
F_20 ( V_26 , & V_27 . V_28 ) ;
return V_31 ;
}
static int F_22 ( struct V_32 * V_33 , unsigned long V_34 ,
void * V_35 )
{
switch ( V_34 ) {
case V_36 :
case V_37 :
return F_21 () ;
case V_38 :
case V_39 :
return F_16 () ;
default:
return V_31 ;
}
}
static int T_6 F_23 ( void )
{
int V_12 ;
char V_40 [] = {
194 , 197 , 199 , 201 , 213
} ;
F_24 ( & V_27 , V_41 ) ;
if ( V_14 ) {
if ( F_2 ( V_20 , 15 ,
V_40 , sizeof( V_40 ) ) != 0 ) {
F_12 ( L_8 ) ;
return - V_7 ;
}
} else {
if ( F_4 ( V_20 , 30 , V_22 ) ) {
F_12 ( L_8 ) ;
return - V_7 ;
}
}
if ( F_4 ( V_23 , 0 , 0 ) ) {
F_12 ( L_9 ) ;
return - V_7 ;
}
V_12 = F_25 ( & V_42 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_26 ( & V_27 ) ;
if ( V_12 )
F_27 ( & V_42 ) ;
return V_12 ;
}
static void T_7 F_28 ( void )
{
F_29 ( & V_27 ) ;
F_27 ( & V_42 ) ;
}
