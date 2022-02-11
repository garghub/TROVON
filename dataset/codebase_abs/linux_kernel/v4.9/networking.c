static int F_1 ( const struct V_1 * V_2 , struct V_3 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 ;
const T_1 V_6 [] = { 0x03 , 0xFF } ;
const T_1 * V_7 = V_2 -> V_8 + 4 ;
const T_1 * V_9 = V_2 -> V_8 + 12 ;
unsigned int V_10 = V_2 -> V_11 - V_12 ;
unsigned int V_13 = V_10 + V_14 ;
if ( V_3 -> V_15 < V_13 ) {
F_2 ( L_1 ,
V_3 -> V_15 , V_13 ) ;
return - V_16 ;
}
if ( V_2 -> V_11 < V_12 ) {
F_2 ( L_2 , V_2 -> V_11 ) ;
return - V_16 ;
}
if ( V_7 [ 0 ] == 0xFF && V_7 [ 1 ] == 0xFF )
V_7 = V_6 ;
* V_4 ++ = F_3 ( V_13 - 2 ) ;
* V_4 ++ = F_4 ( V_13 - 2 ) ;
* V_4 ++ = V_17 ;
* V_4 ++ = ( V_18 << V_19 ) | V_20 ;
* V_4 ++ = V_21 ;
* V_4 ++ = V_7 [ 0 ] ;
* V_4 ++ = V_7 [ 1 ] ;
* V_4 ++ = 0x00 ;
* V_4 ++ = F_3 ( V_10 + 6 ) ;
* V_4 ++ = F_4 ( V_10 + 6 ) ;
* V_4 ++ = V_9 [ 0 ] ;
* V_4 ++ = V_9 [ 1 ] ;
* V_4 ++ = 0 ;
* V_4 ++ = 0 ;
* V_4 ++ = V_22 << 4 | F_3 ( V_10 ) ;
* V_4 ++ = F_4 ( V_10 ) ;
memcpy ( V_4 , V_2 -> V_8 + V_12 , V_10 ) ;
V_3 -> V_15 = V_13 ;
return 0 ;
}
static int F_5 ( const struct V_1 * V_2 , struct V_3 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 ;
unsigned int V_23 = V_2 -> V_11 + V_24 ;
if ( V_3 -> V_15 < V_23 ) {
F_2 ( L_1 ,
V_3 -> V_15 , V_23 ) ;
return - V_16 ;
}
* V_4 ++ = F_3 ( V_23 - 2 ) ;
* V_4 ++ = F_4 ( V_23 - 2 ) ;
* V_4 ++ = V_17 ;
* V_4 ++ = ( V_25 << V_19 ) | V_20 ;
* V_4 ++ = ( V_26 << V_27 ) | V_21 ;
* V_4 ++ = 0 ;
* V_4 ++ = 0 ;
* V_4 ++ = 0 ;
memcpy ( V_4 , V_2 -> V_8 , V_2 -> V_11 ) ;
V_3 -> V_15 = V_23 ;
return 0 ;
}
static int F_6 ( struct V_28 * V_29 , void * V_30 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
int V_34 = F_7 ( V_29 , V_30 ) ;
if ( V_34 )
return V_34 ;
F_8 ( V_32 -> V_29 != V_29 ) ;
V_32 -> V_35 =
( V_29 -> V_36 [ 0 ] == 0 && V_29 -> V_36 [ 1 ] == 0 &&
V_29 -> V_36 [ 2 ] == 0 && V_29 -> V_36 [ 3 ] == 0 ) ;
V_29 -> V_37 = V_32 -> V_35 ? V_38 : V_39 ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
F_10 ( V_29 , L_3 ) ;
F_8 ( V_32 -> V_29 != V_29 ) ;
if ( V_32 -> V_40 )
return - V_41 ;
F_8 ( ! V_32 -> V_42 . V_43 || ! V_32 -> V_44 . V_43 ) ;
if ( F_11 ( V_32 -> V_45 , V_32 -> V_44 . V_46 , & V_47 ) ) {
F_12 ( V_29 , L_4 ) ;
return - V_48 ;
}
if ( F_11 ( V_32 -> V_45 , V_32 -> V_42 . V_46 , & V_47 ) ) {
F_12 ( V_29 , L_4 ) ;
F_13 ( V_32 -> V_45 , V_32 -> V_44 . V_46 , & V_47 ) ;
return - V_48 ;
}
V_32 -> V_40 = true ;
if ( V_32 -> V_35 ) {
V_32 -> V_49 = 1 ;
F_14 ( V_29 ) ;
} else {
V_32 -> V_45 -> V_50 ( V_32 -> V_45 , V_32 -> V_42 . V_46 ) ;
}
return 0 ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
F_10 ( V_29 , L_5 ) ;
F_8 ( V_32 -> V_29 != V_29 ) ;
F_16 ( V_29 ) ;
if ( V_32 -> V_40 ) {
F_13 ( V_32 -> V_45 , V_32 -> V_44 . V_46 , & V_47 ) ;
F_13 ( V_32 -> V_45 , V_32 -> V_42 . V_46 , & V_47 ) ;
V_32 -> V_40 = false ;
}
return 0 ;
}
static T_2 F_17 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_3 ;
int V_51 ;
F_8 ( V_32 -> V_29 != V_29 ) ;
V_3 = F_18 ( V_32 -> V_45 , V_32 -> V_42 . V_46 , & V_47 ) ;
if ( ! V_3 ) {
F_16 ( V_29 ) ;
V_29 -> V_52 . V_53 ++ ;
return V_54 ;
}
if ( V_32 -> V_35 )
V_51 = F_1 ( V_2 , V_3 ) ;
else
V_51 = F_5 ( V_2 , V_3 ) ;
if ( V_51 ) {
F_19 ( V_3 ) ;
V_29 -> V_52 . V_55 ++ ;
F_20 ( V_2 ) ;
return V_56 ;
}
F_21 ( V_3 ) ;
V_29 -> V_52 . V_57 ++ ;
V_29 -> V_52 . V_58 += V_2 -> V_11 ;
F_20 ( V_2 ) ;
return V_56 ;
}
static void F_22 ( struct V_28 * V_29 )
{
F_10 ( V_29 , L_6 ) ;
F_23 ( V_29 ) ;
V_29 -> V_59 = & V_60 ;
}
static void F_24 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_29 )
return;
F_25 ( L_7 , V_32 -> V_29 ) ;
F_26 ( V_32 -> V_29 ) ;
F_27 ( V_32 -> V_29 ) ;
V_32 -> V_29 = NULL ;
}
static struct V_31 * F_28 (
struct V_61 * V_45 )
{
struct V_31 * V_32 , * V_62 ;
unsigned long V_63 ;
F_29 ( & V_64 , V_63 ) ;
F_30 (nd, tmp, &net_devices, list) {
if ( V_32 -> V_45 == V_45 ) {
F_31 ( & V_64 , V_63 ) ;
return V_32 ;
}
}
F_31 ( & V_64 , V_63 ) ;
return NULL ;
}
static int F_32 ( struct V_61 * V_45 , int V_65 ,
struct V_66 * V_67 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_31 * V_32 ;
struct V_71 * V_72 ;
unsigned long V_63 ;
if ( ! V_45 )
return - V_16 ;
if ( V_67 -> V_73 != V_74 )
return - V_16 ;
V_32 = F_28 ( V_45 ) ;
if ( ! V_32 ) {
V_32 = F_33 ( sizeof( * V_32 ) , V_75 ) ;
if ( ! V_32 )
return - V_76 ;
V_32 -> V_45 = V_45 ;
F_29 ( & V_64 , V_63 ) ;
F_34 ( & V_32 -> V_77 , & V_78 ) ;
F_31 ( & V_64 , V_63 ) ;
}
V_72 = V_67 -> V_79 == V_80 ? & V_32 -> V_42 : & V_32 -> V_44 ;
if ( V_72 -> V_43 ) {
F_2 ( L_8 ) ;
return - V_16 ;
}
if ( V_32 -> V_42 . V_43 || V_32 -> V_44 . V_43 ) {
struct V_28 * V_29 =
F_35 ( 0 , L_9 , V_81 ,
F_22 ) ;
if ( ! V_29 ) {
F_2 ( L_10 ) ;
return - V_76 ;
}
V_32 -> V_29 = V_29 ;
V_72 -> V_46 = V_65 ;
V_72 -> V_43 = true ;
V_29 -> V_33 = V_32 ;
if ( F_36 ( V_29 ) ) {
F_2 ( L_11 ) ;
V_72 -> V_43 = false ;
F_27 ( V_29 ) ;
return - V_16 ;
}
}
V_72 -> V_46 = V_65 ;
V_72 -> V_43 = true ;
return 0 ;
}
static int F_37 ( struct V_61 * V_45 ,
int V_65 )
{
struct V_31 * V_32 ;
struct V_71 * V_72 ;
unsigned long V_63 ;
V_32 = F_28 ( V_45 ) ;
if ( ! V_32 )
return - V_16 ;
if ( V_32 -> V_44 . V_43 && V_65 == V_32 -> V_44 . V_46 )
V_72 = & V_32 -> V_44 ;
else if ( V_32 -> V_42 . V_43 && V_65 == V_32 -> V_42 . V_46 )
V_72 = & V_32 -> V_42 ;
else
return - V_16 ;
V_72 -> V_43 = false ;
F_24 ( V_32 ) ;
if ( ! V_32 -> V_44 . V_43 && ! V_32 -> V_42 . V_43 ) {
F_29 ( & V_64 , V_63 ) ;
F_38 ( & V_32 -> V_77 ) ;
F_31 ( & V_64 , V_63 ) ;
F_39 ( V_32 ) ;
}
return 0 ;
}
static int F_40 ( struct V_61 * V_45 ,
int V_65 )
{
struct V_31 * V_32 ;
V_32 = F_28 ( V_45 ) ;
if ( ! V_32 || ! V_32 -> V_40 || V_32 -> V_42 . V_46 != V_65 )
return 0 ;
if ( ! V_32 -> V_29 )
return 0 ;
F_14 ( V_32 -> V_29 ) ;
return 0 ;
}
static int F_41 ( struct V_3 * V_3 )
{
const T_3 V_82 = 0 ;
struct V_31 * V_32 ;
char * V_83 = V_3 -> V_5 ;
T_3 V_11 = V_3 -> V_84 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
unsigned int V_85 ;
V_32 = F_28 ( V_3 -> V_86 ) ;
if ( ! V_32 || ! V_32 -> V_40 || V_32 -> V_44 . V_46 != V_3 -> V_87 )
return - V_88 ;
V_29 = V_32 -> V_29 ;
if ( ! V_29 ) {
F_42 ( L_12 ) ;
return - V_88 ;
}
if ( V_32 -> V_35 ) {
if ( ! F_43 ( V_83 , V_11 ) )
return - V_88 ;
V_2 = F_44 ( V_11 - V_14 + 2 * V_89 + 2 ) ;
} else {
if ( ! F_45 ( V_83 , V_11 ) )
return - V_88 ;
V_2 = F_44 ( V_11 - V_24 ) ;
}
if ( ! V_2 ) {
V_29 -> V_52 . V_90 ++ ;
F_42 ( L_13 ) ;
goto V_91;
}
V_2 -> V_29 = V_29 ;
if ( V_32 -> V_35 ) {
F_46 ( F_47 ( V_2 , V_89 ) , V_29 -> V_36 ) ;
memcpy ( F_47 ( V_2 , 4 ) , & V_82 , 4 ) ;
memcpy ( F_47 ( V_2 , 2 ) , V_83 + 5 , 2 ) ;
memcpy ( F_47 ( V_2 , 2 ) , V_83 + 10 , 2 ) ;
V_83 += V_14 ;
V_11 -= V_14 ;
} else {
V_83 += V_24 ;
V_11 -= V_24 ;
}
memcpy ( F_47 ( V_2 , V_11 ) , V_83 , V_11 ) ;
V_2 -> V_92 = F_48 ( V_2 , V_29 ) ;
V_85 = V_2 -> V_11 ;
if ( F_49 ( V_2 ) == V_93 ) {
V_29 -> V_52 . V_94 ++ ;
V_29 -> V_52 . V_95 += V_85 ;
} else {
V_29 -> V_52 . V_90 ++ ;
}
V_91:
F_19 ( V_3 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
F_25 ( L_14 ) ;
F_51 ( & V_64 ) ;
return F_52 ( & V_47 ) ;
}
static void T_5 F_53 ( void )
{
struct V_31 * V_32 , * V_62 ;
unsigned long V_63 ;
F_29 ( & V_64 , V_63 ) ;
F_30 (nd, tmp, &net_devices, list) {
F_38 ( & V_32 -> V_77 ) ;
F_31 ( & V_64 , V_63 ) ;
F_24 ( V_32 ) ;
F_39 ( V_32 ) ;
F_29 ( & V_64 , V_63 ) ;
}
F_31 ( & V_64 , V_63 ) ;
F_54 ( & V_47 ) ;
F_25 ( L_15 ) ;
}
void F_55 ( struct V_61 * V_45 ,
unsigned char V_49 , unsigned char * V_96 )
{
struct V_31 * V_32 ;
struct V_28 * V_29 ;
F_25 ( L_16 , V_45 -> V_97 ) ;
V_32 = F_28 ( V_45 ) ;
if ( ! V_32 )
return;
V_29 = V_32 -> V_29 ;
if ( ! V_29 )
return;
if ( V_96 )
F_46 ( V_29 -> V_36 , V_96 ) ;
if ( V_32 -> V_49 != V_49 ) {
V_32 -> V_49 = V_49 ;
if ( V_32 -> V_49 )
F_14 ( V_29 ) ;
else
F_16 ( V_29 ) ;
}
}
