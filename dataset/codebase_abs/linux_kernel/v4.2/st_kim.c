static struct V_1 * F_1 ( int V_2 )
{
return V_3 [ V_2 ] ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! V_7 )
return;
if ( V_7 -> V_9 [ 2 ] == 0x01 && V_7 -> V_9 [ 3 ] == 0x01 &&
V_7 -> V_9 [ 4 ] == 0x10 && V_7 -> V_9 [ 5 ] == 0x00 ) {
memcpy ( V_5 -> V_10 ,
V_5 -> V_8 -> V_9 ,
V_5 -> V_8 -> V_11 ) ;
F_3 ( & V_5 -> V_12 ) ;
V_5 -> V_13 = V_14 ;
V_5 -> V_8 = NULL ;
V_5 -> V_15 = 0 ;
} else if ( F_4 ( V_7 -> V_9 [ 5 ] != 0 ) ) {
F_5 ( L_1 ) ;
F_5 ( L_2 , V_7 -> V_9 [ 5 ] ) ;
F_6 ( V_7 ) ;
return;
}
F_3 ( & V_5 -> V_12 ) ;
F_6 ( V_7 ) ;
}
static inline int F_7 ( struct V_4 * V_5 , int V_11 )
{
register int V_16 = F_8 ( V_5 -> V_8 ) ;
F_9 ( L_3 , V_11 , V_16 ) ;
if ( ! V_11 ) {
F_2 ( V_5 ) ;
} else if ( V_11 > V_16 ) {
F_5 ( L_4 , V_11 ,
V_16 ) ;
F_6 ( V_5 -> V_8 ) ;
} else {
V_5 -> V_13 = V_17 ;
V_5 -> V_15 = V_11 ;
return V_11 ;
}
V_5 -> V_13 = V_14 ;
V_5 -> V_8 = NULL ;
V_5 -> V_15 = 0 ;
return 0 ;
}
static void F_10 ( struct V_4 * V_5 ,
const unsigned char * V_9 , long V_18 )
{
const unsigned char * V_19 ;
int V_11 = 0 , type = 0 ;
unsigned char * V_20 ;
F_9 ( L_5 , V_21 ) ;
V_19 = V_9 ;
if ( F_4 ( V_19 == NULL ) ) {
F_5 ( L_6 ) ;
return;
}
while ( V_18 ) {
if ( V_5 -> V_15 ) {
V_11 = F_11 (unsigned int, kim_gdata->rx_count, count) ;
memcpy ( F_12 ( V_5 -> V_8 , V_11 ) , V_19 , V_11 ) ;
V_5 -> V_15 -= V_11 ;
V_18 -= V_11 ;
V_19 += V_11 ;
if ( V_5 -> V_15 )
continue;
switch ( V_5 -> V_13 ) {
case V_17 :
F_9 ( L_7 ) ;
F_2 ( V_5 ) ;
V_5 -> V_13 = V_14 ;
V_5 -> V_8 = NULL ;
continue;
case V_22 :
V_20 =
( unsigned char * ) & V_5 -> V_8 -> V_9 [ 1 ] ;
F_9 ( L_8 , * V_20 ) ;
F_7 ( V_5 , * V_20 ) ;
continue;
}
}
switch ( * V_19 ) {
case 0x04 :
V_5 -> V_13 = V_22 ;
V_5 -> V_15 = 2 ;
type = * V_19 ;
break;
default:
F_13 ( L_9 ) ;
V_19 ++ ;
V_18 -- ;
continue;
}
V_19 ++ ;
V_18 -- ;
V_5 -> V_8 =
F_14 ( 1024 + 8 , V_23 ) ;
if ( ! V_5 -> V_8 ) {
F_5 ( L_10 ) ;
V_5 -> V_13 = V_14 ;
V_5 -> V_15 = 0 ;
return;
}
F_15 ( V_5 -> V_8 , 8 ) ;
V_5 -> V_8 -> V_24 [ 0 ] = 4 ;
V_5 -> V_8 -> V_24 [ 1 ] = 0 ;
}
return;
}
static long F_16 ( struct V_4 * V_5 , char * V_25 )
{
unsigned short V_26 = 0 , V_27 = 0 , V_28 = 0 , V_29 = 0 ;
const char V_30 [] = { 0x01 , 0x01 , 0x10 , 0x00 } ;
long V_31 ;
F_9 ( L_5 , V_21 ) ;
F_17 ( & V_5 -> V_12 ) ;
if ( 4 != F_18 ( V_5 -> V_32 , V_30 , 4 ) ) {
F_5 ( L_11 ) ;
return - V_33 ;
}
V_31 = F_19 (
& V_5 -> V_12 , F_20 ( V_34 ) ) ;
if ( V_31 <= 0 ) {
F_5 ( L_12 ) ;
return V_31 ? - V_35 : - V_36 ;
}
F_17 ( & V_5 -> V_12 ) ;
V_26 =
F_21 ( V_5 -> V_10 [ 12 ] ,
V_5 -> V_10 [ 13 ] ) ;
V_27 = ( V_26 & 0x7C00 ) >> 10 ;
V_28 = ( V_26 & 0x007F ) ;
V_29 = ( V_26 & 0x0380 ) >> 7 ;
if ( V_26 & 0x8000 )
V_29 |= 0x0008 ;
sprintf ( V_25 , L_13 ,
V_27 , V_29 , V_28 ) ;
V_5 -> V_26 . V_37 = V_26 ;
V_5 -> V_26 . V_27 = V_27 ;
V_5 -> V_26 . V_29 = V_29 ;
V_5 -> V_26 . V_28 = V_28 ;
F_13 ( L_5 , V_25 ) ;
return 0 ;
}
static void F_22 ( unsigned char * * V_19 , long * V_11 )
{
unsigned char * V_38 , * V_39 ;
V_39 = * V_19 ;
V_38 = V_39 + sizeof( struct V_40 ) +
( (struct V_40 * ) V_39 ) -> V_41 ;
if ( ( (struct V_40 * ) V_38 ) -> type != V_42 ) {
F_5 ( L_14 ) ;
} else {
* V_19 = * V_19 + sizeof( struct V_40 ) +
( (struct V_40 * ) V_39 ) -> V_41 ;
* V_11 = * V_11 - ( sizeof( struct V_40 ) +
( (struct V_40 * ) V_39 ) -> V_41 ) ;
F_23 ( L_15 ) ;
}
}
static long F_24 ( struct V_4 * V_5 )
{
long V_43 = 0 ;
long V_11 = 0 ;
unsigned char * V_19 = NULL ;
unsigned char * V_44 = NULL ;
unsigned char V_25 [ 40 ] = { 0 } ;
int V_45 ;
int V_46 ;
unsigned long V_31 ;
V_43 = F_16 ( V_5 , V_25 ) ;
if ( V_43 != 0 ) {
F_5 ( L_16 ) ;
return V_43 ;
}
V_43 =
F_25 ( & V_5 -> V_47 , V_25 ,
& V_5 -> V_48 -> V_49 ) ;
if ( F_4 ( ( V_43 != 0 ) || ( V_5 -> V_47 -> V_9 == NULL ) ||
( V_5 -> V_47 -> V_41 == 0 ) ) ) {
F_5 ( L_17 , V_43 ,
V_25 ) ;
return - V_50 ;
}
V_19 = ( void * ) V_5 -> V_47 -> V_9 ;
V_11 = V_5 -> V_47 -> V_41 ;
V_19 += sizeof( struct V_51 ) ;
V_11 -= sizeof( struct V_51 ) ;
while ( V_11 > 0 && V_19 ) {
F_9 ( L_18 ,
( (struct V_40 * ) V_19 ) -> V_41 ,
( (struct V_40 * ) V_19 ) -> type ) ;
switch ( ( (struct V_40 * ) V_19 ) -> type ) {
case V_52 :
F_9 ( L_19 ) ;
V_44 = & ( ( (struct V_40 * ) V_19 ) -> V_9 [ 0 ] ) ;
if ( F_4
( ( (struct V_53 * ) V_44 ) -> V_54 ==
0xFF36 ) ) {
F_23 ( L_20
L_21 ) ;
F_22 ( & V_19 , & V_11 ) ;
break;
}
V_46 = ( (struct V_40 * ) V_19 ) -> V_41 ;
V_31 = V_55 + F_20 ( V_56 ) ;
do {
V_45 =
F_26 ( V_5 -> V_32 ) ;
if ( V_45 < 0 ) {
F_5 ( L_22
L_23 ) ;
F_27 ( V_5 -> V_47 ) ;
return V_45 ;
}
F_28 ( 1 ) ;
} while ( ( V_45 < V_46 ) &&
F_29 ( V_55 , V_31 ) );
if ( F_30 ( V_55 , V_31 ) ) {
F_5 ( L_24
L_25 ) ;
F_27 ( V_5 -> V_47 ) ;
return - V_36 ;
}
F_17 ( & V_5 -> V_12 ) ;
V_43 = F_18 ( V_5 -> V_32 ,
( (struct V_57 * ) V_44 ) -> V_9 ,
( (struct V_40 * ) V_19 ) -> V_41 ) ;
if ( F_4 ( V_43 < 0 ) ) {
F_27 ( V_5 -> V_47 ) ;
return V_43 ;
}
if ( V_43 != V_46 ) {
F_5 ( L_26
L_27
L_28 ) ;
F_27 ( V_5 -> V_47 ) ;
return - V_33 ;
}
break;
case V_42 :
F_9 ( L_29 ) ;
V_43 = F_19 (
& V_5 -> V_12 ,
F_20 ( V_34 ) ) ;
if ( V_43 <= 0 ) {
F_5 ( L_30 ) ;
F_27 ( V_5 -> V_47 ) ;
return V_43 ? - V_35 : - V_36 ;
}
F_17 ( & V_5 -> V_12 ) ;
break;
case V_58 :
F_13 ( L_31 ) ;
V_44 = & ( ( (struct V_40 * ) V_19 ) -> V_9 [ 0 ] ) ;
F_28 ( ( (struct V_59 * ) V_44 ) -> V_60 ) ;
break;
}
V_11 =
V_11 - ( sizeof( struct V_40 ) +
( (struct V_40 * ) V_19 ) -> V_41 ) ;
V_19 =
V_19 + sizeof( struct V_40 ) +
( (struct V_40 * ) V_19 ) -> V_41 ;
}
F_27 ( V_5 -> V_47 ) ;
return 0 ;
}
void F_31 ( void * V_61 , const unsigned char * V_9 , long V_18 )
{
struct V_62 * V_63 = (struct V_62 * ) V_61 ;
struct V_4 * V_5 = V_63 -> V_64 ;
F_10 ( V_5 , V_9 , V_18 ) ;
return;
}
void F_32 ( void * V_64 )
{
struct V_4 * V_5 = (struct V_4 * ) V_64 ;
F_33 ( & V_5 -> V_65 ) ;
}
long F_34 ( void * V_64 )
{
long V_43 = 0 ;
long V_66 = V_67 ;
struct V_68 * V_69 ;
struct V_4 * V_5 = (struct V_4 * ) V_64 ;
F_13 ( L_32 , V_21 ) ;
if ( V_5 -> V_48 -> V_49 . V_70 ) {
F_9 ( L_33 ) ;
V_69 = V_71 ;
} else {
V_69 = V_5 -> V_48 -> V_49 . V_72 ;
}
do {
if ( V_69 -> V_73 )
V_69 -> V_73 ( V_5 ) ;
F_35 ( V_5 -> V_74 , V_75 ) ;
F_28 ( 5 ) ;
F_35 ( V_5 -> V_74 , V_76 ) ;
F_28 ( 100 ) ;
F_17 ( & V_5 -> V_65 ) ;
V_5 -> V_77 = 1 ;
F_13 ( L_34 ) ;
F_36 ( & V_5 -> V_48 -> V_49 . V_78 ,
NULL , L_35 ) ;
V_43 = F_19 (
& V_5 -> V_65 , F_20 ( V_79 ) ) ;
if ( ! V_43 ) {
F_5 ( L_36 ) ;
V_43 = F_37 ( V_5 ) ;
continue;
} else {
F_13 ( L_37 ) ;
V_43 = F_24 ( V_5 ) ;
if ( V_43 != 0 ) {
F_5 ( L_38 ) ;
V_43 = F_37 ( V_5 ) ;
continue;
} else {
break;
}
}
} while ( V_66 -- );
return V_43 ;
}
long F_37 ( void * V_64 )
{
long V_43 = 0 ;
struct V_4 * V_5 = (struct V_4 * ) V_64 ;
struct V_68 * V_69 ;
struct V_80 * V_81 = V_5 -> V_32 -> V_81 ;
F_17 ( & V_5 -> V_65 ) ;
if ( V_5 -> V_48 -> V_49 . V_70 ) {
F_9 ( L_33 ) ;
V_69 = V_71 ;
} else
V_69 = V_5 -> V_48 -> V_49 . V_72 ;
if ( V_81 ) {
F_38 ( V_81 ) ;
F_39 ( V_81 ) ;
}
F_13 ( L_39 ) ;
V_5 -> V_77 = 0 ;
F_36 ( & V_5 -> V_48 -> V_49 . V_78 , NULL , L_35 ) ;
V_43 = F_19 (
& V_5 -> V_65 , F_20 ( V_79 ) ) ;
if ( ! V_43 ) {
F_5 ( L_40 ) ;
V_43 = - V_36 ;
}
F_35 ( V_5 -> V_74 , V_75 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_74 , V_76 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_74 , V_75 ) ;
if ( V_69 -> V_82 )
V_69 -> V_82 ( V_5 ) ;
return V_43 ;
}
static int F_40 ( struct V_83 * V_84 , void * V_85 )
{
struct V_4 * V_5 = (struct V_4 * ) V_84 -> V_86 ;
F_41 ( V_84 , L_41 , V_5 -> V_26 . V_37 ,
V_5 -> V_26 . V_27 , V_5 -> V_26 . V_29 ,
V_5 -> V_26 . V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_83 * V_84 , void * V_85 )
{
struct V_4 * V_5 = (struct V_4 * ) V_84 -> V_86 ;
F_43 ( V_5 -> V_32 , V_84 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_87 * V_49 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_4 * V_64 = F_45 ( V_49 ) ;
return sprintf ( V_90 , L_42 , V_64 -> V_77 ) ;
}
static T_1 F_46 ( struct V_87 * V_49 ,
struct V_88 * V_89 , const char * V_90 , T_2 V_18 )
{
struct V_4 * V_64 = F_45 ( V_49 ) ;
F_9 ( L_43 , V_90 ) ;
strncpy ( V_64 -> V_91 , V_90 , V_18 ) ;
F_9 ( L_44 , V_64 -> V_91 ) ;
return V_18 ;
}
static T_1 F_47 ( struct V_87 * V_49 ,
struct V_88 * V_89 , const char * V_90 , T_2 V_18 )
{
struct V_4 * V_64 = F_45 ( V_49 ) ;
F_9 ( L_45 , V_90 ) ;
sscanf ( V_90 , L_46 , & V_64 -> V_92 ) ;
F_9 ( L_47 , V_64 -> V_92 ) ;
return V_18 ;
}
static T_1 F_48 ( struct V_87 * V_49 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_4 * V_64 = F_45 ( V_49 ) ;
return sprintf ( V_90 , L_48 , V_64 -> V_91 ) ;
}
static T_1 F_49 ( struct V_87 * V_49 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_4 * V_64 = F_45 ( V_49 ) ;
return sprintf ( V_90 , L_42 , V_64 -> V_92 ) ;
}
static T_1 F_50 ( struct V_87 * V_49 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_4 * V_64 = F_45 ( V_49 ) ;
return sprintf ( V_90 , L_42 , V_64 -> V_93 ) ;
}
void F_51 ( struct V_62 * * V_32 , int V_2 )
{
struct V_1 * V_94 ;
struct V_4 * V_5 ;
V_94 = F_1 ( V_2 ) ;
if ( ! V_94 )
goto V_43;
V_5 = F_52 ( V_94 ) ;
if ( ! V_5 )
goto V_43;
* V_32 = V_5 -> V_32 ;
return;
V_43:
* V_32 = NULL ;
}
static int F_53 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
return F_54 ( V_98 , F_40 , V_96 -> V_99 ) ;
}
static int F_55 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
return F_54 ( V_98 , F_42 , V_96 -> V_99 ) ;
}
static struct V_68 * F_56 ( struct V_87 * V_49 )
{
struct V_100 * V_101 = V_49 -> V_70 ;
const T_3 * V_102 ;
int V_11 ;
V_71 = F_57 ( sizeof( * V_71 ) , V_103 ) ;
if ( ! V_71 )
return NULL ;
V_102 = F_58 ( V_101 , L_49 , & V_11 ) ;
if ( V_102 )
memcpy ( & V_71 -> V_91 , V_102 , V_11 ) ;
F_59 ( V_101 , L_50 ,
& V_71 -> V_104 ) ;
F_59 ( V_101 , L_51 , & V_71 -> V_93 ) ;
F_59 ( V_101 , L_52 , & V_71 -> V_92 ) ;
return V_71 ;
}
static int F_60 ( struct V_1 * V_94 )
{
struct V_4 * V_5 ;
struct V_68 * V_69 ;
int V_43 ;
if ( V_94 -> V_49 . V_70 )
V_69 = F_56 ( & V_94 -> V_49 ) ;
else
V_69 = V_94 -> V_49 . V_72 ;
if ( V_69 == NULL ) {
F_61 ( & V_94 -> V_49 , L_53 ) ;
return - V_105 ;
}
if ( ( V_94 -> V_2 != - 1 ) && ( V_94 -> V_2 < V_106 ) ) {
V_3 [ V_94 -> V_2 ] = V_94 ;
} else {
V_3 [ 0 ] = V_94 ;
}
V_5 = F_57 ( sizeof( struct V_4 ) , V_23 ) ;
if ( ! V_5 ) {
F_5 ( L_54 ) ;
return - V_107 ;
}
F_62 ( V_94 , V_5 ) ;
V_43 = F_63 ( & V_5 -> V_32 ) ;
if ( V_43 != 0 ) {
F_5 ( L_55 ) ;
V_43 = - V_33 ;
goto V_108;
}
V_5 -> V_32 -> V_64 = V_5 ;
V_5 -> V_74 = V_69 -> V_104 ;
V_43 = F_64 ( V_5 -> V_74 , L_56 ) ;
if ( F_4 ( V_43 ) ) {
F_5 ( L_57 , V_5 -> V_74 ) ;
return V_43 ;
}
V_43 = F_65 ( V_5 -> V_74 , 0 ) ;
if ( F_4 ( V_43 ) ) {
F_5 ( L_58 , V_5 -> V_74 ) ;
return V_43 ;
}
V_5 -> V_48 = V_94 ;
F_66 ( & V_5 -> V_12 ) ;
F_66 ( & V_5 -> V_65 ) ;
V_43 = F_67 ( & V_94 -> V_49 . V_78 , & V_109 ) ;
if ( V_43 ) {
F_5 ( L_59 ) ;
goto V_110;
}
strncpy ( V_5 -> V_91 , V_69 -> V_91 , V_111 ) ;
V_5 -> V_93 = V_69 -> V_93 ;
V_5 -> V_92 = V_69 -> V_92 ;
F_13 ( L_60 ) ;
V_112 = F_68 ( L_61 , NULL ) ;
if ( ! V_112 ) {
F_5 ( L_62 ) ;
return 0 ;
}
F_69 ( L_63 , V_113 , V_112 ,
V_5 , & V_114 ) ;
F_69 ( L_64 , V_113 , V_112 ,
V_5 , & V_115 ) ;
return 0 ;
V_110:
F_70 ( V_5 -> V_32 ) ;
V_108:
F_71 ( V_5 ) ;
return V_43 ;
}
static int F_72 ( struct V_1 * V_94 )
{
struct V_68 * V_69 ;
struct V_4 * V_5 ;
if ( V_94 -> V_49 . V_70 ) {
F_9 ( L_33 ) ;
V_69 = V_71 ;
} else {
V_69 = V_94 -> V_49 . V_72 ;
}
V_5 = F_52 ( V_94 ) ;
F_73 ( V_69 -> V_104 ) ;
F_13 ( L_65 ) ;
F_74 ( V_112 ) ;
F_75 ( & V_94 -> V_49 . V_78 , & V_109 ) ;
F_13 ( L_66 ) ;
V_5 -> V_48 = NULL ;
F_70 ( V_5 -> V_32 ) ;
F_71 ( V_5 ) ;
V_5 = NULL ;
F_71 ( V_71 ) ;
V_71 = NULL ;
return 0 ;
}
static int F_76 ( struct V_1 * V_94 , T_4 V_116 )
{
struct V_68 * V_69 ;
if ( V_94 -> V_49 . V_70 ) {
F_9 ( L_33 ) ;
V_69 = V_71 ;
} else {
V_69 = V_94 -> V_49 . V_72 ;
}
if ( V_69 -> V_117 )
return V_69 -> V_117 ( V_94 , V_116 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_94 )
{
struct V_68 * V_69 ;
if ( V_94 -> V_49 . V_70 ) {
F_9 ( L_33 ) ;
V_69 = V_71 ;
} else {
V_69 = V_94 -> V_49 . V_72 ;
}
if ( V_69 -> V_118 )
return V_69 -> V_118 ( V_94 ) ;
return 0 ;
}
