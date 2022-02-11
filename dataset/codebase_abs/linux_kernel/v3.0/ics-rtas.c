static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
int V_4 ;
int V_5 ;
F_3 ( L_1 , V_2 -> V_6 , V_3 ) ;
if ( V_3 == V_7 || V_3 == V_8 )
return;
V_5 = F_4 ( V_2 -> V_6 , V_2 -> V_9 , 0 ) ;
V_4 = F_5 ( V_10 , 3 , 1 , NULL , V_3 , V_5 ,
V_11 ) ;
if ( V_4 != 0 ) {
F_6 ( V_12
L_2 ,
V_13 , V_3 , V_5 , V_4 ) ;
return;
}
V_4 = F_5 ( V_14 , 1 , 1 , NULL , V_3 ) ;
if ( V_4 != 0 ) {
F_6 ( V_12 L_3 ,
V_13 , V_3 , V_4 ) ;
return;
}
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
#ifdef F_8
if ( V_2 -> V_15 )
F_9 ( V_2 ) ;
#endif
F_1 ( V_2 ) ;
return 0 ;
}
static void F_10 ( unsigned int V_3 )
{
int V_4 ;
if ( V_3 == V_7 )
return;
V_4 = F_5 ( V_16 , 1 , 1 , NULL , V_3 ) ;
if ( V_4 != 0 ) {
F_6 ( V_12 L_4 ,
V_13 , V_3 , V_4 ) ;
return;
}
V_4 = F_5 ( V_10 , 3 , 1 , NULL , V_3 ,
V_17 , 0xff ) ;
if ( V_4 != 0 ) {
F_6 ( V_12 L_5 ,
V_13 , V_3 , V_4 ) ;
return;
}
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
F_3 ( L_6 , V_2 -> V_6 , V_3 ) ;
if ( V_3 == V_7 || V_3 == V_8 )
return;
F_10 ( V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_18 * V_18 ,
bool V_19 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
int V_20 ;
int V_21 [ 2 ] ;
int V_22 ;
if ( V_3 == V_7 || V_3 == V_8 )
return - 1 ;
V_20 = F_5 ( V_23 , 1 , 3 , V_21 , V_3 ) ;
if ( V_20 ) {
F_6 ( V_12 L_7 ,
V_13 , V_3 , V_20 ) ;
return - 1 ;
}
V_22 = F_4 ( V_2 -> V_6 , V_18 , 1 ) ;
if ( V_22 == - 1 ) {
char V_24 [ 128 ] ;
F_13 ( V_24 , sizeof( V_24 ) , V_18 ) ;
F_6 ( V_25
L_8 ,
V_13 , V_24 , V_2 -> V_6 ) ;
return - 1 ;
}
V_20 = F_5 ( V_10 , 3 , 1 , NULL ,
V_3 , V_22 , V_21 [ 1 ] ) ;
if ( V_20 ) {
F_6 ( V_12 L_9 ,
V_13 , V_3 , V_20 ) ;
return - 1 ;
}
return V_26 ;
}
static int F_14 ( struct V_27 * V_27 , unsigned int V_28 )
{
unsigned int V_3 = ( unsigned int ) F_15 ( V_28 ) ;
int V_20 [ 2 ] ;
int V_29 ;
if ( F_16 ( V_3 == V_7 || V_3 == V_8 ) )
return - V_30 ;
V_29 = F_5 ( V_23 , 1 , 3 , V_20 , V_3 ) ;
if ( V_29 )
return - V_31 ;
F_17 ( V_28 , & V_32 , V_33 ) ;
F_18 ( V_28 , & V_34 ) ;
return 0 ;
}
static void F_19 ( struct V_27 * V_27 , unsigned long V_35 )
{
F_10 ( V_35 ) ;
}
static long F_20 ( struct V_27 * V_27 , unsigned long V_35 )
{
int V_29 , V_20 [ 2 ] ;
V_29 = F_5 ( V_23 , 1 , 3 , V_20 , V_35 ) ;
if ( V_29 )
return - 1 ;
return V_20 [ 0 ] ;
}
static int F_21 ( struct V_27 * V_27 , struct V_36 * V_37 )
{
return ! F_22 ( V_37 , L_10 ) ;
}
int F_23 ( void )
{
V_23 = F_24 ( L_11 ) ;
V_10 = F_24 ( L_12 ) ;
V_14 = F_24 ( L_13 ) ;
V_16 = F_24 ( L_14 ) ;
if ( V_23 == V_38 ||
V_10 == V_38 )
return - V_39 ;
V_32 . V_40 = V_41 -> V_42 ;
F_25 ( & V_34 ) ;
return 0 ;
}
