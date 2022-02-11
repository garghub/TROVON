static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type , const void * V_5 ,
const void * V_6 , unsigned V_7 )
{
struct V_8 V_9 ;
struct V_10 * V_11 ;
unsigned int V_12 ;
char * V_13 ;
V_11 = F_2 ( V_4 ) ;
V_9 . V_14 = V_15 ;
switch ( type )
{
case V_16 :
V_9 . V_17 = V_18 ;
V_12 = sizeof( V_9 . V_14 ) + sizeof( V_9 . V_17 ) ;
break;
default:
V_9 . V_19 = V_20 ;
V_9 . V_21 = V_22 ;
memset ( V_9 . V_23 , 0 , sizeof( V_9 . V_23 ) ) ;
V_9 . V_24 = F_3 ( type ) ;
V_12 = sizeof( V_9 ) ;
break;
}
V_13 = F_4 ( V_2 , V_12 ) ;
if ( ! V_13 )
return 0 ;
memcpy ( V_13 , & V_9 , V_12 ) ;
return V_12 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_25 , V_26 ;
V_11 = F_2 ( V_4 ) ;
if ( ! F_6 ( V_2 , sizeof( * V_9 ) ) ) {
F_7 ( V_27 L_1 ,
V_4 -> V_28 ) ;
V_4 -> V_29 . V_30 ++ ;
F_8 ( V_2 ) ;
return;
}
V_9 = (struct V_8 * ) V_2 -> V_31 ;
V_25 = 0 ;
V_26 = 0 ;
V_2 -> V_4 = V_4 ;
if ( V_9 -> V_14 != V_15 )
{
F_7 ( V_27 L_2 , V_4 -> V_28 , V_9 -> V_14 ) ;
V_4 -> V_29 . V_30 ++ ;
}
else
switch ( V_9 -> V_17 )
{
case V_20 :
if ( V_9 -> V_21 != V_22 )
{
F_7 ( V_27 L_3 , V_4 -> V_28 , V_9 -> V_21 ) ;
V_4 -> V_29 . V_30 ++ ;
break;
}
if ( V_9 -> V_23 [ 0 ] + V_9 -> V_23 [ 1 ] + V_9 -> V_23 [ 2 ] != 0 )
{
F_7 ( V_27 L_4 , V_4 -> V_28 , V_9 -> V_23 [ 0 ] , V_9 -> V_23 [ 1 ] , V_9 -> V_23 [ 2 ] ) ;
V_4 -> V_29 . V_30 ++ ;
break;
}
V_26 = sizeof( struct V_8 ) ;
V_2 -> V_32 = V_9 -> V_24 ;
V_25 = 1 ;
break;
case V_18 :
V_26 = sizeof( V_9 -> V_14 ) + sizeof( V_9 -> V_17 ) ;
V_2 -> V_32 = F_3 ( V_16 ) ;
V_25 = 1 ;
break;
case V_22 :
case V_33 :
case V_34 :
F_7 ( V_27 L_3 , V_4 -> V_28 , V_9 -> V_19 ) ;
V_4 -> V_29 . V_30 ++ ;
break;
default:
F_7 ( V_27 L_5 , V_4 -> V_28 , V_9 -> V_19 ) ;
V_4 -> V_29 . V_30 ++ ;
break;
}
if ( V_25 )
{
F_9 ( V_2 ) ;
F_10 ( V_2 , V_26 ) ;
V_4 -> V_29 . V_35 += V_2 -> V_7 ;
F_11 ( V_2 ) ;
V_4 -> V_29 . V_36 ++ ;
}
else
F_12 ( V_2 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
if ( V_2 )
V_11 -> V_37 -> V_38 -> V_39 ( V_2 , V_11 -> V_37 ) ;
return V_40 ;
}
static int F_14 ( struct V_3 * V_4 , struct V_41 T_2 * V_42 , int V_43 )
{
struct V_41 V_44 ;
struct V_10 * V_11 ;
struct V_45 * V_46 ;
int V_47 ;
V_11 = F_2 ( V_4 ) ;
V_46 = F_2 ( V_11 -> V_37 ) ;
if ( ! V_43 )
{
if ( F_15 ( & V_44 , V_42 , sizeof( struct V_41 ) ) )
return - V_48 ;
if ( V_44 . V_49 & ~ V_50 )
return - V_51 ;
memcpy ( & V_11 -> V_44 , & V_44 , sizeof( struct V_41 ) ) ;
V_11 -> V_52 = 1 ;
}
V_47 = (* V_46 -> V_41 )( V_11 -> V_37 , V_4 , V_43 ) ;
if ( V_47 )
return V_47 ;
if ( V_43 )
{
if ( F_16 ( V_42 , & V_11 -> V_44 , sizeof( struct V_41 ) ) )
return - V_48 ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_53 * V_54 , int V_55 )
{
struct V_10 * V_11 ;
if ( ! F_18 ( V_56 ) )
return - V_57 ;
V_11 = F_2 ( V_4 ) ;
switch ( V_55 )
{
case V_58 :
if ( ! * ( short * ) ( V_4 -> V_59 ) )
return - V_51 ;
strncpy ( V_54 -> V_60 , V_11 -> V_37 -> V_28 , sizeof( V_54 -> V_60 ) ) ;
break;
case V_61 :
case V_62 :
if ( ! * ( short * ) ( V_4 -> V_59 ) )
return - V_51 ;
return F_14 ( V_4 , V_54 -> V_63 , V_55 == V_61 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 , int V_65 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
return F_20 ( V_11 -> V_37 , V_65 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_10 * V_11 ;
struct V_45 * V_46 ;
int V_47 ;
V_11 = F_2 ( V_4 ) ;
if ( ! * ( short * ) ( V_4 -> V_59 ) )
return - V_51 ;
if ( ! F_22 ( V_11 -> V_37 ) )
return - V_66 ;
V_46 = F_2 ( V_11 -> V_37 ) ;
V_47 = (* V_46 -> V_67 )( V_11 -> V_37 , V_4 ) ;
if ( V_47 )
return V_47 ;
F_23 ( V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_10 * V_11 ;
struct V_45 * V_46 ;
int V_47 ;
F_25 ( V_4 ) ;
V_11 = F_2 ( V_4 ) ;
V_46 = F_2 ( V_11 -> V_37 ) ;
V_47 = (* V_46 -> V_68 )( V_11 -> V_37 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct F_26 * V_69 )
{
struct V_3 * V_70 , * V_37 ;
struct V_10 * V_11 ;
struct V_45 * V_46 ;
int V_47 = - V_51 ;
V_37 = F_27 ( & V_71 , V_69 -> V_72 ) ;
if ( ! V_37 )
return - V_73 ;
if ( V_37 -> type != V_74 || F_2 ( V_37 ) == NULL )
goto V_75;
V_70 = F_28 ( sizeof( struct V_10 ) , L_6 ,
V_76 ) ;
if ( ! V_70 ) {
V_47 = - V_77 ;
goto V_75;
}
F_29 () ;
F_30 (dlp, &dlci_devs, list) {
if ( V_11 -> V_37 == V_37 ) {
V_47 = - V_78 ;
goto V_79;
}
}
* ( short * ) ( V_70 -> V_59 ) = V_69 -> V_69 ;
V_11 = F_2 ( V_70 ) ;
V_11 -> V_37 = V_37 ;
V_11 -> V_70 = V_70 ;
V_46 = F_2 ( V_37 ) ;
V_47 = (* V_46 -> V_80 )( V_37 , V_70 ) ;
if ( V_47 < 0 )
goto V_79;
V_47 = F_31 ( V_70 ) ;
if ( V_47 < 0 )
goto V_79;
strcpy ( V_69 -> V_72 , V_70 -> V_28 ) ;
F_32 ( & V_11 -> V_81 , & V_82 ) ;
F_33 () ;
return 0 ;
V_79:
F_33 () ;
F_34 ( V_70 ) ;
V_75:
F_35 ( V_37 ) ;
return V_47 ;
}
static int F_36 ( struct F_26 * V_69 )
{
struct V_10 * V_11 ;
struct V_45 * V_46 ;
struct V_3 * V_70 , * V_37 ;
int V_47 ;
V_70 = F_37 ( & V_71 , V_69 -> V_72 ) ;
if ( ! V_70 )
return - V_73 ;
if ( F_22 ( V_70 ) ) {
return - V_78 ;
}
V_11 = F_2 ( V_70 ) ;
V_37 = V_11 -> V_37 ;
V_46 = F_2 ( V_37 ) ;
F_29 () ;
V_47 = (* V_46 -> V_83 )( V_37 , V_70 ) ;
if ( ! V_47 ) {
F_38 ( & V_11 -> V_81 ) ;
F_39 ( V_70 ) ;
F_35 ( V_37 ) ;
}
F_33 () ;
return V_47 ;
}
static int F_40 ( unsigned int V_55 , void T_2 * V_84 )
{
struct F_26 V_85 ;
int V_47 ;
if ( ! F_18 ( V_56 ) )
return - V_57 ;
if ( F_15 ( & V_85 , V_84 , sizeof( struct F_26 ) ) )
return - V_48 ;
switch ( V_55 )
{
case V_86 :
V_47 = F_26 ( & V_85 ) ;
if ( ! V_47 )
if ( F_16 ( V_84 , & V_85 , sizeof( struct F_26 ) ) )
return - V_48 ;
break;
case V_87 :
V_47 = F_36 ( & V_85 ) ;
break;
default:
V_47 = - V_51 ;
}
return V_47 ;
}
static void V_76 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
V_4 -> V_49 = 0 ;
V_4 -> V_88 = & V_89 ;
V_4 -> V_38 = & V_90 ;
V_4 -> V_91 = F_34 ;
V_11 -> V_92 = F_5 ;
V_4 -> type = V_93 ;
V_4 -> V_94 = sizeof( struct V_8 ) ;
V_4 -> V_95 = sizeof( short ) ;
}
static int F_41 ( struct V_96 * V_97 ,
unsigned long V_98 , void * V_99 )
{
struct V_3 * V_4 = (struct V_3 * ) V_99 ;
if ( F_42 ( V_4 ) != & V_71 )
return V_100 ;
if ( V_98 == V_101 ) {
struct V_10 * V_11 ;
F_30 (dlp, &dlci_devs, list) {
if ( V_11 -> V_37 == V_4 ) {
F_38 ( & V_11 -> V_81 ) ;
F_39 ( V_11 -> V_70 ) ;
F_35 ( V_11 -> V_37 ) ;
break;
}
}
}
return V_100 ;
}
static int T_3 F_43 ( void )
{
F_44 ( F_40 ) ;
F_45 ( & V_102 ) ;
F_7 ( L_7 , V_103 ) ;
return 0 ;
}
static void T_4 F_46 ( void )
{
struct V_10 * V_11 , * V_104 ;
F_44 ( NULL ) ;
F_47 ( & V_102 ) ;
F_29 () ;
F_48 (dlp, nxt, &dlci_devs, list) {
F_39 ( V_11 -> V_70 ) ;
F_35 ( V_11 -> V_37 ) ;
}
F_33 () ;
}
