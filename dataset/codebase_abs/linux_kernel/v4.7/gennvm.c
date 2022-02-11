static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 , * V_10 , * V_11 ;
T_1 V_12 = 0 ;
T_1 V_13 = ( V_2 -> V_14 * V_2 -> V_15 ) >> 9 ;
if ( V_4 > V_13 )
return - V_16 ;
V_9 = F_2 ( sizeof( struct V_8 ) , V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_10 = NULL ;
F_3 ( & V_2 -> V_19 ) ;
F_4 (next, &gn->area_list, list) {
if ( V_12 + V_4 > V_11 -> V_12 ) {
V_12 = V_11 -> V_20 ;
V_10 = V_11 ;
continue;
}
break;
}
if ( ( V_12 + V_4 ) > V_13 ) {
F_5 ( & V_2 -> V_19 ) ;
F_6 ( V_9 ) ;
return - V_16 ;
}
V_9 -> V_12 = * V_3 = V_12 ;
V_9 -> V_20 = V_12 + V_4 ;
if ( V_10 )
F_7 ( & V_9 -> V_21 , & V_10 -> V_21 ) ;
else
F_7 ( & V_9 -> V_21 , & V_6 -> V_22 ) ;
F_5 ( & V_2 -> V_19 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
F_3 ( & V_2 -> V_19 ) ;
F_4 (area, &gn->area_list, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_9 ( & V_9 -> V_21 ) ;
F_5 ( & V_2 -> V_19 ) ;
F_6 ( V_9 ) ;
return;
}
F_5 ( & V_2 -> V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 ;
int V_25 ;
F_11 (gn, lun, i) {
if ( ! V_24 -> V_26 . V_27 )
break;
F_12 ( V_24 -> V_26 . V_27 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_6 ( V_6 -> V_28 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_23 * V_24 ;
int V_25 ;
V_6 -> V_28 = F_15 ( V_2 -> V_29 , sizeof( struct V_23 ) , V_17 ) ;
if ( ! V_6 -> V_28 )
return - V_18 ;
F_11 (gn, lun, i) {
F_16 ( & V_24 -> V_26 . V_19 ) ;
F_17 ( & V_24 -> V_30 ) ;
F_17 ( & V_24 -> V_31 ) ;
F_17 ( & V_24 -> V_32 ) ;
V_24 -> V_33 = 2 ;
V_24 -> V_26 . V_34 = V_25 ;
V_24 -> V_26 . V_35 = V_25 % V_2 -> V_36 ;
V_24 -> V_26 . V_37 = V_25 / V_2 -> V_36 ;
V_24 -> V_26 . V_38 = V_2 -> V_39 ;
V_24 -> V_26 . V_40 = 0 ;
V_24 -> V_26 . V_41 = 0 ;
V_24 -> V_26 . V_42 = 0 ;
}
return 0 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_43 V_44 ,
T_2 * V_45 , int V_46 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_23 * V_24 ;
struct V_47 * V_48 ;
int V_25 ;
V_46 = F_19 ( V_2 , V_45 , V_46 ) ;
if ( V_46 < 0 )
return V_46 ;
V_24 = & V_6 -> V_28 [ ( V_2 -> V_36 * V_44 . V_49 . V_50 ) + V_44 . V_49 . V_24 ] ;
for ( V_25 = 0 ; V_25 < V_46 ; V_25 ++ ) {
if ( V_45 [ V_25 ] == 0 )
continue;
V_48 = & V_24 -> V_26 . V_27 [ V_25 ] ;
F_20 ( & V_48 -> V_21 , & V_24 -> V_32 ) ;
V_24 -> V_26 . V_42 ++ ;
V_24 -> V_26 . V_38 -- ;
}
return 0 ;
}
static int F_21 ( T_3 V_51 , T_4 V_52 , T_5 * V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_55 = V_51 + V_52 ;
struct V_23 * V_24 ;
struct V_47 * V_48 ;
T_3 V_25 ;
int V_35 ;
if ( F_22 ( V_55 > V_2 -> V_15 ) ) {
F_23 ( L_1 ) ;
return - V_16 ;
}
for ( V_25 = 0 ; V_25 < V_52 ; V_25 ++ ) {
T_3 V_56 = F_24 ( V_53 [ V_25 ] ) ;
if ( F_22 ( V_56 >= V_2 -> V_15 && V_56 != V_57 ) ) {
F_23 ( L_2 ) ;
return - V_16 ;
}
if ( ! V_56 )
continue;
V_35 = F_25 ( V_56 , V_2 -> V_58 ) ;
V_24 = & V_6 -> V_28 [ V_35 ] ;
V_56 = V_56 - ( V_2 -> V_58 * V_35 ) ;
V_48 = & V_24 -> V_26 . V_27 [ F_25 ( V_56 , V_2 -> V_59 ) ] ;
if ( ! V_48 -> V_60 ) {
F_20 ( & V_48 -> V_21 , & V_24 -> V_31 ) ;
V_48 -> V_60 = V_61 ;
V_24 -> V_26 . V_38 -- ;
V_24 -> V_26 . V_40 ++ ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_23 * V_24 ;
struct V_47 * V_62 ;
T_1 V_63 , V_64 , V_65 = 0 ;
int V_66 , V_46 ;
T_2 * V_45 ;
V_46 = V_2 -> V_39 * V_2 -> V_67 ;
V_45 = F_2 ( V_46 , V_17 ) ;
if ( ! V_45 )
return - V_18 ;
F_11 (gn, lun, lun_iter) {
V_24 -> V_26 . V_27 = F_27 ( sizeof( struct V_47 ) *
V_2 -> V_39 ) ;
if ( ! V_24 -> V_26 . V_27 ) {
F_6 ( V_45 ) ;
return - V_18 ;
}
for ( V_64 = 0 ; V_64 < V_2 -> V_39 ; V_64 ++ ) {
V_62 = & V_24 -> V_26 . V_27 [ V_64 ] ;
F_17 ( & V_62 -> V_21 ) ;
V_62 -> V_24 = & V_24 -> V_26 ;
V_62 -> V_34 = V_65 ++ ;
if ( F_22 ( V_63 == 0 && V_64 == 0 ) ) {
V_24 -> V_26 . V_38 -- ;
continue;
}
F_28 ( & V_62 -> V_21 , & V_24 -> V_30 ) ;
}
if ( V_2 -> V_68 -> V_69 ) {
struct V_43 V_44 ;
V_44 . V_44 = 0 ;
V_44 . V_49 . V_50 = V_24 -> V_26 . V_37 ;
V_44 . V_49 . V_24 = V_24 -> V_26 . V_35 ;
V_66 = F_29 ( V_2 , V_44 , V_45 ) ;
if ( V_66 )
F_23 ( L_3 ) ;
V_66 = F_18 ( V_6 , V_44 , V_45 , V_46 ) ;
if ( V_66 )
F_23 ( L_4 ) ;
}
}
if ( ( V_2 -> V_70 . V_71 & V_72 ) && V_2 -> V_68 -> V_73 ) {
V_66 = V_2 -> V_68 -> V_73 ( V_2 , 0 , V_2 -> V_15 ,
F_21 , V_2 ) ;
if ( V_66 ) {
F_23 ( L_5 ) ;
F_30 ( L_6 ) ;
}
}
F_6 ( V_45 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
F_6 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_66 ;
if ( ! F_33 ( V_74 ) )
return - V_75 ;
V_6 = F_34 ( sizeof( struct V_5 ) , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_29 = V_2 -> V_29 ;
F_17 ( & V_6 -> V_22 ) ;
V_2 -> V_7 = V_6 ;
V_66 = F_14 ( V_2 , V_6 ) ;
if ( V_66 ) {
F_23 ( L_7 ) ;
goto V_76;
}
V_66 = F_26 ( V_2 , V_6 ) ;
if ( V_66 ) {
F_23 ( L_8 ) ;
goto V_76;
}
return 1 ;
V_76:
F_31 ( V_2 ) ;
F_35 ( V_74 ) ;
return V_66 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_35 ( V_74 ) ;
}
static struct V_47 * F_37 ( struct V_1 * V_2 ,
struct V_77 * V_26 , unsigned long V_78 )
{
struct V_23 * V_24 = F_38 ( V_26 , struct V_23 , V_26 ) ;
struct V_47 * V_48 = NULL ;
int V_79 = V_78 & V_80 ;
F_39 ( & V_26 -> V_19 ) ;
if ( F_40 ( & V_24 -> V_30 ) ) {
F_41 ( L_9 ,
V_24 -> V_26 . V_34 ) ;
goto V_81;
}
if ( ! V_79 && V_24 -> V_26 . V_38 < V_24 -> V_33 )
goto V_81;
V_48 = F_42 ( & V_24 -> V_30 , struct V_47 , V_21 ) ;
F_20 ( & V_48 -> V_21 , & V_24 -> V_31 ) ;
V_48 -> V_60 = V_61 ;
V_24 -> V_26 . V_38 -- ;
V_24 -> V_26 . V_40 ++ ;
V_81:
return V_48 ;
}
static struct V_47 * F_43 ( struct V_1 * V_2 ,
struct V_77 * V_26 , unsigned long V_78 )
{
struct V_47 * V_48 ;
F_3 ( & V_26 -> V_19 ) ;
V_48 = F_37 ( V_2 , V_26 , V_78 ) ;
F_5 ( & V_26 -> V_19 ) ;
return V_48 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_77 * V_26 = V_48 -> V_24 ;
struct V_23 * V_24 = F_38 ( V_26 , struct V_23 , V_26 ) ;
F_39 ( & V_26 -> V_19 ) ;
if ( V_48 -> V_60 & V_61 ) {
F_20 ( & V_48 -> V_21 , & V_24 -> V_30 ) ;
V_24 -> V_26 . V_40 -- ;
V_24 -> V_26 . V_38 ++ ;
V_48 -> V_60 = V_82 ;
} else if ( V_48 -> V_60 & V_83 ) {
F_20 ( & V_48 -> V_21 , & V_24 -> V_30 ) ;
V_24 -> V_26 . V_41 -- ;
V_24 -> V_26 . V_38 ++ ;
V_48 -> V_60 = V_82 ;
} else if ( V_48 -> V_60 & V_84 ) {
F_20 ( & V_48 -> V_21 , & V_24 -> V_32 ) ;
V_24 -> V_26 . V_42 ++ ;
V_48 -> V_60 = V_84 ;
} else {
F_45 ( 1 ) ;
F_23 ( L_10 ,
V_48 -> V_34 , V_48 -> V_60 ) ;
F_20 ( & V_48 -> V_21 , & V_24 -> V_32 ) ;
V_24 -> V_26 . V_42 ++ ;
V_48 -> V_60 = V_84 ;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_77 * V_26 = V_48 -> V_24 ;
F_3 ( & V_26 -> V_19 ) ;
F_44 ( V_2 , V_48 ) ;
F_5 ( & V_26 -> V_19 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_43 V_44 , int type )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 ;
struct V_47 * V_48 ;
F_48 ( L_11 ,
V_44 . V_49 . V_50 , V_44 . V_49 . V_24 , V_44 . V_49 . V_48 , V_44 . V_49 . V_85 , type ) ;
if ( F_22 ( V_44 . V_49 . V_50 > V_2 -> V_86 ||
V_44 . V_49 . V_24 > V_2 -> V_36 ||
V_44 . V_49 . V_48 > V_2 -> V_39 ) ) {
F_45 ( 1 ) ;
F_23 ( L_12 ,
V_44 . V_49 . V_50 , V_2 -> V_86 ,
V_44 . V_49 . V_24 , V_2 -> V_36 ,
V_44 . V_49 . V_48 , V_2 -> V_39 ) ;
return;
}
V_24 = & V_6 -> V_28 [ V_44 . V_49 . V_24 * V_44 . V_49 . V_50 ] ;
V_48 = & V_24 -> V_26 . V_27 [ V_44 . V_49 . V_48 ] ;
V_48 -> V_60 = type ;
}
static void F_49 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
int V_89 = - 1 ;
int V_90 = V_2 -> V_68 -> V_91 ;
void * V_92 = & V_88 -> V_93 ;
F_50 ( V_2 , V_88 ) ;
if ( V_88 -> V_94 == 1 ) {
F_47 ( V_2 , V_88 -> V_43 , V_84 ) ;
return;
}
while ( ( V_89 = F_51 ( V_92 , V_90 , V_89 + 1 ) ) < V_90 )
F_47 ( V_2 , V_88 -> V_95 [ V_89 ] , V_84 ) ;
}
static void F_52 ( struct V_87 * V_88 )
{
struct V_96 * V_97 = V_88 -> V_97 ;
if ( V_88 -> error == V_98 )
F_49 ( V_88 -> V_2 , V_88 ) ;
V_97 -> V_99 -> V_100 ( V_88 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
if ( ! V_2 -> V_68 -> V_101 )
return - V_75 ;
F_54 ( V_2 , V_88 ) ;
V_88 -> V_2 = V_2 ;
V_88 -> V_100 = F_52 ;
return V_2 -> V_68 -> V_101 ( V_2 , V_88 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_47 * V_48 ,
unsigned long V_78 )
{
struct V_43 V_102 = F_56 ( V_2 , V_48 ) ;
return F_57 ( V_2 , & V_102 , 1 ) ;
}
static int F_58 ( struct V_1 * V_2 , int V_103 )
{
return F_59 ( V_103 , V_2 -> V_104 ) ;
}
static void F_60 ( struct V_1 * V_2 , int V_103 )
{
F_61 ( ! F_62 ( V_103 , V_2 -> V_104 ) ) ;
}
static struct V_77 * F_63 ( struct V_1 * V_2 , int V_103 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_22 ( V_103 >= V_2 -> V_29 ) )
return NULL ;
return & V_6 -> V_28 [ V_103 ] . V_26 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 ;
unsigned int V_25 ;
F_11 (gn, lun, i) {
F_3 ( & V_24 -> V_26 . V_19 ) ;
F_65 ( L_13 ,
V_2 -> V_105 , V_25 ,
V_24 -> V_26 . V_38 ,
V_24 -> V_26 . V_40 ,
V_24 -> V_26 . V_41 ,
V_24 -> V_26 . V_42 ) ;
F_5 ( & V_24 -> V_26 . V_19 ) ;
}
}
static int T_6 F_66 ( void )
{
return F_67 ( & V_106 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_106 ) ;
}
