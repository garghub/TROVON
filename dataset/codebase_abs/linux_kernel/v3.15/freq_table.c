int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = ~ 0 ;
unsigned int V_6 = 0 ;
unsigned int V_7 ;
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
unsigned int V_10 = V_4 [ V_7 ] . V_8 ;
if ( V_10 == V_11 ) {
F_2 ( L_1 , V_7 ) ;
continue;
}
if ( ! F_3 ()
&& ( V_4 [ V_7 ] . V_12 & V_13 ) )
continue;
F_2 ( L_2 , V_7 , V_10 ) ;
if ( V_10 < V_5 )
V_5 = V_10 ;
if ( V_10 > V_6 )
V_6 = V_10 ;
}
V_2 -> V_14 = V_2 -> V_15 . V_5 = V_5 ;
V_2 -> V_16 = V_2 -> V_15 . V_6 = V_6 ;
if ( V_2 -> V_14 == ~ 0 )
return - V_17 ;
else
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_18 = ~ 0 , V_10 , V_7 = 0 ;
bool V_19 = false ;
F_2 ( L_3 ,
V_2 -> V_14 , V_2 -> V_16 , V_2 -> V_20 ) ;
F_5 ( V_2 ) ;
for (; V_10 = V_4 [ V_7 ] . V_8 , V_10 != V_9 ; V_7 ++ ) {
if ( V_10 == V_11 )
continue;
if ( ( V_10 >= V_2 -> V_14 ) && ( V_10 <= V_2 -> V_16 ) ) {
V_19 = true ;
break;
}
if ( ( V_18 > V_10 ) && ( V_10 > V_2 -> V_16 ) )
V_18 = V_10 ;
}
if ( ! V_19 ) {
V_2 -> V_16 = V_18 ;
F_5 ( V_2 ) ;
}
F_2 ( L_4 ,
V_2 -> V_14 , V_2 -> V_16 , V_2 -> V_20 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_7 ( V_2 -> V_20 ) ;
if ( ! V_4 )
return - V_21 ;
return F_4 ( V_2 , V_4 ) ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_22 ,
unsigned int V_23 ,
unsigned int * V_24 )
{
struct V_3 V_25 = {
. V_26 = ~ 0 ,
. V_8 = 0 ,
} ;
struct V_3 V_27 = {
. V_26 = ~ 0 ,
. V_8 = 0 ,
} ;
unsigned int V_7 ;
F_2 ( L_5 ,
V_22 , V_23 , V_2 -> V_20 ) ;
switch ( V_23 ) {
case V_28 :
V_27 . V_8 = ~ 0 ;
break;
case V_29 :
V_25 . V_8 = ~ 0 ;
break;
}
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
unsigned int V_10 = V_4 [ V_7 ] . V_8 ;
if ( V_10 == V_11 )
continue;
if ( ( V_10 < V_2 -> V_14 ) || ( V_10 > V_2 -> V_16 ) )
continue;
switch ( V_23 ) {
case V_28 :
if ( V_10 <= V_22 ) {
if ( V_10 >= V_25 . V_8 ) {
V_25 . V_8 = V_10 ;
V_25 . V_26 = V_7 ;
}
} else {
if ( V_10 <= V_27 . V_8 ) {
V_27 . V_8 = V_10 ;
V_27 . V_26 = V_7 ;
}
}
break;
case V_29 :
if ( V_10 >= V_22 ) {
if ( V_10 <= V_25 . V_8 ) {
V_25 . V_8 = V_10 ;
V_25 . V_26 = V_7 ;
}
} else {
if ( V_10 >= V_27 . V_8 ) {
V_27 . V_8 = V_10 ;
V_27 . V_26 = V_7 ;
}
}
break;
}
}
if ( V_25 . V_26 > V_7 ) {
if ( V_27 . V_26 > V_7 )
return - V_17 ;
* V_24 = V_27 . V_26 ;
} else
* V_24 = V_25 . V_26 ;
F_2 ( L_6 , * V_24 ,
V_4 [ * V_24 ] . V_8 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_7 ( V_2 -> V_20 ) ;
if ( F_10 ( ! V_4 ) ) {
F_2 ( L_7 , V_30 ) ;
return - V_31 ;
}
for ( V_7 = 0 ; V_4 [ V_7 ] . V_8 != V_9 ; V_7 ++ ) {
if ( V_4 [ V_7 ] . V_8 == V_10 )
return V_7 ;
}
return - V_17 ;
}
static T_1 F_11 ( struct V_1 * V_2 , char * V_32 ,
bool V_33 )
{
unsigned int V_7 = 0 ;
T_1 V_34 = 0 ;
struct V_3 * V_4 = V_2 -> V_35 ;
if ( ! V_4 )
return - V_21 ;
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
if ( V_4 [ V_7 ] . V_8 == V_11 )
continue;
if ( V_33 ^ ( V_4 [ V_7 ] . V_12 & V_13 ) )
continue;
V_34 += sprintf ( & V_32 [ V_34 ] , L_8 , V_4 [ V_7 ] . V_8 ) ;
}
V_34 += sprintf ( & V_32 [ V_34 ] , L_9 ) ;
return V_34 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
char * V_32 )
{
return F_11 ( V_2 , V_32 , false ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
char * V_32 )
{
return F_11 ( V_2 , V_32 , true ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_36 = F_1 ( V_2 , V_4 ) ;
if ( ! V_36 )
V_2 -> V_35 = V_4 ;
return V_36 ;
}
struct V_3 * F_7 ( unsigned int V_20 )
{
struct V_1 * V_2 = F_15 ( V_20 ) ;
return V_2 ? V_2 -> V_35 : NULL ;
}
