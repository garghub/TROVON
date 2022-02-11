static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ) { }
static void F_2 ( struct V_3 * V_4 , unsigned int V_5 , T_1 V_6 )
{
F_3 ( L_1 , V_6 , V_5 ) ;
F_4 ( V_4 -> V_7 , V_5 , V_6 ) ;
}
static void F_5 ( unsigned int V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_3 * V_4 = F_7 ( V_8 ) ;
T_1 V_13 , V_14 ;
int V_15 ;
int V_16 = 0 ;
V_13 = F_8 ( V_4 -> V_7 , V_17 ) ;
F_3 ( L_2 , V_13 ) ;
V_13 &= V_18 ;
while ( V_4 -> V_19 != V_13 && V_16 < 100 ) {
V_15 = V_4 -> V_19 / sizeof( V_20 ) ;
V_14 = F_9 ( V_4 -> V_21 [ V_15 ] ) ;
V_14 &= 0xFFFF ;
F_3 ( L_3 ,
V_13 , V_4 -> V_19 , V_14 ) ;
if ( V_14 < V_22 && F_10 ( V_14 ) == V_4 ) {
F_11 ( V_14 ) ;
V_4 -> V_21 [ V_15 ] = F_12 ( 0xffffffff ) ;
} else {
F_13 ( 1 ) ;
V_16 ++ ;
F_3 ( L_4 , V_14 ) ;
continue;
}
if ( V_16 ) {
F_3 ( L_5 ,
V_14 , V_16 ) ;
V_16 = 0 ;
}
V_4 -> V_19 += V_23 ;
V_4 -> V_19 &= V_18 ;
}
if ( V_16 ) {
F_14 ( V_24 L_6 ) ;
V_4 -> V_19 += V_23 ;
V_4 -> V_19 &= V_18 ;
}
V_12 -> V_25 ( & V_10 -> V_26 ) ;
}
static struct V_3 * F_15 ( struct V_27 * V_28 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 , * V_30 ;
const T_2 * V_31 ;
struct V_3 * V_4 = NULL ;
V_2 = F_16 ( F_17 ( V_28 ) ) ;
if ( ! V_2 ) {
F_18 ( & V_28 -> V_28 , L_7 ) ;
return NULL ;
}
for (; V_2 ; V_2 = F_19 ( V_2 ) ) {
V_31 = F_20 ( V_2 , L_8 , NULL ) ;
if ( V_31 )
break;
}
if ( ! V_31 ) {
F_18 ( & V_28 -> V_28 ,
L_9 ) ;
goto V_32;
}
V_30 = V_2 ;
V_2 = F_21 ( * V_31 ) ;
F_22 ( V_30 ) ;
if ( ! V_2 ) {
F_18 ( & V_28 -> V_28 ,
L_10 ) ;
goto V_32;
}
V_29 = F_23 ( V_2 ) ;
if ( ! V_29 ) {
F_18 ( & V_28 -> V_28 , L_11 ,
V_2 -> V_33 ) ;
goto V_32;
}
V_4 = V_29 -> V_34 ;
V_32:
F_22 ( V_2 ) ;
return V_4 ;
}
static int F_24 ( struct V_27 * V_28 , struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
int V_39 ;
const T_1 * V_40 ;
V_2 = F_16 ( F_17 ( V_28 ) ) ;
if ( ! V_2 ) {
F_18 ( & V_28 -> V_28 , L_7 ) ;
return - V_41 ;
}
V_38 = F_25 ( & V_28 -> V_42 , struct V_37 , V_43 ) ;
for (; V_2 ; V_2 = F_19 ( V_2 ) ) {
if ( V_38 -> V_44 . V_45 ) {
V_40 = F_20 ( V_2 , L_12 , & V_39 ) ;
if ( V_40 )
break;
}
V_40 = F_20 ( V_2 , L_13 , & V_39 ) ;
if ( V_40 )
break;
}
if ( ! V_40 ) {
F_18 ( & V_28 -> V_28 ,
L_14 ) ;
return - V_46 ;
}
switch ( V_39 ) {
case 8 :
V_36 -> V_47 = V_40 [ 0 ] ;
V_36 -> V_48 = V_40 [ 1 ] ;
break;
case 4 :
V_36 -> V_47 = 0 ;
V_36 -> V_48 = V_40 [ 0 ] ;
break;
default:
F_18 ( & V_28 -> V_28 ,
L_15 ) ;
F_22 ( V_2 ) ;
return - V_49 ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_27 * V_28 , int V_50 , int type )
{
unsigned int V_51 , V_52 ;
struct V_37 * V_38 ;
struct V_35 V_36 ;
struct V_3 * V_4 ;
V_4 = F_15 ( V_28 ) ;
if ( ! V_4 )
return - V_41 ;
V_52 = F_24 ( V_28 , & V_36 ) ;
if ( V_52 )
return V_52 ;
F_27 (entry, &dev->msi_list, list) {
V_51 = F_28 ( V_4 -> V_29 ) ;
if ( V_51 == V_53 ) {
F_29 ( & V_28 -> V_28 ,
L_16 ) ;
return - 1 ;
}
F_18 ( & V_28 -> V_28 , L_17 , V_51 ) ;
F_30 ( V_51 , V_38 ) ;
V_36 . V_54 = V_51 ;
F_31 ( V_51 , & V_36 ) ;
}
return 0 ;
}
static void F_32 ( struct V_27 * V_28 )
{
struct V_37 * V_38 ;
F_18 ( & V_28 -> V_28 , L_18 ) ;
F_27 (entry, &dev->msi_list, list) {
if ( V_38 -> V_8 == V_53 )
continue;
F_30 ( V_38 -> V_8 , NULL ) ;
F_33 ( V_38 -> V_8 ) ;
}
}
static int F_34 ( struct V_29 * V_55 , unsigned int V_51 ,
T_3 V_56 )
{
F_35 ( V_51 , V_55 -> V_34 ) ;
F_36 ( V_51 , & V_57 , V_58 ) ;
return 0 ;
}
static void F_37 ( struct V_59 * V_60 )
{
struct V_3 * V_4 = F_38 ( & V_60 -> V_28 ) ;
T_1 V_30 ;
F_3 ( L_19 ,
V_4 -> V_29 -> V_61 -> V_33 ) ;
V_30 = F_8 ( V_4 -> V_7 , V_62 ) ;
V_30 &= ~ V_63 & ~ V_64 ;
F_2 ( V_4 , V_62 , V_30 ) ;
}
static int F_39 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_28 . V_61 ;
struct V_3 * V_4 ;
unsigned int V_51 ;
int V_65 , V_66 ;
F_3 ( L_20 , V_2 -> V_33 ) ;
V_4 = F_40 ( sizeof( struct V_3 ) , V_67 ) ;
if ( ! V_4 ) {
F_14 ( V_68 L_21 ,
V_2 -> V_33 ) ;
goto V_69;
}
V_65 = F_41 ( V_2 , 0 ) ;
V_66 = F_42 ( V_2 , 0 ) ;
if ( V_65 == 0 || V_66 == 0 ) {
F_14 ( V_68
L_22 ,
V_2 -> V_33 ) ;
goto V_70;
}
V_4 -> V_7 = F_43 ( V_2 , V_65 , V_66 ) ;
if ( ! F_44 ( V_4 -> V_7 ) ) {
F_14 ( V_68 L_23 ,
V_2 -> V_33 ) ;
goto V_70;
}
V_4 -> V_21 = F_45 ( & V_60 -> V_28 , V_71 ,
& V_4 -> V_72 , V_67 ) ;
if ( ! V_4 -> V_21 ) {
F_14 ( V_68 L_24 ,
V_2 -> V_33 ) ;
goto V_70;
}
V_51 = F_46 ( V_2 , 0 ) ;
if ( V_51 == V_53 ) {
F_14 ( V_68 L_25 ,
V_2 -> V_33 ) ;
goto V_73;
}
memset ( V_4 -> V_21 , 0xff , V_71 ) ;
V_4 -> V_29 = F_47 ( V_2 , 65536 , & V_74 , V_4 ) ;
if ( ! V_4 -> V_29 ) {
F_14 ( V_68 L_26 ,
V_2 -> V_33 ) ;
goto V_73;
}
F_48 ( V_51 , V_4 ) ;
F_49 ( V_51 , F_5 ) ;
F_3 ( L_27 , V_51 ) ;
F_2 ( V_4 , V_75 , V_4 -> V_72 >> 32 ) ;
F_2 ( V_4 , V_76 ,
V_4 -> V_72 & 0xFFFFFFFF ) ;
F_2 ( V_4 , V_62 ,
V_64 | V_63 |
V_77 ) ;
V_4 -> V_19 = F_8 ( V_4 -> V_7 , V_17 )
& V_18 ;
F_50 ( & V_60 -> V_28 , V_4 ) ;
V_78 . V_79 = F_26 ;
V_78 . V_80 = F_32 ;
F_1 ( V_2 , V_4 ) ;
F_14 ( V_81 L_28 , V_2 -> V_33 ) ;
return 0 ;
V_73:
F_51 ( & V_60 -> V_28 , V_71 , V_4 -> V_21 ,
V_4 -> V_72 ) ;
V_70:
F_52 ( V_4 ) ;
V_69:
return - 1 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_82 ) ;
}
static int F_55 ( void * V_54 , T_5 V_6 )
{
struct V_3 * V_4 = V_54 ;
F_56 ( V_4 -> V_83 , V_6 ) ;
return 0 ;
}
static int F_57 ( void * V_54 , T_5 * V_6 )
{
* V_6 = 0 ;
return 0 ;
}
void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_84 [ 8 ] ;
T_5 V_85 ;
V_85 = F_58 ( V_2 , F_20 ( V_2 , L_29 , NULL ) ) ;
if ( V_85 == V_86 ) {
F_3 ( L_30 ) ;
return;
}
V_4 -> V_83 = F_59 ( V_85 , 0x4 ) ;
if ( ! V_4 -> V_83 ) {
F_3 ( L_31 ) ;
return;
}
snprintf ( V_84 , sizeof( V_84 ) , L_32 , F_60 ( V_2 ) ) ;
if ( ! F_61 ( V_84 , 0600 , V_87 ,
V_4 , & V_88 ) ) {
F_3 ( L_33 ) ;
return;
}
}
