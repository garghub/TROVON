int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * T_2 V_2 ,
struct V_6 * T_3 V_2 ,
struct V_7 * V_7 )
{
struct V_8 V_9 ;
T_4 V_10 = V_4 -> V_11 . V_12 & V_13 ;
struct V_14 * V_14 = F_2 ( V_7 , V_4 -> V_15 . V_16 ) ;
if ( V_14 == NULL ) {
F_3 ( L_1 ,
V_4 -> V_11 . type ) ;
return - 1 ;
}
F_4 ( V_14 , V_7 , V_10 , V_17 ,
V_4 -> V_15 . V_15 , & V_9 ) ;
if ( V_9 . V_18 != NULL )
V_9 . V_18 -> V_19 -> V_20 = 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * T_2
V_2 ,
struct V_7 * V_7 )
{
struct V_14 * V_14 = F_2 ( V_7 , V_4 -> V_21 . V_22 ) ;
F_6 ( L_2 , V_4 -> V_21 . V_16 , V_4 -> V_21 . V_22 ,
V_4 -> V_21 . V_23 , V_4 -> V_21 . V_24 ) ;
if ( V_14 ) {
F_7 ( & V_14 -> V_25 , & V_7 -> V_26 ) ;
V_7 -> V_27 = NULL ;
F_8 ( V_14 ) ;
}
return 0 ;
}
int F_9 ( const T_4 * V_28 , int V_29 , char * V_30 )
{
char * V_31 = V_30 ;
const T_4 * V_32 = V_28 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_29 ; ++ V_33 ) {
sprintf ( V_31 , L_3 , * V_32 ) ;
++ V_32 ;
V_31 += 2 ;
}
return V_32 - V_28 ;
}
char * F_10 ( struct V_19 * V_34 , char * V_30 , T_5 V_35 )
{
char V_36 [ V_37 * 2 + 1 ] ;
if ( ! V_34 -> V_38 )
return NULL ;
F_9 ( V_34 -> V_28 , sizeof( V_34 -> V_28 ) , V_36 ) ;
if ( V_30 == NULL ) {
if ( F_11 ( & V_30 , L_4 , V_39 ,
V_36 , V_36 + 2 ) < 0 )
return NULL ;
} else
snprintf ( V_30 , V_35 , L_4 , V_39 ,
V_36 , V_36 + 2 ) ;
return V_30 ;
}
