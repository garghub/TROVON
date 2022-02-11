static void F_1 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
int div ;
div = F_2 ( * V_1 , 6000000 ) ;
if ( div > 256 )
div = F_3 ( div , 2 ) ;
if ( div > 512 )
div = F_3 ( div , 4 ) ;
* V_1 = 6000000 * div ;
if ( V_3 == NULL )
return;
if ( div < 512 )
* V_6 = 1 ;
else
* V_6 = 0 ;
if ( div & 1 )
* V_5 = 1 ;
else
* V_5 = 0 ;
* V_3 = div / ( * V_6 + 1 ) / ( * V_5 + 1 ) ;
}
static void T_3 F_4 ( struct V_7 * V_8 )
{
F_5 ( V_8 , & V_9 , & V_10 ) ;
}
static void F_6 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_1 div ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div > 4 )
div = 4 ;
* V_1 = V_2 / div ;
if ( ! V_5 )
return;
* V_5 = div ;
}
static void T_3 F_7 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_5 ( V_8 , & V_13 ,
& V_14 ) ;
F_8 ( V_12 ) ;
F_9 ( V_12 ) ;
}
static void F_10 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_1 V_15 ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
V_15 = F_11 ( F_2 ( V_2 , * V_1 ) ) ;
if ( V_15 > 3 )
V_15 = 3 ;
* V_1 = V_2 >> V_15 ;
if ( ! V_6 )
return;
* V_6 = V_15 ;
}
static void T_3 F_12 ( struct V_7 * V_8 )
{
F_5 ( V_8 , & V_16 , & V_17 ) ;
}
static void T_3 F_13 ( struct V_7 * V_8 )
{
F_5 ( V_8 , & V_18 , & V_19 ) ;
}
static void F_14 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_1 div ;
T_2 V_20 , V_21 ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div > 256 )
div = 256 ;
V_21 = F_11 ( div ) ;
V_20 = ( V_2 >> V_21 ) - 1 ;
* V_1 = ( V_2 >> V_21 ) / ( V_20 + 1 ) ;
if ( V_3 == NULL )
return;
* V_5 = V_20 ;
* V_6 = V_21 ;
}
static void T_3 F_15 ( struct V_7 * V_8 )
{
F_5 ( V_8 , & V_22 , & V_23 ) ;
}
