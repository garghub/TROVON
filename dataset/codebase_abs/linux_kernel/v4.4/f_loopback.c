static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 ;
int V_11 ;
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_12 . V_13 = V_10 ;
V_10 = F_5 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_14 [ 0 ] . V_10 = V_10 ;
V_12 . V_15 = V_10 ;
V_9 -> V_16 = F_6 ( V_8 -> V_17 , & V_18 ) ;
if ( ! V_9 -> V_16 ) {
V_19:
ERROR ( V_8 , L_1 ,
V_3 -> V_20 , V_8 -> V_17 -> V_20 ) ;
return - V_21 ;
}
V_9 -> V_22 = F_6 ( V_8 -> V_17 , & V_23 ) ;
if ( ! V_9 -> V_22 )
goto V_19;
V_24 . V_25 =
V_18 . V_25 ;
V_26 . V_25 = V_23 . V_25 ;
V_27 . V_25 =
V_18 . V_25 ;
V_28 . V_25 = V_23 . V_25 ;
V_11 = F_7 ( V_3 , V_29 , V_30 ,
V_31 ) ;
if ( V_11 )
return V_11 ;
F_8 ( V_8 , L_2 ,
( F_9 ( V_6 -> V_8 -> V_17 ) ? L_3 :
( F_10 ( V_6 -> V_8 -> V_17 ) ? L_4 : L_5 ) ) ,
V_3 -> V_20 , V_9 -> V_16 -> V_20 , V_9 -> V_22 -> V_20 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
V_33 = F_2 ( V_3 -> V_34 , struct V_32 , V_35 ) ;
F_12 ( & V_33 -> V_36 ) ;
V_33 -> V_37 -- ;
F_13 ( & V_33 -> V_36 ) ;
F_14 ( V_3 ) ;
F_15 ( F_1 ( V_3 ) ) ;
}
static void F_16 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_1 * V_9 = V_39 -> V_42 ;
struct V_7 * V_8 = V_9 -> V_4 . V_43 -> V_8 ;
int V_44 = V_41 -> V_44 ;
switch ( V_44 ) {
case 0 :
if ( V_39 == V_9 -> V_22 ) {
struct V_40 * V_45 = V_41 -> V_46 ;
V_45 -> V_47 = ( V_41 -> V_48 < V_41 -> V_49 ) ;
V_45 -> V_49 = V_41 -> V_48 ;
V_39 = V_9 -> V_16 ;
V_41 = V_45 ;
} else {
V_41 = V_41 -> V_46 ;
V_39 = V_9 -> V_22 ;
}
V_44 = F_17 ( V_39 , V_41 , V_50 ) ;
if ( V_44 == 0 ) {
return;
} else {
ERROR ( V_8 , L_6 ,
V_39 -> V_20 , V_44 ) ;
goto V_51;
}
default:
ERROR ( V_8 , L_7 , V_39 -> V_20 ,
V_44 , V_41 -> V_48 , V_41 -> V_49 ) ;
case - V_52 :
case - V_53 :
case - V_54 :
V_51:
F_18 ( V_39 == V_9 -> V_16 ?
V_9 -> V_22 : V_9 -> V_16 ,
V_41 -> V_46 ) ;
F_19 ( V_39 , V_41 ) ;
return;
}
}
static void F_20 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_43 -> V_8 ;
F_21 ( V_8 , V_9 -> V_16 , V_9 -> V_22 , NULL , NULL ) ;
F_22 ( V_8 , L_8 , V_9 -> V_4 . V_20 ) ;
}
static inline struct V_40 * F_23 ( struct V_38 * V_39 , int V_55 )
{
struct V_1 * V_9 = V_39 -> V_42 ;
return F_24 ( V_39 , V_55 , V_9 -> V_56 ) ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_1 * V_9 )
{
struct V_40 * V_45 , * V_57 ;
int V_58 ;
int V_59 = 0 ;
for ( V_58 = 0 ; V_58 < V_9 -> V_60 && V_59 == 0 ; V_58 ++ ) {
V_59 = - V_61 ;
V_45 = F_26 ( V_9 -> V_16 , V_50 ) ;
if ( ! V_45 )
goto V_62;
V_57 = F_23 ( V_9 -> V_22 , 0 ) ;
if ( ! V_57 )
goto V_63;
V_45 -> V_64 = F_16 ;
V_57 -> V_64 = F_16 ;
V_45 -> V_65 = V_57 -> V_65 ;
V_45 -> V_46 = V_57 ;
V_57 -> V_46 = V_45 ;
V_59 = F_17 ( V_9 -> V_22 , V_57 , V_50 ) ;
if ( V_59 ) {
ERROR ( V_8 , L_9 ,
V_9 -> V_22 -> V_20 , V_59 ) ;
goto V_66;
}
}
return 0 ;
V_66:
F_19 ( V_9 -> V_22 , V_57 ) ;
V_63:
F_18 ( V_9 -> V_16 , V_45 ) ;
V_62:
return V_59 ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_1 * V_9 , struct V_38 * V_39 )
{
int V_59 ;
V_59 = F_28 ( V_8 -> V_17 , & ( V_9 -> V_4 ) , V_39 ) ;
if ( V_59 )
goto V_67;
V_59 = F_29 ( V_39 ) ;
if ( V_59 < 0 )
goto V_67;
V_39 -> V_42 = V_9 ;
V_59 = 0 ;
V_67:
return V_59 ;
}
static int
F_30 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_59 = 0 ;
V_59 = F_27 ( V_8 , V_9 , V_9 -> V_16 ) ;
if ( V_59 )
goto V_67;
V_59 = F_27 ( V_8 , V_9 , V_9 -> V_22 ) ;
if ( V_59 )
goto V_68;
V_59 = F_25 ( V_8 , V_9 ) ;
if ( V_59 )
goto V_69;
F_8 ( V_8 , L_10 , V_9 -> V_4 . V_20 ) ;
return 0 ;
V_69:
F_31 ( V_9 -> V_22 ) ;
V_68:
F_31 ( V_9 -> V_16 ) ;
V_67:
return V_59 ;
}
static int F_32 ( struct V_2 * V_3 ,
unsigned V_70 , unsigned V_71 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_43 -> V_8 ;
F_20 ( V_9 ) ;
return F_30 ( V_8 , V_9 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_20 ( V_9 ) ;
}
static struct V_2 * F_34 ( struct V_72 * V_34 )
{
struct V_1 * V_9 ;
struct V_32 * V_73 ;
V_9 = F_35 ( sizeof *V_9 , V_74 ) ;
if ( ! V_9 )
return F_36 ( - V_61 ) ;
V_73 = F_2 ( V_34 , struct V_32 , V_35 ) ;
F_12 ( & V_73 -> V_36 ) ;
V_73 -> V_37 ++ ;
F_13 ( & V_73 -> V_36 ) ;
V_9 -> V_56 = V_73 -> V_75 ;
V_9 -> V_60 = V_73 -> V_60 ;
if ( ! V_9 -> V_60 )
V_9 -> V_60 = 32 ;
V_9 -> V_4 . V_20 = L_11 ;
V_9 -> V_4 . V_76 = F_3 ;
V_9 -> V_4 . V_77 = F_32 ;
V_9 -> V_4 . V_78 = F_33 ;
V_9 -> V_4 . V_79 = V_80 ;
V_9 -> V_4 . V_81 = F_11 ;
return & V_9 -> V_4 ;
}
static inline struct V_32 * F_37 ( struct V_82 * V_83 )
{
return F_2 ( F_38 ( V_83 ) , struct V_32 ,
V_35 . V_84 ) ;
}
static void F_39 ( struct V_82 * V_83 )
{
struct V_32 * V_73 = F_37 ( V_83 ) ;
F_40 ( & V_73 -> V_35 ) ;
}
static T_1 F_41 ( struct V_82 * V_83 , char * V_85 )
{
struct V_32 * V_33 = F_37 ( V_83 ) ;
int V_59 ;
F_12 ( & V_33 -> V_36 ) ;
V_59 = sprintf ( V_85 , L_12 , V_33 -> V_60 ) ;
F_13 ( & V_33 -> V_36 ) ;
return V_59 ;
}
static T_1 F_42 ( struct V_82 * V_83 ,
const char * V_85 , T_2 V_55 )
{
struct V_32 * V_33 = F_37 ( V_83 ) ;
int V_11 ;
T_3 V_86 ;
F_12 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_37 ) {
V_11 = - V_87 ;
goto V_88;
}
V_11 = F_43 ( V_85 , 0 , & V_86 ) ;
if ( V_11 )
goto V_88;
V_33 -> V_60 = V_86 ;
V_11 = V_55 ;
V_88:
F_13 ( & V_33 -> V_36 ) ;
return V_11 ;
}
static T_1 F_44 ( struct V_82 * V_83 , char * V_85 )
{
struct V_32 * V_33 = F_37 ( V_83 ) ;
int V_59 ;
F_12 ( & V_33 -> V_36 ) ;
V_59 = sprintf ( V_85 , L_12 , V_33 -> V_75 ) ;
F_13 ( & V_33 -> V_36 ) ;
return V_59 ;
}
static T_1 F_45 ( struct V_82 * V_83 ,
const char * V_85 , T_2 V_55 )
{
struct V_32 * V_33 = F_37 ( V_83 ) ;
int V_11 ;
T_3 V_86 ;
F_12 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_37 ) {
V_11 = - V_87 ;
goto V_88;
}
V_11 = F_43 ( V_85 , 0 , & V_86 ) ;
if ( V_11 )
goto V_88;
V_33 -> V_75 = V_86 ;
V_11 = V_55 ;
V_88:
F_13 ( & V_33 -> V_36 ) ;
return V_11 ;
}
static void F_46 ( struct V_72 * V_34 )
{
struct V_32 * V_73 ;
V_73 = F_2 ( V_34 , struct V_32 , V_35 ) ;
F_15 ( V_73 ) ;
}
static struct V_72 * F_47 ( void )
{
struct V_32 * V_73 ;
V_73 = F_35 ( sizeof( * V_73 ) , V_74 ) ;
if ( ! V_73 )
return F_36 ( - V_61 ) ;
F_48 ( & V_73 -> V_36 ) ;
V_73 -> V_35 . V_89 = F_46 ;
V_73 -> V_75 = V_90 ;
V_73 -> V_60 = V_91 ;
F_49 ( & V_73 -> V_35 . V_84 , L_13 ,
& V_92 ) ;
return & V_73 -> V_35 ;
}
int T_4 F_50 ( void )
{
int V_11 ;
V_11 = F_51 ( & V_93 ) ;
if ( V_11 )
return V_11 ;
return V_11 ;
}
void T_5 F_52 ( void )
{
F_53 ( & V_93 ) ;
}
