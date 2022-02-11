static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_3 ( & V_8 -> V_2 ) ;
}
F_4 ( V_3 -> V_9 ) ;
F_5 ( & V_10 , V_3 -> V_11 ) ;
if ( F_6 ( V_2 ) )
F_7 ( F_8 ( V_2 ) ) ;
else
F_7 ( V_3 ) ;
}
bool F_9 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_12 : false ;
}
bool F_6 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_13 : false ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_10 ( V_2 , struct V_3 , V_2 ) ;
F_11 ( V_2 -> type -> V_14 != F_1 ) ;
return V_3 ;
}
struct V_15 * F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_11 ( ! F_6 ( V_2 ) ) ;
return F_10 ( V_3 , struct V_15 , V_3 ) ;
}
void * F_12 ( struct V_3 * V_3 )
{
return V_3 -> V_16 ;
}
void * F_13 ( struct V_15 * V_17 )
{
return V_17 -> V_18 ;
}
void F_14 ( struct V_15 * V_17 , void * V_19 )
{
V_17 -> V_18 = V_19 ;
}
int F_15 ( struct V_3 * V_3 )
{
if ( F_9 ( & V_3 -> V_2 ) ) {
T_1 V_4 , V_20 ;
for ( V_4 = 0 , V_20 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_21 & V_22 )
V_20 ++ ;
}
if ( V_20 )
return V_23 ;
else
return V_24 ;
} else if ( F_6 ( & V_3 -> V_2 ) ) {
return V_25 ;
}
return 0 ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long long V_29 = 0 ;
if ( F_9 ( V_2 ) ) {
V_29 = V_3 -> V_30 ;
} else if ( V_3 -> V_5 == 1 ) {
struct V_6 * V_6 = & V_3 -> V_7 [ 0 ] ;
V_29 = V_6 -> V_29 ;
}
return sprintf ( V_28 , L_1 , V_29 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return sprintf ( V_28 , L_2 , V_3 -> V_5 ) ;
}
static T_2 F_18 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return sprintf ( V_28 , L_2 , F_15 ( V_3 ) ) ;
}
static T_2 F_19 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_31 * V_32 = V_3 -> V_32 ;
if ( F_9 ( V_2 ) && V_32 )
;
else
return - V_33 ;
return sprintf ( V_28 , L_3 , V_32 -> V_34 ) ;
}
T_3 F_20 ( struct V_3 * V_3 )
{
T_3 V_35 = 0 , V_36 , V_37 ;
int V_4 ;
F_11 ( ! F_21 ( & V_3 -> V_2 ) ) ;
V_38:
V_36 = 0 ;
V_37 = V_35 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_39 * V_40 = F_22 ( V_6 ) ;
if ( ! V_40 )
return 0 ;
if ( F_9 ( & V_3 -> V_2 ) ) {
V_36 += F_23 ( V_3 ,
V_6 , & V_37 ) ;
if ( V_37 > V_35 ) {
V_35 = V_37 ;
goto V_38;
}
} else if ( F_6 ( & V_3 -> V_2 ) ) {
V_36 += F_24 ( V_6 ) ;
}
}
return V_36 ;
}
static T_2 F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long long V_36 = 0 ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
V_36 = F_20 ( V_3 ) ;
F_28 ( V_2 ) ;
return sprintf ( V_28 , L_1 , V_36 ) ;
}
static T_2 F_29 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_41 * V_42 = F_30 ( V_2 ) ;
T_2 V_43 ;
F_26 ( V_2 ) ;
if ( V_42 )
V_43 = sprintf ( V_28 , L_4 , V_42 -> V_44 , V_42 -> V_45 ) ;
else
V_43 = - V_33 ;
F_28 ( V_2 ) ;
return V_43 ;
}
static T_2 F_31 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_43 ;
F_26 ( V_2 ) ;
if ( V_3 -> V_46 )
V_43 = sprintf ( V_28 , L_5 , F_32 ( V_3 -> V_46 ) ) ;
else
V_43 = sprintf ( V_28 , L_6 ) ;
F_28 ( V_2 ) ;
return V_43 ;
}
static T_2 F_33 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_43 ;
F_26 ( V_2 ) ;
if ( V_3 -> V_47 )
V_43 = sprintf ( V_28 , L_5 , F_32 ( V_3 -> V_47 ) ) ;
else
V_43 = sprintf ( V_28 , L_6 ) ;
F_28 ( V_2 ) ;
return V_43 ;
}
static T_2 F_34 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_43 ;
F_26 ( V_2 ) ;
if ( V_3 -> V_48 )
V_43 = sprintf ( V_28 , L_5 , F_32 ( V_3 -> V_48 ) ) ;
else
V_43 = sprintf ( V_28 , L_6 ) ;
F_28 ( V_2 ) ;
return V_43 ;
}
static T_2 F_35 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_43 ;
F_26 ( V_2 ) ;
if ( V_3 -> V_49 )
V_43 = sprintf ( V_28 , L_5 , F_32 ( V_3 -> V_49 ) ) ;
else
V_43 = sprintf ( V_28 , L_6 ) ;
F_28 ( V_2 ) ;
return V_43 ;
}
static T_2 F_36 ( struct V_1 * V_2 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return sprintf ( V_28 , L_2 , V_3 -> V_50 ) ;
}
static T_2 F_37 ( struct V_1 * V_2 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_51 )
{
bool V_50 ;
int V_43 = F_38 ( V_28 , & V_50 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_43 )
return V_43 ;
V_3 -> V_50 = V_50 ;
return V_51 ;
}
static T_5 F_39 ( struct V_52 * V_53 , struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_2 = F_10 ( V_53 , F_40 ( * V_2 ) , V_53 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_31 * V_32 = V_3 -> V_32 ;
int type = F_15 ( V_3 ) ;
if ( ! F_9 ( V_2 ) && V_55 == & V_57 . V_27 )
return 0 ;
if ( ! F_9 ( V_2 ) && V_55 == & V_58 . V_27 )
return 0 ;
if ( V_55 != & V_59 . V_27
&& V_55 != & V_60 . V_27 )
return V_55 -> V_61 ;
if ( ( type == V_23
|| type == V_25 )
&& V_55 == & V_60 . V_27 )
return V_55 -> V_61 ;
else if ( F_9 ( V_2 ) && V_32 )
return V_55 -> V_61 ;
return 0 ;
}
T_6 F_41 ( struct V_3 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_32 ;
if ( V_32 )
return V_32 -> V_34 ;
return 0 ;
}
static void F_42 ( struct V_62 * V_62 ,
struct V_1 * V_2 , bool V_63 )
{
struct V_3 * V_3 ;
if ( ! V_63 && ( F_9 ( V_2 ) || F_6 ( V_2 ) ) ) {
int V_4 ;
V_3 = F_2 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_39 * V_40 = V_6 -> V_40 ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_7 ( V_6 -> V_64 ) ;
V_6 -> V_64 = NULL ;
F_43 ( V_40 ) ;
V_6 -> V_40 = NULL ;
if ( V_40 )
F_44 ( & V_8 -> V_65 ) ;
}
if ( F_9 ( V_2 ) )
return;
F_8 ( V_2 ) -> F_45 ( V_62 , V_2 ) ;
}
if ( V_2 -> V_66 && F_6 ( V_2 -> V_66 ) && V_63 ) {
V_3 = F_2 ( V_2 -> V_66 ) ;
F_26 ( V_2 ) ;
if ( V_3 -> V_46 == V_2 )
F_46 ( V_3 ) ;
F_28 ( V_2 ) ;
}
if ( F_47 ( V_2 ) && V_63 ) {
struct V_67 * V_67 = F_48 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_66 ) ;
F_26 ( V_2 ) ;
if ( V_3 -> V_47 == V_2 )
F_49 ( V_3 ) ;
if ( V_3 -> V_46 == & V_67 -> V_68 -> V_2 &&
F_6 ( V_2 -> V_66 ) )
F_46 ( V_3 ) ;
F_28 ( V_2 ) ;
}
if ( F_50 ( V_2 ) && V_63 ) {
V_3 = F_2 ( V_2 -> V_66 ) ;
F_26 ( V_2 ) ;
if ( V_3 -> V_48 == V_2 )
F_51 ( V_3 ) ;
F_28 ( V_2 ) ;
}
if ( F_52 ( V_2 ) && V_63 ) {
V_3 = F_2 ( V_2 -> V_66 ) ;
F_26 ( V_2 ) ;
if ( V_3 -> V_49 == V_2 )
F_53 ( V_3 ) ;
F_28 ( V_2 ) ;
}
}
void F_54 ( struct V_62 * V_62 , struct V_1 * V_2 )
{
F_42 ( V_62 , V_2 , true ) ;
}
void F_55 ( struct V_62 * V_62 , struct V_1 * V_2 )
{
F_42 ( V_62 , V_2 , false ) ;
}
static T_2 F_56 ( struct V_1 * V_2 , char * V_28 , int V_56 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 ;
struct V_8 * V_8 ;
if ( V_56 >= V_3 -> V_5 )
return - V_33 ;
V_6 = & V_3 -> V_7 [ V_56 ] ;
V_8 = V_6 -> V_8 ;
return sprintf ( V_28 , L_7 , F_32 ( & V_8 -> V_2 ) ,
V_6 -> V_69 , V_6 -> V_29 ) ;
}
static T_5 F_57 ( struct V_52 * V_53 , struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_2 = F_10 ( V_53 , struct V_1 , V_53 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_56 < V_3 -> V_5 )
return V_55 -> V_61 ;
return 0 ;
}
int F_58 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_62 * V_62 = F_59 ( V_2 ) ;
if ( ! F_6 ( V_2 ) )
return 0 ;
if ( V_3 -> V_5 < 1 ) {
F_60 ( V_2 , L_8 ) ;
return - V_33 ;
}
return F_8 ( V_2 ) -> F_61 ( V_62 , V_2 ) ;
}
unsigned int F_62 ( struct V_3 * V_3 )
{
unsigned int V_70 , V_9 ;
V_70 = F_63 () ;
if ( V_3 -> V_71 < V_72 ) {
struct V_73 * V_74 , * V_75 ;
V_9 = V_70 % V_3 -> V_71 ;
V_75 = F_64 ( V_3 -> V_9 , V_70 ) ;
V_74 = F_64 ( V_3 -> V_9 , V_9 ) ;
if ( V_75 -> V_45 ++ == 0 )
F_65 ( & V_74 -> V_76 ) ;
} else
V_9 = V_70 ;
return V_9 ;
}
void F_66 ( struct V_3 * V_3 , unsigned int V_9 )
{
if ( V_3 -> V_71 < V_72 ) {
unsigned int V_70 = F_63 () ;
struct V_73 * V_74 , * V_75 ;
V_75 = F_64 ( V_3 -> V_9 , V_70 ) ;
V_74 = F_64 ( V_3 -> V_9 , V_9 ) ;
if ( -- V_75 -> V_45 == 0 )
F_67 ( & V_74 -> V_76 ) ;
F_68 () ;
}
F_68 () ;
}
static struct V_3 * F_69 ( struct V_62 * V_62 ,
struct V_77 * V_78 , struct V_79 * V_80 ,
const char * V_81 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
void * V_82 ;
unsigned int V_4 ;
int V_50 = 0 ;
for ( V_4 = 0 ; V_4 < V_78 -> V_83 ; V_4 ++ ) {
struct V_6 * V_6 = & V_78 -> V_6 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
if ( ( V_6 -> V_69 | V_6 -> V_29 ) % V_84 ) {
F_60 ( & V_62 -> V_2 , L_9 ,
V_81 , F_32 ( & V_8 -> V_2 ) , V_4 ) ;
return NULL ;
}
if ( V_8 -> V_21 & V_85 )
V_50 = 1 ;
}
if ( V_80 == & V_13 ) {
struct V_86 * V_87 ;
struct V_15 * V_17 ;
V_87 = F_70 ( V_78 ) ;
V_17 = F_71 ( sizeof( * V_17 ) + sizeof( struct V_6 )
* V_78 -> V_83 ,
V_88 ) ;
if ( V_17 ) {
V_3 = & V_17 -> V_3 ;
V_17 -> F_61 = V_87 -> F_61 ;
V_17 -> F_45 = V_87 -> F_45 ;
V_17 -> V_89 = V_87 -> V_89 ;
}
V_82 = V_17 ;
} else {
V_3 = F_71 ( sizeof( struct V_3 )
+ sizeof( struct V_6 )
* V_78 -> V_83 ,
V_88 ) ;
V_82 = V_3 ;
}
if ( ! V_82 )
return NULL ;
V_3 -> V_11 = F_72 ( & V_10 , 0 , 0 , V_88 ) ;
if ( V_3 -> V_11 < 0 )
goto V_90;
V_3 -> V_9 = F_73 ( struct V_73 ) ;
if ( ! V_3 -> V_9 )
goto V_91;
for ( V_4 = 0 ; V_4 < V_72 ; V_4 ++ ) {
struct V_73 * V_92 ;
V_92 = F_64 ( V_3 -> V_9 , V_4 ) ;
F_74 ( & V_92 -> V_76 ) ;
V_92 -> V_45 = 0 ;
}
memcpy ( V_3 -> V_7 , V_78 -> V_6 ,
sizeof( struct V_6 ) * V_78 -> V_83 ) ;
for ( V_4 = 0 ; V_4 < V_78 -> V_83 ; V_4 ++ ) {
struct V_6 * V_6 = & V_78 -> V_6 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_75 ( & V_8 -> V_2 ) ;
}
V_3 -> V_5 = V_78 -> V_83 ;
V_3 -> V_16 = V_78 -> V_16 ;
V_3 -> V_32 = V_78 -> V_32 ;
V_3 -> V_71 = V_78 -> V_71 ;
V_3 -> V_21 = V_78 -> V_21 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_93 = V_78 -> V_93 ;
F_76 ( & V_3 -> V_94 ) ;
F_76 ( & V_3 -> V_95 ) ;
F_76 ( & V_3 -> V_96 ) ;
F_76 ( & V_3 -> V_97 ) ;
V_2 = & V_3 -> V_2 ;
F_77 ( V_2 , L_10 , V_3 -> V_11 ) ;
V_2 -> V_66 = & V_62 -> V_2 ;
V_2 -> type = V_80 ;
V_2 -> V_98 = V_78 -> V_99 ;
V_3 -> V_30 = F_78 ( V_78 -> V_100 ) ;
V_3 -> V_101 = V_78 -> V_100 -> V_69 ;
F_79 ( V_2 ) ;
return V_3 ;
V_91:
F_5 ( & V_10 , V_3 -> V_11 ) ;
V_90:
F_7 ( V_82 ) ;
return NULL ;
}
struct V_3 * F_80 ( struct V_62 * V_62 ,
struct V_77 * V_78 )
{
V_78 -> V_71 = V_102 ;
return F_69 ( V_62 , V_78 , & V_12 ,
V_103 ) ;
}
struct V_3 * F_81 ( struct V_62 * V_62 ,
struct V_77 * V_78 )
{
if ( V_78 -> V_83 > 1 )
return NULL ;
V_78 -> V_71 = F_82 ( V_78 -> V_71 , V_102 ) ;
return F_69 ( V_62 , V_78 , & V_13 ,
V_103 ) ;
}
struct V_3 * F_83 ( struct V_62 * V_62 ,
struct V_77 * V_78 )
{
V_78 -> V_71 = V_102 ;
return F_69 ( V_62 , V_78 , & V_104 ,
V_103 ) ;
}
void T_7 F_84 ( void )
{
F_85 ( & V_10 ) ;
}
