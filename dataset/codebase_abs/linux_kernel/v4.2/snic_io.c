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
F_6 ( V_7 -> V_16 , V_5 -> V_17 , V_5 -> V_18 , V_19 ) ;
V_5 -> V_9 = NULL ;
}
static int
F_7 ( struct V_20 * V_8 ,
struct V_3 * V_3 ,
T_1 type ,
T_2 V_21 ,
T_2 V_22 ,
void * V_6 )
{
struct V_7 * V_7 = F_2 ( V_8 ) ;
unsigned long V_23 ;
F_3 ( V_21 != 0 ) ;
F_8 ( & V_7 -> V_24 [ V_21 ] , V_23 ) ;
F_9 ( & V_7 -> V_2 [ V_21 ] ,
V_3 ,
V_22 ,
F_1 ,
NULL ) ;
F_10 ( & V_7 -> V_24 [ V_21 ] , V_23 ) ;
return 0 ;
}
int
F_11 ( struct V_7 * V_7 , int V_25 )
{
unsigned int V_26 = 0 ;
unsigned int V_27 ;
V_7 -> V_28 . V_29 . V_30 = V_31 ;
for ( V_27 = 0 ; V_27 < V_7 -> V_32 ; V_27 ++ ) {
V_26 += F_12 ( & V_7 -> V_33 [ V_27 ] ,
V_25 ,
F_7 ,
NULL ) ;
}
return V_26 ;
}
void
F_13 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_34 * V_35 = V_5 -> V_9 ;
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_15 * V_36 = NULL ;
unsigned long V_23 ;
F_6 ( V_7 -> V_16 , V_5 -> V_17 , V_5 -> V_18 , V_19 ) ;
V_36 = F_14 ( V_35 ) ;
F_8 ( & V_7 -> V_37 , V_23 ) ;
if ( F_15 ( & V_36 -> V_38 ) ) {
F_10 ( & V_7 -> V_37 , V_23 ) ;
goto V_39;
}
F_3 ( V_36 -> V_38 . V_40 == NULL ) ;
F_16 ( & V_36 -> V_38 ) ;
F_10 ( & V_7 -> V_37 , V_23 ) ;
if ( V_36 -> V_41 ) {
F_17 ( V_7 , V_36 ) ;
F_18 ( ( void * ) V_36 -> V_41 ) ;
V_36 -> V_41 = 0 ;
}
F_19 ( V_7 , V_36 ) ;
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
int
F_22 ( struct V_7 * V_7 , void * V_9 , T_2 V_18 )
{
T_3 V_43 = 0 ;
unsigned long V_23 ;
struct V_44 * V_45 = & V_7 -> V_28 . V_46 ;
long V_47 ;
int V_21 = 0 ;
F_23 ( V_48 , V_9 , V_18 ) ;
V_43 = F_24 ( V_7 -> V_16 , V_9 , V_18 , V_19 ) ;
if ( F_25 ( V_7 -> V_16 , V_43 ) ) {
F_26 ( V_7 -> V_12 , L_3 ) ;
return - V_49 ;
}
V_21 = F_20 ( V_7 ) ;
F_8 ( & V_7 -> V_24 [ V_21 ] , V_23 ) ;
if ( ! F_27 ( V_7 -> V_2 ) ) {
F_6 ( V_7 -> V_16 , V_43 , V_18 , V_19 ) ;
F_10 ( & V_7 -> V_24 [ V_21 ] , V_23 ) ;
F_28 ( & V_7 -> V_28 . V_29 . V_50 ) ;
F_29 ( L_4 , V_7 -> V_12 -> V_13 ) ;
return - V_49 ;
}
F_30 ( & V_7 -> V_2 [ V_21 ] , V_9 , V_43 , V_18 , 0 , 0 , 1 ) ;
F_10 ( & V_7 -> V_24 [ V_21 ] , V_23 ) ;
V_47 = F_31 ( & V_45 -> V_51 ) ;
if ( V_47 > F_32 ( & V_45 -> V_52 ) )
F_33 ( & V_45 -> V_52 , V_47 ) ;
return 0 ;
}
void
F_34 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
unsigned long V_23 ;
F_35 ( & V_36 -> V_38 ) ;
F_8 ( & V_7 -> V_37 , V_23 ) ;
F_36 ( & V_36 -> V_38 , & V_7 -> V_53 ) ;
F_10 ( & V_7 -> V_37 , V_23 ) ;
}
struct V_15 *
F_37 ( struct V_7 * V_7 , int V_54 )
{
T_1 V_55 ;
struct V_15 * V_36 = NULL ;
V_55 = ( V_54 <= V_56 ) ?
V_56 : V_57 ;
V_36 = F_38 ( V_7 -> V_58 [ V_55 ] , V_59 ) ;
if ( ! V_36 ) {
F_28 ( & V_7 -> V_28 . V_60 . V_61 ) ;
F_26 ( V_7 -> V_12 ,
L_5 ,
V_55 ) ;
return V_36 ;
}
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_62 = V_55 ;
V_36 -> V_63 = V_31 ;
V_36 -> V_35 = (struct V_34 * ) ( V_36 + 1 ) ;
V_36 -> V_64 = sizeof( struct V_34 ) ;
V_36 -> V_7 = V_7 ;
V_36 -> V_35 = (struct V_34 * ) ( V_36 + 1 ) ;
if ( V_54 == 0 )
goto V_39;
V_36 -> V_64 += ( V_54 * sizeof( struct V_65 ) ) ;
if ( V_54 > F_32 ( & V_7 -> V_28 . V_60 . V_66 ) )
F_33 ( & V_7 -> V_28 . V_60 . V_66 , V_54 ) ;
F_3 ( V_54 > V_67 ) ;
F_28 ( & V_7 -> V_28 . V_60 . V_68 [ V_54 - 1 ] ) ;
V_39:
memset ( V_36 -> V_35 , 0 , V_36 -> V_64 ) ;
V_36 -> V_35 -> V_69 . V_70 = ( V_14 ) V_36 ;
F_39 ( V_7 -> V_12 , L_6 , V_36 ) ;
return V_36 ;
}
struct V_34 *
F_40 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
struct V_34 * V_35 = NULL ;
F_3 ( ! V_36 ) ;
if ( V_36 -> V_71 )
return V_36 -> V_71 ;
V_35 = F_38 ( V_7 -> V_58 [ V_72 ] , V_59 ) ;
if ( ! V_35 ) {
F_26 ( V_7 -> V_12 , L_7 ) ;
F_41 ( 1 ) ;
return NULL ;
}
V_36 -> V_71 = V_35 ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_35 -> V_69 . V_70 = ( V_14 ) V_36 ;
return V_35 ;
}
struct V_34 *
F_42 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
struct V_34 * V_35 = NULL ;
F_3 ( ! V_36 ) ;
V_35 = F_38 ( V_7 -> V_58 [ V_72 ] , V_59 ) ;
if ( ! V_35 ) {
F_26 ( V_7 -> V_12 , L_8 ) ;
F_41 ( 1 ) ;
return NULL ;
}
F_3 ( V_36 -> V_73 != NULL ) ;
V_36 -> V_73 = V_35 ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_35 -> V_69 . V_70 = ( V_14 ) V_36 ;
return V_35 ;
}
void
F_19 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
F_3 ( V_36 -> V_35 == V_36 -> V_71 ) ;
F_3 ( V_36 -> V_35 == V_36 -> V_73 ) ;
F_3 ( V_36 -> V_41 != 0 ) ;
F_39 ( V_7 -> V_12 ,
L_9 ,
V_36 , V_36 -> V_35 , V_36 -> V_71 , V_36 -> V_73 ) ;
if ( V_36 -> V_71 )
F_43 ( V_36 -> V_71 , V_7 -> V_58 [ V_72 ] ) ;
if ( V_36 -> V_73 )
F_43 ( V_36 -> V_73 , V_7 -> V_58 [ V_72 ] ) ;
F_43 ( V_36 , V_7 -> V_58 [ V_36 -> V_62 ] ) ;
}
void
F_17 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
struct V_65 * V_74 ;
V_74 = F_44 ( F_45 ( V_36 ) ) ;
F_3 ( V_74 [ 0 ] . V_75 == 0 ) ;
F_6 ( V_7 -> V_16 ,
F_46 ( V_74 [ 0 ] . V_75 ) ,
F_47 ( V_74 [ 0 ] . V_18 ) ,
V_76 ) ;
}
void
F_48 ( struct V_7 * V_7 )
{
struct V_15 * V_36 ;
struct V_77 * V_78 , * V_79 ;
unsigned long V_23 ;
F_8 ( & V_7 -> V_37 , V_23 ) ;
F_49 (cur, nxt, &snic->spl_cmd_list) {
V_36 = F_50 ( V_78 , struct V_15 , V_38 ) ;
F_16 ( & V_36 -> V_38 ) ;
if ( V_36 -> V_41 ) {
F_17 ( V_7 , V_36 ) ;
F_18 ( ( void * ) V_36 -> V_41 ) ;
V_36 -> V_41 = 0 ;
}
F_19 ( V_7 , V_36 ) ;
}
F_10 ( & V_7 -> V_37 , V_23 ) ;
}
void
F_51 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
unsigned long V_23 ;
F_8 ( & V_7 -> V_80 , V_23 ) ;
if ( V_7 -> V_81 ) {
F_10 ( & V_7 -> V_80 , V_23 ) ;
goto V_39;
}
F_10 ( & V_7 -> V_80 , V_23 ) ;
F_8 ( & V_7 -> V_37 , V_23 ) ;
if ( F_15 ( & V_36 -> V_38 ) ) {
F_10 ( & V_7 -> V_37 , V_23 ) ;
goto V_39;
}
F_16 ( & V_36 -> V_38 ) ;
F_10 ( & V_7 -> V_37 , V_23 ) ;
F_19 ( V_7 , V_36 ) ;
V_39:
return;
}
void
F_52 ( char * V_82 , char * V_83 , int V_18 )
{
F_53 ( L_10 , V_82 , V_18 ) ;
F_54 ( V_82 , V_84 , V_83 , V_18 ) ;
}
static void
F_55 ( const char * V_85 , char * V_9 , int V_18 )
{
struct V_34 * V_35 = (struct V_34 * ) V_9 ;
struct V_86 * V_87 = (struct V_86 * ) V_9 ;
struct V_15 * V_36 = NULL ;
char line [ V_88 ] = { '\0' } ;
char * V_89 = NULL ;
if ( V_35 -> V_69 . type >= V_90 )
V_36 = (struct V_15 * ) V_87 -> V_69 . V_70 ;
else
V_36 = (struct V_15 * ) V_35 -> V_69 . V_70 ;
F_3 ( V_36 == NULL || V_36 -> V_35 == NULL ) ;
switch ( V_35 -> V_69 . type ) {
case V_91 :
V_89 = L_11 ;
snprintf ( line , V_88 , L_12 ) ;
break;
case V_92 :
V_89 = L_13 ;
snprintf ( line , V_88 , L_14 ,
V_35 -> V_93 . V_94 . V_95 [ 0 ] ) ;
break;
case V_96 :
V_89 = L_15 ;
snprintf ( line , V_88 , L_16 ) ;
break;
case V_97 :
V_89 = L_17 ;
snprintf ( line , V_88 , L_18 ) ;
break;
case V_98 :
V_89 = L_19 ;
snprintf ( line , V_88 , L_20 ) ;
break;
case V_99 :
V_89 = L_21 ;
break;
case V_90 :
V_89 = L_22 ;
snprintf ( line , V_88 , L_23 ) ;
break;
case V_100 :
V_89 = L_24 ;
snprintf ( line , V_88 , L_25 ,
V_36 -> V_35 -> V_93 . V_94 . V_95 [ 0 ] ) ;
break;
case V_101 :
V_89 = L_26 ;
snprintf ( line , V_88 , L_27 ) ;
break;
case V_102 :
V_89 = L_28 ;
snprintf ( line , V_88 , L_29 ) ;
break;
case V_103 :
V_89 = L_30 ;
snprintf ( line , V_88 , L_31 ) ;
break;
case V_104 :
V_89 = L_32 ;
snprintf ( line , V_88 , L_33 ) ;
break;
case V_105 :
V_89 = L_34 ;
snprintf ( line , V_88 , L_35 ) ;
break;
default:
V_89 = L_36 ;
F_3 ( 1 ) ;
break;
}
F_53 ( L_37 ,
V_85 , line , V_35 -> V_69 . V_106 , V_35 -> V_69 . V_54 , V_35 -> V_69 . V_107 ,
V_35 -> V_69 . V_70 ) ;
if ( V_10 & 0x20 )
F_52 ( V_89 , V_9 , V_18 ) ;
}
void
F_23 ( const char * V_85 , char * V_9 , int V_18 )
{
if ( V_10 & V_11 )
F_55 ( V_85 , V_9 , V_18 ) ;
}
void
F_56 ( struct V_7 * V_7 , struct V_15 * V_36 )
{
T_4 V_108 ;
V_108 = V_31 - V_36 -> V_63 ;
if ( V_108 > F_32 ( & V_7 -> V_28 . V_60 . V_109 ) )
F_33 ( & V_7 -> V_28 . V_60 . V_109 , V_108 ) ;
}
