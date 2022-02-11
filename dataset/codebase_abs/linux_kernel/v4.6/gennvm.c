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
static int F_18 ( struct V_43 V_44 , int V_45 , T_2 * V_46 ,
void * V_47 )
{
struct V_5 * V_6 = V_47 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_23 * V_24 ;
struct V_48 * V_49 ;
int V_25 ;
V_24 = & V_6 -> V_28 [ ( V_2 -> V_36 * V_44 . V_50 . V_51 ) + V_44 . V_50 . V_24 ] ;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ ) {
if ( V_46 [ V_25 ] == 0 )
continue;
V_49 = & V_24 -> V_26 . V_27 [ V_25 ] ;
if ( ! V_49 ) {
F_19 ( L_1 ) ;
return - V_16 ;
}
F_20 ( & V_49 -> V_21 , & V_24 -> V_32 ) ;
V_24 -> V_26 . V_42 ++ ;
V_24 -> V_26 . V_38 -- ;
}
return 0 ;
}
static int F_21 ( T_3 V_52 , T_4 V_53 , T_5 * V_54 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_55 = V_52 + V_53 ;
struct V_23 * V_24 ;
struct V_48 * V_49 ;
T_3 V_25 ;
int V_35 ;
if ( F_22 ( V_55 > V_2 -> V_15 ) ) {
F_19 ( L_2 ) ;
return - V_16 ;
}
for ( V_25 = 0 ; V_25 < V_53 ; V_25 ++ ) {
T_3 V_56 = F_23 ( V_54 [ V_25 ] ) ;
if ( F_22 ( V_56 >= V_2 -> V_15 && V_56 != V_57 ) ) {
F_19 ( L_3 ) ;
return - V_16 ;
}
if ( ! V_56 )
continue;
V_35 = F_24 ( V_56 , V_2 -> V_58 ) ;
V_24 = & V_6 -> V_28 [ V_35 ] ;
V_56 = V_56 - ( V_2 -> V_58 * V_35 ) ;
V_49 = & V_24 -> V_26 . V_27 [ F_24 ( V_56 , V_2 -> V_59 ) ] ;
if ( ! V_49 -> V_60 ) {
F_20 ( & V_49 -> V_21 , & V_24 -> V_31 ) ;
V_49 -> V_60 = V_61 ;
V_24 -> V_26 . V_38 -- ;
V_24 -> V_26 . V_40 ++ ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_23 * V_24 ;
struct V_48 * V_62 ;
T_1 V_63 , V_64 , V_65 = 0 ;
int V_66 ;
F_11 (gn, lun, lun_iter) {
V_24 -> V_26 . V_27 = F_26 ( sizeof( struct V_48 ) *
V_2 -> V_39 ) ;
if ( ! V_24 -> V_26 . V_27 )
return - V_18 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_39 ; V_64 ++ ) {
V_62 = & V_24 -> V_26 . V_27 [ V_64 ] ;
F_17 ( & V_62 -> V_21 ) ;
V_62 -> V_24 = & V_24 -> V_26 ;
V_62 -> V_34 = V_65 ++ ;
if ( F_22 ( V_63 == 0 && V_64 == 0 ) ) {
V_24 -> V_26 . V_38 -- ;
continue;
}
F_27 ( & V_62 -> V_21 , & V_24 -> V_30 ) ;
}
if ( V_2 -> V_67 -> V_68 ) {
struct V_43 V_44 ;
V_44 . V_44 = 0 ;
V_44 . V_50 . V_51 = V_24 -> V_26 . V_37 ;
V_44 . V_50 . V_24 = V_24 -> V_26 . V_34 ;
V_44 = F_28 ( V_2 , V_44 ) ;
V_66 = V_2 -> V_67 -> V_68 ( V_2 , V_44 ,
V_2 -> V_39 ,
F_18 , V_6 ) ;
if ( V_66 )
F_19 ( L_4 ) ;
}
}
if ( ( V_2 -> V_69 . V_70 & V_71 ) && V_2 -> V_67 -> V_72 ) {
V_66 = V_2 -> V_67 -> V_72 ( V_2 , 0 , V_2 -> V_15 ,
F_21 , V_2 ) ;
if ( V_66 ) {
F_19 ( L_5 ) ;
F_29 ( L_6 ) ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
F_6 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_66 ;
if ( ! F_32 ( V_73 ) )
return - V_74 ;
V_6 = F_33 ( sizeof( struct V_5 ) , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_29 = V_2 -> V_29 ;
F_17 ( & V_6 -> V_22 ) ;
V_2 -> V_7 = V_6 ;
V_66 = F_14 ( V_2 , V_6 ) ;
if ( V_66 ) {
F_19 ( L_7 ) ;
goto V_75;
}
V_66 = F_25 ( V_2 , V_6 ) ;
if ( V_66 ) {
F_19 ( L_8 ) ;
goto V_75;
}
return 1 ;
V_75:
F_30 ( V_2 ) ;
F_34 ( V_73 ) ;
return V_66 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
F_34 ( V_73 ) ;
}
static struct V_48 * F_36 ( struct V_1 * V_2 ,
struct V_76 * V_26 , unsigned long V_77 )
{
struct V_23 * V_24 = F_37 ( V_26 , struct V_23 , V_26 ) ;
struct V_48 * V_49 = NULL ;
int V_78 = V_77 & V_79 ;
F_38 ( & V_26 -> V_19 ) ;
if ( F_39 ( & V_24 -> V_30 ) ) {
F_40 ( L_9 ,
V_24 -> V_26 . V_34 ) ;
goto V_80;
}
if ( ! V_78 && V_24 -> V_26 . V_38 < V_24 -> V_33 )
goto V_80;
V_49 = F_41 ( & V_24 -> V_30 , struct V_48 , V_21 ) ;
F_20 ( & V_49 -> V_21 , & V_24 -> V_31 ) ;
V_49 -> V_60 = V_61 ;
V_24 -> V_26 . V_38 -- ;
V_24 -> V_26 . V_40 ++ ;
V_80:
return V_49 ;
}
static struct V_48 * F_42 ( struct V_1 * V_2 ,
struct V_76 * V_26 , unsigned long V_77 )
{
struct V_48 * V_49 ;
F_3 ( & V_26 -> V_19 ) ;
V_49 = F_36 ( V_2 , V_26 , V_77 ) ;
F_5 ( & V_26 -> V_19 ) ;
return V_49 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_76 * V_26 = V_49 -> V_24 ;
struct V_23 * V_24 = F_37 ( V_26 , struct V_23 , V_26 ) ;
F_38 ( & V_26 -> V_19 ) ;
if ( V_49 -> V_60 & V_61 ) {
F_20 ( & V_49 -> V_21 , & V_24 -> V_30 ) ;
V_24 -> V_26 . V_40 -- ;
V_24 -> V_26 . V_38 ++ ;
V_49 -> V_60 = V_81 ;
} else if ( V_49 -> V_60 & V_82 ) {
F_20 ( & V_49 -> V_21 , & V_24 -> V_30 ) ;
V_24 -> V_26 . V_41 -- ;
V_24 -> V_26 . V_38 ++ ;
V_49 -> V_60 = V_81 ;
} else if ( V_49 -> V_60 & V_83 ) {
F_20 ( & V_49 -> V_21 , & V_24 -> V_32 ) ;
V_24 -> V_26 . V_42 ++ ;
V_49 -> V_60 = V_83 ;
} else {
F_44 ( 1 ) ;
F_19 ( L_10 ,
V_49 -> V_34 , V_49 -> V_60 ) ;
F_20 ( & V_49 -> V_21 , & V_24 -> V_32 ) ;
V_24 -> V_26 . V_42 ++ ;
V_49 -> V_60 = V_83 ;
}
}
static void F_45 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_76 * V_26 = V_49 -> V_24 ;
F_3 ( & V_26 -> V_19 ) ;
F_43 ( V_2 , V_49 ) ;
F_5 ( & V_26 -> V_19 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int type )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 ;
struct V_48 * V_49 ;
if ( F_22 ( V_44 -> V_50 . V_51 > V_2 -> V_84 ||
V_44 -> V_50 . V_24 > V_2 -> V_36 ||
V_44 -> V_50 . V_49 > V_2 -> V_39 ) ) {
F_44 ( 1 ) ;
F_19 ( L_11 ,
V_44 -> V_50 . V_51 , V_2 -> V_84 ,
V_44 -> V_50 . V_24 , V_2 -> V_36 ,
V_44 -> V_50 . V_49 , V_2 -> V_39 ) ;
return;
}
V_24 = & V_6 -> V_28 [ V_44 -> V_50 . V_24 * V_44 -> V_50 . V_51 ] ;
V_49 = & V_24 -> V_26 . V_27 [ V_44 -> V_50 . V_49 ] ;
V_49 -> V_60 = type ;
}
static void F_47 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
int V_25 ;
if ( ! V_2 -> V_67 -> V_87 )
return;
if ( V_2 -> V_67 -> V_87 ( V_2 , V_86 , 1 ) )
return;
F_48 ( V_2 , V_86 ) ;
if ( V_86 -> V_88 > 1 )
for ( V_25 = 0 ; V_25 < V_86 -> V_88 ; V_25 ++ )
F_46 ( V_2 , & V_86 -> V_89 [ V_25 ] ,
V_83 ) ;
else
F_46 ( V_2 , & V_86 -> V_43 , V_83 ) ;
}
static void F_49 ( struct V_85 * V_86 )
{
struct V_90 * V_91 = V_86 -> V_91 ;
switch ( V_86 -> error ) {
case V_92 :
case V_93 :
break;
case V_94 :
F_47 ( V_86 -> V_2 , V_86 ) ;
}
V_91 -> V_95 -> V_96 ( V_86 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
if ( ! V_2 -> V_67 -> V_97 )
return - V_74 ;
F_51 ( V_2 , V_86 ) ;
V_86 -> V_2 = V_2 ;
V_86 -> V_96 = F_49 ;
return V_2 -> V_67 -> V_97 ( V_2 , V_86 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_48 * V_49 ,
unsigned long V_77 )
{
struct V_43 V_98 = F_53 ( V_2 , V_49 ) ;
return F_54 ( V_2 , & V_98 , 1 ) ;
}
static int F_55 ( struct V_1 * V_2 , int V_99 )
{
return F_56 ( V_99 , V_2 -> V_100 ) ;
}
static void F_57 ( struct V_1 * V_2 , int V_99 )
{
F_58 ( ! F_59 ( V_99 , V_2 -> V_100 ) ) ;
}
static struct V_76 * F_60 ( struct V_1 * V_2 , int V_99 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_22 ( V_99 >= V_2 -> V_29 ) )
return NULL ;
return & V_6 -> V_28 [ V_99 ] . V_26 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 ;
unsigned int V_25 ;
F_11 (gn, lun, i) {
F_3 ( & V_24 -> V_26 . V_19 ) ;
F_62 ( L_12 ,
V_2 -> V_101 , V_25 ,
V_24 -> V_26 . V_38 ,
V_24 -> V_26 . V_40 ,
V_24 -> V_26 . V_41 ,
V_24 -> V_26 . V_42 ) ;
F_5 ( & V_24 -> V_26 . V_19 ) ;
}
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_102 ) ;
}
static void F_65 ( void )
{
F_66 ( & V_102 ) ;
}
