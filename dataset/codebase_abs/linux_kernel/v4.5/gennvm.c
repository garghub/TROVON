static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
F_2 (gn, lun, i) {
if ( ! V_7 -> V_9 . V_10 )
break;
F_3 ( V_7 -> V_9 . V_10 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_8 ;
V_4 -> V_11 = F_7 ( V_2 -> V_12 , sizeof( struct V_6 ) , V_13 ) ;
if ( ! V_4 -> V_11 )
return - V_14 ;
F_2 (gn, lun, i) {
F_8 ( & V_7 -> V_9 . V_15 ) ;
F_9 ( & V_7 -> V_16 ) ;
F_9 ( & V_7 -> V_17 ) ;
F_9 ( & V_7 -> V_18 ) ;
V_7 -> V_19 = 2 ;
V_7 -> V_9 . V_20 = V_8 ;
V_7 -> V_9 . V_21 = V_8 % V_2 -> V_22 ;
V_7 -> V_9 . V_23 = V_8 / V_2 -> V_22 ;
V_7 -> V_9 . V_24 = V_2 -> V_25 ;
V_7 -> V_9 . V_26 = 0 ;
V_7 -> V_9 . V_27 = 0 ;
V_7 -> V_9 . V_28 = 0 ;
}
return 0 ;
}
static int F_10 ( struct V_29 V_30 , int V_31 , T_1 * V_32 ,
void * V_33 )
{
struct V_3 * V_4 = V_33 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
int V_8 ;
V_7 = & V_4 -> V_11 [ ( V_2 -> V_22 * V_30 . V_36 . V_37 ) + V_30 . V_36 . V_7 ] ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
if ( V_32 [ V_8 ] == 0 )
continue;
V_35 = & V_7 -> V_9 . V_10 [ V_8 ] ;
if ( ! V_35 ) {
F_11 ( L_1 ) ;
return - V_38 ;
}
F_12 ( & V_35 -> V_39 , & V_7 -> V_18 ) ;
V_7 -> V_9 . V_28 ++ ;
V_7 -> V_9 . V_24 -- ;
}
return 0 ;
}
static int F_13 ( T_2 V_40 , T_3 V_41 , T_4 * V_42 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_43 = V_2 -> V_44 * ( V_2 -> V_45 >> 9 ) ;
T_2 V_46 = V_40 + V_41 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
T_2 V_8 ;
int V_21 ;
if ( F_14 ( V_46 > V_2 -> V_44 ) ) {
F_11 ( L_2 ) ;
return - V_38 ;
}
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ ) {
T_2 V_47 = F_15 ( V_42 [ V_8 ] ) ;
if ( F_14 ( V_47 >= V_43 && V_47 != V_48 ) ) {
F_11 ( L_3 ) ;
return - V_38 ;
}
if ( ! V_47 )
continue;
V_21 = F_16 ( V_47 , V_2 -> V_49 ) ;
V_7 = & V_4 -> V_11 [ V_21 ] ;
V_47 = V_47 - ( V_2 -> V_49 * V_21 ) ;
V_35 = & V_7 -> V_9 . V_10 [ F_16 ( V_47 , V_2 -> V_50 ) ] ;
if ( ! V_35 -> V_51 ) {
F_12 ( & V_35 -> V_39 , & V_7 -> V_17 ) ;
V_35 -> V_51 = V_52 ;
V_7 -> V_9 . V_24 -- ;
V_7 -> V_9 . V_26 ++ ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_34 * V_53 ;
T_5 V_54 , V_55 , V_56 = 0 ;
int V_57 ;
F_2 (gn, lun, lun_iter) {
V_7 -> V_9 . V_10 = F_18 ( sizeof( struct V_34 ) *
V_2 -> V_25 ) ;
if ( ! V_7 -> V_9 . V_10 )
return - V_14 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_25 ; V_55 ++ ) {
V_53 = & V_7 -> V_9 . V_10 [ V_55 ] ;
F_9 ( & V_53 -> V_39 ) ;
V_53 -> V_7 = & V_7 -> V_9 ;
V_53 -> V_20 = V_56 ++ ;
if ( F_14 ( V_54 == 0 && V_55 == 0 ) ) {
V_7 -> V_9 . V_24 -- ;
continue;
}
F_19 ( & V_53 -> V_39 , & V_7 -> V_16 ) ;
}
if ( V_2 -> V_58 -> V_59 ) {
struct V_29 V_30 ;
V_30 . V_30 = 0 ;
V_30 . V_36 . V_37 = V_7 -> V_9 . V_23 ;
V_30 . V_36 . V_7 = V_7 -> V_9 . V_20 ;
V_30 = F_20 ( V_2 , V_30 ) ;
V_57 = V_2 -> V_58 -> V_59 ( V_2 , V_30 ,
V_2 -> V_25 ,
F_10 , V_4 ) ;
if ( V_57 )
F_11 ( L_4 ) ;
}
}
if ( V_2 -> V_58 -> V_60 ) {
V_57 = V_2 -> V_58 -> V_60 ( V_2 , 0 , V_2 -> V_44 ,
F_13 , V_2 ) ;
if ( V_57 ) {
F_11 ( L_5 ) ;
F_21 ( L_6 ) ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_57 ;
if ( ! F_24 ( V_61 ) )
return - V_62 ;
V_4 = F_25 ( sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_2 -> V_12 ;
V_2 -> V_5 = V_4 ;
V_57 = F_6 ( V_2 , V_4 ) ;
if ( V_57 ) {
F_11 ( L_7 ) ;
goto V_63;
}
V_57 = F_17 ( V_2 , V_4 ) ;
if ( V_57 ) {
F_11 ( L_8 ) ;
goto V_63;
}
return 1 ;
V_63:
F_22 ( V_2 ) ;
F_26 ( V_61 ) ;
return V_57 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_26 ( V_61 ) ;
}
static struct V_34 * F_28 ( struct V_1 * V_2 ,
struct V_64 * V_9 , unsigned long V_65 )
{
struct V_6 * V_7 = F_29 ( V_9 , struct V_6 , V_9 ) ;
struct V_34 * V_35 = NULL ;
int V_66 = V_65 & V_67 ;
F_30 ( & V_9 -> V_15 ) ;
if ( F_31 ( & V_7 -> V_16 ) ) {
F_32 ( L_9 ,
V_7 -> V_9 . V_20 ) ;
goto V_68;
}
if ( ! V_66 && V_7 -> V_9 . V_24 < V_7 -> V_19 )
goto V_68;
V_35 = F_33 ( & V_7 -> V_16 , struct V_34 , V_39 ) ;
F_12 ( & V_35 -> V_39 , & V_7 -> V_17 ) ;
V_35 -> V_51 = V_52 ;
V_7 -> V_9 . V_24 -- ;
V_7 -> V_9 . V_26 ++ ;
V_68:
return V_35 ;
}
static struct V_34 * F_34 ( struct V_1 * V_2 ,
struct V_64 * V_9 , unsigned long V_65 )
{
struct V_34 * V_35 ;
F_35 ( & V_9 -> V_15 ) ;
V_35 = F_28 ( V_2 , V_9 , V_65 ) ;
F_36 ( & V_9 -> V_15 ) ;
return V_35 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_64 * V_9 = V_35 -> V_7 ;
struct V_6 * V_7 = F_29 ( V_9 , struct V_6 , V_9 ) ;
F_30 ( & V_9 -> V_15 ) ;
if ( V_35 -> V_51 & V_52 ) {
F_12 ( & V_35 -> V_39 , & V_7 -> V_16 ) ;
V_7 -> V_9 . V_26 -- ;
V_7 -> V_9 . V_24 ++ ;
V_35 -> V_51 = V_69 ;
} else if ( V_35 -> V_51 & V_70 ) {
F_12 ( & V_35 -> V_39 , & V_7 -> V_16 ) ;
V_7 -> V_9 . V_27 -- ;
V_7 -> V_9 . V_24 ++ ;
V_35 -> V_51 = V_69 ;
} else if ( V_35 -> V_51 & V_71 ) {
F_12 ( & V_35 -> V_39 , & V_7 -> V_18 ) ;
V_7 -> V_9 . V_28 ++ ;
V_35 -> V_51 = V_71 ;
} else {
F_38 ( 1 ) ;
F_11 ( L_10 ,
V_35 -> V_20 , V_35 -> V_51 ) ;
F_12 ( & V_35 -> V_39 , & V_7 -> V_18 ) ;
V_7 -> V_9 . V_28 ++ ;
V_35 -> V_51 = V_71 ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_64 * V_9 = V_35 -> V_7 ;
F_35 ( & V_9 -> V_15 ) ;
F_37 ( V_2 , V_35 ) ;
F_36 ( & V_9 -> V_15 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_29 * V_30 ,
int type )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
if ( F_14 ( V_30 -> V_36 . V_37 > V_2 -> V_72 ||
V_30 -> V_36 . V_7 > V_2 -> V_22 ||
V_30 -> V_36 . V_35 > V_2 -> V_25 ) ) {
F_38 ( 1 ) ;
F_11 ( L_11 ,
V_30 -> V_36 . V_37 , V_2 -> V_72 ,
V_30 -> V_36 . V_7 , V_2 -> V_22 ,
V_30 -> V_36 . V_35 , V_2 -> V_25 ) ;
return;
}
V_7 = & V_4 -> V_11 [ V_30 -> V_36 . V_7 * V_30 -> V_36 . V_37 ] ;
V_35 = & V_7 -> V_9 . V_10 [ V_30 -> V_36 . V_35 ] ;
V_35 -> V_51 = type ;
}
static void F_41 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
int V_8 ;
if ( ! V_2 -> V_58 -> V_75 )
return;
if ( V_2 -> V_58 -> V_75 ( V_2 , V_74 , 1 ) )
return;
F_42 ( V_2 , V_74 ) ;
if ( V_74 -> V_76 > 1 )
for ( V_8 = 0 ; V_8 < V_74 -> V_76 ; V_8 ++ )
F_40 ( V_2 , & V_74 -> V_77 [ V_8 ] ,
V_71 ) ;
else
F_40 ( V_2 , & V_74 -> V_29 , V_71 ) ;
}
static void F_43 ( struct V_73 * V_74 )
{
struct V_78 * V_79 = V_74 -> V_79 ;
switch ( V_74 -> error ) {
case V_80 :
case V_81 :
break;
case V_82 :
F_41 ( V_74 -> V_2 , V_74 ) ;
}
V_79 -> V_83 -> V_84 ( V_74 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
if ( ! V_2 -> V_58 -> V_85 )
return - V_62 ;
F_45 ( V_2 , V_74 ) ;
V_74 -> V_2 = V_2 ;
V_74 -> V_84 = F_43 ;
return V_2 -> V_58 -> V_85 ( V_2 , V_74 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_34 * V_35 ,
unsigned long V_65 )
{
struct V_29 V_86 = F_47 ( V_2 , V_35 ) ;
return F_48 ( V_2 , & V_86 , 1 ) ;
}
static struct V_64 * F_49 ( struct V_1 * V_2 , int V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return & V_4 -> V_11 [ V_87 ] . V_9 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
F_2 (gn, lun, i) {
F_35 ( & V_7 -> V_9 . V_15 ) ;
F_51 ( L_12 ,
V_2 -> V_88 , V_8 ,
V_7 -> V_9 . V_24 ,
V_7 -> V_9 . V_26 ,
V_7 -> V_9 . V_27 ,
V_7 -> V_9 . V_28 ) ;
F_36 ( & V_7 -> V_9 . V_15 ) ;
}
}
static int T_6 F_52 ( void )
{
return F_53 ( & V_89 ) ;
}
static void F_54 ( void )
{
F_55 ( & V_89 ) ;
}
