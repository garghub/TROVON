static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 )
{
V_2 -> V_6 [ 0 ] = V_3 ;
memcpy ( V_2 -> V_6 + 1 , V_4 , V_5 ) ;
return F_2 ( V_2 -> V_7 , V_2 -> V_6 , V_5 + 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 )
{
T_1 V_8 = 0 ;
T_1 V_9 ;
V_9 = V_10 ;
V_8 = F_1 ( V_2 , V_3 , & V_9 , 1 ) ;
if ( V_8 == 2 )
V_8 = F_4 ( V_2 -> V_7 , V_4 , V_5 ) ;
return V_8 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_11 ;
F_6 ( V_2 , V_12 , & V_11 , 1 ) ;
F_7 ( V_2 , V_12 , & V_11 , 1 ) ;
return V_11 ;
}
static void F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_1 V_9 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_9 = V_15 ;
F_7 ( V_2 , V_16 , & V_9 , 1 ) ;
}
static T_1 F_10 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_1 V_9 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
F_6 ( V_2 , V_16 , & V_9 , 1 ) ;
return V_9 ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_1 V_9 ;
T_1 V_8 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_8 = F_6 ( V_2 , V_17 , & V_9 , 1 ) ;
if ( V_8 && ( V_9 &
( V_18 | V_19 ) ) ==
( V_18 | V_19 ) )
return V_14 -> V_20 . V_21 ;
return - V_22 ;
}
static int F_12 ( struct V_13 * V_14 )
{
unsigned long V_23 ;
long V_24 ;
struct V_1 * V_2 ;
T_1 V_9 ;
if ( F_11 ( V_14 ) == V_14 -> V_20 . V_21 )
return V_14 -> V_20 . V_21 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_9 = V_25 ;
V_24 = F_7 ( V_2 , V_17 , & V_9 , 1 ) ;
if ( V_24 < 0 )
goto V_26;
V_23 = V_27 + V_14 -> V_20 . V_28 ;
do {
if ( F_11 ( V_14 ) >= 0 )
return V_14 -> V_20 . V_21 ;
F_13 ( V_29 ) ;
} while ( F_14 ( V_27 , V_23 ) );
V_24 = - V_22 ;
V_26:
return V_24 ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_1 V_9 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_9 = V_18 ;
F_7 ( V_2 , V_17 , & V_9 , 1 ) ;
}
static int F_16 ( struct V_13 * V_14 )
{
unsigned long V_23 ;
int V_30 , V_8 ;
T_1 V_31 , V_32 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_23 = V_27 + V_14 -> V_20 . V_33 ;
do {
V_31 = V_16 + 1 ;
V_8 = F_6 ( V_2 , V_31 , & V_32 , 1 ) ;
if ( V_8 < 0 )
goto V_26;
V_31 = V_31 + 1 ;
V_30 = V_32 ;
V_8 = F_6 ( V_2 , V_31 , & V_32 , 1 ) ;
if ( V_8 < 0 )
goto V_26;
V_30 |= V_32 << 8 ;
if ( V_30 )
return V_30 ;
F_13 ( V_29 ) ;
} while ( F_14 ( V_27 , V_23 ) );
V_26:
return - V_34 ;
}
static bool F_17 ( struct V_13 * V_14 , T_1 V_35 ,
bool V_36 , bool * V_37 )
{
T_1 V_8 = V_14 -> V_38 -> V_8 ( V_14 ) ;
* V_37 = false ;
if ( ( V_8 & V_35 ) == V_35 )
return true ;
if ( V_36 && V_14 -> V_38 -> V_39 ( V_14 , V_8 ) ) {
* V_37 = true ;
return true ;
}
return false ;
}
static T_1 F_18 ( T_1 V_40 )
{
T_1 V_8 = 0 ;
if ( ( V_40 & V_41 ) == V_41 )
V_8 |= V_42 ;
if ( ( V_40 & V_43 ) == V_43 )
V_8 |= V_44 ;
if ( ( V_40 & V_45 ) == V_45 )
V_8 |= V_15 ;
return V_8 ;
}
static int F_19 ( struct V_13 * V_14 , T_1 V_35 , unsigned long V_46 ,
T_3 * V_47 , bool V_36 )
{
unsigned long V_23 ;
int V_24 ;
bool V_37 = false ;
bool V_48 ;
T_4 V_49 ;
T_1 V_11 , V_8 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_8 = F_10 ( V_14 ) ;
if ( ( V_8 & V_35 ) == V_35 )
return 0 ;
V_23 = V_27 + V_46 ;
if ( V_14 -> V_20 . V_50 ) {
V_49 = V_2 -> V_51 ;
V_11 = F_5 ( V_2 ) ;
F_20 ( V_14 -> V_20 . V_50 ) ;
V_52:
V_46 = V_23 - V_27 ;
if ( ( long ) V_46 <= 0 )
return - 1 ;
V_24 = F_21 ( * V_47 ,
V_49 != V_2 -> V_51 , V_46 ) ;
V_11 |= F_5 ( V_2 ) ;
V_8 = F_18 ( V_11 ) ;
V_48 = F_17 ( V_14 , V_35 ,
V_36 , & V_37 ) ;
if ( V_24 >= 0 && V_48 ) {
if ( V_37 )
return - V_53 ;
return 0 ;
}
if ( V_24 == - V_54 && F_22 ( V_55 ) ) {
F_23 ( V_56 ) ;
goto V_52;
}
F_24 ( V_14 -> V_20 . V_50 ) ;
} else {
do {
F_13 ( V_29 ) ;
V_8 = V_14 -> V_38 -> V_8 ( V_14 ) ;
if ( ( V_8 & V_35 ) == V_35 )
return 0 ;
} while ( F_14 ( V_27 , V_23 ) );
}
return - V_57 ;
}
static int F_25 ( struct V_13 * V_14 , T_1 * V_6 , T_5 V_58 )
{
int V_59 = 0 , V_30 , V_60 , V_24 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
while ( V_59 < V_58 &&
F_19 ( V_14 ,
V_44 | V_42 ,
V_14 -> V_20 . V_61 ,
& V_14 -> V_20 . V_62 , true ) == 0 ) {
V_30 = F_16 ( V_14 ) ;
if ( V_30 < 0 )
return V_30 ;
V_60 = F_26 ( int , V_30 , V_58 - V_59 ) ;
V_24 = F_6 ( V_2 , V_63 , V_6 + V_59 , V_60 ) ;
if ( V_24 < 0 )
return V_24 ;
V_59 += V_60 ;
}
return V_59 ;
}
static T_6 F_27 ( int V_50 , void * V_64 )
{
struct V_13 * V_14 = V_64 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_2 -> V_51 ++ ;
F_28 ( & V_14 -> V_20 . V_62 ) ;
F_24 ( V_14 -> V_20 . V_50 ) ;
return V_65 ;
}
static int F_29 ( struct V_13 * V_14 , unsigned char * V_6 ,
T_5 V_60 )
{
T_4 V_8 , V_66 , V_59 ;
int V_30 = 0 ;
int V_24 ;
T_1 V_9 ;
struct V_67 * V_7 ;
struct V_1 * V_2 ;
if ( ! V_14 )
return - V_34 ;
if ( V_60 < V_68 )
return - V_34 ;
V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
V_7 = V_2 -> V_7 ;
V_7 -> V_69 = 0 ;
V_24 = F_12 ( V_14 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = F_10 ( V_14 ) ;
if ( ( V_8 & V_15 ) == 0 ) {
F_8 ( V_14 ) ;
if ( F_19
( V_14 , V_15 , V_14 -> V_20 . V_70 ,
& V_14 -> V_20 . V_62 , false ) < 0 ) {
V_24 = - V_57 ;
goto V_71;
}
}
for ( V_66 = 0 ; V_66 < V_60 - 1 ; ) {
V_30 = F_16 ( V_14 ) ;
if ( V_30 < 0 )
return V_30 ;
V_59 = F_26 ( int , V_60 - V_66 - 1 , V_30 ) ;
V_24 = F_7 ( V_2 , V_63 , V_6 + V_66 , V_59 ) ;
if ( V_24 < 0 )
goto V_71;
V_66 += V_59 ;
}
V_8 = F_10 ( V_14 ) ;
if ( ( V_8 & V_72 ) == 0 ) {
V_24 = - V_73 ;
goto V_71;
}
V_24 = F_7 ( V_2 , V_63 , V_6 + V_60 - 1 , 1 ) ;
if ( V_24 < 0 )
goto V_71;
V_8 = F_10 ( V_14 ) ;
if ( ( V_8 & V_72 ) != 0 ) {
V_24 = - V_73 ;
goto V_71;
}
V_9 = V_74 ;
F_7 ( V_2 , V_16 , & V_9 , 1 ) ;
return V_60 ;
V_71:
F_8 ( V_14 ) ;
F_15 ( V_14 ) ;
return V_24 ;
}
static int F_30 ( struct V_13 * V_14 , unsigned char * V_6 ,
T_5 V_58 )
{
int V_59 = 0 ;
int V_75 ;
if ( ! V_14 )
return - V_34 ;
if ( V_58 < V_68 ) {
V_59 = - V_73 ;
goto V_76;
}
V_59 = F_25 ( V_14 , V_6 , V_68 ) ;
if ( V_59 < V_68 ) {
F_31 ( V_14 -> V_77 , L_1 ) ;
goto V_76;
}
V_75 = F_32 ( * ( V_78 * ) ( V_6 + 2 ) ) ;
if ( V_75 > V_58 ) {
V_59 = - V_73 ;
goto V_76;
}
V_59 += F_25 ( V_14 , & V_6 [ V_68 ] ,
V_75 - V_68 ) ;
if ( V_59 < V_75 ) {
F_31 ( V_14 -> V_77 , L_2 ) ;
V_59 = - V_57 ;
goto V_76;
}
V_76:
V_14 -> V_38 -> V_79 ( V_14 ) ;
F_15 ( V_14 ) ;
return V_59 ;
}
static bool F_33 ( struct V_13 * V_14 , T_1 V_8 )
{
return ( V_8 == V_15 ) ;
}
static int F_34 ( struct V_13 * V_14 )
{
struct V_80 * V_81 ;
struct V_1 * V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
struct V_67 * V_7 = V_2 -> V_7 ;
int V_82 ;
int V_24 ;
V_81 = V_7 -> V_83 . V_84 ;
if ( ! V_81 ) {
F_31 ( V_14 -> V_77 , L_3 ) ;
return - V_85 ;
}
V_82 = F_35 ( V_81 , L_4 , 0 ) ;
if ( V_82 < 0 ) {
F_31 ( V_14 -> V_77 , L_5 ) ;
V_2 -> V_86 = - 1 ;
return 0 ;
}
V_24 = F_36 ( & V_7 -> V_83 , V_82 ,
V_87 , L_6 ) ;
if ( V_24 ) {
F_31 ( V_14 -> V_77 , L_7 ) ;
return - V_85 ;
}
V_2 -> V_86 = V_82 ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 )
{
return - V_85 ;
}
static int F_37 ( struct V_67 * V_7 ,
struct V_13 * V_14 )
{
struct V_88 * V_89 ;
struct V_1 * V_2 = (struct V_1 * ) F_9 ( V_14 ) ;
int V_24 ;
V_89 = V_7 -> V_83 . V_90 ;
if ( ! V_89 ) {
F_31 ( V_14 -> V_77 , L_3 ) ;
return - V_85 ;
}
V_2 -> V_86 = V_89 -> V_86 ;
if ( F_38 ( V_89 -> V_86 ) ) {
V_24 = F_36 ( & V_7 -> V_83 ,
V_89 -> V_86 , V_87 ,
L_8 ) ;
if ( V_24 ) {
F_31 ( V_14 -> V_77 , L_9 ,
__FILE__ ) ;
return V_24 ;
}
}
return 0 ;
}
static int
F_39 ( struct V_67 * V_7 , const struct V_91 * V_92 )
{
int V_24 ;
T_1 V_93 = 0 ;
struct V_13 * V_14 ;
struct V_88 * V_90 ;
struct V_1 * V_2 ;
if ( ! V_7 ) {
F_40 ( L_10 ,
V_94 ) ;
return - V_85 ;
}
if ( ! F_41 ( V_7 -> V_95 , V_96 ) ) {
F_42 ( & V_7 -> V_83 , L_11 ) ;
return - V_85 ;
}
V_2 = F_43 ( & V_7 -> V_83 , sizeof( struct V_1 ) ,
V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_14 = F_44 ( & V_7 -> V_83 , & V_99 ) ;
if ( F_45 ( V_14 ) )
return F_46 ( V_14 ) ;
F_9 ( V_14 ) = V_2 ;
V_2 -> V_7 = V_7 ;
V_90 = V_7 -> V_83 . V_90 ;
if ( ! V_90 && V_7 -> V_83 . V_84 ) {
V_24 = F_34 ( V_14 ) ;
if ( V_24 )
goto V_100;
} else if ( V_90 ) {
V_24 = F_37 ( V_7 , V_14 ) ;
if ( V_24 )
goto V_100;
}
V_14 -> V_20 . V_28 = F_47 ( V_101 ) ;
V_14 -> V_20 . V_70 = F_47 ( V_102 ) ;
V_14 -> V_20 . V_61 = F_47 ( V_101 ) ;
V_14 -> V_20 . V_33 = F_47 ( V_101 ) ;
V_14 -> V_20 . V_21 = V_103 ;
if ( V_7 -> V_50 ) {
F_48 ( & V_14 -> V_20 . V_62 ) ;
V_2 -> V_51 = 0 ;
if ( F_12 ( V_14 ) != V_103 ) {
V_24 = - V_85 ;
goto V_100;
}
F_5 ( V_2 ) ;
V_24 = F_49 ( & V_7 -> V_83 , V_7 -> V_50 ,
F_27 ,
V_104 ,
L_12 , V_14 ) ;
if ( V_24 < 0 ) {
F_31 ( V_14 -> V_77 , L_13 ,
V_7 -> V_50 ) ;
goto V_100;
}
V_93 |= V_45
| V_41
| V_43 ;
V_24 = F_7 ( V_2 , V_105 , & V_93 , 1 ) ;
if ( V_24 < 0 )
goto V_100;
V_93 = V_106 ;
V_24 = F_7 ( V_2 , ( V_105 + 3 ) ,
& V_93 , 1 ) ;
if ( V_24 < 0 )
goto V_100;
V_14 -> V_20 . V_50 = V_7 -> V_50 ;
F_24 ( V_14 -> V_20 . V_50 ) ;
F_50 ( V_14 ) ;
}
F_51 ( V_14 ) ;
F_52 ( V_14 ) ;
return F_53 ( V_14 ) ;
V_100:
F_42 ( V_14 -> V_77 , L_14 ) ;
return V_24 ;
}
static int F_54 ( struct V_67 * V_7 )
{
struct V_13 * V_14 =
(struct V_13 * ) F_55 ( V_7 ) ;
if ( V_14 )
F_56 ( V_14 ) ;
return 0 ;
}
static int F_57 ( struct V_107 * V_83 )
{
struct V_88 * V_108 = V_83 -> V_90 ;
int V_24 = 0 ;
if ( F_38 ( V_108 -> V_86 ) )
F_58 ( V_108 -> V_86 , 0 ) ;
else
V_24 = F_59 ( V_83 ) ;
return V_24 ;
}
static int F_60 ( struct V_107 * V_83 )
{
struct V_13 * V_14 = F_61 ( V_83 ) ;
struct V_88 * V_108 = V_83 -> V_90 ;
int V_24 = 0 ;
if ( F_38 ( V_108 -> V_86 ) ) {
F_58 ( V_108 -> V_86 , 1 ) ;
V_24 = F_19 ( V_14 ,
V_42 , V_14 -> V_20 . V_70 ,
& V_14 -> V_20 . V_62 , false ) ;
} else {
V_24 = F_62 ( V_83 ) ;
if ( ! V_24 )
F_52 ( V_14 ) ;
}
return V_24 ;
}
