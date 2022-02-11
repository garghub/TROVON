static T_1 void F_1 ( volatile struct V_1 * V_2 , T_2 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_3 >> 8 ;
}
static T_1 T_3 F_2 ( volatile struct V_1 * V_2 , T_2 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_3 >> 8 ;
return V_2 -> V_6 ;
}
static T_1 void F_3 ( volatile struct V_1 * V_2 , T_2 V_3 , T_3 V_7 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_3 >> 8 ;
V_2 -> V_6 = V_7 ;
}
static T_1 void F_4 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 &= ~ V_9 ;
}
static T_1 void F_5 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 = V_9 | V_10 ;
}
static T_1 void F_6 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 |= V_11 ;
}
static T_1 void F_7 ( volatile struct V_1 * V_2 )
{
V_2 -> V_8 |= V_12 ;
}
static int F_8 ( volatile struct V_1 * V_2 )
{
int V_13 ;
V_13 = ( F_2 ( V_2 , V_14 ) == 0xFF ) ;
F_3 ( V_2 , V_14 , 0 ) ;
return V_13 ;
}
static struct V_15 * F_9 ( void )
{
int V_16 ;
unsigned long V_17 ;
F_10 ( V_17 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
if ( V_19 [ V_16 ] . V_20 == V_21 ) {
V_19 [ V_16 ] . V_20 = V_22 ;
F_11 ( V_17 ) ;
return & V_19 [ V_16 ] ;
}
}
F_11 ( V_17 ) ;
return NULL ;
}
void T_4 F_12 ( void )
{
if ( V_23 -> V_24 == V_25 ) {
if ( V_23 -> V_26 == V_27 ) {
V_28 [ V_29 ] = (struct V_1 * ) V_30 ;
} else {
V_28 [ V_29 ] = (struct V_1 * ) V_31 ;
}
V_28 [ V_29 ] -> V_8 = 0x87 ;
V_32 = 1 ;
} else {
V_28 [ V_29 ] = NULL ;
V_32 = 0 ;
}
if ( V_23 -> V_33 == V_34 ) {
if ( V_23 -> V_26 == V_27 ) {
V_28 [ V_35 ] = (struct V_1 * ) V_36 ;
} else {
V_28 [ V_35 ] = (struct V_1 * ) V_37 ;
}
V_28 [ V_35 ] -> V_8 = 0 ;
V_38 = 1 ;
} else {
V_28 [ V_35 ] = NULL ;
V_38 = 0 ;
}
}
void T_4 F_13 ( void )
{
int V_16 ;
if ( V_32 ) {
F_14 ( L_1 , V_28 [ V_29 ] ) ;
}
if ( V_38 ) {
F_14 ( L_2 , V_28 [ V_35 ] ) ;
F_5 ( V_28 [ V_35 ] ) ;
F_8 ( V_28 [ V_35 ] ) ;
}
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
V_19 [ V_16 ] . V_20 = V_21 ;
}
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
V_40 [ V_29 ] [ V_16 ] = NULL ;
V_40 [ V_35 ] [ V_16 ] = NULL ;
V_41 [ V_29 ] [ V_16 ] . V_42 = NULL ;
V_41 [ V_29 ] [ V_16 ] . V_43 = NULL ;
V_41 [ V_35 ] [ V_16 ] . V_42 = NULL ;
V_41 [ V_35 ] [ V_16 ] . V_43 = NULL ;
}
}
void T_4 F_15 ( void )
{
if ( V_38 ) {
if ( V_23 -> V_26 == V_27 ) {
if ( F_16 ( V_44 , V_45 , 0 ,
L_3 , ( void * ) V_35 ) )
F_17 ( L_4 ) ;
} else {
if ( F_16 ( V_46 , V_45 , 0 , L_3 ,
( void * ) V_35 ) )
F_17 ( L_4 ) ;
}
if ( ! F_8 ( V_28 [ V_35 ] ) ) {
F_18 ( L_5 ) ;
} else {
F_18 ( L_6 ) ;
}
}
}
int F_19 ( T_5 V_47 , T_5 V_48 ,
void (* V_43)( struct V_15 * ) ,
const char * V_42 )
{
if ( ( V_47 >= V_49 ) || ! V_28 [ V_47 ] ) return - V_50 ;
if ( V_48 >= V_39 ) return - V_50 ;
if ( V_41 [ V_47 ] [ V_48 ] . V_43 && V_43 ) return - V_50 ;
V_41 [ V_47 ] [ V_48 ] . V_42 = V_42 ;
V_41 [ V_47 ] [ V_48 ] . V_43 = V_43 ;
return 0 ;
}
void F_20 ( struct V_15 * V_51 )
{
int V_47 = V_51 -> V_47 ;
int V_48 = V_51 -> V_52 ;
int V_16 , V_53 ;
F_21 ( L_7 , V_51 , V_51 -> V_47 ,
V_51 -> V_52 ) ;
V_53 = V_54 + ( V_51 -> V_52 * V_55 ) ;
for ( V_16 = 0 ; V_16 < V_55 ; V_16 ++ , V_53 ++ ) {
F_3 ( V_28 [ V_47 ] , V_53 , V_51 -> V_56 [ V_16 ] ) ;
}
F_3 ( V_28 [ V_47 ] ,
V_57 + V_48 , V_58 ) ;
F_7 ( V_28 [ V_51 -> V_47 ] ) ;
V_51 -> V_20 = V_21 ;
}
static void F_22 ( struct V_15 * V_51 )
{
volatile struct V_1 * V_2 = V_28 [ V_51 -> V_47 ] ;
int V_16 , V_53 ;
V_53 = V_59 + ( V_51 -> V_52 * V_55 ) ;
for ( V_16 = 0 ; V_16 < V_55 ; V_16 ++ , V_53 ++ ) {
F_3 ( V_2 , V_53 , V_51 -> V_60 [ V_16 ] ) ;
}
F_3 ( V_2 , V_61 + V_51 -> V_52 , V_62 ) ;
F_7 ( V_2 ) ;
}
static void F_23 ( T_5 V_47 , T_5 V_48 )
{
volatile struct V_1 * V_2 = V_28 [ V_47 ] ;
struct V_15 * V_51 ;
int V_16 , V_53 ;
F_21 ( L_8 , V_47 , V_48 ) ;
F_3 ( V_2 , V_61 + V_48 , V_63 ) ;
if ( ! ( V_51 = V_40 [ V_47 ] [ V_48 ] ) ) return;
V_51 -> V_20 = V_64 ;
V_53 = V_59 + ( V_48 * V_55 ) ;
for ( V_16 = 0 ; V_16 < V_55 ; V_16 ++ , V_53 ++ ) {
V_51 -> V_56 [ V_16 ] = F_2 ( V_2 , V_53 ) ;
}
if ( V_51 -> V_43 ) (* V_51 -> V_43 )( V_51 ) ;
V_51 -> V_20 = V_21 ;
V_51 = V_51 -> V_65 ;
V_40 [ V_47 ] [ V_48 ] = V_51 ;
if ( V_51 ) F_22 ( V_51 ) ;
}
static void F_24 ( T_5 V_47 , T_5 V_48 )
{
volatile struct V_1 * V_2 = V_28 [ V_47 ] ;
int V_16 , V_53 ;
struct V_15 * V_51 ;
F_21 ( L_8 , V_47 , V_48 ) ;
V_51 = F_9 () ;
V_51 -> V_47 = V_47 ;
V_51 -> V_52 = V_48 ;
V_51 -> V_20 = V_66 ;
V_51 -> V_43 = V_41 [ V_47 ] [ V_48 ] . V_43 ;
V_53 = V_54 + ( V_48 * V_55 ) ;
for ( V_16 = 0 ; V_16 < V_55 ; V_16 ++ , V_53 ++ ) {
V_51 -> V_60 [ V_16 ] = F_2 ( V_2 , V_53 ) ;
}
F_3 ( V_2 , V_57 + V_48 , V_67 ) ;
if ( V_51 -> V_43 ) {
(* V_51 -> V_43 )( V_51 ) ;
} else {
F_21 ( L_9 ,
V_47 , V_48 ) ;
F_21 ( L_10 , V_55 , V_51 -> V_60 ) ;
F_20 ( V_51 ) ;
}
}
int F_25 ( T_5 V_47 , T_5 V_48 , void * V_68 ,
T_5 V_69 , T_3 * V_70 ,
void (* V_43)( struct V_15 * ) )
{
struct V_15 * V_51 , * V_71 ;
if ( ( V_47 >= V_49 ) || ! V_28 [ V_47 ] ) return - V_50 ;
if ( V_48 >= V_39 ) return - V_50 ;
if ( V_69 > V_55 ) return - V_50 ;
V_51 = F_9 () ;
if ( ! V_51 ) return - V_72 ;
V_51 -> V_65 = NULL ;
V_51 -> V_20 = V_22 ;
V_51 -> V_47 = V_47 ;
V_51 -> V_52 = V_48 ;
V_51 -> V_73 = V_68 ;
memcpy ( V_51 -> V_60 , V_70 , V_69 ) ;
V_51 -> V_43 = V_43 ;
if ( ! ( V_71 = V_40 [ V_47 ] [ V_48 ] ) ) {
V_40 [ V_47 ] [ V_48 ] = V_51 ;
} else {
while ( V_71 -> V_65 ) V_71 = V_71 -> V_65 ;
V_71 -> V_65 = V_51 ;
}
if ( F_2 ( V_28 [ V_47 ] ,
V_61 + V_48 ) == V_63 ) {
F_22 ( V_51 ) ;
}
return 0 ;
}
void F_26 ( T_5 V_47 , T_3 * V_74 ,
T_5 V_75 , T_2 V_76 )
{
if ( ( V_47 >= V_49 ) || ! V_28 [ V_47 ] ) return;
F_1 ( V_28 [ V_47 ] , V_76 ) ;
while ( V_75 -- ) {
V_28 [ V_47 ] -> V_6 = * V_74 ++ ;
}
}
void F_27 ( T_5 V_47 , T_3 * V_74 ,
T_5 V_75 , T_2 V_76 )
{
if ( ( V_47 >= V_49 ) || ! V_28 [ V_47 ] ) return;
F_1 ( V_28 [ V_47 ] , V_76 ) ;
while ( V_75 -- ) {
* V_74 ++ = V_28 [ V_47 ] -> V_6 ;
}
}
T_3 * F_28 ( T_5 V_47 , T_3 * V_74 ,
T_5 V_75 , T_2 V_76 )
{
if ( ( V_47 >= V_49 ) || ! V_28 [ V_47 ] ) return V_74 ;
F_1 ( V_28 [ V_47 ] , V_76 ) ;
while ( V_75 -- ) {
if ( * V_74 != V_28 [ V_47 ] -> V_6 ) {
return V_74 ;
}
V_74 ++ ;
}
return ( T_3 * ) 0 ;
}
T_6 V_45 ( int V_77 , void * V_78 )
{
T_5 V_47 = ( T_5 ) V_78 ;
volatile struct V_1 * V_2 = V_28 [ V_47 ] ;
int V_16 , V_79 ;
F_21 ( L_11 , V_2 -> V_8 ) ;
if ( V_2 -> V_8 & V_80 ) {
V_2 -> V_8 = V_80 | V_9 | V_10 ;
F_21 ( L_12 , V_2 -> V_8 ) ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
V_79 = F_2 ( V_2 , V_61 + V_16 ) ;
F_29 ( L_13 , V_79 ) ;
if ( V_79 == V_58 ) {
F_23 ( V_47 , V_16 ) ;
}
}
F_29 ( L_14 ) ;
}
if ( V_2 -> V_8 & V_81 ) {
V_2 -> V_8 = V_81 | V_9 | V_10 ;
F_21 ( L_15 , V_2 -> V_8 ) ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
V_79 = F_2 ( V_2 , V_57 + V_16 ) ;
F_29 ( L_13 , V_79 ) ;
if ( V_79 == V_62 ) {
F_24 ( V_47 , V_16 ) ;
}
}
F_29 ( L_14 ) ;
}
return V_82 ;
}
