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
{ 0 , NULL }
} ;
const struct V_20 * V_25 ;
for ( V_25 = V_21 ; V_25 -> V_26 ; V_25 ++ ) {
if ( V_19 -> V_27 & V_25 -> V_26 )
F_5 ( V_13 , V_25 -> V_28 ) ;
}
return F_6 ( V_13 , V_19 ) ;
}
static void F_7 ( struct V_17 * V_13 , struct V_29 * V_30 )
{
static const struct V_20 V_31 [] = {
{ V_32 , L_4 } ,
{ V_33 , L_5 } ,
{ V_34 , L_6 } ,
{ V_35 , L_7 } ,
{ V_36 , L_8 } ,
{ V_37 , L_9 } ,
{ 0 , NULL }
} ;
const struct V_20 * V_25 ;
for ( V_25 = V_31 ; V_25 -> V_26 ; V_25 ++ ) {
if ( V_30 -> V_38 & V_25 -> V_26 )
F_5 ( V_13 , V_25 -> V_28 ) ;
}
}
static inline void F_8 ( struct V_17 * V_13 , const char * V_39 )
{
F_9 ( V_13 , V_39 , L_10 ) ;
}
static void F_10 ( struct V_17 * V_13 , struct V_18 * V_19 )
{
F_8 ( V_13 , V_19 -> V_40 -> V_41 ) ;
if ( V_19 -> V_42 && V_19 -> V_42 [ 0 ] ) {
F_11 ( V_13 , '.' ) ;
F_8 ( V_13 , V_19 -> V_42 ) ;
}
}
static int F_12 ( struct V_17 * V_13 , struct V_29 * V_30 )
{
struct V_43 * V_44 = F_13 ( V_30 ) ;
int V_45 = 0 ;
struct V_46 V_47 = { . V_48 = V_30 -> V_49 , . V_30 = V_30 } ;
struct V_18 * V_19 = V_47 . V_48 -> V_50 ;
if ( V_19 -> V_51 -> V_52 ) {
V_45 = V_19 -> V_51 -> V_52 ( V_13 , V_47 . V_48 ) ;
if ( V_45 )
goto V_53;
} else {
F_8 ( V_13 , V_44 -> V_54 ? V_44 -> V_54 : L_11 ) ;
}
F_11 ( V_13 , ' ' ) ;
F_14 ( V_13 , & V_47 , L_10 ) ;
F_11 ( V_13 , ' ' ) ;
F_10 ( V_13 , V_19 ) ;
F_5 ( V_13 , F_15 ( V_30 ) ? L_12 : L_13 ) ;
V_45 = F_4 ( V_13 , V_19 ) ;
if ( V_45 )
goto V_53;
F_7 ( V_13 , V_30 ) ;
if ( V_19 -> V_51 -> V_55 )
V_45 = V_19 -> V_51 -> V_55 ( V_13 , V_47 . V_48 ) ;
F_5 ( V_13 , L_14 ) ;
V_53:
return V_45 ;
}
static int F_16 ( struct V_17 * V_13 , struct V_29 * V_30 )
{
struct V_3 * V_4 = V_3 ( V_13 ) ;
struct V_43 * V_44 = F_13 ( V_30 ) ;
struct V_18 * V_19 = V_30 -> V_56 ;
struct V_46 V_47 = { . V_48 = V_30 -> V_49 , . V_30 = V_30 } ;
struct V_46 V_57 = V_4 -> V_57 ;
int V_45 = 0 ;
F_17 ( V_13 , L_15 , V_44 -> V_58 , V_44 -> V_59 -> V_58 ,
F_18 ( V_19 -> V_60 ) , F_19 ( V_19 -> V_60 ) ) ;
if ( V_19 -> V_51 -> V_61 )
V_45 = V_19 -> V_51 -> V_61 ( V_13 , V_30 -> V_49 ) ;
else
F_20 ( V_13 , V_30 -> V_49 , L_10 ) ;
if ( V_45 )
goto V_53;
F_11 ( V_13 , ' ' ) ;
V_45 = F_21 ( V_13 , & V_47 , & V_57 , L_10 ) ;
if ( V_45 )
goto V_53;
F_5 ( V_13 , V_30 -> V_38 & V_62 ? L_12 : L_13 ) ;
F_7 ( V_13 , V_30 ) ;
if ( F_22 ( V_44 ) )
F_17 ( V_13 , L_16 , V_44 -> V_63 ) ;
if ( F_23 ( V_44 ) ) {
int V_64 = V_44 -> V_65 -> V_63 ;
int V_66 = F_24 ( V_44 , & V_4 -> V_57 ) ;
F_17 ( V_13 , L_17 , V_64 ) ;
if ( V_66 && V_66 != V_64 )
F_17 ( V_13 , L_18 , V_66 ) ;
}
if ( F_25 ( V_44 ) )
F_5 ( V_13 , L_19 ) ;
F_5 ( V_13 , L_20 ) ;
F_10 ( V_13 , V_19 ) ;
F_11 ( V_13 , ' ' ) ;
if ( V_19 -> V_51 -> V_52 )
V_45 = V_19 -> V_51 -> V_52 ( V_13 , V_30 -> V_49 ) ;
else
F_8 ( V_13 , V_44 -> V_54 ? V_44 -> V_54 : L_11 ) ;
if ( V_45 )
goto V_53;
F_5 ( V_13 , V_19 -> V_27 & V_67 ? L_12 : L_13 ) ;
V_45 = F_4 ( V_13 , V_19 ) ;
if ( V_45 )
goto V_53;
if ( V_19 -> V_51 -> V_55 )
V_45 = V_19 -> V_51 -> V_55 ( V_13 , V_30 -> V_49 ) ;
F_11 ( V_13 , '\n' ) ;
V_53:
return V_45 ;
}
static int F_26 ( struct V_17 * V_13 , struct V_29 * V_30 )
{
struct V_43 * V_44 = F_13 ( V_30 ) ;
struct V_46 V_47 = { . V_48 = V_30 -> V_49 , . V_30 = V_30 } ;
struct V_18 * V_19 = V_47 . V_48 -> V_50 ;
int V_45 = 0 ;
if ( V_19 -> V_51 -> V_52 ) {
F_5 ( V_13 , L_21 ) ;
V_45 = V_19 -> V_51 -> V_52 ( V_13 , V_47 . V_48 ) ;
} else {
if ( V_44 -> V_54 ) {
F_5 ( V_13 , L_21 ) ;
F_8 ( V_13 , V_44 -> V_54 ) ;
} else
F_5 ( V_13 , L_22 ) ;
}
F_5 ( V_13 , L_23 ) ;
F_14 ( V_13 , & V_47 , L_10 ) ;
F_11 ( V_13 , ' ' ) ;
F_5 ( V_13 , L_24 ) ;
F_10 ( V_13 , V_19 ) ;
if ( V_19 -> V_51 -> V_68 ) {
F_11 ( V_13 , ' ' ) ;
if ( ! V_45 )
V_45 = V_19 -> V_51 -> V_68 ( V_13 , V_47 . V_48 ) ;
}
F_11 ( V_13 , '\n' ) ;
return V_45 ;
}
static int F_27 ( struct V_69 * V_69 , struct V_1 * V_1 ,
int (* F_28)( struct V_17 * , struct V_29 * ) )
{
struct V_70 * V_71 = F_29 ( V_69 ) ;
struct V_72 * V_73 ;
struct V_6 * V_7 = NULL ;
struct V_46 V_57 ;
struct V_3 * V_4 ;
int V_74 = - V_75 ;
if ( ! V_71 )
goto V_45;
F_30 () ;
V_73 = F_31 ( V_71 ) ;
if ( ! V_73 ) {
F_32 () ;
F_33 ( V_71 ) ;
goto V_45;
}
V_7 = V_73 -> V_76 ;
if ( ! V_7 ) {
F_32 () ;
F_33 ( V_71 ) ;
goto V_45;
}
F_34 ( V_7 ) ;
F_32 () ;
F_35 ( V_71 ) ;
if ( ! V_71 -> V_77 ) {
F_36 ( V_71 ) ;
F_33 ( V_71 ) ;
V_74 = - V_78 ;
goto V_79;
}
F_37 ( V_71 -> V_77 , & V_57 ) ;
F_36 ( V_71 ) ;
F_33 ( V_71 ) ;
V_74 = - V_80 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_81 ) ;
if ( ! V_4 )
goto V_82;
V_1 -> V_5 = & V_4 -> V_13 ;
V_74 = F_39 ( V_1 , & V_83 ) ;
if ( V_74 )
goto V_84;
V_4 -> V_7 = V_7 ;
V_4 -> V_57 = V_57 ;
V_4 -> V_13 . V_14 = V_7 -> V_11 ;
V_4 -> F_28 = F_28 ;
return 0 ;
V_84:
F_40 ( V_4 ) ;
V_82:
F_41 ( & V_57 ) ;
V_79:
F_42 ( V_7 ) ;
V_45:
return V_74 ;
}
static int F_43 ( struct V_69 * V_69 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_3 ( V_1 -> V_5 ) ;
F_41 ( & V_4 -> V_57 ) ;
F_42 ( V_4 -> V_7 ) ;
return F_44 ( V_69 , V_1 ) ;
}
static int F_45 ( struct V_69 * V_69 , struct V_1 * V_1 )
{
return F_27 ( V_69 , V_1 , F_12 ) ;
}
static int F_46 ( struct V_69 * V_69 , struct V_1 * V_1 )
{
return F_27 ( V_69 , V_1 , F_16 ) ;
}
static int F_47 ( struct V_69 * V_69 , struct V_1 * V_1 )
{
return F_27 ( V_69 , V_1 , F_26 ) ;
}
