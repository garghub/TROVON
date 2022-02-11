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
return F_10 ( & V_40 -> V_43 ) ;
}
static int F_16 ( struct V_37 * V_39 )
{
struct V_36 * V_40 = F_13 ( V_39 ) ;
F_9 ( L_4 , V_41 , V_39 -> V_42 ) ;
return F_11 ( & V_40 -> V_43 ) ;
}
static void T_1 F_17 ( struct V_36 * V_40 )
{
struct V_37 * V_39 = & V_40 -> V_39 ;
const char * V_42 = V_40 -> V_39 . V_42 ;
struct V_44 * V_45 = & V_46 ;
if ( V_40 -> V_22 & V_47 ) {
F_9 ( L_5 , V_42 , L_6 ) ;
V_39 -> V_22 |= V_48 ;
} else if ( V_40 -> V_22 & V_49 ) {
F_9 ( L_5 , V_42 , L_7 ) ;
V_39 -> V_22 |= V_48 ;
} else if ( V_40 -> V_22 & V_50 ) {
V_39 -> V_22 |= V_48 ;
}
if ( ! ( V_40 -> V_22 & ( V_47 | V_49 ) ) ) {
V_39 -> V_22 |= V_51 ;
if ( V_52 ) {
V_39 -> V_53 = V_54 ;
V_39 -> V_55 = V_56 ;
} else {
V_39 -> V_53 = V_57 ;
V_39 -> V_55 = V_58 ;
}
}
V_39 -> V_59 = F_15 ;
V_39 -> V_60 = F_16 ;
if ( V_40 -> V_22 & ( V_47 | V_50 ) ) {
F_9 ( L_8 , V_41 , V_39 -> V_42 ) ;
goto V_61;
}
if ( ! F_12 ( & V_40 -> V_43 ) ) {
F_9 ( L_9 , V_41 , V_39 -> V_42 ) ;
goto V_61;
}
F_11 ( & V_40 -> V_43 ) ;
V_61:
F_18 ( V_39 , V_45 , false ) ;
}
static int T_1 F_19 ( void )
{
const struct V_62 * V_63 ;
const struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
T_2 V_70 , V_71 ;
void T_3 * V_72 ;
unsigned int V_73 ;
int error ;
if ( V_12 )
return 0 ;
V_69 = F_20 ( NULL , V_74 , & V_65 ) ;
if ( ! V_69 )
return - V_75 ;
V_63 = V_65 -> V_76 ;
if ( V_63 -> V_77 ) {
error = V_63 -> V_77 () ;
if ( error )
return error ;
}
V_52 = F_21 ( NULL , NULL ,
L_10 ) ;
V_72 = F_22 ( V_69 , 0 ) ;
if ( ! V_72 ) {
F_23 ( L_11 , V_69 ) ;
error = - V_78 ;
goto V_79;
}
V_12 = V_72 ;
V_67 = F_24 ( sizeof( * V_67 ) , V_80 ) ;
if ( ! V_67 ) {
error = - V_78 ;
goto V_79;
}
V_67 -> V_81 . V_67 = V_67 -> V_67 ;
V_67 -> V_81 . V_82 = F_25 ( V_67 -> V_67 ) ;
for ( V_73 = 0 , V_70 = 0 ; V_73 < V_63 -> V_83 ; V_73 ++ )
V_70 |= F_3 ( V_63 -> V_84 [ V_73 ] . V_19 ) ;
V_71 = F_2 ( V_72 + V_85 ) ;
V_71 |= V_70 ;
F_9 ( L_12 , V_69 , V_71 ) ;
F_5 ( V_71 , V_72 + V_85 ) ;
F_9 ( L_13 , V_69 , V_70 ) ;
F_5 ( V_70 , V_72 + V_86 ) ;
for ( V_73 = 0 ; V_73 < V_63 -> V_83 ; V_73 ++ ) {
const struct V_87 * V_88 = & V_63 -> V_84 [ V_73 ] ;
struct V_36 * V_40 ;
if ( ! V_88 -> V_42 ) {
continue;
}
V_40 = F_24 ( sizeof( * V_40 ) + strlen ( V_88 -> V_42 ) + 1 , V_80 ) ;
if ( ! V_40 ) {
error = - V_78 ;
goto V_79;
}
strcpy ( V_40 -> V_42 , V_88 -> V_42 ) ;
V_40 -> V_39 . V_42 = V_40 -> V_42 ;
V_40 -> V_43 . V_17 = V_88 -> V_17 ;
V_40 -> V_43 . V_16 = V_88 -> V_16 ;
V_40 -> V_43 . V_19 = V_88 -> V_19 ;
V_40 -> V_22 = V_88 -> V_22 ;
F_17 ( V_40 ) ;
if ( V_88 -> V_89 >= 0 )
F_26 ( V_67 -> V_67 [ V_88 -> V_89 ] ,
& V_40 -> V_39 ) ;
V_67 -> V_67 [ V_88 -> V_19 ] = & V_40 -> V_39 ;
}
error = F_27 ( V_69 , & V_67 -> V_81 ) ;
V_79:
F_28 ( V_69 ) ;
return error ;
}
void T_1 F_29 ( struct V_87 * V_84 ,
unsigned int V_83 , T_4 V_90 )
{
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_83 ; V_73 ++ )
if ( V_84 [ V_73 ] . V_19 == V_90 ) {
V_84 [ V_73 ] . V_42 = NULL ;
return;
}
}
void T_1 F_30 ( T_5 V_72 , T_2 V_70 )
{
T_2 V_71 ;
if ( ! F_19 () )
return;
V_12 = F_31 ( V_72 , V_91 ) ;
V_71 = F_2 ( V_12 + V_85 ) ;
V_71 |= V_70 ;
F_9 ( L_14 , V_41 , V_71 ) ;
F_5 ( V_71 , V_12 + V_85 ) ;
F_9 ( L_15 , V_41 , V_70 ) ;
F_5 ( V_70 , V_12 + V_86 ) ;
}
