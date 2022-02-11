int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 type , T_1 V_4 ,
const T_1 * V_5 , T_2 V_6 ,
T_3 V_7 , void * V_8 ,
unsigned long V_9 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_12 * V_13 ;
const T_1 * V_14 = V_5 ;
int V_15 , V_16 ;
bool V_17 = true ;
V_13 = F_2 ( sizeof( struct V_12 ) , V_18 ) ;
if ( V_13 == NULL )
return - V_19 ;
F_3 ( & V_13 -> V_20 ) ;
F_4 ( & V_13 -> V_21 ) ;
V_13 -> V_22 = ( type == V_23 ) ? true : false ;
V_13 -> V_7 = V_7 ;
V_13 -> V_24 = V_8 ;
V_13 -> V_9 = V_9 ;
V_15 = V_6 + 1 ;
while ( V_15 > 0 ) {
struct V_25 * V_26 ;
int V_27 , V_28 ;
struct V_29 * V_30 ;
if ( V_31 + V_15 <=
V_2 -> V_32 )
V_28 = V_15 ;
else
V_28 = V_2 -> V_32 -
V_31 ;
V_27 = V_11 -> V_33 + V_31 +
V_28 + V_11 -> V_34 ;
V_15 -= V_28 ;
V_26 = F_5 ( V_27 , V_18 ) ;
if ( V_26 == NULL ) {
V_16 = - V_19 ;
goto V_35;
}
F_6 ( V_26 , V_11 -> V_33 ) ;
F_7 ( V_26 , V_31 + V_28 ) ;
V_30 = (struct V_29 * ) V_26 -> V_36 ;
V_30 -> V_37 = V_3 ;
if ( V_17 ) {
V_17 = false ;
V_30 -> V_38 . V_37 = F_8 ( type , V_4 ) ;
if ( V_14 ) {
memcpy ( V_30 -> V_38 . V_36 , V_14 ,
V_28 - 1 ) ;
V_14 += V_28 - 1 ;
}
} else {
memcpy ( & V_30 -> V_38 , V_14 , V_28 ) ;
V_14 += V_28 ;
}
if ( V_15 == 0 )
V_30 -> V_37 |= ~ V_39 ;
F_9 ( & V_13 -> V_21 , V_26 ) ;
}
F_10 ( & V_2 -> V_40 ) ;
F_11 ( & V_13 -> V_20 , & V_2 -> V_41 ) ;
F_12 ( & V_2 -> V_40 ) ;
F_13 ( V_2 -> V_42 , & V_2 -> V_43 ) ;
return 0 ;
V_35:
F_14 ( & V_13 -> V_21 ) ;
F_15 ( V_13 ) ;
return V_16 ;
}
T_1 F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ )
if ( V_2 -> V_46 [ V_44 ] == V_3 )
return V_44 ;
return 0xff ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 type ,
T_1 V_4 , struct V_25 * V_26 )
{
switch ( type ) {
case V_47 :
F_18 ( V_2 , V_4 , V_26 ) ;
break;
case V_23 :
F_19 ( V_2 , V_3 , V_4 , V_26 ) ;
break;
case V_48 :
F_20 ( V_2 , V_3 , V_4 , V_26 ) ;
break;
default:
F_21 ( L_1 ,
type , V_4 ) ;
F_22 ( V_26 ) ;
break;
}
}
