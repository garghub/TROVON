static int F_1 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_2 V_8 ;
F_2 ( V_3 != 4 ) ;
V_8 = F_3 ( V_2 ) ;
while ( V_5 ) {
switch ( V_7 -> V_9 ) {
case 1 :
F_4 ( * ( V_10 * ) V_4 , V_7 -> V_11 + V_8 ) ;
break;
case 2 :
F_5 ( F_6 ( V_4 ) , V_7 -> V_11 + V_8 ) ;
break;
case 4 :
F_7 ( F_3 ( V_4 ) , V_7 -> V_11 + V_8 ) ;
break;
#ifdef F_8
case 8 :
F_9 ( F_10 ( V_4 ) , V_7 -> V_11 + V_8 ) ;
break;
#endif
default:
F_11 () ;
}
V_5 -= V_7 -> V_9 ;
V_4 += V_7 -> V_9 ;
V_8 += V_7 -> V_9 ;
}
return 0 ;
}
static int F_12 ( void * V_1 , const void * V_12 , T_1 V_13 )
{
F_2 ( V_13 < 4 ) ;
return F_1 ( V_1 , V_12 , 4 , V_12 + 4 , V_13 - 4 ) ;
}
static int F_13 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_2 V_8 ;
F_2 ( V_3 != 4 ) ;
V_8 = F_3 ( V_2 ) ;
while ( V_5 ) {
switch ( V_7 -> V_9 ) {
case 1 :
* ( V_10 * ) V_4 = F_14 ( V_7 -> V_11 + V_8 ) ;
break;
case 2 :
* ( V_14 * ) V_4 = F_15 ( F_16 ( V_7 -> V_11 + V_8 ) ) ;
break;
case 4 :
* ( T_2 * ) V_4 = F_17 ( F_18 ( V_7 -> V_11 + V_8 ) ) ;
break;
#ifdef F_8
case 8 :
* ( V_15 * ) V_4 = F_17 ( F_19 ( V_7 -> V_11 + V_8 ) ) ;
break;
#endif
default:
F_11 () ;
}
V_5 -= V_7 -> V_9 ;
V_4 += V_7 -> V_9 ;
V_8 += V_7 -> V_9 ;
}
return 0 ;
}
static void F_20 ( void * V_1 )
{
F_21 ( V_1 ) ;
}
struct V_6 * F_22 ( void T_3 * V_11 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 ;
int V_18 ;
if ( V_17 -> V_19 != 32 )
return F_23 ( - V_20 ) ;
if ( V_17 -> V_21 )
return F_23 ( - V_20 ) ;
switch ( V_17 -> V_22 ) {
case 8 :
V_18 = 0 ;
break;
case 16 :
V_18 = 2 ;
break;
case 32 :
V_18 = 4 ;
break;
#ifdef F_8
case 64 :
V_18 = 8 ;
break;
#endif
break;
default:
return F_23 ( - V_20 ) ;
}
if ( V_17 -> V_23 < V_18 )
return F_23 ( - V_20 ) ;
V_7 = F_24 ( V_24 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return F_23 ( - V_25 ) ;
V_7 -> V_11 = V_11 ;
V_7 -> V_9 = V_17 -> V_22 / 8 ;
return V_7 ;
}
struct V_26 * F_25 ( struct V_27 * V_28 ,
void T_3 * V_11 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_11 , V_17 ) ;
if ( F_26 ( V_7 ) )
return F_27 ( V_7 ) ;
return F_28 ( V_28 , & V_29 , V_7 , V_17 ) ;
}
struct V_26 * F_29 ( struct V_27 * V_28 ,
void T_3 * V_11 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_11 , V_17 ) ;
if ( F_26 ( V_7 ) )
return F_27 ( V_7 ) ;
return F_30 ( V_28 , & V_29 , V_7 , V_17 ) ;
}
