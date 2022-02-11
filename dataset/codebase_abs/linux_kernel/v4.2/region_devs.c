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
return sprintf ( V_37 , L_2 , V_3 -> V_57 ) ;
}
static T_3 F_43 ( struct V_1 * V_2 ,
struct V_35 * V_36 , const char * V_37 , T_5 V_58 )
{
bool V_57 ;
int V_52 = F_44 ( V_37 , & V_57 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_3 -> V_57 = V_57 ;
return V_58 ;
}
static T_6 F_45 ( struct V_59 * V_60 , struct V_61 * V_62 , int V_63 )
{
struct V_1 * V_2 = F_10 ( V_60 , F_46 ( * V_2 ) , V_60 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 = V_3 -> V_41 ;
int type = F_15 ( V_3 ) ;
if ( V_62 != & V_64 . V_36
&& V_62 != & V_65 . V_36 )
return V_62 -> V_66 ;
if ( ( type == V_23
|| type == V_25 )
&& V_62 == & V_65 . V_36 )
return V_62 -> V_66 ;
else if ( F_9 ( V_2 ) && V_41 )
return V_62 -> V_66 ;
return 0 ;
}
T_7 F_47 ( struct V_3 * V_3 )
{
struct V_40 * V_41 = V_3 -> V_41 ;
if ( V_41 )
return V_41 -> V_43 ;
return 0 ;
}
static void F_48 ( struct V_34 * V_34 ,
struct V_1 * V_2 , bool V_67 )
{
struct V_3 * V_3 ;
if ( ! V_67 && ( F_9 ( V_2 ) || F_6 ( V_2 ) ) ) {
int V_4 ;
V_3 = F_2 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_6 = & V_3 -> V_7 [ V_4 ] ;
struct V_48 * V_49 = V_6 -> V_49 ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_7 ( V_6 -> V_68 ) ;
V_6 -> V_68 = NULL ;
F_49 ( V_49 ) ;
V_6 -> V_49 = NULL ;
if ( V_49 )
F_50 ( & V_8 -> V_69 ) ;
}
if ( F_9 ( V_2 ) )
return;
F_8 ( V_2 ) -> F_51 ( V_34 , V_2 ) ;
}
if ( V_2 -> V_26 && F_6 ( V_2 -> V_26 ) && V_67 ) {
V_3 = F_2 ( V_2 -> V_26 ) ;
F_34 ( V_2 ) ;
if ( V_3 -> V_55 == V_2 )
F_52 ( V_3 ) ;
F_36 ( V_2 ) ;
}
if ( F_53 ( V_2 ) && V_67 ) {
struct V_70 * V_70 = F_54 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_26 ) ;
F_34 ( V_2 ) ;
if ( V_3 -> V_56 == V_2 )
F_55 ( V_3 ) ;
if ( V_3 -> V_55 == & V_70 -> V_71 -> V_2 &&
F_6 ( V_2 -> V_26 ) )
F_52 ( V_3 ) ;
F_36 ( V_2 ) ;
}
}
void F_56 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_48 ( V_34 , V_2 , true ) ;
}
void F_57 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_48 ( V_34 , V_2 , false ) ;
}
static T_3 F_58 ( struct V_1 * V_2 , char * V_37 , int V_63 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 ;
struct V_8 * V_8 ;
if ( V_63 >= V_3 -> V_5 )
return - V_42 ;
V_6 = & V_3 -> V_7 [ V_63 ] ;
V_8 = V_6 -> V_8 ;
return sprintf ( V_37 , L_7 , F_40 ( & V_8 -> V_2 ) ,
V_6 -> V_72 , V_6 -> V_38 ) ;
}
static T_6 F_59 ( struct V_59 * V_60 , struct V_61 * V_62 , int V_63 )
{
struct V_1 * V_2 = F_10 ( V_60 , struct V_1 , V_60 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_63 < V_3 -> V_5 )
return V_62 -> V_66 ;
return 0 ;
}
int F_60 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_34 * V_34 = F_22 ( V_2 ) ;
if ( ! F_6 ( V_2 ) )
return 0 ;
if ( V_3 -> V_5 < 1 ) {
F_61 ( V_2 , L_8 ) ;
return - V_42 ;
}
return F_8 ( V_2 ) -> F_62 ( V_34 , V_2 ) ;
}
unsigned int F_63 ( struct V_3 * V_3 )
{
unsigned int V_73 , V_9 ;
V_73 = F_64 () ;
if ( V_3 -> V_74 < V_75 ) {
struct V_76 * V_77 , * V_78 ;
V_9 = V_73 % V_3 -> V_74 ;
V_78 = F_65 ( V_3 -> V_9 , V_73 ) ;
V_77 = F_65 ( V_3 -> V_9 , V_9 ) ;
if ( V_78 -> V_54 ++ == 0 )
F_66 ( & V_77 -> V_79 ) ;
} else
V_9 = V_73 ;
return V_9 ;
}
void F_67 ( struct V_3 * V_3 , unsigned int V_9 )
{
if ( V_3 -> V_74 < V_75 ) {
unsigned int V_73 = F_64 () ;
struct V_76 * V_77 , * V_78 ;
V_78 = F_65 ( V_3 -> V_9 , V_73 ) ;
V_77 = F_65 ( V_3 -> V_9 , V_9 ) ;
if ( -- V_78 -> V_54 == 0 )
F_68 ( & V_77 -> V_79 ) ;
F_69 () ;
}
F_69 () ;
}
static struct V_3 * F_70 ( struct V_34 * V_34 ,
struct V_80 * V_81 , struct V_82 * V_83 ,
const char * V_84 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
void * V_85 ;
unsigned int V_4 ;
int V_57 = 0 ;
for ( V_4 = 0 ; V_4 < V_81 -> V_86 ; V_4 ++ ) {
struct V_6 * V_6 = & V_81 -> V_6 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
if ( ( V_6 -> V_72 | V_6 -> V_38 ) % V_87 ) {
F_61 ( & V_34 -> V_2 , L_9 ,
V_84 , F_40 ( & V_8 -> V_2 ) , V_4 ) ;
return NULL ;
}
if ( V_8 -> V_21 & V_88 )
V_57 = 1 ;
}
if ( V_83 == & V_13 ) {
struct V_89 * V_90 ;
struct V_15 * V_17 ;
V_90 = F_71 ( V_81 ) ;
V_17 = F_72 ( sizeof( * V_17 ) + sizeof( struct V_6 )
* V_81 -> V_86 ,
V_91 ) ;
if ( V_17 ) {
V_3 = & V_17 -> V_3 ;
V_17 -> F_62 = V_90 -> F_62 ;
V_17 -> F_51 = V_90 -> F_51 ;
V_17 -> V_92 = V_90 -> V_92 ;
}
V_85 = V_17 ;
} else {
V_3 = F_72 ( sizeof( struct V_3 )
+ sizeof( struct V_6 )
* V_81 -> V_86 ,
V_91 ) ;
V_85 = V_3 ;
}
if ( ! V_85 )
return NULL ;
V_3 -> V_11 = F_73 ( & V_10 , 0 , 0 , V_91 ) ;
if ( V_3 -> V_11 < 0 )
goto V_93;
V_3 -> V_9 = F_74 ( struct V_76 ) ;
if ( ! V_3 -> V_9 )
goto V_94;
for ( V_4 = 0 ; V_4 < V_75 ; V_4 ++ ) {
struct V_76 * V_95 ;
V_95 = F_65 ( V_3 -> V_9 , V_4 ) ;
F_75 ( & V_95 -> V_79 ) ;
V_95 -> V_54 = 0 ;
}
memcpy ( V_3 -> V_7 , V_81 -> V_6 ,
sizeof( struct V_6 ) * V_81 -> V_86 ) ;
for ( V_4 = 0 ; V_4 < V_81 -> V_86 ; V_4 ++ ) {
struct V_6 * V_6 = & V_81 -> V_6 [ V_4 ] ;
struct V_8 * V_8 = V_6 -> V_8 ;
F_76 ( & V_8 -> V_2 ) ;
}
V_3 -> V_5 = V_81 -> V_86 ;
V_3 -> V_16 = V_81 -> V_16 ;
V_3 -> V_41 = V_81 -> V_41 ;
V_3 -> V_74 = V_81 -> V_74 ;
V_3 -> V_57 = V_57 ;
V_3 -> V_96 = V_81 -> V_96 ;
F_77 ( & V_3 -> V_97 ) ;
F_77 ( & V_3 -> V_98 ) ;
V_2 = & V_3 -> V_2 ;
F_78 ( V_2 , L_10 , V_3 -> V_11 ) ;
V_2 -> V_26 = & V_34 -> V_2 ;
V_2 -> type = V_83 ;
V_2 -> V_99 = V_81 -> V_100 ;
V_3 -> V_39 = F_79 ( V_81 -> V_101 ) ;
V_3 -> V_102 = V_81 -> V_101 -> V_72 ;
F_80 ( V_2 ) ;
return V_3 ;
V_94:
F_5 ( & V_10 , V_3 -> V_11 ) ;
V_93:
F_7 ( V_85 ) ;
return NULL ;
}
struct V_3 * F_81 ( struct V_34 * V_34 ,
struct V_80 * V_81 )
{
V_81 -> V_74 = V_103 ;
return F_70 ( V_34 , V_81 , & V_12 ,
V_104 ) ;
}
struct V_3 * F_82 ( struct V_34 * V_34 ,
struct V_80 * V_81 )
{
if ( V_81 -> V_86 > 1 )
return NULL ;
V_81 -> V_74 = F_83 ( V_81 -> V_74 , V_103 ) ;
return F_70 ( V_34 , V_81 , & V_13 ,
V_104 ) ;
}
struct V_3 * F_84 ( struct V_34 * V_34 ,
struct V_80 * V_81 )
{
V_81 -> V_74 = V_103 ;
return F_70 ( V_34 , V_81 , & V_105 ,
V_104 ) ;
}
