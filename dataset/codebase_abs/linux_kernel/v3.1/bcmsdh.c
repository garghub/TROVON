struct V_1 *
F_1 ( void * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( struct V_1 ) , V_6 ) ;
if ( V_5 == NULL ) {
F_3 ( ( L_1 ) ) ;
return NULL ;
}
V_7 = V_5 ;
V_5 -> V_8 = F_4 ( V_2 , V_4 ) ;
if ( ! V_5 -> V_8 ) {
F_5 ( V_5 ) ;
return NULL ;
}
V_5 -> V_9 = true ;
* V_3 = V_10 ;
V_5 -> V_11 = V_10 ;
return V_5 ;
}
int F_5 ( struct V_1 * V_5 )
{
if ( V_5 != NULL ) {
if ( V_5 -> V_8 ) {
F_6 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
F_7 ( V_5 ) ;
}
V_7 = NULL ;
return 0 ;
}
int
F_8 ( struct V_1 * V_5 , const char * V_12 ,
void * V_13 , int V_14 , void * V_15 , int V_16 , bool V_17 )
{
return F_9 ( V_5 -> V_8 , V_12 , V_13 , V_14 , V_15 ,
V_16 , V_17 ) ;
}
int F_10 ( struct V_1 * V_5 )
{
return F_11 ( V_5 -> V_8 , true ) ;
}
int F_12 ( struct V_1 * V_5 )
{
return F_11 ( V_5 -> V_8 , false ) ;
}
int F_13 ( struct V_1 * V_5 ,
void (* F_14)( void * ) , void * V_18 )
{
return F_15 ( V_5 -> V_8 , F_14 , V_18 ) ;
}
int F_16 ( struct V_1 * V_5 )
{
return F_17 ( V_5 -> V_8 ) ;
}
T_3 F_18 ( struct V_1 * V_5 , T_2 V_19 , T_1 V_20 ,
int * V_21 )
{
int V_22 ;
T_4 V_23 = 0 ;
T_3 V_24 = 0 ;
if ( ! V_5 )
V_5 = V_7 ;
do {
if ( V_23 )
F_19 ( 1000 ) ;
V_22 =
F_20 ( V_5 -> V_8 , V_19 , V_20 ,
( T_3 * ) & V_24 ) ;
} while ( V_22 != 0
&& ( V_23 ++ < V_25 ) );
if ( V_21 )
* V_21 = V_22 ;
F_21 ( ( L_2 ,
V_26 , V_19 , V_20 , V_24 ) ) ;
return V_24 ;
}
void
F_22 ( struct V_1 * V_5 , T_2 V_19 , T_1 V_20 ,
T_3 V_24 , int * V_21 )
{
int V_22 ;
T_4 V_23 = 0 ;
if ( ! V_5 )
V_5 = V_7 ;
do {
if ( V_23 )
F_19 ( 1000 ) ;
V_22 =
F_23 ( V_5 -> V_8 , V_19 , V_20 ,
( T_3 * ) & V_24 ) ;
} while ( V_22 != 0
&& ( V_23 ++ < V_25 ) );
if ( V_21 )
* V_21 = V_22 ;
F_21 ( ( L_2 ,
V_26 , V_19 , V_20 , V_24 ) ) ;
}
T_1 F_24 ( struct V_1 * V_5 , T_2 V_19 ,
T_1 V_20 , int * V_21 )
{
int V_22 ;
T_1 V_24 = 0 ;
if ( ! V_5 )
V_5 = V_7 ;
V_22 = F_25 ( V_5 -> V_8 , V_27 ,
V_28 , V_19 , V_20 , & V_24 , 4 ) ;
if ( V_21 )
* V_21 = V_22 ;
F_21 ( ( L_3 ,
V_26 , V_19 , V_20 , V_24 ) ) ;
return V_24 ;
}
void
F_26 ( struct V_1 * V_5 , T_2 V_19 ,
T_1 V_20 , T_1 V_24 , int * V_21 )
{
int V_22 ;
if ( ! V_5 )
V_5 = V_7 ;
V_22 =
F_25 ( V_5 -> V_8 , V_27 ,
V_29 , V_19 , V_20 , & V_24 , 4 ) ;
if ( V_21 )
* V_21 = V_22 ;
F_21 ( ( L_3 ,
V_26 , V_19 , V_20 , V_24 ) ) ;
}
int F_27 ( struct V_1 * V_5 , T_2 V_30 , T_3 * V_31 ,
T_2 V_32 )
{
int V_22 ;
T_3 * V_33 , * V_34 ;
T_3 * V_35 ;
bool V_36 = V_30 & ~ 0xf ;
V_30 &= 0x7 ;
if ( ! V_5 )
V_5 = V_7 ;
V_22 = F_28 ( V_5 -> V_8 , V_30 , V_31 , V_32 ) ;
if ( V_36 ) {
V_33 = F_29 ( V_32 , V_6 ) ;
if ( V_33 == NULL ) {
F_3 ( ( L_4 , V_26 ) ) ;
return - V_37 ;
}
memcpy ( V_33 , V_31 , V_32 ) ;
for ( V_34 = V_33 , V_35 = V_31 ; V_35 < ( V_31 + V_32 - 4 ) ;
V_34 ++ ) {
V_35 += sprintf ( ( char * ) V_35 , L_5 , * V_34 & 0xff ) ;
if ( ( ( ( V_34 - V_33 ) + 1 ) & 0xf ) == 0 )
V_35 += sprintf ( ( char * ) V_35 , L_6 ) ;
}
F_7 ( V_33 ) ;
}
return V_22 ;
}
static int
F_30 ( struct V_1 * V_5 , T_1 V_38 )
{
int V_21 = 0 ;
F_22 ( V_5 , V_39 , V_40 ,
( V_38 >> 8 ) & V_41 , & V_21 ) ;
if ( ! V_21 )
F_22 ( V_5 , V_39 ,
V_42 ,
( V_38 >> 16 ) & V_43 ,
& V_21 ) ;
if ( ! V_21 )
F_22 ( V_5 , V_39 ,
V_44 ,
( V_38 >> 24 ) & V_45 ,
& V_21 ) ;
return V_21 ;
}
T_1 F_31 ( struct V_1 * V_5 , T_1 V_20 , T_2 V_46 )
{
int V_22 ;
T_1 V_47 = 0 ;
T_2 V_48 = V_20 & ~ V_49 ;
F_21 ( ( L_7 , V_26 , V_20 ) ) ;
if ( ! V_5 )
V_5 = V_7 ;
if ( V_48 != V_5 -> V_11 ) {
if ( F_30 ( V_5 , V_48 ) )
return 0xFFFFFFFF ;
V_5 -> V_11 = V_48 ;
}
V_20 &= V_49 ;
if ( V_46 == 4 )
V_20 |= V_50 ;
V_22 = F_25 ( V_5 -> V_8 , V_27 ,
V_28 , V_39 , V_20 , & V_47 , V_46 ) ;
V_5 -> V_51 = ( V_22 != 0 ) ;
F_21 ( ( L_8 , V_47 ) ) ;
if ( V_22 == 0 ) {
switch ( V_46 ) {
case sizeof( T_3 ) :
return V_47 & 0xff ;
case sizeof( V_52 ) :
return V_47 & 0xffff ;
case sizeof( T_1 ) :
return V_47 ;
default:
V_5 -> V_51 = true ;
}
}
F_3 ( ( L_9 , V_26 ,
V_20 , V_46 ) ) ;
return 0xFFFFFFFF ;
}
T_1 F_32 ( struct V_1 * V_5 , T_1 V_20 , T_2 V_46 ,
T_1 V_24 )
{
int V_22 ;
T_2 V_48 = V_20 & ~ V_49 ;
int V_21 = 0 ;
F_21 ( ( L_10 ,
V_26 , V_20 , V_46 * 8 , V_24 ) ) ;
if ( ! V_5 )
V_5 = V_7 ;
if ( V_48 != V_5 -> V_11 ) {
V_21 = F_30 ( V_5 , V_48 ) ;
if ( V_21 )
return V_21 ;
V_5 -> V_11 = V_48 ;
}
V_20 &= V_49 ;
if ( V_46 == 4 )
V_20 |= V_50 ;
V_22 =
F_25 ( V_5 -> V_8 , V_27 ,
V_29 , V_39 , V_20 , & V_24 , V_46 ) ;
V_5 -> V_51 = ( V_22 != 0 ) ;
if ( V_22 == 0 )
return 0 ;
F_3 ( ( L_11 ,
V_26 , V_24 , V_20 , V_46 ) ) ;
return 0xFFFFFFFF ;
}
bool F_33 ( struct V_1 * V_5 )
{
return V_5 -> V_51 ;
}
int
F_34 ( struct V_1 * V_5 , T_1 V_20 , T_2 F_14 ,
T_2 V_53 ,
T_3 * V_54 , T_2 V_55 , struct V_56 * V_57 ,
void (* F_35)( void * V_58 , int V_22 ,
bool V_59 ) ,
void * V_58 )
{
int V_22 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_48 = V_20 & ~ V_49 ;
int V_21 = 0 ;
F_21 ( ( L_12 ,
V_26 , F_14 , V_20 , V_55 ) ) ;
if ( V_53 & V_62 )
return - V_63 ;
if ( V_48 != V_5 -> V_11 ) {
V_21 = F_30 ( V_5 , V_48 ) ;
if ( V_21 )
return V_21 ;
V_5 -> V_11 = V_48 ;
}
V_20 &= V_49 ;
V_60 = ( V_53 & V_64 ) ? V_65 : V_66 ;
V_61 = ( V_53 & V_67 ) ? 4 : 2 ;
if ( V_61 == 4 )
V_20 |= V_50 ;
V_22 = F_36 ( V_5 -> V_8 , V_68 ,
V_60 , V_28 , F_14 , V_20 , V_61 , V_55 , V_54 , V_57 ) ;
return V_22 ;
}
int
F_37 ( struct V_1 * V_5 , T_1 V_20 , T_2 F_14 ,
T_2 V_53 , T_3 * V_54 , T_2 V_55 , void * V_57 ,
void (* F_35)( void * V_58 , int V_22 ,
bool V_59 ) ,
void * V_58 )
{
T_2 V_60 ;
T_2 V_61 ;
T_2 V_48 = V_20 & ~ V_49 ;
int V_21 = 0 ;
F_21 ( ( L_12 ,
V_26 , F_14 , V_20 , V_55 ) ) ;
if ( V_53 & V_62 )
return - V_63 ;
if ( V_48 != V_5 -> V_11 ) {
V_21 = F_30 ( V_5 , V_48 ) ;
if ( V_21 )
return V_21 ;
V_5 -> V_11 = V_48 ;
}
V_20 &= V_49 ;
V_60 = ( V_53 & V_64 ) ? V_65 : V_66 ;
V_61 = ( V_53 & V_67 ) ? 4 : 2 ;
if ( V_61 == 4 )
V_20 |= V_50 ;
return F_36 ( V_5 -> V_8 , V_68 ,
V_60 , V_29 , F_14 , V_20 , V_61 , V_55 , V_54 , V_57 ) ;
}
int F_38 ( struct V_1 * V_5 , T_2 V_69 , T_1 V_20 ,
T_3 * V_54 , T_2 V_55 )
{
V_20 &= V_49 ;
V_20 |= V_50 ;
return F_36 ( V_5 -> V_8 , V_68 ,
V_66 , ( V_69 ? V_29 : V_28 ) , V_39 ,
V_20 , 4 , V_55 , V_54 , NULL ) ;
}
int F_39 ( struct V_1 * V_5 , T_2 F_14 )
{
return F_40 ( V_5 -> V_8 , F_14 ) ;
}
int F_41 ( struct V_1 * V_5 )
{
V_5 -> V_70 = ( V_71 << 16 ) | 0 ;
return V_5 -> V_70 ;
}
T_1 F_42 ( struct V_1 * V_5 )
{
if ( ! V_5 )
V_5 = V_7 ;
return V_5 -> V_11 ;
}
int F_43 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = NULL ;
T_1 V_76 = 0 ;
struct V_1 * V_5 = NULL ;
int V_4 = 0 ;
T_1 V_70 ;
unsigned long V_77 = 0 ;
V_75 = F_2 ( sizeof( struct V_74 ) , V_6 ) ;
if ( ! V_75 ) {
F_44 ( ( L_4 , V_26 ) ) ;
goto V_21;
}
V_75 -> V_73 = ( void * ) V_73 ;
V_5 = F_1 ( ( void * ) 0 , & V_76 , V_4 ) ;
if ( ! V_5 ) {
F_44 ( ( L_13 , V_26 ) ) ;
goto V_21;
}
V_75 -> V_5 = V_5 ;
V_75 -> V_78 = V_4 ;
V_75 -> V_79 = V_77 ;
V_75 -> V_80 = false ;
V_75 -> V_81 = V_82 ;
V_82 = V_75 ;
V_70 = F_41 ( V_5 ) ;
V_75 -> V_83 = V_84 . V_85 ( ( V_70 >> 16 ) , ( V_70 & 0xFFFF ) ,
0 , 0 , 0 , 0 , V_76 , V_5 ) ;
if ( ! V_75 -> V_83 ) {
F_44 ( ( L_14 , V_26 ) ) ;
goto V_21;
}
return 0 ;
V_21:
if ( V_75 ) {
if ( V_75 -> V_5 )
F_5 ( V_75 -> V_5 ) ;
F_7 ( V_75 ) ;
}
return - V_86 ;
}
int F_45 ( struct V_72 * V_73 )
{
struct V_74 * V_75 , * V_87 ;
V_75 = V_82 ;
V_84 . V_88 ( V_75 -> V_83 ) ;
F_5 ( V_75 -> V_5 ) ;
for ( V_75 = V_82 , V_87 = NULL ; V_75 ; V_75 = V_75 -> V_81 ) {
if ( V_75 -> V_73 == ( void * ) V_73 ) {
if ( V_87 )
V_87 -> V_81 = V_75 -> V_81 ;
else
V_82 = NULL ;
break;
}
V_87 = V_75 ;
}
if ( ! V_75 ) {
F_44 ( ( L_15 , V_26 ) ) ;
return 0 ;
}
F_7 ( V_75 ) ;
return 0 ;
}
int F_46 ( struct V_89 * V_90 )
{
V_84 = * V_90 ;
F_44 ( ( L_16 ) ) ;
return F_47 () ;
}
void F_48 ( void )
{
F_49 () ;
}
void F_50 ( bool V_91 )
{
if ( V_91 )
F_51 ( V_82 -> V_83 , V_92 ) ;
else
F_51 ( V_82 -> V_83 , 0 ) ;
}
