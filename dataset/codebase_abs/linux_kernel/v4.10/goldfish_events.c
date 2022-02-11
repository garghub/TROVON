static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned type , V_5 , V_6 ;
type = F_2 ( V_4 -> V_7 + V_8 ) ;
V_5 = F_2 ( V_4 -> V_7 + V_8 ) ;
V_6 = F_2 ( V_4 -> V_7 + V_8 ) ;
F_3 ( V_4 -> V_9 , type , V_5 , V_6 ) ;
F_4 ( V_4 -> V_9 ) ;
return V_10 ;
}
static void F_5 ( struct V_3 * V_4 ,
unsigned long V_11 [] , unsigned type , T_2 V_12 )
{
void T_3 * V_7 = V_4 -> V_7 ;
int V_13 , V_14 ;
T_2 V_15 ;
T_4 V_16 ;
F_6 ( V_17 | type , V_7 + V_18 ) ;
V_15 = F_2 ( V_7 + V_19 ) * 8 ;
if ( V_15 < V_12 )
V_12 = V_15 ;
V_7 += V_20 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 += 8 ) {
V_16 = F_7 ( V_7 ++ ) ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ )
if ( V_16 & 1 << V_14 )
F_8 ( V_13 + V_14 , V_11 ) ;
}
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_21 * V_21 = V_4 -> V_9 ;
void T_3 * V_7 = V_4 -> V_7 ;
T_5 V_16 [ 4 ] ;
int V_12 ;
int V_13 , V_14 ;
F_6 ( V_22 , V_7 + V_18 ) ;
V_12 = F_2 ( V_7 + V_19 ) / sizeof( V_16 ) ;
if ( V_12 > V_23 )
V_12 = V_23 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( ! F_10 ( V_13 , V_21 -> V_24 ) )
continue;
for ( V_14 = 0 ; V_14 < F_11 ( V_16 ) ; V_14 ++ ) {
int V_25 = ( V_13 * F_11 ( V_16 ) + V_14 ) * sizeof( T_5 ) ;
V_16 [ V_14 ] = F_2 ( V_4 -> V_7 + V_20 + V_25 ) ;
}
F_12 ( V_21 , V_13 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
}
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_21 * V_21 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
unsigned V_30 ;
void T_3 * V_7 ;
int V_1 ;
int V_13 ;
int error ;
V_1 = F_14 ( V_27 , 0 ) ;
if ( V_1 < 0 )
return - V_31 ;
V_29 = F_15 ( V_27 , V_32 , 0 ) ;
if ( ! V_29 )
return - V_31 ;
V_7 = F_16 ( & V_27 -> V_33 , V_29 -> V_34 , 4096 ) ;
if ( ! V_7 )
return - V_35 ;
F_6 ( V_36 , V_7 + V_18 ) ;
V_30 = F_2 ( V_7 + V_19 ) ;
V_4 = F_17 ( & V_27 -> V_33 ,
sizeof( struct V_3 ) + V_30 + 1 ,
V_37 ) ;
if ( ! V_4 )
return - V_35 ;
V_21 = F_18 ( & V_27 -> V_33 ) ;
if ( ! V_21 )
return - V_35 ;
V_4 -> V_9 = V_21 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_1 = V_1 ;
for ( V_13 = 0 ; V_13 < V_30 ; V_13 ++ )
V_4 -> V_38 [ V_13 ] = F_7 ( V_4 -> V_7 + V_20 + V_13 ) ;
F_19 ( L_1 , V_4 -> V_38 ) ;
V_21 -> V_38 = V_4 -> V_38 ;
V_21 -> V_39 . V_40 = V_41 ;
F_5 ( V_4 , V_21 -> V_42 , V_43 , V_44 ) ;
F_5 ( V_4 , V_21 -> V_45 , V_46 , V_47 ) ;
F_5 ( V_4 , V_21 -> V_48 , V_49 , V_50 ) ;
F_5 ( V_4 , V_21 -> V_24 , V_51 , V_23 ) ;
F_5 ( V_4 , V_21 -> V_52 , V_53 , V_54 ) ;
F_5 ( V_4 , V_21 -> V_55 , V_56 , V_57 ) ;
F_5 ( V_4 , V_21 -> V_58 , V_59 , V_60 ) ;
F_5 ( V_4 , V_21 -> V_61 , V_62 , V_63 ) ;
F_5 ( V_4 , V_21 -> V_64 , V_65 , V_66 ) ;
F_9 ( V_4 ) ;
error = F_20 ( & V_27 -> V_33 , V_4 -> V_1 , F_1 , 0 ,
L_2 , V_4 ) ;
if ( error )
return error ;
error = F_21 ( V_21 ) ;
if ( error )
return error ;
return 0 ;
}
