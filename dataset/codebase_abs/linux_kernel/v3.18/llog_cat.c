static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 V_11 = { { 0 } , } ;
int V_12 , V_13 , V_14 ;
V_9 = V_4 -> V_15 ;
V_14 = F_2 ( V_9 ) ;
V_13 = ( V_4 -> V_16 + 1 ) % V_14 ;
if ( V_9 -> V_17 == V_13 ) {
F_3 ( L_1 ) ;
return - V_18 ;
}
if ( F_4 ( V_19 ) )
return - V_18 ;
V_12 = F_5 ( V_2 , V_5 , V_7 ) ;
if ( V_12 == - V_20 ) {
return 0 ;
} else if ( V_12 != 0 ) {
F_3 ( L_2 ,
V_5 -> V_21 -> V_22 -> V_23 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_2 , V_5 ,
V_24 | V_25 ,
& V_4 -> V_15 -> V_26 ) ;
if ( V_12 )
goto V_27;
if ( V_13 == 0 )
V_13 = 1 ;
F_7 ( & V_5 -> V_28 ) ;
V_9 -> V_29 ++ ;
if ( F_8 ( V_13 , V_9 -> V_30 ) ) {
F_3 ( L_3 ,
V_13 ) ;
F_9 ( & V_5 -> V_28 ) ;
F_10 () ;
}
F_9 ( & V_5 -> V_28 ) ;
V_4 -> V_16 = V_13 ;
V_9 -> V_31 . V_32 = V_13 ;
F_11 ( V_33 ,
L_4 V_34 L_5
V_34 L_6 , F_12 ( & V_5 -> V_35 . V_36 ) ,
V_5 -> V_35 . V_37 , V_13 ,
F_12 ( & V_4 -> V_35 . V_36 ) ) ;
V_11 . V_38 . V_39 = sizeof( V_11 ) ;
V_11 . V_38 . V_40 = V_13 ;
V_11 . V_38 . V_41 = V_42 ;
V_11 . V_43 = V_5 -> V_35 ;
V_11 . V_44 . V_45 = sizeof( V_11 ) ;
V_11 . V_44 . V_32 = V_13 ;
V_12 = F_13 ( V_2 , V_4 , & V_11 . V_38 ,
& V_5 -> V_46 . V_47 . V_48 , 1 , NULL , V_13 , V_7 ) ;
if ( V_12 < 0 )
goto V_27;
V_5 -> V_15 -> V_17 = V_13 ;
return 0 ;
V_27:
F_14 ( V_2 , V_5 ) ;
return V_12 ;
}
int F_15 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * * V_49 , struct V_50 * V_51 )
{
struct V_3 * V_5 ;
int V_12 = 0 ;
if ( V_4 == NULL )
return - V_52 ;
F_16 ( & V_4 -> V_53 ) ;
F_17 (loghandle, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct V_50 * V_54 = & V_5 -> V_35 ;
if ( F_18 ( & V_54 -> V_36 ) == F_18 ( & V_51 -> V_36 ) &&
F_19 ( & V_54 -> V_36 ) == F_19 ( & V_51 -> V_36 ) ) {
if ( V_54 -> V_37 != V_51 -> V_37 ) {
F_3 ( L_7 V_34 L_8 ,
V_5 -> V_21 -> V_22 -> V_23 ,
F_12 ( & V_51 -> V_36 ) , V_54 -> V_37 ,
V_51 -> V_37 ) ;
continue;
}
V_5 -> V_46 . V_47 . V_55 = V_4 ;
F_20 ( & V_4 -> V_53 ) ;
V_12 = 0 ;
goto V_56;
}
}
F_20 ( & V_4 -> V_53 ) ;
V_12 = F_21 ( V_2 , V_4 -> V_21 , & V_5 , V_51 , NULL ,
V_57 ) ;
if ( V_12 < 0 ) {
F_3 ( L_9 V_34 L_10 ,
V_4 -> V_21 -> V_22 -> V_23 ,
F_12 ( & V_51 -> V_36 ) , V_51 -> V_37 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_2 , V_5 , V_24 , NULL ) ;
if ( V_12 < 0 ) {
F_22 ( V_2 , V_5 ) ;
V_5 = NULL ;
return V_12 ;
}
F_16 ( & V_4 -> V_53 ) ;
F_23 ( & V_5 -> V_46 . V_47 . V_58 , & V_4 -> V_46 . V_59 . V_60 ) ;
F_20 ( & V_4 -> V_53 ) ;
V_5 -> V_46 . V_47 . V_55 = V_4 ;
V_5 -> V_46 . V_47 . V_48 . V_61 = V_4 -> V_35 ;
V_5 -> V_46 . V_47 . V_48 . V_62 =
V_5 -> V_15 -> V_17 ;
V_56:
F_24 ( V_5 ) ;
* V_49 = V_5 ;
return 0 ;
}
int F_25 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 , * V_63 ;
int V_12 ;
F_26 (loghandle, n, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct V_8 * V_9 = V_5 -> V_15 ;
int V_13 ;
F_27 ( & V_5 -> V_46 . V_47 . V_58 ) ;
V_9 = V_5 -> V_15 ;
if ( V_5 -> V_64 != NULL && V_9 != NULL &&
( V_9 -> V_65 & V_25 ) &&
( V_9 -> V_29 == 1 ) ) {
V_12 = F_14 ( V_2 , V_5 ) ;
if ( V_12 )
F_3 ( L_11
L_12 ,
V_5 -> V_21 -> V_22 -> V_23 ,
V_12 ) ;
V_13 = V_5 -> V_46 . V_47 . V_48 . V_62 ;
F_28 ( V_2 , V_4 , NULL , V_13 ) ;
}
F_22 ( V_2 , V_5 ) ;
}
if ( V_4 -> V_21 -> V_66 == V_4 )
V_4 -> V_21 -> V_66 = NULL ;
V_12 = F_22 ( V_2 , V_4 ) ;
return V_12 ;
}
static struct V_3 * F_29 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_3 * V_5 = NULL ;
F_30 ( & V_4 -> V_53 , V_67 ) ;
V_5 = V_4 -> V_46 . V_59 . V_68 ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_31 ( & V_5 -> V_53 , V_69 ) ;
V_9 = V_5 -> V_15 ;
if ( V_9 == NULL ||
V_5 -> V_16 < F_2 ( V_9 ) - 1 ) {
F_32 ( & V_4 -> V_53 ) ;
return V_5 ;
} else {
F_20 ( & V_5 -> V_53 ) ;
}
}
F_32 ( & V_4 -> V_53 ) ;
F_31 ( & V_4 -> V_53 , V_67 ) ;
V_5 = V_4 -> V_46 . V_59 . V_68 ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_31 ( & V_5 -> V_53 , V_69 ) ;
V_9 = V_5 -> V_15 ;
F_33 ( V_9 ) ;
if ( V_5 -> V_16 < F_2 ( V_9 ) - 1 ) {
F_20 ( & V_4 -> V_53 ) ;
return V_5 ;
} else {
F_20 ( & V_5 -> V_53 ) ;
}
}
F_11 ( V_70 , L_13 ) ;
V_5 = V_4 -> V_46 . V_59 . V_71 ;
V_4 -> V_46 . V_59 . V_68 = V_5 ;
V_4 -> V_46 . V_59 . V_71 = NULL ;
F_31 ( & V_5 -> V_53 , V_69 ) ;
F_20 ( & V_4 -> V_53 ) ;
F_33 ( V_5 ) ;
return V_5 ;
}
int F_34 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_72 * V_11 , struct V_73 * V_74 ,
void * V_75 , struct V_6 * V_7 )
{
struct V_3 * V_5 ;
int V_12 ;
F_33 ( V_11 -> V_39 <= V_76 ) ;
V_5 = F_29 ( V_4 , V_7 ) ;
F_33 ( ! F_35 ( V_5 ) ) ;
if ( ! F_36 ( V_5 ) ) {
V_12 = F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_12 < 0 ) {
F_20 ( & V_5 -> V_53 ) ;
return V_12 ;
}
}
V_12 = F_13 ( V_2 , V_5 , V_11 , V_74 , 1 , V_75 , - 1 , V_7 ) ;
if ( V_12 < 0 )
F_37 ( V_12 == - V_18 ? V_77 : V_78 ,
L_14 , V_12 , V_5 ) ;
F_20 ( & V_5 -> V_53 ) ;
if ( V_12 == - V_18 ) {
V_5 = F_29 ( V_4 , V_7 ) ;
F_33 ( ! F_35 ( V_5 ) ) ;
if ( ! F_36 ( V_5 ) ) {
V_12 = F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
if ( V_12 < 0 ) {
F_20 ( & V_5 -> V_53 ) ;
return V_12 ;
}
}
V_12 = F_13 ( V_2 , V_5 , V_11 , V_74 , 1 , V_75 ,
- 1 , V_7 ) ;
if ( V_12 < 0 )
F_3 ( L_14 , V_12 , V_5 ) ;
F_20 ( & V_5 -> V_53 ) ;
}
return V_12 ;
}
int F_38 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_72 * V_11 , struct V_6 * V_7 )
{
struct V_3 * V_5 , * V_79 ;
int V_12 = 0 ;
if ( V_4 -> V_46 . V_59 . V_68 == NULL ) {
F_16 ( & V_4 -> V_53 ) ;
if ( V_4 -> V_46 . V_59 . V_68 == NULL ) {
V_12 = F_21 ( V_2 , V_4 -> V_21 , & V_5 ,
NULL , NULL , V_80 ) ;
if ( V_12 == 0 ) {
V_4 -> V_46 . V_59 . V_68 = V_5 ;
F_39 ( & V_5 -> V_46 . V_47 . V_58 ,
& V_4 -> V_46 . V_59 . V_60 ) ;
}
}
F_20 ( & V_4 -> V_53 ) ;
} else if ( V_4 -> V_46 . V_59 . V_71 == NULL ) {
F_16 ( & V_4 -> V_53 ) ;
if ( V_4 -> V_46 . V_59 . V_71 == NULL ) {
V_12 = F_21 ( V_2 , V_4 -> V_21 , & V_5 ,
NULL , NULL , V_80 ) ;
if ( V_12 == 0 ) {
V_4 -> V_46 . V_59 . V_71 = V_5 ;
F_39 ( & V_5 -> V_46 . V_47 . V_58 ,
& V_4 -> V_46 . V_59 . V_60 ) ;
}
}
F_20 ( & V_4 -> V_53 ) ;
}
if ( V_12 )
goto V_56;
if ( ! F_36 ( V_4 -> V_46 . V_59 . V_68 ) ) {
V_12 = F_40 ( V_2 , V_4 -> V_46 . V_59 . V_68 ,
V_7 ) ;
if ( V_12 )
goto V_56;
F_41 ( V_2 , V_4 , NULL , - 1 , V_7 ) ;
}
V_12 = F_41 ( V_2 , V_4 -> V_46 . V_59 . V_68 ,
V_11 , - 1 , V_7 ) ;
if ( V_12 )
goto V_56;
V_79 = V_4 -> V_46 . V_59 . V_71 ;
if ( V_79 ) {
if ( ! F_36 ( V_79 ) ) {
V_12 = F_40 ( V_2 , V_79 , V_7 ) ;
F_41 ( V_2 , V_4 , NULL , - 1 , V_7 ) ;
}
F_41 ( V_2 , V_79 , V_11 , - 1 , V_7 ) ;
}
V_56:
return V_12 ;
}
int F_42 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_72 * V_11 , struct V_73 * V_74 ,
void * V_75 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_6 * V_7 = NULL ;
int V_12 ;
V_82 = V_4 -> V_21 ;
F_33 ( V_82 ) ;
F_33 ( V_82 -> V_85 ) ;
if ( V_4 -> V_64 != NULL ) {
V_84 = V_82 -> V_85 -> V_86 -> V_87 . V_84 ;
F_33 ( V_84 ) ;
V_7 = F_43 ( V_2 , V_84 ) ;
if ( F_35 ( V_7 ) )
return F_44 ( V_7 ) ;
V_12 = F_38 ( V_2 , V_4 , V_11 , V_7 ) ;
if ( V_12 )
goto V_88;
V_12 = F_45 ( V_2 , V_84 , V_7 ) ;
if ( V_12 )
goto V_88;
V_12 = F_34 ( V_2 , V_4 , V_11 , V_74 , V_75 , V_7 ) ;
V_88:
F_46 ( V_2 , V_84 , V_7 ) ;
} else {
F_33 ( V_4 -> V_89 != NULL ) ;
V_12 = F_38 ( V_2 , V_4 , V_11 , V_7 ) ;
if ( V_12 == 0 )
V_12 = F_34 ( V_2 , V_4 , V_11 , V_74 ,
V_75 , V_7 ) ;
}
return V_12 ;
}
int F_47 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , int V_90 ,
struct V_73 * V_91 )
{
int V_92 , V_13 , V_12 = 0 , V_93 = 0 ;
for ( V_92 = 0 ; V_92 < V_90 ; V_92 ++ , V_91 ++ ) {
struct V_3 * V_5 ;
struct V_50 * V_94 = & V_91 -> V_61 ;
int V_95 ;
V_12 = F_15 ( V_2 , V_4 , & V_5 , V_94 ) ;
if ( V_12 ) {
F_3 ( L_15 V_34 L_16 ,
V_4 -> V_21 -> V_22 -> V_23 ,
F_12 ( & V_94 -> V_36 ) , V_12 ) ;
V_93 ++ ;
continue;
}
V_95 = F_48 ( V_2 , V_5 , V_91 -> V_62 ) ;
if ( V_95 == 1 ) {
V_13 = V_5 -> V_46 . V_47 . V_48 . V_62 ;
V_12 = F_28 ( V_2 , V_4 , V_5 ,
V_13 ) ;
} else if ( V_95 == - V_96 ) {
if ( V_12 == 0 )
V_12 = V_95 ;
} else if ( V_95 < 0 ) {
V_93 ++ ;
V_12 = V_95 ;
}
F_49 ( V_5 ) ;
}
if ( V_12 )
F_3 ( L_17 ,
V_4 -> V_21 -> V_22 -> V_23 , V_93 , V_90 ,
V_12 ) ;
return V_12 ;
}
int F_50 ( const struct V_1 * V_2 , struct V_3 * V_97 ,
struct V_72 * V_11 , void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_10 * V_101 = (struct V_10 * ) V_11 ;
struct V_3 * V_9 ;
int V_12 ;
if ( V_11 -> V_41 != V_42 ) {
F_3 ( L_18 ) ;
return - V_102 ;
}
F_11 ( V_77 , L_19 V_34 L_20
V_34 L_6 , F_12 ( & V_101 -> V_43 . V_36 ) , V_101 -> V_43 . V_37 ,
V_11 -> V_40 , F_12 ( & V_97 -> V_35 . V_36 ) ) ;
V_12 = F_15 ( V_2 , V_97 , & V_9 , & V_101 -> V_43 ) ;
if ( V_12 ) {
F_3 ( L_15 V_34 L_16 ,
V_97 -> V_21 -> V_22 -> V_23 ,
F_12 ( & V_101 -> V_43 . V_36 ) , V_12 ) ;
return V_12 ;
}
if ( V_11 -> V_40 < V_100 -> V_103 )
V_12 = 0 ;
else if ( V_100 -> V_104 > 0 ) {
struct V_105 V_106 ;
V_106 . V_107 = V_100 -> V_104 ;
V_106 . V_108 = 0 ;
V_12 = F_51 ( V_2 , V_9 , V_100 -> V_109 , V_100 -> V_110 ,
& V_106 , false ) ;
V_100 -> V_104 = 0 ;
} else {
V_12 = F_51 ( V_2 , V_9 , V_100 -> V_109 , V_100 -> V_110 ,
NULL , false ) ;
}
F_49 ( V_9 ) ;
return V_12 ;
}
int F_52 ( const struct V_1 * V_2 ,
struct V_3 * V_97 ,
T_1 V_111 , void * V_98 , int V_112 ,
int V_113 , bool V_114 )
{
struct V_99 V_100 ;
struct V_8 * V_9 = V_97 -> V_15 ;
int V_12 ;
F_33 ( V_9 -> V_65 & V_115 ) ;
V_100 . V_110 = V_98 ;
V_100 . V_109 = V_111 ;
V_100 . V_103 = V_112 ;
V_100 . V_104 = V_113 ;
if ( V_9 -> V_17 > V_97 -> V_16 ) {
struct V_105 V_106 ;
F_53 ( L_21 V_34 L_22 ,
F_12 ( & V_97 -> V_35 . V_36 ) ) ;
V_106 . V_107 = V_9 -> V_17 ;
V_106 . V_108 = 0 ;
V_12 = F_51 ( V_2 , V_97 , F_50 ,
& V_100 , & V_106 , V_114 ) ;
if ( V_12 != 0 )
return V_12 ;
V_106 . V_107 = 0 ;
V_106 . V_108 = V_97 -> V_16 ;
V_12 = F_51 ( V_2 , V_97 , F_50 ,
& V_100 , & V_106 , V_114 ) ;
} else {
V_12 = F_51 ( V_2 , V_97 , F_50 ,
& V_100 , NULL , V_114 ) ;
}
return V_12 ;
}
int F_54 ( const struct V_1 * V_2 , struct V_3 * V_97 ,
T_1 V_111 , void * V_98 , int V_112 , int V_113 )
{
return F_52 ( V_2 , V_97 , V_111 , V_98 , V_112 ,
V_113 , false ) ;
}
static int F_55 ( const struct V_1 * V_2 ,
struct V_3 * V_97 ,
struct V_72 * V_11 , void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_10 * V_101 = (struct V_10 * ) V_11 ;
struct V_3 * V_9 ;
int V_12 ;
if ( F_56 ( V_11 -> V_41 ) != V_42 ) {
F_3 ( L_18 ) ;
return - V_102 ;
}
F_11 ( V_77 , L_19 V_34 L_20
V_34 L_6 , F_12 ( & V_101 -> V_43 . V_36 ) , V_101 -> V_43 . V_37 ,
F_56 ( V_11 -> V_40 ) , F_12 ( & V_97 -> V_35 . V_36 ) ) ;
V_12 = F_15 ( V_2 , V_97 , & V_9 , & V_101 -> V_43 ) ;
if ( V_12 ) {
F_3 ( L_15 V_34 L_16 ,
V_97 -> V_21 -> V_22 -> V_23 ,
F_12 ( & V_101 -> V_43 . V_36 ) , V_12 ) ;
return V_12 ;
}
V_12 = F_57 ( V_2 , V_9 , V_100 -> V_109 , V_100 -> V_110 , NULL ) ;
F_49 ( V_9 ) ;
return V_12 ;
}
int F_58 ( const struct V_1 * V_2 ,
struct V_3 * V_97 ,
T_1 V_111 , void * V_98 )
{
struct V_99 V_100 ;
struct V_105 V_106 ;
struct V_8 * V_9 = V_97 -> V_15 ;
int V_12 ;
F_33 ( V_9 -> V_65 & V_115 ) ;
V_100 . V_110 = V_98 ;
V_100 . V_109 = V_111 ;
if ( V_9 -> V_17 > V_97 -> V_16 ) {
F_53 ( L_23 V_34 L_22 ,
F_12 ( & V_97 -> V_35 . V_36 ) ) ;
V_106 . V_107 = 0 ;
V_106 . V_108 = V_97 -> V_16 ;
V_12 = F_57 ( V_2 , V_97 ,
F_55 ,
& V_100 , & V_106 ) ;
if ( V_12 != 0 )
return V_12 ;
V_106 . V_107 = F_56 ( V_9 -> V_17 ) ;
V_106 . V_108 = 0 ;
V_12 = F_57 ( V_2 , V_97 ,
F_55 ,
& V_100 , & V_106 ) ;
} else {
V_12 = F_57 ( V_2 , V_97 ,
F_55 ,
& V_100 , NULL ) ;
}
return V_12 ;
}
int F_59 ( struct V_3 * V_4 , int V_13 )
{
struct V_8 * V_9 = V_4 -> V_15 ;
int V_92 , V_14 , V_116 ;
V_14 = F_2 ( V_9 ) ;
if ( V_9 -> V_17 == ( V_13 - 1 ) ) {
V_116 = V_9 -> V_17 + 1 ;
V_9 -> V_17 = V_116 ;
if ( V_116 == V_4 -> V_16 )
goto V_56;
for ( V_92 = ( V_13 + 1 ) % V_14 ;
V_92 != V_4 -> V_16 ;
V_92 = ( V_92 + 1 ) % V_14 ) {
if ( ! F_60 ( V_92 , V_9 -> V_30 ) ) {
V_116 = V_9 -> V_17 + 1 ;
V_9 -> V_17 = V_116 ;
} else if ( V_92 == 0 ) {
V_9 -> V_17 = 0 ;
} else {
break;
}
}
V_56:
F_11 ( V_33 , L_24 V_34 L_25 ,
F_12 ( & V_4 -> V_35 . V_36 ) , V_9 -> V_17 ) ;
}
return 0 ;
}
int F_28 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , int V_13 )
{
int V_12 ;
F_33 ( V_13 ) ;
if ( V_5 != NULL ) {
F_16 ( & V_4 -> V_53 ) ;
if ( V_4 -> V_46 . V_59 . V_68 == V_5 )
V_4 -> V_46 . V_59 . V_68 = NULL ;
F_27 ( & V_5 -> V_46 . V_47 . V_58 ) ;
F_20 ( & V_4 -> V_53 ) ;
F_33 ( V_13 == V_5 -> V_46 . V_47 . V_48 . V_62 ) ;
F_22 ( V_2 , V_5 ) ;
}
F_59 ( V_4 , V_13 ) ;
V_12 = F_48 ( V_2 , V_4 , V_13 ) ;
if ( V_12 == 0 )
F_11 ( V_77 , L_26
L_27 V_34 L_6 ,
V_13 , F_12 ( & V_4 -> V_35 . V_36 ) ) ;
return V_12 ;
}
int F_61 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_72 * V_11 , void * V_98 )
{
struct V_10 * V_101 = (struct V_10 * ) V_11 ;
struct V_3 * V_5 ;
struct V_8 * V_9 ;
int V_12 ;
if ( V_11 -> V_41 != V_42 ) {
F_3 ( L_18 ) ;
return - V_102 ;
}
F_11 ( V_77 , L_19 V_34 L_20
V_34 L_6 , F_12 ( & V_101 -> V_43 . V_36 ) , V_101 -> V_43 . V_37 ,
V_11 -> V_40 , F_12 ( & V_4 -> V_35 . V_36 ) ) ;
V_12 = F_15 ( V_2 , V_4 , & V_5 , & V_101 -> V_43 ) ;
if ( V_12 ) {
F_3 ( L_15 V_34 L_16 ,
V_4 -> V_21 -> V_22 -> V_23 ,
F_12 ( & V_101 -> V_43 . V_36 ) , V_12 ) ;
if ( V_12 == - V_96 || V_12 == - V_117 ) {
F_28 ( V_2 , V_4 , NULL , V_11 -> V_40 ) ;
}
return V_12 ;
}
V_9 = V_5 -> V_15 ;
if ( ( V_9 -> V_65 & V_25 ) &&
( V_9 -> V_29 == 1 ) ) {
V_12 = F_14 ( V_2 , V_5 ) ;
if ( V_12 )
F_3 ( L_28 ,
V_5 -> V_21 -> V_22 -> V_23 , V_12 ) ;
F_28 ( V_2 , V_4 , V_5 ,
V_5 -> V_46 . V_47 . V_48 . V_62 ) ;
}
F_49 ( V_5 ) ;
return V_12 ;
}
int F_62 ( const struct V_1 * V_2 ,
struct V_3 * V_9 )
{
int V_12 ;
V_12 = F_6 ( V_2 , V_9 , V_115 , NULL ) ;
if ( V_12 )
return V_12 ;
V_12 = F_51 ( V_2 , V_9 , F_61 , NULL , NULL , false ) ;
if ( V_12 )
F_3 ( L_29
L_30 , V_9 -> V_21 -> V_22 -> V_23 , V_12 ) ;
return 0 ;
}
