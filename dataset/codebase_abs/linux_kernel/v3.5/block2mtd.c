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
break;
}
F_10 ( V_1 ) ;
V_13 -- ;
V_4 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
T_2 V_22 = V_20 -> V_23 ;
T_2 V_8 = V_20 -> V_8 ;
int V_24 ;
V_20 -> V_25 = V_26 ;
F_12 ( & V_6 -> V_27 ) ;
V_24 = F_3 ( V_6 , V_22 , V_8 ) ;
F_13 ( & V_6 -> V_27 ) ;
if ( V_24 ) {
ERROR ( L_1 , V_24 ) ;
V_20 -> V_25 = V_28 ;
} else
V_20 -> V_25 = V_29 ;
F_14 ( V_20 ) ;
return V_24 ;
}
static int F_15 ( struct V_17 * V_18 , T_1 V_22 , T_2 V_8 ,
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
F_10 ( V_1 ) ;
if ( V_30 )
* V_30 += V_33 ;
V_31 += V_33 ;
V_32 = 0 ;
V_4 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , const T_4 * V_31 ,
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
}
F_10 ( V_1 ) ;
if ( V_30 )
* V_30 += V_33 ;
V_31 += V_33 ;
V_32 = 0 ;
V_4 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_17 * V_18 , T_1 V_7 , T_2 V_8 ,
T_2 * V_30 , const T_4 * V_31 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
int V_24 ;
F_12 ( & V_6 -> V_27 ) ;
V_24 = F_16 ( V_6 , V_31 , V_7 , V_8 , V_30 ) ;
F_13 ( & V_6 -> V_27 ) ;
if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_21 ;
F_19 ( V_6 -> V_9 ) ;
return;
}
static void F_20 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_21 ( V_6 -> V_18 . V_35 ) ;
if ( V_6 -> V_9 ) {
F_22 ( V_6 -> V_9 -> V_10 -> V_11 ,
0 , - 1 ) ;
F_23 ( V_6 -> V_9 , V_36 | V_37 | V_38 ) ;
}
F_21 ( V_6 ) ;
}
static struct V_5 * F_24 ( char * V_39 , int V_40 )
{
const T_5 V_41 = V_36 | V_37 | V_38 ;
struct V_42 * V_43 ;
struct V_5 * V_6 ;
char * V_35 ;
if ( ! V_39 )
return NULL ;
V_6 = F_25 ( sizeof( struct V_5 ) , V_44 ) ;
if ( ! V_6 )
return NULL ;
V_43 = F_26 ( V_39 , V_41 , V_6 ) ;
#ifndef F_27
if ( F_4 ( V_43 ) ) {
T_6 V_45 = F_28 ( V_39 ) ;
if ( V_45 )
V_43 = F_29 ( V_45 , V_41 , V_6 ) ;
}
#endif
if ( F_4 ( V_43 ) ) {
ERROR ( L_2 , V_39 ) ;
goto V_46;
}
V_6 -> V_9 = V_43 ;
if ( F_30 ( V_43 -> V_47 ) == V_48 ) {
ERROR ( L_3 ) ;
goto V_46;
}
F_31 ( & V_6 -> V_27 ) ;
V_35 = F_32 ( V_44 , L_4 , V_39 ) ;
if ( ! V_35 )
goto V_46;
V_6 -> V_18 . V_35 = V_35 ;
V_6 -> V_18 . V_49 = V_6 -> V_9 -> V_10 -> V_50 & V_34 ;
V_6 -> V_18 . V_51 = V_40 ;
V_6 -> V_18 . V_52 = 1 ;
V_6 -> V_18 . V_53 = V_16 ;
V_6 -> V_18 . type = V_54 ;
V_6 -> V_18 . V_55 = V_56 ;
V_6 -> V_18 . V_57 = F_11 ;
V_6 -> V_18 . V_58 = F_17 ;
V_6 -> V_18 . V_59 = F_18 ;
V_6 -> V_18 . V_60 = F_15 ;
V_6 -> V_18 . V_21 = V_6 ;
V_6 -> V_18 . V_61 = V_62 ;
if ( F_33 ( & V_6 -> V_18 , NULL , 0 ) ) {
goto V_46;
}
F_34 ( & V_6 -> V_63 , & V_64 ) ;
F_35 ( L_5 , V_6 -> V_18 . V_4 ,
V_6 -> V_18 . V_35 + strlen ( L_6 ) ,
V_6 -> V_18 . V_51 >> 10 , V_6 -> V_18 . V_51 ) ;
return V_6 ;
V_46:
F_20 ( V_6 ) ;
return NULL ;
}
static int F_36 ( const char * V_65 , char * * V_66 , unsigned int V_67 )
{
unsigned long V_68 = F_37 ( V_65 , V_66 , V_67 ) ;
switch ( * * V_66 ) {
case 'G' :
V_68 *= 1024 ;
case 'M' :
V_68 *= 1024 ;
case 'K' :
case 'k' :
V_68 *= 1024 ;
if ( ( * V_66 ) [ 1 ] == 'i' ) {
if ( ( * V_66 ) [ 2 ] == 'B' )
( * V_66 ) += 3 ;
else
( * V_66 ) += 2 ;
}
}
return V_68 ;
}
static int F_38 ( T_2 * V_69 , const char * V_70 )
{
char * V_66 ;
T_2 V_71 ;
V_71 = ( T_2 ) F_36 ( V_70 , & V_66 , 0 ) ;
if ( * V_66 )
return - V_72 ;
* V_69 = V_71 ;
return 0 ;
}
static inline void F_39 ( char * V_73 )
{
char * V_74 = strrchr ( V_73 , '\n' ) ;
if ( V_74 && ! V_74 [ 1 ] )
* V_74 = 0 ;
}
static int F_40 ( const char * V_75 )
{
char V_31 [ 80 + 12 ] ;
char * V_73 = V_31 ;
char * V_70 [ 2 ] ;
char * V_35 ;
T_2 V_40 = V_16 ;
int V_76 , V_77 ;
if ( F_41 ( V_75 , sizeof( V_31 ) ) >= sizeof( V_31 ) )
F_42 ( L_7 ) ;
strcpy ( V_73 , V_75 ) ;
F_39 ( V_73 ) ;
for ( V_76 = 0 ; V_76 < 2 ; V_76 ++ )
V_70 [ V_76 ] = F_43 ( & V_73 , L_8 ) ;
if ( V_73 )
F_42 ( L_9 ) ;
if ( ! V_70 [ 0 ] )
F_42 ( L_10 ) ;
V_35 = V_70 [ 0 ] ;
if ( strlen ( V_35 ) + 1 > 80 )
F_42 ( L_11 ) ;
if ( V_70 [ 1 ] ) {
V_77 = F_38 ( & V_40 , V_70 [ 1 ] ) ;
if ( V_77 ) {
F_42 ( L_12 ) ;
}
}
F_24 ( V_35 , V_40 ) ;
return 0 ;
}
static int F_44 ( const char * V_75 , struct V_78 * V_79 )
{
#ifdef F_27
return F_40 ( V_75 ) ;
#else
if ( V_80 )
return F_40 ( V_75 ) ;
F_45 ( V_81 , V_75 , sizeof( V_81 ) ) ;
return 0 ;
#endif
}
static int T_7 F_46 ( void )
{
int V_77 = 0 ;
#ifndef F_27
if ( strlen ( V_81 ) )
V_77 = F_40 ( V_81 ) ;
V_80 = 1 ;
#endif
return V_77 ;
}
static void T_8 F_47 ( void )
{
struct V_82 * V_83 , * V_84 ;
F_48 (pos, next, &blkmtd_device_list) {
struct V_5 * V_6 = F_49 ( V_83 , F_50 ( * V_6 ) , V_63 ) ;
F_18 ( & V_6 -> V_18 ) ;
F_51 ( & V_6 -> V_18 ) ;
F_35 ( L_13 , V_6 -> V_18 . V_4 ,
V_6 -> V_18 . V_35 + strlen ( L_6 ) ) ;
F_52 ( & V_6 -> V_63 ) ;
F_20 ( V_6 ) ;
}
}
