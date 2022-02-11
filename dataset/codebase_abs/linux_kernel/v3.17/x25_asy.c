static struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = NULL ;
struct V_1 * V_4 ;
int V_5 ;
if ( V_6 == NULL )
return NULL ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_3 = V_6 [ V_5 ] ;
if ( V_3 == NULL )
break;
V_4 = F_2 ( V_3 ) ;
if ( ! F_3 ( V_8 , & V_4 -> V_9 ) )
return V_4 ;
}
if ( V_5 >= V_7 )
return NULL ;
if ( ! V_3 ) {
char V_10 [ V_11 ] ;
sprintf ( V_10 , L_1 , V_5 ) ;
V_3 = F_4 ( sizeof( struct V_1 ) , V_10 ,
V_12 , V_13 ) ;
if ( ! V_3 )
return NULL ;
V_4 = F_2 ( V_3 ) ;
V_3 -> V_14 = V_5 ;
if ( F_5 ( V_3 ) == 0 ) {
F_6 ( V_8 , & V_4 -> V_9 ) ;
V_6 [ V_5 ] = V_3 ;
return V_4 ;
} else {
F_7 ( L_2 , V_15 ) ;
F_8 ( V_3 ) ;
}
}
return NULL ;
}
static void F_9 ( struct V_1 * V_4 )
{
F_10 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
F_10 ( V_4 -> V_17 ) ;
V_4 -> V_17 = NULL ;
if ( ! F_11 ( V_8 , & V_4 -> V_9 ) )
F_12 ( V_4 -> V_3 , L_3 ) ;
}
static int F_13 ( struct V_2 * V_3 , int V_18 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned char * V_17 , * V_16 ;
int V_19 ;
if ( V_18 > 65534 )
return - V_20 ;
V_19 = 2 * V_18 ;
V_17 = F_14 ( V_19 + 4 , V_21 ) ;
V_16 = F_14 ( V_19 + 4 , V_21 ) ;
if ( V_17 == NULL || V_16 == NULL ) {
F_10 ( V_17 ) ;
F_10 ( V_16 ) ;
return - V_22 ;
}
F_15 ( & V_4 -> V_23 ) ;
V_17 = F_16 ( & V_4 -> V_17 , V_17 ) ;
if ( V_4 -> V_24 ) {
if ( V_4 -> V_24 <= V_19 ) {
memcpy ( V_4 -> V_17 , V_4 -> V_25 , V_4 -> V_24 ) ;
} else {
V_4 -> V_24 = 0 ;
V_3 -> V_26 . V_27 ++ ;
}
}
V_4 -> V_25 = V_4 -> V_17 ;
V_16 = F_16 ( & V_4 -> V_16 , V_16 ) ;
if ( V_4 -> V_28 ) {
if ( V_4 -> V_28 <= V_19 ) {
memcpy ( V_4 -> V_16 , V_16 , V_4 -> V_28 ) ;
} else {
V_4 -> V_28 = 0 ;
V_3 -> V_26 . V_29 ++ ;
F_6 ( V_30 , & V_4 -> V_9 ) ;
}
}
V_3 -> V_31 = V_18 ;
V_4 -> V_32 = V_19 ;
F_17 ( & V_4 -> V_23 ) ;
F_10 ( V_17 ) ;
F_10 ( V_16 ) ;
return 0 ;
}
static inline void F_18 ( struct V_1 * V_4 )
{
F_19 ( V_4 -> V_3 ) ;
}
static inline void F_20 ( struct V_1 * V_4 )
{
F_21 ( V_4 -> V_3 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_33 * V_34 ;
int V_35 ;
int V_36 ;
V_35 = V_4 -> V_28 ;
V_3 -> V_26 . V_37 += V_35 ;
V_34 = F_23 ( V_35 + 1 ) ;
if ( V_34 == NULL ) {
F_24 ( V_4 -> V_3 , L_4 ) ;
V_3 -> V_26 . V_38 ++ ;
return;
}
F_25 ( V_34 , 1 ) ;
memcpy ( F_26 ( V_34 , V_35 ) , V_4 -> V_16 , V_35 ) ;
V_34 -> V_39 = F_27 ( V_34 , V_4 -> V_3 ) ;
V_36 = F_28 ( V_34 -> V_3 , V_34 ) ;
if ( V_36 != V_40 ) {
F_29 ( V_34 ) ;
F_30 ( V_41 L_5 , V_36 ) ;
} else {
F_31 ( V_34 ) ;
V_3 -> V_26 . V_42 ++ ;
}
}
static void F_32 ( struct V_1 * V_4 , unsigned char * V_43 , int V_19 )
{
unsigned char * V_44 ;
int V_45 , V_35 , V_31 = V_4 -> V_3 -> V_31 ;
if ( V_19 > V_31 ) {
V_19 = V_31 ;
F_30 ( V_41 L_6 ,
V_4 -> V_3 -> V_10 ) ;
V_4 -> V_3 -> V_26 . V_27 ++ ;
F_20 ( V_4 ) ;
return;
}
V_44 = V_43 ;
V_35 = F_33 ( V_44 , V_4 -> V_17 , V_19 ) ;
F_6 ( V_46 , & V_4 -> V_47 -> V_9 ) ;
V_45 = V_4 -> V_47 -> V_48 -> V_49 ( V_4 -> V_47 , V_4 -> V_17 , V_35 ) ;
V_4 -> V_24 = V_35 - V_45 ;
V_4 -> V_25 = V_4 -> V_17 + V_45 ;
F_34 ( V_50 , & V_4 -> V_9 ) ;
}
static void F_35 ( struct V_51 * V_47 )
{
int V_45 ;
struct V_1 * V_4 = V_47 -> V_52 ;
if ( ! V_4 || V_4 -> V_53 != V_54 || ! F_36 ( V_4 -> V_3 ) )
return;
if ( V_4 -> V_24 <= 0 ) {
V_4 -> V_3 -> V_26 . V_55 ++ ;
F_34 ( V_46 , & V_47 -> V_9 ) ;
F_20 ( V_4 ) ;
return;
}
V_45 = V_47 -> V_48 -> V_49 ( V_47 , V_4 -> V_25 , V_4 -> V_24 ) ;
V_4 -> V_24 -= V_45 ;
V_4 -> V_25 += V_45 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_23 ) ;
if ( F_39 ( V_3 ) ) {
F_24 ( V_3 , L_7 ,
( F_40 ( V_4 -> V_47 ) || V_4 -> V_24 ) ?
L_8 : L_9 ) ;
V_4 -> V_24 = 0 ;
F_34 ( V_46 , & V_4 -> V_47 -> V_9 ) ;
F_20 ( V_4 ) ;
}
F_41 ( & V_4 -> V_23 ) ;
}
static T_1 F_42 ( struct V_33 * V_34 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_36 ;
if ( ! F_36 ( V_4 -> V_3 ) ) {
F_12 ( V_3 , L_10 ) ;
F_29 ( V_34 ) ;
return V_56 ;
}
switch ( V_34 -> V_57 [ 0 ] ) {
case V_58 :
break;
case V_59 :
V_36 = F_43 ( V_3 ) ;
if ( V_36 != V_40 )
F_12 ( V_3 , L_11 ,
V_36 ) ;
F_29 ( V_34 ) ;
return V_56 ;
case V_60 :
V_36 = F_44 ( V_3 ) ;
if ( V_36 != V_40 )
F_12 ( V_3 , L_12 ,
V_36 ) ;
default:
F_29 ( V_34 ) ;
return V_56 ;
}
F_45 ( V_34 , 1 ) ;
V_36 = F_46 ( V_3 , V_34 ) ;
if ( V_36 != V_40 ) {
F_12 ( V_3 , L_13 , V_36 ) ;
F_29 ( V_34 ) ;
return V_56 ;
}
return V_56 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
return F_31 ( V_34 ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_23 ) ;
if ( F_39 ( V_4 -> V_3 ) || V_4 -> V_47 == NULL ) {
F_41 ( & V_4 -> V_23 ) ;
F_12 ( V_3 , L_14 ) ;
F_29 ( V_34 ) ;
return;
}
if ( V_34 != NULL ) {
F_18 ( V_4 ) ;
V_3 -> V_26 . V_61 += V_34 -> V_19 ;
F_32 ( V_4 , V_34 -> V_57 , V_34 -> V_19 ) ;
F_49 ( V_34 ) ;
}
F_41 ( & V_4 -> V_23 ) ;
}
static void F_50 ( struct V_2 * V_3 , int V_62 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_33 * V_34 ;
unsigned char * V_63 ;
V_34 = F_23 ( 1 ) ;
if ( V_34 == NULL ) {
F_12 ( V_3 , L_15 ) ;
return;
}
V_63 = F_26 ( V_34 , 1 ) ;
* V_63 = V_59 ;
V_34 -> V_39 = F_27 ( V_34 , V_4 -> V_3 ) ;
F_31 ( V_34 ) ;
}
static void F_51 ( struct V_2 * V_3 , int V_62 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_33 * V_34 ;
unsigned char * V_63 ;
V_34 = F_23 ( 1 ) ;
if ( V_34 == NULL ) {
F_12 ( V_3 , L_15 ) ;
return;
}
V_63 = F_26 ( V_34 , 1 ) ;
* V_63 = V_60 ;
V_34 -> V_39 = F_27 ( V_34 , V_4 -> V_3 ) ;
F_31 ( V_34 ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_19 ;
int V_36 ;
if ( V_4 -> V_47 == NULL )
return - V_64 ;
V_19 = V_3 -> V_31 * 2 ;
V_4 -> V_16 = F_14 ( V_19 + 4 , V_65 ) ;
if ( V_4 -> V_16 == NULL )
goto V_66;
V_4 -> V_17 = F_14 ( V_19 + 4 , V_65 ) ;
if ( V_4 -> V_17 == NULL )
goto V_67;
V_4 -> V_32 = V_19 ;
V_4 -> V_28 = 0 ;
V_4 -> V_24 = 0 ;
V_4 -> V_9 &= ( 1 << V_8 ) ;
F_53 ( V_3 ) ;
V_36 = F_54 ( V_3 , & V_68 ) ;
if ( V_36 == V_40 )
return 0 ;
F_10 ( V_4 -> V_17 ) ;
V_67:
F_10 ( V_4 -> V_16 ) ;
V_66:
return - V_22 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_23 ) ;
if ( V_4 -> V_47 )
F_34 ( V_46 , & V_4 -> V_47 -> V_9 ) ;
F_19 ( V_3 ) ;
V_4 -> V_28 = 0 ;
V_4 -> V_24 = 0 ;
F_41 ( & V_4 -> V_23 ) ;
return 0 ;
}
static void F_56 ( struct V_51 * V_47 ,
const unsigned char * V_69 , char * V_70 , int V_35 )
{
struct V_1 * V_4 = V_47 -> V_52 ;
if ( ! V_4 || V_4 -> V_53 != V_54 || ! F_36 ( V_4 -> V_3 ) )
return;
while ( V_35 -- ) {
if ( V_70 && * V_70 ++ ) {
if ( ! F_3 ( V_30 , & V_4 -> V_9 ) )
V_4 -> V_3 -> V_26 . V_71 ++ ;
V_69 ++ ;
continue;
}
F_57 ( V_4 , * V_69 ++ ) ;
}
}
static int F_58 ( struct V_51 * V_47 )
{
struct V_1 * V_4 = V_47 -> V_52 ;
int V_36 ;
if ( V_47 -> V_48 -> V_49 == NULL )
return - V_72 ;
if ( V_4 && V_4 -> V_53 == V_54 )
return - V_73 ;
V_4 = F_1 () ;
if ( V_4 == NULL )
return - V_74 ;
V_4 -> V_47 = V_47 ;
V_47 -> V_52 = V_4 ;
V_47 -> V_75 = 65536 ;
F_59 ( V_47 ) ;
F_60 ( V_47 ) ;
V_4 -> V_3 -> type = V_76 ;
V_36 = F_52 ( V_4 -> V_3 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
static void F_61 ( struct V_51 * V_47 )
{
struct V_1 * V_4 = V_47 -> V_52 ;
int V_36 ;
if ( ! V_4 || V_4 -> V_53 != V_54 )
return;
F_62 () ;
if ( V_4 -> V_3 -> V_9 & V_77 )
F_63 ( V_4 -> V_3 ) ;
F_64 () ;
V_36 = F_65 ( V_4 -> V_3 ) ;
if ( V_36 != V_40 )
F_66 ( L_16 ,
V_36 ) ;
V_47 -> V_52 = NULL ;
V_4 -> V_47 = NULL ;
F_9 ( V_4 ) ;
}
static int F_33 ( unsigned char * V_78 , unsigned char * V_79 , int V_19 )
{
unsigned char * V_63 = V_79 ;
unsigned char V_80 ;
* V_63 ++ = V_81 ;
while ( V_19 -- > 0 ) {
switch ( V_80 = * V_78 ++ ) {
case V_81 :
* V_63 ++ = V_82 ;
* V_63 ++ = F_67 ( V_81 ) ;
break;
case V_82 :
* V_63 ++ = V_82 ;
* V_63 ++ = F_67 ( V_82 ) ;
break;
default:
* V_63 ++ = V_80 ;
break;
}
}
* V_63 ++ = V_81 ;
return V_63 - V_79 ;
}
static void F_57 ( struct V_1 * V_4 , unsigned char V_78 )
{
switch ( V_78 ) {
case V_81 :
if ( ! F_11 ( V_30 , & V_4 -> V_9 ) &&
V_4 -> V_28 > 2 )
F_22 ( V_4 ) ;
F_34 ( V_83 , & V_4 -> V_9 ) ;
V_4 -> V_28 = 0 ;
return;
case V_82 :
F_6 ( V_83 , & V_4 -> V_9 ) ;
return;
case F_67 ( V_82 ) :
case F_67 ( V_81 ) :
if ( F_11 ( V_83 , & V_4 -> V_9 ) )
V_78 = F_68 ( V_78 ) ;
break;
}
if ( ! F_69 ( V_30 , & V_4 -> V_9 ) ) {
if ( V_4 -> V_28 < V_4 -> V_32 ) {
V_4 -> V_16 [ V_4 -> V_28 ++ ] = V_78 ;
return;
}
V_4 -> V_3 -> V_26 . V_29 ++ ;
F_6 ( V_30 , & V_4 -> V_9 ) ;
}
}
static int F_70 ( struct V_51 * V_47 , struct V_84 * V_84 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_4 = V_47 -> V_52 ;
if ( ! V_4 || V_4 -> V_53 != V_54 )
return - V_20 ;
switch ( V_85 ) {
case V_87 :
if ( F_71 ( ( void V_88 * ) V_86 , V_4 -> V_3 -> V_10 ,
strlen ( V_4 -> V_3 -> V_10 ) + 1 ) )
return - V_89 ;
return 0 ;
case V_90 :
return - V_20 ;
default:
return F_72 ( V_47 , V_84 , V_85 , V_86 ) ;
}
}
static long F_73 ( struct V_51 * V_47 , struct V_84 * V_84 ,
unsigned int V_85 , unsigned long V_86 )
{
switch ( V_85 ) {
case V_87 :
case V_90 :
return F_70 ( V_47 , V_84 , V_85 ,
( unsigned long ) F_74 ( V_86 ) ) ;
}
return - V_91 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( V_4 -> V_47 == NULL )
return - V_64 ;
return 0 ;
}
static void V_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_4 -> V_53 = V_54 ;
V_4 -> V_3 = V_3 ;
F_76 ( & V_4 -> V_23 ) ;
F_6 ( V_8 , & V_4 -> V_9 ) ;
V_3 -> V_31 = V_92 ;
V_3 -> V_93 = & V_94 ;
V_3 -> V_95 = V_96 * 20 ;
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> type = V_76 ;
V_3 -> V_99 = 10 ;
V_3 -> V_9 = V_100 ;
}
static int T_2 F_77 ( void )
{
if ( V_7 < 4 )
V_7 = 4 ;
F_78 ( L_17 ,
V_7 ) ;
V_6 = F_79 ( V_7 , sizeof( struct V_2 * ) ,
V_65 ) ;
if ( ! V_6 )
return - V_22 ;
return F_80 ( V_101 , & V_102 ) ;
}
static void T_3 F_81 ( void )
{
struct V_2 * V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_3 = V_6 [ V_5 ] ;
if ( V_3 ) {
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_15 ( & V_4 -> V_23 ) ;
if ( V_4 -> V_47 )
F_82 ( V_4 -> V_47 ) ;
F_17 ( & V_4 -> V_23 ) ;
F_83 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
F_10 ( V_6 ) ;
F_84 ( V_101 ) ;
}
