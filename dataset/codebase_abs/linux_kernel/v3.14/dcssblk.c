static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 , * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 (entry, temp, &dev_info->seg_list, lh) {
F_4 ( & V_6 -> V_8 ) ;
F_5 ( V_6 ) ;
}
F_5 ( V_4 ) ;
F_6 ( V_9 ) ;
}
static int
F_7 ( struct V_3 * V_4 )
{
int V_10 , V_11 ;
struct V_3 * V_6 ;
if ( V_4 == NULL )
return - V_12 ;
for ( V_10 = 0 ; V_10 < ( 1 << V_13 ) ; V_10 ++ ) {
V_11 = 0 ;
F_8 (entry, &dcssblk_devices, lh)
if ( V_10 == V_6 -> V_14 -> V_15 )
V_11 ++ ;
if ( ! V_11 ) break;
}
if ( V_11 )
return - V_16 ;
V_4 -> V_14 -> V_15 = V_10 ;
return 0 ;
}
static struct V_3 *
F_9 ( char * V_17 )
{
struct V_3 * V_6 ;
F_8 (entry, &dcssblk_devices, lh) {
if ( ! strcmp ( V_17 , V_6 -> V_18 ) ) {
return V_6 ;
}
}
return NULL ;
}
static struct V_5 *
F_10 ( char * V_17 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_8 (dev_info, &dcssblk_devices, lh) {
F_8 (entry, &dev_info->seg_list, lh) {
if ( ! strcmp ( V_17 , V_6 -> V_18 ) )
return V_6 ;
}
}
return NULL ;
}
static unsigned long
F_11 ( struct V_3 * V_4 )
{
unsigned long V_19 ;
struct V_5 * V_6 ;
V_19 = 0 ;
F_8 (entry, &dev_info->seg_list, lh) {
if ( V_19 < V_6 -> V_20 )
V_19 = V_6 -> V_20 ;
}
return V_19 ;
}
static unsigned long
F_12 ( struct V_3 * V_4 )
{
int V_21 ;
unsigned long V_22 ;
struct V_5 * V_6 ;
V_21 = 0 ;
V_22 = 0 ;
F_8 (entry, &dev_info->seg_list, lh) {
if ( V_21 == 0 ) {
V_22 = V_6 -> V_23 ;
V_21 = 1 ;
} else {
if ( V_22 > V_6 -> V_23 )
V_22 = V_6 -> V_23 ;
}
}
return V_22 ;
}
static int
F_13 ( struct V_3 * V_4 )
{
int V_24 , V_25 , V_26 ;
struct V_5 * V_27 , * V_6 , V_7 ;
if ( V_4 -> V_28 <= 1 )
return 0 ;
V_27 = F_14 (
sizeof( struct V_5 ) * V_4 -> V_28 ,
V_29 ) ;
if ( V_27 == NULL )
return - V_30 ;
V_24 = 0 ;
F_8 (entry, &dev_info->seg_list, lh) {
memcpy ( & V_27 [ V_24 ] , V_6 , sizeof( struct V_5 ) ) ;
V_24 ++ ;
}
for ( V_24 = 0 ; V_24 < V_4 -> V_28 ; V_24 ++ )
for ( V_25 = 0 ; V_25 < V_4 -> V_28 ; V_25 ++ )
if ( V_27 [ V_25 ] . V_23 > V_27 [ V_24 ] . V_23 ) {
memcpy ( & V_7 , & V_27 [ V_24 ] ,
sizeof( struct V_5 ) ) ;
memcpy ( & V_27 [ V_24 ] , & V_27 [ V_25 ] ,
sizeof( struct V_5 ) ) ;
memcpy ( & V_27 [ V_25 ] , & V_7 ,
sizeof( struct V_5 ) ) ;
}
for ( V_24 = 0 ; V_24 < V_4 -> V_28 - 1 ; V_24 ++ ) {
if ( ( V_27 [ V_24 ] . V_20 + 1 ) != V_27 [ V_24 + 1 ] . V_23 ) {
F_15 ( L_1
L_2 , V_27 [ V_24 ] . V_18 ,
V_27 [ V_24 + 1 ] . V_18 ) ;
V_26 = - V_12 ;
goto V_31;
}
if ( V_27 [ V_24 ] . V_32 != V_27 [ V_24 + 1 ] . V_32 ) {
if ( ! ( V_27 [ V_24 ] . V_32 & V_33 ) ||
( V_27 [ V_24 ] . V_32 == V_34 ) ||
! ( V_27 [ V_24 + 1 ] . V_32 &
V_33 ) ||
( V_27 [ V_24 + 1 ] . V_32 == V_34 ) ) {
F_15 ( L_3
L_4 ,
V_27 [ V_24 ] . V_18 ,
V_27 [ V_24 + 1 ] . V_18 ) ;
V_26 = - V_12 ;
goto V_31;
}
}
}
V_26 = 0 ;
V_31:
F_5 ( V_27 ) ;
return V_26 ;
}
static int
F_16 ( char * V_17 , struct V_5 * * V_35 )
{
int V_26 ;
F_17 ( & V_36 ) ;
* V_35 = F_10 ( V_17 ) ;
F_18 ( & V_36 ) ;
if ( * V_35 != NULL )
return - V_37 ;
* V_35 = F_14 ( sizeof( struct V_5 ) , V_29 ) ;
if ( * V_35 == NULL )
return - V_30 ;
strcpy ( ( * V_35 ) -> V_18 , V_17 ) ;
V_26 = F_19 ( V_17 , V_38 ,
& ( * V_35 ) -> V_23 , & ( * V_35 ) -> V_20 ) ;
if ( V_26 < 0 ) {
F_20 ( V_26 , ( * V_35 ) -> V_18 ) ;
F_5 ( * V_35 ) ;
} else {
F_21 ( & ( * V_35 ) -> V_8 ) ;
( * V_35 ) -> V_32 = V_26 ;
}
return V_26 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_39 * V_40 , char * V_41 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
return sprintf ( V_41 , V_4 -> V_42 ? L_5 : L_6 ) ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_39 * V_40 , const char * V_43 , T_2 V_44 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 , * V_7 ;
int V_26 ;
if ( ( V_44 > 1 ) && ( V_43 [ 1 ] != '\n' ) && ( V_43 [ 1 ] != '\0' ) )
return - V_12 ;
F_27 ( & V_36 ) ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( F_28 ( & V_4 -> V_45 ) ) {
V_26 = - V_16 ;
goto V_31;
}
if ( V_43 [ 0 ] == '1' ) {
F_8 (entry, &dev_info->seg_list, lh) {
V_26 = F_29 ( V_6 -> V_18 ,
V_38 ) ;
if ( V_26 < 0 ) {
F_30 ( V_26 == - V_12 ) ;
if ( V_26 != - V_46 )
goto V_47;
}
}
V_4 -> V_42 = 1 ;
switch ( V_4 -> V_32 ) {
case V_48 :
case V_34 :
case V_49 :
F_31 ( V_4 -> V_14 , 1 ) ;
}
} else if ( V_43 [ 0 ] == '0' ) {
if ( V_4 -> V_32 == V_49 ) {
F_15 ( L_7
L_8 ,
V_4 -> V_18 ) ;
V_26 = - V_12 ;
goto V_31;
}
F_8 (entry, &dev_info->seg_list, lh) {
V_26 = F_29 ( V_6 -> V_18 ,
V_33 ) ;
if ( V_26 < 0 ) {
F_30 ( V_26 == - V_12 ) ;
if ( V_26 != - V_46 )
goto V_47;
}
}
V_4 -> V_42 = 0 ;
F_31 ( V_4 -> V_14 , 0 ) ;
} else {
V_26 = - V_12 ;
goto V_31;
}
V_26 = V_44 ;
goto V_31;
V_47:
F_15 ( L_9
L_10 , V_4 -> V_18 ) ;
V_7 = V_6 ;
F_8 (entry, &dev_info->seg_list, lh) {
if ( V_6 != V_7 )
F_32 ( V_6 -> V_18 ) ;
}
F_4 ( & V_4 -> V_8 ) ;
F_33 ( V_4 -> V_14 ) ;
F_34 ( V_4 -> V_50 ) ;
V_4 -> V_14 -> V_51 = NULL ;
F_35 ( V_4 -> V_14 ) ;
V_26 = F_36 ( V_2 , F_22 ) ;
V_31:
F_37 ( & V_36 ) ;
return V_26 ;
}
static T_1
F_38 ( struct V_1 * V_2 , struct V_39 * V_40 , char * V_41 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
return sprintf ( V_41 , V_4 -> V_52 ? L_5 : L_6 ) ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_39 * V_40 , const char * V_43 , T_2 V_44 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ( V_44 > 1 ) && ( V_43 [ 1 ] != '\n' ) && ( V_43 [ 1 ] != '\0' ) )
return - V_12 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_27 ( & V_36 ) ;
if ( V_43 [ 0 ] == '1' ) {
if ( F_28 ( & V_4 -> V_45 ) == 0 ) {
F_40 ( L_11
L_12 , V_4 -> V_18 ) ;
F_8 (entry, &dev_info->seg_list, lh) {
F_41 ( V_6 -> V_18 ) ;
}
} else {
F_40 ( L_13
L_14 ,
V_4 -> V_18 ) ;
V_4 -> V_52 = 1 ;
}
} else if ( V_43 [ 0 ] == '0' ) {
if ( V_4 -> V_52 ) {
V_4 -> V_52 = 0 ;
F_40 ( L_15
L_16 ,
V_4 -> V_18 ) ;
}
} else {
F_37 ( & V_36 ) ;
return - V_12 ;
}
F_37 ( & V_36 ) ;
return V_44 ;
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_39 * V_40 ,
char * V_41 )
{
int V_24 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_17 ( & V_36 ) ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_24 = 0 ;
V_41 [ 0 ] = '\0' ;
F_8 (entry, &dev_info->seg_list, lh) {
strcpy ( & V_41 [ V_24 ] , V_6 -> V_18 ) ;
V_24 += strlen ( V_6 -> V_18 ) ;
V_41 [ V_24 ] = '\n' ;
V_24 ++ ;
}
F_18 ( & V_36 ) ;
return V_24 ;
}
static T_1
F_43 ( struct V_1 * V_2 , struct V_39 * V_40 , const char * V_41 , T_2 V_44 )
{
int V_26 , V_24 , V_25 , V_28 ;
struct V_3 * V_4 ;
struct V_5 * V_35 , * V_7 ;
char * V_53 ;
unsigned long V_54 ;
V_4 = NULL ;
V_35 = NULL ;
if ( V_2 != V_55 ) {
V_26 = - V_12 ;
goto V_56;
}
if ( ( V_44 < 1 ) || ( V_41 [ 0 ] == '\0' ) || ( V_41 [ 0 ] == '\n' ) ) {
V_26 = - V_57 ;
goto V_56;
}
V_53 = F_44 ( V_44 + 1 , V_29 ) ;
if ( V_53 == NULL ) {
V_26 = - V_30 ;
goto V_56;
}
V_28 = 0 ;
for ( V_24 = 0 ; ( ( V_41 [ V_24 ] != '\0' ) && ( V_41 [ V_24 ] != '\n' ) && V_24 < V_44 ) ; V_24 ++ ) {
for ( V_25 = V_24 ; ( V_41 [ V_25 ] != ':' ) &&
( V_41 [ V_25 ] != '\0' ) &&
( V_41 [ V_25 ] != '\n' ) &&
V_25 < V_44 ; V_25 ++ ) {
V_53 [ V_25 - V_24 ] = toupper ( V_41 [ V_25 ] ) ;
}
V_53 [ V_25 - V_24 ] = '\0' ;
if ( ( ( V_25 - V_24 ) == 0 ) || ( ( V_25 - V_24 ) > 8 ) ) {
V_26 = - V_57 ;
goto V_58;
}
V_26 = F_16 ( V_53 , & V_35 ) ;
if ( V_26 < 0 )
goto V_58;
if ( V_28 == 0 ) {
V_4 = F_14 ( sizeof( struct V_3 ) ,
V_29 ) ;
if ( V_4 == NULL ) {
V_26 = - V_30 ;
goto V_31;
}
strcpy ( V_4 -> V_18 , V_53 ) ;
V_4 -> V_32 = V_35 -> V_32 ;
F_21 ( & V_4 -> V_59 ) ;
}
F_45 ( & V_35 -> V_8 , & V_4 -> V_59 ) ;
V_28 ++ ;
V_24 = V_25 ;
if ( ( V_41 [ V_25 ] == '\0' ) || ( V_41 [ V_25 ] == '\n' ) )
break;
}
if ( ( V_24 > 0 ) && ( V_41 [ V_24 - 1 ] == ':' ) ) {
V_26 = - V_57 ;
goto V_58;
}
F_46 ( V_53 , V_41 , V_24 + 1 ) ;
V_4 -> V_28 = V_28 ;
V_26 = F_13 ( V_4 ) ;
if ( V_26 < 0 )
goto V_58;
V_4 -> V_23 = F_12 ( V_4 ) ;
V_4 -> V_20 = F_11 ( V_4 ) ;
F_47 ( & V_4 -> V_2 , V_4 -> V_18 ) ;
V_4 -> V_2 . V_60 = F_1 ;
V_4 -> V_2 . V_61 = V_62 ;
F_21 ( & V_4 -> V_8 ) ;
V_4 -> V_14 = F_48 ( V_63 ) ;
if ( V_4 -> V_14 == NULL ) {
V_26 = - V_30 ;
goto V_58;
}
V_4 -> V_14 -> V_64 = V_65 ;
V_4 -> V_14 -> V_66 = & V_67 ;
V_4 -> V_50 = F_49 ( V_29 ) ;
V_4 -> V_14 -> V_51 = V_4 -> V_50 ;
V_4 -> V_14 -> V_68 = V_4 ;
V_4 -> V_14 -> V_69 = & V_4 -> V_2 ;
F_50 ( V_4 -> V_50 , V_70 ) ;
F_51 ( V_4 -> V_50 , 4096 ) ;
V_54 = ( V_4 -> V_20 - V_4 -> V_23 + 1 ) ;
F_52 ( V_4 -> V_14 , V_54 >> 9 ) ;
F_40 ( L_17
L_18 , V_53 , V_54 , V_54 >> 9 ) ;
V_4 -> V_52 = 0 ;
V_4 -> V_42 = 1 ;
V_4 -> V_2 . V_71 = V_55 ;
F_27 ( & V_36 ) ;
if ( F_10 ( V_53 ) ) {
V_26 = - V_37 ;
goto V_72;
}
V_26 = F_7 ( V_4 ) ;
if ( V_26 )
goto V_72;
sprintf ( V_4 -> V_14 -> V_73 , L_19 ,
V_4 -> V_14 -> V_15 ) ;
F_45 ( & V_4 -> V_8 , & V_74 ) ;
if ( ! F_53 ( V_9 ) ) {
V_26 = - V_75 ;
goto V_76;
}
V_26 = F_54 ( & V_4 -> V_2 ) ;
if ( V_26 )
goto V_77;
F_55 ( & V_4 -> V_2 ) ;
F_56 ( V_4 -> V_14 ) ;
switch ( V_4 -> V_32 ) {
case V_48 :
case V_34 :
case V_49 :
F_31 ( V_4 -> V_14 , 1 ) ;
break;
default:
F_31 ( V_4 -> V_14 , 0 ) ;
break;
}
F_37 ( & V_36 ) ;
V_26 = V_44 ;
goto V_31;
V_77:
F_4 ( & V_4 -> V_8 ) ;
F_34 ( V_4 -> V_50 ) ;
V_4 -> V_14 -> V_51 = NULL ;
F_35 ( V_4 -> V_14 ) ;
F_8 (seg_info, &dev_info->seg_list, lh) {
F_32 ( V_35 -> V_18 ) ;
}
F_24 ( & V_4 -> V_2 ) ;
F_37 ( & V_36 ) ;
goto V_31;
V_76:
F_4 ( & V_4 -> V_8 ) ;
V_72:
F_34 ( V_4 -> V_50 ) ;
V_4 -> V_14 -> V_51 = NULL ;
F_35 ( V_4 -> V_14 ) ;
F_37 ( & V_36 ) ;
V_58:
if ( V_4 == NULL )
goto V_31;
F_3 (seg_info, temp, &dev_info->seg_list, lh) {
F_4 ( & V_35 -> V_8 ) ;
F_32 ( V_35 -> V_18 ) ;
F_5 ( V_35 ) ;
}
F_5 ( V_4 ) ;
V_31:
F_5 ( V_53 ) ;
V_56:
return V_26 ;
}
static T_1
F_57 ( struct V_1 * V_2 , struct V_39 * V_40 , const char * V_41 , T_2 V_44 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_26 , V_24 ;
char * V_53 ;
if ( V_2 != V_55 ) {
return - V_12 ;
}
V_53 = F_44 ( V_44 + 1 , V_29 ) ;
if ( V_53 == NULL ) {
return - V_30 ;
}
for ( V_24 = 0 ; ( ( * ( V_41 + V_24 ) != '\0' ) && ( * ( V_41 + V_24 ) != '\n' ) && V_24 < V_44 ) ; V_24 ++ ) {
V_53 [ V_24 ] = toupper ( V_41 [ V_24 ] ) ;
}
V_53 [ V_24 ] = '\0' ;
if ( ( V_24 == 0 ) || ( V_24 > 8 ) ) {
V_26 = - V_57 ;
goto V_78;
}
F_27 ( & V_36 ) ;
V_4 = F_9 ( V_53 ) ;
if ( V_4 == NULL ) {
F_37 ( & V_36 ) ;
F_58 ( L_20
L_21 , V_53 ) ;
V_26 = - V_75 ;
goto V_78;
}
if ( F_28 ( & V_4 -> V_45 ) != 0 ) {
F_37 ( & V_36 ) ;
F_58 ( L_22
L_23 , V_53 ) ;
V_26 = - V_16 ;
goto V_78;
}
F_4 ( & V_4 -> V_8 ) ;
F_33 ( V_4 -> V_14 ) ;
F_34 ( V_4 -> V_50 ) ;
V_4 -> V_14 -> V_51 = NULL ;
F_35 ( V_4 -> V_14 ) ;
F_23 ( & V_4 -> V_2 ) ;
F_8 (entry, &dev_info->seg_list, lh)
F_32 ( V_6 -> V_18 ) ;
F_24 ( & V_4 -> V_2 ) ;
F_37 ( & V_36 ) ;
V_26 = V_44 ;
V_78:
F_5 ( V_53 ) ;
return V_26 ;
}
static int
F_59 ( struct V_79 * V_80 , T_3 V_81 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = V_80 -> V_82 -> V_68 ;
if ( NULL == V_4 ) {
V_26 = - V_75 ;
goto V_31;
}
F_60 ( & V_4 -> V_45 ) ;
V_80 -> V_83 = 4096 ;
V_26 = 0 ;
V_31:
return V_26 ;
}
static void
F_61 ( struct V_84 * V_85 , T_3 V_81 )
{
struct V_3 * V_4 = V_85 -> V_68 ;
struct V_5 * V_6 ;
if ( ! V_4 ) {
F_62 ( 1 ) ;
return;
}
F_27 ( & V_36 ) ;
if ( F_63 ( & V_4 -> V_45 )
&& ( V_4 -> V_52 ) ) {
F_40 ( L_24
L_25 , V_4 -> V_18 ) ;
F_8 (entry, &dev_info->seg_list, lh) {
F_41 ( V_6 -> V_18 ) ;
}
V_4 -> V_52 = 0 ;
}
F_37 ( & V_36 ) ;
}
static void
V_70 ( struct V_86 * V_87 , struct V_88 * V_88 )
{
struct V_3 * V_4 ;
struct V_89 V_90 ;
struct V_91 V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
V_96 = 0 ;
V_4 = V_88 -> V_97 -> V_82 -> V_68 ;
if ( V_4 == NULL )
goto V_98;
if ( ( V_88 -> V_99 . V_100 & 7 ) != 0 ||
( V_88 -> V_99 . V_101 & 4095 ) != 0 )
goto V_98;
if ( F_64 ( V_88 ) > F_65 ( V_88 -> V_97 -> V_82 ) ) {
goto V_98;
}
if ( V_4 -> V_42 ) {
switch ( V_4 -> V_32 ) {
case V_48 :
case V_34 :
case V_49 :
if ( F_66 ( V_88 ) == V_102 ) {
F_58 ( L_26
L_27 ,
F_67 ( & V_4 -> V_2 ) ) ;
goto V_98;
}
}
}
V_93 = ( V_88 -> V_99 . V_100 >> 3 ) ;
F_68 (bvec, bio, iter) {
V_94 = ( unsigned long )
F_69 ( V_90 . V_103 ) + V_90 . V_104 ;
V_95 = V_4 -> V_23 + ( V_93 << 12 ) + V_96 ;
if ( F_70 ( ( V_94 & 4095 ) != 0 ) || ( V_90 . V_105 & 4095 ) != 0 )
goto V_98;
if ( F_66 ( V_88 ) == V_106 ) {
memcpy ( ( void * ) V_94 , ( void * ) V_95 ,
V_90 . V_105 ) ;
} else {
memcpy ( ( void * ) V_95 , ( void * ) V_94 ,
V_90 . V_105 ) ;
}
V_96 += V_90 . V_105 ;
}
F_71 ( V_88 , 0 ) ;
return;
V_98:
F_72 ( V_88 ) ;
}
static int
F_73 ( struct V_79 * V_80 , T_4 V_107 ,
void * * V_108 , unsigned long * V_109 )
{
struct V_3 * V_4 ;
unsigned long V_110 ;
V_4 = V_80 -> V_82 -> V_68 ;
if ( ! V_4 )
return - V_75 ;
if ( V_107 % ( V_111 / 512 ) )
return - V_12 ;
V_110 = V_107 / ( V_111 / 512 ) ;
if ( ( V_110 + 1 ) * V_111 - 1 > V_4 -> V_20 - V_4 -> V_23 )
return - V_112 ;
* V_108 = ( void * ) ( V_4 -> V_23 + V_110 * V_111 ) ;
* V_109 = F_74 ( * V_108 ) >> V_113 ;
return 0 ;
}
static void
F_75 ( void )
{
int V_26 , V_24 , V_25 , V_114 ;
char V_41 [ V_115 + 1 ] ;
struct V_3 * V_4 ;
for ( V_24 = 0 ; ( V_24 < V_115 ) && ( V_116 [ V_24 ] != '\0' ) ;
V_24 ++ ) {
for ( V_25 = V_24 ; ( V_116 [ V_25 ] != ',' ) &&
( V_116 [ V_25 ] != '\0' ) &&
( V_116 [ V_25 ] != '(' ) &&
( V_25 < V_115 ) ; V_25 ++ )
{
V_41 [ V_25 - V_24 ] = V_116 [ V_25 ] ;
}
V_41 [ V_25 - V_24 ] = '\0' ;
V_26 = F_43 ( V_55 , NULL , V_41 , V_25 - V_24 ) ;
if ( ( V_26 >= 0 ) && ( V_116 [ V_25 ] == '(' ) ) {
for ( V_114 = 0 ; ( V_41 [ V_114 ] != ':' ) && ( V_41 [ V_114 ] != '\0' ) ; V_114 ++ )
V_41 [ V_114 ] = toupper ( V_41 [ V_114 ] ) ;
V_41 [ V_114 ] = '\0' ;
if ( ! strncmp ( & V_116 [ V_25 ] , L_28 , 7 ) ) {
F_17 ( & V_36 ) ;
V_4 = F_9 ( V_41 ) ;
F_18 ( & V_36 ) ;
if ( V_4 )
F_26 ( & V_4 -> V_2 ,
NULL , L_6 , 2 ) ;
}
}
while ( ( V_116 [ V_25 ] != ',' ) &&
( V_116 [ V_25 ] != '\0' ) )
{
V_25 ++ ;
}
if ( V_116 [ V_25 ] == '\0' )
break;
V_24 = V_25 ;
}
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_26 = 0 ;
F_8 (dev_info, &dcssblk_devices, lh) {
switch ( V_4 -> V_32 ) {
case V_48 :
case V_34 :
case V_49 :
if ( ! V_4 -> V_42 )
V_26 = - V_12 ;
break;
default:
V_26 = - V_12 ;
break;
}
if ( V_26 )
break;
}
if ( V_26 )
F_15 ( L_29
L_30 ,
V_4 -> V_18 ) ;
return V_26 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_23 , V_20 ;
int V_26 = 0 ;
F_8 (dev_info, &dcssblk_devices, lh) {
F_8 (entry, &dev_info->seg_list, lh) {
F_32 ( V_6 -> V_18 ) ;
V_26 = F_19 ( V_6 -> V_18 , V_38 ,
& V_23 , & V_20 ) ;
if ( V_26 < 0 ) {
F_20 ( V_26 , V_6 -> V_18 ) ;
goto V_117;
}
if ( V_23 != V_6 -> V_23 || V_20 != V_6 -> V_20 ) {
F_15 ( L_31
L_32 ,
V_6 -> V_18 ) ;
goto V_117;
}
}
}
return 0 ;
V_117:
F_78 ( L_33 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return 0 ;
}
static void T_5
F_80 ( void )
{
F_81 ( V_118 ) ;
F_82 ( & V_119 ) ;
F_83 ( V_55 ) ;
F_84 ( V_65 , V_120 ) ;
}
static int T_6
F_85 ( void )
{
int V_26 ;
V_26 = F_86 ( & V_119 ) ;
if ( V_26 )
return V_26 ;
V_118 = F_87 ( L_34 , - 1 , NULL ,
0 ) ;
if ( F_88 ( V_118 ) ) {
V_26 = F_89 ( V_118 ) ;
goto V_121;
}
V_55 = F_90 ( L_34 ) ;
if ( F_88 ( V_55 ) ) {
V_26 = F_89 ( V_55 ) ;
goto V_122;
}
V_26 = F_91 ( V_55 , & V_123 ) ;
if ( V_26 )
goto V_124;
V_26 = F_91 ( V_55 , & V_125 ) ;
if ( V_26 )
goto V_124;
V_26 = F_92 ( 0 , V_120 ) ;
if ( V_26 < 0 )
goto V_124;
V_65 = V_26 ;
F_93 ( & V_36 ) ;
F_75 () ;
return 0 ;
V_124:
F_83 ( V_55 ) ;
V_122:
F_81 ( V_118 ) ;
V_121:
F_82 ( & V_119 ) ;
return V_26 ;
}
