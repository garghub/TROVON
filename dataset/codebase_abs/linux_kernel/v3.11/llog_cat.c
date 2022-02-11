static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 V_11 = { { 0 } , } ;
int V_12 , V_13 , V_14 ;
V_15 ;
V_9 = V_4 -> V_16 ;
V_14 = F_2 ( V_9 ) ;
V_13 = ( V_4 -> V_17 + 1 ) % V_14 ;
if ( V_9 -> V_18 == V_13 ) {
F_3 ( L_1 ) ;
RETURN ( - V_19 ) ;
}
if ( F_4 ( V_20 ) )
RETURN ( - V_19 ) ;
V_12 = F_5 ( V_2 , V_5 , V_7 ) ;
if ( V_12 == - V_21 ) {
RETURN ( 0 ) ;
} else if ( V_12 != 0 ) {
F_3 ( L_2 ,
V_5 -> V_22 -> V_23 -> V_24 , V_12 ) ;
RETURN ( V_12 ) ;
}
V_12 = F_6 ( V_2 , V_5 ,
V_25 | V_26 ,
& V_4 -> V_16 -> V_27 ) ;
if ( V_12 )
GOTO ( V_28 , V_12 ) ;
if ( V_13 == 0 )
V_13 = 1 ;
F_7 ( & V_5 -> V_29 ) ;
V_9 -> V_30 ++ ;
if ( F_8 ( V_13 , V_9 -> V_31 ) ) {
F_3 ( L_3 ,
V_13 ) ;
F_9 ( & V_5 -> V_29 ) ;
F_10 () ;
}
F_9 ( & V_5 -> V_29 ) ;
V_4 -> V_17 = V_13 ;
V_9 -> V_32 . V_33 = V_13 ;
F_11 ( V_34 , L_4 V_35 L_5
V_35 L_6 , F_12 ( & V_5 -> V_36 . V_37 ) ,
V_5 -> V_36 . V_38 , V_13 ,
F_12 ( & V_4 -> V_36 . V_37 ) ) ;
V_11 . V_39 . V_40 = sizeof( V_11 ) ;
V_11 . V_39 . V_41 = V_13 ;
V_11 . V_39 . V_42 = V_43 ;
V_11 . V_44 = V_5 -> V_36 ;
V_11 . V_45 . V_46 = sizeof( V_11 ) ;
V_11 . V_45 . V_33 = V_13 ;
V_12 = F_13 ( V_2 , V_4 , & V_11 . V_39 ,
& V_5 -> V_47 . V_48 . V_49 , 1 , NULL , V_13 , V_7 ) ;
if ( V_12 < 0 )
GOTO ( V_28 , V_12 ) ;
V_5 -> V_16 -> V_18 = V_13 ;
RETURN ( 0 ) ;
V_28:
F_14 ( V_2 , V_5 ) ;
RETURN ( V_12 ) ;
}
int F_15 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * * V_50 , struct V_51 * V_52 )
{
struct V_3 * V_5 ;
int V_12 = 0 ;
V_15 ;
if ( V_4 == NULL )
RETURN ( - V_53 ) ;
F_16 ( & V_4 -> V_54 ) ;
F_17 (loghandle, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct V_51 * V_55 = & V_5 -> V_36 ;
if ( F_18 ( & V_55 -> V_37 ) == F_18 ( & V_52 -> V_37 ) &&
F_19 ( & V_55 -> V_37 ) == F_19 ( & V_52 -> V_37 ) ) {
if ( V_55 -> V_38 != V_52 -> V_38 ) {
F_3 ( L_7 V_35 L_8 ,
V_5 -> V_22 -> V_23 -> V_24 ,
F_12 ( & V_52 -> V_37 ) , V_55 -> V_38 ,
V_52 -> V_38 ) ;
continue;
}
V_5 -> V_47 . V_48 . V_56 = V_4 ;
F_20 ( & V_4 -> V_54 ) ;
GOTO ( V_57 , V_12 = 0 ) ;
}
}
F_20 ( & V_4 -> V_54 ) ;
V_12 = F_21 ( V_2 , V_4 -> V_22 , & V_5 , V_52 , NULL ,
V_58 ) ;
if ( V_12 < 0 ) {
F_3 ( L_9 V_35 L_10 ,
V_4 -> V_22 -> V_23 -> V_24 ,
F_12 ( & V_52 -> V_37 ) , V_52 -> V_38 , V_12 ) ;
RETURN ( V_12 ) ;
}
V_12 = F_6 ( V_2 , V_5 , V_25 , NULL ) ;
if ( V_12 < 0 ) {
F_22 ( V_2 , V_5 ) ;
V_5 = NULL ;
RETURN ( V_12 ) ;
}
F_16 ( & V_4 -> V_54 ) ;
F_23 ( & V_5 -> V_47 . V_48 . V_59 , & V_4 -> V_47 . V_60 . V_61 ) ;
F_20 ( & V_4 -> V_54 ) ;
V_5 -> V_47 . V_48 . V_56 = V_4 ;
V_5 -> V_47 . V_48 . V_49 . V_62 = V_4 -> V_36 ;
V_5 -> V_47 . V_48 . V_49 . V_63 =
V_5 -> V_16 -> V_18 ;
EXIT ;
V_57:
F_24 ( V_5 ) ;
* V_50 = V_5 ;
return 0 ;
}
int F_25 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 , * V_64 ;
int V_12 ;
V_15 ;
F_26 (loghandle, n, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct V_8 * V_9 = V_5 -> V_16 ;
int V_13 ;
F_27 ( & V_5 -> V_47 . V_48 . V_59 ) ;
V_9 = V_5 -> V_16 ;
if ( V_5 -> V_65 != NULL && V_9 != NULL &&
( V_9 -> V_66 & V_26 ) &&
( V_9 -> V_30 == 1 ) ) {
V_12 = F_14 ( V_2 , V_5 ) ;
if ( V_12 )
F_3 ( L_11
L_12 ,
V_5 -> V_22 -> V_23 -> V_24 ,
V_12 ) ;
V_13 = V_5 -> V_47 . V_48 . V_49 . V_63 ;
F_28 ( V_2 , V_4 , NULL , V_13 ) ;
}
F_22 ( V_2 , V_5 ) ;
}
if ( V_4 -> V_22 -> V_67 == V_4 )
V_4 -> V_22 -> V_67 = NULL ;
V_12 = F_22 ( V_2 , V_4 ) ;
RETURN ( V_12 ) ;
}
static struct V_3 * F_29 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_3 * V_5 = NULL ;
V_15 ;
F_30 ( & V_4 -> V_54 , V_68 ) ;
V_5 = V_4 -> V_47 . V_60 . V_69 ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_31 ( & V_5 -> V_54 , V_70 ) ;
V_9 = V_5 -> V_16 ;
if ( V_9 == NULL ||
V_5 -> V_17 < F_2 ( V_9 ) - 1 ) {
F_32 ( & V_4 -> V_54 ) ;
RETURN ( V_5 ) ;
} else {
F_20 ( & V_5 -> V_54 ) ;
}
}
F_32 ( & V_4 -> V_54 ) ;
F_31 ( & V_4 -> V_54 , V_68 ) ;
V_5 = V_4 -> V_47 . V_60 . V_69 ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_31 ( & V_5 -> V_54 , V_70 ) ;
V_9 = V_5 -> V_16 ;
F_33 ( V_9 ) ;
if ( V_5 -> V_17 < F_2 ( V_9 ) - 1 ) {
F_20 ( & V_4 -> V_54 ) ;
RETURN ( V_5 ) ;
} else {
F_20 ( & V_5 -> V_54 ) ;
}
}
F_11 ( V_71 , L_13 ) ;
V_5 = V_4 -> V_47 . V_60 . V_72 ;
V_4 -> V_47 . V_60 . V_69 = V_5 ;
V_4 -> V_47 . V_60 . V_72 = NULL ;
F_31 ( & V_5 -> V_54 , V_70 ) ;
F_20 ( & V_4 -> V_54 ) ;
F_33 ( V_5 ) ;
RETURN ( V_5 ) ;
}
int F_34 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_73 * V_11 , struct V_74 * V_75 ,
void * V_76 , struct V_6 * V_7 )
{
struct V_3 * V_5 ;
int V_12 ;
V_15 ;
F_33 ( V_11 -> V_40 <= V_77 ) ;
V_5 = F_29 ( V_4 , V_7 ) ;
F_33 ( ! F_35 ( V_5 ) ) ;
if ( ! F_36 ( V_5 ) ) {
V_12 = F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_12 < 0 ) {
F_20 ( & V_5 -> V_54 ) ;
RETURN ( V_12 ) ;
}
}
V_12 = F_13 ( V_2 , V_5 , V_11 , V_75 , 1 , V_76 , - 1 , V_7 ) ;
if ( V_12 < 0 )
F_37 ( V_12 == - V_19 ? V_78 : V_79 ,
L_14 , V_12 , V_5 ) ;
F_20 ( & V_5 -> V_54 ) ;
if ( V_12 == - V_19 ) {
V_5 = F_29 ( V_4 , V_7 ) ;
F_33 ( ! F_35 ( V_5 ) ) ;
if ( ! F_36 ( V_5 ) ) {
V_12 = F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_12 < 0 ) {
F_20 ( & V_5 -> V_54 ) ;
RETURN ( V_12 ) ;
}
}
V_12 = F_13 ( V_2 , V_5 , V_11 , V_75 , 1 , V_76 ,
- 1 , V_7 ) ;
if ( V_12 < 0 )
F_3 ( L_14 , V_12 , V_5 ) ;
F_20 ( & V_5 -> V_54 ) ;
}
RETURN ( V_12 ) ;
}
int F_38 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_73 * V_11 , struct V_6 * V_7 )
{
struct V_3 * V_5 , * V_80 ;
int V_12 = 0 ;
V_15 ;
if ( V_4 -> V_47 . V_60 . V_69 == NULL ) {
F_16 ( & V_4 -> V_54 ) ;
if ( V_4 -> V_47 . V_60 . V_69 == NULL ) {
V_12 = F_21 ( V_2 , V_4 -> V_22 , & V_5 ,
NULL , NULL , V_81 ) ;
if ( V_12 == 0 ) {
V_4 -> V_47 . V_60 . V_69 = V_5 ;
F_39 ( & V_5 -> V_47 . V_48 . V_59 ,
& V_4 -> V_47 . V_60 . V_61 ) ;
}
}
F_20 ( & V_4 -> V_54 ) ;
} else if ( V_4 -> V_47 . V_60 . V_72 == NULL ) {
F_16 ( & V_4 -> V_54 ) ;
if ( V_4 -> V_47 . V_60 . V_72 == NULL ) {
V_12 = F_21 ( V_2 , V_4 -> V_22 , & V_5 ,
NULL , NULL , V_81 ) ;
if ( V_12 == 0 ) {
V_4 -> V_47 . V_60 . V_72 = V_5 ;
F_39 ( & V_5 -> V_47 . V_48 . V_59 ,
& V_4 -> V_47 . V_60 . V_61 ) ;
}
}
F_20 ( & V_4 -> V_54 ) ;
}
if ( V_12 )
GOTO ( V_57 , V_12 ) ;
if ( ! F_36 ( V_4 -> V_47 . V_60 . V_69 ) ) {
V_12 = F_40 ( V_2 , V_4 -> V_47 . V_60 . V_69 ,
V_7 ) ;
if ( V_12 )
GOTO ( V_57 , V_12 ) ;
F_41 ( V_2 , V_4 , NULL , - 1 , V_7 ) ;
}
V_12 = F_41 ( V_2 , V_4 -> V_47 . V_60 . V_69 ,
V_11 , - 1 , V_7 ) ;
if ( V_12 )
GOTO ( V_57 , V_12 ) ;
V_80 = V_4 -> V_47 . V_60 . V_72 ;
if ( V_80 ) {
if ( ! F_36 ( V_80 ) ) {
V_12 = F_40 ( V_2 , V_80 , V_7 ) ;
F_41 ( V_2 , V_4 , NULL , - 1 , V_7 ) ;
}
F_41 ( V_2 , V_80 , V_11 , - 1 , V_7 ) ;
}
V_57:
RETURN ( V_12 ) ;
}
int F_42 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_73 * V_11 , struct V_74 * V_75 ,
void * V_76 )
{
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_6 * V_7 = NULL ;
int V_12 ;
V_83 = V_4 -> V_22 ;
F_33 ( V_83 ) ;
F_33 ( V_83 -> V_86 ) ;
if ( V_4 -> V_65 != NULL ) {
V_85 = V_83 -> V_86 -> V_87 -> V_88 . V_85 ;
F_33 ( V_85 ) ;
V_7 = F_43 ( V_2 , V_85 ) ;
if ( F_35 ( V_7 ) )
RETURN ( F_44 ( V_7 ) ) ;
V_12 = F_38 ( V_2 , V_4 , V_11 , V_7 ) ;
if ( V_12 )
GOTO ( V_89 , V_12 ) ;
V_12 = F_45 ( V_2 , V_85 , V_7 ) ;
if ( V_12 )
GOTO ( V_89 , V_12 ) ;
V_12 = F_34 ( V_2 , V_4 , V_11 , V_75 , V_76 , V_7 ) ;
V_89:
F_46 ( V_2 , V_85 , V_7 ) ;
} else {
F_33 ( V_4 -> V_90 != NULL ) ;
V_12 = F_38 ( V_2 , V_4 , V_11 , V_7 ) ;
if ( V_12 == 0 )
V_12 = F_34 ( V_2 , V_4 , V_11 , V_75 ,
V_76 , V_7 ) ;
}
RETURN ( V_12 ) ;
}
int F_47 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , int V_91 ,
struct V_74 * V_92 )
{
int V_93 , V_13 , V_12 = 0 , V_94 = 0 ;
V_15 ;
for ( V_93 = 0 ; V_93 < V_91 ; V_93 ++ , V_92 ++ ) {
struct V_3 * V_5 ;
struct V_51 * V_95 = & V_92 -> V_62 ;
int V_96 ;
V_12 = F_15 ( V_2 , V_4 , & V_5 , V_95 ) ;
if ( V_12 ) {
F_3 ( L_15 V_35 L_16 ,
V_4 -> V_22 -> V_23 -> V_24 ,
F_12 ( & V_95 -> V_37 ) , V_12 ) ;
V_94 ++ ;
continue;
}
V_96 = F_48 ( V_2 , V_5 , V_92 -> V_63 ) ;
if ( V_96 == 1 ) {
V_13 = V_5 -> V_47 . V_48 . V_49 . V_63 ;
V_12 = F_28 ( V_2 , V_4 , V_5 ,
V_13 ) ;
} else if ( V_96 == - V_97 ) {
if ( V_12 == 0 )
V_12 = V_96 ;
} else if ( V_96 < 0 ) {
V_94 ++ ;
V_12 = V_96 ;
}
F_49 ( V_5 ) ;
}
if ( V_12 )
F_3 ( L_17 ,
V_4 -> V_22 -> V_23 -> V_24 , V_94 , V_91 ,
V_12 ) ;
RETURN ( V_12 ) ;
}
int F_50 ( const struct V_1 * V_2 , struct V_3 * V_98 ,
struct V_73 * V_11 , void * V_99 )
{
struct V_100 * V_101 = V_99 ;
struct V_10 * V_102 = (struct V_10 * ) V_11 ;
struct V_3 * V_9 ;
int V_12 ;
V_15 ;
if ( V_11 -> V_42 != V_43 ) {
F_3 ( L_18 ) ;
RETURN ( - V_103 ) ;
}
F_11 ( V_78 , L_19 V_35 L_20
V_35 L_6 , F_12 ( & V_102 -> V_44 . V_37 ) , V_102 -> V_44 . V_38 ,
V_11 -> V_41 , F_12 ( & V_98 -> V_36 . V_37 ) ) ;
V_12 = F_15 ( V_2 , V_98 , & V_9 , & V_102 -> V_44 ) ;
if ( V_12 ) {
F_3 ( L_15 V_35 L_16 ,
V_98 -> V_22 -> V_23 -> V_24 ,
F_12 ( & V_102 -> V_44 . V_37 ) , V_12 ) ;
RETURN ( V_12 ) ;
}
if ( V_11 -> V_41 < V_101 -> V_104 )
RETURN ( 0 ) ;
if ( V_101 -> V_105 > 0 ) {
struct V_106 V_107 ;
V_107 . V_108 = V_101 -> V_105 ;
V_107 . V_109 = 0 ;
V_12 = F_51 ( V_2 , V_9 , V_101 -> V_110 , V_101 -> V_111 ,
& V_107 , false ) ;
V_101 -> V_105 = 0 ;
} else {
V_12 = F_51 ( V_2 , V_9 , V_101 -> V_110 , V_101 -> V_111 ,
NULL , false ) ;
}
F_49 ( V_9 ) ;
RETURN ( V_12 ) ;
}
int F_52 ( const struct V_1 * V_2 ,
struct V_3 * V_98 ,
T_1 V_112 , void * V_99 , int V_113 ,
int V_114 , bool V_115 )
{
struct V_100 V_101 ;
struct V_8 * V_9 = V_98 -> V_16 ;
int V_12 ;
V_15 ;
F_33 ( V_9 -> V_66 & V_116 ) ;
V_101 . V_111 = V_99 ;
V_101 . V_110 = V_112 ;
V_101 . V_104 = V_113 ;
V_101 . V_105 = V_114 ;
if ( V_9 -> V_18 > V_98 -> V_17 ) {
struct V_106 V_107 ;
F_53 ( L_21 V_35 L_22 ,
F_12 ( & V_98 -> V_36 . V_37 ) ) ;
V_107 . V_108 = V_9 -> V_18 ;
V_107 . V_109 = 0 ;
V_12 = F_51 ( V_2 , V_98 , F_50 ,
& V_101 , & V_107 , V_115 ) ;
if ( V_12 != 0 )
RETURN ( V_12 ) ;
V_107 . V_108 = 0 ;
V_107 . V_109 = V_98 -> V_17 ;
V_12 = F_51 ( V_2 , V_98 , F_50 ,
& V_101 , & V_107 , V_115 ) ;
} else {
V_12 = F_51 ( V_2 , V_98 , F_50 ,
& V_101 , NULL , V_115 ) ;
}
RETURN ( V_12 ) ;
}
int F_54 ( const struct V_1 * V_2 , struct V_3 * V_98 ,
T_1 V_112 , void * V_99 , int V_113 , int V_114 )
{
return F_52 ( V_2 , V_98 , V_112 , V_99 , V_113 ,
V_114 , false ) ;
}
static int F_55 ( const struct V_1 * V_2 ,
struct V_3 * V_98 ,
struct V_73 * V_11 , void * V_99 )
{
struct V_100 * V_101 = V_99 ;
struct V_10 * V_102 = (struct V_10 * ) V_11 ;
struct V_3 * V_9 ;
int V_12 ;
if ( F_56 ( V_11 -> V_42 ) != V_43 ) {
F_3 ( L_18 ) ;
RETURN ( - V_103 ) ;
}
F_11 ( V_78 , L_19 V_35 L_20
V_35 L_6 , F_12 ( & V_102 -> V_44 . V_37 ) , V_102 -> V_44 . V_38 ,
F_56 ( V_11 -> V_41 ) , F_12 ( & V_98 -> V_36 . V_37 ) ) ;
V_12 = F_15 ( V_2 , V_98 , & V_9 , & V_102 -> V_44 ) ;
if ( V_12 ) {
F_3 ( L_15 V_35 L_16 ,
V_98 -> V_22 -> V_23 -> V_24 ,
F_12 ( & V_102 -> V_44 . V_37 ) , V_12 ) ;
RETURN ( V_12 ) ;
}
V_12 = F_57 ( V_2 , V_9 , V_101 -> V_110 , V_101 -> V_111 , NULL ) ;
F_49 ( V_9 ) ;
RETURN ( V_12 ) ;
}
int F_58 ( const struct V_1 * V_2 ,
struct V_3 * V_98 ,
T_1 V_112 , void * V_99 )
{
struct V_100 V_101 ;
struct V_106 V_107 ;
struct V_8 * V_9 = V_98 -> V_16 ;
int V_12 ;
V_15 ;
F_33 ( V_9 -> V_66 & V_116 ) ;
V_101 . V_111 = V_99 ;
V_101 . V_110 = V_112 ;
if ( V_9 -> V_18 > V_98 -> V_17 ) {
F_53 ( L_23 V_35 L_22 ,
F_12 ( & V_98 -> V_36 . V_37 ) ) ;
V_107 . V_108 = 0 ;
V_107 . V_109 = V_98 -> V_17 ;
V_12 = F_57 ( V_2 , V_98 ,
F_55 ,
& V_101 , & V_107 ) ;
if ( V_12 != 0 )
RETURN ( V_12 ) ;
V_107 . V_108 = F_56 ( V_9 -> V_18 ) ;
V_107 . V_109 = 0 ;
V_12 = F_57 ( V_2 , V_98 ,
F_55 ,
& V_101 , & V_107 ) ;
} else {
V_12 = F_57 ( V_2 , V_98 ,
F_55 ,
& V_101 , NULL ) ;
}
RETURN ( V_12 ) ;
}
int F_59 ( struct V_3 * V_4 , int V_13 )
{
struct V_8 * V_9 = V_4 -> V_16 ;
int V_93 , V_14 , V_117 ;
V_15 ;
V_14 = F_2 ( V_9 ) ;
if ( V_9 -> V_18 == ( V_13 - 1 ) ) {
V_117 = V_9 -> V_18 + 1 ;
V_9 -> V_18 = V_117 ;
if ( V_117 == V_4 -> V_17 )
goto V_57;
for ( V_93 = ( V_13 + 1 ) % V_14 ;
V_93 != V_4 -> V_17 ;
V_93 = ( V_93 + 1 ) % V_14 ) {
if ( ! F_60 ( V_93 , V_9 -> V_31 ) ) {
V_117 = V_9 -> V_18 + 1 ;
V_9 -> V_18 = V_117 ;
} else if ( V_93 == 0 ) {
V_9 -> V_18 = 0 ;
} else {
break;
}
}
V_57:
F_11 ( V_34 , L_24 V_35 L_25 ,
F_12 ( & V_4 -> V_36 . V_37 ) , V_9 -> V_18 ) ;
}
RETURN ( 0 ) ;
}
int F_28 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , int V_13 )
{
int V_12 ;
F_33 ( V_13 ) ;
if ( V_5 != NULL ) {
F_16 ( & V_4 -> V_54 ) ;
if ( V_4 -> V_47 . V_60 . V_69 == V_5 )
V_4 -> V_47 . V_60 . V_69 = NULL ;
F_27 ( & V_5 -> V_47 . V_48 . V_59 ) ;
F_20 ( & V_4 -> V_54 ) ;
F_33 ( V_13 == V_5 -> V_47 . V_48 . V_49 . V_63 ) ;
F_22 ( V_2 , V_5 ) ;
}
F_59 ( V_4 , V_13 ) ;
V_12 = F_48 ( V_2 , V_4 , V_13 ) ;
if ( V_12 == 0 )
F_11 ( V_78 , L_26
L_27 V_35 L_6 ,
V_13 , F_12 ( & V_4 -> V_36 . V_37 ) ) ;
return V_12 ;
}
int F_61 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_73 * V_11 , void * V_99 )
{
struct V_10 * V_102 = (struct V_10 * ) V_11 ;
struct V_3 * V_5 ;
struct V_8 * V_9 ;
int V_12 ;
V_15 ;
if ( V_11 -> V_42 != V_43 ) {
F_3 ( L_18 ) ;
RETURN ( - V_103 ) ;
}
F_11 ( V_78 , L_19 V_35 L_20
V_35 L_6 , F_12 ( & V_102 -> V_44 . V_37 ) , V_102 -> V_44 . V_38 ,
V_11 -> V_41 , F_12 ( & V_4 -> V_36 . V_37 ) ) ;
V_12 = F_15 ( V_2 , V_4 , & V_5 , & V_102 -> V_44 ) ;
if ( V_12 ) {
F_3 ( L_15 V_35 L_16 ,
V_4 -> V_22 -> V_23 -> V_24 ,
F_12 ( & V_102 -> V_44 . V_37 ) , V_12 ) ;
if ( V_12 == - V_97 || V_12 == - V_118 ) {
F_28 ( V_2 , V_4 , NULL , V_11 -> V_41 ) ;
}
RETURN ( V_12 ) ;
}
V_9 = V_5 -> V_16 ;
if ( ( V_9 -> V_66 & V_26 ) &&
( V_9 -> V_30 == 1 ) ) {
V_12 = F_14 ( V_2 , V_5 ) ;
if ( V_12 )
F_3 ( L_28 ,
V_5 -> V_22 -> V_23 -> V_24 , V_12 ) ;
F_28 ( V_2 , V_4 , V_5 ,
V_5 -> V_47 . V_48 . V_49 . V_63 ) ;
}
F_49 ( V_5 ) ;
RETURN ( V_12 ) ;
}
int F_62 ( const struct V_1 * V_2 ,
struct V_3 * V_9 )
{
int V_12 ;
V_12 = F_6 ( V_2 , V_9 , V_116 , NULL ) ;
if ( V_12 )
RETURN ( V_12 ) ;
V_12 = F_51 ( V_2 , V_9 , F_61 , NULL , NULL , false ) ;
if ( V_12 )
F_3 ( L_29
L_30 , V_9 -> V_22 -> V_23 -> V_24 , V_12 ) ;
RETURN ( 0 ) ;
}
