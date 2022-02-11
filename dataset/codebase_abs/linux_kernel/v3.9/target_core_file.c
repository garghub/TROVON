static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_6 ( L_2
L_3 , V_5 -> V_12 , V_13 ,
V_14 ) ;
F_6 ( L_4
L_5 ,
V_5 -> V_12 , V_7 -> V_10 , V_15 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_6 ( L_6
L_7 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static struct V_2 * F_9 ( struct V_4 * V_5 , const char * V_16 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_1 ) {
F_5 ( L_8 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
F_6 ( L_9 , V_16 ) ;
return & V_1 -> V_3 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
struct V_17 * V_17 ;
struct V_18 * V_18 = NULL ;
int V_19 , V_20 = - V_21 ;
if ( ! ( V_1 -> V_22 & V_23 ) ) {
F_5 ( L_10 ) ;
return - V_21 ;
}
V_19 = V_24 | V_25 | V_26 | V_27 ;
if ( V_1 -> V_22 & V_28 ) {
F_6 ( L_11 ) ;
V_19 &= ~ V_27 ;
}
V_17 = F_11 ( V_1 -> V_29 , V_19 , 0600 ) ;
if ( F_12 ( V_17 ) ) {
F_5 ( L_12 , V_1 -> V_29 ) ;
V_20 = F_13 ( V_17 ) ;
goto V_30;
}
V_1 -> V_31 = V_17 ;
V_18 = V_17 -> V_32 -> V_33 ;
if ( F_14 ( V_18 -> V_34 ) ) {
struct V_35 * V_36 = F_15 ( V_18 -> V_37 ) ;
unsigned long long V_38 ;
V_3 -> V_39 . V_40 =
F_16 ( V_18 -> V_37 ) ;
V_3 -> V_39 . V_41 = F_17 ( V_36 ) ;
V_38 = ( F_18 ( V_17 -> V_32 -> V_33 ) -
V_1 -> V_42 ) ;
F_6 ( L_13
L_14 ,
V_38 , F_19 ( V_38 , V_1 -> V_42 ) ,
V_1 -> V_42 ) ;
} else {
if ( ! ( V_1 -> V_22 & V_43 ) ) {
F_5 ( L_15
L_16
L_17 ) ;
goto V_30;
}
V_3 -> V_39 . V_40 = V_44 ;
V_3 -> V_39 . V_41 = V_15 ;
}
V_1 -> V_42 = V_3 -> V_39 . V_40 ;
V_3 -> V_39 . V_45 = V_46 ;
if ( V_1 -> V_22 & V_28 ) {
F_6 ( L_18
L_19 ) ;
V_3 -> V_39 . V_47 = 1 ;
}
V_1 -> V_48 = V_7 -> V_49 ++ ;
V_1 -> V_50 = V_3 -> V_51 ;
V_3 -> V_39 . V_52 = 0x1000 ;
F_6 ( L_20
L_21 , V_7 -> V_10 , V_1 -> V_48 ,
V_1 -> V_29 , V_1 -> V_53 ) ;
return 0 ;
V_30:
if ( V_1 -> V_31 ) {
F_20 ( V_1 -> V_31 , NULL ) ;
V_1 -> V_31 = NULL ;
}
return V_20 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_31 ) {
F_20 ( V_1 -> V_31 , NULL ) ;
V_1 -> V_31 = NULL ;
}
F_8 ( V_1 ) ;
}
static int F_22 ( struct V_54 * V_55 , struct V_56 * V_57 ,
T_1 V_58 , int V_59 )
{
struct V_2 * V_60 = V_55 -> V_60 ;
struct V_1 * V_3 = F_1 ( V_60 ) ;
struct V_17 * V_61 = V_3 -> V_31 ;
struct V_56 * V_62 ;
struct V_63 * V_64 ;
T_2 V_65 ;
T_3 V_66 = ( V_55 -> V_67 * V_60 -> V_39 . V_68 ) ;
int V_20 = 0 , V_69 ;
V_64 = F_4 ( sizeof( struct V_63 ) * V_58 , V_8 ) ;
if ( ! V_64 ) {
F_5 ( L_22 ) ;
return - V_9 ;
}
F_23 (sgl, sg, sgl_nents, i) {
V_64 [ V_69 ] . V_70 = V_62 -> V_71 ;
V_64 [ V_69 ] . V_72 = F_24 ( F_25 ( V_62 ) ) + V_62 -> V_73 ;
}
V_65 = F_26 () ;
F_27 ( F_28 () ) ;
if ( V_59 )
V_20 = F_29 ( V_61 , & V_64 [ 0 ] , V_58 , & V_66 ) ;
else
V_20 = F_30 ( V_61 , & V_64 [ 0 ] , V_58 , & V_66 ) ;
F_27 ( V_65 ) ;
F_23 (sgl, sg, sgl_nents, i)
F_31 ( F_25 ( V_62 ) ) ;
F_8 ( V_64 ) ;
if ( V_59 ) {
if ( V_20 < 0 || V_20 != V_55 -> V_74 ) {
F_5 ( L_23 , V_75 , V_20 ) ;
return ( V_20 < 0 ? V_20 : - V_21 ) ;
}
} else {
if ( F_14 ( F_32 ( V_61 ) -> V_34 ) ) {
if ( V_20 < 0 || V_20 != V_55 -> V_74 ) {
F_5 ( L_24
L_25 , V_75 , V_20 ,
V_55 -> V_74 ) ;
return ( V_20 < 0 ? V_20 : - V_21 ) ;
}
} else {
if ( V_20 < 0 ) {
F_5 ( L_26 ,
V_75 , V_20 ) ;
return V_20 ;
}
}
}
return 1 ;
}
static T_4
F_33 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = V_55 -> V_60 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_76 = ( V_55 -> V_77 [ 1 ] & 0x2 ) ;
T_3 V_78 , V_79 ;
int V_20 ;
if ( V_76 )
F_34 ( V_55 , V_80 ) ;
if ( V_55 -> V_67 == 0 && V_55 -> V_74 == 0 ) {
V_78 = 0 ;
V_79 = V_81 ;
} else {
V_78 = V_55 -> V_67 * V_3 -> V_39 . V_68 ;
if ( V_55 -> V_74 )
V_79 = V_78 + V_55 -> V_74 ;
else
V_79 = V_81 ;
}
V_20 = F_35 ( V_1 -> V_31 , V_78 , V_79 , 1 ) ;
if ( V_20 != 0 )
F_5 ( L_27 , V_20 ) ;
if ( V_76 )
return 0 ;
if ( V_20 )
F_34 ( V_55 , V_82 ) ;
else
F_34 ( V_55 , V_80 ) ;
return 0 ;
}
static unsigned char *
F_36 ( struct V_54 * V_55 , struct V_56 * V_62 ,
unsigned int V_83 )
{
struct V_2 * V_60 = V_55 -> V_60 ;
unsigned int V_68 = V_60 -> V_39 . V_68 ;
unsigned int V_69 = 0 , V_79 ;
unsigned char * V_84 , * V_85 , * V_86 ;
V_84 = F_4 ( F_37 (unsigned int, len, PAGE_SIZE) , V_8 ) ;
if ( ! V_84 ) {
F_5 ( L_28 ) ;
return NULL ;
}
V_86 = F_24 ( F_25 ( V_62 ) ) + V_62 -> V_73 ;
if ( ! V_86 ) {
F_5 ( L_29 ) ;
F_8 ( V_84 ) ;
return NULL ;
}
V_85 = V_84 ;
V_79 = F_37 (unsigned int, len, PAGE_SIZE) ;
while ( V_69 < V_79 ) {
memcpy ( V_85 , V_86 , V_68 ) ;
V_69 += V_68 ;
V_85 += V_68 ;
}
F_31 ( F_25 ( V_62 ) ) ;
return V_84 ;
}
static T_4
F_38 ( struct V_54 * V_55 )
{
struct V_2 * V_60 = V_55 -> V_60 ;
struct V_1 * V_1 = F_1 ( V_60 ) ;
struct V_17 * V_87 = V_1 -> V_31 ;
struct V_56 * V_62 ;
struct V_63 * V_64 ;
T_2 V_65 ;
T_5 V_88 = F_39 ( V_55 ) ;
T_3 V_66 = V_55 -> V_67 * V_60 -> V_39 . V_68 ;
unsigned int V_83 , V_89 , V_90 ;
int V_69 , V_91 ;
unsigned char * V_84 ;
if ( ! V_88 ) {
F_34 ( V_55 , V_80 ) ;
return 0 ;
}
V_62 = & V_55 -> V_92 [ 0 ] ;
if ( V_55 -> V_93 > 1 ||
V_62 -> V_71 != V_55 -> V_60 -> V_39 . V_68 ) {
F_5 ( L_30
L_31 , V_55 -> V_93 , V_62 -> V_71 ,
V_55 -> V_60 -> V_39 . V_68 ) ;
return V_94 ;
}
V_83 = V_89 = V_88 * V_60 -> V_39 . V_68 ;
V_90 = F_40 ( V_83 , V_95 ) ;
V_84 = F_36 ( V_55 , V_62 , V_83 ) ;
if ( ! V_84 )
return V_96 ;
V_64 = F_41 ( sizeof( struct V_63 ) * V_90 ) ;
if ( ! V_64 ) {
F_5 ( L_32 ) ;
F_8 ( V_84 ) ;
return V_96 ;
}
for ( V_69 = 0 ; V_69 < V_90 ; V_69 ++ ) {
V_64 [ V_69 ] . V_72 = V_84 ;
V_64 [ V_69 ] . V_70 = F_37 (unsigned int, len_tmp, PAGE_SIZE) ;
V_89 -= V_64 [ V_69 ] . V_70 ;
}
V_65 = F_26 () ;
F_27 ( F_28 () ) ;
V_91 = F_29 ( V_87 , & V_64 [ 0 ] , V_90 , & V_66 ) ;
F_27 ( V_65 ) ;
F_42 ( V_64 ) ;
F_8 ( V_84 ) ;
if ( V_91 < 0 || V_91 != V_83 ) {
F_5 ( L_33 , V_91 ) ;
return V_96 ;
}
F_34 ( V_55 , V_80 ) ;
return 0 ;
}
static T_4
F_43 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_92 ;
T_1 V_58 = V_55 -> V_93 ;
enum V_97 V_98 = V_55 -> V_98 ;
struct V_2 * V_3 = V_55 -> V_60 ;
int V_20 = 0 ;
if ( V_98 == V_99 ) {
V_20 = F_22 ( V_55 , V_57 , V_58 , 0 ) ;
} else {
V_20 = F_22 ( V_55 , V_57 , V_58 , 1 ) ;
if ( V_20 > 0 &&
V_3 -> V_39 . V_100 > 0 &&
( V_55 -> V_101 & V_102 ) ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_78 = V_55 -> V_67 *
V_3 -> V_39 . V_68 ;
T_3 V_79 = V_78 + V_55 -> V_74 ;
F_35 ( V_1 -> V_31 , V_78 , V_79 , 1 ) ;
}
}
if ( V_20 < 0 )
return V_96 ;
if ( V_20 )
F_34 ( V_55 , V_80 ) ;
return 0 ;
}
static T_6 F_44 ( struct V_2 * V_3 ,
const char * V_103 , T_6 V_104 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_105 , * V_106 , * V_107 , * V_108 ;
T_7 args [ V_109 ] ;
int V_20 = 0 , V_110 , V_111 ;
V_108 = F_45 ( V_103 , V_8 ) ;
if ( ! V_108 )
return - V_9 ;
V_105 = V_108 ;
while ( ( V_106 = F_46 ( & V_108 , L_34 ) ) != NULL ) {
if ( ! * V_106 )
continue;
V_111 = F_47 ( V_106 , V_112 , args ) ;
switch ( V_111 ) {
case V_113 :
if ( F_48 ( V_1 -> V_29 , & args [ 0 ] ,
V_114 ) == 0 ) {
V_20 = - V_21 ;
break;
}
F_6 ( L_35 ,
V_1 -> V_29 ) ;
V_1 -> V_22 |= V_23 ;
break;
case V_115 :
V_107 = F_49 ( & args [ 0 ] ) ;
if ( ! V_107 ) {
V_20 = - V_9 ;
break;
}
V_20 = F_50 ( V_107 , 0 , & V_1 -> V_53 ) ;
F_8 ( V_107 ) ;
if ( V_20 < 0 ) {
F_5 ( L_36
L_37 ) ;
goto V_116;
}
F_6 ( L_38
L_39 , V_1 -> V_53 ) ;
V_1 -> V_22 |= V_43 ;
break;
case V_117 :
F_51 ( args , & V_110 ) ;
if ( V_110 != 1 ) {
F_5 ( L_40 , V_110 ) ;
V_20 = - V_21 ;
goto V_116;
}
F_6 ( L_41
L_42 ) ;
V_1 -> V_22 |= V_28 ;
break;
default:
break;
}
}
V_116:
F_8 ( V_105 ) ;
return ( ! V_20 ) ? V_104 : V_20 ;
}
static T_6 F_52 ( struct V_2 * V_3 , char * V_118 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_6 V_119 = 0 ;
V_119 = sprintf ( V_118 + V_119 , L_43 , V_1 -> V_48 ) ;
V_119 += sprintf ( V_118 + V_119 , L_44 ,
V_1 -> V_29 , V_1 -> V_53 ,
( V_1 -> V_22 & V_28 ) ?
L_45 : L_46 ) ;
return V_119 ;
}
static T_5 F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_87 = V_1 -> V_31 ;
struct V_18 * V_69 = V_87 -> V_32 -> V_33 ;
unsigned long long V_38 ;
if ( F_14 ( V_69 -> V_34 ) )
V_38 = ( F_18 ( V_69 ) - V_1 -> V_42 ) ;
else
V_38 = V_1 -> V_53 ;
return F_19 ( V_38 , V_3 -> V_39 . V_68 ) ;
}
static T_4
F_54 ( struct V_54 * V_55 )
{
return F_55 ( V_55 , & V_120 ) ;
}
static int T_8 F_56 ( void )
{
return F_57 ( & V_121 ) ;
}
static void T_9 F_58 ( void )
{
F_59 ( & V_121 ) ;
}
