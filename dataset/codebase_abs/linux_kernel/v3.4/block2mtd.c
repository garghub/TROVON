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
if ( ! V_1 )
return - V_16 ;
if ( F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
V_15 = F_6 ( V_1 ) + V_17 ;
for ( V_14 = F_6 ( V_1 ) ; V_14 < V_15 ; V_14 ++ )
if ( * V_14 != - 1UL ) {
F_7 ( V_1 ) ;
memset ( F_6 ( V_1 ) , 0xff , V_17 ) ;
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
break;
}
F_10 ( V_1 ) ;
V_13 -- ;
V_4 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_5 * V_6 = V_19 -> V_22 ;
T_2 V_23 = V_21 -> V_24 ;
T_2 V_8 = V_21 -> V_8 ;
int V_25 ;
V_21 -> V_26 = V_27 ;
F_12 ( & V_6 -> V_28 ) ;
V_25 = F_3 ( V_6 , V_23 , V_8 ) ;
F_13 ( & V_6 -> V_28 ) ;
if ( V_25 ) {
ERROR ( L_1 , V_25 ) ;
V_21 -> V_26 = V_29 ;
} else
V_21 -> V_26 = V_30 ;
F_14 ( V_21 ) ;
return V_25 ;
}
static int F_15 ( struct V_18 * V_19 , T_1 V_23 , T_2 V_8 ,
T_2 * V_31 , T_4 * V_32 )
{
struct V_5 * V_6 = V_19 -> V_22 ;
struct V_1 * V_1 ;
int V_4 = V_23 >> V_12 ;
int V_33 = V_23 & ( V_17 - 1 ) ;
int V_34 ;
while ( V_8 ) {
if ( ( V_33 + V_8 ) > V_17 )
V_34 = V_17 - V_33 ;
else
V_34 = V_8 ;
V_8 = V_8 - V_34 ;
V_1 = F_1 ( V_6 -> V_9 -> V_10 -> V_11 , V_4 ) ;
if ( ! V_1 )
return - V_16 ;
if ( F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
memcpy ( V_32 , F_6 ( V_1 ) + V_33 , V_34 ) ;
F_10 ( V_1 ) ;
if ( V_31 )
* V_31 += V_34 ;
V_32 += V_34 ;
V_33 = 0 ;
V_4 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , const T_4 * V_32 ,
T_1 V_7 , T_2 V_8 , T_2 * V_31 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 = V_6 -> V_9 -> V_10 -> V_11 ;
int V_4 = V_7 >> V_12 ;
int V_33 = V_7 & ~ V_35 ;
int V_34 ;
while ( V_8 ) {
if ( ( V_33 + V_8 ) > V_17 )
V_34 = V_17 - V_33 ;
else
V_34 = V_8 ;
V_8 = V_8 - V_34 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( ! V_1 )
return - V_16 ;
if ( F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
if ( memcmp ( F_6 ( V_1 ) + V_33 , V_32 , V_34 ) ) {
F_7 ( V_1 ) ;
memcpy ( F_6 ( V_1 ) + V_33 , V_32 , V_34 ) ;
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
}
F_10 ( V_1 ) ;
if ( V_31 )
* V_31 += V_34 ;
V_32 += V_34 ;
V_33 = 0 ;
V_4 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_18 * V_19 , T_1 V_7 , T_2 V_8 ,
T_2 * V_31 , const T_4 * V_32 )
{
struct V_5 * V_6 = V_19 -> V_22 ;
int V_25 ;
F_12 ( & V_6 -> V_28 ) ;
V_25 = F_16 ( V_6 , V_32 , V_7 , V_8 , V_31 ) ;
F_13 ( & V_6 -> V_28 ) ;
if ( V_25 > 0 )
V_25 = 0 ;
return V_25 ;
}
static void F_18 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_22 ;
F_19 ( V_6 -> V_9 ) ;
return;
}
static void F_20 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_21 ( V_6 -> V_19 . V_36 ) ;
if ( V_6 -> V_9 ) {
F_22 ( V_6 -> V_9 -> V_10 -> V_11 ,
0 , - 1 ) ;
F_23 ( V_6 -> V_9 , V_37 | V_38 | V_39 ) ;
}
F_21 ( V_6 ) ;
}
static struct V_5 * F_24 ( char * V_40 , int V_41 )
{
const T_5 V_42 = V_37 | V_38 | V_39 ;
struct V_43 * V_44 ;
struct V_5 * V_6 ;
char * V_36 ;
if ( ! V_40 )
return NULL ;
V_6 = F_25 ( sizeof( struct V_5 ) , V_45 ) ;
if ( ! V_6 )
return NULL ;
V_44 = F_26 ( V_40 , V_42 , V_6 ) ;
#ifndef F_27
if ( F_4 ( V_44 ) ) {
T_6 V_46 = F_28 ( V_40 ) ;
if ( V_46 )
V_44 = F_29 ( V_46 , V_42 , V_6 ) ;
}
#endif
if ( F_4 ( V_44 ) ) {
ERROR ( L_2 , V_40 ) ;
goto V_47;
}
V_6 -> V_9 = V_44 ;
if ( F_30 ( V_44 -> V_48 ) == V_49 ) {
ERROR ( L_3 ) ;
goto V_47;
}
F_31 ( & V_6 -> V_28 ) ;
V_36 = F_32 ( V_45 , L_4 , V_40 ) ;
if ( ! V_36 )
goto V_47;
V_6 -> V_19 . V_36 = V_36 ;
V_6 -> V_19 . V_50 = V_6 -> V_9 -> V_10 -> V_51 & V_35 ;
V_6 -> V_19 . V_52 = V_41 ;
V_6 -> V_19 . V_53 = 1 ;
V_6 -> V_19 . V_54 = V_17 ;
V_6 -> V_19 . type = V_55 ;
V_6 -> V_19 . V_56 = V_57 ;
V_6 -> V_19 . V_58 = F_11 ;
V_6 -> V_19 . V_59 = F_17 ;
V_6 -> V_19 . V_60 = V_61 ;
V_6 -> V_19 . V_62 = F_18 ;
V_6 -> V_19 . V_63 = F_15 ;
V_6 -> V_19 . V_22 = V_6 ;
V_6 -> V_19 . V_64 = V_65 ;
if ( F_33 ( & V_6 -> V_19 , NULL , 0 ) ) {
goto V_47;
}
F_34 ( & V_6 -> V_66 , & V_67 ) ;
F_35 ( L_5 , V_6 -> V_19 . V_4 ,
V_6 -> V_19 . V_36 + strlen ( L_6 ) ,
V_6 -> V_19 . V_52 >> 10 , V_6 -> V_19 . V_52 ) ;
return V_6 ;
V_47:
F_20 ( V_6 ) ;
return NULL ;
}
static int F_36 ( const char * V_68 , char * * V_69 , unsigned int V_70 )
{
unsigned long V_71 = F_37 ( V_68 , V_69 , V_70 ) ;
switch ( * * V_69 ) {
case 'G' :
V_71 *= 1024 ;
case 'M' :
V_71 *= 1024 ;
case 'K' :
case 'k' :
V_71 *= 1024 ;
if ( ( * V_69 ) [ 1 ] == 'i' ) {
if ( ( * V_69 ) [ 2 ] == 'B' )
( * V_69 ) += 3 ;
else
( * V_69 ) += 2 ;
}
}
return V_71 ;
}
static int F_38 ( T_2 * V_72 , const char * V_73 )
{
char * V_69 ;
T_2 V_74 ;
V_74 = ( T_2 ) F_36 ( V_73 , & V_69 , 0 ) ;
if ( * V_69 )
return - V_75 ;
* V_72 = V_74 ;
return 0 ;
}
static inline void F_39 ( char * V_76 )
{
char * V_77 = strrchr ( V_76 , '\n' ) ;
if ( V_77 && ! V_77 [ 1 ] )
* V_77 = 0 ;
}
static int F_40 ( const char * V_78 )
{
char V_32 [ 80 + 12 ] ;
char * V_76 = V_32 ;
char * V_73 [ 2 ] ;
char * V_36 ;
T_2 V_41 = V_17 ;
int V_79 , V_80 ;
if ( F_41 ( V_78 , sizeof( V_32 ) ) >= sizeof( V_32 ) )
F_42 ( L_7 ) ;
strcpy ( V_76 , V_78 ) ;
F_39 ( V_76 ) ;
for ( V_79 = 0 ; V_79 < 2 ; V_79 ++ )
V_73 [ V_79 ] = F_43 ( & V_76 , L_8 ) ;
if ( V_76 )
F_42 ( L_9 ) ;
if ( ! V_73 [ 0 ] )
F_42 ( L_10 ) ;
V_36 = V_73 [ 0 ] ;
if ( strlen ( V_36 ) + 1 > 80 )
F_42 ( L_11 ) ;
if ( V_73 [ 1 ] ) {
V_80 = F_38 ( & V_41 , V_73 [ 1 ] ) ;
if ( V_80 ) {
F_42 ( L_12 ) ;
}
}
F_24 ( V_36 , V_41 ) ;
return 0 ;
}
static int F_44 ( const char * V_78 , struct V_81 * V_82 )
{
#ifdef F_27
return F_40 ( V_78 ) ;
#else
if ( V_83 )
return F_40 ( V_78 ) ;
F_45 ( V_84 , V_78 , sizeof( V_84 ) ) ;
return 0 ;
#endif
}
static int T_7 F_46 ( void )
{
int V_80 = 0 ;
#ifndef F_27
if ( strlen ( V_84 ) )
V_80 = F_40 ( V_84 ) ;
V_83 = 1 ;
#endif
return V_80 ;
}
static void T_8 F_47 ( void )
{
struct V_85 * V_86 , * V_87 ;
F_48 (pos, next, &blkmtd_device_list) {
struct V_5 * V_6 = F_49 ( V_86 , F_50 ( * V_6 ) , V_66 ) ;
F_18 ( & V_6 -> V_19 ) ;
F_51 ( & V_6 -> V_19 ) ;
F_35 ( L_13 , V_6 -> V_19 . V_4 ,
V_6 -> V_19 . V_36 + strlen ( L_6 ) ) ;
F_52 ( & V_6 -> V_66 ) ;
F_20 ( V_6 ) ;
}
}
