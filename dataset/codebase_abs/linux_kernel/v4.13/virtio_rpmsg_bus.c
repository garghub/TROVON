static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 ,
V_4 ) ;
F_3 ( V_3 ) ;
}
static struct V_2 * F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_1 V_9 ,
void * V_10 , T_2 V_11 )
{
int V_12 , V_13 , V_14 ;
struct V_2 * V_3 ;
struct V_15 * V_16 = V_8 ? & V_8 -> V_16 : & V_6 -> V_17 -> V_16 ;
V_3 = F_5 ( sizeof( * V_3 ) , V_18 ) ;
if ( ! V_3 )
return NULL ;
F_6 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_19 ) ;
V_3 -> V_8 = V_8 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_20 = & V_21 ;
if ( V_11 == V_22 ) {
V_12 = V_23 ;
V_13 = 0 ;
} else {
V_12 = V_11 ;
V_13 = V_11 + 1 ;
}
F_8 ( & V_6 -> V_24 ) ;
V_14 = F_9 ( & V_6 -> V_25 , V_3 , V_12 , V_13 , V_18 ) ;
if ( V_14 < 0 ) {
F_10 ( V_16 , L_1 , V_14 ) ;
goto V_26;
}
V_3 -> V_11 = V_14 ;
F_11 ( & V_6 -> V_24 ) ;
return V_3 ;
V_26:
F_11 ( & V_6 -> V_24 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
return NULL ;
}
static struct V_2 * F_13 ( struct V_7 * V_8 ,
T_1 V_9 ,
void * V_10 ,
struct V_27 V_28 )
{
struct V_29 * V_30 = F_14 ( V_8 ) ;
return F_4 ( V_30 -> V_6 , V_8 , V_9 , V_10 , V_28 . V_31 ) ;
}
static void
F_15 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_8 ( & V_6 -> V_24 ) ;
F_16 ( & V_6 -> V_25 , V_3 -> V_11 ) ;
F_11 ( & V_6 -> V_24 ) ;
F_8 ( & V_3 -> V_19 ) ;
V_3 -> V_9 = NULL ;
F_11 ( & V_3 -> V_19 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = F_14 ( V_3 -> V_8 ) ;
F_15 ( V_30 -> V_6 , V_3 ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_15 * V_16 = & V_8 -> V_16 ;
int V_32 = 0 ;
if ( V_8 -> V_33 && V_8 -> V_3 &&
F_19 ( V_6 -> V_17 , V_34 ) ) {
struct V_35 V_36 ;
strncpy ( V_36 . V_37 , V_8 -> V_14 . V_37 , V_38 ) ;
V_36 . V_11 = V_8 -> V_3 -> V_11 ;
V_36 . V_39 = V_40 ;
V_32 = F_20 ( V_8 -> V_3 , & V_36 , sizeof( V_36 ) , V_41 ) ;
if ( V_32 )
F_10 ( V_16 , L_2 , V_32 ) ;
}
return V_32 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_15 * V_16 = & V_8 -> V_16 ;
int V_32 = 0 ;
if ( V_8 -> V_33 && V_8 -> V_3 &&
F_19 ( V_6 -> V_17 , V_34 ) ) {
struct V_35 V_36 ;
strncpy ( V_36 . V_37 , V_8 -> V_14 . V_37 , V_38 ) ;
V_36 . V_11 = V_8 -> V_3 -> V_11 ;
V_36 . V_39 = V_42 ;
V_32 = F_20 ( V_8 -> V_3 , & V_36 , sizeof( V_36 ) , V_41 ) ;
if ( V_32 )
F_10 ( V_16 , L_2 , V_32 ) ;
}
return V_32 ;
}
static void F_22 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_23 ( V_16 ) ;
struct V_29 * V_30 = F_14 ( V_8 ) ;
F_3 ( V_30 ) ;
}
static struct V_7 * F_24 ( struct V_5 * V_6 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_7 * V_8 ;
struct V_15 * V_43 , * V_16 = & V_6 -> V_17 -> V_16 ;
int V_44 ;
V_43 = F_25 ( V_16 , V_28 ) ;
if ( V_43 ) {
F_26 ( V_43 ) ;
F_10 ( V_16 , L_3 ,
V_28 -> V_37 , V_28 -> V_31 , V_28 -> V_45 ) ;
return NULL ;
}
V_30 = F_5 ( sizeof( * V_30 ) , V_18 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_6 = V_6 ;
V_8 = & V_30 -> V_8 ;
V_8 -> V_31 = V_28 -> V_31 ;
V_8 -> V_45 = V_28 -> V_45 ;
V_8 -> V_20 = & V_46 ;
V_8 -> V_33 = V_8 -> V_31 != V_22 ;
strncpy ( V_8 -> V_14 . V_37 , V_28 -> V_37 , V_38 ) ;
V_8 -> V_16 . V_47 = & V_6 -> V_17 -> V_16 ;
V_8 -> V_16 . V_48 = F_22 ;
V_44 = F_27 ( V_8 ) ;
if ( V_44 )
return NULL ;
return V_8 ;
}
static void * F_28 ( struct V_5 * V_6 )
{
unsigned int V_49 ;
void * V_44 ;
F_8 ( & V_6 -> V_50 ) ;
if ( V_6 -> V_51 < V_6 -> V_52 / 2 )
V_44 = V_6 -> V_53 + V_54 * V_6 -> V_51 ++ ;
else
V_44 = F_29 ( V_6 -> V_55 , & V_49 ) ;
F_11 ( & V_6 -> V_50 ) ;
return V_44 ;
}
static void F_30 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_50 ) ;
if ( F_31 ( & V_6 -> V_56 ) == 1 )
F_32 ( V_6 -> V_55 ) ;
F_11 ( & V_6 -> V_50 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_50 ) ;
if ( F_34 ( & V_6 -> V_56 ) )
F_35 ( V_6 -> V_55 ) ;
F_11 ( & V_6 -> V_50 ) ;
}
static int F_36 ( struct V_7 * V_8 ,
T_2 V_31 , T_2 V_45 ,
void * V_57 , int V_49 , bool V_58 )
{
struct V_29 * V_30 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_15 * V_16 = & V_8 -> V_16 ;
struct V_59 V_60 ;
struct V_61 * V_62 ;
int V_32 ;
if ( V_31 == V_22 || V_45 == V_22 ) {
F_10 ( V_16 , L_4 , V_31 , V_45 ) ;
return - V_63 ;
}
if ( V_49 > V_54 - sizeof( struct V_61 ) ) {
F_10 ( V_16 , L_5 , V_49 ) ;
return - V_64 ;
}
V_62 = F_28 ( V_6 ) ;
if ( ! V_62 && ! V_58 )
return - V_65 ;
while ( ! V_62 ) {
F_30 ( V_6 ) ;
V_32 = F_37 ( V_6 -> V_66 ,
( V_62 = F_28 ( V_6 ) ) ,
F_38 ( 15000 ) ) ;
F_33 ( V_6 ) ;
if ( ! V_32 ) {
F_10 ( V_16 , L_6 ) ;
return - V_67 ;
}
}
V_62 -> V_49 = V_49 ;
V_62 -> V_39 = 0 ;
V_62 -> V_31 = V_31 ;
V_62 -> V_45 = V_45 ;
V_62 -> V_68 = 0 ;
memcpy ( V_62 -> V_57 , V_57 , V_49 ) ;
F_39 ( V_16 , L_7 ,
V_62 -> V_31 , V_62 -> V_45 , V_62 -> V_49 , V_62 -> V_39 , V_62 -> V_68 ) ;
#if F_40 ( V_69 )
F_41 ( L_8 , V_70 , 16 , 1 ,
V_62 , sizeof( * V_62 ) + V_62 -> V_49 , true ) ;
#endif
F_42 ( & V_60 , V_62 , sizeof( * V_62 ) + V_49 ) ;
F_8 ( & V_6 -> V_50 ) ;
V_32 = F_43 ( V_6 -> V_55 , & V_60 , 1 , V_62 , V_18 ) ;
if ( V_32 ) {
F_10 ( V_16 , L_9 , V_32 ) ;
goto V_71;
}
F_44 ( V_6 -> V_55 ) ;
V_71:
F_11 ( & V_6 -> V_50 ) ;
return V_32 ;
}
static int F_45 ( struct V_2 * V_3 , void * V_57 , int V_49 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 , V_45 = V_8 -> V_45 ;
return F_36 ( V_8 , V_31 , V_45 , V_57 , V_49 , true ) ;
}
static int F_46 ( struct V_2 * V_3 , void * V_57 , int V_49 ,
T_2 V_45 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 ;
return F_36 ( V_8 , V_31 , V_45 , V_57 , V_49 , true ) ;
}
static int F_47 ( struct V_2 * V_3 , T_2 V_31 ,
T_2 V_45 , void * V_57 , int V_49 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
return F_36 ( V_8 , V_31 , V_45 , V_57 , V_49 , true ) ;
}
static int F_48 ( struct V_2 * V_3 , void * V_57 , int V_49 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 , V_45 = V_8 -> V_45 ;
return F_36 ( V_8 , V_31 , V_45 , V_57 , V_49 , false ) ;
}
static int F_49 ( struct V_2 * V_3 , void * V_57 ,
int V_49 , T_2 V_45 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 ;
return F_36 ( V_8 , V_31 , V_45 , V_57 , V_49 , false ) ;
}
static int F_50 ( struct V_2 * V_3 , T_2 V_31 ,
T_2 V_45 , void * V_57 , int V_49 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
return F_36 ( V_8 , V_31 , V_45 , V_57 , V_49 , false ) ;
}
static int F_51 ( struct V_5 * V_6 , struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int V_49 )
{
struct V_2 * V_3 ;
struct V_59 V_60 ;
int V_32 ;
F_39 ( V_16 , L_10 ,
V_62 -> V_31 , V_62 -> V_45 , V_62 -> V_49 , V_62 -> V_39 , V_62 -> V_68 ) ;
#if F_40 ( V_69 )
F_41 ( L_11 , V_70 , 16 , 1 ,
V_62 , sizeof( * V_62 ) + V_62 -> V_49 , true ) ;
#endif
if ( V_49 > V_54 ||
V_62 -> V_49 > ( V_49 - sizeof( struct V_61 ) ) ) {
F_52 ( V_16 , L_12 , V_49 , V_62 -> V_49 ) ;
return - V_63 ;
}
F_8 ( & V_6 -> V_24 ) ;
V_3 = F_53 ( & V_6 -> V_25 , V_62 -> V_45 ) ;
if ( V_3 )
F_54 ( & V_3 -> V_4 ) ;
F_11 ( & V_6 -> V_24 ) ;
if ( V_3 ) {
F_8 ( & V_3 -> V_19 ) ;
if ( V_3 -> V_9 )
V_3 -> V_9 ( V_3 -> V_8 , V_62 -> V_57 , V_62 -> V_49 , V_3 -> V_10 ,
V_62 -> V_31 ) ;
F_11 ( & V_3 -> V_19 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
} else
F_52 ( V_16 , L_13 ) ;
F_42 ( & V_60 , V_62 , V_54 ) ;
V_32 = F_55 ( V_6 -> V_72 , & V_60 , 1 , V_62 , V_18 ) ;
if ( V_32 < 0 ) {
F_10 ( V_16 , L_14 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
static void F_56 ( struct V_73 * V_72 )
{
struct V_5 * V_6 = V_72 -> V_17 -> V_10 ;
struct V_15 * V_16 = & V_72 -> V_17 -> V_16 ;
struct V_61 * V_62 ;
unsigned int V_49 , V_74 = 0 ;
int V_32 ;
V_62 = F_29 ( V_72 , & V_49 ) ;
if ( ! V_62 ) {
F_10 ( V_16 , L_15 ) ;
return;
}
while ( V_62 ) {
V_32 = F_51 ( V_6 , V_16 , V_62 , V_49 ) ;
if ( V_32 )
break;
V_74 ++ ;
V_62 = F_29 ( V_72 , & V_49 ) ;
}
F_39 ( V_16 , L_16 , V_74 ) ;
if ( V_74 )
F_44 ( V_6 -> V_72 ) ;
}
static void F_57 ( struct V_73 * V_55 )
{
struct V_5 * V_6 = V_55 -> V_17 -> V_10 ;
F_39 ( & V_55 -> V_17 -> V_16 , L_17 , V_75 ) ;
F_58 ( & V_6 -> V_66 ) ;
}
static int F_59 ( struct V_7 * V_8 , void * V_57 , int V_49 ,
void * V_10 , T_2 V_31 )
{
struct V_35 * V_62 = V_57 ;
struct V_7 * V_76 ;
struct V_27 V_28 ;
struct V_5 * V_6 = V_10 ;
struct V_15 * V_16 = & V_6 -> V_17 -> V_16 ;
int V_44 ;
#if F_40 ( V_69 )
F_41 ( L_18 , V_70 , 16 , 1 ,
V_57 , V_49 , true ) ;
#endif
if ( V_49 != sizeof( * V_62 ) ) {
F_10 ( V_16 , L_19 , V_49 ) ;
return - V_63 ;
}
if ( V_8 ) {
F_10 ( V_16 , L_20 ) ;
return - V_63 ;
}
V_62 -> V_37 [ V_38 - 1 ] = '\0' ;
F_60 ( V_16 , L_21 ,
V_62 -> V_39 & V_42 ? L_22 : L_23 ,
V_62 -> V_37 , V_62 -> V_11 ) ;
strncpy ( V_28 . V_37 , V_62 -> V_37 , sizeof( V_28 . V_37 ) ) ;
V_28 . V_31 = V_22 ;
V_28 . V_45 = V_62 -> V_11 ;
if ( V_62 -> V_39 & V_42 ) {
V_44 = F_61 ( & V_6 -> V_17 -> V_16 , & V_28 ) ;
if ( V_44 )
F_10 ( V_16 , L_24 , V_44 ) ;
} else {
V_76 = F_24 ( V_6 , & V_28 ) ;
if ( ! V_76 )
F_10 ( V_16 , L_25 ) ;
}
return 0 ;
}
static int F_62 ( struct V_77 * V_17 )
{
T_3 * V_78 [] = { F_56 , F_57 } ;
static const char * const V_79 [] = { L_26 , L_27 } ;
struct V_73 * V_80 [ 2 ] ;
struct V_5 * V_6 ;
void * V_81 ;
int V_32 = 0 , V_82 ;
T_4 V_83 ;
bool V_84 ;
V_6 = F_5 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return - V_65 ;
V_6 -> V_17 = V_17 ;
F_63 ( & V_6 -> V_25 ) ;
F_7 ( & V_6 -> V_24 ) ;
F_7 ( & V_6 -> V_50 ) ;
F_64 ( & V_6 -> V_66 ) ;
V_32 = F_65 ( V_17 , 2 , V_80 , V_78 , V_79 , NULL ) ;
if ( V_32 )
goto V_85;
V_6 -> V_72 = V_80 [ 0 ] ;
V_6 -> V_55 = V_80 [ 1 ] ;
F_66 ( F_67 ( V_6 -> V_72 ) !=
F_67 ( V_6 -> V_55 ) ) ;
if ( F_67 ( V_6 -> V_72 ) < V_86 / 2 )
V_6 -> V_52 = F_67 ( V_6 -> V_72 ) * 2 ;
else
V_6 -> V_52 = V_86 ;
V_83 = V_6 -> V_52 * V_54 ;
V_81 = F_68 ( V_17 -> V_16 . V_47 -> V_47 ,
V_83 , & V_6 -> V_87 ,
V_18 ) ;
if ( ! V_81 ) {
V_32 = - V_65 ;
goto V_88;
}
F_39 ( & V_17 -> V_16 , L_28 ,
V_81 , & V_6 -> V_87 ) ;
V_6 -> V_89 = V_81 ;
V_6 -> V_53 = V_81 + V_83 / 2 ;
for ( V_82 = 0 ; V_82 < V_6 -> V_52 / 2 ; V_82 ++ ) {
struct V_59 V_60 ;
void * V_90 = V_6 -> V_89 + V_82 * V_54 ;
F_42 ( & V_60 , V_90 , V_54 ) ;
V_32 = F_55 ( V_6 -> V_72 , & V_60 , 1 , V_90 ,
V_18 ) ;
F_66 ( V_32 ) ;
}
F_35 ( V_6 -> V_55 ) ;
V_17 -> V_10 = V_6 ;
if ( F_19 ( V_17 , V_34 ) ) {
V_6 -> V_91 = F_4 ( V_6 , NULL , F_59 ,
V_6 , V_41 ) ;
if ( ! V_6 -> V_91 ) {
F_10 ( & V_17 -> V_16 , L_29 ) ;
V_32 = - V_65 ;
goto V_92;
}
}
V_84 = F_69 ( V_6 -> V_72 ) ;
F_70 ( V_17 ) ;
if ( V_84 )
F_71 ( V_6 -> V_72 ) ;
F_60 ( & V_17 -> V_16 , L_30 ) ;
return 0 ;
V_92:
F_72 ( V_17 -> V_16 . V_47 -> V_47 , V_83 ,
V_81 , V_6 -> V_87 ) ;
V_88:
V_17 -> V_93 -> V_94 ( V_6 -> V_17 ) ;
V_85:
F_3 ( V_6 ) ;
return V_32 ;
}
static int F_73 ( struct V_15 * V_16 , void * V_57 )
{
F_74 ( V_16 ) ;
return 0 ;
}
static void F_75 ( struct V_77 * V_17 )
{
struct V_5 * V_6 = V_17 -> V_10 ;
T_4 V_83 = V_6 -> V_52 * V_54 ;
int V_44 ;
V_17 -> V_93 -> V_95 ( V_17 ) ;
V_44 = F_76 ( & V_17 -> V_16 , NULL , F_73 ) ;
if ( V_44 )
F_52 ( & V_17 -> V_16 , L_31 , V_44 ) ;
if ( V_6 -> V_91 )
F_15 ( V_6 , V_6 -> V_91 ) ;
F_77 ( & V_6 -> V_25 ) ;
V_17 -> V_93 -> V_94 ( V_6 -> V_17 ) ;
F_72 ( V_17 -> V_16 . V_47 -> V_47 , V_83 ,
V_6 -> V_89 , V_6 -> V_87 ) ;
F_3 ( V_6 ) ;
}
static int T_5 F_78 ( void )
{
int V_44 ;
V_44 = F_79 ( & V_96 ) ;
if ( V_44 )
F_80 ( L_32 , V_44 ) ;
return V_44 ;
}
static void T_6 F_81 ( void )
{
F_82 ( & V_96 ) ;
}
