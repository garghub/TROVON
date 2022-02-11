static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , V_5 , V_4 -> V_6 ) ;
V_2 -> V_7 [ V_4 -> V_6 ] = V_4 ;
V_2 -> V_8 [ V_4 -> V_6 ] = true ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_9 )
{
F_2 ( L_1 , V_5 , V_9 -> V_6 ) ;
V_2 -> V_8 [ V_9 -> V_6 ] = false ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
if ( F_5 ( V_2 == NULL || V_2 -> V_11 == NULL ) ) {
F_6 ( L_2 ) ;
return - 1 ;
}
V_11 = V_2 -> V_11 ;
return V_11 -> V_12 -> V_13 ( V_11 ) ;
}
int F_7 ( struct V_1 * V_2 ,
const unsigned char * V_14 , int V_15 )
{
struct V_10 * V_11 ;
if ( F_5 ( V_2 == NULL || V_2 -> V_11 == NULL ) ) {
F_6 ( L_2 ) ;
return - V_16 ;
}
V_11 = V_2 -> V_11 ;
#ifdef F_8
F_9 ( V_17 , L_3 , V_18 ,
16 , 1 , V_14 , V_15 , 0 ) ;
#endif
return V_11 -> V_12 -> V_19 ( V_11 , V_14 , V_15 ) ;
}
static void F_10 ( unsigned char V_6 , struct V_1 * V_2 )
{
F_11 ( L_4 , V_5 , V_6 ) ;
if ( F_5
( V_2 == NULL || V_2 -> V_20 == NULL
|| V_2 -> V_8 [ V_6 ] == false ) ) {
F_6 ( L_5 ,
V_6 ) ;
F_12 ( V_2 -> V_20 ) ;
return;
}
if ( F_13 ( V_2 -> V_7 [ V_6 ] -> V_21 != NULL ) ) {
if ( F_5
( V_2 -> V_7 [ V_6 ] -> V_21
( V_2 -> V_7 [ V_6 ] -> V_22 , V_2 -> V_20 )
!= 0 ) ) {
F_6 ( L_6 , V_6 ) ;
F_12 ( V_2 -> V_20 ) ;
return;
}
} else {
F_6 ( L_7 , V_6 ) ;
F_12 ( V_2 -> V_20 ) ;
}
return;
}
static void F_14 ( struct V_1 * V_2 , char V_23 )
{
unsigned char V_24 = 0 ;
F_2 ( L_8 , V_5 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( F_13 ( V_2 != NULL &&
V_2 -> V_8 [ V_24 ] == true &&
V_2 -> V_7 [ V_24 ] -> V_26 != NULL ) ) {
V_2 -> V_7 [ V_24 ] -> V_26
( V_2 -> V_7 [ V_24 ] -> V_22 , V_23 ) ;
F_2 ( L_9 , V_24 , V_23 ) ;
if ( V_23 ) {
V_2 -> V_8 [ V_24 ] = false ;
if ( V_2 -> V_27 )
V_2 -> V_27 -- ;
}
}
}
}
static inline int F_15 ( struct V_1 * V_2 ,
unsigned char V_6 , int V_28 )
{
int V_29 = F_16 ( V_2 -> V_20 ) ;
F_11 ( L_10 , V_28 , V_29 ) ;
if ( ! V_28 ) {
F_10 ( V_6 , V_2 ) ;
} else if ( V_28 > V_29 ) {
F_6 ( L_11 , V_28 ,
V_29 ) ;
F_12 ( V_2 -> V_20 ) ;
} else {
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = V_28 ;
return V_28 ;
}
V_2 -> V_30 = V_33 ;
V_2 -> V_20 = NULL ;
V_2 -> V_32 = 0 ;
V_2 -> V_34 = 0 ;
return 0 ;
}
static inline void F_17 ( struct V_1 * V_2 ,
unsigned char V_35 )
{
struct V_36 * V_37 ;
unsigned long V_38 = 0 ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
while ( ( V_37 = F_19 ( & V_2 -> V_40 ) ) )
F_20 ( & V_2 -> V_41 , V_37 ) ;
F_21 ( V_2 , ( unsigned long ) V_35 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_23 ( V_2 ) ;
}
void F_24 ( void * V_42 ,
const unsigned char * V_14 , long V_15 )
{
char * V_43 ;
struct V_3 * V_9 ;
unsigned short V_44 = 0 ;
int V_28 = 0 ;
unsigned char type = 0 ;
unsigned char * V_45 ;
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
unsigned long V_38 ;
V_43 = ( char * ) V_14 ;
if ( F_5 ( V_43 == NULL ) || ( V_2 == NULL ) ) {
F_6 ( L_12 ) ;
return;
}
F_11 ( L_13
L_14 , V_15 , V_2 -> V_30 ,
V_2 -> V_32 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
while ( V_15 ) {
if ( V_2 -> V_32 ) {
V_28 = F_25 (unsigned int, st_gdata->rx_count, count) ;
memcpy ( F_26 ( V_2 -> V_20 , V_28 ) , V_43 , V_28 ) ;
V_2 -> V_32 -= V_28 ;
V_15 -= V_28 ;
V_43 += V_28 ;
if ( V_2 -> V_32 )
continue;
switch ( V_2 -> V_30 ) {
case V_31 :
F_11 ( L_15 ) ;
F_10 ( V_2 -> V_34 , V_2 ) ;
V_2 -> V_30 = V_33 ;
V_2 -> V_20 = NULL ;
continue;
case V_46 :
V_9 = V_2 -> V_7 [ V_2 -> V_34 ] ;
V_45 =
& V_2 -> V_20 -> V_14
[ V_9 -> V_47 ] ;
F_11 ( L_16 , * V_45 ) ;
if ( V_9 -> V_48 == 1 )
V_44 = * ( unsigned char * ) V_45 ;
else if ( V_9 -> V_48 == 2 )
V_44 =
F_27 ( * ( unsigned short * ) V_45 ) ;
else
F_2 ( L_17
L_18 ,
V_5 , V_9 -> V_6 ) ;
F_15 ( V_2 , V_9 -> V_6 ,
V_44 ) ;
F_11 ( L_19 ,
V_9 -> V_47 , V_44 ) ;
continue;
}
}
switch ( * V_43 ) {
case V_49 :
case V_50 :
case V_51 :
F_11 ( L_20 ) ;
F_21 ( V_2 , * V_43 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
if ( F_28 ( V_2 ) == V_52 )
F_17 ( V_2 , V_53 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_43 ++ ;
V_15 -- ;
continue;
case V_53 :
F_11 ( L_20 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_17 ( V_2 , * V_43 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_43 ++ ;
V_15 -- ;
continue;
default:
type = * V_43 ;
if ( ( type >= V_25 ) ||
( V_2 -> V_7 [ type ] == NULL ) ) {
F_6 ( L_21
L_22
L_23 , type ) ;
goto V_54;
}
V_2 -> V_20 = F_29 (
V_2 -> V_7 [ type ] -> V_55 ,
V_56 ) ;
if ( V_2 -> V_20 == NULL ) {
F_6 ( L_24 ) ;
goto V_54;
}
F_30 ( V_2 -> V_20 ,
V_2 -> V_7 [ type ] -> V_57 ) ;
V_2 -> V_20 -> V_58 [ 0 ] = type ;
V_2 -> V_20 -> V_58 [ 1 ] = 0 ;
V_2 -> V_34 = * V_43 ;
V_2 -> V_30 = V_46 ;
V_2 -> V_32 = V_2 -> V_7 [ type ] -> V_59 ;
F_11 ( L_25 , V_2 -> V_32 ) ;
} ;
V_43 ++ ;
V_15 -- ;
}
V_54:
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_11 ( L_26 , V_5 ) ;
return;
}
static struct V_36 * F_31 ( struct V_1 * V_2 )
{
struct V_36 * V_60 ;
F_11 ( L_27 , V_5 ) ;
if ( V_2 -> V_61 != NULL ) {
V_60 = V_2 -> V_61 ;
V_2 -> V_61 = NULL ;
return V_60 ;
}
return F_19 ( & V_2 -> V_41 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_36 * V_62 )
{
unsigned long V_38 = 0 ;
F_11 ( L_27 , V_5 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
switch ( F_28 ( V_2 ) ) {
case V_52 :
F_11 ( L_28 ) ;
F_20 ( & V_2 -> V_41 , V_62 ) ;
break;
case V_63 :
F_20 ( & V_2 -> V_40 , V_62 ) ;
break;
case V_64 :
F_6 ( L_29
L_30 , F_28 ( V_2 ) ) ;
F_12 ( V_62 ) ;
break;
case V_65 :
F_20 ( & V_2 -> V_40 , V_62 ) ;
F_33 ( V_2 ) ;
break;
default:
F_6 ( L_29
L_30 , F_28 ( V_2 ) ) ;
F_12 ( V_62 ) ;
break;
}
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_11 ( L_26 , V_5 ) ;
return;
}
static void F_34 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_35 ( V_67 , struct V_1 ,
V_68 ) ;
F_23 ( ( void * ) V_2 ) ;
}
void F_23 ( struct V_1 * V_69 )
{
struct V_36 * V_62 ;
unsigned long V_38 ;
F_11 ( L_27 , V_5 ) ;
if ( F_36 ( V_70 , & V_69 -> V_71 ) ) {
F_11 ( L_31 ) ;
F_37 ( V_72 , & V_69 -> V_71 ) ;
return;
}
do {
F_38 ( V_72 , & V_69 -> V_71 ) ;
while ( ( V_62 = F_31 ( V_69 ) ) ) {
int V_28 ;
F_18 ( & V_69 -> V_39 , V_38 ) ;
F_37 ( V_73 , & V_69 -> V_11 -> V_38 ) ;
V_28 = F_7 ( V_69 , V_62 -> V_14 , V_62 -> V_28 ) ;
F_39 ( V_62 , V_28 ) ;
if ( V_62 -> V_28 ) {
V_69 -> V_61 = V_62 ;
F_22 ( & V_69 -> V_39 , V_38 ) ;
break;
}
F_12 ( V_62 ) ;
F_22 ( & V_69 -> V_39 , V_38 ) ;
}
} while ( F_40 ( V_72 , & V_69 -> V_71 ) );
F_38 ( V_70 , & V_69 -> V_71 ) ;
}
void F_41 ( struct V_1 * V_2 , void * V_74 )
{
F_42 ( V_74 , L_32 ,
V_2 -> V_27 ,
V_2 -> V_8 [ 0x04 ] == true ? 'R' : 'U' ,
V_2 -> V_8 [ 0x08 ] == true ? 'R' : 'U' ,
V_2 -> V_8 [ 0x09 ] == true ? 'R' : 'U' ) ;
}
long F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
long V_23 = 0 ;
unsigned long V_38 = 0 ;
F_44 ( & V_2 , 0 ) ;
if ( V_2 == NULL || V_4 == NULL || V_4 -> V_21 == NULL
|| V_4 -> V_26 == NULL ) {
F_6 ( L_33 ) ;
return - V_16 ;
}
if ( V_4 -> V_6 >= V_25 ) {
F_6 ( L_34 , V_4 -> V_6 ) ;
return - V_75 ;
}
if ( V_2 -> V_8 [ V_4 -> V_6 ] == true ) {
F_6 ( L_35 , V_4 -> V_6 ) ;
return - V_76 ;
}
F_18 ( & V_2 -> V_39 , V_38 ) ;
if ( F_40 ( V_77 , & V_2 -> V_78 ) ) {
F_2 ( L_36 , V_4 -> V_6 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_27 ++ ;
V_4 -> V_19 = V_79 ;
F_37 ( V_80 , & V_2 -> V_78 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
return - V_81 ;
} else if ( V_2 -> V_27 == V_82 ) {
F_2 ( L_37 , V_4 -> V_6 ) ;
F_37 ( V_77 , & V_2 -> V_78 ) ;
V_83 = V_84 ;
F_45 ( V_2 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
V_23 = F_46 ( V_2 -> V_85 ) ;
if ( V_23 != 0 ) {
F_38 ( V_77 , & V_2 -> V_78 ) ;
if ( ( V_2 -> V_27 != V_82 ) &&
( F_40 ( V_80 , & V_2 -> V_78 ) ) ) {
F_6 ( L_38 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
F_14 ( V_2 , V_23 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_38 ( V_80 , & V_2 -> V_78 ) ;
}
return - V_16 ;
}
F_18 ( & V_2 -> V_39 , V_38 ) ;
F_38 ( V_77 , & V_2 -> V_78 ) ;
V_83 = F_24 ;
if ( ( V_2 -> V_27 != V_82 ) &&
( F_40 ( V_80 , & V_2 -> V_78 ) ) ) {
F_11 ( L_39 ) ;
F_14 ( V_2 , 0 ) ;
}
F_38 ( V_80 , & V_2 -> V_78 ) ;
if ( V_2 -> V_8 [ V_4 -> V_6 ] == true ) {
F_6 ( L_40 ,
V_4 -> V_6 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
return - V_76 ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_27 ++ ;
V_4 -> V_19 = V_79 ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
return V_23 ;
}
else {
F_1 ( V_2 , V_4 ) ;
V_2 -> V_27 ++ ;
V_4 -> V_19 = V_79 ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
return V_23 ;
}
F_11 ( L_41 , V_5 , V_4 -> V_6 ) ;
}
long F_47 ( struct V_3 * V_9 )
{
long V_23 = 0 ;
unsigned long V_38 = 0 ;
struct V_1 * V_2 ;
F_11 ( L_42 , V_5 , V_9 -> V_6 ) ;
F_44 ( & V_2 , 0 ) ;
if ( ! V_2 || V_9 -> V_6 >= V_25 ) {
F_6 ( L_43 , V_9 -> V_6 ) ;
return - V_75 ;
}
F_18 ( & V_2 -> V_39 , V_38 ) ;
if ( V_2 -> V_8 [ V_9 -> V_6 ] == false ) {
F_6 ( L_44 , V_9 -> V_6 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
return - V_75 ;
}
if ( V_2 -> V_27 )
V_2 -> V_27 -- ;
F_3 ( V_2 , V_9 ) ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
if ( ( V_2 -> V_27 == V_82 ) &&
( ! F_40 ( V_80 , & V_2 -> V_78 ) ) ) {
F_2 ( L_45 ) ;
if ( V_2 -> V_11 ) {
F_48 ( V_2 -> V_11 ) ;
F_49 ( V_2 -> V_11 ) ;
}
F_50 ( V_2 -> V_85 ) ;
F_51 ( V_2 ) ;
}
return V_23 ;
}
long V_79 ( struct V_36 * V_62 )
{
struct V_1 * V_2 ;
long V_28 ;
F_44 ( & V_2 , 0 ) ;
if ( F_5 ( V_62 == NULL || V_2 == NULL
|| V_2 -> V_11 == NULL ) ) {
F_6 ( L_46 ) ;
return - V_16 ;
}
F_11 ( L_47 , V_62 -> V_28 ) ;
V_28 = V_62 -> V_28 ;
F_32 ( V_2 , V_62 ) ;
F_23 ( V_2 ) ;
return V_28 ;
}
static int F_52 ( struct V_10 * V_11 )
{
int V_23 = 0 ;
struct V_1 * V_2 ;
F_2 ( L_48 , V_5 ) ;
F_44 ( & V_2 , 0 ) ;
V_2 -> V_11 = V_11 ;
V_11 -> V_42 = V_2 ;
F_38 ( V_73 , & V_11 -> V_38 ) ;
V_11 -> V_86 = 65536 ;
F_48 ( V_11 ) ;
F_53 ( V_11 ) ;
F_54 ( V_2 -> V_85 ) ;
F_11 ( L_26 , V_5 ) ;
return V_23 ;
}
static void F_55 ( struct V_10 * V_11 )
{
unsigned char V_24 = V_25 ;
unsigned long V_38 = 0 ;
struct V_1 * V_2 = V_11 -> V_42 ;
F_2 ( L_48 , V_5 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
for ( V_24 = V_87 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_2 -> V_8 [ V_24 ] == true )
F_6 ( L_49 , V_24 ) ;
V_2 -> V_7 [ V_24 ] = NULL ;
V_2 -> V_8 [ V_24 ] = false ;
}
V_2 -> V_27 = 0 ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_54 ( V_2 -> V_85 ) ;
V_2 -> V_11 = NULL ;
F_48 ( V_11 ) ;
F_53 ( V_11 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
F_56 ( & V_2 -> V_41 ) ;
F_56 ( & V_2 -> V_40 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_30 = V_33 ;
F_12 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
F_22 ( & V_2 -> V_39 , V_38 ) ;
F_11 ( L_50 , V_5 ) ;
}
static void F_57 ( struct V_10 * V_11 , const unsigned char * V_14 ,
char * V_88 , int V_15 )
{
#ifdef F_8
F_9 ( V_17 , L_51 , V_18 ,
16 , 1 , V_14 , V_15 , 0 ) ;
#endif
V_83 ( V_11 -> V_42 , V_14 , V_15 ) ;
F_11 ( L_26 , V_5 ) ;
}
static void F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_42 ;
F_11 ( L_48 , V_5 ) ;
F_38 ( V_73 , & V_11 -> V_38 ) ;
F_59 ( & V_2 -> V_68 ) ;
}
static void F_60 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_42 ;
F_11 ( L_48 , V_5 ) ;
F_12 ( V_2 -> V_61 ) ;
V_2 -> V_61 = NULL ;
F_53 ( V_11 ) ;
return;
}
int F_61 ( struct V_1 * * V_89 )
{
struct V_1 * V_2 ;
long V_23 ;
V_23 = F_62 ( V_90 , & V_91 ) ;
if ( V_23 ) {
F_6 ( L_52 ,
V_90 , V_23 ) ;
return V_23 ;
}
F_11 ( L_53 ) ;
V_2 = F_63 ( sizeof( struct V_1 ) , V_92 ) ;
if ( ! V_2 ) {
F_6 ( L_54 ) ;
V_23 = F_64 ( V_90 ) ;
if ( V_23 )
F_6 ( L_55 , V_23 ) ;
V_23 = - V_93 ;
return V_23 ;
}
F_65 ( & V_2 -> V_41 ) ;
F_65 ( & V_2 -> V_40 ) ;
F_66 ( & V_2 -> V_39 ) ;
V_23 = F_67 ( V_2 ) ;
if ( V_23 ) {
F_6 ( L_56 , V_23 ) ;
F_68 ( V_2 ) ;
V_23 = F_64 ( V_90 ) ;
if ( V_23 )
F_6 ( L_57 ) ;
return V_23 ;
}
F_69 ( & V_2 -> V_68 , F_34 ) ;
* V_89 = V_2 ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
long V_23 ;
V_23 = F_71 ( V_2 ) ;
if ( V_23 )
F_6 ( L_58 , V_23 ) ;
if ( V_2 != NULL ) {
F_56 ( & V_2 -> V_41 ) ;
F_56 ( & V_2 -> V_40 ) ;
F_12 ( V_2 -> V_20 ) ;
F_12 ( V_2 -> V_61 ) ;
V_23 = F_64 ( V_90 ) ;
if ( V_23 )
F_6 ( L_55 , V_23 ) ;
F_68 ( V_2 ) ;
}
}
