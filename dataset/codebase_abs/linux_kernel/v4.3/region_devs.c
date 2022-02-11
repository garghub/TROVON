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
static int F_16 ( struct V_1 * V_2 , void * V_19 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_26 ) ;
T_2 * V_27 = V_19 ;
switch ( F_15 ( V_3 ) ) {
case V_23 : {
struct V_28 * V_29 = F_17 ( V_2 ) ;
if ( ! V_29 -> V_27 )
break;
if ( memcmp ( V_27 , V_29 -> V_27 , V_30 ) == 0 )
return - V_31 ;
break;
}
case V_25 : {
struct V_32 * V_33 = F_18 ( V_2 ) ;
if ( ! V_33 -> V_27 )
break;
if ( memcmp ( V_27 , V_33 -> V_27 , V_30 ) == 0 )
return - V_31 ;
break;
}
default:
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_19 )
{
if ( F_9 ( V_2 ) || F_6 ( V_2 ) )
return F_20 ( V_2 , V_19 , F_16 ) ;
return 0 ;
}
bool F_21 ( struct V_1 * V_2 , T_2 * V_27 )
{
struct V_34 * V_34 = F_22 ( V_2 ) ;
if ( ! V_34 )
return false ;
F_23 ( ! F_24 ( & V_34 -> V_2 ) ) ;
if ( F_20 ( & V_34 -> V_2 , V_27 ,
F_19 ) != 0 )
return false ;
return true ;
}
static T_3 F_25 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long long V_38 = 0 ;
if ( F_9 ( V_2 ) ) {
V_38 = V_3 -> V_39 ;
} else if ( V_3 -> V_5 == 1 ) {
struct V_6 * V_6 = & V_3 -> V_7 [ 0 ] ;
V_38 = V_6 -> V_38 ;
}
return sprintf ( V_37 , L_1 , V_38 ) ;
}
static T_3 F_26 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return sprintf ( V_37 , L_2 , V_3 -> V_5 ) ;
}
static T_3 F_27 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return sprintf ( V_37 , L_2 , F_15 ( V_3 ) ) ;
}
static T_3 F_28 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 = V_3 -> V_41 ;
if ( F_9 ( V_2 ) && V_41 )
;
else
return - V_42 ;
return sprintf ( V_37 , L_3 , V_41 -> V_43 ) ;
}
T_4 F_29 ( struct V_3 * V_3 )
{
T_4 V_44 = 0 , V_45 , V_46 ;
int V_4 ;
F_11 ( ! F_24 ( & V_3 -> V_2 ) ) ;
V_47:
V_45 = 0 ;
V_46 = V_44 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_48 * V_49 = F_30 ( V_6 ) ;
if ( ! V_49 )
return 0 ;
if ( F_9 ( & V_3 -> V_2 ) ) {
V_45 += F_31 ( V_3 ,
V_6 , & V_46 ) ;
if ( V_46 > V_44 ) {
V_44 = V_46 ;
goto V_47;
}
} else if ( F_6 ( & V_3 -> V_2 ) ) {
V_45 += F_32 ( V_6 ) ;
}
}
return V_45 ;
}
static T_3 F_33 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long long V_45 = 0 ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
V_45 = F_29 ( V_3 ) ;
F_36 ( V_2 ) ;
return sprintf ( V_37 , L_1 , V_45 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_50 * V_51 = F_38 ( V_2 ) ;
T_3 V_52 ;
F_34 ( V_2 ) ;
if ( V_51 )
V_52 = sprintf ( V_37 , L_4 , V_51 -> V_53 , V_51 -> V_54 ) ;
else
V_52 = - V_42 ;
F_36 ( V_2 ) ;
return V_52 ;
}
static T_3 F_39 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_3 V_52 ;
F_34 ( V_2 ) ;
if ( V_3 -> V_55 )
V_52 = sprintf ( V_37 , L_5 , F_40 ( V_3 -> V_55 ) ) ;
else
V_52 = sprintf ( V_37 , L_6 ) ;
F_36 ( V_2 ) ;
return V_52 ;
}
static T_3 F_41 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_3 V_52 ;
F_34 ( V_2 ) ;
if ( V_3 -> V_56 )
V_52 = sprintf ( V_37 , L_5 , F_40 ( V_3 -> V_56 ) ) ;
else
V_52 = sprintf ( V_37 , L_6 ) ;
F_36 ( V_2 ) ;
return V_52 ;
}
static T_3 F_42 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_3 V_52 ;
F_34 ( V_2 ) ;
if ( V_3 -> V_57 )
V_52 = sprintf ( V_37 , L_5 , F_40 ( V_3 -> V_57 ) ) ;
else
V_52 = sprintf ( V_37 , L_6 ) ;
F_36 ( V_2 ) ;
return V_52 ;
}
static T_3 F_43 ( struct V_1 * V_2 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return sprintf ( V_37 , L_2 , V_3 -> V_58 ) ;
}
static T_3 F_44 ( struct V_1 * V_2 ,
struct V_35 * V_36 , const char * V_37 , T_5 V_59 )
{
bool V_58 ;
int V_52 = F_45 ( V_37 , & V_58 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_3 -> V_58 = V_58 ;
return V_59 ;
}
static T_6 F_46 ( struct V_60 * V_61 , struct V_62 * V_63 , int V_64 )
{
struct V_1 * V_2 = F_10 ( V_61 , F_47 ( * V_2 ) , V_61 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 = V_3 -> V_41 ;
int type = F_15 ( V_3 ) ;
if ( V_63 != & V_65 . V_36
&& V_63 != & V_66 . V_36 )
return V_63 -> V_67 ;
if ( ( type == V_23
|| type == V_25 )
&& V_63 == & V_66 . V_36 )
return V_63 -> V_67 ;
else if ( F_9 ( V_2 ) && V_41 )
return V_63 -> V_67 ;
return 0 ;
}
T_7 F_48 ( struct V_3 * V_3 )
{
struct V_40 * V_41 = V_3 -> V_41 ;
if ( V_41 )
return V_41 -> V_43 ;
return 0 ;
}
static void F_49 ( struct V_34 * V_34 ,
struct V_1 * V_2 , bool V_68 )
{
struct V_3 * V_3 ;
if ( ! V_68 && ( F_9 ( V_2 ) || F_6 ( V_2 ) ) ) {
int V_4 ;
V_3 = F_2 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_48 * V_49 = V_6 -> V_49 ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_7 ( V_6 -> V_69 ) ;
V_6 -> V_69 = NULL ;
F_50 ( V_49 ) ;
V_6 -> V_49 = NULL ;
if ( V_49 )
F_51 ( & V_8 -> V_70 ) ;
}
if ( F_9 ( V_2 ) )
return;
F_8 ( V_2 ) -> F_52 ( V_34 , V_2 ) ;
}
if ( V_2 -> V_26 && F_6 ( V_2 -> V_26 ) && V_68 ) {
V_3 = F_2 ( V_2 -> V_26 ) ;
F_34 ( V_2 ) ;
if ( V_3 -> V_55 == V_2 )
F_53 ( V_3 ) ;
F_36 ( V_2 ) ;
}
if ( F_54 ( V_2 ) && V_68 ) {
struct V_71 * V_71 = F_55 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_26 ) ;
F_34 ( V_2 ) ;
if ( V_3 -> V_56 == V_2 )
F_56 ( V_3 ) ;
if ( V_3 -> V_55 == & V_71 -> V_72 -> V_2 &&
F_6 ( V_2 -> V_26 ) )
F_53 ( V_3 ) ;
F_36 ( V_2 ) ;
}
}
void F_57 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_49 ( V_34 , V_2 , true ) ;
}
void F_58 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_49 ( V_34 , V_2 , false ) ;
}
static T_3 F_59 ( struct V_1 * V_2 , char * V_37 , int V_64 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 ;
struct V_8 * V_8 ;
if ( V_64 >= V_3 -> V_5 )
return - V_42 ;
V_6 = & V_3 -> V_7 [ V_64 ] ;
V_8 = V_6 -> V_8 ;
return sprintf ( V_37 , L_7 , F_40 ( & V_8 -> V_2 ) ,
V_6 -> V_73 , V_6 -> V_38 ) ;
}
static T_6 F_60 ( struct V_60 * V_61 , struct V_62 * V_63 , int V_64 )
{
struct V_1 * V_2 = F_10 ( V_61 , struct V_1 , V_61 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_64 < V_3 -> V_5 )
return V_63 -> V_67 ;
return 0 ;
}
int F_61 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_34 * V_34 = F_22 ( V_2 ) ;
if ( ! F_6 ( V_2 ) )
return 0 ;
if ( V_3 -> V_5 < 1 ) {
F_62 ( V_2 , L_8 ) ;
return - V_42 ;
}
return F_8 ( V_2 ) -> F_63 ( V_34 , V_2 ) ;
}
unsigned int F_64 ( struct V_3 * V_3 )
{
unsigned int V_74 , V_9 ;
V_74 = F_65 () ;
if ( V_3 -> V_75 < V_76 ) {
struct V_77 * V_78 , * V_79 ;
V_9 = V_74 % V_3 -> V_75 ;
V_79 = F_66 ( V_3 -> V_9 , V_74 ) ;
V_78 = F_66 ( V_3 -> V_9 , V_9 ) ;
if ( V_79 -> V_54 ++ == 0 )
F_67 ( & V_78 -> V_80 ) ;
} else
V_9 = V_74 ;
return V_9 ;
}
void F_68 ( struct V_3 * V_3 , unsigned int V_9 )
{
if ( V_3 -> V_75 < V_76 ) {
unsigned int V_74 = F_65 () ;
struct V_77 * V_78 , * V_79 ;
V_79 = F_66 ( V_3 -> V_9 , V_74 ) ;
V_78 = F_66 ( V_3 -> V_9 , V_9 ) ;
if ( -- V_79 -> V_54 == 0 )
F_69 ( & V_78 -> V_80 ) ;
F_70 () ;
}
F_70 () ;
}
static struct V_3 * F_71 ( struct V_34 * V_34 ,
struct V_81 * V_82 , struct V_83 * V_84 ,
const char * V_85 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
void * V_86 ;
unsigned int V_4 ;
int V_58 = 0 ;
for ( V_4 = 0 ; V_4 < V_82 -> V_87 ; V_4 ++ ) {
struct V_6 * V_6 = & V_82 -> V_6 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
if ( ( V_6 -> V_73 | V_6 -> V_38 ) % V_88 ) {
F_62 ( & V_34 -> V_2 , L_9 ,
V_85 , F_40 ( & V_8 -> V_2 ) , V_4 ) ;
return NULL ;
}
if ( V_8 -> V_21 & V_89 )
V_58 = 1 ;
}
if ( V_84 == & V_13 ) {
struct V_90 * V_91 ;
struct V_15 * V_17 ;
V_91 = F_72 ( V_82 ) ;
V_17 = F_73 ( sizeof( * V_17 ) + sizeof( struct V_6 )
* V_82 -> V_87 ,
V_92 ) ;
if ( V_17 ) {
V_3 = & V_17 -> V_3 ;
V_17 -> F_63 = V_91 -> F_63 ;
V_17 -> F_52 = V_91 -> F_52 ;
V_17 -> V_93 = V_91 -> V_93 ;
}
V_86 = V_17 ;
} else {
V_3 = F_73 ( sizeof( struct V_3 )
+ sizeof( struct V_6 )
* V_82 -> V_87 ,
V_92 ) ;
V_86 = V_3 ;
}
if ( ! V_86 )
return NULL ;
V_3 -> V_11 = F_74 ( & V_10 , 0 , 0 , V_92 ) ;
if ( V_3 -> V_11 < 0 )
goto V_94;
V_3 -> V_9 = F_75 ( struct V_77 ) ;
if ( ! V_3 -> V_9 )
goto V_95;
for ( V_4 = 0 ; V_4 < V_76 ; V_4 ++ ) {
struct V_77 * V_96 ;
V_96 = F_66 ( V_3 -> V_9 , V_4 ) ;
F_76 ( & V_96 -> V_80 ) ;
V_96 -> V_54 = 0 ;
}
memcpy ( V_3 -> V_7 , V_82 -> V_6 ,
sizeof( struct V_6 ) * V_82 -> V_87 ) ;
for ( V_4 = 0 ; V_4 < V_82 -> V_87 ; V_4 ++ ) {
struct V_6 * V_6 = & V_82 -> V_6 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_77 ( & V_8 -> V_2 ) ;
}
V_3 -> V_5 = V_82 -> V_87 ;
V_3 -> V_16 = V_82 -> V_16 ;
V_3 -> V_41 = V_82 -> V_41 ;
V_3 -> V_75 = V_82 -> V_75 ;
V_3 -> V_21 = V_82 -> V_21 ;
V_3 -> V_58 = V_58 ;
V_3 -> V_97 = V_82 -> V_97 ;
F_78 ( & V_3 -> V_98 ) ;
F_78 ( & V_3 -> V_99 ) ;
F_78 ( & V_3 -> V_100 ) ;
V_2 = & V_3 -> V_2 ;
F_79 ( V_2 , L_10 , V_3 -> V_11 ) ;
V_2 -> V_26 = & V_34 -> V_2 ;
V_2 -> type = V_84 ;
V_2 -> V_101 = V_82 -> V_102 ;
V_3 -> V_39 = F_80 ( V_82 -> V_103 ) ;
V_3 -> V_104 = V_82 -> V_103 -> V_73 ;
F_81 ( V_2 ) ;
return V_3 ;
V_95:
F_5 ( & V_10 , V_3 -> V_11 ) ;
V_94:
F_7 ( V_86 ) ;
return NULL ;
}
struct V_3 * F_82 ( struct V_34 * V_34 ,
struct V_81 * V_82 )
{
V_82 -> V_75 = V_105 ;
return F_71 ( V_34 , V_82 , & V_12 ,
V_106 ) ;
}
struct V_3 * F_83 ( struct V_34 * V_34 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_87 > 1 )
return NULL ;
V_82 -> V_75 = F_84 ( V_82 -> V_75 , V_105 ) ;
return F_71 ( V_34 , V_82 , & V_13 ,
V_106 ) ;
}
struct V_3 * F_85 ( struct V_34 * V_34 ,
struct V_81 * V_82 )
{
V_82 -> V_75 = V_105 ;
return F_71 ( V_34 , V_82 , & V_107 ,
V_106 ) ;
}
