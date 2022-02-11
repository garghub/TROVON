static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 = V_3 -> V_7 ;
return ( ( V_6 == 0 ) ? & V_5 -> V_8 :
& V_5 -> V_9 [ V_6 - 1 ] ) ;
}
static int F_2 ( struct V_4 * V_5 ,
int V_6 )
{
char * V_10 = V_5 -> V_11 [ V_6 ] . V_12 ;
int V_13 ;
if ( ! strcmp ( V_10 , V_5 -> V_8 . V_14 ) )
return 0 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_15 ; V_13 ++ ) {
if ( ! strcmp ( V_10 ,
V_5 -> V_9 [ V_13 ] . V_14 ) )
return V_13 + 1 ;
}
return - V_16 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
if ( ! V_18 )
return - V_16 ;
V_18 -> V_19 . V_20 = 0 ;
V_18 -> V_19 . V_21 = 0 ;
V_18 -> V_19 . V_22 = V_3 -> V_23 . V_24 ;
V_18 -> V_19 . V_25 = V_3 -> V_23 . V_26 ;
V_18 -> V_27 = V_18 -> V_19 ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_30 = V_29 -> V_6 ;
if ( V_30 >= V_5 -> V_31 )
return - V_16 ;
* V_29 = V_5 -> V_11 [ V_30 ] . V_29 ;
V_29 -> V_6 = V_30 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , char * V_32 ,
int V_33 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_34 V_35 ;
int V_36 = V_33 ;
int V_13 ;
if ( ! V_32 )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ! strcmp ( V_32 , V_35 . V_39 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_34 * V_40 )
{
if ( ! V_40 )
return - V_16 ;
* V_40 = V_3 -> V_23 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
T_1 V_41 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_34 V_35 ;
int V_36 = V_3 -> V_42 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ( V_35 . V_43 & V_44 ) &&
( V_35 . V_41 & V_41 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_8 ( struct V_2 * V_3 ,
char * V_45 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_34 V_35 ;
int V_36 = V_3 -> V_42 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_5 -> V_11 [ V_36 ] . V_37 ; V_13 ++ ) {
V_35 = V_5 -> V_11 [ V_36 ] . V_38 [ V_13 ] ;
if ( ! strcmp ( V_35 . V_39 , V_45 ) ) {
V_3 -> V_23 = V_35 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_9 ( struct V_2 * V_3 , int V_6 )
{
struct V_1 * V_46 =
F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_47 * V_48 = V_3 -> V_48 ;
int V_49 ;
int V_50 ;
int V_51 ;
if ( V_6 >= V_5 -> V_31 )
return - V_16 ;
F_10 ( & V_3 -> V_52 ) ;
V_50 = V_3 -> V_7 ;
V_49 = V_5 -> V_11 [ V_6 ] . V_29 . V_6 ;
if ( strcmp ( V_46 -> V_14 ,
V_5 -> V_11 [ V_6 ] . V_12 ) ) {
V_50 = F_2 ( V_5 , V_6 ) ;
if ( V_50 < 0 ) {
V_51 = - V_16 ;
goto V_53;
}
V_51 = V_48 -> V_54 ( V_5 -> V_11 [ V_6 ] . V_55 ) ;
if ( V_51 )
goto V_53;
}
V_51 = F_11 ( V_3 -> V_56 [ V_50 ] , V_57 ,
V_58 , 0 , V_49 , 0 ) ;
if ( V_51 )
goto V_53;
V_51 = F_5 ( V_3 ,
V_5 -> V_11 [ V_6 ] . V_59 , V_6 ) ;
if ( ! V_51 ) {
struct V_60 * V_61 = V_3 -> V_61 ;
V_61 -> V_62 . V_63 ( V_61 ,
V_3 -> V_23 . V_64 ) ;
V_61 -> V_62 . V_65 ( V_61 ,
V_3 -> V_23 . V_66 ) ;
V_3 -> V_7 = V_50 ;
V_3 -> V_42 = V_6 ;
}
V_53:
F_12 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_31 ; V_13 ++ ) {
if ( ! strcmp ( V_67 ,
V_5 -> V_11 [ V_13 ] . V_29 . V_39 ) ) {
int V_51 = F_9 ( V_3 , V_13 ) ;
if ( ! V_51 )
V_3 -> V_42 = V_13 ;
return V_51 ;
}
}
return 0 ;
}
static unsigned int F_14 ( struct V_2 * V_3 )
{
return V_3 -> V_42 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_70 = V_3 -> V_42 ;
struct V_71 * V_29 = & V_5 -> V_11 [ V_70 ] ;
int V_50 = V_3 -> V_7 ;
int V_51 , V_13 ;
if ( ! ( V_5 -> V_11 [ V_70 ] . V_29 . V_72 &
V_73 ) )
return - V_74 ;
for ( V_13 = 0 ; V_13 < V_29 -> V_37 ; V_13 ++ ) {
if ( V_29 -> V_38 [ V_13 ] . V_43 == V_75 &&
! memcmp ( & V_29 -> V_38 [ V_13 ] . V_69 ,
V_69 , sizeof( * V_69 ) ) )
break;
}
if ( V_13 >= V_29 -> V_37 )
return - V_16 ;
V_3 -> V_23 = V_29 -> V_38 [ V_13 ] ;
F_10 ( & V_3 -> V_52 ) ;
V_51 = F_11 ( V_3 -> V_56 [ V_50 ] , V_57 ,
V_76 , V_69 ) ;
if ( ! V_51 && V_3 -> V_77 ) {
V_51 = F_11 ( V_3 -> V_77 , V_57 ,
V_76 , V_69 ) ;
}
if ( ! V_51 ) {
struct V_60 * V_61 = V_3 -> V_61 ;
V_61 -> V_62 . V_63 ( V_61 ,
V_3 -> V_23 . V_64 ) ;
V_61 -> V_62 . V_65 ( V_61 ,
V_3 -> V_23 . V_66 ) ;
}
F_12 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_70 = V_3 -> V_42 ;
if ( ! ( V_5 -> V_11 [ V_70 ] . V_29 . V_72 &
V_73 ) )
return - V_74 ;
if ( V_3 -> V_23 . V_43 &
V_75 ) {
* V_69 = V_3 -> V_23 . V_69 ;
return 0 ;
}
return - V_16 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_70 = V_3 -> V_42 ;
struct V_71 * V_29 = & V_5 -> V_11 [ V_70 ] ;
int V_80 = 0 ;
int V_13 ;
if ( ! ( V_29 -> V_29 . V_72 & V_73 ) )
return - V_74 ;
for ( V_13 = 0 ; V_13 < V_29 -> V_37 ; V_13 ++ ) {
if ( V_29 -> V_38 [ V_13 ] . V_43 == V_75 ) {
if ( V_80 == V_79 -> V_6 )
break;
V_80 ++ ;
}
}
if ( V_13 == V_29 -> V_37 )
return - V_16 ;
V_79 -> V_79 = V_29 -> V_38 [ V_13 ] . V_69 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , T_1 V_41 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_70 = V_3 -> V_42 ;
int V_50 = V_3 -> V_7 ;
int V_51 ;
if ( ! ( V_5 -> V_11 [ V_70 ] . V_29 . V_72 &
V_81 ) )
return - V_74 ;
V_51 = F_7 ( V_3 , V_41 ) ;
if ( V_51 )
return V_51 ;
F_10 ( & V_3 -> V_52 ) ;
V_51 = F_11 ( V_3 -> V_56 [ V_50 ] , V_57 ,
V_82 , V_41 ) ;
if ( ! V_51 ) {
struct V_60 * V_61 = V_3 -> V_61 ;
V_61 -> V_62 . V_63 ( V_61 ,
V_3 -> V_23 . V_64 ) ;
V_61 -> V_62 . V_65 ( V_61 ,
V_3 -> V_23 . V_66 ) ;
}
F_12 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static int F_19 ( struct V_2 * V_3 , T_1 * V_41 )
{
struct V_34 * V_83 = & V_3 -> V_23 ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_70 = V_3 -> V_42 ;
if ( ! ( V_5 -> V_11 [ V_70 ] . V_29 . V_72 & V_81 ) )
return - V_74 ;
if ( V_83 -> V_43 & V_44 ) {
* V_41 = V_83 -> V_41 ;
return 0 ;
}
return - V_16 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_34 * V_40 )
{
struct V_34 * V_84 = NULL ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_68 V_69 ;
struct V_60 * V_61 ;
int V_70 = V_3 -> V_42 ;
int V_13 ;
if ( ! V_40 || ! V_40 -> V_39 )
return - V_16 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_11 [ V_70 ] . V_37 ; V_13 ++ ) {
if ( ! strcmp ( V_40 -> V_39 ,
V_5 -> V_11 [ V_70 ] . V_38 [ V_13 ] . V_39 ) ) {
V_84 = & V_5 -> V_11 [ V_70 ] . V_38 [ V_13 ] ;
if ( V_84 -> V_43 & V_44 )
return F_18 ( V_3 ,
V_84 -> V_41 ) ;
if ( V_84 -> V_43 &
V_75 ) {
V_69 =
V_84 -> V_69 ;
return F_15 ( V_3 , & V_69 ) ;
}
}
}
if ( ! V_84 )
return - V_16 ;
F_10 ( & V_3 -> V_52 ) ;
V_61 = V_3 -> V_61 ;
V_3 -> V_23 = * V_84 ;
V_61 -> V_62 . V_63 ( V_61 ,
V_3 -> V_23 . V_64 ) ;
V_61 -> V_62 . V_65 ( V_61 ,
V_3 -> V_23 . V_66 ) ;
F_12 ( & V_3 -> V_52 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
int V_51 ;
V_51 = F_8 ( V_3 , V_85 ) ;
if ( V_51 )
return V_51 ;
return F_20 ( V_3 , & V_3 -> V_23 ) ;
}
static int F_22 ( struct V_86 * V_87 , void * V_88 )
{
struct V_89 * V_90 = F_23 ( V_87 ) ;
struct V_2 * V_3 = V_88 ;
if ( strstr ( V_90 -> V_39 , L_1 ) )
V_3 -> V_61 = F_24 ( V_90 ) ;
if ( strstr ( V_90 -> V_39 , L_2 ) )
V_3 -> V_48 = F_25 ( & V_90 -> V_87 ) ;
return 0 ;
}
static int F_26 ( struct V_86 * V_87 , struct V_2 * V_3 )
{
struct V_1 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * * V_95 ;
struct V_60 * V_61 ;
struct V_96 * V_97 ;
int V_98 ;
int V_51 = 0 ;
int V_99 ;
int V_13 ;
if ( ! V_3 || ! V_87 ) {
F_27 ( V_100 L_3 ) ;
return - V_101 ;
}
if ( V_3 -> V_102 )
return 0 ;
F_10 ( & V_3 -> V_52 ) ;
if ( strcmp ( V_3 -> V_5 -> V_14 , L_4 ) != 0 ) {
V_3 -> V_103 = F_28 ( V_3 -> V_90 , L_5 ) ;
if ( F_29 ( V_3 -> V_103 ) ) {
V_51 = F_30 ( V_3 -> V_103 ) ;
goto V_104;
}
if ( F_31 ( V_3 -> V_103 ) ) {
V_51 = - V_101 ;
F_32 ( V_3 -> V_103 ) ;
goto V_104;
}
}
F_33 ( V_105 , 1 ) ;
V_51 = F_34 ( V_87 , & V_3 -> V_106 ) ;
if ( V_51 ) {
F_35 ( V_87 -> V_107 ,
L_6 ) ;
goto V_108;
}
F_36 ( & V_3 -> V_106 , L_7 ) ;
V_99 = F_37 ( & V_109 , NULL , V_3 ,
F_22 ) ;
if ( V_99 < 0 ) {
V_51 = V_99 ;
goto V_110;
}
V_3 -> V_8 = F_38 ( & V_3 -> V_106 ,
V_3 -> V_5 -> V_8 . V_14 ) ;
if ( ! V_3 -> V_8 ) {
F_35 ( & V_3 -> V_106 ,
L_8 ) ;
V_51 = - V_101 ;
goto V_110;
}
V_61 = V_3 -> V_61 ;
if ( V_61 -> V_62 . V_111 ) {
V_99 = V_61 -> V_62 . V_111 ( V_61 ) ;
if ( V_99 ) {
F_35 ( & V_3 -> V_106 ,
L_9 ) ;
V_99 = - V_112 ;
goto V_110;
}
}
V_98 = V_3 -> V_5 -> V_15 + 1 ;
V_3 -> V_56 = F_39 ( V_98 ,
sizeof( * V_3 -> V_56 ) ,
V_113 ) ;
if ( ! V_3 -> V_56 ) {
V_51 = - V_112 ;
goto V_110;
}
V_97 = F_40 ( V_3 -> V_5 -> V_114 ) ;
for ( V_13 = 0 ; V_13 < ( V_3 -> V_5 -> V_15 + 1 ) ; V_13 ++ ) {
if ( V_13 == 0 ) {
V_95 = & V_3 -> V_56 [ V_13 ] ;
* V_95 = V_3 -> V_8 ;
continue;
}
V_91 = & V_3 -> V_5 -> V_9 [ V_13 ] ;
if ( V_91 -> V_115 ) {
V_95 = & V_3 -> V_56 [ V_13 ] ;
* V_95 = F_41 (
& V_3 -> V_106 , V_97 ,
& V_91 -> V_116 , NULL ) ;
if ( * V_95 )
F_36 ( & V_3 -> V_106 ,
L_10 ,
V_91 -> V_14 ) ;
else {
F_35 ( & V_3 -> V_106 , L_11 ,
V_91 -> V_14 ) ;
V_51 = - V_101 ;
goto V_117;
}
} else
F_42 ( & V_3 -> V_106 , L_12 ) ;
}
if ( ( strcmp ( V_3 -> V_5 -> V_14 , L_13 ) == 0 ) &&
V_3 -> V_5 -> V_77 ) {
V_93 = V_3 -> V_5 -> V_77 ;
if ( V_93 -> V_115 ) {
V_3 -> V_77 = F_41 (
& V_3 -> V_106 , V_97 ,
& V_93 -> V_116 , NULL ) ;
if ( ! V_3 -> V_77 ) {
F_35 ( & V_3 -> V_106 ,
L_14 ,
V_93 -> V_14 ) ;
V_51 = - V_101 ;
goto V_117;
}
F_36 ( & V_3 -> V_106 ,
L_10 ,
V_93 -> V_14 ) ;
} else {
V_3 -> V_77 = NULL ;
F_42 ( & V_3 -> V_106 , L_15 ) ;
}
} else {
V_3 -> V_77 = NULL ;
}
V_3 -> V_7 = 0 ;
V_3 -> V_42 = 0 ;
F_12 ( & V_3 -> V_52 ) ;
F_27 ( V_118 L_16 , V_67 ) ;
V_51 = F_13 ( V_3 ) ;
if ( V_51 ) {
F_35 ( & V_3 -> V_106 , L_17 ,
V_67 ) ;
return V_51 ;
}
F_27 ( V_118 L_18 , V_85 ) ;
V_51 = F_21 ( V_3 ) ;
if ( V_51 ) {
F_35 ( & V_3 -> V_106 , L_19 ,
V_85 ) ;
return V_51 ;
}
V_3 -> V_102 = 1 ;
return 0 ;
V_117:
F_43 ( V_3 -> V_56 ) ;
V_110:
F_44 ( & V_3 -> V_106 ) ;
V_108:
if ( strcmp ( V_3 -> V_5 -> V_14 , L_4 ) != 0 ) {
F_45 ( V_3 -> V_103 ) ;
F_32 ( V_3 -> V_103 ) ;
}
V_104:
F_12 ( & V_3 -> V_52 ) ;
return V_51 ;
}
static void F_46 ( struct V_86 * V_87 , struct V_2 * V_3 )
{
F_44 ( & V_3 -> V_106 ) ;
if ( strcmp ( V_3 -> V_5 -> V_14 , L_4 ) != 0 ) {
F_45 ( V_3 -> V_103 ) ;
F_32 ( V_3 -> V_103 ) ;
}
F_43 ( V_3 -> V_77 ) ;
F_43 ( V_3 -> V_56 ) ;
V_3 -> V_102 = 0 ;
F_33 ( V_105 , 0 ) ;
}
static int F_47 ( struct V_89 * V_90 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
if ( ! V_90 -> V_87 . V_119 ) {
F_35 ( V_90 -> V_87 . V_107 , L_20 ) ;
return - V_101 ;
}
V_5 = V_90 -> V_87 . V_119 ;
if ( ! V_5 -> V_14 [ 0 ] ||
! V_5 -> V_120 . V_14 [ 0 ] ||
! V_5 -> V_8 . V_14 [ 0 ] ) {
F_35 ( V_90 -> V_87 . V_107 , L_21 ) ;
return - V_16 ;
}
V_3 = F_48 ( sizeof( * V_3 ) , V_113 ) ;
if ( ! V_3 )
return - V_112 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_62 = V_121 ;
V_3 -> V_90 = & V_90 -> V_87 ;
if ( V_5 -> V_11 -> V_37 > 0 )
V_3 -> V_23 = V_3 -> V_5 -> V_11 [ 0 ] . V_38 [ 0 ] ;
else {
F_43 ( V_3 ) ;
return - V_101 ;
}
F_49 ( V_90 , V_3 ) ;
F_50 ( & V_3 -> V_52 ) ;
return 0 ;
}
static int F_51 ( struct V_89 * V_86 )
{
struct V_2 * V_3 = F_24 ( V_86 ) ;
F_43 ( V_3 ) ;
return 0 ;
}
