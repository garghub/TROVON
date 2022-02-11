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
const T_2 * V_29 ;
T_1 V_30 ;
V_28 = F_16 ( V_18 ) ;
V_29 = F_17 ( V_28 , V_26 , NULL ) ;
if ( ! V_29 ) {
F_7 ( L_4 , V_26 , V_28 ) ;
return - V_31 ;
}
V_30 = F_18 ( V_29 ) ;
if ( V_30 < V_25 ) {
F_7 ( L_5 , V_26 , V_25 ) ;
if ( V_30 == 0 )
return - V_32 ;
return V_30 ;
}
return 0 ;
}
static int F_19 ( struct V_17 * V_18 , int V_25 )
{
return F_15 ( V_18 , V_25 , L_6 ) ;
}
static int F_20 ( struct V_17 * V_18 , int V_25 )
{
return F_15 ( V_18 , V_25 , L_7 ) ;
}
static struct V_27 * F_21 ( struct V_17 * V_33 , int * V_34 )
{
struct V_27 * V_28 ;
const T_2 * V_29 ;
V_28 = F_22 ( F_16 ( V_33 ) ) ;
while ( V_28 ) {
V_29 = F_17 ( V_28 , L_8 , NULL ) ;
if ( V_29 ) {
F_7 ( L_9 ,
V_28 ) ;
* V_34 = F_18 ( V_29 ) ;
return V_28 ;
}
V_28 = F_23 ( V_28 ) ;
}
return NULL ;
}
static struct V_27 * F_24 ( struct V_17 * V_33 , int * V_34 )
{
struct V_27 * V_28 ;
struct V_35 * V_36 ;
V_28 = F_16 ( V_33 ) ;
if ( ! V_28 )
return NULL ;
V_36 = F_25 ( F_26 ( V_28 ) ) ;
if ( V_36 -> V_37 )
V_36 = F_27 ( & V_36 -> V_37 -> V_38 , struct V_35 , V_39 ) ;
V_28 = F_16 ( V_36 -> V_18 ) ;
if ( ! V_28 )
return NULL ;
V_28 = F_28 ( V_28 ) ;
if ( ! V_28 )
return NULL ;
* V_34 = 8 ;
F_7 ( L_10 , V_28 ) ;
return V_28 ;
}
static void * F_29 ( struct V_27 * V_28 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
const T_2 * V_29 ;
T_1 V_43 ;
F_7 ( L_11 , V_28 ) ;
V_29 = F_17 ( V_28 , L_12 , NULL ) ;
V_43 = V_29 ? F_18 ( V_29 ) : 0 ;
if ( ( V_43 >> 8 ) != V_44 )
V_42 -> V_45 ++ ;
return NULL ;
}
static void * F_30 ( struct V_27 * V_28 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
const T_2 * V_29 ;
int V_46 ;
if ( V_28 == V_42 -> V_47 )
V_46 = V_42 -> V_48 ;
else {
V_46 = 0 ;
V_29 = F_17 ( V_28 , L_6 , NULL ) ;
if ( V_29 )
V_46 = F_18 ( V_29 ) ;
V_29 = F_17 ( V_28 , L_7 , NULL ) ;
if ( V_29 )
V_46 = F_31 ( V_46 , ( int ) F_18 ( V_29 ) ) ;
}
if ( V_46 < V_42 -> V_49 )
V_42 -> V_50 += V_42 -> V_49 - V_46 ;
else if ( V_46 > V_42 -> V_49 )
V_42 -> V_51 ++ ;
return NULL ;
}
static int F_32 ( struct V_17 * V_33 , int V_48 )
{
struct V_27 * V_52 ;
struct V_41 V_42 ;
int V_34 ;
F_7 ( L_13 , F_33 ( V_33 ) ,
V_48 ) ;
V_52 = F_21 ( V_33 , & V_34 ) ;
if ( ! V_52 )
V_52 = F_24 ( V_33 , & V_34 ) ;
if ( ! V_52 ) {
F_34 ( L_14 , F_33 ( V_33 ) ) ;
goto V_53;
}
F_7 ( L_15 , V_52 ) ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
F_35 ( V_52 , F_29 , & V_42 ) ;
if ( V_42 . V_45 == 0 ) {
F_34 ( L_16 ,
F_33 ( V_33 ) ) ;
goto V_53;
}
V_42 . V_49 = V_34 / V_42 . V_45 ;
if ( V_48 <= V_42 . V_49 )
goto V_53;
V_42 . V_47 = F_16 ( V_33 ) ;
V_42 . V_48 = V_48 ;
F_35 ( V_52 , F_30 , & V_42 ) ;
V_42 . V_50 += V_34 % V_42 . V_45 ;
if ( V_42 . V_51 )
V_42 . V_49 += V_42 . V_50 / V_42 . V_51 ;
V_48 = F_36 ( V_42 . V_49 , V_48 ) ;
F_7 ( L_17 , V_48 ) ;
V_53:
F_37 ( V_52 ) ;
return V_48 ;
}
static int F_38 ( struct V_17 * V_18 )
{
struct V_22 * V_23 ;
int V_54 ;
V_54 = 0 ;
F_12 (entry, pdev) {
if ( V_23 -> V_55 . V_56 != V_54 ) {
F_7 ( L_18 ) ;
return - V_57 ;
}
V_54 ++ ;
}
return 0 ;
}
static void F_39 ( struct V_17 * V_18 )
{
T_1 V_58 , V_59 ;
F_40 ( & V_18 -> V_33 ,
L_19 ) ;
F_41 ( V_18 , V_18 -> V_60 + V_61 , & V_58 ) ;
V_59 = 0xffff0000 | ( ( V_58 >> ( 48 - 32 ) ) << 4 ) ;
F_42 ( V_18 , V_18 -> V_60 + V_62 , V_59 ) ;
F_42 ( V_18 , V_18 -> V_60 + V_61 , 0 ) ;
}
static int F_43 ( struct V_17 * V_18 , int V_63 , int type )
{
struct V_1 * V_2 ;
int V_64 , V_65 , V_66 , V_49 , V_9 ;
struct V_22 * V_23 ;
struct V_67 V_68 ;
int V_25 = V_63 ;
int V_69 = 0 ;
if ( type == V_70 )
V_9 = F_20 ( V_18 , V_25 ) ;
else
V_9 = F_19 ( V_18 , V_25 ) ;
if ( V_9 )
return V_9 ;
V_49 = F_32 ( V_18 , V_25 ) ;
if ( V_49 && V_49 < V_25 )
return V_49 ;
if ( type == V_70 && F_38 ( V_18 ) )
return - V_57 ;
if ( type == V_70 ) {
int V_71 = F_44 ( V_25 ) ;
V_49 = F_32 ( V_18 , V_71 ) ;
if ( V_49 >= V_71 )
V_25 = V_71 ;
}
V_2 = F_9 ( V_18 ) ;
V_72:
if ( type == V_73 ) {
if ( V_18 -> V_74 ) {
V_9 = F_1 ( V_2 , V_15 , V_25 ) ;
if ( V_9 < 0 ) {
if ( V_18 -> V_75 -> V_76 != V_77 )
return V_9 ;
V_69 = 1 ;
}
} else
V_9 = - 1 ;
if ( V_9 < 0 )
V_9 = F_1 ( V_2 , V_13 , V_25 ) ;
if ( V_9 < 0 ) {
F_7 ( L_20 ) ;
V_9 = F_1 ( V_2 , V_19 , V_25 ) ;
}
if ( V_69 && V_9 > 0 )
F_39 ( V_18 ) ;
} else
V_9 = F_1 ( V_2 , V_14 , V_25 ) ;
if ( V_9 != V_25 ) {
if ( V_25 != V_63 ) {
V_25 = V_63 ;
goto V_72;
}
F_7 ( L_21 ) ;
return V_9 ;
}
V_66 = 0 ;
F_12 (entry, pdev) {
V_64 = F_10 ( V_2 , V_66 ++ ) ;
if ( V_64 < 0 ) {
F_7 ( L_22 , V_9 ) ;
return V_64 ;
}
V_65 = F_45 ( NULL , V_64 ) ;
if ( ! V_65 ) {
F_7 ( L_23 , V_64 ) ;
return - V_32 ;
}
F_46 ( & V_18 -> V_33 , L_24 , V_65 ) ;
F_13 ( V_65 , V_23 ) ;
F_47 ( V_23 , & V_68 ) ;
V_23 -> V_68 = V_68 ;
}
return 0 ;
}
static void F_48 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_24 ) {
F_46 ( & V_18 -> V_33 , L_25 ) ;
return;
}
if ( F_19 ( V_18 , 1 ) && F_20 ( V_18 , 1 ) ) {
F_46 ( & V_18 -> V_33 , L_26 ) ;
return;
}
F_46 ( & V_18 -> V_33 , L_27 ) ;
F_8 ( V_18 ) ;
}
static int F_49 ( void )
{
struct V_78 * V_12 ;
V_21 = F_50 ( L_28 ) ;
V_16 = F_50 ( L_29 ) ;
if ( ( V_21 == V_79 ) ||
( V_16 == V_79 ) ) {
F_7 ( L_30 ) ;
return - 1 ;
}
F_7 ( L_31 ) ;
F_51 ( V_80 . V_81 ) ;
V_80 . V_81 = F_43 ;
V_80 . V_82 = F_11 ;
F_52 (phb, &hose_list, list_node) {
F_51 ( V_12 -> V_83 . V_81 ) ;
V_12 -> V_83 . V_81 = F_43 ;
V_12 -> V_83 . V_82 = F_11 ;
}
F_51 ( V_84 . V_85 ) ;
V_84 . V_85 = F_48 ;
return 0 ;
}
