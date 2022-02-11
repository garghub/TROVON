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
F_11 ( & V_20 -> V_21 ) ;
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
F_11 ( & V_20 -> V_21 ) ;
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
int F_31 ( int V_38 , int V_39 , struct V_1 * V_2 ,
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
F_32 ( V_31 , V_35 , V_39 , 0 , NULL , 0 ) ;
F_33 ( V_31 , V_35 , V_43 -> V_23 , 0 , NULL , 0 ) ;
V_43 -> V_23 = V_39 ;
}
F_34 ( & V_43 -> V_25 ) ;
V_51 = 1 ;
V_46 = V_43 -> V_26 ;
if ( ! V_38 ) {
if ( ! V_46 )
goto V_57;
V_49 = ! 0 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ ) {
V_49 = memcmp ( & V_46 -> V_59 [ V_47 ] , V_42 ,
sizeof( struct V_4 ) ) ;
if ( V_49 == 0 )
break;
}
if ( V_49 )
goto V_57;
if ( V_46 -> V_58 == 1 && V_39 == V_60 ) {
V_50 = 1 ;
goto V_57;
}
F_33 ( V_31 , V_35 , V_39 , 1 , V_42 , 1 ) ;
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
V_64 = F_9 ( V_2 , F_35 ( V_65 ) , V_67 ) ;
if ( ! V_64 ) {
V_13 = - V_62 ;
goto V_57;
}
V_64 -> V_63 = V_65 ;
V_64 -> V_58 = V_65 - V_66 ;
if ( V_46 ) {
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ )
V_64 -> V_59 [ V_47 ] = V_46 -> V_59 [ V_47 ] ;
F_13 ( V_2 , V_46 , F_35 ( V_46 -> V_63 ) ) ;
}
V_43 -> V_26 = V_46 = V_64 ;
}
V_49 = 1 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_58 ; V_47 ++ ) {
V_49 = memcmp ( & V_46 -> V_59 [ V_47 ] , V_42 , sizeof( struct V_4 ) ) ;
if ( V_49 == 0 )
break;
}
if ( V_49 == 0 )
goto V_57;
for ( V_48 = V_46 -> V_58 - 1 ; V_48 >= V_47 ; V_48 -- )
V_46 -> V_59 [ V_48 + 1 ] = V_46 -> V_59 [ V_48 ] ;
V_46 -> V_59 [ V_47 ] = * V_42 ;
V_46 -> V_58 ++ ;
V_13 = 0 ;
F_32 ( V_31 , V_35 , V_39 , 1 , V_42 , 1 ) ;
V_57:
if ( V_51 )
F_36 ( & V_43 -> V_25 ) ;
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
if ( V_50 )
return F_19 ( V_2 , V_41 -> V_56 , V_35 ) ;
return V_13 ;
}
int F_37 ( struct V_1 * V_2 , struct V_68 * V_69 )
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
V_64 = F_9 ( V_2 , F_35 ( V_69 -> V_73 ) ,
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
V_13 = F_32 ( V_31 , V_35 , V_69 -> V_71 ,
V_64 -> V_58 , V_64 -> V_59 , 0 ) ;
if ( V_13 ) {
F_13 ( V_2 , V_64 , F_35 ( V_64 -> V_63 ) ) ;
goto V_57;
}
} else {
V_64 = NULL ;
( void ) F_32 ( V_31 , V_35 , V_69 -> V_71 , 0 , NULL , 0 ) ;
}
F_34 ( & V_43 -> V_25 ) ;
V_46 = V_43 -> V_26 ;
if ( V_46 ) {
( void ) F_33 ( V_31 , V_35 , V_43 -> V_23 ,
V_46 -> V_58 , V_46 -> V_59 , 0 ) ;
F_13 ( V_2 , V_46 , F_35 ( V_46 -> V_63 ) ) ;
} else
( void ) F_33 ( V_31 , V_35 , V_43 -> V_23 , 0 , NULL , 0 ) ;
V_43 -> V_26 = V_64 ;
V_43 -> V_23 = V_69 -> V_71 ;
F_36 ( & V_43 -> V_25 ) ;
V_13 = 0 ;
V_57:
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
if ( V_50 )
V_13 = F_19 ( V_2 , V_69 -> V_72 , V_35 ) ;
return V_13 ;
}
int F_38 ( struct V_1 * V_2 , struct V_68 * V_69 ,
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
if ( F_39 ( F_40 ( V_78 ) , V_77 ) ||
F_41 ( V_76 , V_69 , F_40 ( 0 ) ) ) {
return - V_79 ;
}
for ( V_47 = 0 ; V_47 < V_78 ; V_47 ++ ) {
struct V_52 * V_74 ;
struct V_80 V_81 ;
V_74 = (struct V_52 * ) & V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_74 -> V_82 = V_83 ;
V_74 -> V_54 = V_46 -> V_59 [ V_47 ] ;
if ( F_41 ( & V_76 -> V_75 [ V_47 ] , & V_81 , sizeof( V_81 ) ) )
return - V_79 ;
}
return 0 ;
V_57:
F_29 ( & V_31 -> V_36 ) ;
F_8 () ;
return V_13 ;
}
int F_42 ( struct V_1 * V_2 , const struct V_4 * V_84 ,
const struct V_4 * V_85 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_86 ;
struct V_45 * V_46 ;
int V_49 = 1 ;
F_5 () ;
F_6 (np, mc) {
if ( F_7 ( & V_86 -> V_5 , V_84 ) )
break;
}
if ( ! V_86 ) {
F_8 () ;
return 1 ;
}
F_43 ( & V_86 -> V_25 ) ;
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
V_49 = 0 ;
if ( V_86 -> V_23 == V_24 && V_47 < V_46 -> V_58 )
V_49 = 0 ;
}
F_44 ( & V_86 -> V_25 ) ;
F_8 () ;
return V_49 ;
}
static void F_45 ( struct V_87 * V_86 )
{
if ( F_46 ( & V_86 -> V_88 ) ) {
F_47 ( V_86 -> V_31 ) ;
F_48 ( V_86 ) ;
}
}
static void F_49 ( struct V_87 * V_86 )
{
struct V_6 * V_7 = V_86 -> V_31 -> V_7 ;
char V_89 [ V_90 ] ;
F_50 ( & V_86 -> V_91 ) ;
if ( ! ( V_86 -> V_92 & V_93 ) ) {
V_86 -> V_92 |= V_93 ;
if ( F_51 ( & V_86 -> V_94 , V_89 , V_7 , 0 ) == 0 )
F_52 ( V_7 , V_89 ) ;
}
F_53 ( & V_86 -> V_91 ) ;
if ( ! ( V_7 -> V_95 & V_96 ) || ( V_86 -> V_92 & V_97 ) )
return;
if ( F_54 ( V_86 -> V_31 ) ) {
F_55 ( V_86 ) ;
return;
}
V_86 -> V_98 = V_86 -> V_31 -> V_99 ;
F_56 ( V_86 -> V_31 ) ;
}
static void F_57 ( struct V_87 * V_86 )
{
struct V_6 * V_7 = V_86 -> V_31 -> V_7 ;
char V_89 [ V_90 ] ;
F_50 ( & V_86 -> V_91 ) ;
if ( V_86 -> V_92 & V_93 ) {
V_86 -> V_92 &= ~ V_93 ;
if ( F_51 ( & V_86 -> V_94 , V_89 , V_7 , 0 ) == 0 )
F_58 ( V_7 , V_89 ) ;
}
if ( V_86 -> V_92 & V_97 )
goto V_57;
F_53 ( & V_86 -> V_91 ) ;
if ( ! V_86 -> V_31 -> V_37 )
F_59 ( V_86 ) ;
F_50 ( & V_86 -> V_91 ) ;
if ( F_60 ( & V_86 -> V_100 ) )
F_61 ( & V_86 -> V_88 ) ;
V_57:
F_62 ( V_86 ) ;
F_53 ( & V_86 -> V_91 ) ;
}
static void F_63 ( struct V_30 * V_31 , struct V_87 * V_101 )
{
struct V_87 * V_43 ;
V_43 = F_64 ( sizeof( * V_43 ) , V_67 ) ;
if ( ! V_43 )
return;
F_50 ( & V_101 -> V_91 ) ;
F_65 ( & V_43 -> V_91 ) ;
V_43 -> V_31 = V_101 -> V_31 ;
F_66 ( V_31 ) ;
V_43 -> V_94 = V_101 -> V_94 ;
V_43 -> V_98 = V_31 -> V_99 ;
V_43 -> V_102 = V_101 -> V_102 ;
if ( V_43 -> V_102 == V_60 ) {
struct V_103 * V_104 ;
V_43 -> V_105 = V_101 -> V_105 ;
V_43 -> V_106 = V_101 -> V_106 ;
V_101 -> V_105 = V_101 -> V_106 = NULL ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 )
V_104 -> V_108 = V_43 -> V_98 ;
}
F_53 ( & V_101 -> V_91 ) ;
F_50 ( & V_31 -> V_109 ) ;
V_43 -> V_18 = V_31 -> V_110 ;
V_31 -> V_110 = V_43 ;
F_53 ( & V_31 -> V_109 ) ;
}
static void F_67 ( struct V_30 * V_31 , const struct V_4 * V_111 )
{
struct V_87 * V_43 , * V_112 ;
struct V_103 * V_104 , * V_113 ;
F_50 ( & V_31 -> V_109 ) ;
V_112 = NULL ;
for ( V_43 = V_31 -> V_110 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( F_7 ( & V_43 -> V_94 , V_111 ) )
break;
V_112 = V_43 ;
}
if ( V_43 ) {
if ( V_112 )
V_112 -> V_18 = V_43 -> V_18 ;
else
V_31 -> V_110 = V_43 -> V_18 ;
}
F_53 ( & V_31 -> V_109 ) ;
if ( V_43 ) {
for ( V_104 = V_43 -> V_105 ; V_104 ; V_104 = V_113 ) {
V_113 = V_104 -> V_107 ;
F_48 ( V_104 ) ;
}
F_47 ( V_43 -> V_31 ) ;
F_48 ( V_43 ) ;
}
}
static void F_68 ( struct V_30 * V_31 )
{
struct V_87 * V_43 , * V_114 ;
F_50 ( & V_31 -> V_109 ) ;
V_43 = V_31 -> V_110 ;
V_31 -> V_110 = NULL ;
F_53 ( & V_31 -> V_109 ) ;
for (; V_43 ; V_43 = V_114 ) {
V_114 = V_43 -> V_18 ;
F_62 ( V_43 ) ;
F_47 ( V_43 -> V_31 ) ;
F_48 ( V_43 ) ;
}
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_115 ; V_43 ; V_43 = V_43 -> V_18 ) {
struct V_103 * V_104 , * V_113 ;
F_50 ( & V_43 -> V_91 ) ;
V_104 = V_43 -> V_105 ;
V_43 -> V_105 = NULL ;
F_53 ( & V_43 -> V_91 ) ;
for (; V_104 ; V_104 = V_113 ) {
V_113 = V_104 -> V_107 ;
F_48 ( V_104 ) ;
}
}
F_29 ( & V_31 -> V_36 ) ;
}
int F_15 ( struct V_6 * V_7 , const struct V_4 * V_5 )
{
struct V_87 * V_86 ;
struct V_30 * V_31 ;
V_31 = F_69 ( V_7 ) ;
if ( V_31 == NULL )
return - V_14 ;
F_70 ( & V_31 -> V_36 ) ;
if ( V_31 -> V_37 ) {
F_71 ( & V_31 -> V_36 ) ;
F_47 ( V_31 ) ;
return - V_22 ;
}
for ( V_86 = V_31 -> V_115 ; V_86 ; V_86 = V_86 -> V_18 ) {
if ( F_7 ( & V_86 -> V_94 , V_5 ) ) {
V_86 -> V_116 ++ ;
F_71 ( & V_31 -> V_36 ) ;
F_32 ( V_31 , & V_86 -> V_94 , V_24 , 0 ,
NULL , 0 ) ;
F_47 ( V_31 ) ;
return 0 ;
}
}
V_86 = F_64 ( sizeof( struct V_87 ) , V_67 ) ;
if ( V_86 == NULL ) {
F_71 ( & V_31 -> V_36 ) ;
F_47 ( V_31 ) ;
return - V_17 ;
}
F_72 ( & V_86 -> V_100 , V_117 , ( unsigned long ) V_86 ) ;
V_86 -> V_94 = * V_5 ;
V_86 -> V_31 = V_31 ;
V_86 -> V_116 = 1 ;
V_86 -> V_118 = V_86 -> V_119 = V_120 ;
F_73 ( & V_86 -> V_88 , 2 ) ;
F_65 ( & V_86 -> V_91 ) ;
V_86 -> V_102 = V_24 ;
V_86 -> V_121 [ V_24 ] = 1 ;
if ( F_74 ( & V_86 -> V_94 ) ||
F_75 ( & V_86 -> V_94 ) < V_122 )
V_86 -> V_92 |= V_97 ;
V_86 -> V_18 = V_31 -> V_115 ;
V_31 -> V_115 = V_86 ;
F_71 ( & V_31 -> V_36 ) ;
F_67 ( V_31 , & V_86 -> V_94 ) ;
F_49 ( V_86 ) ;
F_45 ( V_86 ) ;
return 0 ;
}
int F_24 ( struct V_30 * V_31 , const struct V_4 * V_5 )
{
struct V_87 * V_123 , * * V_124 ;
F_70 ( & V_31 -> V_36 ) ;
for ( V_124 = & V_31 -> V_115 ; ( V_123 = * V_124 ) != NULL ; V_124 = & V_123 -> V_18 ) {
if ( F_7 ( & V_123 -> V_94 , V_5 ) ) {
if ( -- V_123 -> V_116 == 0 ) {
* V_124 = V_123 -> V_18 ;
F_71 ( & V_31 -> V_36 ) ;
F_57 ( V_123 ) ;
F_45 ( V_123 ) ;
return 0 ;
}
F_71 ( & V_31 -> V_36 ) ;
return 0 ;
}
}
F_71 ( & V_31 -> V_36 ) ;
return - V_125 ;
}
int F_76 ( struct V_6 * V_7 , const struct V_4 * V_5 )
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
int F_77 ( struct V_126 * V_127 , int V_128 )
{
struct V_129 * V_130 ;
if ( V_128 != V_131 )
return 0 ;
if ( ! F_78 ( V_127 , sizeof( struct V_129 ) ) )
return 0 ;
V_130 = F_79 ( V_127 ) ;
switch ( V_130 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
return 1 ;
default:
break;
}
return 0 ;
}
int F_80 ( struct V_6 * V_7 , const struct V_4 * V_35 ,
const struct V_4 * V_85 )
{
struct V_30 * V_31 ;
struct V_87 * V_86 ;
int V_49 = 0 ;
F_5 () ;
V_31 = F_22 ( V_7 ) ;
if ( V_31 ) {
F_28 ( & V_31 -> V_36 ) ;
for ( V_86 = V_31 -> V_115 ; V_86 ; V_86 = V_86 -> V_18 ) {
if ( F_7 ( & V_86 -> V_94 , V_35 ) )
break;
}
if ( V_86 ) {
if ( V_85 && ! F_81 ( V_85 ) ) {
struct V_103 * V_104 ;
F_50 ( & V_86 -> V_91 ) ;
for ( V_104 = V_86 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( F_7 ( & V_104 -> V_137 , V_85 ) )
break;
}
if ( V_104 )
V_49 = V_104 -> V_138 [ V_60 ] ||
V_104 -> V_138 [ V_24 ] !=
V_86 -> V_121 [ V_24 ] ;
else
V_49 = V_86 -> V_121 [ V_24 ] != 0 ;
F_53 ( & V_86 -> V_91 ) ;
} else
V_49 = 1 ;
}
F_29 ( & V_31 -> V_36 ) ;
}
F_8 () ;
return V_49 ;
}
static void F_82 ( struct V_30 * V_31 )
{
int V_139 = F_83 () % V_31 -> V_140 ;
V_31 -> V_141 = 1 ;
if ( ! F_84 ( & V_31 -> V_142 , V_120 + V_139 + 2 ) )
F_66 ( V_31 ) ;
}
static void F_85 ( struct V_30 * V_31 , int V_143 )
{
int V_139 = F_83 () % V_143 ;
if ( ! F_84 ( & V_31 -> V_144 , V_120 + V_139 + 2 ) )
F_66 ( V_31 ) ;
}
static void F_86 ( struct V_87 * V_123 , unsigned long V_145 )
{
unsigned long V_143 = V_145 ;
if ( F_74 ( & V_123 -> V_94 ) ||
F_75 ( & V_123 -> V_94 ) < V_122 )
return;
if ( F_60 ( & V_123 -> V_100 ) ) {
F_61 ( & V_123 -> V_88 ) ;
V_143 = V_123 -> V_100 . V_146 - V_120 ;
}
if ( V_143 >= V_145 ) {
if ( V_145 )
V_143 = F_83 () % V_145 ;
else
V_143 = 1 ;
}
V_123 -> V_100 . V_146 = V_120 + V_143 ;
if ( ! F_84 ( & V_123 -> V_100 , V_120 + V_143 ) )
F_87 ( & V_123 -> V_88 ) ;
V_123 -> V_92 |= V_147 ;
}
static int F_88 ( struct V_87 * V_43 , int V_148 ,
const struct V_4 * V_149 )
{
struct V_103 * V_104 ;
int V_47 , V_150 ;
V_150 = 0 ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( V_150 == V_148 )
break;
for ( V_47 = 0 ; V_47 < V_148 ; V_47 ++ ) {
if ( V_104 -> V_138 [ V_60 ] ||
V_43 -> V_121 [ V_24 ] !=
V_104 -> V_138 [ V_24 ] )
continue;
if ( F_7 ( & V_149 [ V_47 ] , & V_104 -> V_137 ) ) {
V_150 ++ ;
break;
}
}
}
V_43 -> V_92 &= ~ V_151 ;
if ( V_150 == V_148 )
return 0 ;
return 1 ;
}
static int F_89 ( struct V_87 * V_43 , int V_148 ,
const struct V_4 * V_149 )
{
struct V_103 * V_104 ;
int V_47 , V_150 ;
if ( V_43 -> V_102 == V_24 )
return F_88 ( V_43 , V_148 , V_149 ) ;
V_150 = 0 ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( V_150 == V_148 )
break;
for ( V_47 = 0 ; V_47 < V_148 ; V_47 ++ ) {
if ( F_7 ( & V_149 [ V_47 ] , & V_104 -> V_137 ) ) {
V_104 -> V_152 = 1 ;
V_150 ++ ;
break;
}
}
}
if ( ! V_150 ) {
V_43 -> V_92 &= ~ V_151 ;
return 0 ;
}
V_43 -> V_92 |= V_151 ;
return 1 ;
}
int F_90 ( struct V_126 * V_127 )
{
struct V_153 * V_154 = NULL ;
struct V_87 * V_123 ;
const struct V_4 * V_35 ;
unsigned long V_155 ;
struct V_30 * V_31 ;
struct V_156 * V_157 ;
int V_158 ;
int V_159 = 0 ;
int V_160 ;
if ( ! F_78 ( V_127 , sizeof( struct V_4 ) ) )
return - V_14 ;
V_160 = F_91 ( F_92 ( V_127 ) -> V_161 ) + sizeof( struct V_162 ) ;
V_160 -= F_93 ( V_127 ) ;
if ( ! ( F_94 ( & F_92 ( V_127 ) -> V_163 ) & V_164 ) )
return - V_14 ;
V_31 = F_22 ( V_127 -> V_7 ) ;
if ( V_31 == NULL )
return 0 ;
V_157 = (struct V_156 * ) F_79 ( V_127 ) ;
V_35 = & V_157 -> V_165 ;
V_158 = F_94 ( V_35 ) ;
if ( V_158 != V_166 &&
! ( V_158 & V_167 ) )
return - V_14 ;
if ( V_160 == 24 ) {
int V_168 ;
V_155 = ( F_91 ( V_157 -> V_169 ) * V_170 ) / 1000 ;
V_168 = ( V_31 -> V_99 + 1 ) * V_155 ;
V_31 -> V_171 = V_120 + V_168 ;
V_31 -> V_172 = 0 ;
if ( F_60 ( & V_31 -> V_144 ) )
F_95 ( V_31 ) ;
F_68 ( V_31 ) ;
} else if ( V_160 >= 28 ) {
int V_173 = sizeof( struct V_153 ) -
sizeof( struct V_129 ) ;
if ( ! F_78 ( V_127 , V_173 ) )
return - V_14 ;
V_154 = (struct V_153 * ) F_96 ( V_127 ) ;
V_155 = ( F_97 ( F_91 ( V_154 -> V_174 ) ) * V_170 ) / 1000 ;
if ( ! V_155 )
V_155 = 1 ;
V_31 -> V_140 = V_155 ;
if ( V_154 -> V_175 )
V_31 -> V_99 = V_154 -> V_175 ;
if ( V_158 == V_166 ) {
if ( V_154 -> V_176 )
return - V_14 ;
F_82 ( V_31 ) ;
return 0 ;
}
if ( V_154 -> V_176 != 0 ) {
if ( ! F_78 ( V_127 , V_173 +
F_91 ( V_154 -> V_176 ) * sizeof( struct V_4 ) ) )
return - V_14 ;
V_154 = (struct V_153 * ) F_96 ( V_127 ) ;
V_159 = 1 ;
}
} else
return - V_14 ;
F_28 ( & V_31 -> V_36 ) ;
if ( V_158 == V_166 ) {
for ( V_123 = V_31 -> V_115 ; V_123 ; V_123 = V_123 -> V_18 ) {
F_50 ( & V_123 -> V_91 ) ;
F_86 ( V_123 , V_155 ) ;
F_53 ( & V_123 -> V_91 ) ;
}
} else {
for ( V_123 = V_31 -> V_115 ; V_123 ; V_123 = V_123 -> V_18 ) {
if ( ! F_7 ( V_35 , & V_123 -> V_94 ) )
continue;
F_50 ( & V_123 -> V_91 ) ;
if ( V_123 -> V_92 & V_147 ) {
if ( ! V_159 )
V_123 -> V_92 &= ~ V_151 ;
} else {
if ( V_159 )
V_123 -> V_92 |= V_151 ;
else
V_123 -> V_92 &= ~ V_151 ;
}
if ( ! ( V_123 -> V_92 & V_151 ) ||
F_89 ( V_123 , F_91 ( V_154 -> V_176 ) , V_154 -> V_177 ) )
F_86 ( V_123 , V_155 ) ;
F_53 ( & V_123 -> V_91 ) ;
break;
}
}
F_29 ( & V_31 -> V_36 ) ;
return 0 ;
}
int F_98 ( struct V_126 * V_127 )
{
struct V_87 * V_123 ;
struct V_30 * V_31 ;
struct V_156 * V_157 ;
int V_178 ;
if ( V_127 -> V_179 == V_180 )
return 0 ;
if ( V_127 -> V_179 != V_181 &&
V_127 -> V_179 != V_182 )
return 0 ;
if ( ! F_78 ( V_127 , sizeof( * V_157 ) - sizeof( struct V_129 ) ) )
return - V_14 ;
V_157 = (struct V_156 * ) F_79 ( V_127 ) ;
V_178 = F_94 ( & F_92 ( V_127 ) -> V_163 ) ;
if ( V_178 != V_166 &&
! ( V_178 & V_164 ) )
return - V_14 ;
V_31 = F_22 ( V_127 -> V_7 ) ;
if ( V_31 == NULL )
return - V_22 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_123 = V_31 -> V_115 ; V_123 ; V_123 = V_123 -> V_18 ) {
if ( F_7 ( & V_123 -> V_94 , & V_157 -> V_165 ) ) {
F_16 ( & V_123 -> V_91 ) ;
if ( F_60 ( & V_123 -> V_100 ) )
F_61 ( & V_123 -> V_88 ) ;
V_123 -> V_92 &= ~ ( V_183 | V_147 ) ;
F_18 ( & V_123 -> V_91 ) ;
break;
}
}
F_29 ( & V_31 -> V_36 ) ;
return 0 ;
}
static int F_99 ( struct V_87 * V_43 , struct V_103 * V_104 , int type ,
int V_184 , int V_185 )
{
switch ( type ) {
case V_186 :
case V_187 :
if ( V_184 || V_185 )
return 0 ;
if ( ! ( ( V_43 -> V_92 & V_151 ) && ! V_104 -> V_152 ) ) {
if ( V_43 -> V_102 == V_60 )
return 1 ;
if ( V_104 -> V_138 [ V_60 ] )
return type == V_186 ;
return V_43 -> V_121 [ V_24 ] ==
V_104 -> V_138 [ V_24 ] ;
}
return 0 ;
case V_188 :
if ( V_184 || V_185 )
return 0 ;
return V_104 -> V_138 [ V_60 ] != 0 ;
case V_189 :
if ( V_184 || V_185 )
return 0 ;
if ( V_43 -> V_121 [ V_24 ] == 0 ||
V_104 -> V_138 [ V_60 ] )
return 0 ;
return V_43 -> V_121 [ V_24 ] ==
V_104 -> V_138 [ V_24 ] ;
case V_190 :
if ( V_184 || ! V_104 -> V_108 )
return 0 ;
return ( V_43 -> V_102 == V_60 ) ^ V_185 ;
case V_191 :
if ( V_43 -> V_102 == V_60 )
return V_184 || ( V_104 -> V_108 && V_185 ) ;
return V_104 -> V_108 && ! V_184 && ! V_185 ;
}
return 0 ;
}
static int
F_100 ( struct V_87 * V_43 , int type , int V_184 , int V_185 )
{
struct V_103 * V_104 ;
int V_150 = 0 ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( ! F_99 ( V_43 , V_104 , type , V_184 , V_185 ) )
continue;
V_150 ++ ;
}
return V_150 ;
}
static struct V_126 * F_101 ( struct V_6 * V_7 , int V_192 )
{
struct V_12 * V_12 = F_102 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_193 . V_194 ;
struct V_126 * V_127 ;
struct V_195 * V_196 ;
struct V_4 V_197 ;
const struct V_4 * V_163 ;
int V_198 = F_103 ( V_7 ) ;
int V_199 = V_7 -> V_200 ;
int V_13 ;
T_3 V_201 [ 8 ] = { V_131 , 0 ,
V_202 , 2 , 0 , 0 ,
V_203 , 0 } ;
V_192 += V_198 + V_199 ;
V_192 = F_104 ( int , V_192 , F_105 ( 0 , 0 ) ) ;
V_127 = F_106 ( V_2 , V_192 , 1 , & V_13 ) ;
if ( ! V_127 )
return NULL ;
F_107 ( V_127 , V_198 ) ;
if ( F_108 ( V_7 , & V_197 , V_204 ) ) {
V_163 = & V_205 ;
} else
V_163 = & V_197 ;
F_109 ( V_2 , V_127 , V_7 , V_163 , & V_206 , V_207 , 0 ) ;
memcpy ( F_110 ( V_127 , sizeof( V_201 ) ) , V_201 , sizeof( V_201 ) ) ;
F_111 ( V_127 , F_112 ( V_127 ) - V_127 -> V_208 ) ;
F_110 ( V_127 , sizeof( * V_196 ) ) ;
V_196 = (struct V_195 * ) F_96 ( V_127 ) ;
V_196 -> V_209 = V_136 ;
V_196 -> V_210 = 0 ;
V_196 -> V_211 = 0 ;
V_196 -> V_212 = 0 ;
V_196 -> V_213 = 0 ;
return V_127 ;
}
static void F_113 ( struct V_126 * V_127 )
{
struct V_162 * V_214 = F_92 ( V_127 ) ;
struct V_195 * V_196 =
(struct V_195 * ) F_96 ( V_127 ) ;
int V_161 , V_215 ;
struct V_30 * V_31 ;
struct V_12 * V_12 = F_102 ( V_127 -> V_7 ) ;
int V_13 ;
struct V_216 V_217 ;
struct V_218 * V_21 ;
F_5 () ;
V_31 = F_22 ( V_127 -> V_7 ) ;
F_114 ( V_12 , V_31 , V_219 , V_127 -> V_160 ) ;
V_161 = ( V_127 -> V_220 - V_127 -> V_221 ) - sizeof( * V_214 ) ;
V_215 = V_127 -> V_220 - V_127 -> V_222 ;
V_214 -> V_161 = F_115 ( V_161 ) ;
V_196 -> V_211 = F_116 ( & V_214 -> V_163 , & V_214 -> V_223 , V_215 ,
V_131 ,
F_117 ( F_96 ( V_127 ) ,
V_215 , 0 ) ) ;
F_118 ( V_12 -> V_193 . V_194 , & V_217 , V_136 ,
& F_92 ( V_127 ) -> V_163 , & F_92 ( V_127 ) -> V_223 ,
V_127 -> V_7 -> V_3 ) ;
V_21 = F_119 ( V_127 -> V_7 , NULL , & V_217 ) ;
V_13 = 0 ;
if ( F_120 ( V_21 ) ) {
V_13 = F_121 ( V_21 ) ;
V_21 = NULL ;
}
F_122 ( V_127 , V_21 ) ;
if ( V_13 )
goto V_224;
V_161 = V_127 -> V_160 ;
V_13 = F_123 ( V_225 , V_226 , V_127 , NULL , V_127 -> V_7 ,
V_227 ) ;
V_228:
if ( ! V_13 ) {
F_124 ( V_12 , V_31 , V_136 ) ;
F_125 ( V_12 , V_31 , V_229 ) ;
F_126 ( V_12 , V_31 , V_230 , V_161 ) ;
} else
F_127 ( V_12 , V_31 , V_231 ) ;
F_8 () ;
return;
V_224:
F_128 ( V_127 ) ;
goto V_228;
}
static int F_129 ( struct V_87 * V_43 , int type , int V_232 , int V_233 )
{
return sizeof( struct V_234 ) + 16 * F_100 ( V_43 , type , V_232 , V_233 ) ;
}
static struct V_126 * F_130 ( struct V_126 * V_127 , struct V_87 * V_43 ,
int type , struct V_234 * * V_235 )
{
struct V_6 * V_7 = V_43 -> V_31 -> V_7 ;
struct V_195 * V_196 ;
struct V_234 * V_236 ;
if ( ! V_127 )
V_127 = F_101 ( V_7 , V_7 -> V_237 ) ;
if ( ! V_127 )
return NULL ;
V_236 = (struct V_234 * ) F_110 ( V_127 , sizeof( struct V_234 ) ) ;
V_236 -> V_238 = type ;
V_236 -> V_239 = 0 ;
V_236 -> V_240 = 0 ;
V_236 -> V_241 = V_43 -> V_94 ;
V_196 = (struct V_195 * ) F_96 ( V_127 ) ;
V_196 -> V_213 = F_115 ( F_91 ( V_196 -> V_213 ) + 1 ) ;
* V_235 = V_236 ;
return V_127 ;
}
static struct V_126 * F_131 ( struct V_126 * V_127 , struct V_87 * V_43 ,
int type , int V_184 , int V_185 )
{
struct V_6 * V_7 = V_43 -> V_31 -> V_7 ;
struct V_195 * V_196 ;
struct V_234 * V_236 = NULL ;
struct V_103 * V_104 , * V_113 , * V_242 , * * V_243 ;
int V_150 , V_244 , V_245 , V_246 , V_247 ;
if ( V_43 -> V_92 & V_97 )
return V_127 ;
V_246 = type == V_186 ||
type == V_187 ;
V_247 = type == V_187 ||
type == V_189 ;
V_244 = V_150 = 0 ;
V_243 = V_185 ? & V_43 -> V_105 : & V_43 -> V_106 ;
if ( ! * V_243 )
goto V_248;
V_196 = V_127 ? (struct V_195 * ) F_96 ( V_127 ) : NULL ;
if ( V_247 ) {
if ( V_196 && V_196 -> V_213 &&
F_132 ( V_127 ) < F_129 ( V_43 , type , V_184 , V_185 ) ) {
if ( V_127 )
F_113 ( V_127 ) ;
V_127 = F_101 ( V_7 , V_7 -> V_237 ) ;
}
}
V_245 = 1 ;
V_242 = NULL ;
for ( V_104 = * V_243 ; V_104 ; V_104 = V_113 ) {
struct V_4 * V_249 ;
V_113 = V_104 -> V_107 ;
if ( ! F_99 ( V_43 , V_104 , type , V_184 , V_185 ) ) {
V_242 = V_104 ;
continue;
}
if ( V_246 )
V_104 -> V_152 = 0 ;
if ( F_132 ( V_127 ) < sizeof( * V_249 ) +
V_245 * sizeof( struct V_234 ) ) {
if ( V_247 && ! V_245 )
break;
if ( V_236 )
V_236 -> V_240 = F_115 ( V_150 ) ;
if ( V_127 )
F_113 ( V_127 ) ;
V_127 = F_101 ( V_7 , V_7 -> V_237 ) ;
V_245 = 1 ;
V_150 = 0 ;
}
if ( V_245 ) {
V_127 = F_130 ( V_127 , V_43 , type , & V_236 ) ;
V_245 = 0 ;
}
if ( ! V_127 )
return NULL ;
V_249 = (struct V_4 * ) F_110 ( V_127 , sizeof( * V_249 ) ) ;
* V_249 = V_104 -> V_137 ;
V_150 ++ ; V_244 ++ ;
if ( ( type == V_190 ||
type == V_191 ) && V_104 -> V_108 ) {
V_104 -> V_108 -- ;
if ( ( V_185 || V_184 ) && V_104 -> V_108 == 0 ) {
if ( V_242 )
V_242 -> V_107 = V_104 -> V_107 ;
else
* V_243 = V_104 -> V_107 ;
F_48 ( V_104 ) ;
continue;
}
}
V_242 = V_104 ;
}
V_248:
if ( ! V_244 ) {
if ( type == V_190 ||
type == V_191 )
return V_127 ;
if ( V_43 -> V_98 || V_246 ) {
if ( V_127 && F_132 ( V_127 ) < sizeof( struct V_234 ) ) {
F_113 ( V_127 ) ;
V_127 = NULL ;
}
V_127 = F_130 ( V_127 , V_43 , type , & V_236 ) ;
}
}
if ( V_236 )
V_236 -> V_240 = F_115 ( V_150 ) ;
if ( V_246 )
V_43 -> V_92 &= ~ V_151 ;
return V_127 ;
}
static void F_133 ( struct V_30 * V_31 , struct V_87 * V_43 )
{
struct V_126 * V_127 = NULL ;
int type ;
if ( ! V_43 ) {
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_115 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( V_43 -> V_92 & V_97 )
continue;
F_50 ( & V_43 -> V_91 ) ;
if ( V_43 -> V_121 [ V_24 ] )
type = V_187 ;
else
type = V_186 ;
V_127 = F_131 ( V_127 , V_43 , type , 0 , 0 ) ;
F_53 ( & V_43 -> V_91 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
} else {
F_50 ( & V_43 -> V_91 ) ;
if ( V_43 -> V_121 [ V_24 ] )
type = V_187 ;
else
type = V_186 ;
V_127 = F_131 ( V_127 , V_43 , type , 0 , 0 ) ;
F_53 ( & V_43 -> V_91 ) ;
}
if ( V_127 )
F_113 ( V_127 ) ;
}
static void F_134 ( struct V_103 * * V_250 )
{
struct V_103 * V_242 , * V_113 , * V_104 ;
V_242 = NULL ;
for ( V_104 = * V_250 ; V_104 ; V_104 = V_113 ) {
V_113 = V_104 -> V_107 ;
if ( V_104 -> V_108 == 0 ) {
if ( V_242 )
V_242 -> V_107 = V_104 -> V_107 ;
else
* V_250 = V_104 -> V_107 ;
F_48 ( V_104 ) ;
} else
V_242 = V_104 ;
}
}
static void F_135 ( struct V_30 * V_31 )
{
struct V_87 * V_43 , * V_112 , * V_251 ;
struct V_126 * V_127 = NULL ;
int type , V_252 ;
F_28 ( & V_31 -> V_36 ) ;
F_16 ( & V_31 -> V_109 ) ;
V_112 = NULL ;
for ( V_43 = V_31 -> V_110 ; V_43 ; V_43 = V_251 ) {
V_251 = V_43 -> V_18 ;
if ( V_43 -> V_102 == V_60 ) {
type = V_191 ;
V_252 = V_191 ;
V_127 = F_131 ( V_127 , V_43 , type , 1 , 0 ) ;
V_127 = F_131 ( V_127 , V_43 , V_252 , 1 , 1 ) ;
}
if ( V_43 -> V_98 ) {
if ( V_43 -> V_102 == V_24 ) {
type = V_188 ;
V_127 = F_131 ( V_127 , V_43 , type , 1 , 0 ) ;
}
V_43 -> V_98 -- ;
if ( V_43 -> V_98 == 0 ) {
F_134 ( & V_43 -> V_105 ) ;
F_134 ( & V_43 -> V_106 ) ;
}
}
if ( V_43 -> V_98 == 0 && ! V_43 -> V_105 &&
! V_43 -> V_106 ) {
if ( V_112 )
V_112 -> V_18 = V_251 ;
else
V_31 -> V_110 = V_251 ;
F_47 ( V_43 -> V_31 ) ;
F_48 ( V_43 ) ;
} else
V_112 = V_43 ;
}
F_18 ( & V_31 -> V_109 ) ;
for ( V_43 = V_31 -> V_115 ; V_43 ; V_43 = V_43 -> V_18 ) {
F_50 ( & V_43 -> V_91 ) ;
if ( V_43 -> V_121 [ V_24 ] ) {
type = V_191 ;
V_252 = V_190 ;
} else {
type = V_190 ;
V_252 = V_191 ;
}
V_127 = F_131 ( V_127 , V_43 , type , 0 , 0 ) ;
V_127 = F_131 ( V_127 , V_43 , V_252 , 0 , 1 ) ;
if ( V_43 -> V_98 ) {
if ( V_43 -> V_102 == V_24 )
type = V_189 ;
else
type = V_188 ;
V_127 = F_131 ( V_127 , V_43 , type , 0 , 0 ) ;
V_43 -> V_98 -- ;
}
F_53 ( & V_43 -> V_91 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
if ( ! V_127 )
return;
( void ) F_113 ( V_127 ) ;
}
static void F_136 ( struct V_4 * V_5 , struct V_6 * V_7 , int type )
{
struct V_12 * V_12 = F_102 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_193 . V_194 ;
struct V_30 * V_31 ;
struct V_126 * V_127 ;
struct V_156 * V_253 ;
const struct V_4 * V_254 , * V_163 ;
struct V_4 V_197 ;
int V_198 = F_103 ( V_7 ) ;
int V_199 = V_7 -> V_200 ;
int V_13 , V_160 , V_161 , V_255 ;
T_3 V_201 [ 8 ] = { V_131 , 0 ,
V_202 , 2 , 0 , 0 ,
V_203 , 0 } ;
struct V_216 V_217 ;
struct V_218 * V_21 ;
if ( type == V_135 )
V_254 = & V_256 ;
else
V_254 = V_5 ;
V_160 = sizeof( struct V_129 ) + sizeof( struct V_4 ) ;
V_161 = V_160 + sizeof( V_201 ) ;
V_255 = sizeof( struct V_162 ) + V_161 ;
F_5 () ;
F_114 ( V_12 , F_22 ( V_7 ) ,
V_219 , V_255 ) ;
F_8 () ;
V_127 = F_106 ( V_2 , V_198 + V_199 + V_255 , 1 , & V_13 ) ;
if ( V_127 == NULL ) {
F_5 () ;
F_137 ( V_12 , F_22 ( V_7 ) ,
V_231 ) ;
F_8 () ;
return;
}
F_107 ( V_127 , V_198 ) ;
if ( F_108 ( V_7 , & V_197 , V_204 ) ) {
V_163 = & V_205 ;
} else
V_163 = & V_197 ;
F_109 ( V_2 , V_127 , V_7 , V_163 , V_254 , V_207 , V_161 ) ;
memcpy ( F_110 ( V_127 , sizeof( V_201 ) ) , V_201 , sizeof( V_201 ) ) ;
V_253 = (struct V_156 * ) F_110 ( V_127 , sizeof( struct V_156 ) ) ;
memset ( V_253 , 0 , sizeof( struct V_156 ) ) ;
V_253 -> V_257 = type ;
V_253 -> V_165 = * V_5 ;
V_253 -> V_258 = F_116 ( V_163 , V_254 , V_160 ,
V_131 ,
F_117 ( V_253 , V_160 , 0 ) ) ;
F_5 () ;
V_31 = F_22 ( V_127 -> V_7 ) ;
F_118 ( V_2 , & V_217 , type ,
& F_92 ( V_127 ) -> V_163 , & F_92 ( V_127 ) -> V_223 ,
V_127 -> V_7 -> V_3 ) ;
V_21 = F_119 ( V_127 -> V_7 , NULL , & V_217 ) ;
if ( F_120 ( V_21 ) ) {
V_13 = F_121 ( V_21 ) ;
goto V_224;
}
F_122 ( V_127 , V_21 ) ;
V_13 = F_123 ( V_225 , V_226 , V_127 , NULL , V_127 -> V_7 ,
V_227 ) ;
V_228:
if ( ! V_13 ) {
F_138 ( V_12 , V_31 , type ) ;
F_139 ( V_12 , V_31 , V_229 ) ;
F_114 ( V_12 , V_31 , V_230 , V_255 ) ;
} else
F_137 ( V_12 , V_31 , V_231 ) ;
F_8 () ;
return;
V_224:
F_128 ( V_127 ) ;
goto V_228;
}
static int F_140 ( struct V_87 * V_43 , int V_23 ,
const struct V_4 * V_259 )
{
struct V_103 * V_104 , * V_242 ;
int V_49 = 0 ;
V_242 = NULL ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( F_7 ( & V_104 -> V_137 , V_259 ) )
break;
V_242 = V_104 ;
}
if ( ! V_104 || V_104 -> V_138 [ V_23 ] == 0 ) {
return - V_260 ;
}
V_104 -> V_138 [ V_23 ] -- ;
if ( ! V_104 -> V_138 [ V_60 ] && ! V_104 -> V_138 [ V_24 ] ) {
struct V_30 * V_31 = V_43 -> V_31 ;
if ( V_242 )
V_242 -> V_107 = V_104 -> V_107 ;
else
V_43 -> V_106 = V_104 -> V_107 ;
if ( V_104 -> V_261 && ! ( V_43 -> V_92 & V_97 ) &&
! F_54 ( V_31 ) ) {
V_104 -> V_108 = V_31 -> V_99 ;
V_104 -> V_107 = V_43 -> V_105 ;
V_43 -> V_105 = V_104 ;
V_49 = 1 ;
} else
F_48 ( V_104 ) ;
}
return V_49 ;
}
static int F_33 ( struct V_30 * V_31 , const struct V_4 * V_111 ,
int V_23 , int V_262 , const struct V_4 * V_259 ,
int V_263 )
{
struct V_87 * V_43 ;
int V_264 = 0 ;
int V_47 , V_13 ;
if ( ! V_31 )
return - V_22 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_115 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( F_7 ( V_111 , & V_43 -> V_94 ) )
break;
}
if ( ! V_43 ) {
F_29 ( & V_31 -> V_36 ) ;
return - V_260 ;
}
F_50 ( & V_43 -> V_91 ) ;
F_141 ( V_43 ) ;
if ( ! V_263 ) {
if ( ! V_43 -> V_121 [ V_23 ] ) {
F_53 ( & V_43 -> V_91 ) ;
F_29 ( & V_31 -> V_36 ) ;
return - V_14 ;
}
V_43 -> V_121 [ V_23 ] -- ;
}
V_13 = 0 ;
for ( V_47 = 0 ; V_47 < V_262 ; V_47 ++ ) {
int V_49 = F_140 ( V_43 , V_23 , & V_259 [ V_47 ] ) ;
V_264 |= V_49 > 0 ;
if ( ! V_13 && V_49 < 0 )
V_13 = V_49 ;
}
if ( V_43 -> V_102 == V_24 &&
V_43 -> V_121 [ V_24 ] == 0 &&
V_43 -> V_121 [ V_60 ] ) {
struct V_103 * V_104 ;
V_43 -> V_102 = V_60 ;
V_43 -> V_98 = V_31 -> V_99 ;
V_31 -> V_172 = V_43 -> V_98 ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 )
V_104 -> V_108 = 0 ;
F_56 ( V_43 -> V_31 ) ;
} else if ( F_142 ( V_43 ) || V_264 )
F_56 ( V_43 -> V_31 ) ;
F_53 ( & V_43 -> V_91 ) ;
F_29 ( & V_31 -> V_36 ) ;
return V_13 ;
}
static int F_143 ( struct V_87 * V_43 , int V_23 ,
const struct V_4 * V_259 )
{
struct V_103 * V_104 , * V_242 ;
V_242 = NULL ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( F_7 ( & V_104 -> V_137 , V_259 ) )
break;
V_242 = V_104 ;
}
if ( ! V_104 ) {
V_104 = F_64 ( sizeof( * V_104 ) , V_67 ) ;
if ( ! V_104 )
return - V_62 ;
V_104 -> V_137 = * V_259 ;
if ( V_242 ) {
V_242 -> V_107 = V_104 ;
} else
V_43 -> V_106 = V_104 ;
}
V_104 -> V_138 [ V_23 ] ++ ;
return 0 ;
}
static void F_141 ( struct V_87 * V_43 )
{
struct V_103 * V_104 ;
int V_265 = V_43 -> V_121 [ V_24 ] ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 )
if ( V_43 -> V_121 [ V_24 ] ) {
V_104 -> V_261 = V_265 ==
V_104 -> V_138 [ V_24 ] &&
! V_104 -> V_138 [ V_60 ] ;
} else
V_104 -> V_261 = V_104 -> V_138 [ V_60 ] != 0 ;
}
static int F_142 ( struct V_87 * V_43 )
{
struct V_103 * V_104 , * V_266 ;
int V_265 = V_43 -> V_121 [ V_24 ] ;
int V_267 = V_43 -> V_31 -> V_99 ;
int V_268 , V_49 ;
V_49 = 0 ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 ) {
if ( V_43 -> V_121 [ V_24 ] ) {
V_268 = V_265 == V_104 -> V_138 [ V_24 ] &&
! V_104 -> V_138 [ V_60 ] ;
} else
V_268 = V_104 -> V_138 [ V_60 ] != 0 ;
if ( V_268 ) {
if ( ! V_104 -> V_261 ) {
struct V_103 * V_269 = NULL ;
for ( V_266 = V_43 -> V_105 ; V_266 ;
V_266 = V_266 -> V_107 ) {
if ( F_7 ( & V_266 -> V_137 ,
& V_104 -> V_137 ) )
break;
V_269 = V_266 ;
}
if ( V_266 ) {
if ( V_269 )
V_269 -> V_107 = V_266 -> V_107 ;
else
V_43 -> V_105 = V_266 -> V_107 ;
F_48 ( V_266 ) ;
}
V_104 -> V_108 = V_267 ;
V_49 ++ ;
}
} else if ( V_104 -> V_261 ) {
V_104 -> V_108 = 0 ;
for ( V_266 = V_43 -> V_105 ; V_266 ; V_266 = V_266 -> V_107 )
if ( F_7 ( & V_266 -> V_137 ,
& V_104 -> V_137 ) )
break;
if ( ! V_266 ) {
V_266 = F_144 ( sizeof( * V_266 ) , V_67 ) ;
if ( ! V_266 )
continue;
* V_266 = * V_104 ;
V_266 -> V_107 = V_43 -> V_105 ;
V_43 -> V_105 = V_266 ;
}
V_266 -> V_108 = V_267 ;
V_49 ++ ;
}
}
return V_49 ;
}
static int F_32 ( struct V_30 * V_31 , const struct V_4 * V_111 ,
int V_23 , int V_262 , const struct V_4 * V_259 ,
int V_263 )
{
struct V_87 * V_43 ;
int V_270 ;
int V_47 , V_13 ;
if ( ! V_31 )
return - V_22 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_43 = V_31 -> V_115 ; V_43 ; V_43 = V_43 -> V_18 ) {
if ( F_7 ( V_111 , & V_43 -> V_94 ) )
break;
}
if ( ! V_43 ) {
F_29 ( & V_31 -> V_36 ) ;
return - V_260 ;
}
F_50 ( & V_43 -> V_91 ) ;
F_141 ( V_43 ) ;
V_270 = V_43 -> V_102 == V_24 ;
if ( ! V_263 )
V_43 -> V_121 [ V_23 ] ++ ;
V_13 = 0 ;
for ( V_47 = 0 ; V_47 < V_262 ; V_47 ++ ) {
V_13 = F_143 ( V_43 , V_23 , & V_259 [ V_47 ] ) ;
if ( V_13 )
break;
}
if ( V_13 ) {
int V_48 ;
if ( ! V_263 )
V_43 -> V_121 [ V_23 ] -- ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
( void ) F_140 ( V_43 , V_23 , & V_259 [ V_47 ] ) ;
} else if ( V_270 != ( V_43 -> V_121 [ V_24 ] != 0 ) ) {
struct V_103 * V_104 ;
if ( V_43 -> V_121 [ V_24 ] )
V_43 -> V_102 = V_24 ;
else if ( V_43 -> V_121 [ V_60 ] )
V_43 -> V_102 = V_60 ;
V_43 -> V_98 = V_31 -> V_99 ;
V_31 -> V_172 = V_43 -> V_98 ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_104 -> V_107 )
V_104 -> V_108 = 0 ;
F_56 ( V_31 ) ;
} else if ( F_142 ( V_43 ) )
F_56 ( V_31 ) ;
F_53 ( & V_43 -> V_91 ) ;
F_29 ( & V_31 -> V_36 ) ;
return V_13 ;
}
static void F_62 ( struct V_87 * V_43 )
{
struct V_103 * V_104 , * V_271 ;
for ( V_104 = V_43 -> V_105 ; V_104 ; V_104 = V_271 ) {
V_271 = V_104 -> V_107 ;
F_48 ( V_104 ) ;
}
V_43 -> V_105 = NULL ;
for ( V_104 = V_43 -> V_106 ; V_104 ; V_104 = V_271 ) {
V_271 = V_104 -> V_107 ;
F_48 ( V_104 ) ;
}
V_43 -> V_106 = NULL ;
V_43 -> V_102 = V_24 ;
V_43 -> V_121 [ V_60 ] = 0 ;
V_43 -> V_121 [ V_24 ] = 1 ;
}
static void F_55 ( struct V_87 * V_123 )
{
unsigned long V_143 ;
if ( V_123 -> V_92 & V_97 )
return;
F_136 ( & V_123 -> V_94 , V_123 -> V_31 -> V_7 , V_134 ) ;
V_143 = F_83 () % V_272 ;
F_50 ( & V_123 -> V_91 ) ;
if ( F_60 ( & V_123 -> V_100 ) ) {
F_61 ( & V_123 -> V_88 ) ;
V_143 = V_123 -> V_100 . V_146 - V_120 ;
}
if ( ! F_84 ( & V_123 -> V_100 , V_120 + V_143 ) )
F_87 ( & V_123 -> V_88 ) ;
V_123 -> V_92 |= V_147 | V_183 ;
F_53 ( & V_123 -> V_91 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_8 * V_273 ,
struct V_30 * V_31 )
{
int V_13 ;
if ( ! V_273 -> V_26 ) {
return F_33 ( V_31 , & V_273 -> V_5 , V_273 -> V_23 , 0 , NULL , 0 ) ;
}
V_13 = F_33 ( V_31 , & V_273 -> V_5 , V_273 -> V_23 ,
V_273 -> V_26 -> V_58 , V_273 -> V_26 -> V_59 , 0 ) ;
F_13 ( V_2 , V_273 -> V_26 , F_35 ( V_273 -> V_26 -> V_63 ) ) ;
V_273 -> V_26 = NULL ;
return V_13 ;
}
static void F_59 ( struct V_87 * V_123 )
{
if ( F_54 ( V_123 -> V_31 ) ) {
if ( V_123 -> V_92 & V_183 )
F_136 ( & V_123 -> V_94 , V_123 -> V_31 -> V_7 ,
V_135 ) ;
} else {
F_63 ( V_123 -> V_31 , V_123 ) ;
F_56 ( V_123 -> V_31 ) ;
}
}
static void F_145 ( unsigned long V_208 )
{
struct V_30 * V_31 = (struct V_30 * ) V_208 ;
V_31 -> V_141 = 0 ;
F_133 ( V_31 , NULL ) ;
F_95 ( V_31 ) ;
}
static void F_146 ( unsigned long V_208 )
{
struct V_30 * V_31 = (struct V_30 * ) V_208 ;
F_135 ( V_31 ) ;
if ( V_31 -> V_172 ) {
V_31 -> V_172 -- ;
if ( V_31 -> V_172 )
F_85 ( V_31 , V_31 -> V_140 ) ;
}
F_95 ( V_31 ) ;
}
static void F_56 ( struct V_30 * V_31 )
{
if ( F_54 ( V_31 ) )
return;
V_31 -> V_172 = V_31 -> V_99 ;
F_85 ( V_31 , 1 ) ;
}
static void V_117 ( unsigned long V_208 )
{
struct V_87 * V_123 = (struct V_87 * ) V_208 ;
if ( F_54 ( V_123 -> V_31 ) )
F_136 ( & V_123 -> V_94 , V_123 -> V_31 -> V_7 , V_134 ) ;
else
F_133 ( V_123 -> V_31 , V_123 ) ;
F_16 ( & V_123 -> V_91 ) ;
V_123 -> V_92 |= V_183 ;
V_123 -> V_92 &= ~ V_147 ;
F_18 ( & V_123 -> V_91 ) ;
F_45 ( V_123 ) ;
}
void F_147 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_47 = V_31 -> V_115 ; V_47 ; V_47 = V_47 -> V_18 )
F_57 ( V_47 ) ;
F_29 ( & V_31 -> V_36 ) ;
}
void F_148 ( struct V_30 * V_31 )
{
F_149 ( V_31 ) ;
}
void F_150 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_28 ( & V_31 -> V_36 ) ;
V_31 -> V_172 = 0 ;
if ( F_60 ( & V_31 -> V_144 ) )
F_95 ( V_31 ) ;
V_31 -> V_141 = 0 ;
if ( F_60 ( & V_31 -> V_142 ) )
F_95 ( V_31 ) ;
for ( V_47 = V_31 -> V_115 ; V_47 ; V_47 = V_47 -> V_18 )
F_57 ( V_47 ) ;
F_29 ( & V_31 -> V_36 ) ;
F_68 ( V_31 ) ;
}
void F_149 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_28 ( & V_31 -> V_36 ) ;
for ( V_47 = V_31 -> V_115 ; V_47 ; V_47 = V_47 -> V_18 )
F_49 ( V_47 ) ;
F_29 ( & V_31 -> V_36 ) ;
}
void F_151 ( struct V_30 * V_31 )
{
F_70 ( & V_31 -> V_36 ) ;
F_65 ( & V_31 -> V_109 ) ;
V_31 -> V_141 = 0 ;
F_72 ( & V_31 -> V_142 , F_145 ,
( unsigned long ) V_31 ) ;
V_31 -> V_110 = NULL ;
V_31 -> V_172 = 0 ;
F_72 ( & V_31 -> V_144 , F_146 ,
( unsigned long ) V_31 ) ;
V_31 -> V_99 = V_274 ;
V_31 -> V_140 = V_272 ;
V_31 -> V_171 = 0 ;
F_71 ( & V_31 -> V_36 ) ;
}
void F_152 ( struct V_30 * V_31 )
{
struct V_87 * V_47 ;
F_150 ( V_31 ) ;
F_24 ( V_31 , & V_275 ) ;
if ( V_31 -> V_276 . V_277 )
F_24 ( V_31 , & V_256 ) ;
F_70 ( & V_31 -> V_36 ) ;
while ( ( V_47 = V_31 -> V_115 ) != NULL ) {
V_31 -> V_115 = V_47 -> V_18 ;
F_71 ( & V_31 -> V_36 ) ;
F_57 ( V_47 ) ;
F_45 ( V_47 ) ;
F_70 ( & V_31 -> V_36 ) ;
}
F_71 ( & V_31 -> V_36 ) ;
}
static inline struct V_87 * F_153 ( struct V_278 * V_279 )
{
struct V_87 * V_101 = NULL ;
struct V_280 * V_281 = F_154 ( V_279 ) ;
struct V_12 * V_12 = F_155 ( V_279 ) ;
V_281 -> V_31 = NULL ;
F_156 (net, state->dev) {
struct V_30 * V_31 ;
V_31 = F_22 ( V_281 -> V_7 ) ;
if ( ! V_31 )
continue;
F_28 ( & V_31 -> V_36 ) ;
V_101 = V_31 -> V_115 ;
if ( V_101 ) {
V_281 -> V_31 = V_31 ;
break;
}
F_29 ( & V_31 -> V_36 ) ;
}
return V_101 ;
}
static struct V_87 * F_157 ( struct V_278 * V_279 , struct V_87 * V_101 )
{
struct V_280 * V_281 = F_154 ( V_279 ) ;
V_101 = V_101 -> V_18 ;
while ( ! V_101 ) {
if ( F_158 ( V_281 -> V_31 != NULL ) )
F_29 ( & V_281 -> V_31 -> V_36 ) ;
V_281 -> V_7 = F_159 ( V_281 -> V_7 ) ;
if ( ! V_281 -> V_7 ) {
V_281 -> V_31 = NULL ;
break;
}
V_281 -> V_31 = F_22 ( V_281 -> V_7 ) ;
if ( ! V_281 -> V_31 )
continue;
F_28 ( & V_281 -> V_31 -> V_36 ) ;
V_101 = V_281 -> V_31 -> V_115 ;
}
return V_101 ;
}
static struct V_87 * F_160 ( struct V_278 * V_279 , T_4 V_282 )
{
struct V_87 * V_101 = F_153 ( V_279 ) ;
if ( V_101 )
while ( V_282 && ( V_101 = F_157 ( V_279 , V_101 ) ) != NULL )
-- V_282 ;
return V_282 ? NULL : V_101 ;
}
static void * F_161 ( struct V_278 * V_279 , T_4 * V_282 )
__acquires( T_5 )
{
F_5 () ;
return F_160 ( V_279 , * V_282 ) ;
}
static void * F_162 ( struct V_278 * V_279 , void * V_283 , T_4 * V_282 )
{
struct V_87 * V_101 = F_157 ( V_279 , V_283 ) ;
++ * V_282 ;
return V_101 ;
}
static void F_163 ( struct V_278 * V_279 , void * V_283 )
__releases( T_5 )
{
struct V_280 * V_281 = F_154 ( V_279 ) ;
if ( F_158 ( V_281 -> V_31 != NULL ) ) {
F_29 ( & V_281 -> V_31 -> V_36 ) ;
V_281 -> V_31 = NULL ;
}
V_281 -> V_7 = NULL ;
F_8 () ;
}
static int F_164 ( struct V_278 * V_279 , void * V_283 )
{
struct V_87 * V_101 = (struct V_87 * ) V_283 ;
struct V_280 * V_281 = F_154 ( V_279 ) ;
F_165 ( V_279 ,
L_1 ,
V_281 -> V_7 -> V_3 , V_281 -> V_7 -> V_284 ,
& V_101 -> V_94 ,
V_101 -> V_116 , V_101 -> V_92 ,
( V_101 -> V_92 & V_147 ) ?
F_166 ( V_101 -> V_100 . V_146 - V_120 ) : 0 ) ;
return 0 ;
}
static int F_167 ( struct V_285 * V_285 , struct V_286 * V_286 )
{
return F_168 ( V_285 , V_286 , & V_287 ,
sizeof( struct V_280 ) ) ;
}
static inline struct V_103 * F_169 ( struct V_278 * V_279 )
{
struct V_103 * V_104 = NULL ;
struct V_87 * V_101 = NULL ;
struct V_288 * V_281 = F_170 ( V_279 ) ;
struct V_12 * V_12 = F_155 ( V_279 ) ;
V_281 -> V_31 = NULL ;
V_281 -> V_101 = NULL ;
F_156 (net, state->dev) {
struct V_30 * V_31 ;
V_31 = F_22 ( V_281 -> V_7 ) ;
if ( F_171 ( V_31 == NULL ) )
continue;
F_28 ( & V_31 -> V_36 ) ;
V_101 = V_31 -> V_115 ;
if ( F_158 ( V_101 != NULL ) ) {
F_50 ( & V_101 -> V_91 ) ;
V_104 = V_101 -> V_106 ;
if ( F_158 ( V_104 != NULL ) ) {
V_281 -> V_101 = V_101 ;
V_281 -> V_31 = V_31 ;
break;
}
F_53 ( & V_101 -> V_91 ) ;
}
F_29 ( & V_31 -> V_36 ) ;
}
return V_104 ;
}
static struct V_103 * F_172 ( struct V_278 * V_279 , struct V_103 * V_104 )
{
struct V_288 * V_281 = F_170 ( V_279 ) ;
V_104 = V_104 -> V_107 ;
while ( ! V_104 ) {
F_53 ( & V_281 -> V_101 -> V_91 ) ;
V_281 -> V_101 = V_281 -> V_101 -> V_18 ;
while ( ! V_281 -> V_101 ) {
if ( F_158 ( V_281 -> V_31 != NULL ) )
F_29 ( & V_281 -> V_31 -> V_36 ) ;
V_281 -> V_7 = F_159 ( V_281 -> V_7 ) ;
if ( ! V_281 -> V_7 ) {
V_281 -> V_31 = NULL ;
goto V_228;
}
V_281 -> V_31 = F_22 ( V_281 -> V_7 ) ;
if ( ! V_281 -> V_31 )
continue;
F_28 ( & V_281 -> V_31 -> V_36 ) ;
V_281 -> V_101 = V_281 -> V_31 -> V_115 ;
}
if ( ! V_281 -> V_101 )
break;
F_50 ( & V_281 -> V_101 -> V_91 ) ;
V_104 = V_281 -> V_101 -> V_106 ;
}
V_228:
return V_104 ;
}
static struct V_103 * F_173 ( struct V_278 * V_279 , T_4 V_282 )
{
struct V_103 * V_104 = F_169 ( V_279 ) ;
if ( V_104 )
while ( V_282 && ( V_104 = F_172 ( V_279 , V_104 ) ) != NULL )
-- V_282 ;
return V_282 ? NULL : V_104 ;
}
static void * F_174 ( struct V_278 * V_279 , T_4 * V_282 )
__acquires( T_5 )
{
F_5 () ;
return * V_282 ? F_173 ( V_279 , * V_282 - 1 ) : V_289 ;
}
static void * F_175 ( struct V_278 * V_279 , void * V_283 , T_4 * V_282 )
{
struct V_103 * V_104 ;
if ( V_283 == V_289 )
V_104 = F_169 ( V_279 ) ;
else
V_104 = F_172 ( V_279 , V_283 ) ;
++ * V_282 ;
return V_104 ;
}
static void F_176 ( struct V_278 * V_279 , void * V_283 )
__releases( T_5 )
{
struct V_288 * V_281 = F_170 ( V_279 ) ;
if ( F_158 ( V_281 -> V_101 != NULL ) ) {
F_53 ( & V_281 -> V_101 -> V_91 ) ;
V_281 -> V_101 = NULL ;
}
if ( F_158 ( V_281 -> V_31 != NULL ) ) {
F_29 ( & V_281 -> V_31 -> V_36 ) ;
V_281 -> V_31 = NULL ;
}
V_281 -> V_7 = NULL ;
F_8 () ;
}
static int F_177 ( struct V_278 * V_279 , void * V_283 )
{
struct V_103 * V_104 = (struct V_103 * ) V_283 ;
struct V_288 * V_281 = F_170 ( V_279 ) ;
if ( V_283 == V_289 ) {
F_165 ( V_279 ,
L_2
L_3 , L_4 ,
L_5 , L_6 ,
L_7 , L_8 , L_9 ) ;
} else {
F_165 ( V_279 ,
L_10 ,
V_281 -> V_7 -> V_3 , V_281 -> V_7 -> V_284 ,
& V_281 -> V_101 -> V_94 ,
& V_104 -> V_137 ,
V_104 -> V_138 [ V_60 ] ,
V_104 -> V_138 [ V_24 ] ) ;
}
return 0 ;
}
static int F_178 ( struct V_285 * V_285 , struct V_286 * V_286 )
{
return F_168 ( V_285 , V_286 , & V_290 ,
sizeof( struct V_288 ) ) ;
}
static int T_6 F_179 ( struct V_12 * V_12 )
{
int V_13 ;
V_13 = - V_17 ;
if ( ! F_180 ( V_12 , L_11 , V_291 , & V_292 ) )
goto V_228;
if ( ! F_180 ( V_12 , L_12 , V_291 ,
& V_293 ) )
goto V_294;
V_13 = 0 ;
V_228:
return V_13 ;
V_294:
F_181 ( V_12 , L_11 ) ;
goto V_228;
}
static void T_7 F_182 ( struct V_12 * V_12 )
{
F_181 ( V_12 , L_12 ) ;
F_181 ( V_12 , L_11 ) ;
}
static inline int F_179 ( struct V_12 * V_12 )
{
return 0 ;
}
static inline void F_182 ( struct V_12 * V_12 )
{
}
static int T_6 F_183 ( struct V_12 * V_12 )
{
int V_13 ;
V_13 = F_184 ( & V_12 -> V_193 . V_194 , V_295 ,
V_296 , V_131 , V_12 ) ;
if ( V_13 < 0 ) {
F_185 ( V_297
L_13 ,
V_13 ) ;
goto V_228;
}
F_2 ( V_12 -> V_193 . V_194 ) -> V_298 = 1 ;
V_13 = F_179 ( V_12 ) ;
if ( V_13 )
goto V_299;
V_228:
return V_13 ;
V_299:
F_186 ( V_12 -> V_193 . V_194 ) ;
goto V_228;
}
static void T_7 F_187 ( struct V_12 * V_12 )
{
F_186 ( V_12 -> V_193 . V_194 ) ;
F_182 ( V_12 ) ;
}
int T_8 F_188 ( void )
{
return F_189 ( & V_300 ) ;
}
void F_190 ( void )
{
F_191 ( & V_300 ) ;
}
