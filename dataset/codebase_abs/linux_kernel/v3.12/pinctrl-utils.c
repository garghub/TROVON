int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , unsigned * V_5 ,
unsigned * V_6 , unsigned V_7 )
{
unsigned V_8 = * V_5 ;
unsigned V_9 = * V_6 + V_7 ;
struct V_3 * V_10 ;
if ( V_8 >= V_9 )
return 0 ;
V_10 = F_2 ( * V_4 , sizeof( * V_10 ) * V_9 , V_11 ) ;
if ( ! V_10 ) {
F_3 ( V_2 -> V_12 , L_1 ) ;
return - V_13 ;
}
memset ( V_10 + V_8 , 0 , ( V_9 - V_8 ) * sizeof( * V_10 ) ) ;
* V_4 = V_10 ;
* V_5 = V_9 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , unsigned * V_5 ,
unsigned * V_6 , const char * V_14 ,
const char * V_15 )
{
if ( F_5 ( * V_6 == * V_5 ) )
return - V_16 ;
( * V_4 ) [ * V_6 ] . type = V_17 ;
( * V_4 ) [ * V_6 ] . V_18 . V_19 . V_14 = V_14 ;
( * V_4 ) [ * V_6 ] . V_18 . V_19 . V_15 = V_15 ;
( * V_6 ) ++ ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , unsigned * V_5 ,
unsigned * V_6 , const char * V_14 ,
unsigned long * V_20 , unsigned V_21 ,
enum V_22 type )
{
unsigned long * V_23 ;
if ( F_5 ( * V_6 == * V_5 ) )
return - V_16 ;
V_23 = F_7 ( V_20 , V_21 * sizeof( * V_23 ) ,
V_11 ) ;
if ( ! V_23 ) {
F_3 ( V_2 -> V_12 , L_2 ) ;
return - V_13 ;
}
( * V_4 ) [ * V_6 ] . type = type ;
( * V_4 ) [ * V_6 ] . V_18 . V_20 . V_24 = V_14 ;
( * V_4 ) [ * V_6 ] . V_18 . V_20 . V_20 = V_23 ;
( * V_4 ) [ * V_6 ] . V_18 . V_20 . V_21 = V_21 ;
( * V_6 ) ++ ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
unsigned long * * V_20 , unsigned * V_21 ,
unsigned long V_25 )
{
unsigned V_8 = * V_21 ;
unsigned V_9 = V_8 + 1 ;
unsigned long * V_26 ;
V_26 = F_2 ( * V_20 , sizeof( * V_26 ) * V_9 ,
V_11 ) ;
if ( ! V_26 ) {
F_3 ( V_2 -> V_12 , L_3 ) ;
return - V_13 ;
}
V_26 [ V_8 ] = V_25 ;
* V_20 = V_26 ;
* V_21 = V_9 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_6 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_6 ; V_27 ++ ) {
switch ( V_4 [ V_27 ] . type ) {
case V_28 :
case V_29 :
F_10 ( V_4 [ V_27 ] . V_18 . V_20 . V_20 ) ;
break;
default:
break;
}
}
F_10 ( V_4 ) ;
}
