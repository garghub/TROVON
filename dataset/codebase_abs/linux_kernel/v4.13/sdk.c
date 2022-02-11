struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return F_2 ( V_3 , V_5 , V_6 ) ;
}
void F_3 ( struct V_1 * V_7 )
{
F_4 ( V_7 ) ;
}
int F_5 ( struct V_1 * V_7 ,
struct V_8 * V_9 )
{
return F_6 ( V_7 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_10 ,
T_2 V_11 , T_3 * V_9 )
{
T_1 V_12 = V_13 ;
T_1 V_14 = 0 ;
T_3 V_15 ;
int V_16 ;
if ( ! V_3 -> V_17 )
return - V_18 ;
while ( V_14 < V_10 ) {
V_15 = F_8 ( V_12 , ( V_10 - V_14 ) ) ;
V_16 = F_9 ( V_3 -> V_17 , V_15 ,
V_11 + V_14 ,
V_9 + V_14 , false ) ;
if ( V_16 ) {
F_10 ( V_3 , L_1 ,
V_16 ) ;
break;
}
V_14 += V_15 ;
}
return V_16 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_10 ,
T_2 V_11 , T_3 * V_9 )
{
T_1 V_12 = V_13 ;
T_1 V_14 = 0 ;
T_3 V_15 ;
int V_16 ;
if ( ! V_3 -> V_17 )
return - V_18 ;
while ( V_14 < V_10 ) {
V_15 = F_8 ( V_12 , ( V_10 - V_14 ) ) ;
V_16 = F_9 ( V_3 -> V_17 , V_15 ,
V_11 + V_14 ,
V_9 + V_14 , true ) ;
if ( V_16 ) {
F_10 ( V_3 , L_2 ) ;
break;
}
V_14 += V_15 ;
}
return V_16 ;
}
int F_12 ( struct V_2 * V_3 , T_1 V_10 , T_2 V_11 ,
void * V_9 , enum V_19 V_20 )
{
int V_21 ;
switch ( V_20 ) {
case V_22 :
V_21 = F_7 ( V_3 , V_10 , V_11 , V_9 ) ;
if ( V_21 )
return V_21 ;
break;
default:
F_13 ( V_3 , L_3 ,
V_20 ) ;
return - V_23 ;
}
return V_10 ;
}
int F_14 ( struct V_2 * V_3 , T_1 V_10 , T_2 V_11 ,
void * V_9 , enum V_19 V_20 )
{
int V_21 ;
switch ( V_20 ) {
case V_22 :
V_21 = F_11 ( V_3 , V_10 , V_11 , V_9 ) ;
if ( V_21 )
return V_21 ;
break;
default:
F_13 ( V_3 , L_4 ,
V_20 ) ;
return - V_23 ;
}
return V_10 ;
}
int F_15 ( struct V_2 * V_3 , int V_10 , void * V_9 )
{
return F_16 ( V_3 -> V_17 , V_9 , V_10 ) ;
}
