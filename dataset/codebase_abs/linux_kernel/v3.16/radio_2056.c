static const struct V_1
* F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
switch ( V_3 -> V_5 . V_6 ) {
case 3 :
return & V_7 ;
case 4 :
return & V_8 ;
default:
switch ( V_5 -> V_9 ) {
case 5 :
return & V_10 ;
case 6 :
return & V_11 ;
case 7 :
case 9 :
return & V_12 ;
case 8 :
return & V_13 ;
case 11 :
return & V_14 ;
}
}
return NULL ;
}
static void F_2 ( struct V_2 * V_3 , bool V_15 ,
bool V_16 , T_1 V_17 ,
const struct V_18 * V_19 ,
unsigned int V_20 )
{
unsigned int V_21 ;
T_1 V_22 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ , V_19 ++ ) {
if ( ! ( V_19 -> V_23 & V_24 ) )
continue;
if ( ( V_19 -> V_23 & V_25 ) || V_16 ) {
if ( V_15 )
V_22 = V_19 -> V_15 ;
else
V_22 = V_19 -> V_26 ;
F_3 ( V_3 , V_17 | V_21 , V_22 ) ;
}
}
}
void F_4 ( struct V_2 * V_3 ,
bool V_15 , bool V_16 )
{
const struct V_1 * V_27 ;
V_27 = F_1 ( V_3 ) ;
if ( ! V_27 ) {
F_5 ( 1 ) ;
return;
}
F_2 ( V_3 , V_15 , V_16 ,
V_28 , V_27 -> V_29 , V_27 -> V_30 ) ;
F_2 ( V_3 , V_15 , V_16 ,
V_31 , V_27 -> V_32 , V_27 -> V_33 ) ;
F_2 ( V_3 , V_15 , V_16 ,
V_34 , V_27 -> V_32 , V_27 -> V_33 ) ;
F_2 ( V_3 , V_15 , V_16 ,
V_35 , V_27 -> V_36 , V_27 -> V_37 ) ;
F_2 ( V_3 , V_15 , V_16 ,
V_38 , V_27 -> V_36 , V_27 -> V_37 ) ;
}
void F_6 ( struct V_2 * V_3 , bool V_15 )
{
const struct V_1 * V_27 ;
const struct V_18 * V_19 ;
V_27 = F_1 ( V_3 ) ;
if ( ! V_27 ) {
F_5 ( 1 ) ;
return;
}
V_19 = & V_27 -> V_29 [ V_39 ] ;
F_3 ( V_3 , V_39 , V_15 ? V_19 -> V_15 : V_19 -> V_26 ) ;
}
const struct V_40 *
F_7 ( struct V_2 * V_3 , T_1 V_41 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
const struct V_40 * V_19 ;
unsigned int V_20 , V_21 ;
switch ( V_5 -> V_6 ) {
case 3 :
V_19 = V_42 ;
V_20 = F_8 ( V_42 ) ;
break;
case 4 :
V_19 = V_43 ;
V_20 = F_8 ( V_43 ) ;
break;
default:
switch ( V_5 -> V_9 ) {
case 5 :
V_19 = V_44 ;
V_20 = F_8 ( V_44 ) ;
break;
case 6 :
V_19 = V_45 ;
V_20 = F_8 ( V_45 ) ;
break;
case 7 :
case 9 :
V_19 = V_46 ;
V_20 = F_8 ( V_46 ) ;
break;
case 8 :
V_19 = V_47 ;
V_20 = F_8 ( V_47 ) ;
break;
case 11 :
V_19 = V_48 ;
V_20 = F_8 ( V_48 ) ;
break;
default:
F_5 ( 1 ) ;
return NULL ;
}
}
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ , V_19 ++ ) {
if ( V_19 -> V_41 == V_41 )
return V_19 ;
}
return NULL ;
}
