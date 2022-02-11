static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
int V_4 ;
int V_5 ;
F_3 ( L_1 , V_2 -> V_6 , V_3 ) ;
if ( V_3 == V_7 || V_3 == V_8 )
return;
V_5 = F_4 ( V_2 -> V_6 , F_5 ( V_2 ) , 0 ) ;
V_4 = F_6 ( V_9 , 3 , 1 , NULL , V_3 , V_5 ,
V_10 ) ;
if ( V_4 != 0 ) {
F_7 ( V_11
L_2 ,
V_12 , V_3 , V_5 , V_4 ) ;
return;
}
V_4 = F_6 ( V_13 , 1 , 1 , NULL , V_3 ) ;
if ( V_4 != 0 ) {
F_7 ( V_11 L_3 ,
V_12 , V_3 , V_4 ) ;
return;
}
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
#ifdef F_9
if ( F_10 ( V_2 ) )
F_11 ( V_2 ) ;
#endif
F_1 ( V_2 ) ;
return 0 ;
}
static void F_12 ( unsigned int V_3 )
{
int V_4 ;
if ( V_3 == V_7 )
return;
V_4 = F_6 ( V_14 , 1 , 1 , NULL , V_3 ) ;
if ( V_4 != 0 ) {
F_7 ( V_11 L_4 ,
V_12 , V_3 , V_4 ) ;
return;
}
V_4 = F_6 ( V_9 , 3 , 1 , NULL , V_3 ,
V_15 , 0xff ) ;
if ( V_4 != 0 ) {
F_7 ( V_11 L_5 ,
V_12 , V_3 , V_4 ) ;
return;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
F_3 ( L_6 , V_2 -> V_6 , V_3 ) ;
if ( V_3 == V_7 || V_3 == V_8 )
return;
F_12 ( V_3 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_16 * V_16 ,
bool V_17 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
int V_18 ;
int V_19 [ 2 ] ;
int V_20 ;
if ( V_3 == V_7 || V_3 == V_8 )
return - 1 ;
V_18 = F_6 ( V_21 , 1 , 3 , V_19 , V_3 ) ;
if ( V_18 ) {
F_7 ( V_11 L_7 ,
V_12 , V_3 , V_18 ) ;
return - 1 ;
}
V_20 = F_4 ( V_2 -> V_6 , V_16 , 1 ) ;
if ( V_20 == - 1 ) {
F_15 ( L_8 ,
V_12 , F_16 ( V_16 ) , V_2 -> V_6 ) ;
return - 1 ;
}
V_18 = F_6 ( V_9 , 3 , 1 , NULL ,
V_3 , V_20 , V_19 [ 1 ] ) ;
if ( V_18 ) {
F_7 ( V_11 L_9 ,
V_12 , V_3 , V_18 ) ;
return - 1 ;
}
return V_22 ;
}
static int F_17 ( struct V_23 * V_23 , unsigned int V_24 )
{
unsigned int V_3 = ( unsigned int ) F_18 ( V_24 ) ;
int V_18 [ 2 ] ;
int V_25 ;
if ( F_19 ( V_3 == V_7 || V_3 == V_8 ) )
return - V_26 ;
V_25 = F_6 ( V_21 , 1 , 3 , V_18 , V_3 ) ;
if ( V_25 )
return - V_27 ;
F_20 ( V_24 , & V_28 , V_29 ) ;
F_21 ( V_24 , & V_30 ) ;
return 0 ;
}
static void F_22 ( struct V_23 * V_23 , unsigned long V_31 )
{
F_12 ( V_31 ) ;
}
static long F_23 ( struct V_23 * V_23 , unsigned long V_31 )
{
int V_25 , V_18 [ 2 ] ;
V_25 = F_6 ( V_21 , 1 , 3 , V_18 , V_31 ) ;
if ( V_25 )
return - 1 ;
return V_18 [ 0 ] ;
}
static int F_24 ( struct V_23 * V_23 , struct V_32 * V_33 )
{
return ! F_25 ( V_33 , L_10 ) ;
}
T_1 int F_26 ( void )
{
V_21 = F_27 ( L_11 ) ;
V_9 = F_27 ( L_12 ) ;
V_13 = F_27 ( L_13 ) ;
V_14 = F_27 ( L_14 ) ;
if ( V_21 == V_34 ||
V_9 == V_34 )
return - V_35 ;
V_28 . V_36 = V_37 -> V_38 ;
F_28 ( & V_30 ) ;
return 0 ;
}
