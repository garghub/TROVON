static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type , const void * V_5 ,
const void * V_6 , unsigned V_7 )
{
struct V_8 V_9 ;
unsigned int V_10 ;
char * V_11 ;
V_9 . V_12 = V_13 ;
switch ( type )
{
case V_14 :
V_9 . V_15 = V_16 ;
V_10 = sizeof( V_9 . V_12 ) + sizeof( V_9 . V_15 ) ;
break;
default:
V_9 . V_17 = V_18 ;
V_9 . V_19 = V_20 ;
memset ( V_9 . V_21 , 0 , sizeof( V_9 . V_21 ) ) ;
V_9 . V_22 = F_2 ( type ) ;
V_10 = sizeof( V_9 ) ;
break;
}
V_11 = F_3 ( V_2 , V_10 ) ;
if ( ! V_11 )
return 0 ;
memcpy ( V_11 , & V_9 , V_10 ) ;
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_23 , V_24 ;
if ( ! F_5 ( V_2 , sizeof( * V_9 ) ) ) {
F_6 ( V_4 , L_1 ) ;
V_4 -> V_25 . V_26 ++ ;
F_7 ( V_2 ) ;
return;
}
V_9 = (struct V_8 * ) V_2 -> V_27 ;
V_23 = 0 ;
V_24 = 0 ;
V_2 -> V_4 = V_4 ;
if ( V_9 -> V_12 != V_13 )
{
F_6 ( V_4 , L_2 ,
V_9 -> V_12 ) ;
V_4 -> V_25 . V_26 ++ ;
}
else
switch ( V_9 -> V_15 )
{
case V_18 :
if ( V_9 -> V_19 != V_20 )
{
F_6 ( V_4 , L_3 ,
V_9 -> V_19 ) ;
V_4 -> V_25 . V_26 ++ ;
break;
}
if ( V_9 -> V_21 [ 0 ] + V_9 -> V_21 [ 1 ] + V_9 -> V_21 [ 2 ] != 0 )
{
F_6 ( V_4 , L_4 ,
V_9 -> V_21 [ 0 ] ,
V_9 -> V_21 [ 1 ] ,
V_9 -> V_21 [ 2 ] ) ;
V_4 -> V_25 . V_26 ++ ;
break;
}
V_24 = sizeof( struct V_8 ) ;
V_2 -> V_28 = V_9 -> V_22 ;
V_23 = 1 ;
break;
case V_16 :
V_24 = sizeof( V_9 -> V_12 ) + sizeof( V_9 -> V_15 ) ;
V_2 -> V_28 = F_2 ( V_14 ) ;
V_23 = 1 ;
break;
case V_20 :
case V_29 :
case V_30 :
F_6 ( V_4 , L_3 ,
V_9 -> V_17 ) ;
V_4 -> V_25 . V_26 ++ ;
break;
default:
F_6 ( V_4 , L_5 ,
V_9 -> V_17 ) ;
V_4 -> V_25 . V_26 ++ ;
break;
}
if ( V_23 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 , V_24 ) ;
V_4 -> V_25 . V_31 += V_2 -> V_7 ;
F_10 ( V_2 ) ;
V_4 -> V_25 . V_32 ++ ;
}
else
F_11 ( V_2 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_33 * V_34 = F_13 ( V_4 ) ;
if ( V_2 )
V_34 -> V_35 -> V_36 -> V_37 ( V_2 , V_34 -> V_35 ) ;
return V_38 ;
}
static int F_14 ( struct V_3 * V_4 , struct V_39 T_2 * V_40 , int V_41 )
{
struct V_39 V_42 ;
struct V_33 * V_34 ;
struct V_43 * V_44 ;
int V_45 ;
V_34 = F_13 ( V_4 ) ;
V_44 = F_13 ( V_34 -> V_35 ) ;
if ( ! V_41 )
{
if ( F_15 ( & V_42 , V_40 , sizeof( struct V_39 ) ) )
return - V_46 ;
if ( V_42 . V_47 & ~ V_48 )
return - V_49 ;
memcpy ( & V_34 -> V_42 , & V_42 , sizeof( struct V_39 ) ) ;
V_34 -> V_50 = 1 ;
}
V_45 = (* V_44 -> V_39 )( V_34 -> V_35 , V_4 , V_41 ) ;
if ( V_45 )
return V_45 ;
if ( V_41 )
{
if ( F_16 ( V_40 , & V_34 -> V_42 , sizeof( struct V_39 ) ) )
return - V_46 ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_51 * V_52 , int V_53 )
{
struct V_33 * V_34 ;
if ( ! F_18 ( V_54 ) )
return - V_55 ;
V_34 = F_13 ( V_4 ) ;
switch ( V_53 )
{
case V_56 :
if ( ! * ( short * ) ( V_4 -> V_57 ) )
return - V_49 ;
strncpy ( V_52 -> V_58 , V_34 -> V_35 -> V_59 , sizeof( V_52 -> V_58 ) ) ;
break;
case V_60 :
case V_61 :
if ( ! * ( short * ) ( V_4 -> V_57 ) )
return - V_49 ;
return F_14 ( V_4 , V_52 -> V_62 , V_53 == V_60 ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 , int V_64 )
{
struct V_33 * V_34 = F_13 ( V_4 ) ;
return F_20 ( V_34 -> V_35 , V_64 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_33 * V_34 ;
struct V_43 * V_44 ;
int V_45 ;
V_34 = F_13 ( V_4 ) ;
if ( ! * ( short * ) ( V_4 -> V_57 ) )
return - V_49 ;
if ( ! F_22 ( V_34 -> V_35 ) )
return - V_65 ;
V_44 = F_13 ( V_34 -> V_35 ) ;
V_45 = (* V_44 -> V_66 )( V_34 -> V_35 , V_4 ) ;
if ( V_45 )
return V_45 ;
F_23 ( V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_33 * V_34 ;
struct V_43 * V_44 ;
int V_45 ;
F_25 ( V_4 ) ;
V_34 = F_13 ( V_4 ) ;
V_44 = F_13 ( V_34 -> V_35 ) ;
V_45 = (* V_44 -> V_67 )( V_34 -> V_35 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct F_26 * V_68 )
{
struct V_3 * V_69 , * V_35 ;
struct V_33 * V_34 ;
struct V_43 * V_44 ;
int V_45 = - V_49 ;
V_35 = F_27 ( & V_70 , V_68 -> V_71 ) ;
if ( ! V_35 )
return - V_72 ;
if ( V_35 -> type != V_73 || F_13 ( V_35 ) == NULL )
goto V_74;
V_69 = F_28 ( sizeof( struct V_33 ) , L_6 ,
V_75 ) ;
if ( ! V_69 ) {
V_45 = - V_76 ;
goto V_74;
}
F_29 () ;
F_30 (dlp, &dlci_devs, list) {
if ( V_34 -> V_35 == V_35 ) {
V_45 = - V_77 ;
goto V_78;
}
}
* ( short * ) ( V_69 -> V_57 ) = V_68 -> V_68 ;
V_34 = F_13 ( V_69 ) ;
V_34 -> V_35 = V_35 ;
V_34 -> V_69 = V_69 ;
V_44 = F_13 ( V_35 ) ;
V_45 = (* V_44 -> V_79 )( V_35 , V_69 ) ;
if ( V_45 < 0 )
goto V_78;
V_45 = F_31 ( V_69 ) ;
if ( V_45 < 0 )
goto V_78;
strcpy ( V_68 -> V_71 , V_69 -> V_59 ) ;
F_32 ( & V_34 -> V_80 , & V_81 ) ;
F_33 () ;
return 0 ;
V_78:
F_33 () ;
F_34 ( V_69 ) ;
V_74:
F_35 ( V_35 ) ;
return V_45 ;
}
static int F_36 ( struct F_26 * V_68 )
{
struct V_33 * V_34 ;
struct V_43 * V_44 ;
struct V_3 * V_69 , * V_35 ;
int V_45 ;
bool V_82 = false ;
F_29 () ;
V_69 = F_37 ( & V_70 , V_68 -> V_71 ) ;
if ( ! V_69 ) {
V_45 = - V_72 ;
goto V_83;
}
F_30 (dlp, &dlci_devs, list) {
if ( V_34 -> V_69 == V_69 ) {
V_82 = true ;
break;
}
}
if ( ! V_82 ) {
V_45 = - V_72 ;
goto V_83;
}
if ( F_22 ( V_69 ) ) {
V_45 = - V_77 ;
goto V_83;
}
V_34 = F_13 ( V_69 ) ;
V_35 = V_34 -> V_35 ;
V_44 = F_13 ( V_35 ) ;
V_45 = (* V_44 -> V_84 )( V_35 , V_69 ) ;
if ( ! V_45 ) {
F_38 ( & V_34 -> V_80 ) ;
F_39 ( V_69 ) ;
F_35 ( V_35 ) ;
}
V_83:
F_33 () ;
return V_45 ;
}
static int F_40 ( unsigned int V_53 , void T_2 * V_85 )
{
struct F_26 V_86 ;
int V_45 ;
if ( ! F_18 ( V_54 ) )
return - V_55 ;
if ( F_15 ( & V_86 , V_85 , sizeof( struct F_26 ) ) )
return - V_46 ;
switch ( V_53 )
{
case V_87 :
V_45 = F_26 ( & V_86 ) ;
if ( ! V_45 )
if ( F_16 ( V_85 , & V_86 , sizeof( struct F_26 ) ) )
return - V_46 ;
break;
case V_88 :
V_45 = F_36 ( & V_86 ) ;
break;
default:
V_45 = - V_49 ;
}
return V_45 ;
}
static void V_75 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = F_13 ( V_4 ) ;
V_4 -> V_47 = 0 ;
V_4 -> V_89 = & V_90 ;
V_4 -> V_36 = & V_91 ;
V_4 -> V_92 = F_34 ;
V_34 -> V_93 = F_4 ;
V_4 -> type = V_94 ;
V_4 -> V_95 = sizeof( struct V_8 ) ;
V_4 -> V_96 = sizeof( short ) ;
}
static int F_41 ( struct V_97 * V_98 ,
unsigned long V_99 , void * V_100 )
{
struct V_3 * V_4 = F_42 ( V_100 ) ;
if ( F_43 ( V_4 ) != & V_70 )
return V_101 ;
if ( V_99 == V_102 ) {
struct V_33 * V_34 ;
F_30 (dlp, &dlci_devs, list) {
if ( V_34 -> V_35 == V_4 ) {
F_38 ( & V_34 -> V_80 ) ;
F_39 ( V_34 -> V_69 ) ;
F_35 ( V_34 -> V_35 ) ;
break;
}
}
}
return V_101 ;
}
static int T_3 F_44 ( void )
{
F_45 ( F_40 ) ;
F_46 ( & V_103 ) ;
F_47 ( L_7 , V_104 ) ;
return 0 ;
}
static void T_4 F_48 ( void )
{
struct V_33 * V_34 , * V_105 ;
F_45 ( NULL ) ;
F_49 ( & V_103 ) ;
F_29 () ;
F_50 (dlp, nxt, &dlci_devs, list) {
F_39 ( V_34 -> V_69 ) ;
F_35 ( V_34 -> V_35 ) ;
}
F_33 () ;
}
