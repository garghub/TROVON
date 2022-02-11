static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_2 args ;
int V_12 = F_2 ( V_13 , V_14 ) ;
unsigned char * V_15 ;
T_3 V_16 = F_3 ( 0 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
V_15 = ( unsigned char * ) V_10 -> V_17 . V_18 -> V_19 ;
if ( V_4 & V_20 ) {
if ( V_6 > V_21 ) {
F_4 ( L_1 , V_6 ) ;
return - V_22 ;
}
if ( V_5 == NULL )
args . V_23 = 0 ;
else
args . V_23 = V_5 [ 0 ] ;
if ( V_6 )
V_6 -- ;
if ( V_6 )
memcpy ( & V_16 , & V_5 [ 1 ] , V_6 ) ;
args . V_24 = F_3 ( V_16 ) ;
} else {
if ( V_6 > V_25 ) {
F_4 ( L_2 , V_6 ) ;
return - V_22 ;
}
args . V_23 = 0 ;
args . V_24 = 0 ;
}
args . V_26 = V_4 ;
args . V_27 = V_28 ;
args . V_29 = V_6 ;
args . V_30 = V_3 << 1 ;
args . V_31 = V_2 -> V_32 . V_33 ;
F_5 ( V_10 -> V_17 . V_18 , V_12 , ( V_34 * ) & args ) ;
if ( args . V_35 != V_36 ) {
F_6 ( L_3 ) ;
return - V_37 ;
}
if ( ! ( V_4 & V_20 ) )
F_7 ( V_5 , V_15 , V_6 , false ) ;
return 0 ;
}
int F_8 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_6 )
{
struct V_1 * V_42 = F_9 ( V_39 ) ;
struct V_40 * V_43 ;
int V_44 , V_45 , V_46 , V_47 , V_48 , V_49 ;
T_1 V_4 ;
V_43 = & V_41 [ 0 ] ;
if ( ( V_6 == 1 ) && ( V_43 -> V_50 == 0 ) ) {
V_49 = F_1 ( V_42 ,
V_43 -> V_51 , V_20 ,
NULL , 0 ) ;
if ( V_49 )
return V_49 ;
else
return V_6 ;
}
for ( V_44 = 0 ; V_44 < V_6 ; V_44 ++ ) {
V_43 = & V_41 [ V_44 ] ;
V_45 = V_43 -> V_50 ;
V_47 = 0 ;
if ( V_43 -> V_4 & V_52 ) {
V_48 = V_25 ;
V_4 = V_53 ;
} else {
V_48 = V_21 ;
V_4 = V_20 ;
}
while ( V_45 ) {
if ( V_45 > V_48 )
V_46 = V_48 ;
else
V_46 = V_45 ;
V_49 = F_1 ( V_42 ,
V_43 -> V_51 , V_4 ,
& V_43 -> V_5 [ V_47 ] , V_46 ) ;
if ( V_49 )
return V_49 ;
V_45 -= V_46 ;
V_47 += V_46 ;
}
}
return V_6 ;
}
T_4 F_10 ( struct V_38 * V_54 )
{
return V_55 | V_56 ;
}
