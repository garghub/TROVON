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
char * V_45 , * V_46 , * V_47 , * V_48 ;
int V_49 , V_50 , V_51 , V_52 ;
if ( ! V_15 -> V_12 [ V_32 ] )
return - V_53 ;
V_45 = F_18 ( V_4 ) ;
if ( ! V_45 )
return - V_38 ;
V_52 = F_21 ( V_45 , 10 , & V_49 ) ;
if ( V_52 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_8 ) ;
return V_52 ;
}
if ( V_49 < 1 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_9 ,
V_49 ) ;
return - V_38 ;
}
V_45 = F_18 ( V_4 ) ;
if ( ! V_45 )
return - V_38 ;
if ( ! strcmp ( V_45 , L_6 ) ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_10 ,
V_32 ) ;
return 0 ;
}
V_52 = F_21 ( V_45 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
V_45 = F_18 ( V_4 ) ;
if ( ! V_45 )
return - V_38 ;
V_52 = F_21 ( V_45 , 10 , & V_50 ) ;
if ( V_52 )
return V_52 ;
V_46 = F_18 ( V_4 ) ;
if ( ! V_46 )
return - V_38 ;
if ( strcmp ( V_46 , L_11 ) ) {
F_23 ( V_15 -> V_12 [ V_32 ] , V_54 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_12 , V_32 , V_46 ) ;
return 0 ;
}
V_47 = F_18 ( V_4 ) ;
if ( ! V_47 )
return - V_38 ;
V_48 = F_18 ( V_4 ) ;
if ( ! V_48 )
return - V_38 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_13 ,
V_32 , V_46 , V_51 / 1000 , V_50 / 1000 ,
V_47 [ 0 ] ? L_14 : L_15 , V_47 , V_48 [ 0 ] ? L_16 : L_15 , V_48 ) ;
V_15 -> V_12 [ V_32 ] -> V_55 = V_51 / 424 ;
F_23 ( V_15 -> V_12 [ V_32 ] , V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_14 * V_15 , int V_32 , struct V_3 * V_4 )
{
struct V_17 * V_18 ;
unsigned long V_57 ;
int V_58 ;
int V_59 = 0 , V_52 ;
if ( V_4 -> V_39 < 7 )
return 0 ;
if ( V_4 -> V_40 [ 0 ] != 'L' || ! isdigit ( V_4 -> V_40 [ 1 ] ) ||
! isdigit ( V_4 -> V_40 [ 2 ] ) || ! isdigit ( V_4 -> V_40 [ 3 ] ) ||
! isdigit ( V_4 -> V_40 [ 4 ] ) || ! isdigit ( V_4 -> V_40 [ 5 ] ) ||
V_4 -> V_40 [ 6 ] != '\n' )
return 0 ;
V_52 = F_21 ( & V_4 -> V_40 [ 1 ] , 10 , & V_58 ) ;
if ( V_52 )
return V_52 ;
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
return sprintf ( V_10 , L_17 ) ;
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
int V_52 ;
V_52 = F_34 ( V_15 , F_9 ( V_12 ) , V_10 , V_41 ) ;
return V_52 ? : V_41 ;
}
static T_1 F_36 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_2 V_41 )
{
struct V_64 * V_65 = F_37 ( V_7 ) ;
struct V_66 * V_67 = F_4 ( V_9 , struct V_66 , V_9 ) ;
struct V_14 * V_15 = F_38 ( V_65 ) ;
T_3 V_68 ;
if ( V_41 != 1 && ( V_41 != 2 || V_10 [ 1 ] != '\n' ) )
return - V_69 ;
F_10 ( & V_15 -> V_33 ) ;
V_68 = F_39 ( V_15 -> V_70 + V_71 ) ;
if ( V_10 [ 0 ] == '1' ) {
V_68 |= 1 << V_67 -> V_72 ;
F_40 ( V_68 , V_15 -> V_70 + V_71 ) ;
} else if ( V_10 [ 0 ] == '0' ) {
V_68 &= ~ ( 1 << V_67 -> V_72 ) ;
F_40 ( V_68 , V_15 -> V_70 + V_71 ) ;
} else {
V_41 = - V_69 ;
}
F_12 ( & V_15 -> V_33 ) ;
return V_41 ;
}
static T_1 F_41 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_64 * V_65 = F_37 ( V_7 ) ;
struct V_66 * V_67 = F_4 ( V_9 , struct V_66 , V_9 ) ;
struct V_14 * V_15 = F_38 ( V_65 ) ;
T_3 V_68 ;
V_68 = F_39 ( V_15 -> V_70 + V_71 ) ;
V_68 = ( V_68 >> V_67 -> V_72 ) & 1 ;
return sprintf ( V_10 , L_20 , V_68 ) ;
}
static T_1 F_42 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_64 * V_65 = F_37 ( V_7 ) ;
struct V_66 * V_67 = F_4 ( V_9 , struct V_66 , V_9 ) ;
struct V_14 * V_15 = F_38 ( V_65 ) ;
T_3 V_68 ;
V_68 = F_39 ( V_15 -> V_70 + V_71 ) ;
switch ( V_67 -> V_72 ) {
case 0 :
V_68 = V_68 & 0x1F ;
break;
case 1 :
V_68 = ( V_68 >> 5 ) & 0x0F ;
break;
}
return sprintf ( V_10 , L_20 , V_68 ) ;
}
static int F_43 ( struct V_14 * V_15 , int V_73 )
{
const struct V_74 * V_75 ;
const char * V_76 ;
int V_77 = 0 ;
int V_78 = 0 ;
int V_72 ;
switch ( V_73 ) {
case 0 :
V_76 = L_21 ;
if ( V_15 -> V_79 )
V_77 = V_80 ;
else
V_77 = V_81 ;
break;
case 1 :
V_76 = L_22 ;
if ( V_15 -> V_79 )
V_77 = V_82 ;
else
V_77 = V_81 ;
break;
case 2 :
if ( V_15 -> V_83 > V_84 ) {
V_76 = L_23 ;
if ( V_15 -> V_79 )
V_77 = V_80 ;
else
V_77 = V_81 ;
} else {
F_24 ( & V_15 -> V_7 -> V_7 , L_24
L_25 ) ;
return - V_85 ;
}
break;
case 3 :
if ( V_15 -> V_83 > V_84 ) {
V_76 = L_22 ;
if ( V_15 -> V_79 )
V_77 = V_82 ;
else
V_77 = V_81 ;
} else {
F_24 ( & V_15 -> V_7 -> V_7 , L_24
L_25 ) ;
return - V_85 ;
}
break;
default:
return - V_53 ;
}
if ( F_44 ( & V_75 , V_76 , & V_15 -> V_7 -> V_7 ) )
return - V_86 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_26 ) ;
F_40 ( V_87 , V_15 -> V_70 + V_88 ) ;
V_78 = V_75 -> V_27 / V_77 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_27 , V_75 -> V_27 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_28 , V_78 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_29 ) ;
F_40 ( 1 , V_15 -> V_70 + V_89 ) ;
( void ) F_39 ( V_15 -> V_70 + V_89 ) ;
if( V_73 == 0 || V_73 == 2 )
F_24 ( & V_15 -> V_7 -> V_7 , L_30 ) ;
if( V_73 == 1 || V_73 == 3 )
F_24 ( & V_15 -> V_7 -> V_7 , L_31 ) ;
F_40 ( ( V_73 * 2 ) , V_15 -> V_70 + V_90 ) ;
F_40 ( 1 , V_15 -> V_70 + V_91 ) ;
F_45 ( V_15 -> V_92 , ! F_39 ( V_15 -> V_70 + V_93 ) ) ;
for ( V_72 = 0 ; V_72 < V_75 -> V_27 ; V_72 += V_77 ) {
int V_43 ;
F_40 ( 0 , V_15 -> V_70 + V_91 ) ;
F_40 ( ( ( V_73 * 2 ) + 1 ) , V_15 -> V_70 + V_90 ) ;
for( V_43 = 0 ; V_43 < V_77 ; V_43 += 4 ) {
T_3 V_94 ;
if ( V_15 -> V_79 )
V_94 = F_46 ( ( T_3 * ) ( V_75 -> V_40 + V_72 + V_43 ) ) ;
else
V_94 = * ( T_3 * ) ( V_75 -> V_40 + V_72 + V_43 ) ;
if( V_15 -> V_83 > V_84 )
F_40 ( V_94 , V_95 + V_43 ) ;
else
F_40 ( V_94 , F_47 ( V_15 , 3 ) + V_43 ) ;
}
F_40 ( V_72 / V_77 , V_15 -> V_70 + V_96 ) ;
F_40 ( 1 , V_15 -> V_70 + V_91 ) ;
F_45 ( V_15 -> V_92 , ! F_39 ( V_15 -> V_70 + V_93 ) ) ;
}
F_48 ( V_75 ) ;
F_40 ( 0 , V_15 -> V_70 + V_91 ) ;
F_40 ( 0 , V_15 -> V_70 + V_89 ) ;
F_40 ( 0 , V_15 -> V_70 + V_90 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_32 ) ;
return 0 ;
}
static T_4 F_49 ( int V_97 , void * V_98 )
{
struct V_14 * V_15 = V_98 ;
int V_99 = 1 ;
F_40 ( 0 , V_15 -> V_70 + V_100 ) ;
if ( V_15 -> V_12 [ 0 ] )
F_50 ( & V_15 -> V_101 ) ;
else
F_28 ( & V_15 -> V_92 ) ;
return F_51 ( V_99 ) ;
}
static void F_52 ( unsigned long V_102 )
{
struct V_14 * V_15 = ( void * ) V_102 ;
T_3 V_103 ;
T_3 V_104 = 0 ;
int V_32 ;
V_103 = F_53 ( V_15 ) ;
for ( V_32 = 0 ; V_32 < V_15 -> V_105 ; V_32 ++ ) {
if ( V_103 & ( 0x10 << V_32 ) ) {
struct V_19 V_106 , * V_20 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_27 ;
if ( V_15 -> V_107 ) {
V_4 = V_15 -> V_108 [ V_32 ] ;
V_15 -> V_108 [ V_32 ] = NULL ;
F_54 ( & V_15 -> V_7 -> V_7 , F_55 ( V_4 ) -> V_109 ,
V_110 , V_111 ) ;
V_20 = ( void * ) V_4 -> V_40 ;
V_27 = F_56 ( V_20 -> V_27 ) ;
F_7 ( V_4 , V_27 + sizeof( * V_20 ) ) ;
F_19 ( V_4 , sizeof( * V_20 ) ) ;
} else {
V_20 = & V_106 ;
V_104 |= 0x10 << V_32 ;
F_57 ( V_20 , F_47 ( V_15 , V_32 ) , sizeof( * V_20 ) ) ;
V_27 = F_56 ( V_20 -> V_27 ) ;
if ( V_27 > ( V_15 -> V_112 - sizeof( * V_20 ) ) ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_33 ) ;
continue;
}
V_4 = F_58 ( NULL , V_27 + 1 ) ;
if ( ! V_4 ) {
if ( F_59 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_34 ) ;
continue;
}
F_57 ( F_7 ( V_4 , V_27 ) ,
F_47 ( V_15 , V_32 ) + sizeof( * V_20 ) ,
V_27 ) ;
}
if ( V_113 ) {
F_24 ( & V_15 -> V_7 -> V_7 , L_35 , V_32 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_36 ,
V_27 , F_56 ( V_20 -> V_28 ) ,
F_56 ( V_20 -> V_29 ) ) ;
F_60 ( V_4 ) ;
}
switch ( F_56 ( V_20 -> type ) ) {
case V_114 :
V_2 = F_61 ( V_15 -> V_12 [ V_32 ] , F_56 ( V_20 -> V_28 ) ,
F_56 ( V_20 -> V_29 ) ) ;
if ( ! V_2 ) {
if ( F_59 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_37 ,
F_56 ( V_20 -> V_28 ) , F_56 ( V_20 -> V_29 ) ,
V_32 ) ;
F_2 ( V_4 ) ;
break;
}
F_62 ( V_2 , V_4 -> V_115 ) ;
V_2 -> V_116 ( V_2 , V_4 ) ;
F_63 ( & V_2 -> V_117 -> V_118 ) ;
break;
case V_119 :
if ( F_20 ( V_15 , V_32 , V_4 ) &&
F_59 () ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_38 , V_4 -> V_39 , V_32 ) ;
F_60 ( V_4 ) ;
}
F_2 ( V_4 ) ;
break;
case V_30 :
default:
if ( F_25 ( V_15 , V_32 , V_4 ) )
break;
F_31 ( & V_15 -> V_60 ) ;
if ( F_64 ( & V_15 -> V_61 [ V_32 ] ) > 10 ) {
if ( F_59 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_39 ,
V_32 ) ;
F_2 ( V_4 ) ;
} else
F_65 ( & V_15 -> V_61 [ V_32 ] , V_4 ) ;
F_33 ( & V_15 -> V_60 ) ;
break;
}
}
if ( V_15 -> V_107 && V_15 -> V_12 [ V_32 ] &&
! V_15 -> V_108 [ V_32 ] ) {
struct V_3 * V_4 = F_66 ( V_110 ) ;
if ( V_4 ) {
F_55 ( V_4 ) -> V_109 =
F_67 ( & V_15 -> V_7 -> V_7 , V_4 -> V_40 ,
V_110 , V_111 ) ;
F_40 ( F_55 ( V_4 ) -> V_109 ,
V_15 -> V_70 + F_68 ( V_32 ) ) ;
V_15 -> V_108 [ V_32 ] = V_4 ;
} else {
if ( F_59 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_40 ) ;
F_50 ( & V_15 -> V_101 ) ;
}
}
}
if ( V_104 )
F_40 ( V_104 , V_15 -> V_70 + V_120 ) ;
return;
}
static struct V_1 * F_61 ( struct V_11 * V_7 , short V_28 , int V_29 )
{
struct V_121 * V_122 ;
struct V_1 * V_2 = NULL ;
struct V_123 * V_124 ;
F_69 ( & V_125 ) ;
V_122 = & V_126 [ V_29 & ( V_127 - 1 ) ] ;
F_70 (s, head) {
V_2 = F_71 ( V_124 ) ;
if ( V_2 -> V_7 == V_7 && V_2 -> V_29 == V_29 &&
V_2 -> V_28 == V_28 && V_2 -> V_128 . V_129 . V_130 != V_131 &&
F_72 ( V_132 , & V_2 -> V_57 ) )
goto V_133;
}
V_2 = NULL ;
V_133:
F_73 ( & V_125 ) ;
return V_2 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
if ( V_2 -> V_128 . V_134 != V_135 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_41 ,
V_2 -> V_128 . V_134 ) ;
return - V_69 ;
}
V_4 = F_5 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_4 ) {
if ( F_59 () )
F_6 ( & V_15 -> V_7 -> V_7 , L_42 ) ;
return - V_24 ;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_136 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , NULL ) ;
F_75 ( V_137 , & V_2 -> V_57 ) ;
F_75 ( V_132 , & V_2 -> V_57 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
unsigned char V_32 = F_9 ( V_2 -> V_7 ) ;
struct V_3 * V_4 , * V_138 ;
struct V_19 * V_20 ;
F_31 ( & V_15 -> V_139 ) ;
F_77 (&card->tx_queue[port], skb, tmpskb) {
if ( F_55 ( V_4 ) -> V_2 == V_2 ) {
F_78 ( V_4 , & V_15 -> V_140 [ V_32 ] ) ;
F_1 ( V_2 , V_4 ) ;
}
}
F_33 ( & V_15 -> V_139 ) ;
V_4 = F_5 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_43 ) ;
return;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_141 ) ;
F_79 ( V_4 ) ;
F_13 ( V_15 , V_32 , V_4 , NULL ) ;
if ( ! F_14 ( V_15 -> V_36 , ! F_80 ( V_4 ) , 5 * V_37 ) )
F_6 ( & V_15 -> V_7 -> V_7 ,
L_44 , V_32 ) ;
F_81 ( V_4 ) ;
F_82 ( & V_15 -> V_101 ) ;
F_83 ( V_137 , & V_2 -> V_57 ) ;
return;
}
static int F_60 ( struct V_3 * V_10 )
{
int V_39 , V_43 ;
char V_142 [ 500 ] ;
char V_143 [ 10 ] ;
V_39 = V_10 -> V_39 ;
for ( V_43 = 0 ; V_43 < V_39 ; V_43 ++ ) {
if( V_43 % 8 == 0 )
sprintf ( V_142 , L_45 , V_43 ) ;
sprintf ( V_143 , L_46 , * ( V_10 -> V_40 + V_43 ) ) ;
strcat ( V_142 , V_143 ) ;
if( V_43 % 8 == 7 ) {
sprintf ( V_143 , L_47 ) ;
strcat ( V_142 , V_143 ) ;
F_84 ( V_144 L_48 , V_142 ) ;
}
}
if ( V_43 % 8 != 0 ) {
sprintf ( V_143 , L_47 ) ;
strcat ( V_142 , V_143 ) ;
F_84 ( V_144 L_48 , V_142 ) ;
}
F_84 ( V_144 L_47 ) ;
return 0 ;
}
static void F_13 ( struct V_14 * V_15 , int V_32 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_145 ;
unsigned long V_57 ;
F_55 ( V_4 ) -> V_2 = V_2 ;
F_26 ( & V_15 -> V_139 , V_57 ) ;
V_145 = F_64 ( & V_15 -> V_140 [ V_32 ] ) ;
F_65 ( & V_15 -> V_140 [ V_32 ] , V_4 ) ;
if ( ! V_145 )
V_15 -> V_146 |= ( 1 << V_32 ) ;
F_29 ( & V_15 -> V_139 , V_57 ) ;
if ( ! V_145 )
F_53 ( V_15 ) ;
}
static T_3 F_53 ( struct V_14 * V_15 )
{
T_3 V_147 , V_103 ;
T_3 V_148 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned char V_32 ;
unsigned long V_57 ;
F_26 ( & V_15 -> V_149 , V_57 ) ;
V_103 = F_39 ( V_15 -> V_70 + V_120 ) ;
V_147 = V_15 -> V_146 & ~ V_103 ;
for ( V_32 = 0 ; V_147 ; V_147 >>= 1 , V_32 ++ ) {
if ( V_147 & 1 ) {
struct V_3 * V_150 = V_15 -> V_151 [ V_32 ] ;
if ( V_150 ) {
F_54 ( & V_15 -> V_7 -> V_7 , F_55 ( V_150 ) -> V_109 ,
V_150 -> V_39 , V_152 ) ;
V_15 -> V_151 [ V_32 ] = NULL ;
}
F_31 ( & V_15 -> V_139 ) ;
V_4 = F_32 ( & V_15 -> V_140 [ V_32 ] ) ;
if ( ! V_4 )
V_15 -> V_146 &= ~ ( 1 << V_32 ) ;
F_33 ( & V_15 -> V_139 ) ;
if ( V_4 && ! V_15 -> V_107 ) {
F_85 ( F_86 ( V_15 , V_32 ) , V_4 -> V_40 , V_4 -> V_39 ) ;
V_148 |= 1 << V_32 ;
V_150 = V_4 ;
} else if ( V_4 && V_15 -> V_107 ) {
unsigned char * V_40 = V_4 -> V_40 ;
if ( ( unsigned long ) V_40 & V_15 -> V_153 ) {
V_40 = V_15 -> V_154 + ( V_62 * V_32 ) ;
memcpy ( V_40 , V_4 -> V_40 , V_4 -> V_39 ) ;
}
F_55 ( V_4 ) -> V_109 = F_67 ( & V_15 -> V_7 -> V_7 , V_40 ,
V_4 -> V_39 , V_152 ) ;
V_15 -> V_151 [ V_32 ] = V_4 ;
F_40 ( F_55 ( V_4 ) -> V_109 ,
V_15 -> V_70 + F_87 ( V_32 ) ) ;
}
if ( ! V_150 )
continue;
if ( V_113 ) {
struct V_19 * V_20 = ( void * ) V_150 -> V_40 ;
int V_27 = F_56 ( V_20 -> V_27 ) ;
F_19 ( V_150 , sizeof( * V_20 ) ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_49 ,
V_32 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_36 ,
V_27 , F_56 ( V_20 -> V_28 ) ,
F_56 ( V_20 -> V_29 ) ) ;
F_60 ( V_150 ) ;
}
V_2 = F_55 ( V_150 ) -> V_2 ;
if ( V_2 ) {
F_63 ( & V_2 -> V_117 -> V_155 ) ;
F_1 ( V_2 , V_150 ) ;
} else {
F_88 ( V_150 ) ;
F_28 ( & V_15 -> V_36 ) ;
}
}
}
if ( V_148 )
F_40 ( V_148 , V_15 -> V_70 + V_120 ) ;
F_29 ( & V_15 -> V_149 , V_57 ) ;
return V_103 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_14 * V_15 = V_2 -> V_7 -> V_16 ;
struct V_19 * V_20 ;
int V_156 ;
V_156 = V_4 -> V_39 ;
if ( V_156 > ( V_62 - sizeof( * V_20 ) ) ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_50 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
if ( ! F_90 ( V_4 , sizeof( * V_20 ) ) ) {
int V_157 = 0 ;
int V_42 ;
if ( F_91 ( V_4 ) < sizeof( * V_20 ) )
V_157 = sizeof( * V_20 ) - F_91 ( V_4 ) ;
V_42 = F_92 ( V_4 , V_157 , 0 , V_63 ) ;
if ( V_42 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_51 ) ;
F_1 ( V_2 , V_4 ) ;
return V_42 ;
}
}
V_20 = ( void * ) F_93 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( V_156 ) ;
V_20 -> V_28 = F_8 ( V_2 -> V_28 ) ;
V_20 -> V_29 = F_8 ( V_2 -> V_29 ) ;
V_20 -> type = F_8 ( V_114 ) ;
F_13 ( V_15 , F_9 ( V_2 -> V_7 ) , V_4 , V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_64 * V_7 , const struct V_158 * V_159 )
{
int V_52 ;
T_5 V_160 ;
T_6 V_161 , V_162 ;
T_3 V_68 ;
struct V_14 * V_15 ;
V_15 = F_95 ( sizeof( * V_15 ) , V_23 ) ;
if ( ! V_15 )
return - V_24 ;
V_15 -> V_7 = V_7 ;
F_96 ( & V_15 -> V_92 ) ;
F_96 ( & V_15 -> V_36 ) ;
V_52 = F_97 ( V_7 ) ;
if ( V_52 ) {
F_6 ( & V_7 -> V_7 , L_52 ) ;
goto V_133;
}
V_52 = F_98 ( & V_7 -> V_7 , F_99 ( 32 ) ) ;
if ( V_52 ) {
F_6 ( & V_7 -> V_7 , L_53 ) ;
goto V_133;
}
V_52 = F_100 ( V_7 , L_54 ) ;
if ( V_52 ) {
F_6 ( & V_7 -> V_7 , L_55 ) ;
goto V_133;
}
V_15 -> V_70 = F_101 ( V_7 , 0 , V_163 ) ;
if ( ! V_15 -> V_70 ) {
F_6 ( & V_7 -> V_7 , L_56 ) ;
V_52 = - V_24 ;
goto V_164;
}
V_15 -> V_165 = F_101 ( V_7 , 1 , V_166 ) ;
if ( ! V_15 -> V_165 ) {
F_6 ( & V_7 -> V_7 , L_57 ) ;
V_52 = - V_24 ;
goto V_167;
}
if ( V_168 ) {
F_40 ( 1 , V_15 -> V_70 + V_89 ) ;
V_68 = F_39 ( V_15 -> V_70 + V_89 ) ;
F_40 ( 0 , V_15 -> V_70 + V_89 ) ;
V_68 = F_39 ( V_15 -> V_70 + V_89 ) ;
}
V_68 = F_39 ( V_15 -> V_70 + V_169 ) ;
V_160 = ( V_68 & 0x0000FFFF ) ;
V_161 = ( ( V_68 & 0xFF000000 ) >> 24 ) ;
V_162 = ( ( V_68 & 0x00FF0000 ) >> 16 ) ;
V_15 -> V_83 = F_102 ( V_161 , V_162 ) ;
if ( V_15 -> V_83 > V_84 )
V_15 -> V_112 = V_62 ;
else
V_15 -> V_112 = V_170 ;
F_24 ( & V_7 -> V_7 , L_58 ,
V_161 , V_162 , V_160 ) ;
if ( V_160 < 37 && ( V_171 || V_172 ||
V_173 || V_174 ) ) {
F_6 ( & V_7 -> V_7 ,
L_59 ) ;
V_171 = V_172 = 0 ;
V_173 = V_174 = 0 ;
}
if ( V_160 < 39 )
V_15 -> V_79 = 1 ;
else
V_15 -> V_79 = 0 ;
V_68 = F_39 ( V_15 -> V_70 + V_175 ) ;
V_15 -> V_105 = ( V_68 & 0x000000FF ) ;
if ( V_15 -> V_83 >= V_176 ) {
F_103 ( V_7 ) ;
V_15 -> V_107 = 1 ;
if ( 1 ) {
V_15 -> V_153 = 3 ;
V_15 -> V_154 = F_104 ( V_15 -> V_105 * V_62 , V_23 ) ;
if ( ! V_15 -> V_154 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_60 ) ;
V_52 = - V_24 ;
goto V_177;
}
}
} else {
V_15 -> V_107 = 0 ;
F_40 ( 0xF0 , V_15 -> V_70 + V_120 ) ;
}
F_105 ( V_7 , V_15 ) ;
F_106 ( & V_15 -> V_101 , F_52 , ( unsigned long ) V_15 ) ;
F_107 ( & V_15 -> V_149 ) ;
F_107 ( & V_15 -> V_139 ) ;
F_107 ( & V_15 -> V_60 ) ;
F_107 ( & V_15 -> V_33 ) ;
F_108 ( & V_15 -> V_35 ) ;
V_52 = F_109 ( V_7 -> V_97 , F_49 , V_178 ,
L_61 , V_15 ) ;
if ( V_52 ) {
F_22 ( & V_15 -> V_7 -> V_7 , L_62 , V_7 -> V_97 ) ;
goto V_177;
}
F_40 ( 1 , V_15 -> V_70 + V_179 ) ;
if ( V_171 )
F_43 ( V_15 , 0 ) ;
if ( V_172 )
F_43 ( V_15 , 1 ) ;
if ( V_173 )
F_43 ( V_15 , 2 ) ;
if ( V_174 )
F_43 ( V_15 , 3 ) ;
V_52 = F_110 ( V_15 , & V_7 -> V_7 ) ;
if ( V_52 )
goto V_180;
if ( V_15 -> V_83 >= V_176 &&
F_111 ( & V_15 -> V_7 -> V_7 . V_181 , & V_182 ) )
F_112 ( & V_15 -> V_7 -> V_7 , L_63 ) ;
return 0 ;
V_180:
F_40 ( 0 , V_15 -> V_70 + V_179 ) ;
F_113 ( V_7 -> V_97 , V_15 ) ;
F_114 ( & V_15 -> V_101 ) ;
V_177:
F_115 ( V_15 -> V_154 ) ;
F_116 ( V_7 , V_15 -> V_165 ) ;
V_167:
F_116 ( V_7 , V_15 -> V_70 ) ;
V_164:
F_117 ( V_7 ) ;
V_133:
F_115 ( V_15 ) ;
return V_52 ;
}
static int F_110 ( struct V_14 * V_15 , struct V_6 * V_183 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_105 ; V_43 ++ ) {
struct V_3 * V_4 ;
struct V_19 * V_20 ;
F_118 ( & V_15 -> V_140 [ V_43 ] ) ;
F_118 ( & V_15 -> V_61 [ V_43 ] ) ;
V_15 -> V_12 [ V_43 ] = F_119 ( L_61 , V_183 , & V_184 , - 1 , NULL ) ;
if ( ! V_15 -> V_12 [ V_43 ] ) {
F_112 ( & V_15 -> V_7 -> V_7 , L_64 , V_43 ) ;
F_120 ( V_15 ) ;
return - V_53 ;
}
if ( F_121 ( & V_15 -> V_12 [ V_43 ] -> V_13 , & V_185 ) )
F_112 ( & V_15 -> V_7 -> V_7 , L_65 , V_43 ) ;
if ( F_111 ( & V_15 -> V_12 [ V_43 ] -> V_13 . V_181 , & V_186 ) )
F_112 ( & V_15 -> V_7 -> V_7 , L_66 , V_43 ) ;
F_24 ( & V_15 -> V_7 -> V_7 , L_67 , V_15 -> V_12 [ V_43 ] -> V_187 ) ;
V_15 -> V_12 [ V_43 ] -> V_188 . V_189 = 8 ;
V_15 -> V_12 [ V_43 ] -> V_188 . V_190 = 16 ;
V_15 -> V_12 [ V_43 ] -> V_16 = V_15 ;
V_15 -> V_12 [ V_43 ] -> V_191 = ( void * ) ( unsigned long ) V_43 ;
F_23 ( V_15 -> V_12 [ V_43 ] , V_56 ) ;
V_4 = F_5 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_4 ) {
F_6 ( & V_15 -> V_7 -> V_7 , L_68 ) ;
continue;
}
V_20 = ( void * ) F_7 ( V_4 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_8 ( 0 ) ;
V_20 -> V_28 = F_8 ( 0 ) ;
V_20 -> V_29 = F_8 ( 0 ) ;
V_20 -> type = F_8 ( V_119 ) ;
F_13 ( V_15 , V_43 , V_4 , NULL ) ;
}
return 0 ;
}
static void F_120 ( struct V_14 * V_15 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_105 ; V_43 ++ ) {
if ( V_15 -> V_12 [ V_43 ] ) {
struct V_3 * V_4 ;
F_24 ( & V_15 -> V_7 -> V_7 , L_69 , V_15 -> V_12 [ V_43 ] -> V_187 ) ;
F_122 ( & V_15 -> V_12 [ V_43 ] -> V_13 . V_181 , & V_186 ) ;
F_123 ( V_15 -> V_12 [ V_43 ] ) ;
V_4 = V_15 -> V_108 [ V_43 ] ;
if ( V_4 ) {
F_54 ( & V_15 -> V_7 -> V_7 , F_55 ( V_4 ) -> V_109 ,
V_110 , V_111 ) ;
F_81 ( V_4 ) ;
}
V_4 = V_15 -> V_151 [ V_43 ] ;
if ( V_4 ) {
F_54 ( & V_15 -> V_7 -> V_7 , F_55 ( V_4 ) -> V_109 ,
V_4 -> V_39 , V_152 ) ;
F_81 ( V_4 ) ;
}
while ( ( V_4 = F_32 ( & V_15 -> V_140 [ V_43 ] ) ) )
F_81 ( V_4 ) ;
}
}
}
static void F_124 ( struct V_64 * V_7 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
F_40 ( 0 , V_15 -> V_70 + V_179 ) ;
F_40 ( 1 , V_15 -> V_70 + V_89 ) ;
( void ) F_39 ( V_15 -> V_70 + V_89 ) ;
if ( V_15 -> V_83 >= V_176 )
F_122 ( & V_15 -> V_7 -> V_7 . V_181 , & V_182 ) ;
F_120 ( V_15 ) ;
F_113 ( V_7 -> V_97 , V_15 ) ;
F_114 ( & V_15 -> V_101 ) ;
F_115 ( V_15 -> V_154 ) ;
F_40 ( 0 , V_15 -> V_70 + V_89 ) ;
( void ) F_39 ( V_15 -> V_70 + V_89 ) ;
F_116 ( V_7 , V_15 -> V_165 ) ;
F_116 ( V_7 , V_15 -> V_70 ) ;
F_117 ( V_7 ) ;
F_125 ( V_7 ) ;
F_115 ( V_15 ) ;
}
static int T_7 F_126 ( void )
{
F_127 ( sizeof( struct V_192 ) > sizeof( ( (struct V_3 * ) 0 ) -> V_193 ) ) ;
F_84 ( V_194 L_70 , V_195 ) ;
return F_128 ( & V_196 ) ;
}
static void T_8 F_129 ( void )
{
F_130 ( & V_196 ) ;
F_84 ( V_194 L_71 , V_195 ) ;
}
