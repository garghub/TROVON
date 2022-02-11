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
V_17 , V_18 ) ;
if ( F_3 ( ! V_10 ) )
return;
if ( V_7 -> V_19 ) {
F_5 ( V_7 -> V_19 ) ;
F_6 ( V_7 -> V_16 , & V_7 -> V_19 -> V_20 ) ;
}
F_7 ( F_8 ( V_10 ) ) ;
V_7 -> V_19 = F_8 ( V_10 ) ;
F_9 ( V_7 ) ;
F_10 ( F_11 ( V_7 -> V_16 ) , V_2 , V_3 ,
V_21 ) ;
#ifdef F_2
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
memcpy ( V_12 . V_22 . V_23 , V_3 , V_24 ) ;
F_12 ( V_2 , V_25 , & V_12 , NULL ) ;
#endif
}
void F_13 ( struct V_1 * V_2 , const T_1 * V_3 ,
struct V_4 * V_5 , T_2 V_26 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = F_11 ( V_7 -> V_16 ) ;
struct V_29 * V_30 ;
unsigned long V_31 ;
F_14 ( V_2 , V_3 , V_5 ) ;
if ( F_3 ( ! V_5 ) )
return;
V_30 = F_15 ( sizeof( * V_30 ) , V_26 ) ;
if ( ! V_30 )
return;
V_30 -> type = V_32 ;
memcpy ( V_30 -> V_33 . V_3 , V_3 , V_24 ) ;
V_30 -> V_33 . V_5 = V_5 ;
F_16 ( & V_7 -> V_34 , V_31 ) ;
F_17 ( & V_30 -> V_35 , & V_7 -> V_36 ) ;
F_18 ( & V_7 -> V_34 , V_31 ) ;
F_19 ( V_37 , & V_28 -> V_38 ) ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_43 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_15 )
return - V_44 ;
if ( ! V_40 -> V_45 ) {
struct V_46 * V_47 =
V_28 -> V_16 . V_48 [ V_40 -> V_49 . V_50 -> V_51 ] ;
int V_52 ;
T_3 V_53 = V_40 -> V_49 . V_50 -> V_51 == V_54 ?
V_55 :
V_56 ;
for ( V_52 = 0 ; V_52 < V_47 -> V_57 ; V_52 ++ ) {
if ( V_47 -> V_58 [ V_52 ] . V_31 & V_53 )
V_40 -> V_45 |= F_22 ( V_52 ) ;
}
}
if ( F_3 ( V_7 -> V_59 ) )
F_23 ( V_7 -> V_59 ) ;
V_7 -> V_59 = V_42 ;
V_7 -> V_60 = V_40 -> V_61 ;
V_7 -> V_62 = V_40 -> V_63 ;
V_7 -> V_49 = V_40 -> V_49 ;
#ifdef F_2
V_7 -> V_64 . V_65 . V_49 = V_40 -> V_49 ;
#endif
V_43 = F_24 ( V_28 , V_2 , V_40 ) ;
if ( V_43 ) {
V_7 -> V_59 = NULL ;
return V_43 ;
}
memcpy ( V_7 -> V_66 , V_40 -> V_66 , V_40 -> V_15 ) ;
V_7 -> V_15 = V_40 -> V_15 ;
return 0 ;
}
int F_25 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_43 ;
F_26 () ;
F_27 ( V_7 ) ;
V_43 = F_20 ( V_28 , V_2 , V_40 , V_42 ) ;
F_28 ( V_7 ) ;
return V_43 ;
}
static void F_29 ( struct V_1 * V_2 , bool V_67 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = F_11 ( V_7 -> V_16 ) ;
int V_68 ;
F_21 ( V_7 ) ;
F_23 ( V_7 -> V_59 ) ;
V_7 -> V_59 = NULL ;
F_30 ( V_28 , V_2 , NULL ) ;
if ( V_28 -> V_69 -> V_70 )
for ( V_68 = 0 ; V_68 < 6 ; V_68 ++ )
F_31 ( V_28 , V_2 , V_68 , false , NULL ) ;
if ( V_7 -> V_19 ) {
F_5 ( V_7 -> V_19 ) ;
F_6 ( V_7 -> V_16 , & V_7 -> V_19 -> V_20 ) ;
}
V_7 -> V_19 = NULL ;
V_7 -> V_15 = 0 ;
memset ( & V_7 -> V_49 , 0 , sizeof( V_7 -> V_49 ) ) ;
#ifdef F_2
if ( ! V_67 )
V_7 -> V_64 . V_65 . V_15 = 0 ;
#endif
}
void F_32 ( struct V_1 * V_2 , bool V_67 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_27 ( V_7 ) ;
F_29 ( V_2 , V_67 ) ;
F_28 ( V_7 ) ;
}
int F_33 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_67 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_43 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_15 )
return - V_71 ;
V_43 = F_34 ( V_28 , V_2 ) ;
if ( V_43 )
return V_43 ;
F_29 ( V_2 , V_67 ) ;
return 0 ;
}
int F_35 ( struct V_27 * V_28 ,
struct V_1 * V_2 , bool V_67 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_43 ;
F_27 ( V_7 ) ;
V_43 = F_33 ( V_28 , V_2 , V_67 ) ;
F_28 ( V_7 ) ;
return V_43 ;
}
int F_36 ( struct V_27 * V_28 ,
struct V_6 * V_7 )
{
struct V_41 * V_72 = NULL ;
enum V_73 V_51 ;
int V_68 , V_43 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_64 . V_65 . V_74 )
V_7 -> V_64 . V_65 . V_74 = 100 ;
if ( ! V_7 -> V_64 . V_65 . V_49 . V_50 ) {
struct V_4 * V_75 = NULL ;
for ( V_51 = 0 ; V_51 < V_76 ; V_51 ++ ) {
struct V_46 * V_47 ;
struct V_4 * V_50 ;
V_47 = V_28 -> V_16 . V_48 [ V_51 ] ;
if ( ! V_47 )
continue;
for ( V_68 = 0 ; V_68 < V_47 -> V_77 ; V_68 ++ ) {
V_50 = & V_47 -> V_78 [ V_68 ] ;
if ( V_50 -> V_31 & V_79 )
continue;
if ( V_50 -> V_31 & V_80 )
continue;
V_75 = V_50 ;
break;
}
if ( V_75 )
break;
}
if ( ! V_75 )
return - V_81 ;
F_37 ( & V_7 -> V_64 . V_65 . V_49 , V_75 ,
V_82 ) ;
}
if ( ! V_7 -> V_64 . V_65 . V_15 )
return 0 ;
if ( ! F_38 ( V_7 -> V_83 ) )
return 0 ;
if ( V_7 -> V_64 . V_84 ) {
V_7 -> V_64 . V_84 -> V_85 = V_7 -> V_64 . V_86 ;
V_7 -> V_64 . V_84 -> V_87 = V_7 -> V_64 . V_88 ;
}
V_7 -> V_64 . V_65 . V_89 = V_7 -> V_64 . V_86 != - 1 ;
if ( V_7 -> V_64 . V_84 ) {
V_72 = F_39 ( V_7 -> V_64 . V_84 , sizeof( * V_72 ) , V_21 ) ;
if ( ! V_72 )
return - V_90 ;
for ( V_68 = 0 ; V_68 < 6 ; V_68 ++ )
V_72 -> V_40 [ V_68 ] . V_91 = V_72 -> V_92 [ V_68 ] ;
}
V_43 = F_20 ( V_28 , V_7 -> V_83 ,
& V_7 -> V_64 . V_65 , V_72 ) ;
if ( V_43 )
F_40 ( V_72 ) ;
return V_43 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_95 * V_96 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = F_11 ( V_7 -> V_16 ) ;
struct V_4 * V_50 = NULL ;
int V_43 , V_98 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_81 ;
if ( ! V_28 -> V_69 -> V_99 )
return - V_100 ;
V_98 = F_42 ( V_96 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( V_98 ) {
V_50 = F_43 ( V_7 -> V_16 , V_98 ) ;
if ( ! V_50 )
return - V_81 ;
if ( V_50 -> V_31 & V_79 ||
V_50 -> V_31 & V_80 )
return - V_81 ;
}
if ( V_7 -> V_64 . V_65 . V_49 . V_50 == V_50 )
return 0 ;
F_27 ( V_7 ) ;
V_43 = 0 ;
if ( V_7 -> V_15 )
V_43 = F_33 ( V_28 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_43 )
return V_43 ;
if ( V_50 ) {
F_37 ( & V_7 -> V_64 . V_65 . V_49 , V_50 ,
V_82 ) ;
V_7 -> V_64 . V_65 . V_61 = true ;
} else {
V_7 -> V_64 . V_65 . V_61 = false ;
}
F_27 ( V_7 ) ;
V_43 = F_36 ( V_28 , V_7 ) ;
F_28 ( V_7 ) ;
return V_43 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_95 * V_98 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 * V_50 = NULL ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_81 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_19 )
V_50 = V_7 -> V_19 -> V_20 . V_5 ;
else if ( V_7 -> V_64 . V_65 . V_49 . V_50 )
V_50 = V_7 -> V_64 . V_65 . V_49 . V_50 ;
F_28 ( V_7 ) ;
if ( V_50 ) {
V_98 -> V_101 = V_50 -> V_102 ;
V_98 -> V_103 = 6 ;
return 0 ;
}
return - V_81 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_104 * V_92 , char * V_66 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = F_11 ( V_7 -> V_16 ) ;
T_4 V_105 = V_92 -> V_106 ;
int V_43 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_81 ;
if ( ! V_28 -> V_69 -> V_99 )
return - V_100 ;
F_27 ( V_7 ) ;
V_43 = 0 ;
if ( V_7 -> V_15 )
V_43 = F_33 ( V_28 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_43 )
return V_43 ;
if ( V_105 > 0 && V_66 [ V_105 - 1 ] == '\0' )
V_105 -- ;
memcpy ( V_7 -> V_66 , V_66 , V_105 ) ;
V_7 -> V_64 . V_65 . V_66 = V_7 -> V_66 ;
V_7 -> V_64 . V_65 . V_15 = V_105 ;
F_27 ( V_7 ) ;
V_43 = F_36 ( V_28 , V_7 ) ;
F_28 ( V_7 ) ;
return V_43 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_104 * V_92 , char * V_66 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_81 ;
V_92 -> V_31 = 0 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_15 ) {
V_92 -> V_31 = 1 ;
V_92 -> V_106 = V_7 -> V_15 ;
memcpy ( V_66 , V_7 -> V_66 , V_92 -> V_106 ) ;
} else if ( V_7 -> V_64 . V_65 . V_66 && V_7 -> V_64 . V_65 . V_15 ) {
V_92 -> V_31 = 1 ;
V_92 -> V_106 = V_7 -> V_64 . V_65 . V_15 ;
memcpy ( V_66 , V_7 -> V_64 . V_65 . V_66 , V_92 -> V_106 ) ;
}
F_28 ( V_7 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_107 * V_22 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = F_11 ( V_7 -> V_16 ) ;
T_1 * V_3 = V_22 -> V_23 ;
int V_43 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_81 ;
if ( ! V_28 -> V_69 -> V_99 )
return - V_100 ;
if ( V_22 -> V_108 != V_109 )
return - V_81 ;
if ( F_48 ( V_3 ) || F_49 ( V_3 ) )
V_3 = NULL ;
if ( V_3 && ! F_50 ( V_3 ) )
return - V_81 ;
if ( ! V_3 && ! V_7 -> V_64 . V_65 . V_3 )
return 0 ;
if ( V_7 -> V_64 . V_65 . V_3 && V_3 &&
F_51 ( V_3 , V_7 -> V_64 . V_65 . V_3 ) )
return 0 ;
F_27 ( V_7 ) ;
V_43 = 0 ;
if ( V_7 -> V_15 )
V_43 = F_33 ( V_28 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_43 )
return V_43 ;
if ( V_3 ) {
memcpy ( V_7 -> V_64 . V_3 , V_3 , V_24 ) ;
V_7 -> V_64 . V_65 . V_3 = V_7 -> V_64 . V_3 ;
} else
V_7 -> V_64 . V_65 . V_3 = NULL ;
F_27 ( V_7 ) ;
V_43 = F_36 ( V_28 , V_7 ) ;
F_28 ( V_7 ) ;
return V_43 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_107 * V_22 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_81 ;
V_22 -> V_108 = V_109 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_19 )
memcpy ( V_22 -> V_23 , V_7 -> V_19 -> V_20 . V_3 , V_24 ) ;
else if ( V_7 -> V_64 . V_65 . V_3 )
memcpy ( V_22 -> V_23 , V_7 -> V_64 . V_65 . V_3 , V_24 ) ;
else
F_53 ( V_22 -> V_23 ) ;
F_28 ( V_7 ) ;
return 0 ;
}
