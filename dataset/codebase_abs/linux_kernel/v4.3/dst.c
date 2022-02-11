static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
unsigned long V_5 = ~ 0L ;
struct V_6 * V_7 , * V_8 , V_9 ;
struct V_6 * V_10 = & V_9 ;
F_2 ( & V_11 ) ;
V_8 = V_12 ;
V_13:
while ( ( V_7 = V_8 ) != NULL ) {
V_8 = V_7 -> V_8 ;
F_3 ( & V_8 -> V_8 ) ;
F_4 () ;
if ( F_5 ( F_6 ( & V_7 -> V_14 ) ) ) {
V_10 -> V_8 = V_7 ;
V_10 = V_7 ;
V_3 ++ ;
continue;
}
V_4 ++ ;
V_7 = F_7 ( V_7 ) ;
if ( V_7 ) {
if ( V_7 -> V_15 > 0 )
continue;
F_8 ( V_7 ) ;
V_7 -> V_8 = V_8 ;
V_8 = V_7 ;
}
}
F_9 ( & V_16 . V_17 ) ;
V_8 = V_16 . V_18 ;
if ( V_8 ) {
V_16 . V_18 = NULL ;
F_10 ( & V_16 . V_17 ) ;
goto V_13;
}
V_10 -> V_8 = NULL ;
V_12 = V_9 . V_8 ;
if ( ! V_12 )
V_16 . V_19 = V_20 ;
else {
if ( V_4 <= V_3 / 10 ) {
V_16 . V_21 += V_16 . V_19 ;
if ( V_16 . V_21 > V_20 )
V_16 . V_21 = V_20 ;
V_16 . V_19 += V_22 ;
} else {
V_16 . V_19 = V_22 ;
V_16 . V_21 = V_23 ;
}
V_5 = V_16 . V_21 ;
if ( V_5 > 4 * V_24 )
V_5 = F_11 ( V_5 ) ;
F_12 ( & V_25 , V_5 ) ;
}
F_10 ( & V_16 . V_17 ) ;
F_13 ( & V_11 ) ;
}
int F_14 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
F_15 ( V_29 ) ;
return 0 ;
}
void F_16 ( struct V_6 * V_7 , struct V_30 * V_31 ,
struct V_32 * V_33 , int V_34 , int V_35 ,
unsigned short V_36 )
{
V_7 -> V_37 = NULL ;
V_7 -> V_33 = V_33 ;
if ( V_33 )
F_17 ( V_33 ) ;
V_7 -> V_31 = V_31 ;
F_18 ( V_7 , V_38 , true ) ;
V_7 -> V_5 = 0UL ;
V_7 -> V_39 = V_7 ;
V_7 -> V_40 = NULL ;
#ifdef F_19
V_7 -> V_41 = NULL ;
#endif
V_7 -> V_42 = V_43 ;
V_7 -> V_44 = F_14 ;
V_7 -> error = 0 ;
V_7 -> V_15 = V_35 ;
V_7 -> V_45 = 0 ;
V_7 -> V_46 = 0 ;
#ifdef F_20
V_7 -> V_47 = 0 ;
#endif
V_7 -> V_48 = NULL ;
F_21 ( & V_7 -> V_14 , V_34 ) ;
V_7 -> V_49 = 0 ;
V_7 -> V_50 = V_51 ;
V_7 -> V_36 = V_36 ;
V_7 -> V_52 = 0 ;
V_7 -> V_8 = NULL ;
if ( ! ( V_36 & V_53 ) )
F_22 ( V_31 , 1 ) ;
}
void * F_23 ( struct V_30 * V_31 , struct V_32 * V_33 ,
int V_34 , int V_35 , unsigned short V_36 )
{
struct V_6 * V_7 ;
if ( V_31 -> V_54 && F_24 ( V_31 ) > V_31 -> V_55 ) {
if ( V_31 -> V_54 ( V_31 ) )
return NULL ;
}
V_7 = F_25 ( V_31 -> V_56 , V_57 ) ;
if ( ! V_7 )
return NULL ;
F_16 ( V_7 , V_31 , V_33 , V_34 , V_35 , V_36 ) ;
return V_7 ;
}
static void F_8 ( struct V_6 * V_7 )
{
if ( V_7 -> V_33 == NULL || ! ( V_7 -> V_33 -> V_36 & V_58 ) ) {
V_7 -> V_42 = V_43 ;
V_7 -> V_44 = F_14 ;
}
V_7 -> V_15 = V_59 ;
}
void F_26 ( struct V_6 * V_7 )
{
F_9 ( & V_16 . V_17 ) ;
F_8 ( V_7 ) ;
V_7 -> V_8 = V_16 . V_18 ;
V_16 . V_18 = V_7 ;
if ( V_16 . V_19 > V_22 ) {
V_16 . V_19 = V_22 ;
V_16 . V_21 = V_23 ;
F_27 ( V_60 , & V_25 ,
V_16 . V_21 ) ;
}
F_10 ( & V_16 . V_17 ) ;
}
struct V_6 * F_7 ( struct V_6 * V_7 )
{
struct V_6 * V_37 ;
F_28 () ;
V_61:
V_37 = V_7 -> V_37 ;
if ( ! ( V_7 -> V_36 & V_53 ) )
F_22 ( V_7 -> V_31 , - 1 ) ;
if ( V_7 -> V_31 -> V_62 )
V_7 -> V_31 -> V_62 ( V_7 ) ;
if ( V_7 -> V_33 )
F_29 ( V_7 -> V_33 ) ;
F_30 ( V_7 -> V_48 ) ;
if ( V_7 -> V_36 & V_63 )
F_31 ( V_7 ) ;
else
F_32 ( V_7 -> V_31 -> V_56 , V_7 ) ;
V_7 = V_37 ;
if ( V_7 ) {
int V_64 = V_7 -> V_36 & V_65 ;
if ( F_33 ( & V_7 -> V_14 ) ) {
if ( V_64 )
goto V_61;
} else {
if ( V_64 )
return V_7 ;
}
}
return NULL ;
}
static void F_34 ( struct V_66 * V_9 )
{
struct V_6 * V_7 = F_35 ( V_9 , struct V_6 , V_66 ) ;
V_7 = F_7 ( V_7 ) ;
if ( V_7 )
F_26 ( V_7 ) ;
}
void F_36 ( struct V_6 * V_7 )
{
if ( V_7 ) {
int V_67 ;
V_67 = F_37 ( & V_7 -> V_14 ) ;
if ( F_38 ( V_67 < 0 ) )
F_39 ( L_1 ,
V_68 , V_7 , V_67 ) ;
if ( F_38 ( V_7 -> V_36 & V_69 ) && ! V_67 )
F_40 ( & V_7 -> V_66 , F_34 ) ;
}
}
T_1 * F_41 ( struct V_6 * V_7 , unsigned long V_70 )
{
T_1 * V_71 = F_42 ( sizeof( T_1 ) * V_72 , V_57 ) ;
if ( V_71 ) {
T_1 * V_73 = F_43 ( V_70 ) ;
unsigned long V_74 , V_75 ;
memcpy ( V_71 , V_73 , sizeof( T_1 ) * V_72 ) ;
V_75 = ( unsigned long ) V_71 ;
V_74 = F_44 ( & V_7 -> V_76 , V_70 , V_75 ) ;
if ( V_74 != V_70 ) {
F_31 ( V_71 ) ;
V_71 = F_43 ( V_74 ) ;
if ( V_74 & V_77 )
V_71 = NULL ;
}
}
return V_71 ;
}
void F_45 ( struct V_6 * V_7 , unsigned long V_70 )
{
unsigned long V_74 , V_75 ;
V_75 = ( ( unsigned long ) V_38 ) | V_77 ;
V_74 = F_44 ( & V_7 -> V_76 , V_70 , V_75 ) ;
if ( V_74 == V_70 )
F_31 ( F_43 ( V_70 ) ) ;
}
static int F_46 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
F_47 ( 1 , L_2 ) ;
F_15 ( V_29 ) ;
return 0 ;
}
static int F_48 ( struct V_28 * V_29 )
{
F_47 ( 1 , L_3 ) ;
F_15 ( V_29 ) ;
return 0 ;
}
static void F_49 ( struct V_78 * V_79 , T_2 V_80 )
{
struct V_6 * V_7 ;
V_7 = & V_79 -> V_7 ;
F_16 ( V_7 , & V_81 , NULL , 1 , V_82 ,
V_63 | V_69 | V_53 ) ;
V_7 -> V_42 = F_48 ;
V_7 -> V_44 = F_46 ;
memset ( V_7 + 1 , 0 , sizeof( * V_79 ) + V_80 - sizeof( * V_7 ) ) ;
}
struct V_78 * F_50 ( T_2 V_80 , T_3 V_36 )
{
struct V_78 * V_79 ;
V_79 = F_42 ( sizeof( * V_79 ) + V_80 , V_36 ) ;
if ( ! V_79 )
return NULL ;
F_49 ( V_79 , V_80 ) ;
return V_79 ;
}
struct V_78 T_4 * F_51 ( T_2 V_80 , T_3 V_36 )
{
int V_83 ;
struct V_78 T_4 * V_79 ;
V_79 = F_52 ( sizeof( struct V_78 ) + V_80 ,
F_53 ( struct V_78 ) , V_36 ) ;
if ( ! V_79 )
return NULL ;
F_54 (cpu)
F_49 ( F_55 ( V_79 , V_83 ) , V_80 ) ;
return V_79 ;
}
static void F_56 ( struct V_6 * V_7 , struct V_32 * V_33 ,
int V_84 )
{
if ( V_7 -> V_31 -> V_85 )
V_7 -> V_31 -> V_85 ( V_7 , V_33 , V_84 ) ;
if ( V_33 != V_7 -> V_33 )
return;
if ( ! V_84 ) {
V_7 -> V_42 = V_43 ;
V_7 -> V_44 = F_14 ;
} else {
V_7 -> V_33 = F_57 ( V_7 -> V_33 ) -> V_86 ;
F_17 ( V_7 -> V_33 ) ;
F_29 ( V_33 ) ;
}
}
static int F_58 ( struct V_87 * V_88 , unsigned long V_89 ,
void * V_90 )
{
struct V_32 * V_33 = F_59 ( V_90 ) ;
struct V_6 * V_7 , * V_10 = NULL ;
switch ( V_89 ) {
case V_91 :
case V_92 :
F_2 ( & V_11 ) ;
for ( V_7 = V_12 ; V_7 ; V_7 = V_7 -> V_8 ) {
V_10 = V_7 ;
F_56 ( V_7 , V_33 , V_89 != V_92 ) ;
}
F_9 ( & V_16 . V_17 ) ;
V_7 = V_16 . V_18 ;
V_16 . V_18 = NULL ;
F_10 ( & V_16 . V_17 ) ;
if ( V_10 )
V_10 -> V_8 = V_7 ;
else
V_12 = V_7 ;
for (; V_7 ; V_7 = V_7 -> V_8 )
F_56 ( V_7 , V_33 , V_89 != V_92 ) ;
F_13 ( & V_11 ) ;
break;
}
return V_93 ;
}
void T_5 F_60 ( void )
{
F_61 ( & V_94 ) ;
}
