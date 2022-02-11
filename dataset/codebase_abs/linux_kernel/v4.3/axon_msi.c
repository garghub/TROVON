static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ) { }
static void F_2 ( struct V_3 * V_4 , unsigned int V_5 , T_1 V_6 )
{
F_3 ( L_1 , V_6 , V_5 ) ;
F_4 ( V_4 -> V_7 , V_5 , V_6 ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_3 * V_4 = F_7 ( V_9 ) ;
T_1 V_12 , V_13 ;
int V_14 ;
int V_15 = 0 ;
V_12 = F_8 ( V_4 -> V_7 , V_16 ) ;
F_3 ( L_2 , V_12 ) ;
V_12 &= V_17 ;
while ( V_4 -> V_18 != V_12 && V_15 < 100 ) {
V_14 = V_4 -> V_18 / sizeof( V_19 ) ;
V_13 = F_9 ( V_4 -> V_20 [ V_14 ] ) ;
V_13 &= 0xFFFF ;
F_3 ( L_3 ,
V_12 , V_4 -> V_18 , V_13 ) ;
if ( V_13 < V_21 && F_10 ( V_13 ) == V_4 ) {
F_11 ( V_13 ) ;
V_4 -> V_20 [ V_14 ] = F_12 ( 0xffffffff ) ;
} else {
F_13 ( 1 ) ;
V_15 ++ ;
F_3 ( L_4 , V_13 ) ;
continue;
}
if ( V_15 ) {
F_3 ( L_5 ,
V_13 , V_15 ) ;
V_15 = 0 ;
}
V_4 -> V_18 += V_22 ;
V_4 -> V_18 &= V_17 ;
}
if ( V_15 ) {
F_14 ( V_23 L_6 ) ;
V_4 -> V_18 += V_22 ;
V_4 -> V_18 &= V_17 ;
}
V_11 -> V_24 ( & V_9 -> V_25 ) ;
}
static struct V_3 * F_15 ( struct V_26 * V_27 )
{
struct V_28 * V_28 ;
struct V_1 * V_2 , * V_29 ;
const T_2 * V_30 ;
struct V_3 * V_4 = NULL ;
V_2 = F_16 ( F_17 ( V_27 ) ) ;
if ( ! V_2 ) {
F_18 ( & V_27 -> V_27 , L_7 ) ;
return NULL ;
}
for (; V_2 ; V_2 = F_19 ( V_2 ) ) {
V_30 = F_20 ( V_2 , L_8 , NULL ) ;
if ( V_30 )
break;
}
if ( ! V_30 ) {
F_18 ( & V_27 -> V_27 ,
L_9 ) ;
goto V_31;
}
V_29 = V_2 ;
V_2 = F_21 ( * V_30 ) ;
F_22 ( V_29 ) ;
if ( ! V_2 ) {
F_18 ( & V_27 -> V_27 ,
L_10 ) ;
goto V_31;
}
V_28 = F_23 ( V_2 ) ;
if ( ! V_28 ) {
F_18 ( & V_27 -> V_27 , L_11 ,
V_2 -> V_32 ) ;
goto V_31;
}
V_4 = V_28 -> V_33 ;
V_31:
F_22 ( V_2 ) ;
return V_4 ;
}
static int F_24 ( struct V_26 * V_27 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_38 ;
const T_1 * V_39 ;
V_2 = F_16 ( F_17 ( V_27 ) ) ;
if ( ! V_2 ) {
F_18 ( & V_27 -> V_27 , L_7 ) ;
return - V_40 ;
}
V_37 = F_25 ( V_27 ) ;
for (; V_2 ; V_2 = F_19 ( V_2 ) ) {
if ( V_37 -> V_41 . V_42 ) {
V_39 = F_20 ( V_2 , L_12 , & V_38 ) ;
if ( V_39 )
break;
}
V_39 = F_20 ( V_2 , L_13 , & V_38 ) ;
if ( V_39 )
break;
}
if ( ! V_39 ) {
F_18 ( & V_27 -> V_27 ,
L_14 ) ;
return - V_43 ;
}
switch ( V_38 ) {
case 8 :
V_35 -> V_44 = V_39 [ 0 ] ;
V_35 -> V_45 = V_39 [ 1 ] ;
break;
case 4 :
V_35 -> V_44 = 0 ;
V_35 -> V_45 = V_39 [ 0 ] ;
break;
default:
F_18 ( & V_27 -> V_27 ,
L_15 ) ;
F_22 ( V_2 ) ;
return - V_46 ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_26 * V_27 , int V_47 , int type )
{
unsigned int V_48 , V_49 ;
struct V_36 * V_37 ;
struct V_34 V_35 ;
struct V_3 * V_4 ;
V_4 = F_15 ( V_27 ) ;
if ( ! V_4 )
return - V_40 ;
V_49 = F_24 ( V_27 , & V_35 ) ;
if ( V_49 )
return V_49 ;
F_27 (entry, dev) {
V_48 = F_28 ( V_4 -> V_28 ) ;
if ( V_48 == V_50 ) {
F_29 ( & V_27 -> V_27 ,
L_16 ) ;
return - 1 ;
}
F_18 ( & V_27 -> V_27 , L_17 , V_48 ) ;
F_30 ( V_48 , V_37 ) ;
V_35 . V_51 = V_48 ;
F_31 ( V_48 , & V_35 ) ;
}
return 0 ;
}
static void F_32 ( struct V_26 * V_27 )
{
struct V_36 * V_37 ;
F_18 ( & V_27 -> V_27 , L_18 ) ;
F_27 (entry, dev) {
if ( V_37 -> V_52 == V_50 )
continue;
F_30 ( V_37 -> V_52 , NULL ) ;
F_33 ( V_37 -> V_52 ) ;
}
}
static int F_34 ( struct V_28 * V_53 , unsigned int V_48 ,
T_3 V_54 )
{
F_35 ( V_48 , V_53 -> V_33 ) ;
F_36 ( V_48 , & V_55 , V_56 ) ;
return 0 ;
}
static void F_37 ( struct V_57 * V_58 )
{
struct V_3 * V_4 = F_38 ( & V_58 -> V_27 ) ;
T_1 V_29 ;
F_3 ( L_19 ,
V_4 -> V_28 -> V_59 -> V_32 ) ;
V_29 = F_8 ( V_4 -> V_7 , V_60 ) ;
V_29 &= ~ V_61 & ~ V_62 ;
F_2 ( V_4 , V_60 , V_29 ) ;
}
static int F_39 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_27 . V_59 ;
struct V_3 * V_4 ;
unsigned int V_48 ;
int V_63 , V_64 ;
F_3 ( L_20 , V_2 -> V_32 ) ;
V_4 = F_40 ( sizeof( struct V_3 ) , V_65 ) ;
if ( ! V_4 ) {
F_14 ( V_66 L_21 ,
V_2 -> V_32 ) ;
goto V_67;
}
V_63 = F_41 ( V_2 , 0 ) ;
V_64 = F_42 ( V_2 , 0 ) ;
if ( V_63 == 0 || V_64 == 0 ) {
F_14 ( V_66
L_22 ,
V_2 -> V_32 ) ;
goto V_68;
}
V_4 -> V_7 = F_43 ( V_2 , V_63 , V_64 ) ;
if ( ! F_44 ( V_4 -> V_7 ) ) {
F_14 ( V_66 L_23 ,
V_2 -> V_32 ) ;
goto V_68;
}
V_4 -> V_20 = F_45 ( & V_58 -> V_27 , V_69 ,
& V_4 -> V_70 , V_65 ) ;
if ( ! V_4 -> V_20 ) {
F_14 ( V_66 L_24 ,
V_2 -> V_32 ) ;
goto V_68;
}
V_48 = F_46 ( V_2 , 0 ) ;
if ( V_48 == V_50 ) {
F_14 ( V_66 L_25 ,
V_2 -> V_32 ) ;
goto V_71;
}
memset ( V_4 -> V_20 , 0xff , V_69 ) ;
V_4 -> V_28 = F_47 ( V_2 , 65536 , & V_72 , V_4 ) ;
if ( ! V_4 -> V_28 ) {
F_14 ( V_66 L_26 ,
V_2 -> V_32 ) ;
goto V_71;
}
F_48 ( V_48 , V_4 ) ;
F_49 ( V_48 , F_5 ) ;
F_3 ( L_27 , V_48 ) ;
F_2 ( V_4 , V_73 , V_4 -> V_70 >> 32 ) ;
F_2 ( V_4 , V_74 ,
V_4 -> V_70 & 0xFFFFFFFF ) ;
F_2 ( V_4 , V_60 ,
V_62 | V_61 |
V_75 ) ;
V_4 -> V_18 = F_8 ( V_4 -> V_7 , V_16 )
& V_17 ;
F_50 ( & V_58 -> V_27 , V_4 ) ;
V_76 . V_77 = F_26 ;
V_76 . V_78 = F_32 ;
F_1 ( V_2 , V_4 ) ;
F_14 ( V_79 L_28 , V_2 -> V_32 ) ;
return 0 ;
V_71:
F_51 ( & V_58 -> V_27 , V_69 , V_4 -> V_20 ,
V_4 -> V_70 ) ;
V_68:
F_52 ( V_4 ) ;
V_67:
return - 1 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_80 ) ;
}
static int F_55 ( void * V_51 , T_5 V_6 )
{
struct V_3 * V_4 = V_51 ;
F_56 ( V_4 -> V_81 , V_6 ) ;
return 0 ;
}
static int F_57 ( void * V_51 , T_5 * V_6 )
{
* V_6 = 0 ;
return 0 ;
}
void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_82 [ 8 ] ;
T_5 V_83 ;
V_83 = F_58 ( V_2 , F_20 ( V_2 , L_29 , NULL ) ) ;
if ( V_83 == V_84 ) {
F_3 ( L_30 ) ;
return;
}
V_4 -> V_81 = F_59 ( V_83 , 0x4 ) ;
if ( ! V_4 -> V_81 ) {
F_3 ( L_31 ) ;
return;
}
snprintf ( V_82 , sizeof( V_82 ) , L_32 , F_60 ( V_2 ) ) ;
if ( ! F_61 ( V_82 , 0600 , V_85 ,
V_4 , & V_86 ) ) {
F_3 ( L_33 ) ;
return;
}
}
