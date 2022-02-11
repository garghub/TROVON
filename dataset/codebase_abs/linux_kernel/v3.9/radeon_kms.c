int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_3 * V_4 ;
int V_7 , V_8 ;
V_4 = F_7 ( sizeof( struct V_3 ) , V_9 ) ;
if ( V_4 == NULL ) {
return - V_10 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_8 ( V_2 ) ) {
V_6 |= V_11 ;
} else if ( F_9 ( V_2 -> V_12 ) ) {
V_6 |= V_13 ;
} else {
V_6 |= V_14 ;
}
V_7 = F_10 ( V_4 , V_2 , V_2 -> V_12 , V_6 ) ;
if ( V_7 ) {
F_11 ( & V_2 -> V_12 -> V_2 , L_1 ) ;
goto V_15;
}
V_7 = F_12 ( V_4 ) ;
if ( V_7 )
F_11 ( & V_2 -> V_12 -> V_2 , L_2 ) ;
if ( ! V_7 ) {
V_8 = F_13 ( V_4 ) ;
if ( V_8 )
F_14 ( & V_2 -> V_12 -> V_2 ,
L_3 ) ;
}
V_15:
if ( V_7 )
F_1 ( V_2 ) ;
return V_7 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_16 * * V_17 ,
struct V_16 * V_18 ,
T_1 * V_19 )
{
F_16 ( & V_2 -> V_20 ) ;
if ( * V_19 == 1 ) {
if ( ! * V_17 )
* V_17 = V_18 ;
} else if ( * V_19 == 0 ) {
if ( * V_17 == V_18 )
* V_17 = NULL ;
}
* V_19 = * V_17 == V_18 ? 1 : 0 ;
F_17 ( & V_2 -> V_20 ) ;
}
int F_18 ( struct V_1 * V_2 , void * V_21 , struct V_16 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_21 ;
struct V_25 * V_26 = & V_4 -> V_27 ;
T_1 V_19 , * V_28 ;
T_2 V_29 , * V_30 ;
struct V_31 * V_32 ;
int V_33 , V_34 ;
if ( V_24 -> V_35 == V_36 ) {
if ( V_4 -> V_37 >= V_38 ) {
V_30 = ( T_2 * ) ( ( unsigned long ) V_24 -> V_19 ) ;
V_29 = F_19 ( V_4 ) ;
if ( F_20 ( V_30 , & V_29 , sizeof( V_29 ) ) ) {
F_21 ( L_4 , V_39 , __LINE__ ) ;
return - V_40 ;
}
return 0 ;
} else {
F_22 ( L_5 ) ;
return - V_41 ;
}
}
V_28 = ( T_1 * ) ( ( unsigned long ) V_24 -> V_19 ) ;
if ( F_23 ( & V_19 , V_28 , sizeof( V_19 ) ) ) {
F_21 ( L_6 , V_39 , __LINE__ ) ;
return - V_40 ;
}
switch ( V_24 -> V_35 ) {
case V_42 :
V_19 = V_2 -> V_43 ;
break;
case V_44 :
V_19 = V_4 -> V_45 ;
break;
case V_46 :
V_19 = V_4 -> V_47 ;
break;
case V_48 :
if ( ( V_4 -> V_37 >= V_49 ) && ( V_4 -> V_37 <= V_50 ) )
V_19 = false ;
else
V_19 = V_4 -> V_51 ;
break;
case V_52 :
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_4 -> V_53 ; V_33 ++ ) {
V_32 = (struct V_31 * ) V_26 -> V_54 [ V_33 ] ;
if ( V_32 && V_32 -> V_55 . V_56 == V_19 ) {
struct V_57 * V_57 = F_24 ( V_32 ) ;
V_19 = V_57 -> V_58 ;
V_34 = 1 ;
break;
}
}
if ( ! V_34 ) {
F_22 ( L_7 , V_19 ) ;
return - V_41 ;
}
break;
case V_59 :
V_19 = V_4 -> V_51 ;
break;
case V_60 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_64 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_64 ;
else if ( V_4 -> V_37 >= V_49 )
V_19 = V_4 -> V_62 . V_67 . V_64 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_64 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_64 ;
else {
F_22 ( L_8 ) ;
return - V_41 ;
}
break;
case V_71 :
if ( V_19 >= 2 ) {
F_22 ( L_9 , V_19 ) ;
return - V_41 ;
}
F_15 ( V_2 , & V_4 -> V_72 , V_22 , & V_19 ) ;
break;
case V_73 :
if ( V_19 >= 2 ) {
F_22 ( L_10 , V_19 ) ;
return - V_41 ;
}
F_15 ( V_2 , & V_4 -> V_74 , V_22 , & V_19 ) ;
break;
case V_75 :
if ( V_4 -> V_76 -> V_77 )
V_19 = F_25 ( V_4 ) * 10 ;
else
V_19 = V_4 -> clock . V_78 . V_79 * 10 ;
break;
case V_80 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_81 *
V_4 -> V_62 . V_63 . V_82 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_81 *
V_4 -> V_62 . V_66 . V_82 ;
else if ( V_4 -> V_37 >= V_49 )
V_19 = V_4 -> V_62 . V_67 . V_83 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_83 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_83 ;
else {
return - V_41 ;
}
break;
case V_84 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_85 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_85 ;
else if ( V_4 -> V_37 >= V_49 )
V_19 = V_4 -> V_62 . V_67 . V_85 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_85 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_85 ;
else {
return - V_41 ;
}
break;
case V_86 :
V_19 = 1 ;
break;
case V_87 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_88 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_88 ;
else if ( V_4 -> V_37 >= V_49 )
V_19 = V_4 -> V_62 . V_67 . V_88 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_88 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_88 ;
else {
return - V_41 ;
}
break;
case V_89 :
if ( V_4 -> V_37 < V_65 )
return - V_41 ;
V_19 = V_90 ;
break;
case V_91 :
if ( V_4 -> V_37 < V_65 )
return - V_41 ;
V_19 = V_92 ;
break;
case V_93 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_94 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_95 ;
else if ( V_4 -> V_37 >= V_49 )
V_19 = V_4 -> V_62 . V_67 . V_96 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_96 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_96 ;
else {
return - V_41 ;
}
break;
case V_97 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_82 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_82 ;
else if ( V_4 -> V_37 >= V_49 )
V_19 = V_4 -> V_62 . V_67 . V_98 ;
else
V_19 = 1 ;
break;
case V_99 :
if ( V_4 -> V_37 >= V_61 )
V_19 = V_4 -> V_62 . V_63 . V_100 ;
else
return - V_41 ;
break;
default:
F_22 ( L_11 , V_24 -> V_35 ) ;
return - V_41 ;
}
if ( F_20 ( V_28 , & V_19 , sizeof( T_1 ) ) ) {
F_21 ( L_4 , V_39 , __LINE__ ) ;
return - V_40 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 () ;
}
int F_29 ( struct V_1 * V_2 , struct V_16 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_101 -> V_102 = NULL ;
if ( V_4 -> V_37 >= V_65 ) {
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_7 ;
V_104 = F_7 ( sizeof( * V_104 ) , V_9 ) ;
if ( F_30 ( ! V_104 ) ) {
return - V_10 ;
}
F_31 ( V_4 , & V_104 -> V_107 ) ;
V_106 = F_32 ( V_4 , & V_104 -> V_107 ,
V_4 -> V_108 . V_109 ) ;
V_7 = F_33 ( V_4 , V_106 , V_110 ,
V_111 |
V_112 ) ;
if ( V_7 ) {
F_34 ( V_4 , & V_104 -> V_107 ) ;
F_5 ( V_104 ) ;
return V_7 ;
}
V_101 -> V_102 = V_104 ;
}
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
struct V_16 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_37 >= V_65 && V_101 -> V_102 ) {
struct V_103 * V_104 = V_101 -> V_102 ;
struct V_105 * V_106 ;
int V_7 ;
V_7 = F_36 ( V_4 -> V_108 . V_109 , false ) ;
if ( ! V_7 ) {
V_106 = F_37 ( & V_104 -> V_107 ,
V_4 -> V_108 . V_109 ) ;
if ( V_106 )
F_38 ( V_4 , V_106 ) ;
F_39 ( V_4 -> V_108 . V_109 ) ;
}
F_34 ( V_4 , & V_104 -> V_107 ) ;
F_5 ( V_104 ) ;
V_101 -> V_102 = NULL ;
}
}
void F_40 ( struct V_1 * V_2 ,
struct V_16 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_72 == V_101 )
V_4 -> V_72 = NULL ;
if ( V_4 -> V_74 == V_101 )
V_4 -> V_74 = NULL ;
}
T_3 F_41 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_32 < 0 || V_32 >= V_4 -> V_53 ) {
F_21 ( L_12 , V_32 ) ;
return - V_41 ;
}
return F_42 ( V_4 , V_32 ) ;
}
int F_43 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_113 ;
int V_7 ;
if ( V_32 < 0 || V_32 >= V_4 -> V_53 ) {
F_21 ( L_12 , V_32 ) ;
return - V_41 ;
}
F_44 ( & V_4 -> V_114 . V_115 , V_113 ) ;
V_4 -> V_114 . V_116 [ V_32 ] = true ;
V_7 = F_45 ( V_4 ) ;
F_46 ( & V_4 -> V_114 . V_115 , V_113 ) ;
return V_7 ;
}
void F_47 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_113 ;
if ( V_32 < 0 || V_32 >= V_4 -> V_53 ) {
F_21 ( L_12 , V_32 ) ;
return;
}
F_44 ( & V_4 -> V_114 . V_115 , V_113 ) ;
V_4 -> V_114 . V_116 [ V_32 ] = false ;
F_45 ( V_4 ) ;
F_46 ( & V_4 -> V_114 . V_115 , V_113 ) ;
}
int F_48 ( struct V_1 * V_2 , int V_32 ,
int * V_117 ,
struct V_118 * V_119 ,
unsigned V_6 )
{
struct V_31 * V_120 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_32 < 0 || V_32 >= V_2 -> V_121 ) {
F_21 ( L_12 , V_32 ) ;
return - V_41 ;
}
V_120 = & V_4 -> V_27 . V_54 [ V_32 ] -> V_55 ;
return F_49 ( V_2 , V_32 , V_117 ,
V_119 , V_6 ,
V_120 ) ;
}
int F_50 ( struct V_1 * V_2 , void * V_21 ,
struct V_16 * V_101 )
{
return - V_41 ;
}
