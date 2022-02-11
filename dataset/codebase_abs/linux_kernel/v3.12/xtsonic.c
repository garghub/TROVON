static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 , 0 , L_1 , V_2 ) ;
if ( V_3 ) {
F_3 ( V_6 L_2 ,
V_2 -> V_7 , V_2 -> V_4 ) ;
return - V_8 ;
}
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_7 ( V_2 ) ;
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_9 ;
}
static int T_1 F_8 ( struct V_1 * V_2 )
{
static unsigned V_10 = 0 ;
unsigned int V_11 ;
struct V_12 * V_13 = F_9 ( V_2 ) ;
unsigned int V_14 = V_2 -> V_14 ;
int V_15 ;
int V_9 = 0 ;
if ( ! F_10 ( V_14 , 0x100 , V_16 ) )
return - V_17 ;
V_11 = F_11 ( V_18 ) ;
if ( V_19 > 1 )
F_3 ( L_3 , V_11 ) ;
V_15 = 0 ;
while ( ( V_20 [ V_15 ] != 0xffff ) &&
( V_20 [ V_15 ] != V_11 ) )
V_15 ++ ;
if ( V_20 [ V_15 ] == 0xffff ) {
F_3 ( L_4 ,
V_11 ) ;
return - V_21 ;
}
if ( V_19 && V_10 ++ == 0 )
F_3 ( V_22 ) ;
F_12 ( V_23 , V_24 ) ;
F_12 ( V_25 ,
V_26 | V_27 | V_28 | V_29 ) ;
F_12 ( V_30 , 0 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_23 , V_24 ) ;
F_12 ( V_30 , 0 ) ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
unsigned int V_32 = F_11 ( V_33 - V_15 ) ;
V_2 -> V_34 [ V_15 * 2 ] = V_32 ;
V_2 -> V_34 [ V_15 * 2 + 1 ] = V_32 >> 8 ;
}
V_13 -> V_35 = V_36 ;
V_13 -> V_37 = F_13 ( V_13 -> V_38 ,
V_39 *
F_14 ( V_13 -> V_35 ) ,
& V_13 -> V_40 ,
V_41 ) ;
if ( V_13 -> V_37 == NULL ) {
V_9 = - V_42 ;
goto V_43;
}
V_13 -> V_44 = V_13 -> V_37 ;
V_13 -> V_45 = V_13 -> V_44 + ( V_46
* F_14 ( V_13 -> V_35 ) ) ;
V_13 -> V_47 = V_13 -> V_45 + ( V_48 * V_49
* F_14 ( V_13 -> V_35 ) ) ;
V_13 -> V_50 = V_13 -> V_47 + ( V_51 * V_52
* F_14 ( V_13 -> V_35 ) ) ;
V_13 -> V_53 = V_13 -> V_40 ;
V_13 -> V_54 = V_13 -> V_53 + ( V_46
* F_14 ( V_13 -> V_35 ) ) ;
V_13 -> V_55 = V_13 -> V_54 + ( V_48 * V_49
* F_14 ( V_13 -> V_35 ) ) ;
V_13 -> V_56 = V_13 -> V_55 + ( V_51 * V_52
* F_14 ( V_13 -> V_35 ) ) ;
V_2 -> V_57 = & V_58 ;
V_2 -> V_59 = V_60 ;
F_12 ( V_61 , 0xffff ) ;
F_12 ( V_62 , 0xffff ) ;
F_12 ( V_63 , 0xffff ) ;
return 0 ;
V_43:
F_15 ( V_2 -> V_14 , V_64 ) ;
return V_9 ;
}
int F_16 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_67 * V_68 , * V_69 ;
int V_9 = 0 ;
if ( ( V_68 = F_17 ( V_66 , V_70 , 0 ) ) == NULL )
return - V_21 ;
if ( ( V_69 = F_17 ( V_66 , V_71 , 0 ) ) == NULL )
return - V_21 ;
if ( ( V_2 = F_18 ( sizeof( struct V_12 ) ) ) == NULL )
return - V_42 ;
V_13 = F_9 ( V_2 ) ;
V_13 -> V_38 = & V_66 -> V_2 ;
F_19 ( V_2 , & V_66 -> V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_14 = V_68 -> V_72 ;
V_2 -> V_4 = V_69 -> V_72 ;
if ( ( V_9 = F_8 ( V_2 ) ) )
goto V_43;
if ( ( V_9 = F_21 ( V_2 ) ) )
goto V_73;
F_3 ( L_5 , V_2 -> V_7 ,
V_2 -> V_14 , V_2 -> V_34 , V_2 -> V_4 ) ;
return 0 ;
V_73:
F_15 ( V_2 -> V_14 , V_64 ) ;
V_43:
F_22 ( V_2 ) ;
return V_9 ;
}
static int F_23 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_24 ( V_66 ) ;
struct V_12 * V_13 = F_9 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_13 -> V_38 ,
V_39 * F_14 ( V_13 -> V_35 ) ,
V_13 -> V_37 , V_13 -> V_40 ) ;
F_15 ( V_2 -> V_14 , V_64 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
