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
F_10 ( L_3 , V_29 -> V_40 ) ;
F_8 ( V_32 -> V_29 != V_29 ) ;
if ( V_32 -> V_41 )
return - V_42 ;
F_8 ( ! V_32 -> V_43 . V_44 || ! V_32 -> V_45 . V_44 ) ;
if ( F_11 ( V_32 -> V_46 , V_32 -> V_45 . V_47 ) ) {
F_2 ( L_4 ) ;
return - V_48 ;
}
if ( F_11 ( V_32 -> V_46 , V_32 -> V_43 . V_47 ) ) {
F_2 ( L_4 ) ;
F_12 ( V_32 -> V_46 , V_32 -> V_45 . V_47 ) ;
return - V_48 ;
}
V_32 -> V_41 = true ;
if ( V_32 -> V_35 ) {
V_32 -> V_49 = 1 ;
F_13 ( V_29 ) ;
} else {
V_32 -> V_46 -> V_50 ( V_32 -> V_46 , V_32 -> V_43 . V_47 ) ;
}
return 0 ;
}
static int F_14 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
F_10 ( L_5 , V_29 -> V_40 ) ;
F_8 ( V_32 -> V_29 != V_29 ) ;
F_15 ( V_29 ) ;
if ( V_32 -> V_41 ) {
F_12 ( V_32 -> V_46 , V_32 -> V_45 . V_47 ) ;
F_12 ( V_32 -> V_46 , V_32 -> V_43 . V_47 ) ;
V_32 -> V_41 = false ;
}
return 0 ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_3 ;
int V_51 ;
F_8 ( V_32 -> V_29 != V_29 ) ;
V_3 = F_17 ( V_32 -> V_46 , V_32 -> V_43 . V_47 ) ;
if ( ! V_3 ) {
F_15 ( V_29 ) ;
V_29 -> V_52 . V_53 ++ ;
return V_54 ;
}
if ( V_32 -> V_35 )
V_51 = F_1 ( V_2 , V_3 ) ;
else
V_51 = F_5 ( V_2 , V_3 ) ;
if ( V_51 ) {
F_18 ( V_3 ) ;
V_29 -> V_52 . V_55 ++ ;
F_19 ( V_2 ) ;
return V_56 ;
}
F_20 ( V_3 ) ;
V_29 -> V_52 . V_57 ++ ;
V_29 -> V_52 . V_58 += V_2 -> V_11 ;
F_19 ( V_2 ) ;
return V_56 ;
}
static void F_21 ( struct V_28 * V_29 )
{
F_10 ( L_6 , V_29 -> V_40 ) ;
F_22 ( V_29 ) ;
V_29 -> V_59 = & V_60 ;
}
static void F_23 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_29 )
return;
F_10 ( L_7 , V_32 -> V_29 ) ;
F_24 ( V_32 -> V_29 ) ;
F_25 ( V_32 -> V_29 ) ;
V_32 -> V_29 = 0 ;
}
static struct V_31 * F_26 (
struct V_61 * V_46 )
{
struct V_31 * V_32 , * V_62 ;
F_27 ( & V_63 ) ;
F_28 (nd, tmp, &net_devices, list) {
if ( V_32 -> V_46 == V_46 ) {
F_29 ( & V_63 ) ;
return V_32 ;
}
}
F_29 ( & V_63 ) ;
return NULL ;
}
static int F_30 ( struct V_61 * V_46 , int V_64 ,
struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_40 )
{
struct V_31 * V_32 ;
struct V_69 * V_70 ;
if ( ! V_46 )
return - V_16 ;
if ( V_66 -> V_71 != V_72 )
return - V_16 ;
V_32 = F_26 ( V_46 ) ;
if ( ! V_32 ) {
V_32 = F_31 ( sizeof( * V_32 ) , V_73 ) ;
if ( ! V_32 )
return - V_74 ;
V_32 -> V_46 = V_46 ;
F_27 ( & V_63 ) ;
F_32 ( & V_32 -> V_75 , & V_76 ) ;
F_29 ( & V_63 ) ;
}
V_70 = V_66 -> V_77 == V_78 ? & V_32 -> V_43 : & V_32 -> V_45 ;
if ( V_70 -> V_44 ) {
F_2 ( L_8 ) ;
return - V_16 ;
}
if ( V_32 -> V_43 . V_44 || V_32 -> V_45 . V_44 ) {
struct V_28 * V_29 =
F_33 ( 0 , L_9 , V_79 , F_21 ) ;
if ( ! V_29 ) {
F_2 ( L_10 ) ;
return - V_74 ;
}
V_32 -> V_29 = V_29 ;
V_29 -> V_33 = V_32 ;
if ( F_34 ( V_29 ) ) {
F_2 ( L_11 ) ;
F_25 ( V_29 ) ;
return - V_16 ;
}
}
V_70 -> V_47 = V_64 ;
V_70 -> V_44 = true ;
return 0 ;
}
static int F_35 ( struct V_61 * V_46 ,
int V_64 )
{
struct V_31 * V_32 ;
struct V_69 * V_70 ;
V_32 = F_26 ( V_46 ) ;
if ( ! V_32 )
return - V_16 ;
if ( V_32 -> V_45 . V_44 && V_64 == V_32 -> V_45 . V_47 )
V_70 = & V_32 -> V_45 ;
else if ( V_32 -> V_43 . V_44 && V_64 == V_32 -> V_43 . V_47 )
V_70 = & V_32 -> V_43 ;
else
return - V_16 ;
V_70 -> V_44 = false ;
F_23 ( V_32 ) ;
if ( ! V_32 -> V_45 . V_44 && ! V_32 -> V_43 . V_44 ) {
F_27 ( & V_63 ) ;
F_36 ( & V_32 -> V_75 ) ;
F_29 ( & V_63 ) ;
F_37 ( V_32 ) ;
}
return 0 ;
}
static int F_38 ( struct V_61 * V_46 ,
int V_64 )
{
struct V_31 * V_32 ;
V_32 = F_26 ( V_46 ) ;
if ( ! V_32 || ! V_32 -> V_41 || V_32 -> V_43 . V_47 != V_64 )
return 0 ;
if ( ! V_32 -> V_29 )
return 0 ;
F_13 ( V_32 -> V_29 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_3 )
{
const T_3 V_80 = 0 ;
struct V_31 * V_32 ;
char * V_81 = V_3 -> V_5 ;
T_4 V_11 = V_3 -> V_82 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_32 = F_26 ( V_3 -> V_83 ) ;
if ( ! V_32 || ! V_32 -> V_41 || V_32 -> V_45 . V_47 != V_3 -> V_84 )
return - V_85 ;
V_29 = V_32 -> V_29 ;
if ( ! V_29 ) {
F_40 ( L_12 ) ;
return - V_85 ;
}
if ( V_32 -> V_35 ) {
if ( ! F_41 ( V_81 , V_11 ) )
return - V_85 ;
V_2 = F_42 ( V_11 - V_14 + 2 * V_86 + 2 ) ;
} else {
if ( ! F_43 ( V_81 , V_11 ) )
return - V_85 ;
V_2 = F_42 ( V_11 - V_24 ) ;
}
if ( ! V_2 ) {
V_29 -> V_52 . V_87 ++ ;
F_40 ( L_13 ) ;
goto V_88;
}
V_2 -> V_29 = V_29 ;
if ( V_32 -> V_35 ) {
memcpy ( F_44 ( V_2 , V_86 ) , V_29 -> V_36 , V_86 ) ;
memcpy ( F_44 ( V_2 , 4 ) , & V_80 , 4 ) ;
memcpy ( F_44 ( V_2 , 2 ) , V_81 + 5 , 2 ) ;
memcpy ( F_44 ( V_2 , 2 ) , V_81 + 10 , 2 ) ;
V_81 += V_14 ;
V_11 -= V_14 ;
} else {
V_81 += V_24 ;
V_11 -= V_24 ;
}
memcpy ( F_44 ( V_2 , V_11 ) , V_81 , V_11 ) ;
V_2 -> V_89 = F_45 ( V_2 , V_29 ) ;
V_29 -> V_52 . V_90 ++ ;
V_29 -> V_52 . V_91 += V_2 -> V_11 ;
F_46 ( V_2 ) ;
V_88:
F_18 ( V_3 ) ;
return 0 ;
}
static int T_5 F_47 ( void )
{
F_10 ( L_14 ) ;
F_48 ( & V_63 ) ;
V_92 . V_40 = L_15 ;
V_92 . V_93 = F_30 ;
V_92 . V_94 = F_35 ;
V_92 . V_95 = F_38 ;
V_92 . V_96 = F_39 ;
return F_49 ( & V_92 ) ;
}
static void T_6 F_50 ( void )
{
struct V_31 * V_32 , * V_62 ;
F_27 ( & V_63 ) ;
F_28 (nd, tmp, &net_devices, list) {
F_36 ( & V_32 -> V_75 ) ;
F_29 ( & V_63 ) ;
F_23 ( V_32 ) ;
F_37 ( V_32 ) ;
F_27 ( & V_63 ) ;
}
F_29 ( & V_63 ) ;
F_51 ( & V_92 ) ;
F_10 ( L_16 ) ;
}
void F_52 ( struct V_61 * V_46 ,
unsigned char V_49 , unsigned char * V_97 )
{
struct V_31 * V_32 ;
struct V_28 * V_29 ;
F_10 ( L_17 , V_46 -> V_98 ) ;
V_32 = F_26 ( V_46 ) ;
if ( ! V_32 )
return;
V_29 = V_32 -> V_29 ;
if ( ! V_29 )
return;
if ( V_97 )
memcpy ( V_29 -> V_36 , V_97 , V_86 ) ;
if ( V_32 -> V_49 != V_49 ) {
V_32 -> V_49 = V_49 ;
if ( V_32 -> V_49 )
F_13 ( V_29 ) ;
else
F_15 ( V_29 ) ;
}
}
