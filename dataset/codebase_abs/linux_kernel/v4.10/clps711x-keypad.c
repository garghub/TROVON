static void F_1 ( struct V_1 * V_2 )
{
const unsigned short * V_3 = V_2 -> V_4 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
bool V_9 = false ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
F_2 ( V_7 -> V_13 , V_14 ,
V_15 ,
F_3 ( 8 + V_10 ) ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_16 ; V_11 ++ ) {
struct V_17 * V_18 = & V_7 -> V_19 [ V_11 ] ;
bool V_20 , V_21 ;
do {
V_20 = F_4 ( V_18 -> V_22 ) ;
F_5 () ;
V_21 = F_4 ( V_18 -> V_22 ) ;
} while ( V_20 != V_21 );
if ( F_6 ( V_10 , V_18 -> V_23 ) != V_20 ) {
int V_24 = F_7 ( V_11 , V_10 ,
V_7 -> V_25 ) ;
if ( V_20 ) {
F_8 ( V_10 , V_18 -> V_23 ) ;
F_9 ( V_2 -> V_4 , V_26 ,
V_27 , V_24 ) ;
} else {
F_10 ( V_10 , V_18 -> V_23 ) ;
}
if ( V_3 [ V_24 ] )
F_11 ( V_2 -> V_4 ,
V_3 [ V_24 ] , V_20 ) ;
V_9 = true ;
}
}
F_2 ( V_7 -> V_13 , V_14 ,
V_15 , F_3 ( 1 ) ) ;
}
if ( V_9 )
F_12 ( V_2 -> V_4 ) ;
}
static int F_13 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_30 * V_2 = & V_29 -> V_2 ;
struct V_31 * V_32 = V_2 -> V_33 ;
struct V_1 * V_34 ;
T_1 V_35 ;
int V_36 , V_37 ;
V_7 = F_14 ( V_2 , sizeof( * V_7 ) , V_38 ) ;
if ( ! V_7 )
return - V_39 ;
V_7 -> V_13 =
F_15 ( L_1 ) ;
if ( F_16 ( V_7 -> V_13 ) )
return F_17 ( V_7 -> V_13 ) ;
V_7 -> V_16 = F_18 ( V_32 , L_2 ) ;
if ( V_7 -> V_16 < 1 )
return - V_40 ;
V_7 -> V_19 = F_14 ( V_2 ,
sizeof( * V_7 -> V_19 ) * V_7 -> V_16 ,
V_38 ) ;
if ( ! V_7 -> V_19 )
return - V_39 ;
V_7 -> V_25 = F_19 ( V_12 ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_16 ; V_36 ++ ) {
struct V_17 * V_18 = & V_7 -> V_19 [ V_36 ] ;
V_18 -> V_22 = F_20 ( V_2 , L_3 , V_36 , V_41 ) ;
if ( F_16 ( V_18 -> V_22 ) )
return F_17 ( V_18 -> V_22 ) ;
}
V_37 = F_21 ( V_32 , L_4 , & V_35 ) ;
if ( V_37 )
return V_37 ;
V_34 = F_22 () ;
if ( ! V_34 )
return - V_39 ;
V_34 -> V_8 = V_7 ;
V_34 -> V_42 = F_1 ;
V_34 -> V_35 = V_35 ;
V_34 -> V_4 -> V_43 = V_29 -> V_43 ;
V_34 -> V_4 -> V_2 . V_44 = V_2 ;
V_34 -> V_4 -> V_45 . V_46 = V_47 ;
V_34 -> V_4 -> V_45 . V_48 = 0x0001 ;
V_34 -> V_4 -> V_45 . V_49 = 0x0001 ;
V_34 -> V_4 -> V_45 . V_50 = 0x0100 ;
V_37 = F_23 ( NULL , NULL , V_7 -> V_16 ,
V_12 ,
NULL , V_34 -> V_4 ) ;
if ( V_37 )
goto V_51;
F_24 ( V_34 -> V_4 , V_26 , V_27 ) ;
if ( F_25 ( V_32 , L_5 ) )
F_26 ( V_52 , V_34 -> V_4 -> V_53 ) ;
F_27 ( V_29 , V_34 ) ;
F_2 ( V_7 -> V_13 , V_14 , V_15 ,
F_3 ( 1 ) ) ;
V_37 = F_28 ( V_34 ) ;
if ( V_37 )
goto V_51;
return 0 ;
V_51:
F_29 ( V_34 ) ;
return V_37 ;
}
static int F_30 ( struct V_28 * V_29 )
{
struct V_1 * V_34 = F_31 ( V_29 ) ;
F_32 ( V_34 ) ;
F_29 ( V_34 ) ;
return 0 ;
}
