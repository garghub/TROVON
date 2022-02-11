static inline void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
F_2 ( & V_2 -> V_4 , V_3 , V_2 ,
V_5 ) ;
}
int T_1 F_3 ( void )
{
struct V_6 * V_7 ;
struct V_1 * V_8 ;
T_2 V_9 [ 6 ] ;
T_3 V_10 ;
V_11 = F_4 ( V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_14 = F_4 ( V_12 ) ;
if ( ! V_14 ) {
F_5 ( L_1 ,
V_15 ) ;
F_6 ( V_11 , NULL ) ;
return - V_13 ;
}
F_7 ( & V_14 -> V_16 , & V_17 ,
L_2 ) ;
V_10 = F_8 ( V_18 ) ;
V_19 = F_9 ( V_10 ) ;
V_7 = F_10 ( L_3 , V_20 ) ;
F_11 ( V_7 , L_4 , L_5 , V_21 ) ;
V_9 [ 0 ] = 0x01 ;
V_9 [ 1 ] = 0x00 ;
V_9 [ 2 ] = 0x00 ;
#ifdef F_12
V_9 [ 2 ] |= 0x04 ;
#endif
F_13 ( V_7 , L_6 , V_9 , 3 ,
V_21 ) ;
F_14 ( V_7 ) ;
V_8 = F_15 ( V_22 , V_23 , NULL , NULL ) ;
if ( ! V_8 ) {
F_16 ( 0 , L_7 , V_15 ) ;
return - 1 ;
}
F_17 ( V_8 , V_22 , V_23 ) ;
return 0 ;
}
void F_18 ( void )
{
F_19 ( V_19 ) ;
F_6 ( V_11 , ( V_24 ) V_25 ) ;
F_6 ( V_14 , ( V_24 ) V_26 ) ;
}
struct V_1 * F_15 ( T_2 V_27 , int V_28 , void * V_29 ,
T_4 V_30 )
{
struct V_1 * V_2 ;
F_16 ( 2 , L_8 , V_15 ) ;
V_2 = F_20 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_5 ( L_9 , V_15 ) ;
return NULL ;
}
V_2 -> V_32 = V_33 ;
V_2 -> V_28 = V_28 ;
if ( V_28 == V_34 )
F_17 ( V_2 , V_27 , V_28 ) ;
V_2 -> V_35 = V_30 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_36 = V_37 ;
F_21 ( & V_2 -> V_4 ) ;
F_22 ( V_11 , ( V_38 * ) V_2 , ( long ) V_2 , NULL ) ;
F_23 ( V_2 , V_39 ) ;
F_24 ( V_2 , V_40 ) ;
F_25 ( V_2 , V_41 ) ;
F_26 ( V_2 , V_42 ) ;
return V_2 ;
}
static void V_25 ( struct V_1 * V_2 )
{
F_16 ( 4 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_28 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_43 )
F_29 ( V_2 -> V_43 ) ;
V_2 -> V_32 = 0 ;
F_30 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_1 * V_44 ;
F_16 ( 2 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
if ( V_2 -> V_45 ) {
F_32 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
}
V_44 = (struct V_1 * ) F_33 ( V_11 , ( long ) V_2 , NULL ) ;
F_27 (entry == self, return;) ;
V_25 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_27 , int V_28 )
{
T_5 V_46 ;
F_16 ( 2 , L_8 , V_15 ) ;
F_34 ( & V_46 ) ;
V_46 . V_47 = V_48 ;
V_46 . V_49 = V_50 ;
V_46 . V_51 = V_52 ;
V_46 . V_53 = V_54 ;
V_46 . V_55 = V_2 ;
if ( V_28 == V_34 )
strcpy ( V_46 . V_56 , L_10 ) ;
else
strcpy ( V_46 . V_56 , L_11 ) ;
V_2 -> V_45 = F_35 ( V_27 , & V_46 , 0 ) ;
if ( V_2 -> V_45 == NULL ) {
F_36 ( L_12 , V_15 ) ;
return - 1 ;
}
V_2 -> V_27 = V_2 -> V_45 -> V_27 ;
return 0 ;
}
static void V_52 ( void * V_55 , void * V_57 ,
T_6 V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 ;
F_16 ( 4 , L_13 , V_15 , V_61 [ V_58 ] ) ;
V_2 = V_55 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (iriap != NULL, return;) ;
F_28 ( & V_2 -> V_4 ) ;
if ( V_60 )
F_29 ( V_60 ) ;
if ( V_2 -> V_28 == V_34 ) {
F_16 ( 4 , L_14 , V_15 ) ;
F_37 ( V_2 , V_62 ,
NULL ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_63 , 0 , NULL , V_2 -> V_29 ) ;
} else {
F_16 ( 4 , L_15 , V_15 ) ;
F_38 ( V_2 , V_62 ,
NULL ) ;
F_31 ( V_2 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_59 * V_64 ;
F_16 ( 4 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
V_64 = F_40 ( V_37 , V_31 ) ;
if ( V_64 == NULL ) {
F_16 ( 0 ,
L_16 ,
V_15 , V_37 ) ;
return;
}
F_41 ( V_64 , V_37 ) ;
F_42 ( V_2 -> V_45 , V_64 ) ;
}
int F_43 ( struct V_1 * V_2 ,
T_7 V_65 , T_7 V_66 ,
char * V_56 , char * V_67 )
{
struct V_59 * V_64 ;
int V_68 , V_69 , V_70 ;
T_2 * V_71 ;
F_27 (self != NULL, return -1;) ;
F_27 (self->magic == IAS_MAGIC, return -1;) ;
if ( ! V_66 )
return - 1 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_72 = V_73 ;
F_1 ( V_2 , 10 * V_74 ) ;
V_68 = strlen ( V_56 ) ;
V_69 = strlen ( V_67 ) ;
V_70 = V_2 -> V_36 + 2 + V_68 + 1 + V_69 + 4 ;
V_64 = F_40 ( V_70 , V_31 ) ;
if ( ! V_64 )
return - V_13 ;
F_41 ( V_64 , V_2 -> V_36 ) ;
F_44 ( V_64 , 3 + V_68 + V_69 ) ;
V_71 = V_64 -> V_75 ;
V_71 [ 0 ] = V_76 | V_73 ;
V_71 [ 1 ] = V_68 ;
memcpy ( V_71 + 2 , V_56 , V_68 ) ;
V_71 [ 2 + V_68 ] = V_69 ;
memcpy ( V_71 + 3 + V_68 , V_67 , V_69 ) ;
F_37 ( V_2 , V_77 , V_64 ) ;
F_29 ( V_64 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_78 * V_79 ;
int V_80 ;
T_7 V_81 ;
T_7 V_82 ;
T_3 V_83 ;
T_3 V_84 ;
T_2 type ;
T_2 * V_85 ;
int V_86 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_85 = V_60 -> V_75 ;
V_86 = 2 ;
V_84 = F_46 ( V_85 + V_86 ) ;
V_86 += 2 ;
F_16 ( 4 , L_17 , V_15 , V_84 ) ;
V_83 = F_46 ( V_85 + V_86 ) ;
V_86 += 2 ;
type = V_85 [ V_86 ++ ] ;
F_16 ( 4 , L_18 , V_15 , type ) ;
switch ( type ) {
case V_87 :
memcpy ( & V_82 , V_85 + V_86 , 4 ) ; V_86 += 4 ;
F_47 ( & V_82 ) ;
V_79 = F_48 ( V_82 ) ;
F_16 ( 4 , L_19 , V_15 , V_79 -> V_88 . integer ) ;
break;
case V_89 :
V_80 = V_85 [ V_86 ++ ] ;
switch ( V_80 ) {
case V_90 :
break;
default:
F_16 ( 0 , L_20 ,
V_15 , V_91 [ V_80 ] ) ;
F_39 ( V_2 ) ;
return;
}
V_81 = V_85 [ V_86 ++ ] ;
F_16 ( 4 , L_21 , V_15 , V_81 ) ;
if ( V_86 + V_81 < V_60 -> V_84 )
V_85 [ V_86 + V_81 ] = 0x00 ;
F_16 ( 4 , L_22 , V_85 + V_86 ) ;
V_79 = F_49 ( V_85 + V_86 ) ;
break;
case V_92 :
V_81 = F_46 ( V_85 + V_86 ) ;
V_86 += 2 ;
V_79 = F_50 ( V_85 + V_86 , V_81 ) ;
break;
default:
V_79 = F_51 () ;
break;
}
F_39 ( V_2 ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_93 , V_83 , V_79 , V_2 -> V_29 ) ;
else {
F_16 ( 0 , L_23 , V_15 ) ;
F_52 ( V_79 ) ;
}
}
static void F_53 ( struct V_1 * V_2 ,
T_3 V_83 ,
T_2 V_94 ,
struct V_78 * V_79 )
{
struct V_59 * V_64 ;
int V_86 ;
T_8 V_95 ;
T_9 V_96 ;
T_2 * V_85 ;
F_16 ( 4 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (value != NULL, return;) ;
F_27 (value->len <= 1024 , return;) ;
V_86 = 0 ;
V_64 = F_40 ( V_79 -> V_84 + V_2 -> V_36 + 32 ,
V_31 ) ;
if ( ! V_64 )
return;
F_41 ( V_64 , V_2 -> V_36 ) ;
F_44 ( V_64 , 6 ) ;
V_85 = V_64 -> V_75 ;
V_85 [ V_86 ++ ] = V_73 | V_76 ;
V_85 [ V_86 ++ ] = V_94 ;
V_96 = F_54 ( 0x0001 ) ;
memcpy ( V_85 + V_86 , & V_96 , 2 ) ; V_86 += 2 ;
V_96 = F_55 ( V_83 ) ;
memcpy ( V_85 + V_86 , & V_96 , 2 ) ; V_86 += 2 ;
switch ( V_79 -> type ) {
case V_89 :
F_44 ( V_64 , 3 + V_79 -> V_84 ) ;
V_85 [ V_86 ++ ] = V_79 -> type ;
V_85 [ V_86 ++ ] = 0 ;
V_85 [ V_86 ++ ] = ( T_2 ) V_79 -> V_84 ;
memcpy ( V_85 + V_86 , V_79 -> V_88 . string , V_79 -> V_84 ) ; V_86 += V_79 -> V_84 ;
break;
case V_87 :
F_44 ( V_64 , 5 ) ;
V_85 [ V_86 ++ ] = V_79 -> type ;
V_95 = F_56 ( V_79 -> V_88 . integer ) ;
memcpy ( V_85 + V_86 , & V_95 , 4 ) ; V_86 += 4 ;
break;
case V_92 :
F_44 ( V_64 , 3 + V_79 -> V_84 ) ;
V_85 [ V_86 ++ ] = V_79 -> type ;
V_96 = F_55 ( V_79 -> V_84 ) ;
memcpy ( V_85 + V_86 , & V_96 , 2 ) ; V_86 += 2 ;
memcpy ( V_85 + V_86 , V_79 -> V_88 . V_9 , V_79 -> V_84 ) ; V_86 += V_79 -> V_84 ;
break;
case V_97 :
F_16 ( 3 , L_24 , V_15 ) ;
F_44 ( V_64 , 1 ) ;
V_85 [ V_86 ++ ] = V_79 -> type ;
break;
default:
F_16 ( 0 , L_25 , V_15 ) ;
break;
}
F_57 ( V_2 , V_98 , V_64 ) ;
F_29 ( V_64 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_6 * V_7 ;
struct V_99 * V_100 ;
int V_68 ;
int V_69 ;
char V_56 [ V_101 + 1 ] ;
char V_67 [ V_102 + 1 ] ;
T_2 * V_85 ;
int V_86 ;
F_16 ( 4 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_85 = V_60 -> V_75 ;
V_86 = 1 ;
V_68 = V_85 [ V_86 ++ ] ;
F_27 (name_len < IAS_MAX_CLASSNAME + 1 , return;) ;
memcpy ( V_56 , V_85 + V_86 , V_68 ) ; V_86 += V_68 ;
V_56 [ V_68 ] = '\0' ;
V_69 = V_85 [ V_86 ++ ] ;
F_27 (attr_len < IAS_MAX_ATTRIBNAME + 1 , return;) ;
memcpy ( V_67 , V_85 + V_86 , V_69 ) ; V_86 += V_69 ;
V_67 [ V_69 ] = '\0' ;
F_16 ( 4 , L_26 , V_56 , V_67 ) ;
V_7 = F_59 ( V_56 ) ;
if ( V_7 == NULL ) {
F_16 ( 2 , L_27 , V_56 ) ;
F_53 ( V_2 , 0x1235 , V_103 ,
& V_104 ) ;
return;
}
F_16 ( 4 , L_28 , V_7 -> V_56 , V_7 -> V_105 ) ;
V_100 = F_60 ( V_7 , V_67 ) ;
if ( V_100 == NULL ) {
F_16 ( 2 , L_29 , V_67 ) ;
F_53 ( V_2 , V_7 -> V_105 ,
V_106 ,
& V_104 ) ;
return;
}
F_53 ( V_2 , V_7 -> V_105 , V_93 ,
V_100 -> V_79 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_59 * V_64 ;
T_2 * V_71 ;
F_16 ( 2 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
V_64 = F_40 ( V_37 + 1 , V_31 ) ;
if ( ! V_64 )
return;
F_41 ( V_64 , V_2 -> V_36 ) ;
F_44 ( V_64 , 1 ) ;
V_71 = V_64 -> V_75 ;
V_71 [ 0 ] = V_76 | V_107 | V_2 -> V_72 ;
F_62 ( V_2 -> V_45 , V_64 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
int V_108 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
V_108 = F_64 ( V_2 -> V_45 , V_22 ,
V_2 -> V_65 , V_2 -> V_66 ,
NULL , NULL ) ;
if ( V_108 < 0 ) {
F_16 ( 0 , L_30 , V_15 ) ;
V_2 -> V_35 ( V_63 , 0 , NULL , V_2 -> V_29 ) ;
}
}
static void V_48 ( void * V_55 , void * V_57 ,
struct V_109 * V_110 , T_7 V_111 ,
T_2 V_36 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 ;
V_2 = V_55 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_2 -> V_112 = V_111 ;
V_2 -> V_36 = V_36 ;
F_28 ( & V_2 -> V_4 ) ;
F_37 ( V_2 , V_113 , V_60 ) ;
F_29 ( V_60 ) ;
}
static void V_50 ( void * V_55 , void * V_57 ,
struct V_109 * V_110 , T_7 V_111 ,
T_2 V_36 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 , * V_114 ;
F_16 ( 1 , L_8 , V_15 ) ;
V_2 = V_55 ;
F_27 (skb != NULL, return;) ;
F_27 (self != NULL, goto out;) ;
F_27 (self->magic == IAS_MAGIC, goto out;) ;
V_114 = F_15 ( V_22 , V_23 , NULL , NULL ) ;
if ( ! V_114 ) {
F_16 ( 0 , L_31 , V_15 ) ;
goto V_115;
}
V_114 -> V_45 = F_65 ( V_2 -> V_45 , V_114 ) ;
if ( ! V_114 -> V_45 ) {
F_16 ( 0 , L_32 , V_15 ) ;
goto V_115;
}
V_114 -> V_112 = V_111 ;
V_114 -> V_36 = V_36 ;
F_66 ( V_2 -> V_45 ) ;
F_38 ( V_114 , V_116 , V_60 ) ;
V_115:
F_29 ( V_60 ) ;
}
static int V_54 ( void * V_55 , void * V_57 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 ;
T_2 * V_71 ;
T_2 V_117 ;
F_16 ( 3 , L_8 , V_15 ) ;
V_2 = V_55 ;
F_27 (skb != NULL, return 0;) ;
F_27 (self != NULL, goto out;) ;
F_27 (self->magic == IAS_MAGIC, goto out;) ;
V_71 = V_60 -> V_75 ;
if ( V_2 -> V_28 == V_23 ) {
F_16 ( 4 , L_33 , V_15 ) ;
F_57 ( V_2 , V_118 , V_60 ) ;
goto V_115;
}
V_117 = V_71 [ 0 ] ;
if ( ~ V_117 & V_76 ) {
F_5 ( L_34
L_35 ,
V_15 ) ;
goto V_115;
}
if ( V_117 & V_107 ) {
F_16 ( 0 , L_36 , V_15 ) ;
goto V_115;
}
V_117 &= ~ V_76 ;
switch ( V_117 ) {
case V_119 :
F_16 ( 0 , L_37 ) ;
break;
case V_73 :
F_67 ( V_2 , V_118 , NULL ) ;
switch ( V_71 [ 1 ] ) {
case V_93 :
F_45 ( V_2 , V_60 ) ;
break;
case V_103 :
F_16 ( 1 , L_38 , V_15 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_103 , 0 , NULL ,
V_2 -> V_29 ) ;
break;
case V_106 :
F_16 ( 1 , L_39 , V_15 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_106 , 0 , NULL ,
V_2 -> V_29 ) ;
break;
}
break;
default:
F_16 ( 0 , L_40 , V_15 ,
V_117 ) ;
break;
}
V_115:
F_29 ( V_60 ) ;
return 0 ;
}
void F_68 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
T_2 * V_85 ;
T_2 V_117 ;
F_16 ( 4 , L_8 , V_15 ) ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_85 = V_60 -> V_75 ;
V_117 = V_85 [ 0 ] ;
if ( ~ V_117 & 0x80 ) {
F_5 ( L_41
L_42 , V_15 ) ;
return;
}
V_117 &= 0x7f ;
switch ( V_117 ) {
case V_119 :
F_5 ( L_43 ,
V_15 ) ;
break;
case V_73 :
F_58 ( V_2 , V_60 ) ;
break;
}
}
static void V_5 ( void * V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
}
static inline struct V_6 * F_69 ( T_10 V_120 )
{
struct V_6 * V_7 ;
for ( V_7 = (struct V_6 * ) F_70 ( V_14 ) ;
V_7 ; V_7 = (struct V_6 * ) F_71 ( V_14 ) ) {
if ( V_120 -- == 0 )
break;
}
return V_7 ;
}
static void * F_72 ( struct V_121 * V_122 , T_10 * V_120 )
{
F_73 ( & V_14 -> V_16 ) ;
return * V_120 ? F_69 ( * V_120 - 1 ) : V_123 ;
}
static void * F_74 ( struct V_121 * V_122 , void * V_124 , T_10 * V_120 )
{
++ * V_120 ;
return ( V_124 == V_123 )
? ( void * ) F_70 ( V_14 )
: ( void * ) F_71 ( V_14 ) ;
}
static void F_75 ( struct V_121 * V_122 , void * V_124 )
{
F_76 ( & V_14 -> V_16 ) ;
}
static int F_77 ( struct V_121 * V_122 , void * V_124 )
{
if ( V_124 == V_123 )
F_78 ( V_122 , L_44 ) ;
else {
struct V_6 * V_7 = V_124 ;
struct V_99 * V_100 ;
F_27 (obj->magic == IAS_OBJECT_MAGIC, return -EINVAL;) ;
F_79 ( V_122 , L_45 ,
V_7 -> V_56 , V_7 -> V_105 ) ;
F_80 ( & V_7 -> V_125 -> V_16 ) ;
for ( V_100 = (struct V_99 * ) F_70 ( V_7 -> V_125 ) ;
V_100 != NULL ;
V_100 = (struct V_99 * ) F_71 ( V_7 -> V_125 ) ) {
F_27 (attrib->magic == IAS_ATTRIB_MAGIC,
goto outloop; ) ;
F_79 ( V_122 , L_46 ,
V_100 -> V_56 ) ;
F_79 ( V_122 , L_47 ,
V_126 [ V_100 -> V_79 -> type ] ) ;
switch ( V_100 -> V_79 -> type ) {
case V_87 :
F_79 ( V_122 , L_48 ,
V_100 -> V_79 -> V_88 . integer ) ;
break;
case V_89 :
F_79 ( V_122 , L_49 ,
V_100 -> V_79 -> V_88 . string ) ;
break;
case V_92 :
F_79 ( V_122 , L_50 ,
V_100 -> V_79 -> V_84 ) ;
break;
case V_97 :
F_78 ( V_122 , L_51 ) ;
break;
default:
F_79 ( V_122 , L_52 ,
V_100 -> V_79 -> type ) ;
}
F_81 ( V_122 , '\n' ) ;
}
F_82 (outloop:)
F_83 ( & V_7 -> V_125 -> V_16 ) ;
}
return 0 ;
}
static int F_84 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
F_27 ( irias_objects != NULL, return -EINVAL;) ;
return F_85 ( V_128 , & V_129 ) ;
}
