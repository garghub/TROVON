static int F_1 ( const struct V_1 * V_2 , bool V_3 )
{
unsigned int V_4 , V_5 ;
int V_6 ;
if ( V_3 ) {
V_4 = V_7 ;
V_5 = V_8 ;
} else {
V_4 = V_9 ;
V_5 = V_10 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
if ( F_2 ( V_12 + V_13 ) & F_3 ( V_4 ) )
break;
F_4 ( V_14 ) ;
}
if ( V_6 == V_11 )
return - V_15 ;
F_5 ( F_3 ( V_2 -> V_16 ) ,
V_12 + V_2 -> V_17 + V_5 ) ;
return 0 ;
}
static int F_6 ( const struct V_1 * V_2 , bool V_3 )
{
unsigned int V_18 = F_3 ( V_2 -> V_19 ) ;
unsigned int V_20 = F_3 ( V_2 -> V_16 ) ;
unsigned int V_21 ;
unsigned long V_22 ;
int V_23 = 0 ;
int V_6 ;
F_7 ( & V_24 , V_22 ) ;
F_5 ( V_18 , V_12 + V_25 ) ;
for ( V_6 = 0 ; V_6 < V_26 ; V_6 ++ ) {
V_23 = F_1 ( V_2 , V_3 ) ;
if ( V_23 )
goto V_27;
V_21 = F_2 ( V_12 +
V_2 -> V_17 + V_28 ) ;
if ( ! ( V_21 & V_20 ) )
break;
F_4 ( V_29 ) ;
}
if ( V_6 == V_26 ) {
V_23 = - V_30 ;
goto V_27;
}
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ ) {
if ( F_2 ( V_12 + V_32 ) & V_18 )
break;
F_4 ( V_33 ) ;
}
if ( V_6 == V_31 )
V_23 = - V_30 ;
F_5 ( V_18 , V_12 + V_25 ) ;
V_27:
F_8 ( & V_24 , V_22 ) ;
F_9 ( L_1 , V_3 ? L_2 : L_3 ,
V_2 -> V_19 , F_2 ( V_12 + V_32 ) , V_23 ) ;
return V_23 ;
}
int F_10 ( const struct V_1 * V_2 )
{
return F_6 ( V_2 , false ) ;
}
int F_11 ( const struct V_1 * V_2 )
{
return F_6 ( V_2 , true ) ;
}
static bool F_12 ( const struct V_1 * V_2 )
{
unsigned int V_34 ;
V_34 = F_2 ( V_12 + V_2 -> V_17 + V_35 ) ;
if ( V_34 & F_3 ( V_2 -> V_16 ) )
return true ;
return false ;
}
static inline struct V_36 * F_13 ( struct V_37 * V_38 )
{
return F_14 ( V_38 , struct V_36 , V_39 ) ;
}
static int F_15 ( struct V_37 * V_39 )
{
struct V_36 * V_40 = F_13 ( V_39 ) ;
F_9 ( L_4 , V_41 , V_39 -> V_42 ) ;
if ( V_40 -> V_22 & V_43 ) {
F_9 ( L_5 , V_41 , V_39 -> V_42 ) ;
return - V_44 ;
}
if ( V_40 -> V_22 & V_45 ) {
F_9 ( L_6 , V_41 , V_39 -> V_42 ) ;
return - V_44 ;
}
return F_10 ( & V_40 -> V_46 ) ;
}
static int F_16 ( struct V_37 * V_39 )
{
struct V_36 * V_40 = F_13 ( V_39 ) ;
F_9 ( L_4 , V_41 , V_39 -> V_42 ) ;
if ( V_40 -> V_22 & V_43 ) {
F_9 ( L_5 , V_41 , V_39 -> V_42 ) ;
return 0 ;
}
return F_11 ( & V_40 -> V_46 ) ;
}
static void T_1 F_17 ( struct V_36 * V_40 )
{
struct V_37 * V_39 = & V_40 -> V_39 ;
const char * V_42 = V_40 -> V_39 . V_42 ;
struct V_47 * V_48 = & V_49 ;
if ( V_40 -> V_22 & V_50 ) {
F_9 ( L_7 , V_42 , L_8 ) ;
V_40 -> V_22 |= V_45 ;
V_48 = & V_51 ;
} else if ( V_40 -> V_22 & V_52 ) {
F_9 ( L_7 , V_42 , L_9 ) ;
V_40 -> V_22 |= V_45 ;
V_48 = & V_51 ;
} else if ( V_40 -> V_22 & V_43 ) {
V_40 -> V_22 |= V_45 ;
V_48 = & V_51 ;
}
if ( ! ( V_40 -> V_22 & ( V_50 | V_52 ) ) ) {
V_39 -> V_22 = V_53 ;
if ( V_54 ) {
V_39 -> V_55 = V_56 ;
V_39 -> V_57 = V_58 ;
} else {
V_39 -> V_55 = V_59 ;
V_39 -> V_57 = V_60 ;
}
}
V_39 -> V_61 = F_15 ;
V_39 -> V_62 = F_16 ;
if ( V_40 -> V_22 & ( V_50 | V_43 ) ) {
F_9 ( L_10 , V_41 , V_39 -> V_42 ) ;
goto V_63;
}
if ( ! F_12 ( & V_40 -> V_46 ) ) {
F_9 ( L_11 , V_41 , V_39 -> V_42 ) ;
goto V_63;
}
F_11 ( & V_40 -> V_46 ) ;
V_63:
F_18 ( V_39 , V_48 , false ) ;
}
static int T_1 F_19 ( void )
{
const struct V_64 * V_65 ;
const struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
T_2 V_72 , V_73 ;
void T_3 * V_74 ;
unsigned int V_75 ;
int error ;
if ( V_12 )
return 0 ;
V_71 = F_20 ( NULL , V_76 , & V_67 ) ;
if ( ! V_71 )
return - V_77 ;
V_65 = V_67 -> V_78 ;
V_54 = F_21 ( NULL , NULL ,
L_12 ) ;
V_74 = F_22 ( V_71 , 0 ) ;
if ( ! V_74 ) {
F_23 ( L_13 , V_71 -> V_79 ) ;
error = - V_80 ;
goto V_81;
}
V_12 = V_74 ;
V_69 = F_24 ( sizeof( * V_69 ) , V_82 ) ;
if ( ! V_69 ) {
error = - V_80 ;
goto V_81;
}
V_69 -> V_83 . V_69 = V_69 -> V_69 ;
V_69 -> V_83 . V_84 = F_25 ( V_69 -> V_69 ) ;
for ( V_75 = 0 , V_72 = 0 ; V_75 < V_65 -> V_85 ; V_75 ++ )
V_72 |= F_3 ( V_65 -> V_86 [ V_75 ] . V_19 ) ;
V_73 = F_2 ( V_74 + V_87 ) ;
V_73 |= V_72 ;
F_9 ( L_14 , V_71 -> V_79 , V_73 ) ;
F_5 ( V_73 , V_74 + V_87 ) ;
F_9 ( L_15 , V_71 -> V_79 , V_72 ) ;
F_5 ( V_72 , V_74 + V_88 ) ;
for ( V_75 = 0 ; V_75 < V_65 -> V_85 ; V_75 ++ ) {
const struct V_89 * V_90 = & V_65 -> V_86 [ V_75 ] ;
struct V_36 * V_40 ;
V_40 = F_24 ( sizeof( * V_40 ) + strlen ( V_90 -> V_42 ) + 1 , V_82 ) ;
if ( ! V_40 ) {
error = - V_80 ;
goto V_81;
}
strcpy ( V_40 -> V_42 , V_90 -> V_42 ) ;
V_40 -> V_39 . V_42 = V_40 -> V_42 ;
V_40 -> V_46 . V_17 = V_90 -> V_17 ;
V_40 -> V_46 . V_16 = V_90 -> V_16 ;
V_40 -> V_46 . V_19 = V_90 -> V_19 ;
V_40 -> V_22 = V_90 -> V_22 ;
F_17 ( V_40 ) ;
if ( V_90 -> V_91 >= 0 )
F_26 ( V_69 -> V_69 [ V_90 -> V_91 ] ,
& V_40 -> V_39 ) ;
V_69 -> V_69 [ V_90 -> V_19 ] = & V_40 -> V_39 ;
}
error = F_27 ( V_71 , & V_69 -> V_83 ) ;
V_81:
F_28 ( V_71 ) ;
return error ;
}
void T_1 F_29 ( T_4 V_74 , T_2 V_72 )
{
T_2 V_73 ;
if ( ! F_19 () )
return;
V_12 = F_30 ( V_74 , V_92 ) ;
V_73 = F_2 ( V_12 + V_87 ) ;
V_73 |= V_72 ;
F_9 ( L_14 , V_41 , V_73 ) ;
F_5 ( V_73 , V_12 + V_87 ) ;
F_9 ( L_15 , V_41 , V_72 ) ;
F_5 ( V_72 , V_12 + V_88 ) ;
}
