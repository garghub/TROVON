int F_1 ( T_1 * V_1 )
{
unsigned char * V_2 = V_1 -> V_3 -> V_4 ;
unsigned long V_5 = V_1 -> V_3 -> V_6 ;
const char * V_7 ;
struct V_8 * V_9 ;
const struct V_10 * V_11 = NULL ;
const struct V_12 * V_13 ;
unsigned int V_14 ;
int V_15 , V_16 ;
int V_17 = 0 ;
switch ( V_1 -> V_18 ) {
case V_19 :
case V_20 :
V_7 = V_21 ;
V_15 = V_22 ;
break;
case V_23 :
V_7 = V_24 ;
V_15 = V_25 ;
break;
default:
return - V_26 ;
}
V_9 = F_2 ( L_1 , 0 , NULL , 0 ) ;
if ( F_3 ( V_9 ) ) {
F_4 ( L_2 ) ;
return F_5 ( V_9 ) ;
}
V_17 = F_6 ( & V_11 , V_7 , & V_9 -> V_27 ) ;
F_7 ( V_9 ) ;
if ( V_17 ) {
F_4 ( L_3 ,
V_7 ) ;
return V_17 ;
}
V_14 = 0 ;
V_16 = 0 ;
for ( V_13 = ( const struct V_12 * ) V_11 -> V_28 ;
V_13 ;
V_13 = F_8 ( V_13 ) ) {
V_14 += F_9 ( F_10 ( V_13 -> V_29 ) ) ;
V_16 ++ ;
}
if ( V_16 != V_15 ) {
F_4 ( L_4 , V_7 ) ;
V_17 = - V_26 ;
goto V_30;
}
V_14 = F_11 ( V_14 ) ;
F_12 ( L_5 , V_14 ) ;
if ( V_14 > V_1 -> V_3 -> V_14 ) {
F_4 ( L_6 ,
V_14 , V_1 -> V_3 -> V_14 ) ;
V_17 = - V_31 ;
goto V_30;
}
memset ( V_1 -> V_32 , 0 , sizeof( V_1 -> V_32 ) ) ;
V_16 = 0 ;
for ( V_13 = ( const struct V_12 * ) V_11 -> V_28 ;
V_13 ;
V_13 = F_8 ( V_13 ) ) {
unsigned int V_33 , V_34 ;
F_12 ( L_7 , V_5 , V_2 ) ;
V_1 -> V_32 [ V_16 ] = V_5 ;
V_33 = F_10 ( V_13 -> V_29 ) ;
V_34 = F_9 ( V_33 ) ;
memcpy ( V_2 , V_13 -> V_28 , V_33 ) ;
V_5 += V_34 ;
V_2 += V_34 ;
V_16 ++ ;
}
V_30:
F_13 ( V_11 ) ;
return V_17 ;
}
int F_14 ( T_1 * V_1 )
{
T_2 V_35 ;
switch ( V_1 -> V_18 ) {
case V_19 :
case V_20 :
F_15 ( V_36 , V_37 ) ;
F_15 ( V_38 , 0x00000E00 ) ;
F_15 ( V_39 , 0x00001807 ) ;
F_15 ( V_40 , 0x18000000 ) ;
break;
case V_23 :
F_15 ( V_41 , V_37 ) ;
F_15 ( V_38 , 0x1606 ) ;
F_15 ( V_39 , 7 ) ;
break;
default:
return - V_26 ;
}
F_15 ( V_42 , ( V_43 |
V_44 | V_45 ) ) ;
V_35 = F_16 ( V_42 ) ;
if ( V_35 != V_46 ) {
F_4 ( L_8 ,
V_35 , V_46 ) ;
return - V_26 ;
}
return 0 ;
}
