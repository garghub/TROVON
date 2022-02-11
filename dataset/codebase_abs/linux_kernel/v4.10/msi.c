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
F_12 (entry, pdev) {
if ( ! V_23 -> V_24 )
continue;
F_13 ( V_23 -> V_24 , NULL ) ;
F_14 ( V_23 -> V_24 ) ;
}
F_8 ( V_18 ) ;
}
static int F_15 ( struct V_17 * V_18 , int V_25 , char * V_26 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
const T_2 * V_29 ;
T_1 V_30 ;
V_2 = F_9 ( V_18 ) ;
if ( ! V_2 )
return - V_31 ;
V_28 = V_2 -> V_32 ;
V_29 = F_16 ( V_28 , V_26 , NULL ) ;
if ( ! V_29 ) {
F_7 ( L_4 , V_26 , V_28 -> V_33 ) ;
return - V_34 ;
}
V_30 = F_17 ( V_29 ) ;
if ( V_30 < V_25 ) {
F_7 ( L_5 , V_26 , V_25 ) ;
if ( V_30 == 0 )
return - V_35 ;
return V_30 ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , int V_25 )
{
return F_15 ( V_18 , V_25 , L_6 ) ;
}
static int F_19 ( struct V_17 * V_18 , int V_25 )
{
return F_15 ( V_18 , V_25 , L_7 ) ;
}
static struct V_27 * F_20 ( struct V_17 * V_36 , int * V_37 )
{
struct V_27 * V_28 ;
const T_2 * V_29 ;
V_28 = F_21 ( F_22 ( V_36 ) ) ;
while ( V_28 ) {
V_29 = F_16 ( V_28 , L_8 , NULL ) ;
if ( V_29 ) {
F_7 ( L_9 ,
V_28 -> V_33 ) ;
* V_37 = F_17 ( V_29 ) ;
return V_28 ;
}
V_28 = F_23 ( V_28 ) ;
}
return NULL ;
}
static struct V_27 * F_24 ( struct V_17 * V_36 , int * V_37 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
V_28 = F_22 ( V_36 ) ;
if ( ! V_28 )
return NULL ;
V_39 = F_25 ( F_26 ( V_28 ) ) ;
if ( V_39 -> V_40 )
V_39 = F_27 ( & V_39 -> V_40 -> V_41 , struct V_38 , V_42 ) ;
V_2 = F_28 ( V_39 ) ;
V_28 = V_2 ? V_2 -> V_32 : NULL ;
if ( ! V_28 )
return NULL ;
V_28 = F_29 ( V_28 ) ;
if ( ! V_28 )
return NULL ;
* V_37 = 8 ;
F_7 ( L_10 , V_28 -> V_33 ) ;
return V_28 ;
}
static void * F_30 ( struct V_27 * V_28 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
const T_2 * V_29 ;
T_1 V_46 ;
F_7 ( L_11 , V_28 -> V_33 ) ;
V_29 = F_16 ( V_28 , L_12 , NULL ) ;
V_46 = V_29 ? F_17 ( V_29 ) : 0 ;
if ( ( V_46 >> 8 ) != V_47 )
V_45 -> V_48 ++ ;
return NULL ;
}
static void * F_31 ( struct V_27 * V_28 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
const T_2 * V_29 ;
int V_49 ;
if ( V_28 == V_45 -> V_50 )
V_49 = V_45 -> V_51 ;
else {
V_49 = 0 ;
V_29 = F_16 ( V_28 , L_6 , NULL ) ;
if ( V_29 )
V_49 = F_17 ( V_29 ) ;
V_29 = F_16 ( V_28 , L_7 , NULL ) ;
if ( V_29 )
V_49 = F_32 ( V_49 , ( int ) F_17 ( V_29 ) ) ;
}
if ( V_49 < V_45 -> V_52 )
V_45 -> V_53 += V_45 -> V_52 - V_49 ;
else if ( V_49 > V_45 -> V_52 )
V_45 -> V_54 ++ ;
return NULL ;
}
static int F_33 ( struct V_17 * V_36 , int V_51 )
{
struct V_27 * V_55 ;
struct V_44 V_45 ;
int V_37 ;
F_7 ( L_13 , F_34 ( V_36 ) ,
V_51 ) ;
V_55 = F_20 ( V_36 , & V_37 ) ;
if ( ! V_55 )
V_55 = F_24 ( V_36 , & V_37 ) ;
if ( ! V_55 ) {
F_35 ( L_14 , F_34 ( V_36 ) ) ;
goto V_56;
}
F_7 ( L_15 , V_55 -> V_33 ) ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
F_36 ( V_55 , F_30 , & V_45 ) ;
if ( V_45 . V_48 == 0 ) {
F_35 ( L_16 ,
F_34 ( V_36 ) ) ;
goto V_56;
}
V_45 . V_52 = V_37 / V_45 . V_48 ;
if ( V_51 <= V_45 . V_52 )
goto V_56;
V_45 . V_50 = F_22 ( V_36 ) ;
V_45 . V_51 = V_51 ;
F_36 ( V_55 , F_31 , & V_45 ) ;
V_45 . V_53 += V_37 % V_45 . V_48 ;
if ( V_45 . V_54 )
V_45 . V_52 += V_45 . V_53 / V_45 . V_54 ;
V_51 = F_37 ( V_45 . V_52 , V_51 ) ;
F_7 ( L_17 , V_51 ) ;
V_56:
F_38 ( V_55 ) ;
return V_51 ;
}
static int F_39 ( struct V_17 * V_18 )
{
struct V_22 * V_23 ;
int V_57 ;
V_57 = 0 ;
F_12 (entry, pdev) {
if ( V_23 -> V_58 . V_59 != V_57 ) {
F_7 ( L_18 ) ;
return - V_60 ;
}
V_57 ++ ;
}
return 0 ;
}
static void F_40 ( struct V_17 * V_18 )
{
T_1 V_61 , V_62 ;
F_41 ( & V_18 -> V_36 ,
L_19 ) ;
F_42 ( V_18 , V_18 -> V_63 + V_64 , & V_61 ) ;
V_62 = 0xffff0000 | ( ( V_61 >> ( 48 - 32 ) ) << 4 ) ;
F_43 ( V_18 , V_18 -> V_63 + V_65 , V_62 ) ;
F_43 ( V_18 , V_18 -> V_63 + V_64 , 0 ) ;
}
static int F_44 ( struct V_17 * V_18 , int V_66 , int type )
{
struct V_1 * V_2 ;
int V_67 , V_68 , V_69 , V_52 , V_9 ;
struct V_22 * V_23 ;
struct V_70 V_71 ;
int V_25 = V_66 ;
int V_72 = 0 ;
if ( type == V_73 )
V_9 = F_19 ( V_18 , V_25 ) ;
else
V_9 = F_18 ( V_18 , V_25 ) ;
if ( V_9 )
return V_9 ;
V_52 = F_33 ( V_18 , V_25 ) ;
if ( V_52 && V_52 < V_25 )
return V_52 ;
if ( type == V_73 && F_39 ( V_18 ) )
return - V_60 ;
if ( type == V_73 ) {
int V_74 = F_45 ( V_25 ) ;
V_52 = F_33 ( V_18 , V_74 ) ;
if ( V_52 >= V_74 )
V_25 = V_74 ;
}
V_2 = F_9 ( V_18 ) ;
V_75:
if ( type == V_76 ) {
if ( V_18 -> V_77 ) {
V_9 = F_1 ( V_2 , V_15 , V_25 ) ;
if ( V_9 < 0 ) {
if ( V_18 -> V_78 -> V_79 != V_80 )
return V_9 ;
V_72 = 1 ;
}
} else
V_9 = - 1 ;
if ( V_9 < 0 )
V_9 = F_1 ( V_2 , V_13 , V_25 ) ;
if ( V_9 < 0 ) {
F_7 ( L_20 ) ;
V_9 = F_1 ( V_2 , V_19 , V_25 ) ;
}
if ( V_72 && V_9 > 0 )
F_40 ( V_18 ) ;
} else
V_9 = F_1 ( V_2 , V_14 , V_25 ) ;
if ( V_9 != V_25 ) {
if ( V_25 != V_66 ) {
V_25 = V_66 ;
goto V_75;
}
F_7 ( L_21 ) ;
return V_9 ;
}
V_69 = 0 ;
F_12 (entry, pdev) {
V_67 = F_10 ( V_2 , V_69 ++ ) ;
if ( V_67 < 0 ) {
F_7 ( L_22 , V_9 ) ;
return V_67 ;
}
V_68 = F_46 ( NULL , V_67 ) ;
if ( ! V_68 ) {
F_7 ( L_23 , V_67 ) ;
return - V_35 ;
}
F_47 ( & V_18 -> V_36 , L_24 , V_68 ) ;
F_13 ( V_68 , V_23 ) ;
F_48 ( V_23 , & V_71 ) ;
V_23 -> V_71 = V_71 ;
}
return 0 ;
}
static void F_49 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_24 ) {
F_47 ( & V_18 -> V_36 , L_25 ) ;
return;
}
if ( F_18 ( V_18 , 1 ) && F_19 ( V_18 , 1 ) ) {
F_47 ( & V_18 -> V_36 , L_26 ) ;
return;
}
F_47 ( & V_18 -> V_36 , L_27 ) ;
F_8 ( V_18 ) ;
}
static int F_50 ( void )
{
struct V_81 * V_12 ;
V_21 = F_51 ( L_28 ) ;
V_16 = F_51 ( L_29 ) ;
if ( ( V_21 == V_82 ) ||
( V_16 == V_82 ) ) {
F_7 ( L_30 ) ;
return - 1 ;
}
F_7 ( L_31 ) ;
F_52 ( V_83 . V_84 ) ;
V_83 . V_84 = F_44 ;
V_83 . V_85 = F_11 ;
F_53 (phb, &hose_list, list_node) {
F_52 ( V_12 -> V_86 . V_84 ) ;
V_12 -> V_86 . V_84 = F_44 ;
V_12 -> V_86 . V_85 = F_11 ;
}
F_52 ( V_87 . V_88 ) ;
V_87 . V_88 = F_49 ;
return 0 ;
}
