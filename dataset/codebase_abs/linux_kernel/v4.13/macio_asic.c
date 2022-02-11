static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! V_6 )
return 0 ;
return F_2 ( V_6 , V_2 ) != NULL ;
}
struct V_8 * F_3 ( struct V_8 * V_2 )
{
struct V_1 * V_9 ;
if ( ! V_2 )
return NULL ;
V_9 = F_4 ( & V_2 -> V_10 . V_2 ) ;
if ( V_9 )
return F_5 ( V_9 ) ;
else
return NULL ;
}
void F_6 ( struct V_8 * V_2 )
{
if ( V_2 )
F_7 ( & V_2 -> V_10 . V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int error = - V_11 ;
struct V_12 * V_4 ;
struct V_8 * V_8 ;
const struct V_5 * V_13 ;
V_4 = F_9 ( V_2 -> V_14 ) ;
V_8 = F_5 ( V_2 ) ;
if ( ! V_4 -> V_15 )
return error ;
F_3 ( V_8 ) ;
V_13 = F_2 ( V_4 -> V_14 . V_7 , V_2 ) ;
if ( V_13 )
error = V_4 -> V_15 ( V_8 , V_13 ) ;
if ( error )
F_6 ( V_8 ) ;
return error ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
struct V_12 * V_4 = F_9 ( V_2 -> V_14 ) ;
if ( V_2 -> V_14 && V_4 -> remove )
V_4 -> remove ( V_8 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
struct V_12 * V_4 = F_9 ( V_2 -> V_14 ) ;
if ( V_2 -> V_14 && V_4 -> V_16 )
V_4 -> V_16 ( V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
struct V_12 * V_4 = F_9 ( V_2 -> V_14 ) ;
if ( V_2 -> V_14 && V_4 -> V_18 )
return V_4 -> V_18 ( V_8 , V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
struct V_12 * V_4 = F_9 ( V_2 -> V_14 ) ;
if ( V_2 -> V_14 && V_4 -> V_19 )
return V_4 -> V_19 ( V_8 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_21 ;
V_21 = F_5 ( V_2 ) ;
F_17 ( V_21 ) ;
}
static int F_18 ( struct V_22 * V_23 , struct V_24 * V_25 ,
int V_26 )
{
if ( ( V_25 -> V_27 & V_28 ) == 0 )
return 0 ;
if ( V_26 == 0 && ! strcmp ( V_23 -> V_29 , L_1 ) )
V_25 -> V_30 = V_25 -> V_31 + 0x1ffff ;
if ( V_26 >= 2 && ! strcmp ( V_23 -> V_29 , L_2 ) )
return 1 ;
#ifndef F_19
if ( ( V_25 -> V_31 & 0x0001f000 ) == 0x00008000 )
V_25 -> V_30 = V_25 -> V_31 + 0xff ;
#endif
if ( ! strcmp ( V_23 -> V_29 , L_3 ) )
return 1 ;
if ( V_26 >= 3 && ! ( strcmp ( V_23 -> V_29 , L_4 ) &&
strcmp ( V_23 -> V_29 , L_5 ) ) )
return 1 ;
if ( V_26 > 0 && ! strcmp ( V_23 -> V_29 , L_6 ) )
return 1 ;
if ( ! ( strcmp ( V_23 -> V_29 , L_7 ) && strcmp ( V_23 -> V_29 , L_8 ) &&
strcmp ( V_23 -> type , L_9 ) && strcmp ( V_23 -> type , L_10 ) ) ) {
if ( V_26 == 0 && ( V_25 -> V_30 - V_25 -> V_31 ) > 0xfff )
V_25 -> V_30 = V_25 -> V_31 + 0xfff ;
if ( V_26 == 1 && ( V_25 -> V_30 - V_25 -> V_31 ) > 0xff )
V_25 -> V_30 = V_25 -> V_31 + 0xff ;
}
return 0 ;
}
static void F_20 ( struct V_8 * V_2 , int V_26 ,
unsigned int line )
{
unsigned int V_32 ;
V_32 = F_21 ( NULL , line ) ;
if ( ! V_32 ) {
V_2 -> V_33 [ V_26 ] . V_31 = V_32 ;
V_2 -> V_33 [ V_26 ] . V_27 = V_34 ;
V_2 -> V_33 [ V_26 ] . V_29 = F_22 ( & V_2 -> V_10 . V_2 ) ;
}
if ( V_2 -> V_35 <= V_26 )
V_2 -> V_35 = V_26 + 1 ;
}
static void F_23 ( struct V_8 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_10 . V_2 . V_36 ;
unsigned int V_37 ;
if ( V_2 -> V_38 -> V_39 -> type != V_40 )
return;
V_37 = 64 ;
if ( strcmp ( V_23 -> V_29 , L_4 ) == 0 ) {
F_20 ( V_2 , 0 , 15 + V_37 ) ;
F_20 ( V_2 , 1 , 4 + V_37 ) ;
F_20 ( V_2 , 2 , 5 + V_37 ) ;
F_24 ( V_41 L_11 ) ;
}
if ( strcmp ( V_23 -> V_29 , L_6 ) == 0 ) {
F_20 ( V_2 , 0 , 29 + V_37 ) ;
F_24 ( V_41 L_12 ) ;
}
if ( V_2 -> V_42 != NULL && strcmp ( V_23 -> V_29 , L_13 ) == 0 ) {
F_20 ( V_2 , 0 , 19 + V_37 ) ;
F_20 ( V_2 , 1 , 1 + V_37 ) ;
F_24 ( V_41 L_14 ) ;
}
if ( V_2 -> V_42 != NULL && strcasecmp ( V_23 -> V_29 , L_15 ) == 0 ) {
F_20 ( V_2 , 0 , 14 + V_37 ) ;
F_20 ( V_2 , 0 , 3 + V_37 ) ;
F_24 ( V_41 L_16 ) ;
}
}
static void F_25 ( struct V_8 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_10 . V_2 . V_36 ;
unsigned int V_32 ;
int V_43 = 0 , V_44 = 0 ;
for (; ; ) {
struct V_24 * V_25 ;
if ( V_44 >= V_45 )
break;
V_25 = & V_2 -> V_33 [ V_44 ] ;
V_32 = F_26 ( V_23 , V_43 ++ ) ;
if ( ! V_32 )
break;
V_25 -> V_31 = V_32 ;
V_25 -> V_27 = V_34 ;
V_25 -> V_29 = F_22 ( & V_2 -> V_10 . V_2 ) ;
if ( F_18 ( V_23 , V_25 , V_43 - 1 ) ) {
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
continue;
} else
V_44 ++ ;
}
V_2 -> V_35 = V_44 ;
}
static void F_27 ( struct V_8 * V_2 ,
struct V_24 * V_46 )
{
struct V_22 * V_23 = V_2 -> V_10 . V_2 . V_36 ;
struct V_24 V_47 ;
int V_26 ;
for ( V_26 = 0 ; F_28 ( V_23 , V_26 , & V_47 ) == 0 ; V_26 ++ ) {
struct V_24 * V_25 ;
if ( V_26 >= V_48 )
break;
V_25 = & V_2 -> V_24 [ V_26 ] ;
* V_25 = V_47 ;
V_25 -> V_29 = F_22 ( & V_2 -> V_10 . V_2 ) ;
if ( F_18 ( V_23 , V_25 , V_26 ) ) {
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
continue;
}
if ( F_29 ( V_46 , V_25 ) ) {
F_24 ( V_49 L_17
L_18 ,
V_26 , F_22 ( & V_2 -> V_10 . V_2 ) ) ;
}
}
V_2 -> V_50 = V_26 ;
}
static struct V_8 * F_30 ( struct V_51 * V_39 ,
struct V_1 * V_52 ,
struct V_22 * V_23 ,
struct V_8 * V_53 ,
struct V_24 * V_46 )
{
struct V_8 * V_2 ;
const T_3 * V_54 ;
if ( V_23 == NULL )
return NULL ;
V_2 = F_31 ( sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_38 = & V_39 -> V_56 ;
V_2 -> V_42 = V_53 ;
V_2 -> V_10 . V_2 . V_36 = V_23 ;
V_2 -> V_10 . V_57 . V_58 = 0xffffffffUL ;
V_2 -> V_10 . V_2 . V_58 = & V_2 -> V_10 . V_57 . V_58 ;
V_2 -> V_10 . V_2 . V_52 = V_52 ;
V_2 -> V_10 . V_2 . V_38 = & V_20 ;
V_2 -> V_10 . V_2 . V_59 = F_16 ;
V_2 -> V_10 . V_2 . V_60 = & V_2 -> V_60 ;
F_32 ( & V_2 -> V_10 . V_2 , 65536 ) ;
F_33 ( & V_2 -> V_10 . V_2 , 0xffffffff ) ;
#ifdef F_34
V_2 -> V_10 . V_2 . V_57 = V_39 -> V_56 . V_61 -> V_2 . V_57 ;
V_2 -> V_10 . V_2 . V_62 = V_39 -> V_56 . V_61 -> V_2 . V_62 ;
#endif
#ifdef F_35
F_24 ( L_19 ,
V_2 , & V_2 -> V_10 , & V_2 -> V_10 . V_2 , & V_2 -> V_10 . V_2 . V_63 ) ;
#endif
if ( V_23 == V_39 -> V_36 ) {
F_36 ( & V_2 -> V_10 . V_2 , L_20 ,
V_39 -> V_56 . V_26 ,
#ifdef F_34
( unsigned int ) F_37 ( V_39 -> V_56 . V_61 , 0 ) ,
#else
0 ,
#endif
V_64 , V_23 -> V_29 ) ;
} else {
V_54 = F_38 ( V_23 , L_21 , NULL ) ;
F_36 ( & V_2 -> V_10 . V_2 , L_20 ,
V_39 -> V_56 . V_26 ,
V_54 ? * V_54 : 0 , V_64 , V_23 -> V_29 ) ;
}
F_25 ( V_2 ) ;
F_27 ( V_2 , V_46 ) ;
F_23 ( V_2 ) ;
if ( F_39 ( & V_2 -> V_10 ) != 0 ) {
F_24 ( V_65 L_22 ,
F_22 ( & V_2 -> V_10 . V_2 ) ) ;
F_17 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static int F_40 ( struct V_22 * V_23 )
{
if ( strncmp ( V_23 -> V_29 , L_23 , 7 ) == 0 )
return 1 ;
if ( strncmp ( V_23 -> V_29 , L_24 , 11 ) == 0 )
return 1 ;
return 0 ;
}
static void F_41 ( struct V_51 * V_39 )
{
struct V_22 * V_23 , * V_66 ;
struct V_8 * V_67 , * V_21 , * V_68 = NULL , * V_69 = NULL ;
struct V_1 * V_52 = NULL ;
struct V_24 * V_70 = & V_71 ;
#ifdef F_34
if ( V_39 -> V_56 . V_61 ) {
V_52 = & V_39 -> V_56 . V_61 -> V_2 ;
V_70 = & V_39 -> V_56 . V_61 -> V_24 [ 0 ] ;
}
#endif
V_66 = F_42 ( V_39 -> V_36 ) ;
if ( V_66 == NULL )
return;
V_67 = F_30 ( V_39 , V_52 , V_66 , NULL , V_70 ) ;
if ( V_67 == NULL )
return;
V_70 = & V_67 -> V_24 [ 0 ] ;
for ( V_23 = NULL ; ( V_23 = F_43 ( V_66 , V_23 ) ) != NULL ; ) {
if ( F_40 ( V_23 ) )
continue;
F_42 ( V_23 ) ;
V_21 = F_30 ( V_39 , & V_67 -> V_10 . V_2 , V_23 , NULL ,
V_70 ) ;
if ( V_21 == NULL )
F_44 ( V_23 ) ;
else if ( strncmp ( V_23 -> V_29 , L_6 , 9 ) == 0 )
V_68 = V_21 ;
else if ( strncmp ( V_23 -> V_29 , L_3 , 4 ) == 0 )
V_69 = V_21 ;
}
if ( V_68 ) {
V_66 = V_68 -> V_10 . V_2 . V_36 ;
for ( V_23 = NULL ; ( V_23 = F_43 ( V_66 , V_23 ) ) != NULL ; ) {
if ( F_40 ( V_23 ) )
continue;
F_42 ( V_23 ) ;
if ( F_30 ( V_39 , & V_68 -> V_10 . V_2 , V_23 ,
V_68 , V_70 ) == NULL )
F_44 ( V_23 ) ;
}
}
if ( V_69 ) {
V_66 = V_69 -> V_10 . V_2 . V_36 ;
for ( V_23 = NULL ; ( V_23 = F_43 ( V_66 , V_23 ) ) != NULL ; ) {
if ( F_40 ( V_23 ) )
continue;
F_42 ( V_23 ) ;
if ( F_30 ( V_39 , & V_69 -> V_10 . V_2 , V_23 ,
NULL , V_70 ) == NULL )
F_44 ( V_23 ) ;
}
}
}
int F_45 ( struct V_12 * V_4 )
{
V_4 -> V_14 . V_38 = & V_20 ;
return F_46 ( & V_4 -> V_14 ) ;
}
void F_47 ( struct V_12 * V_4 )
{
F_48 ( & V_4 -> V_14 ) ;
}
static void F_49 ( struct V_1 * V_72 , void * V_25 )
{
struct V_8 * V_2 = F_5 ( V_72 ) ;
struct V_73 * V_74 = V_25 ;
int V_43 , V_75 ;
V_75 = F_50 ( V_2 -> V_50 , 32 ) ;
for ( V_43 = 0 ; V_43 < V_75 ; V_43 ++ ) {
if ( V_74 -> V_76 & ( 1 << V_43 ) )
F_51 ( V_2 , V_43 ) ;
}
}
int F_52 ( struct V_8 * V_2 )
{
struct V_73 * V_74 ;
V_74 = F_53 ( & V_2 -> V_10 . V_2 , F_49 , NULL , NULL ) ;
if ( ! V_74 ) {
V_74 = F_54 ( F_49 , sizeof( * V_74 ) , V_55 ) ;
if ( ! V_74 )
return - V_77 ;
}
return F_55 ( & V_2 -> V_10 . V_2 , V_74 , NULL , NULL ) != NULL ;
}
static struct V_73 * F_56 ( struct V_8 * V_2 )
{
return F_53 ( & V_2 -> V_10 . V_2 , F_49 , NULL , NULL ) ;
}
int F_57 ( struct V_8 * V_2 , int V_78 ,
const char * V_29 )
{
struct V_73 * V_74 = F_56 ( V_2 ) ;
if ( F_58 ( V_2 , V_78 ) == 0 )
return 0 ;
if ( ! F_59 ( F_60 ( V_2 , V_78 ) ,
F_58 ( V_2 , V_78 ) ,
V_29 ) )
goto V_79;
if ( V_74 && V_78 < 32 )
V_74 -> V_76 |= 1 << V_78 ;
return 0 ;
V_79:
F_24 ( V_49 L_25
L_26 ,
V_78 ,
F_58 ( V_2 , V_78 ) ,
F_60 ( V_2 , V_78 ) ,
F_22 ( & V_2 -> V_10 . V_2 ) ) ;
return - V_80 ;
}
void F_51 ( struct V_8 * V_2 , int V_78 )
{
struct V_73 * V_74 = F_56 ( V_2 ) ;
if ( F_58 ( V_2 , V_78 ) == 0 )
return;
F_61 ( F_60 ( V_2 , V_78 ) ,
F_58 ( V_2 , V_78 ) ) ;
if ( V_74 && V_78 < 32 )
V_74 -> V_76 &= ~ ( 1 << V_78 ) ;
}
int F_62 ( struct V_8 * V_2 , const char * V_29 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_50 ; V_43 ++ )
if ( F_57 ( V_2 , V_43 , V_29 ) )
goto V_79;
return 0 ;
V_79:
while( -- V_43 >= 0 )
F_51 ( V_2 , V_43 ) ;
return - V_80 ;
}
void F_63 ( struct V_8 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_50 ; V_43 ++ )
F_51 ( V_2 , V_43 ) ;
}
static int F_64 ( struct V_81 * V_61 , const struct V_82 * V_83 )
{
struct V_22 * V_23 ;
struct V_51 * V_39 ;
if ( V_83 -> V_84 != V_85 )
return - V_11 ;
V_23 = F_65 ( V_61 ) ;
if ( V_23 == NULL )
return - V_11 ;
F_42 ( V_23 ) ;
V_39 = F_66 ( V_23 , V_86 ) ;
F_44 ( V_23 ) ;
if ( V_39 == NULL )
return - V_11 ;
if ( V_39 -> V_56 . V_61 == NULL ) {
V_39 -> V_56 . V_61 = V_61 ;
V_39 -> V_56 . V_39 = V_39 ;
F_67 ( V_61 , & V_39 -> V_56 ) ;
F_68 ( V_61 ) ;
}
F_24 ( V_41 L_27 ,
V_39 -> V_29 ) ;
if ( V_39 -> type == V_40 || V_39 -> type == V_87 )
if ( V_88 [ 0 ] . V_56 . V_61 == NULL ) {
V_89 = V_39 ;
return 0 ;
}
F_41 ( V_39 ) ;
if ( V_89 && V_88 [ 0 ] . V_56 . V_61 != NULL ) {
F_41 ( V_89 ) ;
V_89 = NULL ;
}
return 0 ;
}
static void F_69 ( struct V_81 * V_61 )
{
F_70 ( L_28 ) ;
}
static int T_2 F_71 ( void )
{
#ifdef F_34
int V_90 ;
V_90 = F_72 ( & V_91 ) ;
if ( V_90 )
return V_90 ;
#endif
return 0 ;
}
