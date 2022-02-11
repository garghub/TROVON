static T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 ,
T_3 V_4 )
{
T_2 * V_5 ;
T_1 V_6 ;
if ( ! V_2 -> V_7 )
return - V_8 ;
V_5 = F_2 ( V_3 , V_4 , V_9 ) ;
if ( ! V_5 )
return - V_10 ;
V_6 = V_2 -> V_7 ( V_2 , V_5 , V_4 , V_11 ) ;
F_3 ( V_5 ) ;
return V_6 ;
}
static void F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 , struct V_14 ,
V_16 ) ;
unsigned long V_17 ;
F_6 ( & V_15 -> V_18 , V_17 ) ;
while ( V_15 -> V_19 != V_15 -> V_20 ) {
F_7 ( & V_15 -> V_18 , V_17 ) ;
F_1 ( V_15 -> V_2 , V_15 -> V_21 [ V_15 -> V_20 ] . V_22 ,
V_15 -> V_21 [ V_15 -> V_20 ] . V_23 ) ;
F_6 ( & V_15 -> V_18 , V_17 ) ;
V_15 -> V_20 = ( V_15 -> V_20 + 1 ) % V_24 ;
}
F_7 ( & V_15 -> V_18 , V_17 ) ;
}
static void F_8 ( struct V_14 * V_15 , const T_2 * V_3 ,
T_3 V_4 )
{
unsigned long V_17 ;
T_2 V_25 ;
if ( V_4 > V_26 ) {
F_9 ( V_15 -> V_2 , L_1 ) ;
return;
}
F_6 ( & V_15 -> V_18 , V_17 ) ;
memcpy ( V_15 -> V_21 [ V_15 -> V_19 ] . V_22 , V_3 , V_4 ) ;
V_15 -> V_21 [ V_15 -> V_19 ] . V_23 = V_4 ;
V_25 = ( V_15 -> V_19 + 1 ) % V_24 ;
if ( V_15 -> V_19 == V_15 -> V_20 ) {
V_15 -> V_19 = V_25 ;
F_10 ( & V_15 -> V_16 ) ;
} else if ( V_25 != V_15 -> V_20 ) {
V_15 -> V_19 = V_25 ;
} else {
F_9 ( V_15 -> V_2 , L_2 ) ;
}
F_7 ( & V_15 -> V_18 , V_17 ) ;
}
static void F_11 ( struct V_14 * V_15 , int V_27 )
{
T_2 V_28 [ 2 ] ;
V_27 &= V_29 ;
if ( ( V_15 -> V_30 . V_17 & V_29 ) == V_27 )
return;
V_15 -> V_30 . V_17 = ( V_15 -> V_30 . V_17 & ~ V_29 ) | V_27 ;
V_28 [ 0 ] = V_31 ;
V_28 [ 1 ] = 0 ;
if ( V_27 & V_32 )
V_28 [ 1 ] |= 0x10 ;
if ( V_27 & V_33 )
V_28 [ 1 ] |= 0x20 ;
if ( V_27 & V_34 )
V_28 [ 1 ] |= 0x40 ;
if ( V_27 & V_35 )
V_28 [ 1 ] |= 0x80 ;
F_8 ( V_15 , V_28 , sizeof( V_28 ) ) ;
}
static T_2 F_12 ( struct V_14 * V_15 )
{
return V_36 ;
}
static void F_13 ( struct V_14 * V_15 , T_2 V_37 )
{
T_2 V_28 [ 3 ] ;
if ( V_37 == V_38 )
V_37 = F_12 ( V_15 ) ;
V_28 [ 0 ] = V_39 ;
V_28 [ 1 ] = 0 ;
V_28 [ 2 ] = V_37 ;
F_8 ( V_15 , V_28 , sizeof( V_28 ) ) ;
}
static enum V_40 F_14 ( struct V_41 * V_42 )
{
struct V_14 * V_15 ;
struct V_43 * V_44 = V_42 -> V_44 -> V_45 ;
int V_46 ;
unsigned long V_17 ;
bool V_47 = false ;
V_15 = F_15 ( F_5 ( V_44 , struct V_1 , V_44 ) ) ;
for ( V_46 = 0 ; V_46 < 4 ; ++ V_46 ) {
if ( V_15 -> V_27 [ V_46 ] == V_42 ) {
F_6 ( & V_15 -> V_30 . V_48 , V_17 ) ;
V_47 = V_15 -> V_30 . V_17 & F_16 ( V_46 + 1 ) ;
F_7 ( & V_15 -> V_30 . V_48 , V_17 ) ;
break;
}
}
return V_47 ? V_49 : V_50 ;
}
static void F_17 ( struct V_41 * V_42 ,
enum V_40 V_47 )
{
struct V_14 * V_15 ;
struct V_43 * V_44 = V_42 -> V_44 -> V_45 ;
int V_46 ;
unsigned long V_17 ;
T_2 V_30 , V_51 ;
V_15 = F_15 ( F_5 ( V_44 , struct V_1 , V_44 ) ) ;
for ( V_46 = 0 ; V_46 < 4 ; ++ V_46 ) {
if ( V_15 -> V_27 [ V_46 ] == V_42 ) {
V_51 = F_16 ( V_46 + 1 ) ;
F_6 ( & V_15 -> V_30 . V_48 , V_17 ) ;
V_30 = V_15 -> V_30 . V_17 ;
if ( V_47 == V_50 )
F_11 ( V_15 , V_30 & ~ V_51 ) ;
else
F_11 ( V_15 , V_30 | V_51 ) ;
F_7 ( & V_15 -> V_30 . V_48 , V_17 ) ;
break;
}
}
}
static int F_18 ( struct V_52 * V_44 , unsigned int type ,
unsigned int V_53 , int V_47 )
{
return 0 ;
}
static int F_19 ( struct V_52 * V_44 )
{
struct V_14 * V_15 = F_20 ( V_44 ) ;
return F_21 ( V_15 -> V_2 ) ;
}
static void F_22 ( struct V_52 * V_44 )
{
struct V_14 * V_15 = F_20 ( V_44 ) ;
F_23 ( V_15 -> V_2 ) ;
}
static void F_24 ( struct V_14 * V_15 , const T_2 * V_54 )
{
F_25 ( V_15 -> V_55 , V_56 [ V_57 ] ,
! ! ( V_54 [ 0 ] & 0x01 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_58 ] ,
! ! ( V_54 [ 0 ] & 0x02 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_59 ] ,
! ! ( V_54 [ 0 ] & 0x04 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_60 ] ,
! ! ( V_54 [ 0 ] & 0x08 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_61 ] ,
! ! ( V_54 [ 0 ] & 0x10 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_62 ] ,
! ! ( V_54 [ 1 ] & 0x01 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_63 ] ,
! ! ( V_54 [ 1 ] & 0x02 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_64 ] ,
! ! ( V_54 [ 1 ] & 0x04 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_65 ] ,
! ! ( V_54 [ 1 ] & 0x08 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_66 ] ,
! ! ( V_54 [ 1 ] & 0x10 ) ) ;
F_25 ( V_15 -> V_55 , V_56 [ V_67 ] ,
! ! ( V_54 [ 1 ] & 0x80 ) ) ;
F_26 ( V_15 -> V_55 ) ;
}
static void F_27 ( struct V_14 * V_15 , const T_2 * V_54 )
{
F_24 ( V_15 , V_54 ) ;
F_13 ( V_15 , V_38 ) ;
}
static void F_28 ( struct V_14 * V_15 , const T_2 * V_54 )
{
T_2 V_68 = V_54 [ 3 ] ;
T_2 V_28 = V_54 [ 2 ] ;
F_24 ( V_15 , V_54 ) ;
if ( V_68 )
F_9 ( V_15 -> V_2 , L_3 , V_68 ,
V_28 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_69 * V_70 ,
T_4 * V_71 , int V_23 )
{
struct V_14 * V_15 = F_15 ( V_2 ) ;
struct V_72 * V_73 ;
int V_46 ;
unsigned long V_17 ;
if ( V_23 < 1 )
return - V_74 ;
F_6 ( & V_15 -> V_30 . V_48 , V_17 ) ;
for ( V_46 = 0 ; V_75 [ V_46 ] . V_76 ; ++ V_46 ) {
V_73 = & V_75 [ V_46 ] ;
if ( V_73 -> V_76 == V_71 [ 0 ] && V_73 -> V_23 < V_23 )
V_73 -> V_77 ( V_15 , & V_71 [ 1 ] ) ;
}
F_7 ( & V_15 -> V_30 . V_48 , V_17 ) ;
return 0 ;
}
static void F_30 ( struct V_14 * V_15 )
{
int V_46 ;
struct V_41 * V_78 ;
for ( V_46 = 0 ; V_46 < 4 ; ++ V_46 ) {
if ( V_15 -> V_27 [ V_46 ] ) {
V_78 = V_15 -> V_27 [ V_46 ] ;
V_15 -> V_27 [ V_46 ] = NULL ;
F_31 ( V_78 ) ;
F_3 ( V_78 ) ;
}
}
}
static int F_32 ( struct V_14 * V_15 )
{
int V_46 , V_6 ;
struct V_43 * V_44 = & V_15 -> V_2 -> V_44 ;
T_3 V_79 = strlen ( F_33 ( V_44 ) ) + 9 ;
struct V_41 * V_78 ;
char * V_80 ;
for ( V_46 = 0 ; V_46 < 4 ; ++ V_46 ) {
V_78 = F_34 ( sizeof( struct V_41 ) + V_79 , V_9 ) ;
if ( ! V_78 ) {
V_6 = - V_10 ;
goto V_68;
}
V_80 = ( void * ) & V_78 [ 1 ] ;
snprintf ( V_80 , V_79 , L_4 , F_33 ( V_44 ) , V_46 ) ;
V_78 -> V_80 = V_80 ;
V_78 -> V_81 = 0 ;
V_78 -> V_82 = 1 ;
V_78 -> V_83 = F_14 ;
V_78 -> V_84 = F_17 ;
V_6 = F_35 ( V_44 , V_78 ) ;
if ( V_6 ) {
F_3 ( V_78 ) ;
goto V_68;
}
V_15 -> V_27 [ V_46 ] = V_78 ;
}
return 0 ;
V_68:
F_30 ( V_15 ) ;
return V_6 ;
}
static struct V_14 * F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_46 ;
V_15 = F_34 ( sizeof( * V_15 ) , V_9 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_55 = F_37 () ;
if ( ! V_15 -> V_55 ) {
F_3 ( V_15 ) ;
return NULL ;
}
V_15 -> V_2 = V_2 ;
F_38 ( V_2 , V_15 ) ;
F_39 ( V_15 -> V_55 , V_15 ) ;
V_15 -> V_55 -> V_85 = F_18 ;
V_15 -> V_55 -> V_86 = F_19 ;
V_15 -> V_55 -> V_87 = F_22 ;
V_15 -> V_55 -> V_44 . V_45 = & V_15 -> V_2 -> V_44 ;
V_15 -> V_55 -> V_76 . V_88 = V_15 -> V_2 -> V_89 ;
V_15 -> V_55 -> V_76 . V_90 = V_15 -> V_2 -> V_90 ;
V_15 -> V_55 -> V_76 . V_91 = V_15 -> V_2 -> V_91 ;
V_15 -> V_55 -> V_76 . V_92 = V_15 -> V_2 -> V_92 ;
V_15 -> V_55 -> V_80 = V_93 ;
F_40 ( V_94 , V_15 -> V_55 -> V_95 ) ;
for ( V_46 = 0 ; V_46 < V_96 ; ++ V_46 )
F_40 ( V_56 [ V_46 ] , V_15 -> V_55 -> V_97 ) ;
F_41 ( & V_15 -> V_18 ) ;
F_42 ( & V_15 -> V_16 , F_4 ) ;
F_41 ( & V_15 -> V_30 . V_48 ) ;
return V_15 ;
}
static void F_43 ( struct V_14 * V_15 )
{
F_30 ( V_15 ) ;
F_44 ( V_15 -> V_55 ) ;
F_45 ( & V_15 -> V_16 ) ;
F_46 ( V_15 -> V_2 ) ;
F_3 ( V_15 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_98 * V_76 )
{
struct V_14 * V_15 ;
int V_6 ;
V_15 = F_36 ( V_2 ) ;
if ( ! V_15 ) {
F_48 ( V_2 , L_5 ) ;
return - V_10 ;
}
V_6 = F_49 ( V_2 ) ;
if ( V_6 ) {
F_48 ( V_2 , L_6 ) ;
goto V_68;
}
V_6 = F_50 ( V_2 , V_99 ) ;
if ( V_6 ) {
F_48 ( V_2 , L_7 ) ;
goto V_68;
}
V_6 = F_51 ( V_15 -> V_55 ) ;
if ( V_6 ) {
F_48 ( V_2 , L_8 ) ;
goto V_100;
}
V_6 = F_32 ( V_15 ) ;
if ( V_6 )
goto V_101;
F_52 ( V_2 , L_9 ) ;
F_53 ( & V_15 -> V_30 . V_48 ) ;
F_11 ( V_15 , V_32 ) ;
F_54 ( & V_15 -> V_30 . V_48 ) ;
return 0 ;
V_101:
F_43 ( V_15 ) ;
return V_6 ;
V_100:
F_46 ( V_2 ) ;
V_68:
F_55 ( V_15 -> V_55 ) ;
F_3 ( V_15 ) ;
return V_6 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_15 ( V_2 ) ;
F_52 ( V_2 , L_10 ) ;
F_43 ( V_15 ) ;
}
static int T_5 F_57 ( void )
{
int V_6 ;
V_6 = F_58 ( & V_102 ) ;
if ( V_6 )
F_59 ( L_11 ) ;
return V_6 ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_102 ) ;
}
