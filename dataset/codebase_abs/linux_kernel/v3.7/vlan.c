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
if ( V_3 )
F_7 ( V_16 , V_3 ) ;
V_18 -> V_19 -- ;
if ( V_15 -> V_20 & V_21 )
F_8 ( V_11 ) ;
F_9 ( V_18 , V_3 , NULL ) ;
F_10 ( V_11 , V_13 ) ;
if ( V_18 -> V_19 == 0 )
F_11 ( V_16 ) ;
F_12 ( V_16 ) ;
}
int F_13 ( struct V_4 * V_16 , T_1 V_3 )
{
const char * V_22 = V_16 -> V_22 ;
const struct V_23 * V_24 = V_16 -> V_25 ;
if ( V_16 -> V_26 & V_27 ) {
F_14 ( L_1 , V_22 ) ;
return - V_28 ;
}
if ( ( V_16 -> V_26 & V_29 ) &&
( ! V_24 -> V_30 || ! V_24 -> V_31 ) ) {
F_14 ( L_2 , V_22 ) ;
return - V_28 ;
}
if ( F_15 ( V_16 , V_3 ) != NULL )
return - V_32 ;
return 0 ;
}
int F_16 ( struct V_4 * V_11 )
{
struct V_14 * V_15 = V_14 ( V_11 ) ;
struct V_4 * V_16 = V_15 -> V_16 ;
T_1 V_3 = V_15 -> V_3 ;
struct V_17 * V_17 ;
struct V_1 * V_18 ;
int V_33 ;
V_33 = F_17 ( V_16 , V_3 ) ;
if ( V_33 )
return V_33 ;
V_17 = F_5 ( V_16 -> V_17 ) ;
F_6 ( ! V_17 ) ;
V_18 = & V_17 -> V_18 ;
if ( V_18 -> V_19 == 0 ) {
V_33 = F_18 ( V_16 ) ;
if ( V_33 < 0 )
goto V_34;
}
V_33 = F_1 ( V_18 , V_3 ) ;
if ( V_33 < 0 )
goto V_35;
V_33 = F_19 ( V_11 ) ;
if ( V_33 < 0 )
goto V_35;
F_20 ( V_16 ) ;
F_21 ( V_16 , V_11 ) ;
F_22 ( V_11 ) ;
F_9 ( V_18 , V_3 , V_11 ) ;
V_18 -> V_19 ++ ;
return 0 ;
V_35:
if ( V_18 -> V_19 == 0 )
F_11 ( V_16 ) ;
V_34:
F_7 ( V_16 , V_3 ) ;
return V_33 ;
}
static int F_23 ( struct V_4 * V_16 , T_1 V_3 )
{
struct V_4 * V_36 ;
struct V_37 * V_37 = F_24 ( V_16 ) ;
struct V_38 * V_39 = F_25 ( V_37 , V_40 ) ;
char V_22 [ V_41 ] ;
int V_33 ;
if ( V_3 >= V_42 )
return - V_43 ;
V_33 = F_13 ( V_16 , V_3 ) ;
if ( V_33 < 0 )
return V_33 ;
switch ( V_39 -> V_44 ) {
case V_45 :
snprintf ( V_22 , V_41 , L_3 , V_16 -> V_22 , V_3 ) ;
break;
case V_46 :
snprintf ( V_22 , V_41 , L_4 , V_3 ) ;
break;
case V_47 :
snprintf ( V_22 , V_41 , L_5 , V_16 -> V_22 , V_3 ) ;
break;
case V_48 :
default:
snprintf ( V_22 , V_41 , L_6 , V_3 ) ;
}
V_36 = F_26 ( sizeof( struct V_14 ) , V_22 , V_49 ) ;
if ( V_36 == NULL )
return - V_10 ;
F_27 ( V_36 , V_37 ) ;
V_36 -> V_50 = V_16 -> V_50 ;
V_14 ( V_36 ) -> V_3 = V_3 ;
V_14 ( V_36 ) -> V_16 = V_16 ;
V_14 ( V_36 ) -> V_51 = NULL ;
V_14 ( V_36 ) -> V_20 = V_52 ;
V_36 -> V_53 = & V_54 ;
V_33 = F_16 ( V_36 ) ;
if ( V_33 < 0 )
goto V_55;
return 0 ;
V_55:
F_28 ( V_36 ) ;
return V_33 ;
}
static void F_29 ( struct V_4 * V_11 ,
struct V_4 * V_56 )
{
struct V_14 * V_15 = V_14 ( V_56 ) ;
if ( F_30 ( V_15 -> V_57 , V_11 -> V_58 ) )
return;
if ( ! F_30 ( V_56 -> V_58 , V_15 -> V_57 ) &&
F_30 ( V_56 -> V_58 , V_11 -> V_58 ) )
F_31 ( V_11 , V_56 -> V_58 ) ;
if ( F_30 ( V_56 -> V_58 , V_15 -> V_57 ) &&
! F_30 ( V_56 -> V_58 , V_11 -> V_58 ) )
F_32 ( V_11 , V_56 -> V_58 ) ;
memcpy ( V_15 -> V_57 , V_11 -> V_58 , V_59 ) ;
}
static void F_33 ( struct V_4 * V_11 ,
struct V_4 * V_56 )
{
V_56 -> V_60 = V_11 -> V_60 ;
if ( V_11 -> V_26 & V_61 )
V_56 -> V_62 = V_11 -> V_62 ;
else
V_56 -> V_62 = V_11 -> V_62 + V_63 ;
#if F_34 ( V_64 ) || F_34 ( V_65 )
V_56 -> V_66 = V_11 -> V_66 ;
#endif
F_35 ( V_56 ) ;
}
static void F_36 ( struct V_4 * V_11 , unsigned long V_67 )
{
switch ( V_67 ) {
case V_68 :
F_37 ( V_11 ) ;
if ( F_38 ( V_11 ) < 0 )
F_39 ( L_7 ,
V_11 -> V_22 ) ;
break;
case V_69 :
if ( F_38 ( V_11 ) < 0 )
F_39 ( L_8 , V_11 -> V_22 ) ;
break;
case V_70 :
F_37 ( V_11 ) ;
break;
}
}
static int F_40 ( struct V_71 * V_72 , unsigned long V_67 ,
void * V_73 )
{
struct V_4 * V_11 = V_73 ;
struct V_1 * V_18 ;
struct V_17 * V_17 ;
int V_74 , V_75 ;
struct V_4 * V_56 ;
struct V_14 * V_15 ;
F_41 ( V_76 ) ;
if ( F_42 ( V_11 ) )
F_36 ( V_11 , V_67 ) ;
if ( ( V_67 == V_77 ) &&
( V_11 -> V_26 & V_29 ) ) {
F_14 ( L_9 ,
V_11 -> V_22 ) ;
F_17 ( V_11 , 0 ) ;
}
V_17 = F_5 ( V_11 -> V_17 ) ;
if ( ! V_17 )
goto V_78;
V_18 = & V_17 -> V_18 ;
switch ( V_67 ) {
case V_79 :
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
F_21 ( V_11 , V_56 ) ;
}
break;
case V_81 :
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
V_75 = V_56 -> V_20 ;
if ( ! ( V_75 & V_82 ) )
continue;
F_29 ( V_11 , V_56 ) ;
}
break;
case V_83 :
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
if ( V_56 -> V_50 <= V_11 -> V_50 )
continue;
F_44 ( V_56 , V_11 -> V_50 ) ;
}
break;
case V_84 :
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
F_33 ( V_11 , V_56 ) ;
}
break;
case V_85 :
if ( V_11 -> V_26 & V_29 )
F_7 ( V_11 , 0 ) ;
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
V_75 = V_56 -> V_20 ;
if ( ! ( V_75 & V_82 ) )
continue;
V_15 = V_14 ( V_56 ) ;
if ( ! ( V_15 -> V_20 & V_86 ) )
F_45 ( V_56 , V_75 & ~ V_82 ) ;
F_21 ( V_11 , V_56 ) ;
}
break;
case V_77 :
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
V_75 = V_56 -> V_20 ;
if ( V_75 & V_82 )
continue;
V_15 = V_14 ( V_56 ) ;
if ( ! ( V_15 -> V_20 & V_86 ) )
F_45 ( V_56 , V_75 | V_82 ) ;
F_21 ( V_11 , V_56 ) ;
}
break;
case V_70 :
if ( V_11 -> V_87 != V_88 )
break;
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
if ( V_17 -> V_89 == 1 )
V_74 = V_80 ;
F_4 ( V_56 , & V_76 ) ;
}
F_46 ( & V_76 ) ;
break;
case V_90 :
if ( F_47 ( V_11 ) )
return V_91 ;
break;
case V_92 :
case V_93 :
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_56 = F_43 ( V_18 , V_74 ) ;
if ( ! V_56 )
continue;
F_48 ( V_67 , V_56 ) ;
}
break;
}
V_78:
return V_94 ;
}
static int F_49 ( struct V_37 * V_37 , void T_2 * V_95 )
{
int V_33 ;
struct V_96 args ;
struct V_4 * V_11 = NULL ;
if ( F_50 ( & args , V_95 , sizeof( struct V_96 ) ) )
return - V_97 ;
args . V_98 [ 23 ] = 0 ;
args . V_99 . V_100 [ 23 ] = 0 ;
F_51 () ;
switch ( args . V_101 ) {
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_33 = - V_109 ;
V_11 = F_52 ( V_37 , args . V_98 ) ;
if ( ! V_11 )
goto V_78;
V_33 = - V_110 ;
if ( args . V_101 != V_105 && ! F_42 ( V_11 ) )
goto V_78;
}
switch ( args . V_101 ) {
case V_102 :
V_33 = - V_111 ;
if ( ! F_53 ( V_112 ) )
break;
F_54 ( V_11 ,
args . V_99 . V_113 ,
args . V_114 ) ;
V_33 = 0 ;
break;
case V_103 :
V_33 = - V_111 ;
if ( ! F_53 ( V_112 ) )
break;
V_33 = F_55 ( V_11 ,
args . V_99 . V_113 ,
args . V_114 ) ;
break;
case V_104 :
V_33 = - V_111 ;
if ( ! F_53 ( V_112 ) )
break;
V_33 = F_56 ( V_11 ,
args . V_114 ? args . V_99 . V_115 : 0 ,
args . V_99 . V_115 ) ;
break;
case V_116 :
V_33 = - V_111 ;
if ( ! F_53 ( V_112 ) )
break;
if ( ( args . V_99 . V_44 >= 0 ) &&
( args . V_99 . V_44 < V_117 ) ) {
struct V_38 * V_39 ;
V_39 = F_25 ( V_37 , V_40 ) ;
V_39 -> V_44 = args . V_99 . V_44 ;
V_33 = 0 ;
} else {
V_33 = - V_110 ;
}
break;
case V_105 :
V_33 = - V_111 ;
if ( ! F_53 ( V_112 ) )
break;
V_33 = F_23 ( V_11 , args . V_99 . V_118 ) ;
break;
case V_106 :
V_33 = - V_111 ;
if ( ! F_53 ( V_112 ) )
break;
F_4 ( V_11 , NULL ) ;
V_33 = 0 ;
break;
case V_107 :
V_33 = 0 ;
F_57 ( V_11 , args . V_99 . V_100 ) ;
if ( F_58 ( V_95 , & args ,
sizeof( struct V_96 ) ) )
V_33 = - V_97 ;
break;
case V_108 :
V_33 = 0 ;
args . V_99 . V_118 = F_59 ( V_11 ) ;
if ( F_58 ( V_95 , & args ,
sizeof( struct V_96 ) ) )
V_33 = - V_97 ;
break;
default:
V_33 = - V_28 ;
break;
}
V_78:
F_60 () ;
return V_33 ;
}
static int T_3 F_61 ( struct V_37 * V_37 )
{
struct V_38 * V_39 = F_25 ( V_37 , V_40 ) ;
int V_33 ;
V_39 -> V_44 = V_47 ;
V_33 = F_62 ( V_37 ) ;
return V_33 ;
}
static void T_4 F_63 ( struct V_37 * V_37 )
{
F_64 ( V_37 ) ;
}
static int T_5 F_65 ( void )
{
int V_33 ;
F_14 ( L_10 , V_119 , V_120 ) ;
V_33 = F_66 ( & V_121 ) ;
if ( V_33 < 0 )
goto V_122;
V_33 = F_67 ( & V_123 ) ;
if ( V_33 < 0 )
goto V_124;
V_33 = F_68 () ;
if ( V_33 < 0 )
goto V_125;
V_33 = F_69 () ;
if ( V_33 < 0 )
goto V_126;
F_70 ( F_49 ) ;
return 0 ;
V_126:
F_71 () ;
V_125:
F_72 ( & V_123 ) ;
V_124:
F_73 ( & V_121 ) ;
V_122:
return V_33 ;
}
static void T_6 F_74 ( void )
{
F_70 ( NULL ) ;
F_75 () ;
F_72 ( & V_123 ) ;
F_73 ( & V_121 ) ;
F_76 () ;
F_71 () ;
}
