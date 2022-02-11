static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_7 -> V_9 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_7 -> V_8 ) ) {
F_9 ( L_1 ,
( unsigned long long ) F_8 ( V_7 -> V_8 ) ,
( unsigned long long ) F_4 ( V_4 ) ) ;
return - V_14 ;
}
V_13 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_13 != V_7 -> V_9 ) {
F_9 ( L_2 ,
( unsigned ) F_10 ( V_13 ) ,
( unsigned ) F_10 ( V_7 -> V_9 ) ) ;
return - V_15 ;
}
return 0 ;
}
static void * F_11 ( struct V_16 * V_17 , struct V_6 * V_18 ,
unsigned V_19 )
{
unsigned char * V_20 = ( unsigned char * ) ( V_18 + 1 ) ;
V_20 += V_19 * V_17 -> V_21 . V_22 ;
return V_20 ;
}
static void F_12 ( struct V_16 * V_17 , struct V_6 * V_18 ,
void (* F_13)( void * , const void * ) )
{
unsigned V_23 , V_24 = F_10 ( V_18 -> V_24 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
F_13 ( V_17 -> V_21 . V_25 , F_11 ( V_17 , V_18 , V_23 ) ) ;
}
static void F_14 ( struct V_16 * V_17 , struct V_6 * V_18 )
{
struct V_26 * V_27 = & V_17 -> V_21 ;
if ( V_27 -> V_28 )
F_12 ( V_17 , V_18 , V_27 -> V_28 ) ;
}
static void F_15 ( struct V_16 * V_17 , struct V_6 * V_18 )
{
struct V_26 * V_27 = & V_17 -> V_21 ;
if ( V_27 -> V_29 )
F_12 ( V_17 , V_18 , V_27 -> V_29 ) ;
}
static T_2 F_16 ( T_1 V_30 , T_1 V_5 )
{
return ( V_5 - sizeof( struct V_6 ) ) / V_30 ;
}
static int F_17 ( struct V_16 * V_17 , T_1 V_5 ,
T_2 V_10 ,
struct V_3 * * V_31 , struct V_6 * * V_18 )
{
int V_32 ;
V_32 = F_18 ( V_17 -> V_33 . V_34 , & V_35 , V_31 ) ;
if ( V_32 )
return V_32 ;
( * V_18 ) = F_2 ( * V_31 ) ;
( * V_18 ) -> V_10 = F_5 ( V_10 ) ;
( * V_18 ) -> V_24 = F_5 ( 0 ) ;
( * V_18 ) -> V_30 = F_5 ( V_17 -> V_21 . V_22 ) ;
return 0 ;
}
static void F_19 ( struct V_16 * V_17 , struct V_6 * V_18 ,
const void * V_36 , unsigned V_37 )
{
unsigned V_23 ;
T_2 V_24 ;
struct V_26 * V_27 = & V_17 -> V_21 ;
F_20 ( V_37 > F_10 ( V_18 -> V_10 ) ) ;
F_20 ( V_37 < F_10 ( V_18 -> V_24 ) ) ;
V_24 = F_10 ( V_18 -> V_24 ) ;
for ( V_23 = V_24 ; V_23 < V_37 ; V_23 ++ ) {
if ( V_27 -> V_28 )
V_27 -> V_28 ( V_27 -> V_25 , V_36 ) ;
memcpy ( F_11 ( V_17 , V_18 , V_23 ) , V_36 , V_27 -> V_22 ) ;
}
V_18 -> V_24 = F_5 ( V_37 ) ;
}
static void F_21 ( struct V_16 * V_17 , struct V_6 * V_18 ,
unsigned V_37 )
{
unsigned V_23 ;
T_2 V_24 ;
struct V_26 * V_27 = & V_17 -> V_21 ;
F_20 ( V_37 > F_10 ( V_18 -> V_10 ) ) ;
F_20 ( V_37 > F_10 ( V_18 -> V_24 ) ) ;
V_24 = F_10 ( V_18 -> V_24 ) ;
for ( V_23 = V_24 ; V_23 > V_37 ; V_23 -- )
if ( V_27 -> V_29 )
V_27 -> V_29 ( V_27 -> V_25 , F_11 ( V_17 , V_18 , V_23 - 1 ) ) ;
V_18 -> V_24 = F_5 ( V_37 ) ;
}
static int F_22 ( struct V_16 * V_17 , T_3 V_4 ,
struct V_3 * * V_31 , struct V_6 * * V_18 )
{
int V_32 ;
V_32 = F_23 ( V_17 -> V_33 . V_34 , V_4 , & V_35 , V_31 ) ;
if ( V_32 )
return V_32 ;
* V_18 = F_2 ( * V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_16 * V_17 , struct V_3 * V_31 )
{
return F_25 ( V_17 -> V_33 . V_34 , V_31 ) ;
}
static int F_26 ( struct V_16 * V_17 , T_3 V_38 ,
unsigned V_19 , struct V_3 * * V_31 ,
struct V_6 * * V_18 )
{
int V_32 ;
T_4 V_39 = V_19 ;
T_5 V_40 ;
V_32 = F_27 ( & V_17 -> V_33 , V_38 , & V_39 , & V_40 ) ;
if ( V_32 )
return V_32 ;
return F_22 ( V_17 , F_8 ( V_40 ) , V_31 , V_18 ) ;
}
static int F_28 ( struct V_16 * V_17 , T_4 V_19 ,
struct V_3 * V_31 , T_3 * V_38 )
{
T_5 V_40 = F_3 ( F_4 ( V_31 ) ) ;
F_29 ( V_40 ) ;
return F_30 ( & V_17 -> V_33 , * V_38 , & V_19 , & V_40 , V_38 ) ;
}
static int F_31 ( struct V_16 * V_17 , T_3 * V_38 ,
unsigned V_19 , struct V_3 * * V_31 ,
struct V_6 * * V_18 )
{
int V_32 , V_28 ;
T_4 V_39 = V_19 ;
T_3 V_4 ;
T_5 V_40 ;
V_32 = F_27 ( & V_17 -> V_33 , * V_38 , & V_39 , & V_40 ) ;
if ( V_32 )
return V_32 ;
V_4 = F_8 ( V_40 ) ;
V_32 = F_32 ( V_17 -> V_33 . V_34 , V_4 ,
& V_35 , V_31 , & V_28 ) ;
if ( V_32 )
return V_32 ;
* V_18 = F_2 ( * V_31 ) ;
if ( V_28 )
F_14 ( V_17 , * V_18 ) ;
if ( F_4 ( * V_31 ) != V_4 ) {
F_33 ( V_17 -> V_33 . V_34 , V_4 ) ;
V_32 = F_28 ( V_17 , V_19 , * V_31 , V_38 ) ;
}
return V_32 ;
}
static int F_34 ( struct V_16 * V_17 , T_1 V_5 ,
T_2 V_10 ,
unsigned V_41 , T_2 V_42 ,
const void * V_36 , T_3 * V_38 )
{
int V_32 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
V_32 = F_17 ( V_17 , V_5 , V_10 , & V_31 , & V_18 ) ;
if ( V_32 )
return V_32 ;
F_19 ( V_17 , V_18 , V_36 , V_42 ) ;
V_32 = F_28 ( V_17 , V_41 , V_31 , V_38 ) ;
F_24 ( V_17 , V_31 ) ;
return V_32 ;
}
static int F_35 ( struct V_16 * V_17 , T_1 V_5 ,
unsigned V_43 , unsigned V_44 ,
unsigned V_10 , const void * V_36 ,
T_3 * V_38 )
{
int V_32 = 0 ;
for (; ! V_32 && V_43 != V_44 ; V_43 ++ )
V_32 = F_34 ( V_17 , V_5 , V_10 , V_43 , V_10 , V_36 , V_38 ) ;
return V_32 ;
}
static int F_36 ( struct V_45 * V_45 , unsigned V_46 ,
unsigned V_47 )
{
int V_32 ;
while ( V_46 != V_47 ) {
T_4 V_39 = V_46 ++ ;
V_32 = F_37 ( & V_45 -> V_17 -> V_33 , V_45 -> V_38 ,
& V_39 , & V_45 -> V_38 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static unsigned F_38 ( unsigned V_48 ,
unsigned V_49 )
{
return V_48 + ( V_49 ? 1 : 0 ) ;
}
static int F_39 ( struct V_45 * V_45 )
{
int V_32 ;
unsigned V_50 , V_51 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
if ( V_45 -> V_52 < V_45 -> V_53 ) {
V_50 = F_38 ( V_45 -> V_52 ,
V_45 -> V_54 ) ;
V_51 = F_38 ( V_45 -> V_53 ,
V_45 -> V_55 ) ;
V_32 = F_36 ( V_45 , V_50 , V_51 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_45 -> V_54 ) {
V_32 = F_31 ( V_45 -> V_17 , & V_45 -> V_38 ,
V_45 -> V_52 , & V_31 , & V_18 ) ;
if ( V_32 )
return V_32 ;
F_21 ( V_45 -> V_17 , V_18 , V_45 -> V_54 ) ;
F_24 ( V_45 -> V_17 , V_31 ) ;
}
return 0 ;
}
static int F_40 ( struct V_45 * V_45 , T_2 V_56 )
{
int V_32 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
V_32 = F_31 ( V_45 -> V_17 , & V_45 -> V_38 ,
V_45 -> V_53 , & V_31 , & V_18 ) ;
if ( V_32 )
return V_32 ;
F_19 ( V_45 -> V_17 , V_18 , V_45 -> V_36 , V_56 ) ;
F_24 ( V_45 -> V_17 , V_31 ) ;
return V_32 ;
}
static int F_41 ( struct V_45 * V_45 )
{
return F_34 ( V_45 -> V_17 , V_45 -> V_5 ,
V_45 -> V_10 ,
V_45 -> V_52 ,
V_45 -> V_54 ,
V_45 -> V_36 , & V_45 -> V_38 ) ;
}
static int F_42 ( struct V_45 * V_45 )
{
int V_32 ;
unsigned V_57 = V_45 -> V_53 ;
if ( V_45 -> V_55 > 0 ) {
V_57 ++ ;
V_32 = F_40 ( V_45 , V_45 -> V_10 ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_35 ( V_45 -> V_17 , V_45 -> V_5 ,
V_57 ,
V_45 -> V_52 ,
V_45 -> V_10 , V_45 -> V_36 ,
& V_45 -> V_38 ) ;
if ( V_32 )
return V_32 ;
if ( V_45 -> V_54 )
V_32 = F_41 ( V_45 ) ;
return V_32 ;
}
static int F_43 ( struct V_45 * V_45 )
{
if ( V_45 -> V_52 > V_45 -> V_53 )
return F_42 ( V_45 ) ;
else if ( V_45 -> V_55 )
return F_40 ( V_45 , V_45 -> V_54 ) ;
else
return F_41 ( V_45 ) ;
}
static void F_44 ( void * V_25 , const void * V_36 )
{
T_5 V_40 ;
struct V_16 * V_17 = V_25 ;
memcpy ( & V_40 , V_36 , sizeof( V_40 ) ) ;
F_33 ( V_17 -> V_33 . V_34 , F_8 ( V_40 ) ) ;
}
static void F_45 ( void * V_25 , const void * V_36 )
{
int V_32 ;
T_4 V_4 ;
T_5 V_40 ;
T_2 V_58 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
struct V_16 * V_17 = V_25 ;
memcpy ( & V_40 , V_36 , sizeof( V_40 ) ) ;
V_4 = F_8 ( V_40 ) ;
V_32 = F_46 ( V_17 -> V_33 . V_34 , V_4 , & V_58 ) ;
if ( V_32 ) {
F_9 ( L_3 ,
( unsigned long long ) V_4 ) ;
return;
}
if ( V_58 == 1 ) {
V_32 = F_22 ( V_17 , V_4 , & V_31 , & V_18 ) ;
if ( V_32 ) {
F_9 ( L_4 ,
( unsigned long long ) V_4 ) ;
return;
}
F_15 ( V_17 , V_18 ) ;
F_24 ( V_17 , V_31 ) ;
}
F_47 ( V_17 -> V_33 . V_34 , V_4 ) ;
}
static int F_48 ( void * V_25 , const void * V_59 , const void * V_60 )
{
return ! memcmp ( V_59 , V_60 , sizeof( T_5 ) ) ;
}
void F_49 ( struct V_16 * V_17 ,
struct V_61 * V_34 ,
struct V_26 * V_27 )
{
struct V_26 * V_62 = & V_17 -> V_33 . V_21 ;
memcpy ( & V_17 -> V_21 , V_27 , sizeof( V_17 -> V_21 ) ) ;
V_17 -> V_33 . V_34 = V_34 ;
V_17 -> V_33 . V_63 = 1 ;
V_62 -> V_25 = V_17 ;
V_62 -> V_22 = sizeof( T_5 ) ;
V_62 -> V_28 = F_44 ;
V_62 -> V_29 = F_45 ;
V_62 -> V_64 = F_48 ;
}
int F_50 ( struct V_16 * V_17 , T_3 * V_38 )
{
return F_51 ( & V_17 -> V_33 , V_38 ) ;
}
static int F_52 ( struct V_16 * V_17 , T_3 V_38 ,
T_2 V_65 , T_2 V_66 ,
const void * V_36 , T_3 * V_67 )
{
int V_32 ;
struct V_45 V_45 ;
if ( V_65 == V_66 ) {
* V_67 = V_38 ;
return 0 ;
}
V_45 . V_17 = V_17 ;
V_45 . V_38 = V_38 ;
V_45 . V_5 = F_53 ( F_54 ( V_17 -> V_33 . V_34 ) ) ;
V_45 . V_10 = F_16 ( V_17 -> V_21 . V_22 ,
V_45 . V_5 ) ;
V_45 . V_53 = V_65 / V_45 . V_10 ;
V_45 . V_55 = V_65 % V_45 . V_10 ;
V_45 . V_52 = V_66 / V_45 . V_10 ;
V_45 . V_54 = V_66 % V_45 . V_10 ;
V_45 . V_36 = V_36 ;
V_32 = ( ( V_66 > V_65 ) ? F_43 : F_39 ) ( & V_45 ) ;
if ( V_32 )
return V_32 ;
* V_67 = V_45 . V_38 ;
return 0 ;
}
int F_55 ( struct V_16 * V_17 , T_3 V_38 ,
T_2 V_65 , T_2 V_66 ,
const void * V_36 , T_3 * V_67 )
__dm_written_to_disk( V_36 )
{
int V_32 = F_52 ( V_17 , V_38 , V_65 , V_66 , V_36 , V_67 ) ;
F_56 ( V_36 ) ;
return V_32 ;
}
int F_57 ( struct V_16 * V_17 , T_3 V_38 )
{
return F_58 ( & V_17 -> V_33 , V_38 ) ;
}
int F_59 ( struct V_16 * V_17 , T_3 V_38 ,
T_2 V_19 , void * V_68 )
{
int V_32 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
T_1 V_5 ;
unsigned V_20 , V_10 ;
V_5 = F_53 ( F_54 ( V_17 -> V_33 . V_34 ) ) ;
V_10 = F_16 ( V_17 -> V_21 . V_22 , V_5 ) ;
V_32 = F_26 ( V_17 , V_38 , V_19 / V_10 , & V_31 , & V_18 ) ;
if ( V_32 )
return V_32 ;
V_20 = V_19 % V_10 ;
if ( V_20 >= F_10 ( V_18 -> V_24 ) )
V_32 = - V_69 ;
else
memcpy ( V_68 , F_11 ( V_17 , V_18 , V_20 ) ,
V_17 -> V_21 . V_22 ) ;
F_24 ( V_17 , V_31 ) ;
return V_32 ;
}
static int F_60 ( struct V_16 * V_17 , T_3 V_38 ,
T_2 V_19 , const void * V_36 , T_3 * V_67 )
{
int V_32 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
T_1 V_5 ;
unsigned V_10 ;
unsigned V_20 ;
void * V_70 ;
struct V_26 * V_27 = & V_17 -> V_21 ;
V_5 = F_53 ( F_54 ( V_17 -> V_33 . V_34 ) ) ;
V_10 = F_16 ( V_17 -> V_21 . V_22 , V_5 ) ;
V_32 = F_31 ( V_17 , & V_38 , V_19 / V_10 , & V_31 , & V_18 ) ;
if ( V_32 )
return V_32 ;
* V_67 = V_38 ;
V_20 = V_19 % V_10 ;
if ( V_20 >= F_10 ( V_18 -> V_24 ) ) {
V_32 = - V_69 ;
goto V_71;
}
V_70 = F_11 ( V_17 , V_18 , V_20 ) ;
if ( V_27 -> V_29 &&
( ! V_27 -> V_64 || ! V_27 -> V_64 ( V_27 -> V_25 , V_70 , V_36 ) ) ) {
V_27 -> V_29 ( V_27 -> V_25 , V_70 ) ;
if ( V_27 -> V_28 )
V_27 -> V_28 ( V_27 -> V_25 , V_36 ) ;
}
memcpy ( V_70 , V_36 , V_17 -> V_21 . V_22 ) ;
V_71:
F_24 ( V_17 , V_31 ) ;
return V_32 ;
}
int F_61 ( struct V_16 * V_17 , T_3 V_38 ,
T_2 V_19 , const void * V_36 , T_3 * V_67 )
__dm_written_to_disk( V_36 )
{
int V_32 ;
V_32 = F_60 ( V_17 , V_38 , V_19 , V_36 , V_67 ) ;
F_56 ( V_36 ) ;
return V_32 ;
}
static int F_62 ( void * V_25 , T_4 * V_72 , void * V_73 )
{
struct V_74 * V_75 = V_25 ;
int V_32 ;
unsigned V_23 ;
T_5 V_40 ;
unsigned V_24 , V_10 ;
struct V_3 * V_31 ;
struct V_6 * V_18 ;
memcpy ( & V_40 , V_73 , sizeof( V_40 ) ) ;
V_32 = F_22 ( V_75 -> V_17 , F_8 ( V_40 ) , & V_31 , & V_18 ) ;
if ( V_32 )
return V_32 ;
V_10 = F_10 ( V_18 -> V_10 ) ;
V_24 = F_10 ( V_18 -> V_24 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_32 = V_75 -> F_13 ( V_75 -> V_25 , V_72 [ 0 ] * V_10 + V_23 ,
F_11 ( V_75 -> V_17 , V_18 , V_23 ) ) ;
if ( V_32 )
break;
}
F_24 ( V_75 -> V_17 , V_31 ) ;
return V_32 ;
}
int F_63 ( struct V_16 * V_17 , T_3 V_38 ,
int (* F_13)( void * , T_4 V_39 , void * V_73 ) ,
void * V_25 )
{
struct V_74 V_75 ;
V_75 . V_17 = V_17 ;
V_75 . F_13 = F_13 ;
V_75 . V_25 = V_25 ;
return F_64 ( & V_17 -> V_33 , V_38 , F_62 , & V_75 ) ;
}
