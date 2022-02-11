static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_6 , & V_4 ) ;
if ( ! V_4 )
V_2 -> V_7 = V_3 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 * V_8 )
{
T_1 V_9 , V_10 ;
int V_4 ;
* V_8 = 0 ;
V_9 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_11 , & V_4 ) ;
if ( V_4 )
return - V_12 ;
V_10 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_13 , & V_4 ) ;
if ( V_4 )
return - V_12 ;
* V_8 = ( ( ( T_2 ) V_10 ) << 8 ) | V_9 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_8 )
{
T_1 V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_14 , & V_4 ) ;
if ( ! V_4 )
* V_8 = ( T_2 ) V_3 << V_2 -> V_7 ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_15 )
{
int V_4 ;
F_6 ( V_2 -> V_5 , V_15 , V_2 -> V_3 -> V_16 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_1 ) ;
V_4 = - V_12 ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_15 )
{
T_1 V_16 ;
int V_4 ;
V_16 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_16 , & V_4 ) ;
if ( V_4 )
return - V_12 ;
V_16 &= ~ V_15 ;
F_6 ( V_2 -> V_5 , V_16 , V_2 -> V_3 -> V_16 , & V_4 ) ;
if ( V_4 < 0 ) {
F_7 ( L_2 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
unsigned int V_18 ;
T_1 V_19 ;
int V_4 ;
for ( V_18 = 0 ; V_18 < V_20 * 1000 ; V_18 ++ ) {
V_19 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_21 , & V_4 ) ;
if ( V_4 )
goto V_22;
if ( ( V_19 & V_17 ) == V_17 )
return V_4 ;
F_10 ( 1 ) ;
}
V_4 = - V_23 ;
V_22:
F_7 ( L_3 , V_4 ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_24 )
{
int V_4 = - V_23 ;
T_2 V_25 ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ ) {
if ( F_3 ( V_2 , & V_25 ) < 0 )
continue;
if ( V_25 == V_26 ) {
V_4 = 0 ;
break;
} else {
F_12 ( 10 ) ;
}
}
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 )
{
const struct V_27 * V_28 = NULL ;
const T_1 * V_29 = NULL ;
int V_4 ;
void * V_30 = NULL ;
int V_31 , V_32 , V_33 ;
T_1 * V_34 ;
T_3 V_35 ;
V_4 = F_14 ( & V_28 , V_2 -> V_29 ,
& V_2 -> V_5 -> V_36 ) ;
if ( ( V_4 < 0 ) || ! V_28 ) {
F_7 ( L_4 ,
V_4 ) ;
V_4 = - V_37 ;
goto V_38;
}
V_29 = V_28 -> V_39 ;
V_33 = V_28 -> V_40 ;
F_15 ( L_5 ,
V_33 , V_41 ) ;
V_31 = F_16 ( V_42 , V_43 ) ;
V_30 = F_17 ( V_31 , V_44 ) ;
if ( ! V_30 ) {
F_7 ( L_6
L_7 ) ;
V_4 = - V_45 ;
goto V_38;
}
V_34 = ( T_1 * ) F_18 ( V_30 , V_43 ) ;
V_35 = ( V_46 * V_41 )
- V_47 ;
V_32 = 0 ;
do {
V_4 = F_9 ( V_2 ,
V_48 | V_49 ) ;
if ( V_4 < 0 ) {
F_7 ( L_8 ,
V_32 ) ;
goto V_38;
}
if ( V_32 >= V_33 )
break;
if ( V_33 - V_32 < V_35 )
V_35 = V_33 - V_32 ;
V_34 [ 0 ] = ( ( V_35 & 0x000000ff ) >> 0 ) ;
V_34 [ 1 ] = ( ( V_35 & 0x0000ff00 ) >> 8 ) ;
V_34 [ 2 ] = ( ( V_35 & 0x00ff0000 ) >> 16 ) ;
V_34 [ 3 ] = ( ( V_35 & 0xff000000 ) >> 24 ) ;
memcpy ( & V_34 [ V_47 ] , & V_29 [ V_32 ] ,
V_35 ) ;
V_4 = F_19 ( V_2 -> V_5 , V_2 -> V_50 , V_34 ,
V_46 * V_41 ) ;
if ( V_4 < 0 ) {
F_7 ( L_9 ,
V_32 ) ;
goto V_38;
}
V_32 += V_35 ;
} while ( true );
F_15 ( L_10 ) ;
memset ( V_34 , 0x0 , V_41 ) ;
V_4 = F_19 ( V_2 -> V_5 , V_2 -> V_50 , V_34 ,
V_41 ) ;
if ( V_4 < 0 ) {
F_7 ( L_11 ) ;
goto V_38;
}
V_4 = 0 ;
V_38:
F_20 ( V_30 ) ;
F_21 ( V_28 ) ;
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_27 * V_51 = NULL ;
const T_1 * V_27 = NULL ;
int V_52 , V_53 , V_4 ;
unsigned int V_18 , V_54 ;
T_1 V_55 , V_56 ;
void * V_57 = NULL ;
T_1 * V_58 ;
T_2 V_59 , V_60 = V_2 -> V_61 ;
int V_62 = 0 , V_63 = 0 , V_64 = 0 ;
V_4 = F_14 ( & V_51 , V_2 -> V_27 ,
& V_2 -> V_5 -> V_36 ) ;
if ( ( V_4 < 0 ) || ! V_51 ) {
F_7 ( L_12 ,
V_4 ) ;
V_4 = - V_37 ;
goto V_38;
}
V_27 = V_51 -> V_39 ;
V_52 = V_51 -> V_40 ;
F_15 ( L_13 , V_52 ) ;
V_53 = F_16 ( V_42 , V_43 ) ;
V_57 = F_17 ( V_53 , V_44 ) ;
if ( ! V_57 ) {
F_7 ( L_14
L_7 ) ;
V_4 = - V_45 ;
goto V_38;
}
V_58 = ( T_1 * ) F_18 ( V_57 , V_43 ) ;
V_54 = 0 ;
do {
V_4 = F_9 ( V_2 ,
V_48 | V_49 ) ;
if ( V_4 < 0 ) {
F_7 ( L_15
L_16 , V_54 ) ;
goto V_38;
}
if ( V_54 >= V_52 )
break;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_55 = F_2 ( V_2 -> V_5 ,
V_2 -> V_3 -> V_65 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_17
L_18
L_7 ,
V_55 , V_55 ) ;
V_4 = - V_12 ;
goto V_38;
}
V_56 = F_2 ( V_2 -> V_5 ,
V_2 -> V_3 -> V_66 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_19
L_20
L_7 ,
V_56 , V_56 ) ;
V_4 = - V_12 ;
goto V_38;
}
V_59 = ( ( ( T_2 ) V_56 ) << 8 ) | V_55 ;
if ( V_59 )
break;
F_10 ( 10 ) ;
}
if ( ! V_59 )
break;
else if ( V_59 > V_42 ) {
F_7 ( L_21 ,
V_54 , V_59 ) ;
V_4 = - V_67 ;
goto V_38;
}
V_62 = V_59 ;
if ( V_59 & F_23 ( 0 ) ) {
V_64 ++ ;
if ( V_64 > V_68 ) {
F_7 ( L_22
L_23 , V_54 ) ;
V_4 = - V_12 ;
goto V_38;
}
F_7 ( L_24
L_25 , V_59 , V_62 ) ;
V_59 &= ~ F_23 ( 0 ) ;
V_62 = 0 ;
} else {
V_64 = 0 ;
if ( V_52 - V_54 < V_62 )
V_62 = V_52 - V_54 ;
V_63 = ( V_62 + V_60 - 1 ) / V_60 ;
memcpy ( V_58 , & V_27 [ V_54 ] , V_62 ) ;
}
V_4 = F_19 ( V_2 -> V_5 , V_2 -> V_50 , V_58 ,
V_63 * V_60 ) ;
if ( V_4 < 0 ) {
F_7 ( L_26 ,
V_64 , V_54 ) ;
F_6 ( V_2 -> V_5 , V_69 ,
V_2 -> V_3 -> V_70 , & V_4 ) ;
if ( V_4 )
F_7 ( L_27 ) ;
}
V_54 += V_62 ;
} while ( true );
F_15 ( L_28 , V_54 ) ;
V_4 = 0 ;
V_38:
F_20 ( V_57 ) ;
F_21 ( V_51 ) ;
return V_4 ;
}
static int F_24 ( struct V_71 * V_72 )
{
T_2 V_73 = 0 ;
int V_4 , V_74 , V_75 ;
struct V_76 * V_77 = NULL ;
T_3 type ;
T_1 * V_78 = NULL ;
struct V_79 * V_80 = V_72 -> V_81 . V_82 ;
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
V_4 = - V_67 ;
goto exit;
}
V_4 = F_4 ( V_2 , & V_73 ) ;
if ( V_4 < 0 ) {
F_7 ( L_30 ) ;
V_4 = - V_12 ;
goto exit;
}
V_75 = V_41 ;
V_74 = F_25 ( V_73 , V_75 ) ;
if ( V_73 <= V_47
|| ( V_74 * V_75 ) > V_83 ) {
F_7 ( L_31 , V_73 ) ;
V_4 = - V_67 ;
goto exit;
}
V_77 = F_26 ( V_74 * V_75 + V_43 , V_84 ) ;
if ( V_77 == NULL ) {
F_7 ( L_32 ) ;
goto exit;
}
if ( ( unsigned long ) V_77 -> V_39 & ( V_43 - 1 ) ) {
F_27 ( V_77 , ( unsigned long ) V_77 -> V_39 &
( V_43 - 1 ) ) ;
F_28 ( V_77 , ( unsigned long ) V_77 -> V_39 &
( V_43 - 1 ) ) ;
}
V_78 = V_77 -> V_39 ;
V_4 = F_29 ( V_2 -> V_5 , V_78 , V_2 -> V_50 ,
V_74 * V_75 ) ;
if ( V_4 < 0 ) {
F_7 ( L_33 , V_4 ) ;
V_4 = - V_12 ;
goto exit;
}
V_73 = V_78 [ 0 ] ;
V_73 |= V_78 [ 1 ] << 8 ;
V_73 |= V_78 [ 2 ] << 16 ;
if ( V_73 > V_75 * V_74 ) {
F_7 ( L_34 ,
V_73 , V_75 * V_74 ) ;
V_4 = - V_12 ;
goto exit;
}
type = V_78 [ 3 ] ;
switch ( type ) {
case V_85 :
case V_86 :
case V_87 :
F_30 ( V_77 ) -> V_88 = type ;
V_77 -> V_36 = ( void * ) V_80 ;
F_27 ( V_77 , V_73 ) ;
F_28 ( V_77 , V_47 ) ;
if ( type == V_87 ) {
if ( F_31 ( V_72 , V_77 ) )
F_32 ( V_77 ) ;
} else {
F_32 ( V_77 ) ;
}
V_80 -> V_89 . V_90 += V_73 ;
break;
case V_91 :
F_30 ( V_77 ) -> V_88 = V_92 ;
V_77 -> V_36 = ( void * ) V_80 ;
F_27 ( V_77 , V_73 ) ;
F_28 ( V_77 , V_47 ) ;
if ( F_33 ( V_72 , V_77 ) )
F_32 ( V_77 ) ;
V_80 -> V_89 . V_90 += V_73 ;
break;
default:
F_7 ( L_35 , type ) ;
F_7 ( L_36 , V_75 * V_74 , V_78 ) ;
F_34 ( V_77 ) ;
V_77 = NULL ;
break;
}
exit:
if ( V_4 ) {
V_80 -> V_89 . V_93 ++ ;
F_34 ( V_77 ) ;
}
return V_4 ;
}
static int F_35 ( struct V_71 * V_72 )
{
T_4 V_94 ;
T_1 V_95 ;
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
F_36 ( & V_72 -> V_96 , V_94 ) ;
V_95 = V_97 ;
V_97 = 0 ;
F_37 ( & V_72 -> V_96 , V_94 ) ;
F_38 ( V_2 -> V_5 ) ;
if ( V_95 & V_98 ) {
if ( V_72 -> V_81 . V_99 )
F_15 ( L_37
L_38 , V_95 ) ;
else
V_72 -> V_81 . V_99 = true ;
}
if ( V_95 & V_100 )
F_24 ( V_72 ) ;
F_39 ( V_2 -> V_5 ) ;
return 0 ;
}
static void F_40 ( struct V_101 * V_5 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 ;
T_4 V_94 ;
T_1 V_95 = 0 ;
int V_4 ;
V_2 = F_41 ( V_5 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_7 ( L_39
L_40 , V_5 , V_2 ) ;
return;
}
V_72 = V_2 -> V_72 ;
V_95 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_102 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_41 ) ;
return;
}
if ( V_95 != 0 ) {
F_15 ( L_42 , V_95 ) ;
F_6 ( V_2 -> V_5 , ~ ( V_95 ) & ( V_98 |
V_100 ) ,
V_2 -> V_3 -> V_102 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_43 ) ;
return;
}
}
F_36 ( & V_72 -> V_96 , V_94 ) ;
V_97 |= V_95 ;
F_37 ( & V_72 -> V_96 , V_94 ) ;
F_42 ( V_72 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_101 * V_5 ;
T_1 V_3 ;
int V_4 = 0 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_44 ) ;
V_4 = - V_67 ;
goto V_22;
}
V_5 = V_2 -> V_5 ;
F_38 ( V_5 ) ;
V_4 = F_44 ( V_5 ) ;
if ( V_4 ) {
F_7 ( L_45 , V_4 ) ;
V_4 = - V_12 ;
goto V_103;
}
V_4 = F_45 ( V_5 , F_40 ) ;
if ( V_4 ) {
F_7 ( L_46 , V_4 ) ;
V_4 = - V_12 ;
goto V_104;
}
V_4 = F_46 ( V_2 -> V_5 , V_41 ) ;
if ( V_4 ) {
F_7 ( L_47 ) ;
V_4 = - V_12 ;
goto V_105;
}
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_106 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_105;
}
V_2 -> V_50 = V_3 ;
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_107 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_105;
}
V_2 -> V_50 |= ( V_3 << 8 ) ;
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_108 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_105;
}
V_2 -> V_50 |= ( V_3 << 16 ) ;
F_15 ( L_48 , V_5 -> V_109 , V_2 -> V_50 ) ;
F_47 ( V_5 , V_2 ) ;
F_39 ( V_5 ) ;
return 0 ;
V_105:
F_48 ( V_5 ) ;
V_104:
F_49 ( V_5 ) ;
V_103:
F_39 ( V_5 ) ;
V_22:
return V_4 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_5 ) {
F_38 ( V_2 -> V_5 ) ;
F_48 ( V_2 -> V_5 ) ;
F_49 ( V_2 -> V_5 ) ;
F_39 ( V_2 -> V_5 ) ;
F_47 ( V_2 -> V_5 , NULL ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return - V_67 ;
F_38 ( V_2 -> V_5 ) ;
V_4 = F_5 ( V_2 , V_110 ) ;
F_1 ( V_2 ) ;
F_39 ( V_2 -> V_5 ) ;
return V_4 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return - V_67 ;
F_38 ( V_2 -> V_5 ) ;
V_4 = F_8 ( V_2 , V_111 ) ;
F_39 ( V_2 -> V_5 ) ;
return V_4 ;
}
static int F_53 ( struct V_71 * V_72 ,
T_1 * V_78 , T_2 V_112 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 = 0 ;
int V_113 ;
int V_75 ;
int V_114 = 0 ;
T_1 * V_115 = NULL ;
void * V_116 = NULL ;
int V_117 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
return - V_67 ;
}
V_115 = V_78 ;
if ( ( unsigned long ) V_78 & ( V_43 - 1 ) ) {
V_117 = F_16 ( V_112 , V_43 ) ;
V_116 = F_17 ( V_117 , V_44 ) ;
if ( ! V_116 )
return - V_45 ;
V_115 = ( T_1 * ) F_18 ( V_116 , V_43 ) ;
memcpy ( V_115 , V_78 , V_112 ) ;
}
V_75 = V_41 ;
V_113 = ( V_112 + V_75 - 1 ) / V_75 ;
F_38 ( V_2 -> V_5 ) ;
do {
V_4 = F_19 ( V_2 -> V_5 , V_2 -> V_50 , V_115 ,
V_113 * V_75 ) ;
if ( V_4 < 0 ) {
V_114 ++ ;
F_7 ( L_49 , V_114 , V_4 ) ;
F_7 ( L_36 , V_112 , V_78 ) ;
V_4 = - V_12 ;
if ( V_114 > V_68 )
goto exit;
}
} while ( V_4 );
V_72 -> V_81 . V_99 = false ;
exit:
F_39 ( V_2 -> V_5 ) ;
F_20 ( V_116 ) ;
return V_4 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
T_1 V_9 ;
int V_24 = V_20 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
return - V_67 ;
}
F_38 ( V_2 -> V_5 ) ;
if ( ! F_11 ( V_2 , 1 ) ) {
F_15 ( L_50 ) ;
goto V_38;
}
V_9 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_11 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_51 ) ;
V_4 = - V_12 ;
goto V_38;
}
if ( V_9 ) {
F_15 ( L_52 , V_9 ) ;
V_24 *= 10 ;
} else {
if ( V_2 -> V_29 ) {
V_4 = F_13 ( V_2 ) ;
if ( V_4 ) {
F_7 ( L_53 ) ;
V_4 = - V_12 ;
goto V_38;
}
}
if ( F_22 ( V_2 ) ) {
F_7 ( L_54 ) ;
V_4 = - V_12 ;
goto V_38;
}
}
if ( F_11 ( V_2 , V_24 ) ) {
F_7 ( L_55 ) ;
V_4 = - V_23 ;
goto V_38;
}
V_38:
F_39 ( V_2 -> V_5 ) ;
return V_4 ;
}
static int F_55 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 = 0 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
return - V_67 ;
}
F_38 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_5 , V_118 , V_2 -> V_3 -> V_70 , & V_4 ) ;
F_39 ( V_2 -> V_5 ) ;
F_15 ( L_56 ) ;
return V_4 ;
}
static int F_56 ( struct V_101 * V_5 ,
const struct V_119 * V_120 )
{
int V_4 = 0 ;
struct V_71 * V_72 = NULL ;
struct V_1 * V_2 = NULL ;
F_57 ( L_57 ,
V_120 -> V_121 , V_120 -> V_122 , V_120 -> V_123 , V_5 -> V_109 ) ;
V_2 = F_58 ( & V_5 -> V_36 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_5 = V_5 ;
if ( V_120 -> V_124 ) {
struct V_125 * V_39 = ( void * ) V_120 -> V_124 ;
V_2 -> V_29 = V_39 -> V_29 ;
V_2 -> V_27 = V_39 -> V_27 ;
V_2 -> V_3 = V_39 -> V_3 ;
V_2 -> V_61 = V_39 -> V_61 ;
}
if ( F_43 ( V_2 ) < 0 ) {
F_7 ( L_58 ) ;
return - V_126 ;
}
F_52 ( V_2 ) ;
if ( F_54 ( V_2 ) ) {
F_7 ( L_59 ) ;
V_4 = - V_126 ;
goto V_127;
}
F_12 ( 100 ) ;
F_51 ( V_2 ) ;
V_72 = F_59 ( V_2 ) ;
if ( ! V_72 ) {
F_7 ( L_60 ) ;
V_4 = - V_126 ;
goto V_128;
}
V_2 -> V_72 = V_72 ;
V_72 -> V_129 = F_53 ;
V_72 -> V_130 = F_55 ;
V_72 -> V_131 = F_35 ;
if ( F_60 ( V_72 ) ) {
F_7 ( L_61 ) ;
V_4 = - V_126 ;
goto V_128;
}
V_72 -> V_81 . V_132 = 1 ;
F_61 ( V_72 ) ;
V_72 -> V_81 . V_133 = 0xffff ;
F_62 ( V_72 ) ;
return 0 ;
V_128:
F_52 ( V_2 ) ;
V_127:
F_50 ( V_2 ) ;
return V_4 ;
}
static void F_63 ( struct V_101 * V_5 )
{
struct V_1 * V_2 ;
if ( V_5 ) {
V_2 = F_41 ( V_5 ) ;
if ( V_2 ) {
if ( V_134 ) {
F_64 ( V_2 -> V_72 ,
V_135 ) ;
F_52 ( V_2 ) ;
}
F_15 ( L_62 ) ;
F_50 ( V_2 ) ;
F_65 ( V_2 -> V_72 ) ;
}
}
}
static int F_66 ( struct V_122 * V_36 )
{
struct V_101 * V_5 = F_67 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
T_5 V_136 ;
struct V_79 * V_82 ;
if ( V_5 ) {
V_136 = F_68 ( V_5 ) ;
F_15 ( L_63 , F_69 ( V_5 ) ,
V_136 ) ;
if ( ! ( V_136 & V_137 ) ) {
F_7 ( L_64 ,
F_69 ( V_5 ) ) ;
return - V_138 ;
}
V_2 = F_41 ( V_5 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_7 ( L_65 ) ;
return 0 ;
}
} else {
F_7 ( L_66 ) ;
return 0 ;
}
V_72 = V_2 -> V_72 ;
if ( V_72 -> V_139 -> V_140 != V_141 ) {
if ( F_70 ( V_72 ) ) {
F_7 ( L_67 ) ;
return - V_142 ;
}
}
V_82 = V_72 -> V_81 . V_82 ;
F_15 ( L_68 , V_82 -> V_143 ) ;
F_71 ( V_82 ) ;
F_72 ( & V_72 -> V_139 -> V_144 ) ;
V_72 -> V_139 -> V_145 = true ;
if ( V_72 -> V_139 -> V_140 == V_141 ) {
F_15 ( L_69 ) ;
return F_73 ( V_5 , V_137 ) ;
} else {
F_15 ( L_70 ) ;
return 0 ;
}
}
static int F_74 ( struct V_122 * V_36 )
{
struct V_101 * V_5 = F_67 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
T_5 V_136 ;
struct V_79 * V_82 ;
if ( V_5 ) {
V_136 = F_68 ( V_5 ) ;
F_15 ( L_71 , F_69 ( V_5 ) ,
V_136 ) ;
V_2 = F_41 ( V_5 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_7 ( L_65 ) ;
return 0 ;
}
} else {
F_7 ( L_66 ) ;
return 0 ;
}
V_72 = V_2 -> V_72 ;
if ( ! V_72 -> V_139 -> V_145 ) {
F_15 ( L_72 ) ;
return 0 ;
}
V_72 -> V_139 -> V_145 = false ;
V_82 = V_72 -> V_81 . V_82 ;
F_15 ( L_73 , V_82 -> V_143 ) ;
F_75 ( V_82 ) ;
V_72 -> V_130 ( V_72 ) ;
V_72 -> V_139 -> V_140 = V_146 ;
F_15 ( L_74 , V_82 -> V_143 ) ;
return 0 ;
}
static int T_6 F_76 ( void )
{
if ( F_77 ( & V_147 ) != 0 ) {
F_7 ( L_75 ) ;
return - V_126 ;
}
V_134 = 0 ;
return 0 ;
}
static void T_7 F_78 ( void )
{
V_134 = 1 ;
F_79 ( & V_147 ) ;
}
