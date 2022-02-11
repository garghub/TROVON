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
switch ( V_14 -> V_23 ) {
case 1 :
V_12 -> V_24 = V_25 ;
break;
default:
V_12 -> V_24 = V_26 ;
break;
}
}
static int F_10 ( struct V_11 * V_12 , T_1 V_27 )
{
struct V_28 * V_29 ;
int V_2 ;
V_29 = F_4 ( V_30 ) ;
if ( ! V_29 )
return - V_31 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_32 . V_33 . V_34 = sizeof( V_29 -> V_32 ) ;
V_29 -> V_32 . V_33 . V_35 = V_36 ;
V_29 -> V_14 . V_33 . V_34 = sizeof( V_29 -> V_14 ) ;
V_29 -> V_32 . V_27 = V_27 ;
V_2 = F_3 ( V_29 ) ;
if ( ! V_2 && V_29 -> V_14 . V_33 . V_1 == V_37 )
F_9 ( V_12 , & V_29 -> V_14 ) ;
else {
F_11 ( L_1 ) ;
F_1 ( V_29 -> V_14 . V_33 . V_1 , V_2 ) ;
V_2 = - V_38 ;
}
F_7 ( V_29 ) ;
return V_2 ;
}
static int F_12 ( struct V_11 * V_12 ,
struct V_39 * V_14 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
V_12 -> V_42 [ V_40 ] . V_43 = F_13 ( V_14 -> V_44 [ V_40 ] ) ;
V_12 -> V_42 [ V_40 ] . V_45 = V_14 -> V_46 [ V_40 ] ;
}
V_12 -> V_47 = V_14 -> V_48 ;
V_12 -> V_49 = V_14 -> V_50 ;
V_12 -> V_51 = V_14 -> V_51 ;
V_12 -> V_27 = V_14 -> V_27 ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , T_4 V_52 )
{
struct V_53 * V_29 ;
int V_2 ;
V_29 = F_4 ( V_30 ) ;
if ( ! V_29 )
return - V_31 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_32 . V_33 . V_34 = sizeof( V_29 -> V_32 ) ;
V_29 -> V_32 . V_33 . V_35 = V_54 ;
V_29 -> V_14 . V_33 . V_34 = sizeof( V_29 -> V_14 ) ;
V_29 -> V_32 . V_52 = V_52 ;
V_2 = F_3 ( V_29 ) ;
if ( ! V_2 && V_29 -> V_14 . V_33 . V_1 == V_37 ) {
V_2 = F_12 ( V_12 , & V_29 -> V_14 ) ;
if ( V_2 )
goto V_55;
if ( V_29 -> V_14 . V_27 )
V_2 = F_10 ( V_12 , V_29 -> V_14 . V_27 ) ;
} else {
F_11 ( L_2 ) ;
F_1 ( V_29 -> V_14 . V_33 . V_1 , V_2 ) ;
V_2 = - V_38 ;
}
V_55:
F_7 ( V_29 ) ;
return V_2 ;
}
int F_15 ( T_4 V_56 , T_4 V_52 , int V_57 )
{
struct V_11 * V_12 ;
int V_2 ;
F_16 ( 3 , L_3 , V_56 , V_52 , V_57 ) ;
V_12 = F_17 ( sizeof( * V_12 ) , V_30 ) ;
if ( ! V_12 )
return - V_31 ;
V_12 -> V_52 = V_52 ;
V_12 -> V_56 = V_56 ;
V_2 = F_14 ( V_12 , V_52 ) ;
if ( V_2 )
goto error;
if ( V_57 )
V_12 -> V_58 = V_59 ;
else
V_12 -> V_58 = V_60 ;
V_2 = F_18 ( V_12 ) ;
if ( V_2 )
goto error;
return 0 ;
error:
F_19 ( V_12 ) ;
return V_2 ;
}
static int F_20 ( T_4 * V_52 , T_1 V_61 , T_1 V_62 )
{
struct V_63 * V_29 ;
int V_2 , V_64 = 100 ;
V_29 = F_4 ( V_30 ) ;
if ( ! V_29 )
return - V_31 ;
do {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_32 . V_33 . V_34 = sizeof( V_29 -> V_32 ) ;
V_29 -> V_32 . V_33 . V_35 = V_65 ;
V_29 -> V_14 . V_33 . V_34 = sizeof( V_29 -> V_14 ) ;
V_29 -> V_32 . V_52 = * V_52 ;
V_29 -> V_32 . V_66 = V_62 ;
V_29 -> V_32 . V_67 = V_61 ;
V_2 = F_3 ( V_29 ) ;
if ( V_29 -> V_14 . V_33 . V_1 == V_68 ) {
V_64 -- ;
if ( V_64 < 0 )
break;
F_21 ( 20 ) ;
}
} while ( V_29 -> V_14 . V_33 . V_1 == V_68 );
if ( ! V_2 && V_29 -> V_14 . V_33 . V_1 == V_37 )
* V_52 = V_29 -> V_14 . V_52 ;
else {
F_11 ( L_4 ) ;
F_1 ( V_29 -> V_14 . V_33 . V_1 , V_2 ) ;
V_2 = - V_38 ;
}
F_7 ( V_29 ) ;
return V_2 ;
}
int F_22 ( struct V_11 * V_12 , T_1 V_61 )
{
T_4 V_52 = V_12 -> V_52 ;
int V_2 ;
V_2 = F_20 ( & V_52 , V_61 , V_69 ) ;
if ( ! V_2 )
V_12 -> V_52 = V_52 ;
F_16 ( 3 , L_5 , V_12 -> V_56 , V_12 -> V_52 , V_2 ) ;
return V_2 ;
}
int F_23 ( struct V_11 * V_12 )
{
T_4 V_52 = V_12 -> V_52 ;
int V_2 ;
if ( ! F_24 ( V_12 ) )
return 0 ;
V_2 = F_20 ( & V_52 , 0 , V_70 ) ;
if ( ! V_2 )
V_12 -> V_52 = V_52 ;
F_16 ( 3 , L_6 , V_12 -> V_56 , V_12 -> V_52 , V_2 ) ;
return V_2 ;
}
static int F_25 ( struct V_71 * V_29 ,
void (* F_26)( struct V_72 * V_73 ) )
{
T_2 V_74 = 0 ;
int V_75 , V_40 , V_2 ;
do {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_32 . V_33 . V_34 = sizeof( V_29 -> V_32 ) ;
V_29 -> V_32 . V_33 . V_35 = V_76 ;
V_29 -> V_14 . V_33 . V_34 = V_5 - V_77 ;
V_29 -> V_32 . V_74 = V_74 ;
V_2 = F_3 ( V_29 ) ;
if ( V_2 || V_29 -> V_14 . V_33 . V_1 != V_37 ) {
F_11 ( L_7 ) ;
F_1 ( V_29 -> V_14 . V_33 . V_1 , V_2 ) ;
V_2 = - V_38 ;
goto V_55;
}
F_27 ( V_29 -> V_14 . V_78 !=
sizeof( struct V_72 ) ) ;
V_75 = ( V_29 -> V_14 . V_33 . V_34 - V_77 ) /
V_29 -> V_14 . V_78 ;
V_74 = V_29 -> V_14 . V_74 ;
for ( V_40 = 0 ; V_40 < V_75 ; V_40 ++ )
F_26 ( & V_29 -> V_14 . V_79 [ V_40 ] ) ;
} while ( V_74 );
V_55:
return V_2 ;
}
static void F_28 ( struct V_72 * V_73 )
{
if ( ! V_73 -> V_80 )
return;
F_15 ( V_73 -> V_56 , V_73 -> V_52 , V_73 -> V_81 ) ;
}
static void F_29 ( struct V_72 * V_73 )
{
struct V_11 * V_12 ;
if ( ! V_73 -> V_80 )
return;
V_12 = F_30 ( V_73 -> V_56 ) ;
if ( ! V_12 ) {
F_15 ( V_73 -> V_56 , V_73 -> V_52 , V_73 -> V_81 ) ;
return;
}
if ( ! V_73 -> V_81 ) {
F_31 ( V_12 ) ;
}
}
static void F_32 ( struct V_72 * V_73 )
{
struct V_11 * V_12 ;
if ( ! V_73 -> V_80 )
return;
V_12 = F_30 ( V_73 -> V_56 ) ;
if ( ! V_12 )
return;
V_12 -> V_52 = V_73 -> V_52 ;
}
int F_33 ( void )
{
struct V_71 * V_29 ;
int V_2 ;
V_29 = F_4 ( V_30 ) ;
if ( ! V_29 )
return - V_31 ;
V_2 = F_25 ( V_29 , F_28 ) ;
F_7 ( V_29 ) ;
return V_2 ;
}
int F_34 ( void )
{
struct V_71 * V_29 ;
int V_2 ;
V_29 = F_4 ( V_30 ) ;
if ( ! V_29 )
return - V_31 ;
V_2 = F_25 ( V_29 , F_29 ) ;
F_7 ( V_29 ) ;
return V_2 ;
}
int F_35 ( void )
{
struct V_71 * V_29 ;
int V_2 ;
V_29 = F_4 ( V_82 ) ;
if ( ! V_29 )
return - V_31 ;
V_2 = F_25 ( V_29 , F_32 ) ;
F_7 ( V_29 ) ;
return V_2 ;
}
