bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return false ;
F_2 (pos, table)
if ( V_4 -> V_7 & V_8 )
return true ;
return false ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_3 * V_4 ;
unsigned int V_9 = ~ 0 ;
unsigned int V_10 = 0 ;
unsigned int V_11 ;
F_2 (pos, table) {
V_11 = V_4 -> V_12 ;
if ( ! F_4 ()
&& ( V_4 -> V_7 & V_8 ) )
continue;
F_5 ( L_1 , ( int ) ( V_4 - V_5 ) , V_11 ) ;
if ( V_11 < V_9 )
V_9 = V_11 ;
if ( V_11 > V_10 )
V_10 = V_11 ;
}
V_2 -> V_13 = V_2 -> V_14 . V_9 = V_9 ;
V_2 -> V_15 = V_2 -> V_14 . V_10 = V_10 ;
if ( V_2 -> V_13 == ~ 0 )
return - V_16 ;
else
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_3 * V_4 ;
unsigned int V_11 , V_17 = ~ 0 ;
bool V_18 = false ;
F_5 ( L_2 ,
V_2 -> V_13 , V_2 -> V_15 , V_2 -> V_19 ) ;
F_7 ( V_2 ) ;
F_2 (pos, table) {
V_11 = V_4 -> V_12 ;
if ( ( V_11 >= V_2 -> V_13 ) && ( V_11 <= V_2 -> V_15 ) ) {
V_18 = true ;
break;
}
if ( ( V_17 > V_11 ) && ( V_11 > V_2 -> V_15 ) )
V_17 = V_11 ;
}
if ( ! V_18 ) {
V_2 -> V_15 = V_17 ;
F_7 ( V_2 ) ;
}
F_5 ( L_3 ,
V_2 -> V_13 , V_2 -> V_15 , V_2 -> V_19 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 )
return - V_20 ;
return F_6 ( V_2 , V_2 -> V_6 ) ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned int V_21 ,
unsigned int V_22 )
{
struct V_3 V_23 = {
. V_24 = ~ 0 ,
. V_12 = 0 ,
} ;
struct V_3 V_25 = {
. V_24 = ~ 0 ,
. V_12 = 0 ,
} ;
struct V_3 * V_4 ;
struct V_3 * V_5 = V_2 -> V_6 ;
unsigned int V_11 , V_26 , V_27 = 0 ;
int V_28 ;
F_5 ( L_4 ,
V_21 , V_22 , V_2 -> V_19 ) ;
switch ( V_22 ) {
case V_29 :
V_25 . V_12 = ~ 0 ;
break;
case V_30 :
case V_31 :
V_23 . V_12 = ~ 0 ;
break;
}
F_2 (pos, table) {
V_11 = V_4 -> V_12 ;
V_27 = V_4 - V_5 ;
if ( ( V_11 < V_2 -> V_13 ) || ( V_11 > V_2 -> V_15 ) )
continue;
if ( V_11 == V_21 ) {
V_23 . V_24 = V_27 ;
break;
}
switch ( V_22 ) {
case V_29 :
if ( V_11 < V_21 ) {
if ( V_11 >= V_23 . V_12 ) {
V_23 . V_12 = V_11 ;
V_23 . V_24 = V_27 ;
}
} else {
if ( V_11 <= V_25 . V_12 ) {
V_25 . V_12 = V_11 ;
V_25 . V_24 = V_27 ;
}
}
break;
case V_30 :
if ( V_11 > V_21 ) {
if ( V_11 <= V_23 . V_12 ) {
V_23 . V_12 = V_11 ;
V_23 . V_24 = V_27 ;
}
} else {
if ( V_11 >= V_25 . V_12 ) {
V_25 . V_12 = V_11 ;
V_25 . V_24 = V_27 ;
}
}
break;
case V_31 :
V_26 = abs ( V_11 - V_21 ) ;
if ( V_26 < V_23 . V_12 ||
( V_26 == V_23 . V_12 &&
V_11 > V_5 [ V_23 . V_24 ] . V_12 ) ) {
V_23 . V_12 = V_26 ;
V_23 . V_24 = V_27 ;
}
break;
}
}
if ( V_23 . V_24 > V_27 ) {
if ( V_25 . V_24 > V_27 ) {
F_10 ( 1 , L_5 , V_2 -> V_19 ) ;
return 0 ;
}
V_28 = V_25 . V_24 ;
} else
V_28 = V_23 . V_24 ;
F_5 ( L_6 , V_28 ,
V_5 [ V_28 ] . V_12 ) ;
return V_28 ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_3 * V_4 , * V_5 = V_2 -> V_6 ;
if ( F_12 ( ! V_5 ) ) {
F_5 ( L_7 , V_32 ) ;
return - V_33 ;
}
F_2 (pos, table)
if ( V_4 -> V_12 == V_11 )
return V_4 - V_5 ;
return - V_16 ;
}
static T_1 F_13 ( struct V_1 * V_2 , char * V_34 ,
bool V_35 )
{
T_1 V_36 = 0 ;
struct V_3 * V_4 , * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return - V_20 ;
F_2 (pos, table) {
if ( V_35 ^ ( V_4 -> V_7 & V_8 ) )
continue;
V_36 += sprintf ( & V_34 [ V_36 ] , L_8 , V_4 -> V_12 ) ;
}
V_36 += sprintf ( & V_34 [ V_36 ] , L_9 ) ;
return V_36 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
char * V_34 )
{
return F_13 ( V_2 , V_34 , false ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
char * V_34 )
{
return F_13 ( V_2 , V_34 , true ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = V_2 -> V_6 ;
struct V_3 * V_37 = NULL ;
int V_38 = 0 ;
V_2 -> V_39 = V_40 ;
F_2 (pos, table) {
if ( ! V_37 ) {
V_37 = V_4 ;
continue;
}
if ( V_4 -> V_12 == V_37 -> V_12 ) {
F_17 ( L_10 ,
V_4 -> V_12 ) ;
return - V_16 ;
}
if ( V_4 -> V_12 > V_37 -> V_12 ) {
if ( V_38 < 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
V_38 ++ ;
} else {
if ( V_38 > 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
V_38 -- ;
}
V_37 = V_4 ;
}
if ( V_38 > 0 )
V_2 -> V_39 = V_41 ;
else
V_2 -> V_39 = V_42 ;
F_5 ( L_12 ,
V_38 > 0 ? L_13 : L_14 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
int V_43 ;
V_43 = F_3 ( V_2 , V_5 ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_6 = V_5 ;
return F_16 ( V_2 ) ;
}
