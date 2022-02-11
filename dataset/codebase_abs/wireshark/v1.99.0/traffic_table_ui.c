T_1 *
F_1 ( const T_2 * V_1 , T_1 * * V_2 ) {
char * V_3 , * V_4 ;
T_3 * V_5 , * V_6 ;
char * V_7 ;
T_1 * V_8 = NULL ;
T_4 V_9 ;
T_5 * V_10 ;
T_1 * V_11 ;
int V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ;
T_4 V_20 ;
const char * V_21 = L_1 ;
V_12 = V_13 = V_14 = V_15 = V_16 = V_17 = V_18 = V_19 = - 1 ;
V_3 = F_2 ( L_2 ) ;
V_5 = F_3 ( V_3 , L_3 ) ;
if( V_5 == NULL ) {
if ( V_2 ) {
T_5 * V_22 = F_4 ( L_4 ) ;
F_5 ( V_22 , F_6 ( V_23 , FALSE ) , V_3 ) ;
* V_2 = F_7 ( V_22 , FALSE ) ;
}
F_8 ( V_3 ) ;
return NULL ;
}
F_8 ( V_3 ) ;
#if 1
if ( ! F_9 ( & V_7 , L_5 ) ) {
if ( V_2 ) {
T_5 * V_22 = F_4 ( L_4 ) ;
F_5 ( V_22 , L_6 ,
V_7 ) ;
* V_2 = F_7 ( V_22 , FALSE ) ;
}
fclose ( V_5 ) ;
return NULL ;
}
#else
V_7 = L_7 ;
#endif
V_8 = F_10 ( L_8 , V_7 , V_24 ) ;
V_6 = F_3 ( V_8 , L_9 ) ;
if( V_6 == NULL ) {
if ( V_2 ) {
T_5 * V_22 = F_4 ( L_4 ) ;
F_5 ( V_22 , F_6 ( V_23 , FALSE ) , V_8 ) ;
* V_2 = F_7 ( V_22 , FALSE ) ;
}
F_8 ( V_8 ) ;
fclose ( V_5 ) ;
return NULL ;
}
V_4 = ( char * ) F_11 ( V_25 ) ;
while ( fgets ( V_4 , V_25 , V_5 ) != NULL ) {
fputs ( V_4 , V_6 ) ;
if ( strstr ( V_4 , L_10 ) ) {
break;
}
}
for ( V_20 = 0 ; V_20 < F_12 () ; V_20 ++ ) {
switch ( F_13 ( V_20 ) ) {
case V_26 :
V_12 = V_20 ;
break;
case V_27 :
V_13 = V_20 ;
break;
case V_28 :
V_14 = V_20 ;
break;
case V_29 :
V_15 = V_20 ;
break;
case V_30 :
case V_31 :
V_16 = V_20 ;
break;
case V_32 :
case V_33 :
V_17 = V_20 ;
break;
}
}
if( V_12 < 0 || V_13 < 0 ) {
if ( V_2 ) {
* V_2 = F_14 ( L_11 ) ;
}
F_8 ( V_8 ) ;
fclose ( V_5 ) ;
return NULL ;
}
V_10 = F_4 ( L_4 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_34 ; V_9 ++ ) {
const char * V_35 , * V_36 , * V_37 , * V_38 , * V_39 ;
T_6 * V_40 = & F_15 ( V_1 , T_6 , V_9 ) ;
if ( V_40 -> V_41 . type == V_42 ) {
V_36 = F_16 ( V_12 , F_17 ( V_40 -> V_41 . V_43 ) , NULL ) ;
V_35 = F_16 ( V_13 , F_17 ( V_40 -> V_41 . V_43 ) , NULL ) ;
V_37 = F_16 ( V_14 , F_17 ( V_40 -> V_41 . V_43 ) , L_12 ) ;
V_38 = F_16 ( V_16 , F_17 ( V_40 -> V_41 . V_43 ) , L_12 ) ;
V_39 = F_16 ( V_18 , F_17 ( V_40 -> V_41 . V_43 ) , L_12 ) ;
} else if ( V_40 -> V_41 . type == V_44 ) {
const struct V_45 * V_46 = ( const struct V_45 * ) V_40 -> V_41 . V_43 ;
V_36 = F_18 ( V_12 , * V_46 , NULL ) ;
V_35 = F_18 ( V_13 , * V_46 , NULL ) ;
V_37 = F_18 ( V_15 , * V_46 , L_12 ) ;
V_38 = F_18 ( V_17 , * V_46 , L_12 ) ;
V_39 = F_18 ( V_19 , * V_46 , L_12 ) ;
} else {
continue;
}
if ( V_36 && V_35 ) {
F_5 ( V_10 , L_13 , V_21 ) ;
F_19 ( V_10 , L_14 , V_36 , V_35 ) ;
F_19 ( V_10 , L_15 , F_20 ( & V_40 -> V_41 ) ) ;
V_11 = F_21 ( V_38 , L_16 , L_17 ) ;
F_19 ( V_10 , L_18 , V_11 ) ;
F_8 ( V_11 ) ;
V_11 = F_21 ( V_37 , L_16 , L_17 ) ;
F_19 ( V_10 , L_19 , V_11 ) ;
F_8 ( V_11 ) ;
V_11 = F_22 ( V_40 -> V_47 + V_40 -> V_48 ,
( V_49 ) ( V_50 | V_51 ) ) ;
F_19 ( V_10 , L_20 , V_11 ) ;
F_8 ( V_11 ) ;
V_11 = F_22 ( V_40 -> V_52 + V_40 -> V_53 ,
( V_49 ) ( V_50 | V_51 ) ) ;
F_19 ( V_10 , L_21 , V_11 ) ;
F_8 ( V_11 ) ;
V_11 = F_21 ( V_39 , L_16 , L_17 ) ;
F_19 ( V_10 , L_22 , V_11 ) ;
F_8 ( V_11 ) ;
F_23 ( V_10 , L_23 ) ;
F_23 ( V_10 , L_24 ) ;
fputs ( V_10 -> V_54 , V_6 ) ;
V_21 = L_25 ;
}
}
while ( fgets ( V_4 , V_25 , V_5 ) != NULL ) {
fputs ( V_4 , V_6 ) ;
}
F_8 ( V_4 ) ;
fclose ( V_5 ) ;
fclose ( V_6 ) ;
return V_8 ;
}
