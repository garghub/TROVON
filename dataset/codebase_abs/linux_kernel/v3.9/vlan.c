static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * * V_5 ;
unsigned int V_6 ;
F_2 () ;
V_5 = V_2 -> V_7 [ V_3 / V_8 ] ;
if ( V_5 != NULL )
return 0 ;
V_6 = sizeof( struct V_4 * ) * V_8 ;
V_5 = F_3 ( V_6 , V_9 ) ;
if ( V_5 == NULL )
return - V_10 ;
V_2 -> V_7 [ V_3 / V_8 ] = V_5 ;
return 0 ;
}
void F_4 ( struct V_4 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_14 ( V_11 ) ;
struct V_4 * V_16 = V_15 -> V_16 ;
struct V_17 * V_17 ;
struct V_1 * V_18 ;
T_1 V_3 = V_15 -> V_3 ;
F_2 () ;
V_17 = F_5 ( V_16 -> V_17 ) ;
F_6 ( ! V_17 ) ;
V_18 = & V_17 -> V_18 ;
V_18 -> V_19 -- ;
if ( V_15 -> V_20 & V_21 )
F_7 ( V_11 ) ;
if ( V_15 -> V_20 & V_22 )
F_8 ( V_11 ) ;
F_9 ( V_18 , V_3 , NULL ) ;
F_10 ( V_11 , V_13 ) ;
F_11 ( V_16 , V_11 ) ;
if ( V_18 -> V_19 == 0 ) {
F_12 ( V_16 ) ;
F_13 ( V_16 ) ;
}
if ( V_3 )
F_14 ( V_16 , V_3 ) ;
F_15 ( V_16 ) ;
}
int F_16 ( struct V_4 * V_16 , T_1 V_3 )
{
const char * V_23 = V_16 -> V_23 ;
if ( V_16 -> V_24 & V_25 ) {
F_17 ( L_1 , V_23 ) ;
return - V_26 ;
}
if ( F_18 ( V_16 , V_3 ) != NULL )
return - V_27 ;
return 0 ;
}
int F_19 ( struct V_4 * V_11 )
{
struct V_14 * V_15 = V_14 ( V_11 ) ;
struct V_4 * V_16 = V_15 -> V_16 ;
T_1 V_3 = V_15 -> V_3 ;
struct V_17 * V_17 ;
struct V_1 * V_18 ;
int V_28 ;
V_28 = F_20 ( V_16 , V_3 ) ;
if ( V_28 )
return V_28 ;
V_17 = F_5 ( V_16 -> V_17 ) ;
F_6 ( ! V_17 ) ;
V_18 = & V_17 -> V_18 ;
if ( V_18 -> V_19 == 0 ) {
V_28 = F_21 ( V_16 ) ;
if ( V_28 < 0 )
goto V_29;
V_28 = F_22 ( V_16 ) ;
if ( V_28 < 0 )
goto V_30;
}
V_28 = F_1 ( V_18 , V_3 ) ;
if ( V_28 < 0 )
goto V_31;
V_28 = F_23 ( V_16 , V_11 ) ;
if ( V_28 )
goto V_31;
V_28 = F_24 ( V_11 ) ;
if ( V_28 < 0 )
goto V_32;
F_25 ( V_16 ) ;
F_26 ( V_16 , V_11 ) ;
F_27 ( V_11 ) ;
F_9 ( V_18 , V_3 , V_11 ) ;
V_18 -> V_19 ++ ;
return 0 ;
V_32:
F_11 ( V_16 , V_11 ) ;
V_31:
if ( V_18 -> V_19 == 0 )
F_12 ( V_16 ) ;
V_30:
if ( V_18 -> V_19 == 0 )
F_13 ( V_16 ) ;
V_29:
F_14 ( V_16 , V_3 ) ;
return V_28 ;
}
static int F_28 ( struct V_4 * V_16 , T_1 V_3 )
{
struct V_4 * V_33 ;
struct V_34 * V_34 = F_29 ( V_16 ) ;
struct V_35 * V_36 = F_30 ( V_34 , V_37 ) ;
char V_23 [ V_38 ] ;
int V_28 ;
if ( V_3 >= V_39 )
return - V_40 ;
V_28 = F_16 ( V_16 , V_3 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_36 -> V_41 ) {
case V_42 :
snprintf ( V_23 , V_38 , L_2 , V_16 -> V_23 , V_3 ) ;
break;
case V_43 :
snprintf ( V_23 , V_38 , L_3 , V_3 ) ;
break;
case V_44 :
snprintf ( V_23 , V_38 , L_4 , V_16 -> V_23 , V_3 ) ;
break;
case V_45 :
default:
snprintf ( V_23 , V_38 , L_5 , V_3 ) ;
}
V_33 = F_31 ( sizeof( struct V_14 ) , V_23 , V_46 ) ;
if ( V_33 == NULL )
return - V_10 ;
F_32 ( V_33 , V_34 ) ;
V_33 -> V_47 = V_16 -> V_47 ;
V_33 -> V_48 |= ( V_16 -> V_48 & V_49 ) ;
V_14 ( V_33 ) -> V_3 = V_3 ;
V_14 ( V_33 ) -> V_16 = V_16 ;
V_14 ( V_33 ) -> V_50 = NULL ;
V_14 ( V_33 ) -> V_20 = V_51 ;
V_33 -> V_52 = & V_53 ;
V_28 = F_19 ( V_33 ) ;
if ( V_28 < 0 )
goto V_54;
return 0 ;
V_54:
F_33 ( V_33 ) ;
return V_28 ;
}
static void F_34 ( struct V_4 * V_11 ,
struct V_4 * V_55 )
{
struct V_14 * V_15 = V_14 ( V_55 ) ;
if ( F_35 ( V_15 -> V_56 , V_11 -> V_57 ) )
return;
if ( ! F_35 ( V_55 -> V_57 , V_15 -> V_56 ) &&
F_35 ( V_55 -> V_57 , V_11 -> V_57 ) )
F_36 ( V_11 , V_55 -> V_57 ) ;
if ( F_35 ( V_55 -> V_57 , V_15 -> V_56 ) &&
! F_35 ( V_55 -> V_57 , V_11 -> V_57 ) )
F_37 ( V_11 , V_55 -> V_57 ) ;
memcpy ( V_15 -> V_56 , V_11 -> V_57 , V_58 ) ;
}
static void F_38 ( struct V_4 * V_11 ,
struct V_4 * V_55 )
{
V_55 -> V_59 = V_11 -> V_59 ;
if ( V_11 -> V_24 & V_60 )
V_55 -> V_61 = V_11 -> V_61 ;
else
V_55 -> V_61 = V_11 -> V_61 + V_62 ;
#if F_39 ( V_63 )
V_55 -> V_64 = V_11 -> V_64 ;
#endif
F_40 ( V_55 ) ;
}
static void F_41 ( struct V_4 * V_11 , unsigned long V_65 )
{
switch ( V_65 ) {
case V_66 :
F_42 ( V_11 ) ;
if ( F_43 ( V_11 ) < 0 )
F_44 ( L_6 ,
V_11 -> V_23 ) ;
break;
case V_67 :
if ( F_43 ( V_11 ) < 0 )
F_44 ( L_7 , V_11 -> V_23 ) ;
break;
case V_68 :
F_42 ( V_11 ) ;
break;
}
}
static int F_45 ( struct V_69 * V_70 , unsigned long V_65 ,
void * V_71 )
{
struct V_4 * V_11 = V_71 ;
struct V_1 * V_18 ;
struct V_17 * V_17 ;
int V_72 , V_73 ;
struct V_4 * V_55 ;
struct V_14 * V_15 ;
F_46 ( V_74 ) ;
if ( F_47 ( V_11 ) )
F_41 ( V_11 , V_65 ) ;
if ( ( V_65 == V_75 ) &&
( V_11 -> V_24 & V_76 ) ) {
F_17 ( L_8 ,
V_11 -> V_23 ) ;
F_20 ( V_11 , 0 ) ;
}
V_17 = F_5 ( V_11 -> V_17 ) ;
if ( ! V_17 )
goto V_77;
V_18 = & V_17 -> V_18 ;
switch ( V_65 ) {
case V_78 :
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
F_26 ( V_11 , V_55 ) ;
}
break;
case V_80 :
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
V_73 = V_55 -> V_20 ;
if ( ! ( V_73 & V_81 ) )
continue;
F_34 ( V_11 , V_55 ) ;
}
break;
case V_82 :
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
if ( V_55 -> V_47 <= V_11 -> V_47 )
continue;
F_49 ( V_55 , V_11 -> V_47 ) ;
}
break;
case V_83 :
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
F_38 ( V_11 , V_55 ) ;
}
break;
case V_84 :
if ( V_11 -> V_24 & V_76 )
F_14 ( V_11 , 0 ) ;
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
V_73 = V_55 -> V_20 ;
if ( ! ( V_73 & V_81 ) )
continue;
V_15 = V_14 ( V_55 ) ;
if ( ! ( V_15 -> V_20 & V_85 ) )
F_50 ( V_55 , V_73 & ~ V_81 ) ;
F_26 ( V_11 , V_55 ) ;
}
break;
case V_75 :
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
V_73 = V_55 -> V_20 ;
if ( V_73 & V_81 )
continue;
V_15 = V_14 ( V_55 ) ;
if ( ! ( V_15 -> V_20 & V_85 ) )
F_50 ( V_55 , V_73 | V_81 ) ;
F_26 ( V_11 , V_55 ) ;
}
break;
case V_68 :
if ( V_11 -> V_86 != V_87 )
break;
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
if ( V_17 -> V_88 == 1 )
V_72 = V_79 ;
F_4 ( V_55 , & V_74 ) ;
}
F_51 ( & V_74 ) ;
break;
case V_89 :
if ( F_52 ( V_11 ) )
return V_90 ;
break;
case V_91 :
case V_92 :
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_55 = F_48 ( V_18 , V_72 ) ;
if ( ! V_55 )
continue;
F_53 ( V_65 , V_55 ) ;
}
break;
}
V_77:
return V_93 ;
}
static int F_54 ( struct V_34 * V_34 , void T_2 * V_94 )
{
int V_28 ;
struct V_95 args ;
struct V_4 * V_11 = NULL ;
if ( F_55 ( & args , V_94 , sizeof( struct V_95 ) ) )
return - V_96 ;
args . V_97 [ 23 ] = 0 ;
args . V_98 . V_99 [ 23 ] = 0 ;
F_56 () ;
switch ( args . V_100 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_28 = - V_108 ;
V_11 = F_57 ( V_34 , args . V_97 ) ;
if ( ! V_11 )
goto V_77;
V_28 = - V_109 ;
if ( args . V_100 != V_104 && ! F_47 ( V_11 ) )
goto V_77;
}
switch ( args . V_100 ) {
case V_101 :
V_28 = - V_110 ;
if ( ! F_58 ( V_34 -> V_111 , V_112 ) )
break;
F_59 ( V_11 ,
args . V_98 . V_113 ,
args . V_114 ) ;
V_28 = 0 ;
break;
case V_102 :
V_28 = - V_110 ;
if ( ! F_58 ( V_34 -> V_111 , V_112 ) )
break;
V_28 = F_60 ( V_11 ,
args . V_98 . V_113 ,
args . V_114 ) ;
break;
case V_103 :
V_28 = - V_110 ;
if ( ! F_58 ( V_34 -> V_111 , V_112 ) )
break;
V_28 = F_61 ( V_11 ,
args . V_114 ? args . V_98 . V_115 : 0 ,
args . V_98 . V_115 ) ;
break;
case V_116 :
V_28 = - V_110 ;
if ( ! F_58 ( V_34 -> V_111 , V_112 ) )
break;
if ( ( args . V_98 . V_41 >= 0 ) &&
( args . V_98 . V_41 < V_117 ) ) {
struct V_35 * V_36 ;
V_36 = F_30 ( V_34 , V_37 ) ;
V_36 -> V_41 = args . V_98 . V_41 ;
V_28 = 0 ;
} else {
V_28 = - V_109 ;
}
break;
case V_104 :
V_28 = - V_110 ;
if ( ! F_58 ( V_34 -> V_111 , V_112 ) )
break;
V_28 = F_28 ( V_11 , args . V_98 . V_118 ) ;
break;
case V_105 :
V_28 = - V_110 ;
if ( ! F_58 ( V_34 -> V_111 , V_112 ) )
break;
F_4 ( V_11 , NULL ) ;
V_28 = 0 ;
break;
case V_106 :
V_28 = 0 ;
F_62 ( V_11 , args . V_98 . V_99 ) ;
if ( F_63 ( V_94 , & args ,
sizeof( struct V_95 ) ) )
V_28 = - V_96 ;
break;
case V_107 :
V_28 = 0 ;
args . V_98 . V_118 = F_64 ( V_11 ) ;
if ( F_63 ( V_94 , & args ,
sizeof( struct V_95 ) ) )
V_28 = - V_96 ;
break;
default:
V_28 = - V_26 ;
break;
}
V_77:
F_65 () ;
return V_28 ;
}
static int T_3 F_66 ( struct V_34 * V_34 )
{
struct V_35 * V_36 = F_30 ( V_34 , V_37 ) ;
int V_28 ;
V_36 -> V_41 = V_44 ;
V_28 = F_67 ( V_34 ) ;
return V_28 ;
}
static void T_4 F_68 ( struct V_34 * V_34 )
{
F_69 ( V_34 ) ;
}
static int T_5 F_70 ( void )
{
int V_28 ;
F_17 ( L_9 , V_119 , V_120 ) ;
V_28 = F_71 ( & V_121 ) ;
if ( V_28 < 0 )
goto V_122;
V_28 = F_72 ( & V_123 ) ;
if ( V_28 < 0 )
goto V_124;
V_28 = F_73 () ;
if ( V_28 < 0 )
goto V_125;
V_28 = F_74 () ;
if ( V_28 < 0 )
goto V_126;
V_28 = F_75 () ;
if ( V_28 < 0 )
goto V_127;
F_76 ( F_54 ) ;
return 0 ;
V_127:
F_77 () ;
V_126:
F_78 () ;
V_125:
F_79 ( & V_123 ) ;
V_124:
F_80 ( & V_121 ) ;
V_122:
return V_28 ;
}
static void T_6 F_81 ( void )
{
F_76 ( NULL ) ;
F_82 () ;
F_79 ( & V_123 ) ;
F_80 ( & V_121 ) ;
F_83 () ;
F_77 () ;
F_78 () ;
}
