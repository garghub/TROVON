int F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , L_1 , V_3 ) ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( F_4 ( V_2 -> V_4 ) ) {
F_2 ( 0 , L_2 , V_3 ) ;
return 0 ;
}
V_2 -> V_5 -> V_6 = 1 ;
F_5 ( V_2 ) ;
F_6 ( V_2 , V_7 , NULL , NULL ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_2 ( 0 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_8 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 ) {
F_9 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
if ( V_2 -> V_10 ) {
F_10 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
if ( V_2 -> V_11 ) {
F_11 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
if ( V_2 -> V_12 ) {
F_12 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
F_6 ( V_2 , V_13 , NULL , NULL ) ;
V_2 -> V_14 = V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_2 -> V_17 = 0 ;
memset ( & V_2 -> V_18 , 0 , sizeof( struct V_19 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_20 [ 6 ] ;
T_2 V_21 ;
F_2 ( 0 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_21 = F_13 ( V_22 ) ;
if ( V_2 -> V_23 & V_24 )
V_21 |= F_13 ( V_25 ) ;
if ( ! V_2 -> V_10 )
V_2 -> V_10 = F_14 ( V_21 ) ;
if ( ! V_2 -> V_9 )
V_2 -> V_9 = F_15 ( V_21 ,
V_26 ,
NULL , ( void * ) V_2 ) ;
if ( V_2 -> V_12 )
return;
if ( V_2 -> V_23 & V_24 ) {
V_2 -> V_12 = F_16 ( L_3 , V_27 ) ;
F_17 ( V_2 -> V_12 , L_4 ,
V_2 -> V_17 , V_28 ) ;
} else {
V_2 -> V_12 = F_16 ( L_5 , V_29 ) ;
F_17 ( V_2 -> V_12 , L_6 ,
V_2 -> V_17 , V_28 ) ;
F_18 ( V_20 , L_7 ,
V_30 , 1 , V_2 -> V_23 ,
V_31 , 1 , V_32 ) ;
F_19 ( V_2 -> V_12 , L_8 , V_20 , 6 ,
V_28 ) ;
}
F_20 ( V_2 -> V_12 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 ) {
F_12 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
#if 0
if (self->ckey) {
irlmp_unregister_client(self->ckey);
self->ckey = NULL;
}
#endif
}
int F_22 ( struct V_1 * V_2 )
{
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_2 -> V_23 & V_24 )
return 0 ;
F_2 ( 2 , L_9 , V_3 ,
V_2 -> V_18 . V_33 ) ;
if ( ! V_2 -> V_18 . V_33 )
V_2 -> V_18 . V_33 = 9600 ;
F_2 ( 2 , L_10 , V_3 ,
V_2 -> V_18 . V_34 ) ;
if ( ! V_2 -> V_18 . V_34 )
V_2 -> V_18 . V_34 = V_35 ;
F_2 ( 2 , L_11 , V_3 ,
V_2 -> V_18 . V_36 ) ;
V_2 -> V_18 . V_37 = V_38 | V_39 ;
if ( V_2 -> V_40 )
F_23 ( V_2 , V_30 , FALSE ) ;
F_23 ( V_2 , V_41 , FALSE ) ;
F_23 ( V_2 , V_42 , FALSE ) ;
if ( V_2 -> V_18 . V_23 == V_43 ) {
F_23 ( V_2 , V_44 , TRUE ) ;
return 0 ;
}
F_23 ( V_2 , V_44 , FALSE ) ;
#if 0
ircomm_param_request(self, IRCOMM_XON_XOFF, FALSE);
ircomm_param_request(self, IRCOMM_ENQ_ACK, FALSE);
#endif
F_23 ( V_2 , V_45 , TRUE ) ;
return 0 ;
}
static void V_26 ( T_3 * V_46 ,
T_4 V_47 ,
void * V_48 )
{
struct V_1 * V_2 ;
struct V_49 V_50 ;
F_2 ( 2 , L_1 , V_3 ) ;
if( V_47 == V_51 )
return;
V_50 . V_14 = V_46 -> V_14 ;
V_50 . V_15 = V_46 -> V_15 ;
V_2 = V_48 ;
F_6 ( V_2 , V_52 ,
NULL , & V_50 ) ;
}
void F_24 ( void * V_53 , void * V_54 ,
T_5 V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_2 ( 2 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( ! V_2 -> V_5 )
return;
V_2 -> V_58 = V_59 ;
V_2 -> V_5 -> V_6 = 1 ;
F_6 ( V_2 , V_60 , NULL ,
NULL ) ;
}
static void F_25 ( int V_61 , T_2 V_62 ,
struct V_63 * V_64 ,
void * V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 ;
F_2 ( 2 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_11 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( V_61 != V_65 ) {
F_2 ( 4 , L_12 , V_3 ) ;
return;
}
switch ( V_64 -> type ) {
case V_66 :
F_2 ( 2 , L_13 , V_3 ) ;
F_26 ( V_2 , V_64 -> V_67 . V_20 , V_64 -> V_68 ,
& V_69 ) ;
F_6 ( V_2 , V_70 , NULL ,
NULL ) ;
break;
case V_71 :
F_2 ( 2 , L_14 , V_3 ,
V_64 -> V_67 . integer ) ;
if ( V_64 -> V_67 . integer == - 1 ) {
F_2 ( 0 , L_15 , V_3 ) ;
} else
V_2 -> V_16 = V_64 -> V_67 . integer ;
F_6 ( V_2 , V_72 , NULL , NULL ) ;
break;
case V_73 :
F_2 ( 0 , L_16 , V_3 ) ;
break;
default:
F_2 ( 0 , L_17 , V_3 ) ;
break;
}
F_27 ( V_64 ) ;
}
void F_28 ( void * V_53 , void * V_54 ,
struct V_74 * V_75 ,
T_6 V_76 ,
T_1 V_77 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_2 ( 2 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_2 -> V_40 = TRUE ;
V_2 -> V_76 = V_76 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_58 = V_78 ;
F_6 ( V_2 , V_79 , NULL , NULL ) ;
}
void F_29 ( void * V_53 , void * V_54 ,
struct V_74 * V_75 ,
T_6 V_76 ,
T_1 V_77 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
int V_80 ;
F_2 ( 2 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_2 -> V_40 = FALSE ;
V_2 -> V_76 = V_76 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_58 = V_78 ;
V_80 = V_57 -> V_81 [ 0 ] ;
if ( V_80 )
F_26 ( V_2 , V_57 -> V_81 + 1 ,
F_30 ( V_57 -> V_68 , V_80 ) ,
& V_69 ) ;
F_6 ( V_2 , V_82 , NULL , NULL ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_2 ( 2 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
if ( ! V_2 -> V_5 )
return;
F_8 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_83 & V_84 ) && ( ( V_2 -> V_18 . V_85 & V_86 ) == 0 ) ) {
F_2 ( 0 , L_18 , V_3 ) ;
return;
} else {
F_2 ( 1 , L_19 , V_3 ) ;
V_2 -> V_5 -> V_6 = 0 ;
F_32 ( & V_2 -> V_87 ) ;
}
F_33 ( & V_2 -> V_88 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
int V_89 )
{
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_35 ( & V_2 -> V_8 , V_89 , ( void * ) V_2 ,
V_90 ) ;
}
static void V_90 ( void * V_81 )
{
struct V_1 * V_2 = (struct V_1 * ) V_81 ;
F_2 ( 2 , L_1 , V_3 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_6 ( V_2 , V_91 , NULL , NULL ) ;
}
int F_6 ( struct V_1 * V_2 , T_7 V_92 ,
struct V_56 * V_57 , struct V_49 * V_50 )
{
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_2 ( 2 , L_20 , V_3 ,
V_93 [ V_2 -> V_94 ] , V_95 [ V_92 ] ) ;
return (* V_94 [ V_2 -> V_94 ])( V_2 , V_92 , V_57 , V_50 ) ;
}
static inline void F_36 ( struct V_1 * V_2 , T_8 V_94 )
{
V_2 -> V_94 = V_94 ;
}
static int F_37 ( struct V_1 * V_2 ,
T_7 V_92 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
int V_96 = 0 ;
F_2 ( 2 , L_20 , V_3 ,
V_93 [ V_2 -> V_94 ] , V_95 [ V_92 ] ) ;
switch ( V_92 ) {
case V_7 :
F_34 ( V_2 , 3 * V_97 ) ;
F_36 ( V_2 , V_98 ) ;
F_38 ( V_99 ) ;
break;
case V_52 :
V_2 -> V_14 = V_50 -> V_14 ;
V_2 -> V_15 = V_50 -> V_15 ;
if ( V_2 -> V_11 ) {
F_39 ( L_21 ,
V_3 ) ;
return - V_100 ;
}
V_2 -> V_11 = F_40 ( V_101 , V_102 , V_2 ,
F_25 ) ;
F_41 ( V_2 -> V_11 ,
V_2 -> V_15 , V_2 -> V_14 ,
L_5 , L_8 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
F_36 ( V_2 , V_103 ) ;
break;
case V_82 :
F_8 ( & V_2 -> V_8 ) ;
F_42 ( V_2 -> V_4 , NULL ) ;
F_36 ( V_2 , V_104 ) ;
break;
case V_91 :
break;
case V_13 :
F_36 ( V_2 , V_105 ) ;
break;
default:
F_2 ( 2 , L_22 , V_3 ,
V_95 [ V_92 ] ) ;
V_96 = - V_106 ;
}
return V_96 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_7 V_92 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
int V_96 = 0 ;
F_2 ( 2 , L_20 , V_3 ,
V_93 [ V_2 -> V_94 ] , V_95 [ V_92 ] ) ;
switch ( V_92 ) {
case V_52 :
V_2 -> V_14 = V_50 -> V_14 ;
V_2 -> V_15 = V_50 -> V_15 ;
if ( V_2 -> V_11 ) {
F_39 ( L_21 ,
V_3 ) ;
return - V_100 ;
}
V_2 -> V_11 = F_40 ( V_101 , V_102 , V_2 ,
F_25 ) ;
if ( V_2 -> V_23 == V_24 ) {
F_41 ( V_2 -> V_11 , V_2 -> V_15 ,
V_2 -> V_14 , L_3 ,
L_4 ) ;
F_36 ( V_2 , V_107 ) ;
} else {
F_41 ( V_2 -> V_11 , V_2 -> V_15 ,
V_2 -> V_14 ,
L_5 ,
L_8 ) ;
F_36 ( V_2 , V_103 ) ;
}
F_34 ( V_2 , 3 * V_97 ) ;
break;
case V_82 :
F_8 ( & V_2 -> V_8 ) ;
F_21 ( V_2 ) ;
F_42 ( V_2 -> V_4 , NULL ) ;
F_36 ( V_2 , V_104 ) ;
break;
case V_91 :
#if 1
#else
F_34 ( V_2 , 3 * V_97 ) ;
F_38 ( V_99 ) ;
#endif
break;
case V_13 :
F_36 ( V_2 , V_105 ) ;
break;
default:
F_2 ( 2 , L_22 , V_3 ,
V_95 [ V_92 ] ) ;
V_96 = - V_106 ;
}
return V_96 ;
}
static int F_44 ( struct V_1 * V_2 ,
T_7 V_92 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
int V_96 = 0 ;
F_2 ( 2 , L_20 , V_3 ,
V_93 [ V_2 -> V_94 ] , V_95 [ V_92 ] ) ;
switch ( V_92 ) {
case V_70 :
if ( V_2 -> V_11 ) {
F_39 ( L_21 ,
V_3 ) ;
return - V_100 ;
}
V_2 -> V_11 = F_40 ( V_101 , V_102 , V_2 ,
F_25 ) ;
F_41 ( V_2 -> V_11 , V_2 -> V_15 ,
V_2 -> V_14 , L_5 ,
L_6 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
F_36 ( V_2 , V_107 ) ;
break;
case V_91 :
F_36 ( V_2 , V_98 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
break;
case V_82 :
F_8 ( & V_2 -> V_8 ) ;
F_21 ( V_2 ) ;
F_42 ( V_2 -> V_4 , NULL ) ;
F_36 ( V_2 , V_104 ) ;
break;
case V_13 :
F_36 ( V_2 , V_105 ) ;
break;
default:
F_2 ( 2 , L_22 , V_3 ,
V_95 [ V_92 ] ) ;
V_96 = - V_106 ;
}
return V_96 ;
}
static int F_45 ( struct V_1 * V_2 ,
T_7 V_92 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
int V_96 = 0 ;
F_2 ( 2 , L_20 , V_3 ,
V_93 [ V_2 -> V_94 ] , V_95 [ V_92 ] ) ;
switch ( V_92 ) {
case V_72 :
V_96 = F_46 ( V_2 -> V_4 , V_2 -> V_16 ,
V_2 -> V_15 , V_2 -> V_14 ,
NULL , V_2 -> V_23 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
F_36 ( V_2 , V_108 ) ;
break;
case V_91 :
F_36 ( V_2 , V_98 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
break;
case V_82 :
F_8 ( & V_2 -> V_8 ) ;
F_21 ( V_2 ) ;
F_42 ( V_2 -> V_4 , NULL ) ;
F_36 ( V_2 , V_104 ) ;
break;
case V_13 :
F_36 ( V_2 , V_105 ) ;
break;
default:
F_2 ( 2 , L_22 , V_3 ,
V_95 [ V_92 ] ) ;
V_96 = - V_106 ;
}
return V_96 ;
}
static int F_47 ( struct V_1 * V_2 ,
T_7 V_92 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
int V_96 = 0 ;
F_2 ( 2 , L_20 , V_3 ,
V_93 [ V_2 -> V_94 ] , V_95 [ V_92 ] ) ;
switch ( V_92 ) {
case V_79 :
F_8 ( & V_2 -> V_8 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_31 ( V_2 ) ;
F_36 ( V_2 , V_104 ) ;
break;
case V_82 :
F_8 ( & V_2 -> V_8 ) ;
F_21 ( V_2 ) ;
F_42 ( V_2 -> V_4 , NULL ) ;
F_36 ( V_2 , V_104 ) ;
break;
case V_91 :
F_36 ( V_2 , V_98 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
break;
case V_13 :
F_36 ( V_2 , V_105 ) ;
break;
default:
F_2 ( 2 , L_22 , V_3 ,
V_95 [ V_92 ] ) ;
V_96 = - V_106 ;
}
return V_96 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_7 V_92 ,
struct V_56 * V_57 ,
struct V_49 * V_50 )
{
int V_96 = 0 ;
switch ( V_92 ) {
case V_109 :
V_96 = F_49 ( V_2 -> V_4 , V_57 ) ;
break;
case V_13 :
F_50 ( V_2 -> V_4 , NULL ) ;
F_36 ( V_2 , V_105 ) ;
break;
case V_60 :
F_5 ( V_2 ) ;
F_36 ( V_2 , V_98 ) ;
F_34 ( V_2 , 3 * V_97 ) ;
if ( V_2 -> V_83 & V_110 ) {
V_2 -> V_18 . V_85 = V_111 ;
F_51 ( V_2 ) ;
} else {
F_2 ( 0 , L_23 , V_3 ) ;
if ( V_2 -> V_5 )
F_52 ( V_2 -> V_5 ) ;
}
break;
default:
F_2 ( 2 , L_22 , V_3 ,
V_95 [ V_92 ] ) ;
V_96 = - V_106 ;
}
return V_96 ;
}
