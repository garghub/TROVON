T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_4 , T_1 * V_5 )
{
T_1 V_6 ;
T_3 V_7 [ 32 ] = {} ;
T_4 V_8 , V_9 ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
F_2 ( 30 ) ;
if ( V_4 == 0 ) {
V_9 = V_8 = 0 ;
} else {
V_8 = ( unsigned short ) ( V_4 & 0xffff ) ;
V_9 = ( unsigned short ) ( ( V_4 >> 16 ) & 0xffff ) ;
}
V_6 = F_3 ( V_2 -> V_13 ,
F_4 ( V_2 -> V_13 , 0 ) ,
V_14 | V_3 ,
V_15 | V_16 | V_17 ,
V_8 ,
V_9 ,
& V_7 ,
sizeof( * V_5 ) ,
V_18 ) ;
if ( ! V_6 ) {
return - V_19 ;
} else {
memcpy ( ( char * ) V_5 , & ( V_7 [ 0 ] ) , sizeof( * V_5 ) ) ;
}
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_4 ,
void * V_20 , T_1 * V_5 , T_1 V_21 )
{
T_1 V_6 ;
T_3 V_7 [ 128 ] = {} ;
T_4 V_8 , V_9 ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
F_2 ( 30 ) ;
if ( V_4 == 0 ) {
V_9 = V_8 = 0 ;
} else {
V_8 = ( unsigned short ) ( V_4 & 0xffff ) ;
V_9 = ( unsigned short ) ( ( V_4 >> 16 ) & 0xffff ) ;
}
V_6 = F_3 ( V_2 -> V_13 ,
F_4 ( V_2 -> V_13 , 0 ) ,
V_22 | V_3 ,
V_15 | V_16 | V_17 ,
V_8 ,
V_9 ,
& V_7 ,
( V_21 + sizeof( * V_5 ) ) ,
V_18 ) ;
if ( V_6 < 0 ) {
return - V_19 ;
} else {
memcpy ( ( char * ) V_5 , & V_7 [ 0 ] , sizeof( * V_5 ) ) ;
memcpy ( ( char * ) V_20 , & V_7 [ sizeof( * V_5 ) ] , V_21 ) ;
}
return 0 ;
}
static int F_6 ( struct V_23 * V_24 ,
unsigned long V_25 , void * V_26 )
{
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 , * V_29 ;
switch ( V_25 ) {
case V_30 :
F_7 (node, next, &pd_device_list) {
struct V_31 * V_13 ;
struct V_32 * V_33 ;
int V_34 = 0 ;
V_2 = F_8 ( V_28 , struct V_1 , V_35 ) ;
V_13 = V_2 -> V_13 ;
V_33 = V_2 -> V_36 ;
V_34 = F_9 ( V_13 , V_33 ) ;
if ( V_34 >= 0 ) {
F_10 ( V_13 ) ;
F_11 ( V_13 ) ;
}
}
break;
default:
break;
}
log ( L_1 , V_25 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , unsigned char V_37 )
{
T_1 V_6 , V_5 ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
V_6 = F_1 ( V_2 , V_38 , V_37 , & V_5 ) ;
if ( V_6 || V_5 )
return - V_19 ;
return 0 ;
}
void F_13 ( struct V_39 * V_39 )
{
struct V_1 * V_2 = F_8 ( V_39 , struct V_1 , V_39 ) ;
if ( ! V_2 )
return;
F_14 ( & V_2 -> V_35 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_13 ) {
F_16 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
if ( V_2 -> V_36 ) {
F_17 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
F_18 ( V_2 ) ;
log () ;
}
static int F_19 ( struct V_31 * V_13 )
{
int V_6 = 0 , V_40 ;
const struct V_41 * V_42 = NULL ;
void * V_43 = NULL ;
T_5 V_44 = 0 , V_45 ;
T_5 V_46 ;
V_6 = F_20 ( & V_42 , V_47 , & V_13 -> V_48 ) ;
if ( V_6 ) {
log ( L_2 , V_6 ) ;
return V_6 ;
}
V_44 = V_42 -> V_49 ;
V_43 = F_21 ( V_42 -> V_7 , V_44 , V_50 ) ;
if ( ! V_43 ) {
V_6 = - V_51 ;
goto V_52;
}
V_46 = F_22 ( V_13 -> V_53 [ 0x1 ] -> V_54 . V_55 ) ;
log ( L_3 , ( int ) V_46 ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 += V_46 ) {
V_40 = 0 ;
V_6 = F_23 ( V_13 ,
F_24 ( V_13 , 0x01 ) ,
V_43 + V_45 ,
F_25 ( V_46 , V_44 - V_45 ) ,
& V_40 ,
V_56 * 10 ) ;
if ( V_6 )
break;
}
F_18 ( V_43 ) ;
V_52:
F_26 ( V_42 ) ;
return V_6 ;
}
static inline struct V_1 * F_27 ( struct V_32 * V_57 )
{
return F_28 ( V_57 ) ;
}
static inline void F_29 ( struct V_1 * V_2 , struct V_31 * V_13 )
{
V_2 -> V_58 = V_13 -> V_58 ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
return V_2 -> V_59 . V_60 + V_2 -> V_61 . V_60 + V_2 -> V_62 . V_60
+ F_31 ( & V_2 -> V_63 . V_60 ) +
! F_32 ( & V_2 -> V_64 . V_65 . V_66 ) ;
}
static inline struct V_1 * F_33 ( struct V_1 * V_2 )
{
int V_67 ;
V_67 = F_30 ( V_2 ) ;
log ( L_4 , V_67 , F_34 ( V_2 ) ) ;
while ( V_67 -- )
F_35 ( V_2 -> V_36 ) ;
F_16 ( V_2 -> V_13 ) ;
F_17 ( V_2 -> V_36 ) ;
log ( L_5 , V_2 -> V_68 . V_25 ) ;
return V_2 ;
}
static struct V_1 * F_36 ( struct V_31 * V_13 )
{
struct V_1 * V_2 ;
F_37 (pd, &pd_device_list, device_list) {
if ( V_2 -> V_58 == V_13 -> V_58 && F_38 ( V_2 ) )
return F_33 ( V_2 ) ;
}
return NULL ;
}
static inline int F_39 ( struct V_1 * V_2 )
{
return F_34 ( V_2 ) > 0 ;
}
static int F_40 ( struct V_32 * V_57 , T_6 V_68 )
{
struct V_1 * V_2 = F_27 ( V_57 ) ;
if ( ! V_2 )
return 0 ;
if ( ! F_39 ( V_2 ) ) {
if ( F_34 ( V_2 ) <= 0 && ! F_38 ( V_2 ) ) {
V_2 -> V_68 . V_25 = V_69 ;
V_2 -> V_70 = NULL ;
F_41 ( V_71 L_6 ) ;
}
return 0 ;
}
V_2 -> V_68 = V_68 ;
F_42 ( V_2 ) ;
return V_2 -> V_72 ? V_2 -> V_72 ( V_2 ) : 0 ;
}
static int F_43 ( struct V_32 * V_57 )
{
struct V_1 * V_2 = F_27 ( V_57 ) ;
if ( ! V_2 )
return 0 ;
F_41 ( V_71 L_7 ) ;
if ( ! F_39 ( V_2 ) ) {
if ( V_69 == V_2 -> V_68 . V_25 )
V_2 -> V_68 = V_73 ;
return 0 ;
}
if ( F_38 ( V_2 ) ) {
F_42 ( V_2 ) ;
return 0 ;
}
F_42 ( V_2 ) ;
return V_2 -> V_70 ? V_2 -> V_70 ( V_2 ) : 0 ;
}
static void F_44 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_8 ( V_75 , struct V_1 , V_76 ) ;
int V_67 ;
V_2 -> V_68 . V_25 = 0 ;
V_2 -> V_10 &= ~ V_11 ;
V_67 = F_30 ( V_2 ) ;
while ( V_67 -- )
F_45 ( V_2 -> V_36 ) ;
F_42 ( V_2 ) ;
if ( V_2 -> V_70 )
V_2 -> V_70 ( V_2 ) ;
}
static inline struct V_1 * F_36 ( struct V_31 * V_13 )
{
return NULL ;
}
static inline void F_29 ( struct V_1 * V_2 , struct V_31 * V_13 )
{
}
static int F_46 ( struct V_31 * V_13 )
{
void * V_20 ;
int V_6 ;
struct V_77 * V_78 ;
V_20 = F_47 ( sizeof( * V_78 ) + sizeof( V_79 ) , V_50 ) ;
if ( ! V_20 )
return - V_51 ;
V_6 = F_3 ( V_13 ,
F_4 ( V_13 , 0 ) ,
V_22 | V_80 ,
V_15 | V_16 | V_17 ,
0 ,
0 ,
V_20 ,
sizeof( * V_78 ) + sizeof( V_79 ) ,
V_18 ) ;
F_18 ( V_20 ) ;
if ( V_6 < 0 )
return F_19 ( V_13 ) ;
return 0 ;
}
static int F_48 ( struct V_32 * V_36 ,
const struct V_81 * V_82 )
{
struct V_31 * V_13 = F_49 ( V_36 ) ;
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
int V_83 = 0 ;
V_6 = F_46 ( V_13 ) ;
if ( V_6 )
return V_6 ;
V_2 = F_36 ( V_13 ) ;
if ( ! V_2 ) {
V_2 = F_47 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
F_50 ( & V_2 -> V_39 ) ;
F_29 ( V_2 , V_13 ) ;
V_83 = 1 ;
}
V_2 -> V_13 = F_51 ( V_13 ) ;
V_2 -> V_36 = F_52 ( V_36 ) ;
F_53 ( V_36 , V_2 ) ;
if ( V_83 ) {
F_42 ( V_2 ) ;
F_54 ( & V_2 -> V_84 ) ;
V_6 = F_55 ( & V_36 -> V_48 , & V_2 -> V_85 ) ;
if ( V_6 )
goto V_86;
V_6 = F_56 ( V_2 ) ;
if ( V_6 )
goto V_87;
V_6 = F_57 ( V_2 ) ;
if ( V_6 )
goto V_88;
V_6 = F_58 ( V_2 ) ;
if ( V_6 )
goto V_89;
V_6 = F_59 ( V_2 ) ;
if ( V_6 )
goto V_90;
F_60 ( & V_2 -> V_35 ) ;
F_61 ( & V_2 -> V_35 , & V_91 ) ;
}
F_62 ( & V_13 -> V_48 , 1 ) ;
#ifdef F_63
F_64 ( & V_2 -> V_13 -> V_48 ,
1000 * V_92 ) ;
F_65 ( V_2 -> V_13 ) ;
if ( F_38 ( V_2 ) ) {
F_66 ( & V_2 -> V_76 , F_44 ) ;
F_67 ( & V_2 -> V_76 ) ;
}
#endif
return 0 ;
V_90:
F_68 ( V_2 ) ;
V_89:
F_69 ( V_2 ) ;
V_88:
F_70 ( V_2 ) ;
V_87:
F_71 ( & V_2 -> V_85 ) ;
V_86:
F_17 ( V_2 -> V_36 ) ;
F_16 ( V_2 -> V_13 ) ;
F_18 ( V_2 ) ;
return V_6 ;
}
static void F_72 ( struct V_32 * V_36 )
{
struct V_1 * V_2 = F_27 ( V_36 ) ;
if ( ! V_2 )
return;
F_42 ( V_2 ) ;
if ( F_38 ( V_2 ) )
return;
F_73 ( & V_2 -> V_84 ) ;
V_2 -> V_10 |= V_11 ;
F_74 ( & V_2 -> V_84 ) ;
F_75 ( V_2 ) ;
F_76 ( & V_2 -> V_63 ) ;
F_71 ( & V_2 -> V_85 ) ;
F_77 ( V_2 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_53 ( V_36 , NULL ) ;
F_78 ( & V_2 -> V_39 , F_13 ) ;
}
static int T_7 F_79 ( void )
{
int V_6 ;
V_6 = F_80 ( & V_93 ) ;
if ( V_6 )
return V_6 ;
F_81 ( & V_94 ) ;
return V_6 ;
}
static void T_8 F_82 ( void )
{
log () ;
F_83 ( & V_94 ) ;
F_84 ( & V_93 ) ;
}
