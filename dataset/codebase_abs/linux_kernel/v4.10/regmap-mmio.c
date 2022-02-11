static int F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case 8 :
case 16 :
case 32 :
#ifdef F_2
case 64 :
#endif
return 0 ;
default:
return - V_2 ;
}
}
static int F_3 ( T_1 V_3 )
{
int V_4 ;
switch ( V_3 ) {
case 8 :
V_4 = 0 ;
return 0 ;
case 16 :
V_4 = 2 ;
break;
case 32 :
V_4 = 4 ;
break;
#ifdef F_2
case 64 :
V_4 = 8 ;
break;
#endif
default:
return - V_2 ;
}
return V_4 ;
}
static void F_4 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
F_5 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_6 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
F_7 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_8 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
F_9 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
F_11 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_12 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
F_13 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_14 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
F_15 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static int F_16 ( void * V_10 , unsigned int V_7 , unsigned int V_8 )
{
struct V_5 * V_6 = V_10 ;
int V_11 ;
if ( ! F_17 ( V_6 -> V_12 ) ) {
V_11 = F_18 ( V_6 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_6 -> V_13 ( V_6 , V_7 , V_8 ) ;
if ( ! F_17 ( V_6 -> V_12 ) )
F_19 ( V_6 -> V_12 ) ;
return 0 ;
}
static unsigned int F_20 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_21 ( V_6 -> V_9 + V_7 ) ;
}
static unsigned int F_22 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_23 ( V_6 -> V_9 + V_7 ) ;
}
static unsigned int F_24 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_25 ( V_6 -> V_9 + V_7 ) ;
}
static unsigned int F_26 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_27 ( V_6 -> V_9 + V_7 ) ;
}
static unsigned int F_28 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_29 ( V_6 -> V_9 + V_7 ) ;
}
static unsigned int F_30 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_31 ( V_6 -> V_9 + V_7 ) ;
}
static int F_32 ( void * V_10 , unsigned int V_7 , unsigned int * V_8 )
{
struct V_5 * V_6 = V_10 ;
int V_11 ;
if ( ! F_17 ( V_6 -> V_12 ) ) {
V_11 = F_18 ( V_6 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
}
* V_8 = V_6 -> V_14 ( V_6 , V_7 ) ;
if ( ! F_17 ( V_6 -> V_12 ) )
F_19 ( V_6 -> V_12 ) ;
return 0 ;
}
static void F_33 ( void * V_10 )
{
struct V_5 * V_6 = V_10 ;
if ( ! F_17 ( V_6 -> V_12 ) ) {
F_34 ( V_6 -> V_12 ) ;
F_35 ( V_6 -> V_12 ) ;
}
F_36 ( V_10 ) ;
}
static struct V_5 * F_37 ( struct V_15 * V_16 ,
const char * V_17 ,
void T_2 * V_9 ,
const struct V_18 * V_19 )
{
struct V_5 * V_6 ;
int V_4 ;
int V_11 ;
V_11 = F_1 ( V_19 -> V_1 ) ;
if ( V_11 )
return F_38 ( V_11 ) ;
if ( V_19 -> V_20 )
return F_38 ( - V_2 ) ;
V_4 = F_3 ( V_19 -> V_3 ) ;
if ( V_4 < 0 )
return F_38 ( V_4 ) ;
if ( V_19 -> V_21 < V_4 )
return F_38 ( - V_2 ) ;
V_6 = F_39 ( sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return F_38 ( - V_23 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_24 = V_19 -> V_3 / 8 ;
V_6 -> V_12 = F_38 ( - V_25 ) ;
switch ( F_40 ( V_16 , & V_26 , V_19 ) ) {
case V_27 :
case V_28 :
#ifdef F_41
case V_29 :
#endif
switch ( V_19 -> V_3 ) {
case 8 :
V_6 -> V_14 = F_20 ;
V_6 -> V_13 = F_4 ;
break;
case 16 :
V_6 -> V_14 = F_22 ;
V_6 -> V_13 = F_6 ;
break;
case 32 :
V_6 -> V_14 = F_26 ;
V_6 -> V_13 = F_10 ;
break;
#ifdef F_2
case 64 :
V_6 -> V_14 = F_30 ;
V_6 -> V_13 = F_14 ;
break;
#endif
default:
V_11 = - V_2 ;
goto V_30;
}
break;
case V_31 :
#ifdef F_42
case V_29 :
#endif
switch ( V_19 -> V_3 ) {
case 8 :
V_6 -> V_14 = F_20 ;
V_6 -> V_13 = F_4 ;
break;
case 16 :
V_6 -> V_14 = F_24 ;
V_6 -> V_13 = F_8 ;
break;
case 32 :
V_6 -> V_14 = F_28 ;
V_6 -> V_13 = F_12 ;
break;
default:
V_11 = - V_2 ;
goto V_30;
}
break;
default:
V_11 = - V_2 ;
goto V_30;
}
if ( V_17 == NULL )
return V_6 ;
V_6 -> V_12 = F_43 ( V_16 , V_17 ) ;
if ( F_17 ( V_6 -> V_12 ) ) {
V_11 = F_44 ( V_6 -> V_12 ) ;
goto V_30;
}
V_11 = F_45 ( V_6 -> V_12 ) ;
if ( V_11 < 0 ) {
F_35 ( V_6 -> V_12 ) ;
goto V_30;
}
return V_6 ;
V_30:
F_36 ( V_6 ) ;
return F_38 ( V_11 ) ;
}
struct V_32 * F_46 ( struct V_15 * V_16 , const char * V_17 ,
void T_2 * V_9 ,
const struct V_18 * V_19 ,
struct V_33 * V_34 ,
const char * V_35 )
{
struct V_5 * V_6 ;
V_6 = F_37 ( V_16 , V_17 , V_9 , V_19 ) ;
if ( F_17 ( V_6 ) )
return F_47 ( V_6 ) ;
return F_48 ( V_16 , & V_26 , V_6 , V_19 ,
V_34 , V_35 ) ;
}
struct V_32 * F_49 ( struct V_15 * V_16 ,
const char * V_17 ,
void T_2 * V_9 ,
const struct V_18 * V_19 ,
struct V_33 * V_34 ,
const char * V_35 )
{
struct V_5 * V_6 ;
V_6 = F_37 ( V_16 , V_17 , V_9 , V_19 ) ;
if ( F_17 ( V_6 ) )
return F_47 ( V_6 ) ;
return F_50 ( V_16 , & V_26 , V_6 , V_19 ,
V_34 , V_35 ) ;
}
