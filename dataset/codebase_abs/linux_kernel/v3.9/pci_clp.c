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
static void * F_2 ( void )
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
V_27 = F_2 () ;
if ( ! V_27 )
return - V_29 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_30 . V_31 . V_32 = sizeof( V_27 -> V_30 ) ;
V_27 -> V_30 . V_31 . V_33 = V_34 ;
V_27 -> V_11 . V_31 . V_32 = sizeof( V_27 -> V_11 ) ;
V_27 -> V_30 . V_25 = V_25 ;
V_28 = F_1 ( V_27 ) ;
if ( ! V_28 && V_27 -> V_11 . V_31 . V_35 == V_36 )
F_7 ( V_9 , & V_27 -> V_11 ) ;
else {
F_10 ( L_2 ,
V_27 -> V_11 . V_31 . V_35 , V_28 ) ;
V_28 = - V_37 ;
}
F_5 ( V_27 ) ;
return V_28 ;
}
static int F_11 ( struct V_8 * V_9 ,
struct V_38 * V_11 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_9 -> V_41 [ V_39 ] . V_42 = F_12 ( V_11 -> V_43 [ V_39 ] ) ;
V_9 -> V_41 [ V_39 ] . V_44 = V_11 -> V_45 [ V_39 ] ;
}
V_9 -> V_46 = V_11 -> V_47 ;
V_9 -> V_48 = V_11 -> V_49 ;
V_9 -> V_50 = V_11 -> V_50 ;
V_9 -> V_25 = V_11 -> V_25 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , T_3 V_51 )
{
struct V_52 * V_27 ;
int V_28 ;
V_27 = F_2 () ;
if ( ! V_27 )
return - V_29 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_30 . V_31 . V_32 = sizeof( V_27 -> V_30 ) ;
V_27 -> V_30 . V_31 . V_33 = V_53 ;
V_27 -> V_11 . V_31 . V_32 = sizeof( V_27 -> V_11 ) ;
V_27 -> V_30 . V_51 = V_51 ;
V_28 = F_1 ( V_27 ) ;
if ( ! V_28 && V_27 -> V_11 . V_31 . V_35 == V_36 ) {
V_28 = F_11 ( V_9 , & V_27 -> V_11 ) ;
if ( V_28 )
goto V_54;
if ( V_27 -> V_11 . V_25 )
V_28 = F_9 ( V_9 , V_27 -> V_11 . V_25 ) ;
} else {
F_10 ( L_3 ,
V_27 -> V_11 . V_31 . V_35 , V_28 ) ;
V_28 = - V_37 ;
}
V_54:
F_5 ( V_27 ) ;
return V_28 ;
}
int F_14 ( T_3 V_55 , T_3 V_51 , int V_56 )
{
struct V_8 * V_9 ;
int V_28 ;
V_9 = F_15 () ;
if ( F_16 ( V_9 ) )
return F_17 ( V_9 ) ;
V_9 -> V_51 = V_51 ;
V_9 -> V_55 = V_55 ;
V_28 = F_13 ( V_9 , V_51 ) ;
if ( V_28 )
goto error;
if ( V_56 )
V_9 -> V_57 = V_58 ;
else
V_9 -> V_57 = V_59 ;
V_28 = F_18 ( V_9 ) ;
if ( V_28 )
goto error;
return 0 ;
error:
F_19 ( V_9 ) ;
return V_28 ;
}
static int F_20 ( T_3 * V_51 , T_1 V_60 , T_1 V_61 )
{
struct V_62 * V_27 ;
int V_28 , V_63 = 1000 ;
V_27 = F_2 () ;
if ( ! V_27 )
return - V_29 ;
do {
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_30 . V_31 . V_32 = sizeof( V_27 -> V_30 ) ;
V_27 -> V_30 . V_31 . V_33 = V_64 ;
V_27 -> V_11 . V_31 . V_32 = sizeof( V_27 -> V_11 ) ;
V_27 -> V_30 . V_51 = * V_51 ;
V_27 -> V_30 . V_65 = V_61 ;
V_27 -> V_30 . V_66 = V_60 ;
V_28 = F_1 ( V_27 ) ;
if ( V_27 -> V_11 . V_31 . V_35 == V_67 ) {
V_63 -- ;
if ( V_63 < 0 )
break;
F_21 ( 1 ) ;
}
} while ( V_27 -> V_11 . V_31 . V_35 == V_67 );
if ( ! V_28 && V_27 -> V_11 . V_31 . V_35 == V_36 )
* V_51 = V_27 -> V_11 . V_51 ;
else {
F_10 ( L_4 ,
V_27 -> V_11 . V_31 . V_35 , V_28 ) ;
V_28 = - V_37 ;
}
F_5 ( V_27 ) ;
return V_28 ;
}
int F_22 ( struct V_8 * V_9 , T_1 V_60 )
{
T_3 V_51 = V_9 -> V_51 ;
int V_28 ;
V_28 = F_20 ( & V_51 , V_60 , V_68 ) ;
if ( ! V_28 )
V_9 -> V_51 = V_51 ;
return V_28 ;
}
int F_23 ( struct V_8 * V_9 )
{
T_3 V_51 = V_9 -> V_51 ;
int V_28 ;
if ( ! F_24 ( V_9 ) )
return 0 ;
F_25 ( & V_9 -> V_69 -> V_70 , L_5 , V_51 ) ;
V_28 = F_20 ( & V_51 , 0 , V_71 ) ;
if ( ! V_28 )
V_9 -> V_51 = V_51 ;
else
F_26 ( & V_9 -> V_69 -> V_70 ,
L_6 , V_51 ) ;
return V_28 ;
}
static void F_27 ( struct V_72 * V_73 )
{
int V_74 , V_28 ;
if ( ! V_73 -> V_75 )
return;
V_74 = F_28 ( V_73 -> V_55 ) ;
if ( V_74 )
F_8 ( L_7 , V_76 , V_73 -> V_55 ) ;
if ( V_74 && V_73 -> V_77 )
return;
if ( V_74 && ! V_73 -> V_77 ) {
F_29 ( F_30 ( V_73 -> V_55 ) ) ;
return;
}
V_28 = F_14 ( V_73 -> V_55 , V_73 -> V_51 , V_73 -> V_77 ) ;
if ( V_28 )
F_10 ( L_8 , V_73 -> V_55 ) ;
}
int F_31 ( void )
{
struct V_78 * V_27 ;
T_2 V_79 = 0 ;
int V_80 , V_39 , V_28 ;
V_27 = F_2 () ;
if ( ! V_27 )
return - V_29 ;
do {
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_30 . V_31 . V_32 = sizeof( V_27 -> V_30 ) ;
V_27 -> V_30 . V_31 . V_33 = V_81 ;
V_27 -> V_11 . V_31 . V_32 = V_2 - V_82 ;
V_27 -> V_30 . V_79 = V_79 ;
V_28 = F_1 ( V_27 ) ;
if ( V_28 || V_27 -> V_11 . V_31 . V_35 != V_36 ) {
F_10 ( L_9 ,
V_27 -> V_11 . V_31 . V_35 , V_28 ) ;
V_28 = - V_37 ;
goto V_54;
}
F_32 ( V_27 -> V_11 . V_83 !=
sizeof( struct V_72 ) ) ;
V_80 = ( V_27 -> V_11 . V_31 . V_32 - V_82 ) /
V_27 -> V_11 . V_83 ;
F_33 ( L_10 , V_80 ) ;
V_79 = V_27 -> V_11 . V_79 ;
for ( V_39 = 0 ; V_39 < V_80 ; V_39 ++ )
F_27 ( & V_27 -> V_11 . V_84 [ V_39 ] ) ;
} while ( V_79 );
F_8 ( L_11 ,
V_27 -> V_11 . V_85 ) ;
V_54:
F_5 ( V_27 ) ;
return V_28 ;
}
