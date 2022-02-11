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
if ( V_6 < V_8 )
V_4 = 0 ;
V_3 = F_4 ( V_6 , V_5 , V_4 , L_2 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_2 -> V_2 , L_3 ,
V_6 , V_5 , V_3 ) ;
return V_3 ;
}
V_2 -> V_9 = V_3 ;
F_5 ( & V_2 -> V_2 , L_4 , V_6 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_6 ( T_2 V_6 , int V_10 , int V_11 ,
bool V_12 )
{
int V_3 , V_5 = - 1 , V_9 = - 1 ;
struct V_13 V_14 ;
int V_15 = 0 ;
char * V_16 ;
V_9 = F_7 ( V_6 ) ;
if ( V_9 > 0 )
return V_9 ;
if ( V_12 )
V_5 = V_6 ;
V_14 . V_17 = V_18 ;
V_14 . type = V_19 ;
V_14 . V_20 = V_6 ;
V_14 . V_5 = V_5 ;
V_3 = F_8 ( V_21 , & V_14 ) ;
if ( V_3 ) {
F_9 ( V_22 L_5 , V_3 ) ;
return - 1 ;
}
if ( V_11 == V_23 ) {
V_15 = 0 ;
V_16 = L_6 ;
} else {
V_15 = 1 ;
V_16 = L_7 ;
}
if ( V_10 >= 0 )
V_6 = V_10 ;
V_9 = F_4 ( V_6 , V_14 . V_5 , V_15 , V_16 ) ;
if ( V_9 < 0 )
goto V_24;
F_9 ( V_25 L_8 , V_14 . V_5 , V_9 , V_6 ) ;
V_24:
return V_9 ;
}
static int F_10 ( struct V_26 * V_2 , T_2 V_6 ,
int V_27 , int V_28 )
{
if ( ! F_11 () )
return - 1 ;
return F_6 ( V_6 , - 1 , V_27 ,
false ) ;
}
static int F_12 ( T_2 V_6 , int V_10 , int V_11 , int V_28 )
{
int V_3 , V_9 ;
struct V_29 V_30 ;
if ( ! F_13 () )
return - 1 ;
F_9 ( V_25 L_9 ,
V_6 , V_11 , V_28 ) ;
V_9 = F_6 ( V_6 , V_10 , V_11 , true ) ;
V_30 . V_6 = V_6 ;
V_30 . V_11 = ( V_11 == V_23 ? 0 : 1 ) ;
V_30 . V_28 = ( V_28 == V_31 ? 0 : 1 ) ;
V_3 = F_8 ( V_32 , & V_30 ) ;
if ( V_3 == - V_33 )
F_9 ( V_34 L_10 , V_6 ) ;
else if ( V_3 ) {
F_9 ( V_35 L_11 ,
V_6 , V_3 ) ;
}
return V_9 ;
}
static int F_14 ( struct V_26 * V_2 , T_2 V_6 ,
int V_27 , int V_28 )
{
return F_12 ( V_6 , - 1 , V_27 , V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_36 , int type )
{
int V_9 , V_37 , V_38 ;
struct V_39 * V_40 ;
int * V_41 ;
if ( type == V_42 && V_36 > 1 )
return 1 ;
V_41 = F_16 ( sizeof( int ) * F_17 ( 1 , V_36 ) , V_43 ) ;
if ( ! V_41 )
return - V_44 ;
if ( type == V_45 )
V_37 = F_18 ( V_2 , V_41 , V_36 ) ;
else
V_37 = F_19 ( V_2 , V_41 ) ;
if ( V_37 )
goto error;
V_38 = 0 ;
F_20 (msidesc, &dev->msi_list, list) {
V_9 = F_21 ( V_2 , V_40 , V_41 [ V_38 ] ,
( type == V_45 ) ?
L_12 :
L_13 ,
V_18 ) ;
if ( V_9 < 0 ) {
V_37 = V_9 ;
goto free;
}
V_38 ++ ;
}
F_22 ( V_41 ) ;
return 0 ;
error:
F_23 ( & V_2 -> V_2 , L_14 ) ;
free:
F_22 ( V_41 ) ;
return V_37 ;
}
static void F_24 ( struct V_1 * V_46 , unsigned int V_5 ,
struct V_47 * V_48 )
{
V_48 -> V_49 = V_50 | F_25 ( V_5 ) ;
V_48 -> V_51 =
V_52 |
V_53 |
V_54 |
F_26 ( V_5 ) ;
V_48 -> V_55 = V_56 ;
}
static int F_27 ( struct V_1 * V_2 , int V_36 , int type )
{
int V_9 , V_5 ;
struct V_39 * V_40 ;
struct V_47 V_48 ;
if ( type == V_42 && V_36 > 1 )
return 1 ;
F_20 (msidesc, &dev->msi_list, list) {
F_28 ( V_40 , & V_48 ) ;
V_5 = F_25 ( V_48 . V_49 ) |
( ( V_48 . V_51 >> V_57 ) & 0xff ) ;
if ( V_48 . V_55 != V_56 ||
F_29 ( V_5 ) < 0 ) {
V_5 = F_30 ( V_2 , V_40 ) ;
if ( V_5 < 0 ) {
V_9 = - V_58 ;
goto error;
}
F_24 ( V_2 , V_5 , & V_48 ) ;
F_31 ( V_40 , & V_48 ) ;
F_32 ( & V_2 -> V_2 , L_15 , V_5 ) ;
} else {
F_32 ( & V_2 -> V_2 ,
L_16 , V_5 ) ;
}
V_9 = F_21 ( V_2 , V_40 , V_5 ,
( type == V_45 ) ?
L_17 : L_18 ,
V_18 ) ;
if ( V_9 < 0 )
goto error;
F_32 ( & V_2 -> V_2 ,
L_19 , V_5 , V_9 ) ;
}
return 0 ;
error:
F_23 ( & V_2 -> V_2 ,
L_14 ) ;
return V_9 ;
}
static int F_33 ( struct V_1 * V_2 , int V_36 , int type )
{
int V_37 = 0 ;
struct V_39 * V_40 ;
if ( type == V_42 && V_36 > 1 )
return 1 ;
F_20 (msidesc, &dev->msi_list, list) {
struct V_13 V_14 ;
T_3 V_17 ;
V_17 = V_37 = F_34 ( V_2 ) ;
if ( V_37 < 0 )
V_17 = V_18 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_17 = V_17 ;
V_14 . type = V_59 ;
V_14 . V_20 = - 1 ;
V_14 . V_5 = - 1 ;
V_14 . V_60 = V_2 -> V_60 -> V_61 |
( F_35 ( V_2 -> V_60 ) << 16 ) ;
V_14 . V_62 = V_2 -> V_62 ;
if ( type == V_45 ) {
int V_63 ;
T_2 V_64 , V_65 ;
V_63 = V_2 -> V_66 ;
F_36 ( V_2 , V_63 + V_67 ,
& V_64 ) ;
V_65 = ( T_1 ) ( V_64 & V_68 ) ;
V_14 . V_69 = F_37 ( V_2 , V_65 ) ;
V_14 . V_70 = V_40 -> V_71 . V_70 ;
}
V_37 = - V_72 ;
if ( V_73 )
V_37 = F_8 ( V_21 ,
& V_14 ) ;
if ( V_37 == - V_72 && ! F_35 ( V_2 -> V_60 ) ) {
V_14 . type = V_74 ;
V_14 . V_20 = - 1 ;
V_14 . V_5 = - 1 ;
V_14 . V_60 = V_2 -> V_60 -> V_61 ;
V_37 = F_8 ( V_21 ,
& V_14 ) ;
if ( V_37 != - V_72 )
V_73 = false ;
}
if ( V_37 ) {
F_3 ( & V_2 -> V_2 , L_20 ,
V_37 , V_17 ) ;
goto V_24;
}
V_37 = F_21 ( V_2 , V_40 ,
V_14 . V_5 ,
( type == V_45 ) ?
L_17 : L_18 ,
V_17 ) ;
if ( V_37 < 0 )
goto V_24;
}
V_37 = 0 ;
V_24:
return V_37 ;
}
static void F_38 ( struct V_1 * V_2 , int V_9 )
{
int V_37 = 0 ;
if ( V_73 ) {
struct V_75 V_76 ;
V_76 . V_77 = F_35 ( V_2 -> V_60 ) ;
V_76 . V_60 = V_2 -> V_60 -> V_61 ;
V_76 . V_62 = V_2 -> V_62 ;
V_37 = F_8 ( V_78 ,
& V_76 ) ;
if ( V_37 == - V_79 )
V_73 = false ;
F_39 ( V_37 && V_37 != - V_79 , L_21 , V_37 ) ;
}
if ( ! V_73 ) {
struct V_80 V_81 ;
V_81 . V_60 = V_2 -> V_60 -> V_61 ;
V_81 . V_62 = V_2 -> V_62 ;
V_37 = F_8 ( V_82 , & V_81 ) ;
F_39 ( V_37 && V_37 != - V_79 , L_22 , V_37 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_40 = F_41 ( V_2 -> V_83 . V_84 , struct V_39 , V_85 ) ;
if ( V_40 -> V_71 . V_86 )
F_42 ( V_2 ) ;
else
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( unsigned int V_9 )
{
F_46 ( V_9 ) ;
}
int T_4 F_47 ( void )
{
if ( ! F_13 () || F_48 () )
return - V_58 ;
F_9 ( V_34 L_23 ) ;
F_49 () ;
V_87 = F_1 ;
V_88 = NULL ;
#ifdef F_50
V_89 = 1 ;
#endif
#ifdef F_51
V_90 . V_91 = F_15 ;
V_90 . V_92 = F_45 ;
V_90 . V_93 = F_40 ;
#endif
return 0 ;
}
int T_4 F_52 ( void )
{
if ( ! V_94 || ! F_53 ( V_95 ) )
return 0 ;
#ifdef F_50
V_96 = F_10 ;
#endif
#ifdef F_51
V_90 . V_91 = F_27 ;
V_90 . V_92 = F_45 ;
#endif
return 0 ;
}
static T_4 void F_54 ( void )
{
int V_3 ;
int V_27 , V_28 ;
int V_6 = V_97 ;
int V_9 = - 1 ;
int V_10 = - 1 ;
if ( ! V_6 )
return;
V_3 = F_55 ( V_6 , & V_27 , & V_28 ) ;
if ( V_3 ) {
F_9 ( V_22 L_24
L_25 , V_3 ) ;
return;
}
V_27 = V_27 ? V_98 : V_23 ;
V_28 = V_28 ? V_99 : V_31 ;
F_9 ( V_34 L_26
L_27 , V_6 , V_27 , V_28 ) ;
if ( F_56 ( V_6 , & V_9 ) == 0 ) {
if ( V_9 >= 0 )
V_10 = V_9 ;
}
V_6 = F_12 ( V_6 , V_10 , V_27 , V_28 ) ;
F_9 ( V_34 L_28 , V_6 ) ;
return;
}
int T_4 F_57 ( void )
{
int V_9 ;
#ifdef F_51
V_90 . V_91 = F_33 ;
V_90 . V_92 = F_45 ;
V_90 . V_100 = F_38 ;
#endif
F_54 () ;
V_96 = F_14 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
int V_27 , V_28 ;
if ( F_55 ( V_9 , & V_27 , & V_28 ) == - 1 )
continue;
F_6 ( V_9 , - 1 ,
V_27 ? V_98 : V_23 ,
true ) ;
}
if ( 0 == V_101 ) {
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_4 ( V_9 , V_9 , 0 , L_29 ) ;
}
return 0 ;
}
static struct V_102 * F_58 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
F_20 (owner, &dev_domain_list, list) {
if ( V_103 -> V_2 == V_2 )
return V_103 ;
}
return NULL ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
int V_104 = - V_58 ;
F_59 ( & V_105 ) ;
V_103 = F_58 ( V_2 ) ;
if ( V_103 )
V_104 = V_103 -> V_104 ;
F_60 ( & V_105 ) ;
return V_104 ;
}
int F_61 ( struct V_1 * V_2 , T_5 V_104 )
{
struct V_102 * V_103 ;
V_103 = F_16 ( sizeof( struct V_102 ) , V_43 ) ;
if ( ! V_103 )
return - V_58 ;
F_59 ( & V_105 ) ;
if ( F_58 ( V_2 ) ) {
F_60 ( & V_105 ) ;
F_22 ( V_103 ) ;
return - V_33 ;
}
V_103 -> V_104 = V_104 ;
V_103 -> V_2 = V_2 ;
F_62 ( & V_103 -> V_85 , & V_106 ) ;
F_60 ( & V_105 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
F_59 ( & V_105 ) ;
V_103 = F_58 ( V_2 ) ;
if ( ! V_103 ) {
F_60 ( & V_105 ) ;
return - V_58 ;
}
F_64 ( & V_103 -> V_85 ) ;
F_60 ( & V_105 ) ;
F_22 ( V_103 ) ;
return 0 ;
}
