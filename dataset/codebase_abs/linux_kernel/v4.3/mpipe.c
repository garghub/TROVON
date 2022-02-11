int F_1 ( T_1 * V_1 , unsigned int V_2 )
{
char V_3 [ 32 ] ;
int V_4 ;
int V_5 ;
if ( V_2 >= V_6 )
return - V_7 ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 ) ;
V_4 = F_2 ( ( V_8 ) V_3 , 0 ) ;
V_1 -> V_4 = V_4 ;
if ( V_4 < 0 ) {
if ( V_4 >= V_9 && V_4 <= V_10 )
return V_4 ;
else
return - V_11 ;
}
V_1 -> V_12 = ( void V_13 * )
F_3 ( V_4 , V_14 ,
V_15 ) ;
if ( V_1 -> V_12 == NULL )
goto V_16;
V_1 -> V_17 = ( void V_13 * )
F_3 ( V_4 , V_18 ,
V_19 ) ;
if ( V_1 -> V_17 == NULL )
goto V_20;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
V_1 -> V_21 . V_22 [ V_5 ] = 255 ;
V_1 -> V_23 = V_2 ;
return 0 ;
V_20:
F_4 ( ( void V_13 V_24 * ) ( V_1 -> V_12 ) ) ;
V_16:
F_5 ( V_1 -> V_4 ) ;
V_1 -> V_4 = - 1 ;
return - V_11 ;
}
int F_6 ( T_1 * V_1 )
{
F_4 ( ( void V_13 V_24 * ) ( V_1 -> V_12 ) ) ;
F_4 ( ( void V_13 V_24 * ) ( V_1 -> V_17 ) ) ;
return F_5 ( V_1 -> V_4 ) ;
}
T_2 F_7 ( T_3
V_25 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 7 ; V_5 ++ )
if ( V_25 <= V_26 [ V_5 ] )
break;
return V_5 ;
}
T_3 F_8 ( T_2
V_27 )
{
if ( V_27 > 7 )
V_27 = 7 ;
return V_26 [ V_27 ] ;
}
T_3 F_9 ( unsigned long V_28 )
{
const int V_29 = 12 ;
unsigned long V_30 =
( V_28 + V_29 - 1 ) / V_29 ;
return V_30 * F_10 () ;
}
int F_11 ( T_1 * V_1 ,
unsigned int V_31 ,
T_2
V_27 , void * V_32 , T_3 V_33 ,
unsigned int V_34 )
{
int V_35 ;
memset ( V_32 , 0 , V_33 ) ;
V_35 = F_12 ( V_1 , V_32 , V_33 ,
V_34 , V_31 ,
V_27 ) ;
if ( V_35 < 0 )
return V_35 ;
V_1 -> V_21 . V_22 [ V_27 ] = V_31 ;
return 0 ;
}
int F_13 ( T_1 * V_1 ,
unsigned int V_36 ,
void * V_32 , T_3 V_33 ,
unsigned int V_34 )
{
return F_14 ( V_1 , V_32 , V_33 ,
V_34 , V_36 ) ;
}
int F_15 ( T_1 * V_1 ,
unsigned int V_37 ,
unsigned int V_36 ,
unsigned int V_38 ,
unsigned int V_39 ,
unsigned int V_40 ,
T_4 V_41 )
{
int V_5 ;
int V_35 ;
T_5 V_42 = { {
. V_37 = V_37 ,
. V_41 = V_41 ,
}
} ;
T_6 V_43 = { { 0 } } ;
for ( V_5 = 0 ; V_5 < V_38 ; V_5 ++ )
F_16 ( & V_43 , V_36 + V_5 ) ;
V_35 = F_17 ( V_1 , V_37 , V_43 ) ;
if ( V_35 != 0 )
return V_35 ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ ) {
V_42 . V_44 = V_36 + ( V_5 % V_38 ) ;
V_35 = F_18 ( V_1 , V_39 + V_5 ,
V_42 ) ;
if ( V_35 != 0 )
return V_35 ;
}
return 0 ;
}
int F_19 ( T_1 * V_1 ,
unsigned int V_36 , unsigned int V_45 ,
void * V_32 , T_3 V_33 ,
unsigned int V_34 )
{
memset ( V_32 , 0 , V_33 ) ;
return F_20 ( V_1 , V_32 , V_33 , V_34 ,
V_36 , V_45 ) ;
}
void F_21 ( T_7 * V_46 ,
T_1 * V_1 )
{
V_46 -> V_1 = V_1 ;
memset ( & V_46 -> V_47 , 0 , sizeof( V_46 -> V_47 ) ) ;
}
int F_22 ( T_7 * V_46 ,
unsigned int V_39 , unsigned int V_40 ,
T_8 * V_22 )
{
int V_5 ;
int V_31 = 255 ;
T_9 * V_47 = & V_46 -> V_47 ;
T_10 * V_48 =
( T_10 * ) ( V_47 -> V_46 + V_47 -> V_49 ) ;
unsigned int V_49 = V_47 -> V_50 ;
unsigned int V_51 = 0 ;
while ( ( ( V_49 + V_51 ) % F_23 ( T_10 ) ) != 0 )
V_51 ++ ;
if ( V_49 + V_51 + sizeof( * V_48 ) >= sizeof( V_47 -> V_46 ) )
return V_52 ;
if ( F_24 ( V_40 ) != 1 )
return V_53 ;
V_48 -> V_25 += V_51 ;
V_47 -> V_49 = V_49 + V_51 ;
V_48 = ( T_10 * ) ( V_47 -> V_46 + V_47 -> V_49 ) ;
V_48 -> V_54 = 2 ;
V_48 -> V_55 = 0 ;
V_48 -> V_56 = 16384 ;
V_48 -> V_57 = V_40 - 1 ;
V_48 -> V_58 = V_39 ;
for ( V_5 = 8 - 1 ; V_5 >= 0 ; V_5 -- ) {
int V_59 =
V_22 ? V_22 -> V_22 [ V_5 ] : V_46 -> V_1 -> V_21 .
V_22 [ V_5 ] ;
if ( V_59 != 255 )
V_31 = V_59 ;
V_48 -> V_22 . V_22 [ V_5 ] = V_31 ;
}
if ( V_31 == 255 )
return V_53 ;
for ( V_5 = 8 - 1 ; V_5 > 0 ; V_5 -- ) {
if ( V_48 -> V_22 . V_22 [ V_5 ] == 255 ) {
V_48 -> V_22 . V_22 [ V_5 ] = V_31 ;
V_48 -> V_56 =
F_8 ( V_5 -
1 ) ;
}
}
V_48 -> V_25 = sizeof( * V_48 ) ;
V_47 -> V_50 = V_47 -> V_49 + V_48 -> V_25 ;
return 0 ;
}
int F_25 ( T_7 * V_46 ,
unsigned int V_45 )
{
T_9 * V_47 = & V_46 -> V_47 ;
T_10 * V_48 =
( T_10 * ) ( V_47 -> V_46 + V_47 -> V_49 ) ;
if ( V_45 >= 32 )
return V_53 ;
if ( V_47 -> V_50 == 0 )
return V_60 ;
V_48 -> V_61 |= ( 1UL << V_45 ) ;
return 0 ;
}
int F_26 ( T_7 * V_46 , T_11 V_54 )
{
T_9 * V_47 = & V_46 -> V_47 ;
T_10 * V_48 =
( T_10 * ) ( V_47 -> V_46 + V_47 -> V_49 ) ;
if ( V_47 -> V_50 == 0 )
return V_60 ;
V_48 -> V_54 = V_54 ;
return 0 ;
}
int F_27 ( T_7 * V_46 )
{
T_9 * V_47 = & V_46 -> V_47 ;
unsigned int V_25 =
F_28 ( T_9 , V_46 ) + V_47 -> V_50 ;
return F_29 ( V_46 -> V_1 , V_47 , V_25 ) ;
}
int F_30 ( T_12 * V_62 ,
T_1 * V_1 ,
unsigned int V_36 ,
void * V_32 , T_3 V_33 , unsigned int V_34 )
{
unsigned int V_63 = V_33 / sizeof( V_64 ) ;
V_62 -> V_1 = V_1 ;
V_62 -> V_65 = ( V_64 * ) V_32 ;
V_62 -> V_36 = V_36 ;
V_62 -> V_63 = V_63 ;
V_62 -> V_66 = V_63 - 1 ;
V_62 -> V_67 = F_31 ( V_63 ) ;
V_62 -> V_49 = 1 ;
#ifdef F_32
V_62 -> V_68 = 0 ;
#endif
F_33 ( V_32 , V_62 -> V_49 ) ;
return F_13 ( V_1 , V_36 , V_32 , V_33 ,
V_34 ) ;
}
int F_34 ( T_13 * V_69 ,
T_1 * V_1 ,
unsigned int V_70 ,
unsigned int V_45 ,
void * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
unsigned int V_63 = V_33 / sizeof( V_71 ) ;
T_14 V_72 ;
int V_35 = F_19 ( V_1 , V_70 , V_45 ,
V_32 , V_33 , V_34 ) ;
if ( V_35 < 0 )
return V_35 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_72 . V_73 = 0 ;
V_72 . V_74 =
V_75 -
V_76 ;
V_72 . V_36 = V_70 ;
F_35 ( & V_69 -> V_77 ,
V_1 -> V_17 + V_72 . V_73 ,
V_63 ) ;
V_69 -> V_78 = V_32 ;
V_69 -> V_66 = V_63 - 1 ;
V_69 -> V_67 = F_31 ( V_63 ) ;
V_69 -> V_1 = V_1 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_45 = V_45 ;
return 0 ;
}
int F_36 ( T_1 * V_1 ,
const struct V_79 * V_80 )
{
T_15 V_81 = F_37 () ;
return F_38 ( V_1 , ( V_82 ) V_80 -> V_83 ,
( V_82 ) V_80 -> V_84 ,
( V_82 ) V_81 ) ;
}
int F_39 ( T_1 * V_1 ,
struct V_79 * V_80 )
{
int V_85 ;
T_15 V_86 , V_87 , V_88 ;
V_86 = F_37 () ;
V_85 = F_40 ( V_1 , ( V_82 * ) & V_80 -> V_83 ,
( V_82 * ) & V_80 -> V_84 ,
( V_82 * ) & V_87 ) ;
if ( V_85 < 0 ) {
return V_85 ;
}
V_88 = F_41 () ;
V_80 -> V_84 -= ( V_87 - V_86 ) * 1000000000LL / V_88 ;
if ( V_80 -> V_84 < 0 ) {
V_80 -> V_84 += 1000000000LL ;
V_80 -> V_83 -= 1 ;
}
return V_85 ;
}
int F_42 ( T_1 * V_1 , T_16 V_89 )
{
return F_43 ( V_1 , V_89 ) ;
}
static T_1 * F_44 ( void )
{
static T_1 V_1 ;
static T_1 * V_90 ;
static int V_91 = 0 ;
static F_45 ( V_92 ) ;
F_46 ( & V_92 ) ;
if ( ! V_91 ) {
int V_5 = 0 ;
V_91 = 1 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
char V_3 [ 80 ] ;
snprintf ( V_3 , sizeof( V_3 ) , L_2 , V_5 ) ;
V_1 . V_4 = F_2 ( ( V_8 ) V_3 , 0 ) ;
if ( V_1 . V_4 < 0 )
continue;
V_90 = & V_1 ;
break;
}
}
F_47 ( & V_92 ) ;
return V_90 ;
}
int F_48 ( const char * V_93 )
{
T_17 V_94 ;
T_1 * V_1 = F_44 () ;
if ( ! V_1 )
return V_95 ;
if ( F_49 ( V_94 . V_94 , V_93 , sizeof( V_94 . V_94 ) ) < 0 )
return V_95 ;
return F_50 ( V_1 , V_94 ) ;
}
int F_51 ( int V_96 , char * V_93 , T_11 * V_97 )
{
int V_98 ;
T_17 V_94 ;
T_18 V_99 ;
T_1 * V_1 = F_44 () ;
if ( ! V_1 )
return V_95 ;
V_98 = F_52 ( V_1 , V_96 , & V_94 , & V_99 ) ;
if ( V_98 >= 0 ) {
if ( F_49 ( V_93 , V_94 . V_94 , sizeof( V_94 . V_94 ) ) < 0 )
return V_100 ;
memcpy ( V_97 , V_99 . V_99 , sizeof( V_99 . V_99 ) ) ;
}
return V_98 ;
}
int F_53 ( T_19 * V_101 ,
T_1 * V_1 , const char * V_93 ,
unsigned int V_102 )
{
T_17 V_94 ;
int V_98 ;
if ( F_49 ( V_94 . V_94 , V_93 , sizeof( V_94 . V_94 ) ) < 0 )
return V_95 ;
V_98 = F_54 ( V_1 , V_94 , V_102 ) ;
if ( V_98 < 0 )
return V_98 ;
V_101 -> V_1 = V_1 ;
V_101 -> V_45 = V_98 >> 8 ;
V_101 -> V_99 = V_98 & 0xFF ;
return 0 ;
}
int F_55 ( T_19 * V_101 )
{
return F_56 ( V_101 -> V_1 , V_101 -> V_99 ) ;
}
int F_57 ( T_19 * V_101 , T_20 V_103 ,
T_16 V_104 )
{
return F_58 ( V_101 -> V_1 , V_101 -> V_99 , V_103 ,
V_104 ) ;
}
