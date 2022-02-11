static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
const char * V_8 ;
V_7 = F_2 ( V_4 , struct V_6 , V_9 ) ;
V_8 = F_3 ( V_7 -> V_10 ) ;
F_4 ( L_1 ,
V_7 -> V_11 , V_7 -> V_12 , V_8 ) ;
if ( ! V_8 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_2 , V_8 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
const char * V_8 ;
enum V_15 V_16 ;
V_7 = F_2 ( V_4 , struct V_6 , V_17 ) ;
V_16 = F_7 ( V_7 -> V_10 ) ;
switch ( V_16 ) {
case V_18 : V_8 = L_3 ; break;
case V_19 : V_8 = L_4 ; break;
case V_20 : V_8 = L_5 ; break;
case V_21 : V_8 = L_6 ; break;
default: V_8 = L_7 ; break;
}
F_4 ( L_8 ,
V_7 -> V_11 , V_7 -> V_12 , V_8 ) ;
return F_5 ( V_5 , V_14 , L_2 , V_8 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
long V_22 ;
V_7 = F_2 ( V_4 , struct V_6 , V_23 ) ;
V_22 = F_9 ( V_7 -> V_10 ) ;
F_4 ( L_9 ,
V_7 -> V_11 , V_7 -> V_12 , V_22 ) ;
return F_5 ( V_5 , V_14 , L_10 , V_22 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
long V_22 ;
V_7 = F_2 ( V_4 , struct V_6 , V_24 ) ;
V_22 = F_11 ( V_7 -> V_10 ) ;
F_4 ( L_11 ,
V_7 -> V_11 , V_7 -> V_12 , V_22 ) ;
return F_5 ( V_5 , V_14 , L_10 , V_22 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
int V_22 ;
int V_25 ;
unsigned int V_26 = 0 ;
V_7 = F_2 ( V_4 , struct V_6 , V_27 ) ;
V_25 = F_13 ( V_7 -> V_10 , & V_22 ) ;
if ( V_25 < 0 ) return V_25 ;
V_25 = F_14 ( V_7 -> V_10 , ~ 0 , V_22 ,
V_5 , V_14 - 1 , & V_26 ) ;
F_4 ( L_12 ,
V_7 -> V_11 , V_7 -> V_12 , V_26 , V_5 , V_22 ) ;
V_5 [ V_26 ] = '\n' ;
return V_26 + 1 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
int V_22 ;
int V_25 ;
unsigned int V_26 = 0 ;
V_7 = F_2 ( V_4 , struct V_6 , V_28 ) ;
V_25 = F_16 ( V_7 -> V_10 , & V_22 ) ;
if ( V_25 < 0 ) return V_25 ;
V_25 = F_14 ( V_7 -> V_10 , ~ 0 , V_22 ,
V_5 , V_14 - 1 , & V_26 ) ;
F_4 ( L_13 ,
V_7 -> V_11 , V_7 -> V_12 , V_26 , V_5 , V_22 ) ;
V_5 [ V_26 ] = '\n' ;
return V_26 + 1 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
int V_22 ;
int V_25 ;
unsigned int V_26 = 0 ;
V_7 = F_2 ( V_4 , struct V_6 , V_29 ) ;
V_25 = F_16 ( V_7 -> V_10 , & V_22 ) ;
if ( V_25 < 0 ) return V_25 ;
V_25 = F_18 ( V_7 -> V_10 , ~ 0 , V_22 ,
V_5 , V_14 - 1 , & V_26 ) ;
F_4 ( L_14 ,
V_7 -> V_11 , V_7 -> V_12 , V_26 , V_5 , V_22 ) ;
V_5 [ V_26 ] = '\n' ;
return V_26 + 1 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
long V_22 ;
unsigned int V_30 , V_31 , V_32 ;
V_7 = F_2 ( V_4 , struct V_6 , V_33 ) ;
V_32 = F_20 ( V_7 -> V_10 ) ;
V_30 = 0 ;
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ ) {
F_21 ( V_7 -> V_10 , V_22 , V_5 + V_30 ,
V_14 - V_30 , & V_31 ) ;
if ( ! V_31 ) continue;
V_30 += V_31 ;
if ( V_30 >= V_14 ) break;
V_5 [ V_30 ] = '\n' ;
V_30 ++ ;
}
F_4 ( L_15 ,
V_7 -> V_11 , V_7 -> V_12 ) ;
return V_30 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
int V_34 , V_35 ;
unsigned int V_30 , V_31 ;
V_7 = F_2 ( V_4 , struct V_6 , V_36 ) ;
V_34 = F_23 ( V_7 -> V_10 ) ;
V_30 = 0 ;
for ( V_35 = 1 ; V_34 ; V_35 <<= 1 ) {
if ( ! ( V_35 & V_34 ) ) continue;
V_34 &= ~ V_35 ;
F_21 ( V_7 -> V_10 , V_35 , V_5 + V_30 ,
V_14 - V_30 , & V_31 ) ;
V_30 += V_31 ;
if ( V_30 >= V_14 ) break;
V_5 [ V_30 ] = '\n' ;
V_30 ++ ;
}
F_4 ( L_16 ,
V_7 -> V_11 , V_7 -> V_12 ) ;
return V_30 ;
}
static int F_24 ( struct V_6 * V_7 , int V_37 ,
const char * V_5 , unsigned int V_38 )
{
int V_25 ;
int V_39 , V_22 ;
if ( V_37 ) {
V_25 = F_25 ( V_7 -> V_10 , V_5 , V_38 ,
& V_39 , & V_22 ) ;
} else {
V_25 = F_26 ( V_7 -> V_10 , V_5 , V_38 ,
& V_39 , & V_22 ) ;
}
if ( V_25 < 0 ) return V_25 ;
V_25 = F_27 ( V_7 -> V_10 , V_39 , V_22 ) ;
F_28 ( V_7 -> V_11 -> V_40 . V_41 ) ;
return V_25 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_38 )
{
struct V_6 * V_7 ;
int V_25 ;
V_7 = F_2 ( V_4 , struct V_6 , V_28 ) ;
F_4 ( L_17 ,
V_7 -> V_11 , V_7 -> V_12 , ( int ) V_38 , V_5 ) ;
V_25 = F_24 ( V_7 , 0 , V_5 , V_38 ) ;
if ( ! V_25 ) V_25 = V_38 ;
return V_25 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_38 )
{
struct V_6 * V_7 ;
int V_25 ;
V_7 = F_2 ( V_4 , struct V_6 , V_29 ) ;
F_4 ( L_18 ,
V_7 -> V_11 , V_7 -> V_12 , ( int ) V_38 , V_5 ) ;
V_25 = F_24 ( V_7 , 1 , V_5 , V_38 ) ;
if ( ! V_25 ) V_25 = V_38 ;
return V_25 ;
}
static void F_31 ( struct V_42 * V_43 , int V_12 )
{
struct V_6 * V_7 ;
struct V_44 * V_10 ;
unsigned int V_26 , V_45 ;
int V_25 ;
V_10 = F_32 ( V_43 -> V_40 . V_41 , V_12 ) ;
if ( ! V_10 ) return;
V_7 = F_33 ( sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 ) return;
F_4 ( L_19 , V_7 ) ;
V_7 -> V_10 = V_10 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_11 = V_43 ;
V_7 -> V_47 = NULL ;
if ( V_43 -> V_48 ) {
V_43 -> V_48 -> V_47 = V_7 ;
} else {
V_43 -> V_49 = V_7 ;
}
V_43 -> V_48 = V_7 ;
F_34 ( & V_7 -> V_9 . V_4 ) ;
V_7 -> V_9 . V_4 . V_8 = L_20 ;
V_7 -> V_9 . V_4 . V_50 = V_51 ;
V_7 -> V_9 . V_52 = F_1 ;
F_34 ( & V_7 -> V_17 . V_4 ) ;
V_7 -> V_17 . V_4 . V_8 = L_21 ;
V_7 -> V_17 . V_4 . V_50 = V_51 ;
V_7 -> V_17 . V_52 = F_6 ;
F_34 ( & V_7 -> V_23 . V_4 ) ;
V_7 -> V_23 . V_4 . V_8 = L_22 ;
V_7 -> V_23 . V_4 . V_50 = V_51 ;
V_7 -> V_23 . V_52 = F_8 ;
F_34 ( & V_7 -> V_24 . V_4 ) ;
V_7 -> V_24 . V_4 . V_8 = L_23 ;
V_7 -> V_24 . V_4 . V_50 = V_51 ;
V_7 -> V_24 . V_52 = F_10 ;
F_34 ( & V_7 -> V_27 . V_4 ) ;
V_7 -> V_27 . V_4 . V_8 = L_24 ;
V_7 -> V_27 . V_4 . V_50 = V_51 ;
V_7 -> V_27 . V_52 = F_12 ;
F_34 ( & V_7 -> V_28 . V_4 ) ;
V_7 -> V_28 . V_4 . V_8 = L_25 ;
V_7 -> V_28 . V_4 . V_50 = V_51 ;
F_34 ( & V_7 -> V_29 . V_4 ) ;
V_7 -> V_29 . V_4 . V_8 = L_26 ;
V_7 -> V_29 . V_4 . V_50 = V_51 ;
F_34 ( & V_7 -> V_33 . V_4 ) ;
V_7 -> V_33 . V_4 . V_8 = L_27 ;
V_7 -> V_33 . V_4 . V_50 = V_51 ;
V_7 -> V_33 . V_52 = F_19 ;
F_34 ( & V_7 -> V_36 . V_4 ) ;
V_7 -> V_36 . V_4 . V_8 = L_28 ;
V_7 -> V_36 . V_4 . V_50 = V_51 ;
V_7 -> V_36 . V_52 = F_22 ;
if ( F_35 ( V_10 ) ) {
V_7 -> V_28 . V_4 . V_50 |= V_53 | V_54 ;
V_7 -> V_29 . V_4 . V_50 |= V_53 | V_54 ;
}
V_45 = 0 ;
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_9 . V_4 ;
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_17 . V_4 ;
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_28 . V_4 ;
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_27 . V_4 ;
V_7 -> V_28 . V_52 = F_15 ;
V_7 -> V_28 . V_56 = F_29 ;
if ( F_36 ( V_10 ) ) {
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_29 . V_4 ;
V_7 -> V_29 . V_52 = F_17 ;
V_7 -> V_29 . V_56 = F_30 ;
}
switch ( F_7 ( V_10 ) ) {
case V_19 :
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_33 . V_4 ;
break;
case V_18 :
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_23 . V_4 ;
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_24 . V_4 ;
break;
case V_20 :
V_7 -> V_55 [ V_45 ++ ] = & V_7 -> V_36 . V_4 ;
break;
default: break;
}
V_26 = F_5 ( V_7 -> V_8 , sizeof( V_7 -> V_8 ) - 1 , L_29 ,
F_37 ( V_10 ) ) ;
V_7 -> V_8 [ V_26 ] = 0 ;
V_7 -> V_57 . V_8 = V_7 -> V_8 ;
V_7 -> V_57 . V_58 = V_7 -> V_55 ;
V_25 = F_38 ( & V_43 -> V_2 -> V_59 , & V_7 -> V_57 ) ;
if ( V_25 ) {
F_39 ( V_60 ,
L_30 ,
V_25 ) ;
return;
}
V_7 -> V_61 = ! 0 ;
}
static void F_40 ( struct V_42 * V_43 )
{
struct V_62 * V_63 ;
int V_25 ;
V_63 = F_33 ( sizeof( * V_63 ) , V_46 ) ;
if ( ! V_63 ) return;
F_34 ( & V_63 -> V_64 . V_4 ) ;
V_63 -> V_64 . V_4 . V_8 = L_31 ;
V_63 -> V_64 . V_4 . V_50 = V_51 | V_53 | V_54 ;
V_63 -> V_64 . V_52 = V_65 ;
V_63 -> V_64 . V_56 = V_66 ;
F_34 ( & V_63 -> V_67 . V_4 ) ;
V_63 -> V_67 . V_4 . V_8 = L_32 ;
V_63 -> V_67 . V_4 . V_50 = V_51 ;
V_63 -> V_67 . V_52 = V_68 ;
V_43 -> V_69 = V_63 ;
V_25 = F_41 ( V_43 -> V_2 , & V_63 -> V_64 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_63 -> V_70 = ! 0 ;
}
V_25 = F_41 ( V_43 -> V_2 , & V_63 -> V_67 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_63 -> V_71 = ! 0 ;
}
}
static void F_42 ( struct V_42 * V_43 )
{
if ( ! V_43 -> V_69 ) return;
if ( V_43 -> V_69 -> V_71 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_69 -> V_67 ) ;
}
if ( V_43 -> V_69 -> V_70 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_69 -> V_64 ) ;
}
F_44 ( V_43 -> V_69 ) ;
V_43 -> V_69 = NULL ;
}
static void F_45 ( struct V_42 * V_43 )
{
unsigned int V_72 , V_26 ;
V_26 = F_46 ( V_43 -> V_40 . V_41 ) ;
for ( V_72 = 0 ; V_72 < V_26 ; V_72 ++ ) {
F_31 ( V_43 , V_72 ) ;
}
}
static void F_47 ( struct V_42 * V_43 )
{
struct V_6 * V_73 , * V_74 ;
for ( V_73 = V_43 -> V_49 ; V_73 ; V_73 = V_74 ) {
V_74 = V_73 -> V_47 ;
if ( V_73 -> V_61 ) {
F_48 ( & V_43 -> V_2 -> V_59 , & V_73 -> V_57 ) ;
}
F_4 ( L_34 , V_73 ) ;
F_44 ( V_73 ) ;
}
}
static void F_49 ( struct V_75 * V_75 )
{
struct V_76 * V_77 ;
V_77 = F_2 ( V_75 , struct V_76 , V_75 ) ;
F_4 ( L_35 , V_77 ) ;
F_44 ( V_77 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_4 ( L_36 , V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_51 ( struct V_42 * V_43 )
{
struct V_1 * V_78 ;
if ( ! V_43 -> V_2 ) return;
#ifdef F_52
F_42 ( V_43 ) ;
#endif
F_47 ( V_43 ) ;
if ( V_43 -> V_79 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_80 ) ;
}
if ( V_43 -> V_81 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_82 ) ;
}
if ( V_43 -> V_83 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_84 ) ;
}
if ( V_43 -> V_85 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_86 ) ;
}
if ( V_43 -> V_87 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_88 ) ;
}
if ( V_43 -> V_89 ) {
F_43 ( V_43 -> V_2 ,
& V_43 -> V_90 ) ;
}
F_4 ( L_37 , V_43 -> V_2 ) ;
F_53 ( V_43 -> V_2 , NULL ) ;
V_78 = V_43 -> V_2 -> V_91 ;
V_43 -> V_2 -> V_91 = NULL ;
F_54 ( V_78 ) ;
F_55 ( V_43 -> V_2 ) ;
V_43 -> V_2 = NULL ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_38 ,
F_58 ( V_43 -> V_40 . V_41 ,
V_92 ) ) ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_2 ,
F_60 ( V_43 -> V_40 . V_41 ) ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_2 ,
F_62 ( V_43 -> V_40 . V_41 ) ) ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_2 ,
F_64 ( V_43 -> V_40 . V_41 ) ) ;
}
static T_1 F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_38 ,
F_58 ( V_43 -> V_40 . V_41 ,
V_93 ) ) ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_5 ( V_5 , V_14 , L_38 ,
F_67 ( V_43 -> V_40 . V_41 ) ) ;
}
static void F_68 ( struct V_42 * V_43 ,
struct V_76 * V_94 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
int V_25 ;
V_96 = F_69 ( V_43 -> V_40 . V_41 ) ;
if ( ! V_96 ) return;
V_2 = F_33 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 ) return;
F_4 ( L_39 , V_2 ) ;
V_2 -> V_75 = & V_94 -> V_75 ;
F_70 ( V_2 , L_40 ,
F_71 ( V_43 -> V_40 . V_41 ) ) ;
V_2 -> V_91 = F_72 ( & V_96 -> V_78 ) ;
V_43 -> V_2 = V_2 ;
F_53 ( V_2 , V_43 ) ;
V_25 = F_73 ( V_2 ) ;
if ( V_25 ) {
F_39 ( V_60 ,
L_41 ) ;
F_54 ( V_2 ) ;
return;
}
F_34 ( & V_43 -> V_86 . V_4 ) ;
V_43 -> V_86 . V_4 . V_8 = L_42 ;
V_43 -> V_86 . V_4 . V_50 = V_51 ;
V_43 -> V_86 . V_52 = F_56 ;
V_43 -> V_86 . V_56 = NULL ;
V_25 = F_41 ( V_43 -> V_2 ,
& V_43 -> V_86 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_43 -> V_85 = ! 0 ;
}
F_34 ( & V_43 -> V_88 . V_4 ) ;
V_43 -> V_88 . V_4 . V_8 = L_43 ;
V_43 -> V_88 . V_4 . V_50 = V_51 ;
V_43 -> V_88 . V_52 = F_65 ;
V_43 -> V_88 . V_56 = NULL ;
V_25 = F_41 ( V_43 -> V_2 ,
& V_43 -> V_88 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_43 -> V_87 = ! 0 ;
}
F_34 ( & V_43 -> V_90 . V_4 ) ;
V_43 -> V_90 . V_4 . V_8 = L_44 ;
V_43 -> V_90 . V_4 . V_50 = V_51 ;
V_43 -> V_90 . V_52 = F_66 ;
V_43 -> V_90 . V_56 = NULL ;
V_25 = F_41 ( V_43 -> V_2 , & V_43 -> V_90 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_43 -> V_89 = ! 0 ;
}
F_34 ( & V_43 -> V_84 . V_4 ) ;
V_43 -> V_84 . V_4 . V_8 = L_45 ;
V_43 -> V_84 . V_4 . V_50 = V_51 ;
V_43 -> V_84 . V_52 = F_59 ;
V_43 -> V_84 . V_56 = NULL ;
V_25 = F_41 ( V_43 -> V_2 ,
& V_43 -> V_84 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_43 -> V_83 = ! 0 ;
}
F_34 ( & V_43 -> V_82 . V_4 ) ;
V_43 -> V_82 . V_4 . V_8 = L_46 ;
V_43 -> V_82 . V_4 . V_50 = V_51 ;
V_43 -> V_82 . V_52 = F_61 ;
V_43 -> V_82 . V_56 = NULL ;
V_25 = F_41 ( V_43 -> V_2 ,
& V_43 -> V_82 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_43 -> V_81 = ! 0 ;
}
F_34 ( & V_43 -> V_80 . V_4 ) ;
V_43 -> V_80 . V_4 . V_8 = L_47 ;
V_43 -> V_80 . V_4 . V_50 = V_51 ;
V_43 -> V_80 . V_52 = F_63 ;
V_43 -> V_80 . V_56 = NULL ;
V_25 = F_41 ( V_43 -> V_2 ,
& V_43 -> V_80 ) ;
if ( V_25 < 0 ) {
F_39 ( V_60 ,
L_33 ,
V_25 ) ;
} else {
V_43 -> V_79 = ! 0 ;
}
F_45 ( V_43 ) ;
#ifdef F_52
F_40 ( V_43 ) ;
#endif
}
static void F_74 ( struct V_97 * V_98 )
{
struct V_42 * V_43 ;
V_43 = F_2 ( V_98 , struct V_42 , V_40 ) ;
if ( ! V_43 -> V_40 . V_99 -> V_100 ) return;
F_39 ( V_101 , L_48 , V_43 ) ;
F_51 ( V_43 ) ;
F_75 ( & V_43 -> V_40 ) ;
F_44 ( V_43 ) ;
}
struct V_42 * F_76 ( struct V_102 * V_103 ,
struct V_76 * V_94 )
{
struct V_42 * V_43 ;
V_43 = F_33 ( sizeof( * V_43 ) , V_46 ) ;
if ( ! V_43 ) return V_43 ;
F_39 ( V_101 , L_49 , V_43 ) ;
F_77 ( & V_43 -> V_40 , V_103 ) ;
V_43 -> V_40 . V_104 = F_74 ;
F_68 ( V_43 , V_94 ) ;
return V_43 ;
}
struct V_76 * F_78 ( void )
{
struct V_76 * V_77 ;
V_77 = F_33 ( sizeof( * V_77 ) , V_46 ) ;
if ( ! V_77 ) return V_77 ;
F_4 ( L_50 ,
V_77 ) ;
V_77 -> V_75 . V_8 = L_51 ;
V_77 -> V_75 . V_105 = F_49 ;
V_77 -> V_75 . V_106 = F_50 ;
if ( F_79 ( & V_77 -> V_75 ) ) {
F_4 (
L_52 , V_77 ) ;
F_44 ( V_77 ) ;
V_77 = NULL ;
}
return V_77 ;
}
void F_80 ( struct V_76 * V_77 )
{
F_4 ( L_53 , V_77 ) ;
F_81 ( & V_77 -> V_75 ) ;
}
static T_1 V_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
F_82 ( V_43 -> V_40 . V_41 ) ;
return F_83 ( V_43 -> V_40 . V_41 , V_5 , V_14 ) ;
}
static T_1 V_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_42 * V_43 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
return F_84 ( V_43 -> V_40 . V_41 , V_5 , V_14 ) ;
}
static T_1 V_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_38 )
{
struct V_42 * V_43 ;
int V_25 ;
V_43 = F_57 ( V_2 ) ;
if ( ! V_43 ) return - V_13 ;
V_25 = F_85 ( V_43 -> V_40 . V_41 , V_5 , V_38 ) ;
if ( V_25 < 0 ) return V_25 ;
return V_38 ;
}
