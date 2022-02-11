int
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
if ( ! ( V_5 -> type & V_21 ) )
return 0 ;
if ( ( V_5 -> V_22 & V_23 ) != V_23 &&
( V_5 -> V_22 & V_24 ) != V_24 )
return 0 ;
if ( ( V_14 = F_10 ( V_5 -> V_9 . V_1 , V_5 -> V_9 . V_10 ) ) != NULL ) {
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
V_14 = F_2 ( sizeof( * V_14 ) , V_6 ) ;
if ( ! V_14 )
return - V_7 ;
V_14 -> V_1 = V_5 -> V_9 . V_1 ;
V_14 -> V_10 = V_5 -> V_9 . V_10 ;
V_14 -> V_15 = V_5 -> V_22 ;
V_14 -> V_25 = 0 ;
F_12 ( & V_14 -> V_18 ) ;
F_13 ( V_14 -> V_26 , V_5 -> V_26 , sizeof( V_14 -> V_26 ) ) ;
if ( F_14 ( V_27 , & V_14 -> V_28 ) < 0 ) {
F_15 ( L_1 ) ;
F_3 ( V_14 ) ;
return - V_7 ;
}
F_16 ( V_14 -> V_28 , 1 ) ;
F_7 ( & V_16 , V_15 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( V_17 [ V_19 ] == NULL )
break;
}
if ( V_19 >= V_20 ) {
if ( V_20 >= V_29 ) {
F_9 ( & V_16 , V_15 ) ;
F_17 ( V_14 -> V_28 ) ;
F_3 ( V_14 ) ;
return - V_7 ;
}
V_20 ++ ;
}
V_14 -> V_30 = V_19 ;
V_17 [ V_14 -> V_30 ] = V_14 ;
F_9 ( & V_16 , V_15 ) ;
return 0 ;
}
int
F_18 ( int V_1 , int V_10 )
{
struct V_12 * V_14 ;
unsigned long V_15 ;
int V_31 ;
if ( ( V_14 = F_10 ( V_1 , V_10 ) ) != NULL ) {
F_7 ( & V_16 , V_15 ) ;
V_17 [ V_14 -> V_30 ] = NULL ;
F_9 ( & V_16 , V_15 ) ;
F_11 ( & V_14 -> V_18 ) ;
F_19 ( & V_14 -> V_18 ) ;
F_17 ( V_14 -> V_28 ) ;
F_3 ( V_14 ) ;
}
F_7 ( & V_16 , V_15 ) ;
for ( V_31 = V_20 - 1 ; V_31 >= 0 ; V_31 -- ) {
if ( V_17 [ V_31 ] )
break;
}
V_20 = V_31 + 1 ;
F_9 ( & V_16 , V_15 ) ;
return 0 ;
}
void
F_20 ( void )
{
int V_19 ;
struct V_12 * V_14 ;
unsigned long V_15 ;
F_7 ( & V_16 , V_15 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( ( V_14 = V_17 [ V_19 ] ) != NULL ) {
F_17 ( V_14 -> V_28 ) ;
F_3 ( V_14 ) ;
V_17 [ V_19 ] = NULL ;
}
}
V_20 = 0 ;
F_9 ( & V_16 , V_15 ) ;
}
void
F_21 ( struct V_32 * V_33 )
{
V_33 -> V_34 = V_20 ;
}
void
F_22 ( struct V_32 * V_33 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_33 -> V_34 ; V_19 ++ )
F_23 ( V_33 , V_19 ) ;
V_33 -> V_34 = 0 ;
}
void
F_24 ( struct V_32 * V_33 , int V_35 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_33 -> V_34 ; V_19 ++ )
F_25 ( V_33 , V_19 , V_35 ) ;
}
static struct V_12 *
F_26 ( struct V_32 * V_33 , int V_13 )
{
if ( V_13 < 0 || V_13 >= V_33 -> V_34 )
return NULL ;
return F_6 ( V_13 ) ;
}
int
F_25 ( struct V_32 * V_33 , int V_13 , int V_36 )
{
int V_37 ;
struct V_12 * V_14 ;
struct V_38 V_39 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return - V_40 ;
if ( V_14 -> V_25 && V_14 -> V_41 != V_33 ) {
F_11 ( & V_14 -> V_18 ) ;
return - V_42 ;
}
V_37 = 0 ;
if ( F_27 ( V_36 ) )
V_37 |= V_23 ;
if ( F_28 ( V_36 ) )
V_37 |= V_24 ;
V_37 &= V_14 -> V_15 ;
if ( V_37 == 0 ) {
F_11 ( & V_14 -> V_18 ) ;
return - V_43 ;
}
if ( ( V_14 -> V_25 & V_37 ) == V_37 ) {
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
V_37 &= ~ V_14 -> V_25 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_37 & V_23 ) {
V_39 . V_44 = V_33 -> V_9 ;
V_39 . V_45 . V_1 = V_14 -> V_1 ;
V_39 . V_45 . V_10 = V_14 -> V_10 ;
if ( F_4 ( V_33 -> V_46 , V_47 , & V_39 ) >= 0 )
V_14 -> V_25 |= V_23 ;
}
if ( V_37 & V_24 ) {
V_39 . V_44 . V_1 = V_14 -> V_1 ;
V_39 . V_44 . V_10 = V_14 -> V_10 ;
V_39 . V_45 = V_33 -> V_9 ;
V_39 . V_15 = V_48 ;
V_39 . V_49 = V_33 -> V_49 ;
if ( F_4 ( V_33 -> V_46 , V_47 , & V_39 ) >= 0 )
V_14 -> V_25 |= V_24 ;
}
if ( ! V_14 -> V_25 ) {
F_11 ( & V_14 -> V_18 ) ;
return - V_43 ;
}
V_14 -> V_41 = V_33 ;
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
int
F_23 ( struct V_32 * V_33 , int V_13 )
{
struct V_12 * V_14 ;
struct V_38 V_39 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return - V_40 ;
if ( ! V_14 -> V_25 || V_14 -> V_41 != V_33 ) {
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_14 -> V_25 & V_23 ) {
V_39 . V_44 = V_33 -> V_9 ;
V_39 . V_45 . V_1 = V_14 -> V_1 ;
V_39 . V_45 . V_10 = V_14 -> V_10 ;
F_4 ( V_33 -> V_46 , V_50 , & V_39 ) ;
}
if ( V_14 -> V_25 & V_24 ) {
V_39 . V_44 . V_1 = V_14 -> V_1 ;
V_39 . V_44 . V_10 = V_14 -> V_10 ;
V_39 . V_45 = V_33 -> V_9 ;
F_4 ( V_33 -> V_46 , V_50 , & V_39 ) ;
}
V_14 -> V_25 = 0 ;
V_14 -> V_41 = NULL ;
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
int
F_29 ( struct V_32 * V_33 , int V_13 )
{
struct V_12 * V_14 ;
int V_51 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return 0 ;
V_51 = 0 ;
if ( V_14 -> V_25 & V_23 )
V_51 |= V_52 ;
if ( V_14 -> V_25 & V_24 )
V_51 |= V_53 ;
F_11 ( & V_14 -> V_18 ) ;
return V_51 ;
}
void
F_30 ( struct V_32 * V_33 , int V_13 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return;
if ( ! V_14 -> V_25 ) {
F_11 ( & V_14 -> V_18 ) ;
return;
}
if ( V_14 -> V_25 & V_23 ) {
struct V_54 V_55 ;
int V_56 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_45 . V_1 = V_14 -> V_1 ;
V_55 . V_45 . V_10 = V_14 -> V_10 ;
V_55 . V_49 = V_33 -> V_49 ;
V_55 . V_57 . V_10 = V_33 -> V_10 ;
if ( V_33 -> V_58 == V_59 ) {
V_55 . type = V_60 ;
F_31 ( V_33 , & V_55 , 0 , 0 ) ;
}
for ( V_56 = 0 ; V_56 < 16 ; V_56 ++ ) {
V_55 . type = V_61 ;
V_55 . V_62 . V_63 . V_64 = V_56 ;
V_55 . V_62 . V_63 . V_65 = V_66 ;
F_31 ( V_33 , & V_55 , 0 , 0 ) ;
if ( V_33 -> V_58 == V_67 ) {
V_55 . V_62 . V_63 . V_65 =
V_68 ;
F_31 ( V_33 , & V_55 , 0 , 0 ) ;
V_55 . type = V_69 ;
V_55 . V_62 . V_63 . V_70 = 0 ;
F_31 ( V_33 , & V_55 , 0 , 0 ) ;
}
}
}
F_11 ( & V_14 -> V_18 ) ;
}
void
F_32 ( struct V_32 * V_33 , int V_13 , struct V_71 * V_9 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return;
V_9 -> V_1 = V_14 -> V_1 ;
V_9 -> V_10 = V_14 -> V_10 ;
F_11 ( & V_14 -> V_18 ) ;
}
int
F_33 ( struct V_54 * V_55 , int V_72 , void * V_73 )
{
struct V_32 * V_33 = (struct V_32 * ) V_73 ;
struct V_12 * V_14 ;
int V_74 ;
if ( V_33 -> V_75 == NULL )
return 0 ;
if ( ( V_14 = F_10 ( V_55 -> V_57 . V_1 , V_55 -> V_57 . V_10 ) ) == NULL )
return 0 ;
if ( ! ( V_14 -> V_25 & V_24 ) ) {
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
if ( V_33 -> V_58 == V_67 )
V_74 = F_34 ( V_33 , V_55 , V_14 -> V_30 ) ;
else
V_74 = F_35 ( V_33 , V_55 , V_14 ) ;
F_11 ( & V_14 -> V_18 ) ;
return V_74 ;
}
static int
F_34 ( struct V_32 * V_33 , struct V_54 * V_55 , int V_13 )
{
union V_76 V_77 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
switch ( V_55 -> type ) {
case V_78 :
V_77 . V_79 . V_80 = V_81 ; break;
case V_82 :
V_77 . V_79 . V_80 = V_83 ; break;
case V_84 :
V_77 . V_79 . V_80 = V_85 ; break;
case V_61 :
V_77 . V_86 . V_80 = V_87 ; break;
case V_88 :
V_77 . V_86 . V_80 = V_89 ; break;
case V_90 :
V_77 . V_86 . V_80 = V_91 ; break;
case V_69 :
V_77 . V_86 . V_80 = V_92 ; break;
default:
return 0 ;
}
V_77 . V_79 . V_13 = V_13 ;
switch ( V_55 -> type ) {
case V_78 :
case V_82 :
case V_84 :
V_77 . V_79 . V_93 = V_94 ;
V_77 . V_79 . V_95 = V_55 -> V_62 . V_95 . V_95 ;
V_77 . V_79 . V_96 = V_55 -> V_62 . V_95 . V_97 ;
V_77 . V_79 . V_98 = V_55 -> V_62 . V_95 . V_64 ;
break;
case V_61 :
case V_88 :
case V_90 :
V_77 . V_86 . V_93 = V_99 ;
V_77 . V_86 . V_100 = V_55 -> V_62 . V_63 . V_65 ;
V_77 . V_86 . V_101 = V_55 -> V_62 . V_63 . V_70 ;
V_77 . V_86 . V_98 = V_55 -> V_62 . V_63 . V_64 ;
break;
case V_69 :
V_77 . V_86 . V_93 = V_99 ;
V_77 . V_86 . V_101 = V_55 -> V_62 . V_63 . V_70 + 8192 ;
V_77 . V_86 . V_98 = V_55 -> V_62 . V_63 . V_64 ;
break;
}
F_36 ( V_33 -> V_75 , V_55 -> time . V_102 , V_33 -> V_58 ) ;
F_37 ( V_33 -> V_75 , & V_77 ) ;
return 0 ;
}
static int
F_35 ( struct V_32 * V_33 , struct V_54 * V_55 , struct V_12 * V_14 )
{
char V_103 [ 32 ] ;
int V_104 ;
F_36 ( V_33 -> V_75 , V_55 -> time . V_102 , V_33 -> V_58 ) ;
if ( ! V_33 -> V_105 -> V_106 )
V_104 = F_38 ( V_33 -> V_105 ) ;
if ( V_55 -> type == V_107 ) {
F_39 ( V_33 -> V_75 , V_14 -> V_30 , V_55 ) ;
} else {
V_104 = F_40 ( V_14 -> V_28 , V_103 , sizeof( V_103 ) , V_55 ) ;
if ( V_104 > 0 )
F_41 ( V_33 -> V_75 , V_14 -> V_30 , V_103 , V_104 ) ;
}
return 0 ;
}
int
F_42 ( struct V_32 * V_33 , int V_13 , unsigned char V_56 , struct V_54 * V_55 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return - V_40 ;
if ( F_43 ( V_14 -> V_28 , V_56 , V_55 ) > 0 ) {
F_44 ( V_33 , V_55 , V_14 -> V_1 , V_14 -> V_10 ) ;
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
F_11 ( & V_14 -> V_18 ) ;
return - V_108 ;
}
int
F_45 ( struct V_32 * V_33 , int V_13 , struct V_109 * V_110 )
{
struct V_12 * V_14 ;
if ( ( V_14 = F_26 ( V_33 , V_13 ) ) == NULL )
return - V_43 ;
V_110 -> V_111 = V_13 ;
V_110 -> V_112 = 0 ;
V_110 -> V_113 = 0 ;
F_13 ( V_110 -> V_26 , V_14 -> V_26 , sizeof( V_110 -> V_26 ) ) ;
F_11 ( & V_14 -> V_18 ) ;
return 0 ;
}
static char *
F_46 ( int V_101 )
{
V_101 &= V_24 | V_23 ;
if ( V_101 == ( V_24 | V_23 ) )
return L_2 ;
else if ( V_101 == V_24 )
return L_3 ;
else if ( V_101 == V_23 )
return L_4 ;
else
return L_5 ;
}
void
F_47 ( struct V_114 * V_115 )
{
int V_19 ;
struct V_12 * V_14 ;
F_48 ( V_115 , L_6 , V_20 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
F_48 ( V_115 , L_7 , V_19 ) ;
V_14 = F_6 ( V_19 ) ;
if ( V_14 == NULL ) {
F_48 ( V_115 , L_8 ) ;
continue;
}
F_48 ( V_115 , L_9 , V_14 -> V_26 ,
V_14 -> V_1 , V_14 -> V_10 ) ;
F_48 ( V_115 , L_10 ,
F_46 ( V_14 -> V_15 ) ,
F_46 ( V_14 -> V_25 ) ) ;
F_11 ( & V_14 -> V_18 ) ;
}
}
