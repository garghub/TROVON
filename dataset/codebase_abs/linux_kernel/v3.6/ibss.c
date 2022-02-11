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
F_14 ( V_5 -> V_19 != V_32 ) ;
V_30 = F_15 ( sizeof( * V_30 ) , V_26 ) ;
if ( ! V_30 )
return;
V_30 -> type = V_33 ;
memcpy ( V_30 -> V_34 . V_3 , V_3 , V_24 ) ;
F_16 ( & V_5 -> V_35 , V_31 ) ;
F_17 ( & V_30 -> V_36 , & V_5 -> V_37 ) ;
F_18 ( & V_5 -> V_35 , V_31 ) ;
F_19 ( V_38 , & V_28 -> V_39 ) ;
}
int F_20 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_21 ( V_5 ) ;
if ( V_5 -> V_13 )
return - V_45 ;
if ( ! V_41 -> V_46 ) {
struct V_47 * V_48 =
V_28 -> V_14 . V_49 [ V_41 -> V_50 -> V_51 ] ;
int V_52 ;
T_3 V_53 = V_41 -> V_50 -> V_51 == V_54 ?
V_55 :
V_56 ;
for ( V_52 = 0 ; V_52 < V_48 -> V_57 ; V_52 ++ ) {
if ( V_48 -> V_58 [ V_52 ] . V_31 & V_53 )
V_41 -> V_46 |= F_22 ( V_52 ) ;
}
}
if ( F_3 ( V_5 -> V_59 ) )
F_23 ( V_5 -> V_59 ) ;
V_5 -> V_59 = V_43 ;
V_5 -> V_60 = V_41 -> V_61 ;
#ifdef F_2
V_5 -> V_62 . V_63 . V_50 = V_41 -> V_50 ;
#endif
V_5 -> V_19 = V_32 ;
V_44 = F_24 ( V_28 , V_5 , V_41 -> V_50 ,
V_41 -> V_61
? V_64
: V_65 ) ;
if ( V_44 ) {
V_5 -> V_59 = NULL ;
return V_44 ;
}
V_44 = V_28 -> V_66 -> V_67 ( & V_28 -> V_14 , V_2 , V_41 ) ;
if ( V_44 ) {
V_5 -> V_59 = NULL ;
V_5 -> V_19 = V_68 ;
return V_44 ;
}
memcpy ( V_5 -> V_15 , V_41 -> V_15 , V_41 -> V_13 ) ;
V_5 -> V_13 = V_41 -> V_13 ;
return 0 ;
}
int F_25 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_26 ( & V_28 -> V_69 ) ;
F_27 ( V_5 ) ;
V_44 = F_20 ( V_28 , V_2 , V_41 , V_43 ) ;
F_28 ( V_5 ) ;
F_29 ( & V_28 -> V_69 ) ;
return V_44 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
int V_71 ;
F_21 ( V_5 ) ;
F_23 ( V_5 -> V_59 ) ;
V_5 -> V_59 = NULL ;
if ( V_28 -> V_66 -> V_72 )
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
V_28 -> V_66 -> V_72 ( V_5 -> V_14 , V_2 , V_71 , false , NULL ) ;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( & V_5 -> V_17 -> V_18 ) ;
}
V_5 -> V_17 = NULL ;
V_5 -> V_19 = V_68 ;
V_5 -> V_13 = 0 ;
#ifdef F_2
if ( ! V_70 )
V_5 -> V_62 . V_63 . V_13 = 0 ;
#endif
}
void F_31 ( struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_27 ( V_5 ) ;
F_30 ( V_2 , V_70 ) ;
F_28 ( V_5 ) ;
}
int F_32 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_13 )
return - V_73 ;
V_44 = V_28 -> V_66 -> V_74 ( & V_28 -> V_14 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_30 ( V_2 , V_70 ) ;
return 0 ;
}
int F_33 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_70 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_27 ( V_5 ) ;
V_44 = F_32 ( V_28 , V_2 , V_70 ) ;
F_28 ( V_5 ) ;
return V_44 ;
}
int F_34 ( struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_42 * V_75 = NULL ;
enum V_76 V_51 ;
int V_71 , V_44 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_62 . V_63 . V_77 )
V_5 -> V_62 . V_63 . V_77 = 100 ;
if ( ! V_5 -> V_62 . V_63 . V_50 ) {
for ( V_51 = 0 ; V_51 < V_78 ; V_51 ++ ) {
struct V_47 * V_48 ;
struct V_79 * V_80 ;
V_48 = V_28 -> V_14 . V_49 [ V_51 ] ;
if ( ! V_48 )
continue;
for ( V_71 = 0 ; V_71 < V_48 -> V_81 ; V_71 ++ ) {
V_80 = & V_48 -> V_82 [ V_71 ] ;
if ( V_80 -> V_31 & V_83 )
continue;
if ( V_80 -> V_31 & V_84 )
continue;
V_5 -> V_62 . V_63 . V_50 = V_80 ;
break;
}
if ( V_5 -> V_62 . V_63 . V_50 )
break;
}
if ( ! V_5 -> V_62 . V_63 . V_50 )
return - V_85 ;
}
if ( ! V_5 -> V_62 . V_63 . V_13 )
return 0 ;
if ( ! F_35 ( V_5 -> V_86 ) )
return 0 ;
if ( V_5 -> V_62 . V_87 ) {
V_5 -> V_62 . V_87 -> V_88 = V_5 -> V_62 . V_89 ;
V_5 -> V_62 . V_87 -> V_90 = V_5 -> V_62 . V_91 ;
}
V_5 -> V_62 . V_63 . V_92 = V_5 -> V_62 . V_89 != - 1 ;
if ( V_5 -> V_62 . V_87 ) {
V_75 = F_36 ( V_5 -> V_62 . V_87 , sizeof( * V_75 ) , V_21 ) ;
if ( ! V_75 )
return - V_93 ;
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
V_75 -> V_41 [ V_71 ] . V_94 = V_75 -> V_95 [ V_71 ] ;
}
V_44 = F_20 ( V_28 , V_5 -> V_86 ,
& V_5 -> V_62 . V_63 , V_75 ) ;
if ( V_44 )
F_23 ( V_75 ) ;
return V_44 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
struct V_79 * V_80 = NULL ;
int V_44 , V_101 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
if ( ! V_28 -> V_66 -> V_67 )
return - V_102 ;
V_101 = F_38 ( V_5 -> V_14 , V_99 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( V_101 ) {
V_80 = F_39 ( V_5 -> V_14 , V_101 ) ;
if ( ! V_80 )
return - V_85 ;
if ( V_80 -> V_31 & V_83 ||
V_80 -> V_31 & V_84 )
return - V_85 ;
}
if ( V_5 -> V_62 . V_63 . V_50 == V_80 )
return 0 ;
F_27 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_32 ( V_28 , V_2 , true ) ;
F_28 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_80 ) {
V_5 -> V_62 . V_63 . V_50 = V_80 ;
V_5 -> V_62 . V_63 . V_61 = true ;
} else {
V_5 -> V_62 . V_63 . V_61 = false ;
}
F_26 ( & V_28 -> V_69 ) ;
F_27 ( V_5 ) ;
V_44 = F_34 ( V_28 , V_5 ) ;
F_28 ( V_5 ) ;
F_29 ( & V_28 -> V_69 ) ;
return V_44 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_98 * V_101 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_79 * V_80 = NULL ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
F_27 ( V_5 ) ;
if ( V_5 -> V_17 )
V_80 = V_5 -> V_17 -> V_18 . V_50 ;
else if ( V_5 -> V_62 . V_63 . V_50 )
V_80 = V_5 -> V_62 . V_63 . V_50 ;
F_28 ( V_5 ) ;
if ( V_80 ) {
V_101 -> V_103 = V_80 -> V_104 ;
V_101 -> V_105 = 6 ;
return 0 ;
}
return - V_85 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_106 * V_95 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
T_4 V_107 = V_95 -> V_108 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
if ( ! V_28 -> V_66 -> V_67 )
return - V_102 ;
F_27 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_32 ( V_28 , V_2 , true ) ;
F_28 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_107 > 0 && V_15 [ V_107 - 1 ] == '\0' )
V_107 -- ;
V_5 -> V_62 . V_63 . V_15 = V_5 -> V_15 ;
memcpy ( V_5 -> V_62 . V_63 . V_15 , V_15 , V_107 ) ;
V_5 -> V_62 . V_63 . V_13 = V_107 ;
F_26 ( & V_28 -> V_69 ) ;
F_27 ( V_5 ) ;
V_44 = F_34 ( V_28 , V_5 ) ;
F_28 ( V_5 ) ;
F_29 ( & V_28 -> V_69 ) ;
return V_44 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_106 * V_95 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
V_95 -> V_31 = 0 ;
F_27 ( V_5 ) ;
if ( V_5 -> V_13 ) {
V_95 -> V_31 = 1 ;
V_95 -> V_108 = V_5 -> V_13 ;
memcpy ( V_15 , V_5 -> V_15 , V_95 -> V_108 ) ;
} else if ( V_5 -> V_62 . V_63 . V_15 && V_5 -> V_62 . V_63 . V_13 ) {
V_95 -> V_31 = 1 ;
V_95 -> V_108 = V_5 -> V_62 . V_63 . V_13 ;
memcpy ( V_15 , V_5 -> V_62 . V_63 . V_15 , V_95 -> V_108 ) ;
}
F_28 ( V_5 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_109 * V_22 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
T_1 * V_3 = V_22 -> V_23 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
if ( ! V_28 -> V_66 -> V_67 )
return - V_102 ;
if ( V_22 -> V_110 != V_111 )
return - V_85 ;
if ( F_44 ( V_3 ) || F_45 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_5 -> V_62 . V_63 . V_3 )
return 0 ;
if ( V_5 -> V_62 . V_63 . V_3 && V_3 &&
F_46 ( V_3 , V_5 -> V_62 . V_63 . V_3 ) )
return 0 ;
F_27 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_32 ( V_28 , V_2 , true ) ;
F_28 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_3 ) {
memcpy ( V_5 -> V_62 . V_3 , V_3 , V_24 ) ;
V_5 -> V_62 . V_63 . V_3 = V_5 -> V_62 . V_3 ;
} else
V_5 -> V_62 . V_63 . V_3 = NULL ;
F_26 ( & V_28 -> V_69 ) ;
F_27 ( V_5 ) ;
V_44 = F_34 ( V_28 , V_5 ) ;
F_28 ( V_5 ) ;
F_29 ( & V_28 -> V_69 ) ;
return V_44 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_109 * V_22 , char * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_85 ;
V_22 -> V_110 = V_111 ;
F_27 ( V_5 ) ;
if ( V_5 -> V_17 )
memcpy ( V_22 -> V_23 , V_5 -> V_17 -> V_18 . V_3 , V_24 ) ;
else if ( V_5 -> V_62 . V_63 . V_3 )
memcpy ( V_22 -> V_23 , V_5 -> V_62 . V_63 . V_3 , V_24 ) ;
else
memset ( V_22 -> V_23 , 0 , V_24 ) ;
F_28 ( V_5 ) ;
return 0 ;
}
