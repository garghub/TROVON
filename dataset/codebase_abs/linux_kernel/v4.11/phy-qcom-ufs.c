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
V_40:
V_25 = F_17 ( V_21 -> V_10 , L_13 ,
& V_21 -> V_43 ) ;
if ( V_25 )
goto V_13;
F_15 ( V_21 -> V_10 , L_14 ,
& V_21 -> V_44 , false ) ;
V_25 = F_17 ( V_21 -> V_10 , L_15 ,
& V_21 -> V_45 ) ;
V_13:
return V_25 ;
}
static int F_20 ( struct V_22 * V_10 ,
struct V_46 * V_47 ,
const char * V_35 )
{
int V_25 = 0 ;
char V_48 [ V_49 ] ;
V_47 -> V_35 = V_35 ;
V_47 -> V_50 = F_21 ( V_10 , V_35 ) ;
if ( F_10 ( V_47 -> V_50 ) ) {
V_25 = F_11 ( V_47 -> V_50 ) ;
F_2 ( V_10 , L_16 , V_35 , V_25 ) ;
goto V_13;
}
if ( V_10 -> V_39 ) {
snprintf ( V_48 , V_49 , L_17 , V_35 ) ;
V_25 = F_22 ( V_10 -> V_39 ,
V_48 , & V_47 -> V_51 ) ;
if ( V_25 && V_25 != - V_12 ) {
F_2 ( V_10 , L_18 ,
V_11 , V_48 ) ;
goto V_13;
} else if ( V_25 == - V_12 || ! V_47 -> V_51 ) {
if ( F_23 ( V_47 -> V_50 ) > 0 ) {
F_2 ( V_10 , L_19 ,
V_11 , V_48 ) ;
goto V_13;
}
V_25 = 0 ;
}
}
if ( ! strcmp ( V_35 , L_20 ) ) {
V_47 -> V_52 = V_53 ;
V_47 -> V_54 = V_55 ;
} else if ( ! strcmp ( V_35 , L_21 ) ) {
V_47 -> V_52 = V_56 ;
V_47 -> V_54 = V_57 ;
} else if ( ! strcmp ( V_35 , L_22 ) ) {
V_47 -> V_52 = V_58 ;
V_47 -> V_54 = V_59 ;
}
V_13:
return V_25 ;
}
int F_24 ( struct V_1 * V_21 )
{
int V_25 ;
V_25 = F_20 ( V_21 -> V_10 , & V_21 -> V_60 ,
L_20 ) ;
if ( V_25 )
goto V_13;
V_25 = F_20 ( V_21 -> V_10 , & V_21 -> V_61 ,
L_21 ) ;
if ( V_25 )
goto V_13;
V_25 = F_20 ( V_21 -> V_10 , & V_21 -> V_62 ,
L_22 ) ;
V_13:
return V_25 ;
}
static int F_25 ( struct V_22 * V_10 ,
struct V_46 * V_47 , bool V_63 )
{
int V_9 = 0 ;
struct V_64 * V_50 = V_47 -> V_50 ;
const char * V_35 = V_47 -> V_35 ;
int V_54 ;
int V_65 ;
if ( F_23 ( V_50 ) > 0 ) {
V_54 = V_63 ? V_47 -> V_54 : 0 ;
V_9 = F_26 ( V_50 , V_54 , V_47 -> V_52 ) ;
if ( V_9 ) {
F_2 ( V_10 , L_23 ,
V_11 , V_35 , V_9 ) ;
goto V_13;
}
V_65 = V_63 ? V_47 -> V_51 : 0 ;
V_9 = F_27 ( V_50 , V_65 ) ;
if ( V_9 >= 0 ) {
V_9 = 0 ;
} else {
F_2 ( V_10 , L_24 ,
V_11 , V_35 , V_65 , V_9 ) ;
goto V_13;
}
}
V_13:
return V_9 ;
}
static int F_28 ( struct V_22 * V_10 ,
struct V_46 * V_47 )
{
int V_9 = 0 ;
if ( ! V_47 || V_47 -> V_66 )
goto V_13;
V_9 = F_25 ( V_10 , V_47 , true ) ;
if ( V_9 ) {
F_2 ( V_10 , L_25 ,
V_11 , V_9 ) ;
goto V_13;
}
V_9 = F_29 ( V_47 -> V_50 ) ;
if ( V_9 ) {
F_2 ( V_10 , L_26 ,
V_11 , V_9 ) ;
goto V_13;
}
V_47 -> V_66 = true ;
V_13:
return V_9 ;
}
static int F_30 ( struct V_1 * V_17 )
{
int V_9 = 0 ;
if ( V_17 -> V_67 )
goto V_13;
V_9 = F_31 ( V_17 -> V_43 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_27 ,
V_11 , V_9 ) ;
goto V_13;
}
if ( V_17 -> V_44 ) {
V_9 = F_31 ( V_17 -> V_44 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_28 ,
V_11 , V_9 ) ;
goto V_68;
}
}
V_9 = F_31 ( V_17 -> V_45 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_29 ,
V_11 , V_9 ) ;
goto V_69;
}
V_17 -> V_67 = true ;
goto V_13;
V_69:
if ( V_17 -> V_44 )
F_32 ( V_17 -> V_44 ) ;
V_68:
F_32 ( V_17 -> V_43 ) ;
V_13:
return V_9 ;
}
static int F_33 ( struct V_22 * V_10 ,
struct V_46 * V_47 )
{
int V_9 = 0 ;
if ( ! V_47 || ! V_47 -> V_66 )
goto V_13;
V_9 = F_34 ( V_47 -> V_50 ) ;
if ( ! V_9 ) {
F_25 ( V_10 , V_47 , false ) ;
V_47 -> V_66 = false ;
} else {
F_2 ( V_10 , L_30 ,
V_11 , V_47 -> V_35 , V_9 ) ;
}
V_13:
return V_9 ;
}
static void F_35 ( struct V_1 * V_17 )
{
if ( V_17 -> V_67 ) {
F_32 ( V_17 -> V_45 ) ;
if ( V_17 -> V_44 )
F_32 ( V_17 -> V_44 ) ;
F_32 ( V_17 -> V_43 ) ;
V_17 -> V_67 = false ;
}
}
static void F_36 ( struct V_17 * V_18 , bool V_70 )
{
struct V_1 * V_17 = F_5 ( V_18 ) ;
if ( V_17 -> V_27 &&
( V_70 ^ V_17 -> V_71 ) ) {
T_1 V_72 = F_37 ( V_17 -> V_27 ) ;
if ( V_70 )
V_72 |= V_73 ;
else
V_72 &= ~ V_73 ;
if ( ! V_70 )
F_38 ( 1 ) ;
F_3 ( V_72 , V_17 -> V_27 ) ;
F_39 () ;
if ( V_70 )
F_38 ( 1 ) ;
V_17 -> V_71 = V_70 ;
}
}
void F_40 ( struct V_17 * V_18 )
{
F_36 ( V_18 , true ) ;
}
void F_41 ( struct V_17 * V_18 )
{
F_36 ( V_18 , false ) ;
}
static int F_42 ( struct V_1 * V_17 )
{
int V_9 = 0 ;
if ( V_17 -> V_74 )
goto V_13;
V_9 = F_31 ( V_17 -> V_41 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_31 ,
V_11 , V_9 ) ;
goto V_13;
}
V_9 = F_31 ( V_17 -> V_42 ) ;
if ( V_9 ) {
F_32 ( V_17 -> V_41 ) ;
F_2 ( V_17 -> V_10 , L_32 ,
V_11 , V_9 ) ;
goto V_13;
}
V_17 -> V_74 = true ;
V_13:
return V_9 ;
}
void F_43 ( struct V_1 * V_17 )
{
if ( V_17 -> V_74 ) {
F_32 ( V_17 -> V_41 ) ;
F_32 ( V_17 -> V_42 ) ;
V_17 -> V_74 = false ;
}
}
int F_44 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_32 -> V_75 ) {
F_2 ( V_1 -> V_10 , L_33 ,
V_11 ) ;
V_9 = - V_76 ;
} else {
V_1 -> V_32 -> V_75 ( V_1 ) ;
}
return V_9 ;
}
int F_45 ( struct V_17 * V_18 , T_1 V_77 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_32 -> V_78 ) {
F_2 ( V_1 -> V_10 , L_34 ,
V_11 ) ;
V_9 = - V_76 ;
} else {
V_1 -> V_32 -> V_78 ( V_1 ,
V_77 ) ;
}
return V_9 ;
}
void F_46 ( struct V_17 * V_18 ,
T_2 V_79 , T_3 V_80 , T_3 V_81 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
V_1 -> V_82 = V_79 ;
V_1 -> V_83 = V_80 ;
V_1 -> V_84 = V_81 ;
}
int F_47 ( struct V_17 * V_18 , bool V_7 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_32 -> V_85 ) {
F_2 ( V_1 -> V_10 , L_35 ,
V_11 ) ;
V_9 = - V_76 ;
} else {
V_9 = V_1 -> V_32 ->
V_85 ( V_1 , V_7 ) ;
if ( V_9 )
F_2 ( V_1 -> V_10 , L_36 ,
V_11 , V_9 ) ;
}
return V_9 ;
}
int F_48 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_5 ( V_18 ) ;
if ( ! V_1 -> V_32 -> V_86 ) {
F_2 ( V_1 -> V_10 , L_37 ,
V_11 ) ;
return - V_76 ;
}
return V_1 -> V_32 ->
V_86 ( V_1 ) ;
}
int F_49 ( struct V_17 * V_18 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
struct V_22 * V_10 = V_21 -> V_10 ;
int V_25 ;
if ( V_21 -> V_87 )
return 0 ;
V_25 = F_28 ( V_10 , & V_21 -> V_61 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_38 ,
V_11 , V_25 ) ;
goto V_13;
}
V_21 -> V_32 -> V_88 ( V_21 , true ) ;
V_25 = F_28 ( V_10 , & V_21 -> V_60 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_39 ,
V_11 , V_25 ) ;
goto V_89;
}
V_25 = F_42 ( V_21 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_40 ,
V_11 , V_25 ) ;
goto V_90;
}
V_25 = F_30 ( V_21 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_41 ,
V_11 , V_25 ) ;
goto V_91;
}
if ( V_21 -> V_62 . V_50 ) {
V_25 = F_28 ( V_10 ,
& V_21 -> V_62 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_42 ,
V_11 , V_25 ) ;
goto V_92;
}
}
V_21 -> V_87 = true ;
goto V_13;
V_92:
F_35 ( V_21 ) ;
V_91:
F_43 ( V_21 ) ;
V_90:
F_33 ( V_10 , & V_21 -> V_60 ) ;
V_89:
F_33 ( V_10 , & V_21 -> V_61 ) ;
V_13:
return V_25 ;
}
int F_50 ( struct V_17 * V_18 )
{
struct V_1 * V_21 = F_5 ( V_18 ) ;
if ( ! V_21 -> V_87 )
return 0 ;
V_21 -> V_32 -> V_88 ( V_21 , false ) ;
if ( V_21 -> V_62 . V_50 )
F_33 ( V_21 -> V_10 ,
& V_21 -> V_62 ) ;
F_35 ( V_21 ) ;
F_43 ( V_21 ) ;
F_33 ( V_21 -> V_10 , & V_21 -> V_60 ) ;
F_33 ( V_21 -> V_10 , & V_21 -> V_61 ) ;
V_21 -> V_87 = false ;
return 0 ;
}
