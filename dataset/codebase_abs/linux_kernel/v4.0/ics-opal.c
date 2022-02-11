static int F_1 ( int V_1 )
{
return V_1 << 2 ;
}
static int F_2 ( int V_1 )
{
return V_1 >> 2 ;
}
static void F_3 ( struct V_2 * V_3 )
{
unsigned int V_4 = ( unsigned int ) F_4 ( V_3 ) ;
T_1 V_5 ;
int V_1 ;
F_5 ( L_1 , V_3 -> V_6 , V_4 ) ;
if ( V_4 == V_7 || V_4 == V_8 )
return;
V_1 = F_6 ( V_3 -> V_6 , V_3 -> V_9 , 0 ) ;
V_1 = F_1 ( V_1 ) ;
V_5 = F_7 ( V_4 , V_1 , V_10 ) ;
if ( V_5 != V_11 )
F_8 ( L_2
L_3 ,
V_12 , V_3 -> V_6 , V_4 , V_1 , V_5 ) ;
}
static unsigned int F_9 ( struct V_2 * V_3 )
{
#ifdef F_10
if ( V_3 -> V_13 )
F_11 ( V_3 ) ;
#endif
F_3 ( V_3 ) ;
return 0 ;
}
static void F_12 ( unsigned int V_4 )
{
int V_1 = F_1 ( V_14 ) ;
T_1 V_5 ;
if ( V_4 == V_7 )
return;
V_5 = F_7 ( V_4 , V_1 , 0xff ) ;
if ( V_5 != V_11 )
F_8 ( L_4 ,
V_12 , V_4 , V_5 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
unsigned int V_4 = ( unsigned int ) F_4 ( V_3 ) ;
F_5 ( L_5 , V_3 -> V_6 , V_4 ) ;
if ( V_4 == V_7 || V_4 == V_8 )
return;
F_12 ( V_4 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
const struct V_15 * V_15 ,
bool V_16 )
{
unsigned int V_4 = ( unsigned int ) F_4 ( V_3 ) ;
T_2 V_17 ;
T_3 V_1 ;
T_4 V_18 ;
T_1 V_5 ;
int V_19 ;
if ( V_4 == V_7 || V_4 == V_8 )
return - 1 ;
V_5 = F_15 ( V_4 , & V_17 , & V_18 ) ;
if ( V_5 != V_11 ) {
F_8 ( L_6 ,
V_12 , V_3 -> V_6 , V_4 , V_5 ) ;
return - 1 ;
}
V_1 = F_16 ( V_17 ) ;
V_19 = F_6 ( V_3 -> V_6 , V_15 , 1 ) ;
if ( V_19 < 0 ) {
F_17 ( L_7 ,
V_12 , F_18 ( V_15 ) , V_3 -> V_6 ) ;
return - 1 ;
}
V_1 = F_1 ( V_19 ) ;
F_5 ( L_8 ,
V_3 -> V_6 , V_4 , V_19 , V_1 ) ;
V_5 = F_7 ( V_4 , V_1 , V_18 ) ;
if ( V_5 != V_11 ) {
F_8 ( L_2
L_3 ,
V_12 , V_3 -> V_6 , V_4 , V_1 , V_5 ) ;
return - 1 ;
}
return V_20 ;
}
static int F_19 ( struct V_21 * V_21 , struct V_22 * V_23 )
{
return 1 ;
}
static int F_20 ( struct V_21 * V_21 , unsigned int V_24 )
{
unsigned int V_4 = ( unsigned int ) F_21 ( V_24 ) ;
T_1 V_5 ;
T_2 V_1 ;
T_4 V_18 ;
if ( F_22 ( V_4 == V_7 || V_4 == V_8 ) )
return - V_25 ;
V_5 = F_15 ( V_4 , & V_1 , & V_18 ) ;
if ( V_5 != V_11 )
return - V_26 ;
F_23 ( V_24 , & V_27 , V_28 ) ;
F_24 ( V_24 , & V_29 ) ;
return 0 ;
}
static void F_25 ( struct V_21 * V_21 , unsigned long V_30 )
{
T_1 V_5 ;
T_2 V_1 ;
T_4 V_18 ;
V_5 = F_15 ( V_30 , & V_1 , & V_18 ) ;
if ( V_5 != V_11 )
return;
F_12 ( V_30 ) ;
}
static long F_26 ( struct V_21 * V_21 , unsigned long V_30 )
{
T_1 V_5 ;
T_2 V_1 ;
T_4 V_18 ;
V_5 = F_15 ( V_30 , & V_1 , & V_18 ) ;
if ( V_5 != V_11 )
return - 1 ;
return F_2 ( F_16 ( V_1 ) ) ;
}
int T_5 F_27 ( void )
{
if ( ! F_28 ( V_31 ) )
return - V_32 ;
V_27 . V_33 = V_34 -> V_35 ;
F_29 ( & V_29 ) ;
F_30 ( L_9 ) ;
return 0 ;
}
