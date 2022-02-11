void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_5 * V_5 ;
struct V_12 * V_13 ;
V_5 = F_5 ( V_7 ) ;
if ( ! V_5 )
goto V_14;
V_5 -> V_15 = F_6 () ;
F_7 ( V_9 ) ;
V_13 = F_8 ( V_5 ) ;
V_13 -> V_16 = V_9 ;
V_13 -> V_17 = V_11 ;
V_5 -> V_18 = V_5 -> V_19 = V_5 -> V_20 = V_21 ;
V_5 -> V_22 = V_11 -> V_23 ;
if ( ! V_11 -> V_24 ) {
V_5 -> V_22 |= V_25 ;
V_5 -> V_26 = & V_27 ;
V_5 -> V_28 = & V_29 ;
} else {
V_5 -> V_22 |= V_30 ;
F_9 ( V_5 ) ;
V_5 -> V_26 = & V_31 ;
V_5 -> V_28 = & V_32 ;
}
V_14:
return V_5 ;
}
static struct V_10 * F_10 ( struct V_10 * V_33 , struct V_34 * V_35 )
{
int V_36 ;
for ( ; V_33 -> V_37 ; V_33 ++ ) {
if ( ! V_33 -> V_37 )
continue;
V_36 = strlen ( V_33 -> V_37 ) ;
if ( V_36 != V_35 -> V_36 )
continue;
if ( memcmp ( V_33 -> V_37 , V_35 -> V_35 , V_36 ) != 0 )
continue;
return V_33 ;
}
return NULL ;
}
static struct V_8 * F_11 ( struct V_5 * V_5 )
{
if ( F_8 ( V_5 ) -> V_16 )
return F_12 ( F_8 ( V_5 ) -> V_16 ) ;
else
return F_13 ( NULL ) ;
}
static struct V_38 * F_14 ( struct V_5 * V_39 , struct V_38 * V_38 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 = F_11 ( V_39 ) ;
struct V_10 * V_11 = F_8 ( V_39 ) -> V_17 ;
struct V_8 * V_42 = NULL ;
struct V_34 * V_35 = & V_38 -> V_43 ;
struct V_10 * V_33 ;
struct V_5 * V_5 ;
struct V_38 * V_44 = F_15 ( - V_45 ) ;
if ( F_16 ( V_9 ) )
return F_17 ( V_9 ) ;
if ( V_11 && ! V_11 -> V_24 ) {
F_18 ( 1 ) ;
goto V_14;
}
V_11 = V_11 ? V_11 -> V_24 : V_9 -> V_10 ;
V_33 = F_10 ( V_11 , V_35 ) ;
if ( ! V_33 ) {
for ( V_42 = F_13 ( NULL ) ; V_42 ; V_42 = F_13 ( V_42 ) ) {
if ( V_42 -> V_46 != V_11 )
continue;
V_33 = F_10 ( V_42 -> V_47 , V_35 ) ;
if ( V_33 )
break;
}
}
if ( ! V_33 )
goto V_14;
V_44 = F_15 ( - V_48 ) ;
V_5 = F_4 ( V_39 -> V_49 , V_42 ? V_42 : V_9 , V_33 ) ;
if ( V_42 )
F_19 ( V_42 ) ;
if ( ! V_5 )
goto V_14;
V_44 = NULL ;
F_20 ( V_38 , & V_50 ) ;
F_21 ( V_38 , V_5 ) ;
V_14:
F_19 ( V_9 ) ;
return V_44 ;
}
static T_1 F_22 ( struct V_51 * V_52 , void T_2 * V_53 ,
T_3 V_54 , T_4 * V_55 , int V_56 )
{
struct V_5 * V_5 = V_52 -> V_57 . V_38 -> V_58 ;
struct V_8 * V_9 = F_11 ( V_5 ) ;
struct V_10 * V_11 = F_8 ( V_5 ) -> V_17 ;
T_1 error ;
T_3 V_59 ;
if ( F_16 ( V_9 ) )
return F_23 ( V_9 ) ;
error = - V_60 ;
if ( F_24 ( V_9 -> V_61 , V_11 , V_56 ? V_62 : V_63 ) )
goto V_14;
error = - V_64 ;
if ( ! V_11 -> V_65 )
goto V_14;
V_59 = V_54 ;
error = V_11 -> V_65 ( V_11 , V_56 , V_53 , & V_59 , V_55 ) ;
if ( ! error )
error = V_59 ;
V_14:
F_19 ( V_9 ) ;
return error ;
}
static T_1 F_25 ( struct V_51 * V_52 , char T_2 * V_53 ,
T_3 V_54 , T_4 * V_55 )
{
return F_22 ( V_52 , ( void T_2 * ) V_53 , V_54 , V_55 , 0 ) ;
}
static T_1 F_26 ( struct V_51 * V_52 , const char T_2 * V_53 ,
T_3 V_54 , T_4 * V_55 )
{
return F_22 ( V_52 , ( void T_2 * ) V_53 , V_54 , V_55 , 1 ) ;
}
static int F_27 ( struct V_5 * V_5 , struct V_51 * V_52 )
{
struct V_10 * V_11 = F_8 ( V_5 ) -> V_17 ;
if ( V_11 -> V_2 )
V_52 -> V_66 = F_28 ( V_11 -> V_2 ) ;
return 0 ;
}
static unsigned int F_29 ( struct V_51 * V_52 , T_5 * V_4 )
{
struct V_5 * V_5 = V_52 -> V_57 . V_38 -> V_58 ;
struct V_10 * V_11 = F_8 ( V_5 ) -> V_17 ;
unsigned long V_3 = ( unsigned long ) V_52 -> V_66 ;
unsigned int V_67 = V_68 ;
if ( ! V_11 -> V_65 )
goto V_14;
if ( ! V_11 -> V_2 )
goto V_14;
F_30 ( V_52 , & V_11 -> V_2 -> V_4 , V_4 ) ;
if ( V_3 != F_31 ( & V_11 -> V_2 -> V_3 ) ) {
V_52 -> V_66 = F_28 ( V_11 -> V_2 ) ;
V_67 = V_69 | V_70 | V_71 | V_72 ;
}
V_14:
return V_67 ;
}
static int F_32 ( struct V_51 * V_52 , void * V_73 ,
T_6 V_74 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_38 * V_24 , * V_39 = V_52 -> V_57 . V_38 ;
struct V_5 * V_5 ;
struct V_34 V_75 ;
T_7 V_76 = 0 ;
unsigned type = V_77 ;
V_75 . V_35 = V_11 -> V_37 ;
V_75 . V_36 = strlen ( V_11 -> V_37 ) ;
V_75 . V_78 = F_33 ( V_75 . V_35 , V_75 . V_36 ) ;
V_24 = F_34 ( V_39 , & V_75 ) ;
if ( ! V_24 ) {
V_24 = F_35 ( V_39 , & V_75 ) ;
if ( V_24 ) {
V_5 = F_4 ( V_39 -> V_79 , V_9 , V_11 ) ;
if ( ! V_5 ) {
F_36 ( V_24 ) ;
return - V_48 ;
} else {
F_20 ( V_24 , & V_50 ) ;
F_21 ( V_24 , V_5 ) ;
}
} else {
return - V_48 ;
}
}
V_5 = V_24 -> V_58 ;
V_76 = V_5 -> V_15 ;
type = V_5 -> V_22 >> 12 ;
F_36 ( V_24 ) ;
return ! ! V_74 ( V_73 , V_75 . V_35 , V_75 . V_36 , V_52 -> V_80 , V_76 , type ) ;
}
static int F_37 ( struct V_8 * V_9 , V_10 * V_11 ,
unsigned long * V_81 , struct V_51 * V_51 ,
void * V_73 , T_6 V_74 )
{
for (; V_11 -> V_37 ; V_11 ++ , ( * V_81 ) ++ ) {
int V_59 ;
if ( ! V_11 -> V_37 )
continue;
if ( * V_81 < V_51 -> V_80 )
continue;
V_59 = F_32 ( V_51 , V_73 , V_74 , V_9 , V_11 ) ;
if ( V_59 )
return V_59 ;
V_51 -> V_80 = * V_81 + 1 ;
}
return 0 ;
}
static int F_38 ( struct V_51 * V_52 , void * V_73 , T_6 V_74 )
{
struct V_38 * V_38 = V_52 -> V_57 . V_38 ;
struct V_5 * V_5 = V_38 -> V_58 ;
struct V_8 * V_9 = F_11 ( V_5 ) ;
struct V_10 * V_11 = F_8 ( V_5 ) -> V_17 ;
struct V_8 * V_42 = NULL ;
unsigned long V_81 ;
int V_67 = - V_64 ;
if ( F_16 ( V_9 ) )
return F_23 ( V_9 ) ;
if ( V_11 && ! V_11 -> V_24 ) {
F_18 ( 1 ) ;
goto V_14;
}
V_11 = V_11 ? V_11 -> V_24 : V_9 -> V_10 ;
V_67 = 0 ;
if ( V_52 -> V_80 == 0 ) {
if ( V_74 ( V_73 , L_1 , 1 , V_52 -> V_80 ,
V_5 -> V_15 , V_82 ) < 0 )
goto V_14;
V_52 -> V_80 ++ ;
}
if ( V_52 -> V_80 == 1 ) {
if ( V_74 ( V_73 , L_2 , 2 , V_52 -> V_80 ,
F_39 ( V_38 ) , V_82 ) < 0 )
goto V_14;
V_52 -> V_80 ++ ;
}
V_81 = 2 ;
V_67 = F_37 ( V_9 , V_11 , & V_81 , V_52 , V_73 , V_74 ) ;
if ( V_67 )
goto V_14;
for ( V_42 = F_13 ( NULL ) ; V_42 ; V_42 = F_13 ( V_42 ) ) {
if ( V_42 -> V_46 != V_11 )
continue;
V_67 = F_37 ( V_42 , V_42 -> V_47 , & V_81 , V_52 , V_73 , V_74 ) ;
if ( V_67 ) {
F_19 ( V_42 ) ;
break;
}
}
V_67 = 1 ;
V_14:
F_19 ( V_9 ) ;
return V_67 ;
}
static int F_40 ( struct V_5 * V_5 , int V_83 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int error ;
if ( ( V_83 & V_84 ) && F_41 ( V_5 -> V_22 ) )
return - V_85 ;
V_9 = F_11 ( V_5 ) ;
if ( F_16 ( V_9 ) )
return F_23 ( V_9 ) ;
V_11 = F_8 ( V_5 ) -> V_17 ;
if ( ! V_11 )
error = V_83 & V_62 ? - V_85 : 0 ;
else
error = F_24 ( V_9 -> V_61 , V_11 , V_83 & ~ V_86 ) ;
F_19 ( V_9 ) ;
return error ;
}
static int F_42 ( struct V_38 * V_38 , struct V_87 * V_88 )
{
struct V_5 * V_5 = V_38 -> V_58 ;
int error ;
if ( V_88 -> V_89 & ( V_90 | V_91 | V_92 ) )
return - V_60 ;
error = F_43 ( V_5 , V_88 ) ;
if ( error )
return error ;
if ( ( V_88 -> V_89 & V_93 ) &&
V_88 -> V_94 != F_44 ( V_5 ) ) {
error = F_45 ( V_5 , V_88 -> V_94 ) ;
if ( error )
return error ;
}
F_46 ( V_5 , V_88 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
static int F_48 ( struct V_95 * V_96 , struct V_38 * V_38 , struct V_97 * V_98 )
{
struct V_5 * V_5 = V_38 -> V_58 ;
struct V_8 * V_9 = F_11 ( V_5 ) ;
struct V_10 * V_11 = F_8 ( V_5 ) -> V_17 ;
if ( F_16 ( V_9 ) )
return F_23 ( V_9 ) ;
F_49 ( V_5 , V_98 ) ;
if ( V_11 )
V_98 -> V_23 = ( V_98 -> V_23 & V_99 ) | V_11 -> V_23 ;
F_19 ( V_9 ) ;
return 0 ;
}
static int F_50 ( struct V_38 * V_38 , struct V_40 * V_41 )
{
if ( V_41 -> V_100 & V_101 )
return - V_102 ;
return ! F_8 ( V_38 -> V_58 ) -> V_16 -> V_103 ;
}
static int F_51 ( const struct V_38 * V_38 )
{
return ! ! F_8 ( V_38 -> V_58 ) -> V_16 -> V_103 ;
}
static int F_52 ( const struct V_38 * V_104 ,
const struct V_5 * V_105 ,
const struct V_38 * V_38 , const struct V_5 * V_5 ,
unsigned int V_36 , const char * V_106 , const struct V_34 * V_35 )
{
struct V_8 * V_9 ;
if ( ! V_5 )
return 1 ;
if ( V_35 -> V_36 != V_36 )
return 1 ;
if ( memcmp ( V_35 -> V_35 , V_106 , V_36 ) )
return 1 ;
V_9 = F_53 ( F_8 ( V_5 ) -> V_16 ) ;
return ! V_9 || ! F_54 ( V_9 ) ;
}
int T_8 F_55 ( void )
{
struct V_107 * V_108 ;
V_108 = F_56 ( L_3 , NULL ) ;
V_108 -> V_109 = & V_31 ;
V_108 -> V_110 = & V_32 ;
V_108 -> V_111 = 0 ;
return 0 ;
}
