static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int V_5 )
{
int V_6 , V_7 ;
struct V_8 V_9 ;
int V_10 = 0 ;
char * V_11 ;
if ( ! F_2 () )
return - 1 ;
V_9 . V_12 = V_13 ;
V_9 . type = V_14 ;
V_9 . V_15 = V_3 ;
V_9 . V_16 = - 1 ;
V_6 = F_3 ( V_17 , & V_9 ) ;
if ( V_6 ) {
F_4 ( V_18 L_1 , V_6 ) ;
return - 1 ;
}
if ( V_4 == V_19 ) {
V_10 = 0 ;
V_11 = L_2 ;
} else {
V_10 = 1 ;
V_11 = L_3 ;
}
V_7 = F_5 ( V_3 , V_9 . V_16 , V_10 , V_11 ) ;
F_4 ( V_20 L_4 , V_7 , V_9 . V_16 ) ;
return V_7 ;
}
static void F_6 ( struct V_21 * V_22 , unsigned int V_16 ,
struct V_23 * V_24 )
{
V_24 -> V_25 = V_26 | F_7 ( V_16 ) ;
V_24 -> V_27 =
V_28 |
V_29 |
V_30 |
F_8 ( V_16 ) ;
V_24 -> V_31 = V_32 ;
}
static int F_9 ( struct V_21 * V_2 , int V_33 , int type )
{
int V_7 , V_16 ;
struct V_34 * V_35 ;
struct V_23 V_24 ;
F_10 (msidesc, &dev->msi_list, list) {
F_11 ( V_35 , & V_24 ) ;
V_16 = F_7 ( V_24 . V_25 ) |
( ( V_24 . V_27 >> V_36 ) & 0xff ) ;
if ( V_24 . V_31 != V_32 ||
F_12 ( V_16 ) < 0 ) {
V_16 = F_13 ( V_2 , V_35 ) ;
if ( V_16 < 0 )
goto error;
F_6 ( V_2 , V_16 , & V_24 ) ;
F_14 ( V_35 , & V_24 ) ;
F_15 ( & V_2 -> V_2 , L_5 , V_16 ) ;
} else {
F_15 ( & V_2 -> V_2 ,
L_6 , V_16 ) ;
}
V_7 = F_16 ( V_2 , V_35 , V_16 , 0 ,
( type == V_37 ) ?
L_7 : L_8 ,
V_13 ) ;
if ( V_7 < 0 )
goto error;
F_15 ( & V_2 -> V_2 ,
L_9 , V_16 , V_7 ) ;
}
return 0 ;
error:
F_17 ( & V_2 -> V_2 ,
L_10 ) ;
return - V_38 ;
}
static int F_18 ( struct V_21 * V_2 , int V_33 , int type )
{
int V_7 , V_39 , V_40 ;
struct V_34 * V_35 ;
int * V_41 ;
V_41 = F_19 ( sizeof( int ) * F_20 ( 1 , V_33 ) , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
if ( type == V_37 )
V_39 = F_21 ( V_2 , V_41 , V_33 ) ;
else
V_39 = F_22 ( V_2 , V_41 ) ;
if ( V_39 )
goto error;
V_40 = 0 ;
F_10 (msidesc, &dev->msi_list, list) {
V_7 = F_16 ( V_2 , V_35 , V_41 [ V_40 ] , 0 ,
( type == V_37 ) ?
L_11 :
L_12 ,
V_13 ) ;
if ( V_7 < 0 )
goto free;
V_40 ++ ;
}
F_23 ( V_41 ) ;
return 0 ;
error:
F_17 ( & V_2 -> V_2 , L_10 ) ;
free:
F_23 ( V_41 ) ;
return V_39 ;
}
static void F_24 ( struct V_21 * V_2 )
{
struct V_34 * V_35 ;
V_35 = F_25 ( V_2 -> V_44 . V_45 , struct V_34 , V_46 ) ;
if ( V_35 -> V_47 . V_48 )
F_26 ( V_2 ) ;
else
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( unsigned int V_7 )
{
F_30 ( V_7 ) ;
}
static int F_31 ( struct V_21 * V_2 , int V_33 , int type )
{
int V_39 = 0 ;
struct V_34 * V_35 ;
F_10 (msidesc, &dev->msi_list, list) {
struct V_8 V_9 ;
T_2 V_12 ;
V_12 = V_39 = F_32 ( V_2 ) ;
if ( V_39 < 0 )
V_12 = V_13 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = V_12 ;
V_9 . type = V_49 ;
V_9 . V_15 = - 1 ;
V_9 . V_16 = - 1 ;
V_9 . V_50 = V_2 -> V_50 -> V_51 ;
V_9 . V_52 = V_2 -> V_52 ;
if ( type == V_37 ) {
int V_53 ;
T_1 V_54 , V_55 ;
V_53 = F_33 ( V_2 , V_37 ) ;
F_34 ( V_2 , V_53 + V_56 ,
& V_54 ) ;
V_55 = ( V_57 ) ( V_54 & V_58 ) ;
V_9 . V_59 = F_35 ( V_2 , V_55 ) ;
V_9 . V_60 = V_35 -> V_47 . V_60 ;
}
V_39 = F_3 ( V_17 , & V_9 ) ;
if ( V_39 ) {
F_36 ( & V_2 -> V_2 , L_13 ,
V_39 , V_12 ) ;
goto V_61;
}
V_39 = F_16 ( V_2 , V_35 ,
V_9 . V_16 , V_9 . V_15 ,
( type == V_37 ) ?
L_7 : L_8 ,
V_12 ) ;
if ( V_39 < 0 )
goto V_61;
}
V_39 = 0 ;
V_61:
return V_39 ;
}
static int F_37 ( struct V_21 * V_2 )
{
int V_6 ;
int V_62 = 1 ;
int V_16 ;
V_57 V_3 ;
V_6 = F_38 ( V_2 , V_63 , & V_3 ) ;
if ( V_6 < 0 ) {
F_36 ( & V_2 -> V_2 , L_14 ,
V_6 ) ;
return V_6 ;
}
V_6 = F_39 ( V_3 ) ;
if ( V_6 < 0 ) {
F_36 ( & V_2 -> V_2 , L_15 ,
V_3 , V_6 ) ;
return V_6 ;
}
V_16 = V_6 ;
if ( V_3 < V_64 )
V_62 = 0 ;
V_6 = F_5 ( V_3 , V_16 , V_62 , L_16 ) ;
if ( V_6 < 0 ) {
F_36 ( & V_2 -> V_2 , L_17 ,
V_3 , V_16 , V_6 ) ;
return V_6 ;
}
V_2 -> V_7 = V_6 ;
F_40 ( & V_2 -> V_2 , L_18 , V_3 , V_2 -> V_7 ) ;
return 0 ;
}
int T_3 F_41 ( void )
{
if ( ! F_42 () || F_43 () )
return - V_38 ;
F_4 ( V_65 L_19 ) ;
F_44 () ;
V_66 = F_37 ;
V_67 = NULL ;
#ifdef F_45
V_68 = 1 ;
#endif
#ifdef F_46
V_69 . V_70 = F_18 ;
V_69 . V_71 = F_29 ;
V_69 . V_72 = F_24 ;
#endif
return 0 ;
}
int T_3 F_47 ( void )
{
if ( ! F_48 ( V_73 ) )
return 0 ;
#ifdef F_45
V_74 = F_1 ;
#endif
#ifdef F_46
V_69 . V_70 = F_9 ;
V_69 . V_71 = F_29 ;
#endif
return 0 ;
}
static int F_49 ( T_1 V_3 , int V_75 , int V_76 )
{
int V_6 , V_16 , V_7 = - 1 ;
struct V_8 V_9 ;
int V_10 = 0 ;
char * V_11 ;
if ( ! F_42 () )
return - 1 ;
if ( V_76 == V_19 ) {
V_10 = 0 ;
V_11 = L_2 ;
} else {
V_10 = 1 ;
V_11 = L_3 ;
}
V_16 = F_39 ( V_3 ) ;
if ( V_16 < 0 )
goto V_61;
if ( V_75 >= 0 )
V_7 = F_5 ( V_75 , V_16 , V_10 , V_11 ) ;
else
V_7 = F_5 ( V_3 , V_16 , V_10 , V_11 ) ;
if ( V_7 < 0 )
goto V_61;
F_4 ( V_20 L_20 , V_16 , V_7 , V_3 ) ;
V_9 . V_12 = V_13 ;
V_9 . type = V_14 ;
V_9 . V_15 = V_3 ;
V_9 . V_16 = V_16 ;
V_6 = F_3 ( V_17 , & V_9 ) ;
if ( V_6 ) {
F_4 ( V_18 L_1 , V_6 ) ;
return - 1 ;
}
V_61:
return V_7 ;
}
static int F_50 ( T_1 V_3 , int V_75 , int V_76 , int V_5 )
{
int V_6 , V_7 ;
struct V_77 V_78 ;
if ( ! F_42 () )
return - 1 ;
F_4 ( V_20 L_21 ,
V_3 , V_76 , V_5 ) ;
V_7 = F_49 ( V_3 , V_75 , V_76 ) ;
V_78 . V_3 = V_3 ;
V_78 . V_76 = ( V_76 == V_19 ? 0 : 1 ) ;
V_78 . V_5 = ( V_5 == V_79 ? 0 : 1 ) ;
V_6 = F_3 ( V_80 , & V_78 ) ;
if ( V_6 == - V_81 )
F_4 ( V_65 L_22 , V_3 ) ;
else if ( V_6 ) {
F_4 ( V_82 L_23 ,
V_3 , V_6 ) ;
}
return V_7 ;
}
static T_3 void F_51 ( void )
{
int V_6 ;
int V_4 , V_5 ;
int V_3 = V_83 ;
int V_7 = - 1 ;
int V_75 = - 1 ;
if ( ! V_3 )
return;
V_6 = F_52 ( V_3 , & V_4 , & V_5 ) ;
if ( V_6 ) {
F_4 ( V_18 L_24
L_25 , V_6 ) ;
return;
}
V_4 = V_4 ? V_84 : V_19 ;
V_5 = V_5 ? V_85 : V_79 ;
F_4 ( V_65 L_26
L_27 , V_3 , V_4 , V_5 ) ;
if ( F_53 ( V_3 , & V_7 ) == 0 ) {
if ( V_7 >= 0 && V_7 != V_3 )
V_75 = V_7 ;
}
V_3 = F_50 ( V_3 , V_75 , V_4 , V_5 ) ;
F_4 ( V_65 L_28 , V_3 ) ;
return;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int V_5 )
{
return F_50 ( V_3 , - 1 , V_4 , V_5 ) ;
}
static int T_3 F_55 ( void )
{
#ifdef F_46
V_69 . V_70 = F_31 ;
V_69 . V_71 = F_29 ;
#endif
F_51 () ;
V_74 = F_54 ;
return 0 ;
}
void T_3 F_56 ( void )
{
int V_16 , V_7 ;
F_55 () ;
if ( 0 == V_86 ) {
for ( V_7 = 0 ; V_7 < V_64 ; V_7 ++ ) {
V_16 = F_39 ( V_7 ) ;
if ( F_57 ( V_16 < 0 ,
L_29 ) )
break;
V_7 = F_5 ( V_7 , V_16 , 0 , L_30 ) ;
}
return;
}
for ( V_7 = 0 ; V_7 < V_64 ; V_7 ++ ) {
int V_4 , V_5 ;
if ( F_52 ( V_7 , & V_4 , & V_5 ) == - 1 )
continue;
F_49 ( V_7 , - 1 ,
V_4 ? V_84 : V_19 ) ;
}
}
static struct V_87 * F_58 ( struct V_21 * V_2 )
{
struct V_87 * V_88 ;
F_10 (owner, &dev_domain_list, list) {
if ( V_88 -> V_2 == V_2 )
return V_88 ;
}
return NULL ;
}
int F_32 ( struct V_21 * V_2 )
{
struct V_87 * V_88 ;
int V_89 = - V_38 ;
F_59 ( & V_90 ) ;
V_88 = F_58 ( V_2 ) ;
if ( V_88 )
V_89 = V_88 -> V_89 ;
F_60 ( & V_90 ) ;
return V_89 ;
}
int F_61 ( struct V_21 * V_2 , T_4 V_89 )
{
struct V_87 * V_88 ;
V_88 = F_19 ( sizeof( struct V_87 ) , V_42 ) ;
if ( ! V_88 )
return - V_38 ;
F_59 ( & V_90 ) ;
if ( F_58 ( V_2 ) ) {
F_60 ( & V_90 ) ;
F_23 ( V_88 ) ;
return - V_81 ;
}
V_88 -> V_89 = V_89 ;
V_88 -> V_2 = V_2 ;
F_62 ( & V_88 -> V_46 , & V_91 ) ;
F_60 ( & V_90 ) ;
return 0 ;
}
int F_63 ( struct V_21 * V_2 )
{
struct V_87 * V_88 ;
F_59 ( & V_90 ) ;
V_88 = F_58 ( V_2 ) ;
if ( ! V_88 ) {
F_60 ( & V_90 ) ;
return - V_38 ;
}
F_64 ( & V_88 -> V_46 ) ;
F_60 ( & V_90 ) ;
F_23 ( V_88 ) ;
return 0 ;
}
