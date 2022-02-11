void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 , V_2 , & V_6 ) ;
V_4 -> V_7 = false ;
}
int F_3 ( struct V_3 * V_4 , T_1 * V_8 )
{
return F_4 ( & V_4 -> V_5 , V_8 ) ;
}
int F_5 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_9 , T_2 V_10 ,
bool V_11 , T_1 * V_12 )
{
T_2 V_13 = F_6 ( V_9 , V_14 ) ;
T_2 V_15 = F_6 ( V_10 , V_14 ) ;
T_3 V_16 = V_11 ? F_7 ( ~ 0 ) : F_7 ( 0 ) ;
F_8 ( & V_16 ) ;
return F_9 ( & V_4 -> V_5 , V_8 , V_13 , V_15 ,
& V_16 , V_12 ) ;
}
int F_10 ( struct V_3 * V_4 , T_1 V_8 )
{
return F_11 ( & V_4 -> V_5 , V_8 ) ;
}
int F_12 ( struct V_3 * V_4 , T_1 V_8 ,
T_1 * V_12 )
{
int V_17 ;
T_3 V_16 ;
if ( ! V_4 -> V_7 )
return 0 ;
V_16 = F_7 ( V_4 -> V_18 ) ;
F_8 ( & V_16 ) ;
V_17 = F_13 ( & V_4 -> V_5 , V_8 , V_4 -> V_19 ,
& V_16 , V_12 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_7 = false ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_20 )
{
int V_17 ;
T_3 V_16 ;
V_17 = F_15 ( & V_4 -> V_5 , V_8 , V_20 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_18 = F_16 ( V_16 ) ;
V_4 -> V_7 = true ;
V_4 -> V_19 = V_20 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_21 , T_1 * V_12 )
{
int V_17 ;
unsigned V_20 = V_21 / V_14 ;
if ( V_4 -> V_7 ) {
if ( V_4 -> V_19 == V_20 )
return 0 ;
V_17 = F_12 ( V_4 , V_8 , V_12 ) ;
if ( V_17 )
return V_17 ;
}
return F_14 ( V_4 , V_8 , V_20 ) ;
}
int F_18 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_21 , T_1 * V_12 )
{
int V_17 ;
unsigned V_22 = V_21 % V_14 ;
V_17 = F_17 ( V_4 , V_8 , V_21 , V_12 ) ;
if ( V_17 )
return V_17 ;
F_19 ( V_22 , ( unsigned long * ) & V_4 -> V_18 ) ;
return 0 ;
}
int F_20 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_21 , T_1 * V_12 )
{
int V_17 ;
unsigned V_22 = V_21 % V_14 ;
V_17 = F_17 ( V_4 , V_8 , V_21 , V_12 ) ;
if ( V_17 )
return V_17 ;
F_21 ( V_22 , ( unsigned long * ) & V_4 -> V_18 ) ;
return 0 ;
}
int F_22 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_21 , T_1 * V_12 , bool * V_23 )
{
int V_17 ;
unsigned V_22 = V_21 % V_14 ;
V_17 = F_17 ( V_4 , V_8 , V_21 , V_12 ) ;
if ( V_17 )
return V_17 ;
* V_23 = F_23 ( V_22 , ( unsigned long * ) & V_4 -> V_18 ) ;
return 0 ;
}
