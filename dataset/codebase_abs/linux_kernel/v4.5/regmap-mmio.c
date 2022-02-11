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
static int F_5 ( T_1 V_4 )
{
int V_5 ;
switch ( V_4 ) {
case 8 :
V_5 = 0 ;
return 0 ;
case 16 :
V_5 = 2 ;
break;
case 32 :
V_5 = 4 ;
break;
#ifdef F_2
case 64 :
V_5 = 8 ;
break;
#endif
default:
return - V_3 ;
}
return V_5 ;
}
static inline void F_6 ( T_1 V_6 , T_2 V_7 )
{
F_7 ( V_6 <= V_7 ) ;
}
static inline unsigned int
F_8 ( const void * V_8 , T_1 V_1 )
{
switch ( V_1 ) {
case 1 :
return * ( V_9 * ) V_8 ;
case 2 :
return * ( V_10 * ) V_8 ;
case 4 :
return * ( T_2 * ) V_8 ;
#ifdef F_2
case 8 :
return * ( V_11 * ) V_8 ;
#endif
default:
F_3 () ;
}
}
static int F_9 ( void * V_12 ,
const void * V_8 , T_1 V_1 ,
const void * V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_12 ;
unsigned int V_7 ;
int V_17 ;
F_1 ( V_1 ) ;
if ( ! F_10 ( V_16 -> V_18 ) ) {
V_17 = F_11 ( V_16 -> V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_7 = F_8 ( V_8 , V_1 ) ;
while ( V_14 ) {
switch ( V_16 -> V_19 ) {
case 1 :
F_12 ( * ( V_9 * ) V_13 , V_16 -> V_20 + V_7 ) ;
break;
case 2 :
F_13 ( * ( V_10 * ) V_13 , V_16 -> V_20 + V_7 ) ;
break;
case 4 :
F_14 ( * ( T_2 * ) V_13 , V_16 -> V_20 + V_7 ) ;
break;
#ifdef F_2
case 8 :
F_15 ( * ( V_11 * ) V_13 , V_16 -> V_20 + V_7 ) ;
break;
#endif
default:
F_3 () ;
}
V_14 -= V_16 -> V_19 ;
V_13 += V_16 -> V_19 ;
V_7 += V_16 -> V_19 ;
}
if ( ! F_10 ( V_16 -> V_18 ) )
F_16 ( V_16 -> V_18 ) ;
return 0 ;
}
static int F_17 ( void * V_12 , const void * V_21 , T_1 V_6 )
{
struct V_15 * V_16 = V_12 ;
unsigned int V_7 = V_16 -> V_22 + V_16 -> V_23 ;
F_6 ( V_6 , V_7 ) ;
return F_9 ( V_12 , V_21 , V_16 -> V_22 ,
V_21 + V_7 , V_6 - V_7 ) ;
}
static int F_18 ( void * V_12 ,
const void * V_8 , T_1 V_1 ,
void * V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_12 ;
unsigned int V_7 ;
int V_17 ;
F_1 ( V_1 ) ;
if ( ! F_10 ( V_16 -> V_18 ) ) {
V_17 = F_11 ( V_16 -> V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_7 = F_8 ( V_8 , V_1 ) ;
while ( V_14 ) {
switch ( V_16 -> V_19 ) {
case 1 :
* ( V_9 * ) V_13 = F_19 ( V_16 -> V_20 + V_7 ) ;
break;
case 2 :
* ( V_10 * ) V_13 = F_20 ( V_16 -> V_20 + V_7 ) ;
break;
case 4 :
* ( T_2 * ) V_13 = F_21 ( V_16 -> V_20 + V_7 ) ;
break;
#ifdef F_2
case 8 :
* ( V_11 * ) V_13 = F_22 ( V_16 -> V_20 + V_7 ) ;
break;
#endif
default:
F_3 () ;
}
V_14 -= V_16 -> V_19 ;
V_13 += V_16 -> V_19 ;
V_7 += V_16 -> V_19 ;
}
if ( ! F_10 ( V_16 -> V_18 ) )
F_16 ( V_16 -> V_18 ) ;
return 0 ;
}
static void F_23 ( void * V_12 )
{
struct V_15 * V_16 = V_12 ;
if ( ! F_10 ( V_16 -> V_18 ) ) {
F_24 ( V_16 -> V_18 ) ;
F_25 ( V_16 -> V_18 ) ;
}
F_26 ( V_12 ) ;
}
static struct V_15 * F_27 ( struct V_24 * V_25 ,
const char * V_26 ,
void T_3 * V_20 ,
const struct V_27 * V_28 )
{
struct V_15 * V_16 ;
int V_5 ;
int V_17 ;
V_17 = F_4 ( V_28 -> V_2 ) ;
if ( V_17 )
return F_28 ( V_17 ) ;
if ( V_28 -> V_29 )
return F_28 ( - V_3 ) ;
V_5 = F_5 ( V_28 -> V_4 ) ;
if ( V_5 < 0 )
return F_28 ( V_5 ) ;
if ( V_28 -> V_30 < V_5 )
return F_28 ( - V_3 ) ;
switch ( V_28 -> V_31 ) {
case V_32 :
case V_33 :
break;
default:
return F_28 ( - V_3 ) ;
}
V_16 = F_29 ( sizeof( * V_16 ) , V_34 ) ;
if ( ! V_16 )
return F_28 ( - V_35 ) ;
V_16 -> V_20 = V_20 ;
V_16 -> V_19 = V_28 -> V_4 / 8 ;
V_16 -> V_22 = V_28 -> V_2 / 8 ;
V_16 -> V_23 = V_28 -> V_29 / 8 ;
V_16 -> V_18 = F_28 ( - V_36 ) ;
if ( V_26 == NULL )
return V_16 ;
V_16 -> V_18 = F_30 ( V_25 , V_26 ) ;
if ( F_10 ( V_16 -> V_18 ) ) {
V_17 = F_31 ( V_16 -> V_18 ) ;
goto V_37;
}
V_17 = F_32 ( V_16 -> V_18 ) ;
if ( V_17 < 0 ) {
F_25 ( V_16 -> V_18 ) ;
goto V_37;
}
return V_16 ;
V_37:
F_26 ( V_16 ) ;
return F_28 ( V_17 ) ;
}
struct V_38 * F_33 ( struct V_24 * V_25 , const char * V_26 ,
void T_3 * V_20 ,
const struct V_27 * V_28 ,
struct V_39 * V_40 ,
const char * V_41 )
{
struct V_15 * V_16 ;
V_16 = F_27 ( V_25 , V_26 , V_20 , V_28 ) ;
if ( F_10 ( V_16 ) )
return F_34 ( V_16 ) ;
return F_35 ( V_25 , & V_42 , V_16 , V_28 ,
V_40 , V_41 ) ;
}
struct V_38 * F_36 ( struct V_24 * V_25 ,
const char * V_26 ,
void T_3 * V_20 ,
const struct V_27 * V_28 ,
struct V_39 * V_40 ,
const char * V_41 )
{
struct V_15 * V_16 ;
V_16 = F_27 ( V_25 , V_26 , V_20 , V_28 ) ;
if ( F_10 ( V_16 ) )
return F_34 ( V_16 ) ;
return F_37 ( V_25 , & V_42 , V_16 , V_28 ,
V_40 , V_41 ) ;
}
