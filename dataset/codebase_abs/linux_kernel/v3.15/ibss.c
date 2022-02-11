void F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
#ifdef F_2
union V_11 V_12 ;
#endif
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return;
if ( ! V_7 -> V_15 )
return;
V_10 = F_4 ( V_7 -> V_16 , V_5 , V_3 , NULL , 0 ,
V_17 , V_17 ) ;
if ( F_3 ( ! V_10 ) )
return;
if ( V_7 -> V_18 ) {
F_5 ( V_7 -> V_18 ) ;
F_6 ( V_7 -> V_16 , & V_7 -> V_18 -> V_19 ) ;
}
F_7 ( F_8 ( V_10 ) ) ;
V_7 -> V_18 = F_8 ( V_10 ) ;
F_9 ( V_7 ) ;
F_10 ( F_11 ( V_7 -> V_16 ) , V_2 , V_3 ,
V_20 ) ;
#ifdef F_2
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
memcpy ( V_12 . V_21 . V_22 , V_3 , V_23 ) ;
F_12 ( V_2 , V_24 , & V_12 , NULL ) ;
#endif
}
void F_13 ( struct V_1 * V_2 , const T_1 * V_3 ,
struct V_4 * V_5 , T_2 V_25 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
struct V_28 * V_29 ;
unsigned long V_30 ;
F_14 ( V_2 , V_3 , V_5 ) ;
if ( F_3 ( ! V_5 ) )
return;
V_29 = F_15 ( sizeof( * V_29 ) , V_25 ) ;
if ( ! V_29 )
return;
V_29 -> type = V_31 ;
memcpy ( V_29 -> V_32 . V_3 , V_3 , V_23 ) ;
V_29 -> V_32 . V_5 = V_5 ;
F_16 ( & V_7 -> V_33 , V_30 ) ;
F_17 ( & V_29 -> V_34 , & V_7 -> V_35 ) ;
F_18 ( & V_7 -> V_33 , V_30 ) ;
F_19 ( V_36 , & V_27 -> V_37 ) ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 * V_42 ;
T_1 V_43 = 0 ;
int V_44 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_15 )
return - V_45 ;
if ( ! V_39 -> V_46 ) {
struct V_47 * V_48 =
V_27 -> V_16 . V_49 [ V_39 -> V_50 . V_51 -> V_52 ] ;
int V_53 ;
T_3 V_54 = V_39 -> V_50 . V_51 -> V_52 == V_55 ?
V_56 :
V_57 ;
for ( V_53 = 0 ; V_53 < V_48 -> V_58 ; V_53 ++ ) {
if ( V_48 -> V_59 [ V_53 ] . V_30 & V_54 )
V_39 -> V_46 |= F_22 ( V_53 ) ;
}
}
if ( F_3 ( V_7 -> V_60 ) )
F_23 ( V_7 -> V_60 ) ;
V_7 -> V_60 = V_41 ;
V_7 -> V_61 = V_39 -> V_62 ;
V_7 -> V_63 = V_39 -> V_64 ;
V_7 -> V_50 = V_39 -> V_50 ;
#ifdef F_2
V_7 -> V_65 . V_66 . V_50 = V_39 -> V_50 ;
#endif
V_42 = V_39 -> V_50 . V_51 ;
if ( V_39 -> V_64 ) {
V_43 = F_22 ( V_39 -> V_50 . V_67 ) ;
}
V_44 = F_24 ( V_27 , V_7 , V_7 -> V_13 ,
V_42 ,
( V_39 -> V_62 &&
! V_43 )
? V_68
: V_69 ,
V_43 ) ;
if ( V_44 ) {
V_7 -> V_60 = NULL ;
return V_44 ;
}
V_44 = F_25 ( V_27 , V_2 , V_39 ) ;
if ( V_44 ) {
V_7 -> V_60 = NULL ;
return V_44 ;
}
memcpy ( V_7 -> V_70 , V_39 -> V_70 , V_39 -> V_15 ) ;
V_7 -> V_15 = V_39 -> V_15 ;
return 0 ;
}
int F_26 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_27 () ;
F_28 ( V_7 ) ;
V_44 = F_20 ( V_27 , V_2 , V_39 , V_41 ) ;
F_29 ( V_7 ) ;
return V_44 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_71 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
int V_72 ;
F_21 ( V_7 ) ;
F_23 ( V_7 -> V_60 ) ;
V_7 -> V_60 = NULL ;
F_31 ( V_27 , V_2 , NULL ) ;
if ( V_27 -> V_73 -> V_74 )
for ( V_72 = 0 ; V_72 < 6 ; V_72 ++ )
F_32 ( V_27 , V_2 , V_72 , false , NULL ) ;
if ( V_7 -> V_18 ) {
F_5 ( V_7 -> V_18 ) ;
F_6 ( V_7 -> V_16 , & V_7 -> V_18 -> V_19 ) ;
}
V_7 -> V_18 = NULL ;
V_7 -> V_15 = 0 ;
memset ( & V_7 -> V_50 , 0 , sizeof( V_7 -> V_50 ) ) ;
#ifdef F_2
if ( ! V_71 )
V_7 -> V_65 . V_66 . V_15 = 0 ;
#endif
}
void F_33 ( struct V_1 * V_2 , bool V_71 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_28 ( V_7 ) ;
F_30 ( V_2 , V_71 ) ;
F_29 ( V_7 ) ;
}
int F_34 ( struct V_26 * V_27 ,
struct V_1 * V_2 , bool V_71 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_15 )
return - V_75 ;
V_44 = F_35 ( V_27 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_30 ( V_2 , V_71 ) ;
return 0 ;
}
int F_36 ( struct V_26 * V_27 ,
struct V_1 * V_2 , bool V_71 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_28 ( V_7 ) ;
V_44 = F_34 ( V_27 , V_2 , V_71 ) ;
F_29 ( V_7 ) ;
return V_44 ;
}
int F_37 ( struct V_26 * V_27 ,
struct V_6 * V_7 )
{
struct V_40 * V_76 = NULL ;
enum V_77 V_52 ;
int V_72 , V_44 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_65 . V_66 . V_78 )
V_7 -> V_65 . V_66 . V_78 = 100 ;
if ( ! V_7 -> V_65 . V_66 . V_50 . V_51 ) {
struct V_4 * V_79 = NULL ;
for ( V_52 = 0 ; V_52 < V_80 ; V_52 ++ ) {
struct V_47 * V_48 ;
struct V_4 * V_51 ;
V_48 = V_27 -> V_16 . V_49 [ V_52 ] ;
if ( ! V_48 )
continue;
for ( V_72 = 0 ; V_72 < V_48 -> V_81 ; V_72 ++ ) {
V_51 = & V_48 -> V_82 [ V_72 ] ;
if ( V_51 -> V_30 & V_83 )
continue;
if ( V_51 -> V_30 & V_84 )
continue;
V_79 = V_51 ;
break;
}
if ( V_79 )
break;
}
if ( ! V_79 )
return - V_85 ;
F_38 ( & V_7 -> V_65 . V_66 . V_50 , V_79 ,
V_86 ) ;
}
if ( ! V_7 -> V_65 . V_66 . V_15 )
return 0 ;
if ( ! F_39 ( V_7 -> V_87 ) )
return 0 ;
if ( V_7 -> V_65 . V_88 ) {
V_7 -> V_65 . V_88 -> V_89 = V_7 -> V_65 . V_90 ;
V_7 -> V_65 . V_88 -> V_91 = V_7 -> V_65 . V_92 ;
}
V_7 -> V_65 . V_66 . V_93 = V_7 -> V_65 . V_90 != - 1 ;
if ( V_7 -> V_65 . V_88 ) {
V_76 = F_40 ( V_7 -> V_65 . V_88 , sizeof( * V_76 ) , V_20 ) ;
if ( ! V_76 )
return - V_94 ;
for ( V_72 = 0 ; V_72 < 6 ; V_72 ++ )
V_76 -> V_39 [ V_72 ] . V_95 = V_76 -> V_96 [ V_72 ] ;
}
V_44 = F_20 ( V_27 , V_7 -> V_87 ,
& V_7 -> V_65 . V_66 , V_76 ) ;
if ( V_44 )
F_23 ( V_76 ) ;
return V_44 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_99 * V_100 , char * V_101 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
struct V_4 * V_51 = NULL ;
int V_44 , V_102 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_85 ;
if ( ! V_27 -> V_73 -> V_103 )
return - V_104 ;
V_102 = F_42 ( V_7 -> V_16 , V_100 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_102 ) {
V_51 = F_43 ( V_7 -> V_16 , V_102 ) ;
if ( ! V_51 )
return - V_85 ;
if ( V_51 -> V_30 & V_83 ||
V_51 -> V_30 & V_84 )
return - V_85 ;
}
if ( V_7 -> V_65 . V_66 . V_50 . V_51 == V_51 )
return 0 ;
F_28 ( V_7 ) ;
V_44 = 0 ;
if ( V_7 -> V_15 )
V_44 = F_34 ( V_27 , V_2 , true ) ;
F_29 ( V_7 ) ;
if ( V_44 )
return V_44 ;
if ( V_51 ) {
F_38 ( & V_7 -> V_65 . V_66 . V_50 , V_51 ,
V_86 ) ;
V_7 -> V_65 . V_66 . V_62 = true ;
} else {
V_7 -> V_65 . V_66 . V_62 = false ;
}
F_28 ( V_7 ) ;
V_44 = F_37 ( V_27 , V_7 ) ;
F_29 ( V_7 ) ;
return V_44 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_99 * V_102 , char * V_101 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 * V_51 = NULL ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_85 ;
F_28 ( V_7 ) ;
if ( V_7 -> V_18 )
V_51 = V_7 -> V_18 -> V_19 . V_5 ;
else if ( V_7 -> V_65 . V_66 . V_50 . V_51 )
V_51 = V_7 -> V_65 . V_66 . V_50 . V_51 ;
F_29 ( V_7 ) ;
if ( V_51 ) {
V_102 -> V_105 = V_51 -> V_106 ;
V_102 -> V_107 = 6 ;
return 0 ;
}
return - V_85 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_108 * V_96 , char * V_70 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
T_4 V_109 = V_96 -> V_110 ;
int V_44 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_85 ;
if ( ! V_27 -> V_73 -> V_103 )
return - V_104 ;
F_28 ( V_7 ) ;
V_44 = 0 ;
if ( V_7 -> V_15 )
V_44 = F_34 ( V_27 , V_2 , true ) ;
F_29 ( V_7 ) ;
if ( V_44 )
return V_44 ;
if ( V_109 > 0 && V_70 [ V_109 - 1 ] == '\0' )
V_109 -- ;
V_7 -> V_65 . V_66 . V_70 = V_7 -> V_70 ;
memcpy ( V_7 -> V_65 . V_66 . V_70 , V_70 , V_109 ) ;
V_7 -> V_65 . V_66 . V_15 = V_109 ;
F_28 ( V_7 ) ;
V_44 = F_37 ( V_27 , V_7 ) ;
F_29 ( V_7 ) ;
return V_44 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_108 * V_96 , char * V_70 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_85 ;
V_96 -> V_30 = 0 ;
F_28 ( V_7 ) ;
if ( V_7 -> V_15 ) {
V_96 -> V_30 = 1 ;
V_96 -> V_110 = V_7 -> V_15 ;
memcpy ( V_70 , V_7 -> V_70 , V_96 -> V_110 ) ;
} else if ( V_7 -> V_65 . V_66 . V_70 && V_7 -> V_65 . V_66 . V_15 ) {
V_96 -> V_30 = 1 ;
V_96 -> V_110 = V_7 -> V_65 . V_66 . V_15 ;
memcpy ( V_70 , V_7 -> V_65 . V_66 . V_70 , V_96 -> V_110 ) ;
}
F_29 ( V_7 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_111 * V_21 , char * V_101 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
T_1 * V_3 = V_21 -> V_22 ;
int V_44 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_85 ;
if ( ! V_27 -> V_73 -> V_103 )
return - V_104 ;
if ( V_21 -> V_112 != V_113 )
return - V_85 ;
if ( F_48 ( V_3 ) || F_49 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_7 -> V_65 . V_66 . V_3 )
return 0 ;
if ( V_7 -> V_65 . V_66 . V_3 && V_3 &&
F_50 ( V_3 , V_7 -> V_65 . V_66 . V_3 ) )
return 0 ;
F_28 ( V_7 ) ;
V_44 = 0 ;
if ( V_7 -> V_15 )
V_44 = F_34 ( V_27 , V_2 , true ) ;
F_29 ( V_7 ) ;
if ( V_44 )
return V_44 ;
if ( V_3 ) {
memcpy ( V_7 -> V_65 . V_3 , V_3 , V_23 ) ;
V_7 -> V_65 . V_66 . V_3 = V_7 -> V_65 . V_3 ;
} else
V_7 -> V_65 . V_66 . V_3 = NULL ;
F_28 ( V_7 ) ;
V_44 = F_37 ( V_27 , V_7 ) ;
F_29 ( V_7 ) ;
return V_44 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_111 * V_21 , char * V_101 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_85 ;
V_21 -> V_112 = V_113 ;
F_28 ( V_7 ) ;
if ( V_7 -> V_18 )
memcpy ( V_21 -> V_22 , V_7 -> V_18 -> V_19 . V_3 , V_23 ) ;
else if ( V_7 -> V_65 . V_66 . V_3 )
memcpy ( V_21 -> V_22 , V_7 -> V_65 . V_66 . V_3 , V_23 ) ;
else
memset ( V_21 -> V_22 , 0 , V_23 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
