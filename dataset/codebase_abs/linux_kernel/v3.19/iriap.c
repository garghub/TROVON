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
F_16 ( L_7 , V_15 ) ;
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
V_2 = F_20 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return NULL ;
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
F_34 ( & V_46 ) ;
V_46 . V_47 = V_48 ;
V_46 . V_49 = V_50 ;
V_46 . V_51 = V_52 ;
V_46 . V_53 = V_54 ;
V_46 . V_55 = V_2 ;
if ( V_28 == V_34 )
strcpy ( V_46 . V_56 , L_8 ) ;
else
strcpy ( V_46 . V_56 , L_9 ) ;
V_2 -> V_45 = F_35 ( V_27 , & V_46 , 0 ) ;
if ( V_2 -> V_45 == NULL ) {
F_36 ( L_10 ,
V_15 ) ;
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
F_16 ( L_11 , V_15 ,
F_37 ( V_58 ) , V_58 ) ;
V_2 = V_55 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (iriap != NULL, return;) ;
F_28 ( & V_2 -> V_4 ) ;
if ( V_60 )
F_29 ( V_60 ) ;
if ( V_2 -> V_28 == V_34 ) {
F_16 ( L_12 , V_15 ) ;
F_38 ( V_2 , V_61 ,
NULL ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_62 , 0 , NULL , V_2 -> V_29 ) ;
} else {
F_16 ( L_13 , V_15 ) ;
F_39 ( V_2 , V_61 ,
NULL ) ;
F_31 ( V_2 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_59 * V_63 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
V_63 = F_41 ( V_37 , V_31 ) ;
if ( V_63 == NULL ) {
F_16 ( L_14 ,
V_15 , V_37 ) ;
return;
}
F_42 ( V_63 , V_37 ) ;
F_43 ( V_2 -> V_45 , V_63 ) ;
}
int F_44 ( struct V_1 * V_2 ,
T_7 V_64 , T_7 V_65 ,
char * V_56 , char * V_66 )
{
struct V_59 * V_63 ;
int V_67 , V_68 , V_69 ;
T_2 * V_70 ;
F_27 (self != NULL, return -1;) ;
F_27 (self->magic == IAS_MAGIC, return -1;) ;
if ( ! V_65 )
return - 1 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_71 = V_72 ;
F_1 ( V_2 , 10 * V_73 ) ;
V_67 = strlen ( V_56 ) ;
V_68 = strlen ( V_66 ) ;
V_69 = V_2 -> V_36 + 2 + V_67 + 1 + V_68 + 4 ;
V_63 = F_41 ( V_69 , V_31 ) ;
if ( ! V_63 )
return - V_13 ;
F_42 ( V_63 , V_2 -> V_36 ) ;
F_45 ( V_63 , 3 + V_67 + V_68 ) ;
V_70 = V_63 -> V_74 ;
V_70 [ 0 ] = V_75 | V_72 ;
V_70 [ 1 ] = V_67 ;
memcpy ( V_70 + 2 , V_56 , V_67 ) ;
V_70 [ 2 + V_67 ] = V_68 ;
memcpy ( V_70 + 3 + V_67 , V_66 , V_68 ) ;
F_38 ( V_2 , V_76 , V_63 ) ;
F_29 ( V_63 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_77 * V_78 ;
int V_79 ;
T_7 V_80 ;
T_7 V_81 ;
T_3 V_82 ;
T_3 V_83 ;
T_2 type ;
T_2 * V_84 ;
int V_85 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_84 = V_60 -> V_74 ;
V_85 = 2 ;
V_83 = F_47 ( V_84 + V_85 ) ;
V_85 += 2 ;
F_16 ( L_15 , V_15 , V_83 ) ;
V_82 = F_47 ( V_84 + V_85 ) ;
V_85 += 2 ;
type = V_84 [ V_85 ++ ] ;
F_16 ( L_16 , V_15 , type ) ;
switch ( type ) {
case V_86 :
memcpy ( & V_81 , V_84 + V_85 , 4 ) ; V_85 += 4 ;
F_48 ( & V_81 ) ;
V_78 = F_49 ( V_81 ) ;
F_16 ( L_17 , V_15 , V_78 -> V_87 . integer ) ;
break;
case V_88 :
V_79 = V_84 [ V_85 ++ ] ;
switch ( V_79 ) {
case V_89 :
break;
default:
F_16 ( L_18 ,
V_15 , V_79 ,
V_79 < F_50 ( V_90 ) ?
V_90 [ V_79 ] :
L_19 ) ;
F_40 ( V_2 ) ;
return;
}
V_80 = V_84 [ V_85 ++ ] ;
F_16 ( L_20 , V_15 , V_80 ) ;
if ( V_85 + V_80 < V_60 -> V_83 )
V_84 [ V_85 + V_80 ] = 0x00 ;
F_16 ( L_21 , V_84 + V_85 ) ;
V_78 = F_51 ( V_84 + V_85 ) ;
break;
case V_91 :
V_80 = F_47 ( V_84 + V_85 ) ;
V_85 += 2 ;
V_78 = F_52 ( V_84 + V_85 , V_80 ) ;
break;
default:
V_78 = F_53 () ;
break;
}
F_40 ( V_2 ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_92 , V_82 , V_78 , V_2 -> V_29 ) ;
else {
F_16 ( L_22 , V_15 ) ;
F_54 ( V_78 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
T_3 V_82 ,
T_2 V_93 ,
struct V_77 * V_78 )
{
struct V_59 * V_63 ;
int V_85 ;
T_8 V_94 ;
T_9 V_95 ;
T_2 * V_84 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (value != NULL, return;) ;
F_27 (value->len <= 1024 , return;) ;
V_85 = 0 ;
V_63 = F_41 ( V_78 -> V_83 + V_2 -> V_36 + 32 ,
V_31 ) ;
if ( ! V_63 )
return;
F_42 ( V_63 , V_2 -> V_36 ) ;
F_45 ( V_63 , 6 ) ;
V_84 = V_63 -> V_74 ;
V_84 [ V_85 ++ ] = V_72 | V_75 ;
V_84 [ V_85 ++ ] = V_93 ;
V_95 = F_56 ( 0x0001 ) ;
memcpy ( V_84 + V_85 , & V_95 , 2 ) ; V_85 += 2 ;
V_95 = F_57 ( V_82 ) ;
memcpy ( V_84 + V_85 , & V_95 , 2 ) ; V_85 += 2 ;
switch ( V_78 -> type ) {
case V_88 :
F_45 ( V_63 , 3 + V_78 -> V_83 ) ;
V_84 [ V_85 ++ ] = V_78 -> type ;
V_84 [ V_85 ++ ] = 0 ;
V_84 [ V_85 ++ ] = ( T_2 ) V_78 -> V_83 ;
memcpy ( V_84 + V_85 , V_78 -> V_87 . string , V_78 -> V_83 ) ; V_85 += V_78 -> V_83 ;
break;
case V_86 :
F_45 ( V_63 , 5 ) ;
V_84 [ V_85 ++ ] = V_78 -> type ;
V_94 = F_58 ( V_78 -> V_87 . integer ) ;
memcpy ( V_84 + V_85 , & V_94 , 4 ) ; V_85 += 4 ;
break;
case V_91 :
F_45 ( V_63 , 3 + V_78 -> V_83 ) ;
V_84 [ V_85 ++ ] = V_78 -> type ;
V_95 = F_57 ( V_78 -> V_83 ) ;
memcpy ( V_84 + V_85 , & V_95 , 2 ) ; V_85 += 2 ;
memcpy ( V_84 + V_85 , V_78 -> V_87 . V_9 , V_78 -> V_83 ) ; V_85 += V_78 -> V_83 ;
break;
case V_96 :
F_16 ( L_23 , V_15 ) ;
F_45 ( V_63 , 1 ) ;
V_84 [ V_85 ++ ] = V_78 -> type ;
break;
default:
F_16 ( L_24 , V_15 ) ;
break;
}
F_59 ( V_2 , V_97 , V_63 ) ;
F_29 ( V_63 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_6 * V_7 ;
struct V_98 * V_99 ;
int V_67 ;
int V_68 ;
char V_56 [ V_100 + 1 ] ;
char V_66 [ V_101 + 1 ] ;
T_2 * V_84 ;
int V_85 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_84 = V_60 -> V_74 ;
V_85 = 1 ;
V_67 = V_84 [ V_85 ++ ] ;
F_27 (name_len < IAS_MAX_CLASSNAME + 1 , return;) ;
memcpy ( V_56 , V_84 + V_85 , V_67 ) ; V_85 += V_67 ;
V_56 [ V_67 ] = '\0' ;
V_68 = V_84 [ V_85 ++ ] ;
F_27 (attr_len < IAS_MAX_ATTRIBNAME + 1 , return;) ;
memcpy ( V_66 , V_84 + V_85 , V_68 ) ; V_85 += V_68 ;
V_66 [ V_68 ] = '\0' ;
F_16 ( L_25 , V_56 , V_66 ) ;
V_7 = F_61 ( V_56 ) ;
if ( V_7 == NULL ) {
F_16 ( L_26 , V_56 ) ;
F_55 ( V_2 , 0x1235 , V_102 ,
& V_103 ) ;
return;
}
F_16 ( L_27 , V_7 -> V_56 , V_7 -> V_104 ) ;
V_99 = F_62 ( V_7 , V_66 ) ;
if ( V_99 == NULL ) {
F_16 ( L_28 , V_66 ) ;
F_55 ( V_2 , V_7 -> V_104 ,
V_105 ,
& V_103 ) ;
return;
}
F_55 ( V_2 , V_7 -> V_104 , V_92 ,
V_99 -> V_78 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_59 * V_63 ;
T_2 * V_70 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
V_63 = F_41 ( V_37 + 1 , V_31 ) ;
if ( ! V_63 )
return;
F_42 ( V_63 , V_2 -> V_36 ) ;
F_45 ( V_63 , 1 ) ;
V_70 = V_63 -> V_74 ;
V_70 [ 0 ] = V_75 | V_106 | V_2 -> V_71 ;
F_64 ( V_2 -> V_45 , V_63 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
int V_107 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
V_107 = F_66 ( V_2 -> V_45 , V_22 ,
V_2 -> V_64 , V_2 -> V_65 ,
NULL , NULL ) ;
if ( V_107 < 0 ) {
F_16 ( L_29 , V_15 ) ;
V_2 -> V_35 ( V_62 , 0 , NULL , V_2 -> V_29 ) ;
}
}
static void V_48 ( void * V_55 , void * V_57 ,
struct V_108 * V_109 , T_7 V_110 ,
T_2 V_36 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 ;
V_2 = V_55 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_2 -> V_111 = V_110 ;
V_2 -> V_36 = V_36 ;
F_28 ( & V_2 -> V_4 ) ;
F_38 ( V_2 , V_112 , V_60 ) ;
F_29 ( V_60 ) ;
}
static void V_50 ( void * V_55 , void * V_57 ,
struct V_108 * V_109 , T_7 V_110 ,
T_2 V_36 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 , * V_113 ;
V_2 = V_55 ;
F_27 (skb != NULL, return;) ;
F_27 (self != NULL, goto out;) ;
F_27 (self->magic == IAS_MAGIC, goto out;) ;
V_113 = F_15 ( V_22 , V_23 , NULL , NULL ) ;
if ( ! V_113 ) {
F_16 ( L_30 , V_15 ) ;
goto V_114;
}
V_113 -> V_45 = F_67 ( V_2 -> V_45 , V_113 ) ;
if ( ! V_113 -> V_45 ) {
F_16 ( L_31 , V_15 ) ;
goto V_114;
}
V_113 -> V_111 = V_110 ;
V_113 -> V_36 = V_36 ;
F_68 ( V_2 -> V_45 ) ;
F_39 ( V_113 , V_115 , V_60 ) ;
V_114:
F_29 ( V_60 ) ;
}
static int V_54 ( void * V_55 , void * V_57 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 ;
T_2 * V_70 ;
T_2 V_116 ;
V_2 = V_55 ;
F_27 (skb != NULL, return 0;) ;
F_27 (self != NULL, goto out;) ;
F_27 (self->magic == IAS_MAGIC, goto out;) ;
V_70 = V_60 -> V_74 ;
if ( V_2 -> V_28 == V_23 ) {
F_16 ( L_32 , V_15 ) ;
F_59 ( V_2 , V_117 , V_60 ) ;
goto V_114;
}
V_116 = V_70 [ 0 ] ;
if ( ~ V_116 & V_75 ) {
F_5 ( L_33 ,
V_15 ) ;
goto V_114;
}
if ( V_116 & V_106 ) {
F_16 ( L_34 , V_15 ) ;
goto V_114;
}
V_116 &= ~ V_75 ;
switch ( V_116 ) {
case V_118 :
F_16 ( L_35 ) ;
break;
case V_72 :
F_69 ( V_2 , V_117 , NULL ) ;
switch ( V_70 [ 1 ] ) {
case V_92 :
F_46 ( V_2 , V_60 ) ;
break;
case V_102 :
F_16 ( L_36 , V_15 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_102 , 0 , NULL ,
V_2 -> V_29 ) ;
break;
case V_105 :
F_16 ( L_37 , V_15 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_35 )
V_2 -> V_35 ( V_105 , 0 , NULL ,
V_2 -> V_29 ) ;
break;
}
break;
default:
F_16 ( L_38 , V_15 ,
V_116 ) ;
break;
}
V_114:
F_29 ( V_60 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
T_2 * V_84 ;
T_2 V_116 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
F_27 (skb != NULL, return;) ;
V_84 = V_60 -> V_74 ;
V_116 = V_84 [ 0 ] ;
if ( ~ V_116 & 0x80 ) {
F_5 ( L_39 ,
V_15 ) ;
return;
}
V_116 &= 0x7f ;
switch ( V_116 ) {
case V_118 :
F_5 ( L_40 ,
V_15 ) ;
break;
case V_72 :
F_60 ( V_2 , V_60 ) ;
break;
}
}
static void V_5 ( void * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_27 (self != NULL, return;) ;
F_27 (self->magic == IAS_MAGIC, return;) ;
}
static inline struct V_6 * F_71 ( T_10 V_119 )
{
struct V_6 * V_7 ;
for ( V_7 = (struct V_6 * ) F_72 ( V_14 ) ;
V_7 ; V_7 = (struct V_6 * ) F_73 ( V_14 ) ) {
if ( V_119 -- == 0 )
break;
}
return V_7 ;
}
static void * F_74 ( struct V_120 * V_121 , T_10 * V_119 )
{
F_75 ( & V_14 -> V_16 ) ;
return * V_119 ? F_71 ( * V_119 - 1 ) : V_122 ;
}
static void * F_76 ( struct V_120 * V_121 , void * V_123 , T_10 * V_119 )
{
++ * V_119 ;
return ( V_123 == V_122 )
? ( void * ) F_72 ( V_14 )
: ( void * ) F_73 ( V_14 ) ;
}
static void F_77 ( struct V_120 * V_121 , void * V_123 )
{
F_78 ( & V_14 -> V_16 ) ;
}
static int F_79 ( struct V_120 * V_121 , void * V_123 )
{
if ( V_123 == V_122 )
F_80 ( V_121 , L_41 ) ;
else {
struct V_6 * V_7 = V_123 ;
struct V_98 * V_99 ;
F_27 (obj->magic == IAS_OBJECT_MAGIC, return -EINVAL;) ;
F_81 ( V_121 , L_42 ,
V_7 -> V_56 , V_7 -> V_104 ) ;
F_82 ( & V_7 -> V_124 -> V_16 ) ;
for ( V_99 = (struct V_98 * ) F_72 ( V_7 -> V_124 ) ;
V_99 != NULL ;
V_99 = (struct V_98 * ) F_73 ( V_7 -> V_124 ) ) {
F_27 (attrib->magic == IAS_ATTRIB_MAGIC,
goto outloop; ) ;
F_81 ( V_121 , L_43 ,
V_99 -> V_56 ) ;
F_81 ( V_121 , L_44 ,
V_125 [ V_99 -> V_78 -> type ] ) ;
switch ( V_99 -> V_78 -> type ) {
case V_86 :
F_81 ( V_121 , L_45 ,
V_99 -> V_78 -> V_87 . integer ) ;
break;
case V_88 :
F_81 ( V_121 , L_46 ,
V_99 -> V_78 -> V_87 . string ) ;
break;
case V_91 :
F_81 ( V_121 , L_47 ,
V_99 -> V_78 -> V_83 ) ;
break;
case V_96 :
F_80 ( V_121 , L_48 ) ;
break;
default:
F_81 ( V_121 , L_49 ,
V_99 -> V_78 -> type ) ;
}
F_83 ( V_121 , '\n' ) ;
}
F_84 (outloop:)
F_85 ( & V_7 -> V_124 -> V_16 ) ;
}
return 0 ;
}
static int F_86 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
F_27 ( irias_objects != NULL, return -EINVAL;) ;
return F_87 ( V_127 , & V_128 ) ;
}
