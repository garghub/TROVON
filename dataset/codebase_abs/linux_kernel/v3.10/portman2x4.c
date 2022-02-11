static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_1 * * V_7 )
{
struct V_1 * V_2 ;
* V_7 = NULL ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( V_2 == NULL )
return - V_9 ;
F_5 ( & V_2 -> V_10 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_6 ;
* V_7 = V_2 ;
return 0 ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
F_7 ( V_2 -> V_6 -> V_12 , V_11 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 )
{
return F_9 ( V_2 -> V_6 -> V_12 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 -> V_6 -> V_12 ) ;
}
static inline T_1 F_12 ( struct V_1 * V_2 )
{
return F_13 ( V_2 -> V_6 -> V_12 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_1 V_11 )
{
F_15 ( V_2 -> V_6 -> V_12 , V_11 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
int V_12 , T_1 V_13 )
{
int V_14 = ( ( V_12 + 4 ) << 1 ) ;
V_14 |= V_15 ;
do {
F_6 ( V_2 , V_14 ) ;
F_14 ( V_2 , V_13 ) ;
} while ( ( F_10 ( V_2 ) & V_16 ) != V_16 );
F_6 ( V_2 , V_14 | V_17 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == 0 )
F_17 () ;
F_6 ( V_2 , V_14 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == V_18 )
F_17 () ;
while ( ( F_10 ( V_2 ) & V_19 ) == V_19 )
F_17 () ;
}
static int F_18 ( struct V_1 * V_2 , int V_12 )
{
unsigned char V_20 = 0 ;
unsigned char V_21 ;
F_14 ( V_2 , 0 ) ;
V_21 = ( V_12 << 1 ) | V_15 ;
F_6 ( V_2 , V_21 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == V_18 )
F_17 () ;
if ( ( F_10 ( V_2 ) & V_22 ) == 0 )
return - 1 ;
F_6 ( V_2 , V_21 | V_17 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == 0 )
F_17 () ;
V_20 = ( F_10 ( V_2 ) & 128 ) ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 1 ) & 64 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 2 ) & 32 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 3 ) & 16 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 4 ) & 8 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 5 ) & 4 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 6 ) & 2 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
V_20 |= ( F_10 ( V_2 ) >> 7 ) & 1 ;
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
F_6 ( V_2 , V_21 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == V_18 )
F_17 () ;
return ( V_20 & 255 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_23 )
{
int V_14 = V_15 ;
switch ( V_23 ) {
case 0 :
V_14 |= V_24 ;
break;
case 1 :
V_14 |= V_25 ;
break;
}
F_6 ( V_2 , V_14 ) ;
if ( ( F_10 ( V_2 ) & V_22 ) == V_22 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned char V_12 )
{
unsigned int V_26 = 0 ;
unsigned char V_14 = 0 ;
switch ( V_12 ) {
case 0 :
V_14 = V_24 ;
break;
case 1 :
V_14 = V_25 ;
break;
default:
F_21 ( V_27
L_1 ,
V_12 ) ;
return;
}
F_6 ( V_2 , V_14 ) ;
F_6 ( V_2 , V_14 | V_17 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == 0 )
F_17 () ;
F_14 ( V_2 , 0 ) ;
for ( V_26 = 0 ; V_26 < 250 ; V_26 ++ ) {
F_14 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
}
F_6 ( V_2 , V_14 | V_15 ) ;
while ( ( F_10 ( V_2 ) & V_18 ) == V_18 )
F_17 () ;
}
static int F_22 ( struct V_28 * V_29 )
{
F_15 ( V_29 , 0 ) ;
F_7 ( V_29 , 0 ) ;
F_7 ( V_29 , V_24 ) ;
if ( ( F_11 ( V_29 ) & V_18 ) == V_18 )
return 1 ;
F_7 ( V_29 , V_24 + V_17 ) ;
if ( ( F_11 ( V_29 ) & V_18 ) != V_18 )
return 1 ;
F_7 ( V_29 , 0 ) ;
F_7 ( V_29 , V_30 ) ;
if ( ( F_11 ( V_29 ) & V_16 ) == 0 )
return 2 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_20 ( V_2 , 0 ) ;
F_20 ( V_2 , 1 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 )
{
return 0 ;
}
static int F_25 ( struct V_31 * V_32 )
{
return 0 ;
}
static void F_26 ( struct V_31 * V_32 ,
int V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 -> V_35 ;
unsigned long V_36 ;
F_27 ( & V_2 -> V_10 , V_36 ) ;
if ( V_33 )
V_2 -> V_37 [ V_32 -> V_38 ] |= V_39 ;
else
V_2 -> V_37 [ V_32 -> V_38 ] &= ~ V_39 ;
F_28 ( & V_2 -> V_10 , V_36 ) ;
}
static void F_29 ( struct V_31 * V_32 ,
int V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 -> V_35 ;
unsigned long V_36 ;
unsigned char V_40 ;
F_27 ( & V_2 -> V_10 , V_36 ) ;
if ( V_33 ) {
while ( ( F_30 ( V_32 , & V_40 , 1 ) == 1 ) )
F_16 ( V_2 , V_32 -> V_38 , V_40 ) ;
}
F_28 ( & V_2 -> V_10 , V_36 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_35 ;
struct V_41 * V_34 ;
struct V_31 * V_32 ;
int V_42 ;
V_42 = F_32 ( V_4 , V_43 , 0 ,
V_44 ,
V_45 ,
& V_34 ) ;
if ( V_42 < 0 )
return V_42 ;
V_34 -> V_35 = V_2 ;
strcpy ( V_34 -> V_46 , V_43 ) ;
V_34 -> V_47 = V_48 |
V_49 |
V_50 ;
V_2 -> V_34 = V_34 ;
F_33 ( V_34 , V_51 ,
& V_52 ) ;
F_33 ( V_34 , V_53 ,
& V_54 ) ;
F_34 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams,
list) {
sprintf ( V_32 -> V_46 ,
L_2 , V_32 -> V_38 + 1 ) ;
}
F_34 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams,
list) {
V_2 -> V_55 [ V_32 -> V_38 ] = V_32 ;
sprintf ( V_32 -> V_46 ,
L_2 , V_32 -> V_38 + 1 ) ;
}
return V_42 ;
}
static void F_35 ( void * V_56 )
{
unsigned char V_57 = 0 ;
struct V_1 * V_2 = ( (struct V_3 * ) V_56 ) -> V_35 ;
F_36 ( & V_2 -> V_10 ) ;
while ( ( F_10 ( V_2 ) & V_58 ) == V_58 ) {
if ( F_19 ( V_2 , 0 ) ) {
V_57 = F_18 ( V_2 , 0 ) ;
if ( V_2 -> V_37 [ 0 ] & V_39 )
F_37 ( V_2 -> V_55 [ 0 ] ,
& V_57 , 1 ) ;
}
if ( F_19 ( V_2 , 1 ) ) {
V_57 = F_18 ( V_2 , 1 ) ;
if ( V_2 -> V_37 [ 1 ] & V_39 )
F_37 ( V_2 -> V_55 [ 1 ] ,
& V_57 , 1 ) ;
}
}
F_38 ( & V_2 -> V_10 ) ;
}
static int F_39 ( struct V_28 * V_29 )
{
struct V_5 * V_6 ;
int V_59 ;
V_6 = F_40 ( V_29 , V_60 ,
NULL , NULL , NULL ,
0 , NULL ) ;
if ( ! V_6 )
return - V_61 ;
if ( F_41 ( V_6 ) ) {
F_42 ( V_6 ) ;
return - V_61 ;
}
V_59 = F_22 ( V_29 ) ;
F_43 ( V_6 ) ;
F_42 ( V_6 ) ;
return V_59 ? - V_61 : 0 ;
}
static void F_44 ( struct V_28 * V_29 )
{
struct V_62 * V_63 ;
V_63 = F_45 ( V_64 , V_65 ) ;
if ( ! V_63 )
return;
F_46 ( V_63 , V_29 ) ;
if ( F_47 ( V_63 ) < 0 ) {
F_48 ( V_63 ) ;
return;
}
if ( ! F_49 ( V_63 ) ) {
F_50 ( V_63 ) ;
return;
}
V_66 [ V_65 ] = V_63 ;
V_65 ++ ;
}
static void F_51 ( struct V_28 * V_29 )
{
}
static void F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_35 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 ) {
if ( V_2 -> V_67 )
F_43 ( V_6 ) ;
F_42 ( V_6 ) ;
}
F_1 ( V_2 ) ;
}
static int F_53 ( struct V_62 * V_68 )
{
struct V_5 * V_6 ;
struct V_28 * V_29 ;
int V_69 = V_68 -> V_70 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 = NULL ;
int V_42 ;
V_29 = F_49 ( V_68 ) ;
F_46 ( V_68 , NULL ) ;
if ( V_69 >= V_71 )
return - V_72 ;
if ( ! V_73 [ V_69 ] )
return - V_74 ;
if ( ( V_42 = F_39 ( V_29 ) ) < 0 )
return V_42 ;
V_42 = F_54 ( V_75 [ V_69 ] , V_70 [ V_69 ] , V_76 , 0 , & V_4 ) ;
if ( V_42 < 0 ) {
F_55 ( L_3 ) ;
return V_42 ;
}
strcpy ( V_4 -> V_77 , V_60 ) ;
strcpy ( V_4 -> V_78 , V_43 ) ;
sprintf ( V_4 -> V_79 , L_4 ,
V_4 -> V_78 , V_29 -> V_80 , V_29 -> V_81 ) ;
V_6 = F_40 ( V_29 ,
V_60 ,
NULL ,
NULL ,
F_35 ,
V_82 ,
( void * ) V_4 ) ;
if ( V_6 == NULL ) {
F_55 ( L_5 ) ;
V_42 = - V_61 ;
goto V_83;
}
if ( ( V_42 = F_3 ( V_4 , V_6 , & V_2 ) ) < 0 ) {
F_55 ( L_6 ) ;
F_42 ( V_6 ) ;
goto V_83;
}
V_4 -> V_35 = V_2 ;
V_4 -> V_84 = F_52 ;
if ( ( V_42 = F_31 ( V_4 ) ) < 0 ) {
F_55 ( L_7 ) ;
goto V_83;
}
if ( F_41 ( V_6 ) ) {
F_55 ( L_8 , V_6 -> V_12 -> V_80 ) ;
V_42 = - V_61 ;
goto V_83;
}
V_2 -> V_67 = 1 ;
if ( ( V_42 = F_23 ( V_2 ) ) < 0 )
goto V_83;
F_46 ( V_68 , V_4 ) ;
F_56 ( V_4 , & V_68 -> V_69 ) ;
if ( ( V_42 = F_57 ( V_4 ) ) < 0 ) {
F_55 ( L_9 ) ;
goto V_83;
}
F_21 ( V_85 L_10 , V_29 -> V_80 ) ;
return 0 ;
V_83:
F_58 ( V_4 ) ;
return V_42 ;
}
static int F_59 ( struct V_62 * V_68 )
{
struct V_3 * V_4 = F_49 ( V_68 ) ;
if ( V_4 )
F_58 ( V_4 ) ;
return 0 ;
}
static void F_60 ( void )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_71 ; ++ V_26 ) {
if ( V_66 [ V_26 ] ) {
F_50 ( V_66 [ V_26 ] ) ;
V_66 [ V_26 ] = NULL ;
}
}
F_61 ( & V_86 ) ;
F_62 ( & V_87 ) ;
}
static int T_2 F_63 ( void )
{
int V_42 ;
if ( ( V_42 = F_64 ( & V_86 ) ) < 0 )
return V_42 ;
if ( F_65 ( & V_87 ) != 0 ) {
F_61 ( & V_86 ) ;
return - V_61 ;
}
if ( V_65 == 0 ) {
F_60 () ;
return - V_72 ;
}
return 0 ;
}
static void T_3 F_66 ( void )
{
F_60 () ;
}
