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
return ( V_2 -> V_10 == 0 ) ;
}
void F_6 ( struct V_1 * V_15 , struct V_16 * V_17 )
{
struct V_18 V_19 ;
struct V_20 V_21 ;
T_5 V_22 = 0 ;
F_2 ( V_15 -> V_8 , V_15 ) ;
F_3 ( V_15 , ( unsigned char * ) & V_19 , V_23 ) ;
if ( V_17 -> V_24 == 0x0800 ) {
F_3 ( V_15 , ( T_3 * ) & V_21 , sizeof( V_21 ) ) ;
V_22 = V_21 . V_25 >> 5 ;
} else {
if ( V_17 -> V_24 == 0x888e )
V_22 = 7 ;
}
V_17 -> V_26 = V_22 ;
V_17 -> V_27 = V_28 ;
V_17 -> V_29 = V_30 ;
}
void F_7 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_8 ( V_32 , struct V_33 ,
V_35 ) ;
T_3 V_36 = 0x00 , V_37 = 0x00 ;
unsigned long V_38 ;
V_36 = F_9 ( V_34 , 0x117 ) ;
V_37 = V_36 & 0xfe ;
F_10 ( V_34 , 0x117 , V_37 ) ;
F_11 ( & V_34 -> V_39 , V_38 ) ;
V_34 -> V_40 = 1 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
do {
F_13 ( 100 ) ;
} while ( V_34 -> V_40 == 1 );
F_10 ( V_34 , 0x117 , V_36 ) ;
}
int F_14 ( struct V_33 * V_34 ,
struct V_41 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
V_42 -> V_44 [ V_43 ] = F_15 ( 0 , V_45 ) ;
if ( ! V_42 -> V_44 [ V_43 ] ) {
F_16 ( V_34 -> V_46 , L_1 ) ;
return V_47 ;
}
F_17 ( V_42 -> V_44 [ V_43 ] ) ;
}
return V_48 ;
}
void F_18 ( struct V_33 * V_34 ,
struct V_41 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( V_42 -> V_44 [ V_43 ] ) {
F_19 ( V_42 -> V_44 [ V_43 ] ) ;
F_20 ( V_42 -> V_44 [ V_43 ] ) ;
}
}
}
void F_21 ( struct V_33 * V_34 , struct V_49 * V_50 )
{
if ( V_50 -> V_8 )
F_22 ( V_50 -> V_8 ) ;
V_50 -> V_8 = NULL ;
}
int F_23 ( T_2 * V_8 , struct V_51 * V_46 )
{
struct V_49 * V_52 = NULL ;
struct V_33 * V_34 = F_24 ( V_46 ) ;
struct V_53 * V_54 = & ( V_34 -> V_55 ) ;
if ( ! F_25 ( V_34 ) )
goto V_56;
V_52 = F_26 ( V_54 ) ;
if ( ! V_52 )
goto V_56;
if ( ( ! F_27 ( V_34 , V_8 , & V_52 -> V_57 ) ) )
goto V_56;
V_34 -> V_58 . V_59 ( V_34 , V_60 ) ;
V_52 -> V_8 = V_8 ;
if ( F_28 ( V_34 , V_52 ) ) {
F_22 ( V_8 ) ;
V_52 -> V_8 = NULL ;
}
V_54 -> V_61 ++ ;
V_54 -> V_62 += V_52 -> V_57 . V_63 ;
return 0 ;
V_56:
if ( V_52 )
F_29 ( V_54 , V_52 ) ;
V_54 -> V_64 ++ ;
F_22 ( V_8 ) ;
return 0 ;
}
