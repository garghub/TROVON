static unsigned F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_1 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned V_8 = V_9 | V_10 ;
F_2 ( V_1 , & V_4 -> V_7 -> V_11 , V_2 ) ;
F_3 ( & V_12 ) ;
if ( V_4 -> V_13 . V_14 != V_7 -> V_15 ) {
V_4 -> V_13 . V_14 = V_7 -> V_15 ;
V_8 |= V_16 | V_17 ;
}
F_4 ( & V_12 ) ;
return V_8 ;
}
static int F_5 ( struct V_18 * V_13 , struct V_19 * V_20 )
{
static const struct V_21 V_22 [] = {
{ V_23 , L_1 } ,
{ V_24 , L_2 } ,
{ V_25 , L_3 } ,
{ 0 , NULL }
} ;
const struct V_21 * V_26 ;
for ( V_26 = V_22 ; V_26 -> V_27 ; V_26 ++ ) {
if ( V_20 -> V_28 & V_26 -> V_27 )
F_6 ( V_13 , V_26 -> V_29 ) ;
}
return F_7 ( V_13 , V_20 ) ;
}
static void F_8 ( struct V_18 * V_13 , struct V_30 * V_31 )
{
static const struct V_21 V_32 [] = {
{ V_33 , L_4 } ,
{ V_34 , L_5 } ,
{ V_35 , L_6 } ,
{ V_36 , L_7 } ,
{ V_37 , L_8 } ,
{ V_38 , L_9 } ,
{ 0 , NULL }
} ;
const struct V_21 * V_26 ;
for ( V_26 = V_32 ; V_26 -> V_27 ; V_26 ++ ) {
if ( V_31 -> V_39 & V_26 -> V_27 )
F_6 ( V_13 , V_26 -> V_29 ) ;
}
}
static inline void F_9 ( struct V_18 * V_13 , const char * V_40 )
{
F_10 ( V_13 , V_40 , L_10 ) ;
}
static void F_11 ( struct V_18 * V_13 , struct V_19 * V_20 )
{
F_9 ( V_13 , V_20 -> V_41 -> V_42 ) ;
if ( V_20 -> V_43 && V_20 -> V_43 [ 0 ] ) {
F_12 ( V_13 , '.' ) ;
F_9 ( V_13 , V_20 -> V_43 ) ;
}
}
static int F_13 ( struct V_18 * V_13 , struct V_30 * V_31 )
{
struct V_44 * V_45 = F_14 ( V_31 ) ;
int V_46 = 0 ;
struct V_47 V_48 = { . V_49 = V_31 -> V_50 , . V_31 = V_31 } ;
struct V_19 * V_20 = V_48 . V_49 -> V_51 ;
if ( V_20 -> V_52 -> V_53 ) {
V_46 = V_20 -> V_52 -> V_53 ( V_13 , V_48 . V_49 ) ;
if ( V_46 )
goto V_54;
} else {
F_9 ( V_13 , V_45 -> V_55 ? V_45 -> V_55 : L_11 ) ;
}
F_12 ( V_13 , ' ' ) ;
F_15 ( V_13 , & V_48 , L_10 ) ;
F_12 ( V_13 , ' ' ) ;
F_11 ( V_13 , V_20 ) ;
F_6 ( V_13 , F_16 ( V_31 ) ? L_12 : L_13 ) ;
V_46 = F_5 ( V_13 , V_20 ) ;
if ( V_46 )
goto V_54;
F_8 ( V_13 , V_31 ) ;
if ( V_20 -> V_52 -> V_56 )
V_46 = V_20 -> V_52 -> V_56 ( V_13 , V_48 . V_49 ) ;
F_6 ( V_13 , L_14 ) ;
V_54:
return V_46 ;
}
static int F_17 ( struct V_18 * V_13 , struct V_30 * V_31 )
{
struct V_3 * V_4 = V_3 ( V_13 ) ;
struct V_44 * V_45 = F_14 ( V_31 ) ;
struct V_19 * V_20 = V_31 -> V_57 ;
struct V_47 V_48 = { . V_49 = V_31 -> V_50 , . V_31 = V_31 } ;
struct V_47 V_58 = V_4 -> V_58 ;
int V_46 = 0 ;
F_18 ( V_13 , L_15 , V_45 -> V_59 , V_45 -> V_60 -> V_59 ,
F_19 ( V_20 -> V_61 ) , F_20 ( V_20 -> V_61 ) ) ;
if ( V_20 -> V_52 -> V_62 )
V_46 = V_20 -> V_52 -> V_62 ( V_13 , V_31 -> V_50 ) ;
else
F_21 ( V_13 , V_31 -> V_50 , L_10 ) ;
if ( V_46 )
goto V_54;
F_12 ( V_13 , ' ' ) ;
V_46 = F_22 ( V_13 , & V_48 , & V_58 , L_10 ) ;
if ( V_46 )
goto V_54;
F_6 ( V_13 , V_31 -> V_39 & V_63 ? L_12 : L_13 ) ;
F_8 ( V_13 , V_31 ) ;
if ( F_23 ( V_45 ) )
F_18 ( V_13 , L_16 , V_45 -> V_64 ) ;
if ( F_24 ( V_45 ) ) {
int V_65 = V_45 -> V_66 -> V_64 ;
int V_67 = F_25 ( V_45 , & V_4 -> V_58 ) ;
F_18 ( V_13 , L_17 , V_65 ) ;
if ( V_67 && V_67 != V_65 )
F_18 ( V_13 , L_18 , V_67 ) ;
}
if ( F_26 ( V_45 ) )
F_6 ( V_13 , L_19 ) ;
F_6 ( V_13 , L_20 ) ;
F_11 ( V_13 , V_20 ) ;
F_12 ( V_13 , ' ' ) ;
if ( V_20 -> V_52 -> V_53 )
V_46 = V_20 -> V_52 -> V_53 ( V_13 , V_31 -> V_50 ) ;
else
F_9 ( V_13 , V_45 -> V_55 ? V_45 -> V_55 : L_11 ) ;
if ( V_46 )
goto V_54;
F_6 ( V_13 , V_20 -> V_28 & V_68 ? L_12 : L_13 ) ;
V_46 = F_5 ( V_13 , V_20 ) ;
if ( V_46 )
goto V_54;
if ( V_20 -> V_52 -> V_56 )
V_46 = V_20 -> V_52 -> V_56 ( V_13 , V_31 -> V_50 ) ;
F_12 ( V_13 , '\n' ) ;
V_54:
return V_46 ;
}
static int F_27 ( struct V_18 * V_13 , struct V_30 * V_31 )
{
struct V_44 * V_45 = F_14 ( V_31 ) ;
struct V_47 V_48 = { . V_49 = V_31 -> V_50 , . V_31 = V_31 } ;
struct V_19 * V_20 = V_48 . V_49 -> V_51 ;
int V_46 = 0 ;
if ( V_20 -> V_52 -> V_53 ) {
F_6 ( V_13 , L_21 ) ;
V_46 = V_20 -> V_52 -> V_53 ( V_13 , V_48 . V_49 ) ;
} else {
if ( V_45 -> V_55 ) {
F_6 ( V_13 , L_21 ) ;
F_9 ( V_13 , V_45 -> V_55 ) ;
} else
F_6 ( V_13 , L_22 ) ;
}
F_6 ( V_13 , L_23 ) ;
F_15 ( V_13 , & V_48 , L_10 ) ;
F_12 ( V_13 , ' ' ) ;
F_6 ( V_13 , L_24 ) ;
F_11 ( V_13 , V_20 ) ;
if ( V_20 -> V_52 -> V_69 ) {
F_12 ( V_13 , ' ' ) ;
if ( ! V_46 )
V_46 = V_20 -> V_52 -> V_69 ( V_13 , V_48 . V_49 ) ;
}
F_12 ( V_13 , '\n' ) ;
return V_46 ;
}
static int F_28 ( struct V_70 * V_70 , struct V_1 * V_1 ,
int (* F_29)( struct V_18 * , struct V_30 * ) )
{
struct V_71 * V_72 = F_30 ( V_70 ) ;
struct V_73 * V_74 ;
struct V_6 * V_7 = NULL ;
struct V_47 V_58 ;
struct V_3 * V_4 ;
int V_75 = - V_76 ;
if ( ! V_72 )
goto V_46;
F_31 () ;
V_74 = F_32 ( V_72 ) ;
if ( ! V_74 ) {
F_33 () ;
F_34 ( V_72 ) ;
goto V_46;
}
V_7 = V_74 -> V_77 ;
if ( ! V_7 ) {
F_33 () ;
F_34 ( V_72 ) ;
goto V_46;
}
F_35 ( V_7 ) ;
F_33 () ;
F_36 ( V_72 ) ;
if ( ! V_72 -> V_78 ) {
F_37 ( V_72 ) ;
F_34 ( V_72 ) ;
V_75 = - V_79 ;
goto V_80;
}
F_38 ( V_72 -> V_78 , & V_58 ) ;
F_37 ( V_72 ) ;
F_34 ( V_72 ) ;
V_75 = - V_81 ;
V_4 = F_39 ( sizeof( struct V_3 ) , V_82 ) ;
if ( ! V_4 )
goto V_83;
V_1 -> V_5 = & V_4 -> V_13 ;
V_75 = F_40 ( V_1 , & V_84 ) ;
if ( V_75 )
goto V_85;
V_4 -> V_7 = V_7 ;
V_4 -> V_58 = V_58 ;
V_4 -> V_13 . V_14 = V_7 -> V_15 ;
V_4 -> F_29 = F_29 ;
return 0 ;
V_85:
F_41 ( V_4 ) ;
V_83:
F_42 ( & V_58 ) ;
V_80:
F_43 ( V_7 ) ;
V_46:
return V_75 ;
}
static int F_44 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_3 ( V_1 -> V_5 ) ;
F_42 ( & V_4 -> V_58 ) ;
F_43 ( V_4 -> V_7 ) ;
return F_45 ( V_70 , V_1 ) ;
}
static int F_46 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
return F_28 ( V_70 , V_1 , F_13 ) ;
}
static int F_47 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
return F_28 ( V_70 , V_1 , F_17 ) ;
}
static int F_48 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
return F_28 ( V_70 , V_1 , F_27 ) ;
}
