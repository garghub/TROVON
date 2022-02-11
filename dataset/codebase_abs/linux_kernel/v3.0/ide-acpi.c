static int F_1 ( const struct V_1 * V_2 )
{
V_3 = true ;
F_2 ( V_4 L_1 , V_2 -> V_5 ) ;
return 0 ;
}
int F_3 ( void )
{
F_4 ( V_6 ) ;
return 0 ;
}
bool F_5 ( T_1 * V_7 )
{
return V_8 == 0 && V_7 -> V_9 ;
}
static int F_6 ( struct V_10 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_11 ) ;
unsigned int V_16 , V_17 , V_18 ;
T_3 V_19 ;
T_2 V_20 ;
T_4 V_21 ;
struct V_22 * V_23 = NULL ;
int V_24 = - V_25 ;
V_16 = V_15 -> V_16 -> V_26 ;
V_17 = F_8 ( V_15 -> V_27 ) ;
V_18 = F_9 ( V_15 -> V_27 ) ;
V_19 = ( T_3 ) ( V_17 << 16 | V_18 ) ;
F_10 ( L_2 , V_16 , V_17 , V_18 ) ;
V_20 = F_11 ( V_11 ) ;
if ( ! V_20 ) {
F_10 ( L_3 ) ;
goto V_28;
}
V_21 = F_12 ( V_20 , & V_23 ) ;
if ( F_13 ( V_21 ) ) {
F_10 ( L_4 ) ;
goto V_28;
}
if ( V_23 && ( V_23 -> V_29 & V_30 ) &&
V_23 -> V_31 == V_19 ) {
* V_13 = V_19 ;
* V_12 = V_20 ;
} else {
F_10 ( L_5
L_6 ,
V_23 ? ( unsigned long long ) V_23 -> V_31 : - 1ULL ,
( unsigned int ) V_19 ) ;
goto V_28;
}
F_10 ( L_7 ,
V_17 , V_18 , ( unsigned long long ) V_19 , * V_12 ) ;
V_24 = 0 ;
V_28:
F_14 ( V_23 ) ;
return V_24 ;
}
static T_2 F_15 ( T_1 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_32 . V_33 ;
T_2 V_34 ( V_20 ) ;
T_3 V_13 ;
T_2 V_35 ;
int V_28 ;
F_10 ( L_8 , V_7 -> V_36 ) ;
if ( ! V_11 ) {
F_10 ( L_9 , V_7 -> V_36 ) ;
return NULL ;
}
V_28 = F_6 ( V_11 , & V_20 , & V_13 ) ;
if ( V_28 < 0 ) {
F_10 ( L_10 , V_28 ) ;
return NULL ;
}
V_35 = F_16 ( V_20 , V_7 -> V_37 ) ;
F_10 ( L_11 ,
V_7 -> V_37 , V_35 ) ;
return V_35 ;
}
static int F_17 ( T_5 * V_38 ,
unsigned int * V_39 , unsigned long * V_40 ,
unsigned long * V_41 )
{
T_4 V_21 ;
struct V_42 V_43 ;
union V_44 * V_45 ;
int V_28 = - V_25 ;
* V_39 = 0 ;
* V_40 = 0UL ;
* V_41 = 0UL ;
if ( ! V_38 -> V_9 -> V_46 ) {
F_10 ( L_12 , V_38 -> V_36 ) ;
goto V_47;
}
V_43 . V_48 = V_49 ;
V_43 . V_50 = NULL ;
V_28 = - V_51 ;
V_21 = F_18 ( V_38 -> V_9 -> V_46 , L_13 ,
NULL , & V_43 ) ;
if ( F_13 ( V_21 ) ) {
F_2 ( V_52
L_14 ,
V_53 , V_21 ) ;
goto V_47;
}
if ( ! V_43 . V_48 || ! V_43 . V_50 ) {
F_10 ( L_15
L_16 ,
( unsigned long long ) V_43 . V_48 ,
V_43 . V_50 ) ;
goto V_47;
}
V_45 = V_43 . V_50 ;
if ( V_45 -> type != V_54 ) {
F_10 ( L_17
L_18
L_19 , V_45 -> type ) ;
V_28 = - V_55 ;
F_14 ( V_43 . V_50 ) ;
goto V_47;
}
if ( ! V_45 -> V_56 . V_48 || ! V_45 -> V_56 . V_50 ||
V_45 -> V_56 . V_48 % V_57 ) {
F_2 ( V_58
L_20 ,
V_53 , V_45 -> V_56 . V_48 ,
V_45 -> V_56 . V_50 ) ;
V_28 = - V_55 ;
F_14 ( V_43 . V_50 ) ;
goto V_47;
}
* V_39 = V_45 -> V_56 . V_48 ;
* V_40 = ( unsigned long ) V_45 -> V_56 . V_50 ;
* V_41 = ( unsigned long ) V_45 ;
F_10 ( L_21 ,
* V_39 , * V_40 , * V_41 ) ;
V_28 = 0 ;
V_47:
return V_28 ;
}
static int F_19 ( T_5 * V_38 ,
unsigned int V_39 ,
unsigned long V_40 )
{
int V_59 = 0 , V_28 ;
int V_60 = V_39 / V_57 ;
int V_61 ;
F_10 ( L_22 ,
V_39 , V_39 , V_60 , V_40 ) ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
T_6 * V_62 = ( T_6 * ) ( V_40 + V_61 * V_57 ) ;
struct V_63 V_64 ;
F_10 ( L_23
L_24 ,
V_62 [ 0 ] , V_62 [ 1 ] , V_62 [ 2 ] ,
V_62 [ 3 ] , V_62 [ 4 ] , V_62 [ 5 ] , V_62 [ 6 ] ) ;
if ( ! V_65 ) {
F_10 ( L_25 ) ;
continue;
}
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
memcpy ( & V_64 . V_66 . V_67 , V_62 , V_57 ) ;
V_64 . V_29 . V_47 . V_66 = V_68 | V_69 ;
V_64 . V_29 . V_70 . V_66 = V_71 | V_69 ;
V_28 = F_20 ( V_38 , & V_64 ) ;
if ( V_28 ) {
F_2 ( V_58 L_26 ,
V_53 , V_28 ) ;
V_59 = V_28 ;
}
}
return V_59 ;
}
int F_21 ( T_5 * V_38 )
{
int V_24 ;
unsigned int V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
F_10 ( L_27 , V_38 -> V_36 , V_38 -> V_72 ) ;
V_24 = F_17 ( V_38 , & V_39 , & V_40 , & V_41 ) ;
if ( V_24 < 0 ) {
F_10 ( L_28 , V_24 ) ;
return V_24 ;
}
F_10 ( L_29 , V_38 -> V_36 ) ;
V_24 = F_19 ( V_38 , V_39 , V_40 ) ;
F_14 ( ( void * ) V_41 ) ;
if ( V_24 < 0 ) {
F_10 ( L_30 , V_24 ) ;
}
F_10 ( L_31 , V_24 ) ;
return V_24 ;
}
void F_22 ( T_1 * V_7 )
{
T_4 V_21 ;
struct V_42 V_43 ;
union V_44 * V_45 ;
V_43 . V_48 = V_49 ;
V_43 . V_50 = NULL ;
V_21 = F_18 ( V_7 -> V_9 -> V_46 , L_32 ,
NULL , & V_43 ) ;
F_10 ( L_33 ,
V_21 , V_43 . V_50 ,
( unsigned long long ) V_43 . V_48 ) ;
if ( F_13 ( V_21 ) ) {
F_10 ( L_34 , V_21 ) ;
return;
}
if ( ! V_43 . V_48 || ! V_43 . V_50 ) {
F_10 ( L_35 ,
( unsigned long long ) V_43 . V_48 ,
V_43 . V_50 ) ;
F_14 ( V_43 . V_50 ) ;
return;
}
V_45 = V_43 . V_50 ;
if ( V_45 -> type != V_54 ) {
F_10 ( L_36
L_18
L_19 , V_45 -> type ) ;
F_14 ( V_43 . V_50 ) ;
return;
}
if ( ! V_45 -> V_56 . V_48 || ! V_45 -> V_56 . V_50 ||
V_45 -> V_56 . V_48 != sizeof( struct V_73 ) ) {
F_2 ( V_58
L_37
L_38 ,
V_53 , V_45 -> V_56 . V_48 ,
sizeof( struct V_73 ) , V_45 -> V_56 . V_50 ) ;
F_14 ( V_43 . V_50 ) ;
return;
}
memcpy ( & V_7 -> V_9 -> V_74 , V_45 -> V_56 . V_50 ,
sizeof( struct V_73 ) ) ;
F_10 ( L_39 ,
V_45 -> V_56 . V_50 , V_45 -> V_56 . V_48 ,
sizeof( struct V_73 ) ) ;
F_10 ( L_40 ,
V_7 -> V_9 -> V_74 . V_75 ,
V_7 -> V_9 -> V_74 . V_76 ,
V_7 -> V_9 -> V_74 . V_77 ,
V_7 -> V_9 -> V_74 . V_78 ,
V_7 -> V_9 -> V_74 . V_79 ) ;
F_14 ( V_43 . V_50 ) ;
}
void F_23 ( T_1 * V_7 )
{
T_4 V_21 ;
struct V_80 V_81 ;
union V_44 V_82 [ 3 ] ;
struct V_83 * V_84 = & V_7 -> V_9 -> V_84 ;
struct V_83 * V_85 = & V_7 -> V_9 -> V_85 ;
V_81 . V_86 = 3 ;
V_81 . V_50 = V_82 ;
V_82 [ 0 ] . type = V_54 ;
V_82 [ 0 ] . V_56 . V_48 = sizeof( struct V_73 ) ;
V_82 [ 0 ] . V_56 . V_50 = ( T_6 * ) & V_7 -> V_9 -> V_74 ;
V_82 [ 1 ] . type = V_54 ;
V_82 [ 1 ] . V_56 . V_48 = V_87 * 2 ;
V_82 [ 1 ] . V_56 . V_50 = ( T_6 * ) & V_84 -> V_88 ;
V_82 [ 2 ] . type = V_54 ;
V_82 [ 2 ] . V_56 . V_48 = V_87 * 2 ;
V_82 [ 2 ] . V_56 . V_50 = ( T_6 * ) & V_85 -> V_88 ;
V_21 = F_18 ( V_7 -> V_9 -> V_46 , L_41 ,
& V_81 , NULL ) ;
if ( F_13 ( V_21 ) ) {
F_10 ( L_42 , V_21 ) ;
}
F_10 ( L_43 , V_21 ) ;
}
void F_24 ( T_1 * V_7 , int V_89 )
{
T_5 * V_38 ;
int V_90 ;
if ( V_3 )
return;
F_10 ( L_44 ) ;
if ( V_89 )
F_25 ( V_7 -> V_9 -> V_46 , V_91 ) ;
F_26 (i, drive, hwif) {
if ( V_38 -> V_9 -> V_46 )
F_25 ( V_38 -> V_9 -> V_46 ,
V_89 ? V_91 : V_92 ) ;
}
if ( ! V_89 )
F_25 ( V_7 -> V_9 -> V_46 , V_92 ) ;
}
void F_27 ( T_1 * V_7 )
{
V_7 -> V_9 = F_28 ( sizeof( struct V_93 ) , V_94 ) ;
if ( ! V_7 -> V_9 )
return;
V_7 -> V_9 -> V_46 = F_15 ( V_7 ) ;
if ( ! V_7 -> V_9 -> V_46 ) {
F_10 ( L_45 , V_7 -> V_36 ) ;
F_14 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
}
void F_29 ( T_1 * V_7 )
{
T_5 * V_38 ;
int V_90 , V_28 ;
if ( V_7 -> V_9 == NULL )
return;
V_7 -> V_95 [ 0 ] -> V_9 = & V_7 -> V_9 -> V_84 ;
V_7 -> V_95 [ 1 ] -> V_9 = & V_7 -> V_9 -> V_85 ;
F_26 (i, drive, hwif) {
T_2 V_20 ;
F_10 ( L_46 ,
V_38 -> V_36 , V_7 -> V_37 , V_38 -> V_72 & 1 ) ;
V_20 = F_16 ( V_7 -> V_9 -> V_46 ,
V_38 -> V_72 & 1 ) ;
F_10 ( L_47 , V_38 -> V_36 , V_20 ) ;
V_38 -> V_9 -> V_46 = V_20 ;
}
F_26 (i, drive, hwif) {
V_28 = F_30 ( V_38 , V_38 -> V_9 -> V_88 ) ;
if ( V_28 )
F_10 ( L_48 ,
V_38 -> V_36 , V_28 ) ;
}
if ( V_8 || V_96 == 0 ) {
F_10 ( L_49 ) ;
return;
}
F_24 ( V_7 , 1 ) ;
F_22 ( V_7 ) ;
F_23 ( V_7 ) ;
F_26 (i, drive, hwif) {
F_21 ( V_38 ) ;
}
}
