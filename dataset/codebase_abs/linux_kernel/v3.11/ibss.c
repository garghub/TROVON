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
int V_41 ;
F_21 ( V_5 ) ;
if ( V_5 -> V_13 )
return - V_42 ;
if ( ! V_38 -> V_43 ) {
struct V_44 * V_45 =
V_26 -> V_14 . V_46 [ V_38 -> V_47 . V_48 -> V_49 ] ;
int V_50 ;
T_3 V_51 = V_38 -> V_47 . V_48 -> V_49 == V_52 ?
V_53 :
V_54 ;
for ( V_50 = 0 ; V_50 < V_45 -> V_55 ; V_50 ++ ) {
if ( V_45 -> V_56 [ V_50 ] . V_29 & V_51 )
V_38 -> V_43 |= F_22 ( V_50 ) ;
}
}
if ( F_3 ( V_5 -> V_57 ) )
F_23 ( V_5 -> V_57 ) ;
V_5 -> V_57 = V_40 ;
V_5 -> V_58 = V_38 -> V_59 ;
#ifdef F_2
V_5 -> V_60 . V_61 . V_47 = V_38 -> V_47 ;
#endif
V_41 = F_24 ( V_26 , V_5 , V_38 -> V_47 . V_48 ,
V_38 -> V_59
? V_62
: V_63 ) ;
if ( V_41 ) {
V_5 -> V_57 = NULL ;
return V_41 ;
}
V_41 = F_25 ( V_26 , V_2 , V_38 ) ;
if ( V_41 ) {
V_5 -> V_57 = NULL ;
return V_41 ;
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
int V_41 ;
F_27 () ;
F_28 ( V_5 ) ;
V_41 = F_20 ( V_26 , V_2 , V_38 , V_40 ) ;
F_29 ( V_5 ) ;
return V_41 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
int V_65 ;
F_21 ( V_5 ) ;
F_23 ( V_5 -> V_57 ) ;
V_5 -> V_57 = NULL ;
if ( V_26 -> V_66 -> V_67 )
for ( V_65 = 0 ; V_65 < 6 ; V_65 ++ )
F_31 ( V_26 , V_2 , V_65 , false , NULL ) ;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( V_5 -> V_14 , & V_5 -> V_17 -> V_18 ) ;
}
V_5 -> V_17 = NULL ;
V_5 -> V_13 = 0 ;
#ifdef F_2
if ( ! V_64 )
V_5 -> V_60 . V_61 . V_13 = 0 ;
#endif
}
void F_32 ( struct V_1 * V_2 , bool V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_28 ( V_5 ) ;
F_30 ( V_2 , V_64 ) ;
F_29 ( V_5 ) ;
}
int F_33 ( struct V_25 * V_26 ,
struct V_1 * V_2 , bool V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_41 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_13 )
return - V_68 ;
V_41 = F_34 ( V_26 , V_2 ) ;
if ( V_41 )
return V_41 ;
F_30 ( V_2 , V_64 ) ;
return 0 ;
}
int F_35 ( struct V_25 * V_26 ,
struct V_1 * V_2 , bool V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_41 ;
F_28 ( V_5 ) ;
V_41 = F_33 ( V_26 , V_2 , V_64 ) ;
F_29 ( V_5 ) ;
return V_41 ;
}
int F_36 ( struct V_25 * V_26 ,
struct V_4 * V_5 )
{
struct V_39 * V_69 = NULL ;
enum V_70 V_49 ;
int V_65 , V_41 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_60 . V_61 . V_71 )
V_5 -> V_60 . V_61 . V_71 = 100 ;
if ( ! V_5 -> V_60 . V_61 . V_47 . V_48 ) {
V_5 -> V_60 . V_61 . V_47 . V_72 = V_73 ;
for ( V_49 = 0 ; V_49 < V_74 ; V_49 ++ ) {
struct V_44 * V_45 ;
struct V_75 * V_48 ;
V_45 = V_26 -> V_14 . V_46 [ V_49 ] ;
if ( ! V_45 )
continue;
for ( V_65 = 0 ; V_65 < V_45 -> V_76 ; V_65 ++ ) {
V_48 = & V_45 -> V_77 [ V_65 ] ;
if ( V_48 -> V_29 & V_78 )
continue;
if ( V_48 -> V_29 & V_79 )
continue;
V_5 -> V_60 . V_61 . V_47 . V_48 = V_48 ;
break;
}
if ( V_5 -> V_60 . V_61 . V_47 . V_48 )
break;
}
if ( ! V_5 -> V_60 . V_61 . V_47 . V_48 )
return - V_80 ;
}
if ( ! V_5 -> V_60 . V_61 . V_13 )
return 0 ;
if ( ! F_37 ( V_5 -> V_81 ) )
return 0 ;
if ( V_5 -> V_60 . V_82 ) {
V_5 -> V_60 . V_82 -> V_83 = V_5 -> V_60 . V_84 ;
V_5 -> V_60 . V_82 -> V_85 = V_5 -> V_60 . V_86 ;
}
V_5 -> V_60 . V_61 . V_87 = V_5 -> V_60 . V_84 != - 1 ;
if ( V_5 -> V_60 . V_82 ) {
V_69 = F_38 ( V_5 -> V_60 . V_82 , sizeof( * V_69 ) , V_19 ) ;
if ( ! V_69 )
return - V_88 ;
for ( V_65 = 0 ; V_65 < 6 ; V_65 ++ )
V_69 -> V_38 [ V_65 ] . V_89 = V_69 -> V_90 [ V_65 ] ;
}
V_41 = F_20 ( V_26 , V_5 -> V_81 ,
& V_5 -> V_60 . V_61 , V_69 ) ;
if ( V_41 )
F_23 ( V_69 ) ;
return V_41 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_93 * V_94 , char * V_95 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
struct V_75 * V_48 = NULL ;
int V_41 , V_96 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_80 ;
if ( ! V_26 -> V_66 -> V_97 )
return - V_98 ;
V_96 = F_40 ( V_5 -> V_14 , V_94 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_96 ) {
V_48 = F_41 ( V_5 -> V_14 , V_96 ) ;
if ( ! V_48 )
return - V_80 ;
if ( V_48 -> V_29 & V_78 ||
V_48 -> V_29 & V_79 )
return - V_80 ;
}
if ( V_5 -> V_60 . V_61 . V_47 . V_48 == V_48 )
return 0 ;
F_28 ( V_5 ) ;
V_41 = 0 ;
if ( V_5 -> V_13 )
V_41 = F_33 ( V_26 , V_2 , true ) ;
F_29 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_48 ) {
V_5 -> V_60 . V_61 . V_47 . V_48 = V_48 ;
V_5 -> V_60 . V_61 . V_47 . V_72 = V_73 ;
V_5 -> V_60 . V_61 . V_59 = true ;
} else {
V_5 -> V_60 . V_61 . V_59 = false ;
}
F_28 ( V_5 ) ;
V_41 = F_36 ( V_26 , V_5 ) ;
F_29 ( V_5 ) ;
return V_41 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_93 * V_96 , char * V_95 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_75 * V_48 = NULL ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_80 ;
F_28 ( V_5 ) ;
if ( V_5 -> V_17 )
V_48 = V_5 -> V_17 -> V_18 . V_99 ;
else if ( V_5 -> V_60 . V_61 . V_47 . V_48 )
V_48 = V_5 -> V_60 . V_61 . V_47 . V_48 ;
F_29 ( V_5 ) ;
if ( V_48 ) {
V_96 -> V_100 = V_48 -> V_101 ;
V_96 -> V_102 = 6 ;
return 0 ;
}
return - V_80 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_103 * V_90 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
T_4 V_104 = V_90 -> V_105 ;
int V_41 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_80 ;
if ( ! V_26 -> V_66 -> V_97 )
return - V_98 ;
F_28 ( V_5 ) ;
V_41 = 0 ;
if ( V_5 -> V_13 )
V_41 = F_33 ( V_26 , V_2 , true ) ;
F_29 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_104 > 0 && V_15 [ V_104 - 1 ] == '\0' )
V_104 -- ;
V_5 -> V_60 . V_61 . V_15 = V_5 -> V_15 ;
memcpy ( V_5 -> V_60 . V_61 . V_15 , V_15 , V_104 ) ;
V_5 -> V_60 . V_61 . V_13 = V_104 ;
F_28 ( V_5 ) ;
V_41 = F_36 ( V_26 , V_5 ) ;
F_29 ( V_5 ) ;
return V_41 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_103 * V_90 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_80 ;
V_90 -> V_29 = 0 ;
F_28 ( V_5 ) ;
if ( V_5 -> V_13 ) {
V_90 -> V_29 = 1 ;
V_90 -> V_105 = V_5 -> V_13 ;
memcpy ( V_15 , V_5 -> V_15 , V_90 -> V_105 ) ;
} else if ( V_5 -> V_60 . V_61 . V_15 && V_5 -> V_60 . V_61 . V_13 ) {
V_90 -> V_29 = 1 ;
V_90 -> V_105 = V_5 -> V_60 . V_61 . V_13 ;
memcpy ( V_15 , V_5 -> V_60 . V_61 . V_15 , V_90 -> V_105 ) ;
}
F_29 ( V_5 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_106 * V_20 , char * V_95 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
T_1 * V_3 = V_20 -> V_21 ;
int V_41 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_80 ;
if ( ! V_26 -> V_66 -> V_97 )
return - V_98 ;
if ( V_20 -> V_107 != V_108 )
return - V_80 ;
if ( F_46 ( V_3 ) || F_47 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_5 -> V_60 . V_61 . V_3 )
return 0 ;
if ( V_5 -> V_60 . V_61 . V_3 && V_3 &&
F_48 ( V_3 , V_5 -> V_60 . V_61 . V_3 ) )
return 0 ;
F_28 ( V_5 ) ;
V_41 = 0 ;
if ( V_5 -> V_13 )
V_41 = F_33 ( V_26 , V_2 , true ) ;
F_29 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 ) {
memcpy ( V_5 -> V_60 . V_3 , V_3 , V_22 ) ;
V_5 -> V_60 . V_61 . V_3 = V_5 -> V_60 . V_3 ;
} else
V_5 -> V_60 . V_61 . V_3 = NULL ;
F_28 ( V_5 ) ;
V_41 = F_36 ( V_26 , V_5 ) ;
F_29 ( V_5 ) ;
return V_41 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_106 * V_20 , char * V_95 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_80 ;
V_20 -> V_107 = V_108 ;
F_28 ( V_5 ) ;
if ( V_5 -> V_17 )
memcpy ( V_20 -> V_21 , V_5 -> V_17 -> V_18 . V_3 , V_22 ) ;
else if ( V_5 -> V_60 . V_61 . V_3 )
memcpy ( V_20 -> V_21 , V_5 -> V_60 . V_61 . V_3 , V_22 ) ;
else
memset ( V_20 -> V_21 , 0 , V_22 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
