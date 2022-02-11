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
if ( ! ( V_7 -> V_16 -> V_21 & V_22 ) )
F_9 ( V_7 ) ;
F_10 ( F_11 ( V_7 -> V_16 ) , V_2 , V_3 ,
V_23 ) ;
#ifdef F_2
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
memcpy ( V_12 . V_24 . V_25 , V_3 , V_26 ) ;
F_12 ( V_2 , V_27 , & V_12 , NULL ) ;
#endif
}
void F_13 ( struct V_1 * V_2 , const T_1 * V_3 ,
struct V_4 * V_5 , T_2 V_28 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_29 * V_30 = F_11 ( V_7 -> V_16 ) ;
struct V_31 * V_32 ;
unsigned long V_21 ;
F_14 ( V_2 , V_3 , V_5 ) ;
if ( F_3 ( ! V_5 ) )
return;
V_32 = F_15 ( sizeof( * V_32 ) , V_28 ) ;
if ( ! V_32 )
return;
V_32 -> type = V_33 ;
memcpy ( V_32 -> V_34 . V_3 , V_3 , V_26 ) ;
V_32 -> V_34 . V_5 = V_5 ;
F_16 ( & V_7 -> V_35 , V_21 ) ;
F_17 ( & V_32 -> V_36 , & V_7 -> V_37 ) ;
F_18 ( & V_7 -> V_35 , V_21 ) ;
F_19 ( V_38 , & V_30 -> V_39 ) ;
}
static int F_20 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_15 )
return - V_45 ;
if ( ! V_41 -> V_46 ) {
struct V_47 * V_48 =
V_30 -> V_16 . V_49 [ V_41 -> V_50 . V_51 -> V_52 ] ;
int V_53 ;
T_3 V_54 = V_41 -> V_50 . V_51 -> V_52 == V_55 ?
V_56 :
V_57 ;
for ( V_53 = 0 ; V_53 < V_48 -> V_58 ; V_53 ++ ) {
if ( V_48 -> V_59 [ V_53 ] . V_21 & V_54 )
V_41 -> V_46 |= F_22 ( V_53 ) ;
}
}
if ( F_3 ( V_43 && V_43 -> V_60 < 0 ) )
return - V_61 ;
if ( F_3 ( V_7 -> V_62 ) )
F_23 ( V_7 -> V_62 ) ;
V_7 -> V_62 = V_43 ;
V_7 -> V_63 = V_41 -> V_64 ;
V_7 -> V_65 = V_41 -> V_66 ;
V_7 -> V_50 = V_41 -> V_50 ;
#ifdef F_2
V_7 -> V_67 . V_68 . V_50 = V_41 -> V_50 ;
#endif
V_44 = F_24 ( V_30 , V_2 , V_41 ) ;
if ( V_44 ) {
V_7 -> V_62 = NULL ;
return V_44 ;
}
memcpy ( V_7 -> V_69 , V_41 -> V_69 , V_41 -> V_15 ) ;
V_7 -> V_15 = V_41 -> V_15 ;
return 0 ;
}
int F_25 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_26 () ;
F_27 ( V_7 ) ;
V_44 = F_20 ( V_30 , V_2 , V_41 , V_43 ) ;
F_28 ( V_7 ) ;
return V_44 ;
}
static void F_29 ( struct V_1 * V_2 , bool V_70 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_29 * V_30 = F_11 ( V_7 -> V_16 ) ;
int V_71 ;
F_21 ( V_7 ) ;
F_23 ( V_7 -> V_62 ) ;
V_7 -> V_62 = NULL ;
F_30 ( V_30 , V_2 , NULL ) ;
if ( V_30 -> V_72 -> V_73 )
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
F_31 ( V_30 , V_2 , V_71 , false , NULL ) ;
if ( V_7 -> V_19 ) {
F_5 ( V_7 -> V_19 ) ;
F_6 ( V_7 -> V_16 , & V_7 -> V_19 -> V_20 ) ;
}
V_7 -> V_19 = NULL ;
V_7 -> V_15 = 0 ;
memset ( & V_7 -> V_50 , 0 , sizeof( V_7 -> V_50 ) ) ;
#ifdef F_2
if ( ! V_70 )
V_7 -> V_67 . V_68 . V_15 = 0 ;
#endif
F_32 ( V_30 ) ;
}
void F_33 ( struct V_1 * V_2 , bool V_70 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_27 ( V_7 ) ;
F_29 ( V_2 , V_70 ) ;
F_28 ( V_7 ) ;
}
int F_34 ( struct V_29 * V_30 ,
struct V_1 * V_2 , bool V_70 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_15 )
return - V_74 ;
V_44 = F_35 ( V_30 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_29 ( V_2 , V_70 ) ;
return 0 ;
}
int F_36 ( struct V_29 * V_30 ,
struct V_1 * V_2 , bool V_70 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_44 ;
F_27 ( V_7 ) ;
V_44 = F_34 ( V_30 , V_2 , V_70 ) ;
F_28 ( V_7 ) ;
return V_44 ;
}
int F_37 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_42 * V_75 = NULL ;
enum V_76 V_52 ;
int V_71 , V_44 ;
F_21 ( V_7 ) ;
if ( ! V_7 -> V_67 . V_68 . V_77 )
V_7 -> V_67 . V_68 . V_77 = 100 ;
if ( ! V_7 -> V_67 . V_68 . V_50 . V_51 ) {
struct V_4 * V_78 = NULL ;
for ( V_52 = 0 ; V_52 < V_79 ; V_52 ++ ) {
struct V_47 * V_48 ;
struct V_4 * V_51 ;
V_48 = V_30 -> V_16 . V_49 [ V_52 ] ;
if ( ! V_48 )
continue;
for ( V_71 = 0 ; V_71 < V_48 -> V_80 ; V_71 ++ ) {
V_51 = & V_48 -> V_81 [ V_71 ] ;
if ( V_51 -> V_21 & V_82 )
continue;
if ( V_51 -> V_21 & V_83 )
continue;
V_78 = V_51 ;
break;
}
if ( V_78 )
break;
}
if ( ! V_78 )
return - V_61 ;
F_38 ( & V_7 -> V_67 . V_68 . V_50 , V_78 ,
V_84 ) ;
}
if ( ! V_7 -> V_67 . V_68 . V_15 )
return 0 ;
if ( ! F_39 ( V_7 -> V_85 ) )
return 0 ;
if ( V_7 -> V_67 . V_86 )
V_7 -> V_67 . V_86 -> V_60 = V_7 -> V_67 . V_87 ;
V_7 -> V_67 . V_68 . V_88 = V_7 -> V_67 . V_87 != - 1 ;
if ( V_7 -> V_67 . V_86 && V_7 -> V_67 . V_86 -> V_60 != - 1 ) {
V_75 = F_40 ( V_7 -> V_67 . V_86 , sizeof( * V_75 ) , V_23 ) ;
if ( ! V_75 )
return - V_89 ;
for ( V_71 = 0 ; V_71 < V_90 ; V_71 ++ )
V_75 -> V_41 [ V_71 ] . V_91 = V_75 -> V_92 [ V_71 ] ;
}
V_44 = F_20 ( V_30 , V_7 -> V_85 ,
& V_7 -> V_67 . V_68 , V_75 ) ;
if ( V_44 )
F_41 ( V_75 ) ;
return V_44 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_95 * V_96 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_29 * V_30 = F_11 ( V_7 -> V_16 ) ;
struct V_4 * V_51 = NULL ;
int V_44 , V_98 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_61 ;
if ( ! V_30 -> V_72 -> V_99 )
return - V_100 ;
V_98 = F_43 ( V_96 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( V_98 ) {
V_51 = F_44 ( V_7 -> V_16 , V_98 ) ;
if ( ! V_51 )
return - V_61 ;
if ( V_51 -> V_21 & V_82 ||
V_51 -> V_21 & V_83 )
return - V_61 ;
}
if ( V_7 -> V_67 . V_68 . V_50 . V_51 == V_51 )
return 0 ;
F_27 ( V_7 ) ;
V_44 = 0 ;
if ( V_7 -> V_15 )
V_44 = F_34 ( V_30 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_44 )
return V_44 ;
if ( V_51 ) {
F_38 ( & V_7 -> V_67 . V_68 . V_50 , V_51 ,
V_84 ) ;
V_7 -> V_67 . V_68 . V_64 = true ;
} else {
V_7 -> V_67 . V_68 . V_64 = false ;
}
F_27 ( V_7 ) ;
V_44 = F_37 ( V_30 , V_7 ) ;
F_28 ( V_7 ) ;
return V_44 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_95 * V_98 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 * V_51 = NULL ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_61 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_19 )
V_51 = V_7 -> V_19 -> V_20 . V_5 ;
else if ( V_7 -> V_67 . V_68 . V_50 . V_51 )
V_51 = V_7 -> V_67 . V_68 . V_50 . V_51 ;
F_28 ( V_7 ) ;
if ( V_51 ) {
V_98 -> V_101 = V_51 -> V_102 ;
V_98 -> V_103 = 6 ;
return 0 ;
}
return - V_61 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_104 * V_92 , char * V_69 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_29 * V_30 = F_11 ( V_7 -> V_16 ) ;
T_4 V_105 = V_92 -> V_106 ;
int V_44 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_61 ;
if ( ! V_30 -> V_72 -> V_99 )
return - V_100 ;
F_27 ( V_7 ) ;
V_44 = 0 ;
if ( V_7 -> V_15 )
V_44 = F_34 ( V_30 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_44 )
return V_44 ;
if ( V_105 > 0 && V_69 [ V_105 - 1 ] == '\0' )
V_105 -- ;
memcpy ( V_7 -> V_69 , V_69 , V_105 ) ;
V_7 -> V_67 . V_68 . V_69 = V_7 -> V_69 ;
V_7 -> V_67 . V_68 . V_15 = V_105 ;
F_27 ( V_7 ) ;
V_44 = F_37 ( V_30 , V_7 ) ;
F_28 ( V_7 ) ;
return V_44 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_104 * V_92 , char * V_69 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_61 ;
V_92 -> V_21 = 0 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_15 ) {
V_92 -> V_21 = 1 ;
V_92 -> V_106 = V_7 -> V_15 ;
memcpy ( V_69 , V_7 -> V_69 , V_92 -> V_106 ) ;
} else if ( V_7 -> V_67 . V_68 . V_69 && V_7 -> V_67 . V_68 . V_15 ) {
V_92 -> V_21 = 1 ;
V_92 -> V_106 = V_7 -> V_67 . V_68 . V_15 ;
memcpy ( V_69 , V_7 -> V_67 . V_68 . V_69 , V_92 -> V_106 ) ;
}
F_28 ( V_7 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_107 * V_24 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_29 * V_30 = F_11 ( V_7 -> V_16 ) ;
T_1 * V_3 = V_24 -> V_25 ;
int V_44 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_61 ;
if ( ! V_30 -> V_72 -> V_99 )
return - V_100 ;
if ( V_24 -> V_108 != V_109 )
return - V_61 ;
if ( F_49 ( V_3 ) || F_50 ( V_3 ) )
V_3 = NULL ;
if ( V_3 && ! F_51 ( V_3 ) )
return - V_61 ;
if ( ! V_3 && ! V_7 -> V_67 . V_68 . V_3 )
return 0 ;
if ( V_7 -> V_67 . V_68 . V_3 && V_3 &&
F_52 ( V_3 , V_7 -> V_67 . V_68 . V_3 ) )
return 0 ;
F_27 ( V_7 ) ;
V_44 = 0 ;
if ( V_7 -> V_15 )
V_44 = F_34 ( V_30 , V_2 , true ) ;
F_28 ( V_7 ) ;
if ( V_44 )
return V_44 ;
if ( V_3 ) {
memcpy ( V_7 -> V_67 . V_3 , V_3 , V_26 ) ;
V_7 -> V_67 . V_68 . V_3 = V_7 -> V_67 . V_3 ;
} else
V_7 -> V_67 . V_68 . V_3 = NULL ;
F_27 ( V_7 ) ;
V_44 = F_37 ( V_30 , V_7 ) ;
F_28 ( V_7 ) ;
return V_44 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_107 * V_24 , char * V_97 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_3 ( V_7 -> V_13 != V_14 ) )
return - V_61 ;
V_24 -> V_108 = V_109 ;
F_27 ( V_7 ) ;
if ( V_7 -> V_19 )
memcpy ( V_24 -> V_25 , V_7 -> V_19 -> V_20 . V_3 , V_26 ) ;
else if ( V_7 -> V_67 . V_68 . V_3 )
memcpy ( V_24 -> V_25 , V_7 -> V_67 . V_68 . V_3 , V_26 ) ;
else
F_54 ( V_24 -> V_25 ) ;
F_28 ( V_7 ) ;
return 0 ;
}
