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
static T_2 F_6 ( T_2 V_10 , T_3 V_11 )
{
struct V_12 * V_13 ;
if ( ! V_10 || F_7 ( V_10 , & V_13 ) )
return NULL ;
V_13 = F_8 ( V_13 , V_11 , false ) ;
return V_13 ? V_13 -> V_10 : NULL ;
}
static int F_9 ( struct V_14 * V_15 , T_2 * V_10 ,
T_3 * V_16 )
{
struct V_17 * V_18 = F_10 ( V_15 ) ;
unsigned int V_19 , V_20 , V_21 ;
T_3 V_11 ;
T_2 V_22 ;
T_4 V_23 ;
struct V_24 * V_25 = NULL ;
int V_26 = - V_27 ;
V_19 = V_18 -> V_19 -> V_28 ;
V_20 = F_11 ( V_18 -> V_29 ) ;
V_21 = F_12 ( V_18 -> V_29 ) ;
V_11 = ( T_3 ) ( V_20 << 16 | V_21 ) ;
F_13 ( L_2 , V_19 , V_20 , V_21 ) ;
V_22 = F_14 ( V_15 ) ;
if ( ! V_22 ) {
F_13 ( L_3 ) ;
goto V_30;
}
V_23 = F_15 ( V_22 , & V_25 ) ;
if ( F_16 ( V_23 ) ) {
F_13 ( L_4 ) ;
goto V_30;
}
if ( V_25 && ( V_25 -> V_31 & V_32 ) &&
V_25 -> V_33 == V_11 ) {
* V_16 = V_11 ;
* V_10 = V_22 ;
} else {
F_13 ( L_5
L_6 ,
V_25 ? ( unsigned long long ) V_25 -> V_33 : - 1ULL ,
( unsigned int ) V_11 ) ;
goto V_30;
}
F_13 ( L_7 ,
V_20 , V_21 , ( unsigned long long ) V_11 , * V_10 ) ;
V_26 = 0 ;
V_30:
F_17 ( V_25 ) ;
return V_26 ;
}
static T_2 F_18 ( T_1 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_34 . V_35 ;
T_2 V_36 ( V_22 ) ;
T_3 V_16 ;
T_2 V_37 ;
int V_30 ;
F_13 ( L_8 , V_7 -> V_38 ) ;
if ( ! V_15 ) {
F_13 ( L_9 , V_7 -> V_38 ) ;
return NULL ;
}
V_30 = F_9 ( V_15 , & V_22 , & V_16 ) ;
if ( V_30 < 0 ) {
F_13 ( L_10 , V_30 ) ;
return NULL ;
}
V_37 = F_6 ( V_22 , V_7 -> V_39 ) ;
F_13 ( L_11 ,
V_7 -> V_39 , V_37 ) ;
return V_37 ;
}
static int F_19 ( T_5 * V_40 ,
unsigned int * V_41 , unsigned long * V_42 ,
unsigned long * V_43 )
{
T_4 V_23 ;
struct V_44 V_45 ;
union V_46 * V_47 ;
int V_30 = - V_27 ;
* V_41 = 0 ;
* V_42 = 0UL ;
* V_43 = 0UL ;
if ( ! V_40 -> V_9 -> V_48 ) {
F_13 ( L_12 , V_40 -> V_38 ) ;
goto V_49;
}
V_45 . V_50 = V_51 ;
V_45 . V_52 = NULL ;
V_30 = - V_53 ;
V_23 = F_20 ( V_40 -> V_9 -> V_48 , L_13 ,
NULL , & V_45 ) ;
if ( F_16 ( V_23 ) ) {
F_2 ( V_54
L_14 ,
V_55 , V_23 ) ;
goto V_49;
}
if ( ! V_45 . V_50 || ! V_45 . V_52 ) {
F_13 ( L_15
L_16 ,
( unsigned long long ) V_45 . V_50 ,
V_45 . V_52 ) ;
goto V_49;
}
V_47 = V_45 . V_52 ;
if ( V_47 -> type != V_56 ) {
F_13 ( L_17
L_18
L_19 , V_47 -> type ) ;
V_30 = - V_57 ;
F_17 ( V_45 . V_52 ) ;
goto V_49;
}
if ( ! V_47 -> V_58 . V_50 || ! V_47 -> V_58 . V_52 ||
V_47 -> V_58 . V_50 % V_59 ) {
F_2 ( V_60
L_20 ,
V_55 , V_47 -> V_58 . V_50 ,
V_47 -> V_58 . V_52 ) ;
V_30 = - V_57 ;
F_17 ( V_45 . V_52 ) ;
goto V_49;
}
* V_41 = V_47 -> V_58 . V_50 ;
* V_42 = ( unsigned long ) V_47 -> V_58 . V_52 ;
* V_43 = ( unsigned long ) V_47 ;
F_13 ( L_21 ,
* V_41 , * V_42 , * V_43 ) ;
V_30 = 0 ;
V_49:
return V_30 ;
}
static int F_21 ( T_5 * V_40 ,
unsigned int V_41 ,
unsigned long V_42 )
{
int V_61 = 0 , V_30 ;
int V_62 = V_41 / V_59 ;
int V_63 ;
F_13 ( L_22 ,
V_41 , V_41 , V_62 , V_42 ) ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
T_6 * V_64 = ( T_6 * ) ( V_42 + V_63 * V_59 ) ;
struct V_65 V_66 ;
F_13 ( L_23
L_24 ,
V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ,
V_64 [ 3 ] , V_64 [ 4 ] , V_64 [ 5 ] , V_64 [ 6 ] ) ;
if ( ! V_67 ) {
F_13 ( L_25 ) ;
continue;
}
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memcpy ( & V_66 . V_68 . V_69 , V_64 , V_59 ) ;
V_66 . V_31 . V_49 . V_68 = V_70 | V_71 ;
V_66 . V_31 . V_72 . V_68 = V_73 | V_71 ;
V_30 = F_22 ( V_40 , & V_66 ) ;
if ( V_30 ) {
F_2 ( V_60 L_26 ,
V_55 , V_30 ) ;
V_61 = V_30 ;
}
}
return V_61 ;
}
int F_23 ( T_5 * V_40 )
{
int V_26 ;
unsigned int V_41 ;
unsigned long V_42 ;
unsigned long V_43 ;
F_13 ( L_27 , V_40 -> V_38 , V_40 -> V_74 ) ;
V_26 = F_19 ( V_40 , & V_41 , & V_42 , & V_43 ) ;
if ( V_26 < 0 ) {
F_13 ( L_28 , V_26 ) ;
return V_26 ;
}
F_13 ( L_29 , V_40 -> V_38 ) ;
V_26 = F_21 ( V_40 , V_41 , V_42 ) ;
F_17 ( ( void * ) V_43 ) ;
if ( V_26 < 0 ) {
F_13 ( L_30 , V_26 ) ;
}
F_13 ( L_31 , V_26 ) ;
return V_26 ;
}
void F_24 ( T_1 * V_7 )
{
T_4 V_23 ;
struct V_44 V_45 ;
union V_46 * V_47 ;
V_45 . V_50 = V_51 ;
V_45 . V_52 = NULL ;
V_23 = F_20 ( V_7 -> V_9 -> V_48 , L_32 ,
NULL , & V_45 ) ;
F_13 ( L_33 ,
V_23 , V_45 . V_52 ,
( unsigned long long ) V_45 . V_50 ) ;
if ( F_16 ( V_23 ) ) {
F_13 ( L_34 , V_23 ) ;
return;
}
if ( ! V_45 . V_50 || ! V_45 . V_52 ) {
F_13 ( L_35 ,
( unsigned long long ) V_45 . V_50 ,
V_45 . V_52 ) ;
F_17 ( V_45 . V_52 ) ;
return;
}
V_47 = V_45 . V_52 ;
if ( V_47 -> type != V_56 ) {
F_13 ( L_36
L_18
L_19 , V_47 -> type ) ;
F_17 ( V_45 . V_52 ) ;
return;
}
if ( ! V_47 -> V_58 . V_50 || ! V_47 -> V_58 . V_52 ||
V_47 -> V_58 . V_50 != sizeof( struct V_75 ) ) {
F_2 ( V_60
L_37
L_38 ,
V_55 , V_47 -> V_58 . V_50 ,
sizeof( struct V_75 ) , V_47 -> V_58 . V_52 ) ;
F_17 ( V_45 . V_52 ) ;
return;
}
memcpy ( & V_7 -> V_9 -> V_76 , V_47 -> V_58 . V_52 ,
sizeof( struct V_75 ) ) ;
F_13 ( L_39 ,
V_47 -> V_58 . V_52 , V_47 -> V_58 . V_50 ,
sizeof( struct V_75 ) ) ;
F_13 ( L_40 ,
V_7 -> V_9 -> V_76 . V_77 ,
V_7 -> V_9 -> V_76 . V_78 ,
V_7 -> V_9 -> V_76 . V_79 ,
V_7 -> V_9 -> V_76 . V_80 ,
V_7 -> V_9 -> V_76 . V_81 ) ;
F_17 ( V_45 . V_52 ) ;
}
void F_25 ( T_1 * V_7 )
{
T_4 V_23 ;
struct V_82 V_83 ;
union V_46 V_84 [ 3 ] ;
struct V_85 * V_86 = & V_7 -> V_9 -> V_86 ;
struct V_85 * V_87 = & V_7 -> V_9 -> V_87 ;
V_83 . V_88 = 3 ;
V_83 . V_52 = V_84 ;
V_84 [ 0 ] . type = V_56 ;
V_84 [ 0 ] . V_58 . V_50 = sizeof( struct V_75 ) ;
V_84 [ 0 ] . V_58 . V_52 = ( T_6 * ) & V_7 -> V_9 -> V_76 ;
V_84 [ 1 ] . type = V_56 ;
V_84 [ 1 ] . V_58 . V_50 = V_89 * 2 ;
V_84 [ 1 ] . V_58 . V_52 = ( T_6 * ) & V_86 -> V_90 ;
V_84 [ 2 ] . type = V_56 ;
V_84 [ 2 ] . V_58 . V_50 = V_89 * 2 ;
V_84 [ 2 ] . V_58 . V_52 = ( T_6 * ) & V_87 -> V_90 ;
V_23 = F_20 ( V_7 -> V_9 -> V_48 , L_41 ,
& V_83 , NULL ) ;
if ( F_16 ( V_23 ) ) {
F_13 ( L_42 , V_23 ) ;
}
F_13 ( L_43 , V_23 ) ;
}
void F_26 ( T_1 * V_7 , int V_91 )
{
T_5 * V_40 ;
int V_92 ;
if ( V_3 )
return;
F_13 ( L_44 ) ;
if ( V_91 )
F_27 ( V_7 -> V_9 -> V_48 , V_93 ) ;
F_28 (i, drive, hwif) {
if ( V_40 -> V_9 -> V_48 )
F_27 ( V_40 -> V_9 -> V_48 ,
V_91 ? V_93 : V_94 ) ;
}
if ( ! V_91 )
F_27 ( V_7 -> V_9 -> V_48 ,
V_94 ) ;
}
void F_29 ( T_1 * V_7 )
{
V_7 -> V_9 = F_30 ( sizeof( struct V_95 ) , V_96 ) ;
if ( ! V_7 -> V_9 )
return;
V_7 -> V_9 -> V_48 = F_18 ( V_7 ) ;
if ( ! V_7 -> V_9 -> V_48 ) {
F_13 ( L_45 , V_7 -> V_38 ) ;
F_17 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
}
void F_31 ( T_1 * V_7 )
{
T_5 * V_40 ;
int V_92 , V_30 ;
if ( V_7 -> V_9 == NULL )
return;
V_7 -> V_97 [ 0 ] -> V_9 = & V_7 -> V_9 -> V_86 ;
V_7 -> V_97 [ 1 ] -> V_9 = & V_7 -> V_9 -> V_87 ;
F_28 (i, drive, hwif) {
T_2 V_22 ;
F_13 ( L_46 ,
V_40 -> V_38 , V_7 -> V_39 , V_40 -> V_74 & 1 ) ;
V_22 = F_6 ( V_7 -> V_9 -> V_48 ,
V_40 -> V_74 & 1 ) ;
F_13 ( L_47 , V_40 -> V_38 , V_22 ) ;
V_40 -> V_9 -> V_48 = V_22 ;
}
F_28 (i, drive, hwif) {
V_30 = F_32 ( V_40 , V_40 -> V_9 -> V_90 ) ;
if ( V_30 )
F_13 ( L_48 ,
V_40 -> V_38 , V_30 ) ;
}
if ( V_8 || V_98 == 0 ) {
F_13 ( L_49 ) ;
return;
}
F_26 ( V_7 , 1 ) ;
F_24 ( V_7 ) ;
F_25 ( V_7 ) ;
F_28 (i, drive, hwif) {
F_23 ( V_40 ) ;
}
}
