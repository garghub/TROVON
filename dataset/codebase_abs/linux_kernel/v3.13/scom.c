struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * V_4 ;
const T_1 * V_5 ;
for ( V_3 = F_2 ( V_2 ) ; V_3 ; ) {
if ( F_3 ( V_3 , L_1 , NULL ) )
break;
V_5 = F_3 ( V_3 , L_2 , NULL ) ;
V_4 = V_3 ;
if ( V_5 == NULL )
V_3 = F_4 ( V_3 ) ;
else
V_3 = F_5 ( * V_5 ) ;
F_6 ( V_4 ) ;
}
return V_3 ;
}
T_2 F_7 ( struct V_1 * V_6 , int V_7 )
{
struct V_1 * V_8 ;
unsigned int V_9 , V_10 ;
const T_3 * V_11 , * V_12 ;
T_4 V_13 , V_14 ;
T_2 V_15 ;
V_8 = F_1 ( V_6 ) ;
if ( V_8 == NULL )
return 0 ;
V_11 = F_3 ( V_6 , L_3 , & V_10 ) ;
V_12 = F_3 ( V_8 , L_4 , NULL ) ;
if ( ! V_11 && V_8 == V_6 -> V_8 ) {
V_11 = F_3 ( V_6 , L_5 , & V_10 ) ;
V_12 = F_3 ( V_8 , L_6 , NULL ) ;
}
if ( ! V_11 )
return NULL ;
V_9 = V_12 ? F_8 ( V_12 ) : 1 ;
V_10 >>= 2 ;
if ( V_7 >= ( V_10 / ( 2 * V_9 ) ) )
return 0 ;
V_13 = F_9 ( & V_11 [ V_7 * V_9 * 2 ] , V_9 ) ;
V_14 = F_9 ( & V_11 [ V_7 * V_9 * 2 + V_9 ] , V_9 ) ;
V_15 = F_10 ( V_8 , V_13 , V_14 ) ;
F_6 ( V_8 ) ;
return V_15 ;
}
static T_5 F_11 ( struct V_16 * V_17 , char T_6 * V_18 ,
T_7 V_19 , T_8 * V_20 )
{
struct V_21 * V_22 = V_17 -> V_23 ;
T_4 T_6 * V_24 = ( T_4 T_6 * ) V_18 ;
T_8 V_25 = * V_20 ;
T_5 V_26 = 0 ;
T_4 V_13 , V_27 , V_28 ;
T_2 V_29 ;
int V_30 ;
if ( V_25 < 0 || ( V_25 & 7 ) || ( V_19 & 7 ) )
return - V_31 ;
V_13 = V_25 >> 3 ;
V_27 = V_19 >> 3 ;
V_29 = F_10 ( V_22 -> V_32 , V_13 , V_27 ) ;
if ( ! F_12 ( V_29 ) )
return - V_33 ;
for ( V_13 = 0 ; V_13 < V_27 ; V_13 ++ ) {
V_30 = F_13 ( V_29 , V_13 , & V_28 ) ;
if ( ! V_30 )
V_30 = F_14 ( V_28 , V_24 ) ;
if ( V_30 ) {
if ( ! V_26 )
V_26 = V_30 ;
break;
}
V_24 ++ ;
* V_20 += 8 ;
V_26 += 8 ;
}
F_15 ( V_29 ) ;
return V_26 ;
}
static T_5 F_16 ( struct V_16 * V_17 , const char T_6 * V_18 ,
T_7 V_19 , T_8 * V_20 )
{
struct V_21 * V_22 = V_17 -> V_23 ;
T_4 T_6 * V_24 = ( T_4 T_6 * ) V_18 ;
T_8 V_25 = * V_20 ;
T_5 V_26 = 0 ;
T_4 V_13 , V_27 , V_28 ;
T_2 V_29 ;
int V_30 ;
if ( V_25 < 0 || ( V_25 & 7 ) || ( V_19 & 7 ) )
return - V_31 ;
V_13 = V_25 >> 3 ;
V_27 = V_19 >> 3 ;
V_29 = F_10 ( V_22 -> V_32 , V_13 , V_27 ) ;
if ( ! F_12 ( V_29 ) )
return - V_33 ;
for ( V_13 = 0 ; V_13 < V_27 ; V_13 ++ ) {
V_30 = F_17 ( V_28 , V_24 ) ;
if ( ! V_30 )
V_30 = F_18 ( V_29 , V_13 , V_28 ) ;
if ( V_30 ) {
if ( ! V_26 )
V_26 = V_30 ;
break;
}
V_24 ++ ;
V_26 += 8 ;
}
F_15 ( V_29 ) ;
return V_26 ;
}
static int F_19 ( struct V_34 * V_35 , struct V_1 * V_32 ,
int V_36 )
{
struct V_21 * V_22 ;
struct V_34 * V_37 ;
V_22 = F_20 ( sizeof( * V_22 ) , V_38 ) ;
if ( ! V_22 )
return - V_39 ;
V_22 -> V_32 = F_2 ( V_32 ) ;
snprintf ( V_22 -> V_40 , 16 , L_7 , V_36 ) ;
V_22 -> V_41 . V_42 = ( void * ) V_32 -> V_43 ;
V_22 -> V_41 . V_10 = strlen ( V_32 -> V_43 ) ;
V_37 = F_21 ( V_22 -> V_40 , V_35 ) ;
if ( ! V_37 ) {
F_6 ( V_32 ) ;
F_22 ( V_22 ) ;
return - 1 ;
}
F_23 ( L_8 , 0400 , V_37 , & V_22 -> V_41 ) ;
F_24 ( L_9 , 0600 , V_37 , V_22 , & V_44 ) ;
return 0 ;
}
static int F_25 ( void )
{
struct V_1 * V_32 ;
struct V_34 * V_35 ;
int V_36 , V_30 ;
V_35 = F_21 ( L_10 , V_45 ) ;
if ( ! V_35 )
return - 1 ;
V_36 = V_30 = 0 ;
F_26 (dn, L_1 ) {
int V_46 = F_27 ( V_32 ) ;
if ( V_46 == - 1 )
V_46 = V_36 ;
V_30 |= F_19 ( V_35 , V_32 , V_46 ) ;
V_36 ++ ;
}
return V_30 ;
}
