static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 ;
while ( ( V_5 = F_3 ( & V_3 -> V_6 ) ) )
F_4 ( & V_3 -> V_7 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 ;
unsigned long V_8 ;
while ( ( V_5 = F_3 ( & V_3 -> V_9 ) ) )
F_4 ( & V_3 -> V_10 , V_5 ) ;
F_6 ( & V_3 -> V_9 . V_11 , V_8 ) ;
if ( V_3 -> V_12 ) {
F_4 ( & V_3 -> V_10 , V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
}
F_7 ( & V_3 -> V_9 . V_11 , V_8 ) ;
}
static void F_8 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_3 ) ;
struct V_4 * V_5 ;
if ( V_13 >= V_14 )
F_10 ( L_1 , __FILE__ , __LINE__ ) ;
F_11 ( & V_2 -> V_15 ) ;
F_11 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 == V_3 )
V_2 -> V_17 = NULL ;
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_7 ) ;
if ( V_5 ) {
F_12 ( V_5 ) ;
} else
break;
}
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_10 ) ;
if ( V_5 ) {
F_12 ( V_5 ) ;
} else
break;
}
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_6 ) ;
if ( V_5 ) {
F_12 ( V_5 ) ;
} else
break;
}
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_9 ) ;
if ( V_5 ) {
F_12 ( V_5 ) ;
} else
break;
}
F_12 ( V_3 -> V_12 ) ;
F_12 ( V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_13 >= V_14 )
F_10 ( L_2 , __FILE__ , __LINE__ ) ;
if ( V_3 != NULL ) {
if ( V_3 -> V_18 != V_19 ) {
F_10 ( V_20 L_3 ) ;
return;
}
#if F_14 ( V_21 )
F_15 ( V_21 , & V_2 -> V_8 ) ;
#endif
V_2 -> V_17 = NULL ;
if ( V_2 == V_3 -> V_22 )
V_3 -> V_22 = NULL ;
if ( V_2 != V_3 -> V_2 )
return;
if ( V_3 -> V_22 ) {
V_3 -> V_2 = V_3 -> V_22 ;
} else {
F_8 ( V_3 ) ;
}
}
if ( V_13 >= V_14 )
F_10 ( L_4 , __FILE__ , __LINE__ ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_13 >= V_14 )
F_10 ( L_5 ,
__FILE__ , __LINE__ ,
V_2 -> V_23 ) ;
if ( V_3 ) {
F_10 ( V_24 L_6 ) ;
return - V_25 ;
}
V_3 = F_17 () ;
if ( ! V_3 ) {
F_10 ( V_24 L_7 ) ;
return - V_26 ;
}
V_2 -> V_17 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_27 = 65536 ;
#if F_14 ( V_21 )
F_18 ( V_21 , & V_2 -> V_8 ) ;
#endif
F_19 ( V_2 ) ;
if ( V_13 >= V_14 )
F_10 ( L_8 , __FILE__ , __LINE__ ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_3 , struct V_1 * V_2 )
{
register int V_28 ;
unsigned long V_8 ;
struct V_4 * V_12 ;
if ( V_13 >= V_14 )
F_10 ( L_9 , __FILE__ , __LINE__ ) ;
V_29:
F_6 ( & V_3 -> V_9 . V_11 , V_8 ) ;
if ( V_3 -> V_30 ) {
V_3 -> V_31 = 1 ;
F_7 ( & V_3 -> V_9 . V_11 , V_8 ) ;
return;
}
V_3 -> V_30 = 1 ;
V_3 -> V_31 = 0 ;
F_7 ( & V_3 -> V_9 . V_11 , V_8 ) ;
V_12 = V_3 -> V_12 ;
if ( ! V_12 )
V_12 = F_3 ( & V_3 -> V_9 ) ;
while ( V_12 ) {
if ( V_13 >= V_14 )
F_10 ( L_10 ,
__FILE__ , __LINE__ , V_12 , V_12 -> V_32 ) ;
F_18 ( V_33 , & V_2 -> V_8 ) ;
V_28 = V_2 -> V_34 -> V_35 ( V_2 , V_12 -> V_5 , V_12 -> V_32 ) ;
if ( V_28 == - V_36 ) {
V_3 -> V_12 = V_12 ;
break;
}
if ( V_28 < 0 )
V_28 = V_12 -> V_32 ;
if ( V_28 == V_12 -> V_32 ) {
if ( V_13 >= V_14 )
F_10 ( L_11 ,
__FILE__ , __LINE__ , V_12 ) ;
F_4 ( & V_3 -> V_10 , V_12 ) ;
V_3 -> V_12 = NULL ;
F_11 ( & V_2 -> V_16 ) ;
V_12 = F_3 ( & V_3 -> V_9 ) ;
} else {
if ( V_13 >= V_14 )
F_10 ( L_12 ,
__FILE__ , __LINE__ , V_12 ) ;
V_3 -> V_12 = V_12 ;
break;
}
}
if ( ! V_12 )
F_15 ( V_33 , & V_2 -> V_8 ) ;
F_6 ( & V_3 -> V_9 . V_11 , V_8 ) ;
V_3 -> V_30 = 0 ;
F_7 ( & V_3 -> V_9 . V_11 , V_8 ) ;
if ( V_3 -> V_31 )
goto V_29;
if ( V_13 >= V_14 )
F_10 ( L_13 , __FILE__ , __LINE__ ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_13 >= V_14 )
F_10 ( L_14 , __FILE__ , __LINE__ ) ;
if ( ! V_3 )
return;
if ( V_2 != V_3 -> V_2 ) {
F_15 ( V_33 , & V_2 -> V_8 ) ;
return;
}
F_20 ( V_3 , V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 , const T_1 * V_37 ,
char * V_8 , int V_32 )
{
register struct V_3 * V_3 = F_2 ( V_2 ) ;
register struct V_4 * V_5 ;
if ( V_13 >= V_14 )
F_10 ( L_15 ,
__FILE__ , __LINE__ , V_32 ) ;
if ( ! V_3 || V_2 != V_3 -> V_2 )
return;
if ( V_3 -> V_18 != V_19 ) {
F_10 ( L_16 ,
__FILE__ , __LINE__ ) ;
return;
}
if ( V_32 > V_38 ) {
if ( V_13 >= V_14 )
F_10 ( L_17 ,
__FILE__ , __LINE__ ) ;
return;
}
V_5 = F_3 ( & V_3 -> V_7 ) ;
if ( ! V_5 ) {
if ( V_3 -> V_6 . V_32 < V_39 )
V_5 = F_23 ( V_40 , V_41 ) ;
}
if ( ! V_5 ) {
if ( V_13 >= V_14 )
F_10 ( L_18 ,
__FILE__ , __LINE__ ) ;
return;
}
memcpy ( V_5 -> V_5 , V_37 , V_32 ) ;
V_5 -> V_32 = V_32 ;
F_4 ( & V_3 -> V_6 , V_5 ) ;
F_11 ( & V_2 -> V_15 ) ;
if ( V_3 -> V_2 -> V_42 != NULL )
F_24 ( & V_3 -> V_2 -> V_42 , V_43 , V_44 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , struct V_45 * V_45 ,
T_1 T_3 * V_5 , T_4 V_46 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_47 = 0 ;
struct V_4 * V_48 ;
F_26 ( V_49 , V_50 ) ;
if ( V_13 >= V_14 )
F_10 ( L_19 , __FILE__ , __LINE__ ) ;
if ( ! V_3 )
return - V_51 ;
if ( ! F_27 ( V_52 , V_5 , V_46 ) ) {
F_10 ( V_20 L_20
L_21 , __FILE__ , __LINE__ ) ;
return - V_53 ;
}
F_28 ( & V_2 -> V_15 , & V_49 ) ;
for (; ; ) {
if ( F_29 ( V_54 , & V_2 -> V_8 ) ) {
V_47 = - V_51 ;
break;
}
if ( F_30 ( V_45 ) )
break;
F_31 ( V_55 ) ;
V_48 = F_3 ( & V_3 -> V_6 ) ;
if ( V_48 ) {
if ( V_48 -> V_32 > V_46 ) {
V_47 = - V_56 ;
} else {
if ( F_32 ( V_5 , V_48 -> V_5 , V_48 -> V_32 ) )
V_47 = - V_53 ;
else
V_47 = V_48 -> V_32 ;
}
if ( V_3 -> V_7 . V_32 >
V_57 )
F_12 ( V_48 ) ;
else
F_4 ( & V_3 -> V_7 , V_48 ) ;
break;
}
if ( V_45 -> V_58 & V_59 ) {
V_47 = - V_60 ;
break;
}
F_33 () ;
if ( F_34 ( V_50 ) ) {
V_47 = - V_61 ;
break;
}
}
F_35 ( & V_2 -> V_15 , & V_49 ) ;
F_36 ( V_62 ) ;
return V_47 ;
}
static T_2 F_37 ( struct V_1 * V_2 , struct V_45 * V_45 ,
const unsigned char * V_37 , T_4 V_32 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int error = 0 ;
F_26 ( V_49 , V_50 ) ;
struct V_4 * V_12 ;
if ( V_13 >= V_14 )
F_10 ( L_22 ,
__FILE__ , __LINE__ , V_32 ) ;
if ( ! V_3 )
return - V_51 ;
if ( V_3 -> V_18 != V_19 )
return - V_51 ;
if ( V_32 > V_38 ) {
if ( V_13 & V_14 )
F_10 ( V_20
L_23
L_24 , ( unsigned long ) V_32 ,
V_38 ) ;
V_32 = V_38 ;
}
F_28 ( & V_2 -> V_16 , & V_49 ) ;
for (; ; ) {
F_31 ( V_55 ) ;
V_12 = F_3 ( & V_3 -> V_10 ) ;
if ( V_12 )
break;
if ( V_45 -> V_58 & V_59 ) {
error = - V_60 ;
break;
}
F_33 () ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 || V_3 -> V_18 != V_19 ||
V_2 != V_3 -> V_2 ) {
F_10 ( L_25 , V_3 ) ;
error = - V_51 ;
break;
}
if ( F_34 ( V_50 ) ) {
error = - V_61 ;
break;
}
}
F_36 ( V_62 ) ;
F_35 ( & V_2 -> V_16 , & V_49 ) ;
if ( ! error ) {
memcpy ( V_12 -> V_5 , V_37 , V_32 ) ;
V_12 -> V_32 = error = V_32 ;
F_4 ( & V_3 -> V_9 , V_12 ) ;
F_20 ( V_3 , V_2 ) ;
}
return error ;
}
static int F_38 ( struct V_1 * V_2 , struct V_45 * V_45 ,
unsigned int V_63 , unsigned long V_64 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int error = 0 ;
int V_32 ;
unsigned long V_8 ;
if ( V_13 >= V_14 )
F_10 ( L_26 ,
__FILE__ , __LINE__ , V_63 ) ;
if ( ! V_3 || V_3 -> V_18 != V_19 )
return - V_65 ;
switch ( V_63 ) {
case V_66 :
F_6 ( & V_3 -> V_6 . V_11 , V_8 ) ;
if ( V_3 -> V_6 . V_67 )
V_32 = V_3 -> V_6 . V_67 -> V_32 ;
else
V_32 = 0 ;
F_7 ( & V_3 -> V_6 . V_11 , V_8 ) ;
error = F_39 ( V_32 , ( int T_3 * ) V_64 ) ;
break;
case V_68 :
V_32 = F_40 ( V_2 ) ;
F_6 ( & V_3 -> V_9 . V_11 , V_8 ) ;
if ( V_3 -> V_9 . V_67 )
V_32 += V_3 -> V_9 . V_67 -> V_32 ;
F_7 ( & V_3 -> V_9 . V_11 , V_8 ) ;
error = F_39 ( V_32 , ( int T_3 * ) V_64 ) ;
break;
case V_69 :
switch ( V_64 ) {
case V_70 :
case V_71 :
F_5 ( V_2 ) ;
}
default:
error = F_41 ( V_2 , V_45 , V_63 , V_64 ) ;
break;
}
return error ;
}
static unsigned int F_42 ( struct V_1 * V_2 , struct V_45 * V_72 ,
T_5 * V_49 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_73 = 0 ;
if ( V_13 >= V_14 )
F_10 ( L_27 , __FILE__ , __LINE__ ) ;
if ( V_3 && V_3 -> V_18 == V_19 && V_2 == V_3 -> V_2 ) {
F_43 ( V_72 , & V_2 -> V_15 , V_49 ) ;
F_43 ( V_72 , & V_2 -> V_16 , V_49 ) ;
if ( V_3 -> V_6 . V_67 )
V_73 |= V_74 | V_75 ;
if ( F_29 ( V_54 , & V_2 -> V_8 ) )
V_73 |= V_76 ;
if ( F_30 ( V_72 ) )
V_73 |= V_76 ;
if ( ! F_44 ( V_2 ) &&
V_3 -> V_10 . V_67 )
V_73 |= V_77 | V_78 ;
}
return V_73 ;
}
static struct V_3 * F_17 ( void )
{
struct V_4 * V_5 ;
int V_79 ;
struct V_3 * V_3 = F_23 ( sizeof( * V_3 ) , V_80 ) ;
if ( ! V_3 )
return NULL ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_45 ( & V_3 -> V_7 ) ;
F_45 ( & V_3 -> V_10 ) ;
F_45 ( & V_3 -> V_6 ) ;
F_45 ( & V_3 -> V_9 ) ;
for( V_79 = 0 ; V_79 < V_57 ; V_79 ++ ) {
V_5 = F_23 ( V_40 , V_80 ) ;
if ( V_5 )
F_4 ( & V_3 -> V_7 , V_5 ) ;
else if ( V_13 >= V_14 )
F_10 ( L_28 , __FILE__ , __LINE__ , V_79 ) ;
}
for( V_79 = 0 ; V_79 < V_81 ; V_79 ++ ) {
V_5 = F_23 ( V_40 , V_80 ) ;
if ( V_5 )
F_4 ( & V_3 -> V_10 , V_5 ) ;
else if ( V_13 >= V_14 )
F_10 ( L_29 , __FILE__ , __LINE__ , V_79 ) ;
}
V_3 -> V_18 = V_19 ;
V_3 -> V_8 = 0 ;
return V_3 ;
}
static void F_45 ( struct V_82 * V_83 )
{
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
F_46 ( & V_83 -> V_11 ) ;
}
static void F_4 ( struct V_82 * V_83 ,
struct V_4 * V_5 )
{
unsigned long V_8 ;
F_6 ( & V_83 -> V_11 , V_8 ) ;
V_5 -> V_84 = NULL ;
if ( V_83 -> V_85 )
V_83 -> V_85 -> V_84 = V_5 ;
else
V_83 -> V_67 = V_5 ;
V_83 -> V_85 = V_5 ;
( V_83 -> V_32 ) ++ ;
F_7 ( & V_83 -> V_11 , V_8 ) ;
}
static struct V_4 * F_3 ( struct V_82 * V_83 )
{
unsigned long V_8 ;
struct V_4 * V_5 ;
F_6 ( & V_83 -> V_11 , V_8 ) ;
V_5 = V_83 -> V_67 ;
if ( V_5 ) {
V_83 -> V_67 = V_5 -> V_84 ;
( V_83 -> V_32 ) -- ;
}
if ( ! V_83 -> V_67 )
V_83 -> V_85 = NULL ;
F_7 ( & V_83 -> V_11 , V_8 ) ;
return V_5 ;
}
static int T_6 F_47 ( void )
{
int V_86 ;
if ( V_38 < 4096 )
V_38 = 4096 ;
else if ( V_38 > 65535 )
V_38 = 65535 ;
F_10 ( V_87 , V_38 ) ;
V_86 = F_48 ( V_88 , & V_89 ) ;
if ( ! V_86 )
F_10 ( V_90 ) ;
else
F_10 ( V_91 , V_86 ) ;
if ( V_86 )
F_10 ( V_92 , V_86 ) ;
return V_86 ;
}
static void T_7 F_49 ( void )
{
int V_86 = F_50 ( V_88 ) ;
if ( V_86 )
F_10 ( V_93 , V_86 ) ;
else
F_10 ( V_94 ) ;
}
