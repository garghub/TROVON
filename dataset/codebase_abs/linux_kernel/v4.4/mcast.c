static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 ) )
V_3 = V_2 -> V_4 . V_5 ;
else
V_3 = V_2 -> V_4 . V_6 ;
return V_3 > 0 ? V_3 : 1 ;
}
int F_3 ( struct V_7 * V_8 , int V_9 , const struct V_10 * V_11 )
{
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 ;
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
int V_19 ;
F_6 () ;
if ( ! F_7 ( V_11 ) )
return - V_20 ;
F_8 () ;
F_9 (np, mc_lst) {
if ( ( V_9 == 0 || V_15 -> V_9 == V_9 ) &&
F_10 ( & V_15 -> V_11 , V_11 ) ) {
F_11 () ;
return - V_21 ;
}
}
F_11 () ;
V_15 = F_12 ( V_8 , sizeof( struct V_14 ) , V_22 ) ;
if ( ! V_15 )
return - V_23 ;
V_15 -> V_24 = NULL ;
V_15 -> V_11 = * V_11 ;
if ( V_9 == 0 ) {
struct V_25 * V_26 ;
V_26 = F_13 ( V_18 , V_11 , NULL , 0 , 0 ) ;
if ( V_26 ) {
V_13 = V_26 -> V_27 . V_13 ;
F_14 ( V_26 ) ;
}
} else
V_13 = F_15 ( V_18 , V_9 ) ;
if ( ! V_13 ) {
F_16 ( V_8 , V_15 , sizeof( * V_15 ) ) ;
return - V_28 ;
}
V_15 -> V_9 = V_13 -> V_9 ;
V_15 -> V_29 = V_30 ;
F_17 ( & V_15 -> V_31 ) ;
V_15 -> V_32 = NULL ;
V_19 = F_18 ( V_13 , V_11 ) ;
if ( V_19 ) {
F_16 ( V_8 , V_15 , sizeof( * V_15 ) ) ;
return V_19 ;
}
V_15 -> V_24 = V_17 -> V_33 ;
F_19 ( V_17 -> V_33 , V_15 ) ;
return 0 ;
}
int F_20 ( struct V_7 * V_8 , int V_9 , const struct V_10 * V_11 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_14 * V_15 ;
struct V_14 T_1 * * V_34 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
F_6 () ;
if ( ! F_7 ( V_11 ) )
return - V_20 ;
for ( V_34 = & V_17 -> V_33 ;
( V_15 = F_21 ( * V_34 ) ) != NULL ;
V_34 = & V_15 -> V_24 ) {
if ( ( V_9 == 0 || V_15 -> V_9 == V_9 ) &&
F_10 ( & V_15 -> V_11 , V_11 ) ) {
struct V_12 * V_13 ;
* V_34 = V_15 -> V_24 ;
V_13 = F_15 ( V_18 , V_15 -> V_9 ) ;
if ( V_13 ) {
struct V_1 * V_2 = F_22 ( V_13 ) ;
( void ) F_23 ( V_8 , V_15 , V_2 ) ;
if ( V_2 )
F_24 ( V_2 , & V_15 -> V_11 ) ;
} else
( void ) F_23 ( V_8 , V_15 , NULL ) ;
F_25 ( sizeof( * V_15 ) , & V_8 -> V_35 ) ;
F_26 ( V_15 , V_36 ) ;
return 0 ;
}
}
return - V_37 ;
}
static struct V_1 * F_27 ( struct V_18 * V_18 ,
const struct V_10 * V_38 ,
int V_9 )
{
struct V_12 * V_13 = NULL ;
struct V_1 * V_2 = NULL ;
if ( V_9 == 0 ) {
struct V_25 * V_26 = F_13 ( V_18 , V_38 , NULL , 0 , 0 ) ;
if ( V_26 ) {
V_13 = V_26 -> V_27 . V_13 ;
F_14 ( V_26 ) ;
}
} else
V_13 = F_28 ( V_18 , V_9 ) ;
if ( ! V_13 )
return NULL ;
V_2 = F_22 ( V_13 ) ;
if ( ! V_2 )
return NULL ;
F_29 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_40 ) {
F_30 ( & V_2 -> V_39 ) ;
return NULL ;
}
return V_2 ;
}
void F_31 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_14 * V_15 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
if ( ! F_32 ( V_17 -> V_33 ) )
return;
F_33 () ;
while ( ( V_15 = F_21 ( V_17 -> V_33 ) ) != NULL ) {
struct V_12 * V_13 ;
V_17 -> V_33 = V_15 -> V_24 ;
V_13 = F_15 ( V_18 , V_15 -> V_9 ) ;
if ( V_13 ) {
struct V_1 * V_2 = F_22 ( V_13 ) ;
( void ) F_23 ( V_8 , V_15 , V_2 ) ;
if ( V_2 )
F_24 ( V_2 , & V_15 -> V_11 ) ;
} else
( void ) F_23 ( V_8 , V_15 , NULL ) ;
F_25 ( sizeof( * V_15 ) , & V_8 -> V_35 ) ;
F_26 ( V_15 , V_36 ) ;
}
F_34 () ;
}
int F_35 ( int V_41 , int V_42 , struct V_7 * V_8 ,
struct V_43 * V_44 )
{
struct V_10 * V_45 , * V_38 ;
struct V_14 * V_46 ;
struct V_1 * V_2 ;
struct V_16 * V_47 = F_4 ( V_8 ) ;
struct V_48 * V_49 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
int V_50 , V_51 , V_52 ;
int V_53 = 0 ;
int V_54 = 0 ;
int V_19 ;
V_45 = & ( (struct V_55 * ) & V_44 -> V_56 ) -> V_57 ;
V_38 = & ( (struct V_55 * ) & V_44 -> V_58 ) -> V_57 ;
if ( ! F_7 ( V_38 ) )
return - V_20 ;
F_8 () ;
V_2 = F_27 ( V_18 , V_38 , V_44 -> V_59 ) ;
if ( ! V_2 ) {
F_11 () ;
return - V_28 ;
}
V_19 = - V_37 ;
F_9 (inet6, pmc) {
if ( V_44 -> V_59 && V_46 -> V_9 != V_44 -> V_59 )
continue;
if ( F_10 ( & V_46 -> V_11 , V_38 ) )
break;
}
if ( ! V_46 ) {
V_19 = - V_20 ;
goto V_60;
}
if ( V_46 -> V_32 ) {
if ( V_46 -> V_29 != V_42 ) {
V_19 = - V_20 ;
goto V_60;
}
} else if ( V_46 -> V_29 != V_42 ) {
F_36 ( V_2 , V_38 , V_42 , 0 , NULL , 0 ) ;
F_37 ( V_2 , V_38 , V_46 -> V_29 , 0 , NULL , 0 ) ;
V_46 -> V_29 = V_42 ;
}
F_38 ( & V_46 -> V_31 ) ;
V_54 = 1 ;
V_49 = V_46 -> V_32 ;
if ( ! V_41 ) {
if ( ! V_49 )
goto V_60;
V_52 = ! 0 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_61 ; V_50 ++ ) {
V_52 = ! F_10 ( & V_49 -> V_62 [ V_50 ] , V_45 ) ;
if ( V_52 == 0 )
break;
}
if ( V_52 )
goto V_60;
if ( V_49 -> V_61 == 1 && V_42 == V_63 ) {
V_53 = 1 ;
goto V_60;
}
F_37 ( V_2 , V_38 , V_42 , 1 , V_45 , 1 ) ;
for ( V_51 = V_50 + 1 ; V_51 < V_49 -> V_61 ; V_51 ++ )
V_49 -> V_62 [ V_51 - 1 ] = V_49 -> V_62 [ V_51 ] ;
V_49 -> V_61 -- ;
V_19 = 0 ;
goto V_60;
}
if ( V_49 && V_49 -> V_61 >= V_64 ) {
V_19 = - V_65 ;
goto V_60;
}
if ( ! V_49 || V_49 -> V_61 == V_49 -> V_66 ) {
struct V_48 * V_67 ;
int V_68 = V_69 ;
if ( V_49 )
V_68 += V_49 -> V_66 ;
V_67 = F_12 ( V_8 , F_39 ( V_68 ) , V_70 ) ;
if ( ! V_67 ) {
V_19 = - V_65 ;
goto V_60;
}
V_67 -> V_66 = V_68 ;
V_67 -> V_61 = V_68 - V_69 ;
if ( V_49 ) {
for ( V_50 = 0 ; V_50 < V_49 -> V_61 ; V_50 ++ )
V_67 -> V_62 [ V_50 ] = V_49 -> V_62 [ V_50 ] ;
F_16 ( V_8 , V_49 , F_39 ( V_49 -> V_66 ) ) ;
}
V_46 -> V_32 = V_49 = V_67 ;
}
V_52 = 1 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_61 ; V_50 ++ ) {
V_52 = ! F_10 ( & V_49 -> V_62 [ V_50 ] , V_45 ) ;
if ( V_52 == 0 )
goto V_60;
}
for ( V_51 = V_49 -> V_61 - 1 ; V_51 >= V_50 ; V_51 -- )
V_49 -> V_62 [ V_51 + 1 ] = V_49 -> V_62 [ V_51 ] ;
V_49 -> V_62 [ V_50 ] = * V_45 ;
V_49 -> V_61 ++ ;
V_19 = 0 ;
F_36 ( V_2 , V_38 , V_42 , 1 , V_45 , 1 ) ;
V_60:
if ( V_54 )
F_40 ( & V_46 -> V_31 ) ;
F_30 ( & V_2 -> V_39 ) ;
F_11 () ;
if ( V_53 )
V_19 = F_20 ( V_8 , V_44 -> V_59 , V_38 ) ;
return V_19 ;
}
int F_41 ( struct V_7 * V_8 , struct V_71 * V_72 )
{
const struct V_10 * V_38 ;
struct V_14 * V_46 ;
struct V_1 * V_2 ;
struct V_16 * V_47 = F_4 ( V_8 ) ;
struct V_48 * V_67 , * V_49 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
int V_53 = 0 ;
int V_50 , V_19 ;
V_38 = & ( (struct V_55 * ) & V_72 -> V_73 ) -> V_57 ;
if ( ! F_7 ( V_38 ) )
return - V_20 ;
if ( V_72 -> V_74 != V_63 &&
V_72 -> V_74 != V_30 )
return - V_20 ;
F_8 () ;
V_2 = F_27 ( V_18 , V_38 , V_72 -> V_75 ) ;
if ( ! V_2 ) {
F_11 () ;
return - V_28 ;
}
V_19 = 0 ;
if ( V_72 -> V_74 == V_63 && V_72 -> V_76 == 0 ) {
V_53 = 1 ;
goto V_60;
}
F_9 (inet6, pmc) {
if ( V_46 -> V_9 != V_72 -> V_75 )
continue;
if ( F_10 ( & V_46 -> V_11 , V_38 ) )
break;
}
if ( ! V_46 ) {
V_19 = - V_20 ;
goto V_60;
}
if ( V_72 -> V_76 ) {
V_67 = F_12 ( V_8 , F_39 ( V_72 -> V_76 ) ,
V_70 ) ;
if ( ! V_67 ) {
V_19 = - V_65 ;
goto V_60;
}
V_67 -> V_66 = V_67 -> V_61 = V_72 -> V_76 ;
for ( V_50 = 0 ; V_50 < V_67 -> V_61 ; ++ V_50 ) {
struct V_55 * V_77 ;
V_77 = (struct V_55 * ) & V_72 -> V_78 [ V_50 ] ;
V_67 -> V_62 [ V_50 ] = V_77 -> V_57 ;
}
V_19 = F_36 ( V_2 , V_38 , V_72 -> V_74 ,
V_67 -> V_61 , V_67 -> V_62 , 0 ) ;
if ( V_19 ) {
F_16 ( V_8 , V_67 , F_39 ( V_67 -> V_66 ) ) ;
goto V_60;
}
} else {
V_67 = NULL ;
( void ) F_36 ( V_2 , V_38 , V_72 -> V_74 , 0 , NULL , 0 ) ;
}
F_38 ( & V_46 -> V_31 ) ;
V_49 = V_46 -> V_32 ;
if ( V_49 ) {
( void ) F_37 ( V_2 , V_38 , V_46 -> V_29 ,
V_49 -> V_61 , V_49 -> V_62 , 0 ) ;
F_16 ( V_8 , V_49 , F_39 ( V_49 -> V_66 ) ) ;
} else
( void ) F_37 ( V_2 , V_38 , V_46 -> V_29 , 0 , NULL , 0 ) ;
V_46 -> V_32 = V_67 ;
V_46 -> V_29 = V_72 -> V_74 ;
F_40 ( & V_46 -> V_31 ) ;
V_19 = 0 ;
V_60:
F_30 ( & V_2 -> V_39 ) ;
F_11 () ;
if ( V_53 )
V_19 = F_20 ( V_8 , V_72 -> V_75 , V_38 ) ;
return V_19 ;
}
int F_42 ( struct V_7 * V_8 , struct V_71 * V_72 ,
struct V_71 T_2 * V_79 , int T_2 * V_80 )
{
int V_19 , V_50 , V_68 , V_81 ;
const struct V_10 * V_38 ;
struct V_14 * V_46 ;
struct V_1 * V_2 ;
struct V_16 * V_47 = F_4 ( V_8 ) ;
struct V_48 * V_49 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
V_38 = & ( (struct V_55 * ) & V_72 -> V_73 ) -> V_57 ;
if ( ! F_7 ( V_38 ) )
return - V_20 ;
F_8 () ;
V_2 = F_27 ( V_18 , V_38 , V_72 -> V_75 ) ;
if ( ! V_2 ) {
F_11 () ;
return - V_28 ;
}
V_19 = - V_37 ;
F_9 (inet6, pmc) {
if ( V_46 -> V_9 != V_72 -> V_75 )
continue;
if ( F_10 ( V_38 , & V_46 -> V_11 ) )
break;
}
if ( ! V_46 )
goto V_60;
V_72 -> V_74 = V_46 -> V_29 ;
V_49 = V_46 -> V_32 ;
V_68 = V_49 ? V_49 -> V_61 : 0 ;
F_30 ( & V_2 -> V_39 ) ;
F_11 () ;
V_81 = V_68 < V_72 -> V_76 ? V_68 : V_72 -> V_76 ;
V_72 -> V_76 = V_68 ;
if ( F_43 ( F_44 ( V_81 ) , V_80 ) ||
F_45 ( V_79 , V_72 , F_44 ( 0 ) ) ) {
return - V_82 ;
}
for ( V_50 = 0 ; V_50 < V_81 ; V_50 ++ ) {
struct V_55 * V_77 ;
struct V_83 V_84 ;
V_77 = (struct V_55 * ) & V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_77 -> V_85 = V_86 ;
V_77 -> V_57 = V_49 -> V_62 [ V_50 ] ;
if ( F_45 ( & V_79 -> V_78 [ V_50 ] , & V_84 , sizeof( V_84 ) ) )
return - V_82 ;
}
return 0 ;
V_60:
F_30 ( & V_2 -> V_39 ) ;
F_11 () ;
return V_19 ;
}
bool F_46 ( struct V_7 * V_8 , const struct V_10 * V_87 ,
const struct V_10 * V_88 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_14 * V_89 ;
struct V_48 * V_49 ;
bool V_52 = true ;
F_8 () ;
F_9 (np, mc) {
if ( F_10 ( & V_89 -> V_11 , V_87 ) )
break;
}
if ( ! V_89 ) {
F_11 () ;
return true ;
}
F_47 ( & V_89 -> V_31 ) ;
V_49 = V_89 -> V_32 ;
if ( ! V_49 ) {
V_52 = V_89 -> V_29 == V_30 ;
} else {
int V_50 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_61 ; V_50 ++ ) {
if ( F_10 ( & V_49 -> V_62 [ V_50 ] , V_88 ) )
break;
}
if ( V_89 -> V_29 == V_63 && V_50 >= V_49 -> V_61 )
V_52 = false ;
if ( V_89 -> V_29 == V_30 && V_50 < V_49 -> V_61 )
V_52 = false ;
}
F_48 ( & V_89 -> V_31 ) ;
F_11 () ;
return V_52 ;
}
static void F_49 ( struct V_90 * V_89 )
{
struct V_12 * V_13 = V_89 -> V_2 -> V_13 ;
char V_91 [ V_92 ] ;
if ( F_50 ( & V_89 -> V_93 ) <
V_94 )
return;
F_51 ( & V_89 -> V_95 ) ;
if ( ! ( V_89 -> V_96 & V_97 ) ) {
V_89 -> V_96 |= V_97 ;
if ( F_52 ( & V_89 -> V_93 , V_91 , V_13 , 0 ) == 0 )
F_53 ( V_13 , V_91 ) ;
}
F_54 ( & V_89 -> V_95 ) ;
if ( ! ( V_13 -> V_98 & V_99 ) || ( V_89 -> V_96 & V_100 ) )
return;
if ( F_2 ( V_89 -> V_2 ) ) {
F_55 ( V_89 ) ;
return;
}
V_89 -> V_101 = V_89 -> V_2 -> V_102 ;
F_56 ( V_89 -> V_2 ) ;
}
static void F_57 ( struct V_90 * V_89 )
{
struct V_12 * V_13 = V_89 -> V_2 -> V_13 ;
char V_91 [ V_92 ] ;
if ( F_50 ( & V_89 -> V_93 ) <
V_94 )
return;
F_51 ( & V_89 -> V_95 ) ;
if ( V_89 -> V_96 & V_97 ) {
V_89 -> V_96 &= ~ V_97 ;
if ( F_52 ( & V_89 -> V_93 , V_91 , V_13 , 0 ) == 0 )
F_58 ( V_13 , V_91 ) ;
}
if ( V_89 -> V_96 & V_100 )
goto V_60;
F_54 ( & V_89 -> V_95 ) ;
if ( ! V_89 -> V_2 -> V_40 )
F_59 ( V_89 ) ;
F_51 ( & V_89 -> V_95 ) ;
if ( F_60 ( & V_89 -> V_103 ) )
F_61 ( & V_89 -> V_104 ) ;
V_60:
F_62 ( V_89 ) ;
F_54 ( & V_89 -> V_95 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_90 * V_105 )
{
struct V_90 * V_46 ;
V_46 = F_64 ( sizeof( * V_46 ) , V_70 ) ;
if ( ! V_46 )
return;
F_51 ( & V_105 -> V_95 ) ;
F_65 ( & V_46 -> V_95 ) ;
V_46 -> V_2 = V_105 -> V_2 ;
F_66 ( V_2 ) ;
V_46 -> V_93 = V_105 -> V_93 ;
V_46 -> V_101 = V_2 -> V_102 ;
V_46 -> V_106 = V_105 -> V_106 ;
if ( V_46 -> V_106 == V_63 ) {
struct V_107 * V_108 ;
V_46 -> V_109 = V_105 -> V_109 ;
V_46 -> V_110 = V_105 -> V_110 ;
V_105 -> V_109 = V_105 -> V_110 = NULL ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 )
V_108 -> V_112 = V_46 -> V_101 ;
}
F_54 ( & V_105 -> V_95 ) ;
F_51 ( & V_2 -> V_113 ) ;
V_46 -> V_24 = V_2 -> V_114 ;
V_2 -> V_114 = V_46 ;
F_54 ( & V_2 -> V_113 ) ;
}
static void F_67 ( struct V_1 * V_2 , const struct V_10 * V_115 )
{
struct V_90 * V_46 , * V_116 ;
struct V_107 * V_108 , * V_117 ;
F_51 ( & V_2 -> V_113 ) ;
V_116 = NULL ;
for ( V_46 = V_2 -> V_114 ; V_46 ; V_46 = V_46 -> V_24 ) {
if ( F_10 ( & V_46 -> V_93 , V_115 ) )
break;
V_116 = V_46 ;
}
if ( V_46 ) {
if ( V_116 )
V_116 -> V_24 = V_46 -> V_24 ;
else
V_2 -> V_114 = V_46 -> V_24 ;
}
F_54 ( & V_2 -> V_113 ) ;
if ( V_46 ) {
for ( V_108 = V_46 -> V_109 ; V_108 ; V_108 = V_117 ) {
V_117 = V_108 -> V_111 ;
F_68 ( V_108 ) ;
}
F_69 ( V_46 -> V_2 ) ;
F_68 ( V_46 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_90 * V_46 , * V_118 ;
F_51 ( & V_2 -> V_113 ) ;
V_46 = V_2 -> V_114 ;
V_2 -> V_114 = NULL ;
F_54 ( & V_2 -> V_113 ) ;
for (; V_46 ; V_46 = V_118 ) {
V_118 = V_46 -> V_24 ;
F_62 ( V_46 ) ;
F_69 ( V_46 -> V_2 ) ;
F_68 ( V_46 ) ;
}
F_29 ( & V_2 -> V_39 ) ;
for ( V_46 = V_2 -> V_119 ; V_46 ; V_46 = V_46 -> V_24 ) {
struct V_107 * V_108 , * V_117 ;
F_51 ( & V_46 -> V_95 ) ;
V_108 = V_46 -> V_109 ;
V_46 -> V_109 = NULL ;
F_54 ( & V_46 -> V_95 ) ;
for (; V_108 ; V_108 = V_117 ) {
V_117 = V_108 -> V_111 ;
F_68 ( V_108 ) ;
}
}
F_30 ( & V_2 -> V_39 ) ;
}
static void F_71 ( struct V_90 * V_89 )
{
F_72 ( & V_89 -> V_104 ) ;
}
static void F_73 ( struct V_90 * V_89 )
{
if ( F_74 ( & V_89 -> V_104 ) ) {
F_69 ( V_89 -> V_2 ) ;
F_68 ( V_89 ) ;
}
}
static struct V_90 * F_75 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
struct V_90 * V_89 ;
V_89 = F_64 ( sizeof( * V_89 ) , V_70 ) ;
if ( ! V_89 )
return NULL ;
F_76 ( & V_89 -> V_103 , V_120 , ( unsigned long ) V_89 ) ;
V_89 -> V_93 = * V_11 ;
V_89 -> V_2 = V_2 ;
V_89 -> V_121 = 1 ;
V_89 -> V_122 = V_89 -> V_123 = V_124 ;
F_77 ( & V_89 -> V_104 , 1 ) ;
F_65 ( & V_89 -> V_95 ) ;
V_89 -> V_106 = V_30 ;
V_89 -> V_125 [ V_30 ] = 1 ;
if ( F_78 ( & V_89 -> V_93 ) ||
F_50 ( & V_89 -> V_93 ) < V_94 )
V_89 -> V_96 |= V_100 ;
return V_89 ;
}
int F_18 ( struct V_12 * V_13 , const struct V_10 * V_11 )
{
struct V_90 * V_89 ;
struct V_1 * V_2 ;
F_6 () ;
V_2 = F_79 ( V_13 ) ;
if ( ! V_2 )
return - V_20 ;
F_80 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_40 ) {
F_81 ( & V_2 -> V_39 ) ;
F_69 ( V_2 ) ;
return - V_28 ;
}
for ( V_89 = V_2 -> V_119 ; V_89 ; V_89 = V_89 -> V_24 ) {
if ( F_10 ( & V_89 -> V_93 , V_11 ) ) {
V_89 -> V_121 ++ ;
F_81 ( & V_2 -> V_39 ) ;
F_36 ( V_2 , & V_89 -> V_93 , V_30 , 0 ,
NULL , 0 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
}
V_89 = F_75 ( V_2 , V_11 ) ;
if ( ! V_89 ) {
F_81 ( & V_2 -> V_39 ) ;
F_69 ( V_2 ) ;
return - V_23 ;
}
V_89 -> V_24 = V_2 -> V_119 ;
V_2 -> V_119 = V_89 ;
F_71 ( V_89 ) ;
F_81 ( & V_2 -> V_39 ) ;
F_67 ( V_2 , & V_89 -> V_93 ) ;
F_49 ( V_89 ) ;
F_73 ( V_89 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
struct V_90 * V_126 , * * V_127 ;
F_6 () ;
F_80 ( & V_2 -> V_39 ) ;
for ( V_127 = & V_2 -> V_119 ; ( V_126 = * V_127 ) != NULL ; V_127 = & V_126 -> V_24 ) {
if ( F_10 ( & V_126 -> V_93 , V_11 ) ) {
if ( -- V_126 -> V_121 == 0 ) {
* V_127 = V_126 -> V_24 ;
F_81 ( & V_2 -> V_39 ) ;
F_57 ( V_126 ) ;
F_73 ( V_126 ) ;
return 0 ;
}
F_81 ( & V_2 -> V_39 ) ;
return 0 ;
}
}
F_81 ( & V_2 -> V_39 ) ;
return - V_128 ;
}
int F_82 ( struct V_12 * V_13 , const struct V_10 * V_11 )
{
struct V_1 * V_2 ;
int V_19 ;
F_6 () ;
V_2 = F_22 ( V_13 ) ;
if ( ! V_2 )
V_19 = - V_28 ;
else
V_19 = F_24 ( V_2 , V_11 ) ;
return V_19 ;
}
bool F_83 ( struct V_12 * V_13 , const struct V_10 * V_38 ,
const struct V_10 * V_88 )
{
struct V_1 * V_2 ;
struct V_90 * V_89 ;
bool V_52 = false ;
F_8 () ;
V_2 = F_22 ( V_13 ) ;
if ( V_2 ) {
F_29 ( & V_2 -> V_39 ) ;
for ( V_89 = V_2 -> V_119 ; V_89 ; V_89 = V_89 -> V_24 ) {
if ( F_10 ( & V_89 -> V_93 , V_38 ) )
break;
}
if ( V_89 ) {
if ( V_88 && ! F_84 ( V_88 ) ) {
struct V_107 * V_108 ;
F_51 ( & V_89 -> V_95 ) ;
for ( V_108 = V_89 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( F_10 ( & V_108 -> V_129 , V_88 ) )
break;
}
if ( V_108 )
V_52 = V_108 -> V_130 [ V_63 ] ||
V_108 -> V_130 [ V_30 ] !=
V_89 -> V_125 [ V_30 ] ;
else
V_52 = V_89 -> V_125 [ V_30 ] != 0 ;
F_54 ( & V_89 -> V_95 ) ;
} else
V_52 = true ;
}
F_30 ( & V_2 -> V_39 ) ;
}
F_11 () ;
return V_52 ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned long V_131 = F_86 () % V_2 -> V_132 ;
V_2 -> V_133 = 1 ;
if ( ! F_87 ( & V_2 -> V_134 , V_124 + V_131 + 2 ) )
F_66 ( V_2 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_2 -> V_133 = 0 ;
if ( F_60 ( & V_2 -> V_134 ) )
F_89 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 , unsigned long V_135 )
{
unsigned long V_131 = F_86 () % V_135 ;
if ( ! F_87 ( & V_2 -> V_136 , V_124 + V_131 + 2 ) )
F_66 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
V_2 -> V_137 = 0 ;
if ( F_60 ( & V_2 -> V_136 ) )
F_89 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 , unsigned long V_135 )
{
unsigned long V_131 = F_86 () % V_135 ;
if ( ! F_87 ( & V_2 -> V_138 , V_124 + V_131 + 2 ) )
F_66 ( V_2 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( F_60 ( & V_2 -> V_138 ) )
F_89 ( V_2 ) ;
}
static void F_94 ( struct V_90 * V_126 , unsigned long V_139 )
{
unsigned long V_135 = V_139 ;
if ( F_78 ( & V_126 -> V_93 ) ||
F_50 ( & V_126 -> V_93 ) < V_94 )
return;
if ( F_60 ( & V_126 -> V_103 ) ) {
F_61 ( & V_126 -> V_104 ) ;
V_135 = V_126 -> V_103 . V_140 - V_124 ;
}
if ( V_135 >= V_139 )
V_135 = F_86 () % V_139 ;
V_126 -> V_103 . V_140 = V_124 + V_135 ;
if ( ! F_87 ( & V_126 -> V_103 , V_124 + V_135 ) )
F_72 ( & V_126 -> V_104 ) ;
V_126 -> V_96 |= V_141 ;
}
static bool F_95 ( struct V_90 * V_46 , int V_142 ,
const struct V_10 * V_143 )
{
struct V_107 * V_108 ;
int V_50 , V_144 ;
V_144 = 0 ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( V_144 == V_142 )
break;
for ( V_50 = 0 ; V_50 < V_142 ; V_50 ++ ) {
if ( V_108 -> V_130 [ V_63 ] ||
V_46 -> V_125 [ V_30 ] !=
V_108 -> V_130 [ V_30 ] )
break;
if ( F_10 ( & V_143 [ V_50 ] , & V_108 -> V_129 ) ) {
V_144 ++ ;
break;
}
}
}
V_46 -> V_96 &= ~ V_145 ;
if ( V_144 == V_142 )
return false ;
return true ;
}
static bool F_96 ( struct V_90 * V_46 , int V_142 ,
const struct V_10 * V_143 )
{
struct V_107 * V_108 ;
int V_50 , V_144 ;
if ( V_46 -> V_106 == V_30 )
return F_95 ( V_46 , V_142 , V_143 ) ;
V_144 = 0 ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( V_144 == V_142 )
break;
for ( V_50 = 0 ; V_50 < V_142 ; V_50 ++ ) {
if ( F_10 ( & V_143 [ V_50 ] , & V_108 -> V_129 ) ) {
V_108 -> V_146 = 1 ;
V_144 ++ ;
break;
}
}
}
if ( ! V_144 ) {
V_46 -> V_96 &= ~ V_145 ;
return false ;
}
V_46 -> V_96 |= V_145 ;
return true ;
}
static int F_97 ( const struct V_1 * V_2 )
{
if ( F_98 ( V_2 -> V_13 ) -> V_147 . V_148 -> V_149 != 0 )
return F_98 ( V_2 -> V_13 ) -> V_147 . V_148 -> V_149 ;
else
return V_2 -> V_4 . V_149 ;
}
static bool F_99 ( const struct V_1 * V_2 )
{
return F_97 ( V_2 ) == 2 ;
}
static bool F_100 ( const struct V_1 * V_2 )
{
return F_97 ( V_2 ) == 1 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
if ( F_99 ( V_2 ) )
return false ;
if ( F_100 ( V_2 ) )
return true ;
if ( V_2 -> V_150 && F_101 ( V_124 , V_2 -> V_150 ) )
return true ;
return false ;
}
static void F_102 ( struct V_1 * V_2 )
{
unsigned long V_151 ;
V_151 = ( V_2 -> V_102 * V_2 -> V_152 ) + V_2 -> V_153 ;
V_2 -> V_150 = V_124 + V_151 ;
}
static void F_103 ( struct V_1 * V_2 ,
const struct V_154 * V_155 )
{
const int V_156 = F_104 ( V_157 , V_158 ) ;
F_105 ( V_2 -> V_102 == 0 ) ;
if ( V_155 -> V_159 > 0 )
V_2 -> V_102 = V_155 -> V_159 ;
if ( F_106 ( V_2 -> V_102 < V_156 ) ) {
F_107 ( L_1 ,
V_2 -> V_102 , V_156 ) ;
V_2 -> V_102 = V_156 ;
}
}
static void F_108 ( struct V_1 * V_2 ,
const struct V_154 * V_155 )
{
unsigned long V_160 ;
if ( V_155 -> V_161 < 128 ) {
V_160 = V_155 -> V_161 ;
} else {
unsigned long V_162 , V_163 ;
V_163 = F_109 ( V_155 -> V_161 ) ;
V_162 = F_110 ( V_155 -> V_161 ) ;
V_160 = ( V_162 | 0x10 ) << ( V_163 + 3 ) ;
}
V_2 -> V_152 = V_160 * V_164 ;
}
static void F_111 ( struct V_1 * V_2 ,
const struct V_154 * V_155 )
{
V_2 -> V_153 = F_112 ( F_113 ( V_155 ) ) ;
}
static int F_114 ( struct V_1 * V_2 , struct V_165 * V_166 ,
unsigned long * V_167 , bool V_168 )
{
unsigned long V_169 ;
if ( F_99 ( V_2 ) )
return - V_20 ;
V_169 = F_115 ( V_166 -> V_170 ) ;
if ( ! V_168 )
V_169 = F_104 ( V_169 , V_171 ) ;
* V_167 = F_116 ( F_112 ( V_169 ) , 1UL ) ;
if ( V_168 )
F_102 ( V_2 ) ;
F_88 ( V_2 ) ;
F_91 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , struct V_154 * V_166 ,
unsigned long * V_167 )
{
* V_167 = F_116 ( F_112 ( F_113 ( V_166 ) ) , 1UL ) ;
F_103 ( V_2 , V_166 ) ;
F_108 ( V_2 , V_166 ) ;
F_111 ( V_2 , V_166 ) ;
V_2 -> V_132 = * V_167 ;
return 0 ;
}
int F_118 ( struct V_172 * V_173 )
{
struct V_154 * V_155 = NULL ;
struct V_90 * V_126 ;
const struct V_10 * V_38 ;
unsigned long V_167 ;
struct V_1 * V_2 ;
struct V_165 * V_166 ;
int V_174 ;
int V_175 = 0 ;
int V_176 , V_19 ;
if ( ! F_119 ( V_173 , sizeof( struct V_10 ) ) )
return - V_20 ;
V_176 = F_115 ( F_120 ( V_173 ) -> V_177 ) + sizeof( struct V_178 ) ;
V_176 -= F_121 ( V_173 ) ;
if ( ! ( F_122 ( & F_120 ( V_173 ) -> V_179 ) & V_180 ) ||
F_120 ( V_173 ) -> V_181 != 1 ||
! ( F_123 ( V_173 ) -> V_98 & V_182 ) ||
F_123 ( V_173 ) -> V_183 != F_124 ( V_184 ) )
return - V_20 ;
V_2 = F_22 ( V_173 -> V_13 ) ;
if ( ! V_2 )
return 0 ;
V_166 = (struct V_165 * ) F_125 ( V_173 ) ;
V_38 = & V_166 -> V_185 ;
V_174 = F_122 ( V_38 ) ;
if ( V_174 != V_186 &&
! ( V_174 & V_187 ) )
return - V_20 ;
if ( V_176 < V_188 ) {
return - V_20 ;
} else if ( V_176 == V_188 || F_2 ( V_2 ) ) {
V_19 = F_114 ( V_2 , V_166 , & V_167 ,
V_176 == V_188 ) ;
if ( V_19 < 0 )
return V_19 ;
} else if ( V_176 >= V_189 ) {
int V_190 = sizeof( struct V_154 ) -
sizeof( struct V_191 ) ;
if ( ! F_119 ( V_173 , V_190 ) )
return - V_20 ;
V_155 = (struct V_154 * ) F_126 ( V_173 ) ;
V_19 = F_117 ( V_2 , V_155 , & V_167 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_174 == V_186 ) {
if ( V_155 -> V_192 )
return - V_20 ;
F_85 ( V_2 ) ;
return 0 ;
}
if ( V_155 -> V_192 != 0 ) {
if ( ! F_119 ( V_173 , V_190 +
F_115 ( V_155 -> V_192 ) * sizeof( struct V_10 ) ) )
return - V_20 ;
V_155 = (struct V_154 * ) F_126 ( V_173 ) ;
V_175 = 1 ;
}
} else {
return - V_20 ;
}
F_29 ( & V_2 -> V_39 ) ;
if ( V_174 == V_186 ) {
for ( V_126 = V_2 -> V_119 ; V_126 ; V_126 = V_126 -> V_24 ) {
F_51 ( & V_126 -> V_95 ) ;
F_94 ( V_126 , V_167 ) ;
F_54 ( & V_126 -> V_95 ) ;
}
} else {
for ( V_126 = V_2 -> V_119 ; V_126 ; V_126 = V_126 -> V_24 ) {
if ( ! F_10 ( V_38 , & V_126 -> V_93 ) )
continue;
F_51 ( & V_126 -> V_95 ) ;
if ( V_126 -> V_96 & V_141 ) {
if ( ! V_175 )
V_126 -> V_96 &= ~ V_145 ;
} else {
if ( V_175 )
V_126 -> V_96 |= V_145 ;
else
V_126 -> V_96 &= ~ V_145 ;
}
if ( ! ( V_126 -> V_96 & V_145 ) ||
F_96 ( V_126 , F_115 ( V_155 -> V_192 ) , V_155 -> V_193 ) )
F_94 ( V_126 , V_167 ) ;
F_54 ( & V_126 -> V_95 ) ;
break;
}
}
F_30 ( & V_2 -> V_39 ) ;
return 0 ;
}
int F_127 ( struct V_172 * V_173 )
{
struct V_90 * V_126 ;
struct V_1 * V_2 ;
struct V_165 * V_166 ;
int V_194 ;
if ( V_173 -> V_195 == V_196 )
return 0 ;
if ( V_173 -> V_195 != V_197 &&
V_173 -> V_195 != V_198 )
return 0 ;
if ( ! F_119 ( V_173 , sizeof( * V_166 ) - sizeof( struct V_191 ) ) )
return - V_20 ;
V_166 = (struct V_165 * ) F_125 ( V_173 ) ;
V_194 = F_122 ( & F_120 ( V_173 ) -> V_179 ) ;
if ( V_194 != V_186 &&
! ( V_194 & V_180 ) )
return - V_20 ;
V_2 = F_22 ( V_173 -> V_13 ) ;
if ( ! V_2 )
return - V_28 ;
F_29 ( & V_2 -> V_39 ) ;
for ( V_126 = V_2 -> V_119 ; V_126 ; V_126 = V_126 -> V_24 ) {
if ( F_10 ( & V_126 -> V_93 , & V_166 -> V_185 ) ) {
F_128 ( & V_126 -> V_95 ) ;
if ( F_60 ( & V_126 -> V_103 ) )
F_61 ( & V_126 -> V_104 ) ;
V_126 -> V_96 &= ~ ( V_199 | V_141 ) ;
F_129 ( & V_126 -> V_95 ) ;
break;
}
}
F_30 ( & V_2 -> V_39 ) ;
return 0 ;
}
static bool F_130 ( struct V_90 * V_46 , struct V_107 * V_108 , int type ,
int V_200 , int V_201 )
{
switch ( type ) {
case V_202 :
case V_203 :
if ( V_200 || V_201 )
return false ;
if ( ! ( ( V_46 -> V_96 & V_145 ) && ! V_108 -> V_146 ) ) {
if ( V_46 -> V_106 == V_63 )
return true ;
if ( V_108 -> V_130 [ V_63 ] )
return type == V_202 ;
return V_46 -> V_125 [ V_30 ] ==
V_108 -> V_130 [ V_30 ] ;
}
return false ;
case V_204 :
if ( V_200 || V_201 )
return false ;
return V_108 -> V_130 [ V_63 ] != 0 ;
case V_205 :
if ( V_200 || V_201 )
return false ;
if ( V_46 -> V_125 [ V_30 ] == 0 ||
V_108 -> V_130 [ V_63 ] )
return false ;
return V_46 -> V_125 [ V_30 ] ==
V_108 -> V_130 [ V_30 ] ;
case V_206 :
if ( V_200 || ! V_108 -> V_112 )
return false ;
return ( V_46 -> V_106 == V_63 ) ^ V_201 ;
case V_207 :
if ( V_46 -> V_106 == V_63 )
return V_200 || ( V_108 -> V_112 && V_201 ) ;
return V_108 -> V_112 && ! V_200 && ! V_201 ;
}
return false ;
}
static int
F_131 ( struct V_90 * V_46 , int type , int V_200 , int V_201 )
{
struct V_107 * V_108 ;
int V_144 = 0 ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( ! F_130 ( V_46 , V_108 , type , V_200 , V_201 ) )
continue;
V_144 ++ ;
}
return V_144 ;
}
static void F_132 ( struct V_7 * V_8 , struct V_172 * V_173 ,
struct V_12 * V_13 ,
const struct V_10 * V_179 ,
const struct V_10 * V_208 ,
int V_209 , int V_176 )
{
struct V_178 * V_210 ;
V_173 -> V_211 = F_124 ( V_212 ) ;
V_173 -> V_13 = V_13 ;
F_133 ( V_173 ) ;
F_134 ( V_173 , sizeof( struct V_178 ) ) ;
V_210 = F_120 ( V_173 ) ;
F_135 ( V_210 , 0 , 0 ) ;
V_210 -> V_177 = F_124 ( V_176 ) ;
V_210 -> V_213 = V_209 ;
V_210 -> V_181 = F_4 ( V_8 ) -> V_181 ;
V_210 -> V_179 = * V_179 ;
V_210 -> V_208 = * V_208 ;
}
static struct V_172 * F_136 ( struct V_1 * V_2 , unsigned int V_214 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_18 * V_18 = F_98 ( V_13 ) ;
struct V_7 * V_8 = V_18 -> V_147 . V_215 ;
struct V_172 * V_173 ;
struct V_216 * V_217 ;
struct V_10 V_218 ;
const struct V_10 * V_179 ;
int V_219 = F_137 ( V_13 ) ;
int V_220 = V_13 -> V_221 ;
unsigned int V_222 = V_214 + V_219 + V_220 ;
int V_19 ;
T_3 V_183 [ 8 ] = { V_223 , 0 ,
V_224 , 2 , 0 , 0 ,
V_225 , 0 } ;
V_222 = F_138 ( int , V_222 , F_139 ( 0 , 0 ) ) ;
V_173 = F_140 ( V_8 , V_222 , 1 , & V_19 ) ;
if ( ! V_173 )
return NULL ;
V_173 -> V_226 = V_227 ;
V_173 -> V_228 = F_141 ( V_173 ) -
F_104 ( V_214 , F_141 ( V_173 ) ) ;
F_142 ( V_173 , V_219 ) ;
if ( F_143 ( V_2 , & V_218 , V_229 ) ) {
V_179 = & V_230 ;
} else
V_179 = & V_218 ;
F_132 ( V_8 , V_173 , V_13 , V_179 , & V_231 , V_232 , 0 ) ;
memcpy ( F_134 ( V_173 , sizeof( V_183 ) ) , V_183 , sizeof( V_183 ) ) ;
F_144 ( V_173 , F_145 ( V_173 ) - V_173 -> V_233 ) ;
F_134 ( V_173 , sizeof( * V_217 ) ) ;
V_217 = (struct V_216 * ) F_126 ( V_173 ) ;
V_217 -> V_234 = V_235 ;
V_217 -> V_236 = 0 ;
V_217 -> V_237 = 0 ;
V_217 -> V_238 = 0 ;
V_217 -> V_239 = 0 ;
return V_173 ;
}
static void F_146 ( struct V_172 * V_173 )
{
struct V_178 * V_240 = F_120 ( V_173 ) ;
struct V_216 * V_217 =
(struct V_216 * ) F_126 ( V_173 ) ;
int V_177 , V_241 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = F_98 ( V_173 -> V_13 ) ;
int V_19 ;
struct V_242 V_243 ;
struct V_244 * V_27 ;
F_8 () ;
V_2 = F_22 ( V_173 -> V_13 ) ;
F_147 ( V_18 , V_2 , V_245 , V_173 -> V_176 ) ;
V_177 = ( F_145 ( V_173 ) - F_148 ( V_173 ) ) -
sizeof( * V_240 ) ;
V_241 = F_145 ( V_173 ) - F_126 ( V_173 ) ;
V_240 -> V_177 = F_124 ( V_177 ) ;
V_217 -> V_237 = F_149 ( & V_240 -> V_179 , & V_240 -> V_208 , V_241 ,
V_223 ,
F_150 ( F_126 ( V_173 ) ,
V_241 , 0 ) ) ;
F_151 ( V_18 -> V_147 . V_215 , & V_243 , V_235 ,
& F_120 ( V_173 ) -> V_179 , & F_120 ( V_173 ) -> V_208 ,
V_173 -> V_13 -> V_9 ) ;
V_27 = F_152 ( V_173 -> V_13 , & V_243 ) ;
V_19 = 0 ;
if ( F_153 ( V_27 ) ) {
V_19 = F_154 ( V_27 ) ;
V_27 = NULL ;
}
F_155 ( V_173 , V_27 ) ;
if ( V_19 )
goto V_246;
V_177 = V_173 -> V_176 ;
V_19 = F_156 ( V_247 , V_248 ,
V_18 , V_18 -> V_147 . V_215 , V_173 , NULL , V_173 -> V_13 ,
V_249 ) ;
V_250:
if ( ! V_19 ) {
F_157 ( V_18 , V_2 , V_235 ) ;
F_158 ( V_18 , V_2 , V_251 ) ;
} else {
F_159 ( V_18 , V_2 , V_252 ) ;
}
F_11 () ;
return;
V_246:
F_160 ( V_173 ) ;
goto V_250;
}
static int F_161 ( struct V_90 * V_46 , int type , int V_253 , int V_254 )
{
return sizeof( struct V_255 ) + 16 * F_131 ( V_46 , type , V_253 , V_254 ) ;
}
static struct V_172 * F_162 ( struct V_172 * V_173 , struct V_90 * V_46 ,
int type , struct V_255 * * V_256 )
{
struct V_12 * V_13 = V_46 -> V_2 -> V_13 ;
struct V_216 * V_217 ;
struct V_255 * V_257 ;
if ( ! V_173 )
V_173 = F_136 ( V_46 -> V_2 , V_13 -> V_214 ) ;
if ( ! V_173 )
return NULL ;
V_257 = (struct V_255 * ) F_134 ( V_173 , sizeof( struct V_255 ) ) ;
V_257 -> V_258 = type ;
V_257 -> V_259 = 0 ;
V_257 -> V_260 = 0 ;
V_257 -> V_261 = V_46 -> V_93 ;
V_217 = (struct V_216 * ) F_126 ( V_173 ) ;
V_217 -> V_239 = F_124 ( F_115 ( V_217 -> V_239 ) + 1 ) ;
* V_256 = V_257 ;
return V_173 ;
}
static struct V_172 * F_163 ( struct V_172 * V_173 , struct V_90 * V_46 ,
int type , int V_200 , int V_201 , int V_262 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_216 * V_217 ;
struct V_255 * V_257 = NULL ;
struct V_107 * V_108 , * V_117 , * V_263 , * * V_264 ;
int V_144 , V_265 , V_266 , V_267 , V_268 ;
if ( V_46 -> V_96 & V_100 )
return V_173 ;
V_267 = type == V_202 ||
type == V_203 ;
V_268 = type == V_203 ||
type == V_205 ;
V_265 = V_144 = 0 ;
V_264 = V_201 ? & V_46 -> V_109 : & V_46 -> V_110 ;
if ( ! * V_264 )
goto V_269;
V_217 = V_173 ? (struct V_216 * ) F_126 ( V_173 ) : NULL ;
if ( V_268 ) {
if ( V_217 && V_217 -> V_239 &&
F_164 ( V_173 ) < F_161 ( V_46 , type , V_200 , V_201 ) ) {
if ( V_173 )
F_146 ( V_173 ) ;
V_173 = F_136 ( V_2 , V_13 -> V_214 ) ;
}
}
V_266 = 1 ;
V_263 = NULL ;
for ( V_108 = * V_264 ; V_108 ; V_108 = V_117 ) {
struct V_10 * V_270 ;
V_117 = V_108 -> V_111 ;
if ( ! F_130 ( V_46 , V_108 , type , V_200 , V_201 ) ) {
V_263 = V_108 ;
continue;
}
if ( V_267 )
V_108 -> V_146 = 0 ;
if ( F_164 ( V_173 ) < sizeof( * V_270 ) +
V_266 * sizeof( struct V_255 ) ) {
if ( V_268 && ! V_266 )
break;
if ( V_257 )
V_257 -> V_260 = F_124 ( V_144 ) ;
if ( V_173 )
F_146 ( V_173 ) ;
V_173 = F_136 ( V_2 , V_13 -> V_214 ) ;
V_266 = 1 ;
V_144 = 0 ;
}
if ( V_266 ) {
V_173 = F_162 ( V_173 , V_46 , type , & V_257 ) ;
V_266 = 0 ;
}
if ( ! V_173 )
return NULL ;
V_270 = (struct V_10 * ) F_134 ( V_173 , sizeof( * V_270 ) ) ;
* V_270 = V_108 -> V_129 ;
V_144 ++ ; V_265 ++ ;
if ( ( type == V_206 ||
type == V_207 ) && V_108 -> V_112 ) {
V_108 -> V_112 -- ;
if ( ( V_201 || V_200 ) && V_108 -> V_112 == 0 ) {
if ( V_263 )
V_263 -> V_111 = V_108 -> V_111 ;
else
* V_264 = V_108 -> V_111 ;
F_68 ( V_108 ) ;
continue;
}
}
V_263 = V_108 ;
}
V_269:
if ( ! V_265 ) {
if ( type == V_206 ||
type == V_207 )
return V_173 ;
if ( V_46 -> V_101 || V_267 || V_262 ) {
if ( V_173 && F_164 ( V_173 ) < sizeof( struct V_255 ) ) {
F_146 ( V_173 ) ;
V_173 = NULL ;
}
V_173 = F_162 ( V_173 , V_46 , type , & V_257 ) ;
}
}
if ( V_257 )
V_257 -> V_260 = F_124 ( V_144 ) ;
if ( V_267 )
V_46 -> V_96 &= ~ V_145 ;
return V_173 ;
}
static void F_165 ( struct V_1 * V_2 , struct V_90 * V_46 )
{
struct V_172 * V_173 = NULL ;
int type ;
F_29 ( & V_2 -> V_39 ) ;
if ( ! V_46 ) {
for ( V_46 = V_2 -> V_119 ; V_46 ; V_46 = V_46 -> V_24 ) {
if ( V_46 -> V_96 & V_100 )
continue;
F_51 ( & V_46 -> V_95 ) ;
if ( V_46 -> V_125 [ V_30 ] )
type = V_203 ;
else
type = V_202 ;
V_173 = F_163 ( V_173 , V_46 , type , 0 , 0 , 0 ) ;
F_54 ( & V_46 -> V_95 ) ;
}
} else {
F_51 ( & V_46 -> V_95 ) ;
if ( V_46 -> V_125 [ V_30 ] )
type = V_203 ;
else
type = V_202 ;
V_173 = F_163 ( V_173 , V_46 , type , 0 , 0 , 0 ) ;
F_54 ( & V_46 -> V_95 ) ;
}
F_30 ( & V_2 -> V_39 ) ;
if ( V_173 )
F_146 ( V_173 ) ;
}
static void F_166 ( struct V_107 * * V_271 )
{
struct V_107 * V_263 , * V_117 , * V_108 ;
V_263 = NULL ;
for ( V_108 = * V_271 ; V_108 ; V_108 = V_117 ) {
V_117 = V_108 -> V_111 ;
if ( V_108 -> V_112 == 0 ) {
if ( V_263 )
V_263 -> V_111 = V_108 -> V_111 ;
else
* V_271 = V_108 -> V_111 ;
F_68 ( V_108 ) ;
} else
V_263 = V_108 ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_90 * V_46 , * V_116 , * V_272 ;
struct V_172 * V_173 = NULL ;
int type , V_273 ;
F_29 ( & V_2 -> V_39 ) ;
F_128 ( & V_2 -> V_113 ) ;
V_116 = NULL ;
for ( V_46 = V_2 -> V_114 ; V_46 ; V_46 = V_272 ) {
V_272 = V_46 -> V_24 ;
if ( V_46 -> V_106 == V_63 ) {
type = V_207 ;
V_273 = V_207 ;
V_173 = F_163 ( V_173 , V_46 , type , 1 , 0 , 0 ) ;
V_173 = F_163 ( V_173 , V_46 , V_273 , 1 , 1 , 0 ) ;
}
if ( V_46 -> V_101 ) {
if ( V_46 -> V_106 == V_30 ) {
type = V_204 ;
V_173 = F_163 ( V_173 , V_46 , type , 1 , 0 , 0 ) ;
}
V_46 -> V_101 -- ;
if ( V_46 -> V_101 == 0 ) {
F_166 ( & V_46 -> V_109 ) ;
F_166 ( & V_46 -> V_110 ) ;
}
}
if ( V_46 -> V_101 == 0 && ! V_46 -> V_109 &&
! V_46 -> V_110 ) {
if ( V_116 )
V_116 -> V_24 = V_272 ;
else
V_2 -> V_114 = V_272 ;
F_69 ( V_46 -> V_2 ) ;
F_68 ( V_46 ) ;
} else
V_116 = V_46 ;
}
F_129 ( & V_2 -> V_113 ) ;
for ( V_46 = V_2 -> V_119 ; V_46 ; V_46 = V_46 -> V_24 ) {
F_51 ( & V_46 -> V_95 ) ;
if ( V_46 -> V_125 [ V_30 ] ) {
type = V_207 ;
V_273 = V_206 ;
} else {
type = V_206 ;
V_273 = V_207 ;
}
V_173 = F_163 ( V_173 , V_46 , type , 0 , 0 , 0 ) ;
V_173 = F_163 ( V_173 , V_46 , V_273 , 0 , 1 , 0 ) ;
if ( V_46 -> V_101 ) {
if ( V_46 -> V_106 == V_30 )
type = V_205 ;
else
type = V_204 ;
V_173 = F_163 ( V_173 , V_46 , type , 0 , 0 , 0 ) ;
V_46 -> V_101 -- ;
}
F_54 ( & V_46 -> V_95 ) ;
}
F_30 ( & V_2 -> V_39 ) ;
if ( ! V_173 )
return;
( void ) F_146 ( V_173 ) ;
}
static void F_168 ( struct V_10 * V_11 , struct V_12 * V_13 , int type )
{
struct V_18 * V_18 = F_98 ( V_13 ) ;
struct V_7 * V_8 = V_18 -> V_147 . V_215 ;
struct V_1 * V_2 ;
struct V_172 * V_173 ;
struct V_165 * V_210 ;
const struct V_10 * V_274 , * V_179 ;
struct V_10 V_218 ;
int V_219 = F_137 ( V_13 ) ;
int V_220 = V_13 -> V_221 ;
int V_19 , V_176 , V_177 , V_275 ;
T_3 V_183 [ 8 ] = { V_223 , 0 ,
V_224 , 2 , 0 , 0 ,
V_225 , 0 } ;
struct V_242 V_243 ;
struct V_244 * V_27 ;
if ( type == V_276 )
V_274 = & V_277 ;
else
V_274 = V_11 ;
V_176 = sizeof( struct V_191 ) + sizeof( struct V_10 ) ;
V_177 = V_176 + sizeof( V_183 ) ;
V_275 = sizeof( struct V_178 ) + V_177 ;
F_8 () ;
F_147 ( V_18 , F_22 ( V_13 ) ,
V_245 , V_275 ) ;
F_11 () ;
V_173 = F_140 ( V_8 , V_219 + V_220 + V_275 , 1 , & V_19 ) ;
if ( ! V_173 ) {
F_8 () ;
F_159 ( V_18 , F_22 ( V_13 ) ,
V_252 ) ;
F_11 () ;
return;
}
V_173 -> V_226 = V_227 ;
F_142 ( V_173 , V_219 ) ;
if ( F_169 ( V_13 , & V_218 , V_229 ) ) {
V_179 = & V_230 ;
} else
V_179 = & V_218 ;
F_132 ( V_8 , V_173 , V_13 , V_179 , V_274 , V_232 , V_177 ) ;
memcpy ( F_134 ( V_173 , sizeof( V_183 ) ) , V_183 , sizeof( V_183 ) ) ;
V_210 = (struct V_165 * ) F_134 ( V_173 , sizeof( struct V_165 ) ) ;
memset ( V_210 , 0 , sizeof( struct V_165 ) ) ;
V_210 -> V_278 = type ;
V_210 -> V_185 = * V_11 ;
V_210 -> V_279 = F_149 ( V_179 , V_274 , V_176 ,
V_223 ,
F_150 ( V_210 , V_176 , 0 ) ) ;
F_8 () ;
V_2 = F_22 ( V_173 -> V_13 ) ;
F_151 ( V_8 , & V_243 , type ,
& F_120 ( V_173 ) -> V_179 , & F_120 ( V_173 ) -> V_208 ,
V_173 -> V_13 -> V_9 ) ;
V_27 = F_152 ( V_173 -> V_13 , & V_243 ) ;
if ( F_153 ( V_27 ) ) {
V_19 = F_154 ( V_27 ) ;
goto V_246;
}
F_155 ( V_173 , V_27 ) ;
V_19 = F_156 ( V_247 , V_248 ,
V_18 , V_8 , V_173 , NULL , V_173 -> V_13 ,
V_249 ) ;
V_250:
if ( ! V_19 ) {
F_157 ( V_18 , V_2 , type ) ;
F_158 ( V_18 , V_2 , V_251 ) ;
} else
F_159 ( V_18 , V_2 , V_252 ) ;
F_11 () ;
return;
V_246:
F_160 ( V_173 ) ;
goto V_250;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_172 * V_173 ;
struct V_90 * V_46 ;
int type ;
if ( F_2 ( V_2 ) )
return;
V_173 = NULL ;
F_29 ( & V_2 -> V_39 ) ;
for ( V_46 = V_2 -> V_119 ; V_46 ; V_46 = V_46 -> V_24 ) {
F_51 ( & V_46 -> V_95 ) ;
if ( V_46 -> V_125 [ V_30 ] )
type = V_205 ;
else
type = V_204 ;
V_173 = F_163 ( V_173 , V_46 , type , 0 , 0 , 1 ) ;
F_54 ( & V_46 -> V_95 ) ;
}
F_30 ( & V_2 -> V_39 ) ;
if ( V_173 )
F_146 ( V_173 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
V_2 -> V_280 = V_2 -> V_102 ;
if ( V_2 -> V_280 ) {
F_170 ( V_2 ) ;
V_2 -> V_280 -- ;
if ( V_2 -> V_280 )
F_92 ( V_2 , V_2 -> V_132 ) ;
}
}
static void F_172 ( unsigned long V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
F_170 ( V_2 ) ;
if ( V_2 -> V_280 ) {
V_2 -> V_280 -- ;
if ( V_2 -> V_280 )
F_92 ( V_2 , V_2 -> V_132 ) ;
}
F_69 ( V_2 ) ;
}
static int F_173 ( struct V_90 * V_46 , int V_29 ,
const struct V_10 * V_281 )
{
struct V_107 * V_108 , * V_263 ;
int V_52 = 0 ;
V_263 = NULL ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( F_10 ( & V_108 -> V_129 , V_281 ) )
break;
V_263 = V_108 ;
}
if ( ! V_108 || V_108 -> V_130 [ V_29 ] == 0 ) {
return - V_282 ;
}
V_108 -> V_130 [ V_29 ] -- ;
if ( ! V_108 -> V_130 [ V_63 ] && ! V_108 -> V_130 [ V_30 ] ) {
struct V_1 * V_2 = V_46 -> V_2 ;
if ( V_263 )
V_263 -> V_111 = V_108 -> V_111 ;
else
V_46 -> V_110 = V_108 -> V_111 ;
if ( V_108 -> V_283 && ! ( V_46 -> V_96 & V_100 ) &&
! F_2 ( V_2 ) ) {
V_108 -> V_112 = V_2 -> V_102 ;
V_108 -> V_111 = V_46 -> V_109 ;
V_46 -> V_109 = V_108 ;
V_52 = 1 ;
} else
F_68 ( V_108 ) ;
}
return V_52 ;
}
static int F_37 ( struct V_1 * V_2 , const struct V_10 * V_115 ,
int V_29 , int V_284 , const struct V_10 * V_281 ,
int V_285 )
{
struct V_90 * V_46 ;
int V_286 = 0 ;
int V_50 , V_19 ;
if ( ! V_2 )
return - V_28 ;
F_29 ( & V_2 -> V_39 ) ;
for ( V_46 = V_2 -> V_119 ; V_46 ; V_46 = V_46 -> V_24 ) {
if ( F_10 ( V_115 , & V_46 -> V_93 ) )
break;
}
if ( ! V_46 ) {
F_30 ( & V_2 -> V_39 ) ;
return - V_282 ;
}
F_51 ( & V_46 -> V_95 ) ;
F_174 ( V_46 ) ;
if ( ! V_285 ) {
if ( ! V_46 -> V_125 [ V_29 ] ) {
F_54 ( & V_46 -> V_95 ) ;
F_30 ( & V_2 -> V_39 ) ;
return - V_20 ;
}
V_46 -> V_125 [ V_29 ] -- ;
}
V_19 = 0 ;
for ( V_50 = 0 ; V_50 < V_284 ; V_50 ++ ) {
int V_52 = F_173 ( V_46 , V_29 , & V_281 [ V_50 ] ) ;
V_286 |= V_52 > 0 ;
if ( ! V_19 && V_52 < 0 )
V_19 = V_52 ;
}
if ( V_46 -> V_106 == V_30 &&
V_46 -> V_125 [ V_30 ] == 0 &&
V_46 -> V_125 [ V_63 ] ) {
struct V_107 * V_108 ;
V_46 -> V_106 = V_63 ;
V_46 -> V_101 = V_2 -> V_102 ;
V_2 -> V_137 = V_46 -> V_101 ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 )
V_108 -> V_112 = 0 ;
F_56 ( V_46 -> V_2 ) ;
} else if ( F_175 ( V_46 ) || V_286 )
F_56 ( V_46 -> V_2 ) ;
F_54 ( & V_46 -> V_95 ) ;
F_30 ( & V_2 -> V_39 ) ;
return V_19 ;
}
static int F_176 ( struct V_90 * V_46 , int V_29 ,
const struct V_10 * V_281 )
{
struct V_107 * V_108 , * V_263 ;
V_263 = NULL ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( F_10 ( & V_108 -> V_129 , V_281 ) )
break;
V_263 = V_108 ;
}
if ( ! V_108 ) {
V_108 = F_64 ( sizeof( * V_108 ) , V_70 ) ;
if ( ! V_108 )
return - V_65 ;
V_108 -> V_129 = * V_281 ;
if ( V_263 ) {
V_263 -> V_111 = V_108 ;
} else
V_46 -> V_110 = V_108 ;
}
V_108 -> V_130 [ V_29 ] ++ ;
return 0 ;
}
static void F_174 ( struct V_90 * V_46 )
{
struct V_107 * V_108 ;
int V_287 = V_46 -> V_125 [ V_30 ] ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 )
if ( V_46 -> V_125 [ V_30 ] ) {
V_108 -> V_283 = V_287 ==
V_108 -> V_130 [ V_30 ] &&
! V_108 -> V_130 [ V_63 ] ;
} else
V_108 -> V_283 = V_108 -> V_130 [ V_63 ] != 0 ;
}
static int F_175 ( struct V_90 * V_46 )
{
struct V_107 * V_108 , * V_288 ;
int V_287 = V_46 -> V_125 [ V_30 ] ;
int V_289 = V_46 -> V_2 -> V_102 ;
int V_290 , V_52 ;
V_52 = 0 ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 ) {
if ( V_46 -> V_125 [ V_30 ] ) {
V_290 = V_287 == V_108 -> V_130 [ V_30 ] &&
! V_108 -> V_130 [ V_63 ] ;
} else
V_290 = V_108 -> V_130 [ V_63 ] != 0 ;
if ( V_290 ) {
if ( ! V_108 -> V_283 ) {
struct V_107 * V_291 = NULL ;
for ( V_288 = V_46 -> V_109 ; V_288 ;
V_288 = V_288 -> V_111 ) {
if ( F_10 ( & V_288 -> V_129 ,
& V_108 -> V_129 ) )
break;
V_291 = V_288 ;
}
if ( V_288 ) {
if ( V_291 )
V_291 -> V_111 = V_288 -> V_111 ;
else
V_46 -> V_109 = V_288 -> V_111 ;
F_68 ( V_288 ) ;
}
V_108 -> V_112 = V_289 ;
V_52 ++ ;
}
} else if ( V_108 -> V_283 ) {
V_108 -> V_112 = 0 ;
for ( V_288 = V_46 -> V_109 ; V_288 ; V_288 = V_288 -> V_111 )
if ( F_10 ( & V_288 -> V_129 ,
& V_108 -> V_129 ) )
break;
if ( ! V_288 ) {
V_288 = F_177 ( sizeof( * V_288 ) , V_70 ) ;
if ( ! V_288 )
continue;
* V_288 = * V_108 ;
V_288 -> V_111 = V_46 -> V_109 ;
V_46 -> V_109 = V_288 ;
}
V_288 -> V_112 = V_289 ;
V_52 ++ ;
}
}
return V_52 ;
}
static int F_36 ( struct V_1 * V_2 , const struct V_10 * V_115 ,
int V_29 , int V_284 , const struct V_10 * V_281 ,
int V_285 )
{
struct V_90 * V_46 ;
int V_292 ;
int V_50 , V_19 ;
if ( ! V_2 )
return - V_28 ;
F_29 ( & V_2 -> V_39 ) ;
for ( V_46 = V_2 -> V_119 ; V_46 ; V_46 = V_46 -> V_24 ) {
if ( F_10 ( V_115 , & V_46 -> V_93 ) )
break;
}
if ( ! V_46 ) {
F_30 ( & V_2 -> V_39 ) ;
return - V_282 ;
}
F_51 ( & V_46 -> V_95 ) ;
F_174 ( V_46 ) ;
V_292 = V_46 -> V_106 == V_30 ;
if ( ! V_285 )
V_46 -> V_125 [ V_29 ] ++ ;
V_19 = 0 ;
for ( V_50 = 0 ; V_50 < V_284 ; V_50 ++ ) {
V_19 = F_176 ( V_46 , V_29 , & V_281 [ V_50 ] ) ;
if ( V_19 )
break;
}
if ( V_19 ) {
int V_51 ;
if ( ! V_285 )
V_46 -> V_125 [ V_29 ] -- ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
F_173 ( V_46 , V_29 , & V_281 [ V_51 ] ) ;
} else if ( V_292 != ( V_46 -> V_125 [ V_30 ] != 0 ) ) {
struct V_107 * V_108 ;
if ( V_46 -> V_125 [ V_30 ] )
V_46 -> V_106 = V_30 ;
else if ( V_46 -> V_125 [ V_63 ] )
V_46 -> V_106 = V_63 ;
V_46 -> V_101 = V_2 -> V_102 ;
V_2 -> V_137 = V_46 -> V_101 ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_108 -> V_111 )
V_108 -> V_112 = 0 ;
F_56 ( V_2 ) ;
} else if ( F_175 ( V_46 ) )
F_56 ( V_2 ) ;
F_54 ( & V_46 -> V_95 ) ;
F_30 ( & V_2 -> V_39 ) ;
return V_19 ;
}
static void F_62 ( struct V_90 * V_46 )
{
struct V_107 * V_108 , * V_293 ;
for ( V_108 = V_46 -> V_109 ; V_108 ; V_108 = V_293 ) {
V_293 = V_108 -> V_111 ;
F_68 ( V_108 ) ;
}
V_46 -> V_109 = NULL ;
for ( V_108 = V_46 -> V_110 ; V_108 ; V_108 = V_293 ) {
V_293 = V_108 -> V_111 ;
F_68 ( V_108 ) ;
}
V_46 -> V_110 = NULL ;
V_46 -> V_106 = V_30 ;
V_46 -> V_125 [ V_63 ] = 0 ;
V_46 -> V_125 [ V_30 ] = 1 ;
}
static void F_55 ( struct V_90 * V_126 )
{
unsigned long V_135 ;
if ( V_126 -> V_96 & V_100 )
return;
F_168 ( & V_126 -> V_93 , V_126 -> V_2 -> V_13 , V_294 ) ;
V_135 = F_86 () % F_1 ( V_126 -> V_2 ) ;
F_51 ( & V_126 -> V_95 ) ;
if ( F_60 ( & V_126 -> V_103 ) ) {
F_61 ( & V_126 -> V_104 ) ;
V_135 = V_126 -> V_103 . V_140 - V_124 ;
}
if ( ! F_87 ( & V_126 -> V_103 , V_124 + V_135 ) )
F_72 ( & V_126 -> V_104 ) ;
V_126 -> V_96 |= V_141 | V_199 ;
F_54 ( & V_126 -> V_95 ) ;
}
static int F_23 ( struct V_7 * V_8 , struct V_14 * V_295 ,
struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_295 -> V_32 ) {
return F_37 ( V_2 , & V_295 -> V_11 , V_295 -> V_29 , 0 , NULL , 0 ) ;
}
V_19 = F_37 ( V_2 , & V_295 -> V_11 , V_295 -> V_29 ,
V_295 -> V_32 -> V_61 , V_295 -> V_32 -> V_62 , 0 ) ;
F_16 ( V_8 , V_295 -> V_32 , F_39 ( V_295 -> V_32 -> V_66 ) ) ;
V_295 -> V_32 = NULL ;
return V_19 ;
}
static void F_59 ( struct V_90 * V_126 )
{
if ( F_2 ( V_126 -> V_2 ) ) {
if ( V_126 -> V_96 & V_199 )
F_168 ( & V_126 -> V_93 , V_126 -> V_2 -> V_13 ,
V_276 ) ;
} else {
F_63 ( V_126 -> V_2 , V_126 ) ;
F_56 ( V_126 -> V_2 ) ;
}
}
static void F_178 ( unsigned long V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
V_2 -> V_133 = 0 ;
F_165 ( V_2 , NULL ) ;
F_69 ( V_2 ) ;
}
static void F_179 ( unsigned long V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
F_167 ( V_2 ) ;
if ( V_2 -> V_137 ) {
V_2 -> V_137 -- ;
if ( V_2 -> V_137 )
F_90 ( V_2 , V_2 -> V_132 ) ;
}
F_69 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return;
V_2 -> V_137 = V_2 -> V_102 ;
F_90 ( V_2 , 1 ) ;
}
static void V_120 ( unsigned long V_233 )
{
struct V_90 * V_126 = (struct V_90 * ) V_233 ;
if ( F_2 ( V_126 -> V_2 ) )
F_168 ( & V_126 -> V_93 , V_126 -> V_2 -> V_13 , V_294 ) ;
else
F_165 ( V_126 -> V_2 , V_126 ) ;
F_128 ( & V_126 -> V_95 ) ;
V_126 -> V_96 |= V_199 ;
V_126 -> V_96 &= ~ V_141 ;
F_129 ( & V_126 -> V_95 ) ;
F_73 ( V_126 ) ;
}
void F_180 ( struct V_1 * V_2 )
{
struct V_90 * V_50 ;
F_29 ( & V_2 -> V_39 ) ;
for ( V_50 = V_2 -> V_119 ; V_50 ; V_50 = V_50 -> V_24 )
F_57 ( V_50 ) ;
F_30 ( & V_2 -> V_39 ) ;
}
void F_181 ( struct V_1 * V_2 )
{
F_182 ( V_2 ) ;
}
void F_183 ( struct V_1 * V_2 )
{
struct V_90 * V_50 ;
F_29 ( & V_2 -> V_39 ) ;
F_91 ( V_2 ) ;
F_88 ( V_2 ) ;
F_93 ( V_2 ) ;
for ( V_50 = V_2 -> V_119 ; V_50 ; V_50 = V_50 -> V_24 )
F_57 ( V_50 ) ;
F_30 ( & V_2 -> V_39 ) ;
F_70 ( V_2 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
V_2 -> V_102 = V_158 ;
V_2 -> V_152 = V_296 ;
V_2 -> V_153 = V_297 ;
V_2 -> V_150 = 0 ;
V_2 -> V_132 = F_1 ( V_2 ) ;
}
void F_182 ( struct V_1 * V_2 )
{
struct V_90 * V_50 ;
F_29 ( & V_2 -> V_39 ) ;
F_184 ( V_2 ) ;
for ( V_50 = V_2 -> V_119 ; V_50 ; V_50 = V_50 -> V_24 )
F_49 ( V_50 ) ;
F_30 ( & V_2 -> V_39 ) ;
}
void F_185 ( struct V_1 * V_2 )
{
F_80 ( & V_2 -> V_39 ) ;
F_65 ( & V_2 -> V_113 ) ;
V_2 -> V_133 = 0 ;
F_76 ( & V_2 -> V_134 , F_178 ,
( unsigned long ) V_2 ) ;
V_2 -> V_114 = NULL ;
V_2 -> V_137 = 0 ;
F_76 ( & V_2 -> V_136 , F_179 ,
( unsigned long ) V_2 ) ;
F_76 ( & V_2 -> V_138 , F_172 ,
( unsigned long ) V_2 ) ;
F_184 ( V_2 ) ;
F_81 ( & V_2 -> V_39 ) ;
}
void F_186 ( struct V_1 * V_2 )
{
struct V_90 * V_50 ;
F_183 ( V_2 ) ;
F_24 ( V_2 , & V_298 ) ;
if ( V_2 -> V_4 . V_299 )
F_24 ( V_2 , & V_277 ) ;
F_80 ( & V_2 -> V_39 ) ;
while ( ( V_50 = V_2 -> V_119 ) != NULL ) {
V_2 -> V_119 = V_50 -> V_24 ;
F_81 ( & V_2 -> V_39 ) ;
F_57 ( V_50 ) ;
F_73 ( V_50 ) ;
F_80 ( & V_2 -> V_39 ) ;
}
F_81 ( & V_2 -> V_39 ) ;
}
static inline struct V_90 * F_187 ( struct V_300 * V_301 )
{
struct V_90 * V_105 = NULL ;
struct V_302 * V_303 = F_188 ( V_301 ) ;
struct V_18 * V_18 = F_189 ( V_301 ) ;
V_303 -> V_2 = NULL ;
F_190 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_22 ( V_303 -> V_13 ) ;
if ( ! V_2 )
continue;
F_29 ( & V_2 -> V_39 ) ;
V_105 = V_2 -> V_119 ;
if ( V_105 ) {
V_303 -> V_2 = V_2 ;
break;
}
F_30 ( & V_2 -> V_39 ) ;
}
return V_105 ;
}
static struct V_90 * F_191 ( struct V_300 * V_301 , struct V_90 * V_105 )
{
struct V_302 * V_303 = F_188 ( V_301 ) ;
V_105 = V_105 -> V_24 ;
while ( ! V_105 ) {
if ( F_192 ( V_303 -> V_2 ) )
F_30 ( & V_303 -> V_2 -> V_39 ) ;
V_303 -> V_13 = F_193 ( V_303 -> V_13 ) ;
if ( ! V_303 -> V_13 ) {
V_303 -> V_2 = NULL ;
break;
}
V_303 -> V_2 = F_22 ( V_303 -> V_13 ) ;
if ( ! V_303 -> V_2 )
continue;
F_29 ( & V_303 -> V_2 -> V_39 ) ;
V_105 = V_303 -> V_2 -> V_119 ;
}
return V_105 ;
}
static struct V_90 * F_194 ( struct V_300 * V_301 , T_4 V_304 )
{
struct V_90 * V_105 = F_187 ( V_301 ) ;
if ( V_105 )
while ( V_304 && ( V_105 = F_191 ( V_301 , V_105 ) ) != NULL )
-- V_304 ;
return V_304 ? NULL : V_105 ;
}
static void * F_195 ( struct V_300 * V_301 , T_4 * V_304 )
__acquires( T_5 )
{
F_8 () ;
return F_194 ( V_301 , * V_304 ) ;
}
static void * F_196 ( struct V_300 * V_301 , void * V_305 , T_4 * V_304 )
{
struct V_90 * V_105 = F_191 ( V_301 , V_305 ) ;
++ * V_304 ;
return V_105 ;
}
static void F_197 ( struct V_300 * V_301 , void * V_305 )
__releases( T_5 )
{
struct V_302 * V_303 = F_188 ( V_301 ) ;
if ( F_192 ( V_303 -> V_2 ) ) {
F_30 ( & V_303 -> V_2 -> V_39 ) ;
V_303 -> V_2 = NULL ;
}
V_303 -> V_13 = NULL ;
F_11 () ;
}
static int F_198 ( struct V_300 * V_301 , void * V_305 )
{
struct V_90 * V_105 = (struct V_90 * ) V_305 ;
struct V_302 * V_303 = F_188 ( V_301 ) ;
F_199 ( V_301 ,
L_2 ,
V_303 -> V_13 -> V_9 , V_303 -> V_13 -> V_306 ,
& V_105 -> V_93 ,
V_105 -> V_121 , V_105 -> V_96 ,
( V_105 -> V_96 & V_141 ) ?
F_200 ( V_105 -> V_103 . V_140 - V_124 ) : 0 ) ;
return 0 ;
}
static int F_201 ( struct V_307 * V_307 , struct V_308 * V_308 )
{
return F_202 ( V_307 , V_308 , & V_309 ,
sizeof( struct V_302 ) ) ;
}
static inline struct V_107 * F_203 ( struct V_300 * V_301 )
{
struct V_107 * V_108 = NULL ;
struct V_90 * V_105 = NULL ;
struct V_310 * V_303 = F_204 ( V_301 ) ;
struct V_18 * V_18 = F_189 ( V_301 ) ;
V_303 -> V_2 = NULL ;
V_303 -> V_105 = NULL ;
F_190 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_22 ( V_303 -> V_13 ) ;
if ( F_106 ( V_2 == NULL ) )
continue;
F_29 ( & V_2 -> V_39 ) ;
V_105 = V_2 -> V_119 ;
if ( F_192 ( V_105 ) ) {
F_51 ( & V_105 -> V_95 ) ;
V_108 = V_105 -> V_110 ;
if ( F_192 ( V_108 ) ) {
V_303 -> V_105 = V_105 ;
V_303 -> V_2 = V_2 ;
break;
}
F_54 ( & V_105 -> V_95 ) ;
}
F_30 ( & V_2 -> V_39 ) ;
}
return V_108 ;
}
static struct V_107 * F_205 ( struct V_300 * V_301 , struct V_107 * V_108 )
{
struct V_310 * V_303 = F_204 ( V_301 ) ;
V_108 = V_108 -> V_111 ;
while ( ! V_108 ) {
F_54 ( & V_303 -> V_105 -> V_95 ) ;
V_303 -> V_105 = V_303 -> V_105 -> V_24 ;
while ( ! V_303 -> V_105 ) {
if ( F_192 ( V_303 -> V_2 ) )
F_30 ( & V_303 -> V_2 -> V_39 ) ;
V_303 -> V_13 = F_193 ( V_303 -> V_13 ) ;
if ( ! V_303 -> V_13 ) {
V_303 -> V_2 = NULL ;
goto V_250;
}
V_303 -> V_2 = F_22 ( V_303 -> V_13 ) ;
if ( ! V_303 -> V_2 )
continue;
F_29 ( & V_303 -> V_2 -> V_39 ) ;
V_303 -> V_105 = V_303 -> V_2 -> V_119 ;
}
if ( ! V_303 -> V_105 )
break;
F_51 ( & V_303 -> V_105 -> V_95 ) ;
V_108 = V_303 -> V_105 -> V_110 ;
}
V_250:
return V_108 ;
}
static struct V_107 * F_206 ( struct V_300 * V_301 , T_4 V_304 )
{
struct V_107 * V_108 = F_203 ( V_301 ) ;
if ( V_108 )
while ( V_304 && ( V_108 = F_205 ( V_301 , V_108 ) ) != NULL )
-- V_304 ;
return V_304 ? NULL : V_108 ;
}
static void * F_207 ( struct V_300 * V_301 , T_4 * V_304 )
__acquires( T_5 )
{
F_8 () ;
return * V_304 ? F_206 ( V_301 , * V_304 - 1 ) : V_311 ;
}
static void * F_208 ( struct V_300 * V_301 , void * V_305 , T_4 * V_304 )
{
struct V_107 * V_108 ;
if ( V_305 == V_311 )
V_108 = F_203 ( V_301 ) ;
else
V_108 = F_205 ( V_301 , V_305 ) ;
++ * V_304 ;
return V_108 ;
}
static void F_209 ( struct V_300 * V_301 , void * V_305 )
__releases( T_5 )
{
struct V_310 * V_303 = F_204 ( V_301 ) ;
if ( F_192 ( V_303 -> V_105 ) ) {
F_54 ( & V_303 -> V_105 -> V_95 ) ;
V_303 -> V_105 = NULL ;
}
if ( F_192 ( V_303 -> V_2 ) ) {
F_30 ( & V_303 -> V_2 -> V_39 ) ;
V_303 -> V_2 = NULL ;
}
V_303 -> V_13 = NULL ;
F_11 () ;
}
static int F_210 ( struct V_300 * V_301 , void * V_305 )
{
struct V_107 * V_108 = (struct V_107 * ) V_305 ;
struct V_310 * V_303 = F_204 ( V_301 ) ;
if ( V_305 == V_311 ) {
F_211 ( V_301 , L_3 ) ;
} else {
F_199 ( V_301 ,
L_4 ,
V_303 -> V_13 -> V_9 , V_303 -> V_13 -> V_306 ,
& V_303 -> V_105 -> V_93 ,
& V_108 -> V_129 ,
V_108 -> V_130 [ V_63 ] ,
V_108 -> V_130 [ V_30 ] ) ;
}
return 0 ;
}
static int F_212 ( struct V_307 * V_307 , struct V_308 * V_308 )
{
return F_202 ( V_307 , V_308 , & V_312 ,
sizeof( struct V_310 ) ) ;
}
static int T_6 F_213 ( struct V_18 * V_18 )
{
int V_19 ;
V_19 = - V_23 ;
if ( ! F_214 ( L_5 , V_313 , V_18 -> V_314 , & V_315 ) )
goto V_250;
if ( ! F_214 ( L_6 , V_313 , V_18 -> V_314 ,
& V_316 ) )
goto V_317;
V_19 = 0 ;
V_250:
return V_19 ;
V_317:
F_215 ( L_5 , V_18 -> V_314 ) ;
goto V_250;
}
static void T_7 F_216 ( struct V_18 * V_18 )
{
F_215 ( L_6 , V_18 -> V_314 ) ;
F_215 ( L_5 , V_18 -> V_314 ) ;
}
static inline int F_213 ( struct V_18 * V_18 )
{
return 0 ;
}
static inline void F_216 ( struct V_18 * V_18 )
{
}
static int T_6 F_217 ( struct V_18 * V_18 )
{
int V_19 ;
V_19 = F_218 ( & V_18 -> V_147 . V_215 , V_318 ,
V_319 , V_223 , V_18 ) ;
if ( V_19 < 0 ) {
F_219 ( L_7 ,
V_19 ) ;
goto V_250;
}
F_4 ( V_18 -> V_147 . V_215 ) -> V_181 = 1 ;
V_19 = F_218 ( & V_18 -> V_147 . V_320 , V_318 ,
V_319 , V_223 , V_18 ) ;
if ( V_19 < 0 ) {
F_219 ( L_8 ,
V_19 ) ;
goto V_321;
}
V_19 = F_213 ( V_18 ) ;
if ( V_19 )
goto V_322;
return 0 ;
V_322:
F_220 ( V_18 -> V_147 . V_320 ) ;
V_321:
F_220 ( V_18 -> V_147 . V_215 ) ;
V_250:
return V_19 ;
}
static void T_7 F_221 ( struct V_18 * V_18 )
{
F_220 ( V_18 -> V_147 . V_215 ) ;
F_220 ( V_18 -> V_147 . V_320 ) ;
F_216 ( V_18 ) ;
}
int T_8 F_222 ( void )
{
return F_223 ( & V_323 ) ;
}
void F_224 ( void )
{
F_225 ( & V_323 ) ;
}
