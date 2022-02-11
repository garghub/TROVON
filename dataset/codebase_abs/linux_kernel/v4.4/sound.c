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
while ( ! F_19 () ) {
struct V_13 * V_13 = NULL ;
bool V_34 = false ;
int V_35 ;
F_20 (
V_7 -> V_36 ,
F_19 () ||
( V_7 -> V_37 &&
( V_13 = F_21 ( V_7 -> V_9 , V_7 -> V_12 ,
& V_38 ) ) ) ) ;
if ( ! V_13 )
continue;
if ( V_7 -> V_37 )
V_34 = F_16 ( V_7 , V_13 ) ;
else
memset ( V_13 -> V_30 , 0 , V_13 -> V_26 ) ;
V_35 = F_22 ( V_13 ) ;
if ( V_35 )
V_7 -> V_37 = false ;
if ( V_34 )
F_23 ( V_7 -> V_16 ) ;
}
return 0 ;
}
static int F_24 ( struct V_39 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_40 ;
struct V_14 * V_15 = V_16 -> V_15 ;
struct V_41 * V_18 = V_7 -> V_18 ;
V_7 -> V_16 = V_16 ;
if ( V_18 -> V_23 == V_42 ) {
V_7 -> V_43 = F_25 ( F_18 , V_7 ,
L_1 ) ;
if ( F_26 ( V_7 -> V_43 ) ) {
F_27 ( L_2 ) ;
return F_28 ( V_7 -> V_43 ) ;
}
}
if ( F_29 ( V_7 -> V_9 , V_7 -> V_12 , & V_38 ) ) {
F_27 ( L_3 ) ;
if ( V_18 -> V_23 == V_42 )
F_30 ( V_7 -> V_43 ) ;
return - V_44 ;
}
V_15 -> V_45 = V_7 -> V_46 ;
return 0 ;
}
static int F_31 ( struct V_39 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_40 ;
if ( V_7 -> V_18 -> V_23 == V_42 )
F_30 ( V_7 -> V_43 ) ;
F_32 ( V_7 -> V_9 , V_7 -> V_12 , & V_38 ) ;
return 0 ;
}
static int F_33 ( struct V_39 * V_16 ,
struct V_47 * V_48 )
{
struct V_7 * V_7 = V_16 -> V_40 ;
if ( ( F_34 ( V_48 ) > V_7 -> V_46 . V_49 ) ||
( F_34 ( V_48 ) < V_7 -> V_46 . V_50 ) ) {
F_27 ( L_4 ) ;
return - V_51 ;
}
return F_35 ( V_16 ,
F_36 ( V_48 ) ) ;
}
static int F_37 ( struct V_39 * V_16 )
{
return F_38 ( V_16 ) ;
}
static int F_39 ( struct V_39 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_40 ;
struct V_14 * V_15 = V_16 -> V_15 ;
struct V_41 * V_18 = V_7 -> V_18 ;
int V_52 = F_40 ( V_15 -> V_53 ) ;
V_7 -> V_28 = NULL ;
if ( V_18 -> V_23 == V_42 ) {
if ( F_41 ( V_15 -> V_53 ) || V_52 == 8 )
V_7 -> V_28 = F_6 ;
else if ( V_52 == 16 )
V_7 -> V_28 = F_7 ;
else if ( V_52 == 24 )
V_7 -> V_28 = F_8 ;
else if ( V_52 == 32 )
V_7 -> V_28 = F_9 ;
} else {
if ( F_41 ( V_15 -> V_53 ) || V_52 == 8 )
V_7 -> V_28 = F_10 ;
else if ( V_52 == 16 )
V_7 -> V_28 = F_11 ;
else if ( V_52 == 24 )
V_7 -> V_28 = F_12 ;
else if ( V_52 == 32 )
V_7 -> V_28 = F_13 ;
}
if ( ! V_7 -> V_28 ) {
F_27 ( L_5 ) ;
return - V_51 ;
}
V_7 -> V_31 = 0 ;
V_7 -> V_27 = 0 ;
return 0 ;
}
static int F_42 ( struct V_39 * V_16 , int V_54 )
{
struct V_7 * V_7 = V_16 -> V_40 ;
switch ( V_54 ) {
case V_55 :
V_7 -> V_37 = true ;
F_43 ( & V_7 -> V_36 ) ;
return 0 ;
case V_56 :
V_7 -> V_37 = false ;
return 0 ;
default:
F_44 ( L_6 ) ;
return - V_51 ;
}
return 0 ;
}
static T_4 F_45 ( struct V_39 * V_16 )
{
struct V_7 * V_7 = V_16 -> V_40 ;
return V_7 -> V_27 ;
}
static int F_46 ( char * V_57 , char * * V_58 , char * * V_59 )
{
* V_58 = F_47 ( & V_57 , L_7 ) ;
if ( ! * V_58 )
return - V_60 ;
* V_59 = F_47 ( & V_57 , L_8 ) ;
if ( ! * V_59 )
return - V_60 ;
return 0 ;
}
static int F_48 ( struct V_61 * V_62 ,
char * V_59 ,
struct V_41 * V_18 )
{
V_62 -> V_63 = V_64 ;
V_62 -> V_65 = V_66 ;
V_62 -> V_67 = 48000 ;
V_62 -> V_68 = 48000 ;
V_62 -> V_69 = V_18 -> V_70 * V_18 -> V_20 ;
V_62 -> V_71 = V_18 -> V_20 ;
V_62 -> V_72 = V_18 -> V_20 ;
V_62 -> V_73 = 1 ;
V_62 -> V_74 = V_18 -> V_70 ;
if ( ! strcmp ( V_59 , L_9 ) ) {
if ( V_18 -> V_19 != 1 )
goto error;
F_44 ( L_10 ) ;
V_62 -> V_50 = 1 ;
V_62 -> V_49 = 1 ;
V_62 -> V_75 = V_76 ;
} else if ( ! strcmp ( V_59 , L_11 ) ) {
if ( V_18 -> V_19 != 4 )
goto error;
F_44 ( L_12 ) ;
V_62 -> V_50 = 2 ;
V_62 -> V_49 = 2 ;
V_62 -> V_75 = V_77 |
V_78 ;
} else if ( ! strcmp ( V_59 , L_13 ) ) {
if ( V_18 -> V_19 != 6 )
goto error;
F_44 ( L_14 ) ;
V_62 -> V_50 = 2 ;
V_62 -> V_49 = 2 ;
V_62 -> V_75 = V_79 |
V_80 ;
} else if ( ! strcmp ( V_59 , L_15 ) ) {
if ( V_18 -> V_19 != 8 )
goto error;
F_44 ( L_16 ) ;
V_62 -> V_50 = 2 ;
V_62 -> V_49 = 2 ;
V_62 -> V_75 = V_81 |
V_82 ;
} else if ( ! strcmp ( V_59 , L_17 ) ) {
if ( V_18 -> V_19 != 12 )
goto error;
F_44 ( L_18 ) ;
V_62 -> V_50 = 6 ;
V_62 -> V_49 = 6 ;
V_62 -> V_75 = V_77 |
V_78 ;
} else {
F_27 ( L_19 , V_59 ) ;
return - V_60 ;
}
return 0 ;
error:
F_27 ( L_20 ) ;
return - V_51 ;
}
static int F_49 ( struct V_8 * V_9 , int V_10 ,
struct V_41 * V_18 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_7 * V_7 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
int V_90 = 0 ;
int V_91 = 0 ;
int V_35 ;
int V_23 ;
char * V_58 ;
char * V_59 ;
if ( ! V_9 )
return - V_51 ;
if ( V_18 -> V_92 != V_93 ) {
F_27 ( L_21 ) ;
return - V_51 ;
}
if ( F_14 ( V_9 , V_10 ) ) {
F_27 ( L_22 ,
V_9 -> V_94 , V_10 ) ;
return - V_51 ;
}
if ( V_18 -> V_23 == V_42 ) {
V_90 = 1 ;
V_23 = V_95 ;
} else {
V_91 = 1 ;
V_23 = V_96 ;
}
V_35 = F_46 ( V_85 , & V_58 , & V_59 ) ;
if ( V_35 < 0 ) {
F_44 ( L_23 ) ;
return V_35 ;
}
V_35 = F_50 ( NULL , - 1 , V_58 , V_97 ,
sizeof( * V_7 ) , & V_87 ) ;
if ( V_35 < 0 )
return V_35 ;
V_7 = V_87 -> V_40 ;
V_7 -> V_87 = V_87 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_12 = V_10 ;
F_51 ( & V_7 -> V_36 ) ;
if ( F_48 ( & V_7 -> V_46 , V_59 , V_18 ) )
goto V_98;
snprintf ( V_87 -> V_99 , sizeof( V_87 -> V_99 ) , L_24 , V_100 ) ;
snprintf ( V_87 -> V_101 , sizeof( V_87 -> V_101 ) , L_25 ,
V_87 -> V_102 ) ;
snprintf ( V_87 -> V_103 , sizeof( V_87 -> V_103 ) , L_26 ,
V_87 -> V_101 , V_9 -> V_94 , V_10 ) ;
V_35 = F_52 ( V_87 , V_58 , 0 , V_90 ,
V_91 , & V_89 ) ;
if ( V_35 < 0 )
goto V_98;
V_89 -> V_40 = V_7 ;
F_53 ( V_89 , V_23 , & V_104 ) ;
V_35 = F_54 ( V_87 ) ;
if ( V_35 < 0 )
goto V_98;
F_55 ( & V_7 -> V_105 , & V_106 ) ;
return 0 ;
V_98:
F_56 ( V_87 ) ;
return V_35 ;
}
static int F_57 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_7 * V_7 ;
V_7 = F_14 ( V_9 , V_10 ) ;
if ( ! V_7 ) {
F_27 ( L_27 ,
V_10 ) ;
return - V_51 ;
}
F_58 ( & V_7 -> V_105 ) ;
F_56 ( V_7 -> V_87 ) ;
return 0 ;
}
static int F_59 ( struct V_13 * V_13 )
{
struct V_7 * V_7 = F_14 ( V_13 -> V_107 , V_13 -> V_108 ) ;
bool V_34 = false ;
if ( ! V_7 ) {
F_27 ( L_28 ,
V_13 -> V_108 ) ;
return - V_51 ;
}
if ( V_7 -> V_37 )
V_34 = F_16 ( V_7 , V_13 ) ;
F_60 ( V_13 ) ;
if ( V_34 )
F_23 ( V_7 -> V_16 ) ;
return 0 ;
}
static int F_61 ( struct V_8 * V_9 , int V_10 )
{
struct V_7 * V_7 = F_14 ( V_9 , V_10 ) ;
if ( ! V_7 ) {
F_27 ( L_29 ,
V_10 ) ;
return - V_51 ;
}
F_43 ( & V_7 -> V_36 ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
F_44 ( L_30 ) ;
F_63 ( & V_106 ) ;
return F_64 ( & V_38 ) ;
}
static void T_6 F_65 ( void )
{
struct V_7 * V_7 , * V_11 ;
F_44 ( L_31 ) ;
F_15 (channel, tmp, &dev_list, list) {
F_58 ( & V_7 -> V_105 ) ;
F_56 ( V_7 -> V_87 ) ;
}
F_66 ( & V_38 ) ;
}
