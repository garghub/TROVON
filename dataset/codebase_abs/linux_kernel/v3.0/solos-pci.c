static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 ( V_2 , V_4 ) ;
else
F_2 ( V_4 ) ;
}
static T_1 F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 , V_13 ) ;
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
int V_21 ;
V_21 = strlen ( V_9 -> V_9 . V_22 ) + 10 ;
V_4 = F_5 ( sizeof( * V_20 ) + V_21 , V_23 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_1 ) ;
return - V_24 ;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_21 = snprintf ( ( void * ) & V_20 [ 1 ] , V_21 - 1 ,
L_2 , V_25 -> V_26 , V_9 -> V_9 . V_22 ) ;
F_7 ( V_4 , V_21 ) ;
V_20 -> V_27 = F_8 ( V_21 ) ;
V_20 -> V_28 = F_8 ( 0 ) ;
V_20 -> V_29 = F_8 ( 0 ) ;
V_20 -> type = F_8 ( V_30 ) ;
V_18 . V_26 = V_25 -> V_26 ;
V_18 . V_31 = NULL ;
V_18 . V_32 = F_9 ( V_12 ) ;
F_10 ( & V_15 -> V_33 ) ;
F_11 ( & V_18 . V_34 , & V_15 -> V_35 ) ;
F_12 ( & V_15 -> V_33 ) ;
F_13 ( V_15 , V_18 . V_32 , V_4 , NULL ) ;
F_14 ( V_15 -> V_36 , V_18 . V_31 , 5 * V_37 ) ;
F_10 ( & V_15 -> V_33 ) ;
F_15 ( & V_18 . V_34 ) ;
F_12 ( & V_15 -> V_33 ) ;
if ( ! V_18 . V_31 )
return - V_38 ;
V_21 = V_18 . V_31 -> V_39 ;
memcpy ( V_10 , V_18 . V_31 -> V_40 , V_21 ) ;
F_16 ( V_18 . V_31 ) ;
return V_21 ;
}
static T_1 F_17 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_2 V_41 )
{
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 , V_13 ) ;
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
int V_21 ;
T_1 V_42 ;
V_21 = strlen ( V_9 -> V_9 . V_22 ) + 11 + V_41 ;
V_4 = F_5 ( sizeof( * V_20 ) + V_21 , V_23 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_3 ) ;
return - V_24 ;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_21 = snprintf ( ( void * ) & V_20 [ 1 ] , V_21 - 1 ,
L_4 , V_25 -> V_26 , V_9 -> V_9 . V_22 , V_10 ) ;
F_7 ( V_4 , V_21 ) ;
V_20 -> V_27 = F_8 ( V_21 ) ;
V_20 -> V_28 = F_8 ( 0 ) ;
V_20 -> V_29 = F_8 ( 0 ) ;
V_20 -> type = F_8 ( V_30 ) ;
V_18 . V_26 = V_25 -> V_26 ;
V_18 . V_31 = NULL ;
V_18 . V_32 = F_9 ( V_12 ) ;
F_10 ( & V_15 -> V_33 ) ;
F_11 ( & V_18 . V_34 , & V_15 -> V_35 ) ;
F_12 ( & V_15 -> V_33 ) ;
F_13 ( V_15 , V_18 . V_32 , V_4 , NULL ) ;
F_14 ( V_15 -> V_36 , V_18 . V_31 , 5 * V_37 ) ;
F_10 ( & V_15 -> V_33 ) ;
F_15 ( & V_18 . V_34 ) ;
F_12 ( & V_15 -> V_33 ) ;
V_4 = V_18 . V_31 ;
if ( ! V_4 )
return - V_38 ;
V_21 = V_4 -> V_39 ;
if ( V_4 -> V_40 [ V_21 - 1 ] == '\n' )
V_21 -- ;
if ( V_21 == 2 && ! strncmp ( V_4 -> V_40 , L_5 , 2 ) )
V_42 = V_41 ;
else if ( V_21 == 5 && ! strncmp ( V_4 -> V_40 , L_6 , 5 ) )
V_42 = - V_38 ;
else {
V_4 -> V_40 [ V_21 ] = 0 ;
F_6 ( & V_15 -> V_7 -> V_7 , L_7 ,
V_4 -> V_40 ) ;
V_42 = - V_38 ;
}
F_16 ( V_4 ) ;
return V_42 ;
}
static char * F_18 ( struct V_3 * V_4 )
{
int V_43 = 0 ;
char * V_44 = V_4 -> V_40 ;
for ( V_43 = 0 ; V_43 < V_4 -> V_39 ; V_43 ++ ) {
if ( V_44 [ V_43 ] == '\n' ) {
V_44 [ V_43 ] = 0 ;
F_19 ( V_4 , V_43 + 1 ) ;
return V_44 ;
}
if ( ! isprint ( V_44 [ V_43 ] ) )
return NULL ;
}
return NULL ;
}
static int F_20 ( struct V_14 * V_15 , int V_32 , struct V_3 * V_4 )
{
char * V_45 , * V_46 , * V_47 , * V_48 , * V_49 ;
int V_50 , V_51 , V_52 ;
if ( ! V_15 -> V_12 [ V_32 ] )
return - V_53 ;
V_45 = F_18 ( V_4 ) ;
if ( ! V_45 )
return - V_38 ;
V_50 = F_21 ( V_45 , NULL , 10 ) ;
if ( V_50 < 1 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_8 ,
V_50 ) ;
return - V_38 ;
}
V_45 = F_18 ( V_4 ) ;
if ( ! V_45 )
return - V_38 ;
if ( ! strcmp ( V_45 , L_6 ) ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_9 ,
V_32 ) ;
return 0 ;
}
V_52 = F_21 ( V_45 , & V_46 , 10 ) ;
if ( * V_46 )
return - V_38 ;
V_45 = F_18 ( V_4 ) ;
if ( ! V_45 )
return - V_38 ;
V_51 = F_21 ( V_45 , & V_46 , 10 ) ;
if ( * V_46 )
return - V_38 ;
V_47 = F_18 ( V_4 ) ;
if ( ! V_47 )
return - V_38 ;
if ( strcmp ( V_47 , L_10 ) ) {
F_23 ( V_15 -> V_12 [ V_32 ] , V_54 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_11 , V_32 , V_47 ) ;
return 0 ;
}
V_48 = F_18 ( V_4 ) ;
if ( ! V_48 )
return - V_38 ;
V_49 = F_18 ( V_4 ) ;
if ( ! V_49 )
return - V_38 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_12 ,
V_32 , V_47 , V_52 / 1000 , V_51 / 1000 ,
V_48 [ 0 ] ? L_13 : L_14 , V_48 , V_49 [ 0 ] ? L_15 : L_14 , V_49 ) ;
V_15 -> V_12 [ V_32 ] -> V_55 = V_52 / 424 ;
F_23 ( V_15 -> V_12 [ V_32 ] , V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_14 * V_15 , int V_32 , struct V_3 * V_4 )
{
struct V_17 * V_18 ;
unsigned long V_57 ;
int V_58 ;
int V_59 = 0 ;
if ( V_4 -> V_39 < 7 )
return 0 ;
if ( V_4 -> V_40 [ 0 ] != 'L' || ! isdigit ( V_4 -> V_40 [ 1 ] ) ||
! isdigit ( V_4 -> V_40 [ 2 ] ) || ! isdigit ( V_4 -> V_40 [ 3 ] ) ||
! isdigit ( V_4 -> V_40 [ 4 ] ) || ! isdigit ( V_4 -> V_40 [ 5 ] ) ||
V_4 -> V_40 [ 6 ] != '\n' )
return 0 ;
V_58 = F_21 ( & V_4 -> V_40 [ 1 ] , NULL , 10 ) ;
F_26 ( & V_15 -> V_33 , V_57 ) ;
F_27 (prm, &card->param_queue, list) {
if ( V_18 -> V_32 == V_32 && V_18 -> V_26 == V_58 ) {
V_18 -> V_31 = V_4 ;
F_19 ( V_4 , 7 ) ;
F_28 ( & V_15 -> V_36 ) ;
V_59 = 1 ;
break;
}
}
F_29 ( & V_15 -> V_33 , V_57 ) ;
return V_59 ;
}
static T_1 F_30 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 , V_13 ) ;
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_3 * V_4 ;
unsigned int V_39 ;
F_31 ( & V_15 -> V_60 ) ;
V_4 = F_32 ( & V_15 -> V_61 [ F_9 ( V_12 ) ] ) ;
F_33 ( & V_15 -> V_60 ) ;
if( V_4 == NULL )
return sprintf ( V_10 , L_16 ) ;
V_39 = V_4 -> V_39 ;
memcpy ( V_10 , V_4 -> V_40 , V_39 ) ;
F_22 ( & V_15 -> V_7 -> V_7 , L_17 , V_39 ) ;
F_16 ( V_4 ) ;
return V_39 ;
}
static int F_34 ( struct V_14 * V_15 , int V_7 , const char * V_10 , T_2 V_27 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 ;
if ( V_27 > ( V_62 - sizeof( * V_20 ) ) ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_18 ) ;
return 0 ;
}
V_4 = F_5 ( V_27 + sizeof( * V_20 ) , V_63 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_19 ) ;
return 0 ;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( V_27 ) ;
V_20 -> V_28 = F_8 ( 0 ) ;
V_20 -> V_29 = F_8 ( 0 ) ;
V_20 -> type = F_8 ( V_30 ) ;
memcpy ( F_7 ( V_4 , V_27 ) , V_10 , V_27 ) ;
F_13 ( V_15 , V_7 , V_4 , NULL ) ;
return 0 ;
}
static T_1 F_35 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_2 V_41 )
{
struct V_11 * V_12 = F_4 ( V_7 , struct V_11 , V_13 ) ;
struct V_14 * V_15 = V_12 -> V_16 ;
int V_64 ;
V_64 = F_34 ( V_15 , F_9 ( V_12 ) , V_10 , V_41 ) ;
return V_64 ? : V_41 ;
}
static int F_36 ( struct V_14 * V_15 , int V_65 )
{
const struct V_66 * V_67 ;
const char * V_68 ;
int V_69 = 0 ;
int V_70 = 0 ;
int V_71 ;
switch ( V_65 ) {
case 0 :
V_68 = L_20 ;
V_69 = V_72 ;
break;
case 1 :
V_68 = L_21 ;
V_69 = V_73 ;
break;
case 2 :
if ( V_15 -> V_74 > V_75 ) {
V_68 = L_22 ;
V_69 = V_72 ;
} else {
F_24 ( & V_15 -> V_7 -> V_7 , L_23
L_24 ) ;
return - V_76 ;
}
break;
case 3 :
if ( V_15 -> V_74 > V_75 ) {
V_68 = L_21 ;
V_69 = V_73 ;
} else {
F_24 ( & V_15 -> V_7 -> V_7 , L_23
L_24 ) ;
return - V_76 ;
}
break;
default:
return - V_53 ;
}
if ( F_37 ( & V_67 , V_68 , & V_15 -> V_7 -> V_7 ) )
return - V_77 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_25 ) ;
V_70 = V_67 -> V_27 / V_69 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_26 , V_67 -> V_27 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_27 , V_70 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_28 ) ;
F_38 ( 1 , V_15 -> V_78 + V_79 ) ;
( void ) F_39 ( V_15 -> V_78 + V_79 ) ;
if( V_65 == 0 || V_65 == 2 )
F_24 ( & V_15 -> V_7 -> V_7 , L_29 ) ;
if( V_65 == 1 || V_65 == 3 )
F_24 ( & V_15 -> V_7 -> V_7 , L_30 ) ;
F_38 ( ( V_65 * 2 ) , V_15 -> V_78 + V_80 ) ;
F_38 ( 1 , V_15 -> V_78 + V_81 ) ;
F_40 ( V_15 -> V_82 , ! F_39 ( V_15 -> V_78 + V_83 ) ) ;
for ( V_71 = 0 ; V_71 < V_67 -> V_27 ; V_71 += V_69 ) {
int V_43 ;
F_38 ( 0 , V_15 -> V_78 + V_81 ) ;
F_38 ( ( ( V_65 * 2 ) + 1 ) , V_15 -> V_78 + V_80 ) ;
for( V_43 = 0 ; V_43 < V_69 ; V_43 += 4 ) {
T_3 V_84 = F_41 ( ( T_3 * ) ( V_67 -> V_40 + V_71 + V_43 ) ) ;
if( V_15 -> V_74 > V_75 )
F_38 ( V_84 , V_85 + V_43 ) ;
else
F_38 ( V_84 , F_42 ( V_15 , 3 ) + V_43 ) ;
}
F_38 ( V_71 / V_69 , V_15 -> V_78 + V_86 ) ;
F_38 ( 1 , V_15 -> V_78 + V_81 ) ;
F_40 ( V_15 -> V_82 , ! F_39 ( V_15 -> V_78 + V_83 ) ) ;
}
F_43 ( V_67 ) ;
F_38 ( 0 , V_15 -> V_78 + V_81 ) ;
F_38 ( 0 , V_15 -> V_78 + V_79 ) ;
F_38 ( 0 , V_15 -> V_78 + V_80 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_31 ) ;
return 0 ;
}
static T_4 F_44 ( int V_87 , void * V_88 )
{
struct V_14 * V_15 = V_88 ;
int V_89 = 1 ;
F_38 ( 0 , V_15 -> V_78 + V_90 ) ;
if ( V_15 -> V_12 [ 0 ] )
F_45 ( & V_15 -> V_91 ) ;
else
F_28 ( & V_15 -> V_82 ) ;
return F_46 ( V_89 ) ;
}
void F_47 ( unsigned long V_92 )
{
struct V_14 * V_15 = ( void * ) V_92 ;
T_3 V_93 ;
T_3 V_94 = 0 ;
int V_32 ;
V_93 = F_48 ( V_15 ) ;
for ( V_32 = 0 ; V_32 < V_15 -> V_95 ; V_32 ++ ) {
if ( V_93 & ( 0x10 << V_32 ) ) {
struct V_19 V_96 , * V_20 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_27 ;
if ( V_15 -> V_97 ) {
V_4 = V_15 -> V_98 [ V_32 ] ;
V_15 -> V_98 [ V_32 ] = NULL ;
F_49 ( V_15 -> V_7 , F_50 ( V_4 ) -> V_99 ,
V_100 , V_101 ) ;
V_20 = ( void * ) V_4 -> V_40 ;
V_27 = F_51 ( V_20 -> V_27 ) ;
F_7 ( V_4 , V_27 + sizeof( * V_20 ) ) ;
F_19 ( V_4 , sizeof( * V_20 ) ) ;
} else {
V_20 = & V_96 ;
V_94 |= 0x10 << V_32 ;
F_52 ( V_20 , F_42 ( V_15 , V_32 ) , sizeof( * V_20 ) ) ;
V_27 = F_51 ( V_20 -> V_27 ) ;
if ( V_27 > ( V_15 -> V_102 - sizeof( * V_20 ) ) ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_32 ) ;
continue;
}
V_4 = F_5 ( V_27 + 1 , V_63 ) ;
if ( ! V_4 ) {
if ( F_53 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_33 ) ;
continue;
}
F_52 ( F_7 ( V_4 , V_27 ) ,
F_42 ( V_15 , V_32 ) + sizeof( * V_20 ) ,
V_27 ) ;
}
if ( V_103 ) {
F_24 ( & V_15 -> V_7 -> V_7 , L_34 , V_32 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_35 ,
V_27 , F_51 ( V_20 -> V_28 ) ,
F_51 ( V_20 -> V_29 ) ) ;
F_54 ( V_4 ) ;
}
switch ( F_51 ( V_20 -> type ) ) {
case V_104 :
V_2 = F_55 ( V_15 -> V_12 [ V_32 ] , F_51 ( V_20 -> V_28 ) ,
F_51 ( V_20 -> V_29 ) ) ;
if ( ! V_2 ) {
if ( F_53 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_36 ,
F_51 ( V_20 -> V_28 ) , F_51 ( V_20 -> V_29 ) ,
V_32 ) ;
continue;
}
F_56 ( V_2 , V_4 -> V_105 ) ;
V_2 -> V_106 ( V_2 , V_4 ) ;
F_57 ( & V_2 -> V_107 -> V_108 ) ;
break;
case V_109 :
if ( F_20 ( V_15 , V_32 , V_4 ) &&
F_53 () ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_37 , V_4 -> V_39 , V_32 ) ;
F_54 ( V_4 ) ;
}
F_2 ( V_4 ) ;
break;
case V_30 :
default:
if ( F_25 ( V_15 , V_32 , V_4 ) )
break;
F_31 ( & V_15 -> V_60 ) ;
if ( F_58 ( & V_15 -> V_61 [ V_32 ] ) > 10 ) {
if ( F_53 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_38 ,
V_32 ) ;
F_2 ( V_4 ) ;
} else
F_59 ( & V_15 -> V_61 [ V_32 ] , V_4 ) ;
F_33 ( & V_15 -> V_60 ) ;
break;
}
}
if ( V_15 -> V_97 && V_15 -> V_12 [ V_32 ] &&
! V_15 -> V_98 [ V_32 ] ) {
struct V_3 * V_4 = F_5 ( V_100 , V_63 ) ;
if ( V_4 ) {
F_50 ( V_4 ) -> V_99 =
F_60 ( V_15 -> V_7 , V_4 -> V_40 ,
V_100 , V_101 ) ;
F_38 ( F_50 ( V_4 ) -> V_99 ,
V_15 -> V_78 + F_61 ( V_32 ) ) ;
V_15 -> V_98 [ V_32 ] = V_4 ;
} else {
if ( F_53 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_39 ) ;
F_45 ( & V_15 -> V_91 ) ;
}
}
}
if ( V_94 )
F_38 ( V_94 , V_15 -> V_78 + V_110 ) ;
return;
}
static struct V_1 * F_55 ( struct V_11 * V_7 , short V_28 , int V_29 )
{
struct V_111 * V_112 ;
struct V_1 * V_2 = NULL ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
F_62 ( & V_117 ) ;
V_112 = & V_118 [ V_29 & ( V_119 - 1 ) ] ;
F_63 (s, node, head) {
V_2 = F_64 ( V_116 ) ;
if ( V_2 -> V_7 == V_7 && V_2 -> V_29 == V_29 &&
V_2 -> V_28 == V_28 && V_2 -> V_120 . V_121 . V_122 != V_123 &&
F_65 ( V_124 , & V_2 -> V_57 ) )
goto V_125;
}
V_2 = NULL ;
V_125:
F_66 ( & V_117 ) ;
return V_2 ;
}
static int F_67 ( int V_29 )
{
struct V_111 * V_112 ;
struct V_1 * V_2 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_126 = 0 ;
int V_43 ;
F_62 ( & V_117 ) ;
if ( V_29 != 0 ) {
V_112 = & V_118 [ V_29 & ( V_119 - 1 ) ] ;
F_63 (s, node, head) {
V_126 ++ ;
V_2 = F_64 ( V_116 ) ;
F_68 ( V_127 L_40 ,
V_2 -> V_7 -> V_128 ,
V_2 -> V_28 ,
V_2 -> V_29 ) ;
}
} else {
for( V_43 = 0 ; V_43 < V_119 ; V_43 ++ ) {
V_112 = & V_118 [ V_43 ] ;
F_63 (s, node, head) {
V_126 ++ ;
V_2 = F_64 ( V_116 ) ;
F_68 ( V_127 L_40 ,
V_2 -> V_7 -> V_128 ,
V_2 -> V_28 ,
V_2 -> V_29 ) ;
}
}
}
F_66 ( & V_117 ) ;
return V_126 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
if ( V_2 -> V_120 . V_129 != V_130 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_41 ,
V_2 -> V_120 . V_129 ) ;
return - V_131 ;
}
V_4 = F_5 ( sizeof( * V_20 ) , V_63 ) ;
if ( ! V_4 ) {
if ( F_53 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_42 ) ;
return - V_24 ;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_132 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , NULL ) ;
F_70 ( V_133 , & V_2 -> V_57 ) ;
F_70 ( V_124 , & V_2 -> V_57 ) ;
F_67 ( 0 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
V_4 = F_5 ( sizeof( * V_20 ) , V_63 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_43 ) ;
return;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_134 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , NULL ) ;
F_72 ( V_133 , & V_2 -> V_57 ) ;
F_72 ( V_124 , & V_2 -> V_57 ) ;
F_73 ( & V_15 -> V_91 ) ;
return;
}
static int F_54 ( struct V_3 * V_10 )
{
int V_39 , V_43 ;
char V_135 [ 500 ] ;
char V_136 [ 10 ] ;
V_39 = V_10 -> V_39 ;
for ( V_43 = 0 ; V_43 < V_39 ; V_43 ++ ) {
if( V_43 % 8 == 0 )
sprintf ( V_135 , L_44 , V_43 ) ;
sprintf ( V_136 , L_45 , * ( V_10 -> V_40 + V_43 ) ) ;
strcat ( V_135 , V_136 ) ;
if( V_43 % 8 == 7 ) {
sprintf ( V_136 , L_46 ) ;
strcat ( V_135 , V_136 ) ;
F_68 ( V_127 L_47 , V_135 ) ;
}
}
if ( V_43 % 8 != 0 ) {
sprintf ( V_136 , L_46 ) ;
strcat ( V_135 , V_136 ) ;
F_68 ( V_127 L_47 , V_135 ) ;
}
F_68 ( V_127 L_46 ) ;
return 0 ;
}
static void F_13 ( struct V_14 * V_15 , int V_32 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_137 ;
unsigned long V_57 ;
F_50 ( V_4 ) -> V_2 = V_2 ;
F_26 ( & V_15 -> V_138 , V_57 ) ;
V_137 = F_58 ( & V_15 -> V_139 [ V_32 ] ) ;
F_59 ( & V_15 -> V_139 [ V_32 ] , V_4 ) ;
if ( ! V_137 )
V_15 -> V_140 |= ( 1 << V_32 ) ;
F_29 ( & V_15 -> V_138 , V_57 ) ;
if ( ! V_137 )
F_48 ( V_15 ) ;
}
static T_3 F_48 ( struct V_14 * V_15 )
{
T_3 V_141 , V_93 ;
T_3 V_142 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned char V_32 ;
unsigned long V_57 ;
F_26 ( & V_15 -> V_143 , V_57 ) ;
V_93 = F_39 ( V_15 -> V_78 + V_110 ) ;
V_141 = V_15 -> V_140 & ~ V_93 ;
for ( V_32 = 0 ; V_141 ; V_141 >>= 1 , V_32 ++ ) {
if ( V_141 & 1 ) {
struct V_3 * V_144 = V_15 -> V_145 [ V_32 ] ;
if ( V_144 )
F_49 ( V_15 -> V_7 , F_50 ( V_144 ) -> V_99 ,
V_144 -> V_39 , V_146 ) ;
F_31 ( & V_15 -> V_138 ) ;
V_4 = F_32 ( & V_15 -> V_139 [ V_32 ] ) ;
if ( ! V_4 )
V_15 -> V_140 &= ~ ( 1 << V_32 ) ;
F_33 ( & V_15 -> V_138 ) ;
if ( V_4 && ! V_15 -> V_97 ) {
F_74 ( F_75 ( V_15 , V_32 ) , V_4 -> V_40 , V_4 -> V_39 ) ;
V_142 |= 1 << V_32 ;
V_144 = V_4 ;
} else if ( V_4 && V_15 -> V_97 ) {
F_50 ( V_4 ) -> V_99 = F_60 ( V_15 -> V_7 , V_4 -> V_40 ,
V_4 -> V_39 , V_146 ) ;
F_38 ( F_50 ( V_4 ) -> V_99 ,
V_15 -> V_78 + F_76 ( V_32 ) ) ;
}
if ( ! V_144 )
continue;
if ( V_103 ) {
struct V_19 * V_20 = ( void * ) V_144 -> V_40 ;
int V_27 = F_51 ( V_20 -> V_27 ) ;
F_19 ( V_144 , sizeof( * V_20 ) ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_48 ,
V_32 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_35 ,
V_27 , F_51 ( V_20 -> V_28 ) ,
F_51 ( V_20 -> V_29 ) ) ;
F_54 ( V_144 ) ;
}
V_2 = F_50 ( V_144 ) -> V_2 ;
if ( V_2 ) {
F_57 ( & V_2 -> V_107 -> V_147 ) ;
F_1 ( V_2 , V_144 ) ;
} else
F_77 ( V_144 ) ;
}
}
if ( V_142 )
F_38 ( V_142 , V_15 -> V_78 + V_110 ) ;
F_29 ( & V_15 -> V_143 , V_57 ) ;
return V_93 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_19 * V_20 ;
int V_148 ;
V_148 = V_4 -> V_39 ;
if ( V_148 > ( V_62 - sizeof( * V_20 ) ) ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_49 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
if ( ! F_79 ( V_4 , sizeof( * V_20 ) ) ) {
int V_149 = 0 ;
int V_42 ;
if ( F_80 ( V_4 ) < sizeof( * V_20 ) )
V_149 = sizeof( * V_20 ) - F_80 ( V_4 ) ;
V_42 = F_81 ( V_4 , V_149 , 0 , V_63 ) ;
if ( V_42 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_50 ) ;
F_1 ( V_2 , V_4 ) ;
return V_42 ;
}
}
V_20 = ( void * ) F_82 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( V_148 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_104 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_150 * V_7 , const struct V_151 * V_152 )
{
int V_64 ;
T_5 V_153 ;
T_6 V_154 , V_155 ;
T_3 V_156 ;
struct V_14 * V_15 ;
V_15 = F_84 ( sizeof( * V_15 ) , V_23 ) ;
if ( ! V_15 )
return - V_24 ;
V_15 -> V_7 = V_7 ;
F_85 ( & V_15 -> V_82 ) ;
F_85 ( & V_15 -> V_36 ) ;
V_64 = F_86 ( V_7 ) ;
if ( V_64 ) {
F_6 ( & V_7 -> V_7 , L_51 ) ;
goto V_125;
}
V_64 = F_87 ( V_7 , F_88 ( 32 ) ) ;
if ( V_64 ) {
F_6 ( & V_7 -> V_7 , L_52 ) ;
goto V_125;
}
V_64 = F_89 ( V_7 , L_53 ) ;
if ( V_64 ) {
F_6 ( & V_7 -> V_7 , L_54 ) ;
goto V_125;
}
V_15 -> V_78 = F_90 ( V_7 , 0 , V_157 ) ;
if ( ! V_15 -> V_78 ) {
F_6 ( & V_7 -> V_7 , L_55 ) ;
goto V_158;
}
V_15 -> V_159 = F_90 ( V_7 , 1 , V_160 ) ;
if ( ! V_15 -> V_159 ) {
F_6 ( & V_7 -> V_7 , L_56 ) ;
goto V_161;
}
if ( V_162 ) {
F_38 ( 1 , V_15 -> V_78 + V_79 ) ;
V_156 = F_39 ( V_15 -> V_78 + V_79 ) ;
F_38 ( 0 , V_15 -> V_78 + V_79 ) ;
V_156 = F_39 ( V_15 -> V_78 + V_79 ) ;
}
V_156 = F_39 ( V_15 -> V_78 + V_163 ) ;
V_153 = ( V_156 & 0x0000FFFF ) ;
V_154 = ( ( V_156 & 0xFF000000 ) >> 24 ) ;
V_155 = ( ( V_156 & 0x00FF0000 ) >> 16 ) ;
V_15 -> V_74 = F_91 ( V_154 , V_155 ) ;
if ( V_15 -> V_74 > V_75 )
V_15 -> V_102 = V_62 ;
else
V_15 -> V_102 = V_164 ;
F_24 ( & V_7 -> V_7 , L_57 ,
V_154 , V_155 , V_153 ) ;
if ( V_153 < 37 && ( V_165 || V_166 ||
V_167 || V_168 ) ) {
F_6 ( & V_7 -> V_7 ,
L_58 ) ;
V_165 = V_166 = 0 ;
V_167 = V_168 = 0 ;
}
if ( V_15 -> V_74 >= V_169 ) {
V_15 -> V_97 = 1 ;
} else {
V_15 -> V_97 = 0 ;
F_38 ( 0xF0 , V_15 -> V_78 + V_110 ) ;
}
V_156 = F_39 ( V_15 -> V_78 + V_170 ) ;
V_15 -> V_95 = ( V_156 & 0x000000FF ) ;
F_92 ( V_7 , V_15 ) ;
F_93 ( & V_15 -> V_91 , F_47 , ( unsigned long ) V_15 ) ;
F_94 ( & V_15 -> V_143 ) ;
F_94 ( & V_15 -> V_138 ) ;
F_94 ( & V_15 -> V_60 ) ;
F_94 ( & V_15 -> V_33 ) ;
F_95 ( & V_15 -> V_35 ) ;
V_64 = F_96 ( V_7 -> V_87 , F_44 , V_171 ,
L_59 , V_15 ) ;
if ( V_64 ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_60 , V_7 -> V_87 ) ;
goto V_172;
}
F_38 ( 1 , V_15 -> V_78 + V_173 ) ;
if ( V_165 )
F_36 ( V_15 , 0 ) ;
if ( V_166 )
F_36 ( V_15 , 1 ) ;
if ( V_167 )
F_36 ( V_15 , 2 ) ;
if ( V_168 )
F_36 ( V_15 , 3 ) ;
V_64 = F_97 ( V_15 , & V_7 -> V_7 ) ;
if ( V_64 )
goto V_174;
return 0 ;
V_174:
F_38 ( 0 , V_15 -> V_78 + V_173 ) ;
F_98 ( V_7 -> V_87 , V_15 ) ;
F_99 ( & V_15 -> V_91 ) ;
V_172:
F_92 ( V_7 , NULL ) ;
F_100 ( V_7 , V_15 -> V_78 ) ;
V_161:
F_100 ( V_7 , V_15 -> V_159 ) ;
V_158:
F_101 ( V_7 ) ;
V_125:
F_102 ( V_15 ) ;
return V_64 ;
}
static int F_97 ( struct V_14 * V_15 , struct V_6 * V_175 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_95 ; V_43 ++ ) {
struct V_3 * V_4 ;
struct V_19 * V_20 ;
F_103 ( & V_15 -> V_139 [ V_43 ] ) ;
F_103 ( & V_15 -> V_61 [ V_43 ] ) ;
V_15 -> V_12 [ V_43 ] = F_104 ( L_59 , V_175 , & V_176 , - 1 , NULL ) ;
if ( ! V_15 -> V_12 [ V_43 ] ) {
F_105 ( & V_15 -> V_7 -> V_7 , L_61 , V_43 ) ;
F_106 ( V_15 ) ;
return - V_53 ;
}
if ( F_107 ( & V_15 -> V_12 [ V_43 ] -> V_13 , & V_177 ) )
F_105 ( & V_15 -> V_7 -> V_7 , L_62 , V_43 ) ;
if ( F_108 ( & V_15 -> V_12 [ V_43 ] -> V_13 . V_178 , & V_179 ) )
F_105 ( & V_15 -> V_7 -> V_7 , L_63 , V_43 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_64 , V_15 -> V_12 [ V_43 ] -> V_128 ) ;
V_15 -> V_12 [ V_43 ] -> V_180 . V_181 = 8 ;
V_15 -> V_12 [ V_43 ] -> V_180 . V_182 = 16 ;
V_15 -> V_12 [ V_43 ] -> V_16 = V_15 ;
V_15 -> V_12 [ V_43 ] -> V_183 = ( void * ) ( unsigned long ) V_43 ;
F_23 ( V_15 -> V_12 [ V_43 ] , V_56 ) ;
V_4 = F_5 ( sizeof( * V_20 ) , V_63 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_65 ) ;
continue;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( 0 ) ;
V_20 -> V_29 = F_8 ( 0 ) ;
V_20 -> type = F_8 ( V_109 ) ;
F_13 ( V_15 , V_43 , V_4 , NULL ) ;
}
return 0 ;
}
static void F_106 ( struct V_14 * V_15 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_95 ; V_43 ++ ) {
if ( V_15 -> V_12 [ V_43 ] ) {
struct V_3 * V_4 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_66 , V_15 -> V_12 [ V_43 ] -> V_128 ) ;
F_109 ( & V_15 -> V_12 [ V_43 ] -> V_13 . V_178 , & V_179 ) ;
F_110 ( V_15 -> V_12 [ V_43 ] ) ;
V_4 = V_15 -> V_98 [ V_43 ] ;
if ( V_4 ) {
F_49 ( V_15 -> V_7 , F_50 ( V_4 ) -> V_99 ,
V_100 , V_101 ) ;
F_111 ( V_4 ) ;
}
V_4 = V_15 -> V_145 [ V_43 ] ;
if ( V_4 ) {
F_49 ( V_15 -> V_7 , F_50 ( V_4 ) -> V_99 ,
V_4 -> V_39 , V_146 ) ;
F_111 ( V_4 ) ;
}
while ( ( V_4 = F_32 ( & V_15 -> V_139 [ V_43 ] ) ) )
F_111 ( V_4 ) ;
}
}
}
static void F_112 ( struct V_150 * V_7 )
{
struct V_14 * V_15 = F_113 ( V_7 ) ;
F_38 ( 0 , V_15 -> V_78 + V_173 ) ;
F_38 ( 1 , V_15 -> V_78 + V_79 ) ;
( void ) F_39 ( V_15 -> V_78 + V_79 ) ;
F_106 ( V_15 ) ;
F_98 ( V_7 -> V_87 , V_15 ) ;
F_99 ( & V_15 -> V_91 ) ;
F_38 ( 0 , V_15 -> V_78 + V_79 ) ;
( void ) F_39 ( V_15 -> V_78 + V_79 ) ;
F_100 ( V_7 , V_15 -> V_159 ) ;
F_100 ( V_7 , V_15 -> V_78 ) ;
F_101 ( V_7 ) ;
F_114 ( V_7 ) ;
F_92 ( V_7 , NULL ) ;
F_102 ( V_15 ) ;
}
static int T_7 F_115 ( void )
{
F_68 ( V_184 L_67 , V_185 ) ;
return F_116 ( & V_186 ) ;
}
static void T_8 F_117 ( void )
{
F_118 ( & V_186 ) ;
F_68 ( V_184 L_68 , V_185 ) ;
}
