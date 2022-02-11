static int T_1
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 , & V_5 ) ;
}
static void
F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 ) ;
}
int
F_6 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_14 . V_15 ;
struct V_16 * V_17 = & V_10 -> V_14 . V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 , V_24 , V_25 ;
if ( V_8 . V_26 == V_27 )
return 0 ;
if ( V_7 -> V_28 == V_29 )
return 0 ;
F_7 ( V_7 , L_1 ) ;
F_8 ( V_7 ) ;
F_7 ( V_7 , L_2 ) ;
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_30 * V_31 ;
V_31 = V_30 ( V_22 -> V_32 ) ;
if ( ! V_31 || ! V_31 -> V_33 )
continue;
F_10 ( V_31 -> V_33 ) ;
}
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_34 * V_35 = V_34 ( V_22 ) ;
F_11 ( V_35 -> V_36 . V_33 ) ;
F_10 ( V_35 -> V_36 . V_33 ) ;
}
F_7 ( V_7 , L_3 ) ;
F_12 ( & V_10 -> V_37 . V_38 , V_39 ) ;
F_7 ( V_7 , L_4 ) ;
for ( V_24 = 0 ; V_24 < V_17 -> V_40 ; V_24 ++ ) {
V_20 = V_10 -> V_40 . V_41 [ V_24 ] ;
if ( V_20 && V_20 -> V_42 )
F_13 ( V_20 ) ;
}
V_17 -> V_43 ( V_7 , false ) ;
V_17 -> V_44 ( V_7 ) ;
V_17 -> V_45 ( V_7 ) ;
for ( V_25 = V_46 - 1 ; V_25 >= 0 ; V_25 -- ) {
if ( V_10 -> V_47 [ V_25 ] ) {
V_23 = V_10 -> V_47 [ V_25 ] -> F_14 ( V_7 , V_25 ) ;
if ( V_23 )
goto V_48;
}
}
V_23 = V_13 -> V_49 ( V_7 ) ;
if ( V_23 ) {
F_15 ( V_7 , L_5 , V_23 ) ;
goto V_48;
}
F_7 ( V_7 , L_6 ) ;
V_23 = F_16 ( V_7 ) ;
if ( V_23 ) {
F_15 ( V_7 , L_5 , V_23 ) ;
V_13 -> V_50 ( V_7 ) ;
goto V_48;
}
F_7 ( V_7 , L_7 ) ;
F_17 ( V_2 ) ;
if ( V_8 . V_26 == V_51 ) {
F_18 ( V_2 ) ;
F_19 ( V_2 , V_52 ) ;
}
F_20 () ;
F_21 ( V_7 , 1 ) ;
F_22 () ;
F_23 ( V_7 ) ;
return 0 ;
V_48:
F_7 ( V_7 , L_8 ) ;
for ( V_25 = V_25 + 1 ; V_25 < V_46 ; V_25 ++ ) {
if ( V_10 -> V_47 [ V_25 ] )
V_10 -> V_47 [ V_25 ] -> F_24 ( V_7 , V_25 ) ;
}
V_17 -> V_53 ( V_7 ) ;
V_17 -> V_43 ( V_7 , true ) ;
return V_23 ;
}
int
F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_54 * V_14 = & V_10 -> V_14 ;
struct V_21 * V_22 ;
int V_23 , V_24 ;
if ( V_7 -> V_28 == V_29 )
return 0 ;
F_8 ( V_7 ) ;
F_7 ( V_7 , L_9 ) ;
F_19 ( V_2 , V_55 ) ;
F_26 ( V_2 ) ;
if ( F_27 ( V_2 ) )
return - 1 ;
F_28 ( V_7 -> V_2 ) ;
if ( V_10 -> V_56 . type == V_57 )
F_29 ( V_7 ) ;
V_14 -> V_58 . V_59 ( V_7 ) ;
F_7 ( V_7 , L_10 ) ;
V_23 = F_30 ( V_7 ) ;
if ( V_23 )
return V_23 ;
F_31 ( V_7 ) ;
if ( V_10 -> V_56 . type == V_57 ) {
V_23 = F_32 ( V_7 ) ;
if ( V_23 ) {
F_15 ( V_7 , L_11 , V_23 ) ;
return V_23 ;
}
}
F_7 ( V_7 , L_12 ) ;
F_33 ( V_7 ) ;
F_7 ( V_7 , L_13 ) ;
V_14 -> V_15 . V_50 ( V_7 ) ;
V_14 -> V_60 . F_24 ( V_7 ) ;
V_14 -> V_61 . F_24 ( V_7 ) ;
V_14 -> V_32 . F_24 ( V_7 ) ;
for ( V_24 = 0 ; V_24 < V_46 ; V_24 ++ ) {
if ( V_10 -> V_47 [ V_24 ] )
V_10 -> V_47 [ V_24 ] -> F_24 ( V_7 , V_24 ) ;
}
V_14 -> V_18 . F_24 ( V_7 ) ;
F_34 ( V_7 ) ;
if ( V_62 ) {
struct V_19 * V_20 ;
int V_63 ;
for ( V_24 = 0 ; V_24 < V_10 -> V_14 . V_18 . V_40 ; V_24 ++ ) {
V_20 = V_10 -> V_40 . V_41 [ V_24 ] ;
if ( ! V_20 || ! V_20 -> V_42 )
continue;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
F_35 ( V_20 -> V_42 , V_24 , 0 ) ;
}
}
F_7 ( V_7 , L_14 ) ;
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_30 * V_31 ;
V_31 = V_30 ( V_22 -> V_32 ) ;
if ( ! V_31 || ! V_31 -> V_33 )
continue;
F_36 ( V_31 -> V_33 , V_65 ) ;
}
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_34 * V_35 = V_34 ( V_22 ) ;
V_23 = F_36 ( V_35 -> V_36 . V_33 , V_65 ) ;
if ( ! V_23 )
V_23 = F_37 ( V_35 -> V_36 . V_33 ) ;
if ( V_23 )
F_15 ( V_7 , L_15 ) ;
}
V_14 -> V_58 . F_24 ( V_7 ) ;
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_34 * V_35 = V_34 ( V_22 ) ;
T_3 V_66 = V_35 -> V_36 . V_33 -> V_67 . V_68 . V_69 << V_70 ;
V_35 -> V_36 . V_71 ( V_35 , V_66 ) ;
V_35 -> V_36 . V_72 ( V_35 , V_35 -> V_73 ,
V_35 -> V_74 ) ;
}
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_34 * V_35 = V_34 ( V_22 ) ;
V_35 -> V_75 . V_76 = 0 ;
}
F_20 () ;
F_21 ( V_7 , 0 ) ;
F_22 () ;
F_38 ( V_7 ) ;
F_39 ( V_7 ) ;
F_23 ( V_7 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
V_5 . V_77 = V_78 ;
if ( V_79 == - 1 ) {
#ifdef F_41
if ( F_42 () )
V_79 = 0 ;
else
#endif
V_79 = 1 ;
}
if ( ! V_79 )
return 0 ;
F_43 () ;
return F_44 ( & V_5 , & V_80 ) ;
}
static void T_5 F_45 ( void )
{
if ( ! V_79 )
return;
F_46 ( & V_5 , & V_80 ) ;
F_47 () ;
}
