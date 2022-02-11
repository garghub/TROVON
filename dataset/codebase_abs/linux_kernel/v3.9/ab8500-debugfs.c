static T_1 F_1 ( int V_1 , void * V_2 )
{
char V_3 [ 16 ] ;
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
unsigned int V_6 = V_1 - V_7 ;
if ( V_6 < V_8 )
V_9 [ V_6 ] ++ ;
sprintf ( V_3 , L_1 , V_1 ) ;
F_2 ( V_5 , NULL , V_3 ) ;
return V_10 ;
}
static int F_3 ( struct V_11 * V_12 , T_2 V_13 ,
struct V_14 * V_15 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 [ V_13 ] . V_18 ; V_16 ++ ) {
T_2 V_19 ;
for ( V_19 = V_17 [ V_13 ] . V_20 [ V_16 ] . V_21 ;
V_19 <= V_17 [ V_13 ] . V_20 [ V_16 ] . V_22 ;
V_19 ++ ) {
T_3 V_23 ;
int V_24 ;
V_24 = F_4 ( V_12 ,
( T_3 ) V_13 , ( T_3 ) V_19 , & V_23 ) ;
if ( V_24 < 0 ) {
F_5 ( V_12 , L_2 , V_24 ) ;
return V_24 ;
}
if ( V_15 ) {
V_24 = F_6 ( V_15 , L_3 ,
V_13 , V_19 , V_23 ) ;
if ( V_24 < 0 ) {
F_5 ( V_12 ,
L_4 ,
V_13 , V_19 ) ;
return 0 ;
}
} else {
F_7 ( V_25 L_5 , V_13 ,
V_19 , V_23 ) ;
}
}
}
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , void * V_26 )
{
struct V_11 * V_12 = V_15 -> V_27 ;
T_2 V_13 = V_28 ;
F_6 ( V_15 , V_29 L_6 ) ;
F_6 ( V_15 , L_7 , V_13 ) ;
F_3 ( V_12 , V_13 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_8 , V_30 -> V_32 ) ;
}
static int F_11 ( struct V_14 * V_15 , void * V_26 )
{
struct V_11 * V_12 = V_15 -> V_27 ;
unsigned int V_16 ;
int V_24 ;
F_6 ( V_15 , V_29 L_6 ) ;
for ( V_16 = 1 ; V_16 < V_33 ; V_16 ++ ) {
V_24 = F_6 ( V_15 , L_7 , V_16 ) ;
if ( V_24 < 0 )
F_5 ( V_12 , L_8 , V_16 ) ;
F_3 ( V_12 , V_16 , V_15 ) ;
}
return 0 ;
}
void F_12 ( struct V_11 * V_12 )
{
unsigned int V_16 ;
F_7 ( V_25 L_9 ) ;
for ( V_16 = 1 ; V_16 < V_33 ; V_16 ++ ) {
F_7 ( V_25 L_7 , V_16 ) ;
F_3 ( V_12 , V_16 , NULL ) ;
}
}
static int F_13 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
struct V_14 * V_15 ;
int V_24 ;
V_24 = F_10 ( V_31 , F_11 , V_30 -> V_32 ) ;
if ( ! V_24 ) {
V_15 = (struct V_14 * ) V_31 -> V_34 ;
V_15 -> V_35 = ( V_36 * 2 ) ;
V_15 -> V_3 = F_14 ( V_15 -> V_35 , V_37 ) ;
if ( ! V_15 -> V_3 ) {
F_15 ( V_30 , V_31 ) ;
V_24 = - V_38 ;
}
}
return V_24 ;
}
static int F_16 ( struct V_14 * V_15 , void * V_26 )
{
return F_6 ( V_15 , L_10 , V_28 ) ;
}
static int F_17 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_16 , V_30 -> V_32 ) ;
}
static T_4 F_18 ( struct V_31 * V_31 ,
const char T_5 * V_39 ,
T_6 V_40 , T_7 * V_41 )
{
struct V_11 * V_12 = ( (struct V_14 * ) ( V_31 -> V_34 ) ) -> V_27 ;
unsigned long V_42 ;
int V_24 ;
V_24 = F_19 ( V_39 , V_40 , 0 , & V_42 ) ;
if ( V_24 )
return V_24 ;
if ( V_42 >= V_33 ) {
F_5 ( V_12 , L_11 ) ;
return - V_43 ;
}
V_28 = V_42 ;
return V_40 ;
}
static int F_20 ( struct V_14 * V_15 , void * V_26 )
{
return F_6 ( V_15 , L_12 , V_44 ) ;
}
static int F_21 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_20 , V_30 -> V_32 ) ;
}
static T_4 F_22 ( struct V_31 * V_31 ,
const char T_5 * V_39 ,
T_6 V_40 , T_7 * V_41 )
{
struct V_11 * V_12 = ( (struct V_14 * ) ( V_31 -> V_34 ) ) -> V_27 ;
unsigned long V_45 ;
int V_24 ;
V_24 = F_19 ( V_39 , V_40 , 0 , & V_45 ) ;
if ( V_24 )
return V_24 ;
if ( V_45 > 0xff ) {
F_5 ( V_12 , L_13 ) ;
return - V_43 ;
}
V_44 = V_45 ;
return V_40 ;
}
static int F_23 ( struct V_14 * V_15 , void * V_26 )
{
struct V_11 * V_12 = V_15 -> V_27 ;
int V_46 ;
T_3 V_47 ;
V_46 = F_4 ( V_12 ,
( T_3 ) V_28 , ( T_3 ) V_44 , & V_47 ) ;
if ( V_46 < 0 ) {
F_5 ( V_12 , L_14 ,
V_46 , __LINE__ ) ;
return - V_43 ;
}
F_6 ( V_15 , L_12 , V_47 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_23 , V_30 -> V_32 ) ;
}
static T_4 F_25 ( struct V_31 * V_31 ,
const char T_5 * V_39 ,
T_6 V_40 , T_7 * V_41 )
{
struct V_11 * V_12 = ( (struct V_14 * ) ( V_31 -> V_34 ) ) -> V_27 ;
unsigned long V_48 ;
int V_24 ;
V_24 = F_19 ( V_39 , V_40 , 0 , & V_48 ) ;
if ( V_24 )
return V_24 ;
if ( V_48 > 0xff ) {
F_5 ( V_12 , L_13 ) ;
return - V_43 ;
}
V_24 = F_26 ( V_12 ,
( T_3 ) V_28 , V_44 , ( T_3 ) V_48 ) ;
if ( V_24 < 0 ) {
F_7 ( V_49 L_15 , V_24 , __LINE__ ) ;
return - V_43 ;
}
return V_40 ;
}
void F_27 ( int line )
{
if ( line < V_50 )
V_51 [ line ] ++ ;
}
static int F_28 ( struct V_14 * V_15 , void * V_26 )
{
int line ;
F_6 ( V_15 , L_16 ) ;
for ( line = 0 ; line < V_50 ; line ++ )
F_6 ( V_15 , L_17 , line , V_51 [ line ] ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_28 , V_30 -> V_32 ) ;
}
static int F_30 ( struct V_14 * V_15 , void * V_52 )
{
struct V_11 * V_12 = V_15 -> V_27 ;
int V_46 ;
T_3 V_47 ;
V_46 = F_4 ( V_12 ,
( T_3 ) V_53 . V_13 , ( T_3 ) V_53 . V_54 , & V_47 ) ;
if ( V_46 < 0 ) {
F_5 ( V_12 , L_14 ,
V_46 , __LINE__ ) ;
return - V_43 ;
}
if ( V_53 . V_55 >= 0 )
V_47 >>= V_53 . V_55 ;
else
V_47 <<= - V_53 . V_55 ;
V_47 &= V_53 . V_56 ;
if ( F_31 ( & V_53 ) )
F_6 ( V_15 , L_10 , V_47 ) ;
else
F_6 ( V_15 , L_12 , V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_30 , V_30 -> V_32 ) ;
}
static int F_33 ( struct V_14 * V_15 , void * V_26 )
{
int V_57 ;
int V_58 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_57 = F_35 ( V_60 , V_61 ) ;
V_58 = F_36 ( V_60 ,
V_61 , V_57 ) ;
return F_6 ( V_15 , L_19 ,
V_58 , V_57 ) ;
}
static int F_37 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_33 , V_30 -> V_32 ) ;
}
static int F_38 ( struct V_14 * V_15 , void * V_26 )
{
int V_62 ;
int V_63 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_62 = F_35 ( V_60 , V_64 ) ;
V_63 = F_36 ( V_60 , V_64 ,
V_62 ) ;
return F_6 ( V_15 ,
L_19 , V_63 , V_62 ) ;
}
static int F_39 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_38 , V_30 -> V_32 ) ;
}
static int F_40 ( struct V_14 * V_15 , void * V_26 )
{
int V_65 ;
int V_66 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_65 = F_35 ( V_60 , V_67 ) ;
V_66 = F_36 ( V_60 ,
V_67 , V_65 ) ;
return F_6 ( V_15 , L_19 ,
V_66 , V_65 ) ;
}
static int F_41 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_40 ,
V_30 -> V_32 ) ;
}
static int F_42 ( struct V_14 * V_15 , void * V_26 )
{
int V_68 ;
int V_69 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_68 = F_35 ( V_60 , V_70 ) ;
V_69 = F_36 ( V_60 , V_70 ,
V_68 ) ;
return F_6 ( V_15 , L_19 ,
V_69 , V_68 ) ;
}
static int F_43 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_42 ,
V_30 -> V_32 ) ;
}
static int F_44 ( struct V_14 * V_15 , void * V_26 )
{
int V_71 ;
int V_72 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_71 = F_35 ( V_60 , V_73 ) ;
V_72 = F_36 ( V_60 ,
V_73 , V_71 ) ;
return F_6 ( V_15 , L_19 ,
V_72 , V_71 ) ;
}
static int F_45 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_44 ,
V_30 -> V_32 ) ;
}
static int F_46 ( struct V_14 * V_15 , void * V_26 )
{
int V_74 ;
int V_75 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_74 = F_35 ( V_60 , V_76 ) ;
V_75 = F_36 ( V_60 , V_76 ,
V_74 ) ;
return F_6 ( V_15 , L_19 ,
V_75 , V_74 ) ;
}
static int F_47 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_46 , V_30 -> V_32 ) ;
}
static int F_48 ( struct V_14 * V_15 , void * V_26 )
{
int V_77 ;
int V_78 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_77 = F_35 ( V_60 , V_79 ) ;
V_78 = F_36 ( V_60 , V_79 ,
V_77 ) ;
return F_6 ( V_15 , L_19 ,
V_78 , V_77 ) ;
}
static int F_49 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_48 , V_30 -> V_32 ) ;
}
static int F_50 ( struct V_14 * V_15 , void * V_26 )
{
int V_80 ;
int V_81 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_80 = F_35 ( V_60 , V_82 ) ;
V_81 = F_36 ( V_60 , V_82 ,
V_80 ) ;
return F_6 ( V_15 , L_19 ,
V_81 , V_80 ) ;
}
static int F_51 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_50 , V_30 -> V_32 ) ;
}
static int F_52 ( struct V_14 * V_15 , void * V_26 )
{
int V_83 ;
int V_84 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_83 = F_35 ( V_60 , V_85 ) ;
V_84 = F_36 ( V_60 , V_85 ,
V_83 ) ;
return F_6 ( V_15 , L_19 ,
V_84 , V_83 ) ;
}
static int F_53 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_52 , V_30 -> V_32 ) ;
}
static int F_54 ( struct V_14 * V_15 , void * V_26 )
{
int V_86 ;
int V_87 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_86 = F_35 ( V_60 , V_88 ) ;
V_87 = F_36 ( V_60 ,
V_88 , V_86 ) ;
return F_6 ( V_15 , L_19 ,
V_87 , V_86 ) ;
}
static int F_55 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_54 ,
V_30 -> V_32 ) ;
}
static int F_56 ( struct V_14 * V_15 , void * V_26 )
{
int V_89 ;
int V_90 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_89 = F_35 ( V_60 , V_91 ) ;
V_90 = F_36 ( V_60 ,
V_91 , V_89 ) ;
return F_6 ( V_15 , L_19 ,
V_90 , V_89 ) ;
}
static int F_57 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_56 ,
V_30 -> V_32 ) ;
}
static int F_58 ( struct V_14 * V_15 , void * V_26 )
{
int V_92 ;
int V_93 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_92 = F_35 ( V_60 , V_94 ) ;
V_93 = F_36 ( V_60 ,
V_94 , V_92 ) ;
return F_6 ( V_15 , L_19 ,
V_93 , V_92 ) ;
}
static int F_59 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_58 , V_30 -> V_32 ) ;
}
static int F_60 ( struct V_14 * V_15 , void * V_26 )
{
int V_95 ;
int V_96 ;
struct V_59 * V_60 ;
V_60 = F_34 ( L_18 ) ;
V_95 = F_35 ( V_60 , V_97 ) ;
V_96 = F_36 ( V_60 , V_97 ,
V_95 ) ;
return F_6 ( V_15 , L_19 ,
V_96 , V_95 ) ;
}
static int F_61 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_10 ( V_31 , F_60 , V_30 -> V_32 ) ;
}
static int F_62 ( char * V_98 )
{
char * V_15 = V_98 ;
if ( ( * V_15 == '0' ) && ( ( * ( V_15 + 1 ) == 'x' ) || ( * ( V_15 + 1 ) == 'X' ) ) ) {
V_15 += 2 ;
for (; * V_15 && ( * V_15 != ' ' ) && ( * V_15 != '\n' ) ; V_15 ++ ) {
if ( ! isxdigit ( * V_15 ) )
return 0 ;
}
} else {
if ( * V_15 == '-' )
V_15 ++ ;
for (; * V_15 && ( * V_15 != ' ' ) && ( * V_15 != '\n' ) ; V_15 ++ ) {
if ( ! isdigit ( * V_15 ) )
return 0 ;
}
}
return ( int ) ( V_15 - V_98 ) ;
}
static T_4 F_63 ( char * V_98 , struct V_53 * V_99 ,
struct V_11 * V_12 )
{
T_8 V_100 , V_101 = 0 ;
T_3 V_47 ;
int V_46 ;
struct V_53 V_102 = {
. V_13 = 0 ,
. V_54 = 0 ,
. V_103 = 0 ,
. V_56 = 0xFFFFFFFF ,
. V_55 = 0 ,
} ;
if ( ! strncmp ( V_98 , L_20 , 5 ) ) {
V_100 = 0 ;
V_98 += 5 ;
} else if ( ! strncmp ( V_98 , L_21 , 6 ) ) {
V_100 = 1 ;
V_98 += 6 ;
} else
return - V_43 ;
while ( ( * V_98 == ' ' ) || ( * V_98 == '-' ) ) {
if ( * ( V_98 - 1 ) != ' ' ) {
V_98 ++ ;
continue;
}
if ( ( ! strncmp ( V_98 , L_22 , 3 ) ) ||
( ! strncmp ( V_98 , L_23 , 5 ) ) ) {
V_98 += ( * ( V_98 + 2 ) == ' ' ) ? 3 : 5 ;
V_102 . V_103 |= ( 1 << 0 ) ;
} else if ( ( ! strncmp ( V_98 , L_24 , 3 ) ) ||
( ! strncmp ( V_98 , L_25 , 5 ) ) ) {
V_98 += ( * ( V_98 + 2 ) == ' ' ) ? 3 : 5 ;
V_102 . V_103 &= ~ ( 1 << 0 ) ;
} else if ( ( ! strncmp ( V_98 , L_26 , 3 ) ) ||
( ! strncmp ( V_98 , L_27 , 6 ) ) ) {
V_98 += ( * ( V_98 + 2 ) == ' ' ) ? 3 : 6 ;
if ( F_62 ( V_98 ) == 0 )
return - V_43 ;
V_102 . V_56 = F_64 ( V_98 , & V_98 , 0 ) ;
} else if ( ( ! strncmp ( V_98 , L_28 , 3 ) ) ||
( ! strncmp ( V_98 , L_29 , 7 ) ) ) {
V_98 += ( * ( V_98 + 2 ) == ' ' ) ? 3 : 7 ;
if ( F_62 ( V_98 ) == 0 )
return - V_43 ;
V_102 . V_55 = F_65 ( V_98 , & V_98 , 0 ) ;
} else {
return - V_43 ;
}
}
if ( F_62 ( V_98 ) == 0 )
return - V_43 ;
V_102 . V_13 = F_64 ( V_98 , & V_98 , 0 ) ;
while ( * V_98 == ' ' )
V_98 ++ ;
if ( F_62 ( V_98 ) == 0 )
return - V_43 ;
V_102 . V_54 = F_64 ( V_98 , & V_98 , 0 ) ;
if ( V_100 ) {
while ( * V_98 == ' ' )
V_98 ++ ;
if ( F_62 ( V_98 ) == 0 )
return - V_43 ;
V_101 = F_64 ( V_98 , & V_98 , 0 ) ;
}
* V_99 = V_102 ;
#ifdef F_66
F_67 ( L_30
L_31 , ( V_100 ) ? L_32 : L_33 ,
F_31 ( V_99 ) ? L_34 : L_35 ,
V_99 -> V_54 , V_99 -> V_56 , V_99 -> V_55 , V_101 ) ;
#endif
if ( ! V_100 )
return 0 ;
V_46 = F_4 ( V_12 ,
( T_3 ) V_99 -> V_13 , ( T_3 ) V_99 -> V_54 , & V_47 ) ;
if ( V_46 < 0 ) {
F_5 ( V_12 , L_14 ,
V_46 , __LINE__ ) ;
return - V_43 ;
}
if ( V_99 -> V_55 >= 0 ) {
V_47 &= ~ ( V_99 -> V_56 << ( V_99 -> V_55 ) ) ;
V_101 = ( V_101 & V_99 -> V_56 ) << ( V_99 -> V_55 ) ;
} else {
V_47 &= ~ ( V_99 -> V_56 >> ( - V_99 -> V_55 ) ) ;
V_101 = ( V_101 & V_99 -> V_56 ) >> ( - V_99 -> V_55 ) ;
}
V_101 = V_101 | V_47 ;
V_46 = F_26 ( V_12 ,
( T_3 ) V_99 -> V_13 , ( T_3 ) V_99 -> V_54 , ( T_3 ) V_101 ) ;
if ( V_46 < 0 ) {
F_68 ( L_15 , V_46 , __LINE__ ) ;
return - V_43 ;
}
return 0 ;
}
static T_4 F_69 ( struct V_31 * V_31 ,
const char T_5 * V_39 , T_6 V_40 , T_7 * V_41 )
{
struct V_11 * V_12 = ( (struct V_14 * ) ( V_31 -> V_34 ) ) -> V_27 ;
char V_3 [ 128 ] ;
int V_104 , V_46 ;
V_104 = F_70 ( V_40 , ( sizeof( V_3 ) - 1 ) ) ;
if ( F_71 ( V_3 , V_39 , V_104 ) )
return - V_105 ;
V_3 [ V_104 ] = 0 ;
V_46 = F_63 ( V_3 , & V_53 , V_12 ) ;
return ( V_46 ) ? V_46 : V_104 ;
}
static int F_72 ( struct V_14 * V_15 , void * V_26 )
{
F_6 ( V_15 , L_10 , V_7 ) ;
return 0 ;
}
static int F_73 ( struct V_30 * V_30 ,
struct V_31 * V_31 )
{
return F_10 ( V_31 , F_72 ,
V_30 -> V_32 ) ;
}
static T_4 F_74 ( struct V_11 * V_12 ,
struct V_106 * V_107 , char * V_3 )
{
unsigned long V_108 ;
unsigned int V_109 ;
int V_24 ;
V_24 = F_75 ( V_107 -> V_107 . V_108 , 0 , & V_108 ) ;
if ( V_24 )
return V_24 ;
V_109 = V_108 - V_7 ;
if ( V_109 >= V_8 )
return - V_43 ;
else
return sprintf ( V_3 , L_36 , V_9 [ V_109 ] ) ;
}
static T_4 F_76 ( struct V_31 * V_31 ,
const char T_5 * V_39 ,
T_6 V_40 , T_7 * V_41 )
{
struct V_11 * V_12 = ( (struct V_14 * ) ( V_31 -> V_34 ) ) -> V_27 ;
char V_3 [ 32 ] ;
int V_104 ;
unsigned long V_48 ;
int V_24 ;
unsigned int V_109 ;
V_104 = F_70 ( V_40 , ( sizeof( V_3 ) - 1 ) ) ;
if ( F_71 ( V_3 , V_39 , V_104 ) )
return - V_105 ;
V_3 [ V_104 ] = 0 ;
V_24 = F_75 ( V_3 , 0 , & V_48 ) ;
if ( V_24 )
return - V_43 ;
if ( V_48 < V_7 ) {
F_5 ( V_12 , L_37 , V_7 ) ;
return - V_43 ;
}
if ( V_48 > V_110 ) {
F_5 ( V_12 , L_38 , V_110 ) ;
return - V_43 ;
}
V_109 = V_48 - V_7 ;
if ( V_109 >= V_8 )
return - V_43 ;
V_111 [ V_109 ] = F_14 ( sizeof( struct V_106 ) ,
V_37 ) ;
V_112 [ V_109 ] = F_14 ( V_104 , V_37 ) ;
sprintf ( V_112 [ V_109 ] , L_39 , V_48 ) ;
V_111 [ V_109 ] -> V_113 = F_74 ;
V_111 [ V_109 ] -> V_114 = NULL ;
V_111 [ V_109 ] -> V_107 . V_108 = V_112 [ V_109 ] ;
V_111 [ V_109 ] -> V_107 . V_115 = V_116 ;
V_24 = F_77 ( & V_12 -> V_5 , & V_111 [ V_109 ] -> V_107 ) ;
if ( V_24 < 0 ) {
F_7 ( V_49 L_40 , V_24 ) ;
return V_24 ;
}
V_24 = F_78 ( V_48 , NULL , F_1 ,
V_117 | V_118 ,
L_41 , & V_12 -> V_5 ) ;
if ( V_24 < 0 ) {
F_7 ( V_49 L_42 ,
V_24 , V_48 ) ;
F_79 ( & V_12 -> V_5 , & V_111 [ V_109 ] -> V_107 ) ;
return V_24 ;
}
return V_104 ;
}
static T_4 F_80 ( struct V_31 * V_31 ,
const char T_5 * V_39 ,
T_6 V_40 , T_7 * V_41 )
{
struct V_11 * V_12 = ( (struct V_14 * ) ( V_31 -> V_34 ) ) -> V_27 ;
char V_3 [ 32 ] ;
int V_104 ;
unsigned long V_48 ;
int V_24 ;
unsigned int V_109 ;
V_104 = F_70 ( V_40 , ( sizeof( V_3 ) - 1 ) ) ;
if ( F_71 ( V_3 , V_39 , V_104 ) )
return - V_105 ;
V_3 [ V_104 ] = 0 ;
V_24 = F_75 ( V_3 , 0 , & V_48 ) ;
if ( V_24 )
return - V_43 ;
if ( V_48 < V_7 ) {
F_5 ( V_12 , L_37 , V_7 ) ;
return - V_43 ;
}
if ( V_48 > V_110 ) {
F_5 ( V_12 , L_38 , V_110 ) ;
return - V_43 ;
}
V_109 = V_48 - V_7 ;
if ( V_109 >= V_8 )
return - V_43 ;
V_9 [ V_109 ] = 0 ;
if ( V_111 [ V_109 ] )
F_79 ( & V_12 -> V_5 , & V_111 [ V_109 ] -> V_107 ) ;
F_81 ( V_48 , & V_12 -> V_5 ) ;
F_82 ( V_112 [ V_109 ] ) ;
F_82 ( V_111 [ V_109 ] ) ;
return V_104 ;
}
static int F_83 ( struct V_119 * V_120 )
{
struct V_121 * V_31 ;
int V_46 = - V_38 ;
struct V_122 * V_122 ;
V_28 = V_123 ;
V_44 = V_124 & 0x00FF ;
V_122 = F_84 ( V_120 -> V_12 . V_125 ) ;
V_8 = V_122 -> V_126 ;
V_9 = F_85 ( sizeof( * V_9 ) * V_8 , V_37 ) ;
if ( ! V_9 )
return - V_38 ;
V_111 = F_85 ( sizeof( * V_111 ) * V_8 , V_37 ) ;
if ( ! V_111 )
goto V_127;
V_112 = F_85 ( sizeof( * V_112 ) * V_8 , V_37 ) ;
if ( ! V_112 )
goto V_128;
V_7 = F_86 ( V_120 , L_43 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_120 -> V_12 , L_44 ,
V_7 ) ;
V_46 = V_7 ;
goto V_129;
}
V_110 = F_86 ( V_120 , L_45 ) ;
if ( V_110 < 0 ) {
F_5 ( & V_120 -> V_12 , L_46 ,
V_110 ) ;
V_46 = V_110 ;
goto V_129;
}
V_130 = F_87 ( V_29 , NULL ) ;
if ( ! V_130 )
goto V_24;
V_131 = F_87 ( V_132 ,
V_130 ) ;
if ( ! V_131 )
goto V_24;
V_31 = F_88 ( L_47 , V_116 ,
V_130 , & V_120 -> V_12 , & V_133 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_48 , V_116 ,
V_130 , & V_120 -> V_12 , & V_134 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_49 , ( V_116 | V_135 ) ,
V_130 , & V_120 -> V_12 , & V_136 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_50 , ( V_116 | V_135 ) ,
V_130 , & V_120 -> V_12 , & V_137 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_51 , ( V_116 | V_135 ) ,
V_130 , & V_120 -> V_12 , & V_138 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_52 , ( V_116 | V_135 ) ,
V_130 , & V_120 -> V_12 , & V_139 ) ;
if ( ! V_31 )
goto V_24;
if ( F_89 ( V_122 ) )
V_50 = V_140 ;
else if ( F_90 ( V_122 ) )
V_50 = V_141 ;
else if ( F_91 ( V_122 ) )
V_50 = V_142 ;
V_31 = F_88 ( L_53 , ( V_116 ) ,
V_130 , & V_120 -> V_12 , & V_143 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_54 , ( V_116 | V_135 ) ,
V_130 , & V_120 -> V_12 , & V_144 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_55 , ( V_116 | V_135 ) ,
V_130 , & V_120 -> V_12 , & V_145 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_56 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_146 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_57 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_147 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_58 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_148 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_59 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_149 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_60 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_150 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_61 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_151 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_62 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_152 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_63 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_153 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_64 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_154 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_65 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_155 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_66 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_156 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_67 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_157 ) ;
if ( ! V_31 )
goto V_24;
V_31 = F_88 ( L_68 , ( V_116 | V_135 ) ,
V_131 , & V_120 -> V_12 , & V_158 ) ;
if ( ! V_31 )
goto V_24;
return 0 ;
V_24:
if ( V_130 )
F_92 ( V_130 ) ;
F_5 ( & V_120 -> V_12 , L_69 ) ;
V_129:
F_82 ( V_112 ) ;
V_128:
F_82 ( V_111 ) ;
V_127:
F_82 ( V_9 ) ;
return V_46 ;
}
static int F_93 ( struct V_119 * V_120 )
{
F_92 ( V_130 ) ;
F_82 ( V_112 ) ;
F_82 ( V_111 ) ;
F_82 ( V_9 ) ;
return 0 ;
}
static int T_9 F_94 ( void )
{
return F_95 ( & V_159 ) ;
}
static void T_10 F_96 ( void )
{
F_97 ( & V_159 ) ;
}
