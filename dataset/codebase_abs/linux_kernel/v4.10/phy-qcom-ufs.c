int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
int V_4 ,
struct V_2 * V_5 ,
int V_6 , bool V_7 )
{
int V_8 ;
int V_9 = 0 ;
if ( ! V_3 ) {
F_2 ( V_1 -> V_10 , L_1 , V_11 ) ;
V_9 = V_12 ;
goto V_13;
}
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ )
F_3 ( V_3 [ V_8 ] . V_14 ,
V_1 -> V_15 + V_3 [ V_8 ] . V_16 ) ;
if ( V_7 ) {
if ( ! V_5 ) {
F_2 ( V_1 -> V_10 , L_2 ,
V_11 ) ;
V_9 = V_12 ;
goto V_13;
}
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
F_3 ( V_5 [ V_8 ] . V_14 ,
V_1 -> V_15 + V_5 [ V_8 ] . V_16 ) ;
}
F_4 () ;
V_13:
return V_9 ;
}
struct V_1 * F_5 ( struct V_17 * V_18 )
{
return (struct V_1 * ) F_6 ( V_18 ) ;
}
static
int F_7 ( struct V_19 * V_20 ,
struct V_1 * V_21 )
{
struct V_22 * V_10 = & V_20 -> V_10 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
V_24 = F_8 ( V_20 , V_26 , L_3 ) ;
V_21 -> V_15 = F_9 ( V_10 , V_24 ) ;
if ( F_10 ( ( void const * ) V_21 -> V_15 ) ) {
V_25 = F_11 ( ( void const * ) V_21 -> V_15 ) ;
V_21 -> V_15 = NULL ;
F_2 ( V_10 , L_4 ,
V_11 , V_25 ) ;
return V_25 ;
}
V_24 = F_8 ( V_20 , V_26 ,
L_5 ) ;
V_21 -> V_27 = F_9 ( V_10 , V_24 ) ;
if ( F_10 ( ( void const * ) V_21 -> V_27 ) )
V_21 -> V_27 = NULL ;
return 0 ;
}
struct V_17 * F_12 ( struct V_19 * V_20 ,
struct V_1 * V_28 ,
const struct V_29 * V_30 ,
struct V_31 * V_32 )
{
int V_25 ;
struct V_22 * V_10 = & V_20 -> V_10 ;
struct V_17 * V_18 = NULL ;
struct V_33 * V_33 ;
V_25 = F_7 ( V_20 , V_28 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_6 , V_11 , V_25 ) ;
goto V_13;
}
V_33 = F_13 ( V_10 , V_34 ) ;
if ( F_10 ( V_33 ) ) {
V_25 = F_11 ( V_33 ) ;
F_2 ( V_10 , L_7 , V_11 , V_25 ) ;
goto V_13;
}
V_18 = F_14 ( V_10 , NULL , V_30 ) ;
if ( F_10 ( V_18 ) ) {
V_25 = F_11 ( V_18 ) ;
F_2 ( V_10 , L_8 , V_11 , V_25 ) ;
V_18 = NULL ;
goto V_13;
}
V_28 -> V_32 = V_32 ;
V_28 -> V_10 = V_10 ;
V_13:
return V_18 ;
}
static int F_15 ( struct V_22 * V_10 ,
const char * V_35 , struct V_36 * * V_37 , bool V_38 )
{
struct V_36 * V_36 ;
int V_25 = 0 ;
V_36 = F_16 ( V_10 , V_35 ) ;
if ( F_10 ( V_36 ) ) {
V_25 = F_11 ( V_36 ) ;
if ( V_38 )
F_2 ( V_10 , L_9 , V_35 , V_25 ) ;
} else {
* V_37 = V_36 ;
}
return V_25 ;
}
static int F_17 ( struct V_22 * V_10 ,
const char * V_35 , struct V_36 * * V_37 )
{
return F_15 ( V_10 , V_35 , V_37 , true ) ;
}
int F_18 ( struct V_1 * V_21 )
{
int V_25 ;
if ( F_19 ( V_21 -> V_10 -> V_39 ,
L_10 ) )
goto V_40;
V_25 = F_17 ( V_21 -> V_10 , L_11 ,
& V_21 -> V_41 ) ;
if ( V_25 )
goto V_13;
V_25 = F_17 ( V_21 -> V_10 , L_12 ,
& V_21 -> V_42 ) ;
if ( V_25 )
goto V_13;
V_25 = F_17 ( V_21 -> V_10 , L_13 ,
& V_21 -> V_43 ) ;
if ( V_25 )
goto V_13;
V_40:
F_15 ( V_21 -> V_10 , L_14 ,
& V_21 -> V_44 , false ) ;
V_25 = F_17 ( V_21 -> V_10 , L_15 ,
& V_21 -> V_45 ) ;
V_13:
return V_25 ;
}
static int F_20 ( struct V_22 * V_10 ,
struct V_46 * V_47 , const char * V_35 , bool V_48 )
{
int V_25 = 0 ;
char V_49 [ V_50 ] ;
V_47 -> V_35 = F_21 ( V_10 , V_35 , V_51 ) ;
if ( ! V_47 -> V_35 ) {
V_25 = - V_52 ;
goto V_13;
}
V_47 -> V_53 = F_22 ( V_10 , V_35 ) ;
if ( F_10 ( V_47 -> V_53 ) ) {
V_25 = F_11 ( V_47 -> V_53 ) ;
V_47 -> V_53 = NULL ;
if ( ! V_48 )
F_2 ( V_10 , L_16 , V_35 , V_25 ) ;
goto V_13;
}
if ( V_10 -> V_39 ) {
snprintf ( V_49 , V_50 , L_17 , V_35 ) ;
V_25 = F_23 ( V_10 -> V_39 ,
V_49 , & V_47 -> V_54 ) ;
if ( V_25 && V_25 != - V_12 ) {
F_2 ( V_10 , L_18 ,
V_11 , V_49 ) ;
goto V_13;
} else if ( V_25 == - V_12 || ! V_47 -> V_54 ) {
if ( F_24 ( V_47 -> V_53 ) > 0 ) {
F_2 ( V_10 , L_19 ,
V_11 , V_49 ) ;
goto V_13;
}
V_25 = 0 ;
}
snprintf ( V_49 , V_50 , L_20 , V_35 ) ;
V_47 -> V_55 = F_25 ( V_10 -> V_39 ,
V_49 ) ;
}
if ( ! strcmp ( V_35 , L_21 ) ) {
V_47 -> V_56 = V_57 ;
V_47 -> V_58 = V_59 ;
} else if ( ! strcmp ( V_35 , L_22 ) ) {
V_47 -> V_56 = V_60 ;
V_47 -> V_58 = V_61 ;
} else if ( ! strcmp ( V_35 , L_23 ) ) {
V_47 -> V_56 = V_62 ;
V_47 -> V_58 = V_63 ;
}
V_13:
if ( V_25 )
F_26 ( V_47 -> V_35 ) ;
return V_25 ;
}
static int F_27 ( struct V_22 * V_10 ,
struct V_46 * V_47 , const char * V_35 )
{
return F_20 ( V_10 , V_47 , V_35 , false ) ;
}
int F_28 ( struct V_1 * V_21 )
{
int V_25 ;
V_25 = F_27 ( V_21 -> V_10 , & V_21 -> V_64 ,
L_21 ) ;
if ( V_25 )
goto V_13;
V_25 = F_27 ( V_21 -> V_10 , & V_21 -> V_65 ,
L_22 ) ;
if ( V_25 )
goto V_13;
F_20 ( V_21 -> V_10 , & V_21 -> V_66 ,
L_23 , true ) ;
V_13:
return V_25 ;
}
static int F_29 ( struct V_22 * V_10 ,
struct V_46 * V_47 , bool V_67 )
{
int V_9 = 0 ;
struct V_68 * V_53 = V_47 -> V_53 ;
const char * V_35 = V_47 -> V_35 ;
int V_58 ;
int V_69 ;
if ( F_24 ( V_53 ) > 0 ) {
V_58 = V_67 ? V_47 -> V_58 : 0 ;
V_9 = F_30 ( V_53 , V_58 , V_47 -> V_56 ) ;
if ( V_9 ) {
F_2 ( V_10 , L_24 ,
V_11 , V_35 , V_9 ) ;
goto V_13;
}
V_69 = V_67 ? V_47 -> V_54 : 0 ;
V_9 = F_31 ( V_53 , V_69 ) ;
if ( V_9 >= 0 ) {
V_9 = 0 ;
} else {
F_2 ( V_10 , L_25 ,
V_11 , V_35 , V_69 , V_9 ) ;
goto V_13;
}
}
V_13:
return V_9 ;
}
static int F_32 ( struct V_22 * V_10 ,
struct V_46 * V_47 )
{
int V_9 = 0 ;
if ( ! V_47 || V_47 -> V_70 )
goto V_13;
V_9 = F_29 ( V_10 , V_47 , true ) ;
if ( V_9 ) {
F_2 ( V_10 , L_26 ,
V_11 , V_9 ) ;
goto V_13;
}
V_9 = F_33 ( V_47 -> V_53 ) ;
if ( V_9 ) {
F_2 ( V_10 , L_27 ,
V_11 , V_9 ) ;
goto V_13;
}
V_47 -> V_70 = true ;
V_13:
return V_9 ;
}
static int F_34 ( struct V_1 * V_17 )
{
int V_9 = 0 ;
if ( V_17 -> V_71 )
goto V_13;
V_9 = F_35 ( V_17 -> V_43 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_28 ,
V_11 , V_9 ) ;
goto V_13;
}
if ( V_17 -> V_44 ) {
V_9 = F_35 ( V_17 -> V_44 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_29 ,
V_11 , V_9 ) ;
goto V_72;
}
}
V_9 = F_35 ( V_17 -> V_45 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_30 ,
V_11 , V_9 ) ;
goto V_73;
}
V_17 -> V_71 = true ;
goto V_13;
V_73:
if ( V_17 -> V_44 )
F_36 ( V_17 -> V_44 ) ;
V_72:
F_36 ( V_17 -> V_43 ) ;
V_13:
return V_9 ;
}
static int F_37 ( struct V_22 * V_10 ,
struct V_46 * V_47 )
{
int V_9 = 0 ;
if ( ! V_47 || ! V_47 -> V_70 || V_47 -> V_55 )
goto V_13;
V_9 = F_38 ( V_47 -> V_53 ) ;
if ( ! V_9 ) {
F_29 ( V_10 , V_47 , false ) ;
V_47 -> V_70 = false ;
} else {
F_2 ( V_10 , L_31 ,
V_11 , V_47 -> V_35 , V_9 ) ;
}
V_13:
return V_9 ;
}
static void F_39 ( struct V_1 * V_17 )
{
if ( V_17 -> V_71 ) {
F_36 ( V_17 -> V_45 ) ;
if ( V_17 -> V_44 )
F_36 ( V_17 -> V_44 ) ;
F_36 ( V_17 -> V_43 ) ;
V_17 -> V_71 = false ;
}
}
static void F_40 ( struct V_17 * V_18 , bool V_74 )
{
struct V_1 * V_17 = F_5 ( V_18 ) ;
if ( V_17 -> V_27 &&
( V_74 ^ V_17 -> V_75 ) ) {
T_1 V_76 = F_41 ( V_17 -> V_27 ) ;
if ( V_74 )
V_76 |= V_77 ;
else
V_76 &= ~ V_77 ;
if ( ! V_74 )
F_42 ( 1 ) ;
F_3 ( V_76 , V_17 -> V_27 ) ;
F_43 () ;
if ( V_74 )
F_42 ( 1 ) ;
V_17 -> V_75 = V_74 ;
}
}
void F_44 ( struct V_17 * V_18 )
{
F_40 ( V_18 , true ) ;
}
void F_45 ( struct V_17 * V_18 )
{
F_40 ( V_18 , false ) ;
}
static int F_46 ( struct V_1 * V_17 )
{
int V_9 = 0 ;
if ( V_17 -> V_78 )
goto V_13;
V_9 = F_35 ( V_17 -> V_41 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_32 ,
V_11 , V_9 ) ;
goto V_13;
}
V_9 = F_35 ( V_17 -> V_42 ) ;
if ( V_9 ) {
F_36 ( V_17 -> V_41 ) ;
F_2 ( V_17 -> V_10 , L_33 ,
V_11 , V_9 ) ;
goto V_13;
}
V_17 -> V_78 = true ;
V_13:
return V_9 ;
}
void F_47 ( struct V_1 * V_17 )
{
if ( V_17 -> V_78 ) {
F_36 ( V_17 -> V_41 ) ;
F_36 ( V_17 -> V_42 ) ;
V_17 -> V_78 = false ;
}
}
int F_48 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_32 -> V_79 ) {
F_2 ( V_1 -> V_10 , L_34 ,
V_11 ) ;
V_9 = - V_80 ;
} else {
V_1 -> V_32 -> V_79 ( V_1 ) ;
}
return V_9 ;
}
int F_49 ( struct V_17 * V_18 , T_1 V_81 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_32 -> V_82 ) {
F_2 ( V_1 -> V_10 , L_35 ,
V_11 ) ;
V_9 = - V_80 ;
} else {
V_1 -> V_32 -> V_82 ( V_1 ,
V_81 ) ;
}
return V_9 ;
}
void F_50 ( struct V_17 * V_18 ,
T_2 V_83 , T_3 V_84 , T_3 V_85 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
V_1 -> V_86 = V_83 ;
V_1 -> V_87 = V_84 ;
V_1 -> V_88 = V_85 ;
}
int F_51 ( struct V_17 * V_18 , bool V_7 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_32 -> V_89 ) {
F_2 ( V_1 -> V_10 , L_36 ,
V_11 ) ;
V_9 = - V_80 ;
} else {
V_9 = V_1 -> V_32 ->
V_89 ( V_1 , V_7 ) ;
if ( V_9 )
F_2 ( V_1 -> V_10 , L_37 ,
V_11 , V_9 ) ;
}
return V_9 ;
}
int F_52 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
if ( ! V_1 -> V_32 -> V_90 ) {
F_2 ( V_1 -> V_10 , L_38 ,
V_11 ) ;
return - V_80 ;
}
return V_1 -> V_32 ->
V_90 ( V_1 ) ;
}
int F_53 ( struct V_17 * V_18 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
struct V_22 * V_10 = V_21 -> V_10 ;
int V_25 ;
if ( V_21 -> V_91 )
return 0 ;
V_25 = F_32 ( V_10 , & V_21 -> V_65 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_39 ,
V_11 , V_25 ) ;
goto V_13;
}
V_21 -> V_32 -> V_92 ( V_21 , true ) ;
V_25 = F_32 ( V_10 , & V_21 -> V_64 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_40 ,
V_11 , V_25 ) ;
goto V_93;
}
V_25 = F_46 ( V_21 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_41 ,
V_11 , V_25 ) ;
goto V_94;
}
V_25 = F_34 ( V_21 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_42 ,
V_11 , V_25 ) ;
goto V_95;
}
if ( V_21 -> V_66 . V_53 ) {
V_25 = F_32 ( V_10 ,
& V_21 -> V_66 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_43 ,
V_11 , V_25 ) ;
goto V_96;
}
}
V_21 -> V_91 = true ;
goto V_13;
V_96:
F_39 ( V_21 ) ;
V_95:
F_47 ( V_21 ) ;
V_94:
F_37 ( V_10 , & V_21 -> V_64 ) ;
V_93:
F_37 ( V_10 , & V_21 -> V_65 ) ;
V_13:
return V_25 ;
}
int F_54 ( struct V_17 * V_18 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
if ( ! V_21 -> V_91 )
return 0 ;
V_21 -> V_32 -> V_92 ( V_21 , false ) ;
if ( V_21 -> V_66 . V_53 )
F_37 ( V_21 -> V_10 ,
& V_21 -> V_66 ) ;
F_39 ( V_21 ) ;
F_47 ( V_21 ) ;
F_37 ( V_21 -> V_10 , & V_21 -> V_64 ) ;
F_37 ( V_21 -> V_10 , & V_21 -> V_65 ) ;
V_21 -> V_91 = false ;
return 0 ;
}
