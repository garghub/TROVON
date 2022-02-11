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
F_16 ( V_4 ) ;
return V_39 ;
}
static int F_34 ( struct V_14 * V_15 , int V_7 , const char * V_10 , T_2 V_27 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 ;
if ( V_27 > ( V_62 - sizeof( * V_20 ) ) ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_17 ) ;
return 0 ;
}
V_4 = F_5 ( V_27 + sizeof( * V_20 ) , V_63 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_18 ) ;
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
static T_1 F_36 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_2 V_41 )
{
struct V_65 * V_66 = F_4 ( V_7 , struct V_65 , V_7 ) ;
struct V_67 * V_68 = F_4 ( V_9 , struct V_67 , V_9 ) ;
struct V_14 * V_15 = F_37 ( V_66 ) ;
T_3 V_69 ;
if ( V_41 != 1 && ( V_41 != 2 || V_10 [ 1 ] != '\n' ) )
return - V_70 ;
F_10 ( & V_15 -> V_33 ) ;
V_69 = F_38 ( V_15 -> V_71 + V_72 ) ;
if ( V_10 [ 0 ] == '1' ) {
V_69 |= 1 << V_68 -> V_73 ;
F_39 ( V_69 , V_15 -> V_71 + V_72 ) ;
} else if ( V_10 [ 0 ] == '0' ) {
V_69 &= ~ ( 1 << V_68 -> V_73 ) ;
F_39 ( V_69 , V_15 -> V_71 + V_72 ) ;
} else {
V_41 = - V_70 ;
}
F_12 ( & V_15 -> V_33 ) ;
return V_41 ;
}
static T_1 F_40 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_65 * V_66 = F_4 ( V_7 , struct V_65 , V_7 ) ;
struct V_67 * V_68 = F_4 ( V_9 , struct V_67 , V_9 ) ;
struct V_14 * V_15 = F_37 ( V_66 ) ;
T_3 V_69 ;
V_69 = F_38 ( V_15 -> V_71 + V_72 ) ;
V_69 = ( V_69 >> V_68 -> V_73 ) & 1 ;
return sprintf ( V_10 , L_19 , V_69 ) ;
}
static T_1 F_41 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_65 * V_66 = F_4 ( V_7 , struct V_65 , V_7 ) ;
struct V_67 * V_68 = F_4 ( V_9 , struct V_67 , V_9 ) ;
struct V_14 * V_15 = F_37 ( V_66 ) ;
T_3 V_69 ;
V_69 = F_38 ( V_15 -> V_71 + V_72 ) ;
switch ( V_68 -> V_73 ) {
case 0 :
V_69 = V_69 & 0x1F ;
break;
case 1 :
V_69 = ( V_69 >> 5 ) & 0x0F ;
break;
}
return sprintf ( V_10 , L_19 , V_69 ) ;
}
static int F_42 ( struct V_14 * V_15 , int V_74 )
{
const struct V_75 * V_76 ;
const char * V_77 ;
int V_78 = 0 ;
int V_79 = 0 ;
int V_73 ;
switch ( V_74 ) {
case 0 :
V_77 = L_20 ;
if ( V_15 -> V_80 )
V_78 = V_81 ;
else
V_78 = V_82 ;
break;
case 1 :
V_77 = L_21 ;
if ( V_15 -> V_80 )
V_78 = V_83 ;
else
V_78 = V_82 ;
break;
case 2 :
if ( V_15 -> V_84 > V_85 ) {
V_77 = L_22 ;
if ( V_15 -> V_80 )
V_78 = V_81 ;
else
V_78 = V_82 ;
} else {
F_24 ( & V_15 -> V_7 -> V_7 , L_23
L_24 ) ;
return - V_86 ;
}
break;
case 3 :
if ( V_15 -> V_84 > V_85 ) {
V_77 = L_21 ;
if ( V_15 -> V_80 )
V_78 = V_83 ;
else
V_78 = V_82 ;
} else {
F_24 ( & V_15 -> V_7 -> V_7 , L_23
L_24 ) ;
return - V_86 ;
}
break;
default:
return - V_53 ;
}
if ( F_43 ( & V_76 , V_77 , & V_15 -> V_7 -> V_7 ) )
return - V_87 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_25 ) ;
F_39 ( V_88 , V_15 -> V_71 + V_89 ) ;
V_79 = V_76 -> V_27 / V_78 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_26 , V_76 -> V_27 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_27 , V_79 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_28 ) ;
F_39 ( 1 , V_15 -> V_71 + V_90 ) ;
( void ) F_38 ( V_15 -> V_71 + V_90 ) ;
if( V_74 == 0 || V_74 == 2 )
F_24 ( & V_15 -> V_7 -> V_7 , L_29 ) ;
if( V_74 == 1 || V_74 == 3 )
F_24 ( & V_15 -> V_7 -> V_7 , L_30 ) ;
F_39 ( ( V_74 * 2 ) , V_15 -> V_71 + V_91 ) ;
F_39 ( 1 , V_15 -> V_71 + V_92 ) ;
F_44 ( V_15 -> V_93 , ! F_38 ( V_15 -> V_71 + V_94 ) ) ;
for ( V_73 = 0 ; V_73 < V_76 -> V_27 ; V_73 += V_78 ) {
int V_43 ;
F_39 ( 0 , V_15 -> V_71 + V_92 ) ;
F_39 ( ( ( V_74 * 2 ) + 1 ) , V_15 -> V_71 + V_91 ) ;
for( V_43 = 0 ; V_43 < V_78 ; V_43 += 4 ) {
T_3 V_95 ;
if ( V_15 -> V_80 )
V_95 = F_45 ( ( T_3 * ) ( V_76 -> V_40 + V_73 + V_43 ) ) ;
else
V_95 = * ( T_3 * ) ( V_76 -> V_40 + V_73 + V_43 ) ;
if( V_15 -> V_84 > V_85 )
F_39 ( V_95 , V_96 + V_43 ) ;
else
F_39 ( V_95 , F_46 ( V_15 , 3 ) + V_43 ) ;
}
F_39 ( V_73 / V_78 , V_15 -> V_71 + V_97 ) ;
F_39 ( 1 , V_15 -> V_71 + V_92 ) ;
F_44 ( V_15 -> V_93 , ! F_38 ( V_15 -> V_71 + V_94 ) ) ;
}
F_47 ( V_76 ) ;
F_39 ( 0 , V_15 -> V_71 + V_92 ) ;
F_39 ( 0 , V_15 -> V_71 + V_90 ) ;
F_39 ( 0 , V_15 -> V_71 + V_91 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_31 ) ;
return 0 ;
}
static T_4 F_48 ( int V_98 , void * V_99 )
{
struct V_14 * V_15 = V_99 ;
int V_100 = 1 ;
F_39 ( 0 , V_15 -> V_71 + V_101 ) ;
if ( V_15 -> V_12 [ 0 ] )
F_49 ( & V_15 -> V_102 ) ;
else
F_28 ( & V_15 -> V_93 ) ;
return F_50 ( V_100 ) ;
}
static void F_51 ( unsigned long V_103 )
{
struct V_14 * V_15 = ( void * ) V_103 ;
T_3 V_104 ;
T_3 V_105 = 0 ;
int V_32 ;
V_104 = F_52 ( V_15 ) ;
for ( V_32 = 0 ; V_32 < V_15 -> V_106 ; V_32 ++ ) {
if ( V_104 & ( 0x10 << V_32 ) ) {
struct V_19 V_107 , * V_20 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_27 ;
if ( V_15 -> V_108 ) {
V_4 = V_15 -> V_109 [ V_32 ] ;
V_15 -> V_109 [ V_32 ] = NULL ;
F_53 ( & V_15 -> V_7 -> V_7 , F_54 ( V_4 ) -> V_110 ,
V_111 , V_112 ) ;
V_20 = ( void * ) V_4 -> V_40 ;
V_27 = F_55 ( V_20 -> V_27 ) ;
F_7 ( V_4 , V_27 + sizeof( * V_20 ) ) ;
F_19 ( V_4 , sizeof( * V_20 ) ) ;
} else {
V_20 = & V_107 ;
V_105 |= 0x10 << V_32 ;
F_56 ( V_20 , F_46 ( V_15 , V_32 ) , sizeof( * V_20 ) ) ;
V_27 = F_55 ( V_20 -> V_27 ) ;
if ( V_27 > ( V_15 -> V_113 - sizeof( * V_20 ) ) ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_32 ) ;
continue;
}
V_4 = F_5 ( V_27 + 1 , V_63 ) ;
if ( ! V_4 ) {
if ( F_57 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_33 ) ;
continue;
}
F_56 ( F_7 ( V_4 , V_27 ) ,
F_46 ( V_15 , V_32 ) + sizeof( * V_20 ) ,
V_27 ) ;
}
if ( V_114 ) {
F_24 ( & V_15 -> V_7 -> V_7 , L_34 , V_32 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_35 ,
V_27 , F_55 ( V_20 -> V_28 ) ,
F_55 ( V_20 -> V_29 ) ) ;
F_58 ( V_4 ) ;
}
switch ( F_55 ( V_20 -> type ) ) {
case V_115 :
V_2 = F_59 ( V_15 -> V_12 [ V_32 ] , F_55 ( V_20 -> V_28 ) ,
F_55 ( V_20 -> V_29 ) ) ;
if ( ! V_2 ) {
if ( F_57 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_36 ,
F_55 ( V_20 -> V_28 ) , F_55 ( V_20 -> V_29 ) ,
V_32 ) ;
F_2 ( V_4 ) ;
break;
}
F_60 ( V_2 , V_4 -> V_116 ) ;
V_2 -> V_117 ( V_2 , V_4 ) ;
F_61 ( & V_2 -> V_118 -> V_119 ) ;
break;
case V_120 :
if ( F_20 ( V_15 , V_32 , V_4 ) &&
F_57 () ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_37 , V_4 -> V_39 , V_32 ) ;
F_58 ( V_4 ) ;
}
F_2 ( V_4 ) ;
break;
case V_30 :
default:
if ( F_25 ( V_15 , V_32 , V_4 ) )
break;
F_31 ( & V_15 -> V_60 ) ;
if ( F_62 ( & V_15 -> V_61 [ V_32 ] ) > 10 ) {
if ( F_57 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_38 ,
V_32 ) ;
F_2 ( V_4 ) ;
} else
F_63 ( & V_15 -> V_61 [ V_32 ] , V_4 ) ;
F_33 ( & V_15 -> V_60 ) ;
break;
}
}
if ( V_15 -> V_108 && V_15 -> V_12 [ V_32 ] &&
! V_15 -> V_109 [ V_32 ] ) {
struct V_3 * V_4 = F_5 ( V_111 , V_63 ) ;
if ( V_4 ) {
F_54 ( V_4 ) -> V_110 =
F_64 ( & V_15 -> V_7 -> V_7 , V_4 -> V_40 ,
V_111 , V_112 ) ;
F_39 ( F_54 ( V_4 ) -> V_110 ,
V_15 -> V_71 + F_65 ( V_32 ) ) ;
V_15 -> V_109 [ V_32 ] = V_4 ;
} else {
if ( F_57 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_39 ) ;
F_49 ( & V_15 -> V_102 ) ;
}
}
}
if ( V_105 )
F_39 ( V_105 , V_15 -> V_71 + V_121 ) ;
return;
}
static struct V_1 * F_59 ( struct V_11 * V_7 , short V_28 , int V_29 )
{
struct V_122 * V_123 ;
struct V_1 * V_2 = NULL ;
struct V_124 * V_125 ;
F_66 ( & V_126 ) ;
V_123 = & V_127 [ V_29 & ( V_128 - 1 ) ] ;
F_67 (s, head) {
V_2 = F_68 ( V_125 ) ;
if ( V_2 -> V_7 == V_7 && V_2 -> V_29 == V_29 &&
V_2 -> V_28 == V_28 && V_2 -> V_129 . V_130 . V_131 != V_132 &&
F_69 ( V_133 , & V_2 -> V_57 ) )
goto V_134;
}
V_2 = NULL ;
V_134:
F_70 ( & V_126 ) ;
return V_2 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
if ( V_2 -> V_129 . V_135 != V_136 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_40 ,
V_2 -> V_129 . V_135 ) ;
return - V_70 ;
}
V_4 = F_5 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_4 ) {
if ( F_57 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_41 ) ;
return - V_24 ;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_137 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , NULL ) ;
F_72 ( V_138 , & V_2 -> V_57 ) ;
F_72 ( V_133 , & V_2 -> V_57 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
unsigned char V_32 = F_9 ( V_2 -> V_7 ) ;
struct V_3 * V_4 , * V_139 ;
struct V_19 * V_20 ;
F_31 ( & V_15 -> V_140 ) ;
F_74 (&card->tx_queue[port], skb, tmpskb) {
if ( F_54 ( V_4 ) -> V_2 == V_2 ) {
F_75 ( V_4 , & V_15 -> V_141 [ V_32 ] ) ;
F_1 ( V_2 , V_4 ) ;
}
}
F_33 ( & V_15 -> V_140 ) ;
V_4 = F_5 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_42 ) ;
return;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_142 ) ;
F_76 ( V_4 ) ;
F_13 ( V_15 , V_32 , V_4 , NULL ) ;
if ( ! F_14 ( V_15 -> V_36 , ! F_77 ( V_4 ) , 5 * V_37 ) )
F_6 ( & V_15 -> V_7 -> V_7 ,
L_43 , V_32 ) ;
F_78 ( V_4 ) ;
F_79 ( & V_15 -> V_102 ) ;
F_80 ( V_138 , & V_2 -> V_57 ) ;
return;
}
static int F_58 ( struct V_3 * V_10 )
{
int V_39 , V_43 ;
char V_143 [ 500 ] ;
char V_144 [ 10 ] ;
V_39 = V_10 -> V_39 ;
for ( V_43 = 0 ; V_43 < V_39 ; V_43 ++ ) {
if( V_43 % 8 == 0 )
sprintf ( V_143 , L_44 , V_43 ) ;
sprintf ( V_144 , L_45 , * ( V_10 -> V_40 + V_43 ) ) ;
strcat ( V_143 , V_144 ) ;
if( V_43 % 8 == 7 ) {
sprintf ( V_144 , L_46 ) ;
strcat ( V_143 , V_144 ) ;
F_81 ( V_145 L_47 , V_143 ) ;
}
}
if ( V_43 % 8 != 0 ) {
sprintf ( V_144 , L_46 ) ;
strcat ( V_143 , V_144 ) ;
F_81 ( V_145 L_47 , V_143 ) ;
}
F_81 ( V_145 L_46 ) ;
return 0 ;
}
static void F_13 ( struct V_14 * V_15 , int V_32 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_146 ;
unsigned long V_57 ;
F_54 ( V_4 ) -> V_2 = V_2 ;
F_26 ( & V_15 -> V_140 , V_57 ) ;
V_146 = F_62 ( & V_15 -> V_141 [ V_32 ] ) ;
F_63 ( & V_15 -> V_141 [ V_32 ] , V_4 ) ;
if ( ! V_146 )
V_15 -> V_147 |= ( 1 << V_32 ) ;
F_29 ( & V_15 -> V_140 , V_57 ) ;
if ( ! V_146 )
F_52 ( V_15 ) ;
}
static T_3 F_52 ( struct V_14 * V_15 )
{
T_3 V_148 , V_104 ;
T_3 V_149 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned char V_32 ;
unsigned long V_57 ;
F_26 ( & V_15 -> V_150 , V_57 ) ;
V_104 = F_38 ( V_15 -> V_71 + V_121 ) ;
V_148 = V_15 -> V_147 & ~ V_104 ;
for ( V_32 = 0 ; V_148 ; V_148 >>= 1 , V_32 ++ ) {
if ( V_148 & 1 ) {
struct V_3 * V_151 = V_15 -> V_152 [ V_32 ] ;
if ( V_151 ) {
F_53 ( & V_15 -> V_7 -> V_7 , F_54 ( V_151 ) -> V_110 ,
V_151 -> V_39 , V_153 ) ;
V_15 -> V_152 [ V_32 ] = NULL ;
}
F_31 ( & V_15 -> V_140 ) ;
V_4 = F_32 ( & V_15 -> V_141 [ V_32 ] ) ;
if ( ! V_4 )
V_15 -> V_147 &= ~ ( 1 << V_32 ) ;
F_33 ( & V_15 -> V_140 ) ;
if ( V_4 && ! V_15 -> V_108 ) {
F_82 ( F_83 ( V_15 , V_32 ) , V_4 -> V_40 , V_4 -> V_39 ) ;
V_149 |= 1 << V_32 ;
V_151 = V_4 ;
} else if ( V_4 && V_15 -> V_108 ) {
unsigned char * V_40 = V_4 -> V_40 ;
if ( ( unsigned long ) V_40 & V_15 -> V_154 ) {
V_40 = V_15 -> V_155 + ( V_62 * V_32 ) ;
memcpy ( V_40 , V_4 -> V_40 , V_4 -> V_39 ) ;
}
F_54 ( V_4 ) -> V_110 = F_64 ( & V_15 -> V_7 -> V_7 , V_40 ,
V_4 -> V_39 , V_153 ) ;
V_15 -> V_152 [ V_32 ] = V_4 ;
F_39 ( F_54 ( V_4 ) -> V_110 ,
V_15 -> V_71 + F_84 ( V_32 ) ) ;
}
if ( ! V_151 )
continue;
if ( V_114 ) {
struct V_19 * V_20 = ( void * ) V_151 -> V_40 ;
int V_27 = F_55 ( V_20 -> V_27 ) ;
F_19 ( V_151 , sizeof( * V_20 ) ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_48 ,
V_32 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_35 ,
V_27 , F_55 ( V_20 -> V_28 ) ,
F_55 ( V_20 -> V_29 ) ) ;
F_58 ( V_151 ) ;
}
V_2 = F_54 ( V_151 ) -> V_2 ;
if ( V_2 ) {
F_61 ( & V_2 -> V_118 -> V_156 ) ;
F_1 ( V_2 , V_151 ) ;
} else {
F_85 ( V_151 ) ;
F_28 ( & V_15 -> V_36 ) ;
}
}
}
if ( V_149 )
F_39 ( V_149 , V_15 -> V_71 + V_121 ) ;
F_29 ( & V_15 -> V_150 , V_57 ) ;
return V_104 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_19 * V_20 ;
int V_157 ;
V_157 = V_4 -> V_39 ;
if ( V_157 > ( V_62 - sizeof( * V_20 ) ) ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_49 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
if ( ! F_87 ( V_4 , sizeof( * V_20 ) ) ) {
int V_158 = 0 ;
int V_42 ;
if ( F_88 ( V_4 ) < sizeof( * V_20 ) )
V_158 = sizeof( * V_20 ) - F_88 ( V_4 ) ;
V_42 = F_89 ( V_4 , V_158 , 0 , V_63 ) ;
if ( V_42 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_50 ) ;
F_1 ( V_2 , V_4 ) ;
return V_42 ;
}
}
V_20 = ( void * ) F_90 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( V_157 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_115 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_65 * V_7 , const struct V_159 * V_160 )
{
int V_64 ;
T_5 V_161 ;
T_6 V_162 , V_163 ;
T_3 V_69 ;
struct V_14 * V_15 ;
V_15 = F_92 ( sizeof( * V_15 ) , V_23 ) ;
if ( ! V_15 )
return - V_24 ;
V_15 -> V_7 = V_7 ;
F_93 ( & V_15 -> V_93 ) ;
F_93 ( & V_15 -> V_36 ) ;
V_64 = F_94 ( V_7 ) ;
if ( V_64 ) {
F_6 ( & V_7 -> V_7 , L_51 ) ;
goto V_134;
}
V_64 = F_95 ( & V_7 -> V_7 , F_96 ( 32 ) ) ;
if ( V_64 ) {
F_6 ( & V_7 -> V_7 , L_52 ) ;
goto V_134;
}
V_64 = F_97 ( V_7 , L_53 ) ;
if ( V_64 ) {
F_6 ( & V_7 -> V_7 , L_54 ) ;
goto V_134;
}
V_15 -> V_71 = F_98 ( V_7 , 0 , V_164 ) ;
if ( ! V_15 -> V_71 ) {
F_6 ( & V_7 -> V_7 , L_55 ) ;
V_64 = - V_24 ;
goto V_165;
}
V_15 -> V_166 = F_98 ( V_7 , 1 , V_167 ) ;
if ( ! V_15 -> V_166 ) {
F_6 ( & V_7 -> V_7 , L_56 ) ;
V_64 = - V_24 ;
goto V_168;
}
if ( V_169 ) {
F_39 ( 1 , V_15 -> V_71 + V_90 ) ;
V_69 = F_38 ( V_15 -> V_71 + V_90 ) ;
F_39 ( 0 , V_15 -> V_71 + V_90 ) ;
V_69 = F_38 ( V_15 -> V_71 + V_90 ) ;
}
V_69 = F_38 ( V_15 -> V_71 + V_170 ) ;
V_161 = ( V_69 & 0x0000FFFF ) ;
V_162 = ( ( V_69 & 0xFF000000 ) >> 24 ) ;
V_163 = ( ( V_69 & 0x00FF0000 ) >> 16 ) ;
V_15 -> V_84 = F_99 ( V_162 , V_163 ) ;
if ( V_15 -> V_84 > V_85 )
V_15 -> V_113 = V_62 ;
else
V_15 -> V_113 = V_171 ;
F_24 ( & V_7 -> V_7 , L_57 ,
V_162 , V_163 , V_161 ) ;
if ( V_161 < 37 && ( V_172 || V_173 ||
V_174 || V_175 ) ) {
F_6 ( & V_7 -> V_7 ,
L_58 ) ;
V_172 = V_173 = 0 ;
V_174 = V_175 = 0 ;
}
if ( V_161 < 39 )
V_15 -> V_80 = 1 ;
else
V_15 -> V_80 = 0 ;
V_69 = F_38 ( V_15 -> V_71 + V_176 ) ;
V_15 -> V_106 = ( V_69 & 0x000000FF ) ;
if ( V_15 -> V_84 >= V_177 ) {
F_100 ( V_7 ) ;
V_15 -> V_108 = 1 ;
if ( 1 ) {
V_15 -> V_154 = 3 ;
V_15 -> V_155 = F_101 ( V_15 -> V_106 * V_62 , V_23 ) ;
if ( ! V_15 -> V_155 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_59 ) ;
V_64 = - V_24 ;
goto V_178;
}
}
} else {
V_15 -> V_108 = 0 ;
F_39 ( 0xF0 , V_15 -> V_71 + V_121 ) ;
}
F_102 ( V_7 , V_15 ) ;
F_103 ( & V_15 -> V_102 , F_51 , ( unsigned long ) V_15 ) ;
F_104 ( & V_15 -> V_150 ) ;
F_104 ( & V_15 -> V_140 ) ;
F_104 ( & V_15 -> V_60 ) ;
F_104 ( & V_15 -> V_33 ) ;
F_105 ( & V_15 -> V_35 ) ;
V_64 = F_106 ( V_7 -> V_98 , F_48 , V_179 ,
L_60 , V_15 ) ;
if ( V_64 ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_61 , V_7 -> V_98 ) ;
goto V_178;
}
F_39 ( 1 , V_15 -> V_71 + V_180 ) ;
if ( V_172 )
F_42 ( V_15 , 0 ) ;
if ( V_173 )
F_42 ( V_15 , 1 ) ;
if ( V_174 )
F_42 ( V_15 , 2 ) ;
if ( V_175 )
F_42 ( V_15 , 3 ) ;
V_64 = F_107 ( V_15 , & V_7 -> V_7 ) ;
if ( V_64 )
goto V_181;
if ( V_15 -> V_84 >= V_177 &&
F_108 ( & V_15 -> V_7 -> V_7 . V_182 , & V_183 ) )
F_109 ( & V_15 -> V_7 -> V_7 , L_62 ) ;
return 0 ;
V_181:
F_39 ( 0 , V_15 -> V_71 + V_180 ) ;
F_110 ( V_7 -> V_98 , V_15 ) ;
F_111 ( & V_15 -> V_102 ) ;
V_178:
F_112 ( V_15 -> V_155 ) ;
F_113 ( V_7 , V_15 -> V_166 ) ;
V_168:
F_113 ( V_7 , V_15 -> V_71 ) ;
V_165:
F_114 ( V_7 ) ;
V_134:
F_112 ( V_15 ) ;
return V_64 ;
}
static int F_107 ( struct V_14 * V_15 , struct V_6 * V_184 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_106 ; V_43 ++ ) {
struct V_3 * V_4 ;
struct V_19 * V_20 ;
F_115 ( & V_15 -> V_141 [ V_43 ] ) ;
F_115 ( & V_15 -> V_61 [ V_43 ] ) ;
V_15 -> V_12 [ V_43 ] = F_116 ( L_60 , V_184 , & V_185 , - 1 , NULL ) ;
if ( ! V_15 -> V_12 [ V_43 ] ) {
F_109 ( & V_15 -> V_7 -> V_7 , L_63 , V_43 ) ;
F_117 ( V_15 ) ;
return - V_53 ;
}
if ( F_118 ( & V_15 -> V_12 [ V_43 ] -> V_13 , & V_186 ) )
F_109 ( & V_15 -> V_7 -> V_7 , L_64 , V_43 ) ;
if ( F_108 ( & V_15 -> V_12 [ V_43 ] -> V_13 . V_182 , & V_187 ) )
F_109 ( & V_15 -> V_7 -> V_7 , L_65 , V_43 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_66 , V_15 -> V_12 [ V_43 ] -> V_188 ) ;
V_15 -> V_12 [ V_43 ] -> V_189 . V_190 = 8 ;
V_15 -> V_12 [ V_43 ] -> V_189 . V_191 = 16 ;
V_15 -> V_12 [ V_43 ] -> V_16 = V_15 ;
V_15 -> V_12 [ V_43 ] -> V_192 = ( void * ) ( unsigned long ) V_43 ;
F_23 ( V_15 -> V_12 [ V_43 ] , V_56 ) ;
V_4 = F_5 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_67 ) ;
continue;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( 0 ) ;
V_20 -> V_29 = F_8 ( 0 ) ;
V_20 -> type = F_8 ( V_120 ) ;
F_13 ( V_15 , V_43 , V_4 , NULL ) ;
}
return 0 ;
}
static void F_117 ( struct V_14 * V_15 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_106 ; V_43 ++ ) {
if ( V_15 -> V_12 [ V_43 ] ) {
struct V_3 * V_4 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_68 , V_15 -> V_12 [ V_43 ] -> V_188 ) ;
F_119 ( & V_15 -> V_12 [ V_43 ] -> V_13 . V_182 , & V_187 ) ;
F_120 ( V_15 -> V_12 [ V_43 ] ) ;
V_4 = V_15 -> V_109 [ V_43 ] ;
if ( V_4 ) {
F_53 ( & V_15 -> V_7 -> V_7 , F_54 ( V_4 ) -> V_110 ,
V_111 , V_112 ) ;
F_78 ( V_4 ) ;
}
V_4 = V_15 -> V_152 [ V_43 ] ;
if ( V_4 ) {
F_53 ( & V_15 -> V_7 -> V_7 , F_54 ( V_4 ) -> V_110 ,
V_4 -> V_39 , V_153 ) ;
F_78 ( V_4 ) ;
}
while ( ( V_4 = F_32 ( & V_15 -> V_141 [ V_43 ] ) ) )
F_78 ( V_4 ) ;
}
}
}
static void F_121 ( struct V_65 * V_7 )
{
struct V_14 * V_15 = F_37 ( V_7 ) ;
F_39 ( 0 , V_15 -> V_71 + V_180 ) ;
F_39 ( 1 , V_15 -> V_71 + V_90 ) ;
( void ) F_38 ( V_15 -> V_71 + V_90 ) ;
if ( V_15 -> V_84 >= V_177 )
F_119 ( & V_15 -> V_7 -> V_7 . V_182 , & V_183 ) ;
F_117 ( V_15 ) ;
F_110 ( V_7 -> V_98 , V_15 ) ;
F_111 ( & V_15 -> V_102 ) ;
F_112 ( V_15 -> V_155 ) ;
F_39 ( 0 , V_15 -> V_71 + V_90 ) ;
( void ) F_38 ( V_15 -> V_71 + V_90 ) ;
F_113 ( V_7 , V_15 -> V_166 ) ;
F_113 ( V_7 , V_15 -> V_71 ) ;
F_114 ( V_7 ) ;
F_122 ( V_7 ) ;
F_112 ( V_15 ) ;
}
static int T_7 F_123 ( void )
{
F_124 ( sizeof( struct V_193 ) > sizeof( ( (struct V_3 * ) 0 ) -> V_194 ) ) ;
F_81 ( V_195 L_69 , V_196 ) ;
return F_125 ( & V_197 ) ;
}
static void T_8 F_126 ( void )
{
F_127 ( & V_197 ) ;
F_81 ( V_195 L_70 , V_196 ) ;
}
