int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( 0 , L_1 , V_5 ) ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( F_4 ( V_2 -> V_6 ) ) {
F_2 ( 0 , L_2 , V_5 ) ;
return 0 ;
}
V_4 = F_5 ( & V_2 -> V_7 ) ;
if ( V_4 ) {
V_4 -> V_8 = 1 ;
F_6 ( V_4 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 , V_9 , NULL , NULL ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_2 ( 0 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_10 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_11 ) {
F_11 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
if ( V_2 -> V_12 ) {
F_12 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
if ( V_2 -> V_13 ) {
F_13 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
if ( V_2 -> V_14 ) {
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_8 ( V_2 , V_15 , NULL , NULL ) ;
V_2 -> V_16 = V_2 -> V_17 = 0 ;
V_2 -> V_18 = V_2 -> V_19 = 0 ;
memset ( & V_2 -> V_20 , 0 , sizeof( struct V_21 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_22 [ 6 ] ;
T_2 V_23 ;
F_2 ( 0 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_23 = F_15 ( V_24 ) ;
if ( V_2 -> V_25 & V_26 )
V_23 |= F_15 ( V_27 ) ;
if ( ! V_2 -> V_12 )
V_2 -> V_12 = F_16 ( V_23 ) ;
if ( ! V_2 -> V_11 )
V_2 -> V_11 = F_17 ( V_23 ,
V_28 ,
NULL , ( void * ) V_2 ) ;
if ( V_2 -> V_14 )
return;
if ( V_2 -> V_25 & V_26 ) {
V_2 -> V_14 = F_18 ( L_3 , V_29 ) ;
F_19 ( V_2 -> V_14 , L_4 ,
V_2 -> V_19 , V_30 ) ;
} else {
V_2 -> V_14 = F_18 ( L_5 , V_31 ) ;
F_19 ( V_2 -> V_14 , L_6 ,
V_2 -> V_19 , V_30 ) ;
F_20 ( V_22 , L_7 ,
V_32 , 1 , V_2 -> V_25 ,
V_33 , 1 , V_34 ) ;
F_21 ( V_2 -> V_14 , L_8 , V_22 , 6 ,
V_30 ) ;
}
F_22 ( V_2 -> V_14 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 ) {
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
#if 0
if (self->ckey) {
irlmp_unregister_client(self->ckey);
self->ckey = NULL;
}
#endif
}
int F_24 ( struct V_1 * V_2 )
{
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_2 -> V_25 & V_26 )
return 0 ;
F_2 ( 2 , L_9 , V_5 ,
V_2 -> V_20 . V_35 ) ;
if ( ! V_2 -> V_20 . V_35 )
V_2 -> V_20 . V_35 = 9600 ;
F_2 ( 2 , L_10 , V_5 ,
V_2 -> V_20 . V_36 ) ;
if ( ! V_2 -> V_20 . V_36 )
V_2 -> V_20 . V_36 = V_37 ;
F_2 ( 2 , L_11 , V_5 ,
V_2 -> V_20 . V_38 ) ;
V_2 -> V_20 . V_39 = V_40 | V_41 ;
if ( V_2 -> V_42 )
F_25 ( V_2 , V_32 , FALSE ) ;
F_25 ( V_2 , V_43 , FALSE ) ;
F_25 ( V_2 , V_44 , FALSE ) ;
if ( V_2 -> V_20 . V_25 == V_45 ) {
F_25 ( V_2 , V_46 , TRUE ) ;
return 0 ;
}
F_25 ( V_2 , V_46 , FALSE ) ;
#if 0
ircomm_param_request(self, IRCOMM_XON_XOFF, FALSE);
ircomm_param_request(self, IRCOMM_ENQ_ACK, FALSE);
#endif
F_25 ( V_2 , V_47 , TRUE ) ;
return 0 ;
}
static void V_28 ( T_3 * V_48 ,
T_4 V_49 ,
void * V_50 )
{
struct V_1 * V_2 ;
struct V_51 V_52 ;
F_2 ( 2 , L_1 , V_5 ) ;
if( V_49 == V_53 )
return;
V_52 . V_16 = V_48 -> V_16 ;
V_52 . V_17 = V_48 -> V_17 ;
V_2 = V_50 ;
F_8 ( V_2 , V_54 ,
NULL , & V_52 ) ;
}
void F_26 ( void * V_55 , void * V_56 ,
T_5 V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
struct V_3 * V_4 ;
F_2 ( 2 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_4 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_4 )
return;
V_2 -> V_60 = V_61 ;
V_4 -> V_8 = 1 ;
F_8 ( V_2 , V_62 , NULL ,
NULL ) ;
F_6 ( V_4 ) ;
}
static void F_27 ( int V_63 , T_2 V_64 ,
struct V_65 * V_66 ,
void * V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
F_2 ( 2 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_13 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
if ( V_63 != V_67 ) {
F_2 ( 4 , L_12 , V_5 ) ;
return;
}
switch ( V_66 -> type ) {
case V_68 :
F_2 ( 2 , L_13 , V_5 ) ;
F_28 ( V_2 , V_66 -> V_69 . V_22 , V_66 -> V_70 ,
& V_71 ) ;
F_8 ( V_2 , V_72 , NULL ,
NULL ) ;
break;
case V_73 :
F_2 ( 2 , L_14 , V_5 ,
V_66 -> V_69 . integer ) ;
if ( V_66 -> V_69 . integer == - 1 ) {
F_2 ( 0 , L_15 , V_5 ) ;
} else
V_2 -> V_18 = V_66 -> V_69 . integer ;
F_8 ( V_2 , V_74 , NULL , NULL ) ;
break;
case V_75 :
F_2 ( 0 , L_16 , V_5 ) ;
break;
default:
F_2 ( 0 , L_17 , V_5 ) ;
break;
}
F_29 ( V_66 ) ;
}
void F_30 ( void * V_55 , void * V_56 ,
struct V_76 * V_77 ,
T_6 V_78 ,
T_1 V_79 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_2 ( 2 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_2 -> V_42 = TRUE ;
V_2 -> V_78 = V_78 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_60 = V_80 ;
F_8 ( V_2 , V_81 , NULL , NULL ) ;
}
void F_31 ( void * V_55 , void * V_56 ,
struct V_76 * V_77 ,
T_6 V_78 ,
T_1 V_79 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
int V_82 ;
F_2 ( 2 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_2 -> V_42 = FALSE ;
V_2 -> V_78 = V_78 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_60 = V_80 ;
V_82 = V_59 -> V_83 [ 0 ] ;
if ( V_82 )
F_28 ( V_2 , V_59 -> V_83 + 1 ,
F_32 ( V_59 -> V_70 , V_82 ) ,
& V_71 ) ;
F_8 ( V_2 , V_84 , NULL , NULL ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( 2 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
V_4 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_4 )
return;
F_10 ( & V_2 -> V_10 ) ;
if ( F_34 ( & V_2 -> V_7 ) &&
( ( V_2 -> V_20 . V_85 & V_86 ) == 0 ) ) {
F_2 ( 0 , L_18 , V_5 ) ;
goto V_87;
} else {
F_2 ( 1 , L_19 , V_5 ) ;
V_4 -> V_8 = 0 ;
F_35 ( & V_2 -> V_7 . V_88 ) ;
}
F_36 ( & V_2 -> V_89 ) ;
V_87:
F_6 ( V_4 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
int V_90 )
{
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_38 ( & V_2 -> V_10 , V_90 , ( void * ) V_2 ,
V_91 ) ;
}
static void V_91 ( void * V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
F_2 ( 2 , L_1 , V_5 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return;) ;
F_8 ( V_2 , V_92 , NULL , NULL ) ;
}
int F_8 ( struct V_1 * V_2 , T_7 V_93 ,
struct V_58 * V_59 , struct V_51 * V_52 )
{
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
F_2 ( 2 , L_20 , V_5 ,
V_94 [ V_2 -> V_95 ] , V_96 [ V_93 ] ) ;
return (* V_95 [ V_2 -> V_95 ])( V_2 , V_93 , V_59 , V_52 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , T_8 V_95 )
{
V_2 -> V_95 = V_95 ;
}
static int F_40 ( struct V_1 * V_2 ,
T_7 V_93 ,
struct V_58 * V_59 ,
struct V_51 * V_52 )
{
int V_97 = 0 ;
F_2 ( 2 , L_20 , V_5 ,
V_94 [ V_2 -> V_95 ] , V_96 [ V_93 ] ) ;
switch ( V_93 ) {
case V_9 :
F_37 ( V_2 , 3 * V_98 ) ;
F_39 ( V_2 , V_99 ) ;
F_41 ( V_100 ) ;
break;
case V_54 :
V_2 -> V_16 = V_52 -> V_16 ;
V_2 -> V_17 = V_52 -> V_17 ;
if ( V_2 -> V_13 ) {
F_42 ( L_21 ,
V_5 ) ;
return - V_101 ;
}
V_2 -> V_13 = F_43 ( V_102 , V_103 , V_2 ,
F_27 ) ;
F_44 ( V_2 -> V_13 ,
V_2 -> V_17 , V_2 -> V_16 ,
L_5 , L_8 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
F_39 ( V_2 , V_104 ) ;
break;
case V_84 :
F_10 ( & V_2 -> V_10 ) ;
F_45 ( V_2 -> V_6 , NULL ) ;
F_39 ( V_2 , V_105 ) ;
break;
case V_92 :
break;
case V_15 :
F_39 ( V_2 , V_106 ) ;
break;
default:
F_2 ( 2 , L_22 , V_5 ,
V_96 [ V_93 ] ) ;
V_97 = - V_107 ;
}
return V_97 ;
}
static int F_46 ( struct V_1 * V_2 ,
T_7 V_93 ,
struct V_58 * V_59 ,
struct V_51 * V_52 )
{
int V_97 = 0 ;
F_2 ( 2 , L_20 , V_5 ,
V_94 [ V_2 -> V_95 ] , V_96 [ V_93 ] ) ;
switch ( V_93 ) {
case V_54 :
V_2 -> V_16 = V_52 -> V_16 ;
V_2 -> V_17 = V_52 -> V_17 ;
if ( V_2 -> V_13 ) {
F_42 ( L_21 ,
V_5 ) ;
return - V_101 ;
}
V_2 -> V_13 = F_43 ( V_102 , V_103 , V_2 ,
F_27 ) ;
if ( V_2 -> V_25 == V_26 ) {
F_44 ( V_2 -> V_13 , V_2 -> V_17 ,
V_2 -> V_16 , L_3 ,
L_4 ) ;
F_39 ( V_2 , V_108 ) ;
} else {
F_44 ( V_2 -> V_13 , V_2 -> V_17 ,
V_2 -> V_16 ,
L_5 ,
L_8 ) ;
F_39 ( V_2 , V_104 ) ;
}
F_37 ( V_2 , 3 * V_98 ) ;
break;
case V_84 :
F_10 ( & V_2 -> V_10 ) ;
F_23 ( V_2 ) ;
F_45 ( V_2 -> V_6 , NULL ) ;
F_39 ( V_2 , V_105 ) ;
break;
case V_92 :
#if 1
#else
F_37 ( V_2 , 3 * V_98 ) ;
F_41 ( V_100 ) ;
#endif
break;
case V_15 :
F_39 ( V_2 , V_106 ) ;
break;
default:
F_2 ( 2 , L_22 , V_5 ,
V_96 [ V_93 ] ) ;
V_97 = - V_107 ;
}
return V_97 ;
}
static int F_47 ( struct V_1 * V_2 ,
T_7 V_93 ,
struct V_58 * V_59 ,
struct V_51 * V_52 )
{
int V_97 = 0 ;
F_2 ( 2 , L_20 , V_5 ,
V_94 [ V_2 -> V_95 ] , V_96 [ V_93 ] ) ;
switch ( V_93 ) {
case V_72 :
if ( V_2 -> V_13 ) {
F_42 ( L_21 ,
V_5 ) ;
return - V_101 ;
}
V_2 -> V_13 = F_43 ( V_102 , V_103 , V_2 ,
F_27 ) ;
F_44 ( V_2 -> V_13 , V_2 -> V_17 ,
V_2 -> V_16 , L_5 ,
L_6 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
F_39 ( V_2 , V_108 ) ;
break;
case V_92 :
F_39 ( V_2 , V_99 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
break;
case V_84 :
F_10 ( & V_2 -> V_10 ) ;
F_23 ( V_2 ) ;
F_45 ( V_2 -> V_6 , NULL ) ;
F_39 ( V_2 , V_105 ) ;
break;
case V_15 :
F_39 ( V_2 , V_106 ) ;
break;
default:
F_2 ( 2 , L_22 , V_5 ,
V_96 [ V_93 ] ) ;
V_97 = - V_107 ;
}
return V_97 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_7 V_93 ,
struct V_58 * V_59 ,
struct V_51 * V_52 )
{
int V_97 = 0 ;
F_2 ( 2 , L_20 , V_5 ,
V_94 [ V_2 -> V_95 ] , V_96 [ V_93 ] ) ;
switch ( V_93 ) {
case V_74 :
V_97 = F_49 ( V_2 -> V_6 , V_2 -> V_18 ,
V_2 -> V_17 , V_2 -> V_16 ,
NULL , V_2 -> V_25 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
F_39 ( V_2 , V_109 ) ;
break;
case V_92 :
F_39 ( V_2 , V_99 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
break;
case V_84 :
F_10 ( & V_2 -> V_10 ) ;
F_23 ( V_2 ) ;
F_45 ( V_2 -> V_6 , NULL ) ;
F_39 ( V_2 , V_105 ) ;
break;
case V_15 :
F_39 ( V_2 , V_106 ) ;
break;
default:
F_2 ( 2 , L_22 , V_5 ,
V_96 [ V_93 ] ) ;
V_97 = - V_107 ;
}
return V_97 ;
}
static int F_50 ( struct V_1 * V_2 ,
T_7 V_93 ,
struct V_58 * V_59 ,
struct V_51 * V_52 )
{
int V_97 = 0 ;
F_2 ( 2 , L_20 , V_5 ,
V_94 [ V_2 -> V_95 ] , V_96 [ V_93 ] ) ;
switch ( V_93 ) {
case V_81 :
F_10 ( & V_2 -> V_10 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_33 ( V_2 ) ;
F_39 ( V_2 , V_105 ) ;
break;
case V_84 :
F_10 ( & V_2 -> V_10 ) ;
F_23 ( V_2 ) ;
F_45 ( V_2 -> V_6 , NULL ) ;
F_39 ( V_2 , V_105 ) ;
break;
case V_92 :
F_39 ( V_2 , V_99 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
break;
case V_15 :
F_39 ( V_2 , V_106 ) ;
break;
default:
F_2 ( 2 , L_22 , V_5 ,
V_96 [ V_93 ] ) ;
V_97 = - V_107 ;
}
return V_97 ;
}
static int F_51 ( struct V_1 * V_2 ,
T_7 V_93 ,
struct V_58 * V_59 ,
struct V_51 * V_52 )
{
int V_97 = 0 ;
switch ( V_93 ) {
case V_110 :
V_97 = F_52 ( V_2 -> V_6 , V_59 ) ;
break;
case V_15 :
F_53 ( V_2 -> V_6 , NULL ) ;
F_39 ( V_2 , V_106 ) ;
break;
case V_62 :
F_7 ( V_2 ) ;
F_39 ( V_2 , V_99 ) ;
F_37 ( V_2 , 3 * V_98 ) ;
if ( V_2 -> V_7 . V_111 & V_112 ) {
V_2 -> V_20 . V_85 = V_113 ;
F_54 ( V_2 ) ;
} else {
F_2 ( 0 , L_23 , V_5 ) ;
F_55 ( & V_2 -> V_7 , false ) ;
}
break;
default:
F_2 ( 2 , L_22 , V_5 ,
V_96 [ V_93 ] ) ;
V_97 = - V_107 ;
}
return V_97 ;
}
