void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
void * V_5 ,
void (* F_2)( void * V_5 ,
T_1 V_6 , void * V_7 ,
T_2 V_8 , void * V_9 ,
T_2 * V_10 ) )
{
struct V_11 * V_12 = & V_2 -> V_12 [ V_4 ] ;
V_12 -> V_13 = F_2 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_14 = V_15 ;
}
void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_11 * V_12 = & V_2 -> V_12 [ V_4 ] ;
V_12 -> V_14 &= ~ V_15 ;
while ( V_12 -> V_14 & V_16 )
F_4 () ;
V_12 -> V_13 = NULL ;
}
static T_3 F_5 ( struct V_1 * V_2 ,
T_2 V_17 , enum V_3 V_4 ,
enum V_18 V_19 ,
enum V_20 V_21 ,
T_2 V_6 , T_2 V_22 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
return F_6 ( V_17 , V_25 ) |
F_6 ( V_4 , V_26 ) |
F_6 ( V_27 , V_28 ) |
F_6 ( V_19 , V_29 ) |
F_6 ( 0 , V_30 ) |
F_6 ( 0 , V_31 ) |
F_6 ( V_32 , V_33 ) |
F_6 ( V_21 , V_34 ) |
F_6 ( V_6 , V_35 ) |
F_6 ( F_7 ( V_24 ) , V_36 ) |
F_6 ( F_8 ( V_24 ) , V_37 ) |
F_6 ( V_22 , V_38 ) ;
}
static void F_9 ( T_1 * V_39 , T_3 * V_40 , T_1 * V_41 , T_2 V_17 )
{
memset ( V_39 , 0 , V_42 ) ;
V_39 += V_42 ;
memcpy ( V_39 , V_40 , sizeof( * V_40 ) ) ;
V_39 += sizeof( * V_40 ) ;
memcpy ( V_39 , V_41 , V_17 ) ;
}
static T_2 F_10 ( T_2 V_43 )
{
T_2 V_17 = V_42 + sizeof( T_3 ) + V_43 ;
if ( V_17 > V_44 )
V_17 = V_44 +
F_11 ( ( V_17 - V_44 ) ,
V_45 ) ;
else
V_17 = V_44 ;
return V_17 ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_6 ,
T_1 * V_46 , T_2 V_47 ,
enum V_18 V_19 ,
enum V_20 V_21 ,
T_2 V_48 )
{
struct V_49 * V_50 ;
T_3 V_40 ;
T_2 V_22 ;
V_22 = F_13 ( V_2 ) ;
if ( V_21 == V_51 ) {
V_40 = F_5 ( V_2 , V_47 , V_4 , V_19 ,
V_21 , V_6 , V_48 ) ;
} else {
F_14 ( V_2 ) ;
V_40 = F_5 ( V_2 , V_47 , V_4 , V_19 ,
V_21 , V_6 , V_22 ) ;
}
F_9 ( V_2 -> V_52 , & V_40 , V_46 , V_47 ) ;
V_50 = V_2 -> V_53 [ V_54 ] ;
return F_15 ( V_50 , V_55 ,
V_2 -> V_52 ,
F_10 ( V_47 ) ) ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_6 ,
T_1 * V_7 , T_2 V_8 ,
T_1 * V_9 , T_2 * V_10 ,
enum V_20 V_21 ,
T_2 V_48 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_56 * V_57 = V_24 -> V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_2 V_22 ;
int V_62 ;
F_17 ( & V_2 -> V_63 ) ;
V_59 = & V_2 -> V_64 ;
V_61 = & V_59 -> V_61 ;
if ( V_48 == V_65 )
V_22 = F_13 ( V_2 ) ;
else
V_22 = V_48 ;
F_18 ( V_61 ) ;
V_62 = F_12 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_66 , V_21 , V_48 ) ;
if ( V_62 ) {
F_19 ( & V_57 -> V_67 , L_1 ) ;
goto V_68;
}
if ( ! F_20 ( V_61 , V_69 ) ) {
F_19 ( & V_57 -> V_67 , L_2 , V_22 ) ;
V_62 = - V_70 ;
goto V_68;
}
F_21 () ;
if ( V_59 -> V_22 != V_22 ) {
F_19 ( & V_57 -> V_67 , L_3 , V_22 ) ;
V_62 = - V_71 ;
goto V_68;
}
if ( ( V_9 ) && ( V_59 -> V_17 <= V_72 ) ) {
memcpy ( V_9 , V_59 -> V_41 , V_59 -> V_17 ) ;
* V_10 = V_59 -> V_17 ;
}
V_68:
F_22 ( & V_2 -> V_63 ) ;
return V_62 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_6 ,
T_1 * V_7 , T_2 V_8 ,
enum V_20 V_21 ,
T_2 V_48 )
{
int V_62 ;
F_17 ( & V_2 -> V_63 ) ;
V_62 = F_12 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_73 , V_21 , V_48 ) ;
F_22 ( & V_2 -> V_63 ) ;
return V_62 ;
}
int F_24 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_6 ,
void * V_7 , T_2 V_8 , void * V_9 , T_2 * V_10 ,
enum V_74 V_75 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_56 * V_57 = V_24 -> V_57 ;
if ( V_75 != V_76 ) {
F_19 ( & V_57 -> V_67 , L_4 ) ;
return - V_77 ;
}
if ( ! F_25 ( V_8 ) ) {
F_19 ( & V_57 -> V_67 , L_5 ) ;
return - V_77 ;
}
return F_16 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_78 ,
V_65 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_56 * V_57 = V_24 -> V_57 ;
T_1 * V_9 = V_59 -> V_9 ;
struct V_11 * V_12 ;
unsigned long V_79 ;
T_2 V_10 = 0 ;
if ( V_59 -> V_4 >= V_80 ) {
F_19 ( & V_57 -> V_67 , L_6 ,
V_59 -> V_4 ) ;
return;
}
V_12 = & V_2 -> V_12 [ V_59 -> V_4 ] ;
V_79 = F_27 ( & V_12 -> V_14 ,
V_15 ,
V_15 | V_16 ) ;
if ( ( V_79 == V_15 ) && ( V_12 -> V_13 ) )
V_12 -> V_13 ( V_12 -> V_5 , V_59 -> V_6 ,
V_59 -> V_41 , V_59 -> V_17 ,
V_9 , & V_10 ) ;
else
F_19 ( & V_57 -> V_67 , L_7 ,
V_59 -> V_4 ) ;
V_12 -> V_14 &= ~ V_16 ;
if ( ! V_59 -> V_81 )
F_23 ( V_2 , V_59 -> V_4 , V_59 -> V_6 ,
V_9 , V_10 , V_51 ,
V_59 -> V_22 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
F_29 () ;
F_30 ( & V_59 -> V_61 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
T_3 * V_40 , struct V_58 * V_59 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_56 * V_57 = V_24 -> V_57 ;
int V_82 , V_83 ;
T_1 * V_84 ;
V_82 = F_32 ( * V_40 , V_31 ) ;
V_83 = F_32 ( * V_40 , V_28 ) ;
if ( V_82 >= ( V_85 / V_27 ) ) {
F_19 ( & V_57 -> V_67 , L_8 ) ;
return;
}
V_84 = ( T_1 * ) V_40 + sizeof( * V_40 ) ;
memcpy ( V_59 -> V_41 + V_82 * V_27 , V_84 , V_83 ) ;
if ( ! F_32 ( * V_40 , V_33 ) )
return;
V_59 -> V_6 = F_32 ( * V_40 , V_35 ) ;
V_59 -> V_4 = F_32 ( * V_40 , V_26 ) ;
V_59 -> V_81 = F_32 ( * V_40 ,
V_30 ) ;
V_59 -> V_17 = F_32 ( * V_40 , V_25 ) ;
V_59 -> V_22 = F_32 ( * V_40 , V_38 ) ;
if ( F_32 ( * V_40 , V_34 ) == V_51 )
F_28 ( V_2 , V_59 ) ;
else
F_26 ( V_2 , V_59 ) ;
}
static void F_33 ( void * V_5 , void * V_46 , T_1 V_86 )
{
struct V_1 * V_2 = V_5 ;
struct V_58 * V_59 ;
T_3 * V_40 = ( T_3 * ) V_46 ;
V_59 = F_32 ( * V_40 , V_34 ) ==
V_78 ?
& V_2 -> V_87 :
& V_2 -> V_64 ;
F_31 ( V_2 , V_40 , V_59 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_56 * V_57 = V_24 -> V_57 ;
V_59 -> V_41 = F_35 ( & V_57 -> V_67 , V_72 ,
V_88 ) ;
if ( ! V_59 -> V_41 )
return - V_89 ;
V_59 -> V_9 = F_35 ( & V_57 -> V_67 , V_72 ,
V_88 ) ;
if ( ! V_59 -> V_9 )
return - V_89 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_56 * V_57 = V_24 -> V_57 ;
int V_62 ;
V_62 = F_34 ( V_2 ,
& V_2 -> V_87 ) ;
if ( V_62 ) {
F_19 ( & V_57 -> V_67 , L_9 ) ;
return V_62 ;
}
V_62 = F_34 ( V_2 ,
& V_2 -> V_64 ) ;
if ( V_62 ) {
F_19 ( & V_57 -> V_67 , L_10 ) ;
return V_62 ;
}
V_2 -> V_52 = F_35 ( & V_57 -> V_67 ,
V_72 ,
V_88 ) ;
if ( ! V_2 -> V_52 )
return - V_89 ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_90 * V_91 = F_38 ( V_2 ) ;
struct V_92 * V_93 = & V_91 -> V_93 ;
struct V_56 * V_57 = V_24 -> V_57 ;
int V_62 ;
V_2 -> V_24 = V_24 ;
F_39 ( & V_2 -> V_63 , 1 ) ;
V_2 -> V_94 = 0 ;
V_62 = F_36 ( V_2 ) ;
if ( V_62 ) {
F_19 ( & V_57 -> V_67 , L_11 ) ;
return V_62 ;
}
V_62 = F_40 ( V_2 -> V_53 , V_24 ) ;
if ( V_62 ) {
F_19 ( & V_57 -> V_67 , L_12 ) ;
return V_62 ;
}
F_41 ( & V_93 -> V_95 , V_96 ,
V_2 ,
F_33 ) ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_38 ( V_2 ) ;
struct V_92 * V_93 = & V_91 -> V_93 ;
F_43 ( & V_93 -> V_95 , V_96 ) ;
F_44 ( V_2 -> V_53 ) ;
}
