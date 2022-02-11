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
void F_7 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_8 ( V_33 , struct V_34 ,
V_36 ) ;
T_3 V_37 = 0x00 , V_38 = 0x00 ;
unsigned long V_39 ;
V_37 = F_9 ( V_35 , 0x117 ) ;
V_38 = V_37 & 0xfe ;
F_10 ( V_35 , 0x117 , V_38 ) ;
F_11 ( & V_35 -> V_40 , V_39 ) ;
V_35 -> V_41 = 1 ;
F_12 ( & V_35 -> V_40 , V_39 ) ;
do {
F_13 ( 100 ) ;
} while ( V_35 -> V_41 == 1 );
F_10 ( V_35 , 0x117 , V_37 ) ;
}
int F_14 ( struct V_34 * V_35 ,
struct V_42 * V_43 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_43 -> V_44 [ V_18 ] = F_15 ( 0 , V_45 ) ;
if ( V_43 -> V_44 [ V_18 ] == NULL ) {
F_16 ( V_35 -> V_46 , L_1 ) ;
return V_47 ;
}
}
return V_48 ;
}
void F_17 ( struct V_34 * V_35 ,
struct V_42 * V_43 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
if ( V_43 -> V_44 [ V_18 ] ) {
F_18 ( V_43 -> V_44 [ V_18 ] ) ;
F_19 ( V_43 -> V_44 [ V_18 ] ) ;
}
}
}
void F_20 ( struct V_34 * V_35 , struct V_49 * V_50 )
{
if ( V_50 -> V_8 )
F_21 ( V_50 -> V_8 ) ;
V_50 -> V_8 = NULL ;
}
int F_22 ( T_2 * V_8 , struct V_51 * V_46 )
{
struct V_49 * V_52 = NULL ;
struct V_34 * V_35 = (struct V_34 * ) F_23 ( V_46 ) ;
struct V_53 * V_54 = & ( V_35 -> V_55 ) ;
int V_56 = 0 ;
if ( F_24 ( V_35 ) == false ) {
V_56 = 0 ;
goto V_57;
}
V_52 = F_25 ( V_54 ) ;
if ( V_52 == NULL ) {
V_56 = 0 ;
goto V_57;
}
if ( ( ! F_26 ( V_35 , V_8 , & V_52 -> V_58 ) ) ) {
V_56 = 0 ;
goto V_57;
}
V_35 -> V_59 . V_60 ( V_35 , V_61 ) ;
V_52 -> V_8 = V_8 ;
if ( F_27 ( V_35 , V_52 ) == true ) {
F_21 ( V_8 ) ;
V_52 -> V_8 = NULL ;
}
V_54 -> V_62 ++ ;
V_54 -> V_63 += V_52 -> V_58 . V_64 ;
return V_56 ;
V_57:
if ( V_52 )
F_28 ( V_54 , V_52 ) ;
V_54 -> V_65 ++ ;
F_21 ( V_8 ) ;
return V_56 ;
}
