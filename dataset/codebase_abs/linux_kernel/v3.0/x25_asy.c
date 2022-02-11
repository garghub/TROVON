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
F_7 ( V_14 L_2 ) ;
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
F_7 ( V_17 L_3 ,
V_4 -> V_3 -> V_10 ) ;
}
static int F_12 ( struct V_2 * V_3 , int V_18 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned char * V_16 , * V_15 ;
int V_19 = 2 * V_18 ;
V_16 = F_13 ( V_19 + 4 , V_20 ) ;
V_15 = F_13 ( V_19 + 4 , V_20 ) ;
if ( V_16 == NULL || V_15 == NULL ) {
F_7 ( V_14 L_4 ,
V_3 -> V_10 ) ;
F_10 ( V_16 ) ;
F_10 ( V_15 ) ;
return - V_21 ;
}
F_14 ( & V_4 -> V_22 ) ;
V_16 = F_15 ( & V_4 -> V_16 , V_16 ) ;
if ( V_4 -> V_23 ) {
if ( V_4 -> V_23 <= V_19 ) {
memcpy ( V_4 -> V_16 , V_4 -> V_24 , V_4 -> V_23 ) ;
} else {
V_4 -> V_23 = 0 ;
V_3 -> V_25 . V_26 ++ ;
}
}
V_4 -> V_24 = V_4 -> V_16 ;
V_15 = F_15 ( & V_4 -> V_15 , V_15 ) ;
if ( V_4 -> V_27 ) {
if ( V_4 -> V_27 <= V_19 ) {
memcpy ( V_4 -> V_15 , V_15 , V_4 -> V_27 ) ;
} else {
V_4 -> V_27 = 0 ;
V_3 -> V_25 . V_28 ++ ;
F_6 ( V_29 , & V_4 -> V_9 ) ;
}
}
V_3 -> V_30 = V_18 ;
V_4 -> V_31 = V_19 ;
F_16 ( & V_4 -> V_22 ) ;
F_10 ( V_16 ) ;
F_10 ( V_15 ) ;
return 0 ;
}
static inline void F_17 ( struct V_1 * V_4 )
{
F_18 ( V_4 -> V_3 ) ;
}
static inline void F_19 ( struct V_1 * V_4 )
{
F_20 ( V_4 -> V_3 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_32 * V_33 ;
int V_34 ;
int V_35 ;
V_34 = V_4 -> V_27 ;
V_3 -> V_25 . V_36 += V_34 ;
V_33 = F_22 ( V_34 + 1 ) ;
if ( V_33 == NULL ) {
F_7 ( V_14 L_5 ,
V_4 -> V_3 -> V_10 ) ;
V_3 -> V_25 . V_37 ++ ;
return;
}
F_23 ( V_33 , 1 ) ;
memcpy ( F_24 ( V_33 , V_34 ) , V_4 -> V_15 , V_34 ) ;
V_33 -> V_38 = F_25 ( V_33 , V_4 -> V_3 ) ;
V_35 = F_26 ( V_33 -> V_3 , V_33 ) ;
if ( V_35 != V_39 ) {
F_27 ( V_33 ) ;
F_7 ( V_40 L_6 , V_35 ) ;
} else {
F_28 ( V_33 ) ;
V_3 -> V_25 . V_41 ++ ;
}
}
static void F_29 ( struct V_1 * V_4 , unsigned char * V_42 , int V_19 )
{
unsigned char * V_43 ;
int V_44 , V_34 , V_30 = V_4 -> V_3 -> V_30 ;
if ( V_19 > V_30 ) {
V_19 = V_30 ;
F_7 ( V_40 L_7 ,
V_4 -> V_3 -> V_10 ) ;
V_4 -> V_3 -> V_25 . V_26 ++ ;
F_19 ( V_4 ) ;
return;
}
V_43 = V_42 ;
V_34 = F_30 ( V_43 , ( unsigned char * ) V_4 -> V_16 , V_19 ) ;
F_6 ( V_45 , & V_4 -> V_46 -> V_9 ) ;
V_44 = V_4 -> V_46 -> V_47 -> V_48 ( V_4 -> V_46 , V_4 -> V_16 , V_34 ) ;
V_4 -> V_23 = V_34 - V_44 ;
V_4 -> V_24 = V_4 -> V_16 + V_44 ;
F_31 ( V_49 , & V_4 -> V_9 ) ;
}
static void F_32 ( struct V_50 * V_46 )
{
int V_44 ;
struct V_1 * V_4 = V_46 -> V_51 ;
if ( ! V_4 || V_4 -> V_52 != V_53 || ! F_33 ( V_4 -> V_3 ) )
return;
if ( V_4 -> V_23 <= 0 ) {
V_4 -> V_3 -> V_25 . V_54 ++ ;
F_31 ( V_45 , & V_46 -> V_9 ) ;
F_19 ( V_4 ) ;
return;
}
V_44 = V_46 -> V_47 -> V_48 ( V_46 , V_4 -> V_24 , V_4 -> V_23 ) ;
V_4 -> V_23 -= V_44 ;
V_4 -> V_24 += V_44 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_35 ( & V_4 -> V_22 ) ;
if ( F_36 ( V_3 ) ) {
F_7 ( V_14 L_8 , V_3 -> V_10 ,
( F_37 ( V_4 -> V_46 ) || V_4 -> V_23 ) ?
L_9 : L_10 ) ;
V_4 -> V_23 = 0 ;
F_31 ( V_45 , & V_4 -> V_46 -> V_9 ) ;
F_19 ( V_4 ) ;
}
F_38 ( & V_4 -> V_22 ) ;
}
static T_1 F_39 ( struct V_32 * V_33 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_35 ;
if ( ! F_33 ( V_4 -> V_3 ) ) {
F_7 ( V_17 L_11 ,
V_3 -> V_10 ) ;
F_27 ( V_33 ) ;
return V_55 ;
}
switch ( V_33 -> V_56 [ 0 ] ) {
case V_57 :
break;
case V_58 :
V_35 = F_40 ( V_3 ) ;
if ( V_35 != V_39 )
F_7 ( V_17 L_12 , V_35 ) ;
F_27 ( V_33 ) ;
return V_55 ;
case V_59 :
V_35 = F_41 ( V_3 ) ;
if ( V_35 != V_39 )
F_7 ( V_17 L_13 , V_35 ) ;
default:
F_27 ( V_33 ) ;
return V_55 ;
}
F_42 ( V_33 , 1 ) ;
V_35 = F_43 ( V_3 , V_33 ) ;
if ( V_35 != V_39 ) {
F_7 ( V_17 L_14 , V_35 ) ;
F_27 ( V_33 ) ;
return V_55 ;
}
return V_55 ;
}
static int F_44 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
return F_28 ( V_33 ) ;
}
static void F_45 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_35 ( & V_4 -> V_22 ) ;
if ( F_36 ( V_4 -> V_3 ) || V_4 -> V_46 == NULL ) {
F_38 ( & V_4 -> V_22 ) ;
F_7 ( V_17 L_15 ) ;
F_27 ( V_33 ) ;
return;
}
if ( V_33 != NULL ) {
F_17 ( V_4 ) ;
V_3 -> V_25 . V_60 += V_33 -> V_19 ;
F_29 ( V_4 , V_33 -> V_56 , V_33 -> V_19 ) ;
F_46 ( V_33 ) ;
}
F_38 ( & V_4 -> V_22 ) ;
}
static void F_47 ( struct V_2 * V_3 , int V_61 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_32 * V_33 ;
unsigned char * V_62 ;
V_33 = F_22 ( 1 ) ;
if ( V_33 == NULL ) {
F_7 ( V_17 L_16 ) ;
return;
}
V_62 = F_24 ( V_33 , 1 ) ;
* V_62 = V_58 ;
V_33 -> V_38 = F_25 ( V_33 , V_4 -> V_3 ) ;
F_28 ( V_33 ) ;
}
static void F_48 ( struct V_2 * V_3 , int V_61 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_32 * V_33 ;
unsigned char * V_62 ;
V_33 = F_22 ( 1 ) ;
if ( V_33 == NULL ) {
F_7 ( V_17 L_16 ) ;
return;
}
V_62 = F_24 ( V_33 , 1 ) ;
* V_62 = V_59 ;
V_33 -> V_38 = F_25 ( V_33 , V_4 -> V_3 ) ;
F_28 ( V_33 ) ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_19 ;
int V_35 ;
if ( V_4 -> V_46 == NULL )
return - V_63 ;
V_19 = V_3 -> V_30 * 2 ;
V_4 -> V_15 = F_13 ( V_19 + 4 , V_64 ) ;
if ( V_4 -> V_15 == NULL )
goto V_65;
V_4 -> V_16 = F_13 ( V_19 + 4 , V_64 ) ;
if ( V_4 -> V_16 == NULL )
goto V_66;
V_4 -> V_31 = V_19 ;
V_4 -> V_27 = 0 ;
V_4 -> V_23 = 0 ;
V_4 -> V_9 &= ( 1 << V_8 ) ;
F_50 ( V_3 ) ;
V_35 = F_51 ( V_3 , & V_67 ) ;
if ( V_35 == V_39 )
return 0 ;
F_10 ( V_4 -> V_16 ) ;
V_66:
F_10 ( V_4 -> V_15 ) ;
V_65:
return - V_21 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_35 ( & V_4 -> V_22 ) ;
if ( V_4 -> V_46 )
F_31 ( V_45 , & V_4 -> V_46 -> V_9 ) ;
F_18 ( V_3 ) ;
V_4 -> V_27 = 0 ;
V_4 -> V_23 = 0 ;
F_38 ( & V_4 -> V_22 ) ;
return 0 ;
}
static void F_53 ( struct V_50 * V_46 ,
const unsigned char * V_68 , char * V_69 , int V_34 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
if ( ! V_4 || V_4 -> V_52 != V_53 || ! F_33 ( V_4 -> V_3 ) )
return;
while ( V_34 -- ) {
if ( V_69 && * V_69 ++ ) {
if ( ! F_3 ( V_29 , & V_4 -> V_9 ) )
V_4 -> V_3 -> V_25 . V_70 ++ ;
V_68 ++ ;
continue;
}
F_54 ( V_4 , * V_68 ++ ) ;
}
}
static int F_55 ( struct V_50 * V_46 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
int V_35 ;
if ( V_46 -> V_47 -> V_48 == NULL )
return - V_71 ;
if ( V_4 && V_4 -> V_52 == V_53 )
return - V_72 ;
V_4 = F_1 () ;
if ( V_4 == NULL )
return - V_73 ;
V_4 -> V_46 = V_46 ;
V_46 -> V_51 = V_4 ;
V_46 -> V_74 = 65536 ;
F_56 ( V_46 ) ;
F_57 ( V_46 ) ;
V_4 -> V_3 -> type = V_75 ;
V_35 = F_49 ( V_4 -> V_3 ) ;
if ( V_35 )
return V_35 ;
return 0 ;
}
static void F_58 ( struct V_50 * V_46 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
int V_35 ;
if ( ! V_4 || V_4 -> V_52 != V_53 )
return;
F_59 () ;
if ( V_4 -> V_3 -> V_9 & V_76 )
F_60 ( V_4 -> V_3 ) ;
F_61 () ;
V_35 = F_62 ( V_4 -> V_3 ) ;
if ( V_35 != V_39 )
F_7 ( V_17 L_17 ,
V_35 ) ;
V_46 -> V_51 = NULL ;
V_4 -> V_46 = NULL ;
F_9 ( V_4 ) ;
}
static int F_30 ( unsigned char * V_77 , unsigned char * V_78 , int V_19 )
{
unsigned char * V_62 = V_78 ;
unsigned char V_79 ;
* V_62 ++ = V_80 ;
while ( V_19 -- > 0 ) {
switch ( V_79 = * V_77 ++ ) {
case V_80 :
* V_62 ++ = V_81 ;
* V_62 ++ = F_63 ( V_80 ) ;
break;
case V_81 :
* V_62 ++ = V_81 ;
* V_62 ++ = F_63 ( V_81 ) ;
break;
default:
* V_62 ++ = V_79 ;
break;
}
}
* V_62 ++ = V_80 ;
return V_62 - V_78 ;
}
static void F_54 ( struct V_1 * V_4 , unsigned char V_77 )
{
switch ( V_77 ) {
case V_80 :
if ( ! F_11 ( V_29 , & V_4 -> V_9 ) &&
V_4 -> V_27 > 2 )
F_21 ( V_4 ) ;
F_31 ( V_82 , & V_4 -> V_9 ) ;
V_4 -> V_27 = 0 ;
return;
case V_81 :
F_6 ( V_82 , & V_4 -> V_9 ) ;
return;
case F_63 ( V_81 ) :
case F_63 ( V_80 ) :
if ( F_11 ( V_82 , & V_4 -> V_9 ) )
V_77 = F_64 ( V_77 ) ;
break;
}
if ( ! F_65 ( V_29 , & V_4 -> V_9 ) ) {
if ( V_4 -> V_27 < V_4 -> V_31 ) {
V_4 -> V_15 [ V_4 -> V_27 ++ ] = V_77 ;
return;
}
V_4 -> V_3 -> V_25 . V_28 ++ ;
F_6 ( V_29 , & V_4 -> V_9 ) ;
}
}
static int F_66 ( struct V_50 * V_46 , struct V_83 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_1 * V_4 = V_46 -> V_51 ;
if ( ! V_4 || V_4 -> V_52 != V_53 )
return - V_86 ;
switch ( V_84 ) {
case V_87 :
if ( F_67 ( ( void V_88 * ) V_85 , V_4 -> V_3 -> V_10 ,
strlen ( V_4 -> V_3 -> V_10 ) + 1 ) )
return - V_89 ;
return 0 ;
case V_90 :
return - V_86 ;
default:
return F_68 ( V_46 , V_83 , V_84 , V_85 ) ;
}
}
static long F_69 ( struct V_50 * V_46 , struct V_83 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
switch ( V_84 ) {
case V_87 :
case V_90 :
return F_66 ( V_46 , V_83 , V_84 ,
( unsigned long ) F_70 ( V_85 ) ) ;
}
return - V_91 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( V_4 -> V_46 == NULL )
return - V_63 ;
return 0 ;
}
static void V_12 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_4 -> V_52 = V_53 ;
V_4 -> V_3 = V_3 ;
F_72 ( & V_4 -> V_22 ) ;
F_6 ( V_8 , & V_4 -> V_9 ) ;
V_3 -> V_30 = V_92 ;
V_3 -> V_93 = & V_94 ;
V_3 -> V_95 = V_96 * 20 ;
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> type = V_75 ;
V_3 -> V_99 = 10 ;
V_3 -> V_9 = V_100 ;
}
static int T_2 F_73 ( void )
{
if ( V_7 < 4 )
V_7 = 4 ;
F_7 ( V_101 L_18
L_19 , V_7 ) ;
V_6 = F_74 ( V_7 , sizeof( struct V_2 * ) ,
V_64 ) ;
if ( ! V_6 ) {
F_7 ( V_14 L_20
L_21 ) ;
return - V_21 ;
}
return F_75 ( V_102 , & V_103 ) ;
}
static void T_3 F_76 ( void )
{
struct V_2 * V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_3 = V_6 [ V_5 ] ;
if ( V_3 ) {
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_14 ( & V_4 -> V_22 ) ;
if ( V_4 -> V_46 )
F_77 ( V_4 -> V_46 ) ;
F_16 ( & V_4 -> V_22 ) ;
F_78 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
F_10 ( V_6 ) ;
F_79 ( V_102 ) ;
}
