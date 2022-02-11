static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( V_2 -> V_5 [ V_3 ] ) ;
F_2 ( V_2 ) ;
}
static struct V_1 * F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_7 ;
return V_2 ;
}
static int F_5 ( struct V_1 * V_9 , T_1 V_10 )
{
struct V_6 * * V_11 ;
unsigned int V_12 ;
F_6 () ;
V_11 = V_9 -> V_5 [ V_10 / V_13 ] ;
if ( V_11 != NULL )
return 0 ;
V_12 = sizeof( struct V_6 * ) * V_13 ;
V_11 = F_4 ( V_12 , V_8 ) ;
if ( V_11 == NULL )
return - V_14 ;
V_9 -> V_5 [ V_10 / V_13 ] = V_11 ;
return 0 ;
}
static void F_7 ( struct V_15 * V_16 )
{
F_1 ( F_8 ( V_16 , struct V_1 , V_16 ) ) ;
}
void F_9 ( struct V_6 * V_17 , struct V_18 * V_19 )
{
struct V_20 * V_21 = V_20 ( V_17 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
const struct V_22 * V_23 = V_7 -> V_24 ;
struct V_1 * V_2 ;
T_1 V_10 = V_21 -> V_10 ;
F_6 () ;
V_2 = F_10 ( V_7 -> V_25 ) ;
F_11 ( ! V_2 ) ;
if ( V_10 && ( V_7 -> V_26 & V_27 ) )
V_23 -> V_28 ( V_7 , V_10 ) ;
V_2 -> V_29 -- ;
if ( V_21 -> V_30 & V_31 )
F_12 ( V_17 ) ;
F_13 ( V_2 , V_10 , NULL ) ;
F_14 ( V_17 , V_19 ) ;
if ( V_2 -> V_29 == 0 ) {
F_15 ( V_7 ) ;
F_16 ( V_7 -> V_25 , NULL ) ;
F_17 ( & V_2 -> V_16 , F_7 ) ;
}
F_18 ( V_7 ) ;
}
int F_19 ( struct V_6 * V_7 , T_1 V_10 )
{
const char * V_32 = V_7 -> V_32 ;
const struct V_22 * V_23 = V_7 -> V_24 ;
if ( V_7 -> V_26 & V_33 ) {
F_20 ( L_1 , V_32 ) ;
return - V_34 ;
}
if ( ( V_7 -> V_26 & V_27 ) &&
( ! V_23 -> V_35 || ! V_23 -> V_28 ) ) {
F_20 ( L_2 , V_32 ) ;
return - V_34 ;
}
if ( F_21 ( V_7 , V_10 ) != NULL )
return - V_36 ;
return 0 ;
}
int F_22 ( struct V_6 * V_17 )
{
struct V_20 * V_21 = V_20 ( V_17 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
const struct V_22 * V_23 = V_7 -> V_24 ;
T_1 V_10 = V_21 -> V_10 ;
struct V_1 * V_2 , * V_37 = NULL ;
int V_38 ;
V_2 = F_10 ( V_7 -> V_25 ) ;
if ( ! V_2 ) {
V_37 = V_2 = F_3 ( V_7 ) ;
if ( ! V_2 )
return - V_14 ;
V_38 = F_23 ( V_7 ) ;
if ( V_38 < 0 )
goto V_39;
}
V_38 = F_5 ( V_2 , V_10 ) ;
if ( V_38 < 0 )
goto V_40;
V_38 = F_24 ( V_17 ) ;
if ( V_38 < 0 )
goto V_40;
F_25 ( V_7 ) ;
F_26 ( V_7 , V_17 ) ;
F_27 ( V_17 ) ;
F_13 ( V_2 , V_10 , V_17 ) ;
V_2 -> V_29 ++ ;
if ( V_37 ) {
F_28 ( V_7 -> V_25 , V_37 ) ;
}
if ( V_7 -> V_26 & V_27 )
V_23 -> V_35 ( V_7 , V_10 ) ;
return 0 ;
V_40:
if ( V_37 )
F_15 ( V_7 ) ;
V_39:
if ( V_37 ) {
F_17 ( & V_37 -> V_16 , F_7 ) ;
}
return V_38 ;
}
static int F_29 ( struct V_6 * V_7 , T_1 V_10 )
{
struct V_6 * V_41 ;
struct V_42 * V_42 = F_30 ( V_7 ) ;
struct V_43 * V_44 = F_31 ( V_42 , V_45 ) ;
char V_32 [ V_46 ] ;
int V_38 ;
if ( V_10 >= V_47 )
return - V_48 ;
V_38 = F_19 ( V_7 , V_10 ) ;
if ( V_38 < 0 )
return V_38 ;
switch ( V_44 -> V_49 ) {
case V_50 :
snprintf ( V_32 , V_46 , L_3 , V_7 -> V_32 , V_10 ) ;
break;
case V_51 :
snprintf ( V_32 , V_46 , L_4 , V_10 ) ;
break;
case V_52 :
snprintf ( V_32 , V_46 , L_5 , V_7 -> V_32 , V_10 ) ;
break;
case V_53 :
default:
snprintf ( V_32 , V_46 , L_6 , V_10 ) ;
}
V_41 = F_32 ( sizeof( struct V_20 ) , V_32 , V_54 ) ;
if ( V_41 == NULL )
return - V_14 ;
F_33 ( V_41 , V_42 ) ;
V_41 -> V_55 = V_7 -> V_55 ;
V_20 ( V_41 ) -> V_10 = V_10 ;
V_20 ( V_41 ) -> V_7 = V_7 ;
V_20 ( V_41 ) -> V_56 = NULL ;
V_20 ( V_41 ) -> V_30 = V_57 ;
V_41 -> V_58 = & V_59 ;
V_38 = F_22 ( V_41 ) ;
if ( V_38 < 0 )
goto V_60;
return 0 ;
V_60:
F_34 ( V_41 ) ;
return V_38 ;
}
static void F_35 ( struct V_6 * V_17 ,
struct V_6 * V_61 )
{
struct V_20 * V_21 = V_20 ( V_61 ) ;
if ( ! F_36 ( V_21 -> V_62 , V_17 -> V_63 ) )
return;
if ( F_36 ( V_61 -> V_63 , V_21 -> V_62 ) &&
! F_36 ( V_61 -> V_63 , V_17 -> V_63 ) )
F_37 ( V_17 , V_61 -> V_63 ) ;
if ( ! F_36 ( V_61 -> V_63 , V_21 -> V_62 ) &&
F_36 ( V_61 -> V_63 , V_17 -> V_63 ) )
F_38 ( V_17 , V_61 -> V_63 ) ;
memcpy ( V_21 -> V_62 , V_17 -> V_63 , V_64 ) ;
}
static void F_39 ( struct V_6 * V_17 ,
struct V_6 * V_61 )
{
V_61 -> V_65 = V_17 -> V_65 ;
if ( V_17 -> V_26 & V_66 )
V_61 -> V_67 = V_17 -> V_67 ;
else
V_61 -> V_67 = V_17 -> V_67 + V_68 ;
#if F_40 ( V_69 ) || F_40 ( V_70 )
V_61 -> V_71 = V_17 -> V_71 ;
#endif
F_41 ( V_61 ) ;
}
static void F_42 ( struct V_6 * V_17 , unsigned long V_72 )
{
switch ( V_72 ) {
case V_73 :
F_43 ( V_17 ) ;
if ( F_44 ( V_17 ) < 0 )
F_45 ( L_7 ,
V_17 -> V_32 ) ;
break;
case V_74 :
if ( F_44 ( V_17 ) < 0 )
F_45 ( L_8 , V_17 -> V_32 ) ;
break;
case V_75 :
F_43 ( V_17 ) ;
break;
}
}
static int F_46 ( struct V_76 * V_77 , unsigned long V_72 ,
void * V_78 )
{
struct V_6 * V_17 = V_78 ;
struct V_1 * V_2 ;
int V_3 , V_79 ;
struct V_6 * V_61 ;
struct V_20 * V_21 ;
F_47 ( V_80 ) ;
if ( F_48 ( V_17 ) )
F_42 ( V_17 , V_72 ) ;
if ( ( V_72 == V_81 ) &&
( V_17 -> V_26 & V_27 ) &&
V_17 -> V_24 -> V_35 ) {
F_20 ( L_9 ,
V_17 -> V_32 ) ;
V_17 -> V_24 -> V_35 ( V_17 , 0 ) ;
}
V_2 = F_10 ( V_17 -> V_25 ) ;
if ( ! V_2 )
goto V_82;
switch ( V_72 ) {
case V_83 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
F_26 ( V_17 , V_61 ) ;
}
break;
case V_85 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
V_79 = V_61 -> V_30 ;
if ( ! ( V_79 & V_86 ) )
continue;
F_35 ( V_17 , V_61 ) ;
}
break;
case V_87 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
if ( V_61 -> V_55 <= V_17 -> V_55 )
continue;
F_50 ( V_61 , V_17 -> V_55 ) ;
}
break;
case V_88 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
F_39 ( V_17 , V_61 ) ;
}
break;
case V_89 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
V_79 = V_61 -> V_30 ;
if ( ! ( V_79 & V_86 ) )
continue;
V_21 = V_20 ( V_61 ) ;
if ( ! ( V_21 -> V_30 & V_90 ) )
F_51 ( V_61 , V_79 & ~ V_86 ) ;
F_26 ( V_17 , V_61 ) ;
}
break;
case V_81 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
V_79 = V_61 -> V_30 ;
if ( V_79 & V_86 )
continue;
V_21 = V_20 ( V_61 ) ;
if ( ! ( V_21 -> V_30 & V_90 ) )
F_51 ( V_61 , V_79 | V_86 ) ;
F_26 ( V_17 , V_61 ) ;
}
break;
case V_75 :
if ( V_17 -> V_91 != V_92 )
break;
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
if ( V_2 -> V_29 == 1 )
V_3 = V_84 ;
F_9 ( V_61 , & V_80 ) ;
}
F_52 ( & V_80 ) ;
break;
case V_93 :
return V_94 ;
case V_95 :
case V_96 :
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_61 = F_49 ( V_2 , V_3 ) ;
if ( ! V_61 )
continue;
F_53 ( V_72 , V_61 ) ;
}
break;
}
V_82:
return V_97 ;
}
static int F_54 ( struct V_42 * V_42 , void T_2 * V_98 )
{
int V_38 ;
struct V_99 args ;
struct V_6 * V_17 = NULL ;
if ( F_55 ( & args , V_98 , sizeof( struct V_99 ) ) )
return - V_100 ;
args . V_101 [ 23 ] = 0 ;
args . V_102 . V_103 [ 23 ] = 0 ;
F_56 () ;
switch ( args . V_104 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_38 = - V_112 ;
V_17 = F_57 ( V_42 , args . V_101 ) ;
if ( ! V_17 )
goto V_82;
V_38 = - V_113 ;
if ( args . V_104 != V_108 && ! F_48 ( V_17 ) )
goto V_82;
}
switch ( args . V_104 ) {
case V_105 :
V_38 = - V_114 ;
if ( ! F_58 ( V_115 ) )
break;
F_59 ( V_17 ,
args . V_102 . V_116 ,
args . V_117 ) ;
V_38 = 0 ;
break;
case V_106 :
V_38 = - V_114 ;
if ( ! F_58 ( V_115 ) )
break;
V_38 = F_60 ( V_17 ,
args . V_102 . V_116 ,
args . V_117 ) ;
break;
case V_107 :
V_38 = - V_114 ;
if ( ! F_58 ( V_115 ) )
break;
V_38 = F_61 ( V_17 ,
args . V_117 ? args . V_102 . V_118 : 0 ,
args . V_102 . V_118 ) ;
break;
case V_119 :
V_38 = - V_114 ;
if ( ! F_58 ( V_115 ) )
break;
if ( ( args . V_102 . V_49 >= 0 ) &&
( args . V_102 . V_49 < V_120 ) ) {
struct V_43 * V_44 ;
V_44 = F_31 ( V_42 , V_45 ) ;
V_44 -> V_49 = args . V_102 . V_49 ;
V_38 = 0 ;
} else {
V_38 = - V_113 ;
}
break;
case V_108 :
V_38 = - V_114 ;
if ( ! F_58 ( V_115 ) )
break;
V_38 = F_29 ( V_17 , args . V_102 . V_121 ) ;
break;
case V_109 :
V_38 = - V_114 ;
if ( ! F_58 ( V_115 ) )
break;
F_9 ( V_17 , NULL ) ;
V_38 = 0 ;
break;
case V_110 :
V_38 = 0 ;
F_62 ( V_17 , args . V_102 . V_103 ) ;
if ( F_63 ( V_98 , & args ,
sizeof( struct V_99 ) ) )
V_38 = - V_100 ;
break;
case V_111 :
V_38 = 0 ;
args . V_102 . V_121 = F_64 ( V_17 ) ;
if ( F_63 ( V_98 , & args ,
sizeof( struct V_99 ) ) )
V_38 = - V_100 ;
break;
default:
V_38 = - V_34 ;
break;
}
V_82:
F_65 () ;
return V_38 ;
}
static int T_3 F_66 ( struct V_42 * V_42 )
{
struct V_43 * V_44 = F_31 ( V_42 , V_45 ) ;
int V_38 ;
V_44 -> V_49 = V_52 ;
V_38 = F_67 ( V_42 ) ;
return V_38 ;
}
static void T_4 F_68 ( struct V_42 * V_42 )
{
F_69 ( V_42 ) ;
}
static int T_5 F_70 ( void )
{
int V_38 ;
F_20 ( L_10 , V_122 , V_123 ) ;
V_38 = F_71 ( & V_124 ) ;
if ( V_38 < 0 )
goto V_125;
V_38 = F_72 ( & V_126 ) ;
if ( V_38 < 0 )
goto V_127;
V_38 = F_73 () ;
if ( V_38 < 0 )
goto V_128;
V_38 = F_74 () ;
if ( V_38 < 0 )
goto V_129;
F_75 ( F_54 ) ;
return 0 ;
V_129:
F_76 () ;
V_128:
F_77 ( & V_126 ) ;
V_127:
F_78 ( & V_124 ) ;
V_125:
return V_38 ;
}
static void T_6 F_79 ( void )
{
F_75 ( NULL ) ;
F_80 () ;
F_77 ( & V_126 ) ;
F_78 ( & V_124 ) ;
F_81 () ;
F_76 () ;
}
