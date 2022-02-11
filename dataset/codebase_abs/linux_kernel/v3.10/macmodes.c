int F_1 ( int V_1 , int V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = NULL ;
const struct V_7 * V_8 ;
for ( V_8 = V_9 ; V_8 -> V_1 != - 1 ; V_8 ++ )
if ( V_8 -> V_1 == V_1 ) {
V_6 = V_8 -> V_6 ;
break;
}
if ( ! V_6 )
return - V_10 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
switch ( V_2 ) {
case V_11 :
V_4 -> V_12 = 8 ;
V_4 -> V_13 . V_14 = 0 ;
V_4 -> V_13 . V_15 = 8 ;
V_4 -> V_16 . V_14 = 0 ;
V_4 -> V_16 . V_15 = 8 ;
V_4 -> V_17 . V_14 = 0 ;
V_4 -> V_17 . V_15 = 8 ;
break;
case V_18 :
V_4 -> V_12 = 16 ;
V_4 -> V_13 . V_14 = 10 ;
V_4 -> V_13 . V_15 = 5 ;
V_4 -> V_16 . V_14 = 5 ;
V_4 -> V_16 . V_15 = 5 ;
V_4 -> V_17 . V_14 = 0 ;
V_4 -> V_17 . V_15 = 5 ;
break;
case V_19 :
V_4 -> V_12 = 32 ;
V_4 -> V_13 . V_14 = 16 ;
V_4 -> V_13 . V_15 = 8 ;
V_4 -> V_16 . V_14 = 8 ;
V_4 -> V_16 . V_15 = 8 ;
V_4 -> V_17 . V_14 = 0 ;
V_4 -> V_17 . V_15 = 8 ;
V_4 -> V_20 . V_14 = 24 ;
V_4 -> V_20 . V_15 = 8 ;
break;
default:
return - V_10 ;
}
V_4 -> V_21 = V_6 -> V_21 ;
V_4 -> V_22 = V_6 -> V_22 ;
V_4 -> V_23 = V_6 -> V_21 ;
V_4 -> V_24 = V_6 -> V_22 ;
V_4 -> V_25 = - 1 ;
V_4 -> V_26 = - 1 ;
V_4 -> V_27 = V_6 -> V_27 ;
V_4 -> V_28 = V_6 -> V_28 ;
V_4 -> V_29 = V_6 -> V_29 ;
V_4 -> V_30 = V_6 -> V_30 ;
V_4 -> V_31 = V_6 -> V_31 ;
V_4 -> V_32 = V_6 -> V_32 ;
V_4 -> V_33 = V_6 -> V_33 ;
V_4 -> V_34 = V_6 -> V_34 ;
V_4 -> V_1 = V_6 -> V_1 ;
return 0 ;
}
int F_2 ( const struct V_3 * V_4 , int * V_1 ,
int * V_2 )
{
const struct V_7 * V_8 ;
if ( V_4 -> V_12 <= 8 )
* V_2 = V_11 ;
else if ( V_4 -> V_12 <= 16 )
* V_2 = V_18 ;
else if ( V_4 -> V_12 <= 32 )
* V_2 = V_19 ;
else
return - V_10 ;
for ( V_8 = V_9 ; V_8 -> V_1 != - 1 ; V_8 ++ ) {
const struct V_5 * V_6 = V_8 -> V_6 ;
if ( V_4 -> V_21 > V_6 -> V_21 || V_4 -> V_22 > V_6 -> V_22 )
continue;
if ( V_4 -> V_23 > V_6 -> V_21 || V_4 -> V_24 > V_6 -> V_22 )
continue;
if ( V_4 -> V_27 > V_6 -> V_27 )
continue;
if ( ( V_4 -> V_1 & V_35 ) != V_6 -> V_1 )
continue;
* V_1 = V_8 -> V_1 ;
V_8 ++ ;
while ( V_8 -> V_1 != - 1 ) {
const struct V_5 * V_36 = V_8 -> V_6 ;
if ( V_6 -> V_21 != V_36 -> V_21 || V_6 -> V_22 != V_36 -> V_22 )
break;
if ( V_4 -> V_27 > V_6 -> V_27 )
break;
if ( V_6 -> V_1 != V_36 -> V_1 )
continue;
* V_1 = V_8 -> V_1 ;
V_8 ++ ;
}
return 0 ;
}
return - V_10 ;
}
int F_3 ( int V_37 )
{
const struct V_38 * V_8 ;
for ( V_8 = V_39 ; V_8 -> V_37 != - 1 ; V_8 ++ )
if ( V_8 -> V_37 == V_37 )
break;
return V_8 -> V_1 ;
}
int F_4 ( struct V_3 * V_4 , struct V_40 * V_41 ,
const char * V_42 , unsigned int V_43 )
{
const struct V_5 * V_44 = NULL ;
unsigned int V_45 = 0 ;
if ( V_42 && ! strncmp ( V_42 , L_1 , 3 ) ) {
V_42 += 3 ;
V_44 = V_46 ;
V_45 = F_5 ( V_46 ) ;
}
return F_6 ( V_4 , V_41 , V_42 , V_44 , V_45 ,
& V_46 [ V_47 ] , V_43 ) ;
}
