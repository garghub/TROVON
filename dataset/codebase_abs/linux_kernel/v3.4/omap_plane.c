static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
F_3 ( F_1 , V_4 ,
V_10 [ V_5 -> V_11 -> V_12 ] ) ;
F_4 ( V_7 -> V_13 , & V_5 -> V_14 ) ;
}
static void F_5 ( struct V_15 * V_14 )
{
struct V_5 * V_5 =
F_6 ( V_14 , struct V_5 , V_14 ) ;
struct V_16 V_17 ;
F_7 ( & V_5 -> V_18 ) ;
F_8 ( L_1 , V_5 -> V_19 ,
V_5 -> V_19 + V_5 -> V_20 ) ;
while ( V_5 -> V_19 > 0 ) {
struct V_21 * V_22 = NULL ;
int V_23 = F_9 ( & V_5 -> V_24 , & V_22 ) ;
F_10 ( ! V_23 ) ;
F_11 ( V_22 ) ;
F_12 ( V_22 ) ;
V_5 -> V_19 -- ;
}
V_17 = V_5 -> V_17 ;
V_5 -> V_17 . V_25 = NULL ;
F_13 ( & V_5 -> V_18 ) ;
if ( V_17 . V_25 )
V_17 . V_25 ( V_17 . V_1 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_26 * V_11 = V_5 -> V_11 ;
int V_23 ;
V_23 = F_15 ( F_1 , V_4 , V_10 [ V_11 -> V_12 ] ) ;
F_10 ( V_23 == - V_27 ) ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_28 * V_8 = V_4 -> V_8 ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_26 * V_11 = V_5 -> V_11 ;
struct V_29 * V_30 = & V_5 -> V_30 ;
int V_23 ;
F_8 ( L_2 , V_11 -> V_31 ) ;
F_8 ( L_3 , V_30 -> V_32 , V_30 -> V_33 , V_30 -> V_34 ,
V_30 -> V_35 , V_30 -> V_36 ) ;
F_8 ( L_4 , V_30 -> V_37 , V_30 -> V_38 ,
V_30 -> V_39 , V_30 -> V_40 ) ;
V_23 = V_11 -> V_41 ( V_11 , V_30 ) ;
if ( V_23 ) {
F_17 ( V_8 -> V_8 , L_5 ) ;
return V_23 ;
}
F_7 ( & V_5 -> V_18 ) ;
V_5 -> V_19 += V_5 -> V_20 ;
V_5 -> V_20 = 0 ;
F_13 ( & V_5 -> V_18 ) ;
if ( V_11 -> V_42 ) {
V_23 = V_11 -> V_42 -> V_43 ( V_11 -> V_42 ) ;
if ( V_23 ) {
F_17 ( V_8 -> V_8 , L_6 ) ;
return V_23 ;
}
if ( V_5 -> V_19 > 0 )
F_14 ( V_4 ) ;
} else {
struct V_6 * V_7 = V_8 -> V_9 ;
F_4 ( V_7 -> V_13 , & V_5 -> V_14 ) ;
}
if ( V_11 -> V_44 ( V_11 ) ) {
F_18 ( V_4 -> V_45 , V_30 -> V_37 , V_30 -> V_38 ,
V_30 -> V_34 , V_30 -> V_35 ) ;
}
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_26 * V_11 = V_5 -> V_11 ;
struct V_46 * V_47 = NULL ;
int V_48 ;
if ( V_4 -> V_49 ) {
for ( V_48 = 0 ; V_48 < V_7 -> V_50 ; V_48 ++ ) {
struct V_51 * V_52 = V_7 -> V_53 [ V_48 ] ;
if ( V_52 -> V_49 == V_4 -> V_49 ) {
V_47 = F_20 ( V_52 ) ;
break;
}
}
}
if ( V_11 -> V_42 != V_47 ) {
bool V_54 = V_11 -> V_44 ( V_11 ) ;
if ( V_54 )
F_21 ( V_4 , V_55 ) ;
if ( V_11 -> V_42 ) {
F_8 ( L_7 , V_11 -> V_31 ,
V_11 -> V_42 -> V_31 ) ;
V_11 -> V_56 ( V_11 ) ;
}
if ( V_47 ) {
F_8 ( L_8 , V_11 -> V_31 , V_47 -> V_31 ) ;
V_11 -> V_57 ( V_11 , V_47 ) ;
}
if ( V_54 && V_47 )
F_21 ( V_4 , V_58 ) ;
}
}
static void F_22 ( void * V_1 , struct V_21 * V_22 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
if ( F_23 ( & V_5 -> V_24 ,
( const struct V_21 * * ) & V_22 ) ) {
V_5 -> V_20 ++ ;
F_24 ( V_22 ) ;
} else {
F_17 ( V_4 -> V_8 -> V_8 , L_9 ) ;
F_11 ( V_22 ) ;
}
}
static int F_25 ( struct V_3 * V_4 , struct V_59 * V_45 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_59 * V_60 = V_5 -> V_60 ;
if ( V_60 != V_45 ) {
int V_23 ;
F_8 ( L_10 , V_60 , V_45 ) ;
F_7 ( & V_5 -> V_18 ) ;
V_23 = F_26 ( V_60 , V_45 , V_4 , F_22 ) ;
F_13 ( & V_5 -> V_18 ) ;
if ( V_23 ) {
F_17 ( V_4 -> V_8 -> V_8 , L_11 ,
V_5 -> V_60 , V_45 ) ;
V_5 -> V_60 = NULL ;
return V_23 ;
}
V_5 -> V_60 = V_45 ;
}
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_29 * V_30 = & V_5 -> V_30 ;
int V_23 ;
V_23 = F_25 ( V_4 , V_4 -> V_45 ) ;
if ( V_23 ) {
F_17 ( V_4 -> V_8 -> V_8 ,
L_12 , V_23 ) ;
F_21 ( V_4 , V_55 ) ;
return;
}
F_28 ( V_4 -> V_45 ,
V_5 -> V_61 , V_5 -> V_62 , V_30 ) ;
F_8 ( L_13 , V_5 -> V_11 -> V_31 ,
V_5 -> V_61 , V_5 -> V_62 ,
( V_63 ) V_30 -> V_39 , ( V_63 ) V_30 -> V_40 ,
V_30 -> V_36 ) ;
}
int F_29 ( struct V_3 * V_4 ,
struct V_64 * V_49 , struct V_59 * V_45 ,
int V_65 , int V_66 ,
unsigned int V_67 , unsigned int V_68 ,
T_1 V_61 , T_1 V_62 ,
T_1 V_69 , T_1 V_70 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
V_61 = V_61 >> 16 ;
V_62 = V_62 >> 16 ;
V_69 = V_69 >> 16 ;
V_70 = V_70 >> 16 ;
V_5 -> V_30 . V_37 = V_65 ;
V_5 -> V_30 . V_38 = V_66 ;
V_5 -> V_30 . V_34 = V_67 ;
V_5 -> V_30 . V_35 = V_68 ;
V_5 -> V_30 . V_32 = V_69 ;
V_5 -> V_30 . V_33 = V_70 ;
V_5 -> V_61 = V_61 ;
V_5 -> V_62 = V_62 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_49 = V_49 ;
F_27 ( V_4 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_64 * V_49 , struct V_59 * V_45 ,
int V_65 , int V_66 ,
unsigned int V_67 , unsigned int V_68 ,
T_1 V_61 , T_1 V_62 ,
T_1 V_69 , T_1 V_70 )
{
F_29 ( V_4 , V_49 , V_45 , V_65 , V_66 , V_67 , V_68 ,
V_61 , V_62 , V_69 , V_70 ) ;
return F_21 ( V_4 , V_58 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
return F_21 ( V_4 , V_55 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
F_8 ( L_2 , V_5 -> V_11 -> V_31 ) ;
F_31 ( V_4 ) ;
F_33 ( V_4 ) ;
F_10 ( V_5 -> V_20 + V_5 -> V_19 > 0 ) ;
F_34 ( & V_5 -> V_24 ) ;
F_35 ( V_5 ) ;
}
int F_21 ( struct V_3 * V_4 , int V_71 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_26 * V_11 = V_5 -> V_11 ;
int V_72 ;
F_8 ( L_14 , V_5 -> V_11 -> V_31 , V_71 ) ;
if ( V_71 == V_58 ) {
F_27 ( V_4 ) ;
V_72 = F_16 ( V_4 ) ;
if ( ! V_72 )
V_72 = V_11 -> V_73 ( V_11 ) ;
} else {
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
V_72 = V_11 -> V_74 ( V_11 ) ;
F_25 ( V_4 , NULL ) ;
F_4 ( V_7 -> V_13 , & V_5 -> V_14 ) ;
}
return V_72 ;
}
void F_36 ( struct V_3 * V_4 ,
void (* V_25)( void * ) , void * V_1 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
F_7 ( & V_5 -> V_18 ) ;
V_5 -> V_17 . V_25 = V_25 ;
V_5 -> V_17 . V_1 = V_1 ;
F_13 ( & V_5 -> V_18 ) ;
F_14 ( V_4 ) ;
}
struct V_3 * F_37 ( struct V_28 * V_8 ,
struct V_26 * V_11 , unsigned int V_75 ,
bool V_7 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_5 ;
int V_23 ;
F_8 ( L_15 , V_11 -> V_31 ,
V_75 , V_7 ) ;
F_10 ( V_11 -> V_12 >= F_38 ( V_10 ) ) ;
V_5 = F_39 ( sizeof( * V_5 ) , V_76 ) ;
if ( ! V_5 ) {
F_17 ( V_8 -> V_8 , L_16 ) ;
goto V_77;
}
F_40 ( & V_5 -> V_18 ) ;
V_23 = F_41 ( & V_5 -> V_24 , 16 , V_76 ) ;
if ( V_23 ) {
F_17 ( V_8 -> V_8 , L_17 ) ;
goto V_77;
}
F_42 ( & V_5 -> V_14 , F_5 ) ;
V_5 -> V_78 = F_43 (
V_5 -> V_79 , F_38 ( V_5 -> V_79 ) ,
V_11 -> V_80 ) ;
V_5 -> V_11 = V_11 ;
V_4 = & V_5 -> V_81 ;
F_44 ( V_8 , V_4 , V_75 , & V_82 ,
V_5 -> V_79 , V_5 -> V_78 , V_7 ) ;
V_11 -> V_83 ( V_11 , & V_5 -> V_30 ) ;
V_5 -> V_30 . V_84 = V_85 ;
V_5 -> V_30 . V_86 = V_87 ;
V_5 -> V_30 . V_88 = 0xff ;
V_5 -> V_30 . V_89 = 0 ;
V_5 -> V_30 . V_89 = 0 ;
if ( V_7 )
V_5 -> V_30 . V_90 = 0 ;
else
V_5 -> V_30 . V_90 = V_11 -> V_12 ;
F_19 ( V_4 ) ;
return V_4 ;
V_77:
if ( V_4 ) {
F_32 ( V_4 ) ;
}
return NULL ;
}
