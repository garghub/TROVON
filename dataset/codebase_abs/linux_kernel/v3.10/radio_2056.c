static void F_1 ( struct V_1 * V_2 , bool V_3 ,
bool V_4 , T_1 V_5 ,
const struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
T_1 V_10 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ , V_7 ++ ) {
if ( ! ( V_7 -> V_11 & V_12 ) )
continue;
if ( ( V_7 -> V_11 & V_13 ) || V_4 ) {
if ( V_3 )
V_10 = V_7 -> V_3 ;
else
V_10 = V_7 -> V_14 ;
F_2 ( V_2 , V_5 | V_9 , V_10 ) ;
}
}
}
void F_3 ( struct V_1 * V_2 ,
bool V_3 , bool V_4 )
{
const struct V_15 * V_16 ;
if ( V_2 -> V_17 . V_18 >= F_4 ( V_19 ) ) {
F_5 ( 1 ) ;
return;
}
V_16 = & V_19 [ V_2 -> V_17 . V_18 ] ;
F_1 ( V_2 , V_3 , V_4 ,
V_20 , V_16 -> V_21 , V_16 -> V_22 ) ;
F_1 ( V_2 , V_3 , V_4 ,
V_23 , V_16 -> V_24 , V_16 -> V_25 ) ;
F_1 ( V_2 , V_3 , V_4 ,
V_26 , V_16 -> V_24 , V_16 -> V_25 ) ;
F_1 ( V_2 , V_3 , V_4 ,
V_27 , V_16 -> V_28 , V_16 -> V_29 ) ;
F_1 ( V_2 , V_3 , V_4 ,
V_30 , V_16 -> V_28 , V_16 -> V_29 ) ;
}
void F_6 ( struct V_1 * V_2 , bool V_3 )
{
const struct V_15 * V_16 ;
const struct V_6 * V_7 ;
if ( V_2 -> V_17 . V_18 >= F_4 ( V_19 ) ) {
F_5 ( 1 ) ;
return;
}
V_16 = & V_19 [ V_2 -> V_17 . V_18 ] ;
V_7 = & V_16 -> V_21 [ V_31 ] ;
F_2 ( V_2 , V_31 , V_3 ? V_7 -> V_3 : V_7 -> V_14 ) ;
}
const struct V_32 *
F_7 ( struct V_1 * V_2 , T_1 V_33 )
{
const struct V_32 * V_7 ;
unsigned int V_8 , V_9 ;
switch ( V_2 -> V_17 . V_18 ) {
case 3 :
V_7 = V_34 ;
V_8 = F_4 ( V_34 ) ;
break;
case 4 :
V_7 = V_35 ;
V_8 = F_4 ( V_35 ) ;
break;
case 5 :
V_7 = V_36 ;
V_8 = F_4 ( V_36 ) ;
break;
case 6 :
V_7 = V_37 ;
V_8 = F_4 ( V_37 ) ;
break;
case 7 :
case 9 :
V_7 = V_38 ;
V_8 = F_4 ( V_38 ) ;
break;
case 8 :
V_7 = V_39 ;
V_8 = F_4 ( V_39 ) ;
break;
default:
F_5 ( 1 ) ;
return NULL ;
}
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ , V_7 ++ ) {
if ( V_7 -> V_33 == V_33 )
return V_7 ;
}
return NULL ;
}
