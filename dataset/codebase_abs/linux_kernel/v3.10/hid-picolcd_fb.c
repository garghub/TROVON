static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
int V_4 , int V_5 )
{
struct V_6 * V_7 , * V_8 ;
unsigned long V_9 ;
T_1 * V_10 ;
int V_11 ;
V_7 = F_2 ( V_12 , V_2 -> V_13 ) ;
if ( ! V_7 || V_7 -> V_14 != 1 )
return - V_15 ;
V_8 = F_2 ( V_16 , V_2 -> V_13 ) ;
if ( ! V_8 || V_8 -> V_14 != 1 )
return - V_15 ;
F_3 ( & V_2 -> V_17 , V_9 ) ;
if ( ( V_2 -> V_18 & V_19 ) ) {
F_4 ( & V_2 -> V_17 , V_9 ) ;
return - V_15 ;
}
F_5 ( V_7 -> V_20 [ 0 ] , 0 , V_4 << 2 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 1 , 0x02 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 2 , 0x00 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 3 , 0x00 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 4 , 0xb8 | V_5 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 5 , 0x00 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 6 , 0x00 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 7 , 0x40 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 8 , 0x00 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 9 , 0x00 ) ;
F_5 ( V_7 -> V_20 [ 0 ] , 10 , 32 ) ;
F_5 ( V_8 -> V_20 [ 0 ] , 0 , ( V_4 << 2 ) | 0x01 ) ;
F_5 ( V_8 -> V_20 [ 0 ] , 1 , 0x00 ) ;
F_5 ( V_8 -> V_20 [ 0 ] , 2 , 0x00 ) ;
F_5 ( V_8 -> V_20 [ 0 ] , 3 , 32 ) ;
V_10 = V_3 + ( V_5 * 4 + V_4 ) * 64 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
if ( V_11 < 32 )
F_5 ( V_7 -> V_20 [ 0 ] , 11 + V_11 , V_10 [ V_11 ] ) ;
else
F_5 ( V_8 -> V_20 [ 0 ] , 4 + V_11 - 32 , V_10 [ V_11 ] ) ;
F_6 ( V_2 -> V_13 , V_7 , V_21 ) ;
F_6 ( V_2 -> V_13 , V_8 , V_21 ) ;
F_4 ( & V_2 -> V_17 , V_9 ) ;
return 0 ;
}
static int F_7 ( T_1 * V_3 , const T_1 * V_22 , int V_23 ,
int V_4 , int V_5 )
{
int V_11 , V_24 , V_25 = 0 ;
T_1 V_10 [ 64 ] ;
T_1 * V_26 = V_3 + ( V_5 * 4 + V_4 ) * 64 ;
if ( V_23 == 1 ) {
for ( V_24 = 7 ; V_24 >= 0 ; V_24 -- ) {
const T_1 * V_27 = V_22 + V_5 * 256 + V_4 * 8 + V_24 * 32 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ ) {
V_10 [ V_11 ] <<= 1 ;
V_10 [ V_11 ] |= ( V_27 [ V_11 / 8 ] >> ( V_11 % 8 ) ) & 0x01 ;
}
}
} else if ( V_23 == 8 ) {
for ( V_24 = 7 ; V_24 >= 0 ; V_24 -- ) {
const T_1 * V_27 = V_22 + ( V_5 * 256 + V_4 * 8 + V_24 * 32 ) * 8 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ ) {
V_10 [ V_11 ] <<= 1 ;
V_10 [ V_11 ] |= ( V_27 [ V_11 ] & 0x80 ) ? 0x01 : 0x00 ;
}
}
} else {
F_8 ( 1 ) ;
return 0 ;
}
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
if ( V_10 [ V_11 ] != V_26 [ V_11 ] ) {
V_25 = 1 ;
V_26 [ V_11 ] = V_10 [ V_11 ] ;
}
return V_25 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 )
F_10 ( & V_2 -> V_28 -> V_29 , 0 ) ;
}
int F_11 ( struct V_1 * V_2 , int V_30 )
{
struct V_6 * V_31 = F_2 ( V_32 , V_2 -> V_13 ) ;
struct V_33 * V_34 = V_2 -> V_28 -> V_35 ;
int V_11 , V_36 ;
unsigned long V_9 ;
static const T_1 V_37 [ 8 ] = { 0x00 , 0x02 , 0x00 , 0x64 , 0x3f , 0x00 , 0x64 , 0xc0 } ;
if ( ! V_31 || V_31 -> V_14 != 1 )
return - V_15 ;
F_3 ( & V_2 -> V_17 , V_9 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
for ( V_36 = 0 ; V_36 < V_31 -> V_20 [ 0 ] -> V_38 ; V_36 ++ )
if ( V_36 == 0 )
F_5 ( V_31 -> V_20 [ 0 ] , V_36 , V_11 << 2 ) ;
else if ( V_36 < sizeof( V_37 ) )
F_5 ( V_31 -> V_20 [ 0 ] , V_36 , V_37 [ V_36 ] ) ;
else
F_5 ( V_31 -> V_20 [ 0 ] , V_36 , 0 ) ;
F_6 ( V_2 -> V_13 , V_31 , V_21 ) ;
}
F_4 ( & V_2 -> V_17 , V_9 ) ;
if ( V_30 ) {
memset ( V_34 -> V_3 , 0 , V_39 ) ;
memset ( V_34 -> V_22 , 0 , V_39 * V_34 -> V_23 ) ;
}
V_34 -> V_40 = 1 ;
if ( V_34 -> V_41 )
F_10 ( & V_2 -> V_28 -> V_29 , 0 ) ;
else
V_34 -> V_41 = 1 ;
return 0 ;
}
static void F_12 ( struct V_28 * V_42 )
{
int V_4 , V_5 , V_43 ;
unsigned long V_9 ;
struct V_33 * V_34 = V_42 -> V_35 ;
struct V_1 * V_2 ;
F_13 ( & V_42 -> V_17 ) ;
F_3 ( & V_34 -> V_17 , V_9 ) ;
if ( ! V_34 -> V_41 && V_34 -> V_44 )
F_11 ( V_34 -> V_44 , 0 ) ;
F_4 ( & V_34 -> V_17 , V_9 ) ;
V_43 = 0 ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ )
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( ! V_34 -> V_40 && ! F_7 (
V_34 -> V_3 , V_34 -> V_22 ,
V_34 -> V_23 , V_4 , V_5 ) )
continue;
V_43 += 2 ;
if ( V_43 >= V_45 / 2 ) {
F_3 ( & V_34 -> V_17 , V_9 ) ;
V_2 = V_34 -> V_44 ;
F_4 ( & V_34 -> V_17 , V_9 ) ;
F_14 ( & V_42 -> V_17 ) ;
if ( ! V_2 )
return;
F_15 ( V_2 -> V_13 ) ;
F_13 ( & V_42 -> V_17 ) ;
V_43 = 0 ;
}
F_3 ( & V_34 -> V_17 , V_9 ) ;
V_2 = V_34 -> V_44 ;
F_4 ( & V_34 -> V_17 , V_9 ) ;
if ( ! V_2 || F_1 ( V_2 ,
V_34 -> V_3 , V_4 , V_5 ) )
goto V_46;
}
V_34 -> V_40 = false ;
if ( V_43 ) {
F_3 ( & V_34 -> V_17 , V_9 ) ;
V_2 = V_34 -> V_44 ;
F_4 ( & V_34 -> V_17 , V_9 ) ;
F_14 ( & V_42 -> V_17 ) ;
if ( V_2 )
F_15 ( V_2 -> V_13 ) ;
return;
}
V_46:
F_14 ( & V_42 -> V_17 ) ;
}
static void F_16 ( struct V_28 * V_42 ,
const struct V_47 * V_48 )
{
if ( ! V_42 -> V_35 )
return;
F_17 ( V_42 , V_48 ) ;
F_10 ( & V_42 -> V_29 , 0 ) ;
}
static void F_18 ( struct V_28 * V_42 ,
const struct V_49 * V_50 )
{
if ( ! V_42 -> V_35 )
return;
F_19 ( V_42 , V_50 ) ;
F_10 ( & V_42 -> V_29 , 0 ) ;
}
static void F_20 ( struct V_28 * V_42 , const struct V_51 * V_52 )
{
if ( ! V_42 -> V_35 )
return;
F_21 ( V_42 , V_52 ) ;
F_10 ( & V_42 -> V_29 , 0 ) ;
}
static T_2 F_22 ( struct V_28 * V_42 , const char T_3 * V_53 ,
T_4 V_54 , T_5 * V_55 )
{
T_2 V_56 ;
if ( ! V_42 -> V_35 )
return - V_15 ;
V_56 = F_23 ( V_42 , V_53 , V_54 , V_55 ) ;
if ( V_56 >= 0 )
F_10 ( & V_42 -> V_29 , 0 ) ;
return V_56 ;
}
static int F_24 ( int V_57 , struct V_28 * V_42 )
{
return 0 ;
}
static void F_25 ( struct V_28 * V_42 )
{
struct V_33 * V_34 = V_42 -> V_35 ;
F_26 ( V_42 ) ;
F_8 ( V_34 -> V_44 != NULL ) ;
F_27 ( ( T_1 * ) V_42 -> V_58 . V_59 ) ;
F_28 ( V_42 ) ;
}
static int F_29 ( struct V_60 * V_61 , struct V_28 * V_42 )
{
T_6 V_23 = V_61 -> V_62 ;
T_6 V_63 = V_61 -> V_63 ;
* V_61 = V_64 ;
V_61 -> V_63 = V_63 ;
if ( V_23 >= 8 ) {
V_61 -> V_62 = 8 ;
V_61 -> V_65 . V_66 = 8 ;
V_61 -> V_67 . V_66 = 8 ;
V_61 -> V_68 . V_66 = 8 ;
} else {
V_61 -> V_62 = 1 ;
V_61 -> V_65 . V_66 = 1 ;
V_61 -> V_67 . V_66 = 1 ;
V_61 -> V_68 . V_66 = 1 ;
}
return 0 ;
}
static int F_30 ( struct V_28 * V_42 )
{
struct V_33 * V_34 = V_42 -> V_35 ;
T_1 * V_69 , * V_70 ;
if ( V_42 -> V_61 . V_62 == V_34 -> V_23 )
return 0 ;
if ( V_42 -> V_61 . V_62 != 1 && V_42 -> V_61 . V_62 != 8 )
return - V_71 ;
V_70 = V_34 -> V_22 ;
V_69 = F_31 ( V_39 * V_42 -> V_61 . V_62 , V_72 ) ;
if ( ! V_69 )
return - V_73 ;
if ( V_42 -> V_61 . V_62 == 1 ) {
int V_11 , V_24 ;
for ( V_11 = 0 ; V_11 < V_39 ; V_11 ++ ) {
T_1 V_74 = 0 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
V_74 <<= 1 ;
V_74 |= V_70 [ V_11 * 8 + V_24 ] ? 0x01 : 0x00 ;
}
V_69 [ V_11 ] = V_74 ;
}
memcpy ( V_70 , V_69 , V_39 ) ;
V_42 -> V_58 . V_75 = V_76 ;
V_42 -> V_58 . V_77 = V_78 / 8 ;
} else {
int V_11 ;
memcpy ( V_69 , V_70 , V_39 ) ;
for ( V_11 = 0 ; V_11 < V_39 * 8 ; V_11 ++ )
V_70 [ V_11 ] = V_69 [ V_11 / 8 ] & ( 0x01 << ( 7 - V_11 % 8 ) ) ? 0xff : 0x00 ;
V_42 -> V_58 . V_75 = V_79 ;
V_42 -> V_58 . V_77 = V_78 ;
}
F_32 ( V_69 ) ;
V_34 -> V_23 = V_42 -> V_61 . V_62 ;
return 0 ;
}
static void F_33 ( struct V_28 * V_42 , struct V_80 * V_81 )
{
F_12 ( V_42 ) ;
}
static T_2 F_34 ( struct V_82 * V_83 ,
struct V_84 * V_85 , char * V_53 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
struct V_33 * V_34 = V_2 -> V_28 -> V_35 ;
unsigned V_11 , V_86 = V_34 -> V_87 ;
T_4 V_56 = 0 ;
for ( V_11 = 1 ; V_11 <= V_88 ; V_11 ++ )
if ( V_56 >= V_89 )
break;
else if ( V_11 == V_86 )
V_56 += snprintf ( V_53 + V_56 , V_89 - V_56 , L_1 , V_11 ) ;
else
V_56 += snprintf ( V_53 + V_56 , V_89 - V_56 , L_2 , V_11 ) ;
if ( V_56 > 0 )
V_53 [ F_36 ( V_56 , ( T_4 ) V_89 ) - 1 ] = '\n' ;
return V_56 ;
}
static T_2 F_37 ( struct V_82 * V_83 ,
struct V_84 * V_85 , const char * V_53 , T_4 V_54 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
struct V_33 * V_34 = V_2 -> V_28 -> V_35 ;
int V_11 ;
unsigned V_90 ;
if ( V_54 < 1 || V_54 > 10 )
return - V_71 ;
V_11 = sscanf ( V_53 , L_3 , & V_90 ) ;
if ( V_11 != 1 )
return - V_71 ;
if ( V_90 > V_88 )
return - V_91 ;
else if ( V_90 == 0 )
V_90 = V_92 ;
V_34 -> V_87 = V_90 ;
V_2 -> V_28 -> V_93 -> V_94 = V_95 / V_34 -> V_87 ;
return V_54 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = & V_2 -> V_13 -> V_83 ;
struct V_28 * V_42 = NULL ;
struct V_33 * V_34 = NULL ;
int V_11 , error = - V_73 ;
T_7 * V_96 ;
V_42 = F_39 ( 256 * sizeof( T_7 ) +
sizeof( struct V_97 ) +
sizeof( struct V_33 ) +
V_39 , V_83 ) ;
if ( V_42 == NULL ) {
F_40 ( V_83 , L_4 ) ;
goto V_98;
}
V_42 -> V_93 = V_42 -> V_35 ;
* V_42 -> V_93 = V_99 ;
V_42 -> V_35 += sizeof( struct V_97 ) ;
V_96 = V_42 -> V_35 ;
V_42 -> V_35 += 256 * sizeof( T_7 ) ;
for ( V_11 = 0 ; V_11 < 256 ; V_11 ++ )
V_96 [ V_11 ] = V_11 > 0 && V_11 < 16 ? 0xff : 0 ;
V_42 -> V_100 = V_96 ;
V_42 -> V_101 = & V_102 ;
V_42 -> V_61 = V_64 ;
V_42 -> V_58 = V_103 ;
V_42 -> V_58 . V_104 = V_39 * 8 ;
V_42 -> V_9 = V_105 ;
V_34 = V_42 -> V_35 ;
F_41 ( & V_34 -> V_17 ) ;
V_34 -> V_44 = V_2 ;
V_34 -> V_87 = V_92 ;
V_34 -> V_23 = V_64 . V_62 ;
V_34 -> V_40 = 1 ;
V_34 -> V_3 = V_42 -> V_35 + sizeof( struct V_33 ) ;
V_34 -> V_22 = F_42 ( V_39 * 8 ) ;
if ( V_34 -> V_22 == NULL ) {
F_40 ( V_83 , L_5 ) ;
goto V_98;
}
V_42 -> V_106 = ( char V_107 V_108 * ) V_34 -> V_22 ;
V_42 -> V_58 . V_59 = ( unsigned long ) V_34 -> V_22 ;
memset ( V_34 -> V_3 , 0xff , V_39 ) ;
V_2 -> V_28 = V_42 ;
error = F_11 ( V_2 , 1 ) ;
if ( error ) {
F_40 ( V_83 , L_6 ) ;
goto V_109;
}
error = F_43 ( V_83 , & V_110 ) ;
if ( error ) {
F_40 ( V_83 , L_7 ) ;
goto V_109;
}
F_44 ( V_42 ) ;
error = F_45 ( V_42 ) ;
if ( error ) {
F_40 ( V_83 , L_8 ) ;
goto V_111;
}
return 0 ;
V_111:
F_46 ( V_83 , & V_110 ) ;
F_26 ( V_42 ) ;
V_109:
V_2 -> V_28 = NULL ;
V_98:
if ( V_34 )
F_27 ( V_34 -> V_22 ) ;
F_28 ( V_42 ) ;
return error ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_28 * V_42 = V_2 -> V_28 ;
struct V_33 * V_34 = V_42 -> V_35 ;
unsigned long V_9 ;
F_46 ( & V_2 -> V_13 -> V_83 , & V_110 ) ;
F_3 ( & V_34 -> V_17 , V_9 ) ;
V_34 -> V_44 = NULL ;
F_4 ( & V_34 -> V_17 , V_9 ) ;
F_48 ( & V_42 -> V_29 ) ;
V_2 -> V_28 = NULL ;
F_49 ( V_42 ) ;
}
