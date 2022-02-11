int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * T_2 V_2 ,
struct V_8 * V_8 )
{
struct V_9 V_10 ;
T_3 V_11 = V_4 -> V_12 . V_13 & V_14 ;
struct V_15 * V_15 = F_2 ( V_8 , V_6 -> V_16 ,
V_6 -> V_16 ) ;
if ( V_15 == NULL ) {
F_3 ( L_1 ,
V_4 -> V_12 . type ) ;
return - 1 ;
}
F_4 ( V_15 , V_8 , V_11 , V_17 ,
V_6 -> V_18 , & V_10 ) ;
if ( V_10 . V_19 != NULL )
V_10 . V_19 -> V_20 -> V_21 = 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6
V_2 ,
struct V_8 * V_8 )
{
struct V_15 * V_15 = F_2 ( V_8 ,
V_4 -> V_22 . V_16 ,
V_4 -> V_22 . V_23 ) ;
F_6 ( L_2 , V_4 -> V_22 . V_16 , V_4 -> V_22 . V_23 ,
V_4 -> V_22 . V_24 , V_4 -> V_22 . V_25 ) ;
if ( V_15 ) {
F_7 ( & V_15 -> V_26 , & V_8 -> V_27 ) ;
V_8 -> V_28 = NULL ;
F_8 ( V_15 ) ;
}
return 0 ;
}
int F_9 ( const T_3 * V_29 , int V_30 , char * V_31 )
{
char * V_32 = V_31 ;
const T_3 * V_33 = V_29 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_30 ; ++ V_34 ) {
sprintf ( V_32 , L_3 , * V_33 ) ;
++ V_33 ;
V_32 += 2 ;
}
return V_33 - V_29 ;
}
char * F_10 ( struct V_20 * V_20 , char * V_31 , T_4 V_35 )
{
char V_36 [ V_37 * 2 + 1 ] ;
if ( ! V_20 -> V_38 )
return NULL ;
F_9 ( V_20 -> V_29 , sizeof( V_20 -> V_29 ) , V_36 ) ;
if ( V_31 == NULL ) {
if ( F_11 ( & V_31 , L_4 , V_39 ,
V_36 , V_36 + 2 ) < 0 )
return NULL ;
} else
snprintf ( V_31 , V_35 , L_4 , V_39 ,
V_36 , V_36 + 2 ) ;
return V_31 ;
}
