static void
F_1 ( struct V_1 * V_2 , void * V_3 , unsigned int V_4 )
{
if ( F_2 ( V_3 ) ) {
F_3 ( V_2 , 1 ) ;
F_4 ( V_2 , F_5 ( V_3 ) , V_4 ,
F_6 ( V_3 ) ) ;
} else {
F_7 ( ! F_8 ( V_3 ) ) ;
F_9 ( V_2 , V_3 , V_4 ) ;
}
}
static void F_10 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_11 ( V_5 , struct V_6 ,
V_8 ) ;
F_12 ( V_7 ) ;
}
static struct V_6 * F_13 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
T_1 V_13 ,
void * V_14 , T_2 V_15 )
{
int V_16 , V_17 , V_18 ;
struct V_6 * V_7 ;
struct V_19 * V_20 = V_12 ? & V_12 -> V_20 : & V_10 -> V_21 -> V_20 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 )
return NULL ;
F_15 ( & V_7 -> V_8 ) ;
F_16 ( & V_7 -> V_23 ) ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_24 = & V_25 ;
if ( V_15 == V_26 ) {
V_16 = V_27 ;
V_17 = 0 ;
} else {
V_16 = V_15 ;
V_17 = V_15 + 1 ;
}
F_17 ( & V_10 -> V_28 ) ;
V_18 = F_18 ( & V_10 -> V_29 , V_7 , V_16 , V_17 , V_22 ) ;
if ( V_18 < 0 ) {
F_19 ( V_20 , L_1 , V_18 ) ;
goto V_30;
}
V_7 -> V_15 = V_18 ;
F_20 ( & V_10 -> V_28 ) ;
return V_7 ;
V_30:
F_20 ( & V_10 -> V_28 ) ;
F_21 ( & V_7 -> V_8 , F_10 ) ;
return NULL ;
}
static struct V_6 * F_22 ( struct V_11 * V_12 ,
T_1 V_13 ,
void * V_14 ,
struct V_31 V_32 )
{
struct V_33 * V_34 = F_23 ( V_12 ) ;
return F_13 ( V_34 -> V_10 , V_12 , V_13 , V_14 , V_32 . V_35 ) ;
}
static void
F_24 ( struct V_9 * V_10 , struct V_6 * V_7 )
{
F_17 ( & V_10 -> V_28 ) ;
F_25 ( & V_10 -> V_29 , V_7 -> V_15 ) ;
F_20 ( & V_10 -> V_28 ) ;
F_17 ( & V_7 -> V_23 ) ;
V_7 -> V_13 = NULL ;
F_20 ( & V_7 -> V_23 ) ;
F_21 ( & V_7 -> V_8 , F_10 ) ;
}
static void F_26 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = F_23 ( V_7 -> V_12 ) ;
F_24 ( V_34 -> V_10 , V_7 ) ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = F_23 ( V_12 ) ;
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_19 * V_20 = & V_12 -> V_20 ;
int V_36 = 0 ;
if ( V_12 -> V_37 && V_12 -> V_7 &&
F_28 ( V_10 -> V_21 , V_38 ) ) {
struct V_39 V_40 ;
strncpy ( V_40 . V_41 , V_12 -> V_18 . V_41 , V_42 ) ;
V_40 . V_15 = V_12 -> V_7 -> V_15 ;
V_40 . V_43 = V_44 ;
V_36 = F_29 ( V_12 -> V_7 , & V_40 , sizeof( V_40 ) , V_45 ) ;
if ( V_36 )
F_19 ( V_20 , L_2 , V_36 ) ;
}
return V_36 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = F_23 ( V_12 ) ;
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_19 * V_20 = & V_12 -> V_20 ;
int V_36 = 0 ;
if ( V_12 -> V_37 && V_12 -> V_7 &&
F_28 ( V_10 -> V_21 , V_38 ) ) {
struct V_39 V_40 ;
strncpy ( V_40 . V_41 , V_12 -> V_18 . V_41 , V_42 ) ;
V_40 . V_15 = V_12 -> V_7 -> V_15 ;
V_40 . V_43 = V_46 ;
V_36 = F_29 ( V_12 -> V_7 , & V_40 , sizeof( V_40 ) , V_45 ) ;
if ( V_36 )
F_19 ( V_20 , L_2 , V_36 ) ;
}
return V_36 ;
}
static void F_31 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_32 ( V_20 ) ;
struct V_33 * V_34 = F_23 ( V_12 ) ;
F_12 ( V_34 ) ;
}
static struct V_11 * F_33 ( struct V_9 * V_10 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_11 * V_12 ;
struct V_19 * V_47 , * V_20 = & V_10 -> V_21 -> V_20 ;
int V_48 ;
V_47 = F_34 ( V_20 , V_32 ) ;
if ( V_47 ) {
F_35 ( V_47 ) ;
F_19 ( V_20 , L_3 ,
V_32 -> V_41 , V_32 -> V_35 , V_32 -> V_49 ) ;
return NULL ;
}
V_34 = F_14 ( sizeof( * V_34 ) , V_22 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_10 = V_10 ;
V_12 = & V_34 -> V_12 ;
V_12 -> V_35 = V_32 -> V_35 ;
V_12 -> V_49 = V_32 -> V_49 ;
V_12 -> V_24 = & V_50 ;
V_12 -> V_37 = V_12 -> V_35 != V_26 ;
strncpy ( V_12 -> V_18 . V_41 , V_32 -> V_41 , V_42 ) ;
V_12 -> V_20 . V_51 = & V_10 -> V_21 -> V_20 ;
V_12 -> V_20 . V_52 = F_31 ;
V_48 = F_36 ( V_12 ) ;
if ( V_48 )
return NULL ;
return V_12 ;
}
static void * F_37 ( struct V_9 * V_10 )
{
unsigned int V_4 ;
void * V_48 ;
F_17 ( & V_10 -> V_53 ) ;
if ( V_10 -> V_54 < V_10 -> V_55 / 2 )
V_48 = V_10 -> V_56 + V_10 -> V_57 * V_10 -> V_54 ++ ;
else
V_48 = F_38 ( V_10 -> V_58 , & V_4 ) ;
F_20 ( & V_10 -> V_53 ) ;
return V_48 ;
}
static void F_39 ( struct V_9 * V_10 )
{
F_17 ( & V_10 -> V_53 ) ;
if ( F_40 ( & V_10 -> V_59 ) == 1 )
F_41 ( V_10 -> V_58 ) ;
F_20 ( & V_10 -> V_53 ) ;
}
static void F_42 ( struct V_9 * V_10 )
{
F_17 ( & V_10 -> V_53 ) ;
if ( F_43 ( & V_10 -> V_59 ) )
F_44 ( V_10 -> V_58 ) ;
F_20 ( & V_10 -> V_53 ) ;
}
static int F_45 ( struct V_11 * V_12 ,
T_2 V_35 , T_2 V_49 ,
void * V_60 , int V_4 , bool V_61 )
{
struct V_33 * V_34 = F_23 ( V_12 ) ;
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_19 * V_20 = & V_12 -> V_20 ;
struct V_1 V_2 ;
struct V_62 * V_63 ;
int V_36 ;
if ( V_35 == V_26 || V_49 == V_26 ) {
F_19 ( V_20 , L_4 , V_35 , V_49 ) ;
return - V_64 ;
}
if ( V_4 > V_10 -> V_57 - sizeof( struct V_62 ) ) {
F_19 ( V_20 , L_5 , V_4 ) ;
return - V_65 ;
}
V_63 = F_37 ( V_10 ) ;
if ( ! V_63 && ! V_61 )
return - V_66 ;
while ( ! V_63 ) {
F_39 ( V_10 ) ;
V_36 = F_46 ( V_10 -> V_67 ,
( V_63 = F_37 ( V_10 ) ) ,
F_47 ( 15000 ) ) ;
F_42 ( V_10 ) ;
if ( ! V_36 ) {
F_19 ( V_20 , L_6 ) ;
return - V_68 ;
}
}
V_63 -> V_4 = V_4 ;
V_63 -> V_43 = 0 ;
V_63 -> V_35 = V_35 ;
V_63 -> V_49 = V_49 ;
V_63 -> V_69 = 0 ;
memcpy ( V_63 -> V_60 , V_60 , V_4 ) ;
F_48 ( V_20 , L_7 ,
V_63 -> V_35 , V_63 -> V_49 , V_63 -> V_4 , V_63 -> V_43 , V_63 -> V_69 ) ;
#if F_49 ( V_70 )
F_50 ( L_8 , V_71 , 16 , 1 ,
V_63 , sizeof( * V_63 ) + V_63 -> V_4 , true ) ;
#endif
F_1 ( & V_2 , V_63 , sizeof( * V_63 ) + V_4 ) ;
F_17 ( & V_10 -> V_53 ) ;
V_36 = F_51 ( V_10 -> V_58 , & V_2 , 1 , V_63 , V_22 ) ;
if ( V_36 ) {
F_19 ( V_20 , L_9 , V_36 ) ;
goto V_72;
}
F_52 ( V_10 -> V_58 ) ;
V_72:
F_20 ( & V_10 -> V_53 ) ;
return V_36 ;
}
static int F_53 ( struct V_6 * V_7 , void * V_60 , int V_4 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_2 V_35 = V_7 -> V_15 , V_49 = V_12 -> V_49 ;
return F_45 ( V_12 , V_35 , V_49 , V_60 , V_4 , true ) ;
}
static int F_54 ( struct V_6 * V_7 , void * V_60 , int V_4 ,
T_2 V_49 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_2 V_35 = V_7 -> V_15 ;
return F_45 ( V_12 , V_35 , V_49 , V_60 , V_4 , true ) ;
}
static int F_55 ( struct V_6 * V_7 , T_2 V_35 ,
T_2 V_49 , void * V_60 , int V_4 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
return F_45 ( V_12 , V_35 , V_49 , V_60 , V_4 , true ) ;
}
static int F_56 ( struct V_6 * V_7 , void * V_60 , int V_4 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_2 V_35 = V_7 -> V_15 , V_49 = V_12 -> V_49 ;
return F_45 ( V_12 , V_35 , V_49 , V_60 , V_4 , false ) ;
}
static int F_57 ( struct V_6 * V_7 , void * V_60 ,
int V_4 , T_2 V_49 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_2 V_35 = V_7 -> V_15 ;
return F_45 ( V_12 , V_35 , V_49 , V_60 , V_4 , false ) ;
}
static int F_58 ( struct V_6 * V_7 , T_2 V_35 ,
T_2 V_49 , void * V_60 , int V_4 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
return F_45 ( V_12 , V_35 , V_49 , V_60 , V_4 , false ) ;
}
static int F_59 ( struct V_9 * V_10 , struct V_19 * V_20 ,
struct V_62 * V_63 , unsigned int V_4 )
{
struct V_6 * V_7 ;
struct V_1 V_2 ;
int V_36 ;
F_48 ( V_20 , L_10 ,
V_63 -> V_35 , V_63 -> V_49 , V_63 -> V_4 , V_63 -> V_43 , V_63 -> V_69 ) ;
#if F_49 ( V_70 )
F_50 ( L_11 , V_71 , 16 , 1 ,
V_63 , sizeof( * V_63 ) + V_63 -> V_4 , true ) ;
#endif
if ( V_4 > V_10 -> V_57 ||
V_63 -> V_4 > ( V_4 - sizeof( struct V_62 ) ) ) {
F_60 ( V_20 , L_12 , V_4 , V_63 -> V_4 ) ;
return - V_64 ;
}
F_17 ( & V_10 -> V_28 ) ;
V_7 = F_61 ( & V_10 -> V_29 , V_63 -> V_49 ) ;
if ( V_7 )
F_62 ( & V_7 -> V_8 ) ;
F_20 ( & V_10 -> V_28 ) ;
if ( V_7 ) {
F_17 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_13 )
V_7 -> V_13 ( V_7 -> V_12 , V_63 -> V_60 , V_63 -> V_4 , V_7 -> V_14 ,
V_63 -> V_35 ) ;
F_20 ( & V_7 -> V_23 ) ;
F_21 ( & V_7 -> V_8 , F_10 ) ;
} else
F_60 ( V_20 , L_13 ) ;
F_1 ( & V_2 , V_63 , V_10 -> V_57 ) ;
V_36 = F_63 ( V_10 -> V_73 , & V_2 , 1 , V_63 , V_22 ) ;
if ( V_36 < 0 ) {
F_19 ( V_20 , L_14 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static void F_64 ( struct V_74 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_21 -> V_14 ;
struct V_19 * V_20 = & V_73 -> V_21 -> V_20 ;
struct V_62 * V_63 ;
unsigned int V_4 , V_75 = 0 ;
int V_36 ;
V_63 = F_38 ( V_73 , & V_4 ) ;
if ( ! V_63 ) {
F_19 ( V_20 , L_15 ) ;
return;
}
while ( V_63 ) {
V_36 = F_59 ( V_10 , V_20 , V_63 , V_4 ) ;
if ( V_36 )
break;
V_75 ++ ;
V_63 = F_38 ( V_73 , & V_4 ) ;
}
F_48 ( V_20 , L_16 , V_75 ) ;
if ( V_75 )
F_52 ( V_10 -> V_73 ) ;
}
static void F_65 ( struct V_74 * V_58 )
{
struct V_9 * V_10 = V_58 -> V_21 -> V_14 ;
F_48 ( & V_58 -> V_21 -> V_20 , L_17 , V_76 ) ;
F_66 ( & V_10 -> V_67 ) ;
}
static int F_67 ( struct V_11 * V_12 , void * V_60 , int V_4 ,
void * V_14 , T_2 V_35 )
{
struct V_39 * V_63 = V_60 ;
struct V_11 * V_77 ;
struct V_31 V_32 ;
struct V_9 * V_10 = V_14 ;
struct V_19 * V_20 = & V_10 -> V_21 -> V_20 ;
int V_48 ;
#if F_49 ( V_70 )
F_50 ( L_18 , V_71 , 16 , 1 ,
V_60 , V_4 , true ) ;
#endif
if ( V_4 != sizeof( * V_63 ) ) {
F_19 ( V_20 , L_19 , V_4 ) ;
return - V_64 ;
}
if ( V_12 ) {
F_19 ( V_20 , L_20 ) ;
return - V_64 ;
}
V_63 -> V_41 [ V_42 - 1 ] = '\0' ;
F_68 ( V_20 , L_21 ,
V_63 -> V_43 & V_46 ? L_22 : L_23 ,
V_63 -> V_41 , V_63 -> V_15 ) ;
strncpy ( V_32 . V_41 , V_63 -> V_41 , sizeof( V_32 . V_41 ) ) ;
V_32 . V_35 = V_26 ;
V_32 . V_49 = V_63 -> V_15 ;
if ( V_63 -> V_43 & V_46 ) {
V_48 = F_69 ( & V_10 -> V_21 -> V_20 , & V_32 ) ;
if ( V_48 )
F_19 ( V_20 , L_24 , V_48 ) ;
} else {
V_77 = F_33 ( V_10 , & V_32 ) ;
if ( ! V_77 )
F_19 ( V_20 , L_25 ) ;
}
return 0 ;
}
static int F_70 ( struct V_78 * V_21 )
{
T_3 * V_79 [] = { F_64 , F_65 } ;
static const char * const V_80 [] = { L_26 , L_27 } ;
struct V_74 * V_81 [ 2 ] ;
struct V_9 * V_10 ;
void * V_82 ;
int V_36 = 0 , V_83 ;
T_4 V_84 ;
bool V_85 ;
V_10 = F_14 ( sizeof( * V_10 ) , V_22 ) ;
if ( ! V_10 )
return - V_66 ;
V_10 -> V_21 = V_21 ;
F_71 ( & V_10 -> V_29 ) ;
F_16 ( & V_10 -> V_28 ) ;
F_16 ( & V_10 -> V_53 ) ;
F_72 ( & V_10 -> V_67 ) ;
V_36 = F_73 ( V_21 , 2 , V_81 , V_79 , V_80 , NULL ) ;
if ( V_36 )
goto V_86;
V_10 -> V_73 = V_81 [ 0 ] ;
V_10 -> V_58 = V_81 [ 1 ] ;
F_7 ( F_74 ( V_10 -> V_73 ) !=
F_74 ( V_10 -> V_58 ) ) ;
if ( F_74 ( V_10 -> V_73 ) < V_87 / 2 )
V_10 -> V_55 = F_74 ( V_10 -> V_73 ) * 2 ;
else
V_10 -> V_55 = V_87 ;
V_10 -> V_57 = V_88 ;
V_84 = V_10 -> V_55 * V_10 -> V_57 ;
V_82 = F_75 ( V_21 -> V_20 . V_51 -> V_51 ,
V_84 , & V_10 -> V_89 ,
V_22 ) ;
if ( ! V_82 ) {
V_36 = - V_66 ;
goto V_90;
}
F_48 ( & V_21 -> V_20 , L_28 ,
V_82 , & V_10 -> V_89 ) ;
V_10 -> V_91 = V_82 ;
V_10 -> V_56 = V_82 + V_84 / 2 ;
for ( V_83 = 0 ; V_83 < V_10 -> V_55 / 2 ; V_83 ++ ) {
struct V_1 V_2 ;
void * V_3 = V_10 -> V_91 + V_83 * V_10 -> V_57 ;
F_1 ( & V_2 , V_3 , V_10 -> V_57 ) ;
V_36 = F_63 ( V_10 -> V_73 , & V_2 , 1 , V_3 ,
V_22 ) ;
F_7 ( V_36 ) ;
}
F_44 ( V_10 -> V_58 ) ;
V_21 -> V_14 = V_10 ;
if ( F_28 ( V_21 , V_38 ) ) {
V_10 -> V_92 = F_13 ( V_10 , NULL , F_67 ,
V_10 , V_45 ) ;
if ( ! V_10 -> V_92 ) {
F_19 ( & V_21 -> V_20 , L_29 ) ;
V_36 = - V_66 ;
goto V_93;
}
}
V_85 = F_76 ( V_10 -> V_73 ) ;
F_77 ( V_21 ) ;
if ( V_85 )
F_78 ( V_10 -> V_73 ) ;
F_68 ( & V_21 -> V_20 , L_30 ) ;
return 0 ;
V_93:
F_79 ( V_21 -> V_20 . V_51 -> V_51 , V_84 ,
V_82 , V_10 -> V_89 ) ;
V_90:
V_21 -> V_94 -> V_95 ( V_10 -> V_21 ) ;
V_86:
F_12 ( V_10 ) ;
return V_36 ;
}
static int F_80 ( struct V_19 * V_20 , void * V_60 )
{
F_81 ( V_20 ) ;
return 0 ;
}
static void F_82 ( struct V_78 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_14 ;
T_4 V_84 = V_10 -> V_55 * V_10 -> V_57 ;
int V_48 ;
V_21 -> V_94 -> V_96 ( V_21 ) ;
V_48 = F_83 ( & V_21 -> V_20 , NULL , F_80 ) ;
if ( V_48 )
F_60 ( & V_21 -> V_20 , L_31 , V_48 ) ;
if ( V_10 -> V_92 )
F_24 ( V_10 , V_10 -> V_92 ) ;
F_84 ( & V_10 -> V_29 ) ;
V_21 -> V_94 -> V_95 ( V_10 -> V_21 ) ;
F_79 ( V_21 -> V_20 . V_51 -> V_51 , V_84 ,
V_10 -> V_91 , V_10 -> V_89 ) ;
F_12 ( V_10 ) ;
}
static int T_5 F_85 ( void )
{
int V_48 ;
V_48 = F_86 ( & V_97 ) ;
if ( V_48 )
F_87 ( L_32 , V_48 ) ;
return V_48 ;
}
static void T_6 F_88 ( void )
{
F_89 ( & V_97 ) ;
}
