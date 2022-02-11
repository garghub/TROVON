static bool F_1 ( struct V_1 * V_2 )
{
return V_2 && ( V_2 -> V_3 & V_4 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return V_2 && F_1 ( V_2 ) && F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_5 )
{
F_5 ( & V_6 ) ;
if ( V_2 -> V_7 != V_5 ) {
V_2 -> V_7 = V_5 ;
F_6 ( & V_6 ) ;
F_7 ( V_2 ) ;
} else {
F_6 ( & V_6 ) ;
}
}
void F_8 ( struct V_1 * V_8 , struct V_1 * V_9 ,
struct V_1 * V_10 )
{
if ( ! F_1 ( V_8 ) ) {
F_4 ( V_8 , V_11 ) ;
return;
}
if ( F_2 ( V_9 ) || F_2 ( V_10 ) )
F_4 ( V_8 , V_12 ) ;
else
F_4 ( V_8 , V_13 ) ;
}
void F_9 ( struct V_1 * V_8 , struct V_1 * V_9 ,
struct V_1 * V_10 )
{
if ( F_2 ( V_9 ) || F_2 ( V_10 ) )
F_10 ( V_8 ) ;
else
F_11 ( V_8 ) ;
}
void F_12 ( struct V_1 * V_8 , int V_14 )
{
struct V_15 * V_15 ;
V_15 = F_13 ( V_8 ) ;
if ( ( V_8 -> V_7 == V_12 ) && ( V_14 != V_12 ) ) {
V_15 -> V_16 = 0 ;
V_15 -> V_17 . V_18 = V_19 +
F_14 ( V_20 ) ;
F_15 ( & V_15 -> V_17 ) ;
}
if ( ( V_8 -> V_7 != V_12 ) && ( V_14 == V_12 ) )
F_16 ( & V_15 -> V_17 ) ;
}
int F_17 ( struct V_15 * V_15 )
{
int V_21 ;
if ( V_15 -> V_22 [ 0 ] && V_15 -> V_22 [ 1 ] )
V_21 = F_18 ( V_15 -> V_22 [ 0 ] -> V_23 , V_15 -> V_22 [ 1 ] -> V_23 ) ;
else if ( V_15 -> V_22 [ 0 ] )
V_21 = V_15 -> V_22 [ 0 ] -> V_23 ;
else if ( V_15 -> V_22 [ 1 ] )
V_21 = V_15 -> V_22 [ 1 ] -> V_23 ;
else
V_21 = V_24 ;
return V_21 - V_24 ;
}
static int F_19 ( struct V_1 * V_2 , int V_25 )
{
struct V_15 * V_15 ;
V_15 = F_13 ( V_2 ) ;
if ( V_25 > F_17 ( V_15 ) ) {
F_20 ( V_15 -> V_2 , L_1 ,
V_24 ) ;
return - V_26 ;
}
V_2 -> V_23 = V_25 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_15 * V_15 ;
int V_27 ;
char * V_28 ;
V_15 = F_13 ( V_2 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_15 -> V_22 [ V_27 ] )
V_28 = V_15 -> V_22 [ V_27 ] -> V_30 ;
else
V_28 = L_2 ;
if ( ! F_2 ( V_15 -> V_22 [ V_27 ] ) )
F_22 ( V_2 , L_3 ,
'A' + V_27 , V_28 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_24 ( struct V_31 * V_31 , struct V_15 * V_15 )
{
unsigned long V_32 ;
F_25 ( & V_31 -> V_33 , 0x1 ) ;
F_26 ( & V_31 -> V_33 , 0 ) ;
F_27 ( & V_15 -> V_34 , V_32 ) ;
V_31 -> V_33 . V_35 = F_28 ( V_15 -> V_35 ) ;
V_15 -> V_35 ++ ;
F_29 ( & V_15 -> V_34 , V_32 ) ;
V_31 -> V_33 . V_36 = V_31 -> V_37 . V_38 ;
V_31 -> V_37 . V_38 = F_28 ( V_39 ) ;
}
static int F_30 ( struct V_40 * V_41 , struct V_15 * V_15 ,
enum V_42 V_43 )
{
struct V_31 * V_31 ;
V_31 = (struct V_31 * ) V_41 -> V_44 ;
V_41 -> V_2 = V_15 -> V_22 [ V_43 ] ;
F_31 ( V_15 , & V_31 -> V_37 , V_43 ) ;
memcpy ( V_31 -> V_37 . V_45 , V_41 -> V_2 -> V_46 , V_47 ) ;
return F_32 ( V_41 ) ;
}
static int F_33 ( struct V_40 * V_41 , struct V_1 * V_2 )
{
struct V_15 * V_15 ;
struct V_31 * V_31 ;
struct V_40 * V_48 ;
int V_49 , V_50 ;
V_15 = F_13 ( V_2 ) ;
V_31 = (struct V_31 * ) V_41 -> V_44 ;
if ( ( V_41 -> V_51 != F_28 ( V_39 ) ) ||
( V_31 -> V_37 . V_38 != F_28 ( V_39 ) ) ) {
F_24 ( V_31 , V_15 ) ;
V_41 -> V_51 = F_28 ( V_39 ) ;
}
V_48 = F_34 ( V_41 , V_52 ) ;
V_49 = V_53 ;
if ( F_35 ( V_15 -> V_22 [ V_54 ] ) )
V_49 = F_30 ( V_41 , V_15 , V_54 ) ;
V_50 = V_53 ;
if ( F_35 ( V_48 && V_15 -> V_22 [ V_55 ] ) )
V_50 = F_30 ( V_48 , V_15 , V_55 ) ;
if ( F_35 ( V_49 == V_56 || V_49 == V_57 ||
V_50 == V_56 || V_50 == V_57 ) ) {
V_15 -> V_2 -> V_58 . V_59 ++ ;
V_15 -> V_2 -> V_58 . V_60 += V_41 -> V_61 ;
} else {
V_15 -> V_2 -> V_58 . V_62 ++ ;
}
return V_63 ;
}
static int F_36 ( struct V_40 * V_41 , struct V_1 * V_2 ,
unsigned short type , const void * V_64 ,
const void * V_65 , unsigned int V_61 )
{
int V_66 ;
if ( F_37 ( V_41 ) < V_24 + V_67 )
return - V_68 ;
F_38 ( V_41 , V_24 ) ;
V_66 = F_39 ( V_41 , V_2 , type , V_64 , V_65 , V_61 + V_24 ) ;
if ( V_66 <= 0 )
return V_66 ;
F_40 ( V_41 ) ;
return V_66 + V_24 ;
}
static int F_41 ( int V_69 )
{
const int V_70 = V_71 - V_24 - V_67 ;
if ( V_69 >= V_70 )
return V_69 ;
return V_70 ;
}
static void F_42 ( struct V_1 * V_8 , T_1 type )
{
struct V_15 * V_15 ;
struct V_40 * V_41 ;
int V_72 , V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
unsigned long V_32 ;
V_72 = F_43 ( V_8 ) ;
V_73 = V_8 -> V_78 ;
V_41 = F_44 ( F_41 ( sizeof( struct V_76 ) ) + V_72 + V_73 ,
V_52 ) ;
if ( V_41 == NULL )
return;
V_15 = F_13 ( V_8 ) ;
F_45 ( V_41 , V_72 ) ;
V_41 -> V_2 = V_8 ;
V_41 -> V_51 = F_28 ( V_39 ) ;
V_41 -> V_79 = V_80 ;
if ( F_46 ( V_41 , V_41 -> V_2 , V_39 ,
V_15 -> V_81 ,
V_41 -> V_2 -> V_46 , V_41 -> V_61 ) < 0 )
goto V_82;
F_47 ( V_41 , sizeof( struct V_37 ) ) ;
V_75 = ( F_48 ( V_75 ) ) V_41 -> V_44 ;
F_49 ( V_75 , 0xf ) ;
F_50 ( V_75 , 0 ) ;
F_27 ( & V_15 -> V_34 , V_32 ) ;
V_75 -> V_35 = F_28 ( V_15 -> V_35 ) ;
V_15 -> V_35 ++ ;
F_29 ( & V_15 -> V_34 , V_32 ) ;
V_75 -> V_83 = type ;
V_75 -> V_84 = 12 ;
F_38 ( V_41 , sizeof( struct V_37 ) ) ;
V_77 = ( F_48 ( V_77 ) ) F_51 ( V_41 , sizeof( * V_77 ) ) ;
memcpy ( V_77 -> V_85 , V_8 -> V_46 , V_47 ) ;
F_32 ( V_41 ) ;
return;
V_82:
F_52 ( V_41 ) ;
}
static void F_53 ( unsigned long V_44 )
{
struct V_15 * V_15 ;
V_15 = (struct V_15 * ) V_44 ;
if ( V_15 -> V_16 < 3 ) {
F_42 ( V_15 -> V_2 , V_86 ) ;
V_15 -> V_16 ++ ;
} else {
F_42 ( V_15 -> V_2 , V_87 ) ;
}
if ( V_15 -> V_16 < 3 )
V_15 -> V_17 . V_18 = V_19 +
F_14 ( V_20 ) ;
else
V_15 -> V_17 . V_18 = V_19 +
F_14 ( V_88 ) ;
if ( F_1 ( V_15 -> V_2 ) )
F_15 ( & V_15 -> V_17 ) ;
}
static void F_54 ( struct V_1 * V_8 )
{
struct V_15 * V_15 ;
int V_27 ;
int V_66 ;
V_15 = F_13 ( V_8 ) ;
F_55 () ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ! V_15 -> V_22 [ V_27 ] )
continue;
V_66 = F_56 ( V_15 -> V_22 [ V_27 ] , - 1 ) ;
if ( V_66 )
F_20 ( V_8 ,
L_4 ,
V_15 -> V_22 [ V_27 ] -> V_30 , V_66 ) ;
}
F_57 () ;
}
static void F_58 ( struct V_89 * V_90 )
{
struct V_15 * V_15 ;
V_15 = F_59 ( V_90 , struct V_15 , V_89 ) ;
F_60 ( V_15 -> V_2 ) ;
}
static void F_61 ( struct V_1 * V_8 )
{
struct V_15 * V_15 ;
V_15 = F_13 ( V_8 ) ;
F_16 ( & V_15 -> V_17 ) ;
F_62 ( V_15 ) ;
F_54 ( V_8 ) ;
F_63 ( & V_15 -> V_89 , F_58 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_46 ) ;
F_66 ( V_2 ) ;
V_2 -> V_91 = & V_92 ;
V_2 -> V_93 = & V_94 ;
V_2 -> V_95 = 0 ;
V_2 -> V_96 = F_61 ;
}
bool F_67 ( struct V_1 * V_2 )
{
return ( V_2 -> V_93 -> V_97 == F_33 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 & V_98 ) || ( V_2 -> type != V_99 ) ||
( V_2 -> V_100 != V_47 ) ) {
F_20 ( V_2 , L_5 ) ;
return - V_26 ;
}
if ( F_67 ( V_2 ) ) {
F_20 ( V_2 , L_6 ) ;
return - V_26 ;
}
if ( F_69 ( V_2 ) ) {
F_20 ( V_2 , L_7 ) ;
return - V_26 ;
}
if ( V_2 -> V_101 & V_102 ) {
F_20 ( V_2 , L_8 ) ;
return - V_26 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_8 , struct V_1 * V_22 [ 2 ] ,
unsigned char V_103 )
{
struct V_15 * V_15 ;
int V_27 ;
int V_66 ;
V_15 = F_13 ( V_8 ) ;
V_15 -> V_2 = V_8 ;
F_71 ( & V_15 -> V_104 ) ;
F_71 ( & V_15 -> V_105 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ )
V_15 -> V_22 [ V_27 ] = V_22 [ V_27 ] ;
F_72 ( & V_15 -> V_34 ) ;
V_15 -> V_35 = V_106 - 1024 ;
F_73 ( & V_15 -> V_17 ) ;
V_15 -> V_17 . V_107 = F_53 ;
V_15 -> V_17 . V_44 = ( unsigned long ) V_15 ;
memcpy ( V_15 -> V_81 , V_108 , V_47 ) ;
V_15 -> V_81 [ V_47 - 1 ] = V_103 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_66 = F_68 ( V_22 [ V_27 ] ) ;
if ( V_66 )
return V_66 ;
}
V_8 -> V_109 = V_22 [ 0 ] -> V_109 & V_22 [ 1 ] -> V_109 ;
V_8 -> V_109 |= V_110 ;
V_8 -> V_109 |= V_111 ;
memcpy ( V_8 -> V_46 , V_15 -> V_22 [ 0 ] -> V_46 , V_47 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_22 [ V_27 ] -> V_112 + V_24 >
V_8 -> V_112 )
V_8 -> V_112 =
V_22 [ V_27 ] -> V_112 + V_24 ;
}
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ )
if ( V_22 [ V_27 ] -> V_23 - V_24 < V_8 -> V_23 )
V_8 -> V_23 = V_22 [ V_27 ] -> V_23 - V_24 ;
F_11 ( V_8 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_66 = F_56 ( V_22 [ V_27 ] , 1 ) ;
if ( V_66 ) {
F_20 ( V_8 , L_9 ,
V_22 [ V_27 ] -> V_30 , V_66 ) ;
goto V_113;
}
}
V_66 = F_74 ( & V_15 -> V_105 ,
V_8 -> V_46 ,
V_15 -> V_22 [ 1 ] -> V_46 ) ;
if ( V_66 < 0 )
goto V_113;
V_66 = F_75 ( V_8 ) ;
if ( V_66 )
goto V_113;
F_76 ( V_15 ) ;
return 0 ;
V_113:
F_54 ( V_8 ) ;
return V_66 ;
}
