static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 1 ;
int V_5 ;
T_1 V_6 ;
V_3 = F_2 ( V_2 , V_7 , & V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_2 -> V_2 , L_1 ,
V_3 ) ;
return V_3 ;
}
V_5 = V_6 ;
if ( V_6 < F_4 () )
V_4 = 0 ;
V_3 = F_5 ( V_6 , V_5 , V_4 , L_2 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_2 -> V_2 , L_3 ,
V_6 , V_5 , V_3 ) ;
return V_3 ;
}
V_2 -> V_8 = V_3 ;
F_6 ( & V_2 -> V_2 , L_4 , V_6 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_7 ( T_2 V_6 , int V_9 , int V_10 ,
bool V_11 )
{
int V_3 , V_5 = - 1 , V_8 = - 1 ;
struct V_12 V_13 ;
int V_14 = 0 ;
char * V_15 ;
V_8 = F_8 ( V_6 ) ;
if ( V_8 > 0 )
return V_8 ;
if ( V_11 )
V_5 = V_6 ;
V_13 . V_16 = V_17 ;
V_13 . type = V_18 ;
V_13 . V_19 = V_6 ;
V_13 . V_5 = V_5 ;
V_3 = F_9 ( V_20 , & V_13 ) ;
if ( V_3 ) {
F_10 ( V_21 L_5 , V_3 ) ;
return - 1 ;
}
if ( V_10 == V_22 ) {
V_14 = 0 ;
V_15 = L_6 ;
} else {
V_14 = 1 ;
V_15 = L_7 ;
}
if ( V_9 >= 0 )
V_6 = V_9 ;
V_8 = F_5 ( V_6 , V_13 . V_5 , V_14 , V_15 ) ;
if ( V_8 < 0 )
goto V_23;
F_10 ( V_24 L_8 , V_13 . V_5 , V_8 , V_6 ) ;
V_23:
return V_8 ;
}
static int F_11 ( struct V_25 * V_2 , T_2 V_6 ,
int V_26 , int V_27 )
{
if ( ! F_12 () )
return - 1 ;
return F_7 ( V_6 , - 1 , V_26 ,
false ) ;
}
static int F_13 ( T_2 V_6 , int V_9 , int V_10 , int V_27 )
{
int V_3 , V_8 ;
struct V_28 V_29 ;
if ( ! F_14 () )
return - 1 ;
F_10 ( V_24 L_9 ,
V_6 , V_10 , V_27 ) ;
V_8 = F_7 ( V_6 , V_9 , V_10 , true ) ;
V_29 . V_6 = V_6 ;
V_29 . V_10 = ( V_10 == V_22 ? 0 : 1 ) ;
V_29 . V_27 = ( V_27 == V_30 ? 0 : 1 ) ;
V_3 = F_9 ( V_31 , & V_29 ) ;
if ( V_3 == - V_32 )
F_10 ( V_33 L_10 , V_6 ) ;
else if ( V_3 ) {
F_10 ( V_34 L_11 ,
V_6 , V_3 ) ;
}
return V_8 ;
}
static int F_15 ( struct V_25 * V_2 , T_2 V_6 ,
int V_26 , int V_27 )
{
return F_13 ( V_6 , - 1 , V_26 , V_27 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_35 , int type )
{
int V_8 , V_36 , V_37 ;
struct V_38 * V_39 ;
int * V_40 ;
if ( type == V_41 && V_35 > 1 )
return 1 ;
V_40 = F_17 ( sizeof( int ) * F_18 ( 1 , V_35 ) , V_42 ) ;
if ( ! V_40 )
return - V_43 ;
if ( type == V_44 )
V_36 = F_19 ( V_2 , V_40 , V_35 ) ;
else
V_36 = F_20 ( V_2 , V_40 ) ;
if ( V_36 )
goto error;
V_37 = 0 ;
F_21 (msidesc, &dev->msi_list, list) {
V_8 = F_22 ( V_2 , V_39 , V_40 [ V_37 ] ,
( type == V_41 ) ? V_35 : 1 ,
( type == V_44 ) ?
L_12 :
L_13 ,
V_17 ) ;
if ( V_8 < 0 ) {
V_36 = V_8 ;
goto free;
}
V_37 ++ ;
}
F_23 ( V_40 ) ;
return 0 ;
error:
F_24 ( & V_2 -> V_2 , L_14 ) ;
free:
F_23 ( V_40 ) ;
return V_36 ;
}
static void F_25 ( struct V_1 * V_45 , unsigned int V_5 ,
struct V_46 * V_47 )
{
V_47 -> V_48 = V_49 | F_26 ( V_5 ) ;
V_47 -> V_50 =
V_51 |
V_52 |
V_53 |
F_27 ( V_5 ) ;
V_47 -> V_54 = V_55 ;
}
static int F_28 ( struct V_1 * V_2 , int V_35 , int type )
{
int V_8 , V_5 ;
struct V_38 * V_39 ;
struct V_46 V_47 ;
if ( type == V_41 && V_35 > 1 )
return 1 ;
F_21 (msidesc, &dev->msi_list, list) {
F_29 ( V_39 , & V_47 ) ;
V_5 = F_26 ( V_47 . V_48 ) |
( ( V_47 . V_50 >> V_56 ) & 0xff ) ;
if ( V_47 . V_54 != V_55 ||
F_30 ( V_5 ) < 0 ) {
V_5 = F_31 ( V_2 , V_39 ) ;
if ( V_5 < 0 ) {
V_8 = - V_57 ;
goto error;
}
F_25 ( V_2 , V_5 , & V_47 ) ;
F_32 ( V_39 , & V_47 ) ;
F_33 ( & V_2 -> V_2 , L_15 , V_5 ) ;
} else {
F_33 ( & V_2 -> V_2 ,
L_16 , V_5 ) ;
}
V_8 = F_22 ( V_2 , V_39 , V_5 ,
( type == V_41 ) ? V_35 : 1 ,
( type == V_44 ) ?
L_17 : L_18 ,
V_17 ) ;
if ( V_8 < 0 )
goto error;
F_33 ( & V_2 -> V_2 ,
L_19 , V_5 , V_8 ) ;
}
return 0 ;
error:
F_24 ( & V_2 -> V_2 ,
L_14 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 , int V_35 , int type )
{
int V_36 = 0 ;
struct V_38 * V_39 ;
F_21 (msidesc, &dev->msi_list, list) {
struct V_12 V_13 ;
T_3 V_16 ;
V_16 = V_36 = F_35 ( V_2 ) ;
if ( V_36 < 0 )
V_16 = V_17 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_16 = V_16 ;
V_13 . type = V_58 ;
V_13 . V_19 = - 1 ;
V_13 . V_5 = - 1 ;
V_13 . V_59 = V_2 -> V_59 -> V_60 |
( F_36 ( V_2 -> V_59 ) << 16 ) ;
V_13 . V_61 = V_2 -> V_61 ;
if ( type == V_41 && V_35 > 1 ) {
V_13 . type = V_62 ;
V_13 . V_63 = V_35 ;
} else if ( type == V_44 ) {
int V_64 ;
T_2 V_65 , V_66 ;
V_64 = V_2 -> V_67 ;
F_37 ( V_2 , V_64 + V_68 ,
& V_65 ) ;
V_66 = ( T_1 ) ( V_65 & V_69 ) ;
V_13 . V_70 = F_38 ( V_2 , V_66 ) ;
V_13 . V_63 = V_39 -> V_71 . V_63 ;
}
V_36 = - V_72 ;
if ( V_73 )
V_36 = F_9 ( V_20 ,
& V_13 ) ;
if ( type == V_41 && V_35 > 1 && V_36 ) {
V_36 = 1 ;
goto V_23;
}
if ( V_36 == - V_72 && ! F_36 ( V_2 -> V_59 ) ) {
V_13 . type = V_74 ;
V_13 . V_19 = - 1 ;
V_13 . V_5 = - 1 ;
V_13 . V_59 = V_2 -> V_59 -> V_60 ;
V_36 = F_9 ( V_20 ,
& V_13 ) ;
if ( V_36 != - V_72 )
V_73 = false ;
}
if ( V_36 ) {
F_3 ( & V_2 -> V_2 , L_20 ,
V_36 , V_16 ) ;
goto V_23;
}
V_36 = F_22 ( V_2 , V_39 , V_13 . V_5 ,
( type == V_41 ) ? V_35 : 1 ,
( type == V_44 ) ? L_17 : L_18 ,
V_16 ) ;
if ( V_36 < 0 )
goto V_23;
}
V_36 = 0 ;
V_23:
return V_36 ;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
if ( V_73 ) {
struct V_75 V_76 ;
V_76 . V_77 = F_36 ( V_2 -> V_59 ) ;
V_76 . V_59 = V_2 -> V_59 -> V_60 ;
V_76 . V_61 = V_2 -> V_61 ;
V_36 = F_9 ( V_78 ,
& V_76 ) ;
if ( V_36 == - V_79 )
V_73 = false ;
F_40 ( V_36 && V_36 != - V_79 , L_21 , V_36 ) ;
}
if ( ! V_73 ) {
struct V_80 V_81 ;
V_81 . V_59 = V_2 -> V_59 -> V_60 ;
V_81 . V_61 = V_2 -> V_61 ;
V_36 = F_9 ( V_82 , & V_81 ) ;
F_40 ( V_36 && V_36 != - V_79 , L_22 , V_36 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
V_39 = F_42 ( V_2 -> V_83 . V_84 , struct V_38 , V_85 ) ;
if ( V_39 -> V_71 . V_86 )
F_43 ( V_2 ) ;
else
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static void F_46 ( unsigned int V_8 )
{
F_47 ( V_8 ) ;
}
int T_4 F_48 ( void )
{
if ( ! F_14 () || F_49 () )
return - V_57 ;
F_10 ( V_33 L_23 ) ;
F_50 () ;
V_87 = F_1 ;
V_88 = NULL ;
#ifdef F_51
V_89 = 1 ;
#endif
#ifdef F_52
V_90 . V_91 = F_16 ;
V_90 . V_92 = F_46 ;
V_90 . V_93 = F_41 ;
V_94 = 1 ;
#endif
return 0 ;
}
void T_4 F_53 ( void )
{
if ( ! V_95 ) {
T_5 V_96 = F_54 ( F_55 () + 4 ) ;
if ( ( ( V_96 & V_97 ) && V_98 ) ||
( ( V_96 & V_99 ) && V_100 ) )
return;
}
V_90 . V_91 = F_28 ;
V_90 . V_92 = F_46 ;
}
int T_4 F_56 ( void )
{
if ( ! V_101 || ! F_57 ( V_102 ) )
return 0 ;
#ifdef F_51
V_103 = F_11 ;
V_104 = NULL ;
#endif
#ifdef F_52
V_105 . V_106 = F_53 ;
#endif
return 0 ;
}
int T_4 F_58 ( void )
{
int V_8 ;
#ifdef F_52
V_90 . V_91 = F_34 ;
V_90 . V_92 = F_46 ;
V_90 . V_107 = F_39 ;
V_94 = 1 ;
#endif
V_103 = F_15 ;
V_104 = NULL ;
for ( V_8 = 0 ; V_8 < F_4 () ; V_8 ++ ) {
int V_26 , V_27 ;
if ( F_59 ( V_8 , & V_26 , & V_27 ) == - 1 )
continue;
F_7 ( V_8 , - 1 ,
V_26 ? V_108 : V_22 ,
true ) ;
}
if ( 0 == V_109 ) {
for ( V_8 = 0 ; V_8 < F_4 () ; V_8 ++ )
F_5 ( V_8 , V_8 , 0 , L_24 ) ;
}
return 0 ;
}
static struct V_110 * F_60 ( struct V_1 * V_2 )
{
struct V_110 * V_111 ;
F_21 (owner, &dev_domain_list, list) {
if ( V_111 -> V_2 == V_2 )
return V_111 ;
}
return NULL ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_110 * V_111 ;
int V_112 = - V_57 ;
F_61 ( & V_113 ) ;
V_111 = F_60 ( V_2 ) ;
if ( V_111 )
V_112 = V_111 -> V_112 ;
F_62 ( & V_113 ) ;
return V_112 ;
}
int F_63 ( struct V_1 * V_2 , T_6 V_112 )
{
struct V_110 * V_111 ;
V_111 = F_17 ( sizeof( struct V_110 ) , V_42 ) ;
if ( ! V_111 )
return - V_57 ;
F_61 ( & V_113 ) ;
if ( F_60 ( V_2 ) ) {
F_62 ( & V_113 ) ;
F_23 ( V_111 ) ;
return - V_32 ;
}
V_111 -> V_112 = V_112 ;
V_111 -> V_2 = V_2 ;
F_64 ( & V_111 -> V_85 , & V_114 ) ;
F_62 ( & V_113 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_110 * V_111 ;
F_61 ( & V_113 ) ;
V_111 = F_60 ( V_2 ) ;
if ( ! V_111 ) {
F_62 ( & V_113 ) ;
return - V_57 ;
}
F_66 ( & V_111 -> V_85 ) ;
F_62 ( & V_113 ) ;
F_23 ( V_111 ) ;
return 0 ;
}
