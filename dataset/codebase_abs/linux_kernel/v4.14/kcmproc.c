static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = F_3 ( V_4 , V_7 ) ;
return F_4 ( & V_6 -> V_8 ,
struct V_1 , V_9 ) ;
}
static struct V_1 * F_5 ( struct V_1 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
return F_6 ( & V_6 -> V_8 , & V_10 -> V_9 ,
struct V_1 , V_9 ) ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = F_3 ( V_4 , V_7 ) ;
struct V_1 * V_12 ;
F_8 (m, &knet->mux_list, kcm_mux_list) {
if ( ! V_11 )
return V_12 ;
-- V_11 ;
}
return NULL ;
}
static void * F_9 ( struct V_2 * V_3 , void * V_13 , T_1 * V_11 )
{
void * V_14 ;
if ( V_13 == V_15 )
V_14 = F_1 ( V_3 ) ;
else
V_14 = F_5 ( V_13 ) ;
++ * V_11 ;
return V_14 ;
}
static void * F_10 ( struct V_2 * V_3 , T_1 * V_11 )
__acquires( T_2 )
{
F_11 () ;
if ( ! * V_11 )
return V_15 ;
else
return F_7 ( V_3 , * V_11 - 1 ) ;
}
static void F_12 ( struct V_2 * V_3 , void * V_13 )
__releases( T_2 )
{
F_13 () ;
}
static int F_14 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_18 * V_19 = F_15 ( V_16 ) ;
return F_16 ( V_16 , V_17 , & V_19 -> V_20 ,
sizeof( struct V_21 ) ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = F_3 ( V_4 , V_7 ) ;
F_18 ( V_3 ,
L_1 ,
V_6 -> V_22 ) ;
F_18 ( V_3 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ) ;
F_19 ( V_3 , L_13 ) ;
}
static void F_20 ( struct V_23 * V_24 , struct V_2 * V_3 ,
int V_25 , int * V_26 )
{
F_18 ( V_3 ,
L_14 ,
V_24 -> V_27 ,
V_24 -> V_28 . V_29 ,
V_24 -> V_28 . V_30 ,
V_24 -> V_28 . V_31 ,
V_24 -> V_28 . V_32 ,
V_24 -> V_33 . V_34 . V_35 ,
F_21 ( & V_24 -> V_33 ) ,
V_24 -> V_33 . V_36 . V_35 ,
L_15 ) ;
if ( V_24 -> V_37 )
F_18 ( V_3 , L_16 , V_24 -> V_37 -> V_27 ) ;
if ( V_24 -> V_38 )
F_19 ( V_3 , L_17 ) ;
if ( V_24 -> V_39 )
F_19 ( V_3 , L_18 ) ;
if ( V_24 -> V_40 )
F_19 ( V_3 , L_19 ) ;
F_19 ( V_3 , L_13 ) ;
}
static void F_22 ( struct V_41 * V_42 , struct V_2 * V_3 ,
int V_25 , int * V_26 )
{
F_18 ( V_3 ,
L_20 ,
V_42 -> V_27 ,
V_42 -> V_43 . V_28 . V_44 ,
V_42 -> V_43 . V_28 . V_45 ,
V_42 -> V_28 . V_31 ,
V_42 -> V_28 . V_32 ,
V_42 -> V_33 -> V_34 . V_35 ,
F_23 ( & V_42 -> V_33 -> V_46 ) ,
V_42 -> V_33 -> V_36 . V_35 ,
F_24 ( & V_42 -> V_33 -> V_47 ) ) ;
if ( V_42 -> V_48 )
F_19 ( V_3 , L_21 ) ;
if ( V_42 -> V_49 )
F_19 ( V_3 , L_22 ) ;
if ( V_42 -> V_43 . V_50 )
F_19 ( V_3 , L_23 ) ;
if ( V_42 -> V_51 )
F_18 ( V_3 , L_24 , V_42 -> V_51 -> V_27 ) ;
if ( ! V_42 -> V_43 . V_52 && ! V_42 -> V_53 ) {
if ( V_42 -> V_33 -> V_34 . V_35 ) {
if ( V_42 -> V_43 . V_54 )
F_18 ( V_3 , L_25 ,
V_42 -> V_43 . V_54 ) ;
else
F_18 ( V_3 , L_19 ) ;
}
} else {
if ( V_42 -> V_43 . V_52 )
F_19 ( V_3 , L_26 ) ;
if ( V_42 -> V_53 )
F_19 ( V_3 , L_27 ) ;
}
F_19 ( V_3 , L_13 ) ;
}
static void
F_25 ( struct V_1 * V_10 , T_1 V_55 , struct V_2 * V_3 )
{
int V_25 , V_26 ;
struct V_23 * V_24 ;
struct V_41 * V_42 ;
F_18 ( V_3 ,
L_28 ,
L_29 , L_30 ,
V_10 -> V_28 . V_29 ,
V_10 -> V_28 . V_30 ,
V_10 -> V_28 . V_31 ,
V_10 -> V_28 . V_32 ,
L_15 , L_15 , L_15 , L_15 ) ;
F_18 ( V_3 , L_31 ,
V_10 -> V_56 , V_10 -> V_57 ) ;
V_25 = 0 ;
F_26 ( & V_10 -> V_58 ) ;
F_27 (kcm, &mux->kcm_socks, kcm_sock_list) {
F_20 ( V_24 , V_3 , V_25 , & V_26 ) ;
V_25 ++ ;
}
V_25 = 0 ;
F_27 (psock, &mux->psocks, psock_list) {
F_22 ( V_42 , V_3 , V_25 , & V_26 ) ;
V_25 ++ ;
}
F_28 ( & V_10 -> V_58 ) ;
}
static int F_29 ( struct V_2 * V_3 , void * V_13 )
{
struct V_21 * V_59 ;
V_59 = V_3 -> V_60 ;
if ( V_13 == V_15 ) {
V_59 -> V_55 = 0 ;
F_17 ( V_3 ) ;
} else {
F_25 ( V_13 , V_59 -> V_55 , V_3 ) ;
V_59 -> V_55 ++ ;
}
return 0 ;
}
static int F_30 ( struct V_4 * V_4 , struct V_18 * V_19 )
{
struct V_61 * V_14 ;
int V_62 = 0 ;
V_14 = F_31 ( V_19 -> V_63 , V_64 , V_4 -> V_65 ,
V_19 -> V_66 , V_19 ) ;
if ( ! V_14 )
V_62 = - V_67 ;
return V_62 ;
}
static void F_32 ( struct V_4 * V_4 ,
struct V_18 * V_19 )
{
F_33 ( V_19 -> V_63 , V_4 -> V_65 ) ;
}
static int F_34 ( struct V_2 * V_3 , void * V_13 )
{
struct V_68 V_69 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
struct V_1 * V_10 ;
struct V_41 * V_42 ;
struct V_4 * V_4 = V_3 -> V_60 ;
struct V_5 * V_6 = F_3 ( V_4 , V_7 ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_35 ( & V_6 -> V_74 ) ;
F_36 ( & V_6 -> F_36 , & V_71 ) ;
F_37 ( & V_6 -> F_37 ,
& V_69 ) ;
F_38 ( & V_6 -> F_38 ,
& V_73 ) ;
F_8 (mux, &knet->mux_list, kcm_mux_list) {
F_26 ( & V_10 -> V_58 ) ;
F_36 ( & V_10 -> V_28 , & V_71 ) ;
F_37 ( & V_10 -> F_37 ,
& V_69 ) ;
F_38 ( & V_10 -> F_38 ,
& V_73 ) ;
F_27 (psock, &mux->psocks, psock_list) {
F_37 ( & V_42 -> V_28 , & V_69 ) ;
F_39 ( & V_42 -> V_43 , & V_73 ) ;
}
F_28 ( & V_10 -> V_58 ) ;
}
F_40 ( & V_6 -> V_74 ) ;
F_18 ( V_3 ,
L_32 ,
L_33 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ) ;
F_18 ( V_3 ,
L_39 ,
L_30 ,
V_71 . V_29 ,
V_71 . V_30 ,
V_71 . V_31 ,
V_71 . V_32 ,
V_71 . V_75 ,
V_71 . V_76 ,
V_71 . V_77 ,
V_71 . V_78 ,
V_71 . V_79 ) ;
F_18 ( V_3 ,
L_40 ,
L_41 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ) ;
F_18 ( V_3 ,
L_53 ,
L_30 ,
V_73 . V_44 ,
V_73 . V_45 ,
V_69 . V_31 ,
V_69 . V_32 ,
V_69 . V_80 ,
V_69 . V_81 ,
V_73 . V_82 ,
V_73 . V_83 ,
V_73 . V_84 ,
V_73 . V_85 ,
V_73 . V_86 ,
V_73 . V_87 ,
V_73 . V_88 ,
V_73 . V_89 ,
V_69 . V_90 ) ;
return 0 ;
}
static int F_41 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
return F_42 ( V_16 , V_17 , F_34 ) ;
}
static int F_43 ( struct V_4 * V_4 )
{
int V_91 ;
if ( ! F_44 ( L_54 , V_64 , V_4 -> V_65 ,
& V_92 ) ) {
V_91 = - V_67 ;
goto V_93;
}
V_91 = F_30 ( V_4 , & V_18 ) ;
if ( V_91 )
goto V_94;
return 0 ;
V_94:
F_33 ( L_54 , V_4 -> V_65 ) ;
V_93:
return V_91 ;
}
static void F_45 ( struct V_4 * V_4 )
{
F_32 ( V_4 , & V_18 ) ;
F_33 ( L_54 , V_4 -> V_65 ) ;
}
int T_3 F_46 ( void )
{
return F_47 ( & V_95 ) ;
}
void T_4 F_48 ( void )
{
F_49 ( & V_95 ) ;
}
