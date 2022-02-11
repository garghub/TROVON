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
F_6 ( V_5 -> V_14 , & V_5 -> V_17 -> V_18 ) ;
}
F_7 ( F_8 ( V_8 ) ) ;
V_5 -> V_17 = F_8 ( V_8 ) ;
F_9 ( V_5 ) ;
F_10 ( F_11 ( V_5 -> V_14 ) , V_2 , V_3 ,
V_19 ) ;
#ifdef F_2
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
memcpy ( V_10 . V_20 . V_21 , V_3 , V_22 ) ;
F_12 ( V_2 , V_23 , & V_10 , NULL ) ;
#endif
}
void F_13 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_24 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
struct V_27 * V_28 ;
unsigned long V_29 ;
F_14 ( V_2 , V_3 ) ;
V_28 = F_15 ( sizeof( * V_28 ) , V_24 ) ;
if ( ! V_28 )
return;
V_28 -> type = V_30 ;
memcpy ( V_28 -> V_31 . V_3 , V_3 , V_22 ) ;
F_16 ( & V_5 -> V_32 , V_29 ) ;
F_17 ( & V_28 -> V_33 , & V_5 -> V_34 ) ;
F_18 ( & V_5 -> V_32 , V_29 ) ;
F_19 ( V_35 , & V_26 -> V_36 ) ;
}
int F_20 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_41 * V_42 ;
T_1 V_43 = 0 ;
int V_44 ;
F_21 ( V_5 ) ;
if ( V_5 -> V_13 )
return - V_45 ;
if ( ! V_38 -> V_46 ) {
struct V_47 * V_48 =
V_26 -> V_14 . V_49 [ V_38 -> V_50 . V_51 -> V_52 ] ;
int V_53 ;
T_3 V_54 = V_38 -> V_50 . V_51 -> V_52 == V_55 ?
V_56 :
V_57 ;
for ( V_53 = 0 ; V_53 < V_48 -> V_58 ; V_53 ++ ) {
if ( V_48 -> V_59 [ V_53 ] . V_29 & V_54 )
V_38 -> V_46 |= F_22 ( V_53 ) ;
}
}
if ( F_3 ( V_5 -> V_60 ) )
F_23 ( V_5 -> V_60 ) ;
V_5 -> V_60 = V_40 ;
V_5 -> V_61 = V_38 -> V_62 ;
V_5 -> V_63 = V_38 -> V_64 ;
#ifdef F_2
V_5 -> V_65 . V_66 . V_50 = V_38 -> V_50 ;
#endif
V_42 = V_38 -> V_50 . V_51 ;
if ( V_38 -> V_64 ) {
V_43 = F_22 ( V_38 -> V_50 . V_67 ) ;
V_42 = NULL ;
}
V_44 = F_24 ( V_26 , V_5 , V_5 -> V_11 ,
V_42 ,
( V_38 -> V_62 &&
! V_43 )
? V_68
: V_69 ,
V_43 ) ;
if ( V_44 ) {
V_5 -> V_60 = NULL ;
return V_44 ;
}
V_44 = F_25 ( V_26 , V_2 , V_38 ) ;
if ( V_44 ) {
V_5 -> V_60 = NULL ;
return V_44 ;
}
memcpy ( V_5 -> V_15 , V_38 -> V_15 , V_38 -> V_13 ) ;
V_5 -> V_13 = V_38 -> V_13 ;
return 0 ;
}
int F_26 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_27 () ;
F_28 ( V_5 ) ;
V_44 = F_20 ( V_26 , V_2 , V_38 , V_40 ) ;
F_29 ( V_5 ) ;
return V_44 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
int V_71 ;
F_21 ( V_5 ) ;
F_23 ( V_5 -> V_60 ) ;
V_5 -> V_60 = NULL ;
F_31 ( V_26 , V_2 , NULL ) ;
if ( V_26 -> V_72 -> V_73 )
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
F_32 ( V_26 , V_2 , V_71 , false , NULL ) ;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( V_5 -> V_14 , & V_5 -> V_17 -> V_18 ) ;
}
V_5 -> V_17 = NULL ;
V_5 -> V_13 = 0 ;
#ifdef F_2
if ( ! V_70 )
V_5 -> V_65 . V_66 . V_13 = 0 ;
#endif
}
void F_33 ( struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_28 ( V_5 ) ;
F_30 ( V_2 , V_70 ) ;
F_29 ( V_5 ) ;
}
int F_34 ( struct V_25 * V_26 ,
struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_13 )
return - V_74 ;
V_44 = F_35 ( V_26 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_30 ( V_2 , V_70 ) ;
return 0 ;
}
int F_36 ( struct V_25 * V_26 ,
struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_28 ( V_5 ) ;
V_44 = F_34 ( V_26 , V_2 , V_70 ) ;
F_29 ( V_5 ) ;
return V_44 ;
}
int F_37 ( struct V_25 * V_26 ,
struct V_4 * V_5 )
{
struct V_39 * V_75 = NULL ;
enum V_76 V_52 ;
int V_71 , V_44 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_65 . V_66 . V_77 )
V_5 -> V_65 . V_66 . V_77 = 100 ;
if ( ! V_5 -> V_65 . V_66 . V_50 . V_51 ) {
struct V_41 * V_78 = NULL ;
for ( V_52 = 0 ; V_52 < V_79 ; V_52 ++ ) {
struct V_47 * V_48 ;
struct V_41 * V_51 ;
V_48 = V_26 -> V_14 . V_49 [ V_52 ] ;
if ( ! V_48 )
continue;
for ( V_71 = 0 ; V_71 < V_48 -> V_80 ; V_71 ++ ) {
V_51 = & V_48 -> V_81 [ V_71 ] ;
if ( V_51 -> V_29 & V_82 )
continue;
if ( V_51 -> V_29 & V_83 )
continue;
V_78 = V_51 ;
break;
}
if ( V_78 )
break;
}
if ( ! V_78 )
return - V_84 ;
F_38 ( & V_5 -> V_65 . V_66 . V_50 , V_78 ,
V_85 ) ;
}
if ( ! V_5 -> V_65 . V_66 . V_13 )
return 0 ;
if ( ! F_39 ( V_5 -> V_86 ) )
return 0 ;
if ( V_5 -> V_65 . V_87 ) {
V_5 -> V_65 . V_87 -> V_88 = V_5 -> V_65 . V_89 ;
V_5 -> V_65 . V_87 -> V_90 = V_5 -> V_65 . V_91 ;
}
V_5 -> V_65 . V_66 . V_92 = V_5 -> V_65 . V_89 != - 1 ;
if ( V_5 -> V_65 . V_87 ) {
V_75 = F_40 ( V_5 -> V_65 . V_87 , sizeof( * V_75 ) , V_19 ) ;
if ( ! V_75 )
return - V_93 ;
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
V_75 -> V_38 [ V_71 ] . V_94 = V_75 -> V_95 [ V_71 ] ;
}
V_44 = F_20 ( V_26 , V_5 -> V_86 ,
& V_5 -> V_65 . V_66 , V_75 ) ;
if ( V_44 )
F_23 ( V_75 ) ;
return V_44 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
struct V_41 * V_51 = NULL ;
int V_44 , V_101 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_84 ;
if ( ! V_26 -> V_72 -> V_102 )
return - V_103 ;
V_101 = F_42 ( V_5 -> V_14 , V_99 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( V_101 ) {
V_51 = F_43 ( V_5 -> V_14 , V_101 ) ;
if ( ! V_51 )
return - V_84 ;
if ( V_51 -> V_29 & V_82 ||
V_51 -> V_29 & V_83 )
return - V_84 ;
}
if ( V_5 -> V_65 . V_66 . V_50 . V_51 == V_51 )
return 0 ;
F_28 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_34 ( V_26 , V_2 , true ) ;
F_29 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_51 ) {
F_38 ( & V_5 -> V_65 . V_66 . V_50 , V_51 ,
V_85 ) ;
V_5 -> V_65 . V_66 . V_62 = true ;
} else {
V_5 -> V_65 . V_66 . V_62 = false ;
}
F_28 ( V_5 ) ;
V_44 = F_37 ( V_26 , V_5 ) ;
F_29 ( V_5 ) ;
return V_44 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_98 * V_101 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_41 * V_51 = NULL ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_84 ;
F_28 ( V_5 ) ;
if ( V_5 -> V_17 )
V_51 = V_5 -> V_17 -> V_18 . V_104 ;
else if ( V_5 -> V_65 . V_66 . V_50 . V_51 )
V_51 = V_5 -> V_65 . V_66 . V_50 . V_51 ;
F_29 ( V_5 ) ;
if ( V_51 ) {
V_101 -> V_105 = V_51 -> V_106 ;
V_101 -> V_107 = 6 ;
return 0 ;
}
return - V_84 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_108 * V_95 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
T_4 V_109 = V_95 -> V_110 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_84 ;
if ( ! V_26 -> V_72 -> V_102 )
return - V_103 ;
F_28 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_34 ( V_26 , V_2 , true ) ;
F_29 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_109 > 0 && V_15 [ V_109 - 1 ] == '\0' )
V_109 -- ;
V_5 -> V_65 . V_66 . V_15 = V_5 -> V_15 ;
memcpy ( V_5 -> V_65 . V_66 . V_15 , V_15 , V_109 ) ;
V_5 -> V_65 . V_66 . V_13 = V_109 ;
F_28 ( V_5 ) ;
V_44 = F_37 ( V_26 , V_5 ) ;
F_29 ( V_5 ) ;
return V_44 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_108 * V_95 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_84 ;
V_95 -> V_29 = 0 ;
F_28 ( V_5 ) ;
if ( V_5 -> V_13 ) {
V_95 -> V_29 = 1 ;
V_95 -> V_110 = V_5 -> V_13 ;
memcpy ( V_15 , V_5 -> V_15 , V_95 -> V_110 ) ;
} else if ( V_5 -> V_65 . V_66 . V_15 && V_5 -> V_65 . V_66 . V_13 ) {
V_95 -> V_29 = 1 ;
V_95 -> V_110 = V_5 -> V_65 . V_66 . V_13 ;
memcpy ( V_15 , V_5 -> V_65 . V_66 . V_15 , V_95 -> V_110 ) ;
}
F_29 ( V_5 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_111 * V_20 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
T_1 * V_3 = V_20 -> V_21 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_84 ;
if ( ! V_26 -> V_72 -> V_102 )
return - V_103 ;
if ( V_20 -> V_112 != V_113 )
return - V_84 ;
if ( F_48 ( V_3 ) || F_49 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_5 -> V_65 . V_66 . V_3 )
return 0 ;
if ( V_5 -> V_65 . V_66 . V_3 && V_3 &&
F_50 ( V_3 , V_5 -> V_65 . V_66 . V_3 ) )
return 0 ;
F_28 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_34 ( V_26 , V_2 , true ) ;
F_29 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_3 ) {
memcpy ( V_5 -> V_65 . V_3 , V_3 , V_22 ) ;
V_5 -> V_65 . V_66 . V_3 = V_5 -> V_65 . V_3 ;
} else
V_5 -> V_65 . V_66 . V_3 = NULL ;
F_28 ( V_5 ) ;
V_44 = F_37 ( V_26 , V_5 ) ;
F_29 ( V_5 ) ;
return V_44 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_111 * V_20 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_84 ;
V_20 -> V_112 = V_113 ;
F_28 ( V_5 ) ;
if ( V_5 -> V_17 )
memcpy ( V_20 -> V_21 , V_5 -> V_17 -> V_18 . V_3 , V_22 ) ;
else if ( V_5 -> V_65 . V_66 . V_3 )
memcpy ( V_20 -> V_21 , V_5 -> V_65 . V_66 . V_3 , V_22 ) ;
else
memset ( V_20 -> V_21 , 0 , V_22 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
