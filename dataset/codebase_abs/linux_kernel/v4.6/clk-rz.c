static struct V_1 * T_1
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 , const char * V_6 )
{
T_2 V_7 ;
unsigned V_8 ;
static const unsigned V_9 [ 4 ] = { 3 , 2 , 0 , 1 } ;
if ( strcmp ( V_6 , L_1 ) == 0 ) {
unsigned V_10 = 0 ;
const char * V_11 = F_2 ( V_3 , V_10 ) ;
V_8 = V_10 ? ( 32 / 4 ) : 30 ;
return F_3 ( NULL , V_6 , V_11 , 0 , V_8 , 1 ) ;
}
if ( ! V_5 -> V_12 )
return F_4 ( - V_13 ) ;
if ( strcmp ( V_6 , L_2 ) == 0 )
V_7 = ( F_5 ( V_5 -> V_12 + V_14 ) >> 8 ) & 3 ;
else if ( strcmp ( V_6 , L_3 ) == 0 )
V_7 = F_5 ( V_5 -> V_12 + V_15 ) & 3 ;
else
return F_4 ( - V_16 ) ;
V_8 = V_9 [ V_7 ] ;
return F_3 ( NULL , V_6 , L_1 , 0 , V_8 , 3 ) ;
}
static void T_1 F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * * V_17 ;
unsigned V_18 ;
int V_19 ;
V_19 = F_7 ( V_3 , L_4 ) ;
if ( F_8 ( V_19 <= 0 , L_5 ) )
return;
V_5 = F_9 ( sizeof( * V_5 ) , V_20 ) ;
V_17 = F_9 ( V_19 * sizeof( * V_17 ) , V_20 ) ;
F_10 ( ! V_5 || ! V_17 ) ;
V_5 -> V_21 . V_17 = V_17 ;
V_5 -> V_21 . V_22 = V_19 ;
V_5 -> V_12 = F_11 ( V_3 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
const char * V_6 ;
struct V_1 * V_1 ;
F_12 ( V_3 , L_4 , V_18 , & V_6 ) ;
V_1 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( F_13 ( V_1 ) )
F_14 ( L_6 ,
V_23 , V_3 -> V_6 , V_6 , F_15 ( V_1 ) ) ;
else
V_5 -> V_21 . V_17 [ V_18 ] = V_1 ;
}
F_16 ( V_3 , V_24 , & V_5 -> V_21 ) ;
F_17 ( V_3 ) ;
}
