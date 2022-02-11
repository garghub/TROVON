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
V_13 -> V_8 = V_8 ;
V_13 -> V_9 = V_9 ;
V_15 = V_6 + 1 ;
while ( V_15 > 0 ) {
struct V_24 * V_25 ;
int V_26 , V_27 ;
struct V_28 * V_29 ;
if ( V_30 + V_15 <=
V_2 -> V_31 )
V_27 = V_15 ;
else
V_27 = V_2 -> V_31 -
V_30 ;
V_26 = V_11 -> V_32 + V_30 +
V_27 + V_11 -> V_33 ;
V_15 -= V_27 ;
V_25 = F_5 ( V_26 , V_18 ) ;
if ( V_25 == NULL ) {
V_16 = - V_19 ;
goto V_34;
}
F_6 ( V_25 , V_11 -> V_32 ) ;
F_7 ( V_25 , V_30 + V_27 ) ;
V_29 = (struct V_28 * ) V_25 -> V_35 ;
V_29 -> V_36 = V_3 ;
if ( V_17 ) {
V_17 = false ;
V_29 -> V_37 . V_36 = F_8 ( type , V_4 ) ;
if ( V_14 ) {
memcpy ( V_29 -> V_37 . V_35 , V_14 ,
V_27 - 1 ) ;
V_14 += V_27 - 1 ;
}
} else {
memcpy ( & V_29 -> V_37 , V_14 , V_27 ) ;
V_14 += V_27 ;
}
if ( V_15 == 0 )
V_29 -> V_36 |= ~ V_38 ;
F_9 ( & V_13 -> V_21 , V_25 ) ;
}
F_10 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_40 ) {
V_16 = - V_41 ;
F_11 ( & V_2 -> V_39 ) ;
goto V_34;
}
F_12 ( & V_13 -> V_20 , & V_2 -> V_42 ) ;
F_11 ( & V_2 -> V_39 ) ;
F_13 ( & V_2 -> V_43 ) ;
return 0 ;
V_34:
F_14 ( & V_13 -> V_21 ) ;
F_15 ( V_13 ) ;
return V_16 ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 type ,
T_1 V_4 , struct V_24 * V_25 )
{
switch ( type ) {
case V_44 :
F_17 ( V_2 , V_4 , V_25 ) ;
break;
case V_23 :
F_18 ( V_2 , V_3 , V_4 , V_25 ) ;
break;
case V_45 :
F_19 ( V_2 , V_3 , V_4 , V_25 ) ;
break;
default:
F_20 ( L_1 ,
type , V_4 ) ;
F_21 ( V_25 ) ;
break;
}
}
