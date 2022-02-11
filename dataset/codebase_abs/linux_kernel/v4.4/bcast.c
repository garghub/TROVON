static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_3 ;
}
int F_2 ( struct V_2 * V_2 )
{
return F_3 ( F_4 ( V_2 ) ) ;
}
static void F_5 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = V_1 ( V_2 ) ;
int V_5 = F_6 ( V_4 -> V_6 ) ;
int V_7 , V_8 ;
V_4 -> V_9 = V_10 ;
if ( ! V_5 )
return;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( ! V_4 -> V_12 [ V_7 ] )
continue;
V_8 = F_7 ( V_2 , V_7 ) ;
if ( V_8 < F_3 ( V_4 -> V_6 ) )
F_8 ( V_4 -> V_6 , V_8 ) ;
if ( V_4 -> V_12 [ V_7 ] < V_5 )
continue;
V_4 -> V_9 = V_7 ;
if ( ( V_7 ^ F_9 ( V_2 ) ) & 1 )
break;
}
}
void F_10 ( struct V_2 * V_2 , int V_13 )
{
struct V_1 * V_4 = V_1 ( V_2 ) ;
F_11 ( V_2 ) ;
V_4 -> V_12 [ V_13 ] ++ ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_2 * V_2 , int V_13 )
{
struct V_1 * V_4 = V_1 ( V_2 ) ;
F_11 ( V_2 ) ;
V_4 -> V_12 [ V_13 ] -- ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_14 ( struct V_2 * V_2 , struct V_14 * V_15 )
{
int V_13 ;
struct V_1 * V_4 = V_1 ( V_2 ) ;
struct V_16 * V_17 , * V_18 ;
struct V_14 V_19 ;
if ( F_15 ( V_15 ) )
return;
V_13 = V_4 -> V_9 ;
if ( V_13 >= 0 ) {
F_16 ( V_2 , V_13 , V_15 ) ;
return;
}
F_17 ( & V_19 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ ) {
if ( ! V_4 -> V_12 [ V_13 ] )
continue;
F_18 (xmitq, skb) {
V_18 = F_19 ( V_17 , V_20 ) ;
if ( ! V_18 )
break;
F_20 ( & V_19 , V_18 ) ;
}
F_16 ( V_2 , V_13 , & V_19 ) ;
}
F_21 ( V_15 ) ;
F_21 ( & V_19 ) ;
}
int F_22 ( struct V_2 * V_2 , struct V_14 * V_21 )
{
struct V_22 * V_23 = F_4 ( V_2 ) ;
struct V_14 V_15 , V_24 , V_25 ;
int V_26 = 0 ;
F_23 ( & V_25 ) ;
F_23 ( & V_15 ) ;
F_17 ( & V_24 ) ;
if ( F_24 ( ! F_25 ( V_21 , & V_25 ) ) )
return - V_27 ;
F_11 ( V_2 ) ;
if ( F_6 ( V_23 ) )
V_26 = F_26 ( V_23 , V_21 , & V_15 ) ;
F_12 ( V_2 ) ;
if ( F_24 ( V_26 ) ) {
F_21 ( & V_25 ) ;
return V_26 ;
}
F_14 ( V_2 , & V_15 ) ;
F_27 ( V_2 , & V_25 , & V_24 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
int F_28 ( struct V_2 * V_2 , struct V_22 * V_23 , struct V_16 * V_17 )
{
struct V_28 * V_29 = F_29 ( V_17 ) ;
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
int V_26 ;
F_23 ( & V_15 ) ;
if ( F_30 ( V_29 ) != F_31 ( V_2 ) || ! F_32 ( V_23 ) ) {
F_33 ( V_17 ) ;
return 0 ;
}
F_11 ( V_2 ) ;
if ( F_34 ( V_29 ) == V_30 )
V_26 = F_35 ( V_23 , V_17 , & V_15 ) ;
else
V_26 = F_36 ( V_23 , V_17 , NULL ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
return V_26 ;
}
void F_38 ( struct V_2 * V_2 , struct V_22 * V_23 , T_1 V_31 )
{
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
F_23 ( & V_15 ) ;
F_11 ( V_2 ) ;
F_39 ( V_23 , V_31 , & V_15 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
}
void F_40 ( struct V_2 * V_2 , struct V_22 * V_23 ,
struct V_28 * V_29 )
{
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
F_23 ( & V_15 ) ;
F_11 ( V_2 ) ;
if ( F_41 ( V_29 ) == V_32 ) {
F_39 ( V_23 , F_42 ( V_29 ) , & V_15 ) ;
F_43 ( V_23 , V_29 , & V_15 ) ;
} else {
F_44 ( V_23 , V_29 ) ;
}
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
}
void F_45 ( struct V_2 * V_2 , struct V_22 * V_33 ,
struct V_14 * V_15 )
{
struct V_22 * V_34 = F_4 ( V_2 ) ;
F_11 ( V_2 ) ;
F_46 ( V_34 , V_33 , V_15 ) ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_47 ( struct V_2 * V_2 , struct V_22 * V_35 )
{
struct V_22 * V_34 = F_4 ( V_2 ) ;
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
F_23 ( & V_15 ) ;
F_11 ( V_2 ) ;
F_48 ( V_34 , V_35 , & V_15 ) ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
}
static int F_49 ( struct V_16 * V_17 ,
struct V_36 * V_37 )
{
int V_7 ;
struct V_38 * V_39 ;
struct V_40 {
T_2 V_41 ;
T_2 V_42 ;
};
struct V_40 V_43 [] = {
{ V_44 , V_37 -> V_45 } ,
{ V_46 , V_37 -> V_47 } ,
{ V_48 , V_37 -> V_49 } ,
{ V_50 , V_37 -> V_51 } ,
{ V_52 , V_37 -> V_53 } ,
{ V_54 , V_37 -> V_55 } ,
{ V_56 , V_37 -> V_57 } ,
{ V_58 , V_37 -> V_59 } ,
{ V_60 , V_37 -> V_61 } ,
{ V_62 , V_37 -> V_63 } ,
{ V_64 , V_37 -> V_65 } ,
{ V_66 , V_37 -> V_67 } ,
{ V_68 , V_37 -> V_69 } ,
{ V_70 , V_37 -> V_71 } ,
{ V_72 , V_37 -> V_73 } ,
{ V_74 , V_37 -> V_75 } ,
{ V_76 , V_37 -> V_77 } ,
{ V_78 , V_37 -> V_79 } ,
{ V_80 , V_37 -> V_81 ?
( V_37 -> V_82 / V_37 -> V_81 ) : 0 }
} ;
V_39 = F_50 ( V_17 , V_83 ) ;
if ( ! V_39 )
return - V_84 ;
for ( V_7 = 0 ; V_7 < F_51 ( V_43 ) ; V_7 ++ )
if ( F_52 ( V_17 , V_43 [ V_7 ] . V_41 , V_43 [ V_7 ] . V_42 ) )
goto V_85;
F_53 ( V_17 , V_39 ) ;
return 0 ;
V_85:
F_54 ( V_17 , V_39 ) ;
return - V_84 ;
}
int F_55 ( struct V_2 * V_2 , struct V_86 * V_87 )
{
int V_88 ;
void * V_29 ;
struct V_38 * V_89 ;
struct V_38 * V_90 ;
struct F_1 * V_91 = F_56 ( V_2 , V_92 ) ;
struct V_22 * V_93 = V_91 -> V_93 ;
if ( ! V_93 )
return 0 ;
F_11 ( V_2 ) ;
V_29 = F_57 ( V_87 -> V_17 , V_87 -> V_94 , V_87 -> V_95 , & V_96 ,
V_97 , V_98 ) ;
if ( ! V_29 )
return - V_84 ;
V_89 = F_50 ( V_87 -> V_17 , V_99 ) ;
if ( ! V_89 )
goto V_85;
if ( F_58 ( V_87 -> V_17 , V_100 ) )
goto V_101;
if ( F_58 ( V_87 -> V_17 , V_102 ) )
goto V_101;
if ( F_59 ( V_87 -> V_17 , V_103 , V_93 -> V_104 ) )
goto V_101;
if ( F_52 ( V_87 -> V_17 , V_105 , V_93 -> V_106 ) )
goto V_101;
if ( F_52 ( V_87 -> V_17 , V_107 , V_93 -> V_108 ) )
goto V_101;
V_90 = F_50 ( V_87 -> V_17 , V_109 ) ;
if ( ! V_90 )
goto V_101;
if ( F_52 ( V_87 -> V_17 , V_110 , V_93 -> V_111 ) )
goto V_112;
F_53 ( V_87 -> V_17 , V_90 ) ;
V_88 = F_49 ( V_87 -> V_17 , & V_93 -> V_37 ) ;
if ( V_88 )
goto V_101;
F_12 ( V_2 ) ;
F_53 ( V_87 -> V_17 , V_89 ) ;
F_60 ( V_87 -> V_17 , V_29 ) ;
return 0 ;
V_112:
F_54 ( V_87 -> V_17 , V_90 ) ;
V_101:
F_54 ( V_87 -> V_17 , V_89 ) ;
V_85:
F_12 ( V_2 ) ;
F_61 ( V_87 -> V_17 , V_29 ) ;
return - V_84 ;
}
int F_62 ( struct V_2 * V_2 )
{
struct F_1 * V_91 = F_56 ( V_2 , V_92 ) ;
struct V_22 * V_93 = V_91 -> V_93 ;
if ( ! V_93 )
return - V_113 ;
F_11 ( V_2 ) ;
memset ( & V_93 -> V_37 , 0 , sizeof( V_93 -> V_37 ) ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_2 , T_1 V_114 )
{
struct V_22 * V_23 = F_4 ( V_2 ) ;
if ( ! V_23 )
return - V_113 ;
if ( V_114 < V_115 )
V_114 = V_115 ;
if ( V_114 > V_116 )
return - V_117 ;
F_11 ( V_2 ) ;
F_64 ( V_23 , V_114 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
int F_65 ( struct V_2 * V_2 , struct V_38 * V_89 [] )
{
int V_88 ;
T_1 V_118 ;
struct V_38 * V_119 [ V_120 + 1 ] ;
if ( ! V_89 [ V_109 ] )
return - V_117 ;
V_88 = F_66 ( V_89 [ V_109 ] , V_119 ) ;
if ( V_88 )
return V_88 ;
if ( ! V_119 [ V_110 ] )
return - V_121 ;
V_118 = F_67 ( V_119 [ V_110 ] ) ;
return F_63 ( V_2 , V_118 ) ;
}
int F_68 ( struct V_2 * V_2 )
{
struct F_1 * V_91 = F_1 ( V_2 ) ;
struct V_1 * V_4 = NULL ;
struct V_22 * V_23 = NULL ;
V_4 = F_69 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
goto V_122;
V_91 -> V_3 = V_4 ;
F_70 ( & F_1 ( V_2 ) -> V_123 ) ;
if ( ! F_71 ( V_2 , 0 , 0 ,
V_124 ,
V_125 ,
0 ,
& V_4 -> V_24 ,
NULL ,
NULL ,
& V_23 ) )
goto V_122;
V_4 -> V_6 = V_23 ;
V_91 -> V_93 = V_23 ;
return 0 ;
V_122:
F_72 ( V_4 ) ;
F_72 ( V_23 ) ;
return - V_126 ;
}
void F_73 ( struct V_2 * V_2 )
{
struct V_1 * V_127 = V_1 ( V_2 ) ;
F_74 ( V_127 -> V_6 -> V_128 , F_9 ( V_2 ) ) ;
}
void F_75 ( struct V_2 * V_2 )
{
struct F_1 * V_91 = F_56 ( V_2 , V_92 ) ;
F_76 () ;
F_72 ( V_91 -> V_3 ) ;
F_72 ( V_91 -> V_93 ) ;
}
