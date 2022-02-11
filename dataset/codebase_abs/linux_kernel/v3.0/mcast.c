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
F_10 ( & V_9 -> V_5 , V_5 ) ;
F_5 () ;
if ( V_3 == 0 ) {
struct V_19 * V_20 ;
V_20 = F_11 ( V_12 , V_5 , NULL , 0 , 0 ) ;
if ( V_20 ) {
V_7 = V_20 -> V_21 ;
F_12 ( & V_20 -> V_22 ) ;
}
} else
V_7 = F_13 ( V_12 , V_3 ) ;
if ( V_7 == NULL ) {
F_8 () ;
F_14 ( V_2 , V_9 , sizeof( * V_9 ) ) ;
return - V_23 ;
}
V_9 -> V_3 = V_7 -> V_3 ;
V_9 -> V_24 = V_25 ;
F_15 ( & V_9 -> V_26 ) ;
V_9 -> V_27 = NULL ;
V_13 = F_16 ( V_7 , V_5 ) ;
if ( V_13 ) {
F_8 () ;
F_14 ( V_2 , V_9 , sizeof( * V_9 ) ) ;
return V_13 ;
}
F_17 ( & V_28 ) ;
V_9 -> V_18 = V_11 -> V_29 ;
F_18 ( V_11 -> V_29 , V_9 ) ;
F_19 ( & V_28 ) ;
F_8 () ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_8 T_1 * * V_30 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
F_17 ( & V_28 ) ;
for ( V_30 = & V_11 -> V_29 ;
( V_9 = F_21 ( * V_30 ,
F_22 ( & V_28 ) ) ) != NULL ;
V_30 = & V_9 -> V_18 ) {
if ( ( V_3 == 0 || V_9 -> V_3 == V_3 ) &&
F_7 ( & V_9 -> V_5 , V_5 ) ) {
struct V_6 * V_7 ;
* V_30 = V_9 -> V_18 ;
F_19 ( & V_28 ) ;
F_5 () ;
V_7 = F_13 ( V_12 , V_9 -> V_3 ) ;
if ( V_7 != NULL ) {
struct V_31 * V_32 = F_23 ( V_7 ) ;
( void ) F_24 ( V_2 , V_9 , V_32 ) ;
if ( V_32 )
F_25 ( V_32 , & V_9 -> V_5 ) ;
} else
( void ) F_24 ( V_2 , V_9 , NULL ) ;
F_8 () ;
F_26 ( sizeof( * V_9 ) , & V_2 -> V_33 ) ;
F_27 ( V_9 , V_34 ) ;
return 0 ;
}
}
F_19 ( & V_28 ) ;
return - V_35 ;
}
static struct V_31 * F_28 ( struct V_12 * V_12 ,
const struct V_4 * V_36 ,
int V_3 )
{
struct V_6 * V_7 = NULL ;
struct V_31 * V_32 = NULL ;
if ( V_3 == 0 ) {
struct V_19 * V_20 = F_11 ( V_12 , V_36 , NULL , 0 , 0 ) ;
if ( V_20 ) {
V_7 = V_20 -> V_21 ;
F_29 ( V_7 ) ;
F_12 ( & V_20 -> V_22 ) ;
}
} else
V_7 = F_13 ( V_12 , V_3 ) ;
if ( ! V_7 )
return NULL ;
V_32 = F_23 ( V_7 ) ;
if ( ! V_32 )
return NULL ;
F_30 ( & V_32 -> V_37 ) ;
if ( V_32 -> V_38 ) {
F_31 ( & V_32 -> V_37 ) ;
return NULL ;
}
return V_32 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
F_17 ( & V_28 ) ;
while ( ( V_9 = F_21 ( V_11 -> V_29 ,
F_22 ( & V_28 ) ) ) != NULL ) {
struct V_6 * V_7 ;
V_11 -> V_29 = V_9 -> V_18 ;
F_19 ( & V_28 ) ;
F_5 () ;
V_7 = F_13 ( V_12 , V_9 -> V_3 ) ;
if ( V_7 ) {
struct V_31 * V_32 = F_23 ( V_7 ) ;
( void ) F_24 ( V_2 , V_9 , V_32 ) ;
if ( V_32 )
F_25 ( V_32 , & V_9 -> V_5 ) ;
} else
( void ) F_24 ( V_2 , V_9 , NULL ) ;
F_8 () ;
F_26 ( sizeof( * V_9 ) , & V_2 -> V_33 ) ;
F_27 ( V_9 , V_34 ) ;
F_17 ( & V_28 ) ;
}
F_19 ( & V_28 ) ;
}
int F_33 ( int V_39 , int V_40 , struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_4 * V_43 , * V_36 ;
struct V_8 * V_44 ;
struct V_31 * V_32 ;
struct V_10 * V_45 = F_2 ( V_2 ) ;
struct V_46 * V_47 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
int V_48 , V_49 , V_50 ;
int V_51 = 0 ;
int V_52 = 0 ;
int V_13 ;
V_43 = & ( (struct V_53 * ) & V_42 -> V_54 ) -> V_55 ;
V_36 = & ( (struct V_53 * ) & V_42 -> V_56 ) -> V_55 ;
if ( ! F_4 ( V_36 ) )
return - V_14 ;
F_5 () ;
V_32 = F_28 ( V_12 , V_36 , V_42 -> V_57 ) ;
if ( ! V_32 ) {
F_8 () ;
return - V_23 ;
}
V_13 = - V_35 ;
F_6 (inet6, pmc) {
if ( V_42 -> V_57 && V_44 -> V_3 != V_42 -> V_57 )
continue;
if ( F_7 ( & V_44 -> V_5 , V_36 ) )
break;
}
if ( ! V_44 ) {
V_13 = - V_14 ;
goto V_58;
}
if ( V_44 -> V_27 ) {
if ( V_44 -> V_24 != V_40 ) {
V_13 = - V_14 ;
goto V_58;
}
} else if ( V_44 -> V_24 != V_40 ) {
F_34 ( V_32 , V_36 , V_40 , 0 , NULL , 0 ) ;
F_35 ( V_32 , V_36 , V_44 -> V_24 , 0 , NULL , 0 ) ;
V_44 -> V_24 = V_40 ;
}
F_36 ( & V_44 -> V_26 ) ;
V_52 = 1 ;
V_47 = V_44 -> V_27 ;
if ( ! V_39 ) {
if ( ! V_47 )
goto V_58;
V_50 = ! 0 ;
for ( V_48 = 0 ; V_48 < V_47 -> V_59 ; V_48 ++ ) {
V_50 = memcmp ( & V_47 -> V_60 [ V_48 ] , V_43 ,
sizeof( struct V_4 ) ) ;
if ( V_50 == 0 )
break;
}
if ( V_50 )
goto V_58;
if ( V_47 -> V_59 == 1 && V_40 == V_61 ) {
V_51 = 1 ;
goto V_58;
}
F_35 ( V_32 , V_36 , V_40 , 1 , V_43 , 1 ) ;
for ( V_49 = V_48 + 1 ; V_49 < V_47 -> V_59 ; V_49 ++ )
V_47 -> V_60 [ V_49 - 1 ] = V_47 -> V_60 [ V_49 ] ;
V_47 -> V_59 -- ;
V_13 = 0 ;
goto V_58;
}
if ( V_47 && V_47 -> V_59 >= V_62 ) {
V_13 = - V_63 ;
goto V_58;
}
if ( ! V_47 || V_47 -> V_59 == V_47 -> V_64 ) {
struct V_46 * V_65 ;
int V_66 = V_67 ;
if ( V_47 )
V_66 += V_47 -> V_64 ;
V_65 = F_9 ( V_2 , F_37 ( V_66 ) , V_68 ) ;
if ( ! V_65 ) {
V_13 = - V_63 ;
goto V_58;
}
V_65 -> V_64 = V_66 ;
V_65 -> V_59 = V_66 - V_67 ;
if ( V_47 ) {
for ( V_48 = 0 ; V_48 < V_47 -> V_59 ; V_48 ++ )
V_65 -> V_60 [ V_48 ] = V_47 -> V_60 [ V_48 ] ;
F_14 ( V_2 , V_47 , F_37 ( V_47 -> V_64 ) ) ;
}
V_44 -> V_27 = V_47 = V_65 ;
}
V_50 = 1 ;
for ( V_48 = 0 ; V_48 < V_47 -> V_59 ; V_48 ++ ) {
V_50 = memcmp ( & V_47 -> V_60 [ V_48 ] , V_43 , sizeof( struct V_4 ) ) ;
if ( V_50 == 0 )
break;
}
if ( V_50 == 0 )
goto V_58;
for ( V_49 = V_47 -> V_59 - 1 ; V_49 >= V_48 ; V_49 -- )
V_47 -> V_60 [ V_49 + 1 ] = V_47 -> V_60 [ V_49 ] ;
V_47 -> V_60 [ V_48 ] = * V_43 ;
V_47 -> V_59 ++ ;
V_13 = 0 ;
F_34 ( V_32 , V_36 , V_40 , 1 , V_43 , 1 ) ;
V_58:
if ( V_52 )
F_38 ( & V_44 -> V_26 ) ;
F_31 ( & V_32 -> V_37 ) ;
F_8 () ;
if ( V_51 )
return F_20 ( V_2 , V_42 -> V_57 , V_36 ) ;
return V_13 ;
}
int F_39 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
const struct V_4 * V_36 ;
struct V_8 * V_44 ;
struct V_31 * V_32 ;
struct V_10 * V_45 = F_2 ( V_2 ) ;
struct V_46 * V_65 , * V_47 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
int V_51 = 0 ;
int V_48 , V_13 ;
V_36 = & ( (struct V_53 * ) & V_70 -> V_71 ) -> V_55 ;
if ( ! F_4 ( V_36 ) )
return - V_14 ;
if ( V_70 -> V_72 != V_61 &&
V_70 -> V_72 != V_25 )
return - V_14 ;
F_5 () ;
V_32 = F_28 ( V_12 , V_36 , V_70 -> V_73 ) ;
if ( ! V_32 ) {
F_8 () ;
return - V_23 ;
}
V_13 = 0 ;
if ( V_70 -> V_72 == V_61 && V_70 -> V_74 == 0 ) {
V_51 = 1 ;
goto V_58;
}
F_6 (inet6, pmc) {
if ( V_44 -> V_3 != V_70 -> V_73 )
continue;
if ( F_7 ( & V_44 -> V_5 , V_36 ) )
break;
}
if ( ! V_44 ) {
V_13 = - V_14 ;
goto V_58;
}
if ( V_70 -> V_74 ) {
V_65 = F_9 ( V_2 , F_37 ( V_70 -> V_74 ) ,
V_68 ) ;
if ( ! V_65 ) {
V_13 = - V_63 ;
goto V_58;
}
V_65 -> V_64 = V_65 -> V_59 = V_70 -> V_74 ;
for ( V_48 = 0 ; V_48 < V_65 -> V_59 ; ++ V_48 ) {
struct V_53 * V_75 ;
V_75 = (struct V_53 * ) & V_70 -> V_76 [ V_48 ] ;
V_65 -> V_60 [ V_48 ] = V_75 -> V_55 ;
}
V_13 = F_34 ( V_32 , V_36 , V_70 -> V_72 ,
V_65 -> V_59 , V_65 -> V_60 , 0 ) ;
if ( V_13 ) {
F_14 ( V_2 , V_65 , F_37 ( V_65 -> V_64 ) ) ;
goto V_58;
}
} else {
V_65 = NULL ;
( void ) F_34 ( V_32 , V_36 , V_70 -> V_72 , 0 , NULL , 0 ) ;
}
F_36 ( & V_44 -> V_26 ) ;
V_47 = V_44 -> V_27 ;
if ( V_47 ) {
( void ) F_35 ( V_32 , V_36 , V_44 -> V_24 ,
V_47 -> V_59 , V_47 -> V_60 , 0 ) ;
F_14 ( V_2 , V_47 , F_37 ( V_47 -> V_64 ) ) ;
} else
( void ) F_35 ( V_32 , V_36 , V_44 -> V_24 , 0 , NULL , 0 ) ;
V_44 -> V_27 = V_65 ;
V_44 -> V_24 = V_70 -> V_72 ;
F_38 ( & V_44 -> V_26 ) ;
V_13 = 0 ;
V_58:
F_31 ( & V_32 -> V_37 ) ;
F_8 () ;
if ( V_51 )
V_13 = F_20 ( V_2 , V_70 -> V_73 , V_36 ) ;
return V_13 ;
}
int F_40 ( struct V_1 * V_2 , struct V_69 * V_70 ,
struct V_69 T_2 * V_77 , int T_2 * V_78 )
{
int V_13 , V_48 , V_66 , V_79 ;
const struct V_4 * V_36 ;
struct V_8 * V_44 ;
struct V_31 * V_32 ;
struct V_10 * V_45 = F_2 ( V_2 ) ;
struct V_46 * V_47 ;
struct V_12 * V_12 = F_3 ( V_2 ) ;
V_36 = & ( (struct V_53 * ) & V_70 -> V_71 ) -> V_55 ;
if ( ! F_4 ( V_36 ) )
return - V_14 ;
F_5 () ;
V_32 = F_28 ( V_12 , V_36 , V_70 -> V_73 ) ;
if ( ! V_32 ) {
F_8 () ;
return - V_23 ;
}
V_13 = - V_35 ;
F_6 (inet6, pmc) {
if ( V_44 -> V_3 != V_70 -> V_73 )
continue;
if ( F_7 ( V_36 , & V_44 -> V_5 ) )
break;
}
if ( ! V_44 )
goto V_58;
V_70 -> V_72 = V_44 -> V_24 ;
V_47 = V_44 -> V_27 ;
V_66 = V_47 ? V_47 -> V_59 : 0 ;
F_31 ( & V_32 -> V_37 ) ;
F_8 () ;
V_79 = V_66 < V_70 -> V_74 ? V_66 : V_70 -> V_74 ;
V_70 -> V_74 = V_66 ;
if ( F_41 ( F_42 ( V_79 ) , V_78 ) ||
F_43 ( V_77 , V_70 , F_42 ( 0 ) ) ) {
return - V_80 ;
}
for ( V_48 = 0 ; V_48 < V_79 ; V_48 ++ ) {
struct V_53 * V_75 ;
struct V_81 V_82 ;
V_75 = (struct V_53 * ) & V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_75 -> V_83 = V_84 ;
V_75 -> V_55 = V_47 -> V_60 [ V_48 ] ;
if ( F_43 ( & V_77 -> V_76 [ V_48 ] , & V_82 , sizeof( V_82 ) ) )
return - V_80 ;
}
return 0 ;
V_58:
F_31 ( & V_32 -> V_37 ) ;
F_8 () ;
return V_13 ;
}
int F_44 ( struct V_1 * V_2 , const struct V_4 * V_85 ,
const struct V_4 * V_86 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_8 * V_87 ;
struct V_46 * V_47 ;
int V_50 = 1 ;
F_5 () ;
F_6 (np, mc) {
if ( F_7 ( & V_87 -> V_5 , V_85 ) )
break;
}
if ( ! V_87 ) {
F_8 () ;
return 1 ;
}
F_45 ( & V_87 -> V_26 ) ;
V_47 = V_87 -> V_27 ;
if ( ! V_47 ) {
V_50 = V_87 -> V_24 == V_25 ;
} else {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_47 -> V_59 ; V_48 ++ ) {
if ( F_7 ( & V_47 -> V_60 [ V_48 ] , V_86 ) )
break;
}
if ( V_87 -> V_24 == V_61 && V_48 >= V_47 -> V_59 )
V_50 = 0 ;
if ( V_87 -> V_24 == V_25 && V_48 < V_47 -> V_59 )
V_50 = 0 ;
}
F_46 ( & V_87 -> V_26 ) ;
F_8 () ;
return V_50 ;
}
static void F_47 ( struct V_88 * V_87 )
{
if ( F_48 ( & V_87 -> V_89 ) ) {
F_49 ( V_87 -> V_32 ) ;
F_50 ( V_87 ) ;
}
}
static void F_51 ( struct V_88 * V_87 )
{
struct V_6 * V_7 = V_87 -> V_32 -> V_7 ;
char V_90 [ V_91 ] ;
F_52 ( & V_87 -> V_92 ) ;
if ( ! ( V_87 -> V_93 & V_94 ) ) {
V_87 -> V_93 |= V_94 ;
if ( F_53 ( & V_87 -> V_95 , V_90 , V_7 , 0 ) == 0 )
F_54 ( V_7 , V_90 ) ;
}
F_55 ( & V_87 -> V_92 ) ;
if ( ! ( V_7 -> V_96 & V_97 ) || ( V_87 -> V_93 & V_98 ) )
return;
if ( F_56 ( V_87 -> V_32 ) ) {
F_57 ( V_87 ) ;
return;
}
V_87 -> V_99 = V_87 -> V_32 -> V_100 ;
F_58 ( V_87 -> V_32 ) ;
}
static void F_59 ( struct V_88 * V_87 )
{
struct V_6 * V_7 = V_87 -> V_32 -> V_7 ;
char V_90 [ V_91 ] ;
F_52 ( & V_87 -> V_92 ) ;
if ( V_87 -> V_93 & V_94 ) {
V_87 -> V_93 &= ~ V_94 ;
if ( F_53 ( & V_87 -> V_95 , V_90 , V_7 , 0 ) == 0 )
F_60 ( V_7 , V_90 ) ;
}
if ( V_87 -> V_93 & V_98 )
goto V_58;
F_55 ( & V_87 -> V_92 ) ;
if ( ! V_87 -> V_32 -> V_38 )
F_61 ( V_87 ) ;
F_52 ( & V_87 -> V_92 ) ;
if ( F_62 ( & V_87 -> V_101 ) )
F_63 ( & V_87 -> V_89 ) ;
V_58:
F_64 ( V_87 ) ;
F_55 ( & V_87 -> V_92 ) ;
}
static void F_65 ( struct V_31 * V_32 , struct V_88 * V_102 )
{
struct V_88 * V_44 ;
V_44 = F_66 ( sizeof( * V_44 ) , V_68 ) ;
if ( ! V_44 )
return;
F_52 ( & V_102 -> V_92 ) ;
F_67 ( & V_44 -> V_92 ) ;
V_44 -> V_32 = V_102 -> V_32 ;
F_68 ( V_32 ) ;
V_44 -> V_95 = V_102 -> V_95 ;
V_44 -> V_99 = V_32 -> V_100 ;
V_44 -> V_103 = V_102 -> V_103 ;
if ( V_44 -> V_103 == V_61 ) {
struct V_104 * V_105 ;
V_44 -> V_106 = V_102 -> V_106 ;
V_44 -> V_107 = V_102 -> V_107 ;
V_102 -> V_106 = V_102 -> V_107 = NULL ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
V_105 -> V_109 = V_44 -> V_99 ;
}
F_55 ( & V_102 -> V_92 ) ;
F_52 ( & V_32 -> V_110 ) ;
V_44 -> V_18 = V_32 -> V_111 ;
V_32 -> V_111 = V_44 ;
F_55 ( & V_32 -> V_110 ) ;
}
static void F_69 ( struct V_31 * V_32 , const struct V_4 * V_112 )
{
struct V_88 * V_44 , * V_113 ;
struct V_104 * V_105 , * V_114 ;
F_52 ( & V_32 -> V_110 ) ;
V_113 = NULL ;
for ( V_44 = V_32 -> V_111 ; V_44 ; V_44 = V_44 -> V_18 ) {
if ( F_7 ( & V_44 -> V_95 , V_112 ) )
break;
V_113 = V_44 ;
}
if ( V_44 ) {
if ( V_113 )
V_113 -> V_18 = V_44 -> V_18 ;
else
V_32 -> V_111 = V_44 -> V_18 ;
}
F_55 ( & V_32 -> V_110 ) ;
if ( V_44 ) {
for ( V_105 = V_44 -> V_106 ; V_105 ; V_105 = V_114 ) {
V_114 = V_105 -> V_108 ;
F_50 ( V_105 ) ;
}
F_49 ( V_44 -> V_32 ) ;
F_50 ( V_44 ) ;
}
}
static void F_70 ( struct V_31 * V_32 )
{
struct V_88 * V_44 , * V_115 ;
F_52 ( & V_32 -> V_110 ) ;
V_44 = V_32 -> V_111 ;
V_32 -> V_111 = NULL ;
F_55 ( & V_32 -> V_110 ) ;
for (; V_44 ; V_44 = V_115 ) {
V_115 = V_44 -> V_18 ;
F_64 ( V_44 ) ;
F_49 ( V_44 -> V_32 ) ;
F_50 ( V_44 ) ;
}
F_30 ( & V_32 -> V_37 ) ;
for ( V_44 = V_32 -> V_116 ; V_44 ; V_44 = V_44 -> V_18 ) {
struct V_104 * V_105 , * V_114 ;
F_52 ( & V_44 -> V_92 ) ;
V_105 = V_44 -> V_106 ;
V_44 -> V_106 = NULL ;
F_55 ( & V_44 -> V_92 ) ;
for (; V_105 ; V_105 = V_114 ) {
V_114 = V_105 -> V_108 ;
F_50 ( V_105 ) ;
}
}
F_31 ( & V_32 -> V_37 ) ;
}
int F_16 ( struct V_6 * V_7 , const struct V_4 * V_5 )
{
struct V_88 * V_87 ;
struct V_31 * V_32 ;
V_32 = F_71 ( V_7 ) ;
if ( V_32 == NULL )
return - V_14 ;
F_72 ( & V_32 -> V_37 ) ;
if ( V_32 -> V_38 ) {
F_73 ( & V_32 -> V_37 ) ;
F_49 ( V_32 ) ;
return - V_23 ;
}
for ( V_87 = V_32 -> V_116 ; V_87 ; V_87 = V_87 -> V_18 ) {
if ( F_7 ( & V_87 -> V_95 , V_5 ) ) {
V_87 -> V_117 ++ ;
F_73 ( & V_32 -> V_37 ) ;
F_34 ( V_32 , & V_87 -> V_95 , V_25 , 0 ,
NULL , 0 ) ;
F_49 ( V_32 ) ;
return 0 ;
}
}
V_87 = F_66 ( sizeof( struct V_88 ) , V_68 ) ;
if ( V_87 == NULL ) {
F_73 ( & V_32 -> V_37 ) ;
F_49 ( V_32 ) ;
return - V_17 ;
}
F_74 ( & V_87 -> V_101 , V_118 , ( unsigned long ) V_87 ) ;
F_10 ( & V_87 -> V_95 , V_5 ) ;
V_87 -> V_32 = V_32 ;
V_87 -> V_117 = 1 ;
V_87 -> V_119 = V_87 -> V_120 = V_121 ;
F_75 ( & V_87 -> V_89 , 2 ) ;
F_67 ( & V_87 -> V_92 ) ;
V_87 -> V_103 = V_25 ;
V_87 -> V_122 [ V_25 ] = 1 ;
if ( F_76 ( & V_87 -> V_95 ) ||
F_77 ( & V_87 -> V_95 ) < V_123 )
V_87 -> V_93 |= V_98 ;
V_87 -> V_18 = V_32 -> V_116 ;
V_32 -> V_116 = V_87 ;
F_73 ( & V_32 -> V_37 ) ;
F_69 ( V_32 , & V_87 -> V_95 ) ;
F_51 ( V_87 ) ;
F_47 ( V_87 ) ;
return 0 ;
}
int F_25 ( struct V_31 * V_32 , const struct V_4 * V_5 )
{
struct V_88 * V_124 , * * V_125 ;
F_72 ( & V_32 -> V_37 ) ;
for ( V_125 = & V_32 -> V_116 ; ( V_124 = * V_125 ) != NULL ; V_125 = & V_124 -> V_18 ) {
if ( F_7 ( & V_124 -> V_95 , V_5 ) ) {
if ( -- V_124 -> V_117 == 0 ) {
* V_125 = V_124 -> V_18 ;
F_73 ( & V_32 -> V_37 ) ;
F_59 ( V_124 ) ;
F_47 ( V_124 ) ;
return 0 ;
}
F_73 ( & V_32 -> V_37 ) ;
return 0 ;
}
}
F_73 ( & V_32 -> V_37 ) ;
return - V_126 ;
}
int F_78 ( struct V_6 * V_7 , const struct V_4 * V_5 )
{
struct V_31 * V_32 ;
int V_13 ;
F_5 () ;
V_32 = F_23 ( V_7 ) ;
if ( ! V_32 )
V_13 = - V_23 ;
else
V_13 = F_25 ( V_32 , V_5 ) ;
F_8 () ;
return V_13 ;
}
int F_79 ( struct V_127 * V_128 , int V_129 )
{
struct V_130 * V_131 ;
if ( V_129 != V_132 )
return 0 ;
if ( ! F_80 ( V_128 , sizeof( struct V_130 ) ) )
return 0 ;
V_131 = F_81 ( V_128 ) ;
switch ( V_131 -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
case V_137 :
return 1 ;
default:
break;
}
return 0 ;
}
int F_82 ( struct V_6 * V_7 , const struct V_4 * V_36 ,
const struct V_4 * V_86 )
{
struct V_31 * V_32 ;
struct V_88 * V_87 ;
int V_50 = 0 ;
F_5 () ;
V_32 = F_23 ( V_7 ) ;
if ( V_32 ) {
F_30 ( & V_32 -> V_37 ) ;
for ( V_87 = V_32 -> V_116 ; V_87 ; V_87 = V_87 -> V_18 ) {
if ( F_7 ( & V_87 -> V_95 , V_36 ) )
break;
}
if ( V_87 ) {
if ( V_86 && ! F_83 ( V_86 ) ) {
struct V_104 * V_105 ;
F_52 ( & V_87 -> V_92 ) ;
for ( V_105 = V_87 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( F_7 ( & V_105 -> V_138 , V_86 ) )
break;
}
if ( V_105 )
V_50 = V_105 -> V_139 [ V_61 ] ||
V_105 -> V_139 [ V_25 ] !=
V_87 -> V_122 [ V_25 ] ;
else
V_50 = V_87 -> V_122 [ V_25 ] != 0 ;
F_55 ( & V_87 -> V_92 ) ;
} else
V_50 = 1 ;
}
F_31 ( & V_32 -> V_37 ) ;
}
F_8 () ;
return V_50 ;
}
static void F_84 ( struct V_31 * V_32 )
{
int V_140 = F_85 () % V_32 -> V_141 ;
V_32 -> V_142 = 1 ;
if ( ! F_86 ( & V_32 -> V_143 , V_121 + V_140 + 2 ) )
F_68 ( V_32 ) ;
}
static void F_87 ( struct V_31 * V_32 , int V_144 )
{
int V_140 = F_85 () % V_144 ;
if ( ! F_86 ( & V_32 -> V_145 , V_121 + V_140 + 2 ) )
F_68 ( V_32 ) ;
}
static void F_88 ( struct V_88 * V_124 , unsigned long V_146 )
{
unsigned long V_144 = V_146 ;
if ( F_76 ( & V_124 -> V_95 ) ||
F_77 ( & V_124 -> V_95 ) < V_123 )
return;
if ( F_62 ( & V_124 -> V_101 ) ) {
F_63 ( & V_124 -> V_89 ) ;
V_144 = V_124 -> V_101 . V_147 - V_121 ;
}
if ( V_144 >= V_146 ) {
if ( V_146 )
V_144 = F_85 () % V_146 ;
else
V_144 = 1 ;
}
V_124 -> V_101 . V_147 = V_121 + V_144 ;
if ( ! F_86 ( & V_124 -> V_101 , V_121 + V_144 ) )
F_89 ( & V_124 -> V_89 ) ;
V_124 -> V_93 |= V_148 ;
}
static int F_90 ( struct V_88 * V_44 , int V_149 ,
const struct V_4 * V_150 )
{
struct V_104 * V_105 ;
int V_48 , V_151 ;
V_151 = 0 ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( V_151 == V_149 )
break;
for ( V_48 = 0 ; V_48 < V_149 ; V_48 ++ ) {
if ( V_44 -> V_122 [ V_61 ] ||
V_44 -> V_122 [ V_25 ] !=
V_105 -> V_139 [ V_25 ] )
continue;
if ( F_7 ( & V_150 [ V_48 ] , & V_105 -> V_138 ) ) {
V_151 ++ ;
break;
}
}
}
V_44 -> V_93 &= ~ V_152 ;
if ( V_151 == V_149 )
return 0 ;
return 1 ;
}
static int F_91 ( struct V_88 * V_44 , int V_149 ,
const struct V_4 * V_150 )
{
struct V_104 * V_105 ;
int V_48 , V_151 ;
if ( V_44 -> V_103 == V_25 )
return F_90 ( V_44 , V_149 , V_150 ) ;
V_151 = 0 ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( V_151 == V_149 )
break;
for ( V_48 = 0 ; V_48 < V_149 ; V_48 ++ ) {
if ( F_7 ( & V_150 [ V_48 ] , & V_105 -> V_138 ) ) {
V_105 -> V_153 = 1 ;
V_151 ++ ;
break;
}
}
}
if ( ! V_151 ) {
V_44 -> V_93 &= ~ V_152 ;
return 0 ;
}
V_44 -> V_93 |= V_152 ;
return 1 ;
}
int F_92 ( struct V_127 * V_128 )
{
struct V_154 * V_155 = NULL ;
struct V_88 * V_124 ;
const struct V_4 * V_36 ;
unsigned long V_156 ;
struct V_31 * V_32 ;
struct V_157 * V_158 ;
int V_159 ;
int V_160 = 0 ;
int V_161 ;
if ( ! F_80 ( V_128 , sizeof( struct V_4 ) ) )
return - V_14 ;
V_161 = F_93 ( F_94 ( V_128 ) -> V_162 ) + sizeof( struct V_163 ) ;
V_161 -= F_95 ( V_128 ) ;
if ( ! ( F_96 ( & F_94 ( V_128 ) -> V_164 ) & V_165 ) )
return - V_14 ;
V_32 = F_23 ( V_128 -> V_7 ) ;
if ( V_32 == NULL )
return 0 ;
V_158 = (struct V_157 * ) F_81 ( V_128 ) ;
V_36 = & V_158 -> V_166 ;
V_159 = F_96 ( V_36 ) ;
if ( V_159 != V_167 &&
! ( V_159 & V_168 ) )
return - V_14 ;
if ( V_161 == 24 ) {
int V_169 ;
V_156 = ( F_93 ( V_158 -> V_170 ) * V_171 ) / 1000 ;
V_169 = ( V_32 -> V_100 + 1 ) * V_156 ;
V_32 -> V_172 = V_121 + V_169 ;
V_32 -> V_173 = 0 ;
if ( F_62 ( & V_32 -> V_145 ) )
F_97 ( V_32 ) ;
F_70 ( V_32 ) ;
} else if ( V_161 >= 28 ) {
int V_174 = sizeof( struct V_154 ) -
sizeof( struct V_130 ) ;
if ( ! F_80 ( V_128 , V_174 ) )
return - V_14 ;
V_155 = (struct V_154 * ) F_98 ( V_128 ) ;
V_156 = ( F_99 ( F_93 ( V_155 -> V_175 ) ) * V_171 ) / 1000 ;
if ( ! V_156 )
V_156 = 1 ;
V_32 -> V_141 = V_156 ;
if ( V_155 -> V_176 )
V_32 -> V_100 = V_155 -> V_176 ;
if ( V_159 == V_167 ) {
if ( V_155 -> V_177 )
return - V_14 ;
F_84 ( V_32 ) ;
return 0 ;
}
if ( V_155 -> V_177 != 0 ) {
if ( ! F_80 ( V_128 , V_174 +
F_93 ( V_155 -> V_177 ) * sizeof( struct V_4 ) ) )
return - V_14 ;
V_155 = (struct V_154 * ) F_98 ( V_128 ) ;
V_160 = 1 ;
}
} else
return - V_14 ;
F_30 ( & V_32 -> V_37 ) ;
if ( V_159 == V_167 ) {
for ( V_124 = V_32 -> V_116 ; V_124 ; V_124 = V_124 -> V_18 ) {
F_52 ( & V_124 -> V_92 ) ;
F_88 ( V_124 , V_156 ) ;
F_55 ( & V_124 -> V_92 ) ;
}
} else {
for ( V_124 = V_32 -> V_116 ; V_124 ; V_124 = V_124 -> V_18 ) {
if ( ! F_7 ( V_36 , & V_124 -> V_95 ) )
continue;
F_52 ( & V_124 -> V_92 ) ;
if ( V_124 -> V_93 & V_148 ) {
if ( ! V_160 )
V_124 -> V_93 &= ~ V_152 ;
} else {
if ( V_160 )
V_124 -> V_93 |= V_152 ;
else
V_124 -> V_93 &= ~ V_152 ;
}
if ( ! ( V_124 -> V_93 & V_152 ) ||
F_91 ( V_124 , F_93 ( V_155 -> V_177 ) , V_155 -> V_178 ) )
F_88 ( V_124 , V_156 ) ;
F_55 ( & V_124 -> V_92 ) ;
break;
}
}
F_31 ( & V_32 -> V_37 ) ;
return 0 ;
}
int F_100 ( struct V_127 * V_128 )
{
struct V_88 * V_124 ;
struct V_31 * V_32 ;
struct V_157 * V_158 ;
int V_179 ;
if ( V_128 -> V_180 == V_181 )
return 0 ;
if ( V_128 -> V_180 != V_182 &&
V_128 -> V_180 != V_183 )
return 0 ;
if ( ! F_80 ( V_128 , sizeof( * V_158 ) - sizeof( struct V_130 ) ) )
return - V_14 ;
V_158 = (struct V_157 * ) F_81 ( V_128 ) ;
V_179 = F_96 ( & F_94 ( V_128 ) -> V_164 ) ;
if ( V_179 != V_167 &&
! ( V_179 & V_165 ) )
return - V_14 ;
V_32 = F_23 ( V_128 -> V_7 ) ;
if ( V_32 == NULL )
return - V_23 ;
F_30 ( & V_32 -> V_37 ) ;
for ( V_124 = V_32 -> V_116 ; V_124 ; V_124 = V_124 -> V_18 ) {
if ( F_7 ( & V_124 -> V_95 , & V_158 -> V_166 ) ) {
F_17 ( & V_124 -> V_92 ) ;
if ( F_62 ( & V_124 -> V_101 ) )
F_63 ( & V_124 -> V_89 ) ;
V_124 -> V_93 &= ~ ( V_184 | V_148 ) ;
F_19 ( & V_124 -> V_92 ) ;
break;
}
}
F_31 ( & V_32 -> V_37 ) ;
return 0 ;
}
static int F_101 ( struct V_88 * V_44 , struct V_104 * V_105 , int type ,
int V_185 , int V_186 )
{
switch ( type ) {
case V_187 :
case V_188 :
if ( V_185 || V_186 )
return 0 ;
if ( ! ( ( V_44 -> V_93 & V_152 ) && ! V_105 -> V_153 ) ) {
if ( V_44 -> V_103 == V_61 )
return 1 ;
if ( V_105 -> V_139 [ V_61 ] )
return type == V_187 ;
return V_44 -> V_122 [ V_25 ] ==
V_105 -> V_139 [ V_25 ] ;
}
return 0 ;
case V_189 :
if ( V_185 || V_186 )
return 0 ;
return V_105 -> V_139 [ V_61 ] != 0 ;
case V_190 :
if ( V_185 || V_186 )
return 0 ;
if ( V_44 -> V_122 [ V_25 ] == 0 ||
V_105 -> V_139 [ V_61 ] )
return 0 ;
return V_44 -> V_122 [ V_25 ] ==
V_105 -> V_139 [ V_25 ] ;
case V_191 :
if ( V_185 || ! V_105 -> V_109 )
return 0 ;
return ( V_44 -> V_103 == V_61 ) ^ V_186 ;
case V_192 :
if ( V_44 -> V_103 == V_61 )
return V_185 || ( V_105 -> V_109 && V_186 ) ;
return V_105 -> V_109 && ! V_185 && ! V_186 ;
}
return 0 ;
}
static int
F_102 ( struct V_88 * V_44 , int type , int V_185 , int V_186 )
{
struct V_104 * V_105 ;
int V_151 = 0 ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( ! F_101 ( V_44 , V_105 , type , V_185 , V_186 ) )
continue;
V_151 ++ ;
}
return V_151 ;
}
static struct V_127 * F_103 ( struct V_6 * V_7 , int V_193 )
{
struct V_12 * V_12 = F_104 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_194 . V_195 ;
struct V_127 * V_128 ;
struct V_196 * V_197 ;
struct V_4 V_198 ;
const struct V_4 * V_164 ;
int V_13 ;
T_3 V_199 [ 8 ] = { V_132 , 0 ,
V_200 , 2 , 0 , 0 ,
V_201 , 0 } ;
V_193 += F_105 ( V_7 ) ;
V_193 = F_106 ( int , V_193 , F_107 ( 0 , 0 ) ) ;
V_128 = F_108 ( V_2 , V_193 , 1 , & V_13 ) ;
if ( ! V_128 )
return NULL ;
F_109 ( V_128 , F_110 ( V_7 ) ) ;
if ( F_111 ( V_7 , & V_198 , V_202 ) ) {
V_164 = & V_203 ;
} else
V_164 = & V_198 ;
F_112 ( V_2 , V_128 , V_7 , V_164 , & V_204 , V_205 , 0 ) ;
memcpy ( F_113 ( V_128 , sizeof( V_199 ) ) , V_199 , sizeof( V_199 ) ) ;
F_114 ( V_128 , F_115 ( V_128 ) - V_128 -> V_206 ) ;
F_113 ( V_128 , sizeof( * V_197 ) ) ;
V_197 = (struct V_196 * ) F_98 ( V_128 ) ;
V_197 -> V_207 = V_137 ;
V_197 -> V_208 = 0 ;
V_197 -> V_209 = 0 ;
V_197 -> V_210 = 0 ;
V_197 -> V_211 = 0 ;
return V_128 ;
}
static void F_116 ( struct V_127 * V_128 )
{
struct V_163 * V_212 = F_94 ( V_128 ) ;
struct V_196 * V_197 =
(struct V_196 * ) F_98 ( V_128 ) ;
int V_162 , V_213 ;
struct V_31 * V_32 ;
struct V_12 * V_12 = F_104 ( V_128 -> V_7 ) ;
int V_13 ;
struct V_214 V_215 ;
struct V_216 * V_22 ;
F_5 () ;
V_32 = F_23 ( V_128 -> V_7 ) ;
F_117 ( V_12 , V_32 , V_217 , V_128 -> V_161 ) ;
V_162 = ( V_128 -> V_218 - V_128 -> V_219 ) - sizeof( * V_212 ) ;
V_213 = V_128 -> V_218 - V_128 -> V_220 ;
V_212 -> V_162 = F_118 ( V_162 ) ;
V_197 -> V_209 = F_119 ( & V_212 -> V_164 , & V_212 -> V_221 , V_213 ,
V_132 ,
F_120 ( F_98 ( V_128 ) ,
V_213 , 0 ) ) ;
V_22 = F_121 ( V_128 -> V_7 , NULL , & F_94 ( V_128 ) -> V_221 ) ;
if ( ! V_22 ) {
V_13 = - V_17 ;
goto V_222;
}
F_122 ( V_12 -> V_194 . V_195 , & V_215 , V_137 ,
& F_94 ( V_128 ) -> V_164 , & F_94 ( V_128 ) -> V_221 ,
V_128 -> V_7 -> V_3 ) ;
V_22 = F_123 ( V_12 , V_22 , F_124 ( & V_215 ) , NULL , 0 ) ;
V_13 = 0 ;
if ( F_125 ( V_22 ) ) {
V_13 = F_126 ( V_22 ) ;
V_22 = NULL ;
}
F_127 ( V_128 , V_22 ) ;
if ( V_13 )
goto V_222;
V_162 = V_128 -> V_161 ;
V_13 = F_128 ( V_223 , V_224 , V_128 , NULL , V_128 -> V_7 ,
V_225 ) ;
V_226:
if ( ! V_13 ) {
F_129 ( V_12 , V_32 , V_137 ) ;
F_130 ( V_12 , V_32 , V_227 ) ;
F_131 ( V_12 , V_32 , V_228 , V_162 ) ;
} else
F_132 ( V_12 , V_32 , V_229 ) ;
F_8 () ;
return;
V_222:
F_133 ( V_128 ) ;
goto V_226;
}
static int F_134 ( struct V_88 * V_44 , int type , int V_230 , int V_231 )
{
return sizeof( struct V_232 ) + 16 * F_102 ( V_44 , type , V_230 , V_231 ) ;
}
static struct V_127 * F_135 ( struct V_127 * V_128 , struct V_88 * V_44 ,
int type , struct V_232 * * V_233 )
{
struct V_6 * V_7 = V_44 -> V_32 -> V_7 ;
struct V_196 * V_197 ;
struct V_232 * V_234 ;
if ( ! V_128 )
V_128 = F_103 ( V_7 , V_7 -> V_235 ) ;
if ( ! V_128 )
return NULL ;
V_234 = (struct V_232 * ) F_113 ( V_128 , sizeof( struct V_232 ) ) ;
V_234 -> V_236 = type ;
V_234 -> V_237 = 0 ;
V_234 -> V_238 = 0 ;
V_234 -> V_239 = V_44 -> V_95 ;
V_197 = (struct V_196 * ) F_98 ( V_128 ) ;
V_197 -> V_211 = F_118 ( F_93 ( V_197 -> V_211 ) + 1 ) ;
* V_233 = V_234 ;
return V_128 ;
}
static struct V_127 * F_136 ( struct V_127 * V_128 , struct V_88 * V_44 ,
int type , int V_185 , int V_186 )
{
struct V_6 * V_7 = V_44 -> V_32 -> V_7 ;
struct V_196 * V_197 ;
struct V_232 * V_234 = NULL ;
struct V_104 * V_105 , * V_114 , * V_240 , * * V_241 ;
int V_151 , V_242 , V_243 , V_244 , V_245 ;
if ( V_44 -> V_93 & V_98 )
return V_128 ;
V_244 = type == V_187 ||
type == V_188 ;
V_245 = type == V_188 ||
type == V_190 ;
V_242 = V_151 = 0 ;
V_241 = V_186 ? & V_44 -> V_106 : & V_44 -> V_107 ;
if ( ! * V_241 )
goto V_246;
V_197 = V_128 ? (struct V_196 * ) F_98 ( V_128 ) : NULL ;
if ( V_245 ) {
if ( V_197 && V_197 -> V_211 &&
F_137 ( V_128 ) < F_134 ( V_44 , type , V_185 , V_186 ) ) {
if ( V_128 )
F_116 ( V_128 ) ;
V_128 = F_103 ( V_7 , V_7 -> V_235 ) ;
}
}
V_243 = 1 ;
V_240 = NULL ;
for ( V_105 = * V_241 ; V_105 ; V_105 = V_114 ) {
struct V_4 * V_247 ;
V_114 = V_105 -> V_108 ;
if ( ! F_101 ( V_44 , V_105 , type , V_185 , V_186 ) ) {
V_240 = V_105 ;
continue;
}
if ( V_244 )
V_105 -> V_153 = 0 ;
if ( F_137 ( V_128 ) < sizeof( * V_247 ) +
V_243 * sizeof( struct V_232 ) ) {
if ( V_245 && ! V_243 )
break;
if ( V_234 )
V_234 -> V_238 = F_118 ( V_151 ) ;
if ( V_128 )
F_116 ( V_128 ) ;
V_128 = F_103 ( V_7 , V_7 -> V_235 ) ;
V_243 = 1 ;
V_151 = 0 ;
}
if ( V_243 ) {
V_128 = F_135 ( V_128 , V_44 , type , & V_234 ) ;
V_243 = 0 ;
}
if ( ! V_128 )
return NULL ;
V_247 = (struct V_4 * ) F_113 ( V_128 , sizeof( * V_247 ) ) ;
* V_247 = V_105 -> V_138 ;
V_151 ++ ; V_242 ++ ;
if ( ( type == V_191 ||
type == V_192 ) && V_105 -> V_109 ) {
V_105 -> V_109 -- ;
if ( ( V_186 || V_185 ) && V_105 -> V_109 == 0 ) {
if ( V_240 )
V_240 -> V_108 = V_105 -> V_108 ;
else
* V_241 = V_105 -> V_108 ;
F_50 ( V_105 ) ;
continue;
}
}
V_240 = V_105 ;
}
V_246:
if ( ! V_242 ) {
if ( type == V_191 ||
type == V_192 )
return V_128 ;
if ( V_44 -> V_99 || V_244 ) {
if ( V_128 && F_137 ( V_128 ) < sizeof( struct V_232 ) ) {
F_116 ( V_128 ) ;
V_128 = NULL ;
}
V_128 = F_135 ( V_128 , V_44 , type , & V_234 ) ;
}
}
if ( V_234 )
V_234 -> V_238 = F_118 ( V_151 ) ;
if ( V_244 )
V_44 -> V_93 &= ~ V_152 ;
return V_128 ;
}
static void F_138 ( struct V_31 * V_32 , struct V_88 * V_44 )
{
struct V_127 * V_128 = NULL ;
int type ;
if ( ! V_44 ) {
F_30 ( & V_32 -> V_37 ) ;
for ( V_44 = V_32 -> V_116 ; V_44 ; V_44 = V_44 -> V_18 ) {
if ( V_44 -> V_93 & V_98 )
continue;
F_52 ( & V_44 -> V_92 ) ;
if ( V_44 -> V_122 [ V_25 ] )
type = V_188 ;
else
type = V_187 ;
V_128 = F_136 ( V_128 , V_44 , type , 0 , 0 ) ;
F_55 ( & V_44 -> V_92 ) ;
}
F_31 ( & V_32 -> V_37 ) ;
} else {
F_52 ( & V_44 -> V_92 ) ;
if ( V_44 -> V_122 [ V_25 ] )
type = V_188 ;
else
type = V_187 ;
V_128 = F_136 ( V_128 , V_44 , type , 0 , 0 ) ;
F_55 ( & V_44 -> V_92 ) ;
}
if ( V_128 )
F_116 ( V_128 ) ;
}
static void F_139 ( struct V_104 * * V_248 )
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
F_50 ( V_105 ) ;
} else
V_240 = V_105 ;
}
}
static void F_140 ( struct V_31 * V_32 )
{
struct V_88 * V_44 , * V_113 , * V_249 ;
struct V_127 * V_128 = NULL ;
int type , V_250 ;
F_30 ( & V_32 -> V_37 ) ;
F_17 ( & V_32 -> V_110 ) ;
V_113 = NULL ;
for ( V_44 = V_32 -> V_111 ; V_44 ; V_44 = V_249 ) {
V_249 = V_44 -> V_18 ;
if ( V_44 -> V_103 == V_61 ) {
type = V_192 ;
V_250 = V_192 ;
V_128 = F_136 ( V_128 , V_44 , type , 1 , 0 ) ;
V_128 = F_136 ( V_128 , V_44 , V_250 , 1 , 1 ) ;
}
if ( V_44 -> V_99 ) {
if ( V_44 -> V_103 == V_25 ) {
type = V_189 ;
V_128 = F_136 ( V_128 , V_44 , type , 1 , 0 ) ;
}
V_44 -> V_99 -- ;
if ( V_44 -> V_99 == 0 ) {
F_139 ( & V_44 -> V_106 ) ;
F_139 ( & V_44 -> V_107 ) ;
}
}
if ( V_44 -> V_99 == 0 && ! V_44 -> V_106 &&
! V_44 -> V_107 ) {
if ( V_113 )
V_113 -> V_18 = V_249 ;
else
V_32 -> V_111 = V_249 ;
F_49 ( V_44 -> V_32 ) ;
F_50 ( V_44 ) ;
} else
V_113 = V_44 ;
}
F_19 ( & V_32 -> V_110 ) ;
for ( V_44 = V_32 -> V_116 ; V_44 ; V_44 = V_44 -> V_18 ) {
F_52 ( & V_44 -> V_92 ) ;
if ( V_44 -> V_122 [ V_25 ] ) {
type = V_192 ;
V_250 = V_191 ;
} else {
type = V_191 ;
V_250 = V_192 ;
}
V_128 = F_136 ( V_128 , V_44 , type , 0 , 0 ) ;
V_128 = F_136 ( V_128 , V_44 , V_250 , 0 , 1 ) ;
if ( V_44 -> V_99 ) {
if ( V_44 -> V_103 == V_25 )
type = V_190 ;
else
type = V_189 ;
V_128 = F_136 ( V_128 , V_44 , type , 0 , 0 ) ;
V_44 -> V_99 -- ;
}
F_55 ( & V_44 -> V_92 ) ;
}
F_31 ( & V_32 -> V_37 ) ;
if ( ! V_128 )
return;
( void ) F_116 ( V_128 ) ;
}
static void F_141 ( struct V_4 * V_5 , struct V_6 * V_7 , int type )
{
struct V_12 * V_12 = F_104 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_194 . V_195 ;
struct V_31 * V_32 ;
struct V_127 * V_128 ;
struct V_157 * V_251 ;
const struct V_4 * V_252 , * V_164 ;
struct V_4 V_198 ;
int V_13 , V_161 , V_162 , V_253 ;
T_3 V_199 [ 8 ] = { V_132 , 0 ,
V_200 , 2 , 0 , 0 ,
V_201 , 0 } ;
struct V_214 V_215 ;
struct V_216 * V_22 ;
if ( type == V_136 )
V_252 = & V_254 ;
else
V_252 = V_5 ;
V_161 = sizeof( struct V_130 ) + sizeof( struct V_4 ) ;
V_162 = V_161 + sizeof( V_199 ) ;
V_253 = sizeof( struct V_163 ) + V_162 ;
F_5 () ;
F_117 ( V_12 , F_23 ( V_7 ) ,
V_217 , V_253 ) ;
F_8 () ;
V_128 = F_108 ( V_2 , F_105 ( V_7 ) + V_253 , 1 , & V_13 ) ;
if ( V_128 == NULL ) {
F_5 () ;
F_142 ( V_12 , F_23 ( V_7 ) ,
V_229 ) ;
F_8 () ;
return;
}
F_109 ( V_128 , F_110 ( V_7 ) ) ;
if ( F_111 ( V_7 , & V_198 , V_202 ) ) {
V_164 = & V_203 ;
} else
V_164 = & V_198 ;
F_112 ( V_2 , V_128 , V_7 , V_164 , V_252 , V_205 , V_162 ) ;
memcpy ( F_113 ( V_128 , sizeof( V_199 ) ) , V_199 , sizeof( V_199 ) ) ;
V_251 = (struct V_157 * ) F_113 ( V_128 , sizeof( struct V_157 ) ) ;
memset ( V_251 , 0 , sizeof( struct V_157 ) ) ;
V_251 -> V_255 = type ;
F_10 ( & V_251 -> V_166 , V_5 ) ;
V_251 -> V_256 = F_119 ( V_164 , V_252 , V_161 ,
V_132 ,
F_120 ( V_251 , V_161 , 0 ) ) ;
F_5 () ;
V_32 = F_23 ( V_128 -> V_7 ) ;
V_22 = F_121 ( V_128 -> V_7 , NULL , & F_94 ( V_128 ) -> V_221 ) ;
if ( ! V_22 ) {
V_13 = - V_17 ;
goto V_222;
}
F_122 ( V_2 , & V_215 , type ,
& F_94 ( V_128 ) -> V_164 , & F_94 ( V_128 ) -> V_221 ,
V_128 -> V_7 -> V_3 ) ;
V_22 = F_123 ( V_12 , V_22 , F_124 ( & V_215 ) , NULL , 0 ) ;
if ( F_125 ( V_22 ) ) {
V_13 = F_126 ( V_22 ) ;
goto V_222;
}
F_127 ( V_128 , V_22 ) ;
V_13 = F_128 ( V_223 , V_224 , V_128 , NULL , V_128 -> V_7 ,
V_225 ) ;
V_226:
if ( ! V_13 ) {
F_143 ( V_12 , V_32 , type ) ;
F_144 ( V_12 , V_32 , V_227 ) ;
F_117 ( V_12 , V_32 , V_228 , V_253 ) ;
} else
F_142 ( V_12 , V_32 , V_229 ) ;
F_8 () ;
return;
V_222:
F_133 ( V_128 ) ;
goto V_226;
}
static int F_145 ( struct V_88 * V_44 , int V_24 ,
const struct V_4 * V_257 )
{
struct V_104 * V_105 , * V_240 ;
int V_50 = 0 ;
V_240 = NULL ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( F_7 ( & V_105 -> V_138 , V_257 ) )
break;
V_240 = V_105 ;
}
if ( ! V_105 || V_105 -> V_139 [ V_24 ] == 0 ) {
return - V_258 ;
}
V_105 -> V_139 [ V_24 ] -- ;
if ( ! V_105 -> V_139 [ V_61 ] && ! V_105 -> V_139 [ V_25 ] ) {
struct V_31 * V_32 = V_44 -> V_32 ;
if ( V_240 )
V_240 -> V_108 = V_105 -> V_108 ;
else
V_44 -> V_107 = V_105 -> V_108 ;
if ( V_105 -> V_259 && ! ( V_44 -> V_93 & V_98 ) &&
! F_56 ( V_32 ) ) {
V_105 -> V_109 = V_32 -> V_100 ;
V_105 -> V_108 = V_44 -> V_106 ;
V_44 -> V_106 = V_105 ;
V_50 = 1 ;
} else
F_50 ( V_105 ) ;
}
return V_50 ;
}
static int F_35 ( struct V_31 * V_32 , const struct V_4 * V_112 ,
int V_24 , int V_260 , const struct V_4 * V_257 ,
int V_261 )
{
struct V_88 * V_44 ;
int V_262 = 0 ;
int V_48 , V_13 ;
if ( ! V_32 )
return - V_23 ;
F_30 ( & V_32 -> V_37 ) ;
for ( V_44 = V_32 -> V_116 ; V_44 ; V_44 = V_44 -> V_18 ) {
if ( F_7 ( V_112 , & V_44 -> V_95 ) )
break;
}
if ( ! V_44 ) {
F_31 ( & V_32 -> V_37 ) ;
return - V_258 ;
}
F_52 ( & V_44 -> V_92 ) ;
F_146 ( V_44 ) ;
if ( ! V_261 ) {
if ( ! V_44 -> V_122 [ V_24 ] ) {
F_55 ( & V_44 -> V_92 ) ;
F_31 ( & V_32 -> V_37 ) ;
return - V_14 ;
}
V_44 -> V_122 [ V_24 ] -- ;
}
V_13 = 0 ;
for ( V_48 = 0 ; V_48 < V_260 ; V_48 ++ ) {
int V_50 = F_145 ( V_44 , V_24 , & V_257 [ V_48 ] ) ;
V_262 |= V_50 > 0 ;
if ( ! V_13 && V_50 < 0 )
V_13 = V_50 ;
}
if ( V_44 -> V_103 == V_25 &&
V_44 -> V_122 [ V_25 ] == 0 &&
V_44 -> V_122 [ V_61 ] ) {
struct V_104 * V_105 ;
V_44 -> V_103 = V_61 ;
V_44 -> V_99 = V_32 -> V_100 ;
V_32 -> V_173 = V_44 -> V_99 ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
V_105 -> V_109 = 0 ;
F_58 ( V_44 -> V_32 ) ;
} else if ( F_147 ( V_44 ) || V_262 )
F_58 ( V_44 -> V_32 ) ;
F_55 ( & V_44 -> V_92 ) ;
F_31 ( & V_32 -> V_37 ) ;
return V_13 ;
}
static int F_148 ( struct V_88 * V_44 , int V_24 ,
const struct V_4 * V_257 , int V_261 )
{
struct V_104 * V_105 , * V_240 ;
V_240 = NULL ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( F_7 ( & V_105 -> V_138 , V_257 ) )
break;
V_240 = V_105 ;
}
if ( ! V_105 ) {
V_105 = F_66 ( sizeof( * V_105 ) , V_68 ) ;
if ( ! V_105 )
return - V_63 ;
V_105 -> V_138 = * V_257 ;
if ( V_240 ) {
V_240 -> V_108 = V_105 ;
} else
V_44 -> V_107 = V_105 ;
}
V_105 -> V_139 [ V_24 ] ++ ;
return 0 ;
}
static void F_146 ( struct V_88 * V_44 )
{
struct V_104 * V_105 ;
int V_263 = V_44 -> V_122 [ V_25 ] ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
if ( V_44 -> V_122 [ V_25 ] ) {
V_105 -> V_259 = V_263 ==
V_105 -> V_139 [ V_25 ] &&
! V_105 -> V_139 [ V_61 ] ;
} else
V_105 -> V_259 = V_105 -> V_139 [ V_61 ] != 0 ;
}
static int F_147 ( struct V_88 * V_44 )
{
struct V_104 * V_105 , * V_264 ;
int V_263 = V_44 -> V_122 [ V_25 ] ;
int V_265 = V_44 -> V_32 -> V_100 ;
int V_266 , V_50 ;
V_50 = 0 ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 ) {
if ( V_44 -> V_122 [ V_25 ] ) {
V_266 = V_263 == V_105 -> V_139 [ V_25 ] &&
! V_105 -> V_139 [ V_61 ] ;
} else
V_266 = V_105 -> V_139 [ V_61 ] != 0 ;
if ( V_266 ) {
if ( ! V_105 -> V_259 ) {
struct V_104 * V_267 = NULL ;
for ( V_264 = V_44 -> V_106 ; V_264 ;
V_264 = V_264 -> V_108 ) {
if ( F_7 ( & V_264 -> V_138 ,
& V_105 -> V_138 ) )
break;
V_267 = V_264 ;
}
if ( V_264 ) {
if ( V_267 )
V_267 -> V_108 = V_264 -> V_108 ;
else
V_44 -> V_106 = V_264 -> V_108 ;
F_50 ( V_264 ) ;
}
V_105 -> V_109 = V_265 ;
V_50 ++ ;
}
} else if ( V_105 -> V_259 ) {
V_105 -> V_109 = 0 ;
for ( V_264 = V_44 -> V_106 ; V_264 ; V_264 = V_264 -> V_108 )
if ( F_7 ( & V_264 -> V_138 ,
& V_105 -> V_138 ) )
break;
if ( ! V_264 ) {
V_264 = F_149 ( sizeof( * V_264 ) , V_68 ) ;
if ( ! V_264 )
continue;
* V_264 = * V_105 ;
V_264 -> V_108 = V_44 -> V_106 ;
V_44 -> V_106 = V_264 ;
}
V_264 -> V_109 = V_265 ;
V_50 ++ ;
}
}
return V_50 ;
}
static int F_34 ( struct V_31 * V_32 , const struct V_4 * V_112 ,
int V_24 , int V_260 , const struct V_4 * V_257 ,
int V_261 )
{
struct V_88 * V_44 ;
int V_268 ;
int V_48 , V_13 ;
if ( ! V_32 )
return - V_23 ;
F_30 ( & V_32 -> V_37 ) ;
for ( V_44 = V_32 -> V_116 ; V_44 ; V_44 = V_44 -> V_18 ) {
if ( F_7 ( V_112 , & V_44 -> V_95 ) )
break;
}
if ( ! V_44 ) {
F_31 ( & V_32 -> V_37 ) ;
return - V_258 ;
}
F_52 ( & V_44 -> V_92 ) ;
F_146 ( V_44 ) ;
V_268 = V_44 -> V_103 == V_25 ;
if ( ! V_261 )
V_44 -> V_122 [ V_24 ] ++ ;
V_13 = 0 ;
for ( V_48 = 0 ; V_48 < V_260 ; V_48 ++ ) {
V_13 = F_148 ( V_44 , V_24 , & V_257 [ V_48 ] , V_261 ) ;
if ( V_13 )
break;
}
if ( V_13 ) {
int V_49 ;
if ( ! V_261 )
V_44 -> V_122 [ V_24 ] -- ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
( void ) F_145 ( V_44 , V_24 , & V_257 [ V_48 ] ) ;
} else if ( V_268 != ( V_44 -> V_122 [ V_25 ] != 0 ) ) {
struct V_104 * V_105 ;
if ( V_44 -> V_122 [ V_25 ] )
V_44 -> V_103 = V_25 ;
else if ( V_44 -> V_122 [ V_61 ] )
V_44 -> V_103 = V_61 ;
V_44 -> V_99 = V_32 -> V_100 ;
V_32 -> V_173 = V_44 -> V_99 ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_105 -> V_108 )
V_105 -> V_109 = 0 ;
F_58 ( V_32 ) ;
} else if ( F_147 ( V_44 ) )
F_58 ( V_32 ) ;
F_55 ( & V_44 -> V_92 ) ;
F_31 ( & V_32 -> V_37 ) ;
return V_13 ;
}
static void F_64 ( struct V_88 * V_44 )
{
struct V_104 * V_105 , * V_269 ;
for ( V_105 = V_44 -> V_106 ; V_105 ; V_105 = V_269 ) {
V_269 = V_105 -> V_108 ;
F_50 ( V_105 ) ;
}
V_44 -> V_106 = NULL ;
for ( V_105 = V_44 -> V_107 ; V_105 ; V_105 = V_269 ) {
V_269 = V_105 -> V_108 ;
F_50 ( V_105 ) ;
}
V_44 -> V_107 = NULL ;
V_44 -> V_103 = V_25 ;
V_44 -> V_122 [ V_61 ] = 0 ;
V_44 -> V_122 [ V_25 ] = 1 ;
}
static void F_57 ( struct V_88 * V_124 )
{
unsigned long V_144 ;
if ( V_124 -> V_93 & V_98 )
return;
F_141 ( & V_124 -> V_95 , V_124 -> V_32 -> V_7 , V_135 ) ;
V_144 = F_85 () % V_270 ;
F_52 ( & V_124 -> V_92 ) ;
if ( F_62 ( & V_124 -> V_101 ) ) {
F_63 ( & V_124 -> V_89 ) ;
V_144 = V_124 -> V_101 . V_147 - V_121 ;
}
if ( ! F_86 ( & V_124 -> V_101 , V_121 + V_144 ) )
F_89 ( & V_124 -> V_89 ) ;
V_124 -> V_93 |= V_148 | V_184 ;
F_55 ( & V_124 -> V_92 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_8 * V_271 ,
struct V_31 * V_32 )
{
int V_13 ;
if ( ! V_271 -> V_27 ) {
return F_35 ( V_32 , & V_271 -> V_5 , V_271 -> V_24 , 0 , NULL , 0 ) ;
}
V_13 = F_35 ( V_32 , & V_271 -> V_5 , V_271 -> V_24 ,
V_271 -> V_27 -> V_59 , V_271 -> V_27 -> V_60 , 0 ) ;
F_14 ( V_2 , V_271 -> V_27 , F_37 ( V_271 -> V_27 -> V_64 ) ) ;
V_271 -> V_27 = NULL ;
return V_13 ;
}
static void F_61 ( struct V_88 * V_124 )
{
if ( F_56 ( V_124 -> V_32 ) ) {
if ( V_124 -> V_93 & V_184 )
F_141 ( & V_124 -> V_95 , V_124 -> V_32 -> V_7 ,
V_136 ) ;
} else {
F_65 ( V_124 -> V_32 , V_124 ) ;
F_58 ( V_124 -> V_32 ) ;
}
}
static void F_150 ( unsigned long V_206 )
{
struct V_31 * V_32 = (struct V_31 * ) V_206 ;
V_32 -> V_142 = 0 ;
F_138 ( V_32 , NULL ) ;
F_97 ( V_32 ) ;
}
static void F_151 ( unsigned long V_206 )
{
struct V_31 * V_32 = (struct V_31 * ) V_206 ;
F_140 ( V_32 ) ;
if ( V_32 -> V_173 ) {
V_32 -> V_173 -- ;
if ( V_32 -> V_173 )
F_87 ( V_32 , V_32 -> V_141 ) ;
}
F_97 ( V_32 ) ;
}
static void F_58 ( struct V_31 * V_32 )
{
if ( F_56 ( V_32 ) )
return;
V_32 -> V_173 = V_32 -> V_100 ;
F_87 ( V_32 , 1 ) ;
}
static void V_118 ( unsigned long V_206 )
{
struct V_88 * V_124 = (struct V_88 * ) V_206 ;
if ( F_56 ( V_124 -> V_32 ) )
F_141 ( & V_124 -> V_95 , V_124 -> V_32 -> V_7 , V_135 ) ;
else
F_138 ( V_124 -> V_32 , V_124 ) ;
F_17 ( & V_124 -> V_92 ) ;
V_124 -> V_93 |= V_184 ;
V_124 -> V_93 &= ~ V_148 ;
F_19 ( & V_124 -> V_92 ) ;
F_47 ( V_124 ) ;
}
void F_152 ( struct V_31 * V_32 )
{
struct V_88 * V_48 ;
F_30 ( & V_32 -> V_37 ) ;
for ( V_48 = V_32 -> V_116 ; V_48 ; V_48 = V_48 -> V_18 )
F_59 ( V_48 ) ;
F_31 ( & V_32 -> V_37 ) ;
}
void F_153 ( struct V_31 * V_32 )
{
F_154 ( V_32 ) ;
}
void F_155 ( struct V_31 * V_32 )
{
struct V_88 * V_48 ;
F_30 ( & V_32 -> V_37 ) ;
V_32 -> V_173 = 0 ;
if ( F_62 ( & V_32 -> V_145 ) )
F_97 ( V_32 ) ;
V_32 -> V_142 = 0 ;
if ( F_62 ( & V_32 -> V_143 ) )
F_97 ( V_32 ) ;
for ( V_48 = V_32 -> V_116 ; V_48 ; V_48 = V_48 -> V_18 )
F_59 ( V_48 ) ;
F_31 ( & V_32 -> V_37 ) ;
F_70 ( V_32 ) ;
}
void F_154 ( struct V_31 * V_32 )
{
struct V_88 * V_48 ;
F_30 ( & V_32 -> V_37 ) ;
for ( V_48 = V_32 -> V_116 ; V_48 ; V_48 = V_48 -> V_18 )
F_51 ( V_48 ) ;
F_31 ( & V_32 -> V_37 ) ;
}
void F_156 ( struct V_31 * V_32 )
{
F_72 ( & V_32 -> V_37 ) ;
F_67 ( & V_32 -> V_110 ) ;
V_32 -> V_142 = 0 ;
F_74 ( & V_32 -> V_143 , F_150 ,
( unsigned long ) V_32 ) ;
V_32 -> V_111 = NULL ;
V_32 -> V_173 = 0 ;
F_74 ( & V_32 -> V_145 , F_151 ,
( unsigned long ) V_32 ) ;
V_32 -> V_100 = V_272 ;
V_32 -> V_141 = V_270 ;
V_32 -> V_172 = 0 ;
F_73 ( & V_32 -> V_37 ) ;
}
void F_157 ( struct V_31 * V_32 )
{
struct V_88 * V_48 ;
F_155 ( V_32 ) ;
F_25 ( V_32 , & V_273 ) ;
if ( V_32 -> V_274 . V_275 )
F_25 ( V_32 , & V_254 ) ;
F_72 ( & V_32 -> V_37 ) ;
while ( ( V_48 = V_32 -> V_116 ) != NULL ) {
V_32 -> V_116 = V_48 -> V_18 ;
F_73 ( & V_32 -> V_37 ) ;
F_59 ( V_48 ) ;
F_47 ( V_48 ) ;
F_72 ( & V_32 -> V_37 ) ;
}
F_73 ( & V_32 -> V_37 ) ;
}
static inline struct V_88 * F_158 ( struct V_276 * V_277 )
{
struct V_88 * V_102 = NULL ;
struct V_278 * V_279 = F_159 ( V_277 ) ;
struct V_12 * V_12 = F_160 ( V_277 ) ;
V_279 -> V_32 = NULL ;
F_161 (net, state->dev) {
struct V_31 * V_32 ;
V_32 = F_23 ( V_279 -> V_7 ) ;
if ( ! V_32 )
continue;
F_30 ( & V_32 -> V_37 ) ;
V_102 = V_32 -> V_116 ;
if ( V_102 ) {
V_279 -> V_32 = V_32 ;
break;
}
F_31 ( & V_32 -> V_37 ) ;
}
return V_102 ;
}
static struct V_88 * F_162 ( struct V_276 * V_277 , struct V_88 * V_102 )
{
struct V_278 * V_279 = F_159 ( V_277 ) ;
V_102 = V_102 -> V_18 ;
while ( ! V_102 ) {
if ( F_163 ( V_279 -> V_32 != NULL ) )
F_31 ( & V_279 -> V_32 -> V_37 ) ;
V_279 -> V_7 = F_164 ( V_279 -> V_7 ) ;
if ( ! V_279 -> V_7 ) {
V_279 -> V_32 = NULL ;
break;
}
V_279 -> V_32 = F_23 ( V_279 -> V_7 ) ;
if ( ! V_279 -> V_32 )
continue;
F_30 ( & V_279 -> V_32 -> V_37 ) ;
V_102 = V_279 -> V_32 -> V_116 ;
}
return V_102 ;
}
static struct V_88 * F_165 ( struct V_276 * V_277 , T_4 V_280 )
{
struct V_88 * V_102 = F_158 ( V_277 ) ;
if ( V_102 )
while ( V_280 && ( V_102 = F_162 ( V_277 , V_102 ) ) != NULL )
-- V_280 ;
return V_280 ? NULL : V_102 ;
}
static void * F_166 ( struct V_276 * V_277 , T_4 * V_280 )
__acquires( T_5 )
{
F_5 () ;
return F_165 ( V_277 , * V_280 ) ;
}
static void * F_167 ( struct V_276 * V_277 , void * V_281 , T_4 * V_280 )
{
struct V_88 * V_102 = F_162 ( V_277 , V_281 ) ;
++ * V_280 ;
return V_102 ;
}
static void F_168 ( struct V_276 * V_277 , void * V_281 )
__releases( T_5 )
{
struct V_278 * V_279 = F_159 ( V_277 ) ;
if ( F_163 ( V_279 -> V_32 != NULL ) ) {
F_31 ( & V_279 -> V_32 -> V_37 ) ;
V_279 -> V_32 = NULL ;
}
V_279 -> V_7 = NULL ;
F_8 () ;
}
static int F_169 ( struct V_276 * V_277 , void * V_281 )
{
struct V_88 * V_102 = (struct V_88 * ) V_281 ;
struct V_278 * V_279 = F_159 ( V_277 ) ;
F_170 ( V_277 ,
L_1 ,
V_279 -> V_7 -> V_3 , V_279 -> V_7 -> V_282 ,
& V_102 -> V_95 ,
V_102 -> V_117 , V_102 -> V_93 ,
( V_102 -> V_93 & V_148 ) ?
F_171 ( V_102 -> V_101 . V_147 - V_121 ) : 0 ) ;
return 0 ;
}
static int F_172 ( struct V_283 * V_283 , struct V_284 * V_284 )
{
return F_173 ( V_283 , V_284 , & V_285 ,
sizeof( struct V_278 ) ) ;
}
static inline struct V_104 * F_174 ( struct V_276 * V_277 )
{
struct V_104 * V_105 = NULL ;
struct V_88 * V_102 = NULL ;
struct V_286 * V_279 = F_175 ( V_277 ) ;
struct V_12 * V_12 = F_160 ( V_277 ) ;
V_279 -> V_32 = NULL ;
V_279 -> V_102 = NULL ;
F_161 (net, state->dev) {
struct V_31 * V_32 ;
V_32 = F_23 ( V_279 -> V_7 ) ;
if ( F_176 ( V_32 == NULL ) )
continue;
F_30 ( & V_32 -> V_37 ) ;
V_102 = V_32 -> V_116 ;
if ( F_163 ( V_102 != NULL ) ) {
F_52 ( & V_102 -> V_92 ) ;
V_105 = V_102 -> V_107 ;
if ( F_163 ( V_105 != NULL ) ) {
V_279 -> V_102 = V_102 ;
V_279 -> V_32 = V_32 ;
break;
}
F_55 ( & V_102 -> V_92 ) ;
}
F_31 ( & V_32 -> V_37 ) ;
}
return V_105 ;
}
static struct V_104 * F_177 ( struct V_276 * V_277 , struct V_104 * V_105 )
{
struct V_286 * V_279 = F_175 ( V_277 ) ;
V_105 = V_105 -> V_108 ;
while ( ! V_105 ) {
F_55 ( & V_279 -> V_102 -> V_92 ) ;
V_279 -> V_102 = V_279 -> V_102 -> V_18 ;
while ( ! V_279 -> V_102 ) {
if ( F_163 ( V_279 -> V_32 != NULL ) )
F_31 ( & V_279 -> V_32 -> V_37 ) ;
V_279 -> V_7 = F_164 ( V_279 -> V_7 ) ;
if ( ! V_279 -> V_7 ) {
V_279 -> V_32 = NULL ;
goto V_226;
}
V_279 -> V_32 = F_23 ( V_279 -> V_7 ) ;
if ( ! V_279 -> V_32 )
continue;
F_30 ( & V_279 -> V_32 -> V_37 ) ;
V_279 -> V_102 = V_279 -> V_32 -> V_116 ;
}
if ( ! V_279 -> V_102 )
break;
F_52 ( & V_279 -> V_102 -> V_92 ) ;
V_105 = V_279 -> V_102 -> V_107 ;
}
V_226:
return V_105 ;
}
static struct V_104 * F_178 ( struct V_276 * V_277 , T_4 V_280 )
{
struct V_104 * V_105 = F_174 ( V_277 ) ;
if ( V_105 )
while ( V_280 && ( V_105 = F_177 ( V_277 , V_105 ) ) != NULL )
-- V_280 ;
return V_280 ? NULL : V_105 ;
}
static void * F_179 ( struct V_276 * V_277 , T_4 * V_280 )
__acquires( T_5 )
{
F_5 () ;
return * V_280 ? F_178 ( V_277 , * V_280 - 1 ) : V_287 ;
}
static void * F_180 ( struct V_276 * V_277 , void * V_281 , T_4 * V_280 )
{
struct V_104 * V_105 ;
if ( V_281 == V_287 )
V_105 = F_174 ( V_277 ) ;
else
V_105 = F_177 ( V_277 , V_281 ) ;
++ * V_280 ;
return V_105 ;
}
static void F_181 ( struct V_276 * V_277 , void * V_281 )
__releases( T_5 )
{
struct V_286 * V_279 = F_175 ( V_277 ) ;
if ( F_163 ( V_279 -> V_102 != NULL ) ) {
F_55 ( & V_279 -> V_102 -> V_92 ) ;
V_279 -> V_102 = NULL ;
}
if ( F_163 ( V_279 -> V_32 != NULL ) ) {
F_31 ( & V_279 -> V_32 -> V_37 ) ;
V_279 -> V_32 = NULL ;
}
V_279 -> V_7 = NULL ;
F_8 () ;
}
static int F_182 ( struct V_276 * V_277 , void * V_281 )
{
struct V_104 * V_105 = (struct V_104 * ) V_281 ;
struct V_286 * V_279 = F_175 ( V_277 ) ;
if ( V_281 == V_287 ) {
F_170 ( V_277 ,
L_2
L_3 , L_4 ,
L_5 , L_6 ,
L_7 , L_8 , L_9 ) ;
} else {
F_170 ( V_277 ,
L_10 ,
V_279 -> V_7 -> V_3 , V_279 -> V_7 -> V_282 ,
& V_279 -> V_102 -> V_95 ,
& V_105 -> V_138 ,
V_105 -> V_139 [ V_61 ] ,
V_105 -> V_139 [ V_25 ] ) ;
}
return 0 ;
}
static int F_183 ( struct V_283 * V_283 , struct V_284 * V_284 )
{
return F_173 ( V_283 , V_284 , & V_288 ,
sizeof( struct V_286 ) ) ;
}
static int T_6 F_184 ( struct V_12 * V_12 )
{
int V_13 ;
V_13 = - V_17 ;
if ( ! F_185 ( V_12 , L_11 , V_289 , & V_290 ) )
goto V_226;
if ( ! F_185 ( V_12 , L_12 , V_289 ,
& V_291 ) )
goto V_292;
V_13 = 0 ;
V_226:
return V_13 ;
V_292:
F_186 ( V_12 , L_11 ) ;
goto V_226;
}
static void T_7 F_187 ( struct V_12 * V_12 )
{
F_186 ( V_12 , L_12 ) ;
F_186 ( V_12 , L_11 ) ;
}
static inline int F_184 ( struct V_12 * V_12 )
{
return 0 ;
}
static inline void F_187 ( struct V_12 * V_12 )
{
}
static int T_6 F_188 ( struct V_12 * V_12 )
{
int V_13 ;
V_13 = F_189 ( & V_12 -> V_194 . V_195 , V_293 ,
V_294 , V_132 , V_12 ) ;
if ( V_13 < 0 ) {
F_190 ( V_295
L_13 ,
V_13 ) ;
goto V_226;
}
F_2 ( V_12 -> V_194 . V_195 ) -> V_296 = 1 ;
V_13 = F_184 ( V_12 ) ;
if ( V_13 )
goto V_297;
V_226:
return V_13 ;
V_297:
F_191 ( V_12 -> V_194 . V_195 ) ;
goto V_226;
}
static void T_7 F_192 ( struct V_12 * V_12 )
{
F_191 ( V_12 -> V_194 . V_195 ) ;
F_187 ( V_12 ) ;
}
int T_8 F_193 ( void )
{
return F_194 ( & V_298 ) ;
}
void F_195 ( void )
{
F_196 ( & V_298 ) ;
}
