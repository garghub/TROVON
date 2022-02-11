static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
V_1 = F_2 ( V_3 ) ;
if ( ! V_1 )
goto V_10;
V_1 -> V_11 = F_3 () ;
F_4 ( V_5 ) ;
V_9 = F_5 ( V_1 ) ;
V_9 -> V_12 = V_5 ;
V_9 -> V_13 = V_7 ;
V_1 -> V_14 = V_1 -> V_15 = V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_7 -> V_19 ;
if ( ! V_7 -> V_20 ) {
V_1 -> V_18 |= V_21 ;
V_1 -> V_22 = & V_23 ;
V_1 -> V_24 = & V_25 ;
} else {
V_1 -> V_18 |= V_26 ;
V_1 -> V_27 = 0 ;
V_1 -> V_22 = & V_28 ;
V_1 -> V_24 = & V_29 ;
}
V_10:
return V_1 ;
}
static struct V_6 * F_6 ( struct V_6 * V_30 , struct V_31 * V_32 )
{
int V_33 ;
for ( ; V_30 -> V_34 ; V_30 ++ ) {
if ( ! V_30 -> V_34 )
continue;
V_33 = strlen ( V_30 -> V_34 ) ;
if ( V_33 != V_32 -> V_33 )
continue;
if ( memcmp ( V_30 -> V_34 , V_32 -> V_32 , V_33 ) != 0 )
continue;
return V_30 ;
}
return NULL ;
}
static struct V_4 * F_7 ( struct V_1 * V_1 )
{
if ( F_5 ( V_1 ) -> V_12 )
return F_8 ( F_5 ( V_1 ) -> V_12 ) ;
else
return F_9 ( NULL ) ;
}
static struct V_35 * F_10 ( struct V_1 * V_36 , struct V_35 * V_35 ,
struct V_37 * V_38 )
{
struct V_4 * V_5 = F_7 ( V_36 ) ;
struct V_6 * V_7 = F_5 ( V_36 ) -> V_13 ;
struct V_4 * V_39 = NULL ;
struct V_31 * V_32 = & V_35 -> V_40 ;
struct V_6 * V_30 ;
struct V_1 * V_1 ;
struct V_35 * V_41 = F_11 ( - V_42 ) ;
if ( F_12 ( V_5 ) )
return F_13 ( V_5 ) ;
if ( V_7 && ! V_7 -> V_20 ) {
F_14 ( 1 ) ;
goto V_10;
}
V_7 = V_7 ? V_7 -> V_20 : V_5 -> V_6 ;
V_30 = F_6 ( V_7 , V_32 ) ;
if ( ! V_30 ) {
for ( V_39 = F_9 ( NULL ) ; V_39 ; V_39 = F_9 ( V_39 ) ) {
if ( V_39 -> V_43 != V_7 )
continue;
V_30 = F_6 ( V_39 -> V_44 , V_32 ) ;
if ( V_30 )
break;
}
}
if ( ! V_30 )
goto V_10;
V_41 = F_11 ( - V_45 ) ;
V_1 = F_1 ( V_36 -> V_46 , V_39 ? V_39 : V_5 , V_30 ) ;
if ( V_39 )
F_15 ( V_39 ) ;
if ( ! V_1 )
goto V_10;
V_41 = NULL ;
F_16 ( V_35 , & V_47 ) ;
F_17 ( V_35 , V_1 ) ;
V_10:
F_15 ( V_5 ) ;
return V_41 ;
}
static T_1 F_18 ( struct V_48 * V_49 , void T_2 * V_50 ,
T_3 V_51 , T_4 * V_52 , int V_53 )
{
struct V_1 * V_1 = V_49 -> V_54 . V_35 -> V_55 ;
struct V_4 * V_5 = F_7 ( V_1 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) -> V_13 ;
T_1 error ;
T_3 V_56 ;
if ( F_12 ( V_5 ) )
return F_19 ( V_5 ) ;
error = - V_57 ;
if ( F_20 ( V_5 -> V_58 , V_7 , V_53 ? V_59 : V_60 ) )
goto V_10;
error = - V_61 ;
if ( ! V_7 -> V_62 )
goto V_10;
V_56 = V_51 ;
error = V_7 -> V_62 ( V_7 , V_53 , V_50 , & V_56 , V_52 ) ;
if ( ! error )
error = V_56 ;
V_10:
F_15 ( V_5 ) ;
return error ;
}
static T_1 F_21 ( struct V_48 * V_49 , char T_2 * V_50 ,
T_3 V_51 , T_4 * V_52 )
{
return F_18 ( V_49 , ( void T_2 * ) V_50 , V_51 , V_52 , 0 ) ;
}
static T_1 F_22 ( struct V_48 * V_49 , const char T_2 * V_50 ,
T_3 V_51 , T_4 * V_52 )
{
return F_18 ( V_49 , ( void T_2 * ) V_50 , V_51 , V_52 , 1 ) ;
}
static int F_23 ( struct V_48 * V_49 , void * V_63 ,
T_5 V_64 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_35 * V_20 , * V_36 = V_49 -> V_54 . V_35 ;
struct V_1 * V_1 ;
struct V_31 V_65 ;
T_6 V_66 = 0 ;
unsigned type = V_67 ;
V_65 . V_32 = V_7 -> V_34 ;
V_65 . V_33 = strlen ( V_7 -> V_34 ) ;
V_65 . V_68 = F_24 ( V_65 . V_32 , V_65 . V_33 ) ;
V_20 = F_25 ( V_36 , & V_65 ) ;
if ( ! V_20 ) {
V_20 = F_26 ( V_36 , & V_65 ) ;
if ( V_20 ) {
V_1 = F_1 ( V_36 -> V_69 , V_5 , V_7 ) ;
if ( ! V_1 ) {
F_27 ( V_20 ) ;
return - V_45 ;
} else {
F_16 ( V_20 , & V_47 ) ;
F_17 ( V_20 , V_1 ) ;
}
} else {
return - V_45 ;
}
}
V_1 = V_20 -> V_55 ;
V_66 = V_1 -> V_11 ;
type = V_1 -> V_18 >> 12 ;
F_27 ( V_20 ) ;
return ! ! V_64 ( V_63 , V_65 . V_32 , V_65 . V_33 , V_49 -> V_70 , V_66 , type ) ;
}
static int F_28 ( struct V_4 * V_5 , V_6 * V_7 ,
unsigned long * V_71 , struct V_48 * V_48 ,
void * V_63 , T_5 V_64 )
{
for (; V_7 -> V_34 ; V_7 ++ , ( * V_71 ) ++ ) {
int V_56 ;
if ( ! V_7 -> V_34 )
continue;
if ( * V_71 < V_48 -> V_70 )
continue;
V_56 = F_23 ( V_48 , V_63 , V_64 , V_5 , V_7 ) ;
if ( V_56 )
return V_56 ;
V_48 -> V_70 = * V_71 + 1 ;
}
return 0 ;
}
static int F_29 ( struct V_48 * V_49 , void * V_63 , T_5 V_64 )
{
struct V_35 * V_35 = V_49 -> V_54 . V_35 ;
struct V_1 * V_1 = V_35 -> V_55 ;
struct V_4 * V_5 = F_7 ( V_1 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) -> V_13 ;
struct V_4 * V_39 = NULL ;
unsigned long V_71 ;
int V_72 = - V_61 ;
if ( F_12 ( V_5 ) )
return F_19 ( V_5 ) ;
if ( V_7 && ! V_7 -> V_20 ) {
F_14 ( 1 ) ;
goto V_10;
}
V_7 = V_7 ? V_7 -> V_20 : V_5 -> V_6 ;
V_72 = 0 ;
if ( V_49 -> V_70 == 0 ) {
if ( V_64 ( V_63 , L_1 , 1 , V_49 -> V_70 ,
V_1 -> V_11 , V_73 ) < 0 )
goto V_10;
V_49 -> V_70 ++ ;
}
if ( V_49 -> V_70 == 1 ) {
if ( V_64 ( V_63 , L_2 , 2 , V_49 -> V_70 ,
F_30 ( V_35 ) , V_73 ) < 0 )
goto V_10;
V_49 -> V_70 ++ ;
}
V_71 = 2 ;
V_72 = F_28 ( V_5 , V_7 , & V_71 , V_49 , V_63 , V_64 ) ;
if ( V_72 )
goto V_10;
for ( V_39 = F_9 ( NULL ) ; V_39 ; V_39 = F_9 ( V_39 ) ) {
if ( V_39 -> V_43 != V_7 )
continue;
V_72 = F_28 ( V_39 , V_39 -> V_44 , & V_71 , V_49 , V_63 , V_64 ) ;
if ( V_72 ) {
F_15 ( V_39 ) ;
break;
}
}
V_72 = 1 ;
V_10:
F_15 ( V_5 ) ;
return V_72 ;
}
static int F_31 ( struct V_1 * V_1 , int V_74 , unsigned int V_75 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int error ;
if ( ( V_74 & V_76 ) && F_32 ( V_1 -> V_18 ) )
return - V_77 ;
V_5 = F_7 ( V_1 ) ;
if ( F_12 ( V_5 ) )
return F_19 ( V_5 ) ;
V_7 = F_5 ( V_1 ) -> V_13 ;
if ( ! V_7 )
error = V_74 & V_59 ? - V_77 : 0 ;
else
error = F_20 ( V_5 -> V_58 , V_7 , V_74 ) ;
F_15 ( V_5 ) ;
return error ;
}
static int F_33 ( struct V_35 * V_35 , struct V_78 * V_79 )
{
struct V_1 * V_1 = V_35 -> V_55 ;
int error ;
if ( V_79 -> V_80 & ( V_81 | V_82 | V_83 ) )
return - V_57 ;
error = F_34 ( V_1 , V_79 ) ;
if ( error )
return error ;
if ( ( V_79 -> V_80 & V_84 ) &&
V_79 -> V_85 != F_35 ( V_1 ) ) {
error = F_36 ( V_1 , V_79 -> V_85 ) ;
if ( error )
return error ;
}
F_37 ( V_1 , V_79 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_86 * V_87 , struct V_35 * V_35 , struct V_88 * V_89 )
{
struct V_1 * V_1 = V_35 -> V_55 ;
struct V_4 * V_5 = F_7 ( V_1 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) -> V_13 ;
if ( F_12 ( V_5 ) )
return F_19 ( V_5 ) ;
F_40 ( V_1 , V_89 ) ;
if ( V_7 )
V_89 -> V_19 = ( V_89 -> V_19 & V_90 ) | V_7 -> V_19 ;
F_15 ( V_5 ) ;
return 0 ;
}
static int F_41 ( struct V_35 * V_35 , struct V_37 * V_38 )
{
if ( V_38 -> V_75 & V_91 )
return - V_92 ;
return ! F_5 ( V_35 -> V_55 ) -> V_12 -> V_93 ;
}
static int F_42 ( const struct V_35 * V_35 )
{
return ! ! F_5 ( V_35 -> V_55 ) -> V_12 -> V_93 ;
}
static int F_43 ( const struct V_35 * V_94 ,
const struct V_1 * V_95 ,
const struct V_35 * V_35 , const struct V_1 * V_1 ,
unsigned int V_33 , const char * V_96 , const struct V_31 * V_32 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return 1 ;
if ( V_32 -> V_33 != V_33 )
return 1 ;
if ( memcmp ( V_32 -> V_32 , V_96 , V_33 ) )
return 1 ;
V_5 = F_44 ( F_5 ( V_1 ) -> V_12 ) ;
return ! V_5 || ! F_45 ( V_5 ) ;
}
int T_7 F_46 ( void )
{
struct V_97 * V_98 ;
V_98 = F_47 ( L_3 , NULL ) ;
V_98 -> V_99 = & V_28 ;
V_98 -> V_100 = & V_29 ;
V_98 -> V_101 = 0 ;
return 0 ;
}
