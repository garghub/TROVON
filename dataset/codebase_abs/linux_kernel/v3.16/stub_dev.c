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
int V_16 ;
if ( ! V_7 ) {
F_3 ( V_2 , L_1 ) ;
return - V_9 ;
}
V_16 = sscanf ( V_5 , L_3 , & V_14 ) ;
if ( V_16 != 1 )
return - V_17 ;
if ( V_14 != - 1 ) {
int V_18 ;
F_7 ( V_2 , L_4 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
if ( V_7 -> V_10 . V_8 != V_19 ) {
F_3 ( V_2 , L_5 ) ;
goto V_18;
}
V_15 = F_8 ( V_14 , & V_18 ) ;
if ( ! V_15 )
goto V_18;
V_7 -> V_10 . V_20 = V_15 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_21 = F_9 ( V_22 , & V_7 -> V_10 ,
L_6 ) ;
V_7 -> V_10 . V_23 = F_9 ( V_24 , & V_7 -> V_10 ,
L_7 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_8 = V_25 ;
F_5 ( & V_7 -> V_10 . V_11 ) ;
} else {
F_7 ( V_2 , L_8 ) ;
F_4 ( & V_7 -> V_10 . V_11 ) ;
if ( V_7 -> V_10 . V_8 != V_25 )
goto V_18;
F_5 ( & V_7 -> V_10 . V_11 ) ;
F_10 ( & V_7 -> V_10 , V_26 ) ;
}
return V_13 ;
V_18:
F_5 ( & V_7 -> V_10 . V_11 ) ;
return - V_17 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
V_18 = F_12 ( V_2 , & V_27 ) ;
if ( V_18 )
goto V_28;
V_18 = F_12 ( V_2 , & V_29 ) ;
if ( V_18 )
goto V_30;
V_18 = F_12 ( V_2 , & V_31 ) ;
if ( V_18 )
goto V_32;
return 0 ;
V_32:
F_13 ( V_2 , & V_29 ) ;
V_30:
F_13 ( V_2 , & V_27 ) ;
V_28:
return V_18 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 , & V_27 ) ;
F_13 ( V_2 , & V_29 ) ;
F_13 ( V_2 , & V_31 ) ;
}
static void F_15 ( struct V_33 * V_10 )
{
struct V_6 * V_7 = F_16 ( V_10 , struct V_6 , V_10 ) ;
if ( V_10 -> V_20 ) {
F_17 ( & V_7 -> V_34 -> V_2 , L_9 ,
V_10 -> V_20 ) ;
F_18 ( V_10 -> V_20 , V_35 ) ;
}
if ( V_10 -> V_21 ) {
F_19 ( V_10 -> V_21 ) ;
V_10 -> V_21 = NULL ;
}
if ( V_10 -> V_23 ) {
F_19 ( V_10 -> V_23 ) ;
V_10 -> V_23 = NULL ;
}
if ( V_10 -> V_20 ) {
F_20 ( V_10 -> V_20 ) ;
V_10 -> V_20 = NULL ;
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
static void F_27 ( struct V_33 * V_10 )
{
struct V_6 * V_7 = F_16 ( V_10 , struct V_6 , V_10 ) ;
struct V_42 * V_34 = V_7 -> V_34 ;
int V_43 ;
F_17 ( & V_34 -> V_2 , L_10 ) ;
V_43 = F_28 ( V_34 , V_7 -> V_44 ) ;
if ( V_43 < 0 ) {
F_3 ( & V_34 -> V_2 , L_11 ) ;
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_8 = V_45 ;
F_5 ( & V_10 -> V_11 ) ;
return;
}
V_43 = F_29 ( V_34 ) ;
F_30 ( V_34 ) ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_43 ) {
F_3 ( & V_34 -> V_2 , L_12 ) ;
V_10 -> V_8 = V_45 ;
} else {
F_7 ( & V_34 -> V_2 , L_12 ) ;
V_10 -> V_8 = V_19 ;
}
F_5 ( & V_10 -> V_11 ) ;
}
static void F_31 ( struct V_33 * V_10 )
{
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_8 = V_45 ;
F_5 ( & V_10 -> V_11 ) ;
}
static struct V_6 * F_32 ( struct V_42 * V_34 )
{
struct V_6 * V_7 ;
int V_46 = V_34 -> V_47 -> V_46 ;
int V_48 = V_34 -> V_48 ;
F_17 ( & V_34 -> V_2 , L_13 ) ;
V_7 = F_33 ( sizeof( struct V_6 ) , V_49 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_34 = F_34 ( V_34 ) ;
V_7 -> V_50 = ( V_46 << 16 ) | V_48 ;
V_7 -> V_10 . V_51 = V_52 ;
V_7 -> V_10 . V_8 = V_19 ;
F_35 ( & V_7 -> V_10 . V_11 ) ;
V_7 -> V_10 . V_20 = NULL ;
F_36 ( & V_7 -> V_53 ) ;
F_36 ( & V_7 -> V_54 ) ;
F_36 ( & V_7 -> V_55 ) ;
F_36 ( & V_7 -> V_56 ) ;
F_36 ( & V_7 -> V_57 ) ;
F_35 ( & V_7 -> V_40 ) ;
F_37 ( & V_7 -> V_58 ) ;
V_7 -> V_10 . V_59 . V_60 = F_15 ;
V_7 -> V_10 . V_59 . V_61 = F_27 ;
V_7 -> V_10 . V_59 . V_62 = F_31 ;
F_38 ( & V_7 -> V_10 ) ;
F_17 ( & V_34 -> V_2 , L_14 ) ;
return V_7 ;
}
static void F_39 ( struct V_6 * V_7 )
{
F_25 ( V_7 ) ;
}
static int F_40 ( struct V_42 * V_34 )
{
struct V_6 * V_7 = NULL ;
const char * V_63 = F_41 ( & V_34 -> V_2 ) ;
int V_18 = 0 ;
struct V_64 * V_65 ;
int V_66 ;
F_17 ( & V_34 -> V_2 , L_15 ) ;
V_65 = F_42 ( V_63 ) ;
if ( ! V_65 || ( V_65 -> V_8 == V_67 ) ||
( V_65 -> V_8 == V_68 ) ) {
F_7 ( & V_34 -> V_2 ,
L_16 ,
V_63 ) ;
return - V_9 ;
}
if ( V_34 -> V_69 . V_70 == V_71 ) {
F_17 ( & V_34 -> V_2 , L_17 ,
V_63 ) ;
return - V_9 ;
}
if ( ! strcmp ( V_34 -> V_47 -> V_72 , L_18 ) ) {
F_17 ( & V_34 -> V_2 ,
L_19 ,
V_63 ) ;
return - V_9 ;
}
V_7 = F_32 ( V_34 ) ;
if ( ! V_7 )
return - V_73 ;
F_7 ( & V_34 -> V_2 ,
L_20 ,
V_34 -> V_47 -> V_46 , V_34 -> V_48 ) ;
V_65 -> V_74 = 0 ;
F_43 ( & V_34 -> V_2 , V_7 ) ;
V_65 -> V_7 = V_7 ;
V_65 -> V_34 = V_34 ;
V_66 = F_44 ( V_34 -> V_75 , V_34 -> V_76 ,
(struct V_77 * ) V_34 ) ;
if ( V_66 ) {
F_17 ( & V_34 -> V_2 , L_21 ) ;
return V_66 ;
}
V_18 = F_11 ( & V_34 -> V_2 ) ;
if ( V_18 ) {
F_3 ( & V_34 -> V_2 , L_22 , V_63 ) ;
F_43 ( & V_34 -> V_2 , NULL ) ;
F_45 ( V_34 ) ;
F_19 ( V_7 -> V_10 . V_78 ) ;
V_65 -> V_7 = NULL ;
F_39 ( V_7 ) ;
return V_18 ;
}
V_65 -> V_8 = V_79 ;
return 0 ;
}
static void V_74 ( struct V_64 * V_65 )
{
if ( V_65 -> V_7 && ! V_65 -> V_74 ) {
V_65 -> V_74 = 1 ;
F_10 ( & V_65 -> V_7 -> V_10 , V_80 ) ;
F_46 ( & V_65 -> V_7 -> V_10 ) ;
}
}
static void F_47 ( struct V_42 * V_34 )
{
struct V_6 * V_7 ;
const char * V_63 = F_41 ( & V_34 -> V_2 ) ;
struct V_64 * V_65 ;
int V_66 ;
F_17 ( & V_34 -> V_2 , L_15 ) ;
V_65 = F_42 ( V_63 ) ;
if ( ! V_65 ) {
F_48 () ;
return;
}
V_7 = F_2 ( & V_34 -> V_2 ) ;
if ( ! V_7 ) {
F_3 ( & V_34 -> V_2 , L_23 ) ;
return;
}
F_43 ( & V_34 -> V_2 , NULL ) ;
F_14 ( & V_34 -> V_2 ) ;
V_66 = F_49 ( V_34 -> V_75 , V_34 -> V_76 ,
(struct V_77 * ) V_34 ) ;
if ( V_66 ) {
F_17 ( & V_34 -> V_2 , L_24 ) ;
return;
}
if ( V_65 -> V_7 -> V_10 . V_78 == V_81 )
return;
V_74 ( V_65 ) ;
F_45 ( V_7 -> V_34 ) ;
V_65 -> V_7 = NULL ;
F_39 ( V_7 ) ;
if ( V_65 -> V_8 == V_79 ) {
V_65 -> V_8 = V_82 ;
} else {
V_65 -> V_8 = V_68 ;
F_50 ( ( char * ) V_63 ) ;
}
}
static int F_51 ( struct V_42 * V_34 , T_3 V_83 )
{
F_17 ( & V_34 -> V_2 , L_25 ) ;
return 0 ;
}
static int F_52 ( struct V_42 * V_34 , T_3 V_83 )
{
F_17 ( & V_34 -> V_2 , L_26 ) ;
return 0 ;
}
