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
if ( ! ( F_118 ( & F_116 ( V_170 ) -> V_176 ) & V_177 ) ||
F_116 ( V_170 ) -> V_178 != 1 ||
! ( F_119 ( V_170 ) -> V_100 & V_179 ) ||
F_119 ( V_170 ) -> V_180 != F_120 ( V_181 ) )
return - V_20 ;
V_2 = F_24 ( V_170 -> V_13 ) ;
if ( V_2 == NULL )
return 0 ;
V_165 = (struct V_164 * ) F_121 ( V_170 ) ;
V_39 = & V_165 -> V_182 ;
V_171 = F_118 ( V_39 ) ;
if ( V_171 != V_183 &&
! ( V_171 & V_184 ) )
return - V_20 ;
if ( V_173 == V_185 ) {
V_19 = F_110 ( V_2 , V_165 , & V_166 ) ;
if ( V_19 < 0 )
return V_19 ;
} else if ( V_173 >= V_186 ) {
int V_187 = sizeof( struct V_155 ) -
sizeof( struct V_188 ) ;
if ( ! F_115 ( V_170 , V_187 ) )
return - V_20 ;
V_156 = (struct V_155 * ) F_122 ( V_170 ) ;
V_19 = F_113 ( V_2 , V_156 , & V_166 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_171 == V_183 ) {
if ( V_156 -> V_189 )
return - V_20 ;
F_81 ( V_2 ) ;
return 0 ;
}
if ( V_156 -> V_189 != 0 ) {
if ( ! F_115 ( V_170 , V_187 +
F_111 ( V_156 -> V_189 ) * sizeof( struct V_10 ) ) )
return - V_20 ;
V_156 = (struct V_155 * ) F_122 ( V_170 ) ;
V_172 = 1 ;
}
} else
return - V_20 ;
F_30 ( & V_2 -> V_40 ) ;
if ( V_171 == V_183 ) {
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
F_93 ( V_127 , F_111 ( V_156 -> V_189 ) , V_156 -> V_190 ) )
F_90 ( V_127 , V_166 ) ;
F_57 ( & V_127 -> V_97 ) ;
break;
}
}
F_31 ( & V_2 -> V_40 ) ;
return 0 ;
}
int F_123 ( struct V_169 * V_170 )
{
struct V_91 * V_127 ;
struct V_1 * V_2 ;
struct V_164 * V_165 ;
int V_191 ;
if ( V_170 -> V_192 == V_193 )
return 0 ;
if ( V_170 -> V_192 != V_194 &&
V_170 -> V_192 != V_195 )
return 0 ;
if ( ! F_115 ( V_170 , sizeof( * V_165 ) - sizeof( struct V_188 ) ) )
return - V_20 ;
V_165 = (struct V_164 * ) F_121 ( V_170 ) ;
V_191 = F_118 ( & F_116 ( V_170 ) -> V_176 ) ;
if ( V_191 != V_183 &&
! ( V_191 & V_177 ) )
return - V_20 ;
V_2 = F_24 ( V_170 -> V_13 ) ;
if ( V_2 == NULL )
return - V_28 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_127 = V_2 -> V_120 ; V_127 ; V_127 = V_127 -> V_24 ) {
if ( F_9 ( & V_127 -> V_95 , & V_165 -> V_182 ) ) {
F_18 ( & V_127 -> V_97 ) ;
if ( F_63 ( & V_127 -> V_105 ) )
F_64 ( & V_127 -> V_92 ) ;
V_127 -> V_98 &= ~ ( V_196 | V_142 ) ;
F_20 ( & V_127 -> V_97 ) ;
break;
}
}
F_31 ( & V_2 -> V_40 ) ;
return 0 ;
}
static bool F_124 ( struct V_91 * V_47 , struct V_108 * V_109 , int type ,
int V_197 , int V_198 )
{
switch ( type ) {
case V_199 :
case V_200 :
if ( V_197 || V_198 )
return false ;
if ( ! ( ( V_47 -> V_98 & V_146 ) && ! V_109 -> V_147 ) ) {
if ( V_47 -> V_107 == V_64 )
return true ;
if ( V_109 -> V_131 [ V_64 ] )
return type == V_199 ;
return V_47 -> V_126 [ V_30 ] ==
V_109 -> V_131 [ V_30 ] ;
}
return false ;
case V_201 :
if ( V_197 || V_198 )
return false ;
return V_109 -> V_131 [ V_64 ] != 0 ;
case V_202 :
if ( V_197 || V_198 )
return false ;
if ( V_47 -> V_126 [ V_30 ] == 0 ||
V_109 -> V_131 [ V_64 ] )
return false ;
return V_47 -> V_126 [ V_30 ] ==
V_109 -> V_131 [ V_30 ] ;
case V_203 :
if ( V_197 || ! V_109 -> V_113 )
return false ;
return ( V_47 -> V_107 == V_64 ) ^ V_198 ;
case V_204 :
if ( V_47 -> V_107 == V_64 )
return V_197 || ( V_109 -> V_113 && V_198 ) ;
return V_109 -> V_113 && ! V_197 && ! V_198 ;
}
return false ;
}
static int
F_125 ( struct V_91 * V_47 , int type , int V_197 , int V_198 )
{
struct V_108 * V_109 ;
int V_145 = 0 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( ! F_124 ( V_47 , V_109 , type , V_197 , V_198 ) )
continue;
V_145 ++ ;
}
return V_145 ;
}
static void F_126 ( struct V_7 * V_8 , struct V_169 * V_170 ,
struct V_12 * V_13 ,
const struct V_10 * V_176 ,
const struct V_10 * V_205 ,
int V_206 , int V_173 )
{
struct V_175 * V_207 ;
V_170 -> V_208 = F_120 ( V_209 ) ;
V_170 -> V_13 = V_13 ;
F_127 ( V_170 ) ;
F_128 ( V_170 , sizeof( struct V_175 ) ) ;
V_207 = F_116 ( V_170 ) ;
F_129 ( V_207 , 0 , 0 ) ;
V_207 -> V_174 = F_120 ( V_173 ) ;
V_207 -> V_210 = V_206 ;
V_207 -> V_178 = F_4 ( V_8 ) -> V_178 ;
V_207 -> V_176 = * V_176 ;
V_207 -> V_205 = * V_205 ;
}
static struct V_169 * F_130 ( struct V_1 * V_2 , int V_211 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_18 * V_18 = F_95 ( V_13 ) ;
struct V_7 * V_8 = V_18 -> V_148 . V_212 ;
struct V_169 * V_170 ;
struct V_213 * V_214 ;
struct V_10 V_215 ;
const struct V_10 * V_176 ;
int V_216 = F_131 ( V_13 ) ;
int V_217 = V_13 -> V_218 ;
int V_19 ;
T_3 V_180 [ 8 ] = { V_219 , 0 ,
V_220 , 2 , 0 , 0 ,
V_221 , 0 } ;
V_211 += V_216 + V_217 ;
V_211 = F_132 ( int , V_211 , F_133 ( 0 , 0 ) ) ;
V_170 = F_134 ( V_8 , V_211 , 1 , & V_19 ) ;
if ( ! V_170 )
return NULL ;
V_170 -> V_222 = V_223 ;
F_135 ( V_170 , V_216 ) ;
if ( F_136 ( V_2 , & V_215 , V_224 ) ) {
V_176 = & V_225 ;
} else
V_176 = & V_215 ;
F_126 ( V_8 , V_170 , V_13 , V_176 , & V_226 , V_227 , 0 ) ;
memcpy ( F_128 ( V_170 , sizeof( V_180 ) ) , V_180 , sizeof( V_180 ) ) ;
F_137 ( V_170 , F_138 ( V_170 ) - V_170 -> V_228 ) ;
F_128 ( V_170 , sizeof( * V_214 ) ) ;
V_214 = (struct V_213 * ) F_122 ( V_170 ) ;
V_214 -> V_229 = V_230 ;
V_214 -> V_231 = 0 ;
V_214 -> V_232 = 0 ;
V_214 -> V_233 = 0 ;
V_214 -> V_234 = 0 ;
return V_170 ;
}
static void F_139 ( struct V_169 * V_170 )
{
struct V_175 * V_235 = F_116 ( V_170 ) ;
struct V_213 * V_214 =
(struct V_213 * ) F_122 ( V_170 ) ;
int V_174 , V_236 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = F_95 ( V_170 -> V_13 ) ;
int V_19 ;
struct V_237 V_238 ;
struct V_239 * V_27 ;
F_7 () ;
V_2 = F_24 ( V_170 -> V_13 ) ;
F_140 ( V_18 , V_2 , V_240 , V_170 -> V_173 ) ;
V_174 = ( F_138 ( V_170 ) - F_141 ( V_170 ) ) -
sizeof( * V_235 ) ;
V_236 = F_138 ( V_170 ) - F_122 ( V_170 ) ;
V_235 -> V_174 = F_120 ( V_174 ) ;
V_214 -> V_232 = F_142 ( & V_235 -> V_176 , & V_235 -> V_205 , V_236 ,
V_219 ,
F_143 ( F_122 ( V_170 ) ,
V_236 , 0 ) ) ;
F_144 ( V_18 -> V_148 . V_212 , & V_238 , V_230 ,
& F_116 ( V_170 ) -> V_176 , & F_116 ( V_170 ) -> V_205 ,
V_170 -> V_13 -> V_9 ) ;
V_27 = F_145 ( V_170 -> V_13 , & V_238 ) ;
V_19 = 0 ;
if ( F_146 ( V_27 ) ) {
V_19 = F_147 ( V_27 ) ;
V_27 = NULL ;
}
F_148 ( V_170 , V_27 ) ;
if ( V_19 )
goto V_241;
V_174 = V_170 -> V_173 ;
V_19 = F_149 ( V_242 , V_243 , V_170 , NULL , V_170 -> V_13 ,
V_244 ) ;
V_245:
if ( ! V_19 ) {
F_150 ( V_18 , V_2 , V_230 ) ;
F_151 ( V_18 , V_2 , V_246 ) ;
F_140 ( V_18 , V_2 , V_247 , V_174 ) ;
} else {
F_152 ( V_18 , V_2 , V_248 ) ;
}
F_10 () ;
return;
V_241:
F_153 ( V_170 ) ;
goto V_245;
}
static int F_154 ( struct V_91 * V_47 , int type , int V_249 , int V_250 )
{
return sizeof( struct V_251 ) + 16 * F_125 ( V_47 , type , V_249 , V_250 ) ;
}
static struct V_169 * F_155 ( struct V_169 * V_170 , struct V_91 * V_47 ,
int type , struct V_251 * * V_252 )
{
struct V_12 * V_13 = V_47 -> V_2 -> V_13 ;
struct V_213 * V_214 ;
struct V_251 * V_253 ;
if ( ! V_170 )
V_170 = F_130 ( V_47 -> V_2 , V_13 -> V_254 ) ;
if ( ! V_170 )
return NULL ;
V_253 = (struct V_251 * ) F_128 ( V_170 , sizeof( struct V_251 ) ) ;
V_253 -> V_255 = type ;
V_253 -> V_256 = 0 ;
V_253 -> V_257 = 0 ;
V_253 -> V_258 = V_47 -> V_95 ;
V_214 = (struct V_213 * ) F_122 ( V_170 ) ;
V_214 -> V_234 = F_120 ( F_111 ( V_214 -> V_234 ) + 1 ) ;
* V_252 = V_253 ;
return V_170 ;
}
static struct V_169 * F_156 ( struct V_169 * V_170 , struct V_91 * V_47 ,
int type , int V_197 , int V_198 , int V_259 )
{
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_213 * V_214 ;
struct V_251 * V_253 = NULL ;
struct V_108 * V_109 , * V_118 , * V_260 , * * V_261 ;
int V_145 , V_262 , V_263 , V_264 , V_265 ;
if ( V_47 -> V_98 & V_102 )
return V_170 ;
V_264 = type == V_199 ||
type == V_200 ;
V_265 = type == V_200 ||
type == V_202 ;
V_262 = V_145 = 0 ;
V_261 = V_198 ? & V_47 -> V_110 : & V_47 -> V_111 ;
if ( ! * V_261 )
goto V_266;
V_214 = V_170 ? (struct V_213 * ) F_122 ( V_170 ) : NULL ;
if ( V_265 ) {
if ( V_214 && V_214 -> V_234 &&
F_157 ( V_170 ) < F_154 ( V_47 , type , V_197 , V_198 ) ) {
if ( V_170 )
F_139 ( V_170 ) ;
V_170 = F_130 ( V_2 , V_13 -> V_254 ) ;
}
}
V_263 = 1 ;
V_260 = NULL ;
for ( V_109 = * V_261 ; V_109 ; V_109 = V_118 ) {
struct V_10 * V_267 ;
V_118 = V_109 -> V_112 ;
if ( ! F_124 ( V_47 , V_109 , type , V_197 , V_198 ) ) {
V_260 = V_109 ;
continue;
}
if ( V_264 )
V_109 -> V_147 = 0 ;
if ( F_157 ( V_170 ) < sizeof( * V_267 ) +
V_263 * sizeof( struct V_251 ) ) {
if ( V_265 && ! V_263 )
break;
if ( V_253 )
V_253 -> V_257 = F_120 ( V_145 ) ;
if ( V_170 )
F_139 ( V_170 ) ;
V_170 = F_130 ( V_2 , V_13 -> V_254 ) ;
V_263 = 1 ;
V_145 = 0 ;
}
if ( V_263 ) {
V_170 = F_155 ( V_170 , V_47 , type , & V_253 ) ;
V_263 = 0 ;
}
if ( ! V_170 )
return NULL ;
V_267 = (struct V_10 * ) F_128 ( V_170 , sizeof( * V_267 ) ) ;
* V_267 = V_109 -> V_130 ;
V_145 ++ ; V_262 ++ ;
if ( ( type == V_203 ||
type == V_204 ) && V_109 -> V_113 ) {
V_109 -> V_113 -- ;
if ( ( V_198 || V_197 ) && V_109 -> V_113 == 0 ) {
if ( V_260 )
V_260 -> V_112 = V_109 -> V_112 ;
else
* V_261 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
continue;
}
}
V_260 = V_109 ;
}
V_266:
if ( ! V_262 ) {
if ( type == V_203 ||
type == V_204 )
return V_170 ;
if ( V_47 -> V_103 || V_264 || V_259 ) {
if ( V_170 && F_157 ( V_170 ) < sizeof( struct V_251 ) ) {
F_139 ( V_170 ) ;
V_170 = NULL ;
}
V_170 = F_155 ( V_170 , V_47 , type , & V_253 ) ;
}
}
if ( V_253 )
V_253 -> V_257 = F_120 ( V_145 ) ;
if ( V_264 )
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
type = V_200 ;
else
type = V_199 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
F_57 ( & V_47 -> V_97 ) ;
}
} else {
F_54 ( & V_47 -> V_97 ) ;
if ( V_47 -> V_126 [ V_30 ] )
type = V_200 ;
else
type = V_199 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
F_57 ( & V_47 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
if ( V_170 )
F_139 ( V_170 ) ;
}
static void F_159 ( struct V_108 * * V_268 )
{
struct V_108 * V_260 , * V_118 , * V_109 ;
V_260 = NULL ;
for ( V_109 = * V_268 ; V_109 ; V_109 = V_118 ) {
V_118 = V_109 -> V_112 ;
if ( V_109 -> V_113 == 0 ) {
if ( V_260 )
V_260 -> V_112 = V_109 -> V_112 ;
else
* V_268 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
} else
V_260 = V_109 ;
}
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_91 * V_47 , * V_117 , * V_269 ;
struct V_169 * V_170 = NULL ;
int type , V_270 ;
F_30 ( & V_2 -> V_40 ) ;
F_18 ( & V_2 -> V_114 ) ;
V_117 = NULL ;
for ( V_47 = V_2 -> V_115 ; V_47 ; V_47 = V_269 ) {
V_269 = V_47 -> V_24 ;
if ( V_47 -> V_107 == V_64 ) {
type = V_204 ;
V_270 = V_204 ;
V_170 = F_156 ( V_170 , V_47 , type , 1 , 0 , 0 ) ;
V_170 = F_156 ( V_170 , V_47 , V_270 , 1 , 1 , 0 ) ;
}
if ( V_47 -> V_103 ) {
if ( V_47 -> V_107 == V_30 ) {
type = V_201 ;
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
V_117 -> V_24 = V_269 ;
else
V_2 -> V_115 = V_269 ;
F_50 ( V_47 -> V_2 ) ;
F_51 ( V_47 ) ;
} else
V_117 = V_47 ;
}
F_20 ( & V_2 -> V_114 ) ;
for ( V_47 = V_2 -> V_120 ; V_47 ; V_47 = V_47 -> V_24 ) {
F_54 ( & V_47 -> V_97 ) ;
if ( V_47 -> V_126 [ V_30 ] ) {
type = V_204 ;
V_270 = V_203 ;
} else {
type = V_203 ;
V_270 = V_204 ;
}
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
V_170 = F_156 ( V_170 , V_47 , V_270 , 0 , 1 , 0 ) ;
if ( V_47 -> V_103 ) {
if ( V_47 -> V_107 == V_30 )
type = V_202 ;
else
type = V_201 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 0 ) ;
V_47 -> V_103 -- ;
}
F_57 ( & V_47 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
if ( ! V_170 )
return;
( void ) F_139 ( V_170 ) ;
}
static void F_161 ( struct V_10 * V_11 , struct V_12 * V_13 , int type )
{
struct V_18 * V_18 = F_95 ( V_13 ) ;
struct V_7 * V_8 = V_18 -> V_148 . V_212 ;
struct V_1 * V_2 ;
struct V_169 * V_170 ;
struct V_164 * V_207 ;
const struct V_10 * V_271 , * V_176 ;
struct V_10 V_215 ;
int V_216 = F_131 ( V_13 ) ;
int V_217 = V_13 -> V_218 ;
int V_19 , V_173 , V_174 , V_272 ;
T_3 V_180 [ 8 ] = { V_219 , 0 ,
V_220 , 2 , 0 , 0 ,
V_221 , 0 } ;
struct V_237 V_238 ;
struct V_239 * V_27 ;
if ( type == V_273 )
V_271 = & V_274 ;
else
V_271 = V_11 ;
V_173 = sizeof( struct V_188 ) + sizeof( struct V_10 ) ;
V_174 = V_173 + sizeof( V_180 ) ;
V_272 = sizeof( struct V_175 ) + V_174 ;
F_7 () ;
F_140 ( V_18 , F_24 ( V_13 ) ,
V_240 , V_272 ) ;
F_10 () ;
V_170 = F_134 ( V_8 , V_216 + V_217 + V_272 , 1 , & V_19 ) ;
if ( V_170 == NULL ) {
F_7 () ;
F_152 ( V_18 , F_24 ( V_13 ) ,
V_248 ) ;
F_10 () ;
return;
}
V_170 -> V_222 = V_223 ;
F_135 ( V_170 , V_216 ) ;
if ( F_162 ( V_13 , & V_215 , V_224 ) ) {
V_176 = & V_225 ;
} else
V_176 = & V_215 ;
F_126 ( V_8 , V_170 , V_13 , V_176 , V_271 , V_227 , V_174 ) ;
memcpy ( F_128 ( V_170 , sizeof( V_180 ) ) , V_180 , sizeof( V_180 ) ) ;
V_207 = (struct V_164 * ) F_128 ( V_170 , sizeof( struct V_164 ) ) ;
memset ( V_207 , 0 , sizeof( struct V_164 ) ) ;
V_207 -> V_275 = type ;
V_207 -> V_182 = * V_11 ;
V_207 -> V_276 = F_142 ( V_176 , V_271 , V_173 ,
V_219 ,
F_143 ( V_207 , V_173 , 0 ) ) ;
F_7 () ;
V_2 = F_24 ( V_170 -> V_13 ) ;
F_144 ( V_8 , & V_238 , type ,
& F_116 ( V_170 ) -> V_176 , & F_116 ( V_170 ) -> V_205 ,
V_170 -> V_13 -> V_9 ) ;
V_27 = F_145 ( V_170 -> V_13 , & V_238 ) ;
if ( F_146 ( V_27 ) ) {
V_19 = F_147 ( V_27 ) ;
goto V_241;
}
F_148 ( V_170 , V_27 ) ;
V_19 = F_149 ( V_242 , V_243 , V_170 , NULL , V_170 -> V_13 ,
V_244 ) ;
V_245:
if ( ! V_19 ) {
F_150 ( V_18 , V_2 , type ) ;
F_151 ( V_18 , V_2 , V_246 ) ;
F_140 ( V_18 , V_2 , V_247 , V_272 ) ;
} else
F_152 ( V_18 , V_2 , V_248 ) ;
F_10 () ;
return;
V_241:
F_153 ( V_170 ) ;
goto V_245;
}
static void F_163 ( struct V_1 * V_2 )
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
type = V_202 ;
else
type = V_201 ;
V_170 = F_156 ( V_170 , V_47 , type , 0 , 0 , 1 ) ;
F_57 ( & V_47 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
if ( V_170 )
F_139 ( V_170 ) ;
}
void F_164 ( struct V_1 * V_2 )
{
V_2 -> V_277 = V_2 -> V_104 ;
if ( V_2 -> V_277 ) {
F_163 ( V_2 ) ;
V_2 -> V_277 -- ;
if ( V_2 -> V_277 )
F_88 ( V_2 , V_2 -> V_133 ) ;
}
}
static void F_165 ( unsigned long V_228 )
{
struct V_1 * V_2 = (struct V_1 * ) V_228 ;
F_163 ( V_2 ) ;
if ( V_2 -> V_277 ) {
V_2 -> V_277 -- ;
if ( V_2 -> V_277 )
F_88 ( V_2 , V_2 -> V_133 ) ;
}
F_50 ( V_2 ) ;
}
static int F_166 ( struct V_91 * V_47 , int V_29 ,
const struct V_10 * V_278 )
{
struct V_108 * V_109 , * V_260 ;
int V_53 = 0 ;
V_260 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( F_9 ( & V_109 -> V_130 , V_278 ) )
break;
V_260 = V_109 ;
}
if ( ! V_109 || V_109 -> V_131 [ V_29 ] == 0 ) {
return - V_279 ;
}
V_109 -> V_131 [ V_29 ] -- ;
if ( ! V_109 -> V_131 [ V_64 ] && ! V_109 -> V_131 [ V_30 ] ) {
struct V_1 * V_2 = V_47 -> V_2 ;
if ( V_260 )
V_260 -> V_112 = V_109 -> V_112 ;
else
V_47 -> V_111 = V_109 -> V_112 ;
if ( V_109 -> V_280 && ! ( V_47 -> V_98 & V_102 ) &&
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
int V_29 , int V_281 , const struct V_10 * V_278 ,
int V_282 )
{
struct V_91 * V_47 ;
int V_283 = 0 ;
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
return - V_279 ;
}
F_54 ( & V_47 -> V_97 ) ;
F_167 ( V_47 ) ;
if ( ! V_282 ) {
if ( ! V_47 -> V_126 [ V_29 ] ) {
F_57 ( & V_47 -> V_97 ) ;
F_31 ( & V_2 -> V_40 ) ;
return - V_20 ;
}
V_47 -> V_126 [ V_29 ] -- ;
}
V_19 = 0 ;
for ( V_51 = 0 ; V_51 < V_281 ; V_51 ++ ) {
int V_53 = F_166 ( V_47 , V_29 , & V_278 [ V_51 ] ) ;
V_283 |= V_53 > 0 ;
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
} else if ( F_168 ( V_47 ) || V_283 )
F_59 ( V_47 -> V_2 ) ;
F_57 ( & V_47 -> V_97 ) ;
F_31 ( & V_2 -> V_40 ) ;
return V_19 ;
}
static int F_169 ( struct V_91 * V_47 , int V_29 ,
const struct V_10 * V_278 )
{
struct V_108 * V_109 , * V_260 ;
V_260 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( F_9 ( & V_109 -> V_130 , V_278 ) )
break;
V_260 = V_109 ;
}
if ( ! V_109 ) {
V_109 = F_67 ( sizeof( * V_109 ) , V_71 ) ;
if ( ! V_109 )
return - V_66 ;
V_109 -> V_130 = * V_278 ;
if ( V_260 ) {
V_260 -> V_112 = V_109 ;
} else
V_47 -> V_111 = V_109 ;
}
V_109 -> V_131 [ V_29 ] ++ ;
return 0 ;
}
static void F_167 ( struct V_91 * V_47 )
{
struct V_108 * V_109 ;
int V_284 = V_47 -> V_126 [ V_30 ] ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 )
if ( V_47 -> V_126 [ V_30 ] ) {
V_109 -> V_280 = V_284 ==
V_109 -> V_131 [ V_30 ] &&
! V_109 -> V_131 [ V_64 ] ;
} else
V_109 -> V_280 = V_109 -> V_131 [ V_64 ] != 0 ;
}
static int F_168 ( struct V_91 * V_47 )
{
struct V_108 * V_109 , * V_285 ;
int V_284 = V_47 -> V_126 [ V_30 ] ;
int V_286 = V_47 -> V_2 -> V_104 ;
int V_287 , V_53 ;
V_53 = 0 ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_109 -> V_112 ) {
if ( V_47 -> V_126 [ V_30 ] ) {
V_287 = V_284 == V_109 -> V_131 [ V_30 ] &&
! V_109 -> V_131 [ V_64 ] ;
} else
V_287 = V_109 -> V_131 [ V_64 ] != 0 ;
if ( V_287 ) {
if ( ! V_109 -> V_280 ) {
struct V_108 * V_288 = NULL ;
for ( V_285 = V_47 -> V_110 ; V_285 ;
V_285 = V_285 -> V_112 ) {
if ( F_9 ( & V_285 -> V_130 ,
& V_109 -> V_130 ) )
break;
V_288 = V_285 ;
}
if ( V_285 ) {
if ( V_288 )
V_288 -> V_112 = V_285 -> V_112 ;
else
V_47 -> V_110 = V_285 -> V_112 ;
F_51 ( V_285 ) ;
}
V_109 -> V_113 = V_286 ;
V_53 ++ ;
}
} else if ( V_109 -> V_280 ) {
V_109 -> V_113 = 0 ;
for ( V_285 = V_47 -> V_110 ; V_285 ; V_285 = V_285 -> V_112 )
if ( F_9 ( & V_285 -> V_130 ,
& V_109 -> V_130 ) )
break;
if ( ! V_285 ) {
V_285 = F_170 ( sizeof( * V_285 ) , V_71 ) ;
if ( ! V_285 )
continue;
* V_285 = * V_109 ;
V_285 -> V_112 = V_47 -> V_110 ;
V_47 -> V_110 = V_285 ;
}
V_285 -> V_113 = V_286 ;
V_53 ++ ;
}
}
return V_53 ;
}
static int F_35 ( struct V_1 * V_2 , const struct V_10 * V_116 ,
int V_29 , int V_281 , const struct V_10 * V_278 ,
int V_282 )
{
struct V_91 * V_47 ;
int V_289 ;
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
return - V_279 ;
}
F_54 ( & V_47 -> V_97 ) ;
F_167 ( V_47 ) ;
V_289 = V_47 -> V_107 == V_30 ;
if ( ! V_282 )
V_47 -> V_126 [ V_29 ] ++ ;
V_19 = 0 ;
for ( V_51 = 0 ; V_51 < V_281 ; V_51 ++ ) {
V_19 = F_169 ( V_47 , V_29 , & V_278 [ V_51 ] ) ;
if ( V_19 )
break;
}
if ( V_19 ) {
int V_52 ;
if ( ! V_282 )
V_47 -> V_126 [ V_29 ] -- ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ )
F_166 ( V_47 , V_29 , & V_278 [ V_52 ] ) ;
} else if ( V_289 != ( V_47 -> V_126 [ V_30 ] != 0 ) ) {
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
} else if ( F_168 ( V_47 ) )
F_59 ( V_2 ) ;
F_57 ( & V_47 -> V_97 ) ;
F_31 ( & V_2 -> V_40 ) ;
return V_19 ;
}
static void F_65 ( struct V_91 * V_47 )
{
struct V_108 * V_109 , * V_290 ;
for ( V_109 = V_47 -> V_110 ; V_109 ; V_109 = V_290 ) {
V_290 = V_109 -> V_112 ;
F_51 ( V_109 ) ;
}
V_47 -> V_110 = NULL ;
for ( V_109 = V_47 -> V_111 ; V_109 ; V_109 = V_290 ) {
V_290 = V_109 -> V_112 ;
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
F_161 ( & V_127 -> V_95 , V_127 -> V_2 -> V_13 , V_291 ) ;
V_136 = F_82 () % F_1 ( V_127 -> V_2 ) ;
F_54 ( & V_127 -> V_97 ) ;
if ( F_63 ( & V_127 -> V_105 ) ) {
F_64 ( & V_127 -> V_92 ) ;
V_136 = V_127 -> V_105 . V_141 - V_125 ;
}
if ( ! F_83 ( & V_127 -> V_105 , V_125 + V_136 ) )
F_91 ( & V_127 -> V_92 ) ;
V_127 -> V_98 |= V_142 | V_196 ;
F_57 ( & V_127 -> V_97 ) ;
}
static int F_25 ( struct V_7 * V_8 , struct V_14 * V_292 ,
struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_292 -> V_32 ) {
return F_36 ( V_2 , & V_292 -> V_11 , V_292 -> V_29 , 0 , NULL , 0 ) ;
}
V_19 = F_36 ( V_2 , & V_292 -> V_11 , V_292 -> V_29 ,
V_292 -> V_32 -> V_62 , V_292 -> V_32 -> V_63 , 0 ) ;
F_15 ( V_8 , V_292 -> V_32 , F_38 ( V_292 -> V_32 -> V_67 ) ) ;
V_292 -> V_32 = NULL ;
return V_19 ;
}
static void F_62 ( struct V_91 * V_127 )
{
if ( F_2 ( V_127 -> V_2 ) ) {
if ( V_127 -> V_98 & V_196 )
F_161 ( & V_127 -> V_95 , V_127 -> V_2 -> V_13 ,
V_273 ) ;
} else {
F_66 ( V_127 -> V_2 , V_127 ) ;
F_59 ( V_127 -> V_2 ) ;
}
}
static void F_171 ( unsigned long V_228 )
{
struct V_1 * V_2 = (struct V_1 * ) V_228 ;
V_2 -> V_134 = 0 ;
F_158 ( V_2 , NULL ) ;
F_50 ( V_2 ) ;
}
static void F_172 ( unsigned long V_228 )
{
struct V_1 * V_2 = (struct V_1 * ) V_228 ;
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
static void V_122 ( unsigned long V_228 )
{
struct V_91 * V_127 = (struct V_91 * ) V_228 ;
if ( F_2 ( V_127 -> V_2 ) )
F_161 ( & V_127 -> V_95 , V_127 -> V_2 -> V_13 , V_291 ) ;
else
F_158 ( V_127 -> V_2 , V_127 ) ;
F_18 ( & V_127 -> V_97 ) ;
V_127 -> V_98 |= V_196 ;
V_127 -> V_98 &= ~ V_142 ;
F_20 ( & V_127 -> V_97 ) ;
F_48 ( V_127 ) ;
}
void F_173 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_51 = V_2 -> V_120 ; V_51 ; V_51 = V_51 -> V_24 )
F_60 ( V_51 ) ;
F_31 ( & V_2 -> V_40 ) ;
}
void F_174 ( struct V_1 * V_2 )
{
F_175 ( V_2 ) ;
}
void F_176 ( struct V_1 * V_2 )
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
void F_175 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_30 ( & V_2 -> V_40 ) ;
for ( V_51 = V_2 -> V_120 ; V_51 ; V_51 = V_51 -> V_24 )
F_52 ( V_51 ) ;
F_31 ( & V_2 -> V_40 ) ;
}
void F_177 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_40 ) ;
F_68 ( & V_2 -> V_114 ) ;
V_2 -> V_134 = 0 ;
F_75 ( & V_2 -> V_135 , F_171 ,
( unsigned long ) V_2 ) ;
V_2 -> V_115 = NULL ;
V_2 -> V_138 = 0 ;
F_75 ( & V_2 -> V_137 , F_172 ,
( unsigned long ) V_2 ) ;
F_75 ( & V_2 -> V_139 , F_165 ,
( unsigned long ) V_2 ) ;
V_2 -> V_104 = V_158 ;
V_2 -> V_153 = V_293 ;
V_2 -> V_154 = V_294 ;
V_2 -> V_133 = F_1 ( V_2 ) ;
V_2 -> V_151 = 0 ;
F_74 ( & V_2 -> V_40 ) ;
}
void F_178 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
F_176 ( V_2 ) ;
F_26 ( V_2 , & V_295 ) ;
if ( V_2 -> V_4 . V_296 )
F_26 ( V_2 , & V_274 ) ;
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
static inline struct V_91 * F_179 ( struct V_297 * V_298 )
{
struct V_91 * V_106 = NULL ;
struct V_299 * V_300 = F_180 ( V_298 ) ;
struct V_18 * V_18 = F_181 ( V_298 ) ;
V_300 -> V_2 = NULL ;
F_182 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_24 ( V_300 -> V_13 ) ;
if ( ! V_2 )
continue;
F_30 ( & V_2 -> V_40 ) ;
V_106 = V_2 -> V_120 ;
if ( V_106 ) {
V_300 -> V_2 = V_2 ;
break;
}
F_31 ( & V_2 -> V_40 ) ;
}
return V_106 ;
}
static struct V_91 * F_183 ( struct V_297 * V_298 , struct V_91 * V_106 )
{
struct V_299 * V_300 = F_180 ( V_298 ) ;
V_106 = V_106 -> V_24 ;
while ( ! V_106 ) {
if ( F_184 ( V_300 -> V_2 != NULL ) )
F_31 ( & V_300 -> V_2 -> V_40 ) ;
V_300 -> V_13 = F_185 ( V_300 -> V_13 ) ;
if ( ! V_300 -> V_13 ) {
V_300 -> V_2 = NULL ;
break;
}
V_300 -> V_2 = F_24 ( V_300 -> V_13 ) ;
if ( ! V_300 -> V_2 )
continue;
F_30 ( & V_300 -> V_2 -> V_40 ) ;
V_106 = V_300 -> V_2 -> V_120 ;
}
return V_106 ;
}
static struct V_91 * F_186 ( struct V_297 * V_298 , T_4 V_301 )
{
struct V_91 * V_106 = F_179 ( V_298 ) ;
if ( V_106 )
while ( V_301 && ( V_106 = F_183 ( V_298 , V_106 ) ) != NULL )
-- V_301 ;
return V_301 ? NULL : V_106 ;
}
static void * F_187 ( struct V_297 * V_298 , T_4 * V_301 )
__acquires( T_5 )
{
F_7 () ;
return F_186 ( V_298 , * V_301 ) ;
}
static void * F_188 ( struct V_297 * V_298 , void * V_302 , T_4 * V_301 )
{
struct V_91 * V_106 = F_183 ( V_298 , V_302 ) ;
++ * V_301 ;
return V_106 ;
}
static void F_189 ( struct V_297 * V_298 , void * V_302 )
__releases( T_5 )
{
struct V_299 * V_300 = F_180 ( V_298 ) ;
if ( F_184 ( V_300 -> V_2 != NULL ) ) {
F_31 ( & V_300 -> V_2 -> V_40 ) ;
V_300 -> V_2 = NULL ;
}
V_300 -> V_13 = NULL ;
F_10 () ;
}
static int F_190 ( struct V_297 * V_298 , void * V_302 )
{
struct V_91 * V_106 = (struct V_91 * ) V_302 ;
struct V_299 * V_300 = F_180 ( V_298 ) ;
F_191 ( V_298 ,
L_2 ,
V_300 -> V_13 -> V_9 , V_300 -> V_13 -> V_303 ,
& V_106 -> V_95 ,
V_106 -> V_121 , V_106 -> V_98 ,
( V_106 -> V_98 & V_142 ) ?
F_192 ( V_106 -> V_105 . V_141 - V_125 ) : 0 ) ;
return 0 ;
}
static int F_193 ( struct V_304 * V_304 , struct V_305 * V_305 )
{
return F_194 ( V_304 , V_305 , & V_306 ,
sizeof( struct V_299 ) ) ;
}
static inline struct V_108 * F_195 ( struct V_297 * V_298 )
{
struct V_108 * V_109 = NULL ;
struct V_91 * V_106 = NULL ;
struct V_307 * V_300 = F_196 ( V_298 ) ;
struct V_18 * V_18 = F_181 ( V_298 ) ;
V_300 -> V_2 = NULL ;
V_300 -> V_106 = NULL ;
F_182 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_24 ( V_300 -> V_13 ) ;
if ( F_102 ( V_2 == NULL ) )
continue;
F_30 ( & V_2 -> V_40 ) ;
V_106 = V_2 -> V_120 ;
if ( F_184 ( V_106 != NULL ) ) {
F_54 ( & V_106 -> V_97 ) ;
V_109 = V_106 -> V_111 ;
if ( F_184 ( V_109 != NULL ) ) {
V_300 -> V_106 = V_106 ;
V_300 -> V_2 = V_2 ;
break;
}
F_57 ( & V_106 -> V_97 ) ;
}
F_31 ( & V_2 -> V_40 ) ;
}
return V_109 ;
}
static struct V_108 * F_197 ( struct V_297 * V_298 , struct V_108 * V_109 )
{
struct V_307 * V_300 = F_196 ( V_298 ) ;
V_109 = V_109 -> V_112 ;
while ( ! V_109 ) {
F_57 ( & V_300 -> V_106 -> V_97 ) ;
V_300 -> V_106 = V_300 -> V_106 -> V_24 ;
while ( ! V_300 -> V_106 ) {
if ( F_184 ( V_300 -> V_2 != NULL ) )
F_31 ( & V_300 -> V_2 -> V_40 ) ;
V_300 -> V_13 = F_185 ( V_300 -> V_13 ) ;
if ( ! V_300 -> V_13 ) {
V_300 -> V_2 = NULL ;
goto V_245;
}
V_300 -> V_2 = F_24 ( V_300 -> V_13 ) ;
if ( ! V_300 -> V_2 )
continue;
F_30 ( & V_300 -> V_2 -> V_40 ) ;
V_300 -> V_106 = V_300 -> V_2 -> V_120 ;
}
if ( ! V_300 -> V_106 )
break;
F_54 ( & V_300 -> V_106 -> V_97 ) ;
V_109 = V_300 -> V_106 -> V_111 ;
}
V_245:
return V_109 ;
}
static struct V_108 * F_198 ( struct V_297 * V_298 , T_4 V_301 )
{
struct V_108 * V_109 = F_195 ( V_298 ) ;
if ( V_109 )
while ( V_301 && ( V_109 = F_197 ( V_298 , V_109 ) ) != NULL )
-- V_301 ;
return V_301 ? NULL : V_109 ;
}
static void * F_199 ( struct V_297 * V_298 , T_4 * V_301 )
__acquires( T_5 )
{
F_7 () ;
return * V_301 ? F_198 ( V_298 , * V_301 - 1 ) : V_308 ;
}
static void * F_200 ( struct V_297 * V_298 , void * V_302 , T_4 * V_301 )
{
struct V_108 * V_109 ;
if ( V_302 == V_308 )
V_109 = F_195 ( V_298 ) ;
else
V_109 = F_197 ( V_298 , V_302 ) ;
++ * V_301 ;
return V_109 ;
}
static void F_201 ( struct V_297 * V_298 , void * V_302 )
__releases( T_5 )
{
struct V_307 * V_300 = F_196 ( V_298 ) ;
if ( F_184 ( V_300 -> V_106 != NULL ) ) {
F_57 ( & V_300 -> V_106 -> V_97 ) ;
V_300 -> V_106 = NULL ;
}
if ( F_184 ( V_300 -> V_2 != NULL ) ) {
F_31 ( & V_300 -> V_2 -> V_40 ) ;
V_300 -> V_2 = NULL ;
}
V_300 -> V_13 = NULL ;
F_10 () ;
}
static int F_202 ( struct V_297 * V_298 , void * V_302 )
{
struct V_108 * V_109 = (struct V_108 * ) V_302 ;
struct V_307 * V_300 = F_196 ( V_298 ) ;
if ( V_302 == V_308 ) {
F_191 ( V_298 ,
L_3
L_4 , L_5 ,
L_6 , L_7 ,
L_8 , L_9 , L_10 ) ;
} else {
F_191 ( V_298 ,
L_11 ,
V_300 -> V_13 -> V_9 , V_300 -> V_13 -> V_303 ,
& V_300 -> V_106 -> V_95 ,
& V_109 -> V_130 ,
V_109 -> V_131 [ V_64 ] ,
V_109 -> V_131 [ V_30 ] ) ;
}
return 0 ;
}
static int F_203 ( struct V_304 * V_304 , struct V_305 * V_305 )
{
return F_194 ( V_304 , V_305 , & V_309 ,
sizeof( struct V_307 ) ) ;
}
static int T_6 F_204 ( struct V_18 * V_18 )
{
int V_19 ;
V_19 = - V_23 ;
if ( ! F_205 ( L_12 , V_310 , V_18 -> V_311 , & V_312 ) )
goto V_245;
if ( ! F_205 ( L_13 , V_310 , V_18 -> V_311 ,
& V_313 ) )
goto V_314;
V_19 = 0 ;
V_245:
return V_19 ;
V_314:
F_206 ( L_12 , V_18 -> V_311 ) ;
goto V_245;
}
static void T_7 F_207 ( struct V_18 * V_18 )
{
F_206 ( L_13 , V_18 -> V_311 ) ;
F_206 ( L_12 , V_18 -> V_311 ) ;
}
static inline int F_204 ( struct V_18 * V_18 )
{
return 0 ;
}
static inline void F_207 ( struct V_18 * V_18 )
{
}
static int T_6 F_208 ( struct V_18 * V_18 )
{
int V_19 ;
V_19 = F_209 ( & V_18 -> V_148 . V_212 , V_315 ,
V_316 , V_219 , V_18 ) ;
if ( V_19 < 0 ) {
F_210 ( L_14 ,
V_19 ) ;
goto V_245;
}
F_4 ( V_18 -> V_148 . V_212 ) -> V_178 = 1 ;
V_19 = F_204 ( V_18 ) ;
if ( V_19 )
goto V_317;
V_245:
return V_19 ;
V_317:
F_211 ( V_18 -> V_148 . V_212 ) ;
goto V_245;
}
static void T_7 F_212 ( struct V_18 * V_18 )
{
F_211 ( V_18 -> V_148 . V_212 ) ;
F_207 ( V_18 ) ;
}
int T_8 F_213 ( void )
{
return F_214 ( & V_318 ) ;
}
void F_215 ( void )
{
F_216 ( & V_318 ) ;
}
