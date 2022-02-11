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
int V_17 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
F_4 ( & V_2 -> V_18 ) ;
F_4 ( & V_10 -> V_19 . V_20 -> V_21 ) ;
V_15 = ( unsigned char * ) V_10 -> V_19 . V_20 -> V_22 ;
if ( V_4 & V_23 ) {
if ( V_6 > V_24 ) {
F_5 ( L_1 , V_6 ) ;
V_17 = - V_25 ;
goto V_26;
}
if ( V_5 == NULL )
args . V_27 = 0 ;
else
args . V_27 = V_5 [ 0 ] ;
if ( V_6 )
V_6 -- ;
if ( V_6 )
memcpy ( & V_16 , & V_5 [ 1 ] , V_6 ) ;
args . V_28 = F_3 ( V_16 ) ;
} else {
if ( V_6 > V_29 ) {
F_5 ( L_2 , V_6 ) ;
V_17 = - V_25 ;
goto V_26;
}
args . V_27 = 0 ;
args . V_28 = 0 ;
}
args . V_30 = V_4 ;
args . V_31 = V_32 ;
args . V_33 = V_6 ;
args . V_34 = V_3 << 1 ;
args . V_35 = V_2 -> V_36 . V_37 ;
F_6 ( V_10 -> V_19 . V_20 , V_12 , ( V_38 * ) & args ) ;
if ( args . V_39 != V_40 ) {
F_7 ( L_3 ) ;
V_17 = - V_41 ;
goto V_26;
}
if ( ! ( V_4 & V_23 ) )
F_8 ( V_5 , V_15 , V_6 , false ) ;
V_26:
F_9 ( & V_10 -> V_19 . V_20 -> V_21 ) ;
F_9 ( & V_2 -> V_18 ) ;
return V_17 ;
}
int F_10 ( struct V_42 * V_43 ,
struct V_44 * V_45 , int V_6 )
{
struct V_1 * V_46 = F_11 ( V_43 ) ;
struct V_44 * V_47 ;
int V_48 , V_49 , V_50 , V_51 , V_52 , V_53 ;
T_1 V_4 ;
V_47 = & V_45 [ 0 ] ;
if ( ( V_6 == 1 ) && ( V_47 -> V_54 == 0 ) ) {
V_53 = F_1 ( V_46 ,
V_47 -> V_55 , V_23 ,
NULL , 0 ) ;
if ( V_53 )
return V_53 ;
else
return V_6 ;
}
for ( V_48 = 0 ; V_48 < V_6 ; V_48 ++ ) {
V_47 = & V_45 [ V_48 ] ;
V_49 = V_47 -> V_54 ;
V_51 = 0 ;
if ( V_47 -> V_4 & V_56 ) {
V_52 = V_29 ;
V_4 = V_57 ;
} else {
V_52 = V_24 ;
V_4 = V_23 ;
}
while ( V_49 ) {
if ( V_49 > V_52 )
V_50 = V_52 ;
else
V_50 = V_49 ;
V_53 = F_1 ( V_46 ,
V_47 -> V_55 , V_4 ,
& V_47 -> V_5 [ V_51 ] , V_50 ) ;
if ( V_53 )
return V_53 ;
V_49 -= V_50 ;
V_51 += V_50 ;
}
}
return V_6 ;
}
T_4 F_12 ( struct V_42 * V_58 )
{
return V_59 | V_60 ;
}
