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
F_2 ( L_2 ,
V_7 , V_10 , V_4 [ V_7 ] . V_12 ) ;
if ( V_10 < V_5 )
V_5 = V_10 ;
if ( V_10 > V_6 )
V_6 = V_10 ;
}
V_2 -> V_13 = V_2 -> V_14 . V_5 = V_5 ;
V_2 -> V_15 = V_2 -> V_14 . V_6 = V_6 ;
if ( V_2 -> V_13 == ~ 0 )
return - V_16 ;
else
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_17 = ~ 0 ;
unsigned int V_7 ;
unsigned int V_18 = 0 ;
F_2 ( L_3 ,
V_2 -> V_13 , V_2 -> V_15 , V_2 -> V_19 ) ;
if ( ! F_4 ( V_2 -> V_19 ) )
return - V_16 ;
F_5 ( V_2 , V_2 -> V_14 . V_5 ,
V_2 -> V_14 . V_6 ) ;
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
unsigned int V_10 = V_4 [ V_7 ] . V_8 ;
if ( V_10 == V_11 )
continue;
if ( ( V_10 >= V_2 -> V_13 ) && ( V_10 <= V_2 -> V_15 ) )
V_18 ++ ;
else if ( ( V_17 > V_10 ) && ( V_10 > V_2 -> V_15 ) )
V_17 = V_10 ;
}
if ( ! V_18 )
V_2 -> V_15 = V_17 ;
F_5 ( V_2 , V_2 -> V_14 . V_5 ,
V_2 -> V_14 . V_6 ) ;
F_2 ( L_4 ,
V_2 -> V_13 , V_2 -> V_15 , V_2 -> V_19 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_20 ,
unsigned int V_21 ,
unsigned int * V_12 )
{
struct V_3 V_22 = {
. V_12 = ~ 0 ,
. V_8 = 0 ,
} ;
struct V_3 V_23 = {
. V_12 = ~ 0 ,
. V_8 = 0 ,
} ;
unsigned int V_7 ;
F_2 ( L_5 ,
V_20 , V_21 , V_2 -> V_19 ) ;
switch ( V_21 ) {
case V_24 :
V_23 . V_8 = ~ 0 ;
break;
case V_25 :
V_22 . V_8 = ~ 0 ;
break;
}
if ( ! F_4 ( V_2 -> V_19 ) )
return - V_16 ;
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
unsigned int V_10 = V_4 [ V_7 ] . V_8 ;
if ( V_10 == V_11 )
continue;
if ( ( V_10 < V_2 -> V_13 ) || ( V_10 > V_2 -> V_15 ) )
continue;
switch ( V_21 ) {
case V_24 :
if ( V_10 <= V_20 ) {
if ( V_10 >= V_22 . V_8 ) {
V_22 . V_8 = V_10 ;
V_22 . V_12 = V_7 ;
}
} else {
if ( V_10 <= V_23 . V_8 ) {
V_23 . V_8 = V_10 ;
V_23 . V_12 = V_7 ;
}
}
break;
case V_25 :
if ( V_10 >= V_20 ) {
if ( V_10 <= V_22 . V_8 ) {
V_22 . V_8 = V_10 ;
V_22 . V_12 = V_7 ;
}
} else {
if ( V_10 >= V_23 . V_8 ) {
V_23 . V_8 = V_10 ;
V_23 . V_12 = V_7 ;
}
}
break;
}
}
if ( V_22 . V_12 > V_7 ) {
if ( V_23 . V_12 > V_7 )
return - V_16 ;
* V_12 = V_23 . V_12 ;
} else
* V_12 = V_22 . V_12 ;
F_2 ( L_6 , * V_12 , V_4 [ * V_12 ] . V_8 ,
V_4 [ * V_12 ] . V_12 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_26 )
{
unsigned int V_7 = 0 ;
unsigned int V_19 = V_2 -> V_19 ;
T_1 V_18 = 0 ;
struct V_3 * V_4 ;
if ( ! F_8 ( V_27 , V_19 ) )
return - V_28 ;
V_4 = F_8 ( V_27 , V_19 ) ;
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
if ( V_4 [ V_7 ] . V_8 == V_11 )
continue;
V_18 += sprintf ( & V_26 [ V_18 ] , L_7 , V_4 [ V_7 ] . V_8 ) ;
}
V_18 += sprintf ( & V_26 [ V_18 ] , L_8 ) ;
return V_18 ;
}
void F_9 ( struct V_3 * V_4 ,
unsigned int V_19 )
{
F_2 ( L_9 , V_19 , V_4 ) ;
F_8 ( V_27 , V_19 ) = V_4 ;
}
void F_10 ( unsigned int V_19 )
{
F_2 ( L_10 , V_19 ) ;
F_8 ( V_27 , V_19 ) = NULL ;
}
struct V_3 * F_11 ( unsigned int V_19 )
{
return F_8 ( V_27 , V_19 ) ;
}
