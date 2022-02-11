static void F_1 ( void )
{
F_2 ( V_1 . V_2 , F_3 ( V_1 . V_3 , 0 ) ) ;
F_4 ( & V_1 . V_4 ) ;
F_5 ( V_1 . V_2 ) ;
F_6 ( F_3 ( V_1 . V_3 , 0 ) , 1 ) ;
}
static int F_7 ( void )
{
T_1 V_5 ;
struct V_6 * V_7 ;
if ( F_8 ( & V_5 , 0 , 1 , V_8 ) ) {
F_9 ( L_1 ) ;
return - V_9 ;
}
V_1 . V_2 = F_10 ( V_10 , V_8 ) ;
if ( F_11 ( V_1 . V_2 ) ) {
F_9 ( L_2 ) ;
goto V_11;
}
V_1 . V_3 = F_12 ( V_5 ) ;
F_13 ( & V_1 . V_4 , & V_12 ) ;
if ( F_14 ( & V_1 . V_4 , V_5 , 1 ) ) {
F_9 ( L_3 ) ;
goto V_13;
}
V_7 = F_15 ( V_1 . V_2 , NULL ,
F_3 ( V_1 . V_3 , 0 ) ,
NULL , V_8 ) ;
if ( F_11 ( V_7 ) ) {
F_9 ( L_4 ) ;
goto V_14;
}
return 0 ;
V_14:
F_4 ( & V_1 . V_4 ) ;
V_13:
F_5 ( V_1 . V_2 ) ;
V_11:
F_6 ( V_5 , 1 ) ;
return - V_9 ;
}
static int F_16 ( struct V_15 * * V_16 ,
unsigned long V_17 )
{
struct V_15 * V_18 ;
V_18 = F_17 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 )
return - V_20 ;
V_18 -> V_21 = V_22 ;
if ( F_18 ( V_18 , ( void V_23 * ) V_17 , sizeof( * V_18 ) ) ) {
F_9 ( L_5 ) ;
F_19 ( V_18 ) ;
return - V_24 ;
}
* V_16 = V_18 ;
return 0 ;
}
static int F_20 ( struct V_25 * V_26 ,
const char * V_27 ,
const struct V_28 * V_29 )
{
if ( V_29 -> type == V_30 ) {
long * V_31 = ( long * ) V_29 -> V_32 ;
long V_32 = * V_31 ;
if ( F_21 ( V_26 , V_27 ,
V_29 -> V_33 , ( void * ) V_32 ,
V_29 -> type ) ) {
F_22 ( & F_23 ( V_26 ) ,
L_6 ) ;
return - V_9 ;
}
} else {
if ( F_21 ( V_26 , V_27 ,
V_29 -> V_33 , V_29 -> V_32 ,
V_29 -> type ) ) {
F_22 ( & F_23 ( V_26 ) ,
L_7 ) ;
return - V_9 ;
}
}
return 0 ;
}
static int F_24 ( struct V_25 * V_26 ,
struct V_15 * V_16 )
{
struct V_28 V_29 ;
struct V_28 * V_34 ;
struct V_35 V_27 , * V_36 ;
V_36 = V_16 -> V_37 ;
while ( V_36 ) {
if ( F_18 ( & V_27 , ( void V_23 * ) V_36 ,
sizeof( * V_36 ) ) ) {
F_22 ( & F_23 ( V_26 ) ,
L_8 ) ;
goto V_38;
}
if ( F_25 ( V_26 , V_27 . V_39 ) ) {
F_22 ( & F_23 ( V_26 ) ,
L_9 ) ;
goto V_38;
}
V_34 = V_27 . V_40 ;
while ( V_34 ) {
if ( F_18 ( & V_29 , ( void V_23 * ) V_34 ,
sizeof( V_29 ) ) ) {
F_22 ( & F_23 ( V_26 ) ,
L_10 ) ;
goto V_38;
}
if ( F_20 ( V_26 , V_27 . V_39 ,
& V_29 ) ) {
goto V_38;
}
V_34 = V_29 . V_41 ;
}
V_36 = V_27 . V_41 ;
}
return 0 ;
V_38:
F_26 ( V_26 ) ;
return - V_9 ;
}
static int F_27 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
V_26 = F_28 ( V_16 -> V_21 ) ;
if ( ! V_26 ) {
V_45 = - V_9 ;
goto V_46;
}
if ( F_29 ( V_26 ) ) {
V_45 = - V_9 ;
goto V_46;
}
if ( F_24 ( V_26 , V_16 ) ) {
V_45 = - V_9 ;
goto V_46;
}
F_30 ( V_47 , & V_26 -> V_48 ) ;
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_31 ( int V_49 )
{
struct V_25 * V_50 ;
F_32 (dev, adf_devmgr_get_head(), list) {
if ( V_49 == V_50 -> V_51 || V_49 == V_52 ) {
if ( F_33 ( V_50 ) || F_34 ( V_50 ) ) {
F_35 ( & F_23 ( V_50 ) ,
L_11 ,
V_50 -> V_51 ) ;
return - V_53 ;
}
}
}
return 0 ;
}
static void F_36 ( T_2 V_49 )
{
struct V_25 * V_26 ;
F_32 (accel_dev, adf_devmgr_get_head(), list) {
if ( V_49 == V_26 -> V_51 || V_49 == V_52 ) {
if ( ! F_29 ( V_26 ) )
continue;
if ( ! V_26 -> V_54 )
continue;
F_37 ( V_26 ) ;
F_38 ( V_26 ) ;
}
}
F_32 (accel_dev, adf_devmgr_get_head(), list) {
if ( V_49 == V_26 -> V_51 || V_49 == V_52 ) {
if ( ! F_29 ( V_26 ) )
continue;
F_37 ( V_26 ) ;
F_38 ( V_26 ) ;
}
}
}
static int F_39 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
if ( F_40 ( V_16 -> V_21 ) ) {
F_9 ( L_12 , V_16 -> V_21 ) ;
V_45 = - V_55 ;
goto V_46;
}
V_45 = F_31 ( V_16 -> V_21 ) ;
if ( V_45 )
goto V_46;
if ( V_16 -> V_21 == V_52 )
F_41 ( L_13 ) ;
else
F_41 ( L_14 ,
V_16 -> V_21 ) ;
F_36 ( V_16 -> V_21 ) ;
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_42 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
V_45 = - V_55 ;
V_26 = F_28 ( V_16 -> V_21 ) ;
if ( ! V_26 )
goto V_46;
if ( ! F_29 ( V_26 ) ) {
F_35 ( & F_23 ( V_26 ) ,
L_15 ,
V_16 -> V_21 ) ;
V_45 = F_43 ( V_26 ) ;
if ( ! V_45 )
V_45 = F_44 ( V_26 ) ;
} else {
F_35 ( & F_23 ( V_26 ) ,
L_16 ,
V_16 -> V_21 ) ;
}
if ( V_45 ) {
F_22 ( & F_23 ( V_26 ) , L_17 ,
V_16 -> V_21 ) ;
F_37 ( V_26 ) ;
F_38 ( V_26 ) ;
}
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_45 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
T_2 V_56 = 0 ;
F_46 ( & V_56 ) ;
if ( F_47 ( ( void V_23 * ) V_17 , & V_56 , sizeof( V_56 ) ) )
return - V_9 ;
return 0 ;
}
static int F_48 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
struct V_57 * V_58 ;
struct V_59 F_35 ;
struct V_25 * V_26 ;
if ( F_18 ( & F_35 , ( void V_23 * ) V_17 ,
sizeof( struct V_59 ) ) ) {
F_9 ( L_18 ) ;
return - V_9 ;
}
V_26 = F_28 ( F_35 . V_51 ) ;
if ( ! V_26 )
return - V_55 ;
V_58 = V_26 -> V_60 ;
F_35 . V_61 = F_29 ( V_26 ) ? V_62 : V_63 ;
F_35 . V_64 = V_58 -> V_65 ( V_58 ) ;
F_35 . V_66 = V_58 -> V_67 ( V_58 ) ;
F_35 . V_68 = V_58 -> V_68 ;
F_35 . V_69 = V_58 -> V_70
/ V_58 -> V_68 ;
F_49 ( F_35 . V_39 , V_58 -> V_71 -> V_39 , sizeof( F_35 . V_39 ) ) ;
F_35 . V_72 = V_58 -> V_72 ;
F_35 . type = V_58 -> V_71 -> type ;
F_35 . V_73 = F_50 ( V_26 ) -> V_73 -> V_74 ;
F_35 . V_50 = F_51 ( F_50 ( V_26 ) -> V_75 ) ;
F_35 . V_76 = F_52 ( F_50 ( V_26 ) -> V_75 ) ;
if ( F_47 ( ( void V_23 * ) V_17 , & F_35 ,
sizeof( struct V_59 ) ) ) {
F_22 ( & F_23 ( V_26 ) , L_19 ) ;
return - V_9 ;
}
return 0 ;
}
static long F_53 ( struct V_42 * V_43 , unsigned int V_44 , unsigned long V_17 )
{
int V_45 ;
if ( F_54 ( & V_77 ) )
return - V_9 ;
switch ( V_44 ) {
case V_78 :
V_45 = F_27 ( V_43 , V_44 , V_17 ) ;
break;
case V_79 :
V_45 = F_39 ( V_43 , V_44 , V_17 ) ;
break;
case V_80 :
V_45 = F_42 ( V_43 , V_44 , V_17 ) ;
break;
case V_81 :
V_45 = F_45 ( V_43 , V_44 , V_17 ) ;
break;
case V_82 :
V_45 = F_48 ( V_43 , V_44 , V_17 ) ;
break;
default:
F_9 ( L_20 ) ;
V_45 = - V_9 ;
break;
}
F_55 ( & V_77 ) ;
return V_45 ;
}
static int T_3 F_56 ( void )
{
F_57 ( & V_77 ) ;
if ( F_7 () )
goto V_83;
if ( F_58 () )
goto V_84;
if ( F_59 () )
goto V_85;
if ( F_60 () )
goto V_86;
if ( F_61 () )
goto V_87;
return 0 ;
V_87:
F_62 () ;
V_86:
F_63 () ;
V_85:
F_64 () ;
V_84:
F_1 () ;
V_83:
F_65 ( & V_77 ) ;
return - V_9 ;
}
static void T_4 F_66 ( void )
{
F_1 () ;
F_64 () ;
F_62 () ;
F_63 () ;
F_67 () ;
F_68 ( false ) ;
F_65 ( & V_77 ) ;
}
