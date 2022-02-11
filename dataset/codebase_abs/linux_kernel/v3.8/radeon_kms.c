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
if ( V_4 -> V_37 >= V_39 ) {
V_29 = F_19 ( V_4 ) ;
} else {
V_29 = F_20 ( V_4 ) ;
}
if ( F_21 ( V_30 , & V_29 , sizeof( V_29 ) ) ) {
F_22 ( L_4 , V_40 , __LINE__ ) ;
return - V_41 ;
}
return 0 ;
} else {
F_23 ( L_5 ) ;
return - V_42 ;
}
}
V_28 = ( T_1 * ) ( ( unsigned long ) V_24 -> V_19 ) ;
if ( F_24 ( & V_19 , V_28 , sizeof( V_19 ) ) ) {
F_22 ( L_6 , V_40 , __LINE__ ) ;
return - V_41 ;
}
switch ( V_24 -> V_35 ) {
case V_43 :
V_19 = V_2 -> V_44 ;
break;
case V_45 :
V_19 = V_4 -> V_46 ;
break;
case V_47 :
V_19 = V_4 -> V_48 ;
break;
case V_49 :
if ( ( V_4 -> V_37 >= V_50 ) && ( V_4 -> V_37 <= V_51 ) )
V_19 = false ;
else
V_19 = V_4 -> V_52 ;
break;
case V_53 :
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_4 -> V_54 ; V_33 ++ ) {
V_32 = (struct V_31 * ) V_26 -> V_55 [ V_33 ] ;
if ( V_32 && V_32 -> V_56 . V_57 == V_19 ) {
struct V_58 * V_58 = F_25 ( V_32 ) ;
V_19 = V_58 -> V_59 ;
V_34 = 1 ;
break;
}
}
if ( ! V_34 ) {
F_23 ( L_7 , V_19 ) ;
return - V_42 ;
}
break;
case V_60 :
V_19 = V_4 -> V_52 ;
break;
case V_61 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_64 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_64 ;
else if ( V_4 -> V_37 >= V_50 )
V_19 = V_4 -> V_62 . V_67 . V_64 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_64 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_64 ;
else {
F_23 ( L_8 ) ;
return - V_42 ;
}
break;
case V_71 :
if ( V_19 >= 2 ) {
F_23 ( L_9 , V_19 ) ;
return - V_42 ;
}
F_15 ( V_2 , & V_4 -> V_72 , V_22 , & V_19 ) ;
break;
case V_73 :
if ( V_19 >= 2 ) {
F_23 ( L_10 , V_19 ) ;
return - V_42 ;
}
F_15 ( V_2 , & V_4 -> V_74 , V_22 , & V_19 ) ;
break;
case V_75 :
V_19 = V_4 -> clock . V_76 . V_77 * 10 ;
break;
case V_78 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_79 *
V_4 -> V_62 . V_63 . V_80 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_79 *
V_4 -> V_62 . V_66 . V_80 ;
else if ( V_4 -> V_37 >= V_50 )
V_19 = V_4 -> V_62 . V_67 . V_81 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_81 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_81 ;
else {
return - V_42 ;
}
break;
case V_82 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_83 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_83 ;
else if ( V_4 -> V_37 >= V_50 )
V_19 = V_4 -> V_62 . V_67 . V_83 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_83 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_83 ;
else {
return - V_42 ;
}
break;
case V_84 :
V_19 = 1 ;
break;
case V_85 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_86 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_86 ;
else if ( V_4 -> V_37 >= V_50 )
V_19 = V_4 -> V_62 . V_67 . V_86 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_86 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_86 ;
else {
return - V_42 ;
}
break;
case V_87 :
if ( V_4 -> V_37 < V_65 )
return - V_42 ;
V_19 = V_88 ;
break;
case V_89 :
if ( V_4 -> V_37 < V_65 )
return - V_42 ;
V_19 = V_90 ;
break;
case V_91 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_92 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_93 ;
else if ( V_4 -> V_37 >= V_50 )
V_19 = V_4 -> V_62 . V_67 . V_94 ;
else if ( V_4 -> V_37 >= V_68 )
V_19 = V_4 -> V_62 . V_69 . V_94 ;
else if ( V_4 -> V_37 >= V_38 )
V_19 = V_4 -> V_62 . V_70 . V_94 ;
else {
return - V_42 ;
}
break;
case V_95 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_80 ;
else if ( V_4 -> V_37 >= V_65 )
V_19 = V_4 -> V_62 . V_66 . V_80 ;
else if ( V_4 -> V_37 >= V_50 )
V_19 = V_4 -> V_62 . V_67 . V_96 ;
else
V_19 = 1 ;
break;
case V_97 :
if ( V_4 -> V_37 >= V_39 )
V_19 = V_4 -> V_62 . V_63 . V_98 ;
else
return - V_42 ;
break;
default:
F_23 ( L_11 , V_24 -> V_35 ) ;
return - V_42 ;
}
if ( F_21 ( V_28 , & V_19 , sizeof( T_1 ) ) ) {
F_22 ( L_4 , V_40 , __LINE__ ) ;
return - V_41 ;
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
int F_29 ( struct V_1 * V_2 , struct V_16 * V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_99 -> V_100 = NULL ;
if ( V_4 -> V_37 >= V_65 ) {
struct V_101 * V_102 ;
struct V_103 * V_104 ;
int V_7 ;
V_102 = F_7 ( sizeof( * V_102 ) , V_9 ) ;
if ( F_30 ( ! V_102 ) ) {
return - V_10 ;
}
F_31 ( V_4 , & V_102 -> V_105 ) ;
V_104 = F_32 ( V_4 , & V_102 -> V_105 ,
V_4 -> V_106 . V_107 ) ;
V_7 = F_33 ( V_4 , V_104 , V_108 ,
V_109 |
V_110 ) ;
if ( V_7 ) {
F_34 ( V_4 , & V_102 -> V_105 ) ;
F_5 ( V_102 ) ;
return V_7 ;
}
V_99 -> V_100 = V_102 ;
}
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
struct V_16 * V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_37 >= V_65 && V_99 -> V_100 ) {
struct V_101 * V_102 = V_99 -> V_100 ;
struct V_103 * V_104 ;
int V_7 ;
V_7 = F_36 ( V_4 -> V_106 . V_107 , false ) ;
if ( ! V_7 ) {
V_104 = F_37 ( & V_102 -> V_105 ,
V_4 -> V_106 . V_107 ) ;
if ( V_104 )
F_38 ( V_4 , V_104 ) ;
F_39 ( V_4 -> V_106 . V_107 ) ;
}
F_34 ( V_4 , & V_102 -> V_105 ) ;
F_5 ( V_102 ) ;
V_99 -> V_100 = NULL ;
}
}
void F_40 ( struct V_1 * V_2 ,
struct V_16 * V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_72 == V_99 )
V_4 -> V_72 = NULL ;
if ( V_4 -> V_74 == V_99 )
V_4 -> V_74 = NULL ;
}
T_3 F_41 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_32 < 0 || V_32 >= V_4 -> V_54 ) {
F_22 ( L_12 , V_32 ) ;
return - V_42 ;
}
return F_42 ( V_4 , V_32 ) ;
}
int F_43 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_111 ;
int V_7 ;
if ( V_32 < 0 || V_32 >= V_4 -> V_54 ) {
F_22 ( L_12 , V_32 ) ;
return - V_42 ;
}
F_44 ( & V_4 -> V_112 . V_113 , V_111 ) ;
V_4 -> V_112 . V_114 [ V_32 ] = true ;
V_7 = F_45 ( V_4 ) ;
F_46 ( & V_4 -> V_112 . V_113 , V_111 ) ;
return V_7 ;
}
void F_47 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_111 ;
if ( V_32 < 0 || V_32 >= V_4 -> V_54 ) {
F_22 ( L_12 , V_32 ) ;
return;
}
F_44 ( & V_4 -> V_112 . V_113 , V_111 ) ;
V_4 -> V_112 . V_114 [ V_32 ] = false ;
F_45 ( V_4 ) ;
F_46 ( & V_4 -> V_112 . V_113 , V_111 ) ;
}
int F_48 ( struct V_1 * V_2 , int V_32 ,
int * V_115 ,
struct V_116 * V_117 ,
unsigned V_6 )
{
struct V_31 * V_118 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_32 < 0 || V_32 >= V_2 -> V_119 ) {
F_22 ( L_12 , V_32 ) ;
return - V_42 ;
}
V_118 = & V_4 -> V_27 . V_55 [ V_32 ] -> V_56 ;
return F_49 ( V_2 , V_32 , V_115 ,
V_117 , V_6 ,
V_118 ) ;
}
int F_50 ( struct V_1 * V_2 , void * V_21 ,
struct V_16 * V_99 )
{
return - V_42 ;
}
