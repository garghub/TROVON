unsigned long F_1 ( T_1 * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
long V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_6 = F_2 ( ( void * ) V_2 - V_8 ) ;
if ( V_6 && F_3 ( V_6 ) ) {
V_4 = F_4 ( V_6 , struct V_3 , V_6 ) ;
if ( F_5 ( & V_4 -> V_10 ) )
goto V_11;
}
}
return V_2 ;
V_11:
if ( F_6 ( V_1 , ( void * ) V_2 ,
V_12 * sizeof( T_1 ) ) )
return 0UL ;
if ( V_2 == ( unsigned long ) V_6 -> V_2 ) {
V_1 [ 0 ] = V_6 -> V_13 ;
memcpy ( V_1 + 1 , V_4 -> V_14 . V_15 , V_16 ) ;
} else {
V_7 = V_2 - ( unsigned long ) V_6 -> V_2 - 1 ;
memcpy ( V_1 , V_4 -> V_14 . V_15 + V_7 , V_16 - V_7 ) ;
}
return ( unsigned long ) V_1 ;
}
static void F_7 ( T_1 * V_2 , unsigned long V_17 )
{
#ifdef F_8
* V_2 ++ = 0x48 ;
* V_2 ++ = 0xbf ;
#else
* V_2 ++ = 0xb8 ;
#endif
* ( unsigned long * ) V_2 = V_17 ;
}
static void
F_9 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
struct V_20 * V_21 = F_10 () ;
unsigned long V_22 ;
if ( F_11 ( & V_4 -> V_6 ) )
return;
F_12 ( V_22 ) ;
if ( F_13 () ) {
F_14 ( & V_4 -> V_6 ) ;
} else {
#ifdef F_8
V_19 -> V_23 = V_24 ;
#else
V_19 -> V_23 = V_24 | F_15 () ;
V_19 -> V_25 = 0 ;
#endif
V_19 -> V_26 = ( unsigned long ) V_4 -> V_6 . V_2 + V_27 ;
V_19 -> V_28 = ~ 0UL ;
F_16 ( V_29 , & V_4 -> V_6 ) ;
V_21 -> V_30 = V_31 ;
F_17 ( & V_4 -> V_6 , V_19 ) ;
F_16 ( V_29 , NULL ) ;
}
F_18 ( V_22 ) ;
}
static int F_19 ( T_2 * V_32 , T_2 * V_33 )
{
struct V_34 V_34 ;
int V_35 = 0 , V_36 ;
while ( V_35 < V_9 ) {
V_36 = F_20 ( V_32 + V_35 , V_33 + V_35 , & V_34 ) ;
if ( ! V_36 || ! F_21 ( & V_34 , V_33 + V_35 ) )
return - V_37 ;
V_35 += V_36 ;
}
if ( F_22 ( V_33 , V_33 + V_35 - 1 ) ||
F_23 ( V_33 , V_33 + V_35 - 1 ) ||
F_24 ( V_33 , V_33 + V_35 - 1 ) )
return - V_38 ;
return V_35 ;
}
static int F_25 ( struct V_34 * V_34 )
{
return ( ( V_34 -> V_13 . V_39 [ 0 ] == 0xff &&
( F_26 ( V_34 -> V_40 . V_41 ) & 6 ) == 4 ) ||
V_34 -> V_13 . V_39 [ 0 ] == 0xea ) ;
}
static int F_27 ( struct V_34 * V_34 , unsigned long V_42 , int V_35 )
{
unsigned long V_43 = 0 ;
switch ( V_34 -> V_13 . V_39 [ 0 ] ) {
case 0xe0 :
case 0xe1 :
case 0xe2 :
case 0xe3 :
case 0xe9 :
case 0xeb :
break;
case 0x0f :
if ( ( V_34 -> V_13 . V_39 [ 1 ] & 0xf0 ) == 0x80 )
break;
return 0 ;
default:
if ( ( V_34 -> V_13 . V_39 [ 0 ] & 0xf0 ) == 0x70 )
break;
return 0 ;
}
V_43 = ( unsigned long ) V_34 -> V_44 + V_34 -> V_45 . V_41 ;
return ( V_42 <= V_43 && V_43 <= V_42 + V_35 ) ;
}
static int F_28 ( unsigned long V_46 )
{
unsigned long V_2 , V_47 = 0 , V_48 = 0 ;
struct V_34 V_34 ;
T_1 V_1 [ V_12 ] ;
if ( ! F_29 ( V_46 , & V_47 , & V_48 ) )
return 0 ;
if ( ( V_46 >= ( unsigned long ) V_49 ) &&
( V_46 < ( unsigned long ) V_50 ) )
return 0 ;
if ( V_47 - V_48 < V_9 )
return 0 ;
V_2 = V_46 - V_48 ;
while ( V_2 < V_46 - V_48 + V_47 ) {
unsigned long V_51 ;
if ( F_30 ( V_2 ) )
return 0 ;
V_51 = F_31 ( V_1 , V_2 ) ;
if ( ! V_51 )
return 0 ;
F_32 ( & V_34 , ( void * ) V_51 , V_12 ) ;
F_33 ( & V_34 ) ;
if ( V_34 . V_13 . V_39 [ 0 ] == V_52 )
return 0 ;
V_34 . V_53 = ( void * ) V_2 ;
V_34 . V_44 = ( void * ) ( V_2 + V_34 . V_54 ) ;
if ( F_25 ( & V_34 ) ||
F_27 ( & V_34 , V_46 + V_27 ,
V_16 ) )
return 0 ;
V_2 += V_34 . V_54 ;
}
return 1 ;
}
int F_34 ( struct V_3 * V_4 )
{
int V_8 ;
struct V_5 * V_55 ;
for ( V_8 = 1 ; V_8 < V_4 -> V_14 . V_47 ; V_8 ++ ) {
V_55 = F_2 ( V_4 -> V_6 . V_2 + V_8 ) ;
if ( V_55 && ! F_11 ( V_55 ) )
return - V_56 ;
}
return 0 ;
}
int F_35 ( struct V_3 * V_4 ,
unsigned long V_2 )
{
return ( ( unsigned long ) V_4 -> V_6 . V_2 <= V_2 &&
( unsigned long ) V_4 -> V_6 . V_2 + V_4 -> V_14 . V_47 > V_2 ) ;
}
static
void F_36 ( struct V_3 * V_4 , int V_57 )
{
if ( V_4 -> V_14 . V_34 ) {
F_37 ( V_4 -> V_14 . V_34 , V_57 ) ;
V_4 -> V_14 . V_34 = NULL ;
V_4 -> V_14 . V_47 = 0 ;
}
}
void F_38 ( struct V_3 * V_4 )
{
F_36 ( V_4 , 1 ) ;
}
int F_39 ( struct V_3 * V_4 ,
struct V_5 * V_58 )
{
T_2 * V_1 ;
int V_36 ;
long V_59 ;
if ( ! F_28 ( ( unsigned long ) V_4 -> V_6 . V_2 ) )
return - V_60 ;
V_4 -> V_14 . V_34 = F_40 () ;
if ( ! V_4 -> V_14 . V_34 )
return - V_61 ;
V_59 = ( long ) V_4 -> V_14 . V_34 - ( long ) V_4 -> V_6 . V_2 + V_9 ;
if ( abs ( V_59 ) > 0x7fffffff ) {
F_36 ( V_4 , 0 ) ;
return - V_62 ;
}
V_1 = ( T_2 * ) V_4 -> V_14 . V_34 ;
F_41 ( ( unsigned long ) V_1 & V_63 , 1 ) ;
V_36 = F_19 ( V_1 + V_64 , V_4 -> V_6 . V_2 ) ;
if ( V_36 < 0 ) {
F_36 ( V_4 , 0 ) ;
return V_36 ;
}
V_4 -> V_14 . V_47 = V_36 ;
memcpy ( V_1 , & V_65 , V_64 ) ;
F_7 ( V_1 + V_66 , ( unsigned long ) V_4 ) ;
F_42 ( V_1 + V_67 , F_9 ) ;
F_43 ( V_1 + V_64 + V_4 -> V_14 . V_47 ,
( T_2 * ) V_4 -> V_6 . V_2 + V_4 -> V_14 . V_47 ) ;
F_44 ( ( unsigned long ) V_1 & V_63 , 1 ) ;
F_45 ( ( unsigned long ) V_1 ,
( unsigned long ) V_1 + V_64 +
V_4 -> V_14 . V_47 + V_9 ) ;
return 0 ;
}
void F_46 ( struct V_68 * V_69 )
{
struct V_3 * V_4 , * V_70 ;
T_2 V_71 [ V_9 ] ;
F_47 (op, tmp, oplist, list) {
T_3 V_59 = ( T_3 ) ( ( long ) V_4 -> V_14 . V_34 -
( ( long ) V_4 -> V_6 . V_2 + V_9 ) ) ;
F_48 ( F_11 ( & V_4 -> V_6 ) ) ;
memcpy ( V_4 -> V_14 . V_15 , V_4 -> V_6 . V_2 + V_27 ,
V_16 ) ;
V_71 [ 0 ] = V_72 ;
* ( T_3 * ) ( & V_71 [ 1 ] ) = V_59 ;
F_49 ( V_4 -> V_6 . V_2 , V_71 , V_9 ,
V_4 -> V_14 . V_34 ) ;
F_50 ( & V_4 -> V_10 ) ;
}
}
void F_51 ( struct V_3 * V_4 )
{
T_2 V_71 [ V_9 ] ;
V_71 [ 0 ] = V_52 ;
memcpy ( V_71 + 1 , V_4 -> V_14 . V_15 , V_16 ) ;
F_49 ( V_4 -> V_6 . V_2 , V_71 , V_9 ,
V_4 -> V_14 . V_34 ) ;
}
extern void F_52 ( struct V_68 * V_69 ,
struct V_68 * V_73 )
{
struct V_3 * V_4 , * V_70 ;
F_47 (op, tmp, oplist, list) {
F_51 ( V_4 ) ;
F_53 ( & V_4 -> V_10 , V_73 ) ;
}
}
int F_54 ( struct V_5 * V_55 , struct V_18 * V_19 , int V_74 )
{
struct V_3 * V_4 ;
if ( V_55 -> V_22 & V_75 ) {
V_4 = F_4 ( V_55 , struct V_3 , V_6 ) ;
V_19 -> V_26 = ( unsigned long ) V_4 -> V_14 . V_34 + V_64 ;
if ( ! V_74 )
F_55 () ;
F_56 () ;
return 1 ;
}
return 0 ;
}
