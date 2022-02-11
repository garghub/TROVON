static int F_1 ( struct V_1 * V_2 , int type , int V_3 ,
struct V_4 * * V_5 )
{
struct V_4 * V_6 ;
int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
* V_5 = NULL ;
V_10 = V_11 = 0 ;
for ( V_7 = V_2 -> V_13 , V_8 = 0 ; V_8 < V_14 ; V_7 += V_3 , V_8 += V_3 ) {
V_7 %= V_14 ;
if ( ( V_3 == 2 ) && ( V_7 % 2 ) ) {
V_7 ++ ;
continue;
}
V_12 = 0 ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ ) {
V_6 = & V_2 -> V_15 [ ( V_7 + V_9 ) % V_14 ] ;
if ( V_6 -> V_16 ) {
V_12 = 1 ;
break;
}
}
if ( ! V_12 ) {
V_10 = V_7 ;
V_11 = ( V_7 + V_3 ) % V_14 ;
V_2 -> V_13 = V_11 ;
break;
}
}
if ( V_10 == V_11 )
return - V_17 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
V_6 = & V_2 -> V_15 [ ( V_10 + V_7 ) % V_14 ] ;
V_6 -> V_16 = 1 ;
switch ( type ) {
case V_18 :
V_6 -> V_19 = 1 ;
break;
case V_20 :
V_6 -> V_21 = 1 ;
break;
case V_22 :
V_6 -> V_23 = 1 ;
break;
case V_24 :
V_6 -> V_25 = 1 ;
break;
}
}
* V_5 = & V_2 -> V_15 [ V_10 ] ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , int type , int V_3 ,
struct V_4 * * V_5 )
{
unsigned long V_26 ;
int V_27 ;
if ( F_3 ( ! V_5 ) )
return - V_28 ;
if ( F_3 ( ! V_3 ) )
return - V_28 ;
F_4 ( & V_2 -> V_29 , V_26 ) ;
for (; ; ) {
V_27 = F_1 ( V_2 , type , V_3 , V_5 ) ;
if ( V_27 == 0 || type == V_20 || type == V_22 )
break;
if ( V_2 -> V_30 ) {
V_27 = V_2 -> V_30 ( V_2 ) ;
if ( V_27 >= 0 ) {
struct V_4 * V_31 = & V_2 -> V_15 [ V_27 ] ;
V_31 -> V_32 = NULL ;
V_31 -> V_16 = V_31 -> V_19 = V_31 -> V_21 = V_31 -> V_23 = V_31 -> V_25 = 0 ;
V_31 -> V_33 = NULL ;
}
}
if ( V_27 < 0 )
break;
}
F_5 ( & V_2 -> V_29 , V_26 ) ;
return V_27 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_4 * V_31 )
{
unsigned long V_26 ;
if ( F_3 ( ! V_31 ) )
return - V_28 ;
F_4 ( & V_2 -> V_29 , V_26 ) ;
V_31 -> V_32 = NULL ;
V_31 -> V_16 = V_31 -> V_19 = V_31 -> V_21 = V_31 -> V_23 = V_31 -> V_25 = 0 ;
V_31 -> V_33 = NULL ;
F_7 ( V_2 , V_31 -> V_3 ) ;
F_5 ( & V_2 -> V_29 , V_26 ) ;
return 0 ;
}
