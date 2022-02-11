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
while ( ( V_5 = F_3 ( & V_3 -> V_8 ) ) )
F_4 ( & V_3 -> V_9 , V_5 ) ;
}
static void F_6 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_7 ( V_3 ) ;
struct V_4 * V_5 ;
if ( V_10 >= V_11 )
F_8 ( L_1 , __FILE__ , __LINE__ ) ;
F_9 ( & V_2 -> V_12 ) ;
F_9 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 == V_3 )
V_2 -> V_14 = NULL ;
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_7 ) ;
if ( V_5 ) {
F_10 ( V_5 ) ;
} else
break;
}
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_9 ) ;
if ( V_5 ) {
F_10 ( V_5 ) ;
} else
break;
}
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_6 ) ;
if ( V_5 ) {
F_10 ( V_5 ) ;
} else
break;
}
for(; ; ) {
V_5 = F_3 ( & V_3 -> V_8 ) ;
if ( V_5 ) {
F_10 ( V_5 ) ;
} else
break;
}
F_10 ( V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_10 >= V_11 )
F_8 ( L_2 , __FILE__ , __LINE__ ) ;
if ( V_3 != NULL ) {
if ( V_3 -> V_15 != V_16 ) {
F_8 ( V_17 L_3 ) ;
return;
}
#if F_12 ( V_18 )
F_13 ( V_18 , & V_2 -> V_19 ) ;
#endif
V_2 -> V_14 = NULL ;
if ( V_2 == V_3 -> V_20 )
V_3 -> V_20 = NULL ;
if ( V_2 != V_3 -> V_2 )
return;
if ( V_3 -> V_20 ) {
V_3 -> V_2 = V_3 -> V_20 ;
} else {
F_6 ( V_3 ) ;
}
}
if ( V_10 >= V_11 )
F_8 ( L_4 , __FILE__ , __LINE__ ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_10 >= V_11 )
F_8 ( L_5 ,
__FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
if ( V_3 ) {
F_8 ( V_22 L_6 ) ;
return - V_23 ;
}
V_3 = F_15 () ;
if ( ! V_3 ) {
F_8 ( V_22 L_7 ) ;
return - V_24 ;
}
V_2 -> V_14 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_25 = 65536 ;
#if F_12 ( V_18 )
F_16 ( V_18 , & V_2 -> V_19 ) ;
#endif
F_17 ( V_2 ) ;
if ( V_10 >= V_11 )
F_8 ( L_8 , __FILE__ , __LINE__ ) ;
return 0 ;
}
static void F_18 ( struct V_3 * V_3 , struct V_1 * V_2 )
{
register int V_26 ;
unsigned long V_19 ;
struct V_4 * V_27 ;
if ( V_10 >= V_11 )
F_8 ( L_9 , __FILE__ , __LINE__ ) ;
V_28:
F_19 ( & V_3 -> V_8 . V_29 , V_19 ) ;
if ( V_3 -> V_30 ) {
V_3 -> V_31 = 1 ;
F_20 ( & V_3 -> V_8 . V_29 , V_19 ) ;
return;
}
V_3 -> V_30 = 1 ;
V_3 -> V_31 = 0 ;
F_20 ( & V_3 -> V_8 . V_29 , V_19 ) ;
V_27 = F_3 ( & V_3 -> V_8 ) ;
while ( V_27 ) {
if ( V_10 >= V_11 )
F_8 ( L_10 ,
__FILE__ , __LINE__ , V_27 , V_27 -> V_32 ) ;
F_16 ( V_33 , & V_2 -> V_19 ) ;
V_26 = V_2 -> V_34 -> V_35 ( V_2 , V_27 -> V_5 , V_27 -> V_32 ) ;
if ( V_26 == - V_36 ) {
F_21 ( & V_3 -> V_8 , V_27 ) ;
break;
}
if ( V_26 < 0 )
V_26 = V_27 -> V_32 ;
if ( V_26 == V_27 -> V_32 ) {
if ( V_10 >= V_11 )
F_8 ( L_11 ,
__FILE__ , __LINE__ , V_27 ) ;
F_4 ( & V_3 -> V_9 , V_27 ) ;
F_9 ( & V_2 -> V_13 ) ;
V_27 = F_3 ( & V_3 -> V_8 ) ;
} else {
if ( V_10 >= V_11 )
F_8 ( L_12 ,
__FILE__ , __LINE__ , V_27 ) ;
F_21 ( & V_3 -> V_8 , V_27 ) ;
break;
}
}
if ( ! V_27 )
F_13 ( V_33 , & V_2 -> V_19 ) ;
F_19 ( & V_3 -> V_8 . V_29 , V_19 ) ;
V_3 -> V_30 = 0 ;
F_20 ( & V_3 -> V_8 . V_29 , V_19 ) ;
if ( V_3 -> V_31 )
goto V_28;
if ( V_10 >= V_11 )
F_8 ( L_13 , __FILE__ , __LINE__ ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_10 >= V_11 )
F_8 ( L_14 , __FILE__ , __LINE__ ) ;
if ( ! V_3 )
return;
if ( V_2 != V_3 -> V_2 ) {
F_13 ( V_33 , & V_2 -> V_19 ) ;
return;
}
F_18 ( V_3 , V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 , const T_1 * V_37 ,
char * V_19 , int V_32 )
{
register struct V_3 * V_3 = F_2 ( V_2 ) ;
register struct V_4 * V_5 ;
if ( V_10 >= V_11 )
F_8 ( L_15 ,
__FILE__ , __LINE__ , V_32 ) ;
if ( ! V_3 || V_2 != V_3 -> V_2 )
return;
if ( V_3 -> V_15 != V_16 ) {
F_8 ( L_16 ,
__FILE__ , __LINE__ ) ;
return;
}
if ( V_32 > V_38 ) {
if ( V_10 >= V_11 )
F_8 ( L_17 ,
__FILE__ , __LINE__ ) ;
return;
}
V_5 = F_3 ( & V_3 -> V_7 ) ;
if ( ! V_5 ) {
if ( V_3 -> V_6 . V_32 < V_39 )
V_5 = F_24 ( V_40 , V_41 ) ;
}
if ( ! V_5 ) {
if ( V_10 >= V_11 )
F_8 ( L_18 ,
__FILE__ , __LINE__ ) ;
return;
}
memcpy ( V_5 -> V_5 , V_37 , V_32 ) ;
V_5 -> V_32 = V_32 ;
F_4 ( & V_3 -> V_6 , V_5 ) ;
F_9 ( & V_2 -> V_12 ) ;
if ( V_3 -> V_2 -> V_42 != NULL )
F_25 ( & V_3 -> V_2 -> V_42 , V_43 , V_44 ) ;
}
static T_2 F_26 ( struct V_1 * V_2 , struct V_45 * V_45 ,
T_1 T_3 * V_5 , T_4 V_46 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_47 = 0 ;
struct V_4 * V_48 ;
F_27 ( V_49 , V_50 ) ;
if ( V_10 >= V_11 )
F_8 ( L_19 , __FILE__ , __LINE__ ) ;
if ( ! V_3 )
return - V_51 ;
if ( ! F_28 ( V_52 , V_5 , V_46 ) ) {
F_8 ( V_17 L_20
L_21 , __FILE__ , __LINE__ ) ;
return - V_53 ;
}
F_29 ( & V_2 -> V_12 , & V_49 ) ;
for (; ; ) {
if ( F_30 ( V_54 , & V_2 -> V_19 ) ) {
V_47 = - V_51 ;
break;
}
if ( F_31 ( V_45 ) )
break;
F_32 ( V_55 ) ;
V_48 = F_3 ( & V_3 -> V_6 ) ;
if ( V_48 ) {
if ( V_48 -> V_32 > V_46 ) {
V_47 = - V_56 ;
} else {
if ( F_33 ( V_5 , V_48 -> V_5 , V_48 -> V_32 ) )
V_47 = - V_53 ;
else
V_47 = V_48 -> V_32 ;
}
if ( V_3 -> V_7 . V_32 >
V_57 )
F_10 ( V_48 ) ;
else
F_4 ( & V_3 -> V_7 , V_48 ) ;
break;
}
if ( V_45 -> V_58 & V_59 ) {
V_47 = - V_60 ;
break;
}
F_34 () ;
if ( F_35 ( V_50 ) ) {
V_47 = - V_61 ;
break;
}
}
F_36 ( & V_2 -> V_12 , & V_49 ) ;
F_37 ( V_62 ) ;
return V_47 ;
}
static T_2 F_38 ( struct V_1 * V_2 , struct V_45 * V_45 ,
const unsigned char * V_37 , T_4 V_32 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int error = 0 ;
F_27 ( V_49 , V_50 ) ;
struct V_4 * V_27 ;
if ( V_10 >= V_11 )
F_8 ( L_22 ,
__FILE__ , __LINE__ , V_32 ) ;
if ( ! V_3 )
return - V_51 ;
if ( V_3 -> V_15 != V_16 )
return - V_51 ;
if ( V_32 > V_38 ) {
if ( V_10 & V_11 )
F_8 ( V_17
L_23
L_24 , ( unsigned long ) V_32 ,
V_38 ) ;
V_32 = V_38 ;
}
F_29 ( & V_2 -> V_13 , & V_49 ) ;
for (; ; ) {
F_32 ( V_55 ) ;
V_27 = F_3 ( & V_3 -> V_9 ) ;
if ( V_27 )
break;
if ( V_45 -> V_58 & V_59 ) {
error = - V_60 ;
break;
}
F_34 () ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 || V_3 -> V_15 != V_16 ||
V_2 != V_3 -> V_2 ) {
F_8 ( L_25 , V_3 ) ;
error = - V_51 ;
break;
}
if ( F_35 ( V_50 ) ) {
error = - V_61 ;
break;
}
}
F_37 ( V_62 ) ;
F_36 ( & V_2 -> V_13 , & V_49 ) ;
if ( ! error ) {
memcpy ( V_27 -> V_5 , V_37 , V_32 ) ;
V_27 -> V_32 = error = V_32 ;
F_4 ( & V_3 -> V_8 , V_27 ) ;
F_18 ( V_3 , V_2 ) ;
}
return error ;
}
static int F_39 ( struct V_1 * V_2 , struct V_45 * V_45 ,
unsigned int V_63 , unsigned long V_64 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int error = 0 ;
int V_32 ;
unsigned long V_19 ;
struct V_4 * V_5 = NULL ;
if ( V_10 >= V_11 )
F_8 ( L_26 ,
__FILE__ , __LINE__ , V_63 ) ;
if ( ! V_3 || V_3 -> V_15 != V_16 )
return - V_65 ;
switch ( V_63 ) {
case V_66 :
F_19 ( & V_3 -> V_6 . V_29 , V_19 ) ;
V_5 = F_40 ( & V_3 -> V_6 . V_67 ,
struct V_4 , V_68 ) ;
if ( V_5 )
V_32 = V_5 -> V_32 ;
else
V_32 = 0 ;
F_20 ( & V_3 -> V_6 . V_29 , V_19 ) ;
error = F_41 ( V_32 , ( int T_3 * ) V_64 ) ;
break;
case V_69 :
V_32 = F_42 ( V_2 ) ;
F_19 ( & V_3 -> V_8 . V_29 , V_19 ) ;
V_5 = F_40 ( & V_3 -> V_8 . V_67 ,
struct V_4 , V_68 ) ;
if ( V_5 )
V_32 += V_5 -> V_32 ;
F_20 ( & V_3 -> V_8 . V_29 , V_19 ) ;
error = F_41 ( V_32 , ( int T_3 * ) V_64 ) ;
break;
case V_70 :
switch ( V_64 ) {
case V_71 :
case V_72 :
F_5 ( V_2 ) ;
}
default:
error = F_43 ( V_2 , V_45 , V_63 , V_64 ) ;
break;
}
return error ;
}
static unsigned int F_44 ( struct V_1 * V_2 , struct V_45 * V_73 ,
T_5 * V_49 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_74 = 0 ;
if ( V_10 >= V_11 )
F_8 ( L_27 , __FILE__ , __LINE__ ) ;
if ( V_3 && V_3 -> V_15 == V_16 && V_2 == V_3 -> V_2 ) {
F_45 ( V_73 , & V_2 -> V_12 , V_49 ) ;
F_45 ( V_73 , & V_2 -> V_13 , V_49 ) ;
if ( ! F_46 ( & V_3 -> V_6 . V_67 ) )
V_74 |= V_75 | V_76 ;
if ( F_30 ( V_54 , & V_2 -> V_19 ) )
V_74 |= V_77 ;
if ( F_31 ( V_73 ) )
V_74 |= V_77 ;
if ( ! F_47 ( V_2 ) &&
! F_46 ( & V_3 -> V_9 . V_67 ) )
V_74 |= V_78 | V_79 ;
}
return V_74 ;
}
static struct V_3 * F_15 ( void )
{
struct V_4 * V_5 ;
int V_80 ;
struct V_3 * V_3 = F_48 ( sizeof( * V_3 ) , V_81 ) ;
if ( ! V_3 )
return NULL ;
F_49 ( & V_3 -> V_7 . V_29 ) ;
F_49 ( & V_3 -> V_9 . V_29 ) ;
F_49 ( & V_3 -> V_6 . V_29 ) ;
F_49 ( & V_3 -> V_8 . V_29 ) ;
F_50 ( & V_3 -> V_7 . V_67 ) ;
F_50 ( & V_3 -> V_9 . V_67 ) ;
F_50 ( & V_3 -> V_6 . V_67 ) ;
F_50 ( & V_3 -> V_8 . V_67 ) ;
for( V_80 = 0 ; V_80 < V_57 ; V_80 ++ ) {
V_5 = F_24 ( V_40 , V_81 ) ;
if ( V_5 )
F_4 ( & V_3 -> V_7 , V_5 ) ;
else if ( V_10 >= V_11 )
F_8 ( L_28 , __FILE__ , __LINE__ , V_80 ) ;
}
for( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
V_5 = F_24 ( V_40 , V_81 ) ;
if ( V_5 )
F_4 ( & V_3 -> V_9 , V_5 ) ;
else if ( V_10 >= V_11 )
F_8 ( L_29 , __FILE__ , __LINE__ , V_80 ) ;
}
V_3 -> V_15 = V_16 ;
V_3 -> V_19 = 0 ;
return V_3 ;
}
static void F_21 ( struct V_83 * V_84 ,
struct V_4 * V_5 )
{
unsigned long V_19 ;
F_19 ( & V_84 -> V_29 , V_19 ) ;
F_51 ( & V_5 -> V_68 , & V_84 -> V_67 ) ;
V_84 -> V_32 ++ ;
F_20 ( & V_84 -> V_29 , V_19 ) ;
}
static void F_4 ( struct V_83 * V_84 ,
struct V_4 * V_5 )
{
unsigned long V_19 ;
F_19 ( & V_84 -> V_29 , V_19 ) ;
F_52 ( & V_5 -> V_68 , & V_84 -> V_67 ) ;
V_84 -> V_32 ++ ;
F_20 ( & V_84 -> V_29 , V_19 ) ;
}
static struct V_4 * F_3 ( struct V_83 * V_84 )
{
unsigned long V_19 ;
struct V_4 * V_5 ;
F_19 ( & V_84 -> V_29 , V_19 ) ;
V_5 = F_40 ( & V_84 -> V_67 ,
struct V_4 , V_68 ) ;
if ( V_5 ) {
F_53 ( & V_5 -> V_68 ) ;
V_84 -> V_32 -- ;
}
F_20 ( & V_84 -> V_29 , V_19 ) ;
return V_5 ;
}
static int T_6 F_54 ( void )
{
int V_85 ;
if ( V_38 < 4096 )
V_38 = 4096 ;
else if ( V_38 > 65535 )
V_38 = 65535 ;
F_8 ( V_86 , V_38 ) ;
V_85 = F_55 ( V_87 , & V_88 ) ;
if ( ! V_85 )
F_8 ( V_89 ) ;
else
F_8 ( V_90 , V_85 ) ;
return V_85 ;
}
static void T_7 F_56 ( void )
{
int V_85 = F_57 ( V_87 ) ;
if ( V_85 )
F_8 ( V_91 , V_85 ) ;
else
F_8 ( V_92 ) ;
}
