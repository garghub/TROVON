static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_8 ;
F_4 ( V_7 , V_3 ) ;
V_8 = F_5 ( V_5 -> V_9 + V_10 ) ;
if ( V_8 == 0 ) {
F_6 ( V_1 , V_3 ) ;
goto V_11;
}
do {
V_1 = F_7 ( V_8 ) - 1 ;
V_8 &= ~ ( 1 << V_1 ) ;
F_8 ( F_9 ( V_5 -> V_12 , V_1 ) ) ;
} while ( V_8 );
V_11:
F_10 ( V_7 , V_3 ) ;
}
static void F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_4 * V_5 = V_16 -> V_17 ;
T_1 V_18 ;
F_13 ( V_16 ) ;
V_5 -> V_19 = F_5 ( V_5 -> V_9 ) | V_5 -> V_20 ;
if ( V_5 -> V_21 ) {
V_18 = V_5 -> V_19 | V_16 -> V_22 ;
F_14 ( V_18 , V_5 -> V_9 ) ;
}
F_15 ( V_16 ) ;
}
static void F_16 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_4 * V_5 = V_16 -> V_17 ;
F_13 ( V_16 ) ;
F_14 ( V_5 -> V_19 , V_5 -> V_9 ) ;
F_15 ( V_16 ) ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_4 * V_25 ,
int V_1 , const T_2 * V_26 )
{
int V_27 ;
V_27 = F_18 ( V_24 , V_1 ) ;
if ( ! V_27 ) {
F_19 ( L_1 , V_1 ) ;
return - V_28 ;
}
V_25 -> V_29 |= F_20 ( V_26 + V_1 ) ;
F_21 ( V_27 , V_25 ) ;
F_22 ( V_27 , F_1 ) ;
return 0 ;
}
int T_3 F_23 ( struct V_23 * V_24 ,
struct V_23 * V_30 )
{
unsigned int V_31 = V_32 | V_33 | V_34 ;
struct V_4 * V_25 ;
struct V_15 * V_16 ;
struct V_35 * V_36 ;
const T_2 * V_26 ;
int V_37 ;
int V_38 = 0 , V_39 , V_1 ;
V_25 = F_24 ( sizeof( * V_25 ) , V_40 ) ;
if ( ! V_25 )
return - V_41 ;
V_25 -> V_9 = F_25 ( V_24 , 0 ) ;
if ( ! V_25 -> V_9 ) {
F_19 ( L_2 ) ;
V_38 = - V_41 ;
goto V_42;
}
if ( F_26 ( V_24 , L_3 , & V_25 -> V_20 ) )
V_25 -> V_20 = 0 ;
F_14 ( V_25 -> V_20 , V_25 -> V_9 + V_43 ) ;
V_37 = F_27 ( V_24 ) ;
if ( V_37 <= 0 ) {
F_19 ( L_4 ) ;
V_38 = - V_41 ;
goto V_44;
}
V_26 = F_28 ( V_24 , L_5 , & V_39 ) ;
if ( ! V_26 || ( V_39 != ( sizeof( * V_26 ) * V_37 ) ) ) {
F_19 ( L_6 ) ;
V_38 = - V_28 ;
goto V_44;
}
for ( V_1 = 0 ; V_1 < V_37 ; V_1 ++ ) {
V_38 = F_17 ( V_24 , V_25 , V_1 , V_26 ) ;
if ( V_38 )
goto V_44;
}
V_25 -> V_12 = F_29 ( V_24 , 32 ,
& V_45 , NULL ) ;
if ( ! V_25 -> V_12 ) {
V_38 = - V_41 ;
goto V_44;
}
V_38 = F_30 ( V_25 -> V_12 , 32 , 1 ,
V_24 -> V_46 , V_47 , V_31 , 0 ,
V_48 ) ;
if ( V_38 ) {
F_19 ( L_7 ) ;
goto V_49;
}
V_16 = F_31 ( V_25 -> V_12 , 0 ) ;
V_16 -> V_50 = 0xfffffff & ~ V_25 -> V_29 ;
V_16 -> V_51 = V_25 -> V_9 ;
V_16 -> V_17 = V_25 ;
V_36 = V_16 -> V_52 ;
V_36 -> V_53 . V_54 = V_43 ;
V_36 -> V_7 . V_55 = V_56 ;
V_36 -> V_7 . V_57 = V_58 ;
V_36 -> V_7 . V_59 = V_60 ;
V_36 -> V_7 . V_61 = F_11 ;
V_36 -> V_7 . V_62 = F_16 ;
if ( F_32 ( V_24 , L_8 ) ) {
V_25 -> V_21 = true ;
V_16 -> V_63 = 0xffffffff ;
V_16 -> V_63 &= ~ V_16 -> V_50 ;
V_36 -> V_7 . V_64 = V_65 ;
}
F_33 ( L_9 ,
V_25 -> V_9 , V_37 ) ;
return 0 ;
V_49:
F_34 ( V_25 -> V_12 ) ;
V_44:
F_35 ( V_25 -> V_9 ) ;
V_42:
F_36 ( V_25 ) ;
return V_38 ;
}
