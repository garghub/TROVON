static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) ( V_2 -> V_3 - ( ( V_4 ) ( V_2 -> V_5 ) -
( V_4 ) ( V_2 -> V_6 ) ) ) ;
}
void F_2 ( T_2 * V_7 , struct V_1 * V_2 )
{
V_2 -> V_8 = V_7 ;
V_2 -> V_5 = V_2 -> V_6 = V_7 -> V_9 ;
V_2 -> V_10 = V_2 -> V_3 = V_7 -> V_11 ;
V_2 -> V_12 = V_2 -> V_6 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 * V_13 , T_1 V_14 )
{
T_1 V_11 ;
V_11 = F_1 ( V_2 ) ;
V_11 = ( V_14 > V_11 ) ? V_11 : V_14 ;
if ( V_13 )
F_4 ( V_2 -> V_8 , V_2 -> V_3 - V_2 -> V_10 ,
V_13 , V_11 ) ;
V_2 -> V_5 += V_11 ;
V_2 -> V_10 -= V_11 ;
return V_11 ;
}
T_4 F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 == 0 )
return true ;
else
return false ;
}
void F_6 ( struct V_1 * V_15 , struct V_16 * V_17 )
{
int V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
T_5 V_23 = 0 ;
F_2 ( V_15 -> V_8 , V_15 ) ;
F_3 ( V_15 , ( unsigned char * ) & V_20 , V_24 ) ;
if ( V_17 -> V_25 == 0x0800 ) {
V_18 = F_3 ( V_15 , ( T_3 * ) & V_22 ,
sizeof( V_22 ) ) ;
V_23 = V_22 . V_26 >> 5 ;
} else {
if ( V_17 -> V_25 == 0x888e )
V_23 = 7 ;
}
V_17 -> V_27 = V_23 ;
V_17 -> V_28 = V_29 ;
V_17 -> V_30 = V_31 ;
}
int F_7 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_35 -> V_36 [ V_18 ] = F_8 ( 0 , V_37 ) ;
if ( V_35 -> V_36 [ V_18 ] == NULL ) {
F_9 ( V_38 L_1
L_2 ) ;
return V_39 ;
}
}
return V_40 ;
}
void F_10 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
if ( V_35 -> V_36 [ V_18 ] ) {
F_11 ( V_35 -> V_36 [ V_18 ] ) ;
F_12 ( V_35 -> V_36 [ V_18 ] ) ;
}
}
}
void F_13 ( struct V_32 * V_33 , struct V_41 * V_42 )
{
if ( V_42 -> V_8 )
F_14 ( V_42 -> V_8 ) ;
V_42 -> V_8 = NULL ;
}
int F_15 ( T_2 * V_8 , struct V_43 * V_44 )
{
struct V_41 * V_45 = NULL ;
struct V_32 * V_33 = (struct V_32 * ) F_16 ( V_44 ) ;
struct V_46 * V_47 = & ( V_33 -> V_48 ) ;
int V_49 = 0 ;
if ( F_17 ( V_33 ) == false ) {
V_49 = 0 ;
goto V_50;
}
V_45 = F_18 ( V_47 ) ;
if ( V_45 == NULL ) {
V_49 = 0 ;
goto V_50;
}
if ( ( ! F_19 ( V_33 , V_8 , & V_45 -> V_51 ) ) ) {
V_49 = 0 ;
goto V_50;
}
V_33 -> V_52 . V_53 ( V_33 , V_54 ) ;
V_45 -> V_8 = V_8 ;
if ( F_20 ( V_33 , V_45 ) == true ) {
F_14 ( V_8 ) ;
V_45 -> V_8 = NULL ;
}
V_47 -> V_55 ++ ;
V_47 -> V_56 += V_45 -> V_51 . V_57 ;
return V_49 ;
V_50:
if ( V_45 )
F_21 ( V_47 , V_45 ) ;
V_47 -> V_58 ++ ;
F_14 ( V_8 ) ;
return V_49 ;
}
