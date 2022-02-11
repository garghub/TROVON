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
struct V_42 V_43 ;
memcpy ( & V_43 , & V_27 -> V_35 , V_44 ) ;
V_43 . V_38 = F_18 ( V_43 . V_38 ) ;
V_40 = V_27 -> V_34 ;
V_41 = V_5 . V_21 ( ( char * ) & V_43 , V_44 , & V_40 ) ;
return V_41 ;
}
static unsigned char T_5 F_19 ( struct V_42 * V_45 )
{
unsigned int V_46 , V_47 ;
unsigned short * V_48 = ( unsigned short * ) V_45 -> V_39 ;
V_46 = V_45 -> V_36 + V_45 -> V_38 + V_48 [ 0 ] + V_48 [ 1 ] + V_48 [ 2 ] + V_48 [ 3 ] + V_48 [ 4 ] + V_48 [ 5 ] ;
V_46 = ( ( V_46 & 0xffff ) + ( V_46 >> 16 ) ) & 0xffff ;
V_47 = ( V_46 >> 8 ) + ( V_46 << 8 ) ;
V_46 = ( ( V_46 + V_47 ) >> 8 ) & 0xff ;
return V_46 ;
}
static int F_20 ( struct V_32 * V_27 ,
const char * V_39 , int V_49 , const char * V_50 [] )
{
if ( V_27 -> V_35 . V_36 != V_49 )
return 0 ;
if ( V_39 ) {
if ( strncmp ( V_39 , V_27 -> V_35 . V_39 , 12 ) )
return 0 ;
} else if ( V_50 ) {
const char * * V_51 ;
for ( V_51 = V_50 ; * V_51 ; V_51 ++ ) {
if ( ! strncmp ( * V_51 , V_27 -> V_35 . V_39 , 12 ) )
return 0 ;
}
}
return 1 ;
}
int T_5 F_21 ( const char * V_39 , int V_49 ,
const char * V_50 [] )
{
struct V_32 * V_27 , * V_52 , * V_14 ;
int V_41 ;
F_16 (part, &nvram_partitions, partition) {
if ( ! F_20 ( V_27 , V_39 , V_49 , V_50 ) )
continue;
V_27 -> V_35 . V_36 = V_53 ;
strncpy ( V_27 -> V_35 . V_39 , L_5 , 12 ) ;
V_27 -> V_35 . V_37 = F_19 ( & V_27 -> V_35 ) ;
V_41 = F_17 ( V_27 ) ;
if ( V_41 <= 0 ) {
F_12 ( V_54 L_6 , V_41 ) ;
return V_41 ;
}
}
V_52 = NULL ;
F_22 (part, tmp, &nvram_partitions, partition) {
if ( V_27 -> V_35 . V_36 != V_53 ) {
V_52 = NULL ;
continue;
}
if ( V_52 ) {
V_52 -> V_35 . V_38 += V_27 -> V_35 . V_38 ;
V_52 -> V_35 . V_37 = F_19 ( & V_27 -> V_35 ) ;
V_41 = F_17 ( V_27 ) ;
if ( V_41 <= 0 ) {
F_12 ( V_54 L_6 , V_41 ) ;
return V_41 ;
}
F_23 ( & V_27 -> V_55 ) ;
F_7 ( V_27 ) ;
} else
V_52 = V_27 ;
}
return 0 ;
}
T_1 T_5 F_24 ( const char * V_39 , int V_49 ,
int V_56 , int V_57 )
{
struct V_32 * V_27 ;
struct V_32 * V_58 ;
struct V_32 * V_59 = NULL ;
static char V_60 [ 16 ] ;
T_1 V_40 ;
long V_4 = 0 ;
int V_41 ;
V_56 = F_25 ( V_56 , V_61 ) / V_61 ;
V_57 = F_25 ( V_57 , V_61 ) / V_61 ;
if ( V_57 == 0 )
V_57 = V_56 ;
if ( V_57 > V_56 )
return - V_9 ;
V_56 += 1 ;
V_57 += 1 ;
F_16 (part, &nvram_partitions, partition) {
if ( V_27 -> V_35 . V_36 != V_53 )
continue;
if ( V_27 -> V_35 . V_38 >= V_56 ) {
V_4 = V_56 ;
V_59 = V_27 ;
break;
}
if ( V_27 -> V_35 . V_38 > V_4 &&
V_27 -> V_35 . V_38 >= V_57 ) {
V_4 = V_27 -> V_35 . V_38 ;
V_59 = V_27 ;
}
}
if ( ! V_4 )
return - V_62 ;
V_58 = F_5 ( sizeof( * V_58 ) , V_17 ) ;
if ( ! V_58 ) {
F_26 ( L_7 ) ;
return - V_18 ;
}
V_58 -> V_34 = V_59 -> V_34 ;
V_58 -> V_35 . V_36 = V_49 ;
V_58 -> V_35 . V_38 = V_4 ;
strncpy ( V_58 -> V_35 . V_39 , V_39 , 12 ) ;
V_58 -> V_35 . V_37 = F_19 ( & V_58 -> V_35 ) ;
V_41 = F_17 ( V_58 ) ;
if ( V_41 <= 0 ) {
F_26 ( L_8
L_9 , V_41 ) ;
return V_41 ;
}
F_27 ( & V_58 -> V_55 , & V_59 -> V_55 ) ;
if ( V_59 -> V_35 . V_38 > V_4 ) {
V_59 -> V_34 += V_4 * V_61 ;
V_59 -> V_35 . V_38 -= V_4 ;
V_59 -> V_35 . V_37 = F_19 ( & V_59 -> V_35 ) ;
V_41 = F_17 ( V_59 ) ;
if ( V_41 <= 0 ) {
F_26 ( L_8
L_9 , V_41 ) ;
return V_41 ;
}
} else {
F_23 ( & V_59 -> V_55 ) ;
F_7 ( V_59 ) ;
}
for ( V_40 = V_58 -> V_34 + V_44 ;
V_40 < ( ( V_4 - 1 ) * V_61 ) ;
V_40 += V_61 ) {
V_41 = V_5 . V_21 ( V_60 , V_61 , & V_40 ) ;
if ( V_41 <= 0 ) {
F_26 ( L_10 , V_41 ) ;
return V_41 ;
}
}
return V_58 -> V_34 + V_44 ;
}
int F_28 ( T_1 V_63 )
{
struct V_32 * V_27 ;
F_16 (part, &nvram_partitions, partition) {
if ( V_27 -> V_34 + V_44 == V_63 )
return ( V_27 -> V_35 . V_38 - 1 ) * V_61 ;
}
return - 1 ;
}
T_1 F_29 ( const char * V_39 , int V_49 , int * V_64 )
{
struct V_32 * V_45 ;
F_16 (p, &nvram_partitions, partition) {
if ( V_45 -> V_35 . V_36 == V_49 &&
( ! V_39 || ! strncmp ( V_45 -> V_35 . V_39 , V_39 , 12 ) ) ) {
if ( V_64 )
* V_64 = ( V_45 -> V_35 . V_38 - 1 ) *
V_61 ;
return V_45 -> V_34 + V_44 ;
}
}
return 0 ;
}
int T_5 F_30 ( void )
{
T_1 V_65 = 0 ;
struct V_42 V_43 ;
struct V_32 * V_33 ;
unsigned char V_46 ;
char * V_35 ;
int V_66 ;
int V_67 ;
if ( V_5 . V_6 == NULL || V_5 . V_6 () <= 0 )
return - V_7 ;
V_66 = V_5 . V_6 () ;
V_35 = F_5 ( V_44 , V_17 ) ;
if ( ! V_35 ) {
F_12 ( V_54 L_11 ) ;
return - V_18 ;
}
while ( V_65 < V_66 ) {
V_67 = V_5 . V_19 ( V_35 , V_44 , & V_65 ) ;
if ( V_67 != V_44 ) {
F_12 ( V_54 L_12
L_13 ) ;
goto V_15;
}
V_65 -= V_44 ;
memcpy ( & V_43 , V_35 , V_44 ) ;
V_43 . V_38 = F_31 ( V_43 . V_38 ) ;
V_67 = 0 ;
V_46 = F_19 ( & V_43 ) ;
if ( V_46 != V_43 . V_37 ) {
F_12 ( V_25 L_14
L_15 ,
V_43 . V_37 , V_46 ) ;
F_12 ( V_25 L_16 ) ;
goto V_15;
}
if ( ! V_43 . V_38 ) {
F_12 ( V_25 L_17
L_18 ) ;
goto V_15;
}
V_33 = F_5 ( sizeof( struct V_32 ) , V_17 ) ;
V_67 = - V_18 ;
if ( ! V_33 ) {
F_12 ( V_54 L_19 ) ;
goto V_15;
}
memcpy ( & V_33 -> V_35 , & V_43 , V_44 ) ;
V_33 -> V_34 = V_65 ;
F_27 ( & V_33 -> V_55 , & V_68 ) ;
V_65 += V_43 . V_38 * V_61 ;
}
V_67 = 0 ;
#ifdef F_32
F_15 ( L_20 ) ;
#endif
V_15:
F_7 ( V_35 ) ;
return V_67 ;
}
static int T_5 F_33 ( void )
{
int V_41 ;
F_34 ( V_61 != 16 ) ;
if ( V_5 . V_6 == NULL || V_5 . V_6 () <= 0 )
return - V_7 ;
V_41 = F_35 ( & V_69 ) ;
if ( V_41 != 0 ) {
F_12 ( V_54 L_21 ) ;
return V_41 ;
}
return V_41 ;
}
void T_6 F_36 ( void )
{
F_37 ( & V_69 ) ;
}
