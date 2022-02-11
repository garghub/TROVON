static T_1 F_1 ( char * V_1 , const char * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 , V_3 ) + 1 ;
if ( V_4 > V_3 ) {
if ( V_3 )
V_1 [ 0 ] = '\0' ;
return 0 ;
}
memcpy ( V_1 , V_2 , V_4 ) ;
return V_4 ;
}
int F_3 ( T_2 * V_5 , unsigned int V_6 )
{
char V_7 [ 32 ] ;
int V_8 ;
int V_9 ;
if ( V_6 >= V_10 )
return - V_11 ;
snprintf ( V_7 , sizeof( V_7 ) , L_1 , V_6 ) ;
V_8 = F_4 ( ( V_12 ) V_7 , 0 ) ;
V_5 -> V_8 = V_8 ;
if ( V_8 < 0 ) {
if ( V_8 >= V_13 && V_8 <= V_14 )
return V_8 ;
else
return - V_15 ;
}
V_5 -> V_16 = ( void V_17 * )
F_5 ( V_8 , V_18 ,
V_19 ) ;
if ( V_5 -> V_16 == NULL )
goto V_20;
V_5 -> V_21 = ( void V_17 * )
F_5 ( V_8 , V_22 ,
V_23 ) ;
if ( V_5 -> V_21 == NULL )
goto V_24;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
V_5 -> V_25 . V_26 [ V_9 ] = 255 ;
V_5 -> V_27 = V_6 ;
return 0 ;
V_24:
F_6 ( ( void V_17 V_28 * ) ( V_5 -> V_16 ) ) ;
V_20:
F_7 ( V_5 -> V_8 ) ;
V_5 -> V_8 = - 1 ;
return - V_15 ;
}
int F_8 ( T_2 * V_5 )
{
F_6 ( ( void V_17 V_28 * ) ( V_5 -> V_16 ) ) ;
F_6 ( ( void V_17 V_28 * ) ( V_5 -> V_21 ) ) ;
return F_7 ( V_5 -> V_8 ) ;
}
T_3 F_9 ( T_1
V_3 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < 7 ; V_9 ++ )
if ( V_3 <= V_29 [ V_9 ] )
break;
return V_9 ;
}
T_1 F_10 ( T_3
V_30 )
{
if ( V_30 > 7 )
V_30 = 7 ;
return V_29 [ V_30 ] ;
}
T_1 F_11 ( unsigned long V_31 )
{
const int V_32 = 12 ;
unsigned long V_33 =
( V_31 + V_32 - 1 ) / V_32 ;
return V_33 * F_12 () ;
}
int F_13 ( T_2 * V_5 ,
unsigned int V_34 ,
T_3
V_30 , void * V_35 , T_1 V_36 ,
unsigned int V_37 )
{
int V_38 ;
memset ( V_35 , 0 , V_36 ) ;
V_38 = F_14 ( V_5 , V_35 , V_36 ,
V_37 , V_34 ,
V_30 ) ;
if ( V_38 < 0 )
return V_38 ;
V_5 -> V_25 . V_26 [ V_30 ] = V_34 ;
return 0 ;
}
int F_15 ( T_2 * V_5 ,
unsigned int V_39 ,
void * V_35 , T_1 V_36 ,
unsigned int V_37 )
{
return F_16 ( V_5 , V_35 , V_36 ,
V_37 , V_39 ) ;
}
int F_17 ( T_2 * V_5 ,
unsigned int V_40 ,
unsigned int V_39 ,
unsigned int V_41 ,
unsigned int V_42 ,
unsigned int V_43 ,
T_4 V_44 )
{
int V_9 ;
int V_38 ;
T_5 V_45 = { {
. V_40 = V_40 ,
. V_44 = V_44 ,
}
} ;
T_6 V_46 = { { 0 } } ;
for ( V_9 = 0 ; V_9 < V_41 ; V_9 ++ )
F_18 ( & V_46 , V_39 + V_9 ) ;
V_38 = F_19 ( V_5 , V_40 , V_46 ) ;
if ( V_38 != 0 )
return V_38 ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
V_45 . V_47 = V_39 + ( V_9 % V_41 ) ;
V_38 = F_20 ( V_5 , V_42 + V_9 ,
V_45 ) ;
if ( V_38 != 0 )
return V_38 ;
}
return 0 ;
}
int F_21 ( T_2 * V_5 ,
unsigned int V_39 , unsigned int V_48 ,
void * V_35 , T_1 V_36 ,
unsigned int V_37 )
{
memset ( V_35 , 0 , V_36 ) ;
return F_22 ( V_5 , V_35 , V_36 , V_37 ,
V_39 , V_48 ) ;
}
void F_23 ( T_7 * V_49 ,
T_2 * V_5 )
{
V_49 -> V_5 = V_5 ;
memset ( & V_49 -> V_50 , 0 , sizeof( V_49 -> V_50 ) ) ;
}
int F_24 ( T_7 * V_49 ,
unsigned int V_42 , unsigned int V_43 ,
T_8 * V_26 )
{
int V_9 ;
int V_34 = 255 ;
T_9 * V_50 = & V_49 -> V_50 ;
T_10 * V_51 =
( T_10 * ) ( V_50 -> V_49 + V_50 -> V_52 ) ;
unsigned int V_52 = V_50 -> V_53 ;
unsigned int V_54 = 0 ;
while ( ( ( V_52 + V_54 ) % F_25 ( T_10 ) ) != 0 )
V_54 ++ ;
if ( V_52 + V_54 + sizeof( * V_51 ) >= sizeof( V_50 -> V_49 ) )
return V_55 ;
if ( F_26 ( V_43 ) != 1 )
return V_56 ;
V_51 -> V_3 += V_54 ;
V_50 -> V_52 = V_52 + V_54 ;
V_51 = ( T_10 * ) ( V_50 -> V_49 + V_50 -> V_52 ) ;
V_51 -> V_57 = 2 ;
V_51 -> V_58 = 0 ;
V_51 -> V_59 = 16384 ;
V_51 -> V_60 = V_43 - 1 ;
V_51 -> V_61 = V_42 ;
for ( V_9 = 8 - 1 ; V_9 >= 0 ; V_9 -- ) {
int V_62 =
V_26 ? V_26 -> V_26 [ V_9 ] : V_49 -> V_5 -> V_25 .
V_26 [ V_9 ] ;
if ( V_62 != 255 )
V_34 = V_62 ;
V_51 -> V_26 . V_26 [ V_9 ] = V_34 ;
}
if ( V_34 == 255 )
return V_56 ;
for ( V_9 = 8 - 1 ; V_9 > 0 ; V_9 -- ) {
if ( V_51 -> V_26 . V_26 [ V_9 ] == 255 ) {
V_51 -> V_26 . V_26 [ V_9 ] = V_34 ;
V_51 -> V_59 =
F_10 ( V_9 -
1 ) ;
}
}
V_51 -> V_3 = sizeof( * V_51 ) ;
V_50 -> V_53 = V_50 -> V_52 + V_51 -> V_3 ;
return 0 ;
}
int F_27 ( T_7 * V_49 ,
unsigned int V_48 )
{
T_9 * V_50 = & V_49 -> V_50 ;
T_10 * V_51 =
( T_10 * ) ( V_50 -> V_49 + V_50 -> V_52 ) ;
if ( V_48 >= 32 )
return V_56 ;
if ( V_50 -> V_53 == 0 )
return V_63 ;
V_51 -> V_64 |= ( 1UL << V_48 ) ;
return 0 ;
}
int F_28 ( T_7 * V_49 , T_11 V_57 )
{
T_9 * V_50 = & V_49 -> V_50 ;
T_10 * V_51 =
( T_10 * ) ( V_50 -> V_49 + V_50 -> V_52 ) ;
if ( V_50 -> V_53 == 0 )
return V_63 ;
V_51 -> V_57 = V_57 ;
return 0 ;
}
int F_29 ( T_7 * V_49 )
{
T_9 * V_50 = & V_49 -> V_50 ;
unsigned int V_3 =
F_30 ( T_9 , V_49 ) + V_50 -> V_53 ;
return F_31 ( V_49 -> V_5 , V_50 , V_3 ) ;
}
int F_32 ( T_12 * V_65 ,
T_2 * V_5 ,
unsigned int V_39 ,
void * V_35 , T_1 V_36 , unsigned int V_37 )
{
unsigned int V_66 = V_36 / sizeof( V_67 ) ;
V_65 -> V_5 = V_5 ;
V_65 -> V_68 = ( V_67 * ) V_35 ;
V_65 -> V_39 = V_39 ;
V_65 -> V_66 = V_66 ;
V_65 -> V_69 = V_66 - 1 ;
V_65 -> V_70 = F_33 ( V_66 ) ;
V_65 -> V_52 = 1 ;
#ifdef F_34
V_65 -> V_71 = 0 ;
#endif
F_35 ( V_35 , V_65 -> V_52 ) ;
return F_15 ( V_5 , V_39 , V_35 , V_36 ,
V_37 ) ;
}
int F_36 ( T_13 * V_72 ,
T_2 * V_5 ,
unsigned int V_73 ,
unsigned int V_48 ,
void * V_35 , unsigned int V_36 ,
unsigned int V_37 )
{
unsigned int V_66 = V_36 / sizeof( V_74 ) ;
T_14 V_75 ;
int V_38 = F_21 ( V_5 , V_73 , V_48 ,
V_35 , V_36 , V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_75 . V_76 = 0 ;
V_75 . V_77 =
V_78 -
V_79 ;
V_75 . V_39 = V_73 ;
F_37 ( & V_72 -> V_80 ,
V_5 -> V_21 + V_75 . V_76 ,
V_66 ) ;
V_72 -> V_81 = V_35 ;
V_72 -> V_69 = V_66 - 1 ;
V_72 -> V_70 = F_33 ( V_66 ) ;
V_72 -> V_5 = V_5 ;
V_72 -> V_73 = V_73 ;
V_72 -> V_48 = V_48 ;
return 0 ;
}
int F_38 ( T_2 * V_5 ,
const struct V_82 * V_83 )
{
T_15 V_84 = F_39 () ;
return F_40 ( V_5 , ( V_85 ) V_83 -> V_86 ,
( V_85 ) V_83 -> V_87 ,
( V_85 ) V_84 ) ;
}
int F_41 ( T_2 * V_5 ,
struct V_82 * V_83 )
{
int V_88 ;
T_15 V_89 , V_90 , V_91 ;
V_89 = F_39 () ;
V_88 = F_42 ( V_5 , ( V_85 * ) & V_83 -> V_86 ,
( V_85 * ) & V_83 -> V_87 ,
( V_85 * ) & V_90 ) ;
if ( V_88 < 0 ) {
return V_88 ;
}
V_91 = F_43 () ;
V_83 -> V_87 -= ( V_90 - V_89 ) * 1000000000LL / V_91 ;
if ( V_83 -> V_87 < 0 ) {
V_83 -> V_87 += 1000000000LL ;
V_83 -> V_86 -= 1 ;
}
return V_88 ;
}
int F_44 ( T_2 * V_5 , T_16 V_92 )
{
return F_45 ( V_5 , V_92 ) ;
}
static T_2 * F_46 ( void )
{
static T_2 V_5 ;
static T_2 * V_93 ;
static int V_94 = 0 ;
static F_47 ( V_95 ) ;
F_48 ( & V_95 ) ;
if ( ! V_94 ) {
int V_9 = 0 ;
V_94 = 1 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
char V_7 [ 80 ] ;
snprintf ( V_7 , sizeof( V_7 ) , L_2 , V_9 ) ;
V_5 . V_8 = F_4 ( ( V_12 ) V_7 , 0 ) ;
if ( V_5 . V_8 < 0 )
continue;
V_93 = & V_5 ;
break;
}
}
F_49 ( & V_95 ) ;
return V_93 ;
}
int F_50 ( const char * V_96 )
{
T_17 V_97 ;
T_2 * V_5 = F_46 () ;
if ( ! V_5 )
return V_98 ;
if ( F_1 ( V_97 . V_97 , V_96 , sizeof( V_97 . V_97 ) ) == 0 )
return V_98 ;
return F_51 ( V_5 , V_97 ) ;
}
int F_52 ( int V_99 , char * V_96 , T_11 * V_100 )
{
int V_101 ;
T_17 V_97 ;
T_18 V_102 ;
T_2 * V_5 = F_46 () ;
if ( ! V_5 )
return V_98 ;
V_101 = F_53 ( V_5 , V_99 , & V_97 , & V_102 ) ;
if ( V_101 >= 0 ) {
if ( F_1 ( V_96 , V_97 . V_97 , sizeof( V_97 . V_97 ) ) == 0 )
return V_103 ;
memcpy ( V_100 , V_102 . V_102 , sizeof( V_102 . V_102 ) ) ;
}
return V_101 ;
}
int F_54 ( T_19 * V_104 ,
T_2 * V_5 , const char * V_96 ,
unsigned int V_105 )
{
T_17 V_97 ;
int V_101 ;
if ( F_1 ( V_97 . V_97 , V_96 , sizeof( V_97 . V_97 ) ) == 0 )
return V_98 ;
V_101 = F_55 ( V_5 , V_97 , V_105 ) ;
if ( V_101 < 0 )
return V_101 ;
V_104 -> V_5 = V_5 ;
V_104 -> V_48 = V_101 >> 8 ;
V_104 -> V_102 = V_101 & 0xFF ;
return 0 ;
}
int F_56 ( T_19 * V_104 )
{
return F_57 ( V_104 -> V_5 , V_104 -> V_102 ) ;
}
int F_58 ( T_19 * V_104 , T_20 V_106 ,
T_16 V_107 )
{
return F_59 ( V_104 -> V_5 , V_104 -> V_102 , V_106 ,
V_107 ) ;
}
