static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_2 -> V_3 ) ;
}
int F_5 ( T_1 V_4 , struct V_5 const * V_6 ,
T_1 V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_13 * V_15 = NULL ;
struct V_16 V_17 = { 0 , NULL , } ;
struct V_1 * V_18 = F_6 ( V_4 ) ;
int V_19 ;
int V_20 ;
if ( F_7 ( ! V_18 ) )
return - V_21 ;
V_12 = & V_18 -> V_3 ;
F_8 ( V_12 , V_22 ) ;
F_9 ( V_12 , V_23 ) ;
F_10 ( V_12 , 0 ) ;
F_11 ( V_12 , 0 ) ;
F_12 ( V_12 , V_6 -> type ) ;
F_13 ( V_12 , V_6 -> V_24 ) ;
F_14 ( V_12 , V_6 -> V_25 ) ;
F_15 ( V_12 , V_26 ) ;
V_20 = F_16 ( V_12 , V_9 , V_7 , V_10 , V_27 ,
! V_18 -> V_28 , & V_14 ) ;
if ( F_7 ( ! V_14 ) )
return V_20 ;
V_19 = F_17 ( V_6 -> type , V_6 -> V_24 , V_6 -> V_25 ,
V_29 , & V_17 ) ;
if ( V_19 ) {
if ( V_17 . V_30 != 0 ) {
V_15 = F_18 ( V_14 , V_31 ) ;
if ( V_15 == NULL ) {
F_19 ( & V_17 ) ;
F_20 ( V_14 ) ;
return - V_32 ;
}
}
V_20 = F_21 ( V_14 ) ;
if ( ( V_20 < 0 ) && ( V_17 . V_30 != 0 ) )
F_20 ( V_15 ) ;
} else {
V_15 = V_14 ;
}
if ( V_20 >= 0 ) {
if ( V_15 )
F_22 ( V_15 , & V_17 ) ;
} else {
F_19 ( & V_17 ) ;
}
return V_20 ;
}
void F_22 ( struct V_13 * V_14 , struct V_16 * V_33 )
{
struct V_11 * V_34 ;
struct V_16 V_17 = { 0 , NULL , } ;
struct V_16 * V_35 = V_33 ;
int V_36 = 0 ;
V_34 = F_23 ( V_14 ) ;
if ( V_33 == NULL ) {
F_17 ( F_24 ( V_34 ) ,
F_25 ( V_34 ) ,
F_26 ( V_34 ) ,
V_23 ,
& V_17 ) ;
V_35 = V_33 = & V_17 ;
}
if ( V_33 -> V_30 != 0 ) {
F_11 ( V_34 , V_37 ) ;
if ( V_33 -> V_30 == 1 ) {
F_10 ( V_34 , V_33 -> V_38 [ 0 ] ) ;
F_27 ( V_14 ) ;
F_19 ( V_33 ) ;
return;
}
for (; V_36 < V_33 -> V_30 ; V_36 ++ ) {
int V_39 = V_36 % V_40 ;
struct V_13 * V_41 = F_28 ( V_14 , V_31 ) ;
if ( V_41 == NULL ) {
F_29 ( L_1 ) ;
goto exit;
}
if ( ( V_39 == 0 ) && ( V_36 != 0 ) )
V_35 = V_35 -> V_42 ;
F_10 ( F_23 ( V_41 ) , V_35 -> V_38 [ V_39 ] ) ;
F_27 ( V_41 ) ;
}
}
exit:
F_20 ( V_14 ) ;
F_19 ( V_33 ) ;
}
struct V_1 * F_30 ( void * V_43 ,
T_1 (* F_31)( struct V_1 * , struct V_13 * ) ,
void (* F_32)( struct V_1 * ) ,
const T_1 V_44 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
T_1 V_4 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_29 ( L_2 ) ;
return NULL ;
}
V_4 = F_34 ( V_2 , & V_2 -> V_45 ) ;
if ( ! V_4 ) {
F_29 ( L_3 ) ;
F_35 ( V_2 ) ;
return NULL ;
}
V_2 -> V_43 = V_43 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_4 = V_4 ;
V_34 = & V_2 -> V_3 ;
F_36 ( V_34 , V_44 , V_48 , V_49 , 0 ) ;
F_37 ( V_34 , V_4 ) ;
F_38 ( & V_2 -> V_50 ) ;
F_38 ( & V_2 -> V_51 . V_52 ) ;
V_2 -> F_31 = F_31 ;
V_2 -> F_32 = F_32 ;
V_2 -> V_28 = NULL ;
F_39 ( & V_2 -> V_53 , ( V_54 ) V_55 , V_4 ) ;
F_40 ( & V_56 ) ;
F_38 ( & V_2 -> V_57 ) ;
F_38 ( & V_2 -> V_16 ) ;
F_41 ( & V_2 -> V_16 , & V_38 ) ;
F_42 ( & V_56 ) ;
return V_2 ;
}
int F_43 ( T_1 V_4 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = NULL ;
F_44 ( V_4 , 0 , NULL ) ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_46 ( V_4 ) ;
F_47 ( V_2 ) ;
F_48 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_58 ) {
V_14 = F_49 ( V_2 , V_59 ) ;
F_50 ( & V_2 -> V_51 ) ;
}
F_35 ( V_2 -> V_28 ) ;
F_40 ( & V_56 ) ;
F_51 ( & V_2 -> V_16 ) ;
F_51 ( & V_2 -> V_50 ) ;
F_42 ( & V_56 ) ;
F_52 ( & V_2 -> V_53 ) ;
F_35 ( V_2 ) ;
F_53 ( V_14 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
return F_55 ( & V_2 -> V_3 ) ;
}
int F_56 ( T_1 V_4 , unsigned int * V_60 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
* V_60 = F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_57 ( T_1 V_4 , unsigned int V_60 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_58 ( & V_2 -> V_3 , ( V_60 != 0 ) ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
return F_60 ( & V_2 -> V_3 ) ;
}
int F_61 ( T_1 V_4 , unsigned int * V_61 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
* V_61 = F_59 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_62 ( T_1 V_4 , unsigned int V_61 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_63 ( & V_2 -> V_3 , ( V_61 != 0 ) ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static struct V_13 * F_64 ( T_1 V_62 , T_1 V_63 ,
T_1 V_64 , T_1 V_65 ,
T_1 V_66 , T_1 type , T_1 V_67 ,
T_1 V_68 )
{
struct V_13 * V_14 ;
struct V_11 * V_34 ;
V_14 = F_65 ( V_49 ) ;
if ( V_14 ) {
V_34 = F_23 ( V_14 ) ;
F_36 ( V_34 , V_66 , type , V_49 , V_63 ) ;
F_66 ( V_34 , V_67 ) ;
F_10 ( V_34 , V_62 ) ;
F_37 ( V_34 , V_64 ) ;
F_67 ( V_34 , V_65 ) ;
F_68 ( V_34 , V_68 ) ;
}
return V_14 ;
}
int F_69 ( struct V_13 * V_14 , T_1 V_67 )
{
struct V_11 * V_34 = F_23 ( V_14 ) ;
struct V_13 * V_69 ;
struct V_11 * V_70 ;
int V_71 ;
T_1 V_72 = F_70 ( V_34 ) ;
T_1 V_73 = F_71 ( V_34 ) ;
if ( V_73 > V_74 )
V_73 = V_74 ;
if ( F_72 ( V_34 ) && ( V_72 < V_75 ) )
V_72 ++ ;
if ( F_73 ( V_34 ) || F_60 ( V_34 ) ) {
F_20 ( V_14 ) ;
return V_73 ;
}
if ( F_74 ( V_34 ) )
V_71 = V_26 ;
else
V_71 = V_49 ;
V_69 = F_65 ( V_73 + V_71 ) ;
if ( V_69 == NULL ) {
F_20 ( V_14 ) ;
return V_73 ;
}
V_70 = F_23 ( V_69 ) ;
F_36 ( V_70 , V_72 , F_75 ( V_34 ) , V_71 , F_76 ( V_34 ) ) ;
F_66 ( V_70 , V_67 ) ;
F_10 ( V_70 , F_77 ( V_34 ) ) ;
F_37 ( V_70 , F_4 ( V_34 ) ) ;
if ( F_78 ( V_34 ) ) {
F_67 ( V_70 , V_37 ) ;
} else {
F_67 ( V_70 , F_2 ( V_34 ) ) ;
F_12 ( V_70 , F_24 ( V_34 ) ) ;
F_79 ( V_70 , F_80 ( V_34 ) ) ;
}
F_81 ( V_70 , V_73 + V_71 ) ;
F_82 ( V_69 , V_71 , F_83 ( V_34 ) , V_73 ) ;
if ( F_72 ( V_34 ) ) {
struct V_13 * V_76 = NULL ;
struct V_1 * V_2 = F_45 ( F_4 ( V_34 ) ) ;
if ( V_2 ) {
if ( V_2 -> V_58 )
V_76 = F_84 ( V_2 , V_67 ) ;
F_47 ( V_2 ) ;
}
F_53 ( V_76 ) ;
}
F_20 ( V_14 ) ;
F_53 ( V_69 ) ;
return V_73 ;
}
int F_85 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_8 const * V_9 , T_1 V_7 ,
unsigned int V_10 , int V_67 )
{
struct V_13 * V_14 ;
int V_20 ;
V_20 = F_16 ( V_12 , V_9 , V_7 , V_10 , V_27 ,
! V_2 -> V_28 , & V_14 ) ;
if ( ! V_14 )
return V_20 ;
return F_69 ( V_14 , V_67 ) ;
}
static void V_55 ( unsigned long V_4 )
{
struct V_1 * V_2 = F_45 ( V_4 ) ;
struct V_13 * V_14 = NULL ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_58 ) {
F_47 ( V_2 ) ;
return;
}
if ( V_2 -> V_77 == V_78 ) {
V_14 = F_84 ( V_2 , V_59 ) ;
} else {
V_14 = F_64 ( F_3 ( V_2 ) ,
F_1 ( V_2 ) ,
V_2 -> V_4 ,
V_37 ,
V_79 ,
V_80 ,
V_81 ,
0 ) ;
V_2 -> V_77 = V_78 ;
F_86 ( & V_2 -> V_53 , V_2 -> V_82 ) ;
}
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
}
static void F_87 ( unsigned long V_4 )
{
struct V_1 * V_2 = F_45 ( V_4 ) ;
struct V_13 * V_14 = NULL ;
if ( ! V_2 )
return;
V_14 = F_84 ( V_2 , V_83 ) ;
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
}
static struct V_13 * F_84 ( struct V_1 * V_2 , T_1 V_67 )
{
T_1 V_72 = F_70 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_58 )
return NULL ;
if ( V_72 < V_75 )
V_72 ++ ;
return F_64 ( V_2 -> V_4 ,
V_37 ,
F_3 ( V_2 ) ,
F_1 ( V_2 ) ,
V_72 ,
V_84 ,
V_67 ,
0 ) ;
}
static struct V_13 * F_49 ( struct V_1 * V_2 , T_1 V_67 )
{
T_1 V_72 = F_70 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_58 )
return NULL ;
if ( V_72 < V_75 )
V_72 ++ ;
return F_64 ( F_3 ( V_2 ) ,
F_1 ( V_2 ) ,
V_2 -> V_4 ,
V_37 ,
V_72 ,
V_84 ,
V_67 ,
0 ) ;
}
void F_88 ( struct V_13 * V_14 )
{
struct V_11 * V_34 = F_23 ( V_14 ) ;
struct V_1 * V_2 = F_45 ( F_4 ( V_34 ) ) ;
T_1 V_67 = V_81 ;
struct V_13 * V_85 = NULL ;
struct V_13 * V_86 = NULL ;
if ( ! V_2 ) {
V_67 = V_59 ;
} else if ( V_2 -> V_58 ) {
if ( ( F_1 ( V_2 ) != F_76 ( V_34 ) ) ||
( F_3 ( V_2 ) != F_77 ( V_34 ) ) ) {
V_67 = V_59 ;
} else if ( F_75 ( V_34 ) == V_87 ) {
int F_32 = F_89 ( V_2 ) &&
V_2 -> V_88 &&
V_2 -> F_32 ;
V_2 -> V_89 += F_90 ( V_34 ) ;
if ( F_89 ( V_2 ) )
goto exit;
V_2 -> V_88 = 0 ;
if ( ! F_32 )
goto exit;
V_2 -> F_32 ( V_2 ) ;
goto exit;
}
} else if ( V_2 -> V_90 ) {
V_67 = V_59 ;
}
if ( V_67 ) {
V_85 = F_64 ( F_77 ( V_34 ) ,
F_76 ( V_34 ) ,
F_4 ( V_34 ) ,
V_37 ,
V_91 ,
V_84 ,
V_67 ,
0 ) ;
goto exit;
}
if ( F_75 ( V_34 ) == V_80 ) {
V_85 = F_64 ( F_77 ( V_34 ) ,
F_76 ( V_34 ) ,
F_4 ( V_34 ) ,
V_37 ,
V_79 ,
V_92 ,
V_81 ,
0 ) ;
}
V_2 -> V_77 = V_93 ;
exit:
if ( V_2 )
F_47 ( V_2 ) ;
F_53 ( V_85 ) ;
F_53 ( V_86 ) ;
F_20 ( V_14 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_94 * V_14 , int V_95 )
{
struct V_96 * V_97 ;
if ( V_95 )
F_92 ( V_14 , L_4 ,
F_93 ( V_37 ) , F_94 ( V_37 ) ,
F_95 ( V_37 ) , V_2 -> V_4 ) ;
else
F_92 ( V_14 , L_5 , V_2 -> V_4 ) ;
if ( V_2 -> V_58 ) {
T_1 V_98 = F_3 ( V_2 ) ;
T_1 V_63 = F_1 ( V_2 ) ;
F_92 ( V_14 , L_6 ,
F_93 ( V_63 ) , F_94 ( V_63 ) ,
F_95 ( V_63 ) , V_98 ) ;
if ( V_2 -> V_99 != 0 )
F_92 ( V_14 , L_7 ,
V_2 -> V_99 ,
V_2 -> V_100 ) ;
} else if ( V_2 -> V_90 ) {
F_92 ( V_14 , L_8 ) ;
F_96 (publ, &p_ptr->publications, pport_list) {
if ( V_97 -> V_24 == V_97 -> V_25 )
F_92 ( V_14 , L_9 , V_97 -> type ,
V_97 -> V_24 ) ;
else
F_92 ( V_14 , L_10 , V_97 -> type ,
V_97 -> V_24 , V_97 -> V_25 ) ;
}
}
F_92 ( V_14 , L_11 ) ;
}
struct V_13 * F_97 ( void )
{
struct V_13 * V_14 ;
struct V_101 * V_102 ;
struct V_94 V_103 ;
struct V_1 * V_2 ;
int V_104 ;
V_14 = F_98 ( F_99 ( V_105 ) ) ;
if ( ! V_14 )
return NULL ;
V_102 = (struct V_101 * ) V_14 -> V_106 ;
F_100 ( & V_103 , F_101 ( V_102 ) , V_105 ) ;
F_40 ( & V_56 ) ;
F_96 (p_ptr, &ports, port_list) {
F_40 ( V_2 -> V_45 ) ;
F_91 ( V_2 , & V_103 , 0 ) ;
F_42 ( V_2 -> V_45 ) ;
}
F_42 ( & V_56 ) ;
V_104 = F_102 ( & V_103 ) ;
F_103 ( V_14 , F_99 ( V_104 ) ) ;
F_104 ( V_102 , V_107 , NULL , V_104 ) ;
return V_14 ;
}
void F_105 ( void )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
F_40 ( & V_56 ) ;
F_96 (p_ptr, &ports, port_list) {
V_34 = & V_2 -> V_3 ;
if ( F_76 ( V_34 ) == V_37 )
break;
F_106 ( V_34 , V_37 ) ;
F_67 ( V_34 , V_37 ) ;
}
F_42 ( & V_56 ) ;
}
static void F_107 ( void * V_108 )
{
struct V_13 * V_14 ;
F_40 ( & V_109 ) ;
V_14 = V_110 ;
V_110 = NULL ;
F_42 ( & V_109 ) ;
while ( V_14 ) {
struct V_1 * V_2 ;
struct V_28 * V_111 ;
struct V_112 V_113 ;
struct V_5 V_114 ;
void * V_43 ;
int V_58 ;
int V_90 ;
T_1 V_115 ;
struct V_13 * V_42 = V_14 -> V_42 ;
struct V_11 * V_34 = F_23 ( V_14 ) ;
T_1 V_116 = F_4 ( V_34 ) ;
V_115 = F_75 ( V_34 ) ;
if ( V_115 > V_117 )
goto V_118;
V_2 = F_45 ( V_116 ) ;
if ( ! V_2 )
goto V_118;
V_113 . V_4 = F_77 ( V_34 ) ;
V_113 . V_119 = F_76 ( V_34 ) ;
V_111 = V_2 -> V_28 ;
V_43 = V_111 -> V_43 ;
V_58 = V_2 -> V_58 ;
V_90 = V_2 -> V_90 ;
if ( F_7 ( F_73 ( V_34 ) ) )
goto V_67;
switch ( V_115 ) {
case V_84 : {
T_2 V_120 = V_111 -> V_121 ;
T_1 V_122 = F_3 ( V_2 ) ;
T_1 V_123 = F_1 ( V_2 ) ;
T_1 V_124 ;
F_47 ( V_2 ) ;
if ( F_7 ( ! V_120 ) )
goto V_118;
if ( F_7 ( ! V_58 ) ) {
if ( F_108 ( V_116 , & V_113 ) )
goto V_118;
} else if ( ( F_77 ( V_34 ) != V_122 ) ||
( F_76 ( V_34 ) != V_123 ) )
goto V_118;
V_124 = F_71 ( V_34 ) ;
if ( F_7 ( V_124 &&
( ++ V_2 -> V_125 >=
V_126 ) ) )
F_109 ( V_116 ,
V_2 -> V_125 ) ;
F_110 ( V_14 , F_111 ( V_34 ) ) ;
V_120 ( V_43 , V_116 , & V_14 , F_83 ( V_34 ) , V_124 ) ;
break;
}
case V_117 : {
T_3 V_120 = V_111 -> V_127 ;
F_47 ( V_2 ) ;
if ( F_7 ( ! V_120 || V_58 ) )
goto V_118;
F_110 ( V_14 , F_111 ( V_34 ) ) ;
V_120 ( V_43 , V_116 , & V_14 , F_83 ( V_34 ) ,
F_71 ( V_34 ) , F_70 ( V_34 ) ,
& V_113 ) ;
break;
}
case V_22 :
case V_48 : {
T_4 V_120 = V_111 -> V_128 ;
F_47 ( V_2 ) ;
if ( F_7 ( ! V_120 || V_58 || ! V_90 ) )
goto V_118;
V_114 . type = F_24 ( V_34 ) ;
V_114 . V_24 = F_80 ( V_34 ) ;
V_114 . V_25 = ( V_115 == V_48 )
? V_114 . V_24 : F_26 ( V_34 ) ;
F_110 ( V_14 , F_111 ( V_34 ) ) ;
V_120 ( V_43 , V_116 , & V_14 , F_83 ( V_34 ) ,
F_71 ( V_34 ) , F_70 ( V_34 ) ,
& V_113 , & V_114 ) ;
break;
}
}
if ( V_14 )
F_20 ( V_14 ) ;
V_14 = V_42 ;
continue;
V_67:
switch ( V_115 ) {
case V_84 : {
T_5 V_120 =
V_111 -> V_129 ;
T_1 V_122 = F_3 ( V_2 ) ;
T_1 V_123 = F_1 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( ! V_120 || ! V_58 )
break;
if ( ( F_77 ( V_34 ) != V_122 ) ||
( F_76 ( V_34 ) != V_123 ) )
break;
F_112 ( V_116 ) ;
F_110 ( V_14 , F_111 ( V_34 ) ) ;
V_120 ( V_43 , V_116 , & V_14 , F_83 ( V_34 ) ,
F_71 ( V_34 ) , F_73 ( V_34 ) ) ;
break;
}
case V_117 : {
T_6 V_120 = V_111 -> V_130 ;
F_47 ( V_2 ) ;
if ( ! V_120 || V_58 )
break;
F_110 ( V_14 , F_111 ( V_34 ) ) ;
V_120 ( V_43 , V_116 , & V_14 , F_83 ( V_34 ) ,
F_71 ( V_34 ) , F_73 ( V_34 ) , & V_113 ) ;
break;
}
case V_22 :
case V_48 : {
T_7 V_120 =
V_111 -> V_131 ;
F_47 ( V_2 ) ;
if ( ! V_120 || V_58 )
break;
V_114 . type = F_24 ( V_34 ) ;
V_114 . V_24 = F_80 ( V_34 ) ;
V_114 . V_25 = ( V_115 == V_48 )
? V_114 . V_24 : F_26 ( V_34 ) ;
F_110 ( V_14 , F_111 ( V_34 ) ) ;
V_120 ( V_43 , V_116 , & V_14 , F_83 ( V_34 ) ,
F_71 ( V_34 ) , F_73 ( V_34 ) , & V_114 ) ;
break;
}
}
if ( V_14 )
F_20 ( V_14 ) ;
V_14 = V_42 ;
continue;
V_118:
F_69 ( V_14 , V_59 ) ;
V_14 = V_42 ;
}
}
static T_1 F_113 ( struct V_1 * V_108 , struct V_13 * V_14 )
{
V_14 -> V_42 = NULL ;
F_40 ( & V_109 ) ;
if ( V_110 ) {
V_132 -> V_42 = V_14 ;
V_132 = V_14 ;
} else {
V_132 = V_110 = V_14 ;
F_114 ( ( V_54 ) F_107 , 0 ) ;
}
F_42 ( & V_109 ) ;
return 0 ;
}
static void F_115 ( unsigned long V_4 )
{
struct V_1 * V_2 ;
struct V_28 * V_111 ;
T_8 V_120 = NULL ;
void * V_133 = NULL ;
V_2 = F_45 ( V_4 ) ;
if ( V_2 ) {
V_111 = V_2 -> V_28 ;
if ( V_111 ) {
V_120 = V_111 -> V_134 ;
V_133 = V_111 -> V_43 ;
}
F_47 ( V_2 ) ;
}
if ( V_120 )
V_120 ( V_133 , V_4 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_114 ( ( V_54 ) F_115 , V_2 -> V_4 ) ;
}
void F_109 ( T_1 V_4 , T_1 V_68 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = NULL ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return;
if ( V_2 -> V_58 ) {
V_2 -> V_125 -= V_68 ;
V_14 = F_64 ( F_3 ( V_2 ) ,
F_1 ( V_2 ) ,
V_4 ,
V_37 ,
V_79 ,
V_87 ,
V_81 ,
V_68 ) ;
}
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
}
int F_117 ( void * V_43 ,
unsigned int V_44 ,
T_6 V_135 ,
T_7 V_136 ,
T_5 V_137 ,
T_3 V_127 ,
T_4 V_128 ,
T_2 V_121 ,
T_8 V_134 ,
T_1 * V_138 )
{
struct V_28 * V_111 ;
struct V_1 * V_2 ;
V_111 = F_118 ( sizeof( * V_111 ) , V_31 ) ;
if ( ! V_111 ) {
F_29 ( L_2 ) ;
return - V_32 ;
}
V_2 = (struct V_1 * ) F_30 ( NULL , F_113 ,
F_116 , V_44 ) ;
if ( ! V_2 ) {
F_35 ( V_111 ) ;
return - V_32 ;
}
V_2 -> V_28 = V_111 ;
V_111 -> V_43 = V_43 ;
V_111 -> V_4 = V_2 -> V_4 ;
V_111 -> V_130 = V_135 ;
V_111 -> V_131 = V_136 ;
V_111 -> V_129 = V_137 ;
V_111 -> V_127 = V_127 ;
V_111 -> V_128 = V_128 ;
V_111 -> V_121 = V_121 ;
V_111 -> V_134 = V_134 ;
* V_138 = V_2 -> V_4 ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_119 ( T_1 V_4 , unsigned int * V_44 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
* V_44 = ( unsigned int ) F_70 ( & V_2 -> V_3 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_120 ( T_1 V_4 , unsigned int V_72 )
{
struct V_1 * V_2 ;
if ( V_72 > V_75 )
return - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_121 ( & V_2 -> V_3 , ( T_1 ) V_72 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_122 ( T_1 V_4 , unsigned int V_139 , struct V_5 const * V_6 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 ;
T_1 V_140 ;
int V_20 = - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( V_2 -> V_58 )
goto exit;
if ( V_6 -> V_24 > V_6 -> V_25 )
goto exit;
if ( ( V_139 < V_141 ) || ( V_139 > V_29 ) )
goto exit;
V_140 = V_4 + V_2 -> V_142 + 1 ;
if ( V_140 == V_4 ) {
V_20 = - V_143 ;
goto exit;
}
V_97 = F_123 ( V_6 -> type , V_6 -> V_24 , V_6 -> V_25 ,
V_139 , V_2 -> V_4 , V_140 ) ;
if ( V_97 ) {
F_124 ( & V_97 -> V_144 , & V_2 -> V_57 ) ;
V_2 -> V_142 ++ ;
V_2 -> V_90 = 1 ;
V_20 = 0 ;
}
exit:
F_47 ( V_2 ) ;
return V_20 ;
}
int F_44 ( T_1 V_4 , unsigned int V_139 , struct V_5 const * V_6 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 ;
struct V_96 * V_145 ;
int V_20 = - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( ! V_6 ) {
F_125 (publ, tpubl,
&p_ptr->publications, pport_list) {
F_126 ( V_97 -> type , V_97 -> V_24 ,
V_97 -> V_4 , V_97 -> V_140 ) ;
}
V_20 = 0 ;
} else {
F_125 (publ, tpubl,
&p_ptr->publications, pport_list) {
if ( V_97 -> V_139 != V_139 )
continue;
if ( V_97 -> type != V_6 -> type )
continue;
if ( V_97 -> V_24 != V_6 -> V_24 )
continue;
if ( V_97 -> V_25 != V_6 -> V_25 )
break;
F_126 ( V_97 -> type , V_97 -> V_24 ,
V_97 -> V_4 , V_97 -> V_140 ) ;
V_20 = 0 ;
break;
}
}
if ( F_127 ( & V_2 -> V_57 ) )
V_2 -> V_90 = 0 ;
F_47 ( V_2 ) ;
return V_20 ;
}
int F_108 ( T_1 V_4 , struct V_112 const * V_146 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
int V_20 = - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( V_2 -> V_90 || V_2 -> V_58 )
goto exit;
if ( ! V_146 -> V_4 )
goto exit;
V_34 = & V_2 -> V_3 ;
F_11 ( V_34 , V_146 -> V_119 ) ;
F_10 ( V_34 , V_146 -> V_4 ) ;
F_67 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_2 -> V_4 ) ;
F_8 ( V_34 , V_84 ) ;
F_9 ( V_34 , 0 ) ;
F_15 ( V_34 , V_147 ) ;
V_2 -> V_82 = V_148 ;
V_2 -> V_77 = V_93 ;
V_2 -> V_58 = 1 ;
F_86 ( & V_2 -> V_53 , V_2 -> V_82 ) ;
F_128 ( & V_2 -> V_51 , V_146 -> V_119 ,
( void * ) ( unsigned long ) V_4 ,
( V_149 ) F_87 ) ;
V_20 = 0 ;
exit:
F_47 ( V_2 ) ;
V_2 -> V_46 = F_129 ( V_146 -> V_119 , V_4 ) ;
return V_20 ;
}
int F_130 ( struct V_1 * V_150 )
{
int V_20 ;
if ( V_150 -> V_58 ) {
V_150 -> V_58 = 0 ;
F_50 (
& ( (struct V_1 * ) V_150 ) -> V_51 ) ;
V_20 = 0 ;
} else {
V_20 = - V_151 ;
}
return V_20 ;
}
int F_112 ( T_1 V_4 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
V_20 = F_130 ( (struct V_1 * ) V_2 ) ;
F_47 ( V_2 ) ;
return V_20 ;
}
int F_131 ( T_1 V_4 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = NULL ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( V_2 -> V_58 ) {
T_1 V_72 = F_70 ( & V_2 -> V_3 ) ;
if ( V_72 < V_75 )
V_72 ++ ;
V_14 = F_64 ( F_3 ( V_2 ) ,
F_1 ( V_2 ) ,
V_4 ,
V_37 ,
V_72 ,
V_84 ,
V_152 ,
0 ) ;
}
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
return F_112 ( V_4 ) ;
}
static int F_132 ( struct V_1 * V_153 , unsigned int V_7 ,
struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_13 * V_14 ;
int V_20 ;
V_20 = F_16 ( & V_153 -> V_3 , V_9 , V_7 , V_10 ,
V_27 , ! V_153 -> V_28 , & V_14 ) ;
if ( F_133 ( V_14 ) )
F_27 ( V_14 ) ;
return V_20 ;
}
int F_134 ( T_1 V_4 , unsigned int V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 ;
T_1 V_63 ;
int V_20 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || ! V_2 -> V_58 )
return - V_21 ;
V_2 -> V_88 = 1 ;
if ( ! F_89 ( V_2 ) ) {
V_63 = F_1 ( V_2 ) ;
if ( F_133 ( V_63 != V_37 ) )
V_20 = F_135 ( V_2 , V_9 , V_7 ,
V_10 , V_63 ) ;
else
V_20 = F_132 ( V_2 , V_7 , V_9 ,
V_10 ) ;
if ( F_133 ( V_20 != - V_154 ) ) {
V_2 -> V_88 = 0 ;
if ( V_20 > 0 )
V_2 -> V_155 ++ ;
return V_20 ;
}
}
if ( F_54 ( V_2 ) ) {
V_2 -> V_88 = 0 ;
return V_10 ;
}
return - V_154 ;
}
int F_136 ( T_1 V_4 , struct V_156 const * V_157 , unsigned int V_158 ,
unsigned int V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
T_1 V_63 = V_158 ;
T_1 V_62 ;
int V_20 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || V_2 -> V_58 )
return - V_21 ;
V_34 = & V_2 -> V_3 ;
F_8 ( V_34 , V_48 ) ;
F_67 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_4 ) ;
F_15 ( V_34 , V_49 ) ;
F_12 ( V_34 , V_157 -> type ) ;
F_79 ( V_34 , V_157 -> V_159 ) ;
F_9 ( V_34 , F_137 ( V_158 ) ) ;
V_62 = F_138 ( V_157 -> type , V_157 -> V_159 , & V_63 ) ;
F_11 ( V_34 , V_63 ) ;
F_10 ( V_34 , V_62 ) ;
if ( F_133 ( V_62 ) ) {
if ( F_133 ( V_63 == V_37 ) )
V_20 = F_132 ( V_2 , V_7 ,
V_9 , V_10 ) ;
else
V_20 = F_135 ( V_2 , V_9 ,
V_7 , V_10 ,
V_63 ) ;
if ( F_133 ( V_20 != - V_154 ) ) {
if ( V_20 > 0 )
V_2 -> V_155 ++ ;
return V_20 ;
}
if ( F_54 ( V_2 ) ) {
return V_10 ;
}
return - V_154 ;
}
return F_85 ( V_2 , V_34 , V_9 , V_7 ,
V_10 , V_160 ) ;
}
int F_139 ( T_1 V_4 , struct V_112 const * V_161 ,
unsigned int V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
int V_20 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || V_2 -> V_58 )
return - V_21 ;
V_34 = & V_2 -> V_3 ;
F_8 ( V_34 , V_117 ) ;
F_9 ( V_34 , 0 ) ;
F_67 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_4 ) ;
F_11 ( V_34 , V_161 -> V_119 ) ;
F_10 ( V_34 , V_161 -> V_4 ) ;
F_15 ( V_34 , V_162 ) ;
if ( V_161 -> V_119 == V_37 )
V_20 = F_132 ( V_2 , V_7 , V_9 ,
V_10 ) ;
else
V_20 = F_135 ( V_2 , V_9 , V_7 ,
V_10 , V_161 -> V_119 ) ;
if ( F_133 ( V_20 != - V_154 ) ) {
if ( V_20 > 0 )
V_2 -> V_155 ++ ;
return V_20 ;
}
if ( F_54 ( V_2 ) ) {
return V_10 ;
}
return - V_154 ;
}
int F_140 ( T_1 V_4 , struct V_112 const * V_161 ,
struct V_13 * V_14 , unsigned int V_124 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
int V_20 ;
V_2 = (struct V_1 * ) F_141 ( V_4 ) ;
if ( ! V_2 || V_2 -> V_58 )
return - V_21 ;
V_34 = & V_2 -> V_3 ;
F_8 ( V_34 , V_117 ) ;
F_67 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_4 ) ;
F_11 ( V_34 , V_161 -> V_119 ) ;
F_10 ( V_34 , V_161 -> V_4 ) ;
F_15 ( V_34 , V_162 ) ;
F_81 ( V_34 , V_162 + V_124 ) ;
if ( F_142 ( V_14 , V_162 ) )
return - V_32 ;
F_143 ( V_14 , V_162 ) ;
F_144 ( V_14 , V_34 , V_162 ) ;
if ( V_161 -> V_119 == V_37 )
V_20 = F_27 ( V_14 ) ;
else
V_20 = F_145 ( V_14 , V_161 -> V_119 ) ;
if ( F_133 ( V_20 != - V_154 ) ) {
if ( V_20 > 0 )
V_2 -> V_155 ++ ;
return V_20 ;
}
if ( F_54 ( V_2 ) )
return V_124 ;
return - V_154 ;
}
