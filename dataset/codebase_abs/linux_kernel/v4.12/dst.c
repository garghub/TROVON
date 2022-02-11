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
F_18 ( V_7 , V_39 . V_40 , true ) ;
V_7 -> V_5 = 0UL ;
V_7 -> V_41 = V_7 ;
V_7 -> V_42 = NULL ;
#ifdef F_19
V_7 -> V_43 = NULL ;
#endif
V_7 -> V_44 = V_45 ;
V_7 -> V_46 = F_14 ;
V_7 -> error = 0 ;
V_7 -> V_15 = V_36 ;
V_7 -> V_47 = 0 ;
V_7 -> V_48 = 0 ;
#ifdef F_20
V_7 -> V_49 = 0 ;
#endif
V_7 -> V_50 = NULL ;
F_21 ( & V_7 -> V_14 , V_35 ) ;
V_7 -> V_51 = 0 ;
V_7 -> V_52 = V_53 ;
V_7 -> V_37 = V_37 ;
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
V_7 -> V_44 = V_45 ;
V_7 -> V_46 = F_14 ;
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
F_30 ( V_7 -> V_50 ) ;
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
struct V_74 * V_75 = F_42 ( sizeof( * V_75 ) , V_58 ) ;
if ( V_75 ) {
struct V_74 * V_76 = (struct V_74 * ) F_43 ( V_73 ) ;
unsigned long V_77 , V_78 ;
F_21 ( & V_75 -> V_79 , 1 ) ;
memcpy ( V_75 -> V_40 , V_76 -> V_40 , sizeof( V_75 -> V_40 ) ) ;
V_78 = ( unsigned long ) V_75 ;
V_77 = F_44 ( & V_7 -> V_80 , V_73 , V_78 ) ;
if ( V_77 != V_73 ) {
F_45 ( V_75 ) ;
V_75 = (struct V_74 * ) F_43 ( V_77 ) ;
if ( V_77 & V_81 )
V_75 = NULL ;
} else if ( V_77 & V_82 ) {
if ( F_33 ( & V_76 -> V_79 ) )
F_45 ( V_76 ) ;
}
}
F_46 ( F_47 ( struct V_74 , V_40 ) != 0 ) ;
return ( T_1 * ) V_75 ;
}
void F_48 ( struct V_6 * V_7 , unsigned long V_73 )
{
unsigned long V_77 , V_78 ;
V_78 = ( ( unsigned long ) & V_39 ) | V_81 ;
V_77 = F_44 ( & V_7 -> V_80 , V_73 , V_78 ) ;
if ( V_77 == V_73 )
F_45 ( F_43 ( V_73 ) ) ;
}
static int F_49 ( struct V_26 * V_26 , struct V_27 * V_28 , struct V_29 * V_30 )
{
F_50 ( 1 , L_2 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static int F_51 ( struct V_29 * V_30 )
{
F_50 ( 1 , L_3 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static void F_52 ( struct V_65 * V_83 , T_2 V_84 )
{
struct V_6 * V_7 ;
V_7 = & V_83 -> V_7 ;
F_16 ( V_7 , & V_85 , NULL , 1 , V_86 ,
V_64 | V_71 | V_54 ) ;
V_7 -> V_44 = F_51 ;
V_7 -> V_46 = F_49 ;
memset ( V_7 + 1 , 0 , sizeof( * V_83 ) + V_84 - sizeof( * V_7 ) ) ;
}
struct V_65 * F_53 ( T_2 V_84 , T_3 V_37 )
{
struct V_65 * V_83 ;
V_83 = F_42 ( sizeof( * V_83 ) + V_84 , V_37 ) ;
if ( ! V_83 )
return NULL ;
F_52 ( V_83 , V_84 ) ;
return V_83 ;
}
void F_31 ( struct V_65 * V_83 )
{
#ifdef F_54
F_55 ( & V_83 -> V_87 . V_88 . V_89 ) ;
#endif
F_45 ( V_83 ) ;
}
struct V_65 T_4 * F_56 ( T_2 V_84 , T_3 V_37 )
{
int V_90 ;
struct V_65 T_4 * V_83 ;
V_83 = F_57 ( sizeof( struct V_65 ) + V_84 ,
F_58 ( struct V_65 ) , V_37 ) ;
if ( ! V_83 )
return NULL ;
F_59 (cpu)
F_52 ( F_60 ( V_83 , V_90 ) , V_84 ) ;
return V_83 ;
}
static void F_61 ( struct V_6 * V_7 , struct V_33 * V_34 ,
int V_91 )
{
if ( V_7 -> V_32 -> V_92 )
V_7 -> V_32 -> V_92 ( V_7 , V_34 , V_91 ) ;
if ( V_34 != V_7 -> V_34 )
return;
if ( ! V_91 ) {
V_7 -> V_44 = V_45 ;
V_7 -> V_46 = F_14 ;
} else {
V_7 -> V_34 = F_62 ( V_7 -> V_34 ) -> V_93 ;
F_17 ( V_7 -> V_34 ) ;
F_29 ( V_34 ) ;
}
}
static int F_63 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
struct V_33 * V_34 = F_64 ( V_97 ) ;
struct V_6 * V_7 , * V_10 = NULL ;
switch ( V_96 ) {
case V_98 :
case V_99 :
F_2 ( & V_11 ) ;
for ( V_7 = V_12 ; V_7 ; V_7 = V_7 -> V_8 ) {
V_10 = V_7 ;
F_61 ( V_7 , V_34 , V_96 != V_99 ) ;
}
F_9 ( & V_16 . V_17 ) ;
V_7 = V_16 . V_18 ;
V_16 . V_18 = NULL ;
if ( V_16 . V_19 > V_22 ) {
V_16 . V_19 = V_22 ;
V_16 . V_21 = V_23 ;
F_27 ( V_61 , & V_25 ,
V_16 . V_21 ) ;
}
F_10 ( & V_16 . V_17 ) ;
if ( V_10 )
V_10 -> V_8 = V_7 ;
else
V_12 = V_7 ;
for (; V_7 ; V_7 = V_7 -> V_8 )
F_61 ( V_7 , V_34 , V_96 != V_99 ) ;
F_13 ( & V_11 ) ;
break;
}
return V_100 ;
}
void T_5 F_65 ( void )
{
F_66 ( & V_101 ) ;
}
