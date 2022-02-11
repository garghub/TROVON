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
}
return 0 ;
}
static int F_10 ( struct V_28 V_29 , int V_30 , T_1 * V_31 ,
void * V_32 )
{
struct V_3 * V_4 = V_32 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
int V_8 ;
V_7 = & V_4 -> V_11 [ ( V_2 -> V_22 * V_29 . V_35 . V_36 ) + V_29 . V_35 . V_7 ] ;
for ( V_8 = 0 ; V_8 < V_30 ; V_8 ++ ) {
if ( V_31 [ V_8 ] == 0 )
continue;
V_34 = & V_7 -> V_9 . V_10 [ V_8 ] ;
if ( ! V_34 ) {
F_11 ( L_1 ) ;
return - V_37 ;
}
F_12 ( & V_34 -> V_38 , & V_7 -> V_18 ) ;
V_7 -> V_9 . V_27 ++ ;
}
return 0 ;
}
static int F_13 ( T_2 V_39 , T_3 V_40 , T_4 * V_41 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_42 = V_2 -> V_43 * ( V_2 -> V_44 >> 9 ) ;
T_2 V_45 = V_39 + V_40 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
T_2 V_8 ;
int V_21 ;
if ( F_14 ( V_45 > V_2 -> V_43 ) ) {
F_11 ( L_2 ) ;
return - V_37 ;
}
for ( V_8 = 0 ; V_8 < V_40 ; V_8 ++ ) {
T_2 V_46 = F_15 ( V_41 [ V_8 ] ) ;
if ( F_14 ( V_46 >= V_42 && V_46 != V_47 ) ) {
F_11 ( L_3 ) ;
return - V_37 ;
}
if ( ! V_46 )
continue;
V_21 = F_16 ( V_46 , V_2 -> V_48 ) ;
V_7 = & V_4 -> V_11 [ V_21 ] ;
V_46 = V_46 - ( V_2 -> V_48 * V_21 ) ;
V_34 = & V_7 -> V_9 . V_10 [ F_16 ( V_46 , V_2 -> V_49 ) ] ;
if ( ! V_34 -> type ) {
F_12 ( & V_34 -> V_38 , & V_7 -> V_17 ) ;
V_34 -> type = 1 ;
V_7 -> V_9 . V_24 -- ;
V_7 -> V_9 . V_26 ++ ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_33 * V_50 ;
T_5 V_51 , V_52 , V_53 = 0 ;
int V_54 ;
F_2 (gn, lun, lun_iter) {
V_7 -> V_9 . V_10 = F_18 ( sizeof( struct V_33 ) *
V_2 -> V_25 ) ;
if ( ! V_7 -> V_9 . V_10 )
return - V_14 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_25 ; V_52 ++ ) {
V_50 = & V_7 -> V_9 . V_10 [ V_52 ] ;
F_9 ( & V_50 -> V_38 ) ;
V_50 -> V_7 = & V_7 -> V_9 ;
V_50 -> V_20 = V_53 ++ ;
if ( F_14 ( V_51 == 0 && V_52 == 0 ) ) {
V_7 -> V_9 . V_24 -- ;
continue;
}
F_19 ( & V_50 -> V_38 , & V_7 -> V_16 ) ;
}
if ( V_2 -> V_55 -> V_56 ) {
struct V_28 V_29 ;
V_29 . V_29 = 0 ;
V_29 . V_35 . V_36 = V_7 -> V_9 . V_23 ;
V_29 . V_35 . V_7 = V_7 -> V_9 . V_20 ;
V_29 = F_20 ( V_2 , V_29 ) ;
V_54 = V_2 -> V_55 -> V_56 ( V_2 , V_29 ,
V_2 -> V_25 ,
F_10 , V_4 ) ;
if ( V_54 )
F_11 ( L_4 ) ;
}
}
if ( V_2 -> V_55 -> V_57 ) {
V_54 = V_2 -> V_55 -> V_57 ( V_2 , 0 , V_2 -> V_43 ,
F_13 , V_2 ) ;
if ( V_54 ) {
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
int V_54 ;
if ( ! F_24 ( V_58 ) )
return - V_59 ;
V_4 = F_25 ( sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_2 -> V_12 ;
V_2 -> V_5 = V_4 ;
V_54 = F_6 ( V_2 , V_4 ) ;
if ( V_54 ) {
F_11 ( L_7 ) ;
goto V_60;
}
V_54 = F_17 ( V_2 , V_4 ) ;
if ( V_54 ) {
F_11 ( L_8 ) ;
goto V_60;
}
return 1 ;
V_60:
F_22 ( V_2 ) ;
F_26 ( V_58 ) ;
return V_54 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_26 ( V_58 ) ;
}
static struct V_33 * F_28 ( struct V_1 * V_2 ,
struct V_61 * V_9 , unsigned long V_62 )
{
struct V_6 * V_7 = F_29 ( V_9 , struct V_6 , V_9 ) ;
struct V_33 * V_34 = NULL ;
int V_63 = V_62 & V_64 ;
F_30 ( & V_9 -> V_15 ) ;
if ( F_31 ( & V_7 -> V_16 ) ) {
F_32 ( L_9 ,
V_7 -> V_9 . V_20 ) ;
goto V_65;
}
if ( ! V_63 && V_7 -> V_9 . V_24 < V_7 -> V_19 )
goto V_65;
V_34 = F_33 ( & V_7 -> V_16 , struct V_33 , V_38 ) ;
F_12 ( & V_34 -> V_38 , & V_7 -> V_17 ) ;
V_34 -> type = 1 ;
V_7 -> V_9 . V_24 -- ;
V_7 -> V_9 . V_26 ++ ;
V_65:
F_34 ( & V_9 -> V_15 ) ;
return V_34 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_61 * V_9 = V_34 -> V_7 ;
struct V_6 * V_7 = F_29 ( V_9 , struct V_6 , V_9 ) ;
F_30 ( & V_9 -> V_15 ) ;
switch ( V_34 -> type ) {
case 1 :
F_12 ( & V_34 -> V_38 , & V_7 -> V_16 ) ;
V_7 -> V_9 . V_24 ++ ;
V_7 -> V_9 . V_26 -- ;
V_34 -> type = 0 ;
break;
case 2 :
F_12 ( & V_34 -> V_38 , & V_7 -> V_18 ) ;
V_7 -> V_9 . V_27 ++ ;
V_7 -> V_9 . V_26 -- ;
break;
default:
F_36 ( 1 ) ;
F_11 ( L_10 ,
V_34 -> V_20 , V_34 -> type ) ;
F_12 ( & V_34 -> V_38 , & V_7 -> V_18 ) ;
V_7 -> V_9 . V_27 ++ ;
V_7 -> V_9 . V_26 -- ;
}
F_34 ( & V_9 -> V_15 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_8 ;
if ( V_67 -> V_68 > 1 ) {
for ( V_8 = 0 ; V_8 < V_67 -> V_68 ; V_8 ++ )
V_67 -> V_69 [ V_8 ] = F_38 ( V_2 ,
V_67 -> V_69 [ V_8 ] ) ;
} else {
V_67 -> V_28 = F_38 ( V_2 , V_67 -> V_28 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_8 ;
if ( V_67 -> V_68 > 1 ) {
for ( V_8 = 0 ; V_8 < V_67 -> V_68 ; V_8 ++ )
V_67 -> V_69 [ V_8 ] = F_20 ( V_2 ,
V_67 -> V_69 [ V_8 ] ) ;
} else {
V_67 -> V_28 = F_20 ( V_2 , V_67 -> V_28 ) ;
}
}
static int F_40 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
if ( ! V_2 -> V_55 -> V_70 )
return 0 ;
F_39 ( V_2 , V_67 ) ;
V_67 -> V_2 = V_2 ;
return V_2 -> V_55 -> V_70 ( V_2 , V_67 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_28 * V_29 ,
int type )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
if ( F_14 ( V_29 -> V_35 . V_36 > V_2 -> V_71 ||
V_29 -> V_35 . V_7 > V_2 -> V_22 ||
V_29 -> V_35 . V_34 > V_2 -> V_25 ) ) {
F_36 ( 1 ) ;
F_11 ( L_11 ,
V_29 -> V_35 . V_36 , V_2 -> V_71 ,
V_29 -> V_35 . V_7 , V_2 -> V_22 ,
V_29 -> V_35 . V_34 , V_2 -> V_25 ) ;
return;
}
V_7 = & V_4 -> V_11 [ V_29 -> V_35 . V_7 * V_29 -> V_35 . V_36 ] ;
V_34 = & V_7 -> V_9 . V_10 [ V_29 -> V_35 . V_34 ] ;
V_34 -> type = type ;
}
static void F_42 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_8 ;
if ( ! V_2 -> V_55 -> V_72 )
return;
if ( V_2 -> V_55 -> V_72 ( V_2 , V_67 , 1 ) )
return;
F_37 ( V_2 , V_67 ) ;
if ( V_67 -> V_68 > 1 )
for ( V_8 = 0 ; V_8 < V_67 -> V_68 ; V_8 ++ )
F_41 ( V_2 , & V_67 -> V_69 [ V_8 ] , 2 ) ;
else
F_41 ( V_2 , & V_67 -> V_28 , 2 ) ;
}
static int F_43 ( struct V_66 * V_67 , int error )
{
struct V_73 * V_74 = V_67 -> V_74 ;
int V_54 = 0 ;
switch ( error ) {
case V_75 :
break;
case V_76 :
break;
case V_77 :
F_42 ( V_67 -> V_2 , V_67 ) ;
default:
V_54 ++ ;
}
V_54 += V_74 -> V_78 -> V_79 ( V_67 , error ) ;
return V_54 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_33 * V_34 ,
unsigned long V_62 )
{
int V_80 = 0 , V_81 , V_54 ;
struct V_28 V_82 ;
struct V_66 V_67 ;
if ( ! V_2 -> V_55 -> V_83 )
return 0 ;
V_82 = F_45 ( V_2 , V_34 ) ;
if ( V_2 -> V_84 == V_85 ) {
V_67 . V_68 = 1 ;
V_67 . V_28 = V_82 ;
} else {
V_80 = ( 1 << V_2 -> V_84 ) ;
V_67 . V_68 = V_80 ;
V_67 . V_69 = F_46 ( V_2 , V_13 ,
& V_67 . V_86 ) ;
if ( ! V_67 . V_69 ) {
F_11 ( L_12 ) ;
return - V_14 ;
}
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
V_82 . V_35 . V_87 = V_81 ;
V_67 . V_69 [ V_81 ] = V_82 ;
}
}
F_39 ( V_2 , & V_67 ) ;
V_54 = V_2 -> V_55 -> V_83 ( V_2 , & V_67 ) ;
if ( V_80 )
F_47 ( V_2 , V_67 . V_69 , V_67 . V_86 ) ;
return V_54 ;
}
static struct V_61 * F_48 ( struct V_1 * V_2 , int V_88 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return & V_4 -> V_11 [ V_88 ] . V_9 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
F_2 (gn, lun, i) {
F_30 ( & V_7 -> V_9 . V_15 ) ;
F_50 ( L_13 ,
V_2 -> V_89 , V_8 ,
V_7 -> V_9 . V_24 ,
V_7 -> V_9 . V_26 ,
V_7 -> V_9 . V_27 ) ;
F_34 ( & V_7 -> V_9 . V_15 ) ;
}
}
static int T_6 F_51 ( void )
{
return F_52 ( & V_90 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_90 ) ;
}
