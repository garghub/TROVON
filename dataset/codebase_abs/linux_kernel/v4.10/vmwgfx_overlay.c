static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_1 ( V_3 ) ;
return V_5 ? V_5 -> V_6 : NULL ;
}
static inline void F_2 ( struct V_7 * V_8 ,
T_1 V_9 )
{
V_8 -> V_10 = V_11 ;
V_8 -> V_12 . V_13 = V_14 ;
V_8 -> V_12 . V_9 = V_9 ;
}
static inline void F_3 ( struct V_15 * V_10 ,
T_1 V_16 )
{
F_2 ( & V_10 -> V_17 , sizeof( V_10 -> V_18 ) ) ;
V_10 -> V_18 . V_19 = V_20 ;
V_10 -> V_18 . V_21 = V_16 ;
}
static int F_4 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_26 )
{
struct V_15 * V_18 ;
T_2 V_27 ;
bool V_28 = ( V_5 -> V_29 == V_30 ) ;
int V_31 , V_32 ;
T_3 V_33 ;
struct {
struct V_7 V_17 ;
struct {
T_1 V_19 ;
T_1 V_21 ;
} V_8 ;
} * V_34 ;
struct {
T_1 V_35 ;
T_1 V_36 ;
} * V_37 ;
if ( V_28 )
V_32 = V_38 + 1 ;
else
V_32 = V_39 + 1 ;
V_27 = sizeof( * V_34 ) + sizeof( * V_18 ) + sizeof( * V_37 ) * V_32 ;
V_34 = F_5 ( V_5 , V_27 ) ;
if ( ! V_34 )
return - V_40 ;
V_37 = ( F_6 ( V_37 ) ) & V_34 [ 1 ] ;
V_18 = (struct V_15 * ) & V_37 [ V_32 ] ;
F_2 ( & V_34 -> V_17 , sizeof( * V_37 ) * ( V_32 + 1 ) ) ;
V_34 -> V_8 . V_19 = V_41 ;
V_34 -> V_8 . V_21 = V_25 -> V_16 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
V_37 [ V_31 ] . V_35 = V_31 ;
F_7 ( & V_23 -> V_42 , & V_33 ) ;
V_33 . V_43 += V_25 -> V_43 ;
V_37 [ V_44 ] . V_36 = true ;
V_37 [ V_45 ] . V_36 = V_25 -> V_46 ;
V_37 [ V_47 ] . V_36 = V_33 . V_43 ;
V_37 [ V_48 ] . V_36 = V_25 -> V_49 ;
V_37 [ V_50 ] . V_36 = V_25 -> V_51 ;
V_37 [ V_52 ] . V_36 = V_25 -> V_9 ;
V_37 [ V_53 ] . V_36 = V_25 -> V_54 ;
V_37 [ V_55 ] . V_36 = V_25 -> V_56 ;
V_37 [ V_57 ] . V_36 = V_25 -> V_58 . V_59 ;
V_37 [ V_60 ] . V_36 = V_25 -> V_58 . V_61 ;
V_37 [ V_62 ] . V_36 = V_25 -> V_58 . V_63 ;
V_37 [ V_64 ] . V_36 = V_25 -> V_58 . V_65 ;
V_37 [ V_66 ] . V_36 = V_25 -> V_67 . V_59 ;
V_37 [ V_68 ] . V_36 = V_25 -> V_67 . V_61 ;
V_37 [ V_69 ] . V_36 = V_25 -> V_67 . V_63 ;
V_37 [ V_70 ] . V_36 = V_25 -> V_67 . V_65 ;
V_37 [ V_71 ] . V_36 = V_25 -> V_72 [ 0 ] ;
V_37 [ V_73 ] . V_36 = V_25 -> V_72 [ 1 ] ;
V_37 [ V_39 ] . V_36 = V_25 -> V_72 [ 2 ] ;
if ( V_28 ) {
V_37 [ V_74 ] . V_36 = V_33 . V_75 ;
V_37 [ V_38 ] . V_36 = V_76 ;
}
F_3 ( V_18 , V_25 -> V_16 ) ;
F_8 ( V_5 , V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
T_1 V_16 ,
bool V_26 )
{
struct {
struct V_7 V_17 ;
T_4 V_12 ;
struct V_15 V_18 ;
} * V_34 ;
int V_77 ;
for (; ; ) {
V_34 = F_5 ( V_5 , sizeof( * V_34 ) ) ;
if ( V_34 )
break;
V_77 = F_10 ( V_5 , false , true , 0 ,
V_26 , 3 * V_78 ) ;
if ( V_26 && V_77 == - V_79 )
return V_77 ;
else
F_11 ( V_77 != 0 ) ;
}
F_2 ( & V_34 -> V_17 , sizeof( V_34 -> V_12 ) ) ;
V_34 -> V_12 . V_8 . V_19 = V_41 ;
V_34 -> V_12 . V_8 . V_21 = V_16 ;
V_34 -> V_12 . V_37 [ 0 ] . V_35 = V_44 ;
V_34 -> V_12 . V_37 [ 0 ] . V_36 = false ;
F_3 ( & V_34 -> V_18 , V_16 ) ;
F_8 ( V_5 , sizeof( * V_34 ) ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
bool V_80 , bool V_81 )
{
if ( ! V_80 )
return F_13 ( V_5 , V_23 , V_81 ) ;
if ( V_5 -> V_29 == V_82 )
return F_14 ( V_5 , V_23 , V_81 ) ;
return F_15 ( V_5 , V_23 , V_81 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
T_1 V_16 , bool V_83 ,
bool V_26 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
struct V_85 * V_86 = & V_84 -> V_86 [ V_16 ] ;
int V_77 ;
if ( ! V_86 -> V_23 )
return 0 ;
if ( ! V_86 -> V_87 ) {
V_77 = F_9 ( V_5 , V_16 ,
V_26 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_12 ( V_5 , V_86 -> V_23 , false ,
V_26 ) ;
if ( V_26 && V_77 == - V_79 )
return V_77 ;
else
F_11 ( V_77 != 0 ) ;
}
if ( ! V_83 ) {
F_17 ( & V_86 -> V_23 ) ;
V_86 -> V_87 = false ;
} else {
V_86 -> V_87 = true ;
}
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_26 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
struct V_85 * V_86 = & V_84 -> V_86 [ V_25 -> V_16 ] ;
int V_77 = 0 ;
if ( ! V_23 )
return - V_88 ;
F_19 ( L_1 , V_89 ,
V_86 -> V_23 , V_23 , V_86 -> V_87 ? L_2 : L_3 ) ;
if ( V_86 -> V_23 != V_23 ) {
V_77 = F_16 ( V_5 , V_25 -> V_16 ,
false , V_26 ) ;
if ( V_77 )
return V_77 ;
} else if ( ! V_86 -> V_87 ) {
V_77 = F_4 ( V_5 , V_23 , V_25 , V_26 ) ;
if ( V_77 == 0 )
V_86 -> V_90 = * V_25 ;
else
F_11 ( ! V_26 ) ;
return V_77 ;
}
V_77 = F_12 ( V_5 , V_23 , true , V_26 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_4 ( V_5 , V_23 , V_25 , V_26 ) ;
if ( V_77 ) {
F_11 ( F_12 ( V_5 , V_23 , false , false )
!= 0 ) ;
return V_77 ;
}
if ( V_86 -> V_23 != V_23 )
V_86 -> V_23 = F_20 ( V_23 ) ;
V_86 -> V_90 = * V_25 ;
V_86 -> V_87 = false ;
return 0 ;
}
int F_21 ( struct V_4 * V_5 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
int V_31 , V_77 ;
if ( ! V_84 )
return 0 ;
F_22 ( & V_84 -> V_91 ) ;
for ( V_31 = 0 ; V_31 < V_92 ; V_31 ++ ) {
struct V_85 * V_86 = & V_84 -> V_86 [ V_31 ] ;
if ( ! V_86 -> V_23 )
continue;
V_77 = F_16 ( V_5 , V_31 , false , false ) ;
F_23 ( V_77 != 0 ) ;
}
F_24 ( & V_84 -> V_91 ) ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
int V_31 , V_77 ;
if ( ! V_84 )
return 0 ;
F_22 ( & V_84 -> V_91 ) ;
for ( V_31 = 0 ; V_31 < V_92 ; V_31 ++ ) {
struct V_85 * V_86 = & V_84 -> V_86 [ V_31 ] ;
if ( ! V_86 -> V_87 )
continue;
V_77 = F_18 ( V_5 , V_86 -> V_23 ,
& V_86 -> V_90 , false ) ;
if ( V_77 != 0 )
F_26 ( L_4 ,
V_89 , V_31 ) ;
}
F_24 ( & V_84 -> V_91 ) ;
return 0 ;
}
int F_27 ( struct V_4 * V_5 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
int V_31 , V_77 ;
if ( ! V_84 )
return 0 ;
F_22 ( & V_84 -> V_91 ) ;
for ( V_31 = 0 ; V_31 < V_92 ; V_31 ++ ) {
if ( V_84 -> V_86 [ V_31 ] . V_87 )
F_26 ( L_5 ,
V_89 , V_31 ) ;
V_77 = F_16 ( V_5 , V_31 , true , false ) ;
F_23 ( V_77 != 0 ) ;
}
F_24 ( & V_84 -> V_91 ) ;
return 0 ;
}
static bool F_28 ( const struct V_4 * V_5 )
{
return ( V_5 -> V_6 != NULL &&
( ( V_5 -> V_93 . V_94 & V_95 ) ==
V_95 ) ) ;
}
int F_29 ( struct V_2 * V_3 , void * V_96 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = F_30 ( V_98 ) -> V_100 ;
struct V_4 * V_5 = F_1 ( V_3 ) ;
struct V_1 * V_84 = V_5 -> V_6 ;
struct V_24 * V_25 =
(struct V_24 * ) V_96 ;
struct V_22 * V_23 ;
struct V_101 * V_102 ;
int V_77 ;
if ( ! F_28 ( V_5 ) )
return - V_103 ;
V_77 = F_31 ( V_5 , V_100 , & V_25 -> V_16 , & V_102 ) ;
if ( V_77 )
return V_77 ;
F_22 ( & V_84 -> V_91 ) ;
if ( ! V_25 -> V_104 ) {
V_77 = F_16 ( V_5 , V_25 -> V_16 , false , true ) ;
goto V_105;
}
V_77 = F_32 ( V_100 , V_25 -> V_106 , & V_23 , NULL ) ;
if ( V_77 )
goto V_105;
V_77 = F_18 ( V_5 , V_23 , V_25 , true ) ;
F_17 ( & V_23 ) ;
V_105:
F_24 ( & V_84 -> V_91 ) ;
F_33 ( & V_102 ) ;
return V_77 ;
}
int F_34 ( struct V_4 * V_5 )
{
if ( ! F_28 ( V_5 ) )
return 0 ;
return V_92 ;
}
int F_35 ( struct V_4 * V_5 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
int V_31 , V_107 ;
if ( ! F_28 ( V_5 ) )
return 0 ;
F_22 ( & V_84 -> V_91 ) ;
for ( V_31 = 0 , V_107 = 0 ; V_31 < V_92 ; V_31 ++ )
if ( ! V_84 -> V_86 [ V_31 ] . V_108 )
V_107 ++ ;
F_24 ( & V_84 -> V_91 ) ;
return V_107 ;
}
int F_36 ( struct V_4 * V_5 , T_1 * V_109 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
int V_31 ;
if ( ! V_84 )
return - V_103 ;
F_22 ( & V_84 -> V_91 ) ;
for ( V_31 = 0 ; V_31 < V_92 ; V_31 ++ ) {
if ( V_84 -> V_86 [ V_31 ] . V_108 )
continue;
V_84 -> V_86 [ V_31 ] . V_108 = true ;
* V_109 = V_31 ;
F_24 ( & V_84 -> V_91 ) ;
return 0 ;
}
F_24 ( & V_84 -> V_91 ) ;
return - V_110 ;
}
int F_37 ( struct V_4 * V_5 , T_1 V_16 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
F_11 ( V_16 >= V_92 ) ;
if ( ! V_84 )
return - V_103 ;
F_22 ( & V_84 -> V_91 ) ;
F_23 ( ! V_84 -> V_86 [ V_16 ] . V_108 ) ;
F_16 ( V_5 , V_16 , false , false ) ;
V_84 -> V_86 [ V_16 ] . V_108 = false ;
F_24 ( & V_84 -> V_91 ) ;
return 0 ;
}
int F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_84 ;
int V_31 ;
if ( V_5 -> V_6 )
return - V_88 ;
V_84 = F_39 ( sizeof( * V_84 ) , V_111 ) ;
if ( ! V_84 )
return - V_40 ;
F_40 ( & V_84 -> V_91 ) ;
for ( V_31 = 0 ; V_31 < V_92 ; V_31 ++ ) {
V_84 -> V_86 [ V_31 ] . V_23 = NULL ;
V_84 -> V_86 [ V_31 ] . V_87 = false ;
V_84 -> V_86 [ V_31 ] . V_108 = false ;
}
V_5 -> V_6 = V_84 ;
return 0 ;
}
int F_41 ( struct V_4 * V_5 )
{
struct V_1 * V_84 = V_5 -> V_6 ;
bool V_112 = false ;
int V_31 ;
if ( ! V_84 )
return - V_103 ;
for ( V_31 = 0 ; V_31 < V_92 ; V_31 ++ ) {
if ( V_84 -> V_86 [ V_31 ] . V_23 ) {
V_112 = true ;
F_16 ( V_5 , V_31 , false , false ) ;
}
}
F_23 ( V_112 ) ;
V_5 -> V_6 = NULL ;
F_42 ( V_84 ) ;
return 0 ;
}
