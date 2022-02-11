static int F_1 ( struct V_1 * V_2 ,
enum V_3 line ,
enum V_4 V_5 )
{
T_1 V_6 , V_7 , * V_8 ;
unsigned long V_9 = 0 ;
V_8 = & V_2 -> V_10 ;
if ( line == V_11 ) {
V_7 = V_2 -> V_12 ;
V_6 = ( 1UL << V_2 -> V_13 ) ;
} else {
V_7 = V_2 -> V_14 ;
V_6 = ( 1UL << V_2 -> V_15 ) ;
}
F_2 ( & V_2 -> V_16 , V_9 ) ;
if ( V_5 == V_17 ) {
V_2 -> V_18 &= ~ V_7 ;
} else {
V_2 -> V_18 |= V_7 ;
}
F_3 ( V_2 , V_2 -> V_19 -> V_20 , V_2 -> V_18 ) ;
if ( V_5 == V_17 )
* V_8 |= V_6 ;
else
* V_8 &= ~ V_6 ;
F_3 ( V_2 , V_2 -> V_19 -> V_21 , * V_8 ) ;
F_4 ( & V_2 -> V_16 , V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 line ,
enum V_4 * V_22 )
{
T_1 V_23 , V_24 ;
int V_25 ;
unsigned long V_9 = 0 ;
if ( V_22 == NULL ) {
V_25 = 1 ;
goto V_26;
}
if ( line == V_11 )
V_24 = V_2 -> V_12 ;
else
V_24 = V_2 -> V_14 ;
F_2 ( & V_2 -> V_16 , V_9 ) ;
V_2 -> V_18 &= ~ V_24 ;
F_3 ( V_2 , V_2 -> V_19 -> V_20 , V_2 -> V_18 ) ;
V_23 = F_6 ( V_2 , V_2 -> V_19 -> V_27 ) ;
F_4 ( & V_2 -> V_16 , V_9 ) ;
if ( V_23 & V_24 )
* V_22 = V_17 ;
else
* V_22 = V_28 ;
V_25 = 0 ;
V_26:
return V_25 ;
}
static void F_7 ( struct V_1 * V_2 )
{
( void ) F_8 ( V_2 , V_2 -> V_19 -> V_29 ) ;
F_9 () ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_30 )
{
F_11 ( 1 ) ;
F_1 ( V_2 , V_11 , V_30 ? V_17 : V_28 ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_2 V_30 )
{
F_1 ( V_2 , V_31 , V_30 ? V_17 : V_28 ) ;
F_7 ( V_2 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 , int V_32 )
{
enum V_4 V_30 ;
if ( F_5 ( V_2 , V_31 , & V_30 ) )
F_14 ( L_1 ) ;
if ( V_32 )
F_7 ( V_2 ) ;
return V_30 == V_17 ? 1U : 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_33 ;
V_33 = F_13 ( V_2 , 1 ) ;
F_10 ( V_2 , V_17 ) ;
V_33 = F_13 ( V_2 , 1 ) == 0 ;
F_10 ( V_2 , V_28 ) ;
return V_33 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_34 , V_35 ;
V_35 = 0 ;
for ( V_34 = 7 ; V_34 >= 0 ; -- V_34 ) {
V_35 <<= 1 ;
F_10 ( V_2 , V_17 ) ;
V_35 |= F_13 ( V_2 , 0 ) ;
F_10 ( V_2 , V_28 ) ;
}
return V_35 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_35 )
{
int V_34 ;
T_2 V_30 ;
for ( V_34 = 7 ; V_34 >= 0 ; V_34 -- ) {
V_30 = ( V_35 >> V_34 ) & 1 ;
F_12 ( V_2 , V_30 ) ;
F_10 ( V_2 , V_17 ) ;
F_10 ( V_2 , V_28 ) ;
}
return ( ! F_15 ( V_2 ) ) ? 1 : 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_28 ) ;
F_10 ( V_2 , V_17 ) ;
F_10 ( V_2 , V_28 ) ;
F_12 ( V_2 , V_17 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_36 )
{
int V_37 ;
F_12 ( V_2 , V_17 ) ;
F_10 ( V_2 , V_17 ) ;
F_12 ( V_2 , V_28 ) ;
F_10 ( V_2 , V_28 ) ;
V_37 = F_17 ( V_2 , V_36 ) ;
if ( V_37 )
F_20 ( V_38 , L_2 ) ;
return V_37 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_28 ) ;
F_12 ( V_2 , V_28 ) ;
F_10 ( V_2 , V_17 ) ;
F_12 ( V_2 , V_17 ) ;
F_11 ( 2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_39 = 9 ;
T_1 * V_8 = & V_2 -> V_10 ;
int V_25 ;
unsigned long V_9 ;
F_2 ( & V_2 -> V_16 , V_9 ) ;
V_2 -> V_18 = F_6 ( V_2 , V_2 -> V_19 -> V_20 ) ;
* V_8 = F_6 ( V_2 , V_2 -> V_19 -> V_21 ) ;
F_4 ( & V_2 -> V_16 , V_9 ) ;
F_20 ( V_38 , L_3
L_4 , ( unsigned long long ) * V_8 ) ;
F_10 ( V_2 , V_28 ) ;
F_12 ( V_2 , V_17 ) ;
while ( V_39 -- ) {
F_10 ( V_2 , V_17 ) ;
if ( F_13 ( V_2 , 0 ) ) {
F_12 ( V_2 , V_28 ) ;
F_10 ( V_2 , V_28 ) ;
F_10 ( V_2 , V_17 ) ;
F_12 ( V_2 , V_17 ) ;
V_25 = 0 ;
goto V_26;
}
F_10 ( V_2 , V_28 ) ;
}
V_25 = 1 ;
V_26:
return V_25 ;
}
static int F_23 ( struct V_1 * V_2 , int V_40 )
{
int V_25 = 0 ;
V_25 = F_22 ( V_2 ) ;
if ( V_25 ) {
F_24 ( V_2 , L_5 ,
V_40 ) ;
return V_25 ;
}
V_25 = F_19 ( V_2 , V_40 | V_41 ) ;
if ( V_25 )
F_20 ( V_38 , L_6 ,
V_40 ) ;
else {
int V_35 ;
V_35 = F_16 ( V_2 ) ;
F_21 ( V_2 ) ;
F_20 ( V_38 , L_7 , V_40 ) ;
}
return V_25 ;
}
static struct V_42 * F_25 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = V_2 -> V_44 - 1 ;
if ( V_43 >= 0 && V_43 < ( F_26 ( V_45 ) - 1 ) )
goto V_46;
V_43 = 0 ;
while ( V_45 [ V_43 ] . V_47 != V_48 ) {
if ( ! F_23 ( V_2 , V_45 [ V_43 ] . V_47 ) )
break;
++ V_43 ;
}
if ( V_43 == 0 )
F_22 ( V_2 ) ;
if ( V_45 [ V_43 ] . V_47 == V_48 )
V_43 = - 1 ;
else
V_2 -> V_44 = V_43 + 1 ;
V_46:
return ( V_43 >= 0 ) ? V_45 + V_43 : NULL ;
}
static int F_27 ( struct V_1 * V_2 ,
T_2 V_49 , void * V_50 , int V_51 )
{
int V_25 ;
struct V_42 * V_52 ;
T_2 * V_53 = V_50 ;
V_25 = 1 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
goto V_26;
if ( V_52 -> V_54 == V_48 ) {
F_20 ( V_38 , L_8 ) ;
V_49 = ( V_49 << 1 ) | V_41 ;
V_25 = F_19 ( V_2 , V_49 ) ;
} else {
F_20 ( V_38 , L_9 ) ;
if ( F_19 ( V_2 , V_52 -> V_54 | V_55 ) ) {
F_14 ( L_10 ) ;
F_21 ( V_2 ) ;
V_25 = 1 ;
goto V_26;
}
V_25 = F_17 ( V_2 , V_49 ) ;
F_21 ( V_2 ) ;
if ( V_25 ) {
F_24 ( V_2 , L_11 ) ;
V_25 = 1 ;
goto V_26;
}
V_25 = F_19 ( V_2 , V_52 -> V_54 | V_41 ) ;
}
if ( V_25 ) {
F_14 ( L_12 , V_52 -> V_54 ) ;
F_21 ( V_2 ) ;
V_25 = 1 ;
goto V_26;
}
while ( V_51 -- > 0 ) {
* V_53 ++ = F_16 ( V_2 ) ;
if ( V_51 )
F_18 ( V_2 ) ;
}
F_21 ( V_2 ) ;
V_25 = 0 ;
V_26:
return V_25 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 V_49 ,
const void * V_50 , int V_51 )
{
int V_56 ;
const T_2 * V_53 = V_50 ;
int V_57 , V_58 ;
int V_25 ;
struct V_42 * V_52 ;
V_25 = 1 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
goto V_26;
while ( V_51 > 0 ) {
if ( V_52 -> V_54 == V_48 ) {
if ( F_19 ( V_2 ,
( V_49 << 1 ) | V_55 ) ) {
F_14 ( L_13 ,
V_49 ) ;
goto V_59;
}
} else {
if ( F_19 ( V_2 , V_52 -> V_54 | V_55 ) ) {
F_14 ( L_10 ) ;
goto V_59;
}
V_25 = F_17 ( V_2 , V_49 ) ;
if ( V_25 ) {
F_24 ( V_2 , L_14
L_15 ) ;
goto V_59;
}
}
V_56 = F_29 ( V_51 , 4 ) ;
V_49 += V_56 ;
V_51 -= V_56 ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
if ( F_17 ( V_2 , * V_53 ++ ) ) {
F_14 ( L_16
L_17 , V_58 , V_56 ,
V_51 + V_56 - V_58 ) ;
goto V_59;
}
}
F_21 ( V_2 ) ;
V_57 = 100 ;
while ( F_19 ( V_2 , V_52 -> V_54 | V_41 ) ) {
F_21 ( V_2 ) ;
if ( ! -- V_57 ) {
F_14 ( L_18
L_19 ) ;
goto V_59;
}
}
F_16 ( V_2 ) ;
F_21 ( V_2 ) ;
}
V_25 = 0 ;
goto V_26;
V_59:
F_21 ( V_2 ) ;
V_25 = 1 ;
V_26:
return V_25 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_49 ,
void * V_60 , int V_51 )
{
int V_25 ;
V_25 = F_31 ( & V_2 -> V_61 ) ;
if ( ! V_25 ) {
V_25 = F_27 ( V_2 , V_49 , V_60 , V_51 ) ;
F_32 ( & V_2 -> V_61 ) ;
}
return V_25 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_49 ,
const void * V_60 , int V_51 )
{
int V_25 ;
V_25 = F_31 ( & V_2 -> V_61 ) ;
if ( ! V_25 ) {
V_25 = F_28 ( V_2 , V_49 , V_60 , V_51 ) ;
F_32 ( & V_2 -> V_61 ) ;
}
return V_25 ;
}
static T_2 F_34 ( struct V_62 * V_63 , int V_64 )
{
T_2 * V_65 = ( T_2 * ) V_63 ;
T_2 V_66 = 0 , V_51 ;
V_51 = V_63 -> V_67 ;
if ( V_51 > sizeof( struct V_62 ) )
V_51 = sizeof( struct V_62 ) ;
while ( V_51 -- )
V_66 += * V_65 ++ ;
V_66 -= V_63 -> V_68 ;
V_66 = ~ V_66 ;
if ( V_64 )
V_63 -> V_68 = V_66 ;
return V_66 ;
}
void F_35 ( struct V_1 * V_2 )
{
void * V_69 ;
struct V_62 * V_63 ;
T_3 V_70 ;
int V_51 , V_71 ;
T_2 V_66 , * V_72 ;
int V_73 = V_2 -> V_74 ;
struct V_1 * V_75 = F_36 ( 0 ) ;
if ( V_73 && V_75 -> V_76 > 1 && V_73 <= V_75 -> V_76 ) {
T_2 V_77 ;
V_2 -> V_78 = V_75 -> V_78 ;
V_72 = ( T_2 * ) & V_2 -> V_78 ;
V_77 = V_72 [ 7 ] ;
V_72 [ 7 ] += V_73 ;
if ( V_77 > V_72 [ 7 ] ) {
if ( V_72 [ 6 ] == 0xff ) {
if ( V_72 [ 5 ] == 0xff ) {
F_24 (
V_2 ,
L_20
L_21 ,
F_37 ( V_73 ) ) ;
V_2 -> V_78 = 0 ;
goto V_26;
}
V_72 [ 5 ] ++ ;
}
V_72 [ 6 ] ++ ;
}
V_2 -> V_76 = 1 ;
F_14 ( L_22
L_23 ,
V_75 -> V_76 , V_73 ,
( unsigned long long ) F_38 ( V_2 -> V_78 ) ) ;
goto V_26;
}
V_51 = sizeof( struct V_62 ) ;
V_69 = F_39 ( V_51 ) ;
if ( ! V_69 ) {
F_24 ( V_2 , L_24
L_25 , V_51 ) ;
goto V_26;
}
F_40 ( & V_2 -> V_61 ) ;
V_71 = F_27 ( V_2 , 0 , V_69 , V_51 ) ;
F_32 ( & V_2 -> V_61 ) ;
if ( V_71 ) {
F_24 ( V_2 , L_26 ) ;
goto V_46;
}
V_63 = (struct V_62 * ) V_69 ;
V_66 = F_34 ( V_63 , 0 ) ;
if ( V_66 != V_63 -> V_68 ) {
F_41 ( & V_2 -> V_79 -> V_80 , L_27
L_28 , V_66 , V_63 -> V_68 ) ;
goto V_46;
}
if ( * ( T_3 * ) V_63 -> V_81 == F_42 ( 0 ) ||
* ( T_3 * ) V_63 -> V_81 == ~ F_42 ( 0 ) ) {
F_24 ( V_2 , L_29
L_30 ,
* ( unsigned long long * ) V_63 -> V_81 ) ;
goto V_46;
}
if ( * ( T_1 * ) V_63 -> V_81 == 0x100007511000000ULL )
F_41 ( & V_2 -> V_79 -> V_80 , L_31
L_32 ,
* ( unsigned long long * ) V_63 -> V_81 ) ;
V_72 = V_63 -> V_81 ;
if ( ! V_72 [ 0 ] && ! V_72 [ 1 ] && ! V_72 [ 2 ] ) {
V_72 [ 1 ] = V_72 [ 3 ] ;
V_72 [ 2 ] = V_72 [ 4 ] ;
V_72 [ 3 ] = V_72 [ 4 ] = 0 ;
V_70 = * ( T_3 * ) V_63 -> V_81 ;
F_20 ( V_38 , L_33
L_34 ) ;
} else
V_70 = * ( T_3 * ) V_63 -> V_81 ;
V_2 -> V_78 = V_70 ;
V_2 -> V_76 = V_63 -> V_82 ;
if ( ( V_63 -> V_83 > 1 ) && V_63 -> V_84 [ 0 ]
&& ( ( T_2 * ) V_63 -> V_84 ) [ 0 ] != 0xFF ) {
char * V_85 = V_2 -> V_86 ;
memcpy ( V_85 , V_63 -> V_84 , sizeof V_63 -> V_84 ) ;
V_85 [ sizeof V_63 -> V_84 ] = '\0' ;
V_51 = strlen ( V_85 ) ;
V_85 += V_51 ;
V_51 = ( sizeof V_2 -> V_86 ) - V_51 ;
if ( V_51 > sizeof V_63 -> V_87 ) {
V_51 = sizeof V_63 -> V_87 ;
}
memcpy ( V_85 , V_63 -> V_87 , V_51 ) ;
} else
memcpy ( V_2 -> V_86 , V_63 -> V_87 ,
sizeof V_63 -> V_87 ) ;
if ( ! strstr ( V_63 -> V_88 , L_35 ) )
F_24 ( V_2 , L_36
L_37 , V_2 -> V_86 ,
V_63 -> V_88 ) ;
F_20 ( V_38 , L_38 ,
( unsigned long long ) F_38 ( V_2 -> V_78 ) ) ;
memcpy ( & V_2 -> V_89 , & V_63 -> V_90 , V_91 ) ;
F_43 ( & V_2 -> V_92 , 0 ) ;
V_2 -> V_93 = V_63 -> V_94 [ 0 ] | ( V_63 -> V_94 [ 1 ] << 8 ) ;
V_46:
F_44 ( V_69 ) ;
V_26: ;
}
int F_45 ( struct V_1 * V_2 )
{
void * V_69 ;
struct V_62 * V_63 ;
int V_51 , V_95 ;
T_4 V_96 , V_97 ;
T_2 V_66 ;
int V_25 , V_43 ;
unsigned long V_9 ;
V_25 = 0 ;
for ( V_43 = 0 ; V_43 < V_91 ; ++ V_43 ) {
if ( V_2 -> V_98 [ V_43 ] ) {
V_25 = 1 ;
break;
}
}
V_96 = F_46 ( & V_2 -> V_92 ) ;
if ( V_25 == 0 && V_96 < 3600 )
return 0 ;
V_51 = sizeof( struct V_62 ) ;
V_69 = F_39 ( V_51 ) ;
V_25 = 1 ;
if ( ! V_69 ) {
F_24 ( V_2 , L_24
L_39 , V_51 ) ;
goto V_26;
}
V_25 = F_31 ( & V_2 -> V_61 ) ;
if ( V_25 ) {
F_24 ( V_2 , L_40 ) ;
goto V_99;
}
V_25 = F_27 ( V_2 , 0 , V_69 , V_51 ) ;
if ( V_25 ) {
F_32 ( & V_2 -> V_61 ) ;
F_24 ( V_2 , L_41 ) ;
goto V_99;
}
V_63 = (struct V_62 * ) V_69 ;
V_66 = F_34 ( V_63 , 0 ) ;
if ( V_66 != V_63 -> V_68 ) {
F_32 ( & V_2 -> V_61 ) ;
F_24 ( V_2 , L_42 ,
V_66 , V_63 -> V_68 ) ;
V_25 = 1 ;
goto V_99;
}
V_95 = 0 ;
F_2 ( & V_2 -> V_100 , V_9 ) ;
for ( V_43 = 0 ; V_43 < V_91 ; ++ V_43 ) {
int V_101 = V_2 -> V_98 [ V_43 ] ;
if ( V_101 ) {
V_101 += V_63 -> V_90 [ V_43 ] ;
if ( V_101 > 0xFF )
V_101 = 0xFF ;
if ( V_63 -> V_90 [ V_43 ] != V_101 ) {
V_63 -> V_90 [ V_43 ] = V_101 ;
V_95 = F_47 ( struct V_62 ,
V_90 ) + V_43 ;
}
V_2 -> V_89 [ V_43 ] = V_101 ;
V_2 -> V_98 [ V_43 ] = 0 ;
}
}
if ( V_96 >= 3600 ) {
V_97 = V_96 / 3600 ;
F_48 ( ( V_97 * 3600 ) , & V_2 -> V_92 ) ;
V_97 += V_2 -> V_93 ;
if ( V_97 > 0xFFFF )
V_97 = 0xFFFF ;
V_2 -> V_93 = V_97 ;
if ( ( V_97 & 0xFF ) != V_63 -> V_94 [ 0 ] ) {
V_63 -> V_94 [ 0 ] = V_97 & 0xFF ;
V_95 = F_47 ( struct V_62 , V_94 ) ;
}
if ( ( V_97 >> 8 ) != V_63 -> V_94 [ 1 ] ) {
V_63 -> V_94 [ 1 ] = V_97 >> 8 ;
V_95 = F_47 ( struct V_62 , V_94 )
+ 1 ;
}
}
F_4 ( & V_2 -> V_100 , V_9 ) ;
if ( V_95 ) {
V_66 = F_34 ( V_63 , 1 ) ;
V_25 = F_28 ( V_2 , 0 , V_69 , V_95 + 1 ) ;
}
F_32 ( & V_2 -> V_61 ) ;
if ( V_25 )
F_24 ( V_2 , L_43 ) ;
V_99:
F_44 ( V_69 ) ;
V_26:
return V_25 ;
}
void F_49 ( struct V_1 * V_2 , T_5 V_102 , T_5 V_103 )
{
T_6 V_101 ;
unsigned long V_9 ;
F_2 ( & V_2 -> V_100 , V_9 ) ;
V_101 = V_2 -> V_98 [ V_102 ] + V_103 ;
if ( V_101 > 255 )
V_101 = 255 ;
V_2 -> V_98 [ V_102 ] = V_101 ;
F_4 ( & V_2 -> V_100 , V_9 ) ;
return;
}
static int F_50 ( struct V_1 * V_2 , T_2 V_104 )
{
int V_25 ;
struct V_42 * V_52 ;
V_25 = - V_105 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
goto V_26;
if ( V_52 -> V_106 == V_48 ) {
V_25 = - V_107 ;
goto V_26;
}
if ( F_19 ( V_2 , V_52 -> V_106 | V_55 ) ) {
F_14 ( L_44 ) ;
F_21 ( V_2 ) ;
V_25 = - V_107 ;
goto V_26;
}
V_25 = F_17 ( V_2 , V_104 ) ;
F_21 ( V_2 ) ;
if ( V_25 ) {
F_24 ( V_2 , L_45 ,
V_104 ) ;
V_25 = - V_107 ;
goto V_26;
}
if ( F_19 ( V_2 , V_52 -> V_106 | V_41 ) ) {
F_14 ( L_46 ) ;
F_21 ( V_2 ) ;
V_25 = - V_107 ;
goto V_26;
}
V_25 = F_16 ( V_2 ) ;
F_21 ( V_2 ) ;
V_26:
return V_25 ;
}
int F_51 ( struct V_1 * V_2 , T_2 V_104 )
{
int V_25 ;
if ( V_104 > 7 )
return - V_108 ;
if ( ! ( ( 1 << V_104 ) & V_109 ) )
return 0 ;
V_25 = F_31 ( & V_2 -> V_61 ) ;
if ( ! V_25 ) {
V_25 = F_50 ( V_2 , V_104 ) ;
F_32 ( & V_2 -> V_61 ) ;
}
return V_25 ;
}
static int F_52 ( struct V_1 * V_2 ,
T_2 V_104 , T_2 V_35 )
{
int V_25 = - V_105 ;
struct V_42 * V_52 ;
V_52 = F_25 ( V_2 ) ;
if ( ! V_52 )
goto V_26;
if ( V_52 -> V_106 == V_48 ) {
V_25 = - V_107 ;
goto V_26;
}
if ( F_19 ( V_2 , V_52 -> V_106 | V_55 ) ) {
F_14 ( L_44 ) ;
F_21 ( V_2 ) ;
V_25 = - V_107 ;
goto V_26;
}
V_25 = F_17 ( V_2 , V_104 ) ;
if ( V_25 ) {
F_21 ( V_2 ) ;
F_24 ( V_2 , L_47 ,
V_104 ) ;
V_25 = - V_107 ;
goto V_26;
}
V_25 = F_17 ( V_2 , V_35 ) ;
F_21 ( V_2 ) ;
V_25 = F_19 ( V_2 , V_52 -> V_106 | V_41 ) ;
if ( V_25 ) {
F_24 ( V_2 , L_48 ,
V_104 ) ;
V_25 = - V_107 ;
}
V_26:
return V_25 ;
}
int F_53 ( struct V_1 * V_2 , T_2 V_104 , T_2 V_35 )
{
int V_25 ;
if ( V_104 > 15 || ! ( ( 1 << V_104 ) & V_110 ) )
return - V_108 ;
V_25 = F_31 ( & V_2 -> V_61 ) ;
if ( ! V_25 ) {
V_25 = F_52 ( V_2 , V_104 , V_35 ) ;
F_32 ( & V_2 -> V_61 ) ;
}
return V_25 ;
}
