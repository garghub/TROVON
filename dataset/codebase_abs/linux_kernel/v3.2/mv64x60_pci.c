static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
T_4 V_12 ;
if ( V_8 > 0 )
return 0 ;
if ( V_9 < V_13 )
return - V_14 ;
V_11 = F_2 ( 0 , F_3 ( 0 , 0 ) ) ;
if ( ! V_11 )
return - V_15 ;
F_4 ( V_11 , V_16 , & V_12 ) ;
F_5 ( V_11 ) ;
return sprintf ( V_7 , L_1 , V_12 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
T_4 V_12 ;
if ( V_8 > 0 )
return 0 ;
if ( V_9 <= 0 )
return - V_14 ;
if ( sscanf ( V_7 , L_2 , & V_12 ) != 1 )
return - V_14 ;
V_11 = F_2 ( 0 , F_3 ( 0 , 0 ) ) ;
if ( ! V_11 )
return - V_15 ;
F_7 ( V_11 , V_16 , V_12 ) ;
F_5 ( V_11 ) ;
return V_9 ;
}
static int T_5 F_8 ( void )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
const unsigned int * V_21 ;
V_18 = F_9 ( NULL , NULL , L_3 ) ;
if ( ! V_18 )
return 0 ;
V_21 = F_10 ( V_18 , L_4 , NULL ) ;
F_11 ( V_18 ) ;
V_20 = F_12 ( L_3 , 0 , NULL , 0 ) ;
if ( F_13 ( V_20 ) )
return F_14 ( V_20 ) ;
return F_15 ( & V_20 -> V_22 . V_4 , & V_23 ) ;
}
static void T_5 F_16 ( struct V_10 * V_22 )
{
V_22 -> V_24 = V_25 ;
}
static int T_5 F_17 ( struct V_17 * V_22 )
{
int V_26 ;
struct V_27 * V_28 ;
struct V_29 V_30 ;
const int * V_31 ;
int V_32 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
if ( F_18 ( V_22 , 0 , & V_30 ) ) {
F_19 ( V_33 L_5 ) ;
return - V_15 ;
}
V_31 = F_10 ( V_22 , L_6 , & V_26 ) ;
if ( V_31 == NULL || V_26 < 2 * sizeof( int ) )
F_19 ( V_34 L_7
L_8 , V_22 -> V_35 ) ;
V_28 = F_20 ( V_22 ) ;
if ( ! V_28 )
return - V_36 ;
V_28 -> V_37 = V_31 ? V_31 [ 0 ] : 0 ;
V_28 -> V_38 = V_31 ? V_31 [ 1 ] : 0xff ;
F_21 ( V_28 , V_30 . V_39 , V_30 . V_39 + 4 , 0 ) ;
V_28 -> V_40 = V_28 -> V_37 ;
F_19 ( V_41 L_9
L_10 ,
( unsigned long long ) V_30 . V_39 , V_28 -> V_37 ,
V_28 -> V_38 ) ;
V_32 = ( V_28 -> V_37 == 0 ) ;
F_22 ( V_28 , V_22 , V_32 ) ;
return 0 ;
}
void T_5 F_23 ( void )
{
struct V_17 * V_18 ;
F_24 (np, L_11 , L_12 )
F_17 ( V_18 ) ;
}
