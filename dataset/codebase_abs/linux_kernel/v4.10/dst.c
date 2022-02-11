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
int F_14 ( struct V_26 * V_26 , struct V_27 * V_28 , struct V_29 * V_30 )
{
F_15 ( V_30 ) ;
return 0 ;
}
void F_16 ( struct V_6 * V_7 , struct V_31 * V_32 ,
struct V_33 * V_34 , int V_35 , int V_36 ,
unsigned short V_37 )
{
V_7 -> V_38 = NULL ;
V_7 -> V_34 = V_34 ;
if ( V_34 )
F_17 ( V_34 ) ;
V_7 -> V_32 = V_32 ;
F_18 ( V_7 , V_39 , true ) ;
V_7 -> V_5 = 0UL ;
V_7 -> V_40 = V_7 ;
V_7 -> V_41 = NULL ;
#ifdef F_19
V_7 -> V_42 = NULL ;
#endif
V_7 -> V_43 = V_44 ;
V_7 -> V_45 = F_14 ;
V_7 -> error = 0 ;
V_7 -> V_15 = V_36 ;
V_7 -> V_46 = 0 ;
V_7 -> V_47 = 0 ;
#ifdef F_20
V_7 -> V_48 = 0 ;
#endif
V_7 -> V_49 = NULL ;
F_21 ( & V_7 -> V_14 , V_35 ) ;
V_7 -> V_50 = 0 ;
V_7 -> V_51 = V_52 ;
V_7 -> V_37 = V_37 ;
V_7 -> V_53 = 0 ;
V_7 -> V_8 = NULL ;
if ( ! ( V_37 & V_54 ) )
F_22 ( V_32 , 1 ) ;
}
void * F_23 ( struct V_31 * V_32 , struct V_33 * V_34 ,
int V_35 , int V_36 , unsigned short V_37 )
{
struct V_6 * V_7 ;
if ( V_32 -> V_55 && F_24 ( V_32 ) > V_32 -> V_56 ) {
if ( V_32 -> V_55 ( V_32 ) )
return NULL ;
}
V_7 = F_25 ( V_32 -> V_57 , V_58 ) ;
if ( ! V_7 )
return NULL ;
F_16 ( V_7 , V_32 , V_34 , V_35 , V_36 , V_37 ) ;
return V_7 ;
}
static void F_8 ( struct V_6 * V_7 )
{
if ( V_7 -> V_34 == NULL || ! ( V_7 -> V_34 -> V_37 & V_59 ) ) {
V_7 -> V_43 = V_44 ;
V_7 -> V_45 = F_14 ;
}
V_7 -> V_15 = V_60 ;
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
F_27 ( V_61 , & V_25 ,
V_16 . V_21 ) ;
}
F_10 ( & V_16 . V_17 ) ;
}
struct V_6 * F_7 ( struct V_6 * V_7 )
{
struct V_6 * V_38 ;
F_28 () ;
V_62:
V_38 = V_7 -> V_38 ;
if ( ! ( V_7 -> V_37 & V_54 ) )
F_22 ( V_7 -> V_32 , - 1 ) ;
if ( V_7 -> V_32 -> V_63 )
V_7 -> V_32 -> V_63 ( V_7 ) ;
if ( V_7 -> V_34 )
F_29 ( V_7 -> V_34 ) ;
F_30 ( V_7 -> V_49 ) ;
if ( V_7 -> V_37 & V_64 )
F_31 ( (struct V_65 * ) V_7 ) ;
else
F_32 ( V_7 -> V_32 -> V_57 , V_7 ) ;
V_7 = V_38 ;
if ( V_7 ) {
int V_66 = V_7 -> V_37 & V_67 ;
if ( F_33 ( & V_7 -> V_14 ) ) {
if ( V_66 )
goto V_62;
} else {
if ( V_66 )
return V_7 ;
}
}
return NULL ;
}
static void F_34 ( struct V_68 * V_9 )
{
struct V_6 * V_7 = F_35 ( V_9 , struct V_6 , V_68 ) ;
V_7 = F_7 ( V_7 ) ;
if ( V_7 )
F_26 ( V_7 ) ;
}
void F_36 ( struct V_6 * V_7 )
{
if ( V_7 ) {
int V_69 ;
unsigned short V_70 = V_7 -> V_37 & V_71 ;
V_69 = F_37 ( & V_7 -> V_14 ) ;
if ( F_38 ( V_69 < 0 ) )
F_39 ( L_1 ,
V_72 , V_7 , V_69 ) ;
if ( ! V_69 && F_38 ( V_70 ) )
F_40 ( & V_7 -> V_68 , F_34 ) ;
}
}
T_1 * F_41 ( struct V_6 * V_7 , unsigned long V_73 )
{
T_1 * V_74 = F_42 ( sizeof( T_1 ) * V_75 , V_58 ) ;
if ( V_74 ) {
T_1 * V_76 = F_43 ( V_73 ) ;
unsigned long V_77 , V_78 ;
memcpy ( V_74 , V_76 , sizeof( T_1 ) * V_75 ) ;
V_78 = ( unsigned long ) V_74 ;
V_77 = F_44 ( & V_7 -> V_79 , V_73 , V_78 ) ;
if ( V_77 != V_73 ) {
F_45 ( V_74 ) ;
V_74 = F_43 ( V_77 ) ;
if ( V_77 & V_80 )
V_74 = NULL ;
}
}
return V_74 ;
}
void F_46 ( struct V_6 * V_7 , unsigned long V_73 )
{
unsigned long V_77 , V_78 ;
V_78 = ( ( unsigned long ) V_39 ) | V_80 ;
V_77 = F_44 ( & V_7 -> V_79 , V_73 , V_78 ) ;
if ( V_77 == V_73 )
F_45 ( F_43 ( V_73 ) ) ;
}
static int F_47 ( struct V_26 * V_26 , struct V_27 * V_28 , struct V_29 * V_30 )
{
F_48 ( 1 , L_2 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static int F_49 ( struct V_29 * V_30 )
{
F_48 ( 1 , L_3 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static void F_50 ( struct V_65 * V_81 , T_2 V_82 )
{
struct V_6 * V_7 ;
V_7 = & V_81 -> V_7 ;
F_16 ( V_7 , & V_83 , NULL , 1 , V_84 ,
V_64 | V_71 | V_54 ) ;
V_7 -> V_43 = F_49 ;
V_7 -> V_45 = F_47 ;
memset ( V_7 + 1 , 0 , sizeof( * V_81 ) + V_82 - sizeof( * V_7 ) ) ;
}
struct V_65 * F_51 ( T_2 V_82 , T_3 V_37 )
{
struct V_65 * V_81 ;
V_81 = F_42 ( sizeof( * V_81 ) + V_82 , V_37 ) ;
if ( ! V_81 )
return NULL ;
F_50 ( V_81 , V_82 ) ;
return V_81 ;
}
void F_31 ( struct V_65 * V_81 )
{
#ifdef F_52
F_53 ( & V_81 -> V_85 . V_86 . V_87 ) ;
#endif
F_45 ( V_81 ) ;
}
struct V_65 T_4 * F_54 ( T_2 V_82 , T_3 V_37 )
{
int V_88 ;
struct V_65 T_4 * V_81 ;
V_81 = F_55 ( sizeof( struct V_65 ) + V_82 ,
F_56 ( struct V_65 ) , V_37 ) ;
if ( ! V_81 )
return NULL ;
F_57 (cpu)
F_50 ( F_58 ( V_81 , V_88 ) , V_82 ) ;
return V_81 ;
}
static void F_59 ( struct V_6 * V_7 , struct V_33 * V_34 ,
int V_89 )
{
if ( V_7 -> V_32 -> V_90 )
V_7 -> V_32 -> V_90 ( V_7 , V_34 , V_89 ) ;
if ( V_34 != V_7 -> V_34 )
return;
if ( ! V_89 ) {
V_7 -> V_43 = V_44 ;
V_7 -> V_45 = F_14 ;
} else {
V_7 -> V_34 = F_60 ( V_7 -> V_34 ) -> V_91 ;
F_17 ( V_7 -> V_34 ) ;
F_29 ( V_34 ) ;
}
}
static int F_61 ( struct V_92 * V_93 , unsigned long V_94 ,
void * V_95 )
{
struct V_33 * V_34 = F_62 ( V_95 ) ;
struct V_6 * V_7 , * V_10 = NULL ;
switch ( V_94 ) {
case V_96 :
case V_97 :
F_2 ( & V_11 ) ;
for ( V_7 = V_12 ; V_7 ; V_7 = V_7 -> V_8 ) {
V_10 = V_7 ;
F_59 ( V_7 , V_34 , V_94 != V_97 ) ;
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
F_59 ( V_7 , V_34 , V_94 != V_97 ) ;
F_13 ( & V_11 ) ;
break;
}
return V_98 ;
}
void T_5 F_63 ( void )
{
F_64 ( & V_99 ) ;
}
