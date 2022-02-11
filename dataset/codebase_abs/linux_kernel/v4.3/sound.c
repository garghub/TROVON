static void F_1 ( T_1 * V_1 , const T_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = 0 ;
while ( V_4 < ( V_3 / 2 ) ) {
V_1 [ V_4 ] = F_2 ( V_2 [ V_4 ] ) ;
V_4 ++ ;
}
}
static void F_3 ( T_2 * V_1 , const T_2 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = 0 ;
while ( V_4 < V_3 - 2 ) {
V_1 [ V_4 ] = V_2 [ V_4 + 2 ] ;
V_1 [ V_4 + 1 ] = V_2 [ V_4 + 1 ] ;
V_1 [ V_4 + 2 ] = V_2 [ V_4 ] ;
V_4 += 3 ;
}
}
static void F_4 ( T_3 * V_1 , const T_3 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = 0 ;
while ( V_4 < V_3 / 4 ) {
V_1 [ V_4 ] = F_5 ( V_2 [ V_4 ] ) ;
V_4 ++ ;
}
}
static void F_6 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
memcpy ( V_6 , V_5 , V_3 ) ;
}
static void F_7 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
F_1 ( V_6 , V_5 , V_3 ) ;
}
static void F_8 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
F_3 ( V_6 , V_5 , V_3 ) ;
}
static void F_9 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
F_4 ( V_6 , V_5 , V_3 ) ;
}
static void F_10 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
memcpy ( V_5 , V_6 , V_3 ) ;
}
static void F_11 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
F_1 ( V_5 , V_6 , V_3 ) ;
}
static void F_12 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
F_3 ( V_5 , V_6 , V_3 ) ;
}
static void F_13 ( void * V_5 , void * V_6 , unsigned int V_3 )
{
F_4 ( V_5 , V_6 , V_3 ) ;
}
static struct V_7 * F_14 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_7 * V_7 , * V_11 ;
F_15 (channel, tmp, &dev_list, list) {
if ( ( V_7 -> V_9 == V_9 ) && ( V_7 -> V_12 == V_10 ) )
return V_7 ;
}
return NULL ;
}
static bool F_16 ( struct V_7 * V_7 , struct V_13 * V_13 )
{
struct V_14 * const V_15 = V_7 -> V_16 -> V_15 ;
unsigned int const V_17 = V_7 -> V_18 -> V_19 ;
unsigned int const V_20 = V_15 -> V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
if ( V_7 -> V_18 -> V_23 & V_24 )
V_21 = V_13 -> V_25 / V_17 ;
else
V_21 = V_13 -> V_26 / V_17 ;
V_22 = F_17 ( V_20 - V_7 -> V_27 , V_21 ) ;
V_7 -> V_28 ( V_15 -> V_29 + V_7 -> V_27 * V_17 ,
V_13 -> V_30 ,
V_22 * V_17 ) ;
if ( V_21 > V_22 ) {
V_7 -> V_28 ( V_15 -> V_29 ,
V_13 -> V_30 + V_22 * V_17 ,
( V_21 - V_22 ) * V_17 ) ;
}
V_7 -> V_27 += V_21 ;
if ( V_7 -> V_27 >= V_20 )
V_7 -> V_27 -= V_20 ;
V_7 -> V_31 += V_21 ;
if ( V_7 -> V_31 >= V_15 -> V_32 ) {
V_7 -> V_31 -= V_15 -> V_32 ;
return true ;
}
return false ;
}
static int F_18 ( void * V_33 )
{
struct V_7 * const V_7 = V_33 ;
F_19 ( L_1 ) ;
while ( ! F_20 () ) {
struct V_13 * V_13 = NULL ;
bool V_34 = false ;
int V_35 ;
F_21 (
V_7 -> V_36 ,
F_20 () ||
( V_13 = F_22 ( V_7 -> V_9 , V_7 -> V_12 ) ) ) ;
if ( ! V_13 )
continue;
if ( V_7 -> V_37 )
V_34 = F_16 ( V_7 , V_13 ) ;
else
memset ( V_13 -> V_30 , 0 , V_13 -> V_26 ) ;
V_35 = F_23 ( V_13 ) ;
if ( V_35 )
V_7 -> V_37 = false ;
if ( V_34 )
F_24 ( V_7 -> V_16 ) ;
}
return 0 ;
}
static int F_25 ( struct V_38 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_39 ;
struct V_14 * V_15 = V_16 -> V_15 ;
struct V_40 * V_18 = V_7 -> V_18 ;
F_19 ( L_2 , V_16 -> V_41 ) ;
V_7 -> V_16 = V_16 ;
if ( V_18 -> V_23 == V_42 ) {
F_26 ( & V_7 -> V_36 ) ;
V_7 -> V_43 = F_27 ( & F_18 , V_7 ,
L_3 ) ;
if ( F_28 ( V_7 -> V_43 ) )
return F_29 ( V_7 -> V_43 ) ;
}
if ( F_30 ( V_7 -> V_9 , V_7 -> V_12 ) ) {
F_31 ( L_4 ) ;
if ( V_18 -> V_23 == V_42 )
F_32 ( V_7 -> V_43 ) ;
return - V_44 ;
}
V_15 -> V_45 = V_46 ;
V_15 -> V_45 . V_47 = V_18 -> V_48 * V_18 -> V_20 ;
V_15 -> V_45 . V_49 = V_18 -> V_20 ;
V_15 -> V_45 . V_50 = V_18 -> V_20 ;
V_15 -> V_45 . V_51 = 1 ;
V_15 -> V_45 . V_52 = V_18 -> V_48 ;
return 0 ;
}
static int F_33 ( struct V_38 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_39 ;
F_19 ( L_5 , V_16 -> V_41 ) ;
if ( V_7 -> V_18 -> V_23 == V_42 )
F_32 ( V_7 -> V_43 ) ;
F_34 ( V_7 -> V_9 , V_7 -> V_12 ) ;
return 0 ;
}
static int F_35 ( struct V_38 * V_16 ,
struct V_53 * V_54 )
{
F_19 ( L_6 ) ;
return F_36 ( V_16 ,
F_37 ( V_54 ) ) ;
}
static int F_38 ( struct V_38 * V_16 )
{
F_19 ( L_7 ) ;
return F_39 ( V_16 ) ;
}
static int F_40 ( struct V_38 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_39 ;
struct V_14 * V_15 = V_16 -> V_15 ;
struct V_40 * V_18 = V_7 -> V_18 ;
int V_55 = F_41 ( V_15 -> V_56 ) ;
V_7 -> V_28 = NULL ;
if ( V_18 -> V_23 == V_42 ) {
if ( F_42 ( V_15 -> V_56 ) || V_55 == 8 )
V_7 -> V_28 = F_6 ;
else if ( V_55 == 16 )
V_7 -> V_28 = F_7 ;
else if ( V_55 == 24 )
V_7 -> V_28 = F_8 ;
else if ( V_55 == 32 )
V_7 -> V_28 = F_9 ;
} else {
if ( F_42 ( V_15 -> V_56 ) || V_55 == 8 )
V_7 -> V_28 = F_10 ;
else if ( V_55 == 16 )
V_7 -> V_28 = F_11 ;
else if ( V_55 == 24 )
V_7 -> V_28 = F_12 ;
else if ( V_55 == 32 )
V_7 -> V_28 = F_13 ;
}
if ( ! V_7 -> V_28 ) {
F_31 ( L_8 ) ;
return - V_57 ;
}
V_7 -> V_31 = 0 ;
V_7 -> V_27 = 0 ;
return 0 ;
}
static int F_43 ( struct V_38 * V_16 , int V_58 )
{
struct V_7 * V_7 = V_16 -> V_39 ;
switch ( V_58 ) {
case V_59 :
V_7 -> V_37 = true ;
return 0 ;
case V_60 :
V_7 -> V_37 = false ;
return 0 ;
default:
F_19 ( L_9 ) ;
return - V_57 ;
}
return 0 ;
}
static T_4 F_44 ( struct V_38 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_39 ;
return V_7 -> V_27 ;
}
int F_45 ( char * V_61 , char * * V_62 , char * * V_63 )
{
* V_62 = F_46 ( & V_61 , L_10 ) ;
if ( ! * V_62 )
return - V_64 ;
* V_63 = F_46 ( & V_61 , L_11 ) ;
if ( ! * V_63 )
return - V_64 ;
return 0 ;
}
int F_47 ( char * V_63 , struct V_40 * V_18 )
{
if ( ! strcmp ( V_63 , L_12 ) ) {
if ( V_18 -> V_19 != 1 )
goto error;
F_19 ( L_13 ) ;
V_46 . V_65 = V_66 ;
} else if ( ! strcmp ( V_63 , L_14 ) ) {
if ( V_18 -> V_19 != 4 )
goto error;
F_19 ( L_15 ) ;
V_46 . V_65 = V_67 |
V_68 ;
} else if ( ! strcmp ( V_63 , L_16 ) ) {
if ( V_18 -> V_19 != 6 )
goto error;
F_19 ( L_17 ) ;
V_46 . V_65 = V_69 |
V_70 ;
} else if ( ! strcmp ( V_63 , L_18 ) ) {
if ( V_18 -> V_19 != 8 )
goto error;
F_19 ( L_19 ) ;
V_46 . V_65 = V_71 |
V_72 ;
} else {
F_31 ( L_20 , V_63 ) ;
return - V_64 ;
}
return 0 ;
error:
F_31 ( L_21 ) ;
return - V_57 ;
}
static int F_48 ( struct V_8 * V_9 , int V_10 ,
struct V_40 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_7 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_80 = 0 ;
int V_81 = 0 ;
int V_35 ;
int V_23 ;
char * V_62 ;
char * V_63 ;
F_19 ( L_22 ) ;
if ( ! V_9 )
return - V_57 ;
if ( V_18 -> V_82 != V_83 ) {
F_31 ( L_23 ) ;
return - V_57 ;
}
if ( F_14 ( V_9 , V_10 ) ) {
F_31 ( L_24 ,
V_9 -> V_84 , V_10 ) ;
return - V_57 ;
}
if ( V_18 -> V_23 == V_42 ) {
V_80 = 1 ;
V_23 = V_85 ;
} else {
V_81 = 1 ;
V_23 = V_86 ;
}
V_35 = F_45 ( V_75 , & V_62 , & V_63 ) ;
if ( V_35 < 0 ) {
F_19 ( L_25 ) ;
return V_35 ;
}
if ( F_47 ( V_63 , V_18 ) )
return V_35 ;
V_35 = F_49 ( NULL , - 1 , V_62 , V_87 ,
sizeof( * V_7 ) , & V_77 ) ;
if ( V_35 < 0 )
return V_35 ;
V_7 = V_77 -> V_39 ;
V_7 -> V_77 = V_77 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_12 = V_10 ;
snprintf ( V_77 -> V_88 , sizeof( V_77 -> V_88 ) , L_26 , V_89 ) ;
snprintf ( V_77 -> V_90 , sizeof( V_77 -> V_90 ) , L_27 ,
V_77 -> V_91 ) ;
snprintf ( V_77 -> V_92 , sizeof( V_77 -> V_92 ) , L_28 ,
V_77 -> V_90 , V_9 -> V_84 , V_10 ) ;
V_35 = F_50 ( V_77 , V_62 , 0 , V_80 ,
V_81 , & V_79 ) ;
if ( V_35 < 0 )
goto V_93;
V_79 -> V_39 = V_7 ;
F_51 ( V_79 , V_23 , & V_94 ) ;
V_35 = F_52 ( V_77 ) ;
if ( V_35 < 0 )
goto V_93;
F_53 ( & V_7 -> V_95 , & V_96 ) ;
return 0 ;
V_93:
F_54 ( V_77 ) ;
return V_35 ;
}
static int F_55 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_7 * V_7 ;
F_19 ( L_29 ) ;
V_7 = F_14 ( V_9 , V_10 ) ;
if ( ! V_7 ) {
F_31 ( L_30 ,
V_10 ) ;
return - V_57 ;
}
F_56 ( & V_7 -> V_95 ) ;
F_54 ( V_7 -> V_77 ) ;
return 0 ;
}
static int F_57 ( struct V_13 * V_13 )
{
struct V_7 * V_7 = F_14 ( V_13 -> V_97 , V_13 -> V_98 ) ;
bool V_34 = false ;
if ( ! V_7 ) {
F_31 ( L_31 ,
V_13 -> V_98 ) ;
return - V_57 ;
}
if ( V_7 -> V_37 )
V_34 = F_16 ( V_7 , V_13 ) ;
F_58 ( V_13 ) ;
if ( V_34 )
F_24 ( V_7 -> V_16 ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 , int V_10 )
{
struct V_7 * V_7 = F_14 ( V_9 , V_10 ) ;
if ( ! V_7 ) {
F_31 ( L_32 ,
V_10 ) ;
return - V_57 ;
}
F_60 ( & V_7 -> V_36 ) ;
return 0 ;
}
static int T_5 F_61 ( void )
{
F_19 ( L_33 ) ;
F_62 ( & V_96 ) ;
return F_63 ( & V_99 ) ;
}
static void T_6 F_64 ( void )
{
struct V_7 * V_7 , * V_11 ;
F_19 ( L_34 ) ;
F_15 (channel, tmp, &dev_list, list) {
F_56 ( & V_7 -> V_95 ) ;
F_54 ( V_7 -> V_77 ) ;
}
F_65 ( & V_99 ) ;
}
