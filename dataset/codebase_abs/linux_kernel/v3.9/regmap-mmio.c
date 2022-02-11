static int F_1 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_2 V_8 ;
int V_9 ;
F_2 ( V_3 != 4 ) ;
if ( V_7 -> V_10 ) {
V_9 = F_3 ( V_7 -> V_10 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_8 = * ( T_2 * ) V_2 ;
while ( V_5 ) {
switch ( V_7 -> V_11 ) {
case 1 :
F_4 ( * ( V_12 * ) V_4 , V_7 -> V_13 + V_8 ) ;
break;
case 2 :
F_5 ( * ( V_14 * ) V_4 , V_7 -> V_13 + V_8 ) ;
break;
case 4 :
F_6 ( * ( T_2 * ) V_4 , V_7 -> V_13 + V_8 ) ;
break;
#ifdef F_7
case 8 :
F_8 ( * ( V_15 * ) V_4 , V_7 -> V_13 + V_8 ) ;
break;
#endif
default:
F_9 () ;
}
V_5 -= V_7 -> V_11 ;
V_4 += V_7 -> V_11 ;
V_8 += V_7 -> V_11 ;
}
if ( V_7 -> V_10 )
F_10 ( V_7 -> V_10 ) ;
return 0 ;
}
static int F_11 ( void * V_1 , const void * V_16 , T_1 V_17 )
{
F_2 ( V_17 < 4 ) ;
return F_1 ( V_1 , V_16 , 4 , V_16 + 4 , V_17 - 4 ) ;
}
static int F_12 ( void * V_1 ,
const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_2 V_8 ;
int V_9 ;
F_2 ( V_3 != 4 ) ;
if ( V_7 -> V_10 ) {
V_9 = F_3 ( V_7 -> V_10 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_8 = * ( T_2 * ) V_2 ;
while ( V_5 ) {
switch ( V_7 -> V_11 ) {
case 1 :
* ( V_12 * ) V_4 = F_13 ( V_7 -> V_13 + V_8 ) ;
break;
case 2 :
* ( V_14 * ) V_4 = F_14 ( V_7 -> V_13 + V_8 ) ;
break;
case 4 :
* ( T_2 * ) V_4 = F_15 ( V_7 -> V_13 + V_8 ) ;
break;
#ifdef F_7
case 8 :
* ( V_15 * ) V_4 = F_16 ( V_7 -> V_13 + V_8 ) ;
break;
#endif
default:
F_9 () ;
}
V_5 -= V_7 -> V_11 ;
V_4 += V_7 -> V_11 ;
V_8 += V_7 -> V_11 ;
}
if ( V_7 -> V_10 )
F_10 ( V_7 -> V_10 ) ;
return 0 ;
}
static void F_17 ( void * V_1 )
{
struct V_6 * V_7 = V_1 ;
if ( V_7 -> V_10 ) {
F_18 ( V_7 -> V_10 ) ;
F_19 ( V_7 -> V_10 ) ;
}
F_20 ( V_1 ) ;
}
static struct V_6 * F_21 ( struct V_18 * V_19 ,
const char * V_20 ,
void T_3 * V_13 ,
const struct V_21 * V_22 )
{
struct V_6 * V_7 ;
int V_23 ;
int V_9 ;
if ( V_22 -> V_24 != 32 )
return F_22 ( - V_25 ) ;
if ( V_22 -> V_26 )
return F_22 ( - V_25 ) ;
switch ( V_22 -> V_27 ) {
case 8 :
V_23 = 0 ;
break;
case 16 :
V_23 = 2 ;
break;
case 32 :
V_23 = 4 ;
break;
#ifdef F_7
case 64 :
V_23 = 8 ;
break;
#endif
break;
default:
return F_22 ( - V_25 ) ;
}
if ( V_22 -> V_28 < V_23 )
return F_22 ( - V_25 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
case V_31 :
break;
default:
return F_22 ( - V_25 ) ;
}
V_7 = F_23 ( sizeof( * V_7 ) , V_32 ) ;
if ( ! V_7 )
return F_22 ( - V_33 ) ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_22 -> V_27 / 8 ;
if ( V_20 == NULL )
return V_7 ;
V_7 -> V_10 = F_24 ( V_19 , V_20 ) ;
if ( F_25 ( V_7 -> V_10 ) ) {
V_9 = F_26 ( V_7 -> V_10 ) ;
goto V_34;
}
V_9 = F_27 ( V_7 -> V_10 ) ;
if ( V_9 < 0 ) {
F_19 ( V_7 -> V_10 ) ;
goto V_34;
}
return V_7 ;
V_34:
F_20 ( V_7 ) ;
return F_22 ( V_9 ) ;
}
struct V_35 * F_28 ( struct V_18 * V_19 , const char * V_20 ,
void T_3 * V_13 ,
const struct V_21 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_21 ( V_19 , V_20 , V_13 , V_22 ) ;
if ( F_25 ( V_7 ) )
return F_29 ( V_7 ) ;
return F_30 ( V_19 , & V_36 , V_7 , V_22 ) ;
}
struct V_35 * F_31 ( struct V_18 * V_19 , const char * V_20 ,
void T_3 * V_13 ,
const struct V_21 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_21 ( V_19 , V_20 , V_13 , V_22 ) ;
if ( F_25 ( V_7 ) )
return F_29 ( V_7 ) ;
return F_32 ( V_19 , & V_36 , V_7 , V_22 ) ;
}
