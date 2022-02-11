static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
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
T_1 V_16 = - V_17 ;
if ( ! V_7 ) {
F_3 ( V_2 , L_1 ) ;
return - V_9 ;
}
sscanf ( V_5 , L_3 , & V_14 ) ;
if ( V_14 != - 1 ) {
F_7 ( V_2 , L_4 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
if ( V_7 -> V_10 . V_8 != V_18 ) {
F_3 ( V_2 , L_5 ) ;
goto V_16;
}
V_15 = F_8 ( V_14 ) ;
if ( ! V_15 )
goto V_16;
V_7 -> V_10 . V_19 = V_15 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_20 = F_9 ( V_21 , & V_7 -> V_10 ,
L_6 ) ;
V_7 -> V_10 . V_22 = F_9 ( V_23 , & V_7 -> V_10 ,
L_7 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_8 = V_24 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
} else {
F_7 ( V_2 , L_8 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
if ( V_7 -> V_10 . V_8 != V_24 )
goto V_16;
F_5 ( & V_7 -> V_10 . V_11 ) ;
F_10 ( & V_7 -> V_10 , V_25 ) ;
}
return V_13 ;
V_16:
F_5 ( & V_7 -> V_10 . V_11 ) ;
return V_16 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
V_16 = F_12 ( V_2 , & V_26 ) ;
if ( V_16 )
goto V_27;
V_16 = F_12 ( V_2 , & V_28 ) ;
if ( V_16 )
goto V_29;
V_16 = F_12 ( V_2 , & V_30 ) ;
if ( V_16 )
goto V_31;
return 0 ;
V_31:
F_13 ( V_2 , & V_28 ) ;
V_29:
F_13 ( V_2 , & V_26 ) ;
V_27:
return V_16 ;
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
if ( V_10 -> V_19 ) {
F_17 ( & V_7 -> V_33 -> V_2 , L_9 ,
V_10 -> V_19 ) ;
F_18 ( V_10 -> V_19 , V_34 ) ;
}
if ( V_10 -> V_20 ) {
F_19 ( V_10 -> V_20 ) ;
V_10 -> V_20 = NULL ;
}
if ( V_10 -> V_22 ) {
F_19 ( V_10 -> V_22 ) ;
V_10 -> V_22 = NULL ;
}
if ( V_10 -> V_19 ) {
F_20 ( V_10 -> V_19 -> V_35 ) ;
V_10 -> V_19 = NULL ;
}
F_21 ( V_7 ) ;
{
unsigned long V_36 ;
struct V_37 * V_38 , * V_39 ;
F_22 ( & V_7 -> V_40 , V_36 ) ;
F_23 (unlink, tmp, &sdev->unlink_tx, list) {
F_24 ( & V_38 -> V_41 ) ;
F_25 ( V_38 ) ;
}
F_23 (unlink, tmp, &sdev->unlink_free,
list) {
F_24 ( & V_38 -> V_41 ) ;
F_25 ( V_38 ) ;
}
F_26 ( & V_7 -> V_40 , V_36 ) ;
}
}
static void F_27 ( struct V_32 * V_10 )
{
struct V_6 * V_7 = F_16 ( V_10 , struct V_6 , V_10 ) ;
struct V_42 * V_33 = V_7 -> V_33 ;
int V_43 ;
F_17 ( & V_33 -> V_2 , L_10 ) ;
V_43 = F_28 ( V_33 , V_7 -> V_44 ) ;
if ( V_43 < 0 ) {
F_3 ( & V_33 -> V_2 , L_11 ) ;
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_8 = V_45 ;
F_5 ( & V_10 -> V_11 ) ;
return;
}
V_43 = F_29 ( V_33 ) ;
F_30 ( V_33 ) ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_43 ) {
F_3 ( & V_33 -> V_2 , L_12 ) ;
V_10 -> V_8 = V_45 ;
} else {
F_7 ( & V_33 -> V_2 , L_12 ) ;
V_10 -> V_8 = V_18 ;
}
F_5 ( & V_10 -> V_11 ) ;
}
static void F_31 ( struct V_32 * V_10 )
{
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_8 = V_45 ;
F_5 ( & V_10 -> V_11 ) ;
}
static struct V_6 * F_32 ( struct V_42 * V_33 ,
struct V_46 * V_44 )
{
struct V_6 * V_7 ;
int V_47 = F_33 ( V_44 ) ;
int V_48 = F_34 ( V_44 ) ;
F_17 ( & V_44 -> V_2 , L_13 ) ;
V_7 = F_35 ( sizeof( struct V_6 ) , V_49 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_44 = F_36 ( V_44 ) ;
V_7 -> V_33 = F_37 ( V_33 ) ;
V_7 -> V_50 = ( V_47 << 16 ) | V_48 ;
V_7 -> V_10 . V_51 = V_52 ;
V_7 -> V_10 . V_8 = V_18 ;
F_38 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_19 = NULL ;
F_39 ( & V_7 -> V_53 ) ;
F_39 ( & V_7 -> V_54 ) ;
F_39 ( & V_7 -> V_55 ) ;
F_39 ( & V_7 -> V_56 ) ;
F_39 ( & V_7 -> V_57 ) ;
F_38 ( & V_7 -> V_40 ) ;
F_40 ( & V_7 -> V_58 ) ;
V_7 -> V_10 . V_59 . V_60 = F_15 ;
V_7 -> V_10 . V_59 . V_61 = F_27 ;
V_7 -> V_10 . V_59 . V_62 = F_31 ;
F_41 ( & V_7 -> V_10 ) ;
F_17 ( & V_44 -> V_2 , L_14 ) ;
return V_7 ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_25 ( V_7 ) ;
}
static int F_43 ( struct V_46 * V_44 ,
const struct V_63 * V_64 )
{
struct V_42 * V_33 = F_44 ( V_44 ) ;
struct V_6 * V_7 = NULL ;
const char * V_65 = F_45 ( V_44 -> V_2 . V_66 ) ;
int V_16 = 0 ;
struct V_67 * V_68 ;
F_17 ( & V_44 -> V_2 , L_15 ) ;
V_68 = F_46 ( V_65 ) ;
if ( ! V_68 || ( V_68 -> V_8 == V_69 ) ||
( V_68 -> V_8 == V_70 ) ) {
F_7 ( & V_44 -> V_2 , L_16
L_17 , V_65 ) ;
return - V_9 ;
}
if ( V_33 -> V_71 . V_72 == V_73 ) {
F_17 ( & V_33 -> V_2 , L_18 ,
V_65 ) ;
return - V_9 ;
}
if ( ! strcmp ( V_33 -> V_74 -> V_75 , L_19 ) ) {
F_17 ( & V_33 -> V_2 , L_20 ,
V_65 ) ;
return - V_9 ;
}
if ( V_68 -> V_8 == V_76 ) {
V_7 = V_68 -> V_7 ;
if ( ! V_7 )
return - V_9 ;
V_68 -> V_77 ++ ;
F_7 ( & V_44 -> V_2 , L_21
L_22 ,
V_33 -> V_74 -> V_47 , V_33 -> V_48 ,
V_44 -> V_78 -> V_79 . V_80 ) ;
F_47 ( V_44 , V_7 ) ;
V_16 = F_11 ( & V_44 -> V_2 ) ;
if ( V_16 ) {
F_3 ( & V_44 -> V_2 , L_23 ,
V_65 ) ;
F_47 ( V_44 , NULL ) ;
V_68 -> V_77 -- ;
return V_16 ;
}
F_36 ( V_44 ) ;
return 0 ;
}
V_7 = F_32 ( V_33 , V_44 ) ;
if ( ! V_7 )
return - V_81 ;
F_7 ( & V_44 -> V_2 , L_24
L_22 , V_33 -> V_74 -> V_47 , V_33 -> V_48 ,
V_44 -> V_78 -> V_79 . V_80 ) ;
V_68 -> V_77 = 0 ;
V_68 -> V_82 = 0 ;
F_47 ( V_44 , V_7 ) ;
V_68 -> V_77 ++ ;
V_68 -> V_7 = V_7 ;
V_16 = F_11 ( & V_44 -> V_2 ) ;
if ( V_16 ) {
F_3 ( & V_44 -> V_2 , L_23 , V_65 ) ;
F_47 ( V_44 , NULL ) ;
F_48 ( V_44 ) ;
F_49 ( V_33 ) ;
F_19 ( V_7 -> V_10 . V_83 ) ;
V_68 -> V_77 = 0 ;
V_68 -> V_7 = NULL ;
F_42 ( V_7 ) ;
return V_16 ;
}
V_68 -> V_8 = V_76 ;
return 0 ;
}
static void V_82 ( struct V_67 * V_68 )
{
if ( V_68 -> V_7 && ! V_68 -> V_82 ) {
V_68 -> V_82 = 1 ;
F_10 ( & V_68 -> V_7 -> V_10 , V_84 ) ;
F_50 ( & V_68 -> V_7 -> V_10 ) ;
}
}
static void F_51 ( struct V_46 * V_44 )
{
struct V_6 * V_7 ;
const char * V_65 = F_45 ( V_44 -> V_2 . V_66 ) ;
struct V_67 * V_68 ;
F_17 ( & V_44 -> V_2 , L_15 ) ;
V_68 = F_46 ( V_65 ) ;
if ( ! V_68 ) {
F_52 () ;
return;
}
V_7 = F_53 ( V_44 ) ;
if ( ! V_7 ) {
F_3 ( & V_44 -> V_2 , L_25 ) ;
return;
}
F_47 ( V_44 , NULL ) ;
F_14 ( & V_44 -> V_2 ) ;
if ( V_68 -> V_7 -> V_10 . V_83 == V_85 ) {
V_68 -> V_77 -- ;
return;
}
if ( V_68 -> V_77 > 1 ) {
V_68 -> V_77 -- ;
V_82 ( V_68 ) ;
F_48 ( V_44 ) ;
return;
}
V_68 -> V_77 = 0 ;
V_82 ( V_68 ) ;
F_49 ( V_7 -> V_33 ) ;
F_48 ( V_44 ) ;
V_68 -> V_7 = NULL ;
F_42 ( V_7 ) ;
if ( V_68 -> V_8 == V_76 ) {
V_68 -> V_8 = V_86 ;
} else {
V_68 -> V_8 = V_70 ;
F_54 ( ( char * ) V_65 ) ;
}
}
static int F_55 ( struct V_46 * V_44 )
{
F_17 ( & V_44 -> V_2 , L_26 ) ;
return 0 ;
}
static int F_56 ( struct V_46 * V_44 )
{
F_17 ( & V_44 -> V_2 , L_27 ) ;
return 0 ;
}
