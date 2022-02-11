static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 , V_9 = 0 ;
int V_10 , V_11 , V_12 ;
const T_1 * V_13 ;
T_1 * V_14 ;
if ( V_4 -> V_15 . V_16 == V_6 -> V_17 &&
V_6 -> V_18 -> V_19 == V_6 -> V_20 )
goto V_21;
V_13 = V_6 -> V_17 = V_4 -> V_15 . V_16 ;
V_6 -> V_20 = V_6 -> V_18 -> V_19 ;
V_8 = ( ! V_6 -> V_18 -> V_22 ) ? 256 : F_2 ( V_13 ) ;
V_10 = ( ( V_4 -> V_15 . V_23 + 7 ) / 8 ) *
V_4 -> V_15 . V_24 ;
V_11 = V_10 ;
if ( V_6 -> V_25 == V_26 ||
V_6 -> V_25 == V_27 )
V_11 = ( ( V_4 -> V_15 . V_24 + 7 ) / 8 ) *
V_4 -> V_15 . V_23 ;
if ( V_2 -> V_28 -> V_29 )
V_2 -> V_28 -> V_29 ( V_2 ) ;
if ( V_6 -> V_30 < V_11 * V_8 ) {
V_14 = F_3 ( V_11 * V_8 , V_31 ) ;
if ( V_14 == NULL ) {
V_9 = - V_32 ;
goto V_21;
}
V_6 -> V_30 = V_11 * V_8 ;
F_4 ( V_6 -> V_33 ) ;
V_6 -> V_33 = V_14 ;
}
V_14 = V_6 -> V_33 ;
memset ( V_14 , 0 , V_6 -> V_30 ) ;
switch ( V_6 -> V_25 ) {
case V_34 :
for ( V_12 = V_8 ; V_12 -- ; ) {
F_5 ( V_13 , V_14 , V_4 -> V_15 . V_23 ,
V_4 -> V_15 . V_24 ) ;
V_13 += V_10 ;
V_14 += V_11 ;
}
break;
case V_26 :
for ( V_12 = V_8 ; V_12 -- ; ) {
F_6 ( V_13 , V_14 , V_4 -> V_15 . V_23 ,
V_4 -> V_15 . V_24 ) ;
V_13 += V_10 ;
V_14 += V_11 ;
}
break;
case V_27 :
for ( V_12 = V_8 ; V_12 -- ; ) {
F_7 ( V_13 , V_14 , V_4 -> V_15 . V_23 ,
V_4 -> V_15 . V_24 ) ;
V_13 += V_10 ;
V_14 += V_11 ;
}
break;
}
V_21:
return V_9 ;
}
void F_8 ( struct V_5 * V_6 )
{
V_6 -> V_35 = F_1 ;
switch( V_6 -> V_25 ) {
case V_26 :
F_9 ( V_6 ) ;
break;
case V_34 :
F_10 ( V_6 ) ;
break;
case V_27 :
F_11 ( V_6 ) ;
break;
}
}
