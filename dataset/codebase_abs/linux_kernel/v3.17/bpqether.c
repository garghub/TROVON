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
if ( ! F_16 ( V_2 ) ) {
F_26 ( V_17 ) ;
return V_39 ;
}
F_20 ( V_17 , 1 ) ;
V_38 = V_17 -> V_21 ;
if ( F_19 ( V_17 , V_40 ) ) {
if ( F_28 () )
F_29 ( L_2 ) ;
F_26 ( V_17 ) ;
return V_39 ;
}
V_22 = F_22 ( V_17 , 2 ) ;
* V_22 ++ = ( V_38 + 5 ) % 256 ;
* V_22 ++ = ( V_38 + 5 ) / 256 ;
V_11 = F_6 ( V_2 ) ;
V_20 = V_2 ;
if ( ( V_2 = F_5 ( V_2 ) ) == NULL ) {
V_20 -> V_33 . V_41 ++ ;
F_26 ( V_17 ) ;
return V_39 ;
}
V_17 -> V_36 = F_23 ( V_17 , V_2 ) ;
F_30 ( V_17 ) ;
F_31 ( V_17 , V_2 , V_42 , V_11 -> V_43 , NULL , 0 ) ;
V_2 -> V_33 . V_44 ++ ;
V_2 -> V_33 . V_45 += V_17 -> V_21 ;
F_32 ( V_17 ) ;
F_33 ( V_2 ) ;
return V_39 ;
}
static int F_34 ( struct V_1 * V_2 , void * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
memcpy ( V_2 -> V_49 , V_48 -> V_50 , V_2 -> V_51 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_52 * V_53 , int V_54 )
{
struct V_55 T_2 * V_56 = V_53 -> V_57 ;
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_58 V_59 ;
if ( ! F_36 ( V_60 ) )
return - V_61 ;
switch ( V_54 ) {
case V_62 :
if ( F_37 ( & V_59 , V_53 -> V_57 , sizeof( struct V_58 ) ) )
return - V_63 ;
switch ( V_59 . V_54 ) {
case V_64 :
case V_65 :
default:
return - V_66 ;
}
break;
case V_67 :
if ( F_37 ( V_11 -> V_43 , V_56 -> V_68 , V_69 ) )
return - V_63 ;
if ( F_37 ( V_11 -> V_30 , V_56 -> V_70 , V_69 ) )
return - V_63 ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static void * F_42 ( struct V_71 * V_72 , T_3 * V_73 )
__acquires( T_4 )
{
int V_74 = 1 ;
struct V_10 * V_10 ;
F_15 () ;
if ( * V_73 == 0 )
return V_75 ;
F_8 (bpqdev, &bpq_devices, bpq_list) {
if ( V_74 == * V_73 )
return V_10 ;
}
return NULL ;
}
static void * F_43 ( struct V_71 * V_72 , void * V_76 , T_3 * V_73 )
{
struct V_77 * V_78 ;
struct V_10 * V_10 = V_76 ;
++ * V_73 ;
if ( V_76 == V_75 )
V_78 = F_44 ( F_45 ( & V_79 ) ) ;
else
V_78 = F_44 ( F_45 ( & V_10 -> V_80 ) ) ;
return ( V_78 == & V_79 ) ? NULL
: F_46 ( V_78 , struct V_10 , V_80 ) ;
}
static void F_47 ( struct V_71 * V_72 , void * V_76 )
__releases( T_4 )
{
F_25 () ;
}
static int F_48 ( struct V_71 * V_72 , void * V_76 )
{
if ( V_76 == V_75 )
F_49 ( V_72 ,
L_3 ) ;
else {
const struct V_10 * V_10 = V_76 ;
F_50 ( V_72 , L_4 ,
V_10 -> V_13 -> V_15 , V_10 -> V_12 -> V_15 ,
V_10 -> V_43 ) ;
if ( F_51 ( V_10 -> V_30 ) )
F_50 ( V_72 , L_5 ) ;
else
F_50 ( V_72 , L_6 , V_10 -> V_30 ) ;
}
return 0 ;
}
static int F_52 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_53 ( V_82 , & V_83 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_84 = & V_85 ;
V_2 -> V_86 = V_87 ;
memcpy ( V_2 -> V_88 , & V_89 , V_90 ) ;
memcpy ( V_2 -> V_49 , & V_91 , V_90 ) ;
V_2 -> V_92 = 0 ;
#if F_55 ( V_93 ) || F_55 ( V_94 )
V_2 -> V_95 = & V_96 ;
#endif
V_2 -> type = V_97 ;
V_2 -> V_98 = V_99 + V_40 ;
V_2 -> V_100 = V_101 ;
V_2 -> V_51 = V_90 ;
}
static int F_56 ( struct V_1 * V_102 )
{
int V_103 ;
struct V_1 * V_104 ;
struct V_10 * V_11 ;
V_104 = F_57 ( sizeof( struct V_10 ) , L_7 , V_105 ,
F_54 ) ;
if ( ! V_104 )
return - V_106 ;
V_11 = F_6 ( V_104 ) ;
F_58 ( V_102 ) ;
V_11 -> V_12 = V_102 ;
V_11 -> V_13 = V_104 ;
memcpy ( V_11 -> V_43 , V_107 , sizeof( V_108 ) ) ;
memcpy ( V_11 -> V_30 , V_107 , sizeof( V_108 ) ) ;
V_103 = F_59 ( V_104 ) ;
if ( V_103 )
goto error;
F_3 ( V_104 ) ;
F_60 ( & V_11 -> V_80 , & V_79 ) ;
return 0 ;
error:
F_61 ( V_102 ) ;
V_87 ( V_104 ) ;
return V_103 ;
}
static void F_62 ( struct V_1 * V_104 )
{
struct V_10 * V_11 = F_6 ( V_104 ) ;
F_61 ( V_11 -> V_12 ) ;
F_63 ( & V_11 -> V_80 ) ;
F_64 ( V_104 ) ;
}
static int F_65 ( struct V_109 * V_110 ,
unsigned long V_111 , void * V_22 )
{
struct V_1 * V_2 = F_66 ( V_22 ) ;
if ( ! F_11 ( F_12 ( V_2 ) , & V_25 ) )
return V_112 ;
if ( ! F_9 ( V_2 ) )
return V_112 ;
switch ( V_111 ) {
case V_113 :
if ( F_7 ( V_2 ) == NULL )
F_56 ( V_2 ) ;
break;
case V_114 :
if ( ( V_2 = F_7 ( V_2 ) ) != NULL )
F_67 ( V_2 ) ;
break;
case V_115 :
if ( ( V_2 = F_7 ( V_2 ) ) != NULL )
F_62 ( V_2 ) ;
break;
default:
break;
}
return V_112 ;
}
static int T_5 F_68 ( void )
{
#ifdef F_69
if ( ! F_70 ( L_8 , V_116 , V_25 . V_117 ,
& V_118 ) ) {
F_71 ( V_119
L_9 ) ;
return - V_120 ;
}
#endif
F_72 ( & V_121 ) ;
F_73 ( & V_122 ) ;
F_71 ( V_123 ) ;
return 0 ;
}
static void T_6 F_74 ( void )
{
struct V_10 * V_11 ;
F_75 ( & V_121 ) ;
F_76 ( & V_122 ) ;
F_77 ( L_8 , V_25 . V_117 ) ;
F_78 () ;
while ( ! F_79 ( & V_79 ) ) {
V_11 = F_46 ( V_79 . V_124 , struct V_10 , V_80 ) ;
F_62 ( V_11 -> V_13 ) ;
}
F_80 () ;
}
