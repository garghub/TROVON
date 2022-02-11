static inline void F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case 1 :
case 2 :
case 4 :
#ifdef F_2
case 8 :
#endif
break;
default:
F_3 () ;
}
}
static int F_4 ( T_1 V_2 )
{
switch ( V_2 ) {
case 8 :
case 16 :
case 32 :
#ifdef F_2
case 64 :
#endif
return 0 ;
default:
return - V_3 ;
}
}
static inline void F_5 ( T_1 V_4 )
{
F_6 ( V_4 % 2 != 0 ) ;
}
static int F_7 ( void * V_5 ,
const void * V_6 , T_1 V_1 ,
const void * V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_5 ;
T_2 V_11 ;
int V_12 ;
F_1 ( V_1 ) ;
if ( ! F_8 ( V_10 -> V_13 ) ) {
V_12 = F_9 ( V_10 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_11 = * ( T_2 * ) V_6 ;
while ( V_8 ) {
switch ( V_10 -> V_14 ) {
case 1 :
F_10 ( * ( V_15 * ) V_7 , V_10 -> V_16 + V_11 ) ;
break;
case 2 :
F_11 ( * ( V_17 * ) V_7 , V_10 -> V_16 + V_11 ) ;
break;
case 4 :
F_12 ( * ( T_2 * ) V_7 , V_10 -> V_16 + V_11 ) ;
break;
#ifdef F_2
case 8 :
F_13 ( * ( V_18 * ) V_7 , V_10 -> V_16 + V_11 ) ;
break;
#endif
default:
F_3 () ;
}
V_8 -= V_10 -> V_14 ;
V_7 += V_10 -> V_14 ;
V_11 += V_10 -> V_14 ;
}
if ( ! F_8 ( V_10 -> V_13 ) )
F_14 ( V_10 -> V_13 ) ;
return 0 ;
}
static int F_15 ( void * V_5 , const void * V_19 , T_1 V_4 )
{
struct V_9 * V_10 = V_5 ;
T_2 V_11 = V_10 -> V_20 + V_10 -> V_21 ;
F_5 ( V_4 ) ;
return F_7 ( V_5 , V_19 , V_10 -> V_20 ,
V_19 + V_11 , V_4 - V_11 ) ;
}
static int F_16 ( void * V_5 ,
const void * V_6 , T_1 V_1 ,
void * V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_5 ;
T_2 V_11 ;
int V_12 ;
F_1 ( V_1 ) ;
if ( ! F_8 ( V_10 -> V_13 ) ) {
V_12 = F_9 ( V_10 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_11 = * ( T_2 * ) V_6 ;
while ( V_8 ) {
switch ( V_10 -> V_14 ) {
case 1 :
* ( V_15 * ) V_7 = F_17 ( V_10 -> V_16 + V_11 ) ;
break;
case 2 :
* ( V_17 * ) V_7 = F_18 ( V_10 -> V_16 + V_11 ) ;
break;
case 4 :
* ( T_2 * ) V_7 = F_19 ( V_10 -> V_16 + V_11 ) ;
break;
#ifdef F_2
case 8 :
* ( V_18 * ) V_7 = F_20 ( V_10 -> V_16 + V_11 ) ;
break;
#endif
default:
F_3 () ;
}
V_8 -= V_10 -> V_14 ;
V_7 += V_10 -> V_14 ;
V_11 += V_10 -> V_14 ;
}
if ( ! F_8 ( V_10 -> V_13 ) )
F_14 ( V_10 -> V_13 ) ;
return 0 ;
}
static void F_21 ( void * V_5 )
{
struct V_9 * V_10 = V_5 ;
if ( ! F_8 ( V_10 -> V_13 ) ) {
F_22 ( V_10 -> V_13 ) ;
F_23 ( V_10 -> V_13 ) ;
}
F_24 ( V_5 ) ;
}
static struct V_9 * F_25 ( struct V_22 * V_23 ,
const char * V_24 ,
void T_3 * V_16 ,
const struct V_25 * V_26 )
{
struct V_9 * V_10 ;
int V_27 ;
int V_12 ;
V_12 = F_4 ( V_26 -> V_2 ) ;
if ( V_12 )
return F_26 ( V_12 ) ;
if ( V_26 -> V_28 )
return F_26 ( - V_3 ) ;
switch ( V_26 -> V_29 ) {
case 8 :
V_27 = 0 ;
break;
case 16 :
V_27 = 2 ;
break;
case 32 :
V_27 = 4 ;
break;
#ifdef F_2
case 64 :
V_27 = 8 ;
break;
#endif
break;
default:
return F_26 ( - V_3 ) ;
}
if ( V_26 -> V_30 < V_27 )
return F_26 ( - V_3 ) ;
switch ( V_26 -> V_31 ) {
case V_32 :
case V_33 :
break;
default:
return F_26 ( - V_3 ) ;
}
V_10 = F_27 ( sizeof( * V_10 ) , V_34 ) ;
if ( ! V_10 )
return F_26 ( - V_35 ) ;
V_10 -> V_16 = V_16 ;
V_10 -> V_14 = V_26 -> V_29 / 8 ;
V_10 -> V_20 = V_26 -> V_2 / 8 ;
V_10 -> V_21 = V_26 -> V_28 / 8 ;
V_10 -> V_13 = F_26 ( - V_36 ) ;
if ( V_24 == NULL )
return V_10 ;
V_10 -> V_13 = F_28 ( V_23 , V_24 ) ;
if ( F_8 ( V_10 -> V_13 ) ) {
V_12 = F_29 ( V_10 -> V_13 ) ;
goto V_37;
}
V_12 = F_30 ( V_10 -> V_13 ) ;
if ( V_12 < 0 ) {
F_23 ( V_10 -> V_13 ) ;
goto V_37;
}
return V_10 ;
V_37:
F_24 ( V_10 ) ;
return F_26 ( V_12 ) ;
}
struct V_38 * F_31 ( struct V_22 * V_23 , const char * V_24 ,
void T_3 * V_16 ,
const struct V_25 * V_26 )
{
struct V_9 * V_10 ;
V_10 = F_25 ( V_23 , V_24 , V_16 , V_26 ) ;
if ( F_8 ( V_10 ) )
return F_32 ( V_10 ) ;
return F_33 ( V_23 , & V_39 , V_10 , V_26 ) ;
}
struct V_38 * F_34 ( struct V_22 * V_23 , const char * V_24 ,
void T_3 * V_16 ,
const struct V_25 * V_26 )
{
struct V_9 * V_10 ;
V_10 = F_25 ( V_23 , V_24 , V_16 , V_26 ) ;
if ( F_8 ( V_10 ) )
return F_32 ( V_10 ) ;
return F_35 ( V_23 , & V_39 , V_10 , V_26 ) ;
}
