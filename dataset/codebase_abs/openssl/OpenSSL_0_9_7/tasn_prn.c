int F_1 ( T_1 * V_1 , void * V_2 , int V_3 , const T_2 * V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_4 -> V_5 ) ;
}
static int F_2 ( T_1 * V_1 , void * V_2 , int V_3 , const T_2 * V_4 , const char * V_6 )
{
T_3 * V_7 ;
const T_4 * V_8 ;
void * V_9 ;
int V_10 ;
if( ! V_2 ) {
F_3 ( V_1 , L_1 , V_3 , L_2 , V_6 ) ;
return 1 ;
}
switch( V_4 -> V_11 ) {
case V_12 :
if( V_4 -> V_13 )
return F_4 ( V_1 , V_2 , V_3 , V_4 -> V_13 ) ;
return F_5 ( V_1 , V_2 , V_4 -> V_14 , V_3 , V_6 ) ;
break;
case V_15 :
V_7 = V_2 ;
return F_5 ( V_1 , V_2 , V_7 -> type , V_3 , V_6 ) ;
case V_16 :
F_3 ( V_1 , L_3 , V_3 , L_2 , V_6 , V_4 -> V_5 , V_2 ? L_2 : L_4 ) ;
return 1 ;
case V_17 :
F_3 ( V_1 , L_5 , V_3 , L_2 , V_6 , V_4 -> V_5 , V_2 ? L_2 : L_4 ) ;
return 1 ;
case V_18 :
V_10 = F_6 ( V_2 , V_4 ) ;
if( ( V_10 < 0 ) || ( V_10 >= V_4 -> V_19 ) ) {
F_3 ( V_1 , L_6 , V_4 -> V_5 , V_10 ) ;
return 1 ;
}
V_8 = V_4 -> V_13 + V_10 ;
V_9 = F_7 ( V_2 , V_8 ) ;
return F_4 ( V_1 , V_9 , V_3 , V_8 ) ;
case V_20 :
F_3 ( V_1 , L_7 , V_3 , L_2 , V_6 ) ;
for( V_10 = 0 , V_8 = V_4 -> V_13 ; V_10 < V_4 -> V_19 ; V_10 ++ , V_8 ++ ) {
V_9 = F_7 ( V_2 , V_8 ) ;
F_4 ( V_1 , V_9 , V_3 + 2 , V_8 ) ;
}
F_3 ( V_1 , L_8 , V_3 , L_2 ) ;
return 1 ;
default:
return 0 ;
}
}
int F_4 ( T_1 * V_1 , void * V_2 , int V_3 , const T_4 * V_8 )
{
int V_10 , V_21 ;
#if 0
if(!fld) return 0;
#endif
V_21 = V_8 -> V_21 ;
if( V_21 & V_22 ) {
char * V_23 ;
void * V_24 ;
if( V_21 & V_25 ) V_23 = L_9 ;
else V_23 = L_10 ;
if( V_2 ) {
F_3 ( V_1 , L_11 , V_3 , L_2 , V_23 , V_8 -> V_26 ) ;
for( V_10 = 0 ; V_10 < F_8 ( V_2 ) ; V_10 ++ ) {
V_24 = F_9 ( V_2 , V_10 ) ;
F_2 ( V_1 , V_24 , V_3 + 2 , V_8 -> V_27 , L_2 ) ;
}
F_3 ( V_1 , L_8 , V_3 , L_2 ) ;
} else
F_3 ( V_1 , L_12 , V_3 , L_2 , V_23 , V_8 -> V_26 ) ;
return 1 ;
}
return F_2 ( V_1 , V_2 , V_3 , V_8 -> V_27 , V_8 -> V_26 ) ;
}
static int F_5 ( T_1 * V_1 , void * V_2 , long V_14 , int V_3 , const char * V_6 )
{
T_3 * V_7 = V_2 ;
if( V_2 ) {
if( V_14 == V_28 ) {
int * bool = V_2 ;
if( * bool == - 1 ) printf ( L_13 ) ;
F_3 ( V_1 , L_14 , V_3 , L_2 , L_15 , * bool ? L_16 : L_17 ) ;
} else if( ( V_14 == V_29 )
|| ( V_14 == V_30 ) ) {
char * V_31 , * V_32 ;
V_31 = F_10 ( NULL , V_2 ) ;
if( V_14 == V_29 ) V_32 = L_18 ;
else V_32 = L_19 ;
F_3 ( V_1 , L_14 , V_3 , L_2 , V_32 , V_31 ) ;
F_11 ( V_31 ) ;
} else if( V_14 == V_33 ) {
F_3 ( V_1 , L_20 , V_3 , L_2 , L_21 ) ;
} else if( V_14 == V_34 ) {
F_3 ( V_1 , L_22 , V_3 , L_2 , V_6 , L_23 ) ;
F_12 ( V_1 , V_7 ) ;
} else if( V_14 == V_35 ) {
F_3 ( V_1 , L_22 , V_3 , L_2 , V_6 , L_24 ) ;
F_13 ( V_1 , V_7 ) ;
} else if( V_14 == V_36 ) {
char V_37 [ 80 ] , * V_38 ;
V_38 = F_14 ( F_15 ( V_2 ) ) ;
if( ! V_38 ) V_38 = L_2 ;
F_16 ( V_37 , sizeof V_37 , V_2 , 1 ) ;
F_3 ( V_1 , L_25 , V_3 , L_2 , L_26 , V_38 , V_37 ) ;
} else {
F_3 ( V_1 , L_27 , V_3 , L_2 , V_6 ) ;
F_17 ( V_1 , V_7 , V_39 | V_40 ) ;
}
F_3 ( V_1 , L_28 ) ;
} else F_3 ( V_1 , L_29 , V_3 , L_2 , V_6 ) ;
return 1 ;
}
