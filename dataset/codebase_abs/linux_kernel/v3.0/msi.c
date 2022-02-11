static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
if ( ! V_5 ) {
F_3 ( & V_3 -> V_7 , L_1 ) ;
return NULL ;
}
V_6 = F_4 ( V_5 ) ;
if ( ! V_6 ) {
F_3 ( & V_3 -> V_7 , L_2 ) ;
return NULL ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_6 , T_1 V_8 , T_1 V_9 )
{
T_1 V_10 , V_11 , V_12 [ 3 ] ;
unsigned long V_13 ;
int V_14 ;
V_10 = F_6 ( V_6 -> V_15 , V_6 -> V_16 , 0 ) ;
V_13 = V_6 -> V_17 -> V_13 ;
V_11 = 1 ;
do {
if ( V_8 == V_18 || V_8 == V_19 )
V_14 = F_7 ( V_20 , 6 , 4 , V_12 , V_10 ,
F_8 ( V_13 ) , F_9 ( V_13 ) ,
V_8 , V_9 , V_11 ) ;
else
V_14 = F_7 ( V_20 , 6 , 3 , V_12 , V_10 ,
F_8 ( V_13 ) , F_9 ( V_13 ) ,
V_8 , V_9 , V_11 ) ;
V_11 = V_12 [ 1 ] ;
} while ( F_10 ( V_14 ) );
if ( V_14 == 0 )
V_14 = V_12 [ 0 ] ;
else if ( V_14 > 0 )
V_14 = - V_14 ;
F_11 ( L_3 ,
V_8 , V_9 , V_12 [ 0 ] , V_14 ) ;
return V_14 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return;
if ( F_5 ( V_6 , V_18 , 0 ) != 0 ) {
if ( F_5 ( V_6 , V_21 , 0 ) != 0 ) {
F_11 ( L_4 ) ;
}
}
}
static int F_13 ( struct V_1 * V_6 , int V_22 )
{
T_1 V_10 , V_12 [ 2 ] ;
unsigned long V_13 ;
int V_14 ;
V_10 = F_6 ( V_6 -> V_15 , V_6 -> V_16 , 0 ) ;
V_13 = V_6 -> V_17 -> V_13 ;
do {
V_14 = F_7 ( V_23 , 4 , 3 , V_12 , V_10 ,
F_8 ( V_13 ) , F_9 ( V_13 ) , V_22 ) ;
} while ( F_10 ( V_14 ) );
if ( V_14 ) {
F_11 ( L_5 , V_14 ) ;
return V_14 ;
}
return V_12 [ 0 ] ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
F_15 (entry, &pdev->msi_list, list) {
if ( V_25 -> V_26 == V_27 )
continue;
F_16 ( V_25 -> V_26 , NULL ) ;
F_17 ( V_25 -> V_26 ) ;
}
F_12 ( V_3 ) ;
}
static int F_18 ( struct V_2 * V_3 , int V_28 , char * V_29 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
const T_1 * V_30 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_31 ;
V_5 = V_6 -> V_32 ;
V_30 = F_19 ( V_5 , V_29 , NULL ) ;
if ( ! V_30 ) {
F_11 ( L_6 , V_29 , V_5 -> V_33 ) ;
return - V_34 ;
}
if ( * V_30 < V_28 ) {
F_11 ( L_7 , V_29 , V_28 ) ;
if ( * V_30 == 0 )
return - V_35 ;
return * V_30 ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , int V_28 )
{
return F_18 ( V_3 , V_28 , L_8 ) ;
}
static int F_21 ( struct V_2 * V_3 , int V_28 )
{
return F_18 ( V_3 , V_28 , L_9 ) ;
}
static struct V_4 * F_22 ( struct V_2 * V_7 , int * V_36 )
{
struct V_4 * V_5 ;
const T_1 * V_37 ;
V_5 = F_23 ( F_2 ( V_7 ) ) ;
while ( V_5 ) {
V_37 = F_19 ( V_5 , L_10 , NULL ) ;
if ( V_37 ) {
F_11 ( L_11 ,
V_5 -> V_33 ) ;
* V_36 = * V_37 ;
return V_5 ;
}
V_5 = F_24 ( V_5 ) ;
}
return NULL ;
}
static struct V_4 * F_25 ( struct V_2 * V_7 , int * V_36 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 = F_26 ( V_5 ) ;
if ( ! V_5 )
return NULL ;
V_5 = F_27 ( V_5 ) ;
if ( ! V_5 )
return NULL ;
* V_36 = 8 ;
F_11 ( L_12 , V_5 -> V_33 ) ;
return V_5 ;
}
static void * F_28 ( struct V_4 * V_5 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
const T_1 * V_37 ;
T_1 V_41 ;
F_11 ( L_13 , V_5 -> V_33 ) ;
V_37 = F_19 ( V_5 , L_14 , NULL ) ;
V_41 = V_37 ? * V_37 : 0 ;
if ( ( V_41 >> 8 ) != V_42 )
V_40 -> V_43 ++ ;
return NULL ;
}
static void * F_29 ( struct V_4 * V_5 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
const T_1 * V_37 ;
int V_44 ;
if ( V_5 == V_40 -> V_45 )
V_44 = V_40 -> V_46 ;
else {
V_44 = 0 ;
V_37 = F_19 ( V_5 , L_8 , NULL ) ;
if ( V_37 )
V_44 = * V_37 ;
V_37 = F_19 ( V_5 , L_9 , NULL ) ;
if ( V_37 )
V_44 = F_30 ( V_44 , ( int ) * V_37 ) ;
}
if ( V_44 < V_40 -> V_47 )
V_40 -> V_48 += V_40 -> V_47 - V_44 ;
else if ( V_44 > V_40 -> V_47 )
V_40 -> V_49 ++ ;
return NULL ;
}
static int F_31 ( struct V_2 * V_7 , int V_46 )
{
struct V_4 * V_50 ;
struct V_39 V_40 ;
int V_36 ;
F_11 ( L_15 , F_32 ( V_7 ) ,
V_46 ) ;
V_50 = F_22 ( V_7 , & V_36 ) ;
if ( ! V_50 )
V_50 = F_25 ( V_7 , & V_36 ) ;
if ( ! V_50 ) {
F_33 ( L_16 , F_32 ( V_7 ) ) ;
goto V_51;
}
F_11 ( L_17 , V_50 -> V_33 ) ;
memset ( & V_40 , 0 , sizeof( struct V_39 ) ) ;
F_34 ( V_50 , F_28 , & V_40 ) ;
if ( V_40 . V_43 == 0 ) {
F_33 ( L_18 ,
F_32 ( V_7 ) ) ;
goto V_51;
}
V_40 . V_47 = V_36 / V_40 . V_43 ;
if ( V_46 <= V_40 . V_47 )
goto V_51;
V_40 . V_45 = F_2 ( V_7 ) ;
V_40 . V_46 = V_46 ;
F_34 ( V_50 , F_29 , & V_40 ) ;
V_40 . V_48 += V_36 % V_40 . V_43 ;
if ( V_40 . V_49 )
V_40 . V_47 += V_40 . V_48 / V_40 . V_49 ;
V_46 = F_35 ( V_40 . V_47 , V_46 ) ;
F_11 ( L_19 , V_46 ) ;
V_51:
F_36 ( V_50 ) ;
return V_46 ;
}
static int F_37 ( struct V_2 * V_3 , int V_28 , int type )
{
int V_47 , V_14 ;
if ( type == V_52 )
V_14 = F_21 ( V_3 , V_28 ) ;
else
V_14 = F_20 ( V_3 , V_28 ) ;
if ( V_14 )
return V_14 ;
V_47 = F_31 ( V_3 , V_28 ) ;
if ( V_47 && V_47 < V_28 )
return V_47 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
int V_53 ;
V_53 = 0 ;
F_15 (entry, &pdev->msi_list, list) {
if ( V_25 -> V_54 . V_55 != V_53 ) {
F_11 ( L_20 ) ;
return - V_56 ;
}
V_53 ++ ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , int V_28 , int type )
{
struct V_1 * V_6 ;
int V_57 , V_58 , V_59 , V_14 ;
struct V_24 * V_25 ;
struct V_60 V_61 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_31 ;
if ( type == V_52 && F_38 ( V_3 ) )
return - V_56 ;
if ( type == V_62 ) {
V_14 = F_5 ( V_6 , V_18 , V_28 ) ;
if ( V_14 < 0 ) {
F_11 ( L_21 ) ;
V_14 = F_5 ( V_6 , V_21 , V_28 ) ;
}
} else
V_14 = F_5 ( V_6 , V_19 , V_28 ) ;
if ( V_14 != V_28 ) {
F_11 ( L_22 ) ;
return V_14 ;
}
V_59 = 0 ;
F_15 (entry, &pdev->msi_list, list) {
V_57 = F_13 ( V_6 , V_59 ++ ) ;
if ( V_57 < 0 ) {
F_11 ( L_23 , V_14 ) ;
return V_57 ;
}
V_58 = F_40 ( NULL , V_57 ) ;
if ( V_58 == V_27 ) {
F_11 ( L_24 , V_57 ) ;
return - V_35 ;
}
F_3 ( & V_3 -> V_7 , L_25 , V_58 ) ;
F_16 ( V_58 , V_25 ) ;
F_41 ( V_58 , & V_61 ) ;
V_25 -> V_61 = V_61 ;
}
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
if ( V_3 -> V_26 == V_27 ) {
F_3 ( & V_3 -> V_7 , L_26 ) ;
return;
}
if ( F_20 ( V_3 , 1 ) && F_21 ( V_3 , 1 ) ) {
F_3 ( & V_3 -> V_7 , L_27 ) ;
return;
}
F_3 ( & V_3 -> V_7 , L_28 ) ;
F_12 ( V_3 ) ;
}
static int F_43 ( void )
{
V_23 = F_44 ( L_29 ) ;
V_20 = F_44 ( L_30 ) ;
if ( ( V_23 == V_63 ) ||
( V_20 == V_63 ) ) {
F_11 ( L_31 ) ;
return - 1 ;
}
F_11 ( L_32 ) ;
F_45 ( V_64 . V_65 ) ;
V_64 . V_65 = F_39 ;
V_64 . V_66 = F_14 ;
V_64 . V_67 = F_37 ;
F_45 ( V_64 . V_68 ) ;
V_64 . V_68 = F_42 ;
return 0 ;
}
