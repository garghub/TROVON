static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( ! V_7 ) {
F_3 ( V_2 , L_1 ) ;
return - V_9 ;
}
F_4 ( & V_7 -> V_10 . V_11 ) ;
V_8 = V_7 -> V_10 . V_8 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
return snprintf ( V_5 , V_12 , L_2 , V_8 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_14 = 0 ;
struct V_15 * V_15 ;
if ( ! V_7 ) {
F_3 ( V_2 , L_1 ) ;
return - V_9 ;
}
sscanf ( V_5 , L_3 , & V_14 ) ;
if ( V_14 != - 1 ) {
F_7 ( V_2 , L_4 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
if ( V_7 -> V_10 . V_8 != V_16 ) {
F_3 ( V_2 , L_5 ) ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
return - V_17 ;
}
V_15 = F_8 ( V_14 ) ;
if ( ! V_15 ) {
F_5 ( & V_7 -> V_10 . V_11 ) ;
return - V_17 ;
}
V_7 -> V_10 . V_18 = V_15 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_19 = F_9 ( V_20 , & V_7 -> V_10 , L_6 ) ;
V_7 -> V_10 . V_21 = F_9 ( V_22 , & V_7 -> V_10 , L_7 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_8 = V_23 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
} else {
F_7 ( V_2 , L_8 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
if ( V_7 -> V_10 . V_8 != V_23 ) {
F_5 ( & V_7 -> V_10 . V_11 ) ;
return - V_17 ;
}
F_5 ( & V_7 -> V_10 . V_11 ) ;
F_10 ( & V_7 -> V_10 , V_24 ) ;
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
V_25 = F_12 ( V_2 , & V_26 ) ;
if ( V_25 )
goto V_27;
V_25 = F_12 ( V_2 , & V_28 ) ;
if ( V_25 )
goto V_29;
V_25 = F_12 ( V_2 , & V_30 ) ;
if ( V_25 )
goto V_31;
return 0 ;
V_31:
F_13 ( V_2 , & V_28 ) ;
V_29:
F_13 ( V_2 , & V_26 ) ;
V_27:
return V_25 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 , & V_26 ) ;
F_13 ( V_2 , & V_28 ) ;
F_13 ( V_2 , & V_30 ) ;
}
static void F_15 ( struct V_32 * V_10 )
{
struct V_6 * V_7 = F_16 ( V_10 , struct V_6 , V_10 ) ;
if ( V_10 -> V_18 ) {
F_17 ( & V_7 -> V_33 -> V_2 , L_9 ,
V_10 -> V_18 ) ;
F_18 ( V_10 -> V_18 , V_34 ) ;
}
if ( V_10 -> V_19 )
F_19 ( V_10 -> V_19 ) ;
if ( V_10 -> V_21 )
F_19 ( V_10 -> V_21 ) ;
if ( V_10 -> V_18 ) {
F_20 ( V_10 -> V_18 ) ;
V_10 -> V_18 = NULL ;
}
F_21 ( V_7 ) ;
{
unsigned long V_35 ;
struct V_36 * V_37 , * V_38 ;
F_22 ( & V_7 -> V_39 , V_35 ) ;
F_23 (unlink, tmp, &sdev->unlink_tx, list) {
F_24 ( & V_37 -> V_40 ) ;
F_25 ( V_37 ) ;
}
F_23 (unlink, tmp, &sdev->unlink_free,
list) {
F_24 ( & V_37 -> V_40 ) ;
F_25 ( V_37 ) ;
}
F_26 ( & V_7 -> V_39 , V_35 ) ;
}
}
static void F_27 ( struct V_32 * V_10 )
{
struct V_6 * V_7 = F_16 ( V_10 , struct V_6 , V_10 ) ;
struct V_41 * V_33 = V_7 -> V_33 ;
int V_42 ;
F_17 ( & V_33 -> V_2 , L_10 ) ;
V_42 = F_28 ( V_33 , V_7 -> V_43 ) ;
if ( V_42 < 0 ) {
F_3 ( & V_33 -> V_2 , L_11 ) ;
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_8 = V_44 ;
F_5 ( & V_10 -> V_11 ) ;
return;
}
V_42 = F_29 ( V_33 ) ;
F_30 ( V_33 ) ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_42 ) {
F_3 ( & V_33 -> V_2 , L_12 ) ;
V_10 -> V_8 = V_44 ;
} else {
F_7 ( & V_33 -> V_2 , L_12 ) ;
V_10 -> V_8 = V_16 ;
}
F_5 ( & V_10 -> V_11 ) ;
}
static void F_31 ( struct V_32 * V_10 )
{
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_8 = V_44 ;
F_5 ( & V_10 -> V_11 ) ;
}
static struct V_6 * F_32 ( struct V_41 * V_33 ,
struct V_45 * V_43 )
{
struct V_6 * V_7 ;
int V_46 = F_33 ( V_43 ) ;
int V_47 = F_34 ( V_43 ) ;
F_17 ( & V_43 -> V_2 , L_13 ) ;
V_7 = F_35 ( sizeof( struct V_6 ) , V_48 ) ;
if ( ! V_7 ) {
F_3 ( & V_43 -> V_2 , L_14 ) ;
return NULL ;
}
V_7 -> V_43 = F_36 ( V_43 ) ;
V_7 -> V_33 = F_37 ( V_33 ) ;
V_7 -> V_49 = ( V_46 << 16 ) | V_47 ;
V_7 -> V_10 . V_50 = V_51 ;
V_7 -> V_10 . V_8 = V_16 ;
F_38 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_18 = NULL ;
F_39 ( & V_7 -> V_52 ) ;
F_39 ( & V_7 -> V_53 ) ;
F_39 ( & V_7 -> V_54 ) ;
F_39 ( & V_7 -> V_55 ) ;
F_39 ( & V_7 -> V_56 ) ;
F_38 ( & V_7 -> V_39 ) ;
F_40 ( & V_7 -> V_57 ) ;
V_7 -> V_10 . V_58 . V_59 = F_15 ;
V_7 -> V_10 . V_58 . V_60 = F_27 ;
V_7 -> V_10 . V_58 . V_61 = F_31 ;
F_41 ( & V_7 -> V_10 ) ;
F_17 ( & V_43 -> V_2 , L_15 ) ;
return V_7 ;
}
static int F_42 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return - V_17 ;
F_25 ( V_7 ) ;
F_43 ( L_16 ) ;
return 0 ;
}
static int F_44 ( struct V_45 * V_43 ,
const struct V_62 * V_63 )
{
struct V_41 * V_33 = F_45 ( V_43 ) ;
struct V_6 * V_7 = NULL ;
const char * V_64 = F_46 ( V_43 -> V_2 . V_65 ) ;
int V_25 = 0 ;
struct V_66 * V_67 ;
F_17 ( & V_43 -> V_2 , L_17 ) ;
V_67 = F_47 ( V_64 ) ;
if ( ! V_67 || ( V_67 -> V_8 == V_68 ) ||
( V_67 -> V_8 == V_69 ) ) {
F_7 ( & V_43 -> V_2 , L_18
L_19 , V_64 ) ;
return - V_9 ;
}
if ( V_33 -> V_70 . V_71 == V_72 ) {
F_17 ( & V_33 -> V_2 , L_20 ,
V_64 ) ;
return - V_9 ;
}
if ( ! strcmp ( V_33 -> V_73 -> V_74 , L_21 ) ) {
F_17 ( & V_33 -> V_2 , L_22 ,
V_64 ) ;
return - V_9 ;
}
if ( V_67 -> V_8 == V_75 ) {
V_7 = V_67 -> V_7 ;
if ( ! V_7 )
return - V_9 ;
V_67 -> V_76 ++ ;
F_7 ( & V_43 -> V_2 , L_23
L_24 ,
V_33 -> V_73 -> V_46 , V_33 -> V_47 ,
V_43 -> V_77 -> V_78 . V_79 ) ;
F_48 ( V_43 , V_7 ) ;
V_25 = F_11 ( & V_43 -> V_2 ) ;
if ( V_25 ) {
F_3 ( & V_43 -> V_2 , L_25 ,
V_64 ) ;
F_48 ( V_43 , NULL ) ;
V_67 -> V_76 -- ;
return V_25 ;
}
F_36 ( V_43 ) ;
return 0 ;
}
V_7 = F_32 ( V_33 , V_43 ) ;
if ( ! V_7 )
return - V_80 ;
F_7 ( & V_43 -> V_2 , L_26
L_24 , V_33 -> V_73 -> V_46 , V_33 -> V_47 ,
V_43 -> V_77 -> V_78 . V_79 ) ;
V_67 -> V_76 = 0 ;
V_67 -> V_81 = 0 ;
F_48 ( V_43 , V_7 ) ;
V_67 -> V_76 ++ ;
V_67 -> V_7 = V_7 ;
V_25 = F_11 ( & V_43 -> V_2 ) ;
if ( V_25 ) {
F_3 ( & V_43 -> V_2 , L_25 , V_64 ) ;
F_48 ( V_43 , NULL ) ;
F_49 ( V_43 ) ;
V_67 -> V_76 = 0 ;
V_67 -> V_7 = NULL ;
F_42 ( V_7 ) ;
return V_25 ;
}
V_67 -> V_8 = V_75 ;
return 0 ;
}
static void V_81 ( struct V_66 * V_67 )
{
if ( V_67 -> V_7 && ! V_67 -> V_81 ) {
V_67 -> V_81 = 1 ;
F_10 ( & V_67 -> V_7 -> V_10 , V_82 ) ;
F_50 ( & V_67 -> V_7 -> V_10 ) ;
}
}
static void F_51 ( struct V_45 * V_43 )
{
struct V_6 * V_7 ;
const char * V_64 = F_46 ( V_43 -> V_2 . V_65 ) ;
struct V_66 * V_67 ;
F_17 ( & V_43 -> V_2 , L_17 ) ;
V_67 = F_47 ( V_64 ) ;
if ( ! V_67 ) {
F_52 () ;
return;
}
V_7 = F_53 ( V_43 ) ;
if ( ! V_7 ) {
F_3 ( & V_43 -> V_2 , L_27 ) ;
return;
}
F_48 ( V_43 , NULL ) ;
F_14 ( & V_43 -> V_2 ) ;
if ( V_67 -> V_7 -> V_10 . V_83 == V_84 ) {
V_67 -> V_76 -- ;
return;
}
if ( V_67 -> V_76 > 1 ) {
V_67 -> V_76 -- ;
V_81 ( V_67 ) ;
F_49 ( V_43 ) ;
return;
}
V_67 -> V_76 = 0 ;
V_81 ( V_67 ) ;
F_54 ( V_7 -> V_33 ) ;
F_49 ( V_43 ) ;
V_67 -> V_7 = NULL ;
F_42 ( V_7 ) ;
if ( V_67 -> V_8 == V_75 ) {
V_67 -> V_8 = V_85 ;
} else {
V_67 -> V_8 = V_69 ;
F_55 ( ( char * ) V_64 ) ;
}
}
int F_56 ( struct V_45 * V_43 )
{
F_17 ( & V_43 -> V_2 , L_28 ) ;
return 0 ;
}
int F_57 ( struct V_45 * V_43 )
{
F_17 ( & V_43 -> V_2 , L_29 ) ;
return 0 ;
}
