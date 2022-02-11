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
if ( V_8 -> V_33 &&
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
if ( V_8 -> V_33 &&
F_19 ( V_6 -> V_17 , V_34 ) ) {
struct V_35 V_36 ;
strncpy ( V_36 . V_37 , V_8 -> V_14 . V_37 , V_38 ) ;
V_36 . V_11 = V_8 -> V_31 ;
V_36 . V_39 = V_42 ;
V_32 = F_20 ( V_8 -> V_3 , & V_36 , sizeof( V_36 ) , V_41 ) ;
if ( V_32 )
F_10 ( V_16 , L_2 , V_32 ) ;
}
return V_32 ;
}
static struct V_7 * F_22 ( struct V_5 * V_6 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_7 * V_8 ;
struct V_15 * V_43 , * V_16 = & V_6 -> V_17 -> V_16 ;
int V_44 ;
V_43 = F_23 ( V_16 , V_28 ) ;
if ( V_43 ) {
F_24 ( V_43 ) ;
F_10 ( V_16 , L_3 ,
V_28 -> V_37 , V_28 -> V_31 , V_28 -> V_45 ) ;
return NULL ;
}
V_30 = F_5 ( sizeof( * V_30 ) , V_18 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_6 = V_6 ;
V_30 -> V_8 . V_20 = & V_46 ;
V_8 = & V_30 -> V_8 ;
V_8 -> V_31 = V_28 -> V_31 ;
V_8 -> V_45 = V_28 -> V_45 ;
V_8 -> V_20 = & V_46 ;
V_8 -> V_33 = V_8 -> V_31 != V_22 ;
strncpy ( V_8 -> V_14 . V_37 , V_28 -> V_37 , V_38 ) ;
V_8 -> V_16 . V_47 = & V_6 -> V_17 -> V_16 ;
V_44 = F_25 ( V_8 ) ;
if ( V_44 )
return NULL ;
return V_8 ;
}
static void * F_26 ( struct V_5 * V_6 )
{
unsigned int V_48 ;
void * V_44 ;
F_8 ( & V_6 -> V_49 ) ;
if ( V_6 -> V_50 < V_6 -> V_51 / 2 )
V_44 = V_6 -> V_52 + V_53 * V_6 -> V_50 ++ ;
else
V_44 = F_27 ( V_6 -> V_54 , & V_48 ) ;
F_11 ( & V_6 -> V_49 ) ;
return V_44 ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_49 ) ;
if ( F_29 ( & V_6 -> V_55 ) == 1 )
F_30 ( V_6 -> V_54 ) ;
F_11 ( & V_6 -> V_49 ) ;
}
static void F_31 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_49 ) ;
if ( F_32 ( & V_6 -> V_55 ) )
F_33 ( V_6 -> V_54 ) ;
F_11 ( & V_6 -> V_49 ) ;
}
static int F_34 ( struct V_7 * V_8 ,
T_2 V_31 , T_2 V_45 ,
void * V_56 , int V_48 , bool V_57 )
{
struct V_29 * V_30 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_15 * V_16 = & V_8 -> V_16 ;
struct V_58 V_59 ;
struct V_60 * V_61 ;
int V_32 ;
if ( V_31 == V_22 || V_45 == V_22 ) {
F_10 ( V_16 , L_4 , V_31 , V_45 ) ;
return - V_62 ;
}
if ( V_48 > V_53 - sizeof( struct V_60 ) ) {
F_10 ( V_16 , L_5 , V_48 ) ;
return - V_63 ;
}
V_61 = F_26 ( V_6 ) ;
if ( ! V_61 && ! V_57 )
return - V_64 ;
while ( ! V_61 ) {
F_28 ( V_6 ) ;
V_32 = F_35 ( V_6 -> V_65 ,
( V_61 = F_26 ( V_6 ) ) ,
F_36 ( 15000 ) ) ;
F_31 ( V_6 ) ;
if ( ! V_32 ) {
F_10 ( V_16 , L_6 ) ;
return - V_66 ;
}
}
V_61 -> V_48 = V_48 ;
V_61 -> V_39 = 0 ;
V_61 -> V_31 = V_31 ;
V_61 -> V_45 = V_45 ;
V_61 -> V_67 = 0 ;
memcpy ( V_61 -> V_56 , V_56 , V_48 ) ;
F_37 ( V_16 , L_7 ,
V_61 -> V_31 , V_61 -> V_45 , V_61 -> V_48 , V_61 -> V_39 , V_61 -> V_67 ) ;
#if F_38 ( V_68 )
F_39 ( L_8 , V_69 , 16 , 1 ,
V_61 , sizeof( * V_61 ) + V_61 -> V_48 , true ) ;
#endif
F_40 ( & V_59 , V_61 , sizeof( * V_61 ) + V_48 ) ;
F_8 ( & V_6 -> V_49 ) ;
V_32 = F_41 ( V_6 -> V_54 , & V_59 , 1 , V_61 , V_18 ) ;
if ( V_32 ) {
F_10 ( V_16 , L_9 , V_32 ) ;
goto V_70;
}
F_42 ( V_6 -> V_54 ) ;
V_70:
F_11 ( & V_6 -> V_49 ) ;
return V_32 ;
}
static int F_43 ( struct V_2 * V_3 , void * V_56 , int V_48 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 , V_45 = V_8 -> V_45 ;
return F_34 ( V_8 , V_31 , V_45 , V_56 , V_48 , true ) ;
}
static int F_44 ( struct V_2 * V_3 , void * V_56 , int V_48 ,
T_2 V_45 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 ;
return F_34 ( V_8 , V_31 , V_45 , V_56 , V_48 , true ) ;
}
static int F_45 ( struct V_2 * V_3 , T_2 V_31 ,
T_2 V_45 , void * V_56 , int V_48 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
return F_34 ( V_8 , V_31 , V_45 , V_56 , V_48 , true ) ;
}
static int F_46 ( struct V_2 * V_3 , void * V_56 , int V_48 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 , V_45 = V_8 -> V_45 ;
return F_34 ( V_8 , V_31 , V_45 , V_56 , V_48 , false ) ;
}
static int F_47 ( struct V_2 * V_3 , void * V_56 ,
int V_48 , T_2 V_45 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_31 = V_3 -> V_11 ;
return F_34 ( V_8 , V_31 , V_45 , V_56 , V_48 , false ) ;
}
static int F_48 ( struct V_2 * V_3 , T_2 V_31 ,
T_2 V_45 , void * V_56 , int V_48 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
return F_34 ( V_8 , V_31 , V_45 , V_56 , V_48 , false ) ;
}
static int F_49 ( struct V_5 * V_6 , struct V_15 * V_16 ,
struct V_60 * V_61 , unsigned int V_48 )
{
struct V_2 * V_3 ;
struct V_58 V_59 ;
int V_32 ;
F_37 ( V_16 , L_10 ,
V_61 -> V_31 , V_61 -> V_45 , V_61 -> V_48 , V_61 -> V_39 , V_61 -> V_67 ) ;
#if F_38 ( V_68 )
F_39 ( L_11 , V_69 , 16 , 1 ,
V_61 , sizeof( * V_61 ) + V_61 -> V_48 , true ) ;
#endif
if ( V_48 > V_53 ||
V_61 -> V_48 > ( V_48 - sizeof( struct V_60 ) ) ) {
F_50 ( V_16 , L_12 , V_48 , V_61 -> V_48 ) ;
return - V_62 ;
}
F_8 ( & V_6 -> V_24 ) ;
V_3 = F_51 ( & V_6 -> V_25 , V_61 -> V_45 ) ;
if ( V_3 )
F_52 ( & V_3 -> V_4 ) ;
F_11 ( & V_6 -> V_24 ) ;
if ( V_3 ) {
F_8 ( & V_3 -> V_19 ) ;
if ( V_3 -> V_9 )
V_3 -> V_9 ( V_3 -> V_8 , V_61 -> V_56 , V_61 -> V_48 , V_3 -> V_10 ,
V_61 -> V_31 ) ;
F_11 ( & V_3 -> V_19 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
} else
F_50 ( V_16 , L_13 ) ;
F_40 ( & V_59 , V_61 , V_53 ) ;
V_32 = F_53 ( V_6 -> V_71 , & V_59 , 1 , V_61 , V_18 ) ;
if ( V_32 < 0 ) {
F_10 ( V_16 , L_14 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
static void F_54 ( struct V_72 * V_71 )
{
struct V_5 * V_6 = V_71 -> V_17 -> V_10 ;
struct V_15 * V_16 = & V_71 -> V_17 -> V_16 ;
struct V_60 * V_61 ;
unsigned int V_48 , V_73 = 0 ;
int V_32 ;
V_61 = F_27 ( V_71 , & V_48 ) ;
if ( ! V_61 ) {
F_10 ( V_16 , L_15 ) ;
return;
}
while ( V_61 ) {
V_32 = F_49 ( V_6 , V_16 , V_61 , V_48 ) ;
if ( V_32 )
break;
V_73 ++ ;
V_61 = F_27 ( V_71 , & V_48 ) ;
}
F_37 ( V_16 , L_16 , V_73 ) ;
if ( V_73 )
F_42 ( V_6 -> V_71 ) ;
}
static void F_55 ( struct V_72 * V_54 )
{
struct V_5 * V_6 = V_54 -> V_17 -> V_10 ;
F_37 ( & V_54 -> V_17 -> V_16 , L_17 , V_74 ) ;
F_56 ( & V_6 -> V_65 ) ;
}
static int F_57 ( struct V_7 * V_8 , void * V_56 , int V_48 ,
void * V_10 , T_2 V_31 )
{
struct V_35 * V_61 = V_56 ;
struct V_7 * V_75 ;
struct V_27 V_28 ;
struct V_5 * V_6 = V_10 ;
struct V_15 * V_16 = & V_6 -> V_17 -> V_16 ;
int V_44 ;
#if F_38 ( V_68 )
F_39 ( L_18 , V_69 , 16 , 1 ,
V_56 , V_48 , true ) ;
#endif
if ( V_48 != sizeof( * V_61 ) ) {
F_10 ( V_16 , L_19 , V_48 ) ;
return - V_62 ;
}
if ( V_8 ) {
F_10 ( V_16 , L_20 ) ;
return - V_62 ;
}
V_61 -> V_37 [ V_38 - 1 ] = '\0' ;
F_58 ( V_16 , L_21 ,
V_61 -> V_39 & V_42 ? L_22 : L_23 ,
V_61 -> V_37 , V_61 -> V_11 ) ;
strncpy ( V_28 . V_37 , V_61 -> V_37 , sizeof( V_28 . V_37 ) ) ;
V_28 . V_31 = V_22 ;
V_28 . V_45 = V_61 -> V_11 ;
if ( V_61 -> V_39 & V_42 ) {
V_44 = F_59 ( & V_6 -> V_17 -> V_16 , & V_28 ) ;
if ( V_44 )
F_10 ( V_16 , L_24 , V_44 ) ;
} else {
V_75 = F_22 ( V_6 , & V_28 ) ;
if ( ! V_75 )
F_10 ( V_16 , L_25 ) ;
}
return 0 ;
}
static int F_60 ( struct V_76 * V_17 )
{
T_3 * V_77 [] = { F_54 , F_55 } ;
static const char * const V_78 [] = { L_26 , L_27 } ;
struct V_72 * V_79 [ 2 ] ;
struct V_5 * V_6 ;
void * V_80 ;
int V_32 = 0 , V_81 ;
T_4 V_82 ;
bool V_83 ;
V_6 = F_5 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return - V_64 ;
V_6 -> V_17 = V_17 ;
F_61 ( & V_6 -> V_25 ) ;
F_7 ( & V_6 -> V_24 ) ;
F_7 ( & V_6 -> V_49 ) ;
F_62 ( & V_6 -> V_65 ) ;
V_32 = V_17 -> V_84 -> V_85 ( V_17 , 2 , V_79 , V_77 , V_78 ) ;
if ( V_32 )
goto V_86;
V_6 -> V_71 = V_79 [ 0 ] ;
V_6 -> V_54 = V_79 [ 1 ] ;
F_63 ( F_64 ( V_6 -> V_71 ) !=
F_64 ( V_6 -> V_54 ) ) ;
if ( F_64 ( V_6 -> V_71 ) < V_87 / 2 )
V_6 -> V_51 = F_64 ( V_6 -> V_71 ) * 2 ;
else
V_6 -> V_51 = V_87 ;
V_82 = V_6 -> V_51 * V_53 ;
V_80 = F_65 ( V_17 -> V_16 . V_47 -> V_47 ,
V_82 , & V_6 -> V_88 ,
V_18 ) ;
if ( ! V_80 ) {
V_32 = - V_64 ;
goto V_89;
}
F_37 ( & V_17 -> V_16 , L_28 ,
V_80 , & V_6 -> V_88 ) ;
V_6 -> V_90 = V_80 ;
V_6 -> V_52 = V_80 + V_82 / 2 ;
for ( V_81 = 0 ; V_81 < V_6 -> V_51 / 2 ; V_81 ++ ) {
struct V_58 V_59 ;
void * V_91 = V_6 -> V_90 + V_81 * V_53 ;
F_40 ( & V_59 , V_91 , V_53 ) ;
V_32 = F_53 ( V_6 -> V_71 , & V_59 , 1 , V_91 ,
V_18 ) ;
F_63 ( V_32 ) ;
}
F_33 ( V_6 -> V_54 ) ;
V_17 -> V_10 = V_6 ;
if ( F_19 ( V_17 , V_34 ) ) {
V_6 -> V_92 = F_4 ( V_6 , NULL , F_57 ,
V_6 , V_41 ) ;
if ( ! V_6 -> V_92 ) {
F_10 ( & V_17 -> V_16 , L_29 ) ;
V_32 = - V_64 ;
goto V_93;
}
}
V_83 = F_66 ( V_6 -> V_71 ) ;
F_67 ( V_17 ) ;
if ( V_83 )
F_68 ( V_6 -> V_71 ) ;
F_58 ( & V_17 -> V_16 , L_30 ) ;
return 0 ;
V_93:
F_69 ( V_17 -> V_16 . V_47 -> V_47 , V_82 ,
V_80 , V_6 -> V_88 ) ;
V_89:
V_17 -> V_84 -> V_94 ( V_6 -> V_17 ) ;
V_86:
F_3 ( V_6 ) ;
return V_32 ;
}
static int F_70 ( struct V_15 * V_16 , void * V_56 )
{
F_71 ( V_16 ) ;
return 0 ;
}
static void F_72 ( struct V_76 * V_17 )
{
struct V_5 * V_6 = V_17 -> V_10 ;
T_4 V_82 = V_6 -> V_51 * V_53 ;
int V_44 ;
V_17 -> V_84 -> V_95 ( V_17 ) ;
V_44 = F_73 ( & V_17 -> V_16 , NULL , F_70 ) ;
if ( V_44 )
F_50 ( & V_17 -> V_16 , L_31 , V_44 ) ;
if ( V_6 -> V_92 )
F_15 ( V_6 , V_6 -> V_92 ) ;
F_74 ( & V_6 -> V_25 ) ;
V_17 -> V_84 -> V_94 ( V_6 -> V_17 ) ;
F_69 ( V_17 -> V_16 . V_47 -> V_47 , V_82 ,
V_6 -> V_90 , V_6 -> V_88 ) ;
F_3 ( V_6 ) ;
}
static int T_5 F_75 ( void )
{
int V_44 ;
V_44 = F_76 ( & V_96 ) ;
if ( V_44 )
F_77 ( L_32 , V_44 ) ;
return V_44 ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_96 ) ;
}
