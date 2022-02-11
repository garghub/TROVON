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
static T_1 F_19 ( struct V_5 * V_5 , const char * V_14 )
{
unsigned long V_26 ;
int V_19 ;
V_19 = F_20 ( V_14 , 0 , & V_26 ) ;
if ( V_19 )
return V_19 ;
if ( ! F_21 ( V_26 ) || V_26 < V_27 || V_26 > V_28 )
return - V_24 ;
if ( V_5 -> V_2 . V_20 )
return - V_21 ;
else
V_5 -> V_25 = V_26 ;
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_19 = F_19 ( V_5 , V_14 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
if ( V_5 -> V_10 )
return sprintf ( V_14 , L_12 , V_5 -> V_10 ) ;
return sprintf ( V_14 , L_10 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
V_19 = F_25 ( V_2 , & V_5 -> V_10 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_17 ( V_2 ) ;
return V_19 ? V_19 : V_18 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_15 ( V_2 ) ;
V_19 = sprintf ( V_14 , L_1 , V_5 -> V_7
? F_27 ( & V_5 -> V_7 -> V_2 ) : L_9 ) ;
F_16 ( V_2 ) ;
return V_19 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_18 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_19 = F_29 ( V_2 , & V_5 -> V_7 , V_14 , V_18 ) ;
F_4 ( V_2 , L_8 , V_6 ,
V_19 , V_14 , V_14 [ V_18 - 1 ] == '\n' ? L_9 : L_10 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_19 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_20 ) {
struct V_29 * V_30 = V_5 -> V_30 ;
T_3 V_31 = F_31 ( V_30 -> V_32 ) ;
struct V_33 * V_7 = V_5 -> V_7 ;
T_4 V_34 = F_32 ( V_30 -> V_34 ) ;
struct V_35 * V_36 = F_33 ( & V_7 -> V_2 ) ;
V_19 = sprintf ( V_14 , L_13 , ( unsigned long long ) V_36 -> V_37 . V_38
+ V_34 + V_31 ) ;
} else {
V_19 = - V_39 ;
}
F_17 ( V_2 ) ;
return V_19 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
T_1 V_19 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_20 ) {
struct V_29 * V_30 = V_5 -> V_30 ;
T_3 V_31 = F_31 ( V_30 -> V_32 ) ;
struct V_33 * V_7 = V_5 -> V_7 ;
T_4 V_34 = F_32 ( V_30 -> V_34 ) ;
T_4 V_40 = F_32 ( V_30 -> V_40 ) ;
struct V_35 * V_36 = F_33 ( & V_7 -> V_2 ) ;
V_19 = sprintf ( V_14 , L_14 , ( unsigned long long )
F_35 ( & V_36 -> V_37 ) - V_34
- V_40 - V_31 ) ;
} else {
V_19 = - V_39 ;
}
F_17 ( V_2 ) ;
return V_19 ;
}
struct V_1 * F_36 ( struct V_5 * V_5 ,
struct V_33 * V_7 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
if ( ! V_5 )
return NULL ;
V_5 -> V_15 = V_23 ;
V_5 -> V_25 = V_41 ;
V_2 = & V_5 -> V_2 ;
F_37 ( & V_5 -> V_2 ) ;
if ( V_7 && ! F_38 ( & V_5 -> V_2 , V_7 , & V_5 -> V_7 ) ) {
F_4 ( & V_7 -> V_2 , L_15 ,
V_6 , F_27 ( V_7 -> V_42 ) ) ;
F_39 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_5 * F_40 ( struct V_3 * V_3 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_41 ( sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_9 = F_42 ( & V_3 -> V_8 , 0 , 0 , V_43 ) ;
if ( V_5 -> V_9 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_2 = & V_5 -> V_2 ;
F_43 ( V_2 , L_16 , V_3 -> V_9 , V_5 -> V_9 ) ;
V_2 -> V_44 = V_45 ;
V_2 -> type = & V_11 ;
V_2 -> V_4 = & V_3 -> V_2 ;
return V_5 ;
}
struct V_1 * F_44 ( struct V_3 * V_3 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
if ( ! F_45 ( & V_3 -> V_2 ) )
return NULL ;
V_5 = F_40 ( V_3 ) ;
V_2 = F_36 ( V_5 , NULL ) ;
F_46 ( V_2 ) ;
return V_2 ;
}
int F_47 ( struct V_5 * V_5 , const char * V_46 )
{
T_3 V_47 , V_31 ;
unsigned long V_25 ;
enum V_48 V_15 ;
struct V_35 * V_36 ;
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_33 * V_7 = V_5 -> V_7 ;
const T_5 * V_49 = F_48 ( & V_7 -> V_2 ) ;
if ( ! V_30 || ! V_7 )
return - V_50 ;
if ( ! F_45 ( V_5 -> V_2 . V_4 ) )
return - V_50 ;
if ( F_49 ( V_7 , V_51 , V_30 , sizeof( * V_30 ) , 0 ) )
return - V_39 ;
if ( memcmp ( V_30 -> V_52 , V_46 , V_53 ) != 0 )
return - V_50 ;
V_47 = F_50 ( V_30 -> V_47 ) ;
V_30 -> V_47 = 0 ;
if ( V_47 != F_51 ( (struct V_54 * ) V_30 ) )
return - V_50 ;
V_30 -> V_47 = F_52 ( V_47 ) ;
if ( memcmp ( V_30 -> V_49 , V_49 , 16 ) != 0 )
return - V_50 ;
if ( F_53 ( V_30 -> V_55 ) < 1 ) {
V_30 -> V_34 = 0 ;
V_30 -> V_40 = 0 ;
}
if ( F_53 ( V_30 -> V_55 ) < 2 )
V_30 -> V_25 = 0 ;
switch ( F_54 ( V_30 -> V_15 ) ) {
case V_16 :
case V_17 :
break;
default:
return - V_39 ;
}
V_25 = F_54 ( V_30 -> V_25 ) ;
V_31 = F_50 ( V_30 -> V_32 ) ;
if ( V_25 == 0 )
V_25 = 1UL << F_55 ( V_31 ) ;
V_15 = F_54 ( V_30 -> V_15 ) ;
if ( ! V_5 -> V_10 ) {
V_5 -> V_10 = F_56 ( V_30 -> V_10 , 16 , V_43 ) ;
if ( ! V_5 -> V_10 )
return - V_56 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_15 = V_15 ;
} else {
if ( memcmp ( V_5 -> V_10 , V_30 -> V_10 , 16 ) != 0 )
return - V_50 ;
if ( V_5 -> V_25 != V_25 || V_5 -> V_15 != V_15 ) {
F_57 ( & V_5 -> V_2 ,
L_17 ) ;
F_4 ( & V_5 -> V_2 , L_18 ,
V_5 -> V_25 , V_25 , V_5 -> V_15 ,
V_15 ) ;
return - V_24 ;
}
}
if ( V_25 > F_58 ( V_7 ) ) {
F_57 ( & V_5 -> V_2 , L_19 ,
V_25 , F_58 ( V_7 ) ) ;
return - V_24 ;
}
V_36 = F_33 ( & V_7 -> V_2 ) ;
if ( V_31 >= F_35 ( & V_36 -> V_37 ) ) {
F_57 ( & V_5 -> V_2 , L_20 ,
F_27 ( & V_7 -> V_2 ) ) ;
return - V_21 ;
}
if ( ( V_25 && ! F_59 ( V_31 , V_25 ) )
|| ! F_59 ( V_31 , V_27 ) ) {
F_57 ( & V_5 -> V_2 ,
L_21 ,
V_31 , V_25 ) ;
return - V_39 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 , struct V_33 * V_7 )
{
int V_19 ;
struct V_5 * V_5 ;
struct V_1 * V_57 ;
struct V_29 * V_30 ;
struct V_3 * V_3 = F_2 ( V_7 -> V_2 . V_4 ) ;
if ( V_7 -> V_58 )
return - V_50 ;
F_15 ( & V_7 -> V_2 ) ;
V_5 = F_40 ( V_3 ) ;
V_57 = F_36 ( V_5 , V_7 ) ;
F_16 ( & V_7 -> V_2 ) ;
if ( ! V_57 )
return - V_56 ;
V_30 = F_61 ( V_2 , sizeof( * V_30 ) , V_43 ) ;
V_5 = F_3 ( V_57 ) ;
V_5 -> V_30 = V_30 ;
V_19 = F_47 ( V_5 , V_59 ) ;
F_4 ( V_2 , L_22 , V_6 ,
V_19 == 0 ? F_27 ( V_57 ) : L_23 ) ;
if ( V_19 < 0 ) {
F_5 ( V_57 , & V_5 -> V_7 ) ;
F_39 ( V_57 ) ;
} else
F_46 ( V_57 ) ;
return V_19 ;
}
static unsigned long F_62 ( T_6 V_60 )
{
unsigned long V_61 = F_63 ( V_60 ) ;
return F_64 ( V_61 ) ;
}
static unsigned long F_65 ( T_6 V_60 )
{
unsigned long V_62 = F_63 ( V_63 ) ;
unsigned long V_61 = F_63 ( V_60 ) ;
V_62 += V_61 - F_64 ( V_61 ) ;
return V_62 ;
}
static struct V_64 * F_66 ( struct V_5 * V_5 ,
struct V_65 * V_37 , struct V_64 * V_66 )
{
struct V_29 * V_30 = V_5 -> V_30 ;
T_3 V_31 = F_50 ( V_30 -> V_32 ) ;
T_4 V_34 = F_32 ( V_30 -> V_34 ) ;
T_4 V_40 = F_32 ( V_30 -> V_40 ) ;
struct V_33 * V_7 = V_5 -> V_7 ;
struct V_35 * V_36 = F_33 ( & V_7 -> V_2 ) ;
T_6 V_60 = V_36 -> V_37 . V_38 + V_34 ;
struct V_64 V_67 = {
. V_61 = F_62 ( V_60 ) ,
. V_62 = F_65 ( V_60 ) ,
} ;
memcpy ( V_37 , & V_36 -> V_37 , sizeof( * V_37 ) ) ;
V_37 -> V_38 += V_34 ;
V_37 -> V_68 -= V_40 ;
if ( V_5 -> V_15 == V_16 ) {
if ( V_31 < V_63 )
return F_67 ( - V_24 ) ;
V_5 -> V_69 = F_50 ( V_30 -> V_69 ) ;
V_66 = NULL ;
} else if ( V_5 -> V_15 == V_17 ) {
V_5 -> V_69 = F_68 ( ( F_35 ( V_37 )
- V_31 ) / V_27 ) ;
if ( F_50 ( V_5 -> V_30 -> V_69 ) > V_5 -> V_69 )
F_69 ( & V_5 -> V_2 ,
L_24 ,
F_50 ( V_5 -> V_30 -> V_69 ) ,
V_5 -> V_69 ) ;
memcpy ( V_66 , & V_67 , sizeof( * V_66 ) ) ;
V_66 -> free = F_63 ( V_31 - V_63 ) ;
V_66 -> V_70 = 0 ;
} else
return F_67 ( - V_39 ) ;
return V_66 ;
}
static int F_70 ( struct V_5 * V_5 )
{
T_4 V_71 = F_71 ( & V_5 -> V_2 ) ? V_72 : 0 ;
struct V_33 * V_7 = V_5 -> V_7 ;
T_4 V_34 = 0 , V_40 = 0 ;
T_6 V_38 , V_73 ;
struct V_35 * V_36 ;
struct V_3 * V_3 ;
struct V_29 * V_30 ;
unsigned long V_69 ;
T_7 V_31 ;
const char * V_46 ;
T_3 V_47 ;
int V_19 ;
V_30 = F_61 ( & V_5 -> V_2 , sizeof( * V_30 ) , V_43 ) ;
if ( ! V_30 )
return - V_56 ;
V_5 -> V_30 = V_30 ;
if ( F_71 ( & V_5 -> V_2 ) )
V_46 = V_74 ;
else
V_46 = V_59 ;
V_19 = F_47 ( V_5 , V_46 ) ;
if ( V_19 != - V_50 )
return V_19 ;
;
V_3 = F_2 ( V_5 -> V_2 . V_4 ) ;
if ( V_3 -> V_75 ) {
F_69 ( & V_5 -> V_2 ,
L_25 ,
F_27 ( & V_3 -> V_2 ) ) ;
return - V_39 ;
}
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_36 = F_33 ( & V_7 -> V_2 ) ;
V_38 = F_72 ( V_36 -> V_37 . V_38 ) ;
V_73 = F_35 ( & V_36 -> V_37 ) ;
if ( F_73 ( V_38 , V_73 , V_76 ,
V_77 ) == V_78 ) {
V_38 = V_36 -> V_37 . V_38 ;
V_34 = F_74 ( V_38 ) - V_38 ;
}
V_38 = V_36 -> V_37 . V_38 ;
V_73 = F_74 ( V_38 + V_73 ) - V_38 ;
if ( F_73 ( V_38 , V_73 , V_76 ,
V_77 ) == V_78 ) {
V_73 = F_35 ( & V_36 -> V_37 ) ;
V_40 = V_38 + V_73 - F_72 ( V_38 + V_73 ) ;
}
if ( V_34 + V_40 )
F_69 ( & V_5 -> V_2 , L_26 ,
F_27 ( & V_7 -> V_2 ) , V_34 + V_40 ) ;
V_38 += V_34 ;
V_73 = F_35 ( & V_36 -> V_37 ) ;
V_69 = F_68 ( ( V_73 - V_34 - V_40 - V_63 )
/ V_27 ) ;
if ( V_5 -> V_15 == V_17 ) {
V_31 = F_75 ( V_38 + V_63 + 64 * V_69 + V_71 ,
F_76 ( V_5 -> V_25 , V_41 ) ) - V_38 ;
} else if ( V_5 -> V_15 == V_16 )
V_31 = F_75 ( V_38 + V_63 + V_71 ,
V_5 -> V_25 ) - V_38 ;
else
return - V_39 ;
if ( V_31 + V_34 + V_40 >= V_73 ) {
F_57 ( & V_5 -> V_2 , L_27 ,
F_27 ( & V_7 -> V_2 ) ) ;
return - V_39 ;
}
V_69 = ( V_73 - V_31 - V_34 - V_40 ) / V_51 ;
V_30 -> V_15 = F_77 ( V_5 -> V_15 ) ;
V_30 -> V_32 = F_52 ( V_31 ) ;
V_30 -> V_69 = F_52 ( V_69 ) ;
memcpy ( V_30 -> V_52 , V_46 , V_53 ) ;
memcpy ( V_30 -> V_10 , V_5 -> V_10 , 16 ) ;
memcpy ( V_30 -> V_49 , F_48 ( & V_7 -> V_2 ) , 16 ) ;
V_30 -> V_79 = F_78 ( 1 ) ;
V_30 -> V_55 = F_78 ( 2 ) ;
V_30 -> V_34 = F_77 ( V_34 ) ;
V_30 -> V_40 = F_77 ( V_40 ) ;
V_30 -> V_25 = F_77 ( V_5 -> V_25 ) ;
V_47 = F_51 ( (struct V_54 * ) V_30 ) ;
V_30 -> V_47 = F_52 ( V_47 ) ;
return F_79 ( V_7 , V_51 , V_30 , sizeof( * V_30 ) , 0 ) ;
}
struct V_64 * F_80 ( struct V_5 * V_5 ,
struct V_65 * V_37 , struct V_64 * V_66 )
{
int V_19 ;
if ( ! V_5 -> V_10 || ! V_5 -> V_7 )
return F_67 ( - V_50 ) ;
V_19 = F_70 ( V_5 ) ;
if ( V_19 )
return F_67 ( V_19 ) ;
return F_66 ( V_5 , V_37 , V_66 ) ;
}
