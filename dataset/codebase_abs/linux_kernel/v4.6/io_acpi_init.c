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
V_7 = F_13 ( F_14 ( V_41 ) -> V_43 ) ;
V_6 = F_4 ( V_7 , V_26 ,
& V_27 , & V_12 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29 L_5
L_6 ,
V_44 , V_6 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return NULL ;
}
V_22 = V_12 . V_30 ;
V_24 = & V_22 -> V_32 . V_33 ;
if ( ( V_24 -> V_34 - sizeof( struct V_35 ) ) !=
sizeof( struct V_39 * ) ) {
F_7 ( V_29
L_7 ,
V_44 , V_24 -> V_34 ) ;
F_8 ( V_12 . V_30 ) ;
return NULL ;
}
memcpy ( & V_15 , V_24 -> V_36 , sizeof( struct V_39 * ) ) ;
V_42 = F_9 ( (struct V_39 * ) V_15 ) ;
F_8 ( V_12 . V_30 ) ;
return V_42 ;
}
static int
F_15 ( T_4 V_7 , struct V_45 * * V_45 ,
struct V_46 * * V_46 )
{
T_1 V_15 ;
struct V_11 V_12 = { V_13 , NULL } ;
struct V_11 V_14 = { V_13 , NULL } ;
struct V_46 * V_47 , * V_48 ;
struct V_45 * V_49 , * V_50 ;
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
V_44 , V_6 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return 1 ;
}
V_22 = V_12 . V_30 ;
V_24 = & V_22 -> V_32 . V_33 ;
if ( ( V_24 -> V_34 - sizeof( struct V_35 ) ) !=
sizeof( struct V_51 * ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_9 ,
V_44 , V_24 -> V_34 ,
( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
V_10 = 1 ;
goto exit;
}
V_49 = F_16 ( sizeof( struct V_45 ) , V_52 ) ;
if ( ! V_49 )
F_17 ( L_10 , V_44 ) ;
memcpy ( & V_15 , V_24 -> V_36 , sizeof( struct V_45 * ) ) ;
V_50 = F_9 ( V_15 ) ;
memcpy ( V_49 , V_50 , sizeof( struct V_45 ) ) ;
V_47 = F_16 ( sizeof( struct V_46 ) , V_52 ) ;
if ( ! V_47 )
F_17 ( L_11 , V_44 ) ;
if ( V_49 -> V_53 ) {
V_48 = F_9 ( V_49 -> V_53 ) ;
memcpy ( V_47 , V_48 , sizeof( struct V_46 ) ) ;
}
* V_45 = V_49 ;
* V_46 = V_47 ;
exit:
F_8 ( V_12 . V_30 ) ;
return V_10 ;
}
static unsigned int
F_18 ( T_4 V_54 , T_4 V_55 )
{
unsigned long long V_56 ;
T_4 V_57 ;
unsigned int V_58 ;
int V_59 ;
T_4 V_60 ;
int V_61 ;
T_2 V_6 ;
struct V_11 V_14 = { V_13 , NULL } ;
F_6 ( V_54 , V_28 , & V_14 ) ;
V_57 = V_54 ;
while ( V_57 ) {
V_6 = F_19 ( V_57 , & V_60 ) ;
if ( F_5 ( V_6 ) ) {
F_7 ( V_29 L_12
L_13 , V_44 , V_6 ,
( char * ) V_14 . V_30 ) ;
F_17 ( L_14 , V_44 ) ;
}
if ( V_60 == V_55 )
break;
V_57 = V_60 ;
}
if ( ! V_57 ) {
F_7 ( V_29 L_15 ,
V_44 , ( char * ) V_14 . V_30 ) ;
F_20 () ;
}
V_6 = F_21 ( V_57 , V_62 , NULL , & V_56 ) ;
if ( F_5 ( V_6 ) ) {
F_7 ( V_29 L_16 ,
V_44 , V_6 , ( char * ) V_14 . V_30 ) ;
F_17 ( L_14 , V_44 ) ;
}
F_8 ( V_14 . V_30 ) ;
V_61 = ( V_56 >> 16 ) & 0xffff ;
V_59 = V_56 & 0xffff ;
V_58 = F_22 ( V_61 , V_59 ) ;
return V_58 ;
}
static T_2
F_23 ( T_4 V_7 , T_5 V_63 , void * V_9 , void * * V_64 )
{
unsigned long long V_65 = - 1 ;
unsigned long long V_56 ;
T_4 V_60 = NULL ;
T_2 V_6 ;
unsigned int V_58 ;
int V_59 ;
int V_61 ;
struct V_66 * V_67 = V_9 ;
struct V_11 V_14 = { V_13 , NULL } ;
V_6 = F_21 ( V_7 , V_62 , NULL ,
& V_56 ) ;
if ( F_24 ( V_6 ) ) {
V_6 = F_19 ( V_7 , & V_60 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_17 ,
V_44 , V_6 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return V_31 ;
}
V_6 = F_21 ( V_60 , V_68 ,
NULL , & V_65 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_7 , V_28 , & V_14 ) ;
F_7 ( V_29
L_18 ,
V_44 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return V_31 ;
}
V_61 = ( V_56 >> 16 ) & 0xffff ;
V_59 = V_56 & 0xffff ;
V_58 = F_22 ( V_61 , V_59 ) ;
if ( ( V_67 -> V_58 == V_58 ) && ( V_67 -> V_41 == V_65 ) ) {
V_67 -> V_7 = V_7 ;
return 1 ;
}
}
return V_31 ;
}
int
F_25 ( struct V_69 * V_70 , struct V_45 * * V_45 ,
struct V_46 * * V_46 )
{
unsigned int V_71 ;
struct V_66 V_72 ;
T_4 V_55 ;
unsigned long long V_73 ;
T_2 V_6 ;
struct V_11 V_14 = { V_13 , NULL } ;
V_55 = F_13 ( F_14 ( V_70 ) -> V_43 ) ;
V_6 = F_21 ( V_55 , V_74 , NULL ,
& V_73 ) ;
if ( F_24 ( V_6 ) ) {
if ( V_73 != F_26 ( V_70 ) ) {
F_6 ( V_55 , V_28 ,
& V_14 ) ;
F_7 ( V_29
L_19 ,
V_44 , V_73 , F_26 ( V_70 ) ,
( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return 1 ;
}
} else {
F_6 ( V_55 , V_28 , & V_14 ) ;
F_7 ( V_29 L_20 ,
V_44 , ( char * ) V_14 . V_30 ) ;
F_8 ( V_14 . V_30 ) ;
return 1 ;
}
V_72 . V_41 = V_70 -> V_41 -> V_75 ;
V_72 . V_58 = V_70 -> V_58 ;
V_72 . V_7 = NULL ;
F_27 ( V_76 , V_55 , V_77 ,
F_23 , NULL , & V_72 , NULL ) ;
if ( ! V_72 . V_7 ) {
F_7 ( V_29
L_21 ,
V_44 , F_28 ( V_70 ) ) ;
return 1 ;
}
if ( F_15 ( V_72 . V_7 , V_45 , V_46 ) )
return 1 ;
V_71 = F_18 ( V_72 . V_7 , V_55 ) ;
( * V_45 ) -> V_78 =
( ( unsigned long ) F_26 ( V_70 ) << 40 ) |
V_71 ;
return 0 ;
}
void
F_29 ( struct V_69 * V_70 )
{
void T_6 * V_15 ;
struct V_45 * V_45 = NULL ;
struct V_46 * V_46 = NULL ;
struct V_22 * V_79 ;
T_7 V_80 ;
if ( F_25 ( V_70 , & V_45 , & V_46 ) ) {
F_17 ( L_22 ,
V_44 , F_28 ( V_70 ) ) ;
}
if ( V_45 -> V_81 [ V_82 ] ) {
V_80 = F_30 ( V_70 , V_82 ) ;
V_79 = & V_70 -> V_22 [ V_82 ] ;
F_31 ( V_70 ) ;
if ( V_79 -> V_60 )
F_32 ( V_79 ) ;
V_79 -> V_83 = V_45 -> V_81 [ V_82 ] ;
V_79 -> V_84 = V_79 -> V_83 + V_80 - 1 ;
V_79 -> V_85 = V_86 | V_87 |
V_88 ;
}
F_33 ( V_70 , V_45 , V_46 ) ;
}
void
F_34 ( struct V_40 * V_41 )
{
struct V_69 * V_69 = NULL ;
struct V_39 * V_42 ;
if ( ! V_41 -> V_60 ) {
V_42 = F_12 ( V_41 ) ;
if ( V_42 == NULL ) {
F_7 ( V_29
L_23
L_24 ,
V_44 , F_26 ( V_41 ) , V_41 -> V_75 ) ;
return;
}
F_35 ( V_41 , V_42 ) ;
}
F_36 (pci_dev, &bus->devices, bus_list) {
F_29 ( V_69 ) ;
}
}
void T_3
F_37 ( void )
{
T_1 V_1 ;
long V_6 ;
V_89 = V_90 ;
F_38 ( L_25 , F_3 , NULL , NULL ) ;
F_38 ( L_26 , F_3 , NULL , NULL ) ;
V_6 = F_1 ( & V_1 ) ;
if ( V_6 || V_1 )
F_17 ( L_27 ,
V_6 , F_39 ( V_6 ) ) ;
}
