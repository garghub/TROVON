void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_9 =
(struct V_7 * ) V_4 -> V_10 [ 0 ] ;
struct V_11 * V_12 ;
V_12 = (struct V_11 * ) V_9 -> V_12 ;
V_6 . V_13 = & V_8 ;
V_6 . V_14 = V_9 -> V_14 ;
V_6 . V_15 = V_9 -> V_15 ;
V_6 . V_16 = V_9 -> V_17 << V_18 ;
V_6 . type = V_19 ;
V_6 . V_20 = & V_12 -> V_21 . V_22 ;
V_4 -> V_10 [ 0 ] = V_12 -> V_23 ;
F_2 ( & V_12 -> V_21 . V_24 ) ;
if ( F_3 ( & V_6 ) ) {
F_4 ( & V_2 -> V_25 -> V_26 ,
L_1 , V_27 , __LINE__ ) ;
V_4 -> V_28 = V_29 ;
goto error;
}
F_5 ( V_8 , V_8 -> V_17 ) ;
if ( ! V_8 -> V_30 ) {
F_6 ( & V_12 -> V_21 . V_31 ) ;
V_12 -> V_21 . V_32 = 1 ;
F_7 ( & V_8 -> V_33 ) ;
F_8 ( V_12 , V_8 , V_8 -> V_14 ) ;
}
error:
F_9 ( & V_12 -> V_21 . V_24 ) ;
if ( V_8 && ! V_8 -> V_30 )
F_10 ( V_8 , & V_34 . V_35 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
unsigned long V_42 ;
F_12 ( & V_12 -> V_43 ) ;
F_13 (item, &ep->rma_info.vma_list) {
V_39 = F_14 ( V_37 , struct V_38 , V_33 ) ;
V_41 = V_39 -> V_41 ;
V_42 = V_41 -> V_44 - V_41 -> V_45 ;
F_15 ( V_41 , V_41 -> V_45 , V_42 ) ;
F_16 ( V_34 . V_46 . V_47 ,
L_2 ,
V_27 , V_12 , V_39 -> V_41 , V_42 ) ;
}
F_17 ( & V_12 -> V_43 ) ;
}
static void F_18 ( int V_48 , struct V_36 * V_20 )
{
struct V_11 * V_12 ;
struct V_36 * V_37 ;
F_2 ( & V_34 . V_49 ) ;
F_13 (item, head) {
V_12 = F_14 ( V_37 , struct V_11 , V_33 ) ;
if ( V_12 -> V_50 -> V_48 == V_48 )
F_11 ( V_12 ) ;
}
F_9 ( & V_34 . V_49 ) ;
}
void F_19 ( int V_48 )
{
F_18 ( V_48 , & V_34 . V_51 ) ;
F_18 ( V_48 , & V_34 . V_52 ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
struct V_36 * V_53 , * V_54 ;
struct V_7 * V_8 ;
F_21 (pos, tmp, &ep->rma_info.remote_reg_list) {
V_8 = F_14 ( V_53 , struct V_7 , V_33 ) ;
if ( V_8 -> V_30 )
F_5 ( V_8 , V_8 -> V_17 ) ;
else
F_4 ( V_34 . V_46 . V_47 ,
L_3 ,
V_27 , __LINE__ ) ;
if ( ! V_8 -> V_30 ) {
F_6 ( & V_12 -> V_21 . V_31 ) ;
F_7 ( & V_8 -> V_33 ) ;
F_10 ( V_8 , & V_34 . V_35 ) ;
}
}
}
void F_22 ( int V_48 )
{
struct V_11 * V_12 ;
struct V_36 * V_37 ;
F_2 ( & V_34 . V_55 ) ;
F_13 (item, &scif_info.zombie) {
V_12 = F_14 ( V_37 , struct V_11 , V_33 ) ;
if ( V_12 -> V_50 && V_12 -> V_50 -> V_48 == V_48 )
F_20 ( V_12 ) ;
}
F_9 ( & V_34 . V_55 ) ;
F_23 ( & V_34 . V_56 ) ;
}
static int F_24 ( struct V_11 * V_12 , struct V_40 * V_41 )
{
struct V_38 * V_39 ;
int V_57 = 0 ;
V_39 = F_25 ( sizeof( * V_39 ) , V_58 ) ;
if ( ! V_39 ) {
V_57 = - V_59 ;
goto V_60;
}
V_39 -> V_41 = V_41 ;
F_12 ( & V_12 -> V_43 ) ;
F_26 ( & V_39 -> V_33 , & V_12 -> V_21 . V_61 ) ;
F_17 ( & V_12 -> V_43 ) ;
V_60:
return V_57 ;
}
static void F_27 ( struct V_11 * V_12 , struct V_40 * V_41 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
F_12 ( & V_12 -> V_43 ) ;
F_13 (item, &ep->rma_info.vma_list) {
V_39 = F_14 ( V_37 , struct V_38 , V_33 ) ;
if ( V_39 -> V_41 == V_41 ) {
F_28 ( & V_39 -> V_33 ) ;
F_29 ( V_39 ) ;
break;
}
}
F_17 ( & V_12 -> V_43 ) ;
}
static T_1 F_30 ( T_1 V_62 , struct V_11 * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 -> V_50 ;
struct V_63 * V_25 = V_2 -> V_25 ;
T_1 V_64 , V_65 = 0 ;
if ( ! F_31 ( V_2 ) && V_25 -> V_66 && V_25 -> V_67 )
V_65 = V_25 -> V_66 -> V_68 ;
V_64 = V_65 + V_62 ;
return V_64 ;
}
int F_32 ( T_2 V_69 , T_3 V_14 , T_4 V_70 ,
struct V_71 * * V_72 )
{
struct V_11 * V_12 = (struct V_11 * ) V_69 ;
struct V_5 V_6 ;
struct V_7 * V_8 = NULL ;
int V_17 , V_57 , V_73 ;
F_16 ( V_34 . V_46 . V_47 ,
L_4 ,
V_12 , V_14 , V_70 ) ;
V_57 = F_33 ( V_12 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_70 || ( V_14 < 0 ) ||
( V_14 + V_70 < V_14 ) ||
( F_34 ( V_14 , V_74 ) != V_14 ) ||
( F_34 ( V_70 , V_74 ) != V_70 ) )
return - V_75 ;
V_17 = V_70 >> V_18 ;
V_6 . V_13 = & V_8 ;
V_6 . V_14 = V_14 ;
V_6 . V_15 = 0 ;
V_6 . V_16 = V_70 ;
V_6 . type = V_76 ;
V_6 . V_20 = & V_12 -> V_21 . V_77 ;
F_2 ( & V_12 -> V_21 . V_24 ) ;
V_57 = F_3 ( & V_6 ) ;
if ( V_57 ) {
F_4 ( & V_12 -> V_50 -> V_25 -> V_26 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
goto error;
}
* V_72 = F_25 ( sizeof( * * V_72 ) , V_58 ) ;
if ( ! * V_72 ) {
V_57 = - V_59 ;
goto error;
}
( * V_72 ) -> V_78 = F_35 ( V_17 * sizeof( V_79 ) ) ;
if ( ! ( ( * V_72 ) -> V_78 ) ) {
V_57 = - V_59 ;
goto error;
}
if ( F_36 () && ! F_31 ( V_12 -> V_50 ) ) {
( ( * V_72 ) -> V_80 = F_35 ( V_17 * sizeof( void * ) ) ) ;
if ( ! ( * V_72 ) -> V_80 ) {
V_57 = - V_59 ;
goto error;
}
}
( * V_72 ) -> V_81 = V_8 ;
( * V_72 ) -> V_17 = V_17 ;
( * V_72 ) -> V_82 = V_8 -> V_15 ;
for ( V_73 = 0 ; V_73 < V_17 ; V_73 ++ ) {
( * V_72 ) -> V_78 [ V_73 ] =
F_37 ( V_8 , V_14 +
( V_73 * V_74 ) ) ;
( * V_72 ) -> V_78 [ V_73 ] = F_30 ( ( * V_72 ) -> V_78 [ V_73 ] ,
V_12 ) ;
if ( F_36 () && ! F_31 ( V_12 -> V_50 ) )
( * V_72 ) -> V_80 [ V_73 ] =
V_12 -> V_50 -> V_25 -> V_66 -> V_80 +
( * V_72 ) -> V_78 [ V_73 ] -
V_12 -> V_50 -> V_25 -> V_66 -> V_68 ;
}
F_38 ( V_8 , V_17 ) ;
error:
F_9 ( & V_12 -> V_21 . V_24 ) ;
if ( V_57 ) {
if ( * V_72 ) {
F_39 ( ( * V_72 ) -> V_78 ,
V_17 * sizeof( V_79 ) ) ;
F_39 ( ( * V_72 ) -> V_80 ,
V_17 * sizeof( void * ) ) ;
F_29 ( * V_72 ) ;
* V_72 = NULL ;
}
F_4 ( & V_12 -> V_50 -> V_25 -> V_26 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
}
return V_57 ;
}
int F_40 ( struct V_71 * V_72 )
{
struct V_11 * V_12 ;
struct V_7 * V_8 ;
struct V_3 V_4 ;
if ( ! V_72 || ! V_72 -> V_81 )
return - V_75 ;
V_8 = V_72 -> V_81 ;
if ( ! V_8 || V_8 -> V_83 != V_84 )
return - V_75 ;
V_12 = (struct V_11 * ) V_8 -> V_12 ;
if ( V_12 -> V_85 != V_86 && V_12 -> V_85 != V_87 )
return - V_88 ;
F_2 ( & V_12 -> V_21 . V_24 ) ;
F_5 ( V_8 , V_72 -> V_17 ) ;
if ( ! V_8 -> V_30 ) {
F_28 ( & V_8 -> V_33 ) ;
F_9 ( & V_12 -> V_21 . V_24 ) ;
F_41 ( V_12 -> V_50 -> V_25 ,
V_12 -> V_21 . V_89 ) ;
V_4 . V_28 = V_90 ;
V_4 . V_91 = V_12 -> V_92 ;
V_4 . V_10 [ 0 ] = V_8 -> V_93 ;
F_42 ( V_12 -> V_50 , & V_4 ) ;
F_43 ( V_8 ) ;
} else {
F_9 ( & V_12 -> V_21 . V_24 ) ;
}
F_39 ( V_72 -> V_78 , V_72 -> V_17 * sizeof( V_79 ) ) ;
F_39 ( V_72 -> V_80 , V_72 -> V_17 * sizeof( void * ) ) ;
F_29 ( V_72 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_94 , T_5 V_14 ,
int V_17 , struct V_40 * V_41 )
{
T_5 V_95 , V_96 = V_14 ;
struct V_7 * V_8 = V_94 ;
int V_97 , V_98 = V_17 ;
struct V_11 * V_12 = (struct V_11 * ) V_94 -> V_12 ;
struct V_36 * V_20 = & V_12 -> V_21 . V_77 ;
int V_73 , V_57 = 0 ;
V_79 V_78 ;
struct V_99 V_100 ;
T_4 V_101 = 0 ;
F_45 () ;
F_46 (window, head, list) {
V_95 = V_8 -> V_14 +
( V_8 -> V_17 << V_18 ) ;
V_97 = F_47 ( int ,
( V_95 - V_96 ) >> V_18 ,
V_98 ) ;
F_48 ( V_8 , & V_100 ) ;
for ( V_73 = 0 ; V_73 < V_97 ; V_73 ++ ) {
V_78 = F_49 ( V_8 , V_96 ,
& V_101 ,
& V_100 ) ;
V_78 = F_30 ( V_78 , V_12 ) ;
V_57 = F_50 ( V_41 ,
V_41 -> V_45 +
V_96 - V_14 ,
V_78 >> V_18 ,
V_74 ,
V_41 -> V_102 ) ;
if ( V_57 )
goto error;
V_96 += V_74 ;
}
V_98 -= V_97 ;
if ( ! V_98 )
break;
}
V_96 = V_14 ;
V_98 = V_17 ;
V_8 = V_94 ;
V_20 = & V_12 -> V_21 . V_77 ;
F_46 (window, head, list) {
V_95 = V_8 -> V_14 +
( V_8 -> V_17 << V_18 ) ;
V_97 = F_47 ( int ,
( V_95 - V_96 ) >> V_18 ,
V_98 ) ;
F_38 ( V_8 , V_97 ) ;
V_98 -= V_97 ;
V_96 += ( V_97 << V_18 ) ;
if ( ! V_98 )
break;
}
error:
if ( V_57 )
F_4 ( V_34 . V_46 . V_47 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
return V_57 ;
}
static void F_51 ( struct V_7 * V_94 ,
T_5 V_14 , int V_17 )
{
struct V_3 V_4 ;
T_5 V_96 = V_14 , V_95 ;
int V_97 , V_98 = V_17 ;
struct V_11 * V_12 = (struct V_11 * ) V_94 -> V_12 ;
struct V_36 * V_20 = & V_12 -> V_21 . V_77 ;
struct V_7 * V_8 = V_94 , * V_103 ;
V_4 . V_28 = V_90 ;
V_4 . V_91 = V_12 -> V_92 ;
V_96 = V_14 ;
V_98 = V_17 ;
F_52 (window, _window, head, list) {
V_95 = V_8 -> V_14 +
( V_8 -> V_17 << V_18 ) ;
V_97 = F_47 ( int ,
( V_95 - V_96 ) >> V_18 ,
V_98 ) ;
F_5 ( V_8 , V_97 ) ;
if ( ! V_8 -> V_30 ) {
struct V_1 * V_104 = V_12 -> V_50 ;
F_41 ( V_104 -> V_25 ,
V_12 -> V_21 . V_89 ) ;
V_4 . V_10 [ 0 ] = V_8 -> V_93 ;
F_42 ( V_12 -> V_50 , & V_4 ) ;
F_28 ( & V_8 -> V_33 ) ;
F_43 ( V_8 ) ;
}
V_98 -= V_97 ;
V_96 += ( V_97 << V_18 ) ;
if ( ! V_98 )
break;
}
}
static void F_53 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = F_54 ( V_106 , struct V_107 , V_106 ) ;
F_29 ( V_108 ) ;
}
static void F_55 ( struct V_40 * V_41 )
{
struct V_107 * V_108 = V_41 -> V_109 ;
F_16 ( V_34 . V_46 . V_47 ,
L_6 ,
V_41 -> V_45 , V_41 -> V_44 ) ;
F_24 ( V_108 -> V_12 , V_41 ) ;
F_56 ( & V_108 -> V_106 ) ;
}
static void F_57 ( struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_107 * V_108 = V_41 -> V_109 ;
int V_17 = F_58 ( V_41 ) ;
T_5 V_14 ;
struct V_5 V_6 ;
struct V_7 * V_8 = NULL ;
int V_57 ;
F_45 () ;
F_16 ( V_34 . V_46 . V_47 ,
L_7 ,
V_41 -> V_45 , V_41 -> V_44 ) ;
V_12 = V_108 -> V_12 ;
V_14 = V_108 -> V_110 ? V_108 -> V_14 :
( V_41 -> V_111 ) << V_18 ;
F_16 ( V_34 . V_46 . V_47 ,
L_8 ,
V_12 , V_17 , V_14 ) ;
V_6 . V_13 = & V_8 ;
V_6 . V_14 = V_14 ;
V_6 . V_16 = V_41 -> V_44 - V_41 -> V_45 ;
V_6 . V_15 = V_41 -> V_112 & ( V_113 | V_114 ) ;
V_6 . type = V_115 ;
V_6 . V_20 = & V_12 -> V_21 . V_77 ;
F_2 ( & V_12 -> V_21 . V_24 ) ;
V_57 = F_3 ( & V_6 ) ;
if ( V_57 )
F_4 ( V_34 . V_46 . V_47 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
else
F_51 ( V_8 , V_14 , V_17 ) ;
F_9 ( & V_12 -> V_21 . V_24 ) ;
V_41 -> V_116 = NULL ;
V_41 -> V_109 = NULL ;
F_59 ( & V_108 -> V_106 , F_53 ) ;
F_27 ( V_12 , V_41 ) ;
}
int F_60 ( struct V_40 * V_41 , T_2 V_69 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = NULL ;
struct V_11 * V_12 = (struct V_11 * ) V_69 ;
T_5 V_117 = V_41 -> V_111 << V_18 ;
int V_17 = F_58 ( V_41 ) ;
int V_57 ;
struct V_107 * V_108 ;
F_16 ( V_34 . V_46 . V_47 ,
L_9 ,
V_12 , V_117 , V_17 ) ;
V_57 = F_33 ( V_12 ) ;
if ( V_57 )
return V_57 ;
F_45 () ;
V_57 = F_24 ( V_12 , V_41 ) ;
if ( V_57 )
return V_57 ;
V_108 = F_25 ( sizeof( * V_108 ) , V_58 ) ;
if ( ! V_108 ) {
F_27 ( V_12 , V_41 ) ;
return - V_59 ;
}
V_108 -> V_12 = V_12 ;
F_61 ( & V_108 -> V_106 ) ;
V_6 . V_13 = & V_8 ;
V_6 . V_14 = V_117 ;
V_6 . V_16 = V_41 -> V_44 - V_41 -> V_45 ;
V_6 . V_15 = V_41 -> V_112 & ( V_113 | V_114 ) ;
V_6 . type = V_115 ;
V_6 . V_20 = & V_12 -> V_21 . V_77 ;
F_2 ( & V_12 -> V_21 . V_24 ) ;
V_57 = F_3 ( & V_6 ) ;
if ( V_57 ) {
F_4 ( & V_12 -> V_50 -> V_25 -> V_26 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
goto V_118;
}
if ( ! F_31 ( V_12 -> V_50 ) )
V_41 -> V_102 = F_62 ( V_41 -> V_102 ) ;
V_41 -> V_112 |= V_119 | V_120 | V_121 ;
if ( ! F_31 ( V_12 -> V_50 ) )
V_41 -> V_112 |= V_122 | V_123 ;
V_57 = F_44 ( V_8 , V_117 , V_17 , V_41 ) ;
if ( V_57 ) {
F_4 ( & V_12 -> V_50 -> V_25 -> V_26 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
goto V_118;
}
V_41 -> V_116 = & V_124 ;
V_41 -> V_109 = V_108 ;
V_118:
F_9 ( & V_12 -> V_21 . V_24 ) ;
if ( V_57 ) {
F_29 ( V_108 ) ;
F_4 ( & V_12 -> V_50 -> V_25 -> V_26 ,
L_5 , V_27 , __LINE__ , V_57 ) ;
F_27 ( V_12 , V_41 ) ;
}
return V_57 ;
}
