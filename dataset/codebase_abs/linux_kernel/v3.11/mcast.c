int F_1 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
int V_13 ;
if ( ! F_4 ( V_5 ) )
return - V_14 ;
F_5 () ;
F_6 (np, mc_lst) {
if ( ( V_3 == 0 || V_9 -> V_3 == V_3 ) &&
F_7 ( & V_9 -> V_5 , V_5 ) ) {
F_8 () ;
return - V_15 ;
}
}
F_8 () ;
V_9 = F_9 ( V_2 , sizeof( struct V_8 ) , V_16 ) ;
if ( V_9 == NULL )
return - V_17 ;
V_9 -> V_18 = NULL ;
V_9 -> V_5 = * V_5 ;
F_5 () ;
if ( V_3 == 0 ) {
struct V_19 * V_20 ;
V_20 = F_10 ( V_12 , V_5 , NULL , 0 , 0 ) ;
if ( V_20 ) {
V_7 = V_20 -> V_21 . V_7 ;
F_11 ( V_20 ) ;
}
} else
V_7 = F_12 ( V_12 , V_3 ) ;
if ( V_7 == NULL ) {
F_8 () ;
F_13 ( V_2 , V_9 , sizeof( * V_9 ) ) ;
return - V_22 ;
}
V_9 -> V_3 = V_7 -> V_3 ;
V_9 -> V_23 = V_24 ;
F_14 ( & V_9 -> V_25 ) ;
V_9 -> V_26 = NULL ;
V_13 = F_15 ( V_7 , V_5 ) ;
if ( V_13 ) {
F_8 () ;
F_13 ( V_2 , V_9 , sizeof( * V_9 ) ) ;
return V_13 ;
}
F_16 ( & V_27 ) ;
V_9 -> V_18 = V_11 -> V_28 ;
F_17 ( V_11 -> V_28 , V_9 ) ;
F_18 ( & V_27 ) ;
F_8 () ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_8 T_1 * * V_29 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
if ( ! F_4 ( V_5 ) )
return - V_14 ;
F_16 ( & V_27 ) ;
for ( V_29 = & V_11 -> V_28 ;
( V_9 = F_20 ( * V_29 ,
F_21 ( & V_27 ) ) ) != NULL ;
V_29 = & V_9 -> V_18 ) {
if ( ( V_3 == 0 || V_9 -> V_3 == V_3 ) &&
F_7 ( & V_9 -> V_5 , V_5 ) ) {
struct V_6 * V_7 ;
* V_29 = V_9 -> V_18 ;
F_18 ( & V_27 ) ;
F_5 () ;
V_7 = F_12 ( V_12 , V_9 -> V_3 ) ;
if ( V_7 != NULL ) {
struct V_30 * V_31 = F_22 ( V_7 ) ;
( void ) F_23 ( V_2 , V_9 , V_31 ) ;
if ( V_31 )
F_24 ( V_31 , & V_9 -> V_5 ) ;
} else
( void ) F_23 ( V_2 , V_9 , NULL ) ;
F_8 () ;
F_25 ( sizeof( * V_9 ) , & V_2 -> V_32 ) ;
F_26 ( V_9 , V_33 ) ;
return 0 ;
}
}
F_18 ( & V_27 ) ;
return - V_34 ;
}
static struct V_30 * F_27 ( struct V_12 * V_12 ,
const struct V_4 * V_35 ,
int V_3 )
{
struct V_6 * V_7 = NULL ;
struct V_30 * V_31 = NULL ;
if ( V_3 == 0 ) {
struct V_19 * V_20 = F_10 ( V_12 , V_35 , NULL , 0 , 0 ) ;
if ( V_20 ) {
V_7 = V_20 -> V_21 . V_7 ;
F_11 ( V_20 ) ;
}
} else
V_7 = F_12 ( V_12 , V_3 ) ;
if ( ! V_7 )
return NULL ;
V_31 = F_22 ( V_7 ) ;
if ( ! V_31 )
return NULL ;
F_28 ( & V_31 -> V_36 ) ;
if ( V_31 -> V_37 ) {
F_29 ( & V_31 -> V_36 ) ;
return NULL ;
}
return V_31 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
if ( ! F_31 ( V_11 -> V_28 ) )
return;
F_16 ( & V_27 ) ;
while ( ( V_9 = F_20 ( V_11 -> V_28 ,
F_21 ( & V_27 ) ) ) != NULL ) {
struct V_6 * V_7 ;
V_11 -> V_28 = V_9 -> V_18 ;
F_18 ( & V_27 ) ;
F_5 () ;
V_7 = F_12 ( V_12 , V_9 -> V_3 ) ;
if ( V_7 ) {
struct V_30 * V_31 = F_22 ( V_7 ) ;
( void ) F_23 ( V_2 , V_9 , V_31 ) ;
if ( V_31 )
F_24 ( V_31 , & V_9 -> V_5 ) ;
} else
( void ) F_23 ( V_2 , V_9 , NULL ) ;
F_8 () ;
F_25 ( sizeof( * V_9 ) , & V_2 -> V_32 ) ;
F_26 ( V_9 , V_33 ) ;
F_16 ( & V_27 ) ;
}
F_18 ( & V_27 ) ;
}
int F_32 ( int V_38 , int V_39 , struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_4 * V_42 , * V_35 ;
struct V_8 * V_43 ;
struct V_30 * V_31 ;
struct V_10 * V_44 = F_2 ( V_2 ) ;
struct V_45 * V_46 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
int V_47 , V_48 , V_49 ;
int V_50 = 0 ;
int V_51 = 0 ;
int V_13 ;
V_42 = & ( (struct V_52 * ) & V_41 -> V_53 ) -> V_54 ;
V_35 = & ( (struct V_52 * ) & V_41 -> V_55 ) -> V_54 ;
if ( ! F_4 ( V_35 ) )
return - V_14 ;
F_5 () ;
V_31 = F_27 ( V_12 , V_35 , V_41 -> V_56 ) ;
if ( ! V_31 ) {
F_8 () ;
return - V_22 ;
}
V_13 = - V_34 ;
F_6 (inet6, pmc) {
if ( V_41 -> V_56 && V_43 -> V_3 != V_41 -> V_56 )
continue;
if ( F_7 ( & V_43 -> V_5 , V_35 ) )
break;
}
if ( ! V_43 ) {
V_13 = - V_14 ;
goto V_57;
}
if ( V_43 -> V_26 ) {
if ( V_43 -> V_23 != V_39 ) {
V_13 = - V_14 ;
goto V_57;
}
} else if ( V_43 -> V_23 != V_39 ) {
F_33 ( V_31 , V_35 , V_39 , 0 , NULL , 0 ) ;
F_34 ( V_31 , V_35 , V_43 -> V_23 , 0 , NULL , 0 ) ;
V_43 -> V_23 = V_39 ;
}
F_35 ( & V_43 -> V_25 ) ;
V_51 = 1 ;
V_46 = V_43 -> V_26 ;
if ( ! V_38 ) {
if ( ! V_46 )
goto V_57;
V_49 = ! 0 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ ) {
V_49 = ! F_7 ( & V_46 -> V_59 [ V_47 ] , V_42 ) ;
if ( V_49 == 0 )
break;
}
if ( V_49 )
goto V_57;
if ( V_46 -> V_58 == 1 && V_39 == V_60 ) {
V_50 = 1 ;
goto V_57;
}
F_34 ( V_31 , V_35 , V_39 , 1 , V_42 , 1 ) ;
for ( V_48 = V_47 + 1 ; V_48 < V_46 -> V_58 ; V_48 ++ )
V_46 -> V_59 [ V_48 - 1 ] = V_46 -> V_59 [ V_48 ] ;
V_46 -> V_58 -- ;
V_13 = 0 ;
goto V_57;
}
if ( V_46 && V_46 -> V_58 >= V_61 ) {
V_13 = - V_62 ;
goto V_57;
}
if ( ! V_46 || V_46 -> V_58 == V_46 -> V_63 ) {
struct V_45 * V_64 ;
int V_65 = V_66 ;
if ( V_46 )
V_65 += V_46 -> V_63 ;
V_64 = F_9 ( V_2 , F_36 ( V_65 ) , V_67 ) ;
if ( ! V_64 ) {
V_13 = - V_62 ;
goto V_57;
}
V_64 -> V_63 = V_65 ;
V_64 -> V_58 = V_65 - V_66 ;
if ( V_46 ) {
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ )
V_64 -> V_59 [ V_47 ] = V_46 -> V_59 [ V_47 ] ;
F_13 ( V_2 , V_46 , F_36 ( V_46 -> V_63 ) ) ;
}
V_43 -> V_26 = V_46 = V_64 ;
}
V_49 = 1 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ ) {
V_49 = ! F_7 ( & V_46 -> V_59 [ V_47 ] , V_42 ) ;
if ( V_49 == 0 )
goto V_57;
}
for ( V_48 = V_46 -> V_58 - 1 ; V_48 >= V_47 ; V_48 -- )
V_46 -> V_59 [ V_48 + 1 ] = V_46 -> V_59 [ V_48 ] ;
V_46 -> V_59 [ V_47 ] = * V_42 ;
V_46 -> V_58 ++ ;
V_13 = 0 ;
F_33 ( V_31 , V_35 , V_39 , 1 , V_42 , 1 ) ;
V_57:
if ( V_51 )
F_37 ( & V_43 -> V_25 ) ;
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
if ( V_50 )
return F_19 ( V_2 , V_41 -> V_56 , V_35 ) ;
return V_13 ;
}
int F_38 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
const struct V_4 * V_35 ;
struct V_8 * V_43 ;
struct V_30 * V_31 ;
struct V_10 * V_44 = F_2 ( V_2 ) ;
struct V_45 * V_64 , * V_46 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
int V_50 = 0 ;
int V_47 , V_13 ;
V_35 = & ( (struct V_52 * ) & V_69 -> V_70 ) -> V_54 ;
if ( ! F_4 ( V_35 ) )
return - V_14 ;
if ( V_69 -> V_71 != V_60 &&
V_69 -> V_71 != V_24 )
return - V_14 ;
F_5 () ;
V_31 = F_27 ( V_12 , V_35 , V_69 -> V_72 ) ;
if ( ! V_31 ) {
F_8 () ;
return - V_22 ;
}
V_13 = 0 ;
if ( V_69 -> V_71 == V_60 && V_69 -> V_73 == 0 ) {
V_50 = 1 ;
goto V_57;
}
F_6 (inet6, pmc) {
if ( V_43 -> V_3 != V_69 -> V_72 )
continue;
if ( F_7 ( & V_43 -> V_5 , V_35 ) )
break;
}
if ( ! V_43 ) {
V_13 = - V_14 ;
goto V_57;
}
if ( V_69 -> V_73 ) {
V_64 = F_9 ( V_2 , F_36 ( V_69 -> V_73 ) ,
V_67 ) ;
if ( ! V_64 ) {
V_13 = - V_62 ;
goto V_57;
}
V_64 -> V_63 = V_64 -> V_58 = V_69 -> V_73 ;
for ( V_47 = 0 ; V_47 < V_64 -> V_58 ; ++ V_47 ) {
struct V_52 * V_74 ;
V_74 = (struct V_52 * ) & V_69 -> V_75 [ V_47 ] ;
V_64 -> V_59 [ V_47 ] = V_74 -> V_54 ;
}
V_13 = F_33 ( V_31 , V_35 , V_69 -> V_71 ,
V_64 -> V_58 , V_64 -> V_59 , 0 ) ;
if ( V_13 ) {
F_13 ( V_2 , V_64 , F_36 ( V_64 -> V_63 ) ) ;
goto V_57;
}
} else {
V_64 = NULL ;
( void ) F_33 ( V_31 , V_35 , V_69 -> V_71 , 0 , NULL , 0 ) ;
}
F_35 ( & V_43 -> V_25 ) ;
V_46 = V_43 -> V_26 ;
if ( V_46 ) {
( void ) F_34 ( V_31 , V_35 , V_43 -> V_23 ,
V_46 -> V_58 , V_46 -> V_59 , 0 ) ;
F_13 ( V_2 , V_46 , F_36 ( V_46 -> V_63 ) ) ;
} else
( void ) F_34 ( V_31 , V_35 , V_43 -> V_23 , 0 , NULL , 0 ) ;
V_43 -> V_26 = V_64 ;
V_43 -> V_23 = V_69 -> V_71 ;
F_37 ( & V_43 -> V_25 ) ;
V_13 = 0 ;
V_57:
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
if ( V_50 )
V_13 = F_19 ( V_2 , V_69 -> V_72 , V_35 ) ;
return V_13 ;
}
int F_39 ( struct V_1 * V_2 , struct V_68 * V_69 ,
struct V_68 T_2 * V_76 , int T_2 * V_77 )
{
int V_13 , V_47 , V_65 , V_78 ;
const struct V_4 * V_35 ;
struct V_8 * V_43 ;
struct V_30 * V_31 ;
struct V_10 * V_44 = F_2 ( V_2 ) ;
struct V_45 * V_46 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
V_35 = & ( (struct V_52 * ) & V_69 -> V_70 ) -> V_54 ;
if ( ! F_4 ( V_35 ) )
return - V_14 ;
F_5 () ;
V_31 = F_27 ( V_12 , V_35 , V_69 -> V_72 ) ;
if ( ! V_31 ) {
F_8 () ;
return - V_22 ;
}
V_13 = - V_34 ;
F_6 (inet6, pmc) {
if ( V_43 -> V_3 != V_69 -> V_72 )
continue;
if ( F_7 ( V_35 , & V_43 -> V_5 ) )
break;
}
if ( ! V_43 )
goto V_57;
V_69 -> V_71 = V_43 -> V_23 ;
V_46 = V_43 -> V_26 ;
V_65 = V_46 ? V_46 -> V_58 : 0 ;
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
V_78 = V_65 < V_69 -> V_73 ? V_65 : V_69 -> V_73 ;
V_69 -> V_73 = V_65 ;
if ( F_40 ( F_41 ( V_78 ) , V_77 ) ||
F_42 ( V_76 , V_69 , F_41 ( 0 ) ) ) {
return - V_79 ;
}
for ( V_47 = 0 ; V_47 < V_78 ; V_47 ++ ) {
struct V_52 * V_74 ;
struct V_80 V_81 ;
V_74 = (struct V_52 * ) & V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_74 -> V_82 = V_83 ;
V_74 -> V_54 = V_46 -> V_59 [ V_47 ] ;
if ( F_42 ( & V_76 -> V_75 [ V_47 ] , & V_81 , sizeof( V_81 ) ) )
return - V_79 ;
}
return 0 ;
V_57:
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
return V_13 ;
}
bool F_43 ( struct V_1 * V_2 , const struct V_4 * V_84 ,
const struct V_4 * V_85 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_86 ;
struct V_45 * V_46 ;
bool V_49 = true ;
F_5 () ;
F_6 (np, mc) {
if ( F_7 ( & V_86 -> V_5 , V_84 ) )
break;
}
if ( ! V_86 ) {
F_8 () ;
return true ;
}
F_44 ( & V_86 -> V_25 ) ;
V_46 = V_86 -> V_26 ;
if ( ! V_46 ) {
V_49 = V_86 -> V_23 == V_24 ;
} else {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ ) {
if ( F_7 ( & V_46 -> V_59 [ V_47 ] , V_85 ) )
break;
}
if ( V_86 -> V_23 == V_60 && V_47 >= V_46 -> V_58 )
V_49 = false ;
if ( V_86 -> V_23 == V_24 && V_47 < V_46 -> V_58 )
V_49 = false ;
}
F_45 ( & V_86 -> V_25 ) ;
F_8 () ;
return V_49 ;
}
static void F_46 ( struct V_87 * V_86 )
{
if ( F_47 ( & V_86 -> V_88 ) ) {
F_48 ( V_86 -> V_31 ) ;
F_49 ( V_86 ) ;
}
}
static void F_50 ( struct V_87 * V_86 )
{
struct V_6 * V_7 = V_86 -> V_31 -> V_7 ;
char V_89 [ V_90 ] ;
if ( F_51 ( & V_86 -> V_91 ) <
V_92 )
return;
F_52 ( & V_86 -> V_93 ) ;
if ( ! ( V_86 -> V_94 & V_95 ) ) {
V_86 -> V_94 |= V_95 ;
if ( F_53 ( & V_86 -> V_91 , V_89 , V_7 , 0 ) == 0 )
F_54 ( V_7 , V_89 ) ;
}
F_55 ( & V_86 -> V_93 ) ;
if ( ! ( V_7 -> V_96 & V_97 ) || ( V_86 -> V_94 & V_98 ) )
return;
if ( F_56 ( V_86 -> V_31 ) ) {
F_57 ( V_86 ) ;
return;
}
V_86 -> V_99 = V_86 -> V_31 -> V_100 ;
F_58 ( V_86 -> V_31 ) ;
}
static void F_59 ( struct V_87 * V_86 )
{
struct V_6 * V_7 = V_86 -> V_31 -> V_7 ;
char V_89 [ V_90 ] ;
if ( F_51 ( & V_86 -> V_91 ) <
V_92 )
return;
F_52 ( & V_86 -> V_93 ) ;
if ( V_86 -> V_94 & V_95 ) {
V_86 -> V_94 &= ~ V_95 ;
if ( F_53 ( & V_86 -> V_91 , V_89 , V_7 , 0 ) == 0 )
F_60 ( V_7 , V_89 ) ;
}
if ( V_86 -> V_94 & V_98 )
goto V_57;
F_55 ( & V_86 -> V_93 ) ;
if ( ! V_86 -> V_31 -> V_37 )
F_61 ( V_86 ) ;
F_52 ( & V_86 -> V_93 ) ;
if ( F_62 ( & V_86 -> V_101 ) )
F_63 ( & V_86 -> V_88 ) ;
V_57:
F_64 ( V_86 ) ;
F_55 ( & V_86 -> V_93 ) ;
}
static void F_65 ( struct V_30 * V_31 , struct V_87 * V_102 )
{
struct V_87 * V_43 ;
V_43 = F_66 ( sizeof( * V_43 ) , V_67 ) ;
if ( ! V_43 )
return;
F_52 ( & V_102 -> V_93 ) ;
F_67 ( & V_43 -> V_93 ) ;
V_43 -> V_31 = V_102 -> V_31 ;
F_68 ( V_31 ) ;
V_43 -> V_91 = V_102 -> V_91 ;
V_43 -> V_99 = V_31 -> V_100 ;
V_43 -> V_103 = V_102 -> V_103 ;
if ( V_43 -> V_103 == V_60 ) {
struct V_104 * V_105 ;
V_43 -> V_106 = V_102 -> V_106 ;
V_43 -> V_107 = V_102 -> V_107 ;
V_102 -> V_106 = V_102 -> V_107 = NULL ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
V_105 -> V_109 = V_43 -> V_99 ;
}
F_55 ( & V_102 -> V_93 ) ;
F_52 ( & V_31 -> V_110 ) ;
V_43 -> V_18 = V_31 -> V_111 ;
V_31 -> V_111 = V_43 ;
F_55 ( & V_31 -> V_110 ) ;
}
static void F_69 ( struct V_30 * V_31 , const struct V_4 * V_112 )
{
struct V_87 * V_43 , * V_113 ;
struct V_104 * V_105 , * V_114 ;
F_52 ( & V_31 -> V_110 ) ;
V_113 = NULL ;
for ( V_43 = V_31 -> V_111 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( F_7 ( & V_43 -> V_91 , V_112 ) )
break;
V_113 = V_43 ;
}
if ( V_43 ) {
if ( V_113 )
V_113 -> V_18 = V_43 -> V_18 ;
else
V_31 -> V_111 = V_43 -> V_18 ;
}
F_55 ( & V_31 -> V_110 ) ;
if ( V_43 ) {
for ( V_105 = V_43 -> V_106 ; V_105 ; V_105 = V_114 ) {
V_114 = V_105 -> V_108 ;
F_49 ( V_105 ) ;
}
F_48 ( V_43 -> V_31 ) ;
F_49 ( V_43 ) ;
}
}
static void F_70 ( struct V_30 * V_31 )
{
struct V_87 * V_43 , * V_115 ;
F_52 ( & V_31 -> V_110 ) ;
V_43 = V_31 -> V_111 ;
V_31 -> V_111 = NULL ;
F_55 ( & V_31 -> V_110 ) ;
for (; V_43 ; V_43 = V_115 ) {
V_115 = V_43 -> V_18 ;
F_64 ( V_43 ) ;
F_48 ( V_43 -> V_31 ) ;
F_49 ( V_43 ) ;
}
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_116 ; V_43 ; V_43 = V_43 -> V_18 ) {
struct V_104 * V_105 , * V_114 ;
F_52 ( & V_43 -> V_93 ) ;
V_105 = V_43 -> V_106 ;
V_43 -> V_106 = NULL ;
F_55 ( & V_43 -> V_93 ) ;
for (; V_105 ; V_105 = V_114 ) {
V_114 = V_105 -> V_108 ;
F_49 ( V_105 ) ;
}
}
F_29 ( & V_31 -> V_36 ) ;
}
int F_15 ( struct V_6 * V_7 , const struct V_4 * V_5 )
{
struct V_87 * V_86 ;
struct V_30 * V_31 ;
V_31 = F_71 ( V_7 ) ;
if ( V_31 == NULL )
return - V_14 ;
F_72 ( & V_31 -> V_36 ) ;
if ( V_31 -> V_37 ) {
F_73 ( & V_31 -> V_36 ) ;
F_48 ( V_31 ) ;
return - V_22 ;
}
for ( V_86 = V_31 -> V_116 ; V_86 ; V_86 = V_86 -> V_18 ) {
if ( F_7 ( & V_86 -> V_91 , V_5 ) ) {
V_86 -> V_117 ++ ;
F_73 ( & V_31 -> V_36 ) ;
F_33 ( V_31 , & V_86 -> V_91 , V_24 , 0 ,
NULL , 0 ) ;
F_48 ( V_31 ) ;
return 0 ;
}
}
V_86 = F_66 ( sizeof( struct V_87 ) , V_67 ) ;
if ( V_86 == NULL ) {
F_73 ( & V_31 -> V_36 ) ;
F_48 ( V_31 ) ;
return - V_17 ;
}
F_74 ( & V_86 -> V_101 , V_118 , ( unsigned long ) V_86 ) ;
V_86 -> V_91 = * V_5 ;
V_86 -> V_31 = V_31 ;
V_86 -> V_117 = 1 ;
V_86 -> V_119 = V_86 -> V_120 = V_121 ;
F_75 ( & V_86 -> V_88 , 2 ) ;
F_67 ( & V_86 -> V_93 ) ;
V_86 -> V_103 = V_24 ;
V_86 -> V_122 [ V_24 ] = 1 ;
if ( F_76 ( & V_86 -> V_91 ) ||
F_51 ( & V_86 -> V_91 ) < V_92 )
V_86 -> V_94 |= V_98 ;
V_86 -> V_18 = V_31 -> V_116 ;
V_31 -> V_116 = V_86 ;
F_73 ( & V_31 -> V_36 ) ;
F_69 ( V_31 , & V_86 -> V_91 ) ;
F_50 ( V_86 ) ;
F_46 ( V_86 ) ;
return 0 ;
}
int F_24 ( struct V_30 * V_31 , const struct V_4 * V_5 )
{
struct V_87 * V_123 , * * V_124 ;
F_72 ( & V_31 -> V_36 ) ;
for ( V_124 = & V_31 -> V_116 ; ( V_123 = * V_124 ) != NULL ; V_124 = & V_123 -> V_18 ) {
if ( F_7 ( & V_123 -> V_91 , V_5 ) ) {
if ( -- V_123 -> V_117 == 0 ) {
* V_124 = V_123 -> V_18 ;
F_73 ( & V_31 -> V_36 ) ;
F_59 ( V_123 ) ;
F_46 ( V_123 ) ;
return 0 ;
}
F_73 ( & V_31 -> V_36 ) ;
return 0 ;
}
}
F_73 ( & V_31 -> V_36 ) ;
return - V_125 ;
}
int F_77 ( struct V_6 * V_7 , const struct V_4 * V_5 )
{
struct V_30 * V_31 ;
int V_13 ;
F_5 () ;
V_31 = F_22 ( V_7 ) ;
if ( ! V_31 )
V_13 = - V_22 ;
else
V_13 = F_24 ( V_31 , V_5 ) ;
F_8 () ;
return V_13 ;
}
bool F_78 ( struct V_6 * V_7 , const struct V_4 * V_35 ,
const struct V_4 * V_85 )
{
struct V_30 * V_31 ;
struct V_87 * V_86 ;
bool V_49 = false ;
F_5 () ;
V_31 = F_22 ( V_7 ) ;
if ( V_31 ) {
F_28 ( & V_31 -> V_36 ) ;
for ( V_86 = V_31 -> V_116 ; V_86 ; V_86 = V_86 -> V_18 ) {
if ( F_7 ( & V_86 -> V_91 , V_35 ) )
break;
}
if ( V_86 ) {
if ( V_85 && ! F_79 ( V_85 ) ) {
struct V_104 * V_105 ;
F_52 ( & V_86 -> V_93 ) ;
for ( V_105 = V_86 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( F_7 ( & V_105 -> V_126 , V_85 ) )
break;
}
if ( V_105 )
V_49 = V_105 -> V_127 [ V_60 ] ||
V_105 -> V_127 [ V_24 ] !=
V_86 -> V_122 [ V_24 ] ;
else
V_49 = V_86 -> V_122 [ V_24 ] != 0 ;
F_55 ( & V_86 -> V_93 ) ;
} else
V_49 = true ;
}
F_29 ( & V_31 -> V_36 ) ;
}
F_8 () ;
return V_49 ;
}
static void F_80 ( struct V_30 * V_31 )
{
int V_128 = F_81 () % V_31 -> V_129 ;
V_31 -> V_130 = 1 ;
if ( ! F_82 ( & V_31 -> V_131 , V_121 + V_128 + 2 ) )
F_68 ( V_31 ) ;
}
static void F_83 ( struct V_30 * V_31 , int V_132 )
{
int V_128 = F_81 () % V_132 ;
if ( ! F_82 ( & V_31 -> V_133 , V_121 + V_128 + 2 ) )
F_68 ( V_31 ) ;
}
static void F_84 ( struct V_30 * V_31 , int V_132 )
{
int V_128 = F_81 () % V_132 ;
if ( ! F_82 ( & V_31 -> V_134 , V_121 + V_128 + 2 ) )
F_68 ( V_31 ) ;
}
static void F_85 ( struct V_87 * V_123 , unsigned long V_135 )
{
unsigned long V_132 = V_135 ;
if ( F_76 ( & V_123 -> V_91 ) ||
F_51 ( & V_123 -> V_91 ) < V_92 )
return;
if ( F_62 ( & V_123 -> V_101 ) ) {
F_63 ( & V_123 -> V_88 ) ;
V_132 = V_123 -> V_101 . V_136 - V_121 ;
}
if ( V_132 >= V_135 ) {
if ( V_135 )
V_132 = F_81 () % V_135 ;
else
V_132 = 1 ;
}
V_123 -> V_101 . V_136 = V_121 + V_132 ;
if ( ! F_82 ( & V_123 -> V_101 , V_121 + V_132 ) )
F_86 ( & V_123 -> V_88 ) ;
V_123 -> V_94 |= V_137 ;
}
static bool F_87 ( struct V_87 * V_43 , int V_138 ,
const struct V_4 * V_139 )
{
struct V_104 * V_105 ;
int V_47 , V_140 ;
V_140 = 0 ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( V_140 == V_138 )
break;
for ( V_47 = 0 ; V_47 < V_138 ; V_47 ++ ) {
if ( V_105 -> V_127 [ V_60 ] ||
V_43 -> V_122 [ V_24 ] !=
V_105 -> V_127 [ V_24 ] )
break;
if ( F_7 ( & V_139 [ V_47 ] , & V_105 -> V_126 ) ) {
V_140 ++ ;
break;
}
}
}
V_43 -> V_94 &= ~ V_141 ;
if ( V_140 == V_138 )
return false ;
return true ;
}
static bool F_88 ( struct V_87 * V_43 , int V_138 ,
const struct V_4 * V_139 )
{
struct V_104 * V_105 ;
int V_47 , V_140 ;
if ( V_43 -> V_103 == V_24 )
return F_87 ( V_43 , V_138 , V_139 ) ;
V_140 = 0 ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( V_140 == V_138 )
break;
for ( V_47 = 0 ; V_47 < V_138 ; V_47 ++ ) {
if ( F_7 ( & V_139 [ V_47 ] , & V_105 -> V_126 ) ) {
V_105 -> V_142 = 1 ;
V_140 ++ ;
break;
}
}
}
if ( ! V_140 ) {
V_43 -> V_94 &= ~ V_141 ;
return false ;
}
V_43 -> V_94 |= V_141 ;
return true ;
}
int F_89 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = NULL ;
struct V_87 * V_123 ;
const struct V_4 * V_35 ;
unsigned long V_147 ;
struct V_30 * V_31 ;
struct V_148 * V_149 ;
int V_150 ;
int V_151 = 0 ;
int V_152 ;
if ( ! F_90 ( V_144 , sizeof( struct V_4 ) ) )
return - V_14 ;
V_152 = F_91 ( F_92 ( V_144 ) -> V_153 ) + sizeof( struct V_154 ) ;
V_152 -= F_93 ( V_144 ) ;
if ( ! ( F_94 ( & F_92 ( V_144 ) -> V_155 ) & V_156 ) )
return - V_14 ;
V_31 = F_22 ( V_144 -> V_7 ) ;
if ( V_31 == NULL )
return 0 ;
V_149 = (struct V_148 * ) F_95 ( V_144 ) ;
V_35 = & V_149 -> V_157 ;
V_150 = F_94 ( V_35 ) ;
if ( V_150 != V_158 &&
! ( V_150 & V_159 ) )
return - V_14 ;
if ( V_152 == 24 ) {
int V_160 ;
V_147 = ( F_91 ( V_149 -> V_161 ) * V_162 ) / 1000 ;
V_160 = ( V_31 -> V_100 + 1 ) * V_147 ;
V_31 -> V_163 = V_121 + V_160 ;
V_31 -> V_164 = 0 ;
if ( F_62 ( & V_31 -> V_133 ) )
F_96 ( V_31 ) ;
F_70 ( V_31 ) ;
} else if ( V_152 >= 28 ) {
int V_165 = sizeof( struct V_145 ) -
sizeof( struct V_166 ) ;
if ( ! F_90 ( V_144 , V_165 ) )
return - V_14 ;
V_146 = (struct V_145 * ) F_97 ( V_144 ) ;
V_147 = ( F_98 ( F_91 ( V_146 -> V_167 ) ) * V_162 ) / 1000 ;
if ( ! V_147 )
V_147 = 1 ;
V_31 -> V_129 = V_147 ;
if ( V_146 -> V_168 )
V_31 -> V_100 = V_146 -> V_168 ;
if ( V_150 == V_158 ) {
if ( V_146 -> V_169 )
return - V_14 ;
F_80 ( V_31 ) ;
return 0 ;
}
if ( V_146 -> V_169 != 0 ) {
if ( ! F_90 ( V_144 , V_165 +
F_91 ( V_146 -> V_169 ) * sizeof( struct V_4 ) ) )
return - V_14 ;
V_146 = (struct V_145 * ) F_97 ( V_144 ) ;
V_151 = 1 ;
}
} else
return - V_14 ;
F_28 ( & V_31 -> V_36 ) ;
if ( V_150 == V_158 ) {
for ( V_123 = V_31 -> V_116 ; V_123 ; V_123 = V_123 -> V_18 ) {
F_52 ( & V_123 -> V_93 ) ;
F_85 ( V_123 , V_147 ) ;
F_55 ( & V_123 -> V_93 ) ;
}
} else {
for ( V_123 = V_31 -> V_116 ; V_123 ; V_123 = V_123 -> V_18 ) {
if ( ! F_7 ( V_35 , & V_123 -> V_91 ) )
continue;
F_52 ( & V_123 -> V_93 ) ;
if ( V_123 -> V_94 & V_137 ) {
if ( ! V_151 )
V_123 -> V_94 &= ~ V_141 ;
} else {
if ( V_151 )
V_123 -> V_94 |= V_141 ;
else
V_123 -> V_94 &= ~ V_141 ;
}
if ( ! ( V_123 -> V_94 & V_141 ) ||
F_88 ( V_123 , F_91 ( V_146 -> V_169 ) , V_146 -> V_170 ) )
F_85 ( V_123 , V_147 ) ;
F_55 ( & V_123 -> V_93 ) ;
break;
}
}
F_29 ( & V_31 -> V_36 ) ;
return 0 ;
}
int F_99 ( struct V_143 * V_144 )
{
struct V_87 * V_123 ;
struct V_30 * V_31 ;
struct V_148 * V_149 ;
int V_171 ;
if ( V_144 -> V_172 == V_173 )
return 0 ;
if ( V_144 -> V_172 != V_174 &&
V_144 -> V_172 != V_175 )
return 0 ;
if ( ! F_90 ( V_144 , sizeof( * V_149 ) - sizeof( struct V_166 ) ) )
return - V_14 ;
V_149 = (struct V_148 * ) F_95 ( V_144 ) ;
V_171 = F_94 ( & F_92 ( V_144 ) -> V_155 ) ;
if ( V_171 != V_158 &&
! ( V_171 & V_156 ) )
return - V_14 ;
V_31 = F_22 ( V_144 -> V_7 ) ;
if ( V_31 == NULL )
return - V_22 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_123 = V_31 -> V_116 ; V_123 ; V_123 = V_123 -> V_18 ) {
if ( F_7 ( & V_123 -> V_91 , & V_149 -> V_157 ) ) {
F_16 ( & V_123 -> V_93 ) ;
if ( F_62 ( & V_123 -> V_101 ) )
F_63 ( & V_123 -> V_88 ) ;
V_123 -> V_94 &= ~ ( V_176 | V_137 ) ;
F_18 ( & V_123 -> V_93 ) ;
break;
}
}
F_29 ( & V_31 -> V_36 ) ;
return 0 ;
}
static bool F_100 ( struct V_87 * V_43 , struct V_104 * V_105 , int type ,
int V_177 , int V_178 )
{
switch ( type ) {
case V_179 :
case V_180 :
if ( V_177 || V_178 )
return false ;
if ( ! ( ( V_43 -> V_94 & V_141 ) && ! V_105 -> V_142 ) ) {
if ( V_43 -> V_103 == V_60 )
return true ;
if ( V_105 -> V_127 [ V_60 ] )
return type == V_179 ;
return V_43 -> V_122 [ V_24 ] ==
V_105 -> V_127 [ V_24 ] ;
}
return false ;
case V_181 :
if ( V_177 || V_178 )
return false ;
return V_105 -> V_127 [ V_60 ] != 0 ;
case V_182 :
if ( V_177 || V_178 )
return false ;
if ( V_43 -> V_122 [ V_24 ] == 0 ||
V_105 -> V_127 [ V_60 ] )
return false ;
return V_43 -> V_122 [ V_24 ] ==
V_105 -> V_127 [ V_24 ] ;
case V_183 :
if ( V_177 || ! V_105 -> V_109 )
return false ;
return ( V_43 -> V_103 == V_60 ) ^ V_178 ;
case V_184 :
if ( V_43 -> V_103 == V_60 )
return V_177 || ( V_105 -> V_109 && V_178 ) ;
return V_105 -> V_109 && ! V_177 && ! V_178 ;
}
return false ;
}
static int
F_101 ( struct V_87 * V_43 , int type , int V_177 , int V_178 )
{
struct V_104 * V_105 ;
int V_140 = 0 ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( ! F_100 ( V_43 , V_105 , type , V_177 , V_178 ) )
continue;
V_140 ++ ;
}
return V_140 ;
}
static void F_102 ( struct V_1 * V_2 , struct V_143 * V_144 ,
struct V_6 * V_7 ,
const struct V_4 * V_155 ,
const struct V_4 * V_185 ,
int V_186 , int V_152 )
{
struct V_154 * V_187 ;
V_144 -> V_188 = F_103 ( V_189 ) ;
V_144 -> V_7 = V_7 ;
F_104 ( V_144 ) ;
F_105 ( V_144 , sizeof( struct V_154 ) ) ;
V_187 = F_92 ( V_144 ) ;
F_106 ( V_187 , 0 , 0 ) ;
V_187 -> V_153 = F_103 ( V_152 ) ;
V_187 -> V_190 = V_186 ;
V_187 -> V_191 = F_2 ( V_2 ) -> V_191 ;
V_187 -> V_155 = * V_155 ;
V_187 -> V_185 = * V_185 ;
}
static struct V_143 * F_107 ( struct V_30 * V_31 , int V_192 )
{
struct V_6 * V_7 = V_31 -> V_7 ;
struct V_12 * V_12 = F_108 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_193 . V_194 ;
struct V_143 * V_144 ;
struct V_195 * V_196 ;
struct V_4 V_197 ;
const struct V_4 * V_155 ;
int V_198 = F_109 ( V_7 ) ;
int V_199 = V_7 -> V_200 ;
int V_13 ;
T_3 V_201 [ 8 ] = { V_202 , 0 ,
V_203 , 2 , 0 , 0 ,
V_204 , 0 } ;
V_192 += V_198 + V_199 ;
V_192 = F_110 ( int , V_192 , F_111 ( 0 , 0 ) ) ;
V_144 = F_112 ( V_2 , V_192 , 1 , & V_13 ) ;
if ( ! V_144 )
return NULL ;
F_113 ( V_144 , V_198 ) ;
if ( F_114 ( V_31 , & V_197 , V_205 ) ) {
V_155 = & V_206 ;
} else
V_155 = & V_197 ;
F_102 ( V_2 , V_144 , V_7 , V_155 , & V_207 , V_208 , 0 ) ;
memcpy ( F_105 ( V_144 , sizeof( V_201 ) ) , V_201 , sizeof( V_201 ) ) ;
F_115 ( V_144 , F_116 ( V_144 ) - V_144 -> V_209 ) ;
F_105 ( V_144 , sizeof( * V_196 ) ) ;
V_196 = (struct V_195 * ) F_97 ( V_144 ) ;
V_196 -> V_210 = V_211 ;
V_196 -> V_212 = 0 ;
V_196 -> V_213 = 0 ;
V_196 -> V_214 = 0 ;
V_196 -> V_215 = 0 ;
return V_144 ;
}
static void F_117 ( struct V_143 * V_144 )
{
struct V_154 * V_216 = F_92 ( V_144 ) ;
struct V_195 * V_196 =
(struct V_195 * ) F_97 ( V_144 ) ;
int V_153 , V_217 ;
struct V_30 * V_31 ;
struct V_12 * V_12 = F_108 ( V_144 -> V_7 ) ;
int V_13 ;
struct V_218 V_219 ;
struct V_220 * V_21 ;
F_5 () ;
V_31 = F_22 ( V_144 -> V_7 ) ;
F_118 ( V_12 , V_31 , V_221 , V_144 -> V_152 ) ;
V_153 = ( F_116 ( V_144 ) - F_119 ( V_144 ) ) -
sizeof( * V_216 ) ;
V_217 = F_116 ( V_144 ) - F_97 ( V_144 ) ;
V_216 -> V_153 = F_103 ( V_153 ) ;
V_196 -> V_213 = F_120 ( & V_216 -> V_155 , & V_216 -> V_185 , V_217 ,
V_202 ,
F_121 ( F_97 ( V_144 ) ,
V_217 , 0 ) ) ;
F_122 ( V_12 -> V_193 . V_194 , & V_219 , V_211 ,
& F_92 ( V_144 ) -> V_155 , & F_92 ( V_144 ) -> V_185 ,
V_144 -> V_7 -> V_3 ) ;
V_21 = F_123 ( V_144 -> V_7 , & V_219 ) ;
V_13 = 0 ;
if ( F_124 ( V_21 ) ) {
V_13 = F_125 ( V_21 ) ;
V_21 = NULL ;
}
F_126 ( V_144 , V_21 ) ;
if ( V_13 )
goto V_222;
V_153 = V_144 -> V_152 ;
V_13 = F_127 ( V_223 , V_224 , V_144 , NULL , V_144 -> V_7 ,
V_225 ) ;
V_226:
if ( ! V_13 ) {
F_128 ( V_12 , V_31 , V_211 ) ;
F_129 ( V_12 , V_31 , V_227 ) ;
F_130 ( V_12 , V_31 , V_228 , V_153 ) ;
} else
F_131 ( V_12 , V_31 , V_229 ) ;
F_8 () ;
return;
V_222:
F_132 ( V_144 ) ;
goto V_226;
}
static int F_133 ( struct V_87 * V_43 , int type , int V_230 , int V_231 )
{
return sizeof( struct V_232 ) + 16 * F_101 ( V_43 , type , V_230 , V_231 ) ;
}
static struct V_143 * F_134 ( struct V_143 * V_144 , struct V_87 * V_43 ,
int type , struct V_232 * * V_233 )
{
struct V_6 * V_7 = V_43 -> V_31 -> V_7 ;
struct V_195 * V_196 ;
struct V_232 * V_234 ;
if ( ! V_144 )
V_144 = F_107 ( V_43 -> V_31 , V_7 -> V_235 ) ;
if ( ! V_144 )
return NULL ;
V_234 = (struct V_232 * ) F_105 ( V_144 , sizeof( struct V_232 ) ) ;
V_234 -> V_236 = type ;
V_234 -> V_237 = 0 ;
V_234 -> V_238 = 0 ;
V_234 -> V_239 = V_43 -> V_91 ;
V_196 = (struct V_195 * ) F_97 ( V_144 ) ;
V_196 -> V_215 = F_103 ( F_91 ( V_196 -> V_215 ) + 1 ) ;
* V_233 = V_234 ;
return V_144 ;
}
static struct V_143 * F_135 ( struct V_143 * V_144 , struct V_87 * V_43 ,
int type , int V_177 , int V_178 )
{
struct V_30 * V_31 = V_43 -> V_31 ;
struct V_6 * V_7 = V_31 -> V_7 ;
struct V_195 * V_196 ;
struct V_232 * V_234 = NULL ;
struct V_104 * V_105 , * V_114 , * V_240 , * * V_241 ;
int V_140 , V_242 , V_243 , V_244 , V_245 ;
if ( V_43 -> V_94 & V_98 )
return V_144 ;
V_244 = type == V_179 ||
type == V_180 ;
V_245 = type == V_180 ||
type == V_182 ;
V_242 = V_140 = 0 ;
V_241 = V_178 ? & V_43 -> V_106 : & V_43 -> V_107 ;
if ( ! * V_241 )
goto V_246;
V_196 = V_144 ? (struct V_195 * ) F_97 ( V_144 ) : NULL ;
if ( V_245 ) {
if ( V_196 && V_196 -> V_215 &&
F_136 ( V_144 ) < F_133 ( V_43 , type , V_177 , V_178 ) ) {
if ( V_144 )
F_117 ( V_144 ) ;
V_144 = F_107 ( V_31 , V_7 -> V_235 ) ;
}
}
V_243 = 1 ;
V_240 = NULL ;
for ( V_105 = * V_241 ; V_105 ; V_105 = V_114 ) {
struct V_4 * V_247 ;
V_114 = V_105 -> V_108 ;
if ( ! F_100 ( V_43 , V_105 , type , V_177 , V_178 ) ) {
V_240 = V_105 ;
continue;
}
if ( V_244 )
V_105 -> V_142 = 0 ;
if ( F_136 ( V_144 ) < sizeof( * V_247 ) +
V_243 * sizeof( struct V_232 ) ) {
if ( V_245 && ! V_243 )
break;
if ( V_234 )
V_234 -> V_238 = F_103 ( V_140 ) ;
if ( V_144 )
F_117 ( V_144 ) ;
V_144 = F_107 ( V_31 , V_7 -> V_235 ) ;
V_243 = 1 ;
V_140 = 0 ;
}
if ( V_243 ) {
V_144 = F_134 ( V_144 , V_43 , type , & V_234 ) ;
V_243 = 0 ;
}
if ( ! V_144 )
return NULL ;
V_247 = (struct V_4 * ) F_105 ( V_144 , sizeof( * V_247 ) ) ;
* V_247 = V_105 -> V_126 ;
V_140 ++ ; V_242 ++ ;
if ( ( type == V_183 ||
type == V_184 ) && V_105 -> V_109 ) {
V_105 -> V_109 -- ;
if ( ( V_178 || V_177 ) && V_105 -> V_109 == 0 ) {
if ( V_240 )
V_240 -> V_108 = V_105 -> V_108 ;
else
* V_241 = V_105 -> V_108 ;
F_49 ( V_105 ) ;
continue;
}
}
V_240 = V_105 ;
}
V_246:
if ( ! V_242 ) {
if ( type == V_183 ||
type == V_184 )
return V_144 ;
if ( V_43 -> V_99 || V_244 ) {
if ( V_144 && F_136 ( V_144 ) < sizeof( struct V_232 ) ) {
F_117 ( V_144 ) ;
V_144 = NULL ;
}
V_144 = F_134 ( V_144 , V_43 , type , & V_234 ) ;
}
}
if ( V_234 )
V_234 -> V_238 = F_103 ( V_140 ) ;
if ( V_244 )
V_43 -> V_94 &= ~ V_141 ;
return V_144 ;
}
static void F_137 ( struct V_30 * V_31 , struct V_87 * V_43 )
{
struct V_143 * V_144 = NULL ;
int type ;
F_28 ( & V_31 -> V_36 ) ;
if ( ! V_43 ) {
for ( V_43 = V_31 -> V_116 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( V_43 -> V_94 & V_98 )
continue;
F_52 ( & V_43 -> V_93 ) ;
if ( V_43 -> V_122 [ V_24 ] )
type = V_180 ;
else
type = V_179 ;
V_144 = F_135 ( V_144 , V_43 , type , 0 , 0 ) ;
F_55 ( & V_43 -> V_93 ) ;
}
} else {
F_52 ( & V_43 -> V_93 ) ;
if ( V_43 -> V_122 [ V_24 ] )
type = V_180 ;
else
type = V_179 ;
V_144 = F_135 ( V_144 , V_43 , type , 0 , 0 ) ;
F_55 ( & V_43 -> V_93 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
if ( V_144 )
F_117 ( V_144 ) ;
}
static void F_138 ( struct V_104 * * V_248 )
{
struct V_104 * V_240 , * V_114 , * V_105 ;
V_240 = NULL ;
for ( V_105 = * V_248 ; V_105 ; V_105 = V_114 ) {
V_114 = V_105 -> V_108 ;
if ( V_105 -> V_109 == 0 ) {
if ( V_240 )
V_240 -> V_108 = V_105 -> V_108 ;
else
* V_248 = V_105 -> V_108 ;
F_49 ( V_105 ) ;
} else
V_240 = V_105 ;
}
}
static void F_139 ( struct V_30 * V_31 )
{
struct V_87 * V_43 , * V_113 , * V_249 ;
struct V_143 * V_144 = NULL ;
int type , V_250 ;
F_28 ( & V_31 -> V_36 ) ;
F_16 ( & V_31 -> V_110 ) ;
V_113 = NULL ;
for ( V_43 = V_31 -> V_111 ; V_43 ; V_43 = V_249 ) {
V_249 = V_43 -> V_18 ;
if ( V_43 -> V_103 == V_60 ) {
type = V_184 ;
V_250 = V_184 ;
V_144 = F_135 ( V_144 , V_43 , type , 1 , 0 ) ;
V_144 = F_135 ( V_144 , V_43 , V_250 , 1 , 1 ) ;
}
if ( V_43 -> V_99 ) {
if ( V_43 -> V_103 == V_24 ) {
type = V_181 ;
V_144 = F_135 ( V_144 , V_43 , type , 1 , 0 ) ;
}
V_43 -> V_99 -- ;
if ( V_43 -> V_99 == 0 ) {
F_138 ( & V_43 -> V_106 ) ;
F_138 ( & V_43 -> V_107 ) ;
}
}
if ( V_43 -> V_99 == 0 && ! V_43 -> V_106 &&
! V_43 -> V_107 ) {
if ( V_113 )
V_113 -> V_18 = V_249 ;
else
V_31 -> V_111 = V_249 ;
F_48 ( V_43 -> V_31 ) ;
F_49 ( V_43 ) ;
} else
V_113 = V_43 ;
}
F_18 ( & V_31 -> V_110 ) ;
for ( V_43 = V_31 -> V_116 ; V_43 ; V_43 = V_43 -> V_18 ) {
F_52 ( & V_43 -> V_93 ) ;
if ( V_43 -> V_122 [ V_24 ] ) {
type = V_184 ;
V_250 = V_183 ;
} else {
type = V_183 ;
V_250 = V_184 ;
}
V_144 = F_135 ( V_144 , V_43 , type , 0 , 0 ) ;
V_144 = F_135 ( V_144 , V_43 , V_250 , 0 , 1 ) ;
if ( V_43 -> V_99 ) {
if ( V_43 -> V_103 == V_24 )
type = V_182 ;
else
type = V_181 ;
V_144 = F_135 ( V_144 , V_43 , type , 0 , 0 ) ;
V_43 -> V_99 -- ;
}
F_55 ( & V_43 -> V_93 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
if ( ! V_144 )
return;
( void ) F_117 ( V_144 ) ;
}
static void F_140 ( struct V_4 * V_5 , struct V_6 * V_7 , int type )
{
struct V_12 * V_12 = F_108 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_193 . V_194 ;
struct V_30 * V_31 ;
struct V_143 * V_144 ;
struct V_148 * V_187 ;
const struct V_4 * V_251 , * V_155 ;
struct V_4 V_197 ;
int V_198 = F_109 ( V_7 ) ;
int V_199 = V_7 -> V_200 ;
int V_13 , V_152 , V_153 , V_252 ;
T_3 V_201 [ 8 ] = { V_202 , 0 ,
V_203 , 2 , 0 , 0 ,
V_204 , 0 } ;
struct V_218 V_219 ;
struct V_220 * V_21 ;
if ( type == V_253 )
V_251 = & V_254 ;
else
V_251 = V_5 ;
V_152 = sizeof( struct V_166 ) + sizeof( struct V_4 ) ;
V_153 = V_152 + sizeof( V_201 ) ;
V_252 = sizeof( struct V_154 ) + V_153 ;
F_5 () ;
F_118 ( V_12 , F_22 ( V_7 ) ,
V_221 , V_252 ) ;
F_8 () ;
V_144 = F_112 ( V_2 , V_198 + V_199 + V_252 , 1 , & V_13 ) ;
if ( V_144 == NULL ) {
F_5 () ;
F_141 ( V_12 , F_22 ( V_7 ) ,
V_229 ) ;
F_8 () ;
return;
}
F_113 ( V_144 , V_198 ) ;
if ( F_142 ( V_7 , & V_197 , V_205 ) ) {
V_155 = & V_206 ;
} else
V_155 = & V_197 ;
F_102 ( V_2 , V_144 , V_7 , V_155 , V_251 , V_208 , V_153 ) ;
memcpy ( F_105 ( V_144 , sizeof( V_201 ) ) , V_201 , sizeof( V_201 ) ) ;
V_187 = (struct V_148 * ) F_105 ( V_144 , sizeof( struct V_148 ) ) ;
memset ( V_187 , 0 , sizeof( struct V_148 ) ) ;
V_187 -> V_255 = type ;
V_187 -> V_157 = * V_5 ;
V_187 -> V_256 = F_120 ( V_155 , V_251 , V_152 ,
V_202 ,
F_121 ( V_187 , V_152 , 0 ) ) ;
F_5 () ;
V_31 = F_22 ( V_144 -> V_7 ) ;
F_122 ( V_2 , & V_219 , type ,
& F_92 ( V_144 ) -> V_155 , & F_92 ( V_144 ) -> V_185 ,
V_144 -> V_7 -> V_3 ) ;
V_21 = F_123 ( V_144 -> V_7 , & V_219 ) ;
if ( F_124 ( V_21 ) ) {
V_13 = F_125 ( V_21 ) ;
goto V_222;
}
F_126 ( V_144 , V_21 ) ;
V_13 = F_127 ( V_223 , V_224 , V_144 , NULL , V_144 -> V_7 ,
V_225 ) ;
V_226:
if ( ! V_13 ) {
F_143 ( V_12 , V_31 , type ) ;
F_144 ( V_12 , V_31 , V_227 ) ;
F_118 ( V_12 , V_31 , V_228 , V_252 ) ;
} else
F_141 ( V_12 , V_31 , V_229 ) ;
F_8 () ;
return;
V_222:
F_132 ( V_144 ) ;
goto V_226;
}
static void F_145 ( struct V_30 * V_31 )
{
if ( F_56 ( V_31 ) ) {
struct V_87 * V_257 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_257 = V_31 -> V_116 ; V_257 ; V_257 = V_257 -> V_18 ) {
if ( ! ( V_257 -> V_94 & V_98 ) )
F_140 ( & V_257 -> V_91 , V_31 -> V_7 ,
V_258 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
} else {
F_137 ( V_31 , NULL ) ;
}
}
void F_146 ( struct V_30 * V_31 )
{
V_31 -> V_259 = V_31 -> V_100 ;
if ( V_31 -> V_259 ) {
F_145 ( V_31 ) ;
V_31 -> V_259 -- ;
if ( V_31 -> V_259 )
F_84 ( V_31 , V_31 -> V_129 ) ;
}
}
static void F_147 ( unsigned long V_209 )
{
struct V_30 * V_31 = (struct V_30 * ) V_209 ;
F_145 ( V_31 ) ;
if ( V_31 -> V_259 ) {
V_31 -> V_259 -- ;
if ( V_31 -> V_259 )
F_84 ( V_31 , V_31 -> V_129 ) ;
}
F_96 ( V_31 ) ;
}
static int F_148 ( struct V_87 * V_43 , int V_23 ,
const struct V_4 * V_260 )
{
struct V_104 * V_105 , * V_240 ;
int V_49 = 0 ;
V_240 = NULL ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( F_7 ( & V_105 -> V_126 , V_260 ) )
break;
V_240 = V_105 ;
}
if ( ! V_105 || V_105 -> V_127 [ V_23 ] == 0 ) {
return - V_261 ;
}
V_105 -> V_127 [ V_23 ] -- ;
if ( ! V_105 -> V_127 [ V_60 ] && ! V_105 -> V_127 [ V_24 ] ) {
struct V_30 * V_31 = V_43 -> V_31 ;
if ( V_240 )
V_240 -> V_108 = V_105 -> V_108 ;
else
V_43 -> V_107 = V_105 -> V_108 ;
if ( V_105 -> V_262 && ! ( V_43 -> V_94 & V_98 ) &&
! F_56 ( V_31 ) ) {
V_105 -> V_109 = V_31 -> V_100 ;
V_105 -> V_108 = V_43 -> V_106 ;
V_43 -> V_106 = V_105 ;
V_49 = 1 ;
} else
F_49 ( V_105 ) ;
}
return V_49 ;
}
static int F_34 ( struct V_30 * V_31 , const struct V_4 * V_112 ,
int V_23 , int V_263 , const struct V_4 * V_260 ,
int V_264 )
{
struct V_87 * V_43 ;
int V_265 = 0 ;
int V_47 , V_13 ;
if ( ! V_31 )
return - V_22 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_116 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( F_7 ( V_112 , & V_43 -> V_91 ) )
break;
}
if ( ! V_43 ) {
F_29 ( & V_31 -> V_36 ) ;
return - V_261 ;
}
F_52 ( & V_43 -> V_93 ) ;
F_149 ( V_43 ) ;
if ( ! V_264 ) {
if ( ! V_43 -> V_122 [ V_23 ] ) {
F_55 ( & V_43 -> V_93 ) ;
F_29 ( & V_31 -> V_36 ) ;
return - V_14 ;
}
V_43 -> V_122 [ V_23 ] -- ;
}
V_13 = 0 ;
for ( V_47 = 0 ; V_47 < V_263 ; V_47 ++ ) {
int V_49 = F_148 ( V_43 , V_23 , & V_260 [ V_47 ] ) ;
V_265 |= V_49 > 0 ;
if ( ! V_13 && V_49 < 0 )
V_13 = V_49 ;
}
if ( V_43 -> V_103 == V_24 &&
V_43 -> V_122 [ V_24 ] == 0 &&
V_43 -> V_122 [ V_60 ] ) {
struct V_104 * V_105 ;
V_43 -> V_103 = V_60 ;
V_43 -> V_99 = V_31 -> V_100 ;
V_31 -> V_164 = V_43 -> V_99 ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
V_105 -> V_109 = 0 ;
F_58 ( V_43 -> V_31 ) ;
} else if ( F_150 ( V_43 ) || V_265 )
F_58 ( V_43 -> V_31 ) ;
F_55 ( & V_43 -> V_93 ) ;
F_29 ( & V_31 -> V_36 ) ;
return V_13 ;
}
static int F_151 ( struct V_87 * V_43 , int V_23 ,
const struct V_4 * V_260 )
{
struct V_104 * V_105 , * V_240 ;
V_240 = NULL ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( F_7 ( & V_105 -> V_126 , V_260 ) )
break;
V_240 = V_105 ;
}
if ( ! V_105 ) {
V_105 = F_66 ( sizeof( * V_105 ) , V_67 ) ;
if ( ! V_105 )
return - V_62 ;
V_105 -> V_126 = * V_260 ;
if ( V_240 ) {
V_240 -> V_108 = V_105 ;
} else
V_43 -> V_107 = V_105 ;
}
V_105 -> V_127 [ V_23 ] ++ ;
return 0 ;
}
static void F_149 ( struct V_87 * V_43 )
{
struct V_104 * V_105 ;
int V_266 = V_43 -> V_122 [ V_24 ] ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
if ( V_43 -> V_122 [ V_24 ] ) {
V_105 -> V_262 = V_266 ==
V_105 -> V_127 [ V_24 ] &&
! V_105 -> V_127 [ V_60 ] ;
} else
V_105 -> V_262 = V_105 -> V_127 [ V_60 ] != 0 ;
}
static int F_150 ( struct V_87 * V_43 )
{
struct V_104 * V_105 , * V_267 ;
int V_266 = V_43 -> V_122 [ V_24 ] ;
int V_268 = V_43 -> V_31 -> V_100 ;
int V_269 , V_49 ;
V_49 = 0 ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( V_43 -> V_122 [ V_24 ] ) {
V_269 = V_266 == V_105 -> V_127 [ V_24 ] &&
! V_105 -> V_127 [ V_60 ] ;
} else
V_269 = V_105 -> V_127 [ V_60 ] != 0 ;
if ( V_269 ) {
if ( ! V_105 -> V_262 ) {
struct V_104 * V_270 = NULL ;
for ( V_267 = V_43 -> V_106 ; V_267 ;
V_267 = V_267 -> V_108 ) {
if ( F_7 ( & V_267 -> V_126 ,
& V_105 -> V_126 ) )
break;
V_270 = V_267 ;
}
if ( V_267 ) {
if ( V_270 )
V_270 -> V_108 = V_267 -> V_108 ;
else
V_43 -> V_106 = V_267 -> V_108 ;
F_49 ( V_267 ) ;
}
V_105 -> V_109 = V_268 ;
V_49 ++ ;
}
} else if ( V_105 -> V_262 ) {
V_105 -> V_109 = 0 ;
for ( V_267 = V_43 -> V_106 ; V_267 ; V_267 = V_267 -> V_108 )
if ( F_7 ( & V_267 -> V_126 ,
& V_105 -> V_126 ) )
break;
if ( ! V_267 ) {
V_267 = F_152 ( sizeof( * V_267 ) , V_67 ) ;
if ( ! V_267 )
continue;
* V_267 = * V_105 ;
V_267 -> V_108 = V_43 -> V_106 ;
V_43 -> V_106 = V_267 ;
}
V_267 -> V_109 = V_268 ;
V_49 ++ ;
}
}
return V_49 ;
}
static int F_33 ( struct V_30 * V_31 , const struct V_4 * V_112 ,
int V_23 , int V_263 , const struct V_4 * V_260 ,
int V_264 )
{
struct V_87 * V_43 ;
int V_271 ;
int V_47 , V_13 ;
if ( ! V_31 )
return - V_22 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_116 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( F_7 ( V_112 , & V_43 -> V_91 ) )
break;
}
if ( ! V_43 ) {
F_29 ( & V_31 -> V_36 ) ;
return - V_261 ;
}
F_52 ( & V_43 -> V_93 ) ;
F_149 ( V_43 ) ;
V_271 = V_43 -> V_103 == V_24 ;
if ( ! V_264 )
V_43 -> V_122 [ V_23 ] ++ ;
V_13 = 0 ;
for ( V_47 = 0 ; V_47 < V_263 ; V_47 ++ ) {
V_13 = F_151 ( V_43 , V_23 , & V_260 [ V_47 ] ) ;
if ( V_13 )
break;
}
if ( V_13 ) {
int V_48 ;
if ( ! V_264 )
V_43 -> V_122 [ V_23 ] -- ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
F_148 ( V_43 , V_23 , & V_260 [ V_48 ] ) ;
} else if ( V_271 != ( V_43 -> V_122 [ V_24 ] != 0 ) ) {
struct V_104 * V_105 ;
if ( V_43 -> V_122 [ V_24 ] )
V_43 -> V_103 = V_24 ;
else if ( V_43 -> V_122 [ V_60 ] )
V_43 -> V_103 = V_60 ;
V_43 -> V_99 = V_31 -> V_100 ;
V_31 -> V_164 = V_43 -> V_99 ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
V_105 -> V_109 = 0 ;
F_58 ( V_31 ) ;
} else if ( F_150 ( V_43 ) )
F_58 ( V_31 ) ;
F_55 ( & V_43 -> V_93 ) ;
F_29 ( & V_31 -> V_36 ) ;
return V_13 ;
}
static void F_64 ( struct V_87 * V_43 )
{
struct V_104 * V_105 , * V_272 ;
for ( V_105 = V_43 -> V_106 ; V_105 ; V_105 = V_272 ) {
V_272 = V_105 -> V_108 ;
F_49 ( V_105 ) ;
}
V_43 -> V_106 = NULL ;
for ( V_105 = V_43 -> V_107 ; V_105 ; V_105 = V_272 ) {
V_272 = V_105 -> V_108 ;
F_49 ( V_105 ) ;
}
V_43 -> V_107 = NULL ;
V_43 -> V_103 = V_24 ;
V_43 -> V_122 [ V_60 ] = 0 ;
V_43 -> V_122 [ V_24 ] = 1 ;
}
static void F_57 ( struct V_87 * V_123 )
{
unsigned long V_132 ;
if ( V_123 -> V_94 & V_98 )
return;
F_140 ( & V_123 -> V_91 , V_123 -> V_31 -> V_7 , V_258 ) ;
V_132 = F_81 () % V_273 ;
F_52 ( & V_123 -> V_93 ) ;
if ( F_62 ( & V_123 -> V_101 ) ) {
F_63 ( & V_123 -> V_88 ) ;
V_132 = V_123 -> V_101 . V_136 - V_121 ;
}
if ( ! F_82 ( & V_123 -> V_101 , V_121 + V_132 ) )
F_86 ( & V_123 -> V_88 ) ;
V_123 -> V_94 |= V_137 | V_176 ;
F_55 ( & V_123 -> V_93 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_8 * V_274 ,
struct V_30 * V_31 )
{
int V_13 ;
if ( ! V_274 -> V_26 ) {
return F_34 ( V_31 , & V_274 -> V_5 , V_274 -> V_23 , 0 , NULL , 0 ) ;
}
V_13 = F_34 ( V_31 , & V_274 -> V_5 , V_274 -> V_23 ,
V_274 -> V_26 -> V_58 , V_274 -> V_26 -> V_59 , 0 ) ;
F_13 ( V_2 , V_274 -> V_26 , F_36 ( V_274 -> V_26 -> V_63 ) ) ;
V_274 -> V_26 = NULL ;
return V_13 ;
}
static void F_61 ( struct V_87 * V_123 )
{
if ( F_56 ( V_123 -> V_31 ) ) {
if ( V_123 -> V_94 & V_176 )
F_140 ( & V_123 -> V_91 , V_123 -> V_31 -> V_7 ,
V_253 ) ;
} else {
F_65 ( V_123 -> V_31 , V_123 ) ;
F_58 ( V_123 -> V_31 ) ;
}
}
static void F_153 ( unsigned long V_209 )
{
struct V_30 * V_31 = (struct V_30 * ) V_209 ;
V_31 -> V_130 = 0 ;
F_137 ( V_31 , NULL ) ;
F_96 ( V_31 ) ;
}
static void F_154 ( unsigned long V_209 )
{
struct V_30 * V_31 = (struct V_30 * ) V_209 ;
F_139 ( V_31 ) ;
if ( V_31 -> V_164 ) {
V_31 -> V_164 -- ;
if ( V_31 -> V_164 )
F_83 ( V_31 , V_31 -> V_129 ) ;
}
F_96 ( V_31 ) ;
}
static void F_58 ( struct V_30 * V_31 )
{
if ( F_56 ( V_31 ) )
return;
V_31 -> V_164 = V_31 -> V_100 ;
F_83 ( V_31 , 1 ) ;
}
static void V_118 ( unsigned long V_209 )
{
struct V_87 * V_123 = (struct V_87 * ) V_209 ;
if ( F_56 ( V_123 -> V_31 ) )
F_140 ( & V_123 -> V_91 , V_123 -> V_31 -> V_7 , V_258 ) ;
else
F_137 ( V_123 -> V_31 , V_123 ) ;
F_16 ( & V_123 -> V_93 ) ;
V_123 -> V_94 |= V_176 ;
V_123 -> V_94 &= ~ V_137 ;
F_18 ( & V_123 -> V_93 ) ;
F_46 ( V_123 ) ;
}
void F_155 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_47 = V_31 -> V_116 ; V_47 ; V_47 = V_47 -> V_18 )
F_59 ( V_47 ) ;
F_29 ( & V_31 -> V_36 ) ;
}
void F_156 ( struct V_30 * V_31 )
{
F_157 ( V_31 ) ;
}
void F_158 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_28 ( & V_31 -> V_36 ) ;
V_31 -> V_164 = 0 ;
if ( F_62 ( & V_31 -> V_133 ) )
F_96 ( V_31 ) ;
V_31 -> V_130 = 0 ;
if ( F_62 ( & V_31 -> V_131 ) )
F_96 ( V_31 ) ;
if ( F_62 ( & V_31 -> V_134 ) )
F_96 ( V_31 ) ;
for ( V_47 = V_31 -> V_116 ; V_47 ; V_47 = V_47 -> V_18 )
F_59 ( V_47 ) ;
F_29 ( & V_31 -> V_36 ) ;
F_70 ( V_31 ) ;
}
void F_157 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_47 = V_31 -> V_116 ; V_47 ; V_47 = V_47 -> V_18 )
F_50 ( V_47 ) ;
F_29 ( & V_31 -> V_36 ) ;
}
void F_159 ( struct V_30 * V_31 )
{
F_72 ( & V_31 -> V_36 ) ;
F_67 ( & V_31 -> V_110 ) ;
V_31 -> V_130 = 0 ;
F_74 ( & V_31 -> V_131 , F_153 ,
( unsigned long ) V_31 ) ;
V_31 -> V_111 = NULL ;
V_31 -> V_164 = 0 ;
F_74 ( & V_31 -> V_133 , F_154 ,
( unsigned long ) V_31 ) ;
F_74 ( & V_31 -> V_134 , F_147 ,
( unsigned long ) V_31 ) ;
V_31 -> V_100 = V_275 ;
V_31 -> V_129 = V_273 ;
V_31 -> V_163 = 0 ;
F_73 ( & V_31 -> V_36 ) ;
}
void F_160 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_158 ( V_31 ) ;
F_24 ( V_31 , & V_276 ) ;
if ( V_31 -> V_277 . V_278 )
F_24 ( V_31 , & V_254 ) ;
F_72 ( & V_31 -> V_36 ) ;
while ( ( V_47 = V_31 -> V_116 ) != NULL ) {
V_31 -> V_116 = V_47 -> V_18 ;
F_73 ( & V_31 -> V_36 ) ;
F_59 ( V_47 ) ;
F_46 ( V_47 ) ;
F_72 ( & V_31 -> V_36 ) ;
}
F_73 ( & V_31 -> V_36 ) ;
}
static inline struct V_87 * F_161 ( struct V_279 * V_280 )
{
struct V_87 * V_102 = NULL ;
struct V_281 * V_282 = F_162 ( V_280 ) ;
struct V_12 * V_12 = F_163 ( V_280 ) ;
V_282 -> V_31 = NULL ;
F_164 (net, state->dev) {
struct V_30 * V_31 ;
V_31 = F_22 ( V_282 -> V_7 ) ;
if ( ! V_31 )
continue;
F_28 ( & V_31 -> V_36 ) ;
V_102 = V_31 -> V_116 ;
if ( V_102 ) {
V_282 -> V_31 = V_31 ;
break;
}
F_29 ( & V_31 -> V_36 ) ;
}
return V_102 ;
}
static struct V_87 * F_165 ( struct V_279 * V_280 , struct V_87 * V_102 )
{
struct V_281 * V_282 = F_162 ( V_280 ) ;
V_102 = V_102 -> V_18 ;
while ( ! V_102 ) {
if ( F_166 ( V_282 -> V_31 != NULL ) )
F_29 ( & V_282 -> V_31 -> V_36 ) ;
V_282 -> V_7 = F_167 ( V_282 -> V_7 ) ;
if ( ! V_282 -> V_7 ) {
V_282 -> V_31 = NULL ;
break;
}
V_282 -> V_31 = F_22 ( V_282 -> V_7 ) ;
if ( ! V_282 -> V_31 )
continue;
F_28 ( & V_282 -> V_31 -> V_36 ) ;
V_102 = V_282 -> V_31 -> V_116 ;
}
return V_102 ;
}
static struct V_87 * F_168 ( struct V_279 * V_280 , T_4 V_283 )
{
struct V_87 * V_102 = F_161 ( V_280 ) ;
if ( V_102 )
while ( V_283 && ( V_102 = F_165 ( V_280 , V_102 ) ) != NULL )
-- V_283 ;
return V_283 ? NULL : V_102 ;
}
static void * F_169 ( struct V_279 * V_280 , T_4 * V_283 )
__acquires( T_5 )
{
F_5 () ;
return F_168 ( V_280 , * V_283 ) ;
}
static void * F_170 ( struct V_279 * V_280 , void * V_284 , T_4 * V_283 )
{
struct V_87 * V_102 = F_165 ( V_280 , V_284 ) ;
++ * V_283 ;
return V_102 ;
}
static void F_171 ( struct V_279 * V_280 , void * V_284 )
__releases( T_5 )
{
struct V_281 * V_282 = F_162 ( V_280 ) ;
if ( F_166 ( V_282 -> V_31 != NULL ) ) {
F_29 ( & V_282 -> V_31 -> V_36 ) ;
V_282 -> V_31 = NULL ;
}
V_282 -> V_7 = NULL ;
F_8 () ;
}
static int F_172 ( struct V_279 * V_280 , void * V_284 )
{
struct V_87 * V_102 = (struct V_87 * ) V_284 ;
struct V_281 * V_282 = F_162 ( V_280 ) ;
F_173 ( V_280 ,
L_1 ,
V_282 -> V_7 -> V_3 , V_282 -> V_7 -> V_285 ,
& V_102 -> V_91 ,
V_102 -> V_117 , V_102 -> V_94 ,
( V_102 -> V_94 & V_137 ) ?
F_174 ( V_102 -> V_101 . V_136 - V_121 ) : 0 ) ;
return 0 ;
}
static int F_175 ( struct V_286 * V_286 , struct V_287 * V_287 )
{
return F_176 ( V_286 , V_287 , & V_288 ,
sizeof( struct V_281 ) ) ;
}
static inline struct V_104 * F_177 ( struct V_279 * V_280 )
{
struct V_104 * V_105 = NULL ;
struct V_87 * V_102 = NULL ;
struct V_289 * V_282 = F_178 ( V_280 ) ;
struct V_12 * V_12 = F_163 ( V_280 ) ;
V_282 -> V_31 = NULL ;
V_282 -> V_102 = NULL ;
F_164 (net, state->dev) {
struct V_30 * V_31 ;
V_31 = F_22 ( V_282 -> V_7 ) ;
if ( F_179 ( V_31 == NULL ) )
continue;
F_28 ( & V_31 -> V_36 ) ;
V_102 = V_31 -> V_116 ;
if ( F_166 ( V_102 != NULL ) ) {
F_52 ( & V_102 -> V_93 ) ;
V_105 = V_102 -> V_107 ;
if ( F_166 ( V_105 != NULL ) ) {
V_282 -> V_102 = V_102 ;
V_282 -> V_31 = V_31 ;
break;
}
F_55 ( & V_102 -> V_93 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
}
return V_105 ;
}
static struct V_104 * F_180 ( struct V_279 * V_280 , struct V_104 * V_105 )
{
struct V_289 * V_282 = F_178 ( V_280 ) ;
V_105 = V_105 -> V_108 ;
while ( ! V_105 ) {
F_55 ( & V_282 -> V_102 -> V_93 ) ;
V_282 -> V_102 = V_282 -> V_102 -> V_18 ;
while ( ! V_282 -> V_102 ) {
if ( F_166 ( V_282 -> V_31 != NULL ) )
F_29 ( & V_282 -> V_31 -> V_36 ) ;
V_282 -> V_7 = F_167 ( V_282 -> V_7 ) ;
if ( ! V_282 -> V_7 ) {
V_282 -> V_31 = NULL ;
goto V_226;
}
V_282 -> V_31 = F_22 ( V_282 -> V_7 ) ;
if ( ! V_282 -> V_31 )
continue;
F_28 ( & V_282 -> V_31 -> V_36 ) ;
V_282 -> V_102 = V_282 -> V_31 -> V_116 ;
}
if ( ! V_282 -> V_102 )
break;
F_52 ( & V_282 -> V_102 -> V_93 ) ;
V_105 = V_282 -> V_102 -> V_107 ;
}
V_226:
return V_105 ;
}
static struct V_104 * F_181 ( struct V_279 * V_280 , T_4 V_283 )
{
struct V_104 * V_105 = F_177 ( V_280 ) ;
if ( V_105 )
while ( V_283 && ( V_105 = F_180 ( V_280 , V_105 ) ) != NULL )
-- V_283 ;
return V_283 ? NULL : V_105 ;
}
static void * F_182 ( struct V_279 * V_280 , T_4 * V_283 )
__acquires( T_5 )
{
F_5 () ;
return * V_283 ? F_181 ( V_280 , * V_283 - 1 ) : V_290 ;
}
static void * F_183 ( struct V_279 * V_280 , void * V_284 , T_4 * V_283 )
{
struct V_104 * V_105 ;
if ( V_284 == V_290 )
V_105 = F_177 ( V_280 ) ;
else
V_105 = F_180 ( V_280 , V_284 ) ;
++ * V_283 ;
return V_105 ;
}
static void F_184 ( struct V_279 * V_280 , void * V_284 )
__releases( T_5 )
{
struct V_289 * V_282 = F_178 ( V_280 ) ;
if ( F_166 ( V_282 -> V_102 != NULL ) ) {
F_55 ( & V_282 -> V_102 -> V_93 ) ;
V_282 -> V_102 = NULL ;
}
if ( F_166 ( V_282 -> V_31 != NULL ) ) {
F_29 ( & V_282 -> V_31 -> V_36 ) ;
V_282 -> V_31 = NULL ;
}
V_282 -> V_7 = NULL ;
F_8 () ;
}
static int F_185 ( struct V_279 * V_280 , void * V_284 )
{
struct V_104 * V_105 = (struct V_104 * ) V_284 ;
struct V_289 * V_282 = F_178 ( V_280 ) ;
if ( V_284 == V_290 ) {
F_173 ( V_280 ,
L_2
L_3 , L_4 ,
L_5 , L_6 ,
L_7 , L_8 , L_9 ) ;
} else {
F_173 ( V_280 ,
L_10 ,
V_282 -> V_7 -> V_3 , V_282 -> V_7 -> V_285 ,
& V_282 -> V_102 -> V_91 ,
& V_105 -> V_126 ,
V_105 -> V_127 [ V_60 ] ,
V_105 -> V_127 [ V_24 ] ) ;
}
return 0 ;
}
static int F_186 ( struct V_286 * V_286 , struct V_287 * V_287 )
{
return F_176 ( V_286 , V_287 , & V_291 ,
sizeof( struct V_289 ) ) ;
}
static int T_6 F_187 ( struct V_12 * V_12 )
{
int V_13 ;
V_13 = - V_17 ;
if ( ! F_188 ( L_11 , V_292 , V_12 -> V_293 , & V_294 ) )
goto V_226;
if ( ! F_188 ( L_12 , V_292 , V_12 -> V_293 ,
& V_295 ) )
goto V_296;
V_13 = 0 ;
V_226:
return V_13 ;
V_296:
F_189 ( L_11 , V_12 -> V_293 ) ;
goto V_226;
}
static void T_7 F_190 ( struct V_12 * V_12 )
{
F_189 ( L_12 , V_12 -> V_293 ) ;
F_189 ( L_11 , V_12 -> V_293 ) ;
}
static inline int F_187 ( struct V_12 * V_12 )
{
return 0 ;
}
static inline void F_190 ( struct V_12 * V_12 )
{
}
static int T_6 F_191 ( struct V_12 * V_12 )
{
int V_13 ;
V_13 = F_192 ( & V_12 -> V_193 . V_194 , V_297 ,
V_298 , V_202 , V_12 ) ;
if ( V_13 < 0 ) {
F_193 ( L_13 ,
V_13 ) ;
goto V_226;
}
F_2 ( V_12 -> V_193 . V_194 ) -> V_191 = 1 ;
V_13 = F_187 ( V_12 ) ;
if ( V_13 )
goto V_299;
V_226:
return V_13 ;
V_299:
F_194 ( V_12 -> V_193 . V_194 ) ;
goto V_226;
}
static void T_7 F_195 ( struct V_12 * V_12 )
{
F_194 ( V_12 -> V_193 . V_194 ) ;
F_190 ( V_12 ) ;
}
int T_8 F_196 ( void )
{
return F_197 ( & V_300 ) ;
}
void F_198 ( void )
{
F_199 ( & V_300 ) ;
}
