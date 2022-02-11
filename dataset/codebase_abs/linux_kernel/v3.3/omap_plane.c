static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = & V_5 -> V_9 ;
int V_10 ;
F_3 ( L_1 , V_7 -> V_11 ) ;
F_3 ( L_2 , V_9 -> V_12 , V_9 -> V_13 , V_9 -> V_14 ,
V_9 -> V_15 , V_9 -> V_16 ) ;
F_3 ( L_3 , V_9 -> V_17 , V_9 -> V_18 ,
V_9 -> V_19 , V_9 -> V_20 ) ;
V_10 = V_7 -> V_21 ( V_7 , V_9 ) ;
if ( V_10 ) {
F_4 ( V_4 -> V_4 , L_4 ) ;
return V_10 ;
}
if ( V_7 -> V_22 ) {
V_10 = V_7 -> V_22 -> V_23 ( V_7 -> V_22 ) ;
if ( V_10 ) {
F_4 ( V_4 -> V_4 , L_5 ) ;
return V_10 ;
}
}
if ( V_7 -> V_24 ( V_7 ) ) {
F_5 ( V_2 -> V_25 , V_9 -> V_17 , V_9 -> V_18 ,
V_9 -> V_14 , V_9 -> V_15 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_4 -> V_28 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_29 * V_30 = NULL ;
int V_31 ;
if ( V_2 -> V_32 ) {
for ( V_31 = 0 ; V_31 < V_27 -> V_33 ; V_31 ++ ) {
struct V_34 * V_35 = V_27 -> V_36 [ V_31 ] ;
if ( V_35 -> V_32 == V_2 -> V_32 ) {
V_30 = F_7 ( V_35 ) ;
break;
}
}
}
if ( V_7 -> V_22 != V_30 ) {
bool V_37 = V_7 -> V_24 ( V_7 ) ;
if ( V_37 )
F_8 ( V_2 , V_38 ) ;
if ( V_7 -> V_22 ) {
F_3 ( L_6 , V_7 -> V_11 ,
V_7 -> V_22 -> V_11 ) ;
V_7 -> V_39 ( V_7 ) ;
}
if ( V_30 ) {
F_3 ( L_7 , V_7 -> V_11 , V_30 -> V_11 ) ;
V_7 -> V_40 ( V_7 , V_30 ) ;
}
if ( V_37 && V_30 )
F_8 ( V_2 , V_41 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , struct V_42 * V_25 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_10 = 0 ;
if ( V_5 -> V_43 != V_25 ) {
if ( V_5 -> V_43 )
F_10 ( V_5 -> V_43 ) ;
V_5 -> V_43 = V_25 ;
if ( V_25 )
V_10 = F_11 ( V_25 ) ;
}
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_5 -> V_9 ;
int V_10 ;
V_10 = F_9 ( V_2 , V_2 -> V_25 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_4 -> V_4 ,
L_8 , V_10 ) ;
F_8 ( V_2 , V_38 ) ;
return;
}
F_13 ( V_2 -> V_25 ,
V_5 -> V_44 , V_5 -> V_45 , V_9 ) ;
F_3 ( L_9 , V_5 -> V_7 -> V_11 ,
V_5 -> V_44 , V_5 -> V_45 ,
( V_46 ) V_9 -> V_19 , ( V_46 ) V_9 -> V_20 ,
V_9 -> V_16 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_47 * V_32 , struct V_42 * V_25 ,
int V_48 , int V_49 ,
unsigned int V_50 , unsigned int V_51 ,
T_1 V_44 , T_1 V_45 ,
T_1 V_52 , T_1 V_53 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_44 = V_44 >> 16 ;
V_45 = V_45 >> 16 ;
V_52 = V_52 >> 16 ;
V_53 = V_53 >> 16 ;
V_5 -> V_9 . V_17 = V_48 ;
V_5 -> V_9 . V_18 = V_49 ;
V_5 -> V_9 . V_14 = V_50 ;
V_5 -> V_9 . V_15 = V_51 ;
V_5 -> V_9 . V_12 = V_52 ;
V_5 -> V_9 . V_13 = V_53 ;
V_5 -> V_44 = V_44 ;
V_5 -> V_45 = V_45 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_32 = V_32 ;
F_12 ( V_2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_47 * V_32 , struct V_42 * V_25 ,
int V_48 , int V_49 ,
unsigned int V_50 , unsigned int V_51 ,
T_1 V_44 , T_1 V_45 ,
T_1 V_52 , T_1 V_53 )
{
F_14 ( V_2 , V_32 , V_25 , V_48 , V_49 , V_50 , V_51 ,
V_44 , V_45 , V_52 , V_53 ) ;
return F_8 ( V_2 , V_41 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_38 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_5 -> V_7 -> V_11 ) ;
F_16 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_5 ) ;
}
int F_8 ( struct V_1 * V_2 , int V_54 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_55 ;
F_3 ( L_10 , V_5 -> V_7 -> V_11 , V_54 ) ;
if ( V_54 == V_41 ) {
F_12 ( V_2 ) ;
V_55 = F_1 ( V_2 ) ;
if ( ! V_55 )
V_55 = V_7 -> V_56 ( V_7 ) ;
} else {
V_55 = V_7 -> V_57 ( V_7 ) ;
F_9 ( V_2 , NULL ) ;
}
return V_55 ;
}
struct V_1 * F_20 ( struct V_3 * V_4 ,
struct V_6 * V_7 , unsigned int V_58 ,
bool V_27 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_5 ;
F_3 ( L_11 , V_7 -> V_11 ,
V_58 , V_27 ) ;
V_5 = F_21 ( sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 ) {
F_4 ( V_4 -> V_4 , L_12 ) ;
goto V_60;
}
V_5 -> V_7 = V_7 ;
V_2 = & V_5 -> V_61 ;
F_22 ( V_4 , V_2 , V_58 , & V_62 ,
V_63 , F_23 ( V_63 ) , V_27 ) ;
V_7 -> V_64 ( V_7 , & V_5 -> V_9 ) ;
V_5 -> V_9 . V_65 = V_66 ;
V_5 -> V_9 . V_67 = V_68 ;
V_5 -> V_9 . V_69 = 0xff ;
V_5 -> V_9 . V_70 = 0 ;
V_5 -> V_9 . V_70 = 0 ;
if ( V_27 )
V_5 -> V_9 . V_71 = 0 ;
else
V_5 -> V_9 . V_71 = 1 ;
F_6 ( V_2 ) ;
return V_2 ;
V_60:
if ( V_2 ) {
F_17 ( V_2 ) ;
}
return NULL ;
}
