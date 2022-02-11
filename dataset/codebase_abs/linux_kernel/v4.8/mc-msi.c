static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( T_1 ) ( V_4 -> V_5 . V_6 + ( V_2 -> V_7 * 10000 ) ) ;
}
static void F_2 ( T_2 * V_8 ,
struct V_3 * V_4 )
{
V_8 -> V_4 = V_4 ;
V_8 -> V_9 = F_1 ( F_3 ( V_4 -> V_2 ) ,
V_4 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
if ( F_5 ( ! V_13 ) )
return;
if ( V_13 -> V_14 == NULL )
V_13 -> V_14 = F_2 ;
}
static void F_6 ( struct V_1 * V_15 ,
struct V_16 * V_17 )
{
int error ;
struct V_1 * V_18 = V_17 -> V_19 ;
struct V_3 * V_3 = V_17 -> V_3 ;
struct V_20 V_21 ;
if ( V_3 -> V_22 . V_23 == 0x0 && V_3 -> V_22 . V_24 == 0x0 )
return;
if ( F_5 ( ! V_18 ) )
return;
V_21 . V_25 = ( ( V_26 ) V_3 -> V_22 . V_24 << 32 ) |
V_3 -> V_22 . V_23 ;
V_21 . V_27 = V_3 -> V_22 . V_28 ;
V_21 . V_29 = V_3 -> V_30 ;
if ( V_18 == V_15 ) {
error = F_7 ( V_15 -> V_31 ,
V_32 | V_33 ,
V_15 -> V_34 ,
V_17 -> V_35 ,
& V_21 ) ;
if ( error < 0 ) {
F_8 ( & V_18 -> V_2 ,
L_1 , error ) ;
}
} else {
error = F_9 ( V_15 -> V_31 ,
V_32 | V_33 ,
V_15 -> V_34 ,
V_18 -> V_36 . type ,
V_18 -> V_36 . V_37 ,
V_17 -> V_35 ,
& V_21 ) ;
if ( error < 0 ) {
F_8 ( & V_18 -> V_2 ,
L_2 , error ) ;
}
}
}
static void F_10 ( struct V_38 * V_38 ,
struct V_39 * V_22 )
{
struct V_3 * V_3 = F_11 ( V_38 ) ;
struct V_1 * V_15 = F_3 ( V_3 -> V_2 ) ;
struct V_40 * V_41 = F_12 ( V_15 ) ;
struct V_16 * V_17 =
& V_41 -> V_42 [ V_3 -> V_5 . V_6 ] ;
F_5 ( V_17 -> V_3 != V_3 ) ;
V_3 -> V_22 = * V_22 ;
F_6 ( V_15 , V_17 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_43 * V_44 = V_11 -> V_44 ;
if ( F_5 ( ( ! V_44 ) ) )
return;
if ( V_44 -> V_45 == NULL )
V_44 -> V_45 = F_10 ;
}
struct V_46 * F_14 ( struct V_47 * V_48 ,
struct V_10 * V_11 ,
struct V_46 * V_49 )
{
struct V_46 * V_50 ;
if ( V_11 -> V_51 & V_52 )
F_4 ( V_11 ) ;
if ( V_11 -> V_51 & V_53 )
F_13 ( V_11 ) ;
V_50 = F_15 ( V_48 , V_11 , V_49 ) ;
if ( V_50 )
V_50 -> V_54 = V_55 ;
return V_50 ;
}
int F_16 ( struct V_56 * V_57 ,
struct V_46 * * V_58 )
{
struct V_46 * V_59 ;
struct V_60 * V_61 = V_57 -> V_62 ;
V_59 = F_17 ( V_57 , V_61 ,
V_55 ) ;
if ( ! V_59 ) {
F_18 ( L_3 ,
V_61 -> V_63 ) ;
return - V_64 ;
}
* V_58 = V_59 ;
return 0 ;
}
static void F_19 ( struct V_56 * V_2 )
{
struct V_3 * V_4 , * V_65 ;
F_20 (desc, tmp, dev_to_msi_list(dev), list) {
F_21 ( & V_4 -> V_66 ) ;
F_22 ( V_4 ) ;
}
}
static int F_23 ( struct V_56 * V_2 , unsigned int V_67 )
{
unsigned int V_68 ;
int error ;
struct V_3 * V_3 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
V_3 = F_24 ( V_2 ) ;
if ( ! V_3 ) {
F_8 ( V_2 , L_4 ) ;
error = - V_69 ;
goto V_70;
}
V_3 -> V_5 . V_6 = V_68 ;
V_3 -> V_71 = 1 ;
F_25 ( & V_3 -> V_66 ) ;
F_26 ( & V_3 -> V_66 , F_27 ( V_2 ) ) ;
}
return 0 ;
V_70:
F_19 ( V_2 ) ;
return error ;
}
int F_28 ( struct V_56 * V_2 ,
unsigned int V_67 )
{
struct V_46 * V_59 ;
int error ;
if ( F_5 ( ! F_29 ( F_27 ( V_2 ) ) ) )
return - V_72 ;
error = F_23 ( V_2 , V_67 ) ;
if ( error < 0 )
return error ;
V_59 = F_30 ( V_2 ) ;
if ( F_5 ( ! V_59 ) ) {
error = - V_72 ;
goto V_70;
}
error = F_31 ( V_59 , V_2 , V_67 ) ;
if ( error ) {
F_8 ( V_2 , L_5 ) ;
goto V_70;
}
return 0 ;
V_70:
F_19 ( V_2 ) ;
return error ;
}
void F_32 ( struct V_56 * V_2 )
{
struct V_46 * V_59 ;
V_59 = F_30 ( V_2 ) ;
if ( F_5 ( ! V_59 ) )
return;
F_33 ( V_59 , V_2 ) ;
if ( F_5 ( F_29 ( F_27 ( V_2 ) ) ) )
return;
F_19 ( V_2 ) ;
}
