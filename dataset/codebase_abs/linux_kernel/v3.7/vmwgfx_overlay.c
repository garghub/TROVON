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
bool V_28 = V_5 -> V_29 ? true : false ;
int V_30 , V_31 ;
T_3 V_32 ;
struct {
struct V_7 V_17 ;
struct {
T_1 V_19 ;
T_1 V_21 ;
} V_8 ;
} * V_33 ;
struct {
T_1 V_34 ;
T_1 V_35 ;
} * V_36 ;
if ( V_28 )
V_31 = V_37 + 1 ;
else
V_31 = V_38 + 1 ;
V_27 = sizeof( * V_33 ) + sizeof( * V_18 ) + sizeof( * V_36 ) * V_31 ;
V_33 = F_5 ( V_5 , V_27 ) ;
if ( ! V_33 )
return - V_39 ;
V_36 = ( F_6 ( V_36 ) ) & V_33 [ 1 ] ;
V_18 = (struct V_15 * ) & V_36 [ V_31 ] ;
F_2 ( & V_33 -> V_17 , sizeof( * V_36 ) * ( V_31 + 1 ) ) ;
V_33 -> V_8 . V_19 = V_40 ;
V_33 -> V_8 . V_21 = V_25 -> V_16 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_36 [ V_30 ] . V_34 = V_30 ;
F_7 ( & V_23 -> V_41 , & V_32 ) ;
V_32 . V_42 += V_25 -> V_42 ;
V_36 [ V_43 ] . V_35 = true ;
V_36 [ V_44 ] . V_35 = V_25 -> V_45 ;
V_36 [ V_46 ] . V_35 = V_32 . V_42 ;
V_36 [ V_47 ] . V_35 = V_25 -> V_48 ;
V_36 [ V_49 ] . V_35 = V_25 -> V_50 ;
V_36 [ V_51 ] . V_35 = V_25 -> V_9 ;
V_36 [ V_52 ] . V_35 = V_25 -> V_53 ;
V_36 [ V_54 ] . V_35 = V_25 -> V_55 ;
V_36 [ V_56 ] . V_35 = V_25 -> V_57 . V_58 ;
V_36 [ V_59 ] . V_35 = V_25 -> V_57 . V_60 ;
V_36 [ V_61 ] . V_35 = V_25 -> V_57 . V_62 ;
V_36 [ V_63 ] . V_35 = V_25 -> V_57 . V_64 ;
V_36 [ V_65 ] . V_35 = V_25 -> V_66 . V_58 ;
V_36 [ V_67 ] . V_35 = V_25 -> V_66 . V_60 ;
V_36 [ V_68 ] . V_35 = V_25 -> V_66 . V_62 ;
V_36 [ V_69 ] . V_35 = V_25 -> V_66 . V_64 ;
V_36 [ V_70 ] . V_35 = V_25 -> V_71 [ 0 ] ;
V_36 [ V_72 ] . V_35 = V_25 -> V_71 [ 1 ] ;
V_36 [ V_38 ] . V_35 = V_25 -> V_71 [ 2 ] ;
if ( V_28 ) {
V_36 [ V_73 ] . V_35 = V_32 . V_74 ;
V_36 [ V_37 ] . V_35 = V_75 ;
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
} * V_33 ;
int V_76 ;
for (; ; ) {
V_33 = F_5 ( V_5 , sizeof( * V_33 ) ) ;
if ( V_33 )
break;
V_76 = F_10 ( V_5 , false , true , 0 ,
V_26 , 3 * V_77 ) ;
if ( V_26 && V_76 == - V_78 )
return V_76 ;
else
F_11 ( V_76 != 0 ) ;
}
F_2 ( & V_33 -> V_17 , sizeof( V_33 -> V_12 ) ) ;
V_33 -> V_12 . V_8 . V_19 = V_40 ;
V_33 -> V_12 . V_8 . V_21 = V_16 ;
V_33 -> V_12 . V_36 [ 0 ] . V_34 = V_43 ;
V_33 -> V_12 . V_36 [ 0 ] . V_35 = false ;
F_3 ( & V_33 -> V_18 , V_16 ) ;
F_8 ( V_5 , sizeof( * V_33 ) ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
bool V_79 , bool V_80 )
{
if ( ! V_79 )
return F_13 ( V_5 , V_23 , V_80 ) ;
if ( ! V_5 -> V_29 )
return F_14 ( V_5 , V_23 , true , V_80 ) ;
return F_15 ( V_5 , V_23 , true , V_80 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
T_1 V_16 , bool V_81 ,
bool V_26 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
struct V_83 * V_84 = & V_82 -> V_84 [ V_16 ] ;
int V_76 ;
if ( ! V_84 -> V_23 )
return 0 ;
if ( ! V_84 -> V_85 ) {
V_76 = F_9 ( V_5 , V_16 ,
V_26 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_12 ( V_5 , V_84 -> V_23 , false ,
V_26 ) ;
if ( V_26 && V_76 == - V_78 )
return V_76 ;
else
F_11 ( V_76 != 0 ) ;
}
if ( ! V_81 ) {
F_17 ( & V_84 -> V_23 ) ;
V_84 -> V_85 = false ;
} else {
V_84 -> V_85 = true ;
}
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_26 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
struct V_83 * V_84 = & V_82 -> V_84 [ V_25 -> V_16 ] ;
int V_76 = 0 ;
if ( ! V_23 )
return - V_86 ;
F_19 ( L_1 , V_87 ,
V_84 -> V_23 , V_23 , V_84 -> V_85 ? L_2 : L_3 ) ;
if ( V_84 -> V_23 != V_23 ) {
V_76 = F_16 ( V_5 , V_25 -> V_16 ,
false , V_26 ) ;
if ( V_76 )
return V_76 ;
} else if ( ! V_84 -> V_85 ) {
V_76 = F_4 ( V_5 , V_23 , V_25 , V_26 ) ;
if ( V_76 == 0 )
V_84 -> V_88 = * V_25 ;
else
F_11 ( ! V_26 ) ;
return V_76 ;
}
V_76 = F_12 ( V_5 , V_23 , true , V_26 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_4 ( V_5 , V_23 , V_25 , V_26 ) ;
if ( V_76 ) {
F_11 ( F_12 ( V_5 , V_23 , false , false )
!= 0 ) ;
return V_76 ;
}
if ( V_84 -> V_23 != V_23 )
V_84 -> V_23 = F_20 ( V_23 ) ;
V_84 -> V_88 = * V_25 ;
V_84 -> V_85 = false ;
return 0 ;
}
int F_21 ( struct V_4 * V_5 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
int V_30 , V_76 ;
if ( ! V_82 )
return 0 ;
F_22 ( & V_82 -> V_89 ) ;
for ( V_30 = 0 ; V_30 < V_90 ; V_30 ++ ) {
struct V_83 * V_84 = & V_82 -> V_84 [ V_30 ] ;
if ( ! V_84 -> V_23 )
continue;
V_76 = F_16 ( V_5 , V_30 , false , false ) ;
F_23 ( V_76 != 0 ) ;
}
F_24 ( & V_82 -> V_89 ) ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
int V_30 , V_76 ;
if ( ! V_82 )
return 0 ;
F_22 ( & V_82 -> V_89 ) ;
for ( V_30 = 0 ; V_30 < V_90 ; V_30 ++ ) {
struct V_83 * V_84 = & V_82 -> V_84 [ V_30 ] ;
if ( ! V_84 -> V_85 )
continue;
V_76 = F_18 ( V_5 , V_84 -> V_23 ,
& V_84 -> V_88 , false ) ;
if ( V_76 != 0 )
F_26 ( L_4 ,
V_87 , V_30 ) ;
}
F_24 ( & V_82 -> V_89 ) ;
return 0 ;
}
int F_27 ( struct V_4 * V_5 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
int V_30 , V_76 ;
if ( ! V_82 )
return 0 ;
F_22 ( & V_82 -> V_89 ) ;
for ( V_30 = 0 ; V_30 < V_90 ; V_30 ++ ) {
if ( V_82 -> V_84 [ V_30 ] . V_85 )
F_26 ( L_5 ,
V_87 , V_30 ) ;
V_76 = F_16 ( V_5 , V_30 , true , false ) ;
F_23 ( V_76 != 0 ) ;
}
F_24 ( & V_82 -> V_89 ) ;
return 0 ;
}
int F_28 ( struct V_2 * V_3 , void * V_91 ,
struct V_92 * V_93 )
{
struct V_94 * V_95 = F_29 ( V_93 ) -> V_95 ;
struct V_4 * V_5 = F_1 ( V_3 ) ;
struct V_1 * V_82 = V_5 -> V_6 ;
struct V_24 * V_25 =
(struct V_24 * ) V_91 ;
struct V_22 * V_23 ;
struct V_96 * V_97 ;
int V_76 ;
if ( ! V_82 )
return - V_98 ;
V_76 = F_30 ( V_5 , V_95 , & V_25 -> V_16 , & V_97 ) ;
if ( V_76 )
return V_76 ;
F_22 ( & V_82 -> V_89 ) ;
if ( ! V_25 -> V_99 ) {
V_76 = F_16 ( V_5 , V_25 -> V_16 , false , true ) ;
goto V_100;
}
V_76 = F_31 ( V_95 , V_25 -> V_101 , & V_23 ) ;
if ( V_76 )
goto V_100;
V_76 = F_18 ( V_5 , V_23 , V_25 , true ) ;
F_17 ( & V_23 ) ;
V_100:
F_24 ( & V_82 -> V_89 ) ;
F_32 ( & V_97 ) ;
return V_76 ;
}
int F_33 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 )
return 0 ;
return V_90 ;
}
int F_34 ( struct V_4 * V_5 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
int V_30 , V_102 ;
if ( ! V_82 )
return 0 ;
F_22 ( & V_82 -> V_89 ) ;
for ( V_30 = 0 , V_102 = 0 ; V_30 < V_90 ; V_30 ++ )
if ( ! V_82 -> V_84 [ V_30 ] . V_103 )
V_102 ++ ;
F_24 ( & V_82 -> V_89 ) ;
return V_102 ;
}
int F_35 ( struct V_4 * V_5 , T_1 * V_104 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
int V_30 ;
if ( ! V_82 )
return - V_98 ;
F_22 ( & V_82 -> V_89 ) ;
for ( V_30 = 0 ; V_30 < V_90 ; V_30 ++ ) {
if ( V_82 -> V_84 [ V_30 ] . V_103 )
continue;
V_82 -> V_84 [ V_30 ] . V_103 = true ;
* V_104 = V_30 ;
F_24 ( & V_82 -> V_89 ) ;
return 0 ;
}
F_24 ( & V_82 -> V_89 ) ;
return - V_105 ;
}
int F_36 ( struct V_4 * V_5 , T_1 V_16 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
F_11 ( V_16 >= V_90 ) ;
if ( ! V_82 )
return - V_98 ;
F_22 ( & V_82 -> V_89 ) ;
F_23 ( ! V_82 -> V_84 [ V_16 ] . V_103 ) ;
F_16 ( V_5 , V_16 , false , false ) ;
V_82 -> V_84 [ V_16 ] . V_103 = false ;
F_24 ( & V_82 -> V_89 ) ;
return 0 ;
}
int F_37 ( struct V_4 * V_5 )
{
struct V_1 * V_82 ;
int V_30 ;
if ( V_5 -> V_6 )
return - V_86 ;
if ( ! ( V_5 -> V_106 . V_107 & V_108 ) &&
( V_5 -> V_106 . V_107 & V_109 ) ) {
F_26 ( L_6 ) ;
return - V_98 ;
}
V_82 = F_38 ( sizeof( * V_82 ) , V_110 ) ;
if ( ! V_82 )
return - V_39 ;
F_39 ( & V_82 -> V_89 ) ;
for ( V_30 = 0 ; V_30 < V_90 ; V_30 ++ ) {
V_82 -> V_84 [ V_30 ] . V_23 = NULL ;
V_82 -> V_84 [ V_30 ] . V_85 = false ;
V_82 -> V_84 [ V_30 ] . V_103 = false ;
}
V_5 -> V_6 = V_82 ;
return 0 ;
}
int F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_82 = V_5 -> V_6 ;
bool V_111 = false ;
int V_30 ;
if ( ! V_82 )
return - V_98 ;
for ( V_30 = 0 ; V_30 < V_90 ; V_30 ++ ) {
if ( V_82 -> V_84 [ V_30 ] . V_23 ) {
V_111 = true ;
F_16 ( V_5 , V_30 , false , false ) ;
}
}
F_23 ( V_111 ) ;
V_5 -> V_6 = NULL ;
F_41 ( V_82 ) ;
return 0 ;
}
