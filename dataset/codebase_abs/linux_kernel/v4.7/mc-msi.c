static void F_1 ( T_1 * V_1 ,
struct V_2 * V_3 )
{
V_1 -> V_3 = V_3 ;
V_1 -> V_4 = ( V_5 ) V_3 -> V_6 . V_7 ;
}
static void F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
if ( F_3 ( ! V_11 ) )
return;
if ( V_11 -> V_12 == NULL )
V_11 -> V_12 = F_1 ;
}
static void F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
int error ;
struct V_13 * V_17 = V_16 -> V_18 ;
struct V_2 * V_2 = V_16 -> V_2 ;
struct V_19 V_20 ;
if ( V_2 -> V_21 . V_22 == 0x0 && V_2 -> V_21 . V_23 == 0x0 )
return;
if ( F_3 ( ! V_17 ) )
return;
V_20 . V_24 = ( ( V_25 ) V_2 -> V_21 . V_23 << 32 ) |
V_2 -> V_21 . V_22 ;
V_20 . V_26 = V_2 -> V_21 . V_27 ;
V_20 . V_28 = V_2 -> V_29 ;
if ( V_17 == V_14 ) {
error = F_5 ( V_14 -> V_30 ,
V_31 | V_32 ,
V_14 -> V_33 ,
V_16 -> V_34 ,
& V_20 ) ;
if ( error < 0 ) {
F_6 ( & V_17 -> V_35 ,
L_1 , error ) ;
}
} else {
error = F_7 ( V_14 -> V_30 ,
V_31 | V_32 ,
V_14 -> V_33 ,
V_17 -> V_36 . type ,
V_17 -> V_36 . V_37 ,
V_16 -> V_34 ,
& V_20 ) ;
if ( error < 0 ) {
F_6 ( & V_17 -> V_35 ,
L_2 , error ) ;
}
}
}
static void F_8 ( struct V_38 * V_38 ,
struct V_39 * V_21 )
{
struct V_2 * V_2 = F_9 ( V_38 ) ;
struct V_13 * V_14 = F_10 ( V_2 -> V_35 ) ;
struct V_40 * V_41 = F_11 ( V_14 ) ;
struct V_15 * V_16 =
& V_41 -> V_42 [ V_2 -> V_6 . V_7 ] ;
F_3 ( V_16 -> V_2 != V_2 ) ;
V_2 -> V_21 = * V_21 ;
F_4 ( V_14 , V_16 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = V_9 -> V_44 ;
if ( F_3 ( ( ! V_44 ) ) )
return;
if ( V_44 -> V_45 == NULL )
V_44 -> V_45 = F_8 ;
}
struct V_46 * F_13 ( struct V_47 * V_48 ,
struct V_8 * V_9 ,
struct V_46 * V_49 )
{
struct V_46 * V_50 ;
if ( V_9 -> V_51 & V_52 )
F_2 ( V_9 ) ;
if ( V_9 -> V_51 & V_53 )
F_12 ( V_9 ) ;
V_50 = F_14 ( V_48 , V_9 , V_49 ) ;
if ( V_50 )
V_50 -> V_54 = V_55 ;
return V_50 ;
}
int F_15 ( struct V_56 * V_57 ,
struct V_46 * * V_58 )
{
struct V_46 * V_59 ;
struct V_60 * V_61 = V_57 -> V_62 ;
V_59 = F_16 ( V_57 , V_61 ,
V_55 ) ;
if ( ! V_59 ) {
F_17 ( L_3 ,
V_61 -> V_63 ) ;
return - V_64 ;
}
* V_58 = V_59 ;
return 0 ;
}
static void F_18 ( struct V_56 * V_35 )
{
struct V_2 * V_3 , * V_65 ;
F_19 (desc, tmp, dev_to_msi_list(dev), list) {
F_20 ( & V_3 -> V_66 ) ;
F_21 ( V_3 ) ;
}
}
static int F_22 ( struct V_56 * V_35 , unsigned int V_67 )
{
unsigned int V_68 ;
int error ;
struct V_2 * V_2 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
V_2 = F_23 ( V_35 ) ;
if ( ! V_2 ) {
F_6 ( V_35 , L_4 ) ;
error = - V_69 ;
goto V_70;
}
V_2 -> V_6 . V_7 = V_68 ;
V_2 -> V_71 = 1 ;
F_24 ( & V_2 -> V_66 ) ;
F_25 ( & V_2 -> V_66 , F_26 ( V_35 ) ) ;
}
return 0 ;
V_70:
F_18 ( V_35 ) ;
return error ;
}
int F_27 ( struct V_56 * V_35 ,
unsigned int V_67 )
{
struct V_46 * V_59 ;
int error ;
if ( F_3 ( ! F_28 ( F_26 ( V_35 ) ) ) )
return - V_72 ;
error = F_22 ( V_35 , V_67 ) ;
if ( error < 0 )
return error ;
V_59 = F_29 ( V_35 ) ;
if ( F_3 ( ! V_59 ) ) {
error = - V_72 ;
goto V_70;
}
error = F_30 ( V_59 , V_35 , V_67 ) ;
if ( error ) {
F_6 ( V_35 , L_5 ) ;
goto V_70;
}
return 0 ;
V_70:
F_18 ( V_35 ) ;
return error ;
}
void F_31 ( struct V_56 * V_35 )
{
struct V_46 * V_59 ;
V_59 = F_29 ( V_35 ) ;
if ( F_3 ( ! V_59 ) )
return;
F_32 ( V_59 , V_35 ) ;
if ( F_3 ( F_28 ( F_26 ( V_35 ) ) ) )
return;
F_18 ( V_35 ) ;
}
