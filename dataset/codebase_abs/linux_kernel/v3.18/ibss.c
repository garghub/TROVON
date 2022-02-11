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
int V_42 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_15 )
return - V_43 ;
if ( ! V_39 -> V_44 ) {
struct V_45 * V_46 =
V_27 -> V_16 . V_47 [ V_39 -> V_48 . V_49 -> V_50 ] ;
int V_51 ;
T_3 V_52 = V_39 -> V_48 . V_49 -> V_50 == V_53 ?
V_54 :
V_55 ;
for ( V_51 = 0 ; V_51 < V_46 -> V_56 ; V_51 ++ ) {
if ( V_46 -> V_57 [ V_51 ] . V_30 & V_52 )
V_39 -> V_44 |= F_22 ( V_51 ) ;
}
}
if ( F_3 ( V_7 -> V_58 ) )
F_23 ( V_7 -> V_58 ) ;
V_7 -> V_58 = V_41 ;
V_7 -> V_59 = V_39 -> V_60 ;
V_7 -> V_61 = V_39 -> V_62 ;
V_7 -> V_48 = V_39 -> V_48 ;
#ifdef F_2
V_7 -> V_63 . V_64 . V_48 = V_39 -> V_48 ;
#endif
V_42 = F_24 ( V_27 , V_2 , V_39 ) ;
if ( V_42 ) {
V_7 -> V_58 = NULL ;
return V_42 ;
}
memcpy ( V_7 -> V_65 , V_39 -> V_65 , V_39 -> V_15 ) ;
V_7 -> V_15 = V_39 -> V_15 ;
return 0 ;
}
int F_25 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_42 ;
F_26 () ;
F_27 ( V_7 ) ;
V_42 = F_20 ( V_27 , V_2 , V_39 , V_41 ) ;
F_28 ( V_7 ) ;
return V_42 ;
}
static void F_29 ( struct V_1 * V_2 , bool V_66 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
int V_67 ;
F_21 ( V_7 ) ;
F_23 ( V_7 -> V_58 ) ;
V_7 -> V_58 = NULL ;
F_30 ( V_27 , V_2 , NULL ) ;
if ( V_27 -> V_68 -> V_69 )
for ( V_67 = 0 ; V_67 < 6 ; V_67 ++ )
F_31 ( V_27 , V_2 , V_67 , false , NULL ) ;
if ( V_7 -> V_18 ) {
F_5 ( V_7 -> V_18 ) ;
F_6 ( V_7 -> V_16 , & V_7 -> V_18 -> V_19 ) ;
}
V_7 -> V_18 = NULL ;
V_7 -> V_15 = 0 ;
memset ( & V_7 -> V_48 , 0 , sizeof( V_7 -> V_48 ) ) ;
#ifdef F_2
if ( ! V_66 )
V_7 -> V_63 . V_64 . V_15 = 0 ;
#endif
}
void F_32 ( struct V_1 * V_2 , bool V_66 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_27 ( V_7 ) ;
F_29 ( V_2 , V_66 ) ;
F_28 ( V_7 ) ;
}
int F_33 ( struct V_26 * V_27 ,
struct V_1 * V_2 , bool V_66 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_42 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_15 )
return - V_70 ;
V_42 = F_34 ( V_27 , V_2 ) ;
if ( V_42 )
return V_42 ;
F_29 ( V_2 , V_66 ) ;
return 0 ;
}
int F_35 ( struct V_26 * V_27 ,
struct V_1 * V_2 , bool V_66 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_42 ;
F_27 ( V_7 ) ;
V_42 = F_33 ( V_27 , V_2 , V_66 ) ;
F_28 ( V_7 ) ;
return V_42 ;
}
int F_36 ( struct V_26 * V_27 ,
struct V_6 * V_7 )
{
struct V_40 * V_71 = NULL ;
enum V_72 V_50 ;
int V_67 , V_42 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_63 . V_64 . V_73 )
V_7 -> V_63 . V_64 . V_73 = 100 ;
if ( ! V_7 -> V_63 . V_64 . V_48 . V_49 ) {
struct V_4 * V_74 = NULL ;
for ( V_50 = 0 ; V_50 < V_75 ; V_50 ++ ) {
struct V_45 * V_46 ;
struct V_4 * V_49 ;
V_46 = V_27 -> V_16 . V_47 [ V_50 ] ;
if ( ! V_46 )
continue;
for ( V_67 = 0 ; V_67 < V_46 -> V_76 ; V_67 ++ ) {
V_49 = & V_46 -> V_77 [ V_67 ] ;
if ( V_49 -> V_30 & V_78 )
continue;
if ( V_49 -> V_30 & V_79 )
continue;
V_74 = V_49 ;
break;
}
if ( V_74 )
break;
}
if ( ! V_74 )
return - V_80 ;
F_37 ( & V_7 -> V_63 . V_64 . V_48 , V_74 ,
V_81 ) ;
}
if ( ! V_7 -> V_63 . V_64 . V_15 )
return 0 ;
if ( ! F_38 ( V_7 -> V_82 ) )
return 0 ;
if ( V_7 -> V_63 . V_83 ) {
V_7 -> V_63 . V_83 -> V_84 = V_7 -> V_63 . V_85 ;
V_7 -> V_63 . V_83 -> V_86 = V_7 -> V_63 . V_87 ;
}
V_7 -> V_63 . V_64 . V_88 = V_7 -> V_63 . V_85 != - 1 ;
if ( V_7 -> V_63 . V_83 ) {
V_71 = F_39 ( V_7 -> V_63 . V_83 , sizeof( * V_71 ) , V_20 ) ;
if ( ! V_71 )
return - V_89 ;
for ( V_67 = 0 ; V_67 < 6 ; V_67 ++ )
V_71 -> V_39 [ V_67 ] . V_90 = V_71 -> V_91 [ V_67 ] ;
}
V_42 = F_20 ( V_27 , V_7 -> V_82 ,
& V_7 -> V_63 . V_64 , V_71 ) ;
if ( V_42 )
F_40 ( V_71 ) ;
return V_42 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_94 * V_95 , char * V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
struct V_4 * V_49 = NULL ;
int V_42 , V_97 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_80 ;
if ( ! V_27 -> V_68 -> V_98 )
return - V_99 ;
V_97 = F_42 ( V_95 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_97 ) {
V_49 = F_43 ( V_7 -> V_16 , V_97 ) ;
if ( ! V_49 )
return - V_80 ;
if ( V_49 -> V_30 & V_78 ||
V_49 -> V_30 & V_79 )
return - V_80 ;
}
if ( V_7 -> V_63 . V_64 . V_48 . V_49 == V_49 )
return 0 ;
F_27 ( V_7 ) ;
V_42 = 0 ;
if ( V_7 -> V_15 )
V_42 = F_33 ( V_27 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_42 )
return V_42 ;
if ( V_49 ) {
F_37 ( & V_7 -> V_63 . V_64 . V_48 , V_49 ,
V_81 ) ;
V_7 -> V_63 . V_64 . V_60 = true ;
} else {
V_7 -> V_63 . V_64 . V_60 = false ;
}
F_27 ( V_7 ) ;
V_42 = F_36 ( V_27 , V_7 ) ;
F_28 ( V_7 ) ;
return V_42 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_94 * V_97 , char * V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 * V_49 = NULL ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_80 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_18 )
V_49 = V_7 -> V_18 -> V_19 . V_5 ;
else if ( V_7 -> V_63 . V_64 . V_48 . V_49 )
V_49 = V_7 -> V_63 . V_64 . V_48 . V_49 ;
F_28 ( V_7 ) ;
if ( V_49 ) {
V_97 -> V_100 = V_49 -> V_101 ;
V_97 -> V_102 = 6 ;
return 0 ;
}
return - V_80 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_103 * V_91 , char * V_65 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
T_4 V_104 = V_91 -> V_105 ;
int V_42 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_80 ;
if ( ! V_27 -> V_68 -> V_98 )
return - V_99 ;
F_27 ( V_7 ) ;
V_42 = 0 ;
if ( V_7 -> V_15 )
V_42 = F_33 ( V_27 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_42 )
return V_42 ;
if ( V_104 > 0 && V_65 [ V_104 - 1 ] == '\0' )
V_104 -- ;
memcpy ( V_7 -> V_65 , V_65 , V_104 ) ;
V_7 -> V_63 . V_64 . V_65 = V_7 -> V_65 ;
V_7 -> V_63 . V_64 . V_15 = V_104 ;
F_27 ( V_7 ) ;
V_42 = F_36 ( V_27 , V_7 ) ;
F_28 ( V_7 ) ;
return V_42 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_103 * V_91 , char * V_65 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_80 ;
V_91 -> V_30 = 0 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_15 ) {
V_91 -> V_30 = 1 ;
V_91 -> V_105 = V_7 -> V_15 ;
memcpy ( V_65 , V_7 -> V_65 , V_91 -> V_105 ) ;
} else if ( V_7 -> V_63 . V_64 . V_65 && V_7 -> V_63 . V_64 . V_15 ) {
V_91 -> V_30 = 1 ;
V_91 -> V_105 = V_7 -> V_63 . V_64 . V_15 ;
memcpy ( V_65 , V_7 -> V_63 . V_64 . V_65 , V_91 -> V_105 ) ;
}
F_28 ( V_7 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_106 * V_21 , char * V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = F_11 ( V_7 -> V_16 ) ;
T_1 * V_3 = V_21 -> V_22 ;
int V_42 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_80 ;
if ( ! V_27 -> V_68 -> V_98 )
return - V_99 ;
if ( V_21 -> V_107 != V_108 )
return - V_80 ;
if ( F_48 ( V_3 ) || F_49 ( V_3 ) )
V_3 = NULL ;
if ( V_3 && ! F_50 ( V_3 ) )
return - V_80 ;
if ( ! V_3 && ! V_7 -> V_63 . V_64 . V_3 )
return 0 ;
if ( V_7 -> V_63 . V_64 . V_3 && V_3 &&
F_51 ( V_3 , V_7 -> V_63 . V_64 . V_3 ) )
return 0 ;
F_27 ( V_7 ) ;
V_42 = 0 ;
if ( V_7 -> V_15 )
V_42 = F_33 ( V_27 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_42 )
return V_42 ;
if ( V_3 ) {
memcpy ( V_7 -> V_63 . V_3 , V_3 , V_23 ) ;
V_7 -> V_63 . V_64 . V_3 = V_7 -> V_63 . V_3 ;
} else
V_7 -> V_63 . V_64 . V_3 = NULL ;
F_27 ( V_7 ) ;
V_42 = F_36 ( V_27 , V_7 ) ;
F_28 ( V_7 ) ;
return V_42 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_106 * V_21 , char * V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_80 ;
V_21 -> V_107 = V_108 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_18 )
memcpy ( V_21 -> V_22 , V_7 -> V_18 -> V_19 . V_3 , V_23 ) ;
else if ( V_7 -> V_63 . V_64 . V_3 )
memcpy ( V_21 -> V_22 , V_7 -> V_63 . V_64 . V_3 , V_23 ) ;
else
memset ( V_21 -> V_22 , 0 , V_23 ) ;
F_28 ( V_7 ) ;
return 0 ;
}
