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
int F_13 ( int type , struct V_9 * V_9 , T_1 V_3 ,
struct V_16 * V_17 )
{
if ( F_4 ( ! V_3 ) )
return - V_18 ;
if ( F_4 ( ! V_17 ) )
return - V_18 ;
V_17 -> V_10 . type = type ;
V_17 -> V_10 . V_10 = V_9 ;
V_17 -> V_19 = 0 ;
switch ( type ) {
case V_20 :
V_17 -> V_21 = F_3 ( V_3 ,
( V_22 T_2 ) ( unsigned long ) V_9 ) ;
V_17 -> V_23 = 0 ;
break;
#ifdef F_14
case V_24 :
V_17 -> V_21 = F_9 ( V_9 , V_3 , & V_17 -> V_23 ) ;
break;
#endif
#ifdef F_15
case V_25 :
F_16 ( V_9 , V_3 , V_17 , NULL ) ;
break;
#endif
default:
F_17 ( V_26 L_1 , type ) ;
V_17 -> V_21 = NULL ;
V_17 -> V_23 = 0 ;
return - V_18 ;
}
if ( ! V_17 -> V_21 )
return - V_27 ;
V_17 -> V_19 = V_3 ;
return 0 ;
}
int F_18 ( int type , struct V_9 * V_9 , T_1 V_3 ,
struct V_16 * V_17 )
{
int V_28 ;
while ( ( V_28 = F_13 ( type , V_9 , V_3 , V_17 ) ) < 0 ) {
T_1 V_29 ;
if ( V_28 != - V_27 )
return V_28 ;
if ( V_3 <= V_15 )
return - V_27 ;
V_29 = V_15 << F_5 ( V_3 ) ;
if ( V_3 != V_29 )
V_3 = V_29 ;
else
V_3 >>= 1 ;
}
if ( ! V_17 -> V_21 )
return - V_27 ;
return 0 ;
}
void F_19 ( struct V_16 * V_17 )
{
switch ( V_17 -> V_10 . type ) {
case V_20 :
F_7 ( V_17 -> V_21 , V_17 -> V_19 ) ;
break;
#ifdef F_14
case V_24 :
F_11 ( V_17 -> V_10 . V_10 , V_17 -> V_19 , V_17 -> V_21 , V_17 -> V_23 ) ;
break;
#endif
#ifdef F_15
case V_25 :
F_20 ( V_17 ) ;
break;
#endif
default:
F_17 ( V_26 L_1 , V_17 -> V_10 . type ) ;
}
}
T_1 F_21 ( struct V_16 * V_17 , unsigned int V_30 )
{
struct V_31 * V_32 ;
if ( F_4 ( ! V_17 ) )
return 0 ;
F_22 ( & V_33 ) ;
F_23 (mem, &mem_list_head, list) {
if ( V_32 -> V_30 == V_30 &&
( V_32 -> V_34 . V_10 . V_10 == NULL || V_17 -> V_10 . V_10 == NULL ||
! memcmp ( & V_32 -> V_34 . V_10 , & V_17 -> V_10 , sizeof( V_17 -> V_10 ) ) ) ) {
struct V_9 * V_10 = V_17 -> V_10 . V_10 ;
F_24 ( & V_32 -> V_35 ) ;
* V_17 = V_32 -> V_34 ;
if ( V_17 -> V_10 . V_10 == NULL )
V_17 -> V_10 . V_10 = V_10 ;
F_25 ( V_32 ) ;
F_26 ( & V_33 ) ;
return V_17 -> V_19 ;
}
}
F_26 ( & V_33 ) ;
return 0 ;
}
int F_27 ( struct V_16 * V_17 , unsigned int V_30 )
{
struct V_31 * V_32 ;
if ( F_4 ( ! V_17 ) )
return - V_36 ;
V_32 = F_28 ( sizeof( * V_32 ) , V_12 ) ;
if ( ! V_32 )
return - V_27 ;
F_22 ( & V_33 ) ;
V_32 -> V_34 = * V_17 ;
V_32 -> V_30 = V_30 ;
F_29 ( & V_32 -> V_35 , & V_37 ) ;
F_26 ( & V_33 ) ;
return 0 ;
}
static void F_30 ( void )
{
struct V_38 * V_39 ;
struct V_31 * V_32 ;
F_22 ( & V_33 ) ;
while ( ! F_31 ( & V_37 ) ) {
V_39 = V_37 . V_40 ;
V_32 = F_32 ( V_39 , struct V_31 , V_35 ) ;
F_24 ( V_39 ) ;
F_19 ( & V_32 -> V_34 ) ;
F_25 ( V_32 ) ;
}
F_26 ( & V_33 ) ;
}
static int F_33 ( struct V_41 * V_42 , void * V_43 )
{
long V_44 = V_2 >> ( V_45 - 12 ) ;
struct V_31 * V_32 ;
int V_46 ;
static char * V_47 [] = { L_2 , L_3 , L_4 , L_5 } ;
F_22 ( & V_33 ) ;
F_34 ( V_42 , L_6 ,
V_44 * V_15 , V_44 , V_15 / 1024 ) ;
V_46 = 0 ;
F_23 (mem, &mem_list_head, list) {
V_46 ++ ;
F_34 ( V_42 , L_7 ,
V_46 , V_32 -> V_30 , V_47 [ V_32 -> V_34 . V_10 . type ] ) ;
F_34 ( V_42 , L_8 ,
( unsigned long ) V_32 -> V_34 . V_23 ,
( int ) V_32 -> V_34 . V_19 ) ;
}
F_26 ( & V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_36 ( V_49 , F_33 , NULL ) ;
}
static T_4 F_37 ( struct V_49 * V_49 , const char T_5 * V_34 ,
T_1 V_50 , T_6 * V_51 )
{
char V_52 [ 128 ] ;
char * V_53 , * V_39 ;
if ( V_50 > sizeof( V_52 ) - 1 )
return - V_36 ;
if ( F_38 ( V_52 , V_34 , V_50 ) )
return - V_54 ;
V_52 [ V_50 ] = '\0' ;
V_39 = V_52 ;
V_53 = F_39 ( & V_39 ) ;
if ( ! V_53 || * V_53 == '#' )
return V_50 ;
if ( strcmp ( V_53 , L_9 ) == 0 ) {
char * V_55 ;
int V_56 , V_9 , V_3 , V_57 ;
long V_58 ;
int V_59 , V_60 ;
struct V_61 * V_62 ;
if ( ( V_53 = F_39 ( & V_39 ) ) == NULL ||
( V_56 = F_40 ( V_53 , NULL , 0 ) ) <= 0 ||
( V_53 = F_39 ( & V_39 ) ) == NULL ||
( V_9 = F_40 ( V_53 , NULL , 0 ) ) <= 0 ||
( V_53 = F_39 ( & V_39 ) ) == NULL ||
( V_58 = F_40 ( V_53 , NULL , 0 ) ) < 0 ||
( V_53 = F_39 ( & V_39 ) ) == NULL ||
( V_3 = F_41 ( V_53 , & V_55 ) ) < 64 * 1024 ||
V_3 > 16 * 1024 * 1024 ||
( V_53 = F_39 ( & V_39 ) ) == NULL ||
( V_57 = F_40 ( V_53 , NULL , 0 ) ) <= 0 ||
V_57 > 4 ) {
F_17 ( V_26 L_10 ) ;
return V_50 ;
}
V_56 &= 0xffff ;
V_9 &= 0xffff ;
V_60 = 0 ;
V_62 = NULL ;
while ( ( V_62 = F_42 ( V_56 , V_9 , V_62 ) ) != NULL ) {
if ( V_58 > 0 && V_58 < 0xffffffff ) {
if ( F_43 ( V_62 , V_58 ) < 0 ||
F_44 ( V_62 , V_58 ) < 0 ) {
F_17 ( V_26 L_11 , V_58 , V_56 , V_9 ) ;
F_45 ( V_62 ) ;
return V_50 ;
}
}
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
if ( F_13 ( V_24 , F_46 ( V_62 ) ,
V_3 , & V_17 ) < 0 ) {
F_17 ( V_26 L_12 , V_3 ) ;
F_45 ( V_62 ) ;
return V_50 ;
}
F_27 ( & V_17 , F_47 ( V_62 ) ) ;
}
V_60 ++ ;
}
if ( ! V_60 ) {
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
if ( F_13 ( V_24 , NULL ,
V_3 , & V_17 ) < 0 ) {
F_17 ( V_26 L_12 , V_3 ) ;
break;
}
F_27 ( & V_17 , ( unsigned int ) ( ( V_56 << 16 ) | V_9 ) ) ;
}
}
} else if ( strcmp ( V_53 , L_13 ) == 0 )
F_30 () ;
else
F_17 ( V_26 L_14 ) ;
return V_50 ;
}
static int T_7 F_48 ( void )
{
#ifdef F_49
V_63 = F_50 ( V_64 , 0644 , NULL ,
& V_65 ) ;
#endif
return 0 ;
}
static void T_8 F_51 ( void )
{
F_52 ( V_64 , NULL ) ;
F_30 () ;
if ( V_2 > 0 )
F_17 ( V_26 L_15 , V_2 ) ;
}
