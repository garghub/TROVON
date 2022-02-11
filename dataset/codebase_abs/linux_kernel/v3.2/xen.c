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
if ( V_12 )
V_5 = V_6 ;
V_14 . V_17 = V_18 ;
V_14 . type = V_19 ;
V_14 . V_20 = V_6 ;
V_14 . V_5 = V_5 ;
V_3 = F_7 ( V_21 , & V_14 ) ;
if ( V_3 ) {
F_8 ( V_22 L_5 , V_3 ) ;
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
F_8 ( V_25 L_8 , V_14 . V_5 , V_9 , V_6 ) ;
V_24:
return V_9 ;
}
static int F_9 ( struct V_26 * V_2 , T_2 V_6 ,
int V_27 , int V_28 )
{
if ( ! F_10 () )
return - 1 ;
return F_6 ( V_6 , - 1 , V_27 ,
false ) ;
}
static int F_11 ( T_2 V_6 , int V_10 , int V_11 , int V_28 )
{
int V_3 , V_9 ;
struct V_29 V_30 ;
if ( ! F_12 () )
return - 1 ;
F_8 ( V_25 L_9 ,
V_6 , V_11 , V_28 ) ;
V_9 = F_6 ( V_6 , V_10 , V_11 , true ) ;
V_30 . V_6 = V_6 ;
V_30 . V_11 = ( V_11 == V_23 ? 0 : 1 ) ;
V_30 . V_28 = ( V_28 == V_31 ? 0 : 1 ) ;
V_3 = F_7 ( V_32 , & V_30 ) ;
if ( V_3 == - V_33 )
F_8 ( V_34 L_10 , V_6 ) ;
else if ( V_3 ) {
F_8 ( V_35 L_11 ,
V_6 , V_3 ) ;
}
return V_9 ;
}
static int F_13 ( struct V_26 * V_2 , T_2 V_6 ,
int V_27 , int V_28 )
{
return F_11 ( V_6 , - 1 , V_27 , V_28 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_36 , int type )
{
int V_9 , V_37 , V_38 ;
struct V_39 * V_40 ;
int * V_41 ;
V_41 = F_15 ( sizeof( int ) * F_16 ( 1 , V_36 ) , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
if ( type == V_44 )
V_37 = F_17 ( V_2 , V_41 , V_36 ) ;
else
V_37 = F_18 ( V_2 , V_41 ) ;
if ( V_37 )
goto error;
V_38 = 0 ;
F_19 (msidesc, &dev->msi_list, list) {
V_9 = F_20 ( V_2 , V_40 , V_41 [ V_38 ] , 0 ,
( type == V_44 ) ?
L_12 :
L_13 ,
V_18 ) ;
if ( V_9 < 0 ) {
V_37 = V_9 ;
goto free;
}
V_38 ++ ;
}
F_21 ( V_41 ) ;
return 0 ;
error:
F_22 ( & V_2 -> V_2 , L_14 ) ;
free:
F_21 ( V_41 ) ;
return V_37 ;
}
static void F_23 ( struct V_1 * V_45 , unsigned int V_5 ,
struct V_46 * V_47 )
{
V_47 -> V_48 = V_49 | F_24 ( V_5 ) ;
V_47 -> V_50 =
V_51 |
V_52 |
V_53 |
F_25 ( V_5 ) ;
V_47 -> V_54 = V_55 ;
}
static int F_26 ( struct V_1 * V_2 , int V_36 , int type )
{
int V_9 , V_5 ;
struct V_39 * V_40 ;
struct V_46 V_47 ;
F_19 (msidesc, &dev->msi_list, list) {
F_27 ( V_40 , & V_47 ) ;
V_5 = F_24 ( V_47 . V_48 ) |
( ( V_47 . V_50 >> V_56 ) & 0xff ) ;
if ( V_47 . V_54 != V_55 ||
F_28 ( V_5 ) < 0 ) {
V_5 = F_29 ( V_2 , V_40 ) ;
if ( V_5 < 0 ) {
V_9 = - V_57 ;
goto error;
}
F_23 ( V_2 , V_5 , & V_47 ) ;
F_30 ( V_40 , & V_47 ) ;
F_31 ( & V_2 -> V_2 , L_15 , V_5 ) ;
} else {
F_31 ( & V_2 -> V_2 ,
L_16 , V_5 ) ;
}
V_9 = F_20 ( V_2 , V_40 , V_5 , 0 ,
( type == V_44 ) ?
L_17 : L_18 ,
V_18 ) ;
if ( V_9 < 0 )
goto error;
F_31 ( & V_2 -> V_2 ,
L_19 , V_5 , V_9 ) ;
}
return 0 ;
error:
F_22 ( & V_2 -> V_2 ,
L_14 ) ;
return V_9 ;
}
static int F_32 ( struct V_1 * V_2 , int V_36 , int type )
{
int V_37 = 0 ;
struct V_39 * V_40 ;
F_19 (msidesc, &dev->msi_list, list) {
struct V_13 V_14 ;
T_3 V_17 ;
V_17 = V_37 = F_33 ( V_2 ) ;
if ( V_37 < 0 )
V_17 = V_18 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_17 = V_17 ;
V_14 . type = V_58 ;
V_14 . V_20 = - 1 ;
V_14 . V_5 = - 1 ;
V_14 . V_59 = V_2 -> V_59 -> V_60 |
( F_34 ( V_2 -> V_59 ) << 16 ) ;
V_14 . V_61 = V_2 -> V_61 ;
if ( type == V_44 ) {
int V_62 ;
T_2 V_63 , V_64 ;
V_62 = F_35 ( V_2 , V_44 ) ;
F_36 ( V_2 , V_62 + V_65 ,
& V_63 ) ;
V_64 = ( T_1 ) ( V_63 & V_66 ) ;
V_14 . V_67 = F_37 ( V_2 , V_64 ) ;
V_14 . V_68 = V_40 -> V_69 . V_68 ;
}
V_37 = - V_70 ;
if ( V_71 )
V_37 = F_7 ( V_21 ,
& V_14 ) ;
if ( V_37 == - V_70 && ! F_34 ( V_2 -> V_59 ) ) {
V_14 . type = V_72 ;
V_14 . V_20 = - 1 ;
V_14 . V_5 = - 1 ;
V_14 . V_59 = V_2 -> V_59 -> V_60 ;
V_37 = F_7 ( V_21 ,
& V_14 ) ;
if ( V_37 != - V_70 )
V_71 = false ;
}
if ( V_37 ) {
F_3 ( & V_2 -> V_2 , L_20 ,
V_37 , V_17 ) ;
goto V_24;
}
V_37 = F_20 ( V_2 , V_40 ,
V_14 . V_5 , V_14 . V_20 ,
( type == V_44 ) ?
L_17 : L_18 ,
V_17 ) ;
if ( V_37 < 0 )
goto V_24;
}
V_37 = 0 ;
V_24:
return V_37 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_40 = F_39 ( V_2 -> V_73 . V_74 , struct V_39 , V_75 ) ;
if ( V_40 -> V_69 . V_76 )
F_40 ( V_2 ) ;
else
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( unsigned int V_9 )
{
F_44 ( V_9 ) ;
}
int T_4 F_45 ( void )
{
if ( ! F_12 () || F_46 () )
return - V_57 ;
F_8 ( V_34 L_21 ) ;
F_47 () ;
V_77 = F_1 ;
V_78 = NULL ;
#ifdef F_48
V_79 = 1 ;
#endif
#ifdef F_49
V_80 . V_81 = F_14 ;
V_80 . V_82 = F_43 ;
V_80 . V_83 = F_38 ;
#endif
return 0 ;
}
int T_4 F_50 ( void )
{
if ( ! F_51 ( V_84 ) )
return 0 ;
#ifdef F_48
V_85 = F_9 ;
#endif
#ifdef F_49
V_80 . V_81 = F_26 ;
V_80 . V_82 = F_43 ;
#endif
return 0 ;
}
static T_4 void F_52 ( void )
{
int V_3 ;
int V_27 , V_28 ;
int V_6 = V_86 ;
int V_9 = - 1 ;
int V_10 = - 1 ;
if ( ! V_6 )
return;
V_3 = F_53 ( V_6 , & V_27 , & V_28 ) ;
if ( V_3 ) {
F_8 ( V_22 L_22
L_23 , V_3 ) ;
return;
}
V_27 = V_27 ? V_87 : V_23 ;
V_28 = V_28 ? V_88 : V_31 ;
F_8 ( V_34 L_24
L_25 , V_6 , V_27 , V_28 ) ;
if ( F_54 ( V_6 , & V_9 ) == 0 ) {
if ( V_9 >= 0 )
V_10 = V_9 ;
}
V_6 = F_11 ( V_6 , V_10 , V_27 , V_28 ) ;
F_8 ( V_34 L_26 , V_6 ) ;
return;
}
int T_4 F_55 ( void )
{
int V_9 ;
#ifdef F_49
V_80 . V_81 = F_32 ;
V_80 . V_82 = F_43 ;
#endif
F_52 () ;
V_85 = F_13 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
int V_27 , V_28 ;
if ( F_53 ( V_9 , & V_27 , & V_28 ) == - 1 )
continue;
F_6 ( V_9 , - 1 ,
V_27 ? V_87 : V_23 ,
true ) ;
}
if ( 0 == V_89 ) {
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_4 ( V_9 , V_9 , 0 , L_27 ) ;
}
return 0 ;
}
static struct V_90 * F_56 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
F_19 (owner, &dev_domain_list, list) {
if ( V_91 -> V_2 == V_2 )
return V_91 ;
}
return NULL ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
int V_92 = - V_57 ;
F_57 ( & V_93 ) ;
V_91 = F_56 ( V_2 ) ;
if ( V_91 )
V_92 = V_91 -> V_92 ;
F_58 ( & V_93 ) ;
return V_92 ;
}
int F_59 ( struct V_1 * V_2 , T_5 V_92 )
{
struct V_90 * V_91 ;
V_91 = F_15 ( sizeof( struct V_90 ) , V_42 ) ;
if ( ! V_91 )
return - V_57 ;
F_57 ( & V_93 ) ;
if ( F_56 ( V_2 ) ) {
F_58 ( & V_93 ) ;
F_21 ( V_91 ) ;
return - V_33 ;
}
V_91 -> V_92 = V_92 ;
V_91 -> V_2 = V_2 ;
F_60 ( & V_91 -> V_75 , & V_94 ) ;
F_58 ( & V_93 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
F_57 ( & V_93 ) ;
V_91 = F_56 ( V_2 ) ;
if ( ! V_91 ) {
F_58 ( & V_93 ) ;
return - V_57 ;
}
F_62 ( & V_91 -> V_75 ) ;
F_58 ( & V_93 ) ;
F_21 ( V_91 ) ;
return 0 ;
}
