static struct V_1 * T_1
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 ,
unsigned int V_8 , const char * V_9 )
{
const char * V_10 = L_1 ;
unsigned int V_11 = 1 ;
unsigned int div = 1 ;
if ( ! strcmp ( V_9 , L_1 ) ) {
V_10 = F_2 ( V_3 , 0 ) ;
V_11 = V_8 ;
} else if ( ! strcmp ( V_9 , L_2 ) ) {
div = V_7 -> V_12 ;
V_11 = V_7 -> V_13 ;
} else if ( ! strcmp ( V_9 , L_3 ) || ! strcmp ( V_9 , L_4 ) ) {
div = V_7 -> V_14 ;
} else if ( ! strcmp ( V_9 , L_5 ) ) {
div = V_7 -> V_15 ;
} else if ( ! strcmp ( V_9 , L_6 ) ) {
div = V_7 -> V_16 ;
} else if ( ! strcmp ( V_9 , L_7 ) || ! strcmp ( V_9 , L_8 ) ) {
div = V_7 -> V_17 ;
} else {
return F_3 ( - V_18 ) ;
}
return F_4 ( NULL , V_9 , V_10 , 0 , V_11 , div ) ;
}
static void T_1 F_5 ( struct V_2 * V_3 )
{
const struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_1 * * V_19 ;
unsigned int V_20 , V_8 ;
int V_21 ;
T_2 V_22 ;
if ( F_6 ( & V_22 ) )
return;
V_21 = F_7 ( V_3 , L_9 ) ;
if ( V_21 < 0 ) {
F_8 ( L_10 , V_23 ) ;
return;
}
V_5 = F_9 ( sizeof( * V_5 ) , V_24 ) ;
V_19 = F_9 ( V_25 * sizeof( * V_19 ) , V_24 ) ;
if ( V_5 == NULL || V_19 == NULL ) {
return;
}
F_10 ( & V_5 -> V_26 ) ;
V_5 -> V_27 . V_19 = V_19 ;
V_5 -> V_27 . V_28 = V_21 ;
V_7 = & V_29 [ F_11 ( V_22 ) ] ;
V_8 = V_30 [ F_12 ( V_22 ) ] ;
for ( V_20 = 0 ; V_20 < V_21 ; ++ V_20 ) {
const char * V_9 ;
struct V_1 * V_1 ;
F_13 ( V_3 , L_9 , V_20 ,
& V_9 ) ;
V_1 = F_1 ( V_3 , V_5 , V_7 ,
V_8 , V_9 ) ;
if ( F_14 ( V_1 ) )
F_8 ( L_11 ,
V_23 , V_3 -> V_9 , V_9 , F_15 ( V_1 ) ) ;
else
V_5 -> V_27 . V_19 [ V_20 ] = V_1 ;
}
F_16 ( V_3 , V_31 , & V_5 -> V_27 ) ;
F_17 ( V_3 ) ;
}
