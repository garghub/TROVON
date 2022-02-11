static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
F_4 ( V_2 , L_1 , V_6 ) ;
F_5 ( & V_5 -> V_2 , & V_5 -> V_7 ) ;
F_6 ( & V_3 -> V_8 , V_5 -> V_9 ) ;
F_7 ( V_5 -> V_10 ) ;
F_7 ( V_5 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_11 : false ;
}
struct V_5 * F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_9 ( V_2 , struct V_5 , V_2 ) ;
F_10 ( ! F_8 ( V_2 ) ) ;
return V_5 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
switch ( V_5 -> V_15 ) {
case V_16 :
return sprintf ( V_14 , L_2 ) ;
case V_17 :
return sprintf ( V_14 , L_3 ) ;
default:
return sprintf ( V_14 , L_4 ) ;
}
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 = 0 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_20 )
V_19 = - V_21 ;
else {
T_2 V_22 = V_18 - 1 ;
if ( strncmp ( V_14 , L_3 , V_22 ) == 0
|| strncmp ( V_14 , L_5 , V_22 ) == 0 ) {
V_5 -> V_15 = V_17 ;
} else if ( strncmp ( V_14 , L_2 , V_22 ) == 0
|| strncmp ( V_14 , L_6 , V_22 ) == 0 )
V_5 -> V_15 = V_16 ;
else if ( strncmp ( V_14 , L_4 , V_22 ) == 0
|| strncmp ( V_14 , L_7 , V_22 ) == 0 )
V_5 -> V_15 = V_23 ;
else
V_19 = - V_24 ;
}
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
return sprintf ( V_14 , L_11 , V_5 -> V_25 ) ;
}
static const unsigned long * F_19 ( void )
{
const unsigned long V_26 [] = {
V_27 ,
#ifdef F_20
V_28 ,
#ifdef F_21
V_29 ,
#endif
#endif
0 ,
} ;
static unsigned long V_30 [ F_22 ( V_26 ) ] ;
memcpy ( V_30 , V_26 , sizeof( V_30 ) ) ;
return V_30 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_19 = F_24 ( V_2 , V_14 , & V_5 -> V_25 ,
F_19 () ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
if ( V_5 -> V_10 )
return sprintf ( V_14 , L_12 , V_5 -> V_10 ) ;
return sprintf ( V_14 , L_10 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
V_19 = F_27 ( V_2 , & V_5 -> V_10 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_17 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_15 ( V_2 ) ;
V_19 = sprintf ( V_14 , L_1 , V_5 -> V_7
? F_29 ( & V_5 -> V_7 -> V_2 ) : L_9 ) ;
F_16 ( V_2 ) ;
return V_19 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_19 = F_31 ( V_2 , & V_5 -> V_7 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_19 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_20 ) {
struct V_31 * V_32 = V_5 -> V_32 ;
T_3 V_33 = F_33 ( V_32 -> V_34 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
T_4 V_36 = F_34 ( V_32 -> V_36 ) ;
struct V_37 * V_38 = F_35 ( & V_7 -> V_2 ) ;
V_19 = sprintf ( V_14 , L_13 , ( unsigned long long ) V_38 -> V_39 . V_40
+ V_36 + V_33 ) ;
} else {
V_19 = - V_41 ;
}
F_17 ( V_2 ) ;
return V_19 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_20 ) {
struct V_31 * V_32 = V_5 -> V_32 ;
T_3 V_33 = F_33 ( V_32 -> V_34 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
T_4 V_36 = F_34 ( V_32 -> V_36 ) ;
T_4 V_42 = F_34 ( V_32 -> V_42 ) ;
struct V_37 * V_38 = F_35 ( & V_7 -> V_2 ) ;
V_19 = sprintf ( V_14 , L_14 , ( unsigned long long )
F_37 ( & V_38 -> V_39 ) - V_36
- V_42 - V_33 ) ;
} else {
V_19 = - V_41 ;
}
F_17 ( V_2 ) ;
return V_19 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
return F_39 ( 0 , F_19 () , V_14 ) ;
}
struct V_1 * F_40 ( struct V_5 * V_5 ,
struct V_35 * V_7 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
if ( ! V_5 )
return NULL ;
V_5 -> V_15 = V_23 ;
V_5 -> V_25 = V_43 ;
V_2 = & V_5 -> V_2 ;
F_41 ( & V_5 -> V_2 ) ;
if ( V_7 && ! F_42 ( & V_5 -> V_2 , V_7 , & V_5 -> V_7 ) ) {
F_4 ( & V_7 -> V_2 , L_15 ,
V_6 , F_29 ( V_7 -> V_44 ) ) ;
F_43 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_5 * F_44 ( struct V_3 * V_3 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_45 ( sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = F_46 ( & V_3 -> V_8 , 0 , 0 , V_45 ) ;
if ( V_5 -> V_9 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_2 = & V_5 -> V_2 ;
F_47 ( V_2 , L_16 , V_3 -> V_9 , V_5 -> V_9 ) ;
V_2 -> V_46 = V_47 ;
V_2 -> type = & V_11 ;
V_2 -> V_4 = & V_3 -> V_2 ;
return V_5 ;
}
struct V_1 * F_48 ( struct V_3 * V_3 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
if ( ! F_49 ( & V_3 -> V_2 ) )
return NULL ;
V_5 = F_44 ( V_3 ) ;
V_2 = F_40 ( V_5 , NULL ) ;
F_50 ( V_2 ) ;
return V_2 ;
}
int F_51 ( struct V_5 * V_5 , const char * V_48 )
{
T_3 V_49 , V_33 ;
unsigned long V_25 ;
enum V_50 V_15 ;
struct V_37 * V_38 ;
struct V_31 * V_32 = V_5 -> V_32 ;
struct V_35 * V_7 = V_5 -> V_7 ;
const T_5 * V_51 = F_52 ( & V_7 -> V_2 ) ;
if ( ! V_32 || ! V_7 )
return - V_52 ;
if ( ! F_49 ( V_5 -> V_2 . V_4 ) )
return - V_52 ;
if ( F_53 ( V_7 , V_53 , V_32 , sizeof( * V_32 ) , 0 ) )
return - V_41 ;
if ( memcmp ( V_32 -> V_54 , V_48 , V_55 ) != 0 )
return - V_52 ;
V_49 = F_54 ( V_32 -> V_49 ) ;
V_32 -> V_49 = 0 ;
if ( V_49 != F_55 ( (struct V_56 * ) V_32 ) )
return - V_52 ;
V_32 -> V_49 = F_56 ( V_49 ) ;
if ( memcmp ( V_32 -> V_51 , V_51 , 16 ) != 0 )
return - V_52 ;
if ( F_57 ( V_32 -> V_57 ) < 1 ) {
V_32 -> V_36 = 0 ;
V_32 -> V_42 = 0 ;
}
if ( F_57 ( V_32 -> V_57 ) < 2 )
V_32 -> V_25 = 0 ;
switch ( F_58 ( V_32 -> V_15 ) ) {
case V_16 :
case V_17 :
break;
default:
return - V_41 ;
}
V_25 = F_58 ( V_32 -> V_25 ) ;
V_33 = F_54 ( V_32 -> V_34 ) ;
if ( V_25 == 0 )
V_25 = 1UL << F_59 ( V_33 ) ;
V_15 = F_58 ( V_32 -> V_15 ) ;
if ( ! V_5 -> V_10 ) {
V_5 -> V_10 = F_60 ( V_32 -> V_10 , 16 , V_45 ) ;
if ( ! V_5 -> V_10 )
return - V_58 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_15 = V_15 ;
} else {
if ( memcmp ( V_5 -> V_10 , V_32 -> V_10 , 16 ) != 0 )
return - V_52 ;
if ( V_5 -> V_25 != V_25 || V_5 -> V_15 != V_15 ) {
F_61 ( & V_5 -> V_2 ,
L_17 ) ;
F_4 ( & V_5 -> V_2 , L_18 ,
V_5 -> V_25 , V_25 , V_5 -> V_15 ,
V_15 ) ;
return - V_24 ;
}
}
if ( V_25 > F_62 ( V_7 ) ) {
F_61 ( & V_5 -> V_2 , L_19 ,
V_25 , F_62 ( V_7 ) ) ;
return - V_24 ;
}
V_38 = F_35 ( & V_7 -> V_2 ) ;
if ( V_33 >= F_37 ( & V_38 -> V_39 ) ) {
F_61 ( & V_5 -> V_2 , L_20 ,
F_29 ( & V_7 -> V_2 ) ) ;
return - V_21 ;
}
if ( ( V_25 && ! F_63 ( V_33 , V_25 ) )
|| ! F_63 ( V_33 , V_27 ) ) {
F_61 ( & V_5 -> V_2 ,
L_21 ,
V_33 , V_25 ) ;
return - V_41 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 , struct V_35 * V_7 )
{
int V_19 ;
struct V_5 * V_5 ;
struct V_1 * V_59 ;
struct V_31 * V_32 ;
struct V_3 * V_3 = F_2 ( V_7 -> V_2 . V_4 ) ;
if ( V_7 -> V_60 )
return - V_52 ;
switch ( V_7 -> V_61 ) {
case V_62 :
case V_63 :
break;
default:
return - V_52 ;
}
F_15 ( & V_7 -> V_2 ) ;
V_5 = F_44 ( V_3 ) ;
V_59 = F_40 ( V_5 , V_7 ) ;
F_16 ( & V_7 -> V_2 ) ;
if ( ! V_59 )
return - V_58 ;
V_32 = F_65 ( V_2 , sizeof( * V_32 ) , V_45 ) ;
V_5 = F_3 ( V_59 ) ;
V_5 -> V_32 = V_32 ;
V_19 = F_51 ( V_5 , V_64 ) ;
F_4 ( V_2 , L_22 , V_6 ,
V_19 == 0 ? F_29 ( V_59 ) : L_23 ) ;
if ( V_19 < 0 ) {
F_5 ( V_59 , & V_5 -> V_7 ) ;
F_43 ( V_59 ) ;
} else
F_50 ( V_59 ) ;
return V_19 ;
}
static unsigned long F_66 ( T_6 V_65 )
{
unsigned long V_66 = F_67 ( V_65 ) ;
return F_68 ( V_66 ) ;
}
static unsigned long F_69 ( T_6 V_65 )
{
unsigned long V_67 = F_67 ( V_68 ) ;
unsigned long V_66 = F_67 ( V_65 ) ;
V_67 += V_66 - F_68 ( V_66 ) ;
return V_67 ;
}
static struct V_69 * F_70 ( struct V_5 * V_5 ,
struct V_70 * V_39 , struct V_69 * V_71 )
{
struct V_31 * V_32 = V_5 -> V_32 ;
T_3 V_33 = F_54 ( V_32 -> V_34 ) ;
T_4 V_36 = F_34 ( V_32 -> V_36 ) ;
T_4 V_42 = F_34 ( V_32 -> V_42 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
struct V_37 * V_38 = F_35 ( & V_7 -> V_2 ) ;
T_6 V_65 = V_38 -> V_39 . V_40 + V_36 ;
struct V_69 V_72 = {
. V_66 = F_66 ( V_65 ) ,
. V_67 = F_69 ( V_65 ) ,
} ;
memcpy ( V_39 , & V_38 -> V_39 , sizeof( * V_39 ) ) ;
V_39 -> V_40 += V_36 ;
V_39 -> V_73 -= V_42 ;
if ( V_5 -> V_15 == V_16 ) {
if ( V_33 < V_68 )
return F_71 ( - V_24 ) ;
V_5 -> V_74 = F_54 ( V_32 -> V_74 ) ;
V_71 = NULL ;
} else if ( V_5 -> V_15 == V_17 ) {
V_5 -> V_74 = F_72 ( ( F_37 ( V_39 )
- V_33 ) / V_27 ) ;
if ( F_54 ( V_5 -> V_32 -> V_74 ) > V_5 -> V_74 )
F_73 ( & V_5 -> V_2 ,
L_24 ,
F_54 ( V_5 -> V_32 -> V_74 ) ,
V_5 -> V_74 ) ;
memcpy ( V_71 , & V_72 , sizeof( * V_71 ) ) ;
V_71 -> free = F_67 ( V_33 - V_68 ) ;
V_71 -> V_75 = 0 ;
} else
return F_71 ( - V_41 ) ;
return V_71 ;
}
static int F_74 ( struct V_5 * V_5 )
{
T_4 V_76 = F_75 ( & V_5 -> V_2 ) ? V_77 : 0 ;
struct V_35 * V_7 = V_5 -> V_7 ;
T_4 V_36 = 0 , V_42 = 0 ;
T_6 V_40 , V_78 ;
struct V_37 * V_38 ;
struct V_3 * V_3 ;
struct V_31 * V_32 ;
unsigned long V_74 ;
T_7 V_33 ;
const char * V_48 ;
T_3 V_49 ;
int V_19 ;
V_32 = F_65 ( & V_5 -> V_2 , sizeof( * V_32 ) , V_45 ) ;
if ( ! V_32 )
return - V_58 ;
V_5 -> V_32 = V_32 ;
if ( F_75 ( & V_5 -> V_2 ) )
V_48 = V_79 ;
else
V_48 = V_64 ;
V_19 = F_51 ( V_5 , V_48 ) ;
if ( V_19 != - V_52 )
return V_19 ;
;
V_3 = F_2 ( V_5 -> V_2 . V_4 ) ;
if ( V_3 -> V_80 ) {
F_73 ( & V_5 -> V_2 ,
L_25 ,
F_29 ( & V_3 -> V_2 ) ) ;
return - V_41 ;
}
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_38 = F_35 ( & V_7 -> V_2 ) ;
V_40 = F_76 ( V_38 -> V_39 . V_40 ) ;
V_78 = F_37 ( & V_38 -> V_39 ) ;
if ( F_77 ( V_40 , V_78 , V_81 ,
V_82 ) == V_83 ) {
V_40 = V_38 -> V_39 . V_40 ;
V_36 = F_78 ( V_40 ) - V_40 ;
}
V_40 = V_38 -> V_39 . V_40 ;
V_78 = F_78 ( V_40 + V_78 ) - V_40 ;
if ( F_77 ( V_40 , V_78 , V_81 ,
V_82 ) == V_83 ) {
V_78 = F_37 ( & V_38 -> V_39 ) ;
V_42 = V_40 + V_78 - F_76 ( V_40 + V_78 ) ;
}
if ( V_36 + V_42 )
F_73 ( & V_5 -> V_2 , L_26 ,
F_29 ( & V_7 -> V_2 ) , V_36 + V_42 ) ;
V_40 += V_36 ;
V_78 = F_37 ( & V_38 -> V_39 ) ;
V_74 = F_72 ( ( V_78 - V_36 - V_42 - V_68 )
/ V_27 ) ;
if ( V_5 -> V_15 == V_17 ) {
V_33 = F_79 ( V_40 + V_68 + 64 * V_74 + V_76 ,
F_80 ( V_5 -> V_25 , V_84 ) ) - V_40 ;
} else if ( V_5 -> V_15 == V_16 )
V_33 = F_79 ( V_40 + V_68 + V_76 ,
V_5 -> V_25 ) - V_40 ;
else
return - V_41 ;
if ( V_33 + V_36 + V_42 >= V_78 ) {
F_61 ( & V_5 -> V_2 , L_27 ,
F_29 ( & V_7 -> V_2 ) ) ;
return - V_41 ;
}
V_74 = ( V_78 - V_33 - V_36 - V_42 ) / V_53 ;
V_32 -> V_15 = F_81 ( V_5 -> V_15 ) ;
V_32 -> V_34 = F_56 ( V_33 ) ;
V_32 -> V_74 = F_56 ( V_74 ) ;
memcpy ( V_32 -> V_54 , V_48 , V_55 ) ;
memcpy ( V_32 -> V_10 , V_5 -> V_10 , 16 ) ;
memcpy ( V_32 -> V_51 , F_52 ( & V_7 -> V_2 ) , 16 ) ;
V_32 -> V_85 = F_82 ( 1 ) ;
V_32 -> V_57 = F_82 ( 2 ) ;
V_32 -> V_36 = F_81 ( V_36 ) ;
V_32 -> V_42 = F_81 ( V_42 ) ;
V_32 -> V_25 = F_81 ( V_5 -> V_25 ) ;
V_49 = F_55 ( (struct V_56 * ) V_32 ) ;
V_32 -> V_49 = F_56 ( V_49 ) ;
return F_83 ( V_7 , V_53 , V_32 , sizeof( * V_32 ) , 0 ) ;
}
struct V_69 * F_84 ( struct V_5 * V_5 ,
struct V_70 * V_39 , struct V_69 * V_71 )
{
int V_19 ;
if ( ! V_5 -> V_10 || ! V_5 -> V_7 )
return F_71 ( - V_52 ) ;
V_19 = F_74 ( V_5 ) ;
if ( V_19 )
return F_71 ( V_19 ) ;
return F_70 ( V_5 , V_39 , V_71 ) ;
}
