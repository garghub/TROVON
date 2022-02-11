static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_2 * F_3 ( struct V_4 * V_5 ,
const char * V_6 )
{
struct V_1 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_5 ( - V_9 ) ;
V_7 -> V_10 . V_11 = F_6 ( 1 ) ;
V_7 -> V_10 . V_12 = V_13 ;
V_7 -> V_10 . V_14 = V_15 ;
V_7 -> V_10 . V_16 = F_7 ( 0x0100 ) ;
V_7 -> V_10 . V_17 = F_8 ( 48000000 ) ;
F_9 ( & V_7 -> V_3 , V_6 , & V_18 ) ;
return & V_7 -> V_3 ;
}
static void F_10 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_11 ( V_7 ) ;
}
static inline struct V_19
* F_12 ( struct V_2 * V_3 )
{
return F_2 ( F_13 ( V_3 ) ,
struct V_19 , V_5 ) ;
}
static T_1 F_14 (
struct V_2 * V_3 , char * V_20 )
{
struct V_19 * V_21 = F_12 ( V_3 ) ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_21 -> V_5 . V_27 -> V_26 ;
struct V_28 * V_29 ;
int V_30 , V_31 ;
char * V_32 = V_20 ;
F_15 ( V_26 ) ;
V_24 = V_21 -> V_5 . V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
V_29 = & V_23 -> V_35 ;
F_15 ( & V_23 -> V_36 ) ;
for ( V_30 = 0 , V_31 = 0 ; V_31 < V_29 -> V_37 ; ++ V_31 ) {
V_30 += sprintf ( V_32 , L_1 , V_29 -> V_38 [ V_31 ] ) ;
V_32 = V_20 + V_30 ;
}
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_30 ;
}
static inline struct V_39
* F_18 ( struct V_2 * V_3 )
{
return F_2 ( F_13 ( V_3 ) ,
struct V_39 , V_5 ) ;
}
static T_1 F_19 (
struct V_2 * V_3 , char * V_20 )
{
struct V_39 * V_40 = F_18 ( V_3 ) ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_40 -> V_5 . V_27 -> V_26 ;
struct V_41 * V_42 ;
int V_30 , V_31 ;
char * V_32 = V_20 ;
F_15 ( V_26 ) ;
V_24 = V_40 -> V_5 . V_33 . V_34 -> V_34 -> V_34 ->
V_34 ;
V_23 = F_16 ( V_24 ) ;
V_42 = & V_23 -> V_43 ;
F_15 ( & V_23 -> V_36 ) ;
for ( V_30 = 0 , V_31 = 0 ; V_31 < V_42 -> V_37 ; ++ V_31 ) {
V_30 += sprintf ( V_32 , L_1 , V_42 -> V_38 [ V_31 ] ) ;
V_32 = V_20 + V_30 ;
}
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_30 ;
}
static inline struct V_44
* F_20 ( struct V_2 * V_3 )
{
return F_2 ( F_13 ( V_3 ) ,
struct V_44 , V_5 ) ;
}
static inline struct V_45
* * F_21 ( struct V_2 * V_31 , struct V_22 * V_46 )
{
struct V_47 * V_48 = F_2 ( F_13 ( V_31 ) ,
struct V_47 , V_5 ) ;
if ( V_48 == & V_49 )
return V_46 -> V_50 ;
if ( V_48 == & V_51 )
return V_46 -> V_52 ;
return NULL ;
}
static int F_22 ( struct V_2 * V_53 ,
struct V_2 * V_54 )
{
struct V_2 * V_55 , * V_56 ;
struct V_22 * V_23 ;
struct V_25 * V_26 = & V_53 -> V_57 -> V_27 -> V_26 ;
struct V_45 * * V_58 ;
struct V_1 * V_59 ;
int V_60 = - V_61 ;
F_15 ( V_26 ) ;
V_55 = V_53 -> V_34 -> V_34 ;
V_56 = F_23 ( F_13 ( V_55 ) , L_2 ) ;
if ( ! V_56 || V_54 -> V_34 != V_56 )
goto V_62;
V_23 = F_16 ( V_55 -> V_34 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_58 = F_21 ( V_53 , V_23 ) ;
if ( ! V_58 )
goto V_63;
if ( V_23 -> V_64 || V_58 [ 0 ] ) {
V_60 = - V_65 ;
goto V_63;
}
V_59 = F_1 ( V_54 ) ;
++ V_59 -> V_66 ;
V_58 [ 0 ] = (struct V_45 * ) & V_59 -> V_10 ;
V_60 = 0 ;
V_63:
F_17 ( & V_23 -> V_36 ) ;
V_62:
F_17 ( V_26 ) ;
return V_60 ;
}
static int F_24 ( struct V_2 * V_53 ,
struct V_2 * V_54 )
{
struct V_2 * V_55 , * V_56 ;
struct V_22 * V_23 ;
struct V_25 * V_26 = & V_53 -> V_57 -> V_27 -> V_26 ;
struct V_45 * * V_58 ;
struct V_1 * V_59 ;
int V_60 = - V_61 ;
F_15 ( V_26 ) ;
V_55 = V_53 -> V_34 -> V_34 ;
V_56 = F_23 ( F_13 ( V_55 ) , L_2 ) ;
if ( ! V_56 || V_54 -> V_34 != V_56 )
goto V_62;
V_23 = F_16 ( V_55 -> V_34 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_58 = F_21 ( V_53 , V_23 ) ;
if ( ! V_58 )
goto V_63;
if ( V_23 -> V_64 ) {
V_60 = - V_65 ;
goto V_63;
}
V_59 = F_1 ( V_54 ) ;
-- V_59 -> V_66 ;
V_58 [ 0 ] = NULL ;
V_60 = 0 ;
V_63:
F_17 ( & V_23 -> V_36 ) ;
V_62:
F_17 ( V_26 ) ;
return V_60 ;
}
static struct V_67 * F_25 ( struct V_2 * V_3 )
{
return F_2 ( F_13 ( V_3 ) , struct V_67 , V_5 ) ;
}
static T_1 F_26 ( struct V_67 * V_68 , char * V_20 )
{
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_68 -> V_5 . V_27 -> V_26 ;
int V_30 , V_31 ;
char * V_32 = V_20 ;
F_15 ( V_26 ) ;
V_24 = V_68 -> V_5 . V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_30 = sprintf ( V_32 , L_3 ) ;
V_32 += V_30 ;
for ( V_31 = 0 ; V_31 < V_69 ; ++ V_31 ) {
V_30 += sprintf ( V_32 , L_4 , V_68 -> V_70 [ V_31 ] ) ;
V_32 = V_20 + V_30 ;
}
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_30 ;
}
static T_1 F_27 ( struct V_67 * V_71 ,
const char * V_20 , T_2 V_72 )
{
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_71 -> V_5 . V_27 -> V_26 ;
int V_60 = - V_61 ;
F_15 ( V_26 ) ;
V_24 = V_71 -> V_5 . V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
if ( V_71 -> V_66 || V_23 -> V_64 ) {
V_60 = - V_65 ;
goto V_73;
}
if ( V_72 < 4 || * V_20 != '0' ||
( * ( V_20 + 1 ) != 'x' && * ( V_20 + 1 ) != 'X' ) )
goto V_73;
V_60 = F_28 ( V_71 -> V_70 , V_20 + 2 , 1 ) ;
if ( V_60 < 0 )
goto V_73;
V_60 = V_72 ;
V_73:
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_60 ;
}
static struct V_74 * F_29 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_74 , V_3 ) ;
}
static int F_30 ( struct V_2 * V_53 ,
struct V_2 * V_54 )
{
struct V_25 * V_26 = & V_53 -> V_57 -> V_27 -> V_26 ;
struct V_2 * V_24 ;
struct V_22 * V_23 ;
struct V_74 * V_75 ;
struct V_67 * V_76 = NULL ;
struct V_77 * V_78 ;
int V_31 , V_60 = - V_61 ;
V_75 = F_29 ( V_53 ) ;
F_15 ( V_26 ) ;
V_24 = V_53 -> V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
if ( V_75 -> V_66 ) {
V_60 = - V_65 ;
goto V_62;
}
for ( V_31 = 0 ; V_31 < F_31 ( V_79 ) ; ++ V_31 )
if ( V_54 -> V_34 == V_79 [ V_31 ] )
break;
if ( V_31 == F_31 ( V_79 ) )
goto V_62;
V_76 = F_2 ( F_13 ( V_54 ) , struct V_67 ,
V_5 ) ;
if ( ! V_76 )
goto V_62;
V_78 = F_4 ( sizeof( * V_78 ) , V_8 ) ;
if ( ! V_78 ) {
V_60 = - V_9 ;
goto V_62;
}
V_60 = 0 ;
V_78 -> V_80 = V_76 ;
F_32 ( & V_78 -> V_81 , & V_75 -> V_82 ) ;
++ V_75 -> V_83 ;
V_62:
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_60 ;
}
static int F_33 ( struct V_2 * V_53 ,
struct V_2 * V_54 )
{
struct V_25 * V_26 = & V_53 -> V_57 -> V_27 -> V_26 ;
struct V_2 * V_24 ;
struct V_22 * V_23 ;
struct V_74 * V_75 ;
struct V_67 * V_76 = NULL ;
struct V_77 * V_78 , * V_84 ;
int V_60 = - V_61 ;
V_75 = F_29 ( V_53 ) ;
F_15 ( V_26 ) ;
V_24 = V_53 -> V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_76 = F_2 ( F_13 ( V_54 ) , struct V_67 ,
V_5 ) ;
if ( ! V_76 )
goto V_62;
F_34 (format_ptr, tmp, &src_hdr->formats, entry)
if ( V_78 -> V_80 == V_76 ) {
F_35 ( & V_78 -> V_81 ) ;
F_11 ( V_78 ) ;
-- V_75 -> V_83 ;
break;
}
V_62:
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_60 ;
}
static struct V_2
* F_36 ( struct V_4 * V_5 , const char * V_6 )
{
struct V_74 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_5 ( - V_9 ) ;
F_37 ( & V_7 -> V_82 ) ;
V_7 -> V_10 . V_12 = V_13 ;
V_7 -> V_10 . V_14 = V_85 ;
V_7 -> V_10 . V_86 = 3 ;
V_7 -> V_10 . V_37 = V_69 ;
F_9 ( & V_7 -> V_3 , V_6 , & V_87 ) ;
return & V_7 -> V_3 ;
}
static void F_38 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_74 * V_7 = F_29 ( V_3 ) ;
F_11 ( V_7 ) ;
}
static struct V_88 * F_39 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_88 , V_3 ) ;
}
static T_1 F_40 ( struct V_2 * V_3 ,
char * V_20 )
{
struct V_88 * V_89 = F_39 ( V_3 ) ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_89 -> V_3 . V_57 -> V_27 -> V_26 ;
int V_30 , V_31 ;
char * V_32 = V_20 ;
F_15 ( V_26 ) ;
V_24 = V_89 -> V_3 . V_34 -> V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
for ( V_30 = 0 , V_31 = 0 ; V_31 < V_89 -> V_90 . V_91 ; ++ V_31 ) {
V_30 += sprintf ( V_32 , L_1 ,
F_41 ( V_89 -> V_92 [ V_31 ] ) ) ;
V_32 = V_20 + V_30 ;
}
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_30 ;
}
static inline int F_42 ( char * V_93 , void * V_94 )
{
++ * ( ( int * ) V_94 ) ;
return 0 ;
}
static inline int F_43 ( char * V_93 , void * V_94 )
{
T_3 V_95 , * * V_96 ;
int V_60 ;
V_60 = F_44 ( V_93 , 0 , & V_95 ) ;
if ( V_60 )
return V_60 ;
V_96 = V_94 ;
* * V_96 = F_8 ( V_95 ) ;
++ * V_96 ;
return 0 ;
}
static int F_45 ( const char * V_20 , T_2 V_72 ,
int (* F_46)( char * , void * ) , void * V_94 )
{
char V_93 [ 1 + sizeof( T_3 ) * 8 + 1 + 1 ] ;
const char * V_32 = V_20 ;
int V_31 , V_60 ;
if ( ! F_46 )
return - V_61 ;
while ( V_32 - V_20 < V_72 ) {
V_31 = 0 ;
while ( V_31 < sizeof( V_93 ) && ( V_32 - V_20 < V_72 ) &&
* V_32 != '\0' && * V_32 != '\n' )
V_93 [ V_31 ++ ] = * V_32 ++ ;
if ( V_31 == sizeof( V_93 ) )
return - V_61 ;
while ( ( V_32 - V_20 < V_72 ) && ( * V_32 == '\0' || * V_32 == '\n' ) )
++ V_32 ;
V_93 [ V_31 ] = '\0' ;
V_60 = F_46 ( V_93 , V_94 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static T_1 F_47 ( struct V_2 * V_3 ,
const char * V_20 , T_2 V_72 )
{
struct V_88 * V_71 = F_39 ( V_3 ) ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_67 * V_80 ;
struct V_25 * V_26 = & V_71 -> V_3 . V_57 -> V_27 -> V_26 ;
int V_60 = 0 , V_97 = 0 ;
T_3 * V_98 , * V_84 ;
F_15 ( V_26 ) ;
V_24 = V_71 -> V_3 . V_34 -> V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
V_80 = F_25 ( V_71 -> V_3 . V_34 ) ;
F_15 ( & V_23 -> V_36 ) ;
if ( V_80 -> V_66 || V_23 -> V_64 ) {
V_60 = - V_65 ;
goto V_73;
}
V_60 = F_45 ( V_20 , V_72 , F_42 , & V_97 ) ;
if ( V_60 )
goto V_73;
V_84 = V_98 = F_48 ( V_97 , sizeof( T_3 ) , V_8 ) ;
if ( ! V_98 ) {
V_60 = - V_9 ;
goto V_73;
}
V_60 = F_45 ( V_20 , V_72 , F_43 , & V_84 ) ;
if ( V_60 ) {
F_11 ( V_98 ) ;
goto V_73;
}
F_11 ( V_71 -> V_92 ) ;
V_71 -> V_92 = V_98 ;
V_71 -> V_90 . V_91 = V_97 ;
V_60 = V_72 ;
V_73:
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_60 ;
}
static struct V_2 * F_49 ( struct V_4 * V_5 ,
const char * V_6 )
{
struct V_88 * V_7 ;
struct V_67 * V_80 ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_5 ( - V_9 ) ;
V_7 -> V_90 . V_99 = V_13 ;
V_7 -> V_90 . V_100 = 1 ;
V_7 -> V_90 . V_101 = F_7 ( 640 ) ;
V_7 -> V_90 . V_102 = F_7 ( 360 ) ;
V_7 -> V_90 . V_103 = F_8 ( 18432000 ) ;
V_7 -> V_90 . V_104 = F_8 ( 55296000 ) ;
V_7 -> V_90 . V_105 = F_8 ( 460800 ) ;
V_7 -> V_90 . V_106 = F_8 ( 666666 ) ;
V_24 = V_5 -> V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_80 = F_25 ( & V_5 -> V_33 ) ;
if ( V_80 -> type == V_107 ) {
V_7 -> V_90 . V_108 = V_109 ;
V_7 -> V_110 = V_107 ;
} else if ( V_80 -> type == V_111 ) {
V_7 -> V_90 . V_108 = V_112 ;
V_7 -> V_110 = V_111 ;
} else {
F_17 ( & V_23 -> V_36 ) ;
F_11 ( V_7 ) ;
return F_5 ( - V_61 ) ;
}
++ V_80 -> V_113 ;
F_17 ( & V_23 -> V_36 ) ;
F_9 ( & V_7 -> V_3 , V_6 , & V_114 ) ;
return & V_7 -> V_3 ;
}
static void F_50 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
struct V_88 * V_7 = F_39 ( V_3 ) ;
struct V_67 * V_80 ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
V_24 = V_5 -> V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_80 = F_25 ( & V_5 -> V_33 ) ;
-- V_80 -> V_113 ;
F_11 ( V_7 ) ;
F_17 ( & V_23 -> V_36 ) ;
}
static struct V_115 * F_51 ( struct V_2 * V_3 )
{
return F_2 (
F_2 ( F_13 ( V_3 ) , struct V_67 , V_5 ) ,
struct V_115 , V_80 ) ;
}
static T_1 F_52 ( struct V_2 * V_3 ,
char * V_20 )
{
struct V_115 * V_71 = F_51 ( V_3 ) ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_71 -> V_80 . V_5 . V_27 -> V_26 ;
F_15 ( V_26 ) ;
V_24 = V_71 -> V_80 . V_5 . V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
memcpy ( V_20 , V_71 -> V_10 . V_116 , sizeof( V_71 -> V_10 . V_116 ) ) ;
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return sizeof( V_71 -> V_10 . V_116 ) ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
const char * V_20 , T_2 V_72 )
{
struct V_115 * V_71 = F_51 ( V_3 ) ;
struct V_22 * V_23 ;
struct V_2 * V_24 ;
struct V_25 * V_26 = & V_71 -> V_80 . V_5 . V_27 -> V_26 ;
int V_60 ;
F_15 ( V_26 ) ;
V_24 = V_71 -> V_80 . V_5 . V_33 . V_34 -> V_34 -> V_34 ;
V_23 = F_16 ( V_24 ) ;
F_15 ( & V_23 -> V_36 ) ;
if ( V_71 -> V_80 . V_66 || V_23 -> V_64 ) {
V_60 = - V_65 ;
goto V_73;
}
memcpy ( V_71 -> V_10 . V_116 , V_20 ,
F_54 ( sizeof( V_71 -> V_10 . V_116 ) , V_72 ) ) ;
V_60 = sizeof( V_71 -> V_10 . V_116 ) ;
V_73:
F_17 ( & V_23 -> V_36 ) ;
F_17 ( V_26 ) ;
return V_60 ;
}
static inline T_1
F_55 ( struct V_2 * V_3 , char * V_20 )
{
struct V_115 * V_117 = F_51 ( V_3 ) ;
return F_26 ( & V_117 -> V_80 , V_20 ) ;
}
static inline T_1
F_56 ( struct V_2 * V_3 ,
const char * V_20 , T_2 V_72 )
{
struct V_115 * V_117 = F_51 ( V_3 ) ;
return F_27 ( & V_117 -> V_80 , V_20 , V_72 ) ;
}
static struct V_4 * F_57 ( struct V_4 * V_5 ,
const char * V_6 )
{
static char V_118 [] = {
'Y' , 'U' , 'Y' , '2' , 0x00 , 0x00 , 0x10 , 0x00 ,
0x80 , 0x00 , 0x00 , 0xaa , 0x00 , 0x38 , 0x9b , 0x71
} ;
struct V_115 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_5 ( - V_9 ) ;
V_7 -> V_10 . V_11 = V_119 ;
V_7 -> V_10 . V_12 = V_13 ;
V_7 -> V_10 . V_14 = V_120 ;
memcpy ( V_7 -> V_10 . V_116 , V_118 , sizeof( V_118 ) ) ;
V_7 -> V_10 . V_121 = 16 ;
V_7 -> V_10 . V_122 = 1 ;
V_7 -> V_10 . V_123 = 0 ;
V_7 -> V_10 . V_124 = 0 ;
V_7 -> V_10 . V_125 = 0 ;
V_7 -> V_10 . V_126 = 0 ;
V_7 -> V_80 . type = V_107 ;
F_58 ( & V_7 -> V_80 . V_5 , V_6 ,
& V_127 ) ;
return & V_7 -> V_80 . V_5 ;
}
static void F_59 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_115 * V_7 = F_51 ( V_3 ) ;
F_11 ( V_7 ) ;
}
static struct V_128 * F_60 ( struct V_2 * V_3 )
{
return F_2 (
F_2 ( F_13 ( V_3 ) , struct V_67 , V_5 ) ,
struct V_128 , V_80 ) ;
}
static inline T_1
F_61 ( struct V_2 * V_3 , char * V_20 )
{
struct V_128 * V_129 = F_60 ( V_3 ) ;
return F_26 ( & V_129 -> V_80 , V_20 ) ;
}
static inline T_1
F_62 ( struct V_2 * V_3 ,
const char * V_20 , T_2 V_72 )
{
struct V_128 * V_129 = F_60 ( V_3 ) ;
return F_27 ( & V_129 -> V_80 , V_20 , V_72 ) ;
}
static struct V_4 * F_63 ( struct V_4 * V_5 ,
const char * V_6 )
{
struct V_128 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_5 ( - V_9 ) ;
V_7 -> V_10 . V_11 = V_130 ;
V_7 -> V_10 . V_12 = V_13 ;
V_7 -> V_10 . V_14 = V_131 ;
V_7 -> V_10 . V_122 = 1 ;
V_7 -> V_10 . V_123 = 0 ;
V_7 -> V_10 . V_124 = 0 ;
V_7 -> V_10 . V_125 = 0 ;
V_7 -> V_10 . V_126 = 0 ;
V_7 -> V_80 . type = V_111 ;
F_58 ( & V_7 -> V_80 . V_5 , V_6 ,
& V_132 ) ;
return & V_7 -> V_80 . V_5 ;
}
static void F_64 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_128 * V_7 = F_60 ( V_3 ) ;
F_11 ( V_7 ) ;
}
static inline struct V_133
* F_65 ( struct V_2 * V_3 )
{
return F_2 ( F_13 ( V_3 ) ,
struct V_133 , V_5 ) ;
}
static inline struct V_45
* * * F_66 ( struct V_2 * V_31 , struct V_22 * V_46 )
{
struct V_134 * V_48 = F_2 ( F_13 ( V_31 ) ,
struct V_134 , V_5 ) ;
if ( V_48 == & V_135 )
return & V_46 -> V_136 ;
if ( V_48 == & V_137 )
return & V_46 -> V_138 ;
if ( V_48 == & V_139 )
return & V_46 -> V_140 ;
return NULL ;
}
static int F_67 ( struct V_74 * V_7 ,
void * V_141 , void * V_142 ,
int (* F_46)( void * , void * , void * , int , enum V_143 type ) )
{
struct V_77 * V_68 ;
struct V_4 * V_144 ;
struct V_2 * V_3 ;
struct V_88 * V_89 ;
int V_60 , V_31 , V_145 ;
if ( ! F_46 )
return - V_61 ;
V_31 = V_145 = 0 ;
V_60 = F_46 ( V_7 , V_141 , V_142 , 0 , V_146 ) ;
if ( V_60 )
return V_60 ;
F_68 (f, &h->formats, entry) {
V_60 = F_46 ( V_68 -> V_80 , V_141 , V_142 , V_31 ++ , V_147 ) ;
if ( V_60 )
return V_60 ;
V_144 = & V_68 -> V_80 -> V_5 ;
F_68 (item, &grp->cg_children, ci_entry) {
V_89 = F_39 ( V_3 ) ;
V_60 = F_46 ( V_89 , V_141 , V_142 , V_145 ++ , V_148 ) ;
if ( V_60 )
return V_60 ;
}
}
return V_60 ;
}
static int F_69 ( void * V_149 , void * V_141 , void * V_142 , int V_97 ,
enum V_143 type )
{
T_2 * V_150 = V_141 ;
T_2 * V_151 = V_142 ;
switch ( type ) {
case V_146 : {
struct V_74 * V_7 = V_149 ;
* V_150 += sizeof( V_7 -> V_10 ) ;
* V_150 += V_7 -> V_83 * V_69 ;
}
break;
case V_147 : {
struct V_67 * V_80 = V_149 ;
if ( V_80 -> type == V_107 ) {
struct V_115 * V_129 =
F_2 ( V_80 , struct V_115 ,
V_80 ) ;
* V_150 += sizeof( V_129 -> V_10 ) ;
} else if ( V_80 -> type == V_111 ) {
struct V_128 * V_152 =
F_2 ( V_80 , struct V_128 , V_80 ) ;
* V_150 += sizeof( V_152 -> V_10 ) ;
} else {
return - V_61 ;
}
}
break;
case V_148 : {
struct V_88 * V_89 = V_149 ;
int V_153 = sizeof( V_89 -> V_92 ) ;
* V_150 += sizeof( V_89 -> V_90 ) ;
* V_150 += V_89 -> V_90 . V_91 * V_153 ;
}
break;
}
++ * V_151 ;
return 0 ;
}
static int F_70 ( void * V_149 , void * V_141 , void * V_142 , int V_97 ,
enum V_143 type )
{
void * * V_154 = V_141 ;
struct V_45 * * * V_155 = V_142 ;
T_2 V_153 ;
* * V_155 = * V_154 ;
++ * V_155 ;
switch ( type ) {
case V_146 : {
struct V_156 * V_157 = * V_154 ;
struct V_74 * V_7 = V_149 ;
struct V_77 * V_68 ;
memcpy ( * V_154 , & V_7 -> V_10 , sizeof( V_7 -> V_10 ) ) ;
* V_154 += sizeof( V_7 -> V_10 ) ;
V_153 = V_69 ;
F_68 (f, &h->formats, entry) {
memcpy ( * V_154 , V_68 -> V_80 -> V_70 , V_153 ) ;
* V_154 += V_153 ;
}
V_157 -> V_11 = sizeof( V_7 -> V_10 ) + V_7 -> V_83 * V_153 ;
V_157 -> V_158 = V_7 -> V_83 ;
}
break;
case V_147 : {
struct V_67 * V_80 = V_149 ;
if ( V_80 -> type == V_107 ) {
struct V_159 * V_117 = * V_154 ;
struct V_115 * V_129 =
F_2 ( V_80 , struct V_115 ,
V_80 ) ;
memcpy ( * V_154 , & V_129 -> V_10 , sizeof( V_129 -> V_10 ) ) ;
* V_154 += sizeof( V_129 -> V_10 ) ;
V_117 -> V_160 = V_80 -> V_113 ;
V_117 -> V_161 = V_97 + 1 ;
} else if ( V_80 -> type == V_111 ) {
struct V_162 * V_163 = * V_154 ;
struct V_128 * V_152 =
F_2 ( V_80 , struct V_128 , V_80 ) ;
memcpy ( * V_154 , & V_152 -> V_10 , sizeof( V_152 -> V_10 ) ) ;
* V_154 += sizeof( V_152 -> V_10 ) ;
V_163 -> V_160 = V_80 -> V_113 ;
V_163 -> V_161 = V_97 + 1 ;
} else {
return - V_61 ;
}
}
break;
case V_148 : {
struct V_88 * V_89 = V_149 ;
struct V_45 * V_7 = * V_154 ;
V_153 = sizeof( V_89 -> V_90 ) ;
memcpy ( * V_154 , & V_89 -> V_90 , V_153 ) ;
* V_154 += V_153 ;
V_153 = V_89 -> V_90 . V_91 *
sizeof( * V_89 -> V_92 ) ;
memcpy ( * V_154 , V_89 -> V_92 , V_153 ) ;
* V_154 += V_153 ;
if ( V_89 -> V_110 == V_107 )
V_7 -> V_11 = F_71 (
V_89 -> V_90 . V_91 ) ;
else if ( V_89 -> V_110 == V_111 )
V_7 -> V_11 = F_72 (
V_89 -> V_90 . V_91 ) ;
}
break;
}
return 0 ;
}
static int F_73 ( struct V_2 * V_53 ,
struct V_2 * V_54 )
{
struct V_2 * V_164 , * V_56 ;
struct V_22 * V_23 ;
struct V_25 * V_26 = & V_53 -> V_57 -> V_27 -> V_26 ;
struct V_45 * * * V_58 , * * V_165 ;
struct V_74 * V_59 ;
void * V_166 , * V_167 ;
T_2 V_150 = 0 , V_151 = 0 ;
int V_60 = - V_61 ;
F_15 ( V_26 ) ;
V_164 = V_53 -> V_34 -> V_34 ;
V_56 = F_23 ( F_13 ( V_164 ) , L_2 ) ;
if ( ! V_56 || V_54 -> V_34 != V_56 )
goto V_62;
V_23 = F_16 ( V_164 -> V_34 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_58 = F_66 ( V_53 , V_23 ) ;
if ( ! V_58 || * V_58 || V_23 -> V_64 ) {
V_60 = - V_65 ;
goto V_63;
}
V_59 = F_29 ( V_54 ) ;
V_60 = F_67 ( V_59 , & V_150 , & V_151 , F_69 ) ;
if ( V_60 )
goto V_63;
V_151 += 2 ;
* V_58 = F_48 ( V_151 , sizeof( void * ) , V_8 ) ;
if ( ! * V_58 ) {
V_60 = - V_9 ;
goto V_63;
}
V_166 = V_167 = F_4 ( V_150 , V_8 ) ;
if ( ! V_166 ) {
F_11 ( * V_58 ) ;
* V_58 = NULL ;
V_60 = F_74 ( V_166 ) ;
goto V_63;
}
V_165 = * V_58 ;
V_60 = F_67 ( V_59 , & V_166 , & V_165 ,
F_70 ) ;
if ( V_60 ) {
F_11 ( * V_58 ) ;
* V_58 = NULL ;
F_11 ( V_167 ) ;
goto V_63;
}
* V_165 = (struct V_45 * ) & V_23 -> V_168 ;
++ V_59 -> V_66 ;
V_60 = 0 ;
V_63:
F_17 ( & V_23 -> V_36 ) ;
V_62:
F_17 ( V_26 ) ;
return V_60 ;
}
static int F_75 ( struct V_2 * V_53 ,
struct V_2 * V_54 )
{
struct V_2 * V_164 , * V_56 ;
struct V_22 * V_23 ;
struct V_25 * V_26 = & V_53 -> V_57 -> V_27 -> V_26 ;
struct V_45 * * * V_58 ;
struct V_74 * V_59 ;
int V_60 = - V_61 ;
F_15 ( V_26 ) ;
V_164 = V_53 -> V_34 -> V_34 ;
V_56 = F_23 ( F_13 ( V_164 ) , L_2 ) ;
if ( ! V_56 || V_54 -> V_34 != V_56 )
goto V_62;
V_23 = F_16 ( V_164 -> V_34 ) ;
F_15 ( & V_23 -> V_36 ) ;
V_58 = F_66 ( V_53 , V_23 ) ;
if ( ! V_58 || ! * V_58 )
goto V_63;
if ( V_23 -> V_64 ) {
V_60 = - V_65 ;
goto V_63;
}
V_59 = F_29 ( V_54 ) ;
-- V_59 -> V_66 ;
F_11 ( * * V_58 ) ;
F_11 ( * V_58 ) ;
* V_58 = NULL ;
V_60 = 0 ;
V_63:
F_17 ( & V_23 -> V_36 ) ;
V_62:
F_17 ( V_26 ) ;
return V_60 ;
}
static inline struct V_22 * F_16 ( struct V_2 * V_3 )
{
return F_2 ( F_13 ( V_3 ) , struct V_22 ,
V_169 . V_5 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = F_16 ( V_3 ) ;
F_77 ( & V_23 -> V_169 ) ;
}
int F_78 ( struct V_22 * V_23 )
{
F_58 ( & V_170 . V_5 ,
L_2 ,
& V_171 ) ;
F_58 ( & V_19 . V_5 ,
L_5 , & V_172 ) ;
F_58 ( & V_173 . V_5 ,
L_6 , & V_174 ) ;
F_79 ( & V_19 . V_5 ,
& V_173 . V_5 ) ;
F_58 ( & V_39 . V_5 ,
L_5 , & V_175 ) ;
F_58 ( & V_176 . V_5 ,
L_7 , & V_177 ) ;
F_79 ( & V_39 . V_5 ,
& V_176 . V_5 ) ;
F_58 ( & V_44 . V_5 ,
L_5 , & V_178 ) ;
F_58 ( & V_179 . V_5 ,
L_8 , & V_180 ) ;
F_79 ( & V_44 . V_5 ,
& V_179 . V_5 ) ;
F_58 ( & V_181 . V_5 ,
L_9 , & V_182 ) ;
F_79 ( & V_176 . V_5 ,
& V_181 . V_5 ) ;
F_79 ( & V_179 . V_5 ,
& V_181 . V_5 ) ;
F_58 ( & V_49 . V_5 ,
L_10 , & V_183 ) ;
F_58 ( & V_51 . V_5 ,
L_11 , & V_183 ) ;
F_58 ( & V_184 . V_5 ,
L_12 ,
& V_185 ) ;
F_79 ( & V_49 . V_5 ,
& V_184 . V_5 ) ;
F_79 ( & V_51 . V_5 ,
& V_184 . V_5 ) ;
F_58 ( & V_186 . V_5 ,
L_13 ,
& V_187 ) ;
F_79 ( & V_170 . V_5 ,
& V_186 . V_5 ) ;
F_79 ( & V_173 . V_5 ,
& V_186 . V_5 ) ;
F_79 ( & V_181 . V_5 ,
& V_186 . V_5 ) ;
F_79 ( & V_184 . V_5 ,
& V_186 . V_5 ) ;
F_58 ( & V_188 . V_5 ,
L_2 ,
& V_189 ) ;
F_58 ( & V_190 . V_5 ,
L_14 ,
& V_191 ) ;
F_58 ( & V_192 . V_5 ,
L_15 ,
& V_193 ) ;
F_58 ( & V_133 . V_5 ,
L_5 ,
& V_194 ) ;
F_58 ( & V_195 . V_5 ,
L_16 ,
& V_196 ) ;
F_79 ( & V_133 . V_5 ,
& V_195 . V_5 ) ;
F_58 ( & V_135 . V_5 ,
L_10 , & V_197 ) ;
F_58 ( & V_137 . V_5 ,
L_17 , & V_197 ) ;
F_58 ( & V_139 . V_5 ,
L_11 , & V_197 ) ;
F_58 ( & V_198 . V_5 ,
L_12 , & V_199 ) ;
F_79 ( & V_135 . V_5 ,
& V_198 . V_5 ) ;
F_79 ( & V_137 . V_5 ,
& V_198 . V_5 ) ;
F_79 ( & V_139 . V_5 ,
& V_198 . V_5 ) ;
F_58 ( & V_200 . V_5 ,
L_18 , & V_201 ) ;
F_79 ( & V_188 . V_5 ,
& V_200 . V_5 ) ;
F_79 ( & V_190 . V_5 ,
& V_200 . V_5 ) ;
F_79 ( & V_192 . V_5 ,
& V_200 . V_5 ) ;
F_79 ( & V_195 . V_5 ,
& V_200 . V_5 ) ;
F_79 ( & V_198 . V_5 ,
& V_200 . V_5 ) ;
F_58 ( & V_23 -> V_169 . V_5 ,
L_19 ,
& V_202 ) ;
F_79 ( & V_186 . V_5 ,
& V_23 -> V_169 . V_5 ) ;
F_79 ( & V_200 . V_5 ,
& V_23 -> V_169 . V_5 ) ;
return 0 ;
}
