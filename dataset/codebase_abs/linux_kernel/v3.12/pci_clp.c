static inline T_1 F_1 ( void * V_1 )
{
struct { T_1 _ [ V_2 ] ; } * V_3 = V_1 ;
T_2 V_4 ;
T_1 V_5 ;
asm volatile (
" .insn rrf,0xb9a00000,%[ign],%[req],0x0,0x2\n"
" ipm %[cc]\n"
" srl %[cc],28\n"
: [cc] "=d" (cc), [ign] "=d" (ignored), "+m" (*req)
: [req] "a" (req)
: "cc");
return V_5 ;
}
static void * F_2 ( T_3 V_6 )
{
return ( void * ) F_3 ( V_6 , F_4 ( V_2 ) ) ;
}
static void F_5 ( void * V_7 )
{
F_6 ( ( unsigned long ) V_7 , F_4 ( V_2 ) ) ;
}
static void F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
V_9 -> V_12 = V_11 -> V_13 ;
V_9 -> V_14 = V_11 -> V_15 ;
V_9 -> V_16 = V_11 -> V_17 ;
V_9 -> V_18 = V_11 -> V_19 ;
F_8 ( L_1 , V_11 -> V_20 ) ;
switch ( V_11 -> V_21 ) {
case 1 :
V_9 -> V_22 = V_23 ;
break;
default:
V_9 -> V_22 = V_24 ;
break;
}
}
static int F_9 ( struct V_8 * V_9 , T_1 V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
V_27 = F_2 ( V_29 ) ;
if ( ! V_27 )
return - V_30 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_31 . V_32 . V_33 = sizeof( V_27 -> V_31 ) ;
V_27 -> V_31 . V_32 . V_34 = V_35 ;
V_27 -> V_11 . V_32 . V_33 = sizeof( V_27 -> V_11 ) ;
V_27 -> V_31 . V_25 = V_25 ;
V_28 = F_1 ( V_27 ) ;
if ( ! V_28 && V_27 -> V_11 . V_32 . V_36 == V_37 )
F_7 ( V_9 , & V_27 -> V_11 ) ;
else {
F_10 ( L_2 ,
V_27 -> V_11 . V_32 . V_36 , V_28 ) ;
V_28 = - V_38 ;
}
F_5 ( V_27 ) ;
return V_28 ;
}
static int F_11 ( struct V_8 * V_9 ,
struct V_39 * V_11 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
V_9 -> V_42 [ V_40 ] . V_43 = F_12 ( V_11 -> V_44 [ V_40 ] ) ;
V_9 -> V_42 [ V_40 ] . V_45 = V_11 -> V_46 [ V_40 ] ;
}
V_9 -> V_47 = V_11 -> V_48 ;
V_9 -> V_49 = V_11 -> V_50 ;
V_9 -> V_51 = V_11 -> V_51 ;
V_9 -> V_25 = V_11 -> V_25 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , T_4 V_52 )
{
struct V_53 * V_27 ;
int V_28 ;
V_27 = F_2 ( V_29 ) ;
if ( ! V_27 )
return - V_30 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_31 . V_32 . V_33 = sizeof( V_27 -> V_31 ) ;
V_27 -> V_31 . V_32 . V_34 = V_54 ;
V_27 -> V_11 . V_32 . V_33 = sizeof( V_27 -> V_11 ) ;
V_27 -> V_31 . V_52 = V_52 ;
V_28 = F_1 ( V_27 ) ;
if ( ! V_28 && V_27 -> V_11 . V_32 . V_36 == V_37 ) {
V_28 = F_11 ( V_9 , & V_27 -> V_11 ) ;
if ( V_28 )
goto V_55;
if ( V_27 -> V_11 . V_25 )
V_28 = F_9 ( V_9 , V_27 -> V_11 . V_25 ) ;
} else {
F_10 ( L_3 ,
V_27 -> V_11 . V_32 . V_36 , V_28 ) ;
V_28 = - V_38 ;
}
V_55:
F_5 ( V_27 ) ;
return V_28 ;
}
int F_14 ( T_4 V_56 , T_4 V_52 , int V_57 )
{
struct V_8 * V_9 ;
int V_28 ;
F_15 ( 3 , L_4 , V_56 , V_52 , V_57 ) ;
V_9 = F_16 () ;
if ( F_17 ( V_9 ) )
return F_18 ( V_9 ) ;
V_9 -> V_52 = V_52 ;
V_9 -> V_56 = V_56 ;
V_28 = F_13 ( V_9 , V_52 ) ;
if ( V_28 )
goto error;
if ( V_57 )
V_9 -> V_58 = V_59 ;
else
V_9 -> V_58 = V_60 ;
V_28 = F_19 ( V_9 ) ;
if ( V_28 )
goto error;
return 0 ;
error:
F_20 ( V_9 ) ;
return V_28 ;
}
static int F_21 ( T_4 * V_52 , T_1 V_61 , T_1 V_62 )
{
struct V_63 * V_27 ;
int V_28 , V_64 = 100 ;
V_27 = F_2 ( V_29 ) ;
if ( ! V_27 )
return - V_30 ;
do {
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_31 . V_32 . V_33 = sizeof( V_27 -> V_31 ) ;
V_27 -> V_31 . V_32 . V_34 = V_65 ;
V_27 -> V_11 . V_32 . V_33 = sizeof( V_27 -> V_11 ) ;
V_27 -> V_31 . V_52 = * V_52 ;
V_27 -> V_31 . V_66 = V_62 ;
V_27 -> V_31 . V_67 = V_61 ;
V_28 = F_1 ( V_27 ) ;
if ( V_27 -> V_11 . V_32 . V_36 == V_68 ) {
V_64 -- ;
if ( V_64 < 0 )
break;
F_22 ( 20 ) ;
}
} while ( V_27 -> V_11 . V_32 . V_36 == V_68 );
if ( ! V_28 && V_27 -> V_11 . V_32 . V_36 == V_37 )
* V_52 = V_27 -> V_11 . V_52 ;
else {
F_15 ( 0 , L_5 , * V_52 , V_28 ,
V_27 -> V_11 . V_32 . V_36 ) ;
V_28 = - V_38 ;
}
F_5 ( V_27 ) ;
return V_28 ;
}
int F_23 ( struct V_8 * V_9 , T_1 V_61 )
{
T_4 V_52 = V_9 -> V_52 ;
int V_28 ;
V_28 = F_21 ( & V_52 , V_61 , V_69 ) ;
if ( ! V_28 )
V_9 -> V_52 = V_52 ;
F_15 ( 3 , L_6 , V_9 -> V_56 , V_9 -> V_52 , V_28 ) ;
return V_28 ;
}
int F_24 ( struct V_8 * V_9 )
{
T_4 V_52 = V_9 -> V_52 ;
int V_28 ;
if ( ! F_25 ( V_9 ) )
return 0 ;
V_28 = F_21 ( & V_52 , 0 , V_70 ) ;
if ( ! V_28 )
V_9 -> V_52 = V_52 ;
F_15 ( 3 , L_7 , V_9 -> V_56 , V_9 -> V_52 , V_28 ) ;
return V_28 ;
}
static int F_26 ( struct V_71 * V_27 ,
void (* F_27)( struct V_72 * V_73 ) )
{
T_2 V_74 = 0 ;
int V_75 , V_40 , V_28 ;
do {
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_31 . V_32 . V_33 = sizeof( V_27 -> V_31 ) ;
V_27 -> V_31 . V_32 . V_34 = V_76 ;
V_27 -> V_11 . V_32 . V_33 = V_2 - V_77 ;
V_27 -> V_31 . V_74 = V_74 ;
V_28 = F_1 ( V_27 ) ;
if ( V_28 || V_27 -> V_11 . V_32 . V_36 != V_37 ) {
F_10 ( L_8 ,
V_27 -> V_11 . V_32 . V_36 , V_28 ) ;
V_28 = - V_38 ;
goto V_55;
}
F_28 ( V_27 -> V_11 . V_78 !=
sizeof( struct V_72 ) ) ;
V_75 = ( V_27 -> V_11 . V_32 . V_33 - V_77 ) /
V_27 -> V_11 . V_78 ;
F_29 ( L_9 , V_75 ) ;
V_74 = V_27 -> V_11 . V_74 ;
for ( V_40 = 0 ; V_40 < V_75 ; V_40 ++ )
F_27 ( & V_27 -> V_11 . V_79 [ V_40 ] ) ;
} while ( V_74 );
F_8 ( L_10 ,
V_27 -> V_11 . V_80 ) ;
V_55:
return V_28 ;
}
static void F_30 ( struct V_72 * V_73 )
{
if ( ! V_73 -> V_81 )
return;
F_14 ( V_73 -> V_56 , V_73 -> V_52 , V_73 -> V_82 ) ;
}
static void F_31 ( struct V_72 * V_73 )
{
struct V_8 * V_9 ;
if ( ! V_73 -> V_81 )
return;
V_9 = F_32 ( V_73 -> V_56 ) ;
if ( ! V_9 ) {
F_14 ( V_73 -> V_56 , V_73 -> V_52 , V_73 -> V_82 ) ;
return;
}
if ( ! V_73 -> V_82 ) {
F_33 ( V_9 ) ;
}
}
static void F_34 ( struct V_72 * V_73 )
{
struct V_8 * V_9 ;
if ( ! V_73 -> V_81 )
return;
V_9 = F_32 ( V_73 -> V_56 ) ;
if ( ! V_9 )
return;
V_9 -> V_52 = V_73 -> V_52 ;
}
int F_35 ( void )
{
struct V_71 * V_27 ;
int V_28 ;
V_27 = F_2 ( V_29 ) ;
if ( ! V_27 )
return - V_30 ;
V_28 = F_26 ( V_27 , F_30 ) ;
F_5 ( V_27 ) ;
return V_28 ;
}
int F_36 ( void )
{
struct V_71 * V_27 ;
int V_28 ;
V_27 = F_2 ( V_29 ) ;
if ( ! V_27 )
return - V_30 ;
V_28 = F_26 ( V_27 , F_31 ) ;
F_5 ( V_27 ) ;
return V_28 ;
}
int F_37 ( void )
{
struct V_71 * V_27 ;
int V_28 ;
V_27 = F_2 ( V_83 ) ;
if ( ! V_27 )
return - V_30 ;
V_28 = F_26 ( V_27 , F_34 ) ;
F_5 ( V_27 ) ;
return V_28 ;
}
