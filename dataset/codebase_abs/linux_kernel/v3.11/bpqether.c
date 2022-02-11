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
memcmp ( V_24 -> V_31 , V_11 -> V_30 , V_32 ) )
goto V_29;
if ( F_18 ( V_17 , sizeof( struct V_23 ) ) )
goto V_29;
V_21 = V_17 -> V_33 [ 0 ] + V_17 -> V_33 [ 1 ] * 256 - 5 ;
F_19 ( V_17 , 2 ) ;
F_20 ( V_17 , V_21 ) ;
V_2 -> V_34 . V_35 ++ ;
V_2 -> V_34 . V_36 += V_21 ;
V_22 = F_21 ( V_17 , 1 ) ;
* V_22 = 0 ;
V_17 -> V_37 = F_22 ( V_17 , V_2 ) ;
F_23 ( V_17 ) ;
V_38:
F_24 () ;
return 0 ;
V_29:
F_25 ( V_17 ) ;
goto V_38;
V_26:
F_25 ( V_17 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
unsigned char * V_22 ;
struct V_10 * V_11 ;
struct V_1 * V_20 ;
int V_39 ;
if ( ! F_16 ( V_2 ) ) {
F_25 ( V_17 ) ;
return V_40 ;
}
F_19 ( V_17 , 1 ) ;
V_39 = V_17 -> V_21 ;
if ( F_18 ( V_17 , V_41 ) ) {
if ( F_27 () )
F_28 ( L_2 ) ;
F_25 ( V_17 ) ;
return V_40 ;
}
V_22 = F_21 ( V_17 , 2 ) ;
* V_22 ++ = ( V_39 + 5 ) % 256 ;
* V_22 ++ = ( V_39 + 5 ) / 256 ;
V_11 = F_6 ( V_2 ) ;
V_20 = V_2 ;
if ( ( V_2 = F_5 ( V_2 ) ) == NULL ) {
V_20 -> V_34 . V_42 ++ ;
F_25 ( V_17 ) ;
return V_40 ;
}
V_17 -> V_37 = F_22 ( V_17 , V_2 ) ;
F_29 ( V_17 ) ;
F_30 ( V_17 , V_2 , V_43 , V_11 -> V_44 , NULL , 0 ) ;
V_2 -> V_34 . V_45 ++ ;
V_2 -> V_34 . V_46 += V_17 -> V_21 ;
F_31 ( V_17 ) ;
F_32 ( V_2 ) ;
return V_40 ;
}
static int F_33 ( struct V_1 * V_2 , void * V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_47 ;
memcpy ( V_2 -> V_50 , V_49 -> V_51 , V_2 -> V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_53 * V_54 , int V_55 )
{
struct V_56 T_2 * V_57 = V_54 -> V_58 ;
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_59 V_60 ;
if ( ! F_35 ( V_61 ) )
return - V_62 ;
switch ( V_55 ) {
case V_63 :
if ( F_36 ( & V_60 , V_54 -> V_58 , sizeof( struct V_59 ) ) )
return - V_64 ;
switch ( V_60 . V_55 ) {
case V_65 :
case V_66 :
default:
return - V_67 ;
}
break;
case V_68 :
if ( F_36 ( V_11 -> V_44 , V_57 -> V_69 , V_32 ) )
return - V_64 ;
if ( F_36 ( V_11 -> V_30 , V_57 -> V_70 , V_32 ) )
return - V_64 ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static void * F_41 ( struct V_71 * V_72 , T_3 * V_73 )
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
static void * F_42 ( struct V_71 * V_72 , void * V_76 , T_3 * V_73 )
{
struct V_77 * V_78 ;
struct V_10 * V_10 = V_76 ;
++ * V_73 ;
if ( V_76 == V_75 )
V_78 = F_43 ( F_44 ( & V_79 ) ) ;
else
V_78 = F_43 ( F_44 ( & V_10 -> V_80 ) ) ;
return ( V_78 == & V_79 ) ? NULL
: F_45 ( V_78 , struct V_10 , V_80 ) ;
}
static void F_46 ( struct V_71 * V_72 , void * V_76 )
__releases( T_4 )
{
F_24 () ;
}
static int F_47 ( struct V_71 * V_72 , void * V_76 )
{
if ( V_76 == V_75 )
F_48 ( V_72 ,
L_3 ) ;
else {
const struct V_10 * V_10 = V_76 ;
F_49 ( V_72 , L_4 ,
V_10 -> V_13 -> V_15 , V_10 -> V_12 -> V_15 ,
V_10 -> V_44 ) ;
if ( F_50 ( V_10 -> V_30 ) )
F_49 ( V_72 , L_5 ) ;
else
F_49 ( V_72 , L_6 , V_10 -> V_30 ) ;
}
return 0 ;
}
static int F_51 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_52 ( V_82 , & V_83 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
V_2 -> V_84 = & V_85 ;
V_2 -> V_86 = V_87 ;
memcpy ( V_2 -> V_88 , & V_89 , V_90 ) ;
memcpy ( V_2 -> V_50 , & V_91 , V_90 ) ;
V_2 -> V_92 = 0 ;
#if F_54 ( V_93 ) || F_54 ( V_94 )
V_2 -> V_95 = & V_96 ;
#endif
V_2 -> type = V_97 ;
V_2 -> V_98 = V_99 + V_41 ;
V_2 -> V_100 = V_101 ;
V_2 -> V_52 = V_90 ;
}
static int F_55 ( struct V_1 * V_102 )
{
int V_103 ;
struct V_1 * V_104 ;
struct V_10 * V_11 ;
V_104 = F_56 ( sizeof( struct V_10 ) , L_7 ,
F_53 ) ;
if ( ! V_104 )
return - V_105 ;
V_11 = F_6 ( V_104 ) ;
F_57 ( V_102 ) ;
V_11 -> V_12 = V_102 ;
V_11 -> V_13 = V_104 ;
memcpy ( V_11 -> V_44 , V_106 , sizeof( V_107 ) ) ;
memcpy ( V_11 -> V_30 , V_106 , sizeof( V_107 ) ) ;
V_103 = F_58 ( V_104 ) ;
if ( V_103 )
goto error;
F_3 ( V_104 ) ;
F_59 ( & V_11 -> V_80 , & V_79 ) ;
return 0 ;
error:
F_60 ( V_102 ) ;
V_87 ( V_104 ) ;
return V_103 ;
}
static void F_61 ( struct V_1 * V_104 )
{
struct V_10 * V_11 = F_6 ( V_104 ) ;
F_60 ( V_11 -> V_12 ) ;
F_62 ( & V_11 -> V_80 ) ;
F_63 ( V_104 ) ;
}
static int F_64 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_22 )
{
struct V_1 * V_2 = F_65 ( V_22 ) ;
if ( ! F_11 ( F_12 ( V_2 ) , & V_25 ) )
return V_111 ;
if ( ! F_9 ( V_2 ) )
return V_111 ;
switch ( V_110 ) {
case V_112 :
if ( F_7 ( V_2 ) == NULL )
F_55 ( V_2 ) ;
break;
case V_113 :
if ( ( V_2 = F_7 ( V_2 ) ) != NULL )
F_66 ( V_2 ) ;
break;
case V_114 :
if ( ( V_2 = F_7 ( V_2 ) ) != NULL )
F_61 ( V_2 ) ;
break;
default:
break;
}
return V_111 ;
}
static int T_5 F_67 ( void )
{
#ifdef F_68
if ( ! F_69 ( L_8 , V_115 , V_25 . V_116 ,
& V_117 ) ) {
F_70 ( V_118
L_9 ) ;
return - V_119 ;
}
#endif
F_71 ( & V_120 ) ;
F_72 ( & V_121 ) ;
F_70 ( V_122 ) ;
return 0 ;
}
static void T_6 F_73 ( void )
{
struct V_10 * V_11 ;
F_74 ( & V_120 ) ;
F_75 ( & V_121 ) ;
F_76 ( L_8 , V_25 . V_116 ) ;
F_77 () ;
while ( ! F_78 ( & V_79 ) ) {
V_11 = F_45 ( V_79 . V_123 , struct V_10 , V_80 ) ;
F_61 ( V_11 -> V_13 ) ;
}
F_79 () ;
}
