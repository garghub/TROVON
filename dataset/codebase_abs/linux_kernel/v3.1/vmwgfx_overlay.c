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
bool V_24 , bool V_25 )
{
struct V_26 * V_27 = & V_23 -> V_28 ;
struct V_29 * V_30 = & V_31 ;
int V_32 ;
V_32 = F_5 ( & V_5 -> V_33 -> V_34 , V_25 ) ;
if ( F_6 ( V_32 != 0 ) )
return V_32 ;
V_32 = F_7 ( V_27 , V_25 , false , false , 0 ) ;
if ( F_6 ( V_32 != 0 ) )
goto V_35;
if ( V_24 )
V_30 = & V_36 ;
V_32 = F_8 ( V_27 , V_30 , V_25 , false , false ) ;
F_9 ( V_27 ) ;
V_35:
F_10 ( & V_5 -> V_33 -> V_34 ) ;
return V_32 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
struct V_37 * V_38 ,
bool V_25 )
{
struct {
struct V_7 V_17 ;
struct {
struct {
T_1 V_19 ;
T_1 V_21 ;
} V_8 ;
struct {
T_1 V_39 ;
T_1 V_40 ;
} V_41 [ V_42 + 1 ] ;
} V_12 ;
struct V_15 V_18 ;
} * V_43 ;
T_1 V_44 ;
int V_45 , V_32 ;
for (; ; ) {
V_43 = F_12 ( V_5 , sizeof( * V_43 ) ) ;
if ( V_43 )
break;
V_32 = F_13 ( V_5 , false , true , 0 ,
V_25 , 3 * V_46 ) ;
if ( V_25 && V_32 == - V_47 )
return V_32 ;
else
F_14 ( V_32 != 0 ) ;
}
F_2 ( & V_43 -> V_17 , sizeof( V_43 -> V_12 ) ) ;
V_43 -> V_12 . V_8 . V_19 = V_48 ;
V_43 -> V_12 . V_8 . V_21 = V_38 -> V_16 ;
for ( V_45 = 0 ; V_45 <= V_42 ; V_45 ++ )
V_43 -> V_12 . V_41 [ V_45 ] . V_39 = V_45 ;
V_44 = V_23 -> V_28 . V_44 + V_38 -> V_44 ;
V_43 -> V_12 . V_41 [ V_49 ] . V_40 = true ;
V_43 -> V_12 . V_41 [ V_50 ] . V_40 = V_38 -> V_51 ;
V_43 -> V_12 . V_41 [ V_52 ] . V_40 = V_44 ;
V_43 -> V_12 . V_41 [ V_53 ] . V_40 = V_38 -> V_54 ;
V_43 -> V_12 . V_41 [ V_55 ] . V_40 = V_38 -> V_56 ;
V_43 -> V_12 . V_41 [ V_57 ] . V_40 = V_38 -> V_9 ;
V_43 -> V_12 . V_41 [ V_58 ] . V_40 = V_38 -> V_59 ;
V_43 -> V_12 . V_41 [ V_60 ] . V_40 = V_38 -> V_61 ;
V_43 -> V_12 . V_41 [ V_62 ] . V_40 = V_38 -> V_63 . V_64 ;
V_43 -> V_12 . V_41 [ V_65 ] . V_40 = V_38 -> V_63 . V_66 ;
V_43 -> V_12 . V_41 [ V_67 ] . V_40 = V_38 -> V_63 . V_68 ;
V_43 -> V_12 . V_41 [ V_69 ] . V_40 = V_38 -> V_63 . V_70 ;
V_43 -> V_12 . V_41 [ V_71 ] . V_40 = V_38 -> V_72 . V_64 ;
V_43 -> V_12 . V_41 [ V_73 ] . V_40 = V_38 -> V_72 . V_66 ;
V_43 -> V_12 . V_41 [ V_74 ] . V_40 = V_38 -> V_72 . V_68 ;
V_43 -> V_12 . V_41 [ V_75 ] . V_40 = V_38 -> V_72 . V_70 ;
V_43 -> V_12 . V_41 [ V_76 ] . V_40 = V_38 -> V_77 [ 0 ] ;
V_43 -> V_12 . V_41 [ V_78 ] . V_40 = V_38 -> V_77 [ 1 ] ;
V_43 -> V_12 . V_41 [ V_42 ] . V_40 = V_38 -> V_77 [ 2 ] ;
F_3 ( & V_43 -> V_18 , V_38 -> V_16 ) ;
F_15 ( V_5 , sizeof( * V_43 ) ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 ,
T_1 V_16 ,
bool V_25 )
{
struct {
struct V_7 V_17 ;
T_2 V_12 ;
struct V_15 V_18 ;
} * V_43 ;
int V_32 ;
for (; ; ) {
V_43 = F_12 ( V_5 , sizeof( * V_43 ) ) ;
if ( V_43 )
break;
V_32 = F_13 ( V_5 , false , true , 0 ,
V_25 , 3 * V_46 ) ;
if ( V_25 && V_32 == - V_47 )
return V_32 ;
else
F_14 ( V_32 != 0 ) ;
}
F_2 ( & V_43 -> V_17 , sizeof( V_43 -> V_12 ) ) ;
V_43 -> V_12 . V_8 . V_19 = V_48 ;
V_43 -> V_12 . V_8 . V_21 = V_16 ;
V_43 -> V_12 . V_41 [ 0 ] . V_39 = V_49 ;
V_43 -> V_12 . V_41 [ 0 ] . V_40 = false ;
F_3 ( & V_43 -> V_18 , V_16 ) ;
F_15 ( V_5 , sizeof( * V_43 ) ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 ,
T_1 V_16 , bool V_79 ,
bool V_25 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
struct V_81 * V_82 = & V_80 -> V_82 [ V_16 ] ;
int V_32 ;
if ( ! V_82 -> V_23 )
return 0 ;
if ( ! V_82 -> V_83 ) {
V_32 = F_16 ( V_5 , V_16 ,
V_25 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_4 ( V_5 , V_82 -> V_23 , false ,
V_25 ) ;
if ( V_25 && V_32 == - V_47 )
return V_32 ;
else
F_14 ( V_32 != 0 ) ;
}
if ( ! V_79 ) {
F_18 ( & V_82 -> V_23 ) ;
V_82 -> V_83 = false ;
} else {
V_82 -> V_83 = true ;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_22 * V_23 ,
struct V_37 * V_38 ,
bool V_25 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
struct V_81 * V_82 = & V_80 -> V_82 [ V_38 -> V_16 ] ;
int V_32 = 0 ;
if ( ! V_23 )
return - V_84 ;
F_20 ( L_1 , V_85 ,
V_82 -> V_23 , V_23 , V_82 -> V_83 ? L_2 : L_3 ) ;
if ( V_82 -> V_23 != V_23 ) {
V_32 = F_17 ( V_5 , V_38 -> V_16 ,
false , V_25 ) ;
if ( V_32 )
return V_32 ;
} else if ( ! V_82 -> V_83 ) {
V_32 = F_11 ( V_5 , V_23 , V_38 , V_25 ) ;
if ( V_32 == 0 )
V_82 -> V_86 = * V_38 ;
else
F_14 ( ! V_25 ) ;
return V_32 ;
}
V_32 = F_4 ( V_5 , V_23 , true , V_25 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_11 ( V_5 , V_23 , V_38 , V_25 ) ;
if ( V_32 ) {
F_14 ( F_4 ( V_5 , V_23 , false , false ) != 0 ) ;
return V_32 ;
}
if ( V_82 -> V_23 != V_23 )
V_82 -> V_23 = F_21 ( V_23 ) ;
V_82 -> V_86 = * V_38 ;
V_82 -> V_83 = false ;
return 0 ;
}
int F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
int V_45 , V_32 ;
if ( ! V_80 )
return 0 ;
F_23 ( & V_80 -> V_87 ) ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
struct V_81 * V_82 = & V_80 -> V_82 [ V_45 ] ;
if ( ! V_82 -> V_23 )
continue;
V_32 = F_17 ( V_5 , V_45 , false , false ) ;
F_24 ( V_32 != 0 ) ;
}
F_25 ( & V_80 -> V_87 ) ;
return 0 ;
}
int F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
int V_45 , V_32 ;
if ( ! V_80 )
return 0 ;
F_23 ( & V_80 -> V_87 ) ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
struct V_81 * V_82 = & V_80 -> V_82 [ V_45 ] ;
if ( ! V_82 -> V_83 )
continue;
V_32 = F_19 ( V_5 , V_82 -> V_23 ,
& V_82 -> V_86 , false ) ;
if ( V_32 != 0 )
F_27 ( L_4 ,
V_85 , V_45 ) ;
}
F_25 ( & V_80 -> V_87 ) ;
return 0 ;
}
int F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
int V_45 , V_32 ;
if ( ! V_80 )
return 0 ;
F_23 ( & V_80 -> V_87 ) ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
if ( V_80 -> V_82 [ V_45 ] . V_83 )
F_27 ( L_5 ,
V_85 , V_45 ) ;
V_32 = F_17 ( V_5 , V_45 , true , false ) ;
F_24 ( V_32 != 0 ) ;
}
F_25 ( & V_80 -> V_87 ) ;
return 0 ;
}
int F_29 ( struct V_2 * V_3 , void * V_89 ,
struct V_90 * V_91 )
{
struct V_92 * V_93 = F_30 ( V_91 ) -> V_93 ;
struct V_4 * V_5 = F_1 ( V_3 ) ;
struct V_1 * V_80 = V_5 -> V_6 ;
struct V_37 * V_38 =
(struct V_37 * ) V_89 ;
struct V_22 * V_23 ;
struct V_94 * V_95 ;
int V_32 ;
if ( ! V_80 )
return - V_96 ;
V_32 = F_31 ( V_5 , V_93 , & V_38 -> V_16 , & V_95 ) ;
if ( V_32 )
return V_32 ;
F_23 ( & V_80 -> V_87 ) ;
if ( ! V_38 -> V_97 ) {
V_32 = F_17 ( V_5 , V_38 -> V_16 , false , true ) ;
goto V_98;
}
V_32 = F_32 ( V_93 , V_38 -> V_99 , & V_23 ) ;
if ( V_32 )
goto V_98;
V_32 = F_19 ( V_5 , V_23 , V_38 , true ) ;
F_18 ( & V_23 ) ;
V_98:
F_25 ( & V_80 -> V_87 ) ;
F_33 ( & V_95 ) ;
return V_32 ;
}
int F_34 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_6 )
return 0 ;
return V_88 ;
}
int F_35 ( struct V_4 * V_5 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
int V_45 , V_100 ;
if ( ! V_80 )
return 0 ;
F_23 ( & V_80 -> V_87 ) ;
for ( V_45 = 0 , V_100 = 0 ; V_45 < V_88 ; V_45 ++ )
if ( ! V_80 -> V_82 [ V_45 ] . V_101 )
V_100 ++ ;
F_25 ( & V_80 -> V_87 ) ;
return V_100 ;
}
int F_36 ( struct V_4 * V_5 , T_1 * V_102 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
int V_45 ;
if ( ! V_80 )
return - V_96 ;
F_23 ( & V_80 -> V_87 ) ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
if ( V_80 -> V_82 [ V_45 ] . V_101 )
continue;
V_80 -> V_82 [ V_45 ] . V_101 = true ;
* V_102 = V_45 ;
F_25 ( & V_80 -> V_87 ) ;
return 0 ;
}
F_25 ( & V_80 -> V_87 ) ;
return - V_103 ;
}
int F_37 ( struct V_4 * V_5 , T_1 V_16 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
F_14 ( V_16 >= V_88 ) ;
if ( ! V_80 )
return - V_96 ;
F_23 ( & V_80 -> V_87 ) ;
F_24 ( ! V_80 -> V_82 [ V_16 ] . V_101 ) ;
F_17 ( V_5 , V_16 , false , false ) ;
V_80 -> V_82 [ V_16 ] . V_101 = false ;
F_25 ( & V_80 -> V_87 ) ;
return 0 ;
}
int F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_80 ;
int V_45 ;
if ( V_5 -> V_6 )
return - V_84 ;
if ( ! ( V_5 -> V_104 . V_105 & V_106 ) &&
( V_5 -> V_104 . V_105 & V_107 ) ) {
F_27 ( L_6 ) ;
return - V_96 ;
}
V_80 = F_39 ( sizeof( * V_80 ) , V_108 ) ;
if ( ! V_80 )
return - V_109 ;
F_40 ( & V_80 -> V_87 ) ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
V_80 -> V_82 [ V_45 ] . V_23 = NULL ;
V_80 -> V_82 [ V_45 ] . V_83 = false ;
V_80 -> V_82 [ V_45 ] . V_101 = false ;
}
V_5 -> V_6 = V_80 ;
return 0 ;
}
int F_41 ( struct V_4 * V_5 )
{
struct V_1 * V_80 = V_5 -> V_6 ;
bool V_110 = false ;
int V_45 ;
if ( ! V_80 )
return - V_96 ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
if ( V_80 -> V_82 [ V_45 ] . V_23 ) {
V_110 = true ;
F_17 ( V_5 , V_45 , false , false ) ;
}
}
F_24 ( V_110 ) ;
V_5 -> V_6 = NULL ;
F_42 ( V_80 ) ;
return 0 ;
}
