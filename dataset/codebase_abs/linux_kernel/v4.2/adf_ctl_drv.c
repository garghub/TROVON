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
V_34 = V_36 -> V_40 ;
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
struct V_50 * V_51 , * V_52 = F_32 () ;
F_33 (itr, head) {
struct V_25 * V_53 =
F_34 ( V_51 , struct V_25 , V_54 ) ;
if ( V_49 == V_53 -> V_55 || V_49 == V_56 ) {
if ( F_35 ( V_53 ) || F_36 ( V_53 ) ) {
F_37 ( & F_23 ( V_53 ) ,
L_11 ,
V_53 -> V_55 ) ;
return - V_57 ;
}
}
}
return 0 ;
}
static int F_38 ( T_2 V_49 )
{
struct V_50 * V_51 , * V_52 = F_32 () ;
int V_45 = 0 ;
F_33 (itr, head) {
struct V_25 * V_26 =
F_34 ( V_51 , struct V_25 , V_54 ) ;
if ( V_49 == V_26 -> V_55 || V_49 == V_56 ) {
if ( ! F_29 ( V_26 ) )
continue;
if ( F_39 ( V_26 ) ) {
F_22 ( & F_23 ( V_26 ) ,
L_12 , V_49 ) ;
V_45 = - V_9 ;
} else {
F_40 ( V_26 ) ;
}
}
}
return V_45 ;
}
static int F_41 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
int V_45 ;
struct V_15 * V_16 ;
V_45 = F_16 ( & V_16 , V_17 ) ;
if ( V_45 )
return V_45 ;
if ( F_42 ( V_16 -> V_21 ) ) {
F_9 ( L_13 , V_16 -> V_21 ) ;
V_45 = - V_58 ;
goto V_46;
}
V_45 = F_31 ( V_16 -> V_21 ) ;
if ( V_45 )
goto V_46;
if ( V_16 -> V_21 == V_56 )
F_43 ( L_14 ) ;
else
F_43 ( L_15 ,
V_16 -> V_21 ) ;
V_45 = F_38 ( V_16 -> V_21 ) ;
if ( V_45 )
F_9 ( L_16 ) ;
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_44 ( struct V_42 * V_43 , unsigned int V_44 ,
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
F_9 ( L_13 , V_16 -> V_21 ) ;
V_45 = - V_58 ;
goto V_46;
}
if ( ! F_29 ( V_26 ) ) {
F_37 ( & F_23 ( V_26 ) ,
L_17 ,
V_16 -> V_21 ) ;
V_45 = F_45 ( V_26 ) ;
if ( ! V_45 )
V_45 = F_46 ( V_26 ) ;
} else {
F_37 ( & F_23 ( V_26 ) ,
L_18 ,
V_16 -> V_21 ) ;
}
if ( V_45 ) {
F_22 ( & F_23 ( V_26 ) , L_19 ,
V_16 -> V_21 ) ;
F_39 ( V_26 ) ;
F_40 ( V_26 ) ;
}
V_46:
F_19 ( V_16 ) ;
return V_45 ;
}
static int F_47 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
T_2 V_59 = 0 ;
F_48 ( & V_59 ) ;
if ( F_49 ( ( void V_23 * ) V_17 , & V_59 , sizeof( V_59 ) ) )
return - V_9 ;
return 0 ;
}
static int F_50 ( struct V_42 * V_43 , unsigned int V_44 ,
unsigned long V_17 )
{
struct V_60 * V_61 ;
struct V_62 F_37 ;
struct V_25 * V_26 ;
if ( F_18 ( & F_37 , ( void V_23 * ) V_17 ,
sizeof( struct V_62 ) ) ) {
F_9 ( L_20 ) ;
return - V_9 ;
}
V_26 = F_28 ( F_37 . V_55 ) ;
if ( ! V_26 ) {
F_9 ( L_13 , F_37 . V_55 ) ;
return - V_58 ;
}
V_61 = V_26 -> V_63 ;
F_37 . V_64 = F_29 ( V_26 ) ? V_65 : V_66 ;
F_37 . V_67 = V_61 -> V_68 ( V_61 ) ;
F_37 . V_69 = V_61 -> V_70 ( V_61 ) ;
F_37 . V_71 = V_61 -> V_71 ;
F_37 . V_72 = V_61 -> V_73
/ V_61 -> V_71 ;
F_51 ( F_37 . V_39 , V_61 -> V_74 -> V_39 , sizeof( F_37 . V_39 ) ) ;
F_37 . V_75 = V_61 -> V_75 ;
F_37 . type = V_61 -> V_74 -> type ;
F_37 . V_76 = F_52 ( V_26 ) -> V_76 -> V_77 ;
F_37 . V_53 = F_53 ( F_52 ( V_26 ) -> V_78 ) ;
F_37 . V_79 = F_54 ( F_52 ( V_26 ) -> V_78 ) ;
if ( F_49 ( ( void V_23 * ) V_17 , & F_37 ,
sizeof( struct V_62 ) ) ) {
F_22 ( & F_23 ( V_26 ) , L_21 ) ;
return - V_9 ;
}
return 0 ;
}
static long F_55 ( struct V_42 * V_43 , unsigned int V_44 , unsigned long V_17 )
{
int V_45 ;
if ( F_56 ( & V_80 ) )
return - V_9 ;
switch ( V_44 ) {
case V_81 :
V_45 = F_27 ( V_43 , V_44 , V_17 ) ;
break;
case V_82 :
V_45 = F_41 ( V_43 , V_44 , V_17 ) ;
break;
case V_83 :
V_45 = F_44 ( V_43 , V_44 , V_17 ) ;
break;
case V_84 :
V_45 = F_47 ( V_43 , V_44 , V_17 ) ;
break;
case V_85 :
V_45 = F_50 ( V_43 , V_44 , V_17 ) ;
break;
default:
F_9 ( L_22 ) ;
V_45 = - V_9 ;
break;
}
F_57 ( & V_80 ) ;
return V_45 ;
}
static int T_3 F_58 ( void )
{
F_59 ( & V_80 ) ;
if ( F_60 () )
goto V_86;
if ( F_7 () )
goto V_87;
if ( F_61 () )
goto V_88;
if ( F_62 () )
goto V_89;
return 0 ;
V_89:
F_63 () ;
V_88:
F_1 () ;
V_87:
F_64 () ;
V_86:
F_65 ( & V_80 ) ;
return - V_9 ;
}
static void T_4 F_66 ( void )
{
F_1 () ;
F_63 () ;
F_67 () ;
F_64 () ;
F_65 ( & V_80 ) ;
}
