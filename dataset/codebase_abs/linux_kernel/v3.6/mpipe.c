int F_1 ( T_1 * V_1 , unsigned int V_2 )
{
char V_3 [ 32 ] ;
int V_4 ;
int V_5 ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 ) ;
V_4 = F_2 ( ( V_6 ) V_3 , 0 ) ;
if ( V_4 < 0 ) {
if ( V_4 >= V_7 && V_4 <= V_8 )
return V_4 ;
else
return - V_9 ;
}
V_1 -> V_4 = V_4 ;
V_1 -> V_10 = ( void V_11 * )
F_3 ( V_4 , V_12 ,
V_13 ) ;
if ( V_1 -> V_10 == NULL )
goto V_14;
V_1 -> V_15 = ( void V_11 * )
F_3 ( V_4 , V_16 ,
V_17 ) ;
if ( V_1 -> V_15 == NULL )
goto V_18;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
V_1 -> V_19 . V_20 [ V_5 ] = 255 ;
return 0 ;
V_18:
F_4 ( ( void V_11 V_21 * ) ( V_1 -> V_10 ) ) ;
V_14:
F_5 ( V_1 -> V_4 ) ;
return - V_9 ;
}
int F_6 ( T_1 * V_1 )
{
F_4 ( ( void V_11 V_21 * ) ( V_1 -> V_10 ) ) ;
F_4 ( ( void V_11 V_21 * ) ( V_1 -> V_15 ) ) ;
return F_5 ( V_1 -> V_4 ) ;
}
T_2 F_7 ( T_3
V_22 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 7 ; V_5 ++ )
if ( V_22 <= V_23 [ V_5 ] )
break;
return V_5 ;
}
T_3 F_8 ( T_2
V_24 )
{
if ( V_24 > 7 )
V_24 = 7 ;
return V_23 [ V_24 ] ;
}
T_3 F_9 ( unsigned long V_25 )
{
const int V_26 = 12 ;
unsigned long V_27 =
( V_25 + V_26 - 1 ) / V_26 ;
return V_27 * F_10 () ;
}
int F_11 ( T_1 * V_1 ,
unsigned int V_28 ,
T_2
V_24 , void * V_29 , T_3 V_30 ,
unsigned int V_31 )
{
int V_32 ;
memset ( V_29 , 0 , V_30 ) ;
V_32 = F_12 ( V_1 , V_29 , V_30 ,
V_31 , V_28 ,
V_24 ) ;
if ( V_32 < 0 )
return V_32 ;
V_1 -> V_19 . V_20 [ V_24 ] = V_28 ;
return 0 ;
}
int F_13 ( T_1 * V_1 ,
unsigned int V_33 ,
void * V_29 , T_3 V_30 ,
unsigned int V_31 )
{
return F_14 ( V_1 , V_29 , V_30 ,
V_31 , V_33 ) ;
}
int F_15 ( T_1 * V_1 ,
unsigned int V_34 ,
unsigned int V_33 ,
unsigned int V_35 ,
unsigned int V_36 ,
unsigned int V_37 ,
T_4 V_38 )
{
int V_5 ;
int V_32 ;
T_5 V_39 = { {
. V_34 = V_34 ,
. V_38 = V_38 ,
}
} ;
T_6 V_40 = { { 0 } } ;
for ( V_5 = 0 ; V_5 < V_35 ; V_5 ++ )
F_16 ( & V_40 , V_33 + V_5 ) ;
V_32 = F_17 ( V_1 , V_34 , V_40 ) ;
if ( V_32 != 0 )
return V_32 ;
for ( V_5 = 0 ; V_5 < V_37 ; V_5 ++ ) {
V_39 . V_41 = V_33 + ( V_5 % V_35 ) ;
V_32 = F_18 ( V_1 , V_36 + V_5 ,
V_39 ) ;
if ( V_32 != 0 )
return V_32 ;
}
return 0 ;
}
int F_19 ( T_1 * V_1 ,
unsigned int V_33 , unsigned int V_42 ,
void * V_29 , T_3 V_30 ,
unsigned int V_31 )
{
memset ( V_29 , 0 , V_30 ) ;
return F_20 ( V_1 , V_29 , V_30 , V_31 ,
V_33 , V_42 ) ;
}
void F_21 ( T_7 * V_43 ,
T_1 * V_1 )
{
V_43 -> V_1 = V_1 ;
memset ( & V_43 -> V_44 , 0 , sizeof( V_43 -> V_44 ) ) ;
}
int F_22 ( T_7 * V_43 ,
unsigned int V_36 , unsigned int V_37 ,
T_8 * V_20 )
{
int V_5 ;
int V_28 = 255 ;
T_9 * V_44 = & V_43 -> V_44 ;
T_10 * V_45 =
( T_10 * ) ( V_44 -> V_43 + V_44 -> V_46 ) ;
unsigned int V_46 = V_44 -> V_47 ;
unsigned int V_48 = 0 ;
while ( ( ( V_46 + V_48 ) % F_23 ( T_10 ) ) != 0 )
V_48 ++ ;
if ( V_46 + V_48 + sizeof( * V_45 ) >= sizeof( V_44 -> V_43 ) )
return V_49 ;
if ( F_24 ( V_37 ) != 1 )
return V_50 ;
V_45 -> V_22 += V_48 ;
V_44 -> V_46 = V_46 + V_48 ;
V_45 = ( T_10 * ) ( V_44 -> V_43 + V_44 -> V_46 ) ;
V_45 -> V_51 = 2 ;
V_45 -> V_52 = 0 ;
V_45 -> V_53 = 16384 ;
V_45 -> V_54 = V_37 - 1 ;
V_45 -> V_55 = V_36 ;
for ( V_5 = 8 - 1 ; V_5 >= 0 ; V_5 -- ) {
int V_56 =
V_20 ? V_20 -> V_20 [ V_5 ] : V_43 -> V_1 -> V_19 .
V_20 [ V_5 ] ;
if ( V_56 != 255 )
V_28 = V_56 ;
V_45 -> V_20 . V_20 [ V_5 ] = V_28 ;
}
if ( V_28 == 255 )
return V_50 ;
for ( V_5 = 8 - 1 ; V_5 > 0 ; V_5 -- ) {
if ( V_45 -> V_20 . V_20 [ V_5 ] == 255 ) {
V_45 -> V_20 . V_20 [ V_5 ] = V_28 ;
V_45 -> V_53 =
F_8 ( V_5 -
1 ) ;
}
}
V_45 -> V_22 = sizeof( * V_45 ) ;
V_44 -> V_47 = V_44 -> V_46 + V_45 -> V_22 ;
return 0 ;
}
int F_25 ( T_7 * V_43 ,
unsigned int V_42 )
{
T_9 * V_44 = & V_43 -> V_44 ;
T_10 * V_45 =
( T_10 * ) ( V_44 -> V_43 + V_44 -> V_46 ) ;
if ( V_42 >= 32 )
return V_50 ;
if ( V_44 -> V_47 == 0 )
return V_57 ;
V_45 -> V_58 |= ( 1UL << V_42 ) ;
return 0 ;
}
int F_26 ( T_7 * V_43 , T_11 V_51 )
{
T_9 * V_44 = & V_43 -> V_44 ;
T_10 * V_45 =
( T_10 * ) ( V_44 -> V_43 + V_44 -> V_46 ) ;
if ( V_44 -> V_47 == 0 )
return V_57 ;
V_45 -> V_51 = V_51 ;
return 0 ;
}
int F_27 ( T_7 * V_43 )
{
T_9 * V_44 = & V_43 -> V_44 ;
unsigned int V_22 =
F_28 ( T_9 , V_43 ) + V_44 -> V_47 ;
return F_29 ( V_43 -> V_1 , V_44 , V_22 ) ;
}
int F_30 ( T_12 * V_59 ,
T_1 * V_1 ,
unsigned int V_33 ,
void * V_29 , T_3 V_30 , unsigned int V_31 )
{
unsigned int V_60 = V_30 / sizeof( V_61 ) ;
V_59 -> V_1 = V_1 ;
V_59 -> V_62 = ( V_61 * ) V_29 ;
V_59 -> V_33 = V_33 ;
V_59 -> V_60 = V_60 ;
V_59 -> V_63 = V_60 - 1 ;
V_59 -> V_64 = F_31 ( V_60 ) ;
V_59 -> V_46 = 1 ;
#ifdef F_32
V_59 -> V_65 = 0 ;
#endif
F_33 ( V_29 , V_59 -> V_46 ) ;
return F_13 ( V_1 , V_33 , V_29 , V_30 ,
V_31 ) ;
}
int F_34 ( T_13 * V_66 ,
T_1 * V_1 ,
unsigned int V_67 ,
unsigned int V_42 ,
void * V_29 , unsigned int V_30 ,
unsigned int V_31 )
{
unsigned int V_60 = V_30 / sizeof( V_68 ) ;
T_14 V_69 ;
int V_32 = F_19 ( V_1 , V_67 , V_42 ,
V_29 , V_30 , V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_69 . V_70 = 0 ;
V_69 . V_71 =
V_72 -
V_73 ;
V_69 . V_33 = V_67 ;
F_35 ( & V_66 -> V_74 ,
V_1 -> V_15 + V_69 . V_70 ,
V_60 ) ;
V_66 -> V_75 = V_29 ;
V_66 -> V_63 = V_60 - 1 ;
V_66 -> V_64 = F_31 ( V_60 ) ;
return 0 ;
}
int F_36 ( T_1 * V_1 ,
const struct V_76 * V_77 )
{
T_15 V_78 = F_37 () ;
return F_38 ( V_1 , ( V_79 ) V_77 -> V_80 ,
( V_79 ) V_77 -> V_81 ,
( V_79 ) V_78 ) ;
}
int F_39 ( T_1 * V_1 ,
struct V_76 * V_77 )
{
int V_82 ;
T_15 V_83 , V_84 , V_85 ;
V_83 = F_37 () ;
V_82 = F_40 ( V_1 , ( V_79 * ) & V_77 -> V_80 ,
( V_79 * ) & V_77 -> V_81 ,
( V_79 * ) & V_84 ) ;
if ( V_82 < 0 ) {
return V_82 ;
}
V_85 = F_41 () ;
V_77 -> V_81 -= ( V_84 - V_83 ) * 1000000000LL / V_85 ;
if ( V_77 -> V_81 < 0 ) {
V_77 -> V_81 += 1000000000LL ;
V_77 -> V_80 -= 1 ;
}
return V_82 ;
}
int F_42 ( T_1 * V_1 , T_16 V_86 )
{
return F_43 ( V_1 , V_86 ) ;
}
static T_1 * F_44 ( void )
{
static T_1 V_1 ;
static T_1 * V_87 ;
static int V_88 = 0 ;
static F_45 ( V_89 ) ;
F_46 ( & V_89 ) ;
if ( ! V_88 ) {
int V_5 = 0 ;
V_88 = 1 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
char V_3 [ 80 ] ;
snprintf ( V_3 , sizeof( V_3 ) , L_2 , V_5 ) ;
V_1 . V_4 = F_2 ( ( V_6 ) V_3 , 0 ) ;
if ( V_1 . V_4 < 0 )
continue;
V_87 = & V_1 ;
break;
}
}
F_47 ( & V_89 ) ;
return V_87 ;
}
int F_48 ( int V_90 , char * V_91 , T_11 * V_92 )
{
int V_93 ;
T_17 V_94 ;
T_18 V_95 ;
T_1 * V_1 = F_44 () ;
if ( ! V_1 )
return V_96 ;
V_93 = F_49 ( V_1 , V_90 , & V_94 , & V_95 ) ;
if ( V_93 >= 0 ) {
strncpy ( V_91 , V_94 . V_94 , sizeof( V_94 . V_94 ) ) ;
memcpy ( V_92 , V_95 . V_95 , sizeof( V_95 . V_95 ) ) ;
}
return V_93 ;
}
int F_50 ( T_19 * V_97 ,
T_1 * V_1 , const char * V_91 ,
unsigned int V_98 )
{
T_17 V_94 ;
int V_93 ;
strncpy ( V_94 . V_94 , V_91 , sizeof( V_94 . V_94 ) ) ;
V_94 . V_94 [ V_99 - 1 ] = '\0' ;
V_93 = F_51 ( V_1 , V_94 , V_98 ) ;
if ( V_93 < 0 )
return V_93 ;
V_97 -> V_1 = V_1 ;
V_97 -> V_42 = V_93 >> 8 ;
V_97 -> V_95 = V_93 & 0xFF ;
return 0 ;
}
int F_52 ( T_19 * V_97 )
{
return F_53 ( V_97 -> V_1 , V_97 -> V_95 ) ;
}
