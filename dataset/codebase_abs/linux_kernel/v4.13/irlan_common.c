static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 ;
#ifdef F_2
{ struct V_4 * V_5 ;
V_5 = F_3 ( L_1 , 0 , V_6 , & V_7 ) ;
if ( ! V_5 ) {
F_4 ( V_8 L_2 ) ;
return - V_9 ;
}
}
#endif
V_3 = F_5 ( V_10 ) ;
V_11 = F_6 ( V_3 , & V_12 ,
NULL , NULL ) ;
if ( ! V_11 )
goto V_13;
V_14 = F_7 ( V_3 ) ;
if ( ! V_14 )
goto V_15;
V_2 = F_8 ( V_16 , V_16 ) ;
if ( ! V_2 )
goto V_17;
F_9 ( V_2 ) ;
F_10 ( V_18 ) ;
return 0 ;
V_17:
F_11 ( V_14 ) ;
V_15:
F_12 ( V_11 ) ;
V_13:
#ifdef F_2
F_13 ( L_1 , V_6 ) ;
#endif
return - V_19 ;
}
static void T_3 F_14 ( void )
{
struct V_1 * V_20 , * V_21 ;
F_12 ( V_11 ) ;
F_11 ( V_14 ) ;
#ifdef F_2
F_13 ( L_1 , V_6 ) ;
#endif
F_15 () ;
F_16 (self, next, &irlans, dev_list) {
F_17 ( V_20 ) ;
}
F_18 () ;
}
static struct V_1 T_1 * F_8 ( T_4 V_22 , T_4 V_23 )
{
struct V_24 * V_25 ;
struct V_1 * V_20 ;
V_25 = F_19 ( V_26 ? L_3 : L_4 ) ;
if ( ! V_25 )
return NULL ;
V_20 = F_20 ( V_25 ) ;
V_20 -> V_25 = V_25 ;
V_20 -> V_27 = V_28 ;
V_20 -> V_22 = V_22 ;
V_20 -> V_23 = V_23 ;
V_20 -> V_29 . V_30 = V_31 ;
if ( V_31 == V_32 ) {
V_25 -> V_33 [ 0 ] = 0x40 ;
V_25 -> V_33 [ 1 ] = 0x00 ;
V_25 -> V_33 [ 2 ] = 0x00 ;
V_25 -> V_33 [ 3 ] = 0x00 ;
F_21 ( V_25 -> V_33 + 4 , 1 ) ;
F_21 ( V_25 -> V_33 + 5 , 1 ) ;
}
V_20 -> V_34 = V_35 ;
V_20 -> V_36 = V_37 ;
F_22 ( & V_20 -> V_38 ) ;
F_22 ( & V_20 -> V_39 . V_40 ) ;
F_23 ( & V_20 -> V_41 ) ;
F_24 ( & V_20 -> V_39 . V_42 ) ;
F_25 ( V_20 , V_43 ) ;
F_26 ( V_20 , V_43 ) ;
if ( F_27 ( V_25 ) ) {
F_28 ( L_5 ,
V_44 ) ;
V_20 = NULL ;
F_29 ( V_25 ) ;
} else {
F_15 () ;
F_30 ( & V_20 -> V_45 , & V_46 ) ;
F_18 () ;
}
return V_20 ;
}
static void F_17 ( struct V_1 * V_20 )
{
F_31 () ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
F_33 ( & V_20 -> V_38 ) ;
F_33 ( & V_20 -> V_39 . V_40 ) ;
F_34 ( V_20 ) ;
if ( V_20 -> V_39 . V_47 )
F_35 ( V_20 -> V_39 . V_47 ) ;
F_36 ( & V_20 -> V_39 . V_42 ) ;
F_37 ( V_20 -> V_25 ) ;
}
struct V_1 * F_38 ( void )
{
struct V_1 * V_20 ;
F_39 (self, &irlans, dev_list) {
return V_20 ;
}
return NULL ;
}
static void F_40 ( void * V_48 , void * V_49 ,
struct V_50 * V_51 ,
T_4 V_52 ,
T_5 V_53 ,
struct V_54 * V_55 )
{
struct V_1 * V_20 ;
struct V_56 * V_57 ;
V_20 = V_48 ;
V_57 = V_49 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
F_32 (tsap == self->tsap_data,return;) ;
V_20 -> V_52 = V_52 ;
V_20 -> V_53 = V_53 ;
F_28 ( L_6 , V_44 ) ;
F_41 ( & V_20 -> V_38 ) ;
if ( V_55 )
F_42 ( V_55 ) ;
F_43 ( V_20 , V_58 , NULL ) ;
F_44 ( V_20 , V_58 , NULL ) ;
if ( V_20 -> V_29 . V_30 == V_59 ) {
F_45 ( V_20 ) ;
F_46 ( V_20 ) ;
}
F_47 ( V_20 -> V_25 ) ;
}
static void F_48 ( void * V_48 , void * V_49 ,
struct V_50 * V_51 ,
T_4 V_52 ,
T_5 V_53 ,
struct V_54 * V_55 )
{
struct V_1 * V_20 ;
V_20 = V_48 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_20 -> V_52 = V_52 ;
V_20 -> V_53 = V_53 ;
F_28 ( L_6 , V_44 ) ;
F_41 ( & V_20 -> V_38 ) ;
F_45 ( V_20 ) ;
F_46 ( V_20 ) ;
F_49 ( V_20 , TRUE ) ;
F_50 ( V_20 , TRUE ) ;
F_47 ( V_20 -> V_25 ) ;
V_20 -> V_36 = 0 ;
F_51 ( & V_20 -> V_41 ) ;
}
static void F_52 ( void * V_48 ,
void * V_49 , T_6 V_60 ,
struct V_54 * V_61 )
{
struct V_1 * V_20 ;
struct V_56 * V_57 ;
F_28 ( L_7 , V_44 , V_60 ) ;
V_20 = V_48 ;
V_57 = V_49 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
F_32 (tsap != NULL, return;) ;
F_32 (tsap->magic == TTP_TSAP_MAGIC, return;) ;
F_32 (tsap == self->tsap_data, return;) ;
F_28 ( L_8 ) ;
V_20 -> V_36 = V_60 ;
switch ( V_60 ) {
case V_37 :
F_28 ( L_9 , V_44 ) ;
break;
case V_62 :
F_28 ( L_10 , V_44 ) ;
break;
case V_63 :
F_28 ( L_11 , V_44 ) ;
break;
case V_64 :
F_28 ( L_12 , V_44 ) ;
break;
case V_65 :
F_28 ( L_13 , V_44 ) ;
break;
default:
F_53 ( L_14 ,
V_44 ) ;
break;
}
if ( V_61 )
F_42 ( V_61 ) ;
F_44 ( V_20 , V_66 , NULL ) ;
F_43 ( V_20 , V_66 , NULL ) ;
F_51 ( & V_20 -> V_41 ) ;
}
void F_54 ( struct V_1 * V_20 )
{
struct V_56 * V_57 ;
T_7 V_67 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
if ( V_20 -> V_68 )
return;
F_55 ( & V_67 ) ;
V_67 . V_69 = V_70 ;
V_67 . V_71 = V_70 ;
V_67 . V_72 = F_40 ;
V_67 . V_73 = F_48 ;
V_67 . V_74 = V_75 ;
V_67 . V_76 = F_52 ;
V_67 . V_48 = V_20 ;
F_56 ( V_67 . V_77 , L_15 , sizeof( V_67 . V_77 ) ) ;
V_57 = F_57 ( V_78 , V_79 , & V_67 ) ;
if ( ! V_57 ) {
F_28 ( L_16 , V_44 ) ;
return;
}
V_20 -> V_68 = V_57 ;
V_20 -> V_80 = V_20 -> V_68 -> V_81 ;
}
void F_34 ( struct V_1 * V_20 )
{
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
if ( V_20 -> V_68 ) {
F_58 ( V_20 -> V_68 , NULL , V_82 ) ;
F_59 ( V_20 -> V_68 ) ;
V_20 -> V_68 = NULL ;
}
if ( V_20 -> V_39 . V_83 ) {
F_58 ( V_20 -> V_39 . V_83 , NULL ,
V_82 ) ;
F_59 ( V_20 -> V_39 . V_83 ) ;
V_20 -> V_39 . V_83 = NULL ;
}
if ( V_20 -> V_29 . V_83 ) {
F_58 ( V_20 -> V_29 . V_83 , NULL ,
V_82 ) ;
F_59 ( V_20 -> V_29 . V_83 ) ;
V_20 -> V_29 . V_83 = NULL ;
}
V_20 -> V_36 = V_37 ;
}
void F_60 ( struct V_1 * V_20 , T_5 V_84 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
if ( ! F_61 ( L_17 ) ) {
V_86 = F_62 ( L_17 , V_89 ) ;
F_63 ( V_86 , L_18 , V_84 ,
V_90 ) ;
F_64 ( V_86 ) ;
} else {
V_88 = F_65 ( V_84 ) ;
F_66 ( L_17 , L_18 ,
V_88 ) ;
}
if ( ! F_61 ( L_19 ) ) {
V_86 = F_62 ( L_19 , V_91 ) ;
#if 0
irias_add_string_attrib(obj, "Name", sysctl_devname,
IAS_KERNEL_ATTR);
#else
F_67 ( V_86 , L_20 , L_21 , V_90 ) ;
#endif
F_67 ( V_86 , L_22 , L_23 ,
V_90 ) ;
F_63 ( V_86 , L_24 , 1 , V_90 ) ;
if ( V_20 -> V_29 . V_30 == V_59 )
F_67 ( V_86 , L_25 , L_26 ,
V_90 ) ;
else
F_67 ( V_86 , L_25 , L_27 ,
V_90 ) ;
F_67 ( V_86 , L_28 ,
L_29 , V_90 ) ;
F_64 ( V_86 ) ;
}
}
int F_68 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
if ( F_69 ( & V_20 -> V_39 . V_92 ) == FALSE )
return - V_93 ;
V_55 = F_70 ( & V_20 -> V_39 . V_42 ) ;
if ( ! V_55 ) {
V_20 -> V_39 . V_92 = FALSE ;
return 0 ;
}
if ( ( V_20 -> V_39 . V_83 == NULL ) ||
( V_20 -> V_39 . V_94 == V_43 ) )
{
V_20 -> V_39 . V_92 = FALSE ;
F_42 ( V_55 ) ;
return - 1 ;
}
F_28 ( L_30 , V_44 ) ;
return F_71 ( V_20 -> V_39 . V_83 , V_55 ) ;
}
static void F_72 ( struct V_1 * V_20 , struct V_54 * V_55 )
{
F_73 ( & V_20 -> V_39 . V_42 , V_55 ) ;
F_68 ( V_20 ) ;
}
void F_74 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_100 ;
V_95 [ 1 ] = 0x00 ;
F_72 ( V_20 , V_55 ) ;
}
void F_78 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 +
F_79 ( L_31 , L_32 ) +
F_79 ( L_33 , L_34 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_101 ;
V_95 [ 1 ] = 0x02 ;
F_80 ( V_55 , L_31 , L_32 ) ;
F_80 ( V_55 , L_33 , L_34 ) ;
F_72 ( V_20 , V_55 ) ;
}
void F_81 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
if ( V_20 -> V_39 . V_83 == NULL )
return;
V_55 = F_75 ( V_96 + V_97 +
F_82 ( L_35 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_102 ;
V_95 [ 1 ] = 0x01 ;
F_83 ( V_55 , L_35 , V_20 -> V_103 ) ;
F_72 ( V_20 , V_55 ) ;
}
static void F_46 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 +
F_82 ( L_35 ) +
F_79 ( L_36 , L_37 ) +
F_79 ( L_38 , L_39 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_104 ;
V_95 [ 1 ] = 0x03 ;
F_83 ( V_55 , L_35 , V_20 -> V_103 ) ;
F_80 ( V_55 , L_36 , L_37 ) ;
F_80 ( V_55 , L_38 , L_39 ) ;
F_72 ( V_20 , V_55 ) ;
}
void F_49 ( struct V_1 * V_20 , int V_105 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 +
F_82 ( L_35 ) +
F_79 ( L_36 , L_40 ) +
F_79 ( L_38 , L_39 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_104 ;
V_95 [ 1 ] = 0x03 ;
F_83 ( V_55 , L_35 , V_20 -> V_103 ) ;
F_80 ( V_55 , L_36 , L_40 ) ;
if ( V_105 )
F_80 ( V_55 , L_38 , L_39 ) ;
else
F_80 ( V_55 , L_38 , L_41 ) ;
F_72 ( V_20 , V_55 ) ;
}
void F_50 ( struct V_1 * V_20 , int V_105 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 +
F_82 ( L_35 ) +
F_79 ( L_36 , L_42 ) +
F_79 ( L_38 , L_41 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_104 ;
V_95 [ 1 ] = 0x03 ;
F_83 ( V_55 , L_35 , V_20 -> V_103 ) ;
F_80 ( V_55 , L_36 , L_42 ) ;
if ( V_105 )
F_80 ( V_55 , L_38 , L_43 ) ;
else
F_80 ( V_55 , L_38 , L_41 ) ;
F_72 ( V_20 , V_55 ) ;
}
static void F_45 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 +
F_82 ( L_35 ) +
F_79 ( L_36 , L_37 ) +
F_79 ( L_44 ,
L_45 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_104 ;
V_95 [ 1 ] = 0x03 ;
F_83 ( V_55 , L_35 , V_20 -> V_103 ) ;
F_80 ( V_55 , L_36 , L_37 ) ;
F_80 ( V_55 , L_44 , L_45 ) ;
F_72 ( V_20 , V_55 ) ;
}
void F_84 ( struct V_1 * V_20 )
{
struct V_54 * V_55 ;
T_5 * V_95 ;
F_32 (self != NULL, return;) ;
F_32 (self->magic == IRLAN_MAGIC, return;) ;
V_55 = F_75 ( V_96 + V_97 +
F_79 ( L_31 , L_32 ) ,
V_98 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 , V_20 -> V_39 . V_53 ) ;
F_77 ( V_55 , 2 ) ;
V_95 = V_55 -> V_99 ;
V_95 [ 0 ] = V_106 ;
V_95 [ 1 ] = 0x01 ;
F_80 ( V_55 , L_31 , L_32 ) ;
F_72 ( V_20 , V_55 ) ;
}
int F_83 ( struct V_54 * V_55 , char * V_107 , T_5 V_108 )
{
return F_85 ( V_55 , V_107 , V_109 , V_108 , 0 , NULL , 0 ) ;
}
int F_86 ( struct V_54 * V_55 , char * V_107 , T_2 V_108 )
{
return F_85 ( V_55 , V_107 , V_110 , 0 , V_108 , NULL , 0 ) ;
}
int F_80 ( struct V_54 * V_55 , char * V_107 , char * string )
{
int V_111 = strlen ( string ) ;
return F_85 ( V_55 , V_107 , V_112 , 0 , 0 , string ,
V_111 ) ;
}
int F_87 ( struct V_54 * V_55 , char * V_77 , T_5 * V_113 ,
T_2 V_114 )
{
return F_85 ( V_55 , V_77 , V_112 , 0 , 0 , V_113 ,
V_114 ) ;
}
static int F_85 ( struct V_54 * V_55 , char * V_107 , int type ,
T_5 V_115 , T_2 V_116 ,
T_5 * V_117 , T_2 V_118 )
{
T_5 * V_95 ;
T_5 V_119 ;
T_8 V_120 ;
int V_121 = 0 ;
if ( V_55 == NULL ) {
F_28 ( L_46 , V_44 ) ;
return 0 ;
}
V_119 = strlen ( V_107 ) ;
switch ( type ) {
case V_109 :
V_118 = 1 ;
break;
case V_110 :
V_118 = 2 ;
break;
case V_112 :
F_32 (value_array != NULL, return 0;) ;
F_32 (value_len > 0 , return 0;) ;
break;
default:
F_28 ( L_47 , V_44 ) ;
return 0 ;
}
V_95 = F_88 ( V_55 ) ;
if ( F_89 ( V_55 ) < ( V_119 + V_118 + 3 ) ) {
F_28 ( L_48 , V_44 ) ;
return 0 ;
}
F_77 ( V_55 , V_119 + V_118 + 3 ) ;
V_95 [ V_121 ++ ] = V_119 ;
memcpy ( V_95 + V_121 , V_107 , V_119 ) ; V_121 += V_119 ;
V_120 = F_90 ( V_118 ) ;
memcpy ( V_95 + V_121 , & V_120 , 2 ) ; V_121 += 2 ;
switch ( type ) {
case V_109 :
V_95 [ V_121 ++ ] = V_115 ;
break;
case V_110 :
V_120 = F_90 ( V_116 ) ;
memcpy ( V_95 + V_121 , & V_120 , 2 ) ; V_121 += 2 ;
break;
case V_112 :
memcpy ( V_95 + V_121 , V_117 , V_118 ) ; V_121 += V_118 ;
break;
default:
break;
}
F_32 (n == (param_len+value_len+3), return 0;) ;
return V_119 + V_118 + 3 ;
}
int F_91 ( T_5 * V_122 , char * V_77 , char * V_108 , T_2 * V_123 )
{
T_5 V_124 ;
T_2 V_125 ;
int V_121 = 0 ;
V_124 = V_122 [ V_121 ++ ] ;
if ( V_124 > 254 ) {
F_28 ( L_49 , V_44 ) ;
return - V_126 ;
}
memcpy ( V_77 , V_122 + V_121 , V_124 ) ;
V_77 [ V_124 ] = '\0' ;
V_121 += V_124 ;
memcpy ( & V_125 , V_122 + V_121 , 2 ) ;
F_92 ( & V_125 ) ; V_121 += 2 ;
if ( V_125 >= 1016 ) {
F_28 ( L_50 , V_44 ) ;
return - V_126 ;
}
* V_123 = V_125 ;
memcpy ( V_108 , V_122 + V_121 , V_125 ) ;
V_108 [ V_125 ] = '\0' ;
V_121 += V_125 ;
F_28 ( L_51 , V_77 ) ;
F_28 ( L_52 , V_108 ) ;
return V_121 ;
}
static void * F_93 ( struct V_127 * V_128 , T_9 * V_129 )
{
F_94 () ;
return F_95 ( & V_46 , * V_129 ) ;
}
static void * F_96 ( struct V_127 * V_128 , void * V_130 , T_9 * V_129 )
{
return F_97 ( V_130 , & V_46 , V_129 ) ;
}
static void F_98 ( struct V_127 * V_128 , void * V_130 )
{
F_99 () ;
}
static int F_100 ( struct V_127 * V_128 , void * V_130 )
{
if ( V_130 == & V_46 )
F_101 ( V_128 , L_53 ) ;
else {
struct V_1 * V_20 = F_102 ( V_130 , struct V_1 , V_45 ) ;
F_32 (self != NULL, return -1;) ;
F_32 (self->magic == IRLAN_MAGIC, return -1;) ;
F_103 ( V_128 , L_54 ,
V_20 -> V_25 -> V_77 ) ;
F_103 ( V_128 , L_55 ,
V_131 [ V_20 -> V_39 . V_94 ] ) ;
F_103 ( V_128 , L_56 ,
V_131 [ V_20 -> V_29 . V_94 ] ) ;
F_103 ( V_128 , L_57 ,
V_20 -> V_22 ) ;
F_103 ( V_128 , L_58 ,
V_20 -> V_23 ) ;
F_103 ( V_128 , L_59 ,
V_20 -> V_132 [ 1 ] , V_20 -> V_132 [ 0 ] ) ;
F_103 ( V_128 , L_60 ,
V_133 [ V_20 -> V_39 . V_30 ] ) ;
F_103 ( V_128 , L_61 ,
V_134 [ V_20 -> V_34 ] ) ;
F_103 ( V_128 , L_62 ) ;
F_103 ( V_128 , L_63 ) ;
F_104 ( V_128 , V_20 -> V_39 . V_135 ) ;
F_103 ( V_128 , L_64 ,
F_105 ( V_20 -> V_25 ) ? L_65 : L_66 ) ;
F_106 ( V_128 , '\n' ) ;
}
return 0 ;
}
static int F_107 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_108 ( V_137 , & V_138 ) ;
}
