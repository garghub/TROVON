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
unsigned int V_17 = ~ 0 , V_10 , V_7 = 0 ;
bool V_18 = false ;
F_2 ( L_3 ,
V_2 -> V_13 , V_2 -> V_15 , V_2 -> V_19 ) ;
F_4 ( V_2 ) ;
for (; V_10 = V_4 [ V_7 ] . V_8 , V_10 != V_9 ; V_7 ++ ) {
if ( V_10 == V_11 )
continue;
if ( ( V_10 >= V_2 -> V_13 ) && ( V_10 <= V_2 -> V_15 ) ) {
V_18 = true ;
break;
}
if ( ( V_17 > V_10 ) && ( V_10 > V_2 -> V_15 ) )
V_17 = V_10 ;
}
if ( ! V_18 ) {
V_2 -> V_15 = V_17 ;
F_4 ( V_2 ) ;
}
F_2 ( L_4 ,
V_2 -> V_13 , V_2 -> V_15 , V_2 -> V_19 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_6 ( V_2 -> V_19 ) ;
if ( ! V_4 )
return - V_20 ;
return F_3 ( V_2 , V_4 ) ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_21 ,
unsigned int V_22 ,
unsigned int * V_23 )
{
struct V_3 V_24 = {
. V_12 = ~ 0 ,
. V_8 = 0 ,
} ;
struct V_3 V_25 = {
. V_12 = ~ 0 ,
. V_8 = 0 ,
} ;
unsigned int V_7 ;
F_2 ( L_5 ,
V_21 , V_22 , V_2 -> V_19 ) ;
switch ( V_22 ) {
case V_26 :
V_25 . V_8 = ~ 0 ;
break;
case V_27 :
V_24 . V_8 = ~ 0 ;
break;
}
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
unsigned int V_10 = V_4 [ V_7 ] . V_8 ;
if ( V_10 == V_11 )
continue;
if ( ( V_10 < V_2 -> V_13 ) || ( V_10 > V_2 -> V_15 ) )
continue;
switch ( V_22 ) {
case V_26 :
if ( V_10 <= V_21 ) {
if ( V_10 >= V_24 . V_8 ) {
V_24 . V_8 = V_10 ;
V_24 . V_12 = V_7 ;
}
} else {
if ( V_10 <= V_25 . V_8 ) {
V_25 . V_8 = V_10 ;
V_25 . V_12 = V_7 ;
}
}
break;
case V_27 :
if ( V_10 >= V_21 ) {
if ( V_10 <= V_24 . V_8 ) {
V_24 . V_8 = V_10 ;
V_24 . V_12 = V_7 ;
}
} else {
if ( V_10 >= V_25 . V_8 ) {
V_25 . V_8 = V_10 ;
V_25 . V_12 = V_7 ;
}
}
break;
}
}
if ( V_24 . V_12 > V_7 ) {
if ( V_25 . V_12 > V_7 )
return - V_16 ;
* V_23 = V_25 . V_12 ;
} else
* V_23 = V_24 . V_12 ;
F_2 ( L_6 , * V_23 , V_4 [ * V_23 ] . V_8 ,
V_4 [ * V_23 ] . V_12 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 , char * V_28 )
{
unsigned int V_7 = 0 ;
unsigned int V_19 = V_2 -> V_19 ;
T_1 V_29 = 0 ;
struct V_3 * V_4 ;
if ( ! F_9 ( V_30 , V_19 ) )
return - V_20 ;
V_4 = F_9 ( V_30 , V_19 ) ;
for ( V_7 = 0 ; ( V_4 [ V_7 ] . V_8 != V_9 ) ; V_7 ++ ) {
if ( V_4 [ V_7 ] . V_8 == V_11 )
continue;
V_29 += sprintf ( & V_28 [ V_29 ] , L_7 , V_4 [ V_7 ] . V_8 ) ;
}
V_29 += sprintf ( & V_28 [ V_29 ] , L_8 ) ;
return V_29 ;
}
void F_10 ( struct V_3 * V_4 ,
unsigned int V_19 )
{
F_2 ( L_9 , V_19 , V_4 ) ;
F_9 ( V_30 , V_19 ) = V_4 ;
}
void F_11 ( unsigned int V_19 )
{
F_2 ( L_10 , V_19 ) ;
F_9 ( V_30 , V_19 ) = NULL ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_31 = F_1 ( V_2 , V_4 ) ;
if ( ! V_31 )
F_10 ( V_4 , V_2 -> V_19 ) ;
return V_31 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_2 ( L_11 ,
V_2 -> V_19 , V_2 -> V_32 ) ;
F_9 ( V_30 , V_2 -> V_19 ) = F_9 ( V_30 ,
V_2 -> V_32 ) ;
F_9 ( V_30 , V_2 -> V_32 ) = NULL ;
}
struct V_3 * F_6 ( unsigned int V_19 )
{
return F_9 ( V_30 , V_19 ) ;
}
