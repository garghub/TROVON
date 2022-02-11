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
V_3 = F_4 ( sizeof( struct V_1 ) ,
V_10 , V_12 ) ;
if ( ! V_3 )
return NULL ;
V_4 = F_2 ( V_3 ) ;
V_3 -> V_13 = V_5 ;
if ( F_5 ( V_3 ) == 0 ) {
F_6 ( V_8 , & V_4 -> V_9 ) ;
V_6 [ V_5 ] = V_3 ;
return V_4 ;
} else {
F_7 ( L_2 , V_14 ) ;
F_8 ( V_3 ) ;
}
}
return NULL ;
}
static void F_9 ( struct V_1 * V_4 )
{
F_10 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
F_10 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
if ( ! F_11 ( V_8 , & V_4 -> V_9 ) )
F_12 ( V_4 -> V_3 , L_3 ) ;
}
static int F_13 ( struct V_2 * V_3 , int V_17 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned char * V_16 , * V_15 ;
int V_18 = 2 * V_17 ;
V_16 = F_14 ( V_18 + 4 , V_19 ) ;
V_15 = F_14 ( V_18 + 4 , V_19 ) ;
if ( V_16 == NULL || V_15 == NULL ) {
F_15 ( V_3 , L_4 ) ;
F_10 ( V_16 ) ;
F_10 ( V_15 ) ;
return - V_20 ;
}
F_16 ( & V_4 -> V_21 ) ;
V_16 = F_17 ( & V_4 -> V_16 , V_16 ) ;
if ( V_4 -> V_22 ) {
if ( V_4 -> V_22 <= V_18 ) {
memcpy ( V_4 -> V_16 , V_4 -> V_23 , V_4 -> V_22 ) ;
} else {
V_4 -> V_22 = 0 ;
V_3 -> V_24 . V_25 ++ ;
}
}
V_4 -> V_23 = V_4 -> V_16 ;
V_15 = F_17 ( & V_4 -> V_15 , V_15 ) ;
if ( V_4 -> V_26 ) {
if ( V_4 -> V_26 <= V_18 ) {
memcpy ( V_4 -> V_15 , V_15 , V_4 -> V_26 ) ;
} else {
V_4 -> V_26 = 0 ;
V_3 -> V_24 . V_27 ++ ;
F_6 ( V_28 , & V_4 -> V_9 ) ;
}
}
V_3 -> V_29 = V_17 ;
V_4 -> V_30 = V_18 ;
F_18 ( & V_4 -> V_21 ) ;
F_10 ( V_16 ) ;
F_10 ( V_15 ) ;
return 0 ;
}
static inline void F_19 ( struct V_1 * V_4 )
{
F_20 ( V_4 -> V_3 ) ;
}
static inline void F_21 ( struct V_1 * V_4 )
{
F_22 ( V_4 -> V_3 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_31 * V_32 ;
int V_33 ;
int V_34 ;
V_33 = V_4 -> V_26 ;
V_3 -> V_24 . V_35 += V_33 ;
V_32 = F_24 ( V_33 + 1 ) ;
if ( V_32 == NULL ) {
F_15 ( V_4 -> V_3 , L_5 ) ;
V_3 -> V_24 . V_36 ++ ;
return;
}
F_25 ( V_32 , 1 ) ;
memcpy ( F_26 ( V_32 , V_33 ) , V_4 -> V_15 , V_33 ) ;
V_32 -> V_37 = F_27 ( V_32 , V_4 -> V_3 ) ;
V_34 = F_28 ( V_32 -> V_3 , V_32 ) ;
if ( V_34 != V_38 ) {
F_29 ( V_32 ) ;
F_30 ( V_39 L_6 , V_34 ) ;
} else {
F_31 ( V_32 ) ;
V_3 -> V_24 . V_40 ++ ;
}
}
static void F_32 ( struct V_1 * V_4 , unsigned char * V_41 , int V_18 )
{
unsigned char * V_42 ;
int V_43 , V_33 , V_29 = V_4 -> V_3 -> V_29 ;
if ( V_18 > V_29 ) {
V_18 = V_29 ;
F_30 ( V_39 L_7 ,
V_4 -> V_3 -> V_10 ) ;
V_4 -> V_3 -> V_24 . V_25 ++ ;
F_21 ( V_4 ) ;
return;
}
V_42 = V_41 ;
V_33 = F_33 ( V_42 , V_4 -> V_16 , V_18 ) ;
F_6 ( V_44 , & V_4 -> V_45 -> V_9 ) ;
V_43 = V_4 -> V_45 -> V_46 -> V_47 ( V_4 -> V_45 , V_4 -> V_16 , V_33 ) ;
V_4 -> V_22 = V_33 - V_43 ;
V_4 -> V_23 = V_4 -> V_16 + V_43 ;
F_34 ( V_48 , & V_4 -> V_9 ) ;
}
static void F_35 ( struct V_49 * V_45 )
{
int V_43 ;
struct V_1 * V_4 = V_45 -> V_50 ;
if ( ! V_4 || V_4 -> V_51 != V_52 || ! F_36 ( V_4 -> V_3 ) )
return;
if ( V_4 -> V_22 <= 0 ) {
V_4 -> V_3 -> V_24 . V_53 ++ ;
F_34 ( V_44 , & V_45 -> V_9 ) ;
F_21 ( V_4 ) ;
return;
}
V_43 = V_45 -> V_46 -> V_47 ( V_45 , V_4 -> V_23 , V_4 -> V_22 ) ;
V_4 -> V_22 -= V_43 ;
V_4 -> V_23 += V_43 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_21 ) ;
if ( F_39 ( V_3 ) ) {
F_15 ( V_3 , L_8 ,
( F_40 ( V_4 -> V_45 ) || V_4 -> V_22 ) ?
L_9 : L_10 ) ;
V_4 -> V_22 = 0 ;
F_34 ( V_44 , & V_4 -> V_45 -> V_9 ) ;
F_21 ( V_4 ) ;
}
F_41 ( & V_4 -> V_21 ) ;
}
static T_1 F_42 ( struct V_31 * V_32 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_34 ;
if ( ! F_36 ( V_4 -> V_3 ) ) {
F_12 ( V_3 , L_11 ) ;
F_29 ( V_32 ) ;
return V_54 ;
}
switch ( V_32 -> V_55 [ 0 ] ) {
case V_56 :
break;
case V_57 :
V_34 = F_43 ( V_3 ) ;
if ( V_34 != V_38 )
F_12 ( V_3 , L_12 ,
V_34 ) ;
F_29 ( V_32 ) ;
return V_54 ;
case V_58 :
V_34 = F_44 ( V_3 ) ;
if ( V_34 != V_38 )
F_12 ( V_3 , L_13 ,
V_34 ) ;
default:
F_29 ( V_32 ) ;
return V_54 ;
}
F_45 ( V_32 , 1 ) ;
V_34 = F_46 ( V_3 , V_32 ) ;
if ( V_34 != V_38 ) {
F_12 ( V_3 , L_14 , V_34 ) ;
F_29 ( V_32 ) ;
return V_54 ;
}
return V_54 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
return F_31 ( V_32 ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_21 ) ;
if ( F_39 ( V_4 -> V_3 ) || V_4 -> V_45 == NULL ) {
F_41 ( & V_4 -> V_21 ) ;
F_12 ( V_3 , L_15 ) ;
F_29 ( V_32 ) ;
return;
}
if ( V_32 != NULL ) {
F_19 ( V_4 ) ;
V_3 -> V_24 . V_59 += V_32 -> V_18 ;
F_32 ( V_4 , V_32 -> V_55 , V_32 -> V_18 ) ;
F_49 ( V_32 ) ;
}
F_41 ( & V_4 -> V_21 ) ;
}
static void F_50 ( struct V_2 * V_3 , int V_60 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_31 * V_32 ;
unsigned char * V_61 ;
V_32 = F_24 ( 1 ) ;
if ( V_32 == NULL ) {
F_12 ( V_3 , L_16 ) ;
return;
}
V_61 = F_26 ( V_32 , 1 ) ;
* V_61 = V_57 ;
V_32 -> V_37 = F_27 ( V_32 , V_4 -> V_3 ) ;
F_31 ( V_32 ) ;
}
static void F_51 ( struct V_2 * V_3 , int V_60 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_31 * V_32 ;
unsigned char * V_61 ;
V_32 = F_24 ( 1 ) ;
if ( V_32 == NULL ) {
F_12 ( V_3 , L_16 ) ;
return;
}
V_61 = F_26 ( V_32 , 1 ) ;
* V_61 = V_58 ;
V_32 -> V_37 = F_27 ( V_32 , V_4 -> V_3 ) ;
F_31 ( V_32 ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_18 ;
int V_34 ;
if ( V_4 -> V_45 == NULL )
return - V_62 ;
V_18 = V_3 -> V_29 * 2 ;
V_4 -> V_15 = F_14 ( V_18 + 4 , V_63 ) ;
if ( V_4 -> V_15 == NULL )
goto V_64;
V_4 -> V_16 = F_14 ( V_18 + 4 , V_63 ) ;
if ( V_4 -> V_16 == NULL )
goto V_65;
V_4 -> V_30 = V_18 ;
V_4 -> V_26 = 0 ;
V_4 -> V_22 = 0 ;
V_4 -> V_9 &= ( 1 << V_8 ) ;
F_53 ( V_3 ) ;
V_34 = F_54 ( V_3 , & V_66 ) ;
if ( V_34 == V_38 )
return 0 ;
F_10 ( V_4 -> V_16 ) ;
V_65:
F_10 ( V_4 -> V_15 ) ;
V_64:
return - V_20 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_38 ( & V_4 -> V_21 ) ;
if ( V_4 -> V_45 )
F_34 ( V_44 , & V_4 -> V_45 -> V_9 ) ;
F_20 ( V_3 ) ;
V_4 -> V_26 = 0 ;
V_4 -> V_22 = 0 ;
F_41 ( & V_4 -> V_21 ) ;
return 0 ;
}
static void F_56 ( struct V_49 * V_45 ,
const unsigned char * V_67 , char * V_68 , int V_33 )
{
struct V_1 * V_4 = V_45 -> V_50 ;
if ( ! V_4 || V_4 -> V_51 != V_52 || ! F_36 ( V_4 -> V_3 ) )
return;
while ( V_33 -- ) {
if ( V_68 && * V_68 ++ ) {
if ( ! F_3 ( V_28 , & V_4 -> V_9 ) )
V_4 -> V_3 -> V_24 . V_69 ++ ;
V_67 ++ ;
continue;
}
F_57 ( V_4 , * V_67 ++ ) ;
}
}
static int F_58 ( struct V_49 * V_45 )
{
struct V_1 * V_4 = V_45 -> V_50 ;
int V_34 ;
if ( V_45 -> V_46 -> V_47 == NULL )
return - V_70 ;
if ( V_4 && V_4 -> V_51 == V_52 )
return - V_71 ;
V_4 = F_1 () ;
if ( V_4 == NULL )
return - V_72 ;
V_4 -> V_45 = V_45 ;
V_45 -> V_50 = V_4 ;
V_45 -> V_73 = 65536 ;
F_59 ( V_45 ) ;
F_60 ( V_45 ) ;
V_4 -> V_3 -> type = V_74 ;
V_34 = F_52 ( V_4 -> V_3 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
static void F_61 ( struct V_49 * V_45 )
{
struct V_1 * V_4 = V_45 -> V_50 ;
int V_34 ;
if ( ! V_4 || V_4 -> V_51 != V_52 )
return;
F_62 () ;
if ( V_4 -> V_3 -> V_9 & V_75 )
F_63 ( V_4 -> V_3 ) ;
F_64 () ;
V_34 = F_65 ( V_4 -> V_3 ) ;
if ( V_34 != V_38 )
F_66 ( L_17 ,
V_34 ) ;
V_45 -> V_50 = NULL ;
V_4 -> V_45 = NULL ;
F_9 ( V_4 ) ;
}
static int F_33 ( unsigned char * V_76 , unsigned char * V_77 , int V_18 )
{
unsigned char * V_61 = V_77 ;
unsigned char V_78 ;
* V_61 ++ = V_79 ;
while ( V_18 -- > 0 ) {
switch ( V_78 = * V_76 ++ ) {
case V_79 :
* V_61 ++ = V_80 ;
* V_61 ++ = F_67 ( V_79 ) ;
break;
case V_80 :
* V_61 ++ = V_80 ;
* V_61 ++ = F_67 ( V_80 ) ;
break;
default:
* V_61 ++ = V_78 ;
break;
}
}
* V_61 ++ = V_79 ;
return V_61 - V_77 ;
}
static void F_57 ( struct V_1 * V_4 , unsigned char V_76 )
{
switch ( V_76 ) {
case V_79 :
if ( ! F_11 ( V_28 , & V_4 -> V_9 ) &&
V_4 -> V_26 > 2 )
F_23 ( V_4 ) ;
F_34 ( V_81 , & V_4 -> V_9 ) ;
V_4 -> V_26 = 0 ;
return;
case V_80 :
F_6 ( V_81 , & V_4 -> V_9 ) ;
return;
case F_67 ( V_80 ) :
case F_67 ( V_79 ) :
if ( F_11 ( V_81 , & V_4 -> V_9 ) )
V_76 = F_68 ( V_76 ) ;
break;
}
if ( ! F_69 ( V_28 , & V_4 -> V_9 ) ) {
if ( V_4 -> V_26 < V_4 -> V_30 ) {
V_4 -> V_15 [ V_4 -> V_26 ++ ] = V_76 ;
return;
}
V_4 -> V_3 -> V_24 . V_27 ++ ;
F_6 ( V_28 , & V_4 -> V_9 ) ;
}
}
static int F_70 ( struct V_49 * V_45 , struct V_82 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
struct V_1 * V_4 = V_45 -> V_50 ;
if ( ! V_4 || V_4 -> V_51 != V_52 )
return - V_85 ;
switch ( V_83 ) {
case V_86 :
if ( F_71 ( ( void V_87 * ) V_84 , V_4 -> V_3 -> V_10 ,
strlen ( V_4 -> V_3 -> V_10 ) + 1 ) )
return - V_88 ;
return 0 ;
case V_89 :
return - V_85 ;
default:
return F_72 ( V_45 , V_82 , V_83 , V_84 ) ;
}
}
static long F_73 ( struct V_49 * V_45 , struct V_82 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
switch ( V_83 ) {
case V_86 :
case V_89 :
return F_70 ( V_45 , V_82 , V_83 ,
( unsigned long ) F_74 ( V_84 ) ) ;
}
return - V_90 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( V_4 -> V_45 == NULL )
return - V_62 ;
return 0 ;
}
static void V_12 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_4 -> V_51 = V_52 ;
V_4 -> V_3 = V_3 ;
F_76 ( & V_4 -> V_21 ) ;
F_6 ( V_8 , & V_4 -> V_9 ) ;
V_3 -> V_29 = V_91 ;
V_3 -> V_92 = & V_93 ;
V_3 -> V_94 = V_95 * 20 ;
V_3 -> V_96 = 0 ;
V_3 -> V_97 = 0 ;
V_3 -> type = V_74 ;
V_3 -> V_98 = 10 ;
V_3 -> V_9 = V_99 ;
}
static int T_2 F_77 ( void )
{
if ( V_7 < 4 )
V_7 = 4 ;
F_78 ( L_18 ,
V_7 ) ;
V_6 = F_79 ( V_7 , sizeof( struct V_2 * ) ,
V_63 ) ;
if ( ! V_6 )
return - V_20 ;
return F_80 ( V_100 , & V_101 ) ;
}
static void T_3 F_81 ( void )
{
struct V_2 * V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_3 = V_6 [ V_5 ] ;
if ( V_3 ) {
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_16 ( & V_4 -> V_21 ) ;
if ( V_4 -> V_45 )
F_82 ( V_4 -> V_45 ) ;
F_18 ( & V_4 -> V_21 ) ;
F_83 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
F_10 ( V_6 ) ;
F_84 ( V_100 ) ;
}
