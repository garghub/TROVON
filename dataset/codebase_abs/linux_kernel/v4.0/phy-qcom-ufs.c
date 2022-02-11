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
struct V_17 * F_5 ( struct V_18 * V_19 ,
struct V_1 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
int V_25 ;
struct V_26 * V_10 = & V_19 -> V_10 ;
struct V_17 * V_27 = NULL ;
struct V_28 * V_28 ;
V_25 = F_6 ( V_19 , V_20 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_3 , V_11 , V_25 ) ;
goto V_13;
}
V_28 = F_7 ( V_10 , V_29 ) ;
if ( F_8 ( V_28 ) ) {
V_25 = F_9 ( V_28 ) ;
F_2 ( V_10 , L_4 , V_11 , V_25 ) ;
goto V_13;
}
V_27 = F_10 ( V_10 , NULL , V_22 ) ;
if ( F_8 ( V_27 ) ) {
V_25 = F_9 ( V_27 ) ;
F_2 ( V_10 , L_5 , V_11 , V_25 ) ;
goto V_13;
}
V_20 -> V_24 = V_24 ;
V_20 -> V_10 = V_10 ;
V_13:
return V_27 ;
}
struct V_1 * F_11 ( struct V_17 * V_27 )
{
return (struct V_1 * ) F_12 ( V_27 ) ;
}
static
int F_6 ( struct V_18 * V_19 ,
struct V_1 * V_30 )
{
struct V_26 * V_10 = & V_19 -> V_10 ;
struct V_31 * V_32 ;
int V_25 = 0 ;
V_32 = F_13 ( V_19 , V_33 , L_6 ) ;
if ( ! V_32 ) {
F_2 ( V_10 , L_7 , V_11 ) ;
V_25 = - V_34 ;
goto V_13;
}
V_30 -> V_15 = F_14 ( V_10 , V_32 ) ;
if ( F_8 ( ( void const * ) V_30 -> V_15 ) ) {
V_25 = F_9 ( ( void const * ) V_30 -> V_15 ) ;
V_30 -> V_15 = NULL ;
F_2 ( V_10 , L_8 ,
V_11 , V_25 ) ;
goto V_13;
}
V_32 = F_13 ( V_19 , V_33 ,
L_9 ) ;
if ( ! V_32 ) {
F_15 ( V_10 , L_10 ,
V_11 ) ;
goto V_13;
}
V_30 -> V_35 = F_14 ( V_10 , V_32 ) ;
if ( F_8 ( ( void const * ) V_30 -> V_35 ) ) {
V_25 = F_9 ( ( void const * ) V_30 -> V_35 ) ;
V_30 -> V_35 = NULL ;
F_2 ( V_10 , L_11 ,
V_11 , V_25 ) ;
}
V_13:
return V_25 ;
}
static int F_16 ( struct V_17 * V_17 ,
const char * V_36 , struct V_37 * * V_38 , bool V_39 )
{
struct V_37 * V_37 ;
int V_25 = 0 ;
struct V_1 * V_1 = F_11 ( V_17 ) ;
struct V_26 * V_10 = V_1 -> V_10 ;
V_37 = F_17 ( V_10 , V_36 ) ;
if ( F_8 ( V_37 ) ) {
V_25 = F_9 ( V_37 ) ;
if ( V_39 )
F_2 ( V_10 , L_12 , V_36 , V_25 ) ;
} else {
* V_38 = V_37 ;
}
return V_25 ;
}
static
int F_18 ( struct V_17 * V_17 ,
const char * V_36 , struct V_37 * * V_38 )
{
return F_16 ( V_17 , V_36 , V_38 , true ) ;
}
int
F_19 ( struct V_17 * V_27 ,
struct V_1 * V_30 )
{
int V_25 ;
V_25 = F_18 ( V_27 , L_13 ,
& V_30 -> V_40 ) ;
if ( V_25 )
goto V_13;
V_25 = F_18 ( V_27 , L_14 ,
& V_30 -> V_41 ) ;
if ( V_25 )
goto V_13;
V_25 = F_18 ( V_27 , L_15 ,
& V_30 -> V_42 ) ;
if ( V_25 )
goto V_13;
F_16 ( V_27 , L_16 ,
& V_30 -> V_43 , false ) ;
V_25 = F_18 ( V_27 , L_17 ,
& V_30 -> V_44 ) ;
V_13:
return V_25 ;
}
int
F_20 ( struct V_17 * V_27 ,
struct V_1 * V_30 )
{
int V_25 ;
V_25 = F_21 ( V_27 , & V_30 -> V_45 ,
L_18 ) ;
if ( V_25 )
goto V_13;
V_25 = F_21 ( V_27 , & V_30 -> V_46 ,
L_19 ) ;
if ( V_25 )
goto V_13;
F_22 ( V_27 , & V_30 -> V_47 ,
L_20 , true ) ;
V_13:
return V_25 ;
}
static int F_22 ( struct V_17 * V_17 ,
struct V_48 * V_49 , const char * V_36 , bool V_50 )
{
int V_25 = 0 ;
struct V_1 * V_1 = F_11 ( V_17 ) ;
struct V_26 * V_10 = V_1 -> V_10 ;
char V_51 [ V_52 ] ;
V_49 -> V_36 = F_23 ( V_36 , V_53 ) ;
if ( ! V_49 -> V_36 ) {
V_25 = - V_34 ;
goto V_13;
}
V_49 -> V_54 = F_24 ( V_10 , V_36 ) ;
if ( F_8 ( V_49 -> V_54 ) ) {
V_25 = F_9 ( V_49 -> V_54 ) ;
V_49 -> V_54 = NULL ;
if ( ! V_50 )
F_2 ( V_10 , L_21 , V_36 , V_25 ) ;
goto V_13;
}
if ( V_10 -> V_55 ) {
snprintf ( V_51 , V_52 , L_22 , V_36 ) ;
V_25 = F_25 ( V_10 -> V_55 ,
V_51 , & V_49 -> V_56 ) ;
if ( V_25 && V_25 != - V_12 ) {
F_2 ( V_10 , L_23 ,
V_11 , V_51 ) ;
goto V_13;
} else if ( V_25 == - V_12 || ! V_49 -> V_56 ) {
if ( F_26 ( V_49 -> V_54 ) > 0 ) {
F_2 ( V_10 , L_24 ,
V_11 , V_51 ) ;
goto V_13;
}
V_25 = 0 ;
}
snprintf ( V_51 , V_52 , L_25 , V_36 ) ;
if ( F_27 ( V_10 -> V_55 , V_51 , NULL ) )
V_49 -> V_57 = true ;
else
V_49 -> V_57 = false ;
}
if ( ! strcmp ( V_36 , L_18 ) ) {
V_49 -> V_58 = V_59 ;
V_49 -> V_60 = V_61 ;
} else if ( ! strcmp ( V_36 , L_19 ) ) {
V_49 -> V_58 = V_62 ;
V_49 -> V_60 = V_63 ;
} else if ( ! strcmp ( V_36 , L_20 ) ) {
V_49 -> V_58 = V_64 ;
V_49 -> V_60 = V_65 ;
}
V_13:
if ( V_25 )
F_28 ( V_49 -> V_36 ) ;
return V_25 ;
}
static int F_21 ( struct V_17 * V_17 ,
struct V_48 * V_49 , const char * V_36 )
{
return F_22 ( V_17 , V_49 , V_36 , false ) ;
}
static
int F_29 ( struct V_17 * V_17 ,
struct V_48 * V_49 , bool V_66 )
{
int V_9 = 0 ;
struct V_67 * V_54 = V_49 -> V_54 ;
const char * V_36 = V_49 -> V_36 ;
int V_60 ;
int V_68 ;
struct V_1 * V_1 = F_11 ( V_17 ) ;
struct V_26 * V_10 = V_1 -> V_10 ;
F_30 ( ! V_49 ) ;
if ( F_26 ( V_54 ) > 0 ) {
V_60 = V_66 ? V_49 -> V_60 : 0 ;
V_9 = F_31 ( V_54 , V_60 , V_49 -> V_58 ) ;
if ( V_9 ) {
F_2 ( V_10 , L_26 ,
V_11 , V_36 , V_9 ) ;
goto V_13;
}
V_68 = V_66 ? V_49 -> V_56 : 0 ;
V_9 = F_32 ( V_54 , V_68 ) ;
if ( V_9 >= 0 ) {
V_9 = 0 ;
} else {
F_2 ( V_10 , L_27 ,
V_11 , V_36 , V_68 , V_9 ) ;
goto V_13;
}
}
V_13:
return V_9 ;
}
static
int F_33 ( struct V_17 * V_17 ,
struct V_48 * V_49 )
{
struct V_1 * V_1 = F_11 ( V_17 ) ;
struct V_26 * V_10 = V_1 -> V_10 ;
int V_9 = 0 ;
if ( ! V_49 || V_49 -> V_69 )
goto V_13;
V_9 = F_29 ( V_17 , V_49 , true ) ;
if ( V_9 ) {
F_2 ( V_10 , L_28 ,
V_11 , V_9 ) ;
goto V_13;
}
V_9 = F_34 ( V_49 -> V_54 ) ;
if ( V_9 ) {
F_2 ( V_10 , L_29 ,
V_11 , V_9 ) ;
goto V_13;
}
V_49 -> V_69 = true ;
V_13:
return V_9 ;
}
int F_35 ( struct V_17 * V_27 )
{
int V_9 = 0 ;
struct V_1 * V_17 = F_11 ( V_27 ) ;
if ( V_17 -> V_70 )
goto V_13;
V_9 = F_36 ( V_17 -> V_42 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_30 ,
V_11 , V_9 ) ;
goto V_13;
}
if ( V_17 -> V_43 ) {
V_9 = F_36 ( V_17 -> V_43 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_31 ,
V_11 , V_9 ) ;
goto V_71;
}
}
V_9 = F_36 ( V_17 -> V_44 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_32 ,
V_11 , V_9 ) ;
goto V_72;
}
V_17 -> V_70 = true ;
goto V_13;
V_72:
if ( V_17 -> V_43 )
F_37 ( V_17 -> V_43 ) ;
V_71:
F_37 ( V_17 -> V_42 ) ;
V_13:
return V_9 ;
}
static
int F_38 ( struct V_17 * V_17 ,
struct V_48 * V_49 )
{
struct V_1 * V_1 = F_11 ( V_17 ) ;
struct V_26 * V_10 = V_1 -> V_10 ;
int V_9 = 0 ;
if ( ! V_49 || ! V_49 -> V_69 || V_49 -> V_57 )
goto V_13;
V_9 = F_39 ( V_49 -> V_54 ) ;
if ( ! V_9 ) {
F_29 ( V_17 , V_49 , false ) ;
V_49 -> V_69 = false ;
} else {
F_2 ( V_10 , L_33 ,
V_11 , V_49 -> V_36 , V_9 ) ;
}
V_13:
return V_9 ;
}
void F_40 ( struct V_17 * V_27 )
{
struct V_1 * V_17 = F_11 ( V_27 ) ;
if ( V_17 -> V_70 ) {
F_37 ( V_17 -> V_44 ) ;
if ( V_17 -> V_43 )
F_37 ( V_17 -> V_43 ) ;
F_37 ( V_17 -> V_42 ) ;
V_17 -> V_70 = false ;
}
}
static void F_41 ( struct V_17 * V_27 , bool V_73 )
{
struct V_1 * V_17 = F_11 ( V_27 ) ;
if ( V_17 -> V_35 &&
( V_73 ^ V_17 -> V_74 ) ) {
T_1 V_75 = F_42 ( V_17 -> V_35 ) ;
if ( V_73 )
V_75 |= V_76 ;
else
V_75 &= ~ V_76 ;
if ( ! V_73 )
F_43 ( 1 ) ;
F_3 ( V_75 , V_17 -> V_35 ) ;
F_44 () ;
if ( V_73 )
F_43 ( 1 ) ;
V_17 -> V_74 = V_73 ;
}
}
void F_45 ( struct V_17 * V_27 )
{
F_41 ( V_27 , true ) ;
}
void F_46 ( struct V_17 * V_27 )
{
F_41 ( V_27 , false ) ;
}
int F_47 ( struct V_17 * V_27 )
{
struct V_1 * V_17 = F_11 ( V_27 ) ;
int V_9 = 0 ;
if ( V_17 -> V_77 )
goto V_13;
V_9 = F_36 ( V_17 -> V_40 ) ;
if ( V_9 ) {
F_2 ( V_17 -> V_10 , L_34 ,
V_11 , V_9 ) ;
goto V_13;
}
V_9 = F_36 ( V_17 -> V_41 ) ;
if ( V_9 ) {
F_37 ( V_17 -> V_40 ) ;
F_2 ( V_17 -> V_10 , L_35 ,
V_11 , V_9 ) ;
goto V_13;
}
V_17 -> V_77 = true ;
V_13:
return V_9 ;
}
void F_48 ( struct V_17 * V_27 )
{
struct V_1 * V_17 = F_11 ( V_27 ) ;
if ( V_17 -> V_77 ) {
F_37 ( V_17 -> V_40 ) ;
F_37 ( V_17 -> V_41 ) ;
V_17 -> V_77 = false ;
}
}
int F_49 ( struct V_17 * V_27 )
{
struct V_1 * V_1 = F_11 ( V_27 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_24 -> V_78 ) {
F_2 ( V_1 -> V_10 , L_36 ,
V_11 ) ;
V_9 = - V_79 ;
} else {
V_1 -> V_24 -> V_78 ( V_1 ) ;
}
return V_9 ;
}
int F_50 ( struct V_17 * V_27 , T_1 V_80 )
{
struct V_1 * V_1 = F_11 ( V_27 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_24 -> V_81 ) {
F_2 ( V_1 -> V_10 , L_37 ,
V_11 ) ;
V_9 = - V_79 ;
} else {
V_1 -> V_24 -> V_81 ( V_1 ,
V_80 ) ;
}
return V_9 ;
}
void F_51 ( struct V_17 * V_27 ,
T_2 V_82 , T_3 V_83 , T_3 V_84 )
{
struct V_1 * V_1 = F_11 ( V_27 ) ;
V_1 -> V_85 = V_82 ;
V_1 -> V_86 = V_83 ;
V_1 -> V_87 = V_84 ;
}
int F_52 ( struct V_17 * V_27 , bool V_7 )
{
struct V_1 * V_1 = F_11 ( V_27 ) ;
int V_9 = 0 ;
if ( ! V_1 -> V_24 -> V_88 ) {
F_2 ( V_1 -> V_10 , L_38 ,
V_11 ) ;
V_9 = - V_79 ;
} else {
V_9 = V_1 -> V_24 ->
V_88 ( V_1 , V_7 ) ;
if ( V_9 )
F_2 ( V_1 -> V_10 , L_39 ,
V_11 , V_9 ) ;
}
return V_9 ;
}
int F_53 ( struct V_17 * V_27 ,
struct V_1 * V_1 )
{
F_54 ( V_27 ) ;
F_28 ( V_1 -> V_45 . V_36 ) ;
F_28 ( V_1 -> V_46 . V_36 ) ;
return 0 ;
}
int F_55 ( struct V_17 * V_27 )
{
struct V_1 * V_1 = F_11 ( V_27 ) ;
if ( V_1 -> V_89 )
F_54 ( V_27 ) ;
return 0 ;
}
int F_56 ( struct V_17 * V_27 )
{
struct V_1 * V_1 = F_11 ( V_27 ) ;
if ( ! V_1 -> V_24 -> V_90 ) {
F_2 ( V_1 -> V_10 , L_40 ,
V_11 ) ;
return - V_79 ;
}
return V_1 -> V_24 ->
V_90 ( V_1 ) ;
}
int F_57 ( struct V_17 * V_27 )
{
struct V_1 * V_30 = F_11 ( V_27 ) ;
struct V_26 * V_10 = V_30 -> V_10 ;
int V_25 ;
V_25 = F_33 ( V_27 , & V_30 -> V_46 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_41 ,
V_11 , V_25 ) ;
goto V_13;
}
V_30 -> V_24 -> V_91 ( V_30 , true ) ;
V_25 = F_33 ( V_27 , & V_30 -> V_45 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_42 ,
V_11 , V_25 ) ;
goto V_92;
}
V_25 = F_35 ( V_27 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_43 ,
V_11 , V_25 ) ;
goto V_93;
}
if ( V_30 -> V_47 . V_54 ) {
V_25 = F_33 ( V_27 ,
& V_30 -> V_47 ) ;
if ( V_25 ) {
F_2 ( V_10 , L_44 ,
V_11 , V_25 ) ;
goto V_94;
}
}
V_30 -> V_89 = true ;
goto V_13;
V_94:
F_40 ( V_27 ) ;
V_93:
F_38 ( V_27 , & V_30 -> V_45 ) ;
V_92:
F_38 ( V_27 , & V_30 -> V_46 ) ;
V_13:
return V_25 ;
}
int F_58 ( struct V_17 * V_27 )
{
struct V_1 * V_30 = F_11 ( V_27 ) ;
V_30 -> V_24 -> V_91 ( V_30 , false ) ;
if ( V_30 -> V_47 . V_54 )
F_38 ( V_27 ,
& V_30 -> V_47 ) ;
F_40 ( V_27 ) ;
F_38 ( V_27 , & V_30 -> V_45 ) ;
F_38 ( V_27 , & V_30 -> V_46 ) ;
V_30 -> V_89 = false ;
return 0 ;
}
