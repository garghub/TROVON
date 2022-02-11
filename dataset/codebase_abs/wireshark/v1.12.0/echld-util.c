static long F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ) {
long V_4 ;
V_4 = ( V_3 -> V_5 - V_2 -> V_5 ) * 1000 ;
V_4 += ( V_3 -> V_6 - V_2 -> V_6 ) / 1000 ;
return V_4 ;
}
static T_1 F_2 ( T_2 type , T_3 * T_4 V_7 , void * V_8 ) {
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
struct V_1 V_11 ;
long V_12 = - 1 ;
F_3 ( & V_11 , NULL ) ;
switch ( type ) {
case V_13 :
V_12 = F_1 ( & ( V_10 -> V_14 ) , & V_11 ) ;
break;
default:
V_12 = - 1 ;
break;
}
if ( V_10 -> V_15 ) V_10 -> V_15 ( V_12 , V_10 -> V_16 ) ;
F_4 ( V_10 ) ;
return TRUE ;
}
extern T_5 F_5 ( int V_17 , T_6 V_18 , void * V_16 ) {
struct V_9 * V_10 = F_6 ( struct V_9 , 1 ) ;
V_10 -> V_15 = V_18 ;
V_10 -> V_16 = V_16 ;
F_3 ( & ( V_10 -> V_14 ) , NULL ) ;
return F_7 ( V_17 , V_19 , 0 , NULL , F_2 , V_10 ) ;
}
static T_1 F_8 ( T_2 type , T_3 * T_4 V_7 , void * V_8 ) {
struct V_20 * V_21 = (struct V_20 * ) V_8 ;
char * V_22 ;
switch ( type ) {
case V_23 :
if ( V_21 -> V_15 ) {
char * V_24 ;
char * V_25 ;
V_21 -> V_26 ( T_4 , & V_24 , & V_25 ) ;
V_21 -> V_15 ( V_24 , V_25 , NULL , V_21 -> V_16 ) ;
}
break;
case V_27 : {
int V_28 ;
V_21 -> V_29 ( T_4 , & V_28 , & V_22 ) ;
V_21 -> V_15 ( NULL , NULL , V_22 , V_21 -> V_16 ) ;
break;
}
default:
V_22 = F_9 ( L_1 , F_10 ( type ) ) ;
V_21 -> V_15 ( NULL , NULL , V_22 , V_21 -> V_16 ) ;
F_4 ( V_22 ) ;
break;
}
F_4 ( V_21 ) ;
return TRUE ;
}
extern T_5 F_11 ( int V_17 , const char * V_24 , T_7 V_30 , void * V_16 ) {
struct V_20 * V_21 = F_6 ( struct V_20 , 1 ) ;
T_8 * V_31 ;
T_9 * V_26 ;
T_10 * V_32 ;
F_12 ( NULL , NULL , & V_31 , & V_26 ) ;
V_32 = V_31 -> V_33 ( V_24 ) ;
V_21 -> V_34 = V_24 ;
V_21 -> V_15 = V_30 ;
V_21 -> V_16 = V_16 ;
V_21 -> V_26 = V_26 -> V_24 ;
V_21 -> V_29 = V_26 -> error ;
return F_7 ( V_17 , V_35 , 0 , V_32 , F_8 , V_21 ) ;
}
extern T_5 F_13 ( int V_17 , const char * V_24 , const char * V_25 , T_7 V_30 , void * V_16 ) {
struct V_20 * V_21 = F_6 ( struct V_20 , 1 ) ;
T_8 * V_31 ;
T_9 * V_26 ;
T_10 * V_32 ;
F_12 ( NULL , NULL , & V_31 , & V_26 ) ;
V_32 = V_31 -> V_36 ( V_24 , V_25 ) ;
V_21 -> V_34 = V_24 ;
V_21 -> V_15 = V_30 ;
V_21 -> V_16 = V_16 ;
V_21 -> V_26 = V_26 -> V_24 ;
V_21 -> V_29 = V_26 -> error ;
return F_7 ( V_17 , V_37 , 0 , V_32 , F_8 , V_21 ) ;
}
static T_1 F_14 ( T_2 type , T_3 * T_4 , void * V_8 ) {
T_11 * V_38 = ( T_11 * ) V_8 ;
T_9 * V_26 ;
char * V_22 ;
F_12 ( NULL , NULL , NULL , & V_26 ) ;
switch ( type ) {
case V_39 : {
if ( V_38 -> V_15 ) {
V_38 -> V_15 ( NULL , V_38 -> V_16 ) ;
}
break;
}
case V_27 : {
int V_28 ;
if ( V_26 -> error ( T_4 , & V_28 , & V_22 ) ) {
V_38 -> V_15 ( V_22 , V_38 -> V_16 ) ;
F_4 ( V_22 ) ;
} else {
V_38 -> V_15 ( L_2 , V_38 -> V_16 ) ;
}
break;
}
default:
V_22 = F_9 ( L_1 , F_10 ( type ) ) ;
V_38 -> V_15 ( V_22 , V_38 -> V_16 ) ;
F_4 ( V_22 ) ;
break;
}
F_4 ( V_38 ) ;
return TRUE ;
}
T_5 F_15 ( int V_40 , T_12 V_18 , void * V_16 ) {
T_11 * V_38 = F_6 ( T_11 , 1 ) ;
V_38 -> V_15 = V_18 ;
V_38 -> V_16 = V_16 ;
return F_7 ( V_40 , V_41 , 0 , NULL , F_14 , V_38 ) ;
}
