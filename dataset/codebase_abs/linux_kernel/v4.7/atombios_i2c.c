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
V_15 = ( unsigned char * ) V_10 -> V_19 . V_20 -> V_21 ;
if ( V_4 & V_22 ) {
if ( V_6 > V_23 ) {
F_5 ( L_1 , V_6 ) ;
V_17 = - V_24 ;
goto V_25;
}
if ( V_5 == NULL )
args . V_26 = 0 ;
else
args . V_26 = V_5 [ 0 ] ;
if ( V_6 )
V_6 -- ;
if ( V_6 )
memcpy ( & V_16 , & V_5 [ 1 ] , V_6 ) ;
args . V_27 = F_3 ( V_16 ) ;
} else {
if ( V_6 > V_28 ) {
F_5 ( L_2 , V_6 ) ;
V_17 = - V_24 ;
goto V_25;
}
args . V_26 = 0 ;
args . V_27 = 0 ;
}
args . V_29 = V_4 ;
args . V_30 = V_31 ;
args . V_32 = V_6 ;
args . V_33 = V_3 << 1 ;
args . V_34 = V_2 -> V_35 . V_36 ;
F_6 ( V_10 -> V_19 . V_20 , V_12 , ( V_37 * ) & args ) ;
if ( args . V_38 != V_39 ) {
F_7 ( L_3 ) ;
V_17 = - V_40 ;
goto V_25;
}
if ( ! ( V_4 & V_22 ) )
F_8 ( V_5 , V_15 , V_6 , false ) ;
V_25:
F_9 ( & V_2 -> V_18 ) ;
return V_17 ;
}
int F_10 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_6 )
{
struct V_1 * V_45 = F_11 ( V_42 ) ;
struct V_43 * V_46 ;
int V_47 , V_48 , V_49 , V_50 , V_51 , V_52 ;
T_1 V_4 ;
V_46 = & V_44 [ 0 ] ;
if ( ( V_6 == 1 ) && ( V_46 -> V_53 == 0 ) ) {
V_52 = F_1 ( V_45 ,
V_46 -> V_54 , V_22 ,
NULL , 0 ) ;
if ( V_52 )
return V_52 ;
else
return V_6 ;
}
for ( V_47 = 0 ; V_47 < V_6 ; V_47 ++ ) {
V_46 = & V_44 [ V_47 ] ;
V_48 = V_46 -> V_53 ;
V_50 = 0 ;
if ( V_46 -> V_4 & V_55 ) {
V_51 = V_28 ;
V_4 = V_56 ;
} else {
V_51 = V_23 ;
V_4 = V_22 ;
}
while ( V_48 ) {
if ( V_48 > V_51 )
V_49 = V_51 ;
else
V_49 = V_48 ;
V_52 = F_1 ( V_45 ,
V_46 -> V_54 , V_4 ,
& V_46 -> V_5 [ V_50 ] , V_49 ) ;
if ( V_52 )
return V_52 ;
V_48 -= V_49 ;
V_50 += V_49 ;
}
}
return V_6 ;
}
T_4 F_12 ( struct V_41 * V_57 )
{
return V_58 | V_59 ;
}
void F_13 ( struct V_9 * V_10 , T_1 V_3 , T_1 V_60 , T_1 V_61 , T_1 V_62 )
{
T_2 args ;
int V_12 = F_2 ( V_13 , V_14 ) ;
args . V_26 = V_61 ;
args . V_27 = V_62 ;
args . V_29 = 1 ;
args . V_30 = V_31 ;
args . V_32 = 1 ;
args . V_33 = V_3 ;
args . V_34 = V_60 ;
F_6 ( V_10 -> V_19 . V_20 , V_12 , ( V_37 * ) & args ) ;
}
