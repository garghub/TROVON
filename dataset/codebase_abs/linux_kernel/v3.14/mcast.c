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
if ( ! F_6 ( V_11 ) )
return - V_20 ;
F_7 () ;
F_8 (np, mc_lst) {
if ( ( V_9 == 0 || V_15 -> V_9 == V_9 ) &&
F_9 ( & V_15 -> V_11 , V_11 ) ) {
F_10 () ;
return - V_21 ;
}
}
F_10 () ;
V_15 = F_11 ( V_8 , sizeof( struct V_14 ) , V_22 ) ;
if ( V_15 == NULL )
return - V_23 ;
V_15 -> V_24 = NULL ;
V_15 -> V_11 = * V_11 ;
F_7 () ;
if ( V_9 == 0 ) {
struct V_25 * V_26 ;
V_26 = F_12 ( V_18 , V_11 , NULL , 0 , 0 ) ;
if ( V_26 ) {
V_13 = V_26 -> V_27 . V_13 ;
F_13 ( V_26 ) ;
}
} else
V_13 = F_14 ( V_18 , V_9 ) ;
if ( V_13 == NULL ) {
F_10 () ;
F_15 ( V_8 , V_15 , sizeof( * V_15 ) ) ;
return - V_28 ;
}
V_15 -> V_9 = V_13 -> V_9 ;
V_15 -> V_29 = V_30 ;
F_16 ( & V_15 -> V_31 ) ;
V_15 -> V_32 = NULL ;
V_19 = F_17 ( V_13 , V_11 ) ;
if ( V_19 ) {
F_10 () ;
F_15 ( V_8 , V_15 , sizeof( * V_15 ) ) ;
return V_19 ;
}
F_18 ( & V_33 ) ;
V_15 -> V_24 = V_17 -> V_34 ;
F_19 ( V_17 -> V_34 , V_15 ) ;
F_20 ( & V_33 ) ;
F_10 () ;
return 0 ;
}
int F_21 ( struct V_7 * V_8 , int V_9 , const struct V_10 * V_11 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_14 * V_15 ;
struct V_14 T_1 * * V_35 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
if ( ! F_6 ( V_11 ) )
return - V_20 ;
F_18 ( & V_33 ) ;
for ( V_35 = & V_17 -> V_34 ;
( V_15 = F_22 ( * V_35 ,
F_23 ( & V_33 ) ) ) != NULL ;
V_35 = & V_15 -> V_24 ) {
if ( ( V_9 == 0 || V_15 -> V_9 == V_9 ) &&
F_9 ( & V_15 -> V_11 , V_11 ) ) {
struct V_12 * V_13 ;
* V_35 = V_15 -> V_24 ;
F_20 ( & V_33 ) ;
F_7 () ;
V_13 = F_14 ( V_18 , V_15 -> V_9 ) ;
if ( V_13 != NULL ) {
struct V_1 * V_2 = F_24 ( V_13 ) ;
( void ) F_25 ( V_8 , V_15 , V_2 ) ;
if ( V_2 )
F_26 ( V_2 , & V_15 -> V_11 ) ;
} else
( void ) F_25 ( V_8 , V_15 , NULL ) ;
F_10 () ;
F_27 ( sizeof( * V_15 ) , & V_8 -> V_36 ) ;
F_28 ( V_15 , V_37 ) ;
return 0 ;
}
}
F_20 ( & V_33 ) ;
return - V_38 ;
}
static struct V_1 * F_29 ( struct V_18 * V_18 ,
const struct V_10 * V_39 ,
int V_9 )
{
struct V_12 * V_13 = NULL ;
struct V_1 * V_2 = NULL ;
if ( V_9 == 0 ) {
struct V_25 * V_26 = F_12 ( V_18 , V_39 , NULL , 0 , 0 ) ;
if ( V_26 ) {
V_13 = V_26 -> V_27 . V_13 ;
F_13 ( V_26 ) ;
}
} else
V_13 = F_14 ( V_18 , V_9 ) ;
if ( ! V_13 )
return NULL ;
V_2 = F_24 ( V_13 ) ;
if ( ! V_2 )
return NULL ;
F_30 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_41 ) {
F_31 ( & V_2 -> V_40 ) ;
return NULL ;
}
return V_2 ;
}
void F_32 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_14 * V_15 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
if ( ! F_33 ( V_17 -> V_34 ) )
return;
F_18 ( & V_33 ) ;
while ( ( V_15 = F_22 ( V_17 -> V_34 ,
F_23 ( & V_33 ) ) ) != NULL ) {
struct V_12 * V_13 ;
V_17 -> V_34 = V_15 -> V_24 ;
F_20 ( & V_33 ) ;
F_7 () ;
V_13 = F_14 ( V_18 , V_15 -> V_9 ) ;
if ( V_13 ) {
struct V_1 * V_2 = F_24 ( V_13 ) ;
( void ) F_25 ( V_8 , V_15 , V_2 ) ;
if ( V_2 )
F_26 ( V_2 , & V_15 -> V_11 ) ;
} else
( void ) F_25 ( V_8 , V_15 , NULL ) ;
F_10 () ;
F_27 ( sizeof( * V_15 ) , & V_8 -> V_36 ) ;
F_28 ( V_15 , V_37 ) ;
F_18 ( & V_33 ) ;
}
F_20 ( & V_33 ) ;
}
int F_34 ( int V_42 , int V_43 , struct V_7 * V_8 ,
struct V_44 * V_45 )
{
struct V_10 * V_46 , * V_39 ;
struct V_14 * V_47 ;
struct V_1 * V_2 ;
struct V_16 * V_48 = F_4 ( V_8 ) ;
struct V_49 * V_50 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
int V_51 , V_52 , V_53 ;
int V_54 = 0 ;
int V_55 = 0 ;
int V_19 ;
V_46 = & ( (struct V_56 * ) & V_45 -> V_57 ) -> V_58 ;
V_39 = & ( (struct V_56 * ) & V_45 -> V_59 ) -> V_58 ;
if ( ! F_6 ( V_39 ) )
return - V_20 ;
F_7 () ;
V_2 = F_29 ( V_18 , V_39 , V_45 -> V_60 ) ;
if ( ! V_2 ) {
F_10 () ;
return - V_28 ;
}
V_19 = - V_38 ;
F_8 (inet6, pmc) {
if ( V_45 -> V_60 && V_47 -> V_9 != V_45 -> V_60 )
continue;
if ( F_9 ( & V_47 -> V_11 , V_39 ) )
break;
}
if ( ! V_47 ) {
V_19 = - V_20 ;
goto V_61;
}
if ( V_47 -> V_32 ) {
if ( V_47 -> V_29 != V_43 ) {
V_19 = - V_20 ;
goto V_61;
}
} else if ( V_47 -> V_29 != V_43 ) {
F_35 ( V_2 , V_39 , V_43 , 0 , NULL , 0 ) ;
F_36 ( V_2 , V_39 , V_47 -> V_29 , 0 , NULL , 0 ) ;
V_47 -> V_29 = V_43 ;
}
F_37 ( & V_47 -> V_31 ) ;
V_55 = 1 ;
V_50 = V_47 -> V_32 ;
if ( ! V_42 ) {
if ( ! V_50 )
goto V_61;
V_53 = ! 0 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_62 ; V_51 ++ ) {
V_53 = ! F_9 ( & V_50 -> V_63 [ V_51 ] , V_46 ) ;
if ( V_53 == 0 )
break;
}
if ( V_53 )
goto V_61;
if ( V_50 -> V_62 == 1 && V_43 == V_64 ) {
V_54 = 1 ;
goto V_61;
}
F_36 ( V_2 , V_39 , V_43 , 1 , V_46 , 1 ) ;
for ( V_52 = V_51 + 1 ; V_52 < V_50 -> V_62 ; V_52 ++ )
V_50 -> V_63 [ V_52 - 1 ] = V_50 -> V_63 [ V_52 ] ;
V_50 -> V_62 -- ;
V_19 = 0 ;
goto V_61;
}
if ( V_50 && V_50 -> V_62 >= V_65 ) {
V_19 = - V_66 ;
goto V_61;
}
if ( ! V_50 || V_50 -> V_62 == V_50 -> V_67 ) {
struct V_49 * V_68 ;
int V_69 = V_70 ;
if ( V_50 )
V_69 += V_50 -> V_67 ;
V_68 = F_11 ( V_8 , F_38 ( V_69 ) , V_71 ) ;
if ( ! V_68 ) {
V_19 = - V_66 ;
goto V_61;
}
V_68 -> V_67 = V_69 ;
V_68 -> V_62 = V_69 - V_70 ;
if ( V_50 ) {
for ( V_51 = 0 ; V_51 < V_50 -> V_62 ; V_51 ++ )
V_68 -> V_63 [ V_51 ] = V_50 -> V_63 [ V_51 ] ;
F_15 ( V_8 , V_50 , F_38 ( V_50 -> V_67 ) ) ;
}
V_47 -> V_32 = V_50 = V_68 ;
}
V_53 = 1 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_62 ; V_51 ++ ) {
V_53 = ! F_9 ( & V_50 -> V_63 [ V_51 ] , V_46 ) ;
if ( V_53 == 0 )
goto V_61;
}
for ( V_52 = V_50 -> V_62 - 1 ; V_52 >= V_51 ; V_52 -- )
V_50 -> V_63 [ V_52 + 1 ] = V_50 -> V_63 [ V_52 ] ;
V_50 -> V_63 [ V_51 ] = * V_46 ;
V_50 -> V_62 ++ ;
V_19 = 0 ;
F_35 ( V_2 , V_39 , V_43 , 1 , V_46 , 1 ) ;
V_61:
if ( V_55 )
F_39 ( & V_47 -> V_31 ) ;
F_31 ( & V_2 -> V_40 ) ;
F_10 () ;
if ( V_54 )
return F_21 ( V_8 , V_45 -> V_60 , V_39 ) ;
return V_19 ;
}
int F_40 ( struct V_7 * V_8 , struct V_72 * V_73 )
{
const struct V_10 * V_39 ;
struct V_14 * V_47 ;
struct V_1 * V_2 ;
struct V_16 * V_48 = F_4 ( V_8 ) ;
struct V_49 * V_68 , * V_50 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
int V_54 = 0 ;
int V_51 , V_19 ;
V_39 = & ( (struct V_56 * ) & V_73 -> V_74 ) -> V_58 ;
if ( ! F_6 ( V_39 ) )
return - V_20 ;
if ( V_73 -> V_75 != V_64 &&
V_73 -> V_75 != V_30 )
return - V_20 ;
F_7 () ;
V_2 = F_29 ( V_18 , V_39 , V_73 -> V_76 ) ;
if ( ! V_2 ) {
F_10 () ;
return - V_28 ;
}
V_19 = 0 ;
if ( V_73 -> V_75 == V_64 && V_73 -> V_77 == 0 ) {
V_54 = 1 ;
goto V_61;
}
F_8 (inet6, pmc) {
if ( V_47 -> V_9 != V_73 -> V_76 )
continue;
if ( F_9 ( & V_47 -> V_11 , V_39 ) )
break;
}
if ( ! V_47 ) {
V_19 = - V_20 ;
goto V_61;
}
if ( V_73 -> V_77 ) {
V_68 = F_11 ( V_8 , F_38 ( V_73 -> V_77 ) ,
V_71 ) ;
if ( ! V_68 ) {
V_19 = - V_66 ;
goto V_61;
}
V_68 -> V_67 = V_68 -> V_62 = V_73 -> V_77 ;
for ( V_51 = 0 ; V_51 < V_68 -> V_62 ; ++ V_51 ) {
struct V_56 * V_78 ;
V_78 = (struct V_56 * ) & V_73 -> V_79 [ V_51 ] ;
V_68 -> V_63 [ V_51 ] = V_78 -> V_58 ;
}
V_19 = F_35 ( V_2 , V_39 , V_73 -> V_75 ,
V_68 -> V_62 , V_68 -> V_63 , 0 ) ;
if ( V_19 ) {
F_15 ( V_8 , V_68 , F_38 ( V_68 -> V_67 ) ) ;
goto V_61;
}
} else {
V_68 = NULL ;
( void ) F_35 ( V_2 , V_39 , V_73 -> V_75 , 0 , NULL , 0 ) ;
}
F_37 ( & V_47 -> V_31 ) ;
V_50 = V_47 -> V_32 ;
if ( V_50 ) {
( void ) F_36 ( V_2 , V_39 , V_47 -> V_29 ,
V_50 -> V_62 , V_50 -> V_63 , 0 ) ;
F_15 ( V_8 , V_50 , F_38 ( V_50 -> V_67 ) ) ;
} else
( void ) F_36 ( V_2 , V_39 , V_47 -> V_29 , 0 , NULL , 0 ) ;
V_47 -> V_32 = V_68 ;
V_47 -> V_29 = V_73 -> V_75 ;
F_39 ( & V_47 -> V_31 ) ;
V_19 = 0 ;
V_61:
F_31 ( & V_2 -> V_40 ) ;
F_10 () ;
if ( V_54 )
V_19 = F_21 ( V_8 , V_73 -> V_76 , V_39 ) ;
return V_19 ;
}
int F_41 ( struct V_7 * V_8 , struct V_72 * V_73 ,
struct V_72 T_2 * V_80 , int T_2 * V_81 )
{
int V_19 , V_51 , V_69 , V_82 ;
const struct V_10 * V_39 ;
struct V_14 * V_47 ;
struct V_1 * V_2 ;
struct V_16 * V_48 = F_4 ( V_8 ) ;
struct V_49 * V_50 ;
struct V_18 * V_18 = F_5 ( V_8 ) ;
V_39 = & ( (struct V_56 * ) & V_73 -> V_74 ) -> V_58 ;
if ( ! F_6 ( V_39 ) )
return - V_20 ;
F_7 () ;
V_2 = F_29 ( V_18 , V_39 , V_73 -> V_76 ) ;
if ( ! V_2 ) {
F_10 () ;
return - V_28 ;
}
V_19 = - V_38 ;
F_8 (inet6, pmc) {
if ( V_47 -> V_9 != V_73 -> V_76 )
continue;
if ( F_9 ( V_39 , & V_47 -> V_11 ) )
break;
}
if ( ! V_47 )
goto V_61;
V_73 -> V_75 = V_47 -> V_29 ;
V_50 = V_47 -> V_32 ;
V_69 = V_50 ? V_50 -> V_62 : 0 ;
F_31 ( & V_2 -> V_40 ) ;
F_10 () ;
V_82 = V_69 < V_73 -> V_77 ? V_69 : V_73 -> V_77 ;
V_73 -> V_77 = V_69 ;
if ( F_42 ( F_43 ( V_82 ) , V_81 ) ||
F_44 ( V_80 , V_73 , F_43 ( 0 ) ) ) {
return - V_83 ;
}
for ( V_51 = 0 ; V_51 < V_82 ; V_51 ++ ) {
struct V_56 * V_78 ;
struct V_84 V_85 ;
V_78 = (struct V_56 * ) & V_85 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_78 -> V_86 = V_87 ;
V_78 -> V_58 = V_50 -> V_63 [ V_51 ] ;
if ( F_44 ( & V_80 -> V_79 [ V_51 ] , & V_85 , sizeof( V_85 ) ) )
return - V_83 ;
}
return 0 ;
V_61:
F_31 ( & V_2 -> V_40 ) ;
F_10 () ;
return V_19 ;
}
bool F_45 ( struct V_7 * V_8 , const struct V_10 * V_88 ,
const struct V_10 * V_89 )
{
struct V_16 * V_17 = F_4 ( V_8 ) ;
struct V_14 * V_90 ;
struct V_49 * V_50 ;
bool V_53 = true ;
F_7 () ;
F_8 (np, mc) {
if ( F_9 ( & V_90 -> V_11 , V_88 ) )
break;
}
if ( ! V_90 ) {
F_10 () ;
return true ;
}
F_46 ( & V_90 -> V_31 ) ;
V_50 = V_90 -> V_32 ;
if ( ! V_50 ) {
V_53 = V_90 -> V_29 == V_30 ;
} else {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_62 ; V_51 ++ ) {
if ( F_9 ( & V_50 -> V_63 [ V_51 ] , V_89 ) )
break;
}
if ( V_90 -> V_29 == V_64 && V_51 >= V_50 -> V_62 )
V_53 = false ;
if ( V_90 -> V_29 == V_30 && V_51 < V_50 -> V_62 )
V_53 = false ;
}
F_47 ( & V_90 -> V_31 ) ;
F_10 () ;
return V_53 ;
}
static void F_48 ( struct V_91 * V_90 )
{
if ( F_49 ( & V_90 -> V_92 ) ) {
F_50 ( V_90 -> V_2 ) ;
F_51 ( V_90 ) ;
}
}
static void F_52 ( struct V_91 * V_90 )
{
struct V_12 * V_13 = V_90 -> V_2 -> V_13 ;
char V_93 [ V_94 ] ;
if ( F_53 ( & V_90 -> V_95 ) <
V_96 )
return;
F_54 ( & V_90 -> V_97 ) ;
if ( ! ( V_90 -> V_98 & V_99 ) ) {
V_90 -> V_98 |= V_99 ;
if ( F_55 ( & V_90 -> V_95 , V_93 , V_13 , 0 ) == 0 )
F_56 ( V_13 , V_93 ) ;
}
F_57 ( & V_90 -> V_97 ) ;
if ( ! ( V_13 -> V_100 & V_101 ) || ( V_90 -> V_98 & V_102 ) )
return;
if ( F_2 ( V_90 -> V_2 ) ) {
F_58 ( V_90 ) ;
return;
}
V_90 -> V_103 = V_90 -> V_2 -> V_104 ;
F_59 ( V_90 -> V_2 ) ;
}
static void F_60 ( struct V_91 * V_90 )
{
struct V_12 * V_13 = V_90 -> V_2 -> V_13 ;
char V_93 [ V_94 ] ;
if ( F_53 ( & V_90 -> V_95 ) <
V_96 )
return;
F_54 ( & V_90 -> V_97 ) ;
if ( V_90 -> V_98 & V_99 ) {
V_90 -> V_98 &= ~ V_99 ;
if ( F_55 ( & V_90 -> V_95 , V_93 , V_13 , 0 ) == 0 )
F_61 ( V_13 , V_93 ) ;
}
if ( V_90 -> V_98 & V_102 )
goto V_61;
F_57 ( & V_90 -> V_97 ) ;
if ( ! V_90 -> V_2 -> V_41 )
F_62 ( V_90 ) ;
F_54 ( & V_90 -> V_97 ) ;
if ( F_63 ( & V_90 -> V_105 ) )
F_64 ( & V_90 -> V_92 ) ;
V_61:
F_65 ( V_90 ) ;
F_57 ( & V_90 -> V_97 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_91 * V_106 )
{
struct V_91 * V_47 ;
V_47 = F_67 ( sizeof( * V_47 ) , V_71 ) ;
if ( ! V_47 )
return;
F_54 ( & V_106 -> V_97 ) ;
F_68 ( & V_47 -> V_97 ) ;
V_47 -> V_2 = V_106 -> V_2 ;
F_69 ( V_2 ) ;
V_47 -> V_95 = V_106 -> V_95 ;
V_47 -> V_103 = V_2 -> V_104 ;
V_47 -> V_107 = V_106 -> V_107 ;
if ( V_47 -> V_107 == V_64 ) {
struct V_108 * V_109 ;
V_47 -> V_110 = V_106 -> V_110 ;
V_47 -> V_111 = V_106 -> V_111 ;
V_106 -> V_110 = V_106 -> V_111 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 )
V_109 -> V_113 = V_47 -> V_103 ;
}
F_57 ( & V_106 -> V_97 ) ;
F_54 ( & V_2 -> V_114 ) ;
V_47 -> V_24 = V_2 -> V_115 ;
V_2 -> V_115 = V_47 ;
F_57 ( & V_2 -> V_114 ) ;
}
static void F_70 ( struct V_1 * V_2 , const struct V_10 * V_116 )
{
struct V_91 * V_47 , * V_117 ;
struct V_108 * V_109 , * V_118 ;
F_54 ( & V_2 -> V_114 ) ;
V_117 = NULL ;
for ( V_47 = V_2 -> V_115 ; V_47 ; V_47 = V_47 -> V_24 ) {
if ( F_9 ( & V_47 -> V_95 , V_116 ) )
break;
V_117 = V_47 ;
}
if ( V_47 ) {
if ( V_117 )
V_117 -> V_24 = V_47 -> V_24 ;
else
V_2 -> V_115 = V_47 -> V_24 ;
}
F_57 ( & V_2 -> V_114 ) ;
if ( V_47 ) {
for ( V_109 = V_47 -> V_110 ; V_109 ; V_109 = V_118 ) {
V_118 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
}
F_50 ( V_47 -> V_2 ) ;
F_51 ( V_47 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_91 * V_47 , * V_119 ;
F_54 ( & V_2 -> V_114 ) ;
V_47 = V_2 -> V_115 ;
V_2 -> V_115 = NULL ;
F_57 ( & V_2 -> V_114 ) ;
for (; V_47 ; V_47 = V_119 ) {
V_119 = V_47 -> V_24 ;
F_65 ( V_47 ) ;
F_50 ( V_47 -> V_2 ) ;
F_51 ( V_47 ) ;
}
F_30 ( & V_2 -> V_40 ) ;
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
struct V_108 * V_109 , * V_118 ;
F_54 ( & V_47 -> V_97 ) ;
V_109 = V_47 -> V_110 ;
V_47 -> V_110 = NULL ;
F_57 ( & V_47 -> V_97 ) ;
for (; V_109 ; V_109 = V_118 ) {
V_118 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
}
}
F_31 ( & V_2 -> V_40 ) ;
}
int F_17 ( struct V_12 * V_13 , const struct V_10 * V_11 )
{
struct V_91 * V_90 ;
struct V_1 * V_2 ;
V_2 = F_72 ( V_13 ) ;
if ( V_2 == NULL )
return - V_20 ;
F_73 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_41 ) {
F_74 ( & V_2 -> V_40 ) ;
F_50 ( V_2 ) ;
return - V_28 ;
}
for ( V_90 = V_2 -> V_120 ; V_90 ; V_90 = V_90 -> V_24 ) {
if ( F_9 ( & V_90 -> V_95 , V_11 ) ) {
V_90 -> V_121 ++ ;
F_74 ( & V_2 -> V_40 ) ;
F_35 ( V_2 , & V_90 -> V_95 , V_30 , 0 ,
NULL , 0 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
}
V_90 = F_67 ( sizeof( struct V_91 ) , V_71 ) ;
if ( V_90 == NULL ) {
F_74 ( & V_2 -> V_40 ) ;
F_50 ( V_2 ) ;
return - V_23 ;
}
F_75 ( & V_90 -> V_105 , V_122 , ( unsigned long ) V_90 ) ;
V_90 -> V_95 = * V_11 ;
V_90 -> V_2 = V_2 ;
V_90 -> V_121 = 1 ;
V_90 -> V_123 = V_90 -> V_124 = V_125 ;
F_76 ( & V_90 -> V_92 , 2 ) ;
F_68 ( & V_90 -> V_97 ) ;
V_90 -> V_107 = V_30 ;
V_90 -> V_126 [ V_30 ] = 1 ;
if ( F_77 ( & V_90 -> V_95 ) ||
F_53 ( & V_90 -> V_95 ) < V_96 )
V_90 -> V_98 |= V_102 ;
V_90 -> V_24 = V_2 -> V_120 ;
V_2 -> V_120 = V_90 ;
F_74 ( & V_2 -> V_40 ) ;
F_70 ( V_2 , & V_90 -> V_95 ) ;
F_52 ( V_90 ) ;
F_48 ( V_90 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
struct V_91 * V_127 , * * V_128 ;
F_73 ( & V_2 -> V_40 ) ;
for ( V_128 = & V_2 -> V_120 ; ( V_127 = * V_128 ) != NULL ; V_128 = & V_127 -> V_24 ) {
if ( F_9 ( & V_127 -> V_95 , V_11 ) ) {
if ( -- V_127 -> V_121 == 0 ) {
* V_128 = V_127 -> V_24 ;
F_74 ( & V_2 -> V_40 ) ;
F_60 ( V_127 ) ;
F_48 ( V_127 ) ;
return 0 ;
}
F_74 ( & V_2 -> V_40 ) ;
return 0 ;
}
}
F_74 ( & V_2 -> V_40 ) ;
return - V_129 ;
}
int F_78 ( struct V_12 * V_13 , const struct V_10 * V_11 )
{
struct V_1 * V_2 ;
int V_19 ;
F_7 () ;
V_2 = F_24 ( V_13 ) ;
if ( ! V_2 )
V_19 = - V_28 ;
else
V_19 = F_26 ( V_2 , V_11 ) ;
F_10 () ;
return V_19 ;
}
bool F_79 ( struct V_12 * V_13 , const struct V_10 * V_39 ,
const struct V_10 * V_89 )
{
struct V_1 * V_2 ;
struct V_91 * V_90 ;
bool V_53 = false ;
F_7 () ;
V_2 = F_24 ( V_13 ) ;
if ( V_2 ) {
F_30 ( & V_2 -> V_40 ) ;
for ( V_90 = V_2 -> V_120 ; V_90 ; V_90 = V_90 -> V_24 ) {
if ( F_9 ( & V_90 -> V_95 , V_39 ) )
break;
}
if ( V_90 ) {
if ( V_89 && ! F_80 ( V_89 ) ) {
struct V_108 * V_109 ;
F_54 ( & V_90 -> V_97 ) ;
for ( V_109 = V_90 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( F_9 ( & V_109 -> V_130 , V_89 ) )
break;
}
if ( V_109 )
V_53 = V_109 -> V_131 [ V_64 ] ||
V_109 -> V_131 [ V_30 ] !=
V_90 -> V_126 [ V_30 ] ;
else
V_53 = V_90 -> V_126 [ V_30 ] != 0 ;
F_57 ( & V_90 -> V_97 ) ;
} else
V_53 = true ;
}
F_31 ( & V_2 -> V_40 ) ;
}
F_10 () ;
return V_53 ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned long V_132 = F_82 () % V_2 -> V_133 ;
V_2 -> V_134 = 1 ;
if ( ! F_83 ( & V_2 -> V_135 , V_125 + V_132 + 2 ) )
F_69 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
V_2 -> V_134 = 0 ;
if ( F_63 ( & V_2 -> V_135 ) )
F_85 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 , unsigned long V_136 )
{
unsigned long V_132 = F_82 () % V_136 ;
if ( ! F_83 ( & V_2 -> V_137 , V_125 + V_132 + 2 ) )
F_69 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
V_2 -> V_138 = 0 ;
if ( F_63 ( & V_2 -> V_137 ) )
F_85 ( V_2 ) ;
}
static void F_88 ( struct V_1 * V_2 , unsigned long V_136 )
{
unsigned long V_132 = F_82 () % V_136 ;
if ( ! F_83 ( & V_2 -> V_139 , V_125 + V_132 + 2 ) )
F_69 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_63 ( & V_2 -> V_139 ) )
F_85 ( V_2 ) ;
}
static void F_90 ( struct V_91 * V_127 , unsigned long V_140 )
{
unsigned long V_136 = V_140 ;
if ( F_77 ( & V_127 -> V_95 ) ||
F_53 ( & V_127 -> V_95 ) < V_96 )
return;
if ( F_63 ( & V_127 -> V_105 ) ) {
F_64 ( & V_127 -> V_92 ) ;
V_136 = V_127 -> V_105 . V_141 - V_125 ;
}
if ( V_136 >= V_140 )
V_136 = F_82 () % V_140 ;
V_127 -> V_105 . V_141 = V_125 + V_136 ;
if ( ! F_83 ( & V_127 -> V_105 , V_125 + V_136 ) )
F_91 ( & V_127 -> V_92 ) ;
V_127 -> V_98 |= V_142 ;
}
static bool F_92 ( struct V_91 * V_47 , int V_143 ,
const struct V_10 * V_144 )
{
struct V_108 * V_109 ;
int V_51 , V_145 ;
V_145 = 0 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( V_145 == V_143 )
break;
for ( V_51 = 0 ; V_51 < V_143 ; V_51 ++ ) {
if ( V_109 -> V_131 [ V_64 ] ||
V_47 -> V_126 [ V_30 ] !=
V_109 -> V_131 [ V_30 ] )
break;
if ( F_9 ( & V_144 [ V_51 ] , & V_109 -> V_130 ) ) {
V_145 ++ ;
break;
}
}
}
V_47 -> V_98 &= ~ V_146 ;
if ( V_145 == V_143 )
return false ;
return true ;
}
static bool F_93 ( struct V_91 * V_47 , int V_143 ,
const struct V_10 * V_144 )
{
struct V_108 * V_109 ;
int V_51 , V_145 ;
if ( V_47 -> V_107 == V_30 )
return F_92 ( V_47 , V_143 , V_144 ) ;
V_145 = 0 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( V_145 == V_143 )
break;
for ( V_51 = 0 ; V_51 < V_143 ; V_51 ++ ) {
if ( F_9 ( & V_144 [ V_51 ] , & V_109 -> V_130 ) ) {
V_109 -> V_147 = 1 ;
V_145 ++ ;
break;
}
}
}
if ( ! V_145 ) {
V_47 -> V_98 &= ~ V_146 ;
return false ;
}
V_47 -> V_98 |= V_146 ;
return true ;
}
static int F_94 ( const struct V_1 * V_2 )
{
if ( F_95 ( V_2 -> V_13 ) -> V_148 . V_149 -> V_150 != 0 )
return F_95 ( V_2 -> V_13 ) -> V_148 . V_149 -> V_150 ;
else
return V_2 -> V_4 . V_150 ;
}
static bool F_96 ( const struct V_1 * V_2 )
{
return F_94 ( V_2 ) == 2 ;
}
static bool F_97 ( const struct V_1 * V_2 )
{
return F_94 ( V_2 ) == 1 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
if ( F_96 ( V_2 ) )
return false ;
if ( F_97 ( V_2 ) )
return true ;
if ( V_2 -> V_151 && F_98 ( V_125 , V_2 -> V_151 ) )
return true ;
return false ;
}
static void F_99 ( struct V_1 * V_2 )
{
unsigned long V_152 ;
V_152 = ( V_2 -> V_104 * V_2 -> V_153 ) + V_2 -> V_154 ;
V_2 -> V_151 = V_125 + V_152 ;
}
static void F_100 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
F_101 ( V_2 -> V_104 == 0 ) ;
if ( V_156 -> V_157 > 0 )
V_2 -> V_104 = V_156 -> V_157 ;
if ( F_102 ( V_2 -> V_104 < 2 ) ) {
F_103 ( L_1 ,
V_2 -> V_104 , V_158 ) ;
V_2 -> V_104 = V_158 ;
}
}
static void F_104 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
unsigned long V_159 ;
if ( V_156 -> V_160 < 128 ) {
V_159 = V_156 -> V_160 ;
} else {
unsigned long V_161 , V_162 ;
V_162 = F_105 ( V_156 -> V_160 ) ;
V_161 = F_106 ( V_156 -> V_160 ) ;
V_159 = ( V_161 | 0x10 ) << ( V_162 + 3 ) ;
}
V_2 -> V_153 = V_159 * V_163 ;
}
static void F_107 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
V_2 -> V_154 = F_108 ( F_109 ( V_156 ) ) ;
}
static int F_110 ( struct V_1 * V_2 , struct V_164 * V_165 ,
unsigned long * V_166 )
{
unsigned long V_167 ;
if ( F_96 ( V_2 ) )
return - V_20 ;
V_167 = F_111 ( V_165 -> V_168 ) ;
* V_166 = F_112 ( F_108 ( V_167 ) , 1UL ) ;
F_99 ( V_2 ) ;
F_84 ( V_2 ) ;
F_87 ( V_2 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , struct V_155 * V_165 ,
unsigned long * V_166 )
{
if ( F_2 ( V_2 ) )
return - V_20 ;
* V_166 = F_112 ( F_108 ( F_109 ( V_165 ) ) , 1UL ) ;
F_100 ( V_2 , V_165 ) ;
F_104 ( V_2 , V_165 ) ;
F_107 ( V_2 , V_165 ) ;
V_2 -> V_133 = * V_166 ;
return 0 ;
}
int F_114 ( struct V_169 * V_170 )
{
struct V_155 * V_156 = NULL ;
struct V_91 * V_127 ;
const struct V_10 * V_39 ;
unsigned long V_166 ;
struct V_1 * V_2 ;
struct V_164 * V_165 ;
int V_171 ;
int V_172 = 0 ;
int V_173 , V_19 ;
if ( ! F_115 ( V_170 , sizeof( struct V_10 ) ) )
return - V_20 ;
V_173 = F_111 ( F_116 ( V_170 ) -> V_174 ) + sizeof( struct V_175 ) ;
V_173 -= F_117 ( V_170 ) ;
if ( ! ( F_118 ( & F_116 ( V_170 ) -> V_176 ) & V_177 ) )
return - V_20 ;
V_2 = F_24 ( V_170 -> V_13 ) ;
if ( V_2 == NULL )
return 0 ;
V_165 = (struct V_164 * ) F_119 ( V_170 ) ;
V_39 = & V_165 -> V_178 ;
V_171 = F_118 ( V_39 ) ;
if ( V_171 != V_179 &&
! ( V_171 & V_180 ) )
return - V_20 ;
if ( V_173 == V_181 ) {
V_19 = F_110 ( V_2 , V_165 , & V_166 ) ;
if ( V_19 < 0 )
return V_19 ;
} else if ( V_173 >= V_182 ) {
int V_183 = sizeof( struct V_155 ) -
sizeof( struct V_184 ) ;
if ( ! F_115 ( V_170 , V_183 ) )
return - V_20 ;
V_156 = (struct V_155 * ) F_120 ( V_170 ) ;
V_19 = F_113 ( V_2 , V_156 , & V_166 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_171 == V_179 ) {
if ( V_156 -> V_185 )
return - V_20 ;
F_81 ( V_2 ) ;
return 0 ;
}
if ( V_156 -> V_185 != 0 ) {
if ( ! F_115 ( V_170 , V_183 +
F_111 ( V_156 -> V_185 ) * sizeof( struct V_10 ) ) )
return - V_20 ;
V_156 = (struct V_155 * ) F_120 ( V_170 ) ;
V_172 = 1 ;
}
} else
return - V_20 ;
F_30 ( & V_2 -> V_40 ) ;
if ( V_171 == V_179 ) {
for ( V_127 = V_2 -> V_120 ; V_127 ; V_127 = V_127 -> V_24 ) {
F_54 ( & V_127 -> V_97 ) ;
F_90 ( V_127 , V_166 ) ;
F_57 ( & V_127 -> V_97 ) ;
}
} else {
for ( V_127 = V_2 -> V_120 ; V_127 ; V_127 = V_127 -> V_24 ) {
if ( ! F_9 ( V_39 , & V_127 -> V_95 ) )
continue;
F_54 ( & V_127 -> V_97 ) ;
if ( V_127 -> V_98 & V_142 ) {
if ( ! V_172 )
V_127 -> V_98 &= ~ V_146 ;
} else {
if ( V_172 )
V_127 -> V_98 |= V_146 ;
else
V_127 -> V_98 &= ~ V_146 ;
}
if ( ! ( V_127 -> V_98 & V_146 ) ||
F_93 ( V_127 , F_111 ( V_156 -> V_185 ) , V_156 -> V_186 ) )
F_90 ( V_127 , V_166 ) ;
F_57 ( & V_127 -> V_97 ) ;
break;
}
}
F_31 ( & V_2 -> V_40 ) ;
return 0 ;
}
int F_121 ( struct V_169 * V_170 )
{
struct V_91 * V_127 ;
struct V_1 * V_2 ;
struct V_164 * V_165 ;
int V_187 ;
if ( V_170 -> V_188 == V_189 )
return 0 ;
if ( V_170 -> V_188 != V_190 &&
V_170 -> V_188 != V_191 )
return 0 ;
if ( ! F_115 ( V_170 , sizeof( * V_165 ) - sizeof( struct V_184 ) ) )
return - V_20 ;
V_165 = (struct V_164 * ) F_119 ( V_170 ) ;
V_187 = F_118 ( & F_116 ( V_170 ) -> V_176 ) ;
if ( V_187 != V_179 &&
! ( V_187 & V_177 ) )
return - V_20 ;
V_2 = F_24 ( V_170 -> V_13 ) ;
if ( V_2 == NULL )
return - V_28 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_127 = V_2 -> V_120 ; V_127 ; V_127 = V_127 -> V_24 ) {
if ( F_9 ( & V_127 -> V_95 , & V_165 -> V_178 ) ) {
F_18 ( & V_127 -> V_97 ) ;
if ( F_63 ( & V_127 -> V_105 ) )
F_64 ( & V_127 -> V_92 ) ;
V_127 -> V_98 &= ~ ( V_192 | V_142 ) ;
F_20 ( & V_127 -> V_97 ) ;
break;
}
}
F_31 ( & V_2 -> V_40 ) ;
return 0 ;
}
static bool F_122 ( struct V_91 * V_47 , struct V_108 * V_109 , int type ,
int V_193 , int V_194 )
{
switch ( type ) {
case V_195 :
case V_196 :
if ( V_193 || V_194 )
return false ;
if ( ! ( ( V_47 -> V_98 & V_146 ) && ! V_109 -> V_147 ) ) {
if ( V_47 -> V_107 == V_64 )
return true ;
if ( V_109 -> V_131 [ V_64 ] )
return type == V_195 ;
return V_47 -> V_126 [ V_30 ] ==
V_109 -> V_131 [ V_30 ] ;
}
return false ;
case V_197 :
if ( V_193 || V_194 )
return false ;
return V_109 -> V_131 [ V_64 ] != 0 ;
case V_198 :
if ( V_193 || V_194 )
return false ;
if ( V_47 -> V_126 [ V_30 ] == 0 ||
V_109 -> V_131 [ V_64 ] )
return false ;
return V_47 -> V_126 [ V_30 ] ==
V_109 -> V_131 [ V_30 ] ;
case V_199 :
if ( V_193 || ! V_109 -> V_113 )
return false ;
return ( V_47 -> V_107 == V_64 ) ^ V_194 ;
case V_200 :
if ( V_47 -> V_107 == V_64 )
return V_193 || ( V_109 -> V_113 && V_194 ) ;
return V_109 -> V_113 && ! V_193 && ! V_194 ;
}
return false ;
}
static int
F_123 ( struct V_91 * V_47 , int type , int V_193 , int V_194 )
{
struct V_108 * V_109 ;
int V_145 = 0 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( ! F_122 ( V_47 , V_109 , type , V_193 , V_194 ) )
continue;
V_145 ++ ;
}
return V_145 ;
}
static void F_124 ( struct V_7 * V_8 , struct V_169 * V_170 ,
struct V_12 * V_13 ,
const struct V_10 * V_176 ,
const struct V_10 * V_201 ,
int V_202 , int V_173 )
{
struct V_175 * V_203 ;
V_170 -> V_204 = F_125 ( V_205 ) ;
V_170 -> V_13 = V_13 ;
F_126 ( V_170 ) ;
F_127 ( V_170 , sizeof( struct V_175 ) ) ;
V_203 = F_116 ( V_170 ) ;
F_128 ( V_203 , 0 , 0 ) ;
V_203 -> V_174 = F_125 ( V_173 ) ;
V_203 -> V_206 = V_202 ;
V_203 -> V_207 = F_4 ( V_8 ) -> V_207 ;
V_203 -> V_176 = * V_176 ;
V_203 -> V_201 = * V_201 ;
}
static struct V_169 * F_129 ( struct V_1 * V_2 , int V_208 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_18 * V_18 = F_95 ( V_13 ) ;
struct V_7 * V_8 = V_18 -> V_148 . V_209 ;
struct V_169 * V_170 ;
struct V_210 * V_211 ;
struct V_10 V_212 ;
const struct V_10 * V_176 ;
int V_213 = F_130 ( V_13 ) ;
int V_214 = V_13 -> V_215 ;
int V_19 ;
T_3 V_216 [ 8 ] = { V_217 , 0 ,
V_218 , 2 , 0 , 0 ,
V_219 , 0 } ;
V_208 += V_213 + V_214 ;
V_208 = F_131 ( int , V_208 , F_132 ( 0 , 0 ) ) ;
V_170 = F_133 ( V_8 , V_208 , 1 , & V_19 ) ;
if ( ! V_170 )
return NULL ;
V_170 -> V_220 = V_221 ;
F_134 ( V_170 , V_213 ) ;
if ( F_135 ( V_2 , & V_212 , V_222 ) ) {
V_176 = & V_223 ;
} else
V_176 = & V_212 ;
F_124 ( V_8 , V_170 , V_13 , V_176 , & V_224 , V_225 , 0 ) ;
memcpy ( F_127 ( V_170 , sizeof( V_216 ) ) , V_216 , sizeof( V_216 ) ) ;
F_136 ( V_170 , F_137 ( V_170 ) - V_170 -> V_226 ) ;
F_127 ( V_170 , sizeof( * V_211 ) ) ;
V_211 = (struct V_210 * ) F_120 ( V_170 ) ;
V_211 -> V_227 = V_228 ;
V_211 -> V_229 = 0 ;
V_211 -> V_230 = 0 ;
V_211 -> V_231 = 0 ;
V_211 -> V_232 = 0 ;
return V_170 ;
}
static void F_138 ( struct V_169 * V_170 )
{
struct V_175 * V_233 = F_116 ( V_170 ) ;
struct V_210 * V_211 =
(struct V_210 * ) F_120 ( V_170 ) ;
int V_174 , V_234 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = F_95 ( V_170 -> V_13 ) ;
int V_19 ;
struct V_235 V_236 ;
struct V_237 * V_27 ;
F_7 () ;
V_2 = F_24 ( V_170 -> V_13 ) ;
F_139 ( V_18 , V_2 , V_238 , V_170 -> V_173 ) ;
V_174 = ( F_137 ( V_170 ) - F_140 ( V_170 ) ) -
sizeof( * V_233 ) ;
V_234 = F_137 ( V_170 ) - F_120 ( V_170 ) ;
V_233 -> V_174 = F_125 ( V_174 ) ;
V_211 -> V_230 = F_141 ( & V_233 -> V_176 , & V_233 -> V_201 , V_234 ,
V_217 ,
F_142 ( F_120 ( V_170 ) ,
V_234 , 0 ) ) ;
F_143 ( V_18 -> V_148 . V_209 , & V_236 , V_228 ,
& F_116 ( V_170 ) -> V_176 , & F_116 ( V_170 ) -> V_201 ,
V_170 -> V_13 -> V_9 ) ;
V_27 = F_144 ( V_170 -> V_13 , & V_236 ) ;
V_19 = 0 ;
if ( F_145 ( V_27 ) ) {
V_19 = F_146 ( V_27 ) ;
V_27 = NULL ;
}
F_147 ( V_170 , V_27 ) ;
if ( V_19 )
goto V_239;
V_174 = V_170 -> V_173 ;
V_19 = F_148 ( V_240 , V_241 , V_170 , NULL , V_170 -> V_13 ,
V_242 ) ;
V_243:
if ( ! V_19 ) {
F_149 ( V_18 , V_2 , V_228 ) ;
F_150 ( V_18 , V_2 , V_244 ) ;
F_151 ( V_18 , V_2 , V_245 , V_174 ) ;
} else
F_152 ( V_18 , V_2 , V_246 ) ;
F_10 () ;
return;
V_239:
F_153 ( V_170 ) ;
goto V_243;
}
static int F_154 ( struct V_91 * V_47 , int type , int V_247 , int V_248 )
{
return sizeof( struct V_249 ) + 16 * F_123 ( V_47 , type , V_247 , V_248 ) ;
}
static struct V_169 * F_155 ( struct V_169 * V_170 , struct V_91 * V_47 ,
int type , struct V_249 * * V_250 )
{
struct V_12 * V_13 = V_47 -> V_2 -> V_13 ;
struct V_210 * V_211 ;
struct V_249 * V_251 ;
if ( ! V_170 )
V_170 = F_129 ( V_47 -> V_2 , V_13 -> V_252 ) ;
if ( ! V_170 )
return NULL ;
V_251 = (struct V_249 * ) F_127 ( V_170 , sizeof( struct V_249 ) ) ;
V_251 -> V_253 = type ;
V_251 -> V_254 = 0 ;
V_251 -> V_255 = 0 ;
V_251 -> V_256 = V_47 -> V_95 ;
V_211 = (struct V_210 * ) F_120 ( V_170 ) ;
V_211 -> V_232 = F_125 ( F_111 ( V_211 -> V_232 ) + 1 ) ;
* V_250 = V_251 ;
return V_170 ;
}
static struct V_169 * F_156 ( struct V_169 * V_170 , struct V_91 * V_47 ,
int type , int V_193 , int V_194 , int V_257 )
{
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_210 * V_211 ;
struct V_249 * V_251 = NULL ;
struct V_108 * V_109 , * V_118 , * V_258 , * * V_259 ;
int V_145 , V_260 , V_261 , V_262 , V_263 ;
if ( V_47 -> V_98 & V_102 )
return V_170 ;
V_262 = type == V_195 ||
type == V_196 ;
V_263 = type == V_196 ||
type == V_198 ;
V_260 = V_145 = 0 ;
V_259 = V_194 ? & V_47 -> V_110 : & V_47 -> V_111 ;
if ( ! * V_259 )
goto V_264;
V_211 = V_170 ? (struct V_210 * ) F_120 ( V_170 ) : NULL ;
if ( V_263 ) {
if ( V_211 && V_211 -> V_232 &&
F_157 ( V_170 ) < F_154 ( V_47 , type , V_193 , V_194 ) ) {
if ( V_170 )
F_138 ( V_170 ) ;
V_170 = F_129 ( V_2 , V_13 -> V_252 ) ;
}
}
V_261 = 1 ;
V_258 = NULL ;
for ( V_109 = * V_259 ; V_109 ; V_109 = V_118 ) {
struct V_10 * V_265 ;
V_118 = V_109 -> V_112 ;
if ( ! F_122 ( V_47 , V_109 , type , V_193 , V_194 ) ) {
V_258 = V_109 ;
continue;
}
if ( V_262 )
V_109 -> V_147 = 0 ;
if ( F_157 ( V_170 ) < sizeof( * V_265 ) +
V_261 * sizeof( struct V_249 ) ) {
if ( V_263 && ! V_261 )
break;
if ( V_251 )
V_251 -> V_255 = F_125 ( V_145 ) ;
if ( V_170 )
F_138 ( V_170 ) ;
V_170 = F_129 ( V_2 , V_13 -> V_252 ) ;
V_261 = 1 ;
V_145 = 0 ;
}
if ( V_261 ) {
V_170 = F_155 ( V_170 , V_47 , type , & V_251 ) ;
V_261 = 0 ;
}
if ( ! V_170 )
return NULL ;
V_265 = (struct V_10 * ) F_127 ( V_170 , sizeof( * V_265 ) ) ;
* V_265 = V_109 -> V_130 ;
V_145 ++ ; V_260 ++ ;
if ( ( type == V_199 ||
type == V_200 ) && V_109 -> V_113 ) {
V_109 -> V_113 -- ;
if ( ( V_194 || V_193 ) && V_109 -> V_113 == 0 ) {
if ( V_258 )
V_258 -> V_112 = V_109 -> V_112 ;
else
* V_259 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
continue;
}
}
V_258 = V_109 ;
}
V_264:
if ( ! V_260 ) {
if ( type == V_199 ||
type == V_200 )
return V_170 ;
if ( V_47 -> V_103 || V_262 || V_257 ) {
if ( V_170 && F_157 ( V_170 ) < sizeof( struct V_249 ) ) {
F_138 ( V_170 ) ;
V_170 = NULL ;
}
V_170 = F_155 ( V_170 , V_47 , type , & V_251 ) ;
}
}
if ( V_251 )
V_251 -> V_255 = F_125 ( V_145 ) ;
if ( V_262 )
V_47 -> V_98 &= ~ V_146 ;
return V_170 ;
}
static void F_158 ( struct V_1 * V_2 , struct V_91 * V_47 )
{
struct V_169 * V_170 = NULL ;
int type ;
F_30 ( & V_2 -> V_40 ) ;
if ( ! V_47 ) {
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
if ( V_47 -> V_98 & V_102 )
continue;
F_54 ( & V_47 -> V_97 ) ;
if ( V_47 -> V_126 [ V_30 ] )
type = V_196 ;
else
type = V_195 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
F_57 ( & V_47 -> V_97 ) ;
}
} else {
F_54 ( & V_47 -> V_97 ) ;
if ( V_47 -> V_126 [ V_30 ] )
type = V_196 ;
else
type = V_195 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
F_57 ( & V_47 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
if ( V_170 )
F_138 ( V_170 ) ;
}
static void F_159 ( struct V_108 * * V_266 )
{
struct V_108 * V_258 , * V_118 , * V_109 ;
V_258 = NULL ;
for ( V_109 = * V_266 ; V_109 ; V_109 = V_118 ) {
V_118 = V_109 -> V_112 ;
if ( V_109 -> V_113 == 0 ) {
if ( V_258 )
V_258 -> V_112 = V_109 -> V_112 ;
else
* V_266 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
} else
V_258 = V_109 ;
}
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_91 * V_47 , * V_117 , * V_267 ;
struct V_169 * V_170 = NULL ;
int type , V_268 ;
F_30 ( & V_2 -> V_40 ) ;
F_18 ( & V_2 -> V_114 ) ;
V_117 = NULL ;
for ( V_47 = V_2 -> V_115 ; V_47 ; V_47 = V_267 ) {
V_267 = V_47 -> V_24 ;
if ( V_47 -> V_107 == V_64 ) {
type = V_200 ;
V_268 = V_200 ;
V_170 = F_156 ( V_170 , V_47 , type , 1 , 0 , 0 ) ;
V_170 = F_156 ( V_170 , V_47 , V_268 , 1 , 1 , 0 ) ;
}
if ( V_47 -> V_103 ) {
if ( V_47 -> V_107 == V_30 ) {
type = V_197 ;
V_170 = F_156 ( V_170 , V_47 , type , 1 , 0 , 0 ) ;
}
V_47 -> V_103 -- ;
if ( V_47 -> V_103 == 0 ) {
F_159 ( & V_47 -> V_110 ) ;
F_159 ( & V_47 -> V_111 ) ;
}
}
if ( V_47 -> V_103 == 0 && ! V_47 -> V_110 &&
! V_47 -> V_111 ) {
if ( V_117 )
V_117 -> V_24 = V_267 ;
else
V_2 -> V_115 = V_267 ;
F_50 ( V_47 -> V_2 ) ;
F_51 ( V_47 ) ;
} else
V_117 = V_47 ;
}
F_20 ( & V_2 -> V_114 ) ;
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
F_54 ( & V_47 -> V_97 ) ;
if ( V_47 -> V_126 [ V_30 ] ) {
type = V_200 ;
V_268 = V_199 ;
} else {
type = V_199 ;
V_268 = V_200 ;
}
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
V_170 = F_156 ( V_170 , V_47 , V_268 , 0 , 1 , 0 ) ;
if ( V_47 -> V_103 ) {
if ( V_47 -> V_107 == V_30 )
type = V_198 ;
else
type = V_197 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
V_47 -> V_103 -- ;
}
F_57 ( & V_47 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
if ( ! V_170 )
return;
( void ) F_138 ( V_170 ) ;
}
static void F_161 ( struct V_10 * V_11 , struct V_12 * V_13 , int type )
{
struct V_18 * V_18 = F_95 ( V_13 ) ;
struct V_7 * V_8 = V_18 -> V_148 . V_209 ;
struct V_1 * V_2 ;
struct V_169 * V_170 ;
struct V_164 * V_203 ;
const struct V_10 * V_269 , * V_176 ;
struct V_10 V_212 ;
int V_213 = F_130 ( V_13 ) ;
int V_214 = V_13 -> V_215 ;
int V_19 , V_173 , V_174 , V_270 ;
T_3 V_216 [ 8 ] = { V_217 , 0 ,
V_218 , 2 , 0 , 0 ,
V_219 , 0 } ;
struct V_235 V_236 ;
struct V_237 * V_27 ;
if ( type == V_271 )
V_269 = & V_272 ;
else
V_269 = V_11 ;
V_173 = sizeof( struct V_184 ) + sizeof( struct V_10 ) ;
V_174 = V_173 + sizeof( V_216 ) ;
V_270 = sizeof( struct V_175 ) + V_174 ;
F_7 () ;
F_139 ( V_18 , F_24 ( V_13 ) ,
V_238 , V_270 ) ;
F_10 () ;
V_170 = F_133 ( V_8 , V_213 + V_214 + V_270 , 1 , & V_19 ) ;
if ( V_170 == NULL ) {
F_7 () ;
F_162 ( V_18 , F_24 ( V_13 ) ,
V_246 ) ;
F_10 () ;
return;
}
V_170 -> V_220 = V_221 ;
F_134 ( V_170 , V_213 ) ;
if ( F_163 ( V_13 , & V_212 , V_222 ) ) {
V_176 = & V_223 ;
} else
V_176 = & V_212 ;
F_124 ( V_8 , V_170 , V_13 , V_176 , V_269 , V_225 , V_174 ) ;
memcpy ( F_127 ( V_170 , sizeof( V_216 ) ) , V_216 , sizeof( V_216 ) ) ;
V_203 = (struct V_164 * ) F_127 ( V_170 , sizeof( struct V_164 ) ) ;
memset ( V_203 , 0 , sizeof( struct V_164 ) ) ;
V_203 -> V_273 = type ;
V_203 -> V_178 = * V_11 ;
V_203 -> V_274 = F_141 ( V_176 , V_269 , V_173 ,
V_217 ,
F_142 ( V_203 , V_173 , 0 ) ) ;
F_7 () ;
V_2 = F_24 ( V_170 -> V_13 ) ;
F_143 ( V_8 , & V_236 , type ,
& F_116 ( V_170 ) -> V_176 , & F_116 ( V_170 ) -> V_201 ,
V_170 -> V_13 -> V_9 ) ;
V_27 = F_144 ( V_170 -> V_13 , & V_236 ) ;
if ( F_145 ( V_27 ) ) {
V_19 = F_146 ( V_27 ) ;
goto V_239;
}
F_147 ( V_170 , V_27 ) ;
V_19 = F_148 ( V_240 , V_241 , V_170 , NULL , V_170 -> V_13 ,
V_242 ) ;
V_243:
if ( ! V_19 ) {
F_164 ( V_18 , V_2 , type ) ;
F_165 ( V_18 , V_2 , V_244 ) ;
F_139 ( V_18 , V_2 , V_245 , V_270 ) ;
} else
F_162 ( V_18 , V_2 , V_246 ) ;
F_10 () ;
return;
V_239:
F_153 ( V_170 ) ;
goto V_243;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_169 * V_170 ;
struct V_91 * V_47 ;
int type ;
if ( F_2 ( V_2 ) )
return;
V_170 = NULL ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
F_54 ( & V_47 -> V_97 ) ;
if ( V_47 -> V_126 [ V_30 ] )
type = V_198 ;
else
type = V_197 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 1 ) ;
F_57 ( & V_47 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
if ( V_170 )
F_138 ( V_170 ) ;
}
void F_167 ( struct V_1 * V_2 )
{
V_2 -> V_275 = V_2 -> V_104 ;
if ( V_2 -> V_275 ) {
F_166 ( V_2 ) ;
V_2 -> V_275 -- ;
if ( V_2 -> V_275 )
F_88 ( V_2 , V_2 -> V_133 ) ;
}
}
static void F_168 ( unsigned long V_226 )
{
struct V_1 * V_2 = (struct V_1 * ) V_226 ;
F_166 ( V_2 ) ;
if ( V_2 -> V_275 ) {
V_2 -> V_275 -- ;
if ( V_2 -> V_275 )
F_88 ( V_2 , V_2 -> V_133 ) ;
}
F_50 ( V_2 ) ;
}
static int F_169 ( struct V_91 * V_47 , int V_29 ,
const struct V_10 * V_276 )
{
struct V_108 * V_109 , * V_258 ;
int V_53 = 0 ;
V_258 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( F_9 ( & V_109 -> V_130 , V_276 ) )
break;
V_258 = V_109 ;
}
if ( ! V_109 || V_109 -> V_131 [ V_29 ] == 0 ) {
return - V_277 ;
}
V_109 -> V_131 [ V_29 ] -- ;
if ( ! V_109 -> V_131 [ V_64 ] && ! V_109 -> V_131 [ V_30 ] ) {
struct V_1 * V_2 = V_47 -> V_2 ;
if ( V_258 )
V_258 -> V_112 = V_109 -> V_112 ;
else
V_47 -> V_111 = V_109 -> V_112 ;
if ( V_109 -> V_278 && ! ( V_47 -> V_98 & V_102 ) &&
! F_2 ( V_2 ) ) {
V_109 -> V_113 = V_2 -> V_104 ;
V_109 -> V_112 = V_47 -> V_110 ;
V_47 -> V_110 = V_109 ;
V_53 = 1 ;
} else
F_51 ( V_109 ) ;
}
return V_53 ;
}
static int F_36 ( struct V_1 * V_2 , const struct V_10 * V_116 ,
int V_29 , int V_279 , const struct V_10 * V_276 ,
int V_280 )
{
struct V_91 * V_47 ;
int V_281 = 0 ;
int V_51 , V_19 ;
if ( ! V_2 )
return - V_28 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
if ( F_9 ( V_116 , & V_47 -> V_95 ) )
break;
}
if ( ! V_47 ) {
F_31 ( & V_2 -> V_40 ) ;
return - V_277 ;
}
F_54 ( & V_47 -> V_97 ) ;
F_170 ( V_47 ) ;
if ( ! V_280 ) {
if ( ! V_47 -> V_126 [ V_29 ] ) {
F_57 ( & V_47 -> V_97 ) ;
F_31 ( & V_2 -> V_40 ) ;
return - V_20 ;
}
V_47 -> V_126 [ V_29 ] -- ;
}
V_19 = 0 ;
for ( V_51 = 0 ; V_51 < V_279 ; V_51 ++ ) {
int V_53 = F_169 ( V_47 , V_29 , & V_276 [ V_51 ] ) ;
V_281 |= V_53 > 0 ;
if ( ! V_19 && V_53 < 0 )
V_19 = V_53 ;
}
if ( V_47 -> V_107 == V_30 &&
V_47 -> V_126 [ V_30 ] == 0 &&
V_47 -> V_126 [ V_64 ] ) {
struct V_108 * V_109 ;
V_47 -> V_107 = V_64 ;
V_47 -> V_103 = V_2 -> V_104 ;
V_2 -> V_138 = V_47 -> V_103 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 )
V_109 -> V_113 = 0 ;
F_59 ( V_47 -> V_2 ) ;
} else if ( F_171 ( V_47 ) || V_281 )
F_59 ( V_47 -> V_2 ) ;
F_57 ( & V_47 -> V_97 ) ;
F_31 ( & V_2 -> V_40 ) ;
return V_19 ;
}
static int F_172 ( struct V_91 * V_47 , int V_29 ,
const struct V_10 * V_276 )
{
struct V_108 * V_109 , * V_258 ;
V_258 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( F_9 ( & V_109 -> V_130 , V_276 ) )
break;
V_258 = V_109 ;
}
if ( ! V_109 ) {
V_109 = F_67 ( sizeof( * V_109 ) , V_71 ) ;
if ( ! V_109 )
return - V_66 ;
V_109 -> V_130 = * V_276 ;
if ( V_258 ) {
V_258 -> V_112 = V_109 ;
} else
V_47 -> V_111 = V_109 ;
}
V_109 -> V_131 [ V_29 ] ++ ;
return 0 ;
}
static void F_170 ( struct V_91 * V_47 )
{
struct V_108 * V_109 ;
int V_282 = V_47 -> V_126 [ V_30 ] ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 )
if ( V_47 -> V_126 [ V_30 ] ) {
V_109 -> V_278 = V_282 ==
V_109 -> V_131 [ V_30 ] &&
! V_109 -> V_131 [ V_64 ] ;
} else
V_109 -> V_278 = V_109 -> V_131 [ V_64 ] != 0 ;
}
static int F_171 ( struct V_91 * V_47 )
{
struct V_108 * V_109 , * V_283 ;
int V_282 = V_47 -> V_126 [ V_30 ] ;
int V_284 = V_47 -> V_2 -> V_104 ;
int V_285 , V_53 ;
V_53 = 0 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( V_47 -> V_126 [ V_30 ] ) {
V_285 = V_282 == V_109 -> V_131 [ V_30 ] &&
! V_109 -> V_131 [ V_64 ] ;
} else
V_285 = V_109 -> V_131 [ V_64 ] != 0 ;
if ( V_285 ) {
if ( ! V_109 -> V_278 ) {
struct V_108 * V_286 = NULL ;
for ( V_283 = V_47 -> V_110 ; V_283 ;
V_283 = V_283 -> V_112 ) {
if ( F_9 ( & V_283 -> V_130 ,
& V_109 -> V_130 ) )
break;
V_286 = V_283 ;
}
if ( V_283 ) {
if ( V_286 )
V_286 -> V_112 = V_283 -> V_112 ;
else
V_47 -> V_110 = V_283 -> V_112 ;
F_51 ( V_283 ) ;
}
V_109 -> V_113 = V_284 ;
V_53 ++ ;
}
} else if ( V_109 -> V_278 ) {
V_109 -> V_113 = 0 ;
for ( V_283 = V_47 -> V_110 ; V_283 ; V_283 = V_283 -> V_112 )
if ( F_9 ( & V_283 -> V_130 ,
& V_109 -> V_130 ) )
break;
if ( ! V_283 ) {
V_283 = F_173 ( sizeof( * V_283 ) , V_71 ) ;
if ( ! V_283 )
continue;
* V_283 = * V_109 ;
V_283 -> V_112 = V_47 -> V_110 ;
V_47 -> V_110 = V_283 ;
}
V_283 -> V_113 = V_284 ;
V_53 ++ ;
}
}
return V_53 ;
}
static int F_35 ( struct V_1 * V_2 , const struct V_10 * V_116 ,
int V_29 , int V_279 , const struct V_10 * V_276 ,
int V_280 )
{
struct V_91 * V_47 ;
int V_287 ;
int V_51 , V_19 ;
if ( ! V_2 )
return - V_28 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
if ( F_9 ( V_116 , & V_47 -> V_95 ) )
break;
}
if ( ! V_47 ) {
F_31 ( & V_2 -> V_40 ) ;
return - V_277 ;
}
F_54 ( & V_47 -> V_97 ) ;
F_170 ( V_47 ) ;
V_287 = V_47 -> V_107 == V_30 ;
if ( ! V_280 )
V_47 -> V_126 [ V_29 ] ++ ;
V_19 = 0 ;
for ( V_51 = 0 ; V_51 < V_279 ; V_51 ++ ) {
V_19 = F_172 ( V_47 , V_29 , & V_276 [ V_51 ] ) ;
if ( V_19 )
break;
}
if ( V_19 ) {
int V_52 ;
if ( ! V_280 )
V_47 -> V_126 [ V_29 ] -- ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ )
F_169 ( V_47 , V_29 , & V_276 [ V_52 ] ) ;
} else if ( V_287 != ( V_47 -> V_126 [ V_30 ] != 0 ) ) {
struct V_108 * V_109 ;
if ( V_47 -> V_126 [ V_30 ] )
V_47 -> V_107 = V_30 ;
else if ( V_47 -> V_126 [ V_64 ] )
V_47 -> V_107 = V_64 ;
V_47 -> V_103 = V_2 -> V_104 ;
V_2 -> V_138 = V_47 -> V_103 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 )
V_109 -> V_113 = 0 ;
F_59 ( V_2 ) ;
} else if ( F_171 ( V_47 ) )
F_59 ( V_2 ) ;
F_57 ( & V_47 -> V_97 ) ;
F_31 ( & V_2 -> V_40 ) ;
return V_19 ;
}
static void F_65 ( struct V_91 * V_47 )
{
struct V_108 * V_109 , * V_288 ;
for ( V_109 = V_47 -> V_110 ; V_109 ; V_109 = V_288 ) {
V_288 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
}
V_47 -> V_110 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_288 ) {
V_288 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
}
V_47 -> V_111 = NULL ;
V_47 -> V_107 = V_30 ;
V_47 -> V_126 [ V_64 ] = 0 ;
V_47 -> V_126 [ V_30 ] = 1 ;
}
static void F_58 ( struct V_91 * V_127 )
{
unsigned long V_136 ;
if ( V_127 -> V_98 & V_102 )
return;
F_161 ( & V_127 -> V_95 , V_127 -> V_2 -> V_13 , V_289 ) ;
V_136 = F_82 () % F_1 ( V_127 -> V_2 ) ;
F_54 ( & V_127 -> V_97 ) ;
if ( F_63 ( & V_127 -> V_105 ) ) {
F_64 ( & V_127 -> V_92 ) ;
V_136 = V_127 -> V_105 . V_141 - V_125 ;
}
if ( ! F_83 ( & V_127 -> V_105 , V_125 + V_136 ) )
F_91 ( & V_127 -> V_92 ) ;
V_127 -> V_98 |= V_142 | V_192 ;
F_57 ( & V_127 -> V_97 ) ;
}
static int F_25 ( struct V_7 * V_8 , struct V_14 * V_290 ,
struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_290 -> V_32 ) {
return F_36 ( V_2 , & V_290 -> V_11 , V_290 -> V_29 , 0 , NULL , 0 ) ;
}
V_19 = F_36 ( V_2 , & V_290 -> V_11 , V_290 -> V_29 ,
V_290 -> V_32 -> V_62 , V_290 -> V_32 -> V_63 , 0 ) ;
F_15 ( V_8 , V_290 -> V_32 , F_38 ( V_290 -> V_32 -> V_67 ) ) ;
V_290 -> V_32 = NULL ;
return V_19 ;
}
static void F_62 ( struct V_91 * V_127 )
{
if ( F_2 ( V_127 -> V_2 ) ) {
if ( V_127 -> V_98 & V_192 )
F_161 ( & V_127 -> V_95 , V_127 -> V_2 -> V_13 ,
V_271 ) ;
} else {
F_66 ( V_127 -> V_2 , V_127 ) ;
F_59 ( V_127 -> V_2 ) ;
}
}
static void F_174 ( unsigned long V_226 )
{
struct V_1 * V_2 = (struct V_1 * ) V_226 ;
V_2 -> V_134 = 0 ;
F_158 ( V_2 , NULL ) ;
F_50 ( V_2 ) ;
}
static void F_175 ( unsigned long V_226 )
{
struct V_1 * V_2 = (struct V_1 * ) V_226 ;
F_160 ( V_2 ) ;
if ( V_2 -> V_138 ) {
V_2 -> V_138 -- ;
if ( V_2 -> V_138 )
F_86 ( V_2 , V_2 -> V_133 ) ;
}
F_50 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return;
V_2 -> V_138 = V_2 -> V_104 ;
F_86 ( V_2 , 1 ) ;
}
static void V_122 ( unsigned long V_226 )
{
struct V_91 * V_127 = (struct V_91 * ) V_226 ;
if ( F_2 ( V_127 -> V_2 ) )
F_161 ( & V_127 -> V_95 , V_127 -> V_2 -> V_13 , V_289 ) ;
else
F_158 ( V_127 -> V_2 , V_127 ) ;
F_18 ( & V_127 -> V_97 ) ;
V_127 -> V_98 |= V_192 ;
V_127 -> V_98 &= ~ V_142 ;
F_20 ( & V_127 -> V_97 ) ;
F_48 ( V_127 ) ;
}
void F_176 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_51 = V_2 -> V_120 ; V_51 ; V_51 = V_51 -> V_24 )
F_60 ( V_51 ) ;
F_31 ( & V_2 -> V_40 ) ;
}
void F_177 ( struct V_1 * V_2 )
{
F_178 ( V_2 ) ;
}
void F_179 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_30 ( & V_2 -> V_40 ) ;
F_87 ( V_2 ) ;
F_84 ( V_2 ) ;
F_89 ( V_2 ) ;
for ( V_51 = V_2 -> V_120 ; V_51 ; V_51 = V_51 -> V_24 )
F_60 ( V_51 ) ;
F_31 ( & V_2 -> V_40 ) ;
F_71 ( V_2 ) ;
}
void F_178 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_51 = V_2 -> V_120 ; V_51 ; V_51 = V_51 -> V_24 )
F_52 ( V_51 ) ;
F_31 ( & V_2 -> V_40 ) ;
}
void F_180 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_40 ) ;
F_68 ( & V_2 -> V_114 ) ;
V_2 -> V_134 = 0 ;
F_75 ( & V_2 -> V_135 , F_174 ,
( unsigned long ) V_2 ) ;
V_2 -> V_115 = NULL ;
V_2 -> V_138 = 0 ;
F_75 ( & V_2 -> V_137 , F_175 ,
( unsigned long ) V_2 ) ;
F_75 ( & V_2 -> V_139 , F_168 ,
( unsigned long ) V_2 ) ;
V_2 -> V_104 = V_158 ;
V_2 -> V_153 = V_291 ;
V_2 -> V_154 = V_292 ;
V_2 -> V_133 = F_1 ( V_2 ) ;
V_2 -> V_151 = 0 ;
F_74 ( & V_2 -> V_40 ) ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_179 ( V_2 ) ;
F_26 ( V_2 , & V_293 ) ;
if ( V_2 -> V_4 . V_294 )
F_26 ( V_2 , & V_272 ) ;
F_73 ( & V_2 -> V_40 ) ;
while ( ( V_51 = V_2 -> V_120 ) != NULL ) {
V_2 -> V_120 = V_51 -> V_24 ;
F_74 ( & V_2 -> V_40 ) ;
F_60 ( V_51 ) ;
F_48 ( V_51 ) ;
F_73 ( & V_2 -> V_40 ) ;
}
F_74 ( & V_2 -> V_40 ) ;
}
static inline struct V_91 * F_182 ( struct V_295 * V_296 )
{
struct V_91 * V_106 = NULL ;
struct V_297 * V_298 = F_183 ( V_296 ) ;
struct V_18 * V_18 = F_184 ( V_296 ) ;
V_298 -> V_2 = NULL ;
F_185 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_24 ( V_298 -> V_13 ) ;
if ( ! V_2 )
continue;
F_30 ( & V_2 -> V_40 ) ;
V_106 = V_2 -> V_120 ;
if ( V_106 ) {
V_298 -> V_2 = V_2 ;
break;
}
F_31 ( & V_2 -> V_40 ) ;
}
return V_106 ;
}
static struct V_91 * F_186 ( struct V_295 * V_296 , struct V_91 * V_106 )
{
struct V_297 * V_298 = F_183 ( V_296 ) ;
V_106 = V_106 -> V_24 ;
while ( ! V_106 ) {
if ( F_187 ( V_298 -> V_2 != NULL ) )
F_31 ( & V_298 -> V_2 -> V_40 ) ;
V_298 -> V_13 = F_188 ( V_298 -> V_13 ) ;
if ( ! V_298 -> V_13 ) {
V_298 -> V_2 = NULL ;
break;
}
V_298 -> V_2 = F_24 ( V_298 -> V_13 ) ;
if ( ! V_298 -> V_2 )
continue;
F_30 ( & V_298 -> V_2 -> V_40 ) ;
V_106 = V_298 -> V_2 -> V_120 ;
}
return V_106 ;
}
static struct V_91 * F_189 ( struct V_295 * V_296 , T_4 V_299 )
{
struct V_91 * V_106 = F_182 ( V_296 ) ;
if ( V_106 )
while ( V_299 && ( V_106 = F_186 ( V_296 , V_106 ) ) != NULL )
-- V_299 ;
return V_299 ? NULL : V_106 ;
}
static void * F_190 ( struct V_295 * V_296 , T_4 * V_299 )
__acquires( T_5 )
{
F_7 () ;
return F_189 ( V_296 , * V_299 ) ;
}
static void * F_191 ( struct V_295 * V_296 , void * V_300 , T_4 * V_299 )
{
struct V_91 * V_106 = F_186 ( V_296 , V_300 ) ;
++ * V_299 ;
return V_106 ;
}
static void F_192 ( struct V_295 * V_296 , void * V_300 )
__releases( T_5 )
{
struct V_297 * V_298 = F_183 ( V_296 ) ;
if ( F_187 ( V_298 -> V_2 != NULL ) ) {
F_31 ( & V_298 -> V_2 -> V_40 ) ;
V_298 -> V_2 = NULL ;
}
V_298 -> V_13 = NULL ;
F_10 () ;
}
static int F_193 ( struct V_295 * V_296 , void * V_300 )
{
struct V_91 * V_106 = (struct V_91 * ) V_300 ;
struct V_297 * V_298 = F_183 ( V_296 ) ;
F_194 ( V_296 ,
L_2 ,
V_298 -> V_13 -> V_9 , V_298 -> V_13 -> V_301 ,
& V_106 -> V_95 ,
V_106 -> V_121 , V_106 -> V_98 ,
( V_106 -> V_98 & V_142 ) ?
F_195 ( V_106 -> V_105 . V_141 - V_125 ) : 0 ) ;
return 0 ;
}
static int F_196 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
return F_197 ( V_302 , V_303 , & V_304 ,
sizeof( struct V_297 ) ) ;
}
static inline struct V_108 * F_198 ( struct V_295 * V_296 )
{
struct V_108 * V_109 = NULL ;
struct V_91 * V_106 = NULL ;
struct V_305 * V_298 = F_199 ( V_296 ) ;
struct V_18 * V_18 = F_184 ( V_296 ) ;
V_298 -> V_2 = NULL ;
V_298 -> V_106 = NULL ;
F_185 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_24 ( V_298 -> V_13 ) ;
if ( F_102 ( V_2 == NULL ) )
continue;
F_30 ( & V_2 -> V_40 ) ;
V_106 = V_2 -> V_120 ;
if ( F_187 ( V_106 != NULL ) ) {
F_54 ( & V_106 -> V_97 ) ;
V_109 = V_106 -> V_111 ;
if ( F_187 ( V_109 != NULL ) ) {
V_298 -> V_106 = V_106 ;
V_298 -> V_2 = V_2 ;
break;
}
F_57 ( & V_106 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
}
return V_109 ;
}
static struct V_108 * F_200 ( struct V_295 * V_296 , struct V_108 * V_109 )
{
struct V_305 * V_298 = F_199 ( V_296 ) ;
V_109 = V_109 -> V_112 ;
while ( ! V_109 ) {
F_57 ( & V_298 -> V_106 -> V_97 ) ;
V_298 -> V_106 = V_298 -> V_106 -> V_24 ;
while ( ! V_298 -> V_106 ) {
if ( F_187 ( V_298 -> V_2 != NULL ) )
F_31 ( & V_298 -> V_2 -> V_40 ) ;
V_298 -> V_13 = F_188 ( V_298 -> V_13 ) ;
if ( ! V_298 -> V_13 ) {
V_298 -> V_2 = NULL ;
goto V_243;
}
V_298 -> V_2 = F_24 ( V_298 -> V_13 ) ;
if ( ! V_298 -> V_2 )
continue;
F_30 ( & V_298 -> V_2 -> V_40 ) ;
V_298 -> V_106 = V_298 -> V_2 -> V_120 ;
}
if ( ! V_298 -> V_106 )
break;
F_54 ( & V_298 -> V_106 -> V_97 ) ;
V_109 = V_298 -> V_106 -> V_111 ;
}
V_243:
return V_109 ;
}
static struct V_108 * F_201 ( struct V_295 * V_296 , T_4 V_299 )
{
struct V_108 * V_109 = F_198 ( V_296 ) ;
if ( V_109 )
while ( V_299 && ( V_109 = F_200 ( V_296 , V_109 ) ) != NULL )
-- V_299 ;
return V_299 ? NULL : V_109 ;
}
static void * F_202 ( struct V_295 * V_296 , T_4 * V_299 )
__acquires( T_5 )
{
F_7 () ;
return * V_299 ? F_201 ( V_296 , * V_299 - 1 ) : V_306 ;
}
static void * F_203 ( struct V_295 * V_296 , void * V_300 , T_4 * V_299 )
{
struct V_108 * V_109 ;
if ( V_300 == V_306 )
V_109 = F_198 ( V_296 ) ;
else
V_109 = F_200 ( V_296 , V_300 ) ;
++ * V_299 ;
return V_109 ;
}
static void F_204 ( struct V_295 * V_296 , void * V_300 )
__releases( T_5 )
{
struct V_305 * V_298 = F_199 ( V_296 ) ;
if ( F_187 ( V_298 -> V_106 != NULL ) ) {
F_57 ( & V_298 -> V_106 -> V_97 ) ;
V_298 -> V_106 = NULL ;
}
if ( F_187 ( V_298 -> V_2 != NULL ) ) {
F_31 ( & V_298 -> V_2 -> V_40 ) ;
V_298 -> V_2 = NULL ;
}
V_298 -> V_13 = NULL ;
F_10 () ;
}
static int F_205 ( struct V_295 * V_296 , void * V_300 )
{
struct V_108 * V_109 = (struct V_108 * ) V_300 ;
struct V_305 * V_298 = F_199 ( V_296 ) ;
if ( V_300 == V_306 ) {
F_194 ( V_296 ,
L_3
L_4 , L_5 ,
L_6 , L_7 ,
L_8 , L_9 , L_10 ) ;
} else {
F_194 ( V_296 ,
L_11 ,
V_298 -> V_13 -> V_9 , V_298 -> V_13 -> V_301 ,
& V_298 -> V_106 -> V_95 ,
& V_109 -> V_130 ,
V_109 -> V_131 [ V_64 ] ,
V_109 -> V_131 [ V_30 ] ) ;
}
return 0 ;
}
static int F_206 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
return F_197 ( V_302 , V_303 , & V_307 ,
sizeof( struct V_305 ) ) ;
}
static int T_6 F_207 ( struct V_18 * V_18 )
{
int V_19 ;
V_19 = - V_23 ;
if ( ! F_208 ( L_12 , V_308 , V_18 -> V_309 , & V_310 ) )
goto V_243;
if ( ! F_208 ( L_13 , V_308 , V_18 -> V_309 ,
& V_311 ) )
goto V_312;
V_19 = 0 ;
V_243:
return V_19 ;
V_312:
F_209 ( L_12 , V_18 -> V_309 ) ;
goto V_243;
}
static void T_7 F_210 ( struct V_18 * V_18 )
{
F_209 ( L_13 , V_18 -> V_309 ) ;
F_209 ( L_12 , V_18 -> V_309 ) ;
}
static inline int F_207 ( struct V_18 * V_18 )
{
return 0 ;
}
static inline void F_210 ( struct V_18 * V_18 )
{
}
static int T_6 F_211 ( struct V_18 * V_18 )
{
int V_19 ;
V_19 = F_212 ( & V_18 -> V_148 . V_209 , V_313 ,
V_314 , V_217 , V_18 ) ;
if ( V_19 < 0 ) {
F_213 ( L_14 ,
V_19 ) ;
goto V_243;
}
F_4 ( V_18 -> V_148 . V_209 ) -> V_207 = 1 ;
V_19 = F_207 ( V_18 ) ;
if ( V_19 )
goto V_315;
V_243:
return V_19 ;
V_315:
F_214 ( V_18 -> V_148 . V_209 ) ;
goto V_243;
}
static void T_7 F_215 ( struct V_18 * V_18 )
{
F_214 ( V_18 -> V_148 . V_209 ) ;
F_210 ( V_18 ) ;
}
int T_8 F_216 ( void )
{
return F_217 ( & V_316 ) ;
}
void F_218 ( void )
{
F_219 ( & V_316 ) ;
}
