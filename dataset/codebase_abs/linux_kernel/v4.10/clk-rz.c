static T_1 T_2 F_1 ( void )
{
void T_3 * V_1 , * V_2 ;
T_1 V_3 ;
V_1 = F_2 ( V_4 , 2 ) ;
V_2 = F_2 ( V_5 , 2 ) ;
F_3 ( ! V_1 || ! V_2 ) ;
F_4 ( 4 , V_2 ) ;
V_3 = F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
F_6 ( V_2 ) ;
return V_3 ;
}
static struct V_6 * T_2
F_7 ( struct V_7 * V_8 , struct V_9 * V_10 , const char * V_11 )
{
T_4 V_12 ;
unsigned V_13 ;
static const unsigned V_14 [ 4 ] = { 3 , 2 , 0 , 1 } ;
if ( strcmp ( V_11 , L_1 ) == 0 ) {
unsigned int V_15 = F_8 ( F_1 () ) ;
const char * V_16 = F_9 ( V_8 , V_15 ) ;
V_13 = V_15 ? ( 32 / 4 ) : 30 ;
return F_10 ( NULL , V_11 , V_16 , 0 , V_13 , 1 ) ;
}
if ( ! V_10 -> V_17 )
return F_11 ( - V_18 ) ;
if ( strcmp ( V_11 , L_2 ) == 0 )
V_12 = ( F_12 ( V_10 -> V_17 + V_19 ) >> 8 ) & 3 ;
else if ( strcmp ( V_11 , L_3 ) == 0 )
V_12 = F_12 ( V_10 -> V_17 + V_20 ) & 3 ;
else
return F_11 ( - V_21 ) ;
V_13 = V_14 [ V_12 ] ;
return F_10 ( NULL , V_11 , L_1 , 0 , V_13 , 3 ) ;
}
static void T_2 F_13 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_6 * * V_22 ;
unsigned V_23 ;
int V_24 ;
V_24 = F_14 ( V_8 , L_4 ) ;
if ( F_15 ( V_24 <= 0 , L_5 ) )
return;
V_10 = F_16 ( sizeof( * V_10 ) , V_25 ) ;
V_22 = F_16 ( V_24 * sizeof( * V_22 ) , V_25 ) ;
F_3 ( ! V_10 || ! V_22 ) ;
V_10 -> V_26 . V_22 = V_22 ;
V_10 -> V_26 . V_27 = V_24 ;
V_10 -> V_17 = F_17 ( V_8 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; ++ V_23 ) {
const char * V_11 ;
struct V_6 * V_6 ;
F_18 ( V_8 , L_4 , V_23 , & V_11 ) ;
V_6 = F_7 ( V_8 , V_10 , V_11 ) ;
if ( F_19 ( V_6 ) )
F_20 ( L_6 ,
V_28 , V_8 -> V_11 , V_11 , F_21 ( V_6 ) ) ;
else
V_10 -> V_26 . V_22 [ V_23 ] = V_6 ;
}
F_22 ( V_8 , V_29 , & V_10 -> V_26 ) ;
F_23 ( V_8 ) ;
}
