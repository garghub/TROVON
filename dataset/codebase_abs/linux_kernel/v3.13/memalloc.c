static inline void F_1 ( int V_1 )
{
V_2 += 1 << V_1 ;
}
static inline void F_2 ( int V_1 )
{
V_2 -= 1 << V_1 ;
}
void * F_3 ( T_1 V_3 , T_2 V_4 )
{
int V_5 ;
void * V_6 ;
if ( F_4 ( ! V_3 ) )
return NULL ;
if ( F_4 ( ! V_4 ) )
return NULL ;
V_4 |= V_7 ;
V_5 = F_5 ( V_3 ) ;
if ( ( V_6 = ( void * ) F_6 ( V_4 , V_5 ) ) != NULL )
F_1 ( V_5 ) ;
return V_6 ;
}
void F_7 ( void * V_8 , T_1 V_3 )
{
int V_5 ;
if ( V_8 == NULL )
return;
V_5 = F_5 ( V_3 ) ;
F_2 ( V_5 ) ;
F_8 ( ( unsigned long ) V_8 , V_5 ) ;
}
static void * F_9 ( struct V_9 * V_10 , T_1 V_3 , T_3 * V_11 )
{
int V_5 ;
void * V_6 ;
T_2 V_4 ;
if ( F_4 ( ! V_11 ) )
return NULL ;
V_5 = F_5 ( V_3 ) ;
V_4 = V_12
| V_7
| V_13
| V_14 ;
V_6 = F_10 ( V_10 , V_15 << V_5 , V_11 , V_4 ) ;
if ( V_6 != NULL )
F_1 ( V_5 ) ;
return V_6 ;
}
static void F_11 ( struct V_9 * V_10 , T_1 V_3 , void * V_8 ,
T_3 V_11 )
{
int V_5 ;
if ( V_8 == NULL )
return;
V_5 = F_5 ( V_3 ) ;
F_2 ( V_5 ) ;
F_12 ( V_10 , V_15 << V_5 , V_8 , V_11 ) ;
}
static void F_13 ( struct V_16 * V_17 , T_1 V_3 )
{
struct V_9 * V_10 = V_17 -> V_10 . V_10 ;
struct V_18 * V_19 = NULL ;
V_17 -> V_20 = NULL ;
V_17 -> V_21 = 0 ;
if ( V_10 -> V_22 )
V_19 = F_14 ( V_10 -> V_22 , L_1 , 0 ) ;
if ( ! V_19 )
return;
V_17 -> V_23 = V_19 ;
V_17 -> V_20 = F_15 ( V_19 , V_3 , & V_17 -> V_21 ) ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_23 ;
if ( V_19 && V_17 -> V_20 )
F_17 ( V_19 , ( unsigned long ) V_17 -> V_20 , V_17 -> V_24 ) ;
}
int F_18 ( int type , struct V_9 * V_9 , T_1 V_3 ,
struct V_16 * V_17 )
{
if ( F_4 ( ! V_3 ) )
return - V_25 ;
if ( F_4 ( ! V_17 ) )
return - V_25 ;
V_17 -> V_10 . type = type ;
V_17 -> V_10 . V_10 = V_9 ;
V_17 -> V_24 = 0 ;
switch ( type ) {
case V_26 :
V_17 -> V_20 = F_3 ( V_3 ,
( V_27 T_2 ) ( unsigned long ) V_9 ) ;
V_17 -> V_21 = 0 ;
break;
#ifdef F_19
#ifdef F_20
case V_28 :
F_13 ( V_17 , V_3 ) ;
if ( V_17 -> V_20 )
break;
V_17 -> V_10 . type = V_29 ;
#endif
case V_29 :
V_17 -> V_20 = F_9 ( V_9 , V_3 , & V_17 -> V_21 ) ;
break;
#endif
#ifdef F_21
case V_30 :
F_22 ( V_9 , V_3 , V_17 , NULL ) ;
break;
#endif
default:
F_23 ( V_31 L_2 , type ) ;
V_17 -> V_20 = NULL ;
V_17 -> V_21 = 0 ;
return - V_25 ;
}
if ( ! V_17 -> V_20 )
return - V_32 ;
V_17 -> V_24 = V_3 ;
return 0 ;
}
int F_24 ( int type , struct V_9 * V_9 , T_1 V_3 ,
struct V_16 * V_17 )
{
int V_33 ;
while ( ( V_33 = F_18 ( type , V_9 , V_3 , V_17 ) ) < 0 ) {
T_1 V_34 ;
if ( V_33 != - V_32 )
return V_33 ;
if ( V_3 <= V_15 )
return - V_32 ;
V_34 = V_15 << F_5 ( V_3 ) ;
if ( V_3 != V_34 )
V_3 = V_34 ;
else
V_3 >>= 1 ;
}
if ( ! V_17 -> V_20 )
return - V_32 ;
return 0 ;
}
void F_25 ( struct V_16 * V_17 )
{
switch ( V_17 -> V_10 . type ) {
case V_26 :
F_7 ( V_17 -> V_20 , V_17 -> V_24 ) ;
break;
#ifdef F_19
#ifdef F_20
case V_28 :
F_16 ( V_17 ) ;
break;
#endif
case V_29 :
F_11 ( V_17 -> V_10 . V_10 , V_17 -> V_24 , V_17 -> V_20 , V_17 -> V_21 ) ;
break;
#endif
#ifdef F_21
case V_30 :
F_26 ( V_17 ) ;
break;
#endif
default:
F_23 ( V_31 L_2 , V_17 -> V_10 . type ) ;
}
}
T_1 F_27 ( struct V_16 * V_17 , unsigned int V_35 )
{
struct V_36 * V_37 ;
if ( F_4 ( ! V_17 ) )
return 0 ;
F_28 ( & V_38 ) ;
F_29 (mem, &mem_list_head, list) {
if ( V_37 -> V_35 == V_35 &&
( V_37 -> V_39 . V_10 . V_10 == NULL || V_17 -> V_10 . V_10 == NULL ||
! memcmp ( & V_37 -> V_39 . V_10 , & V_17 -> V_10 , sizeof( V_17 -> V_10 ) ) ) ) {
struct V_9 * V_10 = V_17 -> V_10 . V_10 ;
F_30 ( & V_37 -> V_40 ) ;
* V_17 = V_37 -> V_39 ;
if ( V_17 -> V_10 . V_10 == NULL )
V_17 -> V_10 . V_10 = V_10 ;
F_31 ( V_37 ) ;
F_32 ( & V_38 ) ;
return V_17 -> V_24 ;
}
}
F_32 ( & V_38 ) ;
return 0 ;
}
int F_33 ( struct V_16 * V_17 , unsigned int V_35 )
{
struct V_36 * V_37 ;
if ( F_4 ( ! V_17 ) )
return - V_41 ;
V_37 = F_34 ( sizeof( * V_37 ) , V_12 ) ;
if ( ! V_37 )
return - V_32 ;
F_28 ( & V_38 ) ;
V_37 -> V_39 = * V_17 ;
V_37 -> V_35 = V_35 ;
F_35 ( & V_37 -> V_40 , & V_42 ) ;
F_32 ( & V_38 ) ;
return 0 ;
}
static void F_36 ( void )
{
struct V_43 * V_44 ;
struct V_36 * V_37 ;
F_28 ( & V_38 ) ;
while ( ! F_37 ( & V_42 ) ) {
V_44 = V_42 . V_45 ;
V_37 = F_38 ( V_44 , struct V_36 , V_40 ) ;
F_30 ( V_44 ) ;
F_25 ( & V_37 -> V_39 ) ;
F_31 ( V_37 ) ;
}
F_32 ( & V_38 ) ;
}
static int F_39 ( struct V_46 * V_47 , void * V_48 )
{
long V_49 = V_2 >> ( V_50 - 12 ) ;
struct V_36 * V_37 ;
int V_51 ;
static char * V_52 [] = { L_3 , L_4 , L_5 , L_6 } ;
F_28 ( & V_38 ) ;
F_40 ( V_47 , L_7 ,
V_49 * V_15 , V_49 , V_15 / 1024 ) ;
V_51 = 0 ;
F_29 (mem, &mem_list_head, list) {
V_51 ++ ;
F_40 ( V_47 , L_8 ,
V_51 , V_37 -> V_35 , V_52 [ V_37 -> V_39 . V_10 . type ] ) ;
F_40 ( V_47 , L_9 ,
( unsigned long ) V_37 -> V_39 . V_21 ,
( int ) V_37 -> V_39 . V_24 ) ;
}
F_32 ( & V_38 ) ;
return 0 ;
}
static int F_41 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_42 ( V_54 , F_39 , NULL ) ;
}
static T_4 F_43 ( struct V_54 * V_54 , const char T_5 * V_39 ,
T_1 V_55 , T_6 * V_56 )
{
char V_57 [ 128 ] ;
char * V_58 , * V_44 ;
if ( V_55 > sizeof( V_57 ) - 1 )
return - V_41 ;
if ( F_44 ( V_57 , V_39 , V_55 ) )
return - V_59 ;
V_57 [ V_55 ] = '\0' ;
V_44 = V_57 ;
V_58 = F_45 ( & V_44 ) ;
if ( ! V_58 || * V_58 == '#' )
return V_55 ;
if ( strcmp ( V_58 , L_10 ) == 0 ) {
char * V_60 ;
int V_61 , V_9 , V_3 , V_62 ;
long V_63 ;
int V_64 , V_65 ;
struct V_66 * V_67 ;
if ( ( V_58 = F_45 ( & V_44 ) ) == NULL ||
( V_61 = F_46 ( V_58 , NULL , 0 ) ) <= 0 ||
( V_58 = F_45 ( & V_44 ) ) == NULL ||
( V_9 = F_46 ( V_58 , NULL , 0 ) ) <= 0 ||
( V_58 = F_45 ( & V_44 ) ) == NULL ||
( V_63 = F_46 ( V_58 , NULL , 0 ) ) < 0 ||
( V_58 = F_45 ( & V_44 ) ) == NULL ||
( V_3 = F_47 ( V_58 , & V_60 ) ) < 64 * 1024 ||
V_3 > 16 * 1024 * 1024 ||
( V_58 = F_45 ( & V_44 ) ) == NULL ||
( V_62 = F_46 ( V_58 , NULL , 0 ) ) <= 0 ||
V_62 > 4 ) {
F_23 ( V_31 L_11 ) ;
return V_55 ;
}
V_61 &= 0xffff ;
V_9 &= 0xffff ;
V_65 = 0 ;
V_67 = NULL ;
while ( ( V_67 = F_48 ( V_61 , V_9 , V_67 ) ) != NULL ) {
if ( V_63 > 0 && V_63 < 0xffffffff ) {
if ( F_49 ( V_67 , V_63 ) < 0 ||
F_50 ( V_67 , V_63 ) < 0 ) {
F_23 ( V_31 L_12 , V_63 , V_61 , V_9 ) ;
F_51 ( V_67 ) ;
return V_55 ;
}
}
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
if ( F_18 ( V_29 , F_52 ( V_67 ) ,
V_3 , & V_17 ) < 0 ) {
F_23 ( V_31 L_13 , V_3 ) ;
F_51 ( V_67 ) ;
return V_55 ;
}
F_33 ( & V_17 , F_53 ( V_67 ) ) ;
}
V_65 ++ ;
}
if ( ! V_65 ) {
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
if ( F_18 ( V_29 , NULL ,
V_3 , & V_17 ) < 0 ) {
F_23 ( V_31 L_13 , V_3 ) ;
break;
}
F_33 ( & V_17 , ( unsigned int ) ( ( V_61 << 16 ) | V_9 ) ) ;
}
}
} else if ( strcmp ( V_58 , L_14 ) == 0 )
F_36 () ;
else
F_23 ( V_31 L_15 ) ;
return V_55 ;
}
static int T_7 F_54 ( void )
{
#ifdef F_55
V_68 = F_56 ( V_69 , 0644 , NULL ,
& V_70 ) ;
#endif
return 0 ;
}
static void T_8 F_57 ( void )
{
F_58 ( V_69 , NULL ) ;
F_36 () ;
if ( V_2 > 0 )
F_23 ( V_31 L_16 , V_2 ) ;
}
