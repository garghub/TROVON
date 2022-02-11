int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * T_2 V_2 ,
struct V_8 * V_8 )
{
struct V_9 V_10 ;
T_3 V_11 = V_4 -> V_12 . V_13 & V_14 ;
struct V_15 * V_15 = F_2 ( V_8 , V_6 -> V_16 ,
V_6 -> V_17 ) ;
if ( V_15 == NULL ) {
F_3 ( L_1 ,
V_4 -> V_12 . type ) ;
return - 1 ;
}
F_4 ( V_15 , V_11 , V_18 , V_6 -> V_19 , & V_10 ) ;
if ( V_10 . V_20 != NULL )
V_10 . V_20 -> V_21 -> V_22 = 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6
V_2 ,
struct V_8 * V_8 )
{
struct V_15 * V_15 = F_2 ( V_8 ,
V_4 -> V_23 . V_16 ,
V_4 -> V_23 . V_17 ) ;
F_6 ( L_2 , V_4 -> V_23 . V_16 , V_4 -> V_23 . V_17 ,
V_4 -> V_23 . V_24 , V_4 -> V_23 . V_25 ) ;
if ( V_15 ) {
F_7 ( & V_15 -> V_26 , & V_8 -> V_27 ) ;
V_8 -> V_28 = NULL ;
F_8 ( V_15 ) ;
}
return 0 ;
}
int F_9 ( const T_3 * V_29 , int V_30 , char * V_31 )
{
char * V_32 = V_31 ;
const T_3 * V_33 = V_29 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_30 ; ++ V_34 ) {
sprintf ( V_32 , L_3 , * V_33 ) ;
++ V_33 ;
V_32 += 2 ;
}
return V_33 - V_29 ;
}
char * F_10 ( const struct V_21 * V_21 , char * V_31 , T_4 V_35 )
{
char V_36 [ V_37 * 2 + 1 ] ;
if ( ! V_21 -> V_38 )
return NULL ;
F_9 ( V_21 -> V_29 , sizeof( V_21 -> V_29 ) , V_36 ) ;
if ( V_31 == NULL ) {
if ( F_11 ( & V_31 , L_4 , V_39 ,
V_36 , V_36 + 2 ) < 0 )
return NULL ;
} else
snprintf ( V_31 , V_35 , L_4 , V_39 ,
V_36 , V_36 + 2 ) ;
return V_31 ;
}
static int F_12 ( const char * V_40 , T_4 V_41 , T_3 * V_29 ,
T_5 V_16 , T_6 V_13 , int V_42 )
{
int V_43 ;
struct V_44 V_45 ;
T_4 V_30 ;
V_30 = V_41 + 1 ;
V_30 = F_13 ( V_30 , V_46 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
memcpy ( & V_45 . V_29 , V_29 , V_37 ) ;
V_45 . V_16 = V_16 ;
V_45 . V_12 . V_13 = V_13 ;
V_45 . V_12 . V_35 = sizeof( V_45 ) + V_30 ;
V_43 = F_14 ( V_42 , & V_45 , sizeof( V_45 ) ) ;
if ( V_43 < 0 )
return V_43 ;
return F_15 ( V_42 , V_40 , V_41 + 1 , V_30 ) ;
}
static int F_16 ( struct V_47 * V_48 ,
struct V_8 * V_8 ,
T_5 V_16 , T_6 V_13 , int V_42 )
{
char V_49 [ V_50 ] ;
struct V_21 * V_51 ;
F_17 (pos, head) {
int V_43 ;
const char * V_40 ;
T_4 V_41 ;
if ( ! V_51 -> V_22 )
continue;
if ( F_18 ( V_51 ) ) {
V_40 = V_51 -> V_52 ;
V_41 = V_51 -> V_53 + 1 ;
} else if ( F_19 ( V_51 ) ) {
F_20 ( V_8 , V_49 , sizeof( V_49 ) ) ;
V_40 = V_49 ;
V_41 = strlen ( V_49 ) + 1 ;
} else {
V_40 = V_51 -> V_54 ;
V_41 = V_51 -> V_55 + 1 ;
}
V_43 = F_12 ( V_40 , V_41 , V_51 -> V_29 ,
V_16 , V_13 , V_42 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_21 ( struct V_8 * V_8 , int V_42 )
{
int V_43 ;
T_6 V_56 = V_57 ,
V_58 = V_59 ;
if ( ! F_22 ( V_8 ) ) {
V_56 = V_60 ;
V_58 = V_61 ;
}
V_43 = F_16 ( & V_8 -> V_62 . V_48 , V_8 ,
V_8 -> V_16 , V_56 , V_42 ) ;
if ( V_43 == 0 )
V_43 = F_16 ( & V_8 -> V_63 . V_48 ,
V_8 , V_8 -> V_16 , V_58 ,
V_42 ) ;
return V_43 ;
}
int F_23 ( struct V_64 * V_65 , int V_42 )
{
struct V_26 * V_66 ;
int V_43 = F_21 ( & V_65 -> V_67 . V_68 , V_42 ) ;
if ( V_43 )
return V_43 ;
for ( V_66 = F_24 ( & V_65 -> V_67 . V_69 ) ; V_66 ; V_66 = F_25 ( V_66 ) ) {
struct V_8 * V_51 = F_26 ( V_66 , struct V_8 , V_26 ) ;
V_43 = F_21 ( V_51 , V_42 ) ;
if ( V_43 )
break;
}
return V_43 ;
}
static int F_27 ( struct V_47 * V_48 )
{
struct V_21 * V_51 ;
F_28 (pos, head, node)
V_51 -> V_22 = true ;
return 0 ;
}
static int F_29 ( struct V_8 * V_8 )
{
int V_43 ;
V_43 = F_27 ( & V_8 -> V_62 . V_48 ) ;
if ( V_43 )
return V_43 ;
return F_27 ( & V_8 -> V_63 . V_48 ) ;
}
int F_30 ( struct V_64 * V_65 )
{
struct V_26 * V_66 ;
int V_43 ;
V_43 = F_29 ( & V_65 -> V_67 . V_68 ) ;
if ( V_43 )
return V_43 ;
for ( V_66 = F_24 ( & V_65 -> V_67 . V_69 ) ; V_66 ; V_66 = F_25 ( V_66 ) ) {
struct V_8 * V_51 = F_26 ( V_66 , struct V_8 , V_26 ) ;
V_43 = F_29 ( V_51 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
void F_31 ( void )
{
V_70 = true ;
}
int F_32 ( const char * V_71 , const char * V_72 ,
const char * V_40 , bool V_73 , bool V_74 )
{
const T_4 V_35 = V_50 ;
char * V_75 , * V_76 = F_33 ( V_35 ) ,
* V_77 = F_33 ( V_35 ) , * V_78 ;
int V_30 , V_43 = - 1 ;
bool V_79 = V_73 || V_74 ;
if ( V_73 ) {
if ( V_80 . V_81 ) {
F_34 ( L_5 ) ;
V_43 = 0 ;
goto V_82;
}
V_75 = ( char * ) V_40 ;
} else
V_75 = F_35 ( V_40 , NULL ) ;
if ( V_75 == NULL || V_76 == NULL || V_77 == NULL )
goto V_82;
V_30 = F_36 ( V_76 , V_35 , L_6 ,
V_72 , V_79 ? L_7 : L_8 ,
V_74 ? V_83 : V_75 ) ;
if ( F_37 ( V_76 , 0755 ) )
goto V_82;
snprintf ( V_76 + V_30 , V_35 - V_30 , L_9 , V_71 ) ;
if ( F_38 ( V_76 , V_84 ) ) {
if ( V_73 ) {
if ( F_39 ( L_10 , V_76 ) )
goto V_82;
} else if ( F_40 ( V_75 , V_76 ) && F_39 ( V_40 , V_76 ) )
goto V_82;
}
V_30 = F_36 ( V_77 , V_35 , L_11 ,
V_72 , V_71 ) ;
if ( F_38 ( V_77 , V_85 ) && F_37 ( V_77 , 0755 ) )
goto V_82;
snprintf ( V_77 + V_30 , V_35 - V_30 , L_9 , V_71 + 2 ) ;
V_78 = V_76 + strlen ( V_72 ) - 5 ;
memcpy ( V_78 , L_12 , 5 ) ;
if ( F_41 ( V_78 , V_77 ) == 0 )
V_43 = 0 ;
V_82:
if ( ! V_73 )
free ( V_75 ) ;
free ( V_76 ) ;
free ( V_77 ) ;
return V_43 ;
}
static int F_42 ( const T_3 * V_29 , T_4 V_86 ,
const char * V_40 , const char * V_72 ,
bool V_73 , bool V_74 )
{
char V_71 [ V_37 * 2 + 1 ] ;
F_9 ( V_29 , V_86 , V_71 ) ;
return F_32 ( V_71 , V_72 , V_40 ,
V_73 , V_74 ) ;
}
int F_43 ( const char * V_71 , const char * V_72 )
{
const T_4 V_35 = V_50 ;
char * V_76 = F_33 ( V_35 ) ,
* V_77 = F_33 ( V_35 ) ;
int V_43 = - 1 ;
if ( V_76 == NULL || V_77 == NULL )
goto V_82;
snprintf ( V_77 , V_35 , L_4 ,
V_72 , V_71 , V_71 + 2 ) ;
if ( F_38 ( V_77 , V_84 ) )
goto V_82;
if ( F_44 ( V_77 , V_76 , V_35 - 1 ) < 0 )
goto V_82;
if ( F_45 ( V_77 ) )
goto V_82;
snprintf ( V_77 , V_35 , L_4 ,
V_72 , V_71 , V_76 ) ;
if ( F_45 ( V_77 ) )
goto V_82;
V_43 = 0 ;
V_82:
free ( V_76 ) ;
free ( V_77 ) ;
return V_43 ;
}
static int F_46 ( struct V_21 * V_21 , struct V_8 * V_8 ,
const char * V_72 )
{
bool V_73 = V_21 -> V_87 && V_21 -> V_54 [ 0 ] != '/' ;
bool V_74 = F_18 ( V_21 ) ;
const char * V_40 = V_21 -> V_54 ;
char V_49 [ V_50 ] ;
if ( F_19 ( V_21 ) ) {
V_73 = true ;
F_20 ( V_8 , V_49 , sizeof( V_49 ) ) ;
V_40 = V_49 ;
}
return F_42 ( V_21 -> V_29 , sizeof( V_21 -> V_29 ) , V_40 ,
V_72 , V_73 , V_74 ) ;
}
static int F_47 ( struct V_47 * V_48 ,
struct V_8 * V_8 , const char * V_72 )
{
struct V_21 * V_51 ;
int V_43 = 0 ;
F_17 (pos, head)
if ( F_46 ( V_51 , V_8 , V_72 ) )
V_43 = - 1 ;
return V_43 ;
}
static int F_48 ( struct V_8 * V_8 , const char * V_72 )
{
int V_88 = F_47 ( & V_8 -> V_62 . V_48 , V_8 ,
V_72 ) ;
V_88 |= F_47 ( & V_8 -> V_63 . V_48 , V_8 ,
V_72 ) ;
return V_88 ;
}
int F_49 ( struct V_64 * V_65 )
{
struct V_26 * V_66 ;
int V_88 ;
if ( V_70 )
return 0 ;
if ( F_50 ( V_39 , 0755 ) != 0 && V_89 != V_90 )
return - 1 ;
V_88 = F_48 ( & V_65 -> V_67 . V_68 , V_39 ) ;
for ( V_66 = F_24 ( & V_65 -> V_67 . V_69 ) ; V_66 ; V_66 = F_25 ( V_66 ) ) {
struct V_8 * V_51 = F_26 ( V_66 , struct V_8 , V_26 ) ;
V_88 |= F_48 ( V_51 , V_39 ) ;
}
return V_88 ? - 1 : 0 ;
}
static bool F_51 ( struct V_8 * V_8 , bool V_91 )
{
bool V_88 ;
V_88 = F_52 ( & V_8 -> V_62 . V_48 , V_91 ) ;
V_88 |= F_52 ( & V_8 -> V_63 . V_48 , V_91 ) ;
return V_88 ;
}
bool F_53 ( struct V_64 * V_65 , bool V_91 )
{
struct V_26 * V_66 ;
bool V_88 = F_51 ( & V_65 -> V_67 . V_68 , V_91 ) ;
for ( V_66 = F_24 ( & V_65 -> V_67 . V_69 ) ; V_66 ; V_66 = F_25 ( V_66 ) ) {
struct V_8 * V_51 = F_26 ( V_66 , struct V_8 , V_26 ) ;
V_88 |= F_51 ( V_51 , V_91 ) ;
}
return V_88 ;
}
