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
F_9 ( L_5 , V_21 ) ;
F_17 ( & V_5 -> V_12 ) ;
if ( 4 != F_18 ( V_5 -> V_31 , V_30 , 4 ) ) {
F_5 ( L_11 ) ;
return - V_32 ;
}
if ( ! F_19 (
& V_5 -> V_12 , F_20 ( V_33 ) ) ) {
F_5 ( L_12 ) ;
return - V_34 ;
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
sprintf ( V_25 , L_13 , V_27 , V_29 , V_28 ) ;
V_5 -> V_26 . V_35 = V_26 ;
V_5 -> V_26 . V_27 = V_27 ;
V_5 -> V_26 . V_29 = V_29 ;
V_5 -> V_26 . V_28 = V_28 ;
F_13 ( L_5 , V_25 ) ;
return 0 ;
}
static void F_22 ( unsigned char * * V_19 , long * V_11 )
{
unsigned char * V_36 , * V_37 ;
V_37 = * V_19 ;
V_36 = V_37 + sizeof( struct V_38 ) +
( (struct V_38 * ) V_37 ) -> V_39 ;
if ( ( (struct V_38 * ) V_36 ) -> type != V_40 ) {
F_5 ( L_14 ) ;
} else {
* V_19 = * V_19 + sizeof( struct V_38 ) +
( (struct V_38 * ) V_37 ) -> V_39 ;
* V_11 = * V_11 - ( sizeof( struct V_38 ) +
( (struct V_38 * ) V_37 ) -> V_39 ) ;
F_23 ( L_15 ) ;
}
}
static long F_24 ( struct V_4 * V_5 )
{
long V_41 = 0 ;
long V_11 = 0 ;
unsigned char * V_19 = NULL ;
unsigned char * V_42 = NULL ;
unsigned char V_25 [ 30 ] = { 0 } ;
int V_43 ;
int V_44 ;
unsigned long V_45 ;
V_41 = F_16 ( V_5 , V_25 ) ;
if ( V_41 != 0 ) {
F_5 ( L_16 ) ;
return V_41 ;
}
V_41 =
F_25 ( & V_5 -> V_46 , V_25 ,
& V_5 -> V_47 -> V_48 ) ;
if ( F_4 ( ( V_41 != 0 ) || ( V_5 -> V_46 -> V_9 == NULL ) ||
( V_5 -> V_46 -> V_39 == 0 ) ) ) {
F_5 ( L_17 , V_41 ,
V_25 ) ;
return - V_49 ;
}
V_19 = ( void * ) V_5 -> V_46 -> V_9 ;
V_11 = V_5 -> V_46 -> V_39 ;
V_19 += sizeof( struct V_50 ) ;
V_11 -= sizeof( struct V_50 ) ;
while ( V_11 > 0 && V_19 ) {
F_9 ( L_18 ,
( (struct V_38 * ) V_19 ) -> V_39 ,
( (struct V_38 * ) V_19 ) -> type ) ;
switch ( ( (struct V_38 * ) V_19 ) -> type ) {
case V_51 :
F_9 ( L_19 ) ;
V_42 = & ( ( (struct V_38 * ) V_19 ) -> V_9 [ 0 ] ) ;
if ( F_4
( ( (struct V_52 * ) V_42 ) -> V_53 ==
0xFF36 ) ) {
F_23 ( L_20
L_21 ) ;
F_22 ( & V_19 , & V_11 ) ;
break;
}
V_44 = ( (struct V_38 * ) V_19 ) -> V_39 ;
V_45 = V_54 + F_20 ( V_55 ) ;
do {
V_43 =
F_26 ( V_5 -> V_31 ) ;
if ( V_43 < 0 ) {
F_5 ( L_22
L_23 ) ;
F_27 ( V_5 -> V_46 ) ;
return V_43 ;
}
F_28 ( 1 ) ;
} while ( ( V_43 < V_44 ) &&
F_29 ( V_54 , V_45 ) );
if ( F_30 ( V_54 , V_45 ) ) {
F_5 ( L_24
L_25 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_34 ;
}
F_17 ( & V_5 -> V_12 ) ;
V_41 = F_18 ( V_5 -> V_31 ,
( (struct V_56 * ) V_42 ) -> V_9 ,
( (struct V_38 * ) V_19 ) -> V_39 ) ;
if ( F_4 ( V_41 < 0 ) ) {
F_27 ( V_5 -> V_46 ) ;
return V_41 ;
}
if ( V_41 != V_44 ) {
F_5 ( L_26
L_27
L_28 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_32 ;
}
break;
case V_40 :
F_9 ( L_29 ) ;
if ( ! F_19 (
& V_5 -> V_12 ,
F_20 ( V_33 ) ) ) {
F_5 ( L_30 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_34 ;
}
F_17 ( & V_5 -> V_12 ) ;
break;
case V_57 :
F_13 ( L_31 ) ;
V_42 = & ( ( (struct V_38 * ) V_19 ) -> V_9 [ 0 ] ) ;
F_28 ( ( (struct V_58 * ) V_42 ) -> V_59 ) ;
break;
}
V_11 =
V_11 - ( sizeof( struct V_38 ) +
( (struct V_38 * ) V_19 ) -> V_39 ) ;
V_19 =
V_19 + sizeof( struct V_38 ) +
( (struct V_38 * ) V_19 ) -> V_39 ;
}
F_27 ( V_5 -> V_46 ) ;
return 0 ;
}
void F_31 ( void * V_60 , const unsigned char * V_9 , long V_18 )
{
struct V_61 * V_62 = (struct V_61 * ) V_60 ;
struct V_4 * V_5 = V_62 -> V_63 ;
F_10 ( V_5 , V_9 , V_18 ) ;
return;
}
void F_32 ( void * V_63 )
{
struct V_4 * V_5 = (struct V_4 * ) V_63 ;
F_33 ( & V_5 -> V_64 ) ;
}
long F_34 ( void * V_63 )
{
long V_41 = 0 ;
long V_65 = V_66 ;
struct V_67 * V_68 ;
struct V_4 * V_5 = (struct V_4 * ) V_63 ;
F_13 ( L_32 , V_21 ) ;
V_68 = V_5 -> V_47 -> V_48 . V_69 ;
do {
if ( V_68 -> V_70 )
V_68 -> V_70 ( V_5 ) ;
F_35 ( V_5 -> V_71 , V_72 ) ;
F_28 ( 5 ) ;
F_35 ( V_5 -> V_71 , V_73 ) ;
F_28 ( 100 ) ;
F_17 ( & V_5 -> V_64 ) ;
V_5 -> V_74 = 1 ;
F_13 ( L_33 ) ;
F_36 ( & V_5 -> V_47 -> V_48 . V_75 ,
NULL , L_34 ) ;
V_41 = F_19 (
& V_5 -> V_64 , F_20 ( V_76 ) ) ;
if ( ! V_41 ) {
F_5 ( L_35 ) ;
V_41 = F_37 ( V_5 ) ;
continue;
} else {
F_13 ( L_36 ) ;
V_41 = F_24 ( V_5 ) ;
if ( V_41 != 0 ) {
F_5 ( L_37 ) ;
V_41 = F_37 ( V_5 ) ;
continue;
} else {
break;
}
}
} while ( V_65 -- );
return V_41 ;
}
long F_37 ( void * V_63 )
{
long V_41 = 0 ;
struct V_4 * V_5 = (struct V_4 * ) V_63 ;
struct V_67 * V_68 =
V_5 -> V_47 -> V_48 . V_69 ;
struct V_77 * V_78 = V_5 -> V_31 -> V_78 ;
F_17 ( & V_5 -> V_64 ) ;
if ( V_78 ) {
F_38 ( V_78 ) ;
F_39 ( V_78 ) ;
}
F_13 ( L_38 ) ;
V_5 -> V_74 = 0 ;
F_36 ( & V_5 -> V_47 -> V_48 . V_75 , NULL , L_34 ) ;
V_41 = F_19 (
& V_5 -> V_64 , F_20 ( V_76 ) ) ;
if ( ! V_41 ) {
F_5 ( L_39 ) ;
V_41 = - V_34 ;
}
F_35 ( V_5 -> V_71 , V_72 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_71 , V_73 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_71 , V_72 ) ;
if ( V_68 -> V_79 )
V_68 -> V_79 ( V_5 ) ;
return V_41 ;
}
static int F_40 ( struct V_80 * V_81 , void * V_82 )
{
struct V_4 * V_5 = (struct V_4 * ) V_81 -> V_83 ;
F_41 ( V_81 , L_40 , V_5 -> V_26 . V_35 ,
V_5 -> V_26 . V_27 , V_5 -> V_26 . V_29 ,
V_5 -> V_26 . V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_80 * V_81 , void * V_82 )
{
struct V_4 * V_5 = (struct V_4 * ) V_81 -> V_83 ;
F_43 ( V_5 -> V_31 , V_81 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_84 * V_48 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_87 , L_41 , V_63 -> V_74 ) ;
}
static T_1 F_46 ( struct V_84 * V_48 ,
struct V_85 * V_86 , const char * V_87 , T_2 V_18 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
F_9 ( L_42 , V_87 ) ;
strncpy ( V_63 -> V_88 , V_87 , V_18 ) ;
F_9 ( L_43 , V_63 -> V_88 ) ;
return V_18 ;
}
static T_1 F_47 ( struct V_84 * V_48 ,
struct V_85 * V_86 , const char * V_87 , T_2 V_18 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
F_9 ( L_44 , V_87 ) ;
sscanf ( V_87 , L_45 , & V_63 -> V_89 ) ;
F_9 ( L_46 , V_63 -> V_89 ) ;
return V_18 ;
}
static T_1 F_48 ( struct V_84 * V_48 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_87 , L_47 , V_63 -> V_88 ) ;
}
static T_1 F_49 ( struct V_84 * V_48 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_87 , L_48 , V_63 -> V_89 ) ;
}
static T_1 F_50 ( struct V_84 * V_48 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_87 , L_41 , V_63 -> V_90 ) ;
}
void F_51 ( struct V_61 * * V_31 , int V_2 )
{
struct V_1 * V_91 ;
struct V_4 * V_5 ;
V_91 = F_1 ( V_2 ) ;
if ( ! V_91 ) {
* V_31 = NULL ;
return;
}
V_5 = F_52 ( V_91 ) ;
* V_31 = V_5 -> V_31 ;
}
static int F_53 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
return F_54 ( V_95 , F_40 , V_93 -> V_96 ) ;
}
static int F_55 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
return F_54 ( V_95 , F_42 , V_93 -> V_96 ) ;
}
static int F_56 ( struct V_1 * V_91 )
{
struct V_4 * V_5 ;
struct V_67 * V_68 = V_91 -> V_48 . V_69 ;
int V_41 ;
if ( ( V_91 -> V_2 != - 1 ) && ( V_91 -> V_2 < V_97 ) ) {
V_3 [ V_91 -> V_2 ] = V_91 ;
} else {
V_3 [ 0 ] = V_91 ;
}
V_5 = F_57 ( sizeof( struct V_4 ) , V_23 ) ;
if ( ! V_5 ) {
F_5 ( L_49 ) ;
return - V_98 ;
}
F_58 ( V_91 , V_5 ) ;
V_41 = F_59 ( & V_5 -> V_31 ) ;
if ( V_41 != 0 ) {
F_5 ( L_50 ) ;
V_41 = - V_32 ;
goto V_99;
}
V_5 -> V_31 -> V_63 = V_5 ;
V_5 -> V_71 = V_68 -> V_100 ;
V_41 = F_60 ( V_5 -> V_71 , L_51 ) ;
if ( F_4 ( V_41 ) ) {
F_5 ( L_52 , V_5 -> V_71 ) ;
return V_41 ;
}
V_41 = F_61 ( V_5 -> V_71 , 0 ) ;
if ( F_4 ( V_41 ) ) {
F_5 ( L_53 , V_5 -> V_71 ) ;
return V_41 ;
}
V_5 -> V_47 = V_91 ;
F_62 ( & V_5 -> V_12 ) ;
F_62 ( & V_5 -> V_64 ) ;
V_41 = F_63 ( & V_91 -> V_48 . V_75 , & V_101 ) ;
if ( V_41 ) {
F_5 ( L_54 ) ;
goto V_102;
}
strncpy ( V_5 -> V_88 , V_68 -> V_88 , V_103 ) ;
V_5 -> V_90 = V_68 -> V_90 ;
V_5 -> V_89 = V_68 -> V_89 ;
F_13 ( L_55 ) ;
V_104 = F_64 ( L_56 , NULL ) ;
if ( F_65 ( V_104 ) ) {
F_5 ( L_57 ) ;
V_41 = - V_32 ;
goto V_105;
}
F_66 ( L_58 , V_106 , V_104 ,
V_5 , & V_107 ) ;
F_66 ( L_59 , V_106 , V_104 ,
V_5 , & V_108 ) ;
F_13 ( L_60 ) ;
return 0 ;
V_105:
F_67 ( & V_91 -> V_48 . V_75 , & V_101 ) ;
V_102:
F_68 ( V_5 -> V_31 ) ;
V_99:
F_69 ( V_5 ) ;
return V_41 ;
}
static int F_70 ( struct V_1 * V_91 )
{
struct V_67 * V_68 = V_91 -> V_48 . V_69 ;
struct V_4 * V_5 ;
V_5 = F_52 ( V_91 ) ;
F_71 ( V_68 -> V_100 ) ;
F_13 ( L_61 ) ;
F_72 ( V_104 ) ;
F_67 ( & V_91 -> V_48 . V_75 , & V_101 ) ;
F_13 ( L_62 ) ;
V_5 -> V_47 = NULL ;
F_68 ( V_5 -> V_31 ) ;
F_69 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
static int F_73 ( struct V_1 * V_91 , T_3 V_109 )
{
struct V_67 * V_68 = V_91 -> V_48 . V_69 ;
if ( V_68 -> V_110 )
return V_68 -> V_110 ( V_91 , V_109 ) ;
return - V_111 ;
}
static int F_74 ( struct V_1 * V_91 )
{
struct V_67 * V_68 = V_91 -> V_48 . V_69 ;
if ( V_68 -> V_112 )
return V_68 -> V_112 ( V_91 ) ;
return - V_111 ;
}
