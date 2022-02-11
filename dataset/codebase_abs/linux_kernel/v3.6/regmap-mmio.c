static int F_1 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_2 V_8 ;
F_2 ( V_3 != 4 ) ;
V_8 = * ( T_2 * ) V_2 ;
while ( V_5 ) {
switch ( V_7 -> V_9 ) {
case 1 :
F_3 ( * ( V_10 * ) V_4 , V_7 -> V_11 + V_8 ) ;
break;
case 2 :
F_4 ( * ( V_12 * ) V_4 , V_7 -> V_11 + V_8 ) ;
break;
case 4 :
F_5 ( * ( T_2 * ) V_4 , V_7 -> V_11 + V_8 ) ;
break;
#ifdef F_6
case 8 :
F_7 ( * ( V_13 * ) V_4 , V_7 -> V_11 + V_8 ) ;
break;
#endif
default:
F_8 () ;
}
V_5 -= V_7 -> V_9 ;
V_4 += V_7 -> V_9 ;
V_8 += V_7 -> V_9 ;
}
return 0 ;
}
static int F_9 ( void * V_1 , const void * V_14 , T_1 V_15 )
{
F_2 ( V_15 < 4 ) ;
return F_1 ( V_1 , V_14 , 4 , V_14 + 4 , V_15 - 4 ) ;
}
static int F_10 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_2 V_8 ;
F_2 ( V_3 != 4 ) ;
V_8 = * ( T_2 * ) V_2 ;
while ( V_5 ) {
switch ( V_7 -> V_9 ) {
case 1 :
* ( V_10 * ) V_4 = F_11 ( V_7 -> V_11 + V_8 ) ;
break;
case 2 :
* ( V_12 * ) V_4 = F_12 ( V_7 -> V_11 + V_8 ) ;
break;
case 4 :
* ( T_2 * ) V_4 = F_13 ( V_7 -> V_11 + V_8 ) ;
break;
#ifdef F_6
case 8 :
* ( V_13 * ) V_4 = F_14 ( V_7 -> V_11 + V_8 ) ;
break;
#endif
default:
F_8 () ;
}
V_5 -= V_7 -> V_9 ;
V_4 += V_7 -> V_9 ;
V_8 += V_7 -> V_9 ;
}
return 0 ;
}
static void F_15 ( void * V_1 )
{
F_16 ( V_1 ) ;
}
static struct V_6 * F_17 ( void T_3 * V_11 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 ;
int V_18 ;
if ( V_17 -> V_19 != 32 )
return F_18 ( - V_20 ) ;
if ( V_17 -> V_21 )
return F_18 ( - V_20 ) ;
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
#ifdef F_6
case 64 :
V_18 = 8 ;
break;
#endif
break;
default:
return F_18 ( - V_20 ) ;
}
if ( V_17 -> V_23 < V_18 )
return F_18 ( - V_20 ) ;
switch ( V_17 -> V_24 ) {
case V_25 :
case V_26 :
break;
default:
return F_18 ( - V_20 ) ;
}
V_7 = F_19 ( sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return F_18 ( - V_28 ) ;
V_7 -> V_11 = V_11 ;
V_7 -> V_9 = V_17 -> V_22 / 8 ;
return V_7 ;
}
struct V_29 * F_20 ( struct V_30 * V_31 ,
void T_3 * V_11 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 ;
V_7 = F_17 ( V_11 , V_17 ) ;
if ( F_21 ( V_7 ) )
return F_22 ( V_7 ) ;
return F_23 ( V_31 , & V_32 , V_7 , V_17 ) ;
}
struct V_29 * F_24 ( struct V_30 * V_31 ,
void T_3 * V_11 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 ;
V_7 = F_17 ( V_11 , V_17 ) ;
if ( F_21 ( V_7 ) )
return F_22 ( V_7 ) ;
return F_25 ( V_31 , & V_32 , V_7 , V_17 ) ;
}
