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
void T_1 * F_13 ( T_2 V_36 )
{
V_12 = F_14 ( V_36 , V_37 ) ;
if ( ! V_12 )
F_15 ( L_4 ) ;
return V_12 ;
}
static inline struct V_38 * F_16 ( struct V_39 * V_40 )
{
return F_17 ( V_40 , struct V_38 , V_41 ) ;
}
static int F_18 ( struct V_39 * V_41 )
{
struct V_38 * V_42 = F_16 ( V_41 ) ;
F_9 ( L_5 , V_43 , V_41 -> V_44 ) ;
if ( V_42 -> V_22 & V_45 ) {
F_9 ( L_6 , V_43 , V_41 -> V_44 ) ;
return - V_46 ;
}
if ( V_42 -> V_22 & V_47 ) {
F_9 ( L_7 , V_43 , V_41 -> V_44 ) ;
return - V_46 ;
}
return F_10 ( & V_42 -> V_48 ) ;
}
static int F_19 ( struct V_39 * V_41 )
{
struct V_38 * V_42 = F_16 ( V_41 ) ;
F_9 ( L_5 , V_43 , V_41 -> V_44 ) ;
if ( V_42 -> V_22 & V_45 ) {
F_9 ( L_6 , V_43 , V_41 -> V_44 ) ;
return 0 ;
}
return F_11 ( & V_42 -> V_48 ) ;
}
static void T_3 F_20 ( struct V_38 * V_42 )
{
struct V_39 * V_41 = & V_42 -> V_41 ;
const char * V_44 = V_42 -> V_41 . V_44 ;
struct V_49 * V_50 = & V_51 ;
if ( V_42 -> V_22 & V_52 ) {
F_9 ( L_8 , V_44 , L_9 ) ;
V_42 -> V_22 |= V_47 ;
V_50 = & V_53 ;
} else if ( V_42 -> V_22 & V_54 ) {
F_9 ( L_8 , V_44 , L_10 ) ;
V_42 -> V_22 |= V_47 ;
V_50 = & V_53 ;
} else if ( V_42 -> V_22 & V_45 ) {
V_42 -> V_22 |= V_47 ;
V_50 = & V_53 ;
}
if ( ! ( V_42 -> V_22 & ( V_52 | V_54 ) ) ) {
V_41 -> V_22 = V_55 ;
if ( V_56 ) {
V_41 -> V_57 = V_58 ;
V_41 -> V_59 = V_60 ;
} else {
V_41 -> V_57 = V_61 ;
V_41 -> V_59 = V_62 ;
}
}
V_41 -> V_63 = F_18 ;
V_41 -> V_64 = F_19 ;
if ( V_42 -> V_22 & ( V_52 | V_45 ) ) {
F_9 ( L_11 , V_43 , V_41 -> V_44 ) ;
goto V_65;
}
if ( ! F_12 ( & V_42 -> V_48 ) ) {
F_9 ( L_12 , V_43 , V_41 -> V_44 ) ;
goto V_65;
}
F_11 ( & V_42 -> V_48 ) ;
V_65:
F_21 ( V_41 , V_50 , false ) ;
}
static int T_3 F_22 ( void )
{
const struct V_66 * V_67 ;
const struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
T_4 V_74 , V_75 ;
void T_1 * V_36 ;
unsigned int V_76 ;
int error ;
V_73 = F_23 ( NULL , V_77 , & V_69 ) ;
if ( ! V_73 )
return - V_78 ;
V_67 = V_69 -> V_79 ;
V_56 = F_24 ( NULL , NULL ,
L_13 ) ;
V_36 = F_25 ( V_73 , 0 ) ;
if ( ! V_36 ) {
F_26 ( L_14 , V_73 -> V_80 ) ;
error = - V_81 ;
goto V_82;
}
V_12 = V_36 ;
V_71 = F_27 ( sizeof( * V_71 ) , V_83 ) ;
if ( ! V_71 ) {
error = - V_81 ;
goto V_82;
}
V_71 -> V_84 . V_71 = V_71 -> V_71 ;
V_71 -> V_84 . V_85 = F_28 ( V_71 -> V_71 ) ;
for ( V_76 = 0 , V_74 = 0 ; V_76 < V_67 -> V_86 ; V_76 ++ )
V_74 |= F_3 ( V_67 -> V_87 [ V_76 ] . V_19 ) ;
V_75 = F_2 ( V_36 + V_88 ) ;
V_75 |= V_74 ;
F_9 ( L_15 , V_73 -> V_80 , V_75 ) ;
F_5 ( V_75 , V_36 + V_88 ) ;
F_9 ( L_16 , V_73 -> V_80 , V_74 ) ;
F_5 ( V_74 , V_36 + V_89 ) ;
for ( V_76 = 0 ; V_76 < V_67 -> V_86 ; V_76 ++ ) {
const struct V_90 * V_91 = & V_67 -> V_87 [ V_76 ] ;
struct V_38 * V_42 ;
V_42 = F_27 ( sizeof( * V_42 ) + strlen ( V_91 -> V_44 ) + 1 , V_83 ) ;
if ( ! V_42 ) {
error = - V_81 ;
goto V_82;
}
strcpy ( V_42 -> V_44 , V_91 -> V_44 ) ;
V_42 -> V_41 . V_44 = V_42 -> V_44 ;
V_42 -> V_48 . V_17 = V_91 -> V_17 ;
V_42 -> V_48 . V_16 = V_91 -> V_16 ;
V_42 -> V_48 . V_19 = V_91 -> V_19 ;
V_42 -> V_22 = V_91 -> V_22 ;
F_20 ( V_42 ) ;
if ( V_91 -> V_92 >= 0 )
F_29 ( V_71 -> V_71 [ V_91 -> V_92 ] ,
& V_42 -> V_41 ) ;
V_71 -> V_71 [ V_91 -> V_19 ] = & V_42 -> V_41 ;
}
F_30 ( V_73 , & V_71 -> V_84 ) ;
V_82:
F_31 ( V_73 ) ;
return error ;
}
