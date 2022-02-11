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
V_1 = F_6 ( V_3 -> V_6 , F_7 ( V_3 ) , 0 ) ;
V_1 = F_1 ( V_1 ) ;
V_5 = F_8 ( V_4 , V_1 , V_9 ) ;
if ( V_5 != V_10 )
F_9 ( L_2
L_3 ,
V_11 , V_3 -> V_6 , V_4 , V_1 , V_5 ) ;
}
static unsigned int F_10 ( struct V_2 * V_3 )
{
#ifdef F_11
if ( F_12 ( V_3 ) )
F_13 ( V_3 ) ;
#endif
F_3 ( V_3 ) ;
return 0 ;
}
static void F_14 ( unsigned int V_4 )
{
int V_1 = F_1 ( V_12 ) ;
T_1 V_5 ;
if ( V_4 == V_7 )
return;
V_5 = F_8 ( V_4 , V_1 , 0xff ) ;
if ( V_5 != V_10 )
F_9 ( L_4 ,
V_11 , V_4 , V_5 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
unsigned int V_4 = ( unsigned int ) F_4 ( V_3 ) ;
F_5 ( L_5 , V_3 -> V_6 , V_4 ) ;
if ( V_4 == V_7 || V_4 == V_8 )
return;
F_14 ( V_4 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_13 * V_13 ,
bool V_14 )
{
unsigned int V_4 = ( unsigned int ) F_4 ( V_3 ) ;
T_2 V_15 ;
T_3 V_1 ;
T_4 V_16 ;
T_1 V_5 ;
int V_17 ;
if ( V_4 == V_7 || V_4 == V_8 )
return - 1 ;
V_5 = F_17 ( V_4 , & V_15 , & V_16 ) ;
if ( V_5 != V_10 ) {
F_9 ( L_6 ,
V_11 , V_3 -> V_6 , V_4 , V_5 ) ;
return - 1 ;
}
V_1 = F_18 ( V_15 ) ;
V_17 = F_6 ( V_3 -> V_6 , V_13 , 1 ) ;
if ( V_17 < 0 ) {
F_19 ( L_7 ,
V_11 , F_20 ( V_13 ) , V_3 -> V_6 ) ;
return - 1 ;
}
V_1 = F_1 ( V_17 ) ;
F_5 ( L_8 ,
V_3 -> V_6 , V_4 , V_17 , V_1 ) ;
V_5 = F_8 ( V_4 , V_1 , V_16 ) ;
if ( V_5 != V_10 ) {
F_9 ( L_2
L_3 ,
V_11 , V_3 -> V_6 , V_4 , V_1 , V_5 ) ;
return - 1 ;
}
return V_18 ;
}
static int F_21 ( struct V_19 * V_19 , struct V_20 * V_21 )
{
return 1 ;
}
static int F_22 ( struct V_19 * V_19 , unsigned int V_22 )
{
unsigned int V_4 = ( unsigned int ) F_23 ( V_22 ) ;
T_1 V_5 ;
T_2 V_1 ;
T_4 V_16 ;
if ( F_24 ( V_4 == V_7 || V_4 == V_8 ) )
return - V_23 ;
V_5 = F_17 ( V_4 , & V_1 , & V_16 ) ;
if ( V_5 != V_10 )
return - V_24 ;
F_25 ( V_22 , & V_25 , V_26 ) ;
F_26 ( V_22 , & V_27 ) ;
return 0 ;
}
static void F_27 ( struct V_19 * V_19 , unsigned long V_28 )
{
T_1 V_5 ;
T_2 V_1 ;
T_4 V_16 ;
V_5 = F_17 ( V_28 , & V_1 , & V_16 ) ;
if ( V_5 != V_10 )
return;
F_14 ( V_28 ) ;
}
static long F_28 ( struct V_19 * V_19 , unsigned long V_28 )
{
T_1 V_5 ;
T_2 V_1 ;
T_4 V_16 ;
V_5 = F_17 ( V_28 , & V_1 , & V_16 ) ;
if ( V_5 != V_10 )
return - 1 ;
return F_2 ( F_18 ( V_1 ) ) ;
}
int T_5 F_29 ( void )
{
if ( ! F_30 ( V_29 ) )
return - V_30 ;
V_25 . V_31 = V_32 -> V_33 ;
F_31 ( & V_27 ) ;
F_32 ( L_9 ) ;
return 0 ;
}
