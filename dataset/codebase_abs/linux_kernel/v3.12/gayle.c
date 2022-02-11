static int F_1 ( T_1 * V_1 )
{
unsigned char V_2 ;
V_2 = F_2 ( V_1 -> V_3 . V_4 ) ;
if ( ! ( V_2 & V_5 ) )
return 0 ;
return 1 ;
}
static void F_3 ( T_2 * V_6 )
{
T_1 * V_1 = V_6 -> V_1 ;
( void ) F_2 ( V_1 -> V_3 . V_7 ) ;
F_4 ( 0x7c , V_1 -> V_3 . V_4 ) ;
}
static void T_3 F_5 ( struct V_8 * V_9 , unsigned long V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
int V_13 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_3 . V_14 = V_10 ;
for ( V_13 = 1 ; V_13 < 8 ; V_13 ++ )
V_9 -> V_15 [ V_13 ] = V_10 + 2 + V_13 * 4 ;
V_9 -> V_3 . V_16 = V_11 ;
V_9 -> V_3 . V_4 = V_12 ;
V_9 -> V_17 = V_18 ;
}
static int T_3 F_6 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
unsigned long V_10 , V_25 , V_26 ;
unsigned int V_13 ;
int error ;
struct V_8 V_9 [ V_27 ] , * V_28 [ V_27 ] ;
struct V_29 V_30 = V_31 ;
struct V_32 * V_33 ;
V_22 = F_7 ( V_20 , V_34 , 0 ) ;
if ( ! V_22 )
return - V_35 ;
if ( ! F_8 ( V_22 -> V_36 , F_9 ( V_22 ) , L_1 ) )
return - V_37 ;
V_24 = F_10 ( & V_20 -> V_38 ) ;
F_11 ( L_2 ,
V_24 -> V_39 ? 1200 : 4000 ,
V_40 ? L_3 : L_4 ) ;
V_10 = ( unsigned long ) F_12 ( V_24 -> V_10 ) ;
V_25 = 0 ;
V_26 = ( unsigned long ) F_12 ( V_24 -> V_26 ) ;
if ( V_24 -> V_39 )
V_30 . V_41 = & V_42 ;
else
V_30 . V_41 = & V_43 ;
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ , V_10 += V_45 ) {
if ( V_46 )
V_25 = V_10 + V_47 ;
F_5 ( & V_9 [ V_13 ] , V_10 , V_25 , V_26 ) ;
V_28 [ V_13 ] = & V_9 [ V_13 ] ;
}
error = F_13 ( & V_30 , V_28 , V_13 , & V_33 ) ;
if ( error )
goto V_48;
F_14 ( V_20 , V_33 ) ;
return 0 ;
V_48:
F_15 ( V_22 -> V_36 , F_9 ( V_22 ) ) ;
return error ;
}
static int T_4 F_16 ( struct V_19 * V_20 )
{
struct V_32 * V_33 = F_17 ( V_20 ) ;
struct V_21 * V_22 = F_7 ( V_20 , V_34 , 0 ) ;
F_18 ( V_33 ) ;
F_15 ( V_22 -> V_36 , F_9 ( V_22 ) ) ;
return 0 ;
}
