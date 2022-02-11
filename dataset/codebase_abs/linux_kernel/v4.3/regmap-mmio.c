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
static inline void F_5 ( T_1 V_4 , T_2 V_5 )
{
F_6 ( V_4 <= V_5 ) ;
}
static inline unsigned int
F_7 ( const void * V_6 , T_1 V_1 )
{
switch ( V_1 ) {
case 1 :
return * ( V_7 * ) V_6 ;
case 2 :
return * ( V_8 * ) V_6 ;
case 4 :
return * ( T_2 * ) V_6 ;
#ifdef F_2
case 8 :
return * ( V_9 * ) V_6 ;
#endif
default:
F_3 () ;
}
}
static int F_8 ( void * V_10 ,
const void * V_6 , T_1 V_1 ,
const void * V_11 , T_1 V_12 )
{
struct V_13 * V_14 = V_10 ;
unsigned int V_5 ;
int V_15 ;
F_1 ( V_1 ) ;
if ( ! F_9 ( V_14 -> V_16 ) ) {
V_15 = F_10 ( V_14 -> V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_5 = F_7 ( V_6 , V_1 ) ;
while ( V_12 ) {
switch ( V_14 -> V_17 ) {
case 1 :
F_11 ( * ( V_7 * ) V_11 , V_14 -> V_18 + V_5 ) ;
break;
case 2 :
F_12 ( * ( V_8 * ) V_11 , V_14 -> V_18 + V_5 ) ;
break;
case 4 :
F_13 ( * ( T_2 * ) V_11 , V_14 -> V_18 + V_5 ) ;
break;
#ifdef F_2
case 8 :
F_14 ( * ( V_9 * ) V_11 , V_14 -> V_18 + V_5 ) ;
break;
#endif
default:
F_3 () ;
}
V_12 -= V_14 -> V_17 ;
V_11 += V_14 -> V_17 ;
V_5 += V_14 -> V_17 ;
}
if ( ! F_9 ( V_14 -> V_16 ) )
F_15 ( V_14 -> V_16 ) ;
return 0 ;
}
static int F_16 ( void * V_10 , const void * V_19 , T_1 V_4 )
{
struct V_13 * V_14 = V_10 ;
unsigned int V_5 = V_14 -> V_20 + V_14 -> V_21 ;
F_5 ( V_4 , V_5 ) ;
return F_8 ( V_10 , V_19 , V_14 -> V_20 ,
V_19 + V_5 , V_4 - V_5 ) ;
}
static int F_17 ( void * V_10 ,
const void * V_6 , T_1 V_1 ,
void * V_11 , T_1 V_12 )
{
struct V_13 * V_14 = V_10 ;
unsigned int V_5 ;
int V_15 ;
F_1 ( V_1 ) ;
if ( ! F_9 ( V_14 -> V_16 ) ) {
V_15 = F_10 ( V_14 -> V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_5 = F_7 ( V_6 , V_1 ) ;
while ( V_12 ) {
switch ( V_14 -> V_17 ) {
case 1 :
* ( V_7 * ) V_11 = F_18 ( V_14 -> V_18 + V_5 ) ;
break;
case 2 :
* ( V_8 * ) V_11 = F_19 ( V_14 -> V_18 + V_5 ) ;
break;
case 4 :
* ( T_2 * ) V_11 = F_20 ( V_14 -> V_18 + V_5 ) ;
break;
#ifdef F_2
case 8 :
* ( V_9 * ) V_11 = F_21 ( V_14 -> V_18 + V_5 ) ;
break;
#endif
default:
F_3 () ;
}
V_12 -= V_14 -> V_17 ;
V_11 += V_14 -> V_17 ;
V_5 += V_14 -> V_17 ;
}
if ( ! F_9 ( V_14 -> V_16 ) )
F_15 ( V_14 -> V_16 ) ;
return 0 ;
}
static void F_22 ( void * V_10 )
{
struct V_13 * V_14 = V_10 ;
if ( ! F_9 ( V_14 -> V_16 ) ) {
F_23 ( V_14 -> V_16 ) ;
F_24 ( V_14 -> V_16 ) ;
}
F_25 ( V_10 ) ;
}
static struct V_13 * F_26 ( struct V_22 * V_23 ,
const char * V_24 ,
void T_3 * V_18 ,
const struct V_25 * V_26 )
{
struct V_13 * V_14 ;
int V_27 ;
int V_15 ;
V_15 = F_4 ( V_26 -> V_2 ) ;
if ( V_15 )
return F_27 ( V_15 ) ;
if ( V_26 -> V_28 )
return F_27 ( - V_3 ) ;
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
return F_27 ( - V_3 ) ;
}
if ( V_26 -> V_30 < V_27 )
return F_27 ( - V_3 ) ;
switch ( V_26 -> V_31 ) {
case V_32 :
case V_33 :
break;
default:
return F_27 ( - V_3 ) ;
}
V_14 = F_28 ( sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return F_27 ( - V_35 ) ;
V_14 -> V_18 = V_18 ;
V_14 -> V_17 = V_26 -> V_29 / 8 ;
V_14 -> V_20 = V_26 -> V_2 / 8 ;
V_14 -> V_21 = V_26 -> V_28 / 8 ;
V_14 -> V_16 = F_27 ( - V_36 ) ;
if ( V_24 == NULL )
return V_14 ;
V_14 -> V_16 = F_29 ( V_23 , V_24 ) ;
if ( F_9 ( V_14 -> V_16 ) ) {
V_15 = F_30 ( V_14 -> V_16 ) ;
goto V_37;
}
V_15 = F_31 ( V_14 -> V_16 ) ;
if ( V_15 < 0 ) {
F_24 ( V_14 -> V_16 ) ;
goto V_37;
}
return V_14 ;
V_37:
F_25 ( V_14 ) ;
return F_27 ( V_15 ) ;
}
struct V_38 * F_32 ( struct V_22 * V_23 , const char * V_24 ,
void T_3 * V_18 ,
const struct V_25 * V_26 ,
struct V_39 * V_40 ,
const char * V_41 )
{
struct V_13 * V_14 ;
V_14 = F_26 ( V_23 , V_24 , V_18 , V_26 ) ;
if ( F_9 ( V_14 ) )
return F_33 ( V_14 ) ;
return F_34 ( V_23 , & V_42 , V_14 , V_26 ,
V_40 , V_41 ) ;
}
struct V_38 * F_35 ( struct V_22 * V_23 ,
const char * V_24 ,
void T_3 * V_18 ,
const struct V_25 * V_26 ,
struct V_39 * V_40 ,
const char * V_41 )
{
struct V_13 * V_14 ;
V_14 = F_26 ( V_23 , V_24 , V_18 , V_26 ) ;
if ( F_9 ( V_14 ) )
return F_33 ( V_14 ) ;
return F_36 ( V_23 , & V_42 , V_14 , V_26 ,
V_40 , V_41 ) ;
}
