static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 , V_6 , V_7 [ 3 ] ;
unsigned long V_8 ;
int V_9 ;
V_5 = F_2 ( V_2 -> V_10 , V_2 -> V_11 , 0 ) ;
V_8 = V_2 -> V_12 -> V_8 ;
V_6 = 1 ;
do {
if ( V_3 == V_13 || V_3 == V_14 ||
V_3 == V_15 )
V_9 = F_3 ( V_16 , 6 , 4 , V_7 , V_5 ,
F_4 ( V_8 ) , F_5 ( V_8 ) ,
V_3 , V_4 , V_6 ) ;
else
V_9 = F_3 ( V_16 , 6 , 3 , V_7 , V_5 ,
F_4 ( V_8 ) , F_5 ( V_8 ) ,
V_3 , V_4 , V_6 ) ;
V_6 = V_7 [ 1 ] ;
} while ( F_6 ( V_9 ) );
if ( V_9 == 0 )
V_9 = V_7 [ 0 ] ;
else if ( V_9 > 0 )
V_9 = - V_9 ;
F_7 ( L_1 ,
V_3 , V_4 , V_7 [ 0 ] , V_9 ) ;
return V_9 ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_18 ) ;
if ( ! V_2 )
return;
if ( F_1 ( V_2 , V_13 , 0 ) != 0 ) {
if ( F_1 ( V_2 , V_19 , 0 ) != 0 ) {
F_7 ( L_2 ) ;
}
}
}
static int F_10 ( struct V_1 * V_2 , int V_20 )
{
T_1 V_5 , V_7 [ 2 ] ;
unsigned long V_8 ;
int V_9 ;
V_5 = F_2 ( V_2 -> V_10 , V_2 -> V_11 , 0 ) ;
V_8 = V_2 -> V_12 -> V_8 ;
do {
V_9 = F_3 ( V_21 , 4 , 3 , V_7 , V_5 ,
F_4 ( V_8 ) , F_5 ( V_8 ) , V_20 ) ;
} while ( F_6 ( V_9 ) );
if ( V_9 ) {
F_7 ( L_3 , V_9 ) ;
return V_9 ;
}
return V_7 [ 0 ] ;
}
static void F_11 ( struct V_17 * V_18 )
{
struct V_22 * V_23 ;
F_12 (entry, &pdev->msi_list, list) {
if ( V_23 -> V_24 == V_25 )
continue;
F_13 ( V_23 -> V_24 , NULL ) ;
F_14 ( V_23 -> V_24 ) ;
}
F_8 ( V_18 ) ;
}
static int F_15 ( struct V_17 * V_18 , int V_26 , char * V_27 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
const T_2 * V_30 ;
T_1 V_31 ;
V_2 = F_9 ( V_18 ) ;
if ( ! V_2 )
return - V_32 ;
V_29 = V_2 -> V_33 ;
V_30 = F_16 ( V_29 , V_27 , NULL ) ;
if ( ! V_30 ) {
F_7 ( L_4 , V_27 , V_29 -> V_34 ) ;
return - V_35 ;
}
V_31 = F_17 ( V_30 ) ;
if ( V_31 < V_26 ) {
F_7 ( L_5 , V_27 , V_26 ) ;
if ( V_31 == 0 )
return - V_36 ;
return V_31 ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , int V_26 )
{
return F_15 ( V_18 , V_26 , L_6 ) ;
}
static int F_19 ( struct V_17 * V_18 , int V_26 )
{
return F_15 ( V_18 , V_26 , L_7 ) ;
}
static struct V_28 * F_20 ( struct V_17 * V_37 , int * V_38 )
{
struct V_28 * V_29 ;
const T_2 * V_30 ;
V_29 = F_21 ( F_22 ( V_37 ) ) ;
while ( V_29 ) {
V_30 = F_16 ( V_29 , L_8 , NULL ) ;
if ( V_30 ) {
F_7 ( L_9 ,
V_29 -> V_34 ) ;
* V_38 = F_17 ( V_30 ) ;
return V_29 ;
}
V_29 = F_23 ( V_29 ) ;
}
return NULL ;
}
static struct V_28 * F_24 ( struct V_17 * V_37 , int * V_38 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
V_29 = F_22 ( V_37 ) ;
if ( ! V_29 )
return NULL ;
V_40 = F_25 ( F_26 ( V_29 ) ) ;
if ( V_40 -> V_41 )
V_40 = F_27 ( & V_40 -> V_41 -> V_42 , struct V_39 , V_43 ) ;
V_2 = F_28 ( V_40 ) ;
V_29 = V_2 ? V_2 -> V_33 : NULL ;
if ( ! V_29 )
return NULL ;
V_29 = F_29 ( V_29 ) ;
if ( ! V_29 )
return NULL ;
* V_38 = 8 ;
F_7 ( L_10 , V_29 -> V_34 ) ;
return V_29 ;
}
static void * F_30 ( struct V_28 * V_29 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
const T_2 * V_30 ;
T_1 V_47 ;
F_7 ( L_11 , V_29 -> V_34 ) ;
V_30 = F_16 ( V_29 , L_12 , NULL ) ;
V_47 = V_30 ? F_17 ( V_30 ) : 0 ;
if ( ( V_47 >> 8 ) != V_48 )
V_46 -> V_49 ++ ;
return NULL ;
}
static void * F_31 ( struct V_28 * V_29 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
const T_2 * V_30 ;
int V_50 ;
if ( V_29 == V_46 -> V_51 )
V_50 = V_46 -> V_52 ;
else {
V_50 = 0 ;
V_30 = F_16 ( V_29 , L_6 , NULL ) ;
if ( V_30 )
V_50 = F_17 ( V_30 ) ;
V_30 = F_16 ( V_29 , L_7 , NULL ) ;
if ( V_30 )
V_50 = F_32 ( V_50 , ( int ) F_17 ( V_30 ) ) ;
}
if ( V_50 < V_46 -> V_53 )
V_46 -> V_54 += V_46 -> V_53 - V_50 ;
else if ( V_50 > V_46 -> V_53 )
V_46 -> V_55 ++ ;
return NULL ;
}
static int F_33 ( struct V_17 * V_37 , int V_52 )
{
struct V_28 * V_56 ;
struct V_45 V_46 ;
int V_38 ;
F_7 ( L_13 , F_34 ( V_37 ) ,
V_52 ) ;
V_56 = F_20 ( V_37 , & V_38 ) ;
if ( ! V_56 )
V_56 = F_24 ( V_37 , & V_38 ) ;
if ( ! V_56 ) {
F_35 ( L_14 , F_34 ( V_37 ) ) ;
goto V_57;
}
F_7 ( L_15 , V_56 -> V_34 ) ;
memset ( & V_46 , 0 , sizeof( struct V_45 ) ) ;
F_36 ( V_56 , F_30 , & V_46 ) ;
if ( V_46 . V_49 == 0 ) {
F_35 ( L_16 ,
F_34 ( V_37 ) ) ;
goto V_57;
}
V_46 . V_53 = V_38 / V_46 . V_49 ;
if ( V_52 <= V_46 . V_53 )
goto V_57;
V_46 . V_51 = F_22 ( V_37 ) ;
V_46 . V_52 = V_52 ;
F_36 ( V_56 , F_31 , & V_46 ) ;
V_46 . V_54 += V_38 % V_46 . V_49 ;
if ( V_46 . V_55 )
V_46 . V_53 += V_46 . V_54 / V_46 . V_55 ;
V_52 = F_37 ( V_46 . V_53 , V_52 ) ;
F_7 ( L_17 , V_52 ) ;
V_57:
F_38 ( V_56 ) ;
return V_52 ;
}
static int F_39 ( struct V_17 * V_18 )
{
struct V_22 * V_23 ;
int V_58 ;
V_58 = 0 ;
F_12 (entry, &pdev->msi_list, list) {
if ( V_23 -> V_59 . V_60 != V_58 ) {
F_7 ( L_18 ) ;
return - V_61 ;
}
V_58 ++ ;
}
return 0 ;
}
static void F_40 ( struct V_17 * V_18 )
{
T_1 V_62 , V_63 ;
F_41 ( & V_18 -> V_37 ,
L_19 ) ;
F_42 ( V_18 , V_18 -> V_64 + V_65 , & V_62 ) ;
V_63 = 0xffff0000 | ( ( V_62 >> ( 48 - 32 ) ) << 4 ) ;
F_43 ( V_18 , V_18 -> V_64 + V_66 , V_63 ) ;
F_43 ( V_18 , V_18 -> V_64 + V_65 , 0 ) ;
}
static int F_44 ( struct V_17 * V_18 , int V_67 , int type )
{
struct V_1 * V_2 ;
int V_68 , V_69 , V_70 , V_53 , V_9 ;
struct V_22 * V_23 ;
struct V_71 V_72 ;
int V_26 = V_67 ;
int V_73 = 0 ;
if ( type == V_74 )
V_9 = F_19 ( V_18 , V_26 ) ;
else
V_9 = F_18 ( V_18 , V_26 ) ;
if ( V_9 )
return V_9 ;
V_53 = F_33 ( V_18 , V_26 ) ;
if ( V_53 && V_53 < V_26 )
return V_53 ;
if ( type == V_74 && F_39 ( V_18 ) )
return - V_61 ;
if ( type == V_74 ) {
int V_75 = F_45 ( V_26 ) ;
V_53 = F_33 ( V_18 , V_75 ) ;
if ( V_53 >= V_75 )
V_26 = V_75 ;
}
V_2 = F_9 ( V_18 ) ;
V_76:
if ( type == V_77 ) {
if ( V_18 -> V_78 ) {
V_9 = F_1 ( V_2 , V_15 , V_26 ) ;
if ( V_9 < 0 ) {
if ( V_18 -> V_79 -> V_80 != V_81 )
return V_9 ;
V_73 = 1 ;
}
} else
V_9 = - 1 ;
if ( V_9 < 0 )
V_9 = F_1 ( V_2 , V_13 , V_26 ) ;
if ( V_9 < 0 ) {
F_7 ( L_20 ) ;
V_9 = F_1 ( V_2 , V_19 , V_26 ) ;
}
if ( V_73 && V_9 > 0 )
F_40 ( V_18 ) ;
} else
V_9 = F_1 ( V_2 , V_14 , V_26 ) ;
if ( V_9 != V_26 ) {
if ( V_26 != V_67 ) {
V_26 = V_67 ;
goto V_76;
}
F_7 ( L_21 ) ;
return V_9 ;
}
V_70 = 0 ;
F_12 (entry, &pdev->msi_list, list) {
V_68 = F_10 ( V_2 , V_70 ++ ) ;
if ( V_68 < 0 ) {
F_7 ( L_22 , V_9 ) ;
return V_68 ;
}
V_69 = F_46 ( NULL , V_68 ) ;
if ( V_69 == V_25 ) {
F_7 ( L_23 , V_68 ) ;
return - V_36 ;
}
F_47 ( & V_18 -> V_37 , L_24 , V_69 ) ;
F_13 ( V_69 , V_23 ) ;
F_48 ( V_23 , & V_72 ) ;
V_23 -> V_72 = V_72 ;
}
return 0 ;
}
static void F_49 ( struct V_17 * V_18 )
{
if ( V_18 -> V_24 == V_25 ) {
F_47 ( & V_18 -> V_37 , L_25 ) ;
return;
}
if ( F_18 ( V_18 , 1 ) && F_19 ( V_18 , 1 ) ) {
F_47 ( & V_18 -> V_37 , L_26 ) ;
return;
}
F_47 ( & V_18 -> V_37 , L_27 ) ;
F_8 ( V_18 ) ;
}
static int F_50 ( void )
{
struct V_82 * V_12 ;
V_21 = F_51 ( L_28 ) ;
V_16 = F_51 ( L_29 ) ;
if ( ( V_21 == V_83 ) ||
( V_16 == V_83 ) ) {
F_7 ( L_30 ) ;
return - 1 ;
}
F_7 ( L_31 ) ;
F_52 ( V_84 . V_85 ) ;
V_84 . V_85 = F_44 ;
V_84 . V_86 = F_11 ;
F_12 (phb, &hose_list, list_node) {
F_52 ( V_12 -> V_87 . V_85 ) ;
V_12 -> V_87 . V_85 = F_44 ;
V_12 -> V_87 . V_86 = F_11 ;
}
F_52 ( V_88 . V_89 ) ;
V_88 . V_89 = F_49 ;
return 0 ;
}
