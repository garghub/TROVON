static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 ,
void * V_6 )
{
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
F_3 ( V_5 -> V_9 == NULL ) ;
if ( V_10 & V_11 )
F_4 ( V_7 -> V_12 ,
L_1 ,
V_5 -> V_9 ) ;
F_5 ( V_7 -> V_12 -> V_13 , 0 , 0 ,
( ( V_14 ) ( V_5 -> V_9 ) - sizeof( struct V_15 ) ) , 0 , 0 ,
0 ) ;
V_5 -> V_9 = NULL ;
}
static int
F_6 ( struct V_16 * V_8 ,
struct V_3 * V_3 ,
T_1 type ,
T_2 V_17 ,
T_2 V_18 ,
void * V_6 )
{
struct V_7 * V_7 = F_2 ( V_8 ) ;
unsigned long V_19 ;
F_3 ( V_17 != 0 ) ;
F_7 ( & V_7 -> V_20 [ V_17 ] , V_19 ) ;
F_8 ( & V_7 -> V_2 [ V_17 ] ,
V_3 ,
V_18 ,
F_1 ,
NULL ) ;
F_9 ( & V_7 -> V_20 [ V_17 ] , V_19 ) ;
return 0 ;
}
int
F_10 ( struct V_7 * V_7 , int V_21 )
{
unsigned int V_22 = 0 ;
unsigned int V_23 ;
V_7 -> V_24 . V_25 . V_26 = V_27 ;
for ( V_23 = 0 ; V_23 < V_7 -> V_28 ; V_23 ++ ) {
V_22 += F_11 ( & V_7 -> V_29 [ V_23 ] ,
V_21 ,
F_6 ,
NULL ) ;
}
return V_22 ;
}
void
F_12 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_30 * V_31 = V_5 -> V_9 ;
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_15 * V_32 = NULL ;
unsigned long V_19 ;
F_13 ( V_7 -> V_33 , V_5 -> V_34 , V_5 -> V_35 , V_36 ) ;
V_32 = F_14 ( V_31 ) ;
F_7 ( & V_7 -> V_37 , V_19 ) ;
if ( F_15 ( & V_32 -> V_38 ) ) {
F_9 ( & V_7 -> V_37 , V_19 ) ;
goto V_39;
}
F_3 ( V_32 -> V_38 . V_40 == NULL ) ;
F_16 ( & V_32 -> V_38 ) ;
F_9 ( & V_7 -> V_37 , V_19 ) ;
if ( V_32 -> V_41 ) {
F_17 ( V_7 , V_32 ) ;
F_18 ( ( void * ) V_32 -> V_41 ) ;
V_32 -> V_41 = 0 ;
}
F_19 ( V_7 , V_32 ) ;
F_4 ( V_7 -> V_12 , L_2 ) ;
V_39:
return;
}
static int
F_20 ( struct V_7 * V_7 )
{
F_21 ( V_42 > 1 ) ;
return 0 ;
}
static int
F_22 ( struct V_7 * V_7 , int V_17 , int V_43 )
{
int V_44 = V_7 -> V_45 . V_46 ;
if ( V_17 > 0 ) {
F_4 ( V_7 -> V_12 , L_3 ) ;
F_3 ( V_17 > 0 ) ;
return - 1 ;
}
V_44 -= F_23 ( & V_7 -> V_24 . V_47 . V_48 ) ;
return ( ( V_43 == V_49 ) ? V_44 : V_44 - 1 ) ;
}
int
F_24 ( struct V_7 * V_7 , void * V_9 , T_2 V_35 )
{
T_3 V_50 = 0 ;
unsigned long V_19 ;
struct V_51 * V_52 = & V_7 -> V_24 . V_47 ;
struct V_30 * V_31 = (struct V_30 * ) V_9 ;
long V_53 ;
long V_54 = 0 ;
int V_17 = 0 ;
F_25 ( V_55 , V_9 , V_35 ) ;
V_50 = F_26 ( V_7 -> V_33 , V_9 , V_35 , V_36 ) ;
if ( F_27 ( V_7 -> V_33 , V_50 ) ) {
F_28 ( V_7 -> V_12 , L_4 ) ;
return - V_56 ;
}
V_31 -> V_57 = ( V_14 ) V_50 ;
V_17 = F_20 ( V_7 ) ;
F_7 ( & V_7 -> V_20 [ V_17 ] , V_19 ) ;
V_54 = F_22 ( V_7 , V_17 , V_31 -> V_58 . type ) ;
if ( V_54 <= 0 ) {
F_13 ( V_7 -> V_33 , V_50 , V_35 , V_36 ) ;
V_31 -> V_57 = 0 ;
F_9 ( & V_7 -> V_20 [ V_17 ] , V_19 ) ;
F_29 ( & V_7 -> V_24 . V_25 . V_59 ) ;
F_30 ( L_5 , V_7 -> V_12 -> V_13 ) ;
return - V_56 ;
}
F_31 ( & V_7 -> V_2 [ V_17 ] , V_9 , V_50 , V_35 , 0 , 0 , 1 ) ;
V_53 = F_32 ( & V_52 -> V_48 ) ;
F_9 ( & V_7 -> V_20 [ V_17 ] , V_19 ) ;
if ( V_53 > F_23 ( & V_52 -> V_60 ) )
F_33 ( & V_52 -> V_60 , V_53 ) ;
return 0 ;
}
void
F_34 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
unsigned long V_19 ;
F_35 ( & V_32 -> V_38 ) ;
F_7 ( & V_7 -> V_37 , V_19 ) ;
F_36 ( & V_32 -> V_38 , & V_7 -> V_61 ) ;
F_9 ( & V_7 -> V_37 , V_19 ) ;
}
struct V_15 *
F_37 ( struct V_7 * V_7 , int V_62 )
{
T_1 V_63 ;
struct V_15 * V_32 = NULL ;
V_63 = ( V_62 <= V_64 ) ?
V_64 : V_65 ;
V_32 = F_38 ( V_7 -> V_66 [ V_63 ] , V_67 ) ;
if ( ! V_32 ) {
F_29 ( & V_7 -> V_24 . V_68 . V_69 ) ;
F_28 ( V_7 -> V_12 ,
L_6 ,
V_63 ) ;
return V_32 ;
}
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_70 = V_63 ;
V_32 -> V_71 = V_27 ;
V_32 -> V_31 = (struct V_30 * ) ( V_32 + 1 ) ;
V_32 -> V_72 = sizeof( struct V_30 ) ;
V_32 -> V_7 = V_7 ;
V_32 -> V_31 = (struct V_30 * ) ( V_32 + 1 ) ;
if ( V_62 == 0 )
goto V_39;
V_32 -> V_72 += ( V_62 * sizeof( struct V_73 ) ) ;
if ( V_62 > F_23 ( & V_7 -> V_24 . V_68 . V_74 ) )
F_33 ( & V_7 -> V_24 . V_68 . V_74 , V_62 ) ;
F_3 ( V_62 > V_75 ) ;
F_29 ( & V_7 -> V_24 . V_68 . V_76 [ V_62 - 1 ] ) ;
V_39:
memset ( V_32 -> V_31 , 0 , V_32 -> V_72 ) ;
V_32 -> V_31 -> V_58 . V_77 = ( V_14 ) V_32 ;
F_39 ( V_7 -> V_12 , L_7 , V_32 ) ;
return V_32 ;
}
struct V_30 *
F_40 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
struct V_30 * V_31 = NULL ;
F_3 ( ! V_32 ) ;
if ( V_32 -> V_78 )
return V_32 -> V_78 ;
V_31 = F_38 ( V_7 -> V_66 [ V_79 ] , V_67 ) ;
if ( ! V_31 ) {
F_28 ( V_7 -> V_12 , L_8 ) ;
F_41 ( 1 ) ;
return NULL ;
}
V_32 -> V_78 = V_31 ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_58 . V_77 = ( V_14 ) V_32 ;
return V_31 ;
}
struct V_30 *
F_42 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
struct V_30 * V_31 = NULL ;
F_3 ( ! V_32 ) ;
V_31 = F_38 ( V_7 -> V_66 [ V_79 ] , V_67 ) ;
if ( ! V_31 ) {
F_28 ( V_7 -> V_12 , L_9 ) ;
F_41 ( 1 ) ;
return NULL ;
}
F_3 ( V_32 -> V_80 != NULL ) ;
V_32 -> V_80 = V_31 ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_58 . V_77 = ( V_14 ) V_32 ;
return V_31 ;
}
void
F_19 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
F_3 ( V_32 -> V_31 == V_32 -> V_78 ) ;
F_3 ( V_32 -> V_31 == V_32 -> V_80 ) ;
F_3 ( V_32 -> V_41 != 0 ) ;
F_39 ( V_7 -> V_12 ,
L_10 ,
V_32 , V_32 -> V_31 , V_32 -> V_78 , V_32 -> V_80 ) ;
if ( V_32 -> V_78 ) {
if ( V_32 -> V_78 -> V_57 )
F_13 ( V_7 -> V_33 ,
V_32 -> V_78 -> V_57 ,
sizeof( struct V_30 ) ,
V_36 ) ;
F_43 ( V_32 -> V_78 , V_7 -> V_66 [ V_79 ] ) ;
}
if ( V_32 -> V_80 ) {
if ( V_32 -> V_80 -> V_57 )
F_13 ( V_7 -> V_33 ,
V_32 -> V_80 -> V_57 ,
sizeof( struct V_30 ) ,
V_36 ) ;
F_43 ( V_32 -> V_80 , V_7 -> V_66 [ V_79 ] ) ;
}
if ( V_32 -> V_31 -> V_57 )
F_13 ( V_7 -> V_33 ,
V_32 -> V_31 -> V_57 ,
V_32 -> V_72 ,
V_36 ) ;
F_43 ( V_32 , V_7 -> V_66 [ V_32 -> V_70 ] ) ;
}
void
F_17 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
struct V_73 * V_81 ;
V_81 = F_44 ( F_45 ( V_32 ) ) ;
F_3 ( V_81 [ 0 ] . V_82 == 0 ) ;
F_13 ( V_7 -> V_33 ,
F_46 ( V_81 [ 0 ] . V_82 ) ,
F_47 ( V_81 [ 0 ] . V_35 ) ,
V_83 ) ;
}
void
F_48 ( struct V_7 * V_7 )
{
struct V_15 * V_32 ;
struct V_84 * V_85 , * V_86 ;
unsigned long V_19 ;
F_7 ( & V_7 -> V_37 , V_19 ) ;
F_49 (cur, nxt, &snic->spl_cmd_list) {
V_32 = F_50 ( V_85 , struct V_15 , V_38 ) ;
F_16 ( & V_32 -> V_38 ) ;
if ( V_32 -> V_41 ) {
F_17 ( V_7 , V_32 ) ;
F_18 ( ( void * ) V_32 -> V_41 ) ;
V_32 -> V_41 = 0 ;
}
F_19 ( V_7 , V_32 ) ;
}
F_9 ( & V_7 -> V_37 , V_19 ) ;
}
void
F_51 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
unsigned long V_19 ;
F_7 ( & V_7 -> V_87 , V_19 ) ;
if ( V_7 -> V_88 ) {
F_9 ( & V_7 -> V_87 , V_19 ) ;
goto V_39;
}
F_9 ( & V_7 -> V_87 , V_19 ) ;
F_7 ( & V_7 -> V_37 , V_19 ) ;
if ( F_15 ( & V_32 -> V_38 ) ) {
F_9 ( & V_7 -> V_37 , V_19 ) ;
goto V_39;
}
F_16 ( & V_32 -> V_38 ) ;
F_9 ( & V_7 -> V_37 , V_19 ) ;
F_19 ( V_7 , V_32 ) ;
V_39:
return;
}
void
F_52 ( char * V_89 , char * V_90 , int V_35 )
{
F_53 ( L_11 , V_89 , V_35 ) ;
F_54 ( V_89 , V_91 , V_90 , V_35 ) ;
}
static void
F_55 ( const char * V_92 , char * V_9 , int V_35 )
{
struct V_30 * V_31 = (struct V_30 * ) V_9 ;
struct V_93 * V_94 = (struct V_93 * ) V_9 ;
struct V_15 * V_32 = NULL ;
char line [ V_95 ] = { '\0' } ;
char * V_96 = NULL ;
if ( V_31 -> V_58 . type >= V_97 )
V_32 = (struct V_15 * ) V_94 -> V_58 . V_77 ;
else
V_32 = (struct V_15 * ) V_31 -> V_58 . V_77 ;
F_3 ( V_32 == NULL || V_32 -> V_31 == NULL ) ;
switch ( V_31 -> V_58 . type ) {
case V_98 :
V_96 = L_12 ;
snprintf ( line , V_95 , L_13 ) ;
break;
case V_99 :
V_96 = L_14 ;
snprintf ( line , V_95 , L_15 ,
V_31 -> V_100 . V_101 . V_102 [ 0 ] ) ;
break;
case V_103 :
V_96 = L_16 ;
snprintf ( line , V_95 , L_17 ) ;
break;
case V_49 :
V_96 = L_18 ;
snprintf ( line , V_95 , L_19 ) ;
break;
case V_104 :
V_96 = L_20 ;
snprintf ( line , V_95 , L_21 ) ;
break;
case V_105 :
V_96 = L_22 ;
break;
case V_97 :
V_96 = L_23 ;
snprintf ( line , V_95 , L_24 ) ;
break;
case V_106 :
V_96 = L_25 ;
snprintf ( line , V_95 , L_26 ,
V_32 -> V_31 -> V_100 . V_101 . V_102 [ 0 ] ) ;
break;
case V_107 :
V_96 = L_27 ;
snprintf ( line , V_95 , L_28 ) ;
break;
case V_108 :
V_96 = L_29 ;
snprintf ( line , V_95 , L_30 ) ;
break;
case V_109 :
V_96 = L_31 ;
snprintf ( line , V_95 , L_32 ) ;
break;
case V_110 :
V_96 = L_33 ;
snprintf ( line , V_95 , L_34 ) ;
break;
case V_111 :
V_96 = L_35 ;
snprintf ( line , V_95 , L_36 ) ;
break;
default:
V_96 = L_37 ;
F_3 ( 1 ) ;
break;
}
F_53 ( L_38 ,
V_92 , line , V_31 -> V_58 . V_112 , V_31 -> V_58 . V_62 , V_31 -> V_58 . V_113 ,
V_31 -> V_58 . V_77 ) ;
if ( V_10 & 0x20 )
F_52 ( V_96 , V_9 , V_35 ) ;
}
void
F_25 ( const char * V_92 , char * V_9 , int V_35 )
{
if ( V_10 & V_11 )
F_55 ( V_92 , V_9 , V_35 ) ;
}
void
F_56 ( struct V_7 * V_7 , struct V_15 * V_32 )
{
T_4 V_114 ;
V_114 = V_27 - V_32 -> V_71 ;
if ( V_114 > F_23 ( & V_7 -> V_24 . V_68 . V_115 ) )
F_33 ( & V_7 -> V_24 . V_68 . V_115 , V_114 ) ;
}
