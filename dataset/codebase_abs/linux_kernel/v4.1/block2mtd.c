static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
return F_2 ( V_3 , V_4 , NULL ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 )
{
struct V_2 * V_3 = V_6 -> V_9 -> V_10 -> V_11 ;
struct V_1 * V_1 ;
int V_4 = V_7 >> V_12 ;
int V_13 = V_8 >> V_12 ;
T_3 * V_14 ;
T_3 * V_15 ;
while ( V_13 ) {
V_1 = F_1 ( V_3 , V_4 ) ;
if ( F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
V_15 = F_6 ( V_1 ) + V_16 ;
for ( V_14 = F_6 ( V_1 ) ; V_14 < V_15 ; V_14 ++ )
if ( * V_14 != - 1UL ) {
F_7 ( V_1 ) ;
memset ( F_6 ( V_1 ) , 0xff , V_16 ) ;
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_3 ) ;
break;
}
F_11 ( V_1 ) ;
V_13 -- ;
V_4 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
T_2 V_22 = V_20 -> V_23 ;
T_2 V_8 = V_20 -> V_8 ;
int V_24 ;
V_20 -> V_25 = V_26 ;
F_13 ( & V_6 -> V_27 ) ;
V_24 = F_3 ( V_6 , V_22 , V_8 ) ;
F_14 ( & V_6 -> V_27 ) ;
if ( V_24 ) {
F_15 ( L_1 , V_24 ) ;
V_20 -> V_25 = V_28 ;
} else
V_20 -> V_25 = V_29 ;
F_16 ( V_20 ) ;
return V_24 ;
}
static int F_17 ( struct V_17 * V_18 , T_1 V_22 , T_2 V_8 ,
T_2 * V_30 , T_4 * V_31 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
struct V_1 * V_1 ;
int V_4 = V_22 >> V_12 ;
int V_32 = V_22 & ( V_16 - 1 ) ;
int V_33 ;
while ( V_8 ) {
if ( ( V_32 + V_8 ) > V_16 )
V_33 = V_16 - V_32 ;
else
V_33 = V_8 ;
V_8 = V_8 - V_33 ;
V_1 = F_1 ( V_6 -> V_9 -> V_10 -> V_11 , V_4 ) ;
if ( F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
memcpy ( V_31 , F_6 ( V_1 ) + V_32 , V_33 ) ;
F_11 ( V_1 ) ;
if ( V_30 )
* V_30 += V_33 ;
V_31 += V_33 ;
V_32 = 0 ;
V_4 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_5 * V_6 , const T_4 * V_31 ,
T_1 V_7 , T_2 V_8 , T_2 * V_30 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 = V_6 -> V_9 -> V_10 -> V_11 ;
int V_4 = V_7 >> V_12 ;
int V_32 = V_7 & ~ V_34 ;
int V_33 ;
while ( V_8 ) {
if ( ( V_32 + V_8 ) > V_16 )
V_33 = V_16 - V_32 ;
else
V_33 = V_8 ;
V_8 = V_8 - V_33 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
if ( memcmp ( F_6 ( V_1 ) + V_32 , V_31 , V_33 ) ) {
F_7 ( V_1 ) ;
memcpy ( F_6 ( V_1 ) + V_32 , V_31 , V_33 ) ;
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_3 ) ;
}
F_11 ( V_1 ) ;
if ( V_30 )
* V_30 += V_33 ;
V_31 += V_33 ;
V_32 = 0 ;
V_4 ++ ;
}
return 0 ;
}
static int F_19 ( struct V_17 * V_18 , T_1 V_7 , T_2 V_8 ,
T_2 * V_30 , const T_4 * V_31 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
int V_24 ;
F_13 ( & V_6 -> V_27 ) ;
V_24 = F_18 ( V_6 , V_31 , V_7 , V_8 , V_30 ) ;
F_14 ( & V_6 -> V_27 ) ;
if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static void F_20 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
F_21 ( V_6 -> V_9 ) ;
return;
}
static void F_22 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_23 ( V_6 -> V_18 . V_35 ) ;
if ( V_6 -> V_9 ) {
F_24 ( V_6 -> V_9 -> V_10 -> V_11 ,
0 , - 1 ) ;
F_25 ( V_6 -> V_9 , V_36 | V_37 | V_38 ) ;
}
F_23 ( V_6 ) ;
}
static struct V_5 * F_26 ( char * V_39 , int V_40 ,
int V_41 )
{
#ifndef F_27
int V_42 ;
#endif
const T_5 V_43 = V_36 | V_37 | V_38 ;
struct V_44 * V_45 = F_28 ( - V_46 ) ;
struct V_5 * V_6 ;
char * V_35 ;
if ( ! V_39 )
return NULL ;
V_6 = F_29 ( sizeof( struct V_5 ) , V_47 ) ;
if ( ! V_6 )
return NULL ;
V_45 = F_30 ( V_39 , V_43 , V_6 ) ;
#ifndef F_27
for ( V_42 = 0 ; F_4 ( V_45 ) && V_42 <= V_41 ; V_42 ++ ) {
T_6 V_48 ;
if ( V_42 )
F_31 ( 1000 ) ;
F_32 () ;
V_48 = F_33 ( V_39 ) ;
if ( ! V_48 )
continue;
V_45 = F_34 ( V_48 , V_43 , V_6 ) ;
}
#endif
if ( F_4 ( V_45 ) ) {
F_15 ( L_2 , V_39 ) ;
goto V_49;
}
V_6 -> V_9 = V_45 ;
if ( F_35 ( V_45 -> V_50 ) == V_51 ) {
F_15 ( L_3 ) ;
goto V_49;
}
if ( ( long ) V_6 -> V_9 -> V_10 -> V_52 % V_40 ) {
F_15 ( L_4 ) ;
goto V_49;
}
F_36 ( & V_6 -> V_27 ) ;
V_35 = F_37 ( V_47 , L_5 , V_39 ) ;
if ( ! V_35 )
goto V_53;
V_6 -> V_18 . V_35 = V_35 ;
V_6 -> V_18 . V_54 = V_6 -> V_9 -> V_10 -> V_52 & V_34 ;
V_6 -> V_18 . V_55 = V_40 ;
V_6 -> V_18 . V_56 = 1 ;
V_6 -> V_18 . V_57 = V_16 ;
V_6 -> V_18 . type = V_58 ;
V_6 -> V_18 . V_59 = V_60 ;
V_6 -> V_18 . V_61 = F_12 ;
V_6 -> V_18 . V_62 = F_19 ;
V_6 -> V_18 . V_63 = F_20 ;
V_6 -> V_18 . V_64 = F_17 ;
V_6 -> V_18 . V_21 = V_6 ;
V_6 -> V_18 . V_65 = V_66 ;
if ( F_38 ( & V_6 -> V_18 , NULL , 0 ) ) {
goto V_53;
}
F_39 ( & V_6 -> V_67 , & V_68 ) ;
F_40 ( L_6 ,
V_6 -> V_18 . V_4 ,
V_6 -> V_18 . V_35 + strlen ( L_7 ) ,
V_6 -> V_18 . V_55 >> 10 , V_6 -> V_18 . V_55 ) ;
return V_6 ;
V_53:
F_41 ( & V_6 -> V_27 ) ;
V_49:
F_22 ( V_6 ) ;
return NULL ;
}
static int F_42 ( const char * V_69 , char * * V_70 , unsigned int V_71 )
{
unsigned long V_72 = F_43 ( V_69 , V_70 , V_71 ) ;
switch ( * * V_70 ) {
case 'G' :
V_72 *= 1024 ;
case 'M' :
V_72 *= 1024 ;
case 'K' :
case 'k' :
V_72 *= 1024 ;
if ( ( * V_70 ) [ 1 ] == 'i' ) {
if ( ( * V_70 ) [ 2 ] == 'B' )
( * V_70 ) += 3 ;
else
( * V_70 ) += 2 ;
}
}
return V_72 ;
}
static int F_44 ( T_2 * V_73 , const char * V_74 )
{
char * V_70 ;
T_2 V_75 ;
V_75 = ( T_2 ) F_42 ( V_74 , & V_70 , 0 ) ;
if ( * V_70 )
return - V_76 ;
* V_73 = V_75 ;
return 0 ;
}
static inline void F_45 ( char * V_77 )
{
char * V_78 = strrchr ( V_77 , '\n' ) ;
if ( V_78 && ! V_78 [ 1 ] )
* V_78 = 0 ;
}
static int F_46 ( const char * V_79 )
{
char V_31 [ 80 + 12 + 80 + 8 ] ;
char * V_77 = V_31 ;
char * V_74 [ 2 ] ;
char * V_35 ;
T_2 V_40 = V_16 ;
unsigned long V_41 = V_80 ;
int V_42 , V_81 ;
if ( F_47 ( V_79 , sizeof( V_31 ) ) >= sizeof( V_31 ) ) {
F_15 ( L_8 ) ;
return 0 ;
}
strcpy ( V_77 , V_79 ) ;
F_45 ( V_77 ) ;
for ( V_42 = 0 ; V_42 < 2 ; V_42 ++ )
V_74 [ V_42 ] = F_48 ( & V_77 , L_9 ) ;
if ( V_77 ) {
F_15 ( L_10 ) ;
return 0 ;
}
if ( ! V_74 [ 0 ] ) {
F_15 ( L_11 ) ;
return 0 ;
}
V_35 = V_74 [ 0 ] ;
if ( strlen ( V_35 ) + 1 > 80 ) {
F_15 ( L_12 ) ;
return 0 ;
}
if ( V_74 [ 1 ] ) {
V_81 = F_44 ( & V_40 , V_74 [ 1 ] ) ;
if ( V_81 ) {
F_15 ( L_13 ) ;
return 0 ;
}
}
F_26 ( V_35 , V_40 , V_41 ) ;
return 0 ;
}
static int F_49 ( const char * V_79 , struct V_82 * V_83 )
{
#ifdef F_27
return F_46 ( V_79 ) ;
#else
if ( V_84 )
return F_46 ( V_79 ) ;
F_50 ( V_85 , V_79 , sizeof( V_85 ) ) ;
return 0 ;
#endif
}
static int T_7 F_51 ( void )
{
int V_81 = 0 ;
#ifndef F_27
if ( strlen ( V_85 ) )
V_81 = F_46 ( V_85 ) ;
V_84 = 1 ;
#endif
return V_81 ;
}
static void F_52 ( void )
{
struct V_86 * V_87 , * V_88 ;
F_53 (pos, next, &blkmtd_device_list) {
struct V_5 * V_6 = F_54 ( V_87 , F_55 ( * V_6 ) , V_67 ) ;
F_20 ( & V_6 -> V_18 ) ;
F_56 ( & V_6 -> V_18 ) ;
F_41 ( & V_6 -> V_27 ) ;
F_40 ( L_14 ,
V_6 -> V_18 . V_4 ,
V_6 -> V_18 . V_35 + strlen ( L_7 ) ) ;
F_57 ( & V_6 -> V_67 ) ;
F_22 ( V_6 ) ;
}
}
