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
V_19 = 2 * V_18 ;
V_17 = F_14 ( V_19 + 4 , V_20 ) ;
V_16 = F_14 ( V_19 + 4 , V_20 ) ;
if ( V_17 == NULL || V_16 == NULL ) {
F_10 ( V_17 ) ;
F_10 ( V_16 ) ;
return - V_21 ;
}
F_15 ( & V_4 -> V_22 ) ;
V_17 = F_16 ( & V_4 -> V_17 , V_17 ) ;
if ( V_4 -> V_23 ) {
if ( V_4 -> V_23 <= V_19 ) {
memcpy ( V_4 -> V_17 , V_4 -> V_24 , V_4 -> V_23 ) ;
} else {
V_4 -> V_23 = 0 ;
V_3 -> V_25 . V_26 ++ ;
}
}
V_4 -> V_24 = V_4 -> V_17 ;
V_16 = F_16 ( & V_4 -> V_16 , V_16 ) ;
if ( V_4 -> V_27 ) {
if ( V_4 -> V_27 <= V_19 ) {
memcpy ( V_4 -> V_16 , V_16 , V_4 -> V_27 ) ;
} else {
V_4 -> V_27 = 0 ;
V_3 -> V_25 . V_28 ++ ;
F_6 ( V_29 , & V_4 -> V_9 ) ;
}
}
V_3 -> V_30 = V_18 ;
V_4 -> V_31 = V_19 ;
F_17 ( & V_4 -> V_22 ) ;
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
struct V_32 * V_33 ;
int V_34 ;
int V_35 ;
V_34 = V_4 -> V_27 ;
V_3 -> V_25 . V_36 += V_34 ;
V_33 = F_23 ( V_34 + 1 ) ;
if ( V_33 == NULL ) {
F_24 ( V_4 -> V_3 , L_4 ) ;
V_3 -> V_25 . V_37 ++ ;
return;
}
F_25 ( V_33 , 1 ) ;
F_26 ( V_33 , V_4 -> V_16 , V_34 ) ;
V_33 -> V_38 = F_27 ( V_33 , V_4 -> V_3 ) ;
V_35 = F_28 ( V_33 -> V_3 , V_33 ) ;
if ( V_35 != V_39 ) {
F_29 ( V_33 ) ;
F_30 ( V_40 L_5 , V_35 ) ;
} else {
F_31 ( V_33 ) ;
V_3 -> V_25 . V_41 ++ ;
}
}
static void F_32 ( struct V_1 * V_4 , unsigned char * V_42 , int V_19 )
{
unsigned char * V_43 ;
int V_44 , V_34 , V_30 = V_4 -> V_3 -> V_30 ;
if ( V_19 > V_30 ) {
V_19 = V_30 ;
F_30 ( V_40 L_6 ,
V_4 -> V_3 -> V_10 ) ;
V_4 -> V_3 -> V_25 . V_26 ++ ;
F_20 ( V_4 ) ;
return;
}
V_43 = V_42 ;
V_34 = F_33 ( V_43 , V_4 -> V_17 , V_19 ) ;
F_6 ( V_45 , & V_4 -> V_46 -> V_9 ) ;
V_44 = V_4 -> V_46 -> V_47 -> V_48 ( V_4 -> V_46 , V_4 -> V_17 , V_34 ) ;
V_4 -> V_23 = V_34 - V_44 ;
V_4 -> V_24 = V_4 -> V_17 + V_44 ;
F_34 ( V_49 , & V_4 -> V_9 ) ;
}
static void F_35 ( struct V_50 * V_46 )
{
int V_44 ;
struct V_1 * V_4 = V_46 -> V_51 ;
if ( ! V_4 || V_4 -> V_52 != V_53 || ! F_36 ( V_4 -> V_3 ) )
return;
if ( V_4 -> V_23 <= 0 ) {
V_4 -> V_3 -> V_25 . V_54 ++ ;
F_34 ( V_45 , & V_46 -> V_9 ) ;
F_20 ( V_4 ) ;
return;
}
V_44 = V_46 -> V_47 -> V_48 ( V_46 , V_4 -> V_24 , V_4 -> V_23 ) ;
V_4 -> V_23 -= V_44 ;
V_4 -> V_24 += V_44 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_22 ) ;
if ( F_39 ( V_3 ) ) {
F_24 ( V_3 , L_7 ,
( F_40 ( V_4 -> V_46 ) || V_4 -> V_23 ) ?
L_8 : L_9 ) ;
V_4 -> V_23 = 0 ;
F_34 ( V_45 , & V_4 -> V_46 -> V_9 ) ;
F_20 ( V_4 ) ;
}
F_41 ( & V_4 -> V_22 ) ;
}
static T_1 F_42 ( struct V_32 * V_33 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_35 ;
if ( ! F_36 ( V_4 -> V_3 ) ) {
F_12 ( V_3 , L_10 ) ;
F_29 ( V_33 ) ;
return V_55 ;
}
switch ( V_33 -> V_56 [ 0 ] ) {
case V_57 :
break;
case V_58 :
V_35 = F_43 ( V_3 ) ;
if ( V_35 != V_39 )
F_12 ( V_3 , L_11 ,
V_35 ) ;
F_29 ( V_33 ) ;
return V_55 ;
case V_59 :
V_35 = F_44 ( V_3 ) ;
if ( V_35 != V_39 )
F_12 ( V_3 , L_12 ,
V_35 ) ;
default:
F_29 ( V_33 ) ;
return V_55 ;
}
F_45 ( V_33 , 1 ) ;
V_35 = F_46 ( V_3 , V_33 ) ;
if ( V_35 != V_39 ) {
F_12 ( V_3 , L_13 , V_35 ) ;
F_29 ( V_33 ) ;
return V_55 ;
}
return V_55 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
return F_31 ( V_33 ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_22 ) ;
if ( F_39 ( V_4 -> V_3 ) || V_4 -> V_46 == NULL ) {
F_41 ( & V_4 -> V_22 ) ;
F_12 ( V_3 , L_14 ) ;
F_29 ( V_33 ) ;
return;
}
if ( V_33 != NULL ) {
F_18 ( V_4 ) ;
V_3 -> V_25 . V_60 += V_33 -> V_19 ;
F_32 ( V_4 , V_33 -> V_56 , V_33 -> V_19 ) ;
F_49 ( V_33 ) ;
}
F_41 ( & V_4 -> V_22 ) ;
}
static void F_50 ( struct V_2 * V_3 , int V_61 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_32 * V_33 ;
unsigned char * V_62 ;
V_33 = F_23 ( 1 ) ;
if ( V_33 == NULL ) {
F_12 ( V_3 , L_15 ) ;
return;
}
V_62 = F_51 ( V_33 , 1 ) ;
* V_62 = V_58 ;
V_33 -> V_38 = F_27 ( V_33 , V_4 -> V_3 ) ;
F_31 ( V_33 ) ;
}
static void F_52 ( struct V_2 * V_3 , int V_61 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_32 * V_33 ;
unsigned char * V_62 ;
V_33 = F_23 ( 1 ) ;
if ( V_33 == NULL ) {
F_12 ( V_3 , L_15 ) ;
return;
}
V_62 = F_51 ( V_33 , 1 ) ;
* V_62 = V_59 ;
V_33 -> V_38 = F_27 ( V_33 , V_4 -> V_3 ) ;
F_31 ( V_33 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_19 ;
int V_35 ;
if ( V_4 -> V_46 == NULL )
return - V_63 ;
V_19 = V_3 -> V_30 * 2 ;
V_4 -> V_16 = F_14 ( V_19 + 4 , V_64 ) ;
if ( V_4 -> V_16 == NULL )
goto V_65;
V_4 -> V_17 = F_14 ( V_19 + 4 , V_64 ) ;
if ( V_4 -> V_17 == NULL )
goto V_66;
V_4 -> V_31 = V_19 ;
V_4 -> V_27 = 0 ;
V_4 -> V_23 = 0 ;
V_4 -> V_9 &= ( 1 << V_8 ) ;
F_54 ( V_3 ) ;
V_35 = F_55 ( V_3 , & V_67 ) ;
if ( V_35 == V_39 )
return 0 ;
F_10 ( V_4 -> V_17 ) ;
V_66:
F_10 ( V_4 -> V_16 ) ;
V_65:
return - V_21 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_22 ) ;
if ( V_4 -> V_46 )
F_34 ( V_45 , & V_4 -> V_46 -> V_9 ) ;
F_19 ( V_3 ) ;
V_4 -> V_27 = 0 ;
V_4 -> V_23 = 0 ;
F_41 ( & V_4 -> V_22 ) ;
return 0 ;
}
static void F_57 ( struct V_50 * V_46 ,
const unsigned char * V_68 , char * V_69 , int V_34 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
if ( ! V_4 || V_4 -> V_52 != V_53 || ! F_36 ( V_4 -> V_3 ) )
return;
while ( V_34 -- ) {
if ( V_69 && * V_69 ++ ) {
if ( ! F_3 ( V_29 , & V_4 -> V_9 ) )
V_4 -> V_3 -> V_25 . V_70 ++ ;
V_68 ++ ;
continue;
}
F_58 ( V_4 , * V_68 ++ ) ;
}
}
static int F_59 ( struct V_50 * V_46 )
{
struct V_1 * V_4 ;
int V_35 ;
if ( V_46 -> V_47 -> V_48 == NULL )
return - V_71 ;
V_4 = F_1 () ;
if ( V_4 == NULL )
return - V_72 ;
V_4 -> V_46 = V_46 ;
V_46 -> V_51 = V_4 ;
V_46 -> V_73 = 65536 ;
F_60 ( V_46 ) ;
F_61 ( V_46 ) ;
V_4 -> V_3 -> type = V_74 ;
V_35 = F_53 ( V_4 -> V_3 ) ;
if ( V_35 ) {
F_9 ( V_4 ) ;
return V_35 ;
}
return 0 ;
}
static void F_62 ( struct V_50 * V_46 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
int V_35 ;
if ( ! V_4 || V_4 -> V_52 != V_53 )
return;
F_63 () ;
if ( V_4 -> V_3 -> V_9 & V_75 )
F_64 ( V_4 -> V_3 ) ;
F_65 () ;
V_35 = F_66 ( V_4 -> V_3 ) ;
if ( V_35 != V_39 )
F_67 ( L_16 ,
V_35 ) ;
V_46 -> V_51 = NULL ;
V_4 -> V_46 = NULL ;
F_9 ( V_4 ) ;
}
static int F_33 ( unsigned char * V_76 , unsigned char * V_77 , int V_19 )
{
unsigned char * V_62 = V_77 ;
unsigned char V_78 ;
* V_62 ++ = V_79 ;
while ( V_19 -- > 0 ) {
switch ( V_78 = * V_76 ++ ) {
case V_79 :
* V_62 ++ = V_80 ;
* V_62 ++ = F_68 ( V_79 ) ;
break;
case V_80 :
* V_62 ++ = V_80 ;
* V_62 ++ = F_68 ( V_80 ) ;
break;
default:
* V_62 ++ = V_78 ;
break;
}
}
* V_62 ++ = V_79 ;
return V_62 - V_77 ;
}
static void F_58 ( struct V_1 * V_4 , unsigned char V_76 )
{
switch ( V_76 ) {
case V_79 :
if ( ! F_11 ( V_29 , & V_4 -> V_9 ) &&
V_4 -> V_27 > 2 )
F_22 ( V_4 ) ;
F_34 ( V_81 , & V_4 -> V_9 ) ;
V_4 -> V_27 = 0 ;
return;
case V_80 :
F_6 ( V_81 , & V_4 -> V_9 ) ;
return;
case F_68 ( V_80 ) :
case F_68 ( V_79 ) :
if ( F_11 ( V_81 , & V_4 -> V_9 ) )
V_76 = F_69 ( V_76 ) ;
break;
}
if ( ! F_70 ( V_29 , & V_4 -> V_9 ) ) {
if ( V_4 -> V_27 < V_4 -> V_31 ) {
V_4 -> V_16 [ V_4 -> V_27 ++ ] = V_76 ;
return;
}
V_4 -> V_3 -> V_25 . V_28 ++ ;
F_6 ( V_29 , & V_4 -> V_9 ) ;
}
}
static int F_71 ( struct V_50 * V_46 , struct V_82 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
if ( ! V_4 || V_4 -> V_52 != V_53 )
return - V_85 ;
switch ( V_83 ) {
case V_86 :
if ( F_72 ( ( void V_87 * ) V_84 , V_4 -> V_3 -> V_10 ,
strlen ( V_4 -> V_3 -> V_10 ) + 1 ) )
return - V_88 ;
return 0 ;
case V_89 :
return - V_85 ;
default:
return F_73 ( V_46 , V_82 , V_83 , V_84 ) ;
}
}
static long F_74 ( struct V_50 * V_46 , struct V_82 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
switch ( V_83 ) {
case V_86 :
case V_89 :
return F_71 ( V_46 , V_82 , V_83 ,
( unsigned long ) F_75 ( V_84 ) ) ;
}
return - V_90 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( V_4 -> V_46 == NULL )
return - V_63 ;
return 0 ;
}
static void V_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_4 -> V_52 = V_53 ;
V_4 -> V_3 = V_3 ;
F_77 ( & V_4 -> V_22 ) ;
F_6 ( V_8 , & V_4 -> V_9 ) ;
V_3 -> V_30 = V_91 ;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 65534 ;
V_3 -> V_94 = & V_95 ;
V_3 -> V_96 = V_97 * 20 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> type = V_74 ;
V_3 -> V_100 = 10 ;
V_3 -> V_9 = V_101 ;
}
static int T_2 F_78 ( void )
{
if ( V_7 < 4 )
V_7 = 4 ;
F_79 ( L_17 ,
V_7 ) ;
V_6 = F_80 ( V_7 , sizeof( struct V_2 * ) ,
V_64 ) ;
if ( ! V_6 )
return - V_21 ;
return F_81 ( V_102 , & V_103 ) ;
}
static void T_3 F_82 ( void )
{
struct V_2 * V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_3 = V_6 [ V_5 ] ;
if ( V_3 ) {
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_15 ( & V_4 -> V_22 ) ;
if ( V_4 -> V_46 )
F_83 ( V_4 -> V_46 ) ;
F_17 ( & V_4 -> V_22 ) ;
F_84 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
F_10 ( V_6 ) ;
F_85 ( V_102 ) ;
}
