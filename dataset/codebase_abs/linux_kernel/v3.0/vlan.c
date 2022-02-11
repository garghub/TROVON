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
if ( V_23 -> V_32 )
V_23 -> V_32 ( V_7 , NULL ) ;
F_17 ( & V_2 -> V_16 , F_7 ) ;
}
F_18 ( V_7 ) ;
}
int F_19 ( struct V_6 * V_7 , T_1 V_10 )
{
const char * V_33 = V_7 -> V_33 ;
const struct V_22 * V_23 = V_7 -> V_24 ;
if ( V_7 -> V_26 & V_34 ) {
F_20 ( L_1 , V_33 ) ;
return - V_35 ;
}
if ( ( V_7 -> V_26 & V_27 ) &&
( ! V_23 -> V_36 || ! V_23 -> V_28 ) ) {
F_20 ( L_2 , V_33 ) ;
return - V_35 ;
}
if ( F_21 ( V_7 , V_10 ) != NULL )
return - V_37 ;
return 0 ;
}
int F_22 ( struct V_6 * V_17 )
{
struct V_20 * V_21 = V_20 ( V_17 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
const struct V_22 * V_23 = V_7 -> V_24 ;
T_1 V_10 = V_21 -> V_10 ;
struct V_1 * V_2 , * V_38 = NULL ;
int V_39 ;
V_2 = F_10 ( V_7 -> V_25 ) ;
if ( ! V_2 ) {
V_38 = V_2 = F_3 ( V_7 ) ;
if ( ! V_2 )
return - V_14 ;
V_39 = F_23 ( V_7 ) ;
if ( V_39 < 0 )
goto V_40;
}
V_39 = F_5 ( V_2 , V_10 ) ;
if ( V_39 < 0 )
goto V_41;
V_39 = F_24 ( V_17 ) ;
if ( V_39 < 0 )
goto V_41;
F_25 ( V_7 ) ;
F_26 ( V_7 , V_17 ) ;
F_27 ( V_17 ) ;
F_13 ( V_2 , V_10 , V_17 ) ;
V_2 -> V_29 ++ ;
if ( V_38 ) {
if ( V_23 -> V_32 && ( V_7 -> V_26 & V_42 ) )
V_23 -> V_32 ( V_7 , V_38 ) ;
F_16 ( V_7 -> V_25 , V_38 ) ;
}
if ( V_7 -> V_26 & V_27 )
V_23 -> V_36 ( V_7 , V_10 ) ;
return 0 ;
V_41:
if ( V_38 )
F_15 ( V_7 ) ;
V_40:
if ( V_38 ) {
F_17 ( & V_38 -> V_16 , F_7 ) ;
}
return V_39 ;
}
static int F_28 ( struct V_6 * V_7 , T_1 V_10 )
{
struct V_6 * V_43 ;
struct V_44 * V_44 = F_29 ( V_7 ) ;
struct V_45 * V_46 = F_30 ( V_44 , V_47 ) ;
char V_33 [ V_48 ] ;
int V_39 ;
if ( V_10 >= V_49 )
return - V_50 ;
V_39 = F_19 ( V_7 , V_10 ) ;
if ( V_39 < 0 )
return V_39 ;
switch ( V_46 -> V_51 ) {
case V_52 :
snprintf ( V_33 , V_48 , L_3 , V_7 -> V_33 , V_10 ) ;
break;
case V_53 :
snprintf ( V_33 , V_48 , L_4 , V_10 ) ;
break;
case V_54 :
snprintf ( V_33 , V_48 , L_5 , V_7 -> V_33 , V_10 ) ;
break;
case V_55 :
default:
snprintf ( V_33 , V_48 , L_6 , V_10 ) ;
}
V_43 = F_31 ( sizeof( struct V_20 ) , V_33 , V_56 ) ;
if ( V_43 == NULL )
return - V_14 ;
F_32 ( V_43 , V_44 ) ;
V_43 -> V_57 = V_7 -> V_57 ;
V_20 ( V_43 ) -> V_10 = V_10 ;
V_20 ( V_43 ) -> V_7 = V_7 ;
V_20 ( V_43 ) -> V_58 = NULL ;
V_20 ( V_43 ) -> V_30 = V_59 ;
V_43 -> V_60 = & V_61 ;
V_39 = F_22 ( V_43 ) ;
if ( V_39 < 0 )
goto V_62;
return 0 ;
V_62:
F_33 ( V_43 ) ;
return V_39 ;
}
static void F_34 ( struct V_6 * V_17 ,
struct V_6 * V_63 )
{
struct V_20 * V_21 = V_20 ( V_63 ) ;
if ( ! F_35 ( V_21 -> V_64 , V_17 -> V_65 ) )
return;
if ( F_35 ( V_63 -> V_65 , V_21 -> V_64 ) &&
! F_35 ( V_63 -> V_65 , V_17 -> V_65 ) )
F_36 ( V_17 , V_63 -> V_65 ) ;
if ( ! F_35 ( V_63 -> V_65 , V_21 -> V_64 ) &&
F_35 ( V_63 -> V_65 , V_17 -> V_65 ) )
F_37 ( V_17 , V_63 -> V_65 ) ;
memcpy ( V_21 -> V_64 , V_17 -> V_65 , V_66 ) ;
}
static void F_38 ( struct V_6 * V_17 ,
struct V_6 * V_63 )
{
V_63 -> V_67 = V_17 -> V_67 ;
if ( V_17 -> V_26 & V_68 )
V_63 -> V_69 = V_17 -> V_69 ;
else
V_63 -> V_69 = V_17 -> V_69 + V_70 ;
#if F_39 ( V_71 ) || F_39 ( V_72 )
V_63 -> V_73 = V_17 -> V_73 ;
#endif
F_40 ( V_63 ) ;
}
static void F_41 ( struct V_6 * V_17 , unsigned long V_74 )
{
switch ( V_74 ) {
case V_75 :
F_42 ( V_17 ) ;
if ( F_43 ( V_17 ) < 0 )
F_44 ( L_7 ,
V_17 -> V_33 ) ;
break;
case V_76 :
if ( F_43 ( V_17 ) < 0 )
F_44 ( L_8 ,
V_17 -> V_33 ) ;
break;
case V_77 :
F_42 ( V_17 ) ;
break;
}
}
static int F_45 ( struct V_78 * V_79 , unsigned long V_74 ,
void * V_80 )
{
struct V_6 * V_17 = V_80 ;
struct V_1 * V_2 ;
int V_3 , V_81 ;
struct V_6 * V_63 ;
struct V_20 * V_21 ;
F_46 ( V_82 ) ;
if ( F_47 ( V_17 ) )
F_41 ( V_17 , V_74 ) ;
if ( ( V_74 == V_83 ) &&
( V_17 -> V_26 & V_27 ) &&
V_17 -> V_24 -> V_36 ) {
F_20 ( L_9 ,
V_17 -> V_33 ) ;
V_17 -> V_24 -> V_36 ( V_17 , 0 ) ;
}
V_2 = F_10 ( V_17 -> V_25 ) ;
if ( ! V_2 )
goto V_84;
switch ( V_74 ) {
case V_85 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
F_26 ( V_17 , V_63 ) ;
}
break;
case V_87 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
V_81 = V_63 -> V_30 ;
if ( ! ( V_81 & V_88 ) )
continue;
F_34 ( V_17 , V_63 ) ;
}
break;
case V_89 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
if ( V_63 -> V_57 <= V_17 -> V_57 )
continue;
F_49 ( V_63 , V_17 -> V_57 ) ;
}
break;
case V_90 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
F_38 ( V_17 , V_63 ) ;
}
break;
case V_91 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
V_81 = V_63 -> V_30 ;
if ( ! ( V_81 & V_88 ) )
continue;
V_21 = V_20 ( V_63 ) ;
if ( ! ( V_21 -> V_30 & V_92 ) )
F_50 ( V_63 , V_81 & ~ V_88 ) ;
F_26 ( V_17 , V_63 ) ;
}
break;
case V_83 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
V_81 = V_63 -> V_30 ;
if ( V_81 & V_88 )
continue;
V_21 = V_20 ( V_63 ) ;
if ( ! ( V_21 -> V_30 & V_92 ) )
F_50 ( V_63 , V_81 | V_88 ) ;
F_26 ( V_17 , V_63 ) ;
}
break;
case V_77 :
if ( V_17 -> V_93 != V_94 )
break;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
if ( V_2 -> V_29 == 1 )
V_3 = V_86 ;
F_9 ( V_63 , & V_82 ) ;
}
F_51 ( & V_82 ) ;
break;
case V_95 :
return V_96 ;
case V_97 :
case V_98 :
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_63 = F_48 ( V_2 , V_3 ) ;
if ( ! V_63 )
continue;
F_52 ( V_74 , V_63 ) ;
}
break;
}
V_84:
return V_99 ;
}
static int F_53 ( struct V_44 * V_44 , void T_2 * V_100 )
{
int V_39 ;
struct V_101 args ;
struct V_6 * V_17 = NULL ;
if ( F_54 ( & args , V_100 , sizeof( struct V_101 ) ) )
return - V_102 ;
args . V_103 [ 23 ] = 0 ;
args . V_104 . V_105 [ 23 ] = 0 ;
F_55 () ;
switch ( args . V_106 ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_39 = - V_114 ;
V_17 = F_56 ( V_44 , args . V_103 ) ;
if ( ! V_17 )
goto V_84;
V_39 = - V_115 ;
if ( args . V_106 != V_110 && ! F_47 ( V_17 ) )
goto V_84;
}
switch ( args . V_106 ) {
case V_107 :
V_39 = - V_116 ;
if ( ! F_57 ( V_117 ) )
break;
F_58 ( V_17 ,
args . V_104 . V_118 ,
args . V_119 ) ;
V_39 = 0 ;
break;
case V_108 :
V_39 = - V_116 ;
if ( ! F_57 ( V_117 ) )
break;
V_39 = F_59 ( V_17 ,
args . V_104 . V_118 ,
args . V_119 ) ;
break;
case V_109 :
V_39 = - V_116 ;
if ( ! F_57 ( V_117 ) )
break;
V_39 = F_60 ( V_17 ,
args . V_119 ? args . V_104 . V_120 : 0 ,
args . V_104 . V_120 ) ;
break;
case V_121 :
V_39 = - V_116 ;
if ( ! F_57 ( V_117 ) )
break;
if ( ( args . V_104 . V_51 >= 0 ) &&
( args . V_104 . V_51 < V_122 ) ) {
struct V_45 * V_46 ;
V_46 = F_30 ( V_44 , V_47 ) ;
V_46 -> V_51 = args . V_104 . V_51 ;
V_39 = 0 ;
} else {
V_39 = - V_115 ;
}
break;
case V_110 :
V_39 = - V_116 ;
if ( ! F_57 ( V_117 ) )
break;
V_39 = F_28 ( V_17 , args . V_104 . V_123 ) ;
break;
case V_111 :
V_39 = - V_116 ;
if ( ! F_57 ( V_117 ) )
break;
F_9 ( V_17 , NULL ) ;
V_39 = 0 ;
break;
case V_112 :
V_39 = 0 ;
F_61 ( V_17 , args . V_104 . V_105 ) ;
if ( F_62 ( V_100 , & args ,
sizeof( struct V_101 ) ) )
V_39 = - V_102 ;
break;
case V_113 :
V_39 = 0 ;
args . V_104 . V_123 = F_63 ( V_17 ) ;
if ( F_62 ( V_100 , & args ,
sizeof( struct V_101 ) ) )
V_39 = - V_102 ;
break;
default:
V_39 = - V_35 ;
break;
}
V_84:
F_64 () ;
return V_39 ;
}
static int T_3 F_65 ( struct V_44 * V_44 )
{
struct V_45 * V_46 = F_30 ( V_44 , V_47 ) ;
int V_39 ;
V_46 -> V_51 = V_54 ;
V_39 = F_66 ( V_44 ) ;
return V_39 ;
}
static void T_4 F_67 ( struct V_44 * V_44 )
{
F_68 ( V_44 ) ;
}
static int T_5 F_69 ( void )
{
int V_39 ;
F_20 ( L_10 , V_124 , V_125 ) ;
V_39 = F_70 ( & V_126 ) ;
if ( V_39 < 0 )
goto V_127;
V_39 = F_71 ( & V_128 ) ;
if ( V_39 < 0 )
goto V_129;
V_39 = F_72 () ;
if ( V_39 < 0 )
goto V_130;
V_39 = F_73 () ;
if ( V_39 < 0 )
goto V_131;
F_74 ( F_53 ) ;
return 0 ;
V_131:
F_75 () ;
V_130:
F_76 ( & V_128 ) ;
V_129:
F_77 ( & V_126 ) ;
V_127:
return V_39 ;
}
static void T_6 F_78 ( void )
{
F_74 ( NULL ) ;
F_79 () ;
F_76 ( & V_128 ) ;
F_77 ( & V_126 ) ;
F_80 () ;
F_75 () ;
}
