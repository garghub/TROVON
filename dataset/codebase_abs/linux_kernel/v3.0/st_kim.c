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
return;
}
F_5 ( & V_5 -> V_10 ) ;
F_6 ( V_7 ) ;
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
F_6 ( V_5 -> V_8 ) ;
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
V_42 = & ( ( (struct V_38 * ) V_18 ) -> V_9 [ 0 ] ) ;
if ( F_3
( ( (struct V_52 * ) V_42 ) -> V_53 ==
0xFF36 ) ) {
F_23 ( L_19
L_20 ) ;
F_22 ( & V_18 , & V_11 ) ;
break;
}
V_44 = ( (struct V_38 * ) V_18 ) -> V_39 ;
V_45 = V_54 + F_20 ( V_55 ) ;
do {
V_43 =
F_26 ( V_5 -> V_30 ) ;
if ( V_43 < 0 ) {
F_4 ( L_21
L_22 ) ;
F_27 ( V_5 -> V_46 ) ;
return V_43 ;
}
F_28 ( 1 ) ;
} while ( ( V_43 < V_44 ) &&
F_29 ( V_54 , V_45 ) );
if ( F_30 ( V_54 , V_45 ) ) {
F_4 ( L_23
L_24 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_33 ;
}
V_41 = F_18 ( V_5 -> V_30 ,
( (struct V_56 * ) V_42 ) -> V_9 ,
( (struct V_38 * ) V_18 ) -> V_39 ) ;
if ( F_3 ( V_41 < 0 ) ) {
F_27 ( V_5 -> V_46 ) ;
return V_41 ;
}
if ( V_41 != V_44 ) {
F_4 ( L_25
L_26
L_27 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_31 ;
}
break;
case V_40 :
if ( ! F_19
( & V_5 -> V_10 ,
F_20 ( V_32 ) ) ) {
F_4 ( L_28 ) ;
F_27 ( V_5 -> V_46 ) ;
return - V_33 ;
}
F_17 ( V_5 -> V_10 ) ;
break;
case V_57 :
F_13 ( L_29 ) ;
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
F_5 ( & V_5 -> V_10 ) ;
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
struct V_4 * V_5 = (struct V_4 * ) V_63 ;
F_13 ( L_30 , V_20 ) ;
do {
F_35 ( V_5 -> V_67 , V_68 ) ;
F_28 ( 5 ) ;
F_35 ( V_5 -> V_67 , V_69 ) ;
F_28 ( 100 ) ;
F_17 ( V_5 -> V_64 ) ;
V_5 -> V_70 = 1 ;
F_13 ( L_31 ) ;
F_36 ( & V_5 -> V_47 -> V_48 . V_71 ,
NULL , L_32 ) ;
V_41 = F_19 ( & V_5 -> V_64 ,
F_20 ( V_72 ) ) ;
if ( ! V_41 ) {
F_4 ( L_33 ) ;
V_5 -> V_70 = 0 ;
F_13 ( L_34 ) ;
F_36 ( & V_5 -> V_47 -> V_48 . V_71 ,
NULL , L_32 ) ;
V_41 = - V_33 ;
continue;
} else {
F_13 ( L_35 ) ;
V_41 = F_24 ( V_5 ) ;
if ( V_41 != 0 ) {
F_4 ( L_36 ) ;
V_5 -> V_70 = 0 ;
F_13 ( L_34 ) ;
F_36 ( & V_5 -> V_47 -> V_48 . V_71 ,
NULL , L_32 ) ;
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
F_17 ( V_5 -> V_64 ) ;
F_38 ( V_5 -> V_30 -> V_73 ) ;
F_39 ( V_5 -> V_30 -> V_73 ) ;
F_13 ( L_34 ) ;
V_5 -> V_70 = 0 ;
F_36 ( & V_5 -> V_47 -> V_48 . V_71 , NULL , L_32 ) ;
V_41 = F_19 ( & V_5 -> V_64 ,
F_20 ( V_72 ) ) ;
if ( ! V_41 ) {
F_4 ( L_37 ) ;
return - V_33 ;
}
F_35 ( V_5 -> V_67 , V_68 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_67 , V_69 ) ;
F_28 ( 1 ) ;
F_35 ( V_5 -> V_67 , V_68 ) ;
return V_41 ;
}
static int F_40 ( struct V_74 * V_75 , void * V_76 )
{
struct V_4 * V_5 = (struct V_4 * ) V_75 -> V_77 ;
F_41 ( V_75 , L_38 , V_5 -> V_25 . V_35 ,
V_5 -> V_25 . V_26 , V_5 -> V_25 . V_28 ,
V_5 -> V_25 . V_27 ) ;
return 0 ;
}
static int F_42 ( struct V_74 * V_75 , void * V_76 )
{
struct V_4 * V_5 = (struct V_4 * ) V_75 -> V_77 ;
F_43 ( V_5 -> V_30 , V_75 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_78 * V_48 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_81 , L_39 , V_63 -> V_70 ) ;
}
static T_1 F_46 ( struct V_78 * V_48 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_81 , L_40 , V_63 -> V_82 ) ;
}
static T_1 F_47 ( struct V_78 * V_48 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_81 , L_41 , V_63 -> V_83 ) ;
}
static T_1 F_48 ( struct V_78 * V_48 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_4 * V_63 = F_45 ( V_48 ) ;
return sprintf ( V_81 , L_39 , V_63 -> V_84 ) ;
}
void F_49 ( struct V_61 * * V_30 , int V_2 )
{
struct V_1 * V_85 ;
struct V_4 * V_5 ;
V_85 = F_1 ( V_2 ) ;
if ( ! V_85 ) {
* V_30 = NULL ;
return;
}
V_5 = F_45 ( & V_85 -> V_48 ) ;
* V_30 = V_5 -> V_30 ;
}
static int F_50 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
return F_51 ( V_89 , F_40 , V_87 -> V_90 ) ;
}
static int F_52 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
return F_51 ( V_89 , F_42 , V_87 -> V_90 ) ;
}
static int F_53 ( struct V_1 * V_85 )
{
long V_91 ;
struct V_4 * V_5 ;
struct V_92 * V_93 = V_85 -> V_48 . V_94 ;
if ( ( V_85 -> V_2 != - 1 ) && ( V_85 -> V_2 < V_95 ) ) {
V_3 [ V_85 -> V_2 ] = V_85 ;
} else {
V_3 [ 0 ] = V_85 ;
}
V_5 = F_54 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 ) {
F_4 ( L_42 ) ;
return - V_96 ;
}
F_55 ( & V_85 -> V_48 , V_5 ) ;
V_91 = F_56 ( & V_5 -> V_30 ) ;
if ( V_91 != 0 ) {
F_4 ( L_43 ) ;
return - V_31 ;
}
V_5 -> V_30 -> V_63 = V_5 ;
V_5 -> V_67 = V_93 -> V_97 ;
V_91 = F_57 ( V_5 -> V_67 , L_44 ) ;
if ( F_3 ( V_91 ) ) {
F_4 ( L_45 , V_5 -> V_67 ) ;
return V_91 ;
}
V_91 = F_58 ( V_5 -> V_67 , 0 ) ;
if ( F_3 ( V_91 ) ) {
F_4 ( L_46 , V_5 -> V_67 ) ;
return V_91 ;
}
V_5 -> V_47 = V_85 ;
F_59 ( & V_5 -> V_10 ) ;
F_59 ( & V_5 -> V_64 ) ;
V_91 = F_60 ( & V_85 -> V_48 . V_71 , & V_98 ) ;
if ( V_91 ) {
F_4 ( L_47 ) ;
return V_91 ;
}
strncpy ( V_5 -> V_82 , V_93 -> V_82 , V_99 ) ;
V_5 -> V_84 = V_93 -> V_84 ;
V_5 -> V_83 = V_93 -> V_83 ;
F_13 ( L_48 ) ;
V_100 = F_61 ( L_49 , NULL ) ;
if ( F_62 ( V_100 ) ) {
F_4 ( L_50 ) ;
V_100 = NULL ;
return - V_31 ;
}
F_63 ( L_51 , V_101 , V_100 ,
V_5 , & V_102 ) ;
F_63 ( L_52 , V_101 , V_100 ,
V_5 , & V_103 ) ;
F_13 ( L_53 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_85 )
{
struct V_92 * V_93 = V_85 -> V_48 . V_94 ;
struct V_4 * V_5 ;
V_5 = F_45 ( & V_85 -> V_48 ) ;
F_65 ( V_93 -> V_97 ) ;
F_13 ( L_54 ) ;
F_66 ( V_100 ) ;
F_67 ( & V_85 -> V_48 . V_71 , & V_98 ) ;
F_13 ( L_55 ) ;
V_5 -> V_47 = NULL ;
F_68 ( V_5 -> V_30 ) ;
F_69 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
int F_70 ( struct V_1 * V_85 , T_2 V_104 )
{
struct V_92 * V_93 = V_85 -> V_48 . V_94 ;
if ( V_93 -> V_105 )
return V_93 -> V_105 ( V_85 , V_104 ) ;
return - V_106 ;
}
int F_71 ( struct V_1 * V_85 )
{
struct V_92 * V_93 = V_85 -> V_48 . V_94 ;
if ( V_93 -> V_107 )
return V_93 -> V_107 ( V_85 ) ;
return - V_106 ;
}
static int T_3 F_72 ( void )
{
return F_73 ( & V_108 ) ;
}
static void T_4 F_74 ( void )
{
F_75 ( & V_108 ) ;
}
