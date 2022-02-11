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
F_9 ( L_6 ) ;
return - V_9 ;
}
} else {
if ( F_21 ( V_26 , V_27 ,
V_29 -> V_33 , V_29 -> V_32 ,
V_29 -> type ) ) {
F_9 ( L_6 ) ;
return - V_9 ;
}
}
return 0 ;
}
static int F_22 ( struct V_25 * V_26 ,
struct V_15 * V_16 )
{
struct V_28 V_29 ;
struct V_28 * V_34 ;
struct V_35 V_27 , * V_36 ;
V_36 = V_16 -> V_37 ;
while ( V_36 ) {
if ( F_18 ( & V_27 , ( void V_23 * ) V_36 ,
sizeof( * V_36 ) ) ) {
F_9 ( L_7 ) ;
goto V_38;
}
if ( F_23 ( V_26 , V_27 . V_39 ) ) {
F_9 ( L_8 ) ;
goto V_38;
}
V_34 = V_36 -> V_40 ;
while ( V_34 ) {
if ( F_18 ( & V_29 , ( void V_23 * ) V_34 ,
sizeof( V_29 ) ) ) {
F_9 ( L_9 ) ;
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
F_24 ( V_26 ) ;
return - V_9 ;
}
static int F_25 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
V_26 = F_26 ( V_16 -> V_21 ) ;
if ( ! V_26 ) {
V_45 = - V_9 ;
goto V_46;
}
if ( F_27 ( V_26 ) ) {
V_45 = - V_9 ;
goto V_46;
}
if ( F_22 ( V_26 , V_16 ) ) {
V_45 = - V_9 ;
goto V_46;
}
F_28 ( V_47 , & V_26 -> V_48 ) ;
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_29 ( int V_49 )
{
struct V_50 * V_51 , * V_52 = F_30 () ;
F_31 (itr, head) {
struct V_25 * V_53 =
F_32 ( V_51 , struct V_25 , V_54 ) ;
if ( V_49 == V_53 -> V_55 || V_49 == V_56 ) {
if ( F_33 ( V_53 ) || F_34 ( V_53 ) ) {
F_35 ( L_10 ,
V_53 -> V_55 ) ;
return - V_57 ;
}
}
}
return 0 ;
}
static int F_36 ( T_2 V_49 )
{
struct V_50 * V_51 , * V_52 = F_30 () ;
int V_45 = 0 ;
F_31 (itr, head) {
struct V_25 * V_26 =
F_32 ( V_51 , struct V_25 , V_54 ) ;
if ( V_49 == V_26 -> V_55 || V_49 == V_56 ) {
if ( ! F_27 ( V_26 ) )
continue;
if ( F_37 ( V_26 ) ) {
F_9 ( L_11 , V_49 ) ;
V_45 = - V_9 ;
}
}
}
return V_45 ;
}
static int F_38 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
if ( F_39 ( V_16 -> V_21 ) ) {
F_9 ( L_12 , V_16 -> V_21 ) ;
V_45 = - V_58 ;
goto V_46;
}
V_45 = F_29 ( V_16 -> V_21 ) ;
if ( V_45 )
goto V_46;
if ( V_16 -> V_21 == V_56 )
F_35 ( L_13 ) ;
else
F_35 ( L_14 ,
V_16 -> V_21 ) ;
V_45 = F_36 ( V_16 -> V_21 ) ;
if ( V_45 )
F_9 ( L_15 ) ;
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_40 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
struct V_25 * V_26 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
V_26 = F_26 ( V_16 -> V_21 ) ;
if ( ! V_26 ) {
F_9 ( L_12 , V_16 -> V_21 ) ;
V_45 = - V_58 ;
goto V_46;
}
if ( ! F_27 ( V_26 ) ) {
F_35 ( L_16 ,
V_16 -> V_21 ) ;
V_45 = F_41 ( V_26 ) ;
} else {
F_35 ( L_17 ,
V_16 -> V_21 ) ;
}
if ( V_45 ) {
F_9 ( L_18 , V_16 -> V_21 ) ;
F_37 ( V_26 ) ;
}
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_42 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
T_2 V_59 = 0 ;
F_43 ( & V_59 ) ;
if ( F_44 ( ( void V_23 * ) V_17 , & V_59 , sizeof( V_59 ) ) )
return - V_9 ;
return 0 ;
}
static int F_45 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
struct V_60 * V_61 ;
struct V_62 V_63 ;
struct V_25 * V_26 ;
if ( F_18 ( & V_63 , ( void V_23 * ) V_17 ,
sizeof( struct V_62 ) ) ) {
F_9 ( L_19 ) ;
return - V_9 ;
}
V_26 = F_26 ( V_63 . V_55 ) ;
if ( ! V_26 ) {
F_9 ( L_12 , V_63 . V_55 ) ;
return - V_58 ;
}
V_61 = V_26 -> V_64 ;
V_63 . V_65 = F_27 ( V_26 ) ? V_66 : V_67 ;
V_63 . V_68 = V_61 -> V_69 ( V_61 ) ;
V_63 . V_70 = V_61 -> V_71 ( V_61 ) ;
V_63 . V_72 = V_61 -> V_72 ;
V_63 . V_73 = V_61 -> V_74
/ V_61 -> V_72 ;
F_46 ( V_63 . V_39 , V_61 -> V_75 -> V_39 , sizeof( V_63 . V_39 ) ) ;
V_63 . V_76 = V_61 -> V_76 ;
V_63 . type = V_61 -> V_75 -> type ;
V_63 . V_77 = F_47 ( V_26 ) -> V_77 -> V_78 ;
V_63 . V_53 = F_48 ( F_47 ( V_26 ) -> V_79 ) ;
V_63 . V_80 = F_49 ( F_47 ( V_26 ) -> V_79 ) ;
if ( F_44 ( ( void V_23 * ) V_17 , & V_63 ,
sizeof( struct V_62 ) ) ) {
F_9 ( L_20 ) ;
return - V_9 ;
}
return 0 ;
}
static long F_50 ( struct V_42 * V_43 , unsigned int V_44 , unsigned long V_17 )
{
int V_45 ;
if ( F_51 ( & V_81 ) )
return - V_9 ;
switch ( V_44 ) {
case V_82 :
V_45 = F_25 ( V_43 , V_44 , V_17 ) ;
break;
case V_83 :
V_45 = F_38 ( V_43 , V_44 , V_17 ) ;
break;
case V_84 :
V_45 = F_40 ( V_43 , V_44 , V_17 ) ;
break;
case V_85 :
V_45 = F_42 ( V_43 , V_44 , V_17 ) ;
break;
case V_86 :
V_45 = F_45 ( V_43 , V_44 , V_17 ) ;
break;
default:
F_9 ( L_21 ) ;
V_45 = - V_9 ;
break;
}
F_52 ( & V_81 ) ;
return V_45 ;
}
static int T_3 F_53 ( void )
{
F_54 ( & V_81 ) ;
if ( F_55 () )
goto V_87;
if ( F_7 () )
goto V_88;
if ( F_56 () )
goto V_89;
if ( F_57 () )
goto V_90;
return 0 ;
V_90:
F_58 () ;
V_89:
F_1 () ;
V_88:
F_59 () ;
V_87:
F_60 ( & V_81 ) ;
return - V_9 ;
}
static void T_4 F_61 ( void )
{
F_1 () ;
F_58 () ;
F_62 () ;
F_59 () ;
F_60 ( & V_81 ) ;
}
