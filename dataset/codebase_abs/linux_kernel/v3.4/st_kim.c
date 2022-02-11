static struct V_1 * F_1 ( int V_2 )
{
return V_3 [ V_2 ] ;
}
void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_3 ( V_7 -> V_9 [ 5 ] != 0 ) ) {
F_4 ( L_1 ) ;
F_4 ( L_2 , V_7 -> V_9 [ 5 ] ) ;
F_5 ( V_7 ) ;
return;
}
F_6 ( & V_5 -> V_10 ) ;
F_5 ( V_7 ) ;
}
static inline int F_7 ( struct V_4 * V_5 , int V_11 )
{
register int V_12 = F_8 ( V_5 -> V_8 ) ;
F_9 ( L_3 , V_11 , V_12 ) ;
if ( ! V_11 ) {
F_2 ( V_5 ) ;
} else if ( V_11 > V_12 ) {
F_4 ( L_4 , V_11 ,
V_12 ) ;
F_5 ( V_5 -> V_8 ) ;
} else {
V_5 -> V_13 = V_14 ;
V_5 -> V_15 = V_11 ;
return V_11 ;
}
V_5 -> V_13 = V_16 ;
V_5 -> V_8 = NULL ;
V_5 -> V_15 = 0 ;
return 0 ;
}
void F_10 ( struct V_4 * V_5 ,
const unsigned char * V_9 , long V_17 )
{
const unsigned char * V_18 ;
int V_11 = 0 , type = 0 ;
unsigned char * V_19 ;
F_9 ( L_5 , V_20 ) ;
V_18 = V_9 ;
if ( F_3 ( V_18 == NULL ) ) {
F_4 ( L_6 ) ;
return;
}
while ( V_17 ) {
if ( V_5 -> V_15 ) {
V_11 = F_11 (unsigned int, kim_gdata->rx_count, count) ;
memcpy ( F_12 ( V_5 -> V_8 , V_11 ) , V_18 , V_11 ) ;
V_5 -> V_15 -= V_11 ;
V_17 -= V_11 ;
V_18 += V_11 ;
if ( V_5 -> V_15 )
continue;
switch ( V_5 -> V_13 ) {
case V_14 :
F_9 ( L_7 ) ;
F_2 ( V_5 ) ;
V_5 -> V_13 = V_16 ;
V_5 -> V_8 = NULL ;
continue;
case V_21 :
V_19 =
( unsigned char * ) & V_5 -> V_8 -> V_9 [ 1 ] ;
F_9 ( L_8 , * V_19 ) ;
F_7 ( V_5 , * V_19 ) ;
continue;
}
}
switch ( * V_18 ) {
case 0x04 :
V_5 -> V_13 = V_21 ;
V_5 -> V_15 = 2 ;
type = * V_18 ;
break;
default:
F_13 ( L_9 ) ;
V_18 ++ ;
V_17 -- ;
continue;
}
V_18 ++ ;
V_17 -- ;
V_5 -> V_8 =
F_14 ( 1024 + 8 , V_22 ) ;
if ( ! V_5 -> V_8 ) {
F_4 ( L_10 ) ;
V_5 -> V_13 = V_16 ;
V_5 -> V_15 = 0 ;
return;
}
F_15 ( V_5 -> V_8 , 8 ) ;
V_5 -> V_8 -> V_23 [ 0 ] = 4 ;
V_5 -> V_8 -> V_23 [ 1 ] = 0 ;
}
return;
}
static long F_16 ( struct V_4 * V_5 , char * V_24 )
{
unsigned short V_25 = 0 , V_26 = 0 , V_27 = 0 , V_28 = 0 ;
const char V_29 [] = { 0x01 , 0x01 , 0x10 , 0x00 } ;
F_9 ( L_5 , V_20 ) ;
F_17 ( V_5 -> V_10 ) ;
if ( 4 != F_18 ( V_5 -> V_30 , V_29 , 4 ) ) {
F_4 ( L_11 ) ;
return - V_31 ;
}
if ( ! F_19
( & V_5 -> V_10 , F_20 ( V_32 ) ) ) {
F_4 ( L_12 ) ;
return - V_33 ;
}
F_17 ( V_5 -> V_10 ) ;
V_25 =
F_21 ( V_5 -> V_34 [ 13 ] ,
V_5 -> V_34 [ 14 ] ) ;
V_26 = ( V_25 & 0x7C00 ) >> 10 ;
V_27 = ( V_25 & 0x007F ) ;
V_28 = ( V_25 & 0x0380 ) >> 7 ;
if ( V_25 & 0x8000 )
V_28 |= 0x0008 ;
sprintf ( V_24 , L_13 , V_26 , V_28 , V_27 ) ;
V_5 -> V_25 . V_35 = V_25 ;
V_5 -> V_25 . V_26 = V_26 ;
V_5 -> V_25 . V_28 = V_28 ;
V_5 -> V_25 . V_27 = V_27 ;
F_13 ( L_5 , V_24 ) ;
return 0 ;
}
void F_22 ( unsigned char * * V_18 , long * V_11 )
{
unsigned char * V_36 , * V_37 ;
V_37 = * V_18 ;
V_36 = V_37 + sizeof( struct V_38 ) +
( (struct V_38 * ) V_37 ) -> V_39 ;
if ( ( (struct V_38 * ) V_36 ) -> type != V_40 ) {
F_4 ( L_14 ) ;
} else {
* V_18 = * V_18 + sizeof( struct V_38 ) +
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
unsigned char * V_18 = NULL ;
unsigned char * V_42 = NULL ;
unsigned char V_24 [ 30 ] = { 0 } ;
int V_43 ;
int V_44 ;
unsigned long V_45 ;
V_41 = F_16 ( V_5 , V_24 ) ;
if ( V_41 != 0 ) {
F_4 ( L_16 ) ;
return V_41 ;
}
V_41 =
F_25 ( & V_5 -> V_46 , V_24 ,
& V_5 -> V_47 -> V_48 ) ;
if ( F_3 ( ( V_41 != 0 ) || ( V_5 -> V_46 -> V_9 == NULL ) ||
( V_5 -> V_46 -> V_39 == 0 ) ) ) {
F_4 ( L_17 , V_41 ,
V_24 ) ;
return - V_49 ;
}
V_18 = ( void * ) V_5 -> V_46 -> V_9 ;
V_11 = V_5 -> V_46 -> V_39 ;
V_18 += sizeof( struct V_50 ) ;
V_11 -= sizeof( struct V_50 ) ;
while ( V_11 > 0 && V_18 ) {
F_9 ( L_18 ,
( (struct V_38 * ) V_18 ) -> V_39 ,
( (struct V_38 * ) V_18 ) -> type ) ;
switch ( ( (struct V_38 * ) V_18 ) -> type ) {
case V_51 :
F_9 ( L_19 ) ;
V_42 = & ( ( (struct V_38 * ) V_18 ) -> V_9 [ 0 ] ) ;
if ( F_3
( ( (struct V_52 * ) V_42 ) -> V_53 ==
0xFF36 ) ) {
F_23 ( L_20
L_21 ) ;
F_22 ( & V_18 , & V_11 ) ;
break;
}
V_44 = ( (struct V_38 * ) V_18 ) -> V_39 ;
V_45 = V_54 + F_20 ( V_55 ) ;
do {
V_43 =
F_26 ( V_5 -> V_30 ) ;
if ( V_43 < 0 ) {
F_4 ( L_22
L_23 ) ;
F_27 ( V_5 -> V_46 ) ;
return V_43 ;
}
F_28 ( 1 ) ;
} while ( ( V_43 < V_44 ) &&
F_29 ( V_54 , V_45 ) );
if ( F_30 ( V_54 , V_45 ) ) {
F_4 ( L_24
L_25 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_33 ;
}
F_17 ( V_5 -> V_10 ) ;
V_41 = F_18 ( V_5 -> V_30 ,
( (struct V_56 * ) V_42 ) -> V_9 ,
( (struct V_38 * ) V_18 ) -> V_39 ) ;
if ( F_3 ( V_41 < 0 ) ) {
F_27 ( V_5 -> V_46 ) ;
return V_41 ;
}
if ( V_41 != V_44 ) {
F_4 ( L_26
L_27
L_28 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_31 ;
}
break;
case V_40 :
F_9 ( L_29 ) ;
if ( ! F_19
( & V_5 -> V_10 ,
F_20 ( V_32 ) ) ) {
F_4 ( L_30 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_33 ;
}
F_17 ( V_5 -> V_10 ) ;
break;
case V_57 :
F_13 ( L_31 ) ;
V_42 = & ( ( (struct V_38 * ) V_18 ) -> V_9 [ 0 ] ) ;
F_28 ( ( (struct V_58 * ) V_42 ) -> V_59 ) ;
break;
}
V_11 =
V_11 - ( sizeof( struct V_38 ) +
( (struct V_38 * ) V_18 ) -> V_39 ) ;
V_18 =
V_18 + sizeof( struct V_38 ) +
( (struct V_38 * ) V_18 ) -> V_39 ;
}
F_27 ( V_5 -> V_46 ) ;
return 0 ;
}
void F_31 ( void * V_60 , const unsigned char * V_9 , long V_17 )
{
struct V_61 * V_62 = (struct V_61 * ) V_60 ;
struct V_4 * V_5 = V_62 -> V_63 ;
if ( F_3 ( V_9 [ 4 ] == 0x01 && V_9 [ 5 ] == 0x10 && V_9 [ 0 ] == 0x04 ) ) {
memcpy ( V_5 -> V_34 , V_9 , V_17 ) ;
F_6 ( & V_5 -> V_10 ) ;
return;
} else {
F_10 ( V_5 , V_9 , V_17 ) ;
}
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
F_13 ( L_32 , V_20 ) ;
V_68 = V_5 -> V_47 -> V_48 . V_69 ;
do {
if ( V_68 -> V_70 )
V_68 -> V_70 ( V_5 ) ;
F_35 ( V_5 -> V_71 , V_72 ) ;
F_28 ( 5 ) ;
F_35 ( V_5 -> V_71 , V_73 ) ;
F_28 ( 100 ) ;
F_17 ( V_5 -> V_64 ) ;
V_5 -> V_74 = 1 ;
F_13 ( L_33 ) ;
F_36 ( & V_5 -> V_47 -> V_48 . V_75 ,
NULL , L_34 ) ;
V_41 = F_19 ( & V_5 -> V_64 ,
F_20 ( V_76 ) ) ;
if ( ! V_41 ) {
F_4 ( L_35 ) ;
V_41 = F_37 ( V_5 ) ;
continue;
} else {
F_13 ( L_36 ) ;
V_41 = F_24 ( V_5 ) ;
if ( V_41 != 0 ) {
F_4 ( L_37 ) ;
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
struct V_77 * V_78 = V_5 -> V_30 -> V_78 ;
F_17 ( V_5 -> V_64 ) ;
if ( V_78 ) {
F_38 ( V_78 ) ;
F_39 ( V_78 ) ;
V_78 -> V_79 -> V_80 ( V_78 ) ;
}
F_13 ( L_38 ) ;
V_5 -> V_74 = 0 ;
F_36 ( & V_5 -> V_47 -> V_48 . V_75 , NULL , L_34 ) ;
V_41 = F_19 ( & V_5 -> V_64 ,
F_20 ( V_76 ) ) ;
if ( ! V_41 ) {
F_4 ( L_39 ) ;
return - V_33 ;
}
F_35 ( V_5 -> V_71 , V_72 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_71 , V_73 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_71 , V_72 ) ;
if ( V_68 -> V_81 )
V_68 -> V_81 ( V_5 ) ;
return V_41 ;
}
static int F_40 ( struct V_82 * V_83 , void * V_84 )
{
struct V_4 * V_5 = (struct V_4 * ) V_83 -> V_85 ;
F_41 ( V_83 , L_40 , V_5 -> V_25 . V_35 ,
V_5 -> V_25 . V_26 , V_5 -> V_25 . V_28 ,
V_5 -> V_25 . V_27 ) ;
return 0 ;
}
static int F_42 ( struct V_82 * V_83 , void * V_84 )
{
struct V_4 * V_5 = (struct V_4 * ) V_83 -> V_85 ;
F_43 ( V_5 -> V_30 , V_83 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_86 * V_48 ,
struct V_87 * V_88 , char * V_89 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_89 , L_41 , V_63 -> V_74 ) ;
}
static T_1 F_46 ( struct V_86 * V_48 ,
struct V_87 * V_88 , const char * V_89 , T_2 V_17 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
F_9 ( L_42 , V_89 ) ;
strncpy ( V_63 -> V_90 , V_89 , V_17 ) ;
F_9 ( L_43 , V_63 -> V_90 ) ;
return V_17 ;
}
static T_1 F_47 ( struct V_86 * V_48 ,
struct V_87 * V_88 , const char * V_89 , T_2 V_17 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
F_9 ( L_44 , V_89 ) ;
sscanf ( V_89 , L_45 , & V_63 -> V_91 ) ;
F_9 ( L_46 , V_63 -> V_91 ) ;
return V_17 ;
}
static T_1 F_48 ( struct V_86 * V_48 ,
struct V_87 * V_88 , char * V_89 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_89 , L_47 , V_63 -> V_90 ) ;
}
static T_1 F_49 ( struct V_86 * V_48 ,
struct V_87 * V_88 , char * V_89 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_89 , L_48 , V_63 -> V_91 ) ;
}
static T_1 F_50 ( struct V_86 * V_48 ,
struct V_87 * V_88 , char * V_89 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_89 , L_41 , V_63 -> V_92 ) ;
}
void F_51 ( struct V_61 * * V_30 , int V_2 )
{
struct V_1 * V_93 ;
struct V_4 * V_5 ;
V_93 = F_1 ( V_2 ) ;
if ( ! V_93 ) {
* V_30 = NULL ;
return;
}
V_5 = F_45 ( & V_93 -> V_48 ) ;
* V_30 = V_5 -> V_30 ;
}
static int F_52 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
return F_53 ( V_97 , F_40 , V_95 -> V_98 ) ;
}
static int F_54 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
return F_53 ( V_97 , F_42 , V_95 -> V_98 ) ;
}
static int F_55 ( struct V_1 * V_93 )
{
long V_99 ;
struct V_4 * V_5 ;
struct V_67 * V_68 = V_93 -> V_48 . V_69 ;
if ( ( V_93 -> V_2 != - 1 ) && ( V_93 -> V_2 < V_100 ) ) {
V_3 [ V_93 -> V_2 ] = V_93 ;
} else {
V_3 [ 0 ] = V_93 ;
}
V_5 = F_56 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 ) {
F_4 ( L_49 ) ;
return - V_101 ;
}
F_57 ( & V_93 -> V_48 , V_5 ) ;
V_99 = F_58 ( & V_5 -> V_30 ) ;
if ( V_99 != 0 ) {
F_4 ( L_50 ) ;
return - V_31 ;
}
V_5 -> V_30 -> V_63 = V_5 ;
V_5 -> V_71 = V_68 -> V_102 ;
V_99 = F_59 ( V_5 -> V_71 , L_51 ) ;
if ( F_3 ( V_99 ) ) {
F_4 ( L_52 , V_5 -> V_71 ) ;
return V_99 ;
}
V_99 = F_60 ( V_5 -> V_71 , 0 ) ;
if ( F_3 ( V_99 ) ) {
F_4 ( L_53 , V_5 -> V_71 ) ;
return V_99 ;
}
V_5 -> V_47 = V_93 ;
F_61 ( & V_5 -> V_10 ) ;
F_61 ( & V_5 -> V_64 ) ;
V_99 = F_62 ( & V_93 -> V_48 . V_75 , & V_103 ) ;
if ( V_99 ) {
F_4 ( L_54 ) ;
return V_99 ;
}
strncpy ( V_5 -> V_90 , V_68 -> V_90 , V_104 ) ;
V_5 -> V_92 = V_68 -> V_92 ;
V_5 -> V_91 = V_68 -> V_91 ;
F_13 ( L_55 ) ;
V_105 = F_63 ( L_56 , NULL ) ;
if ( F_64 ( V_105 ) ) {
F_4 ( L_57 ) ;
V_105 = NULL ;
return - V_31 ;
}
F_65 ( L_58 , V_106 , V_105 ,
V_5 , & V_107 ) ;
F_65 ( L_59 , V_106 , V_105 ,
V_5 , & V_108 ) ;
F_13 ( L_60 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_93 )
{
struct V_67 * V_68 = V_93 -> V_48 . V_69 ;
struct V_4 * V_5 ;
V_5 = F_45 ( & V_93 -> V_48 ) ;
F_67 ( V_68 -> V_102 ) ;
F_13 ( L_61 ) ;
F_68 ( V_105 ) ;
F_69 ( & V_93 -> V_48 . V_75 , & V_103 ) ;
F_13 ( L_62 ) ;
V_5 -> V_47 = NULL ;
F_70 ( V_5 -> V_30 ) ;
F_71 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
int F_72 ( struct V_1 * V_93 , T_3 V_109 )
{
struct V_67 * V_68 = V_93 -> V_48 . V_69 ;
if ( V_68 -> V_110 )
return V_68 -> V_110 ( V_93 , V_109 ) ;
return - V_111 ;
}
int F_73 ( struct V_1 * V_93 )
{
struct V_67 * V_68 = V_93 -> V_48 . V_69 ;
if ( V_68 -> V_112 )
return V_68 -> V_112 ( V_93 ) ;
return - V_111 ;
}
