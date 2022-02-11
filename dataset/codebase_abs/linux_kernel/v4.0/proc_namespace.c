static unsigned F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_1 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned V_8 = V_9 | V_10 ;
int V_11 ;
F_2 ( V_1 , & V_4 -> V_7 -> V_12 , V_2 ) ;
V_11 = F_3 ( V_7 -> V_11 ) ;
if ( V_4 -> V_13 . V_14 != V_11 ) {
V_4 -> V_13 . V_14 = V_11 ;
V_8 |= V_15 | V_16 ;
}
return V_8 ;
}
static int F_4 ( struct V_17 * V_13 , struct V_18 * V_19 )
{
static const struct V_20 V_21 [] = {
{ V_22 , L_1 } ,
{ V_23 , L_2 } ,
{ V_24 , L_3 } ,
{ V_25 , L_4 } ,
{ 0 , NULL }
} ;
const struct V_20 * V_26 ;
for ( V_26 = V_21 ; V_26 -> V_27 ; V_26 ++ ) {
if ( V_19 -> V_28 & V_26 -> V_27 )
F_5 ( V_13 , V_26 -> V_29 ) ;
}
return F_6 ( V_13 , V_19 ) ;
}
static void F_7 ( struct V_17 * V_13 , struct V_30 * V_31 )
{
static const struct V_20 V_32 [] = {
{ V_33 , L_5 } ,
{ V_34 , L_6 } ,
{ V_35 , L_7 } ,
{ V_36 , L_8 } ,
{ V_37 , L_9 } ,
{ V_38 , L_10 } ,
{ 0 , NULL }
} ;
const struct V_20 * V_26 ;
for ( V_26 = V_32 ; V_26 -> V_27 ; V_26 ++ ) {
if ( V_31 -> V_39 & V_26 -> V_27 )
F_5 ( V_13 , V_26 -> V_29 ) ;
}
}
static inline void F_8 ( struct V_17 * V_13 , const char * V_40 )
{
F_9 ( V_13 , V_40 , L_11 ) ;
}
static void F_10 ( struct V_17 * V_13 , struct V_18 * V_19 )
{
F_8 ( V_13 , V_19 -> V_41 -> V_42 ) ;
if ( V_19 -> V_43 && V_19 -> V_43 [ 0 ] ) {
F_11 ( V_13 , '.' ) ;
F_8 ( V_13 , V_19 -> V_43 ) ;
}
}
static int F_12 ( struct V_17 * V_13 , struct V_30 * V_31 )
{
struct V_3 * V_4 = V_3 ( V_13 ) ;
struct V_44 * V_45 = F_13 ( V_31 ) ;
int V_46 = 0 ;
struct V_47 V_48 = { . V_49 = V_31 -> V_50 , . V_31 = V_31 } ;
struct V_18 * V_19 = V_48 . V_49 -> V_51 ;
if ( V_19 -> V_52 -> V_53 ) {
V_46 = V_19 -> V_52 -> V_53 ( V_13 , V_48 . V_49 ) ;
if ( V_46 )
goto V_54;
} else {
F_8 ( V_13 , V_45 -> V_55 ? V_45 -> V_55 : L_12 ) ;
}
F_11 ( V_13 , ' ' ) ;
V_46 = F_14 ( V_13 , & V_48 , & V_4 -> V_56 , L_11 ) ;
if ( V_46 )
goto V_54;
F_11 ( V_13 , ' ' ) ;
F_10 ( V_13 , V_19 ) ;
F_5 ( V_13 , F_15 ( V_31 ) ? L_13 : L_14 ) ;
V_46 = F_4 ( V_13 , V_19 ) ;
if ( V_46 )
goto V_54;
F_7 ( V_13 , V_31 ) ;
if ( V_19 -> V_52 -> V_57 )
V_46 = V_19 -> V_52 -> V_57 ( V_13 , V_48 . V_49 ) ;
F_5 ( V_13 , L_15 ) ;
V_54:
return V_46 ;
}
static int F_16 ( struct V_17 * V_13 , struct V_30 * V_31 )
{
struct V_3 * V_4 = V_3 ( V_13 ) ;
struct V_44 * V_45 = F_13 ( V_31 ) ;
struct V_18 * V_19 = V_31 -> V_58 ;
struct V_47 V_48 = { . V_49 = V_31 -> V_50 , . V_31 = V_31 } ;
int V_46 = 0 ;
F_17 ( V_13 , L_16 , V_45 -> V_59 , V_45 -> V_60 -> V_59 ,
F_18 ( V_19 -> V_61 ) , F_19 ( V_19 -> V_61 ) ) ;
if ( V_19 -> V_52 -> V_62 )
V_46 = V_19 -> V_52 -> V_62 ( V_13 , V_31 -> V_50 ) ;
else
F_20 ( V_13 , V_31 -> V_50 , L_11 ) ;
if ( V_46 )
goto V_54;
F_11 ( V_13 , ' ' ) ;
V_46 = F_14 ( V_13 , & V_48 , & V_4 -> V_56 , L_11 ) ;
if ( V_46 )
goto V_54;
F_5 ( V_13 , V_31 -> V_39 & V_63 ? L_13 : L_14 ) ;
F_7 ( V_13 , V_31 ) ;
if ( F_21 ( V_45 ) )
F_17 ( V_13 , L_17 , V_45 -> V_64 ) ;
if ( F_22 ( V_45 ) ) {
int V_65 = V_45 -> V_66 -> V_64 ;
int V_67 = F_23 ( V_45 , & V_4 -> V_56 ) ;
F_17 ( V_13 , L_18 , V_65 ) ;
if ( V_67 && V_67 != V_65 )
F_17 ( V_13 , L_19 , V_67 ) ;
}
if ( F_24 ( V_45 ) )
F_5 ( V_13 , L_20 ) ;
F_5 ( V_13 , L_21 ) ;
F_10 ( V_13 , V_19 ) ;
F_11 ( V_13 , ' ' ) ;
if ( V_19 -> V_52 -> V_53 )
V_46 = V_19 -> V_52 -> V_53 ( V_13 , V_31 -> V_50 ) ;
else
F_8 ( V_13 , V_45 -> V_55 ? V_45 -> V_55 : L_12 ) ;
if ( V_46 )
goto V_54;
F_5 ( V_13 , V_19 -> V_28 & V_68 ? L_13 : L_14 ) ;
V_46 = F_4 ( V_13 , V_19 ) ;
if ( V_46 )
goto V_54;
if ( V_19 -> V_52 -> V_57 )
V_46 = V_19 -> V_52 -> V_57 ( V_13 , V_31 -> V_50 ) ;
F_11 ( V_13 , '\n' ) ;
V_54:
return V_46 ;
}
static int F_25 ( struct V_17 * V_13 , struct V_30 * V_31 )
{
struct V_3 * V_4 = V_3 ( V_13 ) ;
struct V_44 * V_45 = F_13 ( V_31 ) ;
struct V_47 V_48 = { . V_49 = V_31 -> V_50 , . V_31 = V_31 } ;
struct V_18 * V_19 = V_48 . V_49 -> V_51 ;
int V_46 = 0 ;
if ( V_19 -> V_52 -> V_53 ) {
F_5 ( V_13 , L_22 ) ;
V_46 = V_19 -> V_52 -> V_53 ( V_13 , V_48 . V_49 ) ;
} else {
if ( V_45 -> V_55 ) {
F_5 ( V_13 , L_22 ) ;
F_8 ( V_13 , V_45 -> V_55 ) ;
} else
F_5 ( V_13 , L_23 ) ;
}
F_5 ( V_13 , L_24 ) ;
V_46 = F_14 ( V_13 , & V_48 , & V_4 -> V_56 , L_11 ) ;
if ( V_46 )
goto V_54;
F_11 ( V_13 , ' ' ) ;
F_5 ( V_13 , L_25 ) ;
F_10 ( V_13 , V_19 ) ;
if ( V_19 -> V_52 -> V_69 ) {
F_11 ( V_13 , ' ' ) ;
if ( ! V_46 )
V_46 = V_19 -> V_52 -> V_69 ( V_13 , V_48 . V_49 ) ;
}
F_11 ( V_13 , '\n' ) ;
V_54:
return V_46 ;
}
static int F_26 ( struct V_70 * V_70 , struct V_1 * V_1 ,
int (* F_27)( struct V_17 * , struct V_30 * ) )
{
struct V_71 * V_72 = F_28 ( V_70 ) ;
struct V_73 * V_74 ;
struct V_6 * V_7 = NULL ;
struct V_47 V_56 ;
struct V_3 * V_4 ;
int V_75 = - V_76 ;
if ( ! V_72 )
goto V_46;
F_29 ( V_72 ) ;
V_74 = V_72 -> V_73 ;
if ( ! V_74 || ! V_74 -> V_77 ) {
F_30 ( V_72 ) ;
F_31 ( V_72 ) ;
goto V_46;
}
V_7 = V_74 -> V_77 ;
F_32 ( V_7 ) ;
if ( ! V_72 -> V_78 ) {
F_30 ( V_72 ) ;
F_31 ( V_72 ) ;
V_75 = - V_79 ;
goto V_80;
}
F_33 ( V_72 -> V_78 , & V_56 ) ;
F_30 ( V_72 ) ;
F_31 ( V_72 ) ;
V_75 = - V_81 ;
V_4 = F_34 ( sizeof( struct V_3 ) , V_82 ) ;
if ( ! V_4 )
goto V_83;
V_1 -> V_5 = & V_4 -> V_13 ;
V_75 = F_35 ( V_1 , & V_84 ) ;
if ( V_75 )
goto V_85;
V_4 -> V_7 = V_7 ;
V_4 -> V_56 = V_56 ;
V_4 -> V_13 . V_14 = V_7 -> V_11 ;
V_4 -> F_27 = F_27 ;
V_4 -> V_86 = ~ 0ULL ;
return 0 ;
V_85:
F_36 ( V_4 ) ;
V_83:
F_37 ( & V_56 ) ;
V_80:
F_38 ( V_7 ) ;
V_46:
return V_75 ;
}
static int F_39 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_3 ( V_1 -> V_5 ) ;
F_37 ( & V_4 -> V_56 ) ;
F_38 ( V_4 -> V_7 ) ;
return F_40 ( V_70 , V_1 ) ;
}
static int F_41 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
return F_26 ( V_70 , V_1 , F_12 ) ;
}
static int F_42 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
return F_26 ( V_70 , V_1 , F_16 ) ;
}
static int F_43 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
return F_26 ( V_70 , V_1 , F_25 ) ;
}
