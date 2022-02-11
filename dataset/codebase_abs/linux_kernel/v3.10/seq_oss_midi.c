int T_1
F_1 ( int V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_6 ) ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_3 || ! V_5 ) {
F_3 ( V_3 ) ;
F_3 ( V_5 ) ;
return - V_7 ;
}
V_3 -> V_1 = - 1 ;
while ( F_4 ( V_1 , V_8 , V_3 ) == 0 ) {
if ( V_3 -> V_1 == V_1 )
continue;
V_5 -> V_9 . V_1 = V_3 -> V_1 ;
V_5 -> V_9 . V_10 = - 1 ;
while ( F_4 ( V_1 , V_11 , V_5 ) == 0 )
F_5 ( V_5 ) ;
}
F_3 ( V_3 ) ;
F_3 ( V_5 ) ;
return 0 ;
}
static struct V_12 *
F_6 ( int V_13 )
{
struct V_12 * V_14 ;
unsigned long V_15 ;
F_7 ( & V_16 , V_15 ) ;
V_14 = V_17 [ V_13 ] ;
if ( V_14 )
F_8 ( & V_14 -> V_18 ) ;
F_9 ( & V_16 , V_15 ) ;
return V_14 ;
}
static struct V_12 *
F_10 ( int V_1 , int V_10 )
{
int V_19 ;
struct V_12 * V_14 ;
unsigned long V_15 ;
F_7 ( & V_16 , V_15 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_14 = V_17 [ V_19 ] ;
if ( V_14 && V_14 -> V_1 == V_1 && V_14 -> V_10 == V_10 ) {
F_8 ( & V_14 -> V_18 ) ;
F_9 ( & V_16 , V_15 ) ;
return V_14 ;
}
}
F_9 ( & V_16 , V_15 ) ;
return NULL ;
}
int
F_5 ( struct V_4 * V_5 )
{
int V_19 ;
struct V_12 * V_14 ;
unsigned long V_15 ;
F_11 ( ( L_1 , V_5 -> V_9 . V_1 , V_5 -> V_9 . V_10 ) ) ;
if ( ! ( V_5 -> type & V_21 ) )
return 0 ;
if ( ( V_5 -> V_22 & V_23 ) != V_23 &&
( V_5 -> V_22 & V_24 ) != V_24 )
return 0 ;
if ( ( V_14 = F_10 ( V_5 -> V_9 . V_1 , V_5 -> V_9 . V_10 ) ) != NULL ) {
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
if ( ( V_14 = F_2 ( sizeof( * V_14 ) , V_6 ) ) == NULL ) {
F_13 ( V_25 L_2 ) ;
return - V_7 ;
}
V_14 -> V_1 = V_5 -> V_9 . V_1 ;
V_14 -> V_10 = V_5 -> V_9 . V_10 ;
V_14 -> V_15 = V_5 -> V_22 ;
V_14 -> V_26 = 0 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 ( V_14 -> V_27 , V_5 -> V_27 , sizeof( V_14 -> V_27 ) ) ;
if ( F_16 ( V_28 , & V_14 -> V_29 ) < 0 ) {
F_13 ( V_25 L_3 ) ;
F_3 ( V_14 ) ;
return - V_7 ;
}
F_17 ( V_14 -> V_29 , 1 ) ;
F_7 ( & V_16 , V_15 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( V_17 [ V_19 ] == NULL )
break;
}
if ( V_19 >= V_20 ) {
if ( V_20 >= V_30 ) {
F_9 ( & V_16 , V_15 ) ;
F_18 ( V_14 -> V_29 ) ;
F_3 ( V_14 ) ;
return - V_7 ;
}
V_20 ++ ;
}
V_14 -> V_31 = V_19 ;
V_17 [ V_14 -> V_31 ] = V_14 ;
F_9 ( & V_16 , V_15 ) ;
return 0 ;
}
int
F_19 ( int V_1 , int V_10 )
{
struct V_12 * V_14 ;
unsigned long V_15 ;
int V_32 ;
if ( ( V_14 = F_10 ( V_1 , V_10 ) ) != NULL ) {
F_7 ( & V_16 , V_15 ) ;
V_17 [ V_14 -> V_31 ] = NULL ;
F_9 ( & V_16 , V_15 ) ;
F_12 ( & V_14 -> V_18 ) ;
F_20 ( & V_14 -> V_18 ) ;
if ( V_14 -> V_29 )
F_18 ( V_14 -> V_29 ) ;
F_3 ( V_14 ) ;
}
F_7 ( & V_16 , V_15 ) ;
for ( V_32 = V_20 - 1 ; V_32 >= 0 ; V_32 -- ) {
if ( V_17 [ V_32 ] )
break;
}
V_20 = V_32 + 1 ;
F_9 ( & V_16 , V_15 ) ;
return 0 ;
}
void
F_21 ( void )
{
int V_19 ;
struct V_12 * V_14 ;
unsigned long V_15 ;
F_7 ( & V_16 , V_15 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( ( V_14 = V_17 [ V_19 ] ) != NULL ) {
if ( V_14 -> V_29 )
F_18 ( V_14 -> V_29 ) ;
F_3 ( V_14 ) ;
V_17 [ V_19 ] = NULL ;
}
}
V_20 = 0 ;
F_9 ( & V_16 , V_15 ) ;
}
void
F_22 ( struct V_33 * V_34 )
{
V_34 -> V_35 = V_20 ;
}
void
F_23 ( struct V_33 * V_34 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_34 -> V_35 ; V_19 ++ )
F_24 ( V_34 , V_19 ) ;
V_34 -> V_35 = 0 ;
}
void
F_25 ( struct V_33 * V_34 , int V_36 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_34 -> V_35 ; V_19 ++ )
F_26 ( V_34 , V_19 , V_36 ) ;
}
static struct V_12 *
F_27 ( struct V_33 * V_34 , int V_13 )
{
if ( V_13 < 0 || V_13 >= V_34 -> V_35 )
return NULL ;
return F_6 ( V_13 ) ;
}
int
F_26 ( struct V_33 * V_34 , int V_13 , int V_37 )
{
int V_38 ;
struct V_12 * V_14 ;
struct V_39 V_40 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return - V_41 ;
if ( V_14 -> V_26 && V_14 -> V_42 != V_34 ) {
F_12 ( & V_14 -> V_18 ) ;
return - V_43 ;
}
V_38 = 0 ;
if ( F_28 ( V_37 ) )
V_38 |= V_23 ;
if ( F_29 ( V_37 ) )
V_38 |= V_24 ;
V_38 &= V_14 -> V_15 ;
if ( V_38 == 0 ) {
F_12 ( & V_14 -> V_18 ) ;
return - V_44 ;
}
if ( ( V_14 -> V_26 & V_38 ) == V_38 ) {
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
V_38 &= ~ V_14 -> V_26 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_38 & V_23 ) {
V_40 . V_45 = V_34 -> V_9 ;
V_40 . V_46 . V_1 = V_14 -> V_1 ;
V_40 . V_46 . V_10 = V_14 -> V_10 ;
if ( F_4 ( V_34 -> V_47 , V_48 , & V_40 ) >= 0 )
V_14 -> V_26 |= V_23 ;
}
if ( V_38 & V_24 ) {
V_40 . V_45 . V_1 = V_14 -> V_1 ;
V_40 . V_45 . V_10 = V_14 -> V_10 ;
V_40 . V_46 = V_34 -> V_9 ;
V_40 . V_15 = V_49 ;
V_40 . V_50 = V_34 -> V_50 ;
if ( F_4 ( V_34 -> V_47 , V_48 , & V_40 ) >= 0 )
V_14 -> V_26 |= V_24 ;
}
if ( ! V_14 -> V_26 ) {
F_12 ( & V_14 -> V_18 ) ;
return - V_44 ;
}
V_14 -> V_42 = V_34 ;
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
int
F_24 ( struct V_33 * V_34 , int V_13 )
{
struct V_12 * V_14 ;
struct V_39 V_40 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return - V_41 ;
if ( ! V_14 -> V_26 || V_14 -> V_42 != V_34 ) {
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
F_11 ( ( L_4 , V_14 -> V_1 , V_14 -> V_10 , V_14 -> V_26 ) ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_14 -> V_26 & V_23 ) {
V_40 . V_45 = V_34 -> V_9 ;
V_40 . V_46 . V_1 = V_14 -> V_1 ;
V_40 . V_46 . V_10 = V_14 -> V_10 ;
F_4 ( V_34 -> V_47 , V_51 , & V_40 ) ;
}
if ( V_14 -> V_26 & V_24 ) {
V_40 . V_45 . V_1 = V_14 -> V_1 ;
V_40 . V_45 . V_10 = V_14 -> V_10 ;
V_40 . V_46 = V_34 -> V_9 ;
F_4 ( V_34 -> V_47 , V_51 , & V_40 ) ;
}
V_14 -> V_26 = 0 ;
V_14 -> V_42 = NULL ;
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
int
F_30 ( struct V_33 * V_34 , int V_13 )
{
struct V_12 * V_14 ;
int V_52 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return 0 ;
V_52 = 0 ;
if ( V_14 -> V_26 & V_23 )
V_52 |= V_53 ;
if ( V_14 -> V_26 & V_24 )
V_52 |= V_54 ;
F_12 ( & V_14 -> V_18 ) ;
return V_52 ;
}
void
F_31 ( struct V_33 * V_34 , int V_13 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return;
if ( ! V_14 -> V_26 ) {
F_12 ( & V_14 -> V_18 ) ;
return;
}
if ( V_14 -> V_26 & V_23 ) {
struct V_55 V_56 ;
int V_57 ;
F_11 ( ( L_5 , V_14 -> V_1 , V_14 -> V_10 ) ) ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_46 . V_1 = V_14 -> V_1 ;
V_56 . V_46 . V_10 = V_14 -> V_10 ;
V_56 . V_50 = V_34 -> V_50 ;
V_56 . V_58 . V_10 = V_34 -> V_10 ;
if ( V_34 -> V_59 == V_60 ) {
V_56 . type = V_61 ;
F_32 ( V_34 , & V_56 , 0 , 0 ) ;
}
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ ) {
V_56 . type = V_62 ;
V_56 . V_63 . V_64 . V_65 = V_57 ;
V_56 . V_63 . V_64 . V_66 = V_67 ;
F_32 ( V_34 , & V_56 , 0 , 0 ) ;
if ( V_34 -> V_59 == V_68 ) {
V_56 . V_63 . V_64 . V_66 =
V_69 ;
F_32 ( V_34 , & V_56 , 0 , 0 ) ;
V_56 . type = V_70 ;
V_56 . V_63 . V_64 . V_71 = 0 ;
F_32 ( V_34 , & V_56 , 0 , 0 ) ;
}
}
}
F_12 ( & V_14 -> V_18 ) ;
}
void
F_33 ( struct V_33 * V_34 , int V_13 , struct V_72 * V_9 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return;
V_9 -> V_1 = V_14 -> V_1 ;
V_9 -> V_10 = V_14 -> V_10 ;
F_12 ( & V_14 -> V_18 ) ;
}
int
F_34 ( struct V_55 * V_56 , int V_73 , void * V_74 )
{
struct V_33 * V_34 = (struct V_33 * ) V_74 ;
struct V_12 * V_14 ;
int V_75 ;
if ( V_34 -> V_76 == NULL )
return 0 ;
if ( ( V_14 = F_10 ( V_56 -> V_58 . V_1 , V_56 -> V_58 . V_10 ) ) == NULL )
return 0 ;
if ( ! ( V_14 -> V_26 & V_24 ) ) {
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
if ( V_34 -> V_59 == V_68 )
V_75 = F_35 ( V_34 , V_56 , V_14 -> V_31 ) ;
else
V_75 = F_36 ( V_34 , V_56 , V_14 ) ;
F_12 ( & V_14 -> V_18 ) ;
return V_75 ;
}
static int
F_35 ( struct V_33 * V_34 , struct V_55 * V_56 , int V_13 )
{
union V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
switch ( V_56 -> type ) {
case V_79 :
V_78 . V_80 . V_81 = V_82 ; break;
case V_83 :
V_78 . V_80 . V_81 = V_84 ; break;
case V_85 :
V_78 . V_80 . V_81 = V_86 ; break;
case V_62 :
V_78 . V_87 . V_81 = V_88 ; break;
case V_89 :
V_78 . V_87 . V_81 = V_90 ; break;
case V_91 :
V_78 . V_87 . V_81 = V_92 ; break;
case V_70 :
V_78 . V_87 . V_81 = V_93 ; break;
default:
return 0 ;
}
V_78 . V_80 . V_13 = V_13 ;
switch ( V_56 -> type ) {
case V_79 :
case V_83 :
case V_85 :
V_78 . V_80 . V_94 = V_95 ;
V_78 . V_80 . V_96 = V_56 -> V_63 . V_96 . V_96 ;
V_78 . V_80 . V_97 = V_56 -> V_63 . V_96 . V_98 ;
V_78 . V_80 . V_99 = V_56 -> V_63 . V_96 . V_65 ;
break;
case V_62 :
case V_89 :
case V_91 :
V_78 . V_87 . V_94 = V_100 ;
V_78 . V_87 . V_101 = V_56 -> V_63 . V_64 . V_66 ;
V_78 . V_87 . V_102 = V_56 -> V_63 . V_64 . V_71 ;
V_78 . V_87 . V_99 = V_56 -> V_63 . V_64 . V_65 ;
break;
case V_70 :
V_78 . V_87 . V_94 = V_100 ;
V_78 . V_87 . V_102 = V_56 -> V_63 . V_64 . V_71 + 8192 ;
V_78 . V_87 . V_99 = V_56 -> V_63 . V_64 . V_65 ;
break;
}
F_37 ( V_34 -> V_76 , V_56 -> time . V_103 , V_34 -> V_59 ) ;
F_38 ( V_34 -> V_76 , & V_78 ) ;
return 0 ;
}
static int
F_36 ( struct V_33 * V_34 , struct V_55 * V_56 , struct V_12 * V_14 )
{
char V_104 [ 32 ] ;
int V_105 ;
F_37 ( V_34 -> V_76 , V_56 -> time . V_103 , V_34 -> V_59 ) ;
if ( ! V_34 -> V_106 -> V_107 )
V_105 = F_39 ( V_34 -> V_106 ) ;
if ( V_56 -> type == V_108 ) {
if ( ( V_56 -> V_15 & V_109 ) == V_110 )
F_40 ( V_34 -> V_76 , V_14 -> V_31 ,
V_56 -> V_63 . V_111 . V_112 , V_56 -> V_63 . V_111 . V_105 ) ;
} else {
V_105 = F_41 ( V_14 -> V_29 , V_104 , sizeof( V_104 ) , V_56 ) ;
if ( V_105 > 0 )
F_40 ( V_34 -> V_76 , V_14 -> V_31 , V_104 , V_105 ) ;
}
return 0 ;
}
int
F_42 ( struct V_33 * V_34 , int V_13 , unsigned char V_57 , struct V_55 * V_56 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return - V_41 ;
if ( F_43 ( V_14 -> V_29 , V_57 , V_56 ) > 0 ) {
F_44 ( V_34 , V_56 , V_14 -> V_1 , V_14 -> V_10 ) ;
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
F_12 ( & V_14 -> V_18 ) ;
return - V_113 ;
}
int
F_45 ( struct V_33 * V_34 , int V_13 , struct V_114 * V_115 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_27 ( V_34 , V_13 ) ) == NULL )
return - V_44 ;
V_115 -> V_116 = V_13 ;
V_115 -> V_117 = 0 ;
V_115 -> V_118 = 0 ;
F_15 ( V_115 -> V_27 , V_14 -> V_27 , sizeof( V_115 -> V_27 ) ) ;
F_12 ( & V_14 -> V_18 ) ;
return 0 ;
}
static char *
F_46 ( int V_102 )
{
V_102 &= V_24 | V_23 ;
if ( V_102 == ( V_24 | V_23 ) )
return L_6 ;
else if ( V_102 == V_24 )
return L_7 ;
else if ( V_102 == V_23 )
return L_8 ;
else
return L_9 ;
}
void
F_47 ( struct V_119 * V_120 )
{
int V_19 ;
struct V_12 * V_14 ;
F_48 ( V_120 , L_10 , V_20 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
F_48 ( V_120 , L_11 , V_19 ) ;
V_14 = F_6 ( V_19 ) ;
if ( V_14 == NULL ) {
F_48 ( V_120 , L_12 ) ;
continue;
}
F_48 ( V_120 , L_13 , V_14 -> V_27 ,
V_14 -> V_1 , V_14 -> V_10 ) ;
F_48 ( V_120 , L_14 ,
F_46 ( V_14 -> V_15 ) ,
F_46 ( V_14 -> V_26 ) ) ;
F_12 ( & V_14 -> V_18 ) ;
}
}
