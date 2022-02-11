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
F_14 ( ! V_5 -> V_13 ) ;
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
V_26 -> V_14 . V_46 [ V_38 -> V_47 -> V_48 ] ;
int V_49 ;
T_3 V_50 = V_38 -> V_47 -> V_48 == V_51 ?
V_52 :
V_53 ;
for ( V_49 = 0 ; V_49 < V_45 -> V_54 ; V_49 ++ ) {
if ( V_45 -> V_55 [ V_49 ] . V_29 & V_50 )
V_38 -> V_43 |= F_22 ( V_49 ) ;
}
}
if ( F_3 ( V_5 -> V_56 ) )
F_23 ( V_5 -> V_56 ) ;
V_5 -> V_56 = V_40 ;
#ifdef F_2
V_5 -> V_57 . V_58 . V_47 = V_38 -> V_47 ;
#endif
V_41 = V_26 -> V_59 -> V_60 ( & V_26 -> V_14 , V_2 , V_38 ) ;
if ( V_41 ) {
V_5 -> V_56 = NULL ;
return V_41 ;
}
memcpy ( V_5 -> V_15 , V_38 -> V_15 , V_38 -> V_13 ) ;
V_5 -> V_13 = V_38 -> V_13 ;
return 0 ;
}
int F_24 ( struct V_25 * V_26 ,
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_41 ;
F_25 ( & V_26 -> V_61 ) ;
F_26 ( V_5 ) ;
V_41 = F_20 ( V_26 , V_2 , V_38 , V_40 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_26 -> V_61 ) ;
return V_41 ;
}
static void F_29 ( struct V_1 * V_2 , bool V_62 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
int V_63 ;
F_21 ( V_5 ) ;
F_23 ( V_5 -> V_56 ) ;
V_5 -> V_56 = NULL ;
if ( V_26 -> V_59 -> V_64 )
for ( V_63 = 0 ; V_63 < 6 ; V_63 ++ )
V_26 -> V_59 -> V_64 ( V_5 -> V_14 , V_2 , V_63 , false , NULL ) ;
if ( V_5 -> V_17 ) {
F_5 ( V_5 -> V_17 ) ;
F_6 ( & V_5 -> V_17 -> V_18 ) ;
}
V_5 -> V_17 = NULL ;
V_5 -> V_13 = 0 ;
#ifdef F_2
if ( ! V_62 )
V_5 -> V_57 . V_58 . V_13 = 0 ;
#endif
}
void F_30 ( struct V_1 * V_2 , bool V_62 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_26 ( V_5 ) ;
F_29 ( V_2 , V_62 ) ;
F_27 ( V_5 ) ;
}
int F_31 ( struct V_25 * V_26 ,
struct V_1 * V_2 , bool V_62 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_41 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_13 )
return - V_65 ;
V_41 = V_26 -> V_59 -> V_66 ( & V_26 -> V_14 , V_2 ) ;
if ( V_41 )
return V_41 ;
F_29 ( V_2 , V_62 ) ;
return 0 ;
}
int F_32 ( struct V_25 * V_26 ,
struct V_1 * V_2 , bool V_62 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_41 ;
F_26 ( V_5 ) ;
V_41 = F_31 ( V_26 , V_2 , V_62 ) ;
F_27 ( V_5 ) ;
return V_41 ;
}
int F_33 ( struct V_25 * V_26 ,
struct V_4 * V_5 )
{
struct V_39 * V_67 = NULL ;
enum V_68 V_48 ;
int V_63 , V_41 ;
F_21 ( V_5 ) ;
if ( ! V_5 -> V_57 . V_58 . V_69 )
V_5 -> V_57 . V_58 . V_69 = 100 ;
if ( ! V_5 -> V_57 . V_58 . V_47 ) {
for ( V_48 = 0 ; V_48 < V_70 ; V_48 ++ ) {
struct V_44 * V_45 ;
struct V_71 * V_72 ;
V_45 = V_26 -> V_14 . V_46 [ V_48 ] ;
if ( ! V_45 )
continue;
for ( V_63 = 0 ; V_63 < V_45 -> V_73 ; V_63 ++ ) {
V_72 = & V_45 -> V_74 [ V_63 ] ;
if ( V_72 -> V_29 & V_75 )
continue;
if ( V_72 -> V_29 & V_76 )
continue;
V_5 -> V_57 . V_58 . V_47 = V_72 ;
break;
}
if ( V_5 -> V_57 . V_58 . V_47 )
break;
}
if ( ! V_5 -> V_57 . V_58 . V_47 )
return - V_77 ;
}
if ( ! V_5 -> V_57 . V_58 . V_13 )
return 0 ;
if ( ! F_34 ( V_5 -> V_78 ) )
return 0 ;
if ( V_5 -> V_57 . V_79 ) {
V_5 -> V_57 . V_79 -> V_80 = V_5 -> V_57 . V_81 ;
V_5 -> V_57 . V_79 -> V_82 = V_5 -> V_57 . V_83 ;
}
V_5 -> V_57 . V_58 . V_84 = V_5 -> V_57 . V_81 != - 1 ;
if ( V_5 -> V_57 . V_79 ) {
V_67 = F_35 ( V_5 -> V_57 . V_79 , sizeof( * V_67 ) , V_19 ) ;
if ( ! V_67 )
return - V_85 ;
for ( V_63 = 0 ; V_63 < 6 ; V_63 ++ )
V_67 -> V_38 [ V_63 ] . V_86 = V_67 -> V_87 [ V_63 ] ;
}
V_41 = F_20 ( V_26 , V_5 -> V_78 ,
& V_5 -> V_57 . V_58 , V_67 ) ;
if ( V_41 )
F_23 ( V_67 ) ;
return V_41 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
struct V_71 * V_72 = NULL ;
int V_41 , V_93 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_77 ;
if ( ! V_26 -> V_59 -> V_60 )
return - V_94 ;
V_93 = F_37 ( V_5 -> V_14 , V_91 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_93 ) {
V_72 = F_38 ( V_5 -> V_14 , V_93 ) ;
if ( ! V_72 )
return - V_77 ;
if ( V_72 -> V_29 & V_75 ||
V_72 -> V_29 & V_76 )
return - V_77 ;
}
if ( V_5 -> V_57 . V_58 . V_47 == V_72 )
return 0 ;
F_26 ( V_5 ) ;
V_41 = 0 ;
if ( V_5 -> V_13 )
V_41 = F_31 ( V_26 , V_2 , true ) ;
F_27 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_72 ) {
V_5 -> V_57 . V_58 . V_47 = V_72 ;
V_5 -> V_57 . V_58 . V_95 = true ;
} else {
V_5 -> V_57 . V_58 . V_95 = false ;
}
F_25 ( & V_26 -> V_61 ) ;
F_26 ( V_5 ) ;
V_41 = F_33 ( V_26 , V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_26 -> V_61 ) ;
return V_41 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_90 * V_93 , char * V_92 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_71 * V_72 = NULL ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_77 ;
F_26 ( V_5 ) ;
if ( V_5 -> V_17 )
V_72 = V_5 -> V_17 -> V_18 . V_47 ;
else if ( V_5 -> V_57 . V_58 . V_47 )
V_72 = V_5 -> V_57 . V_58 . V_47 ;
F_27 ( V_5 ) ;
if ( V_72 ) {
V_93 -> V_96 = V_72 -> V_97 ;
V_93 -> V_98 = 6 ;
return 0 ;
}
return - V_77 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_99 * V_87 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
T_4 V_100 = V_87 -> V_101 ;
int V_41 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_77 ;
if ( ! V_26 -> V_59 -> V_60 )
return - V_94 ;
F_26 ( V_5 ) ;
V_41 = 0 ;
if ( V_5 -> V_13 )
V_41 = F_31 ( V_26 , V_2 , true ) ;
F_27 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_100 > 0 && V_15 [ V_100 - 1 ] == '\0' )
V_100 -- ;
V_5 -> V_57 . V_58 . V_15 = V_5 -> V_15 ;
memcpy ( V_5 -> V_57 . V_58 . V_15 , V_15 , V_100 ) ;
V_5 -> V_57 . V_58 . V_13 = V_100 ;
F_25 ( & V_26 -> V_61 ) ;
F_26 ( V_5 ) ;
V_41 = F_33 ( V_26 , V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_26 -> V_61 ) ;
return V_41 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_99 * V_87 , char * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_77 ;
V_87 -> V_29 = 0 ;
F_26 ( V_5 ) ;
if ( V_5 -> V_13 ) {
V_87 -> V_29 = 1 ;
V_87 -> V_101 = V_5 -> V_13 ;
memcpy ( V_15 , V_5 -> V_15 , V_87 -> V_101 ) ;
} else if ( V_5 -> V_57 . V_58 . V_15 && V_5 -> V_57 . V_58 . V_13 ) {
V_87 -> V_29 = 1 ;
V_87 -> V_101 = V_5 -> V_57 . V_58 . V_13 ;
memcpy ( V_15 , V_5 -> V_57 . V_58 . V_15 , V_87 -> V_101 ) ;
}
F_27 ( V_5 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_102 * V_20 , char * V_92 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = F_11 ( V_5 -> V_14 ) ;
T_1 * V_3 = V_20 -> V_21 ;
int V_41 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_77 ;
if ( ! V_26 -> V_59 -> V_60 )
return - V_94 ;
if ( V_20 -> V_103 != V_104 )
return - V_77 ;
if ( F_43 ( V_3 ) || F_44 ( V_3 ) )
V_3 = NULL ;
if ( ! V_3 && ! V_5 -> V_57 . V_58 . V_3 )
return 0 ;
if ( V_5 -> V_57 . V_58 . V_3 && V_3 &&
F_45 ( V_3 , V_5 -> V_57 . V_58 . V_3 ) == 0 )
return 0 ;
F_26 ( V_5 ) ;
V_41 = 0 ;
if ( V_5 -> V_13 )
V_41 = F_31 ( V_26 , V_2 , true ) ;
F_27 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 ) {
memcpy ( V_5 -> V_57 . V_3 , V_3 , V_22 ) ;
V_5 -> V_57 . V_58 . V_3 = V_5 -> V_57 . V_3 ;
} else
V_5 -> V_57 . V_58 . V_3 = NULL ;
F_25 ( & V_26 -> V_61 ) ;
F_26 ( V_5 ) ;
V_41 = F_33 ( V_26 , V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( & V_26 -> V_61 ) ;
return V_41 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_102 * V_20 , char * V_92 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_3 ( V_5 -> V_11 != V_12 ) )
return - V_77 ;
V_20 -> V_103 = V_104 ;
F_26 ( V_5 ) ;
if ( V_5 -> V_17 )
memcpy ( V_20 -> V_21 , V_5 -> V_17 -> V_18 . V_3 , V_22 ) ;
else if ( V_5 -> V_57 . V_58 . V_3 )
memcpy ( V_20 -> V_21 , V_5 -> V_57 . V_58 . V_3 , V_22 ) ;
else
memset ( V_20 -> V_21 , 0 , V_22 ) ;
F_27 ( V_5 ) ;
return 0 ;
}
