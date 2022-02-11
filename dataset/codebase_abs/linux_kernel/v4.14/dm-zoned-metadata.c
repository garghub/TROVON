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
F_50 ( V_39 , V_2 -> V_6 -> V_52 ) ;
V_39 -> V_40 = V_17 ;
V_39 -> V_53 = F_40 ;
F_51 ( V_39 , V_54 , V_55 | V_56 ) ;
F_52 ( V_39 , V_17 -> V_27 , V_57 , 0 ) ;
F_53 ( V_39 ) ;
return V_17 ;
}
static unsigned long F_54 ( struct V_1 * V_2 ,
unsigned long V_58 )
{
struct V_15 * V_17 ;
unsigned long V_59 = 0 ;
if ( ! V_2 -> V_18 )
return 0 ;
while ( ! F_55 ( & V_2 -> V_21 ) &&
F_7 ( & V_2 -> V_19 ) > V_2 -> V_60 &&
V_59 < V_58 ) {
V_17 = F_56 ( & V_2 -> V_21 ,
struct V_15 , V_22 ) ;
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
V_59 ++ ;
}
return V_59 ;
}
static unsigned long F_57 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_36 ( V_62 , struct V_1 , V_65 ) ;
return F_7 ( & V_2 -> V_19 ) ;
}
static unsigned long F_58 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_36 ( V_62 , struct V_1 , V_65 ) ;
unsigned long V_59 ;
F_19 ( & V_2 -> V_20 ) ;
V_59 = F_54 ( V_2 , V_64 -> V_66 ) ;
F_23 ( & V_2 -> V_20 ) ;
return V_59 ? V_59 : V_67 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_15 * V_17 )
{
if ( ! V_17 )
return;
F_19 ( & V_2 -> V_20 ) ;
if ( F_60 ( & V_17 -> V_28 ) ) {
if ( F_61 ( V_43 , & V_17 -> V_29 ) ) {
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
} else if ( ! F_61 ( V_68 , & V_17 -> V_29 ) ) {
F_62 ( & V_17 -> V_22 , & V_2 -> V_21 ) ;
F_54 ( V_2 , 1 ) ;
}
}
F_23 ( & V_2 -> V_20 ) ;
}
static struct V_15 * F_63 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_15 * V_17 ;
F_19 ( & V_2 -> V_20 ) ;
V_17 = F_39 ( V_2 , V_16 ) ;
if ( V_17 ) {
if ( F_64 ( & V_17 -> V_28 ) == 1 &&
! F_61 ( V_68 , & V_17 -> V_29 ) )
F_21 ( & V_17 -> V_22 ) ;
}
F_23 ( & V_2 -> V_20 ) ;
if ( ! V_17 ) {
V_17 = F_47 ( V_2 , V_16 ) ;
if ( ! V_17 )
return F_65 ( - V_69 ) ;
}
F_66 ( & V_17 -> V_29 , V_46 ,
V_70 ) ;
if ( F_61 ( V_43 , & V_17 -> V_29 ) ) {
F_59 ( V_2 , V_17 ) ;
return F_65 ( - V_71 ) ;
}
return V_17 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_15 * V_17 )
{
F_19 ( & V_2 -> V_20 ) ;
if ( ! F_68 ( V_68 , & V_17 -> V_29 ) )
F_62 ( & V_17 -> V_22 , & V_2 -> V_72 ) ;
F_23 ( & V_2 -> V_20 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_15 * V_17 ,
unsigned int V_73 )
{
T_1 V_47 = V_2 -> V_48 [ V_73 ] . V_47 + V_17 -> V_25 ;
struct V_39 * V_39 ;
V_39 = F_48 ( V_26 , 1 ) ;
if ( ! V_39 ) {
F_41 ( V_43 , & V_17 -> V_29 ) ;
return;
}
F_41 ( V_45 , & V_17 -> V_29 ) ;
V_39 -> V_50 . V_51 = F_49 ( V_47 ) ;
F_50 ( V_39 , V_2 -> V_6 -> V_52 ) ;
V_39 -> V_40 = V_17 ;
V_39 -> V_53 = F_40 ;
F_51 ( V_39 , V_44 , V_55 | V_56 ) ;
F_52 ( V_39 , V_17 -> V_27 , V_57 , 0 ) ;
F_53 ( V_39 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_74 , T_1 V_47 ,
struct V_27 * V_27 )
{
struct V_39 * V_39 ;
int V_75 ;
V_39 = F_48 ( V_26 , 1 ) ;
if ( ! V_39 )
return - V_69 ;
V_39 -> V_50 . V_51 = F_49 ( V_47 ) ;
F_50 ( V_39 , V_2 -> V_6 -> V_52 ) ;
F_51 ( V_39 , V_74 , V_76 | V_55 | V_56 ) ;
F_52 ( V_39 , V_27 , V_57 , 0 ) ;
V_75 = F_71 ( V_39 ) ;
F_46 ( V_39 ) ;
return V_75 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_73 )
{
T_1 V_47 = V_2 -> V_48 [ V_73 ] . V_47 ;
struct V_15 * V_17 = V_2 -> V_48 [ V_73 ] . V_17 ;
struct V_77 * V_48 = V_2 -> V_48 [ V_73 ] . V_48 ;
T_2 V_78 = V_2 -> V_78 + 1 ;
int V_75 ;
V_48 -> V_79 = F_73 ( V_80 ) ;
V_48 -> V_81 = F_73 ( V_82 ) ;
V_48 -> V_83 = F_74 ( V_78 ) ;
V_48 -> V_84 = F_74 ( V_47 ) ;
V_48 -> V_85 = F_73 ( V_2 -> V_85 ) ;
V_48 -> V_86 = F_73 ( V_2 -> V_86 ) ;
V_48 -> V_9 = F_73 ( V_2 -> V_9 ) ;
V_48 -> V_87 = F_73 ( V_2 -> V_87 ) ;
V_48 -> V_88 = F_73 ( V_2 -> V_88 ) ;
V_48 -> V_89 = 0 ;
V_48 -> V_89 = F_73 ( F_75 ( V_78 , ( unsigned char * ) V_48 , V_57 ) ) ;
V_75 = F_70 ( V_2 , V_44 , V_47 , V_17 -> V_27 ) ;
if ( V_75 == 0 )
V_75 = F_76 ( V_2 -> V_6 -> V_52 , V_26 , NULL ) ;
return V_75 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_90 * V_91 ,
unsigned int V_73 )
{
struct V_15 * V_17 ;
struct V_92 V_93 ;
int V_75 = 0 ;
F_78 ( & V_93 ) ;
F_79 (mblk, write_list, link)
F_69 ( V_2 , V_17 , V_73 ) ;
F_80 ( & V_93 ) ;
F_79 (mblk, write_list, link) {
F_66 ( & V_17 -> V_29 , V_45 ,
V_70 ) ;
if ( F_61 ( V_43 , & V_17 -> V_29 ) ) {
F_81 ( V_43 , & V_17 -> V_29 ) ;
V_75 = - V_71 ;
}
}
if ( V_75 == 0 )
V_75 = F_76 ( V_2 -> V_6 -> V_52 , V_26 , NULL ) ;
return V_75 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
unsigned int V_94 = V_2 -> V_49 ^ 0x1 ;
int V_75 ;
V_75 = F_77 ( V_2 , V_91 , V_94 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_72 ( V_2 , V_94 ) ;
if ( V_75 )
return V_75 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_17 ;
struct V_90 V_91 ;
int V_75 ;
if ( F_84 ( ! V_2 ) )
return 0 ;
F_28 ( & V_91 ) ;
F_85 ( & V_2 -> V_13 ) ;
F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_20 ) ;
F_86 ( & V_2 -> V_72 , & V_91 ) ;
F_23 ( & V_2 -> V_20 ) ;
if ( F_55 ( & V_91 ) ) {
V_75 = F_76 ( V_2 -> V_6 -> V_52 , V_26 , NULL ) ;
goto V_95;
}
V_75 = F_82 ( V_2 , & V_91 ) ;
if ( V_75 )
goto V_95;
V_75 = F_77 ( V_2 , & V_91 , V_2 -> V_49 ) ;
if ( V_75 )
goto V_95;
V_75 = F_72 ( V_2 , V_2 -> V_49 ) ;
if ( V_75 )
goto V_95;
while ( ! F_55 ( & V_91 ) ) {
V_17 = F_56 ( & V_91 , struct V_15 , V_22 ) ;
F_21 ( & V_17 -> V_22 ) ;
F_19 ( & V_2 -> V_20 ) ;
F_81 ( V_68 , & V_17 -> V_29 ) ;
if ( F_7 ( & V_17 -> V_28 ) == 0 )
F_62 ( & V_17 -> V_22 , & V_2 -> V_21 ) ;
F_23 ( & V_2 -> V_20 ) ;
}
V_2 -> V_78 ++ ;
V_95:
if ( V_75 && ! F_55 ( & V_91 ) ) {
F_19 ( & V_2 -> V_20 ) ;
F_87 ( & V_91 , & V_2 -> V_72 ) ;
F_23 ( & V_2 -> V_20 ) ;
}
F_17 ( V_2 ) ;
F_88 ( & V_2 -> V_13 ) ;
return V_75 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_77 * V_48 )
{
unsigned int V_96 , V_97 ;
struct V_98 * V_6 = V_2 -> V_6 ;
T_3 V_89 , V_99 ;
T_2 V_83 ;
V_83 = F_90 ( V_48 -> V_83 ) ;
V_99 = F_91 ( V_48 -> V_89 ) ;
V_48 -> V_89 = 0 ;
V_89 = F_75 ( V_83 , ( unsigned char * ) V_48 , V_57 ) ;
if ( V_89 != V_99 ) {
F_92 ( V_6 , L_1 ,
V_89 , V_99 ) ;
return - V_100 ;
}
if ( F_91 ( V_48 -> V_79 ) != V_80 ) {
F_92 ( V_6 , L_2 ,
V_80 , F_91 ( V_48 -> V_79 ) ) ;
return - V_100 ;
}
if ( F_91 ( V_48 -> V_81 ) != V_82 ) {
F_92 ( V_6 , L_3 ,
V_82 , F_91 ( V_48 -> V_81 ) ) ;
return - V_100 ;
}
V_96 = ( F_91 ( V_48 -> V_85 ) + V_6 -> V_101 - 1 )
>> V_6 -> V_8 ;
if ( ! V_96 ||
V_96 >= V_2 -> V_102 ) {
F_92 ( V_6 , L_4 ) ;
return - V_100 ;
}
if ( ! F_91 ( V_48 -> V_86 ) ||
F_91 ( V_48 -> V_86 ) >= ( V_2 -> V_103 - V_96 ) ) {
F_92 ( V_6 , L_5 ) ;
return - V_100 ;
}
V_97 = V_2 -> V_103 -
( V_96 * 2 + F_91 ( V_48 -> V_86 ) ) ;
if ( F_91 ( V_48 -> V_9 ) > V_97 ) {
F_92 ( V_6 , L_6 ,
F_91 ( V_48 -> V_9 ) , V_97 ) ;
return - V_100 ;
}
V_2 -> V_85 = F_91 ( V_48 -> V_85 ) ;
V_2 -> V_86 = F_91 ( V_48 -> V_86 ) ;
V_2 -> V_9 = F_91 ( V_48 -> V_9 ) ;
V_2 -> V_87 = F_91 ( V_48 -> V_87 ) ;
V_2 -> V_88 = F_91 ( V_48 -> V_88 ) ;
V_2 -> V_96 = V_96 ;
V_2 -> V_97 = V_97 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , unsigned int V_73 )
{
return F_70 ( V_2 , V_54 , V_2 -> V_48 [ V_73 ] . V_47 ,
V_2 -> V_48 [ V_73 ] . V_17 -> V_27 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
unsigned int V_101 = V_2 -> V_6 -> V_101 ;
struct V_15 * V_17 ;
int V_104 ;
V_17 = F_18 ( V_2 , 0 ) ;
if ( ! V_17 )
return - V_69 ;
V_2 -> V_48 [ 1 ] . V_17 = V_17 ;
V_2 -> V_48 [ 1 ] . V_48 = V_17 -> V_30 ;
V_2 -> V_48 [ 1 ] . V_47 = V_2 -> V_48 [ 0 ] . V_47 + V_101 ;
for ( V_104 = 0 ; V_104 < V_2 -> V_102 - 1 ; V_104 ++ ) {
if ( F_93 ( V_2 , 1 ) != 0 )
break;
if ( F_91 ( V_2 -> V_48 [ 1 ] . V_48 -> V_79 ) == V_80 )
return 0 ;
V_2 -> V_48 [ 1 ] . V_47 += V_101 ;
}
F_32 ( V_2 , V_17 ) ;
V_2 -> V_48 [ 1 ] . V_17 = NULL ;
return - V_71 ;
}
static int F_95 ( struct V_1 * V_2 , unsigned int V_73 )
{
struct V_15 * V_17 ;
int V_75 ;
V_17 = F_18 ( V_2 , 0 ) ;
if ( ! V_17 )
return - V_69 ;
V_2 -> V_48 [ V_73 ] . V_17 = V_17 ;
V_2 -> V_48 [ V_73 ] . V_48 = V_17 -> V_30 ;
V_75 = F_93 ( V_2 , V_73 ) ;
if ( V_75 ) {
F_32 ( V_2 , V_17 ) ;
V_2 -> V_48 [ V_73 ] . V_17 = NULL ;
return V_75 ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , unsigned int V_105 )
{
unsigned int V_106 = V_105 ^ 0x1 ;
struct V_27 * V_27 ;
int V_104 , V_75 ;
F_97 ( V_2 -> V_6 , L_7 , V_105 ) ;
if ( V_105 == 0 )
V_2 -> V_48 [ 0 ] . V_47 = F_3 ( V_2 , V_2 -> V_107 ) ;
else {
V_2 -> V_48 [ 1 ] . V_47 = V_2 -> V_48 [ 0 ] . V_47 +
( V_2 -> V_96 << V_2 -> V_6 -> V_8 ) ;
}
V_27 = F_25 ( V_26 ) ;
if ( ! V_27 )
return - V_69 ;
for ( V_104 = 1 ; V_104 < V_2 -> V_85 ; V_104 ++ ) {
V_75 = F_70 ( V_2 , V_54 ,
V_2 -> V_48 [ V_106 ] . V_47 + V_104 , V_27 ) ;
if ( V_75 )
goto V_95;
V_75 = F_70 ( V_2 , V_44 ,
V_2 -> V_48 [ V_105 ] . V_47 + V_104 , V_27 ) ;
if ( V_75 )
goto V_95;
}
if ( ! V_2 -> V_48 [ V_105 ] . V_17 ) {
V_2 -> V_48 [ V_105 ] . V_17 = F_18 ( V_2 , 0 ) ;
if ( ! V_2 -> V_48 [ V_105 ] . V_17 ) {
V_75 = - V_69 ;
goto V_95;
}
V_2 -> V_48 [ V_105 ] . V_48 = V_2 -> V_48 [ V_105 ] . V_17 -> V_30 ;
}
V_75 = F_72 ( V_2 , V_105 ) ;
V_95:
F_33 ( V_27 , 0 ) ;
return V_75 ;
}
static int F_98 ( struct V_1 * V_2 )
{
bool V_108 [ 2 ] = { false , false } ;
T_2 V_78 [ 2 ] = { 0 , 0 } ;
int V_75 ;
V_2 -> V_48 [ 0 ] . V_47 = F_3 ( V_2 , V_2 -> V_107 ) ;
V_75 = F_95 ( V_2 , 0 ) ;
if ( V_75 ) {
F_92 ( V_2 -> V_6 , L_8 ) ;
return V_75 ;
}
V_75 = F_89 ( V_2 , V_2 -> V_48 [ 0 ] . V_48 ) ;
if ( V_75 == 0 ) {
V_108 [ 0 ] = true ;
V_2 -> V_48 [ 1 ] . V_47 = V_2 -> V_48 [ 0 ] . V_47 +
( V_2 -> V_96 << V_2 -> V_6 -> V_8 ) ;
V_75 = F_95 ( V_2 , 1 ) ;
} else
V_75 = F_94 ( V_2 ) ;
if ( V_75 ) {
F_92 ( V_2 -> V_6 , L_9 ) ;
return V_75 ;
}
V_75 = F_89 ( V_2 , V_2 -> V_48 [ 1 ] . V_48 ) ;
if ( V_75 == 0 )
V_108 [ 1 ] = true ;
if ( ! V_108 [ 0 ] && ! V_108 [ 1 ] ) {
F_92 ( V_2 -> V_6 , L_10 ) ;
return - V_71 ;
}
if ( V_108 [ 0 ] )
V_78 [ 0 ] = F_90 ( V_2 -> V_48 [ 0 ] . V_48 -> V_83 ) ;
else
V_75 = F_96 ( V_2 , 0 ) ;
if ( V_108 [ 1 ] )
V_78 [ 1 ] = F_90 ( V_2 -> V_48 [ 1 ] . V_48 -> V_83 ) ;
else
V_75 = F_96 ( V_2 , 1 ) ;
if ( V_75 ) {
F_92 ( V_2 -> V_6 , L_11 ) ;
return - V_71 ;
}
if ( V_78 [ 0 ] >= V_78 [ 1 ] ) {
V_2 -> V_78 = V_78 [ 0 ] ;
V_2 -> V_49 = 0 ;
} else {
V_2 -> V_78 = V_78 [ 1 ] ;
V_2 -> V_49 = 1 ;
}
F_99 ( V_2 -> V_6 , L_12 ,
V_2 -> V_49 , V_2 -> V_78 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_109 * V_110 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
if ( V_110 -> V_111 != V_6 -> V_112 ) {
if ( V_110 -> V_113 + V_110 -> V_111 == V_6 -> V_114 )
return 0 ;
return - V_100 ;
}
F_28 ( & V_4 -> V_22 ) ;
F_29 ( & V_4 -> V_115 , 0 ) ;
V_4 -> V_116 = V_117 ;
if ( V_110 -> type == V_118 ) {
F_41 ( V_119 , & V_4 -> V_120 ) ;
V_2 -> V_102 ++ ;
} else if ( V_110 -> type == V_121 ||
V_110 -> type == V_122 ) {
F_41 ( V_123 , & V_4 -> V_120 ) ;
} else
return - V_100 ;
if ( V_110 -> V_124 == V_125 )
F_41 ( V_126 , & V_4 -> V_120 ) ;
else if ( V_110 -> V_124 == V_127 )
F_41 ( V_128 , & V_4 -> V_120 ) ;
if ( F_101 ( V_4 ) )
V_4 -> V_129 = 0 ;
else
V_4 -> V_129 = F_102 ( V_110 -> V_130 - V_110 -> V_113 ) ;
if ( ! F_103 ( V_4 ) && ! F_104 ( V_4 ) ) {
V_2 -> V_103 ++ ;
if ( F_101 ( V_4 ) ) {
V_2 -> V_102 ++ ;
if ( ! V_2 -> V_107 ) {
V_2 -> V_107 = V_4 ;
}
}
}
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
struct V_109 * V_110 ;
unsigned int V_131 ;
T_1 V_132 = 0 ;
int V_104 , V_75 = 0 ;
V_2 -> V_133 = V_6 -> V_101 >> 3 ;
V_2 -> V_134 = V_2 -> V_133 >> V_135 ;
V_2 -> V_5 = F_107 ( V_6 -> V_136 , sizeof( struct V_3 ) , V_137 ) ;
if ( ! V_2 -> V_5 )
return - V_69 ;
F_108 ( V_6 , L_13 ,
sizeof( struct V_3 ) * V_6 -> V_136 ) ;
V_131 = V_138 ;
V_110 = F_107 ( V_131 , sizeof( struct V_109 ) , V_137 ) ;
if ( ! V_110 ) {
V_75 = - V_69 ;
goto V_95;
}
V_4 = V_2 -> V_5 ;
while ( V_132 < V_6 -> V_114 ) {
V_131 = V_138 ;
V_75 = F_109 ( V_6 -> V_52 , V_132 , V_110 ,
& V_131 , V_137 ) ;
if ( V_75 ) {
F_92 ( V_6 , L_14 , V_75 ) ;
goto V_95;
}
for ( V_104 = 0 ; V_104 < V_131 ; V_104 ++ ) {
V_75 = F_100 ( V_2 , V_4 , & V_110 [ V_104 ] ) ;
if ( V_75 )
goto V_95;
V_132 += V_6 -> V_112 ;
V_4 ++ ;
}
}
if ( V_132 < V_6 -> V_114 ) {
F_92 ( V_6 , L_15 ) ;
V_75 = - V_100 ;
}
V_95:
F_26 ( V_110 ) ;
if ( V_75 )
F_105 ( V_2 ) ;
return V_75 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_131 = 1 ;
struct V_109 V_110 ;
int V_75 ;
V_75 = F_109 ( V_2 -> V_6 -> V_52 , F_2 ( V_2 , V_4 ) ,
& V_110 , & V_131 , V_26 ) ;
if ( V_75 ) {
F_92 ( V_2 -> V_6 , L_16 ,
F_1 ( V_2 , V_4 ) ) ;
return V_75 ;
}
F_81 ( V_126 , & V_4 -> V_120 ) ;
F_81 ( V_128 , & V_4 -> V_120 ) ;
if ( V_110 . V_124 == V_125 )
F_41 ( V_126 , & V_4 -> V_120 ) ;
else if ( V_110 . V_124 == V_127 )
F_41 ( V_128 , & V_4 -> V_120 ) ;
if ( F_111 ( V_4 ) )
V_4 -> V_129 = F_102 ( V_110 . V_130 - V_110 . V_113 ) ;
else
V_4 -> V_129 = 0 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_130 = 0 ;
int V_75 ;
V_130 = V_4 -> V_129 ;
V_75 = F_110 ( V_2 , V_4 ) ;
if ( V_75 )
return V_75 ;
F_97 ( V_2 -> V_6 , L_17 ,
F_1 ( V_2 , V_4 ) , V_4 -> V_129 , V_130 ) ;
if ( V_4 -> V_129 < V_130 ) {
F_113 ( V_2 , V_4 , V_4 -> V_129 ,
V_130 - V_4 -> V_129 ) ;
}
return 0 ;
}
static struct V_3 * F_114 ( struct V_1 * V_2 , unsigned int V_139 )
{
return & V_2 -> V_5 [ V_139 ] ;
}
static int F_115 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_75 ;
if ( F_103 ( V_4 ) ||
F_104 ( V_4 ) ||
F_101 ( V_4 ) )
return 0 ;
if ( ! F_116 ( V_4 ) || F_117 ( V_4 ) ) {
struct V_98 * V_6 = V_2 -> V_6 ;
V_75 = F_118 ( V_6 -> V_52 ,
F_2 ( V_2 , V_4 ) ,
V_6 -> V_112 , V_26 ) ;
if ( V_75 ) {
F_92 ( V_6 , L_18 ,
F_1 ( V_2 , V_4 ) , V_75 ) ;
return V_75 ;
}
}
F_81 ( V_140 , & V_4 -> V_120 ) ;
V_4 -> V_129 = 0 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
struct V_3 * V_141 , * V_142 ;
struct V_15 * V_143 = NULL ;
struct V_144 * V_145 ;
unsigned int V_104 = 0 , V_146 = 0 , V_116 = 0 ;
unsigned int V_147 ;
unsigned int V_148 ;
V_2 -> V_149 = F_107 ( V_2 -> V_87 ,
sizeof( struct V_150 * ) , V_137 ) ;
if ( ! V_2 -> V_149 )
return - V_69 ;
while ( V_116 < V_2 -> V_9 ) {
if ( ! V_143 ) {
V_143 = F_63 ( V_2 , V_104 + 1 ) ;
if ( F_120 ( V_143 ) )
return F_121 ( V_143 ) ;
V_2 -> V_149 [ V_104 ] = V_143 ;
V_145 = (struct V_144 * ) V_143 -> V_30 ;
V_104 ++ ;
V_146 = 0 ;
}
V_147 = F_91 ( V_145 [ V_146 ] . V_147 ) ;
if ( V_147 == V_117 )
goto V_151;
if ( V_147 >= V_6 -> V_136 ) {
F_92 ( V_6 , L_19 ,
V_116 , V_147 ) ;
return - V_71 ;
}
V_141 = F_114 ( V_2 , V_147 ) ;
F_41 ( V_152 , & V_141 -> V_120 ) ;
V_141 -> V_116 = V_116 ;
F_122 ( V_2 , V_141 ) ;
if ( F_101 ( V_141 ) )
F_62 ( & V_141 -> V_22 , & V_2 -> V_153 ) ;
else
F_62 ( & V_141 -> V_22 , & V_2 -> V_154 ) ;
V_148 = F_91 ( V_145 [ V_146 ] . V_148 ) ;
if ( V_148 == V_117 )
goto V_151;
if ( V_148 >= V_6 -> V_136 ) {
F_92 ( V_6 , L_20 ,
V_116 , V_148 ) ;
return - V_71 ;
}
V_142 = F_114 ( V_2 , V_148 ) ;
if ( ! F_101 ( V_142 ) ) {
F_92 ( V_6 , L_21 ,
V_116 , V_148 ) ;
return - V_71 ;
}
F_41 ( V_152 , & V_142 -> V_120 ) ;
F_41 ( V_155 , & V_142 -> V_120 ) ;
V_142 -> V_116 = V_116 ;
V_142 -> V_142 = V_141 ;
V_141 -> V_142 = V_142 ;
F_122 ( V_2 , V_142 ) ;
F_62 ( & V_142 -> V_22 , & V_2 -> V_153 ) ;
V_151:
V_116 ++ ;
V_146 ++ ;
if ( V_146 >= V_156 )
V_143 = NULL ;
}
for ( V_104 = 0 ; V_104 < V_6 -> V_136 ; V_104 ++ ) {
V_141 = F_114 ( V_2 , V_104 ) ;
if ( F_123 ( V_141 ) )
continue;
if ( F_101 ( V_141 ) )
V_2 -> V_10 ++ ;
else
V_2 -> V_157 ++ ;
if ( F_124 ( V_141 ) ) {
continue;
}
F_41 ( V_152 , & V_141 -> V_120 ) ;
V_141 -> V_116 = V_117 ;
if ( F_101 ( V_141 ) ) {
F_62 ( & V_141 -> V_22 , & V_2 -> V_158 ) ;
F_31 ( & V_2 -> V_11 ) ;
} else if ( F_7 ( & V_2 -> V_159 ) < V_2 -> V_86 ) {
F_62 ( & V_141 -> V_22 , & V_2 -> V_160 ) ;
F_31 ( & V_2 -> V_159 ) ;
V_2 -> V_157 -- ;
} else {
F_62 ( & V_141 -> V_22 , & V_2 -> V_161 ) ;
F_31 ( & V_2 -> V_162 ) ;
}
}
return 0 ;
}
static void F_125 ( struct V_1 * V_2 , unsigned int V_116 ,
unsigned int V_147 , unsigned int V_148 )
{
struct V_15 * V_143 = V_2 -> V_149 [ V_116 >> V_163 ] ;
struct V_144 * V_145 = (struct V_144 * ) V_143 -> V_30 ;
int V_164 = V_116 & V_165 ;
V_145 [ V_164 ] . V_147 = F_73 ( V_147 ) ;
V_145 [ V_164 ] . V_148 = F_73 ( V_148 ) ;
F_67 ( V_2 , V_143 ) ;
}
static void F_126 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_55 ( & V_4 -> V_22 ) )
return;
F_21 ( & V_4 -> V_22 ) ;
if ( F_111 ( V_4 ) ) {
F_62 ( & V_4 -> V_22 , & V_2 -> V_154 ) ;
} else {
F_62 ( & V_4 -> V_22 , & V_2 -> V_153 ) ;
}
}
static void F_127 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_126 ( V_2 , V_4 ) ;
if ( V_4 -> V_142 )
F_126 ( V_2 , V_4 -> V_142 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_129 ( V_166 ) ;
F_130 ( & V_2 -> V_167 , & V_166 , V_70 ) ;
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
F_131 ( V_168 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
F_132 ( & V_2 -> V_167 , & V_166 ) ;
}
int F_133 ( struct V_3 * V_4 )
{
if ( F_134 ( V_4 ) )
return 0 ;
return ! F_68 ( V_169 , & V_4 -> V_120 ) ;
}
void F_135 ( struct V_3 * V_4 )
{
F_84 ( F_134 ( V_4 ) ) ;
F_84 ( ! F_136 ( V_4 ) ) ;
F_43 ( V_169 , & V_4 -> V_120 ) ;
F_44 () ;
F_45 ( & V_4 -> V_120 , V_169 ) ;
}
static void F_137 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
F_138 ( & V_4 -> V_120 , V_169 , V_70 , V_168 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static struct V_3 * F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_141 = NULL ;
struct V_3 * V_4 ;
if ( F_55 ( & V_2 -> V_153 ) )
return NULL ;
F_79 (zone, &zmd->map_rnd_list, link) {
if ( F_140 ( V_4 ) )
V_141 = V_4 -> V_142 ;
else
V_141 = V_4 ;
if ( F_133 ( V_141 ) )
return V_141 ;
}
return NULL ;
}
static struct V_3 * F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( F_55 ( & V_2 -> V_154 ) )
return NULL ;
F_79 (zone, &zmd->map_seq_list, link) {
if ( ! V_4 -> V_142 )
continue;
if ( F_133 ( V_4 ) )
return V_4 ;
}
return NULL ;
}
struct V_3 * F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_8 ( V_2 ) ;
if ( F_55 ( & V_2 -> V_160 ) )
V_4 = F_141 ( V_2 ) ;
else
V_4 = F_139 ( V_2 ) ;
F_10 ( V_2 ) ;
return V_4 ;
}
void F_143 ( struct V_3 * V_4 )
{
F_41 ( V_170 , & V_4 -> V_120 ) ;
F_31 ( & V_4 -> V_115 ) ;
}
void F_144 ( struct V_3 * V_4 )
{
if ( F_60 ( & V_4 -> V_115 ) ) {
F_84 ( ! F_61 ( V_170 , & V_4 -> V_120 ) ) ;
F_43 ( V_170 , & V_4 -> V_120 ) ;
F_44 () ;
}
}
struct V_3 * F_145 ( struct V_1 * V_2 , unsigned int V_116 , int V_74 )
{
struct V_15 * V_143 = V_2 -> V_149 [ V_116 >> V_163 ] ;
struct V_144 * V_145 = (struct V_144 * ) V_143 -> V_30 ;
int V_171 = V_116 & V_165 ;
unsigned int V_147 ;
struct V_3 * V_141 = NULL ;
int V_75 = 0 ;
F_8 ( V_2 ) ;
V_172:
V_147 = F_91 ( V_145 [ V_171 ] . V_147 ) ;
if ( V_147 == V_117 ) {
if ( V_74 != V_44 )
goto V_95;
V_141 = F_146 ( V_2 , V_173 ) ;
if ( ! V_141 ) {
F_128 ( V_2 ) ;
goto V_172;
}
F_147 ( V_2 , V_141 , V_116 ) ;
} else {
V_141 = F_114 ( V_2 , V_147 ) ;
if ( V_141 -> V_116 != V_116 ) {
V_141 = F_65 ( - V_71 ) ;
goto V_95;
}
if ( F_117 ( V_141 ) ) {
V_75 = F_112 ( V_2 , V_141 ) ;
if ( V_75 ) {
V_141 = F_65 ( - V_71 ) ;
goto V_95;
}
F_81 ( V_140 , & V_141 -> V_120 ) ;
}
}
if ( F_136 ( V_141 ) ) {
F_137 ( V_2 , V_141 ) ;
goto V_172;
}
F_143 ( V_141 ) ;
F_127 ( V_2 , V_141 ) ;
V_95:
F_10 ( V_2 ) ;
return V_141 ;
}
void F_148 ( struct V_1 * V_2 , struct V_3 * V_141 )
{
struct V_3 * V_142 ;
F_8 ( V_2 ) ;
V_142 = V_141 -> V_142 ;
if ( V_142 ) {
if ( F_149 ( V_142 ) )
F_127 ( V_2 , V_142 ) ;
else {
F_150 ( V_2 , V_142 ) ;
F_151 ( V_2 , V_142 ) ;
V_142 = NULL ;
}
}
F_144 ( V_141 ) ;
if ( F_134 ( V_141 ) || V_142 || F_149 ( V_141 ) )
F_127 ( V_2 , V_141 ) ;
else {
F_150 ( V_2 , V_141 ) ;
F_151 ( V_2 , V_141 ) ;
}
F_10 ( V_2 ) ;
}
struct V_3 * F_152 ( struct V_1 * V_2 ,
struct V_3 * V_141 )
{
struct V_3 * V_142 ;
F_8 ( V_2 ) ;
V_172:
V_142 = V_141 -> V_142 ;
if ( V_142 )
goto V_95;
V_142 = F_146 ( V_2 , V_173 ) ;
if ( ! V_142 ) {
F_128 ( V_2 ) ;
goto V_172;
}
F_125 ( V_2 , V_141 -> V_116 , F_1 ( V_2 , V_141 ) ,
F_1 ( V_2 , V_142 ) ) ;
F_41 ( V_155 , & V_142 -> V_120 ) ;
V_142 -> V_116 = V_141 -> V_116 ;
V_142 -> V_142 = V_141 ;
V_141 -> V_142 = V_142 ;
F_62 ( & V_142 -> V_22 , & V_2 -> V_153 ) ;
V_95:
F_10 ( V_2 ) ;
return V_142 ;
}
struct V_3 * F_146 ( struct V_1 * V_2 , unsigned long V_120 )
{
struct V_90 * V_174 ;
struct V_3 * V_4 ;
if ( V_120 & V_173 )
V_174 = & V_2 -> V_158 ;
else
V_174 = & V_2 -> V_161 ;
V_172:
if ( F_55 ( V_174 ) ) {
if ( ! ( V_120 & V_175 ) ||
F_55 ( & V_2 -> V_160 ) )
return NULL ;
V_4 = F_56 ( & V_2 -> V_160 ,
struct V_3 , V_22 ) ;
F_21 ( & V_4 -> V_22 ) ;
F_34 ( & V_2 -> V_159 ) ;
return V_4 ;
}
V_4 = F_56 ( V_174 , struct V_3 , V_22 ) ;
F_21 ( & V_4 -> V_22 ) ;
if ( F_101 ( V_4 ) )
F_34 ( & V_2 -> V_11 ) ;
else
F_34 ( & V_2 -> V_162 ) ;
if ( F_103 ( V_4 ) ) {
F_97 ( V_2 -> V_6 , L_22 , F_1 ( V_2 , V_4 ) ) ;
V_4 = NULL ;
goto V_172;
}
return V_4 ;
}
void F_151 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_111 ( V_4 ) )
F_115 ( V_2 , V_4 ) ;
if ( F_101 ( V_4 ) ) {
F_62 ( & V_4 -> V_22 , & V_2 -> V_158 ) ;
F_31 ( & V_2 -> V_11 ) ;
} else if ( F_7 ( & V_2 -> V_159 ) <
V_2 -> V_86 ) {
F_62 ( & V_4 -> V_22 , & V_2 -> V_160 ) ;
F_31 ( & V_2 -> V_159 ) ;
} else {
F_62 ( & V_4 -> V_22 , & V_2 -> V_161 ) ;
F_31 ( & V_2 -> V_162 ) ;
}
F_153 ( & V_2 -> V_167 ) ;
}
void F_147 ( struct V_1 * V_2 , struct V_3 * V_141 ,
unsigned int V_116 )
{
F_125 ( V_2 , V_116 , F_1 ( V_2 , V_141 ) ,
V_117 ) ;
V_141 -> V_116 = V_116 ;
if ( F_101 ( V_141 ) )
F_62 ( & V_141 -> V_22 , & V_2 -> V_153 ) ;
else
F_62 ( & V_141 -> V_22 , & V_2 -> V_154 ) ;
}
void F_150 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_116 = V_4 -> V_116 ;
unsigned int V_147 ;
if ( V_116 == V_117 ) {
return;
}
if ( F_154 ( V_155 , & V_4 -> V_120 ) ) {
V_147 = F_1 ( V_2 , V_4 -> V_142 ) ;
V_4 -> V_142 -> V_142 = NULL ;
V_4 -> V_142 = NULL ;
} else {
if ( F_84 ( V_4 -> V_142 ) ) {
V_4 -> V_142 -> V_142 = NULL ;
V_4 -> V_142 = NULL ;
}
V_147 = V_117 ;
}
F_125 ( V_2 , V_116 , V_147 , V_117 ) ;
V_4 -> V_116 = V_117 ;
F_21 ( & V_4 -> V_22 ) ;
}
static unsigned int F_155 ( unsigned long * V_176 ,
unsigned int V_177 , unsigned int V_178 )
{
unsigned long * V_179 ;
unsigned int V_180 = V_177 + V_178 ;
unsigned int V_181 = 0 ;
while ( V_177 < V_180 ) {
if ( ( ( V_177 & ( V_182 - 1 ) ) == 0 ) &&
( ( V_180 - V_177 ) >= V_182 ) ) {
V_179 = V_176 + F_156 ( V_177 ) ;
if ( * V_179 == 0 ) {
* V_179 = V_183 ;
V_181 += V_182 ;
V_177 += V_182 ;
continue;
}
}
if ( ! F_68 ( V_177 , V_176 ) )
V_181 ++ ;
V_177 ++ ;
}
return V_181 ;
}
static struct V_15 * F_157 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_184 )
{
T_1 V_185 = 1 + V_2 -> V_87 +
( T_1 ) ( F_1 ( V_2 , V_4 ) * V_2 -> V_134 ) +
( V_184 >> V_186 ) ;
return F_63 ( V_2 , V_185 ) ;
}
int F_158 ( struct V_1 * V_2 , struct V_3 * V_187 ,
struct V_3 * V_188 )
{
struct V_15 * V_189 , * V_190 ;
T_1 V_184 = 0 ;
while ( V_184 < V_2 -> V_6 -> V_101 ) {
V_189 = F_157 ( V_2 , V_187 , V_184 ) ;
if ( F_120 ( V_189 ) )
return F_121 ( V_189 ) ;
V_190 = F_157 ( V_2 , V_188 , V_184 ) ;
if ( F_120 ( V_190 ) ) {
F_59 ( V_2 , V_189 ) ;
return F_121 ( V_190 ) ;
}
memcpy ( V_190 -> V_30 , V_189 -> V_30 , V_57 ) ;
F_67 ( V_2 , V_190 ) ;
F_59 ( V_2 , V_190 ) ;
F_59 ( V_2 , V_189 ) ;
V_184 += V_191 ;
}
V_188 -> V_192 = V_187 -> V_192 ;
return 0 ;
}
int F_159 ( struct V_1 * V_2 , struct V_3 * V_187 ,
struct V_3 * V_188 , T_1 V_184 )
{
unsigned int V_193 ;
int V_75 ;
while ( V_184 < V_2 -> V_6 -> V_101 ) {
V_75 = F_160 ( V_2 , V_187 , & V_184 ) ;
if ( V_75 <= 0 )
return V_75 ;
V_193 = V_75 ;
V_75 = F_161 ( V_2 , V_188 , V_184 , V_193 ) ;
if ( V_75 )
return V_75 ;
V_184 += V_193 ;
}
return 0 ;
}
int F_161 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_184 , unsigned int V_193 )
{
unsigned int V_59 , V_177 , V_178 ;
unsigned int V_101 = V_2 -> V_6 -> V_101 ;
struct V_15 * V_17 ;
unsigned int V_181 = 0 ;
F_99 ( V_2 -> V_6 , L_23 ,
F_1 ( V_2 , V_4 ) , ( unsigned long long ) V_184 ,
V_193 ) ;
F_84 ( V_184 + V_193 > V_101 ) ;
while ( V_193 ) {
V_17 = F_157 ( V_2 , V_4 , V_184 ) ;
if ( F_120 ( V_17 ) )
return F_121 ( V_17 ) ;
V_177 = V_184 & V_194 ;
V_178 = F_162 ( V_193 , V_191 - V_177 ) ;
V_59 = F_155 ( ( unsigned long * ) V_17 -> V_30 , V_177 , V_178 ) ;
if ( V_59 ) {
F_67 ( V_2 , V_17 ) ;
V_181 += V_59 ;
}
F_59 ( V_2 , V_17 ) ;
V_193 -= V_178 ;
V_184 += V_178 ;
}
if ( F_163 ( V_4 -> V_192 + V_181 <= V_101 ) )
V_4 -> V_192 += V_181 ;
else {
F_97 ( V_2 -> V_6 , L_24 ,
F_1 ( V_2 , V_4 ) , V_4 -> V_192 ,
V_101 - V_181 ) ;
V_4 -> V_192 = V_101 ;
}
return 0 ;
}
static int F_164 ( unsigned long * V_176 , int V_177 , int V_178 )
{
unsigned long * V_179 ;
int V_180 = V_177 + V_178 ;
int V_181 = 0 ;
while ( V_177 < V_180 ) {
if ( ( ( V_177 & ( V_182 - 1 ) ) == 0 ) &&
( ( V_180 - V_177 ) >= V_182 ) ) {
V_179 = V_176 + F_156 ( V_177 ) ;
if ( * V_179 == V_183 ) {
* V_179 = 0 ;
V_181 += V_182 ;
V_177 += V_182 ;
continue;
}
}
if ( F_154 ( V_177 , V_176 ) )
V_181 ++ ;
V_177 ++ ;
}
return V_181 ;
}
int F_113 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_184 , unsigned int V_193 )
{
unsigned int V_59 , V_177 , V_178 ;
struct V_15 * V_17 ;
unsigned int V_181 = 0 ;
F_99 ( V_2 -> V_6 , L_25 ,
F_1 ( V_2 , V_4 ) , ( T_2 ) V_184 , V_193 ) ;
F_84 ( V_184 + V_193 > V_2 -> V_6 -> V_101 ) ;
while ( V_193 ) {
V_17 = F_157 ( V_2 , V_4 , V_184 ) ;
if ( F_120 ( V_17 ) )
return F_121 ( V_17 ) ;
V_177 = V_184 & V_194 ;
V_178 = F_162 ( V_193 , V_191 - V_177 ) ;
V_59 = F_164 ( ( unsigned long * ) V_17 -> V_30 ,
V_177 , V_178 ) ;
if ( V_59 ) {
F_67 ( V_2 , V_17 ) ;
V_181 += V_59 ;
}
F_59 ( V_2 , V_17 ) ;
V_193 -= V_178 ;
V_184 += V_178 ;
}
if ( V_4 -> V_192 >= V_181 )
V_4 -> V_192 -= V_181 ;
else {
F_97 ( V_2 -> V_6 , L_26 ,
F_1 ( V_2 , V_4 ) , V_4 -> V_192 , V_181 ) ;
V_4 -> V_192 = 0 ;
}
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_184 )
{
struct V_15 * V_17 ;
int V_75 ;
F_84 ( V_184 >= V_2 -> V_6 -> V_101 ) ;
V_17 = F_157 ( V_2 , V_4 , V_184 ) ;
if ( F_120 ( V_17 ) )
return F_121 ( V_17 ) ;
V_75 = F_61 ( V_184 & V_194 ,
( unsigned long * ) V_17 -> V_30 ) != 0 ;
F_59 ( V_2 , V_17 ) ;
return V_75 ;
}
static int F_166 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_184 , unsigned int V_193 ,
int V_73 )
{
struct V_15 * V_17 ;
unsigned int V_177 , F_41 , V_178 ;
unsigned long * V_176 ;
int V_181 = 0 ;
F_84 ( V_184 + V_193 > V_2 -> V_6 -> V_101 ) ;
while ( V_193 ) {
V_17 = F_157 ( V_2 , V_4 , V_184 ) ;
if ( F_120 ( V_17 ) )
return F_121 ( V_17 ) ;
V_176 = ( unsigned long * ) V_17 -> V_30 ;
V_177 = V_184 & V_194 ;
V_178 = F_162 ( V_193 , V_191 - V_177 ) ;
if ( V_73 )
F_41 = F_167 ( V_176 , V_191 , V_177 ) ;
else
F_41 = F_168 ( V_176 , V_191 , V_177 ) ;
F_59 ( V_2 , V_17 ) ;
V_181 += F_41 - V_177 ;
if ( F_41 < V_191 )
break;
V_193 -= V_178 ;
V_184 += V_178 ;
}
return V_181 ;
}
int F_169 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_184 )
{
int V_195 ;
V_195 = F_165 ( V_2 , V_4 , V_184 ) ;
if ( V_195 <= 0 )
return V_195 ;
return F_166 ( V_2 , V_4 , V_184 ,
V_2 -> V_6 -> V_101 - V_184 , 0 ) ;
}
int F_160 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_184 )
{
T_1 V_196 = * V_184 ;
int V_75 ;
V_75 = F_166 ( V_2 , V_4 , V_196 ,
V_2 -> V_6 -> V_101 - V_196 , 1 ) ;
if ( V_75 < 0 )
return V_75 ;
V_196 += V_75 ;
* V_184 = V_196 ;
return F_166 ( V_2 , V_4 , V_196 ,
V_2 -> V_6 -> V_101 - V_196 , 0 ) ;
}
static int F_170 ( void * V_176 , int V_177 , int V_178 )
{
unsigned long * V_179 ;
int V_180 = V_177 + V_178 ;
int V_181 = 0 ;
while ( V_177 < V_180 ) {
if ( ( ( V_177 & ( V_182 - 1 ) ) == 0 ) &&
( ( V_180 - V_177 ) >= V_182 ) ) {
V_179 = ( unsigned long * ) V_176 + F_156 ( V_177 ) ;
if ( * V_179 == V_183 ) {
V_181 += V_182 ;
V_177 += V_182 ;
continue;
}
}
if ( F_61 ( V_177 , V_176 ) )
V_181 ++ ;
V_177 ++ ;
}
return V_181 ;
}
static void F_122 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_17 ;
T_1 V_184 = 0 ;
unsigned int V_177 , V_178 ;
unsigned int V_193 = V_2 -> V_6 -> V_101 ;
void * V_176 ;
int V_181 = 0 ;
while ( V_193 ) {
V_17 = F_157 ( V_2 , V_4 , V_184 ) ;
if ( F_120 ( V_17 ) ) {
V_181 = 0 ;
break;
}
V_176 = V_17 -> V_30 ;
V_177 = V_184 & V_194 ;
V_178 = F_162 ( V_193 , V_191 - V_177 ) ;
V_181 += F_170 ( V_176 , V_177 , V_178 ) ;
F_59 ( V_2 , V_17 ) ;
V_193 -= V_178 ;
V_184 += V_178 ;
}
V_4 -> V_192 = V_181 ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_15 * V_17 , * V_151 ;
int V_104 ;
if ( V_2 -> V_149 ) {
for ( V_104 = 0 ; V_104 < V_2 -> V_87 ; V_104 ++ )
F_59 ( V_2 , V_2 -> V_149 [ V_104 ] ) ;
F_26 ( V_2 -> V_149 ) ;
V_2 -> V_149 = NULL ;
}
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
if ( V_2 -> V_48 [ V_104 ] . V_17 ) {
F_32 ( V_2 , V_2 -> V_48 [ V_104 ] . V_17 ) ;
V_2 -> V_48 [ V_104 ] . V_17 = NULL ;
}
}
while ( ! F_55 ( & V_2 -> V_72 ) ) {
V_17 = F_56 ( & V_2 -> V_72 ,
struct V_15 , V_22 ) ;
F_97 ( V_2 -> V_6 , L_27 ,
( T_2 ) V_17 -> V_25 , F_7 ( & V_17 -> V_28 ) ) ;
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
}
while ( ! F_55 ( & V_2 -> V_21 ) ) {
V_17 = F_56 ( & V_2 -> V_21 ,
struct V_15 , V_22 ) ;
F_21 ( & V_17 -> V_22 ) ;
F_22 ( & V_17 -> V_23 , & V_2 -> V_24 ) ;
F_32 ( V_2 , V_17 ) ;
}
V_32 = & V_2 -> V_24 ;
F_172 (mblk, next, root, node) {
F_97 ( V_2 -> V_6 , L_28 ,
( T_2 ) V_17 -> V_25 , F_7 ( & V_17 -> V_28 ) ) ;
F_29 ( & V_17 -> V_28 , 0 ) ;
F_32 ( V_2 , V_17 ) ;
}
F_105 ( V_2 ) ;
}
int F_173 ( struct V_98 * V_6 , struct V_1 * * V_197 )
{
struct V_1 * V_2 ;
unsigned int V_104 , V_198 ;
struct V_3 * V_4 ;
int V_75 ;
V_2 = F_174 ( sizeof( struct V_1 ) , V_137 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_24 = V_199 ;
F_175 ( & V_2 -> V_13 ) ;
F_176 ( & V_2 -> V_14 ) ;
F_177 ( & V_2 -> V_20 ) ;
F_28 ( & V_2 -> V_21 ) ;
F_28 ( & V_2 -> V_72 ) ;
F_176 ( & V_2 -> V_12 ) ;
F_29 ( & V_2 -> V_11 , 0 ) ;
F_28 ( & V_2 -> V_158 ) ;
F_28 ( & V_2 -> V_153 ) ;
F_29 ( & V_2 -> V_162 , 0 ) ;
F_28 ( & V_2 -> V_161 ) ;
F_28 ( & V_2 -> V_154 ) ;
F_29 ( & V_2 -> V_159 , 0 ) ;
F_28 ( & V_2 -> V_160 ) ;
F_178 ( & V_2 -> V_167 ) ;
V_75 = F_106 ( V_2 ) ;
if ( V_75 )
goto V_200;
V_75 = F_98 ( V_2 ) ;
if ( V_75 )
goto V_200;
V_198 = F_1 ( V_2 , V_2 -> V_107 ) ;
for ( V_104 = 0 ; V_104 < V_2 -> V_96 << 1 ; V_104 ++ ) {
V_4 = F_114 ( V_2 , V_198 + V_104 ) ;
if ( ! F_101 ( V_4 ) )
goto V_200;
F_41 ( V_201 , & V_4 -> V_120 ) ;
}
V_75 = F_119 ( V_2 ) ;
if ( V_75 )
goto V_200;
V_2 -> V_60 = 2 + V_2 -> V_87 + V_2 -> V_134 * 16 ;
V_2 -> V_18 = V_2 -> V_60 + 512 ;
V_2 -> V_65 . V_202 = F_57 ;
V_2 -> V_65 . V_203 = F_58 ;
V_2 -> V_65 . V_204 = V_205 ;
V_75 = F_179 ( & V_2 -> V_65 ) ;
if ( V_75 ) {
F_92 ( V_6 , L_29 ) ;
goto V_200;
}
F_108 ( V_6 , L_30 ,
F_180 ( V_6 -> V_52 ) == V_206 ?
L_31 : L_32 ) ;
F_108 ( V_6 , L_33 ,
( T_2 ) V_6 -> V_114 ) ;
F_108 ( V_6 , L_34 ,
V_6 -> V_136 , ( T_2 ) V_6 -> V_112 ) ;
F_108 ( V_6 , L_35 ,
V_2 -> V_96 * 2 ) ;
F_108 ( V_6 , L_36 ,
V_2 -> V_97 , V_2 -> V_9 ) ;
F_108 ( V_6 , L_37 ,
V_2 -> V_10 , F_7 ( & V_2 -> V_11 ) ) ;
F_108 ( V_6 , L_38 ,
V_2 -> V_157 , F_7 ( & V_2 -> V_162 ) ) ;
F_108 ( V_6 , L_39 ,
V_2 -> V_86 ) ;
F_99 ( V_6 , L_40 ) ;
F_99 ( V_6 , L_41 ,
V_2 -> V_85 , V_2 -> V_18 ) ;
F_99 ( V_6 , L_42 ,
V_2 -> V_87 ) ;
F_99 ( V_6 , L_43 ,
V_2 -> V_88 ) ;
* V_197 = V_2 ;
return 0 ;
V_200:
F_171 ( V_2 ) ;
F_26 ( V_2 ) ;
* V_197 = NULL ;
return V_75 ;
}
void F_181 ( struct V_1 * V_2 )
{
F_182 ( & V_2 -> V_65 ) ;
F_171 ( V_2 ) ;
F_26 ( V_2 ) ;
}
int F_183 ( struct V_1 * V_2 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
T_1 V_129 ;
unsigned int V_104 ;
int V_75 ;
for ( V_104 = 0 ; V_104 < V_6 -> V_136 ; V_104 ++ ) {
V_4 = F_114 ( V_2 , V_104 ) ;
if ( ! V_4 ) {
F_92 ( V_6 , L_44 , V_104 ) ;
return - V_71 ;
}
V_129 = V_4 -> V_129 ;
V_75 = F_110 ( V_2 , V_4 ) ;
if ( V_75 ) {
F_92 ( V_6 , L_45 , V_104 ) ;
return V_75 ;
}
if ( F_103 ( V_4 ) ) {
F_97 ( V_6 , L_22 , V_104 ) ;
continue;
}
if ( ! F_111 ( V_4 ) )
V_4 -> V_129 = 0 ;
else if ( V_4 -> V_129 != V_129 ) {
F_92 ( V_6 , L_46 ,
V_104 , ( T_2 ) V_4 -> V_129 , ( T_2 ) V_129 ) ;
V_4 -> V_129 = V_129 ;
F_113 ( V_2 , V_4 , V_4 -> V_129 ,
V_6 -> V_101 - V_4 -> V_129 ) ;
}
}
return 0 ;
}
