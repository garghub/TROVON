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
T_2 V_25 ;
int V_18 , V_4 ;
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ ) {
F_12 ( V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 , & V_25 ) ;
F_13 ( V_2 -> V_5 ) ;
if ( V_4 < 0 )
continue;
if ( V_25 == V_26 )
return 0 ;
F_14 ( 10 ) ;
}
return - V_23 ;
}
static int F_15 ( struct V_1 * V_2 )
{
const struct V_27 * V_28 = NULL ;
const T_1 * V_29 = NULL ;
int V_4 ;
void * V_30 = NULL ;
int V_31 , V_32 , V_33 ;
T_1 * V_34 ;
T_3 V_35 ;
V_4 = F_16 ( & V_28 , V_2 -> V_29 ,
& V_2 -> V_5 -> V_36 ) ;
if ( ( V_4 < 0 ) || ! V_28 ) {
F_7 ( L_4 ,
V_4 ) ;
V_4 = - V_37 ;
goto V_38;
}
V_29 = V_28 -> V_39 ;
V_33 = V_28 -> V_40 ;
F_17 ( L_5 ,
V_33 , V_41 ) ;
V_31 = F_18 ( V_42 , V_43 ) ;
V_30 = F_19 ( V_31 , V_44 ) ;
if ( ! V_30 ) {
F_7 ( L_6
L_7 ) ;
V_4 = - V_45 ;
goto V_38;
}
V_34 = ( T_1 * ) F_20 ( V_30 , V_43 ) ;
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
V_4 = F_21 ( V_2 -> V_5 , V_2 -> V_50 , V_34 ,
V_46 * V_41 ) ;
if ( V_4 < 0 ) {
F_7 ( L_9 ,
V_32 ) ;
goto V_38;
}
V_32 += V_35 ;
} while ( true );
F_17 ( L_10 ) ;
memset ( V_34 , 0x0 , V_41 ) ;
V_4 = F_21 ( V_2 -> V_5 , V_2 -> V_50 , V_34 ,
V_41 ) ;
if ( V_4 < 0 ) {
F_7 ( L_11 ) ;
goto V_38;
}
V_4 = 0 ;
V_38:
F_22 ( V_30 ) ;
F_23 ( V_28 ) ;
return V_4 ;
}
static int F_24 ( struct V_1 * V_2 )
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
V_4 = F_16 ( & V_51 , V_2 -> V_27 ,
& V_2 -> V_5 -> V_36 ) ;
if ( ( V_4 < 0 ) || ! V_51 ) {
F_7 ( L_12 ,
V_4 ) ;
V_4 = - V_37 ;
goto V_38;
}
V_27 = V_51 -> V_39 ;
V_52 = V_51 -> V_40 ;
F_17 ( L_13 , V_52 ) ;
V_53 = F_18 ( V_42 , V_43 ) ;
V_57 = F_19 ( V_53 , V_44 ) ;
if ( ! V_57 ) {
F_7 ( L_14
L_7 ) ;
V_4 = - V_45 ;
goto V_38;
}
V_58 = ( T_1 * ) F_20 ( V_57 , V_43 ) ;
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
if ( V_59 & F_25 ( 0 ) ) {
V_64 ++ ;
if ( V_64 > V_68 ) {
F_7 ( L_22
L_23 , V_54 ) ;
V_4 = - V_12 ;
goto V_38;
}
F_7 ( L_24
L_25 , V_59 , V_62 ) ;
V_59 &= ~ F_25 ( 0 ) ;
V_62 = 0 ;
} else {
V_64 = 0 ;
if ( V_52 - V_54 < V_62 )
V_62 = V_52 - V_54 ;
V_63 = F_26 ( V_62 , V_60 ) ;
memcpy ( V_58 , & V_27 [ V_54 ] , V_62 ) ;
}
V_4 = F_21 ( V_2 -> V_5 , V_2 -> V_50 , V_58 ,
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
F_27 ( L_28 , V_54 ) ;
V_4 = 0 ;
V_38:
F_22 ( V_57 ) ;
F_23 ( V_51 ) ;
return V_4 ;
}
static int F_28 ( struct V_71 * V_72 )
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
V_74 = F_26 ( V_73 , V_75 ) ;
if ( V_73 <= V_47
|| ( V_74 * V_75 ) > V_83 ) {
F_7 ( L_31 , V_73 ) ;
V_4 = - V_67 ;
goto exit;
}
V_77 = F_29 ( V_74 * V_75 + V_43 , V_84 ) ;
if ( V_77 == NULL ) {
F_7 ( L_32 ) ;
V_4 = - V_45 ;
goto exit;
}
if ( ( unsigned long ) V_77 -> V_39 & ( V_43 - 1 ) ) {
F_30 ( V_77 , ( unsigned long ) V_77 -> V_39 &
( V_43 - 1 ) ) ;
F_31 ( V_77 , ( unsigned long ) V_77 -> V_39 &
( V_43 - 1 ) ) ;
}
V_78 = V_77 -> V_39 ;
V_4 = F_32 ( V_2 -> V_5 , V_78 , V_2 -> V_50 ,
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
F_33 ( V_77 ) -> V_88 = type ;
F_30 ( V_77 , V_73 ) ;
F_31 ( V_77 , V_47 ) ;
if ( type == V_87 ) {
if ( F_34 ( V_72 , V_77 ) )
F_35 ( V_80 , V_77 ) ;
} else {
F_35 ( V_80 , V_77 ) ;
}
V_80 -> V_89 . V_90 += V_73 ;
break;
case V_91 :
F_33 ( V_77 ) -> V_88 = V_92 ;
F_30 ( V_77 , V_73 ) ;
F_31 ( V_77 , V_47 ) ;
if ( F_36 ( V_72 , V_77 ) )
F_35 ( V_80 , V_77 ) ;
V_80 -> V_89 . V_90 += V_73 ;
break;
default:
F_7 ( L_35 , type ) ;
F_7 ( L_36 , V_75 * V_74 , V_78 ) ;
F_37 ( V_77 ) ;
V_77 = NULL ;
break;
}
exit:
if ( V_4 ) {
V_80 -> V_89 . V_93 ++ ;
F_37 ( V_77 ) ;
}
return V_4 ;
}
static int F_38 ( struct V_71 * V_72 )
{
T_4 V_94 ;
T_1 V_95 ;
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
F_39 ( & V_72 -> V_96 , V_94 ) ;
V_95 = V_97 ;
V_97 = 0 ;
F_40 ( & V_72 -> V_96 , V_94 ) ;
F_12 ( V_2 -> V_5 ) ;
if ( V_95 & V_98 ) {
if ( V_72 -> V_81 . V_99 )
F_17 ( L_37
L_38 , V_95 ) ;
else
V_72 -> V_81 . V_99 = true ;
}
if ( V_95 & V_100 )
F_28 ( V_72 ) ;
F_13 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_95 )
{
struct V_101 * V_102 = V_2 -> V_72 -> V_102 ;
int V_4 ;
V_4 = F_32 ( V_2 -> V_5 , V_102 -> V_103 , 0 , V_41 ) ;
if ( V_4 ) {
F_7 ( L_39 , V_4 ) ;
return V_4 ;
}
* V_95 = V_102 -> V_103 [ V_2 -> V_3 -> V_104 ] ;
F_17 ( L_40 , V_2 -> V_3 -> V_104 , * V_95 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 * V_95 )
{
int V_4 ;
* V_95 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_104 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_41 , V_4 ) ;
return V_4 ;
}
if ( * V_95 ) {
F_17 ( L_42 , * V_95 ) ;
F_6 ( V_2 -> V_5 , ~ ( * V_95 ) & ( V_98 |
V_100 ) ,
V_2 -> V_3 -> V_104 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_43 , V_4 ) ;
return V_4 ;
}
}
return 0 ;
}
static void F_43 ( struct V_105 * V_5 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 ;
T_4 V_94 ;
T_1 V_95 = 0 ;
int V_4 ;
V_2 = F_44 ( V_5 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_7 ( L_44 ,
V_5 , V_2 ) ;
return;
}
V_72 = V_2 -> V_72 ;
if ( V_72 -> V_106 )
return;
if ( V_2 -> V_3 -> V_107 )
V_4 = F_41 ( V_2 , & V_95 ) ;
else
V_4 = F_42 ( V_2 , & V_95 ) ;
if ( V_4 )
return;
F_39 ( & V_72 -> V_96 , V_94 ) ;
V_97 |= V_95 ;
F_40 ( & V_72 -> V_96 , V_94 ) ;
F_45 ( V_72 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_105 * V_5 ;
T_1 V_3 ;
int V_4 = 0 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_45 ) ;
V_4 = - V_67 ;
goto V_22;
}
V_5 = V_2 -> V_5 ;
F_12 ( V_5 ) ;
V_4 = F_47 ( V_5 ) ;
if ( V_4 ) {
F_7 ( L_46 , V_4 ) ;
V_4 = - V_12 ;
goto V_108;
}
V_4 = F_48 ( V_5 , F_43 ) ;
if ( V_4 ) {
F_7 ( L_47 , V_4 ) ;
V_4 = - V_12 ;
goto V_109;
}
V_4 = F_49 ( V_2 -> V_5 , V_41 ) ;
if ( V_4 ) {
F_7 ( L_48 ) ;
V_4 = - V_12 ;
goto V_110;
}
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_111 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
V_2 -> V_50 = V_3 ;
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_112 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
V_2 -> V_50 |= ( V_3 << 8 ) ;
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_113 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
V_2 -> V_50 |= ( V_3 << 16 ) ;
F_17 ( L_49 , V_5 -> V_114 , V_2 -> V_50 ) ;
if ( V_2 -> V_3 -> V_107 ) {
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_115 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
F_6 ( V_5 , V_3 | 0x3f , V_2 -> V_3 -> V_115 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
V_3 = F_2 ( V_5 , V_2 -> V_3 -> V_116 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
F_6 ( V_5 , V_3 | 0x10 , V_2 -> V_3 -> V_116 , & V_4 ) ;
if ( V_4 < 0 ) {
V_4 = - V_12 ;
goto V_110;
}
}
F_50 ( V_5 , V_2 ) ;
F_13 ( V_5 ) ;
return 0 ;
V_110:
F_51 ( V_5 ) ;
V_109:
F_52 ( V_5 ) ;
V_108:
F_13 ( V_5 ) ;
V_22:
return V_4 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_5 ) {
F_12 ( V_2 -> V_5 ) ;
F_51 ( V_2 -> V_5 ) ;
F_52 ( V_2 -> V_5 ) ;
F_13 ( V_2 -> V_5 ) ;
F_50 ( V_2 -> V_5 , NULL ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return - V_67 ;
F_12 ( V_2 -> V_5 ) ;
V_4 = F_5 ( V_2 , V_117 ) ;
F_1 ( V_2 ) ;
F_13 ( V_2 -> V_5 ) ;
return V_4 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return - V_67 ;
F_12 ( V_2 -> V_5 ) ;
V_4 = F_8 ( V_2 , V_118 ) ;
F_13 ( V_2 -> V_5 ) ;
return V_4 ;
}
static int F_56 ( struct V_71 * V_72 ,
T_1 * V_78 , T_2 V_119 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 = 0 ;
int V_120 ;
int V_75 ;
int V_121 = 0 ;
T_1 * V_122 = NULL ;
void * V_123 = NULL ;
int V_124 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
return - V_67 ;
}
V_122 = V_78 ;
if ( ( unsigned long ) V_78 & ( V_43 - 1 ) ) {
V_124 = F_18 ( V_119 , V_43 ) ;
V_123 = F_19 ( V_124 , V_44 ) ;
if ( ! V_123 )
return - V_45 ;
V_122 = ( T_1 * ) F_20 ( V_123 , V_43 ) ;
memcpy ( V_122 , V_78 , V_119 ) ;
}
V_75 = V_41 ;
V_120 = F_26 ( V_119 , V_75 ) ;
F_12 ( V_2 -> V_5 ) ;
do {
V_4 = F_21 ( V_2 -> V_5 , V_2 -> V_50 , V_122 ,
V_120 * V_75 ) ;
if ( V_4 < 0 ) {
V_121 ++ ;
F_7 ( L_50 , V_121 , V_4 ) ;
F_7 ( L_36 , V_119 , V_78 ) ;
V_4 = - V_12 ;
if ( V_121 > V_68 )
goto exit;
}
} while ( V_4 );
V_72 -> V_81 . V_99 = false ;
exit:
F_13 ( V_2 -> V_5 ) ;
F_22 ( V_123 ) ;
return V_4 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_9 ;
int V_24 = V_20 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
return - V_67 ;
}
if ( ! F_11 ( V_2 , 1 ) ) {
F_17 ( L_51 ) ;
return 0 ;
}
F_12 ( V_2 -> V_5 ) ;
V_9 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_11 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_52 ) ;
V_4 = - V_12 ;
goto V_38;
}
if ( V_9 ) {
F_17 ( L_53 , V_9 ) ;
V_24 *= 10 ;
} else {
if ( V_2 -> V_29 ) {
V_4 = F_15 ( V_2 ) ;
if ( V_4 ) {
F_7 ( L_54 ) ;
V_4 = - V_12 ;
goto V_38;
}
}
if ( F_24 ( V_2 ) ) {
F_7 ( L_55 ) ;
V_4 = - V_12 ;
goto V_38;
}
}
F_13 ( V_2 -> V_5 ) ;
if ( F_11 ( V_2 , V_24 ) ) {
F_7 ( L_56 ) ;
return - V_23 ;
}
return 0 ;
V_38:
F_13 ( V_2 -> V_5 ) ;
return V_4 ;
}
static int F_58 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 = 0 ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_7 ( L_29 ) ;
return - V_67 ;
}
F_12 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_5 , V_125 , V_2 -> V_3 -> V_70 , & V_4 ) ;
F_13 ( V_2 -> V_5 ) ;
F_17 ( L_57 ) ;
return V_4 ;
}
static void F_59 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 = 0 ;
unsigned int V_3 , V_126 , V_127 ;
char V_122 [ 256 ] , * V_128 ;
T_1 V_129 , V_5 , V_39 ;
int V_130 = 2 ;
F_58 ( V_72 ) ;
F_12 ( V_2 -> V_5 ) ;
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ ) {
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
V_128 = V_122 ;
if ( V_129 == 0 ) {
V_5 = V_129 ;
V_126 = 0 ;
V_127 = 9 ;
} else {
V_5 = 2 ;
V_126 = 0 ;
V_127 = 0x09 ;
}
V_128 += sprintf ( V_128 , L_58 ,
V_5 , V_126 , V_127 ) ;
for ( V_3 = V_126 ; V_3 <= V_127 ; V_3 ++ ) {
if ( V_5 == 0 )
V_39 = F_60 ( V_2 -> V_5 , V_3 , & V_4 ) ;
else
V_39 = F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
if ( ! V_4 ) {
V_128 += sprintf ( V_128 , L_59 , V_39 ) ;
} else {
V_128 += sprintf ( V_128 , L_60 ) ;
break;
}
}
F_27 ( L_61 , V_122 ) ;
}
F_13 ( V_2 -> V_5 ) ;
}
static enum
V_131 F_61 ( struct V_71 * V_72 ,
T_1 V_132 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 , V_18 ;
T_1 V_133 = 0 ;
F_6 ( V_2 -> V_5 , V_134 , V_2 -> V_3 -> V_135 ,
& V_4 ) ;
if ( V_4 ) {
F_7 ( L_62 ) ;
return V_136 ;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_133 = F_2 ( V_2 -> V_5 , V_2 -> V_3 -> V_135 ,
& V_4 ) ;
if ( V_4 ) {
F_7 ( L_63 ) ;
return V_136 ;
}
if ( V_133 == V_137 )
break;
if ( V_132 && V_133 == V_132 )
return V_138 ;
if ( V_133 != V_134 ) {
F_27 ( L_64 ) ;
F_6 ( V_2 -> V_5 , V_134 ,
V_2 -> V_3 -> V_135 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_62 ) ;
return V_136 ;
}
}
F_62 ( 100 , 200 ) ;
}
if ( V_133 == V_134 ) {
F_7 ( L_65 ) ;
return V_136 ;
}
return V_139 ;
}
static void F_63 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_81 . V_2 ;
int V_4 = 0 ;
unsigned int V_3 , V_126 , V_127 ;
enum V_131 V_89 ;
T_1 * V_140 , * V_141 , * V_142 , * V_143 ;
T_1 V_144 , V_145 , V_121 , V_146 , V_132 = 0 ;
T_3 V_147 , V_148 = 0 ;
F_59 ( V_72 ) ;
if ( ! V_2 -> V_149 ) {
F_7 ( L_66 ) ;
return;
}
for ( V_145 = 0 ; V_145 < F_64 ( V_150 ) ; V_145 ++ ) {
struct V_151 * V_152 = & V_150 [ V_145 ] ;
if ( V_152 -> V_153 ) {
F_65 ( V_152 -> V_153 ) ;
V_152 -> V_153 = NULL ;
}
V_152 -> V_154 = 0 ;
}
F_58 ( V_72 ) ;
F_12 ( V_2 -> V_5 ) ;
F_27 ( L_67 ) ;
V_89 = F_61 ( V_72 , V_132 ) ;
if ( V_89 == V_136 )
goto V_38;
V_3 = V_2 -> V_3 -> V_155 ;
V_144 = F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_68 ) ;
goto V_38;
}
for ( V_145 = 0 ; V_145 < V_144 ; V_145 ++ ) {
struct V_151 * V_152 = & V_150 [ V_145 ] ;
V_89 = F_61 ( V_72 , V_132 ) ;
if ( V_89 == V_136 )
goto V_38;
V_147 = 0 ;
V_3 = V_2 -> V_3 -> V_155 ;
for ( V_121 = 0 ; V_121 < 4 ; V_121 ++ ) {
V_146 = F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_63 ) ;
goto V_38;
}
V_147 |= ( V_146 << V_121 * 8 ) ;
V_3 ++ ;
}
if ( V_147 == 0 ) {
F_27 ( L_69 ) ;
break;
}
F_27 ( L_70 , V_152 -> V_156 , V_147 ) ;
V_152 -> V_153 = F_66 ( V_147 + 1 ) ;
V_152 -> V_154 = V_147 ;
if ( ! V_152 -> V_153 ) {
F_7 ( L_71 , V_152 -> V_156 ) ;
goto V_38;
}
V_148 += ( strlen ( L_72 ) +
strlen ( V_152 -> V_156 ) +
strlen ( L_73 ) +
( V_147 + 1 ) +
strlen ( L_74 ) ) ;
V_140 = V_152 -> V_153 ;
V_141 = V_140 + V_147 ;
V_132 = V_152 -> V_157 ;
F_27 ( L_75 ,
V_152 -> V_156 ) ;
do {
V_89 = F_61 ( V_72 , V_132 ) ;
if ( V_89 == V_136 )
goto V_38;
V_126 = V_2 -> V_3 -> V_155 ;
V_127 = V_2 -> V_3 -> V_158 ;
for ( V_3 = V_126 ; V_3 <= V_127 ; V_3 ++ ) {
* V_140 = F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
if ( V_4 ) {
F_7 ( L_63 ) ;
goto V_38;
}
if ( V_140 < V_141 )
V_140 ++ ;
else
F_7 ( L_76 ) ;
}
if ( V_89 != V_138 ) {
continue;
} else {
F_27 ( L_77 ,
V_152 -> V_156 ,
V_140 - V_152 -> V_153 ) ;
break;
}
} while ( 1 );
}
F_27 ( L_78 ) ;
V_38:
F_13 ( V_2 -> V_5 ) ;
if ( V_148 == 0 )
return;
V_142 = F_66 ( V_148 + 1 ) ;
if ( ! V_142 ) {
F_7 ( L_79 ) ;
return;
}
V_143 = V_142 ;
F_27 ( L_80 ) ;
for ( V_145 = 0 ; V_145 < V_144 ; V_145 ++ ) {
struct V_151 * V_152 = & V_150 [ V_145 ] ;
if ( V_152 -> V_153 ) {
strcpy ( V_143 , L_72 ) ;
V_143 += strlen ( L_72 ) ;
strcpy ( V_143 , V_152 -> V_156 ) ;
V_143 += strlen ( V_152 -> V_156 ) ;
strcpy ( V_143 , L_73 ) ;
V_143 += strlen ( L_73 ) ;
memcpy ( V_143 , V_152 -> V_153 , V_152 -> V_154 ) ;
V_143 += V_152 -> V_154 ;
strcpy ( V_143 , L_74 ) ;
V_143 += strlen ( L_74 ) ;
F_65 ( V_150 [ V_145 ] . V_153 ) ;
V_150 [ V_145 ] . V_153 = NULL ;
}
}
F_67 ( & V_72 -> V_81 . V_82 -> V_36 , V_142 ,
V_148 , V_44 ) ;
F_27 ( L_81 ) ;
}
static int F_68 ( struct V_105 * V_5 ,
const struct V_159 * V_160 )
{
int V_4 = 0 ;
struct V_71 * V_72 = NULL ;
struct V_1 * V_2 = NULL ;
F_27 ( L_82 ,
V_160 -> V_161 , V_160 -> V_162 , V_160 -> V_163 , V_5 -> V_114 ) ;
V_2 = F_69 ( & V_5 -> V_36 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_5 = V_5 ;
if ( V_160 -> V_164 ) {
struct V_165 * V_39 = ( void * ) V_160 -> V_164 ;
V_2 -> V_29 = V_39 -> V_29 ;
V_2 -> V_27 = V_39 -> V_27 ;
V_2 -> V_3 = V_39 -> V_3 ;
V_2 -> V_61 = V_39 -> V_61 ;
V_2 -> V_166 = V_39 -> V_166 ;
V_2 -> V_149 = V_39 -> V_149 ;
}
if ( F_46 ( V_2 ) < 0 ) {
F_7 ( L_83 ) ;
return - V_167 ;
}
F_55 ( V_2 ) ;
if ( F_57 ( V_2 ) ) {
F_7 ( L_84 ) ;
V_4 = - V_167 ;
goto V_168;
}
F_54 ( V_2 ) ;
V_72 = F_70 ( V_2 ) ;
if ( ! V_72 ) {
F_7 ( L_85 ) ;
V_4 = - V_167 ;
goto V_169;
}
V_2 -> V_72 = V_72 ;
V_72 -> V_170 = F_56 ;
V_72 -> V_171 = F_58 ;
V_72 -> V_172 = F_38 ;
V_72 -> V_173 = F_63 ;
if ( F_71 ( V_72 ) ) {
F_7 ( L_86 ) ;
V_4 = - V_167 ;
goto V_169;
}
return 0 ;
V_169:
F_55 ( V_2 ) ;
V_168:
F_53 ( V_2 ) ;
return V_4 ;
}
static void F_72 ( struct V_105 * V_5 )
{
struct V_1 * V_2 ;
if ( V_5 ) {
V_2 = F_44 ( V_5 ) ;
if ( V_2 ) {
if ( V_174 ) {
F_73 ( V_2 -> V_72 ,
V_175 ) ;
F_55 ( V_2 ) ;
}
F_17 ( L_87 ) ;
V_2 -> V_72 -> V_106 = true ;
F_53 ( V_2 ) ;
F_74 ( V_2 -> V_72 ) ;
}
}
}
static int F_75 ( struct V_162 * V_36 )
{
struct V_105 * V_5 = F_76 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
T_5 V_176 ;
struct V_79 * V_82 ;
if ( V_5 ) {
V_176 = F_77 ( V_5 ) ;
F_17 ( L_88 , F_78 ( V_5 ) ,
V_176 ) ;
if ( ! ( V_176 & V_177 ) ) {
F_7 ( L_89 ,
F_78 ( V_5 ) ) ;
return - V_178 ;
}
V_2 = F_44 ( V_5 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_7 ( L_90 ) ;
return 0 ;
}
} else {
F_7 ( L_91 ) ;
return 0 ;
}
V_72 = V_2 -> V_72 ;
V_82 = V_72 -> V_81 . V_82 ;
F_17 ( L_92 , V_82 -> V_179 ) ;
F_79 ( V_82 ) ;
F_80 ( & V_72 -> V_102 -> V_180 ) ;
if ( V_72 -> V_102 -> V_181 != V_182 ) {
if ( F_81 ( V_72 ) ) {
F_7 ( L_93 ) ;
return - V_183 ;
}
}
V_72 -> V_102 -> V_184 = true ;
if ( V_72 -> V_102 -> V_181 == V_182 ) {
F_17 ( L_94 ) ;
return F_82 ( V_5 , V_177 ) ;
} else {
F_17 ( L_95 ) ;
return 0 ;
}
}
static int F_83 ( struct V_162 * V_36 )
{
struct V_105 * V_5 = F_76 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
T_5 V_176 ;
struct V_79 * V_82 ;
if ( V_5 ) {
V_176 = F_77 ( V_5 ) ;
F_17 ( L_96 , F_78 ( V_5 ) ,
V_176 ) ;
V_2 = F_44 ( V_5 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_7 ( L_90 ) ;
return 0 ;
}
} else {
F_7 ( L_91 ) ;
return 0 ;
}
V_72 = V_2 -> V_72 ;
if ( ! V_72 -> V_102 -> V_184 ) {
F_17 ( L_97 ) ;
return 0 ;
}
V_72 -> V_171 ( V_72 ) ;
V_72 -> V_102 -> V_181 = V_185 ;
V_82 = V_72 -> V_81 . V_82 ;
F_17 ( L_98 , V_82 -> V_179 ) ;
V_72 -> V_102 -> V_184 = false ;
F_17 ( L_99 , V_82 -> V_179 ) ;
F_84 ( V_82 ) ;
return 0 ;
}
static int T_6 F_85 ( void )
{
if ( F_86 ( & V_186 ) != 0 ) {
F_7 ( L_100 ) ;
return - V_167 ;
}
V_174 = 0 ;
return 0 ;
}
static void T_7 F_87 ( void )
{
V_174 = 1 ;
F_88 ( & V_186 ) ;
}
