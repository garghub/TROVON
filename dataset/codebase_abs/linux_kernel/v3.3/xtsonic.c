static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 , V_6 ,
L_1 , V_2 ) ;
if ( V_3 ) {
F_3 ( V_7 L_2 ,
V_2 -> V_8 , V_2 -> V_4 ) ;
return - V_9 ;
}
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 ) ;
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_10 ;
}
static int T_1 F_8 ( struct V_1 * V_2 )
{
static unsigned V_11 = 0 ;
unsigned int V_12 ;
struct V_13 * V_14 = F_9 ( V_2 ) ;
unsigned int V_15 = V_2 -> V_15 ;
int V_16 ;
int V_10 = 0 ;
if ( ! F_10 ( V_15 , 0x100 , V_17 ) )
return - V_18 ;
V_12 = F_11 ( V_19 ) ;
if ( V_20 > 1 )
F_3 ( L_3 , V_12 ) ;
V_16 = 0 ;
while ( ( V_21 [ V_16 ] != 0xffff ) &&
( V_21 [ V_16 ] != V_12 ) )
V_16 ++ ;
if ( V_21 [ V_16 ] == 0xffff ) {
F_3 ( L_4 ,
V_12 ) ;
return - V_22 ;
}
if ( V_20 && V_11 ++ == 0 )
F_3 ( V_23 ) ;
F_12 ( V_24 , V_25 ) ;
F_12 ( V_26 ,
V_27 | V_28 | V_29 | V_30 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_32 , 0 ) ;
F_12 ( V_24 , V_25 ) ;
F_12 ( V_31 , 0 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
unsigned int V_33 = F_11 ( V_34 - V_16 ) ;
V_2 -> V_35 [ V_16 * 2 ] = V_33 ;
V_2 -> V_35 [ V_16 * 2 + 1 ] = V_33 >> 8 ;
}
V_14 -> V_36 = V_37 ;
V_14 -> V_38 =
F_13 ( V_14 -> V_39 ,
V_40 * F_14 ( V_14 -> V_36 ) ,
& V_14 -> V_41 , V_42 ) ;
if ( V_14 -> V_38 == NULL ) {
F_3 ( V_7 L_5
L_6 , F_15 ( V_14 -> V_39 ) ) ;
goto V_43;
}
V_14 -> V_44 = V_14 -> V_38 ;
V_14 -> V_45 = V_14 -> V_44 + ( V_46
* F_14 ( V_14 -> V_36 ) ) ;
V_14 -> V_47 = V_14 -> V_45 + ( V_48 * V_49
* F_14 ( V_14 -> V_36 ) ) ;
V_14 -> V_50 = V_14 -> V_47 + ( V_51 * V_52
* F_14 ( V_14 -> V_36 ) ) ;
V_14 -> V_53 = V_14 -> V_41 ;
V_14 -> V_54 = V_14 -> V_53 + ( V_46
* F_14 ( V_14 -> V_36 ) ) ;
V_14 -> V_55 = V_14 -> V_54 + ( V_48 * V_49
* F_14 ( V_14 -> V_36 ) ) ;
V_14 -> V_56 = V_14 -> V_55 + ( V_51 * V_52
* F_14 ( V_14 -> V_36 ) ) ;
V_2 -> V_57 = & V_58 ;
V_2 -> V_59 = V_60 ;
F_12 ( V_61 , 0xffff ) ;
F_12 ( V_62 , 0xffff ) ;
F_12 ( V_63 , 0xffff ) ;
return 0 ;
V_43:
F_16 ( V_2 -> V_15 , V_64 ) ;
return V_10 ;
}
int T_2 F_17 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_67 * V_68 , * V_69 ;
int V_10 = 0 ;
if ( ( V_68 = F_18 ( V_66 , V_70 , 0 ) ) == NULL )
return - V_22 ;
if ( ( V_69 = F_18 ( V_66 , V_71 , 0 ) ) == NULL )
return - V_22 ;
if ( ( V_2 = F_19 ( sizeof( struct V_13 ) ) ) == NULL )
return - V_72 ;
V_14 = F_9 ( V_2 ) ;
V_14 -> V_39 = & V_66 -> V_2 ;
F_20 ( V_2 , & V_66 -> V_2 ) ;
F_21 ( V_2 ) ;
V_2 -> V_15 = V_68 -> V_73 ;
V_2 -> V_4 = V_69 -> V_73 ;
if ( ( V_10 = F_8 ( V_2 ) ) )
goto V_43;
if ( ( V_10 = F_22 ( V_2 ) ) )
goto V_74;
F_3 ( L_7 , V_2 -> V_8 ,
V_2 -> V_15 , V_2 -> V_35 , V_2 -> V_4 ) ;
return 0 ;
V_74:
F_16 ( V_2 -> V_15 , V_64 ) ;
V_43:
F_23 ( V_2 ) ;
return V_10 ;
}
static int T_3 F_24 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_25 ( V_66 ) ;
struct V_13 * V_14 = F_9 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_14 -> V_39 ,
V_40 * F_14 ( V_14 -> V_36 ) ,
V_14 -> V_38 , V_14 -> V_41 ) ;
F_16 ( V_2 -> V_15 , V_64 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
