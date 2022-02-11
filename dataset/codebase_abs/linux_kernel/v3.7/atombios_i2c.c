static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_2 args ;
int V_12 = F_2 ( V_13 , V_14 ) ;
unsigned char * V_15 ;
T_3 V_16 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_15 = ( unsigned char * ) V_10 -> V_17 . V_18 -> V_19 ;
if ( V_4 & V_20 ) {
if ( V_6 > V_21 ) {
F_3 ( L_1 , V_6 ) ;
return - V_22 ;
}
memcpy ( & V_16 , V_5 , V_6 ) ;
args . V_23 = F_4 ( V_16 ) ;
} else {
if ( V_6 > V_24 ) {
F_3 ( L_2 , V_6 ) ;
return - V_22 ;
}
}
args . V_25 = V_26 ;
args . V_27 = 0 ;
args . V_28 = V_6 ;
args . V_29 = V_3 << 1 ;
args . V_30 = V_2 -> V_31 . V_32 ;
F_5 ( V_10 -> V_17 . V_18 , V_12 , ( V_33 * ) & args ) ;
if ( args . V_34 != V_35 ) {
F_6 ( L_3 ) ;
return - V_36 ;
}
if ( ! ( V_4 & V_20 ) )
memcpy ( V_5 , V_15 , V_6 ) ;
return 0 ;
}
int F_7 ( struct V_37 * V_38 ,
struct V_39 * V_40 , int V_6 )
{
struct V_1 * V_41 = F_8 ( V_38 ) ;
struct V_39 * V_42 ;
int V_43 , V_44 , V_45 , V_46 , V_47 , V_48 ;
T_1 V_5 = 0 , V_4 ;
V_42 = & V_40 [ 0 ] ;
if ( ( V_6 == 1 ) && ( V_42 -> V_49 == 0 ) ) {
V_48 = F_1 ( V_41 ,
V_42 -> V_50 , V_20 ,
& V_5 , 1 ) ;
if ( V_48 )
return V_48 ;
else
return V_6 ;
}
for ( V_43 = 0 ; V_43 < V_6 ; V_43 ++ ) {
V_42 = & V_40 [ V_43 ] ;
V_44 = V_42 -> V_49 ;
V_46 = 0 ;
if ( V_42 -> V_4 & V_51 ) {
V_47 = V_24 ;
V_4 = V_52 ;
} else {
V_47 = V_21 ;
V_4 = V_20 ;
}
while ( V_44 ) {
if ( V_44 > V_47 )
V_45 = V_47 ;
else
V_45 = V_44 ;
V_48 = F_1 ( V_41 ,
V_42 -> V_50 , V_4 ,
& V_42 -> V_5 [ V_46 ] , V_45 ) ;
if ( V_48 )
return V_48 ;
V_44 -= V_45 ;
V_46 += V_45 ;
}
}
return V_6 ;
}
T_4 F_9 ( struct V_37 * V_53 )
{
return V_54 | V_55 ;
}
