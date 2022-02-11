unsigned int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( ( unsigned int ) ( V_4 - V_2 -> V_5 ) ) ;
}
T_1 F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( T_1 ) F_1 ( V_2 , V_4 ) << V_2 -> V_6 -> V_7 ;
}
T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( T_1 ) F_1 ( V_2 , V_4 ) << V_2 -> V_6 -> V_8 ;
}
unsigned int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_9 ;
}
unsigned int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_10 ;
}
unsigned int F_6 ( struct V_1 * V_2 )
{
return F_7 ( & V_2 -> V_11 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_12 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_12 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_13 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_13 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_14 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_14 ) ;
}
static struct V_15 * F_18 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_15 * V_17 = NULL ;
if ( V_2 -> V_18 && F_7 ( & V_2 -> V_19 ) > V_2 -> V_18 ) {
F_19 ( & V_2 -> V_20 ) ;
V_17 = F_20 ( & V_2 -> V_21 ,
struct V_15 , V_22 ) ;
if ( V_17 ) {
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
V_17 -> V_25 = V_16 ;
}
F_23 ( & V_2 -> V_20 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_24 ( sizeof( struct V_15 ) , V_26 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_27 = F_25 ( V_26 ) ;
if ( ! V_17 -> V_27 ) {
F_26 ( V_17 ) ;
return NULL ;
}
F_27 ( & V_17 -> V_23 ) ;
F_28 ( & V_17 -> V_22 ) ;
F_29 ( & V_17 -> V_28 , 0 ) ;
V_17 -> V_29 = 0 ;
V_17 -> V_25 = V_16 ;
V_17 -> V_30 = F_30 ( V_17 -> V_27 ) ;
F_31 ( & V_2 -> V_19 ) ;
return V_17 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_15 * V_17 )
{
F_33 ( V_17 -> V_27 , 0 ) ;
F_26 ( V_17 ) ;
F_34 ( & V_2 -> V_19 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_15 * V_17 )
{
struct V_31 * V_32 = & V_2 -> V_24 ;
struct V_33 * * V_34 = & ( V_32 -> V_33 ) , * V_35 = NULL ;
struct V_15 * V_36 ;
while ( * V_34 ) {
V_36 = F_36 ( * V_34 , struct V_15 , V_23 ) ;
V_35 = * V_34 ;
V_34 = ( V_36 -> V_25 < V_17 -> V_25 ) ? & ( ( * V_34 ) -> V_37 ) : & ( ( * V_34 ) -> V_38 ) ;
}
F_37 ( & V_17 -> V_23 , V_35 , V_34 ) ;
F_38 ( & V_17 -> V_23 , V_32 ) ;
}
static struct V_15 * F_39 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_31 * V_32 = & V_2 -> V_24 ;
struct V_33 * V_23 = V_32 -> V_33 ;
struct V_15 * V_17 ;
while ( V_23 ) {
V_17 = F_36 ( V_23 , struct V_15 , V_23 ) ;
if ( V_17 -> V_25 == V_16 )
return V_17 ;
V_23 = ( V_17 -> V_25 < V_16 ) ? V_23 -> V_37 : V_23 -> V_38 ;
}
return NULL ;
}
static void F_40 ( struct V_39 * V_39 )
{
struct V_15 * V_17 = V_39 -> V_40 ;
int V_41 ;
if ( V_39 -> V_42 )
F_41 ( V_43 , & V_17 -> V_29 ) ;
if ( F_42 ( V_39 ) == V_44 )
V_41 = V_45 ;
else
V_41 = V_46 ;
F_43 ( V_41 , & V_17 -> V_29 ) ;
F_44 () ;
F_45 ( & V_17 -> V_29 , V_41 ) ;
F_46 ( V_39 ) ;
}
static struct V_15 * F_47 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_15 * V_17 ;
T_1 V_47 = V_2 -> V_48 [ V_2 -> V_49 ] . V_47 + V_16 ;
struct V_39 * V_39 ;
V_17 = F_18 ( V_2 , V_16 ) ;
if ( ! V_17 )
return NULL ;
F_19 ( & V_2 -> V_20 ) ;
F_31 ( & V_17 -> V_28 ) ;
F_41 ( V_46 , & V_17 -> V_29 ) ;
F_35 ( V_2 , V_17 ) ;
F_23 ( & V_2 -> V_20 ) ;
V_39 = F_48 ( V_26 , 1 ) ;
if ( ! V_39 ) {
F_32 ( V_2 , V_17 ) ;
return NULL ;
}
V_39 -> V_50 . V_51 = F_49 ( V_47 ) ;
V_39 -> V_52 = V_2 -> V_6 -> V_53 ;
V_39 -> V_40 = V_17 ;
V_39 -> V_54 = F_40 ;
F_50 ( V_39 , V_55 , V_56 | V_57 ) ;
F_51 ( V_39 , V_17 -> V_27 , V_58 , 0 ) ;
F_52 ( V_39 ) ;
return V_17 ;
}
static unsigned long F_53 ( struct V_1 * V_2 ,
unsigned long V_59 )
{
struct V_15 * V_17 ;
unsigned long V_60 = 0 ;
if ( ! V_2 -> V_18 )
return 0 ;
while ( ! F_54 ( & V_2 -> V_21 ) &&
F_7 ( & V_2 -> V_19 ) > V_2 -> V_61 &&
V_60 < V_59 ) {
V_17 = F_55 ( & V_2 -> V_21 ,
struct V_15 , V_22 ) ;
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
V_60 ++ ;
}
return V_60 ;
}
static unsigned long F_56 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_36 ( V_63 , struct V_1 , V_66 ) ;
return F_7 ( & V_2 -> V_19 ) ;
}
static unsigned long F_57 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_36 ( V_63 , struct V_1 , V_66 ) ;
unsigned long V_60 ;
F_19 ( & V_2 -> V_20 ) ;
V_60 = F_53 ( V_2 , V_65 -> V_67 ) ;
F_23 ( & V_2 -> V_20 ) ;
return V_60 ? V_60 : V_68 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_15 * V_17 )
{
if ( ! V_17 )
return;
F_19 ( & V_2 -> V_20 ) ;
if ( F_59 ( & V_17 -> V_28 ) ) {
if ( F_60 ( V_43 , & V_17 -> V_29 ) ) {
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
} else if ( ! F_60 ( V_69 , & V_17 -> V_29 ) ) {
F_61 ( & V_17 -> V_22 , & V_2 -> V_21 ) ;
F_53 ( V_2 , 1 ) ;
}
}
F_23 ( & V_2 -> V_20 ) ;
}
static struct V_15 * F_62 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_15 * V_17 ;
F_19 ( & V_2 -> V_20 ) ;
V_17 = F_39 ( V_2 , V_16 ) ;
if ( V_17 ) {
if ( F_63 ( & V_17 -> V_28 ) == 1 &&
! F_60 ( V_69 , & V_17 -> V_29 ) )
F_21 ( & V_17 -> V_22 ) ;
}
F_23 ( & V_2 -> V_20 ) ;
if ( ! V_17 ) {
V_17 = F_47 ( V_2 , V_16 ) ;
if ( ! V_17 )
return F_64 ( - V_70 ) ;
}
F_65 ( & V_17 -> V_29 , V_46 ,
V_71 ) ;
if ( F_60 ( V_43 , & V_17 -> V_29 ) ) {
F_58 ( V_2 , V_17 ) ;
return F_64 ( - V_72 ) ;
}
return V_17 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_15 * V_17 )
{
F_19 ( & V_2 -> V_20 ) ;
if ( ! F_67 ( V_69 , & V_17 -> V_29 ) )
F_61 ( & V_17 -> V_22 , & V_2 -> V_73 ) ;
F_23 ( & V_2 -> V_20 ) ;
}
static void F_68 ( struct V_1 * V_2 , struct V_15 * V_17 ,
unsigned int V_74 )
{
T_1 V_47 = V_2 -> V_48 [ V_74 ] . V_47 + V_17 -> V_25 ;
struct V_39 * V_39 ;
V_39 = F_48 ( V_26 , 1 ) ;
if ( ! V_39 ) {
F_41 ( V_43 , & V_17 -> V_29 ) ;
return;
}
F_41 ( V_45 , & V_17 -> V_29 ) ;
V_39 -> V_50 . V_51 = F_49 ( V_47 ) ;
V_39 -> V_52 = V_2 -> V_6 -> V_53 ;
V_39 -> V_40 = V_17 ;
V_39 -> V_54 = F_40 ;
F_50 ( V_39 , V_44 , V_56 | V_57 ) ;
F_51 ( V_39 , V_17 -> V_27 , V_58 , 0 ) ;
F_52 ( V_39 ) ;
}
static int F_69 ( struct V_1 * V_2 , int V_75 , T_1 V_47 ,
struct V_27 * V_27 )
{
struct V_39 * V_39 ;
int V_76 ;
V_39 = F_48 ( V_26 , 1 ) ;
if ( ! V_39 )
return - V_70 ;
V_39 -> V_50 . V_51 = F_49 ( V_47 ) ;
V_39 -> V_52 = V_2 -> V_6 -> V_53 ;
F_50 ( V_39 , V_75 , V_77 | V_56 | V_57 ) ;
F_51 ( V_39 , V_27 , V_58 , 0 ) ;
V_76 = F_70 ( V_39 ) ;
F_46 ( V_39 ) ;
return V_76 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_74 )
{
T_1 V_47 = V_2 -> V_48 [ V_74 ] . V_47 ;
struct V_15 * V_17 = V_2 -> V_48 [ V_74 ] . V_17 ;
struct V_78 * V_48 = V_2 -> V_48 [ V_74 ] . V_48 ;
T_2 V_79 = V_2 -> V_79 + 1 ;
int V_76 ;
V_48 -> V_80 = F_72 ( V_81 ) ;
V_48 -> V_82 = F_72 ( V_83 ) ;
V_48 -> V_84 = F_73 ( V_79 ) ;
V_48 -> V_85 = F_73 ( V_47 ) ;
V_48 -> V_86 = F_72 ( V_2 -> V_86 ) ;
V_48 -> V_87 = F_72 ( V_2 -> V_87 ) ;
V_48 -> V_9 = F_72 ( V_2 -> V_9 ) ;
V_48 -> V_88 = F_72 ( V_2 -> V_88 ) ;
V_48 -> V_89 = F_72 ( V_2 -> V_89 ) ;
V_48 -> V_90 = 0 ;
V_48 -> V_90 = F_72 ( F_74 ( V_79 , ( unsigned char * ) V_48 , V_58 ) ) ;
V_76 = F_69 ( V_2 , V_44 , V_47 , V_17 -> V_27 ) ;
if ( V_76 == 0 )
V_76 = F_75 ( V_2 -> V_6 -> V_53 , V_26 , NULL ) ;
return V_76 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
unsigned int V_74 )
{
struct V_15 * V_17 ;
struct V_93 V_94 ;
int V_76 = 0 ;
F_77 ( & V_94 ) ;
F_78 (mblk, write_list, link)
F_68 ( V_2 , V_17 , V_74 ) ;
F_79 ( & V_94 ) ;
F_78 (mblk, write_list, link) {
F_65 ( & V_17 -> V_29 , V_45 ,
V_71 ) ;
if ( F_60 ( V_43 , & V_17 -> V_29 ) ) {
F_80 ( V_43 , & V_17 -> V_29 ) ;
V_76 = - V_72 ;
}
}
if ( V_76 == 0 )
V_76 = F_75 ( V_2 -> V_6 -> V_53 , V_26 , NULL ) ;
return V_76 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
unsigned int V_95 = V_2 -> V_49 ^ 0x1 ;
int V_76 ;
V_76 = F_76 ( V_2 , V_92 , V_95 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_71 ( V_2 , V_95 ) ;
if ( V_76 )
return V_76 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_17 ;
struct V_91 V_92 ;
int V_76 ;
if ( F_83 ( ! V_2 ) )
return 0 ;
F_28 ( & V_92 ) ;
F_84 ( & V_2 -> V_13 ) ;
F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_20 ) ;
F_85 ( & V_2 -> V_73 , & V_92 ) ;
F_23 ( & V_2 -> V_20 ) ;
if ( F_54 ( & V_92 ) ) {
V_76 = F_75 ( V_2 -> V_6 -> V_53 , V_26 , NULL ) ;
goto V_96;
}
V_76 = F_81 ( V_2 , & V_92 ) ;
if ( V_76 )
goto V_96;
V_76 = F_76 ( V_2 , & V_92 , V_2 -> V_49 ) ;
if ( V_76 )
goto V_96;
V_76 = F_71 ( V_2 , V_2 -> V_49 ) ;
if ( V_76 )
goto V_96;
while ( ! F_54 ( & V_92 ) ) {
V_17 = F_55 ( & V_92 , struct V_15 , V_22 ) ;
F_21 ( & V_17 -> V_22 ) ;
F_19 ( & V_2 -> V_20 ) ;
F_80 ( V_69 , & V_17 -> V_29 ) ;
if ( F_7 ( & V_17 -> V_28 ) == 0 )
F_61 ( & V_17 -> V_22 , & V_2 -> V_21 ) ;
F_23 ( & V_2 -> V_20 ) ;
}
V_2 -> V_79 ++ ;
V_96:
if ( V_76 && ! F_54 ( & V_92 ) ) {
F_19 ( & V_2 -> V_20 ) ;
F_86 ( & V_92 , & V_2 -> V_73 ) ;
F_23 ( & V_2 -> V_20 ) ;
}
F_17 ( V_2 ) ;
F_87 ( & V_2 -> V_13 ) ;
return V_76 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_78 * V_48 )
{
unsigned int V_97 , V_98 ;
struct V_99 * V_6 = V_2 -> V_6 ;
T_3 V_90 , V_100 ;
T_2 V_84 ;
V_84 = F_89 ( V_48 -> V_84 ) ;
V_100 = F_90 ( V_48 -> V_90 ) ;
V_48 -> V_90 = 0 ;
V_90 = F_74 ( V_84 , ( unsigned char * ) V_48 , V_58 ) ;
if ( V_90 != V_100 ) {
F_91 ( V_6 , L_1 ,
V_90 , V_100 ) ;
return - V_101 ;
}
if ( F_90 ( V_48 -> V_80 ) != V_81 ) {
F_91 ( V_6 , L_2 ,
V_81 , F_90 ( V_48 -> V_80 ) ) ;
return - V_101 ;
}
if ( F_90 ( V_48 -> V_82 ) != V_83 ) {
F_91 ( V_6 , L_3 ,
V_83 , F_90 ( V_48 -> V_82 ) ) ;
return - V_101 ;
}
V_97 = ( F_90 ( V_48 -> V_86 ) + V_6 -> V_102 - 1 )
>> V_6 -> V_8 ;
if ( ! V_97 ||
V_97 >= V_2 -> V_103 ) {
F_91 ( V_6 , L_4 ) ;
return - V_101 ;
}
if ( ! F_90 ( V_48 -> V_87 ) ||
F_90 ( V_48 -> V_87 ) >= ( V_2 -> V_104 - V_97 ) ) {
F_91 ( V_6 , L_5 ) ;
return - V_101 ;
}
V_98 = V_2 -> V_104 -
( V_97 * 2 + F_90 ( V_48 -> V_87 ) ) ;
if ( F_90 ( V_48 -> V_9 ) > V_98 ) {
F_91 ( V_6 , L_6 ,
F_90 ( V_48 -> V_9 ) , V_98 ) ;
return - V_101 ;
}
V_2 -> V_86 = F_90 ( V_48 -> V_86 ) ;
V_2 -> V_87 = F_90 ( V_48 -> V_87 ) ;
V_2 -> V_9 = F_90 ( V_48 -> V_9 ) ;
V_2 -> V_88 = F_90 ( V_48 -> V_88 ) ;
V_2 -> V_89 = F_90 ( V_48 -> V_89 ) ;
V_2 -> V_97 = V_97 ;
V_2 -> V_98 = V_98 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , unsigned int V_74 )
{
return F_69 ( V_2 , V_55 , V_2 -> V_48 [ V_74 ] . V_47 ,
V_2 -> V_48 [ V_74 ] . V_17 -> V_27 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
unsigned int V_102 = V_2 -> V_6 -> V_102 ;
struct V_15 * V_17 ;
int V_105 ;
V_17 = F_18 ( V_2 , 0 ) ;
if ( ! V_17 )
return - V_70 ;
V_2 -> V_48 [ 1 ] . V_17 = V_17 ;
V_2 -> V_48 [ 1 ] . V_48 = V_17 -> V_30 ;
V_2 -> V_48 [ 1 ] . V_47 = V_2 -> V_48 [ 0 ] . V_47 + V_102 ;
for ( V_105 = 0 ; V_105 < V_2 -> V_103 - 1 ; V_105 ++ ) {
if ( F_92 ( V_2 , 1 ) != 0 )
break;
if ( F_90 ( V_2 -> V_48 [ 1 ] . V_48 -> V_80 ) == V_81 )
return 0 ;
V_2 -> V_48 [ 1 ] . V_47 += V_102 ;
}
F_32 ( V_2 , V_17 ) ;
V_2 -> V_48 [ 1 ] . V_17 = NULL ;
return - V_72 ;
}
static int F_94 ( struct V_1 * V_2 , unsigned int V_74 )
{
struct V_15 * V_17 ;
int V_76 ;
V_17 = F_18 ( V_2 , 0 ) ;
if ( ! V_17 )
return - V_70 ;
V_2 -> V_48 [ V_74 ] . V_17 = V_17 ;
V_2 -> V_48 [ V_74 ] . V_48 = V_17 -> V_30 ;
V_76 = F_92 ( V_2 , V_74 ) ;
if ( V_76 ) {
F_32 ( V_2 , V_17 ) ;
V_2 -> V_48 [ V_74 ] . V_17 = NULL ;
return V_76 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , unsigned int V_106 )
{
unsigned int V_107 = V_106 ^ 0x1 ;
struct V_27 * V_27 ;
int V_105 , V_76 ;
F_96 ( V_2 -> V_6 , L_7 , V_106 ) ;
if ( V_106 == 0 )
V_2 -> V_48 [ 0 ] . V_47 = F_3 ( V_2 , V_2 -> V_108 ) ;
else {
V_2 -> V_48 [ 1 ] . V_47 = V_2 -> V_48 [ 0 ] . V_47 +
( V_2 -> V_97 << V_2 -> V_6 -> V_8 ) ;
}
V_27 = F_25 ( V_26 ) ;
if ( ! V_27 )
return - V_70 ;
for ( V_105 = 1 ; V_105 < V_2 -> V_86 ; V_105 ++ ) {
V_76 = F_69 ( V_2 , V_55 ,
V_2 -> V_48 [ V_107 ] . V_47 + V_105 , V_27 ) ;
if ( V_76 )
goto V_96;
V_76 = F_69 ( V_2 , V_44 ,
V_2 -> V_48 [ V_106 ] . V_47 + V_105 , V_27 ) ;
if ( V_76 )
goto V_96;
}
if ( ! V_2 -> V_48 [ V_106 ] . V_17 ) {
V_2 -> V_48 [ V_106 ] . V_17 = F_18 ( V_2 , 0 ) ;
if ( ! V_2 -> V_48 [ V_106 ] . V_17 ) {
V_76 = - V_70 ;
goto V_96;
}
V_2 -> V_48 [ V_106 ] . V_48 = V_2 -> V_48 [ V_106 ] . V_17 -> V_30 ;
}
V_76 = F_71 ( V_2 , V_106 ) ;
V_96:
F_33 ( V_27 , 0 ) ;
return V_76 ;
}
static int F_97 ( struct V_1 * V_2 )
{
bool V_109 [ 2 ] = { false , false } ;
T_2 V_79 [ 2 ] = { 0 , 0 } ;
int V_76 ;
V_2 -> V_48 [ 0 ] . V_47 = F_3 ( V_2 , V_2 -> V_108 ) ;
V_76 = F_94 ( V_2 , 0 ) ;
if ( V_76 ) {
F_91 ( V_2 -> V_6 , L_8 ) ;
return V_76 ;
}
V_76 = F_88 ( V_2 , V_2 -> V_48 [ 0 ] . V_48 ) ;
if ( V_76 == 0 ) {
V_109 [ 0 ] = true ;
V_2 -> V_48 [ 1 ] . V_47 = V_2 -> V_48 [ 0 ] . V_47 +
( V_2 -> V_97 << V_2 -> V_6 -> V_8 ) ;
V_76 = F_94 ( V_2 , 1 ) ;
} else
V_76 = F_93 ( V_2 ) ;
if ( V_76 ) {
F_91 ( V_2 -> V_6 , L_9 ) ;
return V_76 ;
}
V_76 = F_88 ( V_2 , V_2 -> V_48 [ 1 ] . V_48 ) ;
if ( V_76 == 0 )
V_109 [ 1 ] = true ;
if ( ! V_109 [ 0 ] && ! V_109 [ 1 ] ) {
F_91 ( V_2 -> V_6 , L_10 ) ;
return - V_72 ;
}
if ( V_109 [ 0 ] )
V_79 [ 0 ] = F_89 ( V_2 -> V_48 [ 0 ] . V_48 -> V_84 ) ;
else
V_76 = F_95 ( V_2 , 0 ) ;
if ( V_109 [ 1 ] )
V_79 [ 1 ] = F_89 ( V_2 -> V_48 [ 1 ] . V_48 -> V_84 ) ;
else
V_76 = F_95 ( V_2 , 1 ) ;
if ( V_76 ) {
F_91 ( V_2 -> V_6 , L_11 ) ;
return - V_72 ;
}
if ( V_79 [ 0 ] >= V_79 [ 1 ] ) {
V_2 -> V_79 = V_79 [ 0 ] ;
V_2 -> V_49 = 0 ;
} else {
V_2 -> V_79 = V_79 [ 1 ] ;
V_2 -> V_49 = 1 ;
}
F_98 ( V_2 -> V_6 , L_12 ,
V_2 -> V_49 , V_2 -> V_79 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_110 * V_111 )
{
struct V_99 * V_6 = V_2 -> V_6 ;
if ( V_111 -> V_112 != V_6 -> V_113 ) {
if ( V_111 -> V_114 + V_111 -> V_112 == V_6 -> V_115 )
return 0 ;
return - V_101 ;
}
F_28 ( & V_4 -> V_22 ) ;
F_29 ( & V_4 -> V_116 , 0 ) ;
V_4 -> V_117 = V_118 ;
if ( V_111 -> type == V_119 ) {
F_41 ( V_120 , & V_4 -> V_121 ) ;
V_2 -> V_103 ++ ;
} else if ( V_111 -> type == V_122 ||
V_111 -> type == V_123 ) {
F_41 ( V_124 , & V_4 -> V_121 ) ;
} else
return - V_101 ;
if ( V_111 -> V_125 == V_126 )
F_41 ( V_127 , & V_4 -> V_121 ) ;
else if ( V_111 -> V_125 == V_128 )
F_41 ( V_129 , & V_4 -> V_121 ) ;
if ( F_100 ( V_4 ) )
V_4 -> V_130 = 0 ;
else
V_4 -> V_130 = F_101 ( V_111 -> V_131 - V_111 -> V_114 ) ;
if ( ! F_102 ( V_4 ) && ! F_103 ( V_4 ) ) {
V_2 -> V_104 ++ ;
if ( F_100 ( V_4 ) ) {
V_2 -> V_103 ++ ;
if ( ! V_2 -> V_108 ) {
V_2 -> V_108 = V_4 ;
}
}
}
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_99 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
struct V_110 * V_111 ;
unsigned int V_132 ;
T_1 V_133 = 0 ;
int V_105 , V_76 = 0 ;
V_2 -> V_134 = V_6 -> V_102 >> 3 ;
V_2 -> V_135 = V_2 -> V_134 >> V_136 ;
V_2 -> V_5 = F_106 ( V_6 -> V_137 , sizeof( struct V_3 ) , V_138 ) ;
if ( ! V_2 -> V_5 )
return - V_70 ;
F_107 ( V_6 , L_13 ,
sizeof( struct V_3 ) * V_6 -> V_137 ) ;
V_132 = V_139 ;
V_111 = F_106 ( V_132 , sizeof( struct V_110 ) , V_138 ) ;
if ( ! V_111 ) {
V_76 = - V_70 ;
goto V_96;
}
V_4 = V_2 -> V_5 ;
while ( V_133 < V_6 -> V_115 ) {
V_132 = V_139 ;
V_76 = F_108 ( V_6 -> V_53 , V_133 , V_111 ,
& V_132 , V_138 ) ;
if ( V_76 ) {
F_91 ( V_6 , L_14 , V_76 ) ;
goto V_96;
}
for ( V_105 = 0 ; V_105 < V_132 ; V_105 ++ ) {
V_76 = F_99 ( V_2 , V_4 , & V_111 [ V_105 ] ) ;
if ( V_76 )
goto V_96;
V_133 += V_6 -> V_113 ;
V_4 ++ ;
}
}
if ( V_133 < V_6 -> V_115 ) {
F_91 ( V_6 , L_15 ) ;
V_76 = - V_101 ;
}
V_96:
F_26 ( V_111 ) ;
if ( V_76 )
F_104 ( V_2 ) ;
return V_76 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_132 = 1 ;
struct V_110 V_111 ;
int V_76 ;
V_76 = F_108 ( V_2 -> V_6 -> V_53 , F_2 ( V_2 , V_4 ) ,
& V_111 , & V_132 , V_26 ) ;
if ( V_76 ) {
F_91 ( V_2 -> V_6 , L_16 ,
F_1 ( V_2 , V_4 ) ) ;
return V_76 ;
}
F_80 ( V_127 , & V_4 -> V_121 ) ;
F_80 ( V_129 , & V_4 -> V_121 ) ;
if ( V_111 . V_125 == V_126 )
F_41 ( V_127 , & V_4 -> V_121 ) ;
else if ( V_111 . V_125 == V_128 )
F_41 ( V_129 , & V_4 -> V_121 ) ;
if ( F_110 ( V_4 ) )
V_4 -> V_130 = F_101 ( V_111 . V_131 - V_111 . V_114 ) ;
else
V_4 -> V_130 = 0 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_131 = 0 ;
int V_76 ;
V_131 = V_4 -> V_130 ;
V_76 = F_109 ( V_2 , V_4 ) ;
if ( V_76 )
return V_76 ;
F_96 ( V_2 -> V_6 , L_17 ,
F_1 ( V_2 , V_4 ) , V_4 -> V_130 , V_131 ) ;
if ( V_4 -> V_130 < V_131 ) {
F_112 ( V_2 , V_4 , V_4 -> V_130 ,
V_131 - V_4 -> V_130 ) ;
}
return 0 ;
}
static struct V_3 * F_113 ( struct V_1 * V_2 , unsigned int V_140 )
{
return & V_2 -> V_5 [ V_140 ] ;
}
static int F_114 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_76 ;
if ( F_102 ( V_4 ) ||
F_103 ( V_4 ) ||
F_100 ( V_4 ) )
return 0 ;
if ( ! F_115 ( V_4 ) || F_116 ( V_4 ) ) {
struct V_99 * V_6 = V_2 -> V_6 ;
V_76 = F_117 ( V_6 -> V_53 ,
F_2 ( V_2 , V_4 ) ,
V_6 -> V_113 , V_26 ) ;
if ( V_76 ) {
F_91 ( V_6 , L_18 ,
F_1 ( V_2 , V_4 ) , V_76 ) ;
return V_76 ;
}
}
F_80 ( V_141 , & V_4 -> V_121 ) ;
V_4 -> V_130 = 0 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_99 * V_6 = V_2 -> V_6 ;
struct V_3 * V_142 , * V_143 ;
struct V_15 * V_144 = NULL ;
struct V_145 * V_146 ;
unsigned int V_105 = 0 , V_147 = 0 , V_117 = 0 ;
unsigned int V_148 ;
unsigned int V_149 ;
V_2 -> V_150 = F_106 ( V_2 -> V_88 ,
sizeof( struct V_151 * ) , V_138 ) ;
if ( ! V_2 -> V_150 )
return - V_70 ;
while ( V_117 < V_2 -> V_9 ) {
if ( ! V_144 ) {
V_144 = F_62 ( V_2 , V_105 + 1 ) ;
if ( F_119 ( V_144 ) )
return F_120 ( V_144 ) ;
V_2 -> V_150 [ V_105 ] = V_144 ;
V_146 = (struct V_145 * ) V_144 -> V_30 ;
V_105 ++ ;
V_147 = 0 ;
}
V_148 = F_90 ( V_146 [ V_147 ] . V_148 ) ;
if ( V_148 == V_118 )
goto V_152;
if ( V_148 >= V_6 -> V_137 ) {
F_91 ( V_6 , L_19 ,
V_117 , V_148 ) ;
return - V_72 ;
}
V_142 = F_113 ( V_2 , V_148 ) ;
F_41 ( V_153 , & V_142 -> V_121 ) ;
V_142 -> V_117 = V_117 ;
F_121 ( V_2 , V_142 ) ;
if ( F_100 ( V_142 ) )
F_61 ( & V_142 -> V_22 , & V_2 -> V_154 ) ;
else
F_61 ( & V_142 -> V_22 , & V_2 -> V_155 ) ;
V_149 = F_90 ( V_146 [ V_147 ] . V_149 ) ;
if ( V_149 == V_118 )
goto V_152;
if ( V_149 >= V_6 -> V_137 ) {
F_91 ( V_6 , L_20 ,
V_117 , V_149 ) ;
return - V_72 ;
}
V_143 = F_113 ( V_2 , V_149 ) ;
if ( ! F_100 ( V_143 ) ) {
F_91 ( V_6 , L_21 ,
V_117 , V_149 ) ;
return - V_72 ;
}
F_41 ( V_153 , & V_143 -> V_121 ) ;
F_41 ( V_156 , & V_143 -> V_121 ) ;
V_143 -> V_117 = V_117 ;
V_143 -> V_143 = V_142 ;
V_142 -> V_143 = V_143 ;
F_121 ( V_2 , V_143 ) ;
F_61 ( & V_143 -> V_22 , & V_2 -> V_154 ) ;
V_152:
V_117 ++ ;
V_147 ++ ;
if ( V_147 >= V_157 )
V_144 = NULL ;
}
for ( V_105 = 0 ; V_105 < V_6 -> V_137 ; V_105 ++ ) {
V_142 = F_113 ( V_2 , V_105 ) ;
if ( F_122 ( V_142 ) )
continue;
if ( F_100 ( V_142 ) )
V_2 -> V_10 ++ ;
else
V_2 -> V_158 ++ ;
if ( F_123 ( V_142 ) ) {
continue;
}
F_41 ( V_153 , & V_142 -> V_121 ) ;
V_142 -> V_117 = V_118 ;
if ( F_100 ( V_142 ) ) {
F_61 ( & V_142 -> V_22 , & V_2 -> V_159 ) ;
F_31 ( & V_2 -> V_11 ) ;
} else if ( F_7 ( & V_2 -> V_160 ) < V_2 -> V_87 ) {
F_61 ( & V_142 -> V_22 , & V_2 -> V_161 ) ;
F_31 ( & V_2 -> V_160 ) ;
V_2 -> V_158 -- ;
} else {
F_61 ( & V_142 -> V_22 , & V_2 -> V_162 ) ;
F_31 ( & V_2 -> V_163 ) ;
}
}
return 0 ;
}
static void F_124 ( struct V_1 * V_2 , unsigned int V_117 ,
unsigned int V_148 , unsigned int V_149 )
{
struct V_15 * V_144 = V_2 -> V_150 [ V_117 >> V_164 ] ;
struct V_145 * V_146 = (struct V_145 * ) V_144 -> V_30 ;
int V_165 = V_117 & V_166 ;
V_146 [ V_165 ] . V_148 = F_72 ( V_148 ) ;
V_146 [ V_165 ] . V_149 = F_72 ( V_149 ) ;
F_66 ( V_2 , V_144 ) ;
}
static void F_125 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_54 ( & V_4 -> V_22 ) )
return;
F_21 ( & V_4 -> V_22 ) ;
if ( F_110 ( V_4 ) ) {
F_61 ( & V_4 -> V_22 , & V_2 -> V_155 ) ;
} else {
F_61 ( & V_4 -> V_22 , & V_2 -> V_154 ) ;
}
}
static void F_126 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_125 ( V_2 , V_4 ) ;
if ( V_4 -> V_143 )
F_125 ( V_2 , V_4 -> V_143 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 ( V_167 ) ;
F_129 ( & V_2 -> V_168 , & V_167 , V_71 ) ;
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
F_130 ( V_169 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
F_131 ( & V_2 -> V_168 , & V_167 ) ;
}
int F_132 ( struct V_3 * V_4 )
{
if ( F_133 ( V_4 ) )
return 0 ;
return ! F_67 ( V_170 , & V_4 -> V_121 ) ;
}
void F_134 ( struct V_3 * V_4 )
{
F_83 ( F_133 ( V_4 ) ) ;
F_83 ( ! F_135 ( V_4 ) ) ;
F_43 ( V_170 , & V_4 -> V_121 ) ;
F_44 () ;
F_45 ( & V_4 -> V_121 , V_170 ) ;
}
static void F_136 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
F_137 ( & V_4 -> V_121 , V_170 , V_71 , V_169 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static struct V_3 * F_138 ( struct V_1 * V_2 )
{
struct V_3 * V_142 = NULL ;
struct V_3 * V_4 ;
if ( F_54 ( & V_2 -> V_154 ) )
return NULL ;
F_78 (zone, &zmd->map_rnd_list, link) {
if ( F_139 ( V_4 ) )
V_142 = V_4 -> V_143 ;
else
V_142 = V_4 ;
if ( F_132 ( V_142 ) )
return V_142 ;
}
return NULL ;
}
static struct V_3 * F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( F_54 ( & V_2 -> V_155 ) )
return NULL ;
F_78 (zone, &zmd->map_seq_list, link) {
if ( ! V_4 -> V_143 )
continue;
if ( F_132 ( V_4 ) )
return V_4 ;
}
return NULL ;
}
struct V_3 * F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_8 ( V_2 ) ;
if ( F_54 ( & V_2 -> V_161 ) )
V_4 = F_140 ( V_2 ) ;
else
V_4 = F_138 ( V_2 ) ;
F_10 ( V_2 ) ;
return V_4 ;
}
void F_142 ( struct V_3 * V_4 )
{
F_41 ( V_171 , & V_4 -> V_121 ) ;
F_31 ( & V_4 -> V_116 ) ;
}
void F_143 ( struct V_3 * V_4 )
{
if ( F_59 ( & V_4 -> V_116 ) ) {
F_83 ( ! F_60 ( V_171 , & V_4 -> V_121 ) ) ;
F_43 ( V_171 , & V_4 -> V_121 ) ;
F_44 () ;
}
}
struct V_3 * F_144 ( struct V_1 * V_2 , unsigned int V_117 , int V_75 )
{
struct V_15 * V_144 = V_2 -> V_150 [ V_117 >> V_164 ] ;
struct V_145 * V_146 = (struct V_145 * ) V_144 -> V_30 ;
int V_172 = V_117 & V_166 ;
unsigned int V_148 ;
struct V_3 * V_142 = NULL ;
int V_76 = 0 ;
F_8 ( V_2 ) ;
V_173:
V_148 = F_90 ( V_146 [ V_172 ] . V_148 ) ;
if ( V_148 == V_118 ) {
if ( V_75 != V_44 )
goto V_96;
V_142 = F_145 ( V_2 , V_174 ) ;
if ( ! V_142 ) {
F_127 ( V_2 ) ;
goto V_173;
}
F_146 ( V_2 , V_142 , V_117 ) ;
} else {
V_142 = F_113 ( V_2 , V_148 ) ;
if ( V_142 -> V_117 != V_117 ) {
V_142 = F_64 ( - V_72 ) ;
goto V_96;
}
if ( F_116 ( V_142 ) ) {
V_76 = F_111 ( V_2 , V_142 ) ;
if ( V_76 ) {
V_142 = F_64 ( - V_72 ) ;
goto V_96;
}
F_80 ( V_141 , & V_142 -> V_121 ) ;
}
}
if ( F_135 ( V_142 ) ) {
F_136 ( V_2 , V_142 ) ;
goto V_173;
}
F_142 ( V_142 ) ;
F_126 ( V_2 , V_142 ) ;
V_96:
F_10 ( V_2 ) ;
return V_142 ;
}
void F_147 ( struct V_1 * V_2 , struct V_3 * V_142 )
{
struct V_3 * V_143 ;
F_8 ( V_2 ) ;
V_143 = V_142 -> V_143 ;
if ( V_143 ) {
if ( F_148 ( V_143 ) )
F_126 ( V_2 , V_143 ) ;
else {
F_149 ( V_2 , V_143 ) ;
F_150 ( V_2 , V_143 ) ;
V_143 = NULL ;
}
}
F_143 ( V_142 ) ;
if ( F_133 ( V_142 ) || V_143 || F_148 ( V_142 ) )
F_126 ( V_2 , V_142 ) ;
else {
F_149 ( V_2 , V_142 ) ;
F_150 ( V_2 , V_142 ) ;
}
F_10 ( V_2 ) ;
}
struct V_3 * F_151 ( struct V_1 * V_2 ,
struct V_3 * V_142 )
{
struct V_3 * V_143 ;
F_8 ( V_2 ) ;
V_173:
V_143 = V_142 -> V_143 ;
if ( V_143 )
goto V_96;
V_143 = F_145 ( V_2 , V_174 ) ;
if ( ! V_143 ) {
F_127 ( V_2 ) ;
goto V_173;
}
F_124 ( V_2 , V_142 -> V_117 , F_1 ( V_2 , V_142 ) ,
F_1 ( V_2 , V_143 ) ) ;
F_41 ( V_156 , & V_143 -> V_121 ) ;
V_143 -> V_117 = V_142 -> V_117 ;
V_143 -> V_143 = V_142 ;
V_142 -> V_143 = V_143 ;
F_61 ( & V_143 -> V_22 , & V_2 -> V_154 ) ;
V_96:
F_10 ( V_2 ) ;
return V_143 ;
}
struct V_3 * F_145 ( struct V_1 * V_2 , unsigned long V_121 )
{
struct V_91 * V_175 ;
struct V_3 * V_4 ;
if ( V_121 & V_174 )
V_175 = & V_2 -> V_159 ;
else
V_175 = & V_2 -> V_162 ;
V_173:
if ( F_54 ( V_175 ) ) {
if ( ! ( V_121 & V_176 ) ||
F_54 ( & V_2 -> V_161 ) )
return NULL ;
V_4 = F_55 ( & V_2 -> V_161 ,
struct V_3 , V_22 ) ;
F_21 ( & V_4 -> V_22 ) ;
F_34 ( & V_2 -> V_160 ) ;
return V_4 ;
}
V_4 = F_55 ( V_175 , struct V_3 , V_22 ) ;
F_21 ( & V_4 -> V_22 ) ;
if ( F_100 ( V_4 ) )
F_34 ( & V_2 -> V_11 ) ;
else
F_34 ( & V_2 -> V_163 ) ;
if ( F_102 ( V_4 ) ) {
F_96 ( V_2 -> V_6 , L_22 , F_1 ( V_2 , V_4 ) ) ;
V_4 = NULL ;
goto V_173;
}
return V_4 ;
}
void F_150 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_110 ( V_4 ) )
F_114 ( V_2 , V_4 ) ;
if ( F_100 ( V_4 ) ) {
F_61 ( & V_4 -> V_22 , & V_2 -> V_159 ) ;
F_31 ( & V_2 -> V_11 ) ;
} else if ( F_7 ( & V_2 -> V_160 ) <
V_2 -> V_87 ) {
F_61 ( & V_4 -> V_22 , & V_2 -> V_161 ) ;
F_31 ( & V_2 -> V_160 ) ;
} else {
F_61 ( & V_4 -> V_22 , & V_2 -> V_162 ) ;
F_31 ( & V_2 -> V_163 ) ;
}
F_152 ( & V_2 -> V_168 ) ;
}
void F_146 ( struct V_1 * V_2 , struct V_3 * V_142 ,
unsigned int V_117 )
{
F_124 ( V_2 , V_117 , F_1 ( V_2 , V_142 ) ,
V_118 ) ;
V_142 -> V_117 = V_117 ;
if ( F_100 ( V_142 ) )
F_61 ( & V_142 -> V_22 , & V_2 -> V_154 ) ;
else
F_61 ( & V_142 -> V_22 , & V_2 -> V_155 ) ;
}
void F_149 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_117 = V_4 -> V_117 ;
unsigned int V_148 ;
if ( V_117 == V_118 ) {
return;
}
if ( F_153 ( V_156 , & V_4 -> V_121 ) ) {
V_148 = F_1 ( V_2 , V_4 -> V_143 ) ;
V_4 -> V_143 -> V_143 = NULL ;
V_4 -> V_143 = NULL ;
} else {
if ( F_83 ( V_4 -> V_143 ) ) {
V_4 -> V_143 -> V_143 = NULL ;
V_4 -> V_143 = NULL ;
}
V_148 = V_118 ;
}
F_124 ( V_2 , V_117 , V_148 , V_118 ) ;
V_4 -> V_117 = V_118 ;
F_21 ( & V_4 -> V_22 ) ;
}
static unsigned int F_154 ( unsigned long * V_177 ,
unsigned int V_178 , unsigned int V_179 )
{
unsigned long * V_180 ;
unsigned int V_181 = V_178 + V_179 ;
unsigned int V_182 = 0 ;
while ( V_178 < V_181 ) {
if ( ( ( V_178 & ( V_183 - 1 ) ) == 0 ) &&
( ( V_181 - V_178 ) >= V_183 ) ) {
V_180 = V_177 + F_155 ( V_178 ) ;
if ( * V_180 == 0 ) {
* V_180 = V_184 ;
V_182 += V_183 ;
V_178 += V_183 ;
continue;
}
}
if ( ! F_67 ( V_178 , V_177 ) )
V_182 ++ ;
V_178 ++ ;
}
return V_182 ;
}
static struct V_15 * F_156 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_185 )
{
T_1 V_186 = 1 + V_2 -> V_88 +
( T_1 ) ( F_1 ( V_2 , V_4 ) * V_2 -> V_135 ) +
( V_185 >> V_187 ) ;
return F_62 ( V_2 , V_186 ) ;
}
int F_157 ( struct V_1 * V_2 , struct V_3 * V_188 ,
struct V_3 * V_189 )
{
struct V_15 * V_190 , * V_191 ;
T_1 V_185 = 0 ;
while ( V_185 < V_2 -> V_6 -> V_102 ) {
V_190 = F_156 ( V_2 , V_188 , V_185 ) ;
if ( F_119 ( V_190 ) )
return F_120 ( V_190 ) ;
V_191 = F_156 ( V_2 , V_189 , V_185 ) ;
if ( F_119 ( V_191 ) ) {
F_58 ( V_2 , V_190 ) ;
return F_120 ( V_191 ) ;
}
memcpy ( V_191 -> V_30 , V_190 -> V_30 , V_58 ) ;
F_66 ( V_2 , V_191 ) ;
F_58 ( V_2 , V_191 ) ;
F_58 ( V_2 , V_190 ) ;
V_185 += V_192 ;
}
V_189 -> V_193 = V_188 -> V_193 ;
return 0 ;
}
int F_158 ( struct V_1 * V_2 , struct V_3 * V_188 ,
struct V_3 * V_189 , T_1 V_185 )
{
unsigned int V_194 ;
int V_76 ;
while ( V_185 < V_2 -> V_6 -> V_102 ) {
V_76 = F_159 ( V_2 , V_188 , & V_185 ) ;
if ( V_76 <= 0 )
return V_76 ;
V_194 = V_76 ;
V_76 = F_160 ( V_2 , V_189 , V_185 , V_194 ) ;
if ( V_76 )
return V_76 ;
V_185 += V_194 ;
}
return 0 ;
}
int F_160 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_185 , unsigned int V_194 )
{
unsigned int V_60 , V_178 , V_179 ;
unsigned int V_102 = V_2 -> V_6 -> V_102 ;
struct V_15 * V_17 ;
unsigned int V_182 = 0 ;
F_98 ( V_2 -> V_6 , L_23 ,
F_1 ( V_2 , V_4 ) , ( unsigned long long ) V_185 ,
V_194 ) ;
F_83 ( V_185 + V_194 > V_102 ) ;
while ( V_194 ) {
V_17 = F_156 ( V_2 , V_4 , V_185 ) ;
if ( F_119 ( V_17 ) )
return F_120 ( V_17 ) ;
V_178 = V_185 & V_195 ;
V_179 = F_161 ( V_194 , V_192 - V_178 ) ;
V_60 = F_154 ( ( unsigned long * ) V_17 -> V_30 , V_178 , V_179 ) ;
if ( V_60 ) {
F_66 ( V_2 , V_17 ) ;
V_182 += V_60 ;
}
F_58 ( V_2 , V_17 ) ;
V_194 -= V_179 ;
V_185 += V_179 ;
}
if ( F_162 ( V_4 -> V_193 + V_182 <= V_102 ) )
V_4 -> V_193 += V_182 ;
else {
F_96 ( V_2 -> V_6 , L_24 ,
F_1 ( V_2 , V_4 ) , V_4 -> V_193 ,
V_102 - V_182 ) ;
V_4 -> V_193 = V_102 ;
}
return 0 ;
}
static int F_163 ( unsigned long * V_177 , int V_178 , int V_179 )
{
unsigned long * V_180 ;
int V_181 = V_178 + V_179 ;
int V_182 = 0 ;
while ( V_178 < V_181 ) {
if ( ( ( V_178 & ( V_183 - 1 ) ) == 0 ) &&
( ( V_181 - V_178 ) >= V_183 ) ) {
V_180 = V_177 + F_155 ( V_178 ) ;
if ( * V_180 == V_184 ) {
* V_180 = 0 ;
V_182 += V_183 ;
V_178 += V_183 ;
continue;
}
}
if ( F_153 ( V_178 , V_177 ) )
V_182 ++ ;
V_178 ++ ;
}
return V_182 ;
}
int F_112 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_185 , unsigned int V_194 )
{
unsigned int V_60 , V_178 , V_179 ;
struct V_15 * V_17 ;
unsigned int V_182 = 0 ;
F_98 ( V_2 -> V_6 , L_25 ,
F_1 ( V_2 , V_4 ) , ( T_2 ) V_185 , V_194 ) ;
F_83 ( V_185 + V_194 > V_2 -> V_6 -> V_102 ) ;
while ( V_194 ) {
V_17 = F_156 ( V_2 , V_4 , V_185 ) ;
if ( F_119 ( V_17 ) )
return F_120 ( V_17 ) ;
V_178 = V_185 & V_195 ;
V_179 = F_161 ( V_194 , V_192 - V_178 ) ;
V_60 = F_163 ( ( unsigned long * ) V_17 -> V_30 ,
V_178 , V_179 ) ;
if ( V_60 ) {
F_66 ( V_2 , V_17 ) ;
V_182 += V_60 ;
}
F_58 ( V_2 , V_17 ) ;
V_194 -= V_179 ;
V_185 += V_179 ;
}
if ( V_4 -> V_193 >= V_182 )
V_4 -> V_193 -= V_182 ;
else {
F_96 ( V_2 -> V_6 , L_26 ,
F_1 ( V_2 , V_4 ) , V_4 -> V_193 , V_182 ) ;
V_4 -> V_193 = 0 ;
}
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_185 )
{
struct V_15 * V_17 ;
int V_76 ;
F_83 ( V_185 >= V_2 -> V_6 -> V_102 ) ;
V_17 = F_156 ( V_2 , V_4 , V_185 ) ;
if ( F_119 ( V_17 ) )
return F_120 ( V_17 ) ;
V_76 = F_60 ( V_185 & V_195 ,
( unsigned long * ) V_17 -> V_30 ) != 0 ;
F_58 ( V_2 , V_17 ) ;
return V_76 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_185 , unsigned int V_194 ,
int V_74 )
{
struct V_15 * V_17 ;
unsigned int V_178 , F_41 , V_179 ;
unsigned long * V_177 ;
int V_182 = 0 ;
F_83 ( V_185 + V_194 > V_2 -> V_6 -> V_102 ) ;
while ( V_194 ) {
V_17 = F_156 ( V_2 , V_4 , V_185 ) ;
if ( F_119 ( V_17 ) )
return F_120 ( V_17 ) ;
V_177 = ( unsigned long * ) V_17 -> V_30 ;
V_178 = V_185 & V_195 ;
V_179 = F_161 ( V_194 , V_192 - V_178 ) ;
if ( V_74 )
F_41 = F_166 ( V_177 , V_192 , V_178 ) ;
else
F_41 = F_167 ( V_177 , V_192 , V_178 ) ;
F_58 ( V_2 , V_17 ) ;
V_182 += F_41 - V_178 ;
if ( F_41 < V_192 )
break;
V_194 -= V_179 ;
V_185 += V_179 ;
}
return V_182 ;
}
int F_168 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_185 )
{
int V_196 ;
V_196 = F_164 ( V_2 , V_4 , V_185 ) ;
if ( V_196 <= 0 )
return V_196 ;
return F_165 ( V_2 , V_4 , V_185 ,
V_2 -> V_6 -> V_102 - V_185 , 0 ) ;
}
int F_159 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_185 )
{
T_1 V_197 = * V_185 ;
int V_76 ;
V_76 = F_165 ( V_2 , V_4 , V_197 ,
V_2 -> V_6 -> V_102 - V_197 , 1 ) ;
if ( V_76 < 0 )
return V_76 ;
V_197 += V_76 ;
* V_185 = V_197 ;
return F_165 ( V_2 , V_4 , V_197 ,
V_2 -> V_6 -> V_102 - V_197 , 0 ) ;
}
static int F_169 ( void * V_177 , int V_178 , int V_179 )
{
unsigned long * V_180 ;
int V_181 = V_178 + V_179 ;
int V_182 = 0 ;
while ( V_178 < V_181 ) {
if ( ( ( V_178 & ( V_183 - 1 ) ) == 0 ) &&
( ( V_181 - V_178 ) >= V_183 ) ) {
V_180 = ( unsigned long * ) V_177 + F_155 ( V_178 ) ;
if ( * V_180 == V_184 ) {
V_182 += V_183 ;
V_178 += V_183 ;
continue;
}
}
if ( F_60 ( V_178 , V_177 ) )
V_182 ++ ;
V_178 ++ ;
}
return V_182 ;
}
static void F_121 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_17 ;
T_1 V_185 = 0 ;
unsigned int V_178 , V_179 ;
unsigned int V_194 = V_2 -> V_6 -> V_102 ;
void * V_177 ;
int V_182 = 0 ;
while ( V_194 ) {
V_17 = F_156 ( V_2 , V_4 , V_185 ) ;
if ( F_119 ( V_17 ) ) {
V_182 = 0 ;
break;
}
V_177 = V_17 -> V_30 ;
V_178 = V_185 & V_195 ;
V_179 = F_161 ( V_194 , V_192 - V_178 ) ;
V_182 += F_169 ( V_177 , V_178 , V_179 ) ;
F_58 ( V_2 , V_17 ) ;
V_194 -= V_179 ;
V_185 += V_179 ;
}
V_4 -> V_193 = V_182 ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_15 * V_17 , * V_152 ;
int V_105 ;
if ( V_2 -> V_150 ) {
for ( V_105 = 0 ; V_105 < V_2 -> V_88 ; V_105 ++ )
F_58 ( V_2 , V_2 -> V_150 [ V_105 ] ) ;
F_26 ( V_2 -> V_150 ) ;
V_2 -> V_150 = NULL ;
}
for ( V_105 = 0 ; V_105 < 2 ; V_105 ++ ) {
if ( V_2 -> V_48 [ V_105 ] . V_17 ) {
F_32 ( V_2 , V_2 -> V_48 [ V_105 ] . V_17 ) ;
V_2 -> V_48 [ V_105 ] . V_17 = NULL ;
}
}
while ( ! F_54 ( & V_2 -> V_73 ) ) {
V_17 = F_55 ( & V_2 -> V_73 ,
struct V_15 , V_22 ) ;
F_96 ( V_2 -> V_6 , L_27 ,
( T_2 ) V_17 -> V_25 , F_7 ( & V_17 -> V_28 ) ) ;
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
}
while ( ! F_54 ( & V_2 -> V_21 ) ) {
V_17 = F_55 ( & V_2 -> V_21 ,
struct V_15 , V_22 ) ;
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
}
V_32 = & V_2 -> V_24 ;
F_171 (mblk, next, root, node) {
F_96 ( V_2 -> V_6 , L_28 ,
( T_2 ) V_17 -> V_25 , F_7 ( & V_17 -> V_28 ) ) ;
F_29 ( & V_17 -> V_28 , 0 ) ;
F_32 ( V_2 , V_17 ) ;
}
F_104 ( V_2 ) ;
}
int F_172 ( struct V_99 * V_6 , struct V_1 * * V_198 )
{
struct V_1 * V_2 ;
unsigned int V_105 , V_199 ;
struct V_3 * V_4 ;
int V_76 ;
V_2 = F_173 ( sizeof( struct V_1 ) , V_138 ) ;
if ( ! V_2 )
return - V_70 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_24 = V_200 ;
F_174 ( & V_2 -> V_13 ) ;
F_175 ( & V_2 -> V_14 ) ;
F_176 ( & V_2 -> V_20 ) ;
F_28 ( & V_2 -> V_21 ) ;
F_28 ( & V_2 -> V_73 ) ;
F_175 ( & V_2 -> V_12 ) ;
F_29 ( & V_2 -> V_11 , 0 ) ;
F_28 ( & V_2 -> V_159 ) ;
F_28 ( & V_2 -> V_154 ) ;
F_29 ( & V_2 -> V_163 , 0 ) ;
F_28 ( & V_2 -> V_162 ) ;
F_28 ( & V_2 -> V_155 ) ;
F_29 ( & V_2 -> V_160 , 0 ) ;
F_28 ( & V_2 -> V_161 ) ;
F_177 ( & V_2 -> V_168 ) ;
V_76 = F_105 ( V_2 ) ;
if ( V_76 )
goto V_201;
V_76 = F_97 ( V_2 ) ;
if ( V_76 )
goto V_201;
V_199 = F_1 ( V_2 , V_2 -> V_108 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_97 << 1 ; V_105 ++ ) {
V_4 = F_113 ( V_2 , V_199 + V_105 ) ;
if ( ! F_100 ( V_4 ) )
goto V_201;
F_41 ( V_202 , & V_4 -> V_121 ) ;
}
V_76 = F_118 ( V_2 ) ;
if ( V_76 )
goto V_201;
V_2 -> V_61 = 2 + V_2 -> V_88 + V_2 -> V_135 * 16 ;
V_2 -> V_18 = V_2 -> V_61 + 512 ;
V_2 -> V_66 . V_203 = F_56 ;
V_2 -> V_66 . V_204 = F_57 ;
V_2 -> V_66 . V_205 = V_206 ;
V_76 = F_178 ( & V_2 -> V_66 ) ;
if ( V_76 ) {
F_91 ( V_6 , L_29 ) ;
goto V_201;
}
F_107 ( V_6 , L_30 ,
F_179 ( V_6 -> V_53 ) == V_207 ?
L_31 : L_32 ) ;
F_107 ( V_6 , L_33 ,
( T_2 ) V_6 -> V_115 ) ;
F_107 ( V_6 , L_34 ,
V_6 -> V_137 , ( T_2 ) V_6 -> V_113 ) ;
F_107 ( V_6 , L_35 ,
V_2 -> V_97 * 2 ) ;
F_107 ( V_6 , L_36 ,
V_2 -> V_98 , V_2 -> V_9 ) ;
F_107 ( V_6 , L_37 ,
V_2 -> V_10 , F_7 ( & V_2 -> V_11 ) ) ;
F_107 ( V_6 , L_38 ,
V_2 -> V_158 , F_7 ( & V_2 -> V_163 ) ) ;
F_107 ( V_6 , L_39 ,
V_2 -> V_87 ) ;
F_98 ( V_6 , L_40 ) ;
F_98 ( V_6 , L_41 ,
V_2 -> V_86 , V_2 -> V_18 ) ;
F_98 ( V_6 , L_42 ,
V_2 -> V_88 ) ;
F_98 ( V_6 , L_43 ,
V_2 -> V_89 ) ;
* V_198 = V_2 ;
return 0 ;
V_201:
F_170 ( V_2 ) ;
F_26 ( V_2 ) ;
* V_198 = NULL ;
return V_76 ;
}
void F_180 ( struct V_1 * V_2 )
{
F_181 ( & V_2 -> V_66 ) ;
F_170 ( V_2 ) ;
F_26 ( V_2 ) ;
}
int F_182 ( struct V_1 * V_2 )
{
struct V_99 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
T_1 V_130 ;
unsigned int V_105 ;
int V_76 ;
for ( V_105 = 0 ; V_105 < V_6 -> V_137 ; V_105 ++ ) {
V_4 = F_113 ( V_2 , V_105 ) ;
if ( ! V_4 ) {
F_91 ( V_6 , L_44 , V_105 ) ;
return - V_72 ;
}
V_130 = V_4 -> V_130 ;
V_76 = F_109 ( V_2 , V_4 ) ;
if ( V_76 ) {
F_91 ( V_6 , L_45 , V_105 ) ;
return V_76 ;
}
if ( F_102 ( V_4 ) ) {
F_96 ( V_6 , L_22 , V_105 ) ;
continue;
}
if ( ! F_110 ( V_4 ) )
V_4 -> V_130 = 0 ;
else if ( V_4 -> V_130 != V_130 ) {
F_91 ( V_6 , L_46 ,
V_105 , ( T_2 ) V_4 -> V_130 , ( T_2 ) V_130 ) ;
V_4 -> V_130 = V_130 ;
F_112 ( V_2 , V_4 , V_4 -> V_130 ,
V_6 -> V_102 - V_4 -> V_130 ) ;
}
}
return 0 ;
}
