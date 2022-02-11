static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
unsigned long long V_11 ;
switch ( V_7 ) {
case V_12 :
return F_3 ( V_9 -> V_13 , V_5 ) ;
case V_14 :
V_10 = F_4 ( V_9 -> V_13 , V_5 , V_6 ) ;
switch ( V_10 ) {
case V_15 :
V_11 = * V_5 * 1000000000LL ;
F_5 ( V_11 , V_9 -> V_16 ) ;
V_11 *= F_6 ( V_9 -> V_17 ) / 1000 ;
F_5 ( V_11 , 1000000000LL ) ;
* V_5 = V_11 ;
return V_10 ;
case V_18 :
* V_6 = 1 ;
V_10 = V_19 ;
case V_19 :
* V_5 *= F_6 ( V_9 -> V_17 ) / 1000 ;
* V_6 *= V_9 -> V_16 ;
break;
}
return V_10 ;
}
return - V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
const int * * V_21 , int * type , int * V_22 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_12 :
* type = V_18 ;
return F_8 ( V_9 -> V_13 , V_21 , V_22 ) ;
}
return - V_20 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_12 :
return F_10 ( V_9 -> V_13 , V_5 ) ;
}
return - V_20 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long long V_11 ;
int V_10 ;
int V_5 ;
int V_6 ;
int V_25 ;
V_10 = F_12 ( V_9 -> V_13 , & V_25 ) ;
if ( V_10 < 0 ) {
F_13 ( V_24 , L_1 ) ;
return V_10 ;
}
switch ( F_4 ( V_9 -> V_13 , & V_5 , & V_6 ) ) {
case V_18 :
return V_25 * V_5 ;
case V_19 :
V_11 = ( unsigned long long ) V_25 * V_5 ;
F_5 ( V_11 , V_6 ) ;
return V_11 ;
case V_15 :
V_11 = V_5 * 1000000000LL * V_25 >> V_6 ;
F_5 ( V_11 , 1000000000LL ) ;
return V_11 ;
default:
F_13 ( V_24 , L_2 ) ;
}
return - V_20 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_23 * V_24 = & V_27 -> V_24 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
enum V_28 type ;
int V_10 ;
V_2 = F_15 ( V_24 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_29 ;
F_16 ( V_27 , V_2 ) ;
V_9 = F_2 ( V_2 ) ;
V_2 -> V_30 = F_17 ( V_24 ) ;
V_2 -> V_24 . V_31 = V_24 ;
V_2 -> V_32 = & V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = 1 ;
V_9 -> V_17 = F_18 ( V_24 , L_3 ) ;
if ( F_19 ( V_9 -> V_17 ) ) {
if ( F_20 ( V_9 -> V_17 ) != - V_39 )
F_13 ( & V_27 -> V_24 , L_4 ) ;
return F_20 ( V_9 -> V_17 ) ;
}
V_9 -> V_13 = F_21 ( V_24 , L_5 ) ;
if ( F_19 ( V_9 -> V_13 ) ) {
if ( F_20 ( V_9 -> V_13 ) != - V_39 )
F_13 ( V_24 , L_6 ) ;
return F_20 ( V_9 -> V_13 ) ;
}
V_10 = F_22 ( V_9 -> V_13 , & type ) ;
if ( V_10 < 0 )
return V_10 ;
if ( type != V_40 ) {
F_13 ( V_24 , L_7 ) ;
return - V_20 ;
}
V_10 = F_11 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_9 -> V_16 = V_10 ;
V_10 = F_23 ( V_9 -> V_17 ) ;
if ( V_10 ) {
F_13 ( V_24 , L_8 ) ;
return V_10 ;
}
V_10 = F_24 ( V_2 ) ;
if ( V_10 ) {
F_13 ( V_24 , L_9 ) ;
goto V_41;
}
return 0 ;
V_41:
F_25 ( V_9 -> V_17 ) ;
return V_10 ;
}
static int F_26 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_27 ( V_27 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_28 ( V_2 ) ;
F_25 ( V_9 -> V_17 ) ;
return 0 ;
}
