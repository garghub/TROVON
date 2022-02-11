void F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
#ifdef F_2
union V_9 V_10 ;
#endif
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return;
if ( ! V_5 -> V_13 )
return;
V_8 = F_4 ( V_5 -> V_14 , NULL , V_3 ,
V_5 -> V_15 , V_5 -> V_13 ,
V_16 , V_16 ) ;
if ( F_3 ( ! V_8 ) )
return;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( & V_5 -> V_17 -> V_18 ) ;
}
F_7 ( F_8 ( V_8 ) ) ;
V_5 -> V_17 = F_8 ( V_8 ) ;
V_5 -> V_19 = V_20 ;
F_9 ( V_5 ) ;
F_10 ( F_11 ( V_5 -> V_14 ) , V_2 , V_3 ,
V_21 ) ;
#ifdef F_2
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
memcpy ( V_10 . V_22 . V_23 , V_3 , V_24 ) ;
F_12 ( V_2 , V_25 , & V_10 , NULL ) ;
#endif
}
void F_13 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_26 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
struct V_29 * V_30 ;
unsigned long V_31 ;
F_14 ( V_2 , V_3 ) ;
F_15 ( V_5 -> V_19 != V_32 ) ;
V_30 = F_16 ( sizeof( * V_30 ) , V_26 ) ;
if ( ! V_30 )
return;
V_30 -> type = V_33 ;
memcpy ( V_30 -> V_34 . V_3 , V_3 , V_24 ) ;
F_17 ( & V_5 -> V_35 , V_31 ) ;
F_18 ( & V_30 -> V_36 , & V_5 -> V_37 ) ;
F_19 ( & V_5 -> V_35 , V_31 ) ;
F_20 ( V_38 , & V_28 -> V_39 ) ;
}
int F_21 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_22 ( V_5 ) ;
if ( V_5 -> V_13 )
return - V_45 ;
if ( ! V_41 -> V_46 ) {
struct V_47 * V_48 =
V_28 -> V_14 . V_49 [ V_41 -> V_50 . V_51 -> V_52 ] ;
int V_53 ;
T_3 V_54 = V_41 -> V_50 . V_51 -> V_52 == V_55 ?
V_56 :
V_57 ;
for ( V_53 = 0 ; V_53 < V_48 -> V_58 ; V_53 ++ ) {
if ( V_48 -> V_59 [ V_53 ] . V_31 & V_54 )
V_41 -> V_46 |= F_23 ( V_53 ) ;
}
}
if ( F_3 ( V_5 -> V_60 ) )
F_24 ( V_5 -> V_60 ) ;
V_5 -> V_60 = V_43 ;
V_5 -> V_61 = V_41 -> V_62 ;
#ifdef F_2
V_5 -> V_63 . V_64 . V_50 = V_41 -> V_50 ;
#endif
V_5 -> V_19 = V_32 ;
V_44 = F_25 ( V_28 , V_5 , V_41 -> V_50 . V_51 ,
V_41 -> V_62
? V_65
: V_66 ) ;
if ( V_44 ) {
V_5 -> V_60 = NULL ;
return V_44 ;
}
V_44 = F_26 ( V_28 , V_2 , V_41 ) ;
if ( V_44 ) {
V_5 -> V_60 = NULL ;
V_5 -> V_19 = V_67 ;
return V_44 ;
}
memcpy ( V_5 -> V_15 , V_41 -> V_15 , V_41 -> V_13 ) ;
V_5 -> V_13 = V_41 -> V_13 ;
return 0 ;
}
int F_27 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_28 ( & V_28 -> V_68 ) ;
F_29 ( V_5 ) ;
V_44 = F_21 ( V_28 , V_2 , V_41 , V_43 ) ;
F_30 ( V_5 ) ;
F_31 ( & V_28 -> V_68 ) ;
return V_44 ;
}
static void F_32 ( struct V_1 * V_2 , bool V_69 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
int V_70 ;
F_22 ( V_5 ) ;
F_24 ( V_5 -> V_60 ) ;
V_5 -> V_60 = NULL ;
if ( V_28 -> V_71 -> V_72 )
for ( V_70 = 0 ; V_70 < 6 ; V_70 ++ )
F_33 ( V_28 , V_2 , V_70 , false , NULL ) ;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( & V_5 -> V_17 -> V_18 ) ;
}
V_5 -> V_17 = NULL ;
V_5 -> V_19 = V_67 ;
V_5 -> V_13 = 0 ;
#ifdef F_2
if ( ! V_69 )
V_5 -> V_63 . V_64 . V_13 = 0 ;
#endif
}
void F_34 ( struct V_1 * V_2 , bool V_69 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_29 ( V_5 ) ;
F_32 ( V_2 , V_69 ) ;
F_30 ( V_5 ) ;
}
int F_35 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_69 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_22 ( V_5 ) ;
if ( ! V_5 -> V_13 )
return - V_73 ;
V_44 = F_36 ( V_28 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_32 ( V_2 , V_69 ) ;
return 0 ;
}
int F_37 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_69 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_29 ( V_5 ) ;
V_44 = F_35 ( V_28 , V_2 , V_69 ) ;
F_30 ( V_5 ) ;
return V_44 ;
}
int F_38 ( struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_42 * V_74 = NULL ;
enum V_75 V_52 ;
int V_70 , V_44 ;
F_22 ( V_5 ) ;
if ( ! V_5 -> V_63 . V_64 . V_76 )
V_5 -> V_63 . V_64 . V_76 = 100 ;
if ( ! V_5 -> V_63 . V_64 . V_50 . V_51 ) {
V_5 -> V_63 . V_64 . V_50 . V_77 = V_78 ;
for ( V_52 = 0 ; V_52 < V_79 ; V_52 ++ ) {
struct V_47 * V_48 ;
struct V_80 * V_51 ;
V_48 = V_28 -> V_14 . V_49 [ V_52 ] ;
if ( ! V_48 )
continue;
for ( V_70 = 0 ; V_70 < V_48 -> V_81 ; V_70 ++ ) {
V_51 = & V_48 -> V_82 [ V_70 ] ;
if ( V_51 -> V_31 & V_83 )
continue;
if ( V_51 -> V_31 & V_84 )
continue;
V_5 -> V_63 . V_64 . V_50 . V_51 = V_51 ;
break;
}
if ( V_5 -> V_63 . V_64 . V_50 . V_51 )
break;
}
if ( ! V_5 -> V_63 . V_64 . V_50 . V_51 )
return - V_85 ;
}
if ( ! V_5 -> V_63 . V_64 . V_13 )
return 0 ;
if ( ! F_39 ( V_5 -> V_86 ) )
return 0 ;
if ( V_5 -> V_63 . V_87 ) {
V_5 -> V_63 . V_87 -> V_88 = V_5 -> V_63 . V_89 ;
V_5 -> V_63 . V_87 -> V_90 = V_5 -> V_63 . V_91 ;
}
V_5 -> V_63 . V_64 . V_92 = V_5 -> V_63 . V_89 != - 1 ;
if ( V_5 -> V_63 . V_87 ) {
V_74 = F_40 ( V_5 -> V_63 . V_87 , sizeof( * V_74 ) , V_21 ) ;
if ( ! V_74 )
return - V_93 ;
for ( V_70 = 0 ; V_70 < 6 ; V_70 ++ )
V_74 -> V_41 [ V_70 ] . V_94 = V_74 -> V_95 [ V_70 ] ;
}
V_44 = F_21 ( V_28 , V_5 -> V_86 ,
& V_5 -> V_63 . V_64 , V_74 ) ;
if ( V_44 )
F_24 ( V_74 ) ;
return V_44 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
struct V_80 * V_51 = NULL ;
int V_44 , V_101 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
if ( ! V_28 -> V_71 -> V_102 )
return - V_103 ;
V_101 = F_42 ( V_5 -> V_14 , V_99 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( V_101 ) {
V_51 = F_43 ( V_5 -> V_14 , V_101 ) ;
if ( ! V_51 )
return - V_85 ;
if ( V_51 -> V_31 & V_83 ||
V_51 -> V_31 & V_84 )
return - V_85 ;
}
if ( V_5 -> V_63 . V_64 . V_50 . V_51 == V_51 )
return 0 ;
F_29 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_35 ( V_28 , V_2 , true ) ;
F_30 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_51 ) {
V_5 -> V_63 . V_64 . V_50 . V_51 = V_51 ;
V_5 -> V_63 . V_64 . V_50 . V_77 = V_78 ;
V_5 -> V_63 . V_64 . V_62 = true ;
} else {
V_5 -> V_63 . V_64 . V_62 = false ;
}
F_28 ( & V_28 -> V_68 ) ;
F_29 ( V_5 ) ;
V_44 = F_38 ( V_28 , V_5 ) ;
F_30 ( V_5 ) ;
F_31 ( & V_28 -> V_68 ) ;
return V_44 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_98 * V_101 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_80 * V_51 = NULL ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
F_29 ( V_5 ) ;
if ( V_5 -> V_17 )
V_51 = V_5 -> V_17 -> V_18 . V_104 ;
else if ( V_5 -> V_63 . V_64 . V_50 . V_51 )
V_51 = V_5 -> V_63 . V_64 . V_50 . V_51 ;
F_30 ( V_5 ) ;
if ( V_51 ) {
V_101 -> V_105 = V_51 -> V_106 ;
V_101 -> V_107 = 6 ;
return 0 ;
}
return - V_85 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_108 * V_95 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
T_4 V_109 = V_95 -> V_110 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
if ( ! V_28 -> V_71 -> V_102 )
return - V_103 ;
F_29 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_35 ( V_28 , V_2 , true ) ;
F_30 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_109 > 0 && V_15 [ V_109 - 1 ] == '\0' )
V_109 -- ;
V_5 -> V_63 . V_64 . V_15 = V_5 -> V_15 ;
memcpy ( V_5 -> V_63 . V_64 . V_15 , V_15 , V_109 ) ;
V_5 -> V_63 . V_64 . V_13 = V_109 ;
F_28 ( & V_28 -> V_68 ) ;
F_29 ( V_5 ) ;
V_44 = F_38 ( V_28 , V_5 ) ;
F_30 ( V_5 ) ;
F_31 ( & V_28 -> V_68 ) ;
return V_44 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_108 * V_95 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
V_95 -> V_31 = 0 ;
F_29 ( V_5 ) ;
if ( V_5 -> V_13 ) {
V_95 -> V_31 = 1 ;
V_95 -> V_110 = V_5 -> V_13 ;
memcpy ( V_15 , V_5 -> V_15 , V_95 -> V_110 ) ;
} else if ( V_5 -> V_63 . V_64 . V_15 && V_5 -> V_63 . V_64 . V_13 ) {
V_95 -> V_31 = 1 ;
V_95 -> V_110 = V_5 -> V_63 . V_64 . V_13 ;
memcpy ( V_15 , V_5 -> V_63 . V_64 . V_15 , V_95 -> V_110 ) ;
}
F_30 ( V_5 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_111 * V_22 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
T_1 * V_3 = V_22 -> V_23 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
if ( ! V_28 -> V_71 -> V_102 )
return - V_103 ;
if ( V_22 -> V_112 != V_113 )
return - V_85 ;
if ( F_48 ( V_3 ) || F_49 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_5 -> V_63 . V_64 . V_3 )
return 0 ;
if ( V_5 -> V_63 . V_64 . V_3 && V_3 &&
F_50 ( V_3 , V_5 -> V_63 . V_64 . V_3 ) )
return 0 ;
F_29 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_35 ( V_28 , V_2 , true ) ;
F_30 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_3 ) {
memcpy ( V_5 -> V_63 . V_3 , V_3 , V_24 ) ;
V_5 -> V_63 . V_64 . V_3 = V_5 -> V_63 . V_3 ;
} else
V_5 -> V_63 . V_64 . V_3 = NULL ;
F_28 ( & V_28 -> V_68 ) ;
F_29 ( V_5 ) ;
V_44 = F_38 ( V_28 , V_5 ) ;
F_30 ( V_5 ) ;
F_31 ( & V_28 -> V_68 ) ;
return V_44 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_111 * V_22 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
V_22 -> V_112 = V_113 ;
F_29 ( V_5 ) ;
if ( V_5 -> V_17 )
memcpy ( V_22 -> V_23 , V_5 -> V_17 -> V_18 . V_3 , V_24 ) ;
else if ( V_5 -> V_63 . V_64 . V_3 )
memcpy ( V_22 -> V_23 , V_5 -> V_63 . V_64 . V_3 , V_24 ) ;
else
memset ( V_22 -> V_23 , 0 , V_24 ) ;
F_30 ( V_5 ) ;
return 0 ;
}
