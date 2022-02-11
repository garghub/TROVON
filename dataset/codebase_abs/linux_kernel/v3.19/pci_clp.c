static inline void F_1 ( unsigned int V_1 , int V_2 )
{
struct {
unsigned int V_1 ;
int V_2 ;
} V_3 V_4 = { V_1 , V_2 } ;
F_2 ( & V_4 , sizeof( V_4 ) ) ;
}
static inline T_1 F_3 ( void * V_4 )
{
struct { T_1 _ [ V_5 ] ; } * V_6 = V_4 ;
T_2 V_7 ;
T_1 V_8 ;
asm volatile (
" .insn rrf,0xb9a00000,%[ign],%[req],0x0,0x2\n"
" ipm %[cc]\n"
" srl %[cc],28\n"
: [cc] "=d" (cc), [ign] "=d" (ignored), "+m" (*req)
: [req] "a" (req)
: "cc");
return V_8 ;
}
static void * F_4 ( T_3 V_9 )
{
return ( void * ) F_5 ( V_9 , F_6 ( V_5 ) ) ;
}
static void F_7 ( void * V_10 )
{
F_8 ( ( unsigned long ) V_10 , F_6 ( V_5 ) ) ;
}
static void F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_12 -> V_15 = V_14 -> V_16 ;
V_12 -> V_17 = V_14 -> V_18 ;
V_12 -> V_19 = V_14 -> V_20 ;
V_12 -> V_21 = V_14 -> V_22 ;
V_12 -> V_23 = V_14 -> V_24 ;
switch ( V_14 -> V_25 ) {
case 1 :
V_12 -> V_26 = V_27 ;
break;
default:
V_12 -> V_26 = V_28 ;
break;
}
}
static int F_10 ( struct V_11 * V_12 , T_1 V_29 )
{
struct V_30 * V_31 ;
int V_2 ;
V_31 = F_4 ( V_32 ) ;
if ( ! V_31 )
return - V_33 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_34 . V_35 . V_36 = sizeof( V_31 -> V_34 ) ;
V_31 -> V_34 . V_35 . V_37 = V_38 ;
V_31 -> V_14 . V_35 . V_36 = sizeof( V_31 -> V_14 ) ;
V_31 -> V_34 . V_29 = V_29 ;
V_2 = F_3 ( V_31 ) ;
if ( ! V_2 && V_31 -> V_14 . V_35 . V_1 == V_39 )
F_9 ( V_12 , & V_31 -> V_14 ) ;
else {
F_11 ( L_1 ) ;
F_1 ( V_31 -> V_14 . V_35 . V_1 , V_2 ) ;
V_2 = - V_40 ;
}
F_7 ( V_31 ) ;
return V_2 ;
}
static int F_12 ( struct V_11 * V_12 ,
struct V_41 * V_14 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_12 -> V_44 [ V_42 ] . V_45 = F_13 ( V_14 -> V_46 [ V_42 ] ) ;
V_12 -> V_44 [ V_42 ] . V_47 = V_14 -> V_48 [ V_42 ] ;
}
V_12 -> V_49 = V_14 -> V_50 ;
V_12 -> V_51 = V_14 -> V_52 ;
V_12 -> V_53 = V_14 -> V_53 ;
V_12 -> V_29 = V_14 -> V_29 ;
V_12 -> V_54 = V_14 -> V_54 ;
V_12 -> V_55 = V_14 -> V_55 ;
V_12 -> V_56 = V_14 -> V_56 ;
memcpy ( V_12 -> V_57 , V_14 -> V_57 , sizeof( V_12 -> V_57 ) ) ;
if ( V_14 -> V_58 ) {
memcpy ( V_12 -> V_59 , V_14 -> V_59 ,
sizeof( V_12 -> V_59 ) ) ;
}
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , T_4 V_60 )
{
struct V_61 * V_31 ;
int V_2 ;
V_31 = F_4 ( V_32 ) ;
if ( ! V_31 )
return - V_33 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_34 . V_35 . V_36 = sizeof( V_31 -> V_34 ) ;
V_31 -> V_34 . V_35 . V_37 = V_62 ;
V_31 -> V_14 . V_35 . V_36 = sizeof( V_31 -> V_14 ) ;
V_31 -> V_34 . V_60 = V_60 ;
V_2 = F_3 ( V_31 ) ;
if ( ! V_2 && V_31 -> V_14 . V_35 . V_1 == V_39 ) {
V_2 = F_12 ( V_12 , & V_31 -> V_14 ) ;
if ( V_2 )
goto V_63;
if ( V_31 -> V_14 . V_29 )
V_2 = F_10 ( V_12 , V_31 -> V_14 . V_29 ) ;
} else {
F_11 ( L_2 ) ;
F_1 ( V_31 -> V_14 . V_35 . V_1 , V_2 ) ;
V_2 = - V_40 ;
}
V_63:
F_7 ( V_31 ) ;
return V_2 ;
}
int F_15 ( T_4 V_64 , T_4 V_60 , int V_65 )
{
struct V_11 * V_12 ;
int V_2 ;
F_16 ( 3 , L_3 , V_64 , V_60 , V_65 ) ;
V_12 = F_17 ( sizeof( * V_12 ) , V_32 ) ;
if ( ! V_12 )
return - V_33 ;
V_12 -> V_60 = V_60 ;
V_12 -> V_64 = V_64 ;
V_2 = F_14 ( V_12 , V_60 ) ;
if ( V_2 )
goto error;
if ( V_65 )
V_12 -> V_66 = V_67 ;
else
V_12 -> V_66 = V_68 ;
V_2 = F_18 ( V_12 ) ;
if ( V_2 )
goto error;
return 0 ;
error:
F_19 ( V_12 ) ;
return V_2 ;
}
static int F_20 ( T_4 * V_60 , T_1 V_69 , T_1 V_70 )
{
struct V_71 * V_31 ;
int V_2 , V_72 = 100 ;
V_31 = F_4 ( V_32 ) ;
if ( ! V_31 )
return - V_33 ;
do {
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_34 . V_35 . V_36 = sizeof( V_31 -> V_34 ) ;
V_31 -> V_34 . V_35 . V_37 = V_73 ;
V_31 -> V_14 . V_35 . V_36 = sizeof( V_31 -> V_14 ) ;
V_31 -> V_34 . V_60 = * V_60 ;
V_31 -> V_34 . V_74 = V_70 ;
V_31 -> V_34 . V_75 = V_69 ;
V_2 = F_3 ( V_31 ) ;
if ( V_31 -> V_14 . V_35 . V_1 == V_76 ) {
V_72 -- ;
if ( V_72 < 0 )
break;
F_21 ( 20 ) ;
}
} while ( V_31 -> V_14 . V_35 . V_1 == V_76 );
if ( ! V_2 && V_31 -> V_14 . V_35 . V_1 == V_39 )
* V_60 = V_31 -> V_14 . V_60 ;
else {
F_11 ( L_4 ) ;
F_1 ( V_31 -> V_14 . V_35 . V_1 , V_2 ) ;
V_2 = - V_40 ;
}
F_7 ( V_31 ) ;
return V_2 ;
}
int F_22 ( struct V_11 * V_12 , T_1 V_69 )
{
T_4 V_60 = V_12 -> V_60 ;
int V_2 ;
V_2 = F_20 ( & V_60 , V_69 , V_77 ) ;
if ( ! V_2 )
V_12 -> V_60 = V_60 ;
F_16 ( 3 , L_5 , V_12 -> V_64 , V_12 -> V_60 , V_2 ) ;
return V_2 ;
}
int F_23 ( struct V_11 * V_12 )
{
T_4 V_60 = V_12 -> V_60 ;
int V_2 ;
if ( ! F_24 ( V_12 ) )
return 0 ;
V_2 = F_20 ( & V_60 , 0 , V_78 ) ;
if ( ! V_2 )
V_12 -> V_60 = V_60 ;
F_16 ( 3 , L_6 , V_12 -> V_64 , V_12 -> V_60 , V_2 ) ;
return V_2 ;
}
static int F_25 ( struct V_79 * V_31 ,
void (* F_26)( struct V_80 * V_81 ) )
{
T_2 V_82 = 0 ;
int V_83 , V_42 , V_2 ;
do {
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_34 . V_35 . V_36 = sizeof( V_31 -> V_34 ) ;
V_31 -> V_34 . V_35 . V_37 = V_84 ;
V_31 -> V_14 . V_35 . V_36 = V_5 - V_85 ;
V_31 -> V_34 . V_82 = V_82 ;
V_2 = F_3 ( V_31 ) ;
if ( V_2 || V_31 -> V_14 . V_35 . V_1 != V_39 ) {
F_11 ( L_7 ) ;
F_1 ( V_31 -> V_14 . V_35 . V_1 , V_2 ) ;
V_2 = - V_40 ;
goto V_63;
}
F_27 ( V_31 -> V_14 . V_86 !=
sizeof( struct V_80 ) ) ;
V_83 = ( V_31 -> V_14 . V_35 . V_36 - V_85 ) /
V_31 -> V_14 . V_86 ;
V_82 = V_31 -> V_14 . V_82 ;
for ( V_42 = 0 ; V_42 < V_83 ; V_42 ++ )
F_26 ( & V_31 -> V_14 . V_87 [ V_42 ] ) ;
} while ( V_82 );
V_63:
return V_2 ;
}
static void F_28 ( struct V_80 * V_81 )
{
if ( ! V_81 -> V_88 )
return;
F_15 ( V_81 -> V_64 , V_81 -> V_60 , V_81 -> V_89 ) ;
}
static void F_29 ( struct V_80 * V_81 )
{
struct V_11 * V_12 ;
if ( ! V_81 -> V_88 )
return;
V_12 = F_30 ( V_81 -> V_64 ) ;
if ( ! V_12 ) {
F_15 ( V_81 -> V_64 , V_81 -> V_60 , V_81 -> V_89 ) ;
return;
}
if ( ! V_81 -> V_89 ) {
F_31 ( V_12 ) ;
}
}
static void F_32 ( struct V_80 * V_81 )
{
struct V_11 * V_12 ;
if ( ! V_81 -> V_88 )
return;
V_12 = F_30 ( V_81 -> V_64 ) ;
if ( ! V_12 )
return;
V_12 -> V_60 = V_81 -> V_60 ;
}
int F_33 ( void )
{
struct V_79 * V_31 ;
int V_2 ;
V_31 = F_4 ( V_32 ) ;
if ( ! V_31 )
return - V_33 ;
V_2 = F_25 ( V_31 , F_28 ) ;
F_7 ( V_31 ) ;
return V_2 ;
}
int F_34 ( void )
{
struct V_79 * V_31 ;
int V_2 ;
V_31 = F_4 ( V_32 ) ;
if ( ! V_31 )
return - V_33 ;
V_2 = F_25 ( V_31 , F_29 ) ;
F_7 ( V_31 ) ;
return V_2 ;
}
int F_35 ( void )
{
struct V_79 * V_31 ;
int V_2 ;
V_31 = F_4 ( V_90 ) ;
if ( ! V_31 )
return - V_33 ;
V_2 = F_25 ( V_31 , F_32 ) ;
F_7 ( V_31 ) ;
return V_2 ;
}
