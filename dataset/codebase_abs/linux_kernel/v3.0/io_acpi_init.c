static long
F_1 ( T_1 * V_1 )
{
struct V_2 V_3 = { 0 , 0 , 0 , 0 } ;
F_2 ( V_3 ,
V_4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
* V_1 = V_3 . V_5 ;
return V_3 . V_6 ;
}
static T_2 T_3
F_3 ( T_4 V_7 , T_5 V_8 , void * V_9 , void * * V_10 )
{
struct V_11 V_12 = { V_13 , NULL } ;
struct V_11 V_14 = { V_13 , NULL } ;
T_1 V_15 ;
struct V_16 * V_17 ;
struct V_16 * V_18 ;
int V_19 ;
T_1 V_20 ;
struct V_21 * V_22 ;
T_2 V_6 ;
struct V_23 * V_24 ;
extern void V_25 ( struct V_16 * ) ;
V_6 = F_4 ( V_7 , V_26 ,
& V_27 , & V_12 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_1
L_2 , V_6 ,
( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return V_31 ;
}
V_22 = V_12 . V_30 ;
V_24 = & V_22 -> V_32 . V_33 ;
if ( ( V_24 -> V_34 - sizeof( struct V_35 ) ) !=
sizeof( struct V_16 * ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_3
L_4 ,
V_24 -> V_34 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
goto exit;
}
memcpy ( & V_15 , V_24 -> V_36 , sizeof( struct V_16 * ) ) ;
V_18 = F_9 ( (struct V_16 * ) V_15 ) ;
V_20 = V_18 -> V_37 ;
V_19 = F_10 ( V_20 ) ;
V_17 = (struct V_16 * ) ( F_11 ( V_19 ) -> V_38 ) ;
* V_17 = * V_18 ;
V_25 ( V_17 ) ;
exit:
F_8 ( V_12 . V_30 ) ;
return V_31 ;
}
static struct V_39 *
F_12 ( struct V_40 * V_41 )
{
T_1 V_15 ;
struct V_11 V_12 = { V_13 , NULL } ;
struct V_11 V_14 = { V_13 , NULL } ;
T_4 V_7 ;
struct V_39 * V_42 ;
struct V_21 * V_22 ;
T_2 V_6 ;
struct V_23 * V_24 ;
V_7 = F_13 ( V_41 ) -> T_4 ;
V_6 = F_4 ( V_7 , V_26 ,
& V_27 , & V_12 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29 L_5
L_6 ,
V_43 , V_6 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return NULL ;
}
V_22 = V_12 . V_30 ;
V_24 = & V_22 -> V_32 . V_33 ;
if ( ( V_24 -> V_34 - sizeof( struct V_35 ) ) !=
sizeof( struct V_39 * ) ) {
F_7 ( V_29
L_7 ,
V_43 , V_24 -> V_34 ) ;
F_8 ( V_12 . V_30 ) ;
return NULL ;
}
memcpy ( & V_15 , V_24 -> V_36 , sizeof( struct V_39 * ) ) ;
V_42 = F_9 ( (struct V_39 * ) V_15 ) ;
F_8 ( V_12 . V_30 ) ;
return V_42 ;
}
static int
F_14 ( T_4 V_7 , struct V_44 * * V_44 ,
struct V_45 * * V_45 )
{
T_1 V_15 ;
struct V_11 V_12 = { V_13 , NULL } ;
struct V_11 V_14 = { V_13 , NULL } ;
struct V_45 * V_46 , * V_47 ;
struct V_44 * V_48 , * V_49 ;
struct V_21 * V_22 ;
int V_10 = 0 ;
T_2 V_6 ;
struct V_23 * V_24 ;
V_6 = F_4 ( V_7 , V_26 ,
& V_27 , & V_12 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_8 ,
V_43 , V_6 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return 1 ;
}
V_22 = V_12 . V_30 ;
V_24 = & V_22 -> V_32 . V_33 ;
if ( ( V_24 -> V_34 - sizeof( struct V_35 ) ) !=
sizeof( struct V_50 * ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_9 ,
V_43 , V_24 -> V_34 ,
( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
V_10 = 1 ;
goto exit;
}
V_48 = F_15 ( sizeof( struct V_44 ) , V_51 ) ;
if ( ! V_48 )
F_16 ( L_10 , V_43 ) ;
memcpy ( & V_15 , V_24 -> V_36 , sizeof( struct V_44 * ) ) ;
V_49 = F_9 ( V_15 ) ;
memcpy ( V_48 , V_49 , sizeof( struct V_44 ) ) ;
V_46 = F_15 ( sizeof( struct V_45 ) , V_51 ) ;
if ( ! V_46 )
F_16 ( L_11 , V_43 ) ;
if ( V_48 -> V_52 ) {
V_47 = F_9 ( V_48 -> V_52 ) ;
memcpy ( V_46 , V_47 , sizeof( struct V_45 ) ) ;
}
* V_44 = V_48 ;
* V_45 = V_46 ;
exit:
F_8 ( V_12 . V_30 ) ;
return V_10 ;
}
static unsigned int
F_17 ( T_4 V_53 , T_4 V_54 )
{
unsigned long long V_55 ;
T_4 V_56 ;
unsigned int V_57 ;
int V_58 ;
T_4 V_59 ;
int V_60 ;
T_2 V_6 ;
struct V_11 V_14 = { V_13 , NULL } ;
F_6 ( V_53 , V_28 , & V_14 ) ;
V_56 = V_53 ;
while ( V_56 ) {
V_6 = F_18 ( V_56 , & V_59 ) ;
if ( F_5 ( V_6 ) ) {
F_7 ( V_29 L_12
L_13 , V_43 , V_6 ,
( char * ) V_14 . V_30 ) ;
F_16 ( L_14 , V_43 ) ;
}
if ( V_59 == V_54 )
break;
V_56 = V_59 ;
}
if ( ! V_56 ) {
F_7 ( V_29 L_15 ,
V_43 , ( char * ) V_14 . V_30 ) ;
F_19 () ;
}
V_6 = F_20 ( V_56 , V_61 , NULL , & V_55 ) ;
if ( F_5 ( V_6 ) ) {
F_7 ( V_29 L_16 ,
V_43 , V_6 , ( char * ) V_14 . V_30 ) ;
F_16 ( L_14 , V_43 ) ;
}
F_8 ( V_14 . V_30 ) ;
V_60 = ( V_55 >> 16 ) & 0xffff ;
V_58 = V_55 & 0xffff ;
V_57 = F_21 ( V_60 , V_58 ) ;
return V_57 ;
}
static T_2
F_22 ( T_4 V_7 , T_5 V_62 , void * V_9 , void * * V_63 )
{
unsigned long long V_64 = - 1 ;
unsigned long long V_55 ;
T_4 V_59 = NULL ;
T_2 V_6 ;
unsigned int V_57 ;
int V_58 ;
int V_60 ;
struct V_65 * V_66 = V_9 ;
struct V_11 V_14 = { V_13 , NULL } ;
V_6 = F_20 ( V_7 , V_61 , NULL ,
& V_55 ) ;
if ( F_23 ( V_6 ) ) {
V_6 = F_18 ( V_7 , & V_59 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_17 ,
V_43 , V_6 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return V_31 ;
}
V_6 = F_20 ( V_59 , V_67 ,
NULL , & V_64 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_18 ,
V_43 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return V_31 ;
}
V_60 = ( V_55 >> 16 ) & 0xffff ;
V_58 = V_55 & 0xffff ;
V_57 = F_21 ( V_60 , V_58 ) ;
if ( ( V_66 -> V_57 == V_57 ) && ( V_66 -> V_41 == V_64 ) ) {
V_66 -> V_7 = V_7 ;
return 1 ;
}
}
return V_31 ;
}
int
F_24 ( struct V_68 * V_69 , struct V_44 * * V_44 ,
struct V_45 * * V_45 )
{
unsigned int V_70 ;
struct V_65 V_71 ;
T_4 V_54 ;
unsigned long long V_72 ;
T_2 V_6 ;
struct V_11 V_14 = { V_13 , NULL } ;
V_54 = F_13 ( V_69 ) -> T_4 ;
V_6 = F_20 ( V_54 , V_73 , NULL ,
& V_72 ) ;
if ( F_23 ( V_6 ) ) {
if ( V_72 != F_25 ( V_69 ) ) {
F_6 ( V_54 , V_28 ,
& V_14 ) ;
F_7 ( V_29
L_19 ,
V_43 , V_72 , F_25 ( V_69 ) ,
( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return 1 ;
}
} else {
F_6 ( V_54 , V_28 , & V_14 ) ;
F_7 ( V_29 L_20 ,
V_43 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return 1 ;
}
V_71 . V_41 = V_69 -> V_41 -> V_74 ;
V_71 . V_57 = V_69 -> V_57 ;
V_71 . V_7 = NULL ;
F_26 ( V_75 , V_54 , V_76 ,
F_22 , NULL , & V_71 , NULL ) ;
if ( ! V_71 . V_7 ) {
F_7 ( V_29
L_21 ,
V_43 , F_27 ( V_69 ) ) ;
return 1 ;
}
if ( F_14 ( V_71 . V_7 , V_44 , V_45 ) )
return 1 ;
V_70 = F_17 ( V_71 . V_7 , V_54 ) ;
( * V_44 ) -> V_77 =
( ( unsigned long ) F_25 ( V_69 ) << 40 ) |
V_70 ;
return 0 ;
}
void
F_28 ( struct V_68 * V_69 )
{
void T_6 * V_15 ;
struct V_44 * V_44 = NULL ;
struct V_45 * V_45 = NULL ;
T_7 V_78 , V_79 ;
if ( F_24 ( V_69 , & V_44 , & V_45 ) ) {
F_16 ( L_22 ,
V_43 , F_27 ( V_69 ) ) ;
}
if ( V_44 -> V_80 [ V_81 ] ) {
V_79 = F_29 ( V_69 , V_81 ) ;
V_15 = F_30 ( V_44 -> V_80 [ V_81 ] ,
V_79 ) ;
V_78 = F_31 ( V_69 , V_15 , V_79 ) ;
V_69 -> V_22 [ V_81 ] . V_82 = ( unsigned long ) V_15 ;
V_69 -> V_22 [ V_81 ] . V_83 =
( unsigned long ) V_15 + V_78 - 1 ;
V_69 -> V_22 [ V_81 ] . V_84 |= V_85 ;
}
F_32 ( V_69 , V_44 , V_45 ) ;
}
void
F_33 ( struct V_40 * V_41 )
{
struct V_68 * V_68 = NULL ;
struct V_39 * V_42 ;
if ( ! V_41 -> V_59 ) {
V_42 = F_12 ( V_41 ) ;
if ( V_42 == NULL ) {
F_7 ( V_29
L_23
L_24 ,
V_43 , F_25 ( V_41 ) , V_41 -> V_74 ) ;
return;
}
F_34 ( V_41 , V_42 ) ;
}
F_35 (pci_dev, &bus->devices, bus_list) {
F_28 ( V_68 ) ;
}
}
void T_3
F_36 ( void )
{
T_1 V_1 ;
long V_6 ;
V_86 = V_87 ;
F_37 ( L_25 , F_3 , NULL , NULL ) ;
F_37 ( L_26 , F_3 , NULL , NULL ) ;
V_6 = F_1 ( & V_1 ) ;
if ( V_6 || V_1 )
F_16 ( L_27 ,
V_6 , F_38 ( V_6 ) ) ;
}
