int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
unsigned int V_6 = ~ 0 ;
unsigned int V_7 = 0 ;
unsigned int V_8 ;
F_2 (pos, table) {
V_8 = V_5 -> V_9 ;
if ( ! F_3 ()
&& ( V_5 -> V_10 & V_11 ) )
continue;
F_4 ( L_1 , ( int ) ( V_5 - V_4 ) , V_8 ) ;
if ( V_8 < V_6 )
V_6 = V_8 ;
if ( V_8 > V_7 )
V_7 = V_8 ;
}
V_2 -> V_12 = V_2 -> V_13 . V_6 = V_6 ;
V_2 -> V_14 = V_2 -> V_13 . V_7 = V_7 ;
if ( V_2 -> V_12 == ~ 0 )
return - V_15 ;
else
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
unsigned int V_8 , V_16 = ~ 0 ;
bool V_17 = false ;
F_4 ( L_2 ,
V_2 -> V_12 , V_2 -> V_14 , V_2 -> V_18 ) ;
F_6 ( V_2 ) ;
F_2 (pos, table) {
V_8 = V_5 -> V_9 ;
if ( ( V_8 >= V_2 -> V_12 ) && ( V_8 <= V_2 -> V_14 ) ) {
V_17 = true ;
break;
}
if ( ( V_16 > V_8 ) && ( V_8 > V_2 -> V_14 ) )
V_16 = V_8 ;
}
if ( ! V_17 ) {
V_2 -> V_14 = V_16 ;
F_6 ( V_2 ) ;
}
F_4 ( L_3 ,
V_2 -> V_12 , V_2 -> V_14 , V_2 -> V_18 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_8 ( V_2 -> V_18 ) ;
if ( ! V_4 )
return - V_19 ;
return F_5 ( V_2 , V_4 ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_20 ,
unsigned int V_21 ,
unsigned int * V_22 )
{
struct V_3 V_23 = {
. V_24 = ~ 0 ,
. V_9 = 0 ,
} ;
struct V_3 V_25 = {
. V_24 = ~ 0 ,
. V_9 = 0 ,
} ;
struct V_3 * V_5 ;
unsigned int V_8 , V_26 = 0 ;
F_4 ( L_4 ,
V_20 , V_21 , V_2 -> V_18 ) ;
switch ( V_21 ) {
case V_27 :
V_25 . V_9 = ~ 0 ;
break;
case V_28 :
V_23 . V_9 = ~ 0 ;
break;
}
F_2 (pos, table) {
V_8 = V_5 -> V_9 ;
V_26 = V_5 - V_4 ;
if ( ( V_8 < V_2 -> V_12 ) || ( V_8 > V_2 -> V_14 ) )
continue;
if ( V_8 == V_20 ) {
V_23 . V_24 = V_26 ;
break;
}
switch ( V_21 ) {
case V_27 :
if ( V_8 < V_20 ) {
if ( V_8 >= V_23 . V_9 ) {
V_23 . V_9 = V_8 ;
V_23 . V_24 = V_26 ;
}
} else {
if ( V_8 <= V_25 . V_9 ) {
V_25 . V_9 = V_8 ;
V_25 . V_24 = V_26 ;
}
}
break;
case V_28 :
if ( V_8 > V_20 ) {
if ( V_8 <= V_23 . V_9 ) {
V_23 . V_9 = V_8 ;
V_23 . V_24 = V_26 ;
}
} else {
if ( V_8 >= V_25 . V_9 ) {
V_25 . V_9 = V_8 ;
V_25 . V_24 = V_26 ;
}
}
break;
}
}
if ( V_23 . V_24 > V_26 ) {
if ( V_25 . V_24 > V_26 )
return - V_15 ;
* V_22 = V_25 . V_24 ;
} else
* V_22 = V_23 . V_24 ;
F_4 ( L_5 , * V_22 ,
V_4 [ * V_22 ] . V_9 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
struct V_3 * V_5 , * V_4 ;
V_4 = F_8 ( V_2 -> V_18 ) ;
if ( F_11 ( ! V_4 ) ) {
F_4 ( L_6 , V_29 ) ;
return - V_30 ;
}
F_2 (pos, table)
if ( V_5 -> V_9 == V_8 )
return V_5 - V_4 ;
return - V_15 ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_31 ,
bool V_32 )
{
T_1 V_33 = 0 ;
struct V_3 * V_5 , * V_4 = V_2 -> V_34 ;
if ( ! V_4 )
return - V_19 ;
F_2 (pos, table) {
if ( V_32 ^ ( V_5 -> V_10 & V_11 ) )
continue;
V_33 += sprintf ( & V_31 [ V_33 ] , L_7 , V_5 -> V_9 ) ;
}
V_33 += sprintf ( & V_31 [ V_33 ] , L_8 ) ;
return V_33 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
char * V_31 )
{
return F_12 ( V_2 , V_31 , false ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
char * V_31 )
{
return F_12 ( V_2 , V_31 , true ) ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_35 = F_1 ( V_2 , V_4 ) ;
if ( ! V_35 )
V_2 -> V_34 = V_4 ;
return V_35 ;
}
struct V_3 * F_8 ( unsigned int V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
return V_2 ? V_2 -> V_34 : NULL ;
}
