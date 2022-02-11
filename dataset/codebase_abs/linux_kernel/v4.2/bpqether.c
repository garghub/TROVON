static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 )
{
F_2 ( & V_4 -> V_6 , & V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_8 , & V_9 ) ;
F_4 ( V_2 , F_1 , NULL ) ;
}
static inline struct V_1 * F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
return V_11 ? V_11 -> V_12 : NULL ;
}
static inline struct V_1 * F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_8 (bpq, &bpq_devices, bpq_list) {
if ( V_11 -> V_12 == V_2 )
return V_11 -> V_13 ;
}
return NULL ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return V_2 -> type == V_14 && strncmp ( V_2 -> V_15 , L_1 , 5 ) ;
}
static int F_10 ( struct V_16 * V_17 , struct V_1 * V_2 , struct V_18 * V_19 , struct V_1 * V_20 )
{
int V_21 ;
char * V_22 ;
struct V_23 * V_24 ;
struct V_10 * V_11 ;
if ( ! F_11 ( F_12 ( V_2 ) , & V_25 ) )
goto V_26;
if ( ( V_17 = F_13 ( V_17 , V_27 ) ) == NULL )
return V_28 ;
if ( ! F_14 ( V_17 , sizeof( struct V_23 ) ) )
goto V_26;
F_15 () ;
V_2 = F_7 ( V_2 ) ;
if ( V_2 == NULL || ! F_16 ( V_2 ) )
goto V_29;
V_11 = F_6 ( V_2 ) ;
V_24 = F_17 ( V_17 ) ;
if ( ! ( V_11 -> V_30 [ 0 ] & 0x01 ) &&
! F_18 ( V_24 -> V_31 , V_11 -> V_30 ) )
goto V_29;
if ( F_19 ( V_17 , sizeof( struct V_23 ) ) )
goto V_29;
V_21 = V_17 -> V_32 [ 0 ] + V_17 -> V_32 [ 1 ] * 256 - 5 ;
F_20 ( V_17 , 2 ) ;
F_21 ( V_17 , V_21 ) ;
V_2 -> V_33 . V_34 ++ ;
V_2 -> V_33 . V_35 += V_21 ;
V_22 = F_22 ( V_17 , 1 ) ;
* V_22 = 0 ;
V_17 -> V_36 = F_23 ( V_17 , V_2 ) ;
F_24 ( V_17 ) ;
V_37:
F_25 () ;
return 0 ;
V_29:
F_26 ( V_17 ) ;
goto V_37;
V_26:
F_26 ( V_17 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
unsigned char * V_22 ;
struct V_10 * V_11 ;
struct V_1 * V_20 ;
int V_38 ;
if ( V_17 -> V_36 == F_28 ( V_39 ) )
return F_29 ( V_17 ) ;
if ( ! F_16 ( V_2 ) ) {
F_26 ( V_17 ) ;
return V_40 ;
}
F_20 ( V_17 , 1 ) ;
V_38 = V_17 -> V_21 ;
if ( F_19 ( V_17 , V_41 ) ) {
if ( F_30 () )
F_31 ( L_2 ) ;
F_26 ( V_17 ) ;
return V_40 ;
}
V_22 = F_22 ( V_17 , 2 ) ;
* V_22 ++ = ( V_38 + 5 ) % 256 ;
* V_22 ++ = ( V_38 + 5 ) / 256 ;
V_11 = F_6 ( V_2 ) ;
V_20 = V_2 ;
if ( ( V_2 = F_5 ( V_2 ) ) == NULL ) {
V_20 -> V_33 . V_42 ++ ;
F_26 ( V_17 ) ;
return V_40 ;
}
V_17 -> V_36 = F_23 ( V_17 , V_2 ) ;
F_32 ( V_17 ) ;
F_33 ( V_17 , V_2 , V_43 , V_11 -> V_44 , NULL , 0 ) ;
V_2 -> V_33 . V_45 ++ ;
V_2 -> V_33 . V_46 += V_17 -> V_21 ;
F_34 ( V_17 ) ;
F_35 ( V_2 ) ;
return V_40 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_47 ;
memcpy ( V_2 -> V_50 , V_49 -> V_51 , V_2 -> V_52 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_53 * V_54 , int V_55 )
{
struct V_56 T_2 * V_57 = V_54 -> V_58 ;
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_59 V_60 ;
if ( ! F_38 ( V_61 ) )
return - V_62 ;
switch ( V_55 ) {
case V_63 :
if ( F_39 ( & V_60 , V_54 -> V_58 , sizeof( struct V_59 ) ) )
return - V_64 ;
switch ( V_60 . V_55 ) {
case V_65 :
case V_66 :
default:
return - V_67 ;
}
break;
case V_68 :
if ( F_39 ( V_11 -> V_44 , V_57 -> V_69 , V_70 ) )
return - V_64 ;
if ( F_39 ( V_11 -> V_30 , V_57 -> V_71 , V_70 ) )
return - V_64 ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
return 0 ;
}
static void * F_44 ( struct V_72 * V_73 , T_3 * V_74 )
__acquires( T_4 )
{
int V_75 = 1 ;
struct V_10 * V_10 ;
F_15 () ;
if ( * V_74 == 0 )
return V_76 ;
F_8 (bpqdev, &bpq_devices, bpq_list) {
if ( V_75 == * V_74 )
return V_10 ;
}
return NULL ;
}
static void * F_45 ( struct V_72 * V_73 , void * V_77 , T_3 * V_74 )
{
struct V_78 * V_79 ;
struct V_10 * V_10 = V_77 ;
++ * V_74 ;
if ( V_77 == V_76 )
V_79 = F_46 ( F_47 ( & V_80 ) ) ;
else
V_79 = F_46 ( F_47 ( & V_10 -> V_81 ) ) ;
return ( V_79 == & V_80 ) ? NULL
: F_48 ( V_79 , struct V_10 , V_81 ) ;
}
static void F_49 ( struct V_72 * V_73 , void * V_77 )
__releases( T_4 )
{
F_25 () ;
}
static int F_50 ( struct V_72 * V_73 , void * V_77 )
{
if ( V_77 == V_76 )
F_51 ( V_73 ,
L_3 ) ;
else {
const struct V_10 * V_10 = V_77 ;
F_52 ( V_73 , L_4 ,
V_10 -> V_13 -> V_15 , V_10 -> V_12 -> V_15 ,
V_10 -> V_44 ) ;
if ( F_53 ( V_10 -> V_30 ) )
F_52 ( V_73 , L_5 ) ;
else
F_52 ( V_73 , L_6 , V_10 -> V_30 ) ;
}
return 0 ;
}
static int F_54 ( struct V_82 * V_82 , struct V_83 * V_83 )
{
return F_55 ( V_83 , & V_84 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
V_2 -> V_85 = & V_86 ;
V_2 -> V_87 = V_88 ;
memcpy ( V_2 -> V_89 , & V_90 , V_91 ) ;
memcpy ( V_2 -> V_50 , & V_92 , V_91 ) ;
V_2 -> V_93 = 0 ;
V_2 -> V_94 = V_95 ;
#if F_57 ( V_96 ) || F_57 ( V_97 )
V_2 -> V_98 = & V_99 ;
#endif
V_2 -> type = V_100 ;
V_2 -> V_101 = V_102 + V_41 ;
V_2 -> V_103 = V_104 ;
V_2 -> V_52 = V_91 ;
}
static int F_58 ( struct V_1 * V_105 )
{
int V_106 ;
struct V_1 * V_107 ;
struct V_10 * V_11 ;
V_107 = F_59 ( sizeof( struct V_10 ) , L_7 , V_108 ,
F_56 ) ;
if ( ! V_107 )
return - V_109 ;
V_11 = F_6 ( V_107 ) ;
F_60 ( V_105 ) ;
V_11 -> V_12 = V_105 ;
V_11 -> V_13 = V_107 ;
memcpy ( V_11 -> V_44 , V_110 , sizeof( V_111 ) ) ;
memcpy ( V_11 -> V_30 , V_110 , sizeof( V_111 ) ) ;
V_106 = F_61 ( V_107 ) ;
if ( V_106 )
goto error;
F_3 ( V_107 ) ;
F_62 ( & V_11 -> V_81 , & V_80 ) ;
return 0 ;
error:
F_63 ( V_105 ) ;
V_88 ( V_107 ) ;
return V_106 ;
}
static void F_64 ( struct V_1 * V_107 )
{
struct V_10 * V_11 = F_6 ( V_107 ) ;
F_63 ( V_11 -> V_12 ) ;
F_65 ( & V_11 -> V_81 ) ;
F_66 ( V_107 ) ;
}
static int F_67 ( struct V_112 * V_113 ,
unsigned long V_114 , void * V_22 )
{
struct V_1 * V_2 = F_68 ( V_22 ) ;
if ( ! F_11 ( F_12 ( V_2 ) , & V_25 ) )
return V_115 ;
if ( ! F_9 ( V_2 ) )
return V_115 ;
switch ( V_114 ) {
case V_116 :
if ( F_7 ( V_2 ) == NULL )
F_58 ( V_2 ) ;
break;
case V_117 :
if ( ( V_2 = F_7 ( V_2 ) ) != NULL )
F_69 ( V_2 ) ;
break;
case V_118 :
if ( ( V_2 = F_7 ( V_2 ) ) != NULL )
F_64 ( V_2 ) ;
break;
default:
break;
}
return V_115 ;
}
static int T_5 F_70 ( void )
{
#ifdef F_71
if ( ! F_72 ( L_8 , V_119 , V_25 . V_120 ,
& V_121 ) ) {
F_73 ( V_122
L_9 ) ;
return - V_123 ;
}
#endif
F_74 ( & V_124 ) ;
F_75 ( & V_125 ) ;
F_73 ( V_126 ) ;
return 0 ;
}
static void T_6 F_76 ( void )
{
struct V_10 * V_11 ;
F_77 ( & V_124 ) ;
F_78 ( & V_125 ) ;
F_79 ( L_8 , V_25 . V_120 ) ;
F_80 () ;
while ( ! F_81 ( & V_80 ) ) {
V_11 = F_48 ( V_80 . V_127 , struct V_10 , V_81 ) ;
F_64 ( V_11 -> V_13 ) ;
}
F_82 () ;
}
