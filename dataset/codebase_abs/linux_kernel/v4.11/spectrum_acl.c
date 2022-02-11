struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static struct V_5 *
F_2 ( struct V_6 * V_6 ,
const struct V_7 * V_8 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_5 * V_9 ;
T_1 V_10 ;
int V_11 ;
V_10 = sizeof( * V_9 ) + V_8 -> V_12 ;
V_9 = F_3 ( V_10 , V_13 ) ;
if ( ! V_9 )
return F_4 ( - V_14 ) ;
V_9 -> V_15 = 1 ;
V_9 -> V_16 . V_8 = V_8 ;
V_11 = F_5 ( & V_9 -> V_17 , & V_18 ) ;
if ( V_11 )
goto V_19;
V_11 = V_8 -> V_20 ( V_6 , V_3 -> V_21 , V_9 -> V_21 ) ;
if ( V_11 )
goto V_22;
return V_9 ;
V_22:
F_6 ( & V_9 -> V_17 ) ;
V_19:
F_7 ( V_9 ) ;
return F_4 ( V_11 ) ;
}
static void F_8 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
V_8 -> V_23 ( V_6 , V_9 -> V_21 ) ;
F_6 ( & V_9 -> V_17 ) ;
F_7 ( V_9 ) ;
}
static int F_9 ( struct V_6 * V_6 ,
struct V_5 * V_9 ,
struct V_24 * V_25 , bool V_26 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
int V_11 ;
V_9 -> V_16 . V_25 = V_25 ;
V_9 -> V_16 . V_26 = V_26 ;
V_11 = F_10 ( & V_3 -> V_27 , & V_9 -> V_28 ,
V_29 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_8 -> V_30 ( V_6 , V_9 -> V_21 , V_25 , V_26 ) ;
if ( V_11 )
goto V_31;
return 0 ;
V_31:
F_11 ( & V_3 -> V_27 , & V_9 -> V_28 ,
V_29 ) ;
return V_11 ;
}
static void F_12 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
V_8 -> V_32 ( V_6 , V_9 -> V_21 ) ;
F_11 ( & V_3 -> V_27 , & V_9 -> V_28 ,
V_29 ) ;
}
static void F_13 ( struct V_5 * V_9 )
{
V_9 -> V_15 ++ ;
}
static void F_14 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
if ( -- V_9 -> V_15 )
return;
F_12 ( V_6 , V_9 ) ;
F_8 ( V_6 , V_9 ) ;
}
struct V_5 *
F_15 ( struct V_6 * V_6 ,
struct V_24 * V_25 , bool V_26 ,
enum V_33 V_34 )
{
const struct V_7 * V_8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_35 V_16 ;
struct V_5 * V_9 ;
int V_11 ;
V_8 = V_3 -> V_8 -> V_36 ( V_6 , V_34 ) ;
if ( ! V_8 )
return F_4 ( - V_37 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_25 = V_25 ;
V_16 . V_26 = V_26 ;
V_16 . V_8 = V_8 ;
V_9 = F_16 ( & V_3 -> V_27 , & V_16 ,
V_29 ) ;
if ( V_9 ) {
F_13 ( V_9 ) ;
return V_9 ;
}
V_9 = F_2 ( V_6 , V_8 ) ;
if ( F_17 ( V_9 ) )
return V_9 ;
V_11 = F_9 ( V_6 , V_9 , V_25 , V_26 ) ;
if ( V_11 )
goto V_38;
return V_9 ;
V_38:
F_8 ( V_6 , V_9 ) ;
return F_4 ( V_11 ) ;
}
void F_18 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
F_14 ( V_6 , V_9 ) ;
}
struct V_39 *
F_19 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
int V_11 ;
V_40 = F_3 ( sizeof( * V_40 ) , V_13 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_41 = F_20 ( V_3 -> V_42 ) ;
if ( F_17 ( V_40 -> V_41 ) ) {
V_11 = F_21 ( V_40 -> V_41 ) ;
goto V_43;
}
return V_40 ;
V_43:
F_7 ( V_40 ) ;
return F_4 ( V_11 ) ;
}
void F_22 ( struct V_39 * V_40 )
{
F_23 ( V_40 -> V_41 ) ;
F_7 ( V_40 ) ;
}
int F_24 ( struct V_39 * V_40 )
{
return F_25 ( V_40 -> V_41 ) ;
}
void F_26 ( struct V_39 * V_40 ,
unsigned int V_44 )
{
V_40 -> V_44 = V_44 ;
}
void F_27 ( struct V_39 * V_40 ,
enum V_45 V_46 ,
T_2 V_47 , T_2 V_48 )
{
F_28 ( & V_40 -> V_49 , V_46 ,
V_47 , V_48 ) ;
}
void F_29 ( struct V_39 * V_40 ,
enum V_45 V_46 ,
const char * V_47 ,
const char * V_48 , unsigned int V_50 )
{
F_30 ( & V_40 -> V_49 , V_46 ,
V_47 , V_48 , V_50 ) ;
}
void F_31 ( struct V_39 * V_40 )
{
F_32 ( V_40 -> V_41 ) ;
}
void F_33 ( struct V_39 * V_40 ,
T_3 V_51 )
{
F_34 ( V_40 -> V_41 , V_51 ) ;
}
int F_35 ( struct V_39 * V_40 )
{
return F_36 ( V_40 -> V_41 ) ;
}
int F_37 ( struct V_6 * V_6 ,
struct V_39 * V_40 ,
struct V_24 * V_52 )
{
struct V_53 * V_53 ;
T_4 V_54 ;
bool V_55 ;
if ( V_52 ) {
if ( ! F_38 ( V_52 ) )
return - V_37 ;
V_53 = F_39 ( V_52 ) ;
if ( V_53 -> V_6 != V_6 )
return - V_37 ;
V_54 = V_53 -> V_54 ;
V_55 = false ;
} else {
V_54 = 0 ;
V_55 = true ;
}
return F_40 ( V_40 -> V_41 ,
V_54 , V_55 ) ;
}
struct V_56 *
F_41 ( struct V_6 * V_6 ,
struct V_5 * V_9 ,
unsigned long V_57 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
struct V_56 * V_58 ;
int V_11 ;
F_13 ( V_9 ) ;
V_58 = F_3 ( sizeof( * V_58 ) + V_8 -> V_59 , V_13 ) ;
if ( ! V_58 ) {
V_11 = - V_14 ;
goto V_60;
}
V_58 -> V_57 = V_57 ;
V_58 -> V_9 = V_9 ;
V_58 -> V_40 = F_19 ( V_6 -> V_3 ) ;
if ( F_17 ( V_58 -> V_40 ) ) {
V_11 = F_21 ( V_58 -> V_40 ) ;
goto V_61;
}
return V_58 ;
V_61:
F_7 ( V_58 ) ;
V_60:
F_14 ( V_6 , V_9 ) ;
return F_4 ( V_11 ) ;
}
void F_42 ( struct V_6 * V_6 ,
struct V_56 * V_58 )
{
struct V_5 * V_9 = V_58 -> V_9 ;
F_22 ( V_58 -> V_40 ) ;
F_7 ( V_58 ) ;
F_14 ( V_6 , V_9 ) ;
}
int F_43 ( struct V_6 * V_6 ,
struct V_56 * V_58 )
{
struct V_5 * V_9 = V_58 -> V_9 ;
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
int V_11 ;
V_11 = V_8 -> V_62 ( V_6 , V_9 -> V_21 , V_58 -> V_21 , V_58 -> V_40 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_10 ( & V_9 -> V_17 , & V_58 -> V_28 ,
V_18 ) ;
if ( V_11 )
goto V_63;
return 0 ;
V_63:
V_8 -> V_64 ( V_6 , V_58 -> V_21 ) ;
return V_11 ;
}
void F_44 ( struct V_6 * V_6 ,
struct V_56 * V_58 )
{
struct V_5 * V_9 = V_58 -> V_9 ;
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
F_11 ( & V_9 -> V_17 , & V_58 -> V_28 ,
V_18 ) ;
V_8 -> V_64 ( V_6 , V_58 -> V_21 ) ;
}
struct V_56 *
F_45 ( struct V_6 * V_6 ,
struct V_5 * V_9 ,
unsigned long V_57 )
{
return F_16 ( & V_9 -> V_17 , & V_57 ,
V_18 ) ;
}
struct V_39 *
F_46 ( struct V_56 * V_58 )
{
return V_58 -> V_40 ;
}
static int F_47 ( void * V_21 , T_2 * V_65 ,
char * V_66 , bool V_67 )
{
struct V_6 * V_6 = V_21 ;
char V_68 [ V_69 ] ;
T_2 V_70 ;
int V_71 ;
int V_11 ;
if ( V_67 )
return 0 ;
V_71 = F_48 ( V_6 , V_72 ) ;
if ( V_71 < 0 )
return V_71 ;
V_70 = V_71 ;
F_49 ( V_68 , V_70 , V_66 ) ;
V_11 = F_50 ( V_6 -> V_73 , F_51 ( V_74 ) , V_68 ) ;
if ( V_11 )
goto V_75;
* V_65 = V_70 ;
return 0 ;
V_75:
F_52 ( V_6 , V_70 ) ;
return V_11 ;
}
static void F_53 ( void * V_21 , T_2 V_70 ,
bool V_67 )
{
struct V_6 * V_6 = V_21 ;
if ( V_67 )
return;
F_52 ( V_6 , V_70 ) ;
}
static int F_54 ( void * V_21 , T_2 * V_65 ,
T_4 V_54 )
{
struct V_6 * V_6 = V_21 ;
char V_76 [ V_77 ] ;
T_2 V_70 ;
int V_71 ;
int V_11 ;
V_71 = F_48 ( V_6 , 1 ) ;
if ( V_71 < 0 )
return V_71 ;
V_70 = V_71 ;
F_55 ( V_76 , V_70 , V_54 ) ;
V_11 = F_50 ( V_6 -> V_73 , F_51 ( V_78 ) , V_76 ) ;
if ( V_11 )
goto V_79;
* V_65 = V_70 ;
return 0 ;
V_79:
F_52 ( V_6 , V_70 ) ;
return V_11 ;
}
static void F_56 ( void * V_21 , T_2 V_70 )
{
struct V_6 * V_6 = V_21 ;
F_52 ( V_6 , V_70 ) ;
}
int F_57 ( struct V_6 * V_6 )
{
const struct V_80 * V_81 = & V_82 ;
struct V_2 * V_3 ;
int V_11 ;
V_3 = F_3 ( sizeof( * V_3 ) + V_81 -> V_83 , V_13 ) ;
if ( ! V_3 )
return - V_14 ;
V_6 -> V_3 = V_3 ;
V_3 -> V_4 = F_58 ( F_59 ( V_6 -> V_73 ,
V_84 ) ,
V_85 ,
V_86 ) ;
if ( ! V_3 -> V_4 ) {
V_11 = - V_14 ;
goto V_87;
}
V_3 -> V_42 = F_60 ( F_59 ( V_6 -> V_73 ,
V_88 ) ,
& V_89 , V_6 ) ;
if ( F_17 ( V_3 -> V_42 ) ) {
V_11 = F_21 ( V_3 -> V_42 ) ;
goto V_90;
}
V_11 = F_5 ( & V_3 -> V_27 ,
& V_29 ) ;
if ( V_11 )
goto V_19;
V_11 = V_81 -> V_91 ( V_6 , V_3 -> V_21 ) ;
if ( V_11 )
goto V_92;
V_3 -> V_8 = V_81 ;
return 0 ;
V_92:
F_6 ( & V_3 -> V_27 ) ;
V_19:
F_61 ( V_3 -> V_42 ) ;
V_90:
F_62 ( V_3 -> V_4 ) ;
V_87:
F_7 ( V_3 ) ;
return V_11 ;
}
void F_63 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
const struct V_80 * V_81 = V_3 -> V_8 ;
V_81 -> V_93 ( V_6 , V_3 -> V_21 ) ;
F_6 ( & V_3 -> V_27 ) ;
F_61 ( V_3 -> V_42 ) ;
F_62 ( V_3 -> V_4 ) ;
F_7 ( V_3 ) ;
}
