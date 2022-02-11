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
#ifdef F_2
V_5 -> V_60 . V_61 . V_50 = V_41 -> V_50 ;
#endif
V_5 -> V_19 = V_32 ;
V_44 = V_28 -> V_62 -> V_63 ( & V_28 -> V_14 , V_2 , V_41 ) ;
if ( V_44 ) {
V_5 -> V_59 = NULL ;
V_5 -> V_19 = V_64 ;
return V_44 ;
}
memcpy ( V_5 -> V_15 , V_41 -> V_15 , V_41 -> V_13 ) ;
V_5 -> V_13 = V_41 -> V_13 ;
return 0 ;
}
int F_24 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_25 ( & V_28 -> V_65 ) ;
F_26 ( V_5 ) ;
V_44 = F_20 ( V_28 , V_2 , V_41 , V_43 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_28 -> V_65 ) ;
return V_44 ;
}
static void F_29 ( struct V_1 * V_2 , bool V_66 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
int V_67 ;
F_21 ( V_5 ) ;
F_23 ( V_5 -> V_59 ) ;
V_5 -> V_59 = NULL ;
if ( V_28 -> V_62 -> V_68 )
for ( V_67 = 0 ; V_67 < 6 ; V_67 ++ )
V_28 -> V_62 -> V_68 ( V_5 -> V_14 , V_2 , V_67 , false , NULL ) ;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( & V_5 -> V_17 -> V_18 ) ;
}
V_5 -> V_17 = NULL ;
V_5 -> V_19 = V_64 ;
V_5 -> V_13 = 0 ;
#ifdef F_2
if ( ! V_66 )
V_5 -> V_60 . V_61 . V_13 = 0 ;
#endif
}
void F_30 ( struct V_1 * V_2 , bool V_66 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_26 ( V_5 ) ;
F_29 ( V_2 , V_66 ) ;
F_27 ( V_5 ) ;
}
int F_31 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_66 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_13 )
return - V_69 ;
V_44 = V_28 -> V_62 -> V_70 ( & V_28 -> V_14 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_29 ( V_2 , V_66 ) ;
return 0 ;
}
int F_32 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_66 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_44 ;
F_26 ( V_5 ) ;
V_44 = F_31 ( V_28 , V_2 , V_66 ) ;
F_27 ( V_5 ) ;
return V_44 ;
}
int F_33 ( struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_42 * V_71 = NULL ;
enum V_72 V_51 ;
int V_67 , V_44 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_60 . V_61 . V_73 )
V_5 -> V_60 . V_61 . V_73 = 100 ;
if ( ! V_5 -> V_60 . V_61 . V_50 ) {
for ( V_51 = 0 ; V_51 < V_74 ; V_51 ++ ) {
struct V_47 * V_48 ;
struct V_75 * V_76 ;
V_48 = V_28 -> V_14 . V_49 [ V_51 ] ;
if ( ! V_48 )
continue;
for ( V_67 = 0 ; V_67 < V_48 -> V_77 ; V_67 ++ ) {
V_76 = & V_48 -> V_78 [ V_67 ] ;
if ( V_76 -> V_31 & V_79 )
continue;
if ( V_76 -> V_31 & V_80 )
continue;
V_5 -> V_60 . V_61 . V_50 = V_76 ;
break;
}
if ( V_5 -> V_60 . V_61 . V_50 )
break;
}
if ( ! V_5 -> V_60 . V_61 . V_50 )
return - V_81 ;
}
if ( ! V_5 -> V_60 . V_61 . V_13 )
return 0 ;
if ( ! F_34 ( V_5 -> V_82 ) )
return 0 ;
if ( V_5 -> V_60 . V_83 ) {
V_5 -> V_60 . V_83 -> V_84 = V_5 -> V_60 . V_85 ;
V_5 -> V_60 . V_83 -> V_86 = V_5 -> V_60 . V_87 ;
}
V_5 -> V_60 . V_61 . V_88 = V_5 -> V_60 . V_85 != - 1 ;
if ( V_5 -> V_60 . V_83 ) {
V_71 = F_35 ( V_5 -> V_60 . V_83 , sizeof( * V_71 ) , V_21 ) ;
if ( ! V_71 )
return - V_89 ;
for ( V_67 = 0 ; V_67 < 6 ; V_67 ++ )
V_71 -> V_41 [ V_67 ] . V_90 = V_71 -> V_91 [ V_67 ] ;
}
V_44 = F_20 ( V_28 , V_5 -> V_82 ,
& V_5 -> V_60 . V_61 , V_71 ) ;
if ( V_44 )
F_23 ( V_71 ) ;
return V_44 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_94 * V_95 , char * V_96 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
struct V_75 * V_76 = NULL ;
int V_44 , V_97 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_81 ;
if ( ! V_28 -> V_62 -> V_63 )
return - V_98 ;
V_97 = F_37 ( V_5 -> V_14 , V_95 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_97 ) {
V_76 = F_38 ( V_5 -> V_14 , V_97 ) ;
if ( ! V_76 )
return - V_81 ;
if ( V_76 -> V_31 & V_79 ||
V_76 -> V_31 & V_80 )
return - V_81 ;
}
if ( V_5 -> V_60 . V_61 . V_50 == V_76 )
return 0 ;
F_26 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_31 ( V_28 , V_2 , true ) ;
F_27 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_76 ) {
V_5 -> V_60 . V_61 . V_50 = V_76 ;
V_5 -> V_60 . V_61 . V_99 = true ;
} else {
V_5 -> V_60 . V_61 . V_99 = false ;
}
F_25 ( & V_28 -> V_65 ) ;
F_26 ( V_5 ) ;
V_44 = F_33 ( V_28 , V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_28 -> V_65 ) ;
return V_44 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_94 * V_97 , char * V_96 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_75 * V_76 = NULL ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_81 ;
F_26 ( V_5 ) ;
if ( V_5 -> V_17 )
V_76 = V_5 -> V_17 -> V_18 . V_50 ;
else if ( V_5 -> V_60 . V_61 . V_50 )
V_76 = V_5 -> V_60 . V_61 . V_50 ;
F_27 ( V_5 ) ;
if ( V_76 ) {
V_97 -> V_100 = V_76 -> V_101 ;
V_97 -> V_102 = 6 ;
return 0 ;
}
return - V_81 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_103 * V_91 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
T_4 V_104 = V_91 -> V_105 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_81 ;
if ( ! V_28 -> V_62 -> V_63 )
return - V_98 ;
F_26 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_31 ( V_28 , V_2 , true ) ;
F_27 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_104 > 0 && V_15 [ V_104 - 1 ] == '\0' )
V_104 -- ;
V_5 -> V_60 . V_61 . V_15 = V_5 -> V_15 ;
memcpy ( V_5 -> V_60 . V_61 . V_15 , V_15 , V_104 ) ;
V_5 -> V_60 . V_61 . V_13 = V_104 ;
F_25 ( & V_28 -> V_65 ) ;
F_26 ( V_5 ) ;
V_44 = F_33 ( V_28 , V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_28 -> V_65 ) ;
return V_44 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_103 * V_91 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_81 ;
V_91 -> V_31 = 0 ;
F_26 ( V_5 ) ;
if ( V_5 -> V_13 ) {
V_91 -> V_31 = 1 ;
V_91 -> V_105 = V_5 -> V_13 ;
memcpy ( V_15 , V_5 -> V_15 , V_91 -> V_105 ) ;
} else if ( V_5 -> V_60 . V_61 . V_15 && V_5 -> V_60 . V_61 . V_13 ) {
V_91 -> V_31 = 1 ;
V_91 -> V_105 = V_5 -> V_60 . V_61 . V_13 ;
memcpy ( V_15 , V_5 -> V_60 . V_61 . V_15 , V_91 -> V_105 ) ;
}
F_27 ( V_5 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_106 * V_22 , char * V_96 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 = F_11 ( V_5 -> V_14 ) ;
T_1 * V_3 = V_22 -> V_23 ;
int V_44 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_81 ;
if ( ! V_28 -> V_62 -> V_63 )
return - V_98 ;
if ( V_22 -> V_107 != V_108 )
return - V_81 ;
if ( F_43 ( V_3 ) || F_44 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_5 -> V_60 . V_61 . V_3 )
return 0 ;
if ( V_5 -> V_60 . V_61 . V_3 && V_3 &&
F_45 ( V_3 , V_5 -> V_60 . V_61 . V_3 ) )
return 0 ;
F_26 ( V_5 ) ;
V_44 = 0 ;
if ( V_5 -> V_13 )
V_44 = F_31 ( V_28 , V_2 , true ) ;
F_27 ( V_5 ) ;
if ( V_44 )
return V_44 ;
if ( V_3 ) {
memcpy ( V_5 -> V_60 . V_3 , V_3 , V_24 ) ;
V_5 -> V_60 . V_61 . V_3 = V_5 -> V_60 . V_3 ;
} else
V_5 -> V_60 . V_61 . V_3 = NULL ;
F_25 ( & V_28 -> V_65 ) ;
F_26 ( V_5 ) ;
V_44 = F_33 ( V_28 , V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_28 -> V_65 ) ;
return V_44 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_106 * V_22 , char * V_96 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_81 ;
V_22 -> V_107 = V_108 ;
F_26 ( V_5 ) ;
if ( V_5 -> V_17 )
memcpy ( V_22 -> V_23 , V_5 -> V_17 -> V_18 . V_3 , V_24 ) ;
else if ( V_5 -> V_60 . V_61 . V_3 )
memcpy ( V_22 -> V_23 , V_5 -> V_60 . V_61 . V_3 , V_24 ) ;
else
memset ( V_22 -> V_23 , 0 , V_24 ) ;
F_27 ( V_5 ) ;
return 0 ;
}
