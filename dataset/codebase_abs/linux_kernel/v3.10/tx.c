static T_1 F_1 ( T_2 V_1 )
{
switch ( V_1 ) {
case 2 :
return 0 | ( 1 << 4 ) ;
case 4 :
return 1 | ( 1 << 4 ) ;
case 11 :
return 2 | ( 1 << 4 ) ;
case 22 :
return 3 | ( 1 << 4 ) ;
case 12 :
return 4 | ( 1 << 4 ) ;
case 18 :
return 5 | ( 1 << 4 ) ;
case 24 :
return 6 | ( 1 << 4 ) ;
case 36 :
return 7 | ( 1 << 4 ) ;
case 48 :
return 8 | ( 1 << 4 ) ;
case 72 :
return 9 | ( 1 << 4 ) ;
case 96 :
return 10 | ( 1 << 4 ) ;
case 108 :
return 11 | ( 1 << 4 ) ;
}
return 0 ;
}
T_3 F_2 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_10 * V_10 ;
char * V_11 ;
T_4 V_12 ;
T_3 V_13 = V_14 ;
F_3 ( V_15 ) ;
F_4 ( & V_8 -> V_16 , V_6 ) ;
if ( V_8 -> V_17 )
goto free;
if ( ! V_3 -> V_18 || ( V_3 -> V_18 > V_19 ) ) {
F_5 ( L_1 ,
V_3 -> V_18 , V_19 ) ;
V_5 -> V_20 . V_21 ++ ;
V_5 -> V_20 . V_22 ++ ;
goto free;
}
F_6 ( V_8 -> V_5 ) ;
if ( V_8 -> V_23 )
F_6 ( V_8 -> V_23 ) ;
if ( V_8 -> V_24 ) {
F_5 ( L_2 , V_5 -> V_25 ) ;
V_13 = V_26 ;
goto V_27;
}
V_8 -> V_24 = - 1 ;
F_7 ( & V_8 -> V_16 , V_6 ) ;
F_8 ( V_15 , L_3 , V_3 -> V_28 , F_9 (unsigned int, skb->len, 100 ) ) ;
V_10 = ( void * ) V_8 -> V_29 ;
memset ( V_10 , 0 , sizeof( struct V_10 ) ) ;
V_11 = V_3 -> V_28 ;
V_12 = V_3 -> V_18 ;
if ( V_8 -> V_30 -> V_31 == V_32 ) {
struct V_33 * V_34 = ( void * ) V_3 -> V_28 ;
V_10 -> V_35 = F_10 ( F_1 ( V_34 -> V_1 ) ) ;
V_11 += sizeof( * V_34 ) ;
V_12 -= sizeof( * V_34 ) ;
memcpy ( V_10 -> V_36 , V_11 + 4 , V_37 ) ;
} else {
memcpy ( V_10 -> V_36 , V_11 , V_37 ) ;
}
V_10 -> V_38 = F_11 ( V_12 ) ;
V_10 -> V_39 = F_10 ( sizeof( struct V_10 ) ) ;
F_12 ( V_8 , V_5 , V_10 ) ;
F_8 ( V_15 , L_4 , ( T_2 * ) & V_10 , sizeof( struct V_10 ) ) ;
F_8 ( V_15 , L_5 , ( T_2 * ) V_11 , F_13 ( V_10 -> V_38 ) ) ;
memcpy ( & V_10 [ 1 ] , V_11 , F_13 ( V_10 -> V_38 ) ) ;
F_4 ( & V_8 -> V_16 , V_6 ) ;
V_8 -> V_24 = V_12 + sizeof( struct V_10 ) ;
F_5 ( L_6 , V_40 ) ;
V_5 -> V_20 . V_41 ++ ;
V_5 -> V_20 . V_42 += V_3 -> V_18 ;
if ( V_8 -> V_30 -> V_31 == V_32 ) {
F_14 ( V_3 ) ;
V_8 -> V_43 = V_3 ;
} else {
free:
F_15 ( V_3 ) ;
}
V_27:
F_7 ( & V_8 -> V_16 , V_6 ) ;
F_16 ( & V_8 -> V_44 ) ;
F_17 ( V_15 , L_7 , V_13 ) ;
return V_13 ;
}
void F_18 ( struct V_7 * V_8 , T_1 V_45 )
{
struct V_33 * V_46 ;
if ( V_8 -> V_30 -> V_31 != V_32 ||
V_8 -> V_43 == NULL )
return;
V_46 = (struct V_33 * ) V_8 -> V_43 -> V_28 ;
V_46 -> V_47 = V_45 ?
( 1 + V_8 -> V_48 - V_45 ) : 0 ;
V_8 -> V_43 -> V_49 = F_19 ( V_8 -> V_43 ,
V_8 -> V_5 ) ;
F_20 ( V_8 -> V_43 ) ;
V_8 -> V_43 = NULL ;
if ( V_8 -> V_50 == V_51 )
F_21 ( V_8 -> V_5 ) ;
if ( V_8 -> V_23 && F_22 ( V_8 -> V_23 ) )
F_21 ( V_8 -> V_23 ) ;
}
