static unsigned F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
unsigned V_11 = V_12 | V_13 ;
int V_14 ;
F_2 ( V_1 , & V_7 -> V_10 -> V_15 , V_2 ) ;
V_14 = F_3 ( V_10 -> V_14 ) ;
if ( V_4 -> V_16 != V_14 ) {
V_4 -> V_16 = V_14 ;
V_11 |= V_17 | V_18 ;
}
return V_11 ;
}
static int F_4 ( struct V_3 * V_4 , struct V_19 * V_20 )
{
static const struct V_21 V_22 [] = {
{ V_23 , L_1 } ,
{ V_24 , L_2 } ,
{ V_25 , L_3 } ,
{ V_26 , L_4 } ,
{ 0 , NULL }
} ;
const struct V_21 * V_27 ;
for ( V_27 = V_22 ; V_27 -> V_28 ; V_27 ++ ) {
if ( V_20 -> V_29 & V_27 -> V_28 )
F_5 ( V_4 , V_27 -> V_30 ) ;
}
return F_6 ( V_4 , V_20 ) ;
}
static void F_7 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
static const struct V_21 V_33 [] = {
{ V_34 , L_5 } ,
{ V_35 , L_6 } ,
{ V_36 , L_7 } ,
{ V_37 , L_8 } ,
{ V_38 , L_9 } ,
{ V_39 , L_10 } ,
{ 0 , NULL }
} ;
const struct V_21 * V_27 ;
for ( V_27 = V_33 ; V_27 -> V_28 ; V_27 ++ ) {
if ( V_32 -> V_40 & V_27 -> V_28 )
F_5 ( V_4 , V_27 -> V_30 ) ;
}
}
static inline void F_8 ( struct V_3 * V_4 , const char * V_41 )
{
F_9 ( V_4 , V_41 , L_11 ) ;
}
static void F_10 ( struct V_3 * V_4 , struct V_19 * V_20 )
{
F_8 ( V_4 , V_20 -> V_42 -> V_43 ) ;
if ( V_20 -> V_44 && V_20 -> V_44 [ 0 ] ) {
F_11 ( V_4 , '.' ) ;
F_8 ( V_4 , V_20 -> V_44 ) ;
}
}
static int F_12 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_45 * V_46 = F_13 ( V_32 ) ;
struct V_47 V_48 = { . V_49 = V_32 -> V_50 , . V_32 = V_32 } ;
struct V_19 * V_20 = V_48 . V_49 -> V_51 ;
int V_52 ;
if ( V_20 -> V_53 -> V_54 ) {
V_52 = V_20 -> V_53 -> V_54 ( V_4 , V_48 . V_49 ) ;
if ( V_52 )
goto V_55;
} else {
F_8 ( V_4 , V_46 -> V_56 ? V_46 -> V_56 : L_12 ) ;
}
F_11 ( V_4 , ' ' ) ;
V_52 = F_14 ( V_4 , & V_48 , & V_7 -> V_57 , L_11 ) ;
if ( V_52 )
goto V_55;
F_11 ( V_4 , ' ' ) ;
F_10 ( V_4 , V_20 ) ;
F_5 ( V_4 , F_15 ( V_32 ) ? L_13 : L_14 ) ;
V_52 = F_4 ( V_4 , V_20 ) ;
if ( V_52 )
goto V_55;
F_7 ( V_4 , V_32 ) ;
if ( V_20 -> V_53 -> V_58 )
V_52 = V_20 -> V_53 -> V_58 ( V_4 , V_48 . V_49 ) ;
F_5 ( V_4 , L_15 ) ;
V_55:
return V_52 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_45 * V_46 = F_13 ( V_32 ) ;
struct V_19 * V_20 = V_32 -> V_59 ;
struct V_47 V_48 = { . V_49 = V_32 -> V_50 , . V_32 = V_32 } ;
int V_52 ;
F_17 ( V_4 , L_16 , V_46 -> V_60 , V_46 -> V_61 -> V_60 ,
F_18 ( V_20 -> V_62 ) , F_19 ( V_20 -> V_62 ) ) ;
if ( V_20 -> V_53 -> V_63 ) {
V_52 = V_20 -> V_53 -> V_63 ( V_4 , V_32 -> V_50 ) ;
if ( V_52 )
goto V_55;
} else {
F_20 ( V_4 , V_32 -> V_50 , L_11 ) ;
}
F_11 ( V_4 , ' ' ) ;
V_52 = F_14 ( V_4 , & V_48 , & V_7 -> V_57 , L_11 ) ;
if ( V_52 )
goto V_55;
F_5 ( V_4 , V_32 -> V_40 & V_64 ? L_13 : L_14 ) ;
F_7 ( V_4 , V_32 ) ;
if ( F_21 ( V_46 ) )
F_17 ( V_4 , L_17 , V_46 -> V_65 ) ;
if ( F_22 ( V_46 ) ) {
int V_66 = V_46 -> V_67 -> V_65 ;
int V_68 = F_23 ( V_46 , & V_7 -> V_57 ) ;
F_17 ( V_4 , L_18 , V_66 ) ;
if ( V_68 && V_68 != V_66 )
F_17 ( V_4 , L_19 , V_68 ) ;
}
if ( F_24 ( V_46 ) )
F_5 ( V_4 , L_20 ) ;
F_5 ( V_4 , L_21 ) ;
F_10 ( V_4 , V_20 ) ;
F_11 ( V_4 , ' ' ) ;
if ( V_20 -> V_53 -> V_54 ) {
V_52 = V_20 -> V_53 -> V_54 ( V_4 , V_32 -> V_50 ) ;
if ( V_52 )
goto V_55;
} else {
F_8 ( V_4 , V_46 -> V_56 ? V_46 -> V_56 : L_12 ) ;
}
F_5 ( V_4 , V_20 -> V_29 & V_69 ? L_13 : L_14 ) ;
V_52 = F_4 ( V_4 , V_20 ) ;
if ( V_52 )
goto V_55;
if ( V_20 -> V_53 -> V_58 )
V_52 = V_20 -> V_53 -> V_58 ( V_4 , V_32 -> V_50 ) ;
F_11 ( V_4 , '\n' ) ;
V_55:
return V_52 ;
}
static int F_25 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_45 * V_46 = F_13 ( V_32 ) ;
struct V_47 V_48 = { . V_49 = V_32 -> V_50 , . V_32 = V_32 } ;
struct V_19 * V_20 = V_48 . V_49 -> V_51 ;
int V_52 ;
if ( V_20 -> V_53 -> V_54 ) {
F_5 ( V_4 , L_22 ) ;
V_52 = V_20 -> V_53 -> V_54 ( V_4 , V_48 . V_49 ) ;
} else {
if ( V_46 -> V_56 ) {
F_5 ( V_4 , L_22 ) ;
F_8 ( V_4 , V_46 -> V_56 ) ;
} else
F_5 ( V_4 , L_23 ) ;
}
F_5 ( V_4 , L_24 ) ;
V_52 = F_14 ( V_4 , & V_48 , & V_7 -> V_57 , L_11 ) ;
if ( V_52 )
goto V_55;
F_11 ( V_4 , ' ' ) ;
F_5 ( V_4 , L_25 ) ;
F_10 ( V_4 , V_20 ) ;
if ( V_20 -> V_53 -> V_70 ) {
F_11 ( V_4 , ' ' ) ;
V_52 = V_20 -> V_53 -> V_70 ( V_4 , V_48 . V_49 ) ;
}
F_11 ( V_4 , '\n' ) ;
V_55:
return V_52 ;
}
static int F_26 ( struct V_71 * V_71 , struct V_1 * V_1 ,
int (* F_27)( struct V_3 * , struct V_31 * ) )
{
struct V_72 * V_73 = F_28 ( V_71 ) ;
struct V_74 * V_75 ;
struct V_9 * V_10 = NULL ;
struct V_47 V_57 ;
struct V_6 * V_7 ;
struct V_3 * V_4 ;
int V_76 = - V_77 ;
if ( ! V_73 )
goto V_52;
F_29 ( V_73 ) ;
V_75 = V_73 -> V_74 ;
if ( ! V_75 || ! V_75 -> V_78 ) {
F_30 ( V_73 ) ;
F_31 ( V_73 ) ;
goto V_52;
}
V_10 = V_75 -> V_78 ;
F_32 ( V_10 ) ;
if ( ! V_73 -> V_79 ) {
F_30 ( V_73 ) ;
F_31 ( V_73 ) ;
V_76 = - V_80 ;
goto V_81;
}
F_33 ( V_73 -> V_79 , & V_57 ) ;
F_30 ( V_73 ) ;
F_31 ( V_73 ) ;
V_76 = F_34 ( V_1 , & V_82 , sizeof( struct V_6 ) ) ;
if ( V_76 )
goto V_83;
V_4 = V_1 -> V_5 ;
V_4 -> V_16 = V_10 -> V_14 ;
V_7 = V_4 -> V_8 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_57 = V_57 ;
V_7 -> F_27 = F_27 ;
V_7 -> V_84 = ~ 0ULL ;
return 0 ;
V_83:
F_35 ( & V_57 ) ;
V_81:
F_36 ( V_10 ) ;
V_52:
return V_76 ;
}
static int F_37 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_35 ( & V_7 -> V_57 ) ;
F_36 ( V_7 -> V_10 ) ;
return F_38 ( V_71 , V_1 ) ;
}
static int F_39 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
return F_26 ( V_71 , V_1 , F_12 ) ;
}
static int F_40 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
return F_26 ( V_71 , V_1 , F_16 ) ;
}
static int F_41 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
return F_26 ( V_71 , V_1 , F_25 ) ;
}
