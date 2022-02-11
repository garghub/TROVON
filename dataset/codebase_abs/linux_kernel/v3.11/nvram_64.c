static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
int V_4 ;
if ( V_5 . V_6 == NULL )
return - V_7 ;
V_4 = V_5 . V_6 () ;
switch ( V_3 ) {
case 1 :
V_2 += V_1 -> V_8 ;
break;
case 2 :
V_2 += V_4 ;
break;
}
if ( V_2 < 0 )
return - V_9 ;
V_1 -> V_8 = V_2 ;
return V_1 -> V_8 ;
}
static T_2 F_2 ( struct V_1 * V_1 , char T_3 * V_10 ,
T_4 V_11 , T_1 * V_12 )
{
T_2 V_13 ;
char * V_14 = NULL ;
T_2 V_4 ;
if ( ! V_5 . V_6 ) {
V_13 = - V_7 ;
goto V_15;
}
V_4 = V_5 . V_6 () ;
if ( V_4 < 0 ) {
V_13 = V_4 ;
goto V_15;
}
if ( * V_12 >= V_4 ) {
V_13 = 0 ;
goto V_15;
}
V_11 = F_3 ( T_4 , V_11 , V_4 - * V_12 ) ;
V_11 = F_4 ( V_11 , V_16 ) ;
V_14 = F_5 ( V_11 , V_17 ) ;
if ( ! V_14 ) {
V_13 = - V_18 ;
goto V_15;
}
V_13 = V_5 . V_19 ( V_14 , V_11 , V_12 ) ;
if ( V_13 <= 0 )
goto V_15;
if ( F_6 ( V_10 , V_14 , V_13 ) )
V_13 = - V_20 ;
V_15:
F_7 ( V_14 ) ;
return V_13 ;
}
static T_2 F_8 ( struct V_1 * V_1 , const char T_3 * V_10 ,
T_4 V_11 , T_1 * V_12 )
{
T_2 V_13 ;
char * V_14 = NULL ;
T_2 V_4 ;
V_13 = - V_7 ;
if ( ! V_5 . V_6 )
goto V_15;
V_13 = 0 ;
V_4 = V_5 . V_6 () ;
if ( * V_12 >= V_4 || V_4 < 0 )
goto V_15;
V_11 = F_3 ( T_4 , V_11 , V_4 - * V_12 ) ;
V_11 = F_4 ( V_11 , V_16 ) ;
V_13 = - V_18 ;
V_14 = F_5 ( V_11 , V_17 ) ;
if ( ! V_14 )
goto V_15;
V_13 = - V_20 ;
if ( F_9 ( V_14 , V_10 , V_11 ) )
goto V_15;
V_13 = V_5 . V_21 ( V_14 , V_11 , V_12 ) ;
V_15:
F_7 ( V_14 ) ;
return V_13 ;
}
static long F_10 ( struct V_1 * V_1 , unsigned int V_22 ,
unsigned long V_23 )
{
switch( V_22 ) {
#ifdef F_11
case V_24 :
F_12 ( V_25 L_1 ) ;
case V_26 : {
int V_27 , V_2 ;
if ( ! F_13 ( V_28 ) )
return - V_9 ;
if ( F_9 ( & V_27 , ( void T_3 * ) V_23 , sizeof( V_27 ) ) != 0 )
return - V_20 ;
if ( V_27 < V_29 || V_27 > V_30 )
return - V_9 ;
V_2 = F_14 ( V_27 ) ;
if ( V_2 < 0 )
return V_2 ;
if ( F_6 ( ( void T_3 * ) V_23 , & V_2 , sizeof( V_2 ) ) != 0 )
return - V_20 ;
return 0 ;
}
#endif
default:
return - V_9 ;
}
}
static void T_5 F_15 ( char * V_31 )
{
struct V_32 * V_33 ;
F_12 ( V_25 L_2 , V_31 ) ;
F_12 ( V_25 L_3 ) ;
F_16 (tmp_part, &nvram_partitions, partition) {
F_12 ( V_25 L_4 ,
V_33 -> V_34 , V_33 -> V_35 . V_36 ,
V_33 -> V_35 . V_37 , V_33 -> V_35 . V_38 ,
V_33 -> V_35 . V_39 ) ;
}
}
static int T_5 F_17 ( struct V_32 * V_27 )
{
T_1 V_40 ;
int V_41 ;
V_40 = V_27 -> V_34 ;
V_41 = V_5 . V_21 ( ( char * ) & V_27 -> V_35 , V_42 , & V_40 ) ;
return V_41 ;
}
static unsigned char T_5 F_18 ( struct V_43 * V_44 )
{
unsigned int V_45 , V_46 ;
unsigned short * V_47 = ( unsigned short * ) V_44 -> V_39 ;
V_45 = V_44 -> V_36 + V_44 -> V_38 + V_47 [ 0 ] + V_47 [ 1 ] + V_47 [ 2 ] + V_47 [ 3 ] + V_47 [ 4 ] + V_47 [ 5 ] ;
V_45 = ( ( V_45 & 0xffff ) + ( V_45 >> 16 ) ) & 0xffff ;
V_46 = ( V_45 >> 8 ) + ( V_45 << 8 ) ;
V_45 = ( ( V_45 + V_46 ) >> 8 ) & 0xff ;
return V_45 ;
}
static int F_19 ( struct V_32 * V_27 ,
const char * V_39 , int V_48 , const char * V_49 [] )
{
if ( V_27 -> V_35 . V_36 != V_48 )
return 0 ;
if ( V_39 ) {
if ( strncmp ( V_39 , V_27 -> V_35 . V_39 , 12 ) )
return 0 ;
} else if ( V_49 ) {
const char * * V_50 ;
for ( V_50 = V_49 ; * V_50 ; V_50 ++ ) {
if ( ! strncmp ( * V_50 , V_27 -> V_35 . V_39 , 12 ) )
return 0 ;
}
}
return 1 ;
}
int T_5 F_20 ( const char * V_39 , int V_48 ,
const char * V_49 [] )
{
struct V_32 * V_27 , * V_51 , * V_14 ;
int V_41 ;
F_16 (part, &nvram_partitions, partition) {
if ( ! F_19 ( V_27 , V_39 , V_48 , V_49 ) )
continue;
V_27 -> V_35 . V_36 = V_52 ;
strncpy ( V_27 -> V_35 . V_39 , L_5 , 12 ) ;
V_27 -> V_35 . V_37 = F_18 ( & V_27 -> V_35 ) ;
V_41 = F_17 ( V_27 ) ;
if ( V_41 <= 0 ) {
F_12 ( V_53 L_6 , V_41 ) ;
return V_41 ;
}
}
V_51 = NULL ;
F_21 (part, tmp, &nvram_partitions, partition) {
if ( V_27 -> V_35 . V_36 != V_52 ) {
V_51 = NULL ;
continue;
}
if ( V_51 ) {
V_51 -> V_35 . V_38 += V_27 -> V_35 . V_38 ;
V_51 -> V_35 . V_37 = F_18 ( & V_27 -> V_35 ) ;
V_41 = F_17 ( V_27 ) ;
if ( V_41 <= 0 ) {
F_12 ( V_53 L_6 , V_41 ) ;
return V_41 ;
}
F_22 ( & V_27 -> V_54 ) ;
F_7 ( V_27 ) ;
} else
V_51 = V_27 ;
}
return 0 ;
}
T_1 T_5 F_23 ( const char * V_39 , int V_48 ,
int V_55 , int V_56 )
{
struct V_32 * V_27 ;
struct V_32 * V_57 ;
struct V_32 * V_58 = NULL ;
static char V_59 [ 16 ] ;
T_1 V_40 ;
long V_4 = 0 ;
int V_41 ;
V_55 = F_24 ( V_55 , V_60 ) / V_60 ;
V_56 = F_24 ( V_56 , V_60 ) / V_60 ;
if ( V_56 == 0 )
V_56 = V_55 ;
if ( V_56 > V_55 )
return - V_9 ;
V_55 += 1 ;
V_56 += 1 ;
F_16 (part, &nvram_partitions, partition) {
if ( V_27 -> V_35 . V_36 != V_52 )
continue;
if ( V_27 -> V_35 . V_38 >= V_55 ) {
V_4 = V_55 ;
V_58 = V_27 ;
break;
}
if ( V_27 -> V_35 . V_38 > V_4 &&
V_27 -> V_35 . V_38 >= V_56 ) {
V_4 = V_27 -> V_35 . V_38 ;
V_58 = V_27 ;
}
}
if ( ! V_4 )
return - V_61 ;
V_57 = F_5 ( sizeof( * V_57 ) , V_17 ) ;
if ( ! V_57 ) {
F_25 ( L_7 ) ;
return - V_18 ;
}
V_57 -> V_34 = V_58 -> V_34 ;
V_57 -> V_35 . V_36 = V_48 ;
V_57 -> V_35 . V_38 = V_4 ;
strncpy ( V_57 -> V_35 . V_39 , V_39 , 12 ) ;
V_57 -> V_35 . V_37 = F_18 ( & V_57 -> V_35 ) ;
V_41 = F_17 ( V_57 ) ;
if ( V_41 <= 0 ) {
F_25 ( L_8
L_9 , V_41 ) ;
return V_41 ;
}
F_26 ( & V_57 -> V_54 , & V_58 -> V_54 ) ;
if ( V_58 -> V_35 . V_38 > V_4 ) {
V_58 -> V_34 += V_4 * V_60 ;
V_58 -> V_35 . V_38 -= V_4 ;
V_58 -> V_35 . V_37 = F_18 ( & V_58 -> V_35 ) ;
V_41 = F_17 ( V_58 ) ;
if ( V_41 <= 0 ) {
F_25 ( L_8
L_9 , V_41 ) ;
return V_41 ;
}
} else {
F_22 ( & V_58 -> V_54 ) ;
F_7 ( V_58 ) ;
}
for ( V_40 = V_57 -> V_34 + V_42 ;
V_40 < ( ( V_4 - 1 ) * V_60 ) ;
V_40 += V_60 ) {
V_41 = V_5 . V_21 ( V_59 , V_60 , & V_40 ) ;
if ( V_41 <= 0 ) {
F_25 ( L_10 , V_41 ) ;
return V_41 ;
}
}
return V_57 -> V_34 + V_42 ;
}
int F_27 ( T_1 V_62 )
{
struct V_32 * V_27 ;
F_16 (part, &nvram_partitions, partition) {
if ( V_27 -> V_34 + V_42 == V_62 )
return ( V_27 -> V_35 . V_38 - 1 ) * V_60 ;
}
return - 1 ;
}
T_1 F_28 ( const char * V_39 , int V_48 , int * V_63 )
{
struct V_32 * V_44 ;
F_16 (p, &nvram_partitions, partition) {
if ( V_44 -> V_35 . V_36 == V_48 &&
( ! V_39 || ! strncmp ( V_44 -> V_35 . V_39 , V_39 , 12 ) ) ) {
if ( V_63 )
* V_63 = ( V_44 -> V_35 . V_38 - 1 ) *
V_60 ;
return V_44 -> V_34 + V_42 ;
}
}
return 0 ;
}
int T_5 F_29 ( void )
{
T_1 V_64 = 0 ;
struct V_43 V_65 ;
struct V_32 * V_33 ;
unsigned char V_45 ;
char * V_35 ;
int V_66 ;
int V_67 ;
if ( V_5 . V_6 == NULL || V_5 . V_6 () <= 0 )
return - V_7 ;
V_66 = V_5 . V_6 () ;
V_35 = F_5 ( V_42 , V_17 ) ;
if ( ! V_35 ) {
F_12 ( V_53 L_11 ) ;
return - V_18 ;
}
while ( V_64 < V_66 ) {
V_67 = V_5 . V_19 ( V_35 , V_42 , & V_64 ) ;
if ( V_67 != V_42 ) {
F_12 ( V_53 L_12
L_13 ) ;
goto V_15;
}
V_64 -= V_42 ;
memcpy ( & V_65 , V_35 , V_42 ) ;
V_67 = 0 ;
V_45 = F_18 ( & V_65 ) ;
if ( V_45 != V_65 . V_37 ) {
F_12 ( V_25 L_14
L_15 ,
V_65 . V_37 , V_45 ) ;
F_12 ( V_25 L_16 ) ;
goto V_15;
}
if ( ! V_65 . V_38 ) {
F_12 ( V_25 L_17
L_18 ) ;
goto V_15;
}
V_33 = F_5 ( sizeof( struct V_32 ) , V_17 ) ;
V_67 = - V_18 ;
if ( ! V_33 ) {
F_12 ( V_53 L_19 ) ;
goto V_15;
}
memcpy ( & V_33 -> V_35 , & V_65 , V_42 ) ;
V_33 -> V_34 = V_64 ;
F_26 ( & V_33 -> V_54 , & V_68 ) ;
V_64 += V_65 . V_38 * V_60 ;
}
V_67 = 0 ;
#ifdef F_30
F_15 ( L_20 ) ;
#endif
V_15:
F_7 ( V_35 ) ;
return V_67 ;
}
static int T_5 F_31 ( void )
{
int V_41 ;
F_32 ( V_60 != 16 ) ;
if ( V_5 . V_6 == NULL || V_5 . V_6 () <= 0 )
return - V_7 ;
V_41 = F_33 ( & V_69 ) ;
if ( V_41 != 0 ) {
F_12 ( V_53 L_21 ) ;
return V_41 ;
}
return V_41 ;
}
void T_6 F_34 ( void )
{
F_35 ( & V_69 ) ;
}
