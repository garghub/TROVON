void F_1 ( T_1 * V_1 , bool V_2 )
{
F_2 ( V_1 -> V_3 , V_2 ) ;
}
T_1 * F_3 ( void * V_4 , void * * V_5 , T_2 V_6 )
{
T_1 * V_7 ;
V_7 = F_4 ( sizeof( T_1 ) , V_8 ) ;
if ( V_7 == NULL ) {
F_5 ( ( L_1 ) ) ;
return NULL ;
}
V_9 = V_7 ;
V_7 -> V_3 = F_6 ( V_4 , V_6 ) ;
if ( ! V_7 -> V_3 ) {
F_7 ( V_7 ) ;
return NULL ;
}
V_7 -> V_10 = true ;
* V_5 = ( V_11 * ) V_12 ;
V_7 -> V_13 = V_12 ;
return V_7 ;
}
int F_7 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
if ( V_7 != NULL ) {
if ( V_7 -> V_3 ) {
F_8 ( V_7 -> V_3 ) ;
V_7 -> V_3 = NULL ;
}
F_9 ( V_7 ) ;
}
V_9 = NULL ;
return 0 ;
}
int
F_10 ( void * V_1 , const char * V_14 ,
void * V_15 , int V_16 , void * V_17 , int V_18 , bool V_19 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
return F_11 ( V_7 -> V_3 , V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
}
bool F_12 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
bool V_21 ;
ASSERT ( V_7 ) ;
V_20 = F_13 ( V_7 -> V_3 , & V_21 ) ;
if ( F_14 ( V_20 ) )
return false ;
else
return V_21 ;
}
int F_15 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
ASSERT ( V_7 ) ;
V_20 = F_16 ( V_7 -> V_3 , true ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
int F_17 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
ASSERT ( V_7 ) ;
V_20 = F_16 ( V_7 -> V_3 , false ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
int F_18 ( void * V_1 , T_4 V_23 , void * V_24 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
ASSERT ( V_7 ) ;
V_20 = F_19 ( V_7 -> V_3 , V_23 , V_24 ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
int F_20 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
ASSERT ( V_7 ) ;
V_20 = F_21 ( V_7 -> V_3 ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
bool F_22 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
ASSERT ( V_1 ) ;
return F_23 ( V_7 -> V_3 ) ;
}
int F_24 ( void * V_1 , T_4 V_23 , void * V_24 )
{
ASSERT ( V_1 ) ;
return - V_25 ;
}
T_5 F_25 ( void * V_1 , T_2 V_26 , V_11 V_27 , int * V_28 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
#ifdef F_26
T_6 V_29 = 0 ;
#endif
T_5 V_30 = 0 ;
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
#ifdef F_26
do {
if ( V_29 )
F_27 ( 1000 ) ;
#endif
V_20 =
F_28 ( V_7 -> V_3 , V_26 , V_27 ,
( T_5 * ) & V_30 ) ;
#ifdef F_26
} while ( ! F_14 ( V_20 )
&& ( V_29 ++ < F_26 ) );
#endif
if ( V_28 )
* V_28 = ( F_14 ( V_20 ) ? 0 : - V_22 ) ;
F_29 ( ( L_2 ,
V_31 , V_26 , V_27 , V_30 ) ) ;
return V_30 ;
}
void
F_30 ( void * V_1 , T_2 V_26 , V_11 V_27 , T_5 V_30 , int * V_28 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
#ifdef F_26
T_6 V_29 = 0 ;
#endif
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
#ifdef F_26
do {
if ( V_29 )
F_27 ( 1000 ) ;
#endif
V_20 =
F_31 ( V_7 -> V_3 , V_26 , V_27 ,
( T_5 * ) & V_30 ) ;
#ifdef F_26
} while ( ! F_14 ( V_20 )
&& ( V_29 ++ < F_26 ) );
#endif
if ( V_28 )
* V_28 = F_14 ( V_20 ) ? 0 : - V_22 ;
F_29 ( ( L_2 ,
V_31 , V_26 , V_27 , V_30 ) ) ;
}
V_11 F_32 ( void * V_1 , T_2 V_26 , V_11 V_27 , int * V_28 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
V_11 V_30 = 0 ;
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
V_20 =
F_33 ( V_7 -> V_3 , V_32 , V_33 ,
V_26 , V_27 , & V_30 , 4 ) ;
if ( V_28 )
* V_28 = ( F_14 ( V_20 ) ? 0 : - V_22 ) ;
F_29 ( ( L_3 ,
V_31 , V_26 , V_27 , V_30 ) ) ;
return V_30 ;
}
void
F_34 ( void * V_1 , T_2 V_26 , V_11 V_27 , V_11 V_30 ,
int * V_28 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
V_20 =
F_33 ( V_7 -> V_3 , V_32 ,
V_34 , V_26 , V_27 , & V_30 , 4 ) ;
if ( V_28 )
* V_28 = ( F_14 ( V_20 ) ? 0 : - V_22 ) ;
F_29 ( ( L_3 ,
V_31 , V_26 , V_27 , V_30 ) ) ;
}
int F_35 ( void * V_1 , T_2 V_35 , T_5 * V_36 , T_2 V_37 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
T_5 * V_38 , * V_39 ;
T_5 * V_40 ;
bool V_41 = V_35 & ~ 0xf ;
V_35 &= 0x7 ;
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
ASSERT ( V_36 ) ;
ASSERT ( V_37 <= V_42 ) ;
V_20 = F_36 ( V_7 -> V_3 , V_35 , V_36 , V_37 ) ;
if ( V_41 ) {
V_38 = F_37 ( V_37 , V_8 ) ;
if ( V_38 == NULL ) {
F_5 ( ( L_4 , V_31 ) ) ;
return - V_43 ;
}
memcpy ( V_38 , V_36 , V_37 ) ;
for ( V_39 = V_38 , V_40 = V_36 ; V_40 < ( V_36 + V_37 - 4 ) ;
V_39 ++ ) {
V_40 += sprintf ( ( char * ) V_40 , L_5 , * V_39 & 0xff ) ;
if ( ( ( ( V_39 - V_38 ) + 1 ) & 0xf ) == 0 )
V_40 += sprintf ( ( char * ) V_40 , L_6 ) ;
}
F_9 ( V_38 ) ;
}
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
static int F_38 ( void * V_1 , V_11 V_44 )
{
int V_28 = 0 ;
T_1 * V_7 = ( T_1 * ) V_1 ;
F_30 ( V_7 , V_45 , V_46 ,
( V_44 >> 8 ) & V_47 , & V_28 ) ;
if ( ! V_28 )
F_30 ( V_7 , V_45 , V_48 ,
( V_44 >> 16 ) & V_49 , & V_28 ) ;
if ( ! V_28 )
F_30 ( V_7 , V_45 , V_50 ,
( V_44 >> 24 ) & V_51 ,
& V_28 ) ;
return V_28 ;
}
V_11 F_39 ( void * V_1 , V_11 V_27 , T_2 V_52 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
V_11 V_53 = 0 ;
T_2 V_54 = V_27 & ~ V_55 ;
F_29 ( ( L_7 , V_31 , V_27 ) ) ;
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
if ( V_54 != V_7 -> V_13 ) {
if ( F_38 ( V_7 , V_54 ) )
return 0xFFFFFFFF ;
V_7 -> V_13 = V_54 ;
}
V_27 &= V_55 ;
if ( V_52 == 4 )
V_27 |= V_56 ;
V_20 = F_33 ( V_7 -> V_3 , V_32 ,
V_33 , V_45 , V_27 , & V_53 , V_52 ) ;
V_7 -> V_57 = ! ( F_14 ( V_20 ) ) ;
F_29 ( ( L_8 , V_53 ) ) ;
if ( F_14 ( V_20 ) ) {
switch ( V_52 ) {
case sizeof( T_5 ) :
return V_53 & 0xff ;
case sizeof( V_58 ) :
return V_53 & 0xffff ;
case sizeof( V_11 ) :
return V_53 ;
default:
V_7 -> V_57 = true ;
}
}
F_5 ( ( L_9 , V_31 ,
V_27 , V_52 ) ) ;
return 0xFFFFFFFF ;
}
V_11 F_40 ( void * V_1 , V_11 V_27 , T_2 V_52 , V_11 V_30 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
T_2 V_54 = V_27 & ~ V_55 ;
int V_28 = 0 ;
F_29 ( ( L_10 ,
V_31 , V_27 , V_52 * 8 , V_30 ) ) ;
if ( ! V_7 )
V_7 = V_9 ;
ASSERT ( V_7 -> V_10 ) ;
if ( V_54 != V_7 -> V_13 ) {
V_28 = F_38 ( V_7 , V_54 ) ;
if ( V_28 )
return V_28 ;
V_7 -> V_13 = V_54 ;
}
V_27 &= V_55 ;
if ( V_52 == 4 )
V_27 |= V_56 ;
V_20 =
F_33 ( V_7 -> V_3 , V_32 ,
V_34 , V_45 , V_27 , & V_30 , V_52 ) ;
V_7 -> V_57 = ! ( F_14 ( V_20 ) ) ;
if ( F_14 ( V_20 ) )
return 0 ;
F_5 ( ( L_11 ,
V_31 , V_30 , V_27 , V_52 ) ) ;
return 0xFFFFFFFF ;
}
bool F_41 ( void * V_1 )
{
return ( ( T_1 * ) V_1 ) -> V_57 ;
}
int
F_42 ( void * V_1 , V_11 V_27 , T_2 V_23 , T_2 V_59 ,
T_5 * V_60 , T_2 V_61 , struct V_62 * V_63 ,
T_7 V_64 , void * V_65 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
T_2 V_66 ;
T_2 V_67 ;
T_2 V_54 = V_27 & ~ V_55 ;
int V_28 = 0 ;
ASSERT ( V_7 ) ;
ASSERT ( V_7 -> V_10 ) ;
F_29 ( ( L_12 ,
V_31 , V_23 , V_27 , V_61 ) ) ;
ASSERT ( ! ( V_59 & V_68 ) ) ;
if ( V_59 & V_68 )
return - V_25 ;
if ( V_54 != V_7 -> V_13 ) {
V_28 = F_38 ( V_7 , V_54 ) ;
if ( V_28 )
return V_28 ;
V_7 -> V_13 = V_54 ;
}
V_27 &= V_55 ;
V_66 = ( V_59 & V_69 ) ? V_70 : V_71 ;
V_67 = ( V_59 & V_72 ) ? 4 : 2 ;
if ( V_67 == 4 )
V_27 |= V_56 ;
V_20 = F_43 ( V_7 -> V_3 , V_73 , V_66 ,
V_33 , V_23 , V_27 , V_67 , V_61 , V_60 ,
V_63 ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
int
F_44 ( void * V_1 , V_11 V_27 , T_2 V_23 , T_2 V_59 ,
T_5 * V_60 , T_2 V_61 , void * V_63 ,
T_7 V_64 , void * V_65 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
T_2 V_66 ;
T_2 V_67 ;
T_2 V_54 = V_27 & ~ V_55 ;
int V_28 = 0 ;
ASSERT ( V_7 ) ;
ASSERT ( V_7 -> V_10 ) ;
F_29 ( ( L_12 ,
V_31 , V_23 , V_27 , V_61 ) ) ;
ASSERT ( ! ( V_59 & V_68 ) ) ;
if ( V_59 & V_68 )
return - V_25 ;
if ( V_54 != V_7 -> V_13 ) {
V_28 = F_38 ( V_7 , V_54 ) ;
if ( V_28 )
return V_28 ;
V_7 -> V_13 = V_54 ;
}
V_27 &= V_55 ;
V_66 = ( V_59 & V_69 ) ? V_70 : V_71 ;
V_67 = ( V_59 & V_72 ) ? 4 : 2 ;
if ( V_67 == 4 )
V_27 |= V_56 ;
V_20 = F_43 ( V_7 -> V_3 , V_73 , V_66 ,
V_34 , V_23 , V_27 , V_67 , V_61 , V_60 ,
V_63 ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
int F_45 ( void * V_1 , T_2 V_74 , V_11 V_27 , T_5 * V_60 , T_2 V_61 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
T_3 V_20 ;
ASSERT ( V_7 ) ;
ASSERT ( V_7 -> V_10 ) ;
ASSERT ( ( V_27 & V_75 ) == 0 ) ;
V_27 &= V_55 ;
V_27 |= V_56 ;
V_20 =
F_43 ( V_7 -> V_3 , V_73 , V_71 ,
( V_74 ? V_34 : V_33 ) , V_45 ,
V_27 , 4 , V_61 , V_60 , NULL ) ;
return F_14 ( V_20 ) ? 0 : - V_22 ;
}
int F_46 ( void * V_1 , T_2 V_23 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
return F_47 ( V_7 -> V_3 , V_23 ) ;
}
int F_48 ( void * V_1 , int V_76 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
return F_49 ( V_7 -> V_3 , V_76 ) ;
}
int F_50 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
return F_51 ( V_7 -> V_3 ) ;
}
int F_52 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
V_7 -> V_77 = ( V_78 << 16 ) | 0 ;
return V_7 -> V_77 ;
}
T_2 F_53 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
if ( ! V_7 )
V_7 = V_9 ;
return F_54 ( V_7 -> V_3 ) ;
}
int F_55 ( T_1 * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
return F_56 ( V_7 -> V_3 ) ;
}
void * F_57 ( T_1 * V_1 )
{
ASSERT ( V_1 ) ;
return V_1 -> V_3 ;
}
V_11 F_58 ( void * V_1 )
{
return 0 ;
}
V_11 F_59 ( void * V_1 )
{
T_1 * V_7 = ( T_1 * ) V_1 ;
if ( ! V_7 )
V_7 = V_9 ;
return V_7 -> V_13 ;
}
void F_60 ( void * V_1 , V_11 V_79 , V_11 V_80 )
{
return;
}
